#include "common.h"

extern void *D_80801F80_chwaspnestgame;
extern void *D_80801FC8_chwaspnestgame;
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    f32 positions[2][3];
    f32 timers[2];
    u8 pad_0[0x1C];
    f32 nests[3][3];
} WaspNestGameState;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x20];
    u8 flags[2];
    u8 pad_1[2];
    u8 unk_24[1];
} WaspNestReset1302;
extern s16 D_80801F76_chwaspnestgame[];
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80103140();
extern u16 D_80801F70_chwaspnestgame[];
extern void func_8008FE68(f32 *);
extern f32 func_80090010(void);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
extern u8 *func_80106790(s32);
extern void func_8010D600(f32 *);
extern f32 func_80102D78();
extern void func_80102BF8(u8 *, f32, f32, f32);
extern void func_800EF334(s32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_80802044_chwaspnestgame[];
extern u8 D_80802068_chwaspnestgame[];
extern f32 func_800EEF94(f32 *);
extern int func_800BABB8(s32, f32 *, s32, f32, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 pad72 : 10;
} WaspState;
extern void func_8010DCB4(s32);
extern u8 D_8080207C_chwaspnestgame[];
typedef struct {
    f32 position[2][3];
    f32 distance[2];
} WaspNestClosest32;
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct {
    f32 pos[2][3];
    f32 timer[2];
    u8 sfx[2];
    u8 pad22[2];
    u8 unk24[1];
} WaspNestLocal;
extern u8 D_80802010_chwaspnestgame[];
extern void *func_80100094(Actor *, s32);
extern u8 func_800C4350(s32, f32 *, void *);
extern void func_800C3224(s32, f32, f32, f32);
extern void func_800D24E8(s32, s32, s32);
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern void func_80108B04(Actor *, s32);
extern s32 func_800CEAD0(s32);
extern s32 func_800D0A9C(s32, s32);
extern s32 func_800D0B68(s32, s32);
extern s32 func_800D90A4(f32 *);
extern void func_80090708(s32);
extern void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, s32, s32);
extern void func_80101FDC(Actor *, s32);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
extern s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern u8 D_80802024_chwaspnestgame[];
extern u8 D_80802038_chwaspnestgame[];
extern void func_800C4AF0(f32 *, void *);
void func_80800B80_chwaspnestgame();
void func_80800D7C_chwaspnestgame();
s32 func_80800DE4_chwaspnestgame();
void func_80800C7C_chwaspnestgame();
s32 func_80800EB8_chwaspnestgame();
void func_80800F98_chwaspnestgame();

void *chwaspnestgame_entrypoint_0()
{
    return &D_80801F80_chwaspnestgame;
}

void *chwaspnestgame_entrypoint_1()
{
    return &D_80801FC8_chwaspnestgame;
}

// Controller state change: sets up the game, ends it with the result dialog, or restarts.
void func_80800018_chwaspnestgame(Actor *actor, s32 state)
{
    u8 *data;
    s32 dialog_id;
    s32 no_page;
    s32 unk_0;
    s32 record;
    s32 score;
    s32 no_jiggy;

    data = func_80100094(actor, 0);
    switch (state) {
        case 2:
            func_800DA524(0);
            _susubgame_entrypoint_4(actor, data + 0x24);
            func_800DA544(0x6E6);
            _gcfrontend_entrypoint_9(0x73);
            func_800FDC28(12);
            func_80090708(0);
            actor->actorData[7] = 0;
            actor->actorData[3] = 0;
            func_800CE8D8(0, 60.0f, 60);
            func_800CE88C(0, 1);
            func_800D2770(0xF5, 0);
            break;
        case 3:
            record = func_800D2054(0, 0x87, actor->actorData[3]);
            func_80090708(2);
            _susubgame_entrypoint_5(actor, data + 0x24, 5, 1, 0);
            func_80101180(0x1E4, 0x45, 0);
            if (func_800D395C()) {
                if (record == 1) {
                    dialog_id = 0x144E;
                    unk_0 = 0x16;
                } else if (record == 0) {
                    dialog_id = 0x144F;
                    unk_0 = 0x17;
                } else {
                    dialog_id = 0x1450;
                    unk_0 = 0x17;
                }
            } else if (!func_800D0A9C(0x18, 4) && (s32) actor->actorData[3] >= 40) {
                dialog_id = 0x140A;
                unk_0 = 0x16;
            } else if (!func_800D0A9C(0x4B, 1) && (s32) actor->actorData[3] >= 50) {
                dialog_id = 0x140C;
                unk_0 = 0x16;
            } else {
                no_jiggy = func_800D0A9C(0x4B, 1) == 0;
                no_page = func_800D0A9C(0x18, 4) == 0;
                if (no_page + no_jiggy) {
                    score = actor->actorData[3];
                    switch (score) {
                        case 0:
                            dialog_id = 0x1410;
                            break;
                        case 1:
                            dialog_id = 0x144C;
                            break;
                        default:
                            dialog_id = 0x140E;
                            break;
                    }
                    unk_0 = 0x17;
                } else if (record == 1) {
                    dialog_id = 0x140D;
                    unk_0 = 0x16;
                } else {
                    dialog_id = actor->actorData[3] ? 0x140F : 0x1410;
                    unk_0 = 0x17;
                }
            }
            func_800FDC28(0);
            func_800FC6B0(unk_0);
            _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 6, 0, 0x99);
            break;
        case 5:
            func_80090708(0);
            _susubgame_entrypoint_4(actor, data + 0x24);
            actor->unk58 = 0.5f;
    }
    func_80101FDC(actor, state);
}

