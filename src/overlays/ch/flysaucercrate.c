#include "common.h"

extern int D_80800D78_chflysaucercrate[];
typedef struct { s32 f0; s32 f4; u8 pad[0x6C]; u8 pad74:1; u8 flag:1; u8 rest:6; } FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern u8 func_800C4350();
extern void func_800C31DC(u8, f32);
extern u8 D_80800DD0_chflysaucercrate[];
extern u8 D_80800CF0_chflysaucercrate[];
extern s32 D_80800DC0_chflysaucercrate[];
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } FSCState;
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
    return (int)&D_80800D78_chflysaucercrate;
}

void func_8080000C_chflysaucercrate(param_0) u8 *param_0;
{
  u32 temp_t7;
  func_80102424();
  temp_t7 = (u16) (temp_t7 = *((u16 *) (param_0 + 0x72)));
  temp_t7 = temp_t7 >> 0xA;
  switch (temp_t7)
  {
    case 4:
      _subaddieDll_entrypoint_4(param_0, 0);
      return;

    case 3:
      func_800DA544(0x91);
      return;

    case 5:
      func_800DA544(0x93);
      _capod_entrypoint_13(*((s32 *) param_0), 0, 4, 0x2810);
      return;

    case 7:
      *((f32 *) (param_0 + 0x54)) = 0.0f;
      *((f32 *) (param_0 + 0x50)) = 0.0f;
      return;

    case 8:
      _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80800CF0_chflysaucercrate);
      func_800DA544(0x94);
      func_80108B04(param_0, 0);

    default:
      return;

  }

}

int func_808000E4_chflysaucercrate(Actor *param_0, s32 param_1, u32 param_2)
{
    switch (param_1) {
        case 0xB:
            switch (param_2) {
                case 6:
                    if (func_800DA298(0x80)) {
                        _capod_entrypoint_14();
                        func_8080000C_chflysaucercrate(param_0, 2);
                        _subaddieDll_entrypoint_4(param_0, 1);
                        if (func_800DA298(0xB3)) {
                            _glcutDll_entrypoint_6(0xCA, 0x17);
                            _capod_entrypoint_13(param_0->unk0, 0, 2, 0x2810);
                            return 4;
                        }
                        _capod_entrypoint_13(param_0->unk0, 0, 0, 0x2010);
                        return 4;
                    }
                    return 3;
                case 12:
                    if (_glcutDll_entrypoint_19(0x23)) { _glcutDll_entrypoint_17(); }
                    func_8080000C_chflysaucercrate(param_0, 9);
                    return 3;
                case 4: _glcutDll_entrypoint_17(); return 3;
                case 2: _glcutDll_entrypoint_6(0xD6, 0x23); break;
                case 0: case 1: case 3: case 5: case 7: case 8: case 9: case 10: case 11: break;
            }
            return 3;
        case 0x2E: param_0->unk74_30 = 0; break;
        case 0x3D:
            if (param_2 == 1) { func_800FFAB0(param_0); }
            func_801084B0(0x2A2, &param_0);
            break;
        case 0x52: _gcdialogcamera_entrypoint_3(&D_80800DC0_chflysaucercrate, *(s32 *)((u8 *)param_0 + 0x38)); break;
        default: return 0;
    }
    return 1;
}

void func_8080028C_chflysaucercrate(FarmerState *param_0, s32 param_1, s32 param_2) {
    param_2 |= 4;
    _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, &param_0->f4, 0x41);
    param_0->flag = 1;
}

void func_808002D8_chflysaucercrate(Actor *param_0, f32 param_1)
{
    if (param_0->unk5F == 0) {
        param_0->unk5F = func_800C4350(0, param_0->position, D_80800DD0_chflysaucercrate);
    } else {
        func_800C31DC(param_0->unk5F, param_1);
        func_800C4350(param_0->unk5F, param_0->position, NULL);
    }
}

