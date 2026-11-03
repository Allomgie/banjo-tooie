#include "common.h"

extern int D_80802C0C_chboilerboss[];
extern int D_80802C54_chboilerboss[];
extern int D_80802C9C_chboilerboss[];
extern int D_80802CE4_chboilerboss[];
extern f32 D_80802B4C_chboilerboss;
extern void *func_8010D5DC;
extern void func_800F4A58(s32, u8 *, f32);
typedef struct {
    u8 pad0[0x28];
    u32 pad28 : 16;
    u32 pad28b : 2;
    u32 b13 : 1;
    u32 b12 : 1;
    u32 b11 : 1;
    u32 pad28c : 11;
} BoilerFlags;
extern void *func_80100094(Actor *, s32);
extern void func_801015D0(Actor *);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_2 : 11;
} BoilerThresholdFlags_80800B94_chboilerboss;
typedef struct BoilerThresholdFlags_808012C8_chboilerboss {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_2 : 11;
} BoilerThresholdFlags_808012C8_chboilerboss;
typedef struct {
    u8 pad_0[0x48];
    f32 timer;
    u8 pad_1[8];
    u8 used;
    u8 phase;
} BoilerWaitState;
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 third : 1;
    u32 second : 1;
    u32 first : 1;
    u32 pad_2 : 11;
} BoilerProgress;
extern void *func_800B53A4(int);
extern s32 D_80802D68_chboilerboss[6];
extern int func_800BABB8(void *, s32, s32, f32, void *);
extern s32 D_80802D88_chboilerboss[];
extern s32 D_80802DA4_chboilerboss[];
extern s32 D_80802DB0_chboilerboss[];
extern u8 D_80802DBC_chboilerboss[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern int D_80802E44_chboilerboss[];
extern int D_80802E6C_chboilerboss[];
typedef struct {
    u8 pad_0[0x24];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
} BoilerBossQuickSounds;
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, void *, void *, f32);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern u8 D_80802EA4_chboilerboss[];
extern u8 D_80802B20_chboilerboss[];
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest : 10;
} BoilerS;
extern f32 D_80802B58_chboilerboss;
extern f32 func_8010203C(BoilerS *, s32);
extern f32 func_80105AC4(BoilerS *);
extern void func_80101CDC(BoilerS *, f32);
typedef struct {
    u8 pad_0[0x18];
    u32 pad_1 : 27;
    u32 local_0 : 4;
    u32 pad_2 : 1;
    u8 pad_3[0xC];
    u32 pad_4 : 18;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 pad_5 : 11;
} BoilerMarker1493;
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_80101DDC(Actor *);
extern void _subaddiefade_entrypoint_3(Actor *);
extern u32 D_80802EB0_chboilerboss[];
extern void *D_80802EC4_chboilerboss;
extern void *D_80802ED0_chboilerboss;
extern void _subaddieaudioquick_entrypoint_4(void *, void *, void *, void *);
extern void func_800CE8D8(s32, f32, s32);
extern u8 D_80802EE4_chboilerboss[];
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
extern u8 D_80802EF8_chboilerboss[];
extern u8 D_80802F60_chboilerboss[];
typedef struct {
    u8 pad_0[0x48];
    f32 time;
    u8 pad_1[9];
    u8 active;
    u8 pad_2[0xA];
    s32 state;
} BoilerBossState;
extern void func_80109FE8(Actor *, s32);
extern u32 func_800F54E4(void);
extern s32 _plcamera_entrypoint_10(u32);
extern void _plcamera_entrypoint_9(u32, f32 *, f32);
extern s32 func_800F5EF8(u32);
extern s32 func_80110014(s32);
extern void func_80116088(s32, f32 *);
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_8(s32);
extern void _capod_entrypoint_7(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _gcdialogcamera_entrypoint_4(f32[3]);
extern void _gcdialogcamera_entrypoint_5(f32[3]);
extern void _gcdialogcamera_entrypoint_8(void);
typedef struct {
    u8 pad_0[0x59];
    u8 state;
} BoilerCameraState;
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} BoilerState;
typedef struct {
    u8 pad_0[0x28];
    u32 a : 18;
    u32 b13 : 1;
    u32 b12 : 1;
    u32 b11 : 1;
    u32 rest : 11;
} BoilerBits;
typedef struct {
    f32 a;
    f32 b;
} BoilerPair;
extern u8 D_80802AB0_chboilerboss[];
extern u8 D_80802B08_chboilerboss[];
extern u8 D_80802B14_chboilerboss[];
extern u8 D_80802B34_chboilerboss[];
extern u8 D_80802B40_chboilerboss[];
extern BoilerPair D_80802B5C_chboilerboss[];
extern u8 D_80802D2C_chboilerboss[];
extern u8 D_80802D38_chboilerboss[];
extern u8 D_80802D60_chboilerboss[];
extern f32 func_800DC178(f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800DC298(f32);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2();
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, u8 *);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 20;
    u32 touching : 1;
    u32 pad_2 : 11;
} BoilerMarkerFlags;
extern f32 func_80101F24(Actor *);
extern f32 func_800F0E00(f32, f32);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 20;
    u32 local_0 : 1;
    u32 pad_2 : 11;
} Mass45BoilerRenderFlags;
typedef struct {
    s32 local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;
} BoilerMorph61;
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_2 : 11;
} BoilerThresholdFlags_80801628_chboilerboss;
typedef union {
    f32 local_0;
    s32 local_1;
} BoilerSpawnWord1506;
extern void _chbaddiesetup_entrypoint_10(void);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern void _chexploder_entrypoint_5(Actor *, s16, f32 *, f32, f32, s32);
void func_80801B88_chboilerboss();
void func_80802098_chboilerboss();
void func_8080221C_chboilerboss(Actor *param_0, s32 param_1, volatile s32 param_2);
void func_8080238C_chboilerboss();
int func_80802538_chboilerboss();
void func_808025DC_chboilerboss();
void func_808026F0_chboilerboss();
void func_80802730_chboilerboss();
void func_808027E4_chboilerboss();
void func_80800D50_chboilerboss();
void func_80800F34_chboilerboss();
void func_808010F4_chboilerboss();
void func_80801628_chboilerboss();
void func_808017F0_chboilerboss();
void func_80801D80_chboilerboss();
extern void func_801018A4(), func_80102EC0(), func_80107C2C(), func_80108ED0(),
    func_80800030_chboilerboss(), func_80800304_chboilerboss(), func_80800324_chboilerboss();

extern u8 D_80802AA0_chboilerboss[];
extern f32 D_80802ACC_chboilerboss[];

int chboilerboss_entrypoint_0()
{
    return (int) &D_80802C0C_chboilerboss;
}

int chboilerboss_entrypoint_1()
{
    return (int) &D_80802C54_chboilerboss;
}

int *chboilerboss_entrypoint_2()
{
    return &D_80802C9C_chboilerboss;
}

int *chboilerboss_entrypoint_3()
{
    return &D_80802CE4_chboilerboss;
}

void func_808024B8_chboilerboss();

