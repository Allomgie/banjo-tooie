#include "common.h"

extern int D_80801BE0_chsabreman;
extern int D_80801D78_chsabreman;
extern s32 D_80801DC0_chsabreman[];
extern s32 func_800DA564(s32, s32);
extern void func_800FFAB0(s32);
extern void *func_80100094(Actor *, s32);
extern void func_80102FDC(Actor *, f32);
extern void func_801017D0(void);
extern s32 _subaddietaxi_entrypoint_16;
extern void *_gccubesearch_entrypoint_15(s32, s32, f32 *);
extern void func_800EE88C(f32 *, void *);
extern void func_800EE814(void *, void *);
extern s32 func_80102BF8(Actor *, f32, f32, f32);
f32 func_80102D78(Actor *param_0, f32 *param_1);
extern void _sudeflect_entrypoint_0(void *, f32, f32, s32);
extern s32 D_80801BE8_chsabreman;
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_8(s32);
extern void _capod_entrypoint_7(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _gcdialogcamera_entrypoint_4(f32[3]);
extern void _gcdialogcamera_entrypoint_5(f32[3]);
extern void _gcdialogcamera_entrypoint_8(void);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
typedef union { s32 word; void *pointer; } SabremanEventPayload;
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 11; u32 local_0 : 1; u32 pad_2 : 20; } SabremanActorFlags;
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void _subaddiepalette_entrypoint_2(Actor *, void *, s32, f32);
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 26; u32 local_0 : 1; u32 pad_2 : 5; } SabremanSpawnFlags;
extern Actor *func_801084B0(s32, Actor **);
extern void *_chlifeforcespell_entrypoint_1(Actor **, f32 *, s32, f32, s32);
extern f32 func_80101F24(Actor *);
extern s32 func_80102320(Actor *, f32, f32);
extern void func_800DF744(s32, s32);
extern Vec3f D_80801E18_chsabreman;
extern Vec3f D_80801E24_chsabreman;
extern u8 D_80801F98_chsabreman[];
extern u8 D_80801F78_chsabreman[];
extern u8 D_80801F88_chsabreman[];
extern u8 D_80801F44_chsabreman[];
extern u8 D_80801F5C_chsabreman[];
extern u8 D_80801F6C_chsabreman[];
extern u8 D_80801F14_chsabreman[];
extern u8 D_80801F08_chsabreman[];
extern u8 D_80801E9C_chsabreman[];
extern u8 D_80801ED4_chsabreman[];
extern u8 D_80801EC4_chsabreman[];
extern u8 D_80801EFC_chsabreman[];
extern u8 D_80801E60_chsabreman[];
extern u8 D_80801E50_chsabreman[];
extern u8 D_80801E30_chsabreman[];
extern u8 D_80801E40_chsabreman[];
extern u8 D_80801E8C_chsabreman[];
extern u8 D_80801F2C_chsabreman[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
f32 func_8080112C_chsabreman();
void func_80801724_chsabreman();
void func_80800D30_chsabreman();
void func_80801218_chsabreman();

int *chsabreman_entrypoint_0()
{
    return &D_80801BE0_chsabreman;
}

int chsabreman_entrypoint_1()
{
    extern void *D_80801D30_chsabreman;
    return (int)&D_80801D30_chsabreman;
}

int *chsabreman_entrypoint_2()
{
    return &D_80801D78_chsabreman;
}

int chsabreman_entrypoint_3()
{
    return D_80801DC0_chsabreman;
}

void func_808011F8_chsabreman();

int func_80800030_chsabreman(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    func_80102FDC(param_0, 0.45f);
    func_801088A8(param_0, 0x10002000, 0, 0);
    _subaddielink_entrypoint_0(local_0 + 0x810);
    if (_glcutDll_entrypoint_20()) {
        _subaddiepalette_entrypoint_0(param_0, func_80100094(param_0, 0), 0x7F1);
        func_80102424(param_0, 0x19);
        param_0->position[1] = func_8080112C_chsabreman((u8 *)param_0);
        return 1;
    }
    switch (func_800DA564(0x1CA, 2)) {
        case 0:
            func_8010A85C(param_0, 2);
            _subaddiepalette_entrypoint_0(param_0, func_80100094(param_0, 0), 0x7F0);
            func_80108B04(param_0, 0);
            func_808011F8_chsabreman(param_0, 1);
            func_8010A570(param_0);
            *((u8 *)param_0 + 0x75) &= ~0x10;
            break;
        case 1:
            _subaddiepalette_entrypoint_0(param_0, func_80100094(param_0, 0), 0x7F0);
            if (func_800CB3E0(0xB) == 1) {
                func_80108B04(param_0, 0);
            }
            func_808011F8_chsabreman(param_0, 5);
            func_8010A590(param_0);
            param_0->position[1] = func_8080112C_chsabreman((u8 *)param_0);
            break;
        case 2:
            _subaddiepalette_entrypoint_0(param_0, func_80100094(param_0, 0), 0x7F1);
            func_808011F8_chsabreman(param_0, 10);
            func_8010A590(param_0);
            param_0->position[1] = func_8080112C_chsabreman((u8 *)param_0);
            break;
        case 3:
            func_800FFAB0(param_0);
            return 0;
    }
    return 1;
}

void func_808017D8_chsabreman();

s32 func_808011AC_chsabreman();

void func_80800218_chsabreman(Actor *param_0)
{
    extern u8 D_80801E16_chsabreman;
    extern u8 D_80801E08_chsabreman[];
    extern u8 D_80801BF8_chsabreman[];
    extern u8 D_80801C20_chsabreman[];

    u8 *local_0;
    s32 local_2;
    s32 local_3;
    s32 local_5;

    local_0 = (u8 *)func_80100094(param_0, 0);
    local_2 = 2;
    local_3 = 8;

    switch (param_0->unk70_10) {
        case 1:
        case 6:
        case 12:
        case 24:
            break;
        case 2:
            if (func_800D9078(&param_0->unk58)) {
                func_808011F8_chsabreman(param_0, 3);
                func_80101180(0x1FE, 0xA, 0);
                func_8010A85C(param_0, 1);
                ((SabremanActorFlags *)param_0)->local_0 = 1;
            }
            break;

        case 3:
            if (func_80101DDC(param_0)) {
                func_808011F8_chsabreman(param_0, 4);
            }
            break;

        case 4:
            if (func_80101DDC(param_0)) {
                func_80801724_chsabreman(param_0, 3, 1);
                func_8010A590(param_0);

                _subaddiedialog_entrypoint_11(
                    param_0->unk0,
                    0x1271,
                    0xE,
                    param_0->position,
                    0xAA
                );

                func_808011F8_chsabreman(param_0, 6);
                func_800DA7A8(0x1CA, 1, 2);
            }
            break;

        case 5:
            local_3 = 0;
            D_80801E16_chsabreman = 6;

            _subaddiedialog_entrypoint_8(
                param_0,
                param_0->position,
                D_80801E08_chsabreman,
                D_80801BF8_chsabreman,
                5
            );
            break;

        case 7:
            if (func_80101DDC(param_0)) {
                _subaddieDll_entrypoint_4(param_0, 0);

                if (*(s32 *)((u8 *)param_0 + 0x50) >= 3) {
                    func_800F82D4(func_800F54E4(), 0);
                    if (!func_800F6CC8(func_800F54E4())) {
                        local_0 = (u8 *)func_80100094(param_0, 0);

                        _subaddiepalette_entrypoint_2(
                            param_0,
                            local_0,
                            0x7F1,
                            3.0f
                        );

                        func_808011F8_chsabreman(param_0, 8);
                        func_808017D8_chsabreman(param_0, 1, 0x30);
                    } else {
                        func_808011F8_chsabreman(param_0, 5);
                    }
                } else {
                    func_808011F8_chsabreman(param_0, 5);
                }
            }
            break;

        case 8:
            local_0 = (u8 *)func_80100094(param_0, 0);

            if (*(s16 *)(local_0 + 4) == 0) {
                func_808011F8_chsabreman(param_0, 9);
                param_0->unk64_20 = 0;
            }
            break;

        case 9:
            if (func_80101E14(param_0, 0.23f)) {
                func_80101180(0x1FE, 0x48, 3);
                param_0->unk64_20 = 1;
            }

            if (func_80101DDC(param_0)) {
                if (func_800F64A4(func_800F54E4(), 0x400)) {
                    local_5 = 0x12D9;
                } else {
                    local_5 = 0x1273;
                }

                func_808011F8_chsabreman(param_0, 0xB);
                func_800DA7A8(0x1CA, 2, 2);
                func_80801724_chsabreman(param_0, 2, 1);

                _subaddiedialog_entrypoint_11(
                    param_0->unk0,
                    local_5,
                    0xE,
                    param_0->position,
                    0xAA
                );
            }
            break;

        case 10:
            func_808011AC_chsabreman(param_0);
            D_80801E16_chsabreman = 0xB;

            _subaddiedialog_entrypoint_8(
                param_0,
                param_0->position,
                D_80801E08_chsabreman,
                D_80801C20_chsabreman,
                4
            );
            break;

        case 11:
            func_808011AC_chsabreman(param_0);
            break;

        case 13:
            local_2 = 0;
            break;

        case 14:
            local_2 = 0;
            func_808011AC_chsabreman(param_0);

            if (_subaddietaxi_entrypoint_1(param_0, 0xB)) {
                func_808011F8_chsabreman(param_0, 0x11);

                _subaddiedialog_entrypoint_11(
                    param_0->unk0,
                    0x1275,
                    0xE,
                    param_0->position,
                    0xAA
                );

                func_800DA7A8(0x1CA, 3, 2);
            }
            break;

        case 15:
            if (_subaddietaxi_entrypoint_11(param_0, 0xB)) {
                if (_subaddietaxi_entrypoint_5(param_0, 0xB)) {
                    _subaddietaxi_entrypoint_14(param_0, 0xB);
                    func_808011F8_chsabreman(param_0, 0x12);
                    func_8010A590(param_0);
                }
            }

            local_2 = _subaddietaxi_entrypoint_12(param_0, 0xB);
            break;

        case 16:
            func_808011AC_chsabreman(param_0);
            break;

        case 17:
            func_808011AC_chsabreman(param_0);
            break;

        case 18:
            if (_subaddietaxi_entrypoint_15(param_0, 0xB)) {
                func_808011F8_chsabreman(param_0, 0xC);
            }
            break;

        case 19: {
            f32 local_1[3];
            func_800EE88C(
                local_1,
                local_0 + 0x81A
            );

            param_0->unk54 =
                func_80102D78(param_0, local_1);

            func_80102BF8(
                param_0,
                0.1f,
                4.0f,
                150.0f
            );

            if (func_80102CF4(param_0, 8.0f)) {
                func_808011F8_chsabreman(param_0, 0x14);
                *(f32 *)((u8 *)param_0 + 0x24) = 50.0f;
            }
            break;

        }
        case 20: {
            f32 local_7[3];
            func_800EE88C(
                local_7,
                local_0 + 0x81A
            );

            param_0->unk54 =
                func_80102D78(param_0, local_7);

            func_80102BF8(
                param_0,
                0.1f,
                4.0f,
                150.0f
            );

            func_8010B990(param_0, 0x1005);

            if (func_800EEB40(
                    param_0->position,
                    local_7) < 2500.0f) {
                func_808011F8_chsabreman(param_0, 0x15);
            }
            break;

        }
        case 21:
            param_0->unk54 =
                (f32)*(s16 *)(local_0 + 0x818);

            func_80102BF8(
                param_0,
                0.1f,
                4.0f,
                150.0f
            );

            if (func_80102CF4(param_0, 8.0f)) {
                func_808011F8_chsabreman(param_0, 0x16);
            }
            break;

        case 22:
            if (func_80101DDC(param_0)) {
                func_808011F8_chsabreman(param_0, 0x17);
            }
            break;

        case 23:
            if (!func_800C0638()
                && func_800D90A4(&param_0->unk58)
                && func_8010CAC0(param_0->position, 0x190)
                && *(f32 *)(&param_0->unk58) <= 0.0f) {

                _subaddiedialog_entrypoint_11(
                    param_0->unk0,
                    func_800DC128(0, 3) + 0x1293,
                    0,
                    param_0->position,
                    0xAA
                );

                func_80102424(param_0, 0x18);

                *(f32 *)(&param_0->unk58) =
                    func_800DC178(8.0f, 12.0f);
            }
            break;
    }

    _subaddietaxi_entrypoint_9(param_0, 0xB);

    local_0 = (u8 *)func_80100094(param_0, 0);
    _subaddiepalette_entrypoint_1(param_0, local_0);

    func_80801218_chsabreman(param_0);

    if ((local_2 | local_3) != 0) {
        f32 local_8[3];
        if (_subaddieskeleton_entrypoint_0(param_0, 1, local_8)) {
            _sudeflect_entrypoint_0(local_8, 0.0f, 90.0f, local_2 | local_3);
        }
    }
}

void func_808016E4_chsabreman();

s32 func_8080167C_chsabreman();

void func_80801010_chsabreman();

s32 func_808008C8_chsabreman(Actor *param_0, s32 param_1, s32 param_2)
{
    extern s32 D_80801BE8_chsabreman;
    extern void _chsabreman_entrypoint_0(void);
    u8 *local_0;
    Actor *local_1;

    switch (param_1) {
        case 0x3E:
            if (func_800DA564(0x1CA, 2) == 2) {
                if (_subaddietaxi_entrypoint_2(param_0, 0xB)) {
                    func_808011F8_chsabreman(param_0, 0xD);
                }
            }

            break;


        case 0x40:
            if (func_800DA564(0x1CA, 2) == 1) {
                if (param_0->unk70_10 == 5) {
                    func_800FC660(0xE);
                    func_808011F8_chsabreman(param_0, 7);
                    _subaddieDll_entrypoint_4(param_0, 1);

                    ++*(s32 *)((u8 *)param_0 + 0x50);

                    if (*(s32 *)((u8 *)param_0 + 0x50) == 3) {
                        func_800F8300(
                            func_800F54E4(),
                            2,
                            param_0->position
                        );
                    }
                }
            }

            break;


        case 0x3D:
            local_0 = (u8 *)func_80100094(param_0, 0);

            switch (param_2) {
                case 0:
                    local_1 = func_801084B0(
                        0x1FE,
                        &param_0
                    );

                    _subaddielink_entrypoint_1(
                        local_0 + 0x810,
                        local_1->unk0
                    );

                    func_80102FDC(
                        local_1,
                        param_0->scale
                    );

                    local_1->unk3C = param_0->unk0;
                    break;

                case 1:
                    param_0->unk3C =
                        _chlifeforcespell_entrypoint_1(
                            &param_0,
                            param_0->position,
                            0x64,
                            4.0f,
                            0x12
                        );

                    func_808017D8_chsabreman(
                        param_0,
                        0x1B,
                        0x30
                    );
                    break;
            }

            break;


        case 0x2E:
            switch (param_0->unk70_10) {
                case 6:
                    func_808016E4_chsabreman(param_0);
                    func_808011F8_chsabreman(param_0, 5);
                    _subaddieDll_entrypoint_4(param_0, 0);
                    break;

                case 0x0B:
                    func_808016E4_chsabreman(param_0);
                    func_808011F8_chsabreman(param_0, 0xA);
                    break;

                case 0x18:
                    func_808011F8_chsabreman(param_0, 0x17);
                    break;
            }

            if (((s16 *)&param_2)[0] == 0x1275) {
                func_800C01A8(0x64, 0);

                func_808017D8_chsabreman(
                    param_0,
                    8,
                    0x2030
                );

                func_800D1000(
                    0x3F,
                    1,
                    0,
                    1,
                    0
                );
            }

            break;


        case 0x0B:
            if (param_2 == 8) {
                func_808016E4_chsabreman(param_0);
                func_808011F8_chsabreman(param_0, 0x13);
                return 4;
            }

            return 3;


        case 0x44:
            func_80801010_chsabreman(param_0, param_2);
            break;


        case 0x4B:
            func_80108B04(param_0, 1);
            _subaddieDll_entrypoint_4(param_0, 1);
            func_808011F8_chsabreman(param_0, 2);
            param_0->unk58 = 14.0f;
            break;


        case 0x4C:
            param_0->unk3C = 0;
            break;


        case 0x52:
            _gcdialogcamera_entrypoint_3(
                &D_80801BE8_chsabreman,
                param_0->scale
            );
            break;


        case 0x1F:
            func_80800D30_chsabreman(param_0, param_2);
            break;


        case 0x57:
            return func_8080167C_chsabreman(
                param_0,
                param_2 & 0xFFFF,
                (param_2 & 0xFFFF0000) >> 16
            );


        case 0x95:
            *(s32 *)((char *)param_0 + 0x50) = 0;

            if (_glcutDll_entrypoint_20()
                || _subaddietaxi_entrypoint_13(
                    param_0,
                    0xB,
                    _chsabreman_entrypoint_0,
                    3)) {
                func_80800030_chsabreman(param_0);
            } else if (((SabremanSpawnFlags *)param_0)->local_0) {
                func_800FFAB0(param_0);
            }

            break;

        case 0x29:
            local_0 = (u8 *)func_80100094(param_0, 0);
            _subaddiepalette_entrypoint_4(param_0, local_0);
            break;


        default:
            return 0;
    }
    return 1;
}

void func_80800CDC_chsabreman(s32 param_0, s32 param_1)
{
  s32 local_0;
  if (func_80101808(param_0, &func_801017D0))
  {
    local_0 = _subaddielink_entrypoint_4((u8 *)func_80100094(param_0, 0) + 0x810);
    if (local_0 != 0)
    {
      func_8010A764(local_0, param_1);
    }
  }
}

void func_80800D30_chsabreman(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_0 = func_801022E4(param_0);
    if (param_0->unk3C) {
        _subaddiefade_entrypoint_9(param_0, local_2);
        _chlifeforcespell_entrypoint_2(param_0, param_0->unk3C, local_1);
        _subaddiefade_entrypoint_11(param_0, local_1);
        func_801015D0(param_0);
        _subaddiefade_entrypoint_11(param_0, local_2);
    } else {
        func_801015D0(param_0);
    }
    switch (local_0) {
    case 0x2FB:
        if (func_80101F24(param_0) < 0.602f) local_3 = 1;
        else local_3 = 0;
        local_4 = func_80102320(param_0, 0.602f, 0.819f);
        func_800DF744(5, 1);
        func_800DF744(3, 0);
        func_800DF744(6, local_3 && param_0->unk64_20);
        func_800DF744(4, local_4);
        break;
    case 0x2FA:
        local_5 = func_80102320(param_0, 0.33f, 0.93f);
        func_800DF744(5, !local_5);
        func_800DF744(3, local_5);
        func_800DF744(6, 0);
        func_800DF744(4, 0);
        break;
    default:
        func_800DF744(5, 1);
        func_800DF744(3, 0);
        func_800DF744(6, 0);
        func_800DF744(4, 0);
        break;
    }
    _subaddiepalette_entrypoint_3(param_0, func_80100094(param_0, 0), param_1);
}

void func_80800F04_chsabreman(s32 param_0, u8 *param_1, s32 param_2, s32 param_3) {
    if (func_800DA564(0x1CA, 2) != 3) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0, (*(s32 *)((s8 *)(param_1) + (0))), (*(s32 *)((s8 *)(param_1) + (4))), (*(s32 *)((s8 *)(param_1) + (8))), param_2, param_3);
    }
}

