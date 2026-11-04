// Probably the Mayahem Temple treasure-chamber official ("gold horde"): patrols, talks to
// the player and takes back the Golden Relic, then opens the chamber and starts the transition.
#include "common.h"

extern int D_80801240_chamazongoldhordeofficial[];
extern void *func_80100094(Actor *, u32);
extern void func_8010A3E8(Actor *, f32);
typedef struct {
    s16 pos[3];
    u16 unk_6 : 9;
    u16 pad_0 : 7;
    u32 pad_1;
    u32 unk_C : 9;
    u32 pad_2 : 23;
} GoldHordeProp;
extern s16 D_808012D0_chamazongoldhordeofficial[];
extern f32 D_808012DC_chamazongoldhordeofficial[];
extern s16 D_808012F4_chamazongoldhordeofficial[];
extern s32 D_808012FC_chamazongoldhordeofficial[];
extern void func_800EEB9C(f32 *, f32, f32);

extern s32 func_80101E14(Actor *, f32);
extern void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern f32 func_800136E4(f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA994(s32, s32, s16, s32, s32, s32, s32);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 func_800F640C(s32, s32);
extern s32 func_800F54E4(void);
extern s32 func_8008FE14(void);
extern s32 D_80801324_chamazongoldhordeofficial[];
extern s32 D_80801340_chamazongoldhordeofficial[];
extern s32 D_8080135C_chamazongoldhordeofficial[];
void _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
typedef struct {
    u8 pad[0x68];
    u8 cycles;
} GoldHordeOfficialState;
extern u8 D_808011D0_chamazongoldhordeofficial[];
extern u8 D_80801368_chamazongoldhordeofficial[];
extern u8 D_80801380_chamazongoldhordeofficial[];
typedef struct {
    u8 pad_0[8];
    s16 target_x;
    s16 target_z;
    s16 patrol_x[15];
    s16 patrol_z[15];
    u8 patrol_count;
    u8 unk_49[15];
    u8 unk_58[15];
    u8 patrol_index;
    u8 pad_1[2];
    s16 direction;
    u8 subgame[1];
} GoldOfficialState601;
extern s32 D_80801288_chamazongoldhordeofficial[];
extern s32 D_80801294_chamazongoldhordeofficial[];
extern s32 D_808012A0_chamazongoldhordeofficial[];
extern s32 D_808012BC_chamazongoldhordeofficial[];
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern f32 func_800D8FF8(void);
extern void func_80102924(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern f32 func_800F5F7C(s32);
extern f32 func_8010CD28(Actor *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_8008F990(f32 *, f32);
extern void func_8010D5DC(Unk80132ED0 *);
extern void func_800902E4(f32 *, f32, s32, Actor **);
extern u8 D_808011C0_chamazongoldhordeofficial[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
void func_80800DB4_chamazongoldhordeofficial();
void func_80800E18_chamazongoldhordeofficial();
int func_80800F40_chamazongoldhordeofficial();

int chamazongoldhordeofficial_entrypoint_0()
{
    return (int) &D_80801240_chamazongoldhordeofficial;
}

void func_8080000C_chamazongoldhordeofficial(Actor *actor)
{
    GoldHordeProp *props[15];
    u8 *data;
    s32 i;

    data = func_80100094(actor, 0);
    func_8010A3E8(actor, 0.65f);
    _subaddieDll_entrypoint_10(0x125, data);
    *(s16 *) (data + 8) = -999;
    *(s16 *) (data + 0x6A) = 1;
    data[0x48] = _gccubesearch_entrypoint_9(0x122, props, 15);
    for (i = 0; i < data[0x48]; i++) {
        ((s16 *) (data + 0xC))[i] = props[i]->pos[0];
        ((s16 *) (data + 0x2A))[i] = props[i]->pos[2];
        data[0x49 + i] = props[i]->unk_6;
        data[0x58 + i] = props[i]->unk_C >> 1;
    }
    func_80800DB4_chamazongoldhordeofficial(actor, -1);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x127, actor->position),
                              (u8 *) actor + 0x18);
    _susubgame_entrypoint_0(actor, (u8 *) func_80100094(actor, 0) + 0x6C, 0);
    _susubgame_entrypoint_12((u8 *) func_80100094(actor, 0) + 0x6C,
                             (s32 *) D_808011C0_chamazongoldhordeofficial);
}

void func_80800E94_chamazongoldhordeofficial();

void func_80800E64_chamazongoldhordeofficial();

s32 func_80800C60_chamazongoldhordeofficial();

void func_80800A84_chamazongoldhordeofficial();

// Per-frame update; unk70_10 is the state.
void func_80800150_chamazongoldhordeofficial(Actor *actor)
{
    GoldOfficialState601 *state;
    s32 player;
    f32 cam_pos[3];
    f32 target_pos[3];

    state = func_80100094(actor, 0);
    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    _sudeflect_entrypoint_0(actor->position, 150.0f, 150.0f, 10);
    switch (actor->unk70_10) {
        case 1:
            func_80800E64_chamazongoldhordeofficial((s32) actor);
            if (state->target_x == -999) {
                _subaddieDll_entrypoint_12(state, &state->target_x);
            }
            if (func_80800F40_chamazongoldhordeofficial(actor, state->target_x,
                                                        state->target_z)) {
                func_80800E18_chamazongoldhordeofficial(actor);
            }
            func_80800C60_chamazongoldhordeofficial(actor);
            break;
        case 2:
            func_80800E64_chamazongoldhordeofficial((s32) actor);
            if (func_80800F40_chamazongoldhordeofficial(actor, state->patrol_x[state->patrol_index],
                                                        state->patrol_z[state->patrol_index])) {
                func_80102424(actor, 3);
            }
            func_80800C60_chamazongoldhordeofficial(actor);
            break;
        case 3:
            func_80800E64_chamazongoldhordeofficial((s32) actor);
            func_80102924(actor, (f32) (state->unk_58[state->patrol_index] * 2));
            func_80102B2C(actor, func_800D8FF8() * 180.0f);
            if (func_80102CF4(actor, 10.0f)) {
                func_80102424(actor, 4);
            }
            func_80800C60_chamazongoldhordeofficial(actor);
            break;
        case 4:
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             &D_80801288_chamazongoldhordeofficial,
                                             &D_808012A0_chamazongoldhordeofficial);
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             &D_80801294_chamazongoldhordeofficial,
                                             &D_808012BC_chamazongoldhordeofficial);
            func_80800A84_chamazongoldhordeofficial(actor);
            if (func_80101DDC(actor)) {
                func_80102424(actor, 5);
            }
            func_80800C60_chamazongoldhordeofficial(actor);
            break;
        case 5:
            func_80800E64_chamazongoldhordeofficial((s32) actor);
            func_80102924(actor,
                          (f32) (state->unk_58[state->patrol_index] * 2 + state->direction * 120));
            func_80102B2C(actor, func_800D8FF8() * 630.0f);
            if (func_80102CF4(actor, 10.0f)) {
                if (state->direction == 1) {
                    state->direction = -1;
                } else {
                    state->direction = 1;
                }
                func_80102424(actor, 1);
            }
            func_80800C60_chamazongoldhordeofficial(actor);
            break;
        case 6:
            func_80800C60_chamazongoldhordeofficial(actor);
            func_80800E94_chamazongoldhordeofficial(actor);
            break;
        case 7:
            func_8010CEAC(actor);
            break;
        case 9:
            func_8010CEAC(actor);
            break;
        case 10:
            player = func_800F54E4();
            func_8010CEAC(actor);
            if (!actor->unk64_19 && func_800F5F7C(player) < 10.0f &&
                func_800F56AC(player) != 0x12 && func_800F64A4(player, 1)) {
                func_800EEB9C(cam_pos, func_8010CD28(actor), 400.0f);
                func_800EF04C(cam_pos, actor->position);
                func_8008F8B0();
                func_8008F904(func_8010D5DC, actor->unk0);
                func_8008F8D8(1);
                func_8008F990(cam_pos, 300.0f);
                _susubgame_entrypoint_6(actor, (u8 *) func_80100094(actor, 0) + 0x6C, 0x12,
                                        0x60, 0);
                func_80102424(actor, 7);
                actor->unk64_19 = 1;
            }
            break;
        case 11:
            func_8010CEAC(actor);
            func_80800E94_chamazongoldhordeofficial(actor);
            func_800902E4(actor->position, 500.0f, 0x1D9, &actor);
            if (func_8008FE14() == 0x1D9 && func_80090818()) {
                func_800EEB9C(target_pos, func_8010CD28(actor), 200.0f);
                func_800EF04C(target_pos, actor->position);
                func_80090768(target_pos);
                func_800DA544(0x5A);
                _subaddiedialog_entrypoint_11(actor->unk0, 0xF2D, 0xE, actor->position, 0x31);
                func_80102424(actor, 6);
            }
    }
}

