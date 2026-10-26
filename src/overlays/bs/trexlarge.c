#include "bs/trexlarge.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/anctrl.h"

extern f32 func_800962D4(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern f32 func_800F13F0(f32, f32);
extern void func_8009C128(PlayerState *, f32 *);
extern s32 func_80099B94;
extern s32 _bsdrone_entrypoint_3;
extern int bainput_should_enter_first_person(PlayerState *);
extern f32 bastick_getZonePosition(PlayerState *);
extern BsStickZoneId bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern int baanim_isStopped(PlayerState *);
extern s32 D_80801990_bstrexlarge[];
extern s32 func_8009E74C(PlayerState *, s32);
extern void func_800A4D6C(PlayerState *, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void func_8009590C(PlayerState *, f32);
extern void func_80095964(PlayerState *, s32);
extern void func_800947EC(PlayerState *, s32, s32);
extern void baphysics_reset_gravity(PlayerState *);
extern void bastick_pushZone(PlayerState *);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern int D_808019A0_bstrexlarge[];
extern int D_808019B0_bstrexlarge[];
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
typedef struct BSTREXLarge { char pad[0x15C]; char unk15B; } BSTREXLarge;
extern int D_808019C0_bstrexlarge[];
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
extern void func_8009DBB0(PlayerState *, s32, s32, s32, s32);
extern void func_8009BB24(PlayerState *, f32 *);
extern int D_808019D0_bstrexlarge[];
extern s32 D_808019E0_bstrexlarge[];
extern void _babounce_entrypoint_4(Actor *a0, int a1);
extern void _babounce_entrypoint_5(Actor *a0, int a1, int a2);
extern int D_808019F0_bstrexlarge[];
extern s32 D_80801A00_bstrexlarge[];
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern void func_8009DF18(PlayerState *, s16, f32, s16);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern void func_800E144C(s32, f32);
extern void _bamotor_entrypoint_2(PlayerState *, f32, f32, f32);
extern int D_80801A10_bstrexlarge[];
extern int D_80801A20_bstrexlarge[];
extern s32 D_80801A30_bstrexlarge[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern s32 D_80801A40_bstrexlarge[];
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_8008DAE8(PlayerState *, f32 *, f32);
extern void bs_setState(void *bs, s32 state);
extern s32 func_80092AD8(void *param_0);
extern void func_800E0AF0(void *param_0, f32 param_1);
extern f32 func_800F10B4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern void func_800E0AFC(void *param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5);
extern s32 func_800DB9B0(void);
extern s32 func_8009D2E4(void *param_0);
extern void func_8009D2D8(void *param_0, s32 param_1);
extern void func_801013A8(f32 *param_0, s32 param_1, s32 param_2);
extern s32 baanim_isAt(void *param_0, s32 param_1);
void bstrexlarge_entrypoint_2();
void bstrexlarge_entrypoint_3();
void func_80800180_bstrexlarge();

void func_80800000_bstrexlarge(void *param_0) {
    ((s32 *)param_0)[0x5A] = 5;
}

void func_8080000C_bstrexlarge(param_0) void *param_0; {
    s32 val = ((s32 *)param_0)[0x168 / 4];
    if (val > 0) {
        ((s32 *)param_0)[0x168 / 4] = val - 1;
    }
}

int func_80800024_bstrexlarge(param_0)
void *param_0;
{
  return (*((s32 *) (((char *) param_0) + 0x168))) < (1 & 0xFFFFFFFFu);
}

s32 func_80800034_bstrexlarge(void *param_0)
{
  unsigned int new_var2;
  unsigned int new_var;
  new_var2 = 0xFFu;
 if (1) { } if (1) { } if (1) { } new_var2 = 0x59; if (new_var2) { } if (1) { } do { } while (0); if (1) { }
  new_var = new_var2;
  return ((s32 *) param_0)[new_var] >= 4;
}

void func_80800044_bstrexlarge(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4;
    s32 local_5;
    f32 local_6;

    func_8009C128(param_0, local_2);
    func_80096394(param_0, local_3);
    local_0 = func_800962D4(param_0);
    local_4 = !func_80096518(param_0);
    local_1 = baphysics_get_vertical_velocity(param_0);
    local_5 = func_8009650C(param_0);
    if (local_5 && local_4 && local_0 < 70.0f && local_3[1] < 5.0f && local_1 < -100.0f) {
        local_6 = *(s32 *)((u8 *)param_0 + 0x164) + 1;
        *(s32 *)((u8 *)param_0 + 0x164) = func_800F13F0(local_6, 100.0f);
    } else {
        *(s32 *)((u8 *)param_0 + 0x164) = 0;
    }
}

int func_80800140_bstrexlarge(s32 arg0)
{
    return bakey_pressed(arg0,BUTTON_B);
}

int func_80800160_bstrexlarge(s32 arg0)
{
    return bakey_pressed(arg0,BUTTON_A);
}

void func_80800180_bstrexlarge(param_0, param_1) PlayerState *param_0; void (*param_1)(PlayerState *);
{
    switch (func_8009E6EC(param_0)) {
    case 0x20:
    case 0x21:
    case 0x2E:
    case 0x4E:
    case 0x51:
    case 0x52:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x91:
        func_8009E830(param_0, 1);
        break;
    case 0x7E:
        param_0->unk15C.bytes[1] = 2;
        break;
    default:
        param_1(param_0);
        break;
    }
}

void func_8080024C_bstrexlarge(s32 param_0) {
    func_80800180_bstrexlarge(param_0, &func_80099B94);
}

void func_80800270_bstrexlarge(s32 param_0) {
    func_80800180_bstrexlarge(param_0, &_bsdrone_entrypoint_3);
}

void func_80800294_bstrexlarge(Actor *param_0)
{
  int tmp = func_8009E6EC();
  unsigned int new_var;
  ;
  if ((((tmp == 0x1c) || (tmp == 0x1d)) || (tmp == 0x1e)) || (tmp == 0x25))
  {
    return;
  }
  func_8080024C_bstrexlarge(param_0);
}

int func_808002E0_bstrexlarge(Actor *param_0, s32 param_1, s32 param_2)
{
  s32 local_1;
  s32 local_0;
  if (param_2 != 0)
  {
    local_0 = func_80800024_bstrexlarge();
  }
  else
  {
    local_0 = 1;
  }
  switch (bastick_getZone(param_0))
  {
    case 0:
      local_1 = 0x151;
      break;

    case 1:
      local_1 = 0x152;
      break;

    case 2:
      local_1 = 0x150;
      break;
  }

  if (bs_getCurrentState(param_0) != local_1)
  {
    param_1 = local_1;
  }
  if (func_80800140_bstrexlarge(param_0) != 0)
  {
    param_1 = 0x14F;
  }
  if ((local_0 != 0) && (func_8008DD04(param_0) != 0))
  {
    param_1 = 0x14A;
  }
  if (func_80800160_bstrexlarge(param_0) != 0)
  {
    param_1 = 0x14B;
  }
  return param_1;
}

int func_808003C4_bstrexlarge(PlayerState *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (param_2) {
        local_0 = func_80800024_bstrexlarge(param_0);
    } else {
        local_0 = 1;
    }
    switch (bastick_getZone(param_0)) {
    case 0:
        break;
    case 1:
        param_1 = 0x152;
        break;
    case 2:
        param_1 = 0x150;
        break;
    }
    if (bainput_should_enter_first_person(param_0)) {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (func_80800140_bstrexlarge(param_0)) {
        param_1 = 0x14F;
    }
    if (local_0 && func_8008DD04(param_0)) {
        param_1 = 0x14A;
    }
    if (func_80800160_bstrexlarge(param_0)) {
        param_1 = 0x14B;
    }
    return param_1;
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_808004B4_bstrexlarge(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 1:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 100.0f, 400.0f));
        break;
    case 2:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 400.0f, 1000.0f));
        break;
    }
}

