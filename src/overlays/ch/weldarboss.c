#include "common.h"

extern void *func_80100094(Actor *, u32);
extern s32 _subaddiefind_entrypoint_9(s32);
extern void func_800F82D4(s32, s32);
extern void func_800F7B9C(s32, s32);
extern Actor *_subaddielink_entrypoint_4(void *);
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EF030(f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_8010CD50(Actor *, s32);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _chbaddiesetup_entrypoint_5(s32, s32, s32, s32, s32, s32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void *D_808047C4_chweldarboss;
extern s32 D_8080480C_chweldarboss[];
extern void _plcamera_entrypoint_8();
extern void _subaddielink_entrypoint_0();
extern void func_800F608C();
extern void func_800FFAB0();
extern void func_80102424();
extern void func_80108B04();
extern void func_80109EEC();
extern u8 unkB1[];
extern u8 unkB0[];
extern s32 func_800D731C(s32);
extern void func_800DBE60(u8, s32, void *);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_8010D09C(s32, void *, f32);
extern u8 D_808049B4_chweldarboss[];
extern u8 D_808049DC_chweldarboss[];
extern f32 func_800DC178(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern u8 D_808049EC_chweldarboss[];
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_808049FC_chweldarboss[];
extern u8 D_80804A10_chweldarboss[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, s32 *, s32);
extern s32 D_80804A4C_chweldarboss[];
extern s32 D_80804A64_chweldarboss[];
extern s32 D_80804A7C_chweldarboss[];
extern s32 func_8010D490(f32 *, f32 *, f32, f32, s32);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern s32 func_800F6478();
extern s32 func_800F6590();
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F5D9C(s32, f32 *);
extern void func_800F8418(s32, f32 *);
extern u8 D_80804A94_chweldarboss[];
extern f32 func_800F5BF0(s32, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
typedef struct { u8 pad_0[0x44]; f32 local_0[3]; u8 pad_1[0x10]; u8 local_1; u8 pad_2[0x15]; s16 local_2; } WeldarPlayerEvent;
extern u8 D_80804AA4_chweldarboss[];
typedef struct { u8 pad_0[0x64]; u8 enabled; u8 pad_1[0x13]; s16 player; } WeldarCameraState1425;
extern s32 func_80110014(s32);
extern void _plcamera_entrypoint_9(s32, f32 *, f32);
extern u8 D_80804AB4_chweldarboss[];
extern void func_800D2498(int, int, int);
extern void _mlwave_entrypoint_0(void *param_0, f32 param_1, f32 param_2);
extern void _mlwave_entrypoint_7(void *param_0, f32 param_1);
extern void func_800BF744(s32 param_0, s32 param_1);
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern s32 _mlwave_entrypoint_8(void *, f32);
extern void _chweldarboss_entrypoint_2(void);
extern f32 func_800F5628(void *);
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct { u8 pad_0[0x30]; u8 local_0[0x50]; f32 local_1; s32 local_2; } WeldarLinkedPhase;
extern f32 func_800F13C4(f32, f32);
extern void _capod_entrypoint_14(void);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
typedef struct { u8 pad0[0x1A]; u16 unk1A_5:11; u16 pad1A_0:5; u8 pad1C[8]; u32 unk24_22:10; u32 pad24_0:22; } WeldarMsgObj;
typedef struct { u8 pad0[0x30]; u8 unk30[0x31]; u8 unk61; u8 pad62[4]; u8 unk66; u8 pad67; u8 unk68[8]; } WeldarData;
typedef struct { f32 v[3]; } WeldarVec;
typedef union { s32 i; void *p; struct { s16 a; s16 b; } h; } WeldarArg;
extern WeldarVec D_808048EC_chweldarboss;
extern void func_800F79DC(s32, s32, Unk80132ED0 *);
extern s32 _sueggmisc_entrypoint_0(void *);
extern void func_8010114C(void *, s32, s32);
extern s32 func_80101080(void);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern void _chexploder_entrypoint_13(Actor *, s32);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chexploder_entrypoint_8(Actor *, f32, f32);
extern void _chexploder_entrypoint_9(Actor *, s32, s32);
extern void func_80101010(f32 *);
extern void func_800F18FC(f32 *, WeldarVec *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void _subaddielink_entrypoint_3();
extern void func_800FDC28(s32);
extern s32 func_800D395C(void);
extern u8 D_808048F8_chweldarboss[];
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern u8 D_80804908_chweldarboss[];
extern s32 func_80102320(Actor *, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, void *, s32);
extern void func_800C31DC(s32, f32);
extern u8 D_80804918_chweldarboss[];
extern u8 D_80804928_chweldarboss[];
extern u8 D_80804970_chweldarboss[];
extern u8 D_80804980_chweldarboss[];
extern u8 D_80804990_chweldarboss[];
extern u8 D_808049A4_chweldarboss[];
extern void *func_800E1540(s32);
extern void func_800E13F0(void *, f32);
extern void func_800E1410(void *, f32, f32);
extern void func_800187B4(s32, f32, f32, f32);
typedef struct { u8 pad_0[0x65]; u8 active; u8 pad_1[0x12]; s16 id; } WeldarContactState;
typedef struct { u8 pad0[0xA4]; f32 unkA4; } WeldarLocal;
extern s32 func_800F6438(s32);
extern s32 func_800F6AA4(s32);
extern void func_800F796C(s32, s32);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
typedef struct { u8 pad_0[8]; f32 local_0; s32 local_1; } WeldarLightState;
extern u8 D_80804AC8_chweldarboss[];
extern u8 D_80804ABC_chweldarboss[];
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800C8E54(s32, f32, f32);
extern void func_800DF500(f32, f32, f32);
int func_80802214_chweldarboss();
void func_80802F14_chweldarboss();
void func_80803080_chweldarboss();
s32 func_80803184_chweldarboss();
void func_808034A0_chweldarboss();
void func_80803CF0_chweldarboss();
void func_808041C4_chweldarboss();
void func_80801AA0_chweldarboss();
void func_808023F8_chweldarboss();
void func_8080247C_chweldarboss();
void func_808026BC_chweldarboss();
void func_80803528_chweldarboss();
s32 func_808038F8_chweldarboss();
s32 func_80803DD8_chweldarboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800018_chweldarboss(), func_808002BC_chweldarboss(), func_8080030C_chweldarboss(), func_80801944_chweldarboss();
extern u8 D_808045F0_chweldarboss[];

void * chweldarboss_entrypoint_0();
s32 chweldarboss_entrypoint_1(void);
s32 func_808014CC_chweldarboss(Actor *param_0, s32 param_1, WeldarArg param_2);
void func_80801F30_chweldarboss();
int func_80802100_chweldarboss(Actor *param_0, s32 param_1);
void func_8080227C_chweldarboss(Actor *param_0, s32 param_1);
void func_808023BC_chweldarboss(Actor *unused, s32 param_1);
void func_808029D8_chweldarboss(Actor *param_0);
void func_80802ABC_chweldarboss(Actor *param_0, f32 param_1);
void func_80802B1C_chweldarboss(Actor *param_0);
f32 func_80802C9C_chweldarboss(Actor *param_0, s32 param_1);
void func_80802D2C_chweldarboss(Actor *param_0, s32 param_1, s32 param_2);
void func_80802E80_chweldarboss();
void func_80802FE4_chweldarboss(Actor *param_0, s32 param_1);
void func_808032A8_chweldarboss(Actor *param_0);
f32 func_80803378_chweldarboss(Actor *param_0);
int func_808033D8_chweldarboss(s32 param_0);
s32 func_8080340C_chweldarboss(Actor *this);
void func_80803460_chweldarboss(s32 param_0);
void func_808035D0_chweldarboss(s32 param_0);
void func_80803624_chweldarboss(u8 *param_0);
void func_8080367C_chweldarboss(void *param_0);
void func_808036C8_chweldarboss(s32 param_0);
void func_8080373C_chweldarboss(s32 param_0);
void func_80803770_chweldarboss(Actor *param_0);
s32 func_80803B48_chweldarboss(void *param_0);
void chweldarboss_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4);
void func_80803C18_chweldarboss(Actor *param_0);
void func_80803D64_chweldarboss();
s32 func_80803D98_chweldarboss(s32 param_0);
void func_80803E50_chweldarboss(Actor *param_0);
void func_80803EA4_chweldarboss(Actor *param_0);
s32 func_808040F4_chweldarboss(s32 param_0, s32 param_1, s32 param_2);
void func_8080412C_chweldarboss(Actor *param_0, s32 param_1);
void func_80804230_chweldarboss();
void *chweldarboss_entrypoint_0()
{
    return &D_808047C4_chweldarboss;
}

s32 chweldarboss_entrypoint_1(void)
{
    return (s32)&D_8080480C_chweldarboss;
}

void func_80800018_chweldarboss(param_0) Actor *param_0;
{
    u8 *local_4;
    s32 local_0;
    s32 local_5;

    local_4 = func_80100094(param_0, 0);
    if (_glcutDll_entrypoint_19(0x8A)) {
        func_800FFAB0(param_0);
        return;
    }
    if (!_glcutDll_entrypoint_20()) {
        if (func_800DA298(0x18C)) {
            _chintrotext_entrypoint_2(1);
            func_800FFAB0(param_0);
            return;
        }
        if (func_800DA298(0x174)) {
            s32 local_1;
            local_1 = func_800F54E4();
            if (func_800F6438(local_1) && !func_800F64A4(local_1, 1)) {
                func_800FFAB0(param_0);
                return;
            }
        }
    }
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x32, local_4, 1);
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x33, (f32 *)(local_4 + 0x18), 1);
    param_0->rotation[1] = func_80102D78(param_0, (f32 *)local_4);
    func_800EE7F8((f32 *)(local_4 + 0x38), param_0->position);
    _subaddielink_entrypoint_0(local_4 + 0x30);
    func_80108B04(param_0, 0);
    func_80109EEC(param_0, 0x40);
    *(s16 *)(local_4 + 0xAC) = 1;
    func_800BF744(3, 0);
    for (local_5 = 0; local_5 < 6; local_5++) {
        local_4[0x68 + local_5] = 1;
    }
    local_4[0x6F] = 6;
    *(s16 *)(local_4 + 0x76) = -1;
    *(s16 *)(local_4 + 0x78) = -1;
    *(f32 *)(local_4 + 0xB4) = 0.25f;
    local_0 = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(param_0->position, (f32 *)local_4);
        func_80102424(param_0, 0x33);
        ((u8 *)param_0)[0x7B] = (((u8 *)param_0)[0x7B] & ~0xC0) | 0x40;
    } else if (func_800DA298(0x174)) {
        func_800EE7F8(param_0->position, (f32 *)local_4);
        func_800F608C(local_0, 1);
        func_800F8294(local_0, (f32 *)(local_4 + 0x18));
        func_800F497C(local_0);
        _plcamera_entrypoint_8(local_0);
        func_80801AA0_chweldarboss(param_0, 6);
        func_80802214_chweldarboss(param_0, 0x1356, 15);
        func_80803CF0_chweldarboss(param_0, 0x11, 0x30);
        local_4[0x61] = 1;
        ((u8 *)param_0)[0x7B] = (((u8 *)param_0)[0x7B] & ~0xC0) | 0x40;
    } else if (func_800D395C()) {
        func_80801AA0_chweldarboss(param_0, 2);
    } else {
        _chintrotext_entrypoint_2(1);
        param_0->unk64_16 = 0;
    }
}

void func_808002BC_chweldarboss(param_0) s32 param_0;
{
    Actor *local_0;
    local_0 = func_80100094(param_0, 0);
    (*(u8 *)((char *)(local_0) + 0xB0)) = _subaddieaudioloop_entrypoint_3((*(u8 *)((char *)(local_0) + 0xB0)));
    (*(u8 *)((char *)(local_0) + 0xB1)) = _subaddieaudioloop_entrypoint_3((*(u8 *)((char *)(local_0) + 0xB1)));
    (*(u8 *)((char *)(local_0) + 0xB2)) = _subaddieaudioloop_entrypoint_3((*(u8 *)((char *)(local_0) + 0xB2)));
}

void func_8080030C_chweldarboss(param_0) Actor *param_0;
{
    extern u8 B_80804AE0_chweldarboss[];
    extern u8 D_808047B8_chweldarboss[];
    extern u8 D_80804854_chweldarboss[];
    extern u8 D_80804864_chweldarboss[];
    extern u8 D_80804874_chweldarboss[];
    extern u8 D_80804880_chweldarboss[];
    extern u8 D_808048B4_chweldarboss[];
    extern void _chbaddiesetup_entrypoint_10(void);

    u8 *local_0;
    s32 local_1;
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;

    *(s16 *)(local_0 + 0x78) =
        func_80803D98_chweldarboss(param_0);

    func_8080367C_chweldarboss(param_0);

    func_800F5A00( *(s16 *)(local_0 + 0x78), local_2 );

    switch (param_0->unk70_10) {
        case 1:
            if (func_8010CA74(param_0->position, 0x1B58)) {
                if (func_80803B48_chweldarboss(func_800F54E4())) {
                    if (func_800F64A4(func_800F54E4(), 1)) {
                        func_80801AA0_chweldarboss(param_0, 2);
                    }
                }
            }
            break;

        case 2:
            if (*(u8 *)(local_0 + 0x70) == 0) {
                *(u8 *)(local_0 + 0x70) = 1;
                func_80101180(0x431, 8, 0);
            }
            break;

        case 3:
        {
            f32 local_3;
            local_3 = func_80802C9C_chweldarboss(param_0, 0) * 500.0f;
            func_800EF1B8(param_0->position, param_0->rotation[1], func_800D8FF8() * local_3);
            if (func_800D9078(local_0 + 0xB4)) {
                func_80802214_chweldarboss(param_0, 0x1366, 0x44);
            }
            if (func_800F0064(param_0->position, 200.0f, (f32 *)local_0)) {
                func_80801AA0_chweldarboss(param_0, 4);
            }
            break;
        }

        case 4:
            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 5 );
            }
            break;

        case 5:
            if (!func_800DA298(0x6AD)) {
                func_80802214_chweldarboss( param_0, 0x1355, 6 );

                func_80801AA0_chweldarboss( param_0, 6 );
            }
            break;

        case 7:
        {
            s32 local_4;
            f32 local_5;
            f32 local_6;
            f32 local_7;

            local_4 = func_800F0064( param_0->position, 200.0f, B_80804AE0_chweldarboss );

            func_80802F14_chweldarboss( param_0, 0 );

            if (local_4 == 0) {
                local_5 = func_800D8FF8();

                local_6 =
                    func_80802C9C_chweldarboss( param_0, 1 ) * 700.0f;

                local_7 =
                    func_80802C9C_chweldarboss( param_0, 2 ) * 100.0f;

                param_0->unk54 =
                    func_80102D78( param_0, B_80804AE0_chweldarboss );

                func_80102B2C( param_0, local_7 * local_5 );

                func_800EF1B8( param_0->position, param_0->rotation[1], local_6 * local_5 );
            } else if (func_80101E14( param_0, 0.999f)) {
                func_80801AA0_chweldarboss( param_0, 8 );

                *(u8 *)(local_0 + 0x63) =
                    func_808033D8_chweldarboss( param_0 );
            }
            break;
        }

        case 8:
        {
            f32 local_8;
            f32 local_9;

            local_8 = func_800D8FF8();

            local_9 =
                func_80802C9C_chweldarboss( param_0, 2 ) * 100.0f;

            param_0->unk54 =
                func_8010CD50( param_0, *(s16 *)(local_0 + 0x78) );

            func_80102B2C( param_0, local_9 * local_8 );

            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80102CF4(param_0, 10.0f) && func_80101E14(param_0, 0.999f)) {
                func_80801AA0_chweldarboss( param_0, 9 );
            }
            break;
        }

        case 9:
            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80101E14(param_0, 0.3f)) {
                func_80108B04(param_0, 1);
            }

            if (func_80101DDC(param_0)) {
                (*(u8 *)(local_0 + 0x63))--;

                if (*(u8 *)(local_0 + 0x63) == 0) {
                    func_80801AA0_chweldarboss( param_0, 0xA );
                } else {
                    func_80801AA0_chweldarboss( param_0, 8 );
                }
            }
            break;

        case 10:
            func_80802E80_chweldarboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0xB );
            }
            break;

        case 11:
            func_80802D2C_chweldarboss( param_0, 0x10, 0xC );
            break;

        case 12:
            func_80802FE4_chweldarboss( param_0, 0xD );
            break;

        case 13:
            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 8 );

                *(u8 *)(local_0 + 0x63) =
                    func_808033D8_chweldarboss( param_0 );
            }
            break;

        case 14:
            if (func_80101DDC(param_0)) {
                if (*(u8 *)(local_0 + 0x7C) == 0) {
                    *(u8 *)(local_0 + 0x7C) = 1;

                    func_80803CF0_chweldarboss( param_0, 0x22, 0x30 );

                    func_80802214_chweldarboss( param_0, 0x1359, 6 );

                    func_80801AA0_chweldarboss( param_0, 0xF );
                } else {
                    func_80803D64_chweldarboss( param_0 );

                    func_80801AA0_chweldarboss( param_0, 0x12 );

                    *(u8 *)(local_0 + 0x63) = 3;
                }
            }
            break;

        case 16:
            func_808032A8_chweldarboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x11 );
            }
            break;

        case 17:
            if (func_800D9078( &param_0->unk58)) {
                func_800F82D4( *(s16 *)(local_0 + 0x76), 0 );

                func_80803D64_chweldarboss( param_0 );

                func_80801AA0_chweldarboss( param_0, 8 );

                *(u8 *)(local_0 + 0x63) =
                    func_808033D8_chweldarboss( param_0 );

                *(s16 *)(local_0 + 0x76) = -1;
            }
            break;

        case 18:
        {
            f32 local_10;
            f32 local_11;

            local_10 = func_800D8FF8();

            local_11 =
                func_80802C9C_chweldarboss( param_0, 2 ) * 100.0f;

            param_0->unk54 =
                func_8010CD50( param_0, *(s16 *)(local_0 + 0x78) );

            func_80102B2C( param_0, local_11 * local_10 );

            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80102CF4(param_0, 10.0f) && func_80101E14(param_0, 0.999f)) {
                func_80801AA0_chweldarboss( param_0, 0x13 );
            }
            break;
        }

        case 19:
            if (func_80101E14(param_0, 0.3f)) {
                _subaddieaudioquick_entrypoint_2( param_0, local_0 + 0x44, D_80804854_chweldarboss );

                func_80108B04(param_0, 2);

                (*(u8 *)(local_0 + 0x63))--;
            }

            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80101DDC(param_0)) {
                if (*(u8 *)(local_0 + 0x63) == 0) {
                    func_80801AA0_chweldarboss( param_0, 0x14 );
                } else {
                    func_80801AA0_chweldarboss( param_0, 0x12 );
                }
            }
            break;

        case 20:
        {
            s32 local_12;
            local_12 = _subaddiefind_entrypoint_9(0x43E) +
                       _subaddiefind_entrypoint_9(0x43F) +
                       _subaddiefind_entrypoint_9(0x440);
            func_80802F14_chweldarboss(param_0, 0);
            if (local_12 == 0) {
                func_80801AA0_chweldarboss(param_0, 0x15);
            }
            break;
        }

        case 21:
            func_80802E80_chweldarboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x16 );
            }
            break;

        case 22:
            func_80802D2C_chweldarboss( param_0, 0x1A, 0x17 );
            break;

        case 23:
            func_80802FE4_chweldarboss( param_0, 0x18 );
            break;

        case 24:
            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x12 );

                *(u8 *)(local_0 + 0x63) = 3;
            }
            break;

        case 25:
            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x1C );
            }
            break;

        case 26:
            func_808032A8_chweldarboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x1B );
            }
            break;

        case 27:
            if (func_800D9078( &param_0->unk58)) {
                func_800F82D4( *(s16 *)(local_0 + 0x76), 0 );

                func_80803D64_chweldarboss( param_0 );

                func_80801AA0_chweldarboss( param_0, 0x12 );

                *(u8 *)(local_0 + 0x63) = 3;
                *(s16 *)(local_0 + 0x76) = -1;
            }
            break;

        case 28:
            func_80802F14_chweldarboss( param_0, 0 );

            _subaddieaudioquick_entrypoint_3( param_0, param_0->position, D_808047B8_chweldarboss, 0.15f );

            if (func_80101E14(param_0, 0.85f)) {
                func_80801AA0_chweldarboss( param_0, 0x1D );

                *(f32 *)(local_0 + 0x5C) = 3000.0f;
            }
            break;

        case 29:
        {
            f32 local_13;
            *(f32 *)(local_0 + 0x5C) -= func_800D8FF8() * 1000.0f;
            param_0->position[1] += func_800D8FF8() * *(f32 *)(local_0 + 0x5C);
            if (*(s16 *)(local_0 + 0x74) == 0 && param_0->position[1] > 2750.0f) {
                if (func_800EF030(local_2) > 360000.0f) {
                    local_13 = func_800F1DF4(local_2, (f32 *)B_80804AE0_chweldarboss);
                    param_0->position[0] = local_2[0];
                    param_0->position[2] = local_2[2];
                    func_800EF1B8(param_0->position, local_13, 600.0f);
                }
                *(s16 *)(local_0 + 0x74) = 1;
                func_80803D64_chweldarboss(param_0);
            }
            if (*(s16 *)(local_0 + 0x74) != 0) {
                if (func_800EFC7C(local_2, param_0->position) > 2500.0f) {
                    func_800EF1B8(param_0->position, func_80102D78(param_0, local_2), func_800D8FF8() * 600.0f);
                }
            }
            if (*(f32 *)(local_0 + 0x5C) < 0.0f) {
                func_80801AA0_chweldarboss(param_0, 0x1E);
                func_8010A570(param_0);
            }
            break;
        }

        case 30:
            *(f32 *)(local_0 + 0x5C) -=
                func_800D8FF8() * 1000.0f;

            param_0->position[1] +=
                func_800D8FF8() *
                *(f32 *)(local_0 + 0x5C);

            if (param_0->position[1] > 1500.0f) {
                if (func_800EFC7C( local_2, param_0->position) > 2500.0f) {
                    func_800EF1B8(param_0->position, func_80102D78(param_0, local_2), func_800D8FF8() * 600.0f);
                }
            }

            func_80803528_chweldarboss( param_0, local_2 );

            if (param_0->position[1] < 0.0f) {
                param_0->position[1] = 0;

                func_80802B1C_chweldarboss( param_0 );

                func_808035D0_chweldarboss( param_0 );

                func_80801AA0_chweldarboss( param_0, 0x1F );

                func_8010A590(param_0);
            }
            break;

        case 31:
            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x20 );

                param_0->unk58 =
                    10.0f;
            }
            break;

        case 32:
        {
            f32 local_14;
            f32 local_15;
            f32 local_16;

            local_14 = func_800D8FF8();

            local_15 =
                func_80802C9C_chweldarboss( param_0, 1 ) * 1400.0f;

            local_16 =
                func_80802C9C_chweldarboss( param_0, 2 ) * 160.0f;

            param_0->unk54 =
                func_8010CD50( param_0, *(s16 *)(local_0 + 0x78) );

            func_80102B2C( param_0, local_16 * local_14 );

            func_800EF1B8( param_0->position, param_0->rotation[1], local_15 * local_14 );

            param_0->position[0] =
                func_800F0D50( param_0->position[0], -2000.0f, 2000.0f );

            param_0->position[2] =
                func_800F0D50( param_0->position[2], -2000.0f, 2000.0f );

            local_1 = 1;

            func_80802F14_chweldarboss( param_0, 0 );

            if (func_800D90A4( &param_0->unk58)) {
                func_80801AA0_chweldarboss( param_0, 0x21 );
            }
            break;
        }

        case 33:
            _subaddieaudioquick_entrypoint_3( param_0, param_0->position, D_808047B8_chweldarboss, 0.15f );

            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80101E14(param_0, 0.85f)) {
                func_80801AA0_chweldarboss( param_0, 0x22 );

                *(f32 *)(local_0 + 0x5C) = 3000.0f;
            }
            break;

        case 34:
            *(f32 *)(local_0 + 0x5C) -=
                func_800D8FF8() * 1000.0f;

            param_0->position[1] +=
                func_800D8FF8() *
                *(f32 *)(local_0 + 0x5C);

            if (func_800EFC7C( B_80804AE0_chweldarboss, param_0->position) > 2500.0f) {
                func_800EF1B8(param_0->position, func_80102D78(param_0, B_80804AE0_chweldarboss), func_800D8FF8() * 600.0f);
            }

            if (*(f32 *)(local_0 + 0x5C) < 0.0f) {
                func_80801AA0_chweldarboss( param_0, 0x23 );

                func_8010A570(param_0);
            }
            break;

        case 35:
            *(f32 *)(local_0 + 0x5C) -=
                func_800D8FF8() * 1000.0f;

            param_0->position[1] +=
                func_800D8FF8() *
                *(f32 *)(local_0 + 0x5C);

            if (*(s16 *)(local_0 + 0x74) == 0 && param_0->position[1] < 3000.0f) {
                _subaddieaudioquick_entrypoint_2( param_0, local_0 + 0x44, D_80804864_chweldarboss );

                *(s16 *)(local_0 + 0x74) = 1;

                func_80803CF0_chweldarboss( param_0, 0x3C, 0x30 );
            }

            if (param_0->position[1] > 1500.0f) {
                if (func_800EFC7C( B_80804AE0_chweldarboss, param_0->position) > 2500.0f) {
                    func_800EF1B8(param_0->position, func_80102D78(param_0, B_80804AE0_chweldarboss), func_800D8FF8() * 600.0f);
                }
            }

            func_80803528_chweldarboss( param_0, local_2 );

            if (param_0->position[1] < 0.0f) {
                param_0->position[1] = 0;

                func_80802B1C_chweldarboss( param_0 );

                func_808035D0_chweldarboss( param_0 );

                func_80801AA0_chweldarboss( param_0, 0x24 );

                func_8010A590(param_0);
            }
            break;

        case 36:
            if (func_80101DDC(param_0)) {
                func_80803D64_chweldarboss( param_0 );

                func_80801AA0_chweldarboss( param_0, 0x25 );
            }
            break;

        case 37:
            func_80802E80_chweldarboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x26 );
            }
            break;

        case 38:
            func_80802D2C_chweldarboss( param_0, 0x2A, 0x27 );
            break;

        case 39:
            func_80802FE4_chweldarboss( param_0, 0x28 );
            break;

        case 40:
            func_80802F14_chweldarboss( param_0, 0 );

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x1C );
            }
            break;

        case 41:
            if (func_80101DDC(param_0)) {
                if (*(u8 *)(local_0 + 0x62) == 0) {
                    func_80801AA0_chweldarboss( param_0, 0x2C );
                } else {
                    *(u8 *)(local_0 + 0x67) = 1;

                    func_80801AA0_chweldarboss( param_0, 0x2D );
                }
            }
            break;

        case 42:
            func_808032A8_chweldarboss(param_0);

            if (func_80101DDC(param_0)) {
                func_80801AA0_chweldarboss( param_0, 0x2B );
            }
            break;

        case 43:
            if (func_800D9078( &param_0->unk58)) {
                func_800F82D4( *(s16 *)(local_0 + 0x76), 0 );

                func_80801AA0_chweldarboss( param_0, 0x1C );

                *(s16 *)(local_0 + 0x76) = -1;
            }
            break;

        case 45:
            func_80803624_chweldarboss(param_0);
            break;

        case 46:
        {
            f32 local_17[3];

            if (func_800D9078( &param_0->unk58)) {
                func_800EE7F8( local_17, param_0->position );

                local_17[1] += 300.0f;

                *(u8 *)(local_0 + 0x6E) = 0;

                _chbaddiesetup_entrypoint_5( (s32)_chbaddiesetup_entrypoint_10, 5, ((s32 *)local_17)[0], ((s32 *)local_17)[1], ((s32 *)local_17)[2], *(s32 *)((char *)param_0 + 0x48) );

                func_800BBCB8( local_17, local_17, 3.0f, 1, D_80804880_chweldarboss );

                func_800BBCB8( local_17, local_17, 1.0f, 6, D_808048B4_chweldarboss );

                _chexploder_entrypoint_5( param_0, 0x86F, param_0->position, param_0->rotation[1], param_0->scale, 3 );

                _subaddieaudioquick_entrypoint_2( param_0, param_0->position, D_80804874_chweldarboss );
            }

            func_80803624_chweldarboss(param_0);
            break;
        }

        case 47:
            if (func_800D9078( &param_0->unk58)) {
                func_800DA544(0x18C);
                func_80101180(0x345, 5, 0);
            }
            break;

        case 48:
            if (func_800D9078( &param_0->unk58)) {
                func_80801AA0_chweldarboss( param_0, 0x31 );
            }
            break;
    }

    func_808023F8_chweldarboss(param_0);
    func_8080247C_chweldarboss(param_0);
    func_808026BC_chweldarboss(param_0);
    func_80803770_chweldarboss(param_0);
    func_80803C18_chweldarboss(param_0);
    func_808034A0_chweldarboss(param_0);

    if (local_1 != 0) {
        f32 local_18;

        local_18 = 600.0f;
        _sudeflect_entrypoint_1(param_0->position, local_18, 0, local_18, 4);
    }
}


