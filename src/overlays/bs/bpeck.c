// Rat-a-tat Rap, Banjo-Kazooie's mid-air peck attack: hovers, opens two hit spheres on each peck,
// then lands to idle, falls or enters water.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include <types.h>

extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E4FC(PlayerState *, s32, f32, f32, f32);
extern s32 D_808004A0_bsbpeck[];
extern void func_8009DE38(PlayerState *, s32, f32);
extern void *baanim_getAnimCtrlPtr(void);
extern void _bswalk_entrypoint_1(void *);
extern int anctrl_isAt(void *, int);
extern void anctrl_setIndex(void *, int);
extern void anctrl_setStart(void *, float);
extern void anctrl_setDuration(void *, float);
extern void anctrl_setPlaybackType(void *, int);
extern void anctrl_start(void *);
extern void anctrl_reset(void *);
extern void anctrl_setSmoothTransition(void *, int);
extern void func_8008B188(void *, int);
extern int anctrl_isStopped(void *);
extern void func_8009FE58(void *);
extern float func_800D8FF8(void);
extern int player_isStable(void *);
extern int player_inWater(void *);
extern void bs_setState(void *, int);
extern float baphysics_get_target_horizontal_velocity(void *);
extern void baphysics_set_target_horizontal_velocity(void *, float);

// Rat-a-tat Rap: start of the mid-air peck attack.
void bsbpeck_entrypoint_0(PlayerState *player)
{
    s32 prev_state;

    player->unk164.word = 0;
    prev_state = bs_getPreviousState(player);
    if (prev_state != 5 && (prev_state == 8 || (prev_state != 0x2F && prev_state != 0x3D && prev_state != 0x57 &&
                                          prev_state == 0x95))) {
        player->unk164.word++;
    }
    if (func_8009557C(player) == 1)
        func_80095588(player, 2);
    baanim_playForDuration_once(player, 0x1A, 0.2f);
    func_8009FFD8(player, 1, 3, 1, 6);
    yaw_setVelocityBounded(player, 1200.0f, 10.0f);
    func_800A0CF4(player, 1);
    baphysics_set_gravity(player, -1400.0f);
    baphysics_set_vertical_velocity(player, 120.0f);
    func_8009E4AC(player);
    func_8009E55C(player, 0, 35.0f);
    func_8009E55C(player, 1, 42.0f);
    func_8009E4FC(player, 1, -38.0f, 0.0f, 105.0f);
    func_8009E4FC(player, 0, -38.0f, 0.0f, -7.0f);
    player->unk160.word = 0;
    player->unk15C.word = 0;
    baflag_set(player, 0x2A);
}

// One peck: sfx pitch depends on the peck count, then re-apply the vertical boost.
void func_80800168_bsbpeck(PlayerState *player)
{
    f32 pitch = 1.0f;

    switch (player->unk160.word) {
        case 0:
            pitch = 1.13f;
            break;
        case 1:
            pitch = 1.1f;
            break;
        case 2:
            pitch = 1.32f;
            break;
    }
    baflag_set(player, 5);
    func_8009DE38(player, 0x442C, pitch);
    baphysics_set_vertical_velocity(player, 120.0f);
    player->unk160.word++;
}

void bsbpeck_entrypoint_1(void *player)
{
    int next_state;
    void *anim_ctrl;
    int phase;
    float min_timer;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    _bswalk_entrypoint_1(player);
    if (*(int *) ((char *) player + 0x164)) {
        baphysics_set_target_horizontal_velocity(
            player, baphysics_get_target_horizontal_velocity(player) * 0.1f);
    }
    phase = *(int *) ((char *) player + 0x15C);
    switch (phase) {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0x3F69A027)) {
                anctrl_setIndex(anim_ctrl, 0x19);
                anctrl_setStart(anim_ctrl, 0.0f);
                anctrl_setDuration(anim_ctrl, 0.35f);
                anctrl_setPlaybackType(anim_ctrl, 2);
                anctrl_start(anim_ctrl);
                *(int *) ((char *) player + 0x15C) = 1;
                *(float *) ((char *) player + 0x16C) = 0.5f;
            }
            break;
        case 1:
            if (anctrl_isAt(anim_ctrl, 0x3E25FD8B)) {
                func_80800168_bsbpeck(player);
            }
            if (anctrl_isAt(anim_ctrl, 0x3F333333)) {
                func_80800168_bsbpeck(player);
            }
            min_timer = 0.0f;
            *(float *) ((char *) player + 0x16C) =
                *(float *) ((char *) player + 0x16C) - func_800D8FF8();
            if (*(float *) ((char *) player + 0x16C) < min_timer) {
                anctrl_reset(anim_ctrl);
                anctrl_setSmoothTransition(anim_ctrl, 0);
                anctrl_setIndex(anim_ctrl, 0x1A);
                func_8008B188(anim_ctrl, 0);
                anctrl_setDuration(anim_ctrl, 0.2f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                anctrl_start(anim_ctrl);
                *(int *) ((char *) player + 0x15C) = 2;
            }
            break;
        case 2:
            if (anctrl_isStopped(anim_ctrl)) {
                next_state = 0x2F;
            }
    }
    if (player_isStable(player)) {
        func_8009FE58(player);
        next_state = 1;
    }
    if (player_inWater(player)) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

void bsbpeck_entrypoint_2(s32 player)
{
    baflag_clear(player, 0x2A);
    func_800C6DA0(0x46);
    func_8009E474(player);
    func_800A0CF4(player, 0);
    baphysics_reset_gravity(player);
}

int bsbpeck_entrypoint_3(s32 idx)
{
    return D_808004A0_bsbpeck[idx];
}

// TU-NOTE: the overlay's .data is defined here in C. The table holds pointers to functions of
// this file, and IDO's assembler schedules some of them differently unless it is in the same
// unit. Values are taken from the ROM.
extern void _bsbpeck_entrypoint_2();
extern void _bsbpeck_entrypoint_0();
extern void _bsbpeck_entrypoint_1();
extern void func_80099B94();
s32 D_808004A0_bsbpeck[4] = {(u32) _bsbpeck_entrypoint_2, (u32) _bsbpeck_entrypoint_0,
                             (u32) _bsbpeck_entrypoint_1, (u32) func_80099B94};
