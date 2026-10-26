#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern s32 bastick_getZone(PlayerState *);
extern f32 bastick_getZonePosition(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void bainput_enable(PlayerState *, s32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern s32 D_80800CB0_bsbanshack[];
extern s32 D_80800CC0_bsbanshack[];
void anctrl_setSubrange(s32, f32, s32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 D_80800CD0_bsbanshack[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern f32 func_800DC0C0(void);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80800CE0_bsbanshack[];
extern s32 D_80800CF0_bsbanshack[];
extern s32 D_80800D00_bsbanshack[];
extern s32 D_80800D10_bsbanshack[];

s32 func_80800000_bsbanshack(PlayerState *param_0, s32 param_1)
{
    if (bakey_pressed(param_0, 8)) param_1 = 0x16E;
    if (func_8008E148(param_0)) param_1 = 1;
    if (func_8008E260(param_0)) param_1 = 0x3D;
    if (bakey_released(param_0, 1)) param_1 = 0x16B;
    return param_1;
}

int func_80800074_bsbanshack(PlayerState *param_0, unsigned int param_1)
{
    if (bastick_getZone(param_0) > 0) {
        param_1 = 0x16D;
    }
    if (bakey_pressed(param_0, 8)) {
        param_1 = 0x16E;
    }
    if (func_8008E148(param_0)) {
        param_1 = 1;
    }
    if (func_8008E260(param_0)) {
        param_1 = 0x3D;
    }
    if (bakey_released(param_0, 1)) {
        param_1 = 0x16B;
    }
    return param_1;
}

void func_80800100_bsbanshack(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 300.0f));
    }
}

int func_80800164_bsbanshack(param_0) Actor *param_0;
{
  if (func_8009E74C(param_0, 0x13))
  {
    if (_babackpack_get_state(param_0) != 5)
    {
      _babackpack_set_state(param_0, 5);
    }
  }
  else
  {
    if (_babackpack_get_state(param_0) != 1)
    {
      _babackpack_set_state(param_0, 1);
    }
    func_800A0CD0(param_0, 1);
    if (bs_getCurrentState(param_0) != 0x16B)
    {
      baanim_playForDuration_once(param_0, 0x6F, 0x40B00000);
      func_8008CA98(param_0);
    }
    func_80095A40(param_0);
    bastick_popZone(param_0);
  }
}

int func_8080021C_bsbanshack(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_8009E77C(local_0, 0x13))
  {
    _babackpack_set_state(local_0, 5);
    func_800A0CD0(local_0, 0);
    bastick_pushZone(local_0);
    bastick_setZoneMax(local_0, 0, 0x3DF5C28F);
    bastick_setZoneMax(local_0, 1, 0x3F800000);
    func_800959C8(local_0, 0x42540000, 0x41c80000);
    func_8009590C(local_0, 0x42540000);
  }
}

int func_808002AC_bsbanshack(u8 *param_0)
{
  if (param_0[0x15D])
  {
    if ((param_0 && param_0) && param_0)
    {
    }
    func_80800164_bsbanshack();
  }
  else
    if (_babackpack_get_state() != 1)
  {
    func_800A0CD0(param_0, 1);
    _babackpack_set_state(param_0, 1);
  }
}

