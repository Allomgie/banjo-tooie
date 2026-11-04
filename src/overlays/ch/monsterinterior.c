#include "common.h"

extern void *D_80801E80_chmonsterinterior;
extern void *D_80801EC8_chmonsterinterior;
extern int D_80801F10_chmonsterinterior[];
extern s32 D_80801F58_chmonsterinterior[];
extern int D_80801FA0_chmonsterinterior[];
extern void *func_80100094(Actor *, u32);
typedef union {
    s32 value;
    void *ptr;
} MonsterEvent60;
extern s32 func_800D9078();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80105138(Actor *, f32 *, f32, f32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct {
    u8 pad_0[0x70];
    u8 unk_70 : 7;
    u8 unk_71 : 1;
} MonsterFlags61;
extern u8 D_80801FE8_chmonsterinterior[];
extern u8 D_80801FF0_chmonsterinterior[];
extern u32 func_800FDC28(u32);
extern void func_800FC6B0(u32);
extern void _subaddiemulti_entrypoint_3();
extern void _sumultiscore_entrypoint_3();
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern u8 D_80801E58_chmonsterinterior[];
extern u8 D_8080208C_chmonsterinterior[];
extern u8 D_80801E50_chmonsterinterior[];
extern u8 D_8080207C_chmonsterinterior[];
extern u8 D_80802044_chmonsterinterior[];
extern f32 func_800DC178(f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void _susubgame_entrypoint_5();
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800F7C0C(s32, s32, f32);
extern void func_800F8300(s32, s32, f32 *);
extern f32 func_800DC0C0(void);
extern s32 func_800D9154(f32 *, f32);
extern s32 _bsfirstp_entrypoint_18;
extern void _subaddiemulti_entrypoint_2();
extern void func_80101FDC();
extern s32 _gcstatusDll_entrypoint_11(void);
extern s32 func_800D3948(void);
extern void func_800F7B9C(s32, s32);
extern void func_800CE8D8(s32, f32, s32);
extern void func_800CE88C(s32, s32);
extern void _sumultiscore_entrypoint_6();
extern u8 D_8080201C_chmonsterinterior[];
extern void func_8010A3E8(Actor *, f32);
extern void func_80102FDC(Actor *, f32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern void _subaddiefade_entrypoint_3();
extern u8 D_80802030_chmonsterinterior[];
extern f32 func_800D8FF8(void);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_8010C93C(Actor *, f32 *, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 player_controlled : 1;
    u32 pad_2 : 29;
} MonsterControlledFlag1121;
void func_80800BC8_chmonsterinterior();
void func_80801114_chmonsterinterior();
s32 func_80801180_chmonsterinterior();
void func_80801930_chmonsterinterior();
void func_8080068C_chmonsterinterior();
void func_8080078C_chmonsterinterior();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080003C_chmonsterinterior(),
    func_808000BC_chmonsterinterior();

int chmonsterinterior_entrypoint_0()
{
    return &D_80801E80_chmonsterinterior;
}

int chmonsterinterior_entrypoint_1()
{
    return &D_80801EC8_chmonsterinterior;
}

int chmonsterinterior_entrypoint_2()
{
    return &D_80801F10_chmonsterinterior;
}

int chmonsterinterior_entrypoint_3()
{
    return D_80801F58_chmonsterinterior;
}

int chmonsterinterior_entrypoint_4()
{
    return (int) &D_80801FA0_chmonsterinterior;
}

void func_8080003C_chmonsterinterior(actor) Actor *actor;
{
    u8 *data;
    data = func_80100094(actor, 0);
    if (!func_800F6438(func_800F54E4())) {
        func_800FFAB0(actor);
    } else {
        *(s32 *) data = 0;
        _susubgame_entrypoint_0(actor, data + 0x10, 0);
        _susubgame_entrypoint_11(0);
        actor->unk6C_0 = 0;
    }
}

s32 func_80800C38_chmonsterinterior();

void func_808000BC_chmonsterinterior(actor) Actor *actor;
{
    u8 *data;
    void *player;
    f32 roll;
    s32 size;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 3:
            player = func_800F54E4();
            func_800D2498(0xF7, *(s32 *) data, 0);
            if (func_800CEAD0(actor->unk6C_0)) {
                *(s32 *) (data + 8) = func_80800C38_chmonsterinterior(actor, data + 0xC);
                func_800F8300(player, 2, 0);
                func_800F7C0C(player, 0x5F, 0);
                func_80101FDC(actor, 4);
                return;
            }
            if (func_800D9154(&actor->unk58, func_800DC178(0.5f, 1.0f))) {
                roll = func_800DC0C0();
                if (roll < 0.166666f) {
                    size = 0;
                } else if (roll < 0.5f) {
                    size = 1;
                } else {
                    size = 2;
                }
                func_80108B04(actor, size);
            }
        case 1:
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(actor, data + 0x10, 5, 1, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, *(s32 *) (data + 8),
                                              *(s32 *) (data + 0xC), NULL, 0xB3);
                func_80101FDC(actor, 5);
            }
            break;
        case 7:
            if (func_800D0B68(0x2E, 1)) {
                func_800F8300(func_800F54E4(), 2, 0);
                *(s32 *) (data + 8) = 0xCEB;
                *(s32 *) (data + 0xC) = 0x46;
                func_80101FDC(actor, 4);
            }
    }
}

void func_80800A44_chmonsterinterior();

s32 func_808009C0_chmonsterinterior();

s32 func_808002D4_chmonsterinterior(u8 *actor, s32 event, s32 arg)
{
    u8 *data;
    s32 player;
    s32 dialog_id;

    data = func_80100094(actor, 0);
    switch (event) {
        case 0x2E:
            func_8080078C_chmonsterinterior(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x30:
            return func_808009C0_chmonsterinterior(actor, ((s16 *) &arg)[0],
                                                   ((s16 *) &arg)[1]);
        case 0x3D:
            func_80800A44_chmonsterinterior(actor, arg);
            break;
        case 0xB:
            if (arg == 6) {
                _susubgame_entrypoint_4(actor, data + 0x10);
                func_800F7B9C(func_800F54E4(), 0x62);
                func_800F82D4(func_800F54E4(), 0);
                func_80101FDC(actor, 7);
                return 4;
            }
            return 3;
        case 0x49:
            player = func_800F54E4();
            if (((u32) *(u16 *) (actor + 0x72) >> 10) != 1) {
                return 0;
            }
            if (_glcutDll_entrypoint_20() != 0) {
                func_800FFAB0(actor);
                return 0;
            }
            if (func_800DA9E4(0x370, 1) == 0) {
                func_800F49D4(player, &_bsfirstp_entrypoint_18, 0);
                _susubgame_entrypoint_6(actor, data + 0x10, 0, 0x20, 0);
                _chintrotext_entrypoint_2(1);
            } else {
                func_800F49D4(player, 0, 0);
                func_800F7B9C(player, 0x8F);
                func_800F7B9C(player, 0x63);
                func_800F7C58(player, 0x61, 0);
                _susubgame_entrypoint_5(actor, data + 0x10, 5, 1, 0);
                _subaddiedialog_entrypoint_11(*(s32 *) actor, 0xCEC, 0x46, 0, 0xB3);
                func_800F82D4(func_800F54E4(), 2);
            }
            func_80101FDC(actor, 2);
            break;
        case 0x77:
            if (func_800D395C() != 0) {
                dialog_id = 0x181A;
            } else {
                dialog_id = 0x17F2;
            }
            _subaddiedialog_entrypoint_11(*(s32 *) actor, dialog_id, 0x46, 0, 0xB3);
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(actor, data + 0x10, arg & 0xFFFF,
                                           (u32) (arg & 0xFFFF0000) >> 0x10);
        case 0x59:
            dialog_id = arg;
            switch (dialog_id) {
                case 0xCEC:
                    func_8080068C_chmonsterinterior(actor, dialog_id);
                    _susubgame_entrypoint_4(actor, data + 0x10);
                    break;
                case 0xCEB:
                    _susubgame_entrypoint_4(actor, data + 0x10);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

int func_8080060C_chmonsterinterior(actor)
Actor *actor;
{
    s32 data;
    data = func_80100094(actor, 0);
    if (func_800CEAA8(*(s32 *) ((char *) actor + 0x6C) & 0x1FF)) {
        func_800CE88C(*(s32 *) ((char *) actor + 0x6C) & 0x1FF, 0);
    }
    if (_susubgame_entrypoint_2(actor, data + 0x10)) {
        _susubgame_entrypoint_4(actor, data + 0x10);
    }
}

void func_8080068C_chmonsterinterior(actor) u8 *actor;
{
    s32 i;
    s16 time_limit;

    _subaddiemulti_entrypoint_2();
    func_80101FDC(actor, 3);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        if (func_800D3948() == 0) {
            func_800F7B9C(i, 0x73);
            func_800F7C0C(i, 0x5F, -1.0f);
        } else {
            func_800F7C0C(i, 0x5F, -1.0f);
        }
    }
    time_limit = 60;
    func_800CE8D8(*(s32 *) (actor + 0x6C) & 0x1FF, time_limit, time_limit);
    func_800CE88C(*(s32 *) (actor + 0x6C) & 0x1FF, 1);
    *(f32 *) (actor + 0x58) = 0.01f;
    func_800FDC28(0xC);
}

void func_8080078C_chmonsterinterior(actor, dialog_id, answer) Actor *actor;
s32 dialog_id;
s32 answer;
{
    u8 *data;
    data = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x17F2:
        case 0x181A:
            if (answer > 0) {
                _susubgame_entrypoint_6(actor, data + 0x10, 3, 0x20, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17F3, 0x44, 0, 0xB3);
                func_80108B04(actor, 0);
            } else
                _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0xB3);
            _gcfrontend_entrypoint_9(0x6B);
            break;
        case 0x17F3:
            _susubgame_entrypoint_5(actor, data + 0x10, 5, 1, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0xB3);
            break;
        case 0xCEB:
            func_800F82D4(func_800F54E4(), 0);
            func_80101FDC(actor, 6);
            if (func_800D395C()) {
                if (answer > 0)
                    _gcfrontend_entrypoint_11();
                else
                    _gcfrontend_entrypoint_10();
            } else if (answer > 0)
                _gcgoto_entrypoint_1(0x123, 1);
            else
                func_80108BD4(actor, 0xCEB);
            break;
        case 0xCEC:
            func_80108BD4(actor, 0xCEC);
            break;
        case 0x17FA:
            _susubgame_entrypoint_6(actor, data + 0x10, 6, 0x20, 0);
            func_800D1000(0x2E, 1, 0, 1, 0);
            break;
        case 0x17F7:
        case 0x1807:
        case 0x1808:
        case 0x1809:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x46, 0, 0xB3);
    }
}

s32 func_808009C0_chmonsterinterior(Actor *actor, s32 request, MonsterEvent60 arg)
{
    s32 *data;
    s32 dialog_id;

    // Matching: copy of the parameter needed for the match.
    dialog_id = request;
    data = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x17F7:
            return *data;
        case 0x17F3:
            return 0x4B;
        case 0x1808:
        case 0x181A:
            return func_800D211C(0x85);
    }
    return 0;
}

