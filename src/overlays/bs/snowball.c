// Snowball transformation states (Hailfire Peaks): idle, roll, jump, fall, death, drone, spin,
// bounce and rest; enter/exit hooks update the size via the ba snowball code.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern f32 _basnowball_entrypoint_3(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F13C4(f32, f32);
extern void func_8008C990(PlayerState *, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void _basnowball_entrypoint_12(void *);
extern void _basnowball_entrypoint_8(void *, s32);
extern void _basnowball_entrypoint_9(void *, f32);
extern s32 func_800A3274(void);
extern s32 D_80800F30_bssnowball[];
extern s32 D_80800F84_bssnowball[];
extern s32 D_80801028_bssnowball[];
extern s32 D_80801054_bssnowball[];
extern s32 D_80801064_bssnowball[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern int D_80801074_bssnowball[];
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void baphysics_reset_gravity(s32);
extern s32 D_80801084_bssnowball[];
extern s32 D_80801094_bssnowball[];
extern s32 D_808010A4_bssnowball[];
extern s32 D_808010B4_bssnowball[];
extern s32 _bsrest_entrypoint_20(s32);
extern s32 _bsrest_entrypoint_13(s32);
extern void bs_setState(s32, s32);
extern s32 D_808010C4_bssnowball[];
extern s32 D_808010D4_bssnowball[];
extern f32 func_8009BB5C(PlayerState *);
extern void func_8009DBB0(PlayerState *, s32, f32, f32, s32);

extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);

f32 func_80800000_bssnowball(PlayerState *player)
{
    f32 unk_0;
    f32 unk_1;

    unk_0 = func_800F10B4(_basnowball_entrypoint_3(player), 0.0f, 360.0f, 0.0f, 1.0f);
    unk_1 = func_800F13C4(unk_0, 1.0f);
    func_8008C990(player, unk_1);
    return unk_1;
}

void func_80800064_bssnowball(PlayerState *player, s32 allow_boost)
{
    f32 stick_pos;
    stick_pos = bastick_getZonePosition(player);
    if (allow_boost && bakey_held(player, 9)) {
        baphysics_set_target_horizontal_velocity(player, 1400.0f);
        _basnowball_entrypoint_7(player);
    } else if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 700.0f));
    }
}

s32 func_8080010C_bssnowball(s32 player, s32 next_state)
{
    if (bainput_should_enter_first_person()) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (bakey_pressed(player, 8)) {
        next_state = 0x17F;
    }
    return next_state;
}

int func_80800164_bssnowball(Actor *player)
{
    yaw_setUpdateType(player, 0x3);
    yaw_setVelocityBounded(player, 0x43960000, 0x40C00000);
}

void bssnowball_entrypoint_0(player)
{
    if (!func_8009E74C(player, 0x16)) {
        func_800947EC(player, 1, 0);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        func_8009C000(player);
        baroll_resetAngularVelocity(player);
        bastick_popZone(player);
        baflag_clear(player, 3);
        baflag_clear(player, 4);
        _basnowball_entrypoint_1(player);
        func_80092864(player, 1.0f);
    }
}

void bssnowball_entrypoint_1(player) u8 *player;
{
    if (func_8009E77C(player, 0x16) == 0) {
        _basnowball_entrypoint_2(player);
        func_8009BFE4(player, 0x447A0000, 0x41400000);
        baroll_setAngularVelocity(player, 0x447A0000, 0x41400000);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0x3DF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        baflag_set(player, 3);
        baflag_set(player, 4);
        func_800947EC(player, 1, 1);
        ((u8 *) player)[0x165] = 0;
        func_80092864(player, 1.0999908f);
    }
}

void bssnowball_entrypoint_2(u8 *player)
{
    if (func_800A3274() == 2) {
        if (*(u8 *) ((s8 *) player + 0x165) != 0) {
            _basnowball_entrypoint_9(player, 0.0f);
        } else {
            _basnowball_entrypoint_9(player, func_8009BB5C(player));
        }
        if ((*(u8 *) ((s8 *) player + 0x165) != 0) ||
            (baphysics_get_target_horizontal_velocity(player) == 0.0f)) {
            _basnowball_entrypoint_8(player, 1);
        } else {
            _basnowball_entrypoint_8(player, 0);
        }
        _basnowball_entrypoint_12(player);
    }
}

void func_808003B0_bssnowball(s32 player)
{
    _basudie_entrypoint_8();
    bssnowball_entrypoint_0(player);
}

