// Hailfire Peaks Colosseum kickball, built on su/kickball: the match controller, the kickball
// actors, and the AI kickers that chase and kick balls toward a goal.
#include "common.h"

extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800BBCB8(Actor *, int, float, int, void (*)(void));
extern f32 D_80804CB4_chcollballcontrol[];
extern void *func_80100094(Actor *, u32);
extern s32 D_80804CF0_chcollballcontrol[][6];
extern s32 D_80804D68_chcollballcontrol[];
typedef struct {
    u8 pad_0[0x20];
    s32 local_0[4];
    u8 local_1[4];
    u8 local_2[4];
    u8 pad_1;
    u8 local_3;
    u8 local_4;
    u8 local_5;
    u8 local_6;
} CollballScoreState;
extern Actor *func_80106790();
extern Unk80132ED0 *_sukickball_entrypoint_8(Actor *, s32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 _sukickball_entrypoint_6(Actor *, s32);
extern s32 D_80804D7C_chcollballcontrol[];
extern u8 _sukickball_entrypoint_3(void);
extern u8 _gcstatusDll_entrypoint_11(void);
extern f32 _sukickball_entrypoint_15(s32);
typedef struct {
    u8 pad_0[10];
    u8 local_0[4];
    u8 pad_1[2];
    Unk80132ED0 *local_1[4];
} CollisionBallPlayers;
typedef struct {
    s32 local_0[6];
} CollballCountRecord;
extern CollballCountRecord D_80804D90_chcollballcontrol;
typedef struct {
    u8 pad0[0x24];
    u32 unk24_22 : 10;
    u32 pad24 : 22;
} BallMarker;
typedef struct {
    BallMarker *marker;
    s32 pad4;
    s32 flags;
} BallEntry;
extern s32 *func_800BE444(f32 *);
extern void *func_800E9E88(s32);
extern void *func_800E9EB4(s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC298(f32);
extern f32 D_80804CC8_chcollballcontrol[][2];
extern void *D_80804DA8_chcollballcontrol;
extern s32 D_80804DF0_chcollballcontrol;
extern void func_800B4470(f32 *, f32 *, void *, s32, f32, f32, s32, s32, s32);
extern void _sukickball_entrypoint_11(Actor *, s32);
extern void func_800F4F98();
typedef struct {
    u8 pad_0[0x14];
    f32 local_0;
    f32 local_1;
} CollisionBallLaunchState;
extern f32 func_800DC178(f32, f32);
extern s32 D_80804C64_chcollballcontrol[];
extern s32 D_80804E08_chcollballcontrol[];
extern u8 D_80804C74_chcollballcontrol[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 D_80804E4C_chcollballcontrol[];
extern u32 D_80804E94_chcollballcontrol[];
extern u32 D_80804EE4_chcollballcontrol[];
typedef struct {
    Unk80132ED0 *local_0;
    s32 local_1;
    u32 local_2;
} CollballSpatialEntry;
typedef struct {
    u8 pad_0[0x24];
    u32 local_0 : 10;
    u32 pad_1 : 22;
} CollballMarkerC010;
extern s32 *func_800BE3F8(f32 *);
typedef struct {
    u8 pad_0[0x1C];
    f32 local_0;
} CollballContact1472;
extern s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
extern u8 D_80804C84_chcollballcontrol[];
extern void *D_80804F2C_chcollballcontrol[];
extern f32 func_800D8FF8(void);
extern u8 D_80804C98_chcollballcontrol[];
extern f32 func_800F5F24(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int D_80804F58_chcollballcontrol[];
extern s32 D_80804FA0_chcollballcontrol[];
extern int D_80804FE8_chcollballcontrol[];
typedef struct {
    u8 local_0[0x64];
    u32 local_1 : 2;
    u32 local_2 : 1;
    u32 local_3 : 29;
} local_struct;
typedef struct BallMotionVector_808032CC_chcollballcontrol {
    f32 local_0[3];
} BallMotionVector_808032CC_chcollballcontrol;
extern BallMotionVector_808032CC_chcollballcontrol D_80805098_chcollballcontrol;
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
typedef union {
    s32 local_0;
    void *local_1;
} CollballControlEvent;
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct {
    u8 pad[0x65];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS101;
extern s32 D_808050B4_chcollballcontrol[];
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800EEF94();
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct {
    s32 a, b, c;
} W3;
typedef struct {
    s32 local_0;
    u8 pad_0[0x10];
    u8 local_1;
} CollisionBallState;
typedef struct {
    u8 pad_0[0x64];
    u8 local_0 : 1;
    u8 pad_1 : 1;
    u8 local_1 : 1;
    u8 local_2 : 2;
    u8 pad_2 : 3;
} CollisionBallPlayerFlags;
typedef struct BallMotionVector_8080486C_chcollballcontrol {
    f32 local_0[3];
} BallMotionVector_8080486C_chcollballcontrol;
extern u8 D_808050C0_chcollballcontrol[];
extern f32 func_800136E4(f32);
extern Actor *func_801084B0(s32, Actor **);
extern s32 func_800D211C();
extern void func_800CE8D8(s32, f32, s32);
extern void func_800FDC28(s32);
extern s32 _capod_entrypoint_17(f32);
extern s32 func_800CEB54(s32, f32);
extern u8 D_80804DF4_chcollballcontrol[];
extern f32 func_800EFBFC(f32 *, f32 *);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct {
    f32 unk0;
    u8 pad_4[0x1C];
    u8 unk20;
} BallControlLocal;
typedef struct {
    f32 local_0[4];
} CollballDistancesC010;
typedef struct {
    f32 local_0[3];
} BallMotionVector_80802CE0_chcollballcontrol;
typedef struct {
    f32 local_0;
    u8 pad_0[0x1C];
    u8 local_1;
} CollballStateC010;
typedef struct {
    u8 pad_0[0x3A];
    u8 local_0;
} CollballPlayersC010;
extern CollballDistancesC010 D_80804F3C_chcollballcontrol;
extern BallMotionVector_80802CE0_chcollballcontrol D_80804F4C_chcollballcontrol;
extern u8 _chcollballcontrol_entrypoint_1[];
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    s32 local_0;
    f32 local_1;
    f32 local_2[3];
} CollballDataTop50;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} CollballEnableTop50;
extern s32 _sukickball_entrypoint_5(Actor *, f32 *);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern void _sukickball_entrypoint_2(Actor *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, f32 *);
void func_80801108_chcollballcontrol();
void func_80801350_chcollballcontrol();
void func_80801500_chcollballcontrol();
void func_808015D4_chcollballcontrol();
void func_80801650_chcollballcontrol();
void func_808021D4_chcollballcontrol();
void func_80802264_chcollballcontrol();
void func_80802324_chcollballcontrol();
void func_808028D0_chcollballcontrol();
void func_80802964_chcollballcontrol();
void func_808029D8_chcollballcontrol();
void func_808030D0_chcollballcontrol();
void func_8080324C_chcollballcontrol();
void func_80803EF4_chcollballcontrol();
void func_80804A48_chcollballcontrol();
void func_80804AA8_chcollballcontrol();
void func_808020F4_chcollballcontrol();
int func_8080237C_chcollballcontrol();
void func_808023FC_chcollballcontrol();
void func_80802A50_chcollballcontrol();
void func_80802CE0_chcollballcontrol();
Actor *func_8080451C_chcollballcontrol();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_808006FC_chcollballcontrol(),
    func_80800DD8_chcollballcontrol();

// Match controller: difficulty tables, ball spawning, round flow, scores, end-of-round warp.
void func_80800000_chcollballcontrol(s32 *actor, s32 text_id, s32 flags)
{
    _subaddiedialog_entrypoint_11(actor[0], text_id, flags | 0xE, actor + 1, 0x33);
}

f32 func_80800040_chcollballcontrol(Actor *actor)
{
    return D_80804CB4_chcollballcontrol[((u8 *) func_80100094(actor, 0))[0x14]];
}

f32 func_80800070_chcollballcontrol(Actor *actor)
{
    return func_80800040_chcollballcontrol(actor) * 0.75f;
}

f32 func_8080009C_chcollballcontrol(actor)
Actor *actor;
{
    return func_80800040_chcollballcontrol(actor) * 0.33f;
}

f32 func_808000C8_chcollballcontrol(actor)
Actor *actor;
{
    return func_80800040_chcollballcontrol(actor) * 0.05f;
}

f32 func_808000F4_chcollballcontrol(Actor *actor)
{
    return func_808000C8_chcollballcontrol(actor);
}

s32 func_80800114_chcollballcontrol(s32 mode, s32 kind)
{
    return D_80804CF0_chcollballcontrol[mode][kind];
}

int func_80800138_chcollballcontrol(s32 mode)
{
    return D_80804D68_chcollballcontrol[mode];
}

void func_8080014C_chcollballcontrol(s32 actor)
{
    s32 i;
    u8 *data;
    u8 *entry;

    data = func_80100094(actor, 0);
    i = 0;
    entry = data;

if ((s32) data[0x3A] > 0) {
    do {
        if (data[0x39] == 1) {
            *(s32 *) (entry + 0x20) = 0x32;
        } else {
            *(s32 *) (entry + 0x20) = 0;
        }
        i += 1;
        entry += 4;
    } while (i < (s32) data[0x3A]);
}

}

// Spawns a ball of the given kind at a random arena position.
void func_808001B8_chcollballcontrol(Actor *controller, s32 kind)
{
    Actor *ball;

switch (kind) {
    case 1:
    case 6:
        ball = func_801084B0(0x1A1, &controller);
        break;
    case 5:
        ball = func_801084B0(0x1A1, &controller);
        ball->unk64_19 = 1;
        break;
    case 3:
        ball = func_801084B0(0x1A3, &controller);
        break;
    case 2:
        ball = func_801084B0(0x1A2, &controller);
        break;
    case 4:
        ball = func_801084B0(0x1A2, &controller);
        ball->unk64_19 = 1;
}

ball->position[0] = func_800DC178(-470.0f, 470.0f);
ball->position[2] = func_800DC178(-470.0f, 470.0f);
ball->unk3C = controller->unk0;
}

s32 func_808002B8_chcollballcontrol(Actor *actor, s32 msg, s32 arg)
{
    u8 *data;
    f32 prob;
    s32 unk_0;
    s32 unk_1;
    s16 *words;
    data = func_80100094(actor, 0);
    words = (s16 *) &arg;

switch (msg) {
    case 0xB:
        actor->unk79_4 = 2;
        return 3;
    case 0xE:
        switch (data[0x39]) {
            case 0:
                prob = 0.5f;
                break;
            case 1:
                prob = 0.5f;
                break;
            case 2:
                prob = 0.5f;
        }
        if (_capod_entrypoint_17(prob)) {
            _subaddiedialog_entrypoint_11(
                actor->unk0, data[0x39] + 0x12C7, 6,
                (f32 *) ((u8 *) func_80106790(((s32 *) (data + 0x14))[data[0x39]]) + 4), 0);
            actor->unk64_20 = 1;
        }
        return 3;
    case 0x2E:
        switch (words[0]) {
            case 0x12CC:
            case 0x12CD:
                if (func_800D2054(1, data[0x39] + 0x91, *(s32 *) (data + 0x20) + 0x3E80) ==
                    1) {
                    func_80800000_chcollballcontrol(actor, 0x12D4, 0x200);
                    break;
                }
            case 0x127F:
            case 0x1280:
            case 0x12D4:
                func_80800000_chcollballcontrol(actor, 0xCEB, 0x240);
                break;
            case 0xCEB:
                if (func_800D395C()) {
                    if (words[1] == 1) {
                        _gcfrontend_entrypoint_11();
                    } else {
                        _gcfrontend_entrypoint_10();
                    }
                } else if (words[1] == 1) {
                    _gcgoto_entrypoint_1(func_800EA05C(), 1);
                } else {
                    _gcgoto_entrypoint_1(0x12D, 5);
                }
                break;
            case 0x127A:
                func_800FDC28(0xF);
                func_8080014C_chcollballcontrol(actor);
                unk_1 = func_80800138_chcollballcontrol(data[0x39]);
                unk_0 = func_80800138_chcollballcontrol(data[0x39]);
                func_800CE8D8(0, unk_1, unk_0);
                func_800CE88C(0, 1);
                func_80801500_chcollballcontrol(actor, 0);
                actor->unk70_10 = 4;
                break;
            case 0x12D1:
            case 0x12D2:
                _gcfrontend_entrypoint_10();
                break;
            case 0x12C7:
            case 0x12C8:
            case 0x12C9:
                actor->unk64_20 = 0;
        }
        break;
    case 0x30:
        switch (words[0]) {
            case 0x12D1:
                return data[0x3B];
            case 0x12D4:
                return func_800D211C(data[0x39] + 0x91) - 0x3E80;
        }
        break;
    case 0x3D:
        func_808001B8_chcollballcontrol(actor, arg);
        break;
    case 0x49:
        switch (data[0x39]) {
            case 0:
            case 1:
            case 2:
                if (!func_800D395C()) {
                    if (!func_800DA9E4(data[0x39] + 0x41F, 1)) {
                        _capod_entrypoint_13(actor->unk0, 0, 1, 0x2020);
                        actor->unk79_4 = 1;
                        break;
                    }
                }
                func_800A54F8(0);
                break;
            case 4:
                _subaddiemulti_entrypoint_4(0);
        }
        break;
    default:
        return 0;
}

return 1;
}

void func_808011E8_chcollballcontrol();

void func_808008FC_chcollballcontrol();

void func_808006FC_chcollballcontrol(actor) Actor *actor;
{
    u8 *data;
    f32 dt;
    s32 kind;

    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    *(f32 *) data -= dt;
    *(f32 *) (data + 4) -= dt;

switch (actor->unk70_10) {
    case 1:
        _sukickball_entrypoint_17(actor);
        if (!func_800DA298(0x6AD) && actor->unk79_4 != 1 && !actor->unk64_20) {
            if (actor->unk79_4 == 2) {
                _capod_entrypoint_14();
            }
            kind = data[0x39];
            if (kind == 0 || kind == 1 || kind == 2) {
                func_800A54F8(0);
            }
            func_80800000_chcollballcontrol(actor, 0x127A, 0);
            actor->unk70_10 = 3;
        }
        break;
    case 3:
        _sukickball_entrypoint_17(actor);
        return;
    case 6:
        _sukickball_entrypoint_19(actor, 1, data[0x3A]);
        return;
    case 4:
        _sukickball_entrypoint_19(actor, 0, data[0x3A]);
        func_808011E8_chcollballcontrol(actor);
        if (func_800CEB54(0, 6.0f)) {
            func_800FDC28(0x10);
            return;
        }
        if (func_800CEAD0(0)) {
            func_808008FC_chcollballcontrol(actor);
        }
        break;
    case 7:
        func_808011E8_chcollballcontrol(actor);
        return;
    case 8:
        _sukickball_entrypoint_19(actor, 1, data[0x3A]);
        if (actor->unk58 > 0.0f) {
            actor->unk58 -= func_800D8FF8();
        } else {
            _gcgoto_entrypoint_1(0x12D, 5);
        }
}

}

// Round end: scores the match and starts the result dialog.
void func_808008FC_chcollballcontrol(Actor *actor)
{
    CollballScoreState *state;
    s32 ranks[4];
    s32 score_result;
    s32 ties[4];
    s32 text_id;
    s32 i;

    state = func_80100094(actor, 0);
    actor->unk70_10 = 6;
    func_80801500_chcollballcontrol(actor, 1);
    func_800FDC28(0);
    score_result = _sumultiscore_entrypoint_2(state->local_0, ranks, ties, 1, state->local_4);

if (state->local_3 < 4) {
    if (actor->unk64_19) {
        switch (ranks[0]) {
            case 1:
                if (ties[0] == 0) {
                    func_800FC6B0(0x16);
                    func_80800000_chcollballcontrol(actor, 0x12CC, 0x200);
                    break;
                }
            case 2:
            case 3:
            case 4:
                func_80800000_chcollballcontrol(actor, 0x12CD, 0x200);
                func_800FC6B0(0x17);
        }
    } else {
        switch (ranks[0]) {
            case 1:
                if (ties[0] == 0) {
                    func_800D2054(1, state->local_3 + 0x91, state->local_0[0] + 16000);
                    func_800DA544(0xA17);
                    func_800FC6B0(0x16);
                    func_80101FDC(actor, 8);
                    actor->unk58 = 2.5f;
                    break;
                }
            case 2:
            case 3:
                func_80800000_chcollballcontrol(actor, 0x127F, 0x200);
                func_800FC6B0(0x17);
                break;
            case 4:
                func_80800000_chcollballcontrol(actor, 0x1280, 0x200);
                func_800FC6B0(0x17);
        }
    }
} else {

func_800AA200(1);
for (i = 0; i < state->local_4; i++) {
    if (ranks[i] == 1)
        state->local_1[i] = 1;
    else
        state->local_1[i] = 0;
}
if (score_result != 0) {
    text_id = 0x12D1;
    state->local_5 = score_result;
} else {
    text_id = 0x12D2;
}
func_800FC6B0(0x10);
func_80800000_chcollballcontrol(actor, text_id, 0);
}
}

void func_80800B5C_chcollballcontrol(ball) Actor *ball;
{
    *(f32 *) &ball->actorData[3] = func_8080009C_chcollballcontrol(ball);
    *(f32 *) &ball->actorData[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        *(f32 *) &ball->actorData[7] = -*(f32 *) &ball->actorData[7];
    }
    func_8080324C_chcollballcontrol(ball, 9);
    ball->unk64_20 = 1;
}

void func_80800BF0_chcollballcontrol(Actor *actor, f32 *pos)
{
    u8 *data;
    Actor *ball;
    f32 player_pos[3];
    s32 i;

    data = func_80100094(actor, 0);
    for (i = 0; i < data[0x3A]; i++) {
        if (_sukickball_entrypoint_6(actor, i)) {
            func_800F5A00(i, player_pos);

if (func_800F0064(player_pos, 200.0f, pos)) {
    func_800F7B9C(i, 0x38);
}

}
else
{
    ball = func_80106790(_sukickball_entrypoint_8(actor, i));

if (func_800F0064(ball->position, 200.0f, pos)) {
    func_80800B5C_chcollballcontrol(ball);
}

}
}
}

int func_80800CF8_chcollballcontrol(s32 player, s32 mode)
{
    switch (mode) {
        case 0:
            func_800F82D4(player, 0);
            break;

        case 1:
            func_800F82D4(player, 2);
            // Matching: the `| 0` is needed for the match.
            _baattach_entrypoint_6(func_800F53D0(player) | 0, 3, 0, 0);
    }
}

void func_80800D60_chcollballcontrol(Actor *actor, s32 show_intro, s32 mode)
{
    if (show_intro || func_800D395C()) {
        // Matching: the odd masks and the `^ 0` below are needed for the match.
        *((u8 *) (((char *) actor) + 0x65)) =
            ((*((u8 *) (((char *) actor) + 0x65))) & 0xFFFFu) | 8;
        _chintrotext_entrypoint_1(0x18b5, mode + (0xe ^ 0), 0, 0);
    } else {
        *((u8 *) (((char *) actor) + (0x65 & 0xFFFFFFFFu))) &= ~8;
        _chintrotext_entrypoint_2(1);
    }
}

void func_80800DD8_chcollballcontrol(actor) Actor *actor;
{
    u8 *data;
    u8 *base;
    s32 i;
    s32 j;
    s32 offset;
    Actor *ball;

    data = func_80100094(actor, 0);
    data[0x3C] = 0;
    if (!func_80090178(0x80)) {
        func_800FFAB0(actor);
        return;
    }
    func_800DA3B8(0x65A, 1);
    data[0x39] = _sukickball_entrypoint_3();
    data[0x3A] = D_80804D7C_chcollballcontrol[data[0x39]];
    switch (data[0x39]) {
        case 0:
            func_80800D60_chcollballcontrol(actor, func_800DA298(0x368), data[0x39]);
            break;
        case 1:
            func_80800D60_chcollballcontrol(actor, func_800DA298(0x369), data[0x39]);
            break;
        case 2:
            func_80800D60_chcollballcontrol(actor, func_800D0A9C(0x44, 1), data[0x39]);
            break;
        case 4:
            for (i = 0; i < 8; i++) {
                if (func_800F6438(i))
                    func_800F4CEC(i, 0);

}
data[0x3A] = _gcstatusDll_entrypoint_11();
}
for (j = 0, offset = 0; j < data[0x3A]; j++, offset += 4) {
    base = func_80100094(actor, 0);
    base[j + 0x34] = 0;
    *(s32 *) (base + offset + 0x10) = 0;
}
j = 0;
if (data[0x39] == 4)
    data[0xA] = 1;
else
    data[0xA] = 2;
data[0xB] = 1;
data[0xC] = 1;
data[0xD] = 1;
if (j < data[0x3A]) {
    base = data;
    do {
        switch (base[0xA]) {
            case 2:
                break;
            case 1:
                ball = func_801084B0(0x19F, &actor);
                ((Unk80132ED0 **) (data + 0x10))[j] = ball->unk0;
                ball->unk3C = actor->unk0;
        }

func_80801108_chcollballcontrol(actor, j);
j++;
base++;

}
while (j < data[0x3A])
    ;
}
_sukickball_entrypoint_18(actor);
data[0x3C] = 1;
}

int func_80801038_chcollballcontrol(actor)
s32 actor;
{
    Actor *data;
    s32 i;
    data = func_80100094(actor, 0);
    if (*(u8 *) ((char *) data + 0x3C) != 0) {
        func_800DA3B8(0x65A, 0);
        if (*(u8 *) ((char *) data + 0x39) == 4) {
            for (i = 0; i < 8; i++) {
                if (func_800F6438(i)) {
                    func_800F4CC0(i);
                }
            }

}
}
}

void func_808010B8_chcollballcontrol(Actor *actor, s32 player)
{
    actor->unk6C_0 = player;
    if (player == 2) {
        actor->unk64_24 = 1;
    } else {
        actor->unk64_24 = 0;
    }
}

int func_808010F8_chcollballcontrol(s32 actor[3])
{
    return *(s32 *) ((char *) actor + 0x6C) & 0x1FF;
}

void func_80801108_chcollballcontrol(actor, player) Actor *actor;
s32 player;
{
    CollisionBallPlayers *data;
    Actor *ball;
    f32 pos[3];

    data = (CollisionBallPlayers *) func_80100094(actor, 0);
    switch (data->local_0[player]) {
        case 1:
            ball = func_80106790(data->local_1[player]);
            _sukickball_entrypoint_16(player, ball->position);
            ball->rotation[1] = _sukickball_entrypoint_15(player);
            ball->unk54 = ball->rotation[1];
            func_808010B8_chcollballcontrol(ball, player);
            break;
        case 2:
            func_800F82D4(player, 2);
            pos[0] = 0.0f;
            pos[1] = _sukickball_entrypoint_15(player);
            pos[2] = 0.0f;
            func_800F832C(player, pos);
            _sukickball_entrypoint_16(player, pos);
            func_800F8294(player, pos);
    }
}

void func_808011E8_chcollballcontrol(Actor *actor)
{
    s32 spawn_kind;
    CollballCountRecord counts;
    u8 *data;

    data = func_80100094(actor, 0);
    counts = D_80804D90_chcollballcontrol;
    spawn_kind = -1;
    func_80801350_chcollballcontrol(actor, &counts);
    if (counts.local_0[1] < func_80800114_chcollballcontrol(data[0x39], 1))
        spawn_kind = 1;
    else if (counts.local_0[2] < func_80800114_chcollballcontrol(data[0x39], 2))
        spawn_kind = 2;
    else if (counts.local_0[3] < func_80800114_chcollballcontrol(data[0x39], 3))
        spawn_kind = 3;
    else if (counts.local_0[4] < func_80800114_chcollballcontrol(data[0x39], 4))
        spawn_kind = 4;
    else if (counts.local_0[5] < func_80800114_chcollballcontrol(data[0x39], 5))
        spawn_kind = 5;
    if (spawn_kind >= 0) {
        func_80108B04(actor, spawn_kind);
        return;
    }
    if (counts.local_0[0] < func_80800114_chcollballcontrol(data[0x39], 0)) {
        func_80801650_chcollballcontrol(actor);
    }
}

void func_80801350_chcollballcontrol(actor, counts) Actor *actor;
s32 *counts;
{
    s32 i;
    s32 *cell;
    BallEntry *entry;
    BallEntry *end;

    for (i = 0; i < 6; i++) {
        counts[i] = 0;
    }
    cell = func_800BE444(actor->position);
    for (; *cell; cell++) {
        entry = func_800E9E88(*cell);
        end = func_800E9EB4(*cell);
        for (; entry < end; entry++) {
            if (entry->flags & 1) {
                switch (entry->marker->unk24_22) {
                    case 0x44:
                        if (func_80106790(entry->marker)->unk64_19) {
                            counts[5]++;
                        } else {
                            counts[1]++;
                        }
                        break;
                    case 0x43:
                        if (func_80106790(entry->marker)->unk64_19) {
                            counts[4]++;
                        } else {
                            counts[2]++;
                        }
                        break;
                    case 0x42:
                        counts[3]++;
                }
            }

}
}
counts[0] = counts[1] + counts[2] + counts[3] + counts[4] + counts[5];
}

void func_80801500_chcollballcontrol(actor, action) s32 actor;
s32 action;
{
    s32 *data;
    s32 i;

    data = func_80100094(actor, 0);
    i = 0;
    if ((s32) *(u8 *) ((char *) data + 0x3A) > 0) {
        do {
            func_808015D4_chcollballcontrol(actor, i, action);
            i += 1;
        } while (i < (s32) *(u8 *) ((char *) data + 0x3A));
    }
}

void func_80801578_chcollballcontrol(Unk80132ED0 *info, s32 action)
{
    Actor *ball;
    ball = func_80106790(info);
    switch (action) {
        case 0:
            func_8080324C_chcollballcontrol(ball, 2);
            break;

        case 1:
            func_8080324C_chcollballcontrol(ball, 0xB);
    }
}

void func_808015D4_chcollballcontrol(actor, player, action) Actor *actor;
s32 player;
s32 action;
{
    CollisionBallPlayers *data;

    data = func_80100094(actor, 0);
    switch (data->local_0[player]) {
        case 0:
            break;
        case 2:
            func_80800CF8_chcollballcontrol(player, action);
            break;
        case 1:
            func_80801578_chcollballcontrol(data->local_1[player], action);
    }
}

void func_80801650_chcollballcontrol(actor) Actor *actor;
{
    u8 *data;
    f32 roll;
    s32 kind;

    data = func_80100094(actor, 0);
    roll = func_800DC0C0();
    if (func_800EA05C() == 0x12D && actor->unk70_10 == 1) {
        return;
    }
    if (roll < D_80804CC8_chcollballcontrol[data[0x39]][0] && data[0x39] != 1) {
        kind = func_800DC298(0.5f) || !data[0x39] ? 1 : 5;
    } else if (roll < D_80804CC8_chcollballcontrol[data[0x39]][1]) {
        kind = func_800DC298(0.5f) ? 2 : 4;
    } else {
        kind = 3;
    }
    func_80108B04(actor, kind);
}

int chcollballcontrol_entrypoint_0()
{
    return &D_80804DA8_chcollballcontrol;
}

// Kickball actor: rises in, is carried and kicked, bursts in goal particles.
void func_80801764_chcollballcontrol(Actor *actor, s32 new_state)
{
    u8 *data;
    data = func_80100094(actor, 0);
    if (actor->unk70_10 == 2 && new_state != actor->unk70_10) {
        if (actor->unk3C) {
            if (_sukickball_entrypoint_6(func_80106790(actor->unk3C), data[0x20]))
                func_800F4F98(data[0x20], actor->unk0);
            _sukickball_entrypoint_11(func_80106790(actor->unk3C), data[0x20]);
        }
    }
    if (actor->unk70_10 == 3 && new_state == 2 && (actor->unk0->unk24 >> 22) == 0x42) {
        *(f32 *) (data + 0x14) = 20.0f;
        *(f32 *) (data + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(actor);
        func_808021D4_chcollballcontrol(actor);
        new_state = 4;
    }
    func_80101FDC(actor, new_state);
    if (actor->unk70_10 == 6) {
        func_808021D4_chcollballcontrol(actor);
        _subaddiefade_entrypoint_3(actor);
        func_800B4470(actor->position, 0, &D_80804DF0_chcollballcontrol, 1, 0.75f, 0.0f, 125, 250,
                      0);
        switch (actor->unk0->unk24 >> 22) {
            case 0x44:
                func_80802264_chcollballcontrol(actor, 1);
                break;
            case 0x43:
                func_80802264_chcollballcontrol(actor, 2);
                break;
        }
    }
}

void func_80801920_chcollballcontrol(Actor *actor)
{
    void *data;
    // Matching: `0 * 0` and `.0f` are needed for the match.
    data = func_80100094(actor, 0 * 0);
    *((u8 *) (((char *) data) + 0x20)) = 0x7F;
    *((float *) (((char *) data) + 4)) = 0.0f;
    *((float *) (((char *) data) + 0)) = .0f;
    *((float *) (((char *) actor) + 0x24)) = 0.0f;
}

void func_80801964_chcollballcontrol(Actor *actor)
{
    CollisionBallLaunchState *data;

    data = func_80100094(actor, 0);
    actor->unk74_17 = 0;
    func_8010A590(actor);
    actor->scale = 1.5f;
    actor->rotation[0] = func_800DC178(0.0f, 45.0f);
    actor->rotation[2] = func_800DC178(0.0f, 45.0f);
    func_80801920_chcollballcontrol(actor);
    if (actor->unk64_19) {
        data->local_0 = 20.0f;
        data->local_1 = 8.0f;
    }
    actor->alpha = 0;
    actor->position[1] = -75.0f;
}

void func_80802764_chcollballcontrol();

void func_808022F0_chcollballcontrol();

void func_808020B0_chcollballcontrol();

void func_80801A20_chcollballcontrol(Actor *actor)
{
    u8 *data;
    Actor *controller;
    f32 player_pos[3];
    f32 prev_pos[3];
    f32 unk_0[3];
    Actor *carrier;
    Actor *holder;
    f32 tilt_x;
    f32 tilt_z;

    data = func_80100094(actor, 0);
    controller = func_80106790(actor->unk3C);
    switch (actor->unk70_10) {
        case 5:
            if (actor->position[1] < 25.0f)
                actor->position[1] += 5.0f;
            if ((f32) (u32) actor->alpha < 240.0f) {
                actor->alpha = (u32) ((f32) (u32) actor->alpha + 15.0f);
            } else if (actor->position[1] >= 25.0f) {
                actor->unk70_10 = 1;
                actor->alpha = 0xFF;
            }
            break;
        case 1:
            func_80802CE0_chcollballcontrol(actor);
            func_80802764_chcollballcontrol(actor);
            func_808020B0_chcollballcontrol(actor);
            break;
        case 2:
            func_800EE7F8(prev_pos, actor->position);
            func_80802764_chcollballcontrol(actor);
            if (_sukickball_entrypoint_6(controller, data[0x20])) {
                func_800F5A00(data[0x20], player_pos);
                actor->unk54 = func_800F5F24(data[0x20]);
                actor->position[1] = 0.0f;
                func_800EFCD8(actor->position, actor->unk54, 60.0f);
                func_800EF04C(actor->position, player_pos);
                func_800F5D70(data[0x20], unk_0);
                actor->unk50 = unk_0[0] * unk_0[0] + unk_0[2] * unk_0[2];
                func_800EE7F8((f32 *) actor->actorData, player_pos);
            } else {
                carrier = func_80106790(_sukickball_entrypoint_8(controller, data[0x20]));
                actor->position[1] = 0.0f;
                func_800EFCD8(actor->position, carrier->rotation[1], 60.0f);
                func_800EF04C(actor->position, carrier->position);
                actor->unk54 = carrier->rotation[1];
                actor->unk50 = *(f32 *) &carrier->actorData[3] * *(f32 *) &carrier->actorData[3];
                func_800EE7F8((f32 *) actor->actorData, carrier->position);

}
if (func_800EFBFC(prev_pos, actor->position) > 25.0f) {
    if (func_800DC0C0() < 0.1f) {
        func_800B4470(prev_pos, 0, D_80804DF4_chcollballcontrol, 1, 0.75f, 0.0f, 75, 150, 0);
    }

}
func_800D9078(data);
func_80802CE0_chcollballcontrol(actor);
if (_sukickball_entrypoint_7(controller, data[0x20])) {
    holder = func_80106790(_sukickball_entrypoint_8(controller, data[0x20]));

if (holder->unk64_20 == 1) {
    func_808030D0_chcollballcontrol(actor);
    holder->unk58 = 0.0f;
    holder->unk64_20 = 0;
}

}
func_808020B0_chcollballcontrol(actor);
break;
case 3:
    func_80802764_chcollballcontrol(actor);
    func_800EF1B8(actor->position, actor->rotation[1],
                  *(f32 *) &actor->actorData[3] * func_800D8FF8());
    *(f32 *) &actor->actorData[3] -= 6.0f;
    if ((actor->unk0->unk24 >> 22) == 0x42) {
        if (*(f32 *) &actor->actorData[3] < 600.0f) {
            *(f32 *) (data + 0x14) += *(f32 *) (data + 0x18);
            *(f32 *) (data + 0x18) += 0.5f;
        }

}
if (*(f32 *) &actor->actorData[3] <= 0.0f) {
    func_80801764_chcollballcontrol(actor, 1);
    func_808021D4_chcollballcontrol((u8 *) actor);
}
func_80802CE0_chcollballcontrol(actor);
if (func_800DC0C0() < 0.15f && *(f32 *) &actor->actorData[3] > 120.0f) {
    func_800B4470(actor->position, 0, D_80804DF4_chcollballcontrol, 1, 0.75f, 0.0f, 50, 100, 0);
}
func_808020B0_chcollballcontrol(actor);
break;
case 4:
    func_80802764_chcollballcontrol(actor);
    func_808020F4_chcollballcontrol((u8 *) actor);
    break;
case 6:
    *(f32 *) &actor->actorData[3] -= 15.0f;
    func_808020F4_chcollballcontrol((u8 *) actor);
    }
    if (*(f32 *) &actor->actorData[3] > 30.0f) {
        tilt_x = func_800137AC(actor->rotation[1]);
        tilt_z = func_800137C4();
        actor->rotation[0] += ((tilt_x * *(f32 *) &actor->actorData[3]) +
                                 (tilt_x * *(f32 *) &actor->actorData[3])) /
                                30.0f;
        actor->rotation[2] -= ((tilt_z * *(f32 *) &actor->actorData[3]) +
                                 (tilt_z * *(f32 *) &actor->actorData[3])) /
                                30.0f;
    }
    if ((actor->unk0->unk24 >> 22) == 0x42) {
        if (actor->unk70_10 != 4 && actor->unk70_10 != 6 && actor->unk7C_12) {
            if (func_800DC0C0() < 0.1f)
                func_808022F0_chcollballcontrol((s32) (data + 8));

}
}
if (actor->unk64_19)
    *(f32 *) (data + 0x14) += *(f32 *) (data + 0x18);
if (*(f32 *) (data + 0x1C) > 0.0f)
    *(f32 *) (data + 0x1C) -= func_800D8FF8();
}

void func_808020B0_chcollballcontrol(Actor *actor)
{
    s32 edge;

    edge = func_8080237C_chcollballcontrol();
    *(f32 *) ((char *) actor + 0x8) = 30.0f;
    if (edge != -1) {
        func_808023FC_chcollballcontrol(actor, edge);
    }
}

void func_808020F4_chcollballcontrol(actor) u8 *actor;
{
    f32 alpha_f;
    u8 alpha;
    alpha = *(u8 *) ((s8 *) actor + 0x9B);
    *(f32 *) ((s8 *) actor + 8) = (f32) (*(f32 *) ((s8 *) actor + 8) - 5.0f);
    // Matching: no-op `+= 0` is needed for the match.
    alpha += 0;
    alpha_f = (f32) alpha;

    *(u8 *) ((s8 *) actor + 0x9B) = (u8) (u32) (alpha_f * 0.7f);
    *(f32 *) ((s8 *) actor + 0x38) = (f32) (*(f32 *) ((s8 *) actor + 0x38) * 0.95f);
}

void func_808021D4_chcollballcontrol(actor) u8 *actor;
{
    s32 controller;

    controller = func_80106790(*(s32 *) ((s8 *) actor + 0x3C));
    if (((u32) *(u32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 0x24) >> 0x16) == 0x42) {
        func_80802324_chcollballcontrol(actor + 4);
        func_80802A50_chcollballcontrol(actor);
        _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80804C64_chcollballcontrol);
        _subaddiefade_entrypoint_3(actor);
        func_80801764_chcollballcontrol(actor, 4);
        func_80800BF0_chcollballcontrol(controller, actor + 4);
    }
}

void func_80802264_chcollballcontrol(actor, kind) Actor *actor;
s32 kind;
{
    s32 emitter;

    emitter = func_800BABB8(0, actor->position, NULL, 1.0f, D_80804E08_chcollballcontrol);
    func_800BA670(emitter, kind == 1 ? 0x679 : 0x67A);
    func_800BA22C(emitter, 10);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80804C74_chcollballcontrol);
}

void func_808022F0_chcollballcontrol(target) s32 target;
{
    func_800BBCB8(target, 0, 1.0f, 2, &D_80804E4C_chcollballcontrol);
}

void func_80802324_chcollballcontrol(target) Actor *target;
{
    func_800BBCB8(target, 0, 1.0f, 10, D_80804E94_chcollballcontrol);
    func_800BBCB8(target, 0, 1.0f, 5, D_80804EE4_chcollballcontrol);
}

// Returns which arena edge the position is past (0..3), or -1 if inside.
int func_8080237C_chcollballcontrol(pos)
f32 pos[3];
{
    if (pos[1] < -675.0f) {
        return 2;
    }
    if (pos[1] > 675.0f) {
        return 0;
    }
    if (pos[3] < -675.0f) {
        return 3;
    }
    if (pos[3] > 675.0f) {
        return 1;
    }
    return -1;
}

void func_80802AF8_chcollballcontrol();

void func_808023FC_chcollballcontrol(ball, side) Actor *ball;
s32 side;
{
    switch (side) {
        case 0:
            if (-183.0f < ball->position[2] && ball->position[2] < 183.0f) {
                if (ball->unk70_10 != 4 && 720.0f < ball->position[0]) {
                    func_80802AF8_chcollballcontrol(ball, 0);
                }

if (801.0f < ball->position[0]) {
    ball->position[0] = 846.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
}

}
else
{
    ball->position[0] = 720.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
    func_80801764_chcollballcontrol(ball, 6);

}
break;
case 1:
    if (ball->position[0] < 183.0f && -183.0f < ball->position[0]) {
        if (ball->unk70_10 != 4 && 720.0f < ball->position[2]) {
            func_80802AF8_chcollballcontrol(ball, 1);
        }

if (801.0f < ball->position[2]) {
    ball->position[2] = 846.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
}

}
else
{
    ball->position[2] = 720.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
    func_80801764_chcollballcontrol(ball, 6);

}
break;
case 2:
    if (ball->position[2] < 183.0f && -183.0f < ball->position[2]) {
        if (ball->unk70_10 != 4 && ball->position[0] < -720.0f) {
            func_80802AF8_chcollballcontrol(ball, 2);
        }

if (ball->position[0] < -801.0f) {
    ball->position[0] = -846.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
}

}
else
{
    ball->position[0] = -720.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
    func_80801764_chcollballcontrol(ball, 6);

}
break;
case 3:
    if (-183.0f < ball->position[0] && ball->position[0] < 183.0f) {
        if (ball->unk70_10 != 4 && ball->position[2] < -720.0f) {
            func_80802AF8_chcollballcontrol(ball, 3);
        }

if (ball->position[2] < -801.0f) {
    ball->position[2] = -846.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
}

}
else
{
    ball->position[2] = -720.0f;
    ((f32 *) ball->actorData)[3] = 0.0f;
    func_80801764_chcollballcontrol(ball, 6);

}
}
}

void func_80802764_chcollballcontrol(Actor *ball)
{
    s32 *cell;
    CollballSpatialEntry *entry;
    CollballSpatialEntry *entry_end;
    Unk80132ED0 *other_info;

    cell = func_800BE3F8(ball->position);
    while (*cell) {
        entry = func_800E9E88(*cell);
        entry_end = func_800E9EB4(*cell);
        while (entry < entry_end) {
            if (entry->local_2 & 1) {
                other_info = entry->local_0;
                if (other_info != ball->unk0) {
                    if (0x44 == ((CollballMarkerC010 *) other_info)->local_0 ||
                        0x42 == ((CollballMarkerC010 *) other_info)->local_0 ||
                        0x43 == ((CollballMarkerC010 *) other_info)->local_0) {
                        func_808028D0_chcollballcontrol(ball, func_80106790(other_info));
                    }
                    if (((CollballMarkerC010 *) other_info)->local_0 == 0) {
                        func_80802964_chcollballcontrol(
                            ball, (u32) *(u16 *) ((u8 *) other_info + 0x1A) >> 5);
                    }
                    if (0x40 == ((CollballMarkerC010 *) other_info)->local_0) {
                        func_808029D8_chcollballcontrol(ball, func_80106790(other_info));
                    }
                }
            }

entry++;
}
cell++;
}
}

void func_808028D0_chcollballcontrol(ball, other) Actor *ball;
Actor *other;
{
    CollballContact1472 *state;

    state = func_80100094(ball, 0);
    if (_sukickball_entrypoint_13(ball->position, other->position, 60.0f)) {
        if (state->local_0 <= 0.0f) {
            _subaddieaudioquick_entrypoint_2(ball, ball->position,
                                             D_80804C84_chcollballcontrol);
            state->local_0 = 0.75f;
        }
    }
}

void func_80802964_chcollballcontrol(ball, player_idx) u8 *ball;
s32 player_idx;
{
    s32 controller;
    f32 player_pos[3];

    controller = func_80106790(*(s32 **) (ball + 0x3C));
    if ((((u32) ((u16) (*(u16 *) (ball + 0x72))) >> 10) != 2) &&
        (_sukickball_entrypoint_12(controller, player_idx) != 0)) {
        func_800F5A00(player_idx, player_pos);
        _sukickball_entrypoint_13(player_pos, ball + 4, 62.999996185302734f);
    }
}

void func_808029D8_chcollballcontrol(ball, other) u8 *ball;
s32 other;
{
    s32 controller;

    controller = func_80106790((*(s32 *) ((s8 *) (ball) + (0x3C))));
    if (((u32) ((u16) (*(u16 *) ((s8 *) (ball) + (0x72)))) >> 0xA) != 2) {
        if (_sukickball_entrypoint_12(controller, func_808010F8_chcollballcontrol(other)) != 0) {
            _sukickball_entrypoint_13(other + 4, ball + 4, 62.999996185302734f);
        }
    }
}

// Releases the player slot this ball was targeting.
void func_80802A50_chcollballcontrol(ball) Actor *ball;
{
    BallControlLocal *state;
    Actor *controller;

    state = func_80100094(ball, 0);
    controller = func_80106790(ball->unk3C);
    if (state->unk20 != 0x7F) {
        if (_sukickball_entrypoint_6(controller, state->unk20)) {
            func_800F4F98(state->unk20, ball->unk0);
            _sukickball_entrypoint_11(controller, state->unk20);
        } else {
            _sukickball_entrypoint_11(controller, state->unk20);

}
state->unk20 = 0x7F;
state->unk0 = 10000000.0f;
}
}

void func_80802AF8_chcollballcontrol(Actor *ball, s32 side)
{
    Actor *controller;
    controller = func_80106790(ball->unk3C);
    func_80802A50_chcollballcontrol(ball);
    switch (*(u32 *) ((u8 *) ball->unk0 + 0x24) >> 22) {
        case 0x44:
            if (ball->unk64_19)
                _sukickball_entrypoint_9(controller, D_80804F2C_chcollballcontrol[side], 5);
            else
                _sukickball_entrypoint_9(controller, D_80804F2C_chcollballcontrol[side], 1);
            break;
        case 0x42:
            _sukickball_entrypoint_9(controller, D_80804F2C_chcollballcontrol[side], 3);
            break;
        case 0x43:
            if (ball->unk64_19)
                _sukickball_entrypoint_9(controller, D_80804F2C_chcollballcontrol[side], 4);
            else
                _sukickball_entrypoint_9(controller, D_80804F2C_chcollballcontrol[side], 2);
    }
    ball->unk70_10 = 4;
    _subaddiefade_entrypoint_3(ball);
}

void chcollballcontrol_entrypoint_1(Unk80132ED0 *handle, s32 msg, u32 value, s32 unk_3)
{
    Actor *ball;
    f32 *state;

    ball = func_80106790(handle);
    state = func_80100094(ball, 0);
    switch (msg) {
        case 3:
            func_80801764_chcollballcontrol(ball, 1);
            break;
        case 1:
            state[1] = func_800D8FF8() * value;
            func_808030D0_chcollballcontrol(ball);
    }
}

void func_80802CE0_chcollballcontrol(ball) Actor *ball;
{
    CollballStateC010 *state = func_80100094(ball, 0);
    CollballDistancesC010 distances = D_80804F3C_chcollballcontrol;
    Actor *controller;
    CollballPlayersC010 *players;
    s32 i;
    s32 best;
    f32 best_dist;

    controller = func_80106790(ball->unk3C);
    players = func_80100094(controller, 0);
    if ((controller->unk70_10 == 4 || controller->unk70_10 == 7) &&
        (state->local_0 == 0.0f || ball->unk70_10 == 1)) {
        best = 0x7F;
        best_dist = 10000000.0f;
        for (i = 0; i < players->local_0; i++) {
            if ((ball->unk70_10 != 2 || i != state->local_1) &&
                !_sukickball_entrypoint_12(controller, i)) {
                BallMotionVector_80802CE0_chcollballcontrol player_pos = D_80804F4C_chcollballcontrol;

                if (_sukickball_entrypoint_6(controller, i)) {
                    if (func_800F6C5C(i) && func_800F5410(i) == 8) {
                        func_800F5A00(i, player_pos.local_0);
                        if (func_800EFFB4(ball->position, 65.0f, player_pos.local_0)) {
                            distances.local_0[i] =
                                func_800EEB40(ball->position, player_pos.local_0);
                        }
                    }
                } else {
                    func_800EE7F8(
                        player_pos.local_0,
                        func_80106790(_sukickball_entrypoint_8(controller, i))->position);
                    if (func_800EFFB4(ball->position, 65.0f, player_pos.local_0)) {
                        distances.local_0[i] =
                            func_800EEB40(ball->position, player_pos.local_0);
                    }
                }
            }

}
for (i = 0; i < players->local_0; i++) {
    if (ball->unk70_10 != 2 || i != state->local_1) {
        if (distances.local_0[i] < best_dist) {
            best_dist = distances.local_0[i];
            best = i;
        }
    }

}
if (best != 0x7F) {
    if (state->local_1 != 0x7F) {
        if (_sukickball_entrypoint_7(controller, state->local_1)) {
            _sukickball_entrypoint_11(controller, state->local_1);
        } else {
            func_800F4F98(state->local_1, ball->unk0);
            _sukickball_entrypoint_11(controller, state->local_1);
        }
    }

state->local_1 = best;
state->local_0 = 1.5f;

if (_sukickball_entrypoint_6(controller, state->local_1)) {
    func_800F4950(state->local_1, ball->unk0, _chcollballcontrol_entrypoint_1);
} else {

Actor *target = func_80106790(_sukickball_entrypoint_8(controller, state->local_1));

((u8 *) target)[0x65] &= ~0x10;
}
switch (((CollballMarkerC010 *) ball->unk0)->local_0) {
    case 0x44:
        _sukickball_entrypoint_10(controller, state->local_1, 1);
        break;
    case 0x42:
        _sukickball_entrypoint_10(controller, state->local_1, 3);
        break;
    case 0x43:
        _sukickball_entrypoint_10(controller, state->local_1, 2);
    default:
        break;
}
func_80801764_chcollballcontrol(ball, 2);
*(f32 *) ((u8 *) ball + 0x24) = 0.0f;
}
}
}

void func_808030D0_chcollballcontrol(ball) Actor *ball;
{
    f32 kick_speed;
    Actor *controller;
    Actor *carrier;
    u8 *state;

    state = func_80100094(ball, 0);
    controller = func_80106790(ball->unk3C);
    if (_sukickball_entrypoint_6(controller, state[0x20])) {
        ball->rotation[1] = func_800F5F24(state[0x20]);
        kick_speed = func_800F10B4(*(f32 *) (state + 4), 0.0f, 1.0f, 450.0f, 900.0f);
        *(f32 *) ((u8 *) ball + 0x24) = kick_speed;
        func_800F4F98(state[0x20], ball->unk0);
        _sukickball_entrypoint_11(controller, state[0x20]);
    } else {
        carrier = func_80106790(_sukickball_entrypoint_8(controller, state[0x20]));
        ball->rotation[1] = carrier->rotation[1];
        kick_speed = func_800F10B4(carrier->unk58, 8.0f, 16.0f, 450.0f, 900.0f);
        *(f32 *) ((u8 *) ball + 0x24) = kick_speed;
        carrier->unk58 = 0.0f;
        _sukickball_entrypoint_11(controller, state[0x20]);
    }
    ball->unk70_10 = 3;
    state[0x20] = 0x7F;
    *(f32 *) state = 0.0f;
    _subaddieaudioquick_entrypoint_2(ball, ball->position, D_80804C98_chcollballcontrol);
}

void func_80803208_chcollballcontrol(s32 ball)
{
    func_80801764_chcollballcontrol(ball, 0);
}

int *chcollballcontrol_entrypoint_2()
{
    return &D_80804F58_chcollballcontrol;
}

int chcollballcontrol_entrypoint_3()
{
    return D_80804FA0_chcollballcontrol;
}

int chcollballcontrol_entrypoint_4()
{
    return (int) &D_80804FE8_chcollballcontrol;
}

// AI kicker: wanders the arena, finds the nearest ball, chases it and kicks it toward a goal.
void func_8080324C_chcollballcontrol(actor, new_state) Actor *actor;
s32 new_state;
{
    func_80102424(actor, new_state);
    switch ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) {
        case 2:
            if (((local_struct *) actor)->local_2) {
                *(u8 *) ((u8 *) actor + 0x72) = (*(u8 *) ((u8 *) actor + 0x72) & 0xFF03) | 0x28;
                *(f32 *) ((u8 *) actor + 0x58) = 0.0f;
            }
            break;
        case 8:
            *(f32 *) ((u8 *) actor + 0x50) = 0.0f;
    }
}

void func_808032CC_chcollballcontrol(Actor *kicker, f32 *other_pos)
{
    BallMotionVector_808032CC_chcollballcontrol dir;
    f32 angle;
    f32 angle_to_other;

    dir = D_80805098_chcollballcontrol;
    if (other_pos == NULL) {
        angle = func_800DC178(110.0f, 250.0f);
        angle += kicker->rotation[1];
    } else {
        angle_to_other = func_80102D78(kicker, other_pos);
        angle = func_800DC178(110.0f, 250.0f) + angle_to_other;
    }
    func_800EFCD8(dir.local_0, angle, 500.0f);
    func_800EE780((f32 *) ((u8 *) kicker + 0x18), kicker->position, dir.local_0);
    *(f32 *) ((u8 *) kicker + 0x24) = func_8080009C_chcollballcontrol(kicker);
    if (*(f32 *) ((u8 *) kicker + 0x18) > 720.0f) {
        *(f32 *) ((u8 *) kicker + 0x18) = 720.0f;
    }
    if (*(f32 *) ((u8 *) kicker + 0x20) > 720.0f) {
        *(f32 *) ((u8 *) kicker + 0x20) = 720.0f;
    }
    if (*(f32 *) ((u8 *) kicker + 0x18) < -720.0f) {
        *(f32 *) ((u8 *) kicker + 0x18) = -720.0f;
    }
    if (*(f32 *) ((u8 *) kicker + 0x20) < -720.0f) {
        *(f32 *) ((u8 *) kicker + 0x20) = -720.0f;
    }
    *(f32 *) ((u8 *) kicker + 0x34) = func_800DC178(0.25f, 1.0f);
    func_8080324C_chcollballcontrol(kicker, 7);
}

s32 func_80803420_chcollballcontrol(Actor *actor, s32 msg, CollballControlEvent data)
{
    s32 *state;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 1:
            func_800BD268(*state, (*(u32 *) ((u8 *) actor + 0x64) << 3) >> 30);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080486C_chcollballcontrol();

void func_8080405C_chcollballcontrol();

void func_80803F70_chcollballcontrol();

void func_80803E18_chcollballcontrol();

void func_80803484_chcollballcontrol(Actor *kicker)
{
    extern Vec3f D_808050A4_chcollballcontrol;
    extern u8 D_808050B0_chcollballcontrol[];

    CollballDataTop50 *state;
    char *controller;
    f32 dt;
    Vec3f move_dir;
    f32 turn;

    state = func_80100094(kicker, 0);
    dt = func_800D8FF8();
    controller = (char *) func_80106790(*(void **) ((char *) kicker + 0x3C));

    func_800BD2D0(state->local_0);
    state->local_1 -= dt;

    switch (kicker->unk70_10) {
        case 10:
            *(f32 *) ((char *) kicker + 0x2C) = 0.0f;
            *(f32 *) ((char *) kicker + 0x24) = _subaddiejoy_entrypoint_3(kicker);

            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                *(f32 *) ((char *) kicker + 0x24) =
                    func_800F10B4(*(f32 *) ((char *) kicker + 0x24), 0.0f, 1.0f, 0.0f,
                                  func_80800070_chcollballcontrol(kicker));
            } else {
                *(f32 *) ((char *) kicker + 0x24) =
                    func_800F10B4(*(f32 *) ((char *) kicker + 0x24), 0.0f, 1.0f, 0,
                                  func_80800040_chcollballcontrol(kicker));
            }

            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                if (func_800BCFC4(state->local_0, 1)) {
                    *(f32 *) ((char *) kicker + 0x58) =
                        func_800F10B4((f32) func_800BCD78(state->local_0, 1, 1) * func_800D8FF8(),
                                      0.0f, 1.0f, 450.0f, 900.0f);

                    kicker->unk64_20 = 1;
                }
            }

            func_8080486C_chcollballcontrol(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chcollballcontrol(kicker),
                                     func_80800040_chcollballcontrol(kicker));

            if (func_800BD030(state->local_0, 9)) {
                func_8080324C_chcollballcontrol(kicker, 8);
            }
            break;

        case 8:
            if (*(f32 *) ((char *) kicker + 0x50) == 0) {
                if (func_80101E14(kicker, 0.3077f)) {
                    anctrl_setPlaybackType(func_80104248(kicker), 3);

                    *(f32 *) ((char *) kicker + 0x50) = 1.0f;
                    *(f32 *) ((char *) kicker + 0x24) = 1050.0f;

                    func_800B4470(kicker->position, 0, D_808050B0_chcollballcontrol, 1, 0.75f,
                                  0.0f, 125, 250, 0);
                }
            } else if (*(f32 *) ((char *) kicker + 0x50) != 0) {
                *(f32 *) ((char *) kicker + 0x50) += dt;

                if (*(f32 *) ((char *) kicker + 0x50) > 2.5f ||
                    *(f32 *) ((char *) kicker + 0x24) < 150.0f) {
                    func_8080324C_chcollballcontrol(kicker, 2);

                    *(f32 *) ((char *) kicker + 0x24) = func_8080009C_chcollballcontrol(kicker);
                } else {
                    *(f32 *) ((char *) kicker + 0x24) *= 0.9f;
                }
            }

            *(f32 *) ((char *) kicker + 0x2C) = 0;

            func_800EEB9C((char *) kicker + 0x28, *(f32 *) ((char *) kicker + 0x48),
                          *(f32 *) ((char *) kicker + 0x24) * dt);

            func_800EF04C(kicker->position, (char *) kicker + 0x28);

            if (((CollballEnableTop50 *) kicker)->local_0) {
                _subaddiejoy_entrypoint_3(kicker);

                if (!func_80102CF4(kicker, 8.0f)) {
                    func_80102B2C(kicker, 8.0f);
                }
            }

            func_8080405C_chcollballcontrol(kicker);
            break;

        case 12:
            if (*(f32 *) ((char *) kicker + 0x24) < 150.0f) {
                func_8080324C_chcollballcontrol(kicker, 2);

                *(f32 *) ((char *) kicker + 0x24) = func_8080009C_chcollballcontrol(kicker);
            } else {
                *(f32 *) ((char *) kicker + 0x24) *= 0.9f;
            }

            *(f32 *) ((char *) kicker + 0x2C) = 0.0f;

            func_800EEB9C((char *) kicker + 0x28, *(f32 *) ((char *) kicker + 0x54),
                          *(f32 *) ((char *) kicker + 0x24) * dt);

            func_800EF04C(kicker->position, (char *) kicker + 0x28);
            break;
        case 2:
            if (((CollballEnableTop50 *) kicker)->local_0) {
                func_8080324C_chcollballcontrol(kicker, 0xA);
                *(f32 *) ((char *) kicker + 0x58) = 0.0f;
            }

            if (!func_8080451C_chcollballcontrol(kicker)) {
                func_8080324C_chcollballcontrol(kicker, 1);
            }

            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                if (func_800DC0C0() < 0.95f) {
                    func_8080324C_chcollballcontrol(kicker, 5);
                } else {
                    *(f32 *) ((char *) kicker + 0x34) = func_800DC178(0.0f, 2.5f);

                    func_8080324C_chcollballcontrol(kicker, 4);

}
}

func_8080486C_chcollballcontrol(kicker);

_sukickball_entrypoint_2(kicker, func_8080009C_chcollballcontrol(kicker),
                         func_80800040_chcollballcontrol(kicker));
break;

case 1:
    _sukickball_entrypoint_16(kicker->unk6C_0, (char *) kicker + 0x18);

    func_8080486C_chcollballcontrol(kicker);

    _sukickball_entrypoint_2(kicker, func_8080009C_chcollballcontrol(kicker),
                             func_80800040_chcollballcontrol(kicker));

    if (func_8080451C_chcollballcontrol(kicker)) {
        func_8080324C_chcollballcontrol(kicker, 2);
    }

    if (func_800EFFB4(kicker->position, 50.0f, (char *) kicker + 0x18)) {
        func_8080324C_chcollballcontrol(kicker, 3);
    }
    break;

case 3:
    if (func_8080451C_chcollballcontrol(kicker)) {
        func_8080324C_chcollballcontrol(kicker, 2);
    }

    _sukickball_entrypoint_14(kicker);

    _sukickball_entrypoint_2(kicker, func_8080009C_chcollballcontrol(kicker),
                             func_80800040_chcollballcontrol(kicker));
    break;

case 4:
    move_dir = D_808050A4_chcollballcontrol;

    if (*(f32 *) ((char *) kicker + 0x34) > 0.0f) {
        *(f32 *) ((char *) kicker + 0x34) -= dt;
    } else {
        func_8080324C_chcollballcontrol(kicker, 5);
    }

    if (!_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
        func_8080324C_chcollballcontrol(kicker, 1);
    }

    _sukickball_entrypoint_16(kicker->unk6C_0, (char *) kicker + 0x18);

    func_800EFCD8(move_dir.f, _sukickball_entrypoint_15(kicker->unk6C_0), 250.0f);

    func_800EF04C((char *) kicker + 0x18, move_dir.f);

    if (func_800F0064(kicker->position, 100.0f, (f32 *) ((char *) kicker + 0x18)) ||
        _sukickball_entrypoint_12(controller, kicker->unk6C_0) == 3) {
        func_8080324C_chcollballcontrol(kicker, 5);
    }

    func_8080486C_chcollballcontrol(kicker);

    _sukickball_entrypoint_2(kicker, func_8080009C_chcollballcontrol(kicker),
                             func_80800040_chcollballcontrol(kicker));
    break;

case 5:
    func_80803E18_chcollballcontrol(kicker);
    func_80803F70_chcollballcontrol(kicker);
    func_8080324C_chcollballcontrol(kicker, 6);
    break;

case 6:
    if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
        func_80803F70_chcollballcontrol(kicker);
    } else {
        func_8080324C_chcollballcontrol(kicker, 2);
    }
    break;

