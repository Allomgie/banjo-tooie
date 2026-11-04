// Rain weather: drops spawn around the player in view and fall until below the player; also the
// looping rain sound with fade, on/off/stopping states, and a lightning/thunder flash timer.
#include "common.h"

typedef struct {
    u8 pad_0[0x18];
    u8 state;
    u8 pad_19[3];
} RainElement1517;
typedef struct {
    u8 pad_0[0x20];
    void *drops;
} RainState1517;
extern void *func_800D674C(s32);
extern void *vector_begin(void *);
extern void *vector_end(void *);
extern void func_800DF830(s32);
extern void func_800DE448(void *, s32, f32, s32, void *);
extern s32 func_800DF350(void);
extern void func_800C3A40(u8, f32, f32, f32);
typedef struct {
    f32 pos[3];
    f32 velocity[3];
} RainDrop;
typedef struct {
    u8 pad_0[0x10];
    f32 delta[3];
    u8 pad_1C[4];
    void *drops;
    s32 max_count;
} RainSystem;
extern s32 vector_size(void *);
extern void *vector_push_back(void **);
extern void func_800E3980(f32 *);
extern void func_800E3958(f32 *);
extern void func_800E3A58(f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800E3F8C(f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x28];
    s32 mode;
    u8 pad_2C[4];
    u8 phase;
    u8 pad_31[3];
    f32 phase_time;
    u8 pad_38[0xC];
    f32 down_time;
} RainState61;
extern void *heap_alloc(int);
extern void *vector_new(int, int);
extern void func_800EFD24(void *);
// Rain object (0x4C bytes): 'mode' 1 = on, 2 = stopping; 'phase' 0 = no cycle, 1-4 = cycle phase.
typedef struct {
    int unk_0;
    int unk_4;
    int unk_8;
    int unk_C;
    int delta;
    int unk_14;
    int unk_18;
    int unk_1C;
    int drops;
    int max_count;
    int mode;
    float spawn_timer;
    int phase;
} FxRain;
extern f32 func_800D8FF8(void);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800C37E0(u8, f32, f32, f32);
extern void func_800C316C();
extern f32 func_800EEB40();
extern s32 func_800F1574(f32 *, f32);
extern u8 *vector_at(s32, s32);

// Spawns a drop around the player in view, falling at 1500-1600 u/s.
void func_80800000_fxrain(RainSystem *rain)
{
    f32 cam_pos[3];
    f32 cam_dir[3];
    f32 cam_rot[3];
    f32 dist;
    s32 i;
    RainDrop *drop;
    f32 pos[3];

    if (vector_size(rain->drops) >= rain->max_count) {
        return;
    }
    func_800E3980(cam_pos);
    func_800E3958(cam_dir);
    func_800E3A58(cam_rot);
    drop = vector_push_back(&rain->drops);
    dist = func_800DC178(50.0f, 2000.0f);
    func_800EFA4C(pos, 0.0f, func_800DC178(200.0f, 300.0f), -dist);
    if (func_800EEFD4(rain->delta) < 25.0f) {
        func_800EF934(pos, pos, func_800DC178(0.0f, 360.0f));
    } else {
        func_800EF934(pos, pos, cam_rot[1] + func_800DC178(-70.0f, 70.0f));
    }
    func_800EF04C(pos, cam_pos);
    if (dist < 1000.0f) {
        for (i = 0; i < 10 && func_800E3F8C(pos[0], pos[1] - 10.0f, pos[2]); i++) {
            pos[1] += 100.0f;
        }
    }
    func_800EE7F8(drop->pos, pos);
    func_800EFA4C(drop->velocity, 0.0f, func_800DC178(-1600.0f, -1500.0f), 0.0f);
}

void func_808001E8_fxrain(s32 rain, s32 mode)
{
    s32 *mode_ptr;
    mode_ptr = (s32 *) (rain + 0x28);
    *mode_ptr = mode;
}

