#include "common.h"

extern int D_80803B6C_chklungo[];
extern void _plcamera_entrypoint_8();
extern void _susubgame_entrypoint_0();
extern void _susubgame_entrypoint_1();
extern void _susubgame_entrypoint_12();
extern void func_800F608C();
extern void func_800FFAB0();
extern void func_80109FE8();
extern void *func_80100094(Actor *, s32);
extern u32 func_800F54E4(void);
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 26; u32 local_0 : 1; u32 pad_2 : 5; } Mass63KlungoFlags;
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 7; u32 local_0 : 1; u32 pad_2 : 24; } KlungoRouteActiveFlag1161;
typedef struct { u8 pad_0[8]; s16 local_0; } KlungoCompletion;
typedef struct { u8 pad_0[6]; s16 local_0; u8 pad_1[8]; s16 local_1; u8 pad_2[8]; s16 local_2; } KlungoDrawingState;
extern s32 _subaddiefade_entrypoint_0(Actor *);
extern void func_801017D0(Actor *);
extern void func_80101808(Actor *, void (*)(Actor *));
extern void func_800EFD24(f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern void _sudeflect_entrypoint_0(u8 *, f32, f32, s32);
extern void _subaddiefade_entrypoint_1(Actor *, s32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_808038A0_chklungo[];
typedef struct { u32 local_0; u32 local_1; } KlungoMatchEntry1358;
typedef struct { u8 pad_0[8]; KlungoMatchEntry1358 local_0[10]; u8 pad_1[0x2C]; } KlungoMatchRecord1358;
extern int D_80803BE0_chklungo[];
extern int D_80803BEC_chklungo[];
extern int D_80803C0C_chklungo[];
extern int D_80803C2C_chklungo[];
extern int D_80803BFC_chklungo[];
extern int D_80803C1C_chklungo[];
extern s32 D_80803C54_chklungo[];
extern s32 D_80803C3C_chklungo[];
extern s32 func_80101E4C(Actor *, void *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80018820(s32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
typedef union { f32 local_0[3]; s32 local_1[3]; } KlungoPositionWords1590;
extern s32 D_80803C74_chklungo[];
extern s32 D_80803C6C_chklungo[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void _chbaddiesetup_entrypoint_10(void);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern u8 D_80803C84_chklungo[];
extern s32 D_80803C98_chklungo[];
extern s32 D_80803CA8_chklungo[];
extern s32 D_80803CB8_chklungo[];
extern u8 D_80803CC0_chklungo[];
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 D_80803CF4_chklungo[];
extern u8 D_80803D04_chklungo[];
extern u8 D_80803D18_chklungo[];
extern u8 D_80803D28_chklungo[];
extern s32 _subaddieaudioloop_entrypoint_3(s32);
extern s32 _plcamera_entrypoint_10(u32);
extern void _plcamera_entrypoint_9(u32, f32 *, f32);
extern s32 func_800F5EF8(u32);
extern s32 func_80110014(s32);
extern void func_80116088(s32, f32 *);
typedef struct { u8 pad[0x24]; f32 f24; u8 pad28[0x4A]; u16 f72:6; u16 rest:10; } KlungoS;
extern f32 func_8010203C(KlungoS *, s32);
extern void func_80101CDC(KlungoS *, f32);
extern s32 D_80803D38_chklungo[];
extern void func_8010D09C(s32, f32 *, f32);
extern s32 func_800C6A7C(f32 *, f32 *, f32 *, u32);
extern s32 func_800CC5F4(s32);
extern f32 *func_800CC63C(s32, s32);
extern f32 func_800EEB40(f32 *, f32 *);
typedef union { s32 word; Actor *actor; } KlungoEventOwner;
typedef struct { f32 position[3]; s16 distance; } KlungoPathPoint;
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_8008FB58(f32 *, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, u16, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, u16, u32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void func_801058C4(Actor *, s32, f32, s32);
typedef struct { u8 pad0[8]; s16 unk8; u8 padA[0x10]; s16 unk1A; s16 unk1C; u8 pad1E[0xA]; s16 unk28; s16 unk2A; u8 pad2C[0x14]; s16 unk40; } KlungoData;
typedef union { s32 i; struct { s16 a; s16 b; } h; } KlungoArg;
typedef struct { u8 pad0[2]; u16 unk2; u8 pad4[0x80]; } KlungoTbl;
extern KlungoTbl D_808038A4_chklungo[];
extern u8 D_80803A3C_chklungo[];
extern void func_8010A800(Actor *, s32);
extern void func_80108B04(Actor *, s32);
extern void _gcdialogcamera_entrypoint_3();
extern void func_801032B0(Actor *, s32, s32);
extern void func_800FDC28(s32);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern s32 _suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _suexpression_entrypoint_17(s32, s32);
extern void _suexpression_entrypoint_8(Actor *, s32);
extern s32 func_800D395C(void);
typedef struct { u8 pad_0[0x1A]; s16 local_0; } KlungoReaction;
extern void func_800F4A58(s32, void *, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
void func_80801910_chklungo();
void func_808020F0_chklungo();
int func_8080242C_chklungo();
s32 func_80802558_chklungo();
s32 func_80802588_chklungo();
void func_8080299C_chklungo();
u8 func_80802DF4_chklungo();
void func_80802FCC_chklungo();
void func_808030A4_chklungo();
int func_80803158_chklungo();
void func_80803208_chklungo();
int func_80803304_chklungo();
f32 *func_80803390_chklungo();
void func_80803464_chklungo();
void func_80801680_chklungo();
void func_80801744_chklungo();
void func_80801964_chklungo();
void func_8080220C_chklungo();
void func_80802B84_chklungo();
extern void func_80107C2C(), func_80108ED0(), func_8080000C_chklungo(), func_808002D0_chklungo(), func_8080101C_chklungo(), func_808011B4_chklungo();
extern u8 D_80803A4C_chklungo[];

int *chklungo_entrypoint_0()
{
    return &D_80803B6C_chklungo;
}

void func_8080000C_chklungo(param_0) Actor *param_0;
{

  u8 *local_2;
  s32 local_0;
  local_2 = func_80100094(param_0, 0);
  *((s16 *) (((s8 *) local_2) + 8)) = func_8080242C_chklungo();
  if (func_800DA298((*((s16 *) (((s8 *) local_2) + 8))) + 0x318) != 0)
  {
    func_800FFAB0(param_0);
    return;
  }
  if (_glcutDll_entrypoint_20() != 0)
  {
    func_801032B0(param_0, 0x90C, 0);
    func_80801964_chklungo(param_0, 0xA);
    return;
  }
  func_80109FE8(param_0, 0);
  _subaddierouteDll_entrypoint_3(param_0, local_2 + 0x7C, param_0->position);
  _susubgame_entrypoint_0(param_0, (local_2 + 0x88), 0);
  _susubgame_entrypoint_12((local_2 + 0x88), ((s32 *) D_80803A3C_chklungo));
  _susubgame_entrypoint_1(param_0, (local_2 + 0x88), 0xC);
  func_808020F0_chklungo(param_0, 0);
  *((f32 *) (((s8 *) param_0) + 0x24)) = (f32) (*(f32 *)((D_808038A0_chklungo + 0x70) + *(s16 *)(local_2 + 8) * 0x84));
  *((s16 *) (((s8 *) local_2) + 2)) = 1;
  *((s16 *) (((s8 *) local_2) + 4)) = 0;
  *((s16 *) (((s8 *) local_2) + 0)) = (s16) (*((s16 *) (((s8 *) local_2) + 2)));
  *((s16 *) (((s8 *) local_2) + 0x10)) = func_80802DF4_chklungo(param_0);
  if ((*((s16 *) (((s8 *) local_2) + 8))) == 0)
  {
    *((s16 *) (((s8 *) local_2) + 0x22)) = 0;
  }
  else
  {
    *((s16 *) (((s8 *) local_2) + 0x22)) = 1;
  }
  if (((Mass63KlungoFlags *)param_0)->local_0)
  {
    ((KlungoRouteActiveFlag1161 *)param_0)->local_0 = 1;
    *((s16 *) (((s8 *) local_2) + 0x2C)) = _glsplinefind_entrypoint_0(0x3A1, local_2 + 0x30);
    _subaddiemarker_entrypoint_0(param_0, 0x3A1, local_2 + 0x4C, 1);
    _subaddiemarker_entrypoint_0(param_0, 0x154, (local_2 + 0x64), 1);
    if (func_800DA298(*(s16 *)((D_808038A0_chklungo + 0x2) + *(s16 *)(local_2 + 8) * 0x84)) != 0)
    {
      local_0 = func_800F54E4();
      *((s16 *) (((s8 *) local_2) + 0x2A)) = 1;
      func_800F608C(local_0, 1);
      func_800F8294(local_0, (local_2 + 0x64));
      func_800F497C(local_0);
      _plcamera_entrypoint_8(local_0);
      func_80802588_chklungo(param_0, 2, 1);
      func_80803158_chklungo(param_0, *(s16 *)((D_808038A0_chklungo + 0x76) + *(s16 *)(local_2 + 8) * 0x84), 0xE);
      func_80801964_chklungo(param_0, 8);
      *((s16 *) (((s8 *) local_2) + 0x42)) = 1;
      return;
    }
    if (func_800D395C() != 0)
    {
      if ((*((s16 *) (((s8 *) local_2) + 8))) == 2)
      {
        func_80803158_chklungo(param_0, 0x1633, 0x44);
        func_80801964_chklungo(param_0, 2);
      }
      func_80801964_chklungo(param_0, 5);
      return;
    }
    _chintrotext_entrypoint_2(1);
    if ((*((s16 *) (((s8 *) local_2) + 8))) == 2)
    {
      func_80801964_chklungo(param_0, 2);
    }
  }
}

s32 func_808034CC_chklungo();

f32 func_808031E4_chklungo();

void func_8080318C_chklungo();

void func_80802B10_chklungo();

void func_80802940_chklungo();

void func_80802914_chklungo();

void func_808028E8_chklungo();

void func_80802864_chklungo();

void func_80802798_chklungo();

void func_808026CC_chklungo();

void func_808025CC_chklungo();

void func_808018D4_chklungo();

s32 func_80801888_chklungo();

void func_808002D0_chklungo(param_0) Actor *param_0;
{
    extern u8 D_808038A0_chklungo[];
    extern u8 D_80803BB4_chklungo[];

    char *local_0;
    char *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7[3];
    f32 local_8;
    f32 local_9;

    local_0 = (char *)func_80100094(param_0, 0);
    local_1 = (char *)func_80100094(param_0, 1);

    func_800D9078(local_0 + 0xC);
    func_8080220C_chklungo(param_0);

    switch (param_0->unk70_10) {
        case 1:
            func_80801888_chklungo(param_0);
            func_80801910_chklungo(param_0);
            func_808026CC_chklungo(param_0);

            if (func_8010CA74(
                    (char *)param_0 + 4,
                    *(s16 *)((D_808038A0_chklungo + 0x7C) + *(s16 *)(local_0 + 8) * 0x84))) {
                if (func_800F64A4(func_800F54E4(), 1)) {
                    func_80801964_chklungo(param_0, 5);
                }
            }
            break;

        case 2:
            func_80801888_chklungo(param_0);

            if (func_8010CA74(
                    (char *)param_0 + 4,
                    *(s16 *)((D_808038A0_chklungo + 0x7C) + *(s16 *)(local_0 + 8) * 0x84))) {
                if (func_800F64A4(func_800F54E4(), 1)) {
                    func_80803158_chklungo(
                        param_0,
                        0x1633,
                        0x44
                    );
                    func_80801964_chklungo(param_0, 5);
                }
            }
            break;

        case 3:
            local_2 = func_800D8FF8();

            *(f32 *)((char *)param_0 + 0x34) -=
                local_2 * 1000.0f;

            *(f32 *)((char *)param_0 + 8) +=
                local_2 * *(f32 *)((char *)param_0 + 0x34);

            local_3 = *(f32 *)(local_0 + 0x3C);

            if (*(f32 *)((char *)param_0 + 8) < local_3) {
                *(f32 *)((char *)param_0 + 8) = local_3;
                func_80801964_chklungo(param_0, 4);
                func_80802940_chklungo(param_0);
            }
            break;

        case 4:
            if (func_80101DDC(param_0)) {
                func_80801964_chklungo(param_0, 8);
            }
            break;

        case 5:
            if (*(s16 *)(local_0 + 0x40) != 0) {
                break;
            }

        case 6:
        case 8:
            func_80801888_chklungo(param_0);
            func_808026CC_chklungo(param_0);
            break;

        case 27:
            func_808026CC_chklungo(param_0);
            break;

        case 7:
            func_80801888_chklungo(param_0);
            func_808026CC_chklungo(param_0);

            if (!func_800DA298(0x6AD)) {
                func_80802588_chklungo(param_0, 3, 1);

                func_80803158_chklungo(
                    param_0,
                    *(s16 *)((D_808038A0_chklungo + 0x74) + *(s16 *)(local_0 + 8) * 0x84),
                    0xE
                );

                func_80801964_chklungo(param_0, 8);
            }
            break;

        case 9:
            func_80802634_chklungo(param_0);

            if (func_80101DDC(param_0)) {
                func_800FDC28(0xB);

                func_800DA544(
                    *(s16 *)((D_808038A0_chklungo + 0x2) + *(s16 *)(local_0 + 8) * 0x84)
                );

                _gcfrontend_entrypoint_9(
                    *(s16 *)((u8 *)D_808038A4_chklungo + *(s16 *)(local_0 + 8) * 0x84)
                );

                func_800DA544(
                    *(s16 *)(local_0 + 0x10) + 0xC07
                );

                switch (*(s16 *)(local_0 + 0x10)) {
                case 1:
                    func_80801964_chklungo(param_0, 0xB);
                    func_80803158_chklungo(param_0, 0x1624, 4);
                    break;
                case 2:
                    func_80801964_chklungo(param_0, 0x10);
                    func_80803158_chklungo(param_0, 0x1625, 4);
                    break;
                case 3:
                    func_80801964_chklungo(param_0, 0x14);
                    func_80803158_chklungo(param_0, 0x1626, 4);
                    break;
                }
            }
            break;

        case 10:
            func_808026CC_chklungo(param_0);
            break;

        case 11:
            local_4 = func_80101F24(param_0);

            local_5 = func_800F12D4(
                local_4,
                0.0f,
                1.0f,
                1.0f,
                2.5f
            );

            local_5 *= *(f32 *)((char *)param_0 + 0x38);

            func_8008FB58(
                (char *)param_0 + 4,
                local_5 * 80.0f,
                local_5 * 100.0f
            );

            func_80802864_chklungo(param_0);

            if (func_80101DDC(param_0)) {

                *(f32 *)(local_0 + 0xC) =
                    func_800DC178(
                        *(f32 *)(D_808038A0_chklungo +
                            *(s16 *)(local_0 + 8) * 0x84 + 0x60),
                        *(f32 *)(D_808038A0_chklungo +
                            *(s16 *)(local_0 + 8) * 0x84 + 0x64)
                    );

                func_80802558_chklungo(param_0);
                func_80801964_chklungo(param_0, 0xC);
            }
            break;

        case 12:
            func_80801888_chklungo(param_0);
            func_808026CC_chklungo(param_0);

            if (*(f32 *)(local_0 + 0xC) == 0.0f) {
                func_808018D4_chklungo(param_0);
                func_80801964_chklungo(param_0, 0xF);

                if (*(u8 *)(local_0 + 0x49) == 0) {
                    *(u8 *)(local_0 + 0x49) = 1;
                    func_808025CC_chklungo(param_0, 4);
                }
            } else if (func_800D9078(
                    (char *)param_0 + 0x58)) {
                func_80801964_chklungo(param_0, 0xD);
            }
            break;

        case 13:
            local_4 = func_80101F24(param_0);

            local_6 = func_800F12D4(
                local_4,
                0.0f,
                0.5f,
                0.0f,
                1.0f
            );

            func_800EFE50(
                (char *)param_0 + 4,
                (char *)param_0 + 0x28,
                (char *)param_0 + 0x18,
                local_6
            );

            func_80802B10_chklungo(param_0);

            if (func_80101DDC(param_0)) {
                if (*(f32 *)(local_0 + 0xC) == 0.0f) {
                    func_808018D4_chklungo(param_0);
                    func_80801964_chklungo(param_0, 0xF);

                    if (*(u8 *)(local_0 + 0x49) == 0) {
                        *(u8 *)(local_0 + 0x49) = 1;
                        func_808025CC_chklungo(param_0, 4);
                    }
                } else {
                    func_80801964_chklungo(param_0, 0xC);
                }
            }
            break;

        case 14:
            if (func_80101DDC(param_0)) {
                func_80801964_chklungo(param_0, 0xF);
            }
            break;

        case 15:
            func_808028E8_chklungo(param_0);

            if (*(u8 *)(local_0 + 0x12) != 0) {
                func_80801910_chklungo(param_0);
            }

            if (func_80101DDC(param_0)) {
                if (*(u8 *)(local_0 + 0x12) != 0) {
                    func_80801964_chklungo(param_0, 0x1D);
                } else {
                    if (*(s16 *)(local_0 + 0x22) != 0) {
                        func_80802558_chklungo(param_0);
                    }

                    func_80801964_chklungo(param_0, 0x1C);
                }
            }
            break;

        case 16:
            func_808026CC_chklungo(param_0);

            if (_subaddiefade_entrypoint_0(param_0) == 0) {
                func_80802558_chklungo(param_0);

                *(f32 *)(local_0 + 0xC) =
                    func_800DC178(
                        *(f32 *)(D_808038A0_chklungo +
                            *(s16 *)(local_0 + 8) * 0x84 + 0x60),
                        *(f32 *)(D_808038A0_chklungo +
                            *(s16 *)(local_0 + 8) * 0x84 + 0x64)
                    );

                func_80801964_chklungo(param_0, 0x11);
            }
            break;

        case 17:
            func_8080318C_chklungo(param_0);
            func_80803208_chklungo(param_0);

            if (*(f32 *)(local_0 + 0xC) == 0.0f) {
                func_808020F0_chklungo(param_0, 5);
                func_80801964_chklungo(param_0, 0x1C);
            }

            local_8 = func_808031E4_chklungo(param_0);

            _subaddierouteDll_entrypoint_7(
                param_0,
                local_0 + 0x7C,
                *(f32 *)((char *)param_0 + 0x48),
                *(f32 *)((char *)param_0 + 0x54),
                local_8,
                0x4802
            );

            _subaddierouteDll_entrypoint_6(
                param_0,
                local_0 + 0x7C,
                *(u16 *)(local_0 + 0x82),
                0x3F,
                0.7f,
                0x28,
                0x64
            );

            _subaddierouteDll_entrypoint_5(
                param_0,
                local_0 + 0x7C,
                *(u16 *)(local_0 + 0x82),
                0.15f,
                4.0f,
                120.0f
            );

            func_8010B990(param_0, 0x1305);
            break;

        case 18:
            if (func_80101DDC(param_0)) {
                if (*(u8 *)(local_0 + 0x12) != 0) {
                    func_80801964_chklungo(param_0, 0x1D);
                } else {
                    func_80802558_chklungo(param_0);
                    func_80801964_chklungo(param_0, 0x1C);
                }
            }
            break;

        case 19:
            func_800EFD24(local_7);

            *(f32 *)((char *)param_0 + 0x54) =
                func_80102D78(param_0, local_7);

            _subaddierouteDll_entrypoint_5(
                param_0,
                local_0 + 0x7C,
                0,
                0.15f,
                4.0f,
                120.0f
            );

            func_8010B990(param_0, 0x1305);
            func_80803208_chklungo(param_0);

            if (func_808034CC_chklungo(param_0)) {
                func_80109FE8(param_0, 1);
                func_80801964_chklungo(param_0, 0x14);
            }
            break;

        case 20:
            func_808026CC_chklungo(param_0);
            break;

        case 21:
        case 22:
            func_80802914_chklungo(param_0);

            if (func_80101DDC(param_0)) {
                if (!_subaddieskeleton_entrypoint_0(param_0, 3, param_0->position) ||
                    func_800CBD84(param_0->position) == -1) {
                    if (param_0->unk70_10 == 0x15) {
                        local_9 = 90.0f;
                    } else {
                        local_9 = -90.0f;
                    }

                    func_800EF1B8(
                        (char *)param_0 + 4,
                        *(f32 *)((char *)param_0 + 0x48) +
                            local_9,
                        150.0f
                    );
                }

                func_80101180(0x41E, 0xA, 0);
                func_80801964_chklungo(param_0, 0x17);
            }
            break;

        case 23:
            func_8080318C_chklungo(param_0);
            func_80803208_chklungo(param_0);

            if (*(f32 *)(local_0 + 0xC) == 0.0f &&
                *(s16 *)(local_0 + 0x1A) == 0) {
                func_80101180(0x41E, 0x2C, 0);
            }

            local_8 = func_808031E4_chklungo(param_0);

            _subaddierouteDll_entrypoint_7(
                param_0,
                local_0 + 0x7C,
                *(f32 *)((char *)param_0 + 0x48),
                *(f32 *)((char *)param_0 + 0x54),
                local_8,
                0x4802
            );

            _subaddierouteDll_entrypoint_6(
                param_0,
                local_0 + 0x7C,
                *(u16 *)(local_0 + 0x82),
                0x3F,
                0.6f,
                0x28,
                0x3C
            );

            _subaddierouteDll_entrypoint_5(
                param_0,
                local_0 + 0x7C,
                *(u16 *)(local_0 + 0x82),
                0.15f,
                4.0f,
                120.0f
            );

            func_8010B990(param_0, 0x1325);
            break;

        case 24:
            if (func_80101DDC(param_0)) {
                func_80801964_chklungo(param_0, *(u8 *)(local_0 + 0x12) ? 0x1D : 0x1A);
            }
            break;

        case 26:
            func_80801888_chklungo(param_0);
            func_808026CC_chklungo(param_0);

            if (_subaddiefind_entrypoint_9(0x41E) == 1) {
                func_80109FE8(param_0, 1);
                func_80801964_chklungo(param_0, 0x1C);
            }
            break;

        case 28:
            func_80801888_chklungo(param_0);

            if (func_80101E14(param_0, 0.75f)) {
                func_80108B04(param_0, 0);
            }

            if (*(s16 *)(local_0 + 6) == 1) {
                *(s16 *)(local_0 + 6) =
                    *(s16 *)(local_0 + 6) + 1;
            }

            if (func_80101E14(param_0, 0.999f)) {
                *(s16 *)(local_0 + 2) =
                    *(s16 *)(local_0 + 2) - 1;

                if (*(s16 *)(local_0 + 2) == 0) {
                    switch (*(s16 *)(local_0 + 0x10)) {
                    case 1:
                        func_80801964_chklungo(param_0, 0xB);
                        break;
                    case 2:
                        func_80801964_chklungo(param_0, 0x10);
                        break;
                    case 3:
                        func_80801964_chklungo(param_0, func_808034CC_chklungo(param_0) ? 0x14 : 0x13);
                        break;
                    }

                    func_80101180(0x421, 0x2C, 0);
                    *(s16 *)(local_0 + 0x44) = 0;
                }

                *(s16 *)(local_0 + 6) = 0;
            }
            break;

        case 29:
            func_80801910_chklungo(param_0);
            func_80802798_chklungo(param_0);

            if (func_80101DDC(param_0)) {
                func_80801964_chklungo(param_0, 0x1E);
            }
            break;

        case 31:
            func_80801910_chklungo(param_0);

            if (func_800D9078(
                    (char *)param_0 + 0x58)) {
                func_80801964_chklungo(param_0, 0x20);
            }
            break;

        case 32:
            func_80801910_chklungo(param_0);

            _subaddieaudioquick_entrypoint_3(
                param_0,
                (char *)param_0 + 4,
                D_80803BB4_chklungo,
                0.2f
            );

            if (func_80101DDC(param_0)) {
                func_80801964_chklungo(param_0, 0x21);
            }
            break;

        case 33:
            func_80801910_chklungo(param_0);
            func_808026CC_chklungo(param_0);

            if (func_800D9078(
                    (char *)param_0 + 0x58)) {
                func_80801964_chklungo(param_0, 0x22);
            }
            break;

        case 34:
            func_808026CC_chklungo(param_0);
            func_80801910_chklungo(param_0);
            break;

        case 35:
            func_80801910_chklungo(param_0);

            *(s16 *)(local_0 + 0x20) =
                *(s16 *)(local_0 + 0x20) + 1;

            if (*(s16 *)(local_0 + 0x20) == 1) {
                local_9 = *(f32 *)(local_0 + 0x5C);

                *(f32 *)((char *)param_0 + 0x54) = local_9;
                *(f32 *)((char *)param_0 + 0x48) = local_9;

                func_800EE7F8(
                    (char *)param_0 + 4,
                    local_0 + 0x30
                );

                func_801058C4(
                    param_0,
                    *(s16 *)(local_0 + 0x2C),
                    3e+02f,
                    1
                );

                func_80105BAC(param_0);
            }
            break;
    }

    func_808030A4_chklungo(param_0);

    if (local_1 != 0) {
        if (func_801022E4(param_0) != 0x264) {
            _suexpression_entrypoint_18(local_1, 1);
        }

        _suexpression_entrypoint_10(
            local_1,
            *(s32 *)((char *)param_0 + 0),
            0
        );
    }
}

void func_8080101C_chklungo(param_0) Actor *param_0;
{
    void *local_0;

    local_0 = func_80100094(param_0, 1);
    func_80105834(param_0);
    func_80803208_chklungo(param_0);
    func_80801910_chklungo(param_0);
    if (func_80105A5C(param_0)) {
        func_80802558_chklungo(param_0);
        if (func_800D395C()) {
            _gcfrontend_entrypoint_10();
        } else if (((KlungoCompletion *)func_80100094(param_0, 0))->local_0 == 2) {
            _glcutDll_entrypoint_6(0x15D, 0x5B);
        }
        func_800FFAB0(param_0);
    }
    if (local_0) _suexpression_entrypoint_10(local_0, param_0->unk0, 0);
}

void func_808010E0_chklungo(Actor *param_0, s32 param_1)
{
    KlungoDrawingState *local_0;

    local_0 = func_80100094(param_0, 0);
    func_801015D0(param_0);
    switch (param_0->unk70_10) {
        case 9: func_800DF744(3, local_0->local_1); break;
        case 0x1C: func_800DF744(3, local_0->local_0 == 2 ? 0 : 4); break;
        default: func_800DF744(3, 0); break;
    }
    if (local_0->local_2) {
        func_800DF5D8(0xE0, 0xE0, 0xFF, _subaddiefade_entrypoint_0(param_0));
    }
}

void func_808011B4_chklungo(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_0->unk70_10) {
        case 0xD: case 0x15: case 0x16:
            func_800DF440(0);
            break;
        default:
            func_800DF440(1);
            break;
    }
    func_80101808(param_0, func_801017D0);
}

s32 func_80801848_chklungo();

s32 func_80801220_chklungo(Actor *param_0, s32 param_1, KlungoArg param_2)
{
    KlungoData *local_0;
    s32 local_1;
    KlungoArg *local_2;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2E:
        local_2 = &param_2;
        func_80801744_chklungo(param_0, local_2->h.a, local_2->h.b);
        break;
    case 0xB:
        switch (func_80802480_chklungo(param_0, param_2.i)) {
        case 2:
            func_80801964_chklungo(param_0, 9);
            return 4;
        case 6:
            func_80801964_chklungo(param_0, 0x1F);
            return 4;
        }
        return 3;
    case 0x40:
        local_2 = &param_2;
        func_80801680_chklungo(param_0, local_2->i);
        break;
    case 0x3D:
        func_80802B84_chklungo(param_0, param_2.i);
        break;
    case 0x2C:
        if (local_0->unk1A) {
            func_80801964_chklungo(param_0, 0x19);
            break;
        }
        func_8010A800(param_0, 0);
        if (param_2.i) {
            break;
        }
        if (local_0->unk28 == 0) {
            local_0->unk28 = 1;
            func_80803158_chklungo(param_0, 0x1631, 0x44);
        }
        func_80801964_chklungo(param_0, 0x1A);
        break;
    case 0xA:
        if (local_0->unk1A) {
            return 0;
        }
        if (local_0->unk1C == 0) {
            func_80802558_chklungo(param_0);
            func_80801964_chklungo(param_0, 0x17);
            func_8010A800(param_0, 0);
            return 0;
        }
        local_0->unk1C--;
        func_80108B04(param_0, 2);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80803A3C_chklungo, *(s32 *)&param_0->scale);
        break;
    case 0x32:
        if (local_0->unk40 == 0) {
            func_80801964_chklungo(param_0, 7);
        }
        break;
    case 0x57:
        return func_80801848_chklungo(param_0, param_2.i & 0xFFFF, (param_2.i & 0xFFFF0000) >> 16);
    case 0x95:
        func_801032B0(param_0, D_808038A4_chklungo[local_0->unk8].unk2, 0);
        if (local_0->unk2A) {
            func_800FDC28(1);
            local_0->unk2A = 0;
        }
        _subaddierouteDll_entrypoint_1(param_0);
        break;
    case 0x29:
        if (local_0->unk1A == 0) {
            local_1 = _suexpression_entrypoint_7(param_0, 1, 0xAB);
            _suexpression_entrypoint_12(local_1, 70.0f, 30.0f);
            _suexpression_entrypoint_17(local_1, 1000);
        }
        break;
    case 0x2A:
        if (local_0->unk1A == 0) {
            _suexpression_entrypoint_8(param_0, 1);
        }
        break;
    case 0x1F:
        local_2 = &param_2;
        func_808010E0_chklungo(param_0, local_2->i);
        break;
    case 0x96:
        if (local_0->unk1A || !func_800D395C()) {
            return 0;
        }
        func_80803158_chklungo(param_0, 0xCEB, 0x4E);
        break;
    case 0x9F:
        if (local_0->unk1A) {
            func_80801964_chklungo(param_0, 0x19);
            return 0;
        }
        func_800FDC28(0);
        func_80801964_chklungo(param_0, 8);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_8080162C_chklungo(param_0) s32 param_0;
{
    s32 local_0;

    local_0 = func_80100094(param_0, 0);
    func_80802FCC_chklungo(param_0);
    func_80802558_chklungo(param_0);
    if (*(s16*)((char*)local_0 + 0x1A) == 0) {
        _suexpression_entrypoint_8(param_0, 1);
    }
}

void func_80801680_chklungo(param_0, param_1) Actor *param_0; s32 param_1;
{
    KlungoReaction *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 12:
    case 13:
        func_80801964_chklungo(param_0, 14);
        break;
    case 16:
    case 17:
        func_80801964_chklungo(param_0, 18);
        break;
    case 23:
        if (local_0->local_0 == 0) {
            func_80801964_chklungo(param_0, 24);
            func_800FC6B0(14);
            func_80101180(0x41E, 0x2C, 1);
        } else {
            func_800FC6B0(15);
            func_80101180(0x41E, 0x2C, 0);
        }
        break;
    }
}

void func_80801744_chklungo(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
        case 0x1622: case 0x1623: case 0x1628: case 0x1629: case 0x162B: case 0x162C:
            func_80801964_chklungo(param_0, 6);
            break;
        case 0x1627: case 0x162A: case 0x162D:
            func_80801964_chklungo(param_0, 35);
            break;
        case 0x162F:
            func_80802558_chklungo(param_0);
            func_80801964_chklungo(param_0, 28);
            break;
        case 0x1633:
            func_80803158_chklungo(param_0, 0x1634, 0x4E);
            func_808025CC_chklungo(param_0, 1);
            func_80801964_chklungo(param_0, 3);
            break;
        case 0x1634:
            func_80801964_chklungo(param_0, 7);
            break;
        case 0xCEB:
            if (param_2 > 0) _gcfrontend_entrypoint_11();
            else _gcfrontend_entrypoint_10();
            break;
        case 0x1624: case 0x1625: case 0x1626: case 0x1630: case 0x1631: case 0x1632: case 0x1635: case 0x1636: case 0x1637:
            break;
        default:
            func_80801964_chklungo(param_0, 1);
            break;
    }
}

s32 func_80801848_chklungo(s32 param_0, s32 param_1, s32 param_2){
    s32 local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_3(param_0, local_0 + 0x88, param_1, param_2);
}

s32 func_80801888_chklungo(Actor *this) {
    f32 sp1C[3];

    func_8010D600(sp1C);
    *(f32 *)((char *)this + 0x54) = func_80102D78(this, sp1C);
    return func_80102BF8(this, 0x3e19999a, 0x40800000, 0x43480000);
}

void func_808018D4_chklungo(u8 *param_0) {
    f32 local_0[3];
    f32 local_1;

    func_800EFD24(local_0);
    local_1 = func_80102D78(param_0, local_0);
    *(f32 *)(param_0 + 0x54) = local_1;
    *(f32 *)(param_0 + 0x48) = local_1;
}

void func_80801910_chklungo(param_0) u8 *param_0; {
    _sudeflect_entrypoint_0(param_0 + 4, *(f32 *)(param_0 + 0x38) * 100.0f, *(f32 *)(param_0 + 0x38) * 130.0f, 2);
}

void func_8080322C_chklungo(u8 *param_0, f32 param_1);

void func_80803000_chklungo();

void func_80802F30_chklungo();

void func_80801964_chklungo(param_0, param_1) Actor *param_0; s32 param_1;
{
    extern u8 D_808038A0_chklungo[];
    extern u8 D_80803A2C_chklungo[];
    extern u8 D_80803BC0_chklungo[];
    extern u8 D_80803BD0_chklungo[];
    extern void func_8010D5DC(void);

    s32 local_1;
    s32 local_2;
    s32 local_3;
    char *local_0;
    s32 local_4;
    f32 local_6;

    local_1 = param_0->unk70_10;
    local_2 = 0;
    local_3 = 0;

    local_0 = (char *)func_80100094(param_0, 0);

    func_80102424(param_0, param_1);
    func_8080305C_chklungo(param_0);

    switch (param_1) {
        case 2:
            *(f32 *)(local_0 + 0x3C) =
                *(f32 *)((char *)param_0 + 8);
            *(s16 *)(local_0 + 0x40) = 1;
            *(f32 *)((char *)param_0 + 8) += 2500.0f;
            break;

        case 5:
            local_4 = func_800F54E4();

            func_808025CC_chklungo(param_0, 0);
            func_800F497C(local_4);
            func_800F49A8(local_4, 1);

            func_800F49D4(
                local_4,
                func_8010D5DC,
   
                *(s32 *)((char *)param_0 + 0)
            );

        func_800F4A58(
                local_4,
                local_0 + 0x64,
                *(s16 *)(local_0 + 0x40) ? 0xDC : 0x12C
            );

            func_800FDC28(1);
            break;

        case 6:
            if (*(s16 *)(local_0 + 0x42) != 0) {
                func_80801964_chklungo(param_0, 9);
            } else {
                func_808025CC_chklungo(param_0, 2);
            }

            func_80101180(0x41F, 8, 0);
            break;

        case 7:
            _chintrotext_entrypoint_1(
                0x18B9,
                *(s16 *)(local_0 + 8) + 0xB,
                1,
                0
            );
            break;

        case 9:
            func_808025CC_chklungo(param_0, 3);
            break;

        case 12:
            *(f32 *)((char *)param_0 + 0x58) =
                func_800DC178(
                    *(f32 *)(D_808038A0_chklungo + *(s16 *)(local_0 + 8) * 0x84 + 0x68),
                    *(f32 *)(D_808038A0_chklungo + *(s16 *)(local_0 + 8) * 0x84 + 0x6C)
                );

            if (local_1 == 0xB) {
                *(f32 *)((char *)param_0 + 0x58) = 1.0f;
            }

            local_2 = 1;
            break;

        case 13:
            local_6 = 0.0f;
            switch (*(s16 *)(local_0 + 8)) {
                case 0: local_6 = -1.0f; break;
                case 1: break;
                case 2: local_6 = 1.0f; break;
            }

            _subaddieaudioquick_entrypoint_2(
                param_0,
                (char *)param_0 + 4,
                D_80803BC0_chklungo
            );

            func_8080322C_chklungo(param_0, local_6);

            func_800EE7F8(
                (char *)param_0 + 0x28,
                (char *)param_0 + 4
            );

            local_2 = 1;
            break;

        case 14:
            *(s16 *)(local_0 + 4) =
                *(s16 *)(local_0 + 4) + 1;

            if (*(s16 *)(local_0 + 4) == 3) {
                *(u8 *)(local_0 + 0x12) = 1;
            }

            if (*(u8 *)(local_0 + 0x49) == 0 ||
                *(u8 *)(local_0 + 0x12) != 0) {
                *(u8 *)(local_0 + 0x49) = 1;
                func_808018D4_chklungo(param_0);
                func_808025CC_chklungo(param_0, 4);
            }

            func_80802FCC_chklungo(param_0);

            _subaddieaudioquick_entrypoint_2(
                param_0,
                (char *)param_0 + 4,
                D_80803A2C_chklungo
            );
            break;

        case 15:
            if (local_1 != 0xE &&
                *(s16 *)(local_0 + 0x26) == 0) {
                func_80803158_chklungo(
                    param_0,
                    0x1632,
                    0x44
                );

                *(s16 *)(local_0 + 0x26) = 1;
            }
            break;

        case 16:
            func_80802F30_chklungo(param_0);
            func_808020F0_chklungo(param_0, 1);
            break;

        case 17:
            *(f32 *)((char *)param_0 + 0x24) =
                *(f32 *)((D_808038A0_chklungo + 0x70) + *(s16 *)(local_0 + 8) * 0x84);

            *(f32 *)((char *)param_0 + 0x54) =
                *(f32 *)((char *)param_0 + 0x48);

            local_2 = 1;
            break;

        case 18:
            *(s16 *)(local_0 + 4) =
                *(s16 *)(local_0 + 4) + 1;

            if (*(s16 *)(local_0 + 4) == 3) {
                *(u8 *)(local_0 + 0x12) = 1;
            }

            func_80802FCC_chklungo(param_0);

            _subaddieaudioquick_entrypoint_2(
                param_0,
                (char *)param_0 + 4,
                D_80803A2C_chklungo
            );

            func_808020F0_chklungo(param_0, 5);
            break;

        case 19:
        case 26:
            func_80109FE8(param_0, 0);
            break;

        case 20:
            switch (*(s16 *)(local_0 + 4)) {
                case 0: *(s16 *)(local_0 + 0x1C) = 1; break;
                case 1: *(s16 *)(local_0 + 0x1C) = 2; break;
                case 2: *(s16 *)(local_0 + 0x1C) = 3; break;
            }

            *(s16 *)(local_0 + 0x1C) =
                *(s16 *)(local_0 + 0x1C) - 1;

            func_80108B04(param_0, 2);
            func_8010A800(param_0, 2);
            break;

        case 23:
            *(f32 *)(local_0 + 0xC) =
                func_800DC178(
                    *(f32 *)(D_808038A0_chklungo + *(s16 *)(local_0 + 8) * 0x84 + 0x60),
                    *(f32 *)(D_808038A0_chklungo + *(s16 *)(local_0 + 8) * 0x84 + 0x64)
                );

            local_2 = 1;
            break;

        case 24:
            *(s16 *)(local_0 + 4) =
                *(s16 *)(local_0 + 4) + 1;

            if (*(s16 *)(local_0 + 4) == 3) {
                *(u8 *)(local_0 + 0x12) = 1;
            }

            func_80802FCC_chklungo(param_0);

            _subaddieaudioquick_entrypoint_2(
                param_0,
                (char *)param_0 + 4,
                D_80803A2C_chklungo
            );
            break;

        case 25:
            func_8010A570(param_0);
            _subaddiefade_entrypoint_3(param_0);
            func_8010A800(param_0, 2);
            break;

        case 28:
            if (*(s16 *)(local_0 + 0x22) == 0) {
                func_80801964_chklungo(param_0, 0x1B);
                func_808025CC_chklungo(param_0, 9);

                func_80803158_chklungo(
                    param_0,
                    0x162F,
                    0xE
                );

                func_80108B04(param_0, 1);

                *(s16 *)(local_0 + 0x22) = 1;
            } else {
                local_3 = 1;

                if (!func_800DA298(0x685)) {
                    switch (*(s16 *)(local_0 + 4)) {
                        case 0:
                            *(s16 *)(local_0 + 0) = *(s16 *)(local_0 + 2) = 3;
                            break;
                        case 1:
                            *(s16 *)(local_0 + 0) = *(s16 *)(local_0 + 2) = 5;
                            break;
                        case 2:
                            *(s16 *)(local_0 + 0) = *(s16 *)(local_0 + 2) = 7;
                            break;
                    }
                } else {
                    *(s16 *)(local_0 + 2) = 10000;
                    *(s16 *)(local_0 + 0) =
                        *(s16 *)(local_0 + 2);
                }

                *(s16 *)(local_0 + 6) = 0;

                if (*(s16 *)(local_0 + 0x44) == 0) {
                    func_80108B04(param_0, 1);
                }
            }
            break;

        case 29:
            func_800FDC28(0);
            func_80802FCC_chklungo(param_0);

            _subaddieaudioquick_entrypoint_2(
                param_0,
                (char *)param_0 + 4,
                D_80803BD0_chklungo
            );

            func_808018D4_chklungo(param_0);
            func_808025CC_chklungo(param_0, 5);
            func_8010A570(param_0);

            func_80101180(0x423, 0x4F, 0);

            func_800DA544(
                *(s16 *)(local_0 + 8) + 0x318
            );
            break;

        case 30:
            func_808025CC_chklungo(param_0, 6);
            func_80101180(0x41F, 7, 0);
            func_80101180(0x420, 7, 0);
            break;

        case 31:
            func_808025CC_chklungo(param_0, 7);
            *(f32 *)((char *)param_0 + 0x58) = 1.4f;
            break;

        case 33:
            *(f32 *)((char *)param_0 + 0x58) = 3.0f;
            break;

        case 34:
            func_80802588_chklungo(param_0, 3, 1);

            func_80803158_chklungo(
                param_0,
                *(s16 *)((D_808038A0_chklungo + 0x78) + *(s16 *)(local_0 + 8) * 0x84),
                0xE
            );
            break;

        case 35:
            func_808025CC_chklungo(param_0, 8);

            func_80803158_chklungo(
                param_0,
                *(s16 *)((D_808038A0_chklungo + 0x7A) + *(s16 *)(local_0 + 8) * 0x84),
                0x44
            );
            break;
    }

    func_80109FE8(param_0, local_2);

    if (local_3 != 0) {
        func_80803000_chklungo(param_0);
    }
}

void func_808020F0_chklungo(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    *(s16 *)(local_0 + 0x18) = param_1;
    switch (param_1) {
    case 0:
        _subaddiefade_entrypoint_1(param_0, 255);
        break;
    case 2:
        switch (*(s16 *)(local_0 + 8)) {
        case 0: *(f32 *)(local_0 + 0x14) = func_800DC178(1.0f, 2.0f); break;
        case 1: *(f32 *)(local_0 + 0x14) = func_800DC178(2.0f, 3.0f); break;
        case 2: *(f32 *)(local_0 + 0x14) = func_800DC178(3.0f, 4.0f); break;
        }
        break;
    case 4:
        *(f32 *)(local_0 + 0x14) = func_800DC178(1.5f, 2.0f);
        break;
    }
}

void func_80802F58_chklungo();

s32 func_808023A4_chklungo(Actor *param_0, f32 param_1, f32 param_2);

s32 func_8080231C_chklungo(Actor *param_0, f32 param_1, f32 param_2);

void func_8080220C_chklungo(param_0) Actor *param_0;
{
    u8 *local_0;
    local_0 = (u8 *)func_80100094(param_0, 0);
    switch (*(u16 *)(local_0 + 0x18)) {
    case 0:
        break;
    case 1:
        if (func_8080231C_chklungo(param_0, 0.0f, 150.0f)) func_808020F0_chklungo(param_0, 2);
        break;
    case 2:
        if (func_800D9078((f32 *)(local_0 + 0x14))) {
            func_80802F58_chklungo(param_0);
            func_808020F0_chklungo(param_0, 3);
        }
        break;
    case 3:
        if (func_808023A4_chklungo(param_0, 48.0f, 150.0f)) func_808020F0_chklungo(param_0, 4);
        break;
    case 4:
        if (func_800D9078((f32 *)(local_0 + 0x14))) func_808020F0_chklungo(param_0, 1);
        break;
    case 5:
        if (func_808023A4_chklungo(param_0, 255.0f, 150.0f)) func_808020F0_chklungo(param_0, 0);
        break;
    }
}

s32 func_8080231C_chklungo(Actor *param_0, f32 param_1, f32 param_2)
{
    s32 local_0;
    f32 local_1;

    local_0 = 0;
    local_1 = (f32)_subaddiefade_entrypoint_0(param_0);
    local_1 -= func_800D8FF8() * param_2;
    if (local_1 < param_1) {
        local_1 = param_1;
        local_0 = 1;
    }
    _subaddiefade_entrypoint_1(param_0, (s32)local_1);
    return local_0;
}

s32 func_808023A4_chklungo(Actor *param_0, f32 param_1, f32 param_2)
{
    s32 local_0;
    f32 local_1;

    local_0 = 0;
    local_1 = (f32)_subaddiefade_entrypoint_0(param_0);
    local_1 += func_800D8FF8() * param_2;
    if (param_1 < local_1) {
        local_1 = param_1;
        local_0 = 1;
    }
    _subaddiefade_entrypoint_1(param_0, (s32)local_1);
    return local_0;
}

int func_8080242C_chklungo()
{
  s32 local_0;
  s32 local_1;
 do { local_0 = func_800EA05C(); local_1 = 0; while (1) { if (local_0 == (*((s16 *) (((char *) D_808038A0_chklungo) + ((22 * local_1) * 6))))) { return local_1; } local_1 += 1; if (local_1 == 3) { return -1; } } } while (0);
}

int func_80802480_chklungo(Actor *param_0, u32 param_1)
{
    s16 *local_0;

    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    for (local_2 = 0; local_2 < 10; local_2++) {
        if (param_1 == (&((KlungoMatchRecord1358 *)D_808038A0_chklungo)[local_0[4]])->local_0[local_2].local_0) {
            return local_2;
        }
    }
    return -1;
}

s32 func_80802558_chklungo(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_4(param_0, local_0 + 0x88);
}

s32 func_80802588_chklungo(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    s32 local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    _susubgame_entrypoint_5(param_0, local_0 + 0x88, param_1, param_2, local_1);
}

void func_808025CC_chklungo(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 *local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = (s32 *)(D_808038A0_chklungo + *(s16 *)(local_0 + 8) * 0x84 + param_1 * 8);
    local_3 = local_1[3];
    local_2 = local_1[2];
    _susubgame_entrypoint_6(param_0, local_0 + 0x88, local_2, local_3, 0);
}

int func_80802634_chklungo(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80803BE0_chklungo, 0.2f);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80803BEC_chklungo, 0.78f);
  _subaddieaudioquick_entrypoint_4(local_0, local_0 + 4, &D_80803C0C_chklungo, &D_80803C2C_chklungo);
  _subaddieaudioquick_entrypoint_4(local_0, local_0 + 4, &D_80803BFC_chklungo, &D_80803C1C_chklungo);
}

void func_808026CC_chklungo(Actor *param_0)
{
    if (func_80101E4C(param_0, &D_80803C54_chklungo)) {
        func_80018820(0, 0.8f, 0.3f);
        func_800E15CC(0, 0x40A00000, 0x3F333333);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80803C3C_chklungo);
        return;
    }
    if (func_80101E14(param_0, 0.7f)) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80803C3C_chklungo);
    }
}

