#include "common.h"

typedef struct { u8 pad_0[0xE]; s16 f0E; } NFSlot;
extern void *func_800AE080(s32);
extern void mlMtxRotatePYR(f32, f32, f32);
extern Vec3f D_80801950_chnewfreezy;
extern f32 sqrtf(f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct { f32 local_0[3]; f32 local_1[3]; u8 pad_0[0x30]; f32 local_2; u8 pad_1[0xC]; f32 local_3; s8 local_4; s8 local_5; s8 local_6; u8 pad_2; } FreezyPart241;
typedef struct { s32 local_0; f32 local_1; s8 local_2; s8 local_3; u8 pad_0[2]; } FreezyConfig241;
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
typedef struct { f32 local_0[3]; u8 pad_0[0x3C]; f32 local_1; u8 pad_1[0x10]; s8 local_2; u8 pad_2[3]; } FreezyFragment;
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80103DFC(Actor *, f32 *);
extern f32 func_800EC708(Unk80132ED0 *);
extern s32 func_800E3E8C(f32 *, f32);
typedef struct { f32 local_0[15]; u8 local_1[16]; s32 local_2; u8 local_3[12]; s8 local_4, local_5; u8 local_6[2]; } FreezyDrawPart;
typedef union { s32 word; void *pointer; } FreezyMessage;
extern int D_80801978_chnewfreezy[];
typedef struct { u8 pad0[0x18]; f32 unk18[3]; u8 pad24[0xC]; f32 unk30[3]; u8 pad3C[0x10]; f32 unk4C; u8 pad50[0xC]; s8 state; u8 pad5D[3]; } FreezyPart_808000D4_chnewfreezy;
extern f32 func_800F1DF4(void *, f32 *);
extern void func_8010D254(f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void _sufreezy_entrypoint_4(Unk80132ED0 *, s32);
typedef struct { f32 pos[3]; f32 unkC[3]; f32 vel[3]; f32 unk24[3]; f32 unk30[3]; f32 unk3C[3]; f32 unk48; f32 unk4C; f32 unk50; f32 unk54; f32 unk58; s8 state; u8 pad5D[3]; } FreezyPart_808002C0_chnewfreezy;
typedef struct { u8 pad0[0x78]; u32 pad78_3:29; u32 unk78_2:1; u32 pad78_0:2; } FreezyLink;
extern FreezyPart_808002C0_chnewfreezy *func_80100094(Actor *, s32);
extern f32 func_800D8FF8(void);
extern void _subaddiefade_entrypoint_3(Actor *);
extern FreezyLink *_subaddielink_entrypoint_4(void *);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_800D9078(f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800E3980(f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void _fxtwinkle_entrypoint_1(f32 *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern f32 func_800EEF94(f32 *);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern u8 D_8080195C_chnewfreezy[];
extern u8 D_8080196C_chnewfreezy[];
typedef struct { f32 local_0[4]; } FreezyQuaternion35;
void func_808000D4_chnewfreezy();
void func_808011A8_chnewfreezy(f32 param_0, f32 param_1);
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chnewfreezy(), func_80800020_chnewfreezy(), func_808016B4_chnewfreezy();

void func_80800000_chnewfreezy()
{
    _sufreezy_entrypoint_1();
}

void func_80800020_chnewfreezy(param_0) u8 **param_0;
{
  s16 new_var;
  s16 local_0;
  local_0 = *((s16 *) (((s8 *) (*param_0)) + 0x10));
  if ((*((s16 *) (((s8 *) (*param_0)) + 0x10))) != 0)
  {
    new_var = *((s16 *) (((s8 *) (*param_0)) + 0x10));
    func_800ADFE0(new_var, *((s16 *) (((s8 *) (*param_0)) + 0x10)), param_0);
    *((s16 *) (((s8 *) (*param_0)) + 0x10)) = 0;
  }
}

void func_80800068_chnewfreezy(u8 *param_0) {
    func_8010A828(_subaddielink_entrypoint_4(func_80100094(param_0, 1)), (u32)((u8) (*(u8 *)((s8 *)(param_0) + (0x79)))) >> 4);
}

void func_808000AC_chnewfreezy(s32 arg0)
{
    _sufreezy_entrypoint_2();
    func_8010A570(arg0);
}
void func_808000D4_chnewfreezy(param_0) Actor *param_0;
{
    f32 local_0[5];
    FreezyPart_808000D4_chnewfreezy *local_1;
    u32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;

    local_1 = func_80100094(param_0, 0);
    if (param_0->unk64_20) {
        return;
    }
    param_0->unk64_20 = 1;
    param_0->unk54 = 0.0f;
    func_8010D254(local_0);
    local_6 = 20.0f;
    local_7 = 65.0f;
    for (local_2 = 0; local_2 < param_0->unk6C_0; local_2++) {
        if (local_1->state == 3) {
            local_1++;
        } else {
        local_3 = func_800F1DF4(local_1, local_0);
        local_4 = func_800DC178(-local_6, local_6);
        local_5 = func_800DC178(-local_7, local_7);
        func_800EEC30(local_1->unk18, local_4 + 130.0f, local_5 + local_3, func_800DC178(800.0f, 1000.0f));
        local_1->unk30[0] = func_800DC178(-25.0f, 25.0f);
        local_1->unk30[1] = func_800DC178(-25.0f, 25.0f);
        local_1->unk30[2] = func_800DC178(-25.0f, 25.0f);
        local_1->state = 4;
        local_1->unk4C *= 0.6f;
        local_1++;
        }
    }
    _sufreezy_entrypoint_4(param_0->unk0, 8);
}

void func_808002C0_chnewfreezy(Actor *param_0)
{
    s32 fill0;
    s32 fill1;
    u32 local_2;
    s32 local_3;
    u32 local_1;
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[2];
    FreezyPart_808002C0_chnewfreezy *local_0;
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    f32 local_10[3];
    f32 local_11[3];
    s32 local_13;
    f32 local_14;
    f32 local_15;
    f32 local_16;
    FreezyLink *local_12;

    local_0 = func_80100094(param_0, 0);
    local_3 = param_0->unk6C_0;
    if (param_0->unk64_20) {
        if (param_0->unk54 < 5.0f) {
            param_0->unk54 += func_800D8FF8();
        } else {
            _subaddiefade_entrypoint_3(param_0);
        }
    }
    local_12 = _subaddielink_entrypoint_4(func_80100094(param_0, 1));
    if (local_12) {
        if (!local_12->unk78_2) {
            func_80800068_chnewfreezy(param_0);
            func_808000AC_chnewfreezy(param_0);
        } else {
            _sudeflect_entrypoint_0(param_0->position, 0.0f, param_0->unk74_7 * 0.75f, 2);
            if (func_800D9078(&param_0->unk58)) {
                func_80800068_chnewfreezy(param_0);
                func_808000D4_chnewfreezy(param_0);
                func_808000AC_chnewfreezy(param_0);
            }
        }
    }
    local_2 = func_800DC128(0, param_0->unk6C_0 * 5);
    for (local_1 = 0; local_1 < param_0->unk6C_0; local_1++, local_0++) {
        if (1) {}
        switch (local_0->state) {
        case 2:
            if (local_1 == local_2) {
                func_800E3980(local_5);
                func_800F18FC(local_0->pos, local_5, local_6);
                for (local_13 = 0; local_13 < 2; local_13++) {
                    local_6[1] += func_800DC178(0.0f, 160.0f) - 80.0f;
                }
                func_800EEBF0(local_4, local_6, local_0->unk4C * 25.0f);
                func_800EF04C(local_4, local_0->pos);
                _fxtwinkle_entrypoint_1(local_4, 0x9E5);
            }
            break;
        case 1:
            local_0->unk50 = func_800F10B4(*(f32 *)&param_0->actorData[3], local_0->unk54, local_0->unk58, 0, 1.0f);
            if (1.0f <= local_0->unk50) {
                local_0->state = 2;
            }
            local_0->unk4C = local_0->unk48 * local_0->unk50;
            func_800EFB24(local_7, local_0->pos, local_0->unk24);
            func_800EF334(local_7, local_0->unk50);
            func_800EE780(local_0->unk3C, local_0->unk24, local_7);
            break;
        case 4:
            func_800EFA20(local_8, local_0->vel, func_800D8FF8());
            func_800EE7F8(local_9, local_0->unk3C);
            func_800EE780(local_10, local_9, local_8);
            func_800EF04C(local_10, local_8);
            if (func_800BEF00(local_9, local_10, local_11, 0x20020)) {
                local_14 = func_800EEF94(local_0->vel);
                local_15 = func_800EEF94(local_8) * 2;
                local_16 = func_800EEAD4(local_9, local_10);
                if (local_16 < local_15) {
                    func_800EF334(local_8, local_16 / local_15 * 0.9f);
                }
                func_800EFDE8(local_0->vel, local_0->vel, local_11);
                func_800EF368(local_0->vel, local_14 * 0.35f);
                func_800EF334(local_0->unk30, 0.35f);
                if (local_14 < 250.0f) {
                    local_0->state = 5;
                }
            } else {
                local_0->vel[0] *= 0.95f;
                local_0->vel[2] *= 0.95f;
                local_0->vel[1] -= 50.0f;
                func_800EF04C(local_0->unkC, local_0->unk30);
                func_800EF334(local_0->unk30, 0.99f);
            }
            func_800EF04C(local_0->unk3C, local_8);
            break;
        case 3:
            local_3--;
            break;
        case 5:
            local_3--;
            break;
        }
    }
    if (local_3 == 0) {
        _subaddiefade_entrypoint_3(param_0);
    } else {
        *((f32 *) (&param_0->actorData[3])) += (func_800D8FF8() * 450.0f) * (*((f32 *) (&param_0->actorData[7])));
    }
    param_0->unk50 += func_800D8FF8();
}

void func_80800824_chnewfreezy(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    u8 *base;
    NFSlot *arr;
    NFSlot *selfp;
    NFSlot *p;
    u8 *e;
    u8 *o;
    s32 i;

    base = func_80100094(param_0, 0);
    i = 0;
    if (param_2 > 0) {
        arr = (NFSlot *)((param_1 + 8) ^ 0); // KUNSTGRIFF ^0
        selfp = &arr[param_3];
        do {
            p = &arr[i];
            if (i == 0x60) {} // KUNSTGRIFF empty test (prio of constant 0x60)
            if (selfp != p) {
                e = base + i * 0x60;
                if (*(f32 *)(e + 0x58) == -1.0f && (param_3 == p->f0E || i == selfp->f0E)) {
                    o = base + param_3 * 0x60;
                    *(f32 *)(e + 0x54) = *(f32 *)(o + 0x58);
                    *((f32 *) (e + 0x58)) = (*((f32 *) (o + 0x58))) + func_800EEAD4(e, o);
                    func_800EE7F8(e + 0x24, o);
                    func_80800824_chnewfreezy(param_0, param_1, param_2, i);
                }
            }
            i++;
        } while (i != param_2);
        if (selfp) {} // KUNSTGRIFF empty tests: lower selfp's prio (range +blocks)
        if (selfp) {}
        if (selfp) {}
    }
}

void func_80800974_chnewfreezy(Actor *param_0, s32 param_1)
{
    f32 local_1;
    void *local_3;
    u32 local_4;
    u8 *local_5;
    f32 local_0[4][4];

    local_5 = func_80100094(param_0, 0);
    func_800AE290(*(s16 *)((u8 *)param_0->unk0 + 0x10), param_1, func_800DF324());
    local_3 = func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10));
    for (local_4 = 0; local_4 < param_0->unk6C_0; local_4++) {
        mlMtxSet(func_800ADE50(local_3, param_1, _dbskeleton_entrypoint_4(param_1, local_4)));
        mlMtxRotatePYR(param_0->rotation[0], param_0->rotation[1], param_0->rotation[2]);
        mlMtxGet(local_0);
        func_800F2C1C(local_0, local_5 + 0xC);
        *(f32 *)(local_5 + 0x10) = *(f32 *)(local_5 + 0x10) - 90.0f;
        *(f32 *)(local_5 + 0x14) = -*(f32 *)(local_5 + 0xC);
        *(f32 *)(local_5 + 0xC) = 0.0f;
        local_5 += 0x60;
    }
}

void func_80800AA4_chnewfreezy(Actor *param_0, s32 param_1)
{
    void *local_3;
    u32 local_4;
    u8 *local_5 = (u8 *)func_80100094(param_0, 0);
    s32 local_6;
    f32 local_0[4][4];
    Vec3f local_1;
    f32 local_2[3];

    func_800AE40C(*(s16 *)((u8 *)param_0->unk0 + 0x10), param_1, func_800DF324());
    local_3 = func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10));
    for (local_4 = 0; local_4 < param_0->unk6C_0; local_4++, local_5 += 0x60) {
        local_6 = _dbskeleton_entrypoint_4(param_1, local_4);
        local_1 = D_80801950_chnewfreezy;
        mlMtxSet(func_800ADE50(local_3, param_1, local_6));
        mlMtxGet(local_0);
        func_800F23D0(local_0, local_2, &local_1);
        *(f32 *)(local_5 + 0x48) = sqrtf(local_2[0] * local_2[0] + local_2[1] * local_2[1] + local_2[2] * local_2[2]);
    }
}

void func_80800BFC_chnewfreezy(Actor *param_0, s32 param_1)
{
    void *local_0;
    u32 local_1;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    func_800AE1E8(*(s16 *)((u8 *)param_0->unk0 + 0x10), param_1, func_800DF324());
    local_0 = func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10));
    for (local_1 = 0; local_1 < param_0->unk6C_0; local_1++) {
        func_800AE630(local_0, param_1, _dbskeleton_entrypoint_4(param_1, local_1), local_2);
        func_800EF334((f32 *)local_2, *(f32 *)&param_0->actorData[7]);
        func_800EF5A0((f32 *)local_2, param_0->rotation,
            ((f32 *)local_2)[0], ((f32 *)local_2)[1], ((f32 *)local_2)[2]);
        func_800EF04C(local_2, param_0->position);
        *(f32 *)(local_2 + 0x4C) = 0.0f;
        func_800EE7F8((f32 *)(local_2 + 0x24), (f32 *)local_2);
        local_2 += 0x60;
    }
}

