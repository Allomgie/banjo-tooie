#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);
extern int D_808001D0_chdinotraindoor;

void func_80800000_chdinotraindoor(Actor *param_0)
{
    f32 local_0 = param_0->rotation[1];
    if (param_0->unk74_7 == 50) local_0 += 180.0f;
    func_800EFD24(param_0->position);
    func_80103014(param_0);
    if (_chdoormake_entrypoint_3(param_0, local_0, 0.0f, param_0->scale * 600.0f, 0x20, 0x164)) {
        _chdoormake_entrypoint_5(param_0, 3.5f);
        _chdoormake_entrypoint_6(param_0, 4.0f);
        _chdoormake_entrypoint_12(param_0, 0, 0x3C);
        if (param_0->unk74_7 == 50) {
            _chdoormake_entrypoint_8(param_0, 5);
            _chdoormake_entrypoint_9(param_0, 0, 10, 0x910);
        }
    }
    if (func_800DA298(0x164) && !_glcutDll_entrypoint_19(0x3C)) func_800FFAB0(param_0);
}

s32 func_80800120_chdinotraindoor(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        func_80103140(param_0, param_0->unk74_7 == 0x32 ? 0x949 : 0x94A, 0);
        break;
    case 0x9D:
        func_800FFAB0(param_0);
        break;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

int *chdinotraindoor_entrypoint_0()
{
    return &D_808001D0_chdinotraindoor;
}
