#include "nc/ba/pan.h"

extern void func_801107F0();
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F1EA4(f32 *, s32);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(Actor *, f32);
extern f32 func_80115750(Actor *, f32);
extern f32 func_80112C3C(Actor *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

s32 ncbapan_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbapan(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbapan(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800048_ncbapan(u8 *param_0) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    func_801107F0(param_0, local_0);
    func_80800028_ncbapan(param_0, local_2);
    func_800EFB24(local_1, local_0, local_2);
    func_800F1EA4(local_1, *(s32 *)(param_0 + 0x38));
}

s32 ncbapan_entrypoint_1(s32 param_0) {
    func_801120CC(param_0, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(param_0, 0x40800000, 0x41000000);
    func_801124D0(param_0, 1);
    func_80115858(param_0, 1);
    func_80115870(param_0, 0x40A00000);
    func_80800048_ncbapan(param_0);
}

void ncbapan_entrypoint_2(s32 arg0) 
{
}
void ncbapan_entrypoint_3(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[2];
    f32 local_6;

    func_80800028_ncbapan(param_0, local_0);
    func_801107F0(param_0, local_2);
    func_800EFB24(local_1, local_2, local_0);
    local_4 = func_800EEF94(local_1);
    func_800F1A88(local_1, local_5);
    func_80113978(param_0, 1, 0);
    local_4 = func_80115358(param_0, local_4);
    local_5[0] = func_80115750(param_0, local_5[0]);
    local_6 = func_80112C3C(param_0, local_5[1]);
    if (local_6 != local_5[1]) **(f32 **)((u8 *)param_0 + 0x38) = local_6;
    local_5[1] = **(f32 **)((u8 *)param_0 + 0x38);
    func_800EEBF0(local_1, local_5, local_4);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111FD4(param_0, local_2)) {
        if ((func_801138A0(param_0) || func_80115580(param_0, local_0)) && func_801138F4(param_0)) func_80110F44(param_0);
        func_80800048_ncbapan(param_0);
    }
    func_80800008_ncbapan(param_0, local_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}
