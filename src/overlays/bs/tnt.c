#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/anctrl.h"
void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

extern u8 D_80802230_bstnt[];
extern s32 func_8009D454();
extern f32 _batimer_get(PlayerState *, s32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void _bapulse_entrypoint_3(PlayerState *, f32, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_8080223C_bstnt;
extern u8 D_80802284_bstnt;
extern s32 D_808022FC_bstnt;
extern void func_800EE7F8(f32 *);
extern s32 func_800A4C48(s32);
extern void func_800CA3F4(s32, f32 *, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern s32 D_80802328_bstnt;
extern s32 D_808023C8_bstnt;
extern f32 func_800F0E00(f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_80092BE8(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void func_8009328C(PlayerState *, f32);
extern s32 D_808023F8_bstnt[];
extern s32 D_80802408_bstnt[];
extern void func_80092864(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern f32 _bapulse_entrypoint_1(PlayerState *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 D_80802418_bstnt;
extern s32 D_8080246C_bstnt;
extern s32 D_808024B8_bstnt;
extern s32 D_80802504_bstnt;
extern s32 D_8080254C_bstnt[];
extern s32 D_8080255C_bstnt[];
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern void baanim_setEnd(PlayerState *, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 D_8080256C_bstnt[];
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern s32 D_8080257C_bstnt[];
typedef struct bstnt_struct { char pad[0x15C]; int unk15C; } BSTNT;
extern s32 D_8080258C_bstnt[];
extern s32 D_8080259C_bstnt[];
extern s32 D_808025AC_bstnt[];
extern s32 D_808025BC_bstnt[];
extern s32 D_808025CC_bstnt[];
extern u8 D_808022CC_bstnt[];
extern s32 func_800B5BE4(s32);
extern void func_800BABB8(s32, void *, s32, f32, void *);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA5BC(s32, f32, f32);
extern void func_800BA994();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 baanim_getTimer(PlayerState *);
extern int baanim_isAt(PlayerState *, f32);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern f32 func_800136E4(f32);
extern f32 func_800D8FF8(void);
void bstnt_entrypoint_4();
int bstnt_entrypoint_8();
void func_8080030C_bstnt();
void func_80801980_bstnt();

void func_80800000_bstnt(s32 param_0) {
    func_8009DF94(param_0, 0x504, 0x3F800000, 0x7FFF);
}

void func_80800028_bstnt(param_0) u8 *param_0;
{
  unsigned int temp_a1;
  temp_a1 = *((u8 *) (((u8 *) param_0) + 0x160));
  if (temp_a1 != 0)
  {
    func_800C2FDC(temp_a1 & 0xFF, temp_a1, param_0);
  }
  *((u8 *) (((u8 *) param_0) + 0x160)) = 0U;
}

void func_80800060_bstnt(arg0) s32 arg0; 
{
}
void func_80800068_bstnt(u8 *param_0) {
    param_0[0x160] = func_8009D454(param_0, 0, D_80802230_bstnt);
}

void func_8080009C_bstnt(u8 *param_0)
{
  u8 temp_a1;
  temp_a1 = *((u8 *) (((s8 *) param_0) + 0x160));
  if (temp_a1 != 0)
  {
    if ((temp_a1 && temp_a1) && temp_a1)
    {
    }
    func_800C2FDC(temp_a1 & 0xFF, temp_a1, param_0);
  }
  *((u8 *) (((s8 *) param_0) + 0x160)) = 0U;
}

extern void func_80800164_bstnt(PlayerState *);

void func_808000D4_bstnt(PlayerState *param_0, f32 param_1)
{
    if (_batimer_get(param_0, 2) == 0.0f) {
        _bapulse_entrypoint_3(param_0, 0.0f, 0.15f);
        func_80092744(param_0, 1);
        func_80092750(param_0, 255, 255, 255, 255);
    }
    _batimer_set(param_0, 2, param_1);
}


void func_80800164_bstnt(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 600.0f));
    }
}

s32 func_808001C8_bstnt(s32 param_0, s32 param_1) {
    if (bakey_pressed(param_0, 8)) {
        param_1 = 0x107;
    }
    if (bstnt_entrypoint_8(param_0)) {
        param_1 = 0x10E;
    }
    return param_1;
}

s32 func_80800218_bstnt(u8 *param_0, s32 param_1)
{
    s32 local_0;

    local_0 = param_1;
    if (bainput_should_enter_first_person() != 0) {
        local_0 = _badrone_entrypoint_24(param_0);
    }
    if (bakey_pressed(param_0, 8) != 0) {
        local_0 = 0x107;
    }
    if (bstnt_entrypoint_8(param_0) != 0) {
        local_0 = 0x10E;
    }
    if ((*(u8*)((char*)param_0 + 0x168) != 0) && (player_isStable(param_0) != 0)) {
        local_0 = 0x10D;
    }
    return local_0;
}

void func_808002AC_bstnt(s32 param_0, s32 param_1)
{
    func_800BBCB8(param_1 | 0, 0, 1.0f, 8, &D_8080223C_bstnt);
    func_800BBCB8(param_1, 0, 1.0f, 0xC, &D_80802284_bstnt);
}

void func_8080030C_bstnt(param_0, param_1) void *param_0; void *param_1;
{
    f32 local_3;
    f32 local_0[3];
    f32 local_4;
    s32 local_1;
    s32 local_2;
    s32 local_5;

    local_1 = func_800B5BE4(8);
    func_800BABB8(local_1, param_1, 0, 1.0f, D_808022CC_bstnt);
    local_3 = 0.43f;
    func_800BA8F8(local_1, local_3, local_3);
    local_4 = 19.0f / local_3;
    func_800BA5BC(local_1, local_4, local_4);
    for (local_2 = 0; local_2 != 360; local_2 += 45) {
        func_800EFA4C(&local_0, 0.0f, local_2, 480.0f);
        func_800BA994(local_1, (s16)local_0[0], (s16)local_0[1], (s16)local_0[2],
            (s16)local_0[0], (s16)local_0[1], (s16)local_0[2]);
        func_800BA22C(local_1, 1);
        func_800EFA4C(&local_0, -45.0f, local_2, 430.0f);
        func_800BA994(local_1, (s16)local_0[0], (s16)local_0[1], (s16)local_0[2],
            (s16)local_0[0], (s16)local_0[1], (s16)local_0[2]);
        func_800BA22C(local_1, 1);
    }
}

void func_808004F8_bstnt(param_0) s32 param_0; {
    f32 local_0[3];
    func_800EE7F8(local_0);
    func_800CA3F4(func_800A4C48(param_0), local_0, 80.0f);
    func_800BBCB8(local_0, 0, 1.0f, 1, &D_808022FC_bstnt);
}

void func_80800554_bstnt(s32 param_0) {
  s8 _sfpad[8];
    s32 local_0;
    s32 local_1;
    s32 local_2;

    func_8009C128(param_0, &local_0);
    func_800CA3F4(func_800A4C48(param_0), &local_0, 2e+01f);
    local_2 = func_800B5BE4(8);
    local_1 = local_2;
    func_800BABB8(local_2, &local_0, 0, 1.0f, &D_80802328_bstnt);
    func_800CA3F4(func_800A4C48(param_0), &local_0, 45.0f);
    func_800BABB8(local_1, &local_0, 0, 1.0f, &D_808023C8_bstnt);
}

extern void func_8009DB04(PlayerState *, s32, f32, s32);

s32 func_808005F4_bstnt(void *param_0) {
    s32 local_0[3];

    func_8009C128(param_0, local_0);
    _bashake_entrypoint_0(param_0, 3, 2);
    func_8009DB04(param_0, 0x413, 1.0f, 0x7FFF);
    func_808004F8_bstnt(param_0, local_0);
    func_8080030C_bstnt(param_0, local_0);
    func_808002AC_bstnt(param_0, local_0);
}

int func_80800668_bstnt(Actor *param_0)
{
  func_8009E474(param_0);
  baflag_clear(param_0, 0x32);
}

void func_80800694_bstnt()
{
    func_8009E4AC();
}

s32 func_808006B4_bstnt(Actor *this, s32 arg1)
{
  *(u8*)((char*)this + 0x169) = arg1;
  baflag_set(this, 0x32);
  func_8009E55C(this, 1, 0x43480000);
}

s32 func_808006EC_bstnt(void *param_0)
{
  func_8009E55C(param_0, 1, 0x41E00000);
  baflag_clear(param_0, 0x32);
}

void func_80800720_bstnt(PlayerState *param_0)
{
    param_0->unk168.bytes[1] = (u32)func_800F0E00((f32)(param_0->unk168.bytes[1] - 1), 0.0f);
    if (!param_0->unk168.bytes[1]) func_808006EC_bstnt(param_0);
}

extern void baroll_setIdeal(PlayerState *, f32);

extern void func_8009BF5C(PlayerState *, f32);

void func_808007EC_bstnt(PlayerState *param_0, s32 param_1)
{
    param_0->unk15C.word = param_1;
    switch (param_1) {
        case 1:
            baanim_playForDuration_onceSmooth(param_0, 0xE6, 0x3FC00000);
            func_8009FFD8(param_0, 1, 1, 3, 2);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            func_808000D4_bstnt(param_0, 10.0f);
            break;
        case 2:
            func_808006B4_bstnt(param_0, 10);
            func_808005F4_bstnt(param_0);
            func_800A17A8(param_0, -1);
            func_800931AC(param_0, 3);
            param_0->unk16C = 800.0f;
            param_0->unk170 = yaw_get(param_0);
            func_8009328C(param_0, param_0->unk170);
            break;
        case 0:
            yaw_setIdeal(param_0, func_80092BE8(param_0));
            yaw_applyIdeal(param_0);
            func_800931AC(param_0, 1);
            func_808000D4_bstnt(param_0, 0.1f);
            func_8009BC34(param_0);
            func_8009BF5C(param_0, 0.0f);
            baroll_setIdeal(param_0, 0.0f);
            break;
    }
}

s32 func_8080092C_bstnt(u8 *param_0){
    func_80800668_bstnt(param_0);
    func_80800028_bstnt(param_0);
    func_808007EC_bstnt(param_0, 0);
}

void func_80800960_bstnt(Actor *param_0)
{
  func_80800694_bstnt(param_0);
  func_80800060_bstnt(param_0);
  *(s32 *)((char *)param_0 + 0x15C) = 0;
  func_808007EC_bstnt(param_0, 1);
}

void func_80800998_bstnt(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1 = func_800D8FF8();
    func_8009D3A8(param_0, 0);
    if (player_inWater(param_0)) {
        baphysics_set_gravity(param_0, -10.0f);
        baphysics_set_terminal_velocity(param_0, -20.0f);
    }
    switch (*(s32 *)((u8 *)param_0 + 0x15C)) {
    case 1:
        if (baanim_isAt(param_0, 0.1587f)) func_80800068_bstnt(param_0);
        if (baanim_isAt(param_0, 0.277f)) func_80800000_bstnt(param_0);
        if (baanim_isAt(param_0, 0.434f)) func_808007EC_bstnt(param_0, 2);
        break;
    case 2:
        func_8080009C_bstnt(param_0);
        param_0->unk170 = func_800136E4(param_0->unk170 + param_0->unk16C * local_1);
        func_8009328C(param_0, param_0->unk170);
        if (baanim_getTimer(param_0) > 0.78f) param_0->unk16C = func_800F0E00(0.0f, param_0->unk16C - 750.0f * local_1);
        if (baanim_isAt(param_0, 0.5f)) func_80800554_bstnt(param_0);
        if (param_0->unk16C == 0.0f) local_0 = 0x10C;
        break;
    }
    func_80800720_bstnt(param_0);
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

int bstnt_entrypoint_0(s32 param_0)
{
  return D_808023F8_bstnt[param_0];
}

void func_80800B60_bstnt(u8 *param_0, s32 param_1)
{
  f32 local_0;
  f32 local_1[3];
  f32 local_2[3];
  *((s32 *) (((s8 *) param_0) + 0x15C)) = param_1;
  switch (param_1)
  {
    case 1:
      baanim_playForDuration_onceSmooth(param_0, 0xE2, 0x3F333333);
      func_8009FFD8(param_0, 1, 1, 3, 0);
      func_8010114C(*((s32 *) (((s8 *) param_0) + 0x164)), 6, 0);
      func_80101038(local_2);
      func_8009C128(param_0, local_1);
      func_800F1E6C(local_1, local_2, &local_0);
      yaw_setIdeal(param_0, local_0);
      _bamovegoto_entrypoint_0(param_0);
      _bamovegoto_entrypoint_12(param_0, local_2);
      _bamovegoto_entrypoint_7(param_0, 0x3F333333);
      _bamovegoto_entrypoint_13(param_0);
      return;
    case 2:
      baanim_playForDuration_onceSmooth(param_0, 0xE3, 0x4059999A);
      func_8009FFD8(param_0, 1, 1, 3, 6);
      baphysics_set_target_horizontal_velocity(param_0, 0.0f);
      func_8008F880(*((s32 *) (((s8 *) param_0) + 0x164)), local_2);
      func_8009C128(param_0, local_1);
      func_800F1E6C(local_2, local_1, &local_0);
      yaw_setIdeal(param_0, local_0);
      return;
  }
}

void func_80800CB0_bstnt(s32 arg0)
{
    func_80800028_bstnt();
    func_800951B4(arg0);
}
void func_80800CD8_bstnt(Actor *param_0)
{
    func_80800060_bstnt();
    *(s32 *)((char *)param_0 + 0x15c) = 0;
    func_80800B60_bstnt(param_0, 1);
}

void func_80800D08_bstnt(u8 *param_0) {
    s32 local_0;
    s32 local_1;

    local_0 = 0;
    local_1 = (*(s32 *)((s8 *)(param_0) + (0x15C)));
    switch (local_1) {                              
    case 1:
        if (_bamovegoto_entrypoint_4(param_0) != 0) {
            func_80800B60_bstnt(param_0, 2);
        }
        break;
    case 2:
        if (baanim_isAt(param_0, 0.1183f) != 0) {
            func_80800068_bstnt(param_0);
        }
        if (baanim_isAt(param_0, 0.592f) != 0) {
            func_80800000_bstnt(param_0);
        }
        if (baanim_isAt(param_0, 0.65f) != 0) {
            func_8009514C(param_0);
        }
        if (baanim_isAt(param_0, 0.665f) != 0) {
            func_8010114C((*(s32 *)((s8 *)(param_0) + (0x164))), 5, (*(s32 *)((s8 *)(param_0) + (0x184))));
            func_8080009C_bstnt(param_0);
        }
        if (baanim_isAt(param_0, 0.85f) != 0) {
            func_800951B4(param_0);
        }
        if (baanim_isStopped(param_0) != 0) {
            local_0 = 0x10C;
        }
        break;
    }
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

int bstnt_entrypoint_1(s32 param_0)
{
  return D_80802408_bstnt[param_0];
}

void bstnt_entrypoint_2(param_0) s32 param_0; {
    if (func_8009E74C(param_0, 0xC) == 0) {
        func_800947EC(param_0, 1, 0);
        func_80092864(param_0, 1.0f);
        func_8009C000(param_0);
        baroll_resetAngularVelocity(param_0);
        bastick_popZone(param_0);
        func_80095A40(param_0);
        func_80092744(param_0, 0);
    }
}

void bstnt_entrypoint_3(param_0)
PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 12)) {
        *(s32 *)((u8 *)param_0 + 0x164) = 0;
        *(s8 *)((u8 *)param_0 + 0x168) = 0;
        *(s8 *)((u8 *)param_0 + 0x16A) = 0;
        _batimer_set(param_0, 2, 0.0f);
        func_80092864(param_0, 0.899993896484375f);
        func_8009BFE4(param_0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(param_0, 1000.0f, 12.0f);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 1.0f);
        func_800959C8(param_0, 85.0f, 38.0f);
        func_800947EC(param_0, 1, 1);
    }
}

void bstnt_entrypoint_4(param_0) PlayerState *param_0;
{
    s32 local_0;

    if (_batimer_decrement(param_0, 2)) {
        func_80092744(param_0, 0);
        _bapulse_entrypoint_2(param_0);
    } else if (_batimer_get(param_0, 2) > 0.0f) {
        _bapulse_entrypoint_4(param_0);
        local_0 = (s32)func_800F12D4(_bapulse_entrypoint_1(param_0), 0.0f, 1.0f, 0.0f, 255.0f);
        func_80092750(param_0, 255, local_0, local_0, 255);
    }
    param_0->unk168.bytes[0] = 0;
}

void func_80801058_bstnt(s32 arg0)
{
    _basudie_entrypoint_8();
    bstnt_entrypoint_2(arg0);
}
void func_80801080_bstnt(s32 param_0) {
    f32 local_0[3];

    bstnt_entrypoint_3();
    _basudie_entrypoint_9(param_0, 0x42480000);
    func_80800554_bstnt(param_0);
    func_8009C128(param_0, local_0);
    func_808004F8_bstnt(param_0, local_0);
    func_8080030C_bstnt(param_0, local_0);
    func_808002AC_bstnt(param_0, local_0);
    func_8009DB04(param_0, 0x693, 1.0f, 0x7FFF);
    func_8009D9D4(param_0);
    func_800BBCB8(local_0, 0, 1.0f, 1, &D_80802418_bstnt);
    func_800BBCB8(local_0, 0, 1.0f, 1, &D_8080246C_bstnt);
    func_800BBCB8(local_0, 0, 1.0f, 1, &D_808024B8_bstnt);
    func_800BBCB8(local_0, 0, 1.0f, 9, &D_80802504_bstnt);
}

void func_80801190_bstnt(s32 arg0)
{
    _basudie_entrypoint_10();
    bstnt_entrypoint_4(arg0);
}
int bstnt_entrypoint_5(s32 param_0)
{
  return D_8080254C_bstnt[param_0];
}

void func_808011CC_bstnt(s32 arg0)
{
    bstnt_entrypoint_3();
    _bsdrone_entrypoint_0(arg0);
}
void func_808011F4_bstnt(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstnt_entrypoint_4(arg0);
}
void func_8080121C_bstnt(s32 arg0)
{
    bstnt_entrypoint_2();
    _bsdrone_entrypoint_2(arg0);
}
int bstnt_entrypoint_6(s32 param_0)
{
  return D_8080255C_bstnt[param_0];
}

void func_80801258_bstnt(PlayerState *param_0)
{
    AnimCtrl *local_0;
    bstnt_entrypoint_3(param_0);
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0xE5);
    anctrl_setStart(local_0, 0.5036f);
    anctrl_setDuration(local_0, 0.7f);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    param_0->unk15C.word = 0;
}

void func_808012F8_bstnt(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;
    f32 local_2[3];

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_8009D3A8(param_0, 0);
    func_80800164_bstnt(param_0);
    func_8009BB24(param_0, local_2);
    switch (param_0->unk15C.word) {
    case 2:
        break;
    case 0:
        if (func_8008DF8C(param_0, 0x82)) {
            baanim_setEnd(param_0, 0.6538f);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(param_0)) {
            func_800A2EAC(param_0);
            baphysics_set_target_horizontal_velocity(param_0, 0);
            baanim_setEndAndDuration(param_0, 1.0f, 1);
            param_0->unk15C.word = 2;
        }
        break;
    }
    if (player_inWater(param_0)) local_0 = 0x111;
    if (player_isStable(param_0) && (bastick_getZone(param_0) > 0 ||
        (param_0->unk15C.word == 2 && anctrl_isStopped(local_1)))) {
        if (baflag_isTrue(param_0, 0x19)) local_0 = _badrone_entrypoint_28(param_0);
        else local_0 = 0x10C;
    }
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

s32 func_80801464_bstnt(Actor *this)
{
  func_8009BF5C(this, 0);
  baroll_setIdeal(this, 0);
  bstnt_entrypoint_2(this);
}

int bstnt_entrypoint_7(s32 param_0)
{
  return D_8080256C_bstnt[param_0];
}

int bstnt_entrypoint_8(param_0) Actor *param_0;
{
  if (!bakey_pressed(param_0, 9))
  {
    return 0;
  }
  if (func_800A1718(param_0) >= 2)
  {
    return 1;
  }
  func_800FC660(0xf);
  return 0;
}

void func_8080150C_bstnt(PlayerState *param_0)
{
  AnimCtrl *local_0;
  f32 local_1;
  f32 new_var;
  bstnt_entrypoint_3();
  local_0 = baanim_getAnimCtrlPtr(param_0);
  anctrl_reset(local_0);
  anctrl_setSmoothTransition(local_0, 0);
  anctrl_setIndex(local_0, 0xE2);
  anctrl_setSubrange(local_0, 0.0f, 0.4008f);
  anctrl_setDuration(local_0, 1.0f);
  anctrl_setPlaybackType(local_0, 1);
  anctrl_start(local_0);
  func_8009FFD8(param_0, 1, 3, 1, 6);
  yaw_setVelocityBounded(param_0, 1200.0f, 10.0f);
  if (bastick_distance(param_0) != 0.0f)
  {
    yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
  }
  baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
  func_80800164_bstnt(param_0);
  new_var = yaw_getIdeal(param_0);
  baphysics_set_horizontal_velocity(param_0, new_var, baphysics_get_target_horizontal_velocity(param_0));
  baphysics_set_vertical_velocity(param_0, 693.5f);
  baphysics_set_gravity(param_0, -1200.0f);
  func_8009D7A4(param_0, 1.35f, 1.45f);
  *((s32 *) (((u8 *) param_0) + 0x15C)) = 0;
}

void func_8080166C_bstnt(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_80800164_bstnt(param_0);
    if (bakey_released(param_0, 8) && baphysics_get_vertical_velocity(param_0) > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    switch (*(s32 *)((u8 *)param_0 + 0x15C)) {
    case 0:
        if (func_8008DF8C(param_0, 0x82)) {
            baanim_setEndAndDuration(param_0, 1, 0.7f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 2;
        } else if (anctrl_isStopped(local_1)) {
            baanim_setEndAndDuration(param_0, 0.651f, 3.0f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(param_0, 0x82)) {
            baanim_setEndAndDuration(param_0, 1, 1.0f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 2;
        }
        break;
    case 2:
        func_8009D3A8(param_0, 0);
        if (player_isStable(param_0)) {
            func_800A2EAC(param_0);
            baanim_setEndAndDuration(param_0, 1, 1.0f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 3;
        }
        break;
    case 3:
        baphysics_set_target_horizontal_velocity(param_0, func_8009BB5C(param_0) * 0.25f);
        func_8009D2D8(param_0, 3);
        func_8009D3A8(param_0, 0);
        if (anctrl_isStopped(local_1)) {
            if (func_8009BB5C(param_0) > 0.0f) local_0 = 0x108;
            else local_0 = 0x10C;
        }
        break;
    }
    if (baphysics_get_vertical_velocity(param_0) < 0.0f && player_inWater(param_0)) local_0 = 0x111;
    if (bstnt_entrypoint_8(param_0)) local_0 = 0x10E;
    if (player_isStable(param_0) && bakey_pressed(param_0, 8)) local_0 = 0x107;
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

void func_808018D0_bstnt(s32 param_0) {
    baphysics_reset_gravity();
    func_8009BF5C(param_0, 0);
    baroll_setIdeal(param_0, 0);
    bstnt_entrypoint_2(param_0);
}

int bstnt_entrypoint_9(s32 param_0)
{
  return D_8080257C_bstnt[param_0];
}

void bstnt_entrypoint_10(u8 *param_0) {
    if (func_8009E6EC() == 0x42) {
        (*(s32 *)((s8 *)(param_0) + (0x164))) = func_80099A4C(param_0);
        (*(s8 *)((s8 *)(param_0) + (0x168))) = 1;
        func_8009E830(param_0, 2);
        return;
    }
    func_80099B94(param_0);
}

void func_80801980_bstnt(PlayerState *param_0, s32 param_1)
{
    extern f32 func_800DC178(f32, f32);
    extern f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern f32 bastick_distance(PlayerState *);
    extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    extern f32 yaw_getIdeal(PlayerState *);
    extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    extern f32 func_8009BB5C(PlayerState *);
    extern void func_8009DB04(PlayerState *, s32, f32, s32);
    extern void baphysics_set_target_yaw(PlayerState *, f32);
    extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    extern void baphysics_set_vertical_velocity(PlayerState *, f32);
    extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
    extern void yaw_setIdeal(PlayerState *, f32);
    extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    extern void func_8009BF5C(PlayerState *, f32);
    extern void baroll_setIdeal(PlayerState *, f32);
    extern void func_80800164_bstnt(PlayerState *);
    AnimCtrl *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_0 = (void *)baanim_getAnimCtrlPtr(param_0);
    param_0->unk15C.word = param_1;
    switch (param_1) {
    case 1: {
        func_8009DB04(param_0, 0x3F0, func_800DC178(0.96f, 1.04f), 10000);
        func_800A2EEC(param_0, 4);
        func_8009FFD8(param_0, 1, 1, 1, 2);
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        }
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        func_80800164_bstnt(param_0);
        baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
        local_1 = baphysics_get_target_horizontal_velocity(param_0);
        local_2 = func_800F10B4(local_1, 30.0f, 600.0f, 0.35f, 0.7f);
        local_3 = func_800F10B4(local_1, 30.0f, 600.0f, 346.75f, 693.5f);
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 0xE2);
        anctrl_setSubrange(local_0, 0.0f, 0.4008f);
        anctrl_setDuration(local_0, local_2);
        anctrl_setPlaybackType(local_0, 1);
        anctrl_start(local_0);
        baphysics_set_vertical_velocity(param_0, local_3);
        break;
    }
    case 2:
        baanim_setEndAndDuration(param_0, 0.651f, 3.0f);
        break;
    case 3:
        baanim_setEndAndDuration(param_0, 0.93f, 0.7f);
        break;
    case 4:
        param_0->unk16C = func_8009BB5C(param_0) * 0.25f;
        func_8009D2D8(param_0, 3);
        baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
        func_800A2FCC(param_0, 0);
        baanim_setEndAndDuration(param_0, 0.93f, 0.7f);
        break;
    case 0:
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        break;
    }
}

void func_80801C0C_bstnt(BSTNT *param_0)
{
    BSTNT *local_0;
    local_0 = param_0;
    bstnt_entrypoint_3();
    local_0->unk15C = 0;
    func_80801980_bstnt(local_0, 1);
}

void func_80801C3C_bstnt(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    f32 local_2[3];

    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_80800164_bstnt(param_0);
    func_8009BB24(param_0, local_2);
    switch ((u32)param_0->unk15C.word) {
    case 1:
        if (func_8008DF8C(param_0, 0x82)) func_80801980_bstnt(param_0, 3);
        else if (anctrl_isStopped(local_1)) func_80801980_bstnt(param_0, 2);
        local_0 = func_808001C8_bstnt(param_0, 0);
        break;
    case 2:
        if (func_8008DF8C(param_0, 0x82)) func_80801980_bstnt(param_0, 3);
        local_0 = func_808001C8_bstnt(param_0, 0);
        break;
    case 3:
        func_8009D3A8(param_0, 0);
        if (player_isStable(param_0)) func_80801980_bstnt(param_0, 4);
        local_0 = func_808001C8_bstnt(param_0, 0);
        break;
    case 4:
        if (param_0->unk168.bytes[0] && player_isStable(param_0)) local_0 = 0x10D;
        func_8009D3A8(param_0, 0);
        if (anctrl_isStopped(local_1)) {
            if (baphysics_get_target_horizontal_velocity(param_0) > 0.0f) {
                func_80801980_bstnt(param_0, 1);
            } else {
                local_0 = 0x10C;
            }
        } else {
            baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
        }
        local_0 = func_80800218_bstnt(param_0, local_0);
        break;
    }
    if (player_inWater(param_0)) local_0 = 0x111;
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

void func_80801E20_bstnt(s32 arg0)
{
    func_80801980_bstnt(arg0,0);
    bstnt_entrypoint_2(arg0);
}

int bstnt_entrypoint_11(s32 param_0)
{
  return D_8080258C_bstnt[param_0];
}

s32 func_80801E60_bstnt(void *param_0) {
    bstnt_entrypoint_3();
    _babounce_entrypoint_4(param_0, 1);
    _babounce_entrypoint_5(param_0, 0xE9, 0x3ED0FF97);
}

void func_80801EA0_bstnt(Actor *param_0)
{
    s32 local_0;
    local_0 = 0;
    if (baanim_isAt(param_0, 0.5f) != 0) {
        func_800951B4(param_0);
    }
    if (_babounce_entrypoint_2(param_0) != 0) {
        func_80800164_bstnt(param_0);
    }
    if (_babounce_entrypoint_9(param_0) != 0) {
        local_0 = 0x10C;
    }
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

void func_80801F20_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
int bstnt_entrypoint_12(s32 param_0)
{
  return D_8080259C_bstnt[param_0];
}

s32 func_80801F5C_bstnt(s32 param_0) {
    bstnt_entrypoint_3(param_0);
    _babounce_entrypoint_4(param_0, 2);
    _babounce_entrypoint_5(param_0, 0xE9, 0x3ED0FF97);
}

int func_80801F9C_bstnt(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_babounce_entrypoint_2(param_0))
  {
    func_80800164_bstnt(param_0);
  }
  if (_babounce_entrypoint_9(param_0))
  {
    local_0 = 0x10C;
  }
  bstnt_entrypoint_4(param_0);
  bs_setState(param_0, local_0);
}

void func_80802000_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
int bstnt_entrypoint_13(s32 param_0)
{
  return D_808025AC_bstnt[param_0];
}

void func_8080203C_bstnt(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstnt_entrypoint_2(arg0);
}
void func_80802064_bstnt(s32 arg0)
{
    bstnt_entrypoint_3();
    _bsrest_entrypoint_16(arg0);
}
int func_8080208C_bstnt(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 = _bsrest_entrypoint_13(param_0);
  }
  bstnt_entrypoint_4(param_0);
  bs_setState(param_0, local_0);
}

int bstnt_entrypoint_14(s32 param_0)
{
  return D_808025BC_bstnt[param_0];
}

void func_808020EC_bstnt(s32 arg0)
{
    bstnt_entrypoint_2();
    func_80090A2C(arg0);
}
int func_80802114_bstnt(Actor *param_0)
{
  int new_var;
  s32 local_0;
  local_0 = param_0;
  bstnt_entrypoint_3(param_0);
  new_var = 0xe5;
  baanim_playForDuration_loopSmooth(local_0, new_var, 0x40D00000);
  func_8009FFD8(local_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(local_0, 0);
  func_800909CC(local_0);
}

void func_8080217C_bstnt(PlayerState *param_0)
{
    s32 local_0;
    local_0 = 0;
    if (bastick_getZone(param_0) > 0) local_0 = 0x108;
    if (player_inWater(param_0)) local_0 = 0x111;
    local_0 = func_80800218_bstnt(param_0, local_0);
    bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

int bstnt_entrypoint_15(s32 param_0)
{
  return D_808025CC_bstnt[param_0];
}
