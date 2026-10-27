#include "common.h"

extern void *D_808007D0_chbanjocurrent;
extern void func_800EE88C(f32 *, void *);
extern int D_80800818_chbanjocurrent;
extern s32 func_800F54E4(void);
extern f32 func_800F5E7C(u32);
extern f32 func_800F5F7C(u32);
extern f32 func_80013A7C(f32);
extern f32 func_800D8FF8(void);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800137D4(f32);
extern f32 func_80013788(void);
extern void *func_800F5E50(s32);
extern void func_80102EC0(), func_80107C2C(), func_8010A730();

int func_80800000_chbanjocurrent()
{
    func_800F4C24(func_800F54E4());
}

int chbanjocurrent_entrypoint_0()
{
    return (int)&D_808007D0_chbanjocurrent;
}

void func_80800034_chbanjocurrent(void *param_0)
{
  s32 temp;
  temp = *((s32 *) (((char *) param_0) + 4));
  *((s32 *) (((char *) param_0) + 4)) = *((s32 *) (((char *) param_0) + 8));
  *((s32 *) (((char *) param_0) + 8)) = *((s32 *) (((char *) param_0) + 0));
  *((s32 *) (((char *) param_0) + 0)) = temp;
}

void func_80800050_chbanjocurrent(u16 *param_0, f32 (*param_1)[3], f32 (*param_2)[2], s32 *param_3)
{
    s32 local_0;
    u8 *local_1;
    u8 *local_2;
    s32 local_3;
    local_0 = func_800BEB28(1);
    if (!local_0) local_0 = func_800BEB28(0);
    local_1 = (u8 *)func_800B2840(local_0) + 0x18;
    for (local_3 = 0; local_3 != 3; local_3++) {
        local_2 = local_1 + param_0[local_3] * 0x10;
        func_800EE88C(param_1[local_3], local_2);
        param_2[local_3][0] = *(s16 *)(local_2 + 8);
        param_2[local_3][1] = *(s16 *)(local_2 + 10);
        param_3[local_3] = local_3;
    }
    if (param_2[param_3[2]][0] <= param_2[param_3[1]][0])
        func_80800034_chbanjocurrent(param_3);
    if (param_2[param_3[2]][0] <= param_2[param_3[1]][0])
        func_80800034_chbanjocurrent(param_3);
}

void func_808001D0_chbanjocurrent(Actor *param_0)
{
    f32 local_10;
    f32 local_12;
    u32 local_0;
    f32 local_1;
    f32 local_13;
    s32 local_14;
    f32 local_2[3][3];
    f32 local_3[3][2];
    s32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    u16 *local_15;
    f32 local_7[3];
    s32 local_16;
    s32 argp_3;
    f32 local_8[3];
    f32 local_9[3];
    if (!func_80800000_chbanjocurrent(param_0)) return;
    local_0 = func_800F54E4();
    local_14 = func_8008FF94();
    if (!local_14) return;
    if (local_14 == 2) {
        local_10 = func_800F5E7C(local_0) - func_800F5F7C(local_0);
        if (local_10 >= 1000.0f) return;
        if (local_10 < 0) local_10 = 0;
        local_1 = 1.0f - local_10 * 0.001f;
    } else {
        local_1 = 1.0f;
    }
    local_15 = func_800F5E50(local_0);
    local_14 = (*(u32 *)((u8 *)local_15 + 8) & 0x78000000) >> 27;
    if (!local_14) return;
    if (param_0->rotation[1] != 0.0f && param_0->rotation[1] != (local_13 = local_14)) return;
    func_80800050_chbanjocurrent(local_15, local_2, local_3, local_4);
    func_800EFB24(local_5, local_2[local_4[2]], local_2[local_4[1]]);
    local_12 = local_3[local_4[2]][0] - local_3[local_4[1]][0];
    if (local_12 != 0.0f) {
        local_13 = (local_3[local_4[0]][0] - local_3[local_4[1]][0]) / local_12;
        for (local_16 = 0; local_16 < 3; local_16++) {
            local_6[local_16] = local_2[local_4[1]][local_16] + (local_5[local_16] * local_13);
        }
        func_800EFB24(local_7, local_6, local_2[local_4[0]]);
        func_800EF2A0(local_7);
    } else {
        func_800EFD24(local_7);
    }
    argp_3 = local_2[1];
    func_800EF3DC(argp_3, local_2[0]);
    func_800EF3DC(local_2[2], local_2[0]);
    func_800EE97C(local_8, local_2[1], local_2[2]);
    func_800EF2A0(local_8);
    func_800EF334(local_7, func_80013A7C(local_8[1]) * 0.05f + 1.0f);
    func_80090794(local_9);
    func_800EF174(local_9, local_7, func_800D8FF8() * (u32)param_0->unk74_7 * local_1);
    if (param_0->rotation[1] != 0.0f) {
        func_800907C0(local_9);
    }
}

int chbanjocurrent_entrypoint_1()
{
    return (int)&D_80800818_chbanjocurrent;
}

f32 func_80800514_chbanjocurrent(f32 *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_0 = func_800EEF94(param_0);
    local_1 = func_800137D4(func_800136D0((local_0 - param_2) * 0.015707964f)) * 20.0f;
    local_2 = func_80013788() * 20.0f * 0.015707964f;
    if (local_0 != 0.0f) {
        local_3 = local_2 / local_0;
        param_1[0] = param_0[0] * local_3;
        param_1[1] = param_0[2] * local_3;
    } else {
        param_1[0] = param_0[0] * local_2;
        param_1[1] = param_0[2] * local_2;
    }
    return local_1;
}

void func_808005F4_chbanjocurrent(Actor *param_0)
{
    f64 local_9;
    s32 local_0;
    f32 local_1;
    f32 local_4;
    s32 local_5;
    f32 local_2[3];
    f32 local_3[2];
    if (!func_80800000_chbanjocurrent()) return;
    local_0 = func_800F54E4();
    param_0->unk58 += (func_800D8FF8() * (f32)param_0->unk74_7) * 4.0f;
    local_5 = func_8008FF94();
    if (!local_5) return;
    if (local_5 == 2) {
        local_4 = func_800F5E7C(local_0) - func_800F5F7C(local_0);
        if (local_4 >= 2000.0f) return;
        if (local_4 < 0.0f) local_4 = 0.0f;
        local_1 = 1.0f - local_4 * 0.0005f;
    } else local_1 = 1.0f;
    local_5 = (*(u32 *)((u8 *)func_800F5E50(local_0) + 8) & 0x78000000) >> 27;
    if (local_5 && param_0->rotation[1] == (local_4 = local_5)) {
        func_80090794(local_2);
        func_80800514_chbanjocurrent(local_2, local_3, param_0->unk58);
        local_2[0] += (local_3[0] * 8.0f) * local_1;
        local_2[2] += (local_3[1] * 8.0f) * local_1;
        func_800907C0(local_2);
    }
}
