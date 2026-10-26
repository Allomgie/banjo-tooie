#include "common.h"

#define COASTER_SPEED_RECORD_DEFINED
extern void *func_80100094(Actor *, u32);
extern s32 _subaddierouteDll_entrypoint_4();
typedef struct { u8 pad_0[0xC]; s16 local_0; u8 pad_1[9]; s8 local_1; u8 local_2:4; u8 pad_2:4; u8 local_3:1; u8 local_4:1; u8 pad_3:6; } CoasterInit1493;
struct CoasterPropSize;
extern void *func_80100074(Actor *, u32, u32);
extern s32 _sucoasterdata_entrypoint_0(Actor *);
extern s32 _subaddiesect_entrypoint_1(Actor *);
extern void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
typedef struct { u8 pad_0[0x18]; u16 pad_1:12; u16 local_0:1; u16 pad_2:3; } CoasterStateFlags;
typedef struct { u8 pad_0[0xC]; s16 scale; s16 speed; } CoasterSpeedState1417;
extern f32 func_80107C00(void);
typedef struct CoasterSpeedRecord { u8 pad_0[0x3C]; s32 unk3C; u8 pad40[0xC]; f32 unk4C; s16 unk50; s16 unk52; } CoasterSpeedRecord;
struct CoasterRadius1548;
typedef struct { u8 pad0[6]; u16 unk6; } CoasterRoute;
typedef struct { u8 pad0[0x16]; u8 unk16; u8 pad17; u32 kind : 4; u32 pad_26 : 2; u32 bit25 : 1; u32 pad_24 : 1; u32 bit23 : 1; u32 pad_20 : 3; u32 bit19 : 1; u32 pad_0 : 19; } CoasterRide;
extern s32 func_800F64A4(s32, s32);
extern s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, u8, f32, f32, f32);
extern s32 func_8010BA80(Actor *, s32, s32);
extern void func_8010AA54(f32 *);
extern s32 func_800F1EA4(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800136E4(f32);
typedef struct { s16 field_a; s8 field_b; } CoasterMessage1482;
extern s32 func_8010108C(Actor *, s32, s32);
typedef struct { u8 pad_0[0x19]; u8 local_0 : 1; u8 pad_1 : 7; } CoasterRouteFlags;
typedef struct { u8 pad_0[0x15]; u8 local_0; } CoasterRouteState;
typedef struct { u8 pad_0[0x70]; u32 local_0:7; u32 pad_1:15; u32 local_1:6; u32 pad_2:4; } CoasterRouteActor;
extern void func_800F5A00(s32, f32 *);
extern s32 func_800CC338(f32 *, s32, s32);
extern s32 func_800D9058(f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, u8, s32, f32, s32, s32);
typedef struct { u8 pad_0[0x18]; u32 kind : 4; u32 pad_1 : 28; } CoasterEventKind;
extern struct CoasterSpeedRecord *_sucoasterdata_entrypoint_1(s32);
extern s32 func_80101E14(Actor *, f32);
extern int func_801072A8(int);
extern int func_801072E4(int);
extern void func_8010D6E0(int, int, float, float);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef struct { u8 pad_0[0x18]; u32 pad_1 : 9; u32 local_0 : 1; u32 pad_2 : 22; } CoasterTrackItem;
typedef struct CoasterPropKind { u8 pad_0[0x18]; u32 local_0 : 4; u32 pad_1 : 28; } CoasterPropKind;
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 26; u32 local_0 : 1; u32 pad_2 : 5; } CoasterActorFlags;
extern int _sucoasterdata_entrypoint_4(u32);
extern f32 func_80103EAC(Actor *);
extern f32 func_800F0E00(f32, f32);
typedef struct { u8 pad0[0x14]; u32 unk14; u8 pad18[0x64 - 0x18]; u32 unk64_31 : 1; u32 unk64_30 : 1; u32 unk64_25 : 5; u32 unk64_24 : 1; u32 unk64_rest : 24; u8 pad68[0x70 - 0x68]; u32 unk70_25 : 7; u32 unk70_10 : 15; u32 unk70_4 : 6; u32 unk70_0 : 4; u8 pad74[3]; u8 unk77_4 : 4; u8 unk77_0 : 4; } SuCoasterBits;
extern void func_8010A570(SuCoasterBits *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F57F0(void *, f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern f32 func_8010CD50();
extern s32 func_800F54E4(void);
extern s32 func_8010D290(s32);
typedef struct { u8 pad[0x78]; u32 pre : 29; u32 f2 : 1; u32 post : 2; } SBits78;
typedef struct { u8 pad[0x64]; u32 a : 2; u32 f29 : 1; u32 rest : 29; } SBits64;
typedef struct { u8 pad_0[0x18]; u32 local_0:4; u32 pad_1:2; u32 local_1:1; u32 pad_2:1; u32 local_3:1; u32 pad_4:1; u32 local_2:1; u32 pad_3:21; } CoasterUpdateFlags;
typedef struct { u8 pad_0[0x78]; u32 pad_1:28; u32 local_0:1; u32 pad_2:3; } CoasterUpdateActorFlags;
extern s32 func_800DC298(f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102924(Actor *, f32);
extern s32 func_800F20BC(f32, f32, f32);
typedef struct { u16 pad : 7; u16 f : 9; } SC6E;
typedef struct { u8 f : 1; u8 pad : 7; } SB1;
typedef struct { u8 pad : 6; u8 f : 1; u8 r : 1; } SB2;
typedef struct { u8 pad : 5; u8 f : 1; u8 r : 2; } SB4;
typedef struct { u8 pad : 2; u8 f : 1; u8 r : 5; } SB20;
typedef struct { u8 pad : 7; u8 f : 1; } SB01;
typedef struct { u32 pad : 6; u32 f : 1; u32 r : 25; } SW6;
typedef struct { u32 pad : 2; u32 f : 1; u32 r : 29; } SW2;
extern f32 func_8010203C(Actor *, s32);
extern void func_80101CDC(Actor *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
typedef struct { u8 pad_0[0x64]; u8 b64_7 : 1; u8 b64_6 : 1; u8 pad64 : 5; u8 b64_0 : 1; } Coaster64;
typedef struct { u8 pad_0[0x77]; u8 hi77 : 4; u8 lo77 : 4; } Coaster77;
typedef struct { u8 pad_0[0x78]; u32 pad78 : 29; u32 b78_2 : 1; u32 pad78b : 2; } Coaster78;
typedef struct { u8 pad_0[0x18]; u32 pad18 : 10; u32 b18_21 : 1; u32 pad18b : 21; } CoasterObj;
typedef struct { u8 pad_0[0x6C]; u32 pad6C : 11; u32 f6C_9 : 12; u32 f6C_0 : 9; } Coaster6C;
s32 sucoaster_entrypoint_9();
s32 func_8080202C_sucoaster();
void func_80802130_sucoaster();
f32 func_808021A8_sucoaster();
s32 func_80802384_sucoaster(Actor *param_0, u8 *param_1, f32 param_2);
s32 func_80802594_sucoaster();
s32 func_80802728_sucoaster();
s32 func_80802760_sucoaster();
void func_8080027C_sucoaster();
void func_80800C68_sucoaster(Actor *param_0, u8 *param_1, f32 param_2);
s32 sucoaster_entrypoint_10();
void sucoaster_entrypoint_11(Actor *param_0, f32 param_1);
int sucoaster_entrypoint_17();
void sucoaster_entrypoint_2(u8 *param_0);
void *D_exp_sucoaster_entrypoint_2[] = { (void *)sucoaster_entrypoint_2 };
void *D_exp_sucoaster_entrypoint_11[] = { (void *)sucoaster_entrypoint_11 };
void *D_exp_sucoaster_entrypoint_17[] = { (void *)sucoaster_entrypoint_17 };

s32 sucoaster_entrypoint_0(Actor *param_0, s32 param_1)
{
    CoasterInit1493 *local_0;

    local_0 = func_80100074(param_0, 0, param_1 + 0x1C);
    local_0->local_2 = _sucoasterdata_entrypoint_0(param_0);
    local_0->local_1 = _subaddiesect_entrypoint_1(param_0);
    _subaddierouteDll_entrypoint_3(param_0, local_0, param_0->position);
    func_80802130_sucoaster(param_0, (struct CoasterPropSize *)local_0, 0x190);
    local_0->local_3 = 1;
    local_0->local_4 = 1;
    local_0->local_0 = (s32)(param_0->scale * 256.0f);
    func_80107200(param_0);
    return 1;
}

s32 sucoaster_entrypoint_1(s32 param_0) {
    s32 local_0 = func_80100094(param_0, 0);
    func_80802728_sucoaster(param_0, local_0 | 0x10000000 & 0xFF);
}

void sucoaster_entrypoint_22();

void sucoaster_entrypoint_2(u8 *param_0)
{
    u8 *local;
    s32 r;
    u8 v;
    u8 v2;
    u8 t4;
    u32 m;
    local = func_80100094(param_0, 0);
    if (1) {}
    if (*(s8 *)(local + 0x17) == -1 || _subaddiesect_entrypoint_0(param_0, *(s8 *)(local + 0x17), 1) != 0) {
        sucoaster_entrypoint_22(param_0);
        if (local) {}
        if (!((SBits78 *)param_0)->f2) {
            func_800D9078(param_0 + 0x58);
            v = *(u8 *)(local + 0x12);
            if (v > 0) {
                *(u8 *)(local + 0x12) = v - 1;
            }
            if (*(u8 *)(param_0 + 0x74) & 1) {
                m = (u32)*(u16 *)(param_0 + 0x72) >> 10;
                if (m != 0xB && m != 0xC && m != 0xD) {
                    v2 = *(u8 *)(local + 0x13);
                    if (v2 > 0) {
                        *(u8 *)(local + 0x13) = v2 - 1;
                        if (*(u8 *)(local + 0x13) == 0) {
                            sucoaster_entrypoint_17(param_0, 2);
                            *(u8 *)(local + 0x13) = func_800D9058(1.8f);
                        }
                    }
                }
            }
            r = func_80802760_sucoaster(local);
            if (r != -1) {
                func_800F5A00(r, param_0 + 0x18);
            }
            if (((SBits64 *)param_0)->f29) {
                _sucoasterplayer_entrypoint_0(param_0);
            } else {
                func_8080027C_sucoaster(param_0, local);
            }
            if (func_80100094(param_0, 1) != 0) {
                _suexpression_entrypoint_10(func_80100094(param_0, 1), *(s32 *)param_0, 0);
            }
        }
    }
}

f32 func_8080264C_sucoaster();

s32 func_80802400_sucoaster();

f32 func_8080230C_sucoaster();

void func_808020B8_sucoaster(Actor *param_0, CoasterPropKind *param_1, f32 param_2);

s32 sucoaster_entrypoint_19();

s32 sucoaster_entrypoint_16();

void sucoaster_entrypoint_15();

s32 sucoaster_entrypoint_14();

s32 sucoaster_entrypoint_13();

void sucoaster_entrypoint_8();

s32 sucoaster_entrypoint_7(Actor *this, s32 arg1, f32 arg2);

void func_8080027C_sucoaster(param_0, param_1) Actor *param_0; void *param_1;
{
    char *local_0;
    s32 local_1;
    f32 local_2;
    s32 local_3;
    f32 local_4;
    f32 local_6;
    f32 local_5;

    local_0 = (char *)_sucoasterdata_entrypoint_1(
        *(u32 *)((char *)param_1 + 0x18) >> 28
    );

    switch (param_0->unk70_10) {
        case 1:
            if (func_800DC298(0.5f)) {
                local_1 = 2;
            } else {
                local_1 = 3;
            }

            if (sucoaster_entrypoint_9(param_0, local_1, 0) != 0) {
                break;
            }

            sucoaster_entrypoint_9(param_0, 3, 0);
            break;

        case 2:
            sucoaster_entrypoint_19(param_0);

            if (*(f32 *)((char *)param_0 + 0x58) <= 0.0f &&
                func_800DC298(0.03f)) {
                if (((CoasterUpdateFlags *)param_1)->local_1) {
                    sucoaster_entrypoint_9(param_0, 3, 2);
                    ((CoasterUpdateFlags *)param_1)->local_1 = 0;
                } else if (sucoaster_entrypoint_9(param_0, 3, 0)) {
                    _subaddierouteDll_entrypoint_6(
                        param_0,
                        param_1,
                        *(u8 *)((char *)param_1 + 0x16),
                        0,
                        1.0f,
                        10,
                        45
                    );
                }
            }

            sucoaster_entrypoint_13(param_0);
            sucoaster_entrypoint_8(param_0);
            break;

        case 3:
            _subaddierouteDll_entrypoint_6(
                param_0,
                param_1,
                *(u8 *)((char *)param_1 + 0x16),
                7,
                0.6f,
                4,
                8
            );

            if ((*(u8 *)((char *)param_1 + 0x16) & 7) == 0 &&
                *(f32 *)((char *)param_0 + 0x58) <= 0.0f &&
                func_800DC298(0.01f)) {
                if (func_800DC298(0.3f)) {
                    local_1 = 4;
                } else {
                    local_1 = 2;
                }
                sucoaster_entrypoint_9(param_0, local_1, 0);
            }

            if (sucoaster_entrypoint_7(param_0, 0x802, 30.0f)) {
                break;
            }

            sucoaster_entrypoint_13(param_0);
            break;

        case 4:
            _subaddierouteDll_entrypoint_6(
                param_0,
                param_1,
                *(u8 *)((char *)param_1 + 0x16),
                7,
                0.6f,
                4,
                8
            );

            if (*(f32 *)((char *)param_0 + 0x58) <= 0.0f &&
                func_800DC298(0.02f)) {
                sucoaster_entrypoint_9(param_0, 3, 0);
            }

            if (sucoaster_entrypoint_7(param_0, 0x802, 30.0f)) {
                break;
            }

            sucoaster_entrypoint_13(param_0);
            break;

        case 5:
            if (sucoaster_entrypoint_14(param_0)) {
                if (sucoaster_entrypoint_9(param_0, 2, 0)) {
                    local_3 = func_800D9058(2.0f);

                    param_0->unk6C_0 = local_3;
                }
            } else {
                local_2 = func_8080264C_sucoaster(param_0, param_1);

                if (!_subaddierouteDll_entrypoint_7(
                        param_0,
                        param_1,
                        *(f32 *)((char *)param_0 + 0x54),
                        local_2,
                        (f32)*(s16 *)((char *)param_1 + 0x10),
                        0x5802)) {
                    if (sucoaster_entrypoint_9(param_0, 2, 0)) {
                        local_3 = func_800D9058(2.0f);

                        param_0->unk6C_0 = local_3;
                    }
                } else {
                    func_808020B8_sucoaster(param_0, param_1, 1.0f);

                    if (func_80102CF4(param_0, 15.0f)) {
                        if (*(u8 *)((char *)param_1 + 0x12) != 0) {
                            local_1 = 8;
                        } else {
                            local_1 = 7;
                        }

                        sucoaster_entrypoint_9(param_0, local_1, 0);
                    }
                }
            }

            sucoaster_entrypoint_8(param_0);
            break;

        case 6:
            func_80102BF8(
                param_0,
                *(f32 *)(local_0 + 0x4C),
                (f32)*(s16 *)(local_0 + 0x50),
                (f32)*(s16 *)(local_0 + 0x52)
            );

            if (func_80102CF4(param_0, 20.0f)) {
                if (*(u8 *)((char *)param_0 + 0x74) & 1) {
                    sucoaster_entrypoint_9(param_0, 0x12, 0);
                    ((CoasterUpdateFlags *)param_1)->local_1 = 0;
                } else {
                    sucoaster_entrypoint_9(param_0, 3, 2);
                    ((CoasterUpdateFlags *)param_1)->local_1 = 0;
                }
            }

            sucoaster_entrypoint_8(param_0);
            break;

        case 7:
            sucoaster_entrypoint_16(param_0, 0);

            *(f32 *)((char *)param_0 + 0x54) =
                func_8080264C_sucoaster(param_0, param_1);

            func_808020B8_sucoaster(param_0, param_1, 1.0f);

            if (func_80101DDC(param_0)) {
                if (sucoaster_entrypoint_14(param_0)) {
                    if (sucoaster_entrypoint_9(param_0, 3, 0)) {
                        _subaddierouteDll_entrypoint_6(
                            param_0,
                            param_1,
                            *(u8 *)((char *)param_1 + 0x16),
                            0,
                            1.0f,
                            40,
                            70
                        );

                        local_3 = func_800D9058(2.0f);

                        param_0->unk6C_0 = local_3;
                    }
                } else {
                    sucoaster_entrypoint_9(param_0, 8, 0);
                }
            }

            sucoaster_entrypoint_8(param_0);
            break;

        case 8:
            local_4 = (f32)_sucoasterdata_entrypoint_3(*(u32 *)((char *)param_1 + 0x18) >> 28);
            sucoaster_entrypoint_11(param_0, local_4);

            if (sucoaster_entrypoint_14(param_0)) {
                sucoaster_entrypoint_15(param_0);
            } else {
                if (((CoasterUpdateFlags *)param_1)->local_3 ||
                    _subaddierouteDll_entrypoint_4(param_0)) {
                    *(f32 *)((char *)param_0 + 0x54) =
                        func_8080264C_sucoaster(param_0, param_1);
                }

                if (*(u16 *)(local_0 + 0x4A) != 0 &&
                    func_80102CF4(param_0, 80.0f) &&
                    func_80802400_sucoaster(param_0, param_1)) {
                    sucoaster_entrypoint_9(param_0, 9, 0);
                }
            }

            sucoaster_entrypoint_7(param_0, 0x5802, 30.0f);
            break;

        case 9:
            if (((CoasterUpdateFlags *)param_1)->local_3 ||
                _subaddierouteDll_entrypoint_4(param_0)) {
                *(f32 *)((char *)param_0 + 0x54) =
                    func_8080264C_sucoaster(param_0, param_1);
            }

            sucoaster_entrypoint_7(param_0, 0x5802, 30.0f);

            sucoaster_entrypoint_16(param_0, 1);
            sucoaster_entrypoint_16(param_0, 6);

            if (!((CoasterUpdateFlags *)param_1)->local_2) {
                if (sucoaster_entrypoint_16(param_0, 5)) {
                    _sucoasterhit_entrypoint_2(param_0);
                }
            }

            if (func_80101DDC(param_0)) {
                if (sucoaster_entrypoint_13(param_0)) {
                    break;
                }

                sucoaster_entrypoint_9(param_0, 3, 0);
            }
            break;

        case 10:
            local_4 = (f32)_sucoasterdata_entrypoint_3(*(u32 *)((char *)param_1 + 0x18) >> 28);
            sucoaster_entrypoint_11(param_0, local_4);

            if (func_80802550_sucoaster(param_0, param_1)) {
                sucoaster_entrypoint_15(param_0);
            } else if (((CoasterUpdateFlags *)param_1)->local_3 ||
                       _subaddierouteDll_entrypoint_4(param_0)) {
                *(f32 *)((char *)param_0 + 0x54) =
                    func_8080230C_sucoaster(param_0, param_1);
            }

            sucoaster_entrypoint_7(param_0, 0x4802, 30.0f);
            break;

        case 11:
            sucoaster_entrypoint_16(param_0, 2);

            if (func_80101DDC(param_0) &&
                !((CoasterUpdateActorFlags *)param_0)->local_0) {
                if (*(u8 *)((char *)param_0 + 0x74) & 1) {
                    sucoaster_entrypoint_9(param_0, 0x12, 0);
                } else {
                    sucoaster_entrypoint_9(param_0, 3, 0);
                }
            }

            sucoaster_entrypoint_8(param_0);
            break;

        case 12:
            sucoaster_entrypoint_19(param_0);

            if (func_80101DDC(param_0) &&
                !((CoasterUpdateActorFlags *)param_0)->local_0) {
                if (!func_80107070(param_0, 2)) {
                    sucoaster_entrypoint_10(param_0, 0xD);
                    _subaddiefade_entrypoint_3(param_0);
                }
            }

            sucoaster_entrypoint_16(param_0, 3);
            break;

        case 13:
            sucoaster_entrypoint_19(param_0);
            break;

        case 14:
            sucoaster_entrypoint_19(param_0);
            break;

        case 15:
            _sucoasterhit_entrypoint_1(param_0);
            break;

        case 16:
            break;

        case 17:
            sucoaster_entrypoint_19(param_0);
            break;

        case 18:
            local_4 = (f32)_sucoasterdata_entrypoint_3(*(u32 *)((char *)param_1 + 0x18) >> 28);
            sucoaster_entrypoint_11(param_0, local_4);

            local_1 = *(u8 *)((char *)param_1 + 0x16);
            if (!local_1 & 0x1B) {
                if (!func_8001210C(7)) {
                    if (*(u8 *)((char *)param_1 + 0x18) & 1) {
                        local_5 = 1.0f;
                    } else {
                        local_5 = -1.0f;
                    }

                    local_6 = func_800DC178(30.0f, 40.0f) * local_5;
                    func_80102924(param_0, param_0->unk54 + local_6);
                }
            }

            if (!(*(u8 *)((char *)param_0 + 0x74) & 1)) {
                sucoaster_entrypoint_9(param_0, 3, 0);
            } else {
                sucoaster_entrypoint_7(param_0, 0x4000, 30.0f);
            }
            break;
    }
}

s32 sucoaster_entrypoint_3(s32 param_0) {
    return (s32)((u8 *)func_80100094(param_0, 0) + 0x1C);
}

void sucoaster_entrypoint_4(s32 param_0) {
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0 != NULL) {
        local_0[0x19] &= 0xFFBF;
    }
}

void sucoaster_entrypoint_5(Actor *param_0)
{
    CoasterStateFlags *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0) {
        local_0->local_0 = 1;
    }
}

void func_80800C68_sucoaster(Actor *param_0, u8 *param_1, f32 param_2)
{
    if (0.6f * *(s16 *)(param_1 + 0xE) < *(f32 *)&param_0->actorData[3] &&
        !func_800F20BC(param_0->rotation[1], param_0->unk54, 60.0f)) {
        *(f32 *)&param_0->actorData[3] *= 0.95f;
    } else {
        *(f32 *)&param_0->actorData[3] = func_800F15F8(*(f32 *)&param_0->actorData[3], *(s16 *)(param_1 + 0xE), func_80107C00() * param_2);
    }
}

void sucoaster_entrypoint_6(Actor *param_0, f32 param_1)
{
    CoasterSpeedState1417 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0->speed = (s32)(func_80107C00() * ((f32)local_0->scale * 0.00390625f) * param_1);
}

void sucoaster_entrypoint_18();

s32 sucoaster_entrypoint_7(Actor *this, s32 arg1, f32 arg2)
{
    s32 pad;
    CoasterRoute *local;
    CoasterSpeedRecord *rec;
    s32 flags;
    CoasterRide *s;
    s32 r;
    f32 pos[3];
    f32 ang;

    local = func_80100094(this, 0);
    s = (CoasterRide *)local;
    rec = _sucoasterdata_entrypoint_1(s->kind);
    if (!s->bit19) {
        r = func_80802760_sucoaster(s);
        if (r != -1 && func_800F64A4(r, rec->unk3C)) {
            arg1 |= 1;
        }
    }
    if (s->bit23 || _subaddierouteDll_entrypoint_4(this)) {
        if (!_subaddierouteDll_entrypoint_7(this, local, this->rotation[1], this->unk54, func_808021A8_sucoaster(this, s, arg1), arg1) && !s->bit25 && sucoaster_entrypoint_9(this, 6, 1)) {
            func_80802384_sucoaster(this, s, this->rotation[1] + 180.0f);
        }
        s->unk16 = local->unk6;
        s->bit23 = 0;
    }
    _subaddierouteDll_entrypoint_5(this, local, s->unk16, rec->unk4C, rec->unk50, rec->unk52);
    func_80800C68_sucoaster(this, s, arg2);
    sucoaster_entrypoint_18(this);
    flags = func_8010BA80(this, 0x305425, 0x20);
    if (flags & 0x20) {
        func_8010AA54(pos);
        if (func_800F1EA4(pos, &ang) && sucoaster_entrypoint_9(this, 6, 1)) {
            func_80802384_sucoaster(this, s, ang);
        }
    } else if ((flags & 4) && sucoaster_entrypoint_9(this, 6, 1)) {
        this->unk54 = func_800136E4(this->rotation[1] + func_800DC178(140.0f, 2.2e+02f));
    }
    return flags & 0x24;
}

void sucoaster_entrypoint_8(int param_0)
{
  int new_var;
 do { new_var = 0x505410; func_8010BA80(param_0, new_var, 0x20); } while (0);
}

s32 sucoaster_entrypoint_9(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    CoasterMessage1482 local_1;

    local_1.field_b = param_2;
    local_1.field_a = param_1;
    if (func_8010108C(param_0, 0x42, *(s32 *)&local_1) > 0) {
        sucoaster_entrypoint_10(param_0, param_1);
        return 1;
    }
    return 0;
}

void func_80802260_sucoaster();

s32 sucoaster_entrypoint_10(param_0, param_1) u8 *param_0; s32 param_1;
{
    s8 padA[8];
    u8 *temp_s1;
    s32 sp20;

    temp_s1 = func_80100094(param_0, 0);
    func_80102424(param_0, param_1);
    ((SB1 *)(temp_s1 + 0x19))->f = 1;
    switch (param_1) {
    case 2:
        *(f32 *)(param_0 + 0x58) = 2.0f;
        if (((SW6 *)(temp_s1 + 0x18))->f) {
            *(f32 *)(param_0 + 0x58) = *(f32 *)(param_0 + 0x58) * 0.7f;
        }
        sucoaster_entrypoint_6(param_0, 0.0f);
        break;
    case 3:
        sp20 = _sucoasterdata_entrypoint_2(*(u32 *)(temp_s1 + 0x18) >> 28);
        sucoaster_entrypoint_6(param_0, func_800DC178((f32)sp20, (f32)_sucoasterdata_entrypoint_3(*(u32 *)(temp_s1 + 0x18) >> 28)));
        *(f32 *)(param_0 + 0x58) = 4.0f;
        sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_2(*(u32 *)(temp_s1 + 0x18) >> 28));
        break;
    case 4:
        sp20 = _sucoasterdata_entrypoint_3(*(u32 *)(temp_s1 + 0x18) >> 28);
        sucoaster_entrypoint_6(param_0, func_800DC178((f32)sp20, (f32)_sucoasterdata_entrypoint_4(*(u32 *)(temp_s1 + 0x18) >> 28)));
        *(f32 *)(param_0 + 0x58) = 4.0f;
        sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_3(*(u32 *)(temp_s1 + 0x18) >> 28));
        break;
    case 5:
        sucoaster_entrypoint_6(param_0, 0.0f);
        *(f32 *)(param_0 + 0x54) = func_8080264C_sucoaster(param_0, temp_s1);
        break;
    case 6:
        ((SC6E *)(param_0 + 0x6E))->f = func_800D9058(2.0f);
        *(f32 *)(param_0 + 0x24) = 0.0f;
        ((SB2 *)(temp_s1 + 0x18))->f = 1;
        sucoaster_entrypoint_6(param_0, 0.0f);
        temp_s1[0x16] = 0;
        break;
    case 7:
        sucoaster_entrypoint_6(param_0, 0.0f);
        break;
    case 8:
        sucoaster_entrypoint_6(param_0, (f32)_sucoasterdata_entrypoint_4(*(u32 *)(temp_s1 + 0x18) >> 28));
        sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_3(*(u32 *)(temp_s1 + 0x18) >> 28));
        if (!((SW2 *)(param_0 + 0x64))->f) {
            *(f32 *)(param_0 + 0x54) = func_8080264C_sucoaster(param_0, temp_s1);
        }
        break;
    case 9:
        ((SB20 *)(temp_s1 + 0x19))->f = 0;
        sucoaster_entrypoint_6(param_0, 0.0f);
        break;
    case 10:
        sucoaster_entrypoint_6(param_0, (f32)_sucoasterdata_entrypoint_4(*(u32 *)(temp_s1 + 0x18) >> 28));
        sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_3(*(u32 *)(temp_s1 + 0x18) >> 28));
        *(f32 *)(param_0 + 0x54) = func_8080230C_sucoaster(param_0, temp_s1);
        break;
    case 11:
        *(f32 *)(param_0 + 0x24) = 0.0f;
        break;
    case 12:
        func_80802260_sucoaster(param_0, temp_s1);
        break;
    case 13:
        break;
    case 14:
        func_8010A570(param_0);
        sucoaster_entrypoint_6(param_0, 0.0f);
        ((SB4 *)(temp_s1 + 0x18))->f = 1;
        ((SB01 *)(param_0 + 0x64))->f = 0;
        *(f32 *)(param_0 + 0x24) = 0.0f;
        *(f32 *)(param_0 + 0x58) = 3.0f;
        _subaddiefade_entrypoint_5(param_0);
        break;
    case 15:
        *(f32 *)(param_0 + 0x24) = 0.0f;
        *(f32 *)(param_0 + 0x58) = 0.7f;
        temp_s1[0x14] = 0;
        break;
    case 16:
    case 17:
        break;
    case 18:
        ((SB01 *)(temp_s1 + 0x18))->f = func_800DC298(0.5f);
        *(f32 *)(param_0 + 0x24) = 0.0f;
        sucoaster_entrypoint_6(param_0, (f32)_sucoasterdata_entrypoint_4(*(u32 *)(temp_s1 + 0x18) >> 28) * 1.2f);
        sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_3(*(u32 *)(temp_s1 + 0x18) >> 28));
        break;
    }
    return 1;
}

