#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

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
extern s32 D_80800980_bsvanswim[];
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern s32 D_80800990_bsvanswim[];
extern s32 D_808009A0_bsvanswim[];
extern s32 D_808009B0_bsvanswim[];
extern s32 D_808009C0_bsvanswim[];
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

void func_80800000_bsvanswim(PlayerState *player)
{
    f32 pos[3];
    s32 unk_0;

    if (func_80096544(player)) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(player, pos);
        } else {
            func_80092C24(player, pos);
        }
        unk_0 = func_8009FBB0(player, pos, 0.0f);
        func_800BA930(unk_0, -60, -100, -60, 60, 0, 60);
        func_800BA22C(unk_0, 1);
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_808000B0_bsvanswim(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 200.0f));
    }
}

s32 func_80800114_bsvanswim(player)
s32 player;
{
    _bsvan_entrypoint_1(player);
    if (func_8009E6C4(player, 1) == 0) {
        baphysics_set_gravity(player, 1e+02f);
        baphysics_set_terminal_velocity(player, 133.33f);
        func_800961AC(player, 3);
    }
}

int func_80800174_bsvanswim(player)
Actor *player;
{
    if (!func_8009E69C(player, 1)) {
        baphysics_reset_terminal_velocity(player);
        baphysics_reset_gravity(player);
        func_800961AC(player, 1);
    }
    _bsvan_entrypoint_0(player);
}

s32 func_808001CC_bsvanswim(s32 player)
{
    func_8009BC34();
    func_800961AC(player, 1);
    _bsvan_entrypoint_0(player);
}

void func_80800200_bsvanswim(PlayerState *player)
{
    f32 unk_0;
    f32 sink_speed;

    _bsvan_entrypoint_1(player);
    baphysics_set_gravity(player, 0.0f);
    baphysics_set_terminal_velocity(player, -399.99f);
    func_800961AC(player, 3);
    func_8009BC5C(player, 2.0f);
    func_800A046C(player);
    unk_0 = func_800A3298(player);
    baanim_playForDuration_loopSmooth(player, 0xE7, 0x40D00000);
    sink_speed = func_800F10B4(unk_0, 40.0f, 1000.0f, -300.0f, -1200.0f);
    player->unk16C = sink_speed;
    baphysics_set_vertical_velocity(player, sink_speed);
    func_8009FFD8(player, 1, 3, 3, 6);
}

