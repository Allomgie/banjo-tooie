#include "common.h"

extern u8 D_8080119C_chpufferfish[];
extern u8 D_808011D0_chpufferfish[];
extern u8 D_80801288_chpufferfish[];
extern u8 D_80801204_chpufferfish[];
extern u8 D_80801238_chpufferfish[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_80101CDC(Actor *, f32);
extern int func_80107070(void *, s32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void func_800BA994(s32, s32, s32, s32, s32, s32, s32);
typedef struct { u8 local_0[0x64]; u32 local_1 : 2; u32 local_2 : 1; u32 local_3 : 29; } PufferFishFlags49_80800040_chpufferfish;
typedef struct { u32 a : 2; u32 f : 1; u32 rest : 29; } PF64;
typedef Actor PufferFishFlags49_80800518_chpufferfish;
extern u8 D_80801298_chpufferfish[];
extern f32 func_80101F24(Actor *);
extern f32 func_800DC0C0(void);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800D90A4(f32 *);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
typedef struct { u8 pad0[0x70]; u32 unk70_25:7; u32 pad70_10:15; u32 unk70_4:6; u32 pad70_0:4; } PufferBits;
typedef struct { u8 pad0[4]; f32 unk4; u8 pad8[6]; s16 unkE; } PufferArea;
typedef struct { u8 pad0[0xC]; f32 unkC; } PufferData;
extern PufferArea *func_800CC63C(s32, s32);
extern void func_80102950(Actor *, f32);
extern void func_8010CE28(Actor *, f32 *);
extern void func_80102924(Actor *, f32);
extern f32 func_800136E4(f32);
extern s32 _subaddieDll_entrypoint_11(Actor *, s32, s32);
extern f32 func_80102D78(Actor *, PufferArea *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void func_80102C58(Actor *, f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 _subaddiejoy_entrypoint_3(void);
extern f32 func_800F1828(f32 *, f32 *);
void func_8080086C_chpufferfish();
void func_80800518_chpufferfish();
void func_80800AB0_chpufferfish(Actor *param_0, s32 param_1, f32 param_2, f32 param_3);
void func_80800E20_chpufferfish();
void func_80800F30_chpufferfish();

void func_80800000_chpufferfish(u8 *param_0)
{
    if (_subaddieDll_entrypoint_1() == 0)
    {
        func_800FFAB0(param_0);
        return;
    }
    (*(f32 *)((s8 *)(param_0) + (0x34))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x38)));
}

void func_80800274_chpufferfish();

void func_80800040_chpufferfish(Actor *param_0)
{
    func_80800518_chpufferfish();
    func_8010D690(param_0);
    switch (param_0->unk79_4) {
    case 0:
        if (((PufferFishFlags49_80800040_chpufferfish *)param_0)->local_2) {
            func_80800F30_chpufferfish(param_0);
            break;
        }
        func_80800AB0_chpufferfish(param_0, 1, 300.0f, 300.0f);
        func_80800E20_chpufferfish(param_0);
        if (func_8010BA80(param_0, 0x26, 0x10)) param_0->unk54 += 10.0f;
        if (func_8010C500(param_0) && param_0->unk58 == 0.0f) {
            if (func_8008FCC8(param_0->unk0) == 0x14) func_80800274_chpufferfish(param_0, 2);
            else func_80800274_chpufferfish(param_0, 1);
        }
        break;
    case 1:
        func_80800AB0_chpufferfish(param_0, 2, 600.0f, 600.0f);
        func_80800E20_chpufferfish(param_0);
        if (func_8010BA80(param_0, 0x26, 0x10)) param_0->unk54 += 10.0f;
        if (!func_8010C500(param_0)) func_80800274_chpufferfish(param_0, 0);
        break;
    case 2:
        func_80800AB0_chpufferfish(param_0, 4, 450.0f, 550.0f);
        func_80800E20_chpufferfish(param_0);
        if (func_8010BA80(param_0, 0x26, 0x10)) param_0->unk54 += 10.0f;
        if ((!func_8010C500(param_0) || func_8008FCC8(param_0->unk0) != 0x14) && param_0->unk58 == 0.0f)
            func_80800274_chpufferfish(param_0, 0);
        break;
    case 3:
    case 4:
        break;
    }
}

void func_80800274_chpufferfish(Actor *param_0, s32 param_1)
{
    f32 *local_0;
    switch (param_1) {
    case 0: param_0->unk58 = 5.0f; break;
    case 1: break;
    case 3:
        func_8080086C_chpufferfish(param_0, 2);
        func_80101CDC(param_0, 0.5f);
        func_8010A570(param_0);
        break;
    case 4:
        local_0 = param_0->position;
        _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80801288_chpufferfish);
        func_800BBCB8(local_0, local_0, param_0->scale, 10, D_80801238_chpufferfish);
        func_800BBCB8(local_0, local_0, param_0->scale, 2, D_8080119C_chpufferfish);
        func_800BBCB8(local_0, local_0, param_0->scale, 16, D_808011D0_chpufferfish);
        func_800BBCB8(local_0, local_0, param_0->scale, 6, D_80801204_chpufferfish);
        if (!func_80107070(param_0, 3)) func_800FFAB0(param_0);
        break;
    }
    param_0->unk79_4 = param_1;
}

s32 func_808003C8_chpufferfish(u8 *param_0, s32 param_1, s32 param_2) {
    u32 local_0;

    switch (param_1) {                                 
    case 0x3E:
        local_0 = *(u32 *)((s8 *)param_0 + 0x70);
        func_80102924(param_0, func_80102D78(param_0, func_800CC63C(
            (local_0 >> 0x19) - 1,
            (s32)((u32)(local_0 << 0x16) >> 0x1A) - 1)));
        func_80800274_chpufferfish(param_0, 2);
        return 1;
    case 0x40:
        func_80800274_chpufferfish(param_0, 3);
        return 1;
    case 0x8F:
        if ((param_2 == 1) || ((param_2 != 2) && (param_2 != 3) && (param_2 == 4))) {
            func_80800274_chpufferfish(param_0, 0);
            func_8080086C_chpufferfish(param_0, 1);
        }
        return 1;
    case 0x1:
        func_80800274_chpufferfish(param_0, 0);
        if (((s32)((u32)((u16)*(u16 *)((s8 *)param_0 + 0x72)) >> 0xA)) != 1) {
            func_8080086C_chpufferfish(param_0, 4);
        }
        (*(f32 *)((s8 *)(param_0) + (0x2C))) = 2.0f;
        return 1;
    case 0x2:
        func_80800274_chpufferfish(param_0, 0);
        func_80107070(param_0, 1);
        return 1;
    default:
        return 0;
    }
}

void func_8080093C_chpufferfish();

void func_80800518_chpufferfish(param_0) Actor *param_0;
{
    f32 local_0;
    f32 local_1;

    switch (param_0->unk70_10) {
    case 1:
        if (func_80101F24(param_0) > 0.1f && func_80101F24(param_0) < 0.7f && func_800DC0C0() < 0.5f) {
            func_8080093C_chpufferfish(param_0, 1);
        }
        if (((PF64 *)((u8 *)param_0 + 0x64))->f) {
            if (func_800D90A4((f32 *)&param_0->actorData[5]) && _subaddiejoy_entrypoint_6(param_0, 1)) {
                func_8080086C_chpufferfish(param_0, 2);
            }
        } else if (func_800D90A4(&param_0->unk58) && func_8010C9B0(param_0->position, 500)) {
            func_8080086C_chpufferfish(param_0, 2);
        }
        break;
    case 3:
        if (func_80101F24(param_0) > 0.1f && func_80101F24(param_0) < 0.7f && func_800DC0C0() < 0.5f) {
            func_8080093C_chpufferfish(param_0, 1);
        }
        if (((PF64 *)((u8 *)param_0 + 0x64))->f) {
            if (_subaddiejoy_entrypoint_6(param_0, 0)) {
                func_8080086C_chpufferfish(param_0, 4);
            }
        } else if (func_80101E14(param_0, 0.999f)) {
            func_8080086C_chpufferfish(param_0, 4);
        }
        break;
    case 2:
        local_0 = func_80101F24(param_0);
        param_0->scale = func_800F1214(local_0, *(f32 *)&param_0->actorData[7],
                                    *(f32 *)&param_0->actorData[7] + *(f32 *)&param_0->actorData[7]);
        if (func_80101DDC(param_0)) {
            _subaddieaudioloop_entrypoint_2(param_0);
            if (param_0->unk79_4 == 3) {
                func_80800274_chpufferfish(param_0, 4);
            } else {
                func_8080086C_chpufferfish(param_0, 3);
            }
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801298_chpufferfish);
            _subaddieaudioloop_entrypoint_0(param_0, func_800F1214(local_0, 0.8f, 1.4f));
        }
        break;
    case 4:
        local_1 = func_80101F24(param_0);
        param_0->scale = func_800F1214(local_1, *(f32 *)&param_0->actorData[7],
                                    *(f32 *)&param_0->actorData[7] + *(f32 *)&param_0->actorData[7]);
        if (func_80101E14(param_0, 0.1f)) {
            _subaddieaudioloop_entrypoint_2(param_0);
            func_8080086C_chpufferfish(param_0, 1);
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801298_chpufferfish);
            _subaddieaudioloop_entrypoint_0(param_0, func_800F1214(local_1, 0.8f, 1.4f));
        }
        func_8080093C_chpufferfish(param_0, 1);
        break;
    }
}

