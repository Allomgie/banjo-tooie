#include "bs/blongleg.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern f32 bastatetimer_getPrevious(PlayerState *, s32);
extern f32 bastatetimer_get(PlayerState *, s32);
extern void _baalarm_entrypoint_3(PlayerState *, f32, f32);
extern s32 bastatetimer_isAt(PlayerState *, s32, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 func_8009E74C(PlayerState *, s32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void _baalarm_free(PlayerState *);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void _batimer_incrementBy(PlayerState *, s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 func_800A3394(PlayerState *);
extern void bastatetimer_set(PlayerState *, s32, f32);
extern s32 D_80801470_bsblongleg[];
extern s32 D_80801480_bsblongleg[];
extern void func_8009D2F0(PlayerState *, s32, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80801490_bsblongleg[];
extern void func_8009D3A8(PlayerState *, s32);
extern s32 D_808014A0_bsblongleg[];
extern s32 D_808014B0_bsblongleg[];
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 D_808014C0_bsblongleg[];
extern s32 _bsrest_entrypoint_20(s32);
extern s32 _bsrest_entrypoint_13(s32);
extern s32 D_808014D0_bsblongleg[];
extern s32 D_808014E0_bsblongleg[];
extern void func_8008C9F0(void *, int, int, int, float);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern f32 func_8009C150(PlayerState *);
extern f32 func_80096364(PlayerState *);

// Wading boots (BK "long leg" shoes). State timer 2 runs the shoes out; step sound 0x41D loops.

s32 func_80800000_bsblongleg(PlayerState *player)
{
    return player_inWater(player);
}

// Footstep sound; flag picks the pitch.
int func_80800020_bsblongleg(Actor *player, s32 flag)
{
    if (flag != 0) {
        func_8009DE38(player, 0x4433, 0.88f);
    } else {
        func_8009DE38(player, 0x4433, 0.96f);
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800064_bsblongleg(PlayerState *player)
{
    f32 zone_pos;

    zone_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(zone_pos, 80.0f, 500.0f));
    }
}

extern void func_8080013C_bsblongleg();

// Per-frame shoe timer upkeep: alarm beep as the timer runs down.
void func_808000C8_bsblongleg(player) PlayerState *player;
{
    _baalarm_entrypoint_3(player, bastatetimer_getPrevious(player, 2),
                          bastatetimer_get(player, 2));
    if (bastatetimer_isAt(player, 2, 0.01f)) {
        func_8009DE38(player, 0x3EB, 1.0f);
    }
}

extern void func_800931AC(Actor *a0, s32 a1);

// Shared enter setup for the shoe states.
void func_8080013C_bsblongleg(player) Actor *player;
{
    if (!func_8009E77C(player, 8)) {
        func_8009E53C(player, 1, -5e+01f);
        bastick_setZoneMax(player, 0, 0x3CF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        func_800A0CF4(player, 1);
        func_800A0CE8(player, 1);
        func_800A0DD0(player, 1);
        func_8009BFE4(player, 1e+03f, 12.0f);
        baroll_setAngularVelocity(player, 1e+03f, 12.0f);
        baflag_set(player, 3);
        func_800931AC(player, 2);
        _baalarm_new(player);
    }
}

// Shared exit cleanup: frees the alarm, clears timer 2, music layer back to 1.
void func_80800204_bsblongleg(player) PlayerState *player;
{
    if (!func_8009E74C(player, 8)) {
        _baalarm_free(player);
        func_8009E53C(player, 1, 0.0f);
        bastick_resetZones(player);
        func_800A0CF4(player, 0);
        func_800A0CE8(player, 0);
        func_800A0DD0(player, 0);
        func_800931AC(player, 1);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        bastatetimer_clear(player, 2);
        func_800C77DC(1);
        baflag_clear(player, 3);
        _batimer_incrementBy(player, 4, 0.5f);
        func_808000C8_bsblongleg(player);
    }
}

// Put-on animation; starts shoe timer 2 and switches music layer to 2.
void func_808002D8_bsblongleg(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x40);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    bastatetimer_set(player, 2, func_800A3394(player));
    func_800C77DC(2);
    func_800C3BDC(player->unk160.bytes[0]);
    player->unk15C.word = 1;
}

void func_80800378_bsblongleg(u8 *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x16);
    anctrl_setDuration(anim_ctrl, 0.5f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    *(s32 *) ((s8 *) player + 0x15C) = 0;
}

extern void func_800C3730(u8, f32, f32, f32);

extern void func_800C330C(u8 param_0, s32 param_1);

extern void func_800C301C(u8 param_0, s32 param_1);

extern s32 func_800C2E04();

extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);

// Enter: put on the shoes.
void bsblongleg_entrypoint_0(PlayerState *player)
{
    player->unk160.bytes[0] = func_800C2E04();
    func_800C301C(player->unk160.bytes[0], 0x41D);
    func_800C330C(player->unk160.bytes[0], 3);
    func_800C3730(player->unk160.bytes[0], 0.8f, 1.9f, 1.2f);
    baflag_clear(player, 14);
    if (func_8009CA70(player, bs_getPreviousState(player), 0x40))
        func_808002D8_bsblongleg(player);
    else
        func_80800378_bsblongleg(player);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8080013C_bsblongleg(player);
    func_8009D874(player);
}

void bsblongleg_entrypoint_1(u8 *player)
{
    s32 next_state;
    s32 anim_ctrl;
    s32 phase;
    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_808000C8_bsblongleg(player);
    func_8009D2F0(player, 1, 0.5f);
    phase = *(s32 *) ((s8 *) player + 0x15C);
    switch (phase) {
        case 0:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                func_808002D8_bsblongleg(player);
            }
            break;

        case 1:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = 0x26;
            }
    }

    bs_setState(player, next_state);
}

void bsblongleg_entrypoint_2(void *player)
{
    func_80800204_bsblongleg();
    func_800C2FDC(*(unsigned char *) ((char *) player + 0x160));
}

int bsblongleg_entrypoint_3(s32 slot)
{
    return D_80801470_bsblongleg[slot];
}

int bsblongleg_entrypoint_4(Actor *player)
{
    extern void baanim_playForDuration_loopSmooth(Actor * a0, s32 a1, f32 a2);

    baanim_playForDuration_loopSmooth(player, 0x41, 1.0f);
    func_8009FFD8(player, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800931AC(player, 2);
    func_8080013C_bsblongleg(player);
}

// Idle update: 0x27 walk, 0x28 jump, 0x29 timer out, 0x4C in water.
void bsblongleg_entrypoint_5(s32 player)
{
    s32 next_state;

    next_state = 0;
    func_808000C8_bsblongleg();
    func_8009D2F0(player, 1, 0.5f);
    if (bainput_should_enter_first_person(player) != 0) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (bakey_pressed(player, 9) != 0) {
        bastatetimer_clear(player, 2);
    }
    if (bastick_getZone(player) > 0) {
        next_state = 0x27;
    }
    if (func_8008DF18(player) != 0) {
        next_state = 0x55;
    }
    if ((bakey_pressed(player, 8) != 0) && (player_isStable(player) != 0)) {
        next_state = 0x28;
    }
    if (bastatetimer_isDone(player, 2) != 0) {
        next_state = 0x29;
    }
    if (func_80800000_bsblongleg(player) != 0) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

void bsblongleg_entrypoint_6()
{
    func_80800204_bsblongleg();
}

int bsblongleg_entrypoint_7(s32 slot)
{
    return D_80801480_bsblongleg[slot];
}

void bsblongleg_entrypoint_8(Actor *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x42);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 2, 1, 1, 2);
    func_8008C9F0(player, 0x42A00000, 0x43FA0000, 0x3F800000, 0.8f);
}

// Walk update: footsteps on animation time, same exits as idle.
void bsblongleg_entrypoint_9(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;
    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808000C8_bsblongleg(player);
    func_8009D2F0(player, 1, 0.5f);
    func_800A2CE8(player, 0.47f, 4);
    func_800A2CE8(player, 0.97f, 3);
    if (anctrl_isAt(anim_ctrl, 0.7781f))
        func_80800020_bsblongleg(player, 0);
    if (anctrl_isAt(anim_ctrl, 0.2781f))
        func_80800020_bsblongleg(player, 1);
    func_80800064_bsblongleg(player);
    if (bakey_pressed(player, 9) && baphysics_get_target_horizontal_velocity(player) == 0.0f)
        bastatetimer_clear(player, 2);
    if (bastick_getZone(player) == 0 && func_8009BCD4(player, 1.0f))
        next_state = 0x26;
    if (func_8008DF18(player))
        next_state = 0x55;
    if (bakey_pressed(player, 8) && player_isStable(player))
        next_state = 0x28;
    if (bastatetimer_isDone(player, 2))
        next_state = 0x29;
    if (func_80800000_bsblongleg(player))
        next_state = 0x4C;
    bs_setState(player, next_state);
}

void bsblongleg_entrypoint_10()
{
    func_80800204_bsblongleg();
}

int bsblongleg_entrypoint_11(s32 slot)
{
    return D_80801490_bsblongleg[slot];
}

void func_80800994_bsblongleg(player) u8 *player;
{
    s32 anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    func_8008B188(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x40);
    anctrl_setDuration(anim_ctrl, 0.4f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    (*(s32 *) ((s8 *) (player) + (0x15C))) = 0;
}

void func_80800A18_bsblongleg(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 7);
    anctrl_setDuration(anim_ctrl, 0.3f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    player->unk15C.word = 1;
}

int bsblongleg_entrypoint_12(Actor *player)
{
    s32 sound;
    extern void func_8008CA4C(Actor * param_0, s32 param_1);
    extern void func_8009D2D8(Actor * param_0, s32 param_1);

    func_80800994_bsblongleg();
    func_8008CA4C(player, 1);
    func_8009D2D8(player, 2);
    baphysics_set_target_horizontal_velocity(player, 0);
    sound = func_800C2E04();
    *(u8 *) ((u8 *) player + 0x160) = sound;
    func_800C301C(sound, 0x41D);
    func_800C330C(*(u8 *) ((u8 *) player + 0x160), 3);
    func_800C3730(*(u8 *) ((u8 *) player + 0x160), 1.4f, 0.4f, -1.2f);
}

void bsblongleg_entrypoint_13(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_8009D3A8(player, 1);

    switch (player->unk15C.word) {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.68f))
                func_800C3BDC(player->unk160.bytes[0]);
            if (anctrl_isStopped(anim_ctrl))
                func_80800A18_bsblongleg(player);
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl))
                next_state = 1;
    }

    if (func_80800000_bsblongleg(player))
        next_state = 0x4C;
    bs_setState(player, next_state);
}

