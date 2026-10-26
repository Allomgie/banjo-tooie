#include "common.h"

extern u8 D_80800250_chlavacolumns[];
extern u8 D_80800258_chlavacolumns[];
extern f32 func_800D8FF8(void);
extern int D_80800260_chlavacolumns;
s32 func_80800200_chlavacolumns(s32 param_0, f32 param_1);
extern void func_800EDCB8(s32, f32);

void func_80800000_chlavacolumns(u8 *param_0) {
    func_80800200_chlavacolumns(param_0, -400.0f);
    func_800EFD24(param_0 + 4);
    *(f32 *)(param_0 + 8) = -400.0f;
    func_80103014(param_0);
}

s32 func_80800044_chlavacolumns(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x95) {
    if (_glcutDll_entrypoint_19(0x4E)) {
        param_0->unk64_16 = 1;
        param_0->position[1] = -400.0f;
        func_80103110(param_0, 1);
        func_80102FE8(param_0, 0);
        _subaddieDll_entrypoint_0(param_0);
        func_80101FDC(param_0, 2);
        func_80800200_chlavacolumns(param_0, -400.0f);
        _capod_entrypoint_13(param_0->unk0, 0, 0x1A, 0x910);
    } else if (func_800DA298(0x390)) {
        param_0->position[1] = 0.0f;
        func_80101FDC(param_0, 3);
        func_80800200_chlavacolumns(param_0, 0.0f);
    } else {
        param_0->position[1] = -400.0f;
        func_80800200_chlavacolumns(param_0, -400.0f);
    }
    func_80103014(param_0);
    return 1;
    }
    return 0;
}

void func_8080014C_chlavacolumns(Actor *param_0)
{
    if (param_0->unk70_10 == 2) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800250_chlavacolumns);
        param_0->position[1] += 100.0f * func_800D8FF8();
        if (param_0->position[1] > 0.0f) {
            param_0->position[1] = 0.0f;
            func_80101FDC(param_0, 3);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800258_chlavacolumns);
            func_80103110(param_0, 0);
        }
    }
}

s32 func_80800200_chlavacolumns(s32 param_0, f32 param_1) {
    s32 local_0;

    local_0 = _idworld_entrypoint_3(0x190);
    if (local_0) {
        func_800EDCB8(local_0, param_1);
        return 1;
    }
    return 0;
}

int chlavacolumns_entrypoint_0(void)
{
    return (int)&D_80800260_chlavacolumns;
}
