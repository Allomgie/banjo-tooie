// Jamjars' move-teacher spot for Hailfire Peaks: wraps the shared mole logic (su/mole.c) with its
// message handler, init, update and per-world move table.
#include "ch/mole.h"

extern MoveData D_808000C0_chmole_hailfire[];
extern D_808000D0 D_808000E0_chmole_hailfire[];

// Message handler; forwards to the shared mole logic.
void func_80800000_chmole_hailfire(Actor *actor, u32 event, u32 event_arg)
{
    _sumole_entrypoint_3(actor, event, event_arg, D_808000C0_chmole_hailfire);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_hailfire(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

// Update.
void func_80800090_chmole_hailfire(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_hailfire);
}

void *chmole_hailfire_entrypoint_0()
{
    return D_808000E0_chmole_hailfire;
}

extern void func_8010A730();
extern void func_80107C2C();
// Moves taught at this spot.
MoveData D_808000C0_chmole_hailfire[2] = {0x200, 0xD98, 0xD96, 0xD97, 0x21, 0xFF, 0x280, 0x14, 0x0,
                                          0x400, 0xD9B, 0xD99, 0xD9A, 0x22, 0xFF, 0x294, 0x15, 0x0};
D_808000D0 D_808000E0_chmole_hailfire[1] = {0x2EA0184,
                                            0x1,
                                            0x0,
                                            (void *) func_80800090_chmole_hailfire,
                                            0x0,
                                            (void *) func_8010A730,
                                            0x1F40000,
                                            0x0,
                                            0x0,
                                            0x80004,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (void *) func_80800024_chmole_hailfire,
                                            (void *) func_80107C2C,
                                            0x80002202,
                                            (u32) func_80800000_chmole_hailfire,
                                            0x0,
                                            0x0};
