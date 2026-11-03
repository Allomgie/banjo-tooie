#include "common.h"

extern int D_80800E28_chnutsnbolts[];
extern int D_80800E70_chnutsnbolts[];
extern int D_80800EB8_chnutsnbolts[];
extern void _subaddierouteDll_entrypoint_3();
typedef struct {
    u8 pad_0[0x64];
    u32 local_0 : 1;
    u32 pad_1 : 1;
    u32 local_1 : 1;
    u32 pad_2 : 4;
    u32 local_2 : 1;
    u32 pad_3 : 24;
    u8 pad_4[8];
    u32 pad_5 : 15;
    u32 local_3 : 1;
    u32 pad_6 : 16;
    u8 pad_7[4];
    u32 pad_8 : 29;
    u32 local_4 : 1;
    u32 pad_9 : 2;
} NutsFlags1226;
typedef union {
    f32 local_0[3];
    s32 local_1[3];
} NutsPosition1226;
extern u8 D_80800E04_chnutsnbolts[];
extern u8 D_80800E10_chnutsnbolts[];
extern void _chbaddiesetup_entrypoint_10();
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
extern void *func_80100094(Actor *, u32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
extern s32 D_80800CC0_chnutsnbolts[];
extern s32 D_80800F3C_chnutsnbolts[];
extern s32 D_80800F2C_chnutsnbolts[];
extern s32 D_80800F48_chnutsnbolts[];
extern s32 D_80800F58_chnutsnbolts[];
extern void _subaddieaudioquick_entrypoint_4(u8 *, u8 *, void *, void *);
typedef struct {
    u8 pad0[8];
    u8 unk8[6];
    u16 unkE;
    u8 pad10[4];
    s16 unk14;
    u8 unk16;
    u8 pad17;
    f32 unk18;
    f32 unk1C;
} NutsData;
typedef struct {
    u8 pad0[0x64];
    u32 pad64_30 : 2;
    u32 unk64_29 : 1;
    u32 pad64_0 : 29;
    u8 pad68[0x10];
    u32 pad78_3 : 29;
    u32 unk78_2 : 1;
    u32 pad78_0 : 2;
} NutsBits;
extern f32 D_80800F00_chnutsnbolts[];
extern f32 D_80800F14_chnutsnbolts[];
extern void func_8010D254(f32 *);
extern s32 func_801072A8(Actor *);
extern s32 func_801072E4(Actor *);
extern void func_8010D690(Actor *);
extern s32 func_800D90A4(f32 *);
extern f32 func_800D8FF8(void);
extern s32 func_8010B990(Actor *, s32);
extern s32 func_800BFA1C(f32 *);
extern void func_800FFAB0(Actor *);
extern void func_8010AA54(f32 *);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern s32 func_80101DDC(Actor *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, f32 *, s32);
extern void func_8010C3A8(Actor *, s32, f32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern f32 func_80102D78(Actor *, f32 *);
extern void _subaddierouteDll_entrypoint_7(Actor *, u8 *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, u8 *, s32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 func_800DC298(f32);
extern s32 func_8010C9B0(f32 *, s32);
extern s32 func_8010C500(Actor *);
extern s32 func_800F54E4(void);
extern s32 func_800F6478(s32);
extern void _subaddiefx_entrypoint_0(Actor *, s32, NutsData *);
extern s32 func_800D9078(f32 *);
extern void _subaddiefx_entrypoint_1(Actor *, NutsData *);
typedef struct {
    u8 pad_0[0x64];
    u32 local_7 : 1;
    u32 pad_1 : 6;
    u32 local_8 : 1;
    u32 pad_2 : 24;
    u8 pad_3[8];
    u32 local_0 : 7;
    u32 local_1 : 7;
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 local_4 : 6;
    u32 local_5 : 6;
    u32 local_6 : 4;
} NutsFlags37;
typedef struct NutsAndBoltsFlags {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} NutsAndBoltsFlags;
void func_8080092C_chnutsnbolts();
s32 func_80800A88_chnutsnbolts();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_80800024_chnutsnbolts(), func_80800080_chnutsnbolts();

int chnutsnbolts_entrypoint_0()
{
    return (int) &D_80800E28_chnutsnbolts;
}

int *chnutsnbolts_entrypoint_1()
{
    return &D_80800E70_chnutsnbolts;
}

int *chnutsnbolts_entrypoint_2()
{
    return &D_80800EB8_chnutsnbolts;
}

void func_80800024_chnutsnbolts(param_0) u8 *param_0;
{
    u8 *local_0 = func_80100094(param_0, 0);
    _subaddierouteDll_entrypoint_3(param_0, local_0 + 8, param_0 + 4);
    func_8080092C_chnutsnbolts(param_0, 2);
    *(f32 *) (local_0 + 0x1C) = 0.0f;
    *(f32 *) (param_0 + 0x24) = 0.0f;
}

void func_80800C04_chnutsnbolts();

void func_80800080_chnutsnbolts(param_0) Actor *param_0;
{
    NutsData *local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4;

    local_0 = func_80100094(param_0, 0);

if (((NutsBits *) param_0)->unk78_2) {
    return;
}

func_8010D254((f32 *) param_0->actorData);

if (!func_801072A8(param_0) || func_801072E4(param_0)) {
    func_8010D690(param_0);
}

local_1 = func_800D90A4(&param_0->unk58);

switch (param_0->unk70_10) {
    case 1:
        ((f32 *) param_0->actorData)[5] -= func_800D8FF8() * 1000.0f;
        local_2 = func_8010B990(param_0, 0x400027);
        if (!func_800BFA1C(param_0->position)) {
            func_800FFAB0(param_0);
            return;
        }
        if (local_2 & 0x20) {
            func_8010AA54(local_3);
            func_800EFDE8((f32 *) &param_0->actorData[4], (f32 *) &param_0->actorData[4], local_3);
            ((f32 *) param_0->actorData)[4] *= 0.8f;
            ((f32 *) param_0->actorData)[5] *= 0.4f;
            ((f32 *) param_0->actorData)[6] *= 0.8f;
            if (func_800EEFFC((f32 *) &param_0->actorData[4]) < 50.0f) {
                func_8010B990(param_0, 0x1000);
                func_8080092C_chnutsnbolts(param_0, 3);
                return;
            }
            if (local_1) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_80800F00_chnutsnbolts);
                param_0->unk58 = 0.6f;
            }
        }
        break;
    case 2:
        func_80800A88_chnutsnbolts(param_0, 0, 3);
        break;
    case 3:
        func_80800B80_chnutsnbolts(param_0);
        if (func_80101DDC(param_0)) {
            func_8080092C_chnutsnbolts(param_0, 4);
        }
        break;
    case 4:
        if (((NutsBits *) param_0)->unk64_29) {
            local_4 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
            ((f32 *) param_0->actorData)[3] = local_0->unk1C;
            func_80102BF8(param_0, 0.2f, 8.0f, 500.0f);
            func_8010C3A8(param_0, 0x205025,
                          func_800F3780(func_80101F24(param_0), D_80800F14_chnutsnbolts, 3) *
                              local_4);
        } else {
            if (!local_0->unk16) {
                if (_subaddierouteDll_entrypoint_4(param_0)) {
                    param_0->unk54 = func_80102D78(param_0, (f32 *) param_0->actorData);
                    _subaddierouteDll_entrypoint_7(param_0, local_0->unk8, param_0->rotation[1],
                                                   param_0->unk54, 200.0f, 0x5800);
                    local_0->unk14 = local_0->unkE;
                }
                _subaddierouteDll_entrypoint_5(param_0, local_0->unk8, local_0->unk14, 0.15f, 8.0f,
                                               200.0f);
            } else {
                param_0->unk54 = func_80102D78(param_0, (f32 *) param_0->actorData);
                func_80102BF8(param_0, 0.15f, 8.0f, 2e+02f);
            }
            ((f32 *) param_0->actorData)[3] = func_800F15F8(
                ((f32 *) param_0->actorData)[3], local_0->unk1C, func_800D8FF8() * 400.0f);
            func_8010C3A8(param_0, 0x305425,
                          func_800F3780(func_80101F24(param_0), D_80800F14_chnutsnbolts, 3));
            if (!local_0->unk16) {
                if (_subaddierouteDll_entrypoint_4(param_0) && func_800DC298(0.2f) &&
                    (!func_8010C9B0(param_0->position, 1500) || !func_8010C500(param_0))) {
                    func_8080092C_chnutsnbolts(param_0, 6);
                }
            } else if (!func_800F6478(func_800F54E4())) {
                func_8080092C_chnutsnbolts(param_0, 5);
            }
        }
        func_80800BD4_chnutsnbolts(param_0);
        break;
    case 5:
        func_80800BD4_chnutsnbolts(param_0);
        if (func_800F6478(func_800F54E4()) && !func_80800A88_chnutsnbolts(param_0, 1, 4)) {
            func_8080092C_chnutsnbolts(param_0, 6);
        }
        break;
    case 6:
        func_80800C04_chnutsnbolts(param_0);
        if (func_80101DDC(param_0)) {
            func_8080092C_chnutsnbolts(param_0, 2);
            param_0->unk58 = func_800DC178(1.5f, 2.0f);
        }
        break;
    case 7:
        if (!local_0->unk16) {
            _subaddiefx_entrypoint_0(param_0, 4, local_0);
        }
        if (func_800D9078(&local_0->unk18)) {
            _subaddiefx_entrypoint_1(param_0, local_0);
            if (!func_80800A88_chnutsnbolts(param_0, 1, 4)) {
                func_8080092C_chnutsnbolts(param_0, 6);
            }
        }
        break;
    case 8:
        if (!local_0->unk16) {
            _subaddiefx_entrypoint_0(param_0, 4, local_0);
        }
}

}

s32 func_808005D0_chnutsnbolts(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    NutsPosition1226 local_5;
    s32 local_2;
    Actor *local_3;
    s32 local_4;
    s32 local_1;
    f32 local_6[3];
    s32 local_7;

    local_0 = func_80100094(param_0, 0);

switch (param_1) {
    case 0x3E:
        if (!((NutsFlags1226 *) param_0)->local_1 && param_0->unk70_10 == 4)
            func_8080092C_chnutsnbolts(param_0, 5);
        break;
    case 0x3F:
        if (((NutsFlags1226 *) param_0)->local_4)
            return 0;
        if (param_0->unk70_10 != 7)
            func_8080092C_chnutsnbolts(param_0, 7);
        break;
    case 0x40:
        func_80103DFC(param_0, local_5.local_0);
        if (local_0[0x16] == 0) {
            if (func_8010A430(param_0)) {
                _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, local_5.local_1[0],
                                            local_5.local_1[1], local_5.local_1[2],
                                            *(s32 *) ((u8 *) param_0 + 0x48));
            }
        } else {
            local_4 = 1;
            for (local_1 = 0x43E; local_1 < 0x441; local_1++) {
                local_3 = _subaddiefind_entrypoint_2(local_1, &local_2);
                while (local_3 != 0) {
                    if (local_3 != param_0 && (s32) local_3->unk70_10 < 8) {
                        local_4 = 0;
                        goto local_7;
                    }
                    local_3 = _subaddiefind_entrypoint_3(local_1, &local_2);
                }
            }
        local_7:
            if (local_4) {
                _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, local_5.local_1[0],
                                            local_5.local_1[1], local_5.local_1[2],
                                            *(s32 *) ((u8 *) param_0 + 0x48));
            }
        }
        func_8080092C_chnutsnbolts(param_0, 8);
        return 1;
    case 2:
        if (!_subaddieDll_entrypoint_3(param_0) && !func_80107070(param_0, 1)) {
            func_8080092C_chnutsnbolts(param_0, 10);
            _subaddiefade_entrypoint_3(param_0);
            ((NutsFlags1226 *) param_0)->local_3 = 0;
            ((NutsFlags1226 *) param_0)->local_2 = ((NutsFlags1226 *) param_0)->local_0 =
                (s32) ((NutsFlags1226 *) param_0)->local_3;
        }
        break;
    case 0x8E:
        func_80101038(local_6);
        func_800EFB24(&param_0->actorData[4], local_6, param_0->position);
        func_800EF368(&param_0->actorData[4], func_800DC178(1800.0f, 2000.0f));
        func_8080092C_chnutsnbolts(param_0, 1);
        _subaddieDll_entrypoint_4(param_0, 1);
        local_0[0x16] = 1;
        param_0->unk58 = 0.0f;
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(param_0);
        return 1;
    case 0x38:
        if (((*(u32 *) ((u8 *) param_0 + 0x6C) << 11) >> 20) == 0x440) {
            func_80101074(D_80800E10_chnutsnbolts);
            return 2;
        }
        func_80101074(D_80800E04_chnutsnbolts);
        return 1;
    default:
        return 0;
}

