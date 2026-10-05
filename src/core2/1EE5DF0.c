#include "common.h"

typedef struct { u8 local_0[8]; f32 local_1; u8 local_2[0x64]; unsigned local_3:7; unsigned local_4:15; unsigned local_5:6; unsigned local_6:4; } local_type;
extern f32 D_80136F54;
extern s32 func_800CC338();
extern f32 func_800EEAA4(f32*, f32*);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern s32 func_800F54E4();
extern s32 func_800F8B88(void);
extern s32 _plsu_entrypoint_1(s32);
typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x26]; u16 unk62; u8 pad64[0x24]; s16 unk88; s16 unk8A; } S_10C878;
extern f32 func_80103F38(void *, f32 *);
extern f32 func_8010A40C();
extern void func_8008FB58(f32 *, f32, f32);
typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; } G_10C9FC;
extern s32 func_800F00A4(f32 *, f32, f32, f32, f32 *);
typedef struct { u8 pad[0xC]; s16 unkC; } S_136F50;
typedef struct { f32 pos[3]; s16 unkC; s16 unkE; } Bounds_80136F50;
extern Bounds_80136F50 D_80136F50;
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 D_80136F68[];
extern s32 func_800F5898(void);
extern s32 func_800F6438(s32);
extern s32 D_80136F8C;
extern f32 func_80013728(f32);
extern f32 mlAbsF(f32);
extern void func_80102844(s32, f32, s32, void *);
f32 func_80102D78(Actor *param_0, f32 *param_1);
extern s32 func_800F57C0(s32 param_0);
extern f32 func_800F5794(s32, f32 *, s32);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF334(s32, f32);
void func_800F5A2C(s32 a, s32 b, s32 *c);
void func_800EF3DC(s32 *a, s32 *b);
void func_800EE780(s32 a, s32 *b, s32 *c);
void func_800EF04C(s32 a, s32 *b);
extern s16 D_80136F5C;
extern s16 D_80136F5E;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800F5A00(s32, f32 *);
extern s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern f32 func_800F0C68(f32 *, f32 *, f32, f32);
extern void func_800F5BF0(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFD4(f32 *);
extern s32 func_800F0BD0(f32 *, f32 *, f32, f32);
extern s32 func_800F682C(s32 param_0);
extern s32 func_80109EE0(s32 param_0, s32 param_1);
extern void func_800F4F34(s32 param_0, s32 param_1, f32 param_2, f32 param_3);
void func_8010CE28();
int func_8010D600();
void func_8010D6E0(s32 param_0, s32 param_1, f32 param_2, f32 param_3);

extern s32 D_80136F60;
extern s32 D_80136F64;

s32 func_8010C500(u8 *param_0) {
    u32 temp_v0;
    u32 temp_v1;
    u32 local_1;

    temp_v0 = (*(u32 *)((s8 *)param_0 + 0x70));
    temp_v1 = temp_v0 >> 25;
    if (temp_v1 == 0) {
        return 1;
    }
    local_1 = ((temp_v0 << 22) >> 26) - 1;
    return (func_800CC338(D_80136F50.pos, temp_v1 - 1, local_1) + 1) != 0;
}

int func_8010C550(void *param_0, void *param_1)
{
  f32 local_1[3];
  u32 local_0;
  if (!(((u32 *) param_0)[0x70 / 4] >> 25))
  {
    return 1;
  }
  func_800F5A00(param_1, &local_1);
 goto dummy_label_635971; dummy_label_635971: ;
  local_0 = ((u32 *) param_0)[0x70 / 4];
  return (func_800CC338(&local_1, (local_0 >> 0x19) - 1, ((local_0 << 0x16) >> 0x1A) - 1, param_0) + 1) != 0;
}

int func_8010C5C0(local_type *param_0, f32 param_1) {
    if (param_0->local_3 == 0) return 1;
    return D_80136F54 < param_0->local_1 + param_1
        && param_0->local_1 - param_1 < D_80136F54
        && func_800CC338(D_80136F50.pos, param_0->local_3 - 1, param_0->local_5 - 1) != -1;
}

int func_8010C668(local_type *param_0, f32 *param_1, f32 param_2, f32 param_3) {
    if (param_0->local_3 == 0) return 1;
    return D_80136F50.pos[1] < param_1[1] + param_2
        && param_1[1] + param_3 < D_80136F50.pos[1]
        && func_800CC338(D_80136F50.pos, param_0->local_3 - 1, param_0->local_5 - 1) != -1;
}

s32 func_8010C710(param_0) f32 *param_0; {
    f32 local_0[3];
    func_800EFB24(local_0, param_0 + 1, D_80136F50.pos);
    return (s32) func_800EEAA4(local_0, local_0);
}

int func_8010C754()
{
  f32 local_0;
  local_0 = func_8010C710();
  return sqrtf(local_0);
}

void func_8010C788(f32 *param_0, f32 param_1, f32 param_2, f32 param_3)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800F54E4();
  param_3 -= 30.0f;
  if (func_800F8B88() == 3)
  {
    local_1 = _plsu_entrypoint_1(0xA);
    if (local_1 >= 0)
    {
      func_800F4EC8(local_1, param_0, param_1, param_2, param_3);
    }
  }
  func_800F4EC8(local_0, param_0, param_1, param_2, param_3);
}

