#include "core2/1EE9AB0.h"
extern f32 D_80126540;
#include "types.h"

extern s16 D_80137340[25];
extern s16 D_80137372;
extern s32 (*D_80124950[25])(void);
extern void *heap_alloc(s32);
extern void bzero(void *, int);
extern void func_8010FFB0(int, void *, void *);
extern void _ncba1p_entrypoint_1(void *);
extern void _ncbaspline_entrypoint_1(void *);
extern void func_8011337C(void *);
extern void func_80115FB0(void *);
extern void func_801125B8(void *);
extern void func_800EFD24(void *);
extern void func_80112398(void *);
extern void func_80113410();
extern void heap_free(void *ptr);
typedef void (*D_801247A0_func_t)(void *);
extern D_801247A0_func_t D_801247A0[][4];
typedef struct { char pad_0[0x68]; void* unk68; } Actor;
extern f32 func_800136E4(f32);
extern void func_800CA3A4(s32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800F5A00();
extern void func_8010FE14(s32, f32 *, f32 *);
extern s32 func_8010FF80(s32);
extern s32 func_800F6BE4(void *);
extern s32 func_800F6438(void *);
extern s32 func_800F6640(void *);
extern s32 func_800F6690(void *);
extern f32 func_80112550(void *, f32 *);
extern f32 sqrtf(f32);
extern void func_80115D08(void *, f32, f32, f32, f32);
extern void func_8011539C(void *, f32, f32, f32);
extern void func_80116050(s32, f32);
extern void func_801125D8(s32, f32);
typedef struct { u8 local_0[14]; s16 local_1; } local_type;
extern void func_80114D98(void *);
extern f32 func_800F5AE0(s32);
extern f32 func_80115E88(void *);
extern void func_80112524(void *param_0, f32 *param_1);
extern s32 func_800F53D0(s32 param_0);
extern f32 func_800EEFFC(f32 *param_0);
extern void func_800A4EFC(s32 param_0, f32 param_1);
extern void _ncbastring_entrypoint_4(void *param_0);
extern void func_80115DEC(s32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 func_80112E84(void *);
extern s32 func_8011349C(f32 *, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80112D90(void *, f32, f32, s32, s32);
extern s32 func_80092BC4(void *);
extern f32 func_80092BD0(void *);
extern f32 func_800F5F24(s32);
typedef struct { u8 pad[0x34]; f32 *local_0; } State111410;
extern f32 func_80013728(f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F212C(f32, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF2A0(f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern s32 func_800EEEA8(f32 *);
extern s32 func_800D8FEC(void);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern f32 func_800A3048(s32 param_0);
void func_801106A8();
int func_80110720();
void func_80110790(u8 *, f32 *);
void func_80110970(s32 param_0, f32 param_1);
int func_80110A68();
void func_80110C88();
void func_80110CC0(void *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
s32 func_80111154(s32 param_0, f32 param_1);
s32 func_80111198(s32 param_0, f32 param_1);
int func_801111D0(void *param_0, f32 param_1);
f32 func_801112B0();
void func_80111348();
void func_801113B8();
void func_80111590(u8 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
void func_80111B8C(u8 *param_0, f32 param_1, f32 param_2);
void func_801120CC(u8 *param_0, f32 param_1, f32 param_2, f32 param_3);

void func_801101C0(void) {

    s32 local_1, local_2, local_3;
    D_80137372 = 0x98;
    for (local_1 = 0; local_1 < 25; local_1++) {
        D_80137340[local_1] = D_80124950[local_1]();
        local_2 = D_80137340[local_1];
        if (local_2 % 4) local_3 = 4 - local_2 % 4; else local_3 = 0;
        D_80137372 = D_80137372 + local_2 + local_3;
    }
}

void func_80110280(void **param_0) {
    s32 local_0, local_1, local_2, local_3;
    local_0 = 0x98;
    for (local_1 = 0; local_1 < 25; local_1++) {
        *(void **)((u32)param_0 + (local_1 << 2)) = (u8 *)param_0 + local_0;
        local_2 = ((s16 *) D_80137340)[local_1];
        if (local_2 % 4) local_3 = 4 - local_2 % 4; else local_3 = 0;
        local_0 = local_0 + local_2 + local_3;
    }
}

u8 *func_80110424(s32 param_0, s32 param_1)
{
    s32 sp24;
    u8 *temp_v0;

    sp24 = D_80137372;
    temp_v0 = heap_alloc(sp24);
    bzero(temp_v0, sp24);
    func_80110280(temp_v0);
    (*(s32 *)((s8 *)(temp_v0) + (0x64))) = param_0;
    (*(s32 *)((s8 *)(temp_v0) + (0x68))) = param_1;
    func_80110720(temp_v0, 1);
    func_8010FFB0((*(s32 *)((s8 *)(temp_v0) + (0x64))), temp_v0 + 0x74, temp_v0 + 0x80);
    _ncba1p_entrypoint_1(temp_v0);
    func_80112398(temp_v0);
    _ncbaspline_entrypoint_1(temp_v0);
    func_8011337C(temp_v0);
    func_80111348(temp_v0);
    func_80115FB0(temp_v0);
    func_801125B8(temp_v0);
    func_80110C88(temp_v0);
    (*(s32 *)((s8 *)(temp_v0) + (0x6C))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x72))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x71))) = 0;
    func_800EFD24(temp_v0 + 0x8C);
    return temp_v0;
}

void func_801104F4(Actor *param_0)
{
  func_801106A8(param_0, 0);
  func_80113410(param_0);
  heap_free(param_0);
}

int func_80110528(s32 param_0)
{
  f32 local_1[3];
  f32 local_2[3];
  if (func_801138A0(param_0))
  {
    func_801138F4(param_0);
  }
  func_80112524(param_0, &local_1);
  func_80110A68(param_0, &local_2, &local_1);
  func_80110790(param_0, &local_2);
}

void func_80110588(u8 *param_0) {
    f32 local_0[3];
    f32 local_1[3];
    s32 (*local_2)(u8 *);

    if ((*(u8 *)((s8 *)(param_0) + (0x70))) != 0) {
        func_8011607C(param_0, 0);
        if ((*(u8 *)((s8 *)(param_0) + (0x72))) == 0) {
            func_8011347C(param_0);
            func_801123D4(param_0);
            func_80115A9C(param_0);
            func_80112A84(param_0);
            func_801154A4(param_0);
            func_80112648(param_0);
            func_80114DD8(param_0);
            func_80113D30(param_0);
            local_2 = *(s32 (**)(u8 *))((u8 *)((s32 *) D_801247A0)
                + ((*(s32 *)((s8 *)param_0 + 0x6C)) * 0x10) + 4);
            if (local_2 != NULL) {
                local_2(param_0);
            }
        }
        func_800EFD24(param_0 + 0x8C);
        func_800EE7F8(local_0, param_0 + 0x74);
        func_800EE7F8(local_1, param_0 + 0x80);
        if ((*(u8 *)((s8 *)(param_0) + (0x71))) != 0) {
            _ncba1p_entrypoint_3(param_0, local_0, local_1);
        }
        func_80116024(param_0, local_1);
        func_8010FE14((*(s32 *)((s8 *)(param_0) + (0x64))), local_0, local_1);
        if (*(*(s32 **)((s8 *)(param_0) + (0x5C))) != 0) {
            _ncbawaypoint_entrypoint_1(param_0);
        }
    }
}

int func_801106A0(s32 param_0[5])
{
  s32 new_var2;
  int new_var3;
  int new_var;
  new_var3 = 17;
  new_var3 = 0;
  param_0 += new_var3;
  new_var2 = *(s32*)((s8*)param_0 + 108);
  new_var = new_var2;
  return new_var;
}

void func_801106A8(param_0, param_1) void * param_0; s32 param_1; {
    s32 var0;
    D_801247A0_func_t var1;
    D_801247A0_func_t var2;

    var0 = *(s32 *)((u8 *)param_0 + 0x6c);
    if (param_1 == var0) {
        return;
    }
    var1 = D_801247A0[var0][2];
    if (var1) {
        var1(param_0);
    }
    var2 = D_801247A0[param_1][0];
    if (var2) {
        var2(param_0);
    }
    *(s32 *)((u8 *)param_0 + 0x6c) = param_1;
}

int func_80110720(param_0, param_1) s32 param_0; unsigned int param_1;
{
  int new_var;
  u8 new_var2;
  s32 local_0;
  new_var2 = param_1;
  local_0 = param_0;
  new_var = 0x70;
  local_0 += new_var;
  *((u8 *) local_0) = new_var2;
}

func_80110728(s32 param_0, s32 param_1){
    u8 *local_0 = param_0;
    local_0[0x71] = param_1;
}

void func_80110730(u16 *param_0, s32 param_1) {
    ((u8 *)param_0)[0x72] = param_1;
    func_80113410(param_0);
    if (param_1 != 0) {
        return;
    }
    func_8011337C(param_0);
}

void func_80110770(u8 *param_0, f32 *param_1)
{
  func_800EE7F8(param_0 + 0x74, param_1);
}

void func_80110790(u8 *param_0, f32 *param_1)
{
  func_800EE7F8(param_0 + 0x80, param_1);
}

void func_801107B0(s32 param_0)
{
  func_800F5A00(*(s32 *)(param_0 + 0x68));
}

void func_801107D0(Actor *param_0)
{
    func_800F5B38(param_0->unk68);
}

void func_801107F0(u8 *param_0, f32 *param_1)
{
  func_800EE7F8(param_1, param_0 + 0x74);
}

void func_80110818(s32 param_0, s32 param_1)
{
  func_800EE7F8(param_1, param_0 + 0x80);
}

int func_80110840(param_0) void *param_0;
{
    return ((int *)param_0)[0x1A];
}

int func_80110848(s32 param_0, s32 param_1, s32 param_2)
{
  func_800EE7F8(param_1 | 0, param_0 + 0x74);
  func_800EE7F8(param_2, param_0 + 0x80);
}

func_80110888(u8 *param_0) {
    return param_0[0x71];
}

func_80110890(u8 *param_0) {
    return param_0[0x72];
}

int func_80110898(param_0) s32 param_0[5];
{
  return param_0[25];
}

void func_801108A0(s32 param_0)
{
  s32 local_2;
  f32 local_0[3];
  f32 local_1[3];
  func_8010FFB0(*((s32 *) (param_0 + 0x64)), &local_0, &local_1);
  func_80110770(param_0, &local_0);
  func_80110790(param_0, &local_1);
  func_80111348(param_0);
  local_2 = func_801106A0(param_0);
  func_801106A8(param_0, 0);
  func_801106A8(param_0, local_2);
  _ncba1p_entrypoint_1(param_0);
  func_80112398(param_0);
}

void func_80110928(void *param_0) {
  s32 pad0;
    f32 sp20;
    s32 sp1C;

    func_800F5B38(*(s32 *)((u8 *)param_0 + 0x68), &sp1C);
    func_80110970(param_0, func_800136E4(sp20 + 180.0f));
}

void func_80110970(s32 param_0, f32 param_1) {
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2 = *(s32 *)(param_0 + 0x6C);
    if (local_2 == 8 || local_2 == 0x11 || local_2 == 0x13 || local_2 == 2) {
        func_800F5A00(*(s32 *)(param_0 + 0x68), local_0);
        local_0[1] += 100.0f;
        func_800EFA4C(local_1, 0.0f, param_1, 0.0f);
        func_8010FE14(*(s32 *)(param_0 + 0x64), local_0, local_1);
        func_800CA3A4(func_8010FF80(*(s32 *)(param_0 + 0x64)), 300.0f);
        func_801108A0(param_0);
    }
}

s32 func_80110A24(s32 param_0, f32 param_1[3], f32 param_2[3]){
    f32 local_0[3];

    func_80112524(param_0, local_0);
    func_800A516C(param_1, local_0, param_2);
    param_1[2] = 0.0f;
}

int func_80110A68(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  func_800A516C(param_1 | 0, param_2 | 0, param_0 + 0x74);
}

s32 func_80110A9C(void *param_0, s32 param_1, f32 *param_2)
{
  s8 _sfpad[8];
  s32 sp34;
  f32 sp28[3];
  f32 sp24;
  if ((((func_800F6BE4(*((s32 *) (((u8 *) param_0) + 0x68))) == 0) || (func_800F6438(*((s32 *) (((u8 *) param_0) + 0x68))) == 0)) || (func_800F6640(*((s32 *) (((u8 *) param_0) + 0x68))) == 0)) || (func_800F6690(*((s32 *) (((u8 *) param_0) + 0x68))) == 0))
  {
    return 0;
  }
  sp24 = func_80112550(param_0, &sp34);
  func_800EFB24(sp28, param_1, &sp34);
  *param_2 = sqrtf(((sp28[0] * sp28[0]) + (sp28[1] * sp28[1])) + (sp28[2] * sp28[2])) - sp24;
  return 1;
}

void func_80110B68(void *param_0, s32 param_1)
{
  void **new_var;
  void *s0;
  s0 = param_0;
  if (param_1 != 0)
  {
    if (func_800F6BE4(*(void **)((char *)s0 + 0x68)) != 0)
    {
      func_800F7B9C(*(void **)((char *)s0 + 0x68), 0x6C);
      func_80093700(func_800F53D0(*(void **)((char *)s0 + 0x68)), 1);
    }
  }
  else
  {
    if (func_800F6BE4(*(void **)((char *)s0 + 0x68)) != 0)
    {
      func_800F7B9C(*(void **)((char *)s0 + 0x68), 0x6B);
      func_80093700(func_800F53D0(*(void **)((char *)s0 + 0x68)), 0);
    }
  }
}

void func_80110BF0(PlayerState *param_0)
{
    s32 local_0;
    local_0 = (s32)param_0;
    _ncba1p_entrypoint_5(local_0, 1);
    _ncba1p_entrypoint_6(local_0, local_0 + 0x74);
    _ncba1p_entrypoint_7(local_0, local_0 + 0x80);
}

void func_80110C2C(PlayerState *param_0)
{
    s32 local_0;
    local_0 = _ncba1p_entrypoint_10();
    if (local_0 != 0 && local_0 != 3)
    {
        if (*(u8 *)((char *)param_0 + 0x72))
        {
            _ncba1p_entrypoint_13(param_0, (void *)((char *)param_0 + 0x74), (void *)((char *)param_0 + 0x80));
        }
        _ncba1p_entrypoint_5(param_0, 3);
    }
}

void func_80110C88(param_0) s32 param_0; {
    func_80110CC0(param_0, 550.0f, 620.0f, 150.0f, 10.0f);
}

void func_80110CC0(void *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    func_8011539C(param_0, param_1, param_2, param_3);
    func_80115D08(param_0, param_1, param_2, param_3, param_4);
}

void func_80110D08()
{
    func_80115864();
}

void func_80110D28(s32 param_0, s32 param_1) {
    s32 local_0 = param_1;
    func_80116050(param_0, local_0);
}

int func_80110D58(s32 param_0, f32 param_1)
{
  f32 new_var;
  new_var--;
  new_var = param_1;
  func_801125D8(param_0, new_var);
}

void func_80110D80()
{
    func_8011396C();
}

void func_80110DA0()
{
    func_80115460();
}

void func_80110DC0()
{
    func_8011546C();
}

void func_80110DE0()
{
    func_80115478();
}

int func_80110E00(param_0, param_1) void * param_0; s32 param_1; {
    func_80114D98(param_0);
    switch (param_1) {
    case 2:
        switch (((local_type *) D_801247A0)[*(s32 *)((u8 *)param_0 + 0x6C)].local_1) {
        case 1: func_80111198(param_0, func_800F5AE0(*(s32 *)((u8 *)param_0 + 0x68))); break;
        case 2: func_80111198(param_0, func_80115E88(param_0)); break;
        }
        return func_80111154(param_0, func_801112B0(param_0) + 180.0f);
        break;
    case 0: return func_801111D0(param_0, -45.0f); break;
    case 1: return func_801111D0(param_0, 45.0f); break;
    }
    return 0;
}

s32 func_80110EFC(s32 *param_0)
{
  s32 temp;
  temp = param_0[0x1b];
  if (((s16 *) D_801247A0)[temp * 8 + 6])
  {
    return func_80110E00();
  }
  return 0;
}

void func_80110F44(void *param_0)
{
  f32 local_0[3];
  f32 local_1[3];
  f32 local_2[3];
  s32 local_3;
 func_80112524(param_0, local_0); func_801107F0(param_0, local_1);
  func_800EFB24(local_2, local_1, local_0);
  local_3 = func_800F53D0((s32) func_80110840(param_0));
  func_800A4EFC((0, local_3), func_800EEFFC(local_2));
  if (((s32 *) param_0)[27] == 0x11)
  {
    _ncbastring_entrypoint_4(param_0);
  }
}

void *func_80110FCC(void *param_0, s32 param_1)
{
  void *old;

  old = param_0;
  param_0 = defrag(param_0);
  if (old != param_0)
  {
    func_80110280(param_0);
  }
  *((s32 *) (((char *) param_0) + 0x64)) = param_1;
  return param_0;
}

void func_80111018(s32 param_0, s32 param_1)
{
  func_80113410();
  rare_memcpy(param_0 + 0x98, param_1 + 0x98, D_80137372 - 0x98);
  func_8011337C(param_0);
  _ncba1p_entrypoint_1(param_0);
}

void func_8011106C(s32 param_0, s32 param_1)
{
  func_800EE7F8(param_1, param_0 + 0x8C);
}

int func_80111094(s32 param_0, s32 param_1)
{
  func_800EE780(param_1 | 0, param_0 + 0x74, param_0 + 0x8C);
}

void func_801110C4(s32 param_0, s32 param_1)
{
    func_800EFB24(param_0 + 0x8C, param_1, param_0 + 0x74);
}

int func_801110EC(s32 param_0, s32 param_1, s32 param_2)
{
    if (((s32 *)param_0)[0x1B] == 0x14) {
        _ncbatarget_entrypoint_5(param_0, param_1);
        _ncbatarget_entrypoint_4(param_0, param_2);
    } else {
        return 0;
    }
    return 1;
}

int func_8011113C()
{
  s32 local_0 = 0;
  return local_0 | 0;
}

int func_80111144()
{
  s32 local_0;
  local_0 = 0;
  return local_0 | 0;
}

int func_8011114C()
{
  s32 local_0;
  local_0 = 0;
  return local_0 | 0;
}

s32 func_80111154(s32 param_0, f32 param_1) {
    func_80112D90(param_0, func_800136E4(param_1), 75.0f, 2, 2);
    return 1;
}

s32 func_80111198(s32 param_0, f32 param_1) {
    func_80115DEC(param_0, func_800136E4(param_1), 75.0f);
    return 1;
}

int func_801111D0(void *param_0, f32 param_1) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_5[3];
    func_801107F0(param_0, local_0);
    func_80112550(param_0, local_2);
    func_800EFB24(local_1, local_0, local_2);
    func_800F1EA4(local_1, &local_3);
    local_4 = func_800136E4(local_3 + param_1);
    if (func_80112E84(param_0) != 1) {
        func_800EF934(local_5, local_1, param_1 * D_80126540);
        func_800EF04C(local_5, local_2);
        if (!func_8011349C(local_0, local_5)) return 0;
    }
    func_80112D90(param_0, local_4, 45.0f, 1, 2);
    return 1;
}

f32 func_801112B0(param_0) void * param_0; {
    void *p = func_800F53D0(*(s32 *)((u8 *)param_0 + 0x68));
    f32 rv;
    if (func_80092BC4(p) != 0) { rv = func_80092BD0(p) - 180.0f; }
    else { rv = func_800F5F24(*(s32 *)((u8 *)param_0 + 0x68)); }
    return rv;
}

int func_80111310()
{
    func_800A509C(func_800F53D0(func_80110840()) | 0);
}

s32 func_80111340() 
{
    return 0x8C;
}

void func_80111348(param_0) void * param_0; {
    func_801113B8(param_0);
    func_80111590(param_0, 10.0f, 10.0f, 120.0f, 120.0f);
    func_80111B8C(param_0, 1.4f, 14.0f);
    func_801120CC(param_0, 2000.0f, 4000.0f, -4000.0f);
}

void func_801113B8(param_0) u8 * param_0; {
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0x34))) + 0x10);
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0x34))) + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0x34))) + 0x38);
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0x34))) + 0x44);
}

