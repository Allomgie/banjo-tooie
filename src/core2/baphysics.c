#include "overlays/ba/physics.h"

#define STATE(p) (*(LocalState **)((u8 *)(p)+0xC8))
#define QQ (*(S_9B450 **)((u8 *)param_0 + 0xC8))
typedef struct { s32 pad; f32 local_0[3], local_1[3], local_2[3], local_3[3]; f32 local_4, local_5, local_6, local_7; u8 pad1[0xC]; f32 local_8; } Physics9AE08;
typedef struct { u8 pad[0xC8]; Physics9AE08 *local_0; } Player9AE08;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF410(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800F2168(f32 *, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800A3378(PlayerState *);
extern f32 func_80094E98(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_80096518(PlayerState *);
extern s32 func_8008E1C4(PlayerState *);
extern void func_800963C0(PlayerState *, f32 *);
typedef struct { s32 mode; f32 position[3], velocity[3], target[3], delta[3]; u8 pad34[0x10]; f32 rate; } LocalState_8009B08C;
extern void func_800EFA20(f32 *, f32 *, f32, ...);
struct ActorLocal_CC_1 { f32 field_0x08; f32 field_0x0C; f32 field_0x10; f32 field_0x14; f32 field_0x18; f32 field_0x1C; f32 field_0x20; f32 field_0x24; f32 field_0x28; f32 field_0x2C; f32 field_0x30; f32 field_0x34; f32 field_0x38; f32 field_0x3C; };
struct Actor { char _pad[0xC8]; struct ActorLocal_CC_1 *local_1; char _pad2[0x40]; };
typedef struct { f32 local_0; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; } State9B27C;
typedef struct { u8 pad[0xC8]; State9B27C *local_0; } Actor9B27C;
extern void func_80098590(Actor9B27C *, f32 *);
extern s32 func_8009861C(Actor9B27C *);
extern f32 func_80098610(Actor9B27C *);
extern f32 func_80098628(Actor9B27C *);
extern f32 func_800136E4(f32);
extern void func_800EF334(f32 *,f32);
extern void func_800EE7F8();
extern void func_800EF04C(s32 arg0, s32 arg1);
typedef struct { u8 pad0[8]; f32 unk8; u8 padC[0x3C]; f32 unk48; f32 unk4C; } S_9B450;
extern f32 func_800D8FF8();
extern f32 func_800F0F9C(f32, f32);
extern f32 func_80013970(f32);
extern void func_800EFA4C(s32 param_1, f32 param_2, s32 param_3, f32 param_4);
typedef struct { s32 mode; f32 position[3]; u8 pad10[0x40]; f32 scale; } LocalState_8009B590;
extern f32 func_800A3048(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void func_800EFD24(void *param_0);
extern f32 D_80117EF0;
extern f32 D_80117EF4;
void baphysics_set_target_horizontal_velocity(PlayerState *param_0, f32 param_1);
void baphysics_set_target_yaw(PlayerState *param_0, f32 param_1);
void baphysics_set_gravity(PlayerState *param_0, f32 param_1);
void baphysics_set_terminal_velocity(PlayerState *param_0, f32 param_1);

s32 func_8009AD70() 
{
    return 0xF;
}

u8 func_8009AD78(u8 *param_0, s32 param_1)
{
  return *(u8 *)(*(s32 *)((char *)param_0 + 0xC4) + param_1);
}

void func_8009AD88(s32 arg0) 
{
}
void func_8009AD90(u8 *param_0) {
    s32 local_0;

    local_0 = 3;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC4)))) + (0))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC4)))) + (1))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC4)))) + (2))) = 0;
    do {
        *((*(u8 **)((s8 *)(param_0) + (0xC4))) + local_0) = 0;
        (*(s8 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0xC4))) + local_0)) + (1))) = 0;
        (*(s8 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0xC4))) + local_0)) + (2))) = 0;
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC4))) + local_0) + (3))) = 0;
        local_0 += 4;
    } while (local_0 != 0xF);
}

