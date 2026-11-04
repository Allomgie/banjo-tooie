// Bee flying states: take-off, free flight with boost and buzz, stick steering with fly camera,
// landing, and fly variants of rest/hover/drone. Spawns wing particles.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_80800DC0_bsbeefly[];
extern s32 D_80800DE8_bsbeefly[];
extern s32 func_800B5BE4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 anctrl_isAt(void *, f32);
extern void _bsbee_entrypoint_2();
extern s32 D_80800E18_bsbeefly[];
extern void func_80093360(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern int func_8009CA70(Actor *, int, int);
extern void _bafly_entrypoint_5(Actor *);
extern void _babee_entrypoint_6(Actor *);
extern void _babee_entrypoint_7(Actor *, int, int, int);
extern void yaw_setUpdateType(Actor *, int);
extern void baroll_setAngularVelocity(Actor *, int, int);
extern void _bafly_entrypoint_20(Actor *);
extern void baphysics_set_terminal_velocity(Actor *, int);
extern void _baboost_entrypoint_3(Actor *);
extern void _baboost_entrypoint_4(Actor *, int);
extern void _babuzz_entrypoint_2(Actor *);
extern void _bafpctrl_entrypoint_18(Actor *, int);
extern f32 bastick_getX(PlayerState *);
extern void _ncbafly_entrypoint_4(void *, f32, f32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern void _baboost_entrypoint_2(PlayerState *, f32);
extern void _bsbee_entrypoint_1();
extern s32 bs_getPreviousState();
extern void baanim_playForDuration_loopSmooth(void *param_0, s32 param_1, f32 param_2);
extern void func_8009FFD8(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern s32 baflag_isTrue(void *param_0, s32 param_1);
extern f32 baphysics_get_target_horizontal_velocity(void *param_0);
extern void baphysics_set_horizontal_velocity(void *param_0, f32 param_1, f32 param_2);
extern void baphysics_set_target_yaw(void *param_0, f32 param_1);
extern void func_800A4DA4(void *param_0, s32 param_1);
extern s32 D_80800E50_bsbeefly[];
extern s32 D_80800E60_bsbeefly[];
extern s32 D_80800E70_bsbeefly[];
extern s32 D_80800E80_bsbeefly[];
extern f32 D_80800E28_bsbeefly[];
extern f32 D_80800E3C_bsbeefly[];
extern f32 func_8009BFCC(PlayerState *);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_8009C150(PlayerState *);
extern f32 func_800136E4(f32);
extern void _babuzz_entrypoint_3(PlayerState *);
extern void _bafly_entrypoint_10(PlayerState *, f32, f32);
extern void _babuzz_entrypoint_4(PlayerState *, f32);
extern void _bafly_entrypoint_8(PlayerState *, f32, f32, f32, f32, f32, f32, f32);
extern void anctrl_setDuration(void *, f32);

// Spawns wing particles at a random offset around the player.
void func_80800000_bsbeefly(PlayerState *player)
{
    f32 pos[3];
    func_8009C128(player, pos);
    pos[0] += func_800DC178(-30.0f, 30.0f);
    pos[1] += 30.0f + func_800DC178(0.0f, 30.0f);
    pos[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(pos, 0, 1.0f, 1, D_80800DC0_bsbeefly);
}

void func_808000A4_bsbeefly(PlayerState *player)
{
    f32 pos[3];
    s32 particle;

    particle = func_800B5BE4(0x22);
    func_8009C128(player, pos);
    pos[1] += 45.0f;
    func_800BABB8(particle, pos, NULL, 1.0f, D_80800DE8_bsbeefly);
}

void func_8080010C_bsbeefly(PlayerState *player)
{
    _bsbee_entrypoint_1(player);
    baanim_playForDuration_once(player, 0x1DF, 1.5f);
    func_8009FFD8(player, 1, 1, 3, 6);
    if (bastick_distance(player) != 0.0f) {
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    }
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    baphysics_set_gravity(player, -1200.0f);
    *(s32 *) ((u8 *) player + 0x15C) = 0;
}

void func_808001C4_bsbeefly(PlayerState *player)
{
    s32 next_state = 0;
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _bsbee_entrypoint_2(player);
    switch (*(s32 *) ((u8 *) player + 0x15C)) {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.266f)) {
                baphysics_set_vertical_velocity(player, 1600.0f);
                func_8009DE38(player, 0x406, 0.7f);
                *(s32 *) ((u8 *) player + 0x15C) = 1;
            }
            break;
        case 1:
            func_80800000_bsbeefly(player);
            if (anctrl_isStopped(anim_ctrl)) {
                baanim_playForDuration_loopSmooth(player, 0x1DC, 0.38f);
            }
            if (baphysics_get_vertical_velocity(player) < 0.0f) {
                next_state = 0x8C;
            }
    }
    bs_setState(player, next_state);
}

void func_808002B0_bsbeefly()
{
    _bsbee_entrypoint_0();
}

int bsbeefly_entrypoint_0(s32 player)
{
    return D_80800E18_bsbeefly[player];
}

void func_808002E4_bsbeefly(player) PlayerState *player;
{
    s32 next_state;

    next_state = bs_getNextState(player);
    if (!func_8009CA70(player, next_state, 0x4000)) {
        func_80093360(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        func_8009BF5C(player, 0.0f);
        func_800A4E30(player);
        baphysics_reset_gravity(player);
        baphysics_reset_terminal_velocity(player);
        _baboost_entrypoint_4(player, 0);
        _babuzz_entrypoint_1(player);
        _babee_entrypoint_5(player);
        _bafly_entrypoint_4(player);
        _bafpctrl_entrypoint_18(player, 0);
        func_800947EC(player, 1, 1);
    }
}

void func_8080039C_bsbeefly(Actor *player)
{
    if (func_8009CA70(player, bs_getPreviousState(), 0x4000) == 0) {
        _bafly_entrypoint_5(player);
        _babee_entrypoint_6(player);
        _babee_entrypoint_7(player, 0x45BB8000, 0x3E4CCCCD, 0x463B8000);
        func_80093360(player, 65.0f);
        yaw_setUpdateType(player, 3);
        baroll_setAngularVelocity(player, 0x43FA0000, 0x40000000);
        _bafly_entrypoint_20(player);
        baphysics_set_gravity(player, -300.0f);
        baphysics_set_terminal_velocity(player, 0xC2C7CCCD);
        _baboost_entrypoint_3(player);
        _baboost_entrypoint_4(player, 1);
        _babuzz_entrypoint_2(player);
        _bafpctrl_entrypoint_18(player, 1);
    }
}

// Flight steering: stick X drives roll and yaw.
void func_80800480_bsbeefly(PlayerState *player)
{
    f32 yaw_delta;
    f32 yaw_rate;
    f32 max_roll;
    f32 stick_x;

    stick_x = bastick_getX(player);
    _ncbafly_entrypoint_4((void *) func_800A4CA8(player), 2.0f, 2000.0f, 350.0f);
    if (bakey_held(player, 3)) {
        yaw_setVelocityBounded(player, 500.0f, 30.0f);
        yaw_rate = 6.0f;
        max_roll = 85.0f;
    } else {
        yaw_setVelocityBounded(player, 500.0f, 2.0f);
        yaw_rate = 3.0f;
        max_roll = 65.0f;
    }
    baroll_setIdeal(player, func_800F10B4(stick_x, -1.0f, 1.0f, -max_roll, max_roll));
    yaw_delta = func_800F10B4(stick_x, -1.0f, 1.0f, yaw_rate, -yaw_rate);
    yaw_delta *= _bafpctrl_entrypoint_3(player);
    yaw_setIdeal(player, yaw_getIdeal(player) + yaw_delta);
}

s32 func_808005B0_bsbeefly(s32 player)
{
    if (func_8009E6EC() == 0x18) {
        _baboost_entrypoint_2(player, 1.0f);
        func_8009E830(player, 2);
    } else {
        func_80099B94(player);
    }
}

void func_80800600_bsbeefly(void *player)
{
    s32 prev_state;
    f32 target_yaw;
    f32 yaw;

    _bsbee_entrypoint_1(player);
    prev_state = bs_getPreviousState(player);
    baanim_playForDuration_loopSmooth(player, 0x1DC, 0.38f);
    func_8009FFD8(player, 1, 1, 3, 3);
    if (baflag_isTrue(player, 9) != 0) {
        baphysics_set_target_horizontal_velocity(player, 0);
    } else {
        baphysics_set_target_horizontal_velocity(player, 600.0);
    }
    yaw = yaw_getIdeal(player);
    baphysics_set_horizontal_velocity(player, yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    target_yaw = yaw_getIdeal(player);
    baphysics_set_target_yaw(player, target_yaw);
    func_800A4DA4(player, 0x16);
    func_8080039C_bsbeefly(player);
    if (prev_state != 0x8B) {
        _baboost_entrypoint_2(player, 1.0f);
        *(s32 *) ((char *) player + 0x15C) = 0;
        return;
    }
    *(s32 *) ((char *) player + 0x15C) = 1;
}

// Free flight update: boost, buzz sound and speed.
void func_80800708_bsbeefly(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    s32 boost_level;
    f32 anim_speed;
    f32 unk_0;
    f32 unk_1;
    f32 speed_adjust;
    f32 unk_2;
    f32 *boost_entry;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _bsbee_entrypoint_2(player);
    _bafly_entrypoint_20(player);
    func_80800480_bsbeefly(player);
    _bafly_entrypoint_10(player, 300.0f, 80.0f);
    _bafly_entrypoint_11(player);
    func_8009BFCC(player);
    if (bakey_pressed(player, 8)) {
        if (func_8009C150(player) < 27500.0f) {
            _baboost_entrypoint_2(player, 1.0f);
        }
    }
    if (_baboost_entrypoint_1(player) == 0 && player_inWater(player)) {
        _baboost_entrypoint_2(player, 1.0f);
    }
    boost_level = _baboost_entrypoint_1(player);
    anctrl_setDuration(anim_ctrl, D_80800E28_bsbeefly[boost_level]);
    boost_entry = &D_80800E3C_bsbeefly[boost_level];
    anim_speed = 0.9f;
    anim_speed += *boost_entry;
    unk_0 = func_8009BFCC(player);
    speed_adjust = 0.0f;
    if (baphysics_get_vertical_velocity(player) < 0.0f) {
        if (unk_0 < 300.0f) {
            speed_adjust = func_800F10B4(unk_0, 0.0f, 80.0f, 0, 0.23f);
        }
        if (80.0f < unk_0) {
            speed_adjust = func_800F10B4(unk_0, 300.0f, 360.0f, -0.2f, 0);
        }
    }
    anim_speed += speed_adjust;
    if (boost_level == 0 && bakey_held(player, 9)) {
        anim_speed += 0.12f;
    }
    _babuzz_entrypoint_4(player, anim_speed);
    _babuzz_entrypoint_3(player);
    switch (player->unk15C.word) {
        case 0:
            if (boost_entry != D_80800E3C_bsbeefly) {
                player->unk15C.word = 1;
            }
            break;
        case 1:
            unk_1 = func_800136E4(func_8009BFD8(player) - 30.0f);
            if (80.0f < unk_1 && unk_1 < 300.0f) {
                unk_1 = 300.0f;
            }
            func_8009BF5C(player, unk_1);
            _bafly_entrypoint_21(player);
            if (boost_level != 0) {
                baphysics_set_vertical_velocity(player, boost_level * 400.0f);
                func_80800000_bsbeefly(player);
            }
            if (boost_entry == D_80800E3C_bsbeefly) {
                _bafly_entrypoint_20(player);
                player->unk15C.word = 0;
            }
    }
    if (bakey_held(player, 9)) {
        unk_2 = -1500.0f;
        unk_1 = -1800.0f;
    } else {
        unk_2 = -700.0f;
        unk_1 = -1000.0f;
    }
    _bafly_entrypoint_8(player, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, unk_2, unk_1);
    if (bakey_held(player, 9)) {
        func_808000A4_bsbeefly(player);
        baphysics_set_target_horizontal_velocity(
            player, baphysics_get_target_horizontal_velocity(player) * 3.5f);
    }
    if (bakey_held(player, 1)) {
        _babee_entrypoint_2(player);
    }
    if (_bafly_entrypoint_2(player) && !player_inWater(player)) {
        next_state = 0x85;
    }
    _baboost_entrypoint_5(player);
    bs_setState(player, next_state);
}

void func_80800B18_bsbeefly(s32 player)
{
    func_808002E4_bsbeefly();
    _bsbee_entrypoint_0(player);
}

int bsbeefly_entrypoint_1(s32 player)
{
    return D_80800E50_bsbeefly[player];
}

s32 func_80800B54_bsbeefly(void *player)
{
    s32 player_addr;
    player_addr = (s32) player;
    _bsbee_entrypoint_1(player_addr);
    func_8080039C_bsbeefly(player_addr);
    _bsrest_entrypoint_16(player_addr);
    baphysics_set_gravity(player_addr, 0);
    func_8009BA9C(player_addr, 0);
}

int func_80800BA4_bsbeefly(Actor *player)
{
    s32 next_state;
    next_state = 0;
    _bsbee_entrypoint_2();
    if (_bsrest_entrypoint_20(player)) {
        next_state = 0x8C;
    }
    bs_setState(player, next_state);
}

void func_80800BE8_bsbeefly(s32 player)
{
    _bsrest_entrypoint_14();
    func_808002E4_bsbeefly(player);
    _bsbee_entrypoint_0(player);
}

int bsbeefly_entrypoint_2(s32 player)
{
    return D_80800E60_bsbeefly[player];
}

void func_80800C2C_bsbeefly(s32 player)
{
    _bafly_entrypoint_18();
    func_808002E4_bsbeefly(player);
    _bsbee_entrypoint_0(player);
}

int func_80800C5C_bsbeefly(Actor *player)
{
    _bsbee_entrypoint_1();
    func_8080039C_bsbeefly(player);
    _bafly_entrypoint_16(player, 0x1E0, 0x3F800000);
}

int func_80800C94_bsbeefly(s32 player)
{
    s32 next_state;
    next_state = 0;
    _bsbee_entrypoint_2(player);
    _bafly_entrypoint_17(player, 0x8C, 0x85, &next_state);
}

int bsbeefly_entrypoint_3(s32 player)
{
    return D_80800E70_bsbeefly[player];
}

void func_80800CE0_bsbeefly(s32 player)
{
    _bafly_entrypoint_15();
    func_808002E4_bsbeefly(player);
    _bsbee_entrypoint_0(player);
}

int func_80800D10_bsbeefly(Actor *player)
{
    _bsbee_entrypoint_1();
    func_8080039C_bsbeefly(player);
    _bafly_entrypoint_13(player, 1, 0xD3, 0x3F99999A);
}

int func_80800D50_bsbeefly(Actor *player)
{
    extern void _bafly_entrypoint_14(Actor *, s32, s32);
    extern void _bsbee_entrypoint_2(void);
    _bsbee_entrypoint_2();
    _bafly_entrypoint_14(player, 0x8C, 0x85);
}

int bsbeefly_entrypoint_4(s32 player)
{
    return D_80800E80_bsbeefly[player];
}

extern int func_80099B94();
extern void func_80099AA8();
s32 D_80800DC0_bsbeefly[10] = {0x1D09E2, 0x150019,  0x990022,  0x660059, 0x190019,
                               0x270190, 0x1900320, 0x320002B, 0x800080, 0x0};
s32 D_80800DE8_bsbeefly[12] = {0x1D09E0, 0xE0014,   0x2D0015,  0x190099, 0x220066, 0x800014,
                               0x140027, 0x1900190, 0x3200320, 0x2B0073, 0x73021A, 0x0};
s32 D_80800E18_bsbeefly[4] = {(u32) func_808002B0_bsbeefly, (u32) func_8080010C_bsbeefly,
                              (u32) func_808001C4_bsbeefly, (u32) func_80099B94};
f32 D_80800E28_bsbeefly[5] = {0.38f, 0.3f, 0.24f, 0.18f, 0.14f};
f32 D_80800E3C_bsbeefly[5] = {0.0f, 0.2f, 0.3f, 0.4f, 0.5f};
s32 D_80800E50_bsbeefly[4] = {(u32) func_80800B18_bsbeefly, (u32) func_80800600_bsbeefly,
                              (u32) func_80800708_bsbeefly, (u32) func_808005B0_bsbeefly};
s32 D_80800E60_bsbeefly[4] = {(u32) func_80800BE8_bsbeefly, (u32) func_80800B54_bsbeefly,
                              (u32) func_80800BA4_bsbeefly, (u32) func_80099B94};
s32 D_80800E70_bsbeefly[4] = {(u32) func_80800C2C_bsbeefly, (u32) func_80800C5C_bsbeefly,
                              (u32) func_80800C94_bsbeefly, (u32) func_80099AA8};
s32 D_80800E80_bsbeefly[4] = {(u32) func_80800CE0_bsbeefly, (u32) func_80800D10_bsbeefly,
                              (u32) func_80800D50_bsbeefly, (u32) func_80099AA8};
