#include "common.h"

extern int D_808000C8_chbigfoot[];
extern void _sucoaster_entrypoint_0(s32, s32);

int chbigfoot_entrypoint_0()
{
    return (int) &D_808000C8_chbigfoot;
}

// Hands the actor to the shared coaster baddie behaviour, variant 0.
void func_8080000C_chbigfoot(s32 actor)
{
    _sucoaster_entrypoint_0(actor, 0);
}

extern void _sucoaster_entrypoint_2();
extern void func_80105834();
extern void _sucoaster_entrypoint_20();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
extern void _sucoaster_entrypoint_21();
u32 D_80800030_chbigfoot[38] = {
    0x0,        0x0,       0x410E8F5C, 0x3810001, 0x410E8F5C, 0x3810001, 0x3FEA3D71, 0x3830001,
    0x3F800000, 0x3840001, 0x3FEA3D71, 0x3830001, 0x3FEA3D71, 0x3830001, 0x3F9AE148, 0x3820002,
    0x3F800000, 0x3840001, 0x3F666666, 0x3860002, 0x3F800000, 0x3840001, 0x3F4CCCCD, 0x3850002,
    0x3FA00000, 0x3870002, 0x3FA00000, 0x3870084, 0x410E8F5C, 0x3810001, 0x3FEA3D71, 0x3830020,
    0x0,        0x0,       0x410E8F5C, 0x3810001, 0x3F800000, 0x3840001};
int D_808000C8_chbigfoot[18] = {0xAA03E5,
                                0x81C0001,
                                (u32) &D_80800030_chbigfoot,
                                (u32) _sucoaster_entrypoint_2,
                                (u32) func_80105834,
                                (u32) _sucoaster_entrypoint_20,
                                0xBB80000,
                                0x3FC00000,
                                0x0,
                                0x43050321,
                                (u32) _sucoaster_entrypoint_1,
                                (u32) _sucoasterhit_entrypoint_0,
                                0x0,
                                (u32) func_8080000C_chbigfoot,
                                (u32) func_80107C2C,
                                -0x7BCDAFE3,
                                (u32) _sucoaster_entrypoint_21,
                                -0x7FEDBAB0};
