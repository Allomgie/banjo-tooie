#include "common.h"

typedef struct { f32 start[3]; f32 dir[3]; f32 mid[3]; f32 halfLen; } AthleteLane;
typedef struct { AthleteLane lane[3]; } AthleteLocal;
extern s32 _glcutDll_entrypoint_20();
extern void *func_80100094(Actor *, s32);
extern s32 func_800D0A9C(s32, s32);
extern s32 _gccubesearch_entrypoint_9(s32, s32 *, s32);
extern void _gspropctrl_entrypoint_11(s32, f32 *);
extern s32 func_800DA298(s32);
extern s32 func_800EA090(void);
extern s32 func_800F54E4(void);
extern void func_800F608C(s32, s32);
extern void func_800DA524(s32);
extern void func_800FFA88(Unk80132ED0 *);
extern s32 func_800F00A4(void *, f32, f32, f32, void *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F1CF0(void *, f32 *);
extern void func_800EF334(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct { u8 pad_0[0x78]; void *local_0[7]; f32 local_1[7]; } AthleteSplinePaths;
typedef struct { f32 local_0[12]; } AthleteCurve6;
typedef struct { f32 local_0[10]; } AthleteCurve5;
extern u8 D_80803034_chfantasyathlete[];
extern u8 D_8080315C_chfantasyathlete[];
extern u8 D_8080318C_chfantasyathlete[];
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern void func_80101CDC(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
typedef struct AthleteModels1436 { u8 pad_0[0x78]; s32 models[7]; f32 rotations[7]; } AthleteModels1436;
extern void *func_800D7520(s32);
extern void func_800C7A68(void *, f32, f32 *);
extern void func_801058C4(Actor *, s32, f32, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern s32 func_80102CCC(Actor *);
extern u8 unk18[];
extern int D_808031B4_chfantasyathlete[];
extern f32 func_80105B0C(Actor *, f32);
extern f32 func_800F549C(s32, s32);
extern void func_8010573C(Actor *, f32);
extern void func_800EEB9C(f32[3], f32, f32);
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800C4140(s32, f32 *, s32);
extern void func_800F7ECC(s32, s32, f32);
void func_808015D8_chfantasyathlete();
void func_80801654_chfantasyathlete();
s32 func_80802950_chfantasyathlete();
int func_80802D74_chfantasyathlete();
void func_80800314_chfantasyathlete();
void func_8080094C_chfantasyathlete();
void func_80801974_chfantasyathlete();
s32 func_8080298C_chfantasyathlete(Actor *param_0, void *param_1, f32 *param_2, f32 *param_3, f32 param_4);
extern void func_801018A4(), func_80107C2C(), func_80108ED0(), func_80800060_chfantasyathlete(), func_80800314_chfantasyathlete();
extern u8 D_80803030_chfantasyathlete[];

int func_80800000_chfantasyathlete(s32 param_0, s32 param_1)
{
  if (param_1 != 0)
  {
    if (!func_800DA9E4(0xA51, 1))
    {
      func_800C78CC(1);
    }
  }
  else
  {
    if (func_800DA9E4(0xA51, 0) != 0)
    {
      func_800C78CC(0);
    }
  }
}

void func_80800060_chfantasyathlete(this) Actor *this;
{
    AthleteLocal *local;
    s32 props[2];
    f32 vec[3];

    if (_glcutDll_entrypoint_20(this)) {
        func_8080094C_chfantasyathlete(this, 0x22);
        return;
    }
    local = func_80100094(this, 0);
    if (!func_800D0A9C(0x48, 1)) {
        func_80801654_chfantasyathlete(this, local);
        _gccubesearch_entrypoint_9(0x47B, props, 2);
        _gspropctrl_entrypoint_11(props[0], vec);
        _gspropctrl_entrypoint_11(props[1], local->lane[2].start);
        func_808015D8_chfantasyathlete(vec, local->lane[2].start, local->lane[2].mid, local->lane[2].dir, &local->lane[2].halfLen);
        if (func_800DA298(0x3DD)) {
            if (func_800EA090() != 0x18) {
                func_8080094C_chfantasyathlete(this, 0x16);
            }
        } else {
            _gccubesearch_entrypoint_9(0x47A, props, 2);
            _gspropctrl_entrypoint_11(props[0], local->lane[1].start);
            _gspropctrl_entrypoint_11(props[1], vec);
            func_808015D8_chfantasyathlete(vec, local->lane[1].start, local->lane[1].mid, local->lane[1].dir, &local->lane[1].halfLen);
            if (func_800DA298(0x3DC)) {
                if (func_800EA090() != 0x17) {
                    func_8080094C_chfantasyathlete(this, 8);
                }
            } else {
                _gccubesearch_entrypoint_9(0x478, props, 2);
                _gspropctrl_entrypoint_11(props[1], local->lane[0].start);
                _gspropctrl_entrypoint_11(props[0], vec);
                func_808015D8_chfantasyathlete(vec, local->lane[0].start, local->lane[0].mid, local->lane[0].dir, &local->lane[0].halfLen);
                func_8080094C_chfantasyathlete(this, 1);
            }
        }
        if (func_800EA090() == 0x17) {
            func_800F608C(func_800F54E4(), 3);
            if (func_800DA298(0x6D6)) {
                if (func_800DA298(0x6D7)) {
                    func_8080094C_chfantasyathlete(this, 0xF);
                } else {
                    func_8080094C_chfantasyathlete(this, 0xE);
                }
                func_800DA524(0x6D6);
            } else {
                func_8080094C_chfantasyathlete(this, 0xB);
            }
        } else if (func_800EA090() == 0x18) {
            if (func_800DA298(0x6D6)) {
                if (func_800DA298(0x6D7)) {
                    func_8080094C_chfantasyathlete(this, 0x1D);
                } else {
                    func_8080094C_chfantasyathlete(this, 0x1C);
                }
                func_800DA524(0x6D6);
            } else {
                func_8080094C_chfantasyathlete(this, 0x19);
            }
        }
    } else {
        func_800FFA88(this->unk0);
    }
}





































s32 func_80802730_chfantasyathlete(Actor *param_0, s32 param_1, s32 param_2, s16 param_3, s16 param_4, s32 param_5);

void func_80801718_chfantasyathlete();

s32 func_80801114_chfantasyathlete(s32 param_0, void *param_1, void *param_2, f32 *param_3, f32 param_4, f32 *param_5, f32 *param_6);

void func_80800314_chfantasyathlete(param_0) Actor *param_0;
{
    char *local_0;
    s32 local_2;
    s32 local_3;
    f32 local_4[3];

    local_0 = (char *)func_80100094(param_0, 0);

    switch (param_0->unk70_10) {
        case 1:
            local_2 = 0;

            switch (func_800F5410(func_800F54E4())) {
            case 1:
                local_2 = 0x13E0;
                local_3 = 0x13E1;
                break;
            case 0xA:
                local_2 = 0x1454;
                local_3 = 0x13E1;
                break;
            case 0xB:
                local_2 = 0x1455;
                local_3 = 0x1456;
                break;
            }

            if (local_2 != 0) {
                func_80802730_chfantasyathlete(
                    param_0,
                    0x3D9,
                    0x1F4,
                    (s16)local_2,
                    local_3,
                    0
                );
            }

            if (func_800F6720(func_800F54E4()) != 0) {
                break;
            }

            if (!func_800DA298(0x3D9)) {
                break;
            }

            func_800F5A00(func_800F54E4(), local_4);

            if (func_80801114_chfantasyathlete(
                    param_0,
                    local_0 + 0xC,
                    local_0 + 0x18,
                    (f32 *)local_0,
                    *(f32 *)(local_0 + 0x24),
                    local_4,
                    (char *)param_0 + 0x2C)) {
                func_8080094C_chfantasyathlete(param_0, 2);
            }
            break;

        case 2:
            if (func_800F6C5C(func_800F54E4())) {
                func_8080094C_chfantasyathlete(param_0, 3);
            }
            break;

        case 3:
            if (func_800D90A4(&param_0->unk58)) {
                func_8080094C_chfantasyathlete(param_0, 4);
            }
            break;

        case 4:
            func_80802730_chfantasyathlete(
                param_0,
                0,
                0,
                0x13E2,
                0,
                0
            );
            break;

        case 5:
            if (func_80802950_chfantasyathlete(param_0)) {
                func_8080094C_chfantasyathlete(
                    param_0,
                    (param_0->unk70_10) + 1
                );
            }
            break;

        case 6:
        case 7:
        case 20:
        case 21:
            func_80801718_chfantasyathlete(param_0);
            func_80105834(param_0);

            if (func_80105A5C(param_0)) {
                func_8080094C_chfantasyathlete(
                    param_0,
                    (param_0->unk70_10) + 1
                );
            }
            break;

        case 8:
            if (func_800F64A4(func_800F54E4(), 0x200) &&
                func_800F5C94(func_800F54E4()) == 0xC) {
                if (func_800D90A4(&param_0->unk58)) {
                    func_80802730_chfantasyathlete(param_0, 0, 0x1F4,
                        func_800DA298(0x341) ? 0x1435 : 0x1434, 0, 1);
                }
            } else {
                param_0->unk58 = 2.0f;
                func_80802730_chfantasyathlete(param_0, 0x3DA, 0x1F4, 0x13E3, 0x13E4, 0);
            }
            break;

        case 11:
            param_0->unk54 =
                func_80105B0C(param_0, 0);

            func_80802950_chfantasyathlete(param_0);
            break;

        case 12:
            if (func_8080298C_chfantasyathlete(
                    param_0,
                    local_0 + 0x34,
                    local_0 + 0x40,
                    local_0 + 0x28,
                    *(f32 *)(local_0 + 0x4C))) {
                func_8080094C_chfantasyathlete(param_0, 0xD);
                func_800DA544(0x341);
            }
            break;

        case 14:
            func_80802730_chfantasyathlete(
                param_0,
                0,
                0,
                0x13E7,
                0,
                1
            );
            break;

        case 15:
            func_80802730_chfantasyathlete(
                param_0,
                0,
                0,
                0x13E6,
                0,
                0
            );
            break;

        case 17:
            if (func_80802950_chfantasyathlete(param_0)) {
                func_8080094C_chfantasyathlete(param_0, 0x12);
            }
            break;

        case 18:
            if (!func_8010C9B0(param_0->position, 0x1F4) ||
                func_80016B30(0, 1)) {
                func_8080094C_chfantasyathlete(param_0, 8);
            }
            break;

        case 19:
            if (func_80802950_chfantasyathlete(param_0)) {
                func_8080094C_chfantasyathlete(param_0, 0x14);
            }
            break;

        case 22:
            if (func_800F549C(func_800F54E4(), 3) > 0.0f) {
                func_80802730_chfantasyathlete(
                    param_0,
                    0x448,
                    0x1F4,
                    0x1437,
                    0x1437,
                    1
                );
            } else {
                func_80802730_chfantasyathlete(
                    param_0,
                    0x3DB,
                    0x1F4,
                    0x13E8,
                    0x13E9,
                    1
                );
            }
            break;

        case 25:
            param_0->unk54 =
                func_80105B0C(param_0, 0);

            func_80802950_chfantasyathlete(param_0);
            break;

        case 26:
            if (func_8080298C_chfantasyathlete(
                    param_0,
                    local_0 + 0x5C,
                    local_0 + 0x68,
                    local_0 + 0x50,
                    *(f32 *)(local_0 + 0x74))) {
                func_8080094C_chfantasyathlete(param_0, 0x1B);
            }
            break;

        case 27:
            if (!func_800FCCD4(0x16) &&
                !func_800FCCD4(0x17)) {
                _gcgoto_entrypoint_1(func_800EA05C(), 0x18);
            }
            break;

        case 28:
            func_80802730_chfantasyathlete(
                param_0,
                0,
                0,
                0x13EC,
                0,
                1
            );
            break;

        case 29:
            func_80802730_chfantasyathlete(
                param_0,
                0,
                0,
                0x13EB,
                0,
                0
            );
            break;

        case 31:
            if (func_80802950_chfantasyathlete(param_0)) {
                func_8080094C_chfantasyathlete(param_0, 0x20);
            }
            break;

        case 32:
            if (!func_8010C9B0(param_0->position, 0x1F4) ||
                func_80016B30(0, 1)) {
                func_8080094C_chfantasyathlete(param_0, 0x16);
            }
            break;

        case 33:
            func_80801718_chfantasyathlete(param_0);
            func_80105834(param_0);

            if (func_80105A5C(param_0)) {
                func_80802D38_chfantasyathlete(param_0);
                func_80800000_chfantasyathlete(param_0, 0);
                func_800FFA88(param_0->unk0);
            }
            break;

        case 34:
            if (func_80101DDC(param_0)) {
                func_8080094C_chfantasyathlete(param_0, 0x23);
            }
            break;
    }

    func_8010C908(
        param_0,
        param_0->position
    );

    func_80801974_chfantasyathlete(param_0);
}

void func_80802C94_chfantasyathlete();

void func_80802C18_chfantasyathlete();

void func_808018B8_chfantasyathlete(Actor *param_0, AthleteModels1436 *param_1, s32 param_2, u8 param_3);

void func_8080094C_chfantasyathlete(param_0, param_1) Actor *param_0; s32 param_1;
{
    extern f32 D_80803150_chfantasyathlete[];

    char *local_0;
    f32 local_1;
    f32 local_3[3];
    f32 local_2[3];
    f32 local_4;
    f32 local_5[3];
    f32 local_6[3];

    local_0 = (char *)func_80100094(param_0, 0);

    if (param_0->unk70_10 == 0x16) {
        func_80800000_chfantasyathlete(param_0, 1);
    }

    switch (param_1) {
        case 1:
            *(f32 *)((char *)param_0 + 0x2C) = 1.0f;

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                0,
                0xA
            );

            *(f32 *)((char *)param_0 + 0x30) = 0.0f;
            *(f32 *)((char *)param_0 + 0x24) = 0.0f;
            break;

        case 2:
            func_800FC6B0(0x10);
            break;

        case 3:
            func_800DA544(0x3DC);
            *(f32 *)((char *)param_0 + 0x58) = 0.0f;
            break;

        case 5:
            local_1 = *(f32 *)((char *)param_0 + 0x48);

            func_80802C18_chfantasyathlete(
                param_0,
                *(s32 *)((char *)param_0 + 0),
                0x3B,
                0x2810
            );

            _subaddieDll_entrypoint_4(param_0, 1);
            func_8010573C(param_0, 0.0f);

            *(f32 *)((char *)param_0 + 0x54) =
                *(f32 *)((char *)param_0 + 0x48);

            *(f32 *)((char *)param_0 + 0x48) = local_1;
            break;

        case 6:
            *(f32 *)((char *)param_0 + 0x30) = 750.0f;
            break;

        case 7:
            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                1,
                6
            );

            func_80802C18_chfantasyathlete(
                param_0,
                *(s32 *)((char *)param_0 + 0),
                0x3C,
                0x2810
            );

            *(f32 *)((char *)param_0 + 0x30) = 800.0f;
            *(f32 *)((char *)param_0 + 0x24) = 800.0f;
            break;

        case 8:
            if (param_0->unk70_10 == 7) {
                func_808018B8_chfantasyathlete(
                    param_0,
                    local_0,
                    2,
                    5
                );
            } else {
                func_808018B8_chfantasyathlete(
                    param_0,
                    local_0,
                    2,
                    0xA
                );
            }

            _subaddieDll_entrypoint_4(param_0, 0);

            *(f32 *)((char *)param_0 + 0x30) = 0.0f;
            *(f32 *)((char *)param_0 + 0x24) = 0.0f;
            *(f32 *)((char *)param_0 + 0x58) = 2.0f;

            func_80802D38_chfantasyathlete(param_0);
            break;

        case 9:
            param_0->unk79_4 = 2;

            _subaddiedialog_entrypoint_11(
                *(s32 *)((char *)param_0 + 0),
                0x1412,
                0xF,
                (char *)param_0 + 4,
                0x6B
            );
            break;

        case 10:
            func_80802D38_chfantasyathlete(param_0);
            func_800DA524(0x6D6);
            _gcgoto_entrypoint_1(func_800EA05C(), 0x17);
            break;

        case 11:
            func_800F5A00(func_800F54E4(), local_2);

            func_800EEB9C(
                local_3,
                65.0f,
                200.0f
            );

            func_800EF04C(local_3, local_2);

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                2,
                6
            );

            _subaddiedialog_entrypoint_11(
                *(s32 *)((char *)param_0 + 0),
                0x13E5,
                0xF,
                local_3,
                0x6B
            );

            func_80802C94_chfantasyathlete(param_0, 2, 0);
            _subaddieDll_entrypoint_4(param_0, 1);
            func_800F7B9C(func_800F54E4(), 0x7F);
            break;

        case 12:
            param_0->unk64_20 = 0;
            *(u8 *)((char *)param_0 + 0x65) &= 0xF7;

            *(f32 *)((char *)param_0 + 0x2C) = 1.0f;
            *(f32 *)((char *)param_0 + 0x34) = 1.0f;
            *(f32 *)((char *)param_0 + 0x30) = 1050.0f;

            func_800FDC28(0x13);
            func_80802D38_chfantasyathlete(param_0);
            break;

        case 13:
            func_800DA3B8(
                0x6D7,
                !param_0->unk64_19
            );

            func_800DA544(0x6D6);
            _gcgoto_entrypoint_1(func_800EA05C(), 0x17);
            break;

        case 14:
            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                2,
                0xA
            );

            *(f32 *)((char *)param_0 + 0x48) =
                func_8010CD28(param_0);
            break;

        case 15:
            func_800DA544(0x3DD);

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                2,
                0xA
            );

            *(f32 *)((char *)param_0 + 0x48) =
                func_8010CD28(param_0);
            break;

        case 16:
            _subaddiedialog_entrypoint_11(
                *(s32 *)((char *)param_0 + 0),
                0x1413,
                0xF,
                (char *)param_0 + 4,
                0x6B
            );

            func_800F7B9C(func_800F54E4(), 0x80);
            break;

        case 17:
            *(f32 *)((char *)param_0 + 0x54) =
                *(f32 *)(local_0 + 0x9C);

            func_80802D38_chfantasyathlete(param_0);
            break;

        case 19:
            local_4 = *(f32 *)((char *)param_0 + 0x48);

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                3,
                5
            );

            *(f32 *)((char *)param_0 + 0x54) =
                *(f32 *)((char *)param_0 + 0x48);

            *(f32 *)((char *)param_0 + 0x48) = local_4;

            func_80802C18_chfantasyathlete(
                param_0,
                *(s32 *)((char *)param_0 + 0),
                0x3D,
                0x2811
            );
            break;

        case 20:
            _subaddieDll_entrypoint_4(param_0, 1);

            *(f32 *)((char *)param_0 + 0x24) = 0.0f;
            *(f32 *)((char *)param_0 + 0x30) = 750.0f;
            break;

        case 21:
            func_80802C18_chfantasyathlete(
                param_0,
                *(s32 *)((char *)param_0 + 0),
                0x3E,
                0x2811
            );

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                4,
                6
            );

            *(f32 *)((char *)param_0 + 0x30) = 750.0f;
            *(f32 *)((char *)param_0 + 0x24) = 750.0f;

            func_800F7B9C(func_800F54E4(), 0x80);
            break;

        case 22:
            _subaddieDll_entrypoint_4(param_0, 0);

            if (param_0->unk70_10 == 0x15) {
                func_808018B8_chfantasyathlete(
                    param_0,
                    local_0,
                    5,
                    5
                );
            } else {
                func_808018B8_chfantasyathlete(
                    param_0,
                    local_0,
                    5,
                    0xA
                );
            }

            *(f32 *)((char *)param_0 + 0x30) = 0.0f;
            *(f32 *)((char *)param_0 + 0x24) = 0.0f;

            func_80800000_chfantasyathlete(param_0, 0);
            func_80802D38_chfantasyathlete(param_0);
            break;

        case 23:
            param_0->unk79_4 = 2;

            _subaddiedialog_entrypoint_11(
                *(s32 *)((char *)param_0 + 0),
                0x1414,
                0xF,
                (char *)param_0 + 4,
                0x6B
            );
            break;

        case 24:
            func_80802D38_chfantasyathlete(param_0);
            func_800DA524(0x6D6);
            _gcgoto_entrypoint_1(func_800EA05C(), 0x18);
            break;

        case 25:
            func_800F5A00(func_800F54E4(), local_6);

            func_800EEB9C(
                local_5,
                335.0f,
                200.0f
            );

            func_800EF04C(local_5, local_6);

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                5,
                6
            );

            _subaddiedialog_entrypoint_11(
                *(s32 *)((char *)param_0 + 0),
                0x13EA,
                0xF,
                local_5,
                0x6B
            );
            break;

        case 26:
            func_80802D38_chfantasyathlete(param_0);

            param_0->unk64_20 = 0;
            *(u8 *)((char *)param_0 + 0x65) &= 0xF7;

            *(f32 *)((char *)param_0 + 0x2C) = 1.0f;
            *(f32 *)((char *)param_0 + 0x34) = 1.0f;

            _subaddieDll_entrypoint_4(param_0, 1);

            *(f32 *)((char *)param_0 + 0x24) = 0.0f;
            *(f32 *)((char *)param_0 + 0x30) = 1400.0f;

            func_800FDC28(0x13);
            break;

        case 27:
            func_800DA3B8(
                0x6D7,
                !param_0->unk64_19
            );

            func_800DA544(0x6D6);
            _gcgoto_entrypoint_1(func_800EA05C(), 0x18);
            break;

        case 28:
            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                5,
                0xA
            );

            *(f32 *)((char *)param_0 + 0x48) =
                func_8010CD28(param_0);
            break;

        case 29:
            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                5,
                0xA
            );

            *(f32 *)((char *)param_0 + 0x48) =
                func_8010CD28(param_0);
            break;

        case 30:
            func_800F82D4(func_800F54E4(), 0);

            _subaddiedialog_entrypoint_11(
                *(s32 *)((char *)param_0 + 0),
                0x1415,
                0xF,
                (char *)param_0 + 4,
                0x6B
            );
            break;

        case 31:
            *(f32 *)((char *)param_0 + 0x54) =
                *(f32 *)(local_0 + 0xA8);
            break;

        case 32:
            func_80802D38_chfantasyathlete(param_0);
            break;

        case 33:
            func_800D1000(
                0x48,
                1,
                (char *)param_0 + 4,
                0,
                0
            );

            func_80802C18_chfantasyathlete(
                param_0,
                *(s32 *)((char *)param_0 + 0),
                0x40,
                0x2830
            );

            func_808018B8_chfantasyathlete(
                param_0,
                local_0,
                6,
                5
            );

            _subaddieDll_entrypoint_4(param_0, 1);

            *(f32 *)((char *)param_0 + 0x58) = 1.0f;
            *(f32 *)((char *)param_0 + 0x24) = 0.0f;
            *(f32 *)((char *)param_0 + 0x30) = 700.0f;
            break;

        case 34:
            func_800EE7F8(
                (char *)param_0 + 4,
                D_80803150_chfantasyathlete
            );
            break;
    }

    func_80102424(param_0, param_1);
}

