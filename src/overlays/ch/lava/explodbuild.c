#include "ch/lavaexplodbuild.h"

extern u8 position_x[];
extern u8 unk44[];
extern int D_80800290_chlavaexplodbuild;
extern s32 D_808002A4_chlavaexplodbuild[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern int D_808002E0_chlavaexplodbuild;
void func_80800138_chlavaexplodbuild();

int func_80800000_chlavaexplodbuild(Actor *param_0)
{
    f32 *local_0 = (f32 *)((char *)param_0 + 4);
    (*(f32 *)((char *)(local_0) + 68)) = 45.0f;
    func_800EFA4C(local_0, 0xC6115000, 0x42480000, 0xC3FA0000);
    func_80103014(param_0);
}

s32 func_80800048_chlavaexplodbuild(s32 param_0){
    s32 temp = func_8010CB0C(param_0 + 4, 0x708, 0x7D0, -0x1F4);
    func_800DA3B8(0xA24, temp);
}

void func_80800084_chlavaexplodbuild(s32 arg0)
{
    func_800DA524(FLAG3_A24_UNK);
}

int func_808000A8_chlavaexplodbuild(s32 param_0, s32 param_1, s32 param_2)
{
  u8 *local_0;
  if (param_1 == 0x40)
  {
    local_0 = param_0 + 4;
    _chexploder_entrypoint_3(param_0, local_0, 0xC);
    func_80800138_chlavaexplodbuild(param_0);
    func_800C4AF0(local_0, &D_80800290_chlavaexplodbuild);
    func_800E15CC(0, 0x42A00000, 0x3F733333);
    func_80018820(0, 0x40800000, 0x3EE66666);
    func_800DA544(0x49);
    } else {
        return 0;
    }
    return 1;
}

void func_80800138_chlavaexplodbuild(param_0) Actor *param_0;
{
    s32 local_2;
    Vec3f local_0;
    Vec3f local_1;
    s32 local_3;

    func_800EE7F8(local_1.f, param_0->position);
    local_2 = func_800B53A4(10);
    for (local_3 = 0; local_3 != 10; local_3++) {
        func_800EEB9C(local_0.f, (f32)local_3 * 36.0f, func_800DC178(300.0f, 400.0f));
        func_800EF04C(local_0.f, param_0->position);
        local_0.f[1] += func_800DC178(400.0f, 600.0f);
        func_800BABB8(local_2, local_0.f, local_1.f, 2.25f, D_808002A4_chlavaexplodbuild);
    }
}

int chlavaexplodbuild_entrypoint_0()
{
    return (int)&D_808002E0_chlavaexplodbuild;
}
