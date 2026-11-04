#include "ch/mole.h"

extern MoveData D_808000C0_chmole_mine[];
extern D_808000D0 D_808000E0_chmole_mine[];

void func_80800000_chmole_mine(Actor *actor, u32 message, u32 arg)
{
    _sumole_entrypoint_3(actor, message, arg, D_808000C0_chmole_mine);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_mine(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

void func_80800090_chmole_mine(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_mine);
}

void *chmole_mine_entrypoint_0()
{
    return D_808000E0_chmole_mine;
}

// TU-NOTE: the overlay .data is defined in C; its tables point to functions of this file, and IDO
// schedules some of them differently unless the tables are in the same unit. Values are from the ROM.
extern void func_8010A730();
extern void func_80107C2C();
MoveData D_808000C0_chmole_mine[2] = {0x1,   0xD4E, 0xD4C, 0xD4D, 0x19, 0xFF, 0x55, 0xC, 0x0,
                                      0x101, 0xD51, 0xD4F, 0xD50, 0x1A, 0xFF, 0x5F, 0xD, 0x0};
D_808000D0 D_808000E0_chmole_mine[1] = {0x2EA01A8,
                                        0x1,
                                        0x0,
                                        (void *) func_80800090_chmole_mine,
                                        0x0,
                                        (void *) func_8010A730,
                                        0x1F40000,
                                        0x0,
                                        0x0,
                                        0x80004,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (void *) func_80800024_chmole_mine,
                                        (void *) func_80107C2C,
                                        0x80002202,
                                        (u32) func_80800000_chmole_mine,
                                        0x0,
                                        0x0};
