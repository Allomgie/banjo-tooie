#include "nc/ba/die.h"

extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(Actor *, f32);
extern f32 func_80013AAC(f32);
extern void func_80115828(Actor *, f32, f32);
extern f32 func_80115750(Actor *, f32);
extern f32 func_80112C3C(Actor *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
int ncbadie_entrypoint_3(s32 param_0, f32 param_1);

s32 ncbadie_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbadie(u8 *param_0, u8 *param_1)
{
  if (1)
  {
  }
  func_80112524(param_0, param_1);
  *((f32 *) (((char *) param_1) + 4)) = (*((f32 *) (((char *) (*((f32 **) (((char *) param_0) + 0x10)))) + 0))) + (*((f32 *) (((char *) param_1) + 4)));
}

void func_80800048_ncbadie(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

s32 ncbadie_entrypoint_1(Actor *this){
    ncbadie_entrypoint_3(this, 3e+01f);
    func_80111B8C(this, 0x3FB33333, 0x41600000);
    func_80115858(this, 0);
    func_80115870(this, 0x40A00000);
    func_801124D0(this, 4);
}

void ncbadie_entrypoint_2(s32 arg0) 
{
}
ncbadie_entrypoint_3(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 16) + 0) = param_1;
}

void ncbadie_entrypoint_4(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[2];
    f32 local_6;

    func_80800048_ncbadie(param_0, local_0);
    func_801107F0(param_0, local_2);
    func_800EFB24(local_1, local_2, local_0);
    local_4 = func_800EEF94(local_1);
    func_800F1A88(local_1, local_5);
    local_4 = func_80115358(param_0, local_4);
    if (local_4 > 220.0f) local_4 = 220.0f;
    local_6 = func_80013AAC((120.0f - **(f32 **)((u8 *)param_0 + 0x10)) / 220.0f);
    func_80115828(param_0, local_6, local_6);
    local_5[0] = func_80115750(param_0, local_5[0]);
    local_5[1] = func_80112C3C(param_0, local_5[1]);
    func_800EEBF0(local_1, local_5, local_4);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111CC8(param_0, local_2) && func_801138A0(param_0) && func_801138F4(param_0)) func_80110F44(param_0);
    func_80800008_ncbadie(param_0, local_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}
