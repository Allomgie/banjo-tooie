#include "common.h"

extern int D_80802EB4_changlerboss[];
extern int D_80802EFC_changlerboss[];
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800F608C();
extern void func_80102424();
extern void *func_80100094(Actor *, u32);
extern s32 func_800F4AC0(s32, void *, f32);
extern s32 D_80802DA0_changlerboss[];
extern s32 func_8010D5DC;
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 31; u32 local_0 : 1; } AnglerInitializationFlag1121;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 24; u32 local_0 : 2; u32 pad_2 : 6; } AnglerMarkerPairFlags1121;
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_80109FE8();
extern s32 D_80802DAC_changlerboss[];
extern s32 D_80802F70_changlerboss[];
extern s16 D_80802F8C_changlerboss[][3][3];
extern void func_800F18FC();
typedef struct { f32 local_0[3]; u8 pad_0[12]; } AnglerPoint721;
typedef struct { u8 pad_0[0x90]; s16 local_0; u8 pad_1[0x12]; AnglerPoint721 local_1[1]; } AnglerPath721;
extern f32 func_800D8FF8(void);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern s32 func_80102CF4(Actor *, f32);
typedef struct { u8 pad_0[0x128]; s16 local_0; } AnglerAimState;
typedef struct { u8 pad_0[0x1B]; u8 local_0[6]; } AnglerPiecesState;
extern u8 field_38[];
extern u8 field_0[];
typedef struct { u8 pad_0[0x9C]; void *local_0; void *local_1; } AnglerCleanup1358;
extern int _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern s32 func_800D10D4(s32, s32, void *, s32, s32);
extern void func_800FFA88();
extern void func_8010114C();
typedef struct { u32 pad : 31; u32 flag : 1; } BitTest31;
extern void _capod_entrypoint_14(void);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
typedef struct { u8 pad_0[0x3C]; f32 local_0[6][3]; f32 local_1[3]; } AnglerSkeletonState;
extern s16 D_80803054_changlerboss[6];
extern u8 D_80803060_changlerboss[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800EFD24(f32 *);
extern f32 func_80102D78(u8 *, f32 *);
typedef struct { u8 pad_0[0x7A]; u8 pad_1 : 2; u8 local_0 : 2; u8 local_1 : 3; u8 pad_2 : 1; } AnglerRenderFlags;
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern void func_800F5A00(s32, f32 *);
extern s32 B_808030B0_changlerboss;
typedef struct { u8 pad_0[0x90]; s16 local_0; s16 pad_1; s16 local_1; s16 pad_2; f32 local_2; Unk80132ED0 *local_3; u32 pad_3; f32 local_4[2][6]; } AnglerData88;
extern s32 D_80802F80_changlerboss[];
extern f32 func_800DC178(f32, f32);
typedef struct { u8 pad_0[0x90]; s16 local_0; u8 pad_1[6]; f32 local_1; u8 pad_2[0x93]; u8 local_2; } AnglerBossApproach;
typedef struct { f32 local_0[3]; u8 pad_0[0xC]; } AnglerBossWaypoint;
extern f32 func_800F15F8(f32, f32, f32);
typedef struct { u8 pad0[0x6E]; u16 unk6E_9 : 7; u16 unk6E_0 : 9; } AnglerBits;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80802FF8_changlerboss[];
extern s32 func_80102320(Actor *, f32, f32);
extern s32 func_800DC298(f32);
extern void func_800BA22C();
extern void func_800BA568();
extern void func_800BA994();
extern u8 D_80803008_changlerboss[];
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern s32 D_80803098_changlerboss[];
extern void func_800F2F60(s32 *, s32 *, f32);
extern void func_800C8E54(s32, f32, f32);
void func_808015F4_changlerboss();
s32 func_80801C50_changlerboss();
void func_808021E4_changlerboss();
void func_80802210_changlerboss();
void func_808027F8_changlerboss();
void func_808012E0_changlerboss();
void func_8080170C_changlerboss();
s32 func_80801948_changlerboss();
void func_80801E3C_changlerboss();
void func_80801F54_changlerboss();
void func_80802340_changlerboss();
int func_80802430_changlerboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800018_changlerboss(), func_808002E0_changlerboss(), func_80800FEC_changlerboss();
extern u8 D_80802DBC_changlerboss[];

int *changlerboss_entrypoint_0()
{
    return &D_80802EB4_changlerboss;
}

int *changlerboss_entrypoint_1()
{
    return &D_80802EFC_changlerboss;
}

void func_80800018_changlerboss(param_0) Actor *param_0; {
    s32 local_4;
    s32 local_5;
    u8 *local_10;

    local_10 = func_80100094(param_0, 0);
    ((AnglerInitializationFlag1121 *)param_0)->local_0 = 1;
    ((AnglerMarkerPairFlags1121 *)param_0)->local_0 = 3;
    func_800EE7F8(local_10 + 0x11C, param_0->position);
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x32, local_10 + 0xA4, 1);
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x33, local_10 + 0xBC, 1);
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x34, (local_10 + 0xD4), 1);
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x35, (f32 *)(local_10 + 0xEC), 1);
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x36, (f32 *)(local_10 + 0x104), 1);
    (*(s16 *)((s8 *)(local_10) + (0x90))) = 1;
    (*(s32 *)((s8 *)(local_10) + (0x9C))) = 0;
    (*(s32 *)((s8 *)(local_10) + (0xA0))) = 0;
    (*(s16 *)((s8 *)(local_10) + (0x92))) = 0;
    (*(s16 *)((s8 *)(local_10) + (0x96))) = 6;
    for (local_5 = 0; local_5 < 6; local_5++) {
        func_808015F4_changlerboss(param_0, local_5, 1);
    }
    func_80109F08(param_0, 0x40);
    local_4 = func_800F54E4();
    if (_glcutDll_entrypoint_20() != 0) {
        func_800EE7F8(param_0->position, (f32 *)(local_10 + 0x104));
        func_80102424(param_0, 0x1D);
        func_8010A85C(param_0, 1);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802DA0_changlerboss);
        return;
    }
    if (func_800DA298(0x377) != 0) {
        func_8010A85C(param_0, 1);
        func_8010A590(param_0);
        func_808012E0_changlerboss(param_0, 0x1A);
        func_800EE7F8(param_0->position, (f32 *)(local_10 + 0xEC));
        (*(f32 *)((s8 *)(param_0) + (0x48))) = (f32) (*(f32 *)((s8 *)(local_10) + (0xFC)));
        _chintrotext_entrypoint_2(1);
        return;
    }
    func_8010A85C(param_0, 2);
    (*(f32 *)((s8 *)(param_0) + (0x58))) = 2.0f;
    if (func_800DA298(0x1AF) != 0) {
        func_800EE7F8(param_0->position, (f32 *)(local_10 + 0x104));
        func_808012E0_changlerboss(param_0, 4);
        func_800F608C(local_4, 1);
        func_800F8294(local_4, (local_10 + 0xD4));
        _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), 0x1028, 0x106, param_0->position, 0xB4);
        func_808021E4_changlerboss(param_0, 0x12, 0x30);
        (*(s8 *)((s8 *)(local_10) + (0x12A))) = 1;
        return;
    }
    func_800F608C(local_4, 1);
    func_800F497C(local_4);
    func_800F49D4(local_4, &func_8010D5DC, (*(s32 *)((s8 *)(param_0) + (0))));
    func_800F4AC0(local_4, (local_10 + 0xD4), 300.0f);
    func_808021E4_changlerboss(param_0, 0x22, 0x20);
    _chintrotext_entrypoint_2(1);
}

