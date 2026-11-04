// Possibly "Squits", an ambient chattering critter that shows up only 20% of the time, plays
// random sound cues and speaks one of 10 lines when the player comes close.
#include "common.h"

extern int D_808006D8_chsquits[];
typedef struct {
    u8 pad_0[0x2C];
    f32 timer;
    u8 pad_30[0x3E];
    u16 bits_hi : 7;
    u16 bits_lo : 9;
} SquitsState;
extern f32 func_800DC178(f32, f32);
extern s32 func_800D90A4(f32 *);
extern s16 D_808006C4_chsquits[];
extern int func_800DC128(int a, int b);
extern s32 func_800DC298(f32);
extern u8 D_80800720_chsquits[];
typedef struct {
    s16 unk_0;
    s16 unk_2;
    f32 pitch;
    f32 time;
} SquitsCue37;
typedef struct {
    SquitsCue37 *cues;
    s32 count;
    f32 duration;
} SquitsSequence37;
extern SquitsSequence37 D_80800694_chsquits[];
extern s32 func_800D91EC(f32 *, f32);
extern void func_800C4B64(f32);
s32 func_808001A4_chsquits();
void func_80800358_chsquits();
void func_80800564_chsquits();
void func_808003C4_chsquits();

int *chsquits_entrypoint_0()
{
    return &D_808006D8_chsquits;
}

void func_8080000C_chsquits(SquitsState *state)
{
    state->bits_lo = 1;
    state->timer = func_800DC178(5.0f, 8.0f);
}

// Speaks a random line when the player is within 400 units.
void func_80800054_chsquits(Actor *actor)
{
    s32 unk_0;

    if (actor->unk70_10 == 1) {
        if (func_800D90A4(&actor->unk58) && func_8010CAC0(actor->position, 0x190)) {
            if (_subaddiedialog_entrypoint_11(actor->unk0, func_808001A4_chsquits(actor), 0,
                                              actor->position, 0x8F)) {
                func_80101FDC(actor, 2);
            }
            actor->unk58 = func_800DC178(5.0f, 8.0f);
        }
    }
    func_80800358_chsquits(actor);
}

