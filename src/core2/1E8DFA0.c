// Particle emitter manager and particle simulation: emitter list with new/free/update/draw/defrag,
// per-particle aging, fading, animation, physics, floor bounce with sound, and particle spawning.
#include "common.h"
#include "memory.h"
#include "core2/1EC8070.h"
#include "core2/1ECB9F0.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"

extern int func_800BEF00(s32, f32 *, f32 *, u32);
// Particle, 0x3C bytes. Size, lifetime and frame use 8.8 fixed point.
typedef struct {
    s16 accel[3];        // 0x00
    s16 pos[3];          // 0x06
    f32 fade;            // 0x0C
    f32 rot[3];          // 0x10
    f32 age;             // 0x1C, seconds
    s16 ang_vel[3];      // 0x20
    s16 vel[3];          // 0x26
    s16 frame;           // 0x2C, animation frame
    s16 frame_rate;      // 0x2E
    s16 size;            // 0x30, current scale
    s16 size_start;      // 0x32
    s16 size_delta;      // 0x34, final size minus initial size
    s16 lifetime;        // 0x36
    u8 bounces;          // 0x38, remaining bounces
    u8 visible_latch : 1; // 0x39, consumed and reset by the update
    u8 unk_39 : 7;
    u8 pad_3A[2];
} Struct800B4790Particle;
typedef struct Struct800B4790Emitter {
    u16 flags;           // 0x2000 velocity damping, 0x4000 rotation damping
    u8 pad_2[5];
    u8 spawn_mode;       // 0 continuous, 1 finite batch, 2 stopped
    u8 unk_8[2];
    u8 asset_type;       // 7 selects sprite animation
    u8 frame_count;      // sprite frames
    u8 pad_C[0xC];
    f32 fade_in_end;     // normalized
    f32 fade_out_start;  // normalized
    f32 spawn_timer;     // time until next spawn
    f32 duration;        // remaining emission time, if positive
    u8 pad_28[0x2A];
    u8 anim_mode;        // 0 unchanged, 1 loop, 2 hold final frame
    u8 unk_53;
    f32 interval_min;    // spawn interval
    f32 interval_max;
    u8 pad_5C[0x2C];
    s32 water_source;    // optional water-height source
    Struct800B4790Particle *live_start; // live range start
    Struct800B4790Particle *live_end;   // live range end (exclusive)
    Struct800B4790Particle *spawn_limit; // shrinks in batch mode
    s16 water_offset;    // offset from water height
    u8 pad_9A[0x10];
    s16 bounce_sound;    // sound id, zero disables it
    u8 pad_AC[4];
    f32 restitution;     // bounce attenuation
    f32 pitch_min;       // bounce sound pitch range
    f32 pitch_max;
    s32 volume;          // bounce sound base volume
    void (*last_bounce_cb)(struct Struct800B4790Emitter *, f32 *);
    u8 pad_C4[0xC];
    f32 damping;         // per-update damping multiplier
} Struct800B4790Emitter;
extern s32 _idwater_entrypoint_1(s32);
extern void func_800C3FC0(s32, f32, s32);
extern f32 D_80127F14;
extern u8 D_80127F1C;
extern s16 D_80127F18;
extern s32 *D_80127F10;
extern u8 D_80127F1D;
extern s16 D_80127F1A;
void func_800B5450();

// Emitter list lifecycle, per-frame update, draw passes, particle physics and floor bounce.
// Collision test for a particle moving from probe to pos: raycasts the map, or clamps
// pos[1] to the emitter's optional height limits. Returns nonzero on a hit.
int func_800B46B0(s16 *emitter, f32 *particle, f32 *probe, f32 *pos)
{
    f32 hit_pos[3];

    // Matching: reassigning this parameter is needed for the match.
    particle = pos;

    if (emitter[0x56] == -0x8000 && emitter[0x57] == 0x7FFF) {
        return func_800BEF00(probe, particle, hit_pos,
                             (*(u16 *) emitter & 0x100) ? 0x420021 : 0x400000);
    }

    if (emitter[0x57] != 0x7FFF && emitter[0x57] < particle[1]) {
        particle[1] = emitter[0x57];
        return 1;
    }

    if (emitter[0x56] != -0x8000 && particle[1] < emitter[0x56]) {
        particle[1] = emitter[0x56];
        return 1;
    }

    return 0;
}