s32 func_80801114_chfantasyathlete(s32 param_0, void *param_1, void *param_2,
                                 f32 *param_3, f32 param_4, f32 *param_5, f32 *param_6)
{
    f32 local_1;
    f32 local_0[3];
    s32 local_2;

    if (func_800F00A4(param_2, param_4, 1000.0f, 0.0f, param_5)) {
        func_800EFB24(local_0, param_5, param_3);
        func_800EF2A0(local_0);
        local_1 = func_800F1CF0(param_1, local_0);
        local_2 = local_1 >= 0.0f && *param_6 <= 0.0f;
        *param_6 = local_1;
        return local_2;
    }
    *param_6 = 1.0f;
    return 0;
}

s32 func_808011E4_chfantasyathlete(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[4];
    s32 local_1;
    u32 local_2;

    switch (param_1) {
    case 0x2E:
        param_0->unk79_4 = 3;
        switch (((s16 *)&param_2)[0]) {
        case 0x13E2:
            func_8080094C_chfantasyathlete(param_0, 5);
            break;
        case 0x1434:
        case 0x1435:
            if (((s16 *)&param_2)[1] == 1) {
                func_8080094C_chfantasyathlete(param_0, 0xA);
            } else {
                func_8080094C_chfantasyathlete(param_0, 9);
            }
            break;
        case 0x1412:
            func_8080094C_chfantasyathlete(param_0, 8);
            break;
        case 0x1411:
            func_8080094C_chfantasyathlete(param_0, 8);
            break;
        case 0x13E5:
            func_8080094C_chfantasyathlete(param_0, 0xC);
            break;
        case 0x13E7:
            if (((s16 *)&param_2)[1] == 1) {
                func_8080094C_chfantasyathlete(param_0, 0xB);
            } else {
                func_8080094C_chfantasyathlete(param_0, 0x10);
            }
            break;
        case 0x1413:
            func_8080094C_chfantasyathlete(param_0, 0x11);
            break;
        case 0x13E6:
            func_800C01A8(0x6B, 0x4000);
            func_8080094C_chfantasyathlete(param_0, 0x13);
            break;
        case 0x13E8:
        case 0x13E9:
        case 0x1437:
            if (((s16 *)&param_2)[1] == 1) {
                func_8080094C_chfantasyathlete(param_0, 0x18);
            } else {
                func_8080094C_chfantasyathlete(param_0, 0x17);
            }
            break;
        case 0x1414:
            func_8080094C_chfantasyathlete(param_0, 0x16);
            break;
        case 0x13EA:
            func_8080094C_chfantasyathlete(param_0, 0x1A);
            break;
        case 0x13EC:
            if (((s16 *)&param_2)[1] == 1) {
                func_8080094C_chfantasyathlete(param_0, 0x19);
            } else {
                func_8080094C_chfantasyathlete(param_0, 0x1E);
            }
            break;
        case 0x1415:
            func_8080094C_chfantasyathlete(param_0, 0x20);
            break;
        case 0x13EB:
            func_8080094C_chfantasyathlete(param_0, 0x21);
            break;
        case 0x13E0:
        case 0x13E1:
        case 0x13E3:
        case 0x13E4:
        case 0x1454:
        case 0x1455:
        case 0x1456:
            func_80802D38_chfantasyathlete(param_0);
            break;
        }
        return 1;
    case 0x52:
        local_0[0] = func_80103EF4(param_0);
        local_0[1] = func_80103EAC(param_0);
        local_0[2] = func_80103EAC(param_0);
        local_0[3] = local_0[0] * 0.25f;
        _gcdialogcamera_entrypoint_3(local_0, param_0->scale);
        return 1;
    case 0x57:
        local_1 = param_2 & 0xFFFF;
        local_2 = (u32)(param_2 & 0xFFFF0000) >> 16;
        if (_gcdialogcamera_entrypoint_0(local_1, local_2)) {
            func_80802C94_chfantasyathlete((u8 *)param_0, local_1, local_2);
            return 2;
        }
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        switch (*(u16 *)(D_80803034_chfantasyathlete + param_0->unk70_10 * 8)) {
        case 0x3F9:
        case 0x3FA:
        case 0x3FD:
        case 0x3FE:
            func_800DF744(3, 0);
            func_800DF744(4, 1);
            break;
        case 0x3FB:
        case 0x3FC:
        case 0x3FF:
        case 0x400:
            func_800DF744(3, 1);
            func_800DF744(4, 2);
            break;
        }
        return 1;
    default:
        return 0;
    }
}