void bstrexlarge_entrypoint_1();

void func_80800560_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
int func_80800580_bstrexlarge(Actor *param_0)
{
  bstrexlarge_entrypoint_2();
  func_8009FFD8(param_0, 1, 3, 3, 2);
  yaw_setVelocityBounded(param_0, 3e+02f, 3.5f);
  func_80800000_bstrexlarge(param_0);
}

void func_808005D4_bstrexlarge(PlayerState *param_0)
{
    s32 local_0 = 0;

    func_8080000C_bstrexlarge(param_0);
    bstrexlarge_entrypoint_3(param_0);
    if (baanim_isStopped(param_0)) {
        local_0 = 0x151;
    }
    bs_setState(param_0, func_808003C4_bstrexlarge(param_0, local_0, 1));
}

int bstrexlarge_entrypoint_0(s32 param_0)
{
  return D_80801990_bstrexlarge[param_0];
}

void bstrexlarge_entrypoint_1(param_0)
PlayerState *param_0;
{
    if (!func_8009E74C(param_0, 0x11)) {
        bastick_popZone(param_0);
        func_800A4D6C(param_0, 1.0f, 1.0f);
        func_80092864(param_0, 1.0f);
        func_8009E474(param_0);
        func_80095A40(param_0);
        func_8009590C(param_0, 0.0f);
        baphysics_reset_gravity(param_0);
        func_80095964(param_0, 0);
        func_800947EC(param_0, 1, 0);
    }
}