// Updates one emitter's particles (age, fade, size, animation, motion, floor bounce)
// and spawns new particles.
void func_800B4790(Struct800B4790Emitter *emitter)
{
    Struct800B4790Particle *particle;
    f32 dt = func_800D8FF8();
    f32 t;
    s32 i;
    f32 pos[3];
    f32 probe[3];
    s32 hit;
    if (D_80127F1C != 0) {
        for (particle = emitter->live_start; particle < emitter->live_end;) {
            particle->age += dt;
            if (((f32) particle->lifetime * 0.00390625f) <= particle->age) {
                rare_memcpy(particle, --emitter->live_end, sizeof(Struct800B4790Particle));
                if (emitter->spawn_mode == 1) {
                    emitter->spawn_limit--;
                }
            } else {
                f32 intensity;
                t = particle->age / ((f32) particle->lifetime * 0.00390625f);
                if (t < emitter->fade_in_end) {
                    particle->fade = t / emitter->fade_in_end;
                } else if (t <= emitter->fade_out_start) {
                    particle->fade = 1.0f;
                } else {
                    particle->fade =
                        1.0f - ((t - emitter->fade_out_start) / (1.0f - emitter->fade_out_start));
                }
                particle->size =
                    particle->size_start +
                    (s32) (((t * (f32) particle->size_delta) * 0.00390625f) * 256.0f);
                if (emitter->asset_type == 7) {
                    switch (emitter->anim_mode) {
                        case 0:
                            break;
                        case 1:
                            particle->frame += (s32) ((f32) particle->frame_rate * dt);
                            if ((particle->frame >> 8) >= emitter->frame_count) {
                                particle->frame = 0;
                            }
                            break;

                        case 2:
                            particle->frame += (s32) ((f32) particle->frame_rate * dt);
                            if ((particle->frame >> 8) >= emitter->frame_count) {
                                particle->frame = (emitter->frame_count << 8) - 0x100;
                            }
                    }
                }
                // Add in floating point before narrowing back to the packed s16.
                // Casting the delta first would change both rounding and codegen.
                for (i = 0; i < 3; i++) {
                    particle->pos[i] += (f32) particle->vel[i] * dt;
                    particle->rot[i] += (f32) particle->ang_vel[i] * dt;
                    particle->vel[i] += (f32) particle->accel[i] * dt;
                }

                if (emitter->flags & 0x2000) {
                    for (i = 0; i < 3; i++) {
                        particle->vel[i] =
                            (s32) ((f32) particle->vel[i] * emitter->damping);
                    }
                }
                if (emitter->flags & 0x4000) {
                    for (i = 0; i < 3; i++) {
                        particle->rot[i] *= emitter->damping;
                    }
                }
                if (emitter->water_source != 0) {
                    particle->pos[1] =
                        _idwater_entrypoint_1(emitter->water_source) + emitter->water_offset;
                }
                func_800EE88C(pos, particle->pos);
                if ((emitter->flags & 0x1000) && (particle->visible_latch == 0)) {
                    rare_memcpy(particle, --emitter->live_end, sizeof(Struct800B4790Particle));
                    if (emitter->spawn_mode == 1) {
                        emitter->spawn_limit--;
                    }
                } else {
                    particle->visible_latch = 0;
                    if (particle->bounces > 0) {
                        func_800EFA4C(probe, (f32) particle->pos[0],
                                      (f32) particle->pos[1] + 50.0f, (f32) particle->pos[2]);
                        hit = func_800B46B0(emitter, particle, probe, pos);
                        func_800EE940(particle->pos, pos);
                        if (hit != 0) {
                            if (emitter->bounce_sound != 0) {
                                intensity = mlAbsF((f32) particle->vel[1]) * 0.1f;
                                if (intensity > 1) {
                                    intensity = 1;
                                }
                                // Shared cooldown suppresses simultaneous bounce sounds.
                                if (D_80127F14 == 0.0f) {
                                    func_800C3FC0(
                                        emitter->bounce_sound,
                                        func_800DC178(emitter->pitch_min, emitter->pitch_max),
                                        (s32) ((f32) emitter->volume * intensity));
                                    D_80127F14 = 0.25f;
                                }
                            }
                            particle->pos[1] += 2;
                            pos[1] += 2.0f;
                            particle->vel[1] =
                                (s32) (mlAbsF((f32) particle->vel[1]) * emitter->restitution);
                            if (emitter->flags & 0x80) {
                                particle->vel[0] =
                                    (s32) ((f32) particle->vel[0] * emitter->restitution);
                                particle->vel[2] =
                                    (s32) ((f32) particle->vel[2] * emitter->restitution);
                            }
                            if (!(emitter->flags & 2)) {
                                particle->size_start =
                                    (s32) ((f32) particle->size_start * emitter->restitution);
                                particle->size_delta =
                                    (s32) ((f32) particle->size_delta * emitter->restitution);
                            }
                            particle->ang_vel[0] =
                                (s32) ((f32) particle->ang_vel[0] * emitter->restitution);
                            particle->ang_vel[1] =
                                (s32) ((f32) particle->ang_vel[1] * emitter->restitution);
                            particle->ang_vel[2] =
                                (s32) ((f32) particle->ang_vel[2] * emitter->restitution);
                            if (!(particle->bounces = particle->bounces - 1)) {
                                if (emitter->last_bounce_cb != 0) {
                                    emitter->last_bounce_cb(emitter, pos);
                                }
                                rare_memcpy(particle, --emitter->live_end,
                                            sizeof(Struct800B4790Particle));
                                if (emitter->spawn_mode == 1) {
                                    emitter->spawn_limit--;
                                }
                                continue;
                            }
                        }
                    }
                    particle++;
                }
            }
        }

        if (emitter->duration > 0.0f) {
            emitter->duration -= dt;
            if (emitter->duration <= 0.0f) {
                emitter->spawn_mode = 2;
            }
        }
        switch (emitter->spawn_mode) {
            case 0:
                emitter->spawn_timer -= dt;
                if (emitter->spawn_timer <= 0.0f) {
                    emitter->spawn_timer = func_800DC178(emitter->interval_min, emitter->interval_max);
                    {
                        if (emitter->live_end < emitter->spawn_limit) {
                            func_800B9B50(emitter, emitter->live_end++);
                        }
                    }
                }
                break;

            case 1:
                emitter->spawn_timer -= dt;
                if (emitter->spawn_timer <= 0.0f) {
                    emitter->spawn_timer = func_800DC178(emitter->interval_min, emitter->interval_max);
                    {
                        if ((emitter->spawn_limit - emitter->live_end) > 0) {
                            func_800B9B50(emitter, emitter->live_end++);
                            return;
                        }
                        emitter->spawn_mode = 2;
                    }
                }
        }
    }
}

