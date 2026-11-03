#include "ch/mole.h"

extern MoveData D_808000C0_chmole_mine[];
extern D_808000D0 D_808000E0_chmole_mine[];

void func_80800000_chmole_mine(Actor *a0, u32 a1, u32 a2)
{
    _sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_mine);
}

void func_80800024_chmole_mine(Actor *a0)
{
    _sumole_entrypoint_0(a0, 0);
    a0->unk74_7 = a0->unk74_7 - 0x32;
    a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_mine(Actor *a0)
{
    _sumole_entrypoint_4(a0, D_808000C0_chmole_mine);
}

void *chmole_mine_entrypoint_0()
{
    return D_808000E0_chmole_mine;
}

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
