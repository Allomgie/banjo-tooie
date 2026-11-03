#include "common.h"
#include "overlays/bs/kaz/move.h"

// Speed range for the current shoe type.
void func_80800000_bskazmove(PlayerState *self, f32 *out_min, f32 *out_max)
{
    switch (_bashoes_entrypoint_1(self)) {
        case 3:
            *out_min = 250.0f;
            *out_max = 1200.0f;
            return;
        case 4:
            *out_min = 250.0f;
            *out_max = 800.0f;
            return;
        case 5:
            *out_min = 250.0f;
            *out_max = 800.0f;
    }
}

// Maps the stick position to a target horizontal velocity.
void bskazmove_entrypoint_0(PlayerState *self)
{
    s32 has_shoes;
    f32 value;
    f32 max;
    f32 min;
    s32 zone;

    // Matching: taking the address of self forces it onto the stack.
    if (&self) {
    }

    value = bastick_getZonePosition(self);
    zone = bastick_getZone(self);
    has_shoes = func_8008E39C(self);
    switch (zone) {
        case BS_STICK_ZONE_ID_0:
            value = 0;
            max = 0;
            min = 0;
            break;

        case BS_STICK_ZONE_ID_1:
            if (has_shoes != 0) {
                func_80800000_bskazmove(self, &min, &max);
                value = value * 0.5f;
            } else {
                min = 80;
                max = 250;
            }
            break;

        case BS_STICK_ZONE_ID_2:
            if (has_shoes != 0) {
                func_80800000_bskazmove(self, &min, &max);
                value = (value * 0.5f) + 0.5f;
            } else {
                min = 250;
                max = 800;
            }
    }

    baphysics_set_target_horizontal_velocity(self, func_800F1214(value, min, max));
}

BanjoStateId func_808001C4_bskazmove(PlayerState *self, BanjoStateId next_state)
{
    if (func_8008E39C(self) != 0) {
        return next_state;
    }

    if (baphysics_get_target_horizontal_velocity(self) > 80.0f) {
        if (bainput_func_80097FB8(self) != 0) {
            next_state = BS_STATE_C4;
        }
    } else if (bainput_func_80097FB8(self) != 0) {
        next_state = _bskaz_entrypoint_4(self);
    }
    return next_state;
}

void func_8080025C_bskazmove(PlayerState *self)
{
    if (bakey_pressed(self, BUTTON_B) != 0) {
        _bashoes_entrypoint_6(self, 2);
    }
}

void bskazmove_entrypoint_1(PlayerState *self)
{
    _bskaz_entrypoint_2(self);
}

void bskazmove_entrypoint_2(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    f32 anim_timer;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    if (bs_getPreviousState(self) == 0xC7) {
        anim_timer = baanim_getTimer(self);
    } else {
        anim_timer = 0.0f;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_A7_ANIM_BSKAZMOVE_UNKNOWN);
    anctrl_setDuration(anim_ctrl, 0.43);
    anctrl_setStart(anim_ctrl, anim_timer);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, 2, 1, 1, 2);
    baanim_setDurationRange(self, 0.3, 1.5);
    func_8008C9F0(self, 80, 250, 1.3, 0.45f);
    func_8008CA30(self, 1);
}

void bskazmove_entrypoint_3(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    func_800A2CE8(self, 0.47, 4);
    func_800A2CE8(self, 0.97, 3);
    bskazmove_entrypoint_0(self);
    switch (bastick_getZone(self)) {
        case BS_STICK_ZONE_ID_0:
            if (func_8009BCD4(self, 3) != 0) {
                next_state = BS_STATE_BB;
            }
            break;
        case BS_STICK_ZONE_ID_2:
            next_state = BS_STATE_C7;
    }

    if (func_8008E39C(self) != 0) {
        next_state = BS_STATE_C7;
    }

    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_DF;
    }

    if ((bakey_held(self, 1) != 0) && (func_8008E39C(self) == 0)) {
        next_state = BS_STATE_DD;
    }

    if (func_8008E39C(self) != 0) {
        func_8080025C_bskazmove(self);
    } else {
        next_state = func_808001C4_bskazmove(self, next_state);
    }

    if (bakey_pressed(self, 8) != 0) {
        next_state = _bskaz_entrypoint_3(self);
        if ((baphysics_get_target_horizontal_velocity(self) == 0.0f) &&
            (func_8008D790(self) != 0)) {
            _baduo_entrypoint_12(self);
            return;
        }
    }

    if (func_8008DF18(self) != 0) {
        next_state = _badrone_entrypoint_25(self);
    }

    if (player_inWater(self) != 0) {
        next_state = BS_STATE_15D;
    }

    bs_setState(self, func_800A02DC(self, next_state));
}

s32 bskazmove_entrypoint_4(s32 idx)
{
    return D_80800C70_bskazmove[idx];
}

void bskazmove_entrypoint_5(PlayerState *self, s32 shoe_type)
{
    s32 anim_index;
    s32 pad0;
    f32 anim_timer;
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    anim_timer = baanim_getTimer(self);
    switch (shoe_type) {
        case 3:
            anim_index = ASSET_A6_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 1200.0f, 0.54, 0.35f);
            break;
        case 4:
            anim_index = ASSET_24F_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 800.0f, 0.8, 0.4f);
            break;
        case 5:
            anim_index = ASSET_24D_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 800.0f, 1.1, 0.7f);
            break;
        default:
            anim_index = ASSET_A6_ANIM_BSKAZMOVE_UNKNOWN;
            func_8008C9F0(self, 250.0f, 800.0f, 0.54, 0.35f);
    }

    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, anim_index);
    anctrl_setDuration(anim_ctrl, 1);
    func_8008B1C8(anim_ctrl, 0.1);
    anctrl_setStart(anim_ctrl, anim_timer);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8008CA30(self, 1);
    baanim_setDurationRange(self, 0.3, 1.5);
}

