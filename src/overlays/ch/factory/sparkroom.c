#include "common.h"

extern void *func_80100094(Actor *, u32);
typedef struct SparkRoomColor { f32 local_0[3]; } SparkRoomColor;
extern SparkRoomColor D_80801094_chfactorysparkroom;
extern f32 D_808010A8_chfactorysparkroom[4][3];
extern u8 D_808010A0_chfactorysparkroom[];
extern f32 D_808010D8_chfactorysparkroom[3];
extern void func_800C8B84();
typedef struct { f32 local_0; f32 local_1; u8 pad_0[0x14]; s32 local_2; } FactorySpark;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC090(void);
extern void *func_800D7520(void *);
extern void func_800C7A68(void *, f32, f32 *);
extern s32 func_800C8A98(void);
extern void func_800C8F64(s32, s32);
extern void func_800C8FE0(s32, s32);
extern void func_800C8E84(s32, void *);
extern void func_800C8CB8(s32, f32 *);
extern void func_800C8D4C(s32, void *);
typedef struct { u32 a; u32 b; u32 c; } FsrTbl;
typedef struct { f32 f0; f32 f4; f32 f8; f32 fC; f32 v10[2]; void *p18; s32 h1C; } FsrRec;
extern FsrTbl D_808010FC_chfactorysparkroom;
typedef struct { FactorySpark local_0[16]; s32 local_1; s32 local_2; s32 local_3; s32 local_4; } FactorySparkPool;
extern int D_80801108_chfactorysparkroom[];
extern void func_8010A63C();
extern void func_80108B04();
extern u8 D_80801150_chfactorysparkroom[];
extern s32 _chswitch_entrypoint_10(Actor *, s32, s32);
extern int D_8080115C_chfactorysparkroom[];
typedef struct { f32 v[3]; } SparkVec;
typedef struct { f32 unk0; f32 unk4; f32 unk8; f32 unkC; u8 pad10[8]; s32 unk18; s32 unk1C; } Spark;
typedef struct { u8 pad0[0x70]; u32 pad70_1:31; u32 unk70_0:1; } SparkBits;
extern SparkVec D_8080107C_chfactorysparkroom;
extern SparkVec D_80801088_chfactorysparkroom;
extern f32 D_80801060_chfactorysparkroom[];
extern f32 D_80801070_chfactorysparkroom[];
extern s32 func_800D90A4(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800DC0C0(void);
extern void func_800F3214(f32 *, SparkVec *, SparkVec *, f32);
extern u8 _subaddieaudioloop_entrypoint_7();
extern s32 func_800F581C(s32);
extern s32 func_800F55FC(s32);
extern s32 func_800F6C5C(s32);
extern void func_800F796C(s32, s32);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
extern void func_80018820(s32, f32, f32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
typedef struct { s32 color[3]; } SparkRoomBlendColor;
extern SparkRoomBlendColor D_808010E4_chfactorysparkroom;
extern SparkRoomBlendColor D_808010F0_chfactorysparkroom;
typedef struct { f32 local_0; f32 local_1; f32 local_2; f32 local_3; u8 pad_0[8]; s32 local_4; u8 pad_1[4]; } SparkDraw241;
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_80013970(f32);
extern void *func_800D674C(s32);
extern s32 func_800DE498(void *, f32 *, f32 *, f32, f32 *, void *);
void func_80800DC8_chfactorysparkroom();
void func_808006D0_chfactorysparkroom(Actor *param_0, f32 param_1);
void func_80800838_chfactorysparkroom();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chfactorysparkroom(), func_80800838_chfactorysparkroom(), func_80800D30_chfactorysparkroom();

void func_80800000_chfactorysparkroom(param_0) Actor *param_0;
{
    s32 local_0[16];
    u32 local_2;
    s32 *local_3;
    Vec3f local_1;
    u8 *local_4;
    u8 *local_5;

    local_4 = func_80100094(param_0, 0);
    param_0->unk6C_0 = _gccubesearch_entrypoint_9(0x299, local_0, 0x10);
    local_2 = 0;
    local_3 = local_0;
    local_5 = local_4;
    while (local_2 < param_0->unk6C_0) {
        *(f32 *)(local_5 + 0x10) = (f32)_gspropctrl_entrypoint_8(*local_3) * 10.0f;
        *(f32 *)(local_5 + 0x14) = (f32)_gspropctrl_entrypoint_8(*local_3) * 20.0f;
        _gspropctrl_entrypoint_11(*local_3, local_1.f);
        *(s32 *)(local_5 + 0x18) = _glsplinefind_entrypoint_3(local_1.f);
        local_2++;
        local_3++;
        local_5 += 0x20;
    }
    ((u8 *)param_0)[0x50] = _subaddieaudioloop_entrypoint_7(((u8 *)param_0)[0x50],
        param_0->position, 0, ((u8 *) D_80801070_chfactorysparkroom), *(u32 *)((u8 *)param_0 + 0x70) & 1);
}

void func_80800BE0_chfactorysparkroom();

void func_80800B60_chfactorysparkroom();

void func_808007E0_chfactorysparkroom();

void func_808005E0_chfactorysparkroom();

void func_8080013C_chfactorysparkroom(param_0) Actor *param_0;
{
    f32 local_0[3];
    u32 local_1;
    Spark *local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6;
    f32 local_7;
    SparkVec local_8;
    SparkVec local_9;
    f32 local_10[3];
    f32 local_11[3];
    Spark *data;

    local_3 = 10000000.0f;
    data = func_80100094(param_0, 0);
    for (local_1 = 0, local_2 = data; local_1 < param_0->unk6C_0; local_1++, local_2++) {
        if (local_2->unk4 == 0.0f) {
            if (func_800D90A4(&local_2->unk0) && (s32)param_0->actorData[7] < 4) {
                func_80800BE0_chfactorysparkroom(param_0, local_1);
            }
        } else if (func_800D90A4(&local_2->unk4)) {
            func_80800B60_chfactorysparkroom(param_0, local_1);
        } else {
            local_6 = func_800F10B4(local_2->unk4, local_2->unk0, 0.0f, local_2->unk8, local_2->unkC);
            local_8 = D_8080107C_chfactorysparkroom;
            local_9 = D_80801088_chfactorysparkroom;
            func_800F5A00(func_800F54E4(), local_5);
            func_800C7A68(func_800D7520(local_2->unk18), local_6, local_4);
            if ((local_7 = func_800EFC7C(local_5, local_4)) < local_3) {
                local_3 = local_7;
                func_800EE7F8(local_0, local_4);
            }
            local_4[1] += 50.0f;
            func_800F3214(local_10, &local_8, &local_9, func_800DC0C0() * 0.2f + 0.8f);
            func_800C8E84(local_2->unk1C, local_10);
            func_800C8CB8(local_2->unk1C, local_4);
        }
    }
    if (local_3 < 10000000.0f) {
        *(u8 *)&param_0->unk50 = _subaddieaudioloop_entrypoint_7(*(u8 *)&param_0->unk50, local_0, 1, D_80801060_chfactorysparkroom, ((SparkBits *)param_0)->unk70_0);
    } else {
        *(u8 *)&param_0->unk50 = _subaddieaudioloop_entrypoint_7(*(u8 *)&param_0->unk50, local_0, 0, D_80801060_chfactorysparkroom, ((SparkBits *)param_0)->unk70_0);
    }
    if (param_0->unk54 == 0.0f) {
        if ((func_800F581C(func_800F54E4()) & 0x8000000) || (func_800F55FC(func_800F54E4()) & 0x8000000)) {
            if (func_800F6C5C(func_800F54E4())) {
                func_800F5A00(func_800F54E4(), param_0->position);
                func_800F796C(func_800F54E4(), 3);
                _chelectricfence_entrypoint_1(param_0, param_0->position);
                func_80018820(0, 5.0f, param_0->unk74_7 / 10.0f);
                param_0->unk54 = param_0->unk74_7 / 10.0f;
                func_800EE7F8(local_11, param_0->position);
                local_11[1] += 500.0f;
                func_808005E0_chfactorysparkroom(param_0, local_11);
            }
        }
    } else if (func_800D90A4(&param_0->unk54)) {
        func_808007E0_chfactorysparkroom(param_0);
        _subaddieaudioloop_entrypoint_2(param_0);
    } else {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801070_chfactorysparkroom);
        if (param_0->unk54 < param_0->unk74_7 / 10.0f * 0.3f) {
            func_808006D0_chfactorysparkroom(param_0, func_800F10B4(param_0->unk54, 0.0f, param_0->unk74_7 / 10.0f * 0.3f, 0.0f, 1.0f));
        }
    }
}

void func_808005E0_chfactorysparkroom(Actor *param_0, f32 *param_1)
{
    s32 local_2;
    SparkRoomColor local_0 = D_80801094_chfactorysparkroom;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    func_800EE7F8(D_808010D8_chfactorysparkroom, param_1);
    for (local_2 = 0; local_2 < 4; local_2++) {
        *(s32 *)(local_1 + 0x200 + local_2 * 4) = func_800C8A98();
        func_800C8CB8(*(s32 *)(local_1 + 0x200 + local_2 * 4), D_808010A8_chfactorysparkroom[local_2]);
        func_800C8D4C(*(s32 *)(local_1 + 0x200 + local_2 * 4), D_808010A0_chfactorysparkroom);
        func_800C8F64(*(s32 *)(local_1 + 0x200 + local_2 * 4), 3);
        func_800C8FE0(*(s32 *)(local_1 + 0x200 + local_2 * 4), 3);
        func_800C8E84(*(s32 *)(local_1 + 0x200 + local_2 * 4), local_0.local_0);
    }
}

void func_808006D0_chfactorysparkroom(Actor *param_0, f32 param_1)
{
    SparkRoomBlendColor local_0 = D_808010E4_chfactorysparkroom;
    SparkRoomBlendColor local_1 = D_808010F0_chfactorysparkroom;
    u8 *local_3;
    SparkRoomBlendColor local_2;
    s32 local_4;
    local_3 = (u8 *)func_80100094(param_0, 0);
    if (param_1 > 0.5f) param_1 = func_800DC0C0() * 0.2f + 0.8f;
    else param_1 += param_1;
    func_800F3214(&local_2, &local_0, &local_1, param_1);
    for (local_4 = 0; local_4 < 4; local_4++) {
        func_800C8E84(((s32 *)(local_3 + 0x200))[local_4], &local_2);
    }
}

void func_808007E0_chfactorysparkroom(s32 param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    s32 i;
    for (i = 0; i < 4; i++) {
        func_800C8B84(((s32 *)(local_0 + 0x200))[i]);
        ((s32 *)(local_0 + 0x200))[i] = 0;
    }
}

void func_80800838_chfactorysparkroom(param_0, param_1) Actor *param_0; void *param_1;
{
    SparkDraw241 *local_0;
    f32 local_1;
    Vec3f local_2;
    Vec3f local_3;
    u32 local_4;
    void *local_5;
    Vec3f local_7;
    Vec3f local_8;
    u32 local_9;
    f32 local_11;

    local_0 = func_80100094(param_0, 0);
    for (local_4 = 0; local_4 < param_0->unk6C_0; local_4++) {
        if (local_0[local_4].local_1 > 0.0f) {
            local_1 = func_800F10B4(local_0[local_4].local_1, local_0[local_4].local_0, 0.0f, local_0[local_4].local_2, local_0[local_4].local_3);
            func_800C7A68(func_800D7520(local_0[local_4].local_4), local_1, local_2.f);
            func_800E3980(local_3.f);
            func_800F1E6C(local_2.f, local_3.f, &param_0->rotation[1]);
            param_0->scale = func_80013970(local_1 * 180.0f);
            if (param_0->scale > 0.5f) {
                param_0->scale = func_800DC0C0() * 0.2f + 0.8f;
            } else {
                param_0->scale += param_0->scale;
            }
            local_3.pos.x = -90.0f;
            local_3.pos.y = param_0->rotation[1] - 90.0f;
            local_3.pos.z = 0.0f;
            func_800DF830(1);
            func_800DF744(1, func_800DC128(1, 5));
            func_800DE498(param_1, local_2.f, local_3.f, param_0->scale, NULL,
                         func_8010347C(param_0->unk0));
        }
    }
    if ((param_0->unk74_7 / 10.0f) * 0.3f < param_0->unk54) {
        local_5 = func_800D674C(0x6B9);
        for (local_4 = 0; local_4 < 10; local_4++) {
            local_9 = func_800F54E4();
            func_800F5A2C(local_9, local_4, local_7.f);
            func_800F1E6C(param_0->position, local_7.f, &local_8.pos.y);
            local_8.pos.x = func_800F1828(local_7.f, param_0->position);
            local_8.pos.z = 0.0f;
            local_8.pos.y -= 90.0f;
            local_11 = func_800EEAD4(param_0->position, local_7.f) / 100.0f;
            func_800DF830(1);
            func_800DF744(1, func_800DC128(1, 5));
            func_800DE498(param_1, param_0->position, local_8.f, local_11, NULL, local_5);
        }
    }
}

void func_80800B60_chfactorysparkroom(Actor *param_0, s32 param_1)
{
    FactorySpark *local_0;
    local_0 = func_80100094(param_0, 0);
    local_0[param_1].local_0 = func_800DC178(1.0f, 3.0f);
    local_0[param_1].local_1 = 0.0f;
    func_800C8B84(local_0[param_1].local_2);
    local_0[param_1].local_2 = 0;
    param_0->actorData[7]--;
}

void func_80800BE0_chfactorysparkroom(u8 *param_0, s32 param_1)
{
    FsrTbl local_a;
    f32 local_out[3];
    FsrRec *obj;

    local_a = D_808010FC_chfactorysparkroom;
    obj = func_80100094(param_0, 0);
    obj[param_1].f4 = func_800DC178(4.0f, 5.0f);
    obj[param_1].f0 = obj[param_1].f4;
    if (func_800DC090() & 1) {
        obj[param_1].f8 = 0.0f;
        obj[param_1].fC = 1.0f;
    } else {
        obj[param_1].f8 = 1.0f;
        obj[param_1].fC = 0.0f;
    }
    func_800C7A68(func_800D7520(obj[param_1].p18), obj[param_1].f8, local_out);
    local_out[1] = local_out[1] + 50.0f;
    if (obj[param_1].h1C == 0) {
        obj[param_1].h1C = func_800C8A98();
        func_800C8F64(obj[param_1].h1C, 3);
    }
    func_800C8FE0(obj[param_1].h1C, 1);
    func_800C8E84(obj[param_1].h1C, &local_a);
    func_800C8CB8(obj[param_1].h1C, local_out);
    func_800C8D4C(obj[param_1].h1C, obj[param_1].v10);
    *(s32 *)(param_0 + 0x34) = *(s32 *)(param_0 + 0x34) + 1;
}

void func_80800D30_chfactorysparkroom(param_0) u8 *param_0; {
    u32 local_0;

    local_0 = 0;
    if ((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF) {
        do {
            _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(param_0) + (0x50))));
            local_0 += 1;
            (*(u8 *)((s8 *)(param_0) + (0x50))) = 0U;
        } while (local_0 < (u32) ((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF));
    }
}

