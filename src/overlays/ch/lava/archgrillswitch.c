#include "common.h"

extern int D_80800030_chlavaarchgrillswitch[];

s32 func_80800000_chlavaarchgrillswitch(s32 arg0, s32 arg1, s32 arg2)
{
    return 0;
}

void func_80800014_chlavaarchgrillswitch(s32 arg0)
{
}

int chlavaarchgrillswitch_entrypoint_0()
{
    return (int) &D_80800030_chlavaarchgrillswitch;
}

extern void _chswitch_entrypoint_11();
extern void func_80105834();
extern void func_80101870();
extern void _chswitch_entrypoint_2();
extern void func_80107C2C();
int D_80800030_chlavaarchgrillswitch[20] = {0x3430287,
                                            0x8D90001,
                                            -0x7FEE5D40,
                                            (u32) _chswitch_entrypoint_11,
                                            (u32) func_80105834,
                                            (u32) func_80101870,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x888,
                                            0x0,
                                            (u32) _chswitch_entrypoint_2,
                                            0x0,
                                            (u32) func_80800014_chlavaarchgrillswitch,
                                            (u32) func_80107C2C,
                                            -0x7FFFE000,
                                            (u32) func_80800000_chlavaarchgrillswitch,
                                            0x0,
                                            0x0,
                                            0x0};