void bstrexlarge_entrypoint_2(param_0)
PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 0x11)) {
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 0.6f);
        bastick_setZoneMax(param_0, 2, 1.0f);
        func_800A4D6C(param_0, 1.75f, 0.75f);
        func_80092864(param_0, 6.0f);
        func_8009E4AC(param_0);
        func_8009E55C(param_0, 0, 180.0f);
        func_8009E53C(param_0, 0, 0.0f);
        func_8009E55C(param_0, 1, 240.0f);
        func_8009E53C(param_0, 1, 0.0f);
        func_800959C8(param_0, 400.0f, 270.0f);
        func_8009590C(param_0, 400.0f);
        baphysics_set_gravity(param_0, -3000.0f);
        func_80095964(param_0, 1);
        func_800947EC(param_0, 1, 1);
        param_0->unk15C.bytes[1] = 0;
        param_0->unk15C.bytes[2] = 0;
        param_0->unk164.word = 0;
    }
}

void bstrexlarge_entrypoint_3(param_0) u8 *param_0; {
    if (param_0[0x15D]) {
        param_0[0x15D]--;
    }
}

void func_80800834_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
void func_80800854_bstrexlarge()
{
    bstrexlarge_entrypoint_2();
}

void func_80800874_bstrexlarge()
{
    bstrexlarge_entrypoint_3();
}

int bstrexlarge_entrypoint_4(int param_0)
{
  return D_808019A0_bstrexlarge[param_0];
}

void func_808008A8_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_1();
    _bsdrone_entrypoint_2(arg0);
}
void func_808008D0_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_2();
    _bsdrone_entrypoint_0(arg0);
}
void func_808008F8_bstrexlarge(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstrexlarge_entrypoint_3(arg0);
}
int bstrexlarge_entrypoint_5(int param_0)
{
  return D_808019B0_bstrexlarge[param_0];
}

void func_80800934_bstrexlarge(PlayerState *param_0, s32 param_1)
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

void func_80800A00_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
void func_80800A20_bstrexlarge(BSTREXLarge *param_0)
{
    bstrexlarge_entrypoint_2();
    param_0->unk15B = 0;
    func_80800934_bstrexlarge(param_0, 1);
}

void func_80800A50_bstrexlarge(u8 *param_0)
{
  s32 sp24;
  u8 *new_var;
  u8 temp_v0;
  sp24 = 0;
  bstrexlarge_entrypoint_3();
  func_808004B4_bstrexlarge(param_0);
 if (0) { }
  new_var = (u8 *) (((s8 *) param_0) + 0x15C);
  temp_v0 = *new_var;
  switch (temp_v0)
  {
    case 1:
      new_var = param_0;
      if (func_8008DF8C(new_var, 0x82) != 0)
    {
      func_80800934_bstrexlarge(param_0, 2);
    }
      break;

    case 2:
      func_80800044_bstrexlarge(param_0);
      if ((player_isStable(param_0) != 0) || (func_80800034_bstrexlarge(param_0) != 0))
    {
      func_800A2EAC(param_0);
      baphysics_set_target_horizontal_velocity(param_0, 0 & 0xFFFFFFFFFFFFFFFF);
      sp24 = 0x147;
    }
      break;

  }

  bs_setState(param_0, sp24);
}

