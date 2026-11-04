// Twinkly Packing minigame (GI packing room and its multiplayer map), single and multiplayer.
// Twinklies come in three colours (0..2); delivering one to its box scores 3 - colour points.
#include "common.h"

extern int D_80802218_chfactorytwinklies[];
extern int D_80802260_chfactorytwinklies[];
extern int D_808022A8_chfactorytwinklies[];
extern int D_80802338_chfactorytwinklies[];
extern int D_80802380_chfactorytwinklies[];
extern void *func_80100094(Actor *, u32);
extern u32 func_800FDC28(u32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern s32 func_800D211C(s32);
typedef struct TwinklieNodeIndex {
    u8 pad_0[0x70];
    u32 local_0 : 7;
    u32 pad_1 : 25;
} TwinklieNodeIndex;
typedef struct TwinklieMarkerFlag {
    u8 pad_0[0x2A];
    u8 pad_1 : 2;
    u8 local_0 : 1;
    u8 pad_2 : 5;
} TwinklieMarkerFlag;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800FC6B0(u32);
typedef struct {
    s32 local_0[16];
    s32 local_1[4][3];
} TwinkliesPlayers;
typedef union {
    s32 word;
    s16 halves[2];
} TwinklyEventArg;
typedef struct {
    s32 local_0[8];
    s32 local_1[8];
    u8 local_2[0x60];
    s32 local_3;
} Mass47Twinklies;
typedef struct {
    u8 pad[0x28];
    s32 f28;
    s32 f2C;
    u8 pad30[0x46];
    u16 f76 : 9;
    u16 pad76 : 7;
} TwinkS;
typedef struct {
    s32 total[4];
    u8 pad10[0x30];
    s32 cnt[4][3];
} TwinkData;
extern void func_800F5A2C(s32, s32, f32 *);
extern void func_80102FDC(Actor *, f32);
typedef union {
    s32 local_0;
    Unk80132ED0 *local_1;
} TemplateEventValue1161;
extern u8 D_8080243C_chfactorytwinklies[];
extern s16 D_80802478_chfactorytwinklies[];
extern u8 D_80802468_chfactorytwinklies[];
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800BA22C(s32, s32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9078();
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800DC0C0(void);
extern s32 func_800D9154(f32 *, f32);
extern void func_800F7ECC(s32, s32, f32);
extern s32 func_800F54E4(void);
extern void func_800F82D4(s32, s32);
extern void _susubgame_entrypoint_4(Actor *, void *);
extern s32 _susubgame_entrypoint_10(Actor *, s32, s32, s32);
extern void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
extern void _chintrotext_entrypoint_2(s32);
extern void _chmrtannoy_entrypoint_0(void);
extern void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern s32 _susubgame_entrypoint_3(Actor *, void *, s32, s32);
extern s32 func_800D395C(void);
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    u8 pad_0[0x40];
    s32 local_0[4][3];
} TwinkliesCounterState;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F849C(s32, f32);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 flag : 1;
    u32 pad_2 : 13;
} TW28;
extern void func_8010A3E8(Actor *, f32);
extern void func_800C8E54(s32, f32, f32);
extern u8 D_808023C8_chfactorytwinklies[];
extern u8 D_808023EC_chfactorytwinklies[];
extern u8 D_80802400_chfactorytwinklies[];
typedef struct {
    u8 pad[0x64];
    u8 p64 : 7;
    u8 b64_0 : 1;
    u8 p65a : 4;
    u8 b65_3 : 1;
    u8 p65b : 3;
    u8 pad66[0xF];
    u8 p75a : 3;
    u8 b75_4 : 1;
    u8 p75b : 4;
} TwC;
typedef struct {
    u8 pad[0x28];
    u32 hi : 18;
    u32 b13 : 1;
    u32 lo : 13;
} TwA;
typedef struct {
    u8 pad[0x64];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 b29 : 1;
    u32 mid : 9;
    u32 b19 : 1;
    u32 rest : 19;
} TwB;
extern u8 D_808021C0_chfactorytwinklies[];
extern u8 D_80802414_chfactorytwinklies[];
extern u8 D_80802428_chfactorytwinklies[];
extern f32 func_800D8FF8(void);
extern s32 func_800CEAD0(s32);
extern void *_chlightfader_entrypoint_1();
extern void func_8010A570(void *);
extern void func_80101FDC(void *, s32);
extern void _subaddiefade_entrypoint_3(void *);
extern f32 func_80101F24(void *);
extern f32 func_800F3780(f32, void *, s32);
extern s32 func_80101E14(void *, s32);
extern void func_8010D930(s32, s32, void *, void *);
extern f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
extern void func_80102BF8(void *, s32, s32, s32);
extern void func_8010C3A8(void *, s32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 _subaddierouteDll_entrypoint_4(void *);
extern void _subaddierouteDll_entrypoint_7(void *, void *, s32, s32, f32, s32);
extern void _subaddierouteDll_entrypoint_6(void *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(void *, void *, s32, s32, f32, f32);
extern void func_800FFAB0(void *);
extern void func_80103DFC(void *, f32 *);
extern void func_800C8CB8(void *, f32 *);
extern f32 func_80013970(f32);
extern void func_800EFE50(void *, void *, void *, f32);
int func_80801108_chfactorytwinklies();
int func_80801174_chfactorytwinklies();
void func_80801DD8_chfactorytwinklies();
void func_80800D00_chfactorytwinklies();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080145C_chfactorytwinklies();
extern void *D_808022F0_chfactorytwinklies[];

int chfactorytwinklies_entrypoint_0()
{
    return (int) &D_80802218_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_1()
{
    return &D_80802260_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_2()
{
    return &D_808022A8_chfactorytwinklies;
}

s32 chfactorytwinklies_entrypoint_3()
{
    return (s32) &D_808022F0_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_4()
{
    return (int) &D_80802338_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_5()
{
    return (int) &D_80802380_chfactorytwinklies;
}

void func_80800048_chfactorytwinklies(Actor *actor)
{
    u8 *state = (u8 *) func_80100094(actor, 0);
    s32 i;
    s32 player = func_800F54E4();

    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        ((s32 *) state)[i] = 0;
        ((s32(*)[3])(state + 0x40))[i][0] = 0;
        ((s32(*)[3])(state + 0x40))[i][1] = 0;
        ((s32(*)[3])(state + 0x40))[i][2] = 0;
    }
    func_800946C4(func_800F53D0(player), 1);
    _susubgame_entrypoint_0(actor, state + 0xAC, 0);
    _susubgame_entrypoint_11(0);
    func_800A16BC(1);
    switch (func_800F5410(player)) {
        case 10:
            func_800D2748(0xEF, 0x57);
            break;
        case 11:
            func_800D2748(0xEF, 0x58);
            break;
        case 13:
            func_800D2748(0xEF, 0x59);
            break;
        case 7:
            func_800D2748(0xEF, 0x5A);
            break;
        default:
            func_800D2748(0xEF, 0x5B);
            break;
    }
}

s32 func_80800B80_chfactorytwinklies();

void func_808001A0_chfactorytwinklies(Actor *actor)
{
    u8 *state;
    s32 colour;
    s32 player;
    f32 roll;
    s32 i;
    s32 *row;

    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 3:
            player = func_800F54E4();
            func_800D2498(0xEF, ((s32 *) state)[player], 0);
            row = (s32 *) ((u8 *) state + player * 12);
            for (i = 0; i < 3; i++) {
                func_800D2498(i + 0xF0, *(row + 0x10), 0);
                row++;
            }
            func_80800D00_chfactorytwinklies(actor);
            if (func_800CEAD0(0)) {
                *(s32 *) (state + 0xA4) =
                    func_80800B80_chfactorytwinklies(actor, state + 0xA8);
                func_800F7ECC(func_800F54E4(), 3, 0.0f);
                func_800F8300(func_800F54E4(), 2, 0);
                func_80101FDC(actor, 4);
                return;
            }
            // Pick a random colour for the next twinkly.
            if (func_800D9154(&actor->unk58, func_800DC178(1.0f, 1.199996948f))) {
                roll = func_800DC0C0();
                if (roll < 0.1666f)
                    colour = 0;
                else if (roll < 0.5f)
                    colour = 1;
                else
                    colour = 2;
                func_80108B04(actor, colour);
            }
        case 1:
            return;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(actor, state + 0xAC, 5, 1, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, *(s32 *) (state + 0xA4),
                                              *(s32 *) (state + 0xA8), 0, 0xA3);
                func_80101FDC(actor, 5);
            }
            break;
        case 7:
            if (func_800D0B68(0x3B, 1)) {
                func_800F8300(func_800F54E4(), 2, 0);
                // Matching: empty block steers IDO's register allocation.
                if (1) {
                }
                *(s32 *) (state + 0xA4) = 0xCEB;
                *(s32 *) (state + 0xA8) = 0x46;
                func_80101FDC(actor, 4);
            }
    }
}

void func_80800A84_chfactorytwinklies();

s32 func_808009EC_chfactorytwinklies();

void func_80800748_chfactorytwinklies();

s32 func_8080040C_chfactorytwinklies(Actor *actor, s32 event, s32 arg)
{
    u8 *state;

    state = func_80100094(actor, 0);
    switch (event) {
        case 0x2E:
            func_80800748_chfactorytwinklies(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            return 1;
        case 0x30:
            return func_808009EC_chfactorytwinklies(actor, ((s16 *) &arg)[0],
                                                    ((s16 *) &arg)[1]);
        case 0x3D:
            func_80800A84_chfactorytwinklies(actor, arg);
            return 1;
        case 0xB:
            if (arg == 0x15) {
                func_800F82D4(func_800F54E4(), 0);
                func_80101FDC(actor, 7);
                _susubgame_entrypoint_4(actor, state + 0xAC);
                return 4;
            }
            return 3;
        case 0x49:
            if (_susubgame_entrypoint_10(actor, 1, 800, 456)) {
                _susubgame_entrypoint_6(actor, state + 0xAC, 0, 0x20, 0);
                _chintrotext_entrypoint_2(1);
                return 1;
            }
            _chmrtannoy_entrypoint_0();
            _susubgame_entrypoint_5(actor, state + 0xAC, 5, 1, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, actor->position, 0xA3);
            func_800F82D4(func_800F54E4(), 2);
            return 1;
        case 0x57:
            return _susubgame_entrypoint_3(actor, state + 0xAC, arg & 0xFFFF,
                                           (u32) (arg & 0xFFFF0000) >> 16);
        case 0x32:
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(actor->unk0, func_800D395C() ? 0x1385 : 0x1344, 0x46,
                                          actor->position, 0xA3);
            func_800F82D4(func_800F54E4(), 2);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080064C_chfactorytwinklies(actor) Actor *actor;
{
    u8 *state;

    state = func_80100094(actor, 0);
    func_800A16BC(0);
    if (func_800CEAA8(0)) {
        func_800CE88C(0, 0);
    }
    if (_susubgame_entrypoint_2(actor, state + 0xAC)) {
        _susubgame_entrypoint_4(actor, state + 0xAC);
    }
    func_800FDC28(0);
}

void func_808006C0_chfactorytwinklies(actor) Actor *actor;
{
    f32 duration = 60.0f;
    _subaddiemulti_entrypoint_2(actor);
    func_80101FDC(actor, 3);
    func_800CE8D8(0, duration, (s32) duration);
    func_800CE88C(0, 1);
    actor->unk58 = 0.01f;
    if (func_800DA298(0x6A7))
        _subaddiemulti_entrypoint_4(0x17);
    func_800FDC28(12);
}

void func_80800748_chfactorytwinklies(Actor *actor, s32 dialog_id, s32 choice)
{
    u8 *state;
    Actor *found;

    state = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x1344:
        case 0x1385:
            if (choice > 0) {
                _susubgame_entrypoint_6(actor, state + 0xAC, 6, 0x20, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1345, 0x44, 0, 0xA3);
                func_80108B04(actor, 0);
            } else {
                _susubgame_entrypoint_5(actor, state + 0xAC, 5, 1, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0xA3);
            }
            _gcfrontend_entrypoint_9(0x6D);
            return;
        case 0x1345:
            _susubgame_entrypoint_5(actor, state + 0xAC, 5, 1, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0xA3);
            return;
        case 0xCEB:
            func_800F82D4(func_800F54E4(), 0);
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
                _gcgoto_entrypoint_1(0x10A, 1);
                return;
            }
            found = _subaddiefind_entrypoint_2(0x21A, 0);
            if (found != 0) {
                _subaddiefade_entrypoint_3(found);
                func_8010A570(found);
            }
            _susubgame_entrypoint_4(actor, state + 0xAC);
            return;
        case 0xCEC:
            _susubgame_entrypoint_4(actor, state + 0xAC);
            func_808006C0_chfactorytwinklies(actor);
            return;
        case 0x1346:
            _susubgame_entrypoint_6(actor, state + 0xAC, 0x15, 0x10, 0);
            func_800D1000(0x3B, 1, 0, 1, 0);
            return;
        case 0x1347:
        case 0x1374:
        case 0x1375:
        case 0x1376:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x46, 0, 0xA3);
    }
}

s32 func_808009EC_chfactorytwinklies(Actor *actor, s32 dialog_id, s32 unused)
{
    s32 *scores;
    scores = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x1347:
            return scores[func_800F54E4()];
        case 0x1345:
            return 0x28;
        case 0x1375:
        case 0x1385:
            return func_800D211C(0x83);
    }
    return 0;
}

// Spawn a twinkly of the given colour.
void func_80800A84_chfactorytwinklies(Actor *actor, s32 colour)
{
    u8 *state;
    Actor *twinkly;
    f32 pos[3];
    s32 angle;

    switch (colour) {
        case 0:
        case 1:
        case 2:
            state = func_80100094(actor, 0);
            if (_susubgame_entrypoint_2(actor, state + 0xAC)) {
                func_800EE7F8(pos, actor->position);
            } else {
                func_800CD08C(((TwinklieNodeIndex *) actor)->local_0 - 1, pos);
            }
            pos[1] = 0.0f;
            angle = func_800DC128(0, 359);
            twinkly = func_80108528(colour + 0x443, pos, angle, &actor);
            twinkly->unk3C = actor->unk0;
            twinkly->actorData[5] = colour;
            ((TwinklieMarkerFlag *) twinkly->unk0)->local_0 =
                _susubgame_entrypoint_2(actor, state + 0xAC);
    }
}

s32 func_80800B80_chfactorytwinklies(Actor *actor, s32 *dialog_arg)
{
    s32 *scores;
    s32 score;
    s32 dialog_id;
    s32 beat_record;
    s32 score_ok;
    u32 won_jiggy;
    s32 has_jiggy;
    s32 is_replay;
    s32 record_result;

    scores = func_80100094(actor, 0);
    score = scores[func_800F54E4()];
    has_jiggy = func_800D0A9C(0x3B, 1);
    is_replay = func_800D395C();
    record_result = func_800D2054(0, 0x83, score);
    beat_record = record_result == 1 && (has_jiggy || is_replay);
    score_ok = score >= 40;
    won_jiggy = score_ok && !has_jiggy && !is_replay;
    func_800FDC28(0);
    func_800FC6B0((won_jiggy || beat_record) ? 0x16 : 0x17);
    *dialog_arg = 6;
    if (won_jiggy) {
        dialog_id = 0x1346;
    } else if (beat_record) {
        dialog_id = 0x1347;
    } else if (!func_800D395C()) {
        if (has_jiggy) {
            if (record_result == 0)
                dialog_id = 0x1376;
            else
                dialog_id = 0x1375;
        } else {
            dialog_id = 0x1374;
        }
    } else {
        dialog_id = 0xCEB;
        *dialog_arg = 0x46;
    }
    return dialog_id;
}

void func_80800D00_chfactorytwinklies(actor) Actor *actor;
{
    TwinkliesCounterState *state;
    s32 i;
    s32 total;

    state = (TwinkliesCounterState *) func_80100094(actor, 0);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        total = state->local_0[i][0] + state->local_0[i][1] +
                  state->local_0[i][2];
        func_800F849C(i, func_800F10B4((f32) total, 0.0f, 10.0f, 1.0f, 0.6f));
    }
}

void func_80800DE0_chfactorytwinklies(actor) Actor *actor;
{
    TwinkliesPlayers *state;
    s32 i;
    state = func_80100094(actor, 0);
    func_800A16BC(1);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        state->local_0[i] = 0;
        state->local_1[i][0] = 0;
        state->local_1[i][1] = 0;
        state->local_1[i][2] = 0;
        func_800946C4(func_800F53D0(i), 1);
        func_800D2748(i + 0xC3, i + 0x5B);
    }
    _subaddiemulti_entrypoint_3(10);
}

