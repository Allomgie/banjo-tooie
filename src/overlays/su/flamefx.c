#include "common.h"

extern void func_80100074(s32, s32, s32);
extern u8 *func_80100094(s32, s32);
// Component data layout: 0x20-byte header (settings), then particles of 0x30 bytes each.
typedef struct FlameFxSettings {
    f32 spread;
    f32 max_scale;
    f32 min_scale;
    s16 rise_min;
    s16 rise_max;
    u8 pad_10[0xA];
    u8 frame; // 0xFF: random frame in 0..max_frame
    u8 pad_1B[2];
    u8 max_frame;
} FlameFxSettings;
typedef struct FlameFxParticle {
    f32 origin[3];
    f32 offset[3];
    u8 pad_18[0xC];
    f32 rise_accel;
    f32 scale;
    u8 frame;
} FlameFxParticle;
extern f32 func_800DC178(f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern f32 func_800D8FF8(void);
typedef struct FlameEffectNode {
    u8 pad_0[0x18];
    f32 pos[3];
    u8 pad_24[4];
    f32 scale;
    u8 frame;
    u8 pad_2D[3];
} FlameEffectNode;
typedef struct FlameEffectDrawState {
    u8 pad_0[0x18];
    s16 sprite_id;
    u8 pad_1A;
    u8 count;
    u8 pad_1C[4];
    FlameEffectNode particles[1];
} FlameEffectDrawState;
extern s32 func_800E3E8C(f32 *, f32);
extern void *func_800D674C(s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2720(void *, s32, s32, f32 *, f32 *, s32);

void suflamefx_entrypoint_0(actor, unk_1, count, sprite_id) s32 actor;
s32 unk_1;
s32 count;
s16 sprite_id;
{
    u8 *fx;
    func_80100074(actor, unk_1, count * 0x30 + 0x20);
    fx = func_80100094(actor, unk_1);
    *(s16 *) (fx + 0x18) = sprite_id;
    fx[0x1B] = count;
}

void suflamefx_entrypoint_1(s32 actor, s32 unk_1)
{
    func_80100074(actor, unk_1, 0);
}

void func_80800428_suflamefx();

// Per-frame update: moves and shrinks particles, respawns dead ones, advances frames.
void suflamefx_entrypoint_2(u8 *fx, s32 pos)
{
    f32 dt;
    s32 i;
    s32 frame;
    u8 *particle;

    dt = func_800D8FF8();
    particle = fx + 0x20;
    for (i = 0; i < fx[0x1B]; i++, particle += 0x30) {

if (*(f32 *) (particle + 0x28) > 0.05f) {
    *(f32 *) (particle + 0x10) += *(f32 *) (particle + 0x24) * dt;
    *(f32 *) (particle + 0xC) *= *(f32 *) (fx + 0x10);
    *(f32 *) (particle + 0x14) *= *(f32 *) (fx + 0x10);
    *(f32 *) (particle + 0x28) += *(f32 *) (fx + 0x14);
} else if (fx[0x1C] == 1) {

*(f32 *) (particle + 0x28) = 0.0f;
}
else
{
    func_80800428_suflamefx((struct FlameFxSettings *) fx, (struct FlameFxParticle *) particle,
                            (f32 *) pos);
}
if (fx[0x1A] == 0xFF) {
    frame = particle[0x2C];
    if (frame >= fx[0x1D])
        particle[0x2C] = 0;
    else
        particle[0x2C] = frame + 1;

}
func_800EE780(particle + 0x18, particle, particle + 0xC);
}
}

// Draws the particles as billboards when the emitter is in view.
void suflamefx_entrypoint_3(FlameEffectDrawState *fx, void *gfx)
{
    f32 scale_vec[3];
    FlameEffectNode *particle;
    s32 i;
    void *sprite;

    particle = fx->particles;
    if (func_800E3E8C(particle->pos, 250.0f)) {
        sprite = func_800D674C(fx->sprite_id);
        func_800E2588(1);
        func_800E2594(gfx, sprite);
        for (i = 0; i < fx->count; i++, particle++) {
            if (particle->scale > 0.05f) {
                func_800EFA4C(scale_vec, particle->scale, particle->scale, particle->scale);
                func_800E2720(gfx, particle->frame, 0, particle->pos, scale_vec, 255);
            }

}
func_800E2A14(gfx);
}
}

// Stops respawning; particles disappear as they shrink away.
void suflamefx_entrypoint_4(s32 fx)
{
    ((u8 *) fx)[0x1C] = 1;
}

void suflamefx_entrypoint_5(s32 *fx, f32 rise_min, f32 rise_max)
{
    // Matching: dead store and empty block are needed for the match.
    int unk_0;
    unk_0 = 3;
    if (0) {
    }
    *(s16 *) ((char *) fx + 0xC) = (s16) rise_min;
    *(s16 *) ((char *) fx + 0xE) = (s16) rise_max;
}

void suflamefx_entrypoint_6(Actor *fx, f32 scale_rate)
{
    *(f32 *) ((char *) fx + 0x14) = scale_rate;
}

void suflamefx_entrypoint_7(u8 *fx, f32 *pos, f32 min_scale, f32 max_scale, f32 spread,
                            u8 frame, f32 drag)
{
    u8 *particle;
    s32 i;

    *(f32 *) (fx + 8) = min_scale;
    *(f32 *) (fx + 4) = max_scale;
    *(f32 *) (fx + 0) = spread;
    fx[0x1A] = frame;
    *(f32 *) (fx + 0x10) = drag;
    *(s16 *) (fx + 0xC) = 100;
    *(s16 *) (fx + 0xE) = 200;
    *(f32 *) (fx + 0x14) = -0.03f;
    fx[0x1C] = 0;
    if (fx[0x1A] == 0xFF) {
        fx[0x1D] = func_800AF5A0(func_800D674C(*(s16 *) (fx + 0x18))) - 1;
    } else {
        fx[0x1D] = 0xFF;
    }
    particle = fx + 0x20;
    for (i = 0; i < fx[0x1B]; i++, particle += 0x30) {
        func_80800428_suflamefx((struct FlameFxSettings *) fx,
                                (struct FlameFxParticle *) particle, pos);
        *(f32 *) (particle + 0x28) = func_800DC178(0.0f, *(f32 *) (fx + 4));
    }
}

// Spawns a particle at pos with random rise, scale, frame and drift direction.
void func_80800428_suflamefx(FlameFxSettings *fx, FlameFxParticle *particle, f32 *pos)
{
    f32 cam_pos[3];
    f32 angle;

    particle->offset[1] = func_800DC178(0.0f, 20.0f);
    particle->rise_accel = func_800DC178(fx->rise_min, fx->rise_max);
    particle->scale = func_800DC178(fx->min_scale, fx->max_scale);
    if (fx->frame == 0xFF) {
        particle->frame = func_800DC128(0, fx->max_frame);
    } else {
        particle->frame = fx->frame;
    }
    func_800EE7F8(particle->origin, pos);
    func_800E3980(cam_pos);
    angle = func_800F1DF4(particle->origin, cam_pos);
    func_800EFCD8(particle->offset, func_800DC178(-90.0f, 90.0f) + angle, fx->spread);
}