s32 func_808014CC_chweldarboss(Actor *param_0, s32 param_1, WeldarArg param_2)
{
    WeldarData *local_0;
    WeldarMsgObj *local_1;
    void *local_2;
    s32 fill1; /* UNUSED: holds the frame slot at 0x58 */
    Actor *local_3;
    Actor *local_10;
    f32 local_5[3];
    f32 local_4;
    WeldarVec local_6;
    f32 local_7[2];
    f32 local_8[3];

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2E:
        func_80801F30_chweldarboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0xB:
        return func_80802100_chweldarboss(param_0, param_2.i);
    case 0x3D:
        func_8080227C_chweldarboss(param_0, param_2.i);
        return 1;
    case 0x3F:
        local_1 = *(WeldarMsgObj **)&param_2;
        if (local_1->unk24_22 != 0) {
            break;
        }
        switch (param_0->unk70_10) {
        case 0xB:
        case 0xC:
        case 0x10:
        case 0x16:
        case 0x17:
        case 0x1A:
        case 0x26:
        case 0x27:
        case 0x2A:
            break;
        case 0x20:
            func_80801AA0_chweldarboss(param_0, 0x21);
        default:
            func_800F79DC(local_1->unk1A_5, 7, param_0->unk0);
            return 1;
        }
        break;
    case 0x40:
        local_2 = *(void **)&param_2;
        if (func_80803DD8_chweldarboss(param_0) && _sueggmisc_entrypoint_0(local_2)) {
            func_8010114C(local_2, 0x2C, 0);
            return 1;
        }
        break;
    case 0x90:
        local_3 = func_80106790(func_80101080());
        switch (param_2.i) {
        case 0x86E:
            _chexploder_entrypoint_15(local_3, 2, 1.0f);
            _chexploder_entrypoint_13(local_3, 1);
            return 1;
        case 0x86F:
            param_0->unk64_16 = 0;
            _chexploder_entrypoint_6(local_3, 1000.0f, 1200.0f);
            return 1;
        case 0x870:
            _chexploder_entrypoint_6(local_3, 3000.0f, 3000.0f);
            _chexploder_entrypoint_8(local_3, 450.0f, 450.0f);
            _chexploder_entrypoint_9(local_3, 1, 1);
            _chexploder_entrypoint_9(local_3, 2, 1);
            _chexploder_entrypoint_13(local_3, 0xB);
            _chexploder_entrypoint_8(local_3, 320.0f, 320.0f);
            return 1;
        }
        break;

    case 0x8D:
        local_10 = func_80106790(func_80101080());
        switch (param_2.i) {
        case 0x86E:
            local_4 = func_800F1DF4(param_0->position, local_10->position);
            func_800EE7F8(local_5, local_10->position);
            func_800EF1B8(local_5, local_4, -200.0f);
            func_80101010(local_5);
            local_0->unk68[local_0->unk66] = 0;
            local_0->unk66++;
            break;

        case 0x870:
            local_6 = D_808048EC_chweldarboss;
            func_800F18FC(local_10->position, &local_6, local_7);
            func_800EE7F8(local_8, local_10->position);
            func_800EF214(local_8, -local_7[0], local_7[1], -500.0f);
            local_8[1] -= 200.0f;
            func_80101010(local_8);
            return 1;
        default:
            return 0;
        }
        break;
    case 7:
        func_80801AA0_chweldarboss(param_0, 0x30);
        return 1;
    case 0x95:
        _subaddielink_entrypoint_3(local_0->unk30);
        if (local_0->unk61) {
            func_800FDC28(1);
            local_0->unk61 = 0;
        }
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_80802214_chweldarboss(param_0, 0xCEB, 0x4E);
        return 1;
    case 0x9F:
        func_800FDC28(0);
        func_8080373C_chweldarboss(param_0);
        func_80801AA0_chweldarboss(param_0, 0x32);
        func_80803D64_chweldarboss(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801944_chweldarboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_2;
    u8 *local_3;
    s32 local_5;
    s32 local_6;
    f32 local_0[1];
    Actor *local_4;
    f32 *local_7;
    f32 local_1[2];
    f32 *local_8;

    local_2 = func_80100094(param_0, 0);
    local_6 = func_800D731C(param_0->unk0->unk14);
    if (local_6) func_800DBE60(local_6, 0, *(void **)(local_2 + 0x84));
    for (local_5 = 0, local_3 = local_2; local_5 < 6; local_5++, local_3++) {
        func_800DF744(local_5 + 3, local_3[0x68]);
    }
    if (local_2[0x6E]) {
        func_800EE7F8(local_0, param_0->position);
        _subaddieDll_entrypoint_7(param_0, 0xF);
    }
    func_80101870(param_0, param_1);
    if (local_2[0x6E]) func_800EE7F8(param_0->position, local_0);
    if (param_0->unk7C_12) {
        local_4 = _subaddielink_entrypoint_4(local_2 + 0x30);
        local_7 = (f32 *)(local_2 + 0x44);
        _subaddieskeleton_entrypoint_2(param_0->unk0, 5, local_7);
        local_8 = (f32 *)(local_2 + 0x50);
        _subaddieskeleton_entrypoint_2(param_0->unk0, 6, local_8);
        if (local_4 != NULL) {
            func_800EE7F8(local_4->position, local_7);
            func_800F18FC(local_7, local_8, local_1);
            local_4->rotation[0] = 90.0f - local_1[0];
            local_4->rotation[1] = local_1[1];
        }
    }
}

void func_80801AA0_chweldarboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    s32 local_1;
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    func_80102424(param_0, param_1);
    func_80803460_chweldarboss(param_0);
    switch (param_1) {
    case 2:
        func_80803CF0_chweldarboss(param_0, 0x1D, 0x30);
        local_0[0x70] = 0;
        break;
    case 3:
        param_0->unk64_16 = 1;
        *(f32 *)(local_0 + 0xB4) = 4.0f;
        func_800BF744(1, 1);
        func_800FDC28(1);
        func_80803CF0_chweldarboss(param_0, 0, 0x30);
        func_80101180(0x341, 7, 0);
        break;
    case 4:
        ((u8 *)param_0)[0x7B] = (((u8 *)param_0)[0x7B] & ~0xC0) | 0x40;
        func_80101180(0x341, 8, 0);
        func_80803CF0_chweldarboss(param_0, 0xB, 0x30);
        break;
    case 5:
        _chintrotext_entrypoint_1(0x18B9, 6, 1, 0);
        break;
    case 8:
        local_1 = 1;
        if (!local_0[0x7A]) {
            local_0[0x7A] = 1;
            func_80802214_chweldarboss(param_0, 0x1357, 0x44);
        }
        break;
    case 7:
    case 9:
    case 13:
    case 19:
    case 21:
    case 24:
    case 37:
    case 40:
        local_1 = 1;
        break;
    case 12:
    case 23:
    case 39:
        local_1 = 1;
        param_0->unk58 = func_80803378_chweldarboss(param_0);
        local_0[0xB2] = _subaddieaudioloop_entrypoint_3(local_0[0xB2]);
        break;
    case 10:
        local_1 = 1;
        if (!local_0[0x7B]) {
            local_0[0x7B] = 1;
            func_80802214_chweldarboss(param_0, 0x1358, 0x44);
        }
        break;
    case 14:
    case 25:
    case 41:
        func_80803CF0_chweldarboss(param_0, 0x1B, 0x438);
        break;
    case 11:
    case 22:
    case 38:
        local_1 = 1;
        param_0->unk58 = 8.0f;
        break;
    case 16:
    case 26:
    case 42:
        local_0[0xB2] = _subaddieaudioloop_entrypoint_3(local_0[0xB2]);
        func_800F82D4(*(s16 *)(local_0 + 0x76), 2);
        func_800F8150(*(s16 *)(local_0 + 0x76), 0);
        func_800F4FC4();
        local_0[0x60] = 1;
        func_80803CF0_chweldarboss(param_0, 0x19, 0x428);
        break;
    case 17:
    case 27:
    case 43:
        param_0->unk58 = 1.4f;
        break;
    case 28:
        if (!local_0[0x7E]) {
            local_0[0x7E] = 1;
            func_80802214_chweldarboss(param_0, 0x135B, 0x44);
        }
        func_80803CF0_chweldarboss(param_0, 0x39, 0x10);
        *(s16 *)(local_0 + 0x74) = 0;
        break;
    case 35:
        *(s16 *)(local_0 + 0x74) = 0;
        break;
    case 32:
        if (!local_0[0x7F]) {
            local_0[0x7F] = 1;
            func_80802214_chweldarboss(param_0, 0x135C, 0x44);
        }
        break;
    case 18:
        local_1 = 1;
        if (!local_0[0x7D]) {
            local_0[0x7D] = 1;
            func_80802214_chweldarboss(param_0, 0x135A, 0x44);
        }
        break;
    case 44:
        func_80802214_chweldarboss(param_0, 0x135E, 6);
        func_80803CF0_chweldarboss(param_0, 0x22, 0x30);
        break;
    case 45:
        local_0[0x6E] = 1;
        func_800FDC28(0);
        func_8080373C_chweldarboss(param_0);
        func_80802214_chweldarboss(param_0, 0x135D, 0xE);
        func_80803CF0_chweldarboss(param_0, 0x22, 0x30);
        break;
    case 46:
        param_0->unk58 = 1.0f;
        func_80803CF0_chweldarboss(param_0, 0x12, 0x430);
        break;
    case 47:
        func_800EE7F8(local_2, param_0->position);
        local_2[1] += 800.0f;
        _subaddieaudioquick_entrypoint_2(param_0, local_2, D_808048F8_chweldarboss);
        param_0->unk58 = 0.9f;
        _chexploder_entrypoint_5(param_0, 0x870, local_2, param_0->rotation[1], param_0->scale, 0x100);
        func_80803CF0_chweldarboss(param_0, 0x29, 0x30);
        break;
    case 48:
        param_0->unk58 = 4.0f;
        break;
    case 49:
        if (func_800D395C()) {
            func_80803D64_chweldarboss(param_0);
            _gcfrontend_entrypoint_10();
        } else {
            func_80803CF0_chweldarboss(param_0, 0x1D, 0x30);
            func_80101180(0x431, 7, 0);
        }
        break;
    }
    if (local_1) {
        func_8080340C_chweldarboss(param_0);
    }
}