void func_80111410(State111410 *param_0, f32 *param_1, f32 *param_2, f32 param_3) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4;
    local_0[0] = func_80013728(param_1[0] - param_2[0]);
    local_0[1] = func_80013728(param_1[1] - param_2[1]);
    local_0[2] = func_80013728(param_1[2] - param_2[2]);
    local_2 = sqrtf(local_0[0] * local_0[0] + local_0[1] * local_0[1] + local_0[2] * local_0[2]);
    if (local_2 != 0.0f) {
        local_1 = func_800D8FF8();
        local_4 = 1.0f / local_2;
        local_3[0] = (param_0->local_0[2] * local_1) * (local_0[0] * local_4);
        local_3[1] = (param_0->local_0[3] * local_1) * (local_0[1] * local_4);
        local_3[2] = (param_3 * local_1) * (local_0[2] * local_4);
        local_3[0] = func_800F212C(local_3[0], local_0[0]);
        local_3[1] = func_800F212C(local_3[1], local_0[1]);
        local_3[2] = func_800F212C(local_3[2], local_0[2]);
        param_2[0] += local_3[0];
        param_2[1] += local_3[1];
        param_2[2] += local_3[2];
    }
}

void func_80111590(u8 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {

    (*(f32 **)(param_0 + 0x34))[0] = param_1;
    (*(f32 **)(param_0 + 0x34))[1] = param_2;
    (*(f32 **)(param_0 + 0x34))[2] = param_3;
    (*(f32 **)(param_0 + 0x34))[3] = param_4;
}

s32 func_801115C8(f32 *param_0, f32 param_1, f32 *param_2, f32 *param_3, f32 *param_4) {
    f32 sp1C;
    f32 temp_f0;

    sp1C = func_800EEAA4(param_0, param_2);
    temp_f0 = func_800EEAA4(param_0, param_3);
    if ((((sp1C < param_1) && (param_1 < temp_f0)) || ((param_1 < sp1C) && (temp_f0 < param_1))) && (temp_f0 != sp1C)) {
        *param_4 = (param_1 - sp1C) / (temp_f0 - sp1C);
        return 1;
    }
    return 0;
}

void func_80111680(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 param_5, f32 *param_6)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    s32 local_7;
    s32 local_8;
    f32 local_9 = 0.0f;
    f32 local_10 = 0.0f;
    f32 local_11;
    f32 local_12[3];
    f32 local_13;
    f32 local_14;
    f32 local_15[3];
    f32 local_16[3];
    s32 local_17 = 0;
    s32 local_18 = 0;
    f32 local_19;
    if (func_800EEAD4(param_0, param_1) < 0.01f) {
        func_800EE7F8(param_1, param_0);
        func_800EFD24(param_3);
    }
    if (func_800EEAD4(param_0, param_6) < 0.01f) {
        func_800EFB24(local_15, param_2, param_0);
        if (func_800EEEA8(local_15)) func_800EFA4C(local_15, 1.0f, 0.0f, 0.0f);
        func_800EFA4C(local_16, 0.0f, 1.0f, 0.0f);
        func_800EE97C(local_12, local_15, local_16);
        func_800EF2A0(local_12);
        local_13 = func_800EEAA4(local_12, param_0);
        func_800EF2A0(local_15);
        local_14 = func_800EEAA4(local_15, param_0);
        local_17 = local_18 = 1;
    }
    local_8 = func_800D8FEC() * 5;
    local_11 = 0.5f;
    for (local_7 = 0; local_7 < local_8; local_7++) {
        func_800EFB24(local_0, param_0, param_1);
        func_800EF334(local_0, param_4);
        func_800EFB24(local_1, local_0, param_3);
        func_800EF334(local_1, param_5);
        func_800EE7F8(local_2, param_3);
        func_800EE7F8(local_3, local_2);
        func_800EF174(local_3, local_1, 0.0033333334f);
        func_800EE7F8(local_4, param_1);
        func_800EE780(local_6, local_2, local_3);
        func_800EF334(local_6, local_11 * 0.0033333334f);
        if (local_17 || local_18) {
            func_800EE780(local_5, local_4, local_6);
            if (local_17 && func_801115C8(local_12, local_13, param_1, local_5, &local_19)) {
                func_800EF334(local_6, local_19);
                local_17 = 0;
                func_800EF174(local_3, local_12, -func_800EEAA4(local_3, local_12));
            } else if (local_18 && func_801115C8(local_15, local_14, param_1, local_5, &local_19)) {
                func_800EF334(local_6, local_19);
                local_18 = 0;
                func_800EF174(local_3, local_15, -func_800EEAA4(local_3, local_12));
            }
        }
        func_800EE780(local_5, local_4, local_6);
        local_10 += func_800EEAD4(param_3, local_3) / local_8;
        func_800EE7F8(param_1, local_5);
        func_800EE7F8(param_3, local_3);
        local_9 += func_800EEF94(local_6);
    }
    func_800EE7F8(param_6, param_0);
}

