#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800136E4(f32);
extern int D_80800930_chicekeydoor;
extern u8 D_80800920_chicekeydoor[];
extern void func_8010D5DC(void);
extern void func_8008F990(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800F5A00(s32, f32 *);
extern void func_800F8300(s32, s32, f32 *);
extern Prop *_gccubesearch_entrypoint_0(u32, Actor *);
extern void _gspropctrl_entrypoint_11(Prop *, f32 *);
extern s32 _glsplinefind_entrypoint_3(f32 *);
extern void *func_800D7520();
extern void func_800C7A68(void *, f32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern u8 D_80800978_chicekeydoor[];
s32 func_80800640_chicekeydoor();

void func_80800000_chicekeydoor(Actor *param_0)
{
    f32 *local_2;
    Actor *local_0;
    f32 local_1;

    switch (param_0->unk70_10) {
    case 1:
    case 8:
        break;
    case 2:
        if (func_8010C500(param_0)) {
            func_8008F8B0();
            func_8008F8D8(1);
            func_8008F904(func_8010D5DC, param_0->unk0);
            func_8008F938(1);
            func_8008F990((f32 *)param_0->actorData, 500.0f);
            func_80101FDC(param_0, 3);
        }
        break;
    case 3:
        func_800D1824(0x53);
        break;
    case 4:
        if (func_800D90A4(&param_0->unk58)) {
            func_80108B04(param_0, 0);
            param_0->unk58 = 5.0f;
            _capod_entrypoint_13(param_0->unk0, param_0->unk0, 0x1F, 0x10);
            func_800FC660(0xE);
            func_800D1804(0x53);
            func_80101FDC(param_0, 5);
        }
        func_800D1824(0x53);
        break;
    case 5:
        if (param_0->unk3C != NULL && func_80800640_chicekeydoor(param_0, func_80106790(param_0->unk3C))) {
            func_800C4140(0x7FFB5D6D, param_0->position, 0x04B000FA);
            param_0->unk58 = 1.0f;
            func_80101FDC(param_0, 6);
        }
        func_800D1824(0x53);
        break;
    case 6:
        if (param_0->unk3C != NULL) {
            local_0 = func_80106790(param_0->unk3C);
            if (func_800D90A4(&param_0->unk58)) {
                local_2 = param_0->position;
                func_800EFB24((f32 *)&local_0->actorData[4], local_0->position, param_0->position);
                param_0->unk58 = 4.0f;
                local_0->rotation[0] = 90.0f;
                func_800C4140(0x7FFB5C56, local_2, 0x04B000FA);
                func_80101FDC(param_0, 7);
            } else {
                local_0->rotation[0] = func_800F12D4(param_0->unk58, 1.0f, 0.0f, 0.0f, 90.0f);
            }
        }
        func_800D1824(0x53);
        break;
    case 7:
        if (func_800D90A4(&param_0->unk58)) {
            param_0->rotation[1] = -90.0f;
            func_800F82D4(func_800F54E4(), 0);
            func_800DA544(0x3E2);
            _subaddieaudioloop_entrypoint_2(param_0);
            func_800C4140(0x7FFB5CC7, param_0->position, 0x04B000FA);
            _subaddieDll_entrypoint_4(param_0, 0);
            func_80101FDC(param_0, 8);
        } else {
            local_1 = func_800F12D4(param_0->unk58, 4.0f, 0.0f, 0.0f, 1.0f);
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800920_chicekeydoor);
            param_0->rotation[1] = local_1 * -90.0f;
        }
        func_800D1824(0x53);
        break;
    }
}

s32 func_80800318_chicekeydoor(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    Prop *local_1;
    f32 local_2[3];
    Actor *local_3;

    switch (param_1) {
    case 0x32:
        func_800F5A00(func_800F54E4(), local_0);
        func_800EF1B8(local_0, ((f32 *)param_0->actorData)[3], 200.0f);
        func_800F8300(func_800F54E4(), 2, local_0);
        func_80101FDC(param_0, 4);
        param_0->unk58 = 1.0f;
        _subaddieDll_entrypoint_4(param_0, 1);
        break;
    case 0x95:
        if (func_800DA298(0x3E2)) {
            param_0->rotation[1] = -90.0f;
            func_80108B04(param_0, 1);
            func_80101FDC(param_0, 8);
        } else if (func_800D1A04(0x53)) {
            local_1 = _gccubesearch_entrypoint_0(0x299, param_0);
            _gspropctrl_entrypoint_11(local_1, (f32 *)param_0->actorData);
            ((f32 *)param_0->actorData)[3] = (f32)_gspropctrl_entrypoint_12(local_1);
            _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(0x511, param_0), local_2);
            ((f32 *)param_0->actorData)[7] = (f32)_glsplinefind_entrypoint_3(local_2);
            func_80101FDC(param_0, 2);
        } else {
            func_80103110(param_0, 0);
            func_80101FDC(param_0, 1);
        }
        break;
    case 0x3D:
        local_3 = func_80108528(0x513, param_0->position, 0, &param_0);
        local_3->unk3C = param_0->unk0;
        param_0->unk3C = local_3->unk0;
        switch (param_2) {
        case 0:
            func_800C7A68(func_800D7520((s32)((f32 *)param_0->actorData)[7]), 0.0f, local_3->position);
            local_3->scale = 0.1f;
            break;
        case 1:
            local_3->scale = 1.0f;
            break;
        }
        func_8010A570(local_3);
        local_3->unk64_16 = 0;
        return 1;
    }
    return 0;
}