void func_808013BC_chfactorytwinklies();

void func_808011B0_chfactorytwinklies();

void func_80800E9C_chfactorytwinklies(Actor *actor)
{
    s32 unk_0;
    s32 colour;
    s32 phase;
    s32 alive_444;
    f32 roll;
    f32 delay;
    phase = actor->unk70_10;
    switch (phase) {
        case 1:
            if (!func_800C954C() && !func_800DA298(0x6AD)) {
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0xA3);
                func_80101FDC(actor, 2);
            }
            break;
        case 3:
            func_808013BC_chfactorytwinklies(actor, 0);
            func_80800D00_chfactorytwinklies(actor);
            if (func_800CEAD0(0)) {
                func_808011B0_chfactorytwinklies(actor);
                break;
            }
            alive_444 = _subaddiefind_entrypoint_9(0x444);
            phase = _subaddiefind_entrypoint_9(0x443);
            if (_subaddiefind_entrypoint_9(0x445) + phase + alive_444 < 4) {
                delay = func_800DC178(1.0f, 1.199997f);
                if (func_800D9154(&actor->unk58, delay / _gcstatusDll_entrypoint_11())) {
                    roll = func_800DC0C0();
                    if (roll < 0.25f)
                        colour = 0;
                    else if (roll < 0.6f)
                        colour = 1;
                    else
                        colour = 2;
                    func_80108B04(actor, colour);
                }
            }
            break;
        case 5:
        case 6:
            func_808013BC_chfactorytwinklies(actor, 1);
            break;
    }
}

