#include "common.h"

extern int D_80800F78_chprisonbits[];
extern int D_80800FC0_chprisonbits[];
extern int D_80801008_chprisonbits[];
extern s32 D_80801050_chprisonbits[];
extern int D_808010A8_chprisonbits[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
typedef struct {
    u8 rows[3][5];
} PrisonOrder30;
extern PrisonOrder30 D_808010F0_chprisonbits;
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 code[6];
    u8 index;
} PrisonCode;
extern u8 D_80801098_chprisonbits[];
extern f32 func_8010CD28(Actor *);
extern void _gcdialogcamera_entrypoint_3(u8 *, f32);
extern void func_800EFA4C(Vec3f *, f32, f32, f32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _suexpression_entrypoint_14(void *, f32, f32);
extern u8 D_80801100_chprisonbits[];
extern s32 D_8080111C_chprisonbits[];
extern s32 D_80801144_chprisonbits[];
extern s32 D_8080112C_chprisonbits[];
extern s32 D_80801138_chprisonbits[];
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32[3], void *, void *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32[3], void *, f32);
extern s32 func_80090128(void);
extern s32 func_8010C500(s32);
extern f32 func_800D8FF8(void);
extern void func_80102128(u8 *, s32, s32, f32, s32);
extern void func_8010CE70();
extern s32 func_8010BF4C(u8 *, u8 *, f32, s32, s32);
extern s32 func_80102CF4(u8 *, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern void func_80102844(u8 *, f32, s32, u8 *);
extern void func_801058C4(u8 *, s32, f32, s32);
void func_80800344_chprisonbits();
int func_80800CC4_chprisonbits();
int func_80800DAC_chprisonbits();

int chprisonbits_entrypoint_0()
{
    return (int) &D_80800F78_chprisonbits;
}

int chprisonbits_entrypoint_1()
{
    return (int) &D_80800FC0_chprisonbits;
}

int *chprisonbits_entrypoint_2()
{
    return &D_80801008_chprisonbits;
}

int chprisonbits_entrypoint_3()
{
    return (int) D_80801050_chprisonbits;
}

int *chprisonbits_entrypoint_4()
{
    return &D_808010A8_chprisonbits;
}

void func_8080003C_chprisonbits()
{
    _chswitch_entrypoint_7();
}

void func_8080005C_chprisonbits(Actor *actor, s32 unk_1, s32 x_offset)
{
    Actor *anchor;

    anchor = _subaddiefind_entrypoint_2(0x120, NULL);
    actor->position[0] = anchor->position[0] + x_offset;
    actor->position[2] = anchor->position[2];
    func_8080003C_chprisonbits(actor, unk_1);
}

// Chooses the random switch code (flag 0x32B) and places the switch.
void func_808000C0_chprisonbits(Actor *actor)
{
    PrisonOrder30 orders = D_808010F0_chprisonbits;
    u8 *state;
    u8 *order;
    s32 i;
    state = func_80100094(actor, 1);
    state[6] = 0;
    state[0] = 0;
    if (!func_800DA564(0x32B, 2))
        func_800DA7A8(0x32B, func_800DC128(0, 3) + 1, 2);
    order = orders.rows[func_800DA564(0x32B, 2) - 1];
    for (i = 0; i < 5; i++)
        state[i] = order[i];
    state[5] = 0;
    func_8080005C_chprisonbits(actor, 0, -0xAF);
    actor->unk64_19 = func_800DA298(0xD5);
}

void func_808001E0_chprisonbits(s32 actor)
{
    func_8080003C_chprisonbits(actor, 1);
}

void func_80800200_chprisonbits(s32 actor)
{
    func_8080005C_chprisonbits(actor, 2, 0xAF);
}

int func_80800224_chprisonbits(Actor *actor)
{
    if (_chdoormake_entrypoint_0(actor, 0x42B40000, 0x60, 0xD5)) {
        _chdoormake_entrypoint_8(actor, 5);
        _chdoormake_entrypoint_5(actor, 0x40400000);
        _chdoormake_entrypoint_9(actor, 0, 0, 0x10);
    }
}

int func_80800280_chprisonbits()
{
    func_800DA298();
}

s32 func_808002A0_chprisonbits(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 7:
            func_80101180(0x11F, 10, 0);
            break;
        case 10:
            func_80800344_chprisonbits(actor);
            break;
        case 0x91:
            if (func_800DA298(0xD5))
                return 0;
        default:
            return _chswitch_entrypoint_10(actor, msg, data);
    }
    return 1;
}

