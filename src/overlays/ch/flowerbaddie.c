#include "common.h"

#define PLANT_ACTOR_FLAGS_DEFINED
extern int D_80800C14_chflowerbaddie;
extern u8 D_80800CC0_chflowerbaddie[];
extern u8 D_80800BCC_chflowerbaddie[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _chexploder_entrypoint_6(s32, f32, f32);
extern void _chexploder_entrypoint_7(s32, f32, f32);
extern void _chexploder_entrypoint_8(s32, f32, f32);
typedef struct { u32 pad_0 : 29; u32 local_0 : 1; u32 pad_1 : 2; } Broad51FlowerFlags;
typedef struct { Actor **p; } FlowerArg;
extern u8 D_80800CCC_chflowerbaddie[];
extern u8 D_80800D18_chflowerbaddie[];
extern u8 D_80800CF0_chflowerbaddie[];
extern u8 D_80800D04_chflowerbaddie[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct { u8 pad_0[0x64]; u32 pad_64_30 : 2; u32 flag_64_29 : 1; u32 pad_64_0 : 29; } PlantActorFlags;
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 func_8010C9FC(void *, s32, s32, s32);
extern s32 func_8010C668(Actor *, void *, f32, f32);
extern void *_suchase_entrypoint_0(void);
extern s32 func_801072A8(Actor *);
extern u8 D_80800D28_chflowerbaddie;
extern f32 func_800D8FF8(void);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102B2C(Actor *, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern u8 D_80800C80_chflowerbaddie[];
extern u8 D_80800C5C_chflowerbaddie[];
extern u8 D_80800C68_chflowerbaddie[];
extern u8 D_80800C94_chflowerbaddie[];
extern u8 D_80800CA8_chflowerbaddie[];
extern void *func_80100094(Actor *, u32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
typedef struct { u8 pad_0[0x78]; u32 pad_1:29; u32 local_0:1; u32 pad_2:2; } FlowerDisabled241;
typedef struct { u8 pad_0[0x64]; u32 pad_1:2; u32 local_0:1; u32 pad_2:29; } FlowerJoy241;
void func_808006A0_chflowerbaddie();

int chflowerbaddie_entrypoint_0(void)
{
    return (int)&D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(u8 *param_0) {
    _subaddierouteDll_entrypoint_3(param_0, func_80100094(param_0, 0), param_0 + 4);
    (*(f32 *)((s8 *)(param_0) + (0x24))) = 600.0f;
    (*(u8 *)((s8 *)(param_0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x65))) & 0xFFEF);
}





































s32 func_808009F0_chflowerbaddie(Actor *param_0, u8 *param_1, f32 param_2);

s32 func_808007F0_chflowerbaddie();

void func_8080005C_chflowerbaddie(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (!((FlowerDisabled241 *)param_0)->local_0) {
        func_8010D254((f32 *)param_0->actorData);
        func_800D9078(&param_0->unk58);
        switch (param_0->unk70_10) {
        case 1:
            if (func_808007F0_chflowerbaddie(param_0)) {
                func_80102424(param_0, 2);
            }
            break;
        case 2:
            if (func_80101F24(param_0) > 0.1f) {
                param_0->unk64_20 = 1;
            } else {
                param_0->unk64_20 = 0;
            }
            func_80800980_chflowerbaddie(param_0, D_80800C80_chflowerbaddie);
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800C5C_chflowerbaddie, 0.15f);
            if (func_80101F24(param_0) > 0.5f) {
                if (!func_808009F0_chflowerbaddie(param_0, local_0,
                        func_800F3780(func_80101F24(param_0), D_80800C68_chflowerbaddie, 3))) {
                    return;
                }
            } else {
                if (((FlowerJoy241 *)param_0)->local_0) {
                    _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
                } else {
                    param_0->unk54 = func_80102D78(param_0, (f32 *)param_0->actorData);
                }
                func_80102B2C(param_0, func_800D8FF8() * 120.0f);
            }
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 3);
            }
            break;
        case 3:
            func_80800980_chflowerbaddie(param_0, D_80800C94_chflowerbaddie);
            if (!(param_0->unk58 > 0.0f)) {
                func_808009F0_chflowerbaddie(param_0, local_0,
                    func_800F3780(func_80101F24(param_0), D_80800CA8_chflowerbaddie, 3));
            }
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800C5C_chflowerbaddie, 0.08f);
            if (func_80101F24(param_0) > 0.7f) {
                param_0->unk64_20 = 0;
            } else {
                param_0->unk64_20 = 1;
            }
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 1);
            }
            break;
        case 5:
            if (func_80101DDC(param_0)) {
                if (!func_808007F0_chflowerbaddie(param_0)) {
                    local_1 = param_0->unk64_20 ? 4 : 1;
                    func_80102424(param_0, local_1);
                } else {
                    local_1 = param_0->unk64_20 ? 3 : 2;
                    func_80102424(param_0, local_1);
                }
            }
            break;
        }
    }
}