void func_8010C820(u8 *param_0, s32 param_1, s32 param_2) {
    func_8010C788((f32 *) (param_0 + 4), param_1, 0.0f, param_2 + 0x1e);
}

void func_8010C878(S_10C878 *param_0, void *param_1, f32 param_2) {
    f32 a = param_0->unk8A * param_0->unk38;
    f32 b = param_0->unk88 * param_0->unk38;
    f32 c = param_0->unk38 * (f32)(u32)param_0->unk62 * param_2;
    if (param_0->unk62 != 0) { func_8010C788(param_1, a, b, c); }
}

void func_8010C908(s32 param_0, s32 param_1) {
    func_8010C878(param_0, param_1, func_8010A40C());
}

void func_8010C93C(s32 param_0, s32 param_1, f32 param_2) {
    func_8010C878(param_0, param_1, param_2);
}

void func_8010C964(void *param_0) {
    f32 sp24[4];
    f32 r;
    r = func_80103F38(param_0, &sp24[1]);
    func_8008FB58(&sp24[1], 0.0f, func_8010A40C(param_0) * r);
}

s32 func_8010C9B0(s32 param_0, s32 param_1)
{
  if (D_80136F50.unkE == 0)
  {
    return 0;
  }
  func_800EFFB4(param_0, (f32) param_1, D_80136F50.pos);
}

s32 func_8010C9FC(void *param_0, s32 param_1, s32 param_2, s32 param_3) {
    if (D_80136F50.unkE == 0) {
        return 0;
    }
    return func_800F00A4(param_0, (f32)param_1, (f32)param_2, (f32)param_3, D_80136F50.pos);
}

s32 func_8010CA74(s32 param_0, s32 param_1)
{
  if (D_80136F50.unkE == 0)
  {
    return 0;
  }
  func_800F0064(param_0, (f32) param_1, D_80136F50.pos);
}

s32 func_8010CAC0(f32 *param_0, u32 param_1) {
    if (D_80136F50.unkC == 0) { return 0; }
    return func_800EFFB4(param_0, (f32)(s32)param_1, D_80136F50.pos);
}

s32 func_8010CB0C(f32 param_0[3], u32 param_1, u32 param_2, u32 param_3) {
    if (D_80136F50.unkC == 0) {
        return 0;
    }
    return func_800F00A4(param_0, (f32)(s32)param_1, (f32)(s32)param_2, (f32)(s32)param_3, D_80136F50.pos);
}

s32 func_8010CB84(f32 *param_0, u32 param_1) {
    if (D_80136F50.unkC == 0) { return 0; }
    return func_800F0064(param_0, (f32)(s32)param_1, D_80136F50.pos);
}

f32 func_8010CBD0(s32 param_0, u8 *param_1)
{
    func_800F5A00(param_0, param_1);
    *(f32 *)((char *)param_1 + 4) = *(f32 *)((char *)param_1 + 4) + 60.0f;
    return 90.0f;
}

s32 func_8010CC10(s32 param_0, f32 param_1) {
    s32 local_0;
    f32 local_2;
    f32 local_1[3];

    D_80136F68[8] = 0;
    D_80136F68[9] = 0;
    for (local_0 = 0; local_0 < func_800F5898(); local_0++) {
        if (func_800F6438(local_0)) {
            local_2 = func_8010CBD0(local_0, local_1);
            if (func_800EFFB4(param_0, param_1 + local_2, local_1)) {
                D_80136F68[D_80136F68[8]] = local_0;
                D_80136F68[8]++;
            }
        }
    }
    return D_80136F68[8];
}