// Spawns a target (ulcer) of the given size.
void func_80800A44_chmonsterinterior(Actor *controller, s32 size)
{
    Actor *target;
    f32 pos[3];
    f32 ground_y;
    s32 unk_0;
    s32 is_multi;
    u8 *data;
    if (size == 0 || size == 1 || size == 2) {
        is_multi = func_800D3948();
        data = func_80100094(controller, 0);
        if (_susubgame_entrypoint_2(controller, data + 0x10))
            func_800EE7F8(pos, controller->position);
        else
            func_800CD08C((*(u32 *) ((u8 *) controller + 0x70) >> 25) - 1, pos);
        pos[1] = controller->position[1];
        func_80105138(controller, pos, 200.0f, -200.0f, &ground_y);
        pos[1] = ground_y;
        unk_0 = func_800DC128(0, 0x167);
        target = func_80108528(size + 0x452, pos, unk_0, &controller);
        target->unk3C = controller->unk0;
        target->unk64_20 = is_multi;
        target->actorData[5] = size;
        target->unk6C_0 = controller->unk6C_0;
        target->unk64_19 = _susubgame_entrypoint_2(controller, data + 0x10);
        ((MonsterFlags61 *) target)->unk_71 = !is_multi;
        func_80800BC8_chmonsterinterior(target, size);
    }
}

