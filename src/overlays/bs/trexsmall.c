#include "bs/trexsmall.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/anctrl.h"
#include "overlays/ba/playerstate.h"
extern void _badust_entrypoint_5(s32, f32, f32);

extern s32 func_800C2FDC(u8);
extern u8 D_80801AF0_bstrexsmall[];
typedef struct { u8 pad_0[0x15E]; u8 local_0; u8 pad_1; u8 local_1; } TrexSmallState;
extern s32 bastick_getZone();
extern f32 bastick_getZonePosition(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_8009D3A8(PlayerState *, s32);
extern int baanim_isStopped(PlayerState *);
extern int D_80801B08_bstrexsmall[];
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_80092864(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009590C(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void _basudie_entrypoint_3(PlayerState *, f32, f32, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void func_8009D820(PlayerState *, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern f32 func_800F0E00(f32, f32);
extern int D_80801B18_bstrexsmall[];
extern s32 D_80801B28_bstrexsmall[];
extern s32 D_80801B38_bstrexsmall[];
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 func_800DC0C0(void);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8009DBB0(PlayerState *, s32, f32, f32, s32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 D_80801B48_bstrexsmall[];
extern s32 D_80801B58_bstrexsmall[];
extern int D_80801B68_bstrexsmall[];
extern s32 D_80801B78_bstrexsmall[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern int bakey_newlyReleased(PlayerState *, ButtonId);
extern int bs_setState(PlayerState *, s32);
extern int baanim_isAt(PlayerState *, int);
extern int D_80801B88_bstrexsmall[];
extern int D_80801B98_bstrexsmall[];
extern s32 D_80801BA8_bstrexsmall[];
extern s32 D_80801BB8_bstrexsmall[];
extern void func_800C3058();
extern s32 func_800C3920(u8, s32, void *);
extern f32 func_800D8FF8(void);
extern s32 func_800F0E28(s32, s32);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_8008DAE8(PlayerState *, f32 *, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
void bstrexsmall_entrypoint_2();
void bstrexsmall_entrypoint_3();

int func_80800000_bstrexsmall(u8 *param_0) {
    return bakey_pressed(param_0, 9) && func_800C6E38(0x20);
}

int func_8080003C_bstrexsmall(PlayerState* arg0)
{
    return bakey_pressed(arg0, BUTTON_A);
}

void func_8080005C_bstrexsmall()
{
    func_80099B94();
}

int func_8080007C_bstrexsmall(Actor *param_0)
{
  switch (func_8009E6EC())
  {
    case 0x1C :
    case 0x1D :
    case 0x1E :
    case 0x25 :
      break;

    default :
      func_80099B94(param_0);

  }

}

void func_808000C8_bstrexsmall(PlayerState *param_0, s32 param_1)
{
    TrexSmallState *local_0 = (TrexSmallState *)param_0;
    if (local_0->local_0 == 0) local_0->local_1 = 0;
    local_0->local_0 = param_1;
    switch (param_1) {
    case 0:
    case 1:
        if (local_0->local_1) {
            func_800C2FDC(local_0->local_1);
            local_0->local_1 = 0;
        }
        break;
    case 2:
        local_0->local_1 = func_8009D454(param_0, 0, D_80801AF0_bstrexsmall);
        break;
    }
}

s32 func_80800154_bstrexsmall(Actor *param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_1 = bastick_getZone();
    switch (local_1) {
    case 0:
        local_0 = 0x145;
        break;
    case 1:
        local_0 = 0x146;
        break;
    case 2:
        local_0 = 0x144;
        break;
    }
    if (bs_getCurrentState(param_0) != local_0) {
        param_1 = local_0;
    }
    if (func_80800000_bstrexsmall(param_0) != 0) {
        param_1 = 0x143;
    }
    if (func_8008DD04(param_0) != 0) {
        param_1 = 0x13E;
    }
    if (func_8080003C_bstrexsmall(param_0) != 0) {
        param_1 = 0x13F;
    }
    return param_1;
}

int func_8080020C_bstrexsmall(PlayerState *param_0, s32 param_1)
{
    switch (bastick_getZone(param_0)) {
        case 0: break;
        case 1: param_1 = 0x146; break;
        case 2: param_1 = 0x144; break;
    }
    if (bainput_should_enter_first_person(param_0)) {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (func_80800000_bstrexsmall(param_0)) {
        param_1 = 0x143;
    }
    if (func_8008DD04(param_0)) {
        param_1 = 0x13E;
    }
    if (func_8080003C_bstrexsmall(param_0)) {
        param_1 = 0x13F;
    }
    return param_1;
}

void func_808002B8_bstrexsmall(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 1:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 100.0f, 300.0f));
        break;
    case 2:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 300.0f, 600.0f));
        break;
    }
}

void bstrexsmall_entrypoint_1();

void func_80800364_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_80800384_bstrexsmall(Actor *this)
{
  bstrexsmall_entrypoint_2();
  func_8009FFD8(this, 1, 3, 3, 2);
  yaw_setVelocityBounded(this, 5e+02f, 6.5f);
}

void func_808003D0_bstrexsmall(PlayerState *param_0)
{
    s32 local_0 = 0;

    func_8009D3A8(param_0, 0);
    bstrexsmall_entrypoint_3(param_0);
    if (baanim_isStopped(param_0)) {
        local_0 = 0x145;
    }
    bs_setState(param_0, func_8080020C_bstrexsmall(param_0, local_0));
}

int bstrexsmall_entrypoint_0(int param_0)
{
  return D_80801B08_bstrexsmall[param_0];
}

void bstrexsmall_entrypoint_1(param_0) s32 param_0;
{
  unsigned long long new_var;
  if (func_8009E74C(param_0, 0x10) == 0)
  {
    func_808000C8_bstrexsmall(param_0, 0);
    bastick_popZone(param_0);
    param_0 += 0;
    func_80092864(param_0, 1.0f);
    func_8009E474(param_0);
    new_var = 0;
    func_80095A40(param_0);
    func_8009590C(param_0, 0);
    baphysics_reset_gravity(param_0);
    func_800947EC(param_0, 1, 0);
  }
}

void bstrexsmall_entrypoint_2(param_0)
PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 0x10)) {
        *((u8 *)param_0 + 0x15E) = 0;
        func_808000C8_bstrexsmall(param_0, 1);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 0.6f);
        bastick_setZoneMax(param_0, 2, 1.0f);
        func_80092864(param_0, 1.5f);
        func_8009E4AC(param_0);
        func_8009E55C(param_0, 0, 70.0f);
        func_8009E53C(param_0, 0, 0.0f);
        func_8009E55C(param_0, 1, 80.0f);
        func_8009E53C(param_0, 1, 0.0f);
        func_800959C8(param_0, 100.0f, 56.0f);
        func_8009590C(param_0, 125.0f);
        baphysics_set_gravity(param_0, -3000.0f);
        func_800947EC(param_0, 1, 1);
    }
}

