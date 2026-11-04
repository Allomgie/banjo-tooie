#include "common.h"
#include "overlays/ba/playerstate.h"
typedef struct {
    s32 local_0;
    u8 pad_0[0x10];
    u8 local_1[1];
} FpsGamePlayers;

extern int D_808021A0_chfpsgame[];
extern unsigned int func_80016BBC(s32, u16);
extern void *func_80100094(Actor *, u32);
extern PlayerState *func_800F53D0(s32);
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern f32 func_800D8FF8(void);
typedef struct {
    s32 a;
    f32 b;
} FpsE;
extern s32 func_800F1574(f32 *, f32);
typedef struct {
    u8 pad_0[0x558];
    u8 local_0;
    u8 local_1;
    u8 local_2;
    u8 local_3;
    u8 pad_1[4];
    f32 local_4;
} FpsClock1590;
extern void _fxdialog_entrypoint_1(s32, s32);
extern void _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_4(void *, s32, s32, f32, f32, s32, s32);
extern void func_800B8C50(void);
extern void func_800B8C8C(s32);
extern void func_800B8C98(s32);
extern void func_800B8CBC(s32, s32, s32);
extern void func_800B7F14(void *);
extern void func_800B8E28();
extern void func_800B811C(void *);
typedef struct {
    s32 x;
    s32 y;
} FPSPushItem1274_80801C9C_chfpsgame;
typedef struct {
    s32 count;
    FPSPushItem1274_80801C9C_chfpsgame it[10];
} FpsList;
extern s32 func_8010114C(s32, s32, s32);
typedef struct {
    s32 local_0;
    s32 local_1;
} FPSPushItem1274_80801D40_chfpsgame;
typedef struct {
    s32 local_0;
    FPSPushItem1274_80801D40_chfpsgame local_1[10];
} FPSPushList1274;
typedef struct {
    Unk80132ED0 *local_0;
    u32 local_1;
} FpsTimedActor;
typedef struct {
    s32 local_0;
    FpsTimedActor local_1[10];
} FpsTimedActorList;
extern u32 func_8001211C(void);
typedef struct {
    s32 local_0;
    s32 local_1;
} FPSPushItem1274_80802020_chfpsgame;
typedef struct {
    s32 local_0;
    FPSPushItem1274_80802020_chfpsgame local_1[10];
} FpsItemList;
typedef struct {
    u8 pad_0[0x568];
    FpsItemList local_0[4];
} FpsItemLists;
typedef struct {
    u8 pad0[6];
    u16 unk6_7 : 9;
    u16 unk6_0 : 7;
    u8 pad8[4];
    u32 unkC_23 : 9;
    u32 unkC_0 : 23;
} FpsCube;
extern s32 _gccubesearch_entrypoint_9(s32, FpsCube **, s32);
extern s32 func_800EA05C(void);
extern s32 _gcstatusDll_entrypoint_19(void);
extern s32 _bsfirstp_entrypoint_3(s32, s32, s32);
extern Actor *func_801085CC(s32, FpsCube *, u32);
extern Actor *func_80106790(s32);
typedef union {
    s32 word;
    s16 halves[2];
} FpsEvent88;
extern void func_800F7C0C(s32, s32, f32);
typedef struct {
    s32 count;
    u8 pad4[0x10];
    u8 score[0x53C];
    s32 state;
    f32 timer;
} FpsGameCtrl;
extern void func_8010A828(Actor *, s32);
extern s32 func_800F54E4(void);
extern s32 func_800F5410(s32);
extern void func_800FDC28(s32);
extern void func_80101238(s32, s32);
extern void func_800FC6B0(s32);
extern s32 _sumultiscore_entrypoint_8(void *, s32, s32);
extern void _sumultiscore_entrypoint_4(void *, s32, s32, s32);
extern s32 _gcstatusDll_entrypoint_11(void);
extern void _sumultiscore_entrypoint_9(void *, s32, s32, s32);
extern void _sumultiscore_entrypoint_10(void *, s32);
extern void func_800AA20C(s32, s32);
extern void _gcfrontend_entrypoint_10(void);
typedef struct {
    s32 unk530;
    f32 unk534;
} FpsPlayerSlot;
typedef struct {
    u8 pad0[0x530];
    FpsPlayerSlot slot[4];
} FpsGameLocal;
extern s32 func_800A4C68(void *);
extern void func_800C968C(s32, s32);
extern void _bainvisible_entrypoint_8(void *, s32, f32, f32);
extern void func_800A38F0(void *, s32, s32);
extern void func_800F44DC(void *, s32);
extern void func_80093370(void *, s32);
extern s32 _sudeathmatch_entrypoint_0(s32, f32 *, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800F8294(s32, f32 *);
extern s32 func_800A1760(void *);
extern void func_800A1870(void *, s32);
extern void _bainvisible_entrypoint_3(void *);
extern void func_8009337C(void *, s32);
extern void func_800F7F98(s32, s32);
typedef struct {
    u8 pad_0[0x55A];
    u8 local_0;
    u8 local_1;
    f32 local_2;
    f32 local_3;
} FpsTimer61;
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    s32 id;
    s32 w;
} FpsEl;
typedef struct {
    s32 count;
    FpsEl el[10];
} FpsEntry;
typedef struct {
    s32 n;
    u8 pad[0x564];
    FpsEntry e[1];
} FpsBase;
void func_808015EC_chfpsgame();
s32 func_80801758_chfpsgame();
// Draws the round clock as "%d:%02d".
void func_80801B30_chfpsgame();
// Removes the oldest placed egg of `player`.
void func_80801F34_chfpsgame();
// Switches the end-of-round state machine to `state`.
void func_80800CF8_chfpsgame();
void func_80800FF4_chfpsgame();
void func_808013DC_chfpsgame();
// Sets up the round clock from the time limit.
void func_80801814_chfpsgame();
void func_808018E0_chfpsgame();
void func_80801DF0_chfpsgame();

