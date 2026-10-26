#include "common.h"

extern s32 func_800D90A4(f32 *);
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern u32 D_80802674_chaliendad[];
extern int D_808026BC_chaliendad[];
extern int D_80802704_chaliendad[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE940();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102424(Actor *, s32);
extern s32 D_808025C0_chaliendad[];
extern f32 D_808025D8_chaliendad[3];
extern u32 D_8080281C_chaliendad[];
extern int _gcdialogcamera_entrypoint_0(int, int);
extern s32 D_80802824_chaliendad[];
extern u8 unk1C[];
extern u8 D_808025E4_chaliendad[];
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern void func_80105A9C(Actor *, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern void func_801015D0(Actor *);
extern f32 func_800F15F8(f32, f32, f32);
typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest72:10; } AlienState;
extern u8 D_80802834_chaliendad[];
extern void func_80103DFC(AlienState *, f32 *);
extern void _subaddieaudioloop_entrypoint_4();
extern void func_80018820(s32, f32, f32);
extern s32 func_80102320(Actor *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
typedef struct { u8 pad0[0x34]; s32 unk34; } AlienData;
typedef union { s32 i; struct { s16 a; s16 b; } h; } AlienArg;
extern s32 _chlifeforcespell_entrypoint_1(Actor **, f32 *, s32, f32, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_80108B04(Actor *, s32);
extern void func_800EE88C(f32 *, AlienData *);
extern s32 _glcutDll_entrypoint_19(s32);
extern void _glcutDll_entrypoint_17(void);
extern void func_800DA544(s32);
extern void func_800E39A8(f32 *, f32 *);
extern void _gcdialogcamera_entrypoint_3();
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800FFAB0(Actor *);
typedef struct { u8 pad_0[0x78]; u32 pad_1:18; u32 local_0:2; u32 local_1:3; u32 pad_2:9; } AlienDadBlink1506;
typedef struct { u8 pad_0[0x18]; s16 local_0; f32 local_1; f32 local_2; f32 local_3; } AlienDadExpressionData;
extern f32 func_800DC0C0(void);
typedef struct { u8 pad_0[0x1C]; f32 local_0; f32 local_1; f32 local_2; } AlienBlinkData271;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 18; u32 local_0 : 2; u32 local_1 : 3; u32 pad_2 : 9; } AlienBlink271;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern void func_80102FDC(Actor *, f32);
void func_80801C9C_chaliendad();
void func_80801D40_chaliendad();
int func_80801DD0_chaliendad();
void func_80802218_chaliendad();
void func_80802284_chaliendad();
void func_80801324_chaliendad();
void func_8080142C_chaliendad();
void func_8080152C_chaliendad();
void func_80801868_chaliendad();
extern void func_80105834(), func_80107C2C(), func_80800024_chaliendad(), func_808000AC_chaliendad(), func_80800918_chaliendad();
extern u8 D_808025F4_chaliendad[];

u8 *chaliendad_entrypoint_0(void) {
    return D_80802674_chaliendad;
}

int chaliendad_entrypoint_1()
{
  return (int)&D_808026BC_chaliendad;
}

int chaliendad_entrypoint_2()
{
  return (int)&D_80802704_chaliendad;
}

void func_80800024_chaliendad(param_0) Actor *param_0;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800EE940((s16 *)local_0, param_0->position);
    func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
    *(s16 *)(local_0 + 6) = param_0->rotation[1];
    func_80801324_chaliendad(param_0, 0);
    if (func_80801DD0_chaliendad() == 3) func_800FFAB0(param_0);
}

void func_808022CC_chaliendad();

void func_808012AC_chaliendad();

void func_808000AC_chaliendad(param_0) Actor *param_0;
{
    extern u8 D_8080274C_chaliendad[];
    extern u8 D_80802764_chaliendad[];
    extern u8 D_80802774_chaliendad[];
    extern u8 D_80802784_chaliendad[];
    extern u8 D_80802794_chaliendad[];
    extern u8 D_808027A4_chaliendad[];
    extern u8 D_808027B4_chaliendad[];
    extern u8 D_808027C0_chaliendad[];
    extern u8 D_808027CC_chaliendad[];
    extern u8 D_808027D4_chaliendad[];
    extern u8 D_808027FC_chaliendad[];
    extern u8 D_80802808_chaliendad[];
    extern u8 D_80802814_chaliendad[];

    char *local_0;
    char *local_1;
    Actor *local_2;
    f32 local_3[3];
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    char *local_8;
    f32 local_9[3];
    f32 local_10;

    local_0 = (char *)func_80100094(param_0, 0);
    local_1 = (char *)func_80100094(param_0, 1);

    if (local_1 != 0) {
        if (func_801022E4(param_0) != 0x367) {
            _suexpression_entrypoint_18(local_1, 1);
        }

        _suexpression_entrypoint_10(
            local_1,
            *(s32 *)((char *)param_0 + 0x0),
            0
        );
    }

    switch (param_0->unk70_10) {
        case 2:
            func_800EE7F8(
                (char *)param_0 + 0x28,
                (char *)param_0 + 4
            );

            if (_subaddieaudioquick_entrypoint_3(
                    param_0,
                    (char *)param_0 + 4,
                    D_80802764_chaliendad,
                    0.55f)) {
                func_80018820(0, 0.7f, 0.3f);
            }

            if (_subaddieaudioquick_entrypoint_3(
                    param_0,
                    (char *)param_0 + 4,
                    D_80802774_chaliendad,
                    0.71f)) {
                func_80018820(0, 1.0f, 0.3f);
            }

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802784_chaliendad,
                0.92f
            );

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802794_chaliendad,
                0.56f
            );

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_808027A4_chaliendad,
                0.75f
            );

            local_4 = func_80102320(
                param_0,
                0.25f,
                0.9f
            );

            *(u8 *)(local_0 + 0x39) =
                _subaddieaudioloop_entrypoint_7(
                    *(u8 *)(local_0 + 0x39),
                    (char *)param_0 + 4,
                    local_4,
                    D_808027B4_chaliendad,
                    *(s32 *)((char *)param_0 + 0x70) & 1
                );

            if (func_80101DDC(param_0)) {
                func_800EE88C(
                    (char *)param_0 + 4,
                    local_0
                );

                *(f32 *)((char *)param_0 + 0x8) += 6500.0f;
                *(f32 *)((char *)param_0 + 0x48) =
                    (f32)*(s16 *)(local_0 + 6);

                func_80102424(param_0, 3);

                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x1288,
                    0x44,
                    (char *)param_0 + 4,
                    0x62
                );

                func_80801D40_chaliendad(
                    param_0,
                    7,
                    0x31,
                    0
                );

                *(f32 *)((char *)param_0 + 0x24) = 800.0f;

                local_2 = (Actor *)_subaddiefind_entrypoint_2(
                    0x45B,
                    0
                );

                func_80102424(local_2, 4);
                local_2->unk64_16 = 1;
            }
            break;

        case 3:
            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_8080274C_chaliendad,
                0.4f
            );

            *(f32 *)((char *)param_0 + 0x24) += func_800D8FF8() * 600.0f;

            *(f32 *)((char *)param_0 + 0x8) -=
                func_800D8FF8() * *(f32 *)((char *)param_0 + 0x24);
            break;

        case 4:
            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_8080274C_chaliendad,
                0.4f
            );

            *(f32 *)((char *)param_0 + 0x24) += func_800D8FF8() * 400.0f;

            *(f32 *)((char *)param_0 + 0x8) -=
                func_800D8FF8() * *(f32 *)((char *)param_0 + 0x24);
            break;

        case 5:
            if (_subaddieaudioquick_entrypoint_3(
                    param_0,
                    (char *)param_0 + 4,
                    D_808027C0_chaliendad,
                    0.155f)) {

                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_808027CC_chaliendad
                );

                func_80018820(0, 2.0f, 0.3f);

                func_800EE7F8(
                    local_3,
                    (char *)param_0 + 4
                );

                func_800EF1B8(
                    local_3,
                    *(f32 *)((char *)param_0 + 0x48),
                    -100.0f
                );

                func_800BBCB8(
                    local_3,
                    0,
                    1.2f,
                    1,
                    D_808027D4_chaliendad
                );

                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x1289,
                    0x44,
                    (char *)param_0 + 4,
                    0x62
                );
            }

            if (func_80101E14(param_0, 0.9f)) {
                func_80801324_chaliendad(param_0, 1);
            }

            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 6);
                _subaddieDll_entrypoint_4(param_0, 0);
            }
            break;

        case 7:
            if (func_800D9078(
                    (char *)param_0 + 0x58)) {
                func_80102424(param_0, 8);
            }
            break;

        case 8:
            if (func_80101E14(param_0, 0.1f)) {
                func_80801324_chaliendad(param_0, 3);
            }

            if (func_80101DDC(param_0)) {
                func_800DA544(0x376);

                func_80801C9C_chaliendad(
                    param_0,
                    3,
                    1
                );

                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x1287,
                    0xE,
                    (char *)param_0 + 4,
                    0x62
                );

                func_80102424(param_0, 0xA);
            }
            break;

        case 11:
            if (func_80101E14(param_0, 0.2f)) {
                func_80108B04(param_0, 3);
            }

            if (func_80101DDC(param_0)
                && func_800D9078(
                    (char *)param_0 + 0x58)) {

                func_80801C60_chaliendad(param_0);

                func_8010114C(
                    *(s32 *)(local_0 + 0x28),
                    0x4A,
                    0
                );

                func_80102424(param_0, 9);
            }
            break;

        case 9:
            func_80801B9C_chaliendad(param_0);
            break;

        case 12:
            local_5 = 0;
            local_6 = 0;

            while (local_6 < 3) {
                if (func_800D9078(
                        local_0 + 0xC + local_6 * 4)) {

                    func_8010114C(
                        *(s32 *)(local_0 + 0x28 + local_6 * 4),
                        0x4E,
                        0
                    );

                    *(u8 *)(local_0 + 8 + local_6) = 1;
                    *(u8 *)(local_0 + 0xB) = 1;
                }

                if (*(u8 *)(local_0 + 8 + local_6)) {
                    local_5++;
                }

                local_6++;
            }

            if (local_5 == 3) {
                func_80801D40_chaliendad(
                    param_0,
                    0x41,
                    0x30,
                    0
                );

                func_80102424(param_0, 0xD);
                func_80108B04(param_0, 2);
                *(f32 *)((char *)param_0 + 0x58) = 2.0f;
            }
            break;

        case 13:
            if (func_80101DDC(param_0)
                && func_800D9078(
                    (char *)param_0 + 0x58)) {

                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_808027FC_chaliendad
                );

                func_80102424(param_0, 0xE);

                *(f32 *)((char *)param_0 + 0x58) = 4.0f;
                *(f32 *)((char *)param_0 + 0x24) = 50.0f;
                *(f32 *)((char *)param_0 + 0x18) = 0.5f;
            }
            break;

        case 14:
            local_7 = func_800D9078(
                (char *)param_0 + 0x58
            );

            *(f32 *)((char *)param_0 + 0x24) +=
                func_800D8FF8() * 100.0f;

            local_10 = *(f32 *)((char *)param_0 + 0x24) * func_800D8FF8();
            *(f32 *)((char *)param_0 + 0x8) += local_10;

            if (func_800D9078(
                    (char *)param_0 + 0x18)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_80802808_chaliendad
                );
            }

            if (local_7) {
                local_8 = (char *)_subaddiefind_entrypoint_2(
                    0x45B,
                    0
                );

                func_8010114C(
                    *(s32 *)((char *)param_0 + 0x3C),
                    0x4F,
                    0
                );

                *(s32 *)((char *)param_0 + 0x3C) = 0;

                func_800D1000(
                    0x45,
                    1,
                    (char *)param_0 + 4,
                    0,
                    0
                );

                func_80801D40_chaliendad(
                    param_0,
                    0x47,
                    0x31,
                    *(s32 *)local_8
                );

                func_808022CC_chaliendad(local_8);

                *(u8 *)((char *)param_0 + 0x65) &= ~1;
                func_80102424(param_0, 0xF);
            }
            break;
    }

    *(u8 *)(local_0 + 0x38) =
        _subaddieaudioloop_entrypoint_7(
            *(u8 *)(local_0 + 0x38),
            (char *)param_0 + 4,
            *(u8 *)(local_0 + 0xB),
            D_80802814_chaliendad,
            *(s32 *)((char *)param_0 + 0x70) & 1
        );

    if (_subaddieskeleton_entrypoint_0(
            param_0,
            0x2C,
            local_9)) {
        _sudeflect_entrypoint_0(
            local_9,
            0,
            125.0f,
            2
        );
    }

    if (_subaddieskeleton_entrypoint_0(
            param_0,
            1,
            local_9)) {
        _sudeflect_entrypoint_0(
            local_9,
            0,
            125.0f,
            2
        );
    }

    func_808012AC_chaliendad(param_0);

    if (param_0->unk7C_12) {
        _chbadshad_entrypoint_2(
            param_0,
            3,
            param_0->scale + param_0->scale,
            0
        );
    }
}

