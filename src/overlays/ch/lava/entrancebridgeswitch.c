#include "ch/lavaentrancebridgeswitch.h"

extern int D_808000A0_chlavaentrancebridgeswitch[];

int func_80800000_chlavaentrancebridgeswitch(s32 param_0[4], s32 param_1)
{
    if (param_1 == 7) {
        func_80101180(910, 96, 0);
        _capod_entrypoint_13(param_0[0], 0, 5, 16);
        return 1;
    }
    return _chswitch_entrypoint_10(param_0);
}

void func_8080005C_chlavaentrancebridgeswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0, FLAG_391_PROGRESS_IoH_HFP_BRIDGE_EXTENDED);
    _chswitch_entrypoint_9(arg0);
}

int chlavaentrancebridgeswitch_entrypoint_0()
{
    return (int) &D_808000A0_chlavaentrancebridgeswitch;
}

extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808000A0_chlavaentrancebridgeswitch[20] = {0x343038F,
                                                 0x95B0001,
                                                 (u32) &D_8011A270,
                                                 (u32) _chswitch_entrypoint_6,
                                                 (u32) func_80105834,
                                                 (u32) func_80101870,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x808,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_8080005C_chlavaentrancebridgeswitch,
                                                 (u32) func_80107C2C,
                                                 -0x7FFFD3FE,
                                                 (u32) func_80800000_chlavaentrancebridgeswitch,
                                                 0x0,
                                                 0x0,
                                                 0x0};
