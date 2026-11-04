// Magic-spell effect for Mumbo's spells and Humba's transformations: swirling ring of sparkles,
// coloured point light, distance-scaled screen tint and the magic music track (0x1C).
#include "common.h"

extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8();
extern void func_800EF04C();
extern void func_8010D254();
typedef struct {
    f32 angle;
    f32 unk_4;
    u8 pad_8[8];
    f32 pos[3];
    u8 pad_1C[0xC];
    f32 fade;
} MumboEffectBlend;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF334(f32 *, f32);
typedef struct {
    u8 pad_0[0x10];
    f32 time_left;
    f32 duration;
    u8 pad_18[0x10];
    f32 center[3];
    f32 near_sq;
    f32 far_sq;
    u8 pad_3C[0xC];
    u8 tint_color[0xC];
    s32 tint_strength;
    u8 pad_58[8];
    u32 mode : 7;
    u32 pad_60 : 17;
    u8 distance_fade;
} MumboFx;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void *func_800F54E4(void);
extern void func_800F5A00(void *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800B99CC(s32, s32, u8 *);
extern Vec3f D_808014DC_sumumbofx;
extern void func_800F3214(f32 *, f32 *, f32 *, f32);
extern void func_800C8E84(s32, f32 *);
extern f32 func_800DC178(f32, f32);
typedef struct {
    f32 angle;
    f32 offset;
    f32 radius;
    f32 speed;
    u8 pad_10[0x10];
    f32 phase;
    f32 period;
    f32 pad_28;
} MumboSpark29;
typedef struct {
    u8 pad_0[0x58];
    s16 count;
    u8 pad_5A[0xA];
    MumboSpark29 sparks[1];
} MumboParticles29;
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
typedef struct {
    f32 angle;
    f32 height;
    f32 rise_speed;
    f32 spin_speed;
    f32 pos[3];
    f32 scale;
    f32 phase;
    f32 period;
    f32 fade;
} MumboParticle48;
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
typedef struct {
    u32 mode : 7;
    u32 pad_0 : 25;
} Broad51MumboFXFlags;
extern u8 D_808014D0_sumumbofx[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    u8 pad_0[0x60];
    u32 mode : 7;
    u32 dirty : 1;
    u32 pad_61 : 24;
} Mass47MumboFX;
int sumumbofx_entrypoint_13();
void sumumbofx_entrypoint_20(void *param_0, f32 param_1);

// The component lives in an actor slot: a 0x64-byte header followed by `count` sparkles of 0x2C bytes.
void sumumbofx_entrypoint_0(Actor *actor, u32 slot, s32 count, s16 sound)
{
    u8 *fx;
    func_80100074(actor, slot, count * 44 + 0x64);
    fx = func_80100094(actor, slot);
    *(s32 *) fx = sound;
    *(s16 *) (fx + 0x58) = count;
    func_800EE7F8((f32 *) (fx + 0x1C), actor->position);
    fx[0x63] = 0;
}

// Frees the component and stops its music and light.
void sumumbofx_entrypoint_1(Actor *actor, u32 slot)
{
    u8 *fx;
    fx = func_80100094(actor, slot);
    if (*(s16 *) (fx + 0x5E)) {
        sumumbofx_entrypoint_13(fx);
    }
    switch (fx[0x62]) {
        case 1:
            break;
        case 2:
            func_800FCAE0(0x1C, 0, 0x4E20);
            func_800FCA90(0x1C);
    }
    func_80100074(actor, slot, 0);
}

// Resets the component state and randomises all sparkles.
void sumumbofx_entrypoint_2(u8 *fx)
{
    s32 i;
    u8 *spark;

    *(s16 *) (fx + 0x5A) = 0;
    *(s16 *) (fx + 0x5C) = 0;
    fx[0x60] &= ~0xFE;
    *(s16 *) (fx + 0x5E) = 0;
    fx[0x61] = 0;
    fx[0x62] = 2;
    *(s32 *) (fx + 0x54) = -1;
    *(f32 *) (fx + 0x10) = 0.0f;
    *(f32 *) (fx + 0x14) = 0.0f;
    *(f32 *) (fx + 0x18) = 0.0f;
    *(f32 *) (fx + 4) = 0.0f;
    *(f32 *) (fx + 12) = 1.0f;
    for (i = 0, spark = fx + 0x64; i < *(s16 *) (fx + 0x58);
         i++, spark += 0x2C) {
        *(f32 *) (spark + 0x1C) = 0.0f;
        *(f32 *) (spark + 0x24) = func_800DC178(0.4f, 0.8f);
        *(f32 *) (spark + 0x20) = func_800DC178(0, *(f32 *) (spark + 0x24));
        *(f32 *) spark = func_800DC178(0.0f, 359.0f);
        *(f32 *) (spark + 4) = 0.0f;
        *(f32 *) (spark + 12) = func_800DC178(8.0f, 16.0f);
        *(f32 *) (spark + 8) = func_800DC178(8.0f, 16.0f);
    }
}

// Randomises all sparkles; offset is picked in [0, max_offset].
void sumumbofx_entrypoint_3(MumboParticles29 *fx, f32 max_offset)
{
    s32 i;
    MumboSpark29 *spark = fx->sparks;
    for (i = 0; i < fx->count; i++, spark++) {
        spark->period = func_800DC178(0.4f, 0.8f);
        spark->phase = func_800DC178(0, spark->period);
        spark->angle = func_800DC178(0.0f, 359.0f);
        spark->offset = func_800DC178(0.0f, max_offset);
        spark->speed = func_800DC178(8.0f, 16.0f);
        spark->radius = func_800DC178(8.0f, 16.0f);
    }
}

// Sets every sparkle and the whole effect to full intensity.
void sumumbofx_entrypoint_4(u8 *fx)
{
    s32 i;
    // Matching: the same-type cast and the extra pointer temporary are needed for the match.
    f32 *intensity;
    u8 *spark;
    spark = fx + 0x64;
    i = 0;
    *(f32 *) ((s8 *) fx + 8) = 0.0f;
    if (*(s16 *) ((s8 *) fx + 0x58) > 0) {
        do {
            *(f32 *) ((s8 *) spark + 0x28) = 1.0f;
            i += 1;
            spark += 0x2C;
            *(f32 *) ((s8 *) fx + 8) = (f32) (*(f32 *) ((s8 *) fx + 8) + 1.0f);
        } while (i < *(s16 *) ((s8 *) fx + 0x58));
    }
    intensity = (f32 *) ((s8 *) fx + 4);
    if (*intensity != 1.0f) {
        *(f32 *) ((s8 *) fx + 4) = 1.0f;
        *(u8 *) ((s8 *) fx + 0x60) = (u8) ((*(u8 *) ((s8 *) fx + 0x60) & 0xFF) | 1);
    }
}

// Blends a sparkle's position towards a point around the player, weighted by its fade value.
void func_808003E4_sumumbofx(MumboEffectBlend *spark, f32 max_height, f32 radius)
{
    f32 point[3];
    f32 player_pos[3];

    func_8010D254(player_pos);
    func_800EEB9C(point, spark->angle, radius);
    point[1] = spark->unk_4 * 0.75f;
    if (max_height < point[1]) {
        do {
            point[1] -= max_height;
        } while (max_height < point[1]);
    }
    func_800EF04C(point, player_pos);
    func_800EF334(point, 1.0f - spark->fade);
    func_800EF334(spark->pos, spark->fade);
    func_800EF04C(spark->pos, point);
}

// Fades sparkles in one by one; returns 1 when all are fully faded in.
s32 sumumbofx_entrypoint_5(u8 *fx, f32 spawn_time)
{
    s32 i;
    s32 done_count = 0;
    u8 *spark;
    f32 fade;
    f32 raw_step;
    f32 step;
    spark = fx + 0x64;
    *(f32 *) (fx + 8) = 0.0f;
    for (i = 0; i < *(s16 *) (fx + 0x58); i++, spark += 0x2C) {
        if (*(s16 *) (fx + 0x5A) >= i) {
            fade = *(f32 *) (spark + 0x28);
            if (fade < 0.98f) {
                raw_step = (1.0f - fade) * 0.075f;
                step = raw_step < 0.02f ? 0.02f : raw_step;
                *(f32 *) (spark + 0x28) = fade + step;
            } else {
                *(f32 *) (spark + 0x28) = 1.0f;
                done_count++;
            }
        }
        *(f32 *) (fx + 8) += *(f32 *) (spark + 0x28);
    }
    *(s16 *) (fx + 0x5A) = func_800F10B4(*(f32 *) (fx + 0x18), 0.0f, spawn_time, 0.0f,
                                         (f32) *(s16 *) (fx + 0x58));
    *(f32 *) (fx + 0x18) += func_800D8FF8();
    if (done_count < *(s16 *) (fx + 0x58))
        return 0;
    return 1;
}

// Advances a sparkle's phase and sets its scale from the effect mode and progress.
void func_8080060C_sumumbofx(void *fx, void *spark, f32 progress)
{
    f32 scale;
    scale = *(f32 *) ((u8 *) spark + 0x28) * *(f32 *) ((u8 *) fx + 0xC) +
            (1.0f - *(f32 *) ((u8 *) spark + 0x28)) * 0.25f;
    *(f32 *) ((u8 *) spark + 0x20) += func_800D8FF8();
    if (*(f32 *) ((u8 *) spark + 0x20) >= *(f32 *) ((u8 *) spark + 0x24))
        *(f32 *) ((u8 *) spark + 0x20) -= *(f32 *) ((u8 *) spark + 0x24);
    switch (*(u32 *) ((u8 *) fx + 0x60) >> 25) {
        case 2:
            progress = 1.0f - progress;
        case 1:
            *(f32 *) ((u8 *) spark + 0x1C) =
                (func_80013970(func_800F10B4(*(f32 *) ((u8 *) spark + 0x20), 0.0f,
                                             *(f32 *) ((u8 *) spark + 0x24), 0.0f, 180.0f)) *
                     0.7f +
                 0.3f) *
                (progress * scale);
            break;
        case 0:
            *(f32 *) ((u8 *) spark + 0x28) += 0.02f;
            if (*(f32 *) ((u8 *) spark + 0x28) > 1.0f)
                *(f32 *) ((u8 *) spark + 0x28) = 1.0f;
        case 3:
            *(f32 *) ((u8 *) spark + 0x1C) =
                (func_80013970(func_800F10B4(*(f32 *) ((u8 *) spark + 0x20), 0.0f,
                                             *(f32 *) ((u8 *) spark + 0x24), 0.0f, 180.0f)) *
                     0.7f +
                 0.3f) *
                scale;
    }
}

f32 sumumbofx_entrypoint_26();

// Updates sparkles first..last-1 as a column rising around the center.
void sumumbofx_entrypoint_6(u8 *fx, f32 max_height, f32 radius, s32 first, s32 last,
                            f32 *center, f32 *offset, f32 *unk_0)
{
    f32 progress;
    MumboParticle48 *spark;
    f32 *point;
    s32 i;
    u32 mode;
    // Matching: constant kept in a local so it becomes the left operand of beql.
    s32 k = 1;

    progress = sumumbofx_entrypoint_26();
    spark = (MumboParticle48 *) (fx + 0x64) + first;
    for (i = first; i < last; i++, spark++) {
        func_8080060C_sumumbofx(fx, spark, progress);
        point = spark->pos;
        spark->height += spark->rise_speed;
        if (max_height < spark->height) {
            spark->height = 0.0f;
            mode = *(u32 *) (fx + 0x60) >> 25;
            if (k != mode && mode != 2) {
                spark->scale = 0.25f;
            }
        }
        spark->angle += spark->spin_speed;
        if (spark->angle > 359.0f) {
            spark->angle = 0.0f;
        }
        func_800EEB9C(point, spark->angle, radius);
        spark->pos[1] = spark->height;
        func_800EF04C(point, center);
        if (unk_0 != NULL) {
            func_800EF5A0(point, unk_0, spark->pos[0], spark->pos[1],
                          spark->pos[2]);
        }
        if (offset != NULL) {
            func_800EF04C(point, offset);
        }
        if (spark->fade < 1.0f) {
            func_808003E4_sumumbofx(spark, 125.0f, 40.0f);
        }
    }
    if (offset != NULL) {
        func_800EE7F8((f32 *) (fx + 0x1C), offset);
    }
}

// Updates sparkles first..last-1 as points swirling on a sphere around the center.
void sumumbofx_entrypoint_7(u8 *fx, f32 radius, s32 first, s32 last, s32 center,
                            f32 *offset, s32 unk_0)
{
    f32 progress;
    s32 i;
    u8 *spark;
    f32 *point;

    progress = sumumbofx_entrypoint_26((f32 *) fx);
    spark = fx;
    spark += first * 0x2C + 0x64;
    for (i = first; i < last; i++) {
        func_8080060C_sumumbofx(fx, spark, progress);
        point = (f32 *) (spark + 0x10);
        *(f32 *) (spark + 4) += *(f32 *) (spark + 8) * 0.15f;
        if (*(f32 *) (spark + 4) > 359.0f) {
            while (*(f32 *) (spark + 4) > 359.0f) {
                *(f32 *) (spark + 4) -= 360.0f;
            }
            if (((Broad51MumboFXFlags *) (fx + 0x60))->mode != 1 &&
                ((Broad51MumboFXFlags *) (fx + 0x60))->mode != 2) {
                *(f32 *) (spark + 0x1C) = 0.25f;
            }
        }
        *(f32 *) spark += *(f32 *) (spark + 0xC) * 0.3f;
        if (*(f32 *) spark > 359.0f) {
            *(f32 *) spark = 0.0f;
        }
        func_800EF4E4(point, *(f32 *) (spark + 4), *(f32 *) spark, 0.0f, 0.0f, radius);
        func_800EF04C(point, center);
        if (unk_0) {
            func_800EF5A0(point, unk_0, *(f32 *) (spark + 0x10), *(f32 *) (spark + 0x14),
                          *(f32 *) (spark + 0x18));
        }
        if (offset) {
            func_800EF04C(point, offset);
        }
        if (*(f32 *) (spark + 0x28) < 1.0f) {
            func_808003E4_sumumbofx(spark, 125.0f, 40.0f);
        }
        spark += 0x2C;
    }
    if (offset) {
        func_800EE7F8((f32 *) (fx + 0x1C), offset);
    }
}

// Draws the sparkles.
void sumumbofx_entrypoint_8(u8 *fx, void *gfx)
{
    // Matching: unused local needed for the match.
    Vec3f unk_0 = *(Vec3f *) D_808014D0_sumumbofx;
    f32 scale_vec[3];
    u8 *spark;
    void *sprite;
    s32 i;
    f32 size;
    fx[0x61] = 1;
    sprite = (void *) func_800D674C(*(s32 *) fx);
    func_800E2588(2);
    func_800E2594(gfx, sprite);
    func_800E24D8(1);
    spark = fx + 0x64;
    for (i = 0; i < *(s16 *) (fx + 0x58); i++, spark += 0x2C) {
        size = *(f32 *) (spark + 0x1C);
        if (size > 0.005f) {
            func_800EFA4C(scale_vec, size, size, size);
            func_800E2720(gfx, 0, 0, spark + 0x10, scale_vec,
                          (s32) (*(f32 *) (fx + 4) * 127.0f + 128.0f));
        }
    }
    func_800E2A14(gfx);
}

// Applies the screen tint, scaled by the effect mode and the camera distance.
void sumumbofx_entrypoint_9(MumboFx *fx, s32 unk_0)
{
    f32 factor;
    f32 cam_pos[3];
    f32 dist_sq;

    if (fx->tint_strength == -1) {
        return;
    }
    switch (fx->mode) {
        case 1:
            factor = func_800F10B4(fx->time_left, fx->duration, 0.0f, 0.0f, 1.0f);
            break;
        case 0:
        case 3:
            factor = 1.0f;
            break;
        case 2:
            factor = func_800F10B4(fx->time_left, fx->duration, 0.0f, 1.0f, 0.0f);
    }
    if (fx->distance_fade) {
        func_800F5A00(func_800F54E4(), cam_pos);
        dist_sq = func_800EEB40(fx->center, cam_pos);
        if (!(dist_sq < fx->near_sq)) {
            if (fx->far_sq < dist_sq) {
                factor = 0.0f;
            } else {
                factor *= func_800F10B4(dist_sq, fx->near_sq, fx->far_sq, 1.0f, 0.0f);
            }
        }
    } else { // Matching: the empty else block is needed for the match.
    }
    func_800B99CC(unk_0, fx->tint_strength * factor, fx->tint_color);
}

s32 sumumbofx_entrypoint_10(u8 *fx)
{
    // Matching: the extra pointer temporary and the same-type cast are needed for the match.
    u8 *base;
    base = (u8 *) fx;
    return (s32) (255.0f - (((*(f32 *) (base + 8) / (f32) *(s16 *) ((u8 *) fx + 0x58)) *
                             *(f32 *) ((u8 *) fx + 4)) *
                            255.0f));
}

int sumumbofx_entrypoint_11(fx)
s32 fx;
{
    s16 light_id;
    light_id = *(s16 *) ((char *) fx + 0x5e);
    func_800C8CB8(light_id);
}

// Updates the point light colour from the effect intensity.
void func_80800F8C_sumumbofx(u8 *fx)
{
    f32 light_color[3];
    Vec3f black = D_808014DC_sumumbofx;

    func_800F3214(light_color, black.f, (f32 *) (fx + 0x3C), *(f32 *) (fx + 4));
    func_800C8E84(*(s16 *) (fx + 0x5E), light_color);
}

// Creates the point light.
void sumumbofx_entrypoint_12(s32 base, s32 unk_0, s32 unk_1, s32 color)
{
    s32 *fx = (s32 *) base;
    func_800EE830(base + 0x3C, color);
    *(s16 *) ((char *) fx + 0x5E) = func_800C8A98();
    func_80800F8C_sumumbofx(fx);
    sumumbofx_entrypoint_11(fx, unk_0);
    func_800C8D4C(*(s16 *) ((char *) fx + 0x5E), unk_1);
}

int sumumbofx_entrypoint_13(fx)
s32 fx;
{
    s16 light_id;
    light_id = *(s16 *) ((char *) fx + 0x5e);
    func_800C8B84(light_id);
}

// Per-frame update: intensity, music volume, timer and light.
void sumumbofx_entrypoint_14(u8 *fx)
{
    // Matching: unused padding local needed for the match.
    f32 pad[2];
    f32 cam_pos[4];
    f32 tmp;
    f32 volume_scale;

    switch (((Mass47MumboFX *) fx)->mode) {
        case 2:
            tmp = sumumbofx_entrypoint_26((f32 *) fx);
            tmp = 1.0f - tmp;
            ((Mass47MumboFX *) fx)->dirty = tmp != *(f32 *) (fx + 4);
            *(f32 *) (fx + 4) = tmp;
            break;
        case 1:
            tmp = sumumbofx_entrypoint_26((f32 *) fx);
            ((Mass47MumboFX *) fx)->dirty = tmp != *(f32 *) (fx + 4);
            *(f32 *) (fx + 4) = tmp;
    }
    if (fx[0x61] && *(f32 *) (fx + 4) > 0.1f && fx[0x62] == 2) {
        if (fx[0x63]) {
            func_800F5A00(func_800F54E4(), cam_pos);
            tmp = func_800EEB40((f32 *) (fx + 0x28), cam_pos);
            if (tmp < *(f32 *) (fx + 0x34)) {
                volume_scale = 1.0f;
            } else if (*(f32 *) (fx + 0x38) < tmp) {
                volume_scale = 0.0f;
            } else {
                volume_scale = func_800F10B4(tmp, *(f32 *) (fx + 0x34),
                                             *(f32 *) (fx + 0x38), 1.0f, 0.0f);
            }
        } else {
            volume_scale = 1.0f;
        }
        func_800FCAE0(0x1C, (s32) (*(f32 *) (fx + 4) * 20000.0f * volume_scale), 500);
    }
    fx[0x61] = 0;
    func_800D9078(fx + 0x10);
    if (((Mass47MumboFX *) fx)->dirty) {
        ((Mass47MumboFX *) fx)->dirty = 0;
        if (*(s16 *) (fx + 0x5E)) {
            func_80800F8C_sumumbofx(fx);
        }
    }
}

// Entrypoints 15 to 18 set the effect mode and the duration.
void sumumbofx_entrypoint_15(u8 *fx, f32 duration)
{
    fx[0x60] = (fx[0x60] & 0xFF01) | 2;
    sumumbofx_entrypoint_20(fx, duration);
}

void sumumbofx_entrypoint_16(u8 *fx, f32 duration)
{
    fx[0x60] = (fx[0x60] & 0xFF01) | 4;
    sumumbofx_entrypoint_20(fx, duration);
}

void sumumbofx_entrypoint_17(u8 *fx, f32 duration)
{
    fx[0x60] &= 0xFF01;
    sumumbofx_entrypoint_20(fx, duration);
}

void sumumbofx_entrypoint_18(u8 *fx, f32 duration)
{
    fx[0x60] = (fx[0x60] & 0xFF01) | 6;
    sumumbofx_entrypoint_20(fx, duration);
}

void sumumbofx_entrypoint_19(u8 *fx, unsigned int music_mode)
{
    *(s8 *) ((s8 *) fx + 0x62) = music_mode;
}

void sumumbofx_entrypoint_20(void *fx, f32 duration)
{
    *(f32 *) ((char *) fx + 0x10) = duration;
    *(f32 *) ((char *) fx + 0x14) = duration;
}

f32 sumumbofx_entrypoint_21(fx) void *fx;
{
    return ((f32 *) fx)[4];
}

f32 sumumbofx_entrypoint_22(f32 fx[3])
{
    return fx[1];
}

void sumumbofx_entrypoint_23(f32 fx[3], f32 intensity)
{
    fx[1] = intensity;
}

void sumumbofx_entrypoint_24(void *fx, float scale)
{
    *(float *) ((char *) fx + 12) = scale;
}

void sumumbofx_entrypoint_25(u8 *fx, s32 strength, s32 color)
{
    *(s32 *) (fx + 0x54) = strength;
    func_800EE830(fx + 0x48, color);
}

f32 sumumbofx_entrypoint_26(fx)
f32 fx[4];
{
    return 1.0f - fx[4] / fx[5];
}

s32 sumumbofx_entrypoint_27(void)
{
    return sumumbofx_entrypoint_21() <= 0.0f;
}

// Enables fading with distance from the center: full inside near_dist, zero beyond far_dist.
int sumumbofx_entrypoint_28(s32 fx, s32 center, f32 near_dist, f32 far_dist)
{
    u8 *enabled;
    enabled = &*(s32 *) ((char *) fx + 0x63);
    *enabled = 1;
    func_800EE7F8(&*(s32 *) ((char *) fx + 0x28), center, fx);
    *(f32 *) ((char *) fx + 0x34) = near_dist * near_dist;
    *(f32 *) ((char *) fx + 0x38) = far_dist * far_dist;
}

// TU-NOTE: .data of this overlay is defined here in C; values are taken from the ROM.
u8 D_808014D0_sumumbofx[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
Vec3f D_808014DC_sumumbofx = {0.0f, 0.0f, 0.0f};
