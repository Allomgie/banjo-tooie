/*
 * 1E6F080 -- split into two translation units (1E6F080 and 1E700B0).
 *
 * The yaml treated 0x1E6F080..0x1E71260 as one file, but the ROM's .rodata
 * shows two objects: the jump table of func_80095C94 ends at 0x1EFE6D8 and
 * is padded to 0x1EFE6E0, where the constants of the following functions
 * start. IDO aligns every object's .rodata to 16 bytes and never pads inside
 * an object, so this gap is an object boundary. The text shows none because
 * this object happens to end on a 16-byte boundary.
 *
 * The second object starts at func_800967C0 (ROM 0x1E700B0): func_80096768
 * is only called from func_80095C94, the self->unk94 wrappers run up to
 * func_8009679C, and func_800967C0 is the only 16-byte aligned function
 * start before func_800967C8.
 */

#include "core2/1E6F080.h"
#include "types.h"
#include "macros.h"

#define LOCAL_COLLISION(p) (*(LocalCollision **)((u8 *)(p) + 0x94))
#define STATE(p) (*(LocalState **)((u8 *)(p)+0x98))
extern f32 func_800985B8(void);
extern f32 func_8009864C();
extern void func_80098590();
extern void func_800F1E6C(void *, f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 yaw_get();
extern void yaw_setIdeal(void *, f32);
extern void yaw_applyIdeal();
void func_800C68A0(s32 param_0, f32 param_1);
struct UnkStruct { char pad0[0x50]; s32 unk50; };
extern s32 func_800C5BA4(s32);
extern f32 func_800F13F0(f32, f32);
typedef struct { void *floor; f32 value04, value08; u8 pad0C[12]; u8 previous18; u8 pad19[3]; void *triangle1C; u8 pad20[0x30]; Actor *actor50; u8 hit54, hit55, stable56, pad57; f32 delta58[3]; f32 target64, target68; u8 triangle6C[12]; f32 position78[3]; f32 previous84[3]; f32 delta90[3]; s32 mode9C; u8 belowA0, clampedA1, restoreA2, countA3, activeA4; } LocalCollision;
extern s32 func_80091E80(PlayerState *, s32);
extern s32 func_8008E454(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_8009C15C(PlayerState *, f32 *);
extern void func_8009C0F8(PlayerState *, f32 *);
extern s32 func_800BEAAC(f32 *, f32 *);
extern void func_800C68E8(void *, s32, f32);
extern void func_800CB840(s32, s32);
extern void func_800CB870(void);
extern s32 func_800C670C(void *);
extern f32 func_800A0E58(PlayerState *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800D4584(LocalCollision *, f32 *, f32 *, f32 *);
extern void _bahitspline_entrypoint_2(PlayerState *);
extern s32 func_800F1418(s32, s32);
extern void func_800FB508(void *, void *);
extern void func_8010114C(Actor *, s32, s32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void baflag_clear(PlayerState *, s32);
extern s32 player_isStable(PlayerState *);
extern void _bahitspline_entrypoint_0(void);
extern void _bahitspline_entrypoint_1(PlayerState *, s32);
f32 func_8009C150(void);
f32 func_800C6784(s32);
f32 func_800C67D8(s32);
f32 func_800F0E00(f32, f32);
extern void func_800C675C(s32, f32 *);
extern void func_80013A7C(f32);
extern u8 unk94[];
struct unk_struct_94 { u8 pad[0x50]; s32 *unk50; u8 pad2[0x40]; struct unk_struct_94 *unk94; };
typedef struct { f32 local_0; f32 local_1[3], local_2[3], local_3[3], local_4[3]; } Hit967C8;
typedef struct { s32 local_0; Hit967C8 local_1[1]; } Hits967C8;
extern void func_800EE7F8(f32 *, f32 *);
typedef s16 Triangle96ACC[3][3];
typedef struct { s32 local_0; Hit967C8 local_1[1]; } Result96ACC;
typedef struct { u8 pad[0x98]; f32 *local_0; } State97104;
typedef struct { f32 direction[3], position[3], offset[3]; u8 active, state; } LocalState;
typedef struct { f32 local_0[3], local_1[3]; } Motion97530;
typedef struct { u8 pad[0x98]; Motion97530 *local_0; } Actor97530;
extern void *func_800C6C94(f32 *, f32, f32 *, u32);
typedef struct { f32 local_0[3]; u8 pad_0[0x18]; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; f32 local_4; f32 local_5; } local_0;
void func_80095A08();
void func_800961AC();
int func_80096254();
void func_80096260();
s32 func_80096530();
s32 func_80096628();
int func_80096768();
void func_80097858();
void func_8009788C();
void func_800978A4();

s32 func_80095790() 
{
    return 0xAC;
}

void func_80095798(u8 *param_0) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_1 = func_800985B8();
    local_2 = func_8009864C(param_0);
    if (local_2 < *(f32 *)(*(u8 **)(param_0 + 0x94) + 0x7C)) {
        *(f32 *)(*(u8 **)(param_0 + 0x94) + 0x7C) = local_2;
    }
    if (*(f32 *)(*(u8 **)(param_0 + 0x94) + 0x7C) < local_1) {
        *(f32 *)(*(u8 **)(param_0 + 0x94) + 0x7C) = local_1;
    }
    func_80098590(param_0, local_0);
    func_800F1E6C(*(u8 **)(param_0 + 0x94) + 0x78, local_0, &local_3);
    if (mlAbsF(func_800F1DCC(local_3, yaw_get(param_0))) > 1.0f) {
        yaw_setIdeal(param_0, local_3);
        yaw_applyIdeal(param_0);
    }
}

void func_80095870(u8 *param_0, f32 *param_1, f32 *param_2) {

    *param_1 = (*(f32 **)(param_0 + 0x94))[1];
    *param_2 = (*(f32 **)(param_0 + 0x94))[2];
}

s32 func_8009588C(u8 *param_0) {
    return (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x94)))) + (0x14)));
}

