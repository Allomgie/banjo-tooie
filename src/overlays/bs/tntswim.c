#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 func_80096544(PlayerState *);
extern f32 func_800DC0C0(void);
extern void func_80092C00(PlayerState *, f32[3]);
extern void func_80092C24(PlayerState *, f32[3]);
extern s32 func_8009FBB0(PlayerState *, f32[3], f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern void func_800BA22C(s32, s32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void func_8009BC5C(PlayerState *, f32);
extern f32 func_800A3298(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_808009B0_bstntswim[];
extern void *baanim_getAnimCtrlPtr();
extern s32 anctrl_isAt(void *, f32);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern int D_808009C0_bstntswim[];
extern s32 D_808009D0_bstntswim[];
extern s32 D_808009E0_bstntswim[];
extern s32 D_808009F0_bstntswim[];
extern void func_8009C128(PlayerState *, f32 *);
extern f32 mlAbsF(f32);
extern f32 func_800F0E00(f32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8008CA4C(PlayerState *, s32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void yaw_setUpdateType(PlayerState *, s32);
extern void func_8009D2D8(PlayerState *, s32);
extern void baphysics_set_type(PlayerState *, s32);

void func_80800000_bstntswim(PlayerState *player)
{
    f32 pos[3];
    s32 hitbox;

    if (func_80096544(player)) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(player, pos);
        } else {
            func_80092C24(player, pos);
        }
        hitbox = func_8009FBB0(player, pos, 0.0f);
        func_800BA930(hitbox, -60, -100, -60, 60, 0, 60);
        func_800BA22C(hitbox, 1);
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_808000B0_bstntswim(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 200.0f));
    }
}

s32 func_80800114_bstntswim(player)
s32 player;
{
    _bstnt_entrypoint_3(player);
    if (func_8009E6C4(player, 1) == 0) {
        baphysics_set_gravity(player, 1e+02f);
        baphysics_set_terminal_velocity(player, 133.33f);
        func_800961AC(player, 3);
    }
}

// TU-NOTE: near copy of vanswim.c with van hooks swapped for detonator hooks.
int func_80800174_bstntswim(player)
s32 player;
{
    s32 state;
    state = player | 0;
    if (!func_8009E69C(state, 1)) {
        baphysics_reset_terminal_velocity(state);
        baphysics_reset_gravity(state);
        func_800961AC(state, 1);
    }
    _bstnt_entrypoint_2(state);
}

s32 func_808001CC_bstntswim(Actor *player)
{
    func_8009BC34();
    func_800961AC(player, 1);
    _bstnt_entrypoint_2(player);
}

// Enter water: set sink velocity from the entry speed.
void func_80800200_bstntswim(PlayerState *player)
{
    f32 water_depth;
    f32 sink_velocity;

    _bstnt_entrypoint_3(player);
    baphysics_set_gravity(player, 0.0f);
    baphysics_set_terminal_velocity(player, -399.99f);
    func_800961AC(player, 3);
    func_8009BC5C(player, 2.0f);
    func_800A046C(player);
    water_depth = func_800A3298(player);
    baanim_playForDuration_loopSmooth(player, 0xE7, 0x40D00000);
    sink_velocity = func_800F10B4(water_depth, 40.0f, 1000.0f, -300.0f, -1200.0f);
    player->unk16C = sink_velocity;
    baphysics_set_vertical_velocity(player, sink_velocity);
    func_8009FFD8(player, 1, 3, 3, 6);
}

// Sink update: bubbles, slow the descent, go to tread water when stable.
void func_808002D0_bstntswim(PlayerState *player)
{
    s32 next_state = 0;
    f32 pos[3];
    s32 hitbox;

    func_8009C128(player, pos);
    pos[1] += 60.0f;
    hitbox = func_8009FBB0(player, pos, 20.0f);
    func_800BA930(hitbox, -30, -30, -30, 30, 30, 30);
    func_800BA22C(hitbox, 1);
    if (player->unk16C < 0.0f) {
        player->unk16C += func_800F0E00(mlAbsF(player->unk16C) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(player, player->unk16C);
    }
    if (player_isStable(player))
        next_state = 0x10F;
    if (!player_inWater(player))
        next_state = 0x10C;
    if (baphysics_get_vertical_velocity(player) >= 0.0f)
        next_state = 0x10F;
    _bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

int bstntswim_entrypoint_0(s32 index)
{
    return D_808009B0_bstntswim[index];
}

// Tread water enter.
int func_8080042C_bstntswim(Actor *player)
{
    s32 state;
    int zero;
    state = player;
    func_80800114_bstntswim();
    baanim_playForDuration_loopSmooth(state | 0, 0xE7, 0x40D00000);
    func_8009FFD8(state | 0, 1, 3, 3, 2);
    yaw_setVelocityBounded(state | (0 ^ 0), 0x43FA0000, 0x40A00000);
    zero = 0;
    baphysics_set_target_horizontal_velocity(state | 0, zero);
}

// Tread water update: bubbles, to swim (0x110), detonate (0x10E), jump out (0x107).
void func_8080049C_bstntswim(PlayerState *player)
{
    s32 next_state = 0;
    void *anim_ctrl = baanim_getAnimCtrlPtr(player);

    if (!func_8001210C(7) && func_800DC0C0() < 0.5f)
        func_8009FC34(player, 1);
    if (!func_8001210C(7) && func_800DC0C0() < 0.5f)
        func_80800000_bstntswim(player);
    if (anctrl_isAt(anim_ctrl, 0.01f))
        func_8009DEC0(player, 0x46F, 0.85f, 1.15f, 16000, 16000);
    if (bastick_getZone(player) == 1)
        next_state = 0x110;
    if (!player_inWater(player))
        next_state = 0x10C;
    if (_bstnt_entrypoint_8(player))
        next_state = 0x10E;
    if (func_80096500(player) && bakey_pressed(player, 8))
        next_state = 0x107;
    _bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

void func_808005FC_bstntswim()
{
    func_80800174_bstntswim();
}

int bstntswim_entrypoint_1(int index)
{
    return D_808009C0_bstntswim[index];
}

void func_80800630_bstntswim(PlayerState *player)
{
    func_80800114_bstntswim(player);
    baanim_playForDuration_loopSmooth(player, 0xE8, 0x3F4CCCCD);
    func_8008CA4C(player, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 200.0f, 0.8f, 0.45f);
    yaw_setUpdateType(player, 3);
    yaw_setVelocityBounded(player, 0x43FA0000, 0x40A00000);
    func_8009D2D8(player, 1);
    baphysics_set_type(player, 2);
}

void func_808006E4_bstntswim(s32 player)
{
    s32 next_state;
    s32 anim_ctrl;
    s32 anim_ctrl_raw;

    next_state = 0;
    anim_ctrl_raw = baanim_getAnimCtrlPtr();
    anim_ctrl = anim_ctrl_raw;
    if (anctrl_isAt(anim_ctrl_raw, 0.38f) != 0) {
        func_8009FD24(player, 1);
    }
    if (anctrl_isAt(anim_ctrl, 0.88f) != 0) {
        func_8009FD24(player, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f) != 0) {
        func_8009DE74(player, 0x40C, 0x3F666666, 0x3F8CCCCD);
    }
    if (anctrl_isAt(anim_ctrl, 0.7f) != 0) {
        func_8009DE74(player, 0x40C, 0x3F666666, 0x3F8CCCCD);
    }
    func_808000B0_bstntswim(player);
    if (bastick_getZone(player) == 0) {
        next_state = 0x10F;
    }
    if (player_inWater(player) == 0) {
        next_state = 0x10C;
    }
    if (_bstnt_entrypoint_8(player) != 0) {
        next_state = 0x10E;
    }
    if ((func_80096500(player) != 0) && (bakey_pressed(player, 8) != 0)) {
        next_state = 0x107;
    }
    _bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

void func_80800830_bstntswim()
{
    func_80800174_bstntswim();
}

int bstntswim_entrypoint_2(s32 index)
{
    return D_808009D0_bstntswim[index];
}

void func_80800864_bstntswim(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800174_bstntswim(player);
}

void func_8080088C_bstntswim(s32 player)
{
    func_80800114_bstntswim();
    _bsrest_entrypoint_16(player);
}

int func_808008B4_bstntswim(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = 0x10F;
    }
    _bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

int bstntswim_entrypoint_3(s32 index)
{
    return D_808009E0_bstntswim[index];
}

void func_8080090C_bstntswim(s32 player)
{
    func_80800114_bstntswim();
    _bsdrone_entrypoint_0(player);
}

void func_80800934_bstntswim(s32 player)
{
    _bsdrone_entrypoint_1();
    _bstnt_entrypoint_4(player);
}

void func_8080095C_bstntswim(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800174_bstntswim(player);
}

int bstntswim_entrypoint_4(s32 index)
{
    return D_808009F0_bstntswim[index];
}

extern void _bstnt_entrypoint_10();
extern void _bsdrone_entrypoint_3();
s32 D_808009B0_bstntswim[4] = {(u32) func_808001CC_bstntswim, (u32) func_80800200_bstntswim,
                               (u32) func_808002D0_bstntswim, (u32) _bstnt_entrypoint_10};
int D_808009C0_bstntswim[4] = {(u32) func_808005FC_bstntswim, (u32) func_8080042C_bstntswim,
                               (u32) func_8080049C_bstntswim, (u32) _bstnt_entrypoint_10};
s32 D_808009D0_bstntswim[4] = {(u32) func_80800830_bstntswim, (u32) func_80800630_bstntswim,
                               (u32) func_808006E4_bstntswim, (u32) _bstnt_entrypoint_10};
s32 D_808009E0_bstntswim[4] = {(u32) func_80800864_bstntswim, (u32) func_8080088C_bstntswim,
                               (u32) func_808008B4_bstntswim, (u32) _bstnt_entrypoint_10};
s32 D_808009F0_bstntswim[4] = {(u32) func_8080095C_bstntswim, (u32) func_8080090C_bstntswim,
                               (u32) func_80800934_bstntswim, (u32) _bsdrone_entrypoint_3};
