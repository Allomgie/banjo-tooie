#include "common.h"

extern void func_800EF368(f32 *, f32);
extern void func_800BABB8(s32, f32 *, s32, f32, void *);
extern u8 D_80800110_fxsplash25d[];
int func_8080002C_fxsplash25d();

s32 fxsplash25d_entrypoint_0(void){
    s32 out;
    out = func_8080002C_fxsplash25d();
    func_800BA22C(out, 1);
}

int func_8080002C_fxsplash25d(param_0) f32 *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    s32 local_5;

    func_800EE7F8(local_2, param_0);
    func_800FB350(local_2, &local_5, &local_3);
    local_2[1] = local_3 + 14.0f;
    func_800E3980(local_1);
    func_800EFB24(local_0, local_1, local_2);
    local_0[1] = 0.0f;
    func_800EF368(local_0, 20.0f);
    func_800EF04C(local_2, local_0);
    local_4 = func_800B5BE4(4);
    if (local_5) func_800BA660(local_4, local_5, (s16)local_2[1]);
    func_800BABB8(local_4, local_2, 0, 1.0f, D_80800110_fxsplash25d);
}