void func_80801E80_chaliendad();

s32 func_808008C8_chaliendad(this) Actor *this;
{
    u8 *local_0;

    local_0 = func_80100094(this, 0);
    local_0[0x38] = _subaddieaudioloop_entrypoint_3(local_0[0x38]);
    local_0[0x39] = _subaddieaudioloop_entrypoint_3(local_0[0x39]);
    func_80801E80_chaliendad(this);
}

void func_80800918_chaliendad(param_0, param_1) Actor *param_0; void *param_1;
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 2) {
        func_800E39A8(param_0->position, local_1);
        func_800EF214(param_0->position, local_1[0], local_1[1], -1000.0f);
        param_0->rotation[1] = local_1[1];
        param_0->rotation[0] = local_1[0] + 15.0f;
        func_800DF744(3, 1);
    } else {
        func_800DF744(3, 0);
    }
    func_800DF744(1, ((*(u32 *)((u8 *)param_0 + 0x78) << 20) >> 29) + 1);
    func_800DF744(2, ((*(u32 *)((u8 *)param_0 + 0x78) << 20) >> 29) + 1);
    if (*(s32 *)(local_0 + 0x34)) {
        _subaddiefade_entrypoint_9(param_0, local_3);
        _chlifeforcespell_entrypoint_2(param_0, *(s32 *)(local_0 + 0x34), local_2);
        _subaddiefade_entrypoint_11(param_0, local_2);
        func_80101870(param_0, param_1);
        _subaddiefade_entrypoint_11(param_0, local_3);
    } else {
        func_80101870(param_0, param_1);
    }
}

