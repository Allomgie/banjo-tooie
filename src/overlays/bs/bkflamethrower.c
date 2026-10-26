#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 D_80800450_bsbkflamethrower[];
extern u8 _bsbkflamethrower_entrypoint_0[];
extern void *baanim_getAnimCtrlPtr();
extern void anctrl_setPlaybackType(void *ctrl, int type);
extern void anctrl_setSubrange(void *ctrl, float start, float end);
extern void baanim_playForDuration_onceSmooth(void *ctrl, int animId, float duration);
extern void baanim_setEnd(void *ctrl, float value);
extern void _baflamethrower_entrypoint_1(void *param_0);
extern void _baflamethrower_entrypoint_2(void *param_0, void *callback);
extern void _baflamethrower_entrypoint_3(void *param_0);
extern void _baflamethrower_entrypoint_4(void *param_0);
extern void _batimer_set(void *param_0, int timerId, float value);
extern void baphysics_set_target_horizontal_velocity(void *param_0, float value);
extern void yaw_setVelocityBounded(void *param_0, float vel, float bound);
extern int func_8009D874(void *param_0);
extern int func_800C6E38(int param_0);
extern void func_8009FFD8(void *param_0, int param_1, int param_2, int param_3, int param_4);
extern void func_800A0CF4(void *param_0, int param_1);
extern void bs_setState(Actor *param_0, s32 param_1);
extern void _baflamethrower_entrypoint_5(Actor *param_0);
extern f32 _batimer_get(Actor *param_0, s32 param_1);
extern s32 _batimer_decrement(Actor *param_0, s32 param_1);
extern s32 _batimer_isZero(Actor *param_0, s32 param_1);
extern s32 bakey_pressed(Actor *param_0, s32 param_1);
extern s32 bakey_released(Actor *param_0, s32 param_1);
extern s32 baanim_isAt(Actor *param_0, s32 param_1);
extern s32 baanim_isStopped(Actor *param_0);
extern f32 baanim_getTimer(Actor *param_0);
extern void func_8009DF18(Actor *param_0, s32 param_1, f32 param_2, s32 param_3);
extern s32 _bsstand_entrypoint_8(Actor *param_0, s32 param_1);
void func_80800094_bsbkflamethrower();

void bsbkflamethrower_entrypoint_0(PlayerState *param_0, f32 *param_1, f32 *param_2)
{
    f32 local_0[3];
    func_800EEC30(param_2, -func_8009BFCC(param_0), yaw_get(param_0), 1.0f);
    func_8009C128(param_0, param_1);
    func_800EFA98(local_0, param_2, 40.0f);
    func_800EF04C(param_1, local_0);
    param_1[1] += 94.0f;
}

void func_80800094_bsbkflamethrower(param_0, param_1) Actor *param_0; s32 param_1;
{
    void *local_0;
    s32 local_1;
    f32 local_2;

    local_0 = baanim_getAnimCtrlPtr();
    *((s32 *) (((char *) param_0) + 0x15c)) = param_1;
    switch (param_1)
    {
    case 1:
        baanim_playForDuration_onceSmooth(param_0, 0xE0, 1.0f);
        func_8009FFD8(param_0, 1, 3, 8, 2);
        yaw_setVelocityBounded(param_0, 300.0f, 1.600000023841858f);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        func_800A0CF4(param_0, 1);
        func_8009D874(param_0);
        if (func_800C6E38(0x32) != 0)
        {
            local_2 = 0.24f;
        }
        else
        {
            local_2 = 0.0f;
        }
        _batimer_set(param_0, 0, local_2);
        _baflamethrower_entrypoint_2(param_0, &_bsbkflamethrower_entrypoint_0);
        return;
    case 2:
        local_1 = (s32)local_0;
        anctrl_setSubrange(local_0, 0.4f, 0.6f);
        anctrl_setPlaybackType(local_0, 4);
        _batimer_set(param_0, 2, 0.14f);
        _baflamethrower_entrypoint_3(param_0);
        return;
    case 3:
        _baflamethrower_entrypoint_4(param_0);
        _batimer_set(param_0, 1, 0.05f);
        return;
    case 4:
        anctrl_setPlaybackType(local_0, 1);
        baanim_setEnd(param_0, 1.0f);
        return;
    case 0:
        _baflamethrower_entrypoint_1(param_0);
        func_800A0CF4(param_0, 0);
        /* fallthrough */
    default:
        return;
    }
}

void bsbkflamethrower_entrypoint_1(s32 arg0)
{
    func_80800094_bsbkflamethrower(arg0,0);
}

void bsbkflamethrower_entrypoint_2(u8 *param_0) {
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
    func_80800094_bsbkflamethrower(param_0, 1);
}

void bsbkflamethrower_entrypoint_3(Actor *param_0)
{
  s32 sp24;
  s32 temp_v1;

  sp24 = 0;
  if ((_batimer_get(param_0, 0) != 0.0f) && (bakey_pressed(param_0, 9) != 0)) {
    sp24 = 0x189;
  }
  _batimer_decrement(param_0, 0);
  temp_v1 = (*(s32 *)((s8 *)(param_0) + (0x15C)));
  switch (temp_v1) {
    case 1:
      if (baanim_isAt(param_0, 0x3E6147AE) != 0) {
        func_8009DF18(param_0, 0x459F, 1.0f, 0x6590);
      }
      if (baanim_isAt(param_0, 0x3ECCCCCD) != 0) {
        func_80800094_bsbkflamethrower(param_0, 2);
      }
      break;
    case 2:
      _batimer_decrement(param_0, 2);
      if ((_batimer_isZero(param_0, 2) != 0) && (bakey_released(param_0, 9) != 0)) {
        func_80800094_bsbkflamethrower(param_0, 3);
      }
      break;
    case 3:
      if (_batimer_decrement(param_0, 1) != 0) {
        func_80800094_bsbkflamethrower(param_0, 4);
      }
      break;
    case 4:
      if (baanim_isStopped(param_0) != 0) {
        sp24 = 1;
      }
      if (baanim_getTimer(param_0) > 0.7f) {
        sp24 = _bsstand_entrypoint_8(param_0, sp24);
      }
      break;
  }
  _baflamethrower_entrypoint_5(param_0);
  bs_setState(param_0, sp24);
}

int bsbkflamethrower_entrypoint_4(s32 param_0)
{
  return D_80800450_bsbkflamethrower[param_0];
}
