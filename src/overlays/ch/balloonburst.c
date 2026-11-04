// Witchyworld Balloon Burst minigame: single-player and multiplayer controllers (dialogs, scoring,
// results) and the balloon actor that rises, pops on egg hit and awards points by colour.
#include "common.h"

extern int D_80801C40_chballoonburst[];
extern int D_80801C88_chballoonburst[];
extern int D_80801CD0_chballoonburst[];
extern void *func_80100094(Actor *, u32);
extern s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
extern void func_800F82D4(s32, s32);
extern void func_800F7C58(s32, f32 *, s32);
extern void func_80101FDC(Actor *, u32);
extern u32 func_800F54E4(void);
extern s32 func_800D211C(s32);
extern void _chintrotext_entrypoint_2(int);
extern int _susubgame_entrypoint_10(void *, int, int, int);
extern int _susubgame_entrypoint_5(void *, int, int, int, int);
extern int _susubgame_entrypoint_6(void *, int, int, int, int);
extern void func_800BF744(int, int);
extern void func_800F8300(int, int, int);
extern void func_800F4CEC(int, int);
extern u32 func_800FDC28(u32);
extern void func_800CE8D8(s32, f32, s32);
extern void func_800D2770(s32, s32);
extern void func_800F7C0C(s32, s32, f32);
extern void func_800FC6B0(u32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9154(f32 *, f32);
extern void _sumultiscore_entrypoint_6();
typedef union {
    s32 word;
    s16 halves[2];
} PairEventPayload;
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern s32 func_800DC298(f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);
extern void func_8010D930(s32, s32, void *, void *);
extern void *D_80801D18_chballoonburst;
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_80801D28_chballoonburst[];
extern s32 func_800B53A4();
extern void func_800BA22C();
extern void func_800BA670();
extern void func_800BABB8();
extern s32 D_80801D5C_chballoonburst[];
extern s32 D_80801D98_chballoonburst[];
extern u8 D_80801DBC_chballoonburst[];
extern u8 D_80801DF0_chballoonburst[];
extern Actor *func_80106790();
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800DC0C0(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 D_80801DFC_chballoonburst[];
void func_80800970_chballoonburst();
void func_808011A8_chballoonburst();
s32 func_80801254_chballoonburst();
int func_80801290_chballoonburst();
void func_80801338_chballoonburst();
void func_80801948_chballoonburst();
void func_80801A10_chballoonburst();
void func_80801A50_chballoonburst();
void func_80801ABC_chballoonburst();
void func_80801AFC_chballoonburst();
void func_80800BE8_chballoonburst();
void func_80801B6C_chballoonburst();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_80800024_chballoonburst(),
    func_80800098_chballoonburst(), func_808008F0_chballoonburst();

// Minigame controllers (single-player and multiplayer): flow, dialogs, scoring, results, rewards.
int *chballoonburst_entrypoint_0()
{
    return &D_80801C40_chballoonburst;
}

int chballoonburst_entrypoint_1()
{
    return (int) &D_80801C88_chballoonburst;
}

// Balloon actor: rise and spin, colour-dependent lifetime, pop on egg hit, score points and particles.
int chballoonburst_entrypoint_2(void)
{
    return (int) &D_80801CD0_chballoonburst;
}

void func_80800024_chballoonburst(actor) Actor *actor;
{
    u8 *state;
    u16 *field_0x6e;
    state = func_80100094(actor, 0);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    // Matching: the always-true if steers IDO's code generation.
    if (1) {
        field_0x6e = (u16 *) ((char *) actor + 0x6E);
        *field_0x6e &= 0xFE00 & 0xFFFFFFFFu;
        *(s32 *) ((char *) state + 0xC) = 0;
        _susubgame_entrypoint_0(actor, (char *) state + 0x18, 0);
        _susubgame_entrypoint_11(0);
    }
}

s32 func_80800A7C_chballoonburst();

// Single-player controller update: waits for the intro, then the end dialogs.
void func_80800098_chballoonburst(actor) Actor *actor;
{
    u8 *state = func_80100094(actor, 0);

    switch (actor->unk70_10) {
        // Matching: empty block before the first case is needed for the match.
        if (1) {
        }
        case 3:
            func_800D24E8(0xC1, *(s32 *) (state + 4), 0);
            if (func_800D9154(&actor->unk58, func_800DC178(0.5f, 1.0f)))
                func_80108B04(actor, -1);
            if (func_800CEAD0(actor->unk6C_0)) {
                *(s32 *) (state + 0x10) = func_80800A7C_chballoonburst(actor, state + 0x14);
                func_800F8300(func_800F54E4(), 2, 0);
                func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
                func_80101FDC(actor, 4);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(actor, state + 0x18, 5, 1, 0);
                func_80101FDC(actor, 5);
                _subaddiedialog_entrypoint_11(actor->unk0, *(s32 *) (state + 0x10),
                                              *(s32 *) (state + 0x14), NULL, 0x22);
            }
        case 1:
        case 2:
        case 5:
        case 6:
            break;
    }
}

void func_80800790_chballoonburst();

void func_80800704_chballoonburst();

u32 func_8080066C_chballoonburst();

void func_808003C4_chballoonburst();

s32 func_808001FC_chballoonburst(Actor *actor, s32 event, s32 arg)
{
    u8 *state;
    state = func_80100094(actor, 0);
    switch (event) {
        case 0x2E:
            func_808003C4_chballoonburst(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x2F:
            func_80800704_chballoonburst(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x30:
            return func_8080066C_chballoonburst(actor, ((s16 *) &arg)[0],
                                                ((s16 *) &arg)[1]);
        case 0x3D:
            func_80800BE8_chballoonburst(actor, arg);
            break;
        case 0xE:
            if (arg == 4 && actor->unk3C)
                _capod_entrypoint_19(func_80106790(actor->unk3C)->position);
            return 3;
        case 0x32:
            _subaddiedialog_entrypoint_11(actor->unk0, func_800D395C() ? 0x1118 : 0x10BE, 0x46, 0,
                                          0x22);
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(actor, state + 0x18, arg & 0xFFFF,
                                           (u32) (arg & 0xFFFF0000) >> 16);
        case 0x95:
            func_80800790_chballoonburst(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003C4_chballoonburst(Actor *actor, s32 dialog_id, s32 choice)
{
    u8 *state;
    s32 player;

    state = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x10BE:

        case 0x1118:
            if (choice > 0) {
                func_800DA544(0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x10BF, 0x44, 0, 0x22);
                func_80108B04(actor, 0);
            } else {
                _plcamera_entrypoint_8(func_800F54E4());
                _susubgame_entrypoint_5(actor, state + 0x18, 5, 1, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0x22);
            }
            _gcfrontend_entrypoint_9(0x68);
            return;

        case 0x10BF:
            _susubgame_entrypoint_5(actor, state + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0x22);
            return;

        case 0x10C0:

        case 0x10F8:

        case 0x10F9:

        case 0x10FA:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x46, 0, 0x22);
            return;

        case 0xCEB:
            player = func_800F54E4();
            func_800F82D4(player, 0);
            func_80101FDC(actor, 6);
            if (func_800D395C() != 0) {
                if (choice > 0) {
                    _gcfrontend_entrypoint_11();
                    return;
                }
                _gcfrontend_entrypoint_10();
                return;
            }
            if (choice > 0) {
                _gcgoto_entrypoint_1(0xE4, 1);
            } else {
                func_800F4CC0(player);
                _susubgame_entrypoint_4(actor, state + 0x18);
            }
            func_800F7C58(player, 0x5D, 0);
            return;

        case 0xCEC:
            _susubgame_entrypoint_4(actor, state + 0x18);
            func_80800970_chballoonburst(actor, 0);
            return;

        case 0x10D2:
            _susubgame_entrypoint_4(actor, state + 0x18);
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0xE1, 0x22);
    }
}

u32 func_8080066C_chballoonburst(Actor *actor, s32 dialog_id, s32 choice)
{
    u32 result;

    switch (dialog_id) {
        case 0x10BE:
            return choice == 0 ? actor->unk74_7 : 0x32;
        case 0x10C0:
        case 0x10F9:
            return func_800D211C(0x80);
        case 0x1118:
            if (choice == 0) {
                result = actor->unk74_7;
            } else {
                result = func_800D211C(0x80);
            }
            return result;
    }
    return 0;
}

void func_80800704_chballoonburst(s32 actor, s32 unk_1, s32 arg)
{
    s32 actor_ref = actor;
    switch (arg) {
        case 1:
            func_80108B04(actor_ref, 1);
            func_800DA544(3);
            break;

        case 2:
            func_80108B04(actor_ref, 2);
            func_800DA544(2);
            break;

        case 3:
            func_800DA544(1);
            *(s32 *) ((char *) actor + 0x3c) = 0;
    }
}

void func_80800790_chballoonburst(void *actor)
{
    s32 state;
    s32 player;
    state = func_80100094(actor, 0);
    player = func_800F54E4();
    func_800BF744(1, 1);
    func_800BF744(2, 0);
    func_800F4CEC(player, 0x77);
    if ((((u32) ((u16 *) actor)[0x39] >> 10) == 1)) {
        if (_susubgame_entrypoint_10(actor, 2, 0x320, 0x1AE) != 0) {
            _chintrotext_entrypoint_2(1);
            _susubgame_entrypoint_6(actor, state + 0x18, 0, 0x20, 0);
        } else {
            _susubgame_entrypoint_5(actor, state + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(*(void **) actor, 0xCEC, 5, 0, 0x22);
            func_800F82D4(player, 2);
        }
        func_800F7C58(player, 0x5D, 1);
        func_80101FDC(actor, 2);
        return;
    }
    func_800F8300(player, 2, 0);
    _susubgame_entrypoint_5(actor, state + 0x18, 5, 1, 0);
    _subaddiedialog_entrypoint_11(*(void **) actor, 0xCEB, 0x46, 0, 0x22);
}

void func_808008F0_chballoonburst(actor) s32 actor;
{
    s32 state;
    state = func_80100094(actor, 0);
    if (func_800CEAA8(*(s32 *) ((char *) actor + 0x6C) & 0x1FF)) {
        func_800CE88C(*(s32 *) ((char *) actor + 0x6C) & 0x1FF, 0);
    }
    if (_susubgame_entrypoint_2(actor, state + 0x18)) {
        _susubgame_entrypoint_4(actor, state + 0x18);
    }
}

void func_80800970_chballoonburst(actor, unk_1) Actor *actor;
s32 unk_1;
{
    s32 i;
    _subaddiemulti_entrypoint_2();
    func_80101FDC(actor, 3);
    func_800D2770(0xC1, 0);
    func_800CE8D8(actor->unk6C_0, (f32) actor->unk74_7, actor->unk74_7);
    func_800CE88C(actor->unk6C_0, 1);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    func_800FDC28(0xC);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        func_800F7B9C(i, 0x69);
        func_800F7C0C(i, 0x5F, -1.0f);
    }
}

// Evaluates the final score (target 50 for the jiggy) and picks the result dialog.
s32 func_80800A7C_chballoonburst(Actor *actor, s32 *dialog_arg)
{
    s32 *state;
    s32 score;
    s32 dialog_id;
    s32 is_record;
    s32 reached_target;
    u32 earns_jiggy;
    s32 has_jiggy;
    s32 is_replay;
    s32 record_result;

    state = func_80100094(actor, 0);
    score = state[1];
    has_jiggy = func_800D0A9C(0x19, 1);
    is_replay = func_800D395C();
    record_result = func_800D2054(0, 0x80, score);
    is_record = record_result == 1 && (has_jiggy || is_replay);
    reached_target = score >= 50;
    earns_jiggy = reached_target && !has_jiggy && !is_replay;
    func_800FDC28(0);
    func_800FC6B0((earns_jiggy || is_record) ? 0x16 : 0x17);
    *dialog_arg = 6;
    if (earns_jiggy) {
        dialog_id = 0x10D2;
    } else if (is_record) {
        dialog_id = 0x10C0;
    } else if (!func_800D395C()) {
        if (has_jiggy) {
            if (record_result == 0)
                dialog_id = 0x10FA;
            else
                dialog_id = 0x10F9;
        } else {
            dialog_id = 0x10F8;
        }
    } else {
        dialog_id = 0xCEB;
        *dialog_arg = 0x46;
    }
    return dialog_id;
}

void func_80800BE8_chballoonburst(actor, forced_color) Actor *actor;
s32 forced_color;
{
    f32 pos[3];
    Actor *balloon;
    u8 *state;
    f32 roll;
    s32 color;
    s32 unk_0;
    s32 multi;

    state = func_80100094(actor, 0);
    unk_0 = func_800DA298(0);
    if (unk_0) {
        if (actor->unk3C) {
            func_800EE7F8(pos, func_80106790(actor->unk3C)->position);
        } else {
            func_800EFA4C(pos, 1400.0f, 350.0f, -1400.0f);
        }
    } else {
        pos[0] = func_800DC178(-1800.0f, 1800.0f);
        pos[1] = func_800DC178(100.0f, 200.0f);
        pos[2] = func_800DC178(-1800.0f, 1800.0f);
    }
    balloon = func_80108528(0x350, pos, (s32) func_800DC178(0.0f, 360.0f), &actor);
    roll = func_800DC0C0();
    if (roll < 0.1666f) {
        color = 0;
    } else {
        if (roll < 0.5f) {
            color = 1;
        } else {
            color = 2;
        }
    }
    if (forced_color != -1) {
        color = forced_color;
    }
    balloon->actorData[4] = 2 - color;
    multi = *(s32 *) (state + 0xC);
    balloon->unk64_20 = (multi == 0);
    switch (color) {
        case 0:
            func_80102424(balloon, 4);
            func_801032B0(balloon, 0x78C, 0);
            balloon->unk54 = 350.0f;
            break;
        case 1:
            func_80102424(balloon, 3);
            func_801032B0(balloon, 0x78D, 0);
            balloon->unk54 = 300.0f;
            break;
        case 2:
            func_80102424(balloon, 2);
            func_801032B0(balloon, 0x796, 0);
            balloon->unk54 = 250.0f;
    }
    balloon->unk3C = actor->unk0;
    balloon->unk6C_0 = actor->unk6C_0;
    balloon->unk64_19 = *(s32 *) (state + 0xC);
    if (unk_0) {
        balloon->unk54 = 50.0f;
        _susubgame_entrypoint_6(actor, state + 0x18, 4, 0xA0, 0);
        if (forced_color != -1 && actor->unk3C) {
            func_80801B6C_chballoonburst(func_80106790(actor->unk3C));
        }
        actor->unk3C = balloon->unk0;
    }
}

void func_80800EDC_chballoonburst(Actor *actor)
{
    Actor *state;
    state = func_80100094(actor, 0);
    *(u16 *) ((char *) actor + 0x6E) = (*(u16 *) ((char *) actor + 0x6E) & 0xFE00) | 5;
    *(s32 *) ((char *) state + 0x0C) = 1;
    _subaddiemulti_entrypoint_3(0xA);
    _sumultiscore_entrypoint_3((u8 *) state + 0x30);
    _sumultiscore_entrypoint_4((u8 *) state + 0x30, 6, 0, 1);
}

void func_80800F4C_chballoonburst(Actor *actor)
{
    u8 *state;
    state = func_80100094(actor, 0);
    _sumultiscore_entrypoint_6(state + 0x30);
    switch (actor->unk70_10) {
        case 1:
            if (!func_800C954C() && !func_800DA298(0x6AD)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0x22);
                func_80101FDC(actor, 2);
            }
            return;
        case 3:
            if (_subaddiefind_entrypoint_9(0x350) < 8) {
                if (func_800D9154(&actor->unk58,
                                  func_800DC178(0.5f, 1.0f) / (f32) _gcstatusDll_entrypoint_11())) {
                    func_80108B04(actor, -1);
                }
            }
            if (func_800CEAD0(actor->unk6C_0)) {
                func_80801338_chballoonburst(actor);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(actor, state + 0x18, 5, 1, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, *(s32 *) (state + 0x10),
                                              *(s32 *) (state + 0x14), 0, 0x22);
                func_80101FDC(actor, 5);
            }
    }
}

s32 func_808010D8_chballoonburst(s32 actor, s32 player)
{
    s32 state;

    state = func_80100094(actor, 0);
    _sumultiscore_entrypoint_12(state + 0x30, player, 1);
}

s32 func_8080110C_chballoonburst(Actor *actor, s32 event, PairEventPayload payload)
{
    switch (event) {
        case 0x2E:
            func_808011A8_chballoonburst(actor, payload.halves[0], payload.halves[1]);
            break;
        case 0x30:
            return func_80801254_chballoonburst(actor, payload.halves[0], payload.halves[1]);
        case 0x3D:
            func_80800BE8_chballoonburst(actor, -1);
            break;
        case 0x95:
            func_80801290_chballoonburst(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808011A8_chballoonburst(actor, dialog_id, choice) s32 actor;
s32 dialog_id;
s32 choice;
{
    s32 i;

switch (dialog_id) {
    case 0xCEC:
        func_80800970_chballoonburst(actor, 1);
        return;
    case 0x10CF:;
    case 0x10D0:
        i = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            do {
                func_800F7C58(i, 0x5D, 1);
                i += 1;
            } while (i < _gcstatusDll_entrypoint_11());
        }
        _subaddiemulti_entrypoint_2();
        func_80101FDC(actor, 6);
        _gcfrontend_entrypoint_10();
}

}

s32 func_80801254_chballoonburst(actor, dialog_id, choice)
s32 actor;
s32 dialog_id;
s32 choice;
{
    s32 id;
    id = dialog_id;

if (id == 0x10cf) {
    s32 state;
    state = func_80100094(actor, 0);
    return *(s32 *) ((char *) state + 8) + 1;
}

return 0;
}

int func_80801290_chballoonburst(actor)
Actor *actor;
{
    s32 *base = (s32 *) actor;
    s32 i;

    func_800BF744(1, 1);
    func_800BF744(2, 0);
    func_800BF544(0, 0, 0);

if (((u32) *(u16 *) ((char *) base + 0x72) >> 10) == 1) {
    _subaddiemulti_entrypoint_1(2, 0);
}

i = 0;

if (_gcstatusDll_entrypoint_11() > 0) {
    do {
        func_800F7C58(i, 0x5D, 1);
        func_800F4CEC(i, 0x77);
        i += 1;
    } while (i < _gcstatusDll_entrypoint_11());
}

}

void func_80801338_chballoonburst(actor) Actor *actor;
{
    u8 *state;
    s32 scores[8];
    s32 best;
    s32 i;
    s32 j;
    s32 k;
    s32 tmp;
    s32 dialog_id;

    state = func_80100094(actor, 0);
    best = -1;
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        scores[i] = _sumultiscore_entrypoint_8(state + 0x30, i, 6);

if (best < scores[i]) {
    best = scores[i];
}

func_800AA20C(i, scores[i]);

}
for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
    if (best == scores[i]) {
        _sumultiscore_entrypoint_11(state + 0x30, i, 6, 3.0f);
    }

}
for (j = 1; j < _gcstatusDll_entrypoint_11(); j++) {
    for (k = j; k > 0 && scores[k - 1] < scores[k]; k--) {
        tmp = scores[k];
        scores[k] = scores[k - 1];
        scores[k - 1] = tmp;
    }
}
func_800FC6B0(0x16);
if (scores[0] != scores[1]) {
    // Matching: the empty loop body is needed for the match.
    for (k = 0; _sumultiscore_entrypoint_8(state + 0x30, k, 6) != scores[0];
         k++) {
    }
    *(s32 *) (state + 8) = k;
    dialog_id = 0x10CF;
} else {
    dialog_id = 0x10D0;
}
_subaddiemulti_entrypoint_1(0, 0);
*(s32 *) (state + 0x10) = dialog_id;
*(s32 *) (state + 0x14) = 6;
func_80101FDC(actor, 4);
}

void func_8080154C_chballoonburst(Actor *actor)
{
    f32 dir;
    dir = func_800DC298(0.5f) ? 1.0f : -1.0f;
    actor->unk50 = func_800DC178(100.0f, 200.0f) * dir;
    _subaddiefade_entrypoint_2(actor);
    func_8010A800(actor, 2);
    func_80801AFC_chballoonburst(actor);
}

void func_808015D4_chballoonburst(Actor *actor)
{
    f32 dt;
    s32 reached_top;
    s32 unk_0;
    s32 unk_1;
    s32 can_burst;
    f32 scale;

    dt = func_800D8FF8();
    reached_top = 0;
    unk_0 = func_800DA298(0);
    unk_1 = 0;
    can_burst = 1;
    if (func_800CEAD0(actor->unk6C_0)) {
        func_8010A570(actor);
    }
    actor->rotation[1] = func_800136E4(actor->rotation[1] + actor->unk50 * dt);
    if (actor->position[1] < 2800.0f) {
        actor->position[1] += dt * actor->unk54;
    } else {
        reached_top = 1;
    }
    if (_subaddiefade_entrypoint_0(actor) == 255) {
        func_8010A800(actor, 0);
    }
    switch (actor->unk70_10) {
        case 4:
            unk_1 = func_800DA298(3);
            break;
        case 3:
            unk_1 = func_800DA298(2);
            break;
        case 2:
            unk_1 = func_800DA298(1);
            break;
        case 5:
            scale = func_800F10B4(actor->unk58, 0.0f, 1.4f, 0.2f, 1.0f);
            can_burst = 0;
            func_80102FDC(actor, scale);
            if (func_800D90A4(&actor->unk58)) {
                func_8010A570(actor);
                func_800FFAB0(actor);
                return;
            }
    }
    if (can_burst && ((!unk_0 && reached_top) || (unk_0 && unk_1))) {
        func_80801B6C_chballoonburst(actor);
    }
}

int func_808017A4_chballoonburst(Actor *actor, s32 event, u8 *arg)
{
    u8 *state;
    u8 *egg;
    s32 player;
    s32 points;
    switch (event) {
        case 0x40:
            if ((s32) actor->unk70_10 >= 2 && (s32) actor->unk70_10 < 6) {
                egg = (*(u8 **) &arg);
                player = _subaddiemulti_entrypoint_5(egg);
                points = actor->actorData[4] + 1;
                state = func_80100094(func_80106790(actor->unk3C), 0);

if (*(s32 *) (state + 0xC)) {
    _sumultiscore_entrypoint_7(state + 0x30, player, 6, points);
} else {
    *(s32 *) (state + 4) += points;
}

_chscorepoints_entrypoint_2(points, player, actor->position, 1);
func_80801948_chballoonburst(actor);
func_8010A570(actor);
func_800FFAB0(actor);

if (*(u16 *) (egg + 0x18) & 1) {
    func_8010114C(egg, 0x98, 0);
}

}
break;
case 0x29:
    if (actor->unk64_20) {
        func_8010DC50(4);
    }
    break;

case 0x2A:
    if (actor->unk64_20) {
        func_8010DCB4(4);
    }
    break;

case 0x1F:
    egg = arg;

if (actor->unk64_20) {
    func_8010DD20(actor, 4, egg);
}

else
{
    func_801015D0(actor);
}
break;
default:
    return 0;
    }
    return 1;
    }

    void func_80801948_chballoonburst(actor) Actor *actor;
    {
        func_8010D930(1, (*(s32 *) ((u8 *) actor + 0x70)) & 1, (u8 *) actor + 4,
                      &D_80801D18_chballoonburst);
        if (actor->unk64_20) {
            func_80801A50_chballoonburst(actor, 0x771, 2);
            func_80801A50_chballoonburst(actor, 0x772, 3);
            func_80801A50_chballoonburst(actor, 0x773, 4);
            func_80801ABC_chballoonburst(actor);
            func_80801A10_chballoonburst(actor);
            return;
        }
        func_80801A50_chballoonburst(actor, 0x771, 2);
        func_80801A50_chballoonburst(actor, 0x772, 2);
        func_80801A50_chballoonburst(actor, 0x773, 2);
    }

    void func_80801A10_chballoonburst(actor) s32 actor;
    {
        int pos;
        // Matching: `^ 0` below only exists to match.
        pos = actor + 4;
        func_800BBCB8(pos, pos, *((f32 *) ((actor ^ 0) + 0x38)), 8,
                      &D_80801D28_chballoonburst);
    }

    void func_80801A50_chballoonburst(actor, unk_1, unk_2) s32 actor;
    s32 unk_1;
    s32 unk_2;
    {
        s32 handle_copy;
        s32 handle;
        s32 pos;

        handle = func_800B53A4(unk_2);
        handle_copy = handle;
        func_800BA670(handle, unk_1);
        pos = actor + 4;
        func_800BABB8(handle_copy, pos, pos, *(s32 **) ((char *) actor + 0x38),
                      &D_80801D5C_chballoonburst);
        func_800BA22C(handle_copy, unk_2);
    }

    void func_80801ABC_chballoonburst(actor) s32 actor;
    {
        func_800BBCB8(actor + 4, 0, *((f32 *) ((actor ^ 0) + 0x38)), 1,
                      &D_80801D98_chballoonburst);
    }

    void func_80801AFC_chballoonburst(actor) Actor *actor;
    {
        if (actor->unk64_20) {
            func_800BBCB8(actor->position, 0, actor->scale, 0xE, D_80801DBC_chballoonburst);
        }
        func_8010D930(4, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                      D_80801DF0_chballoonburst);
    }

    void func_80801B6C_chballoonburst(actor) Actor *actor;
    {
        if (actor->unk70_10 != 5) {
            actor->unk58 = 1.4f;
            func_80102424(actor, 5);
            func_8010D930(5, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                          D_80801DFC_chballoonburst);
        }
    }

    extern void func_801018A4();
    extern void func_80108ED0();
    int D_80801C40_chballoonburst[18] = {0x2B1034F,
                                         0x1,
                                         0x0,
                                         (u32) func_80800098_chballoonburst,
                                         (u32) func_80105834,
                                         (u32) func_8010A730,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x400000,
                                         (u32) func_808008F0_chballoonburst,
                                         0x0,
                                         0x54C0000,
                                         (u32) func_80800024_chballoonburst,
                                         (u32) func_80107C2C,
                                         -0x7FFFF9FE,
                                         (u32) func_808001FC_chballoonburst,
                                         0x0};
    int D_80801C88_chballoonburst[18] = {0x2B1044C,
                                         -0xFFFF,
                                         0x0,
                                         (u32) func_80800F4C_chballoonburst,
                                         (u32) func_80105834,
                                         (u32) func_808010D8_chballoonburst,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x400400,
                                         (u32) func_808008F0_chballoonburst,
                                         0x0,
                                         0x54C0000,
                                         (u32) func_80800EDC_chballoonburst,
                                         (u32) func_80107C2C,
                                         -0x7FFFFBFE,
                                         (u32) func_8080110C_chballoonburst,
                                         0x0};
    int D_80801CD0_chballoonburst[18] = {0x2B20350,
                                         -0xFFFF,
                                         0x0,
                                         (u32) func_808015D4_chballoonburst,
                                         (u32) func_80105834,
                                         (u32) func_801018A4,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x4,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_8080154C_chballoonburst,
                                         (u32) func_80107C2C,
                                         -0x7FDFFF80,
                                         (u32) func_808017A4_chballoonburst,
                                         0x0};
    void *D_80801D18_chballoonburst = (void *) 0x001304FB;
    static u32 D_80801D18_chballoonburst_rest[3] = {0x180001, 0x7D01388, 0x0};
    s32 D_80801D28_chballoonburst[13] = {0x113001D, 0x9E20016, 0x10000015, 0xB3,    0x2B0133,
                                         0x1990022, 0x4C0059,  0x260033,   0xE000A, 0x14002D,
                                         0x4B005DC, 0x1BFF9C,  -0xC80000};
    s32 D_80801D5C_chballoonburst[15] = {0x1130016, 0x10000015, 0xCC,     0x2B0133,  0x1990022,
                                         0x1000100, 0x660099,   0xE000A,  0x14002D,  0x4B005DC,
                                         0x1BFF9C,  -0xC7FFD9,  0xC800C8, 0x1900190, 0x0};
    s32 D_80801D98_chballoonburst[9] = {0x1D09DD, 0x2B0200, 0x2800022, 0x3000380, 0x8000A00,
                                        0x150000, 0x260019, 0x7,       0x0};
    u8 D_80801DBC_chballoonburst[52] = {
        0x1,  0x13, 0x0,  0x1D, 0x9,  0xE5, 0x0,  0x1B, 0x0,  0xC8, 0x3,  0x20, 0x0,
        0xB,  0x0,  0x78, 0x0,  0x8C, 0x0,  0x64, 0x0,  0x0,  0x0,  0x23, 0x0,  0x99,
        0x0,  0x2B, 0x1,  0x33, 0x1,  0x66, 0x0,  0x15, 0x0,  0x0,  0x0,  0x8C, 0x0,
        0x16, 0x12, 0x0,  0x0,  0x1E, 0xFF, 0xB0, 0xFF, 0xB0, 0x0,  0x0,  0x0,  0x0};
    u8 D_80801DF0_chballoonburst[12] = {0x0, 0x13, 0x3, 0xED, 0x0, 0x1,
                                        0x3, 0xE8, 0x9, 0xC4, 0x0, 0x0};
    u8 D_80801DFC_chballoonburst[36] = {0x0, 0x13, 0x4,  0xFD, 0x0, 0xD,  0x0,  0xF3, 0x1,
                                        0xC, 0x0,  0x15, 0x0,  0x0, 0x1,  0x33, 0x0,  0x33,
                                        0x0, 0x1,  0x3,  0xE8, 0x9, 0xC4, 0x0,  0x0,  0x0,
                                        0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0};