void func_8009ADF0(u8 *param_0, s32 param_1, unsigned int param_2)
{
  u8 *ptr;
  ;
  *((*((u8 **) (param_0 + 0xC4))) + param_1) = param_2;
}

s32 func_8009AE00() 
{
    return 0xC4;
}

void func_8009AE08(PlayerState *param_0) {
    f32 local_0[3], local_1[3], local_2[3], local_3[3], local_4[3], local_5[3];
    f32 local_6, local_7;
    f32 local_8;
    func_800EEB9C(((Player9AE08 *)param_0)->local_0->local_2, ((Player9AE08 *)param_0)->local_0->local_7, ((Player9AE08 *)param_0)->local_0->local_6 * ((Player9AE08 *)param_0)->local_0->local_8);
    local_2[0] = ((Player9AE08 *)param_0)->local_0->local_1[0];
    local_2[1] = 0.0f;
    local_2[2] = ((Player9AE08 *)param_0)->local_0->local_1[2];
    func_800EE7F8(local_3, ((Player9AE08 *)param_0)->local_0->local_2);
    local_3[1] = 0.0f;
    if (func_80096518(param_0)) {
        func_800963C0(param_0, local_4);
        func_800EF410(local_5, local_3);
        local_6 = func_800EEAA4(local_5, local_4);
        local_7 = func_800A3378(param_0);
        if (local_6 != 0.0f) {
            if (local_6 < 0.0f) {
                if (func_8008E1C4(param_0)) local_7 = func_800F10B4(local_7, 0.0f, 1.0f, local_6 * 0.5f, -1.0f);
                else local_7 = local_6 * 0.5f;
                func_800EF334(local_3, 1.0f + local_7);
            } else {
                func_800EF334(local_3, (local_8 = 1.0f) + local_6 * 0.2f);
            }
        }
    }
    func_800EFA20(local_0, local_3, func_80094E98(param_0));
    func_800EFA20(local_1, local_2, func_80094E98(param_0));
    func_800EF3DC(local_0, local_1);
    func_800EF334(local_0, func_800D8FF8() * 30.0f);
    func_800EF04C(((Player9AE08 *)param_0)->local_0->local_1, local_0);
    ((Player9AE08 *)param_0)->local_0->local_1[1] += ((Player9AE08 *)param_0)->local_0->local_4 * func_800D8FF8();
    if (((Player9AE08 *)param_0)->local_0->local_1[1] < ((Player9AE08 *)param_0)->local_0->local_5) ((Player9AE08 *)param_0)->local_0->local_1[1] = ((Player9AE08 *)param_0)->local_0->local_5;
    func_800EFA20(((Player9AE08 *)param_0)->local_0->local_3, ((Player9AE08 *)param_0)->local_0->local_1, func_800D8FF8());
    func_800EF04C(((Player9AE08 *)param_0)->local_0->local_0, ((Player9AE08 *)param_0)->local_0->local_3);
    func_800F2168(((Player9AE08 *)param_0)->local_0->local_1, 0.0001f);
}

