// Jamjars, move teacher in Terrydactyland: a wrapper around the shared mole logic (su/mole.c)
// with this world's move table and ActorInfo.
#include "ch/mole.h"

extern MoveData D_808000C0_chmole_prehist[];
extern D_808000D0 D_808000F0_chmole_prehist[];

// Message handler; forwards to the shared mole logic.
void func_80800000_chmole_prehist(Actor *actor, u32 event, u32 event_arg)
{
    _sumole_entrypoint_3(actor, event, event_arg, D_808000C0_chmole_prehist);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_prehist(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

// Update.
void func_80800090_chmole_prehist(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_prehist);
}

void *chmole_prehist_entrypoint_0()
{
    return D_808000F0_chmole_prehist;
}

extern void func_8010A730();
extern void func_80107C2C();
// Moves taught at this spot.
MoveData D_808000C0_chmole_prehist[3] = {0x1,   0xD8F, 0xD8D, 0xD8E, 0x26, 0xFF, 0x186, 0x8, 0x0,
                                         0x200, 0xD92, 0xD90, 0xD91, 0x27, 0xFF, 0x195, 0x9, 0x0,
                                         0x400, 0xD95, 0xD93, 0xD94, 0x28, 0xFF, 0x1A4, 0xA, 0x0};
D_808000D0 D_808000F0_chmole_prehist[1] = {0x2EA0186,
                                           0x1,
                                           0x0,
                                           (void *) func_80800090_chmole_prehist,
                                           0x0,
                                           (void *) func_8010A730,
                                           0x1F40000,
                                           0x0,
                                           0x0,
                                           0x80004,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (void *) func_80800024_chmole_prehist,
                                           (void *) func_80107C2C,
                                           0x80002202,
                                           (u32) func_80800000_chmole_prehist,
                                           0x0,
                                           0x0};
