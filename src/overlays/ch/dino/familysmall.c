// Small Styracosaurus child NPC: stays tiny until Mumbo casts the enlarge spell on it (mumbofx
// charge, wobbling and bouncing growth, camera-shaking landing), then sets its "grown" flags.
#include "common.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef union {
    s32 word;
    void *pointer;
} DinoMessage30;
extern u8 D_80800F10_chdinofamilysmall[];
extern u16 D_80800E94_chdinofamilysmall[][4];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 _capod_entrypoint_14(void);
extern f32 B_80800F94_chdinofamilysmall[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800DF500(f32, f32, f32);
extern void func_800DE498(s32, f32 *, f32 *, f32, s32, void *);
extern void *func_800D674C(s32);
extern void *D_80800F20_chdinofamilysmall;
extern f32 func_80103EAC(Actor *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern f32 _sumumbofx_entrypoint_26(void *);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, s32, s32);
extern void _sumumbofx_entrypoint_5(void *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern void func_800C4244(s32, f32, s32, f32 *, f32, f32);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern void _sumumbofx_entrypoint_24(void *, f32);
void func_808008B4_chdinofamilysmall();

void func_80800000_chdinofamilysmall(Actor *actor)
{
    if (_glcutDll_entrypoint_20())
        func_808008B4_chdinofamilysmall(actor, 10);
    else if (!func_800DA298(0x15F))
        func_808008B4_chdinofamilysmall(actor, 1);
    else
        func_808008B4_chdinofamilysmall(actor, 9);
    ((f32 *) actor->actorData)[7] = actor->position[1];
    func_800EFA4C((f32 *) &actor->actorData[4], 1.0f, 1.0f, 1.0f);
}

// Update: runs the Mumbo enlarge spell sequence (states 3-8).
void func_80800090_chdinofamilysmall(Actor *actor)
{
    extern u8 D_80800EE8_chdinofamilysmall[];
    extern u8 D_80800EFC_chdinofamilysmall[];
    f32 pos_3[3];
    f32 pos_4[3];
    f32 pos_5[3];
    f32 pos_6[3];
    f32 ease;
    f32 pos_7[3];
    f32 spell_time;

    switch (actor->unk70_10) {
        case 1:
            if (_subaddiedialog_entrypoint_4(actor->position, 0x258, 0)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17CB, 0xF, actor->position, 0x39);
            }
            _sudeflect_entrypoint_1(actor->position, actor->scale * 235.0f, 0,
                                    actor->scale * 179.0f, 0x1E);
            _chdinofamilyfx_entrypoint_0(actor);
            break;
        case 2:
            if (func_800DA298(0x9DE)) {
                func_808008B4_chdinofamilysmall(actor, 3);
            }
            _chdinofamilyfx_entrypoint_0(actor);
            break;
        case 3:
            func_80103DFC(actor, pos_3);
            _sumumbofx_entrypoint_7(func_80100094(actor, 1), func_80103EAC(actor), 0, 0x28,
                                    pos_3, 0, 0);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_808008B4_chdinofamilysmall(actor, 4);
            }
            _chdinofamilyfx_entrypoint_0(actor);
            break;
        case 4:
            func_80103DFC(actor, pos_4);
            _sumumbofx_entrypoint_7(func_80100094(actor, 1), func_80103EAC(actor), 0, 0x28,
                                    pos_4, 0, 0);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            _sumumbofx_entrypoint_5(func_80100094(actor, 1), 2.0f);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_808008B4_chdinofamilysmall(actor, 5);
            }
            break;
        case 5:
            func_80103DFC(actor, pos_5);
            _sumumbofx_entrypoint_7(func_80100094(actor, 1), func_80103EAC(actor), 0, 0x28,
                                    pos_5, 0, 0);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            actor->position[1] = func_800F12D4(
                _sumumbofx_entrypoint_26(func_80100094(actor, 1)), 0.0f, 1.0f, 0.0f, 800.0f);
            actor->position[1] += *(f32 *) ((u8 *) actor + 0x34);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_808008B4_chdinofamilysmall(actor, 6);
            }
            break;
        case 6:
            func_80103DFC(actor, pos_6);
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 1)) > 2.0f) {
                if (!actor->unk64_20) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800EE8_chdinofamilysmall);
                    actor->unk64_20 = 1;
                }
                actor->scale = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)),
                                               4.0f, 2.0f, 0.5f, 0.50f);
                *(f32 *) ((u8 *) actor + 0x30) = *(f32 *) ((u8 *) actor + 0x2C) =
                    *(f32 *) ((u8 *) actor + 0x28) =
                        func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)), 4.0f,
                                      2.0f, 1.0f, 2.0f);
            } else {
                ease = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)), 2.0f,
                                        0.0f, 1.0f, 0.0f);
                if (!actor->unk64_19) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800EFC_chdinofamilysmall);
                    actor->unk64_19 = 1;
                }
                actor->scale = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)),
                                               2.0f, 0.0f, 0.50f, 1.0f);
                *(f32 *) ((u8 *) actor + 0x28) =
                    func_800138D0(ease * 3.0f * 360.0f) * ease + 1.0f;
                *(f32 *) ((u8 *) actor + 0x2C) =
                    func_800138D0(ease * 5.0f * 360.0f) * ease + 1.0f;
                *(f32 *) ((u8 *) actor + 0x30) =
                    func_800138D0(ease * 4.0f * 360.0f) * ease + 1.0f;
            }
            _sumumbofx_entrypoint_7(
                func_80100094(actor, 1),
                func_80103EAC(actor) *
                    (func_80013970(_sumumbofx_entrypoint_26(func_80100094(actor, 1)) * 180.0f) *
                         2.0f +
                     1.0f),
                0, 0x28, pos_6, 0, 0);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_808008B4_chdinofamilysmall(actor, 7);
            }
            break;
        case 7:
            func_80103DFC(actor, pos_7);
            _sumumbofx_entrypoint_7(func_80100094(actor, 1), func_80103EAC(actor), 0, 0x28,
                                    pos_7, 0, 0);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            spell_time = _sumumbofx_entrypoint_21(func_80100094(actor, 1));
            if (spell_time <= (0.55f * 3.0f) && spell_time >= 1.05f) {
                actor->position[1] =
                    func_800138D0(func_800F10B4(spell_time, (0.55f * 3.0f), 1.05f, 0.0f, 90.0f)) *
                    800.0f;
                actor->position[1] += *(f32 *) ((u8 *) actor + 0x34);
            } else if (spell_time < 1.05f) {
                if (!actor->unk74_30) {
                    func_800C4244(0x416, 0.9f, 0x55F0, actor->position, 100.0f, 2500.0f);
                    actor->unk74_30 = 1;
                    func_800E1610(3, 100.0f, 0.6f, actor->position);
                    actor->position[1] = *(f32 *) ((u8 *) actor + 0x34);
                }
            }
            if (spell_time <= 0.0f) {
                func_808008B4_chdinofamilysmall(actor, 8);
            }
            break;
        case 8:
            func_808008B4_chdinofamilysmall(actor, 9);
            break;
        case 9:
            if (_subaddiedialog_entrypoint_4(actor->position, 0x258, 0)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17CC, 0xF, actor->position, 0x39);
            }
            _sudeflect_entrypoint_1(actor->position, actor->scale * 235.0f, 0,
                                    actor->scale * 179.0f, 0x1E);
            _chdinofamilyfx_entrypoint_0(actor);
            break;
        case 10:
            _chdinofamilyfx_entrypoint_0(actor);
    }
}