void func_80802680_changlerboss();

void func_808025EC_changlerboss();

s32 func_808025AC_changlerboss();

void func_808022C4_changlerboss();

s32 func_80801CD8_changlerboss();

void func_80801BC8_changlerboss();

s32 func_80801AF0_changlerboss();

void func_80801A10_changlerboss();

void func_808016A8_changlerboss();

void func_808002E0_changlerboss(param_0) Actor *param_0;
{
    extern u8 D_80802F44_changlerboss[];
    extern u8 D_80802F50_changlerboss[];
    extern u8 D_80802F60_changlerboss[];

    char *local_0;
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_6;
    s32 local_7;

    local_0 = (char *)func_80100094(param_0, 0);

    *(s16 *)(local_0 + 0x128) =
        func_808025AC_changlerboss(param_0);

    if (func_800F6438(*(s16 *)(local_0 + 0x128))) {
        func_800F5A00(
            *(s16 *)(local_0 + 0x128),
            local_2
        );
    } else {
        func_8010D640(local_2);
    }

    func_808025EC_changlerboss(param_0);
    func_80802680_changlerboss(param_0);
    func_808022C4_changlerboss(param_0);
    func_80802340_changlerboss(param_0);

    if (param_0->unk7C_12) {
        if (*(Unk80132ED0 **)(local_0 + 0xA0) != 0) {
            _subaddieskeleton_entrypoint_2(
                *(s32 *)((char *)param_0 + 0),
                0xB,
                func_80106790(*(Unk80132ED0 **)(local_0 + 0xA0))->position
            );
        }
    }

    switch (param_0->unk70_10) {
        case 1:
            func_8010A5B0(
                param_0,
                param_0->unk7C_12
            );

            if (func_800D9078((char *)param_0 + 0x58)) {
                func_80101180(0x46C, 8, 0);
            }

            if (!func_800DA298(0x6AD)) {
                if (*(u8 *)(local_0 + 0x12E) == 0) {
                    *(u8 *)(local_0 + 0x12E) = 1;

                    _subaddiedialog_entrypoint_11(
                        *(s32 *)((char *)param_0 + 0),
                        0x103E,
                        0x144,
                        (char *)param_0 + 4,
                        0xB4
                    );
                }
            }

            if (*(u8 *)(local_0 + 0x12C) != 0 &&
                *(u8 *)(local_0 + 0x12D) != 0) {
                func_800F82D4(func_800F54E4(), 0);
                func_808012E0_changlerboss(param_0, 2);
            }
            break;

        case 2:
            if (func_80101DDC(param_0)) {
                func_808012E0_changlerboss(param_0, 3);
            }
            break;

        case 3:
            local_4 =
                func_800D9078((char *)param_0 + 0x58);

            local_3 = func_800F12D4(
                *(f32 *)((char *)param_0 + 0x58),
                0.0f,
                4.0f,
                1.0f,
                0.0f
            );

            func_800EFE50(
                (char *)param_0 + 4,
                local_0 + 0x11C,
                local_0 + 0x104,
                local_3
            );

            if (local_4) {
                func_808012E0_changlerboss(param_0, 4);

                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x1027,
                    0x106,
                    (char *)param_0 + 4,
                    0xB4
                );

                func_808021E4_changlerboss(
                    param_0,
                    0xA,
                    0x30
                );
            }
            break;

        case 4:
            func_8010A5B0(
                param_0,
                param_0->unk7C_12
            );
            break;

        case 5:
            func_80801A10_changlerboss(param_0);

            if (func_800D9078((char *)param_0 + 0x58)) {
                func_808012E0_changlerboss(param_0, 6);
            }
            break;

        case 6:
            func_80801A10_changlerboss(param_0);

            if (func_80801948_changlerboss(param_0)) {
                func_808012E0_changlerboss(param_0, 7);
            }
            break;

        case 7:
            func_80801948_changlerboss(param_0);

            if (func_80801AF0_changlerboss(param_0)) {
                func_808012E0_changlerboss(param_0, 8);
            }
            break;

        case 8:
            func_80801AF0_changlerboss(param_0);

            if (func_80101E14(param_0, 0.7f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101E14(param_0, 0.999f)) {
                if (--*(s16 *)(local_0 + 0x94) == 0) {
                    func_808012E0_changlerboss(param_0, 5);
                }
            }
            break;

        case 9:
            if (func_80101DDC(param_0)) {
                local_5 = func_80801C50_changlerboss(param_0);

                switch (local_5) {
                case 0:
                    func_808012E0_changlerboss(param_0, 0xB);
                    break;
                case 5:
                    _subaddiedialog_entrypoint_11(
                        *(s32 *)((char *)param_0 + 0),
                        0x102A,
                        0x106,
                        (char *)param_0 + 4,
                        0xB4
                    );

                    func_808012E0_changlerboss(param_0, 0xA);
                    break;
                default:
                    func_808016A8_changlerboss(param_0);
                    func_808012E0_changlerboss(param_0, 6);
                }
            }
            break;

        case 11:
            if (func_800D9078((char *)param_0 + 0x58)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_80802F44_changlerboss
                );

                func_8010A85C(param_0, 1);

                ((AnglerRenderFlags *)param_0)->local_0 = 1;
                ((AnglerRenderFlags *)param_0)->local_1 = 3;

                func_808012E0_changlerboss(param_0, 0xC);
            }
            break;

        case 13:
            if (func_800D9078((char *)param_0 + 0x58)) {
                func_808012E0_changlerboss(param_0, 0xE);
            }
            break;

        case 14:
            func_80801A10_changlerboss(param_0);

            if (func_80801948_changlerboss(param_0)) {
                func_808012E0_changlerboss(param_0, 0xF);
            }
            break;

        case 15:
            func_80801948_changlerboss(param_0);

            if (func_80801AF0_changlerboss(param_0)) {
                func_808012E0_changlerboss(param_0, 0x10);
            }
            break;

        case 16:
            local_6 = func_80101F24(param_0);

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802F60_changlerboss,
                0.4f
            );

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80802F50_changlerboss,
                0.75f
            );

            if (local_6 > 0.0f &&
                local_6 >= 0.4f &&
                local_6 <= 0.75f) {
                func_80801CD8_changlerboss(param_0);
            }

            func_80801AF0_changlerboss(param_0);

            if (func_80101DDC(param_0)) {
                func_808012E0_changlerboss(param_0, 0x12);
                *(s16 *)(local_0 + 0x94) = 2;
            }
            break;

        case 17:
            func_80801AF0_changlerboss(param_0);

            if (*(s16 *)(local_0 + 0x94) == 0) {
                if (_subaddiefind_entrypoint_2(0x460, 0) == 0) {
                    func_808012E0_changlerboss(param_0, 0xD);
                }
            }

            if (func_800D9078((char *)param_0 + 0x58)) {
                if (*(s16 *)(local_0 + 0x94) > 0) {
                    func_808012E0_changlerboss(param_0, 0x12);
                }
            }
            break;

        case 18:
            func_80801AF0_changlerboss(param_0);

            if (func_80101E14(param_0, 0.7f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101DDC(param_0)) {
                if (--*(s16 *)(local_0 + 0x94) == 0 &&
                    _subaddiefind_entrypoint_2(0x460, 0) == 0) {
                    func_808012E0_changlerboss(param_0, 0xD);
                } else {
                    func_808012E0_changlerboss(param_0, 0x11);
                }
            }
            break;

        case 19:
            func_80801AF0_changlerboss(param_0);

            if (func_80101E14(param_0, 0.7f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101E14(param_0, 0.999f)) {
                --*(s16 *)(local_0 + 0x94);
                if (*(s16 *)(local_0 + 0x94) == 0) {
                    func_808012E0_changlerboss(param_0, 0xD);
                }
            }
            break;

        case 20:
            func_80801AF0_changlerboss(param_0);

            if (func_800D9078((char *)param_0 + 0x58)) {
                func_808012E0_changlerboss(param_0, 0x15);
            }
            break;

        case 21:
            func_80801AF0_changlerboss(param_0);

            if (func_80101E14(param_0, 0.7f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101E14(param_0, 0.999f)) {
                --*(s16 *)(local_0 + 0x94);
                if (*(s16 *)(local_0 + 0x94) == 0) {
                    func_808012E0_changlerboss(param_0, 0xD);
                }
            }
            break;

        case 22:
            if (func_80101DDC(param_0)) {
                *(u8 *)(local_0 + 0x12F) = 1;

                if (*(s16 *)(local_0 + 0x96) == 5) {
                    _subaddiedialog_entrypoint_11(
                        *(s32 *)((char *)param_0 + 0),
                        0x1036,
                        0x106,
                        (char *)param_0 + 4,
                        0xB4
                    );

                    func_808012E0_changlerboss(param_0, 0x17);
                } else {
                    func_80109FE8(param_0, 0);
                    func_808012E0_changlerboss(param_0, 0x13);
                }
            }
            break;

        case 24:
            if (func_80101DDC(param_0)) {
                func_808012E0_changlerboss(param_0, 0x19);
            }
            break;

        case 25:
            func_80801BC8_changlerboss(param_0);
            break;

        case 26:
            func_80801BC8_changlerboss(param_0);

            if (*(u8 *)(local_0 + 0x12B) == 0) {
                if (func_800D90A4((char *)param_0 + 0x58)) {
                    if (func_800EEB40(
                            (char *)param_0 + 4,
                            local_2) < 1960000.0f) {
                        local_7 = func_800DC128(0, 4);

                        _subaddiedialog_entrypoint_11(
                            *(s32 *)((char *)param_0 + 0),
                            local_7 + 0x1037,
                            0x144,
                            (char *)param_0 + 4,
                            0xB4
                        );

                        func_808012E0_changlerboss(param_0, 0x1B);
                    }
                }
            }
            break;

        case 29:
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 0x1E);
            }
            break;
    }
}