void sucoaster_entrypoint_11(Actor *param_0, f32 param_1)
{
    s16 *local_0;
    f32 local_1;
    f32 local_2;

    local_0 = (s16 *)func_80100094(param_0, 0);
    local_1 = func_8010203C(param_0, param_0->unk70_10);
    param_1 *= local_0[6] * 0.00390625f;
    if (local_0[7] != 0.0f) {
        local_2 = param_1 / local_0[7];
        if (local_2 < 0.4f) {
            local_2 = 0.4f;
        }
        func_80101CDC(param_0, local_1 * local_2);
    }
}

s32 sucoaster_entrypoint_12(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (!((CoasterRouteFlags *)local_0)->local_0 &&
        _subaddierouteDll_entrypoint_4(param_0, local_0) == 0) {
        return 0;
    }
    return _subaddierouteDll_entrypoint_7(param_0, local_0,
        param_0->rotation[1], param_0->rotation[1], *(s16 *)(local_0 + 0x10), 0x102);
}

int func_808015F8_sucoaster(Actor *param_0, CoasterRouteState *param_1)
{
    f32 local_0[3];
    u8 local_3;
    s32 local_1;
    s32 local_2;
    local_2 = func_80802760_sucoaster(param_1);
    local_3 = param_1->local_0;
    local_1 = local_3 ? local_3 : ((CoasterRouteActor *)param_0)->local_1;
    func_800F5A00(local_2, local_0);
    param_1->local_0 = func_800CC338(local_0, ((CoasterRouteActor *)param_0)->local_0 - 1, local_1 - 1) + 1;
    return param_1->local_0 != 0;
}