void func_808015D8_chfantasyathlete(param_0, param_1, param_2, param_3, param_4) f32 *param_0; f32 *param_1; f32 *param_2; f32 *param_3; f32 *param_4;
{
    func_800EFB24(param_3, param_0, param_1);
    func_800EF2A0(param_3);
    func_800EE780(param_2, param_1, param_0);
    func_800EF334(param_2, 0.5f);
    *param_4 = func_800EEAD4(param_1, param_0) * 0.5f;
}

void func_80801654_chfantasyathlete(param_0, param_1) Actor *param_0; AthleteSplinePaths *param_1;
{
    void *local_0[10];
    s32 local_4;
    s32 local_2;
    f32 local_1[3];
    s32 local_5;

    local_4 = _gccubesearch_entrypoint_9(0x479, local_0, 10);
    for (local_2 = 0; local_2 < local_4; local_2++) {
            local_5 = _gspropctrl_entrypoint_8(local_0[local_2]) - 0x32;
            _gspropctrl_entrypoint_11(local_0[local_2], local_1);
            param_1->local_1[local_5] = (f32)_gspropctrl_entrypoint_12(local_0[local_2]);
            param_1->local_0[local_5] = (void *)_glsplinefind_entrypoint_3(local_1);
    }
}

void func_80801718_chfantasyathlete(Actor *param_0)
{
    ((f32 *)param_0->actorData)[3] = func_800F15F8(((f32 *)param_0->actorData)[3], ((f32 *)param_0->actorData)[6], 50.0f);
    switch (*(u16 *)(D_80803034_chfantasyathlete + param_0->unk70_10 * 8)) {
        case 0x3FA: {
            AthleteCurve6 local_0 = *(AthleteCurve6 *)D_8080315C_chfantasyathlete;
            func_80101CDC(param_0, func_800F10B4(((f32 *)param_0->actorData)[3], 250.0f, 1000.0f, 1.25f, 0.5f));
            func_80105A9C(param_0, ((f32 *)param_0->actorData)[3] * func_800F3780(func_80101F24(param_0), &local_0, 6));
            break;
        }
        case 0x3FC: {
            AthleteCurve5 local_1 = *(AthleteCurve5 *)D_8080318C_chfantasyathlete;
            func_80101CDC(param_0, func_800F10B4(((f32 *)param_0->actorData)[3], 250.0f, 800.0f, 1.5f, 0.75f));
            func_80105A9C(param_0, ((f32 *)param_0->actorData)[3] * func_800F3780(func_80101F24(param_0), &local_1, 5));
            break;
        }
    }
}