void func_808003D0_chfpsgame(Actor *param_0, s32 param_1);
void func_808004E0_chfpsgame(Actor *param_0);
void func_808005B0_chfpsgame(Actor *param_0);
void func_808006A8_chfpsgame(Actor *param_0);
// Game type 5: sets the "it" timer (6/4/2 s by player count) and the scores.
void func_8080075C_chfpsgame(Actor *param_0);
// Adds a kill score (-1 for a teammate); in team games every team member scores.
void func_80800BCC_chfpsgame(Actor *param_0, s32 param_1, s32 param_2);
int func_8080121C_chfpsgame(s32 param_0);
s32 func_808012CC_chfpsgame(Actor *param_0);
void func_8080135C_chfpsgame(s32 param_0);
void func_808018B0_chfpsgame(s32 param_0);
int func_80801A8C_chfpsgame(Actor *param_0, f32 param_1);
s32 func_80801ADC_chfpsgame();
void func_80801C5C_chfpsgame(s32 param_0);
// Removes all placed eggs of every player.
void func_80801C9C_chfpsgame(Actor *param_0);
// Registers a placed egg for `player` (max 10), dropping the oldest if full.
void func_80801D40_chfpsgame(Actor *param_0, s32 param_1, s32 param_2);
// Unregisters egg `egg_id` of `player`.
void func_80802020_chfpsgame(Actor *param_0, s32 param_1, s32 param_2);

int *chfpsgame_entrypoint_0()
{
    return &D_808021A0_chfpsgame;
}

// Sets or clears bit `bit` in the controller flags.
int func_8080000C_chfpsgame(s32 actor, s32 bit, s32 set)
{
    Actor *ctrl;
    ctrl = func_80100094(actor, 0);
    if (set != 0) {
        *(s32 *) ((char *) ctrl + 0x4) |= 1 << bit;
    } else {
        *(s32 *) ((char *) ctrl + 0x4) &= ~(1 << bit);
    }
}

int func_80800074_chfpsgame(s32 actor, s32 bit)
{
    Actor *ctrl;
    s32 result;
    ctrl = func_80100094(actor, 0);
    if (*(s32 *) ((char *) ctrl + 0x4) & 1 << bit) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int func_808000BC_chfpsgame(u32 mask)
{
    s32 i;
    s32 result;
    result = 0;
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        result |= func_80016BBC(i, (u16) mask);
    }
    return result ? 1 : 0;
}

// Applies `value` to every player that passes the check.
void func_80800138_chfpsgame(s32 value)
{
    s32 i;
    s32 arg;
    arg = value;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6BE4(i)) {
            func_800F7F98(i, arg);
        }
    }
}

// Spawns actors from the map cubes depending on the first-person state.
void func_8080019C_chfpsgame(s32 **actor_slot)
{
    s32 saved_id;
    Actor *actor;
    FpsCube *cubes[28];
    s32 cube_count;
    s32 unk_0;
    s32 unk_1;
    Actor *spawned;
    s32 i;
    s32 spawn_id;

    actor = (Actor *) *actor_slot;
    saved_id = *(s32 *) actor;
    cube_count = _gccubesearch_entrypoint_9(0x2BA, cubes, 28);
    unk_0 = func_800EA05C();
    unk_1 = _gcstatusDll_entrypoint_19();
    for (i = 0; i < cube_count; i++) {
        switch (_bsfirstp_entrypoint_3(unk_0, unk_1, cubes[i]->unk6_7 - 0x32)) {
            case 0:
                spawn_id = 0;
                break;
            case 1:
                spawn_id = 0x1C8;
                break;
            case 2:
                spawn_id = 0x1C9;
                break;
            case 3:
                spawn_id = 0x1CA;
                break;
            case 4:
                spawn_id = 0x1CB;
                break;
            case 5:
                spawn_id = 0x1CC;
                break;
            case 6:
                spawn_id = 0x2B8;
                break;
            case 7:
                spawn_id = 0x1CD;
        }
        if (spawn_id != 0) {
            spawned = func_801085CC(spawn_id, cubes[i], cubes[i]->unkC_23);
            spawned->unk74_7 = 0x33;
            actor = func_80106790(saved_id);
        }
    }
    *actor_slot = (s32 *) actor;
}

