#include "common.h"

typedef struct { s16 map, value, mode, enabled; f32 origin[3], normal[3]; } LocalEntry;
typedef struct { u8 *local_0[2], *local_1; u8 local_2, local_3, local_4, local_5, local_6, local_7; s16 local_8; f32 matrix[4][4]; u8 pad54[0x74]; u8 local_9[2][0x30]; } LocalState_800BC690;
extern LocalEntry D_8011A760[];
extern LocalState_800BC690 D_801282E0;
extern f32 D_80128324[];
extern f32 D_801282F4[4][4];
extern f32 D_80128384[];
extern f32 D_80128378[];
extern void *heap_alloc(s32);
extern f32 func_800EEAA4(f32 *,f32 *);
extern void func_800EFA20(f32 *,f32 *,f32);
extern s32 D_80128390;
extern s32 D_8012839C;
extern char D_801282ED;
extern void *D_80128338;
void func_800BCC90();

void func_800BC690(void)
{
    s32 local_3;
    s32 local_8;
    f32 local_1[3];
    local_3 = func_800EA05C();
    for (local_8 = 0; local_8 < 3; local_8++) {
        if (local_3 == D_8011A760[local_8].map) break;
    }
    if (local_8 != 3) {
        if (D_8011A760[local_8].enabled) func_800B5680((s32)D_8011A760[local_8].origin[1]);
        D_801282E0.local_6 = D_801282E0.local_3 = 1;
        D_801282E0.local_5 = D_801282E0.local_4 = 0;
        D_801282E0.local_8 = D_8011A760[local_8].value;
        D_801282E0.local_7 = D_8011A760[local_8].mode;
        D_801282E0.local_0[0] = heap_alloc(0x5DC0);
        D_801282E0.local_0[1] = heap_alloc(0x5DC0);
        func_800EF410(local_1, D_8011A760[local_8].normal);
        D_801282E0.matrix[0][0] = 1.0f - (2.0f * local_1[0]) * local_1[0];
        D_801282E0.matrix[1][0] = (2.0f * -local_1[1]) * local_1[0];
        D_801282E0.matrix[2][0] = (2.0f * -local_1[2]) * local_1[0];
        D_801282E0.matrix[0][1] = (2.0f * -local_1[0]) * local_1[1];
        D_801282E0.matrix[1][1] = 1.0f - (2.0f * local_1[1]) * local_1[1];
        D_801282E0.matrix[2][1] = (2.0f * -local_1[2]) * local_1[1];
        D_801282E0.matrix[0][2] = (2.0f * -local_1[0]) * local_1[2];
        D_801282E0.matrix[1][2] = (2.0f * -local_1[1]) * local_1[2];
        D_801282E0.matrix[2][2] = 1.0f - (2.0f * local_1[2]) * local_1[2];
        D_801282E0.matrix[0][3] = D_801282E0.matrix[1][3] = D_801282E0.matrix[2][3] = 0.0f;
        func_800EFA20(D_80128324, local_1, 2.0f * func_800EEAA4(D_8011A760[local_8].origin, local_1));
        D_801282E0.matrix[3][3] = 1.0f;
        guMtxF2L(D_801282F4, ((Mtx *) &D_80128338));
        func_800EE7F8(D_80128384, local_1);
        func_800EE7F8(D_80128378, D_8011A760[local_8].origin);
    }
}

void func_800BC8A0()
{
    if (((u8 *) &D_801282E0)[0xd] != 0) {
        heap_free(*(u32 *)&((u8 *) &D_801282E0)[0]);
        heap_free(*(u32 *)&((u8 *) &D_801282E0)[4]);
        *(u32 *)&((u8 *) &D_801282E0)[4] = 0;
        *(u32 *)&((u8 *) &D_801282E0)[0] = 0;
        ((u8 *) &D_801282E0)[0xd] = 0;
    }
}

int func_800BC8F8(s32 *param_0)
{
  if (*(u8 *)((char *)((int *) &D_801282E0) + 0xD))
  {
    ((int *) &D_801282E0)[2] = param_0[0];
    param_0[0] = ((int *) &D_801282E0)[*(u8 *)((char *)((int *) &D_801282E0) + 0xC)];
    func_800E42E4(1);
  }
}