s32 func_80095898(void *arg)
{
    return ((u8 *)(*(void **)((char *)arg + 0x94)))[162];
}

int func_800958A4(Actor *param_0, f32 param_1, f32 param_2) {
    f32 local_0[4];
    f32 local_1[3];
    s32 local_2;
    func_8009C128(param_0, local_0);
    local_0[1] += param_1;
    if (func_800C6C94(local_0, param_2, local_1, (*(s32 **)((u8 *)param_0 + 0x94))[5]) != 0) {
        local_2 = 1;
    } else {
        local_2 = 0;
    }
    return local_2;
}

void func_8009590C(s32 *param_0, f32 param_1) {
    if (param_1 == 0.0f) {
        func_800C68A0(*(s32 *)param_0[0x25], 56.0f);
    } else {
        func_800C68A0(*(s32 *)param_0[0x25], param_1);
    }
}

s32 func_80095964(Actor *this, s32 param_1){
    
    if(param_1){
        func_80095A08(this, 8, 1);
        func_80095A08(this, 4, 0);
    }
    else{
        func_80095A08(this, 8, 0);
        func_80095A08(this, 4, 1);
    }
}

void func_800959C8(PlayerState *param_0, f32 param_1, f32 param_2)
{
  f32 *new_var;
  *((f32 *) (((u8 *) ((u8 **) param_0)[37]) + 0x64)) = param_1;
  new_var = (f32 *) (((u8 **) param_0)[37]);
  (*(f32 *)((char *)(new_var) + 4)) = *(f32 *) (((u8 *) new_var) + 0x64);
  new_var++;
  new_var--;
  *((f32 *) (((u8 *) ((u8 **) param_0)[37]) + 0x68)) = param_2;
  new_var = (f32 *) (((u8 **) param_0)[37]);
  (*(f32 *)((char *)(new_var) + 8)) = *(f32 *) (((u8 *) new_var) + 0x68);
}

