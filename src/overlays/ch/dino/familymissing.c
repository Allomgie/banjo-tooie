#include "common.h"

extern s32 D_808006AC_chdinofamilymissing[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, s32 *, s32);
extern void func_80105A9C(Actor *, f32);
extern u8 D_80800664_chdinofamilymissing[];
extern u8 D_808006CC_chdinofamilymissing[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern int D_808006DC_chdinofamilymissing;
extern u8 D_808006A0_chdinofamilymissing[];
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern s32 func_80105998(Actor *, f32);

int func_80800000_chdinofamilymissing(s32 param_0)
{
  switch (func_800EA05C())
  {
    case 0x114:
      if (!_glcutDll_entrypoint_19(0x35))
      {
        func_800FFAB0(param_0);
        return;
      }
      return;

    case 0x118:
      if (_glcutDll_entrypoint_20() != 0)
      {
        if (func_80105494(param_0) != 0)
        {
          func_800FFAB0(param_0);
          return;
        }
        func_80102424(param_0, 7);
        return;
      }
      if ((_glcutDll_entrypoint_19(0x35) == 0) || (func_80105494(param_0) == 0))
      {
        if ((func_800DA298(0x8A) != 0) && (func_80105494(param_0) == 0))
        {
          func_80102424(param_0, 5);
          return;
        }
        func_800FFAB0(param_0);
        return;
      }
      break;

    default:
      func_800FFAB0(param_0);
      break;
  }
}

void func_80800418_chdinofamilymissing();

void func_80800104_chdinofamilymissing(Actor *param_0)
{
    _sudeflect_entrypoint_1(param_0->position, func_80103EF4(param_0), 0.0f, func_80103EAC(param_0), 10);
    switch (param_0->unk70_10) {
    case 1:
        func_80800418_chdinofamilymissing(param_0);
        func_80105834(param_0);
        if (func_80105998(param_0, 0.15f)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17CD, 0xF, param_0->position, 0x39);
        }
        if (func_80105A5C(param_0)) {
            _glcutDll_entrypoint_24(0x118, -1, 0x35);
            func_800FFAB0(param_0);
        }
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_808006A0_chdinofamilymissing, 0.47f);
        break;
    case 2:
        if (func_80105A5C(param_0)) {
            func_800DA524(0x588);
            func_80102424(param_0, 3);
            *((u8 *)param_0 + 0x77) &= ~0xF;
        } else {
            func_80800418_chdinofamilymissing(param_0);
            func_80105834(param_0);
        }
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_808006A0_chdinofamilymissing, 0.47f);
        break;
    case 3:
        if (func_80105A5C(param_0)) {
            func_800DA544(0x8A);
            func_80101180(0x290, 0x33, 2);
            func_80102424(param_0, 4);
        }
        break;
    case 4:
        break;
    case 5:
        _sudeflect_entrypoint_1(param_0->position, param_0->scale * 235.0f, 0.0f, param_0->scale * 179.0f, 30);
        if (_subaddiedialog_entrypoint_4(param_0->position, 600, 0)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17CE, 0xF, param_0->position, 0x39);
        }
        break;
    }
    _chdinofamilyfx_entrypoint_0(param_0);
}

int func_80800324_chdinofamilymissing(s32 param_0, s32 param_1)
{
  int new_var;
  u32 local_0;
  switch (func_800EA05C(param_0))
  {
    case 0x114:
      new_var = 0x2831;
      if (_glcutDll_entrypoint_19(0x35) != 0)
    {
      func_80102424(param_0, 1);
      _capod_entrypoint_13(*(s32*)((char*)param_0 + 0x0), 0, 5, new_var);
      return 1;
    }
      break;

    case 0x118:
      if ((_glcutDll_entrypoint_19(0x35) != 0) && (func_80105494(param_0) != 0))
    {
      func_80102424(param_0, 2);
      _capod_entrypoint_13(*(s32*)((char*)param_0 + 0x0), 0, 0xC, 0x2831);
      return 1;
    }
      if ((_glcutDll_entrypoint_19(0x38) != 0) && (func_80105494(param_0) != 0))
    {
      func_800FFAB0(param_0);
      return 1;
    }

  }

  return 0;
}

void func_80800418_chdinofamilymissing(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800F3780(func_80101F24(param_0), D_808006AC_chdinofamilymissing, 4);
    func_80105A9C(param_0, (param_0->unk70_10 == 1 ? 0.75f : 1.0f) * (local_0 * 1200.0f));
}

int func_808004A4_chdinofamilymissing(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x49:
        return func_80800324_chdinofamilymissing(param_0, param_2);
    case 0x1F:
        func_801015D0(param_0);
        if (*(u16 *)(D_80800664_chdinofamilymissing + param_0->unk70_10 * 8) == 0x14D) {
            func_800DF744(3, 1);
            return 1;
        }
        func_800DF744(1, 0);
        func_800DF744(2, 1);
        func_800DF744(3, 2);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_3(D_808006CC_chdinofamilymissing, param_0->scale);
        return 3;
    case 0xB:
        if (param_2 == 12 && _glcutDll_entrypoint_19(0x35)) {
            if (func_800DA298(0x189) && func_800DA298(0x15E)) {
                _glcutDll_entrypoint_24(0x114, -1, 0x38);
                return 3;
            }
            if (!func_800DA298(0x15E) || func_800DA298(0x189) || !func_800DA298(0x15F))
                _glcutDll_entrypoint_17();
        }
        return 3;
    default:
        return 0;
    }
}

int chdinofamilymissing_entrypoint_0()
{
    return (int)&D_808006DC_chdinofamilymissing;
}