case 7:
    if (*(f32 *) ((char *) kicker + 0x34) > 0.0f) {
        *(f32 *) ((char *) kicker + 0x34) -= dt;
    } else {
        func_8080324C_chcollballcontrol(kicker, 2);
    }

    func_8080486C_chcollballcontrol(kicker);

    _sukickball_entrypoint_2(kicker, func_8080009C_chcollballcontrol(kicker),
                             func_80800040_chcollballcontrol(kicker));
    break;

case 9:
    turn = *(f32 *) ((char *) kicker + 0x34);

    *(f32 *) ((char *) kicker + 0x58) = 0.0f;
    *(f32 *) ((char *) kicker + 0x48) += turn;
    kicker->unk64_20 = 0;

    if (turn > 1.0f) {
        *(f32 *) ((char *) kicker + 0x34) = turn * 0.95f;
    } else if (turn < -1.0f) {
        *(f32 *) ((char *) kicker + 0x34) = turn * 0.95f;
    } else {
        func_8080324C_chcollballcontrol(kicker, 2);
        *(f32 *) ((char *) kicker + 0x34) = 0.0f;
    }
    }

    if (_sukickball_entrypoint_5(kicker, state->local_2)) {
        if (kicker->unk70_10 == 8) {
            func_8080324C_chcollballcontrol(kicker, 2);
        } else if (!((CollballEnableTop50 *) kicker)->local_0) {
            func_808032CC_chcollballcontrol(kicker, 0);
        }
    } else {
        func_800EE7F8(state->local_2, kicker->position);
    }
    }

    s32 func_80803D54_chcollballcontrol(current, mode)
    s32 current;
    s32 mode;
    {
        s32 choice;

        choice = current;
        switch (mode) {
            case 0:
                if (func_800DC298(0.1999969482f))
                    return 0;
                break;
            case 1:
                if (func_800DC298(0.2249908447f))
                    return 0;
                break;
            case 2:
                if (func_800DC298(0.3299865723f))
                    return 0;
        }
        while (choice == current)
            choice = func_800DC128(1, 4);
        return choice;
    }

    void func_80803E18_chcollballcontrol(u8 *kicker)
    {
        u8 *state;
        s32 status;

        state = func_80100094(kicker, 0);
        status = _sukickball_entrypoint_12(func_80106790(*(s32 *) ((s8 *) kicker + 0x3C)),
                                            *(s32 *) ((s8 *) kicker + 0x6C) & 0x1FF);
        switch (status) {
            case 2:
                _sukickball_entrypoint_4(*(s32 *) ((s8 *) kicker + 0x6C) & 0x1FF, kicker + 0x18);
                return;
            case 3:
                func_80803EF4_chcollballcontrol(
                    kicker,
                    func_80803D54_chcollballcontrol(*(s32 *) ((s8 *) kicker + 0x6C) & 0x1FF,
                                                    *(u8 *) ((s8 *) state + 0x14)));
                return;
            case 1:
                _sukickball_entrypoint_4(
                    func_80803D54_chcollballcontrol(*(s32 *) ((s8 *) kicker + 0x6C) & 0x1FF,
                                                    *(u8 *) ((s8 *) state + 0x14)),
                    kicker + 0x18);

            case 0:
                return;
        }
    }

    void func_80803EF4_chcollballcontrol(kicker, slot) s32 *kicker;
    s32 slot;
    {
        s32 controller;

        controller = func_80106790(*(s32 *) ((char *) kicker + 0x3C));
        if (_sukickball_entrypoint_6(controller, slot) != 0) {
            func_800F5A00(slot, (s32 *) ((char *) kicker + 0x18));
            return;
        }
        func_800EE7F8((s32 *) ((char *) kicker + 0x18),
                      func_80106790(_sukickball_entrypoint_8(controller, slot))->position);
    }

    void func_80803F70_chcollballcontrol(Actor *kicker)
    {
        if (_sukickball_entrypoint_12(func_80106790(kicker->unk3C), kicker->unk6C_0) == 2) {
            _sukickball_entrypoint_4(kicker->unk6C_0, (f32 *) ((u8 *) kicker + 0x18));
        }
        *(f32 *) ((u8 *) kicker + 0x54) = func_80102D78(kicker, (f32 *) ((u8 *) kicker + 0x18));
        if (!func_80102CF4(kicker, 16.0f)) {
            func_80102B2C(kicker, 16.0f);
        } else if (!func_80102CF4(kicker, 4.0f)) {
            func_80102B2C(kicker, 4.0f);
        } else {
            kicker->unk58 = func_800DC178(10.0f, 16.0f);
            kicker->unk64_20 = 1;
            func_8080324C_chcollballcontrol(kicker, 2);
        }
    }

    void func_8080405C_chcollballcontrol(u8 *kicker)
    {
        u8 *controller;
        u8 *other;
        s32 i;
        u8 *state;
        f32 target_pos[3];
        f32 other_speed;
        f32 other_dist;
        f32 other_vel[3];
        f32 push_dir[3];
        f32 player_pos[3];
        f32 own_speed;
        f32 player_pos_2[3];

        other = 0;
        controller = func_80106790(*(s32 *) (kicker + 0x3C));
        state = func_80100094(controller, 0);
        i = 0;
        if ((s32) *(u8 *) (state + 0x3A) > 0) {
            do {
                if (i != (*(s32 *) (kicker + 0x6C) & 0x1FF)) {
                    if (_sukickball_entrypoint_7(controller, i) != 0) {
                        other = func_80106790(_sukickball_entrypoint_8(controller, i));
                        target_pos[0] = *(f32 *) (other + 4);
                        target_pos[1] = *(f32 *) (other + 8);
                        target_pos[2] = *(f32 *) (other + 0xC);
                    } else {

func_800F5A00(i, target_pos);
}
if (func_800EFFB4(((f32 *) (kicker + 4)), 90.0f, target_pos) != 0) {
    own_speed = func_800EEF94((f32 *) (kicker + 0x28));

if (_sukickball_entrypoint_6(controller, i) != 0) {
    func_800F5D70(i, other_vel);
    other_speed = func_800EEF94(other_vel);
    other_dist = func_800D8FF8() * other_speed;
} else {

other_speed = func_800EEF94((f32 *) (other + 0x28));
other_dist = func_800D8FF8() * other_speed;

}
if (other_dist <= own_speed) {
    if (_sukickball_entrypoint_6(controller, i) != 0) {
        _sukickball_entrypoint_13((f32 *) (kicker + 4), target_pos, 60.0f);
        func_800F8294(i, target_pos);
        if (((u32) *(u16 *) (kicker + 0x72) >> 10) == 8) {
            *(W3 *) push_dir = *(W3 *) &D_808050B4_chcollballcontrol;
            func_800F5A00(i, player_pos);
            func_800EEB9C(push_dir, func_80102D78(kicker, player_pos), 150.0f);
            func_800EF04C(push_dir, player_pos);
            func_800F7700(i, 3, (f32 *) (kicker + 4));
        }
    } else {

_sukickball_entrypoint_13(((f32 *) (kicker + 4)), ((f32 *) (other + 4)), 60.0f);

if (((u32) *(u16 *) (kicker + 0x72) >> 10) == 8) {
    *(f32 *) (other + 0x58) = 1.5f;
    ((BitS101 *) other)->b4 = 1;
    func_8080324C_chcollballcontrol(other, 0xC);
    *(f32 *) (other + 0x24) = *(f32 *) (kicker + 0x24) * 0.75f;
    *(f32 *) (other + 0x54) = func_80102D78(kicker, (f32 *) (other + 4));
    *(f32 *) (kicker + 0x24) = *(f32 *) (kicker + 0x24) * 0.5f;
}

}
}
else
{
    _sukickball_entrypoint_13(target_pos, ((f32 *) (kicker + 4)), 60.0f);
    if (func_800DC0C0() < 0.5f &&
        _sukickball_entrypoint_12(controller, *(s32 *) (kicker + 0x6C) & 0x1FF) == 0) {
        func_808032CC_chcollballcontrol(kicker, target_pos);
    }
    if (_sukickball_entrypoint_6(controller, i) != 0 && func_800F52B8(i, *(s32 *) kicker) == 2) {
        func_800F5A00(i, player_pos_2);
        *(f32 *) (kicker + 0x54) = func_800F1DF4(player_pos_2, ((f32 *) (kicker + 4)));
        func_8080324C_chcollballcontrol(kicker, 0xC);
        *(f32 *) (kicker + 0x24) = (other_dist * 0.75f) / func_800D8FF8();
    }
    *(f32 *) (kicker + 0x58) = 1.5f;
    ((BitS101 *) kicker)->b4 = 1;
}
}
}
i++;
}
while (i < (s32) *(u8 *) (state + 0x3A))
    ;
}
}

