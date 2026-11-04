// Actor fade and tint: get/set alpha, request fade-in/out (or out and delete), per-frame fade
// update (fixed step or timed), and set/get the RGB tint, including from the ambient colour.
#include "su/baddiefade.h"

// TU-NOTE: the .data of this overlay is defined in C here; values come from the ROM.
typedef struct {
    u8 pad_0[0x74];
    u32 unk_74 : 27;
    u32 timed : 1; // fade runs over a duration instead of a fixed step
    u32 unk_74b : 4;
} FadeFlags49;
extern f32 func_800D8FF8(void);
typedef struct {
    u8 pad[0x70];
    u32 pad70 : 29;
    u32 flag : 1;
    u32 rest : 2;
} FadeS;
extern void func_800F2F20();
extern void func_800F2F3C();
extern void func_800EFA88();
extern void func_800C87DC();
int func_80800450_subaddiefade();

// Returns the actor's alpha.
subaddiefade_entrypoint_0(u8 *actor)
{
    return actor[0x9B];
}

// Sets alpha and cancels any running fade.
void subaddiefade_entrypoint_1(u8 *actor, unsigned int alpha)
{
    actor[0x9B] = alpha;
    actor[0x79] &= ~3U;
}

// Starts a fade-in from alpha 0.
void subaddiefade_entrypoint_2(u8 *actor)
{
    actor[0x9B] = 0;
    actor[0x79] = (actor[0x79] & 0xFFFC) | 1;
}

// Starts a fade-out and deletes the actor at alpha 0.
void subaddiefade_entrypoint_3(u8 *actor)
{
    actor[0x79] = (actor[0x79] & 0xFFFC) | 2;
}

// Starts a fade-in from the current alpha.
void subaddiefade_entrypoint_4(u8 *actor)
{
    actor[0x79] = (actor[0x79] & 0xFFFC) | 1;
}

// Starts a fade-out without deleting the actor.
void subaddiefade_entrypoint_5(u8 *actor)
{
    // Matching: the 0xFFFFu mask is needed for the match.
    actor[121] = (actor[121] & 0xFFFFu) | 3;
}

// Adds delta to alpha, clamped to 0..255.
void subaddiefade_entrypoint_6(u8 *actor, s32 delta)
{
    s32 sum = actor[0x9B] + delta;
    // Matching: the repeated clamp expression is needed for the match.
    actor[0x9B] =
        (((sum > 0xFF) ? 0xFF : sum) < 0) ? 0 : ((sum > 0xFF) ? 0xFF : sum);
}

// Per-frame fade update. Fade mode is in the low 2 bits at +0x78:
// 1 = in, 2 = out and delete, 3 = out.
// Timed mode: actorData[0] is the duration, actorData[1] the elapsed time.
void subaddiefade_entrypoint_7(Actor *actor)
{
    s32 new_alpha;
    if (((FadeFlags49 *) actor)->timed) {
        *(f32 *) &actor->actorData[1] += func_800D8FF8();
        if (*(f32 *) &actor->actorData[0] < *(f32 *) &actor->actorData[1])
            *(f32 *) &actor->actorData[1] = *(f32 *) &actor->actorData[0];
        switch (*(u16 *) ((u8 *) actor + 0x78) & 3) {
            case 1:
                if (*(f32 *) &actor->actorData[0] != 0.0f)
                    actor->alpha =
                        (s32) ((*(f32 *) &actor->actorData[1] / *(f32 *) &actor->actorData[0]) *
                               255.0f);
                else
                    actor->alpha = 255;
                if (actor->alpha == 255)
                    *((u8 *) actor + 0x79) &= ~3;
                break;
            case 2:
                if (*(f32 *) &actor->actorData[0] != 0.0f)
                    actor->alpha =
                        255 -
                        (s32) ((*(f32 *) &actor->actorData[1] / *(f32 *) &actor->actorData[0]) *
                               255.0f);
                else
                    actor->alpha = 0;
                if (actor->alpha == 0)
                    *((u8 *) actor + 0x79) &= ~3;
        }
    } else {
        switch (*(u16 *) ((u8 *) actor + 0x78) & 3) {
            case 1:
                new_alpha = actor->alpha + 7;
                if (new_alpha >= 256)
                    actor->alpha = 255;
                else
                    actor->alpha = new_alpha;
                if (actor->alpha == 255)
                    *((u8 *) actor + 0x79) &= ~3;
                break;
            case 2:
                new_alpha = actor->alpha - 7;
                if (new_alpha < 0)
                    actor->alpha = 0;
                else
                    actor->alpha = new_alpha;
                if (actor->alpha == 0 && !func_80107070(actor, 3))
                    func_800FFAB0(actor);
                break;
            case 3:
                new_alpha = actor->alpha - 7;
                if (new_alpha < 0)
                    actor->alpha = 0;
                else
                    actor->alpha = new_alpha;
                if (actor->alpha == 0)
                    *((u8 *) actor + 0x79) &= ~3;
        }
    }
}

// Sets alpha, clamped to 0..255.
void subaddiefade_entrypoint_8(u8 *actor, s32 alpha)
{
    s32 clamped;
    clamped = func_800F0D90(alpha, 0, 0xFF);
    actor[0x9B] = (u8) clamped;
}

s32 subaddiefade_entrypoint_9(s32 actor, s32 tint)
{
    // Matching: the extra copy is needed for the match.
    s32 tint_copy = tint;
    func_800F2EE0(tint_copy, actor + 0x98);
}

void subaddiefade_entrypoint_10(s32 actor, s32 tint)
{
    func_800F2EFC(tint, actor + 0x98);
}

void subaddiefade_entrypoint_11(FadeS *actor, f32 *color)
{
    f32 rgb[3];
    if (actor->flag) {
        func_80800450_subaddiefade(rgb);
        func_800F2F20((u8 *) actor + 0x98, rgb);
    } else {
        func_800F2F20((u8 *) actor + 0x98, color);
    }
}

s32 subaddiefade_entrypoint_12(Actor *actor)
{
    f32 rgb[3];

    func_800EFA88(rgb);
    subaddiefade_entrypoint_11(actor, &rgb);
}

void subaddiefade_entrypoint_13(FadeS *actor, f32 *color)
{
    f32 rgb[3];
    if (actor->flag) {
        func_80800450_subaddiefade(rgb);
        func_800F2F20((u8 *) actor + 0x98, rgb);
    } else {
        func_800F2F3C((u8 *) actor + 0x98, color);
    }
}

// Writes the average of src to all three dst channels.
int func_80800450_subaddiefade(dst, src)
s32 dst[3];
s32 src[3];
{
    dst[2] = (dst[1] = (dst[0] = ((src[0] + src[1]) + src[2]) / 3.0f));
}

// Tints from the ambient colour.
s32 subaddiefade_entrypoint_14(Actor *actor)
{
    f32 rgb[3];

    func_800C87DC(rgb);
    subaddiefade_entrypoint_11(actor, &rgb);
}
