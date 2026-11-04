#include "common.h"

extern void *D_80800100_chfactorysmoke;
extern int D_80800148_chfactorysmoke[];
extern void func_800BBCB8(int, int, float, int, int *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9078(f32 *);

int chfactorysmoke_entrypoint_0()
{
    return &D_80800100_chfactorysmoke;
}

// Starts the countdown to the first puff.
void func_8080000C_chfactorysmoke(u8 *actor)
{
    *(f32 *) (actor + 0x58) = func_800DC178(0.55f, 0.65f);
}

// Every 0.55-0.65 s: spawn a puff and restart the countdown.
void func_80800044_chfactorysmoke(Actor *actor)
{
    if (actor->unk70_10 == 1 && func_800D9078(&actor->unk58)) {
        func_808000A8_chfactorysmoke(actor);
        actor->unk58 = func_800DC178(0.55f, 0.65f);
    }
}

// Spawns one puff from the emitter script.
int func_808000A8_chfactorysmoke(s32 actor)
{
    s32 emitter;
    emitter = &D_80800148_chfactorysmoke;
    func_800BBCB8(actor + 4, 0, 1.0f, 4, emitter);
}

extern void func_80105834();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to
// functions of this file; IDO's assembler schedules them differently otherwise. Values come from the ROM.
extern void func_8010A730();
extern void func_80107C2C();
void *D_80800100_chfactorysmoke = (void *) 0x009D03D5;
static u32 D_80800100_chfactorysmoke_rest[17] = {0x1,
                                                 0x0,
                                                 (u32) func_80800044_chfactorysmoke,
                                                 (u32) func_80105834,
                                                 (u32) func_8010A730,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_8080000C_chfactorysmoke,
                                                 (u32) func_80107C2C,
                                                 0x80000602,
                                                 0x0,
                                                 0x0};
int D_80800148_chfactorysmoke[26] = {
    0x1D09DD,    0x180000,  0xF66,    0x10D40001, 0x0,      0xFA0000,  0x15E,
    0x2CFFCD,    0x1C2FFBF, 0x3C0226, 0x46000B,   0x6D00C4, 0x0,       0x1F80C4,
    -0x6BFFFFEA, 0x2000027, 0xD001A,  0x31002A,   0x220240, 0x2B0053A, 0x6750015,
    0xCC,        0x2A0000,  0x260180, 0x1C00000,  0x0};
