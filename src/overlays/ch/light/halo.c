#include "common.h"

extern void *D_808006A8_chlighthalo;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800E8918(s32, s32, s32, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2AA4(void *, s32, s32, s32, f32 *, f32 *);
typedef struct Mass46HaloRange {
    f32 inner;
    f32 outer;
} Mass46HaloRange;
extern Mass46HaloRange D_808006A0_chlighthalo;
extern void func_800E8870(s32, f32);
extern void func_80105834(), func_80107C2C(), func_80800000_chlighthalo(),
    func_80800030_chlighthalo(), func_80800630_chlighthalo();

// Updates the occlusion probe position.
void func_80800000_chlighthalo(actor) u8 *actor;
{
    u8 probe;
    probe = *(u8 *) ((char *) actor + 0x34);
    // Matching: the multiply by 0 is needed for the match.
    if (probe != (*(u8 *) ((char *) actor + 0x34) * 0)) {
        func_800E8830(probe & 0xFF, actor + 4);
    }
}

// Releases the occlusion probe.
void func_80800030_chlighthalo(actor) u8 *actor;
{
    short probe;
    probe = *(u8 *) ((s8 *) actor + 0x34);
    if (probe != 0) {
        func_800E87E0(probe & 0xFF, probe, actor);
        *(u8 *) ((s8 *) actor + 0x34) = 0U;
    }
}

// Draws the halo with its alpha eased towards the probe's visibility; fades near screen edges.
void func_80800068_chlighthalo(Actor *actor, void *gfx)
{
    f32 screen[2];
    s32 target_alpha;
    s32 result;
    f32 fade_x;
    f32 fade_y;
    f32 scale_vec[3];

    target_alpha = 0;
    result = func_800E8918(*(u8 *) ((u8 *) actor + 0x34), func_800A89F8(), 0, screen);
    switch (result) {
        case -1:
            if (actor->unk64_20) {
                fade_x = 1.0f;
                fade_y = 1.0f;
                if (screen[0] < actor->scale * -30.0f ||
                    304.0f + actor->scale * 30.0f < screen[0]) {
                    fade_x = -1.0f;
                } else if (screen[0] <= 0.0f && actor->scale * -30.0f <= screen[0]) {
                    fade_x = func_800F10B4(screen[0], 0.0f, actor->scale * -30.0f, 1.0f, 0.0f);
                } else if (304.0f <= screen[0] && screen[0] <= 304.0f + actor->scale * 30.0f) {
                    fade_x = func_800F10B4(screen[0], 304.0f, 304.0f + actor->scale * 30.0f,
                                           1.0f, 0.0f);
                }
                if (screen[1] < actor->scale * -30.0f ||
                    228.0f + actor->scale * 30.0f < screen[1]) {
                    fade_y = -1.0f;
                } else if (screen[1] <= 0.0f && actor->scale * -30.0f <= screen[1]) {
                    fade_y = func_800F10B4(screen[1], 0.0f, actor->scale * -30.0f, 1.0f, 0.0f);
                } else if (228.0f <= screen[1] && screen[1] <= 228.0f + actor->scale * 30.0f) {
                    fade_y = func_800F10B4(screen[1], 228.0f, 228.0f + actor->scale * 30.0f,
                                           1.0f, 0.0f);
                }
                // Matching: the duplicated comparison is needed for the match.
                if (fade_y != -1.0f && fade_y != -1.0f) {
                    target_alpha = (fade_x + fade_y) * 0.5f * 255.0f;
                    result = 1;
                    break;
                }
            }
        case 0:
            target_alpha = (u32) actor->alpha * 0.3f;
            if (target_alpha != 0) {
                result = 1;
            }
            break;
        case 1:
            target_alpha = 0xFF;
    }
    actor->alpha = (actor->alpha + target_alpha) >> 1;
    if (result == 1) {
        _subaddiedraw25d_entrypoint_0(actor);
        func_800EFA4C(scale_vec, actor->scale, actor->scale, actor->scale);
        func_800E2588(0);
        func_800E24F8(*(u8 *) ((u8 *) actor + 0x98), *(u8 *) ((u8 *) actor + 0x99),
                      *(u8 *) ((u8 *) actor + 0x9A));
        func_800E257C(actor->alpha);
        func_800E2AA4(gfx, func_800D674C(actor->unk0->unk14), 0, 0, actor->position,
                      scale_vec);
        actor->unk64_20 = 1;
    } else {
        actor->unk64_20 = 0;
    }
}

// Matching: the line breaks in this function are needed for the match.
// Message 0x95: variant picks the colour; variants below 60 also get a point light.
s32 func_80800448_chlighthalo(actor, msg, unk_2) Actor *actor; s32 msg; s32 unk_2;
{
    s32 color;
    s32 rgb[3];
    Mass46HaloRange radius;

    if (msg == 0x95) {
        switch (actor->unk74_7) {
            case 50: case 60: color = 0xFFFF2000; break;
            case 51: case 61: color = 0x20FF0000; break;
            case 52: case 62: color = 0xFF202000; break;
            case 53: case 54: case 63: case 64: color = 0x20FFFF00; break;
            case 55: case 65: color = 0xFF802000; break;
            case 56: case 66: color = 0xFF60FF00; break;
            case 57: case 67: color = 0xFFFFFF00; break;
            default: color = 0xFFFFFF00; break;
        }
        rgb[0] = (u32)(color & 0xFF000000) >> 24; rgb[1] = (u32)(color & 0xFF0000) >> 16; rgb[2] = (u32)(color & 0xFF00) >> 8;
        _subaddiefade_entrypoint_11(actor, rgb);
        if ((s32)actor->unk74_7 < 60) {
            if (func_800BF8E4() > 0) {
                radius = D_808006A0_chlighthalo;
                radius.inner *= actor->scale;
                radius.outer *= actor->scale;
                actor->actorData[3] = func_800C8A98();
                func_800C8FB0(actor->actorData[3], rgb[0], rgb[1], rgb[2]);
                func_800C8CB8(actor->actorData[3], actor->position);
                func_800C8F64(actor->actorData[3], 5);
                func_800C8D4C(actor->actorData[3], &radius);
                func_800C8FE0(actor->actorData[3], 1);
            }
        }
        *(u8 *)&actor->actorData[7] = func_800E8714(1);
        func_800E8830(*(u8 *)&actor->actorData[7], actor->position);
        actor->rotation[1] += 50.0f;
        func_800E8870(*(u8 *)&actor->actorData[7], 50.0f);
        actor->unk64_20 = 0;
        *((u8 *)actor + 0x9B) = 0;
        return 1;
    }
    return 0;
}

void func_80800630_chlighthalo(s32 arg0)
{
}

int chlighthalo_entrypoint_0()
{
    return &D_808006A8_chlighthalo;
}

// TU-NOTE: the overlay's .data is defined here in C; its table points to functions of this
// file, and IDO's assembler schedules them differently otherwise. Values taken from the ROM.
Mass46HaloRange D_808006A0_chlighthalo = {2.5e+02f, 4e+02f};
void *D_808006A8_chlighthalo = (void *) 0x0158050A;
static u32 D_808006A8_chlighthalo_rest[17] = {0x9C70001,
                                              0x0,
                                              (u32) func_80800000_chlighthalo,
                                              (u32) func_80105834,
                                              (u32) func_80800068_chlighthalo,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x20000,
                                              (u32) func_80800030_chlighthalo,
                                              0x0,
                                              0x0,
                                              (u32) func_80800630_chlighthalo,
                                              (u32) func_80107C2C,
                                              0x80000402,
                                              (u32) func_80800448_chlighthalo,
                                              0x0};