void func_8009B08C(void *param_0)
{
    f32 local_0[3];
    f32 local_1;
    local_1 = func_800D8FF8();
    func_800EFB24(local_0, (*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->target, (*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->velocity);
    func_800EF334(local_0, (*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->rate * local_1);
    if ((local_0[0]*local_0[0] + local_0[1]*local_0[1]) + local_0[2]*local_0[2] < 0.02f) {
        func_800EE7F8((*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->velocity, (*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->target);
    } else {
        func_800EF04C((*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->velocity, local_0);
    }
    func_800EFA20((*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->delta, (*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->velocity, local_1);
    func_800EF04C((*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->position, (*(LocalState_8009B08C **)((u8 *)(param_0)+0xC8))->delta);
}

void func_8009B170(u8 *param_0)
{
    f32 temp_f0;
    
    temp_f0 = func_800D8FF8();
    *(f32 *)(*(u8 **)(param_0 + 0xC8) + 0x14) += *(f32 *)(*(u8 **)(param_0 + 0xC8) + 0x34) * temp_f0;
    if (*(f32 *)(*(u8 **)(param_0 + 0xC8) + 0x14) < *(f32 *)(*(u8 **)(param_0 + 0xC8) + 0x38))
    {
        *(f32 *)(*(u8 **)(param_0 + 0xC8) + 0x14) = *(f32 *)(*(u8 **)(param_0 + 0xC8) + 0x38);
    }
    func_800EFA20((f32 *) (*(u8 **)(param_0 + 0xC8) + 0x28), (f32 *) (*(u8 **)(param_0 + 0xC8) + 0x10), temp_f0, param_0);
    func_800EF04C(*(u8 **)(param_0 + 0xC8) + 4, *(u8 **)(param_0 + 0xC8) + 0x28);
}

void func_8009B1FC(struct Actor *param_0)
{
  f32 local_0 = func_800D8FF8();
  struct ActorLocal_CC_1 *local_3;
  f32 local_2;
  f32 local_1;
  local_3 = *((struct ActorLocal_CC_1 **) (((char *) param_0) + 0xC8));
  *((f32 *) (((char *) local_3) + 0x14)) += (*((f32 *) (((char *) local_3) + 0x34))) * local_0;
  local_3 = *((struct ActorLocal_CC_1 **) (((char *) param_0) + 0xC8));
  local_2 = *((f32 *) (((char *) local_3) + 0x14));
  local_1 = *((f32 *) (((char *) local_3) + 0x38));
  if (local_2 < local_1)
  {
    *((f32 *) (((char *) local_3) + 0x14)) = local_1;
    local_3 = *((struct ActorLocal_CC_1 **) (((char *) param_0) + 0xC8));
    local_2 = *((f32 *) (((char *) local_3) + 0x14));
  }
  local_3 = *((struct ActorLocal_CC_1 **) (((char *) param_0) + 0xC8));
  *((f32 *) (((char *) local_3) + 0x2C)) = local_2 * local_0;
  local_3 = *((struct ActorLocal_CC_1 **) (((char *) param_0) + 0xC8));
  *((f32 *) (((char *) local_3) + 0x8)) += *((f32 *) (((char *) local_3) + 0x2C));
}

void func_8009B27C(Actor9B27C *param_0) {
    f32 local_0[3];
    f32 local_1[3];
    func_80098590(param_0, local_1);
    param_0->local_0->local_1[0] = local_1[0];
    param_0->local_0->local_1[2] = local_1[2];
    if (func_8009861C(param_0) == 2) {
        func_800EEB9C(local_0, func_800136E4(func_80098610(param_0) + 180.0f), -func_80098628(param_0));
    } else {
        func_800EEB9C(local_0, yaw_get(param_0), -func_80098628(param_0));
    }
    param_0->local_0->local_1[0] += local_0[0];
    param_0->local_0->local_1[1] += local_0[1];
    param_0->local_0->local_1[2] += local_0[2];
    param_0->local_0->local_3[0] = param_0->local_0->local_3[2] =
        param_0->local_0->local_2[0] = param_0->local_0->local_2[2] = 0.0f;
    func_8009B08C(param_0);
}

void func_8009B3B8(s32 *param_0)
{
  if (1) { }
  func_800EE7F8(param_0[50] + 0x28, param_0[50] + 0x10);
  func_800EF334(param_0[50] + 0x28, func_800D8FF8());
  func_800EF04C(param_0[50] + 4, param_0[50] + 0x28);
}

void func_8009B414(u8 *param_0) {
  s8 _sfpad[8];
    s32 local_0;
    s32 local_1;

    func_8009C128(param_0, &local_0);
    local_1 = (*(s32 *)((s8 *)(param_0) + (0xC8)));
    func_800EFB24(local_1 + 0x28, local_1 + 4, &local_0);
}

void func_8009B450(void *param_0) {
    QQ->unk4C += func_800D8FF8(param_0);
    QQ->unk8 = QQ->unk48 + func_80013970(func_800F0F9C(QQ->unk4C, 1.2f) * 360.0f) * 5.0f;
}

void func_8009B4D0(u8 *param_0, s32 param_1) {
    func_800EE7F8(param_1, (*(s32 *)((s8 *)(param_0) + (0xC8))) + 0x28);
}

void func_8009B4FC(u8 *param_0) {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x50))) = 1.0f;
    func_800EFA4C((*(u8 **)((s8 *)(param_0) + (0xC8))) + 0x10, 0.0f, 0xBF800000, 0.0f);
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xC8))) + 0x1C);
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xC8))) + 0x28);
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xC8))) + 4);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x44))) = 2.0f;
    func_8009BC34(param_0);
}

