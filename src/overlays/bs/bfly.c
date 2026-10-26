#include "common.h"
#include "overlays/ba/playerstate.h"
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
typedef struct { f32 local_0; u8 pad_0[0x18]; u8 local_1; } FlyState561;
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
void func_808015C4_bsbfly();

void func_80800000_bsbfly(PlayerState *param_0)
{
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    local_0[0] += func_800DC178(-30.0f, 30.0f);
    local_0[1] += 50.0f + func_800DC178(0.0f, 30.0f);
    local_0[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(local_0, 0, 1.0f, 1, D_80801D20_bsbfly);
}

void func_808000AC_bsbfly(s32 param_0)
{
  func_80093360(param_0, 6e+01f);
  yaw_setUpdateType(param_0, 3);
  yaw_setVelocityBounded(param_0, 0x43FA0000, 0x40000000);
  baroll_setAngularVelocity(param_0, 0x43FA0000, 0x40000000);
  _bafly_entrypoint_20(param_0);
  func_800959C8(param_0, 0x42820000, 0x42480000);
  func_800961AC(param_0, 4);
}

int func_80800128_bsbfly(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_8009E77C(local_0, 9))
  {
    _bastatemem_entrypoint_0(local_0, 0x20);
    _bafly_entrypoint_5(local_0);
    func_808000AC_bsbfly(local_0);
    _baboost_entrypoint_3(local_0);
    _baboost_entrypoint_4(local_0, 1);
  }
}