// Advances the code when the correct switch is pressed.
void func_80800344_chprisonbits(actor) Actor *actor;
{
    PrisonCode *state;
    s32 pressed;

    state = func_80100094(actor, 1);
    if (state->code[state->index]) {
        pressed = func_80800280_chprisonbits(state->code[state->index] - 1);
        if (!pressed) {
            pressed = func_80800280_chprisonbits(state->code[0] - 1);
            if (pressed) {
                state->index = 0;
            }
        }
        if (pressed) {
            if (func_800DA298(0xD5)) {
                state->index = 0;
            } else {
                if (!state->code[++state->index]) {
                    func_800DA544(0xD5);
                    func_80101180(0x11E, 7, 0);
                }
            }
        } else if (func_80800280_chprisonbits(0) || func_80800280_chprisonbits(1) ||
                   func_80800280_chprisonbits(2)) {
            state->index = 0;
        }
    }
}

void func_8080044C_chprisonbits(s32 actor)
{
    s32 state;
    state = func_80100094(actor, 0);
    _susubgame_entrypoint_0(actor, state + 0x1C, 1);
    _susubgame_entrypoint_12(state + 0x1C, (int *) D_80801098_chprisonbits);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(actor, 0xA);
        return;
    }
    if ((func_800DA298(0x5C) != 0) && (func_800EA05C() == 0xB9)) {
        func_800FFAB0(actor);
        return;
    }
    func_80800DAC_chprisonbits(actor);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(0x127, actor), state + 0x10);
}

s32 func_80800C84_chprisonbits();

void func_80800C18_chprisonbits();

s32 func_80800BB4_chprisonbits();

// Dilberta's main behaviour.
void func_80800518_chprisonbits(u8 *actor)
{
    u8 *state;
    u8 *home;
    f32 target[3];

    state = func_80100094(actor, 0);
    func_8010C820(actor, 0x28, 0x1E);
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_10(func_80100094(actor, 1), *(s32 *) actor, 0);
    }
    switch ((u32) *(u16 *) (actor + 0x72) >> 10) {
        case 3:
            if (func_80800BB4_chprisonbits(actor) == 0 &&
                func_80800C84_chprisonbits(actor) == 0) {
                func_80102128(actor, 0x1F, 0x11,
                              func_80800DFC_chprisonbits(actor) != 0 ? 1.0f : 0.4f, 2);
            }
            break;
        case 2:
            if (func_80800DFC_chprisonbits(actor) != 0) {
                *(f32 *) (actor + 0x24) = 450.0f;
                func_8010CE70(actor, (s32) (func_800D8FF8() * 350.0f), -1);
                func_8010B990(actor, 0x300105);
                func_80800BB4_chprisonbits(actor);
                break;
            }
            if (func_80800BB4_chprisonbits(actor) == 0 &&
                func_80800C84_chprisonbits(actor) == 0) {
                func_80102128(actor, 0x1F, 7, 0.3f, 3);
            }
            if ((func_8010BF4C(actor, state, 420.0f, (s32) (func_800D8FF8() * 350.0f), 0x300105) &
                 0x24) &&
                func_80102CF4(actor, 20.0f) != 0) {
                func_80800DAC_chprisonbits(actor);
            }
            if (func_800F0064((f32 *) (actor + 4), 100.0f, (f32 *) state) != 0) {
                func_80800DAC_chprisonbits(actor);
            }
            break;
        case 5:
            func_80800C84_chprisonbits(actor);
            func_8010CE70(actor, 5, 6);
            break;
        case 6:
            func_8010CE70(actor, 6, -1);
            break;
        case 7:
            *(f32 *) (actor + 0x24) = 350.0f;
            func_80102844(actor, func_800D8FF8() * 350.0f, -1, home = state + 0x10);
            func_8010B990(actor, 5);
            if (func_800F0064((f32 *) home, 120.0f, (f32 *) (actor + 4)) != 0) {
                _capod_entrypoint_22();
                func_800F7F98(func_800F54E4(), 0);
                _susubgame_entrypoint_5(actor, state + 0x1C, 3, 1, 0x2000);
                _subaddiedialog_entrypoint_11(*(s32 *) actor, 0xF18, 0xE, (actor + 4), 0x32);
                func_80102424(actor, 4);
            }
            break;
        case 4:
            func_80800C18_chprisonbits(actor);
            func_8010CE70(actor, 9, -1);
        case 10:
            break;
        case 8:
            home = state + 0x10;
            func_80102844(actor, 8.0f, -1, home);
            if (func_80102CF4(actor, 60.0f) != 0) {
                target[0] = *(f32 *) (state + 0x10);
                target[1] = *(f32 *) (actor + 8);
                target[2] = *(f32 *) (state + 0x18);
                *(f32 *) (actor + 0x24) = 300.0f;
                func_8010BF4C(actor, home, 300.0f, 6, 0x1005);
                if (func_800F0064((f32 *) (actor + 4), 100.0f, target) != 0) {
                    func_801058C4(actor, _glsplinefind_entrypoint_1(0x127),
                                  *(f32 *) (actor + 0x24), 1);
                }
            }
    }
}

