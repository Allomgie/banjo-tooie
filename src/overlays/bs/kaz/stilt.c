#include "common.h"
#include "overlays/bs/kaz/stilt.h"

extern s32 D_80801200_bskazstilt[];
extern s32 D_80801210_bskazstilt[];
extern s32 D_80801220_bskazstilt[];
extern s32 D_80801230_bskazstilt[];
extern s32 D_80801240_bskazstilt[];
extern s32 D_80801250_bskazstilt[];
extern s32 D_80801260_bskazstilt[];
extern s32 D_80801270_bskazstilt[];

s32 func_80800000_bskazstilt(PlayerState *self)
{
    return player_inWater(self);
}

void func_80800020_bskazstilt(PlayerState *self, s32 arg1)
{
    if (arg1 != 0) {
        func_8009DE38(self, 0x4433, 0.88);
        return;
    }
    func_8009DE38(self, 0x4433, 0.96);
}

void func_80800064_bskazstilt(PlayerState *self)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, func_800F1214(stick_pos, 80.0f, 500.0f));
}

// Ticks the long-leg alarm and plays a sound when the timer runs out.
void func_808000C8_bskazstilt(PlayerState *self)
{
    s32 pad0;
    f32 prev_time;

    prev_time = bastatetimer_getPrevious(self, BA_STATE_TIMER_ID_2_LONGLEG);
    _baalarm_entrypoint_3(self, prev_time, bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG));
    if (bastatetimer_isAt(self, BA_STATE_TIMER_ID_2_LONGLEG, 0.01f) != 0) {
        func_8009DE38(self, 0x3EB, 1);
    }
}

// Common enter: collision spheres, stick zones and the alarm.
void func_8080013C_bskazstilt(PlayerState *self)
{
    if (func_8009E77C(self, 8) == 0) {
        _bskaz_entrypoint_1(self);
        baflag_clear(self, BA_FLAG_E_TOUCHING_WADING_BOOTS);
        func_8009E4AC(self);
        func_8009E5A4(self, 1, 1);
        func_8009E55C(self, 1, 40);
        func_8009E53C(self, 1, -50);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.03f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800A0CF4(self, 1);
        func_800A0CE8(self, 1);
        func_800A0DD0(self, 1);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        _baalarm_new(self);
    }
}

// Common exit: undoes the enter setup and clears the long-leg timer.
void func_80800234_bskazstilt(PlayerState *self)
{
    if (func_8009E74C(self, 8) == 0) {
        _baalarm_free(self);
        func_8009E474(self);
        bastick_popZone(self);
        func_800A0CF4(self, 0);
        func_800A0CE8(self, 0);
        func_800A0DD0(self, 0);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        bastatetimer_clear(self, BA_STATE_TIMER_ID_2_LONGLEG);
        func_800C77DC(1);
        _batimer_incrementBy(self, 4, 0.5);
        func_808000C8_bskazstilt(self);
        _bskaz_entrypoint_2(self);
    }
}

void bskazstilt_entrypoint_0(PlayerState *self)
{
    func_8080013C_bskazstilt(self);
    baanim_playForDuration_once(self, ASSET_27F_ANIM_BSKAZSTILT_UNKNOWN, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    bastatetimer_set(self, BA_STATE_TIMER_ID_2_LONGLEG, func_800A3394(self));
    func_800C77DC(2);
    self->unk160.bytes[0] = func_800C2E04();
    func_800C301C(self->unk160.bytes[0], 0x41D);
    func_800C330C(self->unk160.bytes[0], 3);
    func_800C3730(self->unk160.bytes[0], 0.8, 1.9, 1.2);
    func_800C3BDC(self->unk160.bytes[0]);
}

void bskazstilt_entrypoint_1(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_808000C8_bskazstilt(self);
    func_8009D2F0(self, 1, 0.5f);
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_48;
    }
    bs_setState(self, next_state);
}

void bskazstilt_entrypoint_2(PlayerState *self)
{
    func_80800234_bskazstilt(self);
    func_800C2FDC(self->unk160.bytes[0]);
}

s32 bskazstilt_entrypoint_3(s32 idx)
{
    return D_80801200_bskazstilt[idx];
}

