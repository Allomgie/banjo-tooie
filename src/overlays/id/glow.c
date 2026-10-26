#include "common.h"

extern f32 func_800D8FF8(void);
extern void _idglow_entrypoint_0(void);

void idglow_entrypoint_0(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, f32 *param_4)
{
    Vtx *local_0;
    f32 local_1;
    local_1 = *param_4;
    local_0 = param_1 + param_3;
    for (; param_1 < local_0; param_1++, param_2++) {
        param_2->v.cn[0] = param_1->v.cn[0] * local_1;
        param_2->v.cn[1] = param_1->v.cn[1] * local_1;
        param_2->v.cn[2] = param_1->v.cn[2] * local_1;
    }
}

void idglow_entrypoint_1(s32 arg0) 
{
}
int idglow_entrypoint_2(f32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  float new_var;
  f32 local_0;
  new_var = param_1 + 1.0f;
  local_0 = new_var;
  new_var = 0.009999999776;
  local_0 *= new_var;
  param_0[0] = 0.5f;
  param_0[1] = local_0;
}

void idglow_entrypoint_3(f32 *param_0, void *param_1, void *param_2)
{
    param_0[0] += param_0[1] * func_800D8FF8();
    if (param_0[0] >= 1.0f) {
        param_0[0] = 1.0f;
        param_0[1] = -param_0[1];
    } else if (param_0[0] < 0.3000000119f) {
        param_0[0] = 0.3000000119f;
        param_0[1] = -param_0[1];
    }
    _glid_entrypoint_0(param_1, param_2, _idglow_entrypoint_0, param_0);
}
