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
    return (int)&D_80800788_chgobihailfire;
}

int *chgobihailfire_entrypoint_1()
{
    return &D_808007D0_chgobihailfire;
}

void func_80800018_chgobihailfire(u8 *param_0)
{
  if (_glcutDll_entrypoint_20() != 0)
  {
    if (func_800EA05C() != 0x129)
    {
      func_800FFAB0(param_0);
    }
    func_80102424(param_0, 4);
    func_8010573C(param_0, 0x3F800000);
    goto block_6;
  }
  if (func_800DA298(0x97) == 0)
  {
    func_800FFAB0(param_0);
    return;
  }
  block_6:
  func_80105A9C(param_0, 0x43FA0000);

  func_80102FDC(param_0, 0.25f);
  *((u8 *) (((char *) param_0) + 0x95)) = (u8) (((*((u8 *) (((char *) param_0) + 0x95))) & 0xFFFFu) | 1);
}

void func_808000C8_chgobihailfire(Actor *param_0)
{
    _chgobicommon_entrypoint_0(param_0);
    switch (param_0->unk70_10) {
    case 1:
        if (func_800D9078(&param_0->unk58)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x126E, 4, 0, 0x38);
        }
        if (param_0->unk58 == 0.0f) {
            func_80105834(param_0);
            if (func_80105A5C(param_0)) {
                func_800FFAB0(param_0);
                if (param_0->unk64_20) _glcutDll_entrypoint_24(0x129, 0xEA, 0x47);
                else _glcutDll_entrypoint_6(0x129, 0x47);
            }
        }
        break;
    case 2:
        func_80105834(param_0);
        if (func_80105A5C(param_0)) {
            func_800DA544(0x1C6);
            func_80102424(param_0, 3);
        }
        break;
    case 5:
        if (_plsu_entrypoint_3(param_0->unk0) != -1 && param_0->unk64_19) {
            if (!param_0->unk74_30) {
                param_0->unk74_30 = 1;
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x12C3, 4, param_0->position, 0x38);
            }
            func_80102424(param_0, 6);
            param_0->unk58 = 0.6f;
        }
        break;
    case 6:
        if (_plsu_entrypoint_3(param_0->unk0) == -1 || !param_0->unk64_19) {
            if (func_800D9078(&param_0->unk58)) func_80102424(param_0, 5);
        } else {
            param_0->unk58 = 0.6f;
        }
        break;
    case 7:
        if (func_80101DDC(param_0)) {
            func_800FFA88(param_0->unk3C);
            param_0->unk3C = 0;
            func_80102424(param_0, 5);
        }
        break;
    case 8:
        if (func_80101DDC(param_0)) func_80102424(param_0, 5);
        break;
    }
    _chbadshad_entrypoint_2(param_0, 1, param_0->scale * 2.4f, 0);
    param_0->unk64_19 = 0;
}

s32 func_8080032C_chgobihailfire(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    switch (param_1) {
    case 0x49:
        return func_80800538_chgobihailfire(param_0, param_2);
    case 0x3E:
        param_0->unk64_19 = 1;
        if (func_8008FCC8(param_0->unk0) == 1) {
            if (!func_800DA298(0x171) && func_800DA298(0x4F2)) {
                if (param_0->unk70_10 != 7) {
                    func_80090658(1);
                    _capod_entrypoint_13(param_0->unk0, 0, 0x11, 0);
                    if (func_800C064C() == 0x12C3) {
                        func_800C067C(0x12C3);
                    }
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x12C4, 4, param_0->position, 0x38);
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800818_chgobihailfire);
                    func_80102424(param_0, 7);
                    func_80108B04(param_0, 0);
                    func_8010A570(param_0);
                    func_800DA544(0x171);
                }
            } else if (param_0->unk70_10 != 8) {
                func_80102424(param_0, 8);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800818_chgobihailfire);
            }
        }
        break;
    case 0xB:
        if (param_2 == 0x11) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x12C6, 0x44, param_0->position, 0x42);
            func_80090658(0);
            func_8010A590(param_0);
        }
        return 3;
    case 0x3D:
        local_0 = func_801084B0(0x500, &param_0);
        func_80102FDC(local_0, param_0->scale);
        param_0->unk3C = local_0->unk0;
        func_80101EE4(param_0, 0.0f);
        break;
    }
    return 0;
}

int func_80800538_chgobihailfire(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_1;
    s32 local_0;
    s32 local_2;
    local_0 = func_800DA298(0x1C6);
    local_1 = _glcutDll_entrypoint_19(0x47);
    switch (func_800EA05C()) {
    case 0x127:
        local_2 = func_800DA298(0x97) && !local_0 && !func_800DB9B0();
        if (_glcutDll_entrypoint_20()) { func_800FFAB0(param_0); return 0; }
        func_80102424(param_0, 1);
        if (local_1) param_0->unk64_20 = 1;
        else param_0->unk64_20 = 0;
        if (local_1 || local_2) {
            s32 local_3 = 0x830;
            if (local_1) local_3 = 0x2830;
            param_0->unk58 = 5.0f;
            _capod_entrypoint_13(param_0->unk0, 0, 0, local_3);
            return 1;
        }
        func_800FFAB0(param_0);
        return 0;
    case 0x129:
        if (_glcutDll_entrypoint_20()) return 0;
        if (local_1) {
            func_80102424(param_0, 2);
            func_801056EC(param_0, 0.0f);
            _capod_entrypoint_13(param_0->unk0, 0, 1, 0x2900);
            return 1;
        }
        if (local_0) { func_80102424(param_0, 5); func_801056EC(param_0, 1.0f); func_80104E78(param_0); }
        else func_800FFAB0(param_0);
        break;
    default: break;
    }
    return 0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/gobi/hailfire.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800788_chgobihailfire -> int[], D_808007D0_chgobihailfire -> int[] */
extern void func_80102EC0();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800730_chgobihailfire[18] = { 0x0, 0x0, 0x3F07AE14, 0x2230001, 0x3F07AE14, 0x2230001, 0x40900000, 0x2220001, 0x40900000, 0x2220001, 0x40A3D70A, 0x49A0001, 0x3F19999A, 0x49C0002, 0x4057AE14, 0x49D0002, 0x3F19999A, 0x49C0002 };
u32 D_80800778_chgobihailfire[4] = { 0x0, 0x0, 0x4057AE14, 0x4A00002 };
int D_80800788_chgobihailfire[18] = { 0x18803E3, 0x7880001, (u32)&D_80800730_chgobihailfire, (u32)func_80102EC0, (u32)func_808000C8_chgobihailfire, (u32)func_80101870, 0x0, 0x4119999A, 0x0, 0x4004092C, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800018_chgobihailfire, (u32)func_80107C2C, -0x7FFFFBF0, (u32)func_8080032C_chgobihailfire, 0x0 };
int D_808007D0_chgobihailfire[18] = { 0x1580500, 0x9120001, (u32)&D_80800778_chgobihailfire, (u32)func_80102EC0, (u32)func_80102EC0, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFF7FE, 0x0, 0x0 };
u8 D_80800818_chgobihailfire[24] = { 0x0, 0x13, 0x4, 0xCA, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
