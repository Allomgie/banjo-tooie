#include "common.h"
#include "overlays/ba/playerstate.h"

extern u8 D_80801D20_bsbfly[];
extern f32 func_800DC178(f32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void *baanim_getAnimCtrlPtr();
extern s32 anctrl_isAt(void *, f32);
extern void anctrl_setDuration(void *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 D_80801D48_bsbfly[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern s32 D_80801D58_bsbfly[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void _bafly_entrypoint_1(PlayerState *, void *, f32 *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009DF94(PlayerState *, s32, f32, s32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 bastick_getX(PlayerState *);
extern f32 bastick_getY(PlayerState *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 D_80801D68_bsbfly[];
extern void func_8009BB24(PlayerState *, f32 *);
extern void baanim_playForDuration_onceSmoothStartingAt(PlayerState *, s32, f32, f32);
extern f32 func_800D8FF8(void);
extern s32 D_80801D78_bsbfly[];
extern void _badust_entrypoint_5(s32, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009D820(PlayerState *, f32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern void func_8009D3A8();
extern s32 D_80801D88_bsbfly[];
extern s32 D_80801D98_bsbfly[];
extern s32 D_80801DA8_bsbfly[];
extern void _bafly_entrypoint_16(s32, s32, f32);
extern s32 D_80801DB8_bsbfly[];
extern s32 D_80801DC8_bsbfly[];
extern s32 D_80801DD8_bsbfly[];
extern void _bafly_entrypoint_20();
extern void _bafly_entrypoint_21();
extern void _bafly_entrypoint_7();
extern void _bafly_entrypoint_9();
extern void _chusefeather_entrypoint_1();
typedef struct {
    f32 cooldown;
    u8 pad_4[0x18];
    u8 flap_queued;
} FlyState561;
extern void _bafly_entrypoint_10(PlayerState *, f32, f32);
extern void _bafly_entrypoint_8(PlayerState *, f32, f32, f32, f32, f32, f32, f32);
extern void _baboost_entrypoint_2(PlayerState *, f32);
extern f32 func_800136E4(f32);
extern f32 func_8009BFD8(PlayerState *);
extern void func_8009DFD4(PlayerState *, s32, f32, f32, s32, s32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 mlAbsF(f32);
extern void func_8009DDDC();
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _bafly_entrypoint_6(PlayerState *, f32);
extern void anctrl_reset(void *);
extern void func_8008B1C8(void *, f32);
extern void func_80093360(PlayerState *, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern f32 anctrl_getAnimTimer(void *);

void func_80800000_bsbfly(PlayerState *player)
{
    f32 pos[3];
    func_8009C128(player, pos);
    pos[0] += func_800DC178(-30.0f, 30.0f);
    pos[1] += 50.0f + func_800DC178(0.0f, 30.0f);
    pos[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(pos, 0, 1.0f, 1, D_80801D20_bsbfly);
}

void func_808000AC_bsbfly(s32 player)
{
    func_80093360(player, 6e+01f);
    yaw_setUpdateType(player, 3);
    yaw_setVelocityBounded(player, 0x43FA0000, 0x40000000);
    baroll_setAngularVelocity(player, 0x43FA0000, 0x40000000);
    _bafly_entrypoint_20(player);
    func_800959C8(player, 0x42820000, 0x42480000);
    func_800961AC(player, 4);
}

int func_80800128_bsbfly(actor)
s32 actor;
{
    s32 player;
    // Matching: `| 0` on the copy is needed for the match.
    player = actor | 0;
    if (!func_8009E77C(player, 9)) {
        _bastatemem_entrypoint_0(player, 0x20);
        _bafly_entrypoint_5(player);
        func_808000AC_bsbfly(player);
        _baboost_entrypoint_3(player);
        _baboost_entrypoint_4(player, 1);
    }
}

int func_80800188_bsbfly(player)
Actor *player;
{
    if (!func_8009E74C(player, 9)) {
        _bafly_entrypoint_4(player);
        _bastatemem_entrypoint_1(player);
        baphysics_reset_gravity(player);
        baphysics_reset_terminal_velocity(player);
        func_800A0CF4(player, 0);
        // Matching: the chain of `& 0xFFFFFFFFFFFFFFFF` is needed for the match.
        func_80093360(player,
                      ((0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
        func_800A042C(player);
        yaw_setUpdateType(player, 1);
        func_800A4E30(player);
        func_80095A40(player);
        func_800961AC(player, 1);
        _baboost_entrypoint_4(player, 0);
        baflag_clear(player, 0x2F);
        baflag_clear(player, 0x30);
    }
}

void func_80800248_bsbfly(PlayerState *player)
{
    baanim_playForDuration_once(player, 0x45, 1.4f);
    func_8009FFD8(player, 1, 1, 3, 6);
    if (bastick_distance(player) != 0.0f)
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_8009BA9C(player, 0);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    baphysics_set_gravity(player, -1200.0f);
    func_800A0CF4(player, 1);
    func_8009D874(player);
    player->unk160.word = 0;
    player->unk15C.word = 0;
}

void func_80800320_bsbfly(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (!player->unk160.word) {
        if (anctrl_isAt(anim_ctrl, 0.2416f)) {
            anctrl_setDuration(anim_ctrl, 2.4f);
            baphysics_set_vertical_velocity(player, 1600.0f);
            func_8009DE38(player, 0x406, 0.7f);
            player->unk160.word = 1;
        }
    } else {
        func_80800000_bsbfly(player);
        if (baphysics_get_vertical_velocity(player) < 0.0f)
            next_state = 0x24;
    }
    bs_setState(player, next_state);
}

s32 func_808003E0_bsbfly(Actor *this)
{
    func_800C6DA0(0x44);
    func_800A0CF4(this, 0);
    func_800A4E30(this);
}

int bsbfly_entrypoint_0(s32 idx)
{
    return D_80801D48_bsbfly[idx];
}

void func_80801BB4_bsbfly();

void func_8080042C_bsbfly(s32 player)
{
    func_8009E6EC();
    func_80801BB4_bsbfly(player);
}

void func_80800454_bsbfly(Actor *player)
{
    s32 next_state;
    baflag_clear(player, 0x2F);
    baflag_clear(player, 0x30);
    next_state = bs_getNextState(player);
    if ((((next_state == 0x18) || (next_state == 0x2A)) || (next_state == 0x91)) &&
        (_bafpctrl_entrypoint_4(player) == 3)) {
        baflag_set(player, 0x2F);
        if (_bafpctrl_entrypoint_5(player) != 0) {
            baflag_set(player, 0x30);
        }
    }
    _bafpctrl_entrypoint_17(player);
    // Matching: the 64-bit cast of 0 is needed for the match.
    _bafly_entrypoint_6(player, (unsigned long long) 0);
    _bafly_entrypoint_7(player, 0);
    func_80800188_bsbfly(player);
}

void func_8080050C_bsbfly(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, 0x38, 0.62f);
    func_8009FFD8(player, 1, 1, 3, 3);
    if (baflag_isTrue(player, 9))
        baphysics_set_target_horizontal_velocity(player, 0);
    else
        baphysics_set_target_horizontal_velocity(player, 600.0f);
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_800A0CF4(player, 1);
    baphysics_set_gravity(player, -300.0f);
    baphysics_set_terminal_velocity(player, -99.9f);
    func_800A4DA4(player, 3);
    func_80800128_bsbfly(player);
    *(f32 *) player->kazfly = 1.0f;
    player->unk160.word = 0;
    ((u8 *) player->kazfly)[0x1C] = 0;
    _bafly_entrypoint_19(player);
}

void func_80800624_bsbfly(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    u8 unk_0;
    s32 boost;
    s32 feather_used;
    f32 unk_1;
    f32 unk_2;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _bafly_entrypoint_20(player);
    _bafly_entrypoint_9(player);
    _bafly_entrypoint_10(player, 300.0f, 80.0f);
    _bafly_entrypoint_11(player);
    feather_used = 0;
    if (bakey_pressed(player, 8)) {
        ((FlyState561 *) player->kazfly)->flap_queued = 1;
    }
    if (((FlyState561 *) player->kazfly)->flap_queued && func_8001211C() % 3 == 0) {
        ((FlyState561 *) player->kazfly)->flap_queued = 0;
        feather_used = _bafly_entrypoint_12(player);
    }
    if (feather_used || player->unk15C.word) {
        if (feather_used) {
            anctrl_setDuration(anim_ctrl, 0.3f);
            _chusefeather_entrypoint_1(player->unk184, 0);
        }
        if (player->unk15C.word) {
            player->unk15C.word = 0;
            _baboost_entrypoint_2(player, 0.35f);
        } else {
            _baboost_entrypoint_2(player, 1.0f);
        }
    }
    boost = _baboost_entrypoint_1(player);
    _bafly_entrypoint_7(player, 0);
    switch (player->unk160.word) {
        case 0:
            if (boost) {
                player->unk160.word = 1;
            }
            break;
        case 1:
            _bafly_entrypoint_7(player, 1);
            unk_1 = func_800136E4(func_8009BFD8(player) - 30.0f);
            unk_2 = unk_1;
            if (unk_1 > 80.0f && unk_1 < 300.0f) {
                unk_2 = 300.0f;
            }
            func_8009BF5C(player, unk_2);
            _bafly_entrypoint_21(player);
            if (boost) {
                baphysics_set_vertical_velocity(player, (f32) boost * 400.0f);
            }
            if (!boost) {
                anctrl_setDuration(anim_ctrl, 0.62f);
                _bafly_entrypoint_20(player);
                player->unk160.word = 0;
            }
    }
    if (anctrl_isAt(anim_ctrl, 0.1358f)) {
        func_8009DFD4(player, 0x3FF, 0.6f, 0.7f, 10000, 12000);
    }
    _bafly_entrypoint_8(player, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, -700.0f, -1000.0f);
    if (_bafpctrl_entrypoint_4(player) != 3 && bainput_should_beak_bust(player)) {
        next_state = 0xF;
    }
    ((FlyState561 *) player->kazfly)->cooldown =
        func_800F0E00(((FlyState561 *) player->kazfly)->cooldown - func_800D8FF8(), 0.0f);
    if (((FlyState561 *) player->kazfly)->cooldown == 0.0f && bakey_pressed(player, 9) &&
        func_8008D0E0(player) && _bafly_entrypoint_12(player)) {
        next_state = 0x2A;
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    if (_bafly_entrypoint_2(player)) {
        next_state = 1;
    }
    _baboost_entrypoint_5(player);
    bs_setState(player, next_state);
}

int bsbfly_entrypoint_1(s32 idx)
{
    return D_80801D58_bsbfly[idx];
}

void func_808009D0_bsbfly(u8 *player)
{
    // Matching: unused stack padding is needed for the match.
    s8 _sfpad[8];
    s32 pos;

    func_8009C128(player, &pos);
    func_800EF04C(&pos, *(s32 *) ((s8 *) player + 0x188) + 0x10);
    func_800A34AC(player, &pos);
    func_8009DF58(player, 0x40D, 0x3F800000);
}

// Beak Bomb dive: sets up the given phase.
void func_80800A24_bsbfly(PlayerState *player, s32 phase)
{
    Vec3f aim;
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    switch (phase) {
        case 0:
            func_8009E0DC(player);
            baflag_clear(player, 0x1C);
            break;
        case 1:
            baanim_playForDuration_onceSmooth(player, 0x43, 1.0f);
            func_8009FFD8(player, 1, 1, 3, 7);
            _bafly_entrypoint_1(player, (u8 *) player->kazfly + 0x10, aim.f, 4200.0f);
            yaw_setIdeal(player, aim.f[1] + 180.0f);
            func_8009BF5C(player, aim.f[0]);
            baroll_setIdeal(player, 0.0f);
            func_8009BA9C(player, (u8 *) player->kazfly + 0x10);
            func_800A0CF4(player, 1);
            func_800A4DA4(player, 4);
            _ncbadive_entrypoint_4(func_800A4CA8(player), (u8 *) player->kazfly + 0x10);
            _ncbafly_entrypoint_5(func_800A4CA8(player), 1);
            func_8009DF94(player, 0x439, 1.0f, 28000);
            baflag_clear(player, 0x1C);
            func_8009C128(player, (u8 *) player->kazfly + 4);
            _chusefeather_entrypoint_1(player->unk184, 0);
            break;
        case 2:
            baphysics_set_type(player, 8);
            func_800A4DA4(player, 4);
            _ncbadive_entrypoint_4(func_800A4CA8(player), (u8 *) player->kazfly + 0x10);
            anctrl_setDuration(anim_ctrl, 0.05f);
            func_8009DF94(player, 0x4437, 1.3f, 32767);
            baflag_set(player, 0x1C);
            _batimer_set(player, 1, 0.0001f);
        case 3:
            break;
    }
    player->unk160.word = phase;
}

void func_80800C38_bsbfly(PlayerState *player)
{
    f32 stick_vec[3];
    f32 aim_dir[3];
    f32 cam_angles[3];
    func_800EE7F8(aim_dir, (f32 *) ((u8 *) player->kazfly + 0x10));
    func_800CA9D8(func_800A4C48(player), cam_angles);
    func_800EFA4C(stick_vec, bastick_getX(player) * 1000.0f, 0.0f, 0.0f);
    func_800EF8BC(stick_vec, stick_vec, cam_angles[0]);
    func_800EF934(stick_vec, stick_vec, cam_angles[1]);
    func_800EF04C(aim_dir, stick_vec);
    func_800EFA4C(stick_vec, 0.0f, -bastick_getY(player) * 1000.0f, 0.0f);
    func_800EF8BC(stick_vec, stick_vec, cam_angles[0]);
    func_800EF934(stick_vec, stick_vec, cam_angles[1]);
    func_800EF04C(aim_dir, stick_vec);
    func_8009BA9C(player, aim_dir);
}

void func_80800D50_bsbfly(Actor *player)
{
    func_80800128_bsbfly();
    *(s32 *) ((char *) player + 0x160) = 0;
    func_80800A24_bsbfly(player, 1);
}

s32 func_80800D80_bsbfly(PlayerState *player, s32 next_state)
{
    f32 dot;
    f32 normal[3];
    f32 dive_dir[3];
    s32 unk_0;
    s32 stable;
    if (player_inWater(player)) {
        next_state = 0x4C;
    }
    stable = player_isStable(player);
    if (!func_8009650C(player) && !stable) {
        return next_state;
    }
    if (stable) {
        func_800963C0(player, normal);
        unk_0 = func_80096628(player);
    } else {
        func_80096440(player, normal);
        unk_0 = func_80096434(player);
    }
    func_800EE7F8(dive_dir, *(u8 **) ((u8 *) player + 0x188) + 0x10);
    func_800EF2A0(dive_dir);
    dot = mlAbsF(func_800EEAA4(normal, dive_dir));
    if (baflag_isTrue(player, 8) || (unk_0 & 0x80)) {
        func_808009D0_bsbfly(player);
        next_state = 0x18;
    } else if (dot > 0.4f) {
        if (normal[1] < 0.65f) {
            func_808009D0_bsbfly(player);
            func_800A17A8(player, -1);
            next_state = func_800A1718(player) ? 0x59 : 0x41;
        } else {
            next_state = 0x58;
        }
    } else if (stable) {
        next_state = 0x58;
    }
    return next_state;
}

void func_80800F10_bsbfly(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    Vec3f delta;
    s32 phase;
    f32 dist_sq;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _bafly_entrypoint_11(player);
    func_8009DDDC(player);
    phase = player->unk160.word;
    switch (phase) {
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.6905f)) {
                func_80800A24_bsbfly(player, 2);
            }
            break;
        case 2:
            func_80800C38_bsbfly(player);
            if (anctrl_isStopped(anim_ctrl)) {
                anctrl_setIndex(anim_ctrl, 0x47);
                anctrl_setDuration(anim_ctrl, 0.3f);
                anctrl_setPlaybackType(anim_ctrl, 2);
                anctrl_start(anim_ctrl);
            }
            func_8009C128(player, delta.f);
            func_800EF3DC(delta.f, (u8 *) player->kazfly + 4);
            dist_sq = func_800EEFD4(delta.f);
            _bafly_entrypoint_6(player, func_800F10B4(dist_sq, 0.0f, 16000000.0f, 0.2f, 0.7f));
            dist_sq = func_800EEFD4(delta.f);
            if (dist_sq > 16000000.0f) {
                if (bakey_held(player, 9)) {
                    func_80800A24_bsbfly(player, 3);
                } else {
                    next_state = 0x57;
                }
            }
            func_80800000_bsbfly(player);
            next_state = func_80800D80_bsbfly(player, next_state);
            break;
        case 3:
            func_80800C38_bsbfly(player);
            if (bakey_released(player, 9)) {
                next_state = 0x57;
            } else if (_batimer_decrement(player, 1)) {
                if (_bafly_entrypoint_12(player)) {
                    _chusefeather_entrypoint_1(player->unk184, 0);
                    _batimer_set(player, 1, 1.0f);
                } else {
                    next_state = 0x57;
                }
            }
            func_80800000_bsbfly(player);
            next_state = func_80800D80_bsbfly(player, next_state);
    }
    bs_setState(player, next_state);
}

void func_80801138_bsbfly(s32 player)
{
    func_80800A24_bsbfly(player, 0);
    func_80800188_bsbfly(player);
}

int bsbfly_entrypoint_2(s32 idx)
{
    return D_80801D68_bsbfly[idx];
}

s32 func_80801178_bsbfly(s32 player)
{
    func_8009E0DC(player);
    func_8009E100(player);
    if (func_8009E74C(player, 9) != 0) {
        func_808000AC_bsbfly(player);
    }
    {
        s32 next_state = bs_getNextState(player);
        if ((next_state == 0x20) || (next_state == 0x24) || (next_state == 0x2D)) {
            // Matching: the extra temporaries are needed for the match.
            s32 _t0 = player;
            s32 _t1 = 0x3EA;
            s32 _t2 = 0x3F800000;
            func_8009DBF0(_t0, _t1, _t2);
        }
    }
    func_80800188_bsbfly(player);
    func_800A0CF4(player, 0);
}

void func_80801208_bsbfly(PlayerState *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    func_8008B1C8(anim_ctrl, 0.3f);
    anctrl_setIndex(anim_ctrl, 0xCC);
    anctrl_setDuration(anim_ctrl, 0.38f);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 3);
    func_800A0CF4(player, 1);
    func_80800128_bsbfly((s32) player);
    func_80095A40(player);
    func_800961AC(player, 1);
    baroll_setIdeal(player, 0.0f);
    func_8009BF5C(player, 0.0f);
    baphysics_reset_gravity(player);
    baphysics_reset_terminal_velocity(player);
    func_80093360(player, 0.0f);
    func_8009DF94(player, 0x420, 1.0f, 0x7FFF);
    func_8009DB04(player, 0x444, 1.0f, 0x7FFF);
    *(f32 *) player->kazfly = 0.35f;
    player->unk160.word = 0;
}

void func_80801334_bsbfly(PlayerState *player)
{
    s32 next_state = 0;
    f32 unk_0[3];
    func_8009BB24(player, unk_0);
    switch (player->unk160.word) {
        case 0:
            if (func_8008DF8C(player, 0x5A)) {
                baanim_playForDuration_onceSmoothStartingAt(player, 8, 2.0f, 0.6667f);
                player->unk160.word = 1;
            }
        case 1:
            break;
    }
    *(f32 *) player->kazfly -= func_800D8FF8();
    if (*(f32 *) player->kazfly < 0.0f) {
        player->unk15C.word = 1;
        next_state = 0x24;
    }
    if (bainput_should_beak_bust(player))
        next_state = 0xF;
    if (player_isStable(player)) {
        func_8009FE58(player);
        next_state = 0x20;
    }
    if (player_inWater(player))
        next_state = 0x2D;
    bs_setState(player, next_state);
}

int bsbfly_entrypoint_3(s32 idx)
{
    return D_80801D78_bsbfly[idx];
}

void func_8080145C_bsbfly(s32 player)
{
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        _badust_entrypoint_5(player, angle, 230.0f);
    }
}

void func_808014E8_bsbfly(PlayerState *player)
{
    baanim_playForDuration_onceSmooth(player, 0x3E, 1.4f);
    func_8009FFD8(player, 1, 1, 3, 3);
    func_800A0CF4(player, 1);
    func_8009DF18(player, 0x417, 0.8f, 0x7FFF);
    func_8009D820(player, 1.8f);
    _bamotor_entrypoint_1(player, 1.0f, 0.5f, 0.5f);
    func_800A17A8(player, -1);
    if (!func_800A1718(player))
        _basudie_entrypoint_1(player);
    func_8080145C_bsbfly(player);
    func_8008E944(player);
    *(s32 *) ((u8 *) player + 0x160) = 0;
}

void func_808015C4_bsbfly(player) PlayerState *player;
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (anctrl_isAt(anim_ctrl, 0.3659f)) {
        func_8009DF18(player, 0x417, 1.0f, 0x36B0);
        func_8009DF18(player, 0x4454, 1.0f, 0x6D60);
    }
    if (anctrl_isAt(anim_ctrl, 0.6862f)) {
        func_8009DF18(player, 0x417, 0.8f, 0x4650);
        func_8009DF18(player, 0x427, 1.0f, 0x55F0);
    }
    if (anctrl_isAt(anim_ctrl, 0.92f)) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    }
    if (anctrl_getAnimTimer(anim_ctrl) < 0.8f) {
        _badust_entrypoint_9(player);
    }
}

void func_808016B4_bsbfly(u8 *player)
{
    s32 next_state;
    s32 anim_ctrl;
    s32 phase;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_8009D3A8(player, 0);
    phase = *(s32 *) ((s8 *) player + 0x160);
    switch (phase) {
        case 0:
            func_808015C4_bsbfly(player);
            if (anctrl_isAt(anim_ctrl, 0.2f) != 0) {
                if (func_800F8B64() != 0) {
                    func_800A0180(player);
                    func_800A4DFC(player, 0xA);
                    _ncbadie_entrypoint_3(func_800A4CA8(player), 0x41F00000);
                    _basudie_entrypoint_1(player);
                    _batimer_set(player, 0, 3.2f);
                    *(s32 *) ((s8 *) player + 0x160) = 2;
                }
            } else if (anctrl_isAt(anim_ctrl, 0.92f) != 0) {
                baanim_playForDuration_onceSmooth(player, 0xD2, 2.25f);
                *(s32 *) ((s8 *) player + 0x160) = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.63f) != 0) {
                next_state = 0x20;
            }
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = 1;
            }
            if (func_8008DD04(player) != 0) {
                next_state = 0x2F;
            }
            break;
        case 2:
            func_808015C4_bsbfly(player);
            if (_batimer_decrement(player, 0) != 0) {
                _basudie_entrypoint_0(player);
            }
    }
    bs_setState(player, next_state);
}

s32 func_8080183C_bsbfly(Actor *this)
{
    func_800A4E30(this);
    func_800A042C(this);
    func_800A0CF4(this, 0);
    func_8008E95C(this);
}

int bsbfly_entrypoint_4(s32 idx)
{
    return D_80801D88_bsbfly[idx];
}

int func_8080188C_bsbfly(Actor *actor)
{
    func_80800128_bsbfly(actor);
    _bafly_entrypoint_13(actor, 0, 0xD3, 0x3F99999A);
    func_800A0CF4(actor, 1);
}

int func_808018D0_bsbfly(int player)
{
    _bafly_entrypoint_14(player, 0x24, 2);
}

s32 func_808018F4_bsbfly(Actor *this)
{
    func_800A0CF4(this, 0);
    _bafly_entrypoint_15(this);
    func_80800188_bsbfly(this);
}

int bsbfly_entrypoint_5(s32 idx)
{
    return D_80801D98_bsbfly[idx];
}

int func_8080193C_bsbfly(Actor *actor)
{
    func_80800128_bsbfly(actor);
    _bafly_entrypoint_13(actor, 1, 0xD3, 0x3F99999A);
    func_800A0CF4(actor, 1);
}

void func_80801980_bsbfly(int player)
{
    _bafly_entrypoint_14(player, 0x24, 2);
}

s32 func_808019A4_bsbfly(Actor *this)
{
    func_800A0CF4(this, 0);
    _bafly_entrypoint_15(this);
    func_80800188_bsbfly(this);
}

int bsbfly_entrypoint_6(s32 idx)
{
    return D_80801DA8_bsbfly[idx];
}

int func_808019EC_bsbfly(s32 player)
{
    func_80800128_bsbfly();
    _bafly_entrypoint_16(player, 269, 1.0f);
}

int func_80801A1C_bsbfly(Actor *actor)
{
    _bafly_entrypoint_17(actor, 0x24, 0x20, (char *) actor + 0x15C);
}

void func_80801A44_bsbfly(s32 player)
{
    _bafly_entrypoint_18();
    func_80800188_bsbfly(player);
}

int bsbfly_entrypoint_7(s32 idx)
{
    return D_80801DB8_bsbfly[idx];
}

int func_80801A80_bsbfly(Actor *actor)
{
    s32 player;
    // Matching: copy through a local is needed for the match.
    player = actor;
    func_80800128_bsbfly();
    baanim_playForDuration_loopSmooth(player | 0, 0x38, 0.62f);
    func_8009FFD8(player | 0, 1, 1, 3, 7);
    func_800A0CF4(player | 0, 1);
    func_800A0024(player | 0);
}

int func_80801AEC_bsbfly(Actor *actor)
{
    s32 next_state;
    next_state = 0;
    if (anctrl_isAt(baanim_getAnimCtrlPtr(actor), 0.1358f) != 0) {
        func_8009DEC0(actor, 0x3FF, 0x3F19999A, 0x3F333333, 10000, 12000);
    }
    if (!func_8009CC68(actor)) {
        next_state = 0x24;
    }
    func_800A0024(actor);
    bs_setState(actor, next_state);
}

void func_80801B80_bsbfly()
{
    func_80800188_bsbfly();
}

int bsbfly_entrypoint_8(s32 idx)
{
    return D_80801DC8_bsbfly[idx];
}

void func_80801BB4_bsbfly(Actor *actor)
{
    s32 player;
    // Matching: copy through an s32 local is needed for the match.
    player = (s32) actor;
    switch (func_8009E6EC()) {
        case 9:
            func_8009E830(player, 2);
            baflag_set(player, 7);
            func_800A046C(player);
            return;

        case 0x18:
            if (bs_getCurrentState(player) == 0x24) {
                _baboost_entrypoint_2(player, 6.0f);
                func_8009E830(player, 2);
            }
            return;

        default:
            func_80099B94(player);
    }
}

void func_80801C58_bsbfly(s32 player)
{
    func_80800128_bsbfly();
    _bsdrone_entrypoint_0(player);
    if (_badrone_entrypoint_3(player) == 0xE) {
        baphysics_set_type(player, 7);
    }
}

void func_80801C9C_bsbfly(PlayerState *self)
{
    _bsdrone_entrypoint_1(self);
}

void func_80801CBC_bsbfly(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800188_bsbfly(player);
}

int bsbfly_entrypoint_9(s32 idx)
{
    return D_80801DD8_bsbfly[idx];
}

// TU-NOTE: the .data tables of this overlay are defined at the end of this file in C.
// They hold pointers to functions of this file; IDO's assembler schedules some of these
// functions differently unless the tables are in the same unit. Values are from the ROM.
extern void func_80099AA8();
extern int func_80099B94();
extern void _bsdrone_entrypoint_3();
u8 D_80801D20_bsbfly[40] = {0x0, 0x1D, 0x9, 0xE4, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99,
                            0x0, 0x22, 0x0, 0x66, 0x0, 0x59, 0x0, 0x19, 0x0, 0x19,
                            0x0, 0x27, 0x1, 0x90, 0x1, 0x90, 0x3, 0x20, 0x3, 0x20,
                            0x0, 0x2B, 0x0, 0x80, 0x0, 0x80, 0x0, 0x0,  0x0, 0x0};
s32 D_80801D48_bsbfly[4] = {(u32) func_808003E0_bsbfly, (u32) func_80800248_bsbfly,
                            (u32) func_80800320_bsbfly, (u32) func_80801BB4_bsbfly};
s32 D_80801D58_bsbfly[4] = {(u32) func_80800454_bsbfly, (u32) func_8080050C_bsbfly,
                            (u32) func_80800624_bsbfly, (u32) func_8080042C_bsbfly};
s32 D_80801D68_bsbfly[4] = {(u32) func_80801138_bsbfly, (u32) func_80800D50_bsbfly,
                            (u32) func_80800F10_bsbfly, (u32) func_80801BB4_bsbfly};
s32 D_80801D78_bsbfly[4] = {(u32) func_80801178_bsbfly, (u32) func_80801208_bsbfly,
                            (u32) func_80801334_bsbfly, (u32) func_80801BB4_bsbfly};
s32 D_80801D88_bsbfly[4] = {(u32) func_8080183C_bsbfly, (u32) func_808014E8_bsbfly,
                            (u32) func_808016B4_bsbfly, (u32) func_80099AA8};
s32 D_80801D98_bsbfly[4] = {(u32) func_808018F4_bsbfly, (u32) func_8080188C_bsbfly,
                            (u32) func_808018D0_bsbfly, (u32) func_80801BB4_bsbfly};
s32 D_80801DA8_bsbfly[4] = {(u32) func_808019A4_bsbfly, (u32) func_8080193C_bsbfly,
                            (u32) func_80801980_bsbfly, (u32) func_80801BB4_bsbfly};
s32 D_80801DB8_bsbfly[4] = {(u32) func_80801A44_bsbfly, (u32) func_808019EC_bsbfly,
                            (u32) func_80801A1C_bsbfly, (u32) func_80099B94};
s32 D_80801DC8_bsbfly[4] = {(u32) func_80801B80_bsbfly, (u32) func_80801A80_bsbfly,
                            (u32) func_80801AEC_bsbfly, (u32) func_80099B94};
s32 D_80801DD8_bsbfly[6] = {(u32) func_80801CBC_bsbfly,
                            (u32) func_80801C58_bsbfly,
                            (u32) func_80801C9C_bsbfly,
                            (u32) _bsdrone_entrypoint_3,
                            0x0,
                            0x0};