int func_80800D90_chfactorysparkroom(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0x95)
  {
    func_80800DC8_chfactorysparkroom(param_0);
    return 1;
  }
  return 0;
}

void func_80800DC8_chfactorysparkroom(param_0) Actor *param_0;
{
    FactorySparkPool *local_0;
    u32 local_1;

    local_0 = func_80100094(param_0, 0);
    param_0->actorData[7] = 0;
    param_0->unk54 = 0.0f;
    for (local_1 = 0; local_1 < param_0->unk6C_0; local_1++) {
        local_0->local_0[local_1].local_2 = 0;
        local_0->local_0[local_1].local_0 = func_800DC178(0.0f, 3.0f);
        local_0->local_0[local_1].local_1 = 0.0f;
    }
    local_0->local_2 = 0;
    local_0->local_3 = 0;
    local_0->local_4 = 0;
    local_0->local_1 = 0;
}

int *chfactorysparkroom_entrypoint_0()
{
    return &D_80801108_chfactorysparkroom;
}

s32 func_80800E94_chfactorysparkroom(s32 param_0) {
    _subaddiefade_entrypoint_14();
    func_8010A63C(param_0);
    _chswitch_entrypoint_7(param_0, 0xA2F);
}

s32 func_80800EC8_chfactorysparkroom(Actor *param_0, s32 param_1, s32 param_2)
{
    Vec3f local_0;
    switch (param_1) {
    case 7:
        if (func_800DA298(0x1BD)) {
            if (!func_800DA298(0x1BC)) {
                func_800DA544(0xA04);
                _glcutDll_entrypoint_6(0x10D, 0x41);
                return 1;
            }
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1365, 7, param_0->position, 0xA3);
            func_800DA524(0x1BD);
            func_80108B04(param_0, 0);
            return 1;
        }
        if (!func_800DA298(0x1BD) && !param_0->unk74_30) {
            param_0->unk74_30 = 1;
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x133C, 7, param_0->position, 0xA3);
        }
        return 1;
    case 0x3D:
        local_0 = *(Vec3f *)D_80801150_chfactorysparkroom;
        func_80108528(0x47C, local_0.f, 0, &param_0);
        return 1;
    default: return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
}

