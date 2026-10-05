#include "common.h"

f32 func_800EFC7C(f32 *param_0, f32 *param_1);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } V_F0130;
extern float func_800EEFD4(float*);
extern float sqrtf(float);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EEB40(f32 *param_0, f32 (*param_1)[3]);
extern void func_800EFA4C(f32 *, f32, f32, f32);
f32 func_800EEF94(s32);
s32 func_800EEEA8(void);
extern f32 func_800EEAA4(s32 param_0, s32 param_1);
extern void func_800EF174(s32 param_0, s32 param_1, f32 param_2);

func_800EFE50(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3) {
    s32 i;
    for (i = 0; i < 3; i++) {
        param_0[i] = param_1[i] + param_3 * (param_2[i] - param_1[i]);
    }
}

s32 func_800EFED0(f32 param_0[3], f32 param_1[3], f32 param_2[3])
{
  f32 local_0;
  s32 new_var;
  f32 local_1;
  f32 local_2;
  unsigned char local_3;
  local_0 = param_2[0];
  local_3 = 0;
  if (param_0[0] < local_0)
  {
    local_3 = 1;
  }
  if (local_3 != 0)
  {
    local_3 = 0;
    if (local_0 < param_1[0])
    {
      local_3 = 1;
    }
    if (local_3 != 0)
    {
      local_1 = param_2[1];
      local_3 = 0;
      if (param_0[1] < local_1)
      {
        local_3 = 1;
      }
      if (local_3 != 0)
      {
        local_3 = 0;
        if (local_1 < param_1[1])
        {
          local_3 = 1;
        }
        new_var = local_3;
        if (new_var != 0)
        {
          local_2 = param_2[2];
          local_3 = 0;
          if (param_0[2] < local_2)
          {
            local_3 = 1;
          }
          if (local_3 != 0)
          {
            local_3 = 0;
            if (local_2 < param_1[2])
            {
              local_3 = 1;
            }
          }
        }
      }
    }
  }
  if (local_3)
  {
  }
  return local_3;
}

s32 func_800EFFB4(f32 *param_0, f32 param_1, f32 *param_2)
{
  f32 local_0[3];
  func_800EFB24(local_0, param_2, param_0);
  return func_800EEFD4(local_0) <= param_1 * param_1;
}

s32 func_800F0008(s32 param_0, f32 param_1, s32 param_2, f32 param_3)
{
  f32 local_0[3];

  func_800EFB24(local_0, param_0, param_2);
  return func_800EEFD4(local_0) <= ((param_1 + param_3) * (param_1 + param_3));
}

s32 func_800F0064(s32 param_0, f32 param_1, s32 param_2) {
    return func_800EFC7C(param_0, param_2) < param_1 * param_1;
}

int func_800F00A4(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3, f32 param_4[3])
{
    if ((param_4[1] < (param_0[1] + param_3)) || ((param_0[1] + param_2) < param_4[1]))
    {
        return 0;
    }
    return (func_800EFC7C(param_0, param_4) < (param_1 * param_1));
}

s32 func_800F0130(V_F0130 *param_0, s32 param_1, V_F0130 *param_2) {
    s32 d[3];
    d[0] = param_2->unk0 - param_0->unk0;
    d[2] = param_2->unk8 - param_0->unk8;
    return ((d[0] * d[0]) + (d[2] * d[2])) < (param_1 * param_1);
}

void func_800F018C(s32 param_0, s32 param_1, s32 param_2, float param_3[3]) {
    float local_1[3];
    float local_2[3];
    float local_0;
    float pad;
    func_800EFB24(local_1, param_2, param_1);
    local_0 = func_800EEFD4(local_1);
    if (local_0 < 0.01f) {
        func_800EE7F8(param_0, param_1);
    } else {
        local_0 = 1.0f / sqrtf(local_0);
        local_1[0] *= local_0;
        local_1[1] *= local_0;
        local_1[2] *= local_0;
        func_800EFB24(local_2, param_3, param_1);
        func_800EFA20(param_0, local_1, func_800EEAA4(local_2, local_1));
        func_800EF04C(param_0, param_1);
    }
}

