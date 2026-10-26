#include "common.h"

extern void _sudeflect_entrypoint_0(u8 *, f32, f32, s32);
extern int D_80800090_chdeflect;

s32 func_80800000_chdeflect(s32 param_0){
    if(func_800C6E38(0x14) != 0){
        func_800FFAB0(param_0);
    }
}

void func_80800034_chdeflect(u8 *param_0) {
    _sudeflect_entrypoint_0(param_0 + 4, 0.0f, *(f32 *)(param_0 + 0x38) * 100.0f, 2);
}

int chdeflect_entrypoint_0()
{
  return (int)&D_80800090_chdeflect;
}