// Dilberta walking out along the spline; flag 0x5C is set at the end.
void func_8080090C_chprisonbits(Actor *actor)
{
    u8 *state;

    func_80105834(actor);
    if (func_80105A5C(actor)) {
        state = func_80100094(actor, 0);
        func_800DA544(0x5C);
        _susubgame_entrypoint_4(actor, state + 0x1C);
        func_800FFAB0(actor);
    }
}

int func_80800970_chprisonbits(Actor *actor)
{
    s32 state;
    state = func_80100094(actor, 0);
    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_8(actor, 1);
    }
    _susubgame_entrypoint_4(actor, state + 0x1C);
}

s32 func_808009C4_chprisonbits(Actor *actor, s32 msg, s32 data)
{
    s32 pad0;
    void *state;
    Vec3f focus;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 0x2E:
            func_80800CC4_chprisonbits(actor, ((s16 *) &data)[0], ((s16 *) &data)[1]);
            break;
        case 0x49:
            if (data == 0xC) {
                _susubgame_entrypoint_6(actor, (u8 *) func_80100094(actor, 0) + 0x1C, 0x11,
                                        0x2820, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0xF42, 0x44, &actor->position, 0x32);
                func_80102424(actor, 9);
                break;
            }
            return 0;
        case 0x29:
            _suexpression_entrypoint_7(actor, 1, 0x32);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 45.0f, 15.0f);
            _suexpression_entrypoint_14(func_80100094(actor, 1), 1.0f, 1.0f);
            break;
        case 0x2A:
            _suexpression_entrypoint_8(actor, 1, msg);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(actor, (u8 *) state + 0x1C, data & 0xFFFF,
                                           (u32) (data & 0xFFFF0000) >> 16);
        case 0x52:
            func_800EFA4C(&focus, 0.0f, func_8010CD28(actor), 0.0f);
            _gcdialogcamera_entrypoint_3(D_80801098_chprisonbits, actor->scale);
            _gcdialogcamera_entrypoint_5(&focus);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_80800BB4_chprisonbits(Actor *actor)
{
    s32 dialog_result;

    dialog_result = _subaddiedialog_entrypoint_7(actor, actor->position, D_80801100_chprisonbits);
    if (dialog_result != 0 && dialog_result != 0x1208) {
        _susubgame_entrypoint_5(actor, (u8 *) func_80100094(actor, 0) + 0x1C, 4, 0, 0);
    }
    return dialog_result;
}

void func_80800C18_chprisonbits(Actor *actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_8080111C_chprisonbits,
                                     &D_80801144_chprisonbits);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_8080112C_chprisonbits, 0.75f);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_80801138_chprisonbits, 0.6f);
}

s32 func_80800C84_chprisonbits(s32 actor)
{
    if (func_800DA298(0x514) != 0) {
        func_80102424(actor, 7);
        return 1;
    }
    return 0;
}

int func_80800CC4_chprisonbits(actor, dialog_id, unk_2)
s32 actor;
s32 dialog_id;
s32 unk_2;
{
    u32 state;
    int state_copy;
    state = (s32) func_80100094(actor | 0, 0) | 0;
    switch (dialog_id) {
        case 0xF18:
            state_copy = state;
            func_80102424(actor | 0, 8, dialog_id);
            _susubgame_entrypoint_6(actor | 0, state_copy + 0x1C, 0xE, 0x2030, 0);
            return;

        case 0xF42:
            _susubgame_entrypoint_4(actor | 0, state + 0x1C, dialog_id);
            _glcutDll_entrypoint_17();
            return;

        case 0xF4F:
            _susubgame_entrypoint_4(actor | 0, state + 0x1C, dialog_id);
            func_80102424(actor | 0, 3);
            return;

        default:
            _susubgame_entrypoint_4(actor | 0, state + 0x1C, dialog_id);
            func_80102424(actor | 0, 3);
    }
}

int func_80800DAC_chprisonbits(actor)
Actor *actor;
{
    s32 *state;
    state = func_80100094(actor, 0);
    func_800CD08C(((u32) *(s32 *) ((char *) actor + 0x70) >> 25) - 1, state);
    *(f32 *) ((char *) state + 0x4) = *(f32 *) ((char *) actor + 0x8);
}

