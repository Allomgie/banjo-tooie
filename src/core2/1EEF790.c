#include "core2/1EEF790.h"

f32 func_800FF060(f32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5);
f32 mlAbsF(f32 param_0);
extern void func_800F2388();
extern f32 func_800F22EC(f32*);
extern f32 func_800D8FF8(void);
typedef struct { u8 pad[0x28]; f32 local_0; u8 local_1; u8 pad_1; s16 local_2; f32 pad_2; f32 local_3; f32 pad_3; f32 local_4; f32 local_5; f32 local_6; u8 local_7; u8 pad_4[3]; f32 local_8; f32 local_9[2]; f32 local_10; } Sway116218;
typedef struct { s32 pad; Sway116218 *local_0; } State116218;
extern s32 func_80110840(State116218 *);
extern f32 func_800F5F50(s32);
extern f32 func_800136E4(f32);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
void func_80116218();

s32 func_80115EA0() 
{
    return 0x5C;
}

void func_80115EA8(f32 param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5)
{
  f32 local_0;
  f32 local_2;
  f32 local_1;

  local_0 = param_0 - (*param_1);
  local_2 = mlAbsF(local_0);
  if (0.001f < local_2)
  {
    local_1 = func_800FF060(local_0, param_2, param_4, param_5, param_3, func_800D8FF8());
    if (local_2 < mlAbsF(local_1))
    {
      *param_2 = 0.0f;
      *param_1 = param_0;
      return;
    }
    *param_1 += local_1;
    return;
  }
  *param_2 = 0.0f;
  *param_1 = param_0;
}

int func_80115F98(param_0) f32 param_0[3];
{
  f32 local_0 = 0.0;
  param_0[1] = (param_0[2] = local_0);
  param_0[0] = local_0;
}

void func_80115FB0(u8 *param_0) {
    f32 local_0;
    u8 *local_1;

    func_80115F98((*(u8 **)((s8 *)(param_0) + (4))), param_0);
    func_80115F98((*(u8 **)((s8 *)(param_0) + (4))) + 0x14, param_0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (0x4C))) = 0.0f;
    local_1 = (*(u8 **)((s8 *)(param_0) + (4)));
    local_0 = (*(f32 *)((s8 *)(local_1) + (0x4C)));
    (*(f32 *)((s8 *)(local_1) + (0x54))) = local_0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (0x50))) = local_0;
    (*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (0x2E))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (0x58))) = 1.0f;
}

void func_80116024(u8 *param_0) {
    func_80116218();
    *(u8 *)((u8 *)*(s8 **)((char *)param_0 + 4) + 0x2C) = 0;
}

void func_80116050(u8 *param_0, f32 param_1) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (4))) = param_1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (0x18))) = (f32) (param_1 * 0.5f);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (4)))) + (0x40))) = param_1;
}

void func_8011607C(void *arg, s32 v)
{
    ((s16 *)(*(void **)((char *)arg + 0x4)))[23] = v;
}

void func_80116088(u8 *param_0, s32 param_1)
{
  s8 _sfpad[8];
    s32 sp1C;

    func_801107B0(param_0, &sp1C);
    if (func_800F1E6C(&sp1C, param_1, (*(u8 **)(param_0 + 4)) + 0x28) != 0)
    {
        (*(u8 **)(param_0 + 4))[0x2C] = 1;
    }
}

void func_801160DC(PlayerState *self, f32 param_1)
{
  u8 *temp_v0;
  char *new_var;
  u8 *temp_v0_2;
  *((f32 *) ((char *) ((*((u8 **) (((char *) self) + 4))) + 0x20))) = param_1;
  temp_v0 = *((u8 **) (((char *) self) + 4));
  *((f32 *) (((char *) temp_v0) + 0xC)) = (f32) (*((f32 *) (((char *) temp_v0) + 0x20)));
  *((u8 *) ((char *) ((*((u8 **) (((char *) self) + 4))) + 0x24))) = 1U;
  if (1)
  {
    temp_v0_2 = *((u8 **) (((char *) self) + 4));
    *((u8 *) (new_var = ((char *) temp_v0_2) + 0x10)) = (u8) (*((u8 *) (((char *) temp_v0_2) + 0x24)));
    *((f32 *) ((char *) ((*((u8 **) (((char *) self) + 4))) + 0x44))) = param_1;
    *((char *) ((*((u8 **) (((char *) self) + 4))) + 0x48)) = 1;
  }
}

void func_80116120(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5) {
    f32 sp38[2];
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f2;

    func_800F2388(sp38, param_0, param_1);
    temp_f0 = func_800F22EC(sp38);
    if (0.01f < temp_f0) {
        temp_f0_2 = func_800FF060(temp_f0, param_2, param_4, param_5, param_3, func_800D8FF8());
        if (temp_f0 < temp_f0_2) {
            var_f2 = 1.0f;
            *param_2 = 0.0f;
        } else {
            var_f2 = temp_f0_2 / temp_f0;
        }
        param_1[0] += sp38[0] * var_f2;
        param_1[1] += sp38[1] * var_f2;
        return;
    }
    *param_2 = 0.0f;
}

void func_80116218(State116218 *param_0, f32 *param_1) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    local_0 = param_0->local_0->local_1 ? param_0->local_0->local_0 : func_800F5F50(func_80110840(param_0));
    local_0 = func_800136E4(param_1[1] - local_0 + 180.0f);
    if (param_0->local_0->local_2) {
        if (param_0->local_0->local_7) local_1 = param_0->local_0->local_6;
        else local_1 = param_0->local_0->local_5;
    } else local_1 = 0.0f;
    func_80115EA8(local_1, &param_0->local_0->local_3, &param_0->local_0->local_4, 20.0f, 40.0f, -10.0f);
    local_2 = func_800137AC(local_0);
    local_1 = func_800137C4();
    local_3[0] = -local_1 * param_0->local_0->local_3;
    local_3[1] = local_2 * param_0->local_0->local_3;
    func_80116120(local_3, param_0->local_0->local_9, &param_0->local_0->local_8, 20.0f, 40.0f, -10.0f);
    param_1[0] += param_0->local_0->local_10 * (param_0->local_0->local_9[1] * 0.5f);
    param_1[1] += param_0->local_0->local_10 * param_0->local_0->local_9[0];
    param_0->local_0->local_7 = 0;
}

func_801163A0(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x4) + 0x58) = param_1;
}