void func_808003D8_bssnowball(Actor *player)
{
    f32 pos[3];
    s32 unk_0;

    unk_0 = func_800B53A4(0x32);
    bssnowball_entrypoint_1(player);
    _basudie_entrypoint_9(player, 0x42B40000);
    func_8009C128(player, &pos);
    func_8009DB04(player, 0x694, 0x3F800000, 0x7FFF);
    func_8009D9D4(player);
    func_800BBCB8(&pos, 0, 0x3F800000, 1, &D_80801028_bssnowball);
    func_800BBCB8(&pos, 0, 0x3F800000, 1, &D_80800F30_bssnowball);
    func_800BABB8(unk_0, &pos, &pos, 0x3F800000, &D_80800F84_bssnowball);
    _basnowball_entrypoint_10(player);
}

void func_808004AC_bssnowball()
{
    _basudie_entrypoint_10();
}

int bssnowball_entrypoint_3(s32 player)
{
    return D_80801054_bssnowball[player];
}

void func_808004E0_bssnowball(s32 player)
{
    _bsdrone_entrypoint_2();
    bssnowball_entrypoint_0(player);
}

void func_80800508_bssnowball(s32 player)
{
    bssnowball_entrypoint_1();
    _bsdrone_entrypoint_0(player);
}

void func_80800530_bssnowball(s32 player)
{
    _bsdrone_entrypoint_1();
    bssnowball_entrypoint_2(player);
}

int bssnowball_entrypoint_4(s32 player)
{
    return D_80801064_bssnowball[player];
}

void func_8080056C_bssnowball(s32 player)
{
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    bssnowball_entrypoint_0(player);
}

void func_808005A4_bssnowball(Actor *player)
{
    Actor *player_copy;
    // Matching: extra copy of the argument.
    player_copy = player;
    bssnowball_entrypoint_1(player_copy);
    baanim_playForDuration_loopSmooth(player_copy, 0x5F, 10.0f);
    func_8009FFD8(player_copy, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(player_copy), 3);
    func_80800164_bssnowball(player_copy);
}

int func_80800614_bssnowball(s32 player)
{
    s32 next_state;
    next_state = 0;
    func_80800064_bssnowball(player, 1);
    func_80800000_bssnowball(player);
    if (func_8008DF8C(player, 0xC8) != 0) {
        func_8009D3A8(player, next_state);
    }
    if (player_isStable(player)) {
        func_800A2EAC(player);
        // Matching: odd constant form needed for the match.
        baphysics_set_target_horizontal_velocity(player, 0 & 0xFFFFFFFFFFFFFFFFu);
        next_state = 0x17E;
    }
    bssnowball_entrypoint_2(player);
    bs_setState(player, next_state);
}

int bssnowball_entrypoint_5(s32 player)
{
    return D_80801074_bssnowball[player];
}

void func_808006BC_bssnowball(PlayerState *player)
{
    bssnowball_entrypoint_1(player);
    baanim_playForDuration_loopSmooth(player, 0x5F, 10.0f);
    func_8009FFD8(player, 2, 3, 1, 14);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(player), 3);
    func_80800164_bssnowball(player);
    if (bastick_distance(player) != 0.0f)
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800064_bssnowball(player, 1);
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 693.5f);
    baphysics_set_gravity(player, -2400.0f);
    func_8009D7A4(player, 1.35f, 1.45f);
}

void func_808007D8_bssnowball(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_80800064_bssnowball(player, 1);
    func_80800000_bssnowball(player);
    if (bakey_released(player, 8) && baphysics_get_vertical_velocity(player) > 0.0f)
        baphysics_reset_gravity(player);
    if (func_8008DF8C(player, 200))
        func_8009D3A8(player, 0);
    if (player_isStable(player)) {
        func_800A2EAC(player);
        next_state = 0x17E;
    }
    bssnowball_entrypoint_2(player);
    bs_setState(player, next_state);
}

void func_8080089C_bssnowball(s32 player)
{
    baphysics_reset_gravity(player);
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    bssnowball_entrypoint_0(player);
}

int bssnowball_entrypoint_6(s32 player)
{
    return D_80801084_bssnowball[player];
}

void func_808008F0_bssnowball()
{
    func_80099B94();
}

void func_80800910_bssnowball()
{
    bssnowball_entrypoint_0();
}

void func_80800930_bssnowball(Actor *player)
{
    bssnowball_entrypoint_1();
    baanim_playForDuration_loopSmooth(player, 0x5F, 10.0f);
    func_8009FFD8(player, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(player), 3);
    func_80800164_bssnowball(player);
    *(u8 *) ((char *) player + 0x164) = 0;
    *(f32 *) ((char *) player + 0x174) = 1.0f;
}