void func_8080086C_chpufferfish(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;

    local_0 = param_0->unk70_10;
    func_80102424(param_0, param_1);
    switch (param_1) {
    case 1:
        param_0->scale = ((f32 *)param_0->actorData)[7];
        break;
    case 2:
        if (local_0 == 1) func_80101EE4(param_0, 0.0f);
        break;
    case 3:
        param_0->scale = 2.0f * ((f32 *)param_0->actorData)[7];
        break;
    case 4:
        if (local_0 == 3) func_80101EE4(param_0, 0.999f);
        param_0->unk58 = 5.0f;
        ((f32 *)param_0->actorData)[5] = 2.0f;
        break;
    }
}

void func_8080093C_chpufferfish(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    s32 local_1;
    f32 local_4;
    f32 local_3[1];
    f32 local_2[1];
    if (_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_0)) {
        local_2[0] = func_800DC178(-20.0f, 20.0f);
        local_3[0] = func_800DC178(-20.0f, 20.0f);

        func_800EFA4C(local_0, local_0[0] + local_2[0], local_0[1] + local_3[0], local_0[2] + func_800DC178(-20.0f, 20.0f));
        local_1 = _fxairbub_entrypoint_1(local_0, 1.0f, local_0[1] + 1000.0f, param_0->scale);
        func_800BA994(local_1, (s16)(s32)param_0->rotation[0], (s16)(s32)(param_0->rotation[1] - 35.0f),
            (s16)(s32)(*(f32 *)((u8 *)param_0 + 0x24) * 1.5f), (s16)(s32)param_0->rotation[0],
            (s32)(param_0->rotation[1] + 35.0f), (s32)(*(f32 *)((u8 *)param_0 + 0x24) + *(f32 *)((u8 *)param_0 + 0x24)));
        func_800BA22C(local_1, param_1);
    }
}

