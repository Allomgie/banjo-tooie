#include "common.h"
extern void func_8009BF5C(Actor *a0, f32 a1);

extern void func_8009FFD8(s32, s32, s32, s32, s32);
void baphysics_set_gravity(s32, f32);
void _baswim_entrypoint_10(s32, f32);
extern s32 D_80800A30_bsbanswim[];
extern void anctrl_setDuration(void *ctrl, float duration);
extern void *baanim_getAnimCtrlPtr(void);
extern s32 D_80800A40_bsbanswim[];
extern s32 D_80800A50_bsbanswim[];
extern s32 D_80800A60_bsbanswim[];

void func_80800000_bsbanswim(s32 param_0) {
    func_8009FFD8(param_0, 1, 3, 3, 9);
}

extern void func_80093360(Actor *a0, f32 a1);

int func_80800030_bsbanswim(Actor *param_0)
{
  if ((!func_8009E77C(param_0, 0xB)) & 0xFFFFFFFFu)
  {
    _baswim_entrypoint_5(param_0);
    baroll_setAngularVelocity(param_0, 0x43020000, 0x3F666666);
    baphysics_set_gravity(param_0, (long long) 0);
    baphysics_set_terminal_velocity(param_0, 0xC3C7FEB8);
    if (func_800F8B88() != 3)
    {
      func_800A0CF4(param_0, 1);
    }
    func_800961AC(param_0, 3);
    func_80093360(param_0, 6e+01f);
    func_8009BC5C(param_0, 0x40000000);
    _baswim_entrypoint_6(param_0, 1);
    if (bs_getCurrentState(param_0) != 0x4C)
    {
      _baairbar_entrypoint_0(param_0, 2);
    }
  }
}

int func_80800104_bsbanswim(param_0) Actor *param_0;
{
  extern void baroll_setIdeal(Actor *a0, f32 a1);
  extern void func_80093360(Actor *a0, f32 a1);
  Actor *s0 = param_0;
  if (!func_8009E74C(s0, 0xB))
  {
    func_8009BF5C(param_0, 0);
    baroll_setIdeal(param_0, 0);
    func_8009BC34(param_0);
    func_800A0CF4(param_0, 0);
    func_800961AC(param_0, 1);
    func_80093360(param_0, 0);
    _baswim_entrypoint_6(param_0, 0);
    if (bs_getCurrentState(param_0) != 0x4C)
    {
      _baairbar_entrypoint_0(param_0, 1);
    }
    _baswim_entrypoint_4(param_0);
  }
}

void func_808001A8_bsbanswim()
{
    func_80800104_bsbanswim();
}

void func_808001C8_bsbanswim(u8 *param_0)
{
  long long new_var;
  func_800C6DA0(0x3F);
  baanim_playForDuration_onceSmoothStartingAt(param_0, 0x27D, 0x3FD9999A, 0x3DCCCCCD);
  func_80800000_bsbanswim(param_0);
  yaw_setVelocityBounded(param_0, 0x43FA0000, 0x40A00000);
  func_80800030_bsbanswim(param_0);
  new_var = 0;
  _baswim_entrypoint_10(param_0, 0);
  _baswim_entrypoint_8(param_0, 0x44160000);
  func_8009BFE4(param_0, 0x43480000, 0x40200000);
  *((s8 *) (((s8 *) param_0) + 0x164)) = new_var;
}

