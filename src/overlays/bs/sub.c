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

void func_80800000_bssub(s32 param_0)
{
    func_8009FFD8(param_0, 1, 3, 3, 15);
}

f32 func_80800030_bssub(f32 param_0, f32 param_1)
{
    return param_1 * 300.0f;
}

f32 func_80800048_bssub(f32 param_0, f32 param_1)
{
    return -param_1 * 428.57144f;
}

void func_80800064_bssub(PlayerState *param_0)
{
    switch (func_8009E6EC(param_0)) {
        case 0x85:
            _basub_entrypoint_15(param_0, func_80099A58(param_0));
            break;
        case 0x2D:
            func_800995B8(param_0, 3);
            func_8009E830(param_0, 2);
            bs_setState(param_0, 0x46);
            break;
        default:
            func_80099B94(param_0);
    }
}

void func_808000F0_bssub(param_0) PlayerState *param_0;
{
    f32 local_0 = func_800F10B4(func_8009BB94(param_0), 0.0f, 225.0f, 0.0f, 1.0f);
    f32 local_2;
    f32 local_1;
    f32 local_5;
    f32 local_4;
    f32 local_3;
    if (player_inWater(param_0))
    {
        local_1 = func_800F1214(local_0, 50.0f, 150.0f);
        local_2 = func_800F1214(local_0, 0.5f, 2.0f); local_3 = func_800F1214(local_0, 40.0f, 150.0f); local_5 = func_800F1214(local_0, 0.6f, 3.0f); baroll_setAngularVelocity(param_0, local_3, local_5); yaw_setVelocityBounded(param_0, 250, 20);
    }
    else
    {
        local_1 = 250.0f;
        local_2 = 2.8f;
        baroll_setAngularVelocity(param_0, 250, local_2);
        yaw_setVelocityBounded(param_0, 300.0f, 3.0f);
    }
    local_4 = _bafpctrl_entrypoint_3(param_0);
    local_1 *= func_800F10B4(local_4, 0.1f, 1.0f, local_4 * local_4, 1.0f);
    func_8009BFE4(param_0, local_1, local_2);
}

void func_80800254_bssub(param_0) PlayerState *param_0;
{
    f32 local_0;
    f32 local_7;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;
    f32 local_5[3];
    s32 local_6;

    local_1 = func_800A3048() * 90.0f;
    local_3 = func_800D8FF8();
    local_4 = player_inWater(param_0);
    if (local_4) {
        baphysics_set_gravity(param_0, 0.0f);
        baphysics_set_terminal_velocity(param_0, -4000.0f);
        _bamovethrust_entrypoint_4(param_0, 0.9f);
        _bamovethrust_entrypoint_3(param_0, param_0->unk16C);
    } else {
        baphysics_set_gravity(param_0, -1800.0f);
        baphysics_set_terminal_velocity(param_0, -4000.0f);
        _bamovethrust_entrypoint_4(param_0, 0.95f);
        _bamovethrust_entrypoint_3(param_0, param_0->unk16C * 0.25f);
    }
    if (bakey_held(param_0, 8) || _basub_entrypoint_2(param_0) != 0.0f) {
        local_0 = func_80800030_bssub(param_0->unk16C, local_3);
    } else {
        local_0 = func_80800048_bssub(param_0->unk16C, local_3);
    }
    if (_basub_entrypoint_2(param_0) != 0.0f) {
        param_0->unk16C =
            func_800F0D50(param_0->unk16C + local_0, 0.0f, _basub_entrypoint_2(param_0));
    } else {
        param_0->unk16C = func_800F0D50(param_0->unk16C + local_0, 0, local_1);
    }
    _basub_entrypoint_13(param_0, func_800F10B4(param_0->unk16C, 0.0f, local_1, 200.0f, 1350.0f));
    local_2 = func_800F10B4(param_0->unk16C, 0.0f, local_1, 0.8f, 1.1f);
    local_7 = mlAbsF(func_800F1DCC(yaw_getIdeal(param_0), yaw_get(param_0))) / local_3;
    local_2 += func_800F10B4(local_7, 0.0f, 128.0f, 0.0f, -0.12f);
    if (!local_4) {
        local_2 += 0.7f;
    }
    _basub_entrypoint_11(param_0, local_2);
    local_7 = func_8009BFD8(param_0);
    if (local_7 > 180.0f) {
        local_7 -= 360.0f;
    }
    _basub_entrypoint_12(param_0, func_800F1344(local_7, 0.0f, 85.0f, 0.0f, 60.0f));
    if (local_4) {
        if (_basub_entrypoint_2(param_0) != 0.0f) {
            func_800914FC(param_0, 60.0f, 1);
        } else {
            func_800914FC(
                param_0,
                func_800F10B4(param_0->unk16C, 0.0f, local_1, func_800DC178(1.0f, 3.0f), 40.0f), 0);
        }
    } else if (param_0->unk16C > 0.0f && player_isStable(param_0)) {
        func_8009C128(param_0, local_5);
        local_6 = func_800B5BE4(8);
        func_800BABB8(local_6, local_5, 0, 1.0f, D_808016E0_bssub);
        func_800BA77C(local_6, 0, 0, (s16) func_800DC178(0.0f, 359.0f));
        func_800BA22C(local_6, 1);
    }
    func_808000F0_bssub(param_0);
}

