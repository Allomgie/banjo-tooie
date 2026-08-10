#include "ch/lavatraindoorswitch.h"

s32 func_80800000_chlavatraindoorswitch(void *this, s32 param_1) {
    if (param_1 == 7) {
        _glcutDll_entrypoint_6(0x129, 0x4D);
        return TRUE;
    }
    return _chswitch_entrypoint_10(this, param_1);
}

void func_8080003C_chlavatraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D0_STATION_UNLOCKED_HFPL);
    _chswitch_entrypoint_9(arg0);
}

int chlavatraindoorswitch_entrypoint_0()
{
    extern void *D_80800080_chlavatraindoorswitch;
    return (int)&D_80800080_chlavatraindoorswitch;
}
