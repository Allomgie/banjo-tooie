#include "common.h"

extern int D_80800940_chfactorytoxicpools;
extern int D_80800988_chfactorytoxicpools;
extern int D_808009D0_chfactorytoxicpools;
typedef struct { s16 local_0; s16 local_1; f32 local_2; } ToxicPoolSwitchState;
extern void *func_80100094(Actor *, u32);
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 D_80800A18_chfactorytoxicpools;
extern void func_80103110();
extern void func_8010A570(Actor *);
extern void _capod_entrypoint_13(void *, s32, s32, s32);
extern void func_800C4AF0(f32 *, s32 *);
extern s32 func_800BEA88(s32);
extern void _idworldmake_entrypoint_1(s32, s32, s32, s32);
extern s32 _chswitch_entrypoint_10(Actor *, s32, s32);
typedef struct { s16 pad_0; s16 state; f32 timer; } ToxicPoolState;
typedef struct { s16 pad_0; s16 local_0; } ToxicPoolInteraction;
extern u8 _chfactorytoxicpools_entrypoint_3[];
extern s32 D_80800A38_chfactorytoxicpools;
extern s32 D_80800A74_chfactorytoxicpools;
extern s32 D_80800AB0_chfactorytoxicpools;
extern s32 D_80800AC8_chfactorytoxicpools;
typedef struct ToxicPoolItem { s16 local_0; s16 pad_0; f32 local_1[3]; f32 local_2[3]; } ToxicPoolItem;
typedef struct ToxicPoolNodes { s16 local_0; s16 local_1; ToxicPoolItem local_2[8]; } ToxicPoolNodes;
extern f32 func_800F5628(void *);
extern s32 func_800CC338(f32 *, s32, s32);
typedef struct { s16 sel; s16 cnt; s16 id; s16 pad; f32 src[3]; f32 dst[2]; } TPEntry;
int func_80800270_chfactorytoxicpools();
void func_808004A4_chfactorytoxicpools();

int chfactorytoxicpools_entrypoint_0()
{
    return &D_80800940_chfactorytoxicpools;
}

int chfactorytoxicpools_entrypoint_1()
{
    return (int)&D_80800988_chfactorytoxicpools;
}

int *chfactorytoxicpools_entrypoint_2()
{
    return &D_808009D0_chfactorytoxicpools;
}

void func_80800024_chfactorytoxicpools(s32 param_0) {
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    local_1 = func_800DA298(0x18E);
    if (_chswitch_entrypoint_7(param_0, 0x18E) != 0) {
        func_80103110(param_0, 0, local_1);
    }
    *(f32 *)(local_0 + 4) = 8.0f;
    if (local_1 != 0) {
        *(s16 *)(local_0 + 0) = 0x384;
    } else {
        *(s16 *)(local_0 + 0) = 0;
    }
    if (local_1 != 0) {
        *(s16 *)(local_0 + 2) = 2;
    } else {
        *(s16 *)(local_0 + 2) = 0;
    }
    if (local_1 != 0) {
        func_8010A570(param_0);
    }
}

void func_808000D0_chfactorytoxicpools(Actor *param_0)
{
    ToxicPoolSwitchState *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    switch (local_0->local_1) {
    case 0:
        _chswitch_entrypoint_6(param_0);
        break;
    case 1:
        local_1 = func_800D9078(&local_0->local_2);
        local_0->local_0 = (s32)func_800F12D4(local_0->local_2, 0.0f, 8.0f, 900.0f, 0.0f);
        if (local_1) {
            local_0->local_1 = 2;
            func_80103110(param_0, 0);
        }
        break;
    }
    func_80800270_chfactorytoxicpools(param_0);
}

