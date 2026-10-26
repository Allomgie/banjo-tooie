#include "common.h"

extern int D_808000F0_chbottlesplantgrill;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_5(Actor *, f32);

int chbottlesplantgrill_entrypoint_0()
{
    return (int)&D_808000F0_chbottlesplantgrill;
}

void func_8080000C_chbottlesplantgrill(Actor *param_0)
{
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 250.0f, 0, -1)) {
        _chdoormake_entrypoint_6(param_0, 1.0f);
        _chdoormake_entrypoint_5(param_0, 3.0f);
        _chdoormake_entrypoint_8(param_0, 5);
        _chdoormake_entrypoint_12(param_0, 0, 0x65);
        _chdoormake_entrypoint_9(param_0, 0, 3, 0x2900);
    }
    func_8010A800(param_0, 0);
    if (!_glcutDll_entrypoint_19(0x65) && (func_800DA298(0x1A5) || func_800DA298(0x3B))) {
        func_800FFAB0(param_0);
    }
}