void func_80800754_bskazmove(PlayerState *self)
{
    s32 shoe_type;

    shoe_type = _bashoes_entrypoint_1(self);
    if (shoe_type != self->unk15C.word) {
        self->unk15C.word = shoe_type;
        bskazmove_entrypoint_5(self, shoe_type);
    }
}

void bskazmove_entrypoint_6(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    f32 footstep_b;
    f32 footstep_a;
    s32 unk_0;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    unk_0 = 1;
    footstep_b = 0.7781f;
    footstep_a = 0.2781f;
    switch (_bashoes_entrypoint_1(self)) {
        case 3:
            _bashoes_entrypoint_20(self);
            break;
        case 4:
            unk_0 = 0;
            break;
        case 5:
            footstep_b = 0.1;
            footstep_a = 0.58;
            if (anctrl_isAt(anim_ctrl, footstep_a) != 0) {
                _bashoes_entrypoint_19(self);
            }
            if (anctrl_isAt(anim_ctrl, footstep_b) != 0) {
                _bashoes_entrypoint_18(self);
            }
            break;
        default:
            if ((anctrl_isAt(anim_ctrl, 0.2115f) != 0) || (anctrl_isAt(anim_ctrl, 0.7115f) != 0)) {
                _badust_entrypoint_1(self);
            }
    }

    if (unk_0 != 0) {
        func_800A2CE8(self, footstep_a, 4);
        func_800A2CE8(self, footstep_b, 3);
        return;
    }

    func_800A2D2C(self, footstep_a, 4);
    func_800A2D2C(self, footstep_b, 3);
}

void bskazmove_entrypoint_7(PlayerState *self)
{
    func_8009BF5C(self, 0);
    baroll_setIdeal(self, 0);
    _bskaz_entrypoint_2(self);
}

void bskazmove_entrypoint_8(PlayerState *self)
{
    _bskaz_entrypoint_1(self);
    if ((bs_getPreviousState(self) == 0xBC) && (func_8009BB5C(self) < 200.0f)) {
        _badust_entrypoint_3(self, 0.0f, 0.0f);
    }
    self->unk15C.word = 0;
    func_80800754_bskazmove(self);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8009BFE4(self, 1000, 12);
    baroll_setAngularVelocity(self, 1000, 12);
}

void bskazmove_entrypoint_9(PlayerState *self)
{
    BanjoStateId next_state;
    s32 has_shoes;

    next_state = BS_STATE_0_INVALID;
    has_shoes = func_8008E39C(self);
    func_80800754_bskazmove(self);
    bskazmove_entrypoint_6(self);
    func_8009D2F0(self, 0, 0.5);
    bskazmove_entrypoint_0(self);
    switch (bastick_getZone(self)) {
        case BS_STICK_ZONE_ID_0:
            if (func_8009BCD4(self, 18) != 0) {
                next_state = BS_STATE_BB;
            }
            break;
        case BS_STICK_ZONE_ID_1:
            if ((has_shoes == 0) && (func_8009BCD4(self, 250) != 0)) {
                next_state = BS_STATE_BC;
            }
    }

    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_DF;
    }

    if ((bakey_held(self, 1) != 0) && (func_8008E39C(self) == 0)) {
        next_state = BS_STATE_DD;
    }

    if (has_shoes != 0) {
        func_8080025C_bskazmove(self);
    } else {
        next_state = func_808001C4_bskazmove(self, next_state);
    }

    if (bakey_pressed(self, BUTTON_A) != 0) {
        next_state = _bskaz_entrypoint_3(self);
        if ((baphysics_get_target_horizontal_velocity(self) == 0.0f) &&
            (func_8008D790(self) != 0)) {
            _baduo_entrypoint_12(self);
            return;
        }
    }

    if (func_8008DF18(self) != 0) {
        next_state = _badrone_entrypoint_25(self);
    }

    if (player_inWater(self) != 0) {
        next_state = BS_STATE_15D;
    }

    bs_setState(self, func_800A02DC(self, next_state));
}

s32 bskazmove_entrypoint_10(s32 idx)
{
    return D_80800C80_bskazmove[idx];
}

void bskazmove_entrypoint_11(PlayerState *self, s32 shoe_type)
{
    if ((shoe_type == 3) && (bastick_getZone(self) == BS_STICK_ZONE_ID_2) &&
        (bastick_getZonePosition(self) > 0.8f)) {
        func_800962B0(self, 1);
        return;
    }
    func_800962B0(self, 0);
}

// TU-NOTE: the overlay .data tables are defined here so IDO schedules the functions above the
// same way as the original; values are taken from the ROM.
extern void _bskazshoessuckspline_entrypoint_0();
s32 D_80800C70_bskazmove[4] = {(u32) _bskazmove_entrypoint_1, (u32) _bskazmove_entrypoint_2,
                               (u32) _bskazmove_entrypoint_3,
                               (u32) _bskazshoessuckspline_entrypoint_0};
s32 D_80800C80_bskazmove[4] = {(u32) _bskazmove_entrypoint_7, (u32) _bskazmove_entrypoint_8,
                               (u32) _bskazmove_entrypoint_9,
                               (u32) _bskazshoessuckspline_entrypoint_0};
