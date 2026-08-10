#include "common.h"

func_800B0D50(s16 *param_0) {
    return param_0[0];
}

func_800B0D58(s16 *param_0) {
    return param_0[1];
}

s32 func_800B0D60(s32 param_0)
{
  int new_var;
  s32 new_var2;
  long new_var4;
  s32 *new_var3;
  new_var2 = 8;
  new_var3 = &(*((s32 *) (new_var = param_0 + new_var2)));
  new_var2 = *new_var3;
  new_var4 = *new_var3;
  return param_0 + new_var4;
}

int func_800B0D6C(s32 param_0, s32 param_1)
{
  return (s32)&((char*)param_0)[0xC + param_1 * 8];
}