void func_800F0274(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    func_800EFB24(local_0, param_2, param_1);
    local_2 = func_800EEFD4(local_0);
    if (local_2 < 0.01f) { func_800EE7F8(param_0, param_1); } else {
    local_2 = sqrtf(local_2);
    local_3 = 1.0f / local_2;
    local_0[0] *= local_3;
    local_0[1] *= local_3;
    local_0[2] *= local_3;
    func_800EFB24(local_1, param_3, param_1);
    local_3 = func_800EEAA4(local_1, local_0);
    if (local_3 <= 0.0f) { func_800EE7F8(param_0, param_1); } else
    if (local_2 <= local_3) { func_800EE7F8(param_0, param_2); } else {
    func_800EFA20(param_0, local_0, local_3);
    func_800EF04C(param_0, param_1);
    }
    }
}

void func_800F03AC(s32 *param_0, s32 *param_1, s32 param_2, s32 param_3) {
  s8 _sfpad[8];
    s32 sp1C;

    func_800EFB24(&sp1C, param_3, param_1);
    func_800EFA20(&sp1C, param_2, func_800EEAA4(param_2, &sp1C));
    func_800EFB24(param_0, param_3, &sp1C);
}

void func_800F0410(f32 *param_0, f32 *param_1, f32 (*param_2)[3]) {
  f32 local_3;
  f32 local_5;
  f32 local_4;
  f32 local_0[3];
  f32 local_1[3];
  f32 local_2[3];
  func_800F0274(local_0, param_1, param_1 + 3, param_2);
  func_800F0274(local_1, param_1 + 3, param_1 + 6, param_2);
  func_800F0274(local_2, param_1 + 6, param_1, param_2);
  local_3 = func_800EEB40(local_0, param_2);
  local_5 = func_800EEB40(local_1, param_2);
  local_4 = func_800EEB40(local_2, param_2);
  if (local_3 < local_5) {
    if (local_4 < local_3) {
      func_800EE7F8(param_0, local_2);
    } else {
      func_800EE7F8(param_0, local_0);
    }
  } else if (local_4 < local_5) {
    func_800EE7F8(param_0, local_2);
  } else {
    func_800EE7F8(param_0, local_1);
  }
}

int func_800F0524(s32 param_0, s32 param_1, s32 param_2)
{
  f32 local_0[3];
  f32 local_1[3];
  f32 local_2[3];
  func_800EFB24(local_0, param_1 + 0xC, param_1);
  func_800EFB24(local_1, param_1 + 0x18, param_1);
  func_800EE97C(local_2, local_0, local_1);
  func_800EF2A0(local_2);
  func_800F03AC(param_0, param_1, local_2, param_2);
}

void func_800F059C(void *param_0, void *param_1, void *param_2) {
    f32 sp1C[3];
    f32 r;
    func_800EFA20(param_0, param_1, -1.0f);
    r = func_800EEAA4(param_0, param_2);
    func_800EFA20(sp1C, param_2, r + r);
    func_800EFB24(param_0, sp1C, param_0);
}

int func_800F05F8(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 *param_4) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_7;
    local_0[0] = param_0[0] - param_2[0];
    local_0[2] = param_0[2] - param_2[2];
    local_1 = param_1[0] * param_1[0] + param_1[2] * param_1[2];
    if (local_1 == 0.0f) return 0;
    local_2 = 2.0f * (param_1[0] * local_0[0] + param_1[2] * local_0[2]);
    local_3 = local_0[0] * local_0[0] + local_0[2] * local_0[2] - param_3 * param_3;
    local_7 = local_2 * local_2;
    param_3 = 4.0f * local_1 * local_3;
    if (local_7 < param_3) return 0;
    local_3 = sqrtf(local_7 - param_3);
    local_1 = 0.5f / local_1;
    param_4[0] = (local_3 - local_2) * local_1;
    if (local_3 != 0.0f) {
        param_4[1] = -(local_2 + local_3) * local_1;
        return 2;
    }
    return 1;
}