void func_808018B8_chfantasyathlete(Actor *param_0, AthleteModels1436 *param_1, s32 param_2, u8 param_3)
{
    if (param_3 & 2) {
        func_800C7A68(func_800D7520(param_1->models[param_2]), 0.0f, param_0->position);
    }
    func_801058C4(param_0, param_1->models[param_2], 0.0f, (param_3 & 2) ? 0 : 1);
    if (param_3 & 8) {
        param_0->rotation[1] = param_1->rotations[param_2];
    }
}

void func_80801974_chfantasyathlete(param_0) Actor *param_0;
{
    extern u8 D_80803034_chfantasyathlete[];

    switch (*(u16 *)(D_80803034_chfantasyathlete + param_0->unk70_10 * 8)) {
        case 0x3F9:
            if (func_80101E14(param_0, 0.06f) ||
                func_80101E14(param_0, 0.26f) ||
                func_80101E14(param_0, 0.46f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.1f, 1.2f) * 1023.0f) << 21) + 0x1B5E23,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.17f) ||
                func_80101E14(param_0, 0.37f) ||
                func_80101E14(param_0, 0.57f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.1f, 1.2f) * 1023.0f) << 21) + 0x1B5E24,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.7f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x1B5E26,
                    param_0->position,
                    0x04B000FA
                );
            }
            break;

        case 0x3FA:
            if (func_80101E14(param_0, 0.45f) ||
                func_80101E14(param_0, 0.95f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0x1F4404,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.4f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.25f, 1.35f) * 1023.0f) << 21) + 0xBBD8A,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.9f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.25f, 1.35f) * 1023.0f) << 21) + 0x1F58B,
                    param_0->position,
                    0x04B000FA
                );
            }
            break;

        case 0x3FD:
            if (func_80101E14(param_0, 0.05f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x1B5E26,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.42f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.75f, 0.85f) * 1023.0f) << 21) + 0x1B5E1F,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.66f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.75f, 0.85f) * 1023.0f) << 21) + 0x1B5E1F,
                    param_0->position,
                    0x04B000FA
                );
            }
            break;

        case 0x3FE:
            if (func_80101E14(param_0, 0.32f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.55f, 0.65f) * 1023.0f) << 21) + 0x1B5E1E,
                    param_0->position,
                    0x04B000FA
                );
                return;
            }

            if (func_80101E14(param_0, 0.1f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x1B5E25,
                    param_0->position,
                    0x04B000FA
                );
                return;
            }
            break;

        case 0x3FC:
            if (func_80101E14(param_0, 0.1f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.1f, 1.2f) * 1023.0f) << 21) + 0x138E23,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.17f)) {
                func_800C4140(
                    0x7FF38CD5,
                    param_0->position,
                    0x04B000FA
                );
            }

            if (func_80101E14(param_0, 0.7f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.25f, 1.35f) * 1023.0f) << 21) + 0x9C58B,
                    param_0->position,
                    0x04B000FA
                );
            }
            break;

        case 0x3FF:
            if (func_80101E14(param_0, 0.1f) ||
                func_80101E14(param_0, 0.42f) ||
                func_80101E14(param_0, 0.6f)) {
                func_800C4140(
                    0x665B5E1F,
                    param_0->position,
                    0x04B000FA
                );
                return;
            }
            break;

        case 0x400:
            if (func_80101E14(param_0, 0.34f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.55f, 0.65f) * 1023.0f) << 21) + 0x1B5E1E,
                    param_0->position,
                    0x04B000FA
                );
            }
            break;
    }
}