s32 func_8009B590(PlayerState *param_0)
{
    func_8009C128(param_0, (*(LocalState_8009B590 **)((u8 *)(param_0)+0xC8))->position);
    (*(LocalState_8009B590 **)((u8 *)(param_0)+0xC8))->scale *= func_800A3048(param_0);
    switch ((*(LocalState_8009B590 **)((u8 *)(param_0)+0xC8))->mode) {
    case 0: break;
    case 12: _bamovegoto_entrypoint_14(param_0); break;
    case 11: func_8009B450(param_0); break;
    case 8: func_8009B3B8(param_0); break;
    case 1: func_8009B170(param_0); break;
    case 9: func_8009B08C(param_0); break;
    case 2:
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        func_8009AE08(param_0);
        break;
    case 5:
        baphysics_set_target_yaw(param_0, func_800136E4(yaw_getIdeal(param_0)+180.0f));
        func_8009AE08(param_0);
        break;
    case 3: func_8009AE08(param_0); break;
    case 13: _bamoveledge_entrypoint_3(param_0); break;
    case 6:
        if (bastick_distance(param_0) > 0.0f)
            baphysics_set_target_yaw(param_0, bastick_getAngleRelativeToBanjo(param_0));
        func_8009AE08(param_0);
        break;
    case 10: func_8009B27C(param_0); break;
    case 16:
        _bsfirstp_entrypoint_27(param_0);
        func_8009AE08(param_0);
        func_8009B414(param_0);
        break;
    case 17:
        _bsfirstp_entrypoint_27(param_0);
        func_8009B1FC(param_0);
        break;
    case 14:
        baphysics_set_target_yaw(param_0, yaw_get(param_0));
        func_8009AE08(param_0);
        break;
    case 15: _bamovethrust_entrypoint_5(param_0); break;
    case 18: _bamovespline_entrypoint_10(param_0); break;
    case 19: _bamovehover_entrypoint_2(param_0); break;
    }
    func_8009C0F8(param_0, (*(LocalState_8009B590 **)((u8 *)(param_0)+0xC8))->position);
    (*(LocalState_8009B590 **)((u8 *)(param_0)+0xC8))->scale = 1.0f;
}

void func_8009B7C0(PlayerState *param_0)
{
  u8 *temp_a0;
  u8 *temp_v0;
  f32 temp_f6;
  baphysics_set_target_horizontal_velocity(param_0, 0);
 do { ; *((f32 *) ((*((u8 **) (((u8 *) param_0) + 0xC8))) + 0x18)) = 0.0f; temp_v0 = *((u8 **) (((u8 *) param_0) + 0xC8)); ; } while (0);
  *((f32 *) (temp_v0 + 0x10)) = *((f32 *) (temp_v0 + 0x18));
}

