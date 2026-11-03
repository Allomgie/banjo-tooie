#include "common.h"

extern int D_80800330_chhellterskeltermouth[];
extern s32 D_80800384_chhellterskeltermouth[];
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

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/hellterskeltermouth.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800330_chhellterskeltermouth -> int[], D_80800384_chhellterskeltermouth -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800330_chhellterskeltermouth[18] = { 0x1AA0340, 0x77E0001, 0x0, (u32)func_8080000C_chhellterskeltermouth, (u32)func_80105834, (u32)func_80101870, 0xDAC0000, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_808001BC_chhellterskeltermouth, (u32)func_80107C2C, -0x7FFFDBFE, (u32)func_80800258_chhellterskeltermouth, 0x0 };
u8 D_80800378_chhellterskeltermouth[12] = { 0x0, 0x13, 0x4, 0xCC, 0x0, 0xD, 0x0, 0xA6, 0x0, 0xC0, 0x0, 0x0 };
s32 D_80800384_chhellterskeltermouth[7] = { 0x1304AD, 0x105DC, 0xBB8000E, 0x94009E, 0x190016, 0x6D600000, 0x0 };