s32 func_80801E28_chaliendad();

void func_80801220_chaliendad();

void func_80801110_chaliendad();

void func_80800F28_chaliendad();

s32 func_80800A54_chaliendad(Actor *param_0, s32 param_1, AlienArg param_2)
{
    AlienData *local_0;
    f32 local_1[3];
    f32 local_2[3];
    AlienArg *local_5;
    f32 local_3[3];
    AlienArg *local_6;
    Actor *local_7;
    f32 local_4[2];

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x95:
        func_80800F28_chaliendad(param_0);
        return 1;
    case 0x2E:
        local_5 = &param_2;
        func_80801110_chaliendad(param_0, local_5->h.a, local_5->h.b);
        return 1;
    case 0x2F:
        local_6 = &param_2;
        func_80801220_chaliendad(param_0, local_6->h.a, local_6->h.b);
        return 1;
    case 0x3D:
        switch (param_2.i) {
        case 0:
            func_800EE7F8(local_1, param_0->position);
            local_1[1] += 60.0f;
            local_0->unk34 = _chlifeforcespell_entrypoint_1(&param_0, local_1, 150, 3.2f, 0x12);
            break;
        case 1:
            func_800EE7F8(local_2, param_0->position);
            local_2[1] += 2000.0f;
            func_80108528(0x45B, local_2, 0, &param_0);
            return 1;
        case 2:
            param_0->unk3C = func_80108528(0x466, param_0->position, 0, &param_0)->unk0;
            break;
        case 3:
            if (_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_3)) {
                local_7 = func_80108528(0x467, local_3, 0, &param_0);
                local_7->unk3C = param_0->unk0;
            }
            break;
        }
        break;
    case 0x4B:
        func_80108B04(param_0, 0);
        func_80801D40_chaliendad(param_0, 0x15, 0x30, 0);
        func_80102424(param_0, 7);
        param_0->unk58 = 6.0f;
        break;
    case 0x4C:
        local_0->unk34 = 0;
        break;
    case 0xB:
        switch (param_2.i) {
        case 7:
            func_800EE88C(param_0->position, local_0);
            param_0->position[1] += 6500.0f;
            func_80102424(param_0, 4);
            func_80801D40_chaliendad(param_0, 0x2D, 0x31, 0);
            ((f32 *)param_0->actorData)[3] = 800.0f;
            return 4;
        case 0x2D:
            func_800EE88C(param_0->position, local_0);
            func_80801D40_chaliendad(param_0, 0x27, 0x30, 0);
            func_80102424(param_0, 5);
            return 4;
        case 0x27:
            func_80801C60_chaliendad(param_0);
            if (_glcutDll_entrypoint_19(0x4A)) {
                _glcutDll_entrypoint_17();
            }
            func_800DA544(0x375);
            return 4;
        }
        return 3;
    case 0xE:
        if (param_0->unk70_10 == 2) {
            func_800E39A8(param_0->position, local_4);
            func_800EF214(param_0->position, local_4[0], local_4[1], -1000.0f);
            param_0->rotation[1] = local_4[1];
            param_0->rotation[0] = local_4[0] + 15.0f;
        }
        return 3;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808025E4_chaliendad, *(s32 *)&param_0->scale);
        return 1;
    case 0x57:
        return func_80801254_chaliendad(param_0, param_2.i & 0xFFFF, (param_2.i & 0xFFFF0000) >> 16);
    case 0x31:
        if (param_2.i == 0x45B) {
            func_80801D40_chaliendad(param_0, 0x1A, 0x30, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x12AA, 7, param_0->position, 0x62);
            func_80102424(param_0, 10);
            return 1;
        }
        if (func_80801DD0_chaliendad() == 3) {
            func_80108B04(param_0, 1);
            func_80801D40_chaliendad(param_0, 0x45, 0x2030, 0);
            return 1;
        }
        break;
    case 0x29:
        func_80801E28_chaliendad(param_0);
        return 1;
    case 0x2A:
        func_80801E80_chaliendad(param_0);
        return 1;
    case 0x2C:
        func_80801C60_chaliendad(param_0);
        func_800FFAB0(param_0);
        return 1;
    case 0xB8:
        return 0x12A9 - func_80801DD0_chaliendad();
    default:
        return 0;
    }
    return 1;
}

