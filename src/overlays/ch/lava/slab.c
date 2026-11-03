#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void *D_808000A0_chlavaslab;

void func_80800000_chlavaslab(Actor *param_0)
{
    if (_chdoormake_entrypoint_3(param_0, param_0->rotation[1] + 90.0f, 0.0f,
                                 param_0->scale * 430.0f, 0, 0x38F)) {
        if (param_0->unk74_7 == 0x33)
            _chdoormake_entrypoint_6(param_0, 6.0f);
        _chdoormake_entrypoint_8(param_0, 10);
    }
}

int chlavaslab_entrypoint_0()
{
    return &D_808000A0_chlavaslab;
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
void *D_808000A0_chlavaslab = (void *) 0x032C0250;
static u32 D_808000A0_chlavaslab_rest[19] = {0x8D40001,
                                             0x0,
                                             (u32) _chdoor_entrypoint_0,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x800,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800000_chlavaslab,
                                             (u32) func_80107C2C,
                                             0x80002C02,
                                             (u32) _chdoor_entrypoint_1,
                                             0x0,
                                             0x0,
                                             0x0};
