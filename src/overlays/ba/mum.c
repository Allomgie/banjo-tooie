#include "playerstate.h"

extern u8 D_80800280_bamum[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA994();

s32 bamum_entrypoint_0()
{
    return 0x8;
}

void func_80800008_bamum(param_0) void *param_0;
{
    f32 local_0 = 0.0f;
    ((f32 *) ((void **) param_0)[0xD0 / 4])[1] = local_0;
}

void func_80800018_bamum(param_0) PlayerState *param_0;
{
    f32 local_8[3];
    f32 local_7[3];
    f32 local_6[3];
    f32 local_5[3];
    f32 local_4[3];
    f32 local_3[3];
    f32 local_2[3];
    f32 local_1[2];
    s32 local_0;

    local_0 = func_800B5BE4(0xD);
    if (((f32 *) *(void **) ((u8 *) param_0 + 0xD0))[1] != 0.0f) {
        func_8009C128(param_0, local_6);
        func_8009C15C(param_0, local_5);
        func_800EFB24(local_7, local_6, local_5);
        func_80092C6C(param_0, local_4);
        func_80092C48(param_0, local_3);
        func_800EF04C(local_4, local_7);
        func_800EF04C(local_3, local_7);
        func_800EFB24(local_7, local_3, local_4);
        func_800F1A88(local_7, local_1);
        local_1[0] = -local_1[0];
        func_800EFD24(local_8);
        func_800EE780(local_2, local_3, local_8);
        func_800BA994(local_0, (s16) (s32) (local_1[0] - 20.0f), (s16) (s32) (local_1[1] - 40.0f),
                      400, (s32) (local_1[0] + 20.0f), (s32) (local_1[1] + 40.0f), 400);
        func_800BABB8(local_0, local_2, NULL, 1.0f, D_80800280_bamum);
        func_800BA22C(local_0,
                      (s32) (((f32 *) *(void **) ((u8 *) param_0 + 0xD0))[1] * 3.0f + 0.5f));
    }
}

void bamum_entrypoint_1(s32 arg0)
{
}

int bamum_entrypoint_2(s32 param_0)
{
    s32 local_0;
    func_80800008_bamum();
    local_0 = 0;
    func_8009ADF0(param_0, 5, local_0);
}

void bamum_entrypoint_3()
{
    func_80800018_bamum();
}

int bamum_entrypoint_4(s32 param_0, s32 param_1)
{
    if (param_1 != 0) {
        func_8009ADF0(param_0, 5, 1);
        func_80800008_bamum(param_0);
    } else {
        func_8009ADF0(param_0, 5, 0 | 0);
    }
}

bamum_entrypoint_5(s32 param_0, f32 param_1)
{
    *(f32 *) (*(s32 *) (param_0 + 208) + 4) = param_1;
}

u8 D_80800280_bamum[48] = {0x0,  0x1D, 0x9, 0xE9, 0x0, 0x15, 0x0, 0x0,  0x0, 0x66, 0x0, 0xC,
                           0x0,  0x2,  0x0, 0x22, 0x0, 0x14, 0x0, 0x14, 0x0, 0x33, 0x0, 0x33,
                           0x0,  0x27, 0x0, 0x0,  0x1, 0x90, 0x0, 0x0,  0x1, 0xB8, 0x0, 0x16,
                           0x10, 0x0,  0x0, 0x2B, 0x0, 0x4C, 0x0, 0x54, 0x0, 0x0,  0x0, 0x0};