int func_80800188_bsbfly(param_0) Actor *param_0;
{
  if (!func_8009E74C(param_0, 9))
  {
    _bafly_entrypoint_4(param_0);
    _bastatemem_entrypoint_1(param_0);
    baphysics_reset_gravity(param_0);
    baphysics_reset_terminal_velocity(param_0);
    func_800A0CF4(param_0, 0);
    func_80093360(param_0, ((0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
    func_800A042C(param_0);
    yaw_setUpdateType(param_0, 1);
    func_800A4E30(param_0);
    func_80095A40(param_0);
    func_800961AC(param_0, 1);
    _baboost_entrypoint_4(param_0, 0);
    baflag_clear(param_0, 0x2F);
    baflag_clear(param_0, 0x30);
  }
}

void func_80800248_bsbfly(PlayerState *param_0)
{
    baanim_playForDuration_once(param_0, 0x45, 1.4f);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_8009BA9C(param_0, 0);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    baphysics_set_gravity(param_0, -1200.0f);
    func_800A0CF4(param_0, 1);
    func_8009D874(param_0);
    param_0->unk160.word = 0;
    param_0->unk15C.word = 0;
}

void func_80800320_bsbfly(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (!param_0->unk160.word) {
        if (anctrl_isAt(local_1, 0.2416f)) {
            anctrl_setDuration(local_1, 2.4f);
            baphysics_set_vertical_velocity(param_0, 1600.0f);
            func_8009DE38(param_0, 0x406, 0.7f);
            param_0->unk160.word = 1;
        }
    } else {
        func_80800000_bsbfly(param_0);
        if (baphysics_get_vertical_velocity(param_0) < 0.0f) local_0 = 0x24;
    }
    bs_setState(param_0, local_0);
}

s32 func_808003E0_bsbfly(Actor *this){
    func_800C6DA0(0x44);
    func_800A0CF4(this, 0);
    func_800A4E30(this);
}

int bsbfly_entrypoint_0(s32 param_0)
{
  return D_80801D48_bsbfly[param_0];
}

void func_80801BB4_bsbfly();

void func_8080042C_bsbfly(s32 arg0)
{
    func_8009E6EC();
    func_80801BB4_bsbfly(arg0);
}
void func_80800454_bsbfly(Actor *param_0)
{
  s32 local_0;
  baflag_clear(param_0, 0x2F);
  baflag_clear(param_0, 0x30);
  local_0 = bs_getNextState(param_0);
  if ((((local_0 == 0x18) || (local_0 == 0x2A)) || (local_0 == 0x91)) && (_bafpctrl_entrypoint_4(param_0) == 3))
  {
    baflag_set(param_0, 0x2F);
    if (_bafpctrl_entrypoint_5(param_0) != 0)
    {
      baflag_set(param_0, 0x30);
    }
  }
  _bafpctrl_entrypoint_17(param_0);
  _bafly_entrypoint_6(param_0, (unsigned long long) 0);
  _bafly_entrypoint_7(param_0, 0);
  func_80800188_bsbfly(param_0);
}

void func_8080050C_bsbfly(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0x38, 0.62f);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    if (baflag_isTrue(param_0, 9)) baphysics_set_target_horizontal_velocity(param_0, 0);
    else baphysics_set_target_horizontal_velocity(param_0, 600.0f);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_800A0CF4(param_0, 1);
    baphysics_set_gravity(param_0, -300.0f);
    baphysics_set_terminal_velocity(param_0, -99.9f);
    func_800A4DA4(param_0, 3);
    func_80800128_bsbfly(param_0);
    *(f32 *)param_0->kazfly = 1.0f;
    param_0->unk160.word = 0;
    ((u8 *)param_0->kazfly)[0x1C] = 0;
    _bafly_entrypoint_19(param_0);
}

void func_80800624_bsbfly(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    u8 local_7;
    u8 local_8;
    s32 local_2;
    s32 local_3;
    f32 local_4;
    f32 local_5;
    s32 local_6;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    _bafly_entrypoint_20(param_0);
    _bafly_entrypoint_9(param_0);
    _bafly_entrypoint_10(param_0, 300.0f, 80.0f);
    _bafly_entrypoint_11(param_0);
    local_3 = 0;
    if (bakey_pressed(param_0, 8)) {
        ((FlyState561 *)param_0->kazfly)->local_1 = 1;
    }
    if (((FlyState561 *)param_0->kazfly)->local_1 && func_8001211C() % 3 == 0) {
        ((FlyState561 *)param_0->kazfly)->local_1 = 0;
        local_3 = _bafly_entrypoint_12(param_0);
    }
    if (local_3 || param_0->unk15C.word) {
        if (local_3) {
            anctrl_setDuration(local_1, 0.3f);
            _chusefeather_entrypoint_1(param_0->unk184, 0);
        }
        if (param_0->unk15C.word) {
            param_0->unk15C.word = 0;
            _baboost_entrypoint_2(param_0, 0.35f);
        } else {
            _baboost_entrypoint_2(param_0, 1.0f);
        }
    }
    local_2 = _baboost_entrypoint_1(param_0);
    _bafly_entrypoint_7(param_0, 0);
    switch (param_0->unk160.word) {
    case 0:
        if (local_2) {
            param_0->unk160.word = 1;
        }
        break;
    case 1:
        _bafly_entrypoint_7(param_0, 1);
        local_4 = func_800136E4(func_8009BFD8(param_0) - 30.0f);
        local_5 = local_4;
        if (local_4 > 80.0f && local_4 < 300.0f) {
            local_5 = 300.0f;
        }
        func_8009BF5C(param_0, local_5);
        _bafly_entrypoint_21(param_0);
        if (local_2) {
            baphysics_set_vertical_velocity(param_0, (f32)local_2 * 400.0f);
        }
        if (!local_2) {
            anctrl_setDuration(local_1, 0.62f);
            _bafly_entrypoint_20(param_0);
            param_0->unk160.word = 0;
        }
        break;
    }
    if (anctrl_isAt(local_1, 0.1358f)) {
        func_8009DFD4(param_0, 0x3FF, 0.6f, 0.7f, 10000, 12000);
    }
    _bafly_entrypoint_8(param_0, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, -700.0f, -1000.0f);
    if (_bafpctrl_entrypoint_4(param_0) != 3 && bainput_should_beak_bust(param_0)) {
        local_0 = 0xF;
    }
    ((FlyState561 *)param_0->kazfly)->local_0 = func_800F0E00(
        ((FlyState561 *)param_0->kazfly)->local_0 - func_800D8FF8(), 0.0f);
    if (((FlyState561 *)param_0->kazfly)->local_0 == 0.0f && bakey_pressed(param_0, 9) &&
        func_8008D0E0(param_0) && _bafly_entrypoint_12(param_0)) {
        local_0 = 0x2A;
    }
    if (player_inWater(param_0)) {
        local_0 = 0x2D;
    }
    if (_bafly_entrypoint_2(param_0)) {
        local_0 = 1;
    }
    _baboost_entrypoint_5(param_0);
    bs_setState(param_0, local_0);
}

int bsbfly_entrypoint_1(s32 param_0)
{
  return D_80801D58_bsbfly[param_0];
}

void func_808009D0_bsbfly(u8 *param_0) {
  s8 _sfpad[8];
    s32 local_0;

    func_8009C128(param_0, &local_0);
    func_800EF04C(&local_0, (*(s32 *)((s8 *)(param_0) + (0x188))) + 0x10);
    func_800A34AC(param_0, &local_0);
    func_8009DF58(param_0, 0x40D, 0x3F800000);
}

void func_80800A24_bsbfly(PlayerState *param_0, s32 param_1)
{
    Vec3f local_0;
    void *local_1;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    switch (param_1) {
    case 0:
        func_8009E0DC(param_0);
        baflag_clear(param_0, 0x1C);
        break;
    case 1:
        baanim_playForDuration_onceSmooth(param_0, 0x43, 1.0f);
        func_8009FFD8(param_0, 1, 1, 3, 7);
        _bafly_entrypoint_1(param_0, (u8 *)param_0->kazfly + 0x10, local_0.f, 4200.0f);
        yaw_setIdeal(param_0, local_0.f[1] + 180.0f);
        func_8009BF5C(param_0, local_0.f[0]);
        baroll_setIdeal(param_0, 0.0f);
        func_8009BA9C(param_0, (u8 *)param_0->kazfly + 0x10);
        func_800A0CF4(param_0, 1);
        func_800A4DA4(param_0, 4);
        _ncbadive_entrypoint_4(func_800A4CA8(param_0), (u8 *)param_0->kazfly + 0x10);
        _ncbafly_entrypoint_5(func_800A4CA8(param_0), 1);
        func_8009DF94(param_0, 0x439, 1.0f, 28000);
        baflag_clear(param_0, 0x1C);
        func_8009C128(param_0, (u8 *)param_0->kazfly + 4);
        _chusefeather_entrypoint_1(param_0->unk184, 0);
        break;
    case 2:
        baphysics_set_type(param_0, 8);
        func_800A4DA4(param_0, 4);
        _ncbadive_entrypoint_4(func_800A4CA8(param_0), (u8 *)param_0->kazfly + 0x10);
        anctrl_setDuration(local_1, 0.05f);
        func_8009DF94(param_0, 0x4437, 1.3f, 32767);
        baflag_set(param_0, 0x1C);
        _batimer_set(param_0, 1, 0.0001f);
        break;
    case 3:
        break;
    }
    param_0->unk160.word = param_1;
}

void func_80800C38_bsbfly(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    func_800EE7F8(local_1, (f32 *)((u8 *)param_0->kazfly + 0x10));
    func_800CA9D8(func_800A4C48(param_0), local_2);
    func_800EFA4C(local_0, bastick_getX(param_0) * 1000.0f, 0.0f, 0.0f);
    func_800EF8BC(local_0, local_0, local_2[0]);
    func_800EF934(local_0, local_0, local_2[1]);
    func_800EF04C(local_1, local_0);
    func_800EFA4C(local_0, 0.0f, -bastick_getY(param_0) * 1000.0f, 0.0f);
    func_800EF8BC(local_0, local_0, local_2[0]);
    func_800EF934(local_0, local_0, local_2[1]);
    func_800EF04C(local_1, local_0);
    func_8009BA9C(param_0, local_1);
}

void func_80800D50_bsbfly(Actor *param_0)
{
    func_80800128_bsbfly();
    *(s32 *)((char *)param_0 + 0x160) = 0;
    func_80800A24_bsbfly(param_0, 1);
    return;
}

s32 func_80800D80_bsbfly(PlayerState *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;
    if (player_inWater(param_0)) { param_1 = 0x4C; }
    local_4 = player_isStable(param_0);
    if (!func_8009650C(param_0) && !local_4) { return param_1; }
    if (local_4) {
        func_800963C0(param_0, local_1);
        local_3 = func_80096628(param_0);
    } else {
        func_80096440(param_0, local_1);
        local_3 = func_80096434(param_0);
    }
    func_800EE7F8(local_2, *(u8 **)((u8 *)param_0 + 0x188) + 0x10);
    func_800EF2A0(local_2);
    local_0 = mlAbsF(func_800EEAA4(local_1, local_2));
    if (baflag_isTrue(param_0, 8) || (local_3 & 0x80)) {
        func_808009D0_bsbfly(param_0);
        param_1 = 0x18;
    } else if (local_0 > 0.4f) {
        if (local_1[1] < 0.65f) {
            func_808009D0_bsbfly(param_0);
            func_800A17A8(param_0, -1);
            param_1 = func_800A1718(param_0) ? 0x59 : 0x41;
        } else { param_1 = 0x58; }
    } else if (local_4) { param_1 = 0x58; }
    return param_1;
}

void func_80800F10_bsbfly(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    Vec3f local_2;
    s32 local_3;
    f32 local_4;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    _bafly_entrypoint_11(param_0);
    func_8009DDDC(param_0);
    local_3 = param_0->unk160.word;
    switch (local_3) {
    case 1:
        if (anctrl_isAt(local_1, 0.6905f)) {
            func_80800A24_bsbfly(param_0, 2);
        }
        break;
    case 2:
        func_80800C38_bsbfly(param_0);
        if (anctrl_isStopped(local_1)) {
            anctrl_setIndex(local_1, 0x47);
            anctrl_setDuration(local_1, 0.3f);
            anctrl_setPlaybackType(local_1, 2);
            anctrl_start(local_1);
        }
        func_8009C128(param_0, local_2.f);
        func_800EF3DC(local_2.f, (u8 *)param_0->kazfly + 4);
        local_4 = func_800EEFD4(local_2.f);
        _bafly_entrypoint_6(param_0, func_800F10B4(local_4, 0.0f, 16000000.0f, 0.2f, 0.7f));
        local_4 = func_800EEFD4(local_2.f);
        if (local_4 > 16000000.0f) {
            if (bakey_held(param_0, 9)) {
                func_80800A24_bsbfly(param_0, 3);
            } else {
                local_0 = 0x57;
            }
        }
        func_80800000_bsbfly(param_0);
        local_0 = func_80800D80_bsbfly(param_0, local_0);
        break;
    case 3:
        func_80800C38_bsbfly(param_0);
        if (bakey_released(param_0, 9)) {
            local_0 = 0x57;
        } else if (_batimer_decrement(param_0, 1)) {
            if (_bafly_entrypoint_12(param_0)) {
                _chusefeather_entrypoint_1(param_0->unk184, 0);
                _batimer_set(param_0, 1, 1.0f);
            } else {
                local_0 = 0x57;
            }
        }
        func_80800000_bsbfly(param_0);
        local_0 = func_80800D80_bsbfly(param_0, local_0);
        break;
    }
    bs_setState(param_0, local_0);
}

void func_80801138_bsbfly(s32 arg0)
{
    func_80800A24_bsbfly(arg0,0);
    func_80800188_bsbfly(arg0);
}

int bsbfly_entrypoint_2(s32 param_0)
{
  return D_80801D68_bsbfly[param_0];
}

s32 func_80801178_bsbfly(s32 param_0) {
    func_8009E0DC(param_0);
    func_8009E100(param_0);
    if (func_8009E74C(param_0, 9) != 0) {
        func_808000AC_bsbfly(param_0);
    }
    {
        s32 local_0 = bs_getNextState(param_0);
        if ((local_0 == 0x20) || (local_0 == 0x24) || (local_0 == 0x2D)) {
            s32 _t0 = param_0;
  s32 _t1 = 0x3EA;
  s32 _t2 = 0x3F800000;
  func_8009DBF0(_t0, _t1, _t2);
        }
    }
    func_80800188_bsbfly(param_0);
    func_800A0CF4(param_0, 0);
}

void func_80801208_bsbfly(PlayerState *param_0)
{
    void *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    func_8008B1C8(local_0, 0.3f);
    anctrl_setIndex(local_0, 0xCC);
    anctrl_setDuration(local_0, 0.38f);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    func_800A0CF4(param_0, 1);
    func_80800128_bsbfly((s32)param_0);
    func_80095A40(param_0);
    func_800961AC(param_0, 1);
    baroll_setIdeal(param_0, 0.0f);
    func_8009BF5C(param_0, 0.0f);
    baphysics_reset_gravity(param_0);
    baphysics_reset_terminal_velocity(param_0);
    func_80093360(param_0, 0.0f);
    func_8009DF94(param_0, 0x420, 1.0f, 0x7FFF);
    func_8009DB04(param_0, 0x444, 1.0f, 0x7FFF);
    *(f32 *)param_0->kazfly = 0.35f;
    param_0->unk160.word = 0;
}

void func_80801334_bsbfly(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];
    func_8009BB24(param_0, local_1);
    switch (param_0->unk160.word) {
    case 0:
        if (func_8008DF8C(param_0, 0x5A)) {
            baanim_playForDuration_onceSmoothStartingAt(param_0, 8, 2.0f, 0.6667f);
            param_0->unk160.word = 1;
        }
        break;
    case 1:
        break;
    }
    *(f32 *)param_0->kazfly -= func_800D8FF8();
    if (*(f32 *)param_0->kazfly < 0.0f) {
        param_0->unk15C.word = 1;
        local_0 = 0x24;
    }
    if (bainput_should_beak_bust(param_0)) local_0 = 0xF;
    if (player_isStable(param_0)) {
        func_8009FE58(param_0);
        local_0 = 0x20;
    }
    if (player_inWater(param_0)) local_0 = 0x2D;
    bs_setState(param_0, local_0);
}

int bsbfly_entrypoint_3(s32 param_0)
{
  return D_80801D78_bsbfly[param_0];
}

void func_8080145C_bsbfly(s32 param_0) {
    f32 local_0;

    for (local_0 = 0.0f; local_0 < 360.0f; local_0 += 45.0f) {
        _badust_entrypoint_5(param_0, local_0, 230.0f);
    }
}

void func_808014E8_bsbfly(PlayerState *param_0)
{
    baanim_playForDuration_onceSmooth(param_0, 0x3E, 1.4f);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    func_800A0CF4(param_0, 1);
    func_8009DF18(param_0, 0x417, 0.8f, 0x7FFF);
    func_8009D820(param_0, 1.8f);
    _bamotor_entrypoint_1(param_0, 1.0f, 0.5f, 0.5f);
    func_800A17A8(param_0, -1);
    if (!func_800A1718(param_0)) _basudie_entrypoint_1(param_0);
    func_8080145C_bsbfly(param_0);
    func_8008E944(param_0);
    *(s32 *)((u8 *)param_0 + 0x160) = 0;
}

void func_808015C4_bsbfly(param_0) PlayerState *param_0;
{
    void *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    if (anctrl_isAt(local_0, 0.3659f)) {
        func_8009DF18(param_0, 0x417, 1.0f, 0x36B0);
        func_8009DF18(param_0, 0x4454, 1.0f, 0x6D60);
    }
    if (anctrl_isAt(local_0, 0.6862f)) {
        func_8009DF18(param_0, 0x417, 0.8f, 0x4650);
        func_8009DF18(param_0, 0x427, 1.0f, 0x55F0);
    }
    if (anctrl_isAt(local_0, 0.92f)) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    }
    if (anctrl_getAnimTimer(local_0) < 0.8f) {
        _badust_entrypoint_9(param_0);
    }
}

