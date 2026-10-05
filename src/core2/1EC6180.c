#include "common.h"

extern void _glidmake_entrypoint_2();
extern s16 D_80123580[];
typedef struct { u8 pad[12]; u8 local_0[4]; } VertexColor;
typedef struct { u8 pad[0x50]; f32 local_0[4], local_1[4]; f32 local_2, local_3; f32 local_4[4], local_5[4]; f32 local_6, local_7; } ColorState;
typedef struct { s16 local_0[3]; u8 pad[10]; } VertexECEEC;
typedef struct { u8 pad[0x2C]; f32 local_0[3]; f32 local_1[3]; f32 local_2; f32 local_3; } StateECEEC;
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
typedef struct { s16 local_0[3]; s16 pad[5]; } VertexED;
typedef struct { u8 pad[0x78]; f32 local_0[4], local_1[4], local_2, local_3; } ColorED144;
typedef struct { s32 pad_0; f32 local_0; f32 local_1; u8 pad_1[8]; s16 local_2[6]; u8 pad_2[0x24]; f32 local_3; f32 local_4; } StateED7F8;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF9A8(f32 *, f32 *, f32);
extern u8 unk60[];
extern u8 unk68[];
extern u8 unk64[];
extern u8 unk5C[];
typedef struct LocalEffect LocalEffect;
struct LocalEffect {
    u8 sound;
    u8 pad01[0xF];
    void (*callback)(LocalEffect *);
    u8 pad14[0xC];
    f32 pitchMin, pitchMax;
    u8 pending, mode;
    u8 pad2A[0x1A];
    f32 time, duration;
    s16 current, target;
    u8 pad50[0x20];
    f32 time2, duration2;
    u8 pad78[0x20];
    f32 time3, duration3;
};

extern f32 func_800D8FF8(void);
extern f32 func_800C395C(u8);
extern s32 func_800C3920(u8);
extern f32 func_800DC264(f32, f32);
extern s32 func_800DC214(s32, s32);
extern void func_800C31DC(u8, f32);
extern void func_800C3058(u8, s32);
extern void func_800C2FDC(u8);
extern void _glid_entrypoint_0(s32, s32, void (*)(), LocalEffect *);
void func_800EE010();
void func_800EE040(u8 *param_0, long param_1, f32 param_2, f32 param_3);

void func_800EC890(s32 arg0) 
{
}
void func_800EC898(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s16 *local_0;
  s16 local_1;
  s16 local_2;
  s32 local_3;
  s32 local_4;
  local_4 = func_800EA05C();
  local_0 = D_80123580;
  ;
  while (local_0[0] != 0)
  {
    if ((local_4 == local_0[0]) && (param_3 == local_0[1]))
    {
      break;
    }
    local_2 = local_0[4];
    local_0 += 4;
  }

  *((f32 *) (((s8 *) param_0) + 0x14)) = (f32) (2048.0f / ((f32) local_0[2]));
  *((f32 *) (((s8 *) param_0) + 0xC)) = (f32) (local_0[3] << 6);
  _glidmake_entrypoint_2((void *)param_2, param_3, (s16 *)param_0, (s16 *)(param_0 + 6));
  local_3 = param_1 / 10;
  if (local_3 & 1)
  {
    *((s8 *) (((s8 *) param_0) + 0x1A)) = 0;
  }
  else
  {
    *((s8 *) (((s8 *) param_0) + 0x1A)) = 1;
  }
  if (local_3 & 2)
  {
    *((s8 *) (((s8 *) param_0) + 0x1B)) = 0;
  }
  else
  {
    *((s8 *) (((s8 *) param_0) + 0x1B)) = 1;
  }
  if (local_3 & 4)
  {
    *((s8 *) (((s8 *) param_0) + 0x1C)) = 0;
  }
  else
  {
    *((s8 *) (((s8 *) param_0) + 0x1C)) = 1;
  }
  local_1 = *((s16 *) (((s8 *) param_0) + 0x18));
  if (local_1 == 0)
  {
    *((s8 *) (((s8 *) param_0) + 0x1C)) = 0;
    return;
  }
  *((f32 *) (((s8 *) param_0) + 0x10)) = (f32) (50.0f / ((f32) local_1));
}