void func_8080030C_bsbanshack(PlayerState *param_0)
{
    param_0->unk15C.bytes[1] = 0;
    baanim_playForDuration_onceSmooth(param_0, 0x145, 1.4f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    bainput_enable(param_0, 5, 0);
}

void func_8080037C_bsbanshack(PlayerState *param_0)
{
    s32 local_0 = 0;

    bainput_enable(param_0, 5, 1);
    if (baanim_isAt(param_0, 0.31f)) {
        func_8009DBF0(param_0, 0x3FF, 0.9f);
    }
    if (baanim_isAt(param_0, 0.1976f)) {
        param_0->unk15C.bytes[1] = 1;
        func_8080021C_bsbanshack(param_0);
    }
    if (baanim_isStopped(param_0)) {
        local_0 = 0x16C;
    }
    bs_setState(param_0, local_0);
}

int bsbanshack_entrypoint_0(s32 param_0)
{
  return D_80800CB0_bsbanshack[param_0];
}

void func_80800430_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800450_bsbanshack(Actor *param_0)
{
  Actor *new_var;
  s32 local_0;
  new_var = param_0;
  func_8080021C_bsbanshack();
  baanim_playForDuration_onceSmooth(new_var, 0x295, 1.4f);
  local_0 = 2;
  func_8009FFD8(new_var, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(new_var, 0x0 & 0xFFFFFFFFFFFFFFFF);
}

void func_808004AC_bsbanshack(s32 param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_2 = baanim_getAnimCtrlPtr();
    local_1 = local_2;
    if (anctrl_isAt(local_2, 0x3E947AE1) != 0) {
        func_8009DEC0(param_0, 0x583, 0x3F733333, 0x3F866666, 0x55F0, 0x55F0);
    }
    if (anctrl_isAt(local_1, 0x3F3D70A4) != 0) {
        func_8009DEC0(param_0, 0x584, 0x3F733333, 0x3F866666, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(param_0, 0.1351f) != 0) {
        baphysics_set_vertical_velocity(param_0, 0x44160000);
    }
    if (baanim_isAt(param_0, 0.6757f) != 0) {
        _babackpack_set_state(param_0, 1);
        func_800A0CD0(param_0, 1);
    }
    if (baanim_isStopped(param_0) != 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

int bsbanshack_entrypoint_1(s32 param_0)
{
  return D_80800CC0_bsbanshack[param_0];
}

void func_808005DC_bsbanshack(void *param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  switch (param_1)
  {
    case 0:
      baphysics_reset_gravity(param_0);
      break;

    case 1:
      local_1 = baanim_getAnimCtrlPtr(param_0);
      local_0 = local_1;
      *((s32 *) (((char *) param_0) + 0x160)) = 0;
      anctrl_reset(local_1);
      anctrl_setIndex(local_0, 0x294);
      anctrl_setDuration(local_0, 0x3F800000);
      func_8008B1C8(local_0, 0x3E09374C);
      anctrl_setStart(local_0, 0x3E0F5C29);
      anctrl_setSubrange(local_0, 0, 0x3F333333 & 0xFFFFFFFFFFFFFFFF);
      anctrl_setPlaybackType(local_0, 1);
      anctrl_start(local_0);
      func_8009FFD8(param_0, 1, 1, 1, 2);
      baphysics_set_vertical_velocity(param_0, 0x44188000);
      baphysics_set_gravity(param_0, 0xC47A0000);
      func_8009DF18(param_0, 0x589, 1.0f, 0x3A98);
      break;

    case 2:
      baanim_setEndAndDuration(param_0, 0x3F4F5C29, 0x404CCCCD);
      break;

    case 3:
      baanim_setEndAndDuration(param_0, 0x3F800000, 0x3F4CCCCD);
      break;

  }

  *((s8 *) (((char *) param_0) + 0x15C)) = (s8) param_1;
}

void func_80800744_bsbanshack(s32 arg0)
{
    func_808005DC_bsbanshack(arg0,0);
    func_80800164_bsbanshack(arg0);
}

void func_80800770_bsbanshack(s32 param_0) {
    func_8080021C_bsbanshack(param_0);
    *(u8 *)(param_0 + 0x15C) = 0;
    func_808005DC_bsbanshack(param_0, 1);
}

void func_808007A0_bsbanshack(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    if (bakey_released(param_0, 8) && baphysics_get_vertical_velocity(param_0) > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    switch (*((u8 *)param_0 + 0x15C)) {
    case 1:
        func_80800100_bsbanshack(param_0);
        if (baanim_isStopped(param_0)) func_808005DC_bsbanshack(param_0, 2);
        if (func_8008DF8C(param_0, 0x5A)) func_808005DC_bsbanshack(param_0, 3);
        break;
    case 2:
        func_80800100_bsbanshack(param_0);
        if (func_8008DF8C(param_0, 0x5A)) func_808005DC_bsbanshack(param_0, 3);
        break;
    case 3:
        if (player_isStable(param_0)) {
            if (*(s32 *)((u8 *)param_0 + 0x160) == 0) {
                (*(s32 *)((u8 *)param_0 + 0x160))++;
                func_8009FE58(param_0);
            }
            if (baanim_isStopped(param_0)) local_0 = 0x16C;
            local_0 = func_80800074_bsbanshack(param_0, local_0);
            if (local_0 == 0) baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        }
        break;
    }
    if (func_8008E260(param_0)) local_0 = 0x3D;
    bs_setState(param_0, local_0);
}

int bsbanshack_entrypoint_2(s32 param_0)
{
  return D_80800CD0_bsbanshack[param_0];
}

void func_80800928_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800948_bsbanshack(PlayerState *param_0)
{
    func_8080021C_bsbanshack(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x146, 0.7f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.1f, 5.0f);
    func_8008C9F0(param_0, 30.0f, 300.0f, 0.8f, 0.5f);
    func_8008CA30(param_0, 1.0f);
}

void func_808009E4_bsbanshack(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_80800100_bsbanshack(param_0);
    func_800A2CE8(param_0, 0.25f, 4);
    func_800A2CE8(param_0, 0.75f, 3);
    if (baanim_isAt(param_0, 0.51f)) {
        func_8009DF18(param_0, func_800DC0C0() < 0.5f ? 0x58A : 0x58B, 1.0f, 0x1388);
    }
    if (bastick_getZone(param_0) == 0 && func_8009BCD4(param_0, 3.0f)) local_0 = 0x16C;
    bs_setState(param_0, func_80800000_bsbanshack(param_0, local_0));
}

int bsbanshack_entrypoint_3(s32 param_0)
{
  return D_80800CE0_bsbanshack[param_0];
}

void func_80800AD0_bsbanshack(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800164_bsbanshack(arg0);
}
void func_80800AF8_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800B20_bsbanshack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
int bsbanshack_entrypoint_4(s32 param_0)
{
  return D_80800CF0_bsbanshack[param_0];
}

void func_80800B54_bsbanshack(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800164_bsbanshack(arg0);
}
void func_80800B7C_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsrest_entrypoint_16(arg0);
}
int func_80800BA4_bsbanshack(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 = 0x16C;
  }
  bs_setState(param_0, local_0);
}

int bsbanshack_entrypoint_5(s32 param_0)
{
  return D_80800D00_bsbanshack[param_0];
}

void func_80800BF0_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800C10_bsbanshack(s32 param_0)
{
  s32 *new_var;
  func_8080021C_bsbanshack();
  baanim_playForDuration_loopSmooth(param_0, 0x293, 5.4f);
  {
  }
  func_8009FFD8(param_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(*(new_var = &param_0), (double) 0);
}

s32 func_80800C6C_bsbanshack(s32 param_0){
    s32 next_state = func_80800074_bsbanshack(param_0, 0);
    bs_setState(param_0, next_state | 0x20000000 & 0xFF);
}

int bsbanshack_entrypoint_6(s32 param_0)
{
  return D_80800D10_bsbanshack[param_0];
}