void func_80804420_chcollballcontrol(Actor *actor)
{
    CollisionBallState *state;

    state = func_80100094(actor, 0);
    ((CollisionBallPlayerFlags *) actor)->local_0 = 1;
    actor->scale = 0.5f;
    func_8010A590(actor);
    state->local_1 = _sukickball_entrypoint_3();
    if (state->local_1 == 4 && actor->unk6C_0 < (u32) _gcstatusDll_entrypoint_11()) {
        ((CollisionBallPlayerFlags *) actor)->local_1 = 1;
        ((CollisionBallPlayerFlags *) actor)->local_2 = actor->unk6C_0;
    }
    state->local_0 = func_800BD0DC(2);
    func_800BD268(state->local_0, actor->unk6C_0);
    func_800BD28C(state->local_0, 2);
}

void func_808044F4_chcollballcontrol(s32 actor)
{
    func_800BD09C(*(s32 *) func_80100094(actor, 0));
}

Actor *func_8080451C_chcollballcontrol(kicker)
Actor *kicker;
{
    Actor *ball;
    f32 dist;
    Actor *alt_ball;
    f32 target_angle;
    f32 target_speed;

    ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A1, -1, &dist);
    if (ball == NULL) {
        ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A2, -1, &dist);
        if (ball == NULL) {
            ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A3, -1, &dist);
            if (ball == NULL) {
                return NULL;
            }
        }
    } else if ((ball->unk70_10 == 2 &&
                !func_800F0064(kicker->position, 100.0f, ball->position)) ||
               ball->unk70_10 == 6 || ball->unk70_10 == 4 || ball->unk70_10 == 3) {
        switch (ball->unk70_10) {
            case 2:
                alt_ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A1, 2, &dist);
                break;
            case 3:
                alt_ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A1, 3, &dist);
                break;
            case 6:
                alt_ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A1, 6, &dist);
                break;
            case 4:
                alt_ball = _subaddiefind_entrypoint_0(kicker->position, 0x1A1, 4, &dist);
        }
        if (alt_ball && (alt_ball->unk70_10 == 1 || alt_ball->unk70_10 == 3)) {
            ball = alt_ball;
        }
    }
    if (ball->unk70_10 == 2) {
        target_angle = ball->unk54 - func_80102D78(kicker, (f32 *) ball->actorData);
        target_speed = 0.0f;
        target_angle = func_800136E4(target_angle);
        if (target_angle < 90.0f) {
            target_angle = ball->unk54 + 65.0f;
            target_speed = ball->unk50 * 0.006666666828f;
        } else if (target_angle > 270.0f) {
            target_angle = ball->unk54 - 65.0f;
            target_speed = ball->unk50 * 0.006666666828f;
        } else if (ball->unk50 > 10.0f) {
            target_speed = ball->unk50 * 0.002857142827f;
        }
        if (target_speed < 25.0f) {
            target_speed = 25.0f;
        }
        if (target_speed < 30.0f) {
            kicker->unk54 = func_80102D78(kicker, (f32 *) ball->actorData);
            if (!func_80102CF4(kicker, 45.0f) && func_80102CF4(kicker, 90.0f) &&
                func_800DC0C0() < 0.8f) {
                func_8080324C_chcollballcontrol(kicker, 8);
            }
        }
        func_800EFCD8((f32 *) kicker->actorData, target_angle, target_speed);
        func_800EF04C((f32 *) kicker->actorData, ball->position);
    } else {
        func_800EE7F8((f32 *) kicker->actorData, ball->position);
    }
    return ball;
}