void func_80802798_chklungo(Actor *param_0)
{
    KlungoPositionWords1590 local_0;

    _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80803C74_chklungo, 0.7f);
    if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80803C6C_chklungo, 0.8f)) {
        func_800EE7F8(local_0.local_0, param_0->position);
        local_0.local_0[1] += 80.0f;
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5,
            local_0.local_1[0], local_0.local_1[1], local_0.local_1[2], *(s32 *)&param_0->rotation[1]);
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
    }
}

void func_80802864_chklungo(Actor *param_0)
{
    u8 *local_0;

    if (func_80101E14(param_0, 0.0f)) {
        local_0 = func_80100094(param_0, 0);
        if (local_0[0x48] == 0) {
            local_0[0x48] = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
        }
        func_800C4350(local_0[0x48], param_0->position, D_80803C84_chklungo);
        func_800C3BDC(local_0[0x48]);
    }
}

void func_808028E8_chklungo(u8 *param_0) {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80803C98_chklungo, 0.0f);
}

void func_80802914_chklungo(u8 *param_0) {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80803CA8_chklungo, 0.0f);
}

void func_80802940_chklungo(s32 param_0)
{
    func_8080299C_chklungo(param_0);
    func_80018820(0, 1.0f, 0.4f);
    func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80803CB8_chklungo);
}

