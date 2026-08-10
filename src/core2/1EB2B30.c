#include "core2/1EB2B30.h"

int func_800D9240()
{
    s32 pad0;
    s32 local_0;
    func_800F8E78();
    local_0 = func_800F89BC();
    _glcutDll_entrypoint_10(func_800F8A5C(local_0));
    func_800F9070(local_0, 1);
    _glcutDll_entrypoint_12(1);
}

void func_800D9290()
{
  s32 local_0;
  local_0 = 0;
  while (local_0 < func_800F5898())
  {
    if (func_800F6BE4(local_0))
    {
      func_800F8EE4(local_0);
    }
    local_0++;
  }

}

void func_800D92EC(void) {
}

void func_800D92F4()
{
  s32 local_0;
  local_0 = func_800F8AA4();
  if (func_800F8DA8(local_0 | 0))
  {
    func_800F8E78(local_0);
  }
}

void func_800D9330(u32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_1 = param_0 | 0;
  local_0 = 0;
  while (local_0 < func_800F5898())
  {
    if (func_800F6BE4(local_0))
    {
      func_800F78C8(local_0, local_1);
    }
    local_0++;
  }

}