s32 func_80802730_chfantasyathlete(Actor *param_0, s32 param_1, s32 param_2, s16 param_3, s16 param_4, s32 param_5)
{
    s32 local_0;
    s32 local_1;
    f32 *local_2;

    local_0 = (param_5 ? 0x40 : 1) | 0xE;
    switch (param_0->unk79_4) {
    case 0:
        local_1 = param_2 ? func_8010C9B0(param_0->position, param_2) : 1;
        if (local_1 && func_800F6C5C(func_800F54E4())) {
            param_0->unk54 = func_8010CD28(param_0);
            param_0->unk50 = param_0->rotation[1];
            if (param_1) {
                if (func_800DA298(param_1)) {
                    if (func_80016B30(0, 1)) {
                        param_0->unk79_4 = 1;
                        _subaddiedialog_entrypoint_11(param_0->unk0, param_4, local_0, param_0->position, 0x6B);
                        func_80802D74_chfantasyathlete(param_0);
                        return 1;
                    }
                } else {
                    param_0->unk79_4 = 1;
                    local_2 = param_0->position;
                    func_800DA544(param_1);
                    _subaddiedialog_entrypoint_11(param_0->unk0, param_3, local_0, local_2, 0x6B);
                    func_80802D74_chfantasyathlete(param_0);
                    return 1;
                }
            } else {
                param_0->unk79_4 = 1;
                _subaddiedialog_entrypoint_11(param_0->unk0, param_3, local_0, param_0->position, 0x6B);
                func_80802D74_chfantasyathlete(param_0);
                return 1;
            }
        }
        return 0;
    case 1:
        if (func_80802950_chfantasyathlete(param_0)) {
            param_0->unk79_4 = 2;
        }
        return 1;
    case 2:
        return 1;
    case 3:
        param_0->unk54 = param_0->unk50;
        if (func_80802950_chfantasyathlete(param_0)) {
            param_0->unk79_4 = 0;
            return 0;
        }
        return 1;
    default:
        return 0;
    }
}

