#include "common.h"

// TU-NOTE: data tables below are defined in this TU after the code.
extern int D_80800D78_chflysaucercrate[];
typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[0x6C];
    u8 pad74 : 1;
    u8 flag : 1;
    u8 rest : 6;
} FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern u8 func_800C4350();
extern void func_800C31DC(u8, f32);
extern u8 D_80800DD0_chflysaucercrate[];
extern u8 D_80800CF0_chflysaucercrate[];
extern s32 D_80800DC0_chflysaucercrate[];
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} FSCState;
extern u8 D_80800D00_chflysaucercrate[];
extern u8 D_80800DE4_chflysaucercrate[];
extern u8 D_80800D0C_chflysaucercrate[];
extern u8 D_80800E04_chflysaucercrate[];
extern f32 func_800D8FF8(void);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8008FAC8(f32 *, f32, f32, f32);
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_80102B6C(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
void func_80800904_chflysaucercrate();
void func_80800A2C_chflysaucercrate();

int chflysaucercrate_entrypoint_0()
{
    return (int) &D_80800D78_chflysaucercrate;
}

// Switch the crate to a new state (state is stored in bits 10-15 of the halfword at 0x72).
void func_8080000C_chflysaucercrate(actor) u8 *actor;
{
    u32 state; // crate state
    func_80102424();
    state = (u16) (state = *(u16 *) (actor + 0x72));
    state = state >> 0xA;
    switch (state) {
        case 4:
            _subaddieDll_entrypoint_4(actor, 0);
            return;

        case 3:
            func_800DA544(0x91);
            return;

        case 5:
            func_800DA544(0x93);
            _capod_entrypoint_13(*(s32 *) actor, 0, 4, 0x2810);
            return;

        case 7:
            *(f32 *) (actor + 0x54) = 0.0f;
            *(f32 *) (actor + 0x50) = 0.0f;
            return;

        case 8:
            _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80800CF0_chflysaucercrate);
            func_800DA544(0x94);
            func_80108B04(actor, 0);
    }
}

// Message handler.
int func_808000E4_chflysaucercrate(Actor *actor, s32 msg, u32 arg)
{
    switch (msg) {
        case 0xB:
            switch (arg) {
                case 6:
                    if (func_800DA298(0x80)) {
                        _capod_entrypoint_14();
                        func_8080000C_chflysaucercrate(actor, 2);
                        _subaddieDll_entrypoint_4(actor, 1);
                        if (func_800DA298(0xB3)) {
                            _glcutDll_entrypoint_6(0xCA, 0x17);
                            _capod_entrypoint_13(actor->unk0, 0, 2, 0x2810);
                            return 4;
                        }
                        _capod_entrypoint_13(actor->unk0, 0, 0, 0x2010);
                        return 4;
                    }
                    return 3;
                case 12:
                    if (_glcutDll_entrypoint_19(0x23)) {
                        _glcutDll_entrypoint_17();
                    }
                    func_8080000C_chflysaucercrate(actor, 9);
                    return 3;
                case 4:
                    _glcutDll_entrypoint_17();
                    return 3;
                case 2:
                    _glcutDll_entrypoint_6(0xD6, 0x23);
                    break;
                case 0:
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    break;
            }
            return 3;
        case 0x2E:
            actor->unk74_30 = 0;
            break;
        case 0x3D:
            if (arg == 1) {
                func_800FFAB0(actor);
            }
            func_801084B0(0x2A2, &actor);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800DC0_chflysaucercrate,
                                         *(s32 *) ((u8 *) actor + 0x38));
            break;
        default:
            return 0;
    }
    return 1;
}

// Start a dialog.
void func_8080028C_chflysaucercrate(FarmerState *actor, s32 dialog_id, s32 flags)
{
    flags |= 4;
    _subaddiedialog_entrypoint_11(actor->f0, dialog_id, flags, &actor->f4, 0x41);
    actor->flag = 1;
}

void func_808002D8_chflysaucercrate(Actor *actor, f32 param_1)
{
    if (actor->unk5F == 0) {
        actor->unk5F = func_800C4350(0, actor->position, D_80800DD0_chflysaucercrate);
    } else {
        func_800C31DC(actor->unk5F, param_1);
        func_800C4350(actor->unk5F, actor->position, NULL);
    }
}

