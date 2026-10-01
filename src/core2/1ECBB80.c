#include "common.h"

extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern f32 D_80125EE0;
f32 mlAbsF(f32);

f32 func_800F2290(u8 *param_0, u8 *param_1)
{
  return ((*((f32 *) (((s8 *) param_0) + 0))) * (*((f32 *) (((s8 *) param_1) + 4)))) - ((*((f32 *) (((s8 *) param_0) + 4))) * (*((f32 *) (((s8 *) param_1) + 0))));
}

void func_800F22B4(f32 *param_0, f32 param_1) {
    param_0[0] = func_800137F4(param_1);
    param_0[1] = func_80013788();
}

void func_800F22EC(u8 *param_0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (*(f32 *)((s8 *)(param_0) + (4)));
    temp_f2 = (*(f32 *)((s8 *)(param_0) + (0)));
    sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

f32 func_800F2320(f32 param_0[3]) {
  f32 local_0 = mlAbsF(param_0[0]);
  f32 local_1 = mlAbsF(param_0[1]);
  f32 local_2;
  if (local_0 < local_1) {
    local_2 = local_0;
  } else {
    local_2 = local_1;
  }
  return local_0 + local_1 - local_2 * D_80125EE0;
}

func_800F2388(f32 *param_0, f32 param_1[3], f32 param_2[3]){
    param_0[0] = param_1[0]-param_2[0];
    param_0[1] = param_1[1]-param_2[1];
}

func_800F23AC(f32 *param_0, f32 param_1[3]){
    param_0[0] = param_1[1];
    param_0[1] = -param_1[0];
}