int bsblongleg_entrypoint_14(s32 player)
{
    func_800C2FDC(*(u8 *) ((char *) player + 0x160));
    func_80800204_bsblongleg(player);
}

int bsblongleg_entrypoint_15(s32 slot)
{
    return D_808014A0_bsblongleg[slot];
}

// Jump enter: launches upward.
void bsblongleg_entrypoint_16(PlayerState *player)
{
    AnimCtrl *anim_ctrl = baanim_getAnimCtrlPtr(player);

    *(f32 *) ((u8 *) player + 0x16C) = 0.14f;
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x3D);
    func_8008B1C8(anim_ctrl, 0.134f);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setStart(anim_ctrl, *(f32 *) ((u8 *) player + 0x16C));
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.42f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    if (bastick_distance(player) != 0.0f)
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800064_bsblongleg(player);
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 400.0f);
    baphysics_set_gravity(player, -800.0f);
    func_8009DE38(player, 0x4432, 0.9f);
    *(s32 *) ((u8 *) player + 0x15C) = 0;
}

// Jump update; substate in unk15C.
void bsblongleg_entrypoint_17(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];
    f32 unk_0;
    f32 unk_1;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808000C8_bsblongleg(player);
    func_80800064_bsblongleg(player);
    func_8009BB24(player, velocity);

    if (bakey_released(player, 8) && velocity[1] > 0.0f) {
        baphysics_reset_gravity(player);
    }

    unk_1 = func_8009C150(player);
    unk_0 = unk_1 - func_80096364(player);

    switch (player->unk15C.word) {
        case 0:
            if (velocity[1] < 100.0f || unk_0 < 10.0f) {
                anctrl_setDuration(anim_ctrl, 0.4f);
            }
            if (anctrl_isStopped(anim_ctrl)) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.5281999707f);
                anctrl_setDuration(anim_ctrl, 4.5f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (anctrl_getAnimTimer(anim_ctrl) > 0.4f && unk_0 < 70.0f) {
                player->unk16C = anctrl_getAnimTimer(anim_ctrl);
                player->unk170 = unk_0;
                anctrl_setPlaybackType(anim_ctrl, 3);
                player->unk15C.word = 2;
            }
            break;
        case 2:
            func_8008B10C(anim_ctrl,
                          func_800F10B4(unk_0, player->unk170, 1.0f, player->unk16C, 0.6703f));
            func_8009D2F0(player, 1, 0.5f);
            if (player_isStable(player)) {
                func_8009FE58(player);
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 1.3f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                player->unk15C.word = 3;
            }
            break;
        case 3:
            func_8009D2F0(player, 1, 0.5f);
            if (anctrl_isStopped(anim_ctrl)) {
                next_state = 0x26;
            }
            if (bakey_pressed(player, 8)) {
                next_state = 0x28;
            }
            if (bastatetimer_isDone(player, 2)) {
                next_state = 0x29;
            }
    }

    if (func_80800000_bsblongleg(player)) {
        next_state = 0x4C;
    }

    bs_setState(player, next_state);
}