void func_80802108_changlerboss();

void func_80801D0C_changlerboss();

void func_80801070_changlerboss();

void func_80800F14_changlerboss();

s32 func_80800B7C_changlerboss(u8 *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x3D:
        switch (param_2) {
        case 0:
            func_80801D0C_changlerboss(param_0);
            break;
        case 1:
            func_80801E3C_changlerboss(param_0);
            break;
        case 2:
            func_80801F54_changlerboss(param_0);
            break;
        case 3:
            func_80802108_changlerboss(param_0);
            break;
        }
        break;
    case 0x2E:
        func_8080170C_changlerboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0xB:
        if (param_2 != 0xE) {
            if (param_2 == 0x19) {
                func_80101180(0x46C, 7, 0);
                func_808021E4_changlerboss(param_0, 0xE, 0x10);
                return 4;
            }
        } else {
            local_0[0x12B] = 0;
            if (param_1) {}
        }
        return 3;
    case 0x40:
        func_80801070_changlerboss(param_0, *(s32 *)&param_2);
        break;
    case 0xA:
        if (((u32)*(u16 *)(param_0 + 0x72) >> 10) == 0x11) {
            func_808012E0_changlerboss(param_0, 0x13);
        }
        break;
    case 0x49:
        if (func_800DA298(0x377) == 0 || _glcutDll_entrypoint_20() != 0) {
            func_80801DA0_changlerboss(param_0);
        }
        break;
    case 0x32:
        local_0[0x12C] = 1;
        func_800F82D4(func_800F54E4(), 2);
        break;
    case 0x95:
        if (!func_800DA298(0x377)) {
            func_80108B04(param_0, 0);
        }
        if (local_0[0x12A] != 0) {
            func_800FDC28(1);
            local_0[0x12A] = 0;
        }
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0xCEB, 0x146, param_0 + 4, 0xB4);
        break;
    case 0x9F:
        func_800FDC28(0);
        func_808012E0_changlerboss(param_0, 0x1C);
        break;
    case 0xA2:
        if (!((Actor *)param_0)->unk7C_12 || func_800DA298(0x377)) {
            return 0;
        }
        if (*(s16 *)(local_0 + 0x92) == 0) {
            for (local_2 = 0, local_1 = local_0; local_2 != 6; local_2++, local_1++) {
                if (local_1[0x1B] == 0) {
                    func_800EE7F8(&B_808030B0_changlerboss, &((Vec3f *)(local_0 + 0x3C))[local_2]);
                    func_80101074(&B_808030B0_changlerboss);
                    return 1;
                }
            }
            return 0;
        }
        func_800EE7F8(&B_808030B0_changlerboss, local_0 + 0x84);
        func_80101074(&B_808030B0_changlerboss);
        break;
    case 0x1F:
        func_80800F14_changlerboss(param_0, *(s32 *)&param_2);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800F14_changlerboss(Actor *param_0, s32 param_1)
{
    Unk80132ED0 *local_5;
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;
    u8 *local_4;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    for (local_2 = 1; local_2 < 27; local_2++) {
        func_800DF744(local_2, local_0[local_2]);
    }
    func_801015D0(param_0);
    local_5 = *(Unk80132ED0 **)(local_0 + 0x9C);
    if (local_5 != 0) {
        local_4 = (u8 *)func_80106790(local_5);
        if (*(u16 *)(local_4 + 0x64) & 1) local_1 = *(s32 *)(local_4 + 0x54);
    }
    func_800DF660(4, (local_1 & 0xFFFF) | 0x30000, 0, *((u8 *)param_0 + 0x9B));
    func_800DF720(func_80100AC4(*(s16 *)((u8 *)param_0 + 0x60)));
}