s32 func_80800190_chfactorytoxicpools(Actor *param_0, s32 param_1, s32 param_2)
{
    s16 *local_0;

    switch (param_1) {
    case 7:
        local_0 = func_80100094(param_0, 1);
        func_80103110(param_0, 1);
        func_8010A570(param_0);
        local_0[1] = 1;
        _capod_entrypoint_13(param_0->unk0, 0, 0, 0x10);
        func_800C4AF0(param_0->position, &D_80800A18_chfactorytoxicpools);
        break;
    case 0x95:
        _idworldmake_entrypoint_1(func_800BEA88(1), 0x659, 1, 1);
        func_80800270_chfactorytoxicpools(param_0);
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

int func_80800270_chfactorytoxicpools(param_0) s32 param_0;
{
    s16 *local_0;

    local_0 = func_80100094(param_0, 1);
    _idwibble_entrypoint_5(_idworld_entrypoint_4(func_800BEA88(1), 1), *local_0);
}

void func_808002B8_chfactorytoxicpools(s32 param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    local_1 = func_800DA298(0x166);
    _chswitch_entrypoint_14(param_0, 0x166);
    *(f32 *)(local_0 + 4) = 1.0f;
    if (local_1 != 0) {
        *(s16 *)(local_0 + 2) = 2;
    } else {
        *(s16 *)(local_0 + 2) = 0;
    }
    if (local_1 != 0) {
        func_8010A570(param_0);
    }
    func_80105010(param_0);
}

void func_80800338_chfactorytoxicpools(Actor *param_0)
{
    ToxicPoolState *local_0;
    local_0 = func_80100094(param_0, 1);
    switch (local_0->state) {
        case 0:
            _chswitch_entrypoint_13(param_0);
            break;
        case 1:
            if (func_800D9078(&local_0->timer)) {
                func_80103110(param_0, 0);
                local_0->state = 2;
                func_800F82D4(func_800F54E4(), 0);
                _capod_entrypoint_13(param_0->unk0, 0, 0x12, 0x2030);
            }
            break;
    }
}

s32 func_808003DC_chfactorytoxicpools(Actor *param_0, s32 param_1, s32 param_2)
{
    ToxicPoolInteraction *local_0;

    switch (param_1) {
    case 0x95:
        func_808004A4_chfactorytoxicpools(param_0);
        break;
    case 7:
        local_0 = func_80100094(param_0, 1);
        func_80103110(param_0, 1);
        func_8010A570(param_0);
        local_0->local_0 = 1;
        func_800F8300(func_800F54E4(), 2, param_0->position);
        break;
    case 11:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0x1A7, 0x2A);
        return 4;
    default:
        return 0;
    }
    return 1;
}

void func_808004A4_chfactorytoxicpools(param_0) s32 param_0[3];
{
  s32 local_0;
  local_0 = func_800BEA88(1);
  if (local_0 != 0)
  {
    _idworldmake_entrypoint_1(local_0, 0x7D, 2, 1);
    _glid_entrypoint_0(local_0, 2, &_chfactorytoxicpools_entrypoint_3, param_0[0]);
  }
}

void chfactorytoxicpools_entrypoint_3(void *param_0, Vtx *param_1, Vtx *param_2, s32 param_3)
{
    s32 local_0;
    Vtx *local_1;
    if (func_800DA298(0x166)) local_0 = -300;
    else local_0 = 0;
    local_1 = param_1 + param_3;
    for (; param_1 < local_1; param_1++, param_2++) {
        param_2->v.ob[1] = param_1->v.ob[1] + local_0;
    }
}

void func_8080057C_chfactorytoxicpools(Actor *param_0)
{
    ToxicPoolNodes *local_3;
    void *local_0[8];
    s32 local_2;
    f32 local_1[3];

    local_3 = func_80100094(param_0, 0);
    local_3->local_1 = _gccubesearch_entrypoint_9(0x154, local_0, 8);
    for (local_2 = 0; local_2 < local_3->local_1; local_2++) {
        func_800EE88C(local_1, local_0[local_2]);
        local_3->local_2[local_2].local_0 = func_800CBC3C(local_1);
        func_800EFD24(local_3->local_2[local_2].local_2);
        func_800EE7F8(local_3->local_2[local_2].local_1, local_1);
    }
    local_3->local_0 = -1;
    param_0->unk58 = 1.2f;
}

void func_80800898_chfactorytoxicpools();

void func_80800670_chfactorytoxicpools(Actor *param_0)
{
    s32 local_5;
    s32 local_6;
    s32 local_7;
    f32 local_8;
    f32 local_0[3];
    TPEntry *local_2;
    void *local_4;
    s32 local_1;

    local_2 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        local_4 = func_800F54E4();
        if (func_800F6A38(local_4)) {
            local_5 = func_800F5C94(local_4);
            local_6 = func_800F5D18(local_4);
            if (local_5 != 12 && local_5 != 14 && local_6 && func_800D9078(&param_0->unk58)) {
                func_800F7D90(local_4, 0x52, local_2[local_2->sel].dst, 1);
                func_80101FDC(param_0, 2);
                func_80800898_chfactorytoxicpools(param_0);
                param_0->unk58 = 2.5f;
            }
            return;
        }
        func_800F5A00(local_4, local_0);
        for (local_7 = 0; local_7 < local_2->cnt; local_7++) {
            local_8 = func_800F5628(local_4);
            local_1 = local_8 != -18000.0f;
            if (local_1) {
                local_0[1] = local_8;
            } else {
                local_0[1] = local_2[local_7].dst[1];
            }
            if (func_800CC338(local_0, local_2[local_7].id, 0) != -1) {
                if (!local_1) {
                    func_800EE7F8(local_2[local_7].dst, local_2[local_7].src);
                } else {
                    func_800EE7F8(local_2[local_7].dst, local_0);
                }
                local_2->sel = local_7;
            }
        }
        param_0->unk58 = 1.2f;
        return;
    case 2:
        if (func_800D9078(&param_0->unk58) && func_800F5578(func_800F54E4()) > 0) {
            func_80101FDC(param_0, 1);
            param_0->unk58 = 1.2f;
        }
        break;
    }
}

void func_80800898_chfactorytoxicpools(s32 param_0) {
    f32 local_0[3];
    f32 local_1[3];

    func_800F5A00(func_800F54E4(), local_1);
    func_800BBCB8(local_1, NULL, 0x3F800000, 8, &D_80800A38_chfactorytoxicpools);
    func_800EE780(local_0, local_1, &D_80800AC8_chfactorytoxicpools);
    func_800BBCB8(local_1, local_0, 0x3F800000, 4, &D_80800A74_chfactorytoxicpools);
    _subaddieaudioquick_entrypoint_2(param_0, local_1, &D_80800AB0_chfactorytoxicpools);
}