void func_80801F30_chweldarboss(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    u8 *sp2C;
    s32 sp28;
    u8 *var_v0;

    sp2C = func_80100094(param_0, 0);
    switch (param_1) {                                 
    case 0x1355: ;
    case 0x1356:
        func_800DA544(0x174);
        _gcfrontend_entrypoint_9(0x28);
        func_80803D64_chweldarboss(param_0);
        func_80801AA0_chweldarboss(param_0, 7);
        func_800FDC28(7);
        func_800BF744(1, 0);
        var_v0 = _subaddiefind_entrypoint_2(0x3A7, &sp28);
        if (var_v0 != NULL) {
            do {
                if ((*(f32 *)((s8 *)(var_v0) + (0xC))) < -2600.0f) {
                    func_800FFAB0(var_v0);
                }
                var_v0 = _subaddiefind_entrypoint_3(0x3A7, &sp28);
            } while (var_v0 != NULL);
            return;
        }
        return;
    case 0x135D:
        func_80801AA0_chweldarboss(param_0, 0x2E);
        return;
    case 0x135E:
        func_808036C8_chweldarboss(param_0);
        func_80802214_chweldarboss(param_0, 0x135F, 6);
        func_80803CF0_chweldarboss(param_0, 0x1F, 0x30);
        return;
    case 0x135F:
        func_80803D64_chweldarboss(param_0);
        func_80801AA0_chweldarboss(param_0, 8);
        (*(s8 *)((s8 *)(sp2C) + (0x63))) = func_808033D8_chweldarboss(param_0);
        return;
    case 0x1359:
        if (((u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA) == 0xF) {
            func_80803D64_chweldarboss(param_0);
            func_80801AA0_chweldarboss(param_0, 0x12);
            (*(s8 *)((s8 *)(sp2C) + (0x63))) = 3;
            return;
        }
        break;
    case 0xCEB:
        if (param_2 > 0) {
            _gcfrontend_entrypoint_11();
            return;
        }
        _gcfrontend_entrypoint_10();
        break;
    }
}

int func_80802100_chweldarboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;

    local_0 = (u8 *)func_80100094(param_0, 0);
    local_1 = 3;
    switch (param_1) {
    case 0x1D:
        if (param_0->unk70_10 == 2) {
            func_80801AA0_chweldarboss(param_0, 3);
        } else {
            func_800FFAB0(_subaddielink_entrypoint_4(local_0 + 0x30));
            func_800FFAB0(param_0);
            func_80803D64_chweldarboss((s32)param_0);
            func_800DA544(0x9C9);
            _glcutDll_entrypoint_6(0x10F, 0x45);
        }
        local_1 = 4;
        break;
    case 0x12:
        func_80801AA0_chweldarboss(param_0, 0x2F);
        local_1 = 4;
        break;
    case 0x39:
        *(s16 *)(local_0 + 0x72) = 0;
        break;
    case 0x29:
        func_80803CF0_chweldarboss(param_0, 0x32, 0x30);
        func_80101180(0x46A, 10, 0);
        local_1 = 4;
        break;
    }
    return local_1;
}