void func_80800FEC_changlerboss(param_0, param_1) s32 *param_0; s32 param_1;
{
  s32 *local_0;
  s32 local_1;
  s32 *local_2;
  local_2 = func_80100094(param_0, 0);
  local_0 = local_2;
 local_0 = (char *) local_2; do { if ((*((s32 *) (((char *) local_2) + 0xA0))) != 0) { func_80101870(func_80106790(*((s32 *) (local_0 + 0x28))), param_1); } func_801018A4(param_0, param_1); local_1 = *((s32 *) (((char *) local_0) + 0x9C)); } while (0);
  if (local_1 != 0)
  {
    /* TU integration: position is a byte offset, not four Actor elements. */
    _subaddieskeleton_entrypoint_2(*param_0, 0xB, (u8 *)func_80106790(local_1) + 4);
  }
}

void func_80801070_changlerboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    u32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = (param_0->unk0->unk18 << 11) >> 28;
    if (func_800DA298(0x377)) {
        if (param_0->unk70_10 == 0x1A) {
            _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0, 3) + 0x103B, 0x144, param_0->position, 0xB4);
            func_808012E0_changlerboss(param_0, 0x1B);
        }
    } else {
        local_2 = local_1 - 1;
        if (*(s16 *)(local_0 + 0x92) == 0) {
            if (local_2 >= 0 && local_2 < 6 && !(local_0 + 0x1B)[local_2]) {
                func_808015F4_changlerboss(param_0, local_2, 2);
                func_808012E0_changlerboss(param_0, 9);
                ((f32 *)(local_0 + 0x24))[local_2] = 2.0f;
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802DAC_changlerboss);
                _subaddieaudioquick_entrypoint_2(param_0, (local_0 + 0x3C) + local_2 * 0xC, &D_80802F70_changlerboss);
                if (func_80801C50_changlerboss(param_0) == 5) {
                    func_80109FE8(param_0, 0);
                    func_808027F8_changlerboss(param_0);
                    func_808021E4_changlerboss(param_0, 0x1E, 0x30);
                }
            }
        } else if (local_1 == 8) {
            (*(s16 *)(local_0 + 0x96))--;
            if (!(*(s16 *)(local_0 + 0x96))) {
                func_80109FE8(param_0, 0);
                func_808012E0_changlerboss(param_0, 0x18);
                return;
            }
            if ((*(s16 *)(local_0 + 0x96)) == 5) {
                func_80109FE8(param_0, 0);
                func_808027F8_changlerboss(param_0);
                func_808021E4_changlerboss(param_0, 0x1E, 0x30);
                func_808012E0_changlerboss(param_0, 0x16);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802DAC_changlerboss);
                return;
            }
            if ((*(s16 *)(local_0 + 0x96)) == 3) {
                func_808012E0_changlerboss(param_0, 0x14);
                *(s16 *)(local_0 + 0x94) = 3;
                return;
            }
            func_808012E0_changlerboss(param_0, 0x16);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802DAC_changlerboss);
        }
    }
}

void func_808018E8_changlerboss();