void func_800EC9E0(s32 arg0, s32 arg1, s32 arg2) {
}
void func_800EC9F0(void *param_0, VertexColor *param_1, VertexColor *param_2, s32 param_3, ColorState *param_4)
{
    f32 local_0;
    f32 local_1[4];
    VertexColor *local_2;
    local_0 = param_4->local_2 / param_4->local_3;
    local_1[0] = (param_4->local_1[0] - param_4->local_0[0]) * local_0;
    local_1[1] = (param_4->local_1[1] - param_4->local_0[1]) * local_0;
    local_1[2] = (param_4->local_1[2] - param_4->local_0[2]) * local_0;
    local_1[3] = (param_4->local_1[3] - param_4->local_0[3]) * local_0;
    local_2 = param_1 + param_3;
    for (; param_1 < local_2; param_1++, param_2++) {
        param_2->local_0[0] = (param_4->local_0[0] + local_1[0]) * ((u32)param_1->local_0[0]);
        param_2->local_0[1] = (param_4->local_0[1] + local_1[1]) * ((u32)param_1->local_0[1]);
        param_2->local_0[2] = (param_4->local_0[2] + local_1[2]) * ((u32)param_1->local_0[2]);
        param_2->local_0[3] = (param_4->local_0[3] + local_1[3]) * ((u32)param_1->local_0[3]);
    }
}

void func_800ECD60(s32 param_0, VertexECEEC *param_1, VertexECEEC *param_2, s32 param_3, StateECEEC *param_4) {
    f32 local_2;
    f32 local_0[3];
    VertexECEEC *local_1;
    local_2 = param_4->local_2 / param_4->local_3;
    local_2 = local_2 * local_2 * local_2 * local_2;
    func_800EFE50(local_0, param_4->local_0, param_4->local_1, local_2);
    for (local_1 = param_1 + param_3; param_1 < local_1; param_1++, param_2++) {
        param_2->local_0[0] = param_1->local_0[0] + local_0[0];
        param_2->local_0[1] = param_1->local_0[1] + local_0[1];
        param_2->local_0[2] = param_1->local_0[2] + local_0[2];
    }
}

void func_800ECEEC(s32 param_0, VertexECEEC *param_1, VertexECEEC *param_2, s32 param_3, StateECEEC *param_4) {
    f32 local_2;
    f32 local_0[3];
    VertexECEEC *local_1;
    local_2 = param_4->local_2 / param_4->local_3;
    func_800EFE50(local_0, param_4->local_0, param_4->local_1, local_2);
    for (local_1 = param_1 + param_3; param_1 < local_1; param_1++, param_2++) {
        param_2->local_0[0] = param_1->local_0[0] + local_0[0];
        param_2->local_0[1] = param_1->local_0[1] + local_0[1];
        param_2->local_0[2] = param_1->local_0[2] + local_0[2];
    }
}

void func_800ED064(s32 param_0, VertexED *param_1, VertexED *param_2, s32 param_3, f32 *param_4) {
    s16 local_0;
    VertexED *local_1;
    local_0 = (param_4[17] / param_4[18]) * (param_4[2] - param_4[1]) + param_4[1];
    local_1 = param_1 + param_3;
    for (; param_1 < local_1; param_1++, param_2++) {
        param_2->local_0[1] = param_1->local_0[1] + local_0;
    }
}

void func_800ED0D4(s32 param_0, VertexED *param_1, VertexED *param_2, s32 param_3, f32 *param_4) {
    s16 local_0;
    VertexED *local_1;
    local_0 = (param_4[17] / param_4[18]) * (param_4[2] - param_4[1]) + param_4[1];
    local_1 = param_1 + param_3;
    for (; param_1 < local_1; param_1++, param_2++) {
        param_2->local_0[2] = param_1->local_0[2] + local_0;
    }
}

