#include "common.h"

extern void func_80115870(s32, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(s32, f32);
extern f32 _bamovethrust_entrypoint_6(s32);
extern f32 func_8009BFCC(s32);
extern f32 func_800F1DCC(f32, f32);
extern f32 yaw_get(s32);
extern f32 func_80013728(f32);
extern f32 func_80115750(s32, f32);
extern f32 func_80112C3C(s32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);

void ncbakaztorp_entrypoint_0(s32 arg0) 
{
}
s32 ncbakaztorp_entrypoint_1(s32 param_0) {
  func_801120CC(param_0, 0x44FA0000, 0x457A0000, 0xC57A0000);
  func_80111B8C(param_0, 0x40800000, 0x41000000);
  func_801124D0(param_0, 1);
  func_80115858(param_0, 2);
  func_80115870(param_0, 0);
}

void ncbakaztorp_entrypoint_2(s32 param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[2];
    s32 local_7;
    f32 local_8[3];
    f32 local_13;
    f32 local_10;
    f32 local_11;
    f32 local_12;
    f32 local_9;
    f32 local_14;

    func_80112524(param_0, local_0);
    func_801107F0(param_0, local_2);
    func_800EFB24(local_1, local_2, local_0);
    local_4 = func_800EEF94(local_1);
    func_800F1A88(local_1, local_5);
    func_80113978(param_0, 1, 1);
    local_4 = func_80115358(param_0, local_4);
    local_7 = func_800F53D0(func_80110840(param_0));
    func_80110818(param_0, local_8);
    local_11 = _bamovethrust_entrypoint_6(local_7);
    local_13 = func_800F1DCC(180.0f, func_8009BFCC(local_7));
    local_12 = func_80013728(local_8[1] - yaw_get(local_7) - 180.0f);
    local_10 = local_12;
    if (local_12 > 90.0f) local_10 = 180.0f - local_12;
    else if (local_12 < -90.0f) local_10 = -180.0f - local_12;
    local_9 = func_80013728(local_8[0] - local_13);
    local_13 = local_9;
    if (local_9 > 90.0f) local_13 = 180.0f - local_9;
    else if (local_9 < -90.0f) local_13 = -180.0f - local_9;
    local_14 = local_11 / 225.0f * 0.4f;
    local_5[0] -= local_14 * local_13;
    local_5[1] -= local_14 * local_10;
    local_5[0] = func_80115750(param_0, local_5[0]);
    local_5[1] = func_80112C3C(param_0, local_5[1]);
    func_800EEBF0(local_1, local_5, local_4);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111FD4(param_0, local_2)) func_801138F4(param_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}
