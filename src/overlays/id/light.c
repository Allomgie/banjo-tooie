#include "common.h"

extern void _glid_entrypoint_0(s32, s32, void *, f32 *);
extern f32 func_800DC264(f32, f32);
extern f32 _idlight_entrypoint_0;

void idlight_entrypoint_0(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, f32 *param_4)
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

void idlight_entrypoint_1(s32 arg0) 
{
}
s32 idlight_entrypoint_2(f32 *param_0, s32 param_1, s32 param_2, s32 param_3){
    *param_0 = 1.0f;
}

void idlight_entrypoint_3(f32 *param_0, s32 param_1, s32 param_2)
{
  f32 temp_f2;
  f32 temp_f2_2;
  *param_0 += func_800DC264(-0.04f, 0.04f);
  temp_f2 = *param_0;
  if (temp_f2 > 1.0f)
  {
    *param_0 = 1.0f;
  }
  else
  {
    *param_0 = temp_f2;
  }
  temp_f2 = *param_0;
  temp_f2_2 = temp_f2;
  if (temp_f2_2 < 0.8f)
  {
    *param_0 = 0.8f;
  }
  else
  {
    *param_0 = temp_f2_2;
  }
  _glid_entrypoint_0(param_1, param_2, &_idlight_entrypoint_0, param_0);
}
