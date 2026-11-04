#include "common.h"

extern int D_80800788_chgobihailfire[];
extern int D_808007D0_chgobihailfire[];
extern void func_80101EE4(Actor *, f32);
extern u8 D_80800818_chgobihailfire[];
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void func_801056EC(Actor *, f32);
extern void func_80102424(Actor *, s32);
extern s32 func_800D9078(f32 *);
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
extern void _glcutDll_entrypoint_24(u32, u32, u32);
extern void _glcutDll_entrypoint_6(u32, u32);
int func_80800538_chgobihailfire();

int chgobihailfire_entrypoint_0()
{
    return (int) &D_80800788_chgobihailfire;
}

int *chgobihailfire_entrypoint_1()
{
    return &D_808007D0_chgobihailfire;
}

void func_80800018_chgobihailfire(u8 *actor)
{
    if (_glcutDll_entrypoint_20() != 0) {
        if (func_800EA05C() != 0x129) {
            func_800FFAB0(actor);
        }
        func_80102424(actor, 4);
        func_8010573C(actor, 0x3F800000);
        goto block_6;
    }
    if (func_800DA298(0x97) == 0) {
        func_800FFAB0(actor);
        return;
    }
block_6:
    func_80105A9C(actor, 0x43FA0000);

    func_80102FDC(actor, 0.25f);
    *(u8 *) ((char *) actor + 0x95) = (u8) ((*(u8 *) ((char *) actor + 0x95) & 0xFFFFu) | 1);
}

void func_808000C8_chgobihailfire(Actor *actor)
{
    _chgobicommon_entrypoint_0(actor);
    switch (actor->unk70_10) {
        case 1:
            if (func_800D9078(&actor->unk58)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x126E, 4, 0, 0x38);
            }
            if (actor->unk58 == 0.0f) {
                func_80105834(actor);
                if (func_80105A5C(actor)) {
                    func_800FFAB0(actor);
                    if (actor->unk64_20)
                        _glcutDll_entrypoint_24(0x129, 0xEA, 0x47);
                    else
                        _glcutDll_entrypoint_6(0x129, 0x47);
                }
            }
            break;
        case 2:
            func_80105834(actor);
            if (func_80105A5C(actor)) {
                func_800DA544(0x1C6);
                func_80102424(actor, 3);
            }
            break;
        case 5:
            if (_plsu_entrypoint_3(actor->unk0) != -1 && actor->unk64_19) {
                if (!actor->unk74_30) {
                    actor->unk74_30 = 1;
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x12C3, 4, actor->position,
                                                  0x38);
                }
                func_80102424(actor, 6);
                actor->unk58 = 0.6f;
            }
            break;
        case 6:
            if (_plsu_entrypoint_3(actor->unk0) == -1 || !actor->unk64_19) {
                if (func_800D9078(&actor->unk58))
                    func_80102424(actor, 5);
            } else {
                actor->unk58 = 0.6f;
            }
            break;
        case 7:
            if (func_80101DDC(actor)) {
                func_800FFA88(actor->unk3C);
                actor->unk3C = 0;
                func_80102424(actor, 5);
            }
            break;
        case 8:
            if (func_80101DDC(actor))
                func_80102424(actor, 5);
    }
    _chbadshad_entrypoint_2(actor, 1, actor->scale * 2.4f, 0);
    actor->unk64_19 = 0;
}