int func_80800630_chamazongoldhordeofficial(s32 actor)
{
    s32 actor_ref;
    actor_ref = actor | 0; // Matching: `| 0` is needed for the match.
    _suexpression_entrypoint_8(actor_ref, 1);
    if (_susubgame_entrypoint_2(actor_ref, (s32) func_80100094(actor_ref, 0) + 0x6C)) {
        _susubgame_entrypoint_4(actor_ref, (s32) func_80100094(actor_ref, 0) + 0x6C);
    }
}

void func_80800690_chamazongoldhordeofficial(u8 *actor)
{
    s32 search;

    search = _gccubesearch_entrypoint_15((*(u32 *) (actor + 0x6C) << 11) >> 20,
                                          *(u32 *) (actor + 0x6C) >> 21, actor + 4, actor);
    _gspropctrl_entrypoint_11(search, actor + 4);
    *(f32 *) (actor + 0x48) = (f32) _gspropctrl_entrypoint_12(search);
}

void func_80801060_chamazongoldhordeofficial();

void func_80800CD8_chamazongoldhordeofficial();

s32 func_808006F8_chamazongoldhordeofficial(u8 *actor, s32 event, s32 payload)
{
    f32 view_pos[3];
    f32 focus_pos[3];

    switch (event) {
        case 0x3D:
            func_80801060_chamazongoldhordeofficial(actor);
            break;
        case 0x2E:
            func_80800CD8_chamazongoldhordeofficial(actor, ((s16 *) &payload)[0],
                                                    ((s16 *) &payload)[1]);
            break;
        case 0xB:
            if (payload == 4) {
                _capod_entrypoint_14();
                _glcutDll_entrypoint_6(0x119, 0x34);
                return 4;
            }
            return 3;
        case 0x52:
            func_800EFA4C(view_pos, 0, func_8010CD28(actor), 0);
            _gcdialogcamera_entrypoint_3(&D_808011C0_chamazongoldhordeofficial,
                                         *(s32 *) (actor + 0x38));
            _gcdialogcamera_entrypoint_5(view_pos);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(actor, (s32) func_80100094(actor, 0) + 0x6C,
                                           payload & 0xFFFF, (u32) (payload & 0xFFFF0000) >> 0x10);
        case 0x95:
            _suexpression_entrypoint_7(actor, 1, 0x31);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 0x42A00000, 0x41200000);
            if (func_800DA298(0x5A) != 0 || _glcutDll_entrypoint_20() != 0) {
                func_80102424(actor, 6);
                if (_glcutDll_entrypoint_20() == 0) {
                    func_80108B04(actor, 0);
                }
                if (func_800DA298(0x59C) == 0 && _glcutDll_entrypoint_20() == 0) {
                    _susubgame_entrypoint_5(actor, (s32) func_80100094(actor, 0) + 0x6C, 3, 1,
                                            0x2000);
                    _subaddiedialog_entrypoint_11(*(s32 *) actor, 0xF59, 0xE, actor + 4, 0x31);
                }
            } else if (func_80800C18_chamazongoldhordeofficial() != 0 && func_8008FD48() == 1) {
                func_80800690_chamazongoldhordeofficial(actor);
                func_80102424(actor, 0xA);
            } else if (func_800EA090() == 1 && func_800DA298(0x59C) == 0 && func_8008FD48() == 1) {
                func_80800690_chamazongoldhordeofficial(actor);
                func_800EEB9C(focus_pos, *(f32 *) (actor + 0x48), 3e+02f);
                func_800EF04C(focus_pos, actor + 4);
                func_8008F8B0();
                func_8008F904(&func_8010D5DC, *(s32 *) actor);
                func_8008F8D8(1);
                func_8008F990(focus_pos, 3e+02f);
                _susubgame_entrypoint_6(actor, (s32) func_80100094(actor, 0) + 0x6C, 0xF, 0x60,
                                        0);
                func_80102424(actor, 9);
            } else {
                func_80800E18_chamazongoldhordeofficial(actor);
            }
            break;
        case 0x32:
            func_800904C8(0x8D);
            if (((u32) *(u16 *) (actor + 0x72) >> 0xA) == 9) {
                _subaddiedialog_entrypoint_11(*(s32 *) actor, 0xF0D, 0xE, actor + 4, 0x31);
            } else {
                func_80102424(actor, 0xB);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800A84_chamazongoldhordeofficial(Actor *actor)
{
    f32 yaw[2];
    f32 spawn_pos[3];
    u32 i;
    s32 effect;

    if (actor->unk7C_12) {
        for (i = 0; i < 6; i++) {
            if (func_80101E14(actor, D_808012DC_chamazongoldhordeofficial[i])) {
                _subaddieskeleton_entrypoint_2(actor->unk0,
                                               D_808012D0_chamazongoldhordeofficial[i], spawn_pos);
                yaw[0] = func_800136E4(actor->rotation[1] + 180.0f - 45.0f);
                yaw[1] = func_800136E4(yaw[0] + 90.0f);
                for (i = 0; D_808012F4_chamazongoldhordeofficial[i] != -1; i++) {
                    effect =
                        func_800BABB8(0, spawn_pos, NULL, 1.0f, D_808012FC_chamazongoldhordeofficial);
                    func_800BA994(effect, 0x118, yaw[0], 0x258, 0x140, yaw[1], 0x320);
                    func_800BA670(effect, D_808012F4_chamazongoldhordeofficial[i]);
                    func_800BA22C(effect, 2);
                }
                return;
            }
        }
    }
}

// True while the player holds the Golden Relic.
int func_80800C18_chamazongoldhordeofficial(void)
{
    return func_800F640C(func_800F54E4(), 0x1D9) != 0 || func_8008FE14() == 0x1D9;
}

// Talks to the player; dialog depends on whether the relic was returned (flag 0x5A).
s32 func_80800C60_chamazongoldhordeofficial(s32 actor)
{
    if (func_800F56AC(func_800F54E4()) == 0x12) {
        return 0;
    }
    if (func_800DA298(0x5A) != 0) {
        return _subaddiedialog_entrypoint_7(actor, actor + 4,
                                            &D_80801340_chamazongoldhordeofficial);
    }
    return _subaddiedialog_entrypoint_7(actor, actor + 4,
                                        &D_80801324_chamazongoldhordeofficial);
}

// Dialog end: relic/treasure dialogs open the chamber and start the cutscene to Mayahem Temple.
void func_80800CD8_chamazongoldhordeofficial(s32 actor, s32 dialog_id, s32 unk_2)
{
    s32 actor_ref = actor;
    switch (dialog_id) {
        case 0xF2D:
            _susubgame_entrypoint_4(actor_ref, (s32) func_80100094(actor_ref, 0) + 0x6C);
            func_800D1000(5, 1, 0, 1, 0);
            _capod_entrypoint_13(*(s32 *) ((char *) actor_ref + 0x0), 0, 4, 0x2830);
            return;
        case 0xF0D:
        case 0xF59:
            _susubgame_entrypoint_4(actor_ref, (s32) func_80100094(actor_ref, 0) + 0x6C);
            func_800DA544(0x59C);
            _glcutDll_entrypoint_6(0xB8, 0xD);
            return;
        default:
            func_80800E18_chamazongoldhordeofficial(actor_ref);
        case 0xF2E:
            return;
    }
}

void func_80800DB4_chamazongoldhordeofficial(actor, prev_index) Actor *actor;
s32 prev_index;
{
    u8 *state;

    state = func_80100094(actor, 0);
    do {
        state[0x67] = func_800DC128(0, state[0x48] - 1);
    } while (prev_index == state[0x67]);
    *(f32 *) &actor->actorData[3] = 700.0f;
}

void func_80800E18_chamazongoldhordeofficial(actor) void *actor;
{
    void *state = func_80100094(actor, 0);
    func_80800DB4_chamazongoldhordeofficial(actor, ((u8 *) state)[0x67]);
    func_80102424(actor, 2);
    *(s16 *) ((u8 *) state + 0x8) = -999;
}

void func_80800E64_chamazongoldhordeofficial(s32 actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor + 4,
                                     (s32 *) D_808011D0_chamazongoldhordeofficial,
                                     &D_8080135C_chamazongoldhordeofficial);
}

void func_80800E94_chamazongoldhordeofficial(Actor *actor)
{
    GoldHordeOfficialState *state;
    s32 limit;

    _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                     D_808011D0_chamazongoldhordeofficial,
                                     D_80801368_chamazongoldhordeofficial);
    if (func_80101E14(actor, 0.5f)) {
        state = func_80100094(actor, 0);
        state->cycles++;
        limit = _glcutDll_entrypoint_20() ? 1 : 5;
        if (limit < state->cycles) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_80801380_chamazongoldhordeofficial);
            state->cycles = 0;
        }
    }
}