// Sets up scores and players for the current game type.
void func_808002FC_chfpsgame(Actor *actor)
{
    s32 *ctrl;
    s32 game_type;

    ctrl = func_80100094(actor, 0);
    game_type = _gcstatusDll_entrypoint_14();
    ctrl[1] = 0;
    func_80800CF8_chfpsgame(actor, 0);
    func_80801C5C_chfpsgame(actor);
    ctrl[0] = _gcstatusDll_entrypoint_11();
    switch (game_type) {
        case 1:
        case 4:
            func_808003D0_chfpsgame(actor, game_type);
            break;
        case 3:
            func_808004E0_chfpsgame(actor);
            break;
        case 2:
            func_808005B0_chfpsgame(actor);
            break;
        case 6:
            func_808006A8_chfpsgame(actor);
            break;
        case 5:
            func_8080075C_chfpsgame(actor);
            break;
    }
}

void func_808003D0_chfpsgame(Actor *actor, s32 game_type)
{
    u8 *ctrl;
    s32 unk_0;
    s32 i;
    PlayerState *player;
    s32 unk_1;
    u8 *scores;

    ctrl = func_80100094(actor, 0);
    scores = ctrl + 0x14;
    unk_0 = _gcstatusDll_entrypoint_19();
    for (i = 0; i < *(s32 *) ctrl; i++) {
        player = func_800F53D0(i);
        unk_1 = _gcstatusDll_entrypoint_13(i);
        _bsfirstp_entrypoint_4(player, unk_0);
        _bsfirstp_entrypoint_5(player, 1, unk_1);
    }
    _sumultiscore_entrypoint_3(scores);
    _sumultiscore_entrypoint_4(scores, 1, 0, 1);
    _sumultiscore_entrypoint_4(scores, 2, 1, 1);
    _sumultiscore_entrypoint_4(scores, 3, 2, 1);
    _sumultiscore_entrypoint_4(scores, 4, 3, 0);
}

void func_808004E0_chfpsgame(Actor *actor)
{
    s32 i;
    void *scores;
    s32 unk_0;
    void *player;
    FpsGamePlayers *ctrl;

    ctrl = func_80100094(actor, 0);
    scores = ctrl->local_1;
    for (i = 0; i < ctrl->local_0; i++) {
        player = func_800F53D0(i);
        unk_0 = _gcstatusDll_entrypoint_13(i);
        _bsfirstp_entrypoint_4(player, 0);
        _bsfirstp_entrypoint_5(player, 3, unk_0);
    }
    _sumultiscore_entrypoint_3(scores);
    _sumultiscore_entrypoint_4(scores, 2, 0, 1);
    _sumultiscore_entrypoint_4(scores, 3, 2, 1);
}

void func_808005B0_chfpsgame(Actor *actor)
{
    u8 *ctrl;
    u8 *scores;
    s32 unk_0;
    s32 i;
    PlayerState *player;
    s32 unk_1;

    ctrl = func_80100094(actor, 0);
    scores = ctrl + 0x14;
    unk_0 = _gcstatusDll_entrypoint_19();
    for (i = 0; i < *(s32 *) ctrl; i++) {
        player = func_800F53D0(i);
        unk_1 = _gcstatusDll_entrypoint_13(i);
        _bsfirstp_entrypoint_4(player, unk_0);
        _bsfirstp_entrypoint_5(player, 2, unk_1);
    }
    _sumultiscore_entrypoint_3(scores);
    _sumultiscore_entrypoint_4(scores, 2, 0, 1);
    _sumultiscore_entrypoint_4(scores, 3, 2, 1);
    _sumultiscore_entrypoint_4(scores, 4, 3, 0);
}

void func_808006A8_chfpsgame(Actor *actor)
{
    s32 i;
    u8 *scores;
    PlayerState *player;
    u8 *ctrl;

    ctrl = func_80100094(actor, 0);
    scores = ctrl + 0x14;
    for (i = 0; i < *(s32 *) ctrl; i++) {
        player = func_800F53D0(i);
        func_800A18C8(player, 1);
        func_800A1870(player, 1);
        _badeathmatch_entrypoint_11(player, 1, 1);
    }
    _sumultiscore_entrypoint_3(scores);
    _sumultiscore_entrypoint_4(scores, 2, 0, 1);
}

