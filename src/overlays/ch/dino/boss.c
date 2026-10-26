#include "common.h"
extern void func_800F4F34(s32, f32 *, f32, f32);

#define R32(o) (*(s32 *)((u8 *)rec + (o)))
#define RF(o) (*(f32 *)((u8 *)rec + (o)))
#define R16(o) (*(s16 *)((u8 *)rec + (o)))
#define RU8(o) (*(u8 *)((u8 *)rec + (o)))
extern int D_80802B40_chdinoboss;
extern void *D_80802B88_chdinoboss;
extern void *func_80100094(Actor *, u32);
extern void func_80102FDC(Actor *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800DA564(s32, s32);
typedef struct { u8 pad_0[0x11E]; s16 count; } DinoBossHits;
typedef struct { u8 pad_0[0x110]; f32 local_0[3]; u8 pad_1[8]; f32 local_1; u32 local_2 : 1; u32 pad_2 : 31; f32 local_3; f32 local_4; f32 local_5; } CodexDinoPose;
extern f32 func_800136E4(f32);
extern s32 func_800DC298(f32);
extern f32 func_80013728(f32);
extern f32 func_800EEF94();
extern void func_800EEC30(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
extern u8 D_80802A2C_chdinoboss[];
extern u8 D_80802A48_chdinoboss[];
extern u8 D_80802BEC_chdinoboss[];
extern u8 D_80802BF4_chdinoboss[];
extern u8 D_80802C04_chdinoboss[];
extern u8 D_80802C14_chdinoboss[];
extern u8 D_80802C28_chdinoboss[];
extern u8 D_80802C34_chdinoboss[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern u32 D_80802C40_chdinoboss;
extern void *D_80802C4C_chdinoboss;
extern int D_80802C68_chdinoboss;
extern int D_80802C78_chdinoboss;
extern int D_80802C88_chdinoboss;
extern s32 D_80802C98_chdinoboss;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern f32 func_800DC178(f32, f32);
extern void func_8010D09C(s32, f32 *, f32);
extern void func_800EFD24(f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct { u8 pad_0[0x138]; s16 local_0; u8 pad_1[0x26]; f32 local_1; u8 pad_2[8]; f32 local_2[3]; } DinoBossCameraState;
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct { u8 pad_0[0x138]; s16 local_0; s16 local_1; s16 local_2; s16 local_3; f32 local_4; f32 local_5; f32 local_6[3]; f32 local_7[3]; f32 local_8; s16 local_9; u8 pad_1[2]; f32 local_10; f32 local_11[3]; } DinoCamera441;
extern f32 func_800F1DCC(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern u8 unk12A_11[];
extern s32 func_800D9078();
extern void func_80108B04();
extern s32 D_80802CA8_chdinoboss;
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1F38(f32, f32, f32);
extern f32 func_800F2094(f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_80102CF4(Actor *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void _subaddiemulti_entrypoint_6(f32 *, f32);
typedef struct { u8 pad[0x128]; u32 f31 : 1; u32 f30 : 1; u32 f29 : 1; u32 f28 : 1; u32 f27 : 1; u32 rest : 27; } DinoR128;
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct { s16 local_0; s16 local_1; f32 local_2[20][3]; s16 local_3[22]; s32 local_4; } DinoRouteData;
s32 func_80800E2C_chdinoboss();
void func_80801A44_chdinoboss();
void func_8080232C_chdinoboss();
void func_8080248C_chdinoboss();
void func_80800F70_chdinoboss();
void func_80801408_chdinoboss();
void func_80801AE4_chdinoboss();
f32 func_80801C84_chdinoboss();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(), func_80800018_chdinoboss(), func_80800220_chdinoboss();
extern u8 D_80802A68_chdinoboss[];

int chdinoboss_entrypoint_0()
{
    return (int)&D_80802B40_chdinoboss;
}

int chdinoboss_entrypoint_1()
{
  return &D_80802B88_chdinoboss;
}

void func_80800018_chdinoboss(param_0) Actor *param_0;
{
    void **local_2;
    u8 *local_3;
    void *local_0[18];
    u8 *local_4;
    s32 local_1;
    f32 *local_5;

    local_4 = func_80100094(param_0, 0);
    func_80102FDC(param_0, param_0->scale * 1.25f);
    local_5 = param_0->position;
    func_800EE7F8((f32 *)(local_4 + 0x104), local_5);
    *(s16 *)(local_4 + 0x138) = 0;
    *(s16 *)(local_4 + 0x164) = 1;
    func_800DA524(1);
    param_0->pad5E = 30;
    *(s16 *)(local_4 + 0x11C) = param_0->pad5E;
    *(s16 *)(local_4 + 0x138) = 0;
    func_80109EEC(param_0, 0x40);
    func_80109FE8(param_0, 0);
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 0x1A);
    } else if (func_800D395C()) {
        if (func_800DA298(0x172)) {
            func_8080248C_chdinoboss(param_0, 0xD, 0x30);
            func_80800F70_chdinoboss(param_0, 3);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1801, 6, local_5, 0x57);
        } else {
            func_8080248C_chdinoboss(param_0, 0x28, 0x30);
            func_80800F70_chdinoboss(param_0, 2);
        }
    } else if (func_800DA298(0xE5)) {
        func_80101FDC(param_0, 0x14);
        func_80109EEC(param_0, 1);
        if (func_80800E2C_chdinoboss() == 4) {
            func_80101FDC(param_0, 0x18);
        }
    }
    if (!func_800D395C() && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
    }
    *(s16 *)local_4 = _gccubesearch_entrypoint_9(0x154, local_0, 20);
    local_1 = 0;
    local_3 = local_4 + 4;
    local_2 = local_0;
    if (*(s16 *)local_4 > 0) {
        do {
            func_800EE88C(local_3, *local_2);
            local_3 += 12;
            local_1++;
            local_2++;
        } while (local_1 < *(s16 *)local_4);
    }
}




































void func_80802540_chdinoboss();

void func_80802500_chdinoboss();

void func_80801DC8_chdinoboss();

void func_80801D08_chdinoboss();

void func_80801CDC_chdinoboss();

u8 func_80801C28_chdinoboss();

void func_80801830_chdinoboss();

void func_80801800_chdinoboss();

void func_808017D0_chdinoboss();

void func_808017A0_chdinoboss();

void func_808016C0_chdinoboss();

void func_80801660_chdinoboss(s32 param_0, f32 param_1, f32 param_2);

void func_80800220_chdinoboss(param_0) Actor *param_0;
{
    extern u8 D_80802A2C_chdinoboss[];
    extern u8 D_80802A34_chdinoboss[];
    extern u8 D_80802A58_chdinoboss[];
    extern u8 D_80802A68_chdinoboss[];
    extern f32 D_80802A20_chdinoboss[];
    extern u8 D_80802BD0_chdinoboss[];

    char *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_7;
    f32 local_4;
    f32 local_5;
    s32 local_6;
    f32 local_8;
    f32 local_9;
    s32 local_10;
    f32 local_11;
    f32 local_3[3];
    f32 local_12[3];

    local_0 = (char *)func_80100094(param_0, 0);

    if (func_800DA298(1)) {
        func_80801CDC_chdinoboss(param_0);
    }

    switch (param_0->unk70_10) {
        case 1:
            _subaddieskeleton_entrypoint_2(
                *(s32 *)((char *)param_0 + 0),
                4,
                local_0 + 0x110
            );

            func_800EFD24(local_1);
            local_1[1] = *(f32 *)((char *)param_0 + 8);

            if (func_8010C9B0(local_1, 0x6D6) &&
                func_800F64A4(func_800F54E4(), 1)) {
                func_8010D254(local_2);

                if (local_2[2] < 1000.0f) {
                    if (func_800DA298(0x172)) {
                        func_8080248C_chdinoboss(
                            param_0,
                            0xD,
                            0x30
                        );

                        _subaddiedialog_entrypoint_11(
                            *(s32 *)((char *)param_0 + 0),
                            0x1801,
                            6,
                            (char *)param_0 + 4,
                            0x57
                        );

                        func_80800F70_chdinoboss(param_0, 3);
                    } else {
                        func_8080248C_chdinoboss(
                            param_0,
                            0x28,
                            0x30
                        );

                        func_80800F70_chdinoboss(param_0, 2);
                    }

                    func_80101180(0x461, 8, 0);
                }
            }

            func_808016C0_chdinoboss(param_0);
            break;

        case 2:
        case 3:
            _subaddieskeleton_entrypoint_2(
                *(s32 *)((char *)param_0 + 0),
                4,
                local_0 + 0x110
            );

            func_808016C0_chdinoboss(param_0);
            break;

        case 4:
            func_808016C0_chdinoboss(param_0);

            if (func_800D9078((char *)param_0 + 0x58)) {
                func_800FDC28(6);
                func_80800F70_chdinoboss(param_0, 5);
            }
            break;

        case 5:
            func_808017A0_chdinoboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80800F70_chdinoboss(param_0, 6);
            }
            break;

        case 6:
            if (!func_800DA298(0x6AD)) {
                func_80802500_chdinoboss(param_0);
                func_80800F70_chdinoboss(param_0, 7);

                *(s32 *)(local_0 + 0x120) =
                    func_80801C28_chdinoboss(param_0);

                func_800DA544(0x172);
                _gcfrontend_entrypoint_9(0x27);
            }

            func_80801660_chdinoboss(
                param_0,
                0.0f,
                0.0f
            );

            func_80801D08_chdinoboss(param_0, 2);
            func_808017D0_chdinoboss(param_0);
            break;

        case 7:
            func_80801D08_chdinoboss(param_0, 2);
            func_808017D0_chdinoboss(param_0);

            if (func_800D9078((char *)param_0 + 0x58)) {
                func_80800F70_chdinoboss(param_0, 8);
            }
            break;

        case 8:
            func_80801D08_chdinoboss(param_0, 2);

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802A34_chdinoboss,
                0.65f
            );

            if (func_80101E14(param_0, 0.7f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101DDC(param_0)) {
                if (*(s32 *)(local_0 + 0x120) > 0) {
                    func_80800F70_chdinoboss(param_0, 7);

                    *(f32 *)((char *)param_0 + 0x58) =
                        func_80801C84_chdinoboss(param_0);
                } else {
                    func_80800F70_chdinoboss(param_0, 9);
                }
            }
            break;

        case 9:
            func_80801D08_chdinoboss(param_0, 2);
            func_808017D0_chdinoboss(param_0);

            if (!_subaddiefind_entrypoint_2(0x398, 0) &&
                func_800D9078((char *)param_0 + 0x58)) {
                func_80800F70_chdinoboss(param_0, 0xA);
                *(f32 *)((char *)param_0 + 0x58) = 12.0f;
            }
            break;

        case 10:
            local_7 = func_800D8FF8();

            *(f32 *)(local_0 + 0x130) =
                func_800136E4(
                    *(f32 *)(local_0 + 0x130) +
                    local_7 * 16.0f
                );

            func_80801660_chdinoboss(
                param_0,
                0.0f,
                0.0f
            );

            func_80801D08_chdinoboss(param_0, 1);
            func_80801800_chdinoboss(param_0);

            if (func_800D9078((char *)param_0 + 0x58)) {
                if (*(s16 *)(local_0 + 0x11E) == 0) {
                    func_80800F70_chdinoboss(param_0, 7);

                    *(s32 *)(local_0 + 0x120) =
                        func_80801C28_chdinoboss(param_0);
                } else {
                    func_80800F70_chdinoboss(param_0, 0xB);
                }
            }
            break;

        case 11:
            func_80801D08_chdinoboss(param_0, 0);
            func_808017D0_chdinoboss(param_0);

            if (func_800D9078((char *)param_0 + 0x58)) {
                func_80800F70_chdinoboss(param_0, 0xC);
            }
            break;

        case 12:
            func_80801D08_chdinoboss(param_0, 0);

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802A34_chdinoboss,
                0.65f
            );

            if (func_80101E14(param_0, 0.7f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101DDC(param_0)) {
                if (*(s32 *)(local_0 + 0x120) > 0) {
                    func_80800F70_chdinoboss(param_0, 0xC);

                    *(f32 *)((char *)param_0 + 0x58) =
                        func_800DC178(0.5f, 1.0f);
                } else {
                    func_80800F70_chdinoboss(param_0, 0xD);
                }
            }
            break;

        case 13:
            local_6 =
                func_800D9078((char *)param_0 + 0x58);

            local_4 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x58),
                0.0f,
                4.0f,
                -70.0f,
                0.0f
            );

            local_5 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x58),
                0.0f,
                4.0f,
                6500.0f,
                0.0f
            );

            func_80801660_chdinoboss(
                param_0,
                local_4,
                local_5
            );

            func_80801D08_chdinoboss(param_0, 0);
            func_808017D0_chdinoboss(param_0);

            if (local_6) {
                func_80800F70_chdinoboss(param_0, 0xE);
                func_800DA544(0);
            }
            break;

        case 14:
            func_80801D08_chdinoboss(param_0, 0);

            if (!_subaddiefind_entrypoint_2(0x399, 0) &&
                func_800D90A4((char *)param_0 + 0x58)) {
                func_80800F70_chdinoboss(param_0, 0xF);
                func_800DA524(0);
            }
            break;

        case 15:
            local_10 =
                func_800D9078((char *)param_0 + 0x58);

            local_8 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x58),
                0.0f,
                4.0f,
                0.0f,
                -70.0f
            );

            local_9 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x58),
                0.0f,
                4.0f,
                0.0f,
                6500.0f
            );

            func_80801660_chdinoboss(
                param_0,
                local_8,
                local_9
            );

            func_80801D08_chdinoboss(param_0, 0);
            func_808017D0_chdinoboss(param_0);

            if (local_10) {
                func_80800F70_chdinoboss(param_0, 7);

                *(s32 *)(local_0 + 0x120) =
                    func_80801C28_chdinoboss(param_0);
            }
            break;

        case 16:
            local_11 = func_800D8FF8();

            *(f32 *)(local_0 + 0x130) =
                func_800F1F38(
                    *(f32 *)(local_0 + 0x130),
                    *(f32 *)(local_0 + 0x124),
                    25.0f * local_11
                );

            func_80801660_chdinoboss(
                param_0,
                0.0f,
                0.0f
            );

            func_80801D08_chdinoboss(param_0, 0);
            func_80801830_chdinoboss(param_0);

            if (func_800F2094(
                    *(f32 *)(local_0 + 0x130),
                    *(f32 *)(local_0 + 0x124)) < 1.5f &&
                func_80102CF4(param_0, 4.0f)) {
                *(f32 *)((char *)param_0 + 0x48) =
                    *(f32 *)((char *)param_0 + 0x54);

                func_80800F70_chdinoboss(param_0, 0x11);
                func_8080248C_chdinoboss(
                    param_0,
                    0xA,
                    0x30
                );
            }
            break;

        case 17:
            if (_subaddieaudioquick_entrypoint_3(
                    param_0,
                    (char *)param_0 + 4,
                    D_80802A2C_chdinoboss,
                    0.35f)) {
                func_800E15CC(
                    0,
                    30.0f,
                    0.9f
                );

                func_80018820(
                    0,
                    2.0f,
                    0.45f
                );
            }

            if (func_80101DDC(param_0)) {
                func_80800F70_chdinoboss(param_0, 0x12);
            }
            break;

        case 18:
            if (func_800D9078((char *)param_0 + 0x58)) {
                if (func_800D395C()) {
                    func_80802500_chdinoboss(param_0);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_80800F70_chdinoboss(param_0, 0x13);
                }
            }

            func_80801860_chdinoboss(param_0);
            break;

        case 19:
            func_80801860_chdinoboss(param_0);

            if (!func_800C9510()) {
                *(u16 *)(D_80802A68_chdinoboss + 0xAE) |=
                    0x200;

                func_80800F70_chdinoboss(param_0, 0x15);

                *(u16 *)(D_80802A68_chdinoboss + 0xAE) &=
                    0xFDFF;

                func_8080248C_chdinoboss(
                    param_0,
                    0x13,
                    0x20
                );

                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x17B6,
                    0xE,
                    (char *)param_0 + 4,
                    0x57
                );

                func_800EFD24(local_3);

                local_3[1] =
                    func_800F1DF4(
                        D_80802A20_chdinoboss,
                        (char *)param_0 + 4
                    );

                func_800907C0(D_80802A20_chdinoboss);
                func_800906DC(local_3);
                func_800C964C(4);
            }
            break;

        case 20:
            if (_subaddiedialog_entrypoint_7(
                    param_0,
                    (char *)param_0 + 4,
                    D_80802BD0_chdinoboss)) {
                _capod_entrypoint_13(
                    *(s32 *)((char *)param_0 + 0),
                    0,
                    0x27,
                    0x20
                );
            }

            func_808018D0_chdinoboss(param_0);
            func_80802540_chdinoboss(param_0);
            break;

        case 21:
            func_808018D0_chdinoboss(param_0);
            func_80802540_chdinoboss(param_0);
            break;

        case 22:
            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802A58_chdinoboss,
                0.45f
            );

            if (func_80101DDC(param_0)) {
                if (*(s16 *)(local_0 + 0x11E) == 3) {
                    func_80800F70_chdinoboss(param_0, 0xB);
                } else {
                    func_80800F70_chdinoboss(param_0, 0xA);
                }
            }
            break;

        case 23:
            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802A58_chdinoboss,
                0.45f
            );

            if (func_80101DDC(param_0)) {
                func_80800F70_chdinoboss(param_0, 0x10);
            }
            break;

        case 24:
            func_80802540_chdinoboss(param_0);
            func_808016C0_chdinoboss(param_0);
            break;

        case 25:
            func_80801D08_chdinoboss(param_0, 0);
            func_808017D0_chdinoboss(param_0);
            break;

        case 26:
            func_808016C0_chdinoboss(param_0);
            break;
    }

    func_80801DC8_chdinoboss(param_0);

    switch (func_801022E4(param_0)) {
        case 0x163:
        case 0x1C1:
        case 0x1F7:
            if (!func_800D395C()) {
                break;
            }
        default:
        func_800EFD24(local_12);
        _subaddiemulti_entrypoint_6(
            local_12,
            3062500.0f
        );
    }
}