int func_80802214_chweldarboss(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0x1359)
  {
    if (func_800C064C() == 0x1358)
    {
      func_800C067C(0x1358);
    }
  }
  else
  {}

  return _subaddiedialog_entrypoint_11(param_0[0], param_1, param_2, param_0 + 1, 0xB5);
}

void func_8080227C_chweldarboss(Actor *param_0, s32 param_1)
{
    u8 *local_4;
    Actor *local_0;
    Actor *local_1;
    f32 local_2[3];
    Actor *local_3;

    local_4 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0:
            local_0 = func_80108528(0x468, param_0->position, 0, &param_0);
            _subaddielink_entrypoint_1(local_4 + 0x30, local_0->unk0);
            local_0->unk3C = param_0->unk0;
            break;
        case 1:
            local_1 = func_80108528(0x124, (f32 *)(local_4 + 0x44), 0, &param_0);
            func_8010D09C(*(s16 *)(local_4 + 0x78), local_1->actorData, 0.8f);
            local_1->unk3C = param_0->unk0;
            break;
        case 2:
            local_3 = func_80108528(func_800DC128(0, 3) + 0x43E, (f32 *)(local_4 + 0x44),
                (s32)param_0->rotation[1], &param_0);
            func_80100120(local_3);
            func_800F5A00(*(s16 *)(local_4 + 0x78), local_2);
            local_2[1] = 0.0f;
            func_80101010(local_2);
            func_8010108C(local_3, 0x8E, param_0->unk0);
            break;
    }
}

