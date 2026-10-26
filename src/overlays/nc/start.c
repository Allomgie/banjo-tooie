#include "common.h"

extern void * _gccubesearch_entrypoint_14(s32, s32);
extern f32 func_800136E4(f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);

s32 ncstart_entrypoint_0(s32 param_0, f32 param_1[3], f32 param_2[3])
{
    void *local_1;
    s32 local_0;

    local_0 = 0x29;
    if (func_800A9C98()) {
        if (param_0 > 0 && param_0 < 9) local_0 = param_0 + 0xAD;
    } else {
        if (param_0 > 0 && param_0 < 0x29) local_0 = param_0 + 0x29;
    }
    local_1 = _gccubesearch_entrypoint_14(local_0, 0);
    if (local_1) {
        _gspropctrl_entrypoint_11(local_1, param_1);
        func_800EFA4C(param_2, 0.0f, func_800136E4(_gspropctrl_entrypoint_12(local_1) - 180.0f), 0.0f);
        return 1;
    }
    return 0;
}
