#include "common.h"

extern void *D_80800700_chfreezy;
typedef union { s32 local_0; Actor *local_1; } FreezyMessage1425;
extern void *func_80100094(Actor *, u32);
typedef struct FreezyFlags74 { u8 pad_0 : 7; u8 local_0 : 1; } FreezyFlags74;
typedef struct FreezyFlags78 { u32 pad_0 : 29; u32 local_0 : 1; u32 pad_1 : 2; } FreezyFlags78;
extern u8 D_80800748_chfreezy[];
extern void _chfreezy_entrypoint_2();
extern Actor *func_80106790(void *);
extern Actor *func_801084B0(s32, Actor **);
extern Actor *_chnewfreezy_entrypoint_0(void *, s32, s32, s32);
typedef struct { u8 unused[0x24]; u32 model : 10; u32 flags : 22; } FreezyMarkerView;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80103DFC(Actor *, f32 *);
extern f32 func_800EC708(void *);
extern void _sufreezy_entrypoint_1(void);
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 29; u32 active : 1; u32 pad_2 : 2; } FreezyLinkFlags;
extern Actor *_subaddielink_entrypoint_4(void *);
extern f32 func_800F15F8(f32, f32, f32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _fxtwinkle_entrypoint_1();
extern void func_800F18FC();
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9058(f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
void func_8080044C_chfreezy();
int func_808004B8_chfreezy();
s32 func_808006C0_chfreezy();
void func_80800538_chfreezy();

int chfreezy_entrypoint_0()
{
  return &D_80800700_chfreezy;
}

void func_8080000C_chfreezy(Actor *param_0)
{
    f32 local_0[3];
    _sufreezy_entrypoint_1();
    *(f32 *)((char *)param_0 + 0x38) = 0.2f;
    return;
}

void func_8080003C_chfreezy(u8 *param_0) {
    s32 local_0;
    s32 local_1;

    local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 1));
    local_1 = (u32)(param_0[0x79]) >> 4;
    func_8010A828(local_0, local_1);
}

void func_80800080_chfreezy(Actor *param_0)
{
    Actor *local_0;
    local_0 = _subaddielink_entrypoint_4((void *)func_80100094(param_0, 1));
    if (param_0->unk64_17) return;
    if (!local_0 || local_0->unk64_17) {
        func_808006C0_chfreezy(param_0);
        return;
    }
    param_0->scale = func_800F15F8(param_0->scale, param_0->unk50, (param_0->unk50 - param_0->scale) * 0.1f);
    if (!((FreezyLinkFlags *)local_0)->active) {
        func_808006C0_chfreezy(param_0);
        return;
    }
    _sudeflect_entrypoint_0(param_0->position, 0.0f, param_0->scale * 100.0f, 2);
    func_80800538_chfreezy(param_0);
    if (func_800D9078(&param_0->unk58)) {
        _sufreezy_entrypoint_4(param_0->unk0, 0x10);
        func_808006C0_chfreezy(param_0);
    }
}

int func_80800190_chfreezy(Actor *param_0, s32 param_1, FreezyMessage1425 param_2)
{
    switch (param_1) {
        case 0x3E:
            func_8080003C_chfreezy((u8 *)param_0);
            _sufreezy_entrypoint_5(param_0->unk0, param_2.local_0);
            _sufreezy_entrypoint_4(param_0->unk0, 0x10);
            func_808006C0_chfreezy((s32)param_0);
            return 1;
        case 0x3F:
            _sufreezy_entrypoint_6(param_0->unk0, param_2.local_0);
            return 1;
        case 0x40:
            func_8080003C_chfreezy((u8 *)param_0);
            _sufreezy_entrypoint_7(param_0->unk0, param_2.local_0);
            _sufreezy_entrypoint_4(param_0->unk0, 0x10);
            func_800FFAB0(param_0);
            return 1;
        case 0x95:
            if (!_subaddielink_entrypoint_3(func_80100094(param_0, 1))) {
                func_800FFAB0(param_0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void chfreezy_entrypoint_1(Actor *param_0, s16 *param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    if (!param_0->unk64_17) {
        if (((FreezyFlags74 *)((u8 *)param_0 + 0x74))->local_0) {
            ((FreezyFlags74 *)((u8 *)param_0 + 0x74))->local_0 = 0;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800748_chfreezy);
        } else if (!param_0->unk64_17 && !((FreezyFlags78 *)((u8 *)param_0 + 0x78))->local_0) {
            local_0 = param_1[0];
            local_1 = param_1[1];
            local_2 = param_1[2];
            ((FreezyFlags78 *)((u8 *)param_0 + 0x78))->local_0 = 1;
            func_80102190(param_0, 1);
            func_8010A570(param_0);
            func_8010108C(param_0, 3, 0);
            _sufreezy_entrypoint_3(param_0);
            _chbaddiesetup_entrypoint_5(_chfreezy_entrypoint_2, param_0->unk0, 0, local_0, local_1, local_2);
        }
    }
}

void chfreezy_entrypoint_2(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    Actor *local_0;
    Actor *local_1;

    local_0 = func_80106790(param_0);
    local_1 = _chnewfreezy_entrypoint_0(local_0->unk0, param_2, param_3, param_4);
    if (!local_1) local_1 = func_801084B0(0x363, &local_0);
    else local_0 = func_80106790(param_0);
    if (local_1) {
        _subaddielink_entrypoint_1(func_80100094(local_1, 1), param_0);
        func_8080044C_chfreezy(local_1, local_0, param_1);
        local_1->unk79_4 = func_8010A848(local_0);
        func_8010A828(local_0, 1);
    }
}

void func_8080044C_chfreezy(param_0, param_1, param_2) Actor *param_0; Actor *param_1; s32 param_2;
{
    if (((FreezyMarkerView *)param_0->unk0)->model == 0x2F6) {
        func_800EE7F8(param_0->rotation, param_1->rotation);
        func_80103DFC(param_1, param_0->position);
        func_808004B8_chfreezy(param_0, param_1, param_2);
    }
}

int func_808004B8_chfreezy(param_0, param_1, param_2) Actor *param_0; Actor *param_1; s32 param_2;
{
    f32 local_0;
    f32 local_1;
    if ((*(u32 *)((u8 *)param_0->unk0 + 0x24) >> 22) == 0x2F6) {
        local_0 = func_800EC708(param_1->unk0);
        local_1 = func_800EC708(param_0->unk0) / param_0->scale;
        param_0->unk50 = local_0 / local_1;
        if (param_2) {
            param_0->scale = param_0->unk50;
        }
    }
}

void func_80800538_chfreezy(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[2];
    s32 local_4;
    if (param_0->unk6C_0) --param_0->unk6C_0;
    if (param_0->unk7C_12 &&
        !(*(f32 *)((u8 *)param_0 + 0x58) < 1.0f) && param_0->unk6C_0 == 0) {
        func_800E3980(local_1);

        func_800F18FC(param_0->position, local_1, local_3);
        for (local_4 = 0; local_4 < 2; local_4++) local_3[local_4] += func_800DC178(0.0f, 160.0f) - 80.0f;
        func_800EEBF0(local_2, local_3, param_0->scale * 100.0f);
        func_800EE780(local_0, param_0->position, local_2);
        _fxtwinkle_entrypoint_1(local_0, 0x9E5);
        param_0->unk6C_0 = func_800D9058(func_800DC178(0.5f, 0.8f));
    }
}

s32 func_808006C0_chfreezy(param_0) s32 param_0;{
    _sufreezy_entrypoint_2();
    func_800FFAB0(param_0);
}
