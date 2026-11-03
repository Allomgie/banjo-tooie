#include "fx/twinkle.h"

extern s32 D_808000F0_fxtwinkle[];
extern void *func_800B53A4(int param_0);
extern void func_800BABB8(void *param_0, s32 param_1, int param_2, float param_3, void *param_4);
extern void func_800BA3FC();
extern void func_800BA22C(void *param_0, int param_1);
extern void *D_8080010C_fxtwinkle;

void fxtwinkle_entrypoint_0(s32 arg0)
{
    fxtwinkle_entrypoint_1(arg0, GOLD_SPARKLE);
}

void fxtwinkle_entrypoint_1(f32 *param_0, AssetId param_1)
{
    s32 local_0;
    short new_var;
    s32 local_1;
    local_1 = func_800B53A4(1);
    new_var = param_1;
    local_0 = local_1;
    func_800BABB8(local_1, param_0, 0, 1.0f, &D_808000F0_fxtwinkle);
    func_800BA3FC(local_0, new_var);
    func_800BA22C(local_0, 1);
}

void fxtwinkle_entrypoint_2(param_0, param_1) s32 param_0;
s16 param_1;
{
    void *local_0;
    local_0 = func_800B53A4(1);
    func_800BABB8(local_0, param_0, 0, 1.0f, &D_8080010C_fxtwinkle);
    func_800BA3FC(local_0, param_1);
    func_800BA22C(local_0, 1);
}

s32 D_808000F0_fxtwinkle[7] = {0x2B00B3, 0xB30022,  0x660066, 0x70007,
                               0x270000, 0x10E0000, 0x10E0000};
void *D_8080010C_fxtwinkle = (void *) 0x002B00B3;
static u32 D_8080010C_fxtwinkle_rest[8] = {0xB30016, 0x10040022, 0x660066,  0x70007,
                                           0x270000, 0x10E0000,  0x10E0000, 0x0};
