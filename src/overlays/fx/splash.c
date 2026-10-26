#include "common.h"

extern int D_80800130_fxsplash;
extern s32 D_80800144_fxsplash[];
extern void _fxsplash_entrypoint_0(void);
extern s32 func_800B5BE4(s32);
extern int func_800BA6B0(s32, s16, s16, s16, s16, s16, s16);
extern void func_800BA4D0();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
int fxsplash_entrypoint_2(f32 *param_0, f32 param_1);

s32 fxsplash_entrypoint_0(s32 param_0) {
    _fxripple_entrypoint_0(0);
}

int fxsplash_entrypoint_1(s32 param_0)
{
  s32 local_0;
  local_0 = fxsplash_entrypoint_2(param_0, 20.0f);
  func_800BABB8(local_0, 0, 0, 1.0f, &D_80800130_fxsplash);
}

int fxsplash_entrypoint_2(f32 *param_0, f32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_800B5BE4(1);
    local_1 = (s32)-param_1;
    local_2 = (s32)param_1;
    func_800BA6B0(local_0, (s16)local_1, 0, (s16)local_1, (s16)local_2, 0, (s16)local_2);
    func_800BA4D0((void *)local_0, (s16)(s32)param_0[1]);
    func_800BA544((void *)local_0, (s32)_fxsplash_entrypoint_0);
    func_800BABB8(local_0, param_0, NULL, 1.0f, D_80800144_fxsplash);
}
