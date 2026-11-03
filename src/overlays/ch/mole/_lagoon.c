#include "ch/mole.h"

extern MoveData D_808000C0_chmole_lagoon[];
extern D_808000D0 D_808000F0_chmole_lagoon[];

void func_80800000_chmole_lagoon(Actor *a0, u32 a1, u32 a2)
{
    _sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_lagoon);
}

void func_80800024_chmole_lagoon(Actor *a0)
{
    _sumole_entrypoint_0(a0, 0);
    a0->unk74_7 = a0->unk74_7 - 0x32;
    a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_lagoon(Actor *a0)
{
    _sumole_entrypoint_4(a0, D_808000C0_chmole_lagoon);
}

void *chmole_lagoon_entrypoint_0()
{
    return D_808000F0_chmole_lagoon;
}

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
