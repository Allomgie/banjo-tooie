#include "common.h"

extern void *D_80800640_chvandoor;
extern s32 D_80800688_chvandoor;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 *B_80800690_chvandoor[];
extern u8 *B_80800694_chvandoor;
void func_80800388_chvandoor();
s32 func_8080044C_chvandoor();

int chvandoor_entrypoint_0()
{
  return &D_80800640_chvandoor;
}

void func_8080000C_chvandoor(Actor *param_0)
{
    s32 local_0;

    local_0 = param_0->unk74_7 + 0xA08;
    func_800EE7F8((f32 *)((u8 *)param_0 + 0x18), param_0->position);
    func_800EE7F8((f32 *)((u8 *)param_0 + 0x28), param_0->position);
    *(f32 *)((u8 *)param_0 + 0x2C) += param_0->scale * 300.0f;
    *(s32 *)((u8 *)param_0 + 0x50) = local_0;
    if (!func_800F64A4(func_800F54E4(), 0x8000)) {
        func_800DA524(local_0);
    }
    if (func_800DA298(local_0)) {
        func_80800388_chvandoor(param_0, 3);
        func_800EE7F8(param_0->position, (f32 *)((u8 *)param_0 + 0x28));
    } else {
        func_80800388_chvandoor(param_0, 1);
    }
    func_8010A800(param_0, 0);
    if (func_800EA05C() == 0xE7) {
        _subaddieDll_entrypoint_0(param_0);
    }
}

void func_80800104_chvandoor(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    f32 *local_3;
    local_0 = 0;
    switch (param_0->unk70_10) {
    default: local_3 = param_0->position; break;
    case 1: local_3 = param_0->position; break;
    case 2:
        local_1 = func_800D9078((u8 *)param_0 + 0x58);
        local_3 = param_0->position;
        func_800EFE50(local_3, (f32 *)param_0->actorData, (f32 *)((u8 *)param_0 + 0x28), func_800F10B4(*(f32 *)((u8 *)param_0 + 0x58), 0.0f, 2.0f, 1.0f, 0.0f));
        if (local_1) func_80800388_chvandoor(param_0, 3);
        local_0 = !local_1;
        break;
    case 3:
        if (func_8080044C_chvandoor(param_0)) func_80101180(0x3CC, 8, (u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7);
        local_3 = param_0->position;
        break;
    case 4: {
        s32 local_2;
        local_2 = func_800D9078((u8 *)param_0 + 0x58);
        local_3 = param_0->position;
        func_800EFE50(local_3, (f32 *)param_0->actorData, (f32 *)((u8 *)param_0 + 0x28), func_800F10B4(*(f32 *)((u8 *)param_0 + 0x58), 0.0f, 2.0f, 0.0f, 1.0f));
        if (local_2) func_80800388_chvandoor(param_0, 1);
        local_0 = !local_2;
        break;
    }
    }
    _subaddieaudioloop_entrypoint_4(param_0, local_3, local_0, &D_80800688_chvandoor);
}

int func_80800280_chvandoor(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x19:
        if (param_0->unk70_10 == 1) {
            func_800F5A00(param_2, local_0);
            if (func_800EEB40(local_0, param_0->position) < 250000.0f) {
                func_80101180(0x3CC, 7, param_0->unk74_7);
            }
        }
        break;
    case 7:
        if (param_2 != param_0->unk74_7) {
            return 0;
        }
        func_80800388_chvandoor(param_0, 2);
        break;
    case 8:
        if (param_2 != param_0->unk74_7) {
            return 0;
        }
        func_80800388_chvandoor(param_0, 4);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800388_chvandoor(param_0, param_1) Actor *param_0; s32 param_1; {
    func_80101FDC();
    switch (param_1) {
    case 1:
        func_80103110(param_0, 0);
        func_800DA524(*(s32 **)((char *)param_0 + 0x50));
        return;
    case 2:
        func_80103110(param_0, 1);
        *(f32 *)((char *)param_0 + 0x58) = 2.0f;
        func_800DA544(*(s32 **)((char *)param_0 + 0x50));
        return;
    case 3:
        func_80103110(param_0, 1);
        return;
    case 4:
        *(f32 *)((char *)param_0 + 0x58) = 2.0f;
        return;
    }
}

s32 func_8080044C_chvandoor(param_0) u8 *param_0;
{
    f32 local_0[3];
    s32 local_1[2];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    u8 *local_6;

    local_2 = func_8010D290(0x10000);
    local_3 = 0;
    if (local_2 == -1) {
        return 0;
    }
    func_800F5A00(local_2, local_0);
    local_6 = _subaddiefind_entrypoint_2(0x3CC, local_1);
    if (local_6 != 0) {
        do { if (((u32)*(u16 *)(local_6 + 0x76) >> 7) == ((u32)*(u16 *)(param_0 + 0x76) >> 7)) { B_80800690_chvandoor[local_3] = local_6; local_3++; } local_6 = _subaddiefind_entrypoint_3(0x3CC, local_1); } while (local_6 != 0);
    }
    for (local_4 = 1; local_4 < local_3; local_4++) {
        for (local_5 = local_4; local_5 > 0 && func_800EEB40((f32 *)(B_80800690_chvandoor[local_5] + 4), local_0) < func_800EEB40((f32 *)(B_80800690_chvandoor[local_5 - 1] + 4), local_0); local_5--) {
            local_6 = B_80800690_chvandoor[local_5];
            B_80800690_chvandoor[local_5] = B_80800690_chvandoor[local_5 - 1];
            B_80800690_chvandoor[local_5 - 1] = local_6;
        }
    }
    if (param_0 != B_80800690_chvandoor[0]) {
        return 0;
    }
    return func_800EEB40((f32 *)(B_80800690_chvandoor[0] + 4), local_0) > 2250000.0f;
}