void func_80800D28_chnewfreezy(Actor *param_0, void *param_1)
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    u32 local_4;
    s32 local_5;
    local_0 = func_80100094(param_0, 0);
    local_1 = 0.0f;
    local_2 = 0.0f;
    local_5 = -1;
    for (local_4 = 0; local_4 < (*(u32 *)((u8 *)param_0 + 0x6C) & 0x1FF); local_4++, local_0 += 0x60) {
        local_3 = func_800EEAD4((f32 *)param_0->actorData, (f32 *)local_0);
        if (!local_4 || local_1 < local_3) local_1 = local_3;
        if (!local_4 || local_3 < local_2) {
            local_2 = local_3;
            local_5 = local_4;
        }
        *(f32 *)(local_0 + 0x58) = -1.0f;
    }
    if (local_5 != -1) {
        local_0 = (u8 *)func_80100094(param_0, 0) + local_5 * 0x60;
        *(f32 *)(local_0 + 0x58) = 100.0f;
        *(f32 *)(local_0 + 0x54) = 0.0f;
        func_80800824_chnewfreezy(param_0, param_1, *(u32 *)((u8 *)param_0 + 0x6C) & 0x1FF, local_5);
    }
}

void func_80800E74_chnewfreezy(Actor *param_0, void *param_1, FreezyConfig241 *param_2, s32 param_3)
{
    FreezyPart241 *local_0;
    s32 local_2;
    u32 local_1;
    s32 local_3;
    FreezyConfig241 *local_4;
    u32 local_5;
    s32 local_6;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < param_0->unk6C_0; local_1++, local_0++) {
        local_2 = _dbskeleton_entrypoint_4(param_1, local_1);
        local_0->local_4 = 3;
        if (local_0->local_3 == -1.0f) {
            local_0->local_3 = 100.0f;
        }
        for (local_3 = 0; local_3 < param_3; local_3++) {
            local_4 = &param_2[local_3];
            if (local_2 == local_4->local_0) {
                local_0->local_2 *= local_4->local_1;
                local_0->local_4 = 1;
                local_0->local_5 = local_4->local_2;
                local_0->local_6 = local_4->local_3;
                if (local_0->local_6 >= 0) {
                    for (local_5 = 0; local_5 < param_0->unk6C_0; local_5++) {
                        if (_dbskeleton_entrypoint_4(param_1, local_5) == local_0->local_6) {
                            func_800F18FC(local_0->local_0,
                                ((FreezyPart241 *)func_80100094(param_0, 0))[local_5].local_0,
                                local_0->local_1);
                            local_0->local_1[2] = local_0->local_1[0];
                            local_0->local_1[0] = 0.0f;
                            local_0->local_1[1] -= 90.0f;
                        }
                    }
                } else {
                    switch (local_0->local_6) {
                    case -4:
                        func_800EF214(local_0->local_0, local_0->local_1[0] + 45.0f,
                            param_0->rotation[1], local_0->local_2 * 25.0f);
                        break;
                    case -5:
                        func_800EF214(local_0->local_0, local_0->local_1[0] + 45.0f,
                            local_0->local_1[1] + 90.0f, local_0->local_2 * 25.0f);
                        break;
                    case -3:
                        func_800EF214(local_0->local_0, local_0->local_1[0] + 90.0f,
                            local_0->local_1[1] + 90.0f, local_0->local_2 * 25.0f);
                        break;
                    case -2:
                        func_800EF214(local_0->local_0, local_0->local_1[0] - 90.0f,
                            local_0->local_1[1] + 90.0f, local_0->local_2 * 25.0f);
                        break;
                    }
                }
            }
        }
        local_0->local_2 *= *(f32 *)&param_0->actorData[7];
    }
}