return 1;
}

s32 func_808008FC_chnutsnbolts(enum asset_e param_0)
{
    s32 local_0 = func_80100094(param_0, 0);
    _subaddiefx_entrypoint_1(param_0, local_0);
}

void func_8080092C_chnutsnbolts(param_0, param_1) Actor *param_0;
s32 param_1;
{
    u8 *local_0 = func_80100094(param_0, 0);

    func_80102424(param_0, param_1);

switch (param_1) {
    case 1:
        ((NutsFlags37 *) param_0)->local_8 = 0;
        break;
    case 2:
        ((NutsFlags37 *) param_0)->local_8 = 1;
        break;
    case 4:
        *(f32 *) (local_0 + 0x1C) = func_800DC178(700.0f, 800.0f);
        *(f32 *) &param_0->actorData[3] = 0.0f;
        break;
    case 7:
        *(f32 *) (local_0 + 0x18) = func_800DC178(3.0f, 4.0f);
        break;
    case 8:
        ((NutsFlags37 *) param_0)->local_0 = ((NutsFlags37 *) param_0)->local_5 = 0;
        ((NutsFlags37 *) param_0)->local_3 = 0;
        ((NutsFlags37 *) param_0)->local_8 = ((NutsFlags37 *) param_0)->local_7 =
            (s32) ((NutsFlags37 *) param_0)->local_3;
        if (!func_80107070(param_0, 2)) {
            func_8010A570(param_0);
            _subaddiefade_entrypoint_3(param_0);
        }
}

}