void func_80801900_chdinoboss();

s32 func_80800F28_chdinoboss();

void func_80800E88_chdinoboss();

s32 func_80800C50_chdinoboss(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3F:
        func_80800E88_chdinoboss(param_0, param_2);
        return 1;
    case 0x40:
        func_80800F28_chdinoboss(param_0, param_2);
        return 1;
    case 0xB:
        switch (param_2) {
        case 11:
            func_80802500_chdinoboss(param_0);
            _glcutDll_entrypoint_6(0x112, 0x33);
            return 4;
        case 40:
            func_8080248C_chdinoboss(param_0, 1, 0x30);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17B3, 6, param_0->position, 0x57);
            func_80800F70_chdinoboss(param_0, 3);
            return 4;
        }
        return 3;
    case 0x2E:
        func_80801408_chdinoboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x31:
        func_8080248C_chdinoboss(param_0, 0x1B, 0x30);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x17DF, 6, param_0->position, 0x57);
        return 1;
    case 0x3D:
        func_80801900_chdinoboss(param_0);
        return 1;
    case 0x96:
        if (!func_800D395C()) return 0;
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x4E, param_0->position, 0x57);
        return 1;
    default:
        return 0;
    case 0x9F:
        func_800FDC28(0);
        func_80800F70_chdinoboss(param_0, 0x19);
        return 1;
    }
}