void func_8080075C_chfpsgame(Actor *actor)
{
    u8 *ctrl;
    u8 *scores;
    s32 it_player;
    s32 i;
    void *player;
    u8 *player_score;
    ctrl = func_80100094(actor, 0);
    scores = ctrl + 0x14;
    it_player = _gcstatusDll_entrypoint_15();
    switch (*(s32 *) ctrl) {
        case 2:
            *(f32 *) (ctrl + 0x10) = 6.0f;
            break;
        case 3:
            *(f32 *) (ctrl + 0x10) = 4.0f;
            break;
        case 4:
            *(f32 *) (ctrl + 0x10) = 2.0f;
            break;
    }
    *(f32 *) (ctrl + 0xC) = *(f32 *) (ctrl + 0x10);
    _sumultiscore_entrypoint_3(scores);
    _sumultiscore_entrypoint_4(scores, 2, 0, 1);
    _sumultiscore_entrypoint_4(scores, 3, 2, 1);
    for (i = 0; i < *(s32 *) ctrl; i++) {
        player = (void *) func_800F53D0(i);
        if (i == it_player) {
            _badeathmatch_entrypoint_10(player, 3, 0x19, 0x19);
            _badeathmatch_entrypoint_7(player, 3);
        } else {
            player_score = scores;
            player_score += i * 0x13C;
            _badeathmatch_entrypoint_10(player, 1, 1, -1);
            player_score[0x86] = 0;
        }
    }
}

s32 func_808008D4_chfpsgame(s32 actor)
{
    func_808015EC_chfpsgame(actor);
    func_80800FF4_chfpsgame(actor);
    func_80801758_chfpsgame(actor);
    func_808018E0_chfpsgame(actor);
}

void func_8080090C_chfpsgame(s32 actor)
{
}

