#include "common.h"

extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);

s32 plsu_entrypoint_0(f32 *param_0, f32 *param_1)
{
    f32 local_0[3];
    f32 local_2;
    f32 local_3;
    s32 local_4;
    s32 local_1;

    local_3 = 3.402823466e38f;
    for (local_4 = 0; local_4 < func_800F5898(); local_4++) {
        if (func_800F6BE4(local_4)) {
            func_800F5A00(local_4, local_0);
            local_2 = func_800EEB40(local_0, param_1);
            if (local_2 < local_3) {
                local_3 = local_2;
                local_1 = local_4;
                func_800EE7F8(param_0, local_0);
            }
        }
    }
    return local_1;
}

int plsu_entrypoint_1(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_1 = param_0 | 0;
  local_0 = 0;
  while (local_0 < func_800F5898())
  {
    if (func_800F6BE4(local_0) && func_800F5410(local_0) == local_1)
    {
      return local_0;
    }
    local_0++;
  }

  return -1;
}

s32 plsu_entrypoint_2(void) {
    if ((plsu_entrypoint_1(0xA) == -1)) {
        return 0;
    }
    if ((plsu_entrypoint_1(0xB) == -1)) {
        return 0;
    }
    return 1;
}

int plsu_entrypoint_3(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_1 = param_0 | 0;
  local_0 = 0;
  while (local_0 < func_800F5898())
  {
    if (func_800F6BE4(local_0) && func_800F6C5C(local_0) && func_800F55D0(local_0) == local_1)
    {
      return local_0;
    }
    local_0++;
  }

  return -1;
}
