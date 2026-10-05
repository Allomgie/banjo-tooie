/*
 * 1EEC780 -- second of the three units the former 1EEC090 consists of,
 * from func_80112E90 to func_80113D30. See 1EEC090.c for why the range is
 * three objects.
 *
 * Its .rodata (0x1EFFEA0..0x1EFFEC4) holds the constants and the jump table
 * of func_8011309C and the constants of func_801134F0, func_80113688 and
 * func_80113978. Like 1EEC090 it holds counterparts of functions from
 * Banjo-Kazooie's nc/dynamicCamera.c, and like it it is used by 1EE9AB0 and
 * the nc/ba overlays (func_80113D30 only by 1EE9AB0).
 *
 * Functions defined in 1EEC090 are declared here in exactly the form their
 * definitions had (prototype for ANSI, empty parameter list for K&R), so
 * every call compiles as it did in the combined file.
 */

#include "core2/1EEC090.h"
#include <types.h>
extern f32 func_800136E4(f32);
typedef struct { u8 pad[12]; s16 local_0, local_1; f32 local_2, local_3, local_4, local_5, local_6; } State112A84;
typedef struct { u8 pad[0x60]; State112A84 *local_0; } Actor112A84;
extern void func_801107F0(Actor112A84 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
typedef struct { u8 pad[0xC]; s16 local_0, local_1; f32 local_2, local_3, local_4, local_5, local_6; } Motion112D90;
typedef struct { u8 pad[0x60]; Motion112D90 *local_0; } Actor112D90;
typedef struct { f32 *local_0; s32 local_1; } Table112E98;
extern Table112E98 D_80124A38;
extern Table112E98 D_80124A40;
extern Table112E98 D_80124A48;
extern f32 func_800F0E00(f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_80110770(void *, f32 *);
extern void func_801113B8(void *);
typedef struct { u8 pad00[0x10]; s32 mode; } LocalSearch;
typedef struct { u8 pad00[0x28]; LocalSearch *search; } LocalOwner;
extern f32 func_800F5B64(s32, f32 *);
extern void func_800EF410(f32 *, f32 *);
extern void func_800EE7F8();
extern void func_800EFD24(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
s32 func_800E8714(s32 param_0);
void func_800E8870(s32 param_0, f32 param_1);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF174(s32 param_0, s32 param_1, f32 param_2);
typedef struct { s32 pad[2]; s32 local_0; } Hit113688;
extern f32 func_800EEB40(f32 *, f32 *);
extern Hit113688 *func_800FAB50(f32 *, f32 *, f32 *, s32, f32);
extern Hit113688 *func_800FB3C0(f32 *, f32 *, f32, f32 *, s32, s32);
extern void func_800AAD28(f32 [3][3]);
extern s32 func_80110060(s32);
f32 func_80013A7C(f32 param_0);
s32 func_800C6A7C(s32 param_0, s32 param_1, f32 *param_2, s32 param_3);
void func_800EF2A0(f32 *param_0);
extern float func_800EEF94(s32*);
typedef struct { u8 pad0[0x14]; u8 disabled; u8 pad15[3]; s32 value18,value1C,value20,value24; u8 pad28[0x14]; s32 count3C,count40,count44,count48; f32 point4C[3],point58[3],point64[3],point70[3]; s32 direction7C; } LocalControls;
typedef struct { u8 pad0[0x28]; LocalControls *controls; } LocalState;
extern s32 func_800F711C(s32);
extern f32 func_800F0DC0(f32,f32);
typedef struct { u8 pad0[0xC]; s16 local_0; u8 padE[0xA]; s32 local_1[4]; u8 pad28[0xC]; u8 local_2[4]; s8 local_3[4]; s32 local_4[4]; f32 local_5[4][3]; } State113D30;
typedef struct { u8 pad0[0x28]; State113D30 *local_0; } Owner113D30;
extern void *func_80110840(Owner113D30 *);
extern void *func_80110898(Owner113D30 *);
extern void *func_8010FF80(void *);
extern void *func_800A940C(void *);
extern void func_800CA7E4(void *, f32 *);
extern void *func_800CA7A4(void *);
extern void mlMtxSet(void *);
extern void func_80019224(f32 *, f32 *);
extern void func_800E8830(s32, f32 *);
extern s32 func_800E8918(s32, void *, f32 *, s32);
extern s32 func_8001211C(void);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
void func_80113688();
void func_80114CF4();
void func_80112D90(Actor112D90 *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4);
void func_80112E50(u8 *param_0, f32 param_1, s32 param_2);

s32 func_80112E90() 
{
    return 0x80;
}

s32 func_80112E98(void *param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 param_4, u32 param_5) {
    f32 local_0[3];
    f32 local_1, local_2;
    f32 local_3[3];
    s32 local_4;
    f32 local_5[3];
    f32 *local_6;
    Table112E98 *local_7;
    local_1 = func_800F0E00(150.0f, param_3 - 100.0f);
    switch (param_4) {
        case 1: local_7 = &D_80124A40; break;
        case 2:
        case 3: local_7 = &D_80124A48; break;
        case 0:
        default: local_7 = &D_80124A38; local_1 = 150.0f; break;
    }
    for (local_6 = local_7->local_0; local_6 < local_7->local_0 + local_7->local_1; local_6++) {
        local_2 = *local_6;
        if (param_4 == 3) local_2 = -local_2;
        func_800EFA20(local_0, param_2, -param_3);
        func_800EF934(local_0, local_0, local_2);
        func_800EE780(local_5, param_1, local_0);
        func_800FAB50(param_1, local_5, local_3, param_5, 50.0f);
        func_800FB3C0(param_1, local_5, 50.0f, local_3, 4, param_5);
        if (func_800EEAD4(param_1, local_5) > local_1) {
            func_80110770(param_0, local_5);
            func_801113B8(param_0);
            return 1;
        }
    }
    return 0;
}

s32 func_8011309C(LocalOwner *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8;
    f32 local_9;
    local_9 = func_800F5B64(func_80110840(param_0), local_3);
    func_801107F0(param_0, local_5);
    func_800EFB24(local_2, local_3, local_5);
    func_800EF410(local_1, local_2);
    func_800EE7F8(local_4, local_3);
    local_8 = func_800EEF94(local_2);
    if (1.5e+03f < local_8) {
        func_800EFA20(local_2, local_1, 1.5e+03f);
        func_800EE780(local_4, local_5, local_2);
    }
    switch (param_0->search->mode) {
    case 0: func_800EFD24(local_6); break;
    case 1:
        func_800EFA20(local_6, local_1, local_9);
        func_800EF934(local_6, local_6, -90.0f);
        break;
    case 2:
        func_800EFA20(local_6, local_1, local_9);
        func_800EF934(local_6, local_6, 90.0f);
        break;
    case 3: func_800EFA4C(local_6, 0.0f, local_9, 0.0f); break;
    case 4: func_800EFD24(local_6); break;
    }
    func_800EE780(local_7, local_6, local_4);
    if (func_800C6A7C(local_5, local_7, local_0, 0x860020)) {
        param_0->search->mode++;
        if (param_0->search->mode >= 5) {
            param_0->search->mode = 0;
            return func_80112E98(param_0, local_3, local_1, local_8, param_1, 0x860020);
        }
    } else {
        param_0->search->mode = 0;
    }
    return 0;
}

int func_8011329C(s32 param_0)
{
  f32 local_1[3];
  f32 local_2[3];
  s32 local_0;
  local_0 = func_8010FFD0(func_80110898(param_0));
  if (local_0 != 0)
  {
    return 0;
  }
  func_801107F0(param_0, &local_2);
  func_800EE7F8(&local_1, &local_2);
  func_80113688(param_0, *((s32 *) (param_0 + 0x28)), &local_2);
  func_80110770(param_0, &local_2);
  return !func_800EECE0(&local_1, &local_2);
}

int func_80113320(s32 param_0)
{
  s32 local_3;
  f32 local_1[3];
  f32 local_2[3];
  f32 local_0[3];
  s32 new_var;
  func_800EE7F8(local_0);
  local_3 = func_800F5B64(func_80110840(param_0), local_1);
  local_3 = 0;
  if (func_800C6A7C(local_1, local_0, local_2, 0x860020) != local_3)
  {
    new_var = local_3;
    return new_var;
  }
  return 1;
}

void func_8011337C(u8 *param_0) {
    s32 var_s0;

    func_801107F0(param_0, *(u8 **)((s8 *)(param_0) + (0x28)));
    *(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x28)))) + (0x10)) = 0;
    var_s0 = 0;
    *(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x28)))) + (0x14)) = 0;
    do {
        *(u8 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0x28))) + var_s0)) + (0x34)) = func_800E8714(1);
        func_800E8870(*(u8 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0x28))) + var_s0)) + (0x34)), 10.0f);
        var_s0 += 1;
    } while (var_s0 != 4);
}