void func_808011A8_chnewfreezy(f32 param_0, f32 param_1)
{
    FreezyQuaternion35 local_0 = *(FreezyQuaternion35 *)D_8080195C_chnewfreezy;
    Vec3f local_1 = *(Vec3f *)D_8080196C_chnewfreezy;
    FreezyQuaternion35 local_2;
    FreezyQuaternion35 local_3;
    s32 local_4;
    local_4 = func_800DF324();
    func_800DFB40(local_4, 0x12, local_2.local_0);
    local_1.f[1] = param_0 * 0.75f;
    local_1.f[0] = -param_1 * 0.9f;
    func_800D93A0(&local_0, local_1.f);
    func_800D9470(&local_0, &local_0, local_2.local_0);
    func_800DFF2C(local_4, 0x12, &local_0);
    func_800DFB40(local_4, 1, local_3.local_0);
    local_1.f[1] = param_0 * 0.25f;
    local_1.f[0] = -param_1 * 0.1f;
    func_800D93A0(&local_0, local_1.f);
    func_800D9470(&local_0, &local_0, local_3.local_0);
    func_800DFF2C(local_4, 1, &local_0);
}

f32 func_808012F8_chnewfreezy(Actor *param_0)
{
    f32 local_0;
    FreezyFragment *local_1;
    u32 local_2;
    f32 local_3;

    local_1 = func_80100094(param_0, 0);
    local_0 = 0.0f;
    for (local_2 = 0; local_2 < param_0->unk6C_0; local_2++, local_1++) {
        if (local_1->local_2 != 3) {
            local_3 = func_800EEAD4((f32 *)&param_0->actorData[4], local_1->local_0) + 25.0f * local_1->local_1;
            if (local_0 < local_3) local_0 = local_3;
        }
    }
    return local_0;
}