s32 func_80800380_chflowerbaddie(Actor *param_0, s32 param_1, FlowerArg param_2)
{
    s16 *local_4;
    s16 local_0[18];
    s32 local_2;
    s32 local_3;
    f32 local_1[3];
    switch (param_1) {
    case 0x3E:
        param_0->unk58 = 1.0f;
        break;
    case 0x3F:
        if (param_0->unk70_10 != 5 && !((Broad51FlowerFlags *)((u8 *)param_0 + 0x78))->local_0) {
            _subaddieaudioloop_entrypoint_2(param_0);
            func_80102424(param_0, 5);
            param_0->unk58 = 1.0f;
        }
        break;
    case 0x40:
        _chexploder_entrypoint_4(param_0, param_2.p[0]->position, 4);
        _subaddieaudioloop_entrypoint_2(param_0);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800CC0_chflowerbaddie);
        break;
    case 0x90:
        local_2 = func_80106790(func_80101080());
        for (local_3 = 0x44; (local_3 ^ 0) < 0x53; local_3++) {
            local_0[local_3 - 0x44] = local_3;
            if (param_2.p) {}
        }
        local_0[local_3++ - 0x44] = 0x5B;
        local_0[local_3++ - 0x44] = 0x5C;
        local_0[local_3 - 0x44] = -1;
        _chexploder_entrypoint_9(local_2, 2, 0);
        _chexploder_entrypoint_9(local_2, 3, 0);
        _chexploder_entrypoint_9(local_2, 4, 1);
        _chexploder_entrypoint_9(local_2, 5, 2);
        _chexploder_entrypoint_9(local_2, 6, 1);
        _chexploder_entrypoint_10(local_2, local_0);
        _chexploder_entrypoint_6(local_2, 600.0f, 800.0f);
        _chexploder_entrypoint_7(local_2, -800.0f, -600.0f);
        _chexploder_entrypoint_8(local_2, 80.0f, 160.0f);
        func_808006A0_chflowerbaddie(param_0);
        if (!func_80107070(param_0, 3)) {
            func_800FFAB0(param_0);
        }
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(param_0);
        break;
    case 0x38:
        func_80101074(D_80800BCC_chflowerbaddie);
        return 6;
    case 0x97:
        func_800EFA4C(local_1, 0.0f, 300.0f, 0.0f);
        func_80101010(local_1);
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(param_0)) {
            func_80107070(param_0, 1);
            param_0->unk64_20 = 0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800610_chflowerbaddie(Actor *param_0, s32 param_1)
{
    func_800DF744(3, param_0->unk64_20 ? 1 : 0);
    func_800DF744(4, param_0->unk64_20 ? 2 : 1);
    func_800DF744(5, 1);
    func_800DF744(6, 0);
    func_80101870(param_0, param_1);
}

void func_808006A0_chflowerbaddie(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    func_80103DFC(param_0, local_0);
    local_1 = func_800B53A4(1);
    func_800BABB8(local_1, local_0, local_0, param_0->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(local_1, local_0, local_0, param_0->scale, D_80800D18_chflowerbaddie);
    func_800BA22C(local_1, 1);
    local_1 = func_800B53A4(2);
    func_800BABB8(local_1, local_0, local_0, param_0->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(local_1, local_0, local_0, param_0->scale, D_80800CF0_chflowerbaddie);
    func_800BA22C(local_1, 2);
    local_1 = func_800B53A4(4);
    func_800BABB8(local_1, local_0, local_0, param_0->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(local_1, local_0, local_0, param_0->scale, D_80800D04_chflowerbaddie);
    func_800BA22C(local_1, 4);
    param_0->unk64_20 = 0;
}

s32 func_808007F0_chflowerbaddie(Actor *param_0)
{
    if (param_0->unk58 > 0.0f) {
        return 0;
    }
    if (((PlantActorFlags *)param_0)->flag_64_29) {
        return 1;
    }
    if (func_801072A8(param_0)) {
        return 0;
    }
    if (!_subaddierouteDll_entrypoint_4(param_0)) {
        return 0;
    }
    if (!func_8010C9FC(param_0->position, 1000, 500, -50)) {
        return 0;
    }
    if (!func_8010C668(param_0, param_0->position, 1000.0f, -200.0f)) {
        return 0;
    }
    return _suchase_entrypoint_0() == param_0->unk0;
}

s32 func_808008D4_chflowerbaddie(Actor *param_0)
{
    if (((PlantActorFlags *)param_0)->flag_64_29) {
        return 0;
    }
    if (!_subaddierouteDll_entrypoint_4(param_0)) {
        return 0;
    }
    if (!func_8010C9FC(param_0->position, 1000, 500, -50)) {
        return 1;
    }
    if (!func_8010C668(param_0, param_0->position, 1000.0f, -200.0f)) {
        return 1;
    }
    return _suchase_entrypoint_0() != param_0->unk0;
}

int func_80800980_chflowerbaddie(Actor *param_0)
{
  if (func_80101E4C(param_0))
  {
    if (param_0->unk5F == 0)
    {
      param_0->unk5F = _subaddieaudioquick_entrypoint_1(param_0, &param_0->position);
      func_800C4350(param_0->unk5F, &param_0->position, &D_80800D28_chflowerbaddie);
    }
    func_800C3BDC(param_0->unk5F);
  }
}

s32 func_808009F0_chflowerbaddie(Actor *param_0, u8 *param_1, f32 param_2)
{
    f32 local_0 = func_800D8FF8();
    f32 local_1;

    if ((*(u32 *)((u8 *)param_0 + 0x64) << 2) >> 31) {
        local_1 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
        func_80102B2C(param_0, local_0 * 120.0f);
        func_8010C3A8(param_0, 0x205025, local_1 * param_2);
    } else {
        if (_subaddierouteDll_entrypoint_4(param_0)) {
            param_0->unk54 = func_80102D78(param_0, (f32 *)param_0->actorData);
            _subaddierouteDll_entrypoint_7(param_0, param_1, param_0->rotation[1], param_0->unk54, 350.0f, 0x5000);
            *(s32 *)(param_1 + 12) = *(u16 *)(param_1 + 6);
        }
        func_80102B2C(param_0, local_0 * 120.0f);
        func_8010C3A8(param_0, 0x5325, param_2);
    }
    if (func_808008D4_chflowerbaddie(param_0)) {
        _subaddieaudioloop_entrypoint_2(param_0);
        func_80102424(param_0, 4);
        return 0;
    }
    return 1;
}
