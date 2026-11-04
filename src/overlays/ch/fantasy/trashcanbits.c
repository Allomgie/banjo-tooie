// Most likely the Cloud Cuckooland trash can: a lid (chdoormake door, opens at entrance 0x11) and
// the chswitch that opens it, setting flag 0x9FF and notifying actor 0x40C.
#include "common.h"

extern int D_80800240_chfantasytrashcanbits[];
extern int D_80800288_chfantasytrashcanbits[];
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern f32 func_800EFC7C(f32 *, f32 *);

// Trash can lid init, built on the door framework; starts open if entered via entrance 0x11.
void func_80800000_chfantasytrashcanbits(Actor *actor)
{
    if (func_800EA090(actor) == 0x11) {
        func_80101FDC(actor, 4);
    } else {
        func_80101FDC(actor, 1);
    }
    _chdoormake_entrypoint_3(actor, actor->rotation[1], 90.0f, actor->scale * 325.0f, 0x80A,
                             0);
    _chdoormake_entrypoint_8(actor, 2);
    _chdoormake_entrypoint_5(actor, 2.0f);
    _chdoormake_entrypoint_9(actor, 0, 7, 16);
    if (!func_800F64A4(func_800F54E4(), 0x400) && actor->unk70_10 == 4) {
        func_8010108C(actor, 8, 0);
    }
}

void func_808000EC_chfantasytrashcanbits(Actor *actor)
{
    f32 player_pos[3];

    switch (actor->unk70_10) {
        case 4:
            func_800F5A00(func_800F54E4(), player_pos);
            _subaddieDll_entrypoint_4(actor, 1);
            if (func_800EFC7C(actor->position, player_pos) > 4000000.0f) {
                func_8010108C(actor, 8, 0);
            }
            break;
        case 1:
            _subaddieDll_entrypoint_4(actor, 0);
    }
    _chdoor_entrypoint_0(actor);
}

int chfantasytrashcanbits_entrypoint_0()
{
    return (int) &D_80800240_chfantasytrashcanbits;
}

// Switch that opens the lid.
s32 func_808001A8_chfantasytrashcanbits(Actor *this)
{
    _chswitch_entrypoint_7(this, 0x9FF);
    _chswitch_entrypoint_8(this, 0x400);
}

s32 func_808001D8_chfantasytrashcanbits(s32 actor, s32 msg, s32 arg)
{
    if (msg == 7) {
        func_80101180(0x40C);
    }
    _chswitch_entrypoint_10(actor, msg, arg);
}

int chfantasytrashcanbits_entrypoint_1()
{
    return (int) &D_80800288_chfantasytrashcanbits;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise.
// D_80800240_chfantasytrashcanbits and D_80800288_chfantasytrashcanbits are int[].
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern void _chswitch_entrypoint_6();
int D_80800240_chfantasytrashcanbits[18] = {0xAC040C,
                                            0x8CC0001,
                                            0x0,
                                            (u32) func_808000EC_chfantasytrashcanbits,
                                            (u32) func_80105834,
                                            (u32) func_80101870,
                                            0x9C40000,
                                            0x0,
                                            0x0,
                                            0x800,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_80800000_chfantasytrashcanbits,
                                            (u32) func_80107C2C,
                                            -0x7FFFDBFE,
                                            (u32) _chdoor_entrypoint_1,
                                            0x0};
int D_80800288_chfantasytrashcanbits[18] = {0x343040B,
                                            0x7B90001,
                                            -0x7FEE5DE0,
                                            (u32) _chswitch_entrypoint_6,
                                            (u32) func_80105834,
                                            (u32) func_80101870,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x808,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_808001A8_chfantasytrashcanbits,
                                            (u32) func_80107C2C,
                                            -0x7FFFD3FE,
                                            (u32) func_808001D8_chfantasytrashcanbits,
                                            0x0};
