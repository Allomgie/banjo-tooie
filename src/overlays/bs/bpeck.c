#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"
#include <types.h>

extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E4FC(PlayerState *, s32, f32, f32, f32);
extern s32 D_808004A0_bsbpeck[];
extern void func_8009DE38(PlayerState *, s32, f32);
extern void *baanim_getAnimCtrlPtr(void);
extern void _bswalk_entrypoint_1(void *);
extern int anctrl_isAt(void *, int);
extern void anctrl_setIndex(void *, int);
extern void anctrl_setStart(void *, float);
extern void anctrl_setDuration(void *, float);
extern void anctrl_setPlaybackType(void *, int);
extern void anctrl_start(void *);
extern void anctrl_reset(void *);
extern void anctrl_setSmoothTransition(void *, int);
extern void func_8008B188(void *, int);
extern int anctrl_isStopped(void *);
extern void func_8009FE58(void *);
extern float func_800D8FF8(void);
extern int player_isStable(void *);
extern int player_inWater(void *);
extern void bs_setState(void *, int);
extern float baphysics_get_target_horizontal_velocity(void *);
extern void baphysics_set_target_horizontal_velocity(void *, float);

void bsbpeck_entrypoint_0(PlayerState *param_0)
{
    s32 local_0;

    param_0->unk164.word = 0;
    local_0 = bs_getPreviousState(param_0);
    if (local_0 != 5 && (local_0 == 8 || (local_0 != 0x2F &&
        local_0 != 0x3D && local_0 != 0x57 && local_0 == 0x95))) {
        param_0->unk164.word++;
    }
    if (func_8009557C(param_0) == 1) func_80095588(param_0, 2);
    baanim_playForDuration_once(param_0, 0x1A, 0.2f);
    func_8009FFD8(param_0, 1, 3, 1, 6);
    yaw_setVelocityBounded(param_0, 1200.0f, 10.0f);
    func_800A0CF4(param_0, 1);
    baphysics_set_gravity(param_0, -1400.0f);
    baphysics_set_vertical_velocity(param_0, 120.0f);
    func_8009E4AC(param_0);
    func_8009E55C(param_0, 0, 35.0f);
    func_8009E55C(param_0, 1, 42.0f);
    func_8009E4FC(param_0, 1, -38.0f, 0.0f, 105.0f);
    func_8009E4FC(param_0, 0, -38.0f, 0.0f, -7.0f);
    param_0->unk160.word = 0;
    param_0->unk15C.word = 0;
    baflag_set(param_0, 0x2A);
}

void func_80800168_bsbpeck(PlayerState *param_0)
{
    f32 local_0 = 1.0f;

    switch (param_0->unk160.word) {
    case 0: local_0 = 1.13f; break;
    case 1: local_0 = 1.1f; break;
    case 2: local_0 = 1.32f; break;
    }
    baflag_set(param_0, 5);
    func_8009DE38(param_0, 0x442C, local_0);
    baphysics_set_vertical_velocity(param_0, 120.0f);
    param_0->unk160.word++;
}

void bsbpeck_entrypoint_1(void *param_0)
{
  int local_0;
  void *s0;
  int local_1;
  float local_2;

  local_0 = 0;
  s0 = baanim_getAnimCtrlPtr();
  _bswalk_entrypoint_1(param_0);
  if (*((int *) (((char *) param_0) + 0x164)))
  {
    baphysics_set_target_horizontal_velocity(param_0, baphysics_get_target_horizontal_velocity(param_0) * 0.1f);
  }
  local_1 = *((int *) (((char *) param_0) + 0x15C));
  switch (local_1)
  {
    case 0:
      if (anctrl_isAt(s0, 0x3F69A027))
      {
        anctrl_setIndex(s0, 0x19);
        anctrl_setStart(s0, 0.0f);
        anctrl_setDuration(s0, 0.35f);
        anctrl_setPlaybackType(s0, 2);
        anctrl_start(s0);
        *((int *) (((char *) param_0) + 0x15C)) = 1;
        *((float *) (((char *) param_0) + 0x16C)) = 0.5f;
      }
      break;
    case 1:
      if (anctrl_isAt(s0, 0x3E25FD8B))
      {
        func_80800168_bsbpeck(param_0);
      }
      if (anctrl_isAt(s0, 0x3F333333))
      {
        func_80800168_bsbpeck(param_0);
      }
      local_2 = 0.0f;
      *((float *) (((char *) param_0) + 0x16C)) = (*((float *) (((char *) param_0) + 0x16C))) - func_800D8FF8();
      if (*((float *) (((char *) param_0) + 0x16C)) < local_2)
      {
        anctrl_reset(s0);
        anctrl_setSmoothTransition(s0, 0);
        anctrl_setIndex(s0, 0x1A);
        func_8008B188(s0, 0);
        anctrl_setDuration(s0, 0.2f);
        anctrl_setPlaybackType(s0, 1);
        anctrl_start(s0);
        *((int *) (((char *) param_0) + 0x15C)) = 2;
      }
      break;
    case 2:
      if (anctrl_isStopped(s0))
      {
        local_0 = 0x2F;
      }
      break;
  }
  if (player_isStable(param_0))
  {
    func_8009FE58(param_0);
    local_0 = 1;
  }
  if (player_inWater(param_0))
  {
    local_0 = 0x4C;
  }
  bs_setState(param_0, local_0);
}

void bsbpeck_entrypoint_2(s32 param_0) {
    baflag_clear(param_0, 0x2A);
    func_800C6DA0(0x46);
    func_8009E474(param_0);
    func_800A0CF4(param_0, 0);
    baphysics_reset_gravity(param_0);
}

int bsbpeck_entrypoint_3(s32 param_0)
{
  return D_808004A0_bsbpeck[param_0];
}