void func_808016B4_bsbfly(u8 *param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr();
    func_8009D3A8(param_0, 0);
    local_2 = (*(s32 *)((s8 *)(param_0) + (0x160)));
    switch (local_2) {                              
    case 0:
        func_808015C4_bsbfly(param_0);
        if (anctrl_isAt(local_1, 0.2f) != 0) {
            if (func_800F8B64() != 0) {
                func_800A0180(param_0);
                func_800A4DFC(param_0, 0xA);
                _ncbadie_entrypoint_3(func_800A4CA8(param_0), 0x41F00000);
                _basudie_entrypoint_1(param_0);
                _batimer_set(param_0, 0, 3.2f);
                (*(s32 *)((s8 *)(param_0) + (0x160))) = 2;
            }
        } else if (anctrl_isAt(local_1, 0.92f) != 0) {
            baanim_playForDuration_onceSmooth(param_0, 0xD2, 2.25f);
            (*(s32 *)((s8 *)(param_0) + (0x160))) = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(local_1, 0.63f) != 0) {
            local_0 = 0x20;
        }
        if (anctrl_isStopped(local_1) != 0) {
            local_0 = 1;
        }
        if (func_8008DD04(param_0) != 0) {
            local_0 = 0x2F;
        }
        break;
    case 2:
        func_808015C4_bsbfly(param_0);
        if (_batimer_decrement(param_0, 0) != 0) {
            _basudie_entrypoint_0(param_0);
        }
        break;
    }
    bs_setState(param_0, local_0);
}

