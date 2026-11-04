// Probably Moggy, one of Boggy's kids lost in Witchyworld: follows a spline path and, once
// found and talked to, sets the kid-returned flag and counts the kids that are back.
#include "common.h"
extern u8 D_80800C00_chboggyboy[];

extern int D_80800CB8_chboggyboy[];
typedef struct {
    u8 pad_0[8];
    u8 route[12];
    s16 timer;
    u8 pad_1 : 1;
    u8 active : 1;
    u8 pad_2 : 6;
} BoggyBoyState;
extern void *func_80100094(Actor *, u32);
typedef union {
    s32 word;
    s16 half[2];
} BoggyBoyMessage32;
typedef struct {
    u8 pad_0[0x14];
    s16 local_0;
    u8 pad_1 : 1;
    u8 local_1 : 1;
    u8 local_2 : 1;
    u8 pad_2 : 5;
} BoggyBoyFlags109;
extern void func_80102924(Actor *, f32);
extern void func_80102424(Actor *, s32);
typedef struct {
    u8 pad_0[0x14];
    u32 pad_1 : 16;
    u32 timed : 1;
    u32 pad_4 : 1;
    u32 active : 1;
    u32 pad_2 : 13;
    f32 pad_3[2];
    f32 timer;
} BoggyBoyUpdate;
extern s32 func_800D9154(f32 *, f32);
extern u8 D_80800C18_chboggyboy[];
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
typedef struct {
    u8 pad_0[0x14];
    u32 pad_1 : 16;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 pad_2 : 14;
} BoggyBoyDialogFlags;
extern f32 func_800DC178(f32, f32);
extern f32 func_801028C4(void *, f32 *, f32, f32, f32);
extern f32 func_80102D78(void *, f32 *);
extern void func_80102BF8(void *, f32, f32, f32);
extern s32 func_80102CF4(void *, f32);
extern void _subaddierouteDll_entrypoint_6(void *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(void *, void *, f32, f32, f32, s32);
extern s32 _subaddierouteDll_entrypoint_4(void *);
extern s32 func_8010B990(void *, s32);
extern void func_801058C4(void *, s32, f32, s32);
extern s32 func_800F0064(void *, f32, f32 *);
void typedef struct {
    u8 pad[0x16];
    s16 b15 : 1;
    s16 r : 15;
} BoyBits16;
typedef struct {
    u8 pad[0x14];
    u32 hi : 17;
    u32 b14 : 1;
    u32 lo : 14;
} BoyBits14;
extern s32 D_80800D10_chboggyboy[];
extern s32 D_80800D20_chboggyboy[];
extern void func_800C9C70(f32, s32, f32, s32, f32 *, f32, f32);
typedef union {
    s32 local_0;
    struct {
        s16 local_0;
        s16 local_1;
    } local_1;
} BoggyBoyMessage36;
int func_8080082C_chboggyboy();
// Starts the thank-you dialog (0x1099 once all three kids are back, else 0x1098).
void func_808009F4_chboggyboy();
s32 func_80800AD0_chboggyboy();
extern void func_80101870(), func_80107C2C(), func_80108ED0(), func_8080000C_chboggyboy(),
    func_8080086C_chboggyboy();

int chboggyboy_entrypoint_0()
{
    return (int) &D_80800CB8_chboggyboy;
}

void func_8080000C_chboggyboy(actor) Actor *actor;
{
    BoggyBoyState *state;
    state = func_80100094(actor, 0);
    if (!_chboggykids_entrypoint_0(actor)) {
        func_800FFAB0(actor);
        return;
    }
    *(f32 *) &actor->actorData[3] = 300.0f;
    if (!func_800DA298(0xB8))
        func_8010A570(actor);
    else
        state->active = 1;
    _subaddieDll_entrypoint_1(actor);
    _subaddierouteDll_entrypoint_3(actor, state->route, actor->position);
    state->timer = 0;
    func_8080082C_chboggyboy(actor);
}

// Per-frame behaviour: follows the spline path and reacts to the player.
func_808000B8_chboggyboy(Actor *actor)
{
    extern u16 D_80800D00_chboggyboy[];
    extern u8 D_80800C24_chboggyboy[];

    char *state;
    s32 timer_done;
    f32 target[3];
    f32 goal[3];
    char *expression;

    state = (char *) func_80100094(actor, 0);
    timer_done = func_800D90A4((char *) actor + 0x58);

    expression = (char *) func_80100094(actor, 1);
    if (expression != 0) {
        expression = (char *) func_80100094(actor, 1);
        _suexpression_entrypoint_10(expression, *(s32 *) ((char *) actor + 0), 0);
    }

    switch (((u32) *(u16 *) ((char *) actor + 0x72) >> 10)) {
        case 1:
            if (!_subaddiedialog_entrypoint_8(actor, (char *) actor + 4, D_80800D00_chboggyboy,
                                              D_80800C00_chboggyboy, 3) &&
                func_800DA298(D_80800D00_chboggyboy[0]) && timer_done) {
                func_80102924(actor,
                              *(f32 *) ((char *) actor + 0x48) + func_800DC178(90.0f, 270.0f));

                func_80102424(actor, 3);
                *(s16 *) (state + 0x14) = 0;
            }
            break;

        case 4:
            func_8010CE70(actor, 10, -1);
            break;

        case 3:
            func_80102BF8(actor, 0.2f, 60.0f, 180.0f);

            if (func_80102CF4(actor, 15.0f)) {
                *(f32 *) ((char *) actor + 0x58) = func_800DC178(8.0f, 12.0f);

                func_80102424(actor, 2);
            }

            _subaddiedialog_entrypoint_8(actor, (char *) actor + 4, D_80800D00_chboggyboy,
                                         D_80800C00_chboggyboy, 3);
            break;

        case 2:
            func_80105230(actor, 0);

            if (!_subaddiedialog_entrypoint_8(actor, (char *) actor + 4, D_80800D00_chboggyboy,
                                              D_80800C00_chboggyboy, 3)) {
                _subaddierouteDll_entrypoint_6(actor, state + 8, *(s16 *) (state + 0x14), 7,
                                               0.7f, 8, 12);

                if (_subaddierouteDll_entrypoint_4(actor)) {
                    _subaddierouteDll_entrypoint_7(
                        actor, state + 8, *(f32 *) ((char *) actor + 0x48),
                        *(f32 *) ((char *) actor + 0x54), 200.0f, 0x4000);

                    *(u16 *) (state + 0x14) = *(u16 *) (state + 0x0E);
                }

                func_80102BF8(actor, 0.2f, 30.0f, 180.0f);

                if (func_8010B990(actor, 0x1305) & 4) {
                    func_80102924(actor, *(f32 *) ((char *) actor + 0x48) + 180.0f);

                    func_80102424(actor, 3);
                    *(s16 *) (state + 0x14) = 0;
                } else if (timer_done) {
                    func_80102424(actor, 1);
                    *(f32 *) ((char *) actor + 0x58) = func_800DC178(4.0f, 6.0f);
                }
            }
            break;

        case 5: {
            func_800EE88C(target, state);

            if (func_801028C4(actor, target, 0.2f, 30.0f, 180.0f) < 40.0f) {
                func_80102424(actor, 6);
            }
        } break;

        case 6: {
            func_800EE88C(goal, state);

            *(f32 *) ((char *) actor + 0x54) = func_80102D78(actor, goal);

            func_80102BF8(actor, 0.2f, 30.0f, 180.0f);

            func_8010B990(actor, 0x1005);

            if (func_800F0064((char *) actor + 4, 100.0f, goal)) {
                func_801058C4(actor, *(s16 *) (state + 6), *(f32 *) ((char *) actor + 0x24),
                              1);

                func_80105BAC(actor);
                func_80102424(actor, 7);
            }
        } break;

        case 14:
            _subaddiefx_entrypoint_0(actor, -1, state + 0x18);

            if (func_80101DDC(actor)) {
                _subaddiefx_entrypoint_1(actor, state + 0x18);

                func_80102424(actor, 4);
            }
    }

    if (((BoyBits14 *) state)->b14) {
        if (func_801022E4(actor) == 0x243) {
            if (func_800D9154(state + 0x20, 3.0f)) {
                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_80800C24_chboggyboy);
            }
        }
    } else if (((BoyBits16 *) state)->b15) {
        if (func_800D9154(state + 0x20, 2.5f)) {
            _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80800C18_chboggyboy);
        }
    }

    _sudeflect_entrypoint_0((f32 *) ((char *) actor + 4), 100.0f, 50.0f, 10);
}

