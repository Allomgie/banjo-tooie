#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

void func_80800000_chlavatraindoor(Actor *param_0)
{
    f32 local_0;

    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 1007.5f, 0x20, 0x1D0)) {
        _chdoormake_entrypoint_12(param_0, 0, 0x4D);
        _chdoormake_entrypoint_8(param_0, 5);
        if (param_0->unk74_7 == 0x32) local_0 = 0.8f;
        else local_0 = 3.5f;
        _chdoormake_entrypoint_6(param_0, local_0);
        if (param_0->unk74_7 == 0x32) _chdoormake_entrypoint_9(param_0, 0, 8, 0x910);
    }
}

int chlavatraindoor_entrypoint_0()
{
    extern int D_808000F0_chlavatraindoor;
    return &D_808000F0_chlavatraindoor;
}