s32 func_8080183C_bsbfly(Actor *this){
    func_800A4E30(this);
    func_800A042C(this);
    func_800A0CF4(this, 0);
    func_8008E95C(this);
}

int bsbfly_entrypoint_4(s32 param_0)
{
  return D_80801D88_bsbfly[param_0];
}

int func_8080188C_bsbfly(Actor *param_0)
{
  func_80800128_bsbfly(param_0);
  _bafly_entrypoint_13(param_0, 0, 0xD3, 0x3F99999A);
  func_800A0CF4(param_0, 1);
}

int func_808018D0_bsbfly(int param_0)
{
  int new_var;
  new_var--;
 ;
  new_var = 0;
  new_var++;
  _bafly_entrypoint_14(param_0, 0x24, 2);
}

s32 func_808018F4_bsbfly(Actor *this){
    func_800A0CF4(this, 0);
    _bafly_entrypoint_15(this);
    func_80800188_bsbfly(this);
}

int bsbfly_entrypoint_5(s32 param_0)
{
  return D_80801D98_bsbfly[param_0];
}

int func_8080193C_bsbfly(Actor *param_0)
{
  func_80800128_bsbfly(param_0);
  _bafly_entrypoint_13(param_0, 1, 0xD3, 0x3F99999A);
  func_800A0CF4(param_0, 1);
}

