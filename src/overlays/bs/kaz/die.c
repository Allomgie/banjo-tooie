#include "common.h"
#include "overlays/bs/kaz/die.h"

extern s32 D_80800460_bskazdie[];

// Spawns a ring of 8 dust puffs, 45 degrees apart.
void func_80800000_bskazdie(PlayerState *self)
{
    f32 angle = 0.0f;
    while (angle < 360) {
        _badust_entrypoint_5(self, angle, 230);
        angle += 45.0f;
    }
}

void bskazdie_entrypoint_0(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    f32 target_yaw;
    f32 unk_0[3];
    s32 unk_1[3];

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _bskaz_entrypoint_1(self);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, ASSET_CA_ANIM_BZKAZDIE_UNKNOWN);
    anctrl_setSubrange(anim_ctrl, 0, 0.246);
    anctrl_setDuration(anim_ctrl, 3.7);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    _basudie_entrypoint_1(self);
    func_8009D820(self, 1.8);
    func_8009C128(self, &unk_0);
    func_800A32C4(self, &unk_1);
    func_800F1E6C(&unk_1, &unk_0, &target_yaw);
    self->unk16C = 250;
    yaw_setIdeal(self, func_800136E4(target_yaw + 180.0f));
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    baphysics_set_target_yaw(self, target_yaw);
    baphysics_set_horizontal_velocity(self, target_yaw,
                                      baphysics_get_target_horizontal_velocity(self));
    func_8008CA4C(self, BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateType(self, 1);
    func_8009D2D8(self, 2);
    baphysics_set_type(self, 3);
    baphysics_set_vertical_velocity(self, 510);
    baphysics_set_gravity(self, -1400);
    func_8009BFE4(self, 1000, 12);
    func_800A4DFC(self, 10);
    _ncbadie_entrypoint_3(func_800A4CA8(self), 30);
    func_800A0180(self);
    _batimer_set(self, 0, 3.5);
    func_8008E944(self);
    func_8009514C(self);
    self->unk15C.word = 0;
}

void bskazdie_entrypoint_1(PlayerState *self)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    _basudie_entrypoint_12(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    func_8009D3A8(self, 0);
    // unk15C.word: 0 knocked back, 2 bounced after landing, 3 finished.
    switch (self->unk15C.word) {
        case 3:
            break;
        case 0:
            if (func_8008DF8C(self, 0x82) != 0) {
                anctrl_setSubrange(anim_ctrl, 0, 1);
                anctrl_setPlaybackType(anim_ctrl, 1);
                baphysics_set_vertical_velocity(self, 400);
                func_8009E058(self);
                func_8009D9D4(self);
                _bamotor_entrypoint_1(self, 1, 1, 0.4);
                func_80800000_bskazdie(self);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            self->unk16C = func_800F0E00(self->unk16C - 12.0f, 0);
            if (self->unk16C > 140.0f) {
                _badust_entrypoint_9(self);
            }
            if (anctrl_isAt(anim_ctrl, 0.6538) != 0) {
                anctrl_setDuration(anim_ctrl, 4);
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                self->unk15C.word = 3;
                self->unk16C = 0.0f;
            }
    }
    // After 3.5 s hand over to the shared 'player died' sequence.
    if (_batimer_decrement(self, 0) != 0) {
        _basudie_entrypoint_0(self);
    }
    bs_setState(self, BS_STATE_0_INVALID);
}

void bskazdie_entrypoint_2(PlayerState *self)
{
    baphysics_reset_gravity(self);
    func_8009BF5C(self, 0);
    baroll_setIdeal(self, 0);
    func_800A4E30(self);
    func_800951B4(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazdie_entrypoint_3(s32 idx)
{
    return D_80800460_bskazdie[idx];
}

// TU-NOTE: the overlay .data (formerly die.data.s) is defined here in C. The table holds
// function pointers from this file; IDO's assembler schedules these functions differently
// unless the table is in the same unit. Values are taken from the ROM.
extern void _basudie_entrypoint_11();
s32 D_80800460_bskazdie[4] = {(u32) _bskazdie_entrypoint_2, (u32) _bskazdie_entrypoint_0,
                              (u32) _bskazdie_entrypoint_1, (u32) _basudie_entrypoint_11};
