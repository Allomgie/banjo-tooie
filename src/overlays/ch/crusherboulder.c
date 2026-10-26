#include "common.h"

extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern Vec3f D_80801388_chcrusherboulder;
extern Vec3f D_80801394_chcrusherboulder;
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, f32 *);
extern void func_80105A9C(Actor *, f32);
extern f32 func_800DC178(f32, f32);
typedef struct { u8 pad[0x74]; u32 pad74:2; u32 flag:1; u32 rest:29; } CrushS;
extern void _sudeflect_entrypoint_0(u8 *, f32, f32, s32);
extern s32 D_80801470_chcrusherboulder;
extern void *D_80801464_chcrusherboulder;
extern void func_800BBCB8(void *param_0, int param_1, float param_2, int param_3, s32 *param_4);
extern s32 D_808014BC_chcrusherboulder;
extern int D_808014EC_chcrusherboulder;
extern f32 D_808013A0_chcrusherboulder[];
extern s32 func_80100094(Actor *, s32);
extern f32 func_800D8FF8(void);
extern s32 func_800DA298(s32);
extern void func_800DA544(s32);
extern f32 _sumumbofx_entrypoint_22(s32);
extern void _sumumbofx_entrypoint_1(Actor *, s32);
extern void func_8010A800(Actor *, s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern f32 func_800DC0C0(void);
extern u8 _subaddieaudioloop_entrypoint_7();
extern void func_800187B4(s32, f32, f32, f32);
extern f32 D_808013B4_chcrusherboulder[];
extern f32 D_808013C0_chcrusherboulder[];
extern f32 D_808013C8_chcrusherboulder[];
extern f32 D_80801360_chcrusherboulder[];
extern f32 D_808013D4_chcrusherboulder[];
extern f32 D_80801374_chcrusherboulder[];
extern void func_80101FDC(Actor *, s32);
extern s32 _chmumbopad_entrypoint_0(s32);
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
extern void _sumumbofx_entrypoint_2(s32);
extern void _sumumbofx_entrypoint_3(s32, f32);
extern void _sumumbofx_entrypoint_4(s32);
extern void _sumumbofx_entrypoint_12(s32, f32 *, f32 *, f32 *);
extern void _sumumbofx_entrypoint_15(s32, f32);
extern void _sumumbofx_entrypoint_16(s32, f32);
extern void _sumumbofx_entrypoint_24(s32, f32);
extern void _sumumbofx_entrypoint_25(s32, s32, f32 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern u8 _subaddieaudioloop_entrypoint_3();
extern void func_80101180(s32, s32, s32);
extern Vec3f D_808013E0_chcrusherboulder;
extern u8 D_808013EC_chcrusherboulder[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 D_808013FC_chcrusherboulder[];
extern s32 D_8080143C_chcrusherboulder[];
extern s32 D_80801450_chcrusherboulder[];
void func_80800338_chcrusherboulder();
void func_8080087C_chcrusherboulder();
void func_80800A1C_chcrusherboulder();
void func_80800F38_chcrusherboulder();
void func_80801064_chcrusherboulder();

void func_80800000_chcrusherboulder(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    void *local_2;
    s32 local_3;
    f32 *local_4;

    local_2 = func_80100094(param_0, 1);
    local_1[0] = -param_0->rotation[0];
    local_1[1] = param_0->rotation[1];
    local_1[2] = param_0->rotation[2];
    if (local_2) {
        local_3 = _sumumbofx_entrypoint_10(local_2);
        func_800DF5D8(local_3, 255, local_3, 255);
    }
    local_4 = param_0->position;
    func_800EE7F8(local_0, local_4);
    func_800EF5A0(local_4, local_1, 0.0f, 150.0f, 0.0f);
    func_800EF04C(local_4, local_0);
    param_0->position[1] -= 150.0f;
    if (local_2) {
        _sumumbofx_entrypoint_9(local_2, param_1);
    }
    func_80101870(param_0, param_1);
    func_800EE7F8(local_4, local_0);
    if (local_2) {
        _sumumbofx_entrypoint_8(local_2, param_1);
    }
}

void func_80800100_chcrusherboulder(void *param_0, f32 *param_1)
{
    Vec3f local_0;
    Vec3f local_1;

    local_0 = D_80801388_chcrusherboulder;
    local_1 = D_80801394_chcrusherboulder;
    _sumumbofx_entrypoint_7(param_0, 225.0f, 0, 25, param_1, local_1.f, local_0.f);
    _sumumbofx_entrypoint_14(param_0);
    param_1[1] += 300.0f;
    _sumumbofx_entrypoint_11(param_0, param_1);
    param_1[1] -= 300.0f;
}

int func_808001CC_chcrusherboulder(s32 param_0)
{
  s32 local_0;
  local_0 = func_80100094(param_0, 1);
  _sumumbofx_entrypoint_5(local_0 | 0, 0x40400000);
  func_80800100_chcrusherboulder(local_0, param_0 + 4);
}

void func_80800210_chcrusherboulder(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    if (param_0->unk58 < 20.0f) {
        func_800EE7F8(local_0, param_0->rotation);
        func_80105A9C(param_0, 80.0f);
        func_80105834(param_0);
        func_800EE7F8(param_0->rotation, local_0);
    }
    for (local_1 = 0; local_1 < 3; local_1++) {
        param_0->rotation[local_1] += func_800DC178(-0.25f, 0.25f);
        param_0->rotation[local_1] = param_0->rotation[local_1] < -10.0f ? -10.0f :
            (param_0->rotation[local_1] > 10.0f ? 10.0f : param_0->rotation[local_1]);
    }
}

void func_80800338_chcrusherboulder(param_0) Actor *param_0;
{
    s32 local_0;
    u8 local_2;

    local_0 = func_80100094(param_0, 1);
    switch (param_0->unk70_10) {
    case 2:
        func_80800100_chcrusherboulder(local_0, param_0->position);
        if (5.0f < param_0->position[1]) {
            param_0->position[1] -= 210.0f * func_800D8FF8();
        } else {
            param_0->unk64_20 = 0;
            param_0->unk58 = 0.0f;
            func_80800A1C_chcrusherboulder(param_0, 3);
        }
        break;
    case 3:
        func_80800100_chcrusherboulder(local_0, param_0->position);
        param_0->position[1] = 15.0f;
        *(f32 *)&param_0->actorData[7] = 0.0f;
        if (func_800DA298(0x4FB)) {
            func_80800A1C_chcrusherboulder(param_0, 5);
        } else {
            func_80800A1C_chcrusherboulder(param_0, 4);
        }
        func_800DA544(0x4FD);
        func_800DA544(0x9DF);
        break;
    case 4:
        func_80800100_chcrusherboulder(local_0, param_0->position);
        if (_sumumbofx_entrypoint_22(local_0) <= 0.02f) {
            _sumumbofx_entrypoint_1(param_0, 1);
            func_8010A800(param_0, 0);
            func_80800A1C_chcrusherboulder(param_0, 6);
        }
        break;
    case 6:
        if (func_800DA298(0x4FB)) {
            _capod_entrypoint_13(param_0->unk0, 0, 4, 0x4030);
            func_80800A1C_chcrusherboulder(param_0, 7);
        }
        break;
    case 5:
        func_80800100_chcrusherboulder(local_0, param_0->position);
        if (_sumumbofx_entrypoint_22(local_0) <= 0.02f) {
            _sumumbofx_entrypoint_1(param_0, 1);
            func_8010A800(param_0, 0);
            func_80800A1C_chcrusherboulder(param_0, 7);
        }
    case 7:
        if (param_0->position[0] < -2850.0f) {
            func_80800A1C_chcrusherboulder(param_0, 12);
        }
        if (param_0->position[0] < -1900.0f) {
            if (-2350.0f < param_0->position[0]) {
                if (*(f32 *)&param_0->actorData[7] < 500.0f) {
                    *(f32 *)&param_0->actorData[7] += 2.0f;
                }
            } else if (0.0f < *(f32 *)&param_0->actorData[7]) {
                *(f32 *)&param_0->actorData[7] -= 2.0f;
            }
            if (-325.0f < param_0->position[2]) {
                if (func_800DC0C0() < 0.4f) {
                    param_0->position[2] -= func_800DC178(4.0f, 8.0f);
                    param_0->rotation[2] = -func_800DC178(2.0f, 8.0f);
                }
            }
            if (param_0->position[2] < -375.0f) {
                if (func_800DC0C0() < 0.4f) {
                    param_0->position[2] += func_800DC178(4.0f, 8.0f);
                    param_0->rotation[2] = func_800DC178(2.0f, 8.0f);
                }
            }
            if (param_0->unk74_30) {
                param_0->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.2f, 0.3f);
                local_2 = _subaddieaudioloop_entrypoint_7(*(u8 *)&param_0->actorData[3], param_0->position, 1, D_808013A0_chcrusherboulder, *(u32 *)((u8 *)param_0 + 0x70) & 1);
                *(f32 *)&param_0->actorData[3] = *(f32 *)&local_2;
                if (func_800DC0C0() < 0.2f) {
                    param_0->unk74_30 = 0;
                }
            } else {
                param_0->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.9f, 1.0f);
                if (func_800DC0C0() < 0.2f) {
                    param_0->unk74_30 = 1;
                }
            }
            func_80800F38_chcrusherboulder(param_0);
            if (!param_0->unk64_20) {
                func_800187B4(0, 1.0f, 1.0f, 6.5f);
                param_0->unk64_20 = 1;
            }
        } else {
            param_0->position[0] -= 144.0f * func_800D8FF8();
        }
        break;
    case 1:
    case 12:
        break;
    }
}

void func_808010EC_chcrusherboulder();

void func_8080087C_chcrusherboulder(param_0) Actor *param_0;
{
    switch (param_0->unk70_10) {
        case 1:
            if (func_800DA9E4(0x9DE, 0)) func_80800A1C_chcrusherboulder(param_0, 8);
            break;
        case 8:
            func_80800210_chcrusherboulder(param_0);
            func_808001CC_chcrusherboulder(param_0);
            if (param_0->unk58 > 0.0f) param_0->unk58 -= func_800D8FF8();
            else if (!param_0->unk64_19) {
                _chglowbo_entrypoint_6();
                param_0->unk64_19 = 1;
            }
            break;
        case 11:
            param_0->unk58 -= func_800D8FF8();
            if (param_0->unk58 > 0.0f && !(func_8001211C() & 2) && func_800DC0C0() < 0.3f) func_808010EC_chcrusherboulder();
            break;
    }
}

void func_808009C0_chcrusherboulder(CrushS *param_0) {
    _sudeflect_entrypoint_0((u8 *)param_0 + 4, 1.5e+02f, 240.0f, 0xA);
    if (param_0->flag) {
        func_80800338_chcrusherboulder(param_0);
    } else {
        func_8080087C_chcrusherboulder(param_0);
    }
}

void func_80800A1C_chcrusherboulder(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    f32 local_1[3];
    u8 local_2;
    s32 local_3;
    f32 local_4[3];

    local_0 = func_80100094(param_0, 1);
    func_80101FDC(param_0, param_1);
    switch (param_1) {
    case 2:
        param_0->position[1] = 750.0f;
        _sumumbofx_entrypoint_0(param_0, 1, 25, _chmumbopad_entrypoint_0(1));
        local_0 = func_80100094(param_0, 1);
        _sumumbofx_entrypoint_2(local_0);
        _sumumbofx_entrypoint_4(local_0);
        _sumumbofx_entrypoint_15(local_0, 0.1f);
        _sumumbofx_entrypoint_25(local_0, 0x80, D_808013B4_chcrusherboulder);
        func_8010A800(param_0, 2);
        _sumumbofx_entrypoint_3(local_0, 250.0f);
        local_1[0] = param_0->position[0];
        local_1[1] = param_0->position[1] + 300.0f;
        local_1[2] = param_0->position[2];
        _sumumbofx_entrypoint_12(local_0, local_1, D_808013C0_chcrusherboulder, D_808013C8_chcrusherboulder);
        break;
    case 4:
    case 5:
        _sumumbofx_entrypoint_16(local_0, 0.5f);
        break;
    case 3:
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801360_chcrusherboulder);
        func_800E1610(0, 10.0f, 0.8f, param_0->position);
        break;
    case 6:
        param_0->position[1] = 15.0f;
        break;
    case 7:
        func_800DA544(0x4FF);
        func_800DA544(0);
        param_0->unk74_30 = 0;
        break;
    case 12:
        _subaddieaudioloop_entrypoint_2(param_0);
        local_2 = _subaddieaudioloop_entrypoint_3(*(u8 *)&param_0->actorData[3]);
        *(f32 *)&param_0->actorData[3] = *(f32 *)&local_2;
        break;
    case 8:
        _sumumbofx_entrypoint_0(param_0, 1, 45, _chmumbopad_entrypoint_0(1));
        local_3 = func_80100094(param_0, 1);
        _sumumbofx_entrypoint_2(local_3);
        _sumumbofx_entrypoint_24(local_3, 0.65f);
        _sumumbofx_entrypoint_15(local_3, 3.0f);
        _sumumbofx_entrypoint_25(local_3, 0x80, D_808013B4_chcrusherboulder);
        func_8010A800(param_0, 2);
        local_4[0] = param_0->position[0];
        local_4[1] = param_0->position[1] + 300.0f;
        local_4[2] = param_0->position[2];
        _sumumbofx_entrypoint_12(local_3, local_4, D_808013C0_chcrusherboulder, D_808013C8_chcrusherboulder);
        func_80800210_chcrusherboulder(param_0);
        _capod_entrypoint_13(param_0->unk0, 0, 6, 0x4810);
        param_0->unk58 = 22.5f;
        break;
    case 11:
        _capod_entrypoint_13(param_0->unk0, 0, 8, 0x2830);
        param_0->unk64_16 = 0;
        param_0->unk58 = 3.0f;
        func_808010EC_chcrusherboulder();
        func_80101180(0x180, 10, 0);
        _subaddieaudioquick_entrypoint_2(param_0, D_808013D4_chcrusherboulder, D_80801374_chcrusherboulder);
        break;
    }
}