// TU-NOTE: D_80127F10 is the heap array of emitter pointers, D_80127F18 its count.
// Creates the (empty) emitter array.
s32 func_800B5028(void)
{
    D_80127F10 = heap_alloc(0);
    D_80127F18 = 0;
}

// Frees all emitters and the array.
// Matching: the line breaks in this function are needed for the match.
void func_800B5054(void)
{
    s32 i;
    s32 offset;
    i = 0;
    if (D_80127F18 > 0)
    {
        offset = 0; do { func_800BA2C4(*(s32 *) ((char *) D_80127F10 + offset));
            i += 1;
            offset += 4;
        }
        while (i < D_80127F18);
    }
    heap_free((void *) D_80127F10);
    D_80127F10 = 0;
    D_80127F18 = 0;
    D_80127F1D = 0;
}

// Per-frame update of all emitters; removes the ones that finished.
void func_800B50F0(void)
{
    s32 offset;
    s32 i;
    u8 *emitter;
    u8 *finished;
    if (D_80127F14 < func_800D8FF8()) {
        D_80127F14 = 0.0f;
    } else {
        D_80127F14 -= func_800D8FF8();
    }
    if (D_80127F10 != 0) {
        i = 0;
        offset = 0;
        if (D_80127F18 > 0) {
            do {
                emitter = *(u8 **) ((u8 *) D_80127F10 + offset);
                func_800B4790(emitter);
                if (((*(u8 *) ((char *) emitter + 9) != 0) &&
                     (*(u8 *) ((char *) emitter + 7) == 2)) &&
                    (*(s32 *) ((char *) emitter + 0x8C) == *(s32 *) ((char *) emitter + 0x90))) {
                    *(s8 *) ((char *) emitter + 8) = 1;
                } else {
                    *(s8 *) ((char *) emitter + 8) = 0;
                }
                i += 1;
                offset += 4;
            } while (i < D_80127F18);
        }
        // Matching: this dead load is needed for the match.
        emitter = *(u8 **) ((u8 *) D_80127F10 + offset);
        offset = 0;
        if (D_80127F18 > 0) {
            do {
                finished = *(u8 **) ((u8 *) D_80127F10 + offset);
                if (*(u8 *) ((char *) finished + 8) != 0) {
                    func_800B5450(finished);
                } else {
                    offset += 4;
                }
            } while (offset < (D_80127F18 * 4));
        }
    }
}