void func_8080486C_chcollballcontrol(Actor *kicker)
{
    BallMotionVector_8080486C_chcollballcontrol unk_0 =
        *(BallMotionVector_8080486C_chcollballcontrol *) D_808050C0_chcollballcontrol;
    Actor *controller;

    controller = func_80106790(kicker->unk3C);
    if (kicker->unk70_10 != 10) {
        kicker->unk54 = func_80102D78(kicker, (f32 *) kicker->actorData);
        if (!func_80102CF4(kicker, 240.0f)) {
            func_80804AA8_chcollballcontrol(kicker);
        } else {
            func_80804A48_chcollballcontrol(kicker);
        }
        if (!func_80102CF4(kicker, 16.0f)) {
            func_80102B2C(kicker, 16.0f);
        } else if (!func_80102CF4(kicker, 4.0f)) {
            func_80102B2C(kicker, 4.0f);
        }
    } else {
        if (!func_80102CF4(kicker, 32.0f)) {
            func_80102B2C(kicker, 32.0f);
        } else if (!func_80102CF4(kicker, 16.0f)) {
            func_80102B2C(kicker, 16.0f);
        } else if (!func_80102CF4(kicker, 4.0f)) {
            func_80102B2C(kicker, 4.0f);
        }
    }
    if (_sukickball_entrypoint_12(controller, kicker->unk6C_0) &&
        func_80800070_chcollballcontrol(kicker) < ((f32 *) kicker->actorData)[3]) {
        ((f32 *) kicker->actorData)[3] = func_80800070_chcollballcontrol(kicker);
    }
    func_800EFCD8((f32 *) &kicker->actorData[4], kicker->rotation[1],
                  ((f32 *) kicker->actorData)[3] * func_800D8FF8());
    func_800EF04C(kicker->position, (f32 *) &kicker->actorData[4]);
    func_8080405C_chcollballcontrol(kicker);
    kicker->rotation[1] = func_800136E4(kicker->rotation[1]);
}