void bsblongleg_entrypoint_18(s32 player)
{
    baphysics_reset_gravity();
    func_80800204_bsblongleg(player);
}

int bsblongleg_entrypoint_19(s32 slot)
{
    return D_808014B0_bsblongleg[slot];
}

void bsblongleg_entrypoint_20(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x3D);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_setStart(anim_ctrl, 0.0865f);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 3);
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    func_800A0CF4(player, 1);
    func_800A0CE8(player, 1);
    func_8009BFE4(player, 1000.0f, 12.0f);
    baroll_setAngularVelocity(player, 1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009D658(player);
    _batimer_set(player, 0, 1.0f);
    func_8080013C_bsblongleg(player);
}

void bsblongleg_entrypoint_21(PlayerState *player)
{
    s32 next_state = 0;
    f32 vec[3];
    f32 yaw;
    func_808000C8_bsblongleg(player);
    func_8009D658(player);
    _batimer_decrement(player, 0);

    if (func_8008E148(player)) {
        func_800963C0(player, vec);
        func_800F1EA4(vec, &yaw);
        func_8009D2F0(player, 1, 0.5f);
        baphysics_set_target_horizontal_velocity(
            player, func_800F10B4(func_8009BFD8(player), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(player, yaw);
        _badust_entrypoint_1(player);
    } else
        next_state = 0x26;

    if (_batimer_isZero(player, 0) && bakey_pressed(player, 8))
        next_state = 0x28;
    if (func_80800000_bsblongleg(player))
        next_state = 0x4C;
    bs_setState(player, next_state);
}

void bsblongleg_entrypoint_22()
{
    func_80800204_bsblongleg();
}

int bsblongleg_entrypoint_23(s32 slot)
{
    return D_808014C0_bsblongleg[slot];
}

void bsblongleg_entrypoint_24(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800204_bsblongleg(player);
}

void bsblongleg_entrypoint_25(s32 player)
{
    func_8080013C_bsblongleg();
    _bsrest_entrypoint_16(player);
}

// Wraps bs/rest.
void bsblongleg_entrypoint_26(s32 player)
{
    s32 next_state = 0;
    func_808000C8_bsblongleg(player);
    func_8009D3A8(player, 1);

    if (_bsrest_entrypoint_20(player)) {
        next_state = _bsrest_entrypoint_13(player);
    }

    bs_setState(player, next_state);
}

int bsblongleg_entrypoint_27(s32 slot)
{
    return D_808014D0_bsblongleg[slot];
}

void bsblongleg_entrypoint_28(s32 player)
{
    func_8080013C_bsblongleg();
    _bsdrone_entrypoint_0(player);
}

// Wraps bs/drone; leaves to 0x29 when timer 2 runs out.
int bsblongleg_entrypoint_29(Actor *player)
{
    func_808000C8_bsblongleg();
    _bsdrone_entrypoint_1(player);

    if (bastatetimer_isDone(player, 2)) {
        bs_setState(player, 0x29);
    }
}

void bsblongleg_entrypoint_30(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800204_bsblongleg(player);
}

int bsblongleg_entrypoint_31(s32 slot)
{
    return D_808014E0_bsblongleg[slot];
}

// TU-NOTE: the overlay .data tables are defined here in C (values from the ROM); IDO schedules
// some functions differently unless the tables are in the same unit.
extern void _bsblongleg_entrypoint_2();
extern void _bsblongleg_entrypoint_0();
extern void _bsblongleg_entrypoint_1();
extern void func_8009AB78();
extern void _bsblongleg_entrypoint_6();
extern void _bsblongleg_entrypoint_4();
extern void _bsblongleg_entrypoint_5();
extern void _bsblongleg_entrypoint_10();
extern void _bsblongleg_entrypoint_8();
extern void _bsblongleg_entrypoint_9();
extern void _bsblongleg_entrypoint_14();
extern void _bsblongleg_entrypoint_12();
extern void _bsblongleg_entrypoint_13();
extern void _bsblongleg_entrypoint_18();
extern void _bsblongleg_entrypoint_16();
extern void _bsblongleg_entrypoint_17();
extern void func_80099B94();
extern void _bsblongleg_entrypoint_22();
extern void _bsblongleg_entrypoint_20();
extern void _bsblongleg_entrypoint_21();
extern void _bsblongleg_entrypoint_24();
extern void _bsblongleg_entrypoint_25();
extern void _bsblongleg_entrypoint_26();
extern void _bsblongleg_entrypoint_30();
extern void _bsblongleg_entrypoint_28();
extern void _bsblongleg_entrypoint_29();
extern void _bsdrone_entrypoint_3();
s32 D_80801470_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_2, (u32) _bsblongleg_entrypoint_0,
                                (u32) _bsblongleg_entrypoint_1, (u32) func_8009AB78};
s32 D_80801480_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_6, (u32) _bsblongleg_entrypoint_4,
                                (u32) _bsblongleg_entrypoint_5, (u32) func_8009AB78};
s32 D_80801490_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_10, (u32) _bsblongleg_entrypoint_8,
                                (u32) _bsblongleg_entrypoint_9, (u32) func_8009AB78};
s32 D_808014A0_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_14, (u32) _bsblongleg_entrypoint_12,
                                (u32) _bsblongleg_entrypoint_13, (u32) func_8009AB78};
s32 D_808014B0_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_18, (u32) _bsblongleg_entrypoint_16,
                                (u32) _bsblongleg_entrypoint_17, (u32) func_80099B94};
s32 D_808014C0_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_22, (u32) _bsblongleg_entrypoint_20,
                                (u32) _bsblongleg_entrypoint_21, (u32) func_8009AB78};
s32 D_808014D0_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_24, (u32) _bsblongleg_entrypoint_25,
                                (u32) _bsblongleg_entrypoint_26, (u32) func_80099B94};
s32 D_808014E0_bsblongleg[4] = {(u32) _bsblongleg_entrypoint_30, (u32) _bsblongleg_entrypoint_28,
                                (u32) _bsblongleg_entrypoint_29, (u32) _bsdrone_entrypoint_3};