s32 func_8080105C_chfactorytwinklies(Actor *actor, s32 event, TwinklyEventArg arg)
{
    switch (event) {
        case 0x2E:
            func_80801108_chfactorytwinklies(actor, arg.halves[0], arg.halves[1]);
            break;
        case 0x30:
            return func_80801174_chfactorytwinklies(actor, arg.halves[0], arg.halves[1]);
        case 0x3D:
            func_80800A84_chfactorytwinklies(actor, arg.word);
            break;
        case 0x95:
            _subaddiemulti_entrypoint_1(0, 0);
            _subaddiemulti_entrypoint_4(0);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80801108_chfactorytwinklies(actor, dialog_id, choice)
s32 actor;
s32 dialog_id;
s32 choice;
{
    switch (dialog_id) {
        case 0xCEC:
            func_808006C0_chfactorytwinklies((Actor *) actor);
            break;

        case 0x1348:

        case 0x1349:

            _subaddiemulti_entrypoint_2(actor);
            func_80101FDC(actor, 6);
            _gcfrontend_entrypoint_10();
    }
}

int func_80801174_chfactorytwinklies(actor, dialog_id, choice)
Actor *actor;
s32 dialog_id;
s32 choice;
{
    if (dialog_id == 0x1348) {
        return *(s32 *) ((u8 *) func_80100094(actor, 0) + 0xA0) + 1;
    }
    return 0;
}

void func_808011B0_chfactorytwinklies(Actor *actor)
{
    Mass47Twinklies *state;
    s32 sorted[8];
    s32 i;
    s32 j;
    s32 swap;
    s32 best;
    s32 dialog_id;
    s32 k;

    state = func_80100094(actor, 0);
    best = -1;
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        sorted[i] = state->local_0[i];
        if (best < sorted[i]) {
            best = sorted[i];
        }
        func_800AA20C(i, sorted[i]);
    }
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        if (best == sorted[i]) {
            state->local_1[i] = 1;
        }
    }
    for (k = 1; k < _gcstatusDll_entrypoint_11(); k++) {
        for (j = k; j > 0 && sorted[j - 1] < sorted[j]; j--) {
            swap = sorted[j];
            sorted[j] = sorted[j - 1];
            sorted[j - 1] = swap;
        }
    }
    func_800FC6B0(0x16);
    if (sorted[0] != sorted[1]) {
        for (j = 0; state->local_0[j] != sorted[0]; j++) {
        }
        state->local_3 = j;
        dialog_id = 0x1348;
    } else {
        dialog_id = 0x1349;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    func_80101FDC(actor, 5);
    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 6, 0, 0xA3);
}