void func_800ED144(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, ColorED144 *param_4) {
    f32 local_0;
    f32 local_1[4];
    Vtx *local_2;
    local_0 = param_4->local_2 / param_4->local_3;
    local_1[0] = (param_4->local_1[0] - param_4->local_0[0]) * local_0;
    local_1[1] = (param_4->local_1[1] - param_4->local_0[1]) * local_0;
    local_1[2] = (param_4->local_1[2] - param_4->local_0[2]) * local_0;
    local_1[3] = (param_4->local_1[3] - param_4->local_0[3]) * local_0;
    local_2 = param_3 + param_1;
    for (; param_1 < local_2; param_1++, param_2++) {
        param_2->v.cn[0] = param_4->local_0[0] + local_1[0];
        param_2->v.cn[1] = param_4->local_0[1] + local_1[1];
        param_2->v.cn[2] = param_4->local_0[2] + local_1[2];
        param_2->v.cn[3] = param_4->local_0[3] + local_1[3];
    }
}

void func_800ED424(void *param_0, VertexColor *param_1, VertexColor *param_2, s32 param_3, ColorState *param_4)
{
    f32 local_0;
    f32 local_1[4];
    VertexColor *local_2;
    local_0 = param_4->local_6 / param_4->local_7;
    local_1[0] = (param_4->local_4[0] + (param_4->local_5[0] - param_4->local_4[0]) * local_0) / 255.0f;
    local_1[1] = (param_4->local_4[1] + (param_4->local_5[1] - param_4->local_4[1]) * local_0) / 255.0f;
    local_1[2] = (param_4->local_4[2] + (param_4->local_5[2] - param_4->local_4[2]) * local_0) / 255.0f;
    local_1[3] = (param_4->local_4[3] + (param_4->local_5[3] - param_4->local_4[3]) * local_0) / 255.0f;
    local_2 = param_1 + param_3;
    for (; param_1 < local_2; param_1++, param_2++) {
        param_2->local_0[0] = ((u32)param_1->local_0[0]) * local_1[0];
        param_2->local_0[1] = ((u32)param_1->local_0[1]) * local_1[1];
        param_2->local_0[2] = ((u32)param_1->local_0[2]) * local_1[2];
        param_2->local_0[3] = ((u32)param_1->local_0[3]) * local_1[3];
    }
}

void func_800ED79C(s32 param_0, u8 *param_1, u8 *param_2, s32 param_3, f32 *param_4) {
    int local_0;
    u8 *local_1;
    f32 local_2;
    local_2 = param_4[38] / param_4[39];
    local_0 = param_4[33] + (param_4[37] - param_4[33]) * local_2;
    local_1 = param_1 + param_3 * 16;
    while (param_1 < local_1) {
        param_1 += 16;
        param_2 += 16;
        param_2[-1] = local_0;
    }
}

void func_800ED7F8(s32 param_0, VertexECEEC *param_1, VertexECEEC *param_2, s32 param_3, StateED7F8 *param_4) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    VertexECEEC *local_5;
    local_2 = param_4->local_0 + (param_4->local_3 / param_4->local_4) * (param_4->local_1 - param_4->local_0);
    local_0[0] = (param_4->local_2[0] + param_4->local_2[3]) * 0.5f;
    local_0[1] = (param_4->local_2[1] + param_4->local_2[4]) * 0.5f;
    local_0[2] = 0.0f;
    for (local_5 = param_1 + param_3; param_1 < local_5; param_1++, param_2++) {
        func_800EFA4C(local_1, param_1->local_0[0] - local_0[0], param_1->local_0[1] - local_0[1], 0.0f);
        func_800EF9A8(local_1, local_1, local_2);
        param_2->local_0[0] = (s32)(local_0[0] + local_1[0]);
        param_2->local_0[1] = (s32)(local_0[1] + local_1[1]);
    }
}