void func_808012E0_changlerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    AnglerData88 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_80102424(param_0, param_1);
    switch (param_1) {
        case 2:
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802DA0_changlerboss);
            func_800FDC28(1);
            func_808021E4_changlerboss(param_0, 0, 48);
            func_80102424(func_80106790(local_0->local_3), 2);
            return;
        case 3:
            _chintrotext_entrypoint_1(0x18B9, 5, 1, 0);
            param_0->unk58 = 4.0f;
            return;
        case 5:
            param_0->unk58 = func_800DC178(4.0f, 6.0f);
            return;
        case 6:
        case 14:
            if (func_800EEB40(param_0->position, local_0->local_4[local_0->local_0]) < 640000.0f) {
                local_0->local_0 ^= 1;
            }
            func_80109FE8(param_0, 1);
            func_808018E8_changlerboss(param_0);
            return;
        case 7:
        case 15:
            local_0->local_0 ^= 1;
            local_0->local_2 = 0.0f;
            return;
        case 13:
            param_0->unk58 = func_800DC178(2.0f, 3.0f);
            return;
        case 8:
            if (func_80801C50_changlerboss(param_0) < 4) {
                local_0->local_1 = 2;
                return;
            }
            local_0->local_1 = 1;
            return;
        case 11:
            param_0->unk58 = 2.0f;
            func_808027F8_changlerboss(param_0);
            func_808021E4_changlerboss(param_0, 28, 48);
            func_800D2770(0xFE, 0);
            return;
        case 12:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x102B, 0x106, param_0->position, 0xB4);
            return;
        case 17:
            param_0->unk58 = 2.0f;
            return;
        case 19:
            local_0->local_1 = 1;
            return;
        case 22:
            func_80109FE8(param_0, 0);
            return;
        case 20:
            param_0->unk58 = func_800DC178(1.5f, 2.5f);
            return;
        case 24:
            func_800FDC28(0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802F80_changlerboss);
            func_808027F8_changlerboss(param_0);
            func_808021E4_changlerboss(param_0, 22, 56);
            return;
        case 25:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1029, 0x106, param_0->position, 0xB4);
            return;
        case 26:
            func_80109FE8(param_0, 1);
            param_0->unk58 = func_800DC178(5.0f, 8.0f);
            return;
        case 27:
        case 28:
            func_80109FE8(param_0, 0);
        default:
            return;
    }
}

void func_808015F4_changlerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    u8 *obj;
    s32 j;
    s32 k;
    s32 flag;
    s32 val;

    obj = func_80100094(param_0, 0);
    obj[param_1 + 0x1B] = param_2;
    for (j = 0; j != 3; j++) {
        k = 0;
        if (j == param_2) {
            flag = 1;
        } else {
            flag = 0;
        }
        for (; D_80802F8C_changlerboss[param_1][j][k] != -1; k++) {
            val = D_80802F8C_changlerboss[param_1][j][k];
            obj[val] = flag;
        }
    }
}

void func_808016A8_changlerboss(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = local_0;
    while (1)
    {
        local_0 = func_800DC128(0, 6);
        if (*(u8 *)((char *)(local_1 + local_0) + 0x1B) == 1)
        {
            break;
        }
    }

    func_808015F4_changlerboss(param_0, local_0, 0);
}

void func_80802288_changlerboss();

void func_8080170C_changlerboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x1027:
    case 0x1028:
        func_800FDC28(5);
        func_80802288_changlerboss(param_0);
        _plcamera_entrypoint_8(func_800F54E4());
        func_800DA544(0x1AF);
        _gcfrontend_entrypoint_9(0x26);
        func_808016A8_changlerboss(param_0);
        func_808012E0_changlerboss(param_0, 6);
        return;
    case 0x1029:
        func_808012E0_changlerboss(param_0, 0x1A);
        if (func_800D395C()) {
            func_80802288_changlerboss(param_0);
            _gcfrontend_entrypoint_10();
            return;
        }
        func_80108B04(param_0, 3);
        func_800DA544(0x377);
        return;
    case 0x102B:
        func_80802288_changlerboss(param_0);
        *(s16 *)(local_0 + 0x92) = 1;
        func_808012E0_changlerboss(param_0, 14);
        return;
    case 0x102A:
        func_80802288_changlerboss(param_0);
        func_808016A8_changlerboss(param_0);
        func_808012E0_changlerboss(param_0, 6);
        func_80109FE8(param_0, 1);
        return;
    case 0x1036:
        func_80802288_changlerboss(param_0);
        func_808012E0_changlerboss(param_0, 19);
        func_80109FE8(param_0, 1);
        return;
    case 0x1037:
    case 0x1038:
    case 0x1039:
    case 0x103A:
    case 0x103B:
    case 0x103C:
    case 0x103D:
        func_808012E0_changlerboss(param_0, 26);
        return;
    case 0x103E:
        local_0[0x12D] = 1;
        return;
    case 0xCEB:
        if (param_2 > 0) {
            _gcfrontend_entrypoint_11();
        } else {
            _gcfrontend_entrypoint_10();
        }
        return;
    }
}

void func_808018E8_changlerboss(u8 *param_0) {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    (*(f32 *)((s8 *)(param_0) + (0x24))) = 10.0f;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x12F))) != 0) {
        (*(f32 *)((s8 *)(temp_v0) + (0x98))) = 900.0f;
        return;
    }
    (*(f32 *)((s8 *)(temp_v0) + (0x98))) = 400.0f;
}

s32 func_80801948_changlerboss(param_0) Actor *param_0;
{
    AnglerBossApproach *local_0;

    local_0 = func_80100094(param_0, 0);
    *(f32 *)&param_0->actorData[3] = func_800F15F8(*(f32 *)&param_0->actorData[3], local_0->local_1, func_800D8FF8() * 600.0f);
    func_8010B990(param_0, 6);
    if (func_800EEB40(param_0->position, ((AnglerBossWaypoint *)((u8 *)local_0 + 0xA4))[local_0->local_0].local_0) < 160000.0f) {
        if (local_0->local_2) {
            local_0->local_2 = 0;
            local_0->local_1 = 400.0f;
        }
        return 1;
    }
    return 0;
}

void func_80801A10_changlerboss(Actor *param_0)
{
    AnglerPath721 *local_0;
    f32 local_1[2];
    f32 local_2;

    local_0 = (AnglerPath721 *)func_80100094(param_0, 0);
    local_2 = func_800D8FF8();
    func_800F18FC(param_0->position, local_0->local_1[local_0->local_0].local_0, local_1);
    param_0->unk50 = local_1[0];
    param_0->unk54 = local_1[1];
    param_0->rotation[1] = func_800F1FF0(param_0->rotation[1], param_0->unk54, 0.1f, local_2 + local_2, local_2 * 60.0f);
    param_0->rotation[0] = func_800F1FF0(param_0->rotation[0], param_0->unk50, 0.1f, local_2 + local_2, local_2 * 60.0f);
    func_80102CF4(param_0, 8.0f);
}