void func_80800BC8_chmonsterinterior(actor, size) u8 **actor;
s32 size;
{
    if (func_800D3948() != 0) {
        func_801032B0(actor, *(u16 *) &D_80801FF0_chmonsterinterior[size * 2],
                      *(u16 *) ((char *) *actor + 0x16));
        return;
    }

    func_801032B0(actor, *(u16 *) &D_80801FE8_chmonsterinterior[size * 2],
                  *(u16 *) ((char *) *actor + 0x16));
}

// Picks the end-of-game dialog and records the score.
s32 func_80800C38_chmonsterinterior(Actor *actor, s32 *out_arg)
{
    s32 *data;
    s32 score;
    s32 dialog_id;
    s32 new_best;
    s32 reached_75;
    u32 jiggy_earned;
    s32 jiggy_collected;
    s32 is_multi;
    s32 record_result;

    data = func_80100094(actor, 0);
    score = data[0];
    jiggy_collected = func_800D0A9C(0x2E, 1);
    is_multi = func_800D395C();
    record_result = func_800D2054(0, 0x85, score);
    new_best = record_result == 1 && (jiggy_collected || is_multi);
    reached_75 = score >= 75;
    jiggy_earned = reached_75 && !jiggy_collected && !is_multi;
    func_800FDC28(0);
    func_800FC6B0((jiggy_earned || new_best) ? 0x16 : 0x17);
    *out_arg = 6;

    if (jiggy_earned) {
        dialog_id = 0x17FA;
    } else if (new_best) {
        dialog_id = 0x17F7;

    } else if (!func_800D395C()) {
        if (jiggy_collected) {
            if (record_result == 0)
                dialog_id = 0x1809;
            else
                dialog_id = 0x1808;
        } else {
            dialog_id = 0x1807;
        }
    } else {
        dialog_id = 0xCEB;
        *out_arg = 0x46;
    }
    return dialog_id;
}