void func_808009B0_bssnowball(PlayerState *player)
{
    s32 next_state;
    f32 unk_0;
    f32 pitch_base;
    f32 pitch;

    next_state = 0;
    func_8009D3A8(player, 0);
    func_80800064_bssnowball(player, 1);
    unk_0 = func_80800000_bssnowball(player);
    if (unk_0 > 0.67f && *(f32 *) ((u8 *) player + 0x174) < 0.67f) {
        pitch_base = func_800F10B4(func_8009BB5C(player), 0.0f, 700.0f, 0.9f, 1.1f);
        if (*(u8 *) ((u8 *) player + 0x164)) {
            pitch = pitch_base - 0.1f;
        } else {
            pitch = pitch_base + 0.1f;
        }
        func_8009DBB0(player, 0x5F2, pitch - 0.03f, pitch + 0.03f, 0x6D60);
        *(u8 *) ((u8 *) player + 0x164) ^= 1;
    }
    *(f32 *) ((u8 *) player + 0x174) = unk_0;
    if (bastick_getZone(player) == 0 && _basnowball_entrypoint_3(player) == 0.0f) {
        next_state = 0x17D;
    }
    if (func_8008DD04(player)) {
        next_state = 0x180;
    }
    if (bakey_pressed(player, 8)) {
        next_state = 0x17F;
    }
    bssnowball_entrypoint_2(player);
    bs_setState(player, next_state);
}

int bssnowball_entrypoint_7(s32 player)
{
    return D_80801094_bssnowball[player];
}

void func_80800B44_bssnowball(Actor *player)
{
    _baspin_entrypoint_1();
    *(u8 *) ((char *) player + 0x165) = 0;
    bssnowball_entrypoint_0(player);
}

void func_80800B70_bssnowball(Actor *player)
{
    bssnowball_entrypoint_1();
    *(u8 *) ((char *) player + 0x165) = 1;
    _basnowball_entrypoint_10(player);
    _baspin_entrypoint_2(player, 0x5E, 0x3FE66666, 3, 0);
}

int func_80800BBC_bssnowball(Actor *player)
{
    s32 next_state;
    next_state = 0;
    bssnowball_entrypoint_2(player);
    if (_baspin_entrypoint_3(player) == 2) {
        next_state = 0x17D;
    }
    bs_setState(player, next_state);
}

int bssnowball_entrypoint_8(s32 player)
{
    return D_808010A4_bssnowball[player];
}

void func_80800C18_bssnowball(s32 player)
{
    _babounce_entrypoint_3();
    bssnowball_entrypoint_0(player);
}

int func_80800C40_bssnowball(Actor *player)
{
    int unk_0;
    bssnowball_entrypoint_1(player);
    _babounce_entrypoint_4(player, 2);
    // Matching: extra temporary for the constant.
    unk_0 = 0x3F0346DC;
    _babounce_entrypoint_5(player, 0x5e, unk_0);
    func_8008B10C(baanim_getAnimCtrlPtr(player), 0.1026f);
}

s32 func_80800C98_bssnowball(s32 player)
{
    s32 next_state;

    next_state = 0;
    if (_babounce_entrypoint_2(player)) {
        func_80800064_bssnowball(player, 0);
    }
    if (_babounce_entrypoint_9(player)) {
        next_state = 0x17D;
    }
    bs_setState(player, next_state);
}

int bssnowball_entrypoint_9(s32 player)
{
    return D_808010B4_bssnowball[player];
}

void func_80800D00_bssnowball(s32 player)
{
    _bsrest_entrypoint_14();
    bssnowball_entrypoint_0(player);
}

void func_80800D28_bssnowball(s32 player)
{
    bssnowball_entrypoint_1();
    _bsrest_entrypoint_16(player);
}

void func_80800D50_bssnowball(s32 player)
{
    s32 next_state = 0;
    if (_bsrest_entrypoint_20(player) != 0) {
        next_state = _bsrest_entrypoint_13(player);
    }
    bssnowball_entrypoint_2(player);
    bs_setState(player, next_state);
}

int bssnowball_entrypoint_10(s32 player)
{
    return D_808010C4_bssnowball[player];
}

void func_80800DB0_bssnowball(s32 player)
{
    func_80090A2C();
    bssnowball_entrypoint_0(player);
}

int func_80800DD8_bssnowball(Actor *player)
{
    s32 saved_player;
    // Matching: extra copy of the argument.
    saved_player = player;
    bssnowball_entrypoint_1();
    baanim_playForDuration_loopSmooth(saved_player, 0x5E, 1.2f);
    func_8009FFD8(saved_player, 1, 3, 1, 2);
    func_80800164_bssnowball(saved_player);
    baphysics_set_target_horizontal_velocity(saved_player, 0);
    func_800909CC(saved_player);
}

