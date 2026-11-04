// Banjo-solo Snooze Pack states: Banjo sleeps in his backpack, regaining one health per second.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void bainput_enable(PlayerState *, s32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DF58(PlayerState *, s32, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern s32 D_80800A40_bsbansnooze[];
extern s32 D_80800A50_bsbansnooze[];
extern s32 D_80800A60_bsbansnooze[];
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 anctrl_getAnimTimer(void *);
extern f32 func_800F3780(f32, void *, s32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80800A78_bsbansnooze[];
extern s32 D_80800A88_bsbansnooze[];
extern s32 D_80800A98_bsbansnooze[];
extern void anctrl_setDuration(void *, f32);
extern void func_8008B1C8(void *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern s32 D_80800AA8_bsbansnooze[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern void func_8009DFD4(PlayerState *, s32, f32, f32, s32, s32);

// Leaves the snooze pack: restores backpack state, pops the stick zone, resets the camera.
int func_80800000_bsbansnooze(player_arg)
s32 player_arg;
{
    s32 player;
    // Matching: the `| 0` copy is needed for the match.
    player = player_arg | 0;
    if (func_8009E74C(player, 0x14)) {
        if (_babackpack_get_state(player) != 6) {
            _babackpack_set_state(player, 6);
        }
    } else {
        if (_babackpack_get_state(player) != 1) {
            _babackpack_set_state(player, 1);
        }
        func_800A0CD0(player, 1);
        func_80095A40(player);
        bastick_popZone(player);
        func_800A4E30(player);
    }
}

// Enters the snooze pack: sets backpack state, pushes the stick zone, adjusts the camera.
int func_80800098_bsbansnooze(player_arg)
s32 player_arg;
{
    s32 player;
    // Matching: the `| 0` copy is needed for the match.
    player = player_arg | 0;
    if (!func_8009E77C(player, 0x14)) {
        func_800A0CD0(player, 0);
        _babackpack_set_state(player, 6);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0x3DF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        func_800959C8(player, 0x42700000, 0x41F00000);
        func_800A4DA4(player, 8);
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

// Walk velocity from the stick position, scaled by speed_scale.
void func_80800128_bsbansnooze(PlayerState *player, f32 speed_scale)
{
    f32 stick_pos;
    stick_pos = bastick_getZonePosition(player);
    if (!bastick_getZone(player)) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player,
                                                 func_800F1214(stick_pos, 50.0f, 100.0f) * speed_scale);
    }
}

int func_8080019C_bsbansnooze(u8 *player)
{
    if (player[0x15D]) {
        // Matching: empty if steers IDO's register allocation.
        if ((player && player) && player) {
        }
        func_80800000_bsbansnooze();
    } else if (_babackpack_get_state() != 1) {
        func_800A0CD0(player, 1);
        _babackpack_set_state(player, 1);
    }
}

// Enter transformation: start the animation.
void func_808001FC_bsbansnooze(PlayerState *player)
{
    *(u8 *) ((u8 *) player + 0x15D) = 0;
    baanim_playForDuration_onceSmooth(player, 0x276, 1.5f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009DE38(player, 0x583, 0x3F800000);
    bainput_enable(player, 1, 0);
}

void func_80800278_bsbansnooze(PlayerState *player)
{
    s32 next_state = 0;

    bainput_enable(player, 1, 1);
    if (baanim_isAt(player, 0.18f)) {
        func_8009DF58(player, 0x58C, 1.0f);
    }
    if (baanim_isAt(player, 0.22f)) {
        func_8009DB04(player, 0x3FF, 1.0f, 0x55F0);
    }
    if (baanim_isAt(player, 0.1184f)) {
        func_800A0CD0(player, 0);
        _babackpack_set_state(player, 2);
    }
    if (baanim_isAt(player, 0.3703f)) {
        *((u8 *) player + 0x15D) = 1;
        func_80800098_bsbansnooze(player);
    }
    if (baanim_isStopped(player)) {
        next_state = 0x16F;
    }
    bs_setState(player, next_state);
}

int bsbansnooze_entrypoint_0(s32 param_0)
{
    return D_80800A40_bsbansnooze[param_0];
}

void func_8080037C_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

int func_8080039C_bsbansnooze(Actor *actor)
{
    func_80800098_bsbansnooze(actor);
    baanim_playForDuration_onceSmooth(actor, 0x279, 1.6f);
    func_8009FFD8(actor, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(actor, 0.0f);
    func_8009DF94(actor, 0x58D, 0x3F800000, 0x7530);
}

int func_80800414_bsbansnooze(s32 player)
{
    s32 next_state;
    next_state = 0;
    if (baanim_isAt(player, 0.77f)) {
        func_8009DE38(player, 0x584, 0x3F8CCCCD);
    }
    if (baanim_isAt(player, 0.6556f)) {
        _babackpack_set_state(player, 1);
        func_800A0CD0(player, 1);
    }
    if (baanim_isStopped(player)) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

int bsbansnooze_entrypoint_1(int param_0)
{
    return D_80800A50_bsbansnooze[param_0];
}

void func_808004C0_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

void func_808004E0_bsbansnooze(PlayerState *player)
{
    func_80800098_bsbansnooze(player);
    baanim_playForDuration_loopSmooth(player, 0x278, 0.7f);
    func_8009FFD8(player, 2, 3, 8, 14);
    yaw_setVelocityBounded(player, 0x42C80000, 0x40600000);
    baanim_setDurationRange(player, 0.1f, 5.0f);
    func_8008C9F0(player, 50.0f, 100.0f, 0.7f, 0.7f);
    func_8008CA30(player, 1.0f);
}

void func_80800588_bsbansnooze(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    func_80800128_bsbansnooze(
        player, func_800F3780(anctrl_getAnimTimer(anim_ctrl), &D_80800A60_bsbansnooze, 3));
    if (!bastick_getZone(player) && func_8009BCD4(player, 3.0f))
        next_state = 0x16F;
    if (bakey_released(player, 1))
        next_state = 0x172;
    if (player_inWater(player))
        next_state = 0x4C;
    bs_setState(player, next_state);
}

int bsbansnooze_entrypoint_2(int param_0)
{
    return D_80800A78_bsbansnooze[param_0];
}

void func_8080064C_bsbansnooze(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800000_bsbansnooze(player);
}

void func_80800674_bsbansnooze(s32 player)
{
    func_80800098_bsbansnooze();
    _bsdrone_entrypoint_0(player);
}

void func_8080069C_bsbansnooze(PlayerState *player)
{
    _bsdrone_entrypoint_1(player);
}

int bsbansnooze_entrypoint_3(int param_0)
{
    return D_80800A88_bsbansnooze[param_0];
}

void func_808006D0_bsbansnooze(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800000_bsbansnooze(player);
}

void func_808006F8_bsbansnooze(s32 player)
{
    func_80800098_bsbansnooze();
    _bsrest_entrypoint_16(player);
}

int func_80800720_bsbansnooze(Actor *actor)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20(actor)) {
        next_state = 0x16F;
    }
    bs_setState(actor, next_state);
}

int bsbansnooze_entrypoint_4(s32 param_0)
{
    return D_80800A98_bsbansnooze[param_0];
}

void func_8080076C_bsbansnooze(s32 player)
{
    func_800951B4();
    func_80800000_bsbansnooze(player);
}

void func_80800794_bsbansnooze(PlayerState *player)
{
    void *anim_ctrl;
    s32 health;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_80800098_bsbansnooze(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x277);
    anctrl_setDuration(anim_ctrl, 2.0f);
    func_8008B1C8(anim_ctrl, 0.6f);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 3, 8, 14);
    yaw_setVelocityBounded(player, 0x42C80000, 0x40600000);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009514C(player);
    _batimer_set(player, 0, 1.0f);
    health = func_800A1718(player);
    if (func_800A1760(player) == health)
        func_800A17A8(player, 0);
    if (bs_getPreviousState(player) == 0x170)
        player->unk15C.bytes[0] = 0;
    else
        player->unk15C.bytes[0] = 1;
}

// Heals one health point per second up to max; exits on B release.
void func_808008A4_bsbansnooze(PlayerState *player)
{
    s32 next_state;
    s32 health;

    next_state = 0;
    if (_batimer_decrement(player, 0)) {
        _batimer_set(player, 0, 1.0f);
        health = func_800A1718(player);
        if (health < func_800A1760(player)) {
            func_800FC660(8);
            func_800A17A8(player, 1);
        }
    }
    if (player->unk15C.bytes[0]) {
        if (baanim_isAt(player, player->unk15C.bytes[0] == 1 ? 0.1f : 0.01f)) {
            func_8009DEC0(player, 0x441, 0.93f, 1.08f, 20000, 22000);
        }
        if (baanim_isAt(player, 0.5f)) {
            func_8009DFD4(player, 0x442, 0.93f, 1.08f, 20000, 22000);
        }
    }
    if (baanim_isAt(player, 0.99f))
        player->unk15C.bytes[0] = 2;
    if (bakey_released(player, 1))
        next_state = 0x172;
    if (player_inWater(player))
        next_state = 0x4C;
    bs_setState(player, next_state);
}

s32 bsbansnooze_entrypoint_5(s32 param_0)
{
    return D_80800AA8_bsbansnooze[param_0];
}

// TU-NOTE: the overlay .data is defined here in C. The tables point to functions of this file;
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
// D_80800A60_bsbansnooze is declared as s32[] to match the object.
extern void func_80099B94();
extern void _bsdrone_entrypoint_3();
s32 D_80800A40_bsbansnooze[4] = {(u32) func_8080019C_bsbansnooze, (u32) func_808001FC_bsbansnooze,
                                 (u32) func_80800278_bsbansnooze, (u32) func_80099B94};
s32 D_80800A50_bsbansnooze[4] = {(u32) func_8080037C_bsbansnooze, (u32) func_8080039C_bsbansnooze,
                                 (u32) func_80800414_bsbansnooze, (u32) func_80099B94};
s32 D_80800A60_bsbansnooze[6] = {0x0, 0x3F800000, 0x3F000000, 0x0, 0x3F800000, 0x3F800000};
s32 D_80800A78_bsbansnooze[4] = {(u32) func_808004C0_bsbansnooze, (u32) func_808004E0_bsbansnooze,
                                 (u32) func_80800588_bsbansnooze, (u32) func_80099B94};
s32 D_80800A88_bsbansnooze[4] = {(u32) func_8080064C_bsbansnooze, (u32) func_80800674_bsbansnooze,
                                 (u32) func_8080069C_bsbansnooze, (u32) _bsdrone_entrypoint_3};
s32 D_80800A98_bsbansnooze[4] = {(u32) func_808006D0_bsbansnooze, (u32) func_808006F8_bsbansnooze,
                                 (u32) func_80800720_bsbansnooze, (u32) func_80099B94};
s32 D_80800AA8_bsbansnooze[6] = {(u32) func_8080076C_bsbansnooze,
                                 (u32) func_80800794_bsbansnooze,
                                 (u32) func_808008A4_bsbansnooze,
                                 (u32) func_80099B94,
                                 0x0,
                                 0x0};
