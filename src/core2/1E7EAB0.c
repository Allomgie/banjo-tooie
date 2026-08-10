#include "common.h"

extern void _plcamera_entrypoint_6(s32, s32, s32, s32, f32);

void func_800A51C0()
{
    _plcamera_entrypoint_0(func_800F54E4());
}

void func_800A51E8(s32 arg0)
{
    _plcamera_entrypoint_2(func_800F54E4(),arg0);
}

void func_800A5214(s32 arg0)
{
    _plcamera_entrypoint_3(func_800F54E4(),arg0);
}

void func_800A5240(s32 arg0)
{
    _plcamera_entrypoint_4(func_800F54E4(),arg0);
}

void func_800A526C(s32 arg0)
{
    _plcamera_entrypoint_5(func_800F54E4(),arg0);
}

int func_800A5298(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
  _plcamera_entrypoint_6(func_800F54E4(), param_0, param_1, param_2, param_3);
}

int func_800A52E0(s32 param_0, s32 param_1, s32 param_2)
{
  u32 local_0;
  local_0 = func_800F54E4();
  _plcamera_entrypoint_7(local_0 | 0, param_0, param_1, param_2);
}