void func_80804A48_chcollballcontrol(kicker) Actor *kicker;
{
    if (((f32 *) kicker->actorData)[3] < func_80800040_chcollballcontrol(kicker)) {
        ((f32 *) kicker->actorData)[3] += func_808000C8_chcollballcontrol(kicker);
    } else {
        ((f32 *) kicker->actorData)[3] = func_80800040_chcollballcontrol(kicker);
    }
}

void func_80804AA8_chcollballcontrol(ball) u8 *ball;
{
    if (func_8080009C_chcollballcontrol(ball) < *(f32 *) (ball + 0x24)) {
        *(f32 *) (ball + 0x24) -= func_808000F4_chcollballcontrol(ball);
    }
}

int chcollballcontrol_entrypoint_5()
{
    extern void *D_808050CC_chcollballcontrol;
    return (int) &D_808050CC_chcollballcontrol;
}

// TU-NOTE: the overlay .data is defined here in C. Tables that hold function pointers must live in
// this unit, otherwise IDO's assembler schedules those functions differently. Some extern views
// (D_80804C64, D_80804E4C, D_80804F58, D_80804FE8, D_808050B4) are adjusted to the object type;
// addresses are unchanged.
extern void _sukickball_entrypoint_0();
extern void _sukickball_entrypoint_1();
u32 D_80804C50_chcollballcontrol[5] = {0x1304B1, 0xA00A6, 0x164E20, 0x101F4, 0x13880000};
s32 D_80804C64_chcollballcontrol[4] = {0x130413, 0x180001, 0x1F41388, 0x0};
u8 D_80804C74_chcollballcontrol[16] = {0x0, 0x13, 0x4, 0xF4, 0x0,  0x16, 0x4E, 0x20,
                                       0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0,  0x0};