s32 func_80800E2C_chdinoboss(void) {
    s32 local_0 = 0;
    s32 local_1 = func_800DA564(0x175, 4);
    if (local_1 & 1) {
        local_0++;
    }
    if (local_1 & 2) {
        local_0++;
    }
    if (local_1 & 4) {
        local_0++;
    }
    if (local_1 & 8) {
        local_0++;
    }
    return local_0;
}

void func_80800E88_chdinoboss(Actor *param_0, s32 param_1)
{
    DinoBossHits *local_0;
    local_0 = func_80100094(param_0, 0);
    if (!func_800DA298(0xE5) && param_0->unk70_10 == 0xA) {
        local_0->count++;
        if (local_0->count == 3) func_80109FE8(param_0, 0);
        if (param_0->unk70_10 != 0x16) func_80800F70_chdinoboss(param_0, 0x16);
    }
}

s32 func_80800F28_chdinoboss(s32 param_0, s32 param_1) {
    if (func_800DA298(0xE5) == 0) {
        func_80800F70_chdinoboss(param_0, 0x17);
        func_8080248C_chdinoboss(param_0, 0x2A, 0x438);
    }
}

void func_80801FAC_chdinoboss();

void func_808015AC_chdinoboss();

void func_80800F70_chdinoboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *rec;
    s32 local_3;
    s32 local_4;
    f32 local_1[2]; /* only 2 values (func_800F18FC); matches the target's frame layout */
    f32 local_0[3];

    rec = func_80100094(param_0, 0);
    local_3 = 0;
    local_4 = 0;
    func_80102424(param_0, param_1);
    switch (param_1) {
    case 3:
        func_800FDC28(1);
        break;
    case 4:
        func_8080248C_chdinoboss(param_0, 4, 0x30);
        break;
    case 5:
        func_800DA544(1);
        break;
    case 6:
        if (!func_800DA298(0x172)) {
            _chintrotext_entrypoint_1(0x18B9, 1, 1, 0);
        }
        func_808015AC_chdinoboss(param_0);
        break;
    case 7:
        RF(0x12C) = 30.0f;
        RF(0x134) = 2500.0f;
        func_80801660_chdinoboss(param_0, 0.0f, 0.0f);
        param_0->unk58 = func_800DC178(2.0f, 4.0f);
        local_3 = 1;
        break;
    case 8:
        R32(0x120) = R32(0x120) - 1;
        local_3 = 1;
        break;
    case 9:
        param_0->unk58 = 0.7f;
        R16(0x11E) = 0;
        local_3 = 1;
        break;
    case 10:
        RF(0x12C) = 40.0f;
        RF(0x134) = 3500.0f;
        func_80801660_chdinoboss(param_0, 0.0f, 0.0f);
        if (RU8(0x12A) == 0) {
            RU8(0x12A) = 1;
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17FC, 0x44, param_0->position, 0x57);
        }
        func_80109FE8(param_0, 1);
        R16(0x11C) = param_0->pad5E;
        break;
    case 11:
        RF(0x12C) = 30.0f;
        RF(0x134) = 2500.0f;
        func_80801660_chdinoboss(param_0, 0.0f, 0.0f);
        func_80109FE8(param_0, 0);
        param_0->unk58 = func_800DC178(1.0f, 2.0f);
        R16(2) = func_80801C28_chdinoboss(param_0);
        R32(0x120) = R16(2);
        func_80801AE4_chdinoboss(param_0);
        local_3 = 1;
        local_4 = 1;
        break;
    case 12:
        if (!((DinoR128 *)rec)->f30) {
            ((DinoR128 *)rec)->f30 = 1;
            if (func_800C064C() == 0x17FC) {
                func_800C067C(0x17FC);
            }
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17B4, 0x44, param_0->position, 0x57);
        }
        R32(0x120) = R32(0x120) - 1;
        local_3 = 1;
        local_4 = 1;
        break;
    case 13:
        RF(0x12C) = 40.0f;
        RF(0x134) = 3500.0f;
        func_80801660_chdinoboss(param_0, 0.0f, 0.0f);
        param_0->unk58 = 4.0f;
        local_3 = 2;
        local_4 = 1;
        break;
    case 14:
        param_0->unk64_16 = 0;
        param_0->unk58 = 2.0f;
        break;
    case 15:
        if (!((DinoR128 *)rec)->f27) {
            ((DinoR128 *)rec)->f27 = 1;
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1802, 0x44, param_0->position, 0x57);
        }
        param_0->unk64_16 = 1;
        param_0->unk58 = 4.0f;
        local_3 = 3;
        local_4 = 1;
        break;
    case 23:
        func_800EFD24(local_0);
        func_800F18FC((f32 *)(rec + 0x110), local_0, local_1);
        RF(0x12C) = func_800136E4(-local_1[0]);
        RF(0x134) = func_800EEF94((f32 *)(rec + 0x110));
        RF(0x124) = func_80013728(RF(0x124));
        func_80801660_chdinoboss(param_0, 0.0f, 0.0f);
        func_80109EEC(param_0, 1);
        func_80109FE8(param_0, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x17B5, 0x44, param_0->position, 0x57);
        func_800DA544(0xE5);
        func_800DA524(1);
        func_800FDC28(0);
        param_0->pad5E = 0;
        func_80801CDC_chdinoboss(param_0);
        break;
    case 16:
        local_4 = 1;
        break;
    case 17:
        func_800EE7F8(param_0->position, (f32 *)(rec + 0x104));
        break;
    case 18:
        param_0->unk58 = 10.0f;
        break;
    case 19:
        func_800C964C(3);
        break;
    }
    func_80801FAC_chdinoboss(param_0, local_3, local_4);
}

