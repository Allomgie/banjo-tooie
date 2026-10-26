#include "common.h"

extern void *D_80800260_chstarspinnerplanet;
extern int D_808002A8_chstarspinnerplanet;
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800136E4(f32);
extern u8 D_808002F0_chstarspinnerplanet[];
extern void func_80108A30(s32, void *, f32, s32);

int chstarspinnerplanet_entrypoint_0()
{
  return &D_80800260_chstarspinnerplanet;
}

int chstarspinnerplanet_entrypoint_1()
{
    return (int)&D_808002A8_chstarspinnerplanet;
}

void func_80800018_chstarspinnerplanet(Actor *param_0)
{
    f32 local_0;

    if (func_800DA298(0)) {
        local_0 = func_800D8FF8();
        *(f32 *)&param_0->actorData[5] = func_800F15F8(*(f32 *)&param_0->actorData[5], 20.0f, 0.5f);
        *(f32 *)&param_0->actorData[4] = func_800F15F8(*(f32 *)&param_0->actorData[4], 40.0f, 0.8f);
        param_0->rotation[1] = func_800136E4(param_0->rotation[1] + *(f32 *)&param_0->actorData[5] * local_0);
        param_0->rotation[0] = func_800136E4(param_0->rotation[0] + *(f32 *)&param_0->actorData[4] * local_0);
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, func_800DA298(0), D_808002F0_chstarspinnerplanet);
}

int func_808000E4_chstarspinnerplanet(s32 param_0)
{
  if (func_800DA298(0xEA) != 0 || _glcutDll_entrypoint_20() != 0)
  {
    func_800DA544(0);
  }
  func_80108A30(0x335, param_0 + 4, 0, 0x32);
  if (func_800EA05C() != 0xE6)
  {
    func_8010A624(param_0);
  }
  _subaddiefade_entrypoint_12(param_0, 0xA0, 0xA0, 0xA0);
}

void func_80800170_chstarspinnerplanet(Actor *param_0)
{
    f32 local_0;
    if (func_800DA298(0)) {
        local_0 = func_800D8FF8();
        *(f32 *)&param_0->actorData[5] =
            func_800F15F8(*(f32 *)&param_0->actorData[5], 25.0f, 0.6f);
        param_0->rotation[1] = func_800136E4(
            param_0->rotation[1] - *(f32 *)&param_0->actorData[5] * local_0);
    }
}

void func_808001E8_chstarspinnerplanet(s32 param_0)
{
  if ((func_800DA298(0xEA) != 0) || (_glcutDll_entrypoint_20() != 0))
  {
    func_800DA544(0);
  }
  if (func_800EA05C() != 0xE6)
  {
    func_8010A624(param_0);
  }
  _subaddiefade_entrypoint_12(param_0, 0xA0, 0xA0, 0xA0);
}
