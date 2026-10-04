#include <ultra64.h>
#include "core1/mlmtx.h"
s32 func_800F274C();

#define F2984_DIR(x) ((x) * 128.0f < 127.0f ? (x) * 128.0f : 127.0f)
extern void func_800EF2A0(f32 *);
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
typedef struct { f32 v[4]; } R_F293C;
typedef struct { u8 local_0[8]; s8 local_1[3]; u8 pad[5]; } LightF2984;
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 mlAbsF(f32 param_0);
extern f32 func_80013AAC(f32);
extern f32 func_800138D0(f32);
extern f32 func_80013A7C(f32, f32);

void func_800F23D0(f32 *param_0, f32 *param_1, s32 param_2) {
    s32 i;
    f32 local_0[3];

    func_800EE7F8(local_0, param_2);
    for (i = 0; i < 3; i++) {
        param_1[i] = local_0[0] * param_0[i] + local_0[1] * param_0[i+4] + local_0[2] * param_0[i+8] + param_0[i+12];
    }
}

void func_800F2454(u8 *param_0, u8 *param_1, s32 param_2)
{
  s32 var_v1;
  f32 local_0[3];
  u8 *var_a0;
  u8 *var_v0;
  func_800EE7F8(local_0, param_2);
  var_v1 = 0;
  var_a0 = param_1;
  var_v0 = param_0;
  do
  {
    var_v1++;
    var_a0 += 4;
    *((f32 *) (var_a0 - 4)) = ((local_0[0] * (*((f32 *) var_v0))) + (local_0[1] * (*((f32 *) (var_v0 + 0x10))))) + (local_0[2] * (*((f32 *) (var_v0 + 0x20))));
    var_v0 += 4;
  }
  while (var_v1 != 3);
}

void func_800F24D0(u8 *param_0, u8 *param_1, s32 param_2)
{
  s32 var_v1;
  f32 sp20[3];
  u8 *var_a0;
  u8 *var_v0;
  func_800EE7F8(sp20, param_2);
  var_v0 = param_1;
  var_v1 = 0;
  var_a0 = var_v0;
  var_v0 = param_0;
  while (var_v1 != 3)
  {
    var_v1++;
    var_a0 += 4;
    *((f32 *) (var_a0 - 4)) = ((sp20[0] * (*((f32 *) var_v0))) + (sp20[1] * (*((f32 *) (var_v0 + 4))))) + (sp20[2] * (*((f32 *) (var_v0 + 8))));
    var_v0 += 16;
  }

}

void func_800F254C(f32 param_0[4][4], f32 *param_1, f32 param_2) {
    f32 local_0, local_1, local_2, local_3, local_4;
    f32 local_5, local_6;
    func_800EF2A0(param_1);
    local_0 = func_800137F4(param_2);
    local_1 = func_80013788();
    local_5 = 1.0f - local_1;
    local_2 = param_1[0] * param_1[1] * local_5;
    local_3 = param_1[1] * param_1[2] * local_5;
    local_4 = param_1[2] * param_1[0] * local_5;
    func_800F274C(param_0);
    local_6 = param_1[0] * param_1[0];
    param_0[0][0] = (1.0f - local_6) * local_1 + local_6;
    param_0[2][1] = local_3 - param_1[0] * local_0;
    param_0[1][2] = param_1[0] * local_0 + local_3;
    local_6 = param_1[1] * param_1[1];
    param_0[1][1] = (1.0f - local_6) * local_1 + local_6;
    param_0[2][0] = param_1[1] * local_0 + local_4;
    param_0[0][2] = local_4 - param_1[1] * local_0;
    local_6 = param_1[2] * param_1[2];
    param_0[2][2] = (1.0f - local_6) * local_1 + local_6;
    param_0[1][0] = local_2 - param_1[2] * local_0;
    param_0[0][1] = param_1[2] * local_0 + local_2;
}

void func_800F26B0(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_800F274C(arg0);
    arg0->m[0][0] = arg1;
    arg0->m[1][1] = arg2;
    arg0->m[2][2] = arg3;
    arg0->m[3][3] = 1.0f;
}