s32 sucoaster_entrypoint_13(Actor *param_0)
{
    void *local_0 = func_80100094(param_0, 0);

    if (param_0->unk6C_0) param_0->unk6C_0--;
    if (func_800DB9B0()) return 0;
    if (func_801072A8(param_0)) return 0;
    if (func_80802760_sucoaster(local_0) == -1) return 0;
    if (func_8080202C_sucoaster(param_0, local_0)) {
        if (func_80802594_sucoaster(param_0, local_0)) {
            sucoaster_entrypoint_9(param_0, 10, 0);
            return 2;
        }
        if (param_0->unk6C_0) return 0;
        if (func_808015F8_sucoaster(param_0, local_0) && _suchase_entrypoint_1(param_0)) {
            if (param_0->unk70_10 != 9 || !sucoaster_entrypoint_9(param_0, 8, 0)) {
                sucoaster_entrypoint_9(param_0, 5, 0);
            }
            return 1;
        }
    }
    return 0;
}

s32 sucoaster_entrypoint_14(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (func_80802594_sucoaster(param_0, local_0)) {
        local_0[0x12] = func_800D9058(func_800DC178(5.0f, 8.0f));
        return 1;
    }
    if (func_8080202C_sucoaster(param_0, local_0) &&
        func_808015F8_sucoaster(param_0, local_0) && _suchase_entrypoint_1(param_0)) return 0;
    local_0[0x12] = func_800D9058(func_800DC178(5.0f, 8.0f));
    return 1;
}

