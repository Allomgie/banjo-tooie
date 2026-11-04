// Solo Kazooie crouch (Z held): slides to a stop with dust, turns in place, plays idle fidgets,
// and offers the transitions to idle, jump, wing whack and egg states.
#include "common.h"
#include "overlays/bs/kaz/crouch.h"

extern f32 mlAbsF(f32);

extern s32 D_808007C0_bskazcrouch[];

void func_80800000_bskazcrouch(PlayerState *self)
{
    baanim_playForDuration_loopSmooth(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f);
    self->unk15C.word = 4;
}

void func_80800034_bskazcrouch(PlayerState *self)
{
    baanim_playForDuration_onceSmooth(self, ASSET_141_ANIM_BSKAZCROUCH_UNKNOWN, 3.5f);
    self->unk15C.word = 2;
}

void func_80800068_bskazcrouch(PlayerState *self)
{
    baanim_playForDuration_onceSmoothStartingAt(self, ASSET_28F_ANIM_BSKAZCROUCH_UNKNOWN, 0.5f,
                                                0.9999f);
    _batimer_set(self, 2, 2.0f);
    self->unk15C.word = 1;
}

void func_808000B4_bskazcrouch(AnimCtrl *anim_ctrl, f32 turn_diff)
{
    anctrl_setDuration(anim_ctrl, func_800F10B4(turn_diff, 0, 180, 0.5, 0.2));
}

void func_808000FC_bskazcrouch(PlayerState *self, s32 unk_0)
{
    func_800A2CE8(self, 0.41f, 4);
    func_800A2CE8(self, 0.91f, 3);
}

// Crouch transitions: Z released -> idle, A -> jump, B -> wing whack, egg buttons -> egg states.
BanjoStateId bskazcrouch_entrypoint_0(PlayerState *self, BanjoStateId next_state)
{
    if (bakey_released(self, BUTTON_Z) != 0) {
        next_state = BS_STATE_BB;
        if (bakey_pressed(self, BUTTON_A) != 0) {
            next_state = _bskaz_entrypoint_3(self);
        }
    } else {
        if ((bakey_pressed(self, BUTTON_B) != 0) && (func_800C6E38(0x28) != 0)) {
            next_state = BS_STATE_C5;
        }
        if (bakey_pressed(self, BUTTON_A) != 0) {
            next_state = _bskaz_entrypoint_3(self);
        }
        if ((bainput_should_poop_egg(self) != 0) && (func_80094B14(self) != 0)) {
            next_state = BS_STATE_68;
        }
        if ((bainput_should_shoot_egg(self) != 0) && (func_80094B14(self) != 0)) {
            next_state = BS_STATE_67;
        }
    }

    return next_state;
}

void bskazcrouch_entrypoint_1(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    f32 unk_0;
    f32 unk_1;
    f32 unk_2;
    f32 anim_start;
    f32 target_yaw;
    s32 prev_state;
    f32 speed;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    prev_state = bs_getPreviousState(self);
    // Coming back from an egg state (0x67/0x68): start the crouch anim late.
    if ((prev_state != 0x67) && (prev_state != 0x68)) {
        anim_start = 0;
    } else {
        anim_start = 0.8;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_A8_ANIM_BSKAZCROUCH_UNKNOWN);
    anctrl_setDuration(anim_ctrl, 0.5);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_setStart(anim_ctrl, anim_start);
    anctrl_start(anim_ctrl);
    func_8008CA4C(self, 1);
    yaw_setUpdateType(self, 3);
    yaw_setVelocityBounded(self, 350.0f, 14.0f);
    func_8009D2D8(self, 7);
    func_8009CFD8(self, 8.0f);
    baphysics_set_type(self, 3);
    _batimer_set(self, 0, 0.7f);
    _batimer_set(self, 1, 0.2f);
    func_8009BB24(self, &unk_2);
    speed = sqrtf((unk_0 * unk_0) + (unk_2 * unk_2));
    self->unk16C = speed;
    if (speed > 140.0f) {
        func_8009D658(self);
    }
    if (func_800F1EA4(&unk_2, &target_yaw) != 0) {
        baphysics_set_target_yaw(self, target_yaw);
    }
    self->unk15C.word = NULL;
}