int func_800F2704(f32 param_0[4][4], f32 param_1, f32 param_2, f32 param_3)
{
  func_800F274C();
  param_0[3][0] = param_1;
  param_0[3][1] = param_2;
  param_0[3][2] = param_3;
}

s32 func_800F274C(float mf[4][4])
{
	int	i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			mf[i][j] = (i == j) ? 1 : 0;
}

void func_800F27D4(f32 param_0[4][4], f32 param_1[4][4], f32 param_2[4][4]) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[4][4];
    for (local_0 = 0; local_0 < 4; local_0++) {
        for (local_1 = 0; local_1 < 4; local_1++) {
            local_3[local_0][local_1] = 0.0f;
            for (local_2 = 0; local_2 < 4; local_2++) {
                local_3[local_0][local_1] += param_0[local_0][local_2] * param_1[local_2][local_1];
            }
        }
    }
    for (local_0 = 0; local_0 < 4; local_0++) {
        for (local_1 = 0; local_1 < 4; local_1++) {
            param_2[local_0][local_1] = local_3[local_0][local_1];
        }
    }
}

void func_800F293C(R_F293C *param_0, R_F293C *param_1) {
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            param_0[i].v[j] = param_1[i].v[j];
        }
    }
}

void func_800F2984(f32 param_0[4][4], LightF2984 *param_1, f32 *param_2, f32 *param_3, f32 *param_4) {
    s32 local_0;
    f32 local_1[3], local_2[3];
    func_800EFB24(local_1, param_3, param_2);
    func_800EF368(local_1, -1.0f);
    func_800EE97C(local_2, param_4, local_1);
    func_800EF2A0(local_2);
    func_800EE97C(param_4, local_1, local_2);
    func_800EF2A0(param_4);
    func_800F274C(param_0);
    for (local_0 = 0; local_0 < 3; local_0++) {
        param_0[local_0][0] = local_2[local_0];
        param_0[local_0][1] = param_4[local_0];
        param_0[local_0][2] = local_1[local_0];
    }
    param_0[3][0] = -func_800EEAA4(param_2, local_2);
    param_0[3][1] = -func_800EEAA4(param_2, param_4);
    param_0[3][2] = -func_800EEAA4(param_2, local_1);
    param_1[0].local_1[0] = ((s32) F2984_DIR(local_2[0])) & 0xFF;
    param_1[0].local_1[1] = ((s32) F2984_DIR(local_2[1])) & 0xFF;
    param_1[0].local_1[2] = ((s32) F2984_DIR(local_2[2])) & 0xFF;
    param_1[1].local_1[0] = ((s32) F2984_DIR(param_4[0])) & 0xFF;
    param_1[1].local_1[1] = ((s32) F2984_DIR(param_4[1])) & 0xFF;
    param_1[1].local_1[2] = ((s32) F2984_DIR(param_4[2])) & 0xFF;
    param_1[0].local_0[0] = 0;
    param_1[0].local_0[1] = 0;
    param_1[0].local_0[2] = 0;
    param_1[0].local_0[3] = 0;
    param_1[0].local_0[4] = 0;
    param_1[0].local_0[5] = 0;
    param_1[0].local_0[6] = 0;
    param_1[0].local_0[7] = 0;
    param_1[1].local_0[0] = 0;
    param_1[1].local_0[1] = 128;
    param_1[1].local_0[2] = 0;
    param_1[1].local_0[3] = 0;
    param_1[1].local_0[4] = 0;
    param_1[1].local_0[5] = 128;
    param_1[1].local_0[6] = 0;
    param_1[1].local_0[7] = 0;
}