// Message handler; on 0x95 (spawn) the squits exists only 20% of the time.
s32 func_80800108_chsquits(Actor *actor, s32 message, s32 unk_2)
{
    switch (message) {
        case 0x2E:
            func_80101FDC(actor, 1);
            break;
        case 0x95:
            if (!func_800DC298(0.2f)) {
                func_800BF744(1, 0);
                func_800FFAB0(actor);
                break;
            }
            func_800BF744(1, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

// Returns the next dialog text; each of the 10 is used once before any repeats.
s32 func_808001A4_chsquits(actor)
Actor *actor;
{
    u32 remaining;
    u32 i;
    s32 pick;
    s32 seen;
    remaining = 0;
    for (i = 0; i < 10; i++) {
        if (!(actor->actorData[6] & (1 << i))) {
            remaining++;
        }
    }
    if (remaining == 0) {
        actor->actorData[6] = 0;
        remaining = 10;
    }
    pick = func_800DC128(0, remaining);
    seen = 0;
    for (i = 0; i < 10; i++) {
        if (!(actor->actorData[6] & (1 << i))) {
            if (seen == pick) {
                actor->actorData[6] |= 1 << i;
                return D_808006C4_chsquits[i];
            }
            seen++;
        }
    }
    return D_808006C4_chsquits[0];
}

void func_80800358_chsquits(actor) Actor *actor;
{
    switch (actor->unk6C_0) {
        case 1:
            if (func_800D90A4((f32 *) &actor->actorData[5])) {
                actor->unk6C_0 = 0;
                func_80800564_chsquits(actor);
            }
            break;
        case 0:
            func_808003C4_chsquits(actor);
    }
}

s32 func_80800528_chsquits(f32 now, f32 prev, f32 cue_time);

// Advances the sound-cue timer and plays the cues that fall into this step.
void func_808003C4_chsquits(actor) Actor *actor;
{
    SquitsSequence37 *seq = &D_80800694_chsquits[actor->actorData[4]];
    f32 prev_time = *(f32 *) &actor->actorData[5];
    s32 finished = func_800D91EC((f32 *) &actor->actorData[5], seq->duration);
    s32 i;
    s32 offset;
    SquitsCue37 *cue;

    for (i = 0, offset = 0; i < seq->count;
         i++, offset += sizeof(SquitsCue37)) {
        cue = (SquitsCue37 *) ((u8 *) seq->cues + offset);
        if (func_80800528_chsquits(*(f32 *) &actor->actorData[5], prev_time, cue->time)) {
            func_800C4B7C(cue->unk_0);
            func_800C4B70(cue->unk_2);
            func_800C4B64(func_800DC178(-0.05f, 0.05f) + cue->pitch);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800720_chsquits);
        }
    }
    if (finished) {
        actor->unk6C_0 = 1;
        *(f32 *) &actor->actorData[5] = func_800DC178(5.0f, 8.0f);
    }
}

s32 func_80800528_chsquits(f32 now, f32 prev, f32 cue_time)
{
    if ((cue_time < now) && (prev <= cue_time)) {
        return TRUE;
    }
    return FALSE;
}

void func_80800564_chsquits(actor) Actor *actor;
{
    *(s32 *) ((char *) actor + 0x28) = func_800DC128(0, 4);
    *(f32 *) ((char *) actor + 0x2C) = 0.0f;
}

// TU-NOTE: the overlay's .data is defined here in C; values are from the ROM. The tables hold
// pointers to functions of this file, and IDO's assembler schedules some of them differently
// unless the tables are in the same unit.
// TU-NOTE: linker symbols inside objects (undefined_syms.us.txt): D_808006C6_chsquits =
// D_808006C4_chsquits + 0x2, D_808006CA_chsquits = D_808006C8_chsquits + 0x2.
// TU-NOTE: extern D_808006D8_chsquits is declared as int[] to match the object.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_808005B0_chsquits[12] = {0x42B55F0,  0x3F4CCCCD, 0x3E99999A, 0x42B55F0,
                               0x3F19999A, 0x3F4CCCCD, 0x55755F0,  0x3F99999A,
                               0x40400000, 0x4E455F0,  0x3FA66666, 0x40866666};
u32 D_808005E0_chsquits[6] = {0x42B55F0, 0x3F266666, 0x3E99999A, 0x4E455F0, 0x3FA66666, 0x3F800000};
u32 D_808005F8_chsquits[9] = {0x55955F0,  0x3FB33333, 0x0,        0x42B55F0, 0x3F333333,
                              0x3F19999A, 0x42B55F0,  0x3ECCCCCD, 0x40733333};
u32 D_8080061C_chsquits[30] = {
    0x42B55F0,  0x3FCCCCCD, 0x3E4CCCCD, 0x42B55F0,  0x3FB33333, 0x3ECCCCCD, 0x42B55F0,  0x3F99999A,
    0x3F19999A, 0x42B55F0,  0x3FCCCCCD, 0x3F4CCCCD, 0x42B55F0,  0x3FD9999A, 0x3F800000, 0x42B55F0,
    0x3FE66666, 0x3F99999A, 0x42B55F0,  0x3F99999A, 0x3FB33333, 0x42B7D00,  0x3EB33333, 0x3FCCCCCD,
    0x40955F0,  0x3F59999A, 0x4019999A, 0x4E455F0,  0x3FA66666, 0x404CCCCD};
SquitsSequence37 D_80800694_chsquits[4] = {
    (void *) &D_808005B0_chsquits, 0x4, 8.0f, (void *) &D_808005E0_chsquits, 0x2, 6.0f,
    (void *) &D_808005F8_chsquits, 0x3, 6.0f, (void *) &D_8080061C_chsquits, 0xA, 8.0f};
s16 D_808006C4_chsquits[2] = {0x136A, 0x136B};
u32 D_808006C8_chsquits[4] = {0x136C136D, 0x136E136F, 0x13771378, 0x1379137A};
int D_808006D8_chsquits[18] = {0x15804E9,
                               0x1,
                               0x0,
                               (u32) func_80800054_chsquits,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_8080000C_chsquits,
                               (u32) func_80107C2C,
                               -0x7FFFF9FE,
                               (u32) func_80800108_chsquits,
                               0x0};
u8 D_80800720_chsquits[16] = {0x0, 0x21, 0x0, 0x1E, 0x0, 0x1D, 0x0, 0x1,
                              0x1, 0xF4, 0x5, 0xDC, 0x0, 0x0,  0x0, 0x0};