void func_8080299C_chklungo(param_0) Actor *param_0;
{
    s32 local_2;
    s32 local_3;
    u8 *local_1;
    f32 local_0[2];
    f32 *local_4;
    local_1 = func_80100094(param_0, 0);
    local_2 = func_800B53A4(8);
    func_800BAB80(local_2, D_808038A0_chklungo + *(s16 *)(local_1 + 8) * 0x84 + 0x7E);
    local_4 = param_0->position;
    for (local_3 = 0; local_3 < 8; local_3++) {
        func_800EEB9C(local_0, local_3 * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(local_0, local_4);
        local_0[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(local_2, local_0, local_4, 1.0f, &D_80803CC0_chklungo);
    }
}

void func_80802B10_chklungo(Actor *param_0)
{
    if (func_80101E14(param_0, 0.8f)) {
        func_8080299C_chklungo(param_0);
        func_800E15CC(0, 0x41F00000, 0x3F666666);
        func_80018820(0, 1.5f, 0.6f);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80803CF4_chklungo);
    }
}

void func_80802B84_chklungo(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    Actor *local_1;
    f32 local_2[3];
    s32 pad;
    f32 local_3[3];
    Actor *local_4;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0:
        if (!_subaddieskeleton_entrypoint_2(*(u32 *)param_0, 4, local_2)) {
            func_80103DFC(param_0, local_2);
        }
        local_1 = func_80108528(0x422, local_2, (s32)*(f32 *)((u8 *)param_0 + 0x48), &param_0);
        *(f32 *)((u8 *)local_1 + 0x44) = 180.0f;
        if (func_800DA298(0x683)) {
            *(f32 *)((u8 *)local_1 + 0x24) = *(f32 *)((D_808038A0_chklungo + 0x58) + *(s16 *)(local_0 + 8) * 0x84);
        } else {
            *(f32 *)((u8 *)local_1 + 0x24) = 0.3f;
        }
        if (!func_800DA298(0x684)) {
            *(f32 *)((u8 *)local_1 + 0x58) = *(f32 *)((D_808038A0_chklungo + 0x5C) + *(s16 *)(local_0 + 8) * 0x84);
        } else {
            *(f32 *)((u8 *)local_1 + 0x58) = 0.2f;
        }
        func_80102FDC(local_1, param_0->scale);
        *(s16 *)(local_0 + 6) = 1;
        return;
    case 1:
        func_80103DFC(param_0, local_3);
        func_80102FDC(func_80108528(0x421, local_3, 0, &param_0), param_0->scale * 1.4f);
        *(s16 *)(local_0 + 0x44) = 1;
        return;
    case 2: {
        u8 *local_5;
        if (param_0->unk70_10 != 0x14) {
            func_8010A800(param_0, 0);
            return;
        }
        local_4 = func_801084B0(0x41E, &param_0);
        if ((*(u32 *)((u8 *)local_4 + 0x70) >> 25) == 0) {
            func_800FFAB0(local_4);
            func_80101180(0x41E, 0xA, 0);
            return;
        }
        local_5 = func_80100094(local_4, 0);
        *(s16 *)(local_0 + 0x1E) ^= 1;
        *(s16 *)(local_5 + 0x1A) = 1;
        func_80100120(local_4);
        func_80102FDC(local_4, param_0->scale);
        func_80801964_chklungo(local_4, *(s16 *)(local_0 + 0x1E) == 0 ? 0x16 : 0x15);
        return;
    }
    }
}