int fxrain_entrypoint_0(Actor *rain)
{
    vector_clear(*(s32 *) ((char *) rain + 0x20));
}

void fxrain_entrypoint_1(void *rain)
{
    RainElement1517 *begin;
    RainElement1517 *end;
    void *model;

    model = func_800D674C(0x9EC);
    begin = vector_begin(((RainState1517 *) rain)->drops);
    end = vector_end(((RainState1517 *) rain)->drops);
    for (rain = begin; (RainElement1517 *) rain < end;
         rain = (u8 *) rain + 0x1C) {
        func_800DF830(2);
        func_800DE448(rain, 0, 1.0f, 0, model);
        ((RainElement1517 *) rain)->state = func_800DF350();
    }
}

// Returns 1 once the rain is off and all drops are gone.
int fxrain_entrypoint_2(u8 *rain)
{
    return *(s32 *) (rain + 0x28) != 1 && vector_size(*(s32 *) (rain + 0x20)) == 0;
}

// Returns whether it is currently raining.
int fxrain_entrypoint_3(RainState61 *rain)
{
    if (rain->mode != 1) {
        return 0;
    }
    switch (rain->phase) {
        case 1:
        case 2:
            return 1;
        case 3:
            return rain->phase_time < rain->down_time * 0.9f;
    }
    return 0;
}