void bskazcrouch_entrypoint_2(PlayerState *self)
{
    s32 next_state = 0;
    f32 speed;
    AnimCtrl *anim_ctrl;
    f32 turn_diff;
    f32 cur_yaw;
    f32 ideal_yaw;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _batimer_decrement(self, 0);
    _batimer_decrement(self, 1);
    speed = func_800F10B4(_batimer_get(self, 0), 0.0f, 0.3f, 0.0f, self->unk16C);
    baphysics_set_target_horizontal_velocity(self, speed);
    if (speed > 220.0f) {
        _badust_entrypoint_9(self);
    }
    if (speed > 160.0f) {
        func_8009D658(self);
    }
    if (bastick_distance(self) == 0.0f) {
        yaw_setIdeal(self, yaw_get(self));
    }
    ideal_yaw = yaw_getIdeal(self);
    cur_yaw = yaw_get(self);
    turn_diff = mlAbsF(func_800F1DCC(ideal_yaw, cur_yaw));
    // unk15C.word is the sub-phase: 0 slide to a stop, 1/2 idle fidgets, 3/4 turn in place.
    switch (self->unk15C.word) {
        case 0:
            if (speed == 0.0f) {
                _batimer_set(self, 2, 2.0f);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            if (turn_diff != 0.0f) {
                func_80800000_bskazcrouch(self);
            } else {
                _batimer_decrement(self, 2);
                if (_batimer_isZero(self, 2)) {
                    func_80800034_bskazcrouch(self);
                }
            }
            break;
        case 2:
            if (turn_diff != 0.0f) {
                func_80800000_bskazcrouch(self);
            } else if (anctrl_isStopped(anim_ctrl)) {
                func_80800068_bskazcrouch(self);
            }
            break;
        case 4:
            func_808000B4_bskazcrouch(anim_ctrl, turn_diff);
            func_808000FC_bskazcrouch(self, (s32) anim_ctrl);
            if (turn_diff == 0.0f) {
                if (anctrl_getAnimTimer(anim_ctrl) <= 0.5f) {
                    anctrl_setSubrange(anim_ctrl, 0.0f, 0.5f);
                } else {
                    anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                }
                anctrl_setPlaybackType(anim_ctrl, 1);
                self->unk15C.word = 3;
            }
            break;
        case 3:
            func_808000B4_bskazcrouch(anim_ctrl, turn_diff);
            func_808000FC_bskazcrouch(self, (s32) anim_ctrl);
            if (turn_diff != 0.0f) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setPlaybackType(anim_ctrl, 2);
                self->unk15C.word = 4;
            } else if (anctrl_isStopped(anim_ctrl)) {
                yaw_setIdeal(self, yaw_get(self));
                func_80800068_bskazcrouch(self);
            }
    }
    if (func_8008DF18(self)) {
        next_state = _badrone_entrypoint_25(self);
    }
    next_state = bskazcrouch_entrypoint_0(self, next_state);
    if (next_state == 0xBB && _batimer_isNonzero(self, 1)) {
        next_state = 0;
    }
    if (player_inWater(self)) {
        next_state = 0x15D;
    }
    bs_setState(self, next_state);
}

void bskazcrouch_entrypoint_3(PlayerState *self)
{
    _bskaz_entrypoint_2(self);
}

s32 bskazcrouch_entrypoint_4(s32 idx)
{
    return D_808007C0_bskazcrouch[idx];
}

// TU-NOTE: the overlay .data (formerly crouch.data.s) is defined here in C. The table holds
// function pointers from this file; IDO's assembler schedules these functions differently
// unless the table is in the same unit. Values are taken from the ROM.
extern void _bskazcrouch_entrypoint_2();
s32 D_808007C0_bskazcrouch[4] = {(u32) _bskazcrouch_entrypoint_3, (u32) _bskazcrouch_entrypoint_1,
                                 (u32) _bskazcrouch_entrypoint_2, (u32) func_80099B94};