s32 func_80800914_chfpsgame(Actor *actor, s32 event, FpsEvent88 data)
{
    u8 *ctrl;
    s32 scorer;
    s32 other;
    s32 unk_0;
    s32 unk_1;
    s32 egg_id;
    s32 pad;
    s32 egg_id_2;

    ctrl = func_80100094(actor, 0);
    switch (event) {
        case 0x49:
            func_8080019C_chfpsgame(&actor);
            return 1;
        case 0x70:
            scorer = data.word & 0xF;
            other = data.word >> 4;
            switch (_gcstatusDll_entrypoint_14()) {
                case 5:
                    if (_gcstatusDll_entrypoint_15() == other) {
                        func_800FC660(0x19);
                        func_80800BCC_chfpsgame(actor, scorer, other);
                        *(f32 *) (ctrl + 0xC) = *(f32 *) (ctrl + 0x10);
                    } else {
                        (*(s32 *) (ctrl + 8))++;
                    }
                    break;
                case 3:
                    func_800FC660(0x19);
                    func_80800BCC_chfpsgame(actor, scorer, other);
                    return 1;
                case 6:
                    func_80800BCC_chfpsgame(actor, scorer, other);
                    if (func_800F5410(other) == 0xC) {
                        (*(s32 *) (ctrl + 8))++;
                    }
                    break;
                default:
                    func_80800BCC_chfpsgame(actor, scorer, other);
                    (*(s32 *) (ctrl + 8))++;
            }
            break;
        case 0x71:
            if (_gcstatusDll_entrypoint_14() == 6) {
                func_800F7C0C(data.word, 0x83, 4.0f);
            } else {
                func_808013DC_chfpsgame(actor, data.word, 1);
            }
            (*(s32 *) (ctrl + 8))--;
            break;
        case 0x72:
            _sumultiscore_entrypoint_5(ctrl + 0x14, data.word & 0xF, 3,
                                       (data.word >> 4) & 0xF);
            return 1;
        case 0x73:
            egg_id = data.word;
            unk_0 = _suegg_entrypoint_7(egg_id);
            func_80801D40_chfpsgame(actor, unk_0, egg_id);
            return 1;
        case 0x74:
            egg_id_2 = data.word;
            unk_1 = _suegg_entrypoint_7(egg_id_2);
            func_80802020_chfpsgame(actor, unk_1, egg_id_2);
            return 1;
        case 0x75:
            _sumultiscore_entrypoint_9(ctrl + 0x14, data.word & 0xFFFF, 4,
                                       (data.word >> 16) & 0xFFFF);
            return 1;
        case 0x2E:
            if (data.halves[0] == 0xCEC) {
                func_80800CF8_chfpsgame(actor, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800BCC_chfpsgame(Actor *actor, s32 scorer, s32 other)
{
    u8 *ctrl;
    s32 team;
    s32 delta;
    s32 i;

    ctrl = func_80100094(actor, 0);
    team = _gcstatusDll_entrypoint_16(scorer);
    delta = 1;
    if (other >= 0 && _gcstatusDll_entrypoint_16(other) == team) {
        delta = -1;
    }
    if (team < 4) {
        _sumultiscore_entrypoint_7(ctrl + 0x14, scorer, 2, delta);
        _sumultiscore_entrypoint_11(ctrl + 0x14, scorer, 2, 0.75f);
    } else {
        for (i = 0; i < *(s32 *) ctrl; i++) {
            if (_gcstatusDll_entrypoint_16(i) == team) {
                _sumultiscore_entrypoint_7(ctrl + 0x14, i, 2, delta);
                _sumultiscore_entrypoint_11(ctrl + 0x14, i, 2, 0.75f);
            }
        }
    }
}

void func_80800CF8_chfpsgame(actor, state) Actor *actor;
s32 state;
{
    FpsGameCtrl *ctrl;
    s32 j;
    s32 i;
    s32 k;
    s32 value;
    s32 best;

    ctrl = func_80100094(actor, 0);
    switch (state) {
        case 0:
            func_80800138_chfpsgame(1);
            break;
        case 1:
            func_8080000C_chfpsgame(actor, 0, 0);
            break;
        case 2:
            func_80800138_chfpsgame(0);
            func_8010A828(actor, 0x18);
            func_80801814_chfpsgame(actor);
            value = func_800F5410(func_800F54E4());
            if (value == 6 || value == 0xC) {
                func_800FDC28(0xC);
            }
            break;
        case 3:
            ctrl->timer = 2.0f;
            func_8080000C_chfpsgame(actor, 0, 1);
            break;
        case 4:
            func_80800138_chfpsgame(1);
            func_8080000C_chfpsgame(actor, 0, 1);
            func_808018B0_chfpsgame(actor);
            func_80801C9C_chfpsgame(actor);
            func_80101238(0x78, 0);
            break;
        case 5:
            for (j = 0; j < ctrl->count; j++) {
                func_808013DC_chfpsgame(actor, j, 4);
            }
            func_800FC6B0(0x16);
            value = func_800F5410(func_800F54E4());
            if (value == 6 || value == 0xC) {
                func_800FDC28(0);
            }
            break;
        case 6:
            best = _sumultiscore_entrypoint_8(ctrl->score, 0, 2);
// Matching: empty block steers IDO's register allocation.
            if (1) {
            }
            ctrl->timer = 5.0f;
            _sumultiscore_entrypoint_4(ctrl->score, 5, 5, 2);
            for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
                value = _sumultiscore_entrypoint_8(ctrl->score, i, 2);
                _sumultiscore_entrypoint_9(ctrl->score, i, 5, value);
                if (value != best && best < value) {
                    best = value;
                }
            }
            for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
                if (_sumultiscore_entrypoint_8(ctrl->score, i, 2) == best) {
                    _sumultiscore_entrypoint_10(ctrl->score, i);
                }
            }
            break;
        case 7:
            for (k = 0; k < _gcstatusDll_entrypoint_11(); k++) {
                func_800AA20C(k, _sumultiscore_entrypoint_8(ctrl->score, k, 2));
            }
            _gcfrontend_entrypoint_10();
    }
    ctrl->state = state;
}

void func_80800FF4_chfpsgame(actor) s32 *actor;
{
    u8 *ctrl_copy;
    s32 flag_slot;
    s32 i;
    u8 *ctrl;
    ctrl = func_80100094(actor, 0);
    ctrl_copy = ctrl;
    switch (*(u32 *) ((char *) ctrl + 0x550)) {
        case 0:
            if (func_800C954C() == 0) {
                _subaddiedialog_entrypoint_11(*actor, 0xCEC, 0x22, 0, 0x6F);
                func_80800CF8_chfpsgame(actor, 1);
            }

        default:
            return;

        case 2:
            func_8080135C_chfpsgame(actor);
            if (func_8080121C_chfpsgame(actor) != 0) {
                func_80800CF8_chfpsgame(actor, 4);
                return;
            }
            if (func_808012CC_chfpsgame(actor) != 0) {
                func_80800CF8_chfpsgame(actor, 3);
            }
            break;

        case 3:
            func_8080135C_chfpsgame(actor);
            if (func_800F1574(ctrl_copy + 0x554, func_800D8FF8()) != 0) {
                func_80800CF8_chfpsgame(actor, 4);
                return;
            }
            if (func_8080121C_chfpsgame(actor) != 0) {
                func_80800CF8_chfpsgame(actor, 4);
            }
            break;

        case 4:
            if (*(s32 *) ((char *) ctrl + 8) == 0) {
                func_80800CF8_chfpsgame(actor, 5);
            }
            break;

        case 5:
// Matching: flag_slot is accessed through an odd offset cast; needed for the match.
            *(s32 *) ((s8 *) &flag_slot - 8) = 1;
            i = 0;
            if (*(s32 *) ((char *) ctrl + 0) > 0) {
            loop_15:
                if (func_800C96CC(func_800A4C68(func_800F53D0(i))) == 0) {
                    *(s32 *) ((s8 *) &flag_slot - 8) = 0;
                } else {
                    i += 1;
                    if (i < *(s32 *) ((char *) ctrl_copy + 0)) {
                        goto loop_15;
                    }
                }
            }
            if (*(s32 *) ((s8 *) &flag_slot - 8) != 0) {
                func_80800CF8_chfpsgame(actor, 6);
            }

        case 6:
            if (func_800F1574(ctrl_copy + 0x554, func_800D8FF8()) != 0) {
                func_80800CF8_chfpsgame(actor, 7);
                return;
            }
            if ((*(f32 *) ((char *) ctrl_copy + 0x554) < 4.5f) &&
                (func_808000BC_chfpsgame(0xD000) != 0)) {
                func_80800CF8_chfpsgame(actor, 7);
            }
    }
}

int func_8080121C_chfpsgame(s32 actor)
{
    s32 ctrl;
    s32 score_limit;
    s32 i;
    s32 scores;
    ctrl = func_80100094(actor, 0);
    score_limit = _gcstatusDll_entrypoint_18();
    if (func_80801ADC_chfpsgame(actor) != 0) {
        return 1;
    }
    if (score_limit != 0) {
        i = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            scores = ctrl + 0x14;
            do {
                if (_sumultiscore_entrypoint_8(scores, i, 2) == score_limit) {
                    return 1;
                }
                i = i + 1;
            } while (i < _gcstatusDll_entrypoint_11());
        }
    }
    return 0;
}

s32 func_808012CC_chfpsgame(Actor *actor)
{
    s32 i;
    s32 count;
    if (_gcstatusDll_entrypoint_14() == 3) {
        count = 0;
        for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
            count += _badeathmatch_entrypoint_9(func_800F53D0(i), 1);
        }
        return count ? 0 : 1;
    }
    return 0;
}