void fxrain_entrypoint_4(u8 *rain)
{
    u8 sound;
    int handle;
    // Matching: the repeated masks are needed for the match.
    handle = (((((*rain & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu;
    if ((sound = handle) != 0) {
        func_800C2FDC(sound & 0xFF, rain, sound);
        *rain = 0;
    }
    vector_free(*(void **) ((char *) rain + 0x20));
    heap_free(rain);
}

int fxrain_entrypoint_5(s32 max_count)
{
    FxRain *rain;
    rain = heap_alloc(0x4C);
    func_800EFD24((u8 *) rain + 4);
    func_800EFD24(&rain->delta);
    *(u8 *) ((char *) rain + 0x0) = 0;
    *(u8 *) ((char *) rain + 0x1C) = 0;
    *(u8 *) ((char *) rain + 0x30) = 0;
    rain->drops = vector_new(0x1C, max_count);
    rain->max_count = max_count;
    rain->mode = 0;
    rain->spawn_timer = 0.1f;
    return rain;
}

// Starts the rain cycle: phases 1-4 (ramp up, full, ramp down, pause) last the given times.
void fxrain_entrypoint_6(void *rain, f32 up_time, f32 full_time, f32 down_time, f32 pause_time)
{
    u8 *phase = (u8 *) ((char *) rain + 0x30);
    *phase = 1;
    *(f32 *) ((char *) rain + 0x34) = 0.0f;
    *(f32 *) ((char *) rain + 0x38) = 0.1f;
    *(f32 *) ((char *) rain + 0x3C) = up_time;
    *(f32 *) ((char *) rain + 0x40) = full_time;
    *(f32 *) ((char *) rain + 0x44) = down_time;
    *(f32 *) ((char *) rain + 0x48) = pause_time;
}

void fxrain_entrypoint_7(s32 rain)
{
    func_808001E8_fxrain(rain, 1);
}

// Stops the rain and fades out its sound.
void fxrain_entrypoint_8(u8 *rain)
{
    func_808001E8_fxrain(rain, 2);
    if (*rain) {
        func_800C3A40(*rain, 0.0f, 0.0f, 3.0f);
        *rain = 0;
    }
}

// Per-frame update: rain sound, drop movement and removal, phase cycle, drop spawning.
void fxrain_entrypoint_9(u8 *rain)
{
    f32 cam_pos[3];
    f32 dt;
    s32 i;
    u8 *drop;
    s32 phase;
    f32 max_dist;

    dt = func_800D8FF8();
    func_800E3980(cam_pos);
    func_800EFB24((f32 *) (rain + 0x10), cam_pos, (f32 *) (rain + 4));
    func_800EE7F8((f32 *) (rain + 4), cam_pos);
    if (func_800A5490() != 0) {
        vector_clear(*(s32 *) (rain + 0x20));
    }
    if (vector_size(*(s32 *) (rain + 0x20)) > 0) {
        if (rain[0] == 0) {
            rain[0] = func_800C2E04();
            func_800C330C(rain[0], 3);
            func_800C301C(rain[0], 0x465);
            func_800C37E0(rain[0], 0.95f, 1.05f, 0.01f);
            func_800C3A40(rain[0], 3.0f, 12960000.0f, 0);
            func_800C3418(rain[0], 2);
            func_800C316C(rain[0], 0x1388, 0x1770, 0x40A00000);
            func_800C3BDC(rain[0]);
        }
    } else if (rain[0] != 0) {
        func_800C2FDC(rain[0]);
        rain[0] = 0;
    }
    i = 0;
    if (vector_size(*(s32 *) (rain + 0x20)) > 0) {
        do {
            drop = vector_at(*(s32 *) (rain + 0x20), i);
            *(f32 *) (drop + 0) = *(f32 *) (drop + 0xC) * dt + *(f32 *) (drop + 0);
            *(f32 *) (drop + 4) = *(f32 *) (drop + 0x10) * dt + *(f32 *) (drop + 4);
            *(f32 *) (drop + 8) = *(f32 *) (drop + 0x14) * dt + *(f32 *) (drop + 8);
            if (*(f32 *) (drop + 4) < cam_pos[1] - 500.0f && drop[0x18] == 0) {
                vector_erase(*(s32 *) (rain + 0x20), i);
                i--;
            }
            i++;
        } while (i < vector_size(*(s32 *) (rain + 0x20)));
    }
    // One drop per frame is checked against the 2200 distance limit.
    rain[0x1C] = rain[0x1C] + 1;
    if (rain[0x1C] < vector_size(*(s32 *) (rain + 0x20))) {
        max_dist = 2200.0f;
        if (max_dist * max_dist < func_800EEB40(vector_at(*(s32 *) (rain + 0x20), rain[0x1C]), cam_pos)) {
            vector_erase(*(s32 *) (rain + 0x20), rain[0x1C]);
        }
    } else {
        rain[0x1C] = 0;
    }
    phase = rain[0x30];
    if (rain[0x30] != 0) {
        *(f32 *) (rain + 0x34) = *(f32 *) (rain + 0x34) + dt;
        if (*(f32 *) (rain + phase * 4 + 0x38) <= *(f32 *) (rain + 0x34)) {
            *(f32 *) (rain + 0x34) = 0.0f;
            rain[0x30] = phase + 1;
            phase = rain[0x30];
            if (phase >= 5) {
                rain[0x30] = 1;
                phase = rain[0x30];
            }
        }
        if (phase == 1) {
            *(f32 *) (rain + 0x38) =
                (1.0f - *(f32 *) (rain + 0x34) / *(f32 *) (rain + 0x3C)) * 0.1f;
        } else if (phase == 2) {
            *(f32 *) (rain + 0x38) = 0.01f;
        } else if (phase == 3) {
            *(f32 *) (rain + 0x38) =
                *(f32 *) (rain + 0x34) / *(f32 *) (rain + 0x44) * 0.1f;
        } else {
            *(f32 *) (rain + 0x38) = 0.01f;
        }
        if (*(f32 *) (rain + 0x38) <= 0.01f) {
            *(f32 *) (rain + 0x38) = 0.01f;
        }
    }
    if (func_800F1574((f32 *) (rain + 0x2C), dt) != 0) {
        if (*(s32 *) (rain + 0x28) == 1 && func_800A5490() == 0 && rain[0x30] != 4) {
            func_80800000_fxrain(rain);
        }
        if (rain[0x30] != 0) {
            *(f32 *) (rain + 0x2C) = *(f32 *) (rain + 0x38);
        } else {
            *(f32 *) (rain + 0x2C) = 0.01f;
        }
    }
}
