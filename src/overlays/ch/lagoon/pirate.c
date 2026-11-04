// Probably a small Jolly Roger's Lagoon pirate enemy on the generic su/coaster walking engine.
// Its update runs variant 0 with animation speed 1.5 and a factor of 0.8.
#include "common.h"

extern int D_808000F8_chlagoonpirate[];
extern void _sucoaster_entrypoint_0();
extern void func_80102FDC(u8 *, f32);
extern void func_8010A3E8(u8 *, f32);

int chlagoonpirate_entrypoint_0()
{
    return (int) &D_808000F8_chlagoonpirate;
}

// Update: runs the shared coaster baddie, then sets anim speed 1.5x and a 0.8 factor.
void func_8080000C_chlagoonpirate(u8 *actor)
{
    _sucoaster_entrypoint_0(actor, 0);
    func_80102FDC(actor, *(f32 *) (actor + 0x38) * 1.5f);
    func_8010A3E8(actor, 0.8f);
}

extern void _sucoaster_entrypoint_2();
extern void func_80105834();
extern void _sucoaster_entrypoint_20();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
extern void _sucoaster_entrypoint_21();
u32 D_80800060_chlagoonpirate[38] = {
    0x0,        0x0,       0x40533333, 0x3500001, 0x40533333, 0x3500001, 0x3F99999A, 0x3390001,
    0x3F19999A, 0x33A0001, 0x3F99999A, 0x3390001, 0x3F99999A, 0x3390001, 0x3F99999A, 0x33B0002,
    0x3F19999A, 0x33A0001, 0x3F4CCCCD, 0x33C0002, 0x3F19999A, 0x33A0001, 0x3ECCCCCD, 0x34F0002,
    0x3FE66666, 0x33D0002, 0x3FE66666, 0x33D0084, 0x40533333, 0x3500001, 0x3F99999A, 0x3390020,
    0x0,        0x0,       0x40533333, 0x3500001, 0x3F19999A, 0x33A0001};
int D_808000F8_chlagoonpirate[18] = {0x32B03C9,
                                     0x7FE0001,
                                     (u32) &D_80800060_chlagoonpirate,
                                     (u32) _sucoaster_entrypoint_2,
                                     (u32) func_80105834,
                                     (u32) _sucoaster_entrypoint_20,
                                     0xBB80000,
                                     0x3F4CCCCD,
                                     0x0,
                                     0x43050329,
                                     (u32) _sucoaster_entrypoint_1,
                                     (u32) _sucoasterhit_entrypoint_0,
                                     0x0,
                                     (u32) func_8080000C_chlagoonpirate,
                                     (u32) func_80107C2C,
                                     -0x7BCDAFE3,
                                     (u32) _sucoaster_entrypoint_21,
                                     -0x7FEDBAB0};
