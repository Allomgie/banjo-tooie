// Most likely the "warrior" baddie: data plus a tiny init that hands the actor to the shared
// su/coaster walking AI with scale 1.5 and a speed factor of 0.4.
#include "common.h"

// TU-NOTE: the overlay's .data is defined in C below, values taken from the ROM. The tables point to
// functions of this file, and IDO's assembler schedules some of them differently unless the tables
// are in the same unit. D_80800128_chwarriorbaddy is declared as int[] to match the object.

extern int D_80800128_chwarriorbaddy[];
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 unk_78 : 1;
    u32 pad_2 : 5;
} WarriorCoasterFlags;
extern s32 _sucoaster_entrypoint_0(Actor *, s32);
extern void func_80102FDC(Actor *, f32);
extern void func_8010A3E8(Actor *, f32);

int *chwarriorbaddy_entrypoint_0()
{
    return &D_80800128_chwarriorbaddy;
}

// Hands the actor to the shared coaster AI, scales it by 1.5 and sets the speed factor to 0.4.
void func_8080000C_chwarriorbaddy(Actor *actor)
{
    if (_sucoaster_entrypoint_0(actor, 0)) {
        func_80102FDC(actor, actor->scale * 1.5f);
        func_8010A3E8(actor, 0.4f);
        if (!((WarriorCoasterFlags *) actor)->unk_78)
            _sucoaster_entrypoint_10(actor, 2);
    }
}

extern void _sucoaster_entrypoint_2();
extern void func_80105834();
extern void _sucoaster_entrypoint_20();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
extern void _sucoaster_entrypoint_21();
u32 D_80800090_chwarriorbaddy[38] = {
    0x0,        0x0,       0x40D0F5C3, 0x1A70001, 0x40D0F5C3, 0x1A70001, 0x3FB33333, 0x1A80001,
    0x3F800000, 0x1AA0001, 0x3FB33333, 0x1A80001, 0x3FB33333, 0x1A80001, 0x3F547AE1, 0x1AC0002,
    0x3F800000, 0x1AA0001, 0x3F800000, 0x3A30002, 0x3F800000, 0x1AA0001, 0x3F4CCCCD, 0x4A40002,
    0x3FA8F5C3, 0x1A90002, 0x3FA8F5C3, 0x1A90084, 0x40D0F5C3, 0x1A70001, 0x3FB33333, 0x1A80020,
    0x0,        0x0,       0x40D0F5C3, 0x1A70001, 0x3F800000, 0x1AA0001};
int D_80800128_chwarriorbaddy[18] = {0x15A0112,
                                     0x6670001,
                                     (u32) &D_80800090_chwarriorbaddy,
                                     (u32) _sucoaster_entrypoint_2,
                                     (u32) func_80105834,
                                     (u32) _sucoaster_entrypoint_20,
                                     0xBB80000,
                                     0x3F4CCCCD,
                                     0x0,
                                     0x43850321,
                                     (u32) _sucoaster_entrypoint_1,
                                     (u32) _sucoasterhit_entrypoint_0,
                                     0x0,
                                     (u32) func_8080000C_chwarriorbaddy,
                                     (u32) func_80107C2C,
                                     -0x7BCDAFE3,
                                     (u32) _sucoaster_entrypoint_21,
                                     -0x7FEDBAB0};
