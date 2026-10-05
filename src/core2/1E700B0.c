/*
 * 1E700B0 -- second half of the former 1E6F080, from func_800967C0 on.
 * See 1E6F080.c for why the range is two objects.
 *
 * Functions defined in 1E6F080 are declared here in exactly the form their
 * definitions had (prototype for ANSI, empty parameter list for K&R), so
 * every call compiles as it did in the combined file.
 */

#include "core2/1E6F080.h"
#include "types.h"
#include "macros.h"
#define LOCAL_COLLISION(p) (*(LocalCollision **)((u8 *)(p) + 0x94))
#define STATE(p) (*(LocalState **)((u8 *)(p)+0x98))
extern f32 mlAbsF(f32);
typedef struct { void *floor; f32 value04, value08; u8 pad0C[12]; u8 previous18; u8 pad19[3]; void *triangle1C; u8 pad20[0x30]; Actor *actor50; u8 hit54, hit55, stable56, pad57; f32 delta58[3]; f32 target64, target68; u8 triangle6C[12]; f32 position78[3]; f32 previous84[3]; f32 delta90[3]; s32 mode9C; u8 belowA0, clampedA1, restoreA2, countA3, activeA4; } LocalCollision;
extern void func_8009C128(PlayerState *, f32 *);
extern void func_8009C15C(PlayerState *, f32 *);
extern void func_8009C0F8(PlayerState *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
typedef struct { f32 local_0; f32 local_1[3], local_2[3], local_3[3], local_4[3]; } Hit967C8;
typedef struct { s32 local_0; Hit967C8 local_1[1]; } Hits967C8;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF2A0(f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_800BEE40(f32 *, f32 *, f32 *, f32);
typedef s16 Triangle96ACC[3][3];
typedef struct { s32 local_0; Hit967C8 local_1[1]; } Result96ACC;
extern Triangle96ACC D_80126D20[];
extern Result96ACC D_80126E30;
extern s32 func_800BED70(f32 *, f32 *, Triangle96ACC **, s32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern s32 func_800EECE0(f32 *, f32 *);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
typedef struct { u8 pad[0x98]; f32 *local_0; } State97104;
extern void func_8009BB24(State97104 *, f32 *);
typedef struct { f32 direction[3], position[3], offset[3]; u8 active, state; } LocalState;
typedef struct { f32 local_0[3], local_1[3]; } Motion97530;
typedef struct { u8 pad[0x98]; Motion97530 *local_0; } Actor97530;
extern void func_800EF04C(f32 *, f32 *);
extern void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
extern void *func_800C6C94(f32 *, f32, f32 *, u32);
typedef struct { f32 local_0[3]; u8 pad_0[0x18]; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; f32 local_4; f32 local_5; } local_0;
void func_80097858();
void func_8009788C();
void func_800978A4();
void func_80095870(u8 *param_0, f32 *param_1, f32 *param_2);
void func_80096440(PlayerState *param_0, f32 *param_1);
void func_8009646C(s32 *param_0, s32 param_1);
s32 func_8009650C(PlayerState *param_0);

s32 func_800967C0() 
{
    return 0x28;
}

void func_800967C8(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
    f32 local_0;
    s32 local_14;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5;
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8;
    f32 local_9[3];
    f32 local_10[3];
    f32 local_11[3];
    f32 local_12[3];
    f32 local_13;
    f32 local_1;
    func_800EFB24(local_11, param_1, param_0);
    func_800EFA4C(local_9, 0.0f, 1.0f, 0.0f);
    func_800EFA4C(local_10, local_11[0], 0.0f, local_11[2]);
    func_800EF2A0(local_10);
    func_800EE97C(local_7, local_10, local_9);
    local_0 = func_800EEAA4(param_3, local_7);
    if (local_0 > 0.0f || local_0 == 0.0f) return;
    local_1 = func_800EEAA4(local_7, param_0);
    local_13 = func_800EEAA4(local_7, param_2);
    local_2 = (local_1 - local_13) / local_0;
    if (local_13 < local_1) return;
    for (local_14 = 0; local_14 != 3; local_14++) {
        local_4[local_14] = param_2[local_14] + param_3[local_14] * local_2;
    }
    func_800EFA4C(local_6, local_11[0], 0.0f, local_11[2]);
    func_800EF2A0(local_6);
    func_800EFA4C(local_12, local_4[0] - param_0[0], 0.0f, local_4[2] - param_0[2]);
    local_3 = func_800EEAA4(local_12, local_6);
    if (local_3 < 0.0f) return;
    if (local_3 > func_800EEF94(local_11)) return;
    if (func_800BEE40(param_0, param_1, local_7, 0.028f)) {
        local_5 = func_800EEAD4(param_2, local_4);
        if ((*((Hits967C8 *) &D_80126E30)).local_1[0].local_0 < local_5) return;
        if (local_5 < (*((Hits967C8 *) &D_80126E30)).local_1[0].local_0) (*((Hits967C8 *) &D_80126E30)).local_0 = 0;
        (*((Hits967C8 *) &D_80126E30)).local_1[(*((Hits967C8 *) &D_80126E30)).local_0].local_0 = local_5;
        func_800EE7F8((*((Hits967C8 *) &D_80126E30)).local_1[(*((Hits967C8 *) &D_80126E30)).local_0].local_1, param_0);
        func_800EE7F8((*((Hits967C8 *) &D_80126E30)).local_1[(*((Hits967C8 *) &D_80126E30)).local_0].local_2, param_1);
        func_800EE7F8((*((Hits967C8 *) &D_80126E30)).local_1[(*((Hits967C8 *) &D_80126E30)).local_0].local_3, local_7);
        func_800EE7F8((*((Hits967C8 *) &D_80126E30)).local_1[(*((Hits967C8 *) &D_80126E30)).local_0].local_4, local_4);
        (*((Hits967C8 *) &D_80126E30)).local_0++;
    }
}

s32 func_80096ACC(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
    Triangle96ACC *local_13;
    s32 local_14;
    Triangle96ACC *local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3][3];
    s32 local_7;
    s32 local_8;
    f32 local_9;
    func_800EFB24(local_5, param_1, param_0);
    for (local_2 = 0; local_2 < 3; local_2++) {
        local_3[local_2] = param_0[local_2] < param_1[local_2] ? param_0[local_2] : param_1[local_2];
    }
    for (local_2 = 0; local_2 != 3; local_2++) {
        local_4[local_2] = param_0[local_2] > param_1[local_2] ? param_0[local_2] : param_1[local_2];
    }
    local_4[1] += 100.0f;
    param_1 = (f32 *)D_80126D20;
    local_1 = (Triangle96ACC *)param_1;
    if (!func_800BED70(local_3, local_4, &local_1, 15, 0.98f)) return 0;
    D_80126E30.local_0 = 0;
    D_80126E30.local_1[0].local_0 = 1e+05f;
    for (local_13 = (Triangle96ACC *)param_1; local_13 < local_1; local_13++) {
        for (local_14 = 0; local_14 < 3; local_14++) {
            func_800EE88C(local_6[local_14], (*local_13)[local_14]);
        }
        func_800967C8(local_6[0], local_6[1], param_0, local_5);
        func_800967C8(local_6[1], local_6[2], param_0, local_5);
        func_800967C8(local_6[2], local_6[0], param_0, local_5);
    }
    if (D_80126E30.local_1[0].local_0 == 1e+05f) return 0;
    func_800EE7F8(param_2, D_80126E30.local_1[0].local_4);
    func_800EE7F8(param_3, D_80126E30.local_1[0].local_3);
    local_9 = mlAbsF(D_80126E30.local_1[0].local_1[0] - D_80126E30.local_1[0].local_2[0]);
    if (mlAbsF(D_80126E30.local_1[0].local_1[2] - D_80126E30.local_1[0].local_2[2]) < local_9) {
        param_2[1] = func_800F10B4(param_2[0], D_80126E30.local_1[0].local_1[0], D_80126E30.local_1[0].local_2[0], D_80126E30.local_1[0].local_1[1], D_80126E30.local_1[0].local_2[1]);
    } else {
        param_2[1] = func_800F10B4(param_2[2], D_80126E30.local_1[0].local_1[2], D_80126E30.local_1[0].local_2[2], D_80126E30.local_1[0].local_1[1], D_80126E30.local_1[0].local_2[1]);
    }
    return 1;
}

int func_80096DD4(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  f32 local_0[3];
  f32 local_1[3];
  func_800EE7F8(local_0, param_2 | 0);
  func_800EE7F8(local_1, param_3);
  if (!func_80096ACC(local_0, local_1, param_0, param_1))
  {
    return 0;
  }
  return 1;
}

s32 func_80096E30(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5) {
    s32 local_14;
    f32 local_0[3], local_1[3], local_2[3], local_3[3], local_4[3], local_5[3];
    f32 local_6[3], local_7[3], local_8[3], local_9[3], local_10[3], local_11[3];
    f32 local_12[3], local_13[3];
    func_800EFA20(local_12, param_0, param_4);
    func_800EE780(local_13, param_2, local_12);
    func_800EFA20(local_12, param_0, param_3);
    func_800EF934(local_5, local_12, -param_5);
    func_800EF934(local_11, local_12, param_5);
    func_800EFA4C(local_4, local_12[2], local_12[1], -local_12[0]);
    func_800EFA4C(local_10, -local_12[2], local_12[1], local_12[0]);
    func_800EF368(local_4, 30.0f);
    func_800EF368(local_10, 30.0f);
    func_800EE780(local_3, local_13, local_4);
    func_800EE780(local_9, local_13, local_10);
    func_800EE780(local_0, local_3, local_5);
    func_800EE780(local_6, local_9, local_11);
    if (!func_80096DD4(local_2, local_1, local_3, local_0)) return 0;
    if (!func_80096DD4(local_8, local_7, local_9, local_6)) return 1;
    if (func_800EEAA4(local_1, local_7) <= 0.1f) return 4;
    func_800EFE50(param_1, local_2, local_8, 0.5f);
    func_800EE780(param_0, local_1, local_7);
    func_800EF334(param_0, -0.5f);
    func_800EF2A0(param_0);
    return func_800EECE0(local_1, local_7) ? 2 : 3;
}

s32 func_8009700C(s32 param_0, s32 param_1, u8 *param_2, f32 param_3, f32 param_4)
{
  u8 *new_var3;
  f32 *new_var2;
  s32 sp2C;
  u8 *new_var;
  f32 *new_var4;
  s32 sp20;
  new_var2 = (f32 *) (param_2 + 8);
 new_var = param_2 + 4; new_var3 = param_2 + 8; new_var4 = (f32 *) new_var3; func_800EFA4C(&sp20, *((f32 *) param_2), (*((f32 *) (param_2 + 4))) + param_3, *new_var4);
  func_800EFA4C(&sp2C, *((f32 *) param_2), (*((f32 *) new_var)) + param_4, *new_var2);
  if (func_800C6A7C(&sp20, &sp2C, param_1, 0x420025) != 0)
  {
    return 1;
 dummy_label_419417: ;
  }
  return 0;
}

s32 func_800970A4(f32 *param_0, f32 *param_1, f32 param_2) {
    s32 pad;
    f32 sp28[3];
    f32 sp1C[3];
    s32 var_v1;

    func_800EE7B4(sp28, param_0, param_1, param_2);
    if (func_800C6A7C(param_0, sp28, sp1C, 0x420025) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 func_80097104(State97104 *param_0, f32 *param_1, f32 param_2) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_8;
    f32 local_6;
    f32 local_7[3];
    func_800EFA20(local_0, param_0->local_0, param_2);
    func_800EFB24(local_1, param_1, local_0);
    func_800EFA4C(local_3, 0.0f, 1.0f, 0.0f);
    func_800EE97C(local_4, param_0->local_0, local_3);
    func_800EFA20(local_5, local_4, -1.0f);
    func_8009BB24(param_0, local_7);
    local_7[1] = 0.0f;
    func_800EF2A0(local_7);
    local_6 = func_800EEAA4(local_4, local_7);
    func_800EFA4C(local_2, local_1[0], local_1[1] - 50.0f, local_1[2]);
    if (local_6 > 0.0f) {
        local_8 = param_2 + 4.0f;
        if (func_800970A4(local_1, local_4, local_8)) return 0;
        if (func_800970A4(local_2, local_4, local_8)) return 0;
    }
    if (local_6 < 0.0f) {
        local_8 = -(param_2 + 4.0f);
        if (func_800970A4(local_1, local_4, local_8)) return 0;
        if (func_800970A4(local_2, local_4, local_8)) return 0;
    }
    return 1;
}

s32 func_800972BC(void *param_0, f32 *param_1)
{
    f32 local_6;
    f32 local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    func_800EE7F8(local_2, param_1);
    func_80095870(param_0, &local_1, &local_0);
    local_2[1] += local_1 - local_0;
    if (STATE(param_0)->active) local_6 = 15.0f;
    else local_6 = 0.0f;
    switch (func_80096E30(STATE(param_0), local_3, local_2, local_0+30.0f, -local_0*0.5f, local_6)) {
    case 0: STATE(param_0)->state = 2; return 0;
    case 1: STATE(param_0)->state = 3; return 0;
    case 4: STATE(param_0)->state = 3; return 0;
    case 2: STATE(param_0)->active = 1; break;
    case 3: STATE(param_0)->active = 0; break;
    }
    func_800EE7F8(STATE(param_0)->position, local_3);
    if (!func_80097104(param_0, local_3, local_0)) return 0;
    func_800EFA20(local_5, STATE(param_0)->direction, local_0 + -18.0f);
    func_800EFB24(local_2, local_3, local_5);
    local_2[1] = local_3[1] - local_1 + -43.0f;
    if (func_8009700C(param_0, local_4, local_2, local_0*0.75f+local_1, -50.0f)) {
        if (local_4[1] > 0.0f) {
            STATE(param_0)->state = 4;
        } else {
            STATE(param_0)->state = 5;
        }
        return 0;
    }
    func_800EE7F8(STATE(param_0)->offset, local_2);
    STATE(param_0)->state = 1;
    return 1;
}

f32 func_800974FC(PlayerState *param_0)
{
    f32 local_0;
    func_800F1EA4(*(struct ba_unk_9C **)((char *)param_0 + 152), &local_0);
    return local_0;
}

s32 func_80097524(PlayerState *player) {

    return (*(u8 **)((char *)player + 0x98))[0x25];
}

s32 func_80097530(PlayerState *param_0) {
    f32 local_0, local_1;
    f32 local_2[3], local_3[3], local_4[3], local_5[3];
    func_80095870(param_0, &local_1, &local_0);
    func_800EFA20(local_4, ((Actor97530 *)param_0)->local_0->local_0, 25.0f);
    func_800EF04C(local_4, ((Actor97530 *)param_0)->local_0->local_1);
    func_800EFA4C(local_2, local_4[0], local_4[1] + 6.0f, local_4[2]);
    func_800EFA4C(local_3, local_4[0], local_4[1] + local_1 + local_0 + 5.0f, local_4[2]);
    if (func_800C6A7C(local_2, local_3, local_5, 0x420025)) return 0;
    func_800EFA4C(local_2, local_4[0], local_4[1] + local_1, local_4[2]);
    if (func_800C6C94(local_2, local_0 + 5.0f, local_5, 0x420025)) return 0;
    func_800EFA4C(local_2, local_4[0], local_4[1] + local_1 - local_0 * 0.75f, local_4[2]);
    if (func_800C6C94(local_2, local_0 + 5.0f, local_5, 0x420025)) return 0;
    return 1;
}

s32 func_800976DC(u8 *param_0)
{
    local_0 local_1;
    u8 *local_2;

    if (bastatetimer_isActive(param_0, 7) != 0) {
        return 0;
    }
    if (func_8009650C(param_0) == 0) {
        return 0;
    }

    func_80096440(param_0, local_1.local_2);
    if ((0.028f < local_1.local_2[1])
        && (0.98f > local_1.local_2[1])) {
        return 0;
    }

    func_8009C128(param_0, local_1.local_3);
    func_80095870(param_0, &local_1.local_4, &local_1.local_5);
    local_1.local_3[1] += local_1.local_4;
    func_8009646C(param_0, local_1.local_0);
    func_800F0410(local_1.local_1, local_1.local_0, local_1.local_3);
    func_800EFB24(*(u8 **)(param_0 + 0x98),
        local_1.local_1, local_1.local_3);
    *(f32 *)((*(u8 **)(param_0 + 0x98)) + 4) = 0.0f;
    func_800EF2A0(*(u8 **)(param_0 + 0x98));

    if ((*(f32 *)((local_2 = *(u8 **)(param_0 + 0x98)) + 0) == 0.0f)
        && (*(f32 *)(local_2 + 8) == 0.0f)) {
        return 0;
    }

    local_2[0x24] = 1;
    func_8009C128(param_0, local_1.local_3);
    if (func_800972BC(param_0, local_1.local_3) == 0) {
        return 0;
    }
    return func_800972BC(param_0,
        (*(u8 **)(param_0 + 0x98)) + 0x18);
}

void func_80097858(param_0) u8 * param_0; {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x98)))) + (0x24))) = 1;
    bastatetimer_set(param_0, 7, 0x3E4CCCCD);
}

