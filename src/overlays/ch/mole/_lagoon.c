#include "ch/mole.h"

extern MoveData D_808000C0_chmole_lagoon[];
extern D_808000D0 D_808000F0_chmole_lagoon[];

void func_80800000_chmole_lagoon(Actor *actor, u32 message, u32 arg)
{
    _sumole_entrypoint_3(actor, message, arg, D_808000C0_chmole_lagoon);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_lagoon(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

void func_80800090_chmole_lagoon(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_lagoon);
}

void *chmole_lagoon_entrypoint_0()
{
    return D_808000F0_chmole_lagoon;
}

// TU-NOTE: the overlay .data is defined in C; its tables point to functions of this file, and IDO
// schedules some of them differently unless the tables are in the same unit. Values are from the ROM.
extern void func_8010A730();
extern void func_80107C2C();
MoveData D_808000C0_chmole_lagoon[3] = {0x1,   0xD85, 0xD83, 0xD84, 0x1E, 0xFF, 0x122, 0x11, 0x3,
                                        0x1,   0xD88, 0xD86, 0xD87, 0x1F, 0xFF, 0x113, 0x12, 0x0,
                                        0x400, 0xD8B, 0xD89, 0xD8A, 0x1D, 0xFF, 0x109, 0x13, 0x0};
D_808000D0 D_808000F0_chmole_lagoon[1] = {0x2EA0315,
                                          0x1,
                                          0x0,
                                          (void *) func_80800090_chmole_lagoon,
                                          0x0,
                                          (void *) func_8010A730,
                                          0x1F40000,
                                          0x0,
                                          0x0,
                                          0x80004,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (void *) func_80800024_chmole_lagoon,
                                          (void *) func_80107C2C,
                                          0x80002202,
                                          (u32) func_80800000_chmole_lagoon,
                                          0x0,
                                          0x0};
