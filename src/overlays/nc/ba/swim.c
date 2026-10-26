#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_80115870(s32, f32);
extern f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_80113978(void *, s32, s32);
extern f32 func_80115358(void *, f32);
extern f32 _baswim_entrypoint_14(PlayerState *);
extern f32 func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_8009BFCC(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_80013728(f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801155E8(void *);
extern PlayerState *func_800F53D0(s32);

s32 ncbaswim_entrypoint_0() 
{
    return 0x4;
}

void ncbaswim_entrypoint_1(s32 arg0) 
{
}
s32 ncbaswim_entrypoint_2(s32 param_0)
{
  func_801124D0(param_0, 1);
  func_80115858(param_0, 2);
  func_80115870(param_0, 0);
}

void ncbaswim_entrypoint_3(u8 *param_0)
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    Vec3f local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7[2];
    PlayerState *local_9;
    Vec3f local_10;
    f32 local_11;
    f32 local_12;
    f32 local_13;
    f32 local_14;
    f32 local_15;

    func_80112524(param_0, local_0.f);
    func_801107F0(param_0, local_2.f);
    if (**(s32 **)(param_0 + 0x5C)) {
        local_5 = _ncbawaypoint_entrypoint_3(param_0, local_0.f, local_2.f);
    } else {
        local_5 = 0.0f;
    }
    func_800EFB24(local_1.f, local_2.f, local_0.f);
    local_6 = func_800EEF94(local_1.f) + local_5;
    func_800F1A88(local_1.f, local_7);
    local_7[0] += func_80113978(param_0, 1, 1);
    local_4 = func_80115358(param_0, local_6);
    local_9 = func_800F53D0(func_80110840(param_0));
    func_80110818(param_0, local_10.f);
    local_13 = _baswim_entrypoint_14(local_9);
    local_11 = func_800F1DCC(180.0f, func_8009BFCC(local_9));
    if (param_0) {}
    local_12 = func_80013728(local_10.pos.y - yaw_get(local_9) - 180.0f);
    if (local_11) {}
    if (local_12 > 90.0f) {
        local_12 = 180.0f - local_12;
    } else if (local_12 < -90.0f) {
        local_12 = -180.0f - local_12;
    }
    local_14 = func_80013728(local_10.pos.x - local_11);
    if (local_14 > 90.0f) {
        local_14 = 180.0f - local_14;
    } else if (local_14 < -90.0f) {
        local_14 = -180.0f - local_14;
    }
    local_15 = (local_13 / 900.0f) * 0.2f;
    local_7[0] -= local_15 * local_14;
    local_7[1] -= local_15 * local_12;
    local_7[0] = func_80115750(param_0, local_7[0]);
    local_7[1] = func_80112C3C(param_0, local_7[1]);
    local_4 -= local_5;
    func_800EEBF0(local_1.f, local_7, local_4);
    func_800EE780(local_2.f, local_0.f, local_1.f);
    if (func_80111CC8(param_0, local_2.f)) {
        if (func_801138A0(param_0)) {
            if (func_801138F4(param_0)) {
                func_80110F44(param_0);
            }
        } else if (func_80115580(param_0, local_0.f) && func_801155E8(param_0) < local_6) {
            func_801138F4(param_0);
        }
    }
    func_80112524(param_0, local_0.f);
    func_80110A68(param_0, local_3.f, local_0.f);
    func_80110790(param_0, local_3.f);
}
