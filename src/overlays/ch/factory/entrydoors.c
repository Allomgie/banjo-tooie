// Most likely the Grunty Industries entrance doors on Isle o' Hags: two mirrored door halves
// (variant 0x33 swings -75 degrees, the other +75), plus a small lock actor that vanishes once
// the world is open and plays particles and a sound on message 7.
#include "ch/factory/entrydoors.h"

extern void _chdoormake_entrypoint_0(Actor *, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void func_80103140();
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);
extern int D_808002B0_chfactoryentrydoors[];
extern u8 D_808002F8_chfactoryentrydoors[];
extern u8 D_80800390_chfactoryentrydoors[];
extern int D_808003A0_chfactoryentrydoors[];

// TU-NOTE: .data is defined in this C file; IDO schedules the functions differently otherwise.

// Init: door half swings -75 deg for variant 0x33, +75 deg otherwise.
void func_80800000_chfactoryentrydoors(Actor *actor)
{
    f32 swing_angle;
    s32 flag;

    if (_sujiggy_entrypoint_20(5))
        func_800DA544(0x397);
    if (func_800D3E40(11) && !_glcutDll_entrypoint_19(0x7F)) {
        flag = -1;
        func_80101FDC(actor, 4);
    } else
        flag = 0x397;
    if (actor->unk74_7 == 0x33)
        swing_angle = -75.0f;
    else
        swing_angle = 75.0f;
    _chdoormake_entrypoint_0(actor, swing_angle, 0, flag);
    _chdoormake_entrypoint_8(actor, 1);
    _chdoormake_entrypoint_5(actor, 0.0f);
}

s32 func_808000CC_chfactoryentrydoors(Actor *actor, s32 msg, s32 arg)
{
    s32 sound_id;

    if (msg == 0x95) {
        sound_id = actor->unk74_7 == 0x33 ? 0x971 : 0x972;
        func_80103140(actor, (u16) sound_id, *(u16 *) ((u8 *) actor->unk0 + 0x16));
    }
    return _chdoor_entrypoint_1(actor, msg, arg);
}

int chfactoryentrydoors_entrypoint_0()
{
    return (int) &D_808002B0_chfactoryentrydoors;
}

// Init (lock actor): removes itself once the world is open.
void func_8080014C_chfactoryentrydoors(s32 actor)
{
    if (((func_800DA298(0x397) != 0) || (func_800D3E40(0xB) != 0)) &&
        (_glcutDll_entrypoint_19(0x7F) == 0)) {
        func_800FFAB0(actor);
    }
}

int func_808001A0_chfactoryentrydoors(Actor *actor)
{
    if (func_800D90A4((char *) actor + 0x58) != 0) {
        func_80101180(0x48B, 7, (s32) *(f32 *) ((char *) actor + 0x34));
        func_800FFAB0(actor);
    }
}

// Message 7: particles and sound, then forwards the value.
s32 func_808001F0_chfactoryentrydoors(u8 *actor, s32 msg, s32 arg)
{
    if (msg == 7) {
        func_800BABB8(0, actor + 4, actor + 4, *(s32 *) ((u8 *) actor + 0x38),
                      &D_808002F8_chfactoryentrydoors);
        func_800C4AF0(actor + 4, &D_80800390_chfactoryentrydoors);
        *(u8 *) ((u8 *) actor + 0x65) = (u8) (*(u8 *) ((u8 *) actor + 0x65) & 0xFFFE);
        *(f32 *) ((u8 *) actor + 0x58) = 2.0f;
        func_80103110(actor, 1);
        *(f32 *) ((u8 *) actor + 0x34) = (f32) arg;
        return 1;
    }
    return 0;
}

int *chfactoryentrydoors_entrypoint_1()
{
    return &D_808003A0_chfactoryentrydoors;
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808002B0_chfactoryentrydoors[18] = {0xAC048B,
                                          0x9710001,
                                          0x0,
                                          (u32) _chdoor_entrypoint_0,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0xC00,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_80800000_chfactoryentrydoors,
                                          (u32) func_80107C2C,
                                          -0x7FFFDBFE,
                                          (u32) func_808000CC_chfactoryentrydoors,
                                          0x0};
u8 D_808002F8_chfactoryentrydoors[152] = {
    0x5,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x2,  0x0,  0x3,  0x0,  0x0,  0x22, 0x1, 0x80,
    0x2,  0x0,  0x4, 0x80, 0x6,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x26, 0x0,  0x19, 0x0, 0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0,  0x64, 0x0,  0x20, 0xA7, 0xA7, 0xA7, 0xC0, 0x0, 0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0,  0x64, 0x0,  0x4B, 0x0,  0x64, 0x5,  0x1A, 0x1, 0x10,
    0x0,  0x1D, 0x9, 0x73, 0x0,  0x1B, 0xFC, 0xE0, 0xFD, 0x44, 0x0,  0x2E, 0x0,  0xD7, 0x1, 0x2C,
    0x3,  0x20, 0x0, 0xF5, 0x1,  0x4A, 0x3,  0xE8, 0x0,  0x16, 0x0,  0x2,  0x0,  0x21, 0x0, 0xE6,
    0x0,  0x0,  0x0, 0x0,  0x0,  0x27, 0x1,  0x2C, 0x1,  0x2C, 0x1,  0x2C, 0x1,  0x2C, 0x0, 0x25,
    0x1,  0x0,  0x1, 0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0xE6, 0x0,  0x2B, 0xA,  0x0,  0xA, 0x0,
    0x0,  0x4,  0x0, 0xA6, 0x0,  0x7,  0x0,  0x6,  0x0,  0x3,  0x4,  0x17, 0x3A, 0x98, 0x0, 0x8,
    0x0,  0xE6, 0x1, 0x0,  0x1,  0x1A, 0x0,  0x0};
u8 D_80800390_chfactoryentrydoors[16] = {0x0, 0x13, 0x4,  0x13, 0x0, 0xA, 0x0, 0xE6,
                                         0x0, 0x16, 0x6D, 0x60, 0x0, 0x2, 0x0, 0x0};
int D_808003A0_chfactoryentrydoors[20] = {0x15804DB,
                                          0x9730001,
                                          0x0,
                                          (u32) func_808001A0_chfactoryentrydoors,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x3970000,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_8080014C_chfactoryentrydoors,
                                          (u32) func_80107C2C,
                                          -0x7FFFD3FE,
                                          (u32) func_808001F0_chfactoryentrydoors,
                                          0x0,
                                          0x0,
                                          0x0};
