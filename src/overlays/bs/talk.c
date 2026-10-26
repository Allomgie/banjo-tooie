#include "common.h"

void baphysics_set_target_horizontal_velocity(s32, f32);
extern void bs_setState();
extern s32 D_80800170_bstalk[];

void bstalk_entrypoint_0(u8 *param_0)
{
  s32 sp3C;
  s32 sp38;
  f32 sp2C[3];
  f32 sp20[3];

  sp3C = baanim_getAnimCtrlPtr();
  anctrl_reset(sp3C);
  func_800A0110(param_0, sp3C);
  anctrl_setPlaybackType(sp3C, 2);
  anctrl_start(sp3C);
  func_8009C128(param_0, sp2C);
  func_800A33A0(param_0, sp20);
  func_800F1E6C(sp2C, sp20, &sp38);
  yaw_setIdeal(param_0, sp38);
  func_8008CA4C(param_0, 1);
  yaw_setUpdateType(param_0, 1);
  func_8009D2D8(param_0, 3);
  baphysics_set_type(param_0, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  *((s32 *) (((s8 *) param_0) + 0x15C)) = 1;
}

void bstalk_entrypoint_1(u8 *param_0) {
    s32 local_0 = 0;
    if (*(s32 *)(param_0 + 0x15C) == 0) {
        local_0 = 1;
    }
    *(s32 *)(param_0 + 0x15C) = 0;
    bs_setState(param_0, local_0);
}

void bstalk_entrypoint_2(s32 arg0) 
{
}
int bstalk_entrypoint_3(s32 param_0)
{
  return D_80800170_bstalk[param_0];
}

void bstalk_entrypoint_4(u8 *param_0) {
    if (func_8009E6EC() == 8) {
        (*(s32 *)((s8 *)(param_0) + (0x15C))) = 1;
        func_8009E830(param_0, 2);
        return;
    }
    func_80099B94(param_0);
}