void func_80111A38(u8 *param_0, f32 *param_1, f32 *param_2)
{
    f32 local_0[3];
    u8 *local_1;

    func_80112550(param_0, local_0);
    local_1 = *(u8 **)(param_0 + 0x34);
    func_80111680(param_1, param_2, local_0, local_1 + 0x24,
        *(f32 *)(local_1 + 0x30), *(f32 *)(local_1 + 0x34),
        local_1 + 0x38);
}

void func_80111A98(u8 *param_0) {
    func_801107F0(param_0, (f32 *)(*(u8 **)(param_0 + 0x34) + 0x5C));
}

void func_80111ABC(u8 *param_0, f32 *param_1)
{
    func_800EE7F8((f32 *)(*(u8 **)(param_0 + 0x34) + 0x68), param_1);
}

extern void func_80113640(void *, f32 *, f32 *);

void func_80111AE0(u8 *param_0, f32 *param_1) {
    f32 local_0[3];
    s32 local_1;

    local_1 = func_80110898();
    func_801107F0(param_0, local_0);
    if (func_8010FFD0(local_1) != 0) {
        func_800EFD24((*(s32 *)((s8 *)(param_0) + (0x34))) + 0x24);
        func_80113640(param_0, local_0, param_1);
        func_80110770(param_0, param_1);
        return;
    }
    func_80111A98(param_0);
    func_80111ABC(param_0, param_1);
    func_80111A38(param_0, param_1, local_0);
    func_80110770(param_0, local_0);
}