s32 func_80800F74_chsabreman(s32 param_0, s32 param_1, s32 param_2)
{
    s32 temp_v0;
    s32 sp28;

    if (func_800EA05C() == 0x127)
    {
        temp_v0 = _gccubesearch_entrypoint_15(0x154, 0, param_1);
        if (temp_v0 != 0)
        {
            func_800EE88C(param_2, temp_v0);
            sp28 = func_800CBC3C(param_2);
            if (func_800CBC3C(param_1) == sp28)
            {
                return 2;
            }
        }
    }
    func_800C05B8(0x1276, 1, 0, 0, 0, 0, 0);
    return 1;
}

void func_80801010_chsabreman(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    f32 local_1[3];
    u8 *local_2;
    local_0 = func_80100094(param_0, 0);
    if (func_80800030_chsabreman(param_0)) {
        switch (func_800CB3E0(param_1)) {
        case 1:
            break;
        case 3:
            _subaddietaxi_entrypoint_10(param_0, param_1, 15);
            break;
        case 4:
            func_800EE88C(local_1, _gccubesearch_entrypoint_15(0x154, 0, param_0->position));
            local_2 = _gccubesearch_entrypoint_15(0x347, 0, param_0->position);
            func_800EE814(local_0 + 0x81A, local_2);
            *(s16 *)(local_0 + 0x818) = *(u32 *)(local_2 + 0xC) >> 23;
            func_8010A570(param_0);
            _subaddietaxi_entrypoint_0(param_0, param_1, local_1, 14);
            break;
        case 6:
            func_808011F8_chsabreman(param_0, 16);
            func_8010A570(param_0);
            break;
        }
    }
}