void func_80800030_chboilerboss(param_0) Actor *param_0;
{
    u8 *q;
    u8 *list[2];
    s32 i;
    s32 j;
    s32 n;
    s32 h;
    q = func_80100094(param_0, 0);
    func_800DA524(0x670);
    if (func_800DA298(0x86) && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(param_0);
        return;
    }
    param_0->pad5E = (*(s32 *) &param_0->actorData[5] = 0x32);
    *(f32 *) &param_0->actorData[4] = param_0->rotation[1];
    ((BoilerFlags *) param_0->unk0)->b11 = 1;
    ((BoilerFlags *) param_0->unk0)->b13 = ((BoilerFlags *) param_0->unk0)->b12 =
        ((BoilerFlags *) param_0->unk0)->b11;
    func_80105A9C(param_0, D_80802B4C_chboilerboss);
    func_80105BAC(param_0);
    func_80109FE8(param_0, 0);
    _suexpression_entrypoint_7(param_0, 1, 0x42);
    n = _gccubesearch_entrypoint_9(0x3DA, list, 2);
    i = 0;
    if (n > 0) {
        do {
            j = 0;
            if (n > 0) {
                do {
                    if ((((u32) *(u16 *) (list[j] + 6) >> 7) - 0x32) == i) {
                        break;
                    }
                    j++;
                } while (j != n);
            }
            func_800EE88C((q + 0x68) + (i * 0xC), list[j]);
            i++;
        } while (i < n);
    }
    h = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 0x11);
        return;
    }
    if (func_800DA298(0x179)) {
        *(s32 *) (q + 0x60) = 1;
        *(s16 *) (q + 0x66) = 1;
        *(u8 *) (q + 0x56) = 1;
        func_800F608C(h, 1);
        func_800F8294(h, q + 0x74);
        func_800F497C(h);
        func_8080238C_chboilerboss(param_0, 0xF9E, 0x10F);
        func_80800F34_chboilerboss(param_0, 4);
        func_808024B8_chboilerboss(param_0);
        func_80802730_chboilerboss(param_0, 2, 1);
        return;
    }
    *(s32 *) (q + 0x60) = 0;
    func_800F608C(h, 1);
    func_800F8294(h, q + 0x68);
    func_800F497C(h);
    func_800F49A8(h, 1);
    func_800F49D4(h, &func_8010D5DC, param_0->unk0);
    func_800F4A58(h, q + 0x74, 300.0f);
    _chintrotext_entrypoint_2(1);
    func_8080238C_chboilerboss(param_0, 0xFA8, 0x40);
    func_808027E4_chboilerboss(param_0, 0x13, 0x20, 0);
}

void func_80800304_chboilerboss(Actor *arg0)
{
    _suexpression_entrypoint_8(arg0, 1);
}

s32 func_808023C8_chboilerboss();

void func_80802114_chboilerboss();

void func_80801CE8_chboilerboss();

void func_80801C24_chboilerboss();

void func_808014F4_chboilerboss(Actor *param_0, f32 *param_1, f32 param_2);

void func_80801464_chboilerboss(Actor *param_0, f32 *param_1, f32 param_2);

void func_808013C4_chboilerboss();

void func_808012C8_chboilerboss();

void func_80800324_chboilerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];

    local_0 = func_80100094(param_0, 0);
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_0);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_0 + 0xC);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 6, local_0 + 0x18);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 7, local_0 + 0x3C);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 8, local_0 + 0x30);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 9, local_0 + 0x24);
    func_808012C8_chboilerboss(param_0);
    func_80801628_chboilerboss(param_0);
    func_80802114_chboilerboss(param_0);
    func_808023C8_chboilerboss(param_0);
    switch (((BoilerState *) param_0)->st) {
        case 1:
        case 13:
            break;
        case 2:
            func_808017F0_chboilerboss(param_0);
            if (func_80101DDC(param_0)) {
                func_80800F34_chboilerboss(param_0, 3);
            }
            func_80801C24_chboilerboss(param_0);
            break;
        case 3:
            if (func_80101DDC(param_0)) {
                func_800F82D4(func_800F54E4(), 0);
                func_8080238C_chboilerboss(param_0, 0xF97, 0x10E);
                func_80800F34_chboilerboss(param_0, 4);
            }
            break;
        case 5:
            func_80105834(param_0);
            func_808013C4_chboilerboss(param_0);
            func_80801CE8_chboilerboss(param_0);
            break;
        case 6:
            func_80105834(param_0);
            func_80801CE8_chboilerboss(param_0);
            if (func_80101E14(param_0, 0.2f)) {
                _subaddieaudioquick_entrypoint_2(param_0, local_0 + 0x3C,
                                                 func_800DC298(0.5f) ? D_80802B34_chboilerboss
                                                                     : D_80802B40_chboilerboss);
            }
            if (func_80101DDC(param_0)) {
                func_80800F34_chboilerboss(param_0, 5);
            }
            break;
        case 10:
            if (func_80101DDC(param_0)) {
                func_80800F34_chboilerboss(param_0, 5);
            }
            if (func_80101E14(param_0, 0.8f)) {
                local_1 = 3 - ((BoilerBits *) param_0->unk0)->b11 -
                          ((BoilerBits *) param_0->unk0)->b12 - ((BoilerBits *) param_0->unk0)->b13;
                if (func_800CEAD0(0)) {
                    func_800DA544(0x670);
                    func_8080221C_chboilerboss(param_0, 1, 0x501502F9);
                } else {
                    func_8080221C_chboilerboss(param_0, 1, 0x40A00000);
                }
                *(f32 *) (local_0 + 0x48) = func_800DC178(D_80802B5C_chboilerboss[local_1].a,
                                                          D_80802B5C_chboilerboss[local_1].b);
            }
            _subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x3C, D_80802D2C_chboilerboss,
                                             0.2f);
            break;
        case 7:
            _suexpression_entrypoint_9(func_80100094(param_0, 1));
            if (func_80101E14(param_0, 0.5f)) {
                func_80801464_chboilerboss(param_0, local_2, 40.0f);
                func_800BBCB8(local_2, (f32 *) (local_0 + 0x18), param_0->scale, 8,
                              D_80802AB0_chboilerboss);
                _subaddieaudioquick_entrypoint_2(param_0, local_2, D_80802B14_chboilerboss);
                func_80108B04(param_0, 0x223);
            }
            if (func_80101DDC(param_0)) {
                func_80800F34_chboilerboss(param_0, 5);
            }
            _subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x3C, D_80802B08_chboilerboss,
                                             0.2f);
            break;
        case 8:
            _suexpression_entrypoint_9(func_80100094(param_0, 1));
            if (func_80101E14(param_0, 0.5f)) {
                func_808014F4_chboilerboss(param_0, local_3, 40.0f);
                func_800BBCB8(local_3, (f32 *) (local_0 + 0x18), param_0->scale, 8,
                              D_80802AB0_chboilerboss);
                _subaddieaudioquick_entrypoint_2(param_0, local_3, D_80802B14_chboilerboss);
                func_80108B04(param_0, 0x224);
            }
            if (func_80101DDC(param_0)) {
                func_80800F34_chboilerboss(param_0, 5);
            }
            _subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x3C, D_80802B08_chboilerboss,
                                             0.2f);
            break;
        case 9:
            _suexpression_entrypoint_9(func_80100094(param_0, 1));
            if (func_80101E14(param_0, 0.3f)) {
                func_800EE7F8(local_4, (f32 *) (local_0 + 0x18));
                local_4[1] -= 120.0f;
                func_800BBCB8((f32 *) (local_0 + 0x18), local_4, param_0->scale, 0x10,
                              D_80802D38_chboilerboss);
                _subaddieaudioquick_entrypoint_2(param_0, local_0 + 0x18, D_80802B14_chboilerboss);
                func_80108B04(param_0, 0x225);
            }
            if (func_80101DDC(param_0)) {
                func_80800F34_chboilerboss(param_0, 5);
            }
            _subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x3C, D_80802B08_chboilerboss,
                                             0.0f);
            break;
        case 11:
            func_800F4EC8(func_800F54E4(), param_0->position, 340.0f, 0.0f, 300.0f);
            _subaddieDll_entrypoint_7(param_0, 8);
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80802D60_chboilerboss);
    }
    func_808025DC_chboilerboss(param_0);
}

