#include "core2/1E66990.h"

extern s32 func_800C6E38(s32);
extern s32 func_800A3304(s32);
extern f32 func_800964DC(s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800F65D0(int param_0);
extern f32 func_80090010(void);
extern f32 mlAbsF(f32);
extern s32 func_800F20BC(f32, f32, s32);
f32 func_8009C150(PlayerState *);
f32 func_80096364(PlayerState *);
extern f32 func_800A3378(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_800963C0(PlayerState *, f32 *);
extern s32 func_800954E8(PlayerState *, s32 *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
int player_isStable();
s32 func_8008E23C();
int func_8008E39C();

int func_8008D0A0(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0) && func_800A3304(param_0);
}

int func_8008D0E0(PlayerState *param_0) {
    /* HEADER DEPENDENCY: Also push data/header/include/core2/1E66990.h; this function returns int, not s32 (long). */
    
    return ((func_800C6E38(1)) != 0) && ((baflag_isFalse(param_0, 0x39)) != 0) && (((func_800A3304(param_0)) != 0) || func_800A3274(param_0) == 11);
}

int func_8008D14C(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(2) && func_800A3304(param_0);
}

void func_8008D18C(s32 arg0)
{
    func_800C6E38(0x3);
}

int func_8008D1B0(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0x4) && func_800A3304(param_0);
}

void func_8008D1F0(s32 arg0)
{
    func_800C6E38(0x5);
}

int func_8008D214(s32 param_0) {
    return func_800C6E38(0xF) != 0 && 100.0f < func_800964DC(param_0) - func_80096364(param_0);
}

s32 func_8008D280(s32 param_0)
{
    s32 temp_v0;

    if (func_800C6E38(6) == 0)
    {
        return 0;
    }
    if (func_800DA298(0x6B6) != 0)
    {
        return 0;
    }
    temp_v0 = func_800A3274(param_0);
    if (((temp_v0 == 1) || (temp_v0 == 0xA)) && (func_800A3304(param_0) == 0))
    {
        return 0;
    }
    return 1;
}

int func_8008D304(PlayerState *param_0) {
    
    return ((baflag_isFalse(param_0, 0x12)) != 0) && ((baflag_isFalse(param_0, 5)) != 0) && ((func_800C6E38(7)) != 0) && ((func_800A3304(param_0)) != 0);
}

int func_8008D370(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0x8) && func_800A3304(param_0);
}

int func_8008D3B0(PlayerState *param_0) {
    return baflag_isTrue(param_0, 1) != 0
        && func_800C6E38(9) != 0
        && func_800F64A4(*(s32 *)((u8 *)param_0 + 0x184), 0x401) != 0;
}

int func_8008D40C(s32 param_0) {
    f32 local_0[3];
    s32 local_1;
    f32 local_2[3];
    s32 local_3;
    if (func_800F8B88() == 2 && _plsu_entrypoint_2()) {
        if (func_8008E0C8(param_0)) return 0;
        if (func_800F99E8()) return 0;
        local_3 = bs_getCurrentState(param_0);
        if (local_3 == 0xB9 || local_3 == 0xBA) return 0;
        local_1 = _baduo_entrypoint_2(param_0);
        if (!player_isStable(param_0) || !func_800F6C5C(local_1)) return 0;
        if (!func_800F6774(func_800F54E4())) return 0;
        func_8009C128(param_0, local_2);
        func_800F5A00(_baduo_entrypoint_2(param_0), local_0);
        return func_800EEB40(local_2, local_0) < 8.1e+03f;
    }
    return 0;
}

s32 func_8008D544(PlayerState* arg0)
{
    return func_800C6E38(0xA);
}

int func_8008D568(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0x29) && baflag_isFalse(param_0, 5) && baflag_isFalse(param_0, 0x12);
}

int func_8008D5C4(PlayerState *param_0) {
    
    return ((baflag_isFalse(param_0, 5)) != 0) && ((baflag_isFalse(param_0, 0x12)) != 0) && ((func_800C6E38(11)) != 0) && ((func_800A3304(param_0)) != 0);
}

s32 func_8008D630(s32 param_0) {
    if ((baflag_isTrue(param_0, 0x14) != 0) || (baflag_isTrue(param_0, 0x19) != 0)) {
        return 0;
    }
    if (bs_getCurrentState(param_0) == 0x56) {
        return 0;
    }
    return 1;
}

int func_8008D694(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0xC) && func_800A3304(param_0);
}

int func_8008D6D4(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0xd) && func_800A3304(param_0);
}

