#include "common.h"

#define BLUBBER_STATE_RECORD_DEFINED
extern void func_8010D5DC(Unk80132ED0 *);
extern u8 D_808016C0_chcaptainblubber[];
extern void func_8008F990(void *, f32);
typedef struct { u16 local_0; u8 pad_0[6]; } BlubberStateRecord;
extern BlubberStateRecord D_80801654_chcaptainblubber[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern int D_8080176C_chcaptainblubber;
typedef struct { u8 pad_0[0x79]; u8 mode:4; u8 pad_1:4; } BlubberFlags30;
extern u8 D_808016CC_chcaptainblubber[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void *_gccubesearch_entrypoint_1(s32, f32 *);
typedef struct { u8 pad0[0x70]; u32 pad70 : 28; u32 bit3 : 1; u32 pad70b : 3; } BlubberFlags70;
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80105998(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
extern void func_8010C93C(Actor *, f32 *, f32);
extern s32 D_808016D8_chcaptainblubber;
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern s32 _capod_entrypoint_17(f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 func_800D1A04(s32);
typedef struct { f32 times[3]; } BlubberTimes3;
typedef struct { f32 times[4]; } BlubberTimes4;
typedef struct { f32 times[7]; } BlubberTimes7;
extern s32 func_80101E4C(Actor *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC128(s32, s32);
extern void func_800C4140(s32, f32 *, s32);
extern void func_800C3F48(s32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
void func_80800A1C_chcaptainblubber();

void func_80800000_chcaptainblubber(Actor *param_0)
{
    if (!param_0->unk64_20) {
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(func_8010D5DC, param_0->unk0);
        func_8008F938(1);
        func_8008F990(D_808016C0_chcaptainblubber, 500.0f);
        param_0->unk64_20 = 1;
    }
}

s32 func_80800078_chcaptainblubber(Actor *this){
    s32 local_0 = func_801000D8(this, 0, 0x14);
    _subaddieitem_entrypoint_0(local_0, 0x4E4, 0x3E8, 3);
    _subaddieitem_entrypoint_2(local_0);
    func_80102424(this, 5);
}

void func_808000CC_chcaptainblubber(Actor *param_0)
{
    void *local_0;
    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(param_0->position, (f32 *)D_808016CC_chcaptainblubber);
        func_80102424(param_0, 11);
        return;
    }
    local_0 = _gccubesearch_entrypoint_1(0x299, param_0->position);
    if (!local_0) {
        func_800FFA88(param_0->unk0);
        return;
    }
    _gspropctrl_entrypoint_11(local_0, param_0->actorData);
    *(f32 *)((u8 *)param_0 + 0x54) = _gspropctrl_entrypoint_12(local_0);
    ((BlubberFlags30 *)param_0)->mode = 0;
    if (func_800EEAD4(param_0->position, (f32 *)param_0->actorData) > 1000000.0f) {
        func_800FFA88(param_0->unk0);
        return;
    }
    *(f32 *)((u8 *)param_0 + 0x34) = 0.0f;
    param_0->position[0] += 175.0f;
    param_0->position[2] += -33.0f;
    if (func_800DA298(0xE0)) func_80108B04(param_0, 1);
}

void func_8080143C_chcaptainblubber();

void func_808001F0_chcaptainblubber(Actor *param_0)
{
    f32 local_2[3];
    char *local_1;
    s32 local_3;


    func_8010C93C(param_0, param_0->position, 0.75f);

    if (((BlubberFlags70 *)param_0)->bit3) {
        local_1 = (char *)func_80100094(param_0, 1);
        _suexpression_entrypoint_10(local_1, *(s32 *)((char *)param_0 + 0), 0);
    }

    func_800D1824(0x4E);

    switch (param_0->unk70_10) {
        case 1:
        case 2:
            local_3 = func_800F54E4();

            if (func_800F64A4(local_3, 0x201)) {
                if (func_800DA298(0xDF)) {
                    if (_subaddiedialog_entrypoint_6(
                            param_0->position,
                            (s32)*(f32 *)((char *)param_0 + 0x48),
                            0x12C,
                            0x3C,
                            0)) {
                        func_80800000_chcaptainblubber(param_0);
                    }
                } else {
                    if (_subaddiedialog_entrypoint_3(
                            param_0->position,
                            (s32)*(f32 *)((char *)param_0 + 0x48),
                            0x12C,
                            0x3C,
                            0)) {
                        func_80800000_chcaptainblubber(param_0);
                    }
                }
            } else {
                if (_subaddiedialog_entrypoint_6(
                        param_0->position,
                        (s32)*(f32 *)((char *)param_0 + 0x48),
                        0x12C,
                        0x3C,
                        0)) {
                    _subaddiedialog_entrypoint_11(
                        *(s32 *)((char *)param_0 + 0),
                        0x1208,
                        0xE,
                        param_0->position,
                        0x64
                    );
                }
            }
            break;

        case 5:
            local_1 = (char *)func_80100094(param_0, 0);

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x1E,
                local_2
            );

            if (_subaddieitem_entrypoint_3(
                    param_0,
                    local_2,
                    local_1)) {
                func_80102424(param_0, 6);
                func_80100074(param_0, 0, 0);

                local_3 = func_800F54E4();
                func_800F82D4(local_3, 1);
            }
            break;

        case 6:
            if (func_80101DDC(param_0)) {
                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x100B,
                    0xE,
                    param_0->position,
                    0x64
                );

                *(u8 *)((char *)param_0 + 0x65) &= ~8;

                func_80102424(param_0, 7);

                *(f32 *)((char *)param_0 + 4) -= 175.0f;
                *(f32 *)((char *)param_0 + 0xC) -= -33.0f;
            }
            break;

        case 7:
            if (func_80101E14(param_0, 0.999f)) {
                if (param_0->unk64_19) {
                    local_3 = func_800F54E4();
                    func_800F82D4(local_3, 0);

                    func_80102424(param_0, 8);
                    func_80105A9C(param_0, 500.0f);
                }
            }
            break;

        case 8:
            func_80105834(param_0);
            func_800A54C0(param_0->position);

            if (func_80105998(param_0, 0.84f)) {
                func_80102424(param_0, 9);
            }
            break;

        case 9:
            func_800A54C0(param_0->position);

            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 0xA);
            }
            break;

        case 10:
            func_80105834(param_0);

            if (func_80105A5C(param_0)) {
                _capod_entrypoint_22();
                func_800FFA88(*(s32 *)((char *)param_0 + 0));
            }
            break;

        case 12:
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 0xD);
            }
            break;

        case 13:
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 0xC);
            }
            break;
    }

    func_80800A1C_chcaptainblubber(param_0);
    func_8080143C_chcaptainblubber(param_0);
}

