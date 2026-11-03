// TU-NOTE: the overlay .data (tables below) is defined in this file. The tables point at
// functions of this file; IDO schedules some of them differently unless they share the unit.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

typedef struct {
    s32 unk_0;
    s32 unk_4;
} ClimbPair;
extern u8 D_808008C0_bsclimb[];
extern s32 func_80098634(void);
extern void func_8009DF94(s32, s32, s32, s32);
extern f32 func_800DC0C0(void);
extern f32 func_8009BB0C(PlayerState *);
extern f32 mlAbsF(f32);
extern f32 yaw_get(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 func_800D8FF8(void);
extern void func_800956B8(PlayerState *);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern s32 D_808008FC_bsclimb[];
extern int baanim_isAt(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern f32 func_800985B8(PlayerState *);
extern f32 func_8009864C(PlayerState *);
extern s32 D_8080090C_bsclimb[];
extern s32 D_8080091C_bsclimb[];
extern f32 bastick_getY(PlayerState *);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern void func_8009B94C(PlayerState *, f32 *);
extern void baanim_playForDuration_loopSmooth(void *param_0, int param_1, float param_2);
extern void baanim_setDurationRange(void *param_0, float param_1, float param_2);
extern void func_8008C9F0(void *param_0, float param_1, float param_2, float param_3,
                          float param_4);
extern void func_8008CA4C(void *param_0, int param_1);

// Plays the climb sound pair for the current climb surface.
void func_80800000_bsclimb(s32 player, s32 index)
{
    u8 *sound_entry = D_808008C0_bsclimb + func_80098634() * 20;
    ClimbPair *sound_pairs = (ClimbPair *) (sound_entry - 0x10);
    func_8009DF94(player, *(s16 *) (sound_entry - 0x12), sound_pairs[index].unk_0, sound_pairs[index].unk_4);
}

// Maps stick Y to climb speed (100-300 units/s).
void func_8080005C_bsclimb(player) PlayerState *player;
{
    f32 velocity[3];
    f32 stick_y;
    f32 speed;
    stick_y = bastick_getY(player);
    if (mlAbsF(stick_y) < 0.03f)
        speed = 0.0f;
    else
        speed = func_800F1344(stick_y, 0.03f, 1.0f, 100.0f, 300.0f);
    velocity[0] = 0.0f;
    velocity[1] = speed;
    velocity[2] = 0.0f;
    func_8009B94C(player, velocity);
}

void func_808000E8_bsclimb(s32 player)
{
    if (func_8009861C() == 2) {
        func_8009D2D8(player, 3);
    } else {
        func_8009D2D8(player, 6);
    }
    yaw_setUpdateType(player, 3);
    yaw_setVelocityBounded(player, 0x43FA0000, 0x41700000);
    bastick_setZoneMax(player, 0, 0x3CF5C28F);
    bastick_setZoneMax(player, 1, 0x3F800000);
    baphysics_set_type(player, 0xA);
    func_8009BC5C(player, 0x41200000);
    func_800961AC(player, 5);
    func_800959C8(player, 0x42A00000, 0x41200000);
    func_800A4DA4(player, 0xC);
    if (func_8008E0E8(player) != 0) {
        _bapackctrl_entrypoint_5(player, 4);
    }
}

int func_808001D0_bsclimb(player)
s32 player;
{
    s32 player_copy;
    // Matching: "| 0" copy needed for the match.
    player_copy = player | 0;
    if (!func_8009E74C(player_copy, 0xA)) {
        func_800A4E30(player_copy);
        bastick_resetZones(player_copy);
        func_8008CA4C(player_copy, 1);
        baphysics_set_type(player_copy, 2);
        func_800961AC(player_copy, 1);
        func_80095A40(player_copy);
        if (func_8008E0E8(player_copy)) {
            _bapackctrl_entrypoint_5(player_copy, 3);
        }
    }
}

void func_80800258_bsclimb(u8 *player, f32 base, f32 range)
{
    *(f32 *) (player + 0x16C) = func_800DC0C0() * range + base;
}

int func_80800298_bsclimb(PlayerState *player)
{
    return mlAbsF(func_8009BB0C(player)) > 0.0f || yaw_get(player) != yaw_getIdeal(player);
}

void bsclimb_entrypoint_0(u8 *player)
{
    s32 yaw;
    f32 unk_1[3];
    f32 unk_2[3];

    func_8008FE68(unk_1);
    func_80098590(player, unk_2);
    if (func_8009E77C(player, 0xA) == 0) {
        func_800F1E6C(unk_1, unk_2, &yaw);
        yaw_setIdeal(player, yaw);
        yaw_applyIdeal(player);
    }
    func_800C6DA0(0x40);
    baanim_playForDuration_loopSmooth(player, 0xB2, 2.64f);
    func_8008CA4C(player, 1);
    func_808000E8_bsclimb(player);
    *(s32 *) ((s8 *) player + 0x160) = 1;
    func_80800258_bsclimb(player, 1.0f, 0.5f);
    *(s32 *) ((s8 *) player + 0x15C) = 0;
}

void bsclimb_entrypoint_1(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_800956B8(player);
    switch (player->unk15C.word) {
        case 0:
            player->unk16C -= func_800D8FF8();
            if (player->unk16C <= 0.0f) {
                baanim_playForDuration_onceSmooth(player, 0xB1, 2.96f);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (anctrl_isStopped(anim_ctrl)) {
                baanim_playForDuration_loopSmooth(player, 0xB2, 2.64f);
                func_80800258_bsclimb((u8 *) player, 3.0f, 4.0f);
                player->unk15C.word = 0;
            }
    }
    func_8080005C_bsclimb(player);
    if (func_80800298_bsclimb(player)) {
        next_state = 0x50;
    }
    if (bakey_pressed(player, 8)) {
        next_state = 5;
    }
    if (player->unk160.word == 0) {
        next_state = 1;
    }
    player->unk160.word = 0;
    bs_setState(player, next_state);
}

void bsclimb_entrypoint_2()
{
    func_808001D0_bsclimb();
}

int bsclimb_entrypoint_3(s32 index)
{
    return D_808008FC_bsclimb[index];
}

void bsclimb_entrypoint_4(void *player)
{
    // Matching: extra copy of the argument needed for the match.
    void *player_copy = player;
    baanim_playForDuration_loopSmooth(player_copy, 10, 0.9);
    func_8008CA4C(player_copy, 3);
    baanim_setDurationRange(player_copy, 0.3, 1.5);
    func_8008C9F0(player_copy, 100.0f, 300.0f, 0.6, 0.4f);
    func_808000E8_bsclimb(player_copy);
}

void bsclimb_entrypoint_5(PlayerState *player)
{
    s32 next_state;
    f32 unk_1[3];
    f32 unk_2[3];

    next_state = 0;
    func_800956B8(player);
    func_8080005C_bsclimb(player);
    if (baanim_isAt(player, 0.25f)) {
        func_80800000_bsclimb(player, 0);
    }
    if (baanim_isAt(player, 0.75f)) {
        func_80800000_bsclimb(player, 1);
    }
    if (!func_80800298_bsclimb(player) && baphysics_get_vertical_velocity(player) < 30.0f) {
        next_state = 0x4F;
    }
    func_8009C128(player, unk_1);
    if (func_8009BB0C(player) < 0.0f && func_800985B8(player) == unk_1[1]) {
        next_state = 1;
    }
    if (func_80098640(player) == 2 && func_8009BB0C(player) > 0.0f &&
        func_8009864C(player) == unk_1[1]) {
        if (func_800985C4(player, unk_2)) {
            next_state = _badrone_entrypoint_23(player, unk_2);
        } else {
            next_state = 0x51;
        }
    }
    if (bakey_pressed(player, 8)) {
        next_state = 5;
    }
    if (!player->unk160.word) {
        next_state = 1;
    }
    player->unk160.word = 0;
    bs_setState(player, next_state);
}

void bsclimb_entrypoint_6()
{
    func_808001D0_bsclimb();
}

int bsclimb_entrypoint_7(s32 index)
{
    return D_8080090C_bsclimb[index];
}

int bsclimb_entrypoint_8(Actor *player)
{
    baanim_playForDuration_loopSmooth(player, 0xB2, 2.64f);
    func_8008CA4C(player, 1);
    func_808000E8_bsclimb(player);
    baphysics_set_type(player, 7);
}

int bsclimb_entrypoint_9(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (!func_8009CC68()) {
        next_state = 0x4F;
    }
    bs_setState(player, next_state);
}

void bsclimb_entrypoint_10()
{
    func_808001D0_bsclimb();
}

int bsclimb_entrypoint_11(s32 index)
{
    return D_8080091C_bsclimb[index];
}

void bsclimb_entrypoint_12(PlayerState *player)
{
    if (func_8009E6EC(player) == 0xC) {
        player->unk160.word = 1;
    } else {
        func_80099B94(player);
        return;
    }
    func_8009E830(player, 1);
    bs_setState(player, 0);
}

extern void _bsclimb_entrypoint_2();
extern void _bsclimb_entrypoint_0();
extern void _bsclimb_entrypoint_1();
extern void _bsclimb_entrypoint_12();
extern void _bsclimb_entrypoint_6();
extern void _bsclimb_entrypoint_4();
extern void _bsclimb_entrypoint_5();
extern void _bsclimb_entrypoint_10();
extern void _bsclimb_entrypoint_8();
extern void _bsclimb_entrypoint_9();
u8 D_808008C0_bsclimb[60] = {
    0x1,  0x0, 0x4,  0x6E, 0x3F, 0x45, 0x1E, 0xB8, 0x0,  0x0,  0x3E, 0x80, 0x3F, 0x5E, 0xB8,
    0x52, 0x0, 0x0,  0x3E, 0x80, 0x2,  0x0,  0x4,  0x6D, 0x3F, 0x8C, 0xCC, 0xCD, 0x0,  0x0,
    0x7D, 0x0, 0x3F, 0x99, 0x99, 0x9A, 0x0,  0x0,  0x7D, 0x0,  0x3,  0x0,  0x4,  0x1B, 0x3F,
    0x80, 0x0, 0x0,  0x0,  0x0,  0x27, 0x10, 0x3F, 0x8C, 0xCC, 0xCD, 0x0,  0x0,  0x27, 0x10};
s32 D_808008FC_bsclimb[4] = {(u32) _bsclimb_entrypoint_2, (u32) _bsclimb_entrypoint_0,
                             (u32) _bsclimb_entrypoint_1, (u32) _bsclimb_entrypoint_12};
s32 D_8080090C_bsclimb[4] = {(u32) _bsclimb_entrypoint_6, (u32) _bsclimb_entrypoint_4,
                             (u32) _bsclimb_entrypoint_5, (u32) _bsclimb_entrypoint_12};
s32 D_8080091C_bsclimb[5] = {(u32) _bsclimb_entrypoint_10, (u32) _bsclimb_entrypoint_8,
                             (u32) _bsclimb_entrypoint_9, (u32) _bsclimb_entrypoint_12, 0x0};
