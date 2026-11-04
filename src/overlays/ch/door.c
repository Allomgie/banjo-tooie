// Generic door behaviour shared by about 25 door/gate/grill actors: a state machine that moves
// the door between two poses (rotate, slide, fade), with sounds, camera shots, flags, messages.
#include "common.h"

typedef struct {
    u8 pad_0[0x2E];
    s16 unk_2E;
    s16 unk_30;
    s16 unk_32;
} DoorLoopSound;
extern void *func_80100094(Actor *, u32);
extern void func_800C4B64(f32);
extern u8 D_808015B0_chdoor[];
extern void func_800C4B7C(s32);
extern void func_800C4B70(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 unk_4;
    u8 unk_5;
    u16 active : 1;
    u16 flag_id : 15;
} DoorEntry;
typedef struct {
    u32 flags;
    u8 pad_4[0x18];
    DoorEntry ents[1];
} DoorState;
typedef struct {
    s32 flags;
    u8 pad_4[4];
    u8 motion : 6;
    u8 reverse_pending : 1;
    u8 unk_8_0 : 1;
    u8 pad_9;
    s16 move_time;
    u8 pad_C[0x14];
    u8 open_cutscene;
    u8 unk_21;
    u8 pad_22[2];
    s16 unk_24;
    u8 pad_26[2];
    u8 close_cutscene;
    u8 unk_29;
    u8 pad_2A[2];
    s16 unk_2C;
} DoorLocal;
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern s32 _glcutDll_entrypoint_19(s32);
extern s32 _capod_entrypoint_17(f32);
typedef struct {
    u32 flags;
    s16 flag_id;
} DoorFlagState;
extern f32 mlAbsF(f32);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern f32 func_800F5F24(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800F0AA4(f32 *, f32 *, f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EE88C();
extern f32 func_800F1DCC(f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void _sudeflect_entrypoint_3(f32 *, f32 *, f32 *, f32 *, s32);
typedef struct {
    u32 flags;
    u8 pad_4[4];
    u32 pad8_26 : 6;
    u32 reverse_pending : 1;
    u32 pad8_16 : 9;
    s16 move_time;
    s16 open_delay;
    s16 close_delay;
} DoorData;
void func_8080050C_chdoor();

void func_80800028_chdoor();

extern void func_80101FDC(Actor *, s32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void func_80103110(Actor *, s32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern void func_800E148C(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern void func_800FC660(s32);
extern void func_8010A624(Actor *);
extern void func_8010A63C(Actor *);
extern void func_800FFAB0(Actor *);
s32 func_808013C0_chdoor();
void func_8080032C_chdoor(Actor *param_0, f32 param_1);
void func_80800754_chdoor();
void func_808008A0_chdoor();
void func_80800B14_chdoor();

void chdoor_entrypoint_0(s32 actor)
{
    func_80800028_chdoor();
    func_8080050C_chdoor(actor);
}

void func_8080069C_chdoor();

// Per-frame door state machine. States: 1 closed, 2 delay before opening, 3 opening,
// 4 open, 5 delay before closing, 6 closing, 7/8 locked variants.
void func_80800028_chdoor(Actor *actor)
{
    u8 *door;
    s32 cutscene_id;
    f32 open_prev;
    s32 open_done;
    // Matching: unused locals are needed for the match.
    s32 pad[2];
    f32 close_prev;
    s32 close_done;

    door = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            // closed: start opening once the flag or cutscene triggers
            if (*(s32 *) door & 4) {
                if (func_800DA298(*(s16 *) (door + 4))) {
                    func_80800754_chdoor(actor);
                }
            } else {
                cutscene_id = door[0x20];
                if (cutscene_id && _glcutDll_entrypoint_19(cutscene_id)) {
                    func_80800754_chdoor(actor);
                }
            }
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_80800B14_chdoor(actor, 3);
            }
            break;
        case 3:
            // opening: message 0x9D when done
            open_prev = actor->unk58;
            open_done = func_800D9078(&actor->unk58);
            func_8080032C_chdoor(actor,
                                 func_800F12D4(actor->unk58, 0.0f,
                                               *(s16 *) (door + 0xA) * 0.00390625f, 1.0f, 0.0f));
            if (open_prev >= 0.2f && actor->unk58 < 0.2f) {
                func_8080069C_chdoor(actor, 1);
            }
            if (open_done) {
                func_80800B14_chdoor(actor, 4);
                func_8010108C(actor, 0x9D, 0);
            }
            break;
        case 4:
            // open: start closing on flag, cutscene or flag bit 0x400
            if (*(s32 *) door & 2) {
                if (*(s32 *) door & 4) {
                    if (!func_800DA298(*(s16 *) (door + 4))) {
                        func_808008A0_chdoor(actor);
                    }
                } else {
                    cutscene_id = door[0x28];
                    if (cutscene_id && _glcutDll_entrypoint_19(cutscene_id)) {
                        func_808008A0_chdoor(actor);
                    }
                }
                if (*(s32 *) door & 0x400) {
                    func_808008A0_chdoor(actor);
                }
            }
            break;
        case 5:
            if (func_800D9078(&actor->unk58)) {
                func_80800B14_chdoor(actor, 6);
            }
            break;
        case 6:
            // closing: message 0x9E when done
            close_prev = actor->unk58;
            close_done = func_800D9078(&actor->unk58);
            func_8080032C_chdoor(actor,
                                 func_800F12D4(actor->unk58, 0.0f,
                                               *(s16 *) (door + 0xA) * 0.00390625f, 0.0f, 1.0f));
            if (close_prev >= 0.2f && actor->unk58 < 0.2f) {
                func_8080069C_chdoor(actor, 0);
            }
            if (close_done) {
                func_80800B14_chdoor(actor, 1);
                func_8010108C(actor, 0x9E, 0);
            }
    }
}

// Puts the door at open_amount (0 = closed, 1 = open) according to its motion kind.
void func_8080032C_chdoor(Actor *actor, f32 open_amount)
{
    u8 *door;
    f32 closed_pos[3];
    f32 open_pos[3];
    f32 roll_closed_pos[3];
    f32 roll_open_pos[3];
    // Matching: unused local is needed for the match.
    s32 unused_slot1;
    f32 deflect_a[3];
    f32 deflect_b[3];

    door = func_80100094(actor, 0);
    switch (*(u32 *) (door + 8) >> 26) {
        case 1:
            actor->rotation[1] =
                *(s16 *) (door + 0x12) +
                func_800F1DCC(*(s16 *) (door + 0x10), *(s16 *) (door + 0x12)) * open_amount;
            break;
        case 2:
            func_800EE88C(closed_pos, (s16 *) (door + 0x10));
            func_800EE88C(open_pos, (s16 *) (door + 0x16));
            func_800EFE50(actor->position, closed_pos, open_pos, open_amount);
            break;
        case 3:
            actor->rotation[0] =
                *(s16 *) (door + 0x12) +
                func_800F1DCC(*(s16 *) (door + 0x10), *(s16 *) (door + 0x12)) * open_amount;
            break;
        case 4:
            func_800EE88C(roll_closed_pos, (s16 *) (door + 0x10));
            func_800EE88C(roll_open_pos, (s16 *) (door + 0x16));
            func_800EFE50(actor->position, roll_closed_pos, roll_open_pos, open_amount);
            actor->rotation[2] = *(s16 *) (door + 0x1C) * 0.00390625f * open_amount;
            break;
        case 5:
            _subaddiefade_entrypoint_1(actor, (s32) ((1.0f - open_amount) * 255.0f));
    }
    func_80103014(actor);
    if ((*(s32 *) door << 15) < 0) {
        func_80104004(actor, deflect_a, deflect_b);
        _sudeflect_entrypoint_3(actor->position, actor->rotation, deflect_a, deflect_b, 2);
    }
}

// Starts the door's loop sound if it has one.
void func_8080050C_chdoor(Actor *actor)
{
    s32 moving;
    DoorLoopSound *sound;

    moving = 0;
    sound = func_80100094(actor, 0);
    if (actor->unk70_10 == 3 || actor->unk70_10 == 6)
        moving = 1;
    if (sound->unk_2E && (moving || (!moving && actor->unk5F))) {
        func_800C4B7C(sound->unk_2E);
        func_800C4B70(sound->unk_30);
        func_800C4B64((f32) sound->unk_32 * 0.00390625f);
        _subaddieaudioloop_entrypoint_4(actor, actor->position, moving,
                                        (s16 *) D_808015B0_chdoor);
    }
}

// One-shot sound at the start of a motion.
void func_808005E4_chdoor(Actor *actor, s32 opening)
{
    s16 *door;

    door = func_80100094(actor, 0);
    if (door[28] != 0 &&
        ((opening != 0 && door[26] != 0) || (opening == 0 && door[27] != 0))) {
        func_800C4B7C(door[28]);
        func_800C4B70(door[29]);
        func_800C4B64(door[30] * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808015B0_chdoor);
    }
}

// One-shot sound near the end of a motion.
void func_8080069C_chdoor(Actor *actor, s32 opening)
{
    s16 *door;

    door = func_80100094(actor, 0);
    if (door[33] != 0 &&
        ((opening != 0 && door[31] != 0) || (opening == 0 && door[32] != 0))) {
        func_800C4B7C(door[33]);
        func_800C4B70(door[34]);
        func_800C4B64(door[35] * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808015B0_chdoor);
    }
}

// Starts opening (state 2 or 3, 7 when locked) and snaps the door to its closed pose.
void func_80800754_chdoor(actor) Actor *actor;
{
    u8 *door;
    s32 state;
    door = func_80100094(actor, 0);
    if (*(s16 *) (door + 12))
        state = 2;
    else
        state = 3;
    if (func_800DA298(0x9CC, state)) {
        if ((*(u32 *) door & 0x4000) &&
            (!(*(u32 *) door & 0x80) ||
             !func_800DA298(*(u16 *) (door + 0x22) & 0x7FFF, state)))
            state = 7;
        func_80800B14_chdoor(actor, state);
        switch (*(u32 *) (door + 8) >> 26) {
            case 1:
                actor->rotation[1] = *(s16 *) (door + 0x12);
                break;
            case 2:
                func_800EE88C(actor->position, (s16 *) (door + 0x10));
                break;
            case 3:
                actor->rotation[0] = *(s16 *) (door + 0x12);
                break;
            case 4:
                func_800EE88C(actor->position, (s16 *) (door + 0x10));
                actor->rotation[2] = 0.0f;
                break;
            case 5:
                _subaddiefade_entrypoint_1(actor, 255);
                break;
        }
        func_80103014(actor);
    }
}

// Starts closing (state 5 or 6, 8 when locked) and snaps the door to its open pose.
void func_808008A0_chdoor(actor) Actor *actor;
{
    u8 *door = func_80100094(actor, 0);
    s32 state = *(s16 *) (door + 14) ? 5 : 6;

    if ((*(u32 *) door & 0x4000) &&
        (!(*(u32 *) door & 0x80) || !func_800DA298(*(u16 *) (door + 0x2A) & 0x7FFF))) {
        state = 8;
    }
    func_80800B14_chdoor(actor, state);
    switch (*(u32 *) (door + 8) >> 26) {
        case 1:
            actor->rotation[1] = *(s16 *) (door + 0x10);
            break;
        case 2:
            func_800EE88C(actor->position, door + 0x16);
            break;
        case 3:
            actor->rotation[0] = *(s16 *) (door + 0x10);
            break;
        case 4:
            func_800EE88C(actor->position, door + 0x16);
            actor->rotation[2] = *(s16 *) (door + 0x1C) * 0.00390625f;
            break;
        case 5:
            _subaddiefade_entrypoint_1(actor, 0);
    }
    func_80103014(actor);
}

// Player walked through: skips the delay and starts the next motion; reverses one in progress.
void func_808009F4_chdoor(actor) Actor *actor;
{
    u8 *door;
    f32 remaining;
    s16 saved_delay;
    door = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
        case 2:
        case 7:
            saved_delay = *(s16 *) (door + 0xC);
            *(s16 *) (door + 0xC) = 0;
            func_80800754_chdoor(actor);
            *(s16 *) (door + 0xC) = saved_delay;
            break;
        case 6:
            remaining = *(s16 *) (door + 0xA) * 0.00390625f - actor->unk58;
            func_80800B14_chdoor(actor, 3);
            actor->unk58 = remaining;
            break;
        case 3:
            remaining = *(s16 *) (door + 0xA) * 0.00390625f - actor->unk58;
            func_80800B14_chdoor(actor, 6);
            actor->unk58 = remaining;
            break;
        case 4:
        case 5:
        case 8:
            saved_delay = *(s16 *) (door + 0xE);
            *(s16 *) (door + 0xE) = 0;
            func_808008A0_chdoor(actor);
            *(s16 *) (door + 0xE) = saved_delay;
    }
}

void func_80801330_chdoor();

void func_80800FC0_chdoor();

// Enters new_state and runs its entry actions (sounds, camera pod, music, flag).
void func_80800B14_chdoor(actor, new_state) Actor *actor;
s32 new_state;
{
    DoorData *door;
    s32 old_state;
    s32 flag_4;
    s32 flag_8;

    door = func_80100094(actor, 0);
    old_state = actor->unk70_10;
    flag_4 = (door->flags & 4) ? 1 : 0;
    flag_8 = (door->flags & 8) ? 1 : 0;
    if (door->reverse_pending) {
        switch (old_state) {
            case 3:
                func_80101FDC(actor, 6);
                func_80800FC0_chdoor(actor, 1);
                actor->unk58 = door->move_time * 0.00390625f;
                break;
            case 6:
                func_80101FDC(actor, 3);
                if (door->open_delay == 0) {
                    func_80800FC0_chdoor(actor, 0);
                }
                actor->unk58 = door->move_time * 0.00390625f;
        }
        door->reverse_pending = 0;
        return;
    }
    func_80101FDC(actor, new_state);
    switch (new_state) {
        case 1:
            _subaddieaudioloop_entrypoint_2(actor);
            func_80103110(actor, flag_4 | flag_8);
            func_80801330_chdoor(actor, 0);
            if (door->flags & 0x100) {
                func_800E148C(func_800E1610(2, 100.0f, 0.85f, actor->position), 1000.0f, 4000.0f);
                func_80018820(0, 1.0f, 0.4f);
            }
            break;
        case 2:
            func_80800FC0_chdoor(actor, 0);
            actor->unk58 = door->open_delay * 0.00390625f;
            func_80103110(actor, 1);
            break;
        case 3:
            if (door->flags & 0x40) {
                func_800FC660(0x10);
            }
            if (door->open_delay == 0) {
                func_80800FC0_chdoor(actor, 0);
            }
            actor->unk58 = door->move_time * 0.00390625f;
            func_808005E4_chdoor(actor, 1);
            func_80103110(actor, 1);
            func_80801330_chdoor(actor, 1);
            break;
        case 4:
            _subaddieaudioloop_entrypoint_2(actor);
            func_80103110(actor, flag_4 | flag_8);
            if (door->flags & 0x800) {
                func_8010A624(actor);
            }
            if (door->flags & 0x2000) {
                actor->unk64_16 = 0;
            }
            if (door->flags & 1) {
                func_800FFAB0(actor);
            }
            break;
        case 5:
            func_80800FC0_chdoor(actor, 1);
            actor->unk58 = door->close_delay * 0.00390625f;
            func_80103110(actor, 1);
            break;
        case 6:
            if (door->flags & 0x1000) {
                func_800FC660(0x17);
            }
            if (door->close_delay == 0) {
                func_80800FC0_chdoor(actor, 1);
            }
            if (door->flags & 0x800) {
                func_8010A63C(actor);
            }
            if (door->flags & 0x2000) {
                actor->unk64_16 = 1;
            }
            actor->unk58 = door->move_time * 0.00390625f;
            func_808005E4_chdoor(actor, 0);
            func_80103110(actor, 1);
            break;
        case 7:
            func_80800FC0_chdoor(actor, 0);
            func_80103110(actor, flag_8);
            break;
        case 8:
            func_80800FC0_chdoor(actor, 1);
            func_80103110(actor, flag_8);
    }
}

// Triggers the camera pod shot of record index (0 = open, 1 = close).
void func_80800FC0_chdoor(Actor *actor, s32 index)
{
    DoorState *door;

    door = func_80100094(actor, 0);
    if (door->ents[index].active) {
        if ((door->flags & 0x80) && door->ents[index].flag_id) {
            if (!func_800DA9E4(door->ents[index].flag_id, 1)) {
                _capod_entrypoint_13(actor->unk0, 0, door->ents[index].unk_5,
                                     door->ents[index].unk_2);
            }
        } else {
            _capod_entrypoint_13(actor->unk0, 0, door->ents[index].unk_5,
                                 door->ents[index].unk_2);
        }
    }
}

// Message handler: 7 open, 8 close, 0x49 cutscene, 0x6F player walks through.
s32 chdoor_entrypoint_1(Actor *actor, s32 msg, s32 arg)
{
    DoorLocal *door;
    s32 open_id;
    s32 close_id;

    door = func_80100094(actor, 0);
    switch (msg) {
        case 7:
            if (arg != 0 && door->move_time * 0.00390625f == 0.0f) {
                _chdoormake_entrypoint_5(actor, arg);
            }
            switch (actor->unk70_10) {
                case 6:
                    door->reverse_pending = 1;
                    break;
                case 1:
                    func_80800754_chdoor(actor);
            }
            break;
        case 8:
            if (!(door->flags & 2)) {
                return 0;
            }
            switch (actor->unk70_10) {
                case 3:
                    door->reverse_pending = 1;
                    break;
                case 4:
                    func_808008A0_chdoor(actor);
            }
            break;
        case 0x49:
            open_id = door->open_cutscene;
            close_id = door->close_cutscene;
            if (open_id != -1 && _glcutDll_entrypoint_19(open_id)) {
                func_80800754_chdoor(actor);
                return 1;
            }
            if (close_id != -1 && _glcutDll_entrypoint_19(close_id)) {
                func_808008A0_chdoor(actor);
                return 1;
            }
            return 0;
        case 0x6F:
            if (!(door->flags & 0x200)) {
                return 0;
            }
            return func_808013C0_chdoor(actor, arg);
        case 0xE:
            if (!(door->flags & 0x4000)) {
                return 2;
            }
            if (arg == door->unk_21) {
                if (_capod_entrypoint_17(door->unk_24 * 0.00390625f)) {
                    func_80800B14_chdoor(actor, 3);
                }
            } else if (arg == door->unk_29) {
                if (_capod_entrypoint_17(door->unk_2C * 0.00390625f)) {
                    func_80800B14_chdoor(actor, 6);
                }
            }
            return 3;
        default:
            return 0;
    }
    return 1;
}

// Sets or clears the door's game flag (inverted by flags bit 0x10, skipped by 0x20).
void func_80801330_chdoor(Actor *actor, s32 set)
{
    DoorFlagState *door;
    s32 value;
    door = func_80100094(actor, 0);
    if (door->flag_id != -1 && !(door->flags & 0x20)) {
        value = set ? 1 : 0;
        if (door->flags & 0x10)
            func_800DA3B8(door->flag_id, value ? 0 : 1);
        else
            func_800DA3B8(door->flag_id, value);
    }
}

// Tests whether the player crossed the door's line; if so triggers func_808009F4_chdoor.
s32 func_808013C0_chdoor(actor, player)
Actor *actor;
s32 player;
{
    u8 *door;
    f32 player_pos[3];
    f32 door_y;
    f32 segment_a[3];
    f32 segment_b[3];
    f32 unk_0[3];
    f32 dx;
    f32 dz;
    door = func_80100094(actor, 0);
    func_800F5A00(player, player_pos);
    if (*(u32 *) (door + 8) >> 26 == 2)
        door_y = *(s16 *) (door + 0x12);
    else
        door_y = actor->position[1];
    if (mlAbsF(player_pos[1] - door_y) > 100.0f)
        return 0;
    dx = func_800137AC(actor->rotation[1]) * 100.0f;
    dz = func_800137C4() * 100.0f;
    segment_a[0] = actor->position[0] - dx;
    segment_a[2] = actor->position[2] - dz;
    segment_b[0] = actor->position[0] + dx;
    segment_b[2] = actor->position[2] + dz;
    func_800EEB9C(unk_0, func_800F5F24(player), 200.0f);
    func_800EF04C(unk_0, player_pos);
    if (!func_800F0AA4(segment_a, segment_b, player_pos, unk_0))
        return 0;
    func_808009F4_chdoor(actor);
    return 1;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
u8 D_808015B0_chdoor[16] = {0x0, 0x21, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x2,
                            0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