void sucoaster_entrypoint_15(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (func_80802594_sucoaster(param_0, local_0)) {
        sucoaster_entrypoint_9(param_0, 10, 0);
    } else if (param_0->unk70_10 == 8) {
        sucoaster_entrypoint_9(param_0, 4, 0);
        param_0->unk58 = func_800DC178(2.0f, 4.0f);
    } else {
        sucoaster_entrypoint_9(param_0, 3, 0);
    }
    local_0[0x12] = func_800D9058(func_800DC178(5.0f, 8.0f));
    param_0->unk6C_0 = (u16)func_800D9058(2.0f);
    _subaddierouteDll_entrypoint_6(param_0, local_0, local_0[0x16], 0, 1.0f, 40, 60);
}

s32 sucoaster_entrypoint_16(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    f32 local_2;
    local_0 = (u8 *)_sucoasterdata_entrypoint_1(((CoasterEventKind *)func_80100094(param_0, 0))->kind);
    local_1 = param_1 * 8;
    if (*(s16 *)(local_0 + local_1 + 4) == 0) return 0;
    local_2 = *(s16 *)(local_0 + local_1 + 10) * (1.0f / 256.0f);
    if (func_80101E14(param_0, local_2)) {
        sucoaster_entrypoint_17(param_0, param_1);
        return 1;
    }
    return 0;
}

