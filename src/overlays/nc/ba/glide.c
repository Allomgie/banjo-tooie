#include "nc/ba/glide.h"

extern void func_80111590(void *, f32, f32, f32, f32);
extern void func_80111B8C(void *, f32, f32);
extern void func_80115858(void *, s32);
extern void func_80115870(void *, f32);
extern void func_801124D0(void *, s32);
extern f32 func_800F5AE0(s32);
extern f32 func_80013728(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80115828(void *, f32, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_801112B0(void *);
extern f32 func_800136E4(f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void ncbaglide_entrypoint_0(void *param_0)
{
    func_80111590(param_0, 10.0f, 20.0f, 120.0f, 200.0f);
    func_80111B8C(param_0, 4.0f, 8.0f);
    func_80115858(param_0, 0);
    func_80115870(param_0, 0.0f);
    func_801124D0(param_0, 1);
}

void ncbaglide_entrypoint_1(s32 arg0) 
{
}
void func_8080007C_ncbaglide(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void ncbaglide_entrypoint_2(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4[3];
    f32 local_5;
    f32 local_6[3];
    s32 local_7;
    f32 local_8;

    local_7 = func_80110840(param_0);
    func_8011607C(param_0, 1);
    func_801107F0(param_0, local_1);
    func_8080007C_ncbaglide(param_0, local_0);
    func_80115444(param_0, &local_3, &local_5);
    local_8 = func_80013728(func_800F5AE0(local_7));
    if (local_8 < 0.0f) {
        local_8 = func_800F10B4(local_8, -30.0f, -60.0f, 0.0f, 84.0f);
        func_80115828(param_0, local_8, local_8);
    } else {
        func_80115828(param_0, local_8, local_8);
    }
    func_800EFB24(local_6, local_1, local_0);
    func_800F1A88(local_6, local_4);
    local_4[0] = func_80115750(param_0, local_4[0]);
    local_4[1] = func_800136E4(func_801112B0(param_0) + 180.0f);
    func_800EEBF0(local_6, local_4, local_3);
    func_800EE780(local_1, local_0, local_6);
    if (func_80111CC8(param_0, local_1)) func_801138F4(param_0);
    func_80112524(param_0, local_0);
    func_80110A68(param_0, local_2, local_0);
    func_80110790(param_0, local_2);
}