void func_808024DC_chboilerboss();

void func_808022BC_chboilerboss();

void func_80801584_chboilerboss();

void func_80800E90_chboilerboss();

void func_80800B94_chboilerboss();

s32 func_808008B0_chboilerboss(Actor *param_0, s32 param_1, s32 param_2)
{
    char *local_0;
    s16 *local_1;

    local_0 = (char *) func_80100094(param_0, 0);

    switch (param_1) {
        case 0x3F:
            func_80800D50_chboilerboss(param_0, param_2);
            return 1;

        case 0x40:
            func_80800E90_chboilerboss(param_0, param_2);
            return 1;

        case 0x2E:
            local_1 = (s16 *) &param_2;
            func_80801D80_chboilerboss(param_0, local_1[0], local_1[1]);
            return 1;

        case 0x3D:
            func_80801584_chboilerboss(param_0, param_2);
            return 1;

        case 0x90:
            func_808022BC_chboilerboss(param_0);
            return 1;

        case 0x32:
            *(s16 *) (local_0 + 0x64) = 1;
            func_800F8300(func_800F54E4(), 2, (char *) param_0 + 4);
            return 1;

        case 0x1F:
            local_1 = (s16 *) &param_2;
            func_80800B94_chboilerboss(param_0, *(s32 *) local_1);
            return 1;

        case 0x0B:
            switch (param_2) {
                case 8:
                    if (func_800D395C()) {
                        func_808026F0_chboilerboss(param_0);
                        _gcfrontend_entrypoint_10();
                    } else {
                        func_808027E4_chboilerboss(param_0, 0x14, 0x30, 0);
                        func_80101180(0x46D, 7, 0);
                    }
                    return 4;

                case 0x14:
                    func_808026F0_chboilerboss(param_0);
                    func_800FFAB0(param_0);
                    return 4;

                case 0x13:
                    func_808026F0_chboilerboss(param_0);
                    func_808024DC_chboilerboss(param_0);
                    return 4;
            }
            return 3;

        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80802AA0_chboilerboss,
                                         *(f32 *) ((char *) param_0 + 0x38));
            return 1;

        case 0x57:
            return func_80802690_chboilerboss(param_0, param_2 & 0xFFFF,
                                              ((u32) param_2 & 0xFFFF0000) >> 16);

        case 0x95:
            if (*(u8 *) (local_0 + 0x56) != 0) {
                func_800FDC28(1);
                *(u8 *) (local_0 + 0x56) = 0;
            }
            break;

        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }

            func_8080238C_chboilerboss(param_0, 0xCEB, 0x4A);
            return 1;

        case 0x9F:
            func_800FDC28(0);
            func_80800F34_chboilerboss(param_0, 4);
            func_8080221C_chboilerboss(param_0, 0, 0x40A00000);
            *(u8 *) (local_0 + 0x55) = 0;
            break;
        default:
            return 0;
    }

    return 1;
}

void func_80800B94_chboilerboss(Actor *param_0, s32 param_1)
{
    u32 local_0;
    u32 local_1;
    u32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_0 = ((BoilerThresholdFlags_80800B94_chboilerboss *) param_0->unk0)->local_0;
    local_1 = ((BoilerThresholdFlags_80800B94_chboilerboss *) param_0->unk0)->local_1;
    local_2 = ((BoilerThresholdFlags_80800B94_chboilerboss *) param_0->unk0)->local_2;
    func_801015D0(param_0);
    func_808010F4_chboilerboss(param_0);
    func_800DF744(3, local_2 ? (local_0 ? 0 : 1) : 0);
    func_800DF744(4, local_0);
    func_800DF744(5, local_0);
    func_800DF744(6, local_2 ? (local_1 ? 0 : 1) : 0);
    func_800DF744(7, local_1);
    func_800DF744(8, local_1);
    func_800DF744(9, local_2 ? 0 : 1);
    func_800DF744(10, local_2);
    func_800DF744(11, local_2);
    if (((BoilerThresholdFlags_80800B94_chboilerboss *) param_0->unk0)->local_2) {
        local_3 = func_800B2768(param_1);
        local_4 = func_80103CDC(param_0, param_1);
        local_5 = func_800B2840(param_1);
        if (func_800AE0E8(*(s16 *) ((u8 *) param_0->unk0 + 0x10))) {
            _dbmorph_entrypoint_4(local_3, local_4, local_5, 1,
                                  func_800AE080(*(s16 *) ((u8 *) param_0->unk0 + 0x10)));
        }
        func_800DF5D8(*((u8 *) param_0 + 0x98), *((u8 *) param_0 + 0x99), *((u8 *) param_0 + 0x9A),
                      255);
    }
}

void func_80800D50_chboilerboss(param_0, param_1) Actor *param_0;
s32 param_1;
{
    u8 *local_0;
    local_0 = (u8 *) func_80100094(param_0, 0);
    func_80801B88_chboilerboss(param_0, param_1);
    if ((s32) param_0->unk70_10 < 5 || (s32) param_0->unk70_10 >= 11)
        return;
    if (func_800CB854(0) == 7) {
        *(f32 *) (local_0 + 0x5C) = 1.5f;
        func_80109EEC(param_0, 0x40);
    }
    switch (param_0->unk70_10) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            break;
        default:
            if (((BoilerMarkerFlags *) param_0->unk0)->touching)
                func_80800F34_chboilerboss((u8 *) param_0, 6);
            else
                func_800C4AF0(local_0 + 0x3C, func_800DC298(0.5f) ? D_80802B34_chboilerboss
                                                                  : D_80802B40_chboilerboss);
            break;
    }
}

void func_80800E64_chboilerboss(s32 param_0)
{
    func_800D2498(0xC7, *(u8 *) (param_0 + 0x5E), 0);
}