int sucoaster_entrypoint_17(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_1;
    u8 *local_0;
    s32 local_3;
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    local_0 = (u8 *)_sucoasterdata_entrypoint_1(((CoasterEventKind *)local_0)->kind);
    if (*(s16 *)((local_0 + 4) + param_1 * 8)) {
        func_8010D640(local_2);
        if (func_800EEB40(local_2, param_0->position) >= 6250000.0f) {
            return 0;
        }
        local_1 = *(s16 *)((local_0 + 8) + param_1 * 8) * 0.00390625f + func_800DC178(-0.05f, 0.05f);
        func_800C4104(*(s16 *)((local_0 + 4) + param_1 * 8), local_1,
            *(s16 *)((local_0 + 6) + param_1 * 8), param_0->position, 1250.0f, 2500.0f);
        return 1;
    }
    return 0;
}

void sucoaster_entrypoint_18(s32 arg0)
{
    func_80105230(arg0,0);
}

s32 sucoaster_entrypoint_19(s32 param_0) {
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
    }
}

void sucoaster_entrypoint_20()
{
    func_80101870();
}

void func_80802690_sucoaster();

s32 sucoaster_entrypoint_21(u8 *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    struct { s32 a; s32 b; f32 c; u8 pad[0x18]; } sp28;
    s32 temp;
    s32 sp20;

    switch (param_1) {
    case 1:
    case 2:
        if (!((Coaster78 *)param_0)->b78_2) {
            _sucoasterplayer_entrypoint_1(param_0);
            return 1;
        }
        break;
    case 3:
        ((Coaster64 *)param_0)->b64_6 = 0;
        ((Coaster64 *)param_0)->b64_0 = 0;
        break;
    case 4:
        ((Coaster64 *)param_0)->b64_6 = 1;
        ((Coaster64 *)param_0)->b64_0 = 1;
        break;
    case 0x2B:
        local_0 = func_80100094(param_0, 0);
        temp = param_2 == 0;
        ((Coaster64 *)param_0)->b64_6 = temp;
        ((Coaster64 *)param_0)->b64_0 = temp;
        if (param_2 != 0) {
            local_0[0x13] = func_800D9058(1.8f);
        }
        break;
    case 0x50:
        if (((u32)*(u16 *)(param_0 + 0x72) >> 10) == 9) {
            param_1 = (s32)func_80100094(param_0, 0);
            if (((CoasterObj *)param_1)->b18_21) {
                return *(s16 *)((u8 *)_sucoasterdata_entrypoint_1((u32)*(u32 *)((u8 *)param_1 + 0x18) >> 28) + 0x58) + ((param_2 >> 16) & 0xFFFF) + 1;
            }
        }
        return 0;
    case 0x4D:
        if (func_80107070(param_0, 3) == 0) {
            return 0;
        }
        break;
    case 0x8F:
        switch (param_2) {
        case 0:
            func_8010A590(param_0);
            sucoaster_entrypoint_9(param_0, 2, 8);
        case 4:
            ((Coaster77 *)param_0)->lo77 = 1;
            goto brk;
        default:
            goto brk;
        }
    case 0x29:
        func_80802690_sucoaster(param_0, func_80100094(param_0, 0));
        return 1;
    case 0x2A:
        func_80802728_sucoaster(param_0, func_80100094(param_0, 0));
        return 1;
    case 0x94:
        if (func_80100094(param_0, 1) == 0) {
            return 0;
        }
        sp28.c = 0.0f;
        _suexpression_entrypoint_13(func_80100094(param_0, 1), &sp28.b, &sp28);
        func_80101010(&sp28);
        return 1;
    case 0x95:
        _subaddierouteDll_entrypoint_1(param_0);
        return 1;
    case 0x38:
        local_0 = func_80100094(param_0, 0);
        func_80101074(_sucoasterdata_entrypoint_5((u32)*(u32 *)(local_0 + 0x18) >> 28, ((Coaster6C *)param_0)->f6C_9, &sp20));
        return sp20;
    case 0x9A:
        if (((u32)*(u16 *)(param_0 + 0x72) >> 10) != 0xC) {
            sucoaster_entrypoint_10(param_0, 0xC);
            _subaddieDll_entrypoint_4(param_0, 1);
        }
brk:
        break;
    case 0x42:
        break;
    default:
        return 0;
    }
    return 1;
}