void bstrexsmall_entrypoint_3(param_0) u8 *param_0;
{
    s32 pad[2];
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_2 = param_0[0x160];
    if (local_2 != 0 && param_0[0x15E] == 3) {
        local_0 = func_800C3920(local_2, local_2, param_0);
        local_1 = func_800F0E28(0, (f32)local_0 - func_800D8FF8() * 60000.0f);
        if (local_1 != 0) {
            func_800C3058(param_0[0x160], local_1);
        } else {
            func_808000C8_bstrexsmall(param_0, 1);
        }
    }
}

void func_80800680_bstrexsmall(s32 param_0) {
    f32 local_0;

    for (local_0 = 0.0f; local_0 < 360.0f; local_0 += 45.0f) {
        _badust_entrypoint_5(param_0, local_0, 2.3e+02f);
    }
}

void func_8080070C_bstrexsmall(s32 param_0) {
    _basudie_entrypoint_6();
    func_8009BF5C(param_0, 0);
    baroll_setIdeal(param_0, 0);
}

void func_80800744_bstrexsmall(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk16C = 250.0f;
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x148);
    anctrl_setSubrange(local_0, 0.0f, 0.12f);
    anctrl_setDuration(local_0, 4.5f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    _basudie_entrypoint_3(param_0, param_0->unk16C, 800.0f, -2400.0f, 10.0f);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    func_8009D820(param_0, 1.4f);
    param_0->unk15C.bytes[0] = 0;
}