void func_808013BC_chfactorytwinklies(Actor *actor, s32 show_winner)
{
    s32 *scores;
    s32 i;
    scores = func_80100094(actor, 0);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        func_800D24E8(i + 0xC3, scores[i], 0);
        if (show_winner && scores[i + 8])
            func_800D28A0(i + 0xC3);
    }
}

void func_8080145C_chfactorytwinklies(twinkly) TwinkS *twinkly;
{
    s32 colour = twinkly->f76 - 0x32;
    twinkly->f2C = colour;

    switch (colour) {
        case 0:
            twinkly->f28 = 0x20000000;
            break;
        case 1:
            twinkly->f28 = 0x10000000;
            break;
        case 2:
            twinkly->f28 = 0x8000000;
    }
}

// Packing box: deliver the carried twinklies of this colour for (3 - colour) points each.
void func_808014B0_chfactorytwinklies(Actor *actor)
{
    s32 *p;
    s32 *row;
    s32 pts;
    TwinkData *data;
    s32 j;
    s32 n;
    s32 pos;
    s32 i;
    data = func_80100094(func_80106790(actor->unk3C), 0);

    if (func_800CEAA8(0) && !func_800CEAD0(0)) {
        for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
            if (func_800F6C5C(i) && (func_800F55FC(i) & actor->actorData[4])) {
                n = data->cnt[i][actor->actorData[5]];
                if (n > 0) {
                    pts = (3 - actor->actorData[5]) * n;
                    p = &data->total[i];
                    *p += pts;
                    data->cnt[i][actor->actorData[5]] = 0;
                    func_800F5A2C(i, 5, &pos);
                    _chscorepoints_entrypoint_2(pts, i, &pos, 1);
                    func_80108B04(actor, i);
                }
            }
        }
    }
}

