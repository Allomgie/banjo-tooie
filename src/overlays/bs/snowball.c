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

f32 func_80800000_bssnowball(PlayerState *param_0)
{
    f32 local_1;
    f32 local_0;

    local_1 = func_800F10B4(_basnowball_entrypoint_3(param_0), 0.0f, 360.0f, 0.0f, 1.0f);
    local_0 = func_800F13C4(local_1, 1.0f);
    func_8008C990(param_0, local_0);
    return local_0;
}

void func_80800064_bssnowball(PlayerState *param_0, s32 param_1)
{
    f32 local_0;
    local_0 = bastick_getZonePosition(param_0);
    if (param_1 && bakey_held(param_0, 9)) {
        baphysics_set_target_horizontal_velocity(param_0, 1400.0f);
        _basnowball_entrypoint_7(param_0);
    } else if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 700.0f));
    }
}

s32 func_8080010C_bssnowball(s32 param_0, s32 param_1)
{
    if (bainput_should_enter_first_person()) {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (bakey_pressed(param_0, 8)) {
        param_1 = 0x17F;
    }
    return param_1;
}

int func_80800164_bssnowball(Actor *param_0)
{
    yaw_setUpdateType(param_0, 0x3);
    yaw_setVelocityBounded(param_0, 0x43960000, 0x40C00000);
}

void bssnowball_entrypoint_0(param_0)
{
    if (!func_8009E74C(param_0, 0x16)) {
        func_800947EC(param_0, 1, 0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        func_8009C000(param_0);
        baroll_resetAngularVelocity(param_0);
        bastick_popZone(param_0);
        baflag_clear(param_0, 3);
        baflag_clear(param_0, 4);
        _basnowball_entrypoint_1(param_0);
        func_80092864(param_0, 1.0f);
    }
}

void bssnowball_entrypoint_1(param_0) u8 *param_0;
{
    if (func_8009E77C(param_0, 0x16) == 0) {
        _basnowball_entrypoint_2(param_0);
        func_8009BFE4(param_0, 0x447A0000, 0x41400000);
        baroll_setAngularVelocity(param_0, 0x447A0000, 0x41400000);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0x3DF5C28F);
        bastick_setZoneMax(param_0, 1, 0x3F800000);
        baflag_set(param_0, 3);
        baflag_set(param_0, 4);
        func_800947EC(param_0, 1, 1);
        ((u8 *) param_0)[0x165] = 0;
        func_80092864(param_0, 1.0999908f);
    }
}

void bssnowball_entrypoint_2(u8 *param_0)
{
    if (func_800A3274() == 2) {
        if (*(u8 *) ((s8 *) param_0 + 0x165) != 0) {
            _basnowball_entrypoint_9(param_0, 0.0f);
        } else {
            _basnowball_entrypoint_9(param_0, func_8009BB5C(param_0));
        }
        if ((*(u8 *) ((s8 *) param_0 + 0x165) != 0) ||
            (baphysics_get_target_horizontal_velocity(param_0) == 0.0f)) {
            _basnowball_entrypoint_8(param_0, 1);
        } else {
            _basnowball_entrypoint_8(param_0, 0);
        }
        _basnowball_entrypoint_12(param_0);
    }
}

void func_808003B0_bssnowball(s32 arg0)
{
    _basudie_entrypoint_8();
    bssnowball_entrypoint_0(arg0);
}

void func_808003D8_bssnowball(Actor *param_0)
{
    f32 local_1[3];
    s32 local_0;

    local_0 = func_800B53A4(0x32);
    bssnowball_entrypoint_1(param_0);
    _basudie_entrypoint_9(param_0, 0x42B40000);
    func_8009C128(param_0, &local_1);
    func_8009DB04(param_0, 0x694, 0x3F800000, 0x7FFF);
    func_8009D9D4(param_0);
    func_800BBCB8(&local_1, 0, 0x3F800000, 1, &D_80801028_bssnowball);
    func_800BBCB8(&local_1, 0, 0x3F800000, 1, &D_80800F30_bssnowball);
    func_800BABB8(local_0, &local_1, &local_1, 0x3F800000, &D_80800F84_bssnowball);
    _basnowball_entrypoint_10(param_0);
}

void func_808004AC_bssnowball()
{
    _basudie_entrypoint_10();
}

int bssnowball_entrypoint_3(s32 param_0)
{
    return D_80801054_bssnowball[param_0];
}

void func_808004E0_bssnowball(s32 arg0)
{
    _bsdrone_entrypoint_2();
    bssnowball_entrypoint_0(arg0);
}

void func_80800508_bssnowball(s32 arg0)
{
    bssnowball_entrypoint_1();
    _bsdrone_entrypoint_0(arg0);
}

void func_80800530_bssnowball(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bssnowball_entrypoint_2(arg0);
}

int bssnowball_entrypoint_4(s32 param_0)
{
    return D_80801064_bssnowball[param_0];
}

void func_8080056C_bssnowball(s32 param_0)
{
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    bssnowball_entrypoint_0(param_0);
}

void func_808005A4_bssnowball(Actor *param_0)
{
    Actor *s0;
    s0 = param_0;
    bssnowball_entrypoint_1(s0);
    baanim_playForDuration_loopSmooth(s0, 0x5F, 10.0f);
    func_8009FFD8(s0, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(s0), 3);
    func_80800164_bssnowball(s0);
}

int func_80800614_bssnowball(s32 param_0)
{
    s32 local_0;
    local_0 = 0;
    func_80800064_bssnowball(param_0, 1);
    func_80800000_bssnowball(param_0);
    if (func_8008DF8C(param_0, 0xC8) != 0) {
        func_8009D3A8(param_0, local_0);
    }
    if (player_isStable(param_0)) {
        func_800A2EAC(param_0);
        baphysics_set_target_horizontal_velocity(param_0, 0 & 0xFFFFFFFFFFFFFFFFu);
        local_0 = 0x17E;
    }
    bssnowball_entrypoint_2(param_0);
    bs_setState(param_0, local_0);
}

int bssnowball_entrypoint_5(s32 param_0)
{
    return D_80801074_bssnowball[param_0];
}

void func_808006BC_bssnowball(PlayerState *param_0)
{
    bssnowball_entrypoint_1(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x5F, 10.0f);
    func_8009FFD8(param_0, 2, 3, 1, 14);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(param_0), 3);
    func_80800164_bssnowball(param_0);
    if (bastick_distance(param_0) != 0.0f)
        yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800064_bssnowball(param_0, 1);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0),
                                      baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 693.5f);
    baphysics_set_gravity(param_0, -2400.0f);
    func_8009D7A4(param_0, 1.35f, 1.45f);
}

