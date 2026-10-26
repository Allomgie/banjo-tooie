#include "common.h"

extern u32 func_801168AC(u64 *);

void func_80800000_glcrc(u8 *param_0, u8 *param_1, u32 *param_2)
{
    u32 local_2;
    u32 local_3;
    u64 local_0;
    s32 local_1;
    u8 *local_4;

    local_1 = 0;
    local_0 = 0x8F809F473108B3C1ULL;
    local_2 = 0;
    local_3 = 0;
    for (local_4 = param_0; local_4 < param_1; local_4++, local_1 += 7) {
        local_0 += *local_4 << (local_1 & 0xF);
        local_2 ^= func_801168AC(&local_0);
    }
    for (local_4 = param_1 - 1; local_4 >= param_0; local_4--, local_1 += 3) {
        local_0 += *local_4 << (local_1 & 0xF);
        local_3 ^= func_801168AC(&local_0);
    }
    param_2[0] = local_2;
    param_2[1] = local_3;
}

s32 glcrc_entrypoint_0(u8 *param_0, s32 param_1) {
    u8 *local_0 = param_0 + param_1 - 8;
    func_80800000_glcrc(param_0, local_0, local_0);
    return *(s32 *)local_0;
}

s32 glcrc_entrypoint_1(u8 *param_0, s32 param_1)
{
    u32 local_1[2];
    u32 *local_0;

    local_0 = (u32 *)(param_0 + param_1 - 8);
    func_80800000_glcrc(param_0, local_0, local_1);
    return (local_0[0] != local_1[0] || local_0[1] != local_1[1]) ? 0x6E382 : 0;
}