void func_80800818_bstrexsmall(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    _basudie_entrypoint_5(param_0);
    baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
    switch (param_0->unk15C.bytes[0]) {
    case 3:
        break;
    case 0:
        if (func_8008DF8C(param_0, 0x5A)) param_0->unk15C.bytes[0] = 1;
        break;
    case 1:
        if (player_isStable(param_0)) {
            func_8009DF18(param_0, 0x428, 1.0f, 0x4650);
            _bamotor_entrypoint_1(param_0, 1.0f, 1.0f, 0.4f);
            func_80800680_bstrexsmall(param_0);
            func_8009E058(param_0);
            baanim_setEndAndDuration(param_0, 0.6f, 2.5f);
            param_0->unk15C.bytes[0] = 2;
        }
        break;
    case 2:
        param_0->unk16C = func_800F0E00(param_0->unk16C - 7.0f, 0.0f);
        if (param_0->unk16C > 140.0f) _badust_entrypoint_9(param_0);
        if (anctrl_isStopped(local_0)) {
            baanim_setEnd(param_0, 1.0f);
            param_0->unk15C.bytes[0] = 3;
            param_0->unk16C = 0.0f;
        }
        break;
    }
    bs_setState(param_0, 0);
}

int bstrexsmall_entrypoint_4(int param_0)
{
  return D_80801B18_bstrexsmall[param_0];
}

void func_80800998_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_1();
    _bsdrone_entrypoint_2(arg0);
}
void func_808009C0_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_2();
    _bsdrone_entrypoint_0(arg0);
}
void func_808009E8_bstrexsmall(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstrexsmall_entrypoint_3(arg0);
}
int bstrexsmall_entrypoint_5(s32 param_0)
{
  return D_80801B28_bstrexsmall[param_0];
}

void func_80800A24_bstrexsmall(PlayerState *param_0, s32 param_1)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    switch (param_1) {
        case 1:
            anctrl_reset(local_0);
            anctrl_setIndex(local_0, 0x1D1);
            anctrl_setDuration(local_0, 4.0f);
            anctrl_setSubrange(local_0, 0.0f, 0.715f);
            anctrl_setPlaybackType(local_0, 1);
            anctrl_setStart(local_0, 0.45f);
            anctrl_start(local_0);
            break;
        case 2:
            baanim_setEndAndDuration(param_0, 1.0f, 0.8f);
            break;
    }
    param_0->unk15C.bytes[0] = param_1;
}

void func_80800AF0_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_80800B10_bstrexsmall(Actor *param_0)
{
  bstrexsmall_entrypoint_2();
  ((char*)param_0)[0x15C] = 0;
  func_80800A24_bstrexsmall(param_0, 1);
}

void func_80800B40_bstrexsmall(PlayerState *param_0)
{
    int local_0;

    local_0 = 0;
    bstrexsmall_entrypoint_3(param_0);
    func_808002B8_bstrexsmall(param_0);
    switch (param_0->unk15C.bytes[0]) {
    case 1:
        if (func_8008DF8C(param_0, 0x82)) {
            func_80800A24_bstrexsmall(param_0, 2);
        }
        break;
    case 2:
        func_8009D3A8(param_0, 0);
        if (player_isStable(param_0)) {
            func_800A2E18(param_0);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            local_0 = 0x13B;
        }
        break;
    }
    bs_setState(param_0, local_0);
}

int bstrexsmall_entrypoint_6(s32 param_0)
{
  return D_80801B38_bstrexsmall[param_0];
}

s32 bstrexsmall_entrypoint_7(PlayerState *param_0, f32 *param_1)
{
    f32 local_1;
    f32 local_0[3];

    func_8009C128(param_0, local_0);
    local_1 = func_800EFC7C(local_0, param_1);
    if (local_1 < 40000.0f) {
        return 1;
    }
    if (local_1 > 250000.0f) {
        return 0;
    }
    if (!func_8008DAE8(param_0, param_1, 90.0f)) {
        return 0;
    }
    return 1;
}

