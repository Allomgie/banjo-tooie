#include "common.h"

#define ENT D_80801818_suexpressjoint[*(s16 *)(param_0 + 6)]
extern s16 D_80801820_suexpressjoint;
extern s16 D_80801830_suexpressjoint;
extern s32 D_80801838_suexpressjoint;
extern int D_80801824_suexpressjoint;
typedef struct { u8 pad_0[4]; s16 id; s16 variant; u8 active; u8 pad_1[0x17]; u8 values[32]; } ExpressionJoint_suexpressjoint_entrypoint_2;
typedef struct { u8 b0; u8 b1; u8 pad2[2]; f32 *ptr; } SejItem;
typedef struct { SejItem *list; u8 (*data)[4]; u16 pad_8; u8 base; u8 n1; u8 count; u8 padD[3]; } SejEnt;
typedef SejEnt ExpressionJointData;
extern SejEnt D_80801818_suexpressjoint[];
typedef struct { f32 timer; s16 id; s16 variant; u8 active; u8 pad_9[3]; f32 w[4]; f32 sum; u8 values[32]; } ExpressionJoint_suexpressjoint_entrypoint_3;
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void *func_801040A8(s32);
extern void *func_800AE6BC(void *);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void func_800E0C20(void *, s32, f32, f32, f32, f32);
extern void func_800E0B8C(void *, s32, f32, f32, f32, f32);

s32 func_80800000_suexpressjoint(s32 param_0) {
    s8 *local_0;
    s32 local_1;

    if (param_0 == D_80801820_suexpressjoint) {
        return 0;
    }
    local_0 = &D_80801838_suexpressjoint;
    local_1 = 2;
    if (param_0 == D_80801830_suexpressjoint) {
        return 1;
    }
loop_5:
    if (param_0 == (*(s16 *)((s8 *)(local_0) + (8)))) {
        return local_1;
    }
    if (param_0 == (*(s16 *)((s8 *)(local_0) + (0x18)))) {
        return local_1 + 1;
    }
    if (param_0 == (*(s16 *)((s8 *)(local_0) + (0x28)))) {
        return local_1 + 2;
    }
    if (param_0 == (*(s16 *)((s8 *)(local_0) + (0x38)))) {
        return local_1 + 3;
    }
    local_1 += 4;
    local_0 += 0x40;
    if (local_1 == 0x16) {
        return -1;
    }
    goto loop_5;
}

int suexpressjoint_entrypoint_0(param_0) s16 param_0;
{
  s32 local_0;
  int new_var;
  local_0 = func_80800000_suexpressjoint(param_0);
  if (local_0 == (-1))
  {
    return 0;
  }
  new_var = ((u8 *) (&D_80801824_suexpressjoint))[local_0 * 0x10] + 0x20;
  return new_var;
}

void suexpressjoint_entrypoint_1(s16 *param_0, s16 param_1)
{
    param_0[2] = param_1;
    param_0[3] = func_80800000_suexpressjoint(param_0[2]);
}

void suexpressjoint_entrypoint_2(ExpressionJoint_suexpressjoint_entrypoint_2 *param_0, s16 param_1)
{
    u8 *local_0;
    s32 local_1;
    local_0 = param_0->values;
    suexpressjoint_entrypoint_1((s16 *)param_0, param_1);
    param_0->active = 0;
    for (local_1 = 0; local_1 < D_80801818_suexpressjoint[param_0->variant].count; local_1++) {
        *local_0++ = D_80801818_suexpressjoint[param_0->variant].data[D_80801818_suexpressjoint[param_0->variant].base][local_1];
    }
}