void func_80801408_chdinoboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x17B3:
    case 0x1801:
        func_80800F70_chdinoboss(param_0, 4);
        param_0->unk58 = 0.75f;
        break;
    case 0x17B4:
    case 0x17B5:
    case 0x17FC:
        break;
    case 0x17B6:
        func_800D1000(0x2C, 1, 0, 1, 0);
        func_8080248C_chdinoboss(param_0, 0xB, 0x10);
        func_80800F70_chdinoboss(param_0, 0x14);
        func_80101180(0x461, 7, 0);
        func_80101180(0x469, 7, 0);
        break;
    case 0x17B7:
    case 0x120B:
        func_80800F70_chdinoboss(param_0, 0x14);
        _capod_entrypoint_14();
        break;
    case 0x17DF:
        func_800D1000(0x2F, 1, 0, 1, 0);
        func_8080248C_chdinoboss(param_0, 0x22, 0x10);
        func_80102424(param_0, 0x18);
        break;
    case 0xCEB:
        if (param_2 > 0) {
            _gcfrontend_entrypoint_11();
        } else {
            _gcfrontend_entrypoint_10();
        }
        break;
    default:
        if (func_800DA298(0xE5)) {
            func_80800F70_chdinoboss(param_0, 0x14);
        }
        break;
    }
}