void func_80800634_bssub(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;

    local_4 = bastick_getX(param_0);
    local_3 = func_800D8FF8();
    local_1 = func_800F10B4(func_8009BB94(param_0), 0.0f, 225.0f, 11.25f, 45.0f);
    baroll_setIdeal(param_0, func_800F10B4(local_4, -1.0f, 1.0f, -local_1, local_1));
    if (player_inWater(param_0)) {
        local_2 =
            func_800F10B4(func_8009BB94(param_0), 0.0f, 225.0f, 42.666667938232421875f, 128.0f);
    } else {
        local_2 = 300.0f;
    }
    local_0 = func_800F10B4(local_4, -1.0f, 1.0f, local_2, -local_2) * local_3;
    local_0 *= _bafpctrl_entrypoint_3(param_0);
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + local_0);
}

void func_80800768_bssub(param_0) PlayerState *param_0;
{
    f32 local_2;
    f32 local_0;
    f32 local_1;
    f32 local_3;

    if (player_inWater(param_0)) {
        local_0 = 275.0f;
        local_1 = 85.0f;
    } else {
        local_0 = 325.0f;
        local_1 = 30.0f;
    }
    local_2 = bastick_getY(param_0);
    if (local_2 < 0.0f) {
        local_3 = func_800F10B4(local_2, -1.0f, 0.0f, local_0, 360.0f);
        func_8009BF5C(param_0, local_3);
    } else {
        local_3 = func_800F10B4(local_2, 0.0f, 1.0f, 0.0f, local_1);
        func_8009BF5C(param_0, local_3);
    }
}

void func_80800834_bssub(PlayerState *param_0)
{
    if (bakey_pressed(param_0, 2))
        _basub_entrypoint_1(param_0);
    if (bakey_pressed(param_0, 1))
        _basub_entrypoint_8(param_0, func_8009BB94(param_0));
    if (bakey_pressed(param_0, 9)) {
        if (func_800EA068(0x40))
            _basub_entrypoint_3(param_0, 160.0f, 1.0f);
        else
            _basub_entrypoint_5(param_0);
    }
}

