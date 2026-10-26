#include "common.h"

extern int D_808000E0_chpumproomgrill;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800128_chpumproomgrill[];
extern void _subaddieaudioquick_entrypoint_2();
extern void func_800DA544(s32);
void func_808000AC_chpumproomgrill();

void *chpumproomgrill_entrypoint_0()
{
  return (void *)&D_808000E0_chpumproomgrill;
}

void func_8080000C_chpumproomgrill(s32 arg0) 
{
}
s32 func_80800014_chpumproomgrill(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
    case 0x40:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], -400.0f);
        _chexploder_entrypoint_3(param_0, local_0, 0xF);
        break;
    case 0x90:
        func_808000AC_chpumproomgrill(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808000AC_chpumproomgrill(param_0) u8 *param_0; {
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80800128_chpumproomgrill);
    func_800DA544(0x162);
}