void func_80800DA4_chmonsterinterior(actor) Actor *actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    _subaddiemulti_entrypoint_3(10);
    actor->unk6C_0 = 5;
    _sumultiscore_entrypoint_3(data + 0x28);
    _sumultiscore_entrypoint_4(data + 0x28, 8, 0, 1);
}

void func_808011BC_chmonsterinterior();

void func_80800E0C_chmonsterinterior(Actor *actor)
{
    u8 *data;
    s32 unk_0;
    s32 size;
    s32 state;
    s32 count;
    f32 roll;
    f32 interval;

    data = func_80100094(actor, 0);
    _sumultiscore_entrypoint_6(data + 0x28);
    state = actor->unk70_10;
    switch (state) {
        case 1:
            if (!func_800C954C() && !func_800DA298(0x6AD)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0xCEC, 7, 0, 0xB3);
                func_80101FDC(actor, 2);
            }
            break;
        case 3:
            if (func_800CEAD0(actor->unk6C_0)) {
                func_808011BC_chmonsterinterior(actor);
            } else {
                count = _subaddiefind_entrypoint_9(0x453);
                state = _subaddiefind_entrypoint_9(0x452);

                // Matching: empty block steers IDO's register allocation.
                if (1) {
                }
                if (_subaddiefind_entrypoint_9(0x454) + state + count < 5) {
                    interval = func_800DC178(0.5f, 1.0f);
                    if (func_800D9154(&actor->unk58,
                                      interval / (f32) _gcstatusDll_entrypoint_11())) {
                        roll = func_800DC0C0();
                        if (roll < 0.25f) {
                            size = 0;
                        } else if (roll < 0.6f) {
                            size = 1;
                        } else {
                            size = 2;
                        }
                        func_80108B04(actor, size);
                    }
                }
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(actor, data + 0x10, 5, 1, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, *(s32 *) (data + 8),
                                              *(s32 *) (data + 0xC), 0, 0xB3);
                func_80101FDC(actor, 5);
            }
    }
}

int func_8080101C_chmonsterinterior(actor, player)
s32 actor;
s32 player;
{
    u8 *data;
    data = func_80100094(actor, 0);
    _sumultiscore_entrypoint_12(data + 0x28, player, 1);
}