void func_80800348_chflysaucercrate(Actor *param_0)
{
    if (((FSCState *)param_0)->st < 8) {
        func_8008FAC8(param_0->position, 115.0f, 175.0f, 115.0f);
        _sudeflect_entrypoint_1(param_0->position, 170.0f, 0.0f, 160.0f, 4);
    }
    switch (((FSCState *)param_0)->st) {
    case 1:
        if (!param_0->unk74_30 && func_8010C9B0(param_0->position, 0x15E) && func_8008FA60(0x4001, 0) && !func_800DA298(0x80)) {
            if (!func_800DA9E4(0x90, 1)) {
                func_8080028C_chflysaucercrate(param_0, 0xF92, 8);
            } else if (func_80016B30(0, 1)) {
                func_8080028C_chflysaucercrate(param_0, 0xFA5, 0);
            }
        }
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80800D00_chflysaucercrate, D_80800DE4_chflysaucercrate);
        return;
    case 2:
        func_80800904_chflysaucercrate(param_0);
        if (param_0->position[1] < 525.0f) {
            param_0->position[1] += 250.0f * func_800D8FF8();
        } else {
            func_8080000C_chflysaucercrate(param_0, 3);
        }
        func_808002D8_chflysaucercrate(param_0, func_800F10B4(param_0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        return;
    case 3:
        func_80800904_chflysaucercrate(param_0);
        if (param_0->position[0] < 4750.0f) {
            param_0->position[0] += 375.0f * func_800D8FF8();
        } else if (func_800DA298(0xB3)) {
            func_8080000C_chflysaucercrate(param_0, 5);
        } else {
            func_8080000C_chflysaucercrate(param_0, 4);
        }
        func_808002D8_chflysaucercrate(param_0, func_800F10B4(param_0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        return;
    case 4:
        func_80800904_chflysaucercrate(param_0);
        if (!param_0->unk74_30 && func_8010C9B0(param_0->position, 0x15E) && func_8008FA60(0x4001, 0)) {
            if (!func_800DA9E4(0x92, 1)) {
                func_8080028C_chflysaucercrate(param_0, 0xF94, 8);
            } else if (func_80016B30(0, 1)) {
                func_8080028C_chflysaucercrate(param_0, 0xFA6, 0);
            }
        }
        func_808002D8_chflysaucercrate(param_0, func_800F10B4(param_0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        return;
    case 5:
        func_80800904_chflysaucercrate(param_0);
        if (param_0->position[0] < 6300.0f) {
            param_0->position[0] += 375.0f * func_800D8FF8();
        }
        func_808002D8_chflysaucercrate(param_0, func_800F10B4(param_0->position[1], 478.0f, 525.0f, 0.1f, 0.3f));
        return;
    case 6:
        param_0->position[1] = func_800F10B4(param_0->position[2], -4000.0f, -3500.0f, 1600.0f, 1800.0f);
        func_808002D8_chflysaucercrate(param_0, 0.3f);
        func_80800904_chflysaucercrate(param_0);
        if (param_0->position[2] < -2900.0f) {
            param_0->position[2] += 375.0f * func_800D8FF8();
            break;
        }
        func_8080000C_chflysaucercrate(param_0, 7);
        return;
    case 7:
        func_80800A2C_chflysaucercrate(param_0);
        if (1700.0f < param_0->position[1]) {
            param_0->position[1] -= 250.0f * func_800D8FF8();
        } else {
            param_0->position[1] = 1700.0f;
            func_8080000C_chflysaucercrate(param_0, 8);
        }
        func_808002D8_chflysaucercrate(param_0, func_800F10B4(param_0->position[1], 1700.0f, 1800.0f, 0.1f, 0.3f));
        return;
    case 8:
        func_80800A2C_chflysaucercrate(param_0);
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80800D0C_chflysaucercrate, D_80800E04_chflysaucercrate);
        func_80800A2C_chflysaucercrate(param_0);
        if (func_80101E14(param_0, 0.999f)) {
            func_8080000C_chflysaucercrate(param_0, 9);
        }
        return;
    case 9:
        func_80800A2C_chflysaucercrate(param_0);
        param_0->unk58 += func_800D8FF8();
        if (1.5f < param_0->unk58) {
            _subaddiefade_entrypoint_5(param_0);
        }
        return;
    case 10:
        func_800FFAB0(param_0);
        break;
    }
}

void func_80800904_chflysaucercrate(param_0) Actor *param_0;
{
    if (func_800DC0C0() < 0.2f) {
        param_0->unk50 = func_800DC178(-10.0f, 10.0f);
    }
    func_80102B6C(param_0, 1.0f);
    if (func_800DC0C0() < 0.2f) {
        param_0->unk54 = func_800DC178(-10.0f, 10.0f);
    }
    func_80102B2C(param_0, 1.0f);
    if (param_0->rotation[2] < 10.0f) {
        param_0->rotation[2] += func_800DC178(0.0f, 2.0f);
    }
    if (param_0->rotation[2] > -10.0f) {
        param_0->rotation[2] += func_800DC178(-2.0f, 0.0f);
    }
}

void func_80800A2C_chflysaucercrate(param_0) void *param_0;
{
    func_80102B2C(param_0, 4.0f);
    func_80102B6C(param_0, 4.0f);
    if (*(float *)((char *)param_0 + 0x4c) != 0.0f)
    {
        *(float *)((char *)param_0 + 0x4c) *= 0.8f;
    }
}

void func_80800A88_chflysaucercrate(Actor *param_0) {
    s32 local_0;

    *(f32 *)((char *)param_0 + 0x38) = 1.25f;
    local_0 = func_800EA05C();
    switch (local_0) {
    case 0xCA:
        if (func_800DA298(0x93) != 0) {
            func_800FFAB0(param_0);
            return;
        }
        if (func_800DA298(0x91) != 0) {
            *(f32 *)((char *)param_0 + 4) = 4750.0f;
            *(f32 *)((char *)param_0 + 8) = 525.0f;
            if (func_800DA298(0xB3) != 0) {
                func_8080000C_chflysaucercrate(param_0, 5);
                return;
            }
            func_8080000C_chflysaucercrate(param_0, 4);
            return;
        }
        return;
    case 0xD6:
        if (func_800DA298(0x94) != 0) {
            func_800FFAB0(param_0);
            *(u8 *)((char *)param_0 + 0x65) &= ~1;
            return;
        }
        if ((_glcutDll_entrypoint_19(0x23) != 0) || (func_800DA298(0x93) != 0)) {
            *(f32 *)((char *)param_0 + 4) = -7800.0f;
            *(f32 *)((char *)param_0 + 8) = 1600.0f;
            *(f32 *)((char *)param_0 + 12) = -4500.0f;
            _subaddieDll_entrypoint_4(param_0, 1);
            func_8080000C_chflysaucercrate(param_0, 6);
            if (_glcutDll_entrypoint_19(0x23) != 0) {
                _capod_entrypoint_13(*(s32 *)((char *)param_0 + 0), 0, 0xC, 0x2810);
                return;
            }
            _capod_entrypoint_13(*(s32 *)((char *)param_0 + 0), 0, 0xC, 0x2010);
            return;
        }
        func_800FFAB0(param_0);
        break;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/flysaucercrate.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800D78_chflysaucercrate -> int[], D_80800DC0_chflysaucercrate -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_80800CF0_chflysaucercrate[16] = { 0x0, 0x13, 0x4, 0x48, 0x0, 0x18, 0x0, 0x1, 0x13, 0x88, 0x27, 0x10, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800D00_chflysaucercrate[12] = { 0x0, 0x13, 0x4, 0x48, 0x0, 0x19, 0x17, 0x70, 0x1F, 0x40, 0x0, 0x0 };
u8 D_80800D0C_chflysaucercrate[20] = { 0x0, 0x13, 0x4, 0x47, 0x0, 0xD, 0x0, 0xE6, 0x1, 0x19, 0x0, 0x18, 0x0, 0x1, 0x13, 0x88, 0x27, 0x10, 0x0, 0x0 };
u32 D_80800D20_chflysaucercrate[22] = { 0x0, 0x0, 0x3FC00000, 0x960009, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x960004, 0x3FC00000, 0x94004A, 0x3FC00000, 0x940084, 0x3FC00000, 0x940084 };
int D_80800D78_chflysaucercrate[18] = { 0x20302A3, 0x6910001, (u32)&D_80800D20_chflysaucercrate, (u32)func_80800348_chflysaucercrate, (u32)func_80105834, (u32)func_80101870, 0x7D00000, 0x40400000, 0x0, 0x80004, 0x0, 0x0, 0x0, (u32)func_80800A88_chflysaucercrate, (u32)func_80107C2C, -0x7FFFFFFE, (u32)func_808000E4_chflysaucercrate, 0x0 };
s32 D_80800DC0_chflysaucercrate[4] = { 0x43200000, 0x43340000, 0x43340000, 0x0 };
u8 D_80800DD0_chflysaucercrate[20] = { 0x2, 0x6, 0x0, 0x13, 0x4, 0xE0, 0x0, 0x16, 0x32, 0x0, 0x0, 0x1, 0x0, 0xC8, 0x7, 0xD0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800DE4_chflysaucercrate[32] = { 0x0, 0x0, 0x0, 0x0, 0x3D, 0xCC, 0xCC, 0xCD, 0x3E, 0x80, 0x0, 0x0, 0x3E, 0xC2, 0x8F, 0x5C, 0x3E, 0xEB, 0x85, 0x1F, 0x3F, 0x21, 0x47, 0xAE, 0x3F, 0x40, 0x0, 0x0, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80800E04_chflysaucercrate[76] = { 0x3E, 0x80, 0x0, 0x0, 0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xB3, 0x33, 0x33, 0x3E, 0xCC, 0xCC, 0xCD, 0x3E, 0xE1, 0x47, 0xAE, 0x3E, 0xF3, 0x33, 0x33, 0x3F, 0x2, 0x8F, 0x5C, 0x3F, 0xF, 0x5C, 0x29, 0x3F, 0x14, 0x7A, 0xE1, 0x3F, 0x1E, 0xB8, 0x52, 0x3F, 0x28, 0xF5, 0xC3, 0x3F, 0x35, 0xC2, 0x8F, 0x3F, 0x42, 0x8F, 0x5C, 0x3F, 0x51, 0xEB, 0x85, 0x3F, 0x61, 0x47, 0xAE, 0x3F, 0x7A, 0xE1, 0x48, 0xBF, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