void func_8080135C_chfpsgame(s32 actor)
{
    u8 *ctrl;
    ctrl = func_80100094(actor, 0);
    if ((_gcstatusDll_entrypoint_14() == 5) &&
        (func_800F1574(ctrl + 0xC, func_800D8FF8()) != 0)) {
        func_800FC660(0xE);
        *(f32 *) (ctrl + 0xC) = *(f32 *) (ctrl + 0x10);
        func_80800BCC_chfpsgame(actor, _gcstatusDll_entrypoint_15(), -1);
    }
}

void func_808013DC_chfpsgame(actor, player, state) Actor *actor;
s32 player;
s32 state;
{
    FpsGameLocal *ctrl;
    s32 prev_state;
    f32 spawn_a[3];
    f32 spawn_b[3];
    void *player_state;

    ctrl = func_80100094(actor, 0);
    player_state = func_800F53D0(player);
    switch (state) {
        case 1:
            func_800C968C(func_800A4C68(player_state), 0x13);
            _bainvisible_entrypoint_8(player_state, 1, 0.0f, 1.0f);
            _bainvisible_entrypoint_8(player_state, 2, 1.0f, 0.01f);
            break;
        case 2:
            func_800A38F0(player_state, 0, 0);
            func_800F44DC(player_state, 0);
            func_80093370(player_state, 0);
            ctrl->slot[player].unk534 = 5.0f;
            break;
        case 3:
            func_800C968C(func_800A4C68(player_state), 0x12);
            if (_sudeathmatch_entrypoint_0(player, spawn_a, spawn_b)) {
                func_800F832C(player, spawn_b);
                func_800F8294(player, spawn_a);
            }
            func_800A1870(player_state, func_800A1760(player_state));
            func_800A38F0(player_state, 1, 1);
            _bainvisible_entrypoint_3(player_state);
            func_80093370(player_state, 1);
            func_8009337C(player_state, 1);
            func_800F44DC(player_state, 1);
            func_800F7C0C(player, 0x83, 0.0f);
            func_800F7F98(player, 1);
            break;
        case 0:
            func_800F7F98(player, 0);
            break;
        case 4:
            prev_state = ctrl->slot[player].unk530;
            if (prev_state == 0 || prev_state == 3) {
                func_800C968C(func_800A4C68(player_state), 0x13);
            }
    }
    ctrl->slot[player].unk530 = state;
}

void func_808015EC_chfpsgame(actor) Actor *actor;
{
    u8 *ctrl;
    s32 i;
    s32 player_state;
    FpsE *slot;

    ctrl = func_80100094(actor, 0);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
// Matching: empty block steers IDO's register allocation.
        if (1) {
        }
        player_state = func_800F53D0(i);
        slot = (FpsE *) (ctrl + 0x530) + i;
        switch (slot->a) {
            case 1:
                if (func_800C96CC(func_800A4C68(player_state)))
                    func_808013DC_chfpsgame(actor, i, 2);
                break;
            case 2:
                if (!func_80800074_chfpsgame(actor, 0)) {
                    if (func_800F1574(&slot->b, func_800D8FF8()) ||
                        func_80016BBC(func_800F54F0(i), 0xD000)) {
                        func_808013DC_chfpsgame(actor, i, 3);
                    }
                }
                break;
            case 3:
                if (func_800C9714(func_800A4C68(player_state)))
                    func_808013DC_chfpsgame(actor, i, 0);
        }
    }
}

