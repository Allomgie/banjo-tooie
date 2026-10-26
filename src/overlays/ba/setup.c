#include "common.h"
#include "playerstate.h"

extern void func_800EE7F8(void *, void *);
extern void func_800C6A7C(void *, void *, void *, int);
extern f32 func_8009E97C(void);
extern f32 func_8009E988(void);
extern void bastatetimer_set(PlayerState *, s32, f32);
extern f32 func_800F8A50(void);
extern void _plcamera_entrypoint_13(int *param_0, f32 param_1);
extern void yaw_setIdeal(int param_0, f32 param_1);
extern u8 D_8012762C;
extern void func_8009EB0C(f32);
extern int _gspropctrl_entrypoint_13(s32);
extern void _basetup_entrypoint_1(void);
extern s32 func_800F4A8C(s32, f32 *, f32);

s32 basetup_entrypoint_0() 
{
    return 0x4;
}

int func_80800008_basetup(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800EA05C();
  local_1 = func_800EA090();
  if (!func_800DB9B0())
  {
    if (local_0 == 0x13A && local_1 == 0xE || local_0 == 0x136 && local_1 == 0x1B)
    {
      if (func_800DA298(0x327))
      {
        func_800A0FF0(param_0);
      }
    }
  }
}

void func_80800080_basetup(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = _bashoes_entrypoint_1();
  local_1 = func_800F40EC(param_0);
  if (local_1)
  {
    switch (func_800A3274(param_0))
    {
      case 1:
        switch (local_0)
        {
          case 2:
          case 3:
          case 4:
          case 5:
            _bashoes_entrypoint_6(param_0, 1);
            break;
        }
        break;
      case 0xb:
        switch (local_0)
        {
          case 3:
          case 4:
          case 5:
            _bashoes_entrypoint_6(param_0, 2);
            break;
        }
        break;
    }
  }
}

void func_80800140_basetup(s32 param_0)
{
  f32 local_2[3];
  f32 local_0[3];
  func_800EE7F8(local_0, param_0);
  *(f32 *)((char *)param_0 + 4) -= 1000.0f;
  func_800C6A7C(local_0, param_0, local_2, 0x420025);
}

int func_80800194_basetup(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_0 = func_800A3274(param_0);
  local_1 = func_800EA05C();
  local_2 = func_800EA090();
  if (!func_800DB9B0())
  {
    if (local_1 == 0x112 && local_2 == 0xF || local_1 == 0x116 && local_2 == 2)
    {
      if (local_0 == 0x12)
      {
        func_80800140_basetup(param_1);
        func_80800140_basetup(param_2);
      }
    }
  }
}

void basetup_entrypoint_1(s32 param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_800F53D0(param_1);
    local_1 = _badata_entrypoint_35(local_0);
    local_2 = func_800EA068(8);
    switch (func_8009E958()) {
    case 1:
        if (local_2 && func_800C6E38(0x15)) local_1 = 0xC8;
        break;
    case 9:
        if (local_2) local_1 = 0xCB;
        else local_1 = 0xC9;
        break;
    }
    func_800A3544(local_0, 0);
    bs_setState(local_0, local_1);
}

void func_808002D4_basetup(PlayerState *param_0)
{
    bastatetimer_set(param_0, 2, func_8009E97C());
    bastatetimer_set(param_0, 3, func_8009E988());
    if (func_8009EA64()) {
        bs_setState(param_0, _badata_entrypoint_33(param_0));
    } else if (func_8009EA20()) {
        bs_setState(param_0, 0x11E);
    } else {
        func_80800008_basetup(param_0);
        bs_setState(param_0, _badata_entrypoint_35(param_0));
    }
    func_80800080_basetup(param_0);
}

void func_80800394_basetup(u8 *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    local_0 = func_800F8B88() == 3;
    local_1 = func_8008DAA8(param_0);
    local_2 = func_800A3274(param_0);
    local_5 = bs_getCurrentState(param_0);
    local_4 = local_5 == 0;
    if (local_1 != 0) {
        if (local_4) {
            func_808002D4_basetup(param_0);
        }
    } else if (local_4) {
        func_808002D4_basetup(param_0);
    }
    if (local_1 == 0) {
        local_5 = func_800A3274(param_0);
        if (func_800F64A4(func_800F54E4(), 0x10000) != 0) {
            if (func_8008E23C(param_0) != 0 && local_5 == 0xA) {
                func_800F457C(param_0, 2);
            } else {
                bs_setState(param_0, _badrone_entrypoint_29(param_0));
            }
        } else {
            if (local_0 != 0) {
                bs_setState(param_0, 0xED);
            } else {
                func_800F457C(param_0, 2);
            }
        }
        if (func_800F8DA8(local_5) != 0) {
            func_800F8D50(*((s32 *)(param_0 + 0x184)), local_5);
        }
    } else {
        local_6 = 0;
        switch (local_2) {
        case 11:
            if (local_0 != 0) {
                local_6 = 1;
            }
            break;
        case 14:
        case 17:
            local_6 = 1;
            break;
        }
        if (local_6 != 0) {
            func_800F8128(*((s32 *)(param_0 + 0x184)));
        }
    }
}

