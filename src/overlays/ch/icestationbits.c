#include "common.h"

extern int D_80800280_chicestationbits;
extern int D_808002C8_chicestationbits;
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