f32 func_8080112C_chsabreman(param_0) u8 *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    func_800EE7F8(local_0, param_0 + 4);
    func_800EE7F8(local_1, param_0 + 4);
    local_0[1] += 100.0f;
    local_1[1] -= 400.0f;
    func_800BEF00(local_0, local_1, local_2, *(s32 **)(param_0 + 0x14));
    return local_1[1];
}

s32 func_808011AC_chsabreman(Actor *this) {
    f32 sp1C[3];

    func_8010D600(sp1C);
    *(f32 *)((char *)this + 0x54) = func_80102D78(this, sp1C);
    return func_80102BF8(this, 0.1f, 4.0f, 150.0f);
}

void func_808011F8_chsabreman()
{
    func_80102424();
}

void func_80801218_chsabreman(param_0) Actor *param_0;
{
    Vec3f local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    Vec3f local_4;

    switch (func_801022E4(param_0)) {
    case 0x2F7:
        local_0 = D_80801E18_chsabreman;
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801E30_chsabreman, local_0.f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801E40_chsabreman, 0.2f);
        return;
    case 0x2F9:
        if (func_80101E14(param_0, 0.02f)) {
            if (_subaddieskeleton_entrypoint_2(param_0->unk0, 5, local_1)) {
                func_800EE7F8(local_2, local_1);
                func_800EF1B8(local_2, param_0->rotation[1], -50.0f);
                local_2[1] += 30.0f;
                func_800BABB8(0, local_1, local_2, 1.0f, D_80801E60_chsabreman);
            }
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801E50_chsabreman);
        }
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801E8C_chsabreman, D_80801E9C_chsabreman);
        return;
    case 0x2FA:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801EC4_chsabreman, 0.0f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801E30_chsabreman, 0.75f);
        if (func_80101F24(param_0) < 0.7f && func_8001210C(1) && _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_3)) {
            func_800BBCB8(local_3, 0, 1.0f, 1, D_80801ED4_chsabreman);
            return;
        }
        return;
    case 0x2FB:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801EFC_chsabreman, 0.6f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801F08_chsabreman, 0.8f);
        return;
    case 0x2FC:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801F14_chsabreman, 0.025f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801F2C_chsabreman, 0.12f);
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801F44_chsabreman, D_80801F5C_chsabreman);
        return;
    case 0x2FD:
        local_4 = D_80801E24_chsabreman;
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801E30_chsabreman, local_4.f);
        return;
    case 0x2FE:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801F6C_chsabreman, 0.8f);
        return;
    case 0x2FF:
        if (!param_0->unk5F) {
            param_0->unk5F = func_800C4350(0, param_0->position, D_80801F78_chsabreman);
        }
        if (param_0->unk5F) {
            if (func_80101E14(param_0, 0.0f)) {
                func_800C4350(param_0->unk5F, param_0->position, D_80801F88_chsabreman);
            }
            if (func_80101E14(param_0, 0.65f)) {
                func_800C4350(param_0->unk5F, param_0->position, D_80801F98_chsabreman);
            }
        }
        break;
    }
}

