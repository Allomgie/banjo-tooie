#include "common.h"

typedef struct { s32 local_0; s32 local_1; } LensFlareMap59;
extern LensFlareMap59 D_808008F0_chlensflare[];
extern int D_80800928_chlensflare;
extern void func_800EFA88();
typedef struct { u32 r:8; u32 g:8; u32 b:8; u32 a:8; f32 unk4; f32 unk8; u8 unkC; u8 padD[3]; } FlareElem;
typedef struct { FlareElem *elems; s32 unk4; } FlareDef;
extern FlareDef D_808008F4_chlensflare[];
extern s32 func_800BFFB4(s32, s32, f32 *);
extern void func_800E8830(s32, f32 *);
extern s32 func_800E88AC(s32, f32 *);
extern f32 mlAbsF(f32);
extern void func_800E40DC(f32, f32, f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800B99CC(Gfx **, s32, f32 *);
extern void func_800E2588(s32);
extern void func_800E24F8(s32, s32, s32);
extern s32 func_800D674C(s32);
extern void func_800E2594(Gfx **, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800E3980(f32 *);
extern f32 func_800EEFD4(f32 *);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800E2530(f32);
extern void func_800E2720(Gfx **, s32, s32, f32 *, f32 *, s32);
extern void func_800E2A14(Gfx **);
typedef struct { u8 pad0[0x24]; s32 unk24; u8 pad28[0xC]; f32 unk34; u8 pad38[0x18]; u8 unk50; u8 pad51[0x13]; u32 pad64_21:11; u32 unk64_20:1; u32 pad64_0:20; } LensFlare;
extern void func_80105834(), func_80107C2C(), func_80800084_chlensflare();

s32 chlensflare_entrypoint_0(void)
{
    s32 local_0 = 0;
    s32 local_1;

    local_1 = func_800EA05C();
    if (!_gcskyDll_entrypoint_3()) return 0;
    for (; D_808008F0_chlensflare[local_0].local_0 != -1; local_0++) {
        if (local_1 == D_808008F0_chlensflare[local_0].local_0) return 1;
    }
    return 0;
}

void func_80800084_chlensflare(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    LensFlareMap59 *local_2;
    local_0 = func_800EA05C();
    local_2 = D_808008F0_chlensflare;
    local_1 = 0;
    while (1) {
        if (local_2->local_0 == -1) {
            func_800FFAB0(param_0);
            return;
        }
        if (local_0 == local_2->local_0) {
            param_0->actorData[3] = local_1;
            break;
        }
        local_2++;
        local_1++;
    }
    *(f32 *)&param_0->actorData[7] = 1.01f;
}

void func_808000FC_chlensflare(LensFlare *param_0, Gfx **param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[2];
    f32 local_4;
    FlareElem *local_5;
    FlareElem *local_6;
    s32 local_7;
    f32 local_8[3];
    f32 local_9[3];
    s32 local_13;
    f32 local_10[3];
    f32 local_11[3];
    s32 local_14;

    if (!func_800BFFB4(0, 4, local_0)) {
        return;
    }
    func_800E8830(param_0->unk50, local_0);
    if (func_800E88AC(param_0->unk50, local_3) == 1 || param_0->unk64_20) {
        local_4 = (mlAbsF(local_3[0] - 152.0f) * mlAbsF(local_3[0] - 152.0f) + mlAbsF(local_3[1] - 114.0f) * mlAbsF(local_3[1] - 114.0f)) / 19602.0f;
        if (param_0->unk34 < local_4) {
            param_0->unk34 *= 1.35f;
            if (local_4 < param_0->unk34) {
                param_0->unk34 = local_4;
            } else {
                local_4 = param_0->unk34;
            }
        } else {
            param_0->unk34 /= 1.35f;
            if (param_0->unk34 < local_4) {
                param_0->unk34 = local_4;
            } else {
                local_4 = param_0->unk34;
            }
        }
    } else {
        if (param_0->unk34 < 1.01f) {
            param_0->unk34 *= 1.35f;
        }
        if (1.0f < param_0->unk34) {
            param_0->unk34 = 1.01f;
            return;
        }
        local_4 = param_0->unk34;
    }
    if (1.0f < local_4) {
        return;
    }
    local_3[0] = 304.0f - local_3[0];
    local_3[1] = 228.0f - local_3[1];
    func_800E40DC(local_3[0], local_3[1], local_1, local_2);
    func_800EFB24(local_2, local_1, local_0);
    local_5 = D_808008F4_chlensflare[param_0->unk24].elems;
    for (local_7 = 0; local_5[local_7].unkC != 0; local_7++) {}
    local_6 = (FlareElem *)((u8 *)local_5 + local_7 * 16);
    if (local_6->r) {
        func_800EFA88(local_8, local_6->r, local_6->g, local_6->b);
        func_800B99CC(param_1, local_6->a * (1 - local_4), local_8);
    }
    local_14 = 0;
    func_800E2588(0);
    func_800E24F8(local_5->r, local_5->g, local_5->b);
    func_800E2594(param_1, func_800D674C(0x9D2));
    for (local_7 = 0; local_5[local_7].unkC != 0; local_7++) {
    local_13 = local_5[local_7].a * (1.0f - local_4);
    if (1) {}
    if (local_13 == local_14) {
        local_13++;
    }
    local_14 = local_13;
    func_800E24F8(local_5[local_7].r, local_5[local_7].g, local_5[local_7].b);
    func_800EFA4C(local_1, local_5[local_7].unk4 + local_4, local_5[local_7].unk4 + local_4, local_5[local_7].unk4 + local_4);
    func_800EE7F8(local_9, local_0);
    func_800EF174(local_9, local_2, local_5[local_7].unk8);
    func_800E3980(local_11);
    func_800EFB24(local_10, local_9, local_11);
    if (400000000.0f < func_800EEFD4(local_10)) {
        func_800EFA98(local_10, local_10, 20000.0f);
        func_800EE780(local_9, local_11, local_10);
    }
    switch (local_5[local_7].unkC) {
    case 1:
        func_800E2530(0.0f);
        func_800E2720(param_1, 0, 0, local_9, local_1, local_13);
        break;
    case 2:
        func_800E2530(45.0f);
        func_800E2720(param_1, 0, 0, local_9, local_1, local_13);
        break;
    case 3:
        func_800E2720(param_1, 1, 0, local_9, local_1, local_13);
        break;
    }
}
    func_800E2A14(param_1);
    param_0->unk64_20 = 0;
}

int func_80800634_chlensflare(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0x95)
  {
    *(u8 *)((char *)param_0 + 0x50) = func_800E8714(0);
    return 1;
  }
  return 0;
}

int *chlensflare_entrypoint_1()
{
    return &D_80800928_chlensflare;
}