void func_808015AC_chdinoboss(Actor *param_0)
{
    f32 *local_2;
    f32 local_0;
    f32 local_1[3];
    CodexDinoPose *local_3;

    local_3 = func_80100094(param_0, 0);
    if (!local_3->local_2) {
        local_3->local_2 = 1;
        local_2 = param_0->position;
        func_800EE7F8(local_2, local_3->local_0);
        func_800EFD24(local_1);
        func_800F18FC(local_2, local_1, &local_0);
        local_3->local_1 = local_3->local_4 = func_800136E4(param_0->rotation[1] + 180.0f);
        local_3->local_3 = func_80013728(-local_0);
        local_3->local_5 = func_800EEF94(local_2);
    }
}

void func_80801660_chdinoboss(s32 param_0, f32 param_1, f32 param_2) {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    func_800EEC30((f32 *)(param_0 + 4), (*(f32 *)((u8 *)temp_v0 + 0x12C)) + param_1, (*(f32 *)((u8 *)temp_v0 + 0x130)), (*(f32 *)((u8 *)temp_v0 + 0x134)) + param_2);
}

void func_808016C0_chdinoboss(Actor *param_0)
{
    f32 *local_0;

    local_0 = param_0->position;
    if (_subaddieaudioquick_entrypoint_3(param_0, local_0, D_80802A2C_chdinoboss, 0.94f)) {
        func_800E15CC(0, 30.0f, 0.9f);
        func_80018820(0, 1.0f, 0.3f);
    }
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_80802BEC_chdinoboss, D_80802C28_chdinoboss);
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_80802A48_chdinoboss, D_80802C14_chdinoboss);
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_80802BF4_chdinoboss, D_80802C34_chdinoboss);
    _subaddieaudioquick_entrypoint_3(param_0, local_0, D_80802C04_chdinoboss, 0.07f);
}

void func_808017A0_chdinoboss(s32 param_0)
{
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_80802A48_chdinoboss, &D_80802C40_chdinoboss);
}

void func_808017D0_chdinoboss(s32 param_0)
{
  _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_80802A48_chdinoboss, &D_80802C4C_chdinoboss);
}

void func_80801800_chdinoboss(s32 param_0)
{
  _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80802A48_chdinoboss, 0.23f);
}

void func_80801830_chdinoboss(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80802A48_chdinoboss, 0.28f);
}

int func_80801860_chdinoboss(s32 param_0)
{
  s32 local_0;
 local_0 = param_0 + 0x4; _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80802A2C_chdinoboss, 0.8f);
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80802C68_chdinoboss, 0.65f);
  _subaddieaudioquick_entrypoint_4(param_0, local_0, &D_80802C78_chdinoboss, &D_80802C88_chdinoboss);
}

int func_808018D0_chdinoboss(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80802C98_chdinoboss, 0.1f);
}

void func_80801900_chdinoboss(Actor *param_0)
{
    u8 *local_3;
    Actor *local_4;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[2];

    local_3 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 8) func_80801A44_chdinoboss(param_0, local_1);
    else func_800EE7F8(local_1, ((f32 (*)[3])(local_3 + 4))[((s16 *)(local_3 + 0xF4))[*(s32 *)(local_3 + 0x120)]]);
    _subaddieskeleton_entrypoint_1(param_0, 5, local_0);
    func_800F18FC(local_0, local_1, local_2);
    local_4 = func_80108528(0x398, local_0, (s32)local_2[1], &param_0);
    func_80102FDC(local_4, func_800DC178(2.0f, 4.0f));
    func_800EFB24((f32 *)((u8 *)local_4 + 0x28), local_1, local_0);
    func_800EF368((f32 *)((u8 *)local_4 + 0x28), 3500.0f);
    if (param_0->unk70_10 == 8) local_4->unk64_20 = 0;
    else local_4->unk64_20 = 1;
}

void func_80801A44_chdinoboss(param_0, param_1) Actor *param_0; f32 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    func_8010D09C(func_800F54E4(), local_1, 1.0f);
    func_800EE7F8(local_0, local_1);
    local_0[1] += 400.0f;
    local_1[1] -= 350.0f;
    if (func_800C6A7C(local_0, local_1, local_2, param_0->unk14)) {
        func_800EE7F8(param_1, local_1);
    } else {
        func_8010D254(param_1);
    }
}