void func_80801980_bsbfly(int param_0)
{
  short new_var;
  _bafly_entrypoint_14(param_0, 0x24, 2);
  new_var = 0;
}

s32 func_808019A4_bsbfly(Actor *this){
    func_800A0CF4(this, 0);
    _bafly_entrypoint_15(this);
    func_80800188_bsbfly(this);
}

int bsbfly_entrypoint_6(s32 param_0)
{
  return D_80801DA8_bsbfly[param_0];
}

int func_808019EC_bsbfly(s32 param_0)
{
  func_80800128_bsbfly();
  _bafly_entrypoint_16(param_0, 269, 1.0f);
}

int func_80801A1C_bsbfly(Actor *param_0)
{
  _bafly_entrypoint_17(param_0, 0x24, 0x20, (char *)param_0 + 0x15C);
}

void func_80801A44_bsbfly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_80800188_bsbfly(arg0);
}
int bsbfly_entrypoint_7(s32 param_0)
{
  return D_80801DB8_bsbfly[param_0];
}

int func_80801A80_bsbfly(Actor *param_0)
{
  s32 local_0;
  local_0 = param_0;
  func_80800128_bsbfly();
  baanim_playForDuration_loopSmooth(local_0 | 0, 0x38, 0.62f);
  func_8009FFD8(local_0 | 0, 1, 1, 3, 7);
  func_800A0CF4(local_0 | 0, 1);
  func_800A0024(local_0 | 0);
}