s32 func_80800A64_chboggyboy();

// Moggy was found: starts dialog 0x108A.
void func_80800978_chboggyboy();

void func_808006C4_chboggyboy();

s32 func_80800570_chboggyboy(Actor *actor, s32 msg, BoggyBoyMessage36 param_2)
{
    f32 *pos;

    switch (msg) {
        case 0x2E:
            func_808006C4_chboggyboy(actor, param_2.local_1.local_0, param_2.local_1.local_1);
            break;
        case 0x40:
            func_80800978_chboggyboy(actor, param_2.local_0);
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0x29:
            func_80800A64_chboggyboy(actor);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800D10_chboggyboy, *(s32 *) &actor->scale);
            break;
        case 0x2D:
            pos = actor->position;
            _subaddieaudioquick_entrypoint_2(actor, pos, &D_80800D20_chboggyboy);
            func_800C9C70(1.0f, 0x525, 1.05f, 22000, pos, 200.0f, 3000.0f);
            break;
        case 0x30:
            return 3 - func_800DA980(0x8C, 3);
        case 0x2A:
            func_80800AD0_chboggyboy(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808006C4_chboggyboy(Actor *actor, s32 msg, BoggyBoyMessage32 param_2)
{
    u8 *state;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 0x108A:
            func_800DA544(0x8C);
            func_80101180(0x13F, 0x23, 0);
            func_80102424(actor, 5);
            _subaddieDll_entrypoint_4(actor, 1);
            func_808009F4_chboggyboy(actor);
            break;
        case 0x1098:
        case 0x1099:
            ((BoggyBoyFlags109 *) state)->local_2 = 0;
            break;
        default:
            switch (_subaddiedialog_entrypoint_9(actor, msg, D_80800C00_chboggyboy, 3)) {
                case 1:
                    func_8010A590(actor);
                    ((BoggyBoyFlags109 *) state)->local_1 = 1;
                case 2:
                    func_80102924(actor, actor->rotation[1] + 180.0f);
                    func_80102424(actor, 3);
                    ((BoggyBoyFlags109 *) state)->local_0 = 0;
                    break;
                default:
                    func_80102424(actor, 1);
            }
    }
}

s32 func_808007F4_chboggyboy(actor)
s32 actor;
{
    s32 state;

    state = func_80100094(actor, 0);
    _subaddiefx_entrypoint_1(actor, state + 0x18);
    func_80800AD0_chboggyboy(actor);
}

int func_8080082C_chboggyboy(actor)
s32 actor;
{
    u8 *state;
    s8 _sfpad[8]; // Matching: unused stack padding needed for the match.
    s16 unk_0[2];
    state = func_80100094(actor, 0);
    *(s16 *) ((char *) state + 6) = _glsplinefind_entrypoint_0(0x3A1, unk_0);
    func_800EE940(state, unk_0);
}

void func_8080086C_chboggyboy(actor) Actor *actor;
{
    BoggyBoyUpdate *state;
    state = func_80100094(actor, 0);

if (state->timed) {
    if (func_800D9154(&state->timer, 1.6f)) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800C18_chboggyboy);
    }
}