void func_80111B8C(u8 *param_0, f32 param_1, f32 param_2) {
  f32 local_0;
  s32 local_1;
  local_1 = func_800F53E4(func_80110840());
  if (local_1 != 0) {
        local_0 = func_800A3048(local_1);
    }
  else {
        local_0 = 1.0f;
    }
  *(f32 *)((char *)*(u8 **)((char *)param_0 + 0x34) + 0x30) = (f32) (param_1 * local_0);
  *(f32 *)((char *)*(u8 **)((char *)param_0 + 0x34) + 0x34) = (f32) (param_2 * local_0);
}

void func_80111C04(u8 *param_0) {
    f32 local_6;
    f32 local_5;
    f32 local_1;
    f32 local_4;
    f32 local_3;
    f32 local_0;
    f32 local_2;

    func_801107F0(param_0, (*(u8 **)(param_0 + 0x34)) + 0x50);
    func_800EFB24(&local_0, (*(u8 **)(param_0 + 0x34)) + 0x68, (*(u8 **)(param_0 + 0x34)) + 0x5C);
    func_800EFB24(&local_1, (*(u8 **)(param_0 + 0x34)) + 0x50, (*(u8 **)(param_0 + 0x34)) + 0x5C);
    func_800EF2A0(&local_0);
    func_800EF2A0(&local_1);
    local_2 = func_800EEAA4(&local_0, &local_1);
    if ((local_2 < 0.0f) || (*(f32 *)(*(u8 **)(param_0 + 0x34) + 0x74) < 0.0f)) {
        func_80110770(param_0, (*(u8 **)(param_0 + 0x34)) + 0x5C);
    }
    *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x74) = local_2;
}