u8 func_80802DF4_chklungo(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    u8 local_6;

    local_0 = *(s16 *)((u8 *)func_80100094(param_0, 0) + 8);
    local_1 = func_800DA564(0x315, 3);
    if (local_1 == 0) {
        if (func_800D395C()) {
            local_2 = func_800DC128(0, func_800DA980(0xC08, 3));
            local_3 = 0;
            local_4 = 0;
            for (; local_3 < 3; local_3++) {
                if (func_800DA298(local_3 + 0xC08)) {
                    if (local_4 == local_2) break;
                    local_4++;
                }
            }
            local_5 = local_3 + 1;
            for (local_3 = 0; local_3 < 6; local_3++) {
                if (local_5 == D_80803D04_chklungo[local_3 * 3 + local_0]) {
                    local_1 = local_3 + 1;
                    break;
                }
            }
            func_800DA7A8(0x315, local_1, 3);
        } else {
            local_1 = func_800DC128(0, 6) + 1;
            func_800DA7A8(0x315, local_1, 3);
        }
    }
    local_6 = ((u8 *)D_80803CF4_chklungo + 13)[local_1 * 3 + local_0];
    return local_6;
}

void func_80802F30_chklungo(s32 param_0)
{
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80803D18_chklungo);
}

void func_80802F58_chklungo(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    _subaddieaudioquick_entrypoint_2(param_0, (char *)param_0 + 4, &D_80803D28_chklungo);
    if ((*(s16 *)((char *)local_0 + 0x24) == 0) && (func_800C0638() == 0)) {
        func_80803158_chklungo(param_0, 0x1630, 0x44);
        *(s16 *)((char *)local_0 + 0x24) = 1;
    }
}