s32 func_80801AF0_changlerboss(Actor *param_0)
{
    AnglerAimState *local_0;
    f32 local_1[2];
    f32 local_2;
    f32 local_3[3];
    local_0 = func_80100094(param_0, 0);
    local_2 = func_800D8FF8();
    func_800F5A00(local_0->local_0, local_3);
    func_800F18FC(param_0->position, local_3, local_1);
    param_0->unk50 = local_1[0];
    param_0->unk54 = local_1[1];
    param_0->rotation[1] = func_800F1FF0(param_0->rotation[1], param_0->unk54, 0.1f, local_2 + local_2, local_2 * 60.0f);
    param_0->rotation[0] = func_800F1FF0(param_0->rotation[0], param_0->unk50, 0.1f, local_2 + local_2, local_2 * 60.0f);
    return func_80102CF4(param_0, 8.0f);
}

void func_80801BC8_changlerboss(Actor *param_0)
{
    f32 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_0->position[1] < local_0[0x3C]) {
        param_0->position[1] += func_800D8FF8() * 120.0f;
        if (param_0->position[1] > local_0[0x3C]) param_0->position[1] = local_0[0x3C];
    }
}

s32 func_80801C50_changlerboss(param_0) Actor *param_0;
{
    AnglerPiecesState *local_0;
    s32 local_1;
    s32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    for (local_2 = 0; local_2 < 6; local_2++) {
        if (local_0->local_0[local_2] != 2) local_1++;
    }
    return local_1;
}

s32 func_80801CD8_changlerboss(s32 param_0) {
    if (func_8001210C(3) == 0) {
        func_80108B04(param_0, 2);
    }
}

void func_80801D0C_changlerboss(s32 *param_0) {
    u8 *local_0;
    u8 *local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_801084B0(0x298, &param_0);
    (*(s32 *)((s8 *)(local_1) + (0x3C))) = (s32) *param_0;
    (*(s32 *)((s8 *)(local_0) + (0xA0))) = (s32) (*(s32 *)((s8 *)(local_1) + (0)));
    _subaddieDll_entrypoint_0(local_1);
    func_8010A800(local_1, 2);
    func_8010A570(local_1);
    (*(u8 *)((s8 *)(local_1) + (0x65))) = (u8) ((*(u8 *)((s8 *)(local_1) + (0x65))) & 0xFFFE);
    _subaddieskeleton_entrypoint_2(*param_0, 0xB, local_1 + 4);
}

int func_80801DA0_changlerboss(Actor *param_0)
{
    Actor *local_0;
    Actor *local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_801084B0(0x45E, &param_0);
    func_80102FDC(local_1, *(f32 *)((char *)param_0 + 0x38));
    *(s32 *)((char *)local_1 + 0x3C) = (s32)*(s32 *)((char *)param_0 + 0x0);
    *(s32 *)((char *)local_0 + 0x9C) = (s32)*(s32 *)((char *)local_1 + 0x0);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(local_1, 2);
    } else if (func_800DA298(0x1AF) != 0) {
        func_80102424(local_1, 3);
    }
    return param_0;
}

void func_80801E3C_changlerboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    s32 pad;
    u8 *local_2;
    Actor *local_3;
    f32 local_4;

    func_800F5A00(*(s16 *)((u8 *)func_80100094(param_0, 0) + 0x128), local_0);
    if (_subaddieskeleton_entrypoint_2(param_0->unk0, 0xB, local_1)) {
        local_2 = func_80100094(param_0, 0);
        local_3 = func_80108528(0x45F, local_1, 0, &param_0);
        func_800EFB24((f32 *)((u8 *)local_3 + 0x28), local_0, local_3->position);
        ((AnglerBits *)local_3)->unk6E_0 = *(s16 *)(local_2 + 0x128);
        if (*(s16 *)(local_2 + 0x92) == 0) {
            local_4 = 1000.0f;
        } else {
            local_4 = func_800F10B4(*(s16 *)(local_2 + 0x96), 1.0f, 3.0f, 2000.0f, 1500.0f);
            local_3->unk64_20 = 1;
        }
        func_800EF368((f32 *)((u8 *)local_3 + 0x28), local_4);
        *(void **)((u8 *)local_3 + 0x3C) = param_0->unk0;
    }
}

void func_80801F54_changlerboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_4;
    Actor *local_5;
    _subaddieskeleton_entrypoint_2(param_0->unk0, 10, local_1);
    for (local_4 = 0; local_4 < 3; local_4++) {
        func_800EE7F8(local_0, local_1);
        func_800EF214(local_0, param_0->rotation[0] + (func_800DC178(-10.0f, 10.0f)), param_0->rotation[1] + (func_800DC178(-10.0f, 10.0f)), func_800DC178(200.0f, 300.0f));
        local_5 = (Actor *)func_80108528(0x460, local_0, 0, &param_0);
        if (local_5) {
            func_800EFB24((f32 *)&local_5->actorData[4], local_5->position, local_1);
            func_800EF368((f32 *)&local_5->actorData[4], func_800DC178(1000.0f, 1400.0f));
            local_5->unk3C = param_0->unk0;
            func_80102FDC(local_5, func_800DC178(0.8f, 1.2f));
        }
    }
}

void func_80802108_changlerboss(Actor *param_0)
{
    AnglerCleanup1358 *local_0;
    s32 local_1;
    Unk80132ED0 *local_2;
    f32 local_3[3];
    f32 *local_4;
    Actor *local_5;

    local_0 = func_80100094(param_0, 0);
    local_2 = param_0->unk0;
    local_4 = NULL;
    func_800FFA88(local_0->local_1);
    local_0->local_1 = NULL;
    func_8010114C(local_0->local_0, 0x2C, 0);
    local_0->local_0 = NULL;
    if (_subaddieskeleton_entrypoint_2(param_0->unk0, 11, local_3)) {
        local_4 = local_3;
    }
    local_1 = func_800D10D4(0x25, 1, local_4, 0, 0);
    param_0 = func_80106790(local_2);
    if (local_1) {
        local_5 = func_80106790((Unk80132ED0 *)local_1);
        ((BitTest31 *)((u8 *)local_5 + 0x70))->flag = 1;
        func_80802210_changlerboss(param_0, (Unk80132ED0 *)local_1, 25, 0x438);
    }
}

void func_808021E4_changlerboss(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    func_80802210_changlerboss(param_0, *param_0, param_1, param_2);
}

void func_80802210_changlerboss(param_0, param_1, param_2, param_3) Actor *param_0; Unk80132ED0 *param_1; u32 param_2; u32 param_3;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0[0x12B]) {
        _capod_entrypoint_14();
        param_3 |= 0x2000;
    }
    _capod_entrypoint_13(param_1, param_0->unk0, param_2, param_3);
    local_0[0x12B] = 1;
}

