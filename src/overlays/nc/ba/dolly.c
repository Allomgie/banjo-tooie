#include "common.h"

extern void func_801124D0();
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct { u8 pad_0[0xC]; f32 local_0[3]; f32 local_1; f32 local_2; u8 local_3; u8 local_4; u8 pad_1[2]; f32 local_5; f32 local_6; } DollyCameraData;
typedef struct { u8 pad_0[0x1C]; DollyCameraData *local_0; } DollyCamera;
extern void func_80111B8C(DollyCamera *, f32, f32);
extern void func_80112570(DollyCamera *, f32 *, f32);

s32 ncbadolly_entrypoint_0() 
{
    return 0x2C;
}

void ncbadolly_entrypoint_1(u8 *param_0) {
    (*(u8 **)(param_0 + 0x1c))[0x21] = 1;
    func_801124D0(param_0, 1);
}

void ncbadolly_entrypoint_2(s32 arg0) 
{
}
void ncbadolly_entrypoint_3(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_6;
    f32 local_4[3];
    f32 local_5;
    u8 *local_7;
    if (!(*(u8 **)(param_0 + 0x1C))[0x21]) {
        func_80112524(param_0, local_0);
        func_801107F0(param_0, local_1);
        func_800EFB24(local_4, local_1, local_0);
        local_4[1] = 0.0f;
        local_5 = func_800EEFFC(local_4);
        local_7 = *(u8 **)(param_0 + 0x1C);
        if (local_5 < *(f32 *)(local_7 + 0x1C)) local_5 = *(f32 *)(local_7 + 0x1C);
        if (*(f32 *)(local_7 + 0x18) < local_5) local_5 = *(f32 *)(local_7 + 0x18);
        func_800EFB24(local_3, (f32 *)local_7, local_0);
        local_3[1] = 0.0f;
        local_6 = func_800EEFFC(local_3);
        if (local_6 < local_5) local_5 = local_6;
        func_800EFA98(local_4, local_3, local_5);
        func_800EF04C(local_4, local_0);
        local_4[1] = ((f32 *)*(u8 **)(param_0 + 0x1C))[1];
        func_80111AE0(param_0, local_4);
        if ((*(u8 **)(param_0 + 0x1C))[0x20]) func_8011329C(param_0);
        func_80112524(param_0, local_0);
        func_80110A68(param_0, local_2, local_0);
        func_80110790(param_0, local_2);
    }
}

void ncbadolly_entrypoint_4(DollyCamera *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1;
    s32 local_2;

    func_800A5800(param_1);
    _cadbfunc_entrypoint_29(1, &local_2);
    param_0->local_0->local_3 = local_2;
    _cadbfunc_entrypoint_4(param_0->local_0->local_0);
    _cadbfunc_entrypoint_0(param_0->local_0);
    _cadbfunc_entrypoint_6(&local_0, &local_1);
    func_80111B8C(param_0, local_0, local_1);
    _cadbfunc_entrypoint_8(&local_0, &local_1);
    param_0->local_0->local_5 = local_0;
    param_0->local_0->local_6 = local_1;
    _cadbfunc_entrypoint_18(&param_0->local_0->local_2);
    _cadbfunc_entrypoint_20(&param_0->local_0->local_1);
    param_0->local_0->local_4 = 0;
    func_80112570(param_0, param_0->local_0->local_0, 150.0f);
}
