// Possibly a fire imp: a small flyer on the shared coaster-fly path follower that plays random
// chatter sounds when near the camera or player.
#include "common.h"

extern int D_808001F8_chfireimp[];
extern void func_8010A3E8(void *param_0, float param_1);
extern void *_sucoasterfly_entrypoint_1(void *param_0, int param_1);
extern void *_sucoasterfly_entrypoint_5(void *param_0);
extern f32 func_800DC178(f32, f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s16 D_80800240_chfireimp[];

int chfireimp_entrypoint_0()
{
    return (int) &D_808001F8_chfireimp;
}

void func_8080000C_chfireimp(Actor *actor)
{
    void *flight;
    flight = _sucoasterfly_entrypoint_1(actor, 4);
    if (flight != 0) {
        flight = _sucoasterfly_entrypoint_5(actor);
        *(float *) flight = 3.4f;
    }
    func_8010A3E8(actor, 0.65f);
}

void func_8080005C_chfireimp(Actor *actor)
{
    f32 *chatter_timer;
    s32 can_chatter;
    f32 ref_pos[3];

    chatter_timer = _sucoasterfly_entrypoint_5(actor);
    can_chatter = 1;
    _sucoasterfly_entrypoint_3(actor);
    // No chatter in states 10-16.
    switch (actor->unk70_10) {
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            can_chatter = 0;
    }
    if (can_chatter && func_800D90A4(chatter_timer)) {
        // Chatter only within 1800 units of the reference position (camera/player).
        func_8010D640(ref_pos);
        if (func_800EFFB4(actor->position, 1800.0f, ref_pos)) {
            // Next chatter in 2.4-3.4 s.
            *chatter_timer = func_800DC178(2.4f, 3.4f);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800240_chfireimp);
        }
    }
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
// and IDO's assembler schedules them differently unless defined in the same unit.
extern void func_80105834();
extern void _sucoasterfly_entrypoint_6();
extern void _sucoasterfly_entrypoint_2();
extern void _sucoasterfly_entrypoint_0();
extern void func_80107C2C();
extern void _sucoasterfly_entrypoint_4();
u32 D_80800170_chfireimp[34] = {0x0,        0x0,       0x40000000, 0x15A0001, 0x40800000, 0x1890001,
                                0x40800000, 0x1890001, 0x40800000, 0x1890001, 0x0,        0x0,
                                0x40C00000, 0x1000001, 0x40C00000, 0x1000001, 0x40000000, 0x15A0001,
                                0x40000000, 0x15A0001, 0x3F000000, 0x1650002, 0x3E4CCCCD, 0x3CD0001,
                                0x40000000, 0xF70002,  0x40000000, 0xF70084,  0x0,        0x0,
                                0x40800000, 0x1890001, 0x40800000, 0x1890001};
int D_808001F8_chfireimp[18] = {0x2AD0462,
                                0x6B80001,
                                (u32) &D_80800170_chfireimp,
                                (u32) func_8080005C_chfireimp,
                                (u32) func_80105834,
                                (u32) _sucoasterfly_entrypoint_6,
                                0x9C40000,
                                0x3F800000,
                                0x0,
                                0x3271329,
                                (u32) _sucoasterfly_entrypoint_2,
                                (u32) _sucoasterfly_entrypoint_0,
                                0x0,
                                (u32) func_8080000C_chfireimp,
                                (u32) func_80107C2C,
                                -0x7FCDBFA3,
                                (u32) _sucoasterfly_entrypoint_4,
                                -0x7FEDBA9C};
s16 D_80800240_chfireimp[16] = {0x13, 0x63C, 0xD, 0xF3, 0x10C, 0x1, 0x190, 0x708,
                                0x0,  0x0,   0x0, 0x0,  0x0,   0x0, 0x0,   0x0};