void func_80800CA4_bstrexsmall(PlayerState *param_0, s32 param_1)
{
    AnimCtrl *local_0;
    s32 pad;
    f32 local_2;
    f32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk15C.bytes[0] = param_1;
    switch (param_1) {
    case 1:
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 0x1D1);
        anctrl_setDuration(local_0, 2.2f);
        anctrl_setSubrange(local_0, 0.0f, 0.715f);
        anctrl_setPlaybackType(local_0, 1);
        anctrl_setStart(local_0, 0.194f);
        anctrl_start(local_0);
        func_8009FFD8(param_0, 1, 1, 3, 6);
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        }
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        local_1 = yaw_getIdeal(param_0);
        local_2 = baphysics_get_target_horizontal_velocity(param_0);
        baphysics_set_horizontal_velocity(param_0, local_1, local_2);
        baphysics_set_vertical_velocity(param_0, 1100.0f);
        baphysics_set_gravity(param_0, -1800.0f);
        if (func_800DC0C0() > 0.5f) {
            func_8009DBB0(param_0, 0x4D8, 1.3f, 1.35f, 22000);
        } else {
            func_8009DBB0(param_0, 0x4D9, 1.3f, 1.35f, 22000);
        }
        break;
    case 2:
        baanim_setEndAndDuration(param_0, 1.0f, 0.8f);
        break;
    case 0:
        baphysics_set_gravity(param_0, -3000.0f);
        break;
    }
}

void func_80800E94_bstrexsmall(s32 arg0)
{
    func_80800CA4_bstrexsmall(arg0,0);
    bstrexsmall_entrypoint_1(arg0);
}

void func_80800EC0_bstrexsmall(Actor *param_0)
{
  bstrexsmall_entrypoint_2();
  ((char*)param_0)[0x15C] = 0;
  func_80800CA4_bstrexsmall(param_0, 1);
}

void func_80800EF0_bstrexsmall(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];

    bstrexsmall_entrypoint_3(param_0);
    func_8009BB24(param_0, local_1);
    if (bakey_released(param_0, 8) && local_1[1] > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    switch (*((u8 *)param_0 + 0x15C)) {
        case 1:
            func_808002B8_bstrexsmall(param_0);
            if (func_8008DF8C(param_0, 0x82)) {
                func_80800CA4_bstrexsmall(param_0, 2);
            }
            break;
        case 2:
            func_8009D3A8(param_0, 0);
            func_808002B8_bstrexsmall(param_0);
            if (player_isStable(param_0)) {
                func_800A2E18(param_0);
                baphysics_set_target_horizontal_velocity(param_0, 0.0f);
                local_0 = 0x13B;
            }
            break;
    }
    bs_setState(param_0, local_0);
}

int bstrexsmall_entrypoint_8(s32 param_0)
{
  return D_80801B48_bstrexsmall[param_0];
}

void func_80801004_bstrexsmall(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexsmall_entrypoint_1(arg0);
}
int func_8080102C_bstrexsmall(Actor *param_0)
{
  bstrexsmall_entrypoint_2(param_0);
  _babounce_entrypoint_4(param_0, 1);
  _babounce_entrypoint_5(param_0, 0x147, 0x3F30A3D7);
}

int func_8080106C_bstrexsmall(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  bstrexsmall_entrypoint_3(param_0);
  if (baanim_isAt(param_0, 0x3F000000) != 0)
  {
    func_800951B4(param_0);
  }
  if (_babounce_entrypoint_9(param_0) != 0)
  {
    local_0 = 0x145;
  }
  return bs_setState(param_0, local_0);
}

int bstrexsmall_entrypoint_9(s32 param_0)
{
  return D_80801B58_bstrexsmall[param_0];
}

void func_808010E8_bstrexsmall(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexsmall_entrypoint_1(arg0);
}
int func_80801110_bstrexsmall(Actor *param_0)
{
  Actor *local_0;
  local_0 = param_0;
  bstrexsmall_entrypoint_2(local_0);
  _babounce_entrypoint_4(param_0, 2);
  _babounce_entrypoint_5(param_0, 0x147, 0x3F30A3D7);
}

s32 func_80801150_bstrexsmall(s32 param_0) {
    s32 local_0 = 0;

    bstrexsmall_entrypoint_3(param_0);
    if (_babounce_entrypoint_9(param_0)) {
        local_0 = 0x145;
    }
    bs_setState(param_0, local_0);
}