s32 func_80801758_chfpsgame(actor)
s32 actor;
{
    _sumultiscore_entrypoint_6((u8 *) func_80100094(actor, 0) + 0x14);
}

int func_80801780_chfpsgame(s32 actor, s32 player)
{
    s32 ctrl;
    ctrl = func_80100094(actor, 0);
    switch (func_800EB854()) {
        case 3:
            _sumultiscore_entrypoint_12(ctrl + 0x14, player, 1);
            _scradar_entrypoint_0();
            _scradar_entrypoint_1(player);
            return;
        case 4:
            func_80801B30_chfpsgame(actor, player);
            _sumultiscore_entrypoint_12(ctrl + 0x14, player, 2);
    }
}

void func_80801814_chfpsgame(actor) Actor *actor;
{
    FpsTimer61 *hud;
    s32 minutes;

    hud = func_80100094(actor, 0);
    minutes = _gcstatusDll_entrypoint_17();
    if (minutes != 0) {
        hud->local_0 = minutes;
        hud->local_1 = 0;
        hud->local_2 = minutes * 60.0f + 0.99f;
        func_80801A8C_chfpsgame(actor, 10.99f);
    } else {
        hud->local_2 = 0.0f;
        func_80801A8C_chfpsgame(actor, 0);
    }
    hud->local_3 = hud->local_2;
}

void func_808018B0_chfpsgame(s32 actor)
{
    u8 *ctrl;

    ctrl = func_80100094(actor, 0);
    *(s8 *) ((s8 *) ctrl + 0x558) = 0;
    *(s8 *) ((s8 *) ctrl + 0x559) = 0;
    *(f32 *) ((s8 *) ctrl + 0x55C) = 0.0f;
}

void func_808018E0_chfpsgame(actor) Actor *actor;
{
    u8 *ctrl;
    f32 minutes;
    f32 whole_minutes;
    s32 step;
    ctrl = func_80100094(actor, 0);
    if (*(f32 *) (ctrl + 0x55C) != 0.0f) {
        func_800F1574((f32 *) (ctrl + 0x560), func_800D8FF8());
        minutes = *(f32 *) (ctrl + 0x560) * (1.0f / 60.0f);
        whole_minutes = (s32) minutes;
        ctrl[0x55A] = (s32) whole_minutes;
        ctrl[0x55B] = (s32) ((minutes - whole_minutes) * 60.0f);
        if (ctrl[0x558]) {
            step = (s32) (func_800D8FF8() * 256.0f);
            if (func_800F1574((f32 *) (ctrl + 0x564), func_800D8FF8()))
                func_80801A8C_chfpsgame(actor, 0.0f);
            if (*(f32 *) (ctrl + 0x564) > 1.0f)
                ctrl[0x559] = func_800F1418(ctrl[0x559] + step * 4, 255);
            else if (*(f32 *) (ctrl + 0x564) < 0.5f)
                ctrl[0x559] = func_800F0E28(ctrl[0x559] - step * 2, 0);
        } else if (*(f32 *) (ctrl + 0x560) < 10.99f)
            func_80801A8C_chfpsgame(actor, 60.0f);
        else if (!ctrl[0x55B])
            func_80801A8C_chfpsgame(actor, 2.5f);
    }
}

int func_80801A8C_chfpsgame(Actor *actor, f32 duration)
{
    Actor *ctrl = func_80100094(actor, 0);
    *(f32 *) ((char *) ctrl + 0x564) = duration;
    if (duration != 0.0f) {
        *(u8 *) ((char *) ctrl + 0x558) = 1;
    } else {
        *(u8 *) ((char *) ctrl + 0x558) = 0;
    }
}

s32 func_80801ADC_chfpsgame(actor)
s32 actor;
{
    u8 *ctrl = func_80100094(actor, 0);
    return (*(f32 *) (ctrl + 0x55C) != 0.0f && *(f32 *) (ctrl + 0x560) == 0.0f) ? 1 : 0;
}

void func_80801B30_chfpsgame(actor, dl) Actor *actor;
void *dl;
{
    char text[8];
    s32 whole;
    FpsClock1590 *hud;
    f32 frac;

    hud = func_80100094(actor, 0);

    if (hud->local_0) {
        frac = hud->local_4 * 0.5f;
        whole = (s32) frac;
        frac -= whole;
        _fxdialog_entrypoint_1(0x8F, 0x72);
        _fxdialog_entrypoint_2(0.75f);
        _fxdialog_entrypoint_4(dl, 0xB4F, (s32) (frac * 20.0f), 0.0f, 0.0f,
                               hud->local_1, 0);
        func_800B8C50();
        func_800B8C8C(hud->local_1);
        func_800B8C98(3);
        func_800B8CBC(255, 255, 255);
        func_800B7F14(dl);
        sprintf(text, "%d:%02d", hud->local_2, hud->local_3);
        func_800B8E28(dl, 0x99, 0x72, text);
        func_800B811C(dl);
    }
}