s32 func_80800580_chcaptainblubber(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    s32 local_1;
    s32 local_2;

    switch (param_1) {
    case 0x95:
        _suexpression_entrypoint_7(param_0, 1, 0x64);
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 30.0f, 15.0f);
        return 1;
    case 0x2E:
        switch (((s16 *)&param_2)[0]) {
        case 0x1006:
        case 0x1007:
        case 0x106B:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1008, 0x4E, param_0->position, 0x64);
            func_80102424(param_0, 2);
            return 1;
        case 0x1008:
            if (((s16 *)&param_2)[1] > 0) {
                if (func_800D1A04(0x4E) <= 0) {
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x100A, 0xE, param_0->position, 0x64);
                    return 1;
                }
                func_80800078_chcaptainblubber(param_0);
                return 1;
            }
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1009, 0xE, param_0->position, 0x64);
            return 1;
        case 0x1009:
        case 0x100A:
            func_80102424(param_0, 2);
            return 1;
        case 0x100B:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x103F, 0x4E, param_0->position, 0x64);
            func_800DA544(0xE0);
            func_800D175C(0x4E, -1);
            return 1;
        case 0x103F:
            return 1;
        }
        return 0;
    case 0x30:
        if (((s16 *)&param_2)[0] == 0x1006 || ((s16 *)&param_2)[0] == 0x1007 ||
            ((s16 *)&param_2)[0] == 0x1008 || ((s16 *)&param_2)[0] == 0x106B) {
            return 1;
        }
        return 0;
    case 0xE:
        if (_capod_entrypoint_17(0.3f)) {
            func_80108B04(param_0, 0);
        }
        return 3;
    case 0xB:
        _capod_entrypoint_14();
        if (func_800C064C()) {
            func_800C01A8(0x6B, 0);
            _capod_entrypoint_21(param_0->unk0, param_0->unk0, 4, 0x2011);
        }
        return 4;
    case 0x2F:
        switch (((s16 *)&param_2)[0]) {
        case 0x100B:
            func_800C01A8(0x6B, 0);
            _capod_entrypoint_13(param_0->unk0, param_0->unk0, 0, 0x6010);
            func_800FC6B0(0xE);
            break;
        case 0x103F:
            param_0->unk64_19 = 1;
            break;
        default:
            break;
        }
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_808016D8_chcaptainblubber, param_0->scale);
        return 1;
    case 0x3D:
        local_0 = func_80108528(0x1F0, (f32 *)param_0->actorData, (s32)param_0->unk54, &param_0);
        local_0->unk74_7 = 0x33;
        if (func_800DB9B0()) {
            _chappearfx_entrypoint_1(local_0, 0x20, 0, 1.0f);
        }
        if (param_2) {
            func_800FFA88(param_0->unk0);
        }
        return 1;
    case 0x32:
        local_2 = 0xE;
        local_1 = 0;
        switch (param_0->unk70_10) {
        case 1:
            if (func_800DA298(0xDF)) {
                local_1 = 0x1007;
            } else {
                func_800DA544(0xDF);
                switch (func_800F5410(func_800F54E4())) {
                case 1:
                    local_1 = 0x1006;
                    break;
                case 10:
                    local_1 = 0x106B;
                    break;
                }
            }
            break;
        case 2:
            local_1 = 0x1008;
            local_2 = 0x4E;
            break;
        }
        if (local_1) {
            _subaddiedialog_entrypoint_11(param_0->unk0, local_1, local_2, param_0->position, 0x64);
        }
        param_0->unk64_20 = 0;
        return 1;
    }
    return 0;
}

