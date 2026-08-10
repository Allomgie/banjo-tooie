#include "common.h"

void func_800DBEB0(s32 param_0)
{
  unsigned int local_0;
  s32 local_4;
  local_0 = param_0 + 4;
  local_4 = param_0 + 0x118;
  if (local_0 < local_4)
  {
    do
    {
      func_800EFD24(local_0);
      local_0 += 0xC;
    }
    while (local_0 < local_4);
  }
}

void func_800DBEFC(s32 param_0, s32 param_1, s32 param_2) {
    s32 t0 = param_0;
    s32 t1 = param_1 * 12;
    func_800EE7F8(param_2, t0 + t1 + 4);
}

void func_800DBF38(s32 param_0, s32 param_1, s32 param_2) {
    s32 t0 = param_0;
    s32 t1 = param_1 * 12;
    func_800EE904(param_2, t0 + t1 + 4);
}

void func_800DBF74(s32 param_0, s32 *param_1, s32 param_2, s32 param_3)
{
  s32 t6 = param_0;
  s32 t8 = param_2 * 12;
  s32 t0 = (((s32) param_1) ^ 0) * 12;
  func_800EFB24(param_3, (t6 + t8) + 4, (t6 + t0) + 4);
  func_800EF2A0(param_3);
}

void func_800DBFD8(void* arg0) 
{
    heap_free(arg0);
}
int func_800DBFF8()
{
  void *local_0;
  local_0 = heap_alloc(0x118);
  func_800DBEB0((s32)local_0 | 0);
  return (int)local_0;
}

void func_800DC028(s32 param_0, s32 param_1, s32 param_2)
{
  func_800EE7F8((param_0 + (param_1 * (0xC & 0xFFu))) + 4, param_2);
}

s32 func_800DC060(s32 param_0) {
    s32 local_0;

    if (param_0 != 0) {
        param_0 = (s32)defrag((void *)param_0);
    }
    return param_0;
}