Actor *chnewfreezy_entrypoint_0(Unk80132ED0 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;
    Actor *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5 = 0;
    f32 local_6;
    f32 local_7;
    Vec3f local_8;

    local_0 = func_80106790(param_0);
    local_4 = func_8010108C(local_0, 0x38, 0);
    if (local_4 <= 0) {
        return NULL;
    }
    local_3 = func_80101080();
    local_1 = func_801084B0(0x2FF, &local_0);
    ((f32 *)local_1->actorData)[0] = param_1;
    ((f32 *)local_1->actorData)[1] = param_2;
    ((f32 *)local_1->actorData)[2] = param_3;
    local_1->rotation[0] = local_0->rotation[0];
    local_1->rotation[1] = local_0->rotation[1];
    local_1->rotation[2] = local_0->rotation[2];
    ((f32 *)local_1->actorData)[7] = local_0->scale;
    local_1->unk50 = 0.0f;
    func_80103DFC(local_0, (f32 *)&local_1->actorData[4]);
    local_2 = func_800B27E0(func_801039E4(local_0->unk0));
    local_1->unk6C_0 = _dbskeleton_entrypoint_0(local_2);
    func_80100074(local_1, 0, local_1->unk6C_0 * 0x60);
    if (*(s16 *)((u8 *)local_1->unk0 + 0x10) == 0) {
        *(s16 *)((u8 *)local_1->unk0 + 0x10) = func_800AE020();
    }
    func_800DF41C(func_8008B4D4(func_80104248(local_0)));
    if (func_8010108C(local_0, 0x94, 0) > 0) {
        func_80101038(local_8.f);
        local_5 = 1;
        local_6 = local_8.pos.x;
        local_7 = local_8.pos.y;
    }
    if (local_5) {
        func_808011A8_chnewfreezy(local_7, local_6);
    }
    func_80800974_chnewfreezy(local_1, local_2);
    func_80800AA4_chnewfreezy(local_1, local_2);
    func_80800BFC_chnewfreezy(local_1, local_2);
    func_80800D28_chnewfreezy(local_1, local_2);
    func_80800E74_chnewfreezy(local_1, local_2, local_3, local_4);
    local_1->unk74_7 = func_808012F8_chnewfreezy(local_1);
    local_1->scale = (f32)local_1->unk74_7 / func_800EC708(local_1->unk0);
    _sufreezy_entrypoint_3(local_1);
    return local_1;
}