void func_808007D8_bssnowball(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_80800064_bssnowball(param_0, 1);
    func_80800000_bssnowball(param_0);
    if (bakey_released(param_0, 8) && baphysics_get_vertical_velocity(param_0) > 0.0f)
        baphysics_reset_gravity(param_0);
    if (func_8008DF8C(param_0, 200))
        func_8009D3A8(param_0, 0);
    if (player_isStable(param_0)) {
        func_800A2EAC(param_0);
        local_0 = 0x17E;
    }
    bssnowball_entrypoint_2(param_0);
    bs_setState(param_0, local_0);
}

void func_8080089C_bssnowball(s32 param_0)
{
    baphysics_reset_gravity(param_0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    bssnowball_entrypoint_0(param_0);
}

int bssnowball_entrypoint_6(s32 param_0)
{
    return D_80801084_bssnowball[param_0];
}

void func_808008F0_bssnowball()
{
    func_80099B94();
}

void func_80800910_bssnowball()
{
    bssnowball_entrypoint_0();
}

void func_80800930_bssnowball(Actor *param_0)
{
    bssnowball_entrypoint_1();
    baanim_playForDuration_loopSmooth(param_0, 0x5F, 10.0f);
    func_8009FFD8(param_0, 2, 3, 1, 0xE);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(param_0), 3);
    func_80800164_bssnowball(param_0);
    *(u8 *) ((char *) param_0 + 0x164) = 0;
    *(f32 *) ((char *) param_0 + 0x174) = 1.0f;
}

void func_808009B0_bssnowball(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_0 = 0;
    func_8009D3A8(param_0, 0);
    func_80800064_bssnowball(param_0, 1);
    local_1 = func_80800000_bssnowball(param_0);
    if (local_1 > 0.67f && *(f32 *) ((u8 *) param_0 + 0x174) < 0.67f) {
        local_2 = func_800F10B4(func_8009BB5C(param_0), 0.0f, 700.0f, 0.9f, 1.1f);
        if (*(u8 *) ((u8 *) param_0 + 0x164)) {
            local_3 = local_2 - 0.1f;
        } else {
            local_3 = local_2 + 0.1f;
        }
        func_8009DBB0(param_0, 0x5F2, local_3 - 0.03f, local_3 + 0.03f, 0x6D60);
        *(u8 *) ((u8 *) param_0 + 0x164) ^= 1;
    }
    *(f32 *) ((u8 *) param_0 + 0x174) = local_1;
    if (bastick_getZone(param_0) == 0 && _basnowball_entrypoint_3(param_0) == 0.0f) {
        local_0 = 0x17D;
    }
    if (func_8008DD04(param_0)) {
        local_0 = 0x180;
    }
    if (bakey_pressed(param_0, 8)) {
        local_0 = 0x17F;
    }
    bssnowball_entrypoint_2(param_0);
    bs_setState(param_0, local_0);
}