void func_80801C5C_chfpsgame(s32 actor)
{
    void *ctrl = func_80100094(actor, 0);
    *((int *) (((int) ctrl) + 0x5BC)) = 0;
    *((int *) (((int) ctrl) + 0x5C0)) = 0;
    *((int *) (((int) ctrl) + 0x610)) = 0;
    *((int *) (((int) ctrl) + 0x614)) = 0;
    *((int *) (((int) ctrl) + 0x664)) = 0;
    *((int *) (((int) ctrl) + 0x668)) = 0;
    *((int *) (((int) ctrl) + 0x568)) = 0;
    *((int *) (((int) ctrl) + 0x56C)) = 0;
}

void func_80801C9C_chfpsgame(Actor *actor)
{
    u8 *ctrl;
    s32 i;
    FpsList *list;

    ctrl = func_80100094(actor, 0);
    for (i = 0; i < 4; i++) {
        list = &((FpsList *) (ctrl + 0x568))[i];

        if (list->count != 0) {
            do {
                func_8010114C(list->it[--list->count].x, 0x45, 0);
            } while (list->count != 0);
        }
    }
}

void func_80801D40_chfpsgame(Actor *actor, s32 player, s32 egg_id)
{
    s32 pad[2];
    FPSPushItem1274_80801D40_chfpsgame *entry;
    FPSPushList1274 *list;

    list = &((FPSPushList1274 *) ((u8 *) func_80100094(actor, 0) + 0x568))[player];
    func_80801DF0_chfpsgame(actor, player, egg_id);
    if (list->local_0 >= 10)
        func_80801F34_chfpsgame(actor, player);
    entry = &list->local_1[list->local_0];
    entry->local_0 = egg_id;
    entry->local_1 = func_8001211C();
    list->local_0++;
}

void func_80801DF0_chfpsgame(actor, player, egg_id) Actor *actor;
s32 player;
s32 egg_id;
{
    FpsBase *base;
    Actor *new_egg;
    Actor *other_egg;
    s32 found;
    s32 i;
    s32 j;
    FpsEntry *e;

    base = func_80100094(actor, 0);
    new_egg = func_80106790(egg_id);
    found = 0;
    for (i = 0; i < base->n; i++) {
        e = &base->e[i];
        for (j = 0; j < e->count; j++) {
            other_egg = func_80106790(e->el[j].id);

            if (func_800EEB40(new_egg->position, other_egg->position) < 90000.0f) {
                found = 1;
                func_8010108C(other_egg, 0x40, 0);
            }
        }
    }
    if (found != 0) {
        func_8010108C(new_egg, 0x40, 0);
    }
}

void func_80801F34_chfpsgame(actor, player) Actor *actor;
s32 player;
{
    u32 oldest_time;
    FpsTimedActorList *list;
    s32 pad[2];
    s32 oldest;
    s32 i;

    list = (FpsTimedActorList *) ((u8 *) func_80100094(actor, 0) + 0x568) + player;
    oldest_time = func_8001211C();
    for (i = 0; i < list->local_0; i++) {
        if (list->local_1[i].local_1 < oldest_time) {
            oldest_time = list->local_1[i].local_1;
            oldest = i;
        }
    }
    func_8010114C(list->local_1[oldest].local_0, 0x4F, 0);
    list->local_0--;
    list->local_1[oldest].local_0 = list->local_1[list->local_0].local_0;
    list->local_1[oldest].local_1 = list->local_1[list->local_0].local_1;
}

void func_80802020_chfpsgame(Actor *actor, s32 player, s32 egg_id)
{
    FpsItemList *list;
    s32 i;

    list = &((FpsItemLists *) func_80100094(actor, 0))->local_0[player];
    list->local_0--;
    for (i = 0; i < list->local_0; i++) {
        if (egg_id == list->local_1[i].local_0) {
            list->local_1[i].local_0 = list->local_1[list->local_0].local_0;
            list->local_1[i].local_1 = list->local_1[list->local_0].local_1;
            break;
        }
    }
}

// TU-NOTE: the overlay .data table is defined here in C; it holds pointers to functions
// of this file, and IDO schedules some of them differently unless it is in the same unit.
// D_808021A0_chfpsgame is declared as int[]. Values taken from the ROM.
extern void func_80105834();
extern void func_80107C2C();
int D_808021A0_chfpsgame[20] = {0x15802C4,
                                -0xFFFF,
                                0x0,
                                (u32) func_808008D4_chfpsgame,
                                (u32) func_80105834,
                                (u32) func_80801780_chfpsgame,
                                0x0,
                                0x0,
                                0x0,
                                0x8400400,
                                (u32) func_8080090C_chfpsgame,
                                0x0,
                                0x6B80000,
                                (u32) func_808002FC_chfpsgame,
                                (u32) func_80107C2C,
                                -0x7FFF7BFE,
                                (u32) func_80800914_chfpsgame,
                                0x0,
                                0x0,
                                0x0};