void func_800F2C1C(u8 *param_0, u8 *param_1) {
    f32 local_1;
    f32 local_0;

    if (1e-05f < (1.0f - mlAbsF((*(f32 *)((s8 *)(param_0) + (0x24)))))) {
        local_0 = func_80013AAC(-( *(f32 *)((s8 *)(param_0) + (0x24))) );
        (*(f32 *)((s8 *)(param_1) + (0))) = local_0;
        local_1 = func_800138D0(local_0);
    } else {
        local_1 = 0.0f;
        if ((*(f32 *)((s8 *)(param_0) + (0x24))) < 0.0f) {
            (*(f32 *)((s8 *)(param_1) + (0))) = 90.0f;
        } else {
            (*(f32 *)((s8 *)(param_1) + (0))) = -90.0f;
        }
    }
    if (local_1 != 0.0f) {
        local_1 = 1.0f / local_1;
        *(f32 *)(param_1 + 4) = func_80013AAC(*(f32 *)(param_0 + 0x20) * local_1);
        *(f32 *)(param_1 + 8) = func_80013AAC(*(f32 *)(param_0 + 4) * local_1);
    } else {
        *(f32 *)(param_1 + 4) = func_80013A7C(*(f32 *)param_0, 0.0f);
        *(f32 *)(param_1 + 8) = 0.0f;
    }
}

// Transforms a Vec4f by a MtxF.
void func_800F2D34(MtxF* mat, f32 out[4], f32 in[4]) {
    s32 pad;
    f32 in_copy[4];

    in_copy[0] = in[0];
    in_copy[1] = in[1];
    in_copy[2] = in[2];
    in_copy[3] = in[3];
    out[0] = in_copy[0] * mat->m[0][0] + in_copy[1] * mat->m[1][0] + in_copy[2] * mat->m[2][0] + in_copy[3] * mat->m[3][0];
    out[1] = in_copy[0] * mat->m[0][1] + in_copy[1] * mat->m[1][1] + in_copy[2] * mat->m[2][1] + in_copy[3] * mat->m[3][1];
    out[2] = in_copy[0] * mat->m[0][2] + in_copy[1] * mat->m[1][2] + in_copy[2] * mat->m[2][2] + in_copy[3] * mat->m[3][2];
    out[3] = in_copy[0] * mat->m[0][3] + in_copy[1] * mat->m[1][3] + in_copy[2] * mat->m[2][3] + in_copy[3] * mat->m[3][3];
}

void func_800F2E60(s32 arg0[3], s32 arg1[3]) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
}

void func_800F2E7C(s32 arg0[4], s32 arg1[4]) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
}

func_800F2EA0(u8 *param_0, u8 *param_1){
    param_0[0] = param_1[0];
    param_0[1] = param_1[1];
    param_0[2] = param_1[2];
}

func_800F2EBC(u8 *param_0, u8 *param_1){
    param_0[0] = param_1[0];
    param_0[1] = param_1[1];
    param_0[2] = param_1[2];
    param_0[3] = param_1[3];
}