s32 func_80800A88_chnutsnbolts(param_0, param_1, param_2)
Actor *param_0;
s32 param_1;
f32 *param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);

if (((NutsAndBoltsFlags *) param_0)->local_0) {
    func_8080092C_chnutsnbolts(param_0, param_2);
    return 1;
}

if (param_0->unk58 > 0.0f) {
    return 0;
}

if (local_0[0x16]) {
    func_8080092C_chnutsnbolts(param_0, param_2);
    return 1;
}

if ((param_1 || (_subaddierouteDll_entrypoint_4(param_0) && func_800DC298(0.2f))) &&
    func_8010C9B0(param_0->position, 1500) && func_8010C500(param_0)) {
    func_8080092C_chnutsnbolts(param_0, param_2);
    return 1;
}

return 0;
}

int func_80800B80_chnutsnbolts(f32 param_0[3])
{
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 1, &D_80800CC0_chnutsnbolts,
                                     &D_80800F3C_chnutsnbolts);
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 1, &D_80800F2C_chnutsnbolts, 0x3E4CCCCD);
}

int func_80800BD4_chnutsnbolts(s32 param_0)
{
    s32 local_0;
    int new_var;
    local_0 = param_0 + 4;
    new_var = 0x3F266666;
    _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800CC0_chnutsnbolts, new_var);
}