void func_808008D8_bssub(PlayerState *param_0)
{
    if (!func_8009E74C(param_0, 0xF)) {
        func_800947EC(param_0, 1, 0);
        func_800961AC(param_0, 1);
        func_8009BC34(param_0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        func_8009C000(param_0);
        baroll_resetAngularVelocity(param_0);
        bastick_resetZones(param_0);
        func_80095A40(param_0);
        func_80095964(param_0, 0);
        func_80093360(param_0, 0.0f);
        _basub_entrypoint_9(param_0);
        func_800910BC(param_0, 1);
        _bafpctrl_entrypoint_18(param_0, 0);
        func_8009E474(param_0);
        func_80092864(param_0, 1.0f);
    }
}

void func_808009B0_bssub(param_0) PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 15)) {
        _basub_entrypoint_10(param_0);
        param_0->unk16C = 0.0f;
        param_0->unk170 = 0.0f;
        baphysics_set_gravity(param_0, 0);
        baphysics_set_terminal_velocity(param_0, -399.989990234375f);
        func_800961AC(param_0, 9);
        func_80095964(param_0, 1);
        func_8009BC5C(param_0, 2.0f);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 1.0f);
        func_800959C8(param_0, 90.0f, 70.0f);
        func_8009E4AC(param_0);
        func_8009E55C(param_0, 0, 70.0f);
        func_8009E55C(param_0, 1, 0.0f);
        func_8009E55C(param_0, 2, 0.0f);
        func_80093360(param_0, 55.0f);
        func_800910BC(param_0, 4);
        func_808000F0_bssub(param_0);
        _bafpctrl_entrypoint_18(param_0, 1);
        func_800947EC(param_0, 1, 1);
        func_80092864(param_0, 2.0f);
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

void func_80800B2C_bssub(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0x12E, 6.0f);
    func_80800000_bssub(param_0);
    _bamovethrust_entrypoint_3(param_0, 0.0f);
    _bamovethrust_entrypoint_4(param_0, 0.9f);
    _basub_entrypoint_11(param_0, 0.6f);
    _basub_entrypoint_13(param_0, 1.0f);
    _baspin_entrypoint_2(param_0, 0x130, 1.8f, 3, 1);
    _batimer_set(param_0, 9, 1.8f);
    func_800FC660(0x19);
}

int func_80800BD8_bssub(Actor *param_0)
{
    _baspin_entrypoint_3();
    if (_batimer_decrement(param_0, 9) != 0) {
        func_80101180(0x2C4, 0x71, *(u32 *) ((char *) param_0 + 0x184));
    }
}

void func_80800C1C_bssub(void *param_0)
{
    if (*(s32 *) ((char *) param_0 + 0x15C) != 0) {
        func_80800B0C_bssub(param_0);
    } else {
        _basudie_entrypoint_8(param_0);
    }
    func_808008D8_bssub(param_0);
}

void func_80800C60_bssub(void *param_0)
{
    s32 local_1[10];
    f32 local_0[3];
    s32 local_2;

    func_8009DB04(param_0, 0x413, 1.0, 0x7FFF);
    func_8009D9D4(param_0);
    func_8009C128(param_0, local_0);
    func_800BBCB8(local_0, NULL, 1.0f, 1, D_808017A0_bssub);
    for (local_2 = 0; local_2 < 10; local_2++) {
        local_1[local_2] = func_800B53A4(D_80801840_bssub[local_2].type);
        func_800BA670(local_1[local_2], D_80801840_bssub[local_2].sprite);
        local_1[local_2] =
            func_800BABB8(local_1[local_2], local_0, local_0, 1.0f, D_8080172C_bssub);
    }
    if (player_inWater(param_0)) {
        func_800BABB8(_fxairbub_entrypoint_1(local_0, 100.0f, func_800964DC(param_0), 1.0f),
                      local_0, local_0, 1.0f, D_808017CC_bssub);
        for (local_2 = 0; local_2 < 10; local_2++) {
            local_1[local_2] =
                func_800BABB8(local_1[local_2], local_0, local_0, 1.0f, D_80801748_bssub);
        }
    } else {
        for (local_2 = 0; local_2 < 10; local_2++) {
            local_1[local_2] =
                func_800BABB8(local_1[local_2], local_0, local_0, 1.0f, D_80801774_bssub);
        }
    }
    for (local_2 = 0; local_2 < 10; local_2++) {
        func_800BA22C(local_1[local_2], D_80801840_bssub[local_2].type);
    }
}