s32 func_80802950_chfantasyathlete(param_0) Actor *param_0; {
    func_80102BAC(param_0, 0.2f, 0.1f, 10.0f);
    return func_80102CCC(param_0);
}

s32 func_8080298C_chfantasyathlete(Actor *param_0, void *param_1, f32 *param_2, f32 *param_3, f32 param_4)
{
    f32 local_0[3];
    func_80801718_chfantasyathlete(param_0);
    func_80105834(param_0);
    func_800F5A00(func_800F54E4(), local_0);
    if (!param_0->unk64_19) {
        if (local_0[1] < param_2[1] - 150.0f && !func_800F6C5C(func_800F54E4())) {
            func_800F7ECC(func_800F54E4(), 3, 0);
            func_800FDC28(0);
            if (!param_0->unk64_20) {
                func_800FC6B0(0x17);
                param_0->unk64_19 = 1;
            }
            return 1;
        }
        if (func_80801114_chfantasyathlete(param_0, param_1, param_2, param_3, param_4, local_0, (f32 *)((u8 *)param_0 + 0x2C))) {
            func_800FDC28(0);
            func_800FC6B0(0x16);
            param_0->unk64_20 = 1;
        }
    }
    if (!param_0->unk64_20) {
        if (local_0[1] < param_2[1] - 150.0f && !func_800F6C5C(func_800F54E4())) {
            func_800F7ECC(func_800F54E4(), 3, 0);
            func_800FDC28(0);
            func_800FC6B0(0x17);
            param_0->unk64_19 = 1;
            return 1;
        }
        if (func_80801114_chfantasyathlete(param_0, param_1, param_2, param_3, param_4, param_0->position, (f32 *)((u8 *)param_0 + 0x34))) {
            func_800FDC28(0);
            func_800FC6B0(0x17);
            param_0->unk64_19 = 1;
        }
    }
    if (param_0->unk64_20 || param_0->unk64_19) {
        func_800F7ECC(func_800F54E4(), 3, 0);
        *(f32 *)((u8 *)param_0 + 0x24) *= 0.9f;
        if (!func_800FCCD4(0x16) && !func_800FCCD4(0x17)) { return 1; }
        return 0;
    }
    return 0;
}