int bstrexsmall_entrypoint_10(int param_0)
{
  return D_80801B68_bstrexsmall[param_0];
}

void func_808011A8_bstrexsmall(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstrexsmall_entrypoint_1(arg0);
}
void func_808011D0_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_2();
    _bsrest_entrypoint_16(arg0);
}
int func_808011F8_bstrexsmall(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 = _bsrest_entrypoint_13(param_0);
  }
  bstrexsmall_entrypoint_3(param_0);
  bs_setState(param_0, local_0);
}

int bstrexsmall_entrypoint_11(int param_0)
{
  return D_80801B78_bstrexsmall[param_0];
}

int func_80801258_bstrexsmall(param_0, param_1) Actor *param_0; s32 param_1;
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  func_801013A8(local_0, param_1, *(s32*)((char*)param_0 + 0x184));

}

int func_80801294_bstrexsmall(PlayerState *param_0, s32 param_1)
{
    switch (((u8 *)param_0)[0x15C]) {
        case 2:
            func_80801258_bstrexsmall(param_0, 0x1D, param_1);
            break;
        case 3:
            func_80801258_bstrexsmall(param_0, 0x1E, param_1);
            break;
    }
    ((u8 *)param_0)[0x15C] = param_1;
    switch (param_1) {
        case 0:
            func_808000C8_bstrexsmall(param_0, 3);
            break;
        case 1:
            bstrexsmall_entrypoint_2(param_0);
            baanim_playForDuration_onceSmooth(param_0, 0x1D0, 3.1f);
            func_8009FFD8(param_0, 1, 3, 8, 2);
            yaw_setVelocityBounded(param_0, 55.0f, 0.8f);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            ((u8 *)param_0)[0x15D] = 1;
            break;
        case 2:
            anctrl_setSubrange(baanim_getAnimCtrlPtr(param_0), 0.0f, 0.29f);
            break;
        case 3:
            anctrl_setSubrange(baanim_getAnimCtrlPtr(param_0), 0.0f, 0.49f);
            break;
    }
}

s32 func_808013E8_bstrexsmall(s32 param_0){
    bstrexsmall_entrypoint_1();
    func_80801294_bstrexsmall(param_0, 0);
}

s32 func_80801414_bstrexsmall(s32 param_0) {
    s32 result;
  *(u8 *)((char *)(param_0) + 0x15C) = 0;


    result = func_80801294_bstrexsmall(param_0, 1);
    return result;
}

void func_80801438_bstrexsmall(PlayerState *param_0)
{
    s32 sp24;
    u8 temp_v0;

    sp24 = 0;
    bstrexsmall_entrypoint_3(param_0);
    if ((func_800DB9B0() != 0) && (func_8009D2E4(param_0) == 8)) {
        func_8009D2D8(param_0, 2);
    }
    temp_v0 = (*(u8 *)((s8 *)(param_0) + (0x15C)));
    switch (temp_v0) {                              
    case 1:
        if (baanim_isAt(param_0, 0x3E051EB8) != 0) {
            func_808000C8_bstrexsmall(param_0, 2);
        }
        if (bakey_newlyReleased(param_0, 9) != 0) {
            (*(u8 *)((s8 *)(param_0) + (0x15D))) = 0U;
        }
        if (baanim_isAt(param_0, 0x3E4CCCCD) != 0) {
            if ((*(u8 *)((s8 *)(param_0) + (0x15D))) != 0) {
                func_80801294_bstrexsmall(param_0, 3);
            } else {
                func_80801294_bstrexsmall(param_0, 2);
            }
        }
        break;
    case 2:
        if (baanim_isAt(param_0, 0x3E800000) != 0) {
            func_808000C8_bstrexsmall(param_0, 3);
        }
        if (baanim_isStopped(param_0) != 0) {
            sp24 = 0x145;
        }
        break;
    case 3:
        if (baanim_isAt(param_0, 0x3EE66666) != 0) {
            func_808000C8_bstrexsmall(param_0, 3);
        }
        if (baanim_isStopped(param_0) != 0) {
            sp24 = 0x145;
        }
        break;
    }
    bs_setState(param_0, sp24);
}

int bstrexsmall_entrypoint_12(int param_0)
{
  return D_80801B88_bstrexsmall[param_0];
}

