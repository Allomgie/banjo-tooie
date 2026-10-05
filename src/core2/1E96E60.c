#include "common.h"

extern s32 D_80128454;
typedef struct { s32 pad0; s32 lo[3]; s32 hi[3]; u8 pad1C[0x24]; f32 scale; } StructBD708;
typedef struct { u32 field_0, field_4; } GridCell;
typedef struct { GridCell *field_0; u8 pad_4[0x30]; GridCell field_34; } GridState;
extern f32 D_80128450;
extern s32 D_80128414[];
extern void func_800EFB58(s32 *, s32 *, s32 *);
extern s32 D_80128444[];
extern s16 D_8012844C;
typedef struct { s16 local_0[4]; } CellBE;
typedef struct { CellBE *local_0; s32 local_1[3]; s32 pad10[3]; s32 local_2[2]; s32 pad24; s32 local_4[3]; } GridBE;
extern CellBE *D_80128458[];
extern s32 func_800E9DC4();
extern int D_801284C8[];
extern s32 D_80128538[];
extern s32 func_800E9DCC();
extern s32 D_80128420;
extern s32 D_80128438;
extern s32 D_8012842C;
extern u8 D_8012844E[];


typedef union {
    StructBD708 StructBD708;
    GridState GridState;
    u8* u8p;
    GridBE GridBE;
    s32 arr[1];
} Union_D_80128410;
extern Union_D_80128410 D_80128410;
extern s32 D_80128434;

void func_800BD570()
{
    _gccubeDll_entrypoint_1(&D_80128410);
}

int func_800BD594(s32 param_0)
{
  if (func_800EA068(0x200))
  {
    func_8010A874(param_0);
  }
  else
  {
    func_800D3104(param_0, ((s32 *) D_80128410.arr));
  }
}

void func_800BD5DC()
{
    _gccubeDll_entrypoint_2(&D_80128410);
}

void func_800BD600(void) {
    (*(s32 *)((s8 *)(((s32 *) D_80128410.arr)) + (0))) = defrag((*(s32 *)((s8 *)(((s32 *) D_80128410.arr)) + (0))));
    D_80128454 = defrag((*(s32 *)((s8 *)(((s32 *) D_80128410.arr)) + (0x44))));
    func_800E9DF8();
    func_800D2EE4();
}

void func_800BD64C(s32 *param_0, f32 *param_1) {
    s32 local_0;
    for (local_0 = 0; local_0 < 3; local_0++) {
        if (param_1[local_0] >= 0.0f) param_0[local_0] = (s32)(*(f32 *)((u8 *)D_80128410.arr + 0x40) * param_1[local_0]);
        else param_0[local_0] = (s32)(*(f32 *)((u8 *)D_80128410.arr + 0x40) * param_1[local_0] + -1.0f);
        if (param_0[local_0] < D_80128410.arr[1 + local_0]) param_0[local_0] = D_80128410.arr[1 + local_0];
        if (D_80128410.arr[4 + local_0] < param_0[local_0]) param_0[local_0] = D_80128410.arr[4 + local_0];
    }
}

void func_800BD708(s32 *param_0, s32 *param_1, f32 *param_2, f32 *param_3, f32 param_4)
{
    s32 local_0;
    StructBD708 *local_3 = ((StructBD708 *) D_80128410.arr);
    f32 local_1, local_2;
    for (local_0 = 0; local_0 < 3; local_0++) {
        local_1 = param_2[local_0] <= param_3[local_0] ? param_2[local_0] : param_3[local_0];
        local_2 = local_1 - param_4;
        if (local_2 >= 0.0f) param_0[local_0] = local_2 * D_80128410.StructBD708.scale;
        else param_0[local_0] = local_2 * D_80128410.StructBD708.scale + -1.0f;
        if (param_0[local_0] < D_80128410.StructBD708.lo[local_0]) param_0[local_0] = D_80128410.StructBD708.lo[local_0];
        local_1 = param_3[local_0] <= param_2[local_0] ? param_2[local_0] : param_3[local_0];
        local_2 = local_1 + param_4;
        if (local_2 >= 0.0f) param_1[local_0] = local_2 * D_80128410.StructBD708.scale;
        else param_1[local_0] = local_2 * D_80128410.StructBD708.scale + -1.0f;
        if (local_3->hi[local_0] < param_1[local_0]) param_1[local_0] = local_3->hi[local_0];
    }
}