void func_808023BC_chweldarboss(Actor *unused, s32 param_1) {
    s32 local_0;

    local_0 = _subaddielink_entrypoint_4((u8 *)func_80100094(unused, 0) + 0x30);
    if (local_0 != 0) {
        func_808041C4_chweldarboss(local_0, param_1);
    }
}

void func_808023F8_chweldarboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1;

    if (param_0->unk64_16) {
        func_800EE7F8(local_0, param_0->position);
        local_0[1] = 0.0f;
        local_1 = *(f32 *)((u8 *)param_0 + 0x38)
            * func_800F10B4(param_0->position[1], 0.0f, 3000.0f, 5.0f, 1.4f);
        _chbadshad_entrypoint_1(param_0, local_0, local_1);
    }
}

void func_8080247C_chweldarboss(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;
    f32 *local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    local_1 = _subaddielink_entrypoint_4(local_0 + 0x30);
    local_2 = func_80100094(local_1, 0);
    local_3 = 0;
    if (local_1) {
        switch (func_801022E4(param_0)) {
        case 0x36F:
            if (!local_0[0x67] && (func_80102320(param_0, 0.02f, 0.13f) || func_80102320(param_0, 0.26f, 0.55f))) local_3 = 1;
            func_808023BC_chweldarboss(param_0, local_3 ? 2 : 4);
            break;
        case 0x373:
            if (func_80101E14(param_0, 0.53f)) func_808023BC_chweldarboss(param_0, 2);
            if (func_80101E14(param_0, 0.75f)) func_808023BC_chweldarboss(param_0, 4);
            local_3 = func_80102320(param_0, 0.53f, 0.75f);
            break;
        case 0x372:
            if (func_80101E14(param_0, 0.7f)) func_808023BC_chweldarboss(param_0, 2);
            local_3 = func_80101F24(param_0) > 0.7f;
            break;
        default:
            func_808023BC_chweldarboss(param_0, 4);
            break;
        }
        if (local_2[2] > 0.0f) local_3 = 1;
        local_0[0xB0] = _subaddieaudioloop_entrypoint_7(local_0[0xB0], local_1->position, local_3, D_80804908_chweldarboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
        if (local_0[0xB0]) func_800C31DC(local_0[0xB0], func_800F12D4(local_2[2], 0.0f, 1.0f, 1.2f, 0.8f));
    }
}

void func_808026BC_chweldarboss(param_0) Actor *param_0;
{
    u8 *local_0;
    Vec3f local_1;
    Vec3f local_2;
    void *local_7;
    Vec3f local_3;
    s32 idx;
    Vec3f local_4;
    f32 local_5;

    local_0 = func_80100094(param_0, 0);
    switch (func_801022E4(param_0)) {
    case 0x371:
        _subaddieaudioquick_entrypoint_3(param_0, ((f32 *)(local_0 + 0x44)), D_80804980_chweldarboss, 0.22f);
        _subaddieaudioquick_entrypoint_3(param_0, ((f32 *)(local_0 + 0x44)), D_80804970_chweldarboss, 0.24f);
        if (func_80102320(param_0, 0.2f, 0.4f) && !func_8001210C(1)) {
            func_800EE7F8(local_2.f, ((f32 *)(local_0 + 0x44)));
            local_2.pos.y = 0.0f;
            func_800EE7F8(local_1.f, local_2.f);
            func_800EF1B8(local_1.f, param_0->rotation[1], -100.0f);
            func_800BBCB8(local_2.f, local_1.f, param_0->scale * 0.6f, 2, D_80804928_chweldarboss);
        }
        if (func_80102320(param_0, 0.24f, 0.64f) && func_8001210C(1)) {
            func_800BBCB8(param_0->position, ((f32 *)(local_0 + 0x44)), param_0->scale, 3, D_80804928_chweldarboss);
        }
        if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80804990_chweldarboss, 0.34f)) {
            local_7 = func_800E1540(2);
            func_800E1378(local_7);
            func_800E13F0(local_7, 10.0f);
            func_800E1410(local_7, -8.0f, 1.8f);
            func_800187B4(0, 1.0f, 0.4f, 0.8f);
        }
        break;
    case 0x372:
        func_80802ABC_chweldarboss(param_0, 0.5f);
        break;
    case 0x374:
        break;
    case 0x375:
        func_80802ABC_chweldarboss(param_0, 0.75f);
        break;
    case 0x3E7:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80804918_chweldarboss, 0.15f);
        break;
    case 0x373:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80804918_chweldarboss, 0.08f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_808049A4_chweldarboss, 0.5f);
        if (func_80101E14(param_0, 0.6f)) {
            local_0[0x6F]--;
            idx = local_0[0x66];
            if (_subaddieskeleton_entrypoint_2(param_0->unk0, idx + 7, local_3.f)) {
                local_5 = func_800F1DF4(param_0->position, local_3.f);
                func_800EE7F8(local_4.f, local_3.f);
                func_800EF1B8(local_4.f, local_5, -200.0f);
                _chexploder_entrypoint_5(param_0, 0x86E, local_3.f, local_5, param_0->scale, 2);
            }
        }
        break;
    }
}

