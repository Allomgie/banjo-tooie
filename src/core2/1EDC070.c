#include "common.h"

extern f32 D_80135AA0;
void func_80102424(s32, s32);
typedef struct { u8 pad0[0x48]; f32 unk48; u8 pad4C[8]; f32 unk54; } S_1028C4;
extern void func_800F2094(f32, f32);
extern f32 func_800136E4(f32);
f32 func_800DC0C0(void);
typedef struct { u8 pad[0x74]; u32 pad2:27; u32 local_0:1; u32 pad3:4; } Actor102A04;
extern f32 func_80013728(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800F20BC(f32, f32, f32);
extern s32 func_800DC298(f32);
void func_80102924(void *param_0, f32 param_1);
void func_80102B2C(void *param_0, f32 param_1);
s32 func_80102CF4(s32, f32);
f32 func_80102D78();

int func_80102780(f32 param_0[3], f32 param_1[3])
{
  param_1[0] = param_0[17];
  param_1[1] = param_0[18];
  param_1[2] = param_0[19];
}

void func_8010279C(f32 *param_0, f32 *param_1)
{
  param_0[17] = func_800136E4(param_1[0]);
  param_0[18] = func_800136E4(param_1[1]);
  param_0[19] = func_800136E4(param_1[2]);
}

f32 *func_801027F4(u8 *param_0) {
    if (((u32) *(u32 *)(param_0 + 0x94) >> 0x1F) != 0) {
        func_80102780(param_0, &D_80135AA0);
        D_80135AA0 = -D_80135AA0;
        return &D_80135AA0;
    }
    return (f32 *)(param_0 + 0x44);
}

s32 func_80102844(s32 param_0, f32 param_1, s32 param_2, s32 param_3)
{
    func_80102924(param_0, func_80102D78(param_0, param_3));
    func_80102B2C(param_0, param_1);
    if (func_80102CF4(param_0, 10.0f) != 0)
    {
        if (param_2 != -1)
        {
            func_80102424(param_0, param_2);
        }
        return 1;
    }
    return 0;
}

void func_801028C4(S_1028C4 *param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    param_0->unk54 = func_80102D78(param_0, param_1);
    param_0->unk48 = func_800F1FF0(param_0->unk48, param_0->unk54, param_2, param_3, param_4);
    func_800F2094(param_0->unk48, param_0->unk54);
}

void func_80102924(void *param_0, f32 param_1) {
    *(f32 *)((u8 *)param_0 + 0x54) = func_800136E4(param_1);
}

void func_80102950(void *param_0, f32 param_1) {
    *(f32 *)((u8 *)param_0 + 0x50) = func_800136E4(param_1);
}

void func_8010297C(s32 param_0, f32 param_1, f32 param_2, f32 param_3) {
    f32 var_f0;
    f32 temp_f16;

    temp_f16 = 2.0f * ((func_800DC0C0() - 0.5f) * (param_3 - param_2));
    func_80102924(param_0, (temp_f16 >= 0.0f ? param_2 : -param_2) + (param_1 + temp_f16));
}

f32 func_80102A04(Actor102A04 *param_0, f32 param_1, f32 param_2, s32 param_3) {
    f32 local_0;
    if (param_2 == param_1) return param_1;
    local_0 = func_80013728(param_2 - param_1);
    if (param_0->local_0 && (local_0 >= 50.0f || local_0 < -50.0f)) return param_2;
    local_0 = (local_0 > 0.0f) ? ((local_0 < param_3) ? local_0 : param_3) : ((local_0 > -param_3) ? local_0 : -param_3);
    local_0 += param_1;
    return func_800136E4(local_0);
}

void func_80102B2C(void *param_0, f32 param_1) {
    (*(f32 *)((char *)param_0 + 0x48)) = func_80102A04(param_0, *(f32 *)((char *)param_0 + 0x48), *(f32 *)((char *)param_0 + 0x54), (s32)param_1);
}

void func_80102B6C(u8 *param_0, f32 param_1) {
    (*(f32 *)((s8 *)param_0 + 0x44)) = func_80102A04(param_0, (*(f32 *)((s8 *)param_0 + 0x44)), (*(f32 *)((s8 *)param_0 + 0x50)), (s32)param_1);
}

void func_80102BAC(Actor *param_0, f32 param_1, f32 param_2, f32 param_3) {
    *(f32 *)((u8 *)param_0 + 0x48) =
        func_800F1FF0(*(f32 *)((u8 *)param_0 + 0x48), *(f32 *)((u8 *)param_0 + 0x54),
                      param_1, param_2, param_3);
}

void func_80102BF8(u8 *param_0, f32 param_1, f32 param_2, f32 param_3) {
    f32 temp_f0;

    temp_f0 = func_800D8FF8();
    (*(f32 *)((s8 *)(param_0) + (0x48))) = func_800F1FF0((*(f32 *)((s8 *)(param_0) + (0x48))), (*(f32 *)((s8 *)(param_0) + (0x54))), param_1, temp_f0 * param_2, temp_f0 * param_3);
}

void func_80102C58(Actor *param_0, f32 param_1, f32 param_2, f32 param_3) {
    *(f32 *)((u8 *)param_0 + 0x44) =
        func_800F1FF0(*(f32 *)((u8 *)param_0 + 0x44), *(f32 *)((u8 *)param_0 + 0x50),
                      param_1, param_2, param_3);
}

void func_80102CA4(long param_0)
{
  func_800F20BC(*(float *)((char *)param_0 + 0x44), *(float *)((char *)param_0 + 0x50), 3.0f);
}

void func_80102CCC(long param_0) {
    func_800F20BC(*(float *)(param_0 + 0x48), *(float *)(param_0 + 0x54), 3.0f);
}

s32 func_80102CF4(s32 param_0, f32 param_1)
{
  func_800F20BC(*((f32 *) (param_0 + 0x48)), *((f32 *) (param_0 + 0x54)), param_1);
}

s32 func_80102D20(void *param_0, f32 param_1, f32 param_2) {
    return func_800F20BC(*(f32 *)((u8 *)param_0 + 0x48), param_2, param_1);
}

s32 func_80102D4C(s32 param_0, f32 param_1)
{
  func_800F20BC(*((f32 *) (param_0 + 0x44)), *((f32 *) (param_0 + 0x50)), param_1);
}

f32 func_80102D78(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 + 4;
  func_800F1DF4(local_0);
}

s32 func_80102D98(u8 *param_0, s32 param_1, s32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    if (func_8001210C((((u32)(*(u16 *)((u8 *)*(u8 **)param_0 + 0x12))) >> 1) & param_1) == param_2) {
        if (func_800DC298(param_3) != 0) {
            func_8010297C(param_0, *(f32 *)((u8 *)param_0 + 0x48), param_4, param_5);
            return 1;
        }
    }
    return 0;
}

s32 func_80102E08(u8 *param_0) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    s32 sp30;
    f32 sp24[3];

    sp30 = 0;
    func_800EE7F8(sp4C, param_0 + 4);
    func_800EE7F8(sp40, param_0 + 4);
    sp4C[1] += 50.0f;
    sp40[1] -= 50.0f;
    if (func_800BEF00(sp4C, sp40, sp34, *(s32 **)((char *)param_0 + 0x14)) != 0) {
        *(f32 *)((char *)param_0 + 8) = sp40[1];
        if (func_800F1B78(sp24, sp34, *(s32 **)((char *)param_0 + 0x48), 0x3F800000) != 0) {
            *(f32 *)((char *)param_0 + 0x44) = sp24[0];
            *(f32 *)((char *)param_0 + 0x4C) = sp24[2];
            sp30 = 1;
        }
    }
    return sp30;
}