// Enter spell state; sets the grown flags 0x9DF and 0x15F at the end and clears 0x9DE.
void func_808008B4_chdinofamilysmall(actor, state) Actor *actor;
s32 state;
{
    f32 vec[4];
    switch (state) {
        case 1:
            actor->scale = 0.5f;
            break;
        case 3:
            *(s32 *) &vec[1] = 0;
            *(s32 *) &vec[2] = 0;
            *(s32 *) &vec[3] = 0;
            _sumumbofx_entrypoint_0(actor, 1, 0x28, _chmumbopad_entrypoint_0(7));
            _sumumbofx_entrypoint_2(func_80100094(actor, 1));
            _sumumbofx_entrypoint_25(func_80100094(actor, 1), 0x7D, &vec[1]);
            _sumumbofx_entrypoint_24(func_80100094(actor, 1), 0.2f);
            _sumumbofx_entrypoint_15(func_80100094(actor, 1), 3.0f);
            _capod_entrypoint_13(actor->unk0, 0, 0x15, 0x210);
            func_8010A800(actor, 2);
            break;
        case 4:
            _sumumbofx_entrypoint_18(func_80100094(actor, 1), 2.0f);
            _chglowbo_entrypoint_6();
            break;
        case 5:
            _sumumbofx_entrypoint_17(func_80100094(actor, 1), 3.0f);
            break;
        case 6:
            actor->unk64_19 = 0;
            actor->unk64_20 = 0;
            _sumumbofx_entrypoint_20(func_80100094(actor, 1), 4.0f);
            actor->position[1] = *(f32 *) &actor->actorData[7] + 800.0f;
            break;
        case 7:
            actor->unk74_30 = 0;
            _sumumbofx_entrypoint_16(func_80100094(actor, 1), 3.0f);
            *((u8 *) actor + 0x77) &= ~0xF;
            actor->scale = 1.0f;
            break;
        case 8:
            _sumumbofx_entrypoint_1(actor, 1);
            func_8010A800(actor, 0);
            actor->position[1] = *(f32 *) &actor->actorData[7];
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            func_800DA544(0x15F);
            break;
        case 9:
        case 10:
            actor->scale = 1.0f;
    }
    func_80102424(actor, state);
}

