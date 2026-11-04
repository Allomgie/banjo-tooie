// Shared Gobi (camel) helper: plays sound effects for his animations 0x221-0x223 (spit, grunt,
// breathing), some suppressed while a dialog is open. Used by both Gobi actors.
#include "common.h"

extern u8 D_8080021C_chgobicommon[];
extern u8 D_80800244_chgobicommon[];
extern u8 D_8080022C_chgobicommon[];
extern u8 D_80800254_chgobicommon[];
extern u8 D_80800238_chgobicommon[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern int D_80800264_chgobicommon[];
extern int D_80800270_chgobicommon[];
extern int D_80800200_chgobicommon[];
extern int D_80800210_chgobicommon[];
void func_80800070_chgobicommon();
void func_808000EC_chgobicommon();
void func_808001AC_chgobicommon();

// Plays animation-specific sounds for Gobi's animations 0x221-0x223.
s32 chgobicommon_entrypoint_0(s32 actor)
{
    switch (func_801022E4(actor)) {
        case 0x221:
            func_80800070_chgobicommon(actor);
            break;
        case 0x222:
            func_808000EC_chgobicommon(actor);
            break;
        case 0x223:
            func_808001AC_chgobicommon(actor);
    }
}

void func_80800070_chgobicommon(actor) Actor *actor;
{
    _subaddieaudioquick_entrypoint_4(actor, actor->position, D_8080021C_chgobicommon,
                                     D_80800244_chgobicommon);
    _subaddieaudioquick_entrypoint_4(actor, actor->position, D_8080022C_chgobicommon,
                                     D_80800254_chgobicommon);
    if (!func_800C0638())
        _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80800238_chgobicommon,
                                         0.03f);
}

void func_808000EC_chgobicommon(actor) s32 actor;
{
    s32 base = actor;
    unsigned int arg;
    int pos;
    // Matching: empty blocks are needed for the match.
    if (1) {
    }
    if (1) {
    }
    if (1) {
    }
    if (!func_800C0638()) {
        arg = 4;
        _subaddieaudioquick_entrypoint_4(base, base + arg, &D_80800264_chgobicommon,
                                         &D_80800270_chgobicommon);
    }
    pos = base + 4;
    arg = base;
    _subaddieaudioquick_entrypoint_3(arg, pos, &D_80800200_chgobicommon, 0.26f);
    _subaddieaudioquick_entrypoint_3(arg, pos, &D_80800210_chgobicommon, 0.41f);
    _subaddieaudioquick_entrypoint_3(arg, pos, &D_80800200_chgobicommon, 0.55f);
    _subaddieaudioquick_entrypoint_3(arg, pos, &D_80800200_chgobicommon, 0.62f);
}

void func_808001AC_chgobicommon(actor) u8 *actor;
{
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, ((s32 *) &D_80800200_chgobicommon),
                                     0.65f);
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, ((s32 *) &D_80800210_chgobicommon),
                                     0.0f);
}

// TU-NOTE: the overlay .data is defined in C here; values are taken from the ROM.
// D_80800200, D_80800210, D_80800264 and D_80800270 are declared as int[] to match the objects.
int D_80800200_chgobicommon[4] = {0x130402, 0x1636B0, 0xA00E6, 0x0};
int D_80800210_chgobicommon[3] = {0x130402, 0x1636B0, 0x0};
u8 D_8080021C_chgobicommon[16] = {0x0, 0x13, 0x4, 0x9C, 0x0, 0x16, 0x36, 0xB0,
                                  0x0, 0xD,  0x0, 0xD9, 0x0, 0xF3, 0x0,  0x0};
u8 D_8080022C_chgobicommon[12] = {0x0, 0x13, 0x5, 0xBB, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80800238_chgobicommon[12] = {0x0, 0x13, 0x4, 0xCA, 0x0, 0xD, 0x1, 0x26, 0x1, 0x40, 0x0, 0x0};
u8 D_80800244_chgobicommon[16] = {0x3E, 0xDC, 0x28, 0xF6, 0x3E, 0xF5, 0xC2, 0x8F,
                                  0x3F, 0xF,  0x5C, 0x29, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800254_chgobicommon[16] = {0x3F, 0x26, 0x66, 0x66, 0x3F, 0x46, 0x66, 0x66,
                                  0x3F, 0x66, 0x66, 0x66, 0xBF, 0x80, 0x0,  0x0};
int D_80800264_chgobicommon[3] = {0x1304CA, 0xD0126, 0x1400000};
int D_80800270_chgobicommon[4] = {0x3E2E147B, 0x3EA3D70A, 0x3EF5C28F, -0x40800000};
