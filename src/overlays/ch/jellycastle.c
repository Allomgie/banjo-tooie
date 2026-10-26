#include "common.h"

extern s32 _plsu_entrypoint_3(void *);
extern s32 func_800D90A4(f32 *);
extern void func_800C3F48(s32);
extern int D_808000A0_chjellycastle;

void func_80800000_chjellycastle(Actor *param_0)
{
    s32 local_0;

    local_0 = _plsu_entrypoint_3(param_0->unk0);
    if (!local_0 && func_800D90A4(&param_0->unk58) && !param_0->unk64_20) {
        func_800C3F48(0x599C5699);
        param_0->unk58 = 0.5f;
    }
    param_0->unk64_20 = !local_0;
}

int chjellycastle_entrypoint_0()
{
    return (int)&D_808000A0_chjellycastle;
}
