// Probably the visual and scripted part of Mumbo's heal spell: sparkle phases, then a later
// cutscene aims the healing beam at the sick dinosaur and sets the completion flags.
#include "common.h"

typedef struct {
    s32 unk_0[3];
} HealingParticleColor;
extern HealingParticleColor D_808008DC_chmumbohealspell;
extern HealingParticleColor D_808008E8_chmumbohealspell;
extern HealingParticleColor D_808008F4_chmumbohealspell;
extern void *func_80100094(Actor *, u32);
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, HealingParticleColor *,
                                    HealingParticleColor *, HealingParticleColor *);
extern int D_80800900_chmumbohealspell[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_80103EAC(Actor *);
extern void _sumumbofx_entrypoint_14(void *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, s32);
extern int _sumumbofx_entrypoint_24(void *, f32);
extern int _sumumbofx_entrypoint_15(void *, f32);
extern int _sumumbofx_entrypoint_18(void *, f32);
extern int _sumumbofx_entrypoint_17(void *, f32);
extern int _sumumbofx_entrypoint_16(void *, f32);
extern int _sumumbofx_entrypoint_3(void *, f32);
extern u32 D_808008D0_chmumbohealspell[3];
void func_80800450_chmumbohealspell();

void func_80800000_chmumbohealspell(Actor *actor)
{
    if (func_800DA298(0x15E) && func_800EA05C() == 0x155) {
        func_800FFA88(actor->unk0);
    } else if (!func_800DA298(0x189)) {
        func_800FFA88(actor->unk0);
    }
    func_80103110(actor, 0);
}

void func_80800740_chmumbohealspell();

// Cast sequence update: states 3-6 run particle phases, 9-10 aim the beam at the sick dinosaur (actor 0x52D).
void func_80800074_chmumbohealspell(Actor *actor)
{
    Actor *dino;
    Actor *dino_2;
    void *fx;

    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_800DA298(0x9DE)) {
                func_80800450_chmumbohealspell(actor, 3);
            }
            break;
        case 3:
            func_80800740_chmumbohealspell(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 0));
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 0)) <= 0.0f) {
                func_80800450_chmumbohealspell(actor, 4);
            }
            break;
        case 4:
            func_80800740_chmumbohealspell(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 0));
            _sumumbofx_entrypoint_5(func_80100094(actor, 0), 4.0f);
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 0)) <= 0.0f) {
                func_80800450_chmumbohealspell(actor, 5);
            }
            break;
        case 5:
            func_80800740_chmumbohealspell(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 0));
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 0)) <= 0.0f) {
                func_80800450_chmumbohealspell(actor, 6);
            }
            break;
        case 6:
            func_80800740_chmumbohealspell(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 0));
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 0)) <= 0.0f) {
                func_80800450_chmumbohealspell(actor, 8);
            }
            break;
        case 7:
            func_800FFA88(actor->unk0);
            break;
        case 9:
            dino = _subaddiefind_entrypoint_2(0x52D, 0);
            if (dino) {
                fx = func_80100094(actor, 0);
                _sumumbofx_entrypoint_7(fx, func_80103EAC(dino), 0, 60, dino->position,
                                        NULL, 0);
            }
            _sumumbofx_entrypoint_14(func_80100094(actor, 0));
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 0)) <= 0.0f) {
                func_80800450_chmumbohealspell(actor, 10);
            }
            break;
        case 10:
            dino_2 = _subaddiefind_entrypoint_2(0x52D, 0);
            fx = func_80100094(actor, 0);
            _sumumbofx_entrypoint_7(fx, func_80103EAC(dino_2), 0, 60, dino_2->position, NULL,
                                    0);
            _sumumbofx_entrypoint_14(func_80100094(actor, 0));
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 0)) <= 0.0f) {
                func_80800450_chmumbohealspell(actor, 11);
            }
        case 11:
            break;
    }
}

s32 func_808003A8_chmumbohealspell(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x4B:
            func_80800450_chmumbohealspell(actor, 2);
            func_80103110(actor, 1);
            return 1;
        case 0xB:
            if (data == 0x10) {
                _capod_entrypoint_14();
                func_80800450_chmumbohealspell(actor, 7);
                return 4;
            }
            return 3;
        case 0x49:
            if (data == 0x71) {
                func_80800450_chmumbohealspell(actor, 9);
                return 1;
            }
            return 0;
    }
    return 0;
}