void baphysics_set_type(PlayerState *param_0, BaPhysicsType param_1)
{
    BaPhysicsType local_0;
    local_0 = *(BaPhysicsType *)(*(char **)((char *)param_0 + 0xC8));
    if (local_0 == param_1) return;
    {
        switch (local_0) {
        case 13:
            _bamoveledge_entrypoint_1(param_0);
            break;
        case 15:
            _bamovethrust_entrypoint_0(param_0);
            break;
        case 12:
            _bamovegoto_entrypoint_5(param_0);
            break;
        case 18:
            _bamovespline_entrypoint_5(param_0);
            break;
        case 19:
            _bamovehover_entrypoint_0(param_0);
            break;
        }
        *(s32 *)(*(char **)((char *)param_0 + 0xC8)) = param_1;
        switch (param_1) {
        case 12:
            _bamovegoto_entrypoint_6(param_0);
            break;
        case 13:
            _bamoveledge_entrypoint_2(param_0);
            break;
        case 11:
            if (local_0 != param_1) {
                *(f32 *)(*(char **)((char *)param_0 + 0xC8) + 0x48) = *(f32 *)(*(char **)((char *)param_0 + 0xC8) + 8);
                *(f32 *)(*(char **)((char *)param_0 + 0xC8) + 0x4C) = 0.0f;
            }
            break;
        case 15:
            _bamovethrust_entrypoint_1(param_0);
            break;
        case 18:
            _bamovespline_entrypoint_6(param_0);
            break;
        case 19:
            _bamovehover_entrypoint_1(param_0);
            break;
        }
    }
}

void func_8009B94C(void *param_0, s32 param_1) {
  if (param_1) {
    func_800EE7F8(*(s32 *)((char *)param_0 + 0xC8) + 0x1c);
  } else {
    func_800EFD24(*(s32 *)((char *)param_0 + 0xC8) + 0x1c);
  }
}

void func_8009B98C(void *param_0)
{
    func_800EE7F8((*(s32 *)((char *)(param_0) + 0xC8)) + 4);
}

void baphysics_set_target_horizontal_velocity(PlayerState *param_0, f32 param_1)
{
    *(f32 *)(*(s32 *)((char *)param_0 + 0xC8) + 0x3C) = param_1;
}

void baphysics_set_target_yaw(PlayerState *param_0, f32 param_1)
{
    *(f32 *)(*(s32 *)((char *)param_0 + 0xC8) + 0x40) = func_800136E4(param_1);
}

void func_8009B9F0(PlayerState *param_0, f32 param_1) {
    baphysics_set_target_horizontal_velocity(param_0, param_1);
    func_800EEB9C(*(f32 **)((u8 *)param_0 + 0xC8) + 7, (*(f32 **)((u8 *)param_0 + 0xC8))[16], (*(f32 **)((u8 *)param_0 + 0xC8))[15]);
    (*(f32 **)((u8 *)param_0 + 0xC8))[8] = 0.0f;
    (*(f32 **)((u8 *)param_0 + 0xC8))[4] = (*(f32 **)((u8 *)param_0 + 0xC8))[7];
    (*(f32 **)((u8 *)param_0 + 0xC8))[6] = (*(f32 **)((u8 *)param_0 + 0xC8))[9];
}

void baphysics_set_vertical_velocity(PlayerState *param_0, f32 param_1)
{
  *(f32 *)(*(s32 *)((char *)param_0 + 0xC8) + 0x14) = param_1;
}

void baphysics_set_horizontal_velocity(PlayerState *param_0, f32 yaw, f32 vel)
{
    func_800EEB9C((char *)(*(s32 *)((char *)param_0 + 0xC8)) + 0x10, yaw, vel);
}

void func_8009BA9C(PlayerState *param_0, f32 *param_1)
{
  if (param_1) {
    func_800EE7F8(*(s32 *)((char *)param_0 + 0xC8) + 0x10);
  } else {
    func_800EFD24(*(s32 *)((char *)param_0 + 0xC8) + 0x10);
  }
}

