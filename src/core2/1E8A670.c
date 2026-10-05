#include "common.h"

typedef struct { s16 field_0; s16 field_2[3]; u8 field_8; s8 field_9; u8 pad_A[2]; } LocalPoint;
typedef struct { s16 field_0, field_2, field_4, pad_6; u8 field_8[1]; } LocalModel_800B0D80;
extern f32 D_80127EA0[4][4];
extern void func_800EE88C();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80019CD4(void);
extern void func_80019750(f32 *, f32 *, f32, s32);
extern void mlMtxGet(f32 (*)[4]);
extern void *func_800ADE2C(void *, s32);
extern void func_80019AA0(f32 (*)[4], void *);
extern void func_80019224(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct { s16 field_0[3], field_6[3], field_C[3]; u8 field_12[3], field_15; u8 pad_16[2]; } LocalBox_800B0ECC;
typedef struct { s16 field_0; u8 pad_2[6]; LocalBox_800B0ECC field_8[1]; } LocalModel_800B0ECC;
extern void func_800EF334(f32 *, f32);
extern void func_80019A10(f32 *, f32 *);
extern void func_800193C4(f32 *, f32 *);
typedef struct { s16 local_0, local_1; s16 local_2[3]; u8 local_3[3]; u8 local_4; u8 pad[2]; } CylinderB1110;
typedef struct { s16 local_0, local_1; s32 pad; u8 local_2[1][24]; } MeshB1110;
extern void func_80019924(f32 *, f32 *);
extern void func_8001980C(f32 *, f32 *, f32, f32 *);
typedef struct { s16 local_0, local_1, local_2; s16 pad; } MeshB1328;
typedef struct { s16 local_0; s16 local_1[3]; u8 local_2; u8 pad[3]; } SphereB1328;
extern s16 D_80127EE0;
extern f32 sqrtf(f32);
typedef struct { s16 field_0[3], field_6[3], field_C[3]; u8 field_12[3], field_15; s8 field_16; u8 pad_17; } LocalBox_800B1508;
typedef struct { s16 field_0; u8 pad_2[6]; LocalBox_800B1508 field_8[1]; } LocalModel_800B1508;
extern void func_80019994(f32 *, f32 *);
extern void func_80019480(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF2A0(f32 *);
extern void mlMtxPop(void);
typedef struct { s16 local_0, local_1; s32 pad; } MeshB196C;
typedef struct { s16 local_0, local_1, local_2[3]; u8 local_3[3], local_4; s8 local_5; u8 pad; } CylinderB196C;
extern void func_800198D4(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
typedef struct { s16 local_0, local_1, local_2, pad; } ModelB1D3C;
typedef struct { s16 local_0, local_1[3]; u8 local_2; s8 local_3; s16 pad; } SphereB1D3C;
extern void mlMtxSet(void *);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 mlAbsF(f32);
typedef struct {u8 local_0[6]; u16 local_1; u8 local_2[4]; u8 local_3[4];} local_entry;
typedef struct {u8 local_0[0x16]; u16 local_1; local_entry local_2[1];} local_type;
extern void _dbpalette_entrypoint_0(s32, s32, s32 *);

s32 func_800B0D80(LocalModel_800B0D80 *param_0, s32 param_1, f32 *param_2, f32 *param_3, f32 param_4, s32 param_5, void *param_6, f32 *param_7, f32 *param_8)
{
    LocalPoint *local_0;
    LocalPoint *local_1;
    u8 *local_3;
    u8 *local_4;
    f32 local_2[3];
    local_3 = param_0->field_0 * 24 + param_0->field_8;
    local_0 = (LocalPoint *)(local_3 + param_0->field_2 * 16);
    local_1 = local_0 + param_0->field_4;
    for (; local_0 < local_1; local_0++) if (param_1 == local_0->field_8) break;
    if (local_0 == local_1) return 0;
    func_800EE88C(param_7, local_0->field_2);
    func_800EFA4C(local_2, param_7[0], param_7[1] + local_0->field_0, param_7[2]);
    func_80019CD4();
    func_80019750(param_2, param_3, param_4, param_5);
    mlMtxGet(D_80127EA0);
    func_80019AA0(D_80127EA0, func_800ADE2C(param_6, local_0->field_9));
    func_80019224(param_7, param_7);
    func_80019224(local_2, local_2);
    if (param_8) *param_8 = func_800EEAD4(param_7, local_2);
    return 1;
}

s32 func_800B0ECC(LocalModel_800B0ECC *param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 param_4, f32 *param_5, f32 param_6, s32 param_7)
{
    s32 local_9;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    s32 local_5;
    f32 local_6[3];
    LocalBox_800B0ECC *local_7;
    LocalBox_800B0ECC *local_8;
    local_8 = param_0->field_0 + param_0->field_8;
    for (local_7 = param_0->field_8; local_7 < local_8; local_7++) {
        local_9 = local_7->field_15 - 1;
        if ((1 << local_9) & param_7) continue;
        local_4 = param_6 / param_3;
        func_800EE88C(local_0, local_7->field_C);
        func_800EE88C(local_1, local_7->field_0);
        func_800EE88C(local_2, local_7->field_6);
        local_3[0] = (u32)local_7->field_12[0];
        local_3[1] = (u32)local_7->field_12[1];
        local_3[2] = (u32)local_7->field_12[2];
        func_800EF334(local_3, 2.0f);
        func_80019CD4();
        func_80019A10(local_0, local_3);
        func_8001980C(param_1, param_2, param_3, param_4);
        func_800193C4(local_6, param_5);
        for (local_5 = 0; local_5 < 3; local_5++) {
            if (local_6[local_5] + local_4 <= local_1[local_5]) break;
            if (local_2[local_5] <= local_6[local_5] - local_4) break;
        }
        if (local_5 == 3) return local_7->field_15;
    }
    return 0;
}

s32 func_800B1110(MeshB1110 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 *param_4, f32 *param_5, f32 param_6, u32 param_7) {
    s32 local_9;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2, local_3, local_4;
    s32 local_5;
    f32 local_6[3];
    CylinderB1110 *local_7, *local_8;
    s32 local_10[2];
    local_7 = (CylinderB1110 *)(param_0->local_0 * 24 + (u8 *)param_0 + 8);
    local_8 = local_7 + param_0->local_1;
    for (; local_7 < local_8; local_7++) {
        local_5 = local_7->local_4 - 1;
        if ((1 << local_5) & param_7) continue;
        local_2 = param_6 / param_3;
        func_800EE88C(local_0, local_7->local_2);
        local_1[0] = local_7->local_3[0] * 2;
        local_1[1] = local_7->local_3[1] * 2;
        local_1[2] = local_7->local_3[2] * 2;
        local_3 = local_7->local_0;
        local_4 = local_7->local_1;
        func_80019CD4();
        func_80019924(local_0, local_1);
        func_8001980C(param_1, param_2, param_3, param_4);
        func_800193C4(local_6, param_5);
        if (local_6[2] - local_2 >= local_4 * 0.5f) continue;
        if (local_6[2] + local_2 <= -(local_4 * 0.5f)) continue;
        if ((local_6[0]*local_6[0] + local_6[1]*local_6[1]) >= (local_2 + local_3)*(local_2 + local_3)) continue;
        return local_7->local_4;
    }
    return 0;
}

s32 func_800B1328(MeshB1328 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 *param_4, f32 *param_5, f32 param_6, u32 param_7) {
    s32 local_10;
    u8 *local_0;
    f32 local_1[3];
    s32 local_2;
    f32 local_3[3];
    f32 local_4, local_5, local_6;
    f32 local_7[3];
    SphereB1328 *local_8, *local_9;
    func_80019CD4();
    func_8001980C(param_1, param_2, param_3, param_4);
    func_800193C4(local_1, param_5);
    local_0 = param_0->local_0 * 24 + (u8 *)param_0 + 8;
    local_8 = (SphereB1328 *)(param_0->local_1 * 16 + local_0);
    local_9 = local_8 + param_0->local_2;
    for (; local_8 < local_9; local_8++) {
        local_2 = local_8->local_2 - 1;
        if ((1 << local_2) & param_7) continue;
        local_5 = param_6 / param_3;
        local_3[0] = local_8->local_1[0];
        local_3[1] = local_8->local_1[1];
        local_3[2] = local_8->local_1[2];
        local_4 = local_8->local_0;
        local_7[0] = local_3[0] - local_1[0];
        local_7[1] = local_3[1] - local_1[1];
        local_7[2] = local_3[2] - local_1[2];
        if (sqrtf(local_7[0]*local_7[0] + local_7[1]*local_7[1] + local_7[2]*local_7[2]) >= local_5 + local_4) continue;
        D_80127EE0 = (SphereB1328 *)((u8 *)local_8 - param_0->local_1 * 16) - (SphereB1328 *)local_0;
        return local_8->local_2;
    }
    return 0;
}

s32 func_800B1508(LocalModel_800B1508 *param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 param_4, void *param_5, f32 *param_6, f32 param_7, u32 param_8)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    LocalBox_800B1508 *local_4;
    LocalBox_800B1508 *local_5;
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    f32 local_10[3];
    f32 local_11[3];
    f32 local_12[3];
    f32 local_13[3];
    f32 local_14[3];
    s32 local_15;
    local_5 = param_0->field_0 + param_0->field_8;
    for (local_4 = param_0->field_8; local_4 < local_5; local_4++) {
        local_15 = local_4->field_15 - 1;
        if ((1 << local_15) & param_8) continue;
        func_800EE88C(local_0, local_4->field_C);
        func_800EE88C(local_1, local_4->field_0);
        func_800EE88C(local_2, local_4->field_6);
        local_3[0] = (u32)local_4->field_12[0];
        local_3[1] = (u32)local_4->field_12[1];
        local_3[2] = (u32)local_4->field_12[2];
        func_800EF334(local_3, 2.0f);
        func_80019AA0(D_80127EA0, func_800ADE2C(param_5, local_4->field_16));
        func_80019994(local_0, local_3);
        func_80019480(local_7, local_1[0], local_1[1], local_1[2]);
        func_80019480(local_9, local_1[0], local_1[1], local_2[2]);
        func_800EFB24(local_6, local_7, local_9);
        func_800EF2A0(local_6);
        func_800EFB24(local_8, param_6, local_7);
        if (param_7 <= local_8[0] * local_6[0] + local_8[1] * local_6[1] + local_8[2] * local_6[2]) goto next_box;
        func_800EFB24(local_10, param_6, local_9);
        if (param_7 <= -(local_10[0] * local_6[0] + local_10[1] * local_6[1] + local_10[2] * local_6[2])) goto next_box;
        func_80019480(local_11, local_2[0], local_1[1], local_1[2]);
        func_800EFB24(local_6, local_7, local_11);
        func_800EF2A0(local_6);
        if (param_7 <= local_8[0] * local_6[0] + local_8[1] * local_6[1] + local_8[2] * local_6[2]) goto next_box;
        local_12[0] = param_6[0] - local_11[0];
        local_12[1] = param_6[1] - local_11[1];
        local_12[2] = param_6[2] - local_11[2];
        if (param_7 <= -(local_12[0] * local_6[0] + local_12[1] * local_6[1] + local_12[2] * local_6[2])) goto next_box;
        func_80019480(local_13, local_1[0], local_2[1], local_1[2]);
        local_6[0] = local_7[0] - local_13[0];
        local_6[1] = local_7[1] - local_13[1];
        local_6[2] = local_7[2] - local_13[2];
        func_800EF2A0(local_6);
        if (param_7 <= local_8[0] * local_6[0] + local_8[1] * local_6[1] + local_8[2] * local_6[2]) goto next_box;
        local_14[0] = param_6[0] - local_13[0];
        local_14[1] = param_6[1] - local_13[1];
        local_14[2] = param_6[2] - local_13[2];
        if (param_7 <= -(local_14[0] * local_6[0] + local_14[1] * local_6[1] + local_14[2] * local_6[2])) goto next_box;
        return local_4->field_15;
next_box:
        mlMtxPop();
    }
    return 0;
}

s32 func_800B196C(MeshB196C *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 *param_4, void *param_5, f32 *param_6, f32 param_7, u32 param_8)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    f32 local_4;
    f32 local_5[3];
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    CylinderB196C *local_10, *local_11;
    local_10 = (CylinderB196C *)(param_0->local_0 * 24 + (u8 *)param_0 + 8);
    local_11 = local_10 + param_0->local_1;
    for (; local_10 < local_11; local_10++) {
        local_3 = local_10->local_4 - 1;
        if ((1 << local_3) & param_8) continue;
        local_1[0] = local_10->local_2[0];
        local_1[1] = local_10->local_2[1];
        local_1[2] = local_10->local_2[2];
        local_2[0] = local_10->local_3[0] * 2;
        local_2[1] = local_10->local_3[1] * 2;
        local_2[2] = local_10->local_3[2] * 2;
        func_80019AA0(((f32 *) D_80127EA0), func_800ADE2C(param_5, local_10->local_5));
        func_800198D4(local_1, local_2);
        func_80019480(local_5, 0.0f, 0.0f, -local_10->local_1 * 0.5f);
        func_80019480(local_6, 0.0f, 0.0f, local_10->local_1 * 0.5f);
        func_80019480(local_9, local_10->local_0, 0.0f, -local_10->local_1 * 0.5f);
        func_800EF3DC(local_9, local_5);
        func_800EFB24(local_7, local_5, local_6);
        func_800EF2A0(local_7);
        func_800EFB24(local_8, param_6, local_5);
        local_4 = local_7[0] * local_8[0] + local_7[1] * local_8[1] + local_7[2] * local_8[2];
        if (param_7 < local_4) goto next;
        func_800EFB24(local_8, param_6, local_6);
        if (param_7 < -(local_7[0] * local_8[0] + local_7[1] * local_8[1] + local_7[2] * local_8[2])) goto next;
        local_8[0] = param_6[0] - (local_5[0] + local_7[0] * local_4);
        local_8[1] = param_6[1] - (local_5[1] + local_7[1] * local_4);
        local_8[2] = param_6[2] - (local_5[2] + local_7[2] * local_4);
        local_4 = sqrtf(local_8[0] * local_8[0] + local_8[1] * local_8[1] + local_8[2] * local_8[2]);
        if (sqrtf(local_9[0] * local_9[0] + local_9[1] * local_9[1] + local_9[2] * local_9[2]) < local_4 - param_7) goto next;
        return local_10->local_4;
    next:
        mlMtxPop();
    }
    return 0;
}

s32 func_800B1D3C(ModelB1D3C *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 *param_4, void *param_5, f32 *param_6, f32 param_7, u32 param_8) {
    s32 local_11;
    u8 *local_0;
    f32 local_1[3], local_2[3], local_3[3];
    f32 local_8, local_9, local_10;
    f32 local_5[3];
    SphereB1D3C *local_6, *local_7;
    func_80019CD4();
    func_8001980C(param_1, param_2, param_3, param_4);
    func_800193C4(local_1, param_6);
    local_0 = param_0->local_0 * 24 + (u8 *)param_0 + 8;
    local_6 = (SphereB1D3C *)(local_0 + param_0->local_1 * 16);
    local_7 = local_6 + param_0->local_2;
    param_7 /= param_3;
    for (; local_6 < local_7; local_6++) {
        local_11 = local_6->local_2 - 1;
        if (param_8 & (1 << local_11)) continue;
        local_8 = param_7 * param_7;
        func_800EE88C(local_2, local_6->local_1);
        func_800EFA4C(local_3, local_2[0] + local_6->local_0, local_2[1], local_2[2]);
        mlMtxSet(func_800ADE2C(param_5, local_6->local_3));
        func_80019224(local_2, local_2);
        func_80019224(local_3, local_3);
        local_5[0] = local_3[0] - local_2[0];
        local_5[1] = local_3[1] - local_2[1];
        local_5[2] = local_3[2] - local_2[2];
        local_9 = func_800EEFD4(local_5);
        local_10 = sqrtf(local_9);
        if (func_800EEB40(local_2, local_1) <= local_8 + local_9 + (local_10 + local_10) * param_7) {
            D_80127EE0 = ((u8 *)local_6 - param_0->local_1 * 16 - local_0) / 12;
            return local_6->local_2;
        }
    }
    return 0;
}

s32 func_800B1F8C(void *param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 param_4, void *param_5, f32 *param_6, f32 param_7, f32 *param_8, s32 param_9)
{
    s32 local_0;
    f32 **local_1 = &param_1;
    f32 **local_2 = &param_2;
    if (param_5) {
        func_80019CD4();
        func_80019750(*local_1, *local_2, param_3, param_4);
        mlMtxGet(D_80127EA0);
        local_0 = func_800B1D3C(param_0, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_9);
        if (!local_0) local_0 = func_800B1508(param_0, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_9);
        if (!local_0) local_0 = func_800B196C(param_0, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_9);
    } else {
        local_0 = func_800B1328(param_0, param_1, param_2, param_3, param_4, param_6, param_7, param_9);
        if (!local_0) local_0 = func_800B0ECC(param_0, param_1, param_2, param_3, param_4, param_6, param_7, param_9);
        if (!local_0) local_0 = func_800B1110(param_0, param_1, param_2, param_3, param_4, param_6, param_7, param_9);
    }
    if (local_0) func_800EFA4C(param_8, 0.0f, 1.0f, 0.0f);
    return local_0;
}

func_800B2190(param_0){
    return param_0 + 0x18;
}

func_800B2198(s16 *param_0, s32 *param_1, s32 *param_2){
    param_1[0] = param_0[0];
    param_1[1] = param_0[1];
    param_1[2] = param_0[2];
    param_2[0] = param_0[3];
    param_2[1] = param_0[4];
    param_2[2] = param_0[5];
}

func_800B21CC(s16 *param_0, f32 param_1[3], f32 param_2[3]){
    param_1[0] = param_0[0];
    param_1[1] = param_0[1];
    param_1[2] = param_0[2];
    param_2[0] = param_0[3];
    param_2[1] = param_0[4];
    param_2[2] = param_0[5];
}

s32 func_800B2248(u8 *param_0) {
  s32 local_0;
  s32 local_1;
  local_0 = (s32) mlAbsF((f32) (*((s16 *) param_0)));
  local_1 = (s32) mlAbsF((f32) (*((s16 *) (param_0 + 4))));
  if (local_0 < local_1) {
    local_0 = local_1;
  }
  local_1 = (s32) mlAbsF((f32) (*((s16 *) (param_0 + 6))));
  if (local_0 < local_1) {
    local_0 = local_1;
  }
  local_1 = (s32) mlAbsF((f32) (*((s16 *) (param_0 + 0xA))));
  if (local_0 < local_1) {
    local_0 = local_1;
  }
  return local_0;
}

void func_800B2324(u8 *param_0, s32 *param_1, s32 *param_2)
{
  u16 new_var;
  s32 local_0;
  s32 local_1;
  local_0 = ((s32) param_0) + 0x18;
 do { } while (0);
  *param_1 = local_0;
  local_1 = ((u32) (*((u16 *) (param_0 + 0x16)))) >> 1;
  new_var = *((u16 *) (param_0 + 0x16));
  *param_2 = local_0 + (((((u32) new_var) >> 1) * 8) * 2);
}

int func_800B2344(u16 *param_0)
{
  u16 **new_var;
  ;
  ;
  return ((unsigned int) (*(&param_0))[11]) >> 1;
}

volatile unsigned short func_800B2354(u16 *param_0)
{
  f32 local_0;
  int new_var2;
  f32 new_var3;
  u16 *new_var;
  new_var = param_0;
 if (1 & 0xFFFFu) { } if (1) { } if (1) { } new_var2 = 0x4F800000; if (1) { }
  new_var3 = new_var[10];
  local_0 = new_var3;
  if (((u32) local_0) < 0)
  {
    local_0 += new_var2;
    local_0 = new_var[5];
    return new_var3 = local_0;
  }
}

void func_800B237C(u8 *param_0, u8 *param_1, f32 *param_2)
{
  s16 *new_var3;
  s16 *new_var2;
  s8 *new_var;
  f32 var_f6;
  u16 temp_t9;
  *((f32 *) (((s8 *) param_1) + 0)) = (f32) (*((s16 *) (((s8 *) param_0) + 0xC)));
  new_var3 = (s16 *) (((s8 *) param_0) + 0xE);
  *((f32 *) (new_var = ((s8 *) param_1) + 4)) = (f32) (*new_var3);
  new_var2 = &(*((s16 *) (((s8 *) param_0) + 0x10)));
  *((f32 *) (((s8 *) param_1) + 8)) = (f32) (*new_var2);
  temp_t9 = (*((u16 *) (((s8 *) param_0) + 0x12))) ^ 0;
 do { var_f6 = (*param_2 = (f32) temp_t9); if (((s32) temp_t9) < 0) { var_f6 += 4294967296.0f; } } while (0);
}

void func_800B23E0(void* arg0) 
{
    heap_free(arg0);
}
void *func_800B2400(u16 *param_0, u32 param_1) {
    void *local_0;
    u32 local_1;

    local_1 = (((u32)param_0[11] >> 1) << 4) + 0x18;
    local_0 = heap_alloc_sided(local_1, param_1 != 0 ? 1 : 2);
    aligned4_memcpy(local_0, param_0, local_1);
    return local_0;
}

void func_800B2464(u8 *param_0, s32 *param_1, s32 param_2) {
    s32 *var_a0;
    s32 var_a2;
    s32 var_v0;
    u8 *temp_s1;
    u8 *temp_t1;
    u8 *var_a3;
    u8 *var_a1;
    u8 *var_t0;
    u8 *var_v1;

    var_a2 = param_2;
    if (((*(s32 *)param_1) != 0xFF) ||
        ((*(s32 *)((s8 *)param_1 + 4)) != 0xFF) ||
        ((*(s32 *)((s8 *)param_1 + 8)) != 0xFF)) {
        temp_s1 = param_0 + 0x18;
        var_a3 = temp_s1;
        temp_t1 = ((((u32)(*(u16 *)((s8 *)param_0 + 0x16))) >> 1) * 0x10) + param_0 + 0x18;
        var_t0 = (u8 *)(param_2 + 0x18);
        if ((u32)temp_s1 < (u32)temp_t1) {
            var_a2 = 3;
            do {
                var_v0 = 0;
                var_v1 = var_a3;
                var_a0 = param_1;
                var_a1 = var_t0;
                do {
                    var_v0 += 1;
                    var_v1 += 1;
                    (*(s8 *)((u8 *)var_v1 + 0xB)) = (s8)((*(u8 *)((u8 *)var_a1 + 0xC) * *var_a0) >> 8);
                    var_a0 += 1;
                    var_a1 += 1;
                } while (var_v0 != 3);
                var_a3 += 0x10;
                var_t0 += 0x10;
            } while ((u32)var_a3 < (u32)temp_t1);
        }
        osWritebackDCache(temp_s1, ((s32)(temp_t1 - temp_s1) >> 4) << 4);
    }
}

void func_800B2540(u8 *param_0, s32 *param_1)
{
  u8 *var_a0;
  s32 temp_t9;
  s32 var_v0;
  u8 *temp_a3;
  u8 *temp_s1;
  u8 *var_a2;
  u8 *var_v1;
  temp_s1 = param_0 + 0x18;
  temp_a3 = (((((u32) (*((u16 *) (((s8 *) param_0) + 0x16)))) >> 1) * 0x10) + param_0) + 0x18;
  var_a2 = temp_s1;
  if (((u32) temp_s1) < ((u32) temp_a3))
  {
    do
    {
      var_v0 = 0;
      var_v1 = var_a2;
      var_a0 = param_1;
      loop_3:
      ;

      var_v0 += 1;
      var_v1 += 1;
      *((s8 *) (((s8 *) var_v1) + 0xB)) = (s8) (*((s32 *) var_a0));
      var_a0 += 4;
      if (var_v0 != 3)
      {
        goto loop_3;
      }
      var_a2 += 0x10;
    }
    while (((u32) var_a2) < ((u32) temp_a3));
  }
  osWritebackDCache(temp_s1, (((s32) (temp_a3 - temp_s1)) >> 4) * 0x10);
}

void func_800B25D8(local_type *param_0, local_type *param_1, s32 param_2) {
    u8 local_6[8];
    s32 local_0[3];
    local_entry *local_1;
    local_entry *local_2;
    local_entry *local_3;
    local_entry *local_4;
    s32 local_5;
    local_1 = param_0->local_2;
    local_2 = ((u32)param_0->local_1 >> 1) + param_0->local_2;
    local_3 = local_1;
    local_4 = param_1->local_2;
    for (; local_3 < local_2; local_3++, local_4++) {
        _dbpalette_entrypoint_0(param_2, local_4->local_1 & 0x1FF, local_0);
        for (local_5 = 0; local_5 < 3; local_5++) {
            local_3->local_3[local_5] = (local_4->local_3[local_5] * local_0[local_5]) >> 8;
        }
    }
    osWritebackDCache(local_1, (local_2 - local_1) * sizeof(local_entry));
}

int func_800B26C8()
{
  defrag();
}