void func_80800D3C_chcrusherboulder(Actor *param_0)
{
  *((f32 *) (((s8 *) param_0) + 0x38)) = 0.7f;
  if (func_800EA05C() == 0xCB)
  {
    param_0->unk74_29 = 1;
  }
  else
  {
    param_0->unk74_29 = 0;
  }
  if (param_0->unk74_29)
  {
    if ((func_800DA298(0x4FF) != 0) || (func_800DA298(0x4FC) == 0))
    {
      func_800FFAB0(param_0);
      return;
    }
    if (func_800DA298(0x4FC) != 0)
    {
      if (func_800DA298(0x4FD) != 0)
      {
        func_80800A1C_chcrusherboulder(param_0, 6);
        return;
      }
      if (func_800DA298(0x4FB) != 0)
      {
        _capod_entrypoint_13(*((s32 *) (((s8 *) param_0) + 0)), 0, 2, 0x2820);
      }
      else
      {
        _capod_entrypoint_13(*((s32 *) (((s8 *) param_0) + 0)), 0, 0, 0x2820);
      }
      func_80800A1C_chcrusherboulder(param_0, 2);
    }
  }
  else
  {
    if (func_800DA298(0x4FF) != 0)
    {
      if (func_800DA9E4(0x500, 1) == 0)
      {
        func_80800A1C_chcrusherboulder(param_0, 0xB);
        return;
      }
      func_800FFAB0(param_0);
      return;
    }
    if (func_800DA298(0x4FC) != 0)
    {
      func_800FFAB0(param_0);
      return;
    }
    if (func_800DA298(0x4FD) != 0)
    {
      func_800FFAB0(param_0);
    }
  }
}