void func_80800E90_chboilerboss(u8 *param_0)
{
    func_80801B88_chboilerboss();
    if (func_800CEAA8(0) != 0) {
        func_800CE88C(0, 0);
    }
    *(s8 *) ((s8 *) func_80100094(param_0, 0) + 0x55) = 0;
    func_8080238C_chboilerboss(param_0, 0xF98, 2);
    func_808027E4_chboilerboss(param_0, 0x1F, 0x430, 0);
    func_80800F34_chboilerboss(param_0, 0xB);
    func_8010A570(param_0);
    *(s8 *) ((s8 *) param_0 + 0x5E) = 0;
    func_80800E64_chboilerboss(param_0);
    func_8080221C_chboilerboss(param_0, 0, 0x40A00000);
}

void func_80802594_chboilerboss();

void func_80801EB4_chboilerboss();

void func_80800F34_chboilerboss(param_0, param_1) u8 *param_0;
s32 param_1;
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    func_80102424(param_0, param_1);
    func_80802594_chboilerboss(param_0);

switch (param_1) {
    case 7:
        func_808027E4_chboilerboss(param_0, 2, 0x30, 0);
        func_8080238C_chboilerboss(param_0, 0xF99, 0x40);
        func_80109FE8(param_0, 0);
        break;
    case 8:
        func_808027E4_chboilerboss(param_0, 4, 0x30, 0);
        func_8080238C_chboilerboss(param_0, 0xF9A, 0x40);
        func_80109FE8(param_0, 0);
        break;
    case 9:
        func_808027E4_chboilerboss(param_0, 6, 0x30, 0);
        func_8080238C_chboilerboss(param_0, 0xF9B, 0x40);
        func_80109FE8(param_0, 0);
        break;
    case 5:
        func_80801EB4_chboilerboss(param_0);
        local_1 = 1;
        break;
    case 10:
        local_1 = 1;
        break;
    case 2:
        func_800187B4(0, 0x3FCCCCCD, 0x3E800000, 0x40000000);
        func_808024B8_chboilerboss(param_0);
        func_808027E4_chboilerboss(param_0, 0, 0x20, 0);
        _chintrotext_entrypoint_1(0x18B9, 0, 1, 0);
        *(s32 *) ((s8 *) local_0 + 0x60) = 1;
        break;
    case 6:
        local_1 = 1;
        break;
    case 12:
        *(u8 *) ((s8 *) param_0 + 0x65) = (u8) (*(u8 *) ((s8 *) param_0 + 0x65) & 0xFFFE);
}

(*(s8 *) ((s8 *) (local_0) + (0x58))) = (s8) local_1;
func_808024DC_chboilerboss(param_0);
}

void func_808010F4_chboilerboss(param_0) Actor *param_0;
{
    u8 *local_5;
    BoilerMorph61 local_6;

if (((Mass45BoilerRenderFlags *) param_0->unk0)->local_0 && param_0->unk64_16) {
    local_5 = func_80100094(param_0, 0);
    local_6.local_4 = func_801039E4(param_0->unk0);
    local_6.local_3 = func_80101F24(param_0);
    switch (param_0->unk70_10) {
        case 2:
            if (local_6.local_3 < 0.15f) {
                *(f32 *) (local_5 + 0x4C) = 6.6666665f * local_6.local_3;
            } else {
                *(f32 *) (local_5 + 0x4C) = 1.0f;
            }
            *(f32 *) (local_5 + 0x50) = *(f32 *) (local_5 + 0x4C);
            break;
        case 6:
            if (local_6.local_3 < 0.5f) {
                *(f32 *) (local_5 + 0x4C) = local_6.local_3 + local_6.local_3;
            } else {
                *(f32 *) (local_5 + 0x4C) = (1.0f - local_6.local_3) + (1.0f - local_6.local_3);
            }
            *(f32 *) (local_5 + 0x50) = *(f32 *) (local_5 + 0x4C);
            break;
        case 7:
        case 8:
        case 9:
            if (local_6.local_3 < 0.15f) {
                *(f32 *) (local_5 + 0x4C) = 6.6666665f * local_6.local_3;
            } else {
                *(f32 *) (local_5 + 0x4C) = 1.0f;
            }
            *(f32 *) (local_5 + 0x50) = *(f32 *) (local_5 + 0x4C);
            break;
        default:
            local_6.local_2 = func_800F0E00(*(f32 *) (local_5 + 0x4C) - 0.2f, 0.0f);
            *(f32 *) (local_5 + 0x4C) = local_6.local_2;
            *(f32 *) (local_5 + 0x50) = local_6.local_2;
    }
    local_6.local_0 = func_800B2768(local_6.local_4);
    local_6.local_1 = func_80103CB8(param_0, local_6.local_4);
    _dbmorph_entrypoint_3(local_6.local_0, local_6.local_1, func_800B2840(local_6.local_4), 1,
                          local_5 + 0x4C);
}

}

void func_808012C8_chboilerboss(Actor *param_0)
{
    if ((s32) param_0->unk70_10 < 11) {
        if ((s32) param_0->unk70_10 >= 5)
            func_80800E64_chboilerboss(param_0);
        if (param_0->unk70_10 != 7 && param_0->unk70_10 != 8 && param_0->unk70_10 != 9) {
            if (param_0->pad5E < (s32) param_0->actorData[5]) {
                param_0->actorData[5] = param_0->pad5E;
                if (((BoilerThresholdFlags_808012C8_chboilerboss *) param_0->unk0)->local_0 &&
                    (s32) param_0->actorData[5] < 41) {
                    func_80800F34_chboilerboss(param_0, 7);
                } else if (((BoilerThresholdFlags_808012C8_chboilerboss *) param_0->unk0)
                               ->local_1 &&
                           (s32) param_0->actorData[5] < 31) {
                    func_80800F34_chboilerboss(param_0, 8);
                } else if (((BoilerThresholdFlags_808012C8_chboilerboss *) param_0->unk0)
                               ->local_2 &&
                           (s32) param_0->actorData[5] < 16) {
                    func_80800F34_chboilerboss(param_0, 9);
                }
            }
        }
    }

}

void func_808013C4_chboilerboss(Actor *param_0)
{
    BoilerWaitState *local_0;
    local_0 = func_80100094(param_0, 0);

if (local_0->phase != 3 && local_0->timer == 0.0f && !func_800C0638()) {
    func_80800F34_chboilerboss((u8 *) param_0, 10);
    if (!local_0->used) {
        func_8080238C_chboilerboss(param_0, 0xF9C, 0);
        local_0->used++;
    }
}

}

void func_80801464_chboilerboss(Actor *param_0, f32 *param_1, f32 param_2)
{
    func_800EE7F8(param_1, (f32 *) ((u8 *) func_80100094(param_0, 0) + 0));
    func_800EF1B8(param_1, func_800136E4(param_0->rotation[1] + 90.0f), 15.0f);
    func_800EF1B8(param_1, param_0->rotation[1], param_2);
    param_1[1] -= 10.0f;
}