void func_80802FCC_chklungo(param_0) s32 param_0; {
    s32 local_0 = func_80100094(param_0, 0);
    *(u8 *)(local_0 + 0x48) = _subaddieaudioloop_entrypoint_3(*(u8 *)(local_0 + 0x48));
}

void func_80803000_chklungo(Actor *param_0)
{
  Actor *new_var;
  new_var = func_80100094(param_0, 0);
  if (*(s16 *)((char *)new_var + 0x46) == 0)
  {
    func_800F4AF4(func_800F54E4(), 0x14);
    *(s16 *)((char *)new_var + 0x46) = 1;
  }
  func_808030A4_chklungo(param_0);
}

int func_8080305C_chklungo(s32 param_0)
{
  s32 local_0 = func_80100094(param_0, 0);
  if (*(s16 *)((char *)local_0 + 0x46) != 0) {
    s32 new_var = func_800F54E4();
    func_800F4B20(new_var);
    *(s16 *)((char *)local_0 + 0x46) = 0;
  }
}

void func_808030A4_chklungo(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);
    if (*(s16 *)(local_0 + 0x46)) {
        if (_plcamera_entrypoint_10(func_800F54E4()) != 20) {
            *(s16 *)(local_0 + 0x46) = 0;
            return;
        }
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 400.0f;
        _plcamera_entrypoint_9(func_800F54E4(), local_1, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(func_800F54E4())), local_1);
    }
}