u8 D_80804C84_chcollballcontrol[20] = {0x0,  0x13, 0x4, 0x82, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                                       0x7D, 0x0,  0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0, 0x0};
u8 D_80804C98_chcollballcontrol[28] = {0x0,  0x13, 0x5,  0x3C, 0x0, 0xA, 0x1, 0x0, 0x0, 0x16,
                                       0x7D, 0x0,  0x0,  0x1,  0x0, 0x0, 0x0, 0x2, 0x0, 0x1,
                                       0x1,  0xF4, 0x13, 0x88, 0x0, 0x0, 0x0, 0x0};
f32 D_80804CB4_chcollballcontrol[5] = {1.5e+02f, 225.0f, 3e+02f, 0.0f, 4e+02f};
f32 D_80804CC8_chcollballcontrol[5][2] = {1.0f,  0.0f,    0.75f,   1.0f,    0.75f,
                                          0.75f, 0.3333f, 0.6666f, 0.3333f, 0.6666f};
s32 D_80804CF0_chcollballcontrol[5][6] = {0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x1, 0x0,
                                          0x1, 0x0, 0x5, 0x1, 0x1, 0x0, 0x1, 0x1, 0x4, 0x0,
                                          0x0, 0x2, 0x0, 0x0, 0x5, 0x1, 0x0, 0x1, 0x0, 0x1};