void func_80113410(u8 *param_0) {
    s32 local_0;
    u8 local_1;

    local_0 = 0;
    do {
        local_1 = (*(u8 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x28))) + local_0)) + (0x34)));
        if (local_1 != 0) {
            func_800E87E0(local_1);
            (*(s8 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x28))) + local_0)) + (0x34))) = 0;
        }
        local_0 += 1;
    } while (local_0 != 4);
}

void func_8011347C(void *arg)
{
    func_801107F0(arg, *(s32 *)((char *)arg + 0x28));
}

s32 func_8011349C(f32 *param_0, f32 *param_1)
{
  f32 local_0[3];
  f32 local_C[3];

  func_800EE7F8(local_0, param_1);
  if (func_800FAB50(param_0, local_0, local_C, 0x820020, 50.0f) != 0) {
    return 0;
  }
  return 1;
}

void func_801134F0(f32 *param_0, f32 param_1) {
    f32 local_0[3];
    s32 local_1 = 0;
    f32 local_2;
    if (func_800C6C94(param_0, param_1, local_0, 0x820020)) {
        local_2 = 0.01f;
        for (;;) {
        if (func_800EEFD4(local_0) < local_2) return;
        func_800EF174(param_0, local_0, 1.5f);
        local_1++;
        if (!func_800C6C94(param_0, param_1, local_0, 0x820020)) break;
        if (local_1 == 1) break;
        }
    }
}