s32 func_80800534_basetup(int param_0) {
    int local_0;
    s32 pad0;
    int local_1;
    local_1 = param_0;
    if (func_800DB9B0() != 0 || _glcutDll_entrypoint_1() != 0) {
        func_80800394_basetup(local_1);
        return 1;
    }
    if (func_8008DAA8(local_1) == 0) {
        func_80800394_basetup(local_1);
        if (func_800F99FC() == 0 && func_800F99E8() == 0 && func_800F8B7C() != 0 && func_8008E23C(local_1) != 0) {
            _plcamera_entrypoint_13(*(int **)(local_1 + 0x184), func_800F8A50());
        }
        return 1;
    }
    if (func_800F99FC() != 0) {
        if (func_800A3274(local_1) == 0xA) {
            func_808002D4_basetup(local_1);
        }
        return 1;
    }
    if (func_800F99E8() != 0) {
        func_80800394_basetup(local_1);
        return 1;
    }
    if (func_800F8B7C() != 0 && func_8008E23C(local_1) != 0) {
        func_800F89E4(func_800A3274(local_1), (int *)((s8 *)&local_0 - 8));
        func_800F452C(local_1, (int *)((s8 *)&local_0 - 8));
        yaw_setIdeal(local_1, func_800F8A50());
        yaw_applyIdeal(local_1);
        _plcamera_entrypoint_13(*(int **)(local_1 + 0x184), func_800F8A50());
        func_80800394_basetup(local_1);
        return 1;
    }
    if (func_8009EA64() != 0) {
        func_80800394_basetup(local_1);
        return 1;
    }
    return 0;
}

int func_808006F0_basetup()
{
  s32 local_0;
  local_0 = _gemarkersDll_entrypoint_1();
  _gccubesearch_entrypoint_14(local_0 | 0, 0);
}

int func_8080071C_basetup(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = 0x52;
  if (func_800A9C98(param_0) != 0)
  {
    return 0;
  }
  local_1 = 0;
  if ((param_0 > 0) && (param_0 < 0x29))
  {
    local_0 += param_0;
  }
  return _gccubesearch_entrypoint_14(local_0 | 0, 0);
}

s32 func_80800778_basetup(PlayerState *param_0)
{
    s32 local_0;

    local_0 = func_8009E958();
    switch (local_0) {
    case 9:
        if (func_800EA05C() == 0x116) {
            local_0 = 1;
            func_8009EB18(0);
        }
        break;
    case 1:
        if (func_800EA068(8) && func_800C6E38(0x15)) local_0 = 9;
        break;
    }
    if (func_800EA068(0x40)) {
        switch (func_800EA05C()) {
        case 0x182: local_0 = 12; break;
        case 0x188: local_0 = 6; break;
        default: local_0 = 9; break;
        }
        func_8009E9D8(local_0);
    }
    return local_0;
}

void basetup_entrypoint_2(PlayerState *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4;
    f32 local_5[3];
    s32 local_6;
    s32 local_9;
    Vec3f local_7;
    f32 local_8;

    if (func_800A3274() == 4 || _gclevel_entrypoint_4(1)) {
        func_800F44DC(param_0, 0);
        return;
    }
    if (!func_80800534_basetup(param_0)) {
        local_2 = func_800EA090();
        local_0 = func_808006F0_basetup(local_2);
        if (local_0) {
            local_1 = func_8080071C_basetup(local_2);
        } else {
            if (_sudeathmatch_entrypoint_0(*(s32 *)((u8 *)param_0 + 0x184), local_3, local_5)) {
                local_4 = local_5[1];
            } else if (!local_0) {
                func_800F44DC(param_0, 0);
                return;
            }
            local_1 = 0;
        }
        local_6 = func_80800778_basetup(param_0);
        if (local_6 == 9) {
            _bashoes_entrypoint_6(param_0, 1);
            func_8009EB0C(0.0f);
            if (local_1 && !func_8009E994()) {
                local_6 = func_8009E958();
            } else {
                func_800A3544(param_0, D_8012762C == 0x1B ? 1 : 0);
            }
        }
        func_800A3410(param_0, local_6);
        func_80092778(param_0);
        func_800F44DC(param_0, 0);
        if (local_0) {
            _gspropctrl_entrypoint_11(local_0, local_3);
            local_4 = _gspropctrl_entrypoint_12(local_0);
        }
        func_800F44DC(param_0, 1);
        **(s32 **)((u8 *)param_0 + 0x100) = -1;
        if (func_8009EA4C() == 2) {
            if (func_800EA068(8) && func_800C6E38(0x15)) {
                func_8009EAD0(1);
            } else {
                local_4 += 180.0f;
            }
        }
        yaw_setIdeal(param_0, local_4);
        yaw_applyIdeal(param_0);
        if (local_1) {
            local_8 = 1.0f;
            if (func_800EA068(4)) {
                local_9 = _gspropctrl_entrypoint_13(local_1);
                local_8 = local_9 * 0.1f;
            }
            _gspropctrl_entrypoint_11(local_1, local_7.f);
            func_80800194_basetup(param_0, local_7.f, local_3);
            func_800F452C(param_0, local_7.f);
            func_808002D4_basetup(param_0);
            func_800F497C(*(s32 *)((u8 *)param_0 + 0x184));
            func_800F49D4(*(s32 *)((u8 *)param_0 + 0x184), _basetup_entrypoint_1,
                *(s32 *)((u8 *)param_0 + 0x184));
            func_800F4A8C(*(s32 *)((u8 *)param_0 + 0x184), local_3, local_8);
        } else {
            func_800F452C(param_0, local_3);
            func_808002D4_basetup(param_0);
        }
    }
}

void basetup_entrypoint_3(s32 arg0) 
{
}
void basetup_entrypoint_4(s32 arg0) 
{
}