s32 func_80801050_chmonsterinterior(actor, event, arg)
Actor *actor;
s32 event;
s32 arg;
{
    switch (event) {
        case 0x2E:
            func_80801114_chmonsterinterior(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x30:
            return func_80801180_chmonsterinterior(actor, ((s16 *) &arg)[0],
                                                   ((s16 *) &arg)[1]);
        case 0x3D:
            func_80800A44_chmonsterinterior(actor, arg);
            break;
        case 0x95:
            _subaddiemulti_entrypoint_1(0, 0);
            func_800BF544(0, 0, 0);
            func_800BF544(1, 0, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801114_chmonsterinterior(actor, dialog_id, arg) s32 actor;
s32 dialog_id;
s32 arg;
{
    switch (dialog_id) {
        case 0xCEC:
            func_8080068C_chmonsterinterior(actor);
            break;
        case 0x17F8:
        case 0x17F9:
            _subaddiemulti_entrypoint_2(actor);
            func_80101FDC(actor, 6);
            _gcfrontend_entrypoint_10();
    }
}

s32 func_80801180_chmonsterinterior(actor, dialog_id, arg)
Actor *actor;
s32 dialog_id;
s32 arg;
{
    s32 query;
    // Matching: extra temporary needed for the match.
    query = dialog_id;
    if (query == 0x17F8) {
        s32 data;
        data = func_80100094(actor, 0);
        return (*((s32 *) (((char *) data) + 4))) + 1;
    }
    return 0;
}

// Multiplayer end of game: ranks the scores and picks the winner dialog.
void func_808011BC_chmonsterinterior(Actor *actor)
{
    u8 *data;
    s32 scores[8];
    s32 best;
    s32 i;
    s32 j;
    s32 k;
    s32 tmp;
    s32 dialog_id;

    data = func_80100094(actor, 0);
    best = -1;
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        scores[i] = _sumultiscore_entrypoint_8(data + 0x28, i, 8);
        if (best < scores[i]) {
            best = scores[i];
        }
        func_800AA20C(i, scores[i]);
    }
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        if (best == scores[i]) {
            _sumultiscore_entrypoint_11(data + 0x28, i, 8, 3.0f);
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
        for (k = 0; _sumultiscore_entrypoint_8(data + 0x28, k, 8) != scores[0];
             k++) {
        }
        *(s32 *) (data + 4) = k;
        dialog_id = 0x17F8;
    } else {
        dialog_id = 0x17F9;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    func_80101FDC(actor, 4);
    *(s32 *) (data + 8) = dialog_id;
    *(s32 *) (data + 0xC) = 6;
}

f32 func_80801B7C_chmonsterinterior();

f32 func_80801ADC_chmonsterinterior();

void func_808013D0_chmonsterinterior(Actor *actor)
{
    u8 *data;
    s32 size;
    data = func_80100094(actor, 0);
    size = actor->actorData[5];
    func_8010A3E8(actor, 0.3f);
    *(s32 *) (data + 0xC) = 0;
    actor->position[1] -= 250.0f;
    *(f32 *) ((u8 *) actor + 0x28) = 0.6f;
    *(f32 *) ((u8 *) actor + 0x30) =
        func_80801ADC_chmonsterinterior(size, (f32 *) (data + 0x28));
    actor->unk58 = func_80801B7C_chmonsterinterior(size);
    func_80102FDC(actor, func_800DC178(0.6f, 0.8f));
    _subaddieDll_entrypoint_1(actor);
    _subaddierouteDll_entrypoint_3(actor, data, actor->position);
    _subaddierouteDll_entrypoint_1(actor);
    if (actor->unk64_19) {
        actor->unk64_24 = 0;
        actor->unk58 = 5.5f;
    }
    func_8010D930(4, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                  D_8080201C_chmonsterinterior);
}

s32 func_80801C78_chmonsterinterior();

s32 func_80801C1C_chmonsterinterior();

void func_808014E8_chmonsterinterior(Actor *actor)
{
    u8 *data;
    f32 delta_time;
    f32 unk_0;
    f32 *unk_1;

    data = func_80100094(actor, 0);
    delta_time = func_800D8FF8();
    if (actor->unk70_10 != 4 && func_800CEAD0(actor->unk6C_0) && !actor->unk64_19) {
        func_8010A570(actor);
        func_80101FDC(actor, 4);
        _subaddiefade_entrypoint_3(actor);
    }
    switch (actor->unk70_10) {
        case 1:
            if (func_80801C1C_chmonsterinterior(actor)) {
                func_80101FDC(actor, 2);
            }
            break;
        case 2:
            func_8010C93C(actor, actor->position, 1.0f);
            unk_1 = &actor->unk54;
            if (((MonsterControlledFlag1121 *) actor)->player_controlled) {
                unk_0 = _subaddiejoy_entrypoint_9(actor, unk_1, 3);
                ((f32 *) actor->actorData)[3] = *(f32 *) (data + 0x28) * 1.4f;
                func_80102BF8(actor, 0.2f, 8.0f, 600.0f);
                func_8010C3A8(actor, 0x200025, unk_0);

            } else {
                if (_subaddierouteDll_entrypoint_4(actor)) {
                    _subaddierouteDll_entrypoint_7(actor, data, actor->rotation[1],
                                                   actor->unk54, 400.0f, 0x4802);
                    *(s32 *) (data + 0xC) = *(u16 *) (data + 6);
                }

                _subaddierouteDll_entrypoint_6(actor, data, *(s32 *) (data + 0xC), 0x3F,
                                               0.4f, 20, 40);
                _subaddierouteDll_entrypoint_5(actor, data, *(s32 *) (data + 0xC), 0.2f,
                                               4.0f, 200.0f);
                ((f32 *) actor->actorData)[3] =
                    func_800F15F8(((f32 *) actor->actorData)[3], ((f32 *) actor->actorData)[6],
                                  delta_time * 800.0f);

                if (!actor->unk64_19) {
                    func_8010B990(actor, 0x325);
                }
            }
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 3);
                ((f32 *) actor->actorData)[4] = 0.6f;
                actor->unk64_24 = 0;
            }
            break;
        case 3:
            if (!actor->unk64_19 &&
                func_800F10B4(((f32 *) actor->actorData)[4], 0.0f, 0.6f, 1.0f, 0.0f) > 0.3f) {
                func_8010D930(5, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                              D_80802030_chmonsterinterior);
                actor->unk64_19 = 1;
            }
            if (func_80801C78_chmonsterinterior(actor)) {
                func_800FFAB0(actor);
            }
        case 4:
            break;
    }
}

void func_808017E8_chmonsterinterior(s32 arg0)
{
}

s32 func_808017F0_chmonsterinterior(Actor *actor, s32 event, MonsterEvent60 arg)
{
    void *data;

    switch (event) {
        case 0x40:
            func_80801930_chmonsterinterior(actor, arg.ptr);
            break;
        case 0x99:
            func_80101074(actor->unk64_20 ? 0 : D_80801E58_chmonsterinterior);
            break;
        case 0x1F:
            data = *(void **) &arg;
            if (actor->unk64_20)
                func_8010DD20(actor, actor->unk6C_9 - 0x44B, data);
            else
                func_801015D0(actor);
            break;
        case 0x29:
            if (actor->unk64_20)
                func_8010DC50(actor->unk6C_9 - 0x44B);
            break;
        case 0x2A:
            if (actor->unk64_20)
                func_8010DCB4(actor->unk6C_9 - 0x44B);
            break;
        default:
            return 0;
    }
    return 1;
}

// Hit handler of a target: plays effects, adds points, removes the target.
void func_80801930_chmonsterinterior(target, shooter) s32 target;
Actor *shooter;
{
    s32 controller;
    s32 *score;
    s32 unk_0;
    s32 unk_1;
    s32 player;
    f32 hit_pos[3];
    f32 score_pos[3];

    controller = func_80106790(*(s32 **) ((char *) target + 0x3C));
    score = func_80100094(controller, 0);
    if (func_800D3948() != 0) {
        unk_0 = 2;
    } else {
        unk_0 = func_800DC128(6, 8);
    }
    unk_1 = func_800B53A4(unk_0);
    player = _subaddiemulti_entrypoint_5(shooter);
    func_80103DFC(target, hit_pos);
    func_800BABB8(unk_1, hit_pos, hit_pos, 0x3F800000, D_80802044_chmonsterinterior);
    func_800BA670(unk_1, *(s16 *) ((char *) D_8080208C_chmonsterinterior +
                                     (*(s32 *) ((char *) target + 0x2C)) * 2));
    func_800BA22C(unk_1, unk_0);
    if (func_800D3948() != 0) {
        _sumultiscore_entrypoint_7(score + 0xA, player, 8,
                                   *(s16 *) ((char *) D_80801E50_chmonsterinterior +
                                             (*(s32 *) ((char *) target + 0x2C)) * 2));
    } else {
        *score += *(s16 *) ((char *) D_80801E50_chmonsterinterior +
                              (*(s32 *) ((char *) target + 0x2C)) * 2);
    }
    func_8010D930(1, (*(s32 *) ((char *) target + 0x70)) & 1, hit_pos,
                  D_8080207C_chmonsterinterior);
    func_80103DFC(target, score_pos);
    _chscorepoints_entrypoint_2(
        *(s16 *) ((char *) D_80801E50_chmonsterinterior + (*(s32 *) ((char *) target + 0x2C)) * 2),
        player, score_pos, 1);
    func_800FFAB0(target);
    if ((*(u16 *) ((char *) shooter + 0x18)) & 1) {
        func_8010114C(shooter, 0x98, 0);
    }
}

f32 func_80801ADC_chmonsterinterior(s32 size, f32 *out_value)
{
    switch (size) {
        case 0:
            *out_value = 600.0f;
            return func_800DC178(500.0f, 600.0f);
        case 1:
            *out_value = 450.0f;
            return func_800DC178(350.0f, 450.0f);
        case 2:
            *out_value = 300.0f;
            return func_800DC178(200.0f, 300.0f);
        default:
            return -1.0f;
    }
}

f32 func_80801B7C_chmonsterinterior(s32 size)
{
    switch (size) {
        case 0:
            return func_800DC178(2.5f, 3.0f);
        case 1:
            return func_800DC178(3.0f, 3.5f);
        case 2:
            return func_800DC178(3.5f, 4.5f);
        default:
            return -1.0f;
    }
}

s32 func_80801C1C_chmonsterinterior(u8 *data)
{
    s32 done = func_800D9078(data + 0x28);
    *(f32 *) (data + 8) = func_800F12D4(*(f32 *) (data + 0x28), 0.0f, 0.6f, 0.0f, -250.0f);
    return done;
}

s32 func_80801C78_chmonsterinterior(u8 *data)
{
    s32 done = func_800D9078(data + 0x28);
    *(f32 *) (data + 8) = func_800F12D4(*(f32 *) (data + 0x28), 0.0f, 0.6f, -250.0f, 0.0f);
    return done;
}

// TU-NOTE: the overlay .data is defined here in C. The tables point to functions of this file, and IDO schedules some of them differently unless they are in the same unit.
extern void func_801018A4();
extern void func_80108ED0();
u8 D_80801E50_chmonsterinterior[8] = {0x0, 0x3, 0x0, 0x2, 0x0, 0x1, 0x0, 0x0};
u8 D_80801E58_chmonsterinterior[40] = {0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80,
                                       0x0, 0x0,  0x3,  0x61, 0x0,  0x4A, 0x40, 0x80, 0x0,  0x0,
                                       0x3, 0x62, 0x0,  0x9,  0x3F, 0x80, 0x0,  0x0,  0x3,  0x61,
                                       0x0, 0x92, 0x3F, 0x80, 0x0,  0x0,  0x3,  0x61, 0x0,  0x9};
void *D_80801E80_chmonsterinterior = (void *) 0x01580451;
static u32 D_80801E80_chmonsterinterior_rest[17] = {0x1,
                                                    0x0,
                                                    (u32) func_808000BC_chmonsterinterior,
                                                    (u32) func_80105834,
                                                    (u32) func_80101870,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x1,
                                                    (u32) func_8080060C_chmonsterinterior,
                                                    0x0,
                                                    0x5440000,
                                                    (u32) func_8080003C_chmonsterinterior,
                                                    (u32) func_80107C2C,
                                                    0x80000602,
                                                    (u32) func_808002D4_chmonsterinterior,
                                                    0x0};
void *D_80801EC8_chmonsterinterior = (void *) 0x01580455;
static u32 D_80801EC8_chmonsterinterior_rest[17] = {0xFFFF0001,
                                                    0x0,
                                                    (u32) func_80800E0C_chmonsterinterior,
                                                    (u32) func_80105834,
                                                    (u32) func_8080101C_chmonsterinterior,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x400401,
                                                    (u32) func_8080060C_chmonsterinterior,
                                                    0x0,
                                                    0x5440000,
                                                    (u32) func_80800DA4_chmonsterinterior,
                                                    (u32) func_80107C2C,
                                                    0x80000402,
                                                    (u32) func_80801050_chmonsterinterior,
                                                    0x0};
int D_80801F10_chmonsterinterior[18] = {0x2A60452,
                                        -0xFFFF,
                                        0x0,
                                        (u32) func_808014E8_chmonsterinterior,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x124,
                                        (u32) func_808017E8_chmonsterinterior,
                                        (u32) func_80108ED0,
                                        0x2C0000,
                                        (u32) func_808013D0_chmonsterinterior,
                                        (u32) func_80107C2C,
                                        -0x7FDBEFFF,
                                        (u32) func_808017F0_chmonsterinterior,
                                        0x0};
s32 D_80801F58_chmonsterinterior[18] = {0x2A60453,
                                        -0xFFFF,
                                        0x0,
                                        (u32) func_808014E8_chmonsterinterior,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x124,
                                        (u32) func_808017E8_chmonsterinterior,
                                        (u32) func_80108ED0,
                                        0x2C0000,
                                        (u32) func_808013D0_chmonsterinterior,
                                        (u32) func_80107C2C,
                                        -0x7FDBEFFF,
                                        (u32) func_808017F0_chmonsterinterior,
                                        0x0};
int D_80801FA0_chmonsterinterior[18] = {0x2A60454,
                                        -0xFFFF,
                                        0x0,
                                        (u32) func_808014E8_chmonsterinterior,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x124,
                                        (u32) func_808017E8_chmonsterinterior,
                                        (u32) func_80108ED0,
                                        0x2C0000,
                                        (u32) func_808013D0_chmonsterinterior,
                                        (u32) func_80107C2C,
                                        -0x7FDBEFFF,
                                        (u32) func_808017F0_chmonsterinterior,
                                        0x0};
u8 D_80801FE8_chmonsterinterior[8] = {0x8, 0x6, 0x8, 0x4, 0x8, 0x5, 0x0, 0x0};
u8 D_80801FF0_chmonsterinterior[44] = {0x9, 0x9F, 0x9,  0x9E, 0x9, 0x9D, 0x0, 0x0, 0x0,  0x0, 0x0,
                                       0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0xFF, 0x0, 0x0,
                                       0x0, 0x0,  0x0,  0x0,  0x0, 0xFF, 0x0, 0x0, 0x0,  0x0, 0x0,
                                       0x0, 0x0,  0xFF, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0,  0x0, 0x0};
u8 D_8080201C_chmonsterinterior[20] = {0x0, 0x13, 0x4, 0xB2, 0x0, 0xD,  0x0, 0xA6, 0x0, 0xC0,
                                       0x0, 0x1,  0x3, 0x20, 0x8, 0x98, 0x0, 0x0,  0x0, 0x0};
u8 D_80802030_chmonsterinterior[20] = {0x0, 0x13, 0x6, 0xF,  0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,
                                       0x0, 0x1,  0x3, 0x20, 0x8, 0x98, 0x0, 0x0,  0x0, 0x0};
u8 D_80802044_chmonsterinterior[56] = {
    0x0, 0x16, 0x12, 0x0,  0x0, 0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0x2B, 0x0, 0xB3,
    0x0, 0xCC, 0x0,  0x22, 0x0, 0xCC, 0x1,  0x33, 0x0,  0x80, 0x0,  0x99, 0x0, 0x2D,
    0x2, 0x58, 0x3,  0x20, 0x0, 0x27, 0xFF, 0x38, 0xFF, 0x38, 0x0,  0xC8, 0x0, 0xC8,
    0x0, 0xE,  0x0,  0x19, 0x0, 0x32, 0x0,  0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x0};
u8 D_8080207C_chmonsterinterior[16] = {0x0, 0x13, 0x4, 0x1F, 0x0, 0x18, 0x0, 0xD,
                                       0x0, 0xF3, 0x1, 0xC,  0x0, 0x0,  0x0, 0x0};
u8 D_8080208C_chmonsterinterior[20] = {0x9, 0x22, 0x9, 0x21, 0x9, 0x20, 0x0, 0x0, 0x0, 0x0,
                                       0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