func_800959FC(s32 param_0, s32 param_1){
    *(s32*)(*(s32*)(param_0 + 0x94) + 0x14) = param_1;
}

void func_80095A08(param_0, param_1, param_2) PlayerState * param_0; s32 param_1; s32 param_2; {
    if (param_2 != 0) {
        *(s32 *)((*(u8 **)((u8 *)param_0 + 0x94)) + 0x14) |= param_1;
    } else {
        *(s32 *)((*(u8 **)((u8 *)param_0 + 0x94)) + 0x14) &= ~param_1;
    }
}

void func_80095A40(PlayerState *param_0)
{
  float new_var;
  PlayerState *new_var2;
  new_var2 = param_0;
  func_800959C8(new_var2, new_var = (unsigned long) 80.0f, 35.0f);
}

func_80095A64(void *param_0){
    ((struct UnkStruct *)param_0)->unk50 = 0;
}

int func_80095A6C(s32 param_0, s32 *param_1)
{
  param_1[20] = param_0;
 ;
}

void func_80095A74(s32 param_0, s32 param_1)
{
  if (func_800EA05C() == 0xB8)
  {
    if (param_1 != 0)
    {
      func_80095A08(param_0, 8, 1);
    }
    else
    {
      func_80095A08(param_0, 8, 0);
    }
  }
}

void func_80095AD0(u8 *param_0)
{
    u8 local_0;

    *(u8*)(*(u8**)(param_0 + 0x94) + 0xa3) = 0;
    local_0 = *(u8*)(*(u8**)(param_0 + 0x94) + 0xa3);
    *(u8*)(*(u8**)(param_0 + 0x94) + 0x54) = local_0;
    *(u8*)(*(u8**)(param_0 + 0x94) + 0xa1) = local_0;
    *(u8*)(*(u8**)(param_0 + 0x94) + 0x18) = local_0;
    *(u8*)(*(u8**)(param_0 + 0x94) + 0x56) = local_0;
    *(u8*)(*(u8**)(param_0 + 0x94) + 0xa0) = local_0;
    func_800959FC(param_0, 0x400005);
    *(s32*)(*(u8**)(param_0 + 0x94)) = func_800C5A38();
    func_800EFD24(*(u8**)(param_0 + 0x94) + 0x90);
    func_800EFD24(*(u8**)(param_0 + 0x94) + 0x78);
    func_800EFD24(*(u8**)(param_0 + 0x94) + 0x84);
    func_800EFD24(*(u8**)(param_0 + 0x94) + 0x44);
    *(s32*)(*(u8**)(param_0 + 0x94) + 0x1c) = 0;
    *(u8*)(*(u8**)(param_0 + 0x94) + 0xa2) = 0;
    func_80095A40(param_0);
    *(f32*)(*(u8**)(param_0 + 0x94) + 4) = *(f32*)(*(u8**)(param_0 + 0x94) + 0x64);
    *(f32*)(*(u8**)(param_0 + 0x94) + 8) = *(f32*)(*(u8**)(param_0 + 0x94) + 0x68);
    func_80096254(param_0, 1);
    func_8009590C(param_0, 0);
    *(s32*)(*(u8**)(param_0 + 0x94) + 0x9c) = 0;
    func_800961AC(param_0, 1);
    baflag_clear(param_0, 1);
    baflag_clear(param_0, 2);
    *(void (**)(s32, void *))(*(u8**)(param_0 + 0x94) + 0xc) = func_80095A6C;
    *(void (**)(void *))(*(u8**)(param_0 + 0x94) + 0x10) = func_80095A64;
    *(u8*)(*(u8**)(param_0 + 0x94) + 0xa4) = 0;
}

s32 func_80095C10(s32 param_0) {
    return func_800C5BA4(*(s32 *)(*(s32 *)(param_0 + 0x94)));
}

f32 func_80095C34(f32 param_0, f32 param_1, f32 param_2) {
    if (param_1 < param_0) param_1 = func_800F13F0(param_0, param_1 + param_2);
    else if (param_0 < param_1) param_1 = func_800F0E00(param_0, param_1 - param_2);
    return param_1;
}