s32 func_8080032C_chgobihailfire(Actor *actor, s32 msg, s32 msg_arg)
{
    Actor *spawned;

    switch (msg) {
        case 0x49:
            return func_80800538_chgobihailfire(actor, msg_arg);
        case 0x3E:
            // Player jumped on Gobi's back: spit water into Chuffy's boiler.
            actor->unk64_19 = 1;
            if (func_8008FCC8(actor->unk0) == 1) {
                if (!func_800DA298(0x171) && func_800DA298(0x4F2)) {
                    if (actor->unk70_10 != 7) {
                        func_80090658(1);
                        _capod_entrypoint_13(actor->unk0, 0, 0x11, 0);
                        if (func_800C064C() == 0x12C3) {
                            func_800C067C(0x12C3);
                        }
                        _subaddiedialog_entrypoint_11(actor->unk0, 0x12C4, 4, actor->position,
                                                      0x38);
                        _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                         D_80800818_chgobihailfire);
                        func_80102424(actor, 7);
                        func_80108B04(actor, 0);
                        func_8010A570(actor);
                        func_800DA544(0x171);
                    }
                } else if (actor->unk70_10 != 8) {
                    func_80102424(actor, 8);
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800818_chgobihailfire);
                }
            }
            break;
        case 0xB:
            if (msg_arg == 0x11) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x12C6, 0x44, actor->position, 0x42);
                func_80090658(0);
                func_8010A590(actor);
            }
            return 3;
        case 0x3D:
            spawned = func_801084B0(0x500, &actor);
            func_80102FDC(spawned, actor->scale);
            actor->unk3C = spawned->unk0;
            func_80101EE4(actor, 0.0f);
    }
    return 0;
}

int func_80800538_chgobihailfire(actor, unk_1)
Actor *actor;
s32 unk_1;
{
    s32 cut_active;
    s32 unk_0;
    s32 can_appear;
    unk_0 = func_800DA298(0x1C6);
    cut_active = _glcutDll_entrypoint_19(0x47);
    switch (func_800EA05C()) {
        case 0x127:
            can_appear = func_800DA298(0x97) && !unk_0 && !func_800DB9B0();
            if (_glcutDll_entrypoint_20()) {
                func_800FFAB0(actor);
                return 0;
            }
            func_80102424(actor, 1);
            if (cut_active)
                actor->unk64_20 = 1;
            else
                actor->unk64_20 = 0;
            if (cut_active || can_appear) {
                s32 shot = 0x830;
                if (cut_active)
                    shot = 0x2830;
                actor->unk58 = 5.0f;
                _capod_entrypoint_13(actor->unk0, 0, 0, shot);
                return 1;
            }
            func_800FFAB0(actor);
            return 0;
        case 0x129:
            if (_glcutDll_entrypoint_20())
                return 0;
            if (cut_active) {
                func_80102424(actor, 2);
                func_801056EC(actor, 0.0f);
                _capod_entrypoint_13(actor->unk0, 0, 1, 0x2900);
                return 1;
            }
            if (unk_0) {
                func_80102424(actor, 5);
                func_801056EC(actor, 1.0f);
                func_80104E78(actor);
            } else
                func_800FFAB0(actor);
    }
    return 0;
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of
// this file; IDO schedules some of them differently unless the tables are in the same unit.
// The extern declarations of D_80800788 and D_808007D0 are adjusted to the object (same addresses).
extern void func_80102EC0();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800730_chgobihailfire[18] = {0x0,        0x0,        0x3F07AE14, 0x2230001,  0x3F07AE14,
                                     0x2230001,  0x40900000, 0x2220001,  0x40900000, 0x2220001,
                                     0x40A3D70A, 0x49A0001,  0x3F19999A, 0x49C0002,  0x4057AE14,
                                     0x49D0002,  0x3F19999A, 0x49C0002};
u32 D_80800778_chgobihailfire[4] = {0x0, 0x0, 0x4057AE14, 0x4A00002};
int D_80800788_chgobihailfire[18] = {0x18803E3,
                                     0x7880001,
                                     (u32) &D_80800730_chgobihailfire,
                                     (u32) func_80102EC0,
                                     (u32) func_808000C8_chgobihailfire,
                                     (u32) func_80101870,
                                     0x0,
                                     0x4119999A,
                                     0x0,
                                     0x4004092C,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800018_chgobihailfire,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBF0,
                                     (u32) func_8080032C_chgobihailfire,
                                     0x0};
int D_808007D0_chgobihailfire[18] = {0x1580500,
                                     0x9120001,
                                     (u32) &D_80800778_chgobihailfire,
                                     (u32) func_80102EC0,
                                     (u32) func_80102EC0,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0xC,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFF7FE,
                                     0x0,
                                     0x0};
u8 D_80800818_chgobihailfire[24] = {0x0, 0x13, 0x4, 0xCA, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x0,
                                    0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
