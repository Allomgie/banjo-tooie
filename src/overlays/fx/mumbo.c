#include "common.h"

extern void *func_800B5BE4(int);
extern void func_800BA22C(void *, s32);
extern void func_800BABB8(void *, s32, int, float, void *);
extern void *D_80800060_fxmumbo;

void fxmumbo_entrypoint_0(s32 param_0, s32 param_1)
{
    void *local_0;
    local_0 = func_800B5BE4(0xD);
    func_800BABB8(local_0, param_0, 0, 1.0f, &D_80800060_fxmumbo);
    func_800BA22C(local_0, param_1);
}