int func_80801AEC_bsbfly(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (anctrl_isAt(baanim_getAnimCtrlPtr(param_0), 0.1358f) != 0)
  {
    func_8009DEC0(param_0, 0x3FF, 0x3F19999A, 0x3F333333, 10000, 12000);
  }
  if (!func_8009CC68(param_0))
  {
    local_0 = 0x24;
  }
  func_800A0024(param_0);
  bs_setState(param_0, local_0);
}

void func_80801B80_bsbfly()
{
    func_80800188_bsbfly();
}

int bsbfly_entrypoint_8(s32 param_0)
{
  return D_80801DC8_bsbfly[param_0];
}

void func_80801BB4_bsbfly(Actor *param_0)
{
  s32 local_0;
  local_0 = (s32) param_0;
  switch (func_8009E6EC())
  {
    case 9:
      func_8009E830(local_0, 2);
      baflag_set(local_0, 7);
      func_800A046C(local_0);
      return;

    case 0x18:
      if (bs_getCurrentState(local_0) == 0x24)
      {
        _baboost_entrypoint_2(local_0, 6.0f);
        func_8009E830(local_0, 2);
        return;
      }
      return;

    default:
      func_80099B94(local_0);
      break;
  }
}

void func_80801C58_bsbfly(s32 param_0) {
    func_80800128_bsbfly();
    _bsdrone_entrypoint_0(param_0);
    if (_badrone_entrypoint_3(param_0) == 0xE) {
        baphysics_set_type(param_0, 7);
    }
}

void func_80801C9C_bsbfly(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void func_80801CBC_bsbfly(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800188_bsbfly(arg0);
}
int bsbfly_entrypoint_9(s32 param_0)
{
  return D_80801DD8_bsbfly[param_0];
}