void func_800BD860(s32 param_0, s32 *param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    local_0 = (param_0 - D_80128410.arr[0]) >> 3;
    param_1[2] = local_0 / D_80128410.arr[8];
    local_1 = local_0 - param_1[2] * D_80128410.arr[8];
    param_1[1] = local_1 / D_80128410.arr[7];
    param_1[0] = local_1 - param_1[1] * D_80128410.arr[7];
    for (local_2 = 0; local_2 < 3; local_2++) param_1[local_2] += D_80128410.arr[local_2 + 1];
}

s32 func_800BD948(GridCell *param_0) {
    return param_0 == &D_80128410.GridState.field_34 ? -1 : param_0 - D_80128410.GridState.field_0;
}

s32 func_800BD97C(param_0) s32 *param_0; {
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2;
    for (local_2 = 0; local_2 < 3; local_2++) {
        if (param_0[local_2] >= 0) local_0[local_2] = param_0[local_2] * D_80128450;
        else local_0[local_2] = param_0[local_2] * D_80128450 + -1.0f;
    }
    if (local_0[0] < D_80128410.arr[1] || local_0[1] < D_80128410.arr[2] || local_0[2] < D_80128410.arr[3] ||
        D_80128410.arr[4] < local_0[0] || D_80128410.arr[5] < local_0[1] || D_80128410.arr[6] < local_0[2]) return -1;
    func_800EFB58(local_1, local_0, D_80128414);
    return local_1[0] + local_1[1] * D_80128410.arr[7] + local_1[2] * D_80128410.arr[8];
}

int func_800BDAD4(OSViCommonRegs *param_0)
{


  if (((s32 *)param_0)[0] < D_80128410.arr[1] || ((s32 *)param_0)[1] < D_80128410.arr[2] || ((s32 *)param_0)[2] < D_80128410.arr[3] ||
      D_80128410.arr[4] < ((s32 *)param_0)[0] || D_80128410.arr[5] < ((s32 *)param_0)[1] || D_80128410.arr[6] < ((s32 *)param_0)[2])
  {
    return (int)(&D_80128444);
  }

  return D_80128410.arr[0] + (((s32 *)param_0)[0] - D_80128410.arr[1]) * 8 +
         (((s32 *)param_0)[1] - D_80128410.arr[2]) * D_80128410.arr[7] * 8 +
         (((s32 *)param_0)[2] - D_80128410.arr[3]) * D_80128410.arr[8] * 8;
}

int func_800BDB9C(s32 param_0)
{
    int local_0;
    if (param_0 < 0) {
        local_0 = (u32)((int *) D_80128444);
    } else {
        local_0 = (u32)(D_80128410.u8p + param_0 * 8);
    }
    return local_0;
}

int func_800BDBC4()
{
    func_800BDB9C(func_800BD97C());
}

s32 func_800BDBEC(f32 *param_0)
{
    s32 local_0[3];

    local_0[0] = param_0[0];
    local_0[1] = param_0[1];
    local_0[2] = param_0[2];
    return func_800BDBC4(local_0);
}

int func_800BDC44()
{
  return (int)((s32 *) D_80128444);
}

s32 func_800BDC50()
{
    return D_80128434;
}

int func_800BDC5C()
{
  return D_8012844C;
}

int func_800BDC68(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _gccubeDll_entrypoint_3(((s32 *) D_80128410.arr), local_0);
}

int func_800BDC90(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _gccubeDll_entrypoint_4(((s32 *) D_80128410.arr), local_0);
  return;
}

void func_800BDCB8()
{
    _gccubeDll_entrypoint_0(&D_80128410);
}

