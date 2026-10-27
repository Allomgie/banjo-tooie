#include "common.h"

extern s32 D_808004E0_subaddiefx;
extern s32 D_80800500_subaddiefx;
extern f32 R_808004D0_subaddiefx;
extern f32 func_80103EAC();
extern f32 func_8010A40C();
extern f32 func_80103EF4();
extern s32 _subaddieskeleton_entrypoint_2(s32, s32, s32 *);
extern void func_800EE7F8(void *, void *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern f32 func_80013970(f32);
extern s32 func_800B5BE4(s32);
extern void func_800BA3FC(s32, s32);
extern void func_800BABB8(s32, f32 *, s32, f32, s32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern u8 *func_80104118(void);
extern void func_800E3980(f32 *);
extern f32 func_800EEB40(f32 *, s32 *);
extern s32 _subaddieaudioloop_entrypoint_7();
typedef struct { s32 a : 15; s32 b : 15; u32 c : 2; s16 ph0; s16 ph1; } FxState;

void subaddiefx_entrypoint_0(u8 *param_0, s32 param_1, FxState *param_2)
{
    f32 local_1[3];
    f32 local_2;
    f32 local_4[3];
    f32 local_5[3];
    f32 local_14;
    f32 local_15;
    f32 local_6;
    f32 local_17;
    f32 local_7;
    f32 local_16;
    s32 local_8;
    s32 local_9;
    s32 local_18;
    f32 local_10[3];
    u8 *local_11;
    local_16 = func_80103EAC(param_0);
    local_2 = func_8010A40C(param_0) * local_16;
    if ((param_1 == -1) || (_subaddieskeleton_entrypoint_2(*((s32 *) (param_0 + 0)), param_1, (s32 *)local_1) == 0))
    {
        func_800EE7F8(local_1, param_0 + 4);
        local_14 = func_80103EF4(param_0);
        local_1[1] += 0.8f * local_14;
    }
    if (((Actor *)param_0)->unk7C_12)
    {
        local_17 = 0.0f;
        local_6 = func_800D8FF8();
        local_7 = param_2->ph0 * 0.00390625f;
        local_15 = param_2->ph1 * 0.00390625f;
        local_8 = func_800B5BE4(0x15);
        local_9 = func_800B5BE4(0x16);
        func_800BA3FC(local_8, 0x9E0);
        func_800BA3FC(local_9, 0x9E9);
        for (local_18 = 0, local_16 = 0.0f; local_18 != 4; local_18++)
        {
            func_800EEB9C(local_5, param_2->a + local_16, local_2 + local_17);
            func_800EE780(local_4, local_1, local_5);
            local_14 = func_80013970(local_7 + local_16);
            local_4[1] += 30.0f * local_14;
            func_800BABB8(local_8, local_4, 0, 1.0f, &D_808004E0_subaddiefx);
            func_800EEB9C(local_5, param_2->b + local_16, local_2 + local_17);
            local_17 = 40.0f;
            func_800EE780(local_4, local_1, local_5);
            local_14 = func_80013970(local_15 + local_16);
            local_4[1] += 30.0f * local_14;
            func_800BABB8(local_9, local_4, 0, 1.0f, &D_808004E0_subaddiefx);
            local_16 += 90.0f;
        }
        param_2->a = func_800136E4(param_2->a + 390.0f * local_6);
        param_2->b = func_800136E4(param_2->b - 430.0f * local_6);
        local_7 += local_6 * 100.0f;
        local_15 += local_6 * 150.0f;
        param_2->ph0 = 256.0f * local_7;
        param_2->ph0 = 256.0f * local_15;
    }
    local_11 = func_80104118();
    if ((*((s16 *) (local_11 + 0xE)) == 0) || (local_11[0xD] == 0))
    {
        func_800EE7F8(local_11, local_1);
        local_11[0xD] = 1;
    }
    else
    {
        func_800E3980(local_10);
        local_14 = func_800EEB40(local_10, (s32 *)local_1);
        if (local_14 < func_800EEB40(local_10, (s32 *) local_11))
        {
            func_800EE7F8(local_11, local_1);
        }
    }
    local_11[0xC] = _subaddieaudioloop_entrypoint_7(local_11[0xC], local_11, 1, &D_80800500_subaddiefx, (*((s32 *) (param_0 + 0x70))) & 1);
    if (param_2->c == 0)
    {
        param_2->c = 1;
        *((s16 *) (local_11 + 0xE)) = (s16) ((*((s16 *) (local_11 + 0xE))) + 1);
    }
}

void subaddiefx_entrypoint_1(s32 param_0, u8 *param_1) {
    u8 *temp_v0;
    u8 *sp1C;

    if ((*(s32 *)param_1) & 3) {
        temp_v0 = func_80104118();
        (*(s16 *)((s8 *)param_1 + 4)) = 0;
        (*(s16 *)((s8 *)param_1 + 6)) = 0;
        (*(u8 *)((s8 *)param_1 + 3)) = (u8)((*(u8 *)((s8 *)param_1 + 3)) & 0xFFFC);
        (*(s8 *)((s8 *)temp_v0 + 0xD)) = 0;
        (*(s16 *)((s8 *)temp_v0 + 0xE)) = (s16)((*(s16 *)((s8 *)temp_v0 + 0xE)) - 1);
        if ((*(s16 *)((s8 *)temp_v0 + 0xE)) == 0) {
            sp1C = temp_v0;
            (*(s8 *)((s8 *)sp1C + 0xC)) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)temp_v0 + 0xC)), param_1);
        }
    }
}
