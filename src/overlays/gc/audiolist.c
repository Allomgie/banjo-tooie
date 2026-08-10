#include "common.h"

extern void func_800C4AF0(s32, s32);
extern s32 D_808000F0_gcaudiolist[];

int gcaudiolist_entrypoint_0(s32 param_0)
{
    u32 local_0;
    local_0 = param_0 | 0;
    func_800C4AF0(0, D_808000F0_gcaudiolist[local_0]);
}

void gcaudiolist_entrypoint_1(s32 param_0, s32 param_1)
{
    func_800C4B70(param_1);
    func_800C4AF0(0, D_808000F0_gcaudiolist[param_0]);
}
