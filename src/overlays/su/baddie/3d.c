#include "common.h"

int subaddie3d_entrypoint_0(f32 param_0[3], f32 param_1, f32 param_2, f32 *param_3)
{
  f32 local_2[3];
  f32 local_0[3];
  f32 local_1[3];

  func_800EE7F8(local_0, param_0);
  local_0[1] += param_1;
  func_800EE7F8(local_1, param_0);
  local_1[1] += param_2;
  if (func_800BEF00(local_0, local_1, local_2, 0x20020))
  {
    *param_3 = local_1[1];
    return 1;
  }
  return 0;
}

int subaddie3d_entrypoint_1(f32 param_0[3], f32 param_1, f32 param_2, f32 *param_3)
{
  f32 local_2[3];
  f32 local_0[3];
  f32 local_1[3];

  func_800EE7F8(local_0, param_0);
  local_0[1] += param_1;
  func_800EE7F8(local_1, param_0);
  local_1[1] += param_2;
  if (func_800BEF00(local_0, local_1, local_2, 0x1F00))
  {
    *param_3 = local_1[1];
    return 1;
  }
  return 0;
}
