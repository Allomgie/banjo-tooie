#include "common.h"

extern int D_80800140_chfactoryliftdoor;
extern int D_80800188_chfactoryliftdoor;
extern int _chdoormake_entrypoint_3(u8 *, f32, s32, s32, s32, s32);
typedef struct { s16 a, b; } S16Pair;

int chfactoryliftdoor_entrypoint_0()
{
    return &D_80800140_chfactoryliftdoor;
}

int chfactoryliftdoor_entrypoint_1()
{
    return (int)&D_80800188_chfactoryliftdoor;
}

void func_80800018_chfactoryliftdoor(u8 *param_0) {
    u32 local_0;
    u32 local_1;
    s32 local_2;

    local_0 = *(u16 *)((u8 *)param_0 + 0x76);
    local_1 = local_0 >> 7;
    local_0 = local_1 + 0xC;
    local_2 = 1;

    if (_chdoormake_entrypoint_3(param_0, 0, 0x42B40000, 0x43960000, local_2, local_0) != 0) {
        _chdoormake_entrypoint_5(param_0, 0x3FC00000);
        _chdoormake_entrypoint_8(param_0, 4);
    }
    func_8010A800(param_0, 0);
}

void func_8080008C_chfactoryliftdoor(Actor *param_0)
{
    s32 local_0;

    local_0 = param_0->unk74_7 + 0xC;
    _chswitch_entrypoint_14(param_0, local_0);
    func_80109EEC(param_0, 0x40);
    func_80105010(param_0);
    if (func_800DA298(local_0)) {
        func_8010A570(param_0);
    }
}

s32 func_808000F0_chfactoryliftdoor(Actor *param_0, s32 param_1, S16Pair param_2) {
    if (param_1 == 7) {
        func_80101180(0x3B8, param_1, 0);
        func_8010A570(param_0);
    } else {
        return 0;
    }
    return 1;
}