void func_80801AE4_chdinoboss(param_0) Actor *param_0;
{
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    DinoRouteData *local_5;
    Vec3f local_0;

    local_5 = func_80100094(param_0, 0);
    func_8010D254(local_0.f);
    for (local_1 = 0; local_1 < local_5->local_1; local_1++) {
        local_5->local_3[local_1] = -1;
        do {
            local_2 = func_800DC128(0, local_5->local_0);
            local_4 = 1;
            for (local_3 = local_1 - 1; local_3 >= 0; local_3--) {
                if (local_2 == local_5->local_3[local_3]) {
                    local_4 = 0;
                    break;
                }
            }
            if (local_4) {
                if (func_800EEB40(local_0.f, local_5->local_2[local_2]) > 160000.0f) local_5->local_3[local_1] = local_2;
                else local_4 = 0;
            }
        } while (!local_4);
    }
}

u8 func_80801C28_chdinoboss(u8 *param_0)
{
  u8 var;
  if (param_0[0x5E] < 7)
  {
    return 6;
  }
  if (param_0[0x5E] < 13)
  {
    return 5;
  }
  if (param_0[0x5E] < 19)
  {
    return 4;
  }
  if (param_0[0x5E] < 0x19)
  {
    return 3;
  }
  return 2;
}

f32 func_80801C84_chdinoboss(param_0) u8 *param_0; {
    return func_800F10B4(param_0[0x5E], 0.0f, 30.0f, 0.3f, 1.8f);
}

void func_80801CDC_chdinoboss(u8 *param_0) {
    func_800D2498(0xC8, param_0[0x5E], 0, param_0);
}

void func_80801D08_chdinoboss(Actor *param_0, s32 param_1)
{
    f32 local_0[3];

    switch (param_1) {
    case 0:
        func_800EFD24(local_0);
        param_0->unk54 = func_80102D78(param_0, local_0);
        break;
    case 1:
        func_800EFD24(local_0);
        param_0->unk54 = func_80102D78(param_0, local_0) - 90.0f;
        break;
    case 2:
        func_8010D254(local_0);
        param_0->unk54 = func_80102D78(param_0, local_0);
        break;
    }
    func_80102BF8(param_0, 0.1f, 0.05f, 120.0f);
}

void func_80801DC8_chdinoboss(Actor *param_0)
{
    DinoBossCameraState *local_2;
    f32 local_0[3];
    f32 local_1[3];

    local_2 = func_80100094(param_0, 0);
    switch (local_2->local_0) {
    case 0:
        break;
    case 1:
        func_8008FE68(local_0);
        func_800EEC30(local_1, 60.0f, local_2->local_1, 2800.0f);
        func_800EF934(local_1, local_1, param_0->rotation[1]);
        func_800EF04C(local_1, param_0->position);
        func_8080232C_chdinoboss(param_0, local_1, local_0);
        break;
    case 2:
    case 3:
        func_8080232C_chdinoboss(param_0, local_2->local_2, param_0->position);
        break;
    }
}

int func_80801E90_chdinoboss(f32 *param_0, f32 *param_1)
{
  func_8010FFB0(func_800F5EF8(func_800F54E4()) | 0, param_0, param_1);
}

s32 func_80801ECC_chdinoboss(f32 *param_0, f32 *param_1) {
    s32 i;

    for(i = 0; i < 8; i++){
        if(func_800F6438(i) != 0){
            func_8010FE14(func_800F5EF8(i), param_0, param_1);
        }
    }
}

int func_80801F44_chdinoboss(s32 param_0)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (func_800F6438(local_0 | 0))
    {
      func_8010F9C0(func_800F5EF8(local_0 | 0) | 0, param_0 | 0);
    }
  }

}

void func_80801FAC_chdinoboss(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    DinoCamera441 *local_9;
    s32 local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6;
    Actor *new_var;
    f32 local_7;

    local_9 = func_80100094(param_0, 0);
    local_1 = 0;
    local_2 = 1;
    if (local_9->local_1 && !param_2) {
        func_80090708(0);
        local_9->local_1 = 0;
    }
    if (!local_9->local_1 && param_2) {
        func_80090708(2);
        local_9->local_1 = 1;
    }
    if (param_1 != local_9->local_0) {
        func_80801E90_chdinoboss(local_9->local_6, local_9->local_7);
        if (1) {}
        new_var = param_0;
        switch (local_9->local_0) {
        case 1:
        case 2:
            if (1) {}
        case 3:
            break;
        case 0:
            func_800F7B9C(func_800F54E4(), 0x93);
            break;
        }
        switch (param_1) {
        case 0:
            func_8008FE68(local_0);
            func_80801E90_chdinoboss(local_3, local_5);
            func_800EFB24(local_4, local_3, local_0);
            func_800EF368(local_4, 600.0f);
            func_800EF04C(local_0, local_4);
            func_80801ECC_chdinoboss(local_0, local_5);
            func_80801F44_chdinoboss(2);
            local_2 = 0;
            break;
        case 1:
            func_80801F44_chdinoboss(6);
            local_7 = func_80102D78(new_var, local_9->local_6);
            if (!func_800F1EA4(new_var->position, &local_6)) {
                local_6 = new_var->rotation[1];
            }
            if (func_800F1DCC(local_7, local_6) > 0.0f) {
                local_9->local_8 = -100.0f;
            } else {
                local_9->local_8 = 100.0f;
            }
            if (local_9->local_9) {
                local_2 = 0;
                local_9->local_9 = 0;
            }
            if (new_var->unk70_10 == 0xB || param_0->unk70_10 == 0xC) {
                local_1 = 1;
            }
            break;
        case 2:
            func_80801F44_chdinoboss(6);
            local_9->local_10 = 0.0f;
            func_800EEB9C(local_9->local_11,
                func_800136E4((func_800DC298(0.5f) ? -35.0f : 35.0f) + param_0->rotation[1]), 6000.0f);
            func_800EF04C(local_9->local_11, param_0->position);
            local_1 = 1;
            local_2 = 0;
            break;
        case 3:
            func_80801F44_chdinoboss(6);
            local_1 = 1;
            local_2 = 0;
            break;
        }
        if (local_1 && !local_9->local_2) {
            _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
            func_800C52F4(0, 2);
            local_9->local_2 = 1;
        }
        if (!local_1 && local_9->local_2) {
            _glcutDll_entrypoint_17();
            func_800C53EC(0, 2);
            local_9->local_2 = 0;
        }
        local_9->local_0 = param_1;
        if (local_2) {
            local_9->local_3 = 1;
            local_9->local_5 = 1.0f;
            local_9->local_4 = 1.0f;
            return;
        }
        local_9->local_3 = 0;
    }
}

