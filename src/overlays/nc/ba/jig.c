#include "nc/ba/jig.h"

typedef struct { u8 pad_0[0x2C]; f32 *local_0; } JigCameraState;
extern void func_80111B8C(void *, f32, f32);
extern void func_80115870(void *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_80115358(void *, f32);
extern void func_80115828(void *, f32, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);

s32 ncbajig_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_ncbajig(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbajig(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void ncbajig_entrypoint_1(JigCameraState *param_0)
{
    func_80111B8C(param_0, 1.8f, 14.0f);
    param_0->local_0[0] = 290.0f;
    param_0->local_0[1] = 12.0f;
    func_80115858(param_0, 0);
    func_80115870(param_0, 5.0f);
    func_801124D0(param_0, 5);
}

void ncbajig_entrypoint_2(s32 arg0) 
{
}
void ncbajig_entrypoint_3(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_5;
    f32 local_4[2];
    func_80800028_ncbajig(param_0, local_0);
    func_801107F0(param_0, local_2);
    func_800EFB24(local_1, local_2, local_0);
    local_5 = func_800EEF94(local_1);
    func_800F1A88(local_1, local_4);
    local_5 = func_80115358(param_0, local_5);
    if (((f32 *)*(u8 **)(param_0 + 0x2C))[0] < local_5)
        local_5 = ((f32 *)*(u8 **)(param_0 + 0x2C))[0];
    func_80115828(param_0, ((f32 *)*(u8 **)(param_0 + 0x2C))[1],
        ((f32 *)*(u8 **)(param_0 + 0x2C))[1]);
    local_4[0] = func_80115750(param_0, local_4[0]);
    local_4[1] = func_80112C3C(param_0, local_4[1]);
    func_800EEBF0(local_1, local_4, local_5);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111CC8(param_0, local_2) && func_801138A0(param_0) && func_801138F4(param_0))
        func_80110F44(param_0);
    func_80800008_ncbajig(param_0, local_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}
