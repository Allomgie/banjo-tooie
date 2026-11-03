#include "common.h"

extern u32 D_80800090_chwaterfallgrillswitch[];

int func_80800000_chwaterfallgrillswitch(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 7) {
        func_80101180(0x11B, 7, 0);
    }
    _chswitch_entrypoint_10(param_0, param_1 | param_1, param_2);
}

s32 func_80800054_chwaterfallgrillswitch(Actor *this)
{
    _chswitch_entrypoint_7(this, 0);
    _chswitch_entrypoint_8(this, 0x201);
}

int chwaterfallgrillswitch_entrypoint_0()
{
    return (int) &D_80800090_chwaterfallgrillswitch;
}

extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800090_chwaterfallgrillswitch[20] = {0xC011C,
                                             0x6800001,
                                             (u32) &D_8011A248,
                                             (u32) _chswitch_entrypoint_6,
                                             (u32) func_80102EC0,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x808,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800054_chwaterfallgrillswitch,
                                             (u32) func_80107C2C,
                                             0x80002C02,
                                             (u32) func_80800000_chwaterfallgrillswitch,
                                             0x0,
                                             0x0,
                                             0x0};