void func_80802C18_chfantasyathlete(volatile s32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    volatile s32 *local_0;

    local_0 = (volatile s32 *)((char *)param_0 + 0x18);
    switch (*local_0) {
    case 0:
        _capod_entrypoint_2(param_0[0], 0x2B, 0x10);
        
    case 1:
        *local_0 = 2;
        
    case 2:
        _capod_entrypoint_6(param_1, param_2, param_3);
        return;
    }
}

void func_80802C94_chfantasyathlete(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 state;
    state = *(s32 *)((char *)param_0 + 0x18);
    switch (state)
    {
        case 0:
            _capod_entrypoint_2(*(s32 *)((char *)param_0 + 0x0), 0x2B, 0, param_0);
        case 2:
            _capod_entrypoint_8(1);
            *(s32 *)((char *)param_0 + 0x18) = 1;
            param_1 = 2;
            param_2 = 1;
            _gcdialogcamera_entrypoint_6(*(s32 *)((char *)param_0 + 0x0));
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(param_1, param_2);
            return;
    }
}

int func_80802D38_chfantasyathlete(Actor *param_0)
{
  if ((*(s32 *)((char *)(param_0) + 0x18)) != 0)
  {
    _capod_entrypoint_3(0, param_0);
    (*(s32 *)((char *)(param_0) + 0x18)) = 0;
  }
}

