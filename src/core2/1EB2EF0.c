#include "common.h"

extern f32 D_80125D20;
extern f32 func_80013A7C(f32);
extern f32 func_80013970(f32);
typedef struct { s32 unk0; s32 unk1; s32 unk2; f32 unk3; } UnkStruct;

func_800D9600(f32 param_0[4], f32 param_1[4]){
    param_0[0] = param_1[0];
    param_0[1] = param_1[1];
    param_0[2] = param_1[2];
    param_0[3] = param_1[3];
}

void func_800D9624(f32 *param_0, f32 *param_1)
{
  s32 i;
  for (i = 0; i != 3; i++)
  {
    param_0[i] = -param_1[i];
  }
  param_0[3] = param_1[3];
}

void func_800D965C(f32 *param_0, f32 param_1[][4])
{
    f32 local_0, local_1, local_2, local_3;
    f32 local_4, local_5, local_6;
    f32 local_7, local_8, local_9, local_10, local_11, local_12;
    if (param_0[0] == 0.0f && param_0[1] == 0.0f && param_0[2] == 0.0f && param_0[3] == 0.0f) {}
    local_0 = 2.0f / (param_0[0]*param_0[0] + param_0[1]*param_0[1] + param_0[2]*param_0[2] + param_0[3]*param_0[3]);
    local_4 = param_0[0]*local_0;
    local_5 = param_0[1]*local_0;
    local_6 = param_0[2]*local_0;
    local_1 = param_0[3]*local_4;
    local_2 = param_0[3]*local_5;
    local_3 = param_0[3]*local_6;
    local_7 = param_0[0]*local_4;
    local_8 = param_0[0]*local_5;
    local_9 = param_0[0]*local_6;
    local_10 = param_0[1]*local_5;
    local_11 = param_0[1]*local_6;
    local_12 = param_0[2]*local_6;
    param_1[0][0] = 1.0f - (local_10 + local_12);
    param_1[0][1] = local_8 + local_3;
    param_1[0][2] = local_9 - local_2;
    param_1[1][0] = local_8 - local_3;
    param_1[1][1] = 1.0f - (local_7 + local_12);
    param_1[1][2] = local_11 + local_1;
    param_1[2][0] = local_9 + local_2;
    param_1[2][1] = local_11 - local_1;
    param_1[2][2] = 1.0f - (local_7 + local_10);
    param_1[3][3] = 1.0f;
    param_1[0][3] = 0;
    param_1[1][3] = 0;
    param_1[2][3] = 0;
    param_1[3][0] = 0;
    param_1[3][1] = 0;
    param_1[3][2] = 0;
}

int func_800D97E8(f32 param_0[4], f32 param_1[4])
{
  return param_0[0] == param_1[0] && param_0[1] == param_1[1] && param_0[2] == param_1[2] && param_0[3] == param_1[3];
}

void func_800D9888(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3) {
    f32 local_0, local_1, local_2, local_3, local_4;
    local_0 = param_1[0] * param_2[0] + param_1[1] * param_2[1] + param_1[2] * param_2[2] + param_1[3] * param_2[3];
    if (1.0f + local_0 > D_80125D20) {
        if (1.0f - local_0 > D_80125D20) {
            local_4 = func_80013A7C(local_0);
            local_3 = func_80013970(local_4);
            if (local_3 != 0.0f) {
                local_1 = func_80013970((1.0f - param_3) * local_4) / local_3;
                local_2 = func_80013970(param_3 * local_4) / local_3;
            } else {
                local_1 = 1.0f - param_3;
                local_2 = param_3;
            }
        } else {
            local_1 = 1.0f - param_3;
            local_2 = param_3;
        }
        param_0[0] = local_1 * param_1[0] + local_2 * param_2[0];
        param_0[1] = local_1 * param_1[1] + local_2 * param_2[1];
        param_0[2] = local_1 * param_1[2] + local_2 * param_2[2];
        param_0[3] = local_1 * param_1[3] + local_2 * param_2[3];
    } else {
        param_0[0] = -param_1[1];
        param_0[1] = param_1[0];
        param_0[2] = -param_1[3];
        param_0[3] = param_1[2];
        local_1 = func_80013970((1.0f - param_3) * 90.0f);
        local_2 = func_80013970(param_3 * 90.0f);
        param_0[0] = local_1 * param_1[0] + local_2 * param_0[0];
        param_0[1] = local_1 * param_1[1] + local_2 * param_0[1];
        param_0[2] = local_1 * param_1[2] + local_2 * param_0[2];
    }
}