int func_80800DFC_chprisonbits(s32 actor)
{
    return func_800DA298(0x5B) == 0 && func_80090128() != 0 && func_8010C500(actor) != 0;
}

// Starts the Dilberta dialog.
void chprisonbits_entrypoint_5(s32 unk_0, s32 unk_1)
{
    s32 *dilberta;

    dilberta = _subaddiefind_entrypoint_2(0x117, 0);
    if ((dilberta != NULL) && (func_800DA298(0x6A4) == 0)) {
        _susubgame_entrypoint_6(dilberta, (s32) func_80100094(dilberta, 0) + 0x1C, 2, 0x430, 0);
        _subaddiedialog_entrypoint_11(*dilberta, 0xF4F, 0x44, dilberta + 1, 0x32);
        func_80102424(dilberta, 9);
        func_800DA544(0x6A4);
    }
}

extern void _chdoor_entrypoint_0();
extern int func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
u32 D_80800F20_chprisonbits[22] = {
    0x0,        0x0,       0x0,        0x0,       0x3ECCCCCD, 0x1DA0001, 0x40A66666, 0x1D90001,
    0x40066666, 0x1DB0001, 0x3E99999A, 0x1DA0001, 0x40A66666, 0x1D90001, 0x3E99999A, 0x1DA0001,
    0x3E99999A, 0x1DA0001, 0x40A66666, 0x1D90001, 0x40A66666, 0x1D90001};
int D_80800F78_chprisonbits[18] = {0xE011E,
                                   0x6470001,
                                   0x0,
                                   (u32) _chdoor_entrypoint_0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x800,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800224_chprisonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD3FE,
                                   (u32) _chdoor_entrypoint_1,
                                   0x0};
int D_80800FC0_chprisonbits[18] = {0xF011F,
                                   0x6440001,
                                   (u32) &D_8011A270,
                                   (u32) _chswitch_entrypoint_6,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x808,
                                   0x0,
                                   0x0,
                                   0x7,
                                   (u32) func_808000C0_chprisonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD3FE,
                                   (u32) func_808002A0_chprisonbits,
                                   0x0};
int D_80801008_chprisonbits[18] = {0x130120,
                                   0x6450001,
                                   (u32) &D_8011A270,
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
                                   (u32) func_808001E0_chprisonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD3FE,
                                   (u32) func_808002A0_chprisonbits,
                                   0x0};
s32 D_80801050_chprisonbits[18] = {0x150121,
                                   0x6460001,
                                   (u32) &D_8011A270,
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
                                   (u32) func_80800200_chprisonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD3FE,
                                   (u32) func_808002A0_chprisonbits,
                                   0x0};
u8 D_80801098_chprisonbits[16] = {0x42, 0xA0, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0,
                                  0x42, 0xA0, 0x0, 0x0, 0x41, 0x20, 0x0, 0x0};
int D_808010A8_chprisonbits[18] = {0x360117,
                                   0x66D0003,
                                   (u32) &D_80800F20_chprisonbits,
                                   (u32) func_80800518_chprisonbits,
                                   (u32) func_8080090C_chprisonbits,
                                   (u32) func_80101870,
                                   0x9C40000,
                                   0x3F800000,
                                   0x0,
                                   0x121,
                                   (u32) func_80800970_chprisonbits,
                                   0x0,
                                   0x340000,
                                   (u32) func_8080044C_chprisonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFBB7E,
                                   (u32) func_808009C4_chprisonbits,
                                   0x0};
PrisonOrder30 D_808010F0_chprisonbits = {0x3, 0x2, 0x1, 0x2, 0x3, 0x1, 0x3, 0x1,
                                         0x2, 0x2, 0x2, 0x1, 0x3, 0x1, 0x1};
u8 D_80801100_chprisonbits[28] = {0x0, 0x5B, 0x1,  0x5E, 0xF, 0x16, 0xF, 0x17, 0x0, 0x0,
                                  0x2, 0x81, 0x12, 0x8,  0x0, 0x0,  0x0, 0x32, 0x0, 0x0,
                                  0x0, 0xC,  0x0,  0x0,  0x6, 0x0,  0x0, 0x0};
s32 D_8080111C_chprisonbits[4] = {0x130402, 0x1636B0, 0xA0119, 0x0};
s32 D_8080112C_chprisonbits[3] = {0x13044C, 0x163A98, 0x0};
s32 D_80801138_chprisonbits[3] = {0x13043A, 0xD01CC, 0x1FD0000};
s32 D_80801144_chprisonbits[3] = {0x3E8A3D71, 0x3F000000, -0x40800000};
