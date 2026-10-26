#include "common.h"

extern s32 D_00000000;
extern void func_80095870(void *, f32 *, f32 *);
extern s32 func_8009588C(void *);
extern void *func_800C6C94(f32 *, f32, f32 *, u32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800FAB50(f32 *, f32 *, f32 *, u32, f32);

void bahitspline_entrypoint_0(void *param_0)
{
    void *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    f32 local_7[3];
    u32 local_8;
    f32 local_9[3];

    func_80095870(param_0, &local_1, &local_2);
    func_8009C128(param_0, local_3);
    func_800EFA4C(local_4, local_3[0], local_3[1] + local_1, local_3[2]);
    func_800EE7F8(local_7, local_4);
    local_8 = func_8009588C(param_0);
    local_0 = func_800C6C94(local_7, local_2, local_5, local_8);
    if (local_0) {
        func_800EFA20(local_9, local_5, local_2 * 1.01f);
        func_800EE780(local_6, local_7, local_9);
        if (func_800FAB50(local_6, local_7, local_5, local_8, local_2)) {
            func_800EFB24(local_9, local_7, local_4);
            func_800EF04C(local_3, local_9);
            func_8009C0F8(param_0, local_3);
            func_8009C21C(param_0);
        }
    }
}

void bahitspline_entrypoint_1(s32 arg0) 
{
}
void bahitspline_entrypoint_2(void *param_0) {}