int bssnowball_entrypoint_7(s32 param_0)
{
    return D_80801094_bssnowball[param_0];
}

void func_80800B44_bssnowball(Actor *param_0)
{
    _baspin_entrypoint_1();
    *(u8 *) ((char *) param_0 + 0x165) = 0;
    bssnowball_entrypoint_0(param_0);
}

void func_80800B70_bssnowball(Actor *param_0)
{
    bssnowball_entrypoint_1();
    *(u8 *) ((char *) param_0 + 0x165) = 1;
    _basnowball_entrypoint_10(param_0);
    _baspin_entrypoint_2(param_0, 0x5E, 0x3FE66666, 3, 0);
}

int func_80800BBC_bssnowball(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    bssnowball_entrypoint_2(param_0);
    if (_baspin_entrypoint_3(param_0) == 2) {
        local_0 = 0x17D;
    }
    bs_setState(param_0, local_0);
}

int bssnowball_entrypoint_8(s32 param_0)
{
    return D_808010A4_bssnowball[param_0];
}

void func_80800C18_bssnowball(s32 arg0)
{
    _babounce_entrypoint_3();
    bssnowball_entrypoint_0(arg0);
}

int func_80800C40_bssnowball(Actor *param_0)
{
    int new_var;
    bssnowball_entrypoint_1(param_0);
    _babounce_entrypoint_4(param_0, 2);
    new_var = 0x3F0346DC;
    _babounce_entrypoint_5(param_0, 0x5e, new_var);
    func_8008B10C(baanim_getAnimCtrlPtr(param_0), 0.1026f);
}

s32 func_80800C98_bssnowball(s32 param_0)
{
    s32 local_0;

    local_0 = 0;
    if (_babounce_entrypoint_2(param_0)) {
        func_80800064_bssnowball(param_0, 0);
    }
    if (_babounce_entrypoint_9(param_0)) {
        local_0 = 0x17D;
    }
    bs_setState(param_0, local_0);
}

int bssnowball_entrypoint_9(s32 param_0)
{
    return D_808010B4_bssnowball[param_0];
}

void func_80800D00_bssnowball(s32 arg0)
{
    _bsrest_entrypoint_14();
    bssnowball_entrypoint_0(arg0);
}

void func_80800D28_bssnowball(s32 arg0)
{
    bssnowball_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}

void func_80800D50_bssnowball(s32 param_0)
{
    s32 local_0 = 0;
    if (_bsrest_entrypoint_20(param_0) != 0) {
        local_0 = _bsrest_entrypoint_13(param_0);
    }
    bssnowball_entrypoint_2(param_0);
    bs_setState(param_0, local_0);
}

int bssnowball_entrypoint_10(s32 param_0)
{
    return D_808010C4_bssnowball[param_0];
}

void func_80800DB0_bssnowball(s32 arg0)
{
    func_80090A2C();
    bssnowball_entrypoint_0(arg0);
}

int func_80800DD8_bssnowball(Actor *param_0)
{
    s32 local_0;
    local_0 = param_0;
    bssnowball_entrypoint_1();
    baanim_playForDuration_loopSmooth(local_0, 0x5E, 1.2f);
    func_8009FFD8(local_0, 1, 3, 1, 2);
    func_80800164_bssnowball(local_0);
    baphysics_set_target_horizontal_velocity(local_0, 0);
    func_800909CC(local_0);
}

void func_80800E4C_bssnowball(PlayerState *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_80800064_bssnowball(param_0, 1);
    func_8009D3A8(param_0, 0);
    if (func_8008DD04(param_0))
        local_0 = 0x180;
    if (baphysics_get_target_horizontal_velocity(param_0) > 0.0f)
        local_0 = 0x17E;
    local_0 = func_800A02DC(param_0, func_8080010C_bssnowball((s32) param_0, local_0));
    bssnowball_entrypoint_2(param_0);
    bs_setState(param_0, local_0);
}

int bssnowball_entrypoint_11(s32 param_0)
{
    return D_808010D4_bssnowball[param_0];
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