void suexpressjoint_entrypoint_3(s32 param_0, ExpressionJoint_suexpressjoint_entrypoint_3 *param_1, s32 param_2)
{
    f32 sp40[4];
    s32 row;
    f32 c;
    u8 *cur;
    f32 f;
    s32 i;

    param_1->sum = 0.0f;
    cur = param_1->values;
    row = D_80801818_suexpressjoint[param_1->variant].base;
    if (param_2 != 0 && func_800D52F4() == param_1->id) {
        row = func_800D52A4() - 1;
        if (row < 0) {
            row = D_80801818_suexpressjoint[param_1->variant].base;
        }
        if (func_800D5298() != 0) {
            param_1->timer = 0.05f;
        }
        if (param_1->timer > 0.0f) {
            param_1->timer = param_1->timer - func_800D8FF8();
        } else if (param_1->timer < 0.0f) {
            row = D_80801818_suexpressjoint[param_1->variant].base;
            param_1->timer = 0.0f;
        }
        f = (100 - param_1->active) * 0.2f;
        if (f < 2.0f) {
            f = 2.0f;
        }
        param_1->active = (u32)func_800F15F8((f32)(u32)param_1->active, 100.0f, f);
    } else {
        param_1->active = (u32)((f32)(u32)param_1->active - (f32)(u32)param_1->active * 0.2f);
    }
    for (i = 0; i < D_80801818_suexpressjoint[param_1->variant].count; i++) {
        sp40[i] = (f32)(u32)D_80801818_suexpressjoint[param_1->variant].data[row][i];
        *cur = (u32)((sp40[i] - (f32)*cur) * 0.15f + (f32)*cur);
        param_1->w[i] = (f32)(u32)*cur * 0.01f;
        cur++;
        param_1->sum += param_1->w[i];
    }
    if (param_1->sum != 0.0f) {
        for (i = 0; i < D_80801818_suexpressjoint[param_1->variant].count; i++) {
            param_1->w[i] = param_1->w[i] / param_1->sum;
        }
    }
}

void suexpressjoint_entrypoint_4(u8 *param_0, s32 param_1)
{
    s32 argp_7;
    f32 f22;
    void *s4;
    f32 out1[3];
    f32 out0[3];
    f32 out2[3];
    s32 s5;
    s32 j;

    f22 = (f32)(u32)param_0[8] * 0.01f;
    s4 = func_800AE6BC(func_801040A8(param_1));
    for (s5 = 0; s5 < ENT.n1; s5++) {
        for (j = 0; j < 3; j++) {
            out0[j] = 0.0f;
            out1[j] = 0.0f;
            out2[j] = 0.0f;
            for (argp_7 = 0; argp_7 < ENT.count; argp_7++) {
                out0[j] = (((f32 (*)[9])ENT.list[s5].ptr)[argp_7][j] * ((f32 *)(param_0 + 0xC))[argp_7]) + out0[j];
                out1[j] = (((f32 (*)[9])ENT.list[s5].ptr)[argp_7][j + 3] * ((f32 *) (param_0 + 0xC))[argp_7]) + out1[j];
                out2[j] = (((f32 (*)[9])ENT.list[s5].ptr)[argp_7][j + 6] * ((f32 *) (param_0 + 0xC))[argp_7]) + out2[j];
            }
        }
        if (ENT.list[s5].b1 & 1) {
            func_800E0AFC(s4, ENT.list[s5].b0, f22, out1[0], out1[1], out1[2]);
        } else {
            func_800E0AFC(s4, ENT.list[s5].b0, -f22, out1[0], out1[1], out1[2]);
        }
        if (ENT.list[s5].b1 & 2) {
            func_800E0C20(s4, ENT.list[s5].b0, f22, out0[0], out0[1], out0[2]);
        } else {
            func_800E0C20(s4, ENT.list[s5].b0, -f22, out0[0], out0[1], out0[2]);
        }
        if (ENT.list[s5].b1 & 4) {
            func_800E0B8C(s4, ENT.list[s5].b0, f22, out2[0], out2[1], out2[2]);
        } else {
            func_800E0B8C(s4, ENT.list[s5].b0, -f22, out2[0], out2[1], out2[2]);
        }
    }
}