s32 D_80804D68_chcollballcontrol[5] = {0x2D, 0x2D, 0x2D, 0x0, 0x3C};
s32 D_80804D7C_chcollballcontrol[5] = {0x4, 0x4, 0x4, 0x1, 0x4};
CollballCountRecord D_80804D90_chcollballcontrol = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
void *D_80804DA8_chcollballcontrol = (void *) 0x003F019E;
static u32 D_80804DA8_chcollballcontrol_rest[17] = {0x6370001,
                                                    0x0,
                                                    (u32) func_808006FC_chcollballcontrol,
                                                    (u32) func_80105834,
                                                    (u32) func_8010A730,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x80004,
                                                    (u32) func_80801038_chcollballcontrol,
                                                    0x0,
                                                    0x400000,
                                                    (u32) func_80800DD8_chcollballcontrol,
                                                    (u32) func_80107C2C,
                                                    0x80000202,
                                                    (u32) func_808002B8_chcollballcontrol,
                                                    0x0};
s32 D_80804DF0_chcollballcontrol = -0x38;
u8 D_80804DF4_chcollballcontrol[20] = {0xFF, 0xFF, 0xFF, 0xC8, 0x0, 0x0,  0x0, 0xFF, 0x0, 0x0,
                                       0x0,  0xFF, 0x0,  0x0,  0x0, 0xFF, 0x0, 0x0,  0x0, 0xC8};
