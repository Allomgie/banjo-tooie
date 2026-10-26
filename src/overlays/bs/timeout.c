#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_8009F308(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _ncbadie_entrypoint_3(s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009518C(PlayerState *, s32, f32);
extern s32 D_80800330_bstimeout[];
extern s32 D_80800340_bstimeout[];

void bstimeout_entrypoint_0(PlayerState *param_0)
{
    baanim_playForDuration_onceSmooth(param_0, 0x77, 3.2f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_800A4DA4(param_0, 10);
    yaw_setIdeal(param_0, func_8009F308(param_0) + 35.0f);
    _ncbadie_entrypoint_3(func_800A4CA8(param_0), 80.0f);
    func_800FC6B0(0x17);
    func_800A0CF4(param_0, 1);
    func_8008E944(param_0);
}

void bstimeout_entrypoint_1(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    if (anctrl_isAt(local_0, 0.0625f)) func_8009514C(param_0);
    if (anctrl_isAt(local_0, 0.18f)) func_8009DF18(param_0, 0x3EB, 1.0f, 0x4650);
    if (anctrl_isAt(local_0, 0.8421f)) {
        func_8009518C(param_0, 0, 0.3f);
        func_8009518C(param_0, 1, 0.3f);
    }
    if (anctrl_isAt(local_0, 0.84f)) func_800A05DC(param_0);
}

void bstimeout_entrypoint_2(s32 arg0)
{
    func_800951B4();
    func_800A4E30(arg0);
}
int bstimeout_entrypoint_3(s32 param_0)
{
  return D_80800330_bstimeout[param_0];
}

void bstimeout_entrypoint_4(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  int new_var;
  local_1 = baanim_getAnimCtrlPtr();
  local_0 = local_1;
  anctrl_reset(local_1);
  func_800A0110(param_0, local_0);
  anctrl_setPlaybackType(local_0, 2);
  anctrl_start(local_0);
  func_8009FFD8(param_0, 1, 1, 3, 7);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  func_800A4DA4(param_0, 0xA);
  yaw_setIdeal(param_0, func_8009F308(param_0) + 35.0f);
  _ncbadie_entrypoint_3(func_800A4CA8(param_0), 8e+01f);
  func_800FC6B0(0x17);
  func_8008E944(param_0);
  new_var = 0;
  _batimer_set(param_0, new_var, 0x4039999A);
}

s32 bstimeout_entrypoint_5(Actor *this) {
    if (_batimer_decrement(this, 0)) {
        func_800A05DC(this);
    }
}

s32 bstimeout_entrypoint_6(Actor *this){
    func_800A0CF4(this, 0);
    func_800A4E30(this);
    func_800FC7C4();
}

int bstimeout_entrypoint_7(s32 param_0)
{
  return D_80800340_bstimeout[param_0];
}
