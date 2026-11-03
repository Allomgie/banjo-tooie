#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void _badust_entrypoint_5(s32, f32, f32);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void _basudie_entrypoint_4(PlayerState *, f32, f32, f32, f32, f32);
extern void func_8009D820(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void _basudie_entrypoint_5(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 player_isStable(PlayerState *);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void func_8009E058(PlayerState *);
extern void func_8009E084(PlayerState *);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);
extern void _badust_entrypoint_9(PlayerState *);
extern s32 _basudie_entrypoint_7(PlayerState *);
extern void bs_setState(PlayerState *, s32);
extern void _basudie_entrypoint_6(void);
extern void func_800A0CF4(s32, s32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80800960_bsdie[];
extern void baanim_setEnd(PlayerState *, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 D_80800970_bsdie[];
extern s32 D_80800980_bsdie[];

// Spawns a ring of 8 dust puffs around the player.
void func_80800000_bsdie(s32 player)
{
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        _badust_entrypoint_5(player, angle, 230.0f);
    }
}

// Death variant 1 (anim 9): knocked up and back.
void bsdie_entrypoint_0(PlayerState *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 9);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.3356f);
    anctrl_setDuration(anim_ctrl, 2.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    player->unk16C = 250.0f;
    _basudie_entrypoint_4(player, 250.0f, 510.0f, -1400.0f, 25.0f, 3.5f);
    func_800A0CF4(player, 1);
    func_8009D820(player, 1.0f);
    func_8009BFE4(player, 1000.0f, 12.0f);
    player->unk15C.word = 0;
}

void bsdie_entrypoint_1(PlayerState *player)
{
    void *anim_ctrl;
    s32 next_state;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    _basudie_entrypoint_5(player);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
    switch (player->unk15C.word) {
        case 0:
            if (player_isStable(player)) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                baphysics_set_vertical_velocity(player, 400.0f);
                func_8009E058(player);
                func_8009DF18(player, 0x428, 1.0f, 18000);
                _bamotor_entrypoint_1(player, 1.0, 1.0, 0.4f);
                func_80800000_bsdie(player);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(player)) {
                func_8009E084(player);
                func_8009DF18(player, 0x427, 1.0f, 18000);
                _bamotor_entrypoint_1(player, 1.0f, 0.5f, 0.4f);
                player->unk15C.word = 2;
            }
            break;
        case 2:
            player->unk16C = func_800F0E00(player->unk16C - 12.0f, 0.0f);
            if (140.0f < player->unk16C) {
                _badust_entrypoint_9(player);
            }
            if (anctrl_isAt(anim_ctrl, 0.6538f)) {
                anctrl_setDuration(anim_ctrl, 4.0f);
            }
            if (anctrl_isStopped(anim_ctrl)) {
                player->unk16C = 0.0f;
                player->unk15C.word = 3;
            }
        case 3:
            break;
    }
    if (_basudie_entrypoint_7(player)) {
        next_state = 0x54;
    }
    bs_setState(player, next_state);
}

void bsdie_entrypoint_2(s32 player)
{
    _basudie_entrypoint_6();
    func_800A0CF4(player, 0);
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
}

int bsdie_entrypoint_3(s32 index)
{
    return D_80800960_bsdie[index];
}

// Death variant 2 (anim 0xD8).
void bsdie_entrypoint_4(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0xD8);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.0932f);
    anctrl_setDuration(anim_ctrl, 4.7f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    // Matching: raw offset accesses are needed for the match.
    *(f32 *) ((u8 *) player + 0x16C) = 250.0f;
    _basudie_entrypoint_4(player, *(f32 *) ((u8 *) player + 0x16C), 510.0f, -1400.0f, 30.0f,
                          4.0f);
    func_800A0CF4(player, 1);
    func_8009BFE4(player, 1000.0f, 12.0f);
    func_8009D820(player, 1.0f);
    *(s32 *) ((u8 *) player + 0x15C) = 0;
}