void func_808014F4_chboilerboss(Actor *param_0, f32 *param_1, f32 param_2)
{
    func_800EE7F8(param_1, (f32 *) ((u8 *) func_80100094(param_0, 0) + 0xC));
    func_800EF1B8(param_1, func_800136E4(param_0->rotation[1] - 90.0f), 15.0f);
    func_800EF1B8(param_1, param_0->rotation[1], param_2);
    param_1[1] -= 10.0f;
}

void func_80801584_chboilerboss(Actor *param_0, s32 param_1)
{
    Actor *local_0;
    s32 local_1;
    local_0 = func_801084B0(param_1, &param_0);
    local_0->unk3C = param_0->unk0;
    func_80102424(local_0, local_0->unk70_10);
    func_80102FDC(local_0, param_0->scale);
    local_1 = 3 - ((BoilerProgress *) param_0->unk0)->first -
              ((BoilerProgress *) param_0->unk0)->second -
              ((BoilerProgress *) param_0->unk0)->third;
    func_80105A9C(param_0, ((f32 *) &D_80802B4C_chboilerboss)[local_1]);
}

void func_80801A08_chboilerboss();

void func_808019C8_chboilerboss();

void func_80801628_chboilerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;
    f32 local_4[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = ((BoilerThresholdFlags_80801628_chboilerboss *) param_0->unk0)->local_0;
    local_2 = ((BoilerThresholdFlags_80801628_chboilerboss *) param_0->unk0)->local_1;
    local_3 = ((BoilerThresholdFlags_80801628_chboilerboss *) param_0->unk0)->local_2;

if ((s32) param_0->unk70_10 < 11) {
    if (1)
        if (1) {
        }
    if (local_3 && !local_1) {
        if (param_0->unk70_10 == 5) {
            if (func_800DC298(0.5f)) {
                func_80801464_chboilerboss(param_0, local_4, 75.0f);
                func_808019C8_chboilerboss(param_0, local_4);
            }
        } else if (func_800DC298(0.15f)) {
            func_80801464_chboilerboss(param_0, local_4, 75.0f);
            func_808019C8_chboilerboss(param_0, local_4);
        }
    }
    if (local_3 && !local_2) {
        if (param_0->unk70_10 == 5) {
            if (func_800DC298(0.5f)) {
                func_808014F4_chboilerboss(param_0, local_4, 75.0f);
                func_808019C8_chboilerboss(param_0, local_4);
            }
        } else if (func_800DC298(0.15f)) {
            func_808014F4_chboilerboss(param_0, local_4, 75.0f);
            func_808019C8_chboilerboss(param_0, local_4);
        }
    }
    if (!local_3 && param_0->unk70_10 != 9 && func_800DC298(0.4f)) {
        func_800EE7F8(local_4, local_0 + 0x18);
        func_800EF1B8(local_4, param_0->rotation[1], 75.0f);
        func_80801A08_chboilerboss(param_0, local_4);
    }
}

}

void func_80801B00_chboilerboss();

void func_80801A74_chboilerboss();

void func_808017F0_chboilerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);

if (func_80101F24(param_0) < 0.7f && func_800DC298(0.4f)) {
    func_800EE7F8(local_1, param_0->position);
    local_1[1] += 30.0f;
    func_80801B00_chboilerboss(param_0, local_1);
}

if (func_80101E14(param_0, 0.0f)) {
    func_800EE7F8(local_1, param_0->position);
    local_1[1] -= 250.0f;
    func_80801A74_chboilerboss(param_0, param_0->position, local_1, 0);
}

if (func_80101E14(param_0, 0.45f)) {
    func_800EE7F8(local_2, local_0 + 0x24);
    local_2[1] = param_0->position[1];
    func_800EE7F8(local_1, local_2);
    local_1[1] -= 100.0f;
    func_80801A74_chboilerboss(param_0, local_2, local_1, 1);
}

if (func_80101E14(param_0, 0.65f)) {
    func_800EE7F8(local_2, local_0 + 0x30);
    local_2[1] = param_0->position[1];
    func_800EE7F8(local_1, local_2);
    local_1[1] -= 100.0f;
    func_80801A74_chboilerboss(param_0, local_2, local_1, 1);
}

if (func_80101E14(param_0, 0.85f)) {
    func_800EE7F8(local_2, local_0 + 0x30);
    local_2[1] = param_0->position[1] + 25.0f;
    func_80801B44_chboilerboss(param_0, local_2);
}

}

void func_808019C8_chboilerboss(s32 param_0, unsigned int param_1)
{
    func_800BBCB8(param_1, 0, 1.0f, 1, &D_80802ACC_chboilerboss);
}

void func_80801A08_chboilerboss(s32 param_0, s32 param_1)
{
    Actor *local_0;
    local_0 = func_800B53A4(1);
    func_800BABB8(local_0, param_1, 0, 1.0f, &D_80802ACC_chboilerboss);
    func_800BABB8(local_0, param_1, 0, 1.0f, &D_80802D68_chboilerboss);
}

void func_80801A74_chboilerboss(Actor *param_0, f32 *param_1, f32 *param_2, s32 param_3)
{
    s32 local_0;
    local_0 = func_800BABB8(0, param_1, param_2, param_0->scale, D_80802D88_chboilerboss);
    func_800BABB8(local_0, param_1, param_2, param_0->scale,
                  param_3 ? D_80802DA4_chboilerboss : D_80802DB0_chboilerboss);
    func_800BA22C(local_0, 16);
}

void func_80801B00_chboilerboss(Actor *param_0, s32 param_1)
{
    func_800BBCB8(param_1, 0, *(f32 *) ((char *) param_0 + 0x38), 4, &D_80802DBC_chboilerboss);
}

extern u32 D_80802E00_chboilerboss[];
int func_80801B44_chboilerboss(Actor *param_0, s32 param_1)
{
    func_800BBCB8(param_1, 0, *(f32 *) ((char *) param_0 + 0x38), 8, D_80802E00_chboilerboss);
}

void func_80801B88_chboilerboss(param_0, param_1) s32 param_0;
s32 param_1;
{
    f32 sp34[3];
    f32 sp28[3];
    f32 sp20[2];

    func_800EC398(param_1, sp34);
    func_800F18FC(sp34, param_0 + 4, sp20);
    func_800EEBF0(sp28, sp20, 0x42200000);
    func_800EF04C(sp28, sp34);
    func_800BBCB8(sp34, sp28, 0.7f, 6, &D_80802E44_chboilerboss);
    func_800BBCB8(sp34, sp28, 1.0f, 3, &D_80802E6C_chboilerboss);
}

void func_80801C24_chboilerboss(Actor *param_0)
{
    BoilerBossQuickSounds *local_0;

    local_0 = func_80100094(param_0, 0);

if (!_subaddieaudioquick_entrypoint_3(param_0, local_0->local_2, D_80802EA4_chboilerboss, 0.1f)) {
    if (_subaddieaudioquick_entrypoint_3(param_0, local_0->local_0, D_80802B20_chboilerboss,
                                         0.65f) ||
        _subaddieaudioquick_entrypoint_3(param_0, local_0->local_1, D_80802B20_chboilerboss,
                                         0.88f)) {
        func_800E1610(0, 10.0f, 0.9f, param_0->position);
        func_80018820(0, 1.0f, 0.3f);
    }
}

}