void sucoaster_entrypoint_22(s32 param_0)
{
  u8 *sp24;
  f32 temp_f0;
  f32 temp_f12;
  u8 *temp_v0;
  float new_var;
  sp24 = func_80100094(param_0, 0);
  if ((func_801072A8(param_0) == 0) || (func_801072E4(param_0) != 0))
  {
    temp_v0 = _sucoasterdata_entrypoint_1(((u32) (*((u32 *) (((s8 *) sp24) + 0x18)))) >> 0x1C);
    temp_f0 = ((f32) (*((s16 *) (((s8 *) sp24) + 0xC)))) * 0.00390625f;
    new_var = ((f32) (*((s16 *) (((s8 *) temp_v0) + 0x54)))) * temp_f0;
    temp_f12 = ((f32) (*((s16 *) (((s8 *) temp_v0) + 0x56)))) * temp_f0;
    func_8010D6E0(param_0, param_0 + 4, temp_f12, new_var);
  }
}

s32 func_8080202C_sucoaster(param_0, param_1) Actor *param_0; CoasterTrackItem *param_1;
{
    s32 local_0;
    f32 local_1[3];
    local_0 = func_80802760_sucoaster(param_1);
    if (local_0 == -1) return 0;
    if (!func_800F6478(local_0)) return 0;
    if (!param_1->local_0) return 1;
    func_800F5A00(local_0, local_1);
    return func_800EFFB4(param_0->position, 1800.0f, local_1);
}

