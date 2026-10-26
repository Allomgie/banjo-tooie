#include "common.h"
#include "overlays/ba/playerstate.h"
extern void _baswim_entrypoint_10(PlayerState *, f32);
extern void baroll_setIdeal(Actor *a0, f32 a1);
extern void func_8009BF5C(Actor *a0, f32 a1);

void baphysics_set_gravity(s32, f32);
extern s32 D_80801E60_bsbswim[];
extern void _baswim_entrypoint_8(void *param_0, int param_1);
extern float anctrl_getAnimTimer(void *param_0);
extern void baanim_playForDuration_loopStartingAt(Actor *param_0, int param_1, float param_2, float param_3);
extern int bs_getPreviousState(Actor *param_0);
extern void func_800910BC(Actor *param_0, int param_1);
extern s32 D_80801E70_bsbswim[];
extern void *baanim_getAnimCtrlPtr();
extern s32 anctrl_isAt(void *, f32);
extern s32 func_8009FBB0(PlayerState *, f32 *, f32);
extern void func_8009DE74(void *, s32, f32, f32);
extern s32 D_80801E80_bsbswim[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009BC5C(PlayerState *, f32);
extern s32 D_80801E90_bsbswim[];
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_8009D89C(PlayerState *, f32);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 _bareact_entrypoint_4(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern s32 D_80801EA0_bsbswim[];
extern s32 D_80801EB0_bsbswim[];
extern s32 D_80801EC0_bsbswim[];
extern s32 D_80801ED0_bsbswim[];
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_800A0180(void *);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void baphysics_set_vertical_velocity(void *, f32);
extern s32 _batimer_isAt_rising(void *, s32, f32);
extern s32 _batimer_isGreaterThan(void *, s32, f32);
extern void _ncbadie_entrypoint_3(void *, f32);
extern void func_800A4E30();
extern void func_8008E95C();
extern s32 D_80801EE0_bsbswim[];
extern void _baswim_entrypoint_9(PlayerState *, f32);
extern s32 D_80801EF0_bsbswim[];
extern void anctrl_setDuration(void *, f32);
extern void anctrl_setStart(void *, f32);
extern f32 func_800A3298(PlayerState *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_80801F00_bsbswim[];
extern s32 D_80801F10_bsbswim[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_80801F20_bsbswim[];
extern s32 D_80801F78_bsbswim[];
extern s32 D_80801F88_bsbswim[];
extern s32 D_80801F98_bsbswim[];
extern f32 mlAbsF(f32);
extern f32 baphysics_get_vertical_velocity(void *);

void func_80800000_bsbswim(int arg0)
{
  func_8009FFD8(arg0, 1, 3, 3, 9);
}

extern void func_80093360(Actor *a0, f32 a1);

void func_80800030_bsbswim(param_0) Actor *param_0;
{
  int new_var2;
  Actor *new_var;
  if (1)
  {
    if (!func_8009E77C(param_0, 0xB))
    {
      _baswim_entrypoint_5(param_0);
      baroll_setAngularVelocity(param_0, 0x43020000, 0x3F666666);
      baphysics_set_gravity(param_0, 0 & 0xFFFFFFFFFFFFFFFFu);
      baphysics_set_terminal_velocity(param_0, 0xC3C7FEB8);
      if (func_800F8B88() != 3)
      {
        new_var = param_0;
        func_800A0CF4(new_var, 1);
      }
      if (param_0 && param_0)
      {
      }
      func_800961AC(param_0, 3);
      func_80093360(param_0, 6e+01f);
      func_8009BC5C(param_0, 2.0f);
      new_var2 = 1;
      _baswim_entrypoint_6(param_0, new_var2);
      if (bs_getCurrentState(param_0) != 0x4C)
      {
        _baairbar_entrypoint_0(param_0, 2);
      }
    }
  }
}

int func_80800104_bsbswim(param_0) Actor *param_0;
{
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

void func_808001A8_bsbswim()
{
    func_80800104_bsbswim();
}

void func_808001C8_bsbswim(s32 param_0) {
    s32 local_0;

    local_0 = baanim_getAnimCtrlPtr();
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x70);
    anctrl_setDuration(local_0, 2.0f);
    func_8008B1C8(local_0, 0x3F000000);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_80800000_bsbswim(param_0);
    func_8009B94C(param_0, 0);
    func_80800030_bsbswim(param_0);
    func_8009BC5C(param_0, 0.4f);
    _baswim_entrypoint_8(param_0, 0x43960000);
    if (func_8008E23C(param_0) != 0) {
        func_800A0CF4(param_0, 0);
    }
}

void func_80800288_bsbswim(s32 param_0)
{
  s32 local_0;
  local_0 = 0;
  _baswim_entrypoint_11(param_0);
  _baswim_entrypoint_12(param_0);
  _baswim_entrypoint_13(param_0);
  if (func_8008E23C(param_0))
  {
    if (bakey_held(param_0, 8) || bakey_held(param_0, 9))
    {
      local_0 = 0x81;
    }
  }
  else
  {
    switch (_baswim_entrypoint_3(param_0))
    {
      case 0:
        break;
      case 1:
        local_0 = 0x39;
        break;
      case 2:
        local_0 = 0x2C;
        break;
      case 3:
        local_0 = 0x19;
        break;
    }
    if (bainput_func_8009803C(param_0))
    {
      local_0 = 0x157;
    }
  }
  if (_baswim_entrypoint_2(param_0))
  {
    local_0 = 0x2D;
  }
  if (!player_inWater(param_0))
  {
    local_0 = 1;
  }
  bs_setState(param_0, local_0);
}

int bsbswim_entrypoint_0(s32 param_0)
{
  return D_80801E60_bsbswim[param_0];
}

void func_8080039C_bsbswim(Actor *param_0)
{
  void *local_0;
  float local_1;
  local_0 = baanim_getAnimCtrlPtr(param_0);
  if (bs_getPreviousState(param_0) == 0x19)
  {
    local_1 = anctrl_getAnimTimer(local_0);
  }
  else
  {
    local_1 = 0.5f;
  }
  baanim_playForDuration_loopStartingAt(param_0, 0x3F, 1.0f, local_1);
  func_80800000_bsbswim(param_0);
  func_80800030_bsbswim(param_0);
  _baswim_entrypoint_8(param_0, 0x43960000);
  func_8009BC5C(param_0, 1.0f);
  func_800910BC(param_0, 2);
}

void func_80800440_bsbswim(Actor *param_0)
{
    s32 local_1C;
    s32 local_18;

    local_1C = 0;
    local_18 = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(param_0);
    _baswim_entrypoint_12(param_0);
    _baswim_entrypoint_13(param_0);
    if (anctrl_isAt(local_18, 0.1f) != 0) {
        func_8009DE74(param_0, 0x3FD, 1.2f, 1.4f);
        _baswim_entrypoint_10(param_0, 6e+02f);
    }
    if (anctrl_isAt(local_18, 0.4626f) != 0) {
        anctrl_setDuration(local_18, 1.0f);
    }
    if (anctrl_isAt(local_18, 0.2766f) != 0) {
        anctrl_setDuration(local_18, 3.0f);
    }
    switch (_baswim_entrypoint_3(param_0)) {
    case 2:
        break;
    case 0:
        if (anctrl_isAt(local_18, 0.4625f) != 0) {
            local_1C = 0x2B;
        }
        break;
    case 1:
        local_1C = 0x39;
        break;
    case 3:
        local_1C = 0x19;
        break;
    }
    if ((anctrl_isAt(local_18, 0.4625f) != 0) && (bakey_held(param_0, 9) == 0)) {
        if (bakey_held(param_0, 8) != 0) {
            local_1C = 0x39;
        } else {
            local_1C = 0x2B;
        }
    }
    if (bainput_func_8009803C(param_0) != 0) {
        local_1C = 0x157;
    }
    if (_baswim_entrypoint_2(param_0) != 0) {
        local_1C = 0x2D;
    }
    if (player_inWater(param_0) == 0) {
        local_1C = 1;
    }
    bs_setState(param_0, local_1C);
}

void func_808005F4_bsbswim(s32 arg0)
{
    func_800910BC(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

int bsbswim_entrypoint_1(s32 param_0)
{
  return D_80801E70_bsbswim[param_0];
}

void func_80800634_bsbswim(Actor *param_0)
{
  void *local_0;
  float local_1;
  local_0 = baanim_getAnimCtrlPtr(param_0);
  if (bs_getPreviousState(param_0) == 0x2c)
  {
    local_1 = anctrl_getAnimTimer(local_0);
  }
  else
  {
    local_1 = 0.5f;
  }
  baanim_playForDuration_loopStartingAt(param_0, 0xeb, 1.0f, local_1);
  func_80800000_bsbswim(param_0);
  func_80800030_bsbswim(param_0);
  _baswim_entrypoint_8(param_0, 0x44160000);
  func_8009BC5C(param_0, 1.0f);
  func_800910BC(param_0, 2);
  *(u8 *)((char *)(param_0) + 0x166) = 0;

}

void func_808006DC_bsbswim(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    s32 local_2;
    f32 local_3[3];

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    _baswim_entrypoint_11(param_0);
    _baswim_entrypoint_12(param_0);
    _baswim_entrypoint_13(param_0);
    if (anctrl_isAt(local_1, 0.3f)) {
        param_0->unk164.bytes[2] = 1;
    }
    if (!func_8001210C(1)) {
        func_8009C128(param_0, &local_3);
        local_3[1] += 60.0f;
        local_2 = func_8009FBB0(param_0, &local_3, 40.0f);
        func_800BA930(local_2, -60, -50, -60, 60, 100, 60);
        func_800BA22C(local_2, 1);
    }
    if (anctrl_isAt(local_1, 0.08f)) {
        func_8009DE74(param_0, 0x3FD, 1.2f, 1.4f);
        _baswim_entrypoint_10(param_0, 9e+02f);
    } else {
        _baswim_entrypoint_10(param_0, 5e+02f);
    }
    switch (_baswim_entrypoint_3(param_0)) {
    case 0:
        if (anctrl_isAt(local_1, 0.4791f)) {
            local_0 = 0x2B;
        }
        break;
    case 1:
        if (param_0->unk164.bytes[2]) {
            local_0 = 0x39;
        }
        break;
    case 2:
        if (param_0->unk164.bytes[2]) {
            local_0 = 0x2C;
        }
        break;
    case 3:
        break;
    }
    if (bainput_func_8009803C(param_0)) {
        local_0 = 0x157;
    }
    if (_baswim_entrypoint_2(param_0)) {
        local_0 = 0x2D;
    }
    if (!player_inWater(param_0)) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

void func_808008CC_bsbswim(s32 arg0)
{
    func_800910BC(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

int bsbswim_entrypoint_2(s32 param_0)
{
  return D_80801E80_bsbswim[param_0];
}

void func_8080090C_bsbswim(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0x71, 0.75f);
    func_80800000_bsbswim(param_0);
    func_80800030_bsbswim(param_0);
    _baswim_entrypoint_10(param_0, 2.5e+02f);
    _baswim_entrypoint_8(param_0, 0x44160000);
    func_8009BC5C(param_0, 2.0f);
    func_800910BC(param_0, 2);
}

void func_8080097C_bsbswim(Actor *param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    _baswim_entrypoint_11(param_0);
    _baswim_entrypoint_12(param_0);
    _baswim_entrypoint_13(param_0);
    _baswim_entrypoint_10(param_0, 2.5e+02f);
    if (anctrl_isAt(local_1, 0.17f) != 0) {
        func_8009DF18(param_0, 0x3FD, 1.9f, 0x2710);
    }
    if (anctrl_isAt(local_1, 0.67f) != 0) {
        func_8009DF18(param_0, 0x3FD, 1.7f, 0x2710);
    }
    local_2 = _baswim_entrypoint_3(param_0);
    switch (local_2) {
    case 1:
        break;
    case 0:
        if (anctrl_isAt(local_1, 0.4791f) != 0) {
            local_0 = 0x2B;
        }
        break;
    case 2:
        local_0 = 0x2C;
        break;
    case 3:
        local_0 = 0x19;
        break;
    }
    if (bainput_func_8009803C(param_0) != 0) {
        local_0 = 0x157;
    }
    if (_baswim_entrypoint_2(param_0) != 0) {
        local_0 = 0x2D;
    }
    if (player_inWater(param_0) == 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

void func_80800AD0_bsbswim(s32 arg0)
{
    func_800910BC(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

int bsbswim_entrypoint_3(s32 param_0)
{
  return D_80801E90_bsbswim[param_0];
}

void func_80800B10_bsbswim(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    _bareact_entrypoint_1(param_0, func_80099A58(param_0));
    baanim_playForDuration_once(param_0, 0x14, 1.4f);
    func_8009D89C(param_0, 1.0f);
    func_8009C128(param_0, local_1);
    func_800A32C4(param_0, local_2);
    func_800F1E6C(local_2, local_1, &local_0);
    yaw_setIdeal(param_0, local_0);
    yaw_applyIdeal(param_0);
    baphysics_set_target_horizontal_velocity(param_0, _bareact_entrypoint_4(param_0));
    baphysics_set_target_yaw(param_0, local_0);
    baphysics_set_horizontal_velocity(param_0, local_0, baphysics_get_target_horizontal_velocity(param_0));
    func_8009FFD8(param_0, 1, 1, 2, 3);
    func_8008E944(param_0);
    func_8009514C(param_0);
    func_80800030_bsbswim(param_0);
}

void func_80800C0C_bsbswim(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1[3];
    s32 local_2;

    local_0 = 0;
    func_8009C128(param_0, local_1);
    local_1[1] += 60.0f;
    local_2 = func_8009FBB0(param_0, local_1, 25.0f);
    func_800BA930(local_2, -60, -50, -60, 60, 100, 60);
    func_800BA22C(local_2, 1);
    if (baanim_isAt(param_0, 0.3f)) func_800951B4(param_0);
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(param_0))) local_0 = 0x2B;
    bs_setState(param_0, local_0);
}

s32 func_80800CE4_bsbswim(s32 param_0){
    func_8009BD88();
    func_8008E95C(param_0);
    func_800951B4(param_0);
    func_80800104_bsbswim(param_0);
}

int bsbswim_entrypoint_4(s32 param_0)
{
  return D_80801EA0_bsbswim[param_0];
}

void func_80800D30_bsbswim(s32 arg0)
{
    _baspin_entrypoint_1();
    func_80800104_bsbswim(arg0);
}
void func_80800D58_bsbswim(Actor *param_0)
{
  func_80800030_bsbswim();
  _baspin_entrypoint_2(param_0, 0xB9, 0x3F333333, 3, 1);
}

int func_80800D98_bsbswim(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  func_800914FC(param_0, 0x42200000, 0);
  if (_baspin_entrypoint_3(param_0) == 2)
  {
    local_0 = 0x2B;
  }
  bs_setState(param_0, local_0);
}

int bsbswim_entrypoint_5(s32 param_0)
{
  return D_80801EB0_bsbswim[param_0];
}

s32 func_80800DFC_bsbswim(s32 param_0) {
    _babounce_entrypoint_3();
    func_800961AC(param_0, 3);
    func_80800104_bsbswim(param_0);
}

void func_80800E30_bsbswim(Actor *param_0)
{
  int new_var;
  func_80800030_bsbswim();
  func_800961AC(param_0, 1);
  new_var = 0x3F15119D;
  _babounce_entrypoint_4(param_0, 2);
  _babounce_entrypoint_5(param_0, 0xf, new_var);
}

int func_80800E7C_bsbswim(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_babounce_entrypoint_9())
  {
    local_0 = 0x2B;
  }
  bs_setState(param_0, local_0);
}

int bsbswim_entrypoint_6(s32 param_0)
{
  return D_80801EC0_bsbswim[param_0];
}

void func_80800EC8_bsbswim(u8 *param_0)
{
  s8 *new_var5;
  u8 *new_var4;
  unsigned short new_var2;
  unsigned int new_var3;
  u8 *new_var;
  new_var2 = 0x3C;
  func_800C6DA0(0x3F);
  baanim_playForDuration_onceSmooth(param_0, new_var2, 0x3FC00000);
  func_80800000_bsbswim(param_0);
  yaw_setVelocityBounded(param_0, 0x43FA0000, 0x40A00000);
  new_var4 = new_var;
  func_8009B94C(param_0, 0);
  func_80800030_bsbswim(new_var = param_0);
  if (1)
  {
 ; new_var4 = new_var;
    _baswim_entrypoint_10(param_0, (double) 0);
    _baswim_entrypoint_8(new_var, 0x44160000);
    func_8009BFE4(new_var, 0x43480000, 0x40200000);
    new_var3 = 0x164;
    new_var5 = (s8 *) (((s8 *) param_0) + new_var3);
    func_8009D874(new_var4);
    *new_var5 = 0;
  }
}

void func_80800F64_bsbswim(u8 *param_0) {
    s32 local_0;
    s32 local_1;
    u8 local_2;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr();
    local_2 = *(u8 *)((char *)param_0 + 0x164);
    switch (local_2) {
    case 0:
        func_8009BF5C(param_0, 5e+01f);
        if (anctrl_isAt(local_1, 0.2916f) != 0) {
            if (_baswim_entrypoint_1(param_0) != 0) {
                func_800A0E64(param_0);
            }
            _baswim_entrypoint_10(param_0, 4e+02f);
            _baswim_entrypoint_8(param_0, 0x43960000);
            *(u8 *)((char *)param_0 + 0x164) = 1U;
        }
        break;
    case 1:
        _baswim_entrypoint_11(param_0);
        _baswim_entrypoint_13(param_0);
        if (anctrl_isAt(local_1, 0.58f) != 0) {
            local_0 = 0x2B;
        }
        break;
    }
    if (anctrl_isAt(local_1, 0.6f) != 0) {
        func_8009DE38(param_0, 0x3FD, 0x3F800000);
    }
    if (player_inWater(param_0) == 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

void func_80801084_bsbswim()
{
    func_80800104_bsbswim();
}

int bsbswim_entrypoint_7(s32 param_0)
{
  return D_80801ED0_bsbswim[param_0];
}

void func_808010B8_bsbswim(PlayerState *param_0)
{
    param_0->unk15C.word = func_8009E6C4(param_0, 4) || func_800F8B64();
    _basudie_entrypoint_1(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xB9, 0.7f);
    func_80800000_bsbswim(param_0);
    func_80800030_bsbswim(param_0);
    func_8009BC5C(param_0, 1.0f);
    func_8009B94C(param_0, 0);
    func_8009BA9C(param_0, 0);
    func_8009BF5C(param_0, 275.0f);
    baroll_setIdeal(param_0, 0.0f);
    func_8008E944(param_0);
    _batimer_set(param_0, 0, 0.0f);
    _batimer_set(param_0, 1, 0.0f);
    func_800910BC(param_0, 3);
    func_8009DF18(param_0, 0x467, 1.0f, 0x5DC0);
    _baswim_entrypoint_6(param_0, 0);
}

void func_808011C0_bsbswim(void *param_0)
{
    s32 local_3;
    f32 local_0[3];
    s32 local_1;
    f32 local_2[3];

    func_800EF4E4(local_0, -90.0, 0.0, 0.0, 0.0, 100.0);
    func_8009B94C(param_0, local_0);
    func_8009BA9C(param_0, local_0);
    _batimer_increment(param_0, 1);
    if (_batimer_isAt_rising(param_0, 1, 0.2) ||
        _batimer_isAt_rising(param_0, 1, 0.8) ||
        _batimer_isAt_rising(param_0, 1, 1.4)) {
        func_8009DF18(param_0, 0x468, 1.0, 0x5DC0);
    }
    local_3 = func_8001210C(1);
    if (!local_3) {
        func_8009C128(param_0, local_2);
        local_2[1] += 60.0f;
        local_1 = func_8009FBB0(param_0, local_2, 25.0f);
        func_800BA930(local_1, -60, -50, -60, 60, 100, 60);
        func_800BA22C(local_1, 1);
    }
    if (_batimer_isGreaterThan(param_0, 1, 1.55)) {
        baphysics_set_vertical_velocity(param_0, -50.0);
    }
    if (_batimer_isAt_rising(param_0, 1, 1.9)) {
        func_800A4DA4(param_0, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(param_0), 80.0);
        if (*(s32 *)((u8 *)param_0 + 0x15C)) {
            _batimer_set(param_0, 0, 0.5f);
        } else {
            func_800A0180(param_0);
            _batimer_set(param_0, 0, 3.5f);
        }
    }
    if (_batimer_decrement(param_0, 0)) {
        _basudie_entrypoint_0(param_0);
    }
    bs_setState(param_0, 0);
}

s32 func_808013C4_bsbswim(f32 param_0[3]){
    _baswim_entrypoint_6(param_0, 1);
    func_800910BC(param_0, 1);
    func_800A4E30(param_0);
    func_8008E95C(param_0);
    func_80800104_bsbswim(param_0);
}

int bsbswim_entrypoint_8(s32 param_0)
{
  return D_80801EE0_bsbswim[param_0];
}

void func_80801428_bsbswim(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0x70, 2.0f);
    func_80800000_bsbswim(param_0);
    func_8009B94C(param_0, 0);
    _baswim_entrypoint_9(param_0, 0.0f);
    func_8009BA9C(param_0, 0);
    func_80800030_bsbswim(param_0);
    func_800A0024(param_0);
    _baswim_entrypoint_6(param_0, 0);
}

void func_808014A0_bsbswim(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_800A0024();
    if (player_inWater(param_0) == 0) {
        local_0 = 0x74;
    }
    if (func_8009CC68(param_0) == 0) {
        local_0 = 0x2B;
    }
    bs_setState(param_0, local_0);
}

void func_808014F8_bsbswim(s32 arg0)
{
    _baswim_entrypoint_6(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

int bsbswim_entrypoint_9(s32 param_0)
{
  return D_80801EF0_bsbswim[param_0];
}

void func_80801538_bsbswim(PlayerState *param_0)
{
    void *local_2;
    f32 local_0;
    local_2 = baanim_getAnimCtrlPtr(param_0);
    func_80800030_bsbswim(param_0);
    func_800A046C(param_0);
    local_0 = func_800A3298(param_0);
    if (bs_getPreviousState(param_0) == 15) local_0 = func_800F0E00(local_0, 600.0f);
    if (local_0 > 80.0f) {
        anctrl_reset(local_2);
        anctrl_setIndex(local_2, 0xEA);
        anctrl_setPlaybackType(local_2, 3);
        anctrl_setDuration(local_2, 1.2f);
        anctrl_setStart(local_2, 0.8204f);
        anctrl_start(local_2);
    } else {
        anctrl_reset(local_2);
        anctrl_setIndex(local_2, 0x57);
        anctrl_setPlaybackType(local_2, 2);
        anctrl_setDuration(local_2, 1.2f);
        anctrl_setStart(local_2, 0.6412f);
        anctrl_start(local_2);
    }
    local_0 = func_800F10B4(local_0, 40.0f, 1000.0f, -300.0f, -1200.0f);
    *(f32 *)((u8 *)param_0 + 0x178) = local_0;
    baphysics_set_vertical_velocity(param_0, local_0);
    func_8009FFD8(param_0, 1, 3, 3, 9);
    baphysics_set_type(param_0, 6);
}

void func_808016B8_bsbswim(u8 *param_0)
{
    s32 local_0;
    f32 local_1[3];
    s32 local_2;

    local_0 = 0;
    func_8009C128(param_0, local_1);
    local_1[1] += 60.0f;
    local_2 = func_8009FBB0(param_0, local_1, 20.0f);
    func_800BA930(local_2, -30, -30, -30, 30, 30, 30);
    func_800BA22C(local_2, 1);
    if (*(f32 *)(param_0 + 0x178) < 0.0f) {
        *(f32 *)(param_0 + 0x178) += func_800F0E00(mlAbsF(*(f32 *)(param_0 + 0x178)) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(param_0, *(f32 *)(param_0 + 0x178));
    }
    if (player_isStable(param_0)) {
        local_0 = 0x2D;
    }
    if (!player_inWater(param_0)) {
        local_0 = 1;
    }
    if (baphysics_get_vertical_velocity(param_0) >= 0.0f) {
        local_0 = 0x2D;
    }
    bs_setState(param_0, local_0);
}

void func_808017F8_bsbswim()
{
    func_80800104_bsbswim();
}

int bsbswim_entrypoint_10(s32 param_0)
{
  return D_80801F00_bsbswim[param_0];
}

int func_8080182C_bsbswim(Actor *param_0)
{
  func_80800030_bsbswim();
  _bsdrone_entrypoint_0(param_0);
  func_8009BF5C(param_0, 0);
  baroll_setIdeal(param_0, 0);
}

int func_8080186C_bsbswim(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_badrone_entrypoint_30())
  {
    local_0 = 0xBB;
  }
  _bsdrone_entrypoint_1(param_0);
  bs_setState(param_0, local_0);
}

void func_808018B0_bsbswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800104_bsbswim(arg0);
}
int bsbswim_entrypoint_11(s32 param_0)
{
  return D_80801F10_bsbswim[param_0];
}

s32 func_808018EC_bsbswim(s32 param_0){
    if(func_8009E6EC() == 0x11){
        func_80099B94(param_0);
    }
    else{
        func_80099AA8(param_0);
    }
}

int func_80801930_bsbswim(u8 *param_0)
{
  if (param_0[0x165]) {
    _baduo_entrypoint_7(param_0, 3);
  }
  func_80800104_bsbswim(param_0);
}

void func_8080196C_bsbswim(PlayerState *param_0)
{
    func_80800030_bsbswim();
    baanim_playForDuration_onceSmooth(param_0, 0x131, 0x3FC00000);
    func_80800000_bsbswim(param_0);
    func_8009B94C(param_0, 0);
    func_8009BA9C(param_0, 0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    *((u8 *)param_0 + 0x165) = 0;
}

void func_808019E0_bsbswim(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1[3];
    s32 local_2;
    local_0 = 0;
    if (baanim_isAt(param_0, 0.21f)) {
        func_800A0CF4(param_0, 0);
        _baduo_entrypoint_21(param_0);
        func_800A3410(param_0, 10);
        *(u8 *)((u8 *)param_0 + 0x165) = 1;
        func_8009C128(param_0, local_1);
        local_1[1] += 60.0f;
        local_2 = func_8009FBB0(param_0, local_1, 70.0f);
        func_800BABB8(local_2, local_1, local_1, 1.0f, D_80801F20_bsbswim);
        func_8009DF18(param_0, 0x4592, 1.0f, 0x55F0);
        local_0 = 0xED;
    }
    bs_setState(param_0, local_0);
}

int bsbswim_entrypoint_12(s32 param_0)
{
  return D_80801F78_bsbswim[param_0];
}

void func_80801ACC_bsbswim(u8 *param_0) {
    s32 local_0;

    local_0 = func_8009E6EC();
    switch (local_0) {
    case 0x71:
        (*(u8 *)((s8 *)(param_0) + (0x167))) = 1U;
        func_8009E830(param_0, 2);
        return;
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x24:
    case 0x2D:
    case 0x2E:
    case 0x31:
    case 0x33:
    case 0x4E:
    case 0x51:
    case 0x52:
    case 0x68:
    case 0x6F:
        if ((*(u8 *)((s8 *)(param_0) + (0x167))) == 0) {
            func_800F9BC4(param_0);
            func_80099B94(param_0);
            return;
        }
        return;
    default:
        func_80099B94(param_0);
        break;
    }
}

void func_80801B84_bsbswim(PlayerState *param_0)
{
    ((u8 *)param_0)[0x167] = 0;
    baanim_playForDuration_loopSmooth(param_0, 0x70, 2.0f);
    func_80800000_bsbswim(param_0);
    func_8009B94C(param_0, 0);
    _baswim_entrypoint_9(param_0, 0.0f);
    func_8009BA9C(param_0, 0);
    func_80800030_bsbswim(param_0);
    _baswim_entrypoint_6(param_0, 0);
    func_80091104(param_0, 0);
}

void func_80801C04_bsbswim(s32 arg0) 
{
}
s32 func_80801C0C_bsbswim(Actor *this) {
    func_80091104(this, 1);
    _baswim_entrypoint_7(this, 1, 1);
    func_8009679C(this);
    func_80800104_bsbswim(this);
}

int bsbswim_entrypoint_13(s32 param_0)
{
  return D_80801F88_bsbswim[param_0];
}

s32 func_80801C64_bsbswim(s32 param_0)
{
  func_80800030_bsbswim();
  baanim_playForDuration_once(param_0, 0x136, 0.6f);
  func_80800000_bsbswim(param_0);
  func_8009B94C(param_0, 0);
  func_8009BA9C(param_0, 0);
  func_8009BF5C(param_0, 0);
  baroll_setIdeal(param_0, 0);
  func_800A0CF4(param_0, 1);
}

int func_80801CE4_bsbswim(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if ((baanim_isStopped() != 0) || (_baswim_entrypoint_3(param_0) != 0))
  {
    local_0 = 0x2B;
  }
  bs_setState(param_0, local_0);
}

void func_80801D30_bsbswim()
{
    func_80800104_bsbswim();
}

int bsbswim_entrypoint_14(s32 param_0)
{
  return D_80801F98_bsbswim[param_0];
}