void func_808016B4_chnewfreezy(param_0, param_1) Actor *param_0; s32 param_1;
{
    FreezyDrawPart *local_1;
    s32 local_0[3];
    u32 local_2;
    if (func_800E3E8C((f32 *)((u8 *)param_0 + 0x28), (f32)param_0->unk74_7)) {
        local_1 = func_80100094(param_0, 0);
        local_0[0] = func_800D674C(0x74C);
        local_0[1] = func_800D674C(0x74D);
        local_0[2] = func_800D674C(0x74E);
        for (local_2 = 0; local_2 < param_0->unk6C_0; local_2++, local_1++) {
            if (local_1->local_4 != 3) {
                if (_subaddiefade_entrypoint_0(param_0) < 255)
                    func_800DF410(_subaddiefade_entrypoint_0(param_0));
                func_800DF830(2);
                func_800DE448((u8 *)local_1 + 0x3C, (u8 *)local_1 + 0xC,
                    local_1->local_2, 0, local_0[local_1->local_5]);
            }
        }
    }
}

s32 func_808017FC_chnewfreezy(Actor *param_0, s32 param_1, FreezyMessage param_2)
{
    switch (param_1) {
    case 0x3E:
        if (param_0->unk50 > 0.75f) {
            func_80800068_chnewfreezy(param_0);
            _sufreezy_entrypoint_5(param_0->unk0, param_2.word);
            func_808000D4_chnewfreezy(param_0);
            func_808000AC_chnewfreezy((s32)param_0);
        }
        break;
    case 0x3F:
        _sufreezy_entrypoint_6(param_0->unk0, param_2.word);
        return 1;
    case 0x40:
        func_80800068_chnewfreezy(param_0);
        _sufreezy_entrypoint_7(param_0->unk0, param_2.word);
        func_808000D4_chnewfreezy(param_0);
        func_808000AC_chnewfreezy((s32)param_0);
        return 1;
    case 0x95:
        if (!_subaddielink_entrypoint_3(func_80100094(param_0, 1))) func_800FFAB0(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

int chnewfreezy_entrypoint_1()
{
    return (int)&D_80801978_chnewfreezy;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/newfreezy.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801978_chnewfreezy -> int[] */
Vec3f D_80801950_chnewfreezy = { 0.577f, 0.577f, 0.577f };
u8 D_8080195C_chnewfreezy[16] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080196C_chnewfreezy[12] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_80801978_chnewfreezy[18] = { 0x2F602FF, 0x75D0001, 0x0, (u32)func_808002C0_chnewfreezy, (u32)func_80105834, (u32)func_808016B4_chnewfreezy, 0x0, 0x0, 0x0, 0x120020, (u32)func_80800020_chnewfreezy, (u32)func_80108ED0, 0x8, (u32)func_80800000_chnewfreezy, (u32)func_80107C2C, -0x7FFFE000, (u32)func_808017FC_chnewfreezy, 0x0 };