void func_8080057C_chicekeydoor(Actor *param_0, s32 param_1)
{
    Actor *local_0;

    func_80101870(param_0, param_1);
    if (param_0->unk3C && param_0->unk7C_12) {
        local_0 = func_80106790(param_0->unk3C);
        local_0->unk64_16 = 1;
        if ((s32)param_0->unk70_10 >= 6) {
            _subaddieskeleton_entrypoint_1(param_0, 4, local_0->position);
            local_0->rotation[1] = func_800136E4(param_0->rotation[1] - 180.0f);
        }
        func_80101870(local_0, param_1);
        local_0->unk64_16 = 0;
    }
}

int chicekeydoor_entrypoint_0()
{
    return (int)&D_80800930_chicekeydoor;
}

s32 func_80800640_chicekeydoor(param_0, param_1) Actor *param_0; Actor *param_1;
{
    f32 local_2;
    f32 local_0;
    s32 local_1;

    local_0 = param_1->rotation[1];
    local_1 = func_800D90A4(&param_0->unk58);
    local_2 = func_800F10B4(param_0->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
    func_800C7A68(func_800D7520((s32)((f32 *)param_0->actorData)[7]), local_2, param_1->position);
    param_1->rotation[0] = 0.0f;
    if (local_2 < 0.9f) {
        func_800BBCB8(param_1->position, param_1->position, 1.0f, 1, D_80800978_chicekeydoor);
        param_1->rotation[1] = func_800136E4(func_800F12D4(local_2, 0.0f, 0.9f, 0.0f, 1260.0f));
    } else {
        param_1->rotation[1] = 180.0f;
    }
    if (local_2 < 0.5f) {
        param_1->scale = func_800F12D4(local_2, 0.0f, 0.5f, 0.1f, 1.0f);
    } else {
        param_1->scale = 1.0f;
    }
    if ((local_0 < 160.0f && param_1->rotation[1] >= 160.0f) ||
        (local_0 < 340.0f && param_1->rotation[1] >= 340.0f)) {
        func_800C4140(((u16)(u32)(func_80013970(local_2 * 180.0f) * 0.4f + 1227.600098f) << 21) + 0x1B5E64, param_1->position, 0x04B000FA);
    }
    return local_1;
}