void func_808029D8_chweldarboss(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2;
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_2 = func_800DC178(300.0f, 1000.0f);
    local_3 = func_800F10B4(local_2, 300.0f, 1000.0f, 1.0f, 1.5f);
    func_800EEB9C(local_1, param_0->rotation[1], local_2);
    func_800EF04C(local_1, (f32 *)(local_0 + 0x44));
    func_800BBCB8(local_1, (f32 *)(local_0 + 0x44), local_3, 1, D_808049B4_chweldarboss);
    local_0[0xB2] = _subaddieaudioloop_entrypoint_7(local_0[0xB2], (f32 *)(local_0 + 0x44), 1, D_808049DC_chweldarboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
}

void func_80802ABC_chweldarboss(Actor *param_0, f32 param_1)
{
    if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_808049EC_chweldarboss, param_1)) {
        func_800E15CC(0, 10.0f, 0.8f);
        func_80018820(0, 0.8f, 0.3f);
    }
}

void func_80802B1C_chweldarboss(Actor *param_0)
{
    s32 local_3;
    f32 local_0[3];
    s32 local_2;
    local_2 = func_800B53A4(8);
    for (local_3 = 0; local_3 != 8; local_3++) {
        func_800EEB9C(local_0, (f32)local_3 * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(local_0, param_0->position);
        local_0[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(local_2, local_0, param_0->position, 1.0f, D_80804A10_chweldarboss);
    }
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808049FC_chweldarboss);
    func_800E15CC(0, 30.0f, 0.9f);
    func_80018820(0, 1.8f, 0.75f);
}

f32 func_80802C9C_chweldarboss(Actor *param_0, s32 param_1)
{
    f32 local_0;
    local_0 = func_80101F24(param_0);
    switch (param_1) {
    case 0:
        return func_800F3780(local_0, D_80804A4C_chweldarboss, 3);
    case 1:
        return func_800F3780(local_0, D_80804A64_chweldarboss, 3);
    case 2:
        return func_800F3780(local_0, D_80804A7C_chweldarboss, 3);
    }
    return 0.0f;
}

void func_80802D2C_chweldarboss(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0 = (u8 *)func_80100094(param_0, 0);
    s32 local_1 = func_800D9078(&param_0->unk58);
    f32 local_2 = func_800D8FF8();
    f32 local_3[3];
    f32 local_4[3];
    s32 local_5;

    param_0->unk54 = func_8010CD50(param_0, *(s16 *)(local_0 + 0x78));
    func_80102B2C(param_0, 120.0f * local_2);
    func_808029D8_chweldarboss(param_0);
    func_80802E80_chweldarboss(param_0);
    if ((*(u32 *)((u8 *)param_0 + 0x7C) << 19) >> 31) {
        func_800EEB9C(local_3, param_0->rotation[1], 100.0f);
        func_800EE7F8(local_4, (f32 *)(local_0 + 0x44));
        func_800EF1B8(local_4, param_0->rotation[1], -300.0f);
        local_5 = func_8010D490(local_4, local_3, 2300.0f, 600.0f, -1);
        if (local_5 != -1) func_80803080_chweldarboss(param_0, local_5);
        switch (func_80803184_chweldarboss(param_0, local_5)) {
            case 1:
                func_80801AA0_chweldarboss(param_0, param_1);
                break;
            case 2:
                return;
        }
    }
    if (local_1) func_80801AA0_chweldarboss(param_0, param_2);
}

void func_80802E80_chweldarboss(param_0) u8 *param_0; {
  s8 _sfpad[8];
    s32 local_0;

    func_80802F14_chweldarboss(param_0, 1);
    func_800EE7F8(&local_0, param_0 + 4);
    func_800EF1B8(&local_0, (*(f32 *)((s8 *)(param_0) + (0x48))), 250.0f);
    _sudeflect_entrypoint_1(&local_0, 500.0f, -100.0f, 300.0f, 2);
    func_800EF1B8(&local_0, (*(f32 *)((s8 *)(param_0) + (0x48))), 300.0f);
    _sudeflect_entrypoint_1(&local_0, 500.0f, -100.0f, 200.0f, 2);
}

void func_80802F14_chweldarboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;

    local_0 = 0;
    local_1 = 8;
    do {
        if (func_800F6438(local_0) && (param_1 || !func_800F682C(local_0) || func_800F6AA4(local_0))) {
            func_800F4EC8(local_0, param_0->position, 600.0f, -100.0f, 300.0f);
        }
        local_0++;
    } while (local_0 != local_1);
}

void func_80802FE4_chweldarboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    f32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D90A4(&param_0->unk58);
    local_2 = func_800D8FF8();
    param_0->unk54 = func_8010CD50(param_0, *(s16 *)(local_0 + 0x78));
    func_80102B2C(param_0, 120.0f * local_2);
    func_80802E80_chweldarboss(param_0);
    if (local_1) {
        func_80801AA0_chweldarboss(param_0, param_1);
    }
}

void func_80803080_chweldarboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    s32 pad;
    f32 local_4;
    f32 local_5;

    local_0 = func_80100094(param_0, 0);
    if (func_800F6478((*(s32 *)&param_1)) && !func_800F6590((*(s32 *)&param_1))) {
        func_800F5A00((*(s32 *)&param_1), local_3);
        func_800EE7F8(local_1, (f32 *)(local_0 + 0x44));
        func_800EF1B8(local_1, *(f32 *)((u8 *)param_0 + 0x48), -600.0f);
        local_4 = func_800F10B4(func_800EEAD4(local_3, (f32 *)(local_0 + 0x44)), 100.0f, 3000.0f, 550.0f, 350.0f);
        func_800F5D9C((*(s32 *)&param_1), local_2);
        local_5 = func_800F1DF4((f32 *)(local_0 + 0x44), local_3);
        func_800EF1B8(local_2, local_5, -(func_800D8FF8() * local_4));
        func_800F8418((*(s32 *)&param_1), local_2);
    }
}

s32 func_80803184_chweldarboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    if (param_1 == -1) {
        return 0;
    }
    if (!func_800F6478(param_1)) {
        return 0;
    }
    local_3 = func_800F5BF0(param_1, local_2);
    func_800EE7F8(local_1, (f32 *)(local_0 + 0x44));
    func_800EF1B8(local_1, param_0->rotation[1], 100.0f);
    if (func_800F0008(local_2, local_3, local_1, 175.0f)) {
        if (func_800F64A4(param_1, 0x10000)) {
            func_800F7B9C(param_1, 0x86);
            *(s16 *)(local_0 + 0x78) = func_800F54E4();
            func_80803DD8_chweldarboss(param_0);
            return 2;
        }
        _subaddieaudioquick_entrypoint_2(param_0, local_0 + 0x44, D_80804A94_chweldarboss);
        func_80018820(0, 1.2f, 0.4f);
        *(s16 *)(local_0 + 0x76) = param_1;
        return 1;
    }
    return 0;
}

void func_808032A8_chweldarboss(Actor *param_0)
{
    WeldarPlayerEvent *local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_1) {
        func_800EE7F8(local_1, local_0->local_0);
        local_1[1] -= 200.0f;
        func_800F8294(local_0->local_2, local_1);
        if (func_80101E14(param_0, 0.7f)) {
            _subaddieaudioquick_entrypoint_2(param_0, local_1, D_80804AA4_chweldarboss);
            func_800EE7F8(local_2, param_0->position);
            func_800EF1B8(local_2, param_0->rotation[1], 700.0f);
            func_800F7CF4(local_0->local_2, 0x92, local_2);
            func_800F8150(local_0->local_2, 1);
            local_0->local_1 = 0;
        }
    }
}

f32 func_80803378_chweldarboss(Actor *param_0)
{
    u8 *local_0 = func_80100094(param_0, 0);

    return func_800F10B4((u32)local_0[0x6F], 1.0f, 6.0f, 0.0f, 3.0f);
}

int func_808033D8_chweldarboss(s32 param_0)
{
  u8 *local_0;
  local_0++;
  local_0 = func_80100094(param_0, 0);
  local_0--;
  return (!local_0[0x63]) ? (5) : (8);
}

s32 func_8080340C_chweldarboss(Actor *this)
{
  u8 *local_0;
  u8 *local_1;
  local_0 = func_80100094(this, 0);
  if (local_0[0x64] == 0) {
        local_1 = local_0;
        func_800F4AF4(*(s16 *)&local_0[0x78], 0x14);
        local_1[0x64] = 1;
    }
  func_808034A0_chweldarboss(this);
}

void func_80803460_chweldarboss(s32 param_0) {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if ((*(u8 *)((s8 *)(sp1C) + (0x64))) != 0) {
        func_800F4B20((*(s16 *)((s8 *)(sp1C) + (0x78))));
        (*(s8 *)((s8 *)(sp1C) + (0x64))) = 0;
    }
}

void func_808034A0_chweldarboss(param_0) Actor *param_0;
{
    WeldarCameraState1425 *local_0;
    f32 local_1[3];
    u32 pad;

    local_0 = func_80100094(param_0, 0);
    if (local_0->enabled) {
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 700.0f;
        _plcamera_entrypoint_9(local_0->player, local_1, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(local_0->player)), local_1);
    }
}

void func_80803528_chweldarboss(param_0, param_1) Actor *param_0; f32 *param_1;
{
    WeldarContactState *local_0;
    local_0 = func_80100094(param_0, 0);
    if (!local_0->active && param_0->position[1] < 300.0f) {
        if (func_800EFC7C(param_1, param_0->position) < 40000.0f && func_80803B48_chweldarboss((void *)(s32)local_0->id)) {
            local_0->active = 1;
            func_800F82D4(local_0->id, 2);
        }
    }
}

void func_808035D0_chweldarboss(s32 param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    s32 local_1;
    if (local_0[0x65]) {
        local_1 = *(s16 *)(local_0 + 0x78);
        func_800F82D4(local_1, 0);
        func_800F7B9C(local_1, 0x5A);
        local_0[0x65] = 0;
    }
}

