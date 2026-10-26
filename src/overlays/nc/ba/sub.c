#include "common.h"

extern void func_80115870(s32, f32);
extern void *func_80110840(void *);
extern void *func_800F53D0(void *);
extern f32 func_800F5E7C(void *);
extern f32 func_800F5F7C(void *);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 _bamovethrust_entrypoint_6(void *);
extern f32 func_8009BFCC(void *);
extern f32 func_800F1DCC(f32, f32);
extern f32 yaw_get(void *);
extern f32 func_80013728(f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void ncbasub_entrypoint_0(s32 arg0) 
{
}
void ncbasub_entrypoint_1(s32 param_0)
{
  func_801124D0(param_0, 1);
  func_80115858(param_0, 2);
  func_80115870(param_0, 0);
}

void ncbasub_entrypoint_2(void *param_0)
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    Vec3f local_3;
    Vec3f local_4;
    void *local_5;
    s32 local_6;
    void *local_7;
    Vec3f local_8;
    f32 local_12;
    f32 local_10;
    f32 local_11;
    f32 local_9;
    f32 local_13;

    local_5 = func_80110840(param_0);
    local_6 = func_800F5E7C(local_5) - func_800F5F7C(local_5) < 200.0f;
    func_80112524(param_0, local_0.f);
    func_801107F0(param_0, local_2.f);
    func_800EFB24(local_1.f, local_2.f, local_0.f);
    local_4.pos.z = func_800EEF94(local_1.f);
    func_800F1A88(local_1.f, local_4.f);
    func_80113978(param_0, 1, 1);
    local_4.pos.z = func_80115358(param_0, local_4.pos.z);
    local_7 = func_800F53D0(func_80110840(param_0));
    func_80110818(param_0, local_8.f);
    local_11 = _bamovethrust_entrypoint_6(local_7);
    local_12 = func_800F1DCC(180.0f, func_8009BFCC(local_7));
    local_10 = func_80013728(local_8.pos.y - yaw_get(local_7) - 180.0f);
    if (local_10 > 90.0f) {
        local_10 = 180.0f - local_10;
    } else if (local_10 < -90.0f) {
        local_10 = -180.0f - local_10;
    }
    local_9 = local_8.pos.x - local_12;
    local_12 = func_80013728(local_9);
    if (local_12 > 90.0f) {
        local_12 = 180.0f - local_12;
    } else if (local_12 < -90.0f) {
        local_12 = -180.0f - local_12;
    }
    local_13 = (local_11 / 90.0f) * 0.3f;
    local_4.pos.x -= local_13 * local_12;
    if (!local_6) {
        local_4.pos.y -= local_13 * local_10;
    }
    local_4.pos.x = func_80115750(param_0, local_4.pos.x);
    local_4.pos.y = func_80112C3C(param_0, local_4.pos.y);
    func_800EEBF0(local_1.f, local_4.f, local_4.pos.z);
    func_800EE780(local_2.f, local_0.f, local_1.f);
    if (func_80111CC8(param_0, local_2.f) &&
        (func_801138A0(param_0) || func_80115580(param_0, local_0.f))) {
        func_801138F4(param_0);
    }
    func_80110A68(param_0, local_3.f, local_0.f);
    func_80110790(param_0, local_3.f);
    func_80115858(param_0, local_6 ? 1 : 2);
}