int func_80803158_chklungo(param_0, param_1, param_2) s32 param_0[4]; s32 param_1; s32 param_2;
{
  u32 local_0;
  local_0 = param_0[0];
  return _subaddiedialog_entrypoint_11(local_0, param_1, param_2, param_0 + 1, 0xab);
}

void func_8080318C_chklungo(KlungoS *param_0) {
    f32 local_0 = 300.0f / param_0->f24;
    func_80101CDC(param_0, func_8010203C(param_0, param_0->f72) * local_0);
}

f32 func_808031E4_chklungo(f32 *arg0)
{
  float new_var;
  new_var = arg0[9] / 300.0f;
  return 400.0f * new_var;
}

void func_80803208_chklungo(param_0) s32 param_0; {
    func_80105230(param_0, &D_80803D38_chklungo);
}

void func_8080322C_chklungo(u8 *param_0, f32 param_1) {
    f32 local_0[3];
    s32 local_3;

    func_8010D09C(func_800F54E4(), local_0, param_1);
    if (func_80803304_chklungo(param_0, local_0) != 0) {
        if (func_800CC338(local_0, ((*(u32 *)(param_0 + 0x70)) >> 0x19) - 1, ((u32) ((*(u32 *)(param_0 + 0x70)) << 0x16) >> 0x1A) - 1) != -1) {
            func_800EE7F8(param_0 + 0x18, local_0);
            return;
        }
    }
    local_3 = func_80803390_chklungo(param_0, local_0);
    func_80803464_chklungo(param_0, local_3, local_0, param_0 + 0x18);
    if (func_80803304_chklungo(param_0, param_0 + 0x18) == 0) {
        func_800EE7F8(param_0 + 0x18, param_0 + 4);
    }
}

