#include "common.h"

extern s16 D_80117F02[][2];

int func_8009C2A0(s32 param_0, int param_1)
{
  s16 *new_var;
  short new_var2;
  new_var = D_80117F02[param_1];
  new_var2 = *new_var;
  func_800DBEFC(param_0, new_var2);
}