void func_80801CE8_chboilerboss(s32 param_0)
{
    s32 local_0;
    local_0 = func_80100094(param_0, 0);

if (_subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x24, (u32 *) D_80802B20_chboilerboss, 0) !=
        0 ||
    _subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x30, (u32 *) D_80802B20_chboilerboss,
                                     0.5f) != 0) {
    func_800E1610(0, 15.0f, 0.6f, param_0 + 4);
    func_80018820(0, 0.5f, 0.2f);
}

}

void func_80802414_chboilerboss();

void func_80801D80_chboilerboss(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    BoilerSpawnWord1506 local_0;

switch (param_1) {
    case 0xF97:
    case 0xF9E:
        func_80802414_chboilerboss(param_0);
        break;
    case 0xF99:
    case 0xF9A:
    case 0xF9B:
        func_80109FE8(param_0, 1);
        func_808026F0_chboilerboss((s32) param_0);
        func_808024DC_chboilerboss(param_0);
        break;
    case 0xF98:
        local_0.local_0 = param_0->position[1] + 200.0f;
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5, *(s32 *) &param_0->position[0],
                                    local_0.local_1, *(s32 *) &param_0->position[2],
                                    *(s32 *) &param_0->rotation[1]);
        _chexploder_entrypoint_5(param_0, 0x795, param_0->position, param_0->rotation[1],
                                 param_0->scale, 3);
        func_800FDC28(0);
        func_80800F34_chboilerboss((u8 *) param_0, 12);
        break;
    case 0xCEB:
        if (param_2 > 0)
            _gcfrontend_entrypoint_11();
        else
            _gcfrontend_entrypoint_10();
}

}

void func_80801EB4_chboilerboss(BoilerS *param_0)
{
    f32 local_1;
    f32 local_0 = func_8010203C(param_0, param_0->f72);
    local_1 = D_80802B58_chboilerboss / func_80105AC4(param_0);
    func_80101CDC(param_0, local_0 * local_1);

}

s32 func_80801F10_chboilerboss(s32 param_0)
{
    if (func_800DA298(0x86) != 0) {
        func_800FFAB0(param_0);
    }

}

void func_80801F44_chboilerboss(Actor *param_0)
{
    Actor *local_0;

if (!param_0->unk64_20) {
    local_0 = func_80106790(param_0->unk3C);
    switch (param_0->unk6C_9) {
        case 0x223:
            ((BoilerMarker1493 *) local_0->unk0)->local_1 = 0;
            ((BoilerMarker1493 *) local_0->unk0)->local_0 =
                (u8) (((BoilerMarker1493 *) local_0->unk0)->local_0 | 1);
            break;
        case 0x224:
            ((BoilerMarker1493 *) local_0->unk0)->local_2 = 0;
            ((BoilerMarker1493 *) local_0->unk0)->local_0 =
                (u8) (((BoilerMarker1493 *) local_0->unk0)->local_0 | 2);
            break;
        case 0x225:
            ((BoilerMarker1493 *) local_0->unk0)->local_3 = 0;
            ((BoilerMarker1493 *) local_0->unk0)->local_0 =
                (u8) (((BoilerMarker1493 *) local_0->unk0)->local_0 | 4);
    }
    param_0->unk64_20 = 1;
}

if (func_80101DDC(param_0))
    _subaddiefade_entrypoint_3(param_0);
func_80802098_chboilerboss(param_0);

}

void func_80802098_chboilerboss(param_0) Actor *param_0;
{
    switch (param_0->unk6C_9) {
        case 0x223:
        case 0x224:
            _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80802EB0_chboilerboss,
                                             &D_80802EC4_chboilerboss);
            break;
        case 0x225:
            _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80802EB0_chboilerboss,
                                             &D_80802ED0_chboilerboss);
    }

}

void func_80802114_chboilerboss(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);

if (func_800D9078(local_0 + 0x5C)) {
    func_80109EF4(param_0, 0x40);
}

func_800D9078(local_0 + 0x48);

switch (local_0[0x55]) {
    case 0:
        if (func_800CEAA8(0)) {
            func_800CE88C(0, 0);
        }
        break;
    case 1:
        func_800CE8D8(0, 150.0f, 150);
        func_800CE88C(0, 1);
        local_0[0x55] = 2;
        break;
    case 2:
        if (func_800CEAD0(0)) {
            local_0[0x55] = 3;
            func_800C4AF0(0, D_80802EE4_chboilerboss);
            func_80800F34_chboilerboss(param_0, 0xA);
            func_8080238C_chboilerboss(param_0, 0xF9D, 0);
        }
}

}

void func_8080221C_chboilerboss(Actor *param_0, s32 param_1, volatile s32 param_2)
{
    Actor *local_0;
    f32 *local_1;
    local_1 = param_0->position;

if (!param_0->unk3C) {
    local_0 = _subaddiefind_entrypoint_0(local_1, 0x321, -1, 0);
    if (!local_0) {
        return;
    }
    param_0->unk3C = local_0->unk0;
}

local_0 = func_80106790(param_0->unk3C);

if (param_1) {
    _chboilerid_entrypoint_6(local_0, param_2);
}

else
{
    _chboilerid_entrypoint_5(local_0);
}
func_800EE7F8((f32 *) local_0->actorData, local_1);
}

void func_808022BC_chboilerboss(u8 *param_0)
{
    s32 *local_0;
    u8 *local_1;

    local_0 = func_80106790(func_80101080());
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x4B);
    func_808027E4_chboilerboss(param_0, 8, 0x30, *local_0);
    local_1 = param_0 + 4;
    _subaddieaudioquick_entrypoint_2(param_0, local_1, &D_80802F60_chboilerboss);
    func_800BABB8(0, local_1, local_1, *(f32 *) (param_0 + 0x38), &D_80802EF8_chboilerboss);

if (func_800D395C() == 0) {
    func_800D1000(0xB, 1, local_1, 1, 0);
}

func_800DA544(0x86);
func_800DA524(0x670);
}

void func_8080238C_chboilerboss(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    param_2 |= 0x104;
    _subaddiedialog_entrypoint_11(param_0->unk0, param_1, param_2, param_0->position, 0x42);
}

s32 func_808023C8_chboilerboss(s32 param_0)
{
    s32 *local_0;

    local_0 = func_80100094(param_0, 0);

if ((local_0[0x18] == 0) && (((s16 *) local_0)[0x32] != 0)) {
    func_80800F34_chboilerboss(param_0, 2);
}

return 0;
}

void func_80802414_chboilerboss(Actor *param_0)
{
    BoilerBossState *local_0;
    local_0 = (BoilerBossState *) func_80100094(param_0, 0);
    func_808026F0_chboilerboss(param_0);
    func_800A51C0();
    func_80800F34_chboilerboss(param_0, 5);
    func_80109FE8(param_0, 1);
    local_0->active = 1;
    local_0->time = (*((f32 *) D_80802B5C_chboilerboss)) * 0.5f;
    local_0->state = 2;
    func_800DA544(0x179);
    _gcfrontend_entrypoint_9(0x24);
    func_8010A590(param_0);
    func_800FDC28(3);
}

