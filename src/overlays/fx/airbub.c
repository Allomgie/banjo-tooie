#include "common.h"

extern void func_800BA568();
extern s32 D_80800100_fxairbub[];
extern void _fxairbub_entrypoint_0();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800BA6B0(s32, s16, s16, s16, s16, s16, s16);

s32 fxairbub_entrypoint_0(s32 param_0)
{
    _fxripple_entrypoint_0(0);
}

void fxairbub_entrypoint_1(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3)
{
    s32 local_0;

    local_0 = func_800B5BE4(2);
    func_800BA568(local_0, (s16) param_2);
    func_800BA6B0(local_0, (s16) -param_1, 0, (s16) -param_1, (s16) param_1, 0, (s16) param_1);
    func_800BA544(local_0, _fxairbub_entrypoint_0);
    func_800BABB8(local_0, param_0, NULL, param_3, D_80800100_fxairbub);
}

s32 D_80800100_fxairbub[20] = {
    0x1D09D9, 0x161004, 0x1B0096,   0x960007, 0x10015, 0xCC,     0x2B0300, 0x300002C, 0x0,  0x0,
    0x0,      0x20FFFF, -0x100FFDE, 0xC0017,  0xC0017, 0x2F0040, 0x400000, 0x19,      0x33, 0x0};