void func_808020B8_sucoaster(Actor *param_0, CoasterPropKind *param_1, f32 param_2)
{
    CoasterSpeedRecord *local_0;
    local_0 = _sucoasterdata_entrypoint_1(param_1->local_0);
    func_80102BF8(param_0, local_0->unk4C * param_2,
        local_0->unk50 * param_2, local_0->unk52 * param_2);
}

typedef struct CoasterPropSize {
    u8 pad_0[0x10];
    s16 local_0;
    u8 pad_1[7];
    u8 pad_2 : 3;
    u8 local_1 : 1;
    u8 pad_3 : 4;
} CoasterPropSize;

void func_80802130_sucoaster(param_0, param_1, param_2) Actor *param_0; CoasterPropSize *param_1; s16 param_2;
{
    if (((CoasterActorFlags *)param_0)->local_0 && param_0->unk74_7 != 0x32) {
        param_1->local_0 = param_0->unk74_7;
        param_1->local_1 = 1;
    } else {
        param_1->local_0 = param_0->scale * param_2;
        param_1->local_1 = 0;
    }
}

typedef struct CoasterRadius1548 {
    u8 pad_0[12];
    s16 local_0;
    s16 local_1;
    s16 local_2;
    u8 pad_1[6];
    u32 local_3 : 4;
    u32 pad_2 : 7;
    u32 local_4 : 1;
    u32 pad_3 : 20;
} CoasterRadius1548;