s32 func_80800AF4_chdinofamilysmall(Actor *actor, s32 msg, DinoMessage30 arg)
{
    switch (msg) {
        case 0xB:
            _capod_entrypoint_14();
            func_80101180(0x290, 0x33, 1);
            return 4;
        case 0x4B:
            func_80101FDC(actor, 2);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_3(D_80800F10_chdinofamilysmall, actor->scale);
            return 3;
        case 0x1F:
            func_801015D0(actor);
            if (D_80800E94_chdinofamilysmall[actor->unk70_10][0] == 0x14D)
                func_800DF744(3, 1);
            else {
                func_800DF744(1, 0);
                func_800DF744(2, 1);
                func_800DF744(3, 2);
            }
            return 1;
        default:
            return 0;
    }
}

f32 B_80800F70_chdinofamilysmall[12];
f32 B_80800FA0_chdinofamilysmall[4];

void func_80800C10_chdinofamilysmall(Actor *actor, s32 gfx)
{
    f32 *unk_0;
    f32 *unk_1;
    s32 i;

    if (func_80100094(actor, 1)) {
        _sumumbofx_entrypoint_9(func_80100094(actor, 1), gfx);
    }
    if (actor->unk70_10 == 6) {
        func_801015D0(actor);
        for (i = 4, unk_0 = B_80800FA0_chdinofamilysmall,
            unk_1 = B_80800F94_chdinofamilysmall;
             i != 0; i--, unk_0 -= 3, unk_1 -= 3) {
            func_800EE7F8(unk_0, unk_1);
            if (unk_0[0] != 0.0f && unk_0[1] != 0.0f && unk_0[2] != 0.0f) {
                func_800DF744(3, 1);
                func_800DF500(unk_0[0], unk_0[1], unk_0[2]);
                func_800DF410(160 - i * 30);
                func_800DF830(2);
                func_800DE498(gfx, actor->position, actor->rotation, actor->scale, 0,
                              func_800D674C(actor->unk0->unk14));
            }
        }
        func_800EE7F8(B_80800F70_chdinofamilysmall, (f32 *) &actor->actorData[4]);
        if (((f32 *) actor->actorData)[4] != 0.0f && ((f32 *) actor->actorData)[5] != 0.0f &&
            ((f32 *) actor->actorData)[6] != 0.0f) {
            func_800DF500(((f32 *) actor->actorData)[4], ((f32 *) actor->actorData)[5],
                          ((f32 *) actor->actorData)[6]);
        }
    }
    func_801018A4(actor, gfx);
    if (func_80100094(actor, 1)) {
        _sumumbofx_entrypoint_8(func_80100094(actor, 1), gfx);
    }
}

int chdinofamilysmall_entrypoint_0()
{
    return &D_80800F20_chdinofamilysmall;
}

extern void func_80105834();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
u32 D_80800E90_chdinofamilysmall[1] = {0x0};
u16 D_80800E94_chdinofamilysmall[10][4] = {0x0,   0x0, 0x40A0, 0x0,    0x14D, 0x1,  0x40A0, 0x0,
                                           0x14D, 0x1, 0x40A0, 0x0,    0x14D, 0x1,  0x40A0, 0x0,
                                           0x14D, 0x1, 0x40A0, 0x0,    0x14D, 0x1,  0x40A0, 0x0,
                                           0x14D, 0x1, 0x400C, 0xCCCD, 0x3F8, 0x41, 0x400C, 0xCCCD,
                                           0x3F8, 0x1, 0x400C, 0xCCCD, 0x3F8, 0x1,  0x400C, 0xCCCD};
static u32 D_80800E94_chdinofamilysmall_rest[1] = {0x3F80001};
u8 D_80800EE8_chdinofamilysmall[20] = {0x0,  0x13, 0x4, 0x1D, 0x0, 0xA,  0x0,  0x80, 0x0, 0x16,
                                       0x6D, 0x60, 0x0, 0x1,  0xB, 0xB8, 0x17, 0x70, 0x0, 0x0};
u8 D_80800EFC_chdinofamilysmall[20] = {0x0,  0x13, 0x4, 0x1E, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                                       0x6D, 0x60, 0x0, 0x1,  0xB, 0xB8, 0x17, 0x70, 0x0, 0x0};
u8 D_80800F10_chdinofamilysmall[16] = {0x43, 0x48, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0,
                                       0x43, 0x48, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0};
void *D_80800F20_chdinofamilysmall = (void *) 0x012A0292;
static u32 D_80800F20_chdinofamilysmall_rest[19] = {0x89A0002,
                                                    (u32) &D_80800E90_chdinofamilysmall,
                                                    (u32) func_80800090_chdinofamilysmall,
                                                    (u32) func_80105834,
                                                    (u32) func_80800C10_chdinofamilysmall,
                                                    0x13880000,
                                                    0x40000000,
                                                    0x0,
                                                    0x800100,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    (u32) func_80800000_chdinofamilysmall,
                                                    (u32) func_80107C2C,
                                                    (u32) ((u8 *) boot_thread_stack + 0xF26),
                                                    (u32) func_80800AF4_chdinofamilysmall,
                                                    0x0,
                                                    0x0,
                                                    0x0};