void func_8080158C_chsabreman(s32 param_0) {
    func_80102FDC((Actor *)param_0, 0.45f);
    if (func_800DA564(0x1CA, 2) != 3) {
        func_800FFAB0(param_0);
    }
}

void func_808015D4_chsabreman(Actor *param_0)
{
  s8 _sfpad[8];
    s32 local_0;

    if (_subaddieskeleton_entrypoint_0(param_0, 1, &local_0) != 0) {
        _sudeflect_entrypoint_0((u8 *)param_0 + 4, 0.0f, 100.0f, 0xA);
    }
    func_80801218_chsabreman(param_0);
}

s32 func_80801620_chsabreman(s32 param_0, s32 param_1) {
    func_800DF744(5, 1);
    func_800DF744(3, 0);
    func_800DF744(6, 0);
    func_800DF744(4, 0);
    func_80101870(param_0, param_1);
}

s32 func_8080167C_chsabreman(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    if (_gcdialogcamera_entrypoint_0(param_1, param_2)) {
        local_0 = func_80100094(param_0, 0);
        if (local_0 != NULL && *(s16 *)(local_0 + 0x820) != 2) {
            func_80801724_chsabreman(param_0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808016E4_chsabreman(s32 param_0) {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if ((*(s16 *)((s8 *)(sp1C) + (0x820))) != 0) {
        _capod_entrypoint_3(0);
        (*(s16 *)((s8 *)(sp1C) + (0x820))) = 0;
    }
}

void func_80801724_chsabreman(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (*(s16 *)(local_0 + 0x820)) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 14, 0);
        case 1:
            _capod_entrypoint_8(1);
            *(s16 *)(local_0 + 0x820) = 2;
            _gcdialogcamera_entrypoint_3(&D_80801BE8_chsabreman, param_0->scale);
            _gcdialogcamera_entrypoint_4(param_0->position);
            _gcdialogcamera_entrypoint_5(param_0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(param_1, param_2);
            return;
    }
}

void func_808017D8_chsabreman(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (*(s16 *)(local_0 + 0x820)) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 14, param_2);
        case 2:
            *(s16 *)(local_0 + 0x820) = 1;
        case 1:
            _capod_entrypoint_6(param_0->unk0, param_1, param_2);
            return;
    }
}

void func_80801864_chsabreman(u8 *param_0)
{
  if (func_800DA564(0x1CA, 2) > 0)
  {
    func_80102424(param_0, 3);
    func_80103110(param_0, 0);
  }
  if (func_800DA564(0x1CA, 2) >= 2)
  {
    param_0[0x65] = (param_0[0x65] & 0xFF) | 0x10;
  }
  func_8010A800(param_0, 2);
}

void func_808018DC_chsabreman(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 2:
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
            func_80103110(param_0, 0);
        }
        break;
    case 3:
        break;
    }
}

void func_8080193C_chsabreman(Actor *param_0, s32 param_1)
{
    func_800DF744(3, param_0->unk64_20 ? 0 : 1);
    func_800DF744(4, 1);
    func_800DF744(5, 1);
    func_80101870(param_0, param_1);
}

s32 func_808019A4_chsabreman(Actor *param_0, s32 param_1, SabremanEventPayload param_2)
{
    switch (param_1) {
    case 0xA:
        func_80102424(param_0, 2);
        break;
    case 0x48:
        param_0->unk64_20 = 1;
        break;
    default:
        return 0;
    }
    return 1;
}