void func_80803624_chweldarboss(u8 *param_0) {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    *(u8 *)(temp_v0 + 0xB1) = _subaddieaudioloop_entrypoint_7(
        *(u8 *)(temp_v0 + 0xB1),
        param_0 + 4,
        *(u8 *)(temp_v0 + 0x6E),
        &D_80804AB4_chweldarboss,
        (*(s32 *)(param_0 + 0x70)) & 1
    );
}

void func_8080367C_chweldarboss(void *param_0)
{
    u32 temp_t6;

    temp_t6 = ((u32)*(u16 *)((u8 *)param_0 + 0x72)) >> 10;
    if ((s32)temp_t6 >= 7 && (s32)temp_t6 < 0x2D)
    {
        func_800D2498(0xFD, *(u8 *)((u8 *)func_80100094(param_0, 0) + 0x6F), 0);
    }
}

void func_808036C8_chweldarboss(s32 param_0)
{
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    *(s8 *)(temp_v0 + 0x62) = 1;
    *(s16 *)(temp_v0 + 0xAC) = 2;
    *(f32 *)(temp_v0 + 0xA8) = 10.0f;
    _mlwave_entrypoint_0(temp_v0 + 0x88, 300.0f, 300.0f);
    _mlwave_entrypoint_7(temp_v0 + 0x88, 0.25f);
    func_800BF744(3, 1);
}

void func_8080373C_chweldarboss(s32 param_0) {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    (*(s16 *)((s8 *)(temp_v0) + (0xAC))) = 4;
    (*(f32 *)((s8 *)(temp_v0) + (0xA8))) = 2.0f;
}

void func_80803770_chweldarboss(Actor *param_0)
{
  u8 *local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  void **new_var;
  void **new_var2;
  void *local_4;
  void *local_5;
  local_0 = (u8 *) func_80100094(param_0, 0);
  local_1 = 0;
  new_var2 = &local_4;
  new_var = new_var2;
  switch (*((s16 *) (local_0 + 0xAC)))
  {
    case 1:
      break;

    case 2:
      local_2 = func_800D90A4(local_0 + 0xA8);
      local_4 = local_0 + 0x88;
      _mlwave_entrypoint_1(*new_var);
      *((s16 *) (local_0 + 0xAE)) = (s32) _mlwave_entrypoint_5(local_4, 0, 255.0f);
      if (local_2 && _mlwave_entrypoint_8(local_4, 0.75f))
    {
      *((s16 *) (local_0 + 0xAE)) = 0xFF;
      *((s16 *) (local_0 + 0xAC)) = 3;
    }
      local_1 = 1;
      break;

    case 3:
      if (func_800D90A4(local_0 + 0xA4))
    {
      func_808038F8_chweldarboss(param_0, local_1 | 0);
    }
      break;

    case 4:
      local_3 = func_800D90A4(local_0 + 0xA8);
      *((s16 *) (local_0 + 0xAE)) = (s32) func_800F10B4(*((f32 *) (local_0 + 0xA8)), .0f, 2.0f, 0.0f, 255.0f);
      if (local_3)
    {
      *((s16 *) (local_0 + 0xAC)) = 1;
      func_800BF744(3, 0);
    }
      local_1 = 1;
      break;

  }

  if (local_1)
  {
    local_5 = (void *) func_800BEA88(0, local_1);
    if (local_5)
    {
      _glid_entrypoint_0(local_5, 1, _chweldarboss_entrypoint_2, param_0->unk0);
    }
  }
}

s32 func_808038F8_chweldarboss(this) Actor *this;
{
    WeldarLocal *local;
    f32 pos[3];
    s32 i;
    s32 count;
    s32 cell[2];
    f32 dx;
    f32 dz;
    f32 p2[3];

    local = func_80100094(this, 0);
    count = 0;
    for (i = 0; i < 8; i++) {
        if (!func_800F6438(i)) {
            continue;
        }
        if (!func_80803B48_chweldarboss(i)) {
            continue;
        }
        if (func_800F6AA4(i)) {
            continue;
        }
        func_800F5A00(i, pos);
        cell[0] = (0.0f < pos[0]) ? (s32)(pos[0] / 800.0f) : (s32)(pos[0] / 800.0f + -1.0f);
        cell[1] = (0.0f < pos[2]) ? (s32)(pos[2] / 800.0f) : (s32)(pos[2] / 800.0f + -1.0f);
        dx = pos[0] - (f32)(cell[0] * 800);
        dz = pos[2] - (f32)(cell[1] * 800);
        if (dx < 50.0f || 750.0f < dx || dz < 50.0f || 750.0f < dz) {
            func_800F796C(i, 0xD);
            func_800EE7F8(p2, pos);
            p2[1] += 20.0f;
            _chelectricfence_entrypoint_1(this, p2);
            local->unkA4 = 2.0f;
            count++;
        }
    }
    return count;
}

s32 func_80803B48_chweldarboss(void *param_0)
{
    if (!func_800F6478(param_0) || !func_800F6C5C(param_0)) {
        return 0;
    }
    return func_800F5628(param_0) < 50.0f;
}

void chweldarboss_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    u8 local_0;
    Vtx *local_1;

    local_0 = *((u8 *)func_80100094(func_80106790(param_4), 0) + 0xAF);
    for (local_1 = param_2 + param_3; param_2 < local_1; param_2++) {
        param_2->v.cn[3] = local_0;
    }
}

void func_80803C18_chweldarboss(Actor *param_0)
{
    WeldarLinkedPhase *local_0;
    Actor *local_1;
    u8 *local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    local_1 = _subaddielink_entrypoint_4(local_0->local_0);
    local_0->local_1 += func_800D8FF8() * 22.0f;
    if (local_1) {
        local_2 = func_80100094(local_1, 0);
        if (local_1->unk70_10 == 1) local_0->local_2 = 5;
        else {
            local_3 = (s32)func_800F10B4(*(f32 *)(local_2 + 8), 0.0f, 1.0f, 4.0f, 0.0f);
            local_0->local_2 = (s32)func_800F13C4(local_0->local_1, 2.0f) + local_3;
        }
    }
}

void func_80803CF0_chweldarboss(param_0, param_1, param_2) Actor *param_0; u32 param_1; u32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (*(s16 *)(local_0 + 0x72)) {
        _capod_entrypoint_14();
        param_2 |= 0x2000;
    }
    _capod_entrypoint_13(param_0->unk0, 0, param_1, param_2);
    *(s16 *)(local_0 + 0x72) = 1;
}

void func_80803D64_chweldarboss(param_0) s32 param_0; {
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if ((*(s16 *)((s8 *)(local_0) + (0x72))) != 0) {
        (*(s16 *)((s8 *)(local_0) + (0x72))) = 0;
        _capod_entrypoint_14();
    }
}

s32 func_80803D98_chweldarboss(s32 param_0)
{
  s32 v0;
  s32 v1;
  v0 = func_8010D290(0x10000);
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

s32 func_80803DD8_chweldarboss(param_0) Actor *param_0;
{
    s32 local_0;
    local_0 = 0;
    switch (param_0->unk70_10) {
    case 0xB:
    case 0xC:
        func_80801AA0_chweldarboss(param_0, 0xE);
        local_0 = 1;
        break;
    case 0x16:
    case 0x17:
        func_80801AA0_chweldarboss(param_0, 0x19);
        local_0 = 1;
        break;
    case 0x26:
    case 0x27:
        func_80801AA0_chweldarboss(param_0, 0x29);
        local_0 = 1;
        break;
    }
    return local_0;
}

void func_80803E50_chweldarboss(Actor *param_0)
{
    void *local_0;
    local_0 = func_80100094(param_0, 0);
    *(float *)((char *)local_0 + 8) = 0.0f;
    func_808041C4_chweldarboss(param_0, 1);
    _subaddielink_entrypoint_1(local_0, param_0->unk3C);
    param_0->unk3C = 0;
}

void func_80803EA4_chweldarboss(Actor *param_0)
{
    WeldarLightState *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_6;
    f32 local_5;

    local_0 = func_80100094(param_0, 0);
    local_1 = local_0->local_1;
    local_6 = func_800D8FF8();
    switch (param_0->unk70_10) {
    case 1:
        param_0->unk64_16 = 0;
        break;
    case 2:
        param_0->unk64_16 = 1;
        local_0->local_0 = func_800F15F8(local_0->local_0, 1.0f, local_6 * 1.4f);
        if (local_0->local_0 == 1.0f) func_808041C4_chweldarboss(param_0, 3);
        break;
    case 3:
        param_0->unk64_16 = 1;
        break;
    case 4:
        param_0->unk64_16 = 1;
        local_0->local_0 = func_800F15F8(local_0->local_0, 0.0f, local_6 * 1.6f);
        if (local_0->local_0 == 0.0f) func_808041C4_chweldarboss(param_0, 1);
        break;
    }
    local_5 = func_800F12D4(local_0->local_0, 0.0f, 1.0f, 400.0f, 700.0f);
    func_800EE7F8(local_2, param_0->position);
    func_800EF214(local_2, 90.0f - param_0->rotation[0], param_0->rotation[1], local_5);
    local_3 = func_800F12D4(local_0->local_0, 0.0f, 1.0f, 200.0f, 600.0f);
    local_4 = func_800F12D4(local_0->local_0, 0.0f, 1.0f, 400.0f, 1000.0f);
    func_800C8FE0(local_1, param_0->unk64_16);
    func_800C8E54(local_1, local_3, local_4);
    func_800C8CB8(local_1, local_2);
    func_800C8E84(local_1, func_8001210C(1) ? D_80804AC8_chweldarboss : D_80804ABC_chweldarboss);
}

s32 func_808040F4_chweldarboss(s32 param_0, s32 param_1, s32 param_2)
{
  s32 *new_var2;
  char new_var;
  if (param_1 == 0x95)
  {
    new_var2 = &param_2;
    func_80804230_chweldarboss(param_0, param_1, *new_var2);
    return new_var = 1;
  }
  return 0;
}

void func_8080412C_chweldarboss(Actor *param_0, s32 param_1)
{
    f32 *local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F12D4(local_0[2], 0.0f, 1.0f, 0.4f, 1.4f);
    local_2 = func_800F12D4(local_0[2], 0.0f, 1.0f, 0.8f, 1.2f);
    func_800DF500(local_2, local_1, local_2);
    func_80101870(param_0, param_1);
}

void func_808041C4_chweldarboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_1) {
        case 2:
            if (param_0->unk70_10 == 3) return;
            break;
        case 4:
            if (param_0->unk70_10 == 1) return;
            break;
    }
    func_80102424(param_0, param_1);
}

