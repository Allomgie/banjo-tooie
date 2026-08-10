#include "common.h"

int gcwater_entrypoint_0()
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  s32 local_4;

  local_0 = 0;
  local_1 = func_800BEB28(1);
  if (local_1 != 0)
  {
    local_2 = func_800B2720(local_1);
    if (local_2 != 0)
    {
      local_0 = func_800AAD80(local_2);
    }
  }
  if (local_0 == 0)
  {
    local_3 = func_800BEB28(0);
    if (local_3 != 0)
    {
      local_4 = func_800B2720(local_3);
      if (local_4 != 0)
      {
        local_0 = func_800AAD80(local_4);
      }
    }
  }
  func_800DA3B8(0x6B5, (local_0) ? (1) : (0));
}
