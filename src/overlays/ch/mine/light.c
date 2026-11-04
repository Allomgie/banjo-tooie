#include "common.h"

// Power Hut basement lighting: fades nine point lights and map part 0x1AA when
// FLAG3_9E0 (lights on) changes.

typedef union {
    s32 word;
    void *pointer;
} MineLightMessage29;
extern void *_idworld_entrypoint_3(s32);
extern void *func_800BEA88(s32);
extern void func_800EDDDC(void *, f32 *, f32 *, f32);
extern s32 D_80800688_chminelight[];
extern s32 D_808006AC_chminelight[];
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} MineLightState;
extern u8 D_80800660_chminelight[];
extern u8 D_80800674_chminelight[];
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800C8800(s32, u32 *);
extern void func_800C8E84(s32, s32 *);

s32 func_80800000_chminelight(Actor *actor, s32 msg, MineLightMessage29 data)
{
    void *world_part;
    f32 brightness[4];
    void *entry;
    switch (msg) {
        case 0x95:
            world_part = _idworld_entrypoint_3(0x1AA);
            if (world_part) {
                brightness[0] = *(f32 *) ((u8 *) actor + 0x30);
                brightness[1] = *(f32 *) ((u8 *) actor + 0x30);
                brightness[2] = *(f32 *) ((u8 *) actor + 0x30);
                brightness[3] = *(f32 *) ((u8 *) actor + 0x30);
                entry = func_800BEA88(0);
                if (entry)
                    _idworldmake_entrypoint_1(entry, 0x69, 0x1AA, 1);
                entry = func_800BEA88(1);
                if (entry)
                    _idworldmake_entrypoint_1(entry, 0x69, 0x1AA, 1);
                func_800EDDDC(world_part, brightness, brightness, 0.0f);
            }
            if (_glcutDll_entrypoint_19(0x15)) {
                if (func_800DA298(0x9E0))
                    _capod_entrypoint_13(actor->unk0, 0, 0, 0x6910);
                else
                    _capod_entrypoint_13(actor->unk0, 0, 2, 0x6910);
                actor->unk64_20 = 1;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080011C_chminelight(actor) Actor *actor;
{
    u8 *base_colors;
    f32 scale;
    s32 color[3];
    s32 i;
    s32 world_part;
    f32 brightness[4];

    base_colors = func_80100094(actor, 0);
    switch (((MineLightState *) actor)->st) {
        case 2:
            if (*(f32 *) &actor->actorData[6] <= 0.975f) {
                if (func_8001210C(3)) {
                    *(f32 *) &actor->actorData[6] += 0.025f;
                }
            } else {
                actor->unk70_10 = 3;
            }
            break;
        case 4:
            if (0.02f <= *(f32 *) &actor->actorData[6]) {
                if (func_8001210C(3)) {
                    *(f32 *) &actor->actorData[6] -= 0.02f;
                }
            } else {
                actor->unk70_10 = 1;
            }
    }
    if (actor->unk54 != *(f32 *) &actor->actorData[6]) {
        scale = *(f32 *) &actor->actorData[6];
        if (scale < 0.9f && func_800DC0C0() < 0.8f) {
            scale *= func_800DC178(0.25f, 0.5f);
            func_800C8800(D_80800688_chminelight[actor->unk6C_0], actor->actorData);
            if (((MineLightState *) actor)->st == 2) {
                if (func_800DC0C0() < 0.3f) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800660_chminelight);
                }
            } else {
                if (func_800DC0C0() < 0.15f) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800674_chminelight);
                }
            }
        }
        for (i = 0; i != 2; i++) {
            color[0] = (u32) *(u8 *) ((s32) base_colors + actor->unk6C_0 * 3) * scale;
            color[1] = (u32) *(u8 *) ((s32) base_colors + actor->unk6C_0 * 3 + 1) * scale;
            color[2] = (u32) *(u8 *) ((s32) base_colors + actor->unk6C_0 * 3 + 2) * scale;
            func_800C8E84(D_80800688_chminelight[actor->unk6C_0], color);
            if (actor->unk6C_0 >= 8) {
                actor->unk6C_0 = 0;
                actor->unk54 = *(f32 *) &actor->actorData[6];
            } else {
                actor->unk6C_0++;
            }
        }
    }
    world_part = _idworld_entrypoint_3(0x1AA);
    if (world_part) {
        brightness[0] = *(f32 *) &actor->actorData[6];
        brightness[1] = *(f32 *) &actor->actorData[6];
        brightness[2] = *(f32 *) &actor->actorData[6];
        brightness[3] = *(f32 *) &actor->actorData[6];
        func_800EDDDC(world_part, brightness, brightness, 0.0f);
    }
}

void func_808004CC_chminelight(s32 arg0)
{
}

void func_808004D4_chminelight(Actor *actor)
{
    u8(*colors)[3];
    s32 color[4];
    s32 i;

    colors = func_80100094(actor, 0);

    for (i = 0; i < 9; i++) {
        func_800C8900(D_80800688_chminelight[i], color);
        colors[i][0] = color[0];
        colors[i][1] = color[1];
        colors[i][2] = color[2];
    }
    if (func_800DA298(0x9E0)) {
        if (actor->unk70_10 != 3) {
            ((u8 *) actor)[0x72] = (((u8 *) actor)[0x72] & ~0xFC) | 8;
            actor->unk54 = -1.0f;
            *(f32 *) &actor->actorData[6] = !_glcutDll_entrypoint_19(0x15) ? 1.0f : 0.0f;
        }
    } else {
        if (actor->unk70_10 != 1) {
            ((u8 *) actor)[0x72] = (((u8 *) actor)[0x72] & ~0xFC) | 0x10;
            actor->unk54 = -1.0f;
            *(f32 *) &actor->actorData[6] = !_glcutDll_entrypoint_19(0x15) ? 0.0f : 1.0f;
        }
    }
    func_8080011C_chminelight(actor);
}

int *chminelight_entrypoint_0()
{
    return (int *) &D_808006AC_chminelight;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800660_chminelight[20] = {0x0, 0x13, 0x4,  0xFC, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC,
                                 0x0, 0x16, 0x2E, 0xE0, 0x0, 0x2, 0x0, 0x0,  0x0, 0x0};
u8 D_80800674_chminelight[20] = {0x0, 0x13, 0x4,  0xFC, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC,
                                 0x0, 0x16, 0x17, 0x70, 0x0, 0x2, 0x0, 0x0,  0x0, 0x0};
s32 D_80800688_chminelight[9] = {0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB};
s32 D_808006AC_chminelight[21] = {0x2C80303,
                                  0x4,
                                  0x0,
                                  (u32) func_8080011C_chminelight,
                                  (u32) func_80105834,
                                  (u32) func_8010A730,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x80004,
                                  (u32) func_808004CC_chminelight,
                                  0x0,
                                  0x1B0000,
                                  (u32) func_808004D4_chminelight,
                                  (u32) func_80107C2C,
                                  -0x7FFFFFFE,
                                  (u32) func_80800000_chminelight,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0};