// Steers toward (x, z); true once close to it.
int func_80800F40_chamazongoldhordeofficial(Actor *actor, s32 x, s32 z)
{
    f32 target[3];
    f32 turn;
    s32 reached;
    target[0] = x;
    target[1] = actor->position[1];
    target[2] = z;
    if (func_800F0064(actor->position, 200.0f, target))
        turn = func_800D8FF8() * 630.0f;
    else
        turn = func_800D8FF8() * 180.0f;
    func_80102924(actor, func_80102D78(actor, target));
    func_80102B2C(actor, turn);
    reached = func_800F0064(actor->position, 80.0f, target);
    if (!reached)
        func_8010B990(actor, 0x201005);
    return func_80102CF4(actor, 10.0f) && reached;
}

void func_80801060_chamazongoldhordeofficial(Actor *actor)
{
    extern f32 func_800F1DCC(f32, f32);
    f32 pos[3];
    Actor *relic;

    func_800EEB9C(pos, actor->rotation[1], 200.0f);
    func_800EF04C(pos, actor->position);
    relic = (Actor *) func_80108528(0x1D9, pos, 0, &actor);
    relic->rotation[1] = func_800F1DCC(actor->rotation[1], 180.0f);
}

// TU-NOTE: the overlay .data tables are defined in this file; their function pointers need them in the same unit for IDO to schedule the code as in the original. Values are from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_808011C0_chamazongoldhordeofficial[16] = {0x43, 0x66, 0x0, 0x0, 0x43, 0x16, 0x0, 0x0,
                                               0x42, 0xC8, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0};
