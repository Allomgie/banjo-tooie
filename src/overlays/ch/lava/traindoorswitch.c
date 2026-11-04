#include "ch/lavatraindoorswitch.h"

// HFP fire-side train station switch; message 7 plays cutscene 0x4D in map 0x129.
s32 func_80800000_chlavatraindoorswitch(void *this, s32 msg)
{
    if (msg == 7) {
        _glcutDll_entrypoint_6(0x129, 0x4D);
        return TRUE;
    }
    return _chswitch_entrypoint_10(this, msg);
}

void func_8080003C_chlavatraindoorswitch(s32 switch_actor)
{
    _chswitch_entrypoint_7(switch_actor, FLAG_1D0_STATION_UNLOCKED_HFPL);
    _chswitch_entrypoint_9(switch_actor);
}

int chlavatraindoorswitch_entrypoint_0()
{
    extern void *D_80800080_chlavatraindoorswitch;
    return (int) &D_80800080_chlavatraindoorswitch;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise.
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800080_chlavatraindoorswitch = (void *) 0x03430285;
static u32 D_80800080_chlavatraindoorswitch_rest[19] = {0x86D0001,
                                                        (u32) &D_8011A248,
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
                                                        (u32) func_8080003C_chlavatraindoorswitch,
                                                        (u32) func_80107C2C,
                                                        0x80012C02,
                                                        (u32) func_80800000_chlavatraindoorswitch,
                                                        0x0,
                                                        0x0,
                                                        0x0};
