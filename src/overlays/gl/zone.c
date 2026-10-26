#include "common.h"

extern s32 _dbzone_entrypoint_2(s32, s32, s32);
extern s32 _dbzone_entrypoint_3(s32, s32);
void glzone_entrypoint_2();

s32 glzone_entrypoint_0(u8 *param_0){
    u8 *local_0;
    local_0 = (u8 *)heap_alloc(param_0[0] + 1);
    local_0[0] = param_0[0];
    glzone_entrypoint_2(local_0);
    return local_0;
}

void glzone_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void glzone_entrypoint_2(param_0) u8 *param_0; {
    u8 *local_0 = param_0 + *param_0 + 1;
    param_0++;
    while (param_0 < local_0) {
        *param_0++ = 0;
    }
}

s32 glzone_entrypoint_3(u8 *param_0, s32 param_1){
    param_0[param_1] = 1;
}

s32 glzone_entrypoint_4(s32 param_0, s32 param_1){
    u8 local_0;
    local_0 = *(u8*)(param_0 + param_1);
    return local_0;
}

s32 glzone_entrypoint_5(s32 param_0, s32 param_1, s32 param_2) {
    if (param_2 != 0 && _dbzone_entrypoint_2(param_0, param_1, param_2 - 1)) {
        return param_2;
    }
    return _dbzone_entrypoint_3(param_0, param_1) + 1;
}

int glzone_entrypoint_6(u8 *param_0, u8 *param_1, s32 param_2)
{
  int local_0;
  for (local_0 = 0; local_0 < param_2; local_0++)
  {
    if (param_0[param_1[local_0] + 1])
      return 1;
  }

  return 0;
}
