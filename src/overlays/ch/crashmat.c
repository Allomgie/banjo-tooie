#include "common.h"

extern s32 _plsu_entrypoint_3(void *);
extern s32 func_800D90A4(f32 *);
extern void func_800C3F48(s32);
extern int D_808000A0_chcrashmat[];

void func_80800000_chcrashmat(Actor *param_0)
{
    s32 local_0;

    local_0 = _plsu_entrypoint_3(param_0->unk0);
    if (!local_0 && func_800D90A4(&param_0->unk58) && !param_0->unk64_20) {
        func_800C3F48(0x599C5699);
        param_0->unk58 = 0.5f;
    }
    param_0->unk64_20 = !local_0;
}

int chcrashmat_entrypoint_0()
{
    return (int) &D_808000A0_chcrashmat;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000A0_chcrashmat[20] = {0x158050B,
                                 0x92B0001,
                                 0x0,
                                 (u32) func_80800000_chcrashmat,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x3E80000,
                                 0x0,
                                 0x0,
                                 0x21C08,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0};
