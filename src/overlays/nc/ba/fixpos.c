#include "common.h"

extern void func_801124D0();
extern u32 func_80110840(void *);
extern f32 func_800F5628(u32);
extern f32 func_800F5E7C(u32);
extern f32 func_80115460(void *);
typedef struct { f32 local_0[3]; f32 local_1[3]; u8 local_2; u8 local_3; u8 local_4; } FixedCameraPosition;
typedef struct { u8 pad_0[0x20]; FixedCameraPosition *local_0; } FixedCameraNode;

s32 ncbafixpos_entrypoint_0() 
{
    return 0x1C;
}

void ncbafixpos_entrypoint_1(u8 *param_0) {
    (*(u8 **)(param_0 + 0x20))[0x1A] = 1;
    func_801124D0(param_0, 1);
}

void ncbafixpos_entrypoint_2(s32 arg0) 
{
}
f32 func_8080003C_ncbafixpos(void *param_0)
{
    u32 local_0;
    f32 local_1;

    local_0 = func_80110840(param_0);
    func_800F5628(local_0);
    if (func_800F71D4(local_0)) {
        local_1 = func_800F5E7C(local_0);
    } else {
        local_1 = func_800F5628(local_0);
    }
    return func_80115460(param_0) + local_1;
}

void ncbafixpos_entrypoint_3(FixedCameraNode *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    if (!param_0->local_0->local_4) {
        func_801107F0(param_0, local_1);
        func_800EE7F8(local_3, param_0->local_0->local_1);
        local_1[0] = param_0->local_0->local_0[0];
        local_1[2] = param_0->local_0->local_0[2];
        if (param_0->local_0->local_2) local_1[1] = param_0->local_0->local_0[1];
        else local_1[1] = func_8080003C_ncbafixpos(param_0);
        func_80111AE0(param_0, local_1);
        if (param_0->local_0->local_3) func_8011329C(param_0);
        func_80112524(param_0, local_0);
        func_80110A68(param_0, local_2, local_0);
        func_80110790(param_0, local_2);
    }
}

void ncbafixpos_entrypoint_4(u8 *param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    func_800A5800(param_1);
    _cadbfunc_entrypoint_29(2, &local_2);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x20)))) + (0x18))) = (s8) local_2;
    _cadbfunc_entrypoint_29(1, &local_2);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x20)))) + (0x19))) = (s8) local_2;
    _cadbfunc_entrypoint_4((*(u8 **)((s8 *)(param_0) + (0x20))) + 0xC);
    _cadbfunc_entrypoint_0((*(u8 **)((s8 *)(param_0) + (0x20))));
    _cadbfunc_entrypoint_6(&local_0, &local_1);
    func_80111B8C(param_0, local_0, local_1);
    _cadbfunc_entrypoint_8(&local_0, &local_1);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x20)))) + (0x1A))) = 0;
    func_80112570(param_0, (*(u8 **)((s8 *)(param_0) + (0x20))) + 0xC, 0x42C80000);
}
