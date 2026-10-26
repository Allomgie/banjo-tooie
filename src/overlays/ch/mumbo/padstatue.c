#include "common.h"

typedef union { s32 local_0; void *local_1; } MumboPadStatueEvent;
extern s32 D_808000A0_chmumbopadstatue[];
extern u8 D_8080010C_chmumbopadstatue[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern int D_80800120_chmumbopadstatue;

void func_80800000_chmumbopadstatue(s32 arg0) 
{
}
s32 func_80800008_chmumbopadstatue(Actor *param_0, s32 param_1, MumboPadStatueEvent param_2)
{
    f32 *local_0;
    if (param_1 == 0x40) {
        local_0 = param_0->position;
        _chexploder_entrypoint_3(param_0, local_0, 0xC);
        func_800BABB8(0, local_0, local_0, param_0->scale, D_808000A0_chmumbopadstatue);
        func_800C4AF0(local_0, D_8080010C_chmumbopadstatue);
        return 1;
    }
    return 0;
}

int *chmumbopadstatue_entrypoint_0()
{
    return &D_80800120_chmumbopadstatue;
}
