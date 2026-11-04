// Jamjars' move-teacher spot for Grunty Industries: wraps the shared mole logic (su/mole.c)
// with its message handler, init, update and per-world move table.
#include "ch/mole.h"

extern MoveData D_808000C0_chmole_factory[];
extern D_808000D0 D_808000F0_chmole_factory[];

// Message handler; forwards to the shared mole logic.
void func_80800000_chmole_factory(Actor *actor, u32 event, u32 event_arg)
{
    _sumole_entrypoint_3(actor, event, event_arg, D_808000C0_chmole_factory);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_factory(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

// Update.
void func_80800090_chmole_factory(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_factory);
}

void *chmole_factory_entrypoint_0()
{
    return D_808000F0_chmole_factory;
}

extern void func_8010A730();
extern void func_80107C2C();
// Moves taught at this spot.
MoveData D_808000C0_chmole_factory[3] = {0x1,   0xD9E, 0xD9C, 0xD9D, 0x25, 0xFF, 0x1F9, 0x16, 0x0,
                                         0x200, 0xDA1, 0xD9F, 0xDA0, 0x23, 0xFF, 0x20D, 0x17, 0x0,
                                         0x400, 0xDA4, 0xDA2, 0xDA3, 0x24, 0xFF, 0x221, 0x18, 0x0};
D_808000D0 D_808000F0_chmole_factory[1] = {0x2EA0185,
                                           0x1,
                                           0x0,
                                           (void *) func_80800090_chmole_factory,
                                           0x0,
                                           (void *) func_8010A730,
                                           0x1F40000,
                                           0x0,
                                           0x0,
                                           0x80004,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (void *) func_80800024_chmole_factory,
                                           (void *) func_80107C2C,
                                           0x80002202,
                                           (u32) func_80800000_chmole_factory,
                                           0x0,
                                           0x0};
