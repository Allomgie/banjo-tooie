// Probably the underwater swimming states of Banjo & Kazooie: idle, paddle, fast stroke, glide,
// hurt, spin, bounce, dive, drowning, plunge, first-person look and underwater split-up.
#include "common.h"
#include "overlays/ba/playerstate.h"
extern void _baswim_entrypoint_10(PlayerState *, f32);
extern void baroll_setIdeal(Actor *a0, f32 a1);
extern void func_8009BF5C(Actor *a0, f32 a1);

void baphysics_set_gravity(s32, f32);
extern s32 D_80801E60_bsbswim[];
extern void _baswim_entrypoint_8(void *param_0, int param_1);
extern float anctrl_getAnimTimer(void *param_0);
extern void baanim_playForDuration_loopStartingAt(Actor *param_0, int param_1, float param_2,
                                                  float param_3);
extern int bs_getPreviousState(Actor *param_0);
extern void func_800910BC(Actor *param_0, int param_1);
extern s32 D_80801E70_bsbswim[];
extern void *baanim_getAnimCtrlPtr();
extern s32 anctrl_isAt(void *, f32);
extern s32 func_8009FBB0(PlayerState *, f32 *, f32);
extern void func_8009DE74(void *, s32, f32, f32);
extern s32 D_80801E80_bsbswim[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009BC5C(PlayerState *, f32);
extern s32 D_80801E90_bsbswim[];
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_8009D89C(PlayerState *, f32);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 _bareact_entrypoint_4(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern s32 D_80801EA0_bsbswim[];
extern s32 D_80801EB0_bsbswim[];
extern s32 D_80801EC0_bsbswim[];
extern s32 D_80801ED0_bsbswim[];
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_800A0180(void *);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void baphysics_set_vertical_velocity(void *, f32);
extern s32 _batimer_isAt_rising(void *, s32, f32);
extern s32 _batimer_isGreaterThan(void *, s32, f32);
extern void _ncbadie_entrypoint_3(void *, f32);
extern void func_800A4E30();
extern void func_8008E95C();
extern s32 D_80801EE0_bsbswim[];
extern void _baswim_entrypoint_9(PlayerState *, f32);
extern s32 D_80801EF0_bsbswim[];
extern void anctrl_setDuration(void *, f32);
extern void anctrl_setStart(void *, f32);
extern f32 func_800A3298(PlayerState *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_80801F00_bsbswim[];
extern s32 D_80801F10_bsbswim[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_80801F20_bsbswim[];
extern s32 D_80801F78_bsbswim[];
extern s32 D_80801F88_bsbswim[];
extern s32 D_80801F98_bsbswim[];
extern f32 mlAbsF(f32);
extern f32 baphysics_get_vertical_velocity(void *);

// Shared underwater enter/exit: air bar, zero gravity, terminal velocity, roll, collision mode.
void func_80800000_bsbswim(int player)
{
    func_8009FFD8(player, 1, 3, 3, 9);
}

extern void func_80093360(Actor *a0, f32 a1);

// Shared enter: no gravity, terminal velocity, roll, water physics, air bar.
// Matching: the redundant block and extra temporaries are needed for the match.
void func_80800030_bsbswim(player) Actor *player;
{
    int enable;
    Actor *player_alias;
    {
        if (!func_8009E77C(player, 0xB)) {
            _baswim_entrypoint_5(player);
            baroll_setAngularVelocity(player, 0x43020000, 0x3F666666);
            baphysics_set_gravity(player, 0 & 0xFFFFFFFFFFFFFFFFu);
            baphysics_set_terminal_velocity(player, 0xC3C7FEB8);
            if (func_800F8B88() != 3) {
                player_alias = player;
                func_800A0CF4(player_alias, 1);
            }

            func_800961AC(player, 3);
            func_80093360(player, 6e+01f);
            func_8009BC5C(player, 2.0f);
            enable = 1;
            _baswim_entrypoint_6(player, enable);
            if (bs_getCurrentState(player) != 0x4C) {
                _baairbar_entrypoint_0(player, 2);
            }
        }
    }
}

// Shared exit: restore gravity, roll and physics, remove the air bar.
// Matching: the extra copy of the player pointer is needed for the match.
int func_80800104_bsbswim(player)
Actor *player;
{
    Actor *player_alias = player;
    if (!func_8009E74C(player_alias, 0xB)) {
        func_8009BF5C(player, 0);
        baroll_setIdeal(player, 0);
        func_8009BC34(player);
        func_800A0CF4(player, 0);
        func_800961AC(player, 1);
        func_80093360(player, 0);
        _baswim_entrypoint_6(player, 0);
        if (bs_getCurrentState(player) != 0x4C) {
            _baairbar_entrypoint_0(player, 1);
        }
        _baswim_entrypoint_4(player);
    }
}

void func_808001A8_bsbswim()
{
    func_80800104_bsbswim();
}

// Idle tread state.
void func_808001C8_bsbswim(s32 player)
{
    s32 anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x70);
    anctrl_setDuration(anim_ctrl, 2.0f);
    func_8008B1C8(anim_ctrl, 0x3F000000);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_80800000_bsbswim(player);
    func_8009B94C(player, 0);
    func_80800030_bsbswim(player);
    func_8009BC5C(player, 0.4f);
    _baswim_entrypoint_8(player, 0x43960000);
    if (func_8008E23C(player) != 0) {
        func_800A0CF4(player, 0);
    }
}

void func_80800288_bsbswim(s32 player)
{
    s32 next_state;
    next_state = 0;
    _baswim_entrypoint_11(player);
    _baswim_entrypoint_12(player);
    _baswim_entrypoint_13(player);
    if (func_8008E23C(player)) {
        if (bakey_held(player, 8) || bakey_held(player, 9)) {
            next_state = 0x81;
        }
    } else {
        switch (_baswim_entrypoint_3(player)) {
            case 0:
                break;
            case 1:
                next_state = 0x39;
                break;
            case 2:
                next_state = 0x2C;
                break;
            case 3:
                next_state = 0x19;
        }
        if (bainput_func_8009803C(player)) {
            next_state = 0x157;
        }
    }
    if (_baswim_entrypoint_2(player)) {
        next_state = 0x2D;
    }
    if (!player_inWater(player)) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

int bsbswim_entrypoint_0(s32 index)
{
    return D_80801E60_bsbswim[index];
}

// Slow paddle state with stroke sound.
void func_8080039C_bsbswim(Actor *player)
{
    void *anim_ctrl;
    float start_time;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (bs_getPreviousState(player) == 0x19) {
        start_time = anctrl_getAnimTimer(anim_ctrl);
    } else {
        start_time = 0.5f;
    }
    baanim_playForDuration_loopStartingAt(player, 0x3F, 1.0f, start_time);
    func_80800000_bsbswim(player);
    func_80800030_bsbswim(player);
    _baswim_entrypoint_8(player, 0x43960000);
    func_8009BC5C(player, 1.0f);
    func_800910BC(player, 2);
}

void func_80800440_bsbswim(Actor *player)
{
    s32 next_state;
    s32 anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(player);
    _baswim_entrypoint_12(player);
    _baswim_entrypoint_13(player);
    if (anctrl_isAt(anim_ctrl, 0.1f) != 0) {
        func_8009DE74(player, 0x3FD, 1.2f, 1.4f);
        _baswim_entrypoint_10(player, 6e+02f);
    }
    if (anctrl_isAt(anim_ctrl, 0.4626f) != 0) {
        anctrl_setDuration(anim_ctrl, 1.0f);
    }
    if (anctrl_isAt(anim_ctrl, 0.2766f) != 0) {
        anctrl_setDuration(anim_ctrl, 3.0f);
    }
    switch (_baswim_entrypoint_3(player)) {
        case 2:
            break;
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.4625f) != 0) {
                next_state = 0x2B;
            }
            break;
        case 1:
            next_state = 0x39;
            break;
        case 3:
            next_state = 0x19;
    }
    if ((anctrl_isAt(anim_ctrl, 0.4625f) != 0) && (bakey_held(player, 9) == 0)) {
        if (bakey_held(player, 8) != 0) {
            next_state = 0x39;
        } else {
            next_state = 0x2B;
        }
    }
    if (bainput_func_8009803C(player) != 0) {
        next_state = 0x157;
    }
    if (_baswim_entrypoint_2(player) != 0) {
        next_state = 0x2D;
    }
    if (player_inWater(player) == 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void func_808005F4_bsbswim(s32 player)
{
    func_800910BC(player, 0x1);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_1(s32 index)
{
    return D_80801E70_bsbswim[index];
}

// Fast stroke state with a bubble trail.
void func_80800634_bsbswim(Actor *player)
{
    void *anim_ctrl;
    float start_time;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (bs_getPreviousState(player) == 0x2c) {
        start_time = anctrl_getAnimTimer(anim_ctrl);
    } else {
        start_time = 0.5f;
    }
    baanim_playForDuration_loopStartingAt(player, 0xeb, 1.0f, start_time);
    func_80800000_bsbswim(player);
    func_80800030_bsbswim(player);
    _baswim_entrypoint_8(player, 0x44160000);
    func_8009BC5C(player, 1.0f);
    func_800910BC(player, 2);
    *(u8 *) ((char *) player + 0x166) = 0;
}

void func_808006DC_bsbswim(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    s32 hitbox;
    f32 pos[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _baswim_entrypoint_11(player);
    _baswim_entrypoint_12(player);
    _baswim_entrypoint_13(player);
    if (anctrl_isAt(anim_ctrl, 0.3f)) {
        player->unk164.bytes[2] = 1;
    }
    if (!func_8001210C(1)) {
        func_8009C128(player, &pos);
        pos[1] += 60.0f;
        hitbox = func_8009FBB0(player, &pos, 40.0f);
        func_800BA930(hitbox, -60, -50, -60, 60, 100, 60);
        func_800BA22C(hitbox, 1);
    }
    if (anctrl_isAt(anim_ctrl, 0.08f)) {
        func_8009DE74(player, 0x3FD, 1.2f, 1.4f);
        _baswim_entrypoint_10(player, 9e+02f);
    } else {
        _baswim_entrypoint_10(player, 5e+02f);
    }
    switch (_baswim_entrypoint_3(player)) {
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.4791f)) {
                next_state = 0x2B;
            }
            break;
        case 1:
            if (player->unk164.bytes[2]) {
                next_state = 0x39;
            }
            break;
        case 2:
            if (player->unk164.bytes[2]) {
                next_state = 0x2C;
            }
        case 3:
            break;
    }
    if (bainput_func_8009803C(player)) {
        next_state = 0x157;
    }
    if (_baswim_entrypoint_2(player)) {
        next_state = 0x2D;
    }
    if (!player_inWater(player)) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void func_808008CC_bsbswim(s32 player)
{
    func_800910BC(player, 0x1);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_2(s32 index)
{
    return D_80801E80_bsbswim[index];
}

// Glide/drift state.
void func_8080090C_bsbswim(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, 0x71, 0.75f);
    func_80800000_bsbswim(player);
    func_80800030_bsbswim(player);
    _baswim_entrypoint_10(player, 2.5e+02f);
    _baswim_entrypoint_8(player, 0x44160000);
    func_8009BC5C(player, 2.0f);
    func_800910BC(player, 2);
}

void func_8080097C_bsbswim(Actor *player)
{
    s32 next_state;
    s32 anim_ctrl;
    s32 input;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _baswim_entrypoint_11(player);
    _baswim_entrypoint_12(player);
    _baswim_entrypoint_13(player);
    _baswim_entrypoint_10(player, 2.5e+02f);
    if (anctrl_isAt(anim_ctrl, 0.17f) != 0) {
        func_8009DF18(player, 0x3FD, 1.9f, 0x2710);
    }
    if (anctrl_isAt(anim_ctrl, 0.67f) != 0) {
        func_8009DF18(player, 0x3FD, 1.7f, 0x2710);
    }
    input = _baswim_entrypoint_3(player);
    switch (input) {
        case 1:
            break;
        case 0:
            if (anctrl_isAt(anim_ctrl, 0.4791f) != 0) {
                next_state = 0x2B;
            }
            break;
        case 2:
            next_state = 0x2C;
            break;
        case 3:
            next_state = 0x19;
    }
    if (bainput_func_8009803C(player) != 0) {
        next_state = 0x157;
    }
    if (_baswim_entrypoint_2(player) != 0) {
        next_state = 0x2D;
    }
    if (player_inWater(player) == 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void func_80800AD0_bsbswim(s32 player)
{
    func_800910BC(player, 0x1);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_3(s32 index)
{
    return D_80801E90_bsbswim[index];
}

// Hurt knockback state.
void func_80800B10_bsbswim(PlayerState *player)
{
    f32 yaw;
    f32 player_pos[3];
    f32 other_pos[3];

    _bareact_entrypoint_1(player, func_80099A58(player));
    baanim_playForDuration_once(player, 0x14, 1.4f);
    func_8009D89C(player, 1.0f);
    func_8009C128(player, player_pos);
    func_800A32C4(player, other_pos);
    func_800F1E6C(other_pos, player_pos, &yaw);
    yaw_setIdeal(player, yaw);
    yaw_applyIdeal(player);
    baphysics_set_target_horizontal_velocity(player, _bareact_entrypoint_4(player));
    baphysics_set_target_yaw(player, yaw);
    baphysics_set_horizontal_velocity(player, yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    func_8009FFD8(player, 1, 1, 2, 3);
    func_8008E944(player);
    func_8009514C(player);
    func_80800030_bsbswim(player);
}

void func_80800C0C_bsbswim(PlayerState *player)
{
    s32 next_state;
    f32 pos[3];
    s32 hitbox;

    next_state = 0;
    func_8009C128(player, pos);
    pos[1] += 60.0f;
    hitbox = func_8009FBB0(player, pos, 25.0f);
    func_800BA930(hitbox, -60, -50, -60, 60, 100, 60);
    func_800BA22C(hitbox, 1);
    if (baanim_isAt(player, 0.3f))
        func_800951B4(player);
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(player)))
        next_state = 0x2B;
    bs_setState(player, next_state);
}

s32 func_80800CE4_bsbswim(s32 player)
{
    func_8009BD88();
    func_8008E95C(player);
    func_800951B4(player);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_4(s32 index)
{
    return D_80801EA0_bsbswim[index];
}

// Spin state.
void func_80800D30_bsbswim(s32 player)
{
    _baspin_entrypoint_1();
    func_80800104_bsbswim(player);
}

void func_80800D58_bsbswim(Actor *player)
{
    func_80800030_bsbswim();
    _baspin_entrypoint_2(player, 0xB9, 0x3F333333, 3, 1);
}

int func_80800D98_bsbswim(Actor *player)
{
    s32 next_state;
    next_state = 0;
    func_800914FC(player, 0x42200000, 0);
    if (_baspin_entrypoint_3(player) == 2) {
        next_state = 0x2B;
    }
    bs_setState(player, next_state);
}

int bsbswim_entrypoint_5(s32 index)
{
    return D_80801EB0_bsbswim[index];
}

// Bounce state.
s32 func_80800DFC_bsbswim(s32 player)
{
    _babounce_entrypoint_3();
    func_800961AC(player, 3);
    func_80800104_bsbswim(player);
}

// Matching: the temporary for the constant is needed for the match.
void func_80800E30_bsbswim(Actor *player)
{
    int unk_0;
    func_80800030_bsbswim();
    func_800961AC(player, 1);
    unk_0 = 0x3F15119D;
    _babounce_entrypoint_4(player, 2);
    _babounce_entrypoint_5(player, 0xf, unk_0);
}

int func_80800E7C_bsbswim(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_babounce_entrypoint_9()) {
        next_state = 0x2B;
    }
    bs_setState(player, next_state);
}

int bsbswim_entrypoint_6(s32 index)
{
    return D_80801EC0_bsbswim[index];
}

// Dive from the surface; first use of the move is recorded.
// Matching: the extra pointer temporaries and the empty statement are needed for the match.
void func_80800EC8_bsbswim(u8 *player)
{
    s8 *flag_ptr;
    u8 *player_copy;
    unsigned short anim_id;
    unsigned int offset;
    u8 *player_alias;
    anim_id = 0x3C;
    func_800C6DA0(0x3F);
    baanim_playForDuration_onceSmooth(player, anim_id, 0x3FC00000);
    func_80800000_bsbswim(player);
    yaw_setVelocityBounded(player, 0x43FA0000, 0x40A00000);
    func_8009B94C(player, 0);
    func_80800030_bsbswim(player_alias = player);
    {
        ;
        player_copy = player_alias;
        _baswim_entrypoint_10(player, (double) 0);
        _baswim_entrypoint_8(player_alias, 0x44160000);
        func_8009BFE4(player_alias, 0x43480000, 0x40200000);
        offset = 0x164;
        flag_ptr = (s8 *) ((s8 *) player + offset);
        func_8009D874(player_copy);
        *flag_ptr = 0;
    }
}

void func_80800F64_bsbswim(u8 *player)
{
    s32 next_state;
    s32 anim_ctrl;
    u8 phase;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    phase = *(u8 *) ((char *) player + 0x164);
    switch (phase) {
        case 0:
            func_8009BF5C(player, 5e+01f);
            if (anctrl_isAt(anim_ctrl, 0.2916f) != 0) {
                if (_baswim_entrypoint_1(player) != 0) {
                    func_800A0E64(player);
                }
                _baswim_entrypoint_10(player, 4e+02f);
                _baswim_entrypoint_8(player, 0x43960000);
                *(u8 *) ((char *) player + 0x164) = 1U;
            }
            break;
        case 1:
            _baswim_entrypoint_11(player);
            _baswim_entrypoint_13(player);
            if (anctrl_isAt(anim_ctrl, 0.58f) != 0) {
                next_state = 0x2B;
            }
    }
    if (anctrl_isAt(anim_ctrl, 0.6f) != 0) {
        func_8009DE38(player, 0x3FD, 0x3F800000);
    }
    if (player_inWater(player) == 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void func_80801084_bsbswim()
{
    func_80800104_bsbswim();
}

int bsbswim_entrypoint_7(s32 index)
{
    return D_80801ED0_bsbswim[index];
}

// Drowning death with die camera.
void func_808010B8_bsbswim(PlayerState *player)
{
    player->unk15C.word = func_8009E6C4(player, 4) || func_800F8B64();
    _basudie_entrypoint_1(player);
    baanim_playForDuration_loopSmooth(player, 0xB9, 0.7f);
    func_80800000_bsbswim(player);
    func_80800030_bsbswim(player);
    func_8009BC5C(player, 1.0f);
    func_8009B94C(player, 0);
    func_8009BA9C(player, 0);
    func_8009BF5C(player, 275.0f);
    baroll_setIdeal(player, 0.0f);
    func_8008E944(player);
    _batimer_set(player, 0, 0.0f);
    _batimer_set(player, 1, 0.0f);
    func_800910BC(player, 3);
    func_8009DF18(player, 0x467, 1.0f, 0x5DC0);
    _baswim_entrypoint_6(player, 0);
}

void func_808011C0_bsbswim(void *player)
{
    s32 flag;
    f32 rotation[3];
    s32 hitbox;
    f32 pos[3];

    func_800EF4E4(rotation, -90.0, 0.0, 0.0, 0.0, 100.0);
    func_8009B94C(player, rotation);
    func_8009BA9C(player, rotation);
    _batimer_increment(player, 1);
    if (_batimer_isAt_rising(player, 1, 0.2) || _batimer_isAt_rising(player, 1, 0.8) ||
        _batimer_isAt_rising(player, 1, 1.4)) {
        func_8009DF18(player, 0x468, 1.0, 0x5DC0);
    }
    flag = func_8001210C(1);
    if (!flag) {
        func_8009C128(player, pos);
        pos[1] += 60.0f;
        hitbox = func_8009FBB0(player, pos, 25.0f);
        func_800BA930(hitbox, -60, -50, -60, 60, 100, 60);
        func_800BA22C(hitbox, 1);
    }
    if (_batimer_isGreaterThan(player, 1, 1.55)) {
        baphysics_set_vertical_velocity(player, -50.0);
    }
    if (_batimer_isAt_rising(player, 1, 1.9)) {
        func_800A4DA4(player, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(player), 80.0);
        if (*(s32 *) ((u8 *) player + 0x15C)) {
            _batimer_set(player, 0, 0.5f);
        } else {
            func_800A0180(player);
            _batimer_set(player, 0, 3.5f);
        }
    }
    if (_batimer_decrement(player, 0)) {
        _basudie_entrypoint_0(player);
    }
    bs_setState(player, 0);
}

s32 func_808013C4_bsbswim(f32 player[3])
{
    _baswim_entrypoint_6(player, 1);
    func_800910BC(player, 1);
    func_800A4E30(player);
    func_8008E95C(player);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_8(s32 index)
{
    return D_80801EE0_bsbswim[index];
}

// Locked state: held by a lock request, back to idle when released.
void func_80801428_bsbswim(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, 0x70, 2.0f);
    func_80800000_bsbswim(player);
    func_8009B94C(player, 0);
    _baswim_entrypoint_9(player, 0.0f);
    func_8009BA9C(player, 0);
    func_80800030_bsbswim(player);
    func_800A0024(player);
    _baswim_entrypoint_6(player, 0);
}

void func_808014A0_bsbswim(Actor *player)
{
    s32 local_0;
    local_0 = 0;
    func_800A0024();
    if (player_inWater(player) == 0) {
        local_0 = 0x74;
    }
    if (func_8009CC68(player) == 0) {
        local_0 = 0x2B;
    }
    bs_setState(player, local_0);
}

void func_808014F8_bsbswim(s32 player)
{
    _baswim_entrypoint_6(player, 0x1);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_9(s32 index)
{
    return D_80801EF0_bsbswim[index];
}

// Plunge into the water from a fall: vertical speed from the fall height, then decelerate.
void func_80801538_bsbswim(PlayerState *player)
{
    void *anim_ctrl;
    f32 velocity;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_80800030_bsbswim(player);
    func_800A046C(player);
    velocity = func_800A3298(player);
    if (bs_getPreviousState(player) == 15)
        velocity = func_800F0E00(velocity, 600.0f);
    if (velocity > 80.0f) {
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, 0xEA);
        anctrl_setPlaybackType(anim_ctrl, 3);
        anctrl_setDuration(anim_ctrl, 1.2f);
        anctrl_setStart(anim_ctrl, 0.8204f);
        anctrl_start(anim_ctrl);
    } else {
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, 0x57);
        anctrl_setPlaybackType(anim_ctrl, 2);
        anctrl_setDuration(anim_ctrl, 1.2f);
        anctrl_setStart(anim_ctrl, 0.6412f);
        anctrl_start(anim_ctrl);
    }
    velocity = func_800F10B4(velocity, 40.0f, 1000.0f, -300.0f, -1200.0f);
    *(f32 *) ((u8 *) player + 0x178) = velocity;
    baphysics_set_vertical_velocity(player, velocity);
    func_8009FFD8(player, 1, 3, 3, 9);
    baphysics_set_type(player, 6);
}

void func_808016B8_bsbswim(u8 *player)
{
    s32 next_state;
    f32 pos[3];
    s32 hitbox;

    next_state = 0;
    func_8009C128(player, pos);
    pos[1] += 60.0f;
    hitbox = func_8009FBB0(player, pos, 20.0f);
    func_800BA930(hitbox, -30, -30, -30, 30, 30, 30);
    func_800BA22C(hitbox, 1);
    if (*(f32 *) (player + 0x178) < 0.0f) {
        *(f32 *) (player + 0x178) +=
            func_800F0E00(mlAbsF(*(f32 *) (player + 0x178)) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(player, *(f32 *) (player + 0x178));
    }
    if (player_isStable(player)) {
        next_state = 0x2D;
    }
    if (!player_inWater(player)) {
        next_state = 1;
    }
    if (baphysics_get_vertical_velocity(player) >= 0.0f) {
        next_state = 0x2D;
    }
    bs_setState(player, next_state);
}

void func_808017F8_bsbswim()
{
    func_80800104_bsbswim();
}

int bsbswim_entrypoint_10(s32 index)
{
    return D_80801F00_bsbswim[index];
}

// First-person look underwater.
int func_8080182C_bsbswim(Actor *player)
{
    func_80800030_bsbswim();
    _bsdrone_entrypoint_0(player);
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
}

int func_8080186C_bsbswim(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_badrone_entrypoint_30()) {
        next_state = 0xBB;
    }
    _bsdrone_entrypoint_1(player);
    bs_setState(player, next_state);
}

void func_808018B0_bsbswim(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_11(s32 index)
{
    return D_80801F10_bsbswim[index];
}

// Underwater split-up: switches to Banjo alone, then continues in the follow-up state.
s32 func_808018EC_bsbswim(s32 player)
{
    if (func_8009E6EC() == 0x11) {
        func_80099B94(player);
    } else {
        func_80099AA8(player);
    }
}

int func_80801930_bsbswim(u8 *player)
{
    if (player[0x165]) {
        _baduo_entrypoint_7(player, 3);
    }
    func_80800104_bsbswim(player);
}

void func_8080196C_bsbswim(PlayerState *player)
{
    func_80800030_bsbswim();
    baanim_playForDuration_onceSmooth(player, 0x131, 0x3FC00000);
    func_80800000_bsbswim(player);
    func_8009B94C(player, 0);
    func_8009BA9C(player, 0);
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    *((u8 *) player + 0x165) = 0;
}

void func_808019E0_bsbswim(PlayerState *player)
{
    s32 next_state;
    f32 pos[3];
    s32 hitbox;
    next_state = 0;
    if (baanim_isAt(player, 0.21f)) {
        func_800A0CF4(player, 0);
        _baduo_entrypoint_21(player);
        func_800A3410(player, 10);
        *(u8 *) ((u8 *) player + 0x165) = 1;
        func_8009C128(player, pos);
        pos[1] += 60.0f;
        hitbox = func_8009FBB0(player, pos, 70.0f);
        func_800BABB8(hitbox, pos, pos, 1.0f, D_80801F20_bsbswim);
        func_8009DF18(player, 0x4592, 1.0f, 0x55F0);
        next_state = 0xED;
    }
    bs_setState(player, next_state);
}

int bsbswim_entrypoint_12(s32 index)
{
    return D_80801F78_bsbswim[index];
}

// Passive idle with an interrupt filter.
void func_80801ACC_bsbswim(u8 *player)
{
    s32 interrupt_id;

    interrupt_id = func_8009E6EC();
    switch (interrupt_id) {
        case 0x71:
            *(u8 *) ((s8 *) player + 0x167) = 1U;
            func_8009E830(player, 2);
            return;
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x24:
        case 0x2D:
        case 0x2E:
        case 0x31:
        case 0x33:
        case 0x4E:
        case 0x51:
        case 0x52:
        case 0x68:
        case 0x6F:
            if (*(u8 *) ((s8 *) player + 0x167) == 0) {
                func_800F9BC4(player);
                func_80099B94(player);
            }
            return;
        default:
            func_80099B94(player);
    }
}

void func_80801B84_bsbswim(PlayerState *player)
{
    ((u8 *) player)[0x167] = 0;
    baanim_playForDuration_loopSmooth(player, 0x70, 2.0f);
    func_80800000_bsbswim(player);
    func_8009B94C(player, 0);
    _baswim_entrypoint_9(player, 0.0f);
    func_8009BA9C(player, 0);
    func_80800030_bsbswim(player);
    _baswim_entrypoint_6(player, 0);
    func_80091104(player, 0);
}

void func_80801C04_bsbswim(s32 unk_0)
{
}

s32 func_80801C0C_bsbswim(Actor *player)
{
    func_80091104(player, 1);
    _baswim_entrypoint_7(player, 1, 1);
    func_8009679C(player);
    func_80800104_bsbswim(player);
}

int bsbswim_entrypoint_13(s32 index)
{
    return D_80801F88_bsbswim[index];
}

// One-shot animation, back to idle when it ends or on swim input.
s32 func_80801C64_bsbswim(s32 player)
{
    func_80800030_bsbswim();
    baanim_playForDuration_once(player, 0x136, 0.6f);
    func_80800000_bsbswim(player);
    func_8009B94C(player, 0);
    func_8009BA9C(player, 0);
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
    func_800A0CF4(player, 1);
}

int func_80801CE4_bsbswim(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if ((baanim_isStopped() != 0) || (_baswim_entrypoint_3(player) != 0)) {
        next_state = 0x2B;
    }
    bs_setState(player, next_state);
}

void func_80801D30_bsbswim()
{
    func_80800104_bsbswim();
}

int bsbswim_entrypoint_14(s32 index)
{
    return D_80801F98_bsbswim[index];
}

// TU-NOTE: the overlay .data tables are defined here so IDO schedules the functions as in the original; values come from the ROM.
extern int func_80099B94();
extern int func_80099AA8();
extern void _bsdrone_entrypoint_3();
s32 D_80801E60_bsbswim[4] = {(u32) func_808001A8_bsbswim, (u32) func_808001C8_bsbswim,
                             (u32) func_80800288_bsbswim, (u32) func_80099B94};
s32 D_80801E70_bsbswim[4] = {(u32) func_808005F4_bsbswim, (u32) func_8080039C_bsbswim,
                             (u32) func_80800440_bsbswim, (u32) func_80099B94};
s32 D_80801E80_bsbswim[4] = {(u32) func_808008CC_bsbswim, (u32) func_80800634_bsbswim,
                             (u32) func_808006DC_bsbswim, (u32) func_80099B94};
s32 D_80801E90_bsbswim[4] = {(u32) func_80800AD0_bsbswim, (u32) func_8080090C_bsbswim,
                             (u32) func_8080097C_bsbswim, (u32) func_80099B94};
s32 D_80801EA0_bsbswim[4] = {(u32) func_80800CE4_bsbswim, (u32) func_80800B10_bsbswim,
                             (u32) func_80800C0C_bsbswim, (u32) func_80099AA8};
s32 D_80801EB0_bsbswim[4] = {(u32) func_80800D30_bsbswim, (u32) func_80800D58_bsbswim,
                             (u32) func_80800D98_bsbswim, (u32) func_80099AA8};
s32 D_80801EC0_bsbswim[4] = {(u32) func_80800DFC_bsbswim, (u32) func_80800E30_bsbswim,
                             (u32) func_80800E7C_bsbswim, (u32) func_80099AA8};
s32 D_80801ED0_bsbswim[4] = {(u32) func_80801084_bsbswim, (u32) func_80800EC8_bsbswim,
                             (u32) func_80800F64_bsbswim, (u32) func_80099B94};
s32 D_80801EE0_bsbswim[4] = {(u32) func_808013C4_bsbswim, (u32) func_808010B8_bsbswim,
                             (u32) func_808011C0_bsbswim, (u32) func_80099AA8};
s32 D_80801EF0_bsbswim[4] = {(u32) func_808014F8_bsbswim, (u32) func_80801428_bsbswim,
                             (u32) func_808014A0_bsbswim, (u32) func_80099B94};
s32 D_80801F00_bsbswim[4] = {(u32) func_808017F8_bsbswim, (u32) func_80801538_bsbswim,
                             (u32) func_808016B8_bsbswim, (u32) func_80099B94};
s32 D_80801F10_bsbswim[4] = {(u32) func_808018B0_bsbswim, (u32) func_8080182C_bsbswim,
                             (u32) func_8080186C_bsbswim, (u32) _bsdrone_entrypoint_3};
u8 D_80801F20_bsbswim[88] = {
    0x0,  0xC,  0x0,  0x23, 0x0,  0x2B, 0x2,  0x0,  0x2,  0x80, 0x0,  0x2D, 0x0,  0x14, 0x0,
    0x28, 0x0,  0x22, 0x0,  0x14, 0x0,  0x1E, 0x0,  0x23, 0x0,  0x30, 0x4,  0x1A, 0x0,  0xC,
    0x0,  0x2D, 0x0,  0x2B, 0x1,  0x80, 0x2,  0x0,  0x0,  0x2D, 0x0,  0x32, 0x0,  0x46, 0x0,
    0x22, 0x0,  0x21, 0x0,  0x26, 0x0,  0x2E, 0x0,  0x3A, 0x6,  0x1A, 0x0,  0xC,  0x0,  0x37,
    0x0,  0x2B, 0x1,  0x0,  0x1,  0x80, 0x0,  0x2D, 0x0,  0x46, 0x0,  0x50, 0x0,  0x22, 0x0,
    0x28, 0x0,  0x35, 0x0,  0x40, 0x0,  0x4C, 0x4,  0x1A, 0x0,  0x0,  0x0,  0x0};
s32 D_80801F78_bsbswim[4] = {(u32) func_80801930_bsbswim, (u32) func_8080196C_bsbswim,
                             (u32) func_808019E0_bsbswim, (u32) func_808018EC_bsbswim};
s32 D_80801F88_bsbswim[4] = {(u32) func_80801C0C_bsbswim, (u32) func_80801B84_bsbswim,
                             (u32) func_80801C04_bsbswim, (u32) func_80801ACC_bsbswim};
s32 D_80801F98_bsbswim[6] = {(u32) func_80801D30_bsbswim,
                             (u32) func_80801C64_bsbswim,
                             (u32) func_80801CE4_bsbswim,
                             (u32) func_80099B94,
                             0x0,
                             0x0};
