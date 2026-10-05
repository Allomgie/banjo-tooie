#include "common.h"

extern f32 func_800E42C0(void);
extern f32 D_80125B00;
extern s32 func_800E3D0C(f32 *, f32 *);
typedef struct { s16 pad[4]; } CellD31;
typedef struct { CellD31 *local_0; s32 local_1[3]; s32 pad10[3]; s32 local_2[2]; s32 pad24; s32 local_3[3]; CellD31 local_4; } GridD31;
extern void func_800EB800(void);
extern void func_800E3980(f32 *);
extern void func_800E3958(f32 *);
extern void func_800BD64C(s32 *, f32 *);
extern void func_800EFB58(s32 *, s32 *, s32 *);
extern void func_800EFD3C(s32 *);
extern void func_800EFA88(s32 *, s32, s32, s32);
extern s32 func_800BCC58(void);
extern s32 func_800F0E28(s32, s32);
extern s32 func_800BDC5C(void);
extern s32 func_800E9DCC();
extern f32 mlAbsF(f32);
extern void func_800EB5E0(CellD31 *, void *);
extern s8 D_8012B370[];
typedef struct {
    s16 id;
    u8 unk2;
    u8 unk3;
    s32 ptr;
} Entry_8011B560;

Entry_8011B560 D_8011B560[4] = {
    { 0x0C21, 8, 0, 0 },
    { 0x0C22, 0x10, 0, 0 },
    { 0x0C20, 0x10, 0, 0 },
    { 0x0C23, 6, 0, 0 },
};
u8 D_8011B580[] = "0123456789:ABCDEFGHIJKLMNOPQRSTUVWXYZ@%?()<>\".;-!/'";
extern s32 func_800D6C34(s32);

int func_800D2F20()
{
  return func_800BDC5C() << 2;
}

s32 func_800D2F44(s32 param_0, s32 *param_1, s32 param_2, f32 *param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    local_3 = func_800E42C0();
    local_2[0] = param_1[0] * param_2 + param_2 / 2 - param_3[0];
    local_2[1] = param_1[1] * param_2 + param_2 / 2 - param_3[1];
    local_2[2] = param_1[2] * param_2 + param_2 / 2 - param_3[2];
    local_3 = local_3 * 4.0f * (D_80125B00 * param_2);
    if (local_3 * local_3 < local_2[0] * local_2[0] + local_2[1] * local_2[1] + local_2[2] * local_2[2]) return 0;
    for (local_4 = 0; local_4 < 3; local_4++) {
        local_0[local_4] = param_1[local_4] * param_2 - 150;
        local_1[local_4] = local_0[local_4] + (param_2 + 300);
    }
    return func_800E3D0C(local_0, local_1);
}

void func_800D3104(void *param_0, GridD31 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3[3];
    s32 local_4[3];
    s32 local_5[3];
    s32 local_6;
    f32 local_7;
    f32 local_8;
    s32 local_10;
    s32 local_11;
    s32 local_12;
    CellD31 *local_14;
    s32 local_13[3];
    func_800EB800();
    func_800E3980(local_0);
    func_800E3958(local_1);
    func_800BD64C(local_3, local_0);
    func_800EFB58(local_3, local_3, param_1->local_1);
    func_800EFD3C(local_4);
    func_800EFA88(local_5, param_1->local_3[0] - 1, param_1->local_3[1] - 1, param_1->local_3[2] - 1);
    if (!func_800BCC58()) {
        local_6 = 0;
        local_7 = mlAbsF(local_1[0]);
        local_8 = mlAbsF(local_1[1]);
        if (local_7 < local_8) {
            local_7 = local_8;
            local_6 = 1;
        }
        local_8 = mlAbsF(local_1[2]);
        if (local_7 < local_8) local_6 = 2;
        if (local_1[local_6] < 0.0f) local_5[local_6] = local_3[local_6];
        else if (local_6 == 1) local_4[local_6] = func_800F0E28(0, local_3[local_6] - 1);
        else local_4[local_6] = local_3[local_6];
    }
    for (local_6 = 0; local_6 < 3; local_6++) {
        if (func_800E42C0() * 4.0f < local_3[local_6] - local_4[local_6]) local_4[local_6] = local_3[local_6] - func_800E42C0() * 4.0f;
        if (func_800E42C0() * 4.0f < local_5[local_6] - local_3[local_6]) local_5[local_6] = local_3[local_6] + func_800E42C0() * 4.0f;
    }
    func_800EB5E0(&param_1->local_4, param_0);
    local_2 = func_800BDC5C();
    for (local_10 = local_4[0]; local_10 <= local_5[0]; local_10++) {
        for (local_11 = local_4[1]; local_11 <= local_5[1]; local_11++) {
            for (local_12 = local_4[2]; local_12 <= local_5[2]; local_12++) {
                local_14 = param_1->local_0 + local_10 + local_11 * param_1->local_2[0] + param_1->local_2[1] * local_12;
                local_13[0] = param_1->local_1[0] + local_10;
                local_13[1] = param_1->local_1[1] + local_11;
                local_13[2] = param_1->local_1[2] + local_12;
                if (func_800E9DCC((s16 *)local_14) && func_800D2F44(local_14, local_13, local_2, local_0)) func_800EB5E0(local_14, param_0);
            }
        }
    }
}