void func_80800F28_chaliendad(Actor *param_0)
{
    u8 *local_0;
    Actor *local_1;
    s32 pad[2];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    Actor *local_7;
    s32 local_8;
    u8 *local_6;

    local_0 = func_80100094(param_0, 0);
    local_1 = _subaddiefind_entrypoint_2(0x45B, 0);
    param_0->unk64_20 = 0;
    if (!func_800DA298(0x375)) {
        local_2 = _glcutDll_entrypoint_19(0x4A);
        local_3 = 0;
        local_4 = 0x30;
        if (!local_2 && !func_800DB9B0()) {
            if (func_800DA298(0xB6)) {
                local_5 = func_800EA090();
                local_8 = local_5 != 10;
                if (local_8) {
                    local_8 = local_5 != 6;
                }
                if (local_8) {
                    local_3 = 1;
                }
            }
        } else {
            local_4 = 0x2830;
        }
        if (local_2 || local_3) {
            param_0->unk64_20 = 1;
            func_80102424(param_0, 1);
            func_80101FDC(local_1, 2);
            *(u8 *)((u8 *)param_0 + 0x65) &= ~1;
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x12A0, 0x44, param_0->position, 0x62);
            func_80801D40_chaliendad(param_0, 0x2A, local_4, local_1->unk0);
        }
    }
    local_3 = 0;
    local_6 = local_0;
    do {
        local_7 = _subaddiefind_entrypoint_2(local_3 + 0x456, 0);
        *(Unk80132ED0 **)(local_6 + 0x28) = local_7 ? local_7->unk0 : NULL;
        local_3++;
        local_6 += 4;
    } while (local_3 != 3);
    if (!param_0->unk64_20) {
        func_800FFAB0(local_1);
        if (!func_800DA298(0x375)) {
            func_800FFAB0(param_0);
            return;
        }
        if (!func_800DA298(0x376)) {
            func_80801324_chaliendad(param_0, 2);
            func_80102424(param_0, 6);
        }
    }
}

void func_80801110_chaliendad(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 *local_0;
    s32 local_1;

    local_0 = (f32 *)func_80100094(param_0, 0);
    switch (param_1) {
    case 0x1287:
        func_80102424(param_0, 0xB);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x12B4, 0x144, param_0->position, 0x62);
        func_80801D40_chaliendad(param_0, 0x37, 0x30, NULL);
        param_0->unk58 = 1.5f;
        break;
    case 0x12AA:
        func_80801D40_chaliendad(param_0, 0x49, 0x30, NULL);
        func_80102424(param_0, 0xC);
        for (local_1 = 0; local_1 < 3; local_1++) {
            local_0[local_1 + 3] = D_808025D8_chaliendad[local_1];
        }
        break;
    default:
        if (_subaddiedialog_entrypoint_9(param_0, param_1, &D_808025C0_chaliendad, 3)) {
            func_80102424(param_0, 9);
        }
        break;
    }
}

void func_80801220_chaliendad(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x12A0)
  {
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_8080281C_chaliendad);
  }
}