void func_80095C94(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_7;

    LOCAL_COLLISION(param_0)->activeA4 = 1;
    LOCAL_COLLISION(param_0)->actor50 = NULL;
    if (!func_80091E80(param_0, 4)) return;
    if (!func_8008E454(param_0)) return;

    func_8009C128(param_0, local_0);
    if (func_800BEAAC(local_0, &local_3)) {
        func_800C68E8(LOCAL_COLLISION(param_0)->floor, 1, local_3);
    } else {
        func_800C68E8(LOCAL_COLLISION(param_0)->floor, 0, local_3);
    }
    LOCAL_COLLISION(param_0)->clampedA1 = 0;
    LOCAL_COLLISION(param_0)->hit54 = 0;
    LOCAL_COLLISION(param_0)->hit55 = 0;
    LOCAL_COLLISION(param_0)->triangle1C = NULL;
    LOCAL_COLLISION(param_0)->previous18 = LOCAL_COLLISION(param_0)->stable56;
    func_800CB840(1, param_0->unk184);
    LOCAL_COLLISION(param_0)->value04 = func_80095C34(LOCAL_COLLISION(param_0)->target64, LOCAL_COLLISION(param_0)->value04, 1.0f);
    LOCAL_COLLISION(param_0)->value08 = func_80095C34(LOCAL_COLLISION(param_0)->target68, LOCAL_COLLISION(param_0)->value08, 1.0f);

    switch (LOCAL_COLLISION(param_0)->mode9C) {
    case 1:
    case 3:
    case 4:
    case 9:
        func_8009C128(param_0, LOCAL_COLLISION(param_0)->position78);
        func_8009C15C(param_0, LOCAL_COLLISION(param_0)->previous84);
        if (LOCAL_COLLISION(param_0)->mode9C == 3) {
            void *local_4 = LOCAL_COLLISION(param_0)->floor;
            if (func_800C670C(local_4)) {
                f32 local_5 = func_800C67D8(local_4);
                f32 local_6 = func_800A0E58(param_0);
                if (local_5 - local_6 < LOCAL_COLLISION(param_0)->position78[1]) {
                    LOCAL_COLLISION(param_0)->position78[1] = local_5 - local_6;
                    LOCAL_COLLISION(param_0)->clampedA1 = 1;
                    baphysics_set_vertical_velocity(param_0, 1.0f);
                }
            }
        }
        func_800EFB24(LOCAL_COLLISION(param_0)->delta58, LOCAL_COLLISION(param_0)->position78, LOCAL_COLLISION(param_0)->previous84);
        func_800D4584(LOCAL_COLLISION(param_0), LOCAL_COLLISION(param_0)->previous84, LOCAL_COLLISION(param_0)->position78, LOCAL_COLLISION(param_0)->delta58);
        func_8009C0F8(param_0, LOCAL_COLLISION(param_0)->position78);
        break;
    case 5:
        func_8009C128(param_0, LOCAL_COLLISION(param_0)->position78);
        func_8009C15C(param_0, LOCAL_COLLISION(param_0)->previous84);
        func_800EFB24(LOCAL_COLLISION(param_0)->delta58, LOCAL_COLLISION(param_0)->position78, LOCAL_COLLISION(param_0)->previous84);
        func_800D4584(LOCAL_COLLISION(param_0), LOCAL_COLLISION(param_0)->previous84, LOCAL_COLLISION(param_0)->position78, LOCAL_COLLISION(param_0)->delta58);
        func_80095798(param_0);
        func_8009C0F8(param_0, LOCAL_COLLISION(param_0)->position78);
        break;
    case 7:
        func_800978A4(param_0);
        break;
    case 8:
        func_80096768(param_0);
        break;
    case 10:
        _bahitspline_entrypoint_2(param_0);
    case 2:
    case 6:
        LOCAL_COLLISION(param_0)->hit54 = 0;
        LOCAL_COLLISION(param_0)->hit55 = 0;
        LOCAL_COLLISION(param_0)->stable56 = 0;
        break;
    }
    if (func_800C670C(LOCAL_COLLISION(param_0)->floor)) {
        local_7 = func_800C67D8(LOCAL_COLLISION(param_0)->floor);
        LOCAL_COLLISION(param_0)->belowA0 = LOCAL_COLLISION(param_0)->position78[1] < local_7;
    }
    if (func_80096530(param_0)) LOCAL_COLLISION(param_0)->stable56 = 1;
    if (LOCAL_COLLISION(param_0)->belowA0 && LOCAL_COLLISION(param_0)->position78[1] < func_800C67D8(LOCAL_COLLISION(param_0)->floor) - func_800A0E58(param_0)) {
        func_80096254(param_0, 3);
        if (LOCAL_COLLISION(param_0)->stable56 && baphysics_get_vertical_velocity(param_0) < 0.0f) {
            baphysics_set_vertical_velocity(param_0, -1.0f);
        }
    } else if (LOCAL_COLLISION(param_0)->stable56) {
        func_80096260(param_0);
        if (baphysics_get_vertical_velocity(param_0) < 0.0f) {
            if (!(func_80096628(param_0) & 0x8000)) baphysics_set_vertical_velocity(param_0, -1.0f);
        }
    } else {
        func_80096254(param_0, 1);
    }
    if (LOCAL_COLLISION(param_0)->restoreA2) func_8009C0F8(param_0, local_0);
    func_800CB870();
    if (LOCAL_COLLISION(param_0)->hit54) {
        LOCAL_COLLISION(param_0)->countA3 = func_800F1418(LOCAL_COLLISION(param_0)->countA3 + 1, 3);
    } else {
        LOCAL_COLLISION(param_0)->countA3 = 0;
    }
    func_8009C15C(param_0, local_2);
    func_8009C128(param_0, local_1);
    func_800EFB24(LOCAL_COLLISION(param_0)->delta90, local_1, local_2);
    if (LOCAL_COLLISION(param_0)->triangle1C) {
        func_800FB508(LOCAL_COLLISION(param_0)->triangle6C, LOCAL_COLLISION(param_0)->triangle1C);
        LOCAL_COLLISION(param_0)->triangle1C = LOCAL_COLLISION(param_0)->triangle6C;
    }
    baflag_clear(param_0, 1);
    baflag_clear(param_0, 2);
    if (LOCAL_COLLISION(param_0)->actor50 && player_isStable(param_0)) {
        func_8010114C(LOCAL_COLLISION(param_0)->actor50, 0x91, param_0->unk184);
    }
}