void func_80800E34_bssub(s32 param_0)
{
    s32 local_0;
    s32 *s0;
    s0 = (s32 *) param_0;
    func_808009B0_bssub(s0);
    local_0 = func_800EA068(0x40);
    s0[0x57] = local_0;
    if (local_0 != 0) {
        func_80800B2C_bssub(s0);
    } else {
        _bafpctrl_entrypoint_19(s0);
        _basudie_entrypoint_9(s0, 0x41F00000);
        func_80800C60_bssub(s0);
    }
}

int func_80800E98_bssub(Actor *param_0)
{
    func_80800AEC_bssub();
    if (*(s32 *) ((char *) param_0 + 0x15c) != 0) {
        func_80800BD8_bssub(param_0);
    } else {
        _basudie_entrypoint_10();
    }
}

int func_80800EE0_bssub(Actor *param_0)
{
    s32 local_0;
    Actor *local_1 = param_0;
    local_0 = func_8009E6EC();
    if (local_0 == 0x83) {
        func_8009BDAC(local_1, func_80099A34(local_1));
        func_80093370(local_1, 1);
        bs_setState(local_1, 0x131);
        func_8009E830(local_1, 2);
    } else {
        _basudie_entrypoint_11(local_1);
    }
}

int bssub_entrypoint_0(s32 param_0)
{
    return D_80801890_bssub[param_0];
}

void func_80800F70_bssub(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808008D8_bssub(arg0);
}

void func_80800F98_bssub(s32 arg0)
{
    func_808009B0_bssub();
    _bsdrone_entrypoint_0(arg0);
}

void func_80800FC0_bssub(s32 arg0)
{
    func_80800AEC_bssub();
    func_80800254_bssub(arg0);
    _bsdrone_entrypoint_1(arg0);
}

int bssub_entrypoint_1(s32 param_0)
{
    return D_808018A0_bssub[param_0];
}

void func_80801004_bssub(s32 arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}

void func_8080102C_bssub(param_0) PlayerState *param_0;
{
    AnimCtrl *local_0;
    s32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = anctrl_getIndex(local_0);
    func_8008CA4C(param_0, 2);
    if (func_8009BB94(param_0) < 300.0f) {
        if (local_1 != 0x12E) {
            baanim_playForDuration_loopSmooth(param_0, 0x12E, 6.0f);
            func_8008B1C8(local_0, 0.4f);
        }
        func_8008C9F0(param_0, 0.0f, 900.0f, 6.0f, 6.0f);
    } else {
        if (local_1 != 0x12F) {
            baanim_playForDuration_loopSmooth(param_0, 0x12F, 0.45f);
            func_8008B1C8(local_0, 0.4f);
        }
        func_8008C9F0(param_0, 0.0f, 900.0f, 1.5f, 0.45f);
    }
}

int func_80801130_bssub(s32 param_0)
{
    s32 local_0;
    local_0 = param_0 | 0;
    func_808009B0_bssub(local_0);
    func_8080102C_bssub(local_0);
    baanim_setDurationRange(local_0, 0x3E99999A, 0x41200000);
    func_8008CA30(local_0, 0x3F800000);
    func_800909CC(local_0);
}

void func_80801188_bssub(u8 *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_80800AEC_bssub();
    func_8080102C_bssub(param_0);
    func_80800634_bssub(param_0);
    func_80800768_bssub(param_0);
    func_80800254_bssub(param_0);
    func_80800834_bssub(param_0);
    if (*(f32 *) ((s8 *) param_0 + 0x16C) == 0.0f) {
        local_0 = 0x131;
    }
    bs_setState(param_0, local_0);
}