void func_800BC948(u8 **param_0)
{
  u8 *local_0;
  u8 *local_1;
  u8 *local_4;
  u8 *local_5;
  u8 *local_6;
  u8 *local_7;
  u8 *local_8;
  u8 *local_9;
  s32 local_3;
  u8 *local_10;
  u8 *local_11;
  u8 *local_12;
  if (D_801282E0.local_3 != 0)
  {
    D_801282E0.local_6 = 0;
    local_7 = *param_0;
    *param_0 = local_7 + 8;
    *((s32 *) (local_7 + 4)) = 0;
    *((s32 *) local_7) = 0xDF000000;
    local_4 = D_801282E0.local_0[D_801282E0.local_2];
    osWritebackDCache(local_4, (((s32) ((*param_0) - local_4)) >> 3) * 8);
    *param_0 = D_801282E0.local_1;
    func_800E42E4(0);
    local_0 = D_801282E0.local_9[D_801282E0.local_2];
    func_800E4640(&local_0);
    func_800BCC90(&local_0);
    local_5 = local_0;
    local_0 = local_5 + 8;
    *((s32 *) (local_5 + 4)) = 0;
    *((s32 *) local_5) = 0xDF000000;
    local_1 = local_0;
    func_800E4640(&local_0);
    local_6 = local_0;
    local_0 = local_6 + 8;
    *((s32 *) (local_6 + 4)) = 0;
    goto dummy_label_498827;
    dummy_label_498827:
    ;

    ;
    ;
    ;
    ;
    ;
    ;
    *((s32 *) local_6) = 0xDF000000;
    local_8 = ((u8 *)&D_801282E0 + D_801282E0.local_2 * 0x30);
    osWritebackDCache(local_8 + 0xC8, (((s32) ((local_0 - local_8) - 0xC8)) >> 3) * 8);
    if ((D_801282E0.local_4 == 0) || (func_800CAA24(func_800E42A8(), &D_80128390, &D_8012839C) != 0))
    {
      func_800E46E0(param_0, D_801282E0.local_9[D_801282E0.local_2]);
      func_800BCC90(param_0);
      local_9 = *param_0;
      *param_0 = local_9 + 8;
      *((s32 *) (local_9 + 4)) = 0;
      *((s32 *) local_9) = 0xD9FFF9FF;
      func_800E7FF8(param_0, 0x200);
      if (!param_0)
      {
      }
      local_10 = *param_0;
      *param_0 = local_10 + 8;
      *((s32 *) local_10) = 0xDE000000;
      *((s32 *) (local_10 + 4)) = (s32) (((s32)D_801282E0.local_0[D_801282E0.local_2]) + ((0, 0x80000000)));
      func_800E4640(param_0);
      if ((&D_801282E0 && &D_801282E0) && &D_801282E0)
      {
      }
      local_11 = *param_0;
      *param_0 = local_11 + 8;
      *((s32 *) (local_11 + 4)) = 0;
      *((s32 *) local_11) = 0xD9FFF9FF;
      func_800E7FF8(param_0, 0x400);
      if ((D_801282E0.local_8) != 0)
      {
        local_3 = func_800D674C(D_801282E0.local_8);
        if (D_801282E0.local_5 == 0)
        {
          func_800B21CC(func_800B2840(local_3), &D_80128390, &D_8012839C);
          D_801282E0.local_5 = (D_801282E0.local_4 = 1);
        }
        func_800DF440(0);
        func_800DF830(1);
        func_800DF410(D_801282E0.local_7);
        func_800DE498(param_0, 0, 0, 0x3F800000, 0, local_3);
      }
      D_801282E0.local_6 = 1;
    }
    func_800E46E0(param_0, local_1);
    if (param_0)
    {
    }
    local_12 = *param_0;
    *param_0 = local_12 + 8;
    *((s32 *) local_12) = 0xDE000000;
    *((s32 *) (local_12 + 4)) = (s32) (((s32)D_801282E0.local_0[D_801282E0.local_2]) + 0x80000000);
    D_801282E0.local_2 ^= 1;
  }
}

int func_800BCC28(s32 param_0, s32 param_1)
{
  func_800F23D0(((s32 *) D_801282F4), param_0 | 0, param_1 | 0);
}

int func_800BCC58()
{
  u8 *local_0 = ((int *) &D_801282E0);
  local_0 += 0;
  return local_0[0xD] && local_0[0x10];
}

u8 func_800BCC84()
{
  return D_801282ED;
}

void func_800BCC90(param_0) s32 * param_0;
{
  s32 local_0 = param_0[0];
  s32 *new_var2;
  new_var2 = (s32 *) local_0;
  param_0[0] += 8;
 *new_var2 = 0xDA380005U; new_var2[1] = (s32) ((u8 *) &D_80128338 - 0x80000000);
}