u8 D_808011D0_chamazongoldhordeofficial[16] = {0x0, 0x13, 0x4, 0xBC, 0x0,  0xD,  0x0, 0xD9,
                                               0x1, 0x26, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x0};
u32 D_808011E0_chamazongoldhordeofficial[24] = {
    0x0,        0x0,       0x3F19999A, 0x1B40001, 0x3F19999A, 0x1B40001, 0x3F19999A, 0x1B40001,
    0x40E00000, 0x1B50002, 0x3F19999A, 0x1B40001, 0x40400000, 0x1B60001, 0x40C33333, 0x3E30001,
    0x3F333333, 0x1D60001, 0x40C33333, 0x3E30001, 0x40C33333, 0x3E30001, 0x40C33333, 0x3E30001};
int D_80801240_chamazongoldhordeofficial[18] = {0x15E0115,
                                                0x66B0002,
                                                (u32) &D_808011E0_chamazongoldhordeofficial,
                                                (u32) func_80800150_chamazongoldhordeofficial,
                                                (u32) func_80105834,
                                                (u32) func_80101870,
                                                0x0,
                                                0x40000000,
                                                0x0,
                                                0x160,
                                                (u32) func_80800630_chamazongoldhordeofficial,
                                                0x0,
                                                0x840000,
                                                (u32) func_8080000C_chamazongoldhordeofficial,
                                                (u32) func_80107C2C,
                                                -0x7FFFFF7E,
                                                (u32) func_808006F8_chamazongoldhordeofficial,
                                                0x0};