void func_80804230_chweldarboss(param_0) s32 param_0; {
    u8 *local_0;
    s32 local_1;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    local_0 = local_2;
    _subaddielink_entrypoint_3(local_2);
    local_1 = func_800C8A98();
    *(s32 *)((char *)local_0 + 0xC) = local_1;
    func_800C8FE0(local_1, 0);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/weldarboss.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_8080480C_chweldarboss -> s32[] */
u8 D_808045F0_chweldarboss[416] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x53, 0x33, 0x33, 0x3, 0x71, 0x0, 0x44, 0x40, 0x53, 0x33, 0x33, 0x3, 0x71, 0x0, 0x44, 0x40, 0x53, 0x33, 0x33, 0x3, 0x71, 0x0, 0x9, 0x3F, 0xE0, 0x0, 0x0, 0x3, 0x72, 0x0, 0xA, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x9, 0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x49, 0x3E, 0xE6, 0x66, 0x66, 0x3, 0x76, 0x0, 0xA, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0xA, 0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9, 0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0x92, 0x40, 0x20, 0x0, 0x0, 0x3, 0x73, 0x0, 0xA, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x40, 0x4C, 0xCC, 0xCD, 0x3, 0xE7, 0x0, 0xA, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x49, 0x3E, 0xE6, 0x66, 0x66, 0x3, 0x76, 0x0, 0xA, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0xA, 0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9, 0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0x92, 0x40, 0x20, 0x0, 0x0, 0x3, 0x73, 0x0, 0xA, 0x40, 0x4C, 0xCC, 0xCD, 0x3, 0xE7, 0x0, 0xA, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE5, 0x0, 0x4A, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE5, 0x0, 0x2, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE5, 0x0, 0x2, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE6, 0x0, 0x4A, 0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x9, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE5, 0x0, 0x4A, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE5, 0x0, 0x2, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE5, 0x0, 0x2, 0x3F, 0x40, 0x0, 0x0, 0x3, 0xE6, 0x0, 0x4A, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0xA, 0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9, 0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0x92, 0x40, 0x20, 0x0, 0x0, 0x3, 0x73, 0x0, 0xA, 0x40, 0x4C, 0xCC, 0xCD, 0x3, 0xE7, 0x0, 0xA, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9, 0x40, 0x80, 0x0, 0x0, 0x3, 0x6F, 0x0, 0x9 };
u32 D_80804790_chweldarboss[10] = { 0x0, 0x0, 0x3E23D70A, 0x37A0001, 0x3E23D70A, 0x37A0001, 0x3E23D70A, 0x37A0001, 0x3E23D70A, 0x37A0001 };
u8 D_808047B8_chweldarboss[12] = { 0x0, 0x13, 0x4, 0x1D, 0x0, 0xD, 0x0, 0xC0, 0x0, 0xD9, 0x0, 0x0 };
void *D_808047C4_chweldarboss = (void *)0x02F80465;
static u32 D_808047C4_chweldarboss_rest[17] = { 0x8170001, (u32)&D_808045F0_chweldarboss, (u32)func_8080030C_chweldarboss, (u32)func_80105834, (u32)func_80801944_chweldarboss, 0x0, 0x0, 0x0, 0x568, (u32)func_808002BC_chweldarboss, (u32)func_80108ED0, 0xB80000, (u32)func_80800018_chweldarboss, (u32)func_80107C2C, 0x82010480, (u32)func_808014CC_chweldarboss, 0x0 };
s32 D_8080480C_chweldarboss[18] = { 0x1580468, 0x86B0001, (u32)&D_80804790_chweldarboss, (u32)func_80803EA4_chweldarboss, (u32)func_80105834, (u32)func_8080412C_chweldarboss, 0x0, 0x0, 0x0, 0x20400, 0x0, 0x0, 0x100000, (u32)func_80803E50_chweldarboss, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_808040F4_chweldarboss, 0x0 };
u8 D_80804854_chweldarboss[16] = { 0x0, 0x13, 0x6, 0x1C, 0x0, 0x18, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x0 };
u8 D_80804864_chweldarboss[16] = { 0x0, 0x13, 0x6, 0x12, 0x0, 0x18, 0x0, 0xA, 0x0, 0xC0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804874_chweldarboss[12] = { 0x0, 0x13, 0x4, 0x13, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804880_chweldarboss[52] = { 0x0, 0x1D, 0x7, 0x8F, 0x0, 0x15, 0x0, 0x19, 0x0, 0x66, 0x0, 0x16, 0x12, 0x0, 0x0, 0x32, 0x0, 0x2, 0x0, 0x1E, 0x0, 0x1E, 0x0, 0x1E, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0xF, 0x0, 0xF, 0x0, 0x0, 0x22, 0x1, 0x0, 0x1, 0x0, 0x4, 0x0, 0x4, 0x0, 0x0, 0x2B, 0x1, 0x0, 0x1, 0x0, 0x0, 0x0 };
u8 D_808048B4_chweldarboss[56] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x8, 0x0, 0xA, 0x0, 0x0, 0x22, 0x4, 0x0, 0x5, 0x0, 0x8, 0x80, 0xA, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x66, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x0, 0xB, 0x0, 0x3C, 0x0, 0x78, 0x0, 0xB4, 0xFF, 0x4C, 0x0, 0x0 };
WeldarVec D_808048EC_chweldarboss = { -1.8e+03f, 1.2e+03f, -2.2e+03f };
u8 D_808048F8_chweldarboss[16] = { 0x0, 0x13, 0x4, 0xFE, 0x0, 0x18, 0x0, 0x2, 0x0, 0xA, 0x0, 0x8C, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804908_chweldarboss[16] = { 0x0, 0x13, 0x6, 0x6, 0x0, 0xA, 0x1, 0x33, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x2, 0x0, 0x0 };
u8 D_80804918_chweldarboss[16] = { 0x0, 0x13, 0x4, 0xA4, 0x0, 0xD, 0x0, 0xAE, 0x0, 0xB8, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804928_chweldarboss[72] = { 0x0, 0x1D, 0x9, 0xE2, 0x0, 0x16, 0x2, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x4, 0x0, 0x99, 0x0, 0x7, 0x0, 0x4, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x0, 0x0, 0x22, 0x0, 0x4C, 0x0, 0x59, 0x0, 0x26, 0x0, 0x33, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0x90, 0x0, 0xA, 0xFF, 0x9C, 0x0, 0xA, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0xA, 0x0, 0x64, 0x0, 0x1B, 0xF9, 0xC0, 0xFB, 0x50, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804970_chweldarboss[16] = { 0x0, 0x13, 0x6, 0x9, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804980_chweldarboss[16] = { 0x0, 0x13, 0x6, 0xA, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804990_chweldarboss[20] = { 0x0, 0x13, 0x6, 0x8, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0, 0x0, 0x0 };
u8 D_808049A4_chweldarboss[16] = { 0x0, 0x13, 0x6, 0x7, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0 };
u8 D_808049B4_chweldarboss[40] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x80, 0x0, 0x0, 0x2D, 0x2, 0x58, 0x3, 0x20, 0x1, 0x13, 0x0, 0x22, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x40, 0x0, 0x59, 0x0, 0x15, 0x0, 0x26, 0x0, 0x99, 0x0, 0x2B, 0x0, 0x4C, 0x0, 0x66, 0x0, 0x0 };
u8 D_808049DC_chweldarboss[16] = { 0x0, 0x13, 0x6, 0xB, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0 };
u8 D_808049EC_chweldarboss[16] = { 0x0, 0x13, 0x4, 0xA0, 0x0, 0xD, 0x0, 0x99, 0x0, 0xA6, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_808049FC_chweldarboss[20] = { 0x0, 0x13, 0x4, 0xA0, 0x0, 0xD, 0x0, 0x99, 0x0, 0xA6, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804A10_chweldarboss[60] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x0, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x3, 0x80, 0x4, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x99, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0x5E, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0xC0, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0 };
s32 D_80804A4C_chweldarboss[6] = { 0x3E4CCCCD, 0x0, 0x3ECCCCCD, 0x3F800000, 0x3F266666, 0x0 };
s32 D_80804A64_chweldarboss[6] = { 0x0, 0x0, 0x3ECCCCCD, 0x3F800000, 0x3F400000, 0x0 };
s32 D_80804A7C_chweldarboss[6] = { 0x0, 0x3F800000, 0x3ECCCCCD, 0x0, 0x3F400000, 0x3F800000 };
u8 D_80804A94_chweldarboss[16] = { 0x0, 0x13, 0x4, 0x9C, 0x0, 0x18, 0x0, 0xD, 0x0, 0x66, 0x0, 0x80, 0x0, 0x2, 0x0, 0x0 };
u8 D_80804AA4_chweldarboss[16] = { 0x0, 0x13, 0x6, 0x1C, 0x0, 0x18, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x0 };
u8 D_80804AB4_chweldarboss[8] = { 0x0, 0x13, 0x4, 0xA9, 0x0, 0x2, 0x0, 0x0 };
u8 D_80804ABC_chweldarboss[12] = { 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0xFF };
u8 D_80804AC8_chweldarboss[24] = { 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
