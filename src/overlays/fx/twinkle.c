#include "fx/twinkle.h"

extern s32 D_808000F0_fxtwinkle;
extern void *func_800B53A4(int param_0);
extern void func_800BABB8(void *param_0, s32 param_1, int param_2, float param_3, void *param_4);
extern void func_800BA3FC();
extern void func_800BA22C(void *param_0, int param_1);
extern void *D_8080010C_fxtwinkle;

void fxtwinkle_entrypoint_0(s32 arg0)
{
    fxtwinkle_entrypoint_1(arg0, GOLD_SPARKLE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/twinkle/fxtwinkle_entrypoint_1.s")

void fxtwinkle_entrypoint_2(param_0, param_1) s32 param_0; s16 param_1;
{
    void *local_0;
    local_0 = func_800B53A4(1);
    func_800BABB8(local_0, param_0, 0, 1.0f, &D_8080010C_fxtwinkle);
    func_800BA3FC(local_0, param_1);
    func_800BA22C(local_0, 1);
}
