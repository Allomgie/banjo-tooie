#include "nc/ba/target.h"

extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern void func_80112D08(void *, s32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);

s32 ncbatarget_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_ncbatarget(PlayerState *param_0, s32 param_1) {
    f32 sp1C[3];

    func_80112524(param_0, param_1);
    func_800EFB24(sp1C, (*(u8 **)((s8 *)(param_0) + (0x58))), param_1);
    func_800EF174(param_1, sp1C, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x58)))) + (0xC))));
}

void func_80800058_ncbatarget(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

s32 ncbatarget_entrypoint_1(s32 param_0) {
    func_801120CC(param_0, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(param_0, 0x40800000, 0x41000000);
    func_801124D0(param_0, 1);
    func_80115858(param_0, 1);
    func_80115870(param_0, 0x40A00000);
    func_800EFD24(*(u8 **)(param_0 + 0x58));
    *(f32 *)((char *)(*(u8 **)(param_0 + 0x58)) + 0xC) = 0.5f;
    func_8011607C(param_0, 1);
}

void ncbatarget_entrypoint_2(s32 arg0) 
{
}
void ncbatarget_entrypoint_3(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_6;
    f32 local_5[2];
    f32 local_7;
    func_8011607C(param_0, 1);
    func_80800058_ncbatarget(param_0, local_1);
    func_80800008_ncbatarget(param_0, local_0);
    func_801107F0(param_0, local_3);
    func_800EFB24(local_2, local_3, local_1);
    local_6 = func_800EEF94(local_2);
    func_800F1A88(local_2, local_5);
    local_6 = func_80115358(param_0, local_6);
    local_5[0] = func_80115750(param_0, local_5[0]);
    func_800F1E6C(*(f32 **)(param_0 + 0x58), local_1, &local_7);
    func_80112D08(param_0, 5, local_7, local_7);
    local_5[1] = func_80112C3C(param_0, local_5[1]);
    func_800EEBF0(local_2, local_5, local_6);
    func_800EE780(local_3, local_1, local_2);
    if (func_80111FD4(param_0, local_3) && func_801138A0(param_0) && func_801138F4(param_0))
        func_80110F44(param_0);
    func_80110A68(param_0, local_4, local_0);
    func_80110790(param_0, local_4);
}

int ncbatarget_entrypoint_4(s32 param_0, f32 param_1)
{
  int new_var;
  new_var = param_0;
  *((f32 *) ((*((s32 *)((char *)(new_var) + 88))) + 12)) = param_1;
  new_var = new_var + 0x50;
}

void ncbatarget_entrypoint_5(Actor *param_0)
{
    func_800EE7F8(*(s32 *)((s8 *)param_0 + 0x58));
}
