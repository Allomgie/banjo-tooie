#include "common.h"

extern s16 D_80135530[];
extern s16 D_80135532[];
s16 func_800F9F04();
void func_800F9F2C();

int func_800F9EC0(s32 param_0, s32 param_1)
{
  if (param_1 < 0)
  {
    func_800FC660(0x74);
  }
  func_800F9F2C(param_0, func_800F9F04(param_0) + param_1);
}

s16 func_800F9F04(param_0) s32 param_0;
{
  unsigned int *new_var3;
  int new_var;
  unsigned int new_var2;
  new_var2 = (param_0 ^ 0) * 2;
  new_var3 = &new_var2;
  new_var = *new_var3;
  return D_80135530[new_var];
}

s16 func_800F9F18(s32 param_0)
{
  int new_var;
  new_var = param_0 * 2;
  if (new_var)
  {
  }
  return D_80135532[new_var];
}

void func_800F9F2C(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 *local_0;
  local_0 = &((s32 *) D_80135530)[param_0];
  if (param_1 < 0)
  {
    param_1 = 0;
  }
  else
    if (*((s16*)((u8*)local_0 + 2)) < param_1)
  {
    param_1 = *((s16*)((u8*)local_0 + 2));
  }
  *(s16 *)local_0 = param_1;
}

int func_800F9F74(s32 param_0, int param_1)
{
  *(short *)&((int *) D_80135532)[param_0] = param_1;
}