if (actor->unk70_10 == 0x10) {
    if (!state->active)
        func_800FFAB0(actor);
} else {

func_80105834(actor);
_sudeflect_entrypoint_0(actor->position, 100.0f, 50.0f, 10);
func_80105230(actor, 0);

if (func_80105A5C(actor)) {
    if (state->active) {
        func_80102424(actor, 0x10);
        actor->unk64_16 = 0;
    } else {
        func_800FFAB0(actor);
    }
}

}
}

// Moggy was found: starts dialog 0x108A.
void func_80800978_chboggyboy(Actor *actor, s32 param_1)
{
    BoggyBoyDialogFlags *flags;

    flags = func_80100094(actor, 0);
    _subaddiedialog_entrypoint_11(actor->unk0, 0x108A, 0xE, actor->position, 0x3B);
    func_80102424(actor, 0xE);
    func_8010A570(actor);
    flags->local_0 = 1;
    flags->local_1 = 0;
}

// Starts the thank-you dialog (0x1099 once all three kids are back, else 0x1098).
void func_808009F4_chboggyboy(arg) Actor *arg;
{
    Actor *actor;
    s32 dialog_id;
    u8 *state;
    actor = arg;
    if (func_800DA980(0x8C, 3) == 3) {
        dialog_id = 0x1099;
    } else {
        dialog_id = 0x1098;
    }
    _subaddiedialog_entrypoint_11(*((s32 *) (((char *) actor) + 0x0)), dialog_id, 0xF,
                                  (u32 *) actor + 1, 0x3B);
    state = func_80100094(actor, 0);
    *((u8 *) (((char *) state) + 0x16)) = ((*((u8 *) (((char *) state) + 0x16))) & 0xFF) | 0x20;
}