int bssub_entrypoint_2(s32 param_0)
{
    return D_808018B0_bssub[param_0];
}

void func_8080121C_bssub(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}

void func_80801244_bssub(s32 param_0)
{
    func_808009B0_bssub();
    _baspin_entrypoint_2(param_0, 0x130, 1.8f, 3, 1);
}

void func_80801284_bssub(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_80800AEC_bssub();
    func_800914FC(param_0, 4e+01f, 0);
    if (_baspin_entrypoint_3(param_0) == 2) {
        local_0 = 0x131;
    }
    bs_setState(param_0, local_0);
}

int bssub_entrypoint_3(s32 param_0)
{
    return D_808018C0_bssub[param_0];
}

void func_808012F0_bssub(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}

void func_80801318_bssub(s32 param_0)
{
    func_808009B0_bssub();
    _baspin_entrypoint_2(param_0, 0x130, 1.8f, 3, 1);
}

void func_80801358_bssub(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_80800AEC_bssub();
    func_800914FC(param_0, 4e+01f, 0);
    if (_baspin_entrypoint_3(param_0) == 2) {
        local_0 = 0x131;
    }
    bs_setState(param_0, local_0);
}

int bssub_entrypoint_4(s32 param_0)
{
    return D_808018D0_bssub[param_0];
}

void func_808013C4_bssub(s32 arg0)
{
    _babounce_entrypoint_3();
    func_808008D8_bssub(arg0);
}

int func_808013EC_bssub(s32 param_0)
{
    func_808009B0_bssub();
    _babounce_entrypoint_4(param_0, 2);
    _babounce_entrypoint_5(param_0, 0x12E, 0x40C00000);
}

s32 func_80801428_bssub(s32 param_0)
{
    s32 local_0;

    local_0 = 0;
    func_80800AEC_bssub();
    func_800914FC(param_0, 4e+01f, 0);
    if (_babounce_entrypoint_9(param_0) != 0) {
        local_0 = 0x131;
    }
    bs_setState(param_0, local_0);
}

int bssub_entrypoint_5(s32 param_0)
{
    return D_808018E0_bssub[param_0];
}

void func_80801490_bssub(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808008D8_bssub(arg0);
}

void func_808014B8_bssub(u8 *param_0)
{
    func_808009B0_bssub();
    func_8009BF5C(param_0, 0);
    _bsrest_entrypoint_16(param_0);
    func_8009B94C(param_0, 0);
    func_8009BA9C(param_0, 0);
    *(f32 *) ((s8 *) param_0 + 0x16C) = 0.0f;
}

int func_80801518_bssub(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_80800AEC_bssub();
    if (_bsrest_entrypoint_20(param_0)) {
        local_0 = _badata_entrypoint_34(param_0);
    }
    bs_setState(param_0, local_0);
}

int bssub_entrypoint_6(s32 param_0)
{
    return D_808018F0_bssub[param_0];
}

void func_80801578_bssub(s32 arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}

void func_808015A0_bssub(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    func_808009B0_bssub(param_0);
    if (anctrl_getIndex(local_0) == 0x12E) {
        anctrl_setDuration(local_0, 6.0f);
    } else {
        baanim_playForDuration_loopSmooth(param_0, 0x12E, 6.0f);
    }
    func_800909CC(param_0);
    func_80800000_bssub(param_0);
}

void func_80801618_bssub(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_80800AEC_bssub();
    func_80800634_bssub(param_0);
    func_80800768_bssub(param_0);
    func_80800254_bssub(param_0);
    func_80800834_bssub(param_0);
    if (*(f32 *) ((char *) param_0 + 0x16C) != 0.0f) {
        local_0 = 0x12C;
    }
    bs_setState(param_0, local_0);
}

int bssub_entrypoint_7(s32 param_0)
{
    return D_80801900_bssub[param_0];
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
