#include "nc/ba/bee.h"

extern f32 func_800F5AE0(s32);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern void func_80115828(void *, f32, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_801112B0(void *);
extern void func_800EEBF0(f32 *, f32 *, f32);

int ncbabee_entrypoint_0(Actor *param_0)
{
  extern void func_80115870(Actor *a0, f32 a1);
  int new_var;
  func_801120CC(param_0, 0x44FA0000, 0x457A0000, 0xC57A0000);
  func_80111B8C(param_0, 0x40800000, 0x41000000);
  new_var = 0;
  func_80115858(param_0, new_var);
  func_80115870(param_0, 0);
  func_801124D0(param_0, 1);
}

void ncbabee_entrypoint_1(s32 arg0) 
{
}
void func_80800070_ncbabee(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0,arg1);
}

void ncbabee_entrypoint_2(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4[3];
    s32 local_5;
    f32 local_6[3];
    s32 local_7;
    f32 local_8;

    local_7 = func_80110840();
    func_8011607C(param_0, 1);
    func_801107F0(param_0, local_1);
    func_80800070_ncbabee(param_0, local_0);
    func_80115444(param_0, &local_3, &local_5);
    local_8 = func_80013728(func_800F5AE0(local_7));
    func_80115828(param_0, local_8, local_8);
    func_800EFB24(local_6, local_1, local_0);
    func_800F1A88(local_6, local_4);
    local_4[0] = func_80115750(param_0, local_4[0]);
    local_4[1] = func_800136E4(func_801112B0(param_0) + 180.0f);
    func_800EEBF0(local_6, local_4, local_3);
    func_800EE780(local_1, local_0, local_6);
    if (func_80111FD4(param_0, local_1)) {
        func_801138F4(param_0);
    }
    func_80112524(param_0, local_0);
    func_80110A68(param_0, local_2, local_0);
    func_80110790(param_0, local_2);
}
