// TU-NOTE: the .data of this overlay is defined in this file; its table points to functions here,
// and IDO schedules some of them differently unless they share a unit. Values come from the ROM.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8009E55C(s32, s32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void _babackpack_entrypoint_5();
extern s32 D_80800560_bsbreegullbash[];
extern void func_800EFCD8(f32 *, f32, f32);
extern void _badust_entrypoint_2(PlayerState *, f32 *, f32 *, f32, f32, f32);
extern f32 func_800136E4(f32);

// Spawns one dust puff at the backpack, flying out along angle.
void func_80800000_bsbreegullbash(PlayerState *player, f32 angle, f32 speed, f32 vy)
{
    f32 velocity[3];
    f32 pos[3];
    speed *= 0.51f;
    _babackpack_entrypoint_5(player, pos, 2);
    pos[1] -= 20.0f;
    func_800EFCD8(velocity, angle, speed);
    velocity[1] = vy;
    _badust_entrypoint_2(player, pos, velocity, 0.1f, 0.8f, 0.7f);
}

// Two rings of six dust puffs, the second offset by 30 degrees.
void func_808000A4_bsbreegullbash(player) PlayerState *player;
{
    f32 angle;
    for (angle = 0.0f; angle < 359.0f; angle += 60.0f) {
        func_80800000_bsbreegullbash(player, angle, 730.0f, 100.0f);
    }
    for (angle = 0.0f; angle < 359.0f; angle += 60.0f) {
        func_80800000_bsbreegullbash(player, func_800136E4(angle + 30.0f), 430.0f, 40.0f);
    }
}

void func_808001B4_bsbreegullbash(s32 arg0)
{
    _babackpack_set_state(arg0, 0x7);
}

int func_808001D4_bsbreegullbash(Actor *player)
{
    if (_babackpack_get_state() != 1) {
        _babackpack_set_state(player, 1);
        func_8009E4E0(player, 2, 0);
        func_8009E55C(player, 2, 0);
    }
}

// End.
int bsbreegullbash_entrypoint_0(Actor *player)
{
    func_8009E474();
    func_808001D4_bsbreegullbash(player);
    baflag_clear(player, 0x3E);
}

// Init.
void bsbreegullbash_entrypoint_1(PlayerState *player)
{
    baanim_playForDuration_onceSmooth(player, 0x20, 1.75f);
    func_8009FFD8(player, 1, 1, 3, 6);
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_8009E4AC(player);
    func_8009E4E0(player, 2, 0);
    func_8009E55C(player, 2, 0.0f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
}

// Update: hit sphere, sounds, shake and dust on anim marks.
void bsbreegullbash_entrypoint_2(s32 player)
{
    s32 next_state;

    next_state = 0;
    if ((baanim_isAt(player, 0x3E6147AE) != 0) && (_babackpack_get_state(player) == 7)) {
        baflag_set(player, 0x3E);
        func_8009E55C(player, 2, 60.0f);
        func_8009E4E0(player, 2, &_babackpack_entrypoint_5);
        func_8009E5A4(player, 2, 2);
    }
    if (baanim_isAt(player, 0x3DF34D6A) != 0) {
        func_808001B4_bsbreegullbash(player);
    }
    if (baanim_isAt(player, 0x3E570A3D) != 0) {
        func_8009DFD4(player, 0x4595, 0x3F800000, 0x3F8CCCCD, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(player, 0x3EB851EC) != 0) {
        func_8009DB04(player, 0x416, 0x3F800000, 0x55F0);
    }
    if (baanim_isAt(player, 0x3EBD70A4) != 0) {
        func_8009DFD4(player, 0x4596, 0x3F800000, 0x3F8CCCCD, 0x7FFF, 0x7FFF);
    }
    if (baanim_isAt(player, 0x3F2BE0DF) != 0) {
        func_8009DF18(player, 0x3EA, 0x3F800000, 0x55F0);
    }
    if (baanim_isAt(player, 0x3EAB851F) != 0) {
        _bashake_entrypoint_0(player, 3, 2);
        func_8009E55C(player, 2, 180.0f);
        func_808000A4_bsbreegullbash(player);
    }
    if (baanim_isAt(player, 0x3EC28F5C) != 0) {
        func_8009E55C(player, 2, 0.0f);
        baflag_clear(player, 0x3E);
    }
    if (baanim_isAt(player, 0x3F641F21) != 0) {
        func_808001D4_bsbreegullbash(player);
    }
    if (baanim_isStopped(player) != 0) {
        next_state = 1;
    }
    if (player_inWater(player) != 0) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

int bsbreegullbash_entrypoint_3(s32 index)
{
    return D_80800560_bsbreegullbash[index];
}

extern void _bsbreegullbash_entrypoint_0();
extern void _bsbreegullbash_entrypoint_1();
extern void _bsbreegullbash_entrypoint_2();
extern void func_80099B94();
s32 D_80800560_bsbreegullbash[4] = {(u32) _bsbreegullbash_entrypoint_0,
                                    (u32) _bsbreegullbash_entrypoint_1,
                                    (u32) _bsbreegullbash_entrypoint_2, (u32) func_80099B94};
