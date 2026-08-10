#include "common.h"

s32 func_80094E70(void)
{
	return 0x1C;
}

s32 func_80094E78()
{
    func_800964D0();
}

f32 func_80094E98(Actor *param_0)
{
  int new_var;
  s32 local_0;
  unsigned int local_1;
  f32 func_800D8840(s32);
  local_0 = func_80094E78(param_0);
  new_var = 1;
  if (new_var)
  {
    local_1 = *((s32 *) (((char *) param_0) + 0x74));
    if ((*((u8 *) (local_1 + local_0))) != 0)
    {
      return *((f32 *) ((local_1 + (local_0 * 4)) + 8));
    }
  }
  return func_800D8840(local_0);
}

int func_80094EEC(s32 param_0, s32 param_1)
{
  u32 local_0;

  return func_800964D0(param_0) == param_1;
}

void func_80094F14(u8 *param_0, s32 param_1, s32 param_2, f32 param_3)
{
  s32 ptr1;
  s32 ptr2;
  ;
  *((u8 *) ((*((s32 *) (param_0 + 0x74))) + param_1)) = param_2;
  ;
  *((f32 *) (((*((s32 *) (param_0 + 0x74))) + (param_1 * 4)) + 8)) = param_3;
}

void func_80094F38(void *param_0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        ((u8 **) param_0)[0x1D][i] = 0;
    }
}
