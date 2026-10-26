#include "common.h"

extern int D_80800240_chtntblockage;
extern f32 func_800D8FF8(void);
extern u8 D_80800288_chtntblockage[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 local_1;
extern u8 D_8080029C_chtntblockage[];
extern u8 marker[];
extern u8 ActorMarker[];
int func_80800184_chtntblockage();

void *chtntblockage_entrypoint_0()
{
    return &D_80800240_chtntblockage;
}

void func_8080000C_chtntblockage(Actor *param_0)
{
    if (param_0->unk70_10 == 2) {
        param_0->unk58 += func_800D8FF8();
        if (param_0->unk58 > 0.5f) {
            func_800C4AF0(param_0->position, D_80800288_chtntblockage, param_0);
            func_800FFAB0(param_0);
        }
    }
}

void func_80800088_chtntblockage()
{
    _subaddiefade_entrypoint_14();
}

s32 func_808000A8_chtntblockage(u8 *param_0)
{
  return ((u32)*(u16 *)(param_0 + 0x76) >> 7) + 0x4C;
}

s32 func_808000B8_chtntblockage(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 5:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], -300.0f);
        local_0[1] -= 110.0f;
        _chexploder_entrypoint_3(param_0, local_0, 0);
        break;
    case 0x90:
        func_80800184_chtntblockage(param_0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(param_0, func_808000A8_chtntblockage(param_0));
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800184_chtntblockage(param_0) Actor *param_0;
{
    s32 local_0;
    u8 *local_1;
    local_0 = func_80106790(func_80101080());
    _chexploder_entrypoint_12(local_0, 0x32);
    _chexploder_entrypoint_6(local_0, 0x44960000, 0x44AF0000);
    _chexploder_entrypoint_13(local_0, 4);
    _chexploder_entrypoint_15(local_0, 1, 0x3F99999A);
    local_1 = &D_8080029C_chtntblockage;
    func_800BABB8(0, (u8*)param_0 + 4, local_0 + 0x18, *(s32*)((char*)param_0 + 0x38), local_1);
    func_800DA544(func_808000A8_chtntblockage(param_0));
    func_80101FDC(param_0, 2);
    func_80103110(param_0, 1);
}