s32 func_80801608_chfactorytwinklies(actor, event, arg)
Actor *actor;
s32 event;
s32 arg;
{
    u8 *twinkly_data;
    Actor *twinkly;
    f32 pos[3];
    Actor *owner;

    switch (event) {
        case 0x3D:
            func_800F5A2C(arg, 5, pos);
            twinkly = func_80108528(*(s32 *) ((u8 *) actor + 0x2C) + 0x443, pos,
                                    func_800DC128(0, 0x167), &actor);
            twinkly_data = (u8 *) func_80100094(twinkly, 0);
            func_800EE7F8((f32 *) (twinkly_data + 0x1C), actor->position);
            func_800EE7F8((f32 *) (twinkly_data + 0x10), pos);
            func_80101FDC(twinkly, 5);
            func_80102FDC(twinkly, 0.2f);
            break;
        case 0x95:
            if (func_800EA05C() == 0x17D)
                owner = _subaddiefind_entrypoint_2(0x44D, 0);
            else
                owner = _subaddiefind_entrypoint_2(0x442, 0);
            actor->unk3C = owner->unk0;
            break;
        default:
            return 0;
    }

    return 1;
}

f32 func_80801FAC_chfactorytwinklies();

f32 func_80801ED0_chfactorytwinklies();

void func_8080171C_chfactorytwinklies(actor) Actor *actor;
{
    u8 *route;
    route = (u8 *) func_80100094(actor, 0);
    func_8010A3E8(actor, 0.3f);

    if (actor->unk70_10 == 1) {
        actor->position[1] -= 250.0f;
        *(f32 *) ((u8 *) actor + 0x28) = 0.6f;
        *(f32 *) ((u8 *) actor + 0x30) = func_80801ED0_chfactorytwinklies(actor);
        *(f32 *) ((u8 *) actor + 0x58) = func_80801FAC_chfactorytwinklies(actor);
        _subaddieDll_entrypoint_1(actor);
        _subaddierouteDll_entrypoint_3(actor, route, actor->position);
        _subaddierouteDll_entrypoint_1(actor);
        *(s32 *) (route + 12) = 0;
        *(s32 *) ((u8 *) actor + 0x50) = func_800C8A98();
        func_800C8E54(*(s32 *) ((u8 *) actor + 0x50), 500.0f, 800.0f);
        func_800C8E84(*(s32 *) ((u8 *) actor + 0x50),
                      D_808023C8_chfactorytwinklies + *(s32 *) ((u8 *) actor + 0x2C) * 12);
        if (((TW28 *) actor->unk0)->flag) {
            ((u8 *) actor)[0x64] &= ~1;
            *(f32 *) ((u8 *) actor + 0x58) = 5.5f;
        }
        func_8010D930(4, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                      D_808023EC_chfactorytwinklies);
    } else {
        func_8010D930(4, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                      D_80802400_chfactorytwinklies);
        func_8010A570(actor);
        *(f32 *) ((u8 *) actor + 0x58) = 1.2f;
        ((u8 *) actor)[0x64] &= ~1;
    }
}

