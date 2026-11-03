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

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lava/traindoorswitch.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800080_chlavatraindoorswitch = (void *)0x03430285;
static u32 D_80800080_chlavatraindoorswitch_rest[19] = { 0x86D0001, (u32)&D_8011A248, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, 0x0, 0x0, 0x0, (u32)func_8080003C_chlavatraindoorswitch, (u32)func_80107C2C, 0x80012C02, (u32)func_80800000_chlavatraindoorswitch, 0x0, 0x0, 0x0 };
