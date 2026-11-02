#include "ch/doubloon.h"

extern u8 D_80800290_chdoubloon[];
extern int D_808002A0_chdoubloon;
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
void chdoubloon_entrypoint_1();

void func_80800000_chdoubloon(void *param_0)
{
    *(float *)((char *)param_0 + 0x44) = 0.0f;
}

s32 func_8080000C_chdoubloon(s32 param_0){
    chdoubloon_entrypoint_1(param_0);
    func_80103110(param_0, 0);
}

void chdoubloon_entrypoint_0(Actor *param_0)
{
  func_80101870();
  if (param_0->unk7C_12) {
    func_80103110(param_0, 1);
  }
}

void chdoubloon_entrypoint_1(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_3;
    f32 local_1[2];
    f32 local_2[3];

    param_0->rotation[1] += func_800D8FF8() * 300.0f;
    if (param_0->unk7C_12) {
        func_800E3980(local_2);
        func_800F18FC(param_0->position, local_2, local_1);
        for (local_3 = 0; local_3 != 4; local_3++) {
            if (func_800DC0C0() < 0.015f) {
                func_800EEC30(local_0, local_1[0] + func_800DC178(-90.0f, 90.0f), local_1[1] + func_800DC178(-90.0f, 90.0f), 30.0f);
                func_800EF04C(local_0, param_0->position);
                local_0[1] += 30.0f;
                _fxtwinkle_entrypoint_1(local_0, 0x9E2);
            }
        }
    }
}

s32 func_808001D4_chdoubloon(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3E:
        _sudialog_entrypoint_0(0x165, 4);
        func_800D0BD4(*(s32 *)&param_0->unk54, 7);
        func_800D1844(0x4E);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800290_chdoubloon);
        _fxsparkle_entrypoint_1(param_0->position, 0x13);
        func_800FFAB0(param_0);
        return 1;
    case 0x13:
        *(s32 *)&param_0->unk54 = param_2;
        break;
    default: return 0;
    }
    return 1;
}

int *chdoubloon_entrypoint_2()
{
    return &D_808002A0_chdoubloon;
}