s32 func_8080207C_chfactorytwinklies();

s32 func_80802020_chfactorytwinklies();

f32 func_80801F5C_chfactorytwinklies();

void func_808018A0_chfactorytwinklies(u8 *twinkly)
{
    void *route;
    f32 dt;
    f32 unk_0;
    f32 unk_1;
    f32 tmp;
    s32 done;
    f32 blend;
    f32 pos[3];
    route = func_80100094(twinkly, 0);
    dt = func_800D8FF8();
    if ((u32) *(u16 *) (twinkly + 0x72) >> 10 != 4) {
        if (func_800CEAD0(0) != 0 && !((TwA *) *(u8 **) twinkly)->b13) {
            if (*(void **) (twinkly + 0x50) != NULL) {
                *(void **) (twinkly + 0x50) =
                    _chlightfader_entrypoint_1(*(void **) (twinkly + 0x50), 0x3F266666, 2);
            }
            func_8010A570(twinkly);
            func_80101FDC(twinkly, 4);
            _subaddiefade_entrypoint_3(twinkly);
        }
    }
    switch (((u32) *(u16 *) (twinkly + 0x72) >> 10)) {
        case 1:
            if (func_80802020_chfactorytwinklies(twinkly) != 0) {
                func_80101FDC(twinkly, 2);
            }

            break;

        case 2:
            unk_0 = func_800F3780(func_80101F24(twinkly), D_808021C0_chfactorytwinklies, 5);

            if (func_80101E14(twinkly, 0x3E800000) != 0) {
                func_8010D930(2, *(u32 *) (twinkly + 0x70) & 1, twinkly + 4,
                              D_80802414_chfactorytwinklies);
            }

            if (((TwB *) twinkly)->b29) {
                unk_1 = _subaddiejoy_entrypoint_9(twinkly, twinkly + 0x54, 3);
                *(f32 *) (twinkly + 0x24) = func_80801F5C_chfactorytwinklies(twinkly) * 1.4f;
                func_80102BF8(twinkly, 0x3E4CCCCD, 0x41000000, 0x44160000);
                func_8010C3A8(twinkly, 0x201025, unk_1 * unk_0);
            } else {
                if (_subaddierouteDll_entrypoint_4(twinkly) != 0) {
                    _subaddierouteDll_entrypoint_7(twinkly, route, *(s32 *) (twinkly + 0x48),
                                                   *(s32 *) (twinkly + 0x54), 400.0f, 0x4802);
                    *(s32 *) ((u8 *) route + 0xC) = (s32) *(u16 *) ((u8 *) route + 6);
                }

                _subaddierouteDll_entrypoint_6(
                    twinkly, route, *((s32 *) ((u8 *) route + 0xC)), 0x3F, 0.4f, 20, 40);
                _subaddierouteDll_entrypoint_5(twinkly, route,
                                               *((s32 *) ((u8 *) route + 0xC)), 0x3E4CCCCD, 4.0f,
                                               200.0f);
                *((f32 *) (twinkly + 0x24)) = func_800F15F8(
                    *((f32 *) (twinkly + 0x24)), *((f32 *) (twinkly + 0x30)), dt * 800.0f);

                if (!((TwA *) *(u8 **) twinkly)->b13) {
                    func_8010C3A8(twinkly, 0x1325, unk_0);
                }
            }
            if (func_800D9078(twinkly + 0x58) != 0) {
                if (*(void **) (twinkly + 0x50) != NULL) {
                    *(void **) (twinkly + 0x50) =
                        _chlightfader_entrypoint_1(*(void **) (twinkly + 0x50), 0x3F800000, 2);
                }

                func_80101FDC(twinkly, 3);
                *((f32 *) (twinkly + 0x28)) = 0.6f;
                twinkly[0x64] = twinkly[0x64] & ~1;
            }
            break;

        case 3:
            if (!(((TwB *) twinkly)->b19)) {
                tmp = func_800F10B4(*((f32 *) (twinkly + 0x28)), 0.0f, 0.6f, 1.0f, 0.0f);

                if (0.3f < tmp) {
                    twinkly[0x75] = twinkly[0x75] & ~0x10;
                    func_8010D930(5, *(u32 *) (twinkly + 0x70) & 1, twinkly + 4,
                                  D_80802428_chfactorytwinklies);
                    ((TwC *) twinkly)->b65_3 = 1;
                }
            }
            if (func_8080207C_chfactorytwinklies(twinkly) != 0) {
                func_800FFAB0(twinkly);
            }

        case 4:
            break;

        case 5:
            done = func_800D9078(twinkly + 0x58);
            blend = func_800F12D4(*((f32 *) (twinkly + 0x58)), 0.0f, 1.2f, 1.0f, 0.0f);
            *((f32 *) (twinkly + 0x44)) += func_800D8FF8() * 100.0f;
            *((f32 *) (twinkly + 0x48)) += func_800D8FF8() * 60.0f;
            tmp = func_800D8FF8();
            *((f32 *) (twinkly + 0x38)) =
                func_800F15F8(*((f32 *) (twinkly + 0x38)), 1.0f, tmp + tmp);
            func_800EFE50(twinkly + 4, (u8 *) route + 0x10, (u8 *) route + 0x1C, blend);
            *((f32 *) (twinkly + 8)) += 80.0f * func_80013970(blend * 180.0f);
            if (done != 0) {
                func_800FFAB0(twinkly);
            }
    }
    if (*((void **) (twinkly + 0x50)) != NULL) {
        func_80103DFC(twinkly, pos);
        pos[1] = pos[1] + 100.0f;
        func_800C8CB8(*((void **) (twinkly + 0x50)), pos);
    }
}

