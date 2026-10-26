#include "common.h"

extern int D_80800330_chhellterskeltermouth;
extern s32 D_80800384_chhellterskeltermouth;
extern void _subaddieaudioloop_entrypoint_4();
extern u8 D_80800378_chhellterskeltermouth[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);

int chhellterskeltermouth_entrypoint_0()
{
    return (int)&D_80800330_chhellterskeltermouth;
}

void func_808002E4_chhellterskeltermouth();

void func_8080000C_chhellterskeltermouth(Actor *param_0)
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    f32 *local_3;
    switch (param_0->unk70_10) {
    case 1: break;
    case 2:
        local_0 = func_800D9078(&param_0->unk58);
        local_3 = param_0->position;
        local_1 = func_800F12D4(param_0->unk58, 0.0f, 2.5f, 1.0f, 0.0f);
        func_800EFE50(local_3, (f32 *)param_0->actorData + 4, (f32 *)param_0->actorData, local_1);
        if (local_0) {
            param_0->unk58 = 0.7f;
            func_80101FDC(param_0, 3);
            _subaddieaudioquick_entrypoint_2(param_0, local_3, D_80800378_chhellterskeltermouth);
        }
        func_808002E4_chhellterskeltermouth(param_0);
        break;
    case 3:
        if (func_800D9078(&param_0->unk58)) {
            param_0->unk58 = 2.5f;
            func_80101FDC(param_0, 4);
        }
        break;
    case 4:
        local_2 = func_800D9078(&param_0->unk58);
        local_3 = param_0->position;
        local_1 = func_800F12D4(param_0->unk58, 0.0f, 2.5f, 0.0f, 1.0f);
        func_800EFE50(local_3, (f32 *)param_0->actorData + 4, (f32 *)param_0->actorData, local_1);
        if (local_2) {
            param_0->unk58 = 0.7f;
            func_80101FDC(param_0, 5);
            _subaddieaudioquick_entrypoint_2(param_0, local_3, D_80800378_chhellterskeltermouth);
        }
        func_808002E4_chhellterskeltermouth(param_0);
        break;
    case 5:
        if (func_800D9078(&param_0->unk58)) {
            param_0->unk58 = 2.5f;
            func_80101FDC(param_0, 2);
        }
        break;
    }
}

void func_808001BC_chhellterskeltermouth(u8 *param_0)
{
    func_800EE7F8(param_0 + 0x18, param_0 + 4);
    func_800EE7F8(param_0 + 0x28, param_0 + 4);
    (*(f32 *)((char *)param_0 + 0x2C)) = (*(f32 *)((char *)param_0 + 0x2C)) - 350.0f;
    if (func_800DA298(0xA4) != 0)
    {
        func_8010A590(param_0);
        func_80102FE8(param_0, 0);
        func_80101FDC(param_0, 4);
        (*(f32 *)((char *)param_0 + 0x58)) = 2.5f;
        return;
    }
    func_80103110(param_0, 0);
}

int func_80800258_chhellterskeltermouth(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0xA:
        _capod_entrypoint_13(param_0->unk0, 0, 0x1A, 0x2010);
        func_8010A590(param_0);
        func_80103110(param_0, 1);
        func_80102FE8(param_0, 0);
        func_80101FDC(param_0, 4);
        param_0->unk58 = 2.5f;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808002E4_chhellterskeltermouth(u8 *param_0) {
    _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, 1, &D_80800384_chhellterskeltermouth);
}