void bsdie_entrypoint_5(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 next_state;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    _basudie_entrypoint_5(player);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
    switch (player->unk15C.word) {
        case 3:
            break;
        case 0:
            if (func_8008DF8C(player, 0x96)) {
                baanim_setEnd(player, 0.1863f);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(player)) {
                func_8009DF18(player, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(player, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(player);
                func_8009E058(player);
                baanim_setEnd(player, 0.3333f);
                player->unk15C.word = 2;
            }
            break;
        case 2:
            player->unk16C = func_800F0E00(player->unk16C - 12.0f, 0.0f);
            if (player->unk16C > 140.0f) {
                _badust_entrypoint_9(player);
            }
            if (anctrl_isStopped(anim_ctrl)) {
                baanim_setEnd(player, 1.0f);
                player->unk15C.word = 3;
                player->unk16C = 0.0f;
            }
    }
    if (_basudie_entrypoint_7(player)) {
        next_state = 0x54;
    }
    bs_setState(player, next_state);
}

void bsdie_entrypoint_6(s32 player)
{
    _basudie_entrypoint_6();
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    func_800A0CF4(player, 0);
}

int bsdie_entrypoint_7(s32 index)
{
    return D_80800970_bsdie[index];
}

// Death variant 3 (anim 0xD7).
void bsdie_entrypoint_8(PlayerState *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    player->unk16C = 250.0f;
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0xD7);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.0981f);
    anctrl_setDuration(anim_ctrl, 3.8f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    _basudie_entrypoint_4(player, player->unk16C, 510.0f, -1400.0f, 30.0f, 3.8f - 0.4f);
    func_8009BFE4(player, 1000.0f, 12.0f);
    func_8009D820(player, 1.0f);
    player->unk15C.word = 0;
}

void bsdie_entrypoint_9(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 next_state;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    _basudie_entrypoint_5(player);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
    switch (player->unk15C.word) {
        case 3:
            break;
        case 0:
            if (func_8008DF8C(player, 0xC8)) {
                baanim_setEndAndDuration(player, 0.1961f, 3.1f);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(player)) {
                func_8009DF18(player, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(player, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(player);
                func_8009E058(player);
                baanim_setEnd(player, 0.75f);
                player->unk15C.word = 2;
            }
            break;
        case 2:
            player->unk16C = func_800F0E00(player->unk16C - 7.0f, 0.0f);
            if (player->unk16C > 140.0f) {
                _badust_entrypoint_9(player);
            }
            if (anctrl_isStopped(anim_ctrl)) {
                baanim_setEnd(player, 1.0f);
                player->unk15C.word = 3;
                player->unk16C = 0.0f;
            }
    }
    if (_basudie_entrypoint_7(player)) {
        next_state = 0x54;
    }
    bs_setState(player, next_state);
}

void bsdie_entrypoint_10(s32 player)
{
    _basudie_entrypoint_6();
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
}

int bsdie_entrypoint_11(int index)
{
    return D_80800980_bsdie[index];
}

// TU-NOTE: the overlay's .data is defined here, taken from the ROM. The tables point to functions
// of this file; IDO schedules some of them differently unless the tables are in the same unit.
extern void _bsdie_entrypoint_2();
extern void _bsdie_entrypoint_0();
extern void _bsdie_entrypoint_1();
extern void _basudie_entrypoint_11();
extern void _bsdie_entrypoint_6();
extern void _bsdie_entrypoint_4();
extern void _bsdie_entrypoint_5();
extern void _bsdie_entrypoint_10();
extern void _bsdie_entrypoint_8();
extern void _bsdie_entrypoint_9();
s32 D_80800960_bsdie[4] = {(u32) _bsdie_entrypoint_2, (u32) _bsdie_entrypoint_0,
                           (u32) _bsdie_entrypoint_1, (u32) _basudie_entrypoint_11};
s32 D_80800970_bsdie[4] = {(u32) _bsdie_entrypoint_6, (u32) _bsdie_entrypoint_4,
                           (u32) _bsdie_entrypoint_5, (u32) _basudie_entrypoint_11};
s32 D_80800980_bsdie[4] = {(u32) _bsdie_entrypoint_10, (u32) _bsdie_entrypoint_8,
                           (u32) _bsdie_entrypoint_9, (u32) _basudie_entrypoint_11};