void func_80802288_changlerboss(s32 param_0) {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if (sp1C[0x12B] != 0) {
        _capod_entrypoint_14();
        sp1C[0x12B] = 0;
    }
}

void func_808022C4_changlerboss(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    u8 *local_2;
    local_0 = param_0->unk70_10;
    if (local_0 != 0xB && local_0 != 0xC && local_0 >= 5 && local_0 < 0x19) {
        local_2 = func_80100094(param_0, 0);
        if (*(s16 *)(local_2 + 0x92) == 0) {
            local_1 = func_80801C50_changlerboss(param_0);
        } else {
            local_1 = *(s16 *)(local_2 + 0x96);
        }
        func_800D2498(0xFE, local_1, 0);
    }
}

void func_80802340_changlerboss(param_0) Actor *param_0;
{
    switch (func_801022E4(param_0)) {
        case 0x3EC:
            if (func_80102320(param_0, 0.25f, 0.8f) && func_800DC298(0.15f)) {
                func_80802430_changlerboss(param_0);
            }
            break;
        case 0x330:
            if (func_80102320(param_0, 0.25f, 0.75f) && func_800DC298(0.1f)) {
                func_80802430_changlerboss(param_0);
            }
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80802FF8_changlerboss, 0.4f);
            break;
        case 0x33F:
            if (func_80101E14(param_0, 0.85f)) {
                func_80802430_changlerboss(param_0);
            }
            break;
    }
}

int func_80802430_changlerboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    f32 local_3;
    if (param_0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(param_0->unk0, 10, local_0);
        local_1 = func_800DC128(1, 3);
        local_2 = func_800B53A4(local_1);
        local_3 = param_0->scale * 1.3f;
        func_800BABB8(local_2, local_0, NULL, 1.0f, &D_80803008_changlerboss);
        func_800BA568(local_2, (s16)(s32)(local_0[1] + 1000.0f));
        func_800BA7C4(local_2, 0.16f * local_3, 0.3f * local_3);
        func_800BA7FC(local_2, 0.45f * local_3, 0.6f * local_3);
        func_800BA994(local_2, -75, (s16)(s32)(param_0->rotation[1] - 75.0f), 800, -35, (s32)(param_0->rotation[1] + 75.0f), 1000);
        func_800BA22C(local_2, local_1);
    }
}

s32 func_808025AC_changlerboss(s32 param_0)
{
  s32 v0;
  s32 v1;
  v0 = func_8010D290(0x400);
  v1 = v0;
  if (v1 == (-1))
  {
    v1 = func_800F54E4();
  }
  else
  {
    v1 = v1;
  }
  return v1;
}

void func_808025EC_changlerboss(Actor *param_0)
{
    s32 local_1;
    AnglerSkeletonState *local_0;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 6; local_1++) {
        _subaddieskeleton_entrypoint_2(param_0->unk0, D_80803054_changlerboss[local_1], local_0->local_0[local_1]);
    }
    _subaddieskeleton_entrypoint_2(param_0->unk0, 0xC, local_0->local_1);
}

void func_80802680_changlerboss(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    u8 *local_3;
    u8 *local_4;
    f32 *local_7;
    s32 local_5;
    s32 local_6;
    local_1 = func_800D8FF8();
    local_3 = func_80100094(param_0, 0);
    func_80103DFC(param_0, local_0);
    local_0[1] -= 600.0f;
    for (local_6 = 0, local_4 = local_3; local_6 < 6; local_6++, local_4 += 4) {
        local_7 = (f32 *)local_3;
        local_7 = (f32 *)((u8 *)local_7 + local_6 * 12 + 0x3C);
        if (*(f32 *)(local_4 + 0x24) > 0.0f) {
            if (1) {}
            if (1) {}
            local_2 = func_800F10B4(*(f32 *)(local_4 + 0x24), 0.0f, 2.0f, 0.75f, 1.0f);
            *(f32 *)(local_4 + 0x24) -= local_1;
            local_5 = func_800B53A4(1);
            func_800BABB8(local_5, local_7, local_0, local_2, &D_80803060_changlerboss);
            func_800BA22C(local_5, 1);
        }
    }
}

void func_808027F8_changlerboss(param_0) u8 *param_0; {
    f32 local_0[3];
    f32 local_1;
    func_800EFD24(local_0);
    local_1 = func_80102D78(param_0, local_0);
    *(f32 *)(param_0 + 0x54) = local_1;
    *(f32 *)(param_0 + 0x48) = local_1;
    *(f32 *)(param_0 + 0x50) = 0.0f;
    *(f32 *)(param_0 + 0x44) = 0.0f;
}

void func_80802844_changlerboss(Actor *param_0)
{
  *((f32 *) (((char *) param_0) + 0x58)) = 0.4f;
  *((u8 *) (((char *) param_0) + 0x7A)) = ((*((u8 *) (((char *) param_0) + 0x7A))) & 0xFF3F) | 0x80;
  *((s32 *) (((char *) param_0) + 0x54)) = func_800C8A98();
}

void func_80802888_changlerboss(Actor *param_0)
{
    s32 local_0[3];
    f32 local_1;
    s32 local_2[3];
    s32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;

    switch (param_0->unk70_10) {
    case 1:
        local_1 = param_0->scale * 0.3f;
        param_0->unk64_16 = 0;
        func_800F2F60(local_0, D_80803098_changlerboss, 0.3f);
        func_800C8E54(*(s32 *)&param_0->unk54, local_1 * 400.0f, local_1 * 1000.0f);
        func_800C8E84(*(s32 *)&param_0->unk54, local_0);
        break;
    case 2:
        local_3 = func_800D9078(&param_0->unk58);
        local_4 = func_800F12D4(param_0->unk58, 0.0f, 0.4f, 1.0f, 0.3f);
        local_5 = param_0->scale * local_4;
        param_0->unk64_16 = 1;
        func_800F2F60(local_2, D_80803098_changlerboss, local_4);
        func_800C8E54(*(s32 *)&param_0->unk54, local_5 * 400.0f, local_5 * 1000.0f);
        func_800C8E84(*(s32 *)&param_0->unk54, local_2);
        _subaddiefade_entrypoint_1(param_0, (s32)(local_4 * 255.0f));
        if (local_3) { func_80101FDC(param_0, 3); }
        break;
    case 3:
        local_1 = param_0->scale;
        param_0->unk64_16 = 1;
        func_800C8E54(*(s32 *)&param_0->unk54, local_1 * 400.0f, local_1 * 1000.0f);
        func_800C8E84(*(s32 *)&param_0->unk54, D_80803098_changlerboss);
        break;
    }
    if (*(s32 *)&param_0->unk54) {
        func_800C8CB8(*(s32 *)&param_0->unk54, param_0->position);
    }
}