void func_800D34A0() {
    s32 local_5;
    s32 local_4;
    int new_var;

    local_5 = func_800E7188(D_8011B580);
    for (local_4 = 0; local_4 != 0x80; local_4 += 1) {
        new_var = 0;
        if (local_5 > 0) {
            do {
                if (local_4 == D_8011B580[new_var]) {
                    D_8012B370[local_4] = new_var;
                    break;
                }
                new_var += 1;
            } while (new_var != local_5);
        }
        if (new_var == local_5) {
            D_8012B370[local_4] = -1;
        }
    }
}

s32 func_800D674C(s32 a0);

s32 func_800D3524(s32 param_0) {
    if (D_8011B560[param_0].ptr == 0) {
        D_8011B560[param_0].ptr = func_800D674C(D_8011B560[param_0].id);
    }
    return D_8011B560[param_0].ptr;
}

int func_800D3574(s32 param_0)
{
  s32 idx = param_0 * 8;
  u8 val;
  f32 result;
  return (int) (((f32) ((u8 *)D_8011B560 + 2)[idx]) * 0.8f);
}

u8 func_800D35BC(s32 param_0)
{
  u8 *new_var;
  new_var = &((u8 *)D_8011B560 + 2)[param_0 * 8];
  return *new_var;
}

int func_800D35D0(param_0, param_1) s32 param_0; s32 param_1;
{
  s8 new_var;
  if ((((param_0 != 2) && (param_0 != 0)) && (param_1 >= 0x61)) && (param_1 < 0x7B))
  {
    param_1 -= 0x20;
  }
  switch (param_0)
  {
    case 0:
      if ((param_1 >= 0x21) && (param_1 < 0x7B))
    {
      return param_1 - 0x21;
    }
      break;

    case 1:
      if (param_1 < 0x80)
    {
      new_var = D_8012B370[param_1];
      if (new_var >= 0)
      {
        return new_var;
      }
    }
      break;

    case 2:
      if ((param_1 > 0) && (param_1 < 0xFD))
    {
      return param_1;
    }
      break;

    case 3:
      if ((param_1 >= 0x30) && (param_1 < 0x3B))
    {
      return param_1 - 0x30;
    }
    else
    {
      return 0xb;
    }

  }

  return -1;
}

void func_800D36A8(void)
{
  s32 i;

  for (i = 0; i < 4; i++)
  {
    D_8011B560[i].ptr = 0;
  }
}

int func_800D36C4(s32 param_0)
{
    s32 local_4;
    s32 local_0;

    local_0 = func_800D35D0();
    local_4 = func_800D3524(param_0);
    if ((local_0 < 0) || (local_4 == 0)) {
        return func_800D3574(param_0);
    }
    return *(u8 *)((char *)func_800B0D6C(local_4, local_0) + 2);
}

s32 func_800D3724(s32 param_0)
{
  s32 *local_0;
  s32 local_1;
  local_0 = ((s32 *) D_8011B560) + (param_0 * 2);
  if (local_0[1] != 0)
  {
    local_1 = func_800D6C34(*((s16 *) local_0));
  }
  else
  {
 if (1) { } if (1) { } if (1) { }
    local_1 = 1;
    if (!param_0)
    {
    }
  }
  return local_1;
}
