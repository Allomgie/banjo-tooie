#include "core2/1ECB0F0.h"

extern f32 func_80013AAC(f32);
extern f32 func_80013B7C(f32, f32);
extern f32 func_80013B70(f32, f32, f32);
extern f32 sqrtf(f32);
extern void func_800EFD24(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800EEF94(s32);
extern s32 func_800EE97C(s32 *, s32, s32 *);
extern f32 mlAbsF(f32);
extern void func_80013728(f32);
f32 func_800136E4(f32 param_0);
f32 func_800F1DCC(f32 param_0, f32 param_1);
s32 func_800F1EA4(f32 param_0[3], f32 *param_1);

f32 func_800F1800(f32 param_0)
{
  return mlAbsF(func_80013AAC(param_0));
}

f32 func_800F1828(f32 *param_0, f32 *param_1)
{
  float new_var;
  f32 local_0;
  f32 local_1;
  f32 local_2;
  local_1 = param_1[0] - param_0[0];
  local_0 = param_1[1] - param_0[1];
  local_2 = param_1[2] - param_0[2];
  new_var = (local_1 * local_1) + (local_2 * local_2);
  return func_80013B7C(local_0, sqrtf(new_var));
}

s32 func_800F1884(u8 *param_0, f32 *param_1)
{
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f2;
  temp_f0 = *((f32 *) (((s8 *) param_0) + 8));
  temp_f2 = *((f32 *) (((s8 *) param_0) + 0));
  temp_f0_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
  if (temp_f0_2 == 0.0f)
  {
    *param_1 = 0.0f;
    return 0;
  }
  *param_1 = func_80013B7C(*((f32 *) (((s8 *) param_0) + 4)), temp_f0_2);
  return 1;
}

void func_800F18FC(f32 *param_0, f32 *param_1, f32 *param_2) {
    f32 dx, dy, dz;
    f32 dist;

    dx = param_1[0] - param_0[0];
    dy = param_1[1] - param_0[1];
    dz = param_1[2] - param_0[2];

    dist = sqrtf(dx * dx + dz * dz);

    param_2[1] = func_80013B70(dx, dz, dist);
    param_2[0] = func_80013B7C(dy, dist);
}

int func_800F1988(f32 *param_0, f32 *param_1, f32 *param_2) {
    f32 local_0;
    *param_1 = 0.0f;
    *param_2 = 0.0f;
    local_0 = sqrtf(param_0[2] * param_0[2] + param_0[0] * param_0[0]);
    if (local_0 < 0.01f) return 0;
    *param_2 = func_800F1800(param_0[0] / local_0);
    if (param_0[2] < 0.0f) *param_2 = 180.0f - *param_2;
    if (param_0[0] < 0) *param_2 = 360.0f - *param_2;
    *param_1 = func_800F1800(local_0);
    return 1;
}

void func_800F1A88(f32 *param_0, f32 *param_1) {
    f32 len = sqrtf(param_0[0] * param_0[0] + param_0[2] * param_0[2]);
    param_1[1] = func_80013B70(param_0[0], param_0[2], len);
    param_1[0] = func_80013B7C(param_0[1], len);
}

void func_800F1AFC(f32 *param_0, f32 *param_1) {
    f32 len = sqrtf(param_0[0] * param_0[0] + param_0[2] * param_0[2]);
    param_1[1] = func_80013B70(param_0[0], param_0[2], len);
    param_1[0] = func_80013B7C(param_0[1], len);
    param_1[2] = 0.0f;
}

int func_800F1B78(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;
    func_800EFD24(param_0);
    local_4 = func_800F1988(param_1, &local_0, &local_1);
    local_0 *= param_3;
    if (local_4) {
        local_3 = func_800F1DCC(param_2, local_1);
        local_2 = mlAbsF(local_3);
        param_0[0] = func_800F10B4(local_2, 0.0f, 180.0f, local_0, -local_0);
        if (local_2 < 90.0f) param_0[2] = func_800F10B4(local_2, 0.0f, 90.0f, 0.0f, local_0);
        else param_0[2] = func_800F10B4(local_2, 90.0f, 180.0f, local_0, 0.0f);
        if (local_3 < 0.0f) param_0[2] = -param_0[2];
    }
    return local_4;
}

f32 func_800F1C98(s32 param_0, s32 *param_1) {
    f32 sp2C;
    f32 sp28;
    s8 _sfpad[8];
    s32 sp1C;

    sp2C = func_800EEF94(param_0);
    sp28 = func_800EEF94((s32)param_1);
    func_800EE97C(&sp1C, param_0, param_1);
    return func_800EEF94((s32)&sp1C) / (sp2C * sp28);
}

f32 func_800F1CF0(f32 *param_0, f32 *param_1)
{
  f32 prod;
  f32 cross_z;
  f32 abs_cross;
  f32 len0;
  f32 denom;
  f32 len1;
  len0 = sqrtf((param_0[2] * param_0[2]) + (param_0[0] * param_0[0]));
  len1 = sqrtf((param_1[0] * param_1[0]) + (param_1[2] * param_1[2]));
  prod = len1 * len0;
  if (1e-06f < prod)
  {
    cross_z = (param_0[2] * param_1[0]) - (param_0[0] * param_1[2]);
    abs_cross = mlAbsF(cross_z);
    denom = prod;
    if (prod < abs_cross)
    {
      denom = (prod = abs_cross);
    }
    denom = prod;
    return cross_z / denom;
  }
  return 0.0f;
}

f32 func_800F1DCC(f32 param_0, f32 param_1)
{
  f32 new_var;
  f32 new_var2;
  f32 new_var3;
  new_var2 = param_0;
  new_var3 = param_1;
  if (new_var2)
  {
  }
  new_var3 = (new_var = (1.0f * new_var2) - (new_var = (new_var = new_var3)));
  new_var = new_var3;
  func_80013728(new_var);
}

f32 func_800F1DF4(f32 param_0[3], f32 param_1[3])
{
  f32 local_0;
  float new_var;
  f32 local_1;
  new_var = param_1[0] - param_0[0]; local_0 = param_1[2] - param_0[2]; local_1 = new_var;
  return func_80013B7C(local_1, local_0);
}

void func_800F1E28(u8 *param_0, u8 *param_1) {
    func_80013B7C((f32) ((*(s16 *)((s8 *)(param_1) + (0))) - (*(s16 *)((s8 *)(param_0) + (0)))), (f32) ((*(s16 *)((s8 *)(param_1) + (4))) - (*(s16 *)((s8 *)(param_0) + (4)))));
}

s32 func_800F1E6C(f32 param_0[3], f32 param_1[3], f32 *param_2)
{
  f32 local_0[3];
  func_800EFB24(local_0, param_1, param_0);
  func_800F1EA4(local_0, param_2);
}

s32 func_800F1EA4(f32 param_0[3], f32 *param_1) {
    if ((param_0[0] != 0.0f) || (param_0[2] != 0.0f)) {
        *param_1 = func_80013B7C(param_0[0], param_0[2]);
        return 1;
    } else {
        *param_1 = 0.0f;
        return 0;
    }
}

void func_800F1F0C(s32 param_0, s32 param_1, f32 param_2)
{
  f32 new_var = func_800F1DF4(param_0, param_1);
  func_800F1DCC(new_var, param_2);
}

f32 func_800F1F38(f32 param_0, f32 param_1, f32 param_2) {
    f32 local_0;
    if (param_1 == param_0) return param_1;
    local_0 = func_800F1DCC(param_1, param_0);
    local_0 = local_0 > 0.0f ? (local_0 < param_2 ? local_0 : param_2) : (-param_2 < local_0 ? local_0 : -param_2);
    return func_800136E4(param_0 + local_0);
}

f32 func_800F1FF0(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 var_f2;
    f32 temp_f0;

    var_f2 = func_800F1DCC(param_1, param_0) * param_2;
    temp_f0 = mlAbsF(var_f2);
    if (temp_f0 < param_3)
    {
        return param_1;
    }
    if (param_4 < temp_f0)
    {
        if (var_f2 < 0.0f)
        {
            var_f2 = -param_4;
        }
        else
        {
            var_f2 = param_4;
        }
    }
    return func_800136E4(param_0 + var_f2);
}

f32 func_800F2094(f32 param_0, f32 param_1) {
    return mlAbsF(func_800F1DCC(param_0, param_1));
}

s32 func_800F20BC(f32 param_0, f32 param_1, f32 param_2) {
    return func_800F2094(param_0, param_1) < param_2;
}
