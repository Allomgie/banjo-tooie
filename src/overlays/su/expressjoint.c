#include "common.h"

#define ENT D_80801818_suexpressjoint[*(s16 *)(param_0 + 6)]
extern s16 D_80801820_suexpressjoint;
extern s16 D_80801830_suexpressjoint[];
extern s32 D_80801838_suexpressjoint[];
extern int D_80801824_suexpressjoint;
typedef struct { u8 pad_0[4]; s16 id; s16 variant; u8 active; u8 pad_1[0x17]; u8 values[32]; } ExpressionJoint_suexpressjoint_entrypoint_2;
typedef struct { u8 b0; u8 b1; u8 pad2[2]; f32 *ptr; } SejItem;
typedef u8 SejRow[4];
typedef struct { SejItem *list; SejRow *data; u16 pad_8; u8 base; u8 n1; u8 count; u8 padD[3]; } SejEnt;
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
    local_0 = D_80801838_suexpressjoint;
    local_1 = 2;
    if (param_0 == D_80801830_suexpressjoint[0]) {
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

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/expressjoint.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80801820_suexpressjoint = D_80801818_suexpressjoint + 0x8, D_80801824_suexpressjoint = D_80801818_suexpressjoint + 0xC
 * extern declarations adjusted to the object (same addresses): D_80801830_suexpressjoint -> s16[] (uses written as NAME[0]), D_80801838_suexpressjoint -> s32[] (uses written as NAME[0]) */
u32 D_80800A60_suexpressjoint[27] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x408F0A3D, 0x3F7D70A4, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x3FF851EC, 0x3F07AE14, 0x0, 0x0, 0x0, 0x3F333333, 0x3F6147AE, 0x3F800000 };
u32 D_80800ACC_suexpressjoint[27] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0xBF9D70A4, 0x3F000000, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x3EC7AE14, 0x3F000000, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800B38_suexpressjoint[27] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x3F47AE14, 0x0, 0x0, 0x0, 0x3F47AE14, 0x3F800000, 0x3F800000 };
u32 D_80800BA4_suexpressjoint[6] = { 0x2A010000, (u32)&D_80800A60_suexpressjoint, 0x2B010000, (u32)&D_80800ACC_suexpressjoint, 0x2C010000, (u32)&D_80800B38_suexpressjoint };
u32 D_80800BBC_suexpressjoint[3] = { 0x64000000, 0x640000, 0x6400 };
u32 D_80800BC8_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC0700000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC0B8F5C3, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800C58_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41C8B852, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x4178A3D7, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC117D70A, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800CE8_suexpressjoint[4] = { 0x12010000, (u32)&D_80800BC8_suexpressjoint, 0x35000000, (u32)&D_80800C58_suexpressjoint };
u32 D_80800CF8_suexpressjoint[5] = { 0x64000000, 0x640000, 0x6400, 0x64, 0x323200 };
u32 D_80800D0C_suexpressjoint[18] = { 0x0, 0x0, 0x0, 0x41F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC1600000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800D54_suexpressjoint[2] = { 0x2B000000, (u32)&D_80800D0C_suexpressjoint };
u32 D_80800D5C_suexpressjoint[3] = { 0x64000000, 0x640000, 0x320000 };
u32 D_80800D68_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x40A00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC1700000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800DF8_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0xC0A00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800E88_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC1F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80800F18_suexpressjoint[6] = { 0x2A010000, (u32)&D_80800D68_suexpressjoint, 0x4A010000, (u32)&D_80800DF8_suexpressjoint, 0x4F010000, (u32)&D_80800E88_suexpressjoint };
u32 D_80800F30_suexpressjoint[24] = { 0x64000000, 0x320000, 0x640000, 0x6400, 0x32, 0x64, 0x0, 0x0, 0x0, 0x41A00000, 0x0, 0x0, 0x40400000, 0x40400000, 0x40400000, 0x0, 0x0, 0x0, 0xC1F00000, 0x0, 0x0, 0x40800000, 0x40800000, 0x40800000 };
u32 D_80800F90_suexpressjoint[2] = { 0x3010000, (u32)&D_80800E88_suexpressjoint };
u32 D_80800F98_suexpressjoint[2] = { 0x64000000, 0x640000 };
u32 D_80800FA0_suexpressjoint[4] = { 0x2A010000, (u32)&D_80800D68_suexpressjoint, 0x4A010000, (u32)&D_80800DF8_suexpressjoint };
u32 D_80800FB0_suexpressjoint[3] = { 0x64000000, 0x320000, 0x640000 };
u32 D_80800FBC_suexpressjoint[18] = { 0x0, 0x0, 0x0, 0xC1C347AE, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC11C7AE1, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80801004_suexpressjoint[18] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0xC005C28F, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_8080104C_suexpressjoint[18] = { 0x0, 0x0, 0x0, 0xC1B80000, 0x0, 0x0, 0x3F19999A, 0x3F19999A, 0x3F19999A, 0x0, 0x0, 0x0, 0xC17EB852, 0x0, 0x0, 0x3F19999A, 0x3F19999A, 0x3F19999A };
u32 D_80801094_suexpressjoint[6] = { 0x52000000, (u32)&D_80800FBC_suexpressjoint, 0x51010000, (u32)&D_80801004_suexpressjoint, 0x53000000, (u32)&D_8080104C_suexpressjoint };
u32 D_808010AC_suexpressjoint[2] = { 0x64000000, 0x640000 };
u32 D_808010B4_suexpressjoint[9] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808010D8_suexpressjoint[9] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808010FC_suexpressjoint[4] = { 0x12000000, (u32)&D_808010B4_suexpressjoint, 0x2A000000, (u32)&D_808010D8_suexpressjoint };
u32 D_8080110C_suexpressjoint[3] = { 0x64000000, 0x64000000, 0x64000000 };
u32 D_80801118_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808011A8_suexpressjoint[2] = { 0x12010000, (u32)&D_80801118_suexpressjoint };
u32 D_808011B0_suexpressjoint[5] = { 0x1E000000, 0x640028, 0x506432, 0x3232, 0x32001E };
u32 D_808011C4_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80801254_suexpressjoint[2] = { 0x12010000, (u32)&D_808011C4_suexpressjoint };
u32 D_8080125C_suexpressjoint[3] = { 0x32000000, 0x640032, 0x6432 };
u32 D_80801268_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808012F8_suexpressjoint[2] = { 0x12010000, (u32)&D_80801268_suexpressjoint };
u32 D_80801300_suexpressjoint[3] = { 0x32000000, 0x640032, 0x6432 };
u32 D_8080130C_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_8080139C_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_8080142C_suexpressjoint[4] = { 0x29010000, (u32)&D_8080130C_suexpressjoint, 0x2A000000, (u32)&D_8080139C_suexpressjoint };
u32 D_8080143C_suexpressjoint[3] = { 0x64000000, 0x640032, 0x6432 };
u32 D_80801448_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x41200000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41A00000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x42200000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808014D8_suexpressjoint[2] = { 0x2A030000, (u32)&D_80801448_suexpressjoint };
u32 D_808014E0_suexpressjoint[3] = { 0x32000000, 0x640032, 0x6432 };
u32 D_808014EC_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_8080157C_suexpressjoint[2] = { 0x12010000, (u32)&D_808014EC_suexpressjoint };
u32 D_80801584_suexpressjoint[3] = { 0x32000000, 0x640032, 0x6432 };
u32 D_80801590_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x40A00000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41100000, 0x0, 0x40C00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41100000, 0x0, 0xC0C00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41200000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80801620_suexpressjoint[2] = { 0x12010000, (u32)&D_80801590_suexpressjoint };
u32 D_80801628_suexpressjoint[3] = { 0x64000000, 0x640000, 0x6400 };
u32 D_80801634_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x40A00000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41100000, 0x0, 0x40C00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41100000, 0x0, 0xC0C00000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x41200000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808016C4_suexpressjoint[2] = { 0x12010000, (u32)&D_80801634_suexpressjoint };
u32 D_808016CC_suexpressjoint[4] = { 0x64000000, 0x320000, 0x3200, 0x320000 };
u32 D_808016DC_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x40400000, 0x0, 0xC0000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40800000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x40A00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_8080176C_suexpressjoint[36] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_808017FC_suexpressjoint[4] = { 0x12010000, (u32)&D_808016DC_suexpressjoint, 0x2A000000, (u32)&D_8080176C_suexpressjoint };
u32 D_8080180C_suexpressjoint[3] = { 0x64000000, 0x640000, 0x6400 };
SejEnt D_80801818_suexpressjoint[1] = { (void *)&D_80800F18_suexpressjoint, (void *)&D_80800F30_suexpressjoint, 0xC, 0x0, 0x3, 0x4, 0x0, 0x0, 0x0 };
static u32 D_80801818_suexpressjoint_rest[2] = { (u32)&D_80800F18_suexpressjoint, (u32)&D_80800F30_suexpressjoint };
s16 D_80801830_suexpressjoint[4] = { 0xD, 0x3, 0x400, 0x0 };
s32 D_80801838_suexpressjoint[82] = { (u32)&D_80800F18_suexpressjoint, (u32)&D_80800F30_suexpressjoint, 0xE0003, 0x4000000, (u32)&D_80800CE8_suexpressjoint, (u32)&D_80800CF8_suexpressjoint, 0x100002, 0x4000000, (u32)&D_80800CE8_suexpressjoint, (u32)&D_80800CF8_suexpressjoint, 0x770002, 0x4000000, (u32)&D_80800D54_suexpressjoint, (u32)&D_80800D5C_suexpressjoint, 0x3A0101, 0x2000000, (u32)&D_80800BA4_suexpressjoint, (u32)&D_80800BBC_suexpressjoint, 0x420103, 0x3000000, (u32)&D_80800FA0_suexpressjoint, (u32)&D_80800FB0_suexpressjoint, 0x5B0002, 0x3000000, (u32)&D_80800F90_suexpressjoint, (u32)&D_80800F98_suexpressjoint, 0x5C0001, 0x2000000, (u32)&D_80801094_suexpressjoint, (u32)&D_808010AC_suexpressjoint, 0x750003, 0x2000000, (u32)&D_80801094_suexpressjoint, (u32)&D_808010AC_suexpressjoint, 0x760003, 0x2000000, (u32)&D_808011A8_suexpressjoint, (u32)&D_808011B0_suexpressjoint, 0x790001, 0x4000000, (u32)&D_80801254_suexpressjoint, (u32)&D_8080125C_suexpressjoint, 0x7A0001, 0x4000000, (u32)&D_808012F8_suexpressjoint, (u32)&D_80801300_suexpressjoint, 0x7E0001, 0x4000000, (u32)&D_808010FC_suexpressjoint, (u32)&D_8080110C_suexpressjoint, 0x7F0002, 0x1000000, (u32)&D_8080142C_suexpressjoint, (u32)&D_8080143C_suexpressjoint, 0x800002, 0x4000000, (u32)&D_808010FC_suexpressjoint, (u32)&D_8080110C_suexpressjoint, 0xAB0002, 0x1000000, (u32)&D_808014D8_suexpressjoint, (u32)&D_808014E0_suexpressjoint, 0x220001, 0x4000000, (u32)&D_8080157C_suexpressjoint, (u32)&D_80801584_suexpressjoint, 0xAE0001, 0x4000000, (u32)&D_80801620_suexpressjoint, (u32)&D_80801628_suexpressjoint, 0x400001, 0x4000000, (u32)&D_808016C4_suexpressjoint, (u32)&D_808016CC_suexpressjoint, 0x6F0001, 0x4000000, (u32)&D_808017FC_suexpressjoint, (u32)&D_8080180C_suexpressjoint, 0xAF0002, 0x4000000, 0x0, 0x0 };
