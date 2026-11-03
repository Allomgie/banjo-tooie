#include "common.h"

extern int D_808000A0_chicekey[];
extern int D_808000EC_chicekey[];

int func_80800000_chicekey(s32 param_0[4], s32 param_1, s32 param_2)
{
    if (param_1 == 0x3E) {
        func_800BBCB8(param_0 + 1, param_0 + 1, 0x3F800000, 0x14, &D_808000A0_chicekey);
        func_800D1844(0x53);
        _subaddiedialog_entrypoint_11(param_0[0], 0x1550, 4, param_0 + 1, 0x6F);
        func_800FC660(0xE);
        func_800FFA88(param_0[0]);
        return 1;
    }
    return 0;
}

int chicekey_entrypoint_0()
{
    return (int) &D_808000EC_chicekey;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000A0_chicekey[19] = {0x1D09E0, 0x1BFCE0,   -0x257FFD3, 0xC8015E, 0xE0000,
                               0x500016, 0x10020027, 0x12C,      0x1F4,    0x22004C,
                               0x4C0059, 0x800015,   0xCC,       0x2B0180, 0x3000004,
                               0x990007, 0x40031,    -0x4A0032,  0x0};
int D_808000EC_chicekey[21] = {0x1580513,
                               0x63B0001,
                               0x0,
                               0x0,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_80108ED0,
                               0x0,
                               0x0,
                               (u32) func_80107C2C,
                               -0x7FFFFC00,
                               (u32) func_80800000_chicekey,
                               0x0,
                               0x0,
                               0x0,
                               0x0};
