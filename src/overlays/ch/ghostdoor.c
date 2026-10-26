#include "ch/ghostdoor.h"

extern int D_80800220_chghostdoor;
extern int D_80800268_chghostdoor;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);

int *chghostdoor_entrypoint_0()
{
    return &D_80800220_chghostdoor;
}

int chghostdoor_entrypoint_1()
{
  return (int)&D_80800268_chghostdoor;
}

void func_80800018_chghostdoor(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    local_0 = param_0->rotation[1];
    local_1 = 0;
    if (((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7) == 50) {
        local_1 = 1;
        local_0 += 180.0f;
    }
    func_800EFD24(param_0->position);
    func_80103014(param_0);
    if (_chdoormake_entrypoint_3(param_0, local_0, 0.0f, 650.0f, 0x20, 0x96)) {
        _chdoormake_entrypoint_5(param_0, 3.5f);
        _chdoormake_entrypoint_6(param_0, 2.0f);
        if (local_1) _chdoormake_entrypoint_8(param_0, 15);
    }
    if (func_800DA298(0x96)) func_800FFAB0(param_0);
}

s32 func_808000F4_chghostdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x95:
        local_0 = param_0->unk74_7 == 0x32 ? 0x782 : 0x783;
        func_80103140(param_0, local_0, *(u16 *)((u8 *)param_0->unk0 + 0x16));
        break;
    case 0x9D:
        func_800FFAB0(param_0);
        return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

void func_80800190_chghostdoor(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_096_STATION_UNLOCKED_WW);
    _chswitch_entrypoint_9(arg0);
}

s32 func_808001BC_chghostdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 7:
        _capod_entrypoint_13(param_0->unk0, NULL, 5, 0x10);
        func_80101180(0x344, 7, 0);
        break;
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}
