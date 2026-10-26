#include "ch/factory/entrydoors.h"

extern void _chdoormake_entrypoint_0(Actor *, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void func_80103140();
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);
extern int D_808002B0_chfactoryentrydoors;
extern u8 D_808002F8_chfactoryentrydoors[];
extern u8 D_80800390_chfactoryentrydoors[];
extern int D_808003A0_chfactoryentrydoors;

void func_80800000_chfactoryentrydoors(Actor *param_0)
{
    f32 local_1;
    s32 local_0;

    if (_sujiggy_entrypoint_20(5)) func_800DA544(0x397);
    if (func_800D3E40(11) && !_glcutDll_entrypoint_19(0x7F)) {
        local_0 = -1;
        func_80101FDC(param_0, 4);
    } else local_0 = 0x397;
    if (param_0->unk74_7 == 0x33) local_1 = -75.0f;
    else local_1 = 75.0f;
    _chdoormake_entrypoint_0(param_0, local_1, 0, local_0);
    _chdoormake_entrypoint_8(param_0, 1);
    _chdoormake_entrypoint_5(param_0, 0.0f);
}

s32 func_808000CC_chfactoryentrydoors(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (param_1 == 0x95) {
        local_0 = param_0->unk74_7 == 0x33 ? 0x971 : 0x972;
        func_80103140(param_0, (u16)local_0, *(u16 *)((u8 *)param_0->unk0 + 0x16));
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

int chfactoryentrydoors_entrypoint_0()
{
  return (int)&D_808002B0_chfactoryentrydoors;
}

void func_8080014C_chfactoryentrydoors(s32 param_0) {
    if (((func_800DA298(0x397) != 0) || (func_800D3E40(0xB) != 0)) && (_glcutDll_entrypoint_19(0x7F) == 0)) {
        func_800FFAB0(param_0);
    }
}

int func_808001A0_chfactoryentrydoors(Actor *param_0)
{
    if (func_800D90A4((char *)param_0 + 0x58) != 0) {
        func_80101180(0x48B, 7, (s32)*(f32*)((char*)param_0 + 0x34));
        func_800FFAB0(param_0);
    }
}

s32 func_808001F0_chfactoryentrydoors(u8 *param_0, s32 param_1, s32 param_2) {
    if (param_1 == 7) {
        func_800BABB8(0, param_0 + 4, param_0 + 4, (*(s32 *)((u8 *)(param_0) + 0x38)), &D_808002F8_chfactoryentrydoors);
        func_800C4AF0(param_0 + 4, &D_80800390_chfactoryentrydoors);
        (*(u8 *)((u8 *)(param_0) + 0x65)) = (u8)((*(u8 *)((u8 *)(param_0) + 0x65)) & 0xFFFE);
        (*(f32 *)((u8 *)(param_0) + 0x58)) = 2.0f;
        func_80103110(param_0, 1);
        (*(f32 *)((u8 *)(param_0) + 0x34)) = (f32)param_2;
        return 1;
    }
    return 0;
}

int *chfactoryentrydoors_entrypoint_1()
{
    return &D_808003A0_chfactoryentrydoors;
}
