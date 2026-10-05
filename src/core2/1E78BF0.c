#include "core2/1E78BF0.h"
#include "common.h"

extern void func_8009C128(PlayerState *, f32 *);
extern void *func_800A4C48(PlayerState *);
extern void func_800CA7E4(void *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern void func_800A30B4(PlayerState *, f32 *, f32 *);
extern void func_800F4200(PlayerState *, f32 *);
extern void func_800F4648(PlayerState *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F0DC0(f32, f32);
extern s32 func_800F1660(f32, f32);
extern void func_80019CD4(void);
extern void func_8001980C(f32 *, f32 *, f32, s32);
extern void func_80019750(f32 *, f32 *, f32, s32);
extern void func_800193C4(f32 *, f32 *);
extern void func_800A3148(s32, f32 *, f32 *, f32 *);
extern f32 sqrtf(f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800EF368(f32 *, f32);
extern void func_800A3200(s32, f32 *, f32 *);
extern f32 func_800964DC(PlayerState *);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern s32 func_800966E0(PlayerState *);
extern void _fxripple_entrypoint_1(s32, f32 *, s32);
extern u8 D_80119220[];
extern f32 func_800DC178(f32 a0, f32 a1);
extern void func_800BBCB8(f32 *a0, int a1, int a2, int a3, void *a4);
extern s32 func_80096544(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void func_80092C24(PlayerState *, f32 *);
extern void func_80092C00(PlayerState *, f32 *);
extern void *_fxsplash_entrypoint_2(f32 *, f32);
extern void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
extern void func_800BA22C(void *, s32);
extern void func_8009BF5C(s32 param_0, f32 param_1);
extern void baroll_setIdeal(s32 param_0, f32 param_1);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 func_800A3274(PlayerState *);
extern s32 player_isStable(PlayerState *);
extern BanjoStateId _badrone_entrypoint_28(PlayerState *);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 func_8009E674(PlayerState *, s32);
extern void baflag_clear(PlayerState *, s32);
extern void func_8009BFBC(PlayerState *);
extern void baroll_applyIdeal(PlayerState *);
extern s32 baflag_isFalse(PlayerState *, s32);
extern void _bsjig_entrypoint_4(PlayerState *);
extern void func_800FC660(s32);
s32 func_800A0064();
int func_800A055C();

s32 func_8009F300() 
{
    return 0x4;
}

f32 func_8009F308(PlayerState *param_0) {
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;
    func_8009C128(param_0, sp2C);
    func_800CA7E4(func_800A4C48(param_0), sp20);
    func_800F1E6C(sp2C, sp20, &sp1C);
    return sp1C;
}

int func_8009F354(Actor *param_0)
{
  s32 local_0;
  if (baflag_isTrue(param_0, 0xF))
  {
    return 0;
  }
  baflag_set(param_0, 0xF);
  local_0 = _badata_entrypoint_24(param_0);
  if (bs_getCurrentState(param_0) != local_0)
  {
    return local_0;
  }
  return 0;
}

f32 func_8009F3BC(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 local_0 = 0.0f;
    f32 local_1 = param_3;
    while (0.0f < local_1 || param_2 < param_1) {
        local_0 += 0.01666666754f;
        param_1 += local_1 * 0.01666666754f;
        local_1 += param_4 * 0.01666666754f;
    }
    return local_0;
}

s32 func_8009F440(PlayerState *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4, f32 param_5)
{
    f32 local_0[3];
    f32 local_9[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4, local_5, local_6, local_7, local_8;
    func_800A30B4(param_0, local_2, local_1);
    func_800F4200(param_0, local_9);
    func_80019CD4();
    func_8001980C(param_1, param_2, 1.0f, 0);
    func_800193C4(local_0, local_9);
    func_800EF04C(local_2, local_0);
    func_800EF04C(local_1, local_0);
    if (local_1[1] <= param_3[1] || param_4[1] <= local_2[1]) return 0;
    local_5 = param_4[0] - local_2[0];
    local_4 = param_3[0] - local_1[0];
    if (0.0f <= local_4 || local_5 <= 0.0f) return 0;
    local_7 = local_5 < -local_4 ? local_5 : local_4;
    local_5 = param_4[2] - local_2[2];
    local_4 = param_3[2] - local_1[2];
    if (0.0f <= local_4 || local_5 <= 0.0f) return 0;
    local_8 = local_5 < -local_4 ? local_5 : local_4;
    local_6 = func_800D8FF8() * param_5;
    if (func_800F1660(local_7, local_8)) {
        func_800EFA4C(local_3, 0.0f, 0.0f, func_800F0DC0(local_8, local_6));
    } else {
        func_800EFA4C(local_3, func_800F0DC0(local_7, local_6), 0.0f, 0.0f);
    }
    func_800EF04C(local_0, local_3);
    func_80019CD4();
    func_80019750(param_1, param_2, 1.0f, 0);
    func_800193C4(local_9, local_0);
    func_800F4648(param_0, local_9);
    return 1;
}

s32 func_8009F678(PlayerState *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4, local_5, local_6, local_7, local_8;
    func_800A30B4(param_0, local_2, local_1);
    func_800F4200(param_0, local_0);
    func_800EF04C(local_2, local_0);
    func_800EF04C(local_1, local_0);
    if (local_1[1] <= param_1[1] || param_2[1] <= local_2[1]) return 0;
    local_5 = param_2[0] - local_2[0];
    local_4 = param_1[0] - local_1[0];
    if (0.0f <= local_4 || local_5 <= 0.0f) return 0;
    local_7 = local_5 < -local_4 ? local_5 : local_4;
    local_5 = param_2[2] - local_2[2];
    local_4 = param_1[2] - local_1[2];
    if (0.0f <= local_4 || local_5 <= 0.0f) return 0;
    local_8 = local_5 < -local_4 ? local_5 : local_4;
    local_6 = func_800D8FF8() * param_3;
    if (func_800F1660(local_7, local_8)) {
        func_800EFA4C(local_3, 0.0f, 0.0f, func_800F0DC0(local_8, local_6));
    } else {
        func_800EFA4C(local_3, func_800F0DC0(local_7, local_6), 0.0f, 0.0f);
    }
    func_800EF04C(local_0, local_3);
    func_800F4648(param_0, local_0);
    return 1;
}

s32 func_8009F860(s32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7[3];
    f32 local_8[3];
    s32 local_9[2];
    func_800A3148(param_0, &local_4, &local_5, &local_6);
    func_800F4200(param_0, local_7);
    local_6 *= 0.5f;
    if ((local_7[1] + local_5) + local_6 < param_1[1] + param_3) return 0;
    if (param_1[1] + param_2 < (local_7[1] + local_5) - local_6) return 0;
    func_800EFA4C(local_8, local_7[0] - param_1[0], 0.0f, local_7[2] - param_1[2]);
    local_1 = local_8[0] * local_8[0] + local_8[1] * local_8[1] + local_8[2] * local_8[2];
    local_0 = param_4 + local_4;
    if (local_0 * local_0 < local_1) return 0;
    local_1 = sqrtf(local_1);
    local_3 = func_800F13F0(func_800D8FF8() * param_5, local_0 - local_1);
    if (local_1 == 0.0f) {
        local_1 = func_800DC0C0();
        func_800EFA4C(local_8, local_1, 0.0f, func_800DC0C0());
    }
    func_800EF368(local_8, local_3);
    func_800EF04C(local_7, local_8);
    func_800F4648(param_0, local_7);
    return 1;
}

s32 func_8009FA20(s32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[2];
    func_800EFA4C(local_8, param_1[0], param_1[1] + param_2, param_1[2]);
    func_800A3200(param_0, &local_4, &local_5);
    func_800F4200(param_0, local_6);
    func_800EFA4C(local_7, local_6[0] - local_8[0], local_6[1] + local_5 - local_8[1], local_6[2] - local_8[2]);
    local_1 = local_7[0] * local_7[0] + local_7[1] * local_7[1] + local_7[2] * local_7[2];
    local_0 = param_3 + local_4;
    if (local_0 * local_0 < local_1) return 0;
    local_1 = sqrtf(local_1);
    local_3 = func_800F13F0(func_800D8FF8() * param_4, local_0 - local_1);
    if (local_1 == 0.0f) {
        local_1 = func_800DC0C0();
        local_9[0] = func_800DC0C0();
        func_800EFA4C(local_7, local_1, local_9[0], func_800DC0C0());
    }
    func_800EF368(local_7, local_3);
    func_800EF04C(local_6, local_7);
    func_800F4648(param_0, local_6);
    return 1;
}

s32 func_8009FBB0(PlayerState *param_0, f32 param_1[3], f32 param_2) {
    return _fxairbub_entrypoint_1(param_1, param_2, func_800964DC(param_0), 1.0f);
}

int func_8009FBE8(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  f32 local_1[3];
  func_8009C128(param_0, local_0);
  func_800CA7E4(func_800A4C48(param_0), local_1);
  func_800EFB24(param_1, local_1, local_0);
}

void func_8009FC34(PlayerState *param_0, s32 param_1) {
    f32 sp1C[3];
    func_8009C128(param_0, sp1C);
    sp1C[1] = func_800964DC(param_0);
    _fxripple_entrypoint_1(param_1, sp1C, func_800966E0(param_0));
}

int func_8009FC80(int arg0)
{
    f32 local_0[3];
    func_8009C128(arg0, &local_0[0]);
    local_0[0] += func_800DC178(-30.0f, 30.0f);
    local_0[1] += func_800DC178(95.0f, 105.0f);
    local_0[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(&local_0[0], 0, 0x3F800000, 1, D_80119220);
}

void func_8009FD24(PlayerState *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    void *local_2;
    if (func_80096544(param_0)) {
        if (param_1) func_80092C24(param_0, local_0);
        else func_80092C00(param_0, local_0);
        local_0[1] = func_800964DC(param_0);
        local_1 = yaw_get(param_0);
        local_2 = _fxsplash_entrypoint_2(local_0, 8.0f);
        func_800BA994(local_2, -140, local_1 - 35.0f, 200, -120, local_1 + 35.0f, 250);
        func_800BA22C(local_2, 3);
        func_800BA994(local_2, -100, local_1 - 35.0f, 300, -90, local_1 + 35.0f, 400);
        func_800BA22C(local_2, 2);
    }
}

void func_8009FE58(PlayerState* arg0)
{
    func_800A2E18(arg0);
}

void func_8009FE78(u8 *param_0) {
    *(*(s32 **)((s8 *)(param_0) + (0x12C))) = 0;
}

BanjoStateId bs_getTypeOfJump(PlayerState *self)
{
  if (bakey_held(self, 1) && func_8008D370(self))
  {
    return 0x12;
  }
  if (baflag_isTrue(self, 2))
  {
    return 0x05;
  }
  if (func_8008D3B0(self))
  {
    return 0x23;
  }
  return 0x05;
}

void func_8009FF00(s32 param_0) {
    s32 (*temp_v0)(s32, f32);
    s32 (*sp1C)(s32, f32);

    temp_v0 = _badata_entrypoint_28();
    if (temp_v0 != NULL) {
        sp1C = temp_v0;
        sp1C(param_0, func_8009BB5C(param_0));
    }
}

int func_8009FF44(PlayerState *param_0, enum asset_e param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5)
{
  AnimCtrl *local_0;
  local_0 = baanim_getAnimCtrlPtr(param_0);
  if (anctrl_getIndex(local_0) != param_1)
  {
    anctrl_setIndex(local_0, param_1);
    anctrl_start(local_0);
  }
  func_8008CA4C(param_0, 2);
  baanim_setDurationRange(param_0, 0.234500006f, 3.98760009f);
  func_8008C9F0(param_0, param_2, param_3, param_4, param_5);
}

void func_8009FFD8(PlayerState *p0, BaAnimUpdateType p1, YawType p2, s32 p3, BaPhysicsType p4) {
    func_8008CA4C(p0, p1);
    yaw_setUpdateType(p0, p2);
    func_8009D2D8(p0, p3);
    baphysics_set_type(p0, p4);
}

int func_800A0024(s32 param_0)
{
  f32 local_0[3];
  if (func_8009CC68(param_0) && func_8009CC18(param_0, local_0))
  {
    func_800A0064(param_0, local_0);
  }
}

s32 func_800A0064(param_0, param_1) s32 param_0; s32 param_1; {
    f32 sp24[3];
    f32 sp18[3];

    func_8009C128(param_0, sp24);
    func_800F18FC(sp24, param_1, sp18);
    func_8009BF5C(param_0, -sp18[0]);
    yaw_setIdeal(param_0, sp18[1]);
    baroll_setIdeal(param_0, 0);
}

s32 func_800A00CC(PlayerState *param_0, f32 param_1[3]) {
    f32 sp24[3];
    f32 sp18[3];
    func_8009C128(param_0, sp24);
    func_800F18FC(sp24, param_1, sp18);
    yaw_setIdeal(param_0, sp18[1]);
}

void func_800A0110(s32 param_0, s32 param_1) {
    f32 local_1;
    s32 local_0;

    _badata_entrypoint_3(param_0, &local_0, &local_1);
    anctrl_setIndex(param_1, local_0);
    anctrl_setDuration(param_1, local_1);
}

int func_800A0150(s32 param_0)
{
  func_800FC240(0, 0xFA0);
  func_800FC660(param_0);
}

void func_800A0180(PlayerState *param_0) {
    s32 t = _badata_entrypoint_16(param_0);
    if (func_800D395C() != 0) {
        if (func_800FCCD4(t) == 0) {
            func_800A0150(t);
        }
    } else if (baflag_isTrue(param_0, 0x41) == 0) {
        baflag_set(param_0, 0x41);
        func_800A0150(t);
        func_800FE4E4();
    }
}

BanjoStateId func_800A01F8(PlayerState *param_0, BanjoStateId param_1)
{
  if (baflag_isTrue(param_0, 0xF))
  {
    return param_1;
  }
  if (bakey_pressed(param_0, 8))
  {
    param_1 = bs_getTypeOfJump(param_0);
  }
  if (bakey_pressed(param_0, 9))
  {
    param_1 = func_800A055C(param_0, param_1);
  }
  if (bakey_held(param_0, 1) && bainput_should_beak_barge(param_0))
  {
    param_1 = 0x13;
  }
  if (bainput_should_enter_first_person(param_0))
  {
    param_1 = _badrone_entrypoint_24(param_0);
  }
  if (func_8008E148(param_0))
  {
    param_1 = _badrone_entrypoint_25(param_0);
  }
  return param_1;
}

BanjoStateId func_800A02DC(PlayerState *param_0, BanjoStateId param_1)
{
    s32 local_0;
    local_0 = func_800A3274(param_0);
    if (!player_isStable(param_0)) return param_1;
    if (baflag_isTrue(param_0, 0x19)) param_1 = _badrone_entrypoint_28(param_0);
    if (baflag_isTrue(param_0, 0x1A)) param_1 = 0x34;
    if (baflag_isTrue(param_0, 0xE)) param_1 = local_0 == 0xB ? 0x47 : 0x25;
    if (baflag_isTrue(param_0, 0x10) || baflag_isTrue(param_0, 0x37) || baflag_isTrue(param_0, 0x38)) {
        if (local_0 != 0xB && !func_8009E674(param_0, 0x40)) param_1 = 0x14;
    }
    if (baflag_isTrue(param_0, 6)) param_1 = 0x53;
    if (baflag_isTrue(param_0, 7)) param_1 = 0x44;
    if (baflag_isTrue(param_0, 0x14)) param_1 = 0x53;
    baflag_clear(param_0, 0xF);
    return param_1;
}

void func_800A042C(PlayerState *param_0) {
    func_8009BF5C(param_0, 0.0f);
    func_8009BFBC(param_0);
    baroll_setIdeal(param_0, 0.0f);
    baroll_applyIdeal(param_0);
}

void func_800A046C(PlayerState *param_0) {
    if (baflag_isFalse(param_0, 7) != 0) { return; }
    if (baflag_isTrue(param_0, 0xF) && baflag_isFalse(param_0, 6) && baflag_isFalse(param_0, 0x14)) {
        baflag_clear(param_0, 0xF);
    }
    baflag_clear(param_0, 7);
    _bsjig_entrypoint_4(param_0);
    func_800FC660(5);
}

int func_800A04F4(s32 param_0, s32 param_1)
{
  int new_var;
  new_var = 0;
  if (func_8008E23C(param_0))
  {
    if (func_8008D568(param_0) != new_var)
    {
      return 0xE4;
    }
    return param_1;
  }
  else
  {
    if (!param_0)
    {
    }
    if (func_8008D694() != new_var)
    {
      return 0x31;
    }
    return param_1;
  }
}

int func_800A055C(param_0, param_1) s32 param_0; s32 param_1;
{
  if (param_0)
  {
  }
  if (func_8008E23C(param_0))
  {
    if (func_8008D568(param_0) != 0)
    {
      return 0xE4;
      if (param_0)
      {
      }
    }
    return param_1;
  }
  else
    if (func_8008D1B0() != 0)
  {
    if (func_8009EA2C())
    {
 return 0x18A; }
    return 6;
  }
  return param_1;
}

void func_800A05DC(s32 param_0) {
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 var_v0;
    s32 sp18;
    s32 sp1C;
    s32 var_a0;

    sp2E = 0;
    sp2C = 0;
    func_800F9110(1);
    if (func_800A9C98() != 0) {
        func_800A9CDC();
        return;
    }
    if (func_8008E23C(param_0) != 0) {
        func_800F8F3C();
        if (func_800F8DA8(0xA) != 0) {
            var_a0 = 0xA;
        } else {
            var_a0 = 0xB;
        }
        sp18 = var_a0;
        sp2E = func_800F89E4(var_a0, &sp1C);
        if (func_800EA05C() != sp2E) {
            var_v0 = func_800F8A80(sp18);
        } else {
            var_v0 = func_800EA090(sp18);
        }
        sp2C = var_v0;
    }
    if (sp2E != 0) {
        func_8009EB24(sp2E, sp2C);
    }
    func_8009EC08(&sp2A, &sp28);
    if (sp2E != 0) {
        func_8009EBD0();
    }
    func_800A794C(sp2A, sp28, 1);
}
