// Banjo-Kazooie ground locomotion: creep, walk, run and sticky-ground walking, mapping stick zone
// to speed. Also exports the max walk speed and a stick-to-speed helper used by other bs overlays.
#include "common.h"
#include "overlays/bs/walk.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

// TU-NOTE: The .data of this overlay (formerly walk.data.s) is defined here in C. The tables
// hold pointers to functions of this file; IDO's assembler schedules some of them differently
// unless the tables are in the same unit. Values are taken from the ROM.

extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern f32 bastick_distance(void *);
extern f32 yaw_get(void *);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80801520_bswalk[];
extern s32 D_80801530_bswalk[];
extern f32 func_8009BB5C(PlayerState *);
extern s32 D_80801540_bswalk[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80801550_bswalk[];
extern s32 D_80801560_bswalk[];
extern f32 bastick_getZonePosition(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_8009BBB8(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void *func_8008AEDC(AnimCtrl *);
extern f32 func_8008C0C8(void *);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_800A2EDC(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void _badust_entrypoint_3(PlayerState *, f32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FF44(PlayerState *, s32, f32, f32, f32, f32);

// Maps the stick zone to a target horizontal speed (30/80/150/225/500).
void func_80800000_bswalk(player) PlayerState *player;
{
    f32 zone_pos;
    u32 zone;

    zone_pos = bastick_getZonePosition(player);
    zone = bastick_getZone(player);
    if (func_8008DE24(player) && player_isStable(player)) {
        if (zone == 0)
            baphysics_set_target_horizontal_velocity(player, 0.0f);
        else
            baphysics_set_target_horizontal_velocity(
                player, func_800F1214(bastick_distance(player), 30.0f, 150.0f));
        return;
    }
    switch (zone) {
        case 0:
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            break;
        case 1:
            baphysics_set_target_horizontal_velocity(player, func_800F1214(zone_pos, 30.0f, 80.0f));
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(zone_pos, 80.0f, 150.0f));
            break;
        case 3:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(zone_pos, 150.0f, 225.0f));
            break;
        case 4:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(zone_pos, 225.0f, 500.0f));
            break;
    }
}

void func_8080016C_bswalk(player) PlayerState *player;
{
    if (func_8008E1A0(player)) {
        func_8008CA30(player, func_800F10B4(func_8009BBB8(player), 0.0f, 1.0f, 0.5f, 0.9f));
    } else {
        func_8008CA30(player, 1.0f);
    }
}

void func_808001D8_bswalk(void *player, f32 value)
{
    ((f32 *) player)[0x5B] = value;
}

void func_808001E4_bswalk(u8 *player)
{
    f32 delta_time = func_800D8FF8();
    *(f32 *) (player + 0x16C) = func_800F0E00(0.0f, *(f32 *) (player + 0x16C) - delta_time);
}

int func_80800220_bswalk(struct Actor *actor)
{
    return *(f32 *) ((char *) actor + 0x16C) == 0.0f;
}

s32 func_80800248_bswalk(PlayerState *player, s32 next_state)
{
    if (bakey_pressed(player, 9)) {
        if (baphysics_get_target_horizontal_velocity(player) > 225.0f) {
            next_state = func_800A04F4(player, next_state);
        } else
            next_state = func_800A055C(player, next_state);
    }
    return next_state;
}

// Max walk speed, queried by the player API.
f32 bswalk_entrypoint_0(s32 player)
{
    return 500.0f;
}

// Matching: the call without arguments is needed for the match.
void bswalk_entrypoint_1()
{
    func_80800000_bswalk();
}

void bswalk_entrypoint_2(s32 player)
{
    func_800A2EDC(player, 1.0f);
    if (func_8008E0E8(player) != 0) {
        _bapackctrl_entrypoint_5(player, 3);
    }
}

// Creep (slow walk) init.
void bswalk_entrypoint_3(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 start_time;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (bs_getPreviousState(player) == 2) {
        start_time = func_8008C0C8(func_8008AEDC(anim_ctrl));
    } else {
        start_time = 0.0f;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 2);
    anctrl_setDuration(anim_ctrl, 0.43f);
    anctrl_setStart(anim_ctrl, start_time);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 80.0f, 1.8f, 1.2f);
    bastick_resetZones(player);
    func_800A2EDC(player, 0.2f);
    if (func_8008E0E8(player)) {
        _bapackctrl_entrypoint_5(player, 2);
    }
}

void bswalk_entrypoint_4(void *player)
{
    s32 next_state;
    next_state = 0;
    func_8080016C_bswalk(player);
    if (bastick_distance(player) == 0.0f) {
        yaw_setIdeal(player, yaw_get(player));
    }
    func_800A2CE8(player, 0.47f, 4);
    func_800A2CE8(player, 0.97f, 3);
    func_80800000_bswalk(player);
    switch (bastick_getZone(player)) {
        case 0:
            if (func_8009BCD4(player, 1.0f)) {
                next_state = 1;
            }
            break;
        case 2:
            next_state = 2;
            break;
        case 3:
            next_state = 3;
            break;
        case 4:
            next_state = 4;
    }
    if (func_8008DE24(player)) {
        next_state = 0x7A;
    }
    if (bainput_should_enter_first_person(player)) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    if (bakey_held(player, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(player, next_state);
    if (bakey_pressed(player, 8)) {
        next_state = bs_getTypeOfJump(player);
        if (baphysics_get_target_horizontal_velocity(player) == 0.0f) {
            if (func_8008D714(player)) {
                next_state = 0xB8;
            } else if (func_8008D790(player)) {
                _baduo_entrypoint_12(player);
                return;
            }
        }
    }
    if (func_8008E148(player)) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    bs_setState(player, func_800A02DC(player, next_state));
}

int bswalk_entrypoint_5(s32 index)
{
    return D_80801520_bswalk[index];
}

// Walk init.
void bswalk_entrypoint_6(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 start_time;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (bs_getPreviousState(player) == 3)
        start_time = func_8008C0C8(func_8008AEDC(anim_ctrl));
    else
        start_time = 0.0f;
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 3);
    anctrl_setDuration(anim_ctrl, 0.43f);
    anctrl_setStart(anim_ctrl, start_time);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 80.0f, 150.0f, 1.3f, 0.6f);
    bastick_resetZones(player);
    if (func_8008E0E8(player))
        _bapackctrl_entrypoint_5(player, 2);
}

void bswalk_entrypoint_7(void *player)
{
    s32 next_state;
    next_state = 0;
    func_8080016C_bswalk(player);
    if (bastick_distance(player) == 0.0f) {
        yaw_setIdeal(player, yaw_get(player));
    }
    func_800A2CE8(player, 0.4f, 4);
    func_800A2CE8(player, 0.9f, 3);
    func_80800000_bswalk(player);
    switch (bastick_getZone(player)) {
        case 0:
            if (func_8009BCD4(player, 3.0f)) {
                next_state = 1;
            }
            break;
        case 1:
            next_state = 0x1F;
            break;
        case 3:
            next_state = 3;
            break;
        case 4:
            next_state = 4;
    }
    if (func_8008DE24(player)) {
        next_state = 0x7A;
    }
    if (bainput_should_enter_first_person(player)) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    if (bakey_held(player, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(player, next_state);
    if (bakey_pressed(player, 8)) {
        next_state = bs_getTypeOfJump(player);
        if (baphysics_get_target_horizontal_velocity(player) == 0.0f) {
            if (func_8008D714(player)) {
                next_state = 0xB8;
            } else if (func_8008D790(player)) {
                _baduo_entrypoint_12(player);
                return;
            }
        }
    }
    if (func_8008E148(player)) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    bs_setState(player, func_800A02DC(player, next_state));
}

s32 bswalk_entrypoint_8(s32 player)
{
    if (func_8008E0E8()) {
        _bapackctrl_entrypoint_5(player, 3);
    }
}

int bswalk_entrypoint_9(s32 index)
{
    return D_80801530_bswalk[index];
}

// Fast walk init.
void bswalk_entrypoint_10(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 start_time;
    s32 prev_state;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    prev_state = bs_getPreviousState(player);
    if (prev_state != 2 && prev_state != 4)
        start_time = 0.0f;
    else
        start_time = func_8008C0C8(func_8008AEDC(anim_ctrl));
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0xC);
    anctrl_setDuration(anim_ctrl, 0.66f);
    func_8008B1C8(anim_ctrl, 0.14f);
    anctrl_setStart(anim_ctrl, start_time);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 150.0f, 225.0f, 0.92f, 0.58f);
    func_808001D8_bswalk(player, 0.3f);
    bastick_resetZones(player);
    if (func_8008E0E8(player))
        _bapackctrl_entrypoint_5(player, 2);
}

void bswalk_entrypoint_11(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_8080016C_bswalk(player);
    func_800A2CE8(player, 0.4f, 4);
    func_800A2CE8(player, 0.9f, 3);
    func_808001E4_bswalk(player);
    func_80800000_bswalk(player);
    switch (bastick_getZone(player)) {
        case 0:
        case 1:
        case 2:
            if (func_8009BCD4(player, 150.0f) && func_80800220_bswalk(player)) {
                next_state = 2;
            }
            break;
        case 4:
            next_state = 4;
    }
    if (func_8008DE24(player)) {
        next_state = 0x7A;
    }
    if (func_8008E300(player) && func_8009BB5C(player) > 125.0f) {
        next_state = 12;
    }
    if (bainput_should_enter_first_person(player)) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    if (bakey_held(player, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(player, next_state);
    if (bakey_pressed(player, 8)) {
        next_state = bs_getTypeOfJump(player);
        if (baphysics_get_target_horizontal_velocity(player) == 0.0f) {
            if (func_8008D714(player)) {
                next_state = 0xB8;
            } else if (func_8008D790(player)) {
                _baduo_entrypoint_12(player);
                return;
            }
        }
    }
    if (func_8008E148(player)) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    bs_setState(player, func_800A02DC(player, next_state));
}

s32 bswalk_entrypoint_12(s32 player)
{
    if (func_8008E0E8()) {
        _bapackctrl_entrypoint_5(player, 3);
    }
}

int bswalk_entrypoint_13(s32 index)
{
    return D_80801540_bswalk[index];
}

// Run init (with roll lean).
void bswalk_entrypoint_14(PlayerState *player)
{
    void *anim_ctrl;
    f32 start_time;
    s32 smooth;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    start_time = 0.0f;
    smooth = 1;
    switch (bs_getPreviousState(player)) {
        case 1:
        case 2:
            if (func_8009BB5C(player) < 200.0f)
                _badust_entrypoint_3(player, 0.0f, 0.0f);
            break;
        case 12:
            smooth = 0;
            break;
        case 3:
            start_time = func_8008C0C8(func_8008AEDC(anim_ctrl));
            break;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, smooth);
    anctrl_setIndex(anim_ctrl, 12);
    anctrl_setDuration(anim_ctrl, 0.66f);
    func_8008B1C8(anim_ctrl, 0.1f);
    anctrl_setStart(anim_ctrl, start_time);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 225.0f, 500.0f, 0.54f, 0.44f);
    func_8009BFE4(player, 1000.0f, 12.0f);
    baroll_setAngularVelocity(player, 1000.0f, 12.0f);
    func_808001D8_bswalk(player, 0.3f);
    bastick_resetZones(player);
    if (func_8008E0E8(player))
        _bapackctrl_entrypoint_5(player, 2);
}

void bswalk_entrypoint_15(PlayerState *player)
{
    extern void func_8009D2F0(PlayerState *, s32, f32);
    s32 next_state;
    next_state = 0;
    func_8080016C_bswalk(player);
    func_8009D2F0(player, 0, 0.5f);
    func_800A2CE8(player, 0.4f, 4);
    func_800A2CE8(player, 0.9f, 3);
    func_808001E4_bswalk(player);
    func_80800000_bswalk(player);
    switch (bastick_getZone(player)) {
        case 0:
            if (func_8009BCD4(player, 18.0f)) {
                next_state = 1;
            }
            if (bainput_should_enter_first_person(player)) {
                next_state = _badrone_entrypoint_24(player);
            }
            break;
        case 1:
        case 2:
            if (func_8009BCD4(player, 150.0f)) {
                next_state = 2;
            }
            if (bainput_should_enter_first_person(player)) {
                next_state = _badrone_entrypoint_24(player);
            }
            break;
        case 3:
            if (func_8009BCD4(player, 225.0f) && func_80800220_bswalk(player)) {
                next_state = 3;
            }
            if (bainput_should_enter_first_person(player)) {
                next_state = _badrone_entrypoint_24(player);
            }
    }
    if (func_8008DE24(player)) {
        next_state = 0x7A;
    }
    if (func_8008E300(player) && func_8009BB5C(player) > 125.0f) {
        next_state = 0xC;
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    if (bakey_held(player, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(player, next_state);
    if (bakey_pressed(player, 8)) {
        next_state = bs_getTypeOfJump(player);
        if (baphysics_get_target_horizontal_velocity(player) == 0.0f) {
            if (func_8008D714(player)) {
                next_state = 0xB8;
            } else if (func_8008D790(player)) {
                _baduo_entrypoint_12(player);
                return;
            }
        }
    }
    if (func_8008E148(player)) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    bs_setState(player, func_800A02DC(player, next_state));
}

void bswalk_entrypoint_16(s32 player)
{
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
    if (func_8008E0E8(player) != 0) {
        _bapackctrl_entrypoint_5(player, 3);
    }
}

int bswalk_entrypoint_17(s32 index)
{
    return D_80801550_bswalk[index];
}

void bswalk_entrypoint_18(s32 player)
{
}

// Walking through sticky/slow ground init.
void bswalk_entrypoint_19(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, 0xB, 0.43f);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 150.0f, 1.2f, 0.9f);
}

void bswalk_entrypoint_20(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_8080016C_bswalk(player);
    func_800A2CE8(player, 0.4f, 4);
    func_800A2CE8(player, 0.9f, 3);
    func_80800000_bswalk(player);
    if (!func_8008DE24(player)) {
        next_state = 2;
    }
    if (!bastick_getZone(player)) {
        next_state = 1;
    }
    if (bainput_should_enter_first_person(player)) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    if (bakey_held(player, 1)) {
        next_state = 7;
    }
    next_state = func_80800248_bswalk(player, next_state);
    if (bakey_pressed(player, 8)) {
        next_state = bs_getTypeOfJump(player);
    }
    if (func_8008E148(player)) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    bs_setState(player, func_800A02DC(player, next_state));
}

int bswalk_entrypoint_21(s32 index)
{
    return D_80801560_bswalk[index];
}

// Picks the walk or run animation by speed.
void bswalk_entrypoint_22(PlayerState *player, f32 speed)
{
    if (speed < 150.0f) {
        func_8009FF44(player, 3, 80.0f, 150.0f, 1.3f, 0.6f);
    } else {
        func_8009FF44(player, 12, 225.0f, 500.0f, 0.54f, 0.44f);
    }
}

extern void _bswalk_entrypoint_2();
extern void _bswalk_entrypoint_3();
extern void _bswalk_entrypoint_4();
extern void func_8009AB78();
extern void _bswalk_entrypoint_8();
extern void _bswalk_entrypoint_6();
extern void _bswalk_entrypoint_7();
extern void _bswalk_entrypoint_12();
extern void _bswalk_entrypoint_10();
extern void _bswalk_entrypoint_11();
extern void _bswalk_entrypoint_16();
extern void _bswalk_entrypoint_14();
extern void _bswalk_entrypoint_15();
extern void _bswalk_entrypoint_18();
extern void _bswalk_entrypoint_19();
extern void _bswalk_entrypoint_20();
extern void func_80099B94();
s32 D_80801520_bswalk[4] = {(u32) _bswalk_entrypoint_2, (u32) _bswalk_entrypoint_3,
                            (u32) _bswalk_entrypoint_4, (u32) func_8009AB78};
s32 D_80801530_bswalk[4] = {(u32) _bswalk_entrypoint_8, (u32) _bswalk_entrypoint_6,
                            (u32) _bswalk_entrypoint_7, (u32) func_8009AB78};
s32 D_80801540_bswalk[4] = {(u32) _bswalk_entrypoint_12, (u32) _bswalk_entrypoint_10,
                            (u32) _bswalk_entrypoint_11, (u32) func_8009AB78};
s32 D_80801550_bswalk[4] = {(u32) _bswalk_entrypoint_16, (u32) _bswalk_entrypoint_14,
                            (u32) _bswalk_entrypoint_15, (u32) func_8009AB78};
s32 D_80801560_bswalk[4] = {(u32) _bswalk_entrypoint_18, (u32) _bswalk_entrypoint_19,
                            (u32) _bswalk_entrypoint_20, (u32) func_80099B94};
