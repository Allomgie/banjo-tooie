#include "common.h"

extern int D_808008C8_chjiggytemple[];
extern u8 D_80800910_chjiggytemple[];
void _subaddiedialog_entrypoint_7();
extern f32 func_80103EAC(Actor *);
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
extern int D_8080092C_chjiggytemple[];
extern f32 func_80103EF4(Actor *);
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_7(Actor *, f32);
extern int D_80800974_chjiggytemple[];
extern s32 D_808009BC_chjiggytemple[];
extern s32 D_808009D0_chjiggytemple[];
extern void _subaddieaudioloop_entrypoint_4();
extern u8 _subaddieaudioloop_entrypoint_7();
extern s32 D_808009E0_chjiggytemple[];
extern f32 D_80800A24_chjiggytemple[];
extern f32 D_80800A30_chjiggytemple[];
extern f32 func_800D8FF8(void);
extern f32 func_800F3780(f32, f32 *, s32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800E13F0(s32, f32);
extern void func_80018820(s32, f32, f32);
extern u8 D_80800A50_chjiggytemple[];
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
typedef struct {
    u8 pad_0[0x24];
    u8 local_0;
    u8 pad_1[7];
    void *local_1;
    s32 local_2;
} JiggyTempleData;
extern void func_800B5450(void *);
extern u8 _subaddieaudioloop_entrypoint_3();

int chjiggytemple_entrypoint_0()
{
    return (int) &D_808008C8_chjiggytemple;
}

void func_8080000C_chjiggytemple(s32 param_0)
{
    _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_80800910_chjiggytemple);
}

void func_80800034_chjiggytemple(s32 param_0)
{
    func_8010C908(param_0, param_0 + 4);
    func_8080000C_chjiggytemple(param_0);
    if (func_800DB9B0() == 0) {
        func_800D2498(0x10E, func_800D035C(1), 0);
        func_800D2498(0x106, _sujiggy_entrypoint_2(_sujiggy_entrypoint_0()), 0);
    }
}

void func_808000A8_chjiggytemple(s32 arg0)
{
}

