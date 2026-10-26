#include "nc/ba/spiral.h"

extern f32 func_800EEF94(f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_80112D08(void *, s32, f32, f32);

s32 ncbaspiral_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void ncbaspiral_entrypoint_1(u8 *param_0)
{
    extern void func_80111B8C(u8 *, f32, f32);
    extern void func_80115870(u8 *, f32);

    func_80111B8C(param_0, 4.0f, 8.0f);
    func_801124D0(param_0, 1);
    func_80115858(param_0, 1);
    func_80115870(param_0, 5.0f);
    func_800EFD24(*(u8 **)(param_0 + 0x48) + 4);
    **(s32 **)(param_0 + 0x48) = -1;
}

void ncbaspiral_entrypoint_2(s32 arg0) 
{
}
void ncbaspiral_entrypoint_3(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[2];
    f32 local_6;

    func_80800028_ncbaspiral(param_0, local_0);
    func_801107F0(param_0, local_2);
    func_800EFB24(local_1, local_2, local_0);
    local_4 = func_800EEF94(local_1);
    func_800F1A88(local_1, local_5);
    local_4 = func_80115358(param_0, local_4);
    local_5[0] = func_80115750(param_0, local_5[0]);
    func_800F1E6C(*(u8 **)((u8 *)param_0 + 0x48) + 4, local_0, &local_6);
    func_80112D08(param_0, 5, local_6 - 10.0f, local_6 + 10.0f);
    local_5[1] = func_80112C3C(param_0, local_5[1]);
    func_800EEBF0(local_1, local_5, local_4);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111CC8(param_0, local_2) &&
        (func_801138A0(param_0) || func_80115580(param_0, local_0)) &&
        func_801138F4(param_0)) {
        func_80110F44(param_0);
    }
    func_80800008_ncbaspiral(param_0, local_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}

void ncbaspiral_entrypoint_4(u8 *param_0) {
    func_800EE7F8((*(u8 **)((s8 *)(param_0) + (0x48))) + 4);
    *(*(s32 **)((s8 *)(param_0) + (0x48))) = -1;
}

void ncbaspiral_entrypoint_5(u8 *param_0, s32 param_1) {
    s32 local_0;
    f32 local_1[4];

    if (param_1 != *(*(s32 **)((s8 *)(param_0) + (0x48)))) {
        func_800A5800(param_1);
        _cadbfunc_entrypoint_24(&local_0);
        func_801107B0(param_0, local_1);
        _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(local_0 + 0x1D1, local_1), (*(u8 **)((s8 *)(param_0) + (0x48))) + 4);
        *(*(s32 **)((s8 *)(param_0) + (0x48))) = param_1;
    }
}