s32 D_80801288_chamazongoldhordeofficial[3] = {0x1304B8, 0x167FF8, 0x0};
s32 D_80801294_chamazongoldhordeofficial[3] = {0x1304B9, 0x167FF8, 0x0};
s32 D_808012A0_chamazongoldhordeofficial[7] = {0x3E99999A, 0x3EBC6A7F, 0x3EE353F8, 0x3F051EB8,
                                               0x3F19999A, 0x3F2B851F, -0x40800000};
s32 D_808012BC_chamazongoldhordeofficial[5] = {0x3EBAE148, 0x3EE66666, 0x3F08F5C3, 0x3F1EB852,
                                               -0x40800000};
s16 D_808012D0_chamazongoldhordeofficial[6] = {0x4, 0x5, 0x4, 0x5, 0x4, 0x5};
f32 D_808012DC_chamazongoldhordeofficial[6] = {0.33f, 0.4f, 0.478f, 0.55f, 0.63f, 0.7f};
s16 D_808012F4_chamazongoldhordeofficial[4] = {0x65A, 0x65B, 0x65C, -0x1};
s32 D_808012FC_chamazongoldhordeofficial[10] = {
    0x210001B, -0x8330834, 0x2A0300, 0x3000300, 0x3000015, 0x20002, 0x70002, 0x50000, 0x40099, 0x0};
s32 D_80801324_chamazongoldhordeofficial[7] = {0x1F4,    0xF2F,   0x201,    0xF580000,
                                               0x310000, 0xC0000, 0x7000000};
s32 D_80801340_chamazongoldhordeofficial[7] = {0x5A01F4, 0xF2E,   0x201, 0x12080000,
                                               0x310000, 0xC0000, 0x0};
s32 D_8080135C_chamazongoldhordeofficial[3] = {0x3ED70A3D, 0x3F6B851F, -0x40800000};
u8 D_80801368_chamazongoldhordeofficial[24] = {0x3E, 0x4C, 0xCC, 0xCD, 0x3E, 0xAE, 0x14, 0x7B,
                                               0x3E, 0xF5, 0xC2, 0x8F, 0x3F, 0x23, 0xD7, 0xA,
                                               0x3F, 0x4C, 0xCC, 0xCD, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801380_chamazongoldhordeofficial[16] = {0x0, 0x13, 0x6, 0x12, 0x0, 0xD, 0x1, 0xC,
                                               0x1, 0x26, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