int func_80803304_chklungo(param_0, param_1) Actor *param_0; f32 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    func_800EE7F8(local_0, param_1);
    func_800EE7F8(local_1, param_1);
    local_0[1] = param_0->position[1] + 500.0f;
    local_1[1] = param_0->position[1] - 500.0f;
    if (!func_800C6A7C(local_0, local_1, local_2, 0x20020)) return 0;
    param_1[1] = local_1[1];
    return 1;
}

f32 *func_80803390_chklungo(param_0, param_1) Actor *param_0; f32 *param_1;
{
    s32 local_0;
    s32 local_1;
    f32 *local_2;
    f32 *local_3;

    local_0 = func_800CC5F4((((u32 *)param_0)[0x70 / 4] >> 25) - 1);
    local_2 = NULL;
    for (local_1 = 0; local_1 < local_0; local_1++) {
        local_3 = func_800CC63C((((u32 *)param_0)[0x70 / 4] >> 25) - 1, local_1);
        if (local_2 == NULL || func_800EEB40(local_3, param_1) < func_800EEB40(local_2, param_1)) {
            local_2 = local_3;
        }
    }
    return local_2;
}

void func_80803464_chklungo(KlungoEventOwner param_0, KlungoPathPoint *param_1,
    f32 *param_2, f32 *param_3)
{
    f32 local_0;

    local_0 = func_800F1DF4(param_1->position, param_2);
    func_800EE7F8(param_3, param_1->position);
    func_800EF1B8(param_3, local_0, (f32)param_1->distance);
}