void func_80800E4C_bssnowball(PlayerState *player)
{
    s32 next_state;
    next_state = 0;
    func_80800064_bssnowball(player, 1);
    func_8009D3A8(player, 0);
    if (func_8008DD04(player))
        next_state = 0x180;
    if (baphysics_get_target_horizontal_velocity(player) > 0.0f)
        next_state = 0x17E;
    next_state = func_800A02DC(player, func_8080010C_bssnowball((s32) player, next_state));
    bssnowball_entrypoint_2(player);
    bs_setState(player, next_state);
}

int bssnowball_entrypoint_11(s32 player)
{
    return D_808010D4_bssnowball[player];
}

extern void _basudie_entrypoint_11();
extern void _bsdrone_entrypoint_3();
extern void func_80099AA8();
s32 D_80800F30_bssnowball[21] = {0x1D0963, 0x160002,  0x150000,  0xFD001E,   0x1E001E,  0x2EFFA4,
                                 0x320,    -0x5BFE99, 0x320001B, -0x5DB05DC, 0x30417,   0x36B00008,
                                 0xE60119, 0x400B3,   0x7000F,   0x2B0500,   0x5000026, 0x38400C8,
                                 0x384,    0xC80000,  0x0};
s32 D_80800F84_bssnowball[41] = {0x1D0960,   0x160002,   0xB001E,   0x320050,  0x1E0015,  0xB3,
                                 0x1BFA24,   -0x5DBFFFC, 0x990007,  0x6002B,   0x38003CC, 0x26FE0C,
                                 -0x1F301F4, 0x1F401F4,  0x1F4002E, -0x3C0000, 0xC8FFD8,  0x1670190,
                                 0x220280,   0x2B30280,  0x280041A, 0x2EFFBA,  0x190,     -0x3BFE99,
                                 0x1C20022,  0x18001B3,  0x1800180, 0x61A002E, -0x550000, 0x2BCFFB5,
                                 0x1670352,  0x220100,   0x1330100, 0x100101A, 0x2EFFAB,  0x320,
                                 -0x13FE99,  0x44C0022,  0x990100,  0xCC00CC,  0x181A0000};
s32 D_80801028_bssnowball[11] = {0x1D09D6, 0x150000,  0x4C0016,  0x1000001E, 0x1E001E, 0x190000,
                                 0x22,     0x1000100, 0x4000400, 0x2B0080,   0x800000};
s32 D_80801054_bssnowball[4] = {(u32) func_808003B0_bssnowball, (u32) func_808003D8_bssnowball,
                                (u32) func_808004AC_bssnowball, (u32) _basudie_entrypoint_11};
s32 D_80801064_bssnowball[4] = {(u32) func_808004E0_bssnowball, (u32) func_80800508_bssnowball,
                                (u32) func_80800530_bssnowball, (u32) _bsdrone_entrypoint_3};
int D_80801074_bssnowball[4] = {(u32) func_8080056C_bssnowball, (u32) func_808005A4_bssnowball,
                                (u32) func_80800614_bssnowball, (u32) func_808008F0_bssnowball};
s32 D_80801084_bssnowball[4] = {(u32) func_8080089C_bssnowball, (u32) func_808006BC_bssnowball,
                                (u32) func_808007D8_bssnowball, (u32) func_808008F0_bssnowball};
s32 D_80801094_bssnowball[4] = {(u32) func_80800910_bssnowball, (u32) func_80800930_bssnowball,
                                (u32) func_808009B0_bssnowball, (u32) func_808008F0_bssnowball};
s32 D_808010A4_bssnowball[4] = {(u32) func_80800B44_bssnowball, (u32) func_80800B70_bssnowball,
                                (u32) func_80800BBC_bssnowball, (u32) func_80099AA8};
s32 D_808010B4_bssnowball[4] = {(u32) func_80800C18_bssnowball, (u32) func_80800C40_bssnowball,
                                (u32) func_80800C98_bssnowball, (u32) func_808008F0_bssnowball};
s32 D_808010C4_bssnowball[4] = {(u32) func_80800D00_bssnowball, (u32) func_80800D28_bssnowball,
                                (u32) func_80800D50_bssnowball, (u32) func_808008F0_bssnowball};
s32 D_808010D4_bssnowball[7] = {(u32) func_80800DB0_bssnowball,
                                (u32) func_80800DD8_bssnowball,
                                (u32) func_80800E4C_bssnowball,
                                (u32) func_808008F0_bssnowball,
                                0x0,
                                0x0,
                                0x0};