// Cast sequence state entry.
void func_80800450_chmumbohealspell(actor, state) Actor *actor;
s32 state;
{
    u32 color[3];
    // Matching: unused local needed for the match.
    s32 unk_0;

    switch (state) {
        case 1:
            break;
        case 2:
            func_80103110(actor, 1);
            break;
        case 3:
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
            _sumumbofx_entrypoint_0(actor, 0, 0x3C, (s16) _chmumbopad_entrypoint_0(0x10));
            _sumumbofx_entrypoint_2(func_80100094(actor, 0));
            _sumumbofx_entrypoint_25(func_80100094(actor, 0), 0x7D, color);
            _sumumbofx_entrypoint_24(func_80100094(actor, 0), 0.65f);
            _sumumbofx_entrypoint_15(func_80100094(actor, 0), 3.0f);
            _capod_entrypoint_13(actor->unk0, actor->unk0, 0x10, 0x800);
            func_8010A800(actor, 2);
            break;
        case 4:
            _sumumbofx_entrypoint_18(func_80100094(actor, 0), 4.0f);
            _chglowbo_entrypoint_6();
            break;
        case 5:
            _sumumbofx_entrypoint_17(func_80100094(actor, 0), 3.0f);
            break;
        case 6:
            _sumumbofx_entrypoint_16(func_80100094(actor, 0), 3.0f);
            break;
        case 7:
            _glcutDll_entrypoint_6(0x121, 0x71);
            break;
        case 8:
            _sumumbofx_entrypoint_1(actor, 0);
            break;
        case 9:
            func_80103110(actor, 1);
            _sumumbofx_entrypoint_0(actor, 0, 0x3C, (s16) _chmumbopad_entrypoint_0(0x10));
            _sumumbofx_entrypoint_2(func_80100094(actor, 0));
            _sumumbofx_entrypoint_25(func_80100094(actor, 0), 0x7D, D_808008D0_chmumbohealspell);
            _sumumbofx_entrypoint_24(func_80100094(actor, 0), 0.65f);
            _sumumbofx_entrypoint_17(func_80100094(actor, 0), 3.0f);
            _sumumbofx_entrypoint_3(func_80100094(actor, 0), 375.0f);
            _sumumbofx_entrypoint_4(func_80100094(actor, 0));
            _capod_entrypoint_13(actor->unk0, actor->unk0, 0, 0x2900);
            break;
        case 10:
            _sumumbofx_entrypoint_16(func_80100094(actor, 0), 3.0f);
            func_80101180(0x52D, 0x33, 0);
            break;
        case 11:
            // Cast done: clear 0x9DE, set 0x9DF and 0x15E.
            _sumumbofx_entrypoint_1(actor, 0);
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            func_800DA544(0x15E);
    }
    func_80102424(actor, state);
}

void func_80800740_chmumbohealspell(Actor *actor)
{
    HealingParticleColor color_a = D_808008DC_chmumbohealspell;
    HealingParticleColor color_b = D_808008E8_chmumbohealspell;
    HealingParticleColor color_c = D_808008F4_chmumbohealspell;

    _sumumbofx_entrypoint_6(func_80100094(actor, 0), 1400.0f, 500.0f, 0, 60, &color_b, &color_c,
                            &color_a);
}

s32 func_80800800_chmumbohealspell(Actor *this, f32 vec[3])
{
    if (func_80100094(this, 0) != 0) {
        _sumumbofx_entrypoint_9(func_80100094(this, 0), vec);
        _sumumbofx_entrypoint_8(func_80100094(this, 0), vec);
    }
}

int chmumbohealspell_entrypoint_0()
{
    return (int) &D_80800900_chmumbohealspell;
}

// TU-NOTE: this overlay's .data is defined here in C so IDO schedules the functions the tables point to correctly; values are from the ROM.
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808008D0_chmumbohealspell[3] = {0x0, 0x0, 0x0};
HealingParticleColor D_808008DC_chmumbohealspell = {0x42B40000, 0x43870000, 0x0};
HealingParticleColor D_808008E8_chmumbohealspell = {0x0, 0x0, 0x0};
HealingParticleColor D_808008F4_chmumbohealspell = {0x447A0000, 0x43FA0000, -0x3B790000};
int D_80800900_chmumbohealspell[20] = {0x15804D8,
                                       -0xFFFF,
                                       0x0,
                                       (u32) func_80800074_chmumbohealspell,
                                       (u32) func_80105834,
                                       (u32) func_80800800_chmumbohealspell,
                                       0x0,
                                       0x40000000,
                                       0x0,
                                       0x400,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800000_chmumbohealspell,
                                       (u32) func_80107C2C,
                                       -0x7FFFFC00,
                                       (u32) func_808003A8_chmumbohealspell,
                                       0x0,
                                       0x0,
                                       0x0};
