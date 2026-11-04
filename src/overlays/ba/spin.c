// Spin-out reaction for vehicle-like forms: turns toward the attacker, sets knock-back velocity
// and spins the model N full turns over 1.5 s, handling the first-person camera.
#include "common.h"
#include "playerstate.h"

extern f32 func_80092BE8();
typedef struct {
    u8 turns;
    u8 first_person;
    u8 pad_2[2];
    f32 start_yaw;
} Broad42SpinState;
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern f32 yaw_get(PlayerState *);
extern f32 _bareact_entrypoint_4(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void func_8009328C(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 baanim_isAt(PlayerState *, f32);

s32 baspin_entrypoint_0()
{
    return 0x8;
}

void baspin_entrypoint_1(u8 *player)
{
    if ((*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x118) + 1) == 1) &&
        (_bafpctrl_entrypoint_4() == 3)) {
        _ncba1p_entrypoint_4(func_800A4CA8(player), 1);
    }
    func_8009BD88(player);
    func_8008E95C(player);
    func_800951B4(player);
    yaw_setIdeal(player, func_80092BE8(player));
    yaw_applyIdeal(player);
    func_800931AC(player, 1);
}

// Spin-out start: turn toward the hit, set knock-back velocity, spin the model for 1.5 s (timer 0xB).
void baspin_entrypoint_2(PlayerState *player, s32 anim_id, f32 anim_duration, s32 turns, s32 first_person)
{
    f32 knock_yaw;
    f32 pos[3];
    f32 other_pos[3];

    ((Broad42SpinState *) *(void **) ((u8 *) player + 0x118))->first_person = first_person;
    ((Broad42SpinState *) *(void **) ((u8 *) player + 0x118))->turns = turns;
    _bareact_entrypoint_1(player, func_80099A58());
    baanim_playForDuration_once(player, anim_id, anim_duration);
    if (func_800A32EC(player) != 3) {
        func_8009D9D4(player);
    }
    func_8009C128(player, pos);
    func_800A32C4(player, other_pos);
    func_800F1E6C(other_pos, pos, &knock_yaw);
    yaw_setIdeal(player, knock_yaw);
    yaw_applyIdeal(player);
    baroll_setIdeal(player, 0.0f);
    func_8009BF5C(player, 0.0f);
    ((Broad42SpinState *) *(void **) ((u8 *) player + 0x118))->start_yaw = yaw_get(player);
    func_800931AC(player, 3);
    func_8009328C(player, ((Broad42SpinState *) *(void **) ((u8 *) player + 0x118))->start_yaw);
    baphysics_set_target_horizontal_velocity(player, _bareact_entrypoint_4(player));
    baphysics_set_target_yaw(player, knock_yaw);
    baphysics_set_horizontal_velocity(player, knock_yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    func_8009FFD8(player, 1, 1, 2, 3);
    func_8008E944(player);
    func_8009514C(player);
    _batimer_set(player, 0xB, 1.5f);
    if (((Broad42SpinState *) *(void **) ((u8 *) player + 0x118))->first_person == 1 &&
        _bafpctrl_entrypoint_4(player) == 3) {
        _ncba1p_entrypoint_4(func_800A4CA8(player), 0);
    }
}

// Spin-out update: eases the model yaw through the full turns; returns 2 when finished.
s32 baspin_entrypoint_3(PlayerState *player)
{
    u8 *state = *(u8 **) ((u8 *) player + 0x118);
    f32 total_yaw = 360.0f * (f32) (u32) state[0] + *(f32 *) (state + 4) + 180.0f;
    f32 model_yaw;
    f32 angle;

    angle = func_800F10B4(_batimer_get(player, 11), 0.0f, 1.5f, 1.0f, 0) * 90.0f;
    model_yaw = func_80013970(angle) * total_yaw;
    func_8009328C(player, model_yaw);
    if ((*(u8 **) ((u8 *) player + 0x118))[1] == 1 && _bafpctrl_entrypoint_4(player) == 3) {
        yaw_setIdeal(player, model_yaw);
        yaw_applyIdeal(player);
    }
    _batimer_decrement(player, 11);
    if (baanim_isAt(player, 0.5f))
        func_800951B4(player);
    if (_batimer_get(player, 11) == 0.0f && baanim_isStopped(player))
        return 2;
    return 1;
}