int func_8008D714(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  tmp = 0xC;
 local_0 = (tmp = param_0); goto dummy_label_426559; dummy_label_426559: ;
  return _baduo_entrypoint_3(tmp) && func_800A3304(local_0);
}

int func_8008D750(s32 param_0)
{
  s32 local_0;
  local_0 = func_800C6E38(0xE);
  return (local_0 != 0) && func_800A3304(param_0);
}

int func_8008D790(PlayerState *param_0) {
    /* HEADER DEPENDENCY: Also push data/header/include/core2/1E66990.h; this function returns int, not s32 (long). */
    return _baduo_entrypoint_4(param_0) != 0
        && !func_8008E39C(param_0)
        && player_isStable(param_0) != 0
        && !func_800C954C()
        && !func_800DB9B0()
        && !func_800F8004(*(s32 *)((u8 *)param_0 + 0x184))
        && !func_800F6D24(*(s32 *)((u8 *)param_0 + 0x184))
        && baflag_isFalse(param_0, 0x34) != 0;
}

int func_8008D850(s32 param_0)
{
  f32 local_0[3];
  if (func_800C6E38(0x1E))
  {
    if (func_800A3304(param_0) && (!_bafpctrl_entrypoint_5(param_0)))
    {
      func_8009C128(param_0, local_0);
      if ((func_800EA05C() == 0x117) && (local_0[2] < (-6.13e+03f)))
      {
        return 0;
      }
      return 1;
    }
  }
  param_0 = param_0;
  return 0;
}

int func_8008D8E4(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0x10) && func_800A3304(param_0);
}

int func_8008D924(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0x10) && func_800A3304(param_0);
}

int func_8008D964(s32 param_0)
{
  s32 local_0;
  s32 tmp;
  ;
  ;
  return func_800C6E38(0x12) && func_800A3304(param_0);
}

s32 player_inWater();

int func_8008D9A4(Actor *param_0)
{
  s32 local_0;
  local_0 = func_800A4CA8();
  if (_ncba1p_entrypoint_10(local_0 | 0) == 3)
  {
    return 0;
  }
  if (!func_800A4D40(param_0))
  {
    return 0;
  }
  if (!player_isStable(param_0) && !player_inWater(param_0))
  {
    return 0;
  }
  return 1;
}

int func_8008DA24(Actor *param_0) {
    return func_800C6E38(0x14) != 0
        && baphysics_get_vertical_velocity(param_0) < 100.0f
        && func_800A0FCC(param_0) == 0
        && func_800976DC(param_0) != 0;
}

void func_8008DAA8(int *param_0)
{
    func_800F65D0(param_0[97]);
}

int func_8008DAC8(s32 param_0)
{
  func_800DB9B0(param_0);
  if (param_0)
  {
  }
}

int func_8008DAE8(s32 param_0, s32 param_1, f32 param_2) {
    f32 local_0[3];
    f32 local_1;
    u16 local_2;
    f32 t;
    func_8009C128(param_0, local_0);
    func_800F1E6C(param_1, local_0, &local_1);
    local_2 = (u16)(local_1 * 182.04445f);
    t = func_80090010();
    local_2 -= (u16)(t * 182.04445f);
    return mlAbsF(0x8000 - local_2) < param_2 * 182.04445f;
}

int func_8008DC90(s32 param_0, s32 param_1, s32 param_2) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[2];
    func_8009C128(param_0, local_1);
    func_8008FF40(local_0);
    func_800F18FC(local_1, param_1, local_2);
    return (func_800F20BC(local_0[0], local_2[0], param_2) != 0) &&
           (func_800F20BC(local_0[1], local_2[1], param_2) != 0);
}

s32 func_8008DD04(PlayerState *param_0)
{
  f32 sp1C = func_8009C150(param_0);
  int new_var;
  new_var = (sp1C - func_80096364(param_0)) > 60.0f;
  if (new_var != 0)
  {
    if (!new_var)
    {
    }
    return player_isStable(param_0) == 0;
    return 1;
  }
}

void func_8008DD70(s32 arg0)
{
    func_8009E71C(arg0,0x5);
}

int func_8008DD90(s32 param_0)
{
  s32 local_0;
  if (func_8009E674(param_0, 0x10))
  {
    return 1;
  }
  if (func_8009E674(param_0, 8))
  {
    local_0 = _badrone_entrypoint_1(param_0);
    return !local_0;
  }
  return 0;
}

int func_8008DDEC(s32 param_0, s32 param_1, s32 param_2)
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  func_800F0064(param_1, param_2, local_0);
}