void func_800ED964(f32 param_0[3])
{
  if (param_0[18] == 0.0f)
  {
    param_0[18] = 1e-05f;
  }
  {
    s32 func_ptr = *((s32 *) (&param_0[3]));
    if (func_ptr != 0)
    {
      ((void (*)(void)) func_ptr)();
    }
  }
}

void func_800ED9B4(u8 *param_0, u8 *param_1, u8 *param_2, f32 param_3, s32 param_4)
{
  s8 t6;
  s32 t7;
  t6 = 1;
  *(f32 *)(param_0 + 0x2C) = *(f32 *)(param_1 + 0);
  *(f32 *)(param_0 + 0x30) = *(f32 *)(param_1 + 4);
  *(f32 *)(param_0 + 0x34) = *(f32 *)(param_1 + 8);
  *(f32 *)(param_0 + 0x38) = *(f32 *)(param_2 + 0);
  *(f32 *)(param_0 + 0x3C) = *(f32 *)(param_2 + 4);
  *(f32 *)(param_0 + 0x40) = *(f32 *)(param_2 + 8);
  *(s8 *)(param_0 + 0x29) = t6;
  *(s16 *)(param_0 + 0x4C) = 0;
  *(f32 *)(param_0 + 0x48) = param_3;
  *(f32 *)(param_0 + 0x44) = 0.0f;
  t7 = param_4;
  *(s16 *)(param_0 + 0x4E) = (s16) t7;
  func_800ED964((f32 *) param_0);
}

s16 func_800EDA24(s32 param_0) {
    return ((s16*)param_0)[0x26];
}

int func_800EDA2C(s16 *param_0, f32 *param_1) {
    return param_0[10] <= param_1[0] && param_1[0] < param_0[13] && param_0[12] <= param_1[2] && param_1[2] < param_0[15];
}

int func_800EDAF4(u8 *param_0)
{
  int new_var2;
  int new_var;
  new_var2 = 0xFFFFFFFFFFFFFFFF;
  if ((*param_0) != 0)
  {
    new_var = ((((*param_0) & new_var2) & new_var2) & new_var2) & 0xFFFFFFFFFFFFFFFF;
    func_800C2FDC(((((new_var & new_var2) & 0xFF) & 0xFF) & 0xFF) & 0xFF);
  }
}

void func_800EDB20(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  int new_var;
  *((s8 *) (((s8 *) param_0) + 0)) = 0;
  *((s32 *) (((s8 *) param_0) + 0xC)) = 0 ^ 0;
  *((s32 *) (((s8 *) param_0) + 0x10)) = 0;
  *((s8 *) (((s8 *) param_0) + 0x29)) = 0;
  *((s8 *) (((s8 *) param_0) + 0x28)) = 0;
  *((s16 *) (((s8 *) param_0) + 0x4C)) = 0;
  *((s16 *) (((s8 *) param_0) + 0x4E)) = 0;
  *((f32 *) (((s8 *) param_0) + 0x70)) = 0.0f;
  *((f32 *) (((s8 *) param_0) + 0x74)) = 0.0f;
  *((f32 *) (((s8 *) param_0) + 0x9C)) = 0.0f;
  *((f32 *) (((s8 *) param_0) + 0x98)) = 0.0f;
  *((f32 *) (((s8 *) param_0) + 0x44)) = (int) 0.0f;
  new_var = 0x48;
  *((f32 *) (((s8 *) param_0) + new_var)) = 0;
  _glidmake_entrypoint_2(param_2, param_3, param_0 + 0x14, param_0 + 0x1A);
}

void func_800EDBA0(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 param_4)
{
    *(f32 *)((char *)param_0 + 0x2C) = param_1[0];
    *(f32 *)((char *)param_0 + 0x30) = param_1[1];
    *(f32 *)((char *)param_0 + 0x34) = param_1[2];
    *(f32 *)((char *)param_0 + 0x38) = param_2[0];
    *(f32 *)((char *)param_0 + 0x3C) = param_2[1];
    *(f32 *)((char *)param_0 + 0x40) = param_2[2];
    *(s8 *)((char *)param_0 + 0x29) = 2;
    *(s16 *)((char *)param_0 + 0x4C) = 0;
    *(f32 *)((char *)param_0 + 0x44) = 0.0f;
    *(f32 *)((char *)param_0 + 0x48) = param_3;
    *(s16 *)((char *)param_0 + 0x4E) = (s16)param_4;
    func_800ED964((f32 *) param_0);
}