s32 func_800F2EE0(s32 dst[3], u8 src[3]){
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

s32 func_800F2EFC(s32 dst[4], u8 *src){
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

func_800F2F20(u8 *param_0, s32 param_1[3]){
    param_0[0] = param_1[0];
    param_0[1] = param_1[1];
    param_0[2] = param_1[2];
}

func_800F2F3C(u8 *param_0, s32 param_1[4]) {
    param_0[0] = param_1[0];
    param_0[1] = param_1[1];
    param_0[2] = param_1[2];
    param_0[3] = param_1[3];
}

s32 func_800F2F60(s32 dst[3], s32 src[3], f32 param_2) {
    dst[0] = (s32)(src[0] * param_2);
    dst[1] = (s32)(src[1] * param_2);
    dst[2] = (s32)(src[2] * param_2);
}

void func_800F2FD0(u8 *param_0, u8 param_1[3], f32 param_2) {
    param_0[0] = (u8)((f32)param_1[0] * param_2);
    param_0[1] = (u8)((f32)param_1[1] * param_2);
    param_0[2] = (u8)((f32)param_1[2] * param_2);
}

s32 func_800F31DC(s32 *param_0, s32 param_1, s32 param_2, s32 param_3){
    param_0[0] = param_1;
    param_0[1] = param_2;
    param_0[2] = param_3;
}

s32 func_800F31EC(u8 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    param_0[0] = param_1;
    param_0[1] = param_2;
    param_0[2] = param_3;
}

s32 func_800F31FC(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    param_0[0] = param_1;
    param_0[1] = param_2;
    param_0[2] = param_3;
    param_0[3] = param_4;
}

int func_800F3214(s32 *param_0, s32 *param_1, s32 *param_2, f32 param_3) {
    param_0[0] = param_1[0] + (param_2[0] - param_1[0]) * param_3;
    param_0[1] = param_1[1] + (param_2[1] - param_1[1]) * param_3;
    param_0[2] = param_1[2] + (param_2[2] - param_1[2]) * param_3;
    return param_3 == 1.0f;
}

int func_800F32D4(s32 param_0, s32 param_1, s32 param_2, f32 param_3, f32 param_4)
{
  f32 local_0;
  local_0 = param_3 / param_4;
  if (local_0 > 1.0f)
  {
    local_0 = 1.0f;
  }
  return func_800F3214(param_0, param_1, param_2, local_0);
}

s32 func_800F3320(u8 *param_0, u8 *param_1, u8 *param_2, f32 param_3) {
    u32 local_0, local_1, local_2;
    s32 local_3, local_4, local_5;
    if (param_3 > 1.0f) param_3 = 1.0f;
    local_0 = param_1[0];
    param_0[0] = (param_2[0] - (s32)local_0) * param_3 + local_0;
    local_1 = param_1[1];
    param_0[1] = (param_2[1] - param_1[1]) * param_3 + local_1;
    local_2 = param_1[2];
    param_0[2] = (param_2[2] - param_1[2]) * param_3 + local_2;
    return param_3 == 1.0f;
}

void func_800F35AC(u8 *param_0, s32 param_1[3])
{
    s32 val;
    s32 idx;

    val = param_1[0];
    if (val < 0) {
        param_0[0] = 0;
    } else {
        idx = val >= 0x100 ? 0xff : val;
        param_0[0] = idx;
    }

    val = param_1[1];
    if (val < 0) {
        param_0[1] = 0;
    } else {
        idx = val >= 0x100 ? 0xff : val;
        param_0[1] = idx;
    }

    val = param_1[2];
    if (val < 0) {
        param_0[2] = 0;
    } else {
        idx = val >= 0x100 ? 0xff : val;
        param_0[2] = idx;
    }
}

void func_800F362C(u8 *param_0, s32 param_1[4])
{
  s32 local_0;
  s32 local_1;

  local_0 = param_1[0];
  if (local_0 < 0)
  {
    param_0[0] = 0;
  }
  else
  {
    if (local_0 >= 0x100)
    {
      local_1 = 0xFF;
    }
    else
    {
      local_1 = local_0;
    }
    param_0[0] = local_1;
  }

  local_0 = param_1[1];
  if (local_0 < 0)
  {
    param_0[1] = 0;
  }
  else
  {
    if (local_0 >= 0x100)
    {
      local_1 = 0xFF;
    }
    else
    {
      local_1 = local_0;
    }
    param_0[1] = local_1;
  }

  local_0 = param_1[2];
  if (local_0 < 0)
  {
    param_0[2] = 0;
  }
  else
  {
    if (local_0 >= 0x100)
    {
      local_1 = 0xFF;
    }
    else
    {
      local_1 = local_0;
    }
    param_0[2] = local_1;
  }

  local_0 = param_1[3];
  if (local_0 < 0)
  {
    param_0[3] = 0;
  }
  else
  {
    if (local_0 >= 0x100)
    {
      local_1 = 0xFF;
    }
    else
    {
      local_1 = local_0;
    }
    param_0[3] = local_1;
  }
}

int func_800F36D4(s32 *param_0, s32 *param_1)
{
  s32 v0 = param_0[0] == param_1[0];
  if (v0)
  {
    s32 v1 = param_0[1] == param_1[1];
    if (v1)
    {
      return param_0[2] == param_1[2];
      return 0;
    }
  }
}

int func_800F371C(u32 arg0[4], u32 arg1[4]) {
    return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2] && arg0[3] == arg1[3];
}
