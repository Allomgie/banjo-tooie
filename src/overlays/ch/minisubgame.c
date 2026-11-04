// Probably the mini-sub challenge in Jolly Roger's Lagoon: a host starts a 60-second game in
// which the sub shoots homing mines for points; 60 points earns the jiggy.
#include "common.h"

extern int D_80801424_chminisubgame[];
extern int D_8080146C_chminisubgame[];
extern void *func_80100094(Actor *, u32);
extern void _susubgame_entrypoint_11(s32);
extern s32 _susubgame_entrypoint_2(Actor *, void *);
extern void _susubgame_entrypoint_4(Actor *, void *);
typedef struct {
    u16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
} MinisubgameRecord;
typedef struct {
    f32 positions[60][3];
    u8 states[60];
    u8 sub_data[1];
} MinisubgameData;
extern MinisubgameRecord D_80801400_chminisubgame[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800E3980(f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
extern void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
extern s32 _susubgame_entrypoint_3(Actor *, void *, s32, s32);
extern void func_8008FE68(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct MiniSubGameData {
    f32 positions[60][3];
    u8 states[60];
} MiniSubGameData;
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
typedef struct {
    u8 pad[0x18];
    u16 hi : 15;
    u16 b0 : 1;
} MS18;
extern s32 _subaddiemulti_entrypoint_5(Actor *);
extern void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
extern void func_8010114C(Actor *, s32, s32);
extern void func_8010A570(Actor *);
extern s32 func_8010CC10(f32 *, s32);
extern void func_8010CCE0(void);
extern s32 func_8010CCEC(void);
extern void func_800F7A2C(s32, s32, f32 *);
extern s32 D_808014B4_chminisubgame[];
extern u8 D_80801578_chminisubgame[];
extern u8 D_80801534_chminisubgame[];
extern u8 D_808014F0_chminisubgame[];
typedef union {
    struct {
        s16 a;
        s16 b;
    } h;
    s32 w;
} MSPair;
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern void func_800CE8D8(s32, f32, s32);
s32 func_80801058_chminisubgame();
void func_80801248_chminisubgame();
void func_80800BA8_chminisubgame();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_80800EC8_chminisubgame();

int chminisubgame_entrypoint_0()
{
    return (int) &D_80801424_chminisubgame;
}

int chminisubgame_entrypoint_1()
{
    return (int) &D_8080146C_chminisubgame;
}

s32 B_80801590_chminisubgame;
u8 B_80801590_chminisubgame_tail[4];
u8 B_80801590_chminisubgame_tail1[232];

void func_80800018_chminisubgame(u8 *actor)
{
    s32 base;
    s32 *slot;
    s32 count;
    s32 i;
    s32 dst;

    base = func_80100094((Actor *) actor, 0);
    count = _gccubesearch_entrypoint_9(0x1C0, &B_80801590_chminisubgame, 0x3C);
    *(s32 *) ((s8 *) actor + 0x30) = count;
    i = 0;
    if (count > 0) {
        slot = &B_80801590_chminisubgame;
        dst = base;
        do {
            _gspropctrl_entrypoint_11(*slot, dst);
            i += 1;
            slot += 1;
            dst += 0xC;
        } while (i < *(s32 *) ((s8 *) actor + 0x30));
    }
    _susubgame_entrypoint_0(actor, base + 0x30C, 0);
    _susubgame_entrypoint_11(0);
}

s32 func_80800AAC_chminisubgame();

void func_808000C8_chminisubgame(Actor *actor)
{
    s32 dialog_id;
    s32 unk_0;
    s32 jingle;
    s32 unk_1;
    s32 base;
    s32 mine_idx;
    s32 variant;
    s32 unk_2;
    MSPair pair;
    s32 data;
    f32 roll;
    s32 score;

    switch ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) {
        case 2:
            func_800D24E8(0xFC, *(s32 *) ((u8 *) actor + 0x28), 0);
            if (func_800CEAD0(0) != 0) {
                unk_0 = 4;
                unk_1 = func_800D2054(0, 0x88, *(s32 *) ((u8 *) actor + 0x28));
                base = func_80100094(actor, 0);
                func_800BF99C(0, 0x5AA, 1);
                func_80090708(2);
                _susubgame_entrypoint_5(actor, base + 0x30C, 5, 1, 0);
                func_80101180(0x4AE, 0x3E, 0);
                if (func_800D395C() != 0) {
                    if (unk_1 == 1) {
                        dialog_id = 0x104A;
                        jingle = 0x16;
                    } else if (unk_1 == 0) {
                        dialog_id = 0x104B;
                        jingle = 0x17;
                    } else {
                        dialog_id = 0x104C;
                        jingle = 0x17;
                    }
                } else if (func_800D0A9C(0x1F, 1) == 0 &&
                           *(s32 *) ((u8 *) actor + 0x28) >= 0x3C) {
                    dialog_id = 0x1030;
                    unk_0 = 0x44;
                    jingle = 0x16;
                } else {
                    unk_0 = 6;
                    if (func_800D0A9C(0x1F, 1) == 0) {
                        score = *(s32 *) ((u8 *) actor + 0x28);
                        switch (score) {
                            case 0:
                                dialog_id = 0x1034;
                                jingle = 0x17;
                                break;
                            case 1:
                                dialog_id = 0x1046;
                                jingle = 0x17;
                                break;
                            default:
                                dialog_id = 0x1032;
                                jingle = 0x17;
                                break;
                        }
                    } else if (unk_1 == 1) {
                        dialog_id = 0x1031;
                        jingle = 0x16;
                    } else {
                        dialog_id = *(s32 *) ((u8 *) actor + 0x28) != 0 ? 0x1033 : 0x1034;
                        jingle = 0x17;
                    }
                }
                func_800FDC28(0, jingle);
                func_800FC6B0(jingle);
                _subaddiedialog_entrypoint_11(*(s32 *) actor, dialog_id, unk_0, 0, 0x22);
                func_80101FDC(actor, 3);
                return;
            }
        case 1:
            if (*(s32 *) ((u8 *) actor + 0x2C) < 0xF && func_800DC298(0.2f) != 0) {
                mine_idx = func_80800AAC_chminisubgame(actor);
                variant = 0;
                roll = func_800DC0C0();
                if (roll < 0.1666666f) {
                    variant = 2;
                } else if (roll < 0.5f) {
                    variant = 1;
                }
                if (mine_idx != -1) {
                    pair.h.a = variant;
                    pair.h.b = mine_idx;
                    func_80108B04(actor, pair.w);
                }
            }
            break;
        case 5:
            if (func_800D0B68(0x1F, 1) != 0 && func_800D90A4((u8 *) actor + 0x18) != 0) {
                data = func_80100094(actor, 0);
                func_80090708(2);
                _susubgame_entrypoint_5(actor, data + 0x30C, 5, 1, 0);
                _subaddiedialog_entrypoint_11(*(s32 *) actor, 0xCEB, 0x46, 0, 0x22);
                func_80101FDC(actor, 3);
            }
    }
}

void func_80800430_chminisubgame(Actor *actor)
{
    u8 *data = func_80100094(actor, 0);
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(actor, data + 0x30C)) {
        _susubgame_entrypoint_4(actor, data + 0x30C);
    }
}

s32 func_80800484_chminisubgame(Actor *actor, s32 msg, s32 arg)
{
    MinisubgameData *data;
    Actor *mine;
    s32 target_idx;
    s32 msg_arg;
    f32 spawn_pos[3];
    f32 unk_0[3];
    union {
        struct {
            s16 a;
            s16 b;
        } h;
        u32 w;
    } pair;
    MinisubgameRecord *rec;

    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x95:
            if (func_800D0A9C(0x1F, 1) && !func_800D0B68(0x1F, 1)) {
                func_80101FDC(actor, 5);
                *(f32 *) &actor->actorData[0] = 0.5f;
            } else {
                func_80090708(2);
                func_800DA544(0);
                if (func_800D395C()) {
                    _susubgame_entrypoint_5(actor, data->sub_data, 5, 1, 0);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1049, 6, 0, 0x22);
                } else if (func_800DA298(0x6E5)) {
                    _susubgame_entrypoint_5(actor, data->sub_data, 5, 1, 0);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x102D, 6, 0, 0x22);
                } else {
                    _susubgame_entrypoint_6(actor, data->sub_data, 5, 0x20, 0);
                    _subaddiedialog_entrypoint_11(
                        actor->unk0, !func_800D0A9C(0x1F, 1) ? 0x102C : 0x102D, 6, 0, 0x22);
                }
            }
            break;
        case 0x3D:
            target_idx = ((s16 *) &arg)[1];
            msg_arg = ((s16 *) &arg)[0];
            if (target_idx < 0) {
                func_800EE7F8(spawn_pos, actor->position);
            } else {
                func_800EE7F8(spawn_pos, data->positions[target_idx]);
                data->states[target_idx] = 1;
                actor->actorData[5]++;
            }
            mine = func_80108528(0x4AE, spawn_pos, 0, &actor);
            mine->unk3C = actor->unk0;
            if (target_idx >= 0) {
                func_800E3980(unk_0);
                mine->rotation[1] = func_80102D78(actor, unk_0);
            }
            mine->unk6C_0 = msg_arg;
            mine->actorData[7] = target_idx;
            rec = &D_80801400_chminisubgame[msg_arg];
            func_80103140(mine, rec->unk_0, 0);
            *(f32 *) &mine->actorData[3] = func_800DC178(rec->unk_2, rec->unk_4);
            mine->unk58 = func_800DC178(rec->unk_6, rec->unk_8);
            *(f32 *) &mine->actorData[5] = mine->unk58;
            *(f32 *) &mine->actorData[6] = mine->position[1];
            *(f32 *) &mine->actorData[4] = 0.0f;
            mine->unk50 = rec->unk_A;
            if (target_idx < 0) {
                actor->unk3C = mine->unk0;
            }
            if (target_idx >= 0 || mine->unk6C_0 == 2) {
                _subaddiefade_entrypoint_2(mine);
            }
            return 1;
        case 0x2E:
            func_80800BA8_chminisubgame(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x30: {
            msg_arg = ((s16 *) &arg)[0];
            switch (msg_arg) {
                case 0x1032:
                    return actor->actorData[4];
                case 0x102C:
                    return 60;
                case 0x1033:
                case 0x104C:
                    if (((s16 *) &arg)[1] == 0) {
                        return actor->actorData[4];
                    }
                default:
                    return func_800D211C(0x88, msg_arg);
            }
        }
        case 0x2F:
            pair.h.a = ((s16 *) &arg)[1] - 1;
            pair.h.b = -1;
            if (((s16 *) &arg)[1] == 3) {
                _susubgame_entrypoint_6(actor, data->sub_data, 9, 0xA0, 0);
            }
            func_80108B04(actor, pair.w);
            if (actor->unk3C != NULL) {
                func_8010114C(actor->unk3C, 0x3E, 0);
                actor->unk3C = NULL;
            }
            break;
        case 0xE:
            if (arg == 9 && actor->unk3C != NULL) {
                _capod_entrypoint_19(func_80106790(actor->unk3C)->position);
            }
            return 3;
        case 0xB:
            if (arg == 1) {
                func_80090708(0);
                _susubgame_entrypoint_4(actor, data->sub_data);
                func_80101FDC(actor, 5);
                *(f32 *) &actor->actorData[0] = 0.5f;
                return 4;
            }
            return 3;
        case 0x57:
            return _susubgame_entrypoint_3(actor, data->sub_data, arg & 0xFFFF,
                                           (u32) (arg & 0xFFFF0000) >> 16);
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            func_800BF99C(0, 0x5AA, 1);
            func_80101180(0x4AE, 0x3E, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x46, 0, 0x22);
            func_80101FDC(actor, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800A64_chminisubgame(void *actor, s32 slot)
{
    s32 data;
    data = func_80100094(actor, 0);
    ((s32 *) actor)[0x2C / 4]--;
    // Matching: empty statement needed for the match.
    ;
    *((data + (char *) slot) + 0x2D0) = 2;
}

s32 func_80800AAC_chminisubgame(Actor *actor)
{
    MiniSubGameData *data;
    f32 ref_pos[3];
    s32 i;
    s32 idx;

    data = func_80100094(actor, 0);
    func_8008FE68(ref_pos);
    for (i = 0; i < (s32) actor->actorData[6]; i++) {
        idx = func_800DC128(0, actor->actorData[6]);
        if (func_800EEAD4(data->positions[idx], ref_pos) > 1200.0f) {
            if (data->states[idx] == 2) {
                data->states[idx] = 0;
            } else if (data->states[idx] == 0) {
                return idx;
            }
        }
    }
    return -1;
}

void func_80800BA8_chminisubgame(actor, dialog_id, answer) Actor *actor;
s32 dialog_id;
s32 answer;
{
    u8 *base;
    s32 next_dialog;
    s32 unk_0;
    s32 map_id;
    s32 entrance;

    base = func_80100094(actor, 0);
    unk_0 = 4;
    next_dialog = 0;
    switch (dialog_id) {
        case 0x102C:
        case 0x102D:
        case 0x1049:
            _susubgame_entrypoint_5(actor, base + 0x30C, 5, 1, 0);
            if (func_800DA298(0x6E5) || func_800D395C()) {
                next_dialog = 0xCEC;
            } else {
                next_dialog = 0x102E;
                unk_0 = 0x46;
            }
            break;
        case 0x102E:
            if (answer == 1) {
                next_dialog = 0x102F;
                unk_0 = 0x46;
                _susubgame_entrypoint_6(actor, base + 0x30C, 0xD, 0x20, 0);
            } else {
                next_dialog = 0xCEC;
            }
            break;
        case 0x102F:
            if (actor->unk3C != NULL) {
                func_8010114C(actor->unk3C, 0x3E, 0);
                actor->unk3C = NULL;
            }
            next_dialog = 0xCEC;
            _susubgame_entrypoint_5(actor, base + 0x30C, 5, 1, 0);
            break;
        case 0xCEC:
            _susubgame_entrypoint_4(actor, base + 0x30C);
            actor->actorData[5] = 0;
            actor->actorData[4] = 0;
            func_800D2770(0xFC, 0);
            func_800FDC28(0xC);
            func_8009055C(0x85, 1);
            func_80090708(0);
            func_80101FDC(actor, 2);
            func_800CE8D8(0, 60.0f, 60);
            func_800CE88C(0, 1);
            _gcfrontend_entrypoint_9(0x6A);
            func_800DA544(0x6E5);
            func_800DA524(0);
            func_800BF99C(0, 0x5AA, 0);
            break;
        case 0x1030:
            func_800D1000(0x1F, 1, 0, 1, 0);
            _susubgame_entrypoint_6(actor, base + 0x30C, 1, 0, 0);
            break;
        case 0x1031:
        case 0x1032:
        case 0x1033:
        case 0x1034:
        case 0x104A:
        case 0x104B:
        case 0x104C:
            next_dialog = 0xCEB;
            unk_0 = 0x46;
            break;
        case 0xCEB:
            if (func_800D395C()) {
                if (answer == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else {
                if (answer == 1) {
                    map_id = 0x181;
                    entrance = 1;
                } else {
                    map_id = 0x1A9;
                    entrance = 0x1B;
                }
                func_8009055C(0x85, 0);
                func_80090708(0);
                func_80101FDC(actor, 4);
                _gcgoto_entrypoint_1(map_id, entrance);
            }
    }
    if (next_dialog != 0) {
        _subaddiedialog_entrypoint_11(actor->unk0, next_dialog, unk_0, NULL, 0x22);
    }
}

void func_80800EC8_chminisubgame(actor) Actor *actor;
{
    f32 unk_0[3];
    f32 unk_1[3];
    switch (actor->unk70_10) {
        case 3:
            if (*(s32 *) ((u8 *) actor + 0x34) >= 0) {
                func_800E3980(unk_0);
                actor->unk54 = func_80102D78(actor, unk_0);
                func_80102BF8(actor, 0.1f, 4.0f, 180.0f);
            }
            if (!func_800DA298(0)) {
                func_80102424(actor, 1);
            }
            break;
        case 1:
            if (actor->unk58 < 5.0f) {
                func_80102424(actor, 2);
            }
        case 2:
            func_8010D600(unk_1);
            actor->unk54 = func_80102D78(actor, unk_1);
            func_80102BF8(actor, 0.1f, 4.0f, 180.0f);
            *(f32 *) ((u8 *) actor + 0x28) +=
                (240.0f + (actor->unk58 / *(f32 *) ((u8 *) actor + 0x2C)) * -120.0f) *
                func_800D8FF8();
            actor->position[1] = *(f32 *) ((u8 *) actor + 0x30) +
                                   func_80013970(*(f32 *) ((u8 *) actor + 0x28)) * actor->unk50;
            if (func_800D9078(&actor->unk58) ||
                func_8010C9B0(actor->position, (s32) *(f32 *) ((u8 *) actor + 0x24))) {
                func_80801058_chminisubgame(actor, 0x3E, 0);
            }
    }
}

s32 func_80801058_chminisubgame(Actor *actor, s32 msg, Actor *source)
{
    Actor *host;
    Actor *shooter;
    s32 unk_0;
    s32 points;
    s32 hit;

    host = NULL;
    switch (msg) {
        case 0x40:
            shooter = source;
            // Matching: empty block steers IDO's code generation.
            if (&source) {
            }
            unk_0 = _subaddiemulti_entrypoint_5(shooter);
            points = actor->unk6C_0 + 1;
            // Matching: empty block steers IDO's code generation.
            if (1) {
            }
            host = func_80106790(actor->unk3C);
            host->actorData[4] += points;
            // Matching: empty block steers IDO's code generation.
            if ((s32) actor == points) {
            }
            _chscorepoints_entrypoint_2(points, unk_0, actor->position, 1);
            if ((((((((MS18 *) shooter)->b0 & 1) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFF) & 0xFFFF) &
                 0xFFFF) &
                0xFFFF) {
                func_8010114C(shooter, 0x98, 0);
            }
        case 0x3E:
            if (host == NULL) {
                host = func_80106790(actor->unk3C);
            }
            func_8010A570(actor);
            if (!func_800DA298(0)) {
                if (func_8010CC10(actor->position, *(s32 *) ((u8 *) actor + 0x24))) {
                    func_8010CCE0();
                    for (hit = func_8010CCEC(); hit != -1; hit = func_8010CCEC()) {
                        func_800F7A2C(hit, 7, actor->position);
                    }
                }
            }
            func_80801248_chminisubgame(actor);
            if ((s32) actor->actorData[7] >= 0) {
                func_80800A64_chminisubgame(host, actor->actorData[7]);
            }
            func_800FFAB0(actor);
            return 1;
        default:
            return 0;
        case 0x29:
        case 0x2A:
            return 1;
    }
}

void func_808011DC_chminisubgame(u8 *actor, s32 id, s32 mode)
{
    s32 handle;
    s32 pos;
    s32 slot;
    // Matching: needed for the match.
    if (1) {
        slot = func_800B53A4(mode);
        handle = slot;
        func_800BA670(slot, id);
        pos = actor + 4;
    }
    func_800BABB8(handle, pos, pos, *(s32 *) ((s8 *) actor + 0x38),
                  &D_808014B4_chminisubgame);
    func_800BA22C(handle, mode);
}

void func_80801248_chminisubgame(actor) u8 *actor;
{
    u8 *pos;
    if ((func_80090270(actor) == 0) && ((func_800DA298(0) != 0) || (func_800CEAD0(0) == 0))) {
        pos = actor + 4;
        func_800E1610(0, 0x41A00000, 0x3F19999A, actor + 4);
        func_800C4AF0(pos, &D_80801578_chminisubgame);
    }
    pos = actor + 4;
    func_808011DC_chminisubgame(actor, ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) * 3) + 0x9A4,
                                2);
    func_808011DC_chminisubgame(actor, ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) * 3) + 0x9A5,
                                6);
    func_808011DC_chminisubgame(actor, ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) * 3) + 0x9A6,
                                4);
    func_800BABB8(0, pos, 0, 0x3F800000, &D_808014F0_chminisubgame);
    func_800BABB8(0, pos, 0, 0x3F800000 & 0xFFFFFFFF, &D_80801534_chminisubgame);
}