int func_800EDC10(s32 param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  u8 *local_0 = (u8 *) (param_0 + 0x29);
  f32 *local_1 = (f32 *) (param_0 + 0x4);
  f32 *local_2 = (f32 *) (param_0 + 0x8);
  f32 *local_3 = (f32 *) (param_0 + 0x44);
  f32 *local_4 = (f32 *) (param_0 + 0x48);
  s16 *local_5 = (s16 *) (param_0 + 0x4C);
  s16 *local_6 = (s16 *) (param_0 + 0x4E);
  *local_0 = 3;
  *local_1 = param_1;
  *local_3 = 0.0f;
  *local_4 = param_3;
  *local_2 = param_2;
  *local_5 = 0;
  *local_6 = param_4;
  func_800ED964(param_0);
}

int func_800EDC64(s32 param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  u8 *local_0 = (u8 *) (param_0 + 0x29);
  f32 *local_1 = (f32 *) (param_0 + 0x4);
  f32 *local_2 = (f32 *) (param_0 + 0x8);
  f32 *local_3 = (f32 *) (param_0 + 0x44);
  f32 *local_4 = (f32 *) (param_0 + 0x48);
  s16 *local_5 = (s16 *) (param_0 + 0x4C);
  s16 *local_6 = (s16 *) (param_0 + 0x4E);
  *local_0 = 7;
  *local_1 = param_1;
  *local_3 = 0.0f;
  *local_4 = param_3;
  *local_2 = param_2;
  *local_5 = 0;
  *local_6 = param_4;
  func_800ED964(param_0);
}

void func_800EDCB8(s32 param_0, f32 param_1)
{
  func_800EDC10(param_0, param_1, param_1, 0, 1);
}

int func_800EDCEC(s32 param_0, f32 param_1)
{
  return func_800EDC64(param_0, param_1, param_1, 0, 1);
}

s32 func_800EDD20(s32 param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4) {
    func_800EE010(param_0);
    func_800EDC10(param_0, param_1, param_2, param_3, param_4);
}

func_800EDD68(Actor *param_0, f32 param_1[4], f32 param_2[4], f32 param_3){
    s32 local_0;
    f32 local_1;

    (*(f32 *)((char *)(param_0) + 0x50)) = param_1[0];
    (*(f32 *)((char *)(param_0) + 0x54)) = param_1[1];
    (*(f32 *)((char *)(param_0) + 0x58)) = param_1[2];
    (*(f32 *)((char *)(param_0) + 0x5C)) = param_1[3];
    (*(f32 *)((char *)(param_0) + 0x60)) = param_2[0];
    (*(f32 *)((char *)(param_0) + 0x64)) = param_2[1];
    (*(f32 *)((char *)(param_0) + 0x68)) = param_2[2];
    (*(f32 *)((char *)(param_0) + 0x6C)) = param_2[3];
    (*(u8 *)((char *)(param_0) + 0x28)) = 0;
    (*(f32 *)((char *)(param_0) + 0x70)) = 0.0f;
    if(param_3 > 0.0f){
        (*(f32 *)((char *)(param_0) + 0x74)) = param_3;
    }else{
        (*(f32 *)((char *)(param_0) + 0x74)) = 0.001f;
    }
}