void func_801135D0(s32 *param_0, s32 *param_1, s32 *param_2, s32 param_3, s32 param_4) {
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2[3];
    f32 neg_val;

    func_800EFB24(local_0, param_3, param_2);
    func_800EFB24(local_1, param_1, param_0);
    func_800EFB24(local_2, local_0, local_1);
    neg_val = -func_800EEAA4(param_4, local_2);
    func_800EF174(param_3, param_4, neg_val);
}

void func_80113640(s32 p0, s32 p1, s32 p2) {
    u8 sp24[12];
    func_800FAB50(p1, p2, sp24, 0x820020, 45.0f);
}

void func_80113688(param_0, param_1, param_2) s32 param_0; f32 * param_1; f32 * param_2; {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    Hit113688 *local_3;
    Hit113688 *local_4;
    f32 local_5[3][3];
    func_801134F0(param_1, 45.0f);
    if (func_800EEB40(param_1, param_2) < 0.0001f) return;
    func_800EE7F8(local_1, param_1);
    func_800EE7F8(local_2, param_2);
    local_3 = func_800FAB50(local_1, local_2, local_0, 0x820020, 45.0f);
    if (!local_3) local_4 = func_800FB3C0(local_1, local_2, 45.0f, local_0, 3, 0x820020);
    if (local_3 || local_4) {
        func_800AAD28(local_5);
        func_80114CF4(func_80110060(func_80110898(param_0)), local_5, local_3 ? local_3->local_0 : local_4->local_0, local_0);
        func_801135D0(local_1, local_2, param_1, param_2, local_0);
        func_800FAB50(param_1, param_2, local_0, 0x820020, 45.0f);
    }
}

int func_801137E4(void *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4)
{
  f32 local_1[3];
  f32 local_0[3];
  f32 local_2;
  if (func_800C6A7C(param_1, param_3, &local_1, 0x860020))
  {
    func_800EFB24(&local_0, param_3, param_2);
    func_800EF2A0(&local_0);
    local_2 = func_800EEAA4(&local_0, &local_1);
    if (local_2 < 0.0f)
    {
      return 0;
    }
    else
    {
      param_4[0] = 90.0f - func_80013A7C(local_2) + 5.0f;
      return 1;
    }
  }
  return 0;
}

s32 func_801138A0(u8 *param_0) {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x28)));
    if ((*(u8 *)((s8 *)(local_0) + (0x14))) != 0) {
        return 0;
    }
    if ((*(s16 *)((s8 *)(local_0) + (0xC))) >= 4) {
        (*(s16 *)((s8 *)(local_0) + (0xE))) = (s16) ((*(s16 *)((s8 *)(local_0) + (0xE))) + 1);
    } else {
        (*(s16 *)((s8 *)(local_0) + (0xE))) = 0;
    }
    return (*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x28)))) + (0xE))) >= 5;
}

void func_801138F4(s32 param_0) {
    s32 sp4C[3];
    s32 sp40[3];
    s32 sp34[3];
    s32 sp28[3];

    func_80112550(param_0, sp4C);
    func_801107F0(param_0, sp40);
    func_800EFB24(sp34, sp4C, sp40);
    func_800EF410(sp28, sp34);
    func_80112E98(param_0, sp4C, sp28, func_800EEF94(sp34), 0, 0x20020);
}

void func_8011396C(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x28)))[20] = v;
}