void func_80800C04_chnutsnbolts(u8 *param_0)
{
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80800F48_chnutsnbolts, 0x3F333333);
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_80800CC0_chnutsnbolts,
                                     &D_80800F58_chnutsnbolts);
}

s32 D_80800CC0_chnutsnbolts[4] = {0x13045A, 0xD0140, 0x1590016, 0x36B00000};
u8 D_80800CD0_chnutsnbolts[96] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x3F, 0xCC, 0xCC, 0xCD, 0x2, 0xE3, 0x0, 0x4C,
    0x3F, 0xCC, 0xCC, 0xCD, 0x2, 0xE3, 0x0, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x2, 0xE3, 0x0, 0x2,
    0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xE4, 0x0, 0x1,  0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xE4, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x2, 0xE3, 0x0, 0x92, 0x3F, 0x8F, 0x5C, 0x29, 0x2, 0xE5, 0x0, 0x1,
    0x3F, 0x8F, 0x5C, 0x29, 0x2, 0xE5, 0x0, 0x1,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xE4, 0x4, 0x1,  0x3F, 0xCC, 0xCC, 0xCD, 0x2, 0xE3, 0x0, 0x4C};
u32 D_80800D30_chnutsnbolts[24] = {
    0x0,        0x0,       0x3FCCCCCD, 0x2E9004C, 0x3FCCCCCD, 0x2E9004C, 0x3FCCCCCD, 0x2E90002,
    0x3F28F5C3, 0x2EA0001, 0x3F28F5C3, 0x2EA0001, 0x40000000, 0x2E90092, 0x3F8F5C29, 0x2EB0001,
    0x3FAF5C29, 0x2EB0001, 0x0,        0x0,       0x3F28F5C3, 0x2EA0401, 0x3FCCCCCD, 0x2E9004C};