s32 func_80800A64_chboggyboy(Actor *this)
{
    if (!func_80100094(this, 1)) {
        _suexpression_entrypoint_7(this, 1, 0x3B);
        _suexpression_entrypoint_12(func_80100094(this, 1), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(this, 1), 0x3E8);
    }
}

s32 func_80800AD0_chboggyboy(this) Actor *this;
{
    if (func_80100094(this, 1) != 0) {
        _suexpression_entrypoint_8(this, 1);
    }
}

u8 D_80800C00_chboggyboy[24] = {0x0,  0x0,  0x6, 0x1, 0x10, 0x88, 0x1,  0x0,  0x0,  0x0,  0x6, 0x1,
                                0x10, 0x89, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0x22, 0x3, 0x0};
u8 D_80800C18_chboggyboy[12] = {0x0, 0x13, 0x5, 0x24, 0x0, 0xA, 0x0, 0xCC, 0x0, 0x0, 0x0, 0x0};
u8 D_80800C24_chboggyboy[12] = {0x0, 0x13, 0x5, 0x25, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80800C30_chboggyboy[136] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1,
    0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1,
    0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1,
    0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1,
    0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1,
    0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1,
    0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1,
    0x3F, 0x4C, 0xCC, 0xCD, 0x0, 0xB7, 0x0, 0x2, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0};
int D_80800CB8_chboggyboy[18] = {0x1920140,
                                 0x7590001,
                                 (u32) &D_80800C30_chboggyboy,
                                 (u32) func_808000B8_chboggyboy,
                                 (u32) func_8080086C_chboggyboy,
                                 (u32) func_80101870,
                                 0x9C40000,
                                 0x3F800000,
                                 0x8C0000,
                                 0x40040120,
                                 (u32) func_808007F4_chboggyboy,
                                 (u32) func_80108ED0,
                                 0x240000,
                                 (u32) func_8080000C_chboggyboy,
                                 (u32) func_80107C2C,
                                 -0x7FEFAFEC,
                                 (u32) func_80800570_chboggyboy,
                                 0x0};
u16 D_80800D00_chboggyboy[8] = {0xB8, 0x0, 0x190, 0x3B, 0x0, 0xE, 0x0, 0x400};
s32 D_80800D10_chboggyboy[4] = {0x43200000, 0x430C0000, 0x430C0000, 0x428C0000};
s32 D_80800D20_chboggyboy[4] = {0x1304A4, 0xA0140, 0x0, 0x0};