f32 func_80113978(LocalState *param_0,s32 param_1,s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    f32 local_3;
    s32 local_4;
    local_2=func_80110840(param_0);
    local_3=0.0f;
    local_4=func_8010FF80(func_80110898(param_0));
    if (!func_800F711C(local_2) || param_0->controls->disabled) return 0.0f;
    func_80112550((PlayerState *)param_0,local_0);
    func_800CA7E4(local_4,local_1);
    if (param_1) {
        s32 local_5;
        s32 local_6;
        s32 local_7;
        f32 local_8;
        f32 local_9;
        f32 local_10[2];
        f32 local_11[3];
        f32 local_12[3];
        local_6=0;
        local_5=0;
        local_7=0;
        if (param_0->controls->count40>=4) { local_6++; local_5--; }
        if (param_0->controls->count48>=4) { local_6++; local_5++; }
        local_8=0.0f;
        if (local_6) {
            if (!local_5) local_5=param_0->controls->value24<param_0->controls->value1C ? 1 : -1;
            if (local_5<0) {
                if (func_801137E4(param_0,local_0,local_1,param_0->controls->point58,&local_8)) local_7=1;
            } else {
                if (func_801137E4(param_0,local_0,local_1,param_0->controls->point70,&local_8)) local_7=1;
            }
        }
        if (local_7) {
            func_800EFB24(local_12,local_1,local_0);
            func_800F1A88(local_12,local_10);
            local_9=(local_5<0 ? -1.0f : 1.0f)*local_8;
            func_800EF934(local_11,local_12,local_9*0.2f);
            func_800EF04C(local_11,local_0);
            if (func_8011349C(local_1,local_11)) {
                func_80112D90(param_0,func_800136E4(local_10[1]+local_9),local_8*0.25f,1,1);
                param_0->controls->direction7C=local_5;
            }
        } else if (param_0->controls->direction7C) {
            func_80112E50(param_0,param_0->controls->direction7C*2.5f,1);
            param_0->controls->direction7C=0;
        }
    }
    if (param_2) {
        s32 local_13;
        s32 local_14;
        s32 local_15;
        f32 local_16;
        local_14=0;
        local_13=0;
        local_15=0;
        if (param_0->controls->count44>=4) { local_14++; local_13--; }
        if (param_0->controls->count3C>=4) { local_14++; local_13++; }
        local_16=0.0f;
        if (local_14) {
            if (!local_13) local_13=param_0->controls->value18<param_0->controls->value20 ? 1 : -1;
            if (local_13<0) {
                if (func_801137E4(param_0,local_0,local_1,param_0->controls->point64,&local_16)) local_15=1;
            } else {
                if (func_801137E4(param_0,local_0,local_1,param_0->controls->point4C,&local_16)) local_15=1;
            }
        }
        if (local_15) local_3=func_800F0DC0(local_16,10.0f);
    }
    return local_3;
}

void func_80113D30(Owner113D30 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    s32 local_7;
    f32 local_8;
    void *local_9;
    void *local_10;
    void *local_11;
    local_9 = func_80110840(param_0);
    local_10 = func_8010FF80(func_80110898(param_0));
    local_11 = func_800A940C(local_9);
    local_8 = func_80112550((PlayerState *)param_0, local_2);
    func_800CA7E4(local_10, local_4);
    func_800EFB24(local_1, local_2, local_4);
    func_800EF410(local_0, local_1);
    func_800EE7F8(local_3, local_2);
    mlMtxSet(func_800CA7A4(local_10));
    for (local_7 = 0; local_7 < 4; local_7++) {
        switch (local_7) {
        case 0:
            func_800EFA4C(local_5, 0.0f, -local_8, 0.0f);
            break;
        case 1:
            func_800EFA4C(local_5, local_8, 0.0f, 0.0f);
            break;
        case 2:
            func_800EFA4C(local_5, 0.0f, local_8, 0.0f);
            break;
        case 3:
            func_800EFA4C(local_5, -local_8, 0.0f, 0.0f);
            break;
        }
        func_80019224(local_5, local_5);
        func_800EE780(local_6, local_5, local_3);
        func_800E8830(param_0->local_0->local_2[local_7], local_6);
        param_0->local_0->local_3[local_7] = func_800E8918(param_0->local_0->local_2[local_7], local_11, param_0->local_0->local_5[local_7], 0);
        if (param_0->local_0->local_3[local_7] == 0) {
            if (param_0->local_0->local_1[local_7] == 0) {
                param_0->local_0->local_1[local_7] = func_8001211C();
            }
            param_0->local_0->local_4[local_7]++;
        } else {
            param_0->local_0->local_1[local_7] = 0;
            param_0->local_0->local_4[local_7] = param_0->local_0->local_1[local_7];
        }
    }
    param_0->local_0->local_0 = 0;
    for (local_7 = param_0->local_0->local_0; local_7 < 4; local_7++) {
        if (param_0->local_0->local_4[local_7] >= 4) {
            param_0->local_0->local_0++;
        }
    }
}