void func_80800ED0_chcrusherboulder(Actor *param_0)
{
    u8 local_0;

    if (func_80100094(param_0, 1)) {
        _sumumbofx_entrypoint_1(param_0, 1);
    }
    _subaddieaudioloop_entrypoint_2(param_0);
    local_0 = _subaddieaudioloop_entrypoint_3(*(u8 *)((u8 *)param_0 + 0x24));
    *(f32 *)((u8 *)param_0 + 0x24) = *(f32 *)&local_0;
    func_800DA524(0);
}

void func_80801128_chcrusherboulder();

void func_80800F38_chcrusherboulder(param_0) Actor *param_0;
{
    Vec3f local_0 = D_808013E0_chcrusherboulder;

    if ((func_8001211C() & 3) == 0) {
        local_0.f[2] = *(f32 *)&param_0->actorData[7] + -325.0f;
        if (func_800DC0C0() < 0.6f) {
            func_80801064_chcrusherboulder(local_0.f, *(s32 *)&param_0->scale);
        }
        local_0.f[2] += 25.0f;
        func_800DC0C0();
        func_80801128_chcrusherboulder(local_0.f, *(s32 *)&param_0->scale);
        local_0.f[2] = -325.0f - *(f32 *)&param_0->actorData[7];
        if (func_800DC0C0() < 0.6f) {
            func_80801064_chcrusherboulder(local_0.f, *(s32 *)&param_0->scale);
        }
        local_0.f[2] -= 25.0f;
        func_800DC0C0();
        func_80801128_chcrusherboulder(local_0.f, *(s32 *)&param_0->scale);
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808013EC_chcrusherboulder);
}