// Per-frame update; st: 1 wait for lift, 2 rise, 3 move to door, 4 wait at door, 5 fly on,
// 6 arrive in Witchyworld, 7 descend, 8 open, 9 fade out.
void func_80800348_chflysaucercrate(Actor *actor)
{
    if (((FSCState *) actor)->st < 8) {
        func_8008FAC8(actor->position, 115.0f, 175.0f, 115.0f);
        _sudeflect_entrypoint_1(actor->position, 170.0f, 0.0f, 160.0f, 4);
    }
    switch (((FSCState *) actor)->st) {
        case 1:
            if (!actor->unk74_30 && func_8010C9B0(actor->position, 0x15E) &&
                func_8008FA60(0x4001, 0) && !func_800DA298(0x80)) {
                if (!func_800DA9E4(0x90, 1)) {
                    func_8080028C_chflysaucercrate(actor, 0xF92, 8);
                } else if (func_80016B30(0, 1)) {
                    func_8080028C_chflysaucercrate(actor, 0xFA5, 0);
                }
            }
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             D_80800D00_chflysaucercrate,
                                             D_80800DE4_chflysaucercrate);
            return;
        case 2:
            func_80800904_chflysaucercrate(actor);
            if (actor->position[1] < 525.0f) {
                actor->position[1] += 250.0f * func_800D8FF8();
            } else {
                func_8080000C_chflysaucercrate(actor, 3);
            }
            func_808002D8_chflysaucercrate(
                actor, func_800F10B4(actor->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
            return;
        case 3:
            func_80800904_chflysaucercrate(actor);
            if (actor->position[0] < 4750.0f) {
                actor->position[0] += 375.0f * func_800D8FF8();
            } else if (func_800DA298(0xB3)) {
                func_8080000C_chflysaucercrate(actor, 5);
            } else {
                func_8080000C_chflysaucercrate(actor, 4);
            }
            func_808002D8_chflysaucercrate(
                actor, func_800F10B4(actor->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
            return;
        case 4:
            func_80800904_chflysaucercrate(actor);
            if (!actor->unk74_30 && func_8010C9B0(actor->position, 0x15E) &&
                func_8008FA60(0x4001, 0)) {
                if (!func_800DA9E4(0x92, 1)) {
                    func_8080028C_chflysaucercrate(actor, 0xF94, 8);
                } else if (func_80016B30(0, 1)) {
                    func_8080028C_chflysaucercrate(actor, 0xFA6, 0);
                }
            }
            func_808002D8_chflysaucercrate(
                actor, func_800F10B4(actor->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
            return;
        case 5:
            func_80800904_chflysaucercrate(actor);
            if (actor->position[0] < 6300.0f) {
                actor->position[0] += 375.0f * func_800D8FF8();
            }
            func_808002D8_chflysaucercrate(
                actor, func_800F10B4(actor->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
            return;
        case 6:
            actor->position[1] =
                func_800F10B4(actor->position[2], -4000.0f, -3500.0f, 1600.0f, 1800.0f);
            func_808002D8_chflysaucercrate(actor, 0.3f);
            func_80800904_chflysaucercrate(actor);
            if (actor->position[2] < -2900.0f) {
                actor->position[2] += 375.0f * func_800D8FF8();
                break;
            }
            func_8080000C_chflysaucercrate(actor, 7);
            return;
        case 7:
            func_80800A2C_chflysaucercrate(actor);
            if (1700.0f < actor->position[1]) {
                actor->position[1] -= 250.0f * func_800D8FF8();
            } else {
                actor->position[1] = 1700.0f;
                func_8080000C_chflysaucercrate(actor, 8);
            }
            func_808002D8_chflysaucercrate(
                actor, func_800F10B4(actor->position[1], 1700.0f, 1800.0f, 0.1f, 0.3f));
            return;
        case 8:
            func_80800A2C_chflysaucercrate(actor);
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             D_80800D0C_chflysaucercrate,
                                             D_80800E04_chflysaucercrate);
            func_80800A2C_chflysaucercrate(actor);
            if (func_80101E14(actor, 0.999f)) {
                func_8080000C_chflysaucercrate(actor, 9);
            }
            return;
        case 9:
            func_80800A2C_chflysaucercrate(actor);
            actor->unk58 += func_800D8FF8();
            if (1.5f < actor->unk58) {
                _subaddiefade_entrypoint_5(actor);
            }
            return;
        case 10:
            func_800FFAB0(actor);
    }
}

void func_80800904_chflysaucercrate(actor) Actor *actor;
{
    if (func_800DC0C0() < 0.2f) {
        actor->unk50 = func_800DC178(-10.0f, 10.0f);
    }
    func_80102B6C(actor, 1.0f);
    if (func_800DC0C0() < 0.2f) {
        actor->unk54 = func_800DC178(-10.0f, 10.0f);
    }
    func_80102B2C(actor, 1.0f);
    if (actor->rotation[2] < 10.0f) {
        actor->rotation[2] += func_800DC178(0.0f, 2.0f);
    }
    if (actor->rotation[2] > -10.0f) {
        actor->rotation[2] += func_800DC178(-2.0f, 0.0f);
    }
}

void func_80800A2C_chflysaucercrate(actor) void *actor;
{
    func_80102B2C(actor, 4.0f);
    func_80102B6C(actor, 4.0f);
    if (*(float *) ((char *) actor + 0x4c) != 0.0f) {
        *(float *) ((char *) actor + 0x4c) *= 0.8f;
    }
}

// Init: pick the starting state from the map and story flags.
void func_80800A88_chflysaucercrate(Actor *actor)
{
    s32 map_id;

    *(f32 *) ((char *) actor + 0x38) = 1.25f;
    map_id = func_800EA05C();
    switch (map_id) {
        case 0xCA:
            if (func_800DA298(0x93) != 0) {
                func_800FFAB0(actor);
                return;
            }
            if (func_800DA298(0x91) != 0) {
                *(f32 *) ((char *) actor + 4) = 4750.0f;
                *(f32 *) ((char *) actor + 8) = 525.0f;
                if (func_800DA298(0xB3) != 0) {
                    func_8080000C_chflysaucercrate(actor, 5);
                    return;
                }
                func_8080000C_chflysaucercrate(actor, 4);
            }
            return;
        case 0xD6:
            if (func_800DA298(0x94) != 0) {
                func_800FFAB0(actor);
                *(u8 *) ((char *) actor + 0x65) &= ~1;
                return;
            }
            if ((_glcutDll_entrypoint_19(0x23) != 0) || (func_800DA298(0x93) != 0)) {
                *(f32 *) ((char *) actor + 4) = -7800.0f;
                *(f32 *) ((char *) actor + 8) = 1600.0f;
                *(f32 *) ((char *) actor + 12) = -4500.0f;
                _subaddieDll_entrypoint_4(actor, 1);
                func_8080000C_chflysaucercrate(actor, 6);
                if (_glcutDll_entrypoint_19(0x23) != 0) {
                    _capod_entrypoint_13(*(s32 *) ((char *) actor + 0), 0, 0xC, 0x2810);
                    return;
                }
                _capod_entrypoint_13(*(s32 *) ((char *) actor + 0), 0, 0xC, 0x2010);
                return;
            }
            func_800FFAB0(actor);
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_80800CF0_chflysaucercrate[16] = {0x0,  0x13, 0x4,  0x48, 0x0, 0x18, 0x0, 0x1,
                                      0x13, 0x88, 0x27, 0x10, 0x0, 0x0,  0x0, 0x0};
u8 D_80800D00_chflysaucercrate[12] = {0x0,  0x13, 0x4,  0x48, 0x0, 0x19,
                                      0x17, 0x70, 0x1F, 0x40, 0x0, 0x0};
u8 D_80800D0C_chflysaucercrate[20] = {0x0, 0x13, 0x4, 0x47, 0x0,  0xD,  0x0,  0xE6, 0x1, 0x19,
                                      0x0, 0x18, 0x0, 0x1,  0x13, 0x88, 0x27, 0x10, 0x0, 0x0};
u32 D_80800D20_chflysaucercrate[22] = {
    0x0,        0x0,      0x3FC00000, 0x960009, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004,
    0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004,
    0x3FC00000, 0x94004A, 0x3FC00000, 0x940084, 0x3FC00000, 0x940084};
int D_80800D78_chflysaucercrate[18] = {0x20302A3,
                                       0x6910001,
                                       (u32) &D_80800D20_chflysaucercrate,
                                       (u32) func_80800348_chflysaucercrate,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x7D00000,
                                       0x40400000,
                                       0x0,
                                       0x80004,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800A88_chflysaucercrate,
                                       (u32) func_80107C2C,
                                       -0x7FFFFFFE,
                                       (u32) func_808000E4_chflysaucercrate,
                                       0x0};
s32 D_80800DC0_chflysaucercrate[4] = {0x43200000, 0x43340000, 0x43340000, 0x0};
u8 D_80800DD0_chflysaucercrate[20] = {0x2, 0x6, 0x0, 0x13, 0x4, 0xE0, 0x0, 0x16, 0x32, 0x0,
                                      0x0, 0x1, 0x0, 0xC8, 0x7, 0xD0, 0x0, 0x0,  0x0,  0x0};
u8 D_80800DE4_chflysaucercrate[32] = {
    0x0,  0x0,  0x0,  0x0,  0x3D, 0xCC, 0xCC, 0xCD, 0x3E, 0x80, 0x0, 0x0, 0x3E, 0xC2, 0x8F, 0x5C,
    0x3E, 0xEB, 0x85, 0x1F, 0x3F, 0x21, 0x47, 0xAE, 0x3F, 0x40, 0x0, 0x0, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800E04_chflysaucercrate[76] = {
    0x3E, 0x80, 0x0,  0x0,  0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xB3, 0x33, 0x33, 0x3E, 0xCC, 0xCC, 0xCD,
    0x3E, 0xE1, 0x47, 0xAE, 0x3E, 0xF3, 0x33, 0x33, 0x3F, 0x2,  0x8F, 0x5C, 0x3F, 0xF,  0x5C, 0x29,
    0x3F, 0x14, 0x7A, 0xE1, 0x3F, 0x1E, 0xB8, 0x52, 0x3F, 0x28, 0xF5, 0xC3, 0x3F, 0x35, 0xC2, 0x8F,
    0x3F, 0x42, 0x8F, 0x5C, 0x3F, 0x51, 0xEB, 0x85, 0x3F, 0x61, 0x47, 0xAE, 0x3F, 0x7A, 0xE1, 0x48,
    0xBF, 0x80, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