s32 D_80804E08_chcollballcontrol[17] = {
    0xA10000A, -0x320000,  -0x31FFCE, 0x320032,  0x2CFF83, 0x4BFF83, 0x7D0096,  0x7D001B, -0xF9015E,
    0x27FD30,  -0x2CFFD30, 0x2D00022, 0x1000180, 0x800100, 0x2A0080, 0x1000300, 0x4000000};
s32 D_80804E4C_chcollballcontrol[18] = {
    0x1D09E2, 0x1BFF06, -0xF9FFEB, 0x6600CC, 0x220040, 0x4C0007, 0x70027,  0xC8,      0xF0,
    0x161000, 0xC000F,  0x2C0000,  0x640000, 0xFA,     0x2A,     0x800100, 0x3000400, 0x0};
u32 D_80804E94_chcollballcontrol[20] = {0x1D0678,   0x150066, 0xCC000A, 0xFFFB0000, 0xFFFB0005,
                                        0x5,        0x2CFF06, 0x64FF06, 0x12C00FA,  0x12C001B,
                                        0xFF6AFED4, 0x220080, 0x800100, 0x3000027,  0xFD30FD30,
                                        0x2D002D0,  0x161000, 0x2A0080, 0x1000300,  0x4000000};
u32 D_80804EE4_chcollballcontrol[18] = {
    0x1D09DC, 0x190001, 0x62302,   0xAFFFB,   0x19FFF1, 0x50032,   0xF002C,  0x60,     0x0,
    0xD80000, 0x22010A, 0x3000200, 0x500002A, 0x2,      0x4000700, 0x15004C, 0xB30016, 0x40000};
void *D_80804F2C_chcollballcontrol[4] = {0, (void *) 0x00000002, (void *) 0x00000001,
                                         (void *) 0x00000003};
CollballDistancesC010 D_80804F3C_chcollballcontrol = {1e+07f, 1e+07f, 1e+07f, 1e+07f};
BallMotionVector_80802CE0_chcollballcontrol D_80804F4C_chcollballcontrol = {0.0f, 0.0f, 0.0f};
int D_80804F58_chcollballcontrol[18] = {0x4401A1,
                                        0x6700005,
                                        0x0,
                                        (u32) func_80801A20_chcollballcontrol,
                                        (u32) func_80105834,
                                        (u32) _sukickball_entrypoint_0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x4,
                                        (u32) func_80803208_chcollballcontrol,
                                        0x0,
                                        0x240000,
                                        (u32) func_80801964_chcollballcontrol,
                                        (u32) func_80107C2C,
                                        -0x7FFFFFFE,
                                        0x0,
                                        0x0};
s32 D_80804FA0_chcollballcontrol[18] = {0x4201A3,
                                        0x6770005,
                                        0x0,
                                        (u32) func_80801A20_chcollballcontrol,
                                        (u32) func_80105834,
                                        (u32) _sukickball_entrypoint_0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x6,
                                        (u32) func_80803208_chcollballcontrol,
                                        0x0,
                                        0x240000,
                                        (u32) func_80801964_chcollballcontrol,
                                        (u32) func_80107C2C,
                                        -0x7FFFFFFE,
                                        0x0,
                                        0x0};
int D_80804FE8_chcollballcontrol[18] = {0x4301A2,
                                        0x6720005,
                                        0x0,
                                        (u32) func_80801A20_chcollballcontrol,
                                        (u32) func_80105834,
                                        (u32) _sukickball_entrypoint_0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x4,
                                        (u32) func_80803208_chcollballcontrol,
                                        0x0,
                                        0x240000,
                                        (u32) func_80801964_chcollballcontrol,
                                        (u32) func_80107C2C,
                                        -0x7FFFFFFE,
                                        0x0,
                                        0x0};
u32 D_80805030_chcollballcontrol[26] = {
    0x0,        0x0,        0x3F800000, 0x1D70001,  0x3F800000, 0x1D70001,  0x3F99999A,
    0x1D70001,  0x3F800000, 0x1D70001,  0x3F800000, 0x1D70001,  0x3F800000, 0x1D70001,
    0x3F800000, 0x1D70001,  0x3F800000, 0x1EB0002,  0x4B189680, 0x1D70001,  0x3F800000,
    0x1D70001,  0x40000000, 0x1D70001,  0x4B189680, 0x1D70001};
BallMotionVector_808032CC_chcollballcontrol D_80805098_chcollballcontrol = {0.0f, 0.0f, 0.0f};
Vec3f D_808050A4_chcollballcontrol = {0.0f, 0.0f, 0.0f};
u8 D_808050B0_chcollballcontrol[4] = {0xFF, 0xFF, 0xFF, 0xC8};
s32 D_808050B4_chcollballcontrol[3] = {0x0, 0x0, 0x0};
u8 D_808050C0_chcollballcontrol[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
void *D_808050CC_chcollballcontrol = (void *) 0x0040019F;
static u32 D_808050CC_chcollballcontrol_rest[20] = {0x66A000B,
                                                    (u32) &D_80805030_chcollballcontrol,
                                                    (u32) func_80803484_chcollballcontrol,
                                                    (u32) func_80105834,
                                                    (u32) _sukickball_entrypoint_1,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x4,
                                                    (u32) func_808044F4_chcollballcontrol,
                                                    0x0,
                                                    0x180000,
                                                    (u32) func_80804420_chcollballcontrol,
                                                    (u32) func_80107C2C,
                                                    0x80000003,
                                                    (u32) func_80803420_chcollballcontrol,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x0};