int func_80801254_chaliendad(Actor *param_0, s32 param_1, s32 param_2)
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if (*(s32 *)((char *)param_0 + 0x1C) != 2)
    {
      func_80801C9C_chaliendad((u8 *)param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

void func_808012AC_chaliendad(Actor *param_0)
{
    u8 *local_0;

    local_0 = (u8 *)func_80100094(param_0, 0);
    switch (*(s16 *)(local_0 + 0x18)) {
    case 0:
        func_8080142C_chaliendad(param_0);
        break;
    case 1:
        func_8080152C_chaliendad(param_0);
        break;
    case 3:
        func_80801868_chaliendad(param_0);
        break;
    }
}

void func_80801324_chaliendad(param_0, param_1) Actor *param_0; s32 param_1;
{
    AlienDadExpressionData *local_0;

    local_0 = (AlienDadExpressionData *)func_80100094(param_0, 0);
    local_0->local_0 = param_1;
    switch (param_1) {
    case 0:
        ((AlienDadBlink1506 *)param_0)->local_0 = 0;
        ((AlienDadBlink1506 *)param_0)->local_1 = 0;
        break;
    case 1:
        ((AlienDadBlink1506 *)param_0)->local_0 = 0;
        ((AlienDadBlink1506 *)param_0)->local_1 = 0;
        local_0->local_2 = local_0->local_3 = 0.8f;
        local_0->local_1 = 6.0f;
        break;
    case 2:
        ((AlienDadBlink1506 *)param_0)->local_1 = 3;
        local_0->local_2 = local_0->local_3 = 0.4f;
        break;
    case 3:
        ((AlienDadBlink1506 *)param_0)->local_0 = 2;
        ((AlienDadBlink1506 *)param_0)->local_1 = 3;
        local_0->local_2 = local_0->local_3 = 0.3f;
        local_0->local_1 = 5.0f;
        break;
    }
}

void func_8080142C_chaliendad(param_0) Actor *param_0;
{
    AlienDadBlink1506 *local_0 = (AlienDadBlink1506 *)param_0;

    switch (local_0->local_0) {
    case 0:
        if (func_800DC0C0() < 0.03f) local_0->local_0 = 1;
        break;
    case 1:
        if (local_0->local_1 == 3) local_0->local_0 = 3;
        else local_0->local_1++;
        break;
    case 3:
        local_0->local_1--;
        if (!local_0->local_1) local_0->local_0 = 0;
        break;
    }
}

void func_8080152C_chaliendad(param_0) Actor *param_0;
{
    AlienBlinkData271 *local_4;
    f32 local_0;
    f32 local_1;
    s32 local_2;

    local_4 = func_80100094(param_0, 0);
    func_800D90A4(&local_4->local_0);
    local_2 = func_800D90A4(&local_4->local_1);
    local_0 = func_800F10B4(local_4->local_0, 0.0f, 6.0f, 1.0f, 0.0f);
    local_1 = func_800F10B4(local_4->local_1, 0.0f, local_4->local_2, 1.0f, 0.0f);
    switch (((AlienBlink271 *)param_0)->local_0) {
    case 0:
        if (func_800D90A4(&local_4->local_1)) {
            f32 local_5;
            ((AlienBlink271 *)param_0)->local_0 = 1;
            local_5 = func_800F10B4(local_0, 0.0f, 1.0f, 0.1f, 0.8f);
            local_4->local_2 = local_5;
            local_4->local_1 = local_5;
        }
        break;
    case 1:
        if (((AlienBlink271 *)param_0)->local_1 == 3) {
            if (func_800D90A4(&local_4->local_1)) {
                f32 local_5;
                ((AlienBlink271 *)param_0)->local_0 = 2;
                local_5 = func_800F10B4(local_0, 0.0f, 1.0f, 0.0f, 0.8f);
                local_4->local_2 = local_5;
                local_4->local_1 = local_5;
            }
        } else {
            ((AlienBlink271 *)param_0)->local_1++;
        }
        break;
    case 2:
        if (func_800D90A4(&local_4->local_1)) {
            f32 local_5;
            ((AlienBlink271 *)param_0)->local_0 = 3;
            local_5 = func_800F10B4(local_0, 0.0f, 1.0f, 0.1f, 0.8f);
            local_4->local_2 = local_5;
            local_4->local_1 = local_5;
        }
        break;
    case 3: {
        s32 local_3;

        /* Keep 0.f distinct: IDO does not intern it with the other zeros. */
        local_3 = (s32)func_800F10B4(local_0, 0.0f, 1.0f, 0.f, 2.0f);
        ((AlienBlink271 *)param_0)->local_1 = (u32)func_800F10B4(local_1, 0.0f, 1.0f, (f32)local_3, 3.0f);
        if (local_2) {
            f32 local_5;
            ((AlienBlink271 *)param_0)->local_1 = local_3;
            ((AlienBlink271 *)param_0)->local_0 = 0;
            local_5 = func_800F10B4(local_0, 0.0f, 1.0f, 0.8f, 0.01f);
            local_4->local_2 = local_5;
            local_4->local_1 = local_5;
            if (local_0 == 1.0f) {
                func_80801324_chaliendad(param_0, 2);
            }
        }
        break;
    }
    }
}

void func_80801868_chaliendad(param_0) Actor *param_0;
{
    AlienBlinkData271 *local_4;
    f32 local_0;
    f32 local_1;
    s32 local_2;

    local_4 = func_80100094(param_0, 0);
    func_800D90A4(&local_4->local_0);
    local_2 = func_800D90A4(&local_4->local_1);
    local_0 = func_800F10B4(local_4->local_0, 0, 6.0f, 1.0f, 0);
    local_1 = func_800F10B4(local_4->local_1, 0, local_4->local_2, 1.0f, 0);
    switch (((AlienBlink271 *)param_0)->local_0) {
    case 0:
        if (func_800D90A4(&local_4->local_1)) {
            f32 local_5;
            ((AlienBlink271 *)param_0)->local_0 = 1;
            local_5 = func_800F10B4(local_0, 0, 1.0f, 0.8f, 0.1f);
            local_4->local_2 = local_5;
            local_4->local_1 = local_5;
        }
        break;
    case 1:
        if (((AlienBlink271 *)param_0)->local_1 == 3) {
            if (func_800D90A4(&local_4->local_1)) {
                f32 local_5;
                ((AlienBlink271 *)param_0)->local_0 = 2;
                local_5 = func_800F10B4(local_0, 0, 1.0f, 0.8f, 0);
                local_4->local_2 = local_5;
                local_4->local_1 = local_5;
            }
        } else {
            ((AlienBlink271 *)param_0)->local_1++;
        }
        break;
    case 2:
        if (func_800D90A4(&local_4->local_1)) {
            f32 local_5;
            ((AlienBlink271 *)param_0)->local_0 = 3;
            local_5 = func_800F10B4(local_0, 0, 1.0f, 0.8f, 0.1f);
            local_4->local_2 = local_5;
            local_4->local_1 = local_5;
        }
        break;
    case 3: {
        s32 local_3;

        /* Keep 0.f distinct: IDO does not intern it with the other zeros. */
        local_3 = func_800F10B4(local_0, 0, 1.0f, 2.0f, 0.f);
        ((AlienBlink271 *)param_0)->local_1 = (u32)func_800F10B4(local_1, 0, 1.0f, (f32)local_3, 3.0f);
        if (local_2) {
            f32 local_5;
            ((AlienBlink271 *)param_0)->local_1 = local_3;
            ((AlienBlink271 *)param_0)->local_0 = 0;
            local_5 = func_800F10B4(local_0, 0, 1.0f, 0.01f, 0.08f);
            local_4->local_2 = local_5;
            local_4->local_1 = local_5;
            if (local_0 == 1.0f) {
                func_80801324_chaliendad(param_0, 0);
            }
        }
        break;
    }
    }
}

int func_80801B9C_chaliendad(s32 param_0)
{
  s32 local_0;
  local_0 = 3;
  _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_80802824_chaliendad, &D_808025C0_chaliendad, local_0);
}

void func_80801BD4_chaliendad(void *param_0)
{
  u8 *local_0;
  local_0 = (u8 *) param_0;
  local_0[0x65] = (((((((((((local_0[0x65] & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) | 1;
  _subaddieDll_entrypoint_4(param_0, 1);
  func_80102424(param_0, 2);
  _subaddiedialog_entrypoint_11(*((void ***) param_0), 0x12B3, 0x44, (void *) (((u8 *) param_0) + 4), 0x62);
  func_80801D40_chaliendad(param_0, 0x22, 0x30, 0);
  local_0 = _subaddiefind_entrypoint_2(0x45B, 0);
  local_0[0x65] = local_0[0x65] & 0xFFFE;
}

int func_80801C60_chaliendad(Actor *param_0)
{
  if ((*(s32 *)((char *)(param_0) + 0x1C)) != 0)
  {
    _capod_entrypoint_3(0, param_0);
    (*(s32 *)((char *)(param_0) + 0x1C)) = 0;
  }
}

void func_80801C9C_chaliendad(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2;
{
    s32 temp_v0;

    temp_v0 = *(s32 *)((u8 *)param_0 + 0x1C);
    switch (temp_v0)
    {
    case 0:
        _capod_entrypoint_2(*(s32 *)param_0, 0xD, 0);

    case 1:
        _capod_entrypoint_8(1);
        *(s32 *)((u8 *)param_0 + 0x1C) = 2;
        _gcdialogcamera_entrypoint_3(&D_808025E4_chaliendad, *(s32 *)((u8 *)param_0 + 0x38));
        _gcdialogcamera_entrypoint_4(param_0 + 4);
        _gcdialogcamera_entrypoint_5(param_0 + 0x44);
        _gcdialogcamera_entrypoint_8();

    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

void func_80801D40_chaliendad(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; s32 param_2; Unk80132ED0 *param_3;
{
    if (param_3 == NULL) {
        param_3 = param_0->unk0;
    }
    switch (param_0->actorData[1]) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 13, param_2);
        case 2:
            param_0->actorData[1] = 1;
        case 1:
            _capod_entrypoint_6(param_3, param_1, param_2);
            break;
    }
}

int func_80801DD0_chaliendad()
{
  s32 local_0;
  s32 local_1 = 0;
  s32 local_2 = 0;
  for (local_0 = 0; local_0 < 3; local_0++)
  {
    if (func_800DA298(local_0 + 0x372))
    {
      local_1++;
    }
  }

  return local_1 | local_2;
}

s32 func_80801E28_chaliendad(s32 param_0) {
    s32 local_0;

    if (!func_80100094(param_0, 1)) {
        local_0 = _suexpression_entrypoint_7(param_0, 1, 0x62);
        _suexpression_entrypoint_12(local_0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(local_0, 0x3E8);
    }
}

void func_80801E80_chaliendad(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80801EB4_chaliendad(Actor *param_0)
{
    f32 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0[2] = param_0->rotation[1];
    if (func_80105494(param_0)) {
        local_0[0] = 100.0f;
        local_0[1] = 100.0f;
        func_80105A9C(param_0, 1200.0f);
        if (func_80801DD0_chaliendad() == 3) {
            func_800FFAB0(param_0);
        }
    } else {
        local_0[1] = 100.0f;
        local_0[0] = 10.0f;
        func_800EE7F8((f32 *)((u8 *)param_0 + 0x28), param_0->position);
        func_800EE7F8((f32 *)((u8 *)param_0 + 0x18), param_0->position);
        *(f32 *)((u8 *)param_0 + 0x1C) = 1000.0f;
        func_80101FDC(param_0, 5);
        param_0->unk58 = 6.0f;
    }
}

void func_80801F98_chaliendad(u8 *param_0)
{
  u32 local_0;
  func_80802218_chaliendad((Actor *)param_0);
 do { local_0 = (u16) (*((u16 *) (((s8 *) param_0) + 0x72))); local_0 = local_0 >> 0xA; switch (local_0) { case 3: break; case 2: func_80105834(param_0); if (func_80105998(param_0, 0x3F4CCCCD) != 0) { func_80102424(param_0, 3); func_80801BD4_chaliendad(_subaddiefind_entrypoint_2(0x45A, 0)); } break; case 4: func_80105834(param_0); if (func_80105A5C(param_0) != 0) { func_800FFAB0(param_0); } break; } } while (0);
  func_80802284_chaliendad(param_0);
}

void func_80802058_chaliendad(Actor *param_0)
{
    s32 local_0;
    f32 local_2;
    s32 local_1;

    func_80802218_chaliendad(param_0);
    switch (param_0->unk70_10) {
        case 6:
            break;
        case 5:
            local_0 = func_800D9078(&param_0->unk58);
            local_2 = func_800F12D4(param_0->unk58, 0.0f, 6.0f, 1.0f, 0.0f);
            func_800EFE50(param_0->position, (f32 *)&param_0->actorData[4], (f32 *)param_0->actorData, local_2);
            if (local_0) {
                func_80101180(0x45A, 0x31, param_0->unk6C_9);
                func_80102424(param_0, 6);
            }
            break;
        case 7:
            local_1 = func_800D9078(&param_0->unk58);
            *(f32 *)&param_0->actorData[3] += func_800D8FF8() * 300.0f;
            param_0->position[1] += *(f32 *)&param_0->actorData[3] * func_800D8FF8();
            if (local_1) {
                func_80101180(0x45A, 0x2C, 0);
                func_800FFAB0(param_0);
            }
            break;
    }
    func_80802284_chaliendad(param_0);
}

void func_80802188_chaliendad(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 *local_1;
    local_1 = func_80100094(param_0, 0);
    func_80101970(param_0);
    func_800EFA4C(local_0, param_0->rotation[0], local_1[2], param_0->rotation[2]);
    func_800DF47C(func_801015D0, param_0);
    func_800DE448(param_0->position, local_0, param_0->scale, func_801018D8(param_0), func_8010347C(param_0->unk0));
}

void func_80802218_chaliendad(param_0) Actor *param_0;
{
    f32 *local_1;
    f32 local_0;
    local_1 = (f32 *)func_80100094(param_0, 0);
    local_0 = func_800D8FF8();
    local_1[1] = func_800F15F8(local_1[1], local_1[0], local_0 * 15.0f);
    local_1[2] += local_1[1] * local_0;
}

void func_80802284_chaliendad(param_0) AlienState *param_0; {
    f32 local_0[3];
    func_80103DFC(param_0, local_0);
    _subaddieaudioloop_entrypoint_4(param_0, local_0, param_0->f72 != 1, D_80802834_chaliendad);
}

void func_808022CC_chaliendad(Actor *param_0)
{
    f32 *local_0;

    local_0 = (f32 *)func_80100094(param_0, 0);
    func_80102424(param_0, 7);
    *(f32 *)&param_0->actorData[3] = 100.0f;
    param_0->unk58 = 5.0f;
    local_0[0] = 100.0f;
    local_0[1] = 10.0f;
}

void func_80802330_chaliendad(void *param_0) {
    *(float *)((char *)param_0 + 0x58) = 0.85f;
}

void func_80802340_chaliendad(Actor *param_0)
{
    s32 local_0;

    _subaddieskeleton_entrypoint_2(param_0->unk3C, 4, param_0->position);
    switch (param_0->unk70_10) {
        case 1:
            local_0 = func_800D9078(&param_0->unk58);
            func_80102FDC(param_0, func_800F12D4(param_0->unk58, 0.0f, 0.85f, 0.2f, 0.08f));
            if (local_0) {
                func_80102424(param_0, 2);
                param_0->unk58 = 2.5f;
            }
            break;
        case 2:
            *(f32 *)((u8 *)param_0 + 0x24) += func_800D8FF8() * 800.0f;
            func_80102FDC(param_0, func_800138D0(*(f32 *)((u8 *)param_0 + 0x24)) * 0.080000006f + 0.2f);
            if (func_800D9078(&param_0->unk58)) {
                func_80102424(param_0, 3);
                _subaddiefade_entrypoint_3(param_0);
            }
            break;
        case 3:
            break;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/aliendad.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_808025C0_chaliendad -> s32[], D_80802674_chaliendad -> u32, D_808026BC_chaliendad -> int[], D_80802704_chaliendad -> int[], D_8080281C_chaliendad -> u32[], D_80802824_chaliendad -> s32[] */
extern int func_80101870();
extern void func_80108ED0();
s32 D_808025C0_chaliendad[6] = { 0x601, -0xFE00, 0x1000, 0x12D50200, -0x12001, 0x120F0300 };
f32 D_808025D8_chaliendad[3] = { 1.5f, 3.0f, 4.5f };
u8 D_808025E4_chaliendad[16] = { 0x43, 0x87, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0, 0x43, 0x34, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0 };
u8 D_808025F4_chaliendad[128] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x50, 0x0, 0x0, 0x3, 0x63, 0x0, 0x2, 0x3F, 0x14, 0x7A, 0xE1, 0x3, 0x64, 0x0, 0x1, 0x3F, 0x14, 0x7A, 0xE1, 0x3, 0x64, 0x0, 0x1, 0x40, 0xBE, 0x66, 0x66, 0x3, 0x65, 0x2, 0x2, 0x40, 0xBE, 0x66, 0x66, 0x3, 0x65, 0x0, 0x84, 0x40, 0xBE, 0x66, 0x66, 0x3, 0x65, 0x0, 0x84, 0x40, 0xD0, 0x0, 0x0, 0x3, 0x66, 0x0, 0x42, 0x40, 0x12, 0x8F, 0x5C, 0x3, 0x67, 0x0, 0x1, 0x40, 0x12, 0x8F, 0x5C, 0x3, 0x67, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x68, 0x0, 0x2, 0x40, 0x12, 0x8F, 0x5C, 0x3, 0x67, 0x0, 0x1, 0x40, 0x56, 0x66, 0x66, 0x3, 0x28, 0x0, 0x2, 0x40, 0x56, 0x66, 0x66, 0x3, 0x28, 0x0, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u32 D_80802674_chaliendad[18] = { 0x158045A, 0x8070009, (u32)&D_808025F4_chaliendad, (u32)func_808000AC_chaliendad, (u32)func_80105834, (u32)func_80800918_chaliendad, 0xBB80000, 0x0, 0x0, 0x40060, (u32)func_808008C8_chaliendad, 0x0, 0x3C0000, (u32)func_80800024_chaliendad, (u32)func_80107C2C, 0x84400412, (u32)func_80800A54_chaliendad, 0x0 };
int D_808026BC_chaliendad[18] = { 0x1580467, 0x7FB0001, 0x0, (u32)func_80802340_chaliendad, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x21004, 0x0, 0x0, 0x0, (u32)func_80802330_chaliendad, (u32)func_80107C2C, -0x7FFFFBFE, 0x0, 0x0 };
int D_80802704_chaliendad[18] = { 0x158045B, 0x6FC0001, 0x0, (u32)func_80802058_chaliendad, (u32)func_80801F98_chaliendad, (u32)func_80802188_chaliendad, 0x0, 0x0, 0x0, 0x1400, 0x0, (u32)func_80108ED0, 0xC0000, (u32)func_80801EB4_chaliendad, (u32)func_80107C2C, -0x7FFFFBFE, 0x0, 0x0 };
u8 D_8080274C_chaliendad[24] = { 0x0, 0x13, 0x3, 0xFF, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x1, 0x3, 0x20, 0x13, 0x88, 0x0, 0x16, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802764_chaliendad[16] = { 0x0, 0x13, 0x4, 0xB5, 0x0, 0xA, 0x0, 0xD9, 0x0, 0x2, 0x0, 0x16, 0x61, 0xA8, 0x0, 0x0 };
u8 D_80802774_chaliendad[16] = { 0x0, 0x13, 0x4, 0xCE, 0x0, 0xA, 0x1, 0x70, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802784_chaliendad[16] = { 0x0, 0x13, 0x4, 0x46, 0x0, 0xA, 0x1, 0x99, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802794_chaliendad[16] = { 0x0, 0x13, 0x5, 0xCC, 0x0, 0xA, 0x1, 0x33, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0 };
u8 D_808027A4_chaliendad[16] = { 0x0, 0x13, 0x5, 0xCD, 0x0, 0xA, 0x1, 0x33, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0 };
u8 D_808027B4_chaliendad[12] = { 0x0, 0x13, 0x5, 0xF0, 0x0, 0x2, 0x0, 0x16, 0x75, 0x30, 0x0, 0x0 };
u8 D_808027C0_chaliendad[12] = { 0x0, 0x13, 0x4, 0x1F, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0 };
u8 D_808027CC_chaliendad[8] = { 0x0, 0x13, 0x4, 0x15, 0x0, 0x2, 0x0, 0x0 };
u8 D_808027D4_chaliendad[40] = { 0x0, 0x1D, 0x8, 0x21, 0x0, 0x16, 0x2, 0x0, 0x0, 0x2B, 0xA, 0x0, 0xA, 0x0, 0x0, 0x22, 0x0, 0xCC, 0x0, 0xCC, 0x3, 0x80, 0x3, 0x80, 0x0, 0x15, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x1E, 0x0, 0x4, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0 };
u8 D_808027FC_chaliendad[12] = { 0x0, 0x13, 0x5, 0xF1, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_80802808_chaliendad[12] = { 0x0, 0x13, 0x5, 0xF1, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_80802814_chaliendad[8] = { 0x0, 0x13, 0x5, 0xEF, 0x0, 0x2, 0x0, 0x0 };
u32 D_8080281C_chaliendad[2] = { 0x13051C, 0x20000 };
s32 D_80802824_chaliendad[4] = { 0x0, 0x1C20062, 0xC, 0x63C0A00 };
u8 D_80802834_chaliendad[28] = { 0x0, 0x13, 0x4, 0xDF, 0x0, 0x16, 0x2E, 0xE0, 0x0, 0x2, 0x0, 0x1, 0x7, 0xD0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
