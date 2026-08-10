#include "common.h"

extern void func_80018854(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, f32 param_5, f32 param_6);

int bamotor_entrypoint_0(s32 param_0, s32 param_1, s32 param_2)
{
  func_80018820(bakey_getControllerIndex(param_0) | 0, param_1, param_2);
}

int bamotor_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  func_800187B4(bakey_getControllerIndex(param_0) | 0, param_1, param_2, param_3);
}

int bamotor_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  func_800187E8(bakey_getControllerIndex(param_0) | 0, param_1, param_2, param_3);
}

void bamotor_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, f32 param_5, f32 param_6)
{
    func_80018854(bakey_getControllerIndex(param_0), param_1, param_2, param_3,
                  param_4, param_5, param_6);
}