void func_80800AB0_chpufferfish(Actor *param_0, s32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0[3];
    s32 local_1;
    PufferArea *local_2;

    local_2 = func_800CC63C(((PufferBits *)param_0)->unk70_25 - 1, ((PufferBits *)param_0)->unk70_4 - 1);
    if (local_2->unk4 + local_2->unkE <= param_0->position[1]) {
        local_1 = 1;
        func_80102950(param_0, 355.0f);
    } else if (param_0->position[1] <= local_2->unk4 - local_2->unkE) {
        local_1 = 1;
        func_80102950(param_0, 5.0f);
    } else {
        local_1 = 0;
    }
    if (param_1 & 6) {
        func_8010CE28(param_0, local_0);
        if (param_1 & 2) {
            func_80102924(param_0, local_0[1]);
        } else {
            func_80102924(param_0, func_800136E4(local_0[1] - 180.0f));
        }
        local_0[0] = func_800136E4(-local_0[0]);
        if (25.0f < local_0[0] && local_0[0] < 180.0f) {
            local_0[0] = 25.0f;
        } else if (local_0[0] < 335.0f && 180.0f < local_0[0]) {
            local_0[0] = 335.0f;
        }
        func_80102950(param_0, local_0[0]);
    }
    if (func_800D90A4((f32 *)&param_0->actorData[2])) {
        ((f32 *)param_0->actorData)[2] = ((f32 *)param_0->actorData)[4] = func_800DC178(2.0f, 4.0f);
        ((f32 *)param_0->actorData)[0] = func_800DC178(param_2, param_3);
        if (!local_1) {
            func_80102950(param_0, func_800DC178(-8.333333f, 8.333333f));
        }
        if (param_1 & 5) {
            func_80102924(param_0, func_800DC178(-35.0f, 35.0f) + param_0->rotation[1]);
        }
    }
    if (!_subaddieDll_entrypoint_11(param_0, param_0->unk54, param_0->scale * 3.0f * ((PufferData *)param_0->actorData)->unkC)) {
        func_80102924(param_0, func_80102D78(param_0, local_2));
        ((f32 *)param_0->actorData)[2] = ((f32 *)param_0->actorData)[4] = func_800DC178(2.0f, 4.0f);
    }
    ((f32 *)param_0->actorData)[1] = func_800136E4(func_800F10B4(func_800F1DCC(param_0->rotation[1], param_0->unk54), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(param_0, 0.05f, 0.05f, 4.0f);
    func_80102C58(param_0, 0.05f, 0.01f, 0.5f);
    param_0->rotation[2] = func_800F1FF0(param_0->rotation[2], ((f32 *)param_0->actorData)[1], 0.01f, 0.005f, 0.1f);
}

void func_80800E20_chpufferfish(param_0) Actor *param_0;
{
    f32 local_0;
    f32 local_1;
    local_0 = func_800F10B4(((f32 *)param_0->actorData)[2], ((f32 *)param_0->actorData)[4], 0.0f, 0.0f, 1.0f);
    if (local_0 < 0.2f) {
        local_1 = func_800F10B4(local_0, 0.0f, 0.2f, 0.0f, ((f32 *)param_0->actorData)[0]);
    } else if (local_0 < 0.5f) {
        local_1 = func_800F10B4(local_0, 0.2f, 0.5f, ((f32 *)param_0->actorData)[0], ((f32 *)param_0->actorData)[0] * 0.75f);
    } else {
        local_1 = func_800F10B4(local_0, 0.5f, 1.0f, ((f32 *)param_0->actorData)[0] * 0.75f, 0.0f);
    }
    ((f32 *)param_0->actorData)[3] = func_800F15F8(((f32 *)param_0->actorData)[3], local_1, 4.0f);
}

void func_80800F30_chpufferfish(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1;
    local_1 = _subaddiejoy_entrypoint_3() * 300.0f;
    func_8010D254(local_0);
    param_0->unk50 = func_800F1828(param_0->position, local_0);
    if (param_0->unk50 > 30.0f && param_0->unk50 <= 180.0f) param_0->unk50 = 30.0f;
    else if (param_0->unk50 > 180.0f && param_0->unk50 <= 330.0f) param_0->unk50 = 330.0f;
    if (((f32 *)param_0->actorData)[3] <= local_1) ((f32 *)param_0->actorData)[3] = local_1;
    else {
        ((f32 *)param_0->actorData)[3] -= ((f32 *)param_0->actorData)[3] * 0.02f;
        if (((f32 *)param_0->actorData)[3] < 30.0f) ((f32 *)param_0->actorData)[3] = 0.0f;
    }
    ((f32 *)param_0->actorData)[0] = ((f32 *)param_0->actorData)[3];
    ((f32 *)param_0->actorData)[1] = func_800136E4(func_800F10B4(func_800F1DCC(param_0->rotation[1], param_0->unk54), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(param_0, 0.5f, 0.5, 5.0f);
    func_80102C58(param_0, 0.5f, 0.5, 5.0f);
    param_0->rotation[2] = func_800F1FF0(param_0->rotation[2], ((f32 *)param_0->actorData)[1], 0.01f, 0.005f, 0.1f);
    func_8010BA80(param_0, 0x200006, 0x20);
}

int chpufferfish_entrypoint_0()
{
    extern int D_808012A8_chpufferfish;
    return &D_808012A8_chpufferfish;
}