int *chfactorysparkroom_entrypoint_1()
{
    return &D_8080115C_chfactorysparkroom;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/factory/sparkroom.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801108_chfactorysparkroom -> int[], D_8080115C_chfactorysparkroom -> int[] */
extern void _chswitch_entrypoint_6();
extern void func_80101870();
f32 D_80801060_chfactorysparkroom[4] = { 1.746733e-39f, 2.048407e-39f, 1.194184e-39f, 2.8101662e-38f };
f32 D_80801070_chfactorysparkroom[3] = { 1.746733e-39f, 2.059617e-39f, 0.0f };
SparkVec D_8080107C_chfactorysparkroom = { 0.0f, 0.0f, 0.0f };
SparkVec D_80801088_chfactorysparkroom = { 3.57e-43f, 3.57e-43f, 3.57e-43f };
SparkRoomColor D_80801094_chfactorysparkroom = { 3.57e-43f, 3.57e-43f, 3.57e-43f };
u8 D_808010A0_chfactorysparkroom[8] = { 0x44, 0x5A, 0xC0, 0x0, 0x44, 0xD4, 0x80, 0x0 };
f32 D_808010A8_chfactorysparkroom[4][3] = { 875.0f, 5e+02f, 875.0f, 875.0f, 5e+02f, -875.0f, -875.0f, 5e+02f, 875.0f, -875.0f, 5e+02f, -875.0f };
f32 D_808010D8_chfactorysparkroom[3] = { 0.0f, 0.0f, 0.0f };
SparkRoomBlendColor D_808010E4_chfactorysparkroom = { 0x0, 0x0, 0x0 };
SparkRoomBlendColor D_808010F0_chfactorysparkroom = { 0xFF, 0xFF, 0xFF };
FsrTbl D_808010FC_chfactorysparkroom = { 0xFF, 0xFF, 0xFF };
int D_80801108_chfactorysparkroom[18] = { 0x1580413, 0x6B90001, 0x0, (u32)func_8080013C_chfactorysparkroom, (u32)func_80105834, (u32)func_80800838_chfactorysparkroom, 0x0, 0x0, 0x0, 0x20400, (u32)func_80800D30_chfactorysparkroom, (u32)func_80108ED0, 0x2100000, (u32)func_80800000_chfactorysparkroom, (u32)func_80107C2C, -0x7FFFFC00, (u32)func_80800D90_chfactorysparkroom, 0x0 };
u8 D_80801150_chfactorysparkroom[12] = { 0xC5, 0x1C, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_8080115C_chfactorysparkroom[21] = { 0x34303ED, 0x8830001, -0x7FEE5DE0, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, (u32)func_80800E94_chfactorysparkroom, (u32)func_80107C2C, -0x7FF7D3EE, (u32)func_80800EC8_chfactorysparkroom, 0x0, 0x0, 0x0, 0x0 };