void func_800D9AD4(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
  f32 local_1;
  f32 local_2;
  f32 local_0[4];

  local_0[0] = param_1[0] - param_2[0];
  local_0[1] = param_1[1] - param_2[1];
  local_0[2] = param_1[2] - param_2[2];
  local_0[3] = param_1[3] - param_2[3];

  local_1 = (local_0[0] * local_0[0]) + (local_0[1] * local_0[1]) + (local_0[2] * local_0[2]) + (local_0[3] * local_0[3]);

  local_0[0] = param_1[0] + param_2[0];
  local_0[1] = param_1[1] + param_2[1];
  local_0[2] = param_1[2] + param_2[2];
  local_0[3] = param_1[3] + param_2[3];

  local_2 = (local_0[0] * local_0[0]) + (local_0[1] * local_0[1]) + (local_0[2] * local_0[2]) + (local_0[3] * local_0[3]);

  if (local_1 <= local_2)
  {
    func_800D9888(param_0, param_1, param_2, param_3);
    return;
  }

  local_0[0] = -param_2[0];
  local_0[1] = -param_2[1];
  local_0[2] = -param_2[2];
  local_0[3] = -param_2[3];

  func_800D9888(param_0, param_1, local_0, param_3);
}

void func_800D9C34(UnkStruct* param_0) {
    param_0->unk0 = 0;
    param_0->unk1 = 0;
    param_0->unk2 = 0;
    ((s32*)&param_0->unk3)[0] = 0x3F800000;
}

int func_800D9C4C(f32 param_0[4])
{
  s32 local_0;
  f32 local_1 = 0.0f;
  ;
  return (((param_0[0] == local_1) && (param_0[1] == local_1)) && (param_0[2] == local_1)) && (param_0[3] == 1.0f);
}

void func_800D9CE8(f32 *param_0, f32 param_1[][3])
{
    f32 local_0, local_1, local_2, local_3;
    f32 local_4, local_5, local_6;
    f32 local_7, local_8, local_9, local_10, local_11, local_12;
    if (param_0[0] == 0.0f && param_0[1] == 0.0f && param_0[2] == 0.0f && param_0[3] == 0.0f) {}
    local_0 = 2.0f / (param_0[0]*param_0[0] + param_0[1]*param_0[1] + param_0[2]*param_0[2] + param_0[3]*param_0[3]);
    local_4 = param_0[0]*local_0;
    local_5 = param_0[1]*local_0;
    local_6 = param_0[2]*local_0;
    local_1 = param_0[3]*local_4;
    local_2 = param_0[3]*local_5;
    local_3 = param_0[3]*local_6;
    local_7 = param_0[0]*local_4;
    local_8 = param_0[0]*local_5;
    local_9 = param_0[0]*local_6;
    local_10 = param_0[1]*local_5;
    local_11 = param_0[1]*local_6;
    local_12 = param_0[2]*local_6;
    param_1[0][0] = 1.0f - (local_10 + local_12);
    param_1[0][1] = local_8 + local_3;
    param_1[0][2] = local_9 - local_2;
    param_1[1][0] = local_8 - local_3;
    param_1[1][1] = 1.0f - (local_7 + local_12);
    param_1[1][2] = local_11 + local_1;
    param_1[2][0] = local_9 + local_2;
    param_1[2][1] = local_11 - local_1;
    param_1[2][2] = 1.0f - (local_7 + local_10);
    
}