int func_8010CCE0()
{
  D_80136F8C = 0;
}

int func_8010CCEC()
{
  int local_0;
  if (((int *) D_80136F68)[9] >= ((int *) D_80136F68)[8])
  {
    return -1;
  }
  local_0 = ((int *) D_80136F68)[((int *) D_80136F68)[9]];
  ((int *) D_80136F68)[9]++;
  return local_0;
}

void func_8010CD28(s32 param_0)
{
  func_800F1DF4(param_0 + 4, D_80136F50.pos);
}

int func_8010CD50(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_800F5A00(param_1 | 0, local_0);
  func_800F1DF4(param_0 + 4, local_0);
}

int func_8010CD88(u8 *param_0, f32 param_1, f32 param_2) {
    f32 local_0[2];
    func_8010CE28(param_0, local_0);
    local_0[0] = mlAbsF(func_80013728(*(f32 *)(param_0 + 0x44) - local_0[0]));
    local_0[1] = mlAbsF(func_80013728(*(f32 *)(param_0 + 0x48) - local_0[1]));
    return local_0[1] < param_2 && local_0[0] < param_1;
}

void func_8010CE28(param_0, param_1) s32 param_0; f32 * param_1;
{
    func_800F18FC(param_0 + 4, D_80136F50.pos, param_1);
    *param_1 = 360.0f - *param_1;
}

void func_8010CE70(s32 p0, s32 p1, s32 p2) {
    func_80102844(p0, (f32)p1, p2, &D_80136F50);
}

s32 func_8010CEAC(Actor *this) {
    f32 sp1C[3];

    func_8010D600(sp1C);
    *(f32 *)((char *)this + 0x54) = func_80102D78(this, sp1C);
    return func_80102BF8(this, 0x3DCCCCCD, 0x40800000, 0x43340000);
}

s32 func_8010CEF8(s32 param_0, s32 param_1) {
    s32 temp_v0;
    f32 sp48;
    f32 sp54;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s2;

    var_s2 = param_0 + 4;
    temp_v0 = func_800F54E4();
    temp_v0_2 = func_800F57C0(temp_v0);
    var_s0 = 0;
    if (temp_v0_2 > 0) {
loop_2:
        if (func_800F0008(param_0 + 4, (f32) param_1, &sp54, func_800F5794(temp_v0, &sp54, var_s0)) != 0) {
            return 1;
        }
        var_s0 += 1;
        if (var_s0 < temp_v0_2) {
            goto loop_2;
        }
    }
    return 0;
}

s32 func_8010CFBC(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_2;
    s32 local_3;
    f32 local_6[3];
    s32 local_0;
    f32 local_5[3];

    local_3 = func_800F54E4();
    local_2 = func_800F57C0(local_3);
    func_800EE7F8(local_5, param_0);
    local_0 = 0;
    local_5[1] += (f32) param_1;
    if (local_2 > 0) {
        do {
            if (func_800F0008(local_5, (f32) param_2, local_6, func_800F5794(local_3, local_6, local_0)) != 0) {
                return 1;
            }
            local_0++;
        } while (local_0 != local_2);
    }
    return 0;
}

void func_8010D09C(s32 param_0, s32 param_1, f32 param_2)
{
  s32 sp34[3];
  s32 sp28[3];
  s8 _sfpad[8];
  s32 sp1C;
  f32 sp18;
  sp18 = 1.0f / func_800D8FF8();
  func_800F5A00(param_0, &sp28);
  func_800F5A2C(param_0, 8, &sp34);
  func_800EFB24(&sp1C, &sp28, &sp34);
  func_800EF334(&sp1C, param_2 * sp18);
  func_800EE780(param_1, &sp28, &sp1C);
}

void func_8010D12C(s32 param_0, s32 param_1, f32 param_2, s32 param_3) {
  s32 sp44[3];
  s32 sp38[3];
  s32 sp2C[3];
  s32 sp20[3];
  f32 sp1C;

  sp1C = 1.0f / func_800D8FF8();
  func_800F5A00(param_0, &sp38[0]);
  func_800F5A2C(param_0, 8, &sp44[0]);
  func_800F5A2C(param_0, param_3, &sp20);
  func_800EF3DC(&sp20, &sp38[0]);
  func_800EFB24(&sp2C[0], &sp38[0], &sp44[0]);
  func_800EF334(&sp2C[0], param_2 * sp1C);
  func_800EE780(param_1, &sp38[0], &sp2C[0]);
  func_800EF04C(param_1, &sp20);
}

