#include "common.h"

extern int D_80800280_chicestationbits[];
extern int D_808002C8_chicestationbits[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);

int *chicestationbits_entrypoint_0()
{
    return &D_80800280_chicestationbits;
}

void *chicestationbits_entrypoint_1()
{
    return &D_808002C8_chicestationbits;
}

s32 func_80800018_chicestationbits(void *param_0) {
    _chswitch_entrypoint_7(param_0, 0x1CF);
    _chswitch_entrypoint_9(param_0);
    _chswitch_entrypoint_8(param_0, 2);
}

s32 func_80800050_chicestationbits(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 7:
        _glcutDll_entrypoint_6(0x12A, 0x48);
        break;
    case 0x91:
        if (!func_800F6B94(func_800F54E4())) {
            return 0;
        }
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

void func_808000D4_chicestationbits(Actor *param_0)
{
    f32 local_0;

    local_0 = param_0->rotation[1];
    if (param_0->unk74_7 == 0x32) {
        local_0 += 180.0f;
    }
    func_800EFD24(param_0->position);
    func_80103014(param_0);
    if (_chdoormake_entrypoint_3(param_0, local_0, 0.0f, 600.0f, 0x20, 0x1CF)) {
        _chdoormake_entrypoint_5(param_0, 3.5f);
        _chdoormake_entrypoint_6(param_0, 0.5f);
        _chdoormake_entrypoint_12(param_0, 0, 0x48);
        if (param_0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(param_0, 9);
            _chdoormake_entrypoint_9(param_0, 0, 0, 0x900);
        }
    }
    if (func_800DA298(0x1CF) && !_glcutDll_entrypoint_19(0x48)) {
        func_800FFAB0(param_0);
    }
}

s32 func_808001E0_chicestationbits(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x95:
        local_0 = param_0->unk74_7 == 0x32 ? 0x872 : 0x873;
        func_80103140(param_0, local_0, param_0->unk0->unk16);
        break;
    case 0x9D:
        func_800FFAB0(param_0);
        break;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/icestationbits.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800280_chicestationbits -> int[], D_808002C8_chicestationbits -> int[] */
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
int D_80800280_chicestationbits[18] = { 0x343041A, 0x86D0001, (u32)&D_8011A248, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x80C, 0x0, 0x0, 0x0, (u32)func_80800018_chicestationbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_80800050_chicestationbits, 0x0 };
int D_808002C8_chicestationbits[18] = { 0xAC041B, -0xFFFF, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_808000D4_chicestationbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_808001E0_chicestationbits, 0x0 };
