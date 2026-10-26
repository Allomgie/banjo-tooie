#include "common.h"

extern int D_80800240_chfantasytrashcanbits;
extern int D_80800288_chfantasytrashcanbits;
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern f32 func_800EFC7C(f32 *, f32 *);

void func_80800000_chfantasytrashcanbits(Actor *param_0)
{
    if (func_800EA090(param_0) == 0x11) {
        func_80101FDC(param_0, 4);
    } else {
        func_80101FDC(param_0, 1);
    }
    _chdoormake_entrypoint_3(param_0, param_0->rotation[1], 90.0f, param_0->scale * 325.0f, 0x80A, 0);
    _chdoormake_entrypoint_8(param_0, 2);
    _chdoormake_entrypoint_5(param_0, 2.0f);
    _chdoormake_entrypoint_9(param_0, 0, 7, 16);
    if (!func_800F64A4(func_800F54E4(), 0x400) && param_0->unk70_10 == 4) {
        func_8010108C(param_0, 8, 0);
    }
}

void func_808000EC_chfantasytrashcanbits(Actor *param_0)
{
    f32 local_0[3];

    switch (param_0->unk70_10) {
    case 4:
        func_800F5A00(func_800F54E4(), local_0);
        _subaddieDll_entrypoint_4(param_0, 1);
        if (func_800EFC7C(param_0->position, local_0) > 4000000.0f) {
            func_8010108C(param_0, 8, 0);
        }
        break;
    case 1:
        _subaddieDll_entrypoint_4(param_0, 0);
        break;
    }
    _chdoor_entrypoint_0(param_0);
}

int chfantasytrashcanbits_entrypoint_0()
{
    return (int)&D_80800240_chfantasytrashcanbits;
}

s32 func_808001A8_chfantasytrashcanbits(Actor *this){
    _chswitch_entrypoint_7(this, 0x9FF);
    _chswitch_entrypoint_8(this, 0x400);
}

s32 func_808001D8_chfantasytrashcanbits(s32 param_0, s32 param_1, s32 param_2) {
    if (param_1 == 7) {
        func_80101180(0x40C);
    }
    _chswitch_entrypoint_10(param_0, param_1, param_2);
}

int chfantasytrashcanbits_entrypoint_1()
{
    return (int)&D_80800288_chfantasytrashcanbits;
}