void func_800BDCDC()
{
    _gccubeDll_entrypoint_5(&D_80128410);
}

void func_800BDD00()
{
    _gccubeDll_entrypoint_6(&D_80128410);
}

CellBE **func_800BDD24(s32 *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3[3];
    s32 local_4[3];
    s32 local_5;
    for (local_1 = 0; local_1 < 3; local_1++) {
        local_3[local_1] = ((param_0[local_1] >= 0)
        ? param_0[local_1] * D_80128450
        : param_0[local_1] * D_80128450) - D_80128410.GridBE.local_1[local_1];
    }
    local_1 = 0;
    if (local_3[0] > 0 && local_3[0] < D_80128410.GridBE.local_4[0] - 1
    && local_3[1] > 0 && local_3[1] < D_80128410.GridBE.local_4[1] - 1
    && local_3[2] > 0 && local_3[2] < D_80128410.GridBE.local_4[2] - 1) {
        local_2 = (local_3[0] - 1) + (local_3[1] - 1) * D_80128410.GridBE.local_2[0]
        + (local_3[2] - 1) * D_80128410.GridBE.local_2[1];
        local_5 = local_2;
        for (local_4[0] = 0; local_4[0] < 3; local_4[0]++, local_2 += D_80128410.GridBE.local_2[1], local_5 = local_2) {
            for (local_4[1] = 0; local_4[1] < 3; local_4[1]++, local_5 += D_80128410.GridBE.local_2[0] - 3) {
                for (local_4[2] = 0; local_4[2] < 3; local_4[2]++, local_5++) {
                    if (func_800E9DC4((s16 *)(local_5 + D_80128410.GridBE.local_0))) {
                        D_80128458[local_1++] = local_5 + D_80128410.GridBE.local_0;
                    }
                }
            }
        }
    } else {
        for (local_4[0] = local_3[0] - 1; local_4[0] < local_3[0] + 2; local_4[0]++) {
            if (local_4[0] >= 0 && local_4[0] < D_80128410.GridBE.local_4[0]) {
                for (local_4[1] = local_3[1] - 1; local_4[1] < local_3[1] + 2; local_4[1]++) {
                    if (local_4[1] >= 0 && local_4[1] < D_80128410.GridBE.local_4[1]) {
                        for (local_4[2] = local_3[2] - 1; local_4[2] < local_3[2] + 2; local_4[2]++) {
                            if (local_4[2] >= 0 && local_4[2] < D_80128410.GridBE.local_4[2]) {
                                local_5 = local_4[0] + local_4[1] * D_80128410.GridBE.local_2[0]
                                + local_4[2] * D_80128410.GridBE.local_2[1];
                                if (func_800E9DC4((s16 *)(local_5 + D_80128410.GridBE.local_0))) {
                                    D_80128458[local_1++] = local_5 + D_80128410.GridBE.local_0;
                                }
                        } }
                } }
        } }
    }
    D_80128458[local_1] = 0;
    return D_80128458;
}