void func_8009788C(param_0) u8 * param_0;
{
  u8 *ptr2;
  u8 *ptr1;
  ;
  *((u8 *) ((*((u8 **) (param_0 + 0x98))) + 0x24)) = 1 ^ 0;
 do { ; } while (0);
  *((u8 *) ((*((u8 **) (param_0 + 0x98))) + 0x26)) = 1;
}

void func_800978A4(param_0) u8 * param_0;
{
  s32 local_0[3];
  s32 local_1[3];
  s32 local_2[3];
  u8 *local_3;
  func_8009C15C(param_0, &local_0);
  if (1)
  {
    local_3 = *((u8 **) (param_0 + 0x98));
  }
  if ((*((u8 *) (local_3 + 0x26))) != 0)
  {
    *((u8 *) (local_3 + 0x26)) = 0;
    func_800EE7F8(&local_1, (*((u8 **) (param_0 + 0x98))) + 0x18);
  }
  else
  {
    func_8009C128(param_0, &local_1);
  }
  func_800EE7F8(&local_2, *((u8 **) (param_0 + 0x98)));
  if (func_800972BC(param_0, &local_1) != 0)
  {
    func_800EE7F8(&local_1, (*((u8 **) (param_0 + 0x98))) + 0x18);
    baphysics_set_vertical_velocity(param_0, 1.0f);
  }
  else
  {
    func_800EE7F8(&local_1, &local_0);
    func_800EE7F8(*((u8 **) (param_0 + 0x98)), &local_2);
  }
  func_8009C0F8(param_0, &local_1);
}
