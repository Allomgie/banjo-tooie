#include "common.h"

extern u16 D_808000E0_chboggykids[];

s32 chboggykids_entrypoint_0(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    if (!func_800DA564(0x59D, 2)) {
        func_800DA7A8(0x59D, func_800DC128(0, 3) + 1, 2);
        func_800DA7A8(0x59F, func_800DC128(0, 3) + 1, 2);
        func_800DA7A8(0x5A1, func_800DC128(0, 3) + 1, 2);
    }
    local_0 = param_0->unk74_7 - 0x32;
    local_1 = (param_0->unk0->unk24 >> 22) - 0x192;
    if (func_800DA564(D_808000E0_chboggykids[local_1], 2) != local_0 + 1) return 0;
    return 1;
}