void func_808024B8_chboilerboss(s32 arg0)
{
    func_800FDC28(0x1);
}

void func_808024DC_chboilerboss(Actor *param_0)
{
    u8 *flags;
    flags = func_80100094(param_0, 0);

if (flags[0x57] == 0 && flags[0x58] != 0 && flags[0x59] == 0) {
    func_80802538_chboilerboss(param_0);
    flags[0x58] = 0;
}

}

int func_80802538_chboilerboss(param_0)
Actor *param_0;
{
    Actor *new_var;
    new_var = func_80100094(param_0, 0);

if (*(u8 *) ((char *) new_var + 0x57) == 0) {
    func_800F4AF4(func_800F54E4(), 0x14);
    *(u8 *) ((char *) new_var + 0x57) = 1;
}

func_808025DC_chboilerboss(param_0);
}

void func_80802594_chboilerboss(s32 param_0)
{
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    sp1C = temp_v0;

if (*(u8 *) ((s8 *) temp_v0 + 0x57) != 0) {
    func_800F4B20(func_800F54E4());
    *(s8 *) ((s8 *) sp1C + 0x57) = 0;
}

}

void func_808025DC_chboilerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);

if (*(u8 *) (local_0 + 0x57)) {
    if (_plcamera_entrypoint_10(func_800F54E4()) != 20) {
        *(u8 *) (local_0 + 0x57) = 0;
        return;
    }
    func_800EE7F8(local_1, param_0->position);
    local_1[1] += 400.0f;
    _plcamera_entrypoint_9(func_800F54E4(), local_1, 0.0f);
    func_80116088(func_80110014(func_800F5EF8(func_800F54E4())), local_1);
}

}

int func_80802690_chboilerboss(s32 param_0, s32 param_1, s32 param_2)
{
    if (_gcdialogcamera_entrypoint_0(param_1, param_2) != 0) {
        if (*(u8 *) ((s8 *) func_80100094(param_0, 0) + 0x59) != 2) {
            func_80802730_chboilerboss(param_0, 2, 1);
        }
        return 2;
    }

return 1;
}

void func_808026F0_chboilerboss(param_0) s32 param_0;
{
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);

if (*(u8 *) (sp1C + 0x59) != 0) {
    _capod_entrypoint_3(0);
    *(u8 *) (sp1C + 0x59) = 0;
}

}

void func_80802730_chboilerboss(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);

switch (*(u8 *) (local_0 + 0x59)) {
    case 0:
        _capod_entrypoint_2(param_0->unk0, 20, 0);
    case 1:
        _capod_entrypoint_8(1);
        *(u8 *) (local_0 + 0x59) = 2;
        _gcdialogcamera_entrypoint_3(&D_80802AA0_chboilerboss, param_0->scale);
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_5(param_0->rotation);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(param_1, param_2);
}

}

void func_808027E4_chboilerboss(param_0, param_1, param_2, param_3) Actor *param_0;
s32 param_1;
s32 param_2;
Unk80132ED0 *param_3;
{
    BoilerCameraState *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_3 == NULL)
        param_3 = param_0->unk0;

switch (local_0->state) {
    case 0:
        _capod_entrypoint_2(param_0->unk0, 0x14, param_2);
    case 2:
        local_0->state = 1;
    case 1:
        _capod_entrypoint_6(param_3, param_1, param_2);
}

}

extern int func_80105834();
extern void func_80101870();
u8 D_80802AA0_chboilerboss[16] = {0x43, 0xBE, 0x0, 0x0, 0x44, 0x16, 0x0, 0x0,
                                  0x43, 0x48, 0x0, 0x0, 0x43, 0x34, 0x0, 0x0};
u8 D_80802AB0_chboilerboss[28] = {0x0, 0x1D, 0x7, 0x92, 0x0, 0x14, 0x0, 0x22, 0x0, 0x2E,
                                  0x0, 0x40, 0x0, 0x26, 0x0, 0x2B, 0x0, 0x2D, 0x1, 0x90,
                                  0x2, 0x58, 0x0, 0xC,  0x0, 0x4B, 0x0, 0x0};
f32 D_80802ACC_chboilerboss[15] = {2.666768e-39f,  2.021098e-39f,  3.00356e-39f,  -3.576291e-07f,
                                   2.3510747e-38f, 3.122478e-39f,  6.980036e-39f, 9.403978e-38f,
                                   2.86e-43f,      2.295887e-39f,  6.4291e-40f,   1.4e-43f,
                                   0.0f,           1.8367099e-38f, 0.0f};