void func_8080232C_chdinoboss(param_0, param_1, param_2) Actor *param_0; f32 *param_1; void *param_2;
{
    u8 *local_8;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[2];
    f32 local_3[2];
    f32 local_5;
    f32 local_4;
    f32 local_6;
    s32 i;
    s32 pad; /* filler local: the target has a stack slot here (local_7 at 0x44); original variable unknown */
    s32 local_7;

    local_8 = func_80100094(param_0, 0);
    if (*(s16 *)(local_8 + 0x13E)) {
        local_7 = func_800D9078(local_8 + 0x140);
        local_6 = func_800F12D4(*(f32 *)(local_8 + 0x140), 0.0f, *(f32 *)(local_8 + 0x144), 1.0f, 0.0f);
        func_800F1A88(local_8 + 0x148, local_2);
        func_800F1A88(param_1, local_3);
        local_5 = func_800EEF94((f32 *)(local_8 + 0x148));
        local_4 = (func_800EEF94(param_1) - local_5) * local_6 + local_5;
        for (i = 0; i < 2; i++) {
            local_3[i] = local_2[i] + func_800F1DCC(local_3[i], local_2[i]) * local_6;
        }
        func_800EEBF0(local_1, local_3, local_4);
        func_800A516C(local_0, param_2, local_1);
        func_80801ECC_chdinoboss(local_1, local_0);
        if (local_7) *(s16 *)(local_8 + 0x13E) = 0;
    } else {
        func_800A516C(local_0, param_2, param_1);
        func_80801ECC_chdinoboss(param_1, local_0);
    }
}

void func_8080248C_chdinoboss(param_0, param_1, param_2) s32 param_0[3]; s32 param_1; u32 param_2;
{
  Actor *local_0;
  local_0 = func_80100094(param_0, 0);
  if (*(u8 *)((char *)(local_0) + 0x12B))
  {
    _capod_entrypoint_14();
    param_2 = param_2 | 0x2000;
  }
  _capod_entrypoint_13(*param_0, 0, param_1, param_2);
  *(u8 *)((char *)(local_0) + 0x12B) = 1;
}

void func_80802500_chdinoboss(s32 param_0) {
    u8 *sp1C;
    u8 *var_v1;

    sp1C = func_80100094(param_0, 0);
    var_v1 = sp1C;
    if (*(u8 *)((char *)sp1C + 0x12B) != 0) {
        _capod_entrypoint_14();
        var_v1 = sp1C;
    }
    *(s8 *)((char *)var_v1 + 0x12B) = 0;
}

void func_80802540_chdinoboss(Actor *param_0)
{
    f32 local_0[3];
    func_800F4F34(func_800F54E4(), param_0->position, 5e+02f, 5e+02f);
    if (_subaddieskeleton_entrypoint_0(param_0, 6, local_0)) func_800F4F34(func_800F54E4(), local_0, 0.0f, 3e+02f);
    if (_subaddieskeleton_entrypoint_0(param_0, 20, local_0)) func_800F4F34(func_800F54E4(), local_0, 0.0f, 3e+02f);
}

void func_808025E8_chdinoboss(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800EA05C();
    local_1 = 1;
    param_0->actorData[4] = -1;
    if (!_glcutDll_entrypoint_19(0x33)) {
        if (func_800DA298(0xE5) && local_0 == 0x112
            && !_subaddiefind_entrypoint_2(0x234, 0)) {
            func_80108B04(param_0, 0);
            local_1 = 0;
        }
    } else {
        local_1 = 0;
    }
    if (local_1) {
        func_800FFAB0(param_0);
    }
}

void func_80802684_chdinoboss(u8 *param_0, s32 param_1) {
    if (func_800D9078(param_0 + 0x58, param_1, param_0) != 0 && *(s32 *)(param_0 + 0x28) == 0x1D) {
        func_80108B04(param_0, 0);
    }
}

void func_80802864_chdinoboss();

