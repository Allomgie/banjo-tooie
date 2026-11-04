// This seems to be Kazooie's charged spring jump: a sparkle helper (also used by kaz/jump), a short
// jump with a charge window and the high launch, with feathery-flap and dive exits.
#include "common.h"
#include "overlays/bs/kaz/shock.h"

extern s32 D_80800770_bskazshock[];
extern s32 D_808007A4_bskazshock[];
extern s32 D_808007B4_bskazshock[];

// Spawns the spark particles (also called from kaz/jump on spring pads).
void bskazshock_entrypoint_0(PlayerState *self)
{
    f32 unk_0[3];

    func_80092C24(self, unk_0);
    func_800BBCB8(unk_0, 0, 1, 1, D_80800770_bskazshock);
}

// Short spring jump: enter.
void bskazshock_entrypoint_1(PlayerState *self)
{
    f32 ideal_yaw[3];
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_27C_ANIM_BSKAZSHOCK_UNKNOWN);
    func_8008B1C8(anim_ctrl, 0.4);
    anctrl_setDuration(anim_ctrl, 3);
    anctrl_setSubrange(anim_ctrl, 0, 0.2);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, 1, 1, 3, 6);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bskazmove_entrypoint_0(self);
    ideal_yaw[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, ideal_yaw[0],
                                      baphysics_get_target_horizontal_velocity(self));
    self->unk164.bytes[0] = func_800C2E04();
    func_800C3418(self->unk164.bytes[0], 0);
    func_800C2E40(self->unk164.bytes[0]);
    func_800C330C(self->unk164.bytes[0], 3);
    func_800C301C(self->unk164.bytes[0], 0x41D);
    func_800C3730(self->unk164.bytes[0], 1.4, 0.4, -1.2);
    self->unk15C.word = 1;
    self->unk160.word = 0;
}

// Short spring jump update: holding A past the halfway point switches to state 0xC1.
void bskazshock_entrypoint_2(PlayerState *self)
{
    BanjoStateId next_state;
    AnimCtrl *anim_ctrl;
    f32 vec[3];

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (player_isStable(self) != 0) {
        if ((func_8001211C() % -2) != 0) {
            bskazshock_entrypoint_0(self);
        }
    } else {
        bskazshock_entrypoint_0(self);
    }
    _bskazmove_entrypoint_0(self);
    func_8009BB24(self, vec);
    if ((bakey_released(self, BUTTON_A) != 0) && (vec[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    switch (self->unk160.word) {
        case 0:
            if (func_8008E260(self) != 0) {
                next_state = BS_STATE_E0;
            }
            if (func_8008DF8C(self, 0x82) != 0) {
                anctrl_setSubrange(anim_ctrl, 0, 1);
                anctrl_setDuration(anim_ctrl, 2.8);
                anctrl_setPlaybackType(anim_ctrl, 1);
                self->unk160.word = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.11) != 0) {
                func_800C3BDC(self->unk164.bytes[0]);
            }
            if (anctrl_isAt(anim_ctrl, 0.4036) != 0) {
                anctrl_setDuration(anim_ctrl, 1.4);
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = BS_STATE_BB;
            }
    }
    if (func_8008DF8C(self, 0x3C) != 0) {
        if ((anctrl_getAnimTimer(anim_ctrl) < 0.5f) && (bakey_released(self, BUTTON_A) != 0)) {
            self->unk15C.word = 0;
        }
        if (player_isStable(self) != 0) {
            baphysics_set_target_horizontal_velocity(self, 0);
        }
    }
    if ((anctrl_isAt(anim_ctrl, 0.5) != 0) && (self->unk15C.word != 0)) {
        next_state = BS_STATE_C1;
    }
    if (anctrl_isAt(anim_ctrl, 0.5551) != 0) {
        baphysics_set_vertical_velocity(self, 180);
    }
    if ((vec[1] < 0.0f) && (player_inWater(self) != 0)) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

void bskazshock_entrypoint_3(PlayerState *self)
{
    func_800C2FDC(self->unk164.bytes[0]);
    func_80092BF4(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazshock_entrypoint_4(s32 idx)
{
    return D_808007A4_bskazshock[idx];
}

// High spring launch: enter (1820 up, gravity -1200, sets ability-used flag 0x45).
void bskazshock_entrypoint_5(PlayerState *self)
{
    f32 ideal_yaw[3];
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, ASSET_27A_ANIM_BSKAZSHOCK_UNKNOWN);
    anctrl_setDuration(anim_ctrl, 1.6);
    anctrl_setStart(anim_ctrl, 0.5814);
    anctrl_setSubrange(anim_ctrl, 0, 1);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(self, 1, 1, 3, 6);
    if (bastick_distance(self) != 0.0f) {
        yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
    }
    baphysics_set_target_yaw(self, yaw_getIdeal(self));
    _bskazmove_entrypoint_0(self);
    ideal_yaw[0] = yaw_getIdeal(self);
    baphysics_set_horizontal_velocity(self, ideal_yaw[0],
                                      baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, 1820);
    baphysics_set_gravity(self, -1200);
    func_8009DBF0(self, 0x408, 1);
    func_800C6DA0(0x45);
    self->unk160.word = 0;
}

// High spring launch update: exits to dive, flap or fall.
void bskazshock_entrypoint_6(PlayerState *self)
{
    BanjoStateId next_state;
    f32 vec[3];
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bskazmove_entrypoint_0(self);
    func_8009BB24(self, vec);
    if (anctrl_isAt(anim_ctrl, 0.61) != 0) {
        func_8009DF58(self, 0x4598, 1);
    }
    if ((bakey_released(self, BUTTON_A) != 0) && (vec[1] > 0.0f)) {
        baphysics_reset_gravity(self);
    }
    if (self->unk160.word == 0) {
        bskazshock_entrypoint_0(self);
        if (vec[1] < 0.0f) {
            next_state = BS_STATE_DF;
        }
    }
    if (player_isStable(self) == 0) {
        if (func_8008E260(self) != 0) {
            next_state = BS_STATE_E0;
        }
        if (bainput_should_feathery_flap(self) != 0) {
            next_state = BS_STATE_15C;
        }
        if ((baphysics_get_vertical_velocity(self) < 0.0f) && (bainput_func_80097E74(self) != 0)) {
            next_state = BS_STATE_BE;
        }
    }
    bs_setState(self, next_state);
}

void bskazshock_entrypoint_7(PlayerState *self)
{
    baphysics_reset_gravity(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazshock_entrypoint_8(s32 idx)
{
    return D_808007B4_bskazshock[idx];
}

// TU-NOTE: the overlay .data is defined here in C. The tables point to functions of this file;
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
// Values are taken from the ROM.
extern void func_80099B94();
s32 D_80800770_bskazshock[13] = {0x1D09E1,  0xAFFE7,  0xFFE7,   0x19001E, 0x190015,
                                 0x190099,  0x220066, 0x590019, 0x190027, 0x1900190,
                                 0x3200320, 0x2B0080, 0x800000};
s32 D_808007A4_bskazshock[4] = {(u32) _bskazshock_entrypoint_3, (u32) _bskazshock_entrypoint_1,
                                (u32) _bskazshock_entrypoint_2, (u32) func_80099B94};
s32 D_808007B4_bskazshock[7] = {(u32) _bskazshock_entrypoint_7,
                                (u32) _bskazshock_entrypoint_5,
                                (u32) _bskazshock_entrypoint_6,
                                (u32) func_80099B94,
                                0x0,
                                0x0,
                                0x0};
