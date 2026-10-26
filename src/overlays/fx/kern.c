#include "common.h"

typedef struct { u8 local_0; u8 local_1; s8 local_2; s8 local_3; } FxKernPair59;
extern FxKernPair59 D_80800420_fxkern[];
typedef struct { f32 x; f32 y; } KernPos;
extern KernPos B_80800488_fxkern[];
extern s32 func_800D36C4(s32, s32);
extern void func_800B8C98(s32);
extern void func_800B7F14(s32);
extern void func_800B8DEC(s32, s32, s32, s32);
extern void func_800B811C(s32);
typedef struct { f32 local_0; f32 local_1; } FxKernMetrics;
extern float B_80800480_fxkern;
extern void func_800B8CF0(f32);

void func_80800000_fxkern(u8 param_0, u8 param_1, s32 *param_2, s32 *param_3)
{
    s32 local_0;

    *param_2 = *param_3 = 0;
    for (local_0 = 0; D_80800420_fxkern[local_0].local_0; local_0++) {
        if (D_80800420_fxkern[local_0].local_1 == param_0 &&
            (D_80800420_fxkern[local_0].local_0 == param_1 ||
             D_80800420_fxkern[local_0].local_0 == '*')) {
            *param_2 = D_80800420_fxkern[local_0].local_2;
            *param_3 = D_80800420_fxkern[local_0].local_3;
            return;
        }
    }
}

s32 func_80800084_fxkern(u8 *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    B_80800488_fxkern[0].x = 0.0f;
    B_80800488_fxkern[0].y = 0.0f;
    for (local_0 = 1; param_0[local_0] != 0 && local_0 != 0x40; local_0++) {
        B_80800488_fxkern[local_0].x = B_80800488_fxkern[local_0 - 1].x;
        B_80800488_fxkern[local_0].x += ((f32 *) &B_80800480_fxkern)[0] * (func_800D36C4(1, param_0[local_0 - 1]) / 2);
        B_80800488_fxkern[local_0].x += ((f32 *) &B_80800480_fxkern)[0] * (func_800D36C4(1, param_0[local_0]) / 2);
        B_80800488_fxkern[local_0].x += ((f32 *) &B_80800480_fxkern)[0] * -4.0f;
        func_80800000_fxkern(param_0[local_0], param_0[local_0 - 1], &local_1, &local_2);
        B_80800488_fxkern[local_0].x += ((f32 *) &B_80800480_fxkern)[0] * local_1;
        B_80800488_fxkern[local_0].y = local_2;
        B_80800488_fxkern[local_0].y *= ((f32 *) &B_80800480_fxkern)[0];
    }
    return local_0 - 1;
}

int func_80800224_fxkern(s32 param_0, s32 param_1, s32 param_2, u8 *param_3, s32 param_4)
{
    func_800B8C98(1);
    func_800B7F14(param_0);
    for (; param_4 >= 0; param_4--) {
        func_800B8DEC(param_0, ((f32 (*)[2]) B_80800488_fxkern)[param_4][0] + param_1, ((f32 (*)[2]) B_80800488_fxkern)[param_4][1] + param_2, param_3[param_4]);
    }
    func_800B811C(param_0);
}

s32 fxkern_entrypoint_0(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0 = func_80800084_fxkern(param_3);

    return func_80800224_fxkern(param_0, param_1, param_2, param_3, local_0);
}

void fxkern_entrypoint_1(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    FxKernMetrics *local_1;

    local_0 = func_80800084_fxkern(param_2);
    local_1 = (FxKernMetrics *)((f32 *) B_80800488_fxkern);
    func_80800224_fxkern(param_0, (s32)((304.0f - local_1[local_0].local_0) / 2),
        param_1, param_2, local_0);
}

int fxkern_entrypoint_2()
{
  func_800B8C50();
  B_80800480_fxkern = 1.0f;
}

void fxkern_entrypoint_3(f32 param_0) {
    func_800B8CF0(param_0);
    B_80800480_fxkern = param_0;
}