// Controller init: reads the three nest markers.
void func_808002EC_chwaspnestgame(Actor *actor)
{
    WaspNestGameState *state;
    s32 i;
    f32 marker[6];
    state = (WaspNestGameState *) func_80100094(actor, 0);
    _subaddiemarker_entrypoint_0(actor, 0x201, marker, 1);
    func_800EE7F8((f32 *) actor->actorData, marker);
    for (i = 0; i < 2; i++) {
        func_800EFD24(state->positions[i]);
        state->timers[i] = -1.0f;
    }
    for (i = 0; i < 3; i++) {
        _subaddiemarker_entrypoint_1(actor, 0x1C0, i + 0x33, marker, 1);
        func_800EE7F8(state->nests[i], marker);
    }
    _susubgame_entrypoint_0(actor, (u8 *) state + 0x24, 0);
    _susubgame_entrypoint_11(0);
}

void func_80800400_chwaspnestgame(Actor *actor)
{
    WaspNestReset1302 *state;
    s32 i;

    state = (WaspNestReset1302 *) func_80100094(actor, 0);
    for (i = 0; i < 2; i++) {
        state->flags[i] = 0;
    }
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(actor, state->unk_24)) {
        _susubgame_entrypoint_4(actor, state->unk_24);
    }
    func_800FDC28(0xC);
}

void func_8080047C_chwaspnestgame(Actor *this)
{
    WaspNestLocal *local;
    u32 i;
    s32 n;
    f32 r;
    WaspNestLocal *local2;

    local = func_80100094(this, 0);
    for (i = 0; i < 2; i++) {
        if (0.0f < local->timer[i]) {
            if (local->sfx[i] == 0) {
                local->sfx[i] = func_800C4350(0, local->pos[i], D_80802010_chwaspnestgame);
            }
            if (this->unk70_10 == 2) {
                func_800C3224(local->sfx[i], 1.0f, 1.1f, 0.05f);
            } else {
                func_800C3224(local->sfx[i], 0.8f, 0.9f, 0.05f);
            }
            func_800C4350(local->sfx[i], local->pos[i], 0);
            local->timer[i] = -1.0f;
        }
    }
    switch (this->unk70_10) {
        case 1:
            break;
        case 2:
            func_800D24E8(0xF5, this->actorData[3], 0);
            if ((s32) this->actorData[7] < 10 && func_800DC298(0.09999084473f)) {
                n = 1;
                r = func_800DC0C0();
                if (r < 0.1666665971f) {
                    n = 3;
                } else if (r < 0.5f) {
                    n = 2;
                }
                func_80108B04(this, n);
            }
            if (func_800CEAD0(0)) {
                func_80800018_chwaspnestgame(this, 3);
            }
            break;
        case 5:
            if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) ||
                (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
                break;
            }
            if (func_800D90A4(&this->unk58)) {
                local2 = func_80100094(this, 0);
                func_80090708(2);
                _susubgame_entrypoint_5(this, local2->unk24, 5, 1, 0);
                _subaddiedialog_entrypoint_11(this->unk0, 0xCEB, 0x46, 0, 0x99);
                func_80101FDC(this, 3);
            }
    }
}

