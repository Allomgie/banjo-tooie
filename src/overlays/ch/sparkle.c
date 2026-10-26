#include "common.h"

extern s16 D_80800120_chsparkle[];
extern u8 D_8080012C_chsparkle[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern int D_80800164_chsparkle;

void func_80800000_chsparkle(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[2];
    s32 local_4;
    s32 local_5;
    local_4 = func_800DC128(0, 5);
    local_5 = func_800B53A4(1);
    func_800BA3FC(local_5, D_80800120_chsparkle[local_4]);
    func_800E3980(local_0);
    func_800EE7F8(local_1, param_0->position);
    local_1[1] -= 200.0f;
    func_800F18FC(param_0->position, local_0, local_3);
    func_800EEB9C(local_2, local_3[1] + func_800DC178(-90.0f, 90.0f), 40.0f);
    func_800EF04C(local_2, param_0->position);
    local_2[1] += func_800DC178(0.0f, 120.0f);
    func_800BABB8(local_5, local_2, local_1, 1.0f, D_8080012C_chsparkle);
}

int chsparkle_entrypoint_0()
{
    return (int)&D_80800164_chsparkle;
}
