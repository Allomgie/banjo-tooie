// Switch that unlocks the Isle o' Hags train station: sets FLAG_403_STATION_UNLOCKED_IoH and
// on message 7 (pressed) tells the station door (actor 0x38C) to open.
#include "ch/hagstraindoorswit.h"

extern int D_80800080_chhagstraindoorswitch[];

// Pressed (7): tells the station door (actor 0x38C) to open.
s32 func_80800000_chhagstraindoorswitch(void *this, s32 msg)
{
    if (msg == 7) {
        func_80101180(0x38C, 7, 0);
        return 1;
    }
    _chswitch_entrypoint_10(this, msg);
}

void func_80800040_chhagstraindoorswitch(s32 actor)
{
    _chswitch_entrypoint_7(actor, FLAG_403_STATION_UNLOCKED_IoH);
    _chswitch_entrypoint_9(actor);
}

int chhagstraindoorswitch_entrypoint_0()
{
    return (int) &D_80800080_chhagstraindoorswitch;
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800080_chhagstraindoorswitch[20] = {0x343038D,
                                            0x86D0001,
                                            -0x7FEE5D40,
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
                                            (u32) func_80800040_chhagstraindoorswitch,
                                            (u32) func_80107C2C,
                                            -0x7FFED3FE,
                                            (u32) func_80800000_chhagstraindoorswitch,
                                            0x0,
                                            0x0,
                                            0x0};