extern void func_80102EC0();
extern void func_8010A730();
MinisubgameRecord D_80801400_chminisubgame[3] = {0x76E, 0xC8, 0x12C, 0x46, 0x46, 0x32,
                                                 0x76F, 0xC8, 0x12C, 0x46, 0x46, 0x4B,
                                                 0x770, 0xC8, 0x12C, 0x46, 0x46, 0x64};
int D_80801424_chminisubgame[18] = {0x15804AD,
                                    0x1,
                                    0x0,
                                    (u32) func_808000C8_chminisubgame,
                                    (u32) func_80102EC0,
                                    (u32) func_8010A730,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800430_chminisubgame,
                                    0x0,
                                    0x3240000,
                                    (u32) func_80800018_chminisubgame,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    (u32) func_80800484_chminisubgame,
                                    0x0};
int D_8080146C_chminisubgame[18] = {0x1C704AE,
                                    0x76E0003,
                                    0x0,
                                    (u32) func_80800EC8_chminisubgame,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x104,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    0x0,
                                    (u32) func_80107C2C,
                                    -0x7FE00000,
                                    (u32) func_80801058_chminisubgame,
                                    0x0};
s32 D_808014B4_chminisubgame[15] = {0x1130016, 0x10000015, 0xCC,     0x2B0133,  0x1990022,
                                    0x1000100, 0x660099,   0xE000A,  0x14002D,  0x4B005DC,
                                    0x1BFF9C,  -0xC7FFD9,  0xC800C8, 0x1900190, 0x0};
