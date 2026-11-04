// Most likely Lil Terry, a small flying Terrydactyland baddie on the generic su/coaster/fly engine.
// Its update runs variant 0 and sets a factor of 0.5.
#include "common.h"

extern int D_808000C8_chlilterry[];

int chlilterry_entrypoint_0()
{
    return (int) &D_808000C8_chlilterry;
}

// Runs the flying-baddie engine (variant 0) and sets the factor at actor+0x92 to 0.5.
int func_8080000C_chlilterry(Actor *actor)
{
    _sucoasterfly_entrypoint_1(actor, 0);
    func_8010A3E8(actor, 0x3F000000);
}

extern void _sucoasterfly_entrypoint_3();
extern void func_80105834();
extern void _sucoasterfly_entrypoint_6();
extern void _sucoasterfly_entrypoint_2();
extern void _sucoasterfly_entrypoint_0();
extern void func_80107C2C();
extern void _sucoasterfly_entrypoint_4();
u32 D_80800040_chlilterry[34] = {
    0x0,        0x0,        0x3F147AE1, 0x1680001,  0x3F147AE1, 0x1680001,  0x3F147AE1,
    0x1680001,  0x3F147AE1, 0x1680001,  0x3F19999A, 0x1670002,  0x3EE66666, 0x1660001,
    0x3EE66666, 0x1660001,  0x3F147AE1, 0x1680001,  0x3F147AE1, 0x1680001,  0x3F000000,
    0x1650002,  0x3EA8F5C3, 0x52B0101,  0x3F8CCCCD, 0x1640002,  0x3F570A3D, 0x1640084,
    0x3F147AE1, 0x1680001,  0x3F147AE1, 0x1680001,  0x3F147AE1, 0x1680001};
int D_808000C8_chlilterry[18] = {0x2FD039A,
                                 0x6D70001,
                                 (u32) &D_80800040_chlilterry,
                                 (u32) _sucoasterfly_entrypoint_3,
                                 (u32) func_80105834,
                                 (u32) _sucoasterfly_entrypoint_6,
                                 0x9C40000,
                                 0x40000000,
                                 0x0,
                                 0x3250329,
                                 (u32) _sucoasterfly_entrypoint_2,
                                 (u32) _sucoasterfly_entrypoint_0,
                                 0x0,
                                 (u32) func_8080000C_chlilterry,
                                 (u32) func_80107C2C,
                                 -0x7FCDBFE3,
                                 (u32) _sucoasterfly_entrypoint_4,
                                 -0x7FEDBA9C};
