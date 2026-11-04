// Possibly a bouncy object in Cloud Cuckooland: only two ActorInfo descriptors and a callback that
// places the actor at a fixed world position; the real behaviour is likely in generic core code.
#include "common.h"

extern int D_80800060_chfantasybounce[];
extern int D_808000A8_chfantasybounce[];

// Sets the actor position to a fixed world position.
s32 func_80800000_chfantasybounce(f32 pos_out[4])
{
    func_800EFA4C(pos_out + 1, 0xC62C8A36, 0x4604CA00, 0xC6149236);
}

int *chfantasybounce_entrypoint_0()
{
    return &D_80800060_chfantasybounce;
}

int chfantasybounce_entrypoint_1()
{
    return (int) &D_808000A8_chfantasybounce;
}

// TU-NOTE: the overlay .data is defined in C here (values taken from the ROM); IDO schedules some
// functions differently unless these tables share the unit. The extern declarations at the top
// were adjusted to the object types (same addresses).
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
int D_80800060_chfantasybounce[18] = {0x15804C6,
                                      0x62C0001,
                                      0x0,
                                      (u32) func_80102EC0,
                                      (u32) func_80102EC0,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x1C0C,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800000_chfantasybounce,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      0x0,
                                      0x0};
int D_808000A8_chfantasybounce[18] = {0x15804C7,
                                      0x62D0001,
                                      0x0,
                                      (u32) func_80102EC0,
                                      (u32) func_80102EC0,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x1C0C,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      0x0,
                                      0x0};