f32 func_8009BADC(PlayerState *param_0)
{
  return ((f32 *)(*(f32 **)((char *)param_0 + 0xC8)))[0xD];
}

f32 func_8009BAE8(PlayerState *param_0){
    f32 local_0[3];

    return *(f32 *)((char *)(*(struct ba_state_timer_list_s **)((char *)param_0 + 0xC8)) + 0x38);
}

s32 func_8009BAF4(struct SomeStruct *param_0) {

    return *(*(s32 **)((char *)param_0 + 0xC8));
}

float baphysics_get_target_horizontal_velocity(PlayerState *param_0)
{
    return *(f32 *)(*(s32 *)((char *)param_0 + 0xC8) + 0x3C);
}

f32 func_8009BB0C(u8 *param_0) {
    return (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x20)));
}

f32 func_8009BB18(u8 *param_0) {
    return (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x40)));
}

void func_8009BB24(PlayerState *player, f32 *param_1)
{
  char *new_var;
  if (1)
  {
    new_var = param_1;
  }
  func_800EE7F8(new_var, new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xC8)))) + 16);
}

f32 baphysics_get_vertical_velocity(PlayerState *param_0) {
    return ((f32 *)((u8 **)param_0)[50])[0x5];
}

f32 func_8009BB5C(PlayerState *param_0)
{
  f32 *new_var;
  f32 *local_1;
 local_1 = *((f32 **) (((char *) param_0) + 0xC8)); new_var = (f32 *) (((char *) local_1) + 24); return sqrtf(((*new_var) * (*(new_var = (f32 *) (((char *) local_1) + 16)))) + ((*((f32 *) (((char *) local_1) + 24))) * (*((f32 *) (((char *) local_1) + 24)))));
}

f32 func_8009BB94(PlayerState *param_0)
{
  func_800EEF94(*(s32 *)((char *)param_0 + 200) + 16);

}

f32 func_8009BBB8(struct PlayerState *param_0) {
    f32 local_0;
    f32 local_1;
    f32 local_2;

    local_0 = func_8009BB5C(param_0);
    local_1 = baphysics_get_target_horizontal_velocity(param_0);
    if (local_0 < local_1) {
        local_2 = local_0 / local_1;
    } else {
        local_2 = 1.0f;
    }
    return local_2;
}

void func_8009BC08(u8 *param_0, s32 param_1) {
    func_800EE7F8(param_1, (*(s32 *)((s8 *)(param_0) + (0xC8))) + 4);
}

void func_8009BC34(PlayerState* arg0)
{
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
}
void func_8009BC5C(PlayerState *param_0, f32 param_1)
{
  *(*(f32 **)((u8*)param_0 + 0xC8) + 17) = param_1;
}

void baphysics_reset_gravity(PlayerState *param_0) {
    baphysics_set_gravity(param_0, D_80117EF0);
}

void baphysics_reset_terminal_velocity(PlayerState *player)
{
    baphysics_set_terminal_velocity(player, D_80117EF4);
}

void baphysics_set_gravity(PlayerState *param_0, f32 param_1)
{
  *(f32 *)(*(s32 *)((char *)param_0 + 0xC8) + 0x34) = param_1;
}

void baphysics_set_terminal_velocity(PlayerState *param_0, f32 param_1)
{
    *(f32 *)(*(s32 *)((char *)param_0 + 0xC8) + 0x38) = param_1;
}

s32 func_8009BCD4(PlayerState *param_0, f32 param_1)
{
    f32 *local_1 = *(f32 **)((char *)(param_0) + 0xC8);
    return local_1[4] * local_1[4] + local_1[6] * local_1[6] <= param_1 * param_1;
}

int func_8009BD18(s32 param_0, f32 param_1)
{
  s32 local_0;
  f32 new_var;
  new_var = param_1;
  *((f32 *) ((*((s32 *) (param_0 + 0xC8))) + 0x50)) = new_var;
}