s32 func_800BE09C(CellBE **param_0, s32 *param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3[3];
    s32 local_4[3];
    s32 local_5;
    for (local_1 = 0; local_1 < 3; local_1++) {
        local_3[local_1] = ((param_1[local_1] >= 0)
        ? param_1[local_1] * D_80128450
        : param_1[local_1] * D_80128450) - D_80128410.GridBE.local_1[local_1];
    }
    local_1 = 0;
    if (local_3[0] > 0 && local_3[0] < D_80128410.GridBE.local_4[0] - 1
    && local_3[1] > 0 && local_3[1] < D_80128410.GridBE.local_4[1] - 1
    && local_3[2] > 0 && local_3[2] < D_80128410.GridBE.local_4[2] - 1) {
        local_2 = (local_3[0] - 1) + (local_3[1] - 1) * D_80128410.GridBE.local_2[0]
        + (local_3[2] - 1) * D_80128410.GridBE.local_2[1];
        local_5 = local_2;
        for (local_4[0] = 0; local_4[0] < 3; local_4[0]++, local_2 += D_80128410.GridBE.local_2[1], local_5 = local_2) {
            for (local_4[1] = 0; local_4[1] < 3; local_4[1]++, local_5 += D_80128410.GridBE.local_2[0] - 3) {
                for (local_4[2] = 0; local_4[2] < 3; local_4[2]++, local_5++) {
                    if (func_800E9DCC((s16 *)(local_5 + D_80128410.GridBE.local_0))) {
                        param_0[local_1++] = local_5 + D_80128410.GridBE.local_0;
                    }
                }
            }
        }
    } else {
        for (local_4[0] = local_3[0] - 1; local_4[0] < local_3[0] + 2; local_4[0]++) {
            if (local_4[0] >= 0 && local_4[0] < D_80128410.GridBE.local_4[0]) {
                for (local_4[1] = local_3[1] - 1; local_4[1] < local_3[1] + 2; local_4[1]++) {
                    if (local_4[1] >= 0 && local_4[1] < D_80128410.GridBE.local_4[1]) {
                        for (local_4[2] = local_3[2] - 1; local_4[2] < local_3[2] + 2; local_4[2]++) {
                            if (local_4[2] >= 0 && local_4[2] < D_80128410.GridBE.local_4[2]) {
                                local_5 = local_4[0] + local_4[1] * D_80128410.GridBE.local_2[0]
                                + local_4[2] * D_80128410.GridBE.local_2[1];
                                if (func_800E9DCC((s16 *)(local_5 + D_80128410.GridBE.local_0))) {
                                    param_0[local_1++] = local_5 + D_80128410.GridBE.local_0;
                                }
                        } }
                } }
        } }
    }
    return local_1;
}

int *func_800BE3F8(s32 param_0)
{
    f32 local_0[3];
    func_800EE904(local_0, param_0);
    D_801284C8[func_800BE09C(&D_801284C8, local_0)] = 0;
    return D_801284C8;
}

s32 func_800BE444(s32 param_0)
{
    f32 local_0[3];
    s32 local_1;
    func_800EE904(local_0, param_0);
    local_1 = func_800BE09C(&D_80128538, local_0);
    if (func_800E9DCC(((void * *) D_80128444))) {
        D_80128538[local_1] = (s32)((void * *) D_80128444);
        local_1++;
    }
    D_80128538[local_1] = 0;
    return (s32)D_80128538;
}

void func_800BE4C4(void)
{
  u32 s0;
  int new_var;
  u32 s1;
  s0 = *((u32 *) (((u8 *) D_80128410.arr)));
  s1 = ((*((s32 *) (&((u8 *) D_80128410.arr)[0x24]))) * 8) + s0;
  new_var = ((*((s32 *) (&((u8 *) D_80128410.arr)[0x24]))) * 8) + s0;
  if (s0 < s1)
  {
    do
    {
      func_800E9CF4((u8 *) s0);
      s0 += 8;
    }
    while (s0 < new_var);
 if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
  }
  func_800E9CF4(((u8 *) D_80128444));
}

int func_800BE52C(s32 *param_0, s32 *param_1)
{
  *param_0 = D_80128410.arr[0];
  *param_1 = D_80128410.arr[0] + (D_80128410.arr[9] << 3);
}

int func_800BE554(s32 param_0, s32 param_1)
{
  func_800EE830(param_0, ((s32 *) D_80128414));
  func_800EE830(param_1, &D_80128420);
}

int func_800BE58C(s32 param_0, s32 param_1)
{
  func_800EE830(param_0, &D_80128438);
  func_800EE830(param_1, &D_8012842C);
}

int func_800BE5C4(s32 param_0)
{
  s32 base = (s32)((u8 *) D_80128410.arr);
  if (param_0 == base + 0x34)
  {
    return (s32)D_8012844E;
  }
  return *(s32*)(base + 0x44) + ((param_0 - *(s32*)(base)) >> 3);
}
