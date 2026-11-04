// Player states of the Submarine transformation: idle, cruise (stick yaw/pitch/roll, buoyancy),
// death (debris and bubbles, or spin-death), knockback spins, bounce, rest and drone wrappers.
// B/Z/C fire torpedo, sonar ping and eggs through the basub subsystem.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void func_8009FFD8(s32, s32, s32, s32, s32);
extern f32 bastick_getX(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 func_8009BB94(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _basub_entrypoint_8(PlayerState *, f32);
extern void _basub_entrypoint_3(PlayerState *, f32, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern void func_80093360(PlayerState *, f32);
extern void func_80092864(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern void func_8009BC5C(PlayerState *, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void _bamovethrust_entrypoint_3(PlayerState *, f32);
extern void _bamovethrust_entrypoint_4(PlayerState *, f32);
extern void _basub_entrypoint_11(PlayerState *, f32);
extern void _basub_entrypoint_13(PlayerState *, f32);
extern void _baspin_entrypoint_2(PlayerState *, s32, f32, s32, s32);
extern void _batimer_set(PlayerState *, s32, f32);
typedef struct {
    s32 type;
    s32 sprite;
} SubPartDef;
extern SubPartDef D_80801840_bssub[];
extern u8 D_8080172C_bssub[];
extern u8 D_80801748_bssub[];
extern u8 D_80801774_bssub[];
extern u8 D_808017A0_bssub[];
extern u8 D_808017CC_bssub[];
extern void func_8009DB04(void *, s32, f32, s32);
extern void func_8009D9D4(void *);
extern void func_8009C128(void *, f32 *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_800B53A4(s32);
extern void func_800BA670(s32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern f32 func_800964DC(void *);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void func_800BA22C(s32, s32);
extern void _basudie_entrypoint_10(void);
extern f32 func_80099A34(Actor *);
extern void func_8009BDAC(Actor *, f32);
extern s32 D_80801890_bssub[];
extern s32 D_808018A0_bssub[];
extern s32 D_808018B0_bssub[];
extern s32 D_808018C0_bssub[];
extern s32 D_808018D0_bssub[];
extern s32 D_808018E0_bssub[];
extern s32 D_808018F0_bssub[];
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern s32 D_80801900_bssub[];
extern f32 func_800F1214(f32, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern s32 D_808016E0_bssub[];
extern f32 func_800A3048(void);
extern f32 _basub_entrypoint_2(PlayerState *);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern s32 _basub_entrypoint_12(PlayerState *, f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800914FC(PlayerState *, f32, s32);
extern int player_inWater(PlayerState *);
extern f32 bastick_getY(PlayerState *);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);

void func_80800000_bssub(s32 player)
{
    func_8009FFD8(player, 1, 3, 3, 15);
}

f32 func_80800030_bssub(f32 param_0, f32 param_1)
{
    return param_1 * 300.0f;
}

f32 func_80800048_bssub(f32 param_0, f32 param_1)
{
    return -param_1 * 428.57144f;
}

void func_80800064_bssub(PlayerState *player)
{
    switch (func_8009E6EC(player)) {
        case 0x85:
            _basub_entrypoint_15(player, func_80099A58(player));
            break;
        case 0x2D:
            func_800995B8(player, 3);
            func_8009E830(player, 2);
            bs_setState(player, 0x46);
            break;
        default:
            func_80099B94(player);
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_808000F0_bssub(player) PlayerState *player;
{
    f32 speed_t = func_800F10B4(func_8009BB94(player), 0.0f, 225.0f, 0.0f, 1.0f);
    f32 accel;
    f32 rate;
    f32 roll_accel;
    f32 fp_scale;
    f32 roll_rate;
    if (player_inWater(player))
    {
        rate = func_800F1214(speed_t, 50.0f, 150.0f);
        accel = func_800F1214(speed_t, 0.5f, 2.0f); roll_rate = func_800F1214(speed_t, 40.0f, 150.0f); roll_accel = func_800F1214(speed_t, 0.6f, 3.0f); baroll_setAngularVelocity(player, roll_rate, roll_accel); yaw_setVelocityBounded(player, 250, 20);
    }
    else
    {
        rate = 250.0f;
        accel = 2.8f;
        baroll_setAngularVelocity(player, 250, accel);
        yaw_setVelocityBounded(player, 300.0f, 3.0f);
    }
    fp_scale = _bafpctrl_entrypoint_3(player);
    rate *= func_800F10B4(fp_scale, 0.1f, 1.0f, fp_scale * fp_scale, 1.0f);
    func_8009BFE4(player, rate, accel);
}

void func_80800254_bssub(player) PlayerState *player;
{
    f32 accel;
    f32 angle;
    f32 max_speed;
    f32 scale;
    f32 frame_dt;
    s32 in_water;
    f32 pos[3];
    s32 emitter;

    max_speed = func_800A3048() * 90.0f;
    frame_dt = func_800D8FF8();
    in_water = player_inWater(player);
    if (in_water) {
        baphysics_set_gravity(player, 0.0f);
        baphysics_set_terminal_velocity(player, -4000.0f);
        _bamovethrust_entrypoint_4(player, 0.9f);
        _bamovethrust_entrypoint_3(player, player->unk16C);
    } else {
        baphysics_set_gravity(player, -1800.0f);
        baphysics_set_terminal_velocity(player, -4000.0f);
        _bamovethrust_entrypoint_4(player, 0.95f);
        _bamovethrust_entrypoint_3(player, player->unk16C * 0.25f);
    }
    if (bakey_held(player, 8) || _basub_entrypoint_2(player) != 0.0f) {
        accel = func_80800030_bssub(player->unk16C, frame_dt);
    } else {
        accel = func_80800048_bssub(player->unk16C, frame_dt);
    }
    if (_basub_entrypoint_2(player) != 0.0f) {
        player->unk16C =
            func_800F0D50(player->unk16C + accel, 0.0f, _basub_entrypoint_2(player));
    } else {
        player->unk16C = func_800F0D50(player->unk16C + accel, 0, max_speed);
    }
    _basub_entrypoint_13(player, func_800F10B4(player->unk16C, 0.0f, max_speed, 200.0f, 1350.0f));
    scale = func_800F10B4(player->unk16C, 0.0f, max_speed, 0.8f, 1.1f);
    angle = mlAbsF(func_800F1DCC(yaw_getIdeal(player), yaw_get(player))) / frame_dt;
    scale += func_800F10B4(angle, 0.0f, 128.0f, 0.0f, -0.12f);
    if (!in_water) {
        scale += 0.7f;
    }
    _basub_entrypoint_11(player, scale);
    angle = func_8009BFD8(player);
    if (angle > 180.0f) {
        angle -= 360.0f;
    }
    _basub_entrypoint_12(player, func_800F1344(angle, 0.0f, 85.0f, 0.0f, 60.0f));
    if (in_water) {
        if (_basub_entrypoint_2(player) != 0.0f) {
            func_800914FC(player, 60.0f, 1);
        } else {
            func_800914FC(
                player,
                func_800F10B4(player->unk16C, 0.0f, max_speed, func_800DC178(1.0f, 3.0f), 40.0f), 0);
        }
    } else if (player->unk16C > 0.0f && player_isStable(player)) {
        func_8009C128(player, pos);
        emitter = func_800B5BE4(8);
        func_800BABB8(emitter, pos, 0, 1.0f, D_808016E0_bssub);
        func_800BA77C(emitter, 0, 0, (s16) func_800DC178(0.0f, 359.0f));
        func_800BA22C(emitter, 1);
    }
    func_808000F0_bssub(player);
}

void func_80800634_bssub(PlayerState *player)
{
    f32 yaw_delta;
    f32 max_roll;
    f32 turn_rate;
    f32 frame_dt;
    f32 stick_x;

    stick_x = bastick_getX(player);
    frame_dt = func_800D8FF8();
    max_roll = func_800F10B4(func_8009BB94(player), 0.0f, 225.0f, 11.25f, 45.0f);
    baroll_setIdeal(player, func_800F10B4(stick_x, -1.0f, 1.0f, -max_roll, max_roll));
    if (player_inWater(player)) {
        turn_rate =
            func_800F10B4(func_8009BB94(player), 0.0f, 225.0f, 42.666667938232421875f, 128.0f);
    } else {
        turn_rate = 300.0f;
    }
    yaw_delta = func_800F10B4(stick_x, -1.0f, 1.0f, turn_rate, -turn_rate) * frame_dt;
    yaw_delta *= _bafpctrl_entrypoint_3(player);
    yaw_setIdeal(player, yaw_getIdeal(player) + yaw_delta);
}

void func_80800768_bssub(player) PlayerState *player;
{
    f32 stick_y;
    f32 max_down;
    f32 max_up;
    f32 pitch;

    if (player_inWater(player)) {
        max_down = 275.0f;
        max_up = 85.0f;
    } else {
        max_down = 325.0f;
        max_up = 30.0f;
    }
    stick_y = bastick_getY(player);
    if (stick_y < 0.0f) {
        pitch = func_800F10B4(stick_y, -1.0f, 0.0f, max_down, 360.0f);
        func_8009BF5C(player, pitch);
    } else {
        pitch = func_800F10B4(stick_y, 0.0f, 1.0f, 0.0f, max_up);
        func_8009BF5C(player, pitch);
    }
}

void func_80800834_bssub(PlayerState *player)
{
    if (bakey_pressed(player, 2))
        _basub_entrypoint_1(player);
    if (bakey_pressed(player, 1))
        _basub_entrypoint_8(player, func_8009BB94(player));
    if (bakey_pressed(player, 9)) {
        if (func_800EA068(0x40))
            _basub_entrypoint_3(player, 160.0f, 1.0f);
        else
            _basub_entrypoint_5(player);
    }
}

// Form exit: teardown is skipped when the next state has the same class (0xF).
void func_808008D8_bssub(PlayerState *player)
{
    if (!func_8009E74C(player, 0xF)) {
        func_800947EC(player, 1, 0);
        func_800961AC(player, 1);
        func_8009BC34(player);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        func_8009C000(player);
        baroll_resetAngularVelocity(player);
        bastick_resetZones(player);
        func_80095A40(player);
        func_80095964(player, 0);
        func_80093360(player, 0.0f);
        _basub_entrypoint_9(player);
        func_800910BC(player, 1);
        _bafpctrl_entrypoint_18(player, 0);
        func_8009E474(player);
        func_80092864(player, 1.0f);
    }
}

// Form enter: setup is skipped when the previous state has the same class (0xF).
void func_808009B0_bssub(player) PlayerState *player;
{
    if (!func_8009E77C(player, 15)) {
        _basub_entrypoint_10(player);
        player->unk16C = 0.0f;
        player->unk170 = 0.0f;
        baphysics_set_gravity(player, 0);
        baphysics_set_terminal_velocity(player, -399.989990234375f);
        func_800961AC(player, 9);
        func_80095964(player, 1);
        func_8009BC5C(player, 2.0f);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 1.0f);
        func_800959C8(player, 90.0f, 70.0f);
        func_8009E4AC(player);
        func_8009E55C(player, 0, 70.0f);
        func_8009E55C(player, 1, 0.0f);
        func_8009E55C(player, 2, 0.0f);
        func_80093360(player, 55.0f);
        func_800910BC(player, 4);
        func_808000F0_bssub(player);
        _bafpctrl_entrypoint_18(player, 1);
        func_800947EC(player, 1, 1);
        func_80092864(player, 2.0f);
    }
}

void func_80800AEC_bssub()
{
    _basub_entrypoint_14();
}

void func_80800B0C_bssub()
{
    _baspin_entrypoint_1();
}

void func_80800B2C_bssub(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, 0x12E, 6.0f);
    func_80800000_bssub(player);
    _bamovethrust_entrypoint_3(player, 0.0f);
    _bamovethrust_entrypoint_4(player, 0.9f);
    _basub_entrypoint_11(player, 0.6f);
    _basub_entrypoint_13(player, 1.0f);
    _baspin_entrypoint_2(player, 0x130, 1.8f, 3, 1);
    _batimer_set(player, 9, 1.8f);
    func_800FC660(0x19);
}

int func_80800BD8_bssub(Actor *player)
{
    _baspin_entrypoint_3();
    if (_batimer_decrement(player, 9) != 0) {
        func_80101180(0x2C4, 0x71, *(u32 *) ((char *) player + 0x184));
    }
}

void func_80800C1C_bssub(void *player)
{
    if (*(s32 *) ((char *) player + 0x15C) != 0) {
        func_80800B0C_bssub(player);
    } else {
        _basudie_entrypoint_8(player);
    }
    func_808008D8_bssub(player);
}

// Sub death: spawns 10 debris emitters plus air bubbles when under water.
void func_80800C60_bssub(void *player)
{
    s32 emitters[10];
    f32 pos[3];
    s32 i;

    func_8009DB04(player, 0x413, 1.0, 0x7FFF);
    func_8009D9D4(player);
    func_8009C128(player, pos);
    func_800BBCB8(pos, NULL, 1.0f, 1, D_808017A0_bssub);
    for (i = 0; i < 10; i++) {
        emitters[i] = func_800B53A4(D_80801840_bssub[i].type);
        func_800BA670(emitters[i], D_80801840_bssub[i].sprite);
        emitters[i] =
            func_800BABB8(emitters[i], pos, pos, 1.0f, D_8080172C_bssub);
    }
    if (player_inWater(player)) {
        func_800BABB8(_fxairbub_entrypoint_1(pos, 100.0f, func_800964DC(player), 1.0f),
                      pos, pos, 1.0f, D_808017CC_bssub);
        for (i = 0; i < 10; i++) {
            emitters[i] =
                func_800BABB8(emitters[i], pos, pos, 1.0f, D_80801748_bssub);
        }
    } else {
        for (i = 0; i < 10; i++) {
            emitters[i] =
                func_800BABB8(emitters[i], pos, pos, 1.0f, D_80801774_bssub);
        }
    }
    for (i = 0; i < 10; i++) {
        func_800BA22C(emitters[i], D_80801840_bssub[i].type);
    }
}

void func_80800E34_bssub(s32 player)
{
    s32 spin_death;
    s32 *s0;
    s0 = (s32 *) player;
    func_808009B0_bssub(s0);
    spin_death = func_800EA068(0x40);
    s0[0x57] = spin_death;
    if (spin_death != 0) {
        func_80800B2C_bssub(s0);
    } else {
        _bafpctrl_entrypoint_19(s0);
        _basudie_entrypoint_9(s0, 0x41F00000);
        func_80800C60_bssub(s0);
    }
}

int func_80800E98_bssub(Actor *player)
{
    func_80800AEC_bssub();
    if (*(s32 *) ((char *) player + 0x15c) != 0) {
        func_80800BD8_bssub(player);
    } else {
        _basudie_entrypoint_10();
    }
}

int func_80800EE0_bssub(Actor *player)
{
    s32 interrupt;
    Actor *plr = player;
    interrupt = func_8009E6EC();
    if (interrupt == 0x83) {
        func_8009BDAC(plr, func_80099A34(plr));
        func_80093370(plr, 1);
        bs_setState(plr, 0x131);
        func_8009E830(plr, 2);
    } else {
        _basudie_entrypoint_11(plr);
    }
}

int bssub_entrypoint_0(s32 player)
{
    return D_80801890_bssub[player];
}

void func_80800F70_bssub(s32 player)
{
    _bsdrone_entrypoint_2();
    func_808008D8_bssub(player);
}

void func_80800F98_bssub(s32 player)
{
    func_808009B0_bssub();
    _bsdrone_entrypoint_0(player);
}

void func_80800FC0_bssub(s32 player)
{
    func_80800AEC_bssub();
    func_80800254_bssub(player);
    _bsdrone_entrypoint_1(player);
}

int bssub_entrypoint_1(s32 player)
{
    return D_808018A0_bssub[player];
}

void func_80801004_bssub(s32 player)
{
    func_80090A2C();
    func_808008D8_bssub(player);
}

void func_8080102C_bssub(player) PlayerState *player;
{
    AnimCtrl *anim_ctrl;
    s32 anim_id;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anim_id = anctrl_getIndex(anim_ctrl);
    func_8008CA4C(player, 2);
    if (func_8009BB94(player) < 300.0f) {
        if (anim_id != 0x12E) {
            baanim_playForDuration_loopSmooth(player, 0x12E, 6.0f);
            func_8008B1C8(anim_ctrl, 0.4f);
        }
        func_8008C9F0(player, 0.0f, 900.0f, 6.0f, 6.0f);
    } else {
        if (anim_id != 0x12F) {
            baanim_playForDuration_loopSmooth(player, 0x12F, 0.45f);
            func_8008B1C8(anim_ctrl, 0.4f);
        }
        func_8008C9F0(player, 0.0f, 900.0f, 1.5f, 0.45f);
    }
}

int func_80801130_bssub(s32 player)
{
    s32 player_copy;
    player_copy = player | 0;
    func_808009B0_bssub(player_copy);
    func_8080102C_bssub(player_copy);
    baanim_setDurationRange(player_copy, 0x3E99999A, 0x41200000);
    func_8008CA30(player_copy, 0x3F800000);
    func_800909CC(player_copy);
}

void func_80801188_bssub(u8 *player)
{
    s32 next_state;

    next_state = 0;
    func_80800AEC_bssub();
    func_8080102C_bssub(player);
    func_80800634_bssub(player);
    func_80800768_bssub(player);
    func_80800254_bssub(player);
    func_80800834_bssub(player);
    if (*(f32 *) ((s8 *) player + 0x16C) == 0.0f) {
        next_state = 0x131;
    }
    bs_setState(player, next_state);
}

int bssub_entrypoint_2(s32 player)
{
    return D_808018B0_bssub[player];
}

void func_8080121C_bssub(s32 player)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(player);
}

void func_80801244_bssub(s32 player)
{
    func_808009B0_bssub();
    _baspin_entrypoint_2(player, 0x130, 1.8f, 3, 1);
}

void func_80801284_bssub(Actor *player)
{
    s32 next_state;
    next_state = 0;
    func_80800AEC_bssub();
    func_800914FC(player, 4e+01f, 0);
    if (_baspin_entrypoint_3(player) == 2) {
        next_state = 0x131;
    }
    bs_setState(player, next_state);
}

int bssub_entrypoint_3(s32 player)
{
    return D_808018C0_bssub[player];
}

void func_808012F0_bssub(s32 player)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(player);
}

void func_80801318_bssub(s32 player)
{
    func_808009B0_bssub();
    _baspin_entrypoint_2(player, 0x130, 1.8f, 3, 1);
}

void func_80801358_bssub(Actor *player)
{
    s32 next_state;
    next_state = 0;
    func_80800AEC_bssub();
    func_800914FC(player, 4e+01f, 0);
    if (_baspin_entrypoint_3(player) == 2) {
        next_state = 0x131;
    }
    bs_setState(player, next_state);
}

int bssub_entrypoint_4(s32 player)
{
    return D_808018D0_bssub[player];
}

void func_808013C4_bssub(s32 player)
{
    _babounce_entrypoint_3();
    func_808008D8_bssub(player);
}

int func_808013EC_bssub(s32 player)
{
    func_808009B0_bssub();
    _babounce_entrypoint_4(player, 2);
    _babounce_entrypoint_5(player, 0x12E, 0x40C00000);
}

s32 func_80801428_bssub(s32 player)
{
    s32 next_state;

    next_state = 0;
    func_80800AEC_bssub();
    func_800914FC(player, 4e+01f, 0);
    if (_babounce_entrypoint_9(player) != 0) {
        next_state = 0x131;
    }
    bs_setState(player, next_state);
}

int bssub_entrypoint_5(s32 player)
{
    return D_808018E0_bssub[player];
}

void func_80801490_bssub(s32 player)
{
    _bsrest_entrypoint_14();
    func_808008D8_bssub(player);
}

void func_808014B8_bssub(u8 *player)
{
    func_808009B0_bssub();
    func_8009BF5C(player, 0);
    _bsrest_entrypoint_16(player);
    func_8009B94C(player, 0);
    func_8009BA9C(player, 0);
    *(f32 *) ((s8 *) player + 0x16C) = 0.0f;
}

int func_80801518_bssub(Actor *player)
{
    s32 next_state;
    next_state = 0;
    func_80800AEC_bssub();
    if (_bsrest_entrypoint_20(player)) {
        next_state = _badata_entrypoint_34(player);
    }
    bs_setState(player, next_state);
}

int bssub_entrypoint_6(s32 player)
{
    return D_808018F0_bssub[player];
}

void func_80801578_bssub(s32 player)
{
    func_80090A2C();
    func_808008D8_bssub(player);
}

void func_808015A0_bssub(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808009B0_bssub(player);
    if (anctrl_getIndex(anim_ctrl) == 0x12E) {
        anctrl_setDuration(anim_ctrl, 6.0f);
    } else {
        baanim_playForDuration_loopSmooth(player, 0x12E, 6.0f);
    }
    func_800909CC(player);
    func_80800000_bssub(player);
}

void func_80801618_bssub(Actor *player)
{
    s32 next_state;
    next_state = 0;
    func_80800AEC_bssub();
    func_80800634_bssub(player);
    func_80800768_bssub(player);
    func_80800254_bssub(player);
    func_80800834_bssub(player);
    if (*(f32 *) ((char *) player + 0x16C) != 0.0f) {
        next_state = 0x12C;
    }
    bs_setState(player, next_state);
}

int bssub_entrypoint_7(s32 player)
{
    return D_80801900_bssub[player];
}

extern void _bsdrone_entrypoint_3();
s32 D_808016E0_bssub[19] = {0x1D09DC,   0xA0000,   0x0,      0x0,       0x2C,
                            -0x4FFFCE,  -0x4FFFB0, 0x320050, 0x150014,  0x660020,
                            -0xF0F0FB0, 0x220033,  0x6600CC, 0x1330016, 0x10000018,
                            0x6,        0x0,       0x2B0099, 0xB30000};
u8 D_8080172C_bssub[28] = {0x0, 0x16, 0x0, 0x2,  0x0, 0x15, 0x0, 0x0, 0x0, 0xB3,
                           0x0, 0x1E, 0x0, 0x1E, 0x0, 0x1E, 0x0, 0x4, 0x0, 0x99,
                           0x0, 0x7,  0x0, 0x5,  0x0, 0x0,  0x0, 0x0};
u8 D_80801748_bssub[44] = {0x0,  0x26, 0x0,  0x96, 0x0,  0x96, 0x0,  0x0,  0x0,  0xFA, 0x0,
                           0xFA, 0x0,  0x0,  0x0,  0x2E, 0xFF, 0xA8, 0x0,  0x0,  0x0,  0x96,
                           0x0,  0x58, 0x1,  0x67, 0x0,  0xFA, 0x0,  0x1B, 0xFF, 0x38, 0xFF,
                           0x9C, 0x0,  0x2B, 0x2,  0xB3, 0x2,  0xB3, 0x0,  0x0,  0x0,  0x0};
u8 D_80801774_bssub[44] = {0x0,  0x26, 0x1,  0x90, 0x0,  0xC8, 0x0,  0x0,  0x3,  0x84, 0x1,
                           0xF4, 0x0,  0x0,  0x0,  0x2E, 0xFF, 0xA4, 0x0,  0x0,  0x2,  0x58,
                           0xFF, 0xD8, 0x1,  0x67, 0x3,  0x20, 0x0,  0x1B, 0xFA, 0x24, 0xFA,
                           0x88, 0x0,  0x2B, 0x2,  0x66, 0x2,  0x66, 0x0,  0x0,  0x0,  0x0};
u8 D_808017A0_bssub[44] = {0x0,  0x1D, 0x9, 0xD6, 0x0,  0x15, 0x0,  0x0, 0x0,  0x4C, 0x0,
                           0x16, 0x10, 0x0, 0x0,  0x1E, 0x0,  0x1E, 0x0, 0x1E, 0x0,  0x19,
                           0x0,  0x0,  0x0, 0x0,  0x0,  0x22, 0x1,  0x0, 0x1,  0x0,  0x4,
                           0x0,  0x4,  0x0, 0x0,  0x2B, 0x0,  0x80, 0x0, 0x80, 0x0,  0x0};
u8 D_808017CC_bssub[116] = {
    0x0,  0xC,  0x0,  0x23, 0x0,  0x2B, 0x2,  0x0,  0x2,  0x80, 0x0,  0x2D, 0x0,  0x14, 0x0,
    0x28, 0x0,  0x22, 0x0,  0x14, 0x0,  0x1E, 0x0,  0x23, 0x0,  0x30, 0x4,  0x1A, 0x0,  0xC,
    0x0,  0x2D, 0x0,  0x2B, 0x1,  0x80, 0x2,  0x0,  0x0,  0x2D, 0x0,  0x32, 0x0,  0x46, 0x0,
    0x22, 0x0,  0x21, 0x0,  0x26, 0x0,  0x2E, 0x0,  0x3A, 0x6,  0x1A, 0x0,  0xC,  0x0,  0x37,
    0x0,  0x2B, 0x1,  0x0,  0x1,  0x80, 0x0,  0x2D, 0x0,  0x46, 0x0,  0x50, 0x0,  0x22, 0x0,
    0x28, 0x0,  0x35, 0x0,  0x40, 0x0,  0x4C, 0x7,  0x1A, 0x0,  0xC,  0x0,  0x3C, 0x0,  0x2D,
    0x0,  0x50, 0x0,  0x5A, 0x0,  0x2B, 0x0,  0x80, 0x1,  0x0,  0x0,  0x22, 0x0,  0x3D, 0x0,
    0x40, 0x0,  0x4A, 0x0,  0x59, 0x8,  0x1A, 0x0,  0x0,  0x0,  0x0};
SubPartDef D_80801840_bssub[10] = {0x1, 0x711, 0x1, 0x712, 0x1, 0x713, 0x3, 0x714, 0x4, 0x715,
                                   0x2, 0x716, 0x1, 0x717, 0x1, 0x718, 0x1, 0x719, 0x1, 0x963};
s32 D_80801890_bssub[4] = {(u32) func_80800C1C_bssub, (u32) func_80800E34_bssub,
                           (u32) func_80800E98_bssub, (u32) func_80800EE0_bssub};
s32 D_808018A0_bssub[4] = {(u32) func_80800F70_bssub, (u32) func_80800F98_bssub,
                           (u32) func_80800FC0_bssub, (u32) _bsdrone_entrypoint_3};
s32 D_808018B0_bssub[4] = {(u32) func_80801004_bssub, (u32) func_80801130_bssub,
                           (u32) func_80801188_bssub, (u32) func_80800064_bssub};
s32 D_808018C0_bssub[4] = {(u32) func_8080121C_bssub, (u32) func_80801244_bssub,
                           (u32) func_80801284_bssub, (u32) func_80800064_bssub};
s32 D_808018D0_bssub[4] = {(u32) func_808012F0_bssub, (u32) func_80801318_bssub,
                           (u32) func_80801358_bssub, (u32) func_80800064_bssub};
s32 D_808018E0_bssub[4] = {(u32) func_808013C4_bssub, (u32) func_808013EC_bssub,
                           (u32) func_80801428_bssub, (u32) func_80800064_bssub};
s32 D_808018F0_bssub[4] = {(u32) func_80801490_bssub, (u32) func_808014B8_bssub,
                           (u32) func_80801518_bssub, (u32) func_80800064_bssub};
s32 D_80801900_bssub[4] = {(u32) func_80801578_bssub, (u32) func_808015A0_bssub,
                           (u32) func_80801618_bssub, (u32) func_80800064_bssub};
