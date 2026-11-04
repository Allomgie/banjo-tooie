// Probably the shared player-death helpers: death sequence, death camera and game-over trigger.
#include "common.h"
#include "playerstate.h"

extern void func_8009C128(PlayerState *, f32 *);
extern void func_800A32C4(PlayerState *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void _ncbadie_entrypoint_3(void *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 func_800964DC(void *);
extern f32 func_80096364(void *);
extern f32 _batimer_get(void *, s32);
extern s32 func_80096544(void *);
extern s32 player_inWater();
extern f32 func_8009C150(void *);
void basudie_entrypoint_4(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4,
                          f32 param_5);

void basudie_entrypoint_0()
{
    func_80091EF0();
}

// Game over: with no other party member, broadcast message 0x9F and end control.
void basudie_entrypoint_1(u8 *player)
{
    if (func_800F8B64() == 0) {
        func_80101238(0x9F, *(s32 *) ((s8 *) player + 0x184));
        func_800F90F8(1);
        func_800C0658();
    }
}

void basudie_entrypoint_2(s32 player, f32 speed, f32 vertical_velocity, f32 gravity)
{
    basudie_entrypoint_4(player, speed, vertical_velocity, gravity, 30.0f, 3.5f);
}

void basudie_entrypoint_3(void *player, f32 speed, f32 vertical_velocity, s32 gravity_bits, f32 unk_4)
{
    basudie_entrypoint_4(player, speed, vertical_velocity, *(f32 *) &gravity_bits, unk_4, 3.5f);
}

// Death sequence: knock the player away from the attacker, start the death camera and timer 9.
void basudie_entrypoint_4(PlayerState *player, f32 speed, f32 vertical_velocity, f32 gravity, f32 unk_4,
                          f32 death_time)
{
    f32 knock_yaw;
    f32 player_pos[3];
    f32 attacker_pos[3];

    basudie_entrypoint_1(player);
    func_8009FFD8(player, 1, 1, 2, 3);
    func_8009C128(player, player_pos);
    func_800A32C4(player, attacker_pos);
    func_800F1E6C(attacker_pos, player_pos, &knock_yaw);
    yaw_setIdeal(player, func_800136E4(knock_yaw + 180.0f));
    yaw_applyIdeal(player);
    baphysics_set_target_horizontal_velocity(player, speed);
    baphysics_set_target_yaw(player, knock_yaw);
    baphysics_set_horizontal_velocity(player, knock_yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, vertical_velocity);
    baphysics_set_gravity(player, gravity);
    func_8008E944(player);
    func_8009514C(player);
    func_800A4DFC(player, 10);
    func_800C52F4(func_800A4C68(player), 2);
    _ncbadie_entrypoint_3(func_800A4CA8(player), unk_4);
    func_800A0180(player);
    _batimer_set(player, 9, death_time);
}

s32 basudie_entrypoint_5(Actor *player)
{
    func_8009D3A8(player, 0);
    if (_batimer_decrement(player, 0x9))
        basudie_entrypoint_0(player);
}

int basudie_entrypoint_6(Actor *player)
{
    baphysics_reset_gravity();
    func_800A4E30(player);
    // Matching: "| 0" needed for the match.
    func_800C53EC(func_800A4C68(player) | 0, 2);
    func_800951B4(player);
}

// Water test during death (drowned / hit water).
int basudie_entrypoint_7(void *player)
{
    f32 unk_0;
    f32 unk_1;

    unk_0 = func_800964DC(player);
    unk_1 = func_80096364(player);
    return _batimer_get(player, 9) != 0.0f && func_80096544(player) != 0 &&
           player_inWater(player) != 0 && func_8009C150(player) < unk_0 - 150.0f &&
           unk_0 - unk_1 > 100.0f;
}

int basudie_entrypoint_8(Actor *player)
{
    func_80091E6C();
    func_800A4E30(player);
    // Matching: "| 0" needed for the match.
    func_800C53EC(func_800A4C68(player) | 0, 2);
}

// Death sequence variant with camera shake.
void basudie_entrypoint_9(s32 player, f32 unk_1)
{
    func_80091E48(player, 0x20);
    basudie_entrypoint_1(player);
    func_8008E944(player);
    func_800A4DFC(player, 0xA);
    func_800C52F4(func_800A4C68(player), 2);
    _ncbadie_entrypoint_3(func_800A4CA8(player), unk_1);
    func_800A0180(player);
    _batimer_set(player, 9, 3.6f);
    _bashake_entrypoint_0(player, 3, 2);
}

int basudie_entrypoint_10(Actor *player)
{
    if (_batimer_decrement(player, 9)) {
        basudie_entrypoint_0(player);
    }
}

void basudie_entrypoint_11(s32 player)
{
    func_8009E6EC();
    func_80099AA8(player);
}

// Sets a custom terminal velocity while in water, resets it otherwise.
int basudie_entrypoint_12(Actor *player)
{
    if (player_inWater()) {
        baphysics_set_terminal_velocity(player, 0xC37A0000);
    } else {
        baphysics_reset_terminal_velocity();
    }
}