int bstrexlarge_entrypoint_6(int param_0)
{
  return D_808019C0_bstrexlarge[param_0];
}

s32 bstrexlarge_entrypoint_7(PlayerState *param_0, f32 *param_1)
{
    f32 local_1;
    f32 local_0[3];

    func_8009C128(param_0, local_0);
    local_1 = func_800EFC7C(local_0, param_1);
    if (local_1 < 160000.0f) {
        return 1;
    }
    if (local_1 > 2250000.0f) {
        return 0;
    }
    if (!func_8008DAE8(param_0, param_1, 90.0f)) {
        return 0;
    }
    return 1;
}

void func_80800BC4_bstrexlarge(PlayerState *param_0, s32 param_1)
{
    AnimCtrl *local_0;
    f32 sf_t559;
    f32 sf_t461;
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
        sf_t461 = bastick_distance(param_0);
        if (sf_t461 != 0.0f) {
            sf_t559 = bastick_getAngleRelativeToBanjo(param_0);
            yaw_setIdeal(param_0, sf_t559);
        }
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        local_1 = yaw_getIdeal(param_0);
        baphysics_set_horizontal_velocity(param_0, local_1, baphysics_get_target_horizontal_velocity(param_0));
        baphysics_set_vertical_velocity(param_0, 900.0f);
        baphysics_set_gravity(param_0, -1350.0f);
        if (func_800DC0C0() > 0.5f) {
            func_8009DBB0(param_0, 0x4D8, 0x3F000000, 0x3F0CCCCD, 25000);
        } else {
            func_8009DBB0(param_0, 0x4D9, 0x3F000000, 0x3F0CCCCD, 25000);
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

void func_80800DAC_bstrexlarge(s32 arg0)
{
    func_80800BC4_bstrexlarge(arg0,0);
    bstrexlarge_entrypoint_1(arg0);
}

void func_80800DD8_bstrexlarge(Actor *param_0)
{
  char *new_var;
  new_var = ((char *) param_0) + 0x15c;
  bstrexlarge_entrypoint_2();
  *new_var = 0;
  func_80800BC4_bstrexlarge(param_0, 1);
}

void func_80800E08_bstrexlarge(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];
    bstrexlarge_entrypoint_3(param_0);
    func_8009BB24(param_0, local_1);
    if (bakey_released(param_0, 8) && local_1[1] > 0.0f) baphysics_reset_gravity(param_0);
    switch (param_0->unk15C.bytes[0]) {
    case 1:
        func_808004B4_bstrexlarge(param_0);
        if (func_8008DF8C(param_0, 0x82)) func_80800BC4_bstrexlarge(param_0, 2);
        break;
    case 2:
        func_808004B4_bstrexlarge(param_0);
        func_80800044_bstrexlarge(param_0);
        if (player_isStable(param_0) || func_80800034_bstrexlarge(param_0)) {
            func_800A2EAC(param_0);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            local_0 = 0x147;
        }
        break;
    }
    bs_setState(param_0, local_0);
}

int bstrexlarge_entrypoint_8(s32 param_0)
{
  return D_808019D0_bstrexlarge[param_0];
}

void func_80800F2C_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
void func_80800F4C_bstrexlarge()
{
    bstrexlarge_entrypoint_2();
}

void func_80800F6C_bstrexlarge()
{
    bstrexlarge_entrypoint_3();
}

int bstrexlarge_entrypoint_9(s32 param_0)
{
  return D_808019E0_bstrexlarge[param_0];
}

void func_80800FA0_bstrexlarge(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexlarge_entrypoint_1(arg0);
}
int func_80800FC8_bstrexlarge(Actor *param_0)
{
    bstrexlarge_entrypoint_2();
    _babounce_entrypoint_4(param_0, 2);
    _babounce_entrypoint_5(param_0, 0x147, 0x3F30A3D7);
}

int func_80801008_bstrexlarge(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  bstrexlarge_entrypoint_3(param_0);
  if (_babounce_entrypoint_9(param_0))
  {
    local_0 = 0x151;
  }
  bs_setState(param_0, local_0);
}

int bstrexlarge_entrypoint_10(int param_0)
{
  return D_808019F0_bstrexlarge[param_0];
}

void func_80801060_bstrexlarge(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstrexlarge_entrypoint_1(arg0);
}
void func_80801088_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_2();
    _bsrest_entrypoint_16(arg0);
}
s32 func_808010B0_bstrexlarge(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    if (_bsrest_entrypoint_20(param_0)) {
        local_0 = _bsrest_entrypoint_13(param_0);
    }
    bstrexlarge_entrypoint_3(param_0);
    bs_setState(param_0, local_0);
}