void func_800961A0(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x94)))[162] = v;
}

void func_800961AC(param_0, param_1) PlayerState * param_0; s32 param_1;
{
  s32 temp_v1;
  u8 *var_v0;
  var_v0 = *((u8 **) (((char *) param_0) + 0x94));
  temp_v1 = *((s32 *) (((char *) var_v0) + 0x9C));
  switch (temp_v1)
  {
    case 7:
      func_80097858();
      break;

    case 10:
      _bahitspline_entrypoint_0();
      goto block_5;

  }

  block_5:
  var_v0 = *((u8 **) (((char *) param_0) + 0x94));

  *((s32 *) (((char *) var_v0) + 0x9C)) = param_1;
  switch (param_1)
  {
    case 7:
      func_8009788C(param_0, param_1);
      return;

    case 10:
      _bahitspline_entrypoint_1(param_0, param_1);
      return;

  }

}

func_80096254(param_0, param_1) s32 param_0; s32 param_1;{
    *(s32*)(*(s32*)(param_0 + 0x94) + 0xA8) = param_1;
}

void func_80096260(param_0) PlayerState * param_0;
{
  s32 ret;
  ret = func_80096628(param_0);
  if (func_800C84B0(ret) == 0x18)
  {
    func_80096254(param_0, 4);
    return;
  }
  func_80096254(param_0, 2);
}