s32 func_808034CC_chklungo(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 *local_2;

    local_2 = param_0->position;
    func_800EE7F8(local_0, local_2);
    func_800EF1B8(local_0, param_0->rotation[1] + 90.0f, 1.5e+02f);
    if (func_800CBD84(local_0) == -1) return 0;
    func_800EE7F8(local_1, local_2);
    func_800EF1B8(local_1, param_0->rotation[1] - 90.0f, 150.0f);
    if (func_800CBD84(local_1) == -1) return 0;
    return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/klungo.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80803B6C_chklungo -> int[], D_80803BE0_chklungo -> int[], D_80803BEC_chklungo -> int[], D_80803BFC_chklungo -> int[], D_80803C0C_chklungo -> int[], D_80803C1C_chklungo -> int[], D_80803C2C_chklungo -> int[], D_80803C3C_chklungo -> s32[], D_80803C54_chklungo -> s32[], D_80803C6C_chklungo -> s32[], D_80803C74_chklungo -> s32[], D_80803C98_chklungo -> s32[], D_80803CA8_chklungo -> s32[], D_80803CB8_chklungo -> s32[], D_80803CF4_chklungo -> s32[], D_80803D38_chklungo -> s32[] */
u8 D_808038A0_chklungo[4] = { 0x1, 0x41, 0x0, 0xC1 };
KlungoTbl D_808038A4_chklungo[2] = { 0x0, 0x20, 0x707, 0x0, 0x0, 0x0, 0x12, 0x0, 0x1, 0x0, 0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x5, 0x0, 0x1, 0x4, 0x38, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0x14, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x4, 0x38, 0x3F, 0x99, 0x99, 0x9A, 0x0, 0x0, 0x0, 0x0, 0x41, 0x70, 0x0, 0x0, 0x41, 0xA0, 0x0, 0x0, 0x40, 0x40, 0x0, 0x0, 0x40, 0x80, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0, 0x16, 0x22, 0x16, 0x23, 0x16, 0x27, 0x16, 0x35, 0xF, 0xA0, 0xDE, 0xA7, 0x71, 0xC0, 0x0, 0x0, 0x1, 0x5B, 0x1, 0xBA, 0x0, 0x21, 0x90C, 0x0, 0x0, 0x0, 0x11, 0x0, 0x1, 0x0, 0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x5, 0x0, 0x1, 0x4, 0x38, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0x14, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0, 0x4, 0x38, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x4, 0x38, 0x3F, 0x80, 0x0, 0x0, 0x3E, 0xCC, 0xCC, 0xCD, 0x41, 0x70, 0x0, 0x0, 0x41, 0xA0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x40, 0x40, 0x0, 0x0, 0x43, 0xC8, 0x0, 0x0, 0x16, 0x28, 0x16, 0x29, 0x16, 0x2A, 0x16, 0x36, 0xB, 0xB8, 0xDE, 0xA7, 0x71, 0xC0, 0x0, 0x0, 0x1, 0x5E, 0x0, 0xB7 };
static u32 D_808038A4_chklungo_rest[32] = { 0x22090D, 0x12, 0x10030, 0x14, 0x10031, 0x2, 0x30, 0x3, 0x10438, 0x5, 0x438, 0x7, 0x438, 0xB, 0x438, 0xD, 0x438, 0xF, 0x30, 0x3, 0x438, 0x3F4CCCCD, 0x3F4CCCCD, 0x41700000, 0x41A00000, 0x3F800000, 0x40000000, 0x43FA0000, 0x162B162C, 0x162D1637, 0x9C480C0, 0xC0C00000 };
u8 D_80803A2C_chklungo[16] = { 0x0, 0x13, 0x6, 0x14, 0x0, 0xD, 0x0, 0xB3, 0x0, 0xCC, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0 };
u8 D_80803A3C_chklungo[16] = { 0x43, 0x34, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0, 0x43, 0x89, 0x80, 0x0, 0x42, 0xC8, 0x0, 0x0 };
u8 D_80803A4C_chklungo[288] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x3F, 0x0, 0x0, 0x0, 0x4, 0xB2, 0x0, 0x1, 0x3F, 0x0, 0x0, 0x0, 0x4, 0xB2, 0x0, 0x1, 0x3F, 0x19, 0x99, 0x9A, 0x4, 0xB3, 0x0, 0x2, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x40, 0xAF, 0xA, 0x3D, 0x2, 0x5D, 0x0, 0x2, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x40, 0x20, 0x0, 0x0, 0x2, 0x5E, 0x0, 0x2, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x67, 0x0, 0x1, 0x3F, 0x99, 0x99, 0x9A, 0x2, 0x5F, 0x0, 0x2, 0x3E, 0xDC, 0x28, 0xF6, 0x2, 0x60, 0x0, 0x2, 0x3F, 0xC0, 0x0, 0x0, 0x2, 0x68, 0x0, 0x2, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x0, 0x1, 0x3E, 0xDC, 0x28, 0xF6, 0x2, 0x66, 0x0, 0x2, 0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x0, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x3F, 0x9D, 0x70, 0xA4, 0x2, 0x65, 0x0, 0x42, 0x3F, 0x9D, 0x70, 0xA4, 0x2, 0x6A, 0x0, 0x42, 0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x4, 0x1, 0x3E, 0xDC, 0x28, 0xF6, 0x2, 0x66, 0x0, 0x2, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x4, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x4, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x3F, 0x95, 0xC2, 0x8F, 0x2, 0x61, 0x0, 0x1, 0x40, 0x41, 0xEB, 0x85, 0x2, 0x62, 0x0, 0x2, 0x40, 0x41, 0xEB, 0x85, 0x2, 0x62, 0x0, 0x84, 0x40, 0x41, 0xEB, 0x85, 0x2, 0x62, 0x0, 0x84, 0x3F, 0x0, 0x0, 0x0, 0x2, 0x63, 0x0, 0x2, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1, 0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x0, 0x1 };
int D_80803B6C_chklungo[18] = { 0xB3041E, -0xFFFF, (u32)&D_80803A4C_chklungo, (u32)func_808002D0_chklungo, (u32)func_8080101C_chklungo, (u32)func_808011B4_chklungo, 0x0, 0x40000000, 0x0, 0x40561, (u32)func_8080162C_chklungo, (u32)func_80108ED0, 0xA00000, (u32)func_8080000C_chklungo, (u32)func_80107C2C, -0x7FDFEBFC, (u32)func_80801220_chklungo, 0x0 };
u8 D_80803BB4_chklungo[12] = { 0x0, 0x13, 0x5, 0x67, 0x0, 0xA, 0x0, 0xB3, 0x0, 0x2, 0x0, 0x0 };
u8 D_80803BC0_chklungo[16] = { 0x0, 0x13, 0x6, 0x15, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0 };
u8 D_80803BD0_chklungo[16] = { 0x0, 0x13, 0x4, 0xF8, 0x0, 0xA, 0x0, 0xB3, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
int D_80803BE0_chklungo[3] = { 0x1304A2, 0x180002, 0x0 };
int D_80803BEC_chklungo[4] = { 0x13049C, 0xA00B3, 0x180002, 0x0 };
int D_80803BFC_chklungo[4] = { 0x130434, 0xA00B3, 0x180002, 0x0 };
int D_80803C0C_chklungo[4] = { 0x1305BA, 0xD00F3, 0x10C0018, 0x20000 };
int D_80803C1C_chklungo[4] = { 0x3EDC28F6, 0x3F000000, 0x3F19999A, -0x40800000 };
int D_80803C2C_chklungo[4] = { 0x3F4F5C29, 0x3F6147AE, 0x3F733333, -0x40800000 };
s32 D_80803C3C_chklungo[6] = { 0x130417, 0x164650, 0xD00F3, 0x10C0001, 0x3201D4C, 0x0 };
s32 D_80803C54_chklungo[6] = { 0x3D75C28F, 0x3E19999A, 0x3E75C28F, 0x3F07AE14, 0x3F1C28F6, -0x40800000 };
s32 D_80803C6C_chklungo[2] = { 0x130417, 0x20000 };
s32 D_80803C74_chklungo[4] = { 0x130614, 0xA00B3, 0x180002, 0x0 };
u8 D_80803C84_chklungo[20] = { 0x3, 0x6, 0x0, 0x13, 0x4, 0xF7, 0x0, 0xD, 0x0, 0x8C, 0x0, 0xA6, 0x0, 0x18, 0x0, 0x2, 0x0, 0x11, 0x0, 0x0 };
s32 D_80803C98_chklungo[4] = { 0x1304F8, 0xD00C0, 0xD90018, 0x20000 };
s32 D_80803CA8_chklungo[4] = { 0x1304ED, 0xD00C0, 0xD90002, 0x0 };
s32 D_80803CB8_chklungo[2] = { 0x130417, 0x20000 };
u8 D_80803CC0_chklungo[52] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x0, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x3, 0x80, 0x4, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x99, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0x5E, 0x1, 0x1A, 0x0, 0x0 };
s32 D_80803CF4_chklungo[4] = { 0x130413, 0x18000D, 0xC000D9, 0x20000 };
u8 D_80803D04_chklungo[20] = { 0x1, 0x2, 0x3, 0x1, 0x3, 0x2, 0x2, 0x1, 0x3, 0x2, 0x3, 0x1, 0x3, 0x2, 0x1, 0x3, 0x1, 0x2, 0x0, 0x0 };
u8 D_80803D18_chklungo[16] = { 0x0, 0x13, 0x5, 0xFF, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0 };
u8 D_80803D28_chklungo[16] = { 0x0, 0x13, 0x4, 0xB0, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
s32 D_80803D38_chklungo[6] = { 0x0, 0x3F000000, -0x40800000, 0x0, 0x0, 0x0 };