int func_8010D1E8()
{
  s32 local_0;
  func_8008FE68(D_80136F50.pos);
  D_80136F5C = func_80090128();
  D_80136F5E = func_80090150();
  D_80136F60 = func_8008FD48();
  D_80136F64 = func_8008FF6C();
}

int func_8010D23C()
{
  return D_80136F5C;
}

int func_8010D248()
{
  return D_80136F5E;
}

void func_8010D254(s32 param_0) {
    func_800EE7F8(param_0, D_80136F50.pos);
}

s32 func_8010D278()
{
    return D_80136F60;
}

s32 func_8010D284()
{
    return D_80136F64;
}

s32 func_8010D290(s32 param_0)
{
  s32 i;
  s32 local_0;
  s32 local_1;
  local_1 = func_800F54E4(param_0);
  if (local_1 == (-1))
  {
    return -1;
  }
  if (func_800F6438(local_1))
  {
    if (1)
    {
      if (func_800F64A4(local_1, param_0) == 0)
      {
        return local_1;
      }
    }
  }
  for (i = 0; i < 8; i++)
  {
    if (i != local_1)
    {
      if (func_800F6438(i))
      {
        if (func_800F64A4(i, param_0) == 0)
        {
          return i;
        }
      }
    }
  }

  return -1;
}

s32 func_8010D350(f32 *param_0, f32 *param_1, f32 param_2, s32 param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5;
    f32 local_6;
    s32 local_7;
    func_800EE7F8(local_1, param_0);
    func_800EE7F8(local_2, param_1);
    local_4 = 120.0f;
    for (local_7 = 0; local_7 < func_800F5898(); local_7++) {
        if (func_800F6438(local_7) && local_7 != param_3) {
            local_5 = param_2 * 2;
            local_6 = 55.0f + param_2;
            func_800F5A00(local_7, local_0);
            local_0[1] -= param_2;
            local_4 += local_5;
            if (func_800F0734(local_1, local_2, local_0, local_6, local_4, local_3, local_3)) return local_7;
        }
    }
    return -1;
}

s32 func_8010D490(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, s32 param_4) {
    s32 local_6;
    f32 local_7;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    s32 local_4;
    f32 local_5[3];
    func_800EE7F8(local_5, param_1);
    param_1 = &local_2;
    local_7 = func_800F0C68(param_0, local_5, param_2, param_3);
    local_6 = -1;
    local_3 = 1e+08f;
    for (local_4 = 0; local_4 < func_800F5898(); local_4++) {
        if (func_800F6438(local_4) && local_4 != param_4) {
            func_800F5BF0(local_4, local_0);
            func_800EFB24(local_1, local_0, param_0);
            local_2 = func_800EEFD4(local_1);
            if (local_2 < local_3 && func_800F0BD0(local_1, local_5, param_2, local_7)) {
                local_6 = local_4;
                local_3 = local_2;
            }
        }
    }
    if (local_6 == -1) return -1;
    return local_6;
}

void func_8010D5DC(s32 arg0,s32 arg1)
{
    func_8010114C(arg0,0x32,arg1);
}

int func_8010D600(param_0) s32 param_0;
{
  if ((param_0 && param_0) && param_0)
  {
  }
  if (func_8010D23C(param_0))
  {
    func_8008FE68(param_0);
  }
  else
  {
    func_800E3980();
  }
}

int func_8010D640(s32 param_0)
{
  if ((func_8010D23C() != 0) && (func_800DB9B0() == 0))
  {
    func_8008FE68(param_0);
    return;
  }
  func_800E3980(param_0);
}

void func_8010D690(void *param_0) {
    f32 sp24[4];
    f32 r;
    r = func_80103F38(param_0, &sp24[1]);
    func_8010D6E0(param_0, &sp24[1], 0.0f, func_8010A40C(param_0) * r);
}

void func_8010D6E0(s32 param_0, s32 param_1, f32 param_2, f32 param_3) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_800F6438(i) != 0) {
            if (func_800F682C(i) != 0) {
                if (func_80109EE0(param_0, 1) == 0) {
                    continue;
                }
            }
            func_800F4F34(i, param_1, param_2, param_3);
        }
    }
}
