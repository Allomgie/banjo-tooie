#include "common.h"

extern f32 D_808008B0_chsunlightspell[];
extern void *func_80100094(Actor *, u32);
typedef union {
    s32 word;
    void *pointer;
} SunlightSpellEventPayload;
extern void *D_808008BC_chsunlightspell;
extern u8 D_80800890_chsunlightspell[];
extern s32 func_800DA298(s32);
extern s32 _sumumbofx_entrypoint_27(s32);
extern void _sumumbofx_entrypoint_5(s32, f32);
extern f32 _sumumbofx_entrypoint_26(s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void _subaddieaudioloop_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_1(Actor *, s32);
typedef struct {
    f32 data[3];
} SunlightVector;
extern u8 D_808008A4_chsunlightspell[];
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_24(void *, f32);
void func_80800404_chsunlightspell();

// Oxygenate spell target (Jolly Roger's Lagoon): deletes itself if the water is already oxygenated.
void func_80800000_chsunlightspell(s32 *actor)
{
    if (func_800DA298(0xE9) != 0) {
        func_800FFA88(*actor);
        return;
    }
    func_80800404_chsunlightspell(actor, 1);
}

s32 func_80800704_chsunlightspell(s32 param_0, f32 param_1);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, s32, s32);

void func_80800668_chsunlightspell();

void func_80800048_chsunlightspell(Actor *actor)
{
    f32 grow;
    f32 shrink;
    f32 fade;

    // States: 2 wait for Mumbo's cast (flag 0x9DE), 3-8 sunlight beam grows and fades, 9 done.
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_800DA298(0x9DE)) {
                func_80800404_chsunlightspell(actor, 3);
            }
            break;
        case 3:
            func_80800668_chsunlightspell(actor);
            func_80800704_chsunlightspell(actor, 1e+02f);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800404_chsunlightspell(actor, 4);
            }
            break;
        case 4:
            func_80800668_chsunlightspell(actor);
            func_80800704_chsunlightspell(actor, 1e+02f);
            _sumumbofx_entrypoint_5(func_80100094(actor, 1), 4.5f);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800404_chsunlightspell(actor, 5);
            }
            break;
        case 5:
            grow = _sumumbofx_entrypoint_26(func_80100094(actor, 1));
            func_80800668_chsunlightspell(actor);
            func_80800704_chsunlightspell(actor,
                                          func_800F12D4(grow, 0.0f, 1.0f, 100.0f, 10.0f));
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800404_chsunlightspell(actor, 6);
            }
            break;
        case 6:
            shrink = _sumumbofx_entrypoint_26(func_80100094(actor, 1));
            func_80800668_chsunlightspell(actor);
            func_80800704_chsunlightspell(actor,
                                          func_800F12D4(shrink, 0.0f, 1.0f, 10.0f, 100.0f));
            actor->scale = func_800F12D4(shrink, 0.0f, 1.0f, 0.01f, 1.0f);
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            D_80800890_chsunlightspell);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800404_chsunlightspell(actor, 7);
            }
            break;
        case 7:
            func_80800668_chsunlightspell(actor);
            func_80800704_chsunlightspell(actor, 1e+02f);
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            D_80800890_chsunlightspell);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800404_chsunlightspell(actor, 8);
            }
            break;
        case 8:
            func_80800668_chsunlightspell(actor);
            func_80800704_chsunlightspell(actor, 1e+02f);
            fade = 1.0f - _sumumbofx_entrypoint_26(func_80100094(actor, 1));
            actor->alpha = fade * 255.0f;
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            D_80800890_chsunlightspell);
            _subaddieaudioloop_entrypoint_1(actor, fade * 20000.0f);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800404_chsunlightspell(actor, 9);
            }
        case 9:
            break;
    }
}