// Controller message handler.
s32 func_80800724_chwaspnestgame(Actor *actor, s32 msg, s32 arg)
{
    u8 *data;
    s32 index;
    s32 no_page;
    s32 no_jiggy;

    data = (u8 *) func_80100094(actor, 0);
    switch (msg) {
        case 0x95:
            if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) ||
                (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
                actor->unk58 = 0.5f;
                func_80101FDC(actor, 5);
            } else {
                func_80090708(2);
                if (func_800D395C()) {
                    _susubgame_entrypoint_5(actor, data + 0x24, 5, 1, 0);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x144D, 6, 0, 0x99);
                } else if (func_800DA298(0x6E6)) {
                    _susubgame_entrypoint_5(actor, data + 0x24, 5, 1, 0);
                    no_jiggy = !func_800D0A9C(0x4B, 1);
                    no_page = !func_800D0A9C(0x18, 4);
                    _subaddiedialog_entrypoint_11(actor->unk0, -no_page - no_jiggy + 0x144B, 6, 0,
                                                  0x99);
                } else {
                    _susubgame_entrypoint_6(actor, data + 0x24, 8, 0x20, 0);
                    no_jiggy = !func_800D0A9C(0x4B, 1);
                    no_page = !func_800D0A9C(0x18, 4);
                    _subaddiedialog_entrypoint_11(actor->unk0, -no_page - no_jiggy + 0x1407, 6, 0,
                                                  0x99);
                    func_800DA544(0);
                    func_80108B04(actor, 0);
                }
                func_80800018_chwaspnestgame(actor, 1);
            }
            break;
        case 0x3D:
            if (arg > 0) {
                func_80800C7C_chwaspnestgame(actor, arg);
            } else if (arg < 0) {
                func_80800D7C_chwaspnestgame(actor, -arg);
            } else {
                func_80800B80_chwaspnestgame(actor);
            }
            break;
        case 0x2E:
            func_80800F98_chwaspnestgame(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x30:
            return func_80800EB8_chwaspnestgame(actor, ((s16 *) &arg)[0],
                                                ((s16 *) &arg)[1]);
        case 0x2F:
            index = ((s16 *) &arg)[1];
            func_80101180(0x1E4, 0x45, 0);
            _susubgame_entrypoint_6(actor, data + 0x24, D_80801F76_chwaspnestgame[index],
                                    0x20, 0);
            func_80108B04(actor, -index);
            break;
        case 0xB:
            return func_80800DE4_chwaspnestgame(actor, arg);
        case 0x57:
            return _susubgame_entrypoint_3(actor, data + 0x24, arg & 0xFFFF,
                                           (u32) (arg & 0xFFFF0000) >> 16);
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            func_80101180(0x1E4, 0x45, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x46, 0, 0x99);
            func_80101FDC(actor, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

// Spawns a Zubba (actor 0x1E4) owned by the controller.
Actor *func_80800AF8_chwaspnestgame(Actor *controller, f32 *pos, f32 *target, s32 type)
{
    Actor *zubba;
    zubba = func_80108528(0x1E4, pos, 0, &controller);
    zubba->unk3C = controller->unk0;
    func_800EE7F8((f32 *) zubba->actorData, target);
    zubba->unk6C_0 = type;
    func_80103140(zubba, D_80801F70_chwaspnestgame[type], 0);
    return zubba;
}

// Spawns a Zubba near the player.
void func_80800B80_chwaspnestgame(actor) Actor *actor;
{
    f32 player_pos[3];
    f32 offset[3];
    Actor *zubba;
    func_8008FE68(player_pos);
    func_800EEB9C(offset, func_80090010(), 300.0f);
    offset[1] = 100.0f;
    func_800EF04C(player_pos, offset);
    zubba = func_80800AF8_chwaspnestgame(actor, actor->position, actor->position, 0);
    actor->unk3C = zubba->unk0;
    ((u8 *) zubba)[0x75] &= ~0x10;
}

void func_80800C00_chwaspnestgame(f32 *vec, f32 scale)
{
    vec[0] = func_800DC178(-100.0f, 100.0f);
    vec[1] = func_800DC178(-100.0f, 100.0f);
    vec[2] = func_800DC178(-100.0f, 100.0f);
    func_800EF368(vec, scale);
}

// Spawns a Zubba from above, found by a downward raycast.
void func_80800C7C_chwaspnestgame(controller, type) Actor *controller;
s32 type;
{
    s32 hit;
    f32 line_start[3];
    f32 line_end[3];
    f32 hit_pos[3];
    f32 spawn_target[3];
    f32 center[3];
    f32 dir[3];
    f32 down[3];

    func_80800C00_chwaspnestgame(center, 500.0f);
    center[1] += 1950.0f;
    func_80800C00_chwaspnestgame(dir, 100.0f);
    func_800EE7B4(line_end, center, dir, 100.0f);
    func_800EE7B4(line_start, center, dir, -100.0f);
    func_800EFA4C(down, 0.0f, -600.0f, 0.0f);
    hit = func_800F0734(line_start, line_end, down, 4000.0f, 5100.0f, hit_pos, spawn_target);
    if (hit) {
        func_800EF3DC(hit_pos, dir);
        func_800EF04C(spawn_target, dir);
        func_80800AF8_chwaspnestgame(controller, hit_pos, spawn_target, type);
        controller->actorData[7]++;
    }
}

// Spawns a Zubba at a nest marker.
void func_80800D7C_chwaspnestgame(controller, nest) Actor *controller;
s32 nest;
{
    u8 *state;
    f32 pos[3];
    f32 target[3];

    state = (u8 *) func_80100094(controller, 0);
    func_800EE7F8(pos, ((f32(*)[3])(state + 0x30))[nest]);
    func_800EE7F8(target, pos);
    func_80800AF8_chwaspnestgame(controller, pos, target, nest);
}

s32 func_80800DE4_chwaspnestgame(controller, phase)
u8 *controller;
s32 phase;
{
    s32 state;

    state = func_80100094(controller, 0);
    switch (phase) {
        case 0:
            if ((func_800D0A9C(0x4B, 1) == 0) && (*(s32 *) ((s8 *) controller + 0x24) >= 0x32)) {
                _susubgame_entrypoint_5(controller, state + 0x24, 5, 1, 0);
                _subaddiedialog_entrypoint_11(*(s32 *) (s8 *) controller, 0x140B, 4, 0, 0x99);
                return 4;
            }
            func_80800018_chwaspnestgame(controller, 5);
            return 4;
        case 4:
            func_80800018_chwaspnestgame(controller, 5);
            return 4;
        default:
            return 3;
    }
}

s32 func_80800EB8_chwaspnestgame(controller, dialog_id, arg)
Actor *controller;
s32 dialog_id;
s32 arg;
{
    switch (dialog_id) {
        case 0x1405:
        case 0x1449:
            return arg ? 50 : 40;
        case 0x1406:
        case 0x144A:
            return 50;
        case 0x1409:
            return 60;
        case 0x140E:
        case 0x144C:
            return controller->actorData[3];
        case 0x140F:
        case 0x1450:
            if (!arg)
                return controller->actorData[3];
    }
    return func_800D211C(0x87);
}

void func_80800F98_chwaspnestgame(controller, dialog_id, answer) Actor *controller;
s32 dialog_id;
s32 answer;
{
    u8 *state;
    s32 next_dialog;
    s32 dialog_arg;
    s32 map;
    s32 entrance;

    state = func_80100094(controller, 0);
    dialog_arg = 4;
    next_dialog = 0;
    switch (dialog_id) {
        case 0x1405:

        case 0x1406:

        case 0x1407:
            _susubgame_entrypoint_5(controller, state + 0x24, 5, 1, 0);
            next_dialog = 0x1408;
            dialog_arg = 0x46;
            break;

        case 0x1408:
            if (answer == 1) {
                next_dialog = 0x1409;
                _susubgame_entrypoint_6(controller, state + 0x24, 0xC, 0x20, 0);
            } else {
                next_dialog = 0xCEC;
                func_80101180(0x1E4, 0x45, 0);
            }
            break;

        case 0x1409:
            func_80101180(0x1E4, 0x45, 0);
            _susubgame_entrypoint_5(controller, state + 0x24, 5, 1, 0);

        case 0x1449:

        case 0x144A:

        case 0x144B:

        case 0x144D:
            next_dialog = 0xCEC;
            break;

        case 0xCEC:
            func_80800018_chwaspnestgame(controller, 2);
            break;

        case 0xCEB:
            if (func_800D395C() != 0) {
                if (answer == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else {
                if (answer == 1) {
                    map = 0x139;
                    entrance = 1;
                } else {
                    map = 0x136;
                    entrance = 0x13;
                }
                func_80090708(0);
                func_80800018_chwaspnestgame(controller, 4);
                _gcgoto_entrypoint_1(map, entrance);
            }
            break;

        case 0x140A:
            func_800D1000(0x18, 4, controller->actorData, 1, 0);
            _susubgame_entrypoint_6(controller, state + 0x24, 0, 0x20, 0);
            break;

        case 0x140B:

        case 0x140C:
            func_800D1000(0x4B, 1, 0, 1, 0);
            _susubgame_entrypoint_6(controller, state + 0x24, 4, 0x20, 0);
            break;

        case 0x140D:

        case 0x140E:

        case 0x140F:

        case 0x1410:

        case 0x144C:

        case 0x144E:

        case 0x144F:

        case 0x1450:
            next_dialog = 0xCEB;
            dialog_arg = 0x46;
    }

    if (next_dialog != 0) {
        _subaddiedialog_entrypoint_11(controller->unk0, next_dialog, dialog_arg, 0, 0x99);
    }
}

// Zubba kill report: adds score to the controller and decrements its alive count.
int func_80801260_chwaspnestgame(s32 id, s32 amount)
{
    Actor *controller;
    controller = func_80106790(id);
    *(s32 *) ((char *) controller + 0x24) += amount;
    (*(s32 *) ((char *) controller + 0x34))--;
}

void func_8080129C_chwaspnestgame(s32 id)
{
    (*(s32 *) (func_80106790(id) + 0x34))--;
}

void func_808012C8_chwaspnestgame(s32 arg0)
{
}

void func_808012D0_chwaspnestgame(u8 *zubba)
{
    f32 target_pos[3];
    func_8010D600(target_pos);
    *(f32 *) (zubba + 0x54) = func_80102D78(zubba, target_pos);
    func_80102BF8(zubba, 0.1f, 4.0f, 180.0f);
    func_808012C8_chwaspnestgame(zubba);
}

void func_80801324_chwaspnestgame(s32 vec, f32 length, f32 new_length)
{
    if (length != 0.0f) {
        func_800EF334(vec, new_length / length);
    }
}

void func_80801364_chwaspnestgame(actor, state) Actor *actor;
s32 state;
{
    f32 player_pos[3];
    if ((actor->unk70_10 == 2) && (state != 5)) {
        func_8010DCB4(0xA);
    }
    switch (state) {
        case 2:
            func_8010DC50(0xA);
            break;

        case 1:
            func_8008FE68(player_pos);
            *(f32 *) ((s8 *) actor + 0x28) = player_pos[2] - actor->position[2];
            *(f32 *) ((s8 *) actor + 0x2C) = 0;
            *(f32 *) ((s8 *) actor + 0x30) = player_pos[0] - actor->position[0];
            func_800EF2A0((s8 *) actor + 0x28);
            *(f32 *) ((s8 *) actor + 0x24) = 0.0f;
            *(f32 *) ((s8 *) actor + 0x34) = 0.0f;
            *(f32 *) ((s8 *) actor + 0x2C) = 1.0f;
            func_800EE7F8(actor->actorData, actor->position);
            break;

        case 5:
            func_8010A570(actor);
            break;

        case 3:
            func_800C4AF0(actor->position, &D_80802024_chwaspnestgame);
            func_8010A570(actor);
            break;

        case 4: {
            func_800C4AF0(actor->position, &D_80802038_chwaspnestgame);
            ((Actor *) actor)->rotation[0] = 0.0f;
            break;
        }

        case 6:
            func_800EFD24((s8 *) actor + 0x28);
            break;

        case 7:
            _subaddiefade_entrypoint_3(actor);
    }

    func_80102424(actor, state);
}

void func_808014BC_chwaspnestgame(Actor *actor, f32 *accel)
{
    f32 dt;

    dt = func_800D8FF8();
    actor->position[0] +=
        ((f32 *) actor->actorData)[4] * dt + accel[0] * dt * dt;
    actor->position[1] +=
        ((f32 *) actor->actorData)[5] * dt + accel[1] * dt * dt;
    actor->position[2] +=
        ((f32 *) actor->actorData)[6] * dt + accel[2] * dt * dt;
    ((f32 *) actor->actorData)[4] += accel[0] * dt;
    ((f32 *) actor->actorData)[5] += accel[1] * dt;
    ((f32 *) actor->actorData)[6] += accel[2] * dt;
}

int func_80801590_chwaspnestgame(Actor *actor, f32 radius, f32 max_speed)
{
    f32 dist;
    f32 speed;
    f32 to_target[3];
    f32 old_pos[3];
    f32 new_pos[3];
    f32 hit_pos[3];
    f32 angles[3];
    s32 effect;
    func_800EFB24(to_target, (f32 *) actor->actorData, actor->position);
    dist = func_800EEF94(to_target);
    if (dist < 2.0f * radius)
        func_80801324_chwaspnestgame(to_target, dist, 8.0f * max_speed);
    else
        func_80801324_chwaspnestgame(to_target, dist, 2.0f * max_speed);
    func_800EE7F8(old_pos, actor->position);
    func_808014BC_chwaspnestgame(actor, to_target);
    speed = func_800EEF94((f32 *) &actor->actorData[4]);
    if (max_speed < speed)
        func_80801324_chwaspnestgame((f32 *) &actor->actorData[4], speed, max_speed);
    func_800EE7F8(new_pos, actor->position);
    if (actor->unk74_30)
        func_800EE7F8(new_pos, actor->position);
    else {
        func_800EE7F8(new_pos, old_pos);
        func_800EE7F8(old_pos, actor->position);
    }
    if (func_800BEF00(old_pos, new_pos, hit_pos, 0x20020)) {
        actor->unk74_30 = (s32) actor->unk74_30 ^ 1;
        func_800F1988(hit_pos, &angles[0], &angles[1]);
        angles[2] = 0.0f;
        effect = func_800BABB8(0, new_pos, 0, 1.0f, D_80802044_chwaspnestgame);
        func_800BA77C(effect, (s16) (s32) angles[0], (s16) (s32) angles[1],
                      (s16) (s32) angles[2]);
        func_800BA22C(effect, 1);
        func_800C4AF0(actor->position, D_80802068_chwaspnestgame);
    }
    return dist < 0.5f * radius;
}

s32 func_808017DC_chwaspnestgame(void *actor, f32 gravity, s32 check_hit)
{
    f32 accel[3];
    f32 old_pos[3];
    f32 hit_pos[3];

    func_800EFA4C(accel, 0.0f, -gravity, 0.0f);
    func_800EE7F8(old_pos, (f32 *) ((u8 *) actor + 4));
    func_808014BC_chwaspnestgame(actor, accel);
    return check_hit != 0
               ? (func_800BEF00(old_pos, (f32 *) ((u8 *) actor + 4), hit_pos, 0x20020) ? 1
                                                                                             : 0)
               : 0;
}

void func_80801880_chwaspnestgame(f32 *state, f32 amp, f32 speed_a, f32 speed_b)
{
    f32 dt;

    dt = func_800D8FF8();
    state[13] += speed_a * dt;
    state[9] += speed_b * dt;
    state[1] = state[6] + (state[10] * amp) * func_800138D0(state[13]);
    state[3] = state[8] + (state[12] * amp) * func_800138D0(state[13]);
    state[2] = state[7] + (state[11] * amp) * func_80013970(state[9]);
}

void func_80801954_chwaspnestgame(Actor *actor)
{
    if (func_800EEB40((f32 *) actor->actorData, actor->position) > 1.0f) {
        func_80801364_chwaspnestgame(actor, 2);
    } else {
        func_80801364_chwaspnestgame(actor, 1);
    }
    if (func_800DA298(0)) {
        func_8010A570(actor);
    }
}

void func_808019D4_chwaspnestgame(WaspState *actor)
{
    if (actor->f72 == 2 || actor->f72 == 5) {
        func_8010DCB4(10);
    }
}

void func_80801D28_chwaspnestgame();

void func_80801A10_chwaspnestgame(u8 *actor)
{
    switch ((u32) (u16) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) {
        case 1:
            func_80801D28_chwaspnestgame(actor);
            func_808012D0_chwaspnestgame(actor);
            func_80801880_chwaspnestgame(actor, 5e+01f, 2.4e+02f, 1.9e+02f);
            return;

        case 2:
            func_80801D28_chwaspnestgame(actor);
            func_80801CE4_chwaspnestgame(actor);
            if (func_80801590_chwaspnestgame(actor, 1e+02f, 5e+02f) != 0) {
                if (func_800DA298(0) == 0) {
                    func_8080129C_chwaspnestgame(*(s32 *) ((s8 *) actor + 0x3C));
                    func_800FFA88(*(s32 *) ((s8 *) actor + 0));
                    return;
                }
                func_80801364_chwaspnestgame(actor, 1);
            }

            return;

        case 5:
            func_80801D28_chwaspnestgame(actor);
            func_80801CE4_chwaspnestgame(actor);
            if (func_80801590_chwaspnestgame(actor, 2e+02f, 2e+03f) != 0) {
                func_800FFA88(*(s32 *) ((s8 *) actor + 0));
            }
            break;

        case 3:
            func_808012C8_chwaspnestgame(actor);
            if (func_808017DC_chwaspnestgame(actor, 1e+03f, 1) != 0) {
                func_80801364_chwaspnestgame(actor, 4);
            }
            break;

        case 4:
            if (func_80101DDC(actor) != 0) {
                func_80801364_chwaspnestgame(actor, 7);
            }
            break;

        case 6:
            func_80801D28_chwaspnestgame(actor);
            if (func_808017DC_chwaspnestgame(actor, 5e+02f, 1) != 0) {
                func_80801364_chwaspnestgame(actor, 7);
            }
    }
}

s32 func_80801B9C_chwaspnestgame(Actor *actor, s32 msg, s32 arg)
{
    s32 points;
    s32 type;
    switch (msg) {
        case 0x3E:
            func_800C4AF0(actor->position, D_8080207C_chwaspnestgame);
            return 1;
        case 0x40:
            points = _subaddiemulti_entrypoint_5(*(s32 *) &arg);
            type = actor->unk6C_0;
            _chscorepoints_entrypoint_2(type, points, actor->position, 1);
            func_80801260_chwaspnestgame(actor->unk3C, type);
            func_80801364_chwaspnestgame(actor, 3);
            return 1;
        case 0x45:
            if (actor->unk70_10 == 2) {
                func_80801364_chwaspnestgame(actor, 5);
            } else if (actor->unk70_10 == 1) {
                func_80801364_chwaspnestgame(actor, 6);
            }
            break;
        case 0x1F:
            if (actor->unk70_10 == 2 || actor->unk70_10 == 5)
                func_8010DD20(actor, 10, *(s32 *) &arg);
            else
                func_801015D0(actor);
            return 1;
        default:
            return 0;
    }
    return 1;
}

int func_80801CE4_chwaspnestgame(s32 actor)
{
    f32 dir[2];
    func_800F1A88(actor + 0x28, dir);
    *(f32 *) ((char *) actor + 0x44) = -dir[0];
    *(f32 *) ((char *) actor + 0x48) = dir[1];
}

void func_80801D28_chwaspnestgame(Actor *actor)
{
    s32 i;
    WaspNestClosest32 *closest;
    s32 j;
    f32 player_pos[3];
    f32 dist;

    closest = (WaspNestClosest32 *) func_80100094(func_80106790(actor->unk3C), 0);
    func_800E3980(player_pos);
    dist = func_800EEAD4(actor->position, player_pos);
    for (i = 0; i < 2; i++) {
        if (closest->distance[i] < 0.0f || dist < closest->distance[i]) {
            break;
        }
    }
    if (i < 2) {
        for (j = 1; j > i; j--) {
            func_800EE7F8(closest->position[j], closest->position[j - 1]);
            closest->distance[j] = closest->distance[j - 1];
        }
        func_800EE7F8(closest->position[i], actor->position);
        closest->distance[i] = dist;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C so IDO schedules the functions
// that the tables point to as in the original. Values are taken from the ROM.
// D_80801F76_chwaspnestgame = D_80801F70_chwaspnestgame + 0x6 (linker symbol in undefined_syms.us.txt).
extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
extern void func_801018A4();
extern void func_80108ED0();
u32 D_80801F30_chwaspnestgame[16] = {0x0,        0x0,       0x3F266666, 0x3CB0001, 0x0, 0x0,
                                     0x3E4CCCCD, 0x3CD0001, 0x3F800000, 0x3CE0002, 0x0, 0x0,
                                     0x3F266666, 0x3CB0001, 0x3F800000, 0x3CE0084};
u16 D_80801F70_chwaspnestgame[8] = {0x85F, 0x76B, 0x76C, 0x76D, 0x18, 0x14, 0x10, 0x0};
void *D_80801F80_chwaspnestgame = (void *) 0x015801E3;
static u32 D_80801F80_chwaspnestgame_rest[17] = {0x1,
                                                 0x0,
                                                 (u32) func_8080047C_chwaspnestgame,
                                                 (u32) func_80102EC0,
                                                 (u32) func_8010A730,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_80800400_chwaspnestgame,
                                                 0x0,
                                                 0x600000,
                                                 (u32) func_808002EC_chwaspnestgame,
                                                 (u32) func_80107C2C,
                                                 0x80002402,
                                                 (u32) func_80800724_chwaspnestgame,
                                                 0x0};
void *D_80801FC8_chwaspnestgame = (void *) 0x01C201E4;
static u32 D_80801FC8_chwaspnestgame_rest[17] = {0x85F0001,
                                                 (u32) &D_80801F30_chwaspnestgame,
                                                 (u32) func_80801A10_chwaspnestgame,
                                                 (u32) func_80102EC0,
                                                 (u32) func_801018A4,
                                                 0x0,
                                                 0x3F800000,
                                                 0x0,
                                                 0x104,
                                                 (u32) func_808019D4_chwaspnestgame,
                                                 (u32) func_80108ED0,
                                                 0x0,
                                                 (u32) func_80801954_chwaspnestgame,
                                                 (u32) func_80107C2C,
                                                 0x80200000,
                                                 (u32) func_80801B9C_chwaspnestgame,
                                                 0x0};
u8 D_80802010_chwaspnestgame[20] = {0x2,  0x6,  0x0, 0x13, 0x4,  0x9B, 0x0, 0x1, 0x3, 0xE8,
                                    0x17, 0x70, 0x0, 0x16, 0x27, 0x10, 0x0, 0x7, 0x0, 0x0};
u8 D_80802024_chwaspnestgame[20] = {0x0, 0x13, 0x6, 0xE,  0x0, 0x1,  0x3, 0xE8, 0x17, 0x70,
                                    0x0, 0xD,  0x1, 0x99, 0x1, 0xB3, 0x0, 0x0,  0x0,  0x0};
u8 D_80802038_chwaspnestgame[12] = {0x0, 0x13, 0x4,  0x1F, 0x0, 0x1,
                                    0x3, 0xE8, 0x17, 0x70, 0x0, 0x0};
u8 D_80802044_chwaspnestgame[36] = {0x1, 0x10, 0x0, 0x1D, 0x8, 0x21, 0x0, 0x2B, 0x2, 0x0, 0x2, 0x80,
                                    0x0, 0x22, 0x1, 0x80, 0x2, 0x0,  0x4, 0x80, 0x5, 0x0, 0x0, 0x15,
                                    0x0, 0x0,  0x0, 0x80, 0x0, 0x33, 0x0, 0x3,  0x0, 0x0, 0x0, 0x0};
u8 D_80802068_chwaspnestgame[20] = {0x0, 0x13, 0x6, 0xF,  0x0, 0x1,  0x3, 0xE8, 0x17, 0x70,
                                    0x0, 0xD,  0x0, 0xD9, 0x0, 0xF3, 0x0, 0x0,  0x0,  0x0};
u8 D_8080207C_chwaspnestgame[20] = {0x0, 0x13, 0x6, 0x10, 0x0, 0x1,  0x3, 0xE8, 0x17, 0x70,
                                    0x0, 0xD,  0x0, 0xF3, 0x1, 0x19, 0x0, 0x0,  0x0,  0x0};
