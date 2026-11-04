// Most likely Kazooie's feathery flap: a wind-up, one strong flap, then a hovering flap loop
// with reduced fall speed while A is held; Z queues an air attack.
#include "common.h"
#include "overlays/bs/kaz/spring.h"

extern s32 D_80800430_bskazspring[];

// Sets the horizontal speed from the stick position.
void func_80800000_bskazspring(PlayerState *self)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(self);
    if (bastick_getZone(self) != BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, func_800F1214(stick_pos, 80, 200));
        return;
    }
    baphysics_set_target_horizontal_velocity(self, 0.0f);
}

// Enters a phase: 0 exit, 1 wind-up, 2 strong flap, 3 hovering flap loop.
void func_80800064_bskazspring(PlayerState *self, s32 phase)
{
    f32 ideal_yaw[3];

    switch (phase) {
        case 0:
            bastick_popZone(self);
            baphysics_reset_gravity(self);
            baphysics_reset_terminal_velocity(self);
            break;
        case 1:
            baanim_playForDuration_onceSmooth(self, ASSET_142_ANIM_BSKAZSPRING_UNKNOWN, 1.4);
            func_8009FFD8(self, 1, 1, 1, 2);
            baphysics_set_target_horizontal_velocity(
                self, baphysics_get_target_horizontal_velocity(self) * 0.7f);
            baphysics_set_gravity(self, -1200);
            baphysics_set_terminal_velocity(self, -533.3);
            bastick_pushZone(self);
            bastick_setZoneMax(self, 0, 0.03);
            bastick_setZoneMax(self, 1, 1);
            self->unk160.word = 0;
            break;
        case 2:
            yaw_setUpdateType(self, 2);
            func_8009D2D8(self, 3);
            yaw_rotateTimed(self, 1);
            // Matching: tests the function address, not a call; needed for the match.
            if (bastick_distance) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
            }
            baphysics_set_target_yaw(self, yaw_getIdeal(self));
            ideal_yaw[0] = yaw_getIdeal(self);
            baphysics_set_horizontal_velocity(self, ideal_yaw[0],
                                              baphysics_get_target_horizontal_velocity(self));
            func_80800000_bskazspring(self);
            baphysics_set_vertical_velocity(self, 1293);
            func_8009DF18(self, 0x45A5, 1, 22000);
            break;
        case 3:
            baanim_playForDuration_loopSmooth(self, ASSET_288_ANIM_BSKAZFLY_UNKNOWN, 00.18);
    }

    self->unk15C.bytes[0] = (s8) phase;
}

void func_80800244_bskazspring(s32 self)
{
    func_80800064_bskazspring(self, (s8) 0);
    _bskaz_entrypoint_2(self);
}

void func_80800270_bskazspring(PlayerState *self)
{
    _bskaz_entrypoint_1(self);
    self->unk15C.bytes[0] = 0;
    func_80800064_bskazspring(self, 1);
}

void func_808002A0_bskazspring(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = 0;
    switch (self->unk15C.bytes[0]) {
        case 1:
            if (baanim_isAt(self, 0.22) != 0) {
                func_8009DF94(self, 0x3FF, 0.558, 22000);
            }
            if (baanim_isAt(self, 0.3) != 0) {
                func_80800064_bskazspring(self, 2);
            }
            break;
        case 2:
            func_80800000_bskazspring(self);
            if (baanim_isStopped(self) != 0) {
                func_80800064_bskazspring(self, 3);
            }
            break;
        case 3:
            func_80800000_bskazspring(self);
            if (bakey_released(self, BUTTON_A) != 0) {
                next_state = BS_STATE_DF;
            }
            if (player_isStable(self) != 0) {
                next_state = BS_STATE_DF;
            }
    }
    // Z queues an air attack, started once falling.
    if (bakey_pressed(self, BUTTON_Z) != 0) {
        self->unk160.word = 1;
    }
    if ((self->unk160.word != 0) && (baphysics_get_vertical_velocity(self) < 0.0f) &&
        (bainput_func_80097E74(self) != 0)) {
        next_state = BS_STATE_BE;
    }
    bs_setState(self, next_state);
}

s32 bskazspring_entrypoint_0(s32 idx)
{
    return D_80800430_bskazspring[idx];
}

// TU-NOTE: the overlay .data (formerly spring.data.s) is defined here in C. The table holds
// function pointers from this file; IDO's assembler schedules these functions differently
// unless the table is in the same unit. Values are taken from the ROM.
extern void func_80099B94();
s32 D_80800430_bskazspring[4] = {(u32) func_80800244_bskazspring, (u32) func_80800270_bskazspring,
                                 (u32) func_808002A0_bskazspring, (u32) func_80099B94};