int bstrexlarge_entrypoint_11(int param_0)
{
  return D_80801A00_bstrexlarge[param_0];
}

void func_80801110_bstrexlarge(PlayerState *param_0)
{
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    param_0->unk160.word = func_800E1610(0, 30.0f, 1.0f, local_0);
    func_8009DF18(param_0, 0x56C, 1.0f, 0x7FFF);
    func_8009E5A4(param_0, 2, 1);
    func_8009E55C(param_0, 2, 600.0f);
    _bamotor_entrypoint_1(param_0, 1.0f, 1.0f, 5.0f);
}

int func_808011A8_bstrexlarge(param_0) PlayerState *param_0;
{
    if (param_0->unk160.word != -1) {
        func_800E144C(param_0->unk160.word, 0.86f);
    }
    func_8009E55C(param_0, 2, 0.0f);
    _bamotor_entrypoint_2(param_0, 1.0f, 0.1f, 0.5f);
}

int func_80801208_bstrexlarge(s32 param_0)
{
    s32 local_0;

    local_0 = func_808011A8_bstrexlarge();
    *(u8 *)(param_0 + 0x15E) = 0;
}

func_80801230_bstrexlarge(u8 *param_0){
    *(u32 *)(param_0 + 0x160) = 0xFFFFFFFF;
    param_0[0x15E] = param_0[0x15D];
}

void func_80801244_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_1();
    func_80801208_bstrexlarge(arg0);
}
int func_8080126C_bstrexlarge(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  local_0 = param_0;
  bstrexlarge_entrypoint_2();
  baanim_playForDuration_onceSmooth(local_0, 0x1D0, 0x40466666);
  func_8009FFD8(local_0, 1, 3, 8, 2);
  yaw_setVelocityBounded(local_0, 55.0f, 0.8f);
  baphysics_set_target_horizontal_velocity(local_0, 0);
  func_80801230_bstrexlarge(local_0);
}

void func_808012EC_bstrexlarge(u8 *param_0) {
    void *temp_v0;
    s32 sp40;
    f32 sp3C;
    s32 sp38;
    f32 sp34;
    f32 sp28[3];

    temp_v0 = baanim_getAnimCtrlPtr();
    sp40 = 0;
    sp3C = anctrl_getAnimTimer(temp_v0);
    bstrexlarge_entrypoint_3(param_0);
    if ((*(u8 *)((s8 *)param_0 + 0x15E)) != 0) {
        sp38 = func_80092AD8(param_0);
        func_800E0AF0((void *)sp38, 1.0f);
        sp34 = func_800F10B4(sp3C, 0.75f, 1.0f, -25.0f, 0.0f);
        func_800E0AFC((void *)sp38, 1, 1.0f, sp34, 0.0f, 0.0f);
        func_800E0AFC((void *)sp38, 0x12, 1.0f, sp34, 0.0f, 0.0f);
    }
    if ((func_800DB9B0() != 0) && (func_8009D2E4(param_0) == 8)) {
        func_8009D2D8(param_0, 2);
    }
    if ((sp3C >= 0.3f) && (sp3C <= 0.7f)) {
        func_8009C128(param_0, sp28);
        func_801013A8(sp28, 0x1B, (*(s32 *)((s8 *)param_0 + 388)));
    }
    if (baanim_isAt(param_0, 0x3E051EB8) != 0) {
        func_80801110_bstrexlarge(param_0);
    }
    if (baanim_isAt(param_0, 0x3F666666) != 0) {
        func_808011A8_bstrexlarge(param_0);
    }
    if (baanim_isStopped(param_0) != 0) {
        sp40 = 0x151;
    }
    bs_setState(param_0, sp40);
}

int bstrexlarge_entrypoint_12(int param_0)
{
  return D_80801A10_bstrexlarge[param_0];
}

