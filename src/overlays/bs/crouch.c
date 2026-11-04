// Crouch for Banjo-Kazooie and solo Banjo: slide, turn, fidgets, and the crouch move table.
// TU-NOTE: the overlay .data (D_80800990_bscrouch) is defined in this file. It points at
// functions of this file; IDO schedules some of them differently unless they share the unit.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/anim.h"
#include "core2/physics.h"
#include "overlays/ba/yaw.h"
#include "overlays/ba/timer.h"

extern f32 mlAbsF(f32);
extern void baphysics_set_target_horizontal_velocity(Actor *, f32);
void baphysics_set_target_yaw(PlayerState *, f32 target_yaw);

extern s32 D_80800990_bscrouch[];
extern void *_bapackctrl_entrypoint_1(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern s32 func_800CB7C4(void *, f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 bakey_released(PlayerState *, s32);
extern s32 bakey_pressed(PlayerState *, s32);
extern s32 func_800A055C(PlayerState *, s32);
extern s32 bs_getTypeOfJump(PlayerState *);
extern s32 func_8008E23C(PlayerState *);
extern s32 func_800C6E38(s32);
extern s32 func_8008E0C8(PlayerState *);
extern s32 bainput_should_wonderwing(PlayerState *);
extern void _suinv_entrypoint_0(s32 *, s32, s32, s32, s32);
extern s32 bainput_should_trot(PlayerState *);
extern s32 bainput_should_poop_egg(PlayerState *);
extern s32 func_80094B14(PlayerState *);
extern s32 bainput_should_shoot_egg(PlayerState *);
extern s32 bainput_should_flap_flip(PlayerState *);
extern s32 bainput_should_beak_barge(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800F1EA4(f32 *, f32 *);
extern void func_8009CFD8(PlayerState *, f32);
extern void _badust_entrypoint_9(PlayerState *);
extern void func_8009D658(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_8008E148(PlayerState *);
extern s32 _badrone_entrypoint_25(PlayerState *);
extern s32 func_8008DD04(PlayerState *);
extern s32 player_inWater(PlayerState *);
extern void bs_setState(PlayerState *, s32);

void func_80800000_bscrouch(void *player)
{
    baanim_playForDuration_loopSmooth(player, 0x10C, 0.5f);
    *(s32 *) ((char *) player + 0x15C) = 4;
}

void func_80800034_bscrouch(void *player)
{
    baanim_playForDuration_onceSmooth(player, 0x116, 2.0f);
    *(s32 *) ((char *) player + 0x15c) = 2;
}

void func_80800068_bscrouch(Actor *player)
{
    baanim_playForDuration_onceSmoothStartingAt(player, 0x10C, 0.5f, 0.9999f);
    _batimer_set(player, 2, 2.0f);
    *(int *) ((char *) player + 0x15C) = 1;
}

// Turn-in-place anim speed from turn rate.
void func_808000B4_bscrouch(s32 anim_ctrl, f32 turn_rate)
{
    anctrl_setDuration(anim_ctrl, func_800F10B4(turn_rate, 0.0f, 180.0f, 0.5f, 0.2f));
}

int func_808000FC_bscrouch(s32 player, s32 anim_ctrl)
{
    func_800A2CE8(player, 0x3ED1EB85, 4);
    func_800A2CE8(player, 0x3F68F5C3, 3);
}

void bscrouch_entrypoint_0(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 velocity[3];
    f32 anim_start;
    f32 yaw;
    s32 prev_state;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    prev_state = bs_getPreviousState(player);
    if (prev_state != 9 && prev_state != 0xA && prev_state != 0x1A)
        anim_start = 0.0f;
    else
        anim_start = 0.5357f;
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 1);
    anctrl_setDuration(anim_ctrl, 0.5f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_setStart(anim_ctrl, anim_start);
    anctrl_start(anim_ctrl);
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 3);
    yaw_setVelocityBounded(player, 350.0f, 14.0f);
    func_8009D2D8(player, 7);
    func_8009CFD8(player, 8.0f);
    baphysics_set_type(player, 3);
    _batimer_set(player, 0, 0.7f);
    _batimer_set(player, 1, 0.2f);
    func_8009BB24(player, velocity);
    player->unk16C = sqrtf(velocity[0] * velocity[0] + velocity[2] * velocity[2]);
    if (player->unk16C > 140.0f)
        func_8009D658(player);
    if (func_800F1EA4(velocity, &yaw))
        baphysics_set_target_yaw(player, yaw);
    player->unk15C.word = 0;
}

s32 bscrouch_entrypoint_4();

void bscrouch_entrypoint_1(PlayerState *player)
{
    s32 next_state;
    f32 target_speed;
    AnimCtrl *anim_ctrl;
    f32 turn_rate;
    f32 pad;
    f32 ideal_yaw;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _batimer_decrement(player, 0);
    _batimer_decrement(player, 1);
    target_speed = func_800F10B4(_batimer_get(player, 0), 0.0f, 0.3f, 0.0f, player->unk16C);
    baphysics_set_target_horizontal_velocity(player, target_speed);
    if (220.0f < target_speed)
        _badust_entrypoint_9(player);
    if (160.0f < target_speed)
        func_8009D658(player);
    if (bastick_distance(player) == 0.0f)
        yaw_setIdeal(player, yaw_get(player));
    ideal_yaw = yaw_getIdeal(player);
    turn_rate = mlAbsF(func_800F1DCC(ideal_yaw, yaw_get(player)));

    switch (player->unk15C.word) {
        case 0:
            if (target_speed != 0.0f)
                break;
            _batimer_set(player, 2, 2.0f);
            player->unk15C.word = 1;
            break;

        case 1:
            if (turn_rate != 0.0f) {
                func_80800000_bscrouch(player);
            } else {
                _batimer_decrement(player, 2);
                if (_batimer_isZero(player, 2))
                    func_80800034_bscrouch(player);
            }
            break;

        case 2:
            if (turn_rate != 0.0f) {
                func_80800000_bscrouch(player);
            } else {
                if (anctrl_isStopped(anim_ctrl))
                    func_80800068_bscrouch(player);
            }
            break;

        case 4:
            func_808000B4_bscrouch(anim_ctrl, turn_rate);
            func_808000FC_bscrouch(player, anim_ctrl);
            if (turn_rate != 0.0f)
                break;
            if (anctrl_getAnimTimer(anim_ctrl) <= 0.5f) {
                anctrl_setSubrange(anim_ctrl, 0, 0.5f);
            } else {
                anctrl_setSubrange(anim_ctrl, 0, 1.0f);
            }
            anctrl_setPlaybackType(anim_ctrl, 1);
            player->unk15C.word = 3;
            break;

        case 3:
            func_808000B4_bscrouch(anim_ctrl, turn_rate);
            func_808000FC_bscrouch(player, anim_ctrl);
            if (turn_rate != 0.0f) {
                anctrl_setSubrange(anim_ctrl, 0, 1.0f);
                anctrl_setPlaybackType(anim_ctrl, 2);
                player->unk15C.word = 4;
            } else {
                if (anctrl_isStopped(anim_ctrl)) {
                    yaw_setIdeal(player, yaw_get(player));
                    func_80800068_bscrouch(player);
                }
            }
    }

    if (func_8008E148(player))
        next_state = _badrone_entrypoint_25(player);
    if (func_8008DD04(player))
        next_state = 0x2F;
    next_state = bscrouch_entrypoint_4(player, next_state);
    if (next_state == 1 && _batimer_isNonzero(player, 1))
        next_state = 0;
    if (player_inWater(player))
        next_state = 0x2D;
    bs_setState(player, next_state);
}

void bscrouch_entrypoint_2(s32 player)
{
}

int bscrouch_entrypoint_3(s32 index)
{
    return D_80800990_bscrouch[index];
}

// Picks the taxi/sack target for the pack move; result 2 also turns toward it.
s32 func_808006A4_bscrouch(PlayerState *player)
{
    f32 pos[3];
    f32 target_pos[3];
    void *pack_ctrl;
    s32 result;

    pack_ctrl = _bapackctrl_entrypoint_1(player);
    func_8009C128(player, pos);
    result = func_800CB7C4(pack_ctrl, pos, target_pos);
    if (result == 2) {
        yaw_setIdeal(player, func_800F1DF4(pos, target_pos));
    }
    return result;
}

// Crouch move table. Solo Banjo: pack moves on C buttons gated by abilities; otherwise duo moves.
s32 bscrouch_entrypoint_4(PlayerState *player, s32 next_state)
{
    if (bakey_released(player, 1)) {
        next_state = 1;
        if (bakey_pressed(player, 9)) {
            next_state = func_800A055C(player, next_state);
        }
        if (bakey_pressed(player, 8)) {
            next_state = bs_getTypeOfJump(player);
        }
        return next_state;
    }
    if (func_8008E23C(player)) {
        if (bakey_pressed(player, 0xB) && func_800C6E38(0x21)) {
            next_state = 0x16A;
        } else if (bakey_pressed(player, 0xC) && func_800C6E38(0x2A)) {
            next_state = 0x163;
        } else if (bakey_pressed(player, 0xD) && func_800C6E38(0x23)) {
            next_state = 0x171;
        } else if (bakey_pressed(player, 0xA) && func_800C6E38(0x27)) {
            if (!func_8008E0C8(player)) {
                next_state = 0x122;
            } else {
                switch (func_808006A4_bscrouch(player)) {
                    case 0:
                        break;
                    case 1:
                        next_state = 0x129;
                        break;
                    case 2:
                        next_state = 0x128;
                }
            }
        }
        if (bakey_pressed(player, 8)) {
            next_state = 0x6C;
        }
        return next_state;
    } else {
        if (bainput_should_wonderwing(player)) {
            _suinv_entrypoint_0(&next_state, -1, 0x1A, 0x47, 1);
        }
        if (bainput_should_trot(player)) {
            next_state = 0x14;
        }
        if (bainput_should_poop_egg(player) && func_80094B14(player)) {
            next_state = 0xA;
        }
        if (bainput_should_shoot_egg(player) && func_80094B14(player)) {
            next_state = 9;
        }
        if (bainput_should_flap_flip(player)) {
            next_state = 0x12;
        }
        if (bainput_should_beak_barge(player)) {
            next_state = 0x13;
        }
    }
    return next_state;
}

extern void _bscrouch_entrypoint_2();
extern void _bscrouch_entrypoint_0();
extern void _bscrouch_entrypoint_1();
extern void func_8009AB78();
s32 D_80800990_bscrouch[4] = {(u32) _bscrouch_entrypoint_2, (u32) _bscrouch_entrypoint_0,
                              (u32) _bscrouch_entrypoint_1, (u32) func_8009AB78};
