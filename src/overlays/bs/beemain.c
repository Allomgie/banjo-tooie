#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern s32 D_80801260_bsbeemain[];
extern s32 D_80801270_bsbeemain[];
extern void _bsbee_entrypoint_1();
extern void anctrl_reset(void *);
extern void anctrl_setSmoothTransition(void *, int);
extern void anctrl_setIndex(void *, int);
extern void anctrl_setSubrange(void *, f32, f32);
extern void anctrl_setStart(void *, int);
extern void anctrl_setDuration(void *, f32);
extern void anctrl_setPlaybackType(void *, int);
extern void anctrl_start(void *);
extern float bastick_distance(Actor *);
extern float bastick_getAngleRelativeToBanjo(Actor *);
extern float yaw_getIdeal(Actor *);
extern s32 D_80801280_bsbeemain[];
extern void *baanim_getAnimCtrlPtr();
extern void func_8009BB24();
extern s32 D_80801290_bsbeemain[];
extern void _babounce_entrypoint_4(s32, s32);
extern void _babounce_entrypoint_5(s32, s32, f32);
extern void _bsbee_entrypoint_2();
extern s32 _babounce_entrypoint_9(s32);
extern void bs_setState(s32, s32);
extern s32 D_808012A0_bsbeemain[];
extern s32 D_808012B0_bsbeemain[];
extern f32 func_800136E4(f32);
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(Actor *, int);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009D820(PlayerState *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void _ncbadie_entrypoint_3(PlayerState *, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern f32 func_800F0E00(f32, f32);
extern void func_8009D3A8(PlayerState *, s32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern f32 func_80099A34(Actor *);
extern void func_8009BDAC(Actor *, f32);
extern s32 D_808012C0_bsbeemain[];
extern s32 D_808012D0_bsbeemain[];
extern s32 D_808012E0_bsbeemain[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void baanim_playForDuration_loopStartingAt(PlayerState *, s32, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_800909CC(PlayerState *);

int func_80800000_bsbeemain(int param_0)
{
  int new_var;
  unsigned int new_var2;
  new_var = 0;
  new_var2 = (new_var = 0x1F40);
  func_8009DF18(param_0, 0x41F, 1.4f, new_var2);
}

void func_8080002C_bsbeemain(int param_0)
{
  int new_var;
  new_var = new_var * 0;
  func_8009D7A4(param_0, 0x3FACCCCD, 0x3FB9999A);
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800058_bsbeemain(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 375.0f));
    }
}

void func_808000C0_bsbeemain(Actor *param_0) {
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  _bsbee_entrypoint_1(param_0);
  baanim_playForDuration_loopSmooth(param_0, 0x1DE, 3.0f);
  func_8009FFD8(param_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  func_800909CC(param_0);
}

void func_80800128_bsbeemain(s32 param_0)
{
  unsigned int local_1 = 0;
  _bsbee_entrypoint_2(param_0);
  func_8009D3A8(param_0, 0);
  if (func_8008DD04(param_0) != 0)
  {
    local_1 = 0x88;
  }
  if (bakey_held(param_0, 1) != 0)
  {
    _babee_entrypoint_2(param_0);
  }
  if (bainput_should_enter_first_person(param_0) != 0)
  {
    local_1 = _badrone_entrypoint_24(param_0);
  }
  if (bastick_getZone(param_0) > 0)
  {
    local_1 = 0x86;
  }
  if (bakey_pressed(param_0, 8) != 0)
  {
    local_1 = 0x87;
  }
  if (player_inWater(param_0) != 0)
  {
    local_1 = 0x8C;
  }
  bs_setState(param_0, func_800A02DC(param_0, local_1));
}

void func_808001FC_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
int bsbeemain_entrypoint_0(s32 param_0)
{
  return D_80801260_bsbeemain[param_0];
}

void func_80800238_bsbeemain(PlayerState *param_0)
{
    _bsbee_entrypoint_1(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1DD, 0.38f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    func_8008C9F0(param_0, 30.0f, 375.0f, 0.6f, 0.4f);
    func_800909CC(param_0);
}

void func_808002C0_bsbeemain(s32 param_0) {
    s32 sp24;

    sp24 = 0;
    _bsbee_entrypoint_2();
    func_8009D3A8(param_0, 0);
    func_80800058_bsbeemain(param_0);
    func_800A2CE8(param_0, 0x3F70A3D7, 4);
    func_800A2CE8(param_0, 0x3EE147AE, 3);
    if (bakey_held(param_0, 1) != 0) {
        _babee_entrypoint_2(param_0);
    }
    if ((bastick_getZone(param_0) == 0) && (func_8009BCD4(param_0, 0x3F800000) != 0)) {
        sp24 = 0x85;
    }
    if (func_8008DD04(param_0) != 0) {
        sp24 = 0x88;
    }
    if (bakey_pressed(param_0, 8) != 0) {
        sp24 = 0x87;
    }
    if (player_inWater(param_0) != 0) {
        sp24 = 0x8C;
    }
    bs_setState(param_0, sp24);
}

void func_808003B4_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
int bsbeemain_entrypoint_1(s32 param_0)
{
  return D_80801270_bsbeemain[param_0];
}

void func_808003F0_bsbeemain(Actor *param_0)
{
    s8 _sfpad[8];
    f32 local_0;
    void *temp_s0;

    temp_s0 = baanim_getAnimCtrlPtr();
    _bsbee_entrypoint_1(param_0);
    anctrl_reset(temp_s0);
    anctrl_setSmoothTransition(temp_s0, 0);
    anctrl_setIndex(temp_s0, 0x1E2);
    anctrl_setSubrange(temp_s0, 0.0f, 0.34f);
    anctrl_setStart(temp_s0, 0x3DCCCCCD);
    anctrl_setDuration(temp_s0, 1.2f);
    anctrl_setPlaybackType(temp_s0, 1);
    anctrl_start(temp_s0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) {
        yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    }
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800058_bsbeemain(param_0);
    local_0 = yaw_getIdeal(param_0);
    baphysics_set_horizontal_velocity(param_0, local_0, baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 693.5f);
    baphysics_set_gravity(param_0, 0xC4960000);
    func_8080002C_bsbeemain(param_0);
    (*(s32 *)((s8 *)(param_0) + (0x15C))) = 0;
}

int func_80800548_bsbeemain(void *param_0)
{
  s32 local_2 = 0;
  void *local_0;
  f32 local_1[3];
  local_0 = baanim_getAnimCtrlPtr(param_0);
  _bsbee_entrypoint_2(param_0);
  func_80800058_bsbeemain(param_0);
  func_8009BB24(param_0, local_1);
  if ((bakey_released(param_0, 8) != 0) && (local_1[1] > 0.0f))
  {
    baphysics_reset_gravity(param_0);
  }
  switch (*((s32 *) (((char *) param_0) + 0x15C)))
  {
    case 0:
      if (func_8008DF8C(param_0, 0x82) != 0)
    {
      baanim_setEndAndDuration(param_0, 0x3F370A3D, 0x3F333333);
      *((s32 *) (((char *) param_0) + 0x15C)) = 2;
    }
    else
      if (anctrl_isStopped(local_0) != 0)
    {
      baanim_setEndAndDuration(param_0, 0x3F028F5C, 0x40800000);
      *((s32 *) (((char *) param_0) + 0x15C)) = 1;
    }
      break;

    case 1:
      if (func_8008DF8C(param_0, 0x82) != 0)
    {
      baanim_setEndAndDuration(param_0, 0x3F370A3D, 0x3F99999A);
      *((s32 *) (((char *) param_0) + 0x15C)) = 2;
    }
      break;

    case 2:
      func_8009D3A8(param_0, 0);
      if (player_isStable(param_0) != 0)
    {
      func_80800000_bsbeemain(param_0);
      baanim_setEndAndDuration(param_0, 0x3F800000, 0x3F333333);
      *((s32 *) (((char *) param_0) + 0x15C)) = 3;
    }
      break;

    case 3:
      func_8009D3A8(param_0, 0);
      if (anctrl_isStopped(local_0) != 0)
    {
      baphysics_set_target_horizontal_velocity(param_0, 0.0f);
      local_2 = 0x85;
    }
      break;

  }

  if (bakey_held(param_0, 1) != 0)
  {
    _babee_entrypoint_2(param_0);
  }
  if (player_isStable(param_0) != 0)
  {
    if (bastick_getZone(param_0) > 0)
    {
      local_2 = 0x86;
    }
    if (0 != bakey_pressed(param_0, 8))
    {
      local_2 = 0x87;
    }
  }
  else
    if (bakey_pressed(param_0, 8) != 0)
  {
    local_2 = 0x8C;
  }
  if (player_inWater(param_0) != 0)
  {
    local_2 = 0x8C;
  }
  bs_setState(param_0, local_2);
}

void func_80800788_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_0();
    baphysics_reset_gravity(arg0);
}
int bsbeemain_entrypoint_2(s32 param_0)
{
  return D_80801280_bsbeemain[param_0];
}

void func_808007C4_bsbeemain(PlayerState *param_0)
{
    void *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    _bsbee_entrypoint_1(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x1E2);
    anctrl_setStart(local_0, 0x3EAE147B);
    anctrl_setDuration(local_0, 8.0f);
    anctrl_setSubrange(local_0, 0.0f, 0.51f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    param_0->unk15C.word = 0;
}

void func_80800874_bsbeemain(u8 *param_0) {
    s32 sp34;
    s32 sp30;
    s32 sp24;
    s32 temp_v0;

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr();
    _bsbee_entrypoint_2(param_0);
    func_8009D3A8(param_0, 0);
    func_80800058_bsbeemain(param_0);
    func_8009BB24(param_0, (s32 *)((s8 *)&sp24 - 8));
    temp_v0 = (*(s32 *)((s8 *)(param_0) + (0x15C)));
    switch (temp_v0) {
    case 0:
        if (func_8008DF8C(param_0, 0x82) != 0) {
            baanim_setEndAndDuration(param_0, 0x3F370A3D, 0x3F333333);
            (*(s32 *)((s8 *)(param_0) + (0x15C))) = 1;
        }
        break;
    case 1:
        func_8009D3A8(param_0, 0);
        if (player_isStable(param_0) != 0) {
            func_80800000_bsbeemain(param_0);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            baanim_setEndAndDuration(param_0, 0x3F800000, 0x3F333333);
            (*(s32 *)((s8 *)(param_0) + (0x15C))) = 2;
        }
        break;
    case 2:
        func_8009D3A8(param_0, 0);
        if (anctrl_isStopped(sp30) != 0) {
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            sp34 = 0x85;
        }
        break;
    }
    if (bakey_held(param_0, 1) != 0) {
        _babee_entrypoint_2(param_0);
    }
    if (player_isStable(param_0) != 0) {
        if (baflag_isTrue(param_0, 0x19) != 0) {
            sp34 = _badrone_entrypoint_28(param_0);
        } else {
            if (bastick_getZone(param_0) > 0) {
                sp34 = 0x86;
            }
            if (bakey_pressed(param_0, 8) != 0) {
                sp34 = 0x87;
            }
            sp34 = func_800A02DC(param_0, sp34);
        }
    } else if ((baflag_isFalse(param_0, 0xF) != 0) && (bakey_pressed(param_0, 8) != 0)) {
        sp34 = 0x8C;
    }
    if (player_inWater(param_0) != 0) {
        sp34 = 0x8C;
    }
    bs_setState(param_0, sp34);
}

void func_80800A74_bsbeemain()
{
    _bsbee_entrypoint_0();
}

int bsbeemain_entrypoint_3(s32 param_0)
{
  return D_80801290_bsbeemain[param_0];
}

void bsbeemain_entrypoint_4(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void bsbeemain_entrypoint_5(s32 param_0) {
    _bsbee_entrypoint_1(param_0);
    _babounce_entrypoint_4(param_0, 1);
    _babounce_entrypoint_5(param_0, 0x1E0, 0.751800000667572f);
}

void bsbeemain_entrypoint_6(s32 param_0) {
    s32 local_0 = 0;
    _bsbee_entrypoint_2(param_0);
    if (_babounce_entrypoint_9(param_0) != 0) {
        local_0 = 0x85;
    }
    bs_setState(param_0, local_0);
}

int bsbeemain_entrypoint_7(s32 param_0)
{
  return D_808012A0_bsbeemain[param_0];
}

void func_80800B68_bsbeemain(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
int func_80800B90_bsbeemain(Actor *param_0)
{
  _bsbee_entrypoint_1();
  _babounce_entrypoint_4(param_0, 2);
  _babounce_entrypoint_5(param_0, 0x1E0, 0.7518f);
}

int func_80800BD0_bsbeemain(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  _bsbee_entrypoint_2();
  if (_babounce_entrypoint_9(param_0))
  {
    local_0 = 0x85;
  }
  bs_setState(param_0, local_0);
}

int bsbeemain_entrypoint_8(s32 param_0)
{
  return D_808012B0_bsbeemain[param_0];
}

void func_80800C28_bsbeemain(PlayerState *param_0)
{
    void *local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];

    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk160.word = func_800EA068(0x40);
    if (param_0->unk160.word) {
        func_800FC660(0x19);
    } else {
        _basudie_entrypoint_1(param_0);
        func_8008E944(param_0);
        func_8009514C(param_0);
        func_800A4DA4(param_0, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(param_0), 30.0f);
        func_800A0180(param_0);
    }
    _bsbee_entrypoint_1(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x1E1);
    anctrl_setSubrange(local_0, 0.0f, 0.3966f);
    anctrl_setDuration(local_0, 1.7f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 2, 3);
    func_8009C128(param_0, local_2);
    func_800A32C4(param_0, local_3);
    func_800F1E6C(local_3, local_2, &local_1);
    yaw_setIdeal(param_0, func_800136E4(local_1 + 180.0f));
    yaw_applyIdeal(param_0);
    param_0->unk16C = 250.0f;
    baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
    baphysics_set_target_yaw(param_0, local_1);
    baphysics_set_horizontal_velocity(param_0, local_1, baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 420.0f);
    baphysics_set_gravity(param_0, 0xC4960000);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    func_8009D820(param_0, 1.8f);
    _batimer_set(param_0, 0, 2.9f);
    param_0->unk15C.word = 0;
}

void func_80800E0C_bsbeemain(PlayerState *param_0)
{
    _bsbee_entrypoint_2(param_0);
    baphysics_set_target_horizontal_velocity(param_0, *(f32 *)((u8 *)param_0 + 0x16C));
    func_8009D3A8(param_0, 0);
    switch ((int)param_0->unk15C.word) {
    case 0:
        if (player_isStable(param_0)) {
            baanim_setEnd(param_0, 0.7453f);
            func_8009DF18(param_0, 0x417, 0.8f, 18000);
            func_8009DF18(param_0, 0x428, 1.8f, 18000);
            baphysics_set_vertical_velocity(param_0, 400.0f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (player_isStable(param_0)) {
            baanim_setEnd(param_0, 1.0f);
            func_8009DF18(param_0, 0x417, 0.8f, 18000);
            func_8009DF18(param_0, 0x428, 1.8f, 18000);
            *(s32 *)((u8 *)param_0 + 0x15C) = 2;
        }
        break;
    case 2: *(s32 *)((u8 *)param_0 + 0x15C) = 3; break;
    case 3:
        if (*(f32 *)((u8 *)param_0 + 0x16C) > 0.0f) *(f32 *)((u8 *)param_0 + 0x16C) = func_800F0E00(0.0f, *(f32 *)((u8 *)param_0 + 0x16C) - 10.0f);
        break;
    }
    if (_batimer_decrement(param_0, 0)) {
        if (*(s32 *)((u8 *)param_0 + 0x160)) func_80101180(0x2C4, 0x71, *(s32 *)((u8 *)param_0 + 0x184));
        else _basudie_entrypoint_0(param_0);
    }
    bs_setState(param_0, 0);
}

int func_80800FB8_bsbeemain(Actor *param_0)
{
  baphysics_reset_gravity();
  func_800A4E30(param_0);
  func_800951B4(param_0);
  _bsbee_entrypoint_0(param_0);
}

int func_80800FF0_bsbeemain(Actor *param_0)
{
    s32 local_0;
    Actor *local_1 = param_0;
    local_0 = func_8009E6EC();
    if (local_0 == 0x83) {
        func_8009BDAC(local_1, func_80099A34(local_1));
        func_80093370(local_1, 1);
        bs_setState(local_1, 0x85);
        func_8009E830(local_1, 2);
    } else {
        _basudie_entrypoint_11(local_1);
    }
}

int bsbeemain_entrypoint_9(s32 param_0)
{
  return D_808012C0_bsbeemain[param_0];
}

void func_80801080_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
int func_808010A8_bsbeemain(s32 param_0)
{
  s32 local_0;
  local_0 = 0;
  _bsbee_entrypoint_2();
  if (_bsrest_entrypoint_20(param_0))
  {
    local_0 = _bsrest_entrypoint_13(param_0);
  }
  bs_setState(param_0, local_0);
}

void func_808010F4_bsbeemain(s32 arg0)
{
    _bsrest_entrypoint_14();
    _bsbee_entrypoint_0(arg0);
}
int bsbeemain_entrypoint_10(s32 param_0)
{
  return D_808012D0_bsbeemain[param_0];
}

int func_80801130_bsbeemain(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _bsbee_entrypoint_1(local_0);
  _bsdrone_entrypoint_0(local_0);
  if (_badrone_entrypoint_3(local_0) == 2)
  {
    _bafpctrl_entrypoint_10(local_0, 1);
    func_800947EC(local_0, 2, 1);
  }
}

int func_8080118C_bsbeemain(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _bsbee_entrypoint_2(local_0);
  _bsdrone_entrypoint_1(local_0);
  if (_badrone_entrypoint_3(local_0) == 2 && bakey_held(local_0, 1))
  {
    _babee_entrypoint_2(local_0);
  }
}

int func_808011E8_bsbeemain(Actor *param_0)
{
  if (_badrone_entrypoint_3() == 2)
  {
    func_800947EC(param_0, 2, 0);
  }
  _bsdrone_entrypoint_2(param_0);
  _bsbee_entrypoint_0(param_0);
}

bsbeemain_entrypoint_11(param_0)
{
    return D_808012E0_bsbeemain[param_0];
}