void func_800EDDDC(f32 param_0[4], f32 param_1[4], f32 param_2[4], f32 param_3)
{
  param_0[20] = param_1[0];
  param_0[21] = param_1[1];
  param_0[22] = param_1[2];
  param_0[23] = param_1[3];
  param_0[24] = param_2[0];
  param_0[25] = param_2[1];
  param_0[26] = param_2[2];
  param_0[27] = param_2[3];
  *((u8 *) ((char *)param_0 + 0x28)) = 0;
  param_0[28] = 0.0f;
  if (param_3 > 0.0f)
  {
    param_0[29] = param_3;
  }
  else
  {
    param_0[29] = 0.001f;
  }
  *((u8 *) ((char *)param_0 + 0x29)) = 6;
}

void func_800EDE54(f32 param_0[10], s32 param_1[4], s32 param_2[4], f32 param_3)
{
  int new_var;
  s32 local_4;
  local_4 = 9;
  param_0[30] = param_1[0];
  param_0[31] = param_1[1];
  param_0[32] = param_1[2];
  param_0[33] = param_1[3];
  param_0[34] = param_2[0];
  param_0[35] = param_2[1];
  param_0[36] = param_2[2];
  new_var = local_4;
  param_0[37] = param_2[3];
  *((u8 *) (((u8 *) param_0) + 0x28)) = 0;
  ;
  if (param_3 > 0.0f)
  {
    param_0[39] = param_3;
  }
  else
  {
    param_0[39] = 0.001f;
  }
  param_0[38] = 0;
}

void func_800EDF2C(u8 *param_0, s32 param_1, s32 param_2, f32 param_3) {
    f32 local_0;
    local_0 = 0.0f;
    param_0[0x29] = 5;
    param_0[0x28] = 0;
    *(f32 *)&param_0[0x84] = (f32)param_1;
    *(f32 *)&param_0[0x80] = local_0;
    *(f32 *)&param_0[0x7C] = local_0;
    *(f32 *)&param_0[0x78] = local_0;
    *(f32 *)&param_0[0x94] = (f32)param_2;
    *(f32 *)&param_0[0x90] = local_0;
    *(f32 *)&param_0[0x8C] = local_0;
    *(f32 *)&param_0[0x88] = local_0;
    if (param_3 > 0) {
        *(f32 *)&param_0[0x9C] = param_3;
    } else {
        *(f32 *)&param_0[0x9C] = 0.001f;
    }
    *(f32 *)&param_0[0x98] = local_0;
}

void func_800EDF98(s32 param_0, s32 param_1) {
    func_800EDF2C(param_0, param_1, param_1, 0);
}

int func_800EDFBC(s32 param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  u8 *local_0 = (u8 *) (param_0 + 0x29);
  f32 *local_1 = (f32 *) (param_0 + 0x4);
  f32 *local_2 = (f32 *) (param_0 + 0x8);
  f32 *local_3 = (f32 *) (param_0 + 0x44);
  f32 *local_4 = (f32 *) (param_0 + 0x48);
  s16 *local_5 = (s16 *) (param_0 + 0x4C);
  s16 *local_6 = (s16 *) (param_0 + 0x4E);
  *local_0 = 4;
  *local_1 = param_1;
  *local_3 = 0.0f;
  *local_4 = param_3;
  *local_2 = param_2;
  *local_5 = 0;
  *local_6 = param_4;
  func_800ED964(param_0);
}

void func_800EE010(s32 param_0)
{
  func_800EE040((u8 *) param_0, 1004, 0.7f, 0.9f);
}

void func_800EE040(u8 *param_0, long param_1, f32 param_2, f32 param_3) {
    u8 var_a2;
    var_a2 = *param_0;
    if (var_a2 == 0) {
        *param_0 = func_800C2E04(param_0);
        var_a2 = *param_0;
    }
    *(f32 *)(param_0 + 0x20) = param_2;
    *(f32 *)(param_0 + 0x24) = param_3;
    func_800C301C(var_a2 & 0xFF, param_1, var_a2);
    func_800C330C(*param_0, 3);
    func_800C31DC(*param_0, (param_2 + param_3) * 0.5f);
    func_800C3058(*param_0, 0x7D00);
    func_800C3BDC(*param_0);
}

func_800EE0F0(s32 *param_0, s32 param_1) {
    s32 local_0;
    local_0 = param_1;
    param_0[3] = local_0;
}