f32 func_808021A8_sucoaster(param_0, param_1, param_2) Actor *param_0; CoasterRadius1548 *param_1; u32 param_2;
{
    f32 local_0;

    if ((param_2 & 0x1000) || param_1->local_4) return param_1->local_2;
    local_0 = ((f32)param_1->local_1 / (f32)_sucoasterdata_entrypoint_4(param_1->local_3)) *
        ((f32)param_1->local_0 * 0.00390625f) * (f32)param_1->local_2;
    return func_800F0E00(func_80103EAC(param_0) + 50.0f, local_0);
}

void func_80802260_sucoaster(SuCoasterBits *param_0, s32 param_1)
{
    func_8010A570(param_0);
    param_0->unk64_24 = 0;
    param_0->unk70_4 = 0;
    param_0->unk70_25 = param_0->unk70_4;
    param_0->unk64_30 = 0;
    param_0->unk64_31 = param_0->unk64_30;
    param_0->unk14 &= ~0x80000;
    param_0->unk77_0 = 2;
}

f32 func_8080230C_sucoaster(Actor *param_0, s32 param_1)
{
    s32 local_1;
    f32 local_0;

    local_0 = func_80102D78(param_0, (f32 *)param_0->actorData);
    return func_800136E4((func_800F1DCC(param_0->rotation[1], local_0) > 0.0f ? 110.0f : -110.0f) + local_0);
}

s32 func_80802384_sucoaster(Actor *param_0, u8 *param_1, f32 param_2)
{
    f32 local_0;
    local_0 = func_800136E4(func_800DC178(-20.0f, 20.0f) + param_2);
    if (_subaddierouteDll_entrypoint_7(param_0, param_1, local_0, local_0, *(s16 *)(param_1 + 0x10), 2) == 0) {
        return 0;
    }
    return 1;
}

s32 func_80802400_sucoaster(Actor *param_0, u8 *param_1)
{
    u8 *local_0;
    f32 local_3;
    f32 local_1[3];
    f32 local_2;
    f32 local_4;
    f32 local_5;
    local_0 = (u8 *)_sucoasterdata_entrypoint_1(*(u32 *)(param_1 + 0x18) >> 28);
    local_2 = func_800F57F0((void *)func_80802760_sucoaster(param_1), local_1);
    local_3 = (u32)*(u16 *)(local_0 + 0x4A) * (*(s16 *)(param_1 + 12) * 0.00390625f);
    local_4 = *(f32 *)((u8 *)param_0 + 0x24);
    local_5 = func_800D8FF8();
    while (local_4 > 0.0f) {
        local_3 += local_5 * local_4;
        local_4 = func_800F15F8(local_4, 0.0f, func_80107C00() * 30.0f);
    }
    local_3 += local_2;
    return func_800EFC7C(param_0->position, local_1) < local_3 * local_3;
}

int func_80802550_sucoaster(s32 param_0, s32 param_1)
{
  if (func_8080202C_sucoaster(param_0, param_1))
  {
    return !func_80802594_sucoaster(param_0, param_1) | 0;
  }
  return 1;
}

s32 func_80802594_sucoaster(param_0, param_1) s32 *param_0; CoasterPropKind *param_1;
{
    CoasterSpeedRecord *local_0;
    s32 local_1;
    s32 local_2;
    local_0 = _sucoasterdata_entrypoint_1(param_1->local_0);
    local_1 = func_80802760_sucoaster(param_1);
    if (local_1 == -1) return 0;
    if (func_800F64A4(local_1, *(s32 *)((u8 *)local_0 + 0x40))) return 1;
    if (func_800F5C94(local_1) == 3) return 1;
    local_2 = func_800F52B8(local_1, *param_0);
    if (local_2 == 0xF || local_2 == 0x19) return 1;
    return 0;
}

f32 func_8080264C_sucoaster(u8 *param_0, s32 param_1) {
    s32 local_0 = func_80802760_sucoaster(param_1);
    if (local_0 == -1) {
        return *(f32 *)(param_0 + 0x48);
    }
    return func_8010CD50(param_0, local_0);
}

void func_80802690_sucoaster(s32 param_0, u8 *param_1) {
    u8 *local_0;

    local_0 = _sucoasterdata_entrypoint_1((u32) (*(u32 *)((s8 *)(param_1) + (0x18))) >> 0x1C);
    if ((func_80100094(param_0, 1) == 0) && (_suexpression_entrypoint_1((*(u8 *)((s8 *)(local_0) + (3)))) != 0)) {
        _suexpression_entrypoint_7(param_0, 1, (*(s16 *)((s8 *)(local_0) + (2))));
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 0x42700000, 0x42200000);
        _suexpression_entrypoint_17(func_80100094(param_0, 1), 0x960);
    }
}

s32 func_80802728_sucoaster(param_0, param_1) void *param_0; s32 param_1; {
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_8(param_0, 1);
    }
}

s32 func_80802760_sucoaster(param_0) void *param_0;
{
  u32 temp_v0;
  int new_var;
  temp_v0 = (*((u32 *) ((u8 *)param_0 + 0x18))) & 0xFFFFFFFFFFFFFFFFu;
  new_var = temp_v0 & 0x80000;
  if (new_var)
  {
    return func_800F54E4();
  }
  return func_8010D290(*((s32 *) ((u8 *)_sucoasterdata_entrypoint_1(temp_v0 >> 0x1C) + 0x3C)));
}
