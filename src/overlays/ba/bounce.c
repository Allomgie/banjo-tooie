#include "common.h"
#include "overlays/ba/bounce.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/react.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/timer.h"
#include "core2/1E2B200.h"
#include "core2/1E67DA0.h"
#include "core2/1E6E870.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1ECB0F0.h"
#include "core2/1EDA900.h"

s32 babounce_entrypoint_0(void)
{
    return sizeof(BaBounce);
}

// States: 1 done, 2 knocked back, 3 launched toward a point.
void func_80800008_babounce(PlayerState *self, s32 state)
{
    self->bounce->unkC = state;
    if (state == 1) {
        func_8008E95C(self);
    }
}

s32 babounce_entrypoint_1(PlayerState *self)
{
    return self->bounce->unkC;
}

// True when the current reaction is of class 2.
int babounce_entrypoint_2(PlayerState *self)
{
    return (_bareact_entrypoint_2(self) == 2);
}

// Ends the knock-back: restores gravity and terminal velocity, then notifies the attacker.
void babounce_entrypoint_3(PlayerState *self)
{
    if (self->bounce->unkC == 3) {
        func_8009BA9C(self, 0);
    }

    if (self->bounce->unkD == 1) {
        func_800951B4(self);
        func_8009BD88(self);
    }

    baphysics_set_gravity(self, self->bounce->unk14);
    baphysics_set_terminal_velocity(self, self->bounce->unk18);
    func_8008E95C(self);
    if (self->bounce->unk10 != 0) {
        func_8010114C(self->bounce->unk10, 0xA1, 0);
        self->bounce->unk10 = 0;
    }
}

// Starts a knock-back for the current hit reaction.
void babounce_entrypoint_4(PlayerState *self, s32 mode)
{
    f32 velocity[3];
    f32 target[3];
    f32 pos[3];
    f32 aim[2];
    f32 flight_time;
    s32 reaction_kind;

    self->bounce->unk14 = func_8009BADC(self);
    self->bounce->unk18 = func_8009BAE8(self);
    self->bounce->unk10 = 0;
    self->bounce->unkD = mode;
    switch (mode) {
        case 1:
            if (func_800A32EC(self) != 3) {
                func_8009D9D4(self);
            }
            func_8009514C(self);
            break;

        case 2:
            func_8009DA40(self);
    }
    reaction_kind = func_80099A58(self);
    _bareact_entrypoint_1(self, reaction_kind);
    self->bounce->unk0 = 1.2f;
    self->bounce->unk4 = 1.4f;
    func_800A32C4(self, target);
    func_8009C128(self, pos);
    func_800F1E6C(target, pos, aim);
    // Reaction kinds 0xE and 0x10 launch the player on a ballistic arc toward a point.
    if ((reaction_kind == 0xE) || (reaction_kind == 0x10)) {
        func_80800008_babounce(self, 3);
        func_8009FFD8(self, 1, 1, 2, 1);
        yaw_setIdeal(self, func_800136E4(aim[0]));
        self->bounce->unk1C = func_80099A40(self);
        flight_time = func_8009F3BC(self, pos[1], target[1], (aim[1] = func_80099A34(self)),
                             self->bounce->unk1C);
        func_800EFB24(velocity, target, pos);
        velocity[0] = velocity[0] / flight_time;
        velocity[2] = velocity[2] / flight_time;
        velocity[1] = aim[1];
        self->bounce->unk8 = flight_time;
        func_8009BA9C(self, velocity);
        _batimer_set(self, 6, flight_time);
    } else {
        // Otherwise knock back away from the attacker with the reaction speeds.
        func_80800008_babounce(self, 2);
        yaw_setIdeal(self, func_800136E4(aim[0] + 180.0f));
        baphysics_set_target_horizontal_velocity(self, _bareact_entrypoint_4(self));
        baphysics_set_target_yaw(self, aim[0]);
        baphysics_set_horizontal_velocity(self, aim[0],
                                          baphysics_get_target_horizontal_velocity(self));
        baphysics_set_vertical_velocity(self, _bareact_entrypoint_3(self));
        self->bounce->unk1C = _bareact_entrypoint_5(self);
        func_8009FFD8(self, 1, 1, 2, 3);
        if (_bareact_entrypoint_2(self) == 2) {
            baphysics_set_type(self, BA_PHYSICS_6_AIRBORN);
        }
    }
    baphysics_set_gravity(self, self->bounce->unk1C);
    baphysics_reset_terminal_velocity(self);
    yaw_applyIdeal(self);
    func_8008E944(self);
}

void babounce_entrypoint_5(PlayerState *self, AssetId asset_id, f32 range_end)
{
    AnimCtrl *anctrl = baanim_getAnimCtrlPtr(self);
    anctrl_reset(anctrl);
    anctrl_setIndex(anctrl, asset_id);
    if (self->bounce->unkC == 3) {
        anctrl_setDuration(anctrl, self->bounce->unk8 * (1.0f / range_end));
    } else {
        anctrl_setDuration(anctrl, self->bounce->unk0);
    }
    anctrl_setSubrange(anctrl, 0.0f, range_end);
    anctrl_setPlaybackType(anctrl, 1);
    anctrl_start(anctrl);
}

void babounce_entrypoint_6(PlayerState *self, AssetId asset_id, f32 range_end, f32 duration, f32 landing_duration)
{
    self->bounce->unk0 = duration;
    self->bounce->unk4 = landing_duration;
    babounce_entrypoint_5(self, asset_id, range_end);
}

void babounce_entrypoint_7(PlayerState *self, s32 attacker)
{
    self->bounce->unk10 = attacker;
}

// Advances the knock-back; returns 1 on landing or timeout, 2 once finished, else 0.
s32 babounce_entrypoint_8(PlayerState *self)
{
    f32 velocity[3];

    switch (self->bounce->unkC) {
        case 3:
            if (_batimer_decrement(self, 6)) {
                func_8009BB24(self, velocity);
                velocity[0] = 0.0f;
                velocity[2] = 0.0f;
                func_8009BA9C(self, velocity);
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                func_80800008_babounce(self, 1);
                return 1;
            }
            return 0;

        case 2:
            if (player_isStable(self)) {
                baphysics_set_target_horizontal_velocity(self, 0.0f);
                func_80800008_babounce(self, 1);
                return 1;
            }
            return 0;

        case 1:
            return 2;
    }
    return 0;
}

s32 babounce_entrypoint_9(PlayerState *self)
{
    switch (babounce_entrypoint_8(self)) {
        case 1:
            baanim_setEndAndDuration(self, 1.0f, self->bounce->unk4);
            return 0;

        case 2:
            if (baanim_isStopped(self) || (bastick_distance(self) != 0.0f)) {
                return 1;
            }
    }
    return 0;
}

s32 babounce_entrypoint_10(PlayerState *self)
{
    if (babounce_entrypoint_8(self) == 1) {
        return 1;
    }
    return 0;
}