func_800EE0F8(s32 *param_0, s32 param_1) {
    param_0[4] = param_1;
}

void func_800EE100(void *param_0, int param_1)
{
  s16 *new_var;
  s16 *new_var3;
  s16 *new_var2;
  new_var = (s16 *) (((char *) param_0) + 0x4A);
  new_var2 = new_var;
  new_var2++;
  new_var3 = (0, new_var = new_var2);
  new_var2--;
  *new_var3 = param_1;
}

void func_800EE108(LocalEffect *param_0, s32 param_1, s32 param_2)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    s32 local_3;

    local_0 = func_800D8FF8();
    if (param_0->duration2 > 0.0f) {
        param_0->time2 += local_0;
        if (param_0->duration2 <= param_0->time2) {
            param_0->time2 = param_0->duration2;
            if (!param_0->pending) {
            param_0->pending = 2;
        }
        }
        _glid_entrypoint_0(param_1, param_2, func_800EC9F0, param_0);
        if (param_0->pending) {
            param_0->pending--;
            if (param_0->pending == 0) {
            param_0->duration2 = 0.0f;
        }
        }
    }
    if (param_0->duration3 > 0.0f) {
        param_0->time3 += local_0;
        if (param_0->duration3 <= param_0->time3) {
            param_0->time3 = param_0->duration3;
            if (!param_0->pending) {
            param_0->pending = 2;
        }
        }
        switch (param_0->mode) {
        case 5:
            _glid_entrypoint_0(param_1, param_2, func_800ED79C, param_0);
            break;
        case 6:
            _glid_entrypoint_0(param_1, param_2, func_800ED424, param_0);
            break;
        default:
            _glid_entrypoint_0(param_1, param_2, func_800ED144, param_0);
            break;
        }
        if (param_0->pending) {
            param_0->pending--;
            if (param_0->pending == 0) {
            param_0->duration3 = 0.0f;
        }
        }
    }
    if (param_0->mode == 0 || param_0->mode == 5) return;
    {
        param_0->time += local_0;
        if (param_0->duration < param_0->time) {
            param_0->time = param_0->duration;
        }
        if (param_0->sound) {
            local_1 = param_0->time / param_0->duration;
            local_2 = func_800C395C(param_0->sound);
            local_3 = func_800C3920(param_0->sound);
            local_2 += func_800DC264(-1.0f, 1.0f) * local_0;
            local_2 = param_0->pitchMin > local_2 ? param_0->pitchMin : local_2;
            local_2 = param_0->pitchMax < local_2 ? param_0->pitchMax : local_2;
            local_3 += func_800DC214(-15, 15);
            local_3 = 0x7FFF < local_3 ? 0x7FFF : local_3;
            local_3 = 0x7918 > local_3 ? 0x7918 : local_3;
            if (local_1 >= 0.85f) {
            local_3 = (1.0f - (local_1 - 0.85f) / 0.14999998f) * local_3;
        }
            func_800C31DC(param_0->sound, local_2);
            func_800C3058(param_0->sound, local_3);
        }
        switch (param_0->mode) {
        case 1:
            _glid_entrypoint_0(param_1, param_2, func_800ECD60, param_0);
            break;
        case 2:
            _glid_entrypoint_0(param_1, param_2, func_800ECEEC, param_0);
            break;
        case 3:
            _glid_entrypoint_0(param_1, param_2, func_800ED064, param_0);
            break;
        case 4:
            _glid_entrypoint_0(param_1, param_2, func_800ED7F8, param_0);
            break;
        case 7:
            _glid_entrypoint_0(param_1, param_2, func_800ED0D4, param_0);
            break;
        }
        if (param_0->duration <= param_0->time) {
            param_0->mode = 0;
            param_0->current = param_0->target;
            if (param_0->callback) {
            param_0->callback(param_0);
        }
            if (param_0->sound) {
                func_800C2FDC(param_0->sound);
                param_0->sound = 0;
            }
        }
    }
}
