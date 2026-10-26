#include "nc/ba/ledge.h"

extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801112B0(void *);
extern f32 func_800F1DCC(f32, f32);
extern void func_80112D08(void *, s32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void func_80800000_ncbaledge(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800020_ncbaledge(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

int ncbaledge_entrypoint_0(Actor *param_0)
{
  func_80111B8C(param_0, 0x40800000, 0x41000000);
  func_801124D0(param_0, 1);
  func_80115858(param_0, 1);
  func_80115870(param_0, 0x40A00000);
}

void ncbaledge_entrypoint_1(s32 arg0) 
{
}
void ncbaledge_entrypoint_2(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[2];
    f32 local_6;

    func_80800020_ncbaledge(param_0, local_0);
    func_801107F0(param_0, local_2);
    func_800EFB24(local_1, local_2, local_0);
    local_4 = func_800EEF94(local_1);
    func_800F1A88(local_1, local_5);
    local_4 = func_80115358(param_0, local_4);
    local_5[0] = func_80115750(param_0, local_5[0]);
    local_5[1] = func_80112C3C(param_0, local_5[1]);
    local_6 = func_800F1DCC(func_801112B0(param_0), 180.0f);
    func_80112D08(param_0, 5, local_6 - 45.0f, local_6 + 45.0f);
    local_5[1] = func_80112C3C(param_0, local_5[1]);
    func_800EEBF0(local_1, local_5, local_4);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111CC8(param_0, local_2) &&
        (func_801138A0(param_0) || func_80115580(param_0, local_0)) &&
        func_801138F4(param_0)) {
        func_80110F44(param_0);
    }
    func_80800000_ncbaledge(param_0, local_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}