void func_808014A4_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
void func_808014C4_bstrexlarge(PlayerState *param_0)
{
    bstrexlarge_entrypoint_2(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1CF, 0.7f);
    func_8009FFD8(param_0, 2, 3, 1, 14);
    yaw_setVelocityBounded(param_0, 300.0f, 3.5f);
    baanim_setDurationRange(param_0, 0.1f, 10.0f);
    func_8008C9F0(param_0, 400.0f, 1000.0f, 1.0f, 0.6f);
    func_8008CA30(param_0, 1.0f);
    func_80800000_bstrexlarge(param_0);
}

void func_80801574_bstrexlarge(s32 param_0) {
    func_8080000C_bstrexlarge(param_0);
    bstrexlarge_entrypoint_3(param_0);
    func_808004B4_bstrexlarge(param_0);
    func_800A2D2C(param_0, 0x3F11F8A1, 3);
    func_800A2D2C(param_0, 0x3D8FC505, 4);
    bs_setState(param_0, func_808002E0_bstrexlarge(param_0, 0, 1));
}

int bstrexlarge_entrypoint_13(int param_0)
{
  return D_80801A20_bstrexlarge[param_0];
}

void func_80801604_bstrexlarge(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bstrexlarge_entrypoint_1(arg0);
}

void func_80801634_bstrexlarge(s32 param_0) {
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  bstrexlarge_entrypoint_2();
  baanim_playForDuration_loopSmooth(param_0, 0x1D2, 8.5f);
  func_8009FFD8(param_0, 1, 3, 2, 2);
  yaw_setVelocityBounded(param_0, 3e+02f, 3.5f);
  baphysics_set_target_horizontal_velocity(param_0, 0);
  func_800909CC(param_0);
  func_80800000_bstrexlarge(param_0);
}

void func_808016B4_bstrexlarge(s32 param_0) {
    func_8080000C_bstrexlarge();
    bstrexlarge_entrypoint_3(param_0);
    if (baanim_isAt(param_0, 0x3DC28F5C) != 0) {
        func_8009DF18(param_0, 0x570, 0.9f, 0x4650);
    }
    if (baanim_isAt(param_0, 0x3F0B851F) != 0) {
        func_8009DEC0(param_0, 0x56F, 0x3F666666, 0x3F8CCCCD, 0x4E20, 0x55F0);
    }
    if (baanim_isAt(param_0, 0x3F51EB85) != 0) {
        func_8009DF18(param_0, 0x570, 0.9f, 0x4E20);
    }
    if (baanim_isAt(param_0, 0x3F6B851F) != 0) {
        func_8009DF18(param_0, 0x570, 1.0f, 0x32C8);
    }
    func_808004B4_bstrexlarge(param_0);
    bs_setState(param_0, func_808003C4_bstrexlarge(param_0, 0, 1));
}

int bstrexlarge_entrypoint_14(s32 param_0)
{
  return D_80801A30_bstrexlarge[param_0];
}

void func_808017DC_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
void func_808017FC_bstrexlarge(PlayerState *param_0)
{
    bstrexlarge_entrypoint_2(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1CE, 1.2f);
    func_8009FFD8(param_0, 2, 3, 1, 14);
    yaw_setVelocityBounded(param_0, 3e+02f, 3.5f);
    baanim_setDurationRange(param_0, 0.1f, 10.0f);
    func_8008C9F0(param_0, 100.0f, 400.0f, 1.5f, 1.0f);
    func_8008CA30(param_0, 1.0f);
    func_80800000_bstrexlarge(param_0);
}

int func_808018AC_bstrexlarge(Actor *param_0)
{
  Actor *local_0;
  local_0 = param_0;
  func_8080000C_bstrexlarge(local_0);
  bstrexlarge_entrypoint_3(local_0);
  func_808004B4_bstrexlarge(local_0);
  func_800A2D2C(local_0, 0x3F65CFAB, 3);
  func_800A2D2C(local_0, 0x3ECB9F56, 4);
  bs_setState(local_0, func_808002E0_bstrexlarge(local_0, 0, 1) | 0);
}

int bstrexlarge_entrypoint_15(int param_0)
{
  return D_80801A40_bstrexlarge[param_0];
}