void func_8080025C_bsbanswim(u8 *param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr();
    local_2 = *(u8 *)((char *)param_0 + 0x164);
    switch (local_2) {
    case 0:
        func_8009BF5C(param_0, 5e+01f);
        if (anctrl_isAt(local_1, 0x3EBD70A4) != 0) {
            if (_baswim_entrypoint_1(param_0) != 0) {
                func_800A0E64(param_0);
            }
            _baswim_entrypoint_10(param_0, 3e+02f);
            _baswim_entrypoint_8(param_0, 0x43480000);
            *(u8 *)((char *)param_0 + 0x164) = 1U;
        }
        break;
    case 1:
        _baswim_entrypoint_11(param_0);
        _baswim_entrypoint_13(param_0);
        if (anctrl_isAt(local_1, 0x3F428F5C) != 0) {
            local_0 = 0x2B;
        }
        break;
    }
    if (anctrl_isAt(local_1, 0x3F19999A) != 0) {
        func_8009DE38(param_0, 0x3FD, 0x3F800000);
    }
    if (player_inWater(param_0) == 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

int bsbanswim_entrypoint_0(s32 param_0)
{
  return D_80800A30_bsbanswim[param_0];
}

int func_80800390_bsbanswim(s32 param_0)
{
  switch (param_0)
  {
    case 0x81 :
    case 0x82 :
    case 0x90 :
      return 1;

    default :
      return 0;

  }

}

void func_808003BC_bsbanswim(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = bs_getNextState();
  if (func_80800390_bsbanswim(local_0) == 0)
  {
    if (func_8008E0E8(param_0) != 0)
    {
      _bapackctrl_entrypoint_5(param_0, 3);
    }
    func_80800104_bsbanswim(param_0);
  }
}

void func_8080040C_bsbanswim(s32 param_0)
{
  if (func_80800390_bsbanswim(bs_getPreviousState()) == 0)
  {
    baanim_playForDuration_loopSmooth(param_0, 0x27E, 0x3F400000);
    func_80800000_bsbanswim(param_0);
    func_80800030_bsbanswim(param_0);
    _baswim_entrypoint_10(param_0, ((((0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
    _baswim_entrypoint_8(param_0, 0x44160000);
    func_8009BC5C(param_0, 0x40000000);
    if (func_8008E0E8(param_0) != 0)
    {
      _bapackctrl_entrypoint_5(param_0, 4);
    }
  }
}

void func_8080049C_bsbanswim()
{
    func_808003BC_bsbanswim();
}

void func_808004BC_bsbanswim(Actor *param_0)
{
    void *local_0;
    local_0 = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(param_0);
    anctrl_setDuration(local_0, 1.0f);
}

void func_808004F4_bsbanswim(s32 param_0) {
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(param_0);
    _baswim_entrypoint_12(param_0);
    _baswim_entrypoint_13(param_0);
    if (anctrl_isAt(sp20, 0x3F03126F) != 0) {
        _baswim_entrypoint_10(param_0, 3.2e+02f);
    } else {
        _baswim_entrypoint_10(param_0, 2.5e+02f);
    }
    if (anctrl_isAt(sp20, 0x3E2E147B) != 0) {
        func_8009DF18(param_0, 0x3FD, 0x3FF33333, 0x2710);
    }
    if (anctrl_isAt(sp20, 0x3F2B851F) != 0) {
        func_8009DF18(param_0, 0x3FD, 0x3FD9999A, 0x2710);
    }
    temp_v0 = _baswim_entrypoint_3(param_0);
    switch (temp_v0) {
    case 1:
        break;
    case 0:
        if (anctrl_isAt(sp20, 0x3F7D70A4) != 0) {
            sp24 = 0x2B;
        }
        break;
    case 2:
        sp24 = 0x82;
        break;
    case 3:
        sp24 = 0x90;
        break;
    }
    if (_baswim_entrypoint_2(param_0) != 0) {
        sp24 = 0x2D;
    }
    if (player_inWater(param_0) == 0) {
        sp24 = 1;
    }
    bs_setState(param_0, sp24);
}

int bsbanswim_entrypoint_1(int param_0)
{
  return D_80800A40_bsbanswim[param_0];
}

void func_80800670_bsbanswim()
{
    func_808003BC_bsbanswim();
}

void func_80800690_bsbanswim(s32 param_0) {
    s32 local_0;

    local_0 = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(param_0);
    anctrl_setDuration(local_0, 0.8f);
}

void func_808006CC_bsbanswim(s32 param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(param_0);
    _baswim_entrypoint_12(param_0);
    _baswim_entrypoint_13(param_0);
    if (anctrl_isAt(local_1, 0x3F03126F) != 0) {
        _baswim_entrypoint_10(param_0, 4.5e+02f);
    } else {
        _baswim_entrypoint_10(param_0, 3e+02f);
    }
    if (anctrl_isAt(local_1, 0x3E2E147B) != 0) {
        func_8009DF18(param_0, 0x3FD, 0x3FF33333, 0x2710);
    }
    if (anctrl_isAt(local_1, 0x3F2B851F) != 0) {
        func_8009DF18(param_0, 0x3FD, 0x3FD9999A, 0x2710);
    }
    local_2 = _baswim_entrypoint_3(param_0);
    switch (local_2) {                              
    case 2:
        break;
    case 0:
        if (anctrl_isAt(local_1, 0x3F7D70A4) != 0) {
            local_0 = 0x2B;
        }
        break;
    case 1:
        local_0 = 0x81;
        break;
    case 3:
        local_0 = 0x90;
        break;
    }
    if (_baswim_entrypoint_2(param_0) != 0) {
        local_0 = 0x2D;
    }
    if (player_inWater(param_0) == 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

int bsbanswim_entrypoint_2(int param_0)
{
  return D_80800A50_bsbanswim[param_0];
}

void func_80800848_bsbanswim()
{
    func_808003BC_bsbanswim();
}

void func_80800868_bsbanswim(s32 param_0) {
    s32 local_0;

    local_0 = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(param_0);
    anctrl_setDuration(local_0, 0.7f);
}

void func_808008A4_bsbanswim(s32 param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(param_0);
    _baswim_entrypoint_12(param_0);
    _baswim_entrypoint_13(param_0);
    if (anctrl_isAt(local_1, 0x3F03126F) != 0) {
        _baswim_entrypoint_10(param_0, 6e+02f);
    } else {
        _baswim_entrypoint_10(param_0, 4e+02f);
    }
    if (anctrl_isAt(local_1, 0x3E2E147B) != 0) {
        func_8009DF18(param_0, 0x3FD, 0x3FF33333, 0x2710);
    }
    if (anctrl_isAt(local_1, 0x3F2B851F) != 0) {
        func_8009DF18(param_0, 0x3FD, 0x3FD9999A, 0x2710);
    }
    local_2 = _baswim_entrypoint_3(param_0);
    switch (local_2) {                              
    case 3:
        break;
    case 0:
        if (anctrl_isAt(local_1, 0x3F7D70A4) != 0) {
            local_0 = 0x2B;
        }
        break;
    case 1:
        local_0 = 0x81;
        break;
    case 2:
        local_0 = 0x82;
        break;
    }
    if (_baswim_entrypoint_2(param_0) != 0) {
        local_0 = 0x2D;
    }
    if (player_inWater(param_0) == 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

s32 bsbanswim_entrypoint_3(s32 param_0) {
    return D_80800A60_bsbanswim[param_0];
}