void func_808015BC_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_808015DC_bstrexsmall(PlayerState *param_0)
{
    bstrexsmall_entrypoint_2(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1CF, 0.7f);
    func_8009FFD8(param_0, 2, 3, 1, 2);
    yaw_setVelocityBounded(param_0, 500.0f, 6.5f);
    baanim_setDurationRange(param_0, 0.1f, 10.0f);
    func_8008C9F0(param_0, 300.0f, 600.0f, 0.86f, 0.48f);
    func_8008CA30(param_0, 1.0f);
}

void func_80801688_bstrexsmall(s32 param_0)
{
    bstrexsmall_entrypoint_3();
    func_808002B8_bstrexsmall(param_0);
    func_8009D3A8(param_0, 0);
    func_800A2CE8(param_0, 0x3F11F8A1, 3);
    func_800A2CE8(param_0, 0x3D8FC505, 4);
    bs_setState(param_0, func_80800154_bstrexsmall(param_0, 0));
}

int bstrexsmall_entrypoint_13(int param_0)
{
  return D_80801B98_bstrexsmall[param_0];
}

void func_80801718_bstrexsmall(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bstrexsmall_entrypoint_1(arg0);
}

void func_80801748_bstrexsmall(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    bstrexsmall_entrypoint_2(param_0);
    local_1 = bs_getPreviousState(param_0) == 0x143 ? 0.5f : 0.2f;
    anctrl_reset(local_0);
    func_8008B1C8(local_0, local_1);
    anctrl_setIndex(local_0, 0x1D2);
    anctrl_setDuration(local_0, 8.5f);
    anctrl_setStart(local_0, 0.13f);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 3, 2, 2);
    yaw_setVelocityBounded(param_0, 500.0f, 6.5f);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_800909CC(param_0);
}

void func_80801844_bstrexsmall(s32 param_0) {
    s32 local_0;
    local_0 = param_0;
    func_8009D3A8(param_0, 0);
    bstrexsmall_entrypoint_3(param_0);
    if (baanim_isAt(local_0, 0x3DC28F5C) != 0) {
        func_8009DF18(local_0, 0x570, 1.2f, 0x4650);
    }
    if (baanim_isAt(local_0, 0x3F0B851F) != 0) {
        func_8009DEC0(local_0, 0x56F, 0x3F99999A, 0x3FB33333, 0x4E20, 0x55F0);
    }
    if (baanim_isAt(local_0, 0x3F51EB85) != 0) {
        func_8009DF18(local_0, 0x570, 1.2f, 0x4E20);
    }
    if (baanim_isAt(local_0, 0x3F6B851F) != 0) {
        func_8009DF18(local_0, 0x570, 1.3f, 0x32C8);
    }
    func_808002B8_bstrexsmall(local_0);
    bs_setState(local_0, func_8080020C_bstrexsmall(local_0, 0));
}

int bstrexsmall_entrypoint_14(s32 param_0)
{
  return D_80801BA8_bstrexsmall[param_0];
}

void func_80801970_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_80801990_bstrexsmall(PlayerState *param_0)
{
    bstrexsmall_entrypoint_2(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1CE, 1.2f);
    func_8009FFD8(param_0, 2, 3, 1, 2);
    yaw_setVelocityBounded(param_0, 500.0f, 6.5f);
    baanim_setDurationRange(param_0, 0.1f, 10.0f);
    func_8008C9F0(param_0, 100.0f, 300.0f, 1.15f, 0.61f);
    func_8008CA30(param_0, 1.0f);
}

int func_80801A3C_bstrexsmall(Actor *param_0)
{
  Actor *local_0;
  local_0 = param_0;
  bstrexsmall_entrypoint_3(local_0);
  func_808002B8_bstrexsmall(local_0);
  func_8009D3A8(local_0, 0);
  func_800A2CE8(local_0, 0x3F65CFAB, 3);
  func_800A2CE8(local_0, 0x3ECB9F56, 4);
  bs_setState(local_0, func_80800154_bstrexsmall(local_0, 0));
}

int bstrexsmall_entrypoint_15(s32 param_0)
{
  return D_80801BB8_bstrexsmall[param_0];
}