void func_80801064_chcrusherboulder(param_0, param_1) f32 *param_0; s32 param_1;
{
    s32 local_0;
    local_0 = func_800BABB8(0, param_0, 0, 1.0f, D_808013FC_chcrusherboulder);
    func_800BABB8(local_0, param_0, 0, 1.0f,
        param_0[2] < -325.0f ? D_8080143C_chcrusherboulder : D_80801450_chcrusherboulder);
}

void func_808010EC_chcrusherboulder()
{
    func_800BBCB8(&D_80801464_chcrusherboulder, 0, 1.0f, 3, &D_80801470_chcrusherboulder);
}

void func_80801128_chcrusherboulder(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_1 = func_800BABB8(0, param_0, 0, 1.0f, &D_808014BC_chcrusherboulder);
    local_0 = local_1;
    func_800BA3FC(local_1, 0x9DD);
    func_800BA22C(local_0, 1);
}

unsigned long func_80801184_chcrusherboulder(s32 param_0, u32 param_1, u32 param_2)
{
  if (param_1 == 0xB) {
    switch (param_2) {
    case 6:
      func_800DA544(0x4FC);
      _glcutDll_entrypoint_6(0xCB, 0x19);
      /* fallthrough */
    default:
      return 3;
    case 0:
      _glcutDll_entrypoint_17();
      return 3;
    case 4:
      _capod_entrypoint_15();
      _glcutDll_entrypoint_6(0xC7, 0x19);
      return 4;
    case 2:
      _glcutDll_entrypoint_17();
      return 3;
    case 8:
      if (_glcutDll_entrypoint_23() != 0) {
        _glcutDll_entrypoint_17();
        return 3;
      }
      if (func_800DB9B0() != 0) {
        _glcutDll_entrypoint_17();
      }
      _capod_entrypoint_14();
      func_800FFAB0(param_0);
      return 4;
    }
  } else {
    return 0;
  }
}

int chcrusherboulder_entrypoint_0()
{
    return (int)&D_808014EC_chcrusherboulder;
}