u8 D_808014F0_chminisubgame[68] = {
    0x7,  0x10, 0x0, 0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x2,  0x0, 0x99, 0x0, 0x16,
    0x12, 0x0,  0x0, 0xE,  0x0, 0xDC, 0x0, 0xF0, 0x0, 0x26, 0x0, 0x0,  0x0, 0x0,
    0xFF, 0x9C, 0x0, 0x0,  0x0, 0x0,  0x0, 0x64, 0x0, 0x19, 0x0, 0x1,  0x0, 0x1,
    0x0,  0x22, 0x1, 0x33, 0x1, 0x99, 0x3, 0x33, 0x4, 0x0,  0x0, 0x2A, 0x0, 0xA,
    0x0,  0xA,  0x0, 0x80, 0x0, 0x8C, 0x0, 0xF,  0x0, 0x0,  0x0, 0x0};
u8 D_80801534_chminisubgame[68] = {
    0x5,  0x10, 0x0, 0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x2,  0x0, 0x99, 0x0, 0x16,
    0x12, 0x0,  0x0, 0xE,  0x0, 0x3C, 0x0, 0x78, 0x0, 0x26, 0x0, 0x0,  0x0, 0x0,
    0xFF, 0x9C, 0x0, 0x0,  0x0, 0x0,  0x0, 0x64, 0x0, 0x19, 0x0, 0x0,  0x0, 0x0,
    0x0,  0x22, 0x1, 0x33, 0x1, 0x99, 0x4, 0x0,  0x5, 0x99, 0x0, 0x2A, 0x0, 0x8,
    0x0,  0x8,  0x0, 0x66, 0x0, 0x66, 0x0, 0xF,  0x0, 0x0,  0x0, 0x0};
u8 D_80801578_chminisubgame[24] = {0x0,  0x13, 0x4, 0x13, 0x0, 0x1B, 0x0, 0x18, 0x0, 0x1, 0x3, 0xE8,
                                   0x17, 0x70, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