int func_80111CC8(s32 param_0, s32 param_1)
{
  f32 local_1[3];
  f32 local_2[3];
  s32 local_0;
  local_0 = func_80110898(param_0);
  func_801107F0(param_0, local_1);
  if (func_8010FFD0(local_0) != 0)
  {
    func_800EFD24(*(u8 **)(param_0 + 0x34) + 0x24);
    func_80113640(param_0, local_1, param_1);
    func_80110770(param_0, param_1);
    goto block_4;
  }
  func_80111A98(param_0);
  func_80111ABC(param_0, param_1);
  func_80111A38(param_0, param_1, local_1);
  func_8011106C(param_0, local_2);
  func_800EF04C(local_1, local_2);
  func_80110770(param_0, local_1);
  if (func_8011329C(param_0) != 0)
  {
    func_80111C04(param_0);
    return 1;
  }
block_4:
  return 0;
}

void func_80111DB0(u8 *param_0, f32 *param_1, f32 *param_2, f32 *param_3) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    func_800EFB24(local_0, param_1, param_2);
    local_1 = func_800EEF94(local_0);
    if (0.01f < local_1) {
        local_2 = func_800FF060(local_1, param_3, *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x80), *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x84), *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x7C), func_800D8FF8());
        if (local_1 < local_2) {
            local_2 = local_1;
            *param_3 = 0.0f;
        }
        func_800EF174(param_2, local_0, local_2 / local_1);
        return;
    }
    *param_3 = 0.0f;
}

