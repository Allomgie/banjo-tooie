#include "nc/ba/pivot.h"

extern f32 _ncbawaypoint_entrypoint_3(void *, Vec3f *, Vec3f *);
extern f32 func_800EEF94(Vec3f *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801125E8(void *);
extern void func_800EEBF0(Vec3f *, f32 *, f32);

s32 ncbapivot_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbapivot(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

int ncbapivot_entrypoint_1(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_801120CC(local_0, 0x44FA0000, 0x457A0000, 0xC57A0000);
  func_80111B8C(local_0, 0x40800000, 0x41000000);
  func_801124D0(local_0, 1);
  func_80115858(local_0, 1);
  func_80115870(local_0, 0x40A00000);
}

void ncbapivot_entrypoint_2(s32 arg0) 
{
}
void ncbapivot_entrypoint_3(u8 *param_0)
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    Vec3f local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7[2];
    Vec3f local_9;

    func_8011607C(param_0, 1);
    func_80113978(param_0, 1, 0);
    func_80800008_ncbapivot(param_0, &local_0);
    func_801107F0(param_0, &local_3);
    func_800EE7F8(&local_9, &local_0);
    if (**(s32 **)(param_0 + 0x5C)) {
        local_5 = _ncbawaypoint_entrypoint_3(param_0, &local_9, &local_3);
    } else {
        local_5 = 0.0f;
    }
    func_800EFB24(&local_2, &local_3, &local_9);
    local_6 = func_800EEF94(&local_2) + local_5;
    func_800F1A88(&local_2, local_7);
    local_4 = func_80115358(param_0, local_6);
    local_7[0] = func_80115750(param_0, local_7[0]);
    local_7[1] = func_80112C3C(param_0, local_7[1]);
    local_7[1] += func_801125E8(param_0);
    local_4 -= local_5;
    func_800EEBF0(&local_2, local_7, local_4);
    func_800EE780(&local_3, &local_9, &local_2);
    if (func_80111FD4(param_0, &local_3)) {
        if (func_801138A0(param_0)) {
            if (func_801138F4(param_0)) {
                func_80110F44(param_0);
            }
        } else if (func_80115580(param_0, &local_9) || func_80115580(param_0, &local_0)) {
            if (func_801138F4(param_0)) {
                func_80110F44(param_0);
            }
        }
    }
    func_80110A68(param_0, &local_1, &local_0);
    func_80110790(param_0, &local_1);
    if (local_5 != 0.0f) {
        func_80111310(param_0);
    }
}