s32 func_808000B0_chjiggytemple(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    f32 local_1[4];
    switch (param_1) {
        case 0x2E:
            local_0 = 0;
            switch (((s16 *) &param_2)[0]) {
                case 0x1505:
                case 0x1506:
                    switch (_sujiggy_entrypoint_17()) {
                        case -1:
                            local_0 = 0x1509;
                            break;
                        case 0:
                            if (_sujiggy_entrypoint_16() == 1)
                                local_0 = 0x154A;
                            else
                                local_0 = 0x1508;
                            break;
                        case 1:
                            local_0 = 0x1507;
                    }
                    break;
                case 0x1507:
                    if (!func_800DA298(0x532)) {
                        func_800DA544(0x532);
                        _capod_entrypoint_14();
                    } else {
                        func_800C01A8(0x6B, 0);
                    }
            }
            if (local_0)
                _subaddiedialog_entrypoint_11(param_0->unk0, local_0, 0xF, param_0->position, 0x98);
            break;
        case 0x30:
            return _sujiggy_entrypoint_16();
        case 0x2F:
            if (!func_800DA298(0x532)) {
                func_80101180(0x1E7, 7, 0);
                func_800C01A8(0x6B, 0);
                _capod_entrypoint_13(param_0->unk0, 0, 5, 0x2020);
            }
            break;
        case 0x95:
            if (_sujiggy_entrypoint_17())
                func_80102424(param_0, 2);
            else
                func_80102424(param_0, 1);
            break;
        case 0x52:
            local_1[0] = (1.0f / param_0->scale) * 180.0f;
            local_1[1] = func_80103EAC(param_0) * 2.5f;
            local_1[2] = local_1[1] * 2.5f;
            local_1[3] = (1.0f / param_0->scale) * 120.0f;
            _gcdialogcamera_entrypoint_4(param_0->position);
            _gcdialogcamera_entrypoint_3((u32 *) local_1, param_0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

int chjiggytemple_entrypoint_1()
{
    return (int) &D_8080092C_chjiggytemple;
}

void func_80800320_chjiggytemple(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800EA090();
    if (func_800DA298(0x532) && (local_0 == 1 || _sujiggy_entrypoint_17()))
        func_80101FDC(param_0, 4);
    _chdoormake_entrypoint_3(param_0, 0, 90.0f, func_80103EF4(param_0), 2, -1);
    _chdoormake_entrypoint_5(param_0, 1.0f);
    _chdoormake_entrypoint_6(param_0, 0.5f);
    _chdoormake_entrypoint_7(param_0, 0.5f);
    _chdoormake_entrypoint_8(param_0, 5);
    _chdoormake_entrypoint_9(param_0, 1, 0x12, 0x10);
    if (func_800DA298(0x532)) {
        local_1 = _glcutDll_entrypoint_18();
        if (!_sujiggy_entrypoint_17() && local_1 != 0x67 && local_1 != 0x7A)
            func_8010108C(param_0, 8, 0);
    }
}

s32 func_80800438_chjiggytemple(s32 param_0, s32 param_1)
{
    if (param_1 == 7) {
        _chdoor_entrypoint_1(param_0);
        return;
    }
    _chdoor_entrypoint_1(param_0);
}

int chjiggytemple_entrypoint_2(void)
{
    return (int) &D_80800974_chjiggytemple;
}

void func_8080047C_chjiggytemple(u8 *param_0)
{
    _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, 1, &D_808009BC_chjiggytemple);
    param_0[0x24] = _subaddieaudioloop_entrypoint_7(param_0[0x24], param_0 + 4, 1,
                                                    &D_808009D0_chjiggytemple, 0);
}

void func_808004D8_chjiggytemple(Actor *param_0)
{
    f32 local_3;
    int local_0;
    f32 local_1[3];

    local_3 = func_800D8FF8();
    local_0 = 0;
    if (((f32 *) param_0->actorData)[2] < 1.0f) {
        ((f32 *) param_0->actorData)[2] += local_3 * ((f32 *) param_0->actorData)[4];
        if (((f32 *) param_0->actorData)[2] >= 1.0f) {
            ((f32 *) param_0->actorData)[2] = 1.0f;
            local_0 = 1;
        }
    }
    if (!param_0->actorData[5]) {
        func_800EE780(local_1, param_0->position, D_80800A24_chjiggytemple);
        param_0->actorData[5] = func_800B53A4(50);
        func_800B5534(param_0->actorData[5]);
        param_0->actorData[5] = func_800BABB8(param_0->actorData[5], param_0->position, local_1,
                                              1.0f, &D_808009E0_chjiggytemple);
    }
    func_800BA22C(param_0->actorData[5], 4);
    if (_glcutDll_entrypoint_19(0x67)) {
        if (!param_0->actorData[6])
            param_0->actorData[6] = func_800E15CC(0, 0.0f, 1.0f) + 1;
        func_800E13F0(param_0->actorData[6] - 1, 10.0f);
    }
    switch (param_0->unk70_10) {
        case 1:
            if (_glcutDll_entrypoint_19(0x67)) {
                func_80018820(0, 0.75f, 0.5f);
                func_8080047C_chjiggytemple(param_0);
            }
            break;
        case 2:
            ((f32 *) param_0->actorData)[1] =
                func_800F3780(((f32 *) param_0->actorData)[2], D_80800A30_chjiggytemple, 4);
            if (local_0) {
                _capod_entrypoint_14();
                _sujiggy_entrypoint_15(_sujiggy_entrypoint_0() - 1, 0);
            }
            func_8080047C_chjiggytemple(param_0);
    }
}

void func_80800688_chjiggytemple(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2[3];
    f32 local_3;

    func_800E3A58(local_0);
    param_0->rotation[1] = local_0[1];
    func_80101870(param_0, param_1);
    if (*(f32 *) &param_0->actorData[1] > 0.0f) {
        _sufade_entrypoint_0((s32) (*(f32 *) &param_0->actorData[1] * 255.0f),
                             D_80800A50_chjiggytemple);
    }
    func_800E3980(local_2);
    if (func_800F1E6C(param_0->position, local_2, &local_1)) {
        local_3 = mlAbsF(func_800F1DCC(local_1, local_0[1])) / 25.0f;
        if (local_3 < 1.0f) {
            _sufade_entrypoint_0((s32) ((1.0f - local_3) * 100.0f), D_80800A50_chjiggytemple);
        }
    }
}

void func_80800784_chjiggytemple(JiggyTempleData *param_0)
{
    if (param_0->local_1 != NULL) {
        func_800B5450(param_0->local_1);
        param_0->local_1 = NULL;
    }
    if (param_0->local_2 != 0) {
        func_800E1720(param_0->local_2 - 1);
        param_0->local_2 = 0;
    }
    if (param_0->local_0 != 0) {
        param_0->local_0 = _subaddieaudioloop_entrypoint_3(param_0->local_0);
    }
}

s32 func_808007F4_chjiggytemple(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x95:
            if (!_glcutDll_entrypoint_19(0x67) && !_glcutDll_entrypoint_19(0x7A)) {
                func_800FFAB0(param_0);
            } else {
                _capod_entrypoint_13(param_0->unk0, 0, 20, 0x2820);
            }
            break;
        case 0xB:
            func_80101FDC(param_0, 2);
            *(f32 *) &param_0->actorData[2] = 0.0f;
            *(f32 *) &param_0->actorData[4] = 2.0f;
            return 3;
        default:
            return 0;
    }
    return 1;
}

extern void func_80102EC0();
extern int func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
u32 D_808008B0_chjiggytemple[6] = {0x0, 0x0, 0x418651EC, 0x4C90000, 0x418651EC, 0x4C90000};
int D_808008C8_chjiggytemple[18] = {0x15801E6,
                                    0x9370001,
                                    (u32) &D_808008B0_chjiggytemple,
                                    (u32) func_80800034_chjiggytemple,
                                    (u32) func_80102EC0,
                                    (u32) func_80101870,
                                    0x3E80000,
                                    0x0,
                                    0x0,
                                    0x128,
                                    (u32) func_808000A8_chjiggytemple,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    (u32) func_808000B0_chjiggytemple,
                                    0x0};
u8 D_80800910_chjiggytemple[28] = {0x3,  0xED, 0x1, 0x2C, 0x15, 0x5, 0x15, 0x6,  0xFF, 0xFF,
                                   0xFF, 0xFF, 0x0, 0x0,  0x0,  0x0, 0x0,  0x98, 0x0,  0x0,
                                   0x0,  0x8,  0x6, 0x28, 0x0,  0x0, 0x0,  0x0};
int D_8080092C_chjiggytemple[18] = {0xAC01E7,
                                    0x9680001,
                                    0x0,
                                    (u32) _chdoor_entrypoint_0,
                                    (u32) func_80102EC0,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0xC00,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800320_chjiggytemple,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    (u32) func_80800438_chjiggytemple,
                                    0x0};
int D_80800974_chjiggytemple[18] = {0x15804B2,
                                    0x81B0001,
                                    0x0,
                                    (u32) func_808004D8_chjiggytemple,
                                    (u32) func_80102EC0,
                                    (u32) func_80800688_chjiggytemple,
                                    0x4E20,
                                    0x0,
                                    0x0,
                                    0x20400,
                                    (u32) func_80800784_chjiggytemple,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80107C2C,
                                    -0x7FFFFBFE,
                                    (u32) func_808007F4_chjiggytemple,
                                    0x0};
s32 D_808009BC_chjiggytemple[5] = {0x130673, 0x200002, 0x1632C8, 0xA00D9, 0x0};
s32 D_808009D0_chjiggytemple[4] = {0x1304A9, 0x165DC0, 0xA0100, 0x0};
s32 D_808009E0_chjiggytemple[17] = {0x1D09E5, 0x1BFF38,  -0x12BFFD3, 0x2BC04B0, 0xB0082,  0xBE0032,
                                    0x16,     0x2020024, 0x330059,   0x150000,  0x4C001E, 0x640064,
                                    0x2A0000, 0x190080,  0xC00004,   0x4C0007,  0x20000};
f32 D_80800A24_chjiggytemple[3] = {0.0f, -3.3e+02f, 0.0f};
f32 D_80800A30_chjiggytemple[8] = {0.0f, 0.0f, 0.2f, 0.0f, 0.8f, 1.0f, 1.0f, 1.0f};
u8 D_80800A50_chjiggytemple[16] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF,
                                   0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0};
