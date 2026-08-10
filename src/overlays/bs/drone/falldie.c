#include "common.h"

extern void _badata_entrypoint_6(void *param_0, s32 *local_1, s32 *local_2, f32 *local_3, f32 *local_4);
extern void _basudie_entrypoint_1(Actor *param_0);
extern void *baanim_getAnimCtrlPtr(Actor *param_0);
extern void anctrl_reset(void *param_0);
extern void anctrl_setIndex(void *param_0, s32 param_1);
extern void anctrl_setDuration(void *param_0, s32 param_1);
extern void anctrl_setStart(void *param_0, f32 param_1);
extern void anctrl_setSubrange(void *param_0, f32 param_1, f32 param_2);
extern void anctrl_setPlaybackType(void *param_0, s32 param_1);
extern void anctrl_start(void *param_0);
extern void func_8009FFD8(Actor *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern void func_800961AC(Actor *param_0, s32 param_1);
extern void func_800A0180(Actor *param_0);
extern void func_800A4DFC(Actor *param_0, s32 param_1);
extern void func_80098B4C(Actor *param_0, s32 param_1);
extern void func_80092880(Actor *param_0, s32 param_1);

int func_80800000_bsdronefalldie(Actor *param_0, s32 param_1)
{
  if (param_1 == 2)
  {
    _basudie_entrypoint_0();
  }
  *(s32*)((char*)param_0 + 0x190) = param_1;
  return;
}

int bsdronefalldie_entrypoint_0(Actor *param_0)
{
  func_800961AC(param_0, 1);
  func_80092880(param_0, 1);
}

void bsdronefalldie_entrypoint_1(Actor *param_0)
{
  f32 sp3C;
  f32 sp38;
  f32 sp34;
  s32 sp30;
  s32 sp2C;
  void *temp_s0;

  _basudie_entrypoint_1(param_0);
  temp_s0 = baanim_getAnimCtrlPtr(param_0);
  _badata_entrypoint_6(param_0, &sp2C, &sp30, &sp34, &sp38);
  if (sp34 == sp38)
  {
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, sp2C);
    anctrl_setDuration(temp_s0, sp30);
    anctrl_setStart(temp_s0, sp34);
    anctrl_setSubrange(temp_s0, sp34, sp38);
    anctrl_setPlaybackType(temp_s0, 1);
    anctrl_start(temp_s0);
  }
  else
  {
    anctrl_reset(temp_s0);
    anctrl_setIndex(temp_s0, sp2C);
    anctrl_setDuration(temp_s0, sp30);
    anctrl_setSubrange(temp_s0, sp34, sp38);
    anctrl_setPlaybackType(temp_s0, 4);
    anctrl_start(temp_s0);
  }
  func_8009FFD8(param_0, 1, 1, 3, 2);
  func_800961AC(param_0, 6);
  func_800A0180(param_0);
  func_800A4DFC(param_0, 5);
  func_80098B4C(param_0, 0);
  func_80092880(param_0, 0);
  *(s32 *)((char *)(param_0) + 0x190) = 0;
  func_80800000_bsdronefalldie(param_0, 1);
}

int bsdronefalldie_entrypoint_2(Actor *param_0)
{
  if (func_8009E6EC(param_0) != 0x91)
  {
    func_80099AA8(param_0);
  }
}

void bsdronefalldie_entrypoint_3(u8 *param_0) {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0x190)));
    switch (local_0) {                              
    case 1:
        if (func_800FCCD4(_badata_entrypoint_16()) == 0) {
            func_80800000_bsdronefalldie(param_0, 2);
        }
        
    case 2:
        return;
    }
}