s32 func_80802A90_changlerboss(u8 *param_0, s32 param_1, s32 param_2) {
    s32 temp_a0;

    if (param_1 == 0x2C) {
        temp_a0 = (*(s32 *)((s8 *)(param_0) + (0x54)));
        if (temp_a0 != 0) {
            (*(s32 *)((s8 *)(param_0) + (0x54))) = _chlightfader_entrypoint_1(temp_a0, 0x3F800000, 3, param_0);
        }
        _subaddiefade_entrypoint_3(param_0);
        func_80101FDC(param_0, 4);
    } else {
        return 0;
    }
    return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/anglerboss.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80802DA0_changlerboss -> s32[], D_80802DAC_changlerboss -> s32[], D_80802EB4_changlerboss -> int[], D_80802EFC_changlerboss -> int[], D_80802F70_changlerboss -> s32[], D_80802F80_changlerboss -> s32[] */
extern int func_80101870();
s32 D_80802DA0_changlerboss[3] = { 0x1305E2, 0x180002, 0x0 };
s32 D_80802DAC_changlerboss[4] = { 0x1305E2, 0x18000D, 0xCC00E6, 0x20000 };
u8 D_80802DBC_changlerboss[248] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x2C, 0xCC, 0xCD, 0x3, 0xEB, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0xEC, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x3E, 0x0, 0x1, 0x3F, 0xC0, 0x0, 0x0, 0x3, 0x3F, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x3E, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x3E, 0x0, 0x42, 0x40, 0x0, 0x0, 0x0, 0x3, 0x3E, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x3E, 0x0, 0x1, 0x3F, 0xC0, 0x0, 0x0, 0x3, 0x3F, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x41, 0x13, 0x33, 0x33, 0x3, 0x40, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x3, 0x41, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x41, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x41, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x3, 0xEC, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x3, 0x30, 0x0, 0x1 };
int D_80802EB4_changlerboss[18] = { 0x2045D, 0x7F90001, (u32)&D_80802DBC_changlerboss, (u32)func_808002E0_changlerboss, (u32)func_80105834, (u32)func_80800FEC_changlerboss, 0x752F, 0x0, 0x0, 0x468, 0x0, (u32)func_80108ED0, 0x1300000, (u32)func_80800018_changlerboss, (u32)func_80107C2C, -0x7F1EFBFE, (u32)func_80800B7C_changlerboss, 0x0 };
int D_80802EFC_changlerboss[18] = { 0x158045E, 0x7FB0001, 0x0, (u32)func_80802888_changlerboss, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x21404, 0x0, 0x0, 0x0, (u32)func_80802844_changlerboss, (u32)func_80107C2C, -0x7FFFFFFE, (u32)func_80802A90_changlerboss, 0x0 };
u8 D_80802F44_changlerboss[12] = { 0x0, 0x13, 0x6, 0x92, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802F50_changlerboss[16] = { 0x0, 0x13, 0x5, 0xE3, 0x0, 0x18, 0x0, 0x2, 0x0, 0xD, 0x1, 0x40, 0x1, 0x59, 0x0, 0x0 };
u8 D_80802F60_changlerboss[16] = { 0x0, 0x13, 0x5, 0xE4, 0x0, 0x18, 0x0, 0x2, 0x0, 0xD, 0x1, 0x40, 0x1, 0x59, 0x0, 0x0 };
s32 D_80802F70_changlerboss[4] = { 0x13060F, 0xD00C0, 0xD90018, 0x20000 };
s32 D_80802F80_changlerboss[3] = { 0x1305E1, 0x180002, 0x0 };
s16 D_80802F8C_changlerboss[6][3][3] = { 0x3, 0x6, -0x1, 0x4, 0x7, -0x1, 0x5, 0x8, -0x1, 0x9, -0x1, 0x0, 0xA, -0x1, 0x0, 0xB, -0x1, 0x0, 0xC, 0xF, -0x1, 0xD, 0x10, -0x1, 0xE, 0x11, -0x1, 0x12, -0x1, 0x0, 0x13, -0x1, 0x0, 0x14, -0x1, 0x0, 0x15, -0x1, 0x0, 0x16, -0x1, 0x0, 0x17, -0x1, 0x0, 0x18, -0x1, 0x0, 0x19, -0x1, 0x0, 0x1A, -0x1, 0x0 };
u8 D_80802FF8_changlerboss[16] = { 0x0, 0x13, 0x3, 0xFD, 0x0, 0xD, 0x0, 0xA6, 0x0, 0xC0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80803008_changlerboss[76] = { 0x0, 0x1D, 0x9, 0xD9, 0x0, 0x16, 0x12, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x23, 0x0, 0x0, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0, 0x7, 0x0, 0x1, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0xE, 0x0, 0x32, 0x0, 0x3C, 0x0, 0x2B, 0x1, 0x80, 0x4, 0x80, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0, 0x0, 0x0 };
s16 D_80803054_changlerboss[6] = { 0x4, 0x5, 0x6, 0x7, 0x8, 0x9 };
u8 D_80803060_changlerboss[56] = { 0x0, 0x1D, 0x9, 0xD3, 0x0, 0x22, 0x0, 0xCC, 0x1, 0x0, 0x0, 0x19, 0x0, 0x26, 0x0, 0x16, 0x22, 0x0, 0x0, 0x2D, 0x3, 0x20, 0x3, 0xE8, 0x0, 0x15, 0x0, 0x0, 0x0, 0xC0, 0x0, 0xE, 0x0, 0x14, 0x0, 0x50, 0x0, 0x2B, 0x1, 0x40, 0x1, 0xC0, 0x0, 0x30, 0x0, 0xF0, 0x0, 0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0, 0x0, 0x0, 0x0 };
s32 D_80803098_changlerboss[6] = { 0xFF, 0xFF, 0x60, 0x0, 0x0, 0x0 };
