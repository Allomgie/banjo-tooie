#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/timer.h"
#include "overlays/ba/yaw.h"
#include "core2/1E76CC0.h"

extern s32 D_80800400_bsclaw[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);

int bsclaw_entrypoint_0(Actor *param_0)
{
  func_8009E474();
  func_800C6DA0(0x47);
  baflag_clear(param_0, 0x1F);
  func_800A0CF4(param_0, 0);
}

void bsclaw_entrypoint_1(PlayerState *param_0)
{
    f32 local_0;

    baanim_playForDuration_onceSmooth(param_0, 5, 1.4f);
    func_8009FFD8(param_0, 1, 1, 1, 2);
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    baphysics_set_target_horizontal_velocity(param_0, 80.0f);
    baflag_clear(param_0, 0x1F);
    func_800A0CF4(param_0, 1);
    if (func_800C6E38(0x32)) local_0 = 0.24f;
    else local_0 = 0.0f;
    _batimer_set(param_0, 0, local_0);
    func_8009E4AC(param_0);
    func_8009E5A4(param_0, 2, 3);
    func_8009E55C(param_0, 2, 40.0f);
}

void bsclaw_entrypoint_2(PlayerState *param_0)
{
  AnimCtrl *local_2;
  s32 local_0;
  f32 local_1;

  local_2 = baanim_getAnimCtrlPtr(param_0);
  local_0 = 0;
  local_1 = anctrl_getAnimTimer(local_2);
  if ((_batimer_get(param_0, 0) != 0.0f) && (bakey_pressed(param_0, 9) != 0)) {
    local_0 = 0x189;
  }
  _batimer_decrement(param_0, 0);
  if (anctrl_isAt(local_2, 0.512899995f)) {
    baphysics_set_horizontal_velocity(param_0, yaw_get(param_0), 360.0f);
  }
  if (anctrl_isAt(local_2, 0.653900027f) != 0) {
    baphysics_set_target_horizontal_velocity(param_0, 0);
  }
  if ((anctrl_isAt(local_2, 0.148800001f) != 0) || ((local_1 > 0.0488f) && (local_1 < 0.24880001f)) || (anctrl_isAt(local_2, 0.328799993f) != 0) || ((local_1 > 0.2288f) && (local_1 < 0.4288f)) || (anctrl_isAt(local_2, 0.578800023f) != 0) || ((local_1 > 0.47880003f) && (local_1 < 0.67880005f))) {
    baflag_set(param_0, 0x1F);
  } else {
    baflag_clear(param_0, 0x1F);
  }
  if (anctrl_isAt(local_2, 0.578800023f) != 0) {
    baphysics_set_target_horizontal_velocity(param_0, 0);
  }
  if (anctrl_isAt(local_2, 0.118799999f) != 0) {
    func_8009DE38(param_0, 0x442C, 1.13f);
  }
  if (anctrl_isAt(local_2, 0.288800001f) != 0) {
    func_8009DE38(param_0, 0x442C, 1.10000002f);
  }
  if (anctrl_isAt(local_2, 0.5f) != 0) {
    func_8009DE38(param_0, 0x442C, 1.32000005f);
  }
  if (anctrl_isStopped(local_2) != 0) {
    local_0 = 1;
  }
  if (player_inWater(param_0) != 0) {
    local_0 = 0x4C;
  }
  if (bakey_pressed(param_0, 8) != 0) {
    local_0 = bs_getTypeOfJump(param_0);
  }
  bs_setState(param_0, local_0);
}

int bsclaw_entrypoint_3(s32 param_0)
{
  return D_80800400_bsclaw[param_0];
}
