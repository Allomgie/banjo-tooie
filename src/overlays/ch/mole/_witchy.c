// Jamjars, move teacher in Witchyworld: a wrapper around the shared mole logic (su/mole.c)
// with this world's move table and ActorInfo.
#include "ch/mole.h"

extern MoveData D_808000C0_chmole_witchy[];
extern D_808000D0 D_808000F0_chmole_witchy[];

// Message handler.
void func_80800000_chmole_witchy(Actor *actor, u32 msg, u32 arg)
{
    _sumole_entrypoint_3(actor, msg, arg, D_808000C0_chmole_witchy);
}

// Init: variant - 0x32 selects the move slot.
void func_80800024_chmole_witchy(Actor *actor)
{
    _sumole_entrypoint_0(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 0x32;
    actor->unk54 = actor->unk74_7;
}

// Update.
void func_80800090_chmole_witchy(Actor *actor)
{
    _sumole_entrypoint_4(actor, D_808000C0_chmole_witchy);
}

void *chmole_witchy_entrypoint_0()
{
    return D_808000F0_chmole_witchy;
}

extern void func_8010A730();
extern void func_80107C2C();
MoveData D_808000C0_chmole_witchy[3] = {0x1,   0xD63, 0xD64, 0xD65, 0x1B, 0xFF, 0xB4, 0x5, 0x0,
                                        0x1,   0xD66, 0xD67, 0xD68, 0x1C, 0xFF, 0xA0, 0x6, 0x0,
                                        0x200, 0xD69, 0xD6A, 0xD6B, 0x29, 0xFF, 0xAA, 0x7, 0x0};
D_808000D0 D_808000F0_chmole_witchy[1] = {0x2EA0182,
                                          0x1,
                                          0x0,
                                          (void *) func_80800090_chmole_witchy,
                                          0x0,
                                          (void *) func_8010A730,
                                          0x1F40000,
                                          0x0,
                                          0x0,
                                          0x80004,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (void *) func_80800024_chmole_witchy,
                                          (void *) func_80107C2C,
                                          0x80002202,
                                          (u32) func_80800000_chmole_witchy,
                                          0x0,
                                          0x0};
