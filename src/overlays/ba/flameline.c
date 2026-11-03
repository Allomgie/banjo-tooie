#include "common.h"

extern s32 D_80800784_baflameline[];
extern s32 func_800EE7F8(s32);
extern void func_800EF2A0(int);
extern s32 D_808006F0_baflameline[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA77C();
typedef struct { u8 pad_0[0xC]; f32 local_0[3]; f32 local_1; s32 local_2; } FlameLineData31;
typedef struct { u8 pad_0[0x84]; FlameLineData31 *local_0; } FlameLineOwner31;
extern s32 D_80800738_baflameline[];
extern void func_800BA930();
extern s32 D_80800798_baflameline[];
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void func_800C8E54(s32, f32, f32);
extern void func_8008EEC4(void *, f32 *, f32, s32);

s32 baflameline_entrypoint_0() 
{
    return 0x28;
}

void baflameline_entrypoint_1(u8 *param_0)
{
    f32 local_5;
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    u8 *local_4;
    local_2 = func_800B53A4(0xE);
    local_4 = *(u8 **)(param_0 + 0x84);
    func_800EFA20(local_0, (f32 *)(local_4 + 0xC), *(f32 *)(local_4 + 0x18));
    func_800EF04C(local_0, *(void **)(param_0 + 0x84));
    for (local_3 = 0; local_3 < 7; local_3++) {
        func_800EFE50(local_1, *(void **)(param_0 + 0x84), local_0, func_800F10B4((local_3 + 0.5f) / 7.0f, 0.0f, 1.0f, 0.2f, 1.0f));
        func_800BA77C(local_2, 0, 0, (s16)(s32)func_800DC178(0.0f, 359.0f));
        func_800BABB8(local_2, local_1, NULL, 1.0, &D_808006F0_baflameline);
    }
}

void func_80800184_baflameline(FlameLineOwner31 *param_0, f32 *param_1)
{
    f32 local_0[3];

    func_800EFA20(local_0, param_0->local_0->local_0, param_0->local_0->local_1 / 0.3f);
    local_0[1] -= (param_0->local_0->local_1 / 0.3f) * 0.1f;
    func_800BA77C(param_0->local_0->local_2, 0, 0, (s16)func_800DC178(0.0f, 359.0f));
    func_800BA930(param_0->local_0->local_2, (s16)local_0[0], (s16)local_0[1], (s16)local_0[2],
        (s16)local_0[0], (s16)local_0[1], (s16)local_0[2]);
    func_800BABB8(param_0->local_0->local_2, param_1, 0, 1.0f, &D_80800738_baflameline);
}

void baflameline_entrypoint_2(u8 *param_0) {
    s32 local_0;
    u8 *local_1;

    func_800C2FDC((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x20))), param_0);
    local_1 = (*(u8 **)((s8 *)(param_0) + (0x84)));
    local_0 = (*(s32 *)((s8 *)(local_1) + (0x24)));
    if (local_0 != 0) {
        func_800C8B84(local_0, param_0);
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x24))) = 0;
        local_1 = (*(u8 **)((s8 *)(param_0) + (0x84)));
    }
    func_800B5450((*(s32 *)((s8 *)(local_1) + (0x1C))), param_0);
}

void baflameline_entrypoint_3(u8 *param_0) {
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0x84))));
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0x84))) + 0xC);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x18))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x1C))) = func_800B53A4(0x28);
    func_800B5534((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x1C))));
    if (func_800BF8E4() > 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x24))) = func_800C8A98();
        func_800C8F64((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x24))), 0xB);
        func_800C8FE0((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x24))), 0);
    } else {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x24))) = 0;
    }
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x84)))) + (0x20))) = func_800C4350(0, 0, &D_80800784_baflameline);
}

s32 baflameline_entrypoint_4(s32 param_0) {
    return func_800EE7F8(*(s32 *)(param_0 + 0x84));
}

int baflameline_entrypoint_5(Actor *param_0)
{
    func_800EE7F8(*(int *)((char *)param_0 + 0x84) + 0xC);
    func_800EF2A0(*(int *)((char *)param_0 + 0x84) + 0xC);
}

