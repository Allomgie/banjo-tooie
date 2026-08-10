#include "common.h"

extern u32 D_808003AC_fxsparkle[];
extern void func_800BABB8(u32, s32, s32, f32, u32);
extern u32 _fxspgold_entrypoint_2(void);
int fxsparkle_entrypoint_1();

int fxsparkle_entrypoint_0(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_800EE88C(local_0, param_0 | 0);
  fxsparkle_entrypoint_1(local_0, param_1);
}

int fxsparkle_entrypoint_1(param_0, param_1) s32 param_0; s32 param_1;
{
    u32 local_0;
    u32 *local_1 = &D_808003AC_fxsparkle[param_1];
    local_0 = _fxspgold_entrypoint_2();
    if (*local_1 != 0)
    {
        func_800BABB8(local_0 | 0, param_0, 0, 1.0f, *local_1);
    }
}

void fxsparkle_entrypoint_2()
{
    _fxspgold_entrypoint_0();
}

s32 fxsparkle_entrypoint_3(s32 param_0, f32 position[3], s32 param_2, s32 param_3) {
    _fxspgold_entrypoint_1(param_0, position, param_2, param_3);
}
