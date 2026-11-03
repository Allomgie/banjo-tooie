#include "ch/mole.h"

extern MoveData D_808000C0_chmole_hailfire[];
extern D_808000D0 D_808000E0_chmole_hailfire[];

void func_80800000_chmole_hailfire(Actor *a0, u32 a1, u32 a2)
{
    _sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_hailfire);
}

void func_80800024_chmole_hailfire(Actor *a0)
{
    _sumole_entrypoint_0(a0, 0);
    a0->unk74_7 = a0->unk74_7 - 0x32;
    a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_hailfire(Actor *a0)
{
    _sumole_entrypoint_4(a0, D_808000C0_chmole_hailfire);
}

void *chmole_hailfire_entrypoint_0()
{
    return D_808000E0_chmole_hailfire;
}

extern void func_8010A730();
extern void func_80107C2C();
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