void func_800B525C(s32 unk_0)
{
    s32 i;
    s32 emitter;
    s32 unk_1;
    s32 unk_2;
    i = 0;
    while (i < D_80127F18) {
        emitter = ((s32 *) D_80127F10)[i];
        // Matching: `| 0` is needed for the match.
        unk_1 = unk_0 | 0;
        unk_2 = 4;
        func_800BC358(emitter, unk_1, unk_2);
        i++;
    }
}

void func_800B52EC(s32 unk_0)
{
    s32 i;
    s32 emitter;
    s32 unk_1;
    i = 0;
    while (i < D_80127F18) {
        emitter = ((s32 *) D_80127F10)[i];
        // Matching: `| 0` is needed for the match.
        unk_1 = unk_0 | 0;
        func_800BC358(emitter, unk_1, 0);
        i++;
    }
}

void func_800B537C(s32 unk_0)
{
    func_800B525C(unk_0);
    func_800B52EC(unk_0);
}

// Adds a new emitter to the array and returns it.
s32 func_800B53A4(s32 unk_0)
{
    s32 *old_array;

    old_array = (s32 *) D_80127F10;
    D_80127F18 += 1;
    D_80127F10 = heap_realloc(old_array, D_80127F18 * 4);

    ((s32 *) D_80127F10)[D_80127F18 - 1] = func_800BA2E8(unk_0);
    *((u8 *) (s32 *) D_80127F10[D_80127F18 - 1] + 9) = 1;

    return ((s32 *) D_80127F10)[D_80127F18 - 1];
}

// Frees the emitter and removes it from the array.
void func_800B5450(emitter) int emitter;
{
    s32 i;

    i = 0;
    while (((s32 *) D_80127F10)[i] != emitter && i < D_80127F18) {
        i++;
    }

    if (i == D_80127F18) {
        return;
    }

    func_800BA2C4(emitter);
    ((s32 *) D_80127F10)[i] = ((s32 *) D_80127F10)[D_80127F18 - 1];
    D_80127F18--;
    D_80127F10 = heap_realloc((s32 *) D_80127F10, D_80127F18 * 4);
}

// Clears the emitter's flag at +9.
// Matching: the temporary pointer is needed for the match.
void func_800B5534(int *emitter)
{
    unsigned char *flag;
    flag = emitter;
    flag = flag + 9;
    *flag = 0;
}

// Sets the emitter's flag at +9.
// Matching: the temporaries and the bare block are needed for the match.
void func_800B553C(int *emitter)
{
    unsigned char *flag_end;
    unsigned char *flag;
    int *base;
    {
        base = emitter;
        base = base + 2;
    }
    flag = base;
    flag_end = (unsigned char *) (flag + 2);
    flag = flag_end;
    flag--;
    *flag = 1;
}

// Defrag of emitters and of the emitter array.
// Defrag: moves the emitter and fixes up its pointers at +0x8C/+0x90/+0x94.
u8 *func_800B5548(u8 *emitter)
{
    s32 i;
    s32 old_addr;
    // Matching: the repeated assignment to this variable is needed for the match.
    unsigned long new_addr;

    if (emitter) {
        old_addr = (s32) emitter;
        i = 0;

        while ((((void **) D_80127F10)[i] != emitter) && (i < D_80127F18)) {
            i++;
        }

        emitter = (u8 *) defrag(emitter);

        *(u8 **) (emitter + 0x8C) =
            (u8 *) (((s32) *(u8 **) (emitter + 0x8C) - old_addr) + (new_addr = (s32) emitter));

        *(u8 **) (emitter + 0x90) =
            (u8 *) (((s32) *(u8 **) (emitter + 0x90) - old_addr) + (new_addr = (s32) emitter));

        *(u8 **) (emitter + 0x94) =
            (u8 *) (((s32) *(u8 **) (emitter + 0x94) - old_addr) + (new_addr = (s32) emitter));

        if (i < D_80127F18) {
            ((void **) D_80127F10)[i] = emitter;
        }
    }

    return emitter;
}

void func_800B562C(void)
{
    D_80127F10 = defrag((void *) D_80127F10);
}

s32 func_800B5654(s32 unk_0, s32 unk_1)
{
    if (unk_1 == 0x02) {
        D_80127F1C = TRUE;
    } else {
        D_80127F1C = FALSE;
    }
}

s32 func_800B5680(enum map_e map_id)
{
    D_80127F1D = TRUE;
    D_80127F1A = map_id;
}

s32 func_800B5698(s16 *map_id)
{
    if (D_80127F1D) {
        *map_id = D_80127F1A;
        return TRUE;
    }
    return FALSE;
}