u8 D_80802B08_chboilerboss[12] = {0x0, 0x13, 0x4, 0xF8, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80802B14_chboilerboss[12] = {0x0, 0x13, 0x4, 0xB5, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80802B20_chboilerboss[20] = {0x0, 0x13, 0x4, 0x17, 0x0, 0x16, 0x36, 0xB0, 0x0, 0xD,
                                  0x0, 0xC0, 0x0, 0xD9, 0x0, 0x2,  0x0,  0x0,  0x0, 0x0};
u8 D_80802B34_chboilerboss[12] = {0x0, 0x13, 0x4, 0xF5, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80802B40_chboilerboss[12] = {0x0, 0x13, 0x4, 0xF6, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
f32 D_80802B4C_chboilerboss = 3e+02f;
static u32 D_80802B4C_chboilerboss_rest[2] = {0x43C80000, 0x43FA0000};
f32 D_80802B58_chboilerboss = 6e+02f;
BoilerPair D_80802B5C_chboilerboss[4] = {14.0f, 16.0f, 12.0f, 14.0f, 1e+01f, 12.0f, 8.0f, 1e+01f};
u8 D_80802B7C_chboilerboss[144] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x3F, 0x80, 0x0,  0x0,  0x0, 0xC5, 0x0, 0x44,
    0x40, 0x93, 0x33, 0x33, 0x0, 0xC5, 0x0, 0x2, 0x3F, 0xD9, 0x99, 0x9A, 0x2, 0xC5, 0x0, 0x2,
    0x3F, 0x99, 0x99, 0x9A, 0x2, 0xC6, 0x0, 0x1, 0x3F, 0x40, 0x0,  0x0,  0x0, 0xC6, 0x0, 0x1,
    0x3F, 0x40, 0x0,  0x0,  0x0, 0xC7, 0x0, 0x2, 0x40, 0x40, 0x0,  0x0,  0x0, 0xC3, 0x0, 0x2,
    0x40, 0x40, 0x0,  0x0,  0x0, 0xC2, 0x0, 0x2, 0x40, 0x40, 0x0,  0x0,  0x0, 0xBF, 0x0, 0x2,
    0x40, 0x40, 0x0,  0x0,  0x0, 0xC4, 0x0, 0x2, 0x3F, 0x99, 0x99, 0x9A, 0x2, 0xC6, 0x0, 0x1,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x3F, 0xC0, 0x0,  0x0,  0x0, 0xC1, 0x0, 0x2, 0x3F, 0xC0, 0x0,  0x0,  0x0, 0xC0, 0x0, 0x2,
    0x3F, 0xCC, 0xCC, 0xCD, 0x0, 0xBE, 0x0, 0x2, 0x3F, 0x99, 0x99, 0x9A, 0x2, 0xC6, 0x0, 0x1};
int D_80802C0C_chboilerboss[18] = {0x70118,
                                   0x6500001,
                                   (u32) &D_80802B7C_chboilerboss,
                                   (u32) func_80102EC0,
                                   (u32) func_80800324_chboilerboss,
                                   (u32) func_801018A4,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x11568,
                                   (u32) func_80800304_chboilerboss,
                                   (u32) func_80108ED0,
                                   0x800000,
                                   (u32) func_80800030_chboilerboss,
                                   (u32) func_80107C2C,
                                   -0x7FFFFBDE,
                                   (u32) func_808008B0_chboilerboss,
                                   0x0};
int D_80802C54_chboilerboss[18] = {0x2B0223,
                                   0x64D000E,
                                   (u32) &D_80802B7C_chboilerboss,
                                   (u32) func_80801F44_chboilerboss,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x40C,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80801F10_chboilerboss,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0};
int D_80802C9C_chboilerboss[18] = {0x2C0224,
                                   0x64C000F,
                                   (u32) &D_80802B7C_chboilerboss,
                                   (u32) func_80801F44_chboilerboss,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x40C,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80801F10_chboilerboss,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0};
int D_80802CE4_chboilerboss[18] = {0x2D0225,
                                   0x64F0010,
                                   (u32) &D_80802B7C_chboilerboss,
                                   (u32) func_80801F44_chboilerboss,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x40C,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80801F10_chboilerboss,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0};
u8 D_80802D2C_chboilerboss[12] = {0x0, 0x13, 0x4, 0xF7, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80802D38_chboilerboss[40] = {0x0, 0x1D, 0x7, 0x92, 0x0,  0x14, 0x0, 0x22, 0x0,  0x2E,
                                  0x0, 0x40, 0x0, 0x26, 0x0,  0x2B, 0x0, 0x2D, 0x1,  0x90,
                                  0x2, 0x58, 0x0, 0xA,  0xFF, 0x6A, 0x0, 0x14, 0xFF, 0x6A,
                                  0x0, 0x96, 0x0, 0x14, 0x0,  0x96, 0x0, 0x0,  0x0,  0x0};
u8 D_80802D60_chboilerboss[8] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x2, 0x0, 0x0};
s32 D_80802D68_chboilerboss[6] = {0x2C0000, 0x320000, 0x64, 0xA, -0x960000, -0x95FF6A};
static u32 D_80802D68_chboilerboss_rest[2] = {0x96, 0x11A0000};
s32 D_80802D88_chboilerboss[7] = {0x1010001D, 0x7920014, 0x22002E, 0x400019,
                                  0x26002D,   0x1900258, 0x0};
s32 D_80802DA4_chboilerboss[3] = {0xB002D, 0x37000A, 0x0};
s32 D_80802DB0_chboilerboss[3] = {0xB0064, 0x820032, 0x1E0000};
u8 D_80802DBC_chboilerboss[68] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0,  0x0,  0x20, 0x96, 0x96, 0x96, 0xB4,
    0x0, 0x2B, 0x1, 0x0,  0x1, 0x33, 0x0, 0x22, 0x0,  0x33, 0x0,  0x4C, 0x1,  0x80,
    0x2, 0x0,  0x0, 0x15, 0x0, 0x0,  0x0, 0xCC, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,
    0x0, 0x2C, 0x0, 0x0,  0x0, 0x32, 0x0, 0x0,  0x0,  0x0,  0x0,  0x64, 0x0,  0x0,
    0x0, 0xB,  0x0, 0xB4, 0x0, 0xB4, 0x0, 0xA,  0xFF, 0xFB, 0x0,  0x0};
u32 D_80802E00_chboilerboss[17] = {0x1D09DD, 0x160200,  0x209696, 0x96B4002B, 0x1000133, 0x220033,
                                   0x4C0180, 0x2000015, 0xCC,     0x190000,   0x7002C,   0x32,
                                   0x0,      0x640000,  0xB0064,  0x64000A,   0xFFFB0000};
int D_80802E44_chboilerboss[10] = {0x1D0792, 0x140005, 0x1E002B, 0x1330180, 0x22002E,
                                   0x400026, 0x2B002D, 0xC80190, 0xE0023,   0x2D0000};
int D_80802E6C_chboilerboss[14] = {0x1D09DD, 0x160200, 0x20B4B4,  -0x4B3FFFD5, 0x1000133,
                                   0x220033, 0x4C0180, 0x2000015, 0xCC,        0x190000,
                                   0x7002D,  0x6400C8, 0xE000A,   0x140000};
u8 D_80802EA4_chboilerboss[12] = {0x0, 0x13, 0x4, 0xF9, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u32 D_80802EB0_chboilerboss[5] = {0x130416, 0x163A98, 0xD00F3, 0x10C0002, 0x0};
void *D_80802EC4_chboilerboss = (void *) 0x3EB33333;
static u32 D_80802EC4_chboilerboss_rest[2] = {0x3F333333, 0xBF800000};
void *D_80802ED0_chboilerboss = (void *) 0x3E99999A;
static u32 D_80802ED0_chboilerboss_rest[4] = {0x3F000000, 0x3F2B851F, 0x3F400000, 0xBF800000};
u8 D_80802EE4_chboilerboss[20] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x15,
                                  0x0, 0x0,  0x3, 0x0,  0x0, 0x33, 0x0,  0x14, 0x0, 0x0};
u8 D_80802EF8_chboilerboss[104] = {
    0x8,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x16, 0x2,  0x0,  0x0,  0x2B, 0x8,  0x0,  0xA,
    0x0,  0x0,  0x22, 0x2,  0x0,  0x2,  0x80, 0x6,  0x0,  0x8,  0x0,  0x0,  0x15, 0x0,  0x0,
    0x0,  0x26, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,  0x2D, 0x0,  0xA0, 0x0,  0xC8, 0x0,
    0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x0,  0xA,  0xFF, 0x38, 0x0,  0x4B, 0xFF, 0x38, 0x0,  0xC8,
    0x0,  0x96, 0x0,  0xC8, 0x8,  0x1A, 0x10, 0x10, 0x0,  0x1D, 0x7,  0x92, 0x0,  0x14, 0x0,
    0x2D, 0x3,  0x84, 0x4,  0x4C, 0x0,  0x22, 0x0,  0x4C, 0x0,  0x66, 0x0,  0x33, 0x0,  0x40,
    0x0,  0x1E, 0x0,  0x14, 0x0,  0x14, 0x0,  0xD,  0x0,  0x4B, 0x10, 0x1A, 0x0,  0x0};
u8 D_80802F60_chboilerboss[16] = {0x0, 0x13, 0x4, 0x13, 0x0, 0x18, 0x0, 0x2,
                                  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
