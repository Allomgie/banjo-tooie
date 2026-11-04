// Jamjars' move-teacher spot for Cloud Cuckooland: wraps the shared mole logic (su/mole.c) with its
// message handler, init, update and per-world move table.
#include "ch/mole.h"

extern MoveData D_808000C0_chmole_cuckoo[];
extern D_808000D0 D_808000D0_chmole_cuckoo[];

// Message handler; forwards to the shared mole logic.
void func_80800000_chmole_cuckoo(Actor *actor, u32 event, u32 event_arg)
{
    _sumole_entrypoint_3(actor, event, event_arg, D_808000C0_chmole_cuckoo);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_cuckoo(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

// Update.
void func_80800090_chmole_cuckoo(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_cuckoo);
}

void *chmole_cuckoo_entrypoint_0()
{
    return D_808000D0_chmole_cuckoo;
}

extern void func_8010A730();
extern void func_80107C2C();
// Moves taught at this spot.
MoveData D_808000C0_chmole_cuckoo[1] = {0x200, 0xDB5, 0xDB3, 0xDB4, 0x2A, 0xFF, 0x2FD, 0x19, 0x0};
D_808000D0 D_808000D0_chmole_cuckoo[1] = {0x2EA0376,
                                          0x1,
                                          0x0,
                                          (void *) func_80800090_chmole_cuckoo,
                                          0x0,
                                          (void *) func_8010A730,
                                          0x1F40000,
                                          0x0,
                                          0x0,
                                          0x80004,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (void *) func_80800024_chmole_cuckoo,
                                          (void *) func_80107C2C,
                                          0x80002202,
                                          (u32) func_80800000_chmole_cuckoo,
                                          0x0,
                                          0x0};