void func_800962B0(PlayerState *param_0, s32 param_1) {
    func_800C68D4(*(*(PlayerState***)((u8*)param_0 + 0x94)), param_1);
}

f32 func_800962D4(void *param_0)
{
    f32 sp1C;
    sp1C = func_8009C150();
    return sp1C - func_800C6784(*(*(s32 **)((s8 *)param_0 + 0x94)));
}

f32 func_8009630C(PlayerState *param_0)
{
  f32 sp1C;
  f32 sp20;
  f32 new_var;
  s8 _sfpad[8];
  new_var = func_8009C150();
  if (new_var)
  {
  }
  sp1C = new_var;
  sp20 = func_800C6784(*(*((s32 **) (((char *) param_0) + 0x94))));
  return sp1C - func_800F0E00(sp20, func_800C67D8(*(*((s32 **) (((char *) param_0) + 0x94)))));
}

f32 func_80096364(PlayerState *param_0) {
    return func_800C6784(*(s32 *)(*(s32 **)((u8 *)param_0 + 0x94)));
}

s32 func_80096388(PlayerState *param_0){

    return *(s32 *)((char *)(*(struct ba_unk_9C **)((char *)param_0 + 0x94)) + 156);
}

void func_80096394(u8 *param_0, s32 param_1) {
    func_800EE7F8(param_1, *(u32 *)(param_0 + 0x94) + 0x90);
}

void func_800963C0(PlayerState *param_0, f32 param_1[3]) {
    func_800C675C(*(s32 *)(*(s32 **)((u8 *)param_0 + 0x94)), param_1);
}

int func_800963E4(f32 param_0[3]) {
    f32 local_0[3];
    func_800963C0(param_0, local_0);
    func_80013A7C(local_0[1]);
}

s32 func_8009640C(u8 *param_0)
{
  s32 temp_t6;
  s32 var_v0;
  u8 *temp_v1;
  u8 *new_var;
  temp_v1 = *((u8 **) (param_0 + 0x94));
  temp_t6 = (*(new_var = temp_v1 + 0x18)) == 0;
  var_v0 = temp_t6;
  if (temp_t6 != (temp_t6 * 0))
  {
    ;
    return (*((u8 *) (temp_v1 + 0x56))) != 0;
  }
}

s32 func_80096434(PlayerState *param_0) {

    return *(s32 *)((char *)(*(struct ba_flag_s **)((char *)param_0 + 0x94)) + 0x74);
}

void func_80096440(PlayerState *param_0, f32 *param_1)
{
  func_800EE7F8(param_1, *(s32 *)((char *)param_0 + 0x94) + 0x44);
}

void func_8009646C(s32 *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;

    local_0 = 0;
    local_1 = param_1;
    do {
        func_800EE7F8(local_1, param_0[37] + local_0 + 0x20);
        local_0 += 0xC;
        local_1 += 0xC;
    } while (local_0 != 0x24);
}

s32 func_800964D0(void *arg)
{
    return ((s32 *)(*(void **)((char *)arg + 0x94)))[42];
}

f32 func_800964DC(PlayerState *param_0) {
    return func_800C67D8(*(s32 *)(*(s32 **)((u8 *)param_0 + 0x94)));
}

s32 func_80096500(PlayerState *param_0)
{
  s32 local_0;
  ;
  return *(((char *) (*((s32 *) (((char *) param_0) + 0x94)))) + 0xA1);
}

s32 func_8009650C(PlayerState *param_0)
{
  s32 local_0;
  local_0 = *((s32 *) (((char *) param_0) + 0x94));
  return *(((char *) (*((s32 *) (((char *) param_0) + 0x94)))) + 0x55);
}

s32 func_80096518(void *arg)
{
    return ((u8 *)(*(void **)((char *)arg + 0x94)))[86];
}

u8 func_80096524(u8 *arg0) {
    return ((u8 **)arg0)[37][0xA0];
}

