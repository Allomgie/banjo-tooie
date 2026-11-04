// Bonfire in Terrydactyland's Bonfire Caverns, built on the shared fire effect: a hit puts it out
// for 6 seconds, then it relights.
#include "common.h"

extern int D_80800200_chbonfirecavern[];
extern u8 D_808002A0_chbonfirecavern[];
extern u8 D_80800248_chbonfirecavern[];
extern void func_800BABB8(s32, f32 *, s32, f32, void *);

typedef union {
    u8 *ptr;
    s32 value;
} BonfireEvent;

int chbonfirecavern_entrypoint_0()
{
    return (int) &D_80800200_chbonfirecavern;
}

void func_8080000C_chbonfirecavern(Actor *actor)
{
    extern void _chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    extern void func_80102FDC(Actor *, f32);

    _chfirefx_entrypoint_2(actor, actor->scale, (f32) actor->unk74_7, 30, 5);
    _chfirefx_entrypoint_6(actor, 500, 4000);
    func_80102FDC(actor, 1.0f);
}

// Message 0x3F (hit) puts the fire out for 6 seconds; 0x40 relights it at once.
s32 func_80800080_chbonfirecavern(Actor *actor, s32 msg, BonfireEvent event)
{
    Actor *unk_0;
    f32 *pos;
    switch (msg) {
        case 0x40:
            if (*(u16 *) (event.ptr + 0x18) & 1)
                func_8010114C(event.ptr, 0x92, 0);
            // Matching: empty block is needed for the match.
            if (event.ptr) {
            }
            func_80101FDC(actor, 2);
            break;
        case 0x3F:
            if (*(u16 *) (event.ptr + 0x18) & 1)
                func_8010114C(event.ptr, 0x92, 0);
            // Matching: empty block is needed for the match.
            if (event.ptr) {
            }
            if (actor->unk70_10 == 2) {
                pos = actor->position;
                _subaddieaudioquick_entrypoint_2(actor, pos, D_808002A0_chbonfirecavern);
                func_800BABB8(0, pos, 0, 1.0f, D_80800248_chbonfirecavern);
            }
            func_80101FDC(actor, 1);
            func_8010A570(actor);
            ((f32 *) actor->actorData)[3] = 6.0f;
            break;
        default:
            return _chfirefx_entrypoint_5(actor, msg, event.ptr);
    }
    return 1;
}

// Relights the fire when the extinguish countdown has run out.
void func_80800190_chbonfirecavern(u8 *actor)
{
    s32 expired;

    expired = func_800D9078(actor + 0x24);
    _chfirefx_entrypoint_3(actor);
    if ((expired != 0) && (((u32) (u16) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) == 1)) {
        func_80101FDC(actor, 2);
        func_8010A590(actor);
    }
}

// TU-NOTE: the .data below is defined in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80105834();
extern void _chfirefx_entrypoint_4();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800200_chbonfirecavern[18] = {0x31103A9,
                                      0x6FB0002,
                                      0x0,
                                      (u32) func_80800190_chbonfirecavern,
                                      (u32) func_80105834,
                                      (u32) _chfirefx_entrypoint_4,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x400,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_8080000C_chbonfirecavern,
                                      (u32) func_80107C2C,
                                      -0x7FFFBC00,
                                      (u32) func_80800080_chbonfirecavern,
                                      0x0};
u8 D_80800248_chbonfirecavern[88] = {
    0x10, 0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x16, 0x2,  0x0,  0x0,  0x2C, 0x0,  0x0,  0x0,
    0xFA, 0x0,  0x0,  0x0,  0x0,  0x1,  0x5E, 0x0,  0x0,  0x0,  0x1B, 0x0,  0x64, 0x0,  0x96,
    0x0,  0xB,  0x0,  0x0,  0x1,  0x2C, 0x0,  0x32, 0xFF, 0xF6, 0x0,  0x20, 0xC0, 0xC0, 0xC0,
    0xC0, 0x0,  0x22, 0x2,  0x0,  0x2,  0x99, 0x1,  0x33, 0x1,  0x66, 0x0,  0x15, 0x0,  0x19,
    0x0,  0x99, 0x0,  0x2A, 0x0,  0xC,  0x0,  0x19, 0x0,  0xCC, 0x1,  0x0,  0x0,  0x27, 0xFF,
    0x9C, 0xFF, 0x9C, 0x0,  0x64, 0x0,  0x64, 0x0,  0x28, 0x1,  0xCC, 0x0,  0x0};
u8 D_808002A0_chbonfirecavern[32] = {0x0,  0x13, 0x4, 0xDC, 0x0,  0xD, 0x0,  0xB3, 0x0, 0xCC, 0x0,
                                     0x15, 0x0,  0x0, 0x0,  0x80, 0x0, 0x66, 0x0,  0x1, 0x3,  0x20,
                                     0xF,  0xA0, 0x0, 0x0,  0x0,  0x0, 0x0,  0x0,  0x0, 0x0};
