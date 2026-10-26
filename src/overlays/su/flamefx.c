#include "common.h"

extern void func_80100074(s32, s32, s32);
extern u8 *func_80100094(s32, s32);
typedef struct FlameFxSettings { f32 local_0; f32 local_1; f32 local_2; s16 local_3; s16 local_4; u8 pad_0[0xA]; u8 local_5; u8 pad_1[2]; u8 local_6; } FlameFxSettings;
typedef struct FlameFxParticle { f32 local_0[3]; f32 local_1[3]; u8 pad_0[0xC]; f32 local_2; f32 local_3; u8 local_4; } FlameFxParticle;
extern f32 func_800DC178(f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern f32 func_800D8FF8(void);
typedef struct FlameEffectNode { u8 pad_0[0x18]; f32 local_0[3]; u8 pad_1[4]; f32 local_1; u8 local_2; u8 pad_2[3]; } FlameEffectNode;
typedef struct FlameEffectDrawState { u8 pad_0[0x18]; s16 local_0; u8 pad_1; u8 local_1; u8 pad_2[4]; FlameEffectNode local_2[1]; } FlameEffectDrawState;
extern s32 func_800E3E8C(f32 *, f32);
extern void *func_800D674C(s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2720(void *, s32, s32, f32 *, f32 *, s32);

void suflamefx_entrypoint_0(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s16 param_3; {
    u8 *local_0;
    func_80100074(param_0, param_1, param_2 * 0x30 + 0x20);
    local_0 = func_80100094(param_0, param_1);
    *(s16 *)(local_0 + 0x18) = param_3;
    local_0[0x1B] = param_2;
}

void suflamefx_entrypoint_1(s32 p0, s32 p1) {
    func_80100074(p0, p1, 0);
}

void func_80800428_suflamefx();

void suflamefx_entrypoint_2(u8 *param_0, s32 param_1)
{
    f32 local_1;
    s32 local_2;
    s32 local_3;
    u8 *local_4;

    local_1 = func_800D8FF8();
    local_4 = param_0 + 0x20;
    for (local_2 = 0; local_2 < param_0[0x1B]; local_2++, local_4 += 0x30) {
        if (*(f32 *)(local_4 + 0x28) > 0.05f) {
            *(f32 *)(local_4 + 0x10) += *(f32 *)(local_4 + 0x24) * local_1;
            *(f32 *)(local_4 + 0xC) *= *(f32 *)(param_0 + 0x10);
            *(f32 *)(local_4 + 0x14) *= *(f32 *)(param_0 + 0x10);
            *(f32 *)(local_4 + 0x28) += *(f32 *)(param_0 + 0x14);
        } else if (param_0[0x1C] == 1) {
            *(f32 *)(local_4 + 0x28) = 0.0f;
        } else {
            func_80800428_suflamefx((struct FlameFxSettings *)param_0,
                (struct FlameFxParticle *)local_4, (f32 *)param_1);
        }
        if (param_0[0x1A] == 0xFF) {
            local_3 = local_4[0x2C];
            if (local_3 >= param_0[0x1D]) local_4[0x2C] = 0;
            else local_4[0x2C] = local_3 + 1;
        }
        func_800EE780(local_4 + 0x18, local_4, local_4 + 0xC);
    }
}

void suflamefx_entrypoint_3(FlameEffectDrawState *param_0, void *param_1)
{
    f32 local_0[3];
    FlameEffectNode *local_1;
    s32 local_2;
    void *local_3;

    local_1 = param_0->local_2;
    if (func_800E3E8C(local_1->local_0, 250.0f)) {
        local_3 = func_800D674C(param_0->local_0);
        func_800E2588(1);
        func_800E2594(param_1, local_3);
        for (local_2 = 0; local_2 < param_0->local_1; local_2++, local_1++) {
            if (local_1->local_1 > 0.05f) {
                func_800EFA4C(local_0, local_1->local_1, local_1->local_1, local_1->local_1);
                func_800E2720(param_1, local_1->local_2, 0, local_1->local_0, local_0, 255);
            }
        }
        func_800E2A14(param_1);
    }
}

void suflamefx_entrypoint_4(s32 param_0)
{
    ((u8 *)param_0)[0x1C] = 1;
}

void suflamefx_entrypoint_5(s32 *param_0, f32 param_1, f32 param_2)
{
  int new_var;
  char new_var2;
 new_var = 3; if (0) { } *(s16*)((char*)param_0 + 0xC) = (s16)param_1; *(s16*)((char*)param_0 + 0xE) = (s16)param_2;
}

void suflamefx_entrypoint_6(Actor *param_0, f32 param_1)
{
    *(f32 *)((char *)param_0 + 0x14) = param_1;
}

void suflamefx_entrypoint_7(u8 *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4, u8 param_5, f32 param_6)
{
    u8 *local_0;
    s32 local_1;

    *(f32 *)(param_0 + 8) = param_2;
    *(f32 *)(param_0 + 4) = param_3;
    *(f32 *)(param_0 + 0) = param_4;
    param_0[0x1A] = param_5;
    *(f32 *)(param_0 + 0x10) = param_6;
    *(s16 *)(param_0 + 0xC) = 100;
    *(s16 *)(param_0 + 0xE) = 200;
    *(f32 *)(param_0 + 0x14) = -0.03f;
    param_0[0x1C] = 0;
    if (param_0[0x1A] == 0xFF) {
        param_0[0x1D] = func_800AF5A0(func_800D674C(*(s16 *)(param_0 + 0x18))) - 1;
    } else {
        param_0[0x1D] = 0xFF;
    }
    local_0 = param_0 + 0x20;
    for (local_1 = 0; local_1 < param_0[0x1B]; local_1++, local_0 += 0x30) {
        func_80800428_suflamefx((struct FlameFxSettings *)param_0,
            (struct FlameFxParticle *)local_0, param_1);
        *(f32 *)(local_0 + 0x28) = func_800DC178(0.0f, *(f32 *)(param_0 + 4));
    }
}

void func_80800428_suflamefx(FlameFxSettings *param_0, FlameFxParticle *param_1, f32 *param_2)
{
    f32 local_0[3];
    f32 local_1;

    param_1->local_1[1] = func_800DC178(0.0f, 20.0f);
    param_1->local_2 = func_800DC178(param_0->local_3, param_0->local_4);
    param_1->local_3 = func_800DC178(param_0->local_2, param_0->local_1);
    if (param_0->local_5 == 0xFF) {
        param_1->local_4 = func_800DC128(0, param_0->local_6);
    } else {
        param_1->local_4 = param_0->local_5;
    }
    func_800EE7F8(param_1->local_0, param_2);
    func_800E3980(local_0);
    local_1 = func_800F1DF4(param_1->local_0, local_0);
    func_800EFCD8(param_1->local_1, func_800DC178(-90.0f, 90.0f) + local_1, param_0->local_0);
}
