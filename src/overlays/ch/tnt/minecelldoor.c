#include "common.h"

extern int D_80800140_chtntminecelldoor;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
void func_808000F4_chtntminecelldoor();

void *chtntminecelldoor_entrypoint_0()
{
    return &D_80800140_chtntminecelldoor;
}

void func_8080000C_chtntminecelldoor(s32 arg0)
{
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg0);
}
s32 func_80800034_chtntminecelldoor(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
    case 5:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], 100.0f);
        local_0[1] += 25.0f;
        _chexploder_entrypoint_3(param_0, local_0, 40);
        break;
    case 0x90:
        func_808000F4_chtntminecelldoor(param_0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(param_0, 0x85);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808000F4_chtntminecelldoor(param_0) s32 param_0;
{
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp1C = temp_v0;
    _chexploder_entrypoint_13(temp_v0, 1);
    _chexploder_entrypoint_12(sp1C, 0x3C);
    func_800DA544(0x85);
}