void func_808002D0_bsvanswim(PlayerState *player)
{
    s32 next_state = 0;
    f32 pos[3];
    s32 unk_0;

    func_8009C128(player, pos);
    pos[1] += 60.0f;
    unk_0 = func_8009FBB0(player, pos, 20.0f);
    func_800BA930(unk_0, -30, -30, -30, 30, 30, 30);
    func_800BA22C(unk_0, 1);
    if (player->unk16C < 0.0f) {
        player->unk16C += func_800F0E00(mlAbsF(player->unk16C) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(player, player->unk16C);
    }
    if (player_isStable(player))
        next_state = 0x11B;
    if (!player_inWater(player))
        next_state = 0x11A;
    if (baphysics_get_vertical_velocity(player) >= 0.0f)
        next_state = 0x11B;
    _bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

int bsvanswim_entrypoint_0(s32 index)
{
    return D_80800980_bsvanswim[index];
}

void func_8080042C_bsvanswim(Actor *player)
{
    s32 player_copy;
    int zero;
    player_copy = player;
    func_80800114_bsvanswim();
    baanim_playForDuration_loopSmooth(player_copy | 0, 0xe7, 0x40D00000);
    func_8009FFD8(player_copy | 0, 1, 3, 3, 2);
    yaw_setVelocityBounded(player_copy | (0 ^ 0), 0x43FA0000, 0x40A00000);
    zero = 0;
    baphysics_set_target_horizontal_velocity(player_copy | 0, zero);
}

void func_8080049C_bsvanswim(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (!func_8001210C(7) && func_800DC0C0() < 0.5f)
        func_8009FC34(player, 1);
    if (!func_8001210C(7) && func_800DC0C0() < 0.5f)
        func_80800000_bsvanswim(player);
    if (anctrl_isAt(anim_ctrl, 0.01f))
        func_8009DEC0(player, 0x46F, 0.85f, 1.15f, 16000, 16000);
    if (bastick_getZone(player) == 1)
        next_state = 0x11C;
    if (!player_inWater(player))
        next_state = 0x11A;
    if (func_80096500(player) && bakey_pressed(player, 8))
        next_state = 0x115;
    _bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

void func_808005E8_bsvanswim()
{
    func_80800174_bsvanswim();
}

int bsvanswim_entrypoint_1(s32 index)
{
    return D_80800990_bsvanswim[index];
}

void func_8080061C_bsvanswim(PlayerState *player)
{
    func_80800114_bsvanswim(player);
    baanim_playForDuration_loopSmooth(player, 0xE8, 0x3F4CCCCD);
    func_8008CA4C(player, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 200.0f, 0.8f, 0.45f);
    yaw_setUpdateType(player, 3);
    yaw_setVelocityBounded(player, 0x43FA0000, 0x40A00000);
    func_8009D2D8(player, 1);
    baphysics_set_type(player, 2);
}

void func_808006D0_bsvanswim(Actor *player)
{
    s32 next_state;

    s32 anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if (anctrl_isAt(anim_ctrl, 0.38f)) {
        func_8009FD24(player, 1);
    }
    if (anctrl_isAt(anim_ctrl, 0.88f)) {
        func_8009FD24(player, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f)) {
        func_8009DE74(player, 0x40C, 0x3F666666, 0x3F8CCCCD);
    }
    if (anctrl_isAt(anim_ctrl, 0.7f)) {
        func_8009DE74(player, 0x40C, 0x3F666666, 0x3F8CCCCD);
    }
    func_808000B0_bsvanswim(player);
    if (bastick_getZone(player) == 0) {
        next_state = 0x11B;
    }
    if (player_inWater(player) == 0) {
        next_state = 0x11A;
    }
    if ((func_80096500(player) != 0) && (bakey_pressed(player, 8) != 0)) {
        next_state = 0x115;
    }
    _bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

void func_80800808_bsvanswim()
{
    func_80800174_bsvanswim();
}

int bsvanswim_entrypoint_2(s32 index)
{
    return D_808009A0_bsvanswim[index];
}

void func_8080083C_bsvanswim(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800174_bsvanswim(player);
}

void func_80800864_bsvanswim(s32 player)
{
    func_80800114_bsvanswim();
    _bsrest_entrypoint_16(player);
}

s32 func_8080088C_bsvanswim(Actor *player)
{
    s32 next_state = 0;
    if (_bsrest_entrypoint_20(player)) {
        next_state = 0x11B;
    }
    _bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

int bsvanswim_entrypoint_3(s32 index)
{
    return D_808009B0_bsvanswim[index];
}

void func_808008E4_bsvanswim(s32 player)
{
    func_80800114_bsvanswim();
    _bsdrone_entrypoint_0(player);
}

void func_8080090C_bsvanswim(s32 player)
{
    _bsdrone_entrypoint_1();
    _bsvan_entrypoint_3(player);
}

void func_80800934_bsvanswim(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800174_bsvanswim(player);
}

int bsvanswim_entrypoint_4(s32 index)
{
    return D_808009C0_bsvanswim[index];
}

// TU-NOTE: same code as tntswim.c, with van hooks and state ids.
extern void _bsvan_entrypoint_8();
extern void _bsvan_entrypoint_9();
s32 D_80800980_bsvanswim[4] = {(u32) func_808001CC_bsvanswim, (u32) func_80800200_bsvanswim,
                               (u32) func_808002D0_bsvanswim, (u32) _bsvan_entrypoint_8};
s32 D_80800990_bsvanswim[4] = {(u32) func_808005E8_bsvanswim, (u32) func_8080042C_bsvanswim,
                               (u32) func_8080049C_bsvanswim, (u32) _bsvan_entrypoint_8};
s32 D_808009A0_bsvanswim[4] = {(u32) func_80800808_bsvanswim, (u32) func_8080061C_bsvanswim,
                               (u32) func_808006D0_bsvanswim, (u32) _bsvan_entrypoint_8};
s32 D_808009B0_bsvanswim[4] = {(u32) func_8080083C_bsvanswim, (u32) func_80800864_bsvanswim,
                               (u32) func_8080088C_bsvanswim, (u32) _bsvan_entrypoint_8};
s32 D_808009C0_bsvanswim[4] = {(u32) func_80800934_bsvanswim, (u32) func_808008E4_bsvanswim,
                               (u32) func_8080090C_bsvanswim, (u32) _bsvan_entrypoint_9};