void baflameline_entrypoint_6(void *param_0, f32 param_1)
{
  s32 *t6;
  t6 = *((s32 **) (((char *) param_0) + 0x84));
  *((f32 *) ((*((s32 **) (((char *) param_0) + 0x84))) + 0x6)) = param_1;
}

void baflameline_entrypoint_7(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_3;
    s32 local_4;
    u8 *local_6;

    local_6 = *(u8 **)(param_0 + 0x84);
    if (*(f32 *)(local_6 + 0x18) == 0.0f) {
        if (*(s32 *)(local_6 + 0x24)) {
            func_800C8FE0(*(s32 *)(local_6 + 0x24), 0);
        }
    } else {
        func_800EFA20(local_0, (f32 *)(local_6 + 0xC), *(f32 *)(local_6 + 0x18));
        func_800EF04C(local_0, *(u8 **)(param_0 + 0x84));
        func_800C3058((*(u8 **)(param_0 + 0x84))[0x20], (s32)func_800F10B4(*(f32 *)(*(u8 **)(param_0 + 0x84) + 0x18), 0.0f, 300.0f, 5000.0f, 32000.0f));
        func_800C35E8((*(u8 **)(param_0 + 0x84))[0x20], local_0);
        func_800C3BDC((*(u8 **)(param_0 + 0x84))[0x20]);
        local_6 = *(u8 **)(param_0 + 0x84);
        if (*(s32 *)(local_6 + 0x24)) {
            local_3 = *(f32 *)(local_6 + 0x18) * 0.5f;
            func_800EFE50(local_1, local_6, local_0, 0.5);
            func_800C8FE0(*(s32 *)(*(u8 **)(param_0 + 0x84) + 0x24), 1);
            func_800C8CB8(*(s32 *)(*(u8 **)(param_0 + 0x84) + 0x24), local_1);
            local_6 = *(u8 **)(param_0 + 0x84);
            func_800C8E54(*(s32 *)(local_6 + 0x24), local_3, *(f32 *)(local_6 + 0x18));
            func_800C8E84(*(s32 *)(*(u8 **)(param_0 + 0x84) + 0x24), (u8 *)&D_80800798_baflameline + func_8001210C(1) * 12);
        }
        for (local_4 = 0; local_4 < 2; local_4++) {
            func_800EFE50(local_1, *(u8 **)(param_0 + 0x84), local_0, func_800DC178(0.0f, 0.1f));
            func_80800184_baflameline(param_0, local_1);
            func_800EFE50(local_1, *(u8 **)(param_0 + 0x84), local_0, func_800DC178(0.0f, 0.1f));
            func_80800184_baflameline(param_0, local_1);
        }
        for (local_4 = 0; local_4 < 3; local_4++) {
            func_800EFE50(local_1, *(u8 **)(param_0 + 0x84), local_0, (local_4 + 0.5f) / 3.0f);
            func_8008EEC4(param_0, local_1, 45.0f, 0x26D);
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ba/flameline.data.s) is defined here in C.
 * Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808006F0_baflameline -> s32[], D_80800738_baflameline -> s32[], D_80800784_baflameline -> s32[], D_80800798_baflameline -> s32[] */
s32 D_808006F0_baflameline[18] = { 0x1D09DC, 0x2CFFEC, 0x1EFFEC, 0x140050, 0x14000E, 0x50005, 0x150002, 0x660020, 0x28412832, 0x22004C, 0x4C0133, 0x1660016, 0x10000018, 0x3, 0x0, 0x2B0233, 0x3E6011A, 0x0 };
s32 D_80800738_baflameline[19] = { 0x1D09CE, 0x150002, 0xAE0016, 0x1000000E, 0x50005, 0x260000, 0xFF9C, 0x0, 0x640032, 0x20018, 0x0, 0x17551755, 0x220040, 0x400099, 0x99002B, 0x4C004C, 0x1B015E, 0x15E011A, 0x0 };
s32 D_80800784_baflameline[5] = { 0x2060013, 0x483001B, 0x1655F0, 0xA0100, 0x0 };
s32 D_80800798_baflameline[6] = { 0xFF, 0xFF, 0x40, 0xFF, 0x40, 0x20 };