s32 func_808026D0_chdinoboss(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
        case 0xB:
            switch (param_2) {
                case 0x1D:
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(param_0->unk0, 0, 0x25, 0x2820);
                    *(s32 *)((u8 *)param_0 + 0x28) = 0x25;
                    return 4;
                case 0x25:
                    _glcutDll_entrypoint_24(0x115, 0x113, 0x33);
                    *(s32 *)((u8 *)param_0 + 0x28) = -1;
                    return 2;
                case 4:
                    _glcutDll_entrypoint_17();
                    *(s32 *)((u8 *)param_0 + 0x28) = -1;
                    break;
            }
            return 2;
        case 0x3D:
            func_80802864_chdinoboss(param_0, param_2);
            return 1;
        case 0x49:
            local_0 = func_800EA05C();
            if (param_2 != 0x33) {
                return 0;
            }
            switch (local_0) {
                case 0x112:
                    param_0->unk58 = 0.8f;
                    *(s32 *)((u8 *)param_0 + 0x28) = 0x1D;
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x17FB, 0x44, 0, 0x57);
                    _capod_entrypoint_13(param_0->unk0, 0, 0x1D, 0x2820);
                    break;
                case 0x115:
                    *(s32 *)((u8 *)param_0 + 0x28) = 4;
                    _capod_entrypoint_13(param_0->unk0, 0, 4, 0x2820);
                    break;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80802864_chdinoboss(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    if (param_1 == 0) {
        local_1 = func_80108528(0x234, &D_80802CA8_chdinoboss, 0x5A, &param_0);
        local_0 = local_1;
        func_80102FDC(local_1, 0.8f);
        if (_glcutDll_entrypoint_19(0x33) != 0) {
            _chappearfx_entrypoint_1(local_0, 0x22, 2, 0x3F800000);
            return;
        }
        func_800FFAB0(param_0);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/dino/boss.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently. */
extern void func_8010A730();
f32 D_80802A20_chdinoboss[3] = { 3e+02f, 1e+01f, -1.5e+02f };
u8 D_80802A2C_chdinoboss[8] = { 0x0, 0x13, 0x4, 0x17, 0x0, 0x2, 0x0, 0x0 };
u8 D_80802A34_chdinoboss[20] = { 0x0, 0x13, 0x5, 0x38, 0x0, 0x2, 0x0, 0x16, 0x75, 0x30, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802A48_chdinoboss[16] = { 0x0, 0x13, 0x3, 0xFF, 0x0, 0xD, 0x0, 0x73, 0x0, 0x8C, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802A58_chdinoboss[16] = { 0x0, 0x13, 0x5, 0x39, 0x0, 0x2, 0x0, 0x18, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_80802A68_chdinoboss[216] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1, 0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1, 0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1, 0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x1, 0x62, 0x0, 0x2, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x3, 0x1, 0x40, 0x99, 0x99, 0x9A, 0x1, 0x61, 0x0, 0x1, 0x3F, 0x80, 0x0, 0x0, 0x1, 0x5F, 0x0, 0x42, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1, 0x3E, 0xE6, 0x66, 0x66, 0x1, 0x60, 0x0, 0x1, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1, 0x3F, 0x80, 0x0, 0x0, 0x1, 0x5F, 0x0, 0x42, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1, 0x3F, 0x66, 0x66, 0x66, 0x1, 0x5E, 0x0, 0x1, 0x3F, 0x80, 0x0, 0x0, 0x1, 0x5D, 0x3, 0x2, 0x41, 0x3B, 0xAE, 0x14, 0x1, 0xC1, 0x0, 0x1, 0x41, 0x3B, 0xAE, 0x14, 0x1, 0xC1, 0x0, 0x1, 0x40, 0xE7, 0x5C, 0x29, 0x1, 0xF7, 0x0, 0x1, 0x40, 0xE7, 0x5C, 0x29, 0x1, 0xF7, 0x0, 0x1, 0x3F, 0x0, 0x0, 0x0, 0x1, 0x5C, 0x0, 0x2, 0x3F, 0x0, 0x0, 0x0, 0x1, 0x5C, 0x0, 0x2, 0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1, 0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1 };
int D_80802B40_chdinoboss = 0x2FA036F;
static int D_80802B40_chdinoboss_rest[17] = { 0x6DA0001, (int)&D_80802A68_chdinoboss, (int)func_80800220_chdinoboss, (int)func_80105834, (int)func_80101870, 0x0, 0x0, 0x0, 0x10568, 0x0, (int)func_80108ED0, 0x1780000, (int)func_80800018_chdinoboss, (int)func_80107C2C, -0x7FDEFBE0, (int)func_80800C50_chdinoboss, 0x0 };
void *D_80802B88_chdinoboss = (void *)0x009F03D8;
static void *D_80802B88_chdinoboss_rest[17] = { (void *)0x00000001, 0, func_80802684_chdinoboss, func_80105834, func_8010A730, 0, 0, 0, 0, 0, 0, 0, func_808025E8_chdinoboss, func_80107C2C, (void *)0x80000602, func_808026D0_chdinoboss, 0 };
u8 D_80802BD0_chdinoboss[28] = { 0x0, 0x0, 0x9, 0xC4, 0x0, 0x0, 0x17, 0xB7, 0x0, 0x0, 0x6, 0x1, 0x12, 0xB, 0x0, 0x0, 0x0, 0x57, 0x0, 0x0, 0x0, 0xE, 0x22, 0x28, 0x15, 0x0, 0x0, 0x0 };
u8 D_80802BEC_chdinoboss[8] = { 0x0, 0x13, 0x4, 0xAA, 0x0, 0x2, 0x0, 0x0 };
u8 D_80802BF4_chdinoboss[16] = { 0x0, 0x13, 0x5, 0x35, 0x0, 0x2, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802C04_chdinoboss[16] = { 0x0, 0x13, 0x5, 0x34, 0x0, 0x2, 0x0, 0x18, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_80802C14_chdinoboss[20] = { 0x3D, 0x38, 0x51, 0xEC, 0x3D, 0xB4, 0x39, 0x58, 0x3E, 0xD, 0x4F, 0xDF, 0x3E, 0x3D, 0x70, 0xA4, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80802C28_chdinoboss[12] = { 0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xBD, 0x70, 0xA4, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80802C34_chdinoboss[12] = { 0x3F, 0x40, 0x0, 0x0, 0x3F, 0x6B, 0x85, 0x1F, 0xBF, 0x80, 0x0, 0x0 };
u32 D_80802C40_chdinoboss = 0x3E99999A;
static u32 D_80802C40_chdinoboss_rest[2] = { 0x3F266666, 0xBF800000 };
void *D_80802C4C_chdinoboss = (void *)0x3C23D70A;
static void *D_80802C4C_chdinoboss_rest[6] = { (void *)0x3E3851EC, (void *)0x3EB33333, (void *)0x3F051EB8, (void *)0x3F2E147B, (void *)0x3F570A3D, (void *)0xBF800000 };
int D_80802C68_chdinoboss = 0x130512;
static int D_80802C68_chdinoboss_rest[3] = { 0x2000D, 0xC000D9, 0x0 };
int D_80802C78_chdinoboss = 0x130551;
static int D_80802C78_chdinoboss_rest[3] = { 0x2000D, 0xF3010C, 0x0 };
int D_80802C88_chdinoboss = 0x3EE147AE;
static int D_80802C88_chdinoboss_rest[3] = { 0x3F000000, 0x3F0F5C29, -0x40800000 };
s32 D_80802C98_chdinoboss = 0x130535;
static s32 D_80802C98_chdinoboss_rest[3] = { 0x2000D, 0x9900B3, 0x0 };
s32 D_80802CA8_chdinoboss = -0x3A2EA000;
static s32 D_80802CA8_chdinoboss_rest[5] = { 0x44A28000, -0x3A768000, 0x0, 0x0, 0x0 };