s32 func_800F0734(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 *param_5, f32 *param_6)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    f32 local_10;
    f32 local_11;
    f32 local_12;
    f32 local_13;
    func_800EFB24(local_0, param_0, param_2);
    func_800EFB24(local_1, param_1, param_2);
    func_800EFB24(local_2, local_1, local_0);
    local_5 = local_0[0] * local_2[0] + local_0[2] * local_2[2];
    local_6 = local_2[0] * local_2[0] + local_2[2] * local_2[2];
    if (local_6 != 0.0f) {
        if (-local_5 / local_6 < 0.0f) {
            func_800EE7F8(local_3, local_0);
        } else if (-local_5 / local_6 < 1.0f) {
            func_800EFA20(local_3, local_2, -local_5 / local_6);
            func_800EF04C(local_3, local_0);
        } else {
            func_800EE7F8(local_3, local_1);
        }
        local_4 = param_3 * param_3;
        local_7 = local_3[0] * local_3[0] + local_3[2] * local_3[2];
        if (local_4 < local_7) return 0;
        local_10 = -local_5 / local_6;
        local_9 = sqrtf(local_6);
        local_11 = sqrtf(local_4 - local_7) / local_9;
        local_13 = local_10 - local_11 > 0.0f ? local_10 - local_11 : 0.0f;
        local_12 = local_10 + local_11 < 1.0f ? local_10 + local_11 : 1;
        func_800EFE50(param_5, param_0, param_1, local_13);
        func_800EFE50(param_6, param_0, param_1, local_12);
        local_8 = param_2[1] + param_4;
        if (param_2[1] <= param_5[1] && param_5[1] < local_8) return 1;
        if (param_2[1] <= param_6[1] && param_6[1] < local_8) return 1;
        return 0;
    } else {
        if (func_800F0064(param_0, param_3, param_2)) {
            if (param_0[1] < param_2[1] && param_2[1] < param_1[1]) {
                func_800EE7F8(param_5, param_2);
                func_800EFA4C(param_6, param_2[0], param_2[1] + param_4, param_2[2]);
                return 1;
            }
            local_8 = param_2[1] + param_4;
            if (local_8 < param_0[1] && param_1[1] < local_8) {
                func_800EFA4C(param_5, param_2[0], local_8, param_2[2]);
                func_800EE7F8(param_6, param_2);
                return 1;
            }
        }
        return 0;
    }
}

int func_800F0AA4(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    local_0 = param_1[2] - param_0[2];
    local_1 = param_0[0] - param_1[0];
    local_2 = param_1[0] * param_0[2] - param_0[0] * param_1[2];
    local_3 = local_0 * param_2[0] + local_1 * param_2[2] + local_2;
    local_4 = local_0 * param_3[0] + local_1 * param_3[2] + local_2;
    if (local_3 * local_4 > 0.0f) return 0;
    local_0 = param_3[2] - param_2[2];
    local_1 = param_2[0] - param_3[0];
    local_2 = param_3[0] * param_2[2] - param_2[0] * param_3[2];
    local_3 = local_0 * param_0[0] + local_1 * param_0[2] + local_2;
    local_4 = local_0 * param_1[0] + local_1 * param_1[2] + local_2;
    if (local_3 * local_4 > 0.0f) return 0;
    return 1;
}

s32 func_800F0BD0(s32 param_0, s32 param_1, f32 param_2, f32 param_3)
{
  f32 temp_f0;
  f32 func_res;
  float new_var;
  s32 var_v0;
  if (func_800EEEA8() != 0)
  {
    return 0;
  }
  temp_f0 = func_800EEAA4(param_1, param_0);
  if (param_2 < temp_f0)
  {
    return 0;
  }
  func_res = func_800EEF94(param_0);
  new_var = temp_f0 / func_res;
  var_v0 = 1;
  temp_f0 = new_var;
  if (((float) temp_f0) < param_3)
  {
    return 0;
  }
  return var_v0;
}

f32 func_800F0C68(s32 param_0, s32 param_1, f32 param_2, f32 param_3) {
    func_800EF2A0(param_1);
    return param_2 / sqrtf((param_2 * param_2) + (param_3 * param_3));
}

s32 func_800F0CB4(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = func_800EEAA4(param_1, param_3);
    if (sp24 == 0.0f) {
        return 0;
    }
    sp1C = func_800EEAA4(param_3, param_2);
    sp20 = func_800EEAA4(param_0, param_3);
    sp18 = sp1C - sp20;
    sp18 = sp18 / sp24;
    func_800EF174(param_0, param_1, sp18);
    return 1;
}