void func_80800A1C_chcaptainblubber(param_0) Actor *param_0;
{
    extern BlubberStateRecord D_80801654_chcaptainblubber[];
    extern BlubberTimes4 D_808016E8_chcaptainblubber;
    extern BlubberTimes3 D_808016F8_chcaptainblubber;
    extern BlubberTimes3 D_80801704_chcaptainblubber;
    extern BlubberTimes3 D_80801710_chcaptainblubber;
    extern BlubberTimes7 D_8080171C_chcaptainblubber;
    extern BlubberTimes3 D_80801738_chcaptainblubber;
    extern u8 D_80801744_chcaptainblubber[];

    s32 local_0;
    BlubberTimes4 local_1;
    BlubberTimes3 local_2;
    BlubberTimes3 local_3;
    BlubberTimes3 local_4;
    BlubberTimes7 local_5;
    BlubberTimes3 local_6;
    f32 local_8[3];
    f32 local_7[3];

    local_0 = 0;

    switch (D_80801654_chcaptainblubber[param_0->unk70_10].local_0) {
        case 0x159:
            local_1 = D_808016E8_chcaptainblubber;

            if (func_80101E4C(param_0, local_1.times)) {
                                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0x119564,
                    (char *)param_0 + 4,
                    0x04B000FA
                );

                                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0x119614,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.22f)) {
                func_800C4140(
                    0x4CB194E3,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            } else if (func_80101E14(param_0, 0.4f)) {
                func_800C4140(
                    0x4CB194E4,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }
            break;


        case 0x1C0:
            if (func_80101E14(param_0, 0.14f)) {
                func_800C4140(
                    0x7FF19612,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            } else if (func_80101E14(param_0, 0.55f)) {
                local_0 = 1;

                                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x1B5C50,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }
            break;
        case 0x15A:
            local_2 = D_808016F8_chcaptainblubber;

            local_3 = D_80801704_chcaptainblubber;

            if (param_0->unk70_10 == 0xB) {
                if (func_80101E14(param_0, 0.24f)) {
                                        func_800C3F48(
                        ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x09C612
                    );
                }
            } else if (func_80101E4C(param_0, local_2.times)) {
                    if (param_0->unk70_10 == 9) {
                    func_800C3F48(0x7FE7D612);
                } else {
                    func_800C4140(
                        0x7FE7D612,
                        (char *)param_0 + 4,
                        0x04B000FA
                    );
                }
            }

            if (func_80101E4C(param_0, local_3.times)) {
                local_0 = 1;

                                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x177450,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }
            break;


        case 0x1BF:
            local_4 = D_80801710_chcaptainblubber;

            if (func_80101E4C(param_0, local_4.times)) {
                local_0 = 1;

                                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x119451,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }
            break;


        case 0x17B:
            local_5 = D_8080171C_chcaptainblubber;

            local_6 = D_80801738_chcaptainblubber;

            if (func_80101E4C(param_0, local_5.times)) {
                local_0 = 1;

                                func_800C4140(
                    (((func_800DC128(0x36B0, 0x3E81) >> 5) & 0x3FF) << 11) +
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                    0x451,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }
            break;


        case 0x16D:
            if (func_80101E14(param_0, 0.07f)) {
                func_800C4140(
                    0x7FF19612,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            } else if (func_80101E14(param_0, 0.9f)) {
                local_0 = 1;

                                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x09C451,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }
            break;


    }

    if (local_0 != 0) {
        _subaddieskeleton_entrypoint_0(
            param_0,
            0x14,
            local_7
        );

        _subaddieskeleton_entrypoint_0(
            param_0,
            6,
            local_8
        );

        func_800BBCB8(
            local_7,
            0,
            1.0f,
            1,
            D_80801744_chcaptainblubber
        );

        func_800BBCB8(
            local_8,
            0,
            1.0f,
            1,
            D_80801744_chcaptainblubber
        );
    }
}

void func_8080143C_chcaptainblubber(Actor *param_0)
{
    f32 local_0[3];
    if (D_80801654_chcaptainblubber[param_0->unk70_10].local_0 == 0x1C0) {
        _subaddieskeleton_entrypoint_0(param_0, 3, local_0);
        local_0[1] = 0.0f;
    } else func_800EFA4C(local_0, param_0->position[0], 0.0f, param_0->position[2]);
    _chbadshad_entrypoint_1(param_0, local_0, param_0->scale + param_0->scale);
}

void func_808014C8_chcaptainblubber(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
int chcaptainblubber_entrypoint_0()
{
  return (int)&D_8080176C_chcaptainblubber;
}