s32 func_8008DE24(PlayerState* arg0)
{
    func_80096568(arg0,0xE00);
}

func_8008DE44(s32 param_0){
    return 0;
}

int func_8008DE50()
{
  return func_80096694() == 3;
}

int func_8008DE74(Actor *param_0)
{
  func_8009CA70(param_0, bs_getCurrentState() | 0, 0x4000);
}

int func_8008DEA4(void *param_0, f32 param_1[3], f32 param_2)
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  return param_1[1] - param_2 <= local_0[1] && local_0[1] <= param_1[1] + param_2;
}

int func_8008DF18(PlayerState *param_0) {
    return bastatetimer_isActive(param_0, 6) != 0
        || (func_800A3378(param_0) == 1.0f && func_8009659C(param_0, 0x40) != 0);
}

int func_8008DF8C(PlayerState *param_0, s32 param_1) {
    /* HEADER DEPENDENCY: Also push data/header/include/core2/1E66990.h; this function returns int, not s32 (long). */
    f32 local_0[3];
    if (player_isStable(param_0)) return 1;
    func_800963C0(param_0, local_0);
    if (local_0[1] < 0.35f && local_0[1] >= 0.0f) return 0;
    return baphysics_get_vertical_velocity(param_0) < 0.0f && func_8009C150(param_0) - func_80096364(param_0) < (f32)param_1;
}

int player_isStable(self) PlayerState * self;
{
  return func_800A0FCC(self) && (baphysics_get_vertical_velocity(self) < 0.0f);
}

int func_8008E0C8()
{
    _bapackctrl_entrypoint_1();
}

int func_8008E0E8(PlayerState *param_0)
{
  return func_8008E23C(param_0) && (func_8008E0C8(param_0) == 0);
}

s32 func_8008E124(PlayerState *param_0)
{
    return func_8009CC68(param_0) != 0;
}

int func_8008E148(s32 param_0) {
    return bastatetimer_isActive(param_0, 5) != 0 || func_800A3378(param_0) == 1.0f;
}

int func_8008E1A0()
{
  return func_80096694() == 0x18;
}

int func_8008E1C4(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_8009659C(param_0, 0x10) && baflag_isFalse(param_0, 3);
  local_1 = func_8009659C(param_0, 0x40) && baflag_isFalse(param_0, 4);
  if (local_0 || local_1)
  {
    return 1;
  }
  return 0;
}

s32 func_8008E23C(param_0) PlayerState * param_0;
{
  s32 *new_var;
  s32 local_0;
  new_var = &param_0;
  local_0 = func_800F8B88(*new_var);
  return local_0 == 2;
}

s32 func_8008E260(PlayerState *param_0)
{
  s32 local_0;
  if (player_isStable())
  {
    return 0;
  }
  else
  {
    local_0 = func_800954E8(param_0, &local_0);
    if (!local_0)
    {
      return 0;
    }
  }
  return 1;
}

s32 func_8008E2AC(void) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = bs_getCurrentState();
    switch (temp_v0) {
    case 0x2B: ;
    case 0x2C:
    case 0x2D: ;
    case 0x2E:
    case 0x30: ;
    case 0x39:
    case 0x4C:
        var_v1 = 1;
        break;
    default:
        var_v1 = 0;
        break;
    }
    return var_v1;
}

s32 func_8008E300(PlayerState *param_0) {
    return mlAbsF(func_800F1DCC(yaw_getIdeal(param_0), yaw_get(param_0))) > 135.0f;
}

s32 player_inWater()
{
    return func_800A0FD8();
}

void func_8008E37C()
{
    func_800A0FE4();
}

int func_8008E39C(param_0) PlayerState * param_0; {
    /* HEADER DEPENDENCY: Also push data/header/include/core2/1E66990.h; this function returns int, not s32 (long). */
    s32 local_0 = _bashoes_entrypoint_1(param_0);
    return !(local_0 == 1) && !(local_0 == 0) && !(local_0 == 2);
}

s32 func_8008E3E8(PlayerState *param_0)
{
    return _bashoes_entrypoint_1(param_0) == 3;
}

int func_8008E40C()
{
  return _bashoes_entrypoint_1() == 4;
}

s32 func_8008E430()
{
  return _bashoes_entrypoint_1() == 5;
}

int func_8008E454(s32 param_0)
{
  f32 local_0[3];
  if ((func_800DB9B0() != 0) && (func_800BFAA4() != 0))
  {
    func_8009C128(param_0, local_0);
    return (_gcmapsects_entrypoint_4(local_0) + 1) != 0;
  }
  return 1;
}
