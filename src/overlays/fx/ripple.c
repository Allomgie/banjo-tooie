#include "common.h"

extern s32 func_800FB2AC(f32 *, f32);
extern s32 func_800FB338(f32 *, s32, s32 *, f32 *);
extern u8 *D_80800320_fxripple[];
extern u8 D_80800334_fxripple[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800BA660();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800BA22C(s32, s32);

int func_80800000_fxripple(f32 *param_0, s32 *param_1, s32 param_2)
{
    f32 local_0;
    *param_1 = 0;
    if (param_2) {
        param_0[1] += 1.0f;
    } else {
        param_2 = func_800FB2AC(param_0, 50.0f);
        if (!param_2) return 0;
    }
    if (func_800FB338(param_0, param_2, param_1, &local_0)) param_0[1] = local_0;
    return 1;
}

s32 func_80800094_fxripple(param_0, param_1, param_2)
s32 param_0;
f32 *param_1;
s32 param_2;
{
    s32 local_0;
    f32 local_1[3];
    s32 local_2;

    func_800EE7F8(local_1, param_1);
    if (!func_80800000_fxripple(local_1, &local_0, param_2)) return 0;
    local_1[1] += 3.0f;
    local_2 = func_800B5BE4(3);
    if (local_0 != 0) func_800BA660(local_2, local_0, (s16)(s32)local_1[1]);
    else func_800BA660(local_2, 0, 0);
    func_800BABB8(local_2, local_1, 0, 1.0f, D_80800334_fxripple);
    func_800BABB8(local_2, 0, 0, 1.0f, D_80800320_fxripple[param_0]);
    return local_2;
}

void fxripple_entrypoint_0(s32 param_0, s32 param_1) {
    s32 local_0 = func_80800094_fxripple(param_0, param_1, 0);
    if (local_0 != 0) {
        func_800BA22C(local_0, 1);
    }
}

s32 fxripple_entrypoint_1(s32 position[3]) {
    Actor *actor = func_80800094_fxripple(position);
    if (actor) {
        func_800BA22C(actor, 1);
    }
}

void fxripple_entrypoint_2(s32 p0, s32 p1) {
    func_80800094_fxripple(p0, p1, 0);
}

void fxripple_entrypoint_3()
{
    func_80800094_fxripple();
}

s32 fxripple_entrypoint_4(f32 param_0){
    s32 local_0;
    s32 local_1;

    local_0 = func_800B5BE4(3);
    local_1 = (s16)param_0;
    func_800BA5D0(local_0 | 0, local_1);
}
