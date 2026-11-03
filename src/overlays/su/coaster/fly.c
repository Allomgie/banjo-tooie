#include "su/coasterfly.h"

#define OD(n) (((f32 *) param_0->actorData)[n])
extern int D_80802280_sucoasterfly[];
typedef struct {
    u8 pad_0[0xC];
    f32 local_0;
    u8 pad_1;
    u8 local_1 : 4;
    u8 pad_2 : 4;
    u8 pad_3[6];
    s16 local_2;
} CoasterFlightRoute;
extern void *func_80100074(Actor *, u32, u32);
typedef struct {
    u32 pad74_4 : 28;
    u32 unk74_0 : 4;
} ActorFlags74;
typedef struct {
    u8 pad0[0x11];
    u8 unk11_4 : 4;
    u8 unk11_0 : 4;
} CoasterFlyLocal;
extern s32 _subaddieDll_entrypoint_3(Actor *);
extern s32 func_80107070(Actor *, s32);
extern void _subaddiefade_entrypoint_3(Actor *);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_13(void *, f32 *, f32 *);
extern void func_80101010(f32 *);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern s32 _sucoasterflydata_entrypoint_2(s32, s32 *);
extern void func_80101074(s32);
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest : 10;
} FlyActor;
typedef struct {
    u8 pad[0x24];
    u32 f24 : 10;
    u32 r24 : 22;
} FlyObj;
extern u8 *func_80106790(s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEF94(f32 *);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern s32 _glhittableDll_entrypoint_10(u8 *);
extern s32 _glhittableDll_entrypoint_9(u8 *);
extern s32 _glhittableDll_entrypoint_6(u8 *);
extern s32 _glhittableDll_entrypoint_8(u8 *);
extern s32 func_800F70EC(s32);
extern s32 func_800F6C1C(s32);
extern s32 func_800F0E28(s32, s32, u8 *, u8 *);
extern void func_80109600(u8 *, u8 *, u8 *, s32);
extern void _chflamer_entrypoint_1(u8 *, u8 *, u8 *);
extern void func_800EC370(u8 *, s32 *, u8 *);
extern void _chfreezy_entrypoint_1(u8 *, s32 *);
extern s32 func_8010A430(u8 *);
extern s32 func_800F54E4(void);
extern f32 func_800F5F24(s32);
extern void func_800EB860(void *, u8 *);
extern f32 func_800EC708(s32);
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
extern void func_800EB874(void);
extern void func_8010D930(s32, s32, u8 *, u8 *);
extern void _subaddiejoy_entrypoint_10(u8 *, f32, f32);
extern u8 D_80802294_sucoasterfly[];
extern u8 func_80108EF4[];
extern u8 _chbaddiesetup_entrypoint_10[];
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800F0D50(f32, f32, f32);
extern void func_80102924(Actor *, f32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} CoasterFlyMovementFlags;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 1;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 pad_2 : 29;
    u8 pad_3[16];
    u32 pad_4 : 28;
    u32 local_2 : 1;
    u32 pad_5 : 3;
} CoasterFlyEligibility;
typedef struct {
    u8 pad_0[0x10];
    u32 pad_1 : 12;
    u32 local_0 : 1;
    u32 pad_2 : 19;
} CodexCoasterFlyFlags;
typedef struct {
    u32 pad_0 : 2;
    u32 local_0 : 1;
    u32 pad_1 : 29;
} CodexCoasterActorFlags;
extern s32 func_80101E14(Actor *, f32);
extern f32 func_8010CD28(Actor *);
extern s32 func_800F20BC(f32, f32, f32);
typedef struct {
    u8 pad_0[0x18];
    s16 local_0;
} FlightClearance1570;
extern void func_8008FE94(s32, f32 *);
extern int func_80104544(Actor *);
extern f32 func_8010473C(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern int func_800CC338(f32 *, s32, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 local_1 : 1;
    u32 pad_5 : 2;
} CoasterFlyUpdateFlags;
typedef struct {
    u8 pad_0[0x10];
    u32 pad_1 : 12;
    u32 local_0 : 1;
    u32 pad_2 : 19;
} CoasterFlyUpdateLocalFlags;
extern f32 func_80107C00(void);
extern void func_800D9078(f32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern s32 func_800DC298(f32);
extern void func_80102D98(Actor *, s32, s32, f32, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_80102CF4(Actor *, f32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, u8, f32, f32, f32);
extern f32 func_800F5BF0(s32, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern s32 func_8010B990(Actor *, s32);
extern void func_800EE88C(f32 *, s16 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10;
    u8 unk11_4 : 4;
    u8 unk11_3 : 1;
    u8 pad11 : 3;
    s16 unk12[3];
} FlyData;
typedef struct {
    u8 pad0[0x24];
    s16 unk24;
    s16 unk26;
} FlyInfo;
typedef struct {
    u8 pad0[0x14];
    u32 pad14_20 : 12;
    u32 unk14_19 : 1;
    u32 pad14_0 : 19;
    u8 pad18[0x64 - 0x18];
    u32 unk64_31 : 1;
    u32 unk64_30 : 1;
    u32 pad64_26 : 4;
    u32 unk64_25 : 1;
    u32 unk64_24 : 1;
    u32 pad64_0 : 24;
    u8 pad68[8];
    u32 unk70_25 : 7;
    u32 pad70_10 : 15;
    u32 unk70_4 : 6;
    u32 pad70_0 : 4;
    u32 pad74_4 : 28;
    u32 unk74_0 : 4;
} FlyBits;
extern u8 D_808022AC_sucoasterfly[];
extern FlyInfo *_sucoasterflydata_entrypoint_1(s32);
extern void func_80102424(Actor *, s32);
extern s32 _sucoasterflydata_entrypoint_3(s32);
extern s32 _sucoasterflydata_entrypoint_4(s32);
extern s32 _sucoasterflydata_entrypoint_5(s32);
extern s32 func_800DC128(s32, s32);
extern void func_800EE940();
extern void func_8010A570(Actor *);
extern void _subaddieaudioquick_entrypoint_2();
typedef struct {
    u8 pad_0[0xC];
    f32 local_0;
} CoasterFlySpeed1482;
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
typedef struct CoasterFlyJoyFlag {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} CoasterFlyJoyFlag;
extern u8 D_808022BC_sucoasterfly[];
extern f32 func_800DC178(f32, f32);
extern void func_800C4B64(f32);
f32 func_80801E5C_sucoasterfly();
s32 func_80801FE4_sucoasterfly(u8 *param_0, f32 *param_1, f32 param_2, f32 param_3);
void func_80802080_sucoasterfly();
extern void func_808014AC_sucoasterfly(Actor *, s32);
extern void func_8080181C_sucoasterfly(Actor *);
void func_80801CD0_sucoasterfly();

int sucoasterfly_entrypoint_0()
{
    return (int) &D_80802280_sucoasterfly;
}

s32 sucoasterfly_entrypoint_1(Actor *param_0, s32 param_1)
{
    CoasterFlightRoute *local_1;
    f32 local_0;

    local_1 = func_80100074(param_0, 0, param_1 + 0x1C);
    local_1->local_1 = _sucoasterflydata_entrypoint_0(param_0);
    _subaddierouteDll_entrypoint_3(param_0, local_1, param_0->position);
    local_1->local_0 = 0.0f;
    local_0 = param_0->position[1] - 400.0f;
    func_80801FE4_sucoasterfly(param_0, &local_0, 50.0f, -1500.0f);
    local_1->local_2 = (s32) (param_0->position[1] - local_0);
    return 1;
}

void sucoasterfly_entrypoint_2(Actor *arg0)
{
    func_80802128_sucoasterfly(arg0);
}

extern s32 func_8080215C_sucoasterfly(s32);

extern void func_80801C44_sucoasterfly(Actor *, s32);

extern s32 func_80801B90_sucoasterfly(Actor *);

extern s32 func_80801AB0_sucoasterfly(Actor *);

extern s32 func_80801A80_sucoasterfly(s32);

extern void func_808019A0_sucoasterfly(Actor *);

void sucoasterfly_entrypoint_3(Actor *param_0)
{
    char *local_0;
    f32 local_2;
    f32 local_1;
    f32 local_3;
    void *local_13;

    local_0 = (char *) func_80100094(param_0, 0);
    local_1 = func_800D8FF8();

    if (((CoasterFlyUpdateFlags *) param_0)->local_1) {
        return;
    }

    func_800D9078((char *) param_0 + 0x58);

    local_2 = *(f32 *) ((char *) param_0 + 0x48);

    if (func_80100094(param_0, 1) != 0) {
        local_13 = func_80100094(param_0, 1);
        _suexpression_entrypoint_10(local_13, *(s32 *) param_0, 0);
    }

    switch (param_0->unk70_10) {
        case 1: {
            f32 local_3;

            func_80801C44_sucoasterfly(param_0, 0);

            if (((CoasterFlyUpdateFlags *) param_0)->local_0) {
                local_3 = _subaddiejoy_entrypoint_9(param_0, (char *) param_0 + 0x54, 3);

                if (0.2f < local_3) {
                    func_808014AC_sucoasterfly(param_0, 3);
                }

                func_80801DD0_sucoasterfly(param_0);
            } else {
                if (!func_80801AB0_sucoasterfly(param_0) &&
                    *(f32 *) ((char *) param_0 + 0x58) <= 0.0f && func_800DC298(0.02f)) {
                    func_808014AC_sucoasterfly(param_0, 3);
                }

                func_80102D98(param_0, 0x3F, 0, 0.3f, 20.0f, 40.0f);
            }

            func_80102BF8(param_0, 0.1f, 4.0f, 150.0f);
            func_808019A0_sucoasterfly(param_0);
            break;
        }

        case 2:
            func_80801C44_sucoasterfly(param_0, 0);
            func_80102BF8(param_0, 0.1f, 4.0f, 150.0f);

            if (func_80102CF4(param_0, 6.0f)) {
                func_808014AC_sucoasterfly(param_0, 3);
            }
            break;

        case 3: {
            f32 local_3;

            func_80801C44_sucoasterfly(param_0, 0);

            if (((CoasterFlyUpdateFlags *) param_0)->local_0) {
                local_3 = _subaddiejoy_entrypoint_9(param_0, (char *) param_0 + 0x54, 3);

                func_80102BF8(param_0, 0.1f, 4.0f, 150.0f);

                if (local_3 == 0.0f) {
                    func_808014AC_sucoasterfly(param_0, 1);
                }

                func_80801DD0_sucoasterfly(param_0);
            } else {
                if (_subaddierouteDll_entrypoint_4(param_0)) {
                    local_3 = func_80107C00();

                    _subaddierouteDll_entrypoint_7(
                        param_0, local_0, *(f32 *) ((char *) param_0 + 0x48),
                        *(f32 *) ((char *) param_0 + 0x54), local_3 * 300.0f, 0x4802);

                    *(u8 *) (local_0 + 0x10) = *(u16 *) (local_0 + 6);
                }

                if (!func_80801AB0_sucoasterfly(param_0) &&
                    *(f32 *) ((char *) param_0 + 0x58) <= 0.0f && func_800DC298(0.02f)) {
                    func_808014AC_sucoasterfly(param_0, 1);
                }

                _subaddierouteDll_entrypoint_5(param_0, local_0, *(u8 *) (local_0 + 0x10), 0.1f,
                                               4.0f, 150.0f);
            }

            func_808019A0_sucoasterfly(param_0);
            break;
        }

        case 4: {
            f32 local_3;

            func_80801C44_sucoasterfly(param_0, 0);

            if (_subaddierouteDll_entrypoint_4(param_0)) {
                *(f32 *) ((char *) param_0 + 0x54) = func_8010CD28(param_0);

                local_3 = func_80107C00();

                _subaddierouteDll_entrypoint_7(param_0, local_0, *(f32 *) ((char *) param_0 + 0x48),
                                               *(f32 *) ((char *) param_0 + 0x54), local_3 * 300.0f,
                                               0x4802);

                *(u8 *) (local_0 + 0x10) = *(u16 *) (local_0 + 6);
            }

            _subaddierouteDll_entrypoint_5(param_0, local_0, *(u8 *) (local_0 + 0x10), 0.1f, 4.0f,
                                           180.0f);

            func_808019A0_sucoasterfly(param_0);

            if (((CoasterFlyUpdateFlags *) param_0)->local_0) {
                func_808014AC_sucoasterfly(param_0, 1);
                break;
            }

            if (func_80801B90_sucoasterfly(param_0)) {
                break;
            }

            if (!func_80102CF4(param_0, 20.0f)) {
                break;
            }

            if (func_801021BC(param_0, 5)) {
                func_808014AC_sucoasterfly(param_0, 5);
            } else {
                func_808014AC_sucoasterfly(param_0, 6);
            }
            break;
        }

        case 5: {
            f32 local_3;

            func_80801C44_sucoasterfly(param_0, 1);

            if (_subaddierouteDll_entrypoint_4(param_0)) {
                *(f32 *) ((char *) param_0 + 0x54) = func_8010CD28(param_0);

                local_3 = func_80107C00();

                _subaddierouteDll_entrypoint_7(param_0, local_0, *(f32 *) ((char *) param_0 + 0x48),
                                               *(f32 *) ((char *) param_0 + 0x54), local_3 * 300.0f,
                                               0x4802);

                *(u8 *) (local_0 + 0x10) = *(u16 *) (local_0 + 6);
            }

            _subaddierouteDll_entrypoint_5(param_0, local_0, *(u8 *) (local_0 + 0x10), 0.1f, 4.0f,
                                           180.0f);

            func_808019A0_sucoasterfly(param_0);

            if (func_80801B90_sucoasterfly(param_0)) {
                break;
            }

            if (func_80101DDC(param_0)) {
                func_808014AC_sucoasterfly(param_0, 6);
            }
            break;
        }

        case 6: {
            f32 local_6[3];
            f32 local_3;
            f32 local_4;
            f32 local_7[3];
            s32 local_12;
            s32 local_11;

            local_12 = func_800F54E4();
            local_3 = func_800F5BF0(local_12, local_6);

            func_80801C44_sucoasterfly(param_0, 0);

            if (!func_800F0008((f32 *) param_0->position, 300.0f, local_6, local_3)) {
                func_80801A80_sucoasterfly(param_0);
            }

            if (((CoasterFlyUpdateFlags *) param_0)->local_0) {
                local_3 = _subaddiejoy_entrypoint_3(param_0);

                if (0.0f < local_3) {
                    local_4 = func_800F1DCC(*(f32 *) ((char *) param_0 + 0x54),
                                            *(f32 *) ((char *) param_0 + 0x48));

                    if (local_4 < -30.0f) {
                        *(f32 *) ((char *) param_0 + 0x54) =
                            *(f32 *) ((char *) param_0 + 0x48) - 30.0f;
                    } else if (30.0f < local_4) {
                        *(f32 *) ((char *) param_0 + 0x54) =
                            *(f32 *) ((char *) param_0 + 0x48) + 30.0f;
                    }
                }
            } else {
                *(f32 *) ((char *) param_0 + 0x54) =
                    func_80102D78(param_0, (char *) param_0 + 0x18);
            }

            func_80102BF8(param_0, 0.1f, 4.0f, 180.0f);

            if (func_80801B90_sucoasterfly(param_0)) {
                break;
            }

            local_11 = ((CoasterFlyUpdateFlags *) param_0)->local_0 ? 0x00604027 : 0x00600307;

            func_8080181C_sucoasterfly(param_0);

            func_800EFB24(local_7, (f32 *) param_0->actorData, (char *) param_0 + 4);

            func_800EF368(local_7, *(f32 *) ((char *) param_0 + 0x24));

            local_3 = func_800EEFFC(local_7);

            func_800EFCD8((char *) param_0 + 0x28, *(f32 *) ((char *) param_0 + 0x48), local_3);

            *(f32 *) ((char *) param_0 + 0x2C) = local_7[1];

            local_12 = func_8010B990(param_0, local_11);

            if (local_12 & 0x24) {
                func_808014AC_sucoasterfly(param_0, 8);
                break;
            }

            local_3 = func_80102D78(param_0, (f32 *) param_0->actorData);

            if (func_800F20BC(*(f32 *) ((char *) param_0 + 0x48), local_3, 100.0f)) {
                break;
            }

            func_808014AC_sucoasterfly(param_0, 7);
            break;
        }

        case 7: {
            s32 local_12;
            s32 local_11;

            if (((CoasterFlyUpdateFlags *) param_0)->local_0) {
                local_11 = 0x00604027;
            } else {
                local_11 = 0x00600307;
            }

            func_80801C44_sucoasterfly(param_0, 0);
            func_80102BF8(param_0, 0.1f, 4.0f, 150.0f);
            func_8080181C_sucoasterfly(param_0);

            if (30.0f < *(f32 *) ((char *) param_0 + 0x24)) {
                func_800EF368((char *) param_0 + 0x28, *(f32 *) ((char *) param_0 + 0x24));

                local_12 = func_8010B990(param_0, local_11);

                if ((local_12 & 0x24) != 0 || *(f32 *) ((char *) param_0 + 0x24) == 0.0f) {
                    func_808014AC_sucoasterfly(param_0, 8);
                }
            } else {
                if (*(u8 *) ((char *) param_0 + 0x64) & 1) {
                    func_808014AC_sucoasterfly(param_0, 3);
                } else {
                    func_808014AC_sucoasterfly(param_0, 8);
                }
            }
            break;
        }

        case 8: {
            f32 local_9[3];
            f32 local_4;
            f32 local_3;
            f32 local_8[3];

            local_4 = func_800D8FF8();
            local_4 *= 10.0f * *(f32 *) (local_0 + 0xC);

            func_80801C44_sucoasterfly(param_0, 0);

            if (_subaddierouteDll_entrypoint_4(param_0)) {
                func_800EE88C(local_8, local_0 + 0x12);

                *(f32 *) ((char *) param_0 + 0x54) = func_80102D78(param_0, local_8);

                local_3 = func_80107C00();

                _subaddierouteDll_entrypoint_7(param_0, local_0, *(f32 *) ((char *) param_0 + 0x48),
                                               *(f32 *) ((char *) param_0 + 0x54), local_3 * 300.0f,
                                               0x4802);

                *(u8 *) (local_0 + 0x10) = *(u16 *) (local_0 + 6);
            }

            _subaddierouteDll_entrypoint_5(param_0, local_0, *(u8 *) (local_0 + 0x10), 0.1f, 4.0f,
                                           150.0f);

            func_808019A0_sucoasterfly(param_0);

            func_800EE88C(local_9, local_0 + 0x12);

            if (func_80102CF4(param_0, 6.0f) ||
                func_800EEB40((f32 *) param_0->position, local_9) < local_4 * local_4) {
                func_808014AC_sucoasterfly(param_0, 9);
            }
            break;
        }

        case 9: {
            f32 local_10[3];
            f32 local_4;

            local_4 = func_800D8FF8();
            local_4 *= 10.0f * *(f32 *) (local_0 + 0xC);

            func_80801C44_sucoasterfly(param_0, 0);
            func_80102BF8(param_0, 0.1f, 4.0f, 150.0f);

            func_800EE88C(local_10, local_0 + 0x12);

            if (func_800EEB40(param_0->position, local_10) < local_4 * local_4) {
                param_0->unk64_24 = 1;
                func_808014AC_sucoasterfly(param_0, 3);
            } else {
                func_8080181C_sucoasterfly(param_0);

                func_800EFB24((char *) param_0 + 0x28, local_10, param_0->position);

                func_800EF368((char *) param_0 + 0x28, *(f32 *) ((char *) param_0 + 0x24));

                func_8010B990(param_0, 0x4027);
            }
            break;
        }

        case 10:
            func_8080215C_sucoasterfly(param_0);
            func_80801C44_sucoasterfly(param_0, 2);

            if (func_80101DDC(param_0)) {
                if (((CoasterFlyUpdateLocalFlags *) local_0)->local_0) {
                    func_808014AC_sucoasterfly(param_0, 8);
                } else {
                    func_808014AC_sucoasterfly(param_0, 3);
                }

                func_80101D7C(param_0);
            }
            break;

        case 11: {
            f32 local_3;
            s32 local_11;

            local_3 = func_800D8FF8();

            func_8080215C_sucoasterfly(param_0);

            *(f32 *) ((char *) param_0 + 0x34) += local_3 * -9800.0f;

            *(f32 *) ((char *) param_0 + 0x2C) += local_3 * *(f32 *) ((char *) param_0 + 0x34);

            if (*(f32 *) ((char *) param_0 + 0x2C) < -1500.0f) {
                *(f32 *) ((char *) param_0 + 0x2C) = -1500.0f;
            }

            local_11 = func_8010B990(param_0, 0x00204007);

            if (local_11 & 0x28) {
                func_808014AC_sucoasterfly(param_0, 12);
            }
            break;
        }

        case 12:
            func_8080215C_sucoasterfly(param_0);
            func_80801C44_sucoasterfly(param_0, 3);

            if (func_80101DDC(param_0)) {
                _subaddieDll_entrypoint_4(param_0, 0);

                if (!func_80107070(param_0, 2)) {
                    func_808014AC_sucoasterfly(param_0, 13);
                    _subaddiefade_entrypoint_3(param_0);
                }
            }
            break;

        case 13:
        case 14:
        case 15:
        case 16:
            func_8080215C_sucoasterfly(param_0);
    }

    local_3 = func_800F1DCC(local_2, *(f32 *) ((char *) param_0 + 0x48));

    {
        f32 local_15;
        f32 local_16;
        local_15 = 1.0f / local_1;
        local_16 = func_800F10B4(local_3 * local_15, -60.0f, 60.0f, -12.0f, 12.0f);

        *(f32 *) ((char *) param_0 + 0x4C) = func_800F1FF0(
            *(f32 *) ((char *) param_0 + 0x4C), local_16, 0.1f, 4.0f * local_1, 120.0f * local_1);
    }

    if (!func_801072A8(param_0) || func_801072E4(param_0)) {
        func_8010D690(param_0);
    }
}

s32 sucoasterfly_entrypoint_4(Actor *this, s32 msg, s32 arg)
{
    f32 v[3];
    s32 ret;

    switch (msg) {
        case 1:
            func_808014AC_sucoasterfly(this, 1);
            break;
        case 2:
            if (this->unk70_10 == 0xB) {
                break;
            }
            if (!_subaddieDll_entrypoint_3(this) && !func_80107070(this, 1)) {
                _subaddiefade_entrypoint_3(this);
                func_808014AC_sucoasterfly(this, 0xF);
                this->unk64_24 = 0;
            }
            break;
        case 0x8F:
            if (arg == 0) {
                this->unk64_25 = 1;
                ((ActorFlags74 *) ((u8 *) this + 0x74))->unk74_0 = 1;
                func_808014AC_sucoasterfly(this, 3);
            }
            break;
        case 0x29:
            func_80802080_sucoasterfly(this);
            break;
        case 0x2A:
            func_80802128_sucoasterfly(this);
            break;
        case 0x4D:
            _subaddieDll_entrypoint_4(this, 0);
            if (!func_80107070(this, 3)) {
                return 0;
            }
            break;
        case 0x94:
            if (!func_80100094(this, 1)) {
                return 0;
            }
            v[2] = 0.0f;
            _suexpression_entrypoint_13(func_80100094(this, 1), &v[1], &v[0]);
            func_80101010(v);
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(this);
            break;
        case 0x38:
            func_80101074(_sucoasterflydata_entrypoint_2(
                ((CoasterFlyLocal *) func_80100094(this, 0))->unk11_4, &ret));
            return ret;
        default:
            return 0;
    }
    return 1;
}

void func_80800EF0_sucoasterfly(s32 param_0, FlyObj *param_1)
{
    FlyActor *local_0 = func_80106790(param_0);
    if (param_1->f24 == 0 && local_0->f72 == 6) {
        func_808014AC_sucoasterfly(local_0, 7);
    }
}

void func_80800F44_sucoasterfly(Actor *param_0, u32 param_1)
{
    void *local_0;
    unsigned int new_var;
    int new_var2;
    local_0 = func_80106790(param_0);
    new_var2 = 0xFF;
    new_var = 0xFFFFu;
    if (((u32) ((u16 *) local_0)[57] >> 10) != 0xA) {
        short val = ((((((((((((((u32 *) local_0)[30] & new_var) & 0xFFFFu) & 0xFF) & new_var2) &
                            new_var2) &
                           new_var2) &
                          new_var2) &
                         new_var2) &
                        new_var2) &
                       0xFF) &
                      (0xFFFFFFFFFFFFFFFF & 0xFFFFFFFFu)) &
                     0xFF) &
                    0xFFFFu;
        if ((val << 29) >= 0) {
            if (func_801021BC(local_0, 0xA)) {
                func_808014AC_sucoasterfly(local_0, 0xA);
            }
        }
    }
}

void func_80800FA8_sucoasterfly(Unk80132ED0 *param_0, Unk80132ED0 *param_1)
{
    Actor *local_0 = func_80106790(param_0);
    f32 local_1[3];
    f32 local_3;
    f32 local_2[3];

    if (_sueggmisc_entrypoint_0(param_1)) {
        _suegg_entrypoint_19(func_80106790(param_1), local_1);
        local_3 = 1.0f / func_800D8FF8();
        func_800EF334(local_1, local_3);
        if (func_800EEF94(local_1) > 400.0f)
            func_800EF368(local_1, 400.0f);
    } else if (!(*(u32 *) ((u8 *) param_1 + 0x24) >> 22)) {
        func_800F5D70((u32) *(u16 *) ((u8 *) param_1 + 0x1A) >> 5, local_1);
        if (func_800EEFD4(local_1) < 100.0f) {
            func_800F5A00((u32) *(u16 *) ((u8 *) param_1 + 0x1A) >> 5, local_2);
            func_800EFB24(local_1, local_0->position, local_2);
            func_800EF368(local_1, 200.0f);
            local_1[1] += 150.0f;
        }
    } else {
        func_800EFD24(local_1);
    }
    func_808014AC_sucoasterfly(local_0, 11);
    func_800EF04C((f32 *) &local_0->actorData[4], local_1);
}

void func_80801108_sucoasterfly(s32 param_0, u8 *param_1, u8 *param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 unused48;
    s32 unused44;
    s32 x;
    s32 local_6[2];
    f32 local_7;
    f32 local_8;

    local_0 = func_80106790(param_0);
    local_1 = _glhittableDll_entrypoint_10(param_2);
    local_2 = _glhittableDll_entrypoint_9(param_2);
    local_3 = _glhittableDll_entrypoint_6(param_2);
    x = !(*(u32 *) (param_1 + 0x24) >> 22);
    if (x) {
        x = (u32) *(u16 *) (param_1 + 0x1A) >> 5;
        if (!func_800F70EC(x) || !func_800F6C1C(x)) {
            if (_glhittableDll_entrypoint_8(param_2)) {
                return;
            }
        }
    }
    if (local_3 == 0) {
        if (local_2 == 0 && (*(u32 *) (param_1 + 0x24) >> 22) != 0) {
            return;
        }
        if (local_2 <= 0) {
            local_2 = 1;
        }
    }
    (local_0 + local_3)[0x5C] =
        func_800F0E28(0, (local_0 + local_3)[0x5C] - 100 / local_2, local_0 + local_3, param_1);
    local_4 = local_3 == 2 && !(local_0 + local_3)[0x5C];
    if (local_2 != 0) {
        switch (local_3) {
            case 2:
                func_80109600(local_0, param_1, (local_0 + local_3), local_3);
                if ((*(u32 *) (param_1 + 0x24) >> 22) == 0x26D) {
                    _chflamer_entrypoint_1(local_0, (u8 *) ((s32) param_1 ^ 0),
                                           (local_0 + local_3));
                }
                break;
            case 1:
                func_80109600(local_0, param_1, (local_0 + local_3), local_3);
                if ((*(u32 *) (param_1 + 0x24) >> 22) == 0x26E) {
                    func_800EC370((u8 *) ((s32) param_1 ^ 0), local_6, (local_0 + local_3));
                    _chfreezy_entrypoint_1(local_0, local_6);
                }
                break;
        }
    }
    if ((local_0 + local_3)[0x5C] == 0 || local_3 != 0) {
        if ((local_0 + local_3)[0x5C] != 0) {
            local_3--;
        }
        if (local_3 != 2) {
            (local_0 + local_3)[0x5C] = 99;
        }
        if (local_3 == 2 && local_1 && func_8010A430(local_0)) {
            local_7 = func_800F5F24(func_800F54E4());
            func_800EB860(func_80108EF4, local_0);
            local_8 = *(f32 *) (local_0 + 0x8) + func_800EC708(param_0);
            _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, local_1 + 2,
                                        *(s32 *) (local_0 + 0x4), *(s32 *) &local_8,
                                        *(s32 *) (local_0 + 0xC), *(s32 *) &local_7);
            func_800EB874();
        }
        switch (local_3) {
            case 0:
                func_80800EF0_sucoasterfly(*(s32 *) local_0, param_1);
                break;
            case 1:
                func_80800F44_sucoasterfly(*(s32 *) local_0, param_1);
                break;
            case 2:
                func_80800FA8_sucoasterfly(*(s32 *) local_0, param_1);
        }
    }
    if (local_4) {
        func_8010D930(1, *(s32 *) (local_0 + 0x70) & 1, local_0 + 4, D_80802294_sucoasterfly);
        _subaddiejoy_entrypoint_10(local_0, 1.0f, 0.25f);
    }
}

void func_808014AC_sucoasterfly(param_0, param_1) Actor *param_0;
s32 param_1;
{
    FlyData *local_0;
    FlyInfo *local_1;
    s32 local_2;
    f32 local_3[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = _sucoasterflydata_entrypoint_1(local_0->unk11_4);
    local_2 = param_0->unk70_10;
    func_80102424(param_0, param_1);
    switch (param_1) {
        case 1:
            param_0->unk58 = local_1->unk24;
            local_0->unkC = 0.0f;
            break;
        case 2:
            OD(3) = local_0->unkC = 0.0f;
            break;
        case 3:
            param_0->unk58 = local_1->unk26;
            local_0->unkC =
                func_80107C00() * func_800DC128(_sucoasterflydata_entrypoint_3(local_0->unk11_4),
                                                _sucoasterflydata_entrypoint_4(local_0->unk11_4));
            break;
        case 4:
            param_0->unk54 = func_8010CD28(param_0);
            local_0->unkC = func_80107C00() * _sucoasterflydata_entrypoint_3(local_0->unk11_4);
            OD(3) = 0.0f;
            break;
        case 5:
            func_800EE940(local_0->unk12, param_0->position);
            break;
        case 6:
            if (local_2 != 5) {
                func_800EE940(local_0->unk12, param_0->position);
            }
            func_80801A80_sucoasterfly(param_0);
            param_0->unk54 = func_80102D78(param_0, &OD(0));
            local_0->unk11_3 = 1;
            OD(3) = local_0->unkC =
                func_80107C00() * _sucoasterflydata_entrypoint_5(local_0->unk11_4);
            break;
        case 7:
            local_0->unkC = 0.0f;
            break;
        case 8:
            func_800EE88C(local_3, local_0->unk12);
            param_0->unk54 = func_80102D78(param_0, local_3);
            local_0->unk11_3 = 0;
            local_0->unkC = func_80107C00() * _sucoasterflydata_entrypoint_3(local_0->unk11_4);
            OD(3) = 0.0f;
            break;
        case 9:
            local_0->unkC =
                (func_80107C00() * 1.2f) * _sucoasterflydata_entrypoint_4(local_0->unk11_4);
            break;
        case 11:
            OD(7) = 0.0f;
            _subaddieDll_entrypoint_4(param_0, 1);
            ((FlyBits *) param_0)->unk64_25 = 0;
            ((FlyBits *) param_0)->unk64_24 = 0;
            ((FlyBits *) param_0)->unk70_4 = 0;
            ((FlyBits *) param_0)->unk70_25 = ((FlyBits *) param_0)->unk70_4;
            ((FlyBits *) param_0)->unk64_30 = 0;
            ((FlyBits *) param_0)->unk64_31 = ((FlyBits *) param_0)->unk64_30;
            param_0->unk14 &= ~0x80000;
            ((FlyBits *) param_0)->unk74_0 = 2;
            func_8010A570(param_0);
            func_80801CD0_sucoasterfly(param_0, 2);
            break;
        case 12:
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808022AC_sucoasterfly);
    }
}

void func_8080181C_sucoasterfly(param_0) Actor *param_0;
{
    CoasterFlySpeed1482 *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = (local_0->local_0 < ((f32 *) param_0->actorData)[3]
                   ? func_800F0E00(((f32 *) param_0->actorData)[3], 10.0f)
                   : local_0->local_0) *
              0.1f;
    ((f32 *) param_0->actorData)[3] =
        func_800F15F8(((f32 *) param_0->actorData)[3], local_0->local_0, func_80107C00() * local_1);
}

void func_808018BC_sucoasterfly(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_2;
    f32 local_1;

    local_0 = (u8 *) func_80100094(param_0, 0);
    if (((CoasterFlyJoyFlag *) param_0)->local_0)
        local_1 = _subaddiejoy_entrypoint_9(param_0, 0, 0);
    else
        local_1 = 1.0f;
    local_2 = (*(f32 *) (local_0 + 0xC) < *(f32 *) ((u8 *) param_0 + 0x24)
                   ? func_800F0E00(*(f32 *) ((u8 *) param_0 + 0x24), 10.0f)
                   : *(f32 *) (local_0 + 0xC)) *
              0.1f;
    *(f32 *) ((u8 *) param_0 + 0x24) =
        func_800F15F8(*(f32 *) ((u8 *) param_0 + 0x24), *(f32 *) (local_0 + 0xC) * local_1,
                      func_80107C00() * local_2);
}

void func_808019A0_sucoasterfly(Actor *param_0)
{
    f32 local_0;
    s32 local_1;

    local_0 = func_80801E5C_sucoasterfly(param_0);
    local_1 = ((CoasterFlyMovementFlags *) param_0)->local_0 ? 0x404027 : 0x504327;
    func_808018BC_sucoasterfly(param_0);
    func_800EEB9C((f32 *) &param_0->actorData[4], param_0->rotation[1],
                  ((f32 *) param_0->actorData)[3]);
    ((f32 *) param_0->actorData)[5] =
        func_800F0D50(local_0 - param_0->position[1], -300.0f, 300.0f);
    if ((func_8010B990(param_0, local_1) & 0x24) &&
        !((CoasterFlyMovementFlags *) param_0)->local_0) {
        func_80102924(param_0, param_0->rotation[1] + 180.0f);
        func_808014AC_sucoasterfly(param_0, 2);
    }
}

s32 func_80801A80_sucoasterfly(s32 param_0)
{
    func_800F5BF0(func_800F54E4(), param_0 + 0x18);
}

s32 func_80801AB0_sucoasterfly(Actor *param_0)
{
    if (!((CoasterFlyEligibility *) param_0)->local_0)
        return 0;
    if (((CoasterFlyEligibility *) param_0)->local_1)
        return 1;
    if (func_801072A8(param_0) || ((CoasterFlyEligibility *) param_0)->local_2)
        return 0;
    if (!_subaddierouteDll_entrypoint_4(param_0))
        return 0;
    if (!func_8010C9B0(param_0->position, 0x578))
        return 0;
    if (!func_8010C500(param_0))
        return 0;
    if (!_suchase_entrypoint_1(param_0))
        return 0;
    func_808014AC_sucoasterfly(param_0, 4);
    return 1;
}

s32 func_80801B90_sucoasterfly(Actor *param_0)
{
    s32 local_0;
    CodexCoasterFlyFlags *local_1;

    local_0 = 0;
    if (((CodexCoasterActorFlags *) ((u8 *) param_0 + 0x64))->local_0) {
        return 0;
    }
    if (!func_8010C500(param_0)) {
        local_0 = 1;
    }
    if (!local_0) {
        if (!_suchase_entrypoint_1(param_0)) {
            local_0++;
        }
    }
    if (local_0) {
        local_1 = func_80100094(param_0, 0);
        func_808014AC_sucoasterfly(param_0, local_1->local_0 ? 7 : 1);
    }
    return local_0;
}

void func_80801C44_sucoasterfly(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;

    local_0 = _sucoasterflydata_entrypoint_1(
        (u32) *(u8 *) ((u8 *) func_80100094(param_0, 0) + 0x11) >> 4);
    local_1 = param_1 * 8;
    if (*(s16 *) (local_0 + local_1 + 4) != 0 &&
        func_80101E14(param_0, *(s16 *) (local_0 + local_1 + 0xA) * 0.00390625f)) {
        func_80801CD0_sucoasterfly(param_0, param_1);
    }
}

void func_80801CD0_sucoasterfly(param_0, param_1) Actor *param_0;
s32 param_1;
{
    f32 local_3;
    u8 *local_0;
    s32 local_2;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);
    local_0 = (u8 *) _sucoasterflydata_entrypoint_1((u32) local_0[0x11] >> 4);
    if (*(s16 *) ((local_0 + 4) + param_1 * 8)) {
        func_8010D640(local_1);
        if (func_800EEB40(local_1, param_0->position) >= 9000000.0f) {
            return;
        }
        local_3 = func_800DC178(-0.05f, 0.05f);
        local_3 += *(s16 *) ((local_0 + 8) + param_1 * 8) * 0.00390625f;
        func_800C4B64(local_3);
        func_800C4B7C(*(s16 *) ((local_0 + 4) + param_1 * 8));
        func_800C4B70(*(s16 *) ((local_0 + 6) + param_1 * 8));
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808022BC_sucoasterfly);
    }
}

int func_80801DD0_sucoasterfly(Actor *param_0)
{
    if (func_800F20BC(param_0->rotation[1], func_8010CD28(param_0), 20.0f)) {
        if (_subaddiejoy_entrypoint_6(param_0, 1) == 1) {
            if (func_801021BC(param_0, 5))
                func_808014AC_sucoasterfly(param_0, 5);
            else
                func_808014AC_sucoasterfly(param_0, 6);
            return 1;
        }
    }
    return 0;
}

f32 func_80801E5C_sucoasterfly(param_0)
Actor *param_0;
{
    FlightClearance1570 *local_3;
    f32 local_0[3];
    f32 local_1;
    f32 local_2;

    local_3 = func_80100094(param_0, 0);
    if (((CoasterFlyMovementFlags *) param_0)->local_0) {
        func_8008FE94(5, local_0);
        return local_0[1] + 100.0f;
    }
    if (func_80104544(param_0)) {
        local_1 = func_8010473C(param_0, 0) + local_3->local_0;
        func_800EE7F8(local_0, param_0->position);
        local_0[1] = local_1;
        if (func_800CC338(local_0, (*(u32 *) ((u8 *) param_0 + 0x70) >> 25) - 1,
                          ((*(u32 *) ((u8 *) param_0 + 0x70) << 22) >> 26) - 1) != -1)
            return local_1;
    } else {
        if (func_80801FE4_sucoasterfly(param_0, &local_2, 50.0f, -(local_3->local_0 + 400.0f))) {
            func_800EE7F8(local_0, param_0->position);
            local_0[1] = local_3->local_0 + local_2;
            if (func_800CC338(local_0, (*(u32 *) ((u8 *) param_0 + 0x70) >> 25) - 1,
                              ((*(u32 *) ((u8 *) param_0 + 0x70) << 22) >> 26) - 1) != -1)
                return local_3->local_0 + local_2;
        }
    }
    return param_0->position[1];
}

s32 func_80801FE4_sucoasterfly(u8 *param_0, f32 *param_1, f32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    func_800EE7F8(local_0, param_0 + 4);
    func_800EE7F8(local_1, param_0 + 4);
    local_0[1] += param_2;
    local_1[1] += param_3;
    if (func_800BEF00(local_0, local_1, local_2, *(s32 **) ((char *) param_0 + 0x14)) != 0) {
        *param_1 = local_1[1];
        return 1;
    }
    return 0;
}

void func_80802080_sucoasterfly(param_0) s32 param_0;
{
    u8 *temp;
    u8 *sp20;

    temp = func_80100094(param_0, 0);
    sp20 = _sucoasterflydata_entrypoint_1((u32) (*(u8 *) ((s8 *) (temp) + 0x11)) >> 4);

if ((func_80100094(param_0, 1) == NULL) &&
    (_suexpression_entrypoint_1(*(u8 *) ((s8 *) sp20 + 3)) != 0)) {
    _suexpression_entrypoint_7(param_0, 1, *(s16 *) ((s8 *) sp20 + 2));
    _suexpression_entrypoint_12(func_80100094(param_0, 1), 0x42480000, 0x42200000);
    _suexpression_entrypoint_17(func_80100094(param_0, 1), 0x7D0);
}

}

void func_80802128_sucoasterfly(Actor *arg0)
{
    if (func_80100094(arg0, 1) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }

}
s32 func_8080215C_sucoasterfly(s32 param_0)
{
    s32 local_0;

if (func_80100094(param_0, 1)) {
    local_0 = func_80100094(param_0, 1);
    _suexpression_entrypoint_18(local_0 | 0, 1);
}

}

s32 sucoasterfly_entrypoint_5(s32 param_0)
{
    return (s32) ((u8 *) func_80100094(param_0, 0) + 0x1C);
}

void sucoasterfly_entrypoint_6()
{
    func_80101870();
}

int D_80802280_sucoasterfly[5] = {0x0, (u32) func_80800F44_sucoasterfly,
                                  (u32) func_80800FA8_sucoasterfly,
                                  (u32) func_80801108_sucoasterfly, 0x0};
u8 D_80802294_sucoasterfly[24] = {0x0, 0x13, 0x4,  0x17, 0x0,  0xD,  0x1, 0xC,
                                  0x1, 0x26, 0x0,  0x16, 0x65, 0x90, 0x0, 0x1,
                                  0x3, 0x20, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_808022AC_sucoasterfly[16] = {0x0, 0x13, 0x4, 0x1F, 0x0,  0xD,  0x0, 0xC0,
                                  0x0, 0xD9, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
u8 D_808022BC_sucoasterfly[20] = {0x0, 0x21, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x1, 0x5, 0xDC,
                                  0xB, 0xB8, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
