#include "common.h"

extern int D_80800B90_chfactorylight[];
extern void *func_80100094(Actor *, u32);
typedef struct { u8 pad_0[15]; u8 alpha; } FactoryLightVertex;
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct { u8 pad_0[0x10]; s32 local_0; s32 local_1; s32 local_2; } FactoryLightColor;
extern void func_801015D0(Actor *);
extern void func_80101808(Actor *, void (*)(Actor *));
extern void func_800EE7F8(f32[3], f32[3]);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
extern void func_80103014(Actor *);
typedef struct { f32 f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15; } ADF_;
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } FLightState;
extern u8 _chfactorylight_entrypoint_1[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800F3214(f32 *, f32 *, f32 *, s32);
extern void func_800C4140(u32, f32 *, u32);
extern int func_800D9154(f32 *, f32);
extern void func_800C8CB8(s32 param_0, f32 param_1[3]);
extern void func_800C8E84(s32 param_0, u32 param_1[3]);
extern s32 func_800D90A4(f32 *param_0);
extern void func_800EF04C(f32 *param_0, f32 *param_1);
extern void func_80101FDC(Actor *param_0, u32 param_1);
extern s32 func_801065A4(s32 param_0);
typedef struct { u8 pad0[0x7C]; u32 pad7C : 16; u32 flag : 1; u32 rest : 15; } FactoryLightFlags;
typedef struct { s32 local_0[2]; f32 local_1[2]; u8 local_2[1]; } FactoryLights50;
extern void func_800C8E54(s32, f32, f32);
void func_80800830_chfactorylight();
s32 func_8080057C_chfactorylight();
void func_808008E4_chfactorylight();
extern void func_80105834(), func_80107C2C(), func_80800408_chfactorylight(), func_808006B8_chfactorylight();

int *chfactorylight_entrypoint_0()
{
    return &D_80800B90_chfactorylight;
}

s32 func_8080000C_chfactorylight(param_0) s32 param_0;{
    func_80800830_chfactorylight(param_0);
    func_8010A800(param_0, 2);
}

void func_80800038_chfactorylight(Actor *param_0)
{
    s32 *local_10;
    s32 local_7;
    f32 local_0[1];
    s32 *local_1;
    s32 *local_9;
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    f32 local_5[3];
    u16 t;
    local_1 = func_80100094(param_0, 0);
    local_3 = func_800D8FF8();
    local_9 = local_1;
    func_800EE7F8(local_2, param_0->position);
    func_800EF1B8(local_2, *(f32 *)&param_0->rotation[1], param_0->scale * 300.0f);
    local_4 = func_800E3E8C(local_2, param_0->scale * 1300.0f);
    switch (((FLightState *)param_0)->st) {
    case 1:
        func_800F2E60(local_0, (u8 *)local_9 + 0x10);
        param_0->unk54 = 1.0f;
        break;
    case 2:
        func_800EFD3C(local_0);
        param_0->unk54 = 0.0f;
        break;
    case 3:
        if (func_800D90A4(&param_0->unk58)) {
            func_80101FDC(param_0, 1);
        }
        param_0->unk54 = func_800F10B4(param_0->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
        func_800EFD3C(local_5);
        func_800F3214(local_0, local_5, (f32 *)((u8 *)local_9 + 0x10), *(s32 *)&param_0->unk54);
        break;
    }
    param_0->rotation[2] = func_800136E4(((local_3 * (*((f32 *) (&param_0->actorData[7])))) * param_0->unk54) + param_0->rotation[2]);
    if (param_0->unk78 && !_subaddiezone_entrypoint_1(param_0)) {
        local_4 = 0;
    }
    for (local_7 = 0, local_10 = local_1; local_7 < 8; local_7 += 4, local_10++) {
        *(f32 *)&local_10[2] = func_800136E4(*(f32 *)&local_10[2] + local_3 * ((ADF_ *)param_0->actorData)->f7 * param_0->unk54);
        func_800EEC30(local_2, *(f32 *)&local_10[2], param_0->rotation[1] + 90.0f, param_0->scale * 500.0f);
        func_800EF04C(local_2, param_0->position);
        func_800EF1B8(local_2, *(f32 *)&param_0->rotation[1], param_0->scale * 300.0f);
        if (local_4) {
            func_800C8CB8(local_10[0], local_2);
            func_800C8E84(local_10[0], local_0);
        }
    }
    if (param_0->unk7C_12) {
        if (func_801065A4(param_0)) {
            _glid_entrypoint_0(func_801065A4(param_0), 1, _chfactorylight_entrypoint_1, param_0->unk0);
        }
    }
    if (func_800EA05C() == 0x10D) {
        if (((FLightState *)param_0)->st == 3 || ((FLightState *)param_0)->st == 1) {
            if (func_800D9154(&param_0->actorData[3], 1.3f)) {
                t = (u32)(func_800F1214(param_0->unk54, 0.9f, 1.1f) * 1023.0f);
                func_800C4140((t << 21) + 0x1F4566, param_0->position, 0x138800FA);
            }
        }
    }
}

void func_80800408_chfactorylight(param_0) Actor *param_0;
{
    s32 local_0;
    s32 *local_1;

    local_1 = func_80100094(param_0, 0);
    for (local_0 = 0; local_0 < 2; local_0++) {
        if (local_1[local_0] != 0) {
            func_800C8B84(local_1[local_0]);
            local_1[local_0] = 0;
        }
    }
}

void chfactorylight_entrypoint_1(s32 param_0, FactoryLightVertex *param_1, FactoryLightVertex *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    Actor *local_0;
    FactoryLightVertex *local_1;
    local_0 = func_80106790(param_4);
    local_1 = param_2 + param_3;
    for (; param_2 < local_1; param_1++, param_2++) {
        param_2->alpha = (u32)(param_1->alpha * local_0->unk54);
    }
}

s32 func_8080057C_chfactorylight(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    s32 local_1;
    s32 *local_2;
    s32 *local_3;

    switch (param_1) {
        case 0xA:
            if (param_2) local_0 = 1;
            else local_0 = 0;
            local_2 = func_80100094(param_0, 0);
            if (!((FactoryLightFlags *)param_0)->flag) {
                func_808008E4_chfactorylight(param_0);
                ((FactoryLightFlags *)param_0)->flag = 1;
            }
            if (func_800EA05C() == 0x10D) {
                func_80101FDC(param_0, local_0 ? 3 : 2);
                param_0->unk58 = 5.0f;
                *(f32 *)((u8 *)param_0 + 0x24) = 1.3f;
            } else {
                func_80101FDC(param_0, local_0 ? 1 : 2);
            }
            for (local_1 = 0; local_1 < 8; local_1 += 4) {
                func_800C8FE0(*(s32 *)((u8 *)local_2 + local_1), local_0);
            }
            break;
        case 0x95:
            func_808008E4_chfactorylight(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808006B8_chfactorylight(param_0, param_1) Actor *param_0; s32 param_1;
{
    FactoryLightColor *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
    case 3:
        local_1 = param_0->unk54;
        func_800DF5D8((s32)(local_0->local_0 * local_1),
                     (s32)(local_0->local_1 * local_1),
                     (s32)(local_0->local_2 * local_1), 255);
        break;
    }
    func_80101970(param_0);
    func_80101808(param_0, func_801015D0);
}

void func_80800778_chfactorylight(Actor *param_0, u32 *param_1)
{
    u32 local_0;

    switch (*(u32 *)((u8 *)param_0 + 0x6C) & 0x1FF) {
        case 0: local_0 = 0xFFFF2000; break;
        case 1: local_0 = 0x20FF0000; break;
        case 2: local_0 = 0xFF202000; break;
        case 3: local_0 = 0x0096FF00; break;
        case 4: local_0 = 0x20FFFF00; break;
        case 5: local_0 = 0xFF802000; break;
        case 6: local_0 = 0xFF60FF00; break;
        case 7: local_0 = 0xFFFFFF00; break;
        default: local_0 = 0xFFFF2000; break;
    }
    param_1[0] = (local_0 & 0xFF000000) >> 24; param_1[1] = (local_0 & 0x00FF0000) >> 16; param_1[2] = (local_0 & 0x0000FF00) >> 8;
}

void func_80800830_chfactorylight(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], 100.0f);
    func_800EE7F8(local_1, param_0->position);
    func_800EF1B8(local_1, param_0->rotation[1], -200.0f);
    if (func_800BEF00(local_0, local_1, local_2, param_0->unk14)) {
        func_800EE7F8(param_0->position, local_1);
        func_800EF1B8(param_0->position, param_0->rotation[1], param_0->scale * 5.0f);
        func_80103014(param_0);
    }
}

void func_808008E4_chfactorylight(param_0) Actor *param_0;
{
    FactoryLights50 *local_0;
    f32 local_2;
    f32 local_1[3];
    f32 local_4;
    s32 local_3;
    s32 local_5;
    local_0 = (FactoryLights50 *)func_80100094(param_0, 0);
    local_5 = param_0->unk74_7 - 0x32;
    if (local_5 < 0 || local_5 >= 8) local_5 = 0;
    param_0->unk6C_0 = local_5;
    *(f32 *)&param_0->actorData[7] = func_800DC128(200, 300);
    func_80800778_chfactorylight(param_0, local_0->local_2);
    for (local_3 = 0; local_3 != 2; local_3++) {
        local_0->local_0[local_3] = func_800C8A98();
        local_4 = local_3 * 180.0f;
        local_0->local_1[local_3] = local_4;
        func_800C8E84(local_0->local_0[local_3], local_0->local_2);
        func_800EEC30(local_1, local_4, param_0->rotation[1] + 90.0f, param_0->scale * 500.0f);
        func_800EF04C(local_1, param_0->position);
        func_800EF1B8(local_1, param_0->rotation[1], param_0->scale * 300.0f);
        func_800C8CB8(local_0->local_0[local_3], local_1);
        local_2 = param_0->scale;
        func_800C8E54(local_0->local_0[local_3], local_2 * 350.0f, local_2 * 800.0f);
    }
    if (func_800EA05C() == 0x10D) {
        if (func_800DA298(0x1BD)) {
            func_80101FDC(param_0, 1);
            func_800C8FE0(local_0->local_0[0], 1);
            func_800C8FE0(local_0->local_0[1], 1);
            *(f32 *)&param_0->actorData[3] = 1.3f;
        } else {
            func_80101FDC(param_0, 2);
            func_800C8FE0(local_0->local_0[0], 0);
            func_800C8FE0(local_0->local_0[1], 0);
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/factory/light.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800B90_chfactorylight -> int[] */
int D_80800B90_chfactorylight[20] = { 0x2A303A7, 0x7430001, 0x0, (u32)func_80800038_chfactorylight, (u32)func_80105834, (u32)func_808006B8_chfactorylight, 0x0, 0x0, 0x0, 0x5C00, (u32)func_80800408_chfactorylight, 0x0, 0x1C0000, (u32)func_8080000C_chfactorylight, (u32)func_80107C2C, -0x7FFFDBFE, (u32)func_8080057C_chfactorylight, 0x0, 0x0, 0x0 };