void func_80111E88(f32 param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_0 = func_800D8FF8();
    if (param_0 == *param_1) {
        *param_2 = 0.0f;
        return;
    }
    local_2 = (param_0 - *param_1) * param_3;
    local_3 = (local_2 - *param_2) * param_4;
    *param_2 += local_3 * local_0;
    local_1 = *param_1 + *param_2 * local_0;
    if (param_0 < *param_1) {
        if (local_1 < param_0) {
            local_1 = param_0;
            *param_2 = 0.0f;
        }
    } else {
        if (param_0 < local_1) {
            local_1 = param_0;
            *param_2 = 0.0f;
        }
    }
    *param_1 = local_1;
}

void func_80111F70(u8 *param_0, u8 *param_1, f32 *param_2, s32 param_3, s32 param_4) {
    f32 local_0;

    local_0 = param_2[1];
    func_80111DB0(param_0, param_1, param_2, param_3);
    param_2[1] = local_0;
    func_80111E88(*(f32 *)(param_1 + 4), &param_2[1], param_4, *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x30), *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x34));
}

s32 func_80111FD4(u8 *param_0, s32 *param_1)
{
  f32 local_0[3];
  f32 local_1[3];
  s32 local_2;
  u8 *local_3;
  local_2 = func_80110898();
  func_801107F0(param_0, &local_0);
  if (func_8010FFD0(local_2) != 0)
  {
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x34)))) + 0x78)) = 0.0f;
    func_80113640(param_0, &local_0, param_1);
    func_80110770(param_0, param_1);
    goto block_4;
  }
  func_80111A98(param_0);
  func_80111ABC(param_0, param_1);
  if (1)
  {
    local_3 = *((u8 **) (((s8 *) param_0) + 0x34));
    func_80111F70(param_0, param_1, &local_0, local_3 + 0x78, local_3 + 0x88);
  }
  func_8011106C(param_0, &local_1);
  func_800EF04C(&local_0, &local_1);
  func_80110770(param_0, &local_0);
  if (func_8011329C(param_0) != 0)
  {
    func_80111C04(param_0);
    return 1;
  }
  block_4:
  return 0;

}

void func_801120CC(u8 *param_0, f32 param_1, f32 param_2, f32 param_3) {
    s32 local_0;
    f32 local_1;
    u8 *tmp1;
    u8 *tmp2;
    u8 *tmp3;

    local_0 = func_800F53E4(func_80110840());
    if (local_0 != 0) {
        local_1 = func_800A3048(local_0);
    } else {
        local_1 = 1.0f;
    }
    *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x7C) = param_1 * local_1;
    *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x80) = param_2 * local_1;
    *(f32 *)(*(u8 **)(param_0 + 0x34) + 0x84) = param_3 * local_1;
}