void func_80801D58_chfactorytwinklies(twinkly) u8 *twinkly;
{
    int new_var;
    s32 new_var2;
    s32 temp_a3;
    // Matching: empty block and extra temporaries are needed for the match.
    if (twinkly) {
    }
    new_var2 = *((s32 *) (((u8 *) twinkly) + 0x50));
    temp_a3 = *((s32 *) (((u8 *) twinkly) + 0x50));
    if (temp_a3 != 0) {
        new_var = 0x50;
        *((s32 *) (((u8 *) twinkly) + new_var)) = _chlightfader_entrypoint_1(
            new_var2, 0x3F800000, 2, *((s32 *) (((u8 *) twinkly) + 0x50)));
    }
}

s32 func_80801D94_chfactorytwinklies(Actor *actor, s32 event, TemplateEventValue1161 arg)
{
    switch (event) {
        case 0x3E:
            func_80801DD8_chfactorytwinklies(actor,
                                             (u32) *(u16 *) ((u8 *) arg.local_1 + 0x1A) >> 5);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801DD8_chfactorytwinklies(actor, player) Actor *actor;
s32 player;
{
    Actor *owner;
    u8 *owner_data;
    s32 sfx;
    f32 pos[3];

    owner = func_80106790(actor->unk3C);
    owner_data = func_80100094(owner, 0);
    sfx = func_800B53A4(12);
    func_80103DFC(actor, pos);
    func_800BABB8(sfx, pos, pos, 1.0f, D_8080243C_chfactorytwinklies);
    func_800BA3FC(sfx, D_80802478_chfactorytwinklies[actor->actorData[5]]);
    func_800BA22C(sfx, 12);
    (*(s32(*)[3])(owner_data + 0x40 + player * 12))[actor->actorData[5]]++;
    func_8010D930(1, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                  D_80802468_chfactorytwinklies);
    func_800FFAB0(actor);
}

f32 func_80801ED0_chfactorytwinklies(Actor *actor)
{
    switch (*(s32 *) &actor->actorData[5]) {
        case 0:
            return func_800DC178(800.0f, 900.0f);
        case 1:
            return func_800DC178(600.0f, 700.0f);
        default:
            return func_800DC178(400.0f, 500.0f);
    }
}

f32 func_80801F5C_chfactorytwinklies(void *twinkly)
{
    s32 colour;

    colour = *(s32 *) ((char *) twinkly + 0x2C);
    switch (colour) {
        case 0:
            return 900.0f;
        case 1:
            return 700.0f;
        default:
            return 500.0f;
    }
}

f32 func_80801FAC_chfactorytwinklies(Actor *actor)
{
    switch (*(s32 *) &actor->actorData[5]) {
        case 0:
            return func_800DC178(4.0f, 4.0f);
        case 1:
            return func_800DC178(4.0f, 4.0f);
        default:
            return func_800DC178(4.0f, 4.0f);
    }
}

s32 func_80802020_chfactorytwinklies(u8 *twinkly)
{
    s32 done = func_800D9078(twinkly + 0x28);
    *(f32 *) (twinkly + 8) = func_800F12D4(*(f32 *) (twinkly + 0x28), 0.0f, 0.6f, 0.0f, -250.0f);
    return done;
}

s32 func_8080207C_chfactorytwinklies(u8 *twinkly)
{
    s32 done = func_800D9078(twinkly + 0x28);
    *(f32 *) (twinkly + 8) = func_800F12D4(*(f32 *) (twinkly + 0x28), 0.0f, 0.6f, -250.0f, 0.0f);
    return done;
}

extern void func_80108ED0();
u8 D_808021C0_chfactorytwinklies[40] = {0x0,  0x0, 0x0,  0x0,  0x3F, 0x0,  0x0,  0x0, 0x3E, 0x80,
                                        0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x3F, 0x0, 0x0,  0x0,
                                        0x3F, 0x0, 0x0,  0x0,  0x3F, 0x40, 0x0,  0x0, 0x3F, 0x80,
                                        0x0,  0x0, 0x3F, 0x80, 0x0,  0x0,  0x3F, 0x0, 0x0,  0x0};
u8 D_808021E8_chfactorytwinklies[48] = {
    0x0,  0x0, 0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x3F, 0xA, 0x3D, 0x71, 0x3, 0x60, 0x0, 0x0,
    0x3F, 0xA, 0x3D, 0x71, 0x3, 0x60, 0x0, 0x0, 0x3F, 0xA, 0x3D, 0x71, 0x3, 0x60, 0x0, 0x0,
    0x3F, 0xA, 0x3D, 0x71, 0x3, 0x60, 0x0, 0x0, 0x3F, 0xA, 0x3D, 0x71, 0x3, 0x60, 0x0, 0x0};
int D_80802218_chfactorytwinklies[18] = {0x1580442,
                                         0x1,
                                         0x0,
                                         (u32) func_808001A0_chfactorytwinklies,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x1,
                                         (u32) func_8080064C_chfactorytwinklies,
                                         0x0,
                                         0xC40000,
                                         (u32) func_80800048_chfactorytwinklies,
                                         (u32) func_80107C2C,
                                         -0x7FFFF9FE,
                                         (u32) func_8080040C_chfactorytwinklies,
                                         0x0};
int D_80802260_chfactorytwinklies[18] = {0x158044D,
                                         0x1,
                                         0x0,
                                         (u32) func_80800E9C_chfactorytwinklies,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x1,
                                         (u32) func_8080064C_chfactorytwinklies,
                                         0x0,
                                         0xC40000,
                                         (u32) func_80800DE0_chfactorytwinklies,
                                         (u32) func_80107C2C,
                                         -0x7FFFF9FE,
                                         (u32) func_8080105C_chfactorytwinklies,
                                         0x0};
int D_808022A8_chfactorytwinklies[18] = {0x1580446,
                                         0x1,
                                         0x0,
                                         (u32) func_808014B0_chfactorytwinklies,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_8080145C_chfactorytwinklies,
                                         (u32) func_80107C2C,
                                         -0x7FFFFBFE,
                                         (u32) func_80801608_chfactorytwinklies,
                                         0x0};
void *D_808022F0_chfactorytwinklies[18] = {(void *) 0x01AB0443,
                                           (void *) 0x07C50001,
                                           (void *) &D_808021E8_chfactorytwinklies,
                                           (void *) func_808018A0_chfactorytwinklies,
                                           (void *) func_80105834,
                                           (void *) func_80101870,
                                           0,
                                           (void *) 0x3F800000,
                                           0,
                                           (void *) 0x0006012C,
                                           (void *) func_80801D58_chfactorytwinklies,
                                           (void *) func_80108ED0,
                                           (void *) 0x00280000,
                                           (void *) func_8080171C_chfactorytwinklies,
                                           (void *) func_80107C2C,
                                           (void *) 0x80001001,
                                           (void *) func_80801D94_chfactorytwinklies,
                                           0};
int D_80802338_chfactorytwinklies[18] = {0x1AB0444,
                                         0x7C60001,
                                         (u32) &D_808021E8_chfactorytwinklies,
                                         (u32) func_808018A0_chfactorytwinklies,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x3F800000,
                                         0x0,
                                         0x6012C,
                                         (u32) func_80801D58_chfactorytwinklies,
                                         (u32) func_80108ED0,
                                         0x280000,
                                         (u32) func_8080171C_chfactorytwinklies,
                                         (u32) func_80107C2C,
                                         -0x7FFFEFFF,
                                         (u32) func_80801D94_chfactorytwinklies,
                                         0x0};
int D_80802380_chfactorytwinklies[18] = {0x1AB0445,
                                         0x7C70001,
                                         (u32) &D_808021E8_chfactorytwinklies,
                                         (u32) func_808018A0_chfactorytwinklies,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x3F800000,
                                         0x0,
                                         0x6012C,
                                         (u32) func_80801D58_chfactorytwinklies,
                                         (u32) func_80108ED0,
                                         0x280000,
                                         (u32) func_8080171C_chfactorytwinklies,
                                         (u32) func_80107C2C,
                                         -0x7FFFEFFF,
                                         (u32) func_80801D94_chfactorytwinklies,
                                         0x0};
u8 D_808023C8_chfactorytwinklies[36] = {
    0x0, 0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_808023EC_chfactorytwinklies[20] = {0x0, 0x13, 0x6, 0x1D, 0x0, 0xD,  0x1, 0x66, 0x1, 0x80,
                                        0x0, 0x1,  0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0,  0x0, 0x0};
u8 D_80802400_chfactorytwinklies[20] = {0x0, 0x13, 0x4, 0x3A, 0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,
                                        0x0, 0x1,  0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0,  0x0, 0x0};
u8 D_80802414_chfactorytwinklies[20] = {0x0, 0x13, 0x3, 0xF0, 0x0, 0xD,  0x1, 0x33, 0x1, 0x4C,
                                        0x0, 0x1,  0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0,  0x0, 0x0};
u8 D_80802428_chfactorytwinklies[20] = {0x0, 0x13, 0x6, 0x1E, 0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,
                                        0x0, 0x1,  0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0,  0x0, 0x0};
u8 D_8080243C_chfactorytwinklies[44] = {
    0x0, 0x16, 0x12, 0x0, 0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0x2B, 0x0,  0xC0, 0x1,
    0x0, 0x0,  0x22, 0x0, 0x4C, 0x0,  0x59, 0x0,  0x26, 0x0,  0x33, 0x0,  0x2D, 0x1,  0x90,
    0x2, 0x58, 0x0,  0xD, 0x0,  0x14, 0x0,  0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0,  0x0};
u8 D_80802468_chfactorytwinklies[16] = {0x0, 0x13, 0x4, 0xFC, 0x0, 0x2, 0x0, 0x18,
                                        0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
s16 D_80802478_chfactorytwinklies[4] = {0x9E0, 0x9E8, 0x9E4, 0x0};