s32 func_80096530(param_0) struct SomeStruct * param_0;
{
  u8 *local_0;
  local_0 = (*((s32 *) (((char *) param_0) + 0x94))) & 0xFFFFFFFFFFFFFFFFu;
  return local_0[0xA3] == 3;
}

s32 func_80096544(PlayerState *param_0)
{
    func_800C670C(*(*(s32 **)((s8 *)param_0 + 0x94)));
}

s32 func_80096568(s32 *param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  s32 new_var;
  s32 local_4;
  s32 local_5;
  local_5 = param_1;
  local_2 = param_0[0x25];
  new_var = param_0[0x25];
  local_0 = *((s32 **) (local_2 + 0));
  local_2 = new_var;
  local_1 = func_800C6744(local_0);
  local_3 = local_5;
  local_5 = local_5;
  local_4 = local_1 & 0x1F00;
  return local_4 == local_5;
}

s32 func_8009659C(u8 *param_0, s32 param_1)
{
  s32 *var_t6;
  s32 var_a0;
  s32 *new_var2;
  s32 var_v0;
  s32 new_var;
  new_var2 = *((s32 **) (((u8 *) param_0) + 0x94));
  var_t6 = *((s32 **) (((u8 *) param_0) + 0x94));
  var_t6 = new_var2;
  new_var = *var_t6;
  var_a0 = new_var;
  ;
  return func_800C6744(var_a0) & param_1;
}

s32 func_800965C8(s32 param_0)
{
    return ((u8 **)(param_0 + 0x94))[0][0xA4];
}

struct unk_struct_94 *func_800965D4(struct unk_struct_94 *param_0)
{
    return param_0->unk94->unk50;
}

void func_800965E0(u8 *param_0) {
    func_800C67F8(*(*(s32 **)((s8 *)(param_0) + (0x94))));
}

void func_80096604(u8 *param_0) {
    func_800C6840(*(*(s32 **)((s8 *)(param_0) + (0x94))));
}

s32 func_80096628(param_0) PlayerState * param_0;
{
  s32 local_0;
  s32 local_1;
  local_0 = local_1;
  ;
  local_1 = *((s32 **) local_0);
  func_800C6744(*((void **) (*((s32 *) (((char *) param_0) + 0x94)))));
}

void func_8009664C(void *param_0) {
    func_800C674C(*(*(s32 **)((u8 *)param_0 + 0x94)));
}

void func_80096670(void *param_0)
{
  s32 **new_var;
  s32 *t6;
  if (((param_0 && param_0) && param_0) != 0)
  {
 do { } while (0);
  }
  new_var = &(*((s32 **) (((char *) param_0) + 0x94)));
  ;
  func_800C67C8(*(*new_var));
}

void func_80096694(PlayerState* a0)
{
    func_800C84B0(func_80096628(a0));
}

void func_800966BC(u8 *param_0) {
    func_800C67E0(*(*(s32 **)((s8 *)(param_0) + (0x94))));
}

void func_800966E0(void *param_0)
{
    func_800C67E8(*(*(s32 **)((s8 *)param_0 + 0x94)));
}

void func_80096704(void *param_0)
{
  s32 *t6;
  ;
  func_800C5B84(*(*((s32 **) (((char *) param_0) + 0x94))));
}

void func_80096728(u8 *param_0)
{
  s32 temp_a1;
  temp_a1 = *(*((s32 **) (((u8 *) param_0) + 0x94)));
  if (temp_a1 != 0)
  {
    *(*((s32 **) (((u8 *) param_0) + 0x94))) = func_800C5BC4(temp_a1 ^ 0, temp_a1, param_0);
  }
}

int func_80096768(param_0) Actor * param_0;
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  func_800D4D5C(local_0, *(s32*)((char*)param_0 + 0x94));
}

void func_8009679C(u8 *param_0) {
    func_800C68DC(*(*(s32 **)((s8 *)(param_0) + (0x94))));
}