void func_80800404_chsunlightspell(Actor *actor, s32 state)
{
    switch (state) {
        case 1:
            actor->unk64_19 = 0;
            break;
        case 2:
            func_80103110(actor, 1);
            *((u8 *) actor + 0x7A) = (*((u8 *) actor + 0x7A) & ~0xC0) | 0x80;
            break;
        case 3: {
            SunlightVector color = *(SunlightVector *) D_808008A4_chsunlightspell;
            s16 pad_id;
            pad_id = _chmumbopad_entrypoint_0(6);
            _sumumbofx_entrypoint_0(actor, 1, 0x2E, pad_id);
            _sumumbofx_entrypoint_2(func_80100094(actor, 1));
            _sumumbofx_entrypoint_15(func_80100094(actor, 1), 3.0f);
            _sumumbofx_entrypoint_24(func_80100094(actor, 1), 0.5f);
            _sumumbofx_entrypoint_25(func_80100094(actor, 1), 0, &color);
            _capod_entrypoint_13(actor->unk0, 0, 0x12, 0x10);
            break;
        }
        case 4:
            _sumumbofx_entrypoint_18(func_80100094(actor, 1), 6.0f);
            break;
        case 5:
            _sumumbofx_entrypoint_17(func_80100094(actor, 1), 2.0f);
            break;
        case 6:
            _sumumbofx_entrypoint_17(func_80100094(actor, 1), 6.0f);
            actor->unk64_19 = 1;
            actor->scale = 0.01f;
            break;
        case 7:
            _sumumbofx_entrypoint_17(func_80100094(actor, 1), 1.5f);
            actor->scale = 1.0f;
            break;
        case 8:
            _sumumbofx_entrypoint_16(func_80100094(actor, 1), 3.0f);
            break;
        case 9:
            _sumumbofx_entrypoint_1(actor, 1);
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            func_800DA544(0xE9); // FLAG_0E9_MAGIC_SUNLIGHT_OXYGENATED_WATER
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1035, 7, actor->position, 0x10);
            actor->unk64_16 = 0;
            _subaddieaudioloop_entrypoint_2(actor);
            func_800FFAB0(actor);
    }
    func_80102424(actor, state);
}

// Aims the beam from the sky's sun position down to the actor.
void func_80800668_chsunlightspell(u8 *actor)
{
    f32 sun_pos[3];
    f32 unk_0[3];
    f32 angles[2];

    if (func_800BFFB4(0, 4, sun_pos) != 0) {
        func_800E3980(unk_0);
        func_800F18FC(unk_0, sun_pos, angles);
        func_800EEBF0(sun_pos, angles, 0x447A0000);
        func_800EE780(actor + 4, unk_0, sun_pos);
        func_800F18FC(actor + 4, &D_808008B0_chsunlightspell, angles);
        *(f32 *) ((s8 *) actor + 0x48) = angles[1];
        *(f32 *) ((s8 *) actor + 0x44) = angles[0];
    }
}

s32 func_80800704_chsunlightspell(s32 actor, f32 amount)
{
    _sumumbofx_entrypoint_7(func_80100094(actor, 1), amount, 0, 0x2E, actor + 4, 0, 0);
    _sumumbofx_entrypoint_14(func_80100094(actor, 1));
}

void func_80800768_chsunlightspell(Actor *actor, s32 unk_1)
{
    if (func_80100094(actor, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(actor, 1), unk_1);
    }
    if (actor->unk64_19) {
        func_80101870(actor, unk_1);
    }
}

s32 func_808007CC_chsunlightspell(Actor *actor, s32 msg, SunlightSpellEventPayload payload)
{
    switch (msg) {
        case 0x4B:
            _subaddieDll_entrypoint_0(actor);
            func_80800404_chsunlightspell(actor, 2);
            return 1;
        case 0x2E:
            func_800FFA88(actor->unk0);
            return 1;
    }
    return 0;
}

void *chsunlightspell_entrypoint_0(void)
{
    return &D_808008BC_chsunlightspell;
}

extern void func_80105834();
extern void func_80107C2C();
u8 D_80800890_chsunlightspell[20] = {0x0, 0x13, 0x6, 0x73, 0x0,  0x20, 0x0, 0x2, 0x0, 0xA,
                                     0x1, 0x19, 0x0, 0x16, 0x4E, 0x20, 0x0, 0x0, 0x0, 0x0};
u8 D_808008A4_chsunlightspell[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF};
f32 D_808008B0_chsunlightspell[3] = {-9e+03f, 8e+03f, -3.1e+03f};
void *D_808008BC_chsunlightspell = (void *) 0x01310297;
static u32 D_808008BC_chsunlightspell_rest[20] = {0x9280001,
                                                  0x0,
                                                  (u32) func_80800048_chsunlightspell,
                                                  (u32) func_80105834,
                                                  (u32) func_80800768_chsunlightspell,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  0x21000,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  (u32) func_80800000_chsunlightspell,
                                                  (u32) func_80107C2C,
                                                  0x80000402,
                                                  (u32) func_808007CC_chsunlightspell,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  0x0};