void bskazstilt_entrypoint_4(PlayerState *self)
{
    baanim_playForDuration_loopSmooth(self, ASSET_149_ABIM_BSKAZSTILT_UNKNOWN, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8080013C_bskazstilt(self);
}

void bskazstilt_entrypoint_5(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_808000C8_bskazstilt(self);
    func_8009D2F0(self, 1, 0.5f);
    if (bainput_should_enter_first_person(self) != 0) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (bakey_pressed(self, BUTTON_B) != 0) {
        bastatetimer_clear(self, BA_STATE_TIMER_ID_2_LONGLEG);
    }
    if (bastick_getZone(self) > BS_STICK_ZONE_ID_0) {
        next_state = BS_STATE_49;
    }
    if (func_8008DF18(self) != 0) {
        next_state = BS_STATE_4D;
    }
    if ((bakey_pressed(self, BUTTON_A) != 0) && (player_isStable(self) != 0)) {
        next_state = BS_STATE_4A;
    }
    if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0) {
        next_state = BS_STATE_4B;
    }
    if (func_80800000_bskazstilt(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazstilt_entrypoint_6(PlayerState *self)
{
    func_80800234_bskazstilt(self);
}

s32 bskazstilt_entrypoint_7(s32 idx)
{
    return D_80801210_bskazstilt[idx];
}

void bskazstilt_entrypoint_8(PlayerState *self)
{
    baanim_playForDuration_loopSmooth(self, 0x280, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_2_SCALE_HORZ, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_8008C9F0(self, 80.0f, 500.0f, 1.0f, 0.8f);
}

void bskazstilt_entrypoint_9(PlayerState *self)
{
    BanjoStateId next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_808000C8_bskazstilt(self);
    func_8009D2F0(self, 1, 0.5f);
    func_800A2CE8(self, 0.47f, 4);
    func_800A2CE8(self, 0.97f, 3);
    if (anctrl_isAt(anim_ctrl, 0.7781f) != 0) {
        func_80800020_bskazstilt(self, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2781f) != 0) {
        func_80800020_bskazstilt(self, 1);
    }
    func_80800064_bskazstilt(self);
    if ((bakey_pressed(self, BUTTON_B) != 0) &&
        (baphysics_get_target_horizontal_velocity(self) == 0.0f)) {
        bastatetimer_clear(self, BA_STATE_TIMER_ID_2_LONGLEG);
    }
    if ((bastick_getZone(self) == BS_STICK_ZONE_ID_0) && (func_8009BCD4(self, 1.0f) != 0)) {
        next_state = BS_STATE_48;
    }
    if (func_8008DF18(self) != 0) {
        next_state = BS_STATE_4D;
    }
    if ((bakey_pressed(self, BUTTON_A) != 0) && (player_isStable(self) != 0)) {
        next_state = BS_STATE_4A;
    }
    if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0) {
        next_state = BS_STATE_4B;
    }
    if (func_80800000_bskazstilt(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazstilt_entrypoint_10(PlayerState *self)
{
    func_80800234_bskazstilt(self);
}

s32 bskazstilt_entrypoint_11(s32 idx)
{
    return D_80801220_bskazstilt[idx];
}

void bskazstilt_entrypoint_12(PlayerState *self)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    func_8008B188(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x27F);
    anctrl_setDuration(anim_ctrl, 0.4f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    self->unk160.bytes[0] = func_800C2E04();
    func_800C301C(self->unk160.bytes[0], 0x41D);
    func_800C330C(self->unk160.bytes[0], 3);
    func_800C3730(self->unk160.bytes[0], 1.4, 0.4, -1.2);
}

void bskazstilt_entrypoint_13(PlayerState *self)
{
    BanjoStateId next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_8009D3A8(self, 1);
    if (anctrl_isAt(anim_ctrl, 0.68f) != 0) {
        func_800C3BDC(self->unk160.bytes[0]);
    }
    if (anctrl_isStopped(anim_ctrl) != 0) {
        next_state = BS_STATE_BB;
    }
    if (func_80800000_bskazstilt(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazstilt_entrypoint_14(PlayerState *self)
{
    func_800C2FDC(self->unk160.bytes[0]);
    func_80800234_bskazstilt(self);
}

s32 bskazstilt_entrypoint_15(s32 idx)
{
    return D_80801230_bskazstilt[idx];
}

void bskazstilt_entrypoint_16(PlayerState *self)
{
    f32 ideal_yaw[3];
    AnimCtrl *anim_ctrl_1;
    AnimCtrl *anim_ctrl_2;
    AnimCtrl *anim_ctrl_3;

    anim_ctrl_3 = baanim_getAnimCtrlPtr(self);
    anim_ctrl_2 = anim_ctrl_3;
    anim_ctrl_1 = anim_ctrl_3;
    self->unk16C = 0.14f;
    anctrl_reset(anim_ctrl_1);
    anctrl_setIndex(anim_ctrl_2, ASSET_14A_ANIM_BSKAZSTILT_UNKNOWN);
    func_8008B1C8(anim_ctrl_2, 0.134f);
    anctrl_setDuration(anim_ctrl_2, 1.0f);
    anctrl_setStart(anim_ctrl_2, self->unk16C);
    anctrl_setSubrange(anim_ctrl_2, 0.0f, 0.42f);
    anctrl_setPlaybackType(anim_ctrl_2, 1);
    anctrl_start(anim_ctrl_2);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    func_80800064_bskazstilt(self);
    ideal_yaw[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, ideal_yaw[0],
                                      baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 400.0f);
    baphysics_set_gravity(self, -800.0f);
    func_8009DE38(self, 0x4432, 0.9f);
    self->unk15C.word = 0;
}

void bskazstilt_entrypoint_17(PlayerState *self)
{
    BanjoStateId next_state;
    AnimCtrl *anim_ctrl;
    s32 pad0;
    f32 vel_y;
    f32 vel_x;
    f32 height_delta;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_808000C8_bskazstilt(self);
    func_80800064_bskazstilt(self);
    func_8009BB24(self, &vel_x);
    if ((bakey_released(self, BUTTON_A) != 0) && (vel_y > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    height_delta = func_8009C150(self) - func_80096364(self);
    switch (self->unk15C.word) {
        case 0:
            if ((vel_y < 100.0f) || (height_delta < 10.0f)) {
                anctrl_setDuration(anim_ctrl, 0.4f);
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.5282f);
                anctrl_setDuration(anim_ctrl, 4.5f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            if ((anctrl_getAnimTimer(anim_ctrl) > 0.4f) && (height_delta < 70.0f)) {
                self->unk16C = anctrl_getAnimTimer(anim_ctrl);
                self->unk170 = height_delta;
                anctrl_setPlaybackType(anim_ctrl, 3);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            func_8008B10C(anim_ctrl, func_800F10B4(height_delta, self->unk170, 1, self->unk16C, 0.6703f));
            func_8009D2F0(self, 1, 0.5f);
            if (player_isStable(self) != 0) {
                func_8009FE58(self);
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 1.3f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                self->unk15C.word = 3;
            }
            break;
        case 3:
            func_8009D2F0(self, 1, 0.5f);
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = BS_STATE_48;
            }
            if (bakey_pressed(self, BUTTON_A) != 0) {
                next_state = BS_STATE_4A;
            }
            if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0) {
                next_state = BS_STATE_4B;
            }
    }
    if (func_80800000_bskazstilt(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazstilt_entrypoint_18(PlayerState *self)
{
    baphysics_reset_gravity(self);
    func_80800234_bskazstilt(self);
}

s32 bskazstilt_entrypoint_19(s32 idx)
{
    return D_80801240_bskazstilt[idx];
}

void bskazstilt_entrypoint_20(PlayerState *self)
{
    f32 ideal_yaw[3];
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_8080013C_bskazstilt(self);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x14A);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_setStart(anim_ctrl, 0.0865f);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3,
                  BA_PHYSICS_3_LOCKED_ROTATION);
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    ideal_yaw[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, ideal_yaw[0],
                                      baphysics_get_target_horizontal_velocity(self));
    func_800A0CF4(self, 1);
    func_800A0CE8(self, 1);
    func_8009BFE4(self, 1000.0f, 12.0f);
    baroll_setAngularVelocity(self, 1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009D658(self);
    _batimer_set(self, 0, 1.0f);
}

void bskazstilt_entrypoint_21(PlayerState *self)
{
    BanjoStateId next_state;
    f32 stick_vec[3];
    f32 target_yaw;

    next_state = BS_STATE_0_INVALID;
    func_808000C8_bskazstilt(self);
    func_8009D658(self);
    _batimer_decrement(self, 0);
    if (func_8008DF18(self) != 0) {
        func_800963C0(self, stick_vec);
        func_800F1EA4(&stick_vec, &target_yaw);
        func_8009D2F0(self, 1, 0.5f);
        baphysics_set_target_horizontal_velocity(
            self, func_800F10B4(func_8009BFD8(self), 20.0f, 60, 550, 700.0f));
        baphysics_set_target_yaw(self, target_yaw);
        _badust_entrypoint_1(self);
    } else {
        next_state = BS_STATE_48;
    }
    if ((_batimer_isZero(self, 0) != 0) && (bakey_pressed(self, BUTTON_A) != 0)) {
        next_state = BS_STATE_4A;
    }
    if (func_80800000_bskazstilt(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazstilt_entrypoint_22(PlayerState *self)
{
    func_80800234_bskazstilt(self);
}

s32 bskazstilt_entrypoint_23(s32 idx)
{
    return D_80801250_bskazstilt[idx];
}

void bskazstilt_entrypoint_24(PlayerState *self)
{
    _bsrest_entrypoint_14(self);
    func_80800234_bskazstilt(self);
}

void bskazstilt_entrypoint_25(PlayerState *self)
{
    func_8080013C_bskazstilt(self);
    _bsrest_entrypoint_16(self);
}

void bskazstilt_entrypoint_26(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    func_808000C8_bskazstilt(self);
    func_8009D3A8(self, 1);
    if (_bsrest_entrypoint_20(self) != 0) {
        next_state = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, next_state);
}

s32 bskazstilt_entrypoint_27(s32 idx)
{
    return D_80801260_bskazstilt[idx];
}

void bskazstilt_entrypoint_28(PlayerState *self)
{
    func_8080013C_bskazstilt(self);
    _bsdrone_entrypoint_0(self);
}

void bskazstilt_entrypoint_29(PlayerState *self)
{
    func_808000C8_bskazstilt(self);
    _bsdrone_entrypoint_1(self);
    if (bastatetimer_isDone(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0) {
        bs_setState(self, BS_STATE_4B);
    }
}

void bskazstilt_entrypoint_30(PlayerState *self)
{
    _bsdrone_entrypoint_2(self);
    func_80800234_bskazstilt(self);
}

s32 bskazstilt_entrypoint_31(s32 idx)
{
    return D_80801270_bskazstilt[idx];
}

// TU-NOTE: the overlay .data tables are defined here so IDO schedules the functions above the
// same way as the original; values are taken from the ROM.
extern void func_80099B94();
extern void _bsdrone_entrypoint_3();
s32 D_80801200_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_2, (u32) _bskazstilt_entrypoint_0,
                                (u32) _bskazstilt_entrypoint_1, (u32) func_80099B94};
s32 D_80801210_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_6, (u32) _bskazstilt_entrypoint_4,
                                (u32) _bskazstilt_entrypoint_5, (u32) func_80099B94};
s32 D_80801220_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_10, (u32) _bskazstilt_entrypoint_8,
                                (u32) _bskazstilt_entrypoint_9, (u32) func_80099B94};
s32 D_80801230_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_14, (u32) _bskazstilt_entrypoint_12,
                                (u32) _bskazstilt_entrypoint_13, (u32) func_80099B94};
s32 D_80801240_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_18, (u32) _bskazstilt_entrypoint_16,
                                (u32) _bskazstilt_entrypoint_17, (u32) func_80099B94};
s32 D_80801250_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_22, (u32) _bskazstilt_entrypoint_20,
                                (u32) _bskazstilt_entrypoint_21, (u32) func_80099B94};
s32 D_80801260_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_24, (u32) _bskazstilt_entrypoint_25,
                                (u32) _bskazstilt_entrypoint_26, (u32) func_80099B94};
s32 D_80801270_bskazstilt[4] = {(u32) _bskazstilt_entrypoint_30, (u32) _bskazstilt_entrypoint_28,
                                (u32) _bskazstilt_entrypoint_29, (u32) _bsdrone_entrypoint_3};