u32 D_80800D90_chnutsnbolts[24] = {
    0x0,        0x0,       0x3FCCCCCD, 0x2E6004C, 0x3FCCCCCD, 0x2E6004C, 0x3FCCCCCD, 0x2E60002,
    0x3F28F5C3, 0x2E70001, 0x3F28F5C3, 0x2E70001, 0x40000000, 0x2E60092, 0x3F8F5C29, 0x2E80001,
    0x3F8F5C29, 0x2E80001, 0x0,        0x0,       0x3F28F5C3, 0x2E70401, 0x3FCCCCCD, 0x2E6004C};
u8 D_80800DF0_chnutsnbolts[20] = {0x0, 0x2, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0, 0x0, 0x8,
                                  0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0xB, 0x0, 0x0};
u8 D_80800E04_chnutsnbolts[12] = {0x0, 0x0, 0x0, 0x1, 0x3F, 0xE6, 0x66, 0x66, 0x0, 0x12, 0x0, 0x0};
u8 D_80800E10_chnutsnbolts[24] = {0x0, 0x0, 0x0, 0x3, 0x3F, 0xC0, 0x0, 0x0, 0x0, 0x12, 0x0, 0x0,
                                  0x0, 0x0, 0x0, 0x1, 0x40, 0x0,  0x0, 0x0, 0x0, 0x12, 0x0, 0x0};
int D_80800E28_chnutsnbolts[18] = {0x19D043E,
                                   0x7EA0002,
                                   (u32) &D_80800CD0_chnutsnbolts,
                                   (u32) func_80800080_chnutsnbolts,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x9C40000,
                                   0x3F800000,
                                   0x0,
                                   0x3850261,
                                   (u32) func_808008FC_chnutsnbolts,
                                   (u32) func_80108ED0,
                                   0x200000,
                                   (u32) func_80800024_chnutsnbolts,
                                   (u32) func_80107C2C,
                                   -0x7FDDABE3,
                                   (u32) func_808005D0_chnutsnbolts,
                                   (u32) &D_80800DF0_chnutsnbolts};
int D_80800E70_chnutsnbolts[18] = {0x19D043F,
                                   0x7EB0002,
                                   (u32) &D_80800D30_chnutsnbolts,
                                   (u32) func_80800080_chnutsnbolts,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x9C40000,
                                   0x3F4CCCCD,
                                   0x0,
                                   0x3850261,
                                   (u32) func_808008FC_chnutsnbolts,
                                   (u32) func_80108ED0,
                                   0x200000,
                                   (u32) func_80800024_chnutsnbolts,
                                   (u32) func_80107C2C,
                                   -0x7FDDABE3,
                                   (u32) func_808005D0_chnutsnbolts,
                                   (u32) &D_80800DF0_chnutsnbolts};
int D_80800EB8_chnutsnbolts[18] = {0x19D0440,
                                   0x7EC0002,
                                   (u32) &D_80800D90_chnutsnbolts,
                                   (u32) func_80800080_chnutsnbolts,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x9C40000,
                                   0x3F99999A,
                                   0x0,
                                   0x3850261,
                                   (u32) func_808008FC_chnutsnbolts,
                                   (u32) func_80108ED0,
                                   0x200000,
                                   (u32) func_80800024_chnutsnbolts,
                                   (u32) func_80107C2C,
                                   -0x7FDDABE3,
                                   (u32) func_808005D0_chnutsnbolts,
                                   (u32) &D_80800DF0_chnutsnbolts};
f32 D_80800F00_chnutsnbolts[5] = {1.746939e-39f, 1.194112e-39f, 1.8734443e-38f, 2.0695875e-35f,
                                  0.0f};
f32 D_80800F14_chnutsnbolts[6] = {0.0f, 0.1f, 0.5f, 1.0f, 1.0f, 0.1f};
s32 D_80800F2C_chnutsnbolts[4] = {0x1304B2, 0xD00D9, 0xF30016, 0x36B00000};
s32 D_80800F3C_chnutsnbolts[3] = {0x3F19999A, 0x3F666666, -0x40800000};
s32 D_80800F48_chnutsnbolts[4] = {0x1304B2, 0xD00C0, 0xD90016, 0x36B00000};
s32 D_80800F58_chnutsnbolts[6] = {0x3E4CCCCD, 0x3F000000, -0x40800000, 0x0, 0x0, 0x0};