int func_80802D74_chfantasyathlete(param_0) Actor *param_0;
{
  if ((*(s32 *)((char *)(param_0) + 0x18)) != 1)
  {
    func_80802C94_chfantasyathlete(param_0, 2, 0);
  }
}

int func_80802DA8_chfantasyathlete(param_0) Actor *param_0;
{
  if (_glcutDll_entrypoint_20())
  {
    func_80800314_chfantasyathlete(param_0);
  }
}

int *chfantasyathlete_entrypoint_0()
{
    return &D_808031B4_chfantasyathlete;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/fantasy/athlete.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_808031B4_chfantasyathlete -> int[] */
u8 D_80803030_chfantasyathlete[4] = { 0x0, 0x0, 0x0, 0x0 };
u8 D_80803034_chfantasyathlete[284] = { 0x0, 0x0, 0x0, 0x0, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0x8C, 0xCC, 0xCD, 0x3, 0xFE, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFA, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFA, 0x0, 0x9, 0x40, 0xC, 0xCC, 0xCD, 0x3, 0xFC, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFB, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFB, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFB, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFB, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFC, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFB, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFF, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x4, 0x0, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFF, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFF, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFF, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFC, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFC, 0x0, 0x9, 0x40, 0xC, 0xCC, 0xCD, 0x3, 0xFA, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xFA, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFD, 0x0, 0x9, 0x40, 0x8C, 0xCC, 0xCD, 0x3, 0xFE, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFD, 0x0, 0x9, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0xFA, 0x0, 0x9, 0x40, 0x26, 0x66, 0x66, 0x3, 0xFD, 0x0, 0x4A, 0x40, 0xB6, 0x66, 0x66, 0x3, 0xF9, 0x0, 0x9 };
f32 D_80803150_chfantasyathlete[3] = { 1.395e+04f, 4045.0f, -1.399e+04f };
u8 D_8080315C_chfantasyathlete[48] = { 0x0, 0x0, 0x0, 0x0, 0x3E, 0xCC, 0xCC, 0xCD, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x80, 0x0, 0x0, 0x3E, 0x99, 0x99, 0x9A, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x3E, 0xCC, 0xCC, 0xCD, 0x3F, 0x33, 0x33, 0x33, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x80, 0x0, 0x0 };
u8 D_8080318C_chfantasyathlete[40] = { 0x3E, 0x23, 0xD7, 0xA, 0x0, 0x0, 0x0, 0x0, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x40, 0x0, 0x0, 0x3E, 0xDC, 0x28, 0xF6, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x33, 0x33, 0x33, 0x3F, 0x40, 0x0, 0x0, 0x3F, 0x23, 0xD7, 0xA, 0x0, 0x0, 0x0, 0x0 };
int D_808031B4_chfantasyathlete[19] = { 0x1580477, 0x89E0001, (u32)&D_80803030_chfantasyathlete, (u32)func_80802DA8_chfantasyathlete, (u32)func_80800314_chfantasyathlete, (u32)func_801018A4, 0xBB80000, 0x3FC00000, 0x0, 0x840100, 0x0, (u32)func_80108ED0, 0xB00000, (u32)func_80800060_chfantasyathlete, (u32)func_80107C2C, -0x7BFFBBFE, (u32)func_808011E4_chfantasyathlete, 0x0, 0x0 };
