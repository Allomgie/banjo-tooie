#include "common.h"

#define TRASH_IMPACT(volume) func_800C4140( \
    (((u32)(func_800DC178(1.05f, 1.15f) * 1023.0f) & 0x7FF) << 21) \
    + ((((volume) >> 5) & 0x3FF) << 11) + 0x4C1, \
    (f32 *)(param_0 + 4), 0x04B000FA)
#define TRASH_RATTLE() func_800C4140( \
    (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21) \
    + 0x157C04, (f32 *)(param_0 + 4), 0x04B000FA)
extern s32 func_80101E14(void *, f32);
extern s32 func_80101E4C(void *, void *);
extern int func_800C954C(void);
extern int func_800DA298(int);
extern int func_800CC63C(int, int);
extern void _subaddiemulti_entrypoint_6(int, int);
extern int _gcstatusDll_entrypoint_11(void);
extern void func_800D2498(int, int, int);
extern int func_800D90A4(float *);
extern void func_80108B04(void *, int);
extern void func_800D28A0(int);
extern void func_800BA22C(s32, s32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern int _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
typedef struct { s32 local_0[4]; } TrashParticleColours27;
extern TrashParticleColours27 D_80803164_chtrashcangame;
extern u8 D_80803174_chtrashcangame[];
extern f32 func_800C6920(f32 *, f32, f32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern f32 func_800DC178(f32, f32);
extern int D_808031B4_chtrashcangame;
typedef union { s32 local_0; s16 local_1[2]; } TrashCanEventValue;
extern int D_808031FC_chtrashcangame;
extern f32 func_800F1DF4(f32 *, f32 *);
extern int D_808033A0_chtrashcangame;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern int D_808033E8_chtrashcangame;
extern f32 func_80103EF4(Actor *);
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern int D_80803430_chtrashcangame;
extern u8 D_80803090_chtrashcangame[];
extern s16 D_80803096_chtrashcangame;
extern f32 func_80103EAC(Actor *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void func_800CE8D8(s32, f32, s32);
extern u8 D_808030AC_chtrashcangame[];
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
typedef struct { s32 local_0[7]; } TrashTimes7;
typedef struct { u16 local_0, local_1; f32 local_2; } TrashAnimation;
extern TrashAnimation D_80802FF4_chtrashcangame[];
extern TrashParticleColours27 D_808030BC_chtrashcangame;
extern TrashParticleColours27 D_808030CC_chtrashcangame;
extern TrashParticleColours27 D_808030DC_chtrashcangame;
extern TrashParticleColours27 D_808030EC_chtrashcangame;
extern TrashParticleColours27 D_808030FC_chtrashcangame;
extern TrashParticleColours27 D_8080310C_chtrashcangame;
extern TrashParticleColours27 D_8080311C_chtrashcangame;
extern TrashTimes7 D_8080312C_chtrashcangame;
extern TrashTimes7 D_80803148_chtrashcangame;
extern void func_800C4140(s32, f32 *, s32);
extern f32 func_800DC0C0(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_80013970(f32);
extern f32 func_80101F24(Actor *);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, u8 *);
extern void func_800BA994(s32, s16, s16, s16, s16, s16, s16);
extern void func_800F4F34(s32, f32 *, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_80803398_chtrashcangame[];
extern u8 D_80803394_chtrashcangame[];
extern u8 D_80803364_chtrashcangame[];
extern u8 D_80803324_chtrashcangame[];
extern u8 D_8080339C_chtrashcangame[];
extern s32 func_800B53A4(s32);
extern void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
void func_808017F0_chtrashcangame();
void func_808003D0_chtrashcangame();
void func_80800BA8_chtrashcangame();
void func_8080134C_chtrashcangame();
s32 func_80801558_chtrashcangame();
void func_808019EC_chtrashcangame();
void func_80801EE8_chtrashcangame();

void func_80800000_chtrashcangame(Actor *param_0) {
    *(s32 *)((u8 *)param_0 + 0x18) = 0;
    *(s32 *)((u8 *)param_0 + 0x30) = 0;
    *(s32 *)((u8 *)param_0 + 0x2C) = 0;
    *(s32 *)((u8 *)param_0 + 0x28) = 0;
}

s32 func_80800014_chtrashcangame(Actor *param_0, s32 param_1)
{
  if (func_800D3948())
  {
    switch (param_1)
    {
      case 0:
        return ((s32 *)param_0)[10];

      case 1:
        return ((s32 *)param_0)[11];

      case 2:
        return ((s32 *)param_0)[12];

      case 3:
        return ((s32 *)param_0)[6];

      default:
        return 0;
    }
  }
  else
  {
    return ((s32 *)param_0)[10];
  }
}

void func_80800098_chtrashcangame(Actor *param_0, s32 param_1, s32 param_2)
{
    if (func_800D3948()) {
        if ((s32)param_0->unk70_10 == 3) {
            switch (param_1) {
                case 0: param_0->actorData[4] = param_2; break;
                case 1: param_0->actorData[5] = param_2; break;
                case 2: param_0->actorData[6] = param_2; break;
                case 3: param_0->actorData[0] = param_2; break;
            }
        }
    } else if (param_0->unk70_10 == 8) {
        param_0->actorData[4] = param_2;
    }
}

void func_80800144_chtrashcangame(Actor *param_0, s32 param_1, s32 param_2){
    s32 local_0;
    local_0 = func_80800014_chtrashcangame(param_0, param_1);
    func_80800098_chtrashcangame(param_0, param_1, local_0 + param_2);
}

void func_808018E4_chtrashcangame();

void func_80801740_chtrashcangame();

void func_80800180_chtrashcangame(Actor *param_0)
{
    _sudeflect_entrypoint_1(param_0->position, func_80103EF4(param_0), 0.0f, func_80103EAC(param_0), 30);
    switch (param_0->unk70_10) {
    case 1:
        if (func_800D90A4(&param_0->unk58)) func_808003D0_chtrashcangame(param_0, 2);
        break;
    case 3:
        if (func_800D0A9C(0x4E, 1)) D_80803096_chtrashcangame = 0x13F0;
        if (_subaddiedialog_entrypoint_7(param_0, param_0->position, D_80803090_chtrashcangame)) func_80801740_chtrashcangame(param_0, 2, 0);
        break;
    case 8:
        if (func_800D90A4(&param_0->unk58)) {
            param_0->unk58 = 0.299987793f;
            func_80108B04(param_0, 0);
        }
        if (_subaddiedialog_entrypoint_4(param_0->position, 400, 0)) {
            if (func_800D0A9C(0x4E, 1)) _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0x1403, 0x1405), 7, param_0->position, 0x6A);
            else _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0x1401, 0x1405), 7, param_0->position, 0x6A);
        }
        if (func_800CEAD0(0)) func_80800728_chtrashcangame(param_0);
        func_800D2498(0xF8, func_80800014_chtrashcangame(param_0, 0), 0);
        break;
    case 9:
    case 11:
        func_8010CEAC(param_0);
        func_800D2498(0xF8, func_80800014_chtrashcangame(param_0, 0), 0);
        break;
    case 13:
        if (!_subaddiefind_entrypoint_2(0x21F, 0)) func_808003D0_chtrashcangame(param_0, 14);
        break;
    case 14:
        if (func_800D90A4(&param_0->unk58)) func_808003D0_chtrashcangame(param_0, 15);
        break;
    case 15:
        func_8010CEAC(param_0);
        break;
    }
    func_80800BA8_chtrashcangame(param_0);
    func_808018E4_chtrashcangame(param_0);
}

void func_8080189C_chtrashcangame();

void func_808016B4_chtrashcangame();

void func_808003D0_chtrashcangame(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    switch (param_1) {
    case 1:
        param_0->unk58 = func_800DC178(15.0f, 25.0f);
        break;
    case 2:
        _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0x13FE, 0x1401), 4, param_0->position, 0x6A);
        break;
    case 3:
        *(s32 *)&param_0->unk50 = 0;
        param_0->actorData[7] = 10;
        func_8080189C_chtrashcangame(param_0);
        break;
    case 4:
        param_0->unk79_4 = func_800DC128(1, 4);
        func_808017F0_chtrashcangame((u8 *)param_0, 0x13F1, 0x4E);
        break;
    case 5:
        func_808017F0_chtrashcangame((u8 *)param_0, 0x13F2, 0x4E);
        break;
    case 6:
        local_1 = func_800D0A9C(0x4E, 1) ? 0x13FD : 0x13F3;
        func_808017F0_chtrashcangame((u8 *)param_0, local_1, 0xF);
        break;
    case 7:
        *(s32 *)&param_0->unk50 = 0;
        if (func_800D395C()) {
            local_0 = 0x1444;
            func_800946C4(func_800F53D0(func_800F54E4()), 1);
        } else if (func_800D0A9C(0x4E, 1)) {
            local_0 = 0x13F5;
        } else {
            local_0 = 0x13F4;
        }
        func_808017F0_chtrashcangame((u8 *)param_0, local_0, 0xF);
        func_80800000_chtrashcangame(param_0);
        _gcfrontend_entrypoint_9(0x72);
        func_80101180(0x533, 8, 0);
        break;
    case 8:
        func_8080189C_chtrashcangame(param_0);
        func_800CE8D8(0, 60.0f, 60);
        func_800CE88C(0, 1);
        param_0->unk58 = 0.29998779296875f;
        func_80800098_chtrashcangame(param_0, 0, 0);
        *(s32 *)&param_0->unk50 = 0;
        func_800FDC28(12);
        break;
    case 9:
        func_800FC6B0(0x17);
        break;
    case 10:
        local_2 = func_800D0A9C(0x4E, 1) ? 0x13FC : 0x13FB;
        func_808017F0_chtrashcangame((u8 *)param_0, local_2, 0x4E);
        func_800D2054(0, 0x86, func_80800014_chtrashcangame(param_0, 0));
        break;
    case 11:
        func_800FC6B0(0x16);
        break;
    case 12:
        func_800D1000(0x4E, 1, param_0->position, 6, 0);
        func_808016B4_chtrashcangame(param_0, (s32)param_0->unk0, 6, 0x10);
        break;
    case 13:
        func_8080189C_chtrashcangame(param_0);
        break;
    case 14:
        param_0->unk58 = 0.5f;
        break;
    case 15:
        func_808017F0_chtrashcangame((u8 *)param_0, 0x13FC, 0x4E);
        func_800D2054(0, 0x86, func_80800014_chtrashcangame(param_0, 0));
        break;
    case 16:
        *(s32 *)&param_0->unk50 = 0;
        param_0->actorData[7] = 10;
        func_8080189C_chtrashcangame(param_0);
        func_808017F0_chtrashcangame((u8 *)param_0, 0x1443, 0x4E);
        break;
    case 17:
        func_808017F0_chtrashcangame((u8 *)param_0, 0x1451, 0xF);
        break;
    }
    func_80102424(param_0, param_1);
}

int func_80800728_chtrashcangame(s32 param_0)
{
  s32 local_0;
  u32 local_1 = param_0 | 0U;
  func_800FDC28(0);
  func_80101180(0x533, 7, 0);
  if (func_800D395C() != 0)
  {
    local_0 = func_80800014_chtrashcangame(param_0, 0);
    if (local_0 == func_800D211C(0x86))
    {
      func_800FC660(0x17);
      func_808017F0_chtrashcangame(param_0, 0x1446, 0xF);
    }
    else
    {
      local_0 = func_80800014_chtrashcangame(param_0, 0);
      if (local_0 < func_800D211C(0x86))
      {
        func_800FC660(0x17);
        func_808017F0_chtrashcangame(param_0, 0x1445, 0xF);
      }
      else
      {
        func_800FC660(0x16);
        func_808017F0_chtrashcangame(param_0, 0x1447, 0xF);
      }
    }
    func_808003D0_chtrashcangame(param_0, 0x12);
    return;
  }
  if (func_800D0A9C(0x4E, 1) != 0)
  {
    local_0 = func_80800014_chtrashcangame(param_0, 0);
    if (local_0 == func_800D211C(0x86))
    {
      func_808017F0_chtrashcangame(param_0, 0x13F9, 0xF);
      func_808003D0_chtrashcangame(param_0, 9);
      return;
    }
    local_0 = func_80800014_chtrashcangame(param_0, 0);
    if (local_0 < func_800D211C(0x86))
    {
      func_808017F0_chtrashcangame(param_0, 0x13F8, 0xF);
      func_808003D0_chtrashcangame(param_0, 9);
      return;
    }
    func_808017F0_chtrashcangame(param_0, 0x13FA, 0xF);
    func_808003D0_chtrashcangame(param_0, 0xB);
    return;
  }
  if (func_80800014_chtrashcangame(param_0, 0) < 0x32)
  {
    func_808017F0_chtrashcangame(param_0, 0x13F6, 0xF);
    func_808003D0_chtrashcangame(param_0, 9);
    return;
  }
  func_808017F0_chtrashcangame(param_0, 0x13F7, 0xF);
  func_808003D0_chtrashcangame(param_0, 0xB);
}

s32 func_8080093C_chtrashcangame(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    u32 local_1;

    switch (param_1) {
    case 0x2E:
        func_8080134C_chtrashcangame(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x2F:
        func_80108B04(param_0, ((s16 *)&param_2)[1]);
        return 1;
    case 0x30:
        return func_80801558_chtrashcangame(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x3D:
        func_808019EC_chtrashcangame(param_0, param_2);
        return 1;
    case 0xB:
        if (param_2 == 6) {
            func_808003D0_chtrashcangame(param_0, 13);
        }
        return 4;
    case 0x52:
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_3(D_808030AC_chtrashcangame, param_0->scale);
        return 3;
    case 0x57:
        local_0 = param_2 & 0xFFFF;
        local_1 = (u32)(param_2 & 0xFFFF0000) >> 16;
        if (_gcdialogcamera_entrypoint_0(local_0, local_1)) {
            func_80801740_chtrashcangame(param_0, local_0, local_1);
            return 2;
        }
        return 1;
    case 0x95:
        param_0->unk74_7 = 0;
        *(f32 *)&param_0->actorData[3] = 0.0f;
        if (_glcutDll_entrypoint_20()) {
            func_808003D0_chtrashcangame(param_0, 19);
        } else if (func_800D395C()) {
            func_808003D0_chtrashcangame(param_0, 16);
        } else if (!func_800F64A4(func_800F54E4(), 0x400)) {
            func_808003D0_chtrashcangame(param_0, 1);
        } else {
            func_808003D0_chtrashcangame(param_0, 3);
        }
        func_800BF744(1, 1);
        return 1;
    default:
        return 0;
    }
}

s32 func_80800B64_chtrashcangame(f32 *param_0)
{
    Actor *local_0[50];
    f32 local_1;
    s32 local_2;

    local_1 = 300.0f;
    local_2 = _subaddiefind_entrypoint_5(0x476, local_0, 50, param_0, local_1, func_800EFC7C);
    return local_2;
}

void func_80800BA8_chtrashcangame(param_0) u8 *param_0;
{
    switch (D_80802FF4_chtrashcangame[((u32)*(u16 *)(param_0 + 0x72)) >> 10].local_0) {
    case 0x369: { /* One explicit strong impact, then table-driven softer hits. */
        TrashParticleColours27 local_0 = D_808030BC_chtrashcangame;
        TrashParticleColours27 local_1 = D_808030CC_chtrashcangame;
        TrashParticleColours27 local_2 = D_808030DC_chtrashcangame;
        s32 local_3 = 0;
        if (func_80101E14(param_0, 0.157f)) local_3 = 22000;
        else if (func_80101E4C(param_0, &local_0)) local_3 = 10000;
        else if (func_80101E4C(param_0, &local_1)) local_3 = 5000;
        if (func_80101E4C(param_0, &local_2)) TRASH_RATTLE();
        if (local_3) TRASH_IMPACT(local_3);
        break;
    }
    case 0x36A: { /* Explicit normalized animation times; no rattle branch. */
        TrashParticleColours27 local_4 = D_808030EC_chtrashcangame;
        TrashParticleColours27 local_5 = D_808030FC_chtrashcangame;
        TrashParticleColours27 local_6 = D_8080310C_chtrashcangame;
        s32 local_7 = 0;
        if (func_80101E14(param_0, 0.126f)) local_7 = 22000;
        else if (func_80101E14(param_0, 0.156f) || func_80101E14(param_0, 0.888f)) local_7 = 10000;
        else if (func_80101E14(param_0, 0.918f)) local_7 = 5000;
        if (local_7) TRASH_IMPACT(local_7);
        break;
    }
    case 0x36B: { /* Table-driven strong/medium hits and independent rattles. */
        TrashParticleColours27 local_8 = D_8080311C_chtrashcangame;
        TrashTimes7 local_9 = D_8080312C_chtrashcangame;
        TrashTimes7 local_10 = D_80803148_chtrashcangame;
        s32 local_11 = 0;
        if (func_80101E4C(param_0, &local_8)) local_11 = 22000;
        else if (func_80101E4C(param_0, &local_9)) local_11 = 10000;
        else if (func_80101E14(param_0, 0.44f) || func_80101E14(param_0, 0.994f)) local_11 = 5000;
        if (func_80101E4C(param_0, &local_10)) TRASH_RATTLE();
        if (local_11) TRASH_IMPACT(local_11);
        break;
    }
    }
}

void func_8080134C_chtrashcangame(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x13EE:
        if (param_2) {
            func_808003D0_chtrashcangame(param_0, 4);
            return;
        }
        func_808003D0_chtrashcangame(param_0, 5);
        return;
    case 0x13EF: case 0x13F0: case 0x13F1: case 0x13F2:
        if (param_2) {
            func_808003D0_chtrashcangame(param_0, 7);
            return;
        }
        func_808003D0_chtrashcangame(param_0, 6);
        return;
    case 0x13F3:
        func_808003D0_chtrashcangame(param_0, 3);
        return;
    case 0x13F4: case 0x13F5: case 0x1444:
        func_808003D0_chtrashcangame(param_0, 8);
        return;
    case 0x13F6: case 0x13F8: case 0x13F9:
        func_808003D0_chtrashcangame(param_0, 10);
        return;
    case 0x13FA:
        func_808003D0_chtrashcangame(param_0, 15);
        return;
    case 0x13F7:
        func_808003D0_chtrashcangame(param_0, 12);
        return;
    case 0x13FD:
        func_808003D0_chtrashcangame(param_0, 3);
        return;
    case 0x13FC:
        if (param_2) {
            func_808003D0_chtrashcangame(param_0, 7);
            return;
        }
        func_808003D0_chtrashcangame(param_0, 6);
        return;
    case 0x13FB:
        if (param_2) {
            func_808003D0_chtrashcangame(param_0, 7);
            return;
        }
        func_808003D0_chtrashcangame(param_0, 6);
        return;
    case 0x13FE: case 0x13FF: case 0x1400:
        func_808003D0_chtrashcangame(param_0, 1);
        return;
    case 0x1443:
        if (param_2) {
            func_808003D0_chtrashcangame(param_0, 17);
            return;
        }
        func_808003D0_chtrashcangame(param_0, 7);
        return;
    case 0x1451:
        func_808003D0_chtrashcangame(param_0, 7);
        return;
    case 0x1445: case 0x1446: case 0x1447:
        func_808017F0_chtrashcangame(param_0, 0x1448, 0x4E);
        func_800D2054(0, 0x86, func_80800014_chtrashcangame(param_0, 0));
        return;
    case 0x1448:
        if (param_2) {
            func_808003D0_chtrashcangame(param_0, 7);
            return;
        }
        func_800C0850();
        _gcfrontend_entrypoint_10();
        break;
    }
}

s32 func_80801558_chtrashcangame(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    switch (param_1) {                                 
    case 0x13EF: ;
    case 0x13F1:
    case 0x13F2:
        return 0x32;
    case 0x13F0:
        return func_800D211C(0x86);
    case 0x13F4:
        if (param_2 != 0) {
            return 0x32;
        }
        return 0x3C;
    case 0x13F5:
        if (param_2 != 0) {
            return func_800D211C(0x86);
        }
        return 0x3C;
    case 0x13F8:
        if (param_2 != 0) {
            return func_800D211C(0x86);
        }
        return func_80800014_chtrashcangame(param_0, 0);
    case 0x13FA:
        return func_80800014_chtrashcangame(param_0, 0);
    case 0x13F6: ;
    case 0x13F7:
    case 0x13F9:
        return func_80800014_chtrashcangame(param_0, 0);
    case 0x1443:
        return 0x3C;
    case 0x1444:
        if (param_2 != 0) {
            return func_800D211C(0x86);
        }
        return 0x3C;
    case 0x1445: ;
    case 0x1446:
    case 0x1447:
        if (param_2 != 0) {
            return func_800D211C(0x86);
        }
        return func_80800014_chtrashcangame(param_0, 0);
    case 0x1451:
        return 0x3C;
    default:
        return 0;
    }
}

void func_808016B4_chtrashcangame(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    switch (param_0->unk74_7) {
    case 0:
        _capod_entrypoint_2(param_0->unk0, 0x2A, 0x10);
    case 1:
        param_0->unk74_7 = 2;
    case 2:
        _capod_entrypoint_6(param_1, param_2, param_3);
        break;
    }
}

void func_80801740_chtrashcangame(u8 *param_0, s32 param_1, s32 param_2)
{
  u32 local_0;
  local_0 = (u16) (*((u16 *) (((char *) param_0) + 0x76)));
  local_0 = local_0 >> 7;
  switch (local_0)
  {
    case 0:
      _capod_entrypoint_2(*((s32 *) (((char *) param_0) + 0x0)), 0x2A, 0x10, param_0);

    case 2:
      _capod_entrypoint_8(1);
      *((u16 *) (((char *) param_0) + 0x76)) = (u16) (((*((u16 *) (((char *) param_0) + 0x76))) & 0x7F) | 0x80);
      param_1 = 2;
      param_2 = 1;
      _gcdialogcamera_entrypoint_6(*((s32 *) (((char *) param_0) + 0x0)));
      _gcdialogcamera_entrypoint_8();

    case 1:
      _capod_entrypoint_7(param_1, param_2);
      return;

  }

}

void func_808017F0_chtrashcangame(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    u32 local_0;

    local_0 = (u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7;
    switch (local_0) {                              
    case 0:
        _capod_entrypoint_2((*(s32 *)((s8 *)(param_0) + (0))), 0x2A, 0x10);
        
    case 2:
        _capod_entrypoint_8(1);
        (*(u16 *)((s8 *)(param_0) + (0x76))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x76))) & 0x7F) | 0x80);
        _gcdialogcamera_entrypoint_6((*(s32 *)((s8 *)(param_0) + (0))));
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(2, 1);
        break;
    }
    _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), param_1, param_2, param_0 + 4, 0x6A);
}

void func_8080189C_chtrashcangame(Actor *param_0)
{
  u16 val;
  unsigned int new_var;
  u16 masked_val;
  val = (*((u16 *) (((char *) param_0) + 0x76))) ^ 0;
  new_var = 0x76;
  do
  {
    if ((((u32) val) >> 7) != 0)
    {
      _capod_entrypoint_3(0, param_0);
      masked_val = (*((u16 *) (((char *) param_0) + 0x76))) & 0x7F;
      *((u16 *) (((char *) param_0) + new_var)) = (*((u16 *) (((char *) param_0) + 0x76))) & 0x7F;
    }
  }
  while ((int) 0);
}

void func_808018E4_chtrashcangame(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;
    TrashParticleColours27 local_2;

    if (param_0->unk70_10 != 8 && func_800D90A4(&param_0->actorData[3])) {
        local_2 = D_80803164_chtrashcangame;
        func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, local_0);
        local_0[1] = func_800C6920(local_0, 1000.0f, -1000.0f, 0);
        local_1 = func_800BABB8(0, local_0, local_0, 1.0f, D_80803174_chtrashcangame);
        func_800BAB80(local_1, &local_2.local_0[func_800DC128(0, 4)]);
        func_800BA22C(local_1, 1);
        ((f32 *)param_0->actorData)[3] = func_800DC178(1.0f, 2.0f);
    }
}

void func_808019EC_chtrashcangame(param_0, param_1) Actor *param_0; s32 param_1;
{
    Vec3f local_4;
    Actor *local_3;
    s32 local_2;
    s32 local_1 = -1;
    f32 local_0;

    if (*(s32 *)&param_0->unk50 < (s32)param_0->actorData[7]) {
        (*(s32 *)&param_0->unk50)++;
        switch (param_1) {
        case 0:
            local_0 = func_800DC0C0();
            func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, local_4.f);
            while (func_80800B64_chtrashcangame(local_4.f)) {
                func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, local_4.f);
            }
            if (local_0 < 0.5f) {
                local_2 = func_800D3948() ? 0x99D : 0x805;
            } else if (local_0 < 0.799987793f) {
                local_2 = func_800D3948() ? 0x99E : 0x804;
            } else {
                local_2 = func_800D3948() ? 0x99F : 0x806;
            }
            break;
        case 1:
            local_2 = 0x805;
            func_800EFA4C(local_4.f, -716.0f, 0.0f, -1173.0f);
            local_1 = 0;
            break;
        case 2:
            local_2 = 0x804;
            func_800EFA4C(local_4.f, 1203.0f, 0.0f, -810.0f);
            local_1 = 2;
            break;
        case 3:
            local_2 = 0x806;
            func_800EFA4C(local_4.f, 1050.0f, 0.0f, 500.0f);
            local_1 = 4;
            break;
        }
        local_3 = func_80108528(0x476, local_4.f, 0, &param_0);
        local_3->scale = 0.5f;
        func_80103140(local_3, (u16)local_2, local_3->unk0->unk16);
        func_80102424(local_3, local_3->unk70_10);
        local_3->unk3C = param_0->unk0;
        if (local_1 != -1) {
            func_808016B4_chtrashcangame(param_0, param_0->unk0, local_1, 0x10);
        }
        if (param_1 != 0) {
            local_3->unk64_20 = param_1 == param_0->unk79_4;
        } else {
            local_3->unk64_20 = func_800DC0C0() < 0.3f;
        }
    }
}

int chtrashcangame_entrypoint_0()
{
    return (int)&D_808031B4_chtrashcangame;
}

void func_80801CF0_chtrashcangame(s32 param_0)
{
  s32 local_0;
  _subaddiemulti_entrypoint_3(1);
  {
    for (local_0 = 0; local_0 < _gcstatusDll_entrypoint_11(); local_0++)
    {
      func_800946C4(func_800F53D0(local_0 | 0), 1);
    }

  }
}

void func_80801D54_chtrashcangame(u8 *param_0)
{
  s32 var_s0;
  s32 var_s0_2;
  u32 temp_t6;
  u32 temp_v0;
  u8 *temp_v0_2;
  temp_t6 = (u16) (*((u16 *) (((char *) param_0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  switch (temp_t6)
  {
    case 1:
      if ((func_800C954C() == 0) && (func_800DA298(0x6AD) == 0))
    {
      func_80801EE8_chtrashcangame(param_0, 2);
      return;
    }

    case 2:
      return;

    case 3:
      temp_v0 = *((u32 *) (((char *) param_0) + 0x70));
      temp_v0_2 = func_800CC63C((temp_v0 >> 0x19) - 1, (((u32) (temp_v0 << 0x16)) >> 0x1A) - 1);
      _subaddiemulti_entrypoint_6(temp_v0_2, *((s32 *) (((char *) temp_v0_2) + 0x10)));
      var_s0 = 0;
      if (_gcstatusDll_entrypoint_11() > 0)
    {
      do
      {
        func_800D2498(var_s0 + 0xC3, func_80800014_chtrashcangame(param_0, var_s0), 0);
        var_s0++;
      }
      while (var_s0 < _gcstatusDll_entrypoint_11());
    }
      if (func_800D90A4(param_0 + 0x58) != 0)
    {
      *((float *) (((char *) param_0) + 0x58)) = 0.2999878f;
      func_80108B04(param_0, 0);
    }
      if (func_800CEAD0(0) != 0)
    {
      func_80801EE8_chtrashcangame(param_0, 4);
      return;
    }
      break;

    case 4:
      var_s0_2 = 0;
      if (_gcstatusDll_entrypoint_11() > 0)
    {
      do
      {
        if (var_s0_2 == (*((s32 *) (((char *) param_0) + 0x20))))
        {
          func_800D28A0(var_s0_2 + 0xC3);
        }
        func_800D2498(var_s0_2 + 0xC3, func_80800014_chtrashcangame(param_0, var_s0_2), 0);
        var_s0_2++;
      }
      while (var_s0_2 < _gcstatusDll_entrypoint_11());
    }
      break;

  }

}

void func_80801EE8_chtrashcangame(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    switch (param_1) {
    case 2:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x13ED, 0xF, 0, 0x6A);
        func_80800000_chtrashcangame(param_0);
        break;
    case 3:
        param_0->unk58 = 0.299987793f;
        *(s32 *)&param_0->unk50 = 0;
        param_0->actorData[7] = 10;
        for (local_0 = 0; local_0 < _gcstatusDll_entrypoint_11(); local_0++) {
            func_80800098_chtrashcangame(param_0, local_0, 0);
            func_800D2748(local_0 + 0xC3, local_0 + 0x5F);
        }
        func_800CE8D8(0, 60.0f, 60);
        func_800CE88C(0, 1);
        _subaddiemulti_entrypoint_2();
        func_800FDC28(12);
        break;
    case 4:
        local_2 = 0;
        param_0->actorData[1] = func_80800014_chtrashcangame(param_0, 0);
        param_0->actorData[2] = 0;
        func_800AA20C(0, param_0->actorData[1]);
        func_800FC660(0x10);
        for (local_0 = 1; local_0 < _gcstatusDll_entrypoint_11(); local_0++) {
            local_1 = func_80800014_chtrashcangame(param_0, local_0);
            if ((s32)param_0->actorData[1] < local_1) {
                param_0->actorData[1] = local_1;
                param_0->actorData[2] = local_0;
            } else if (local_1 == param_0->actorData[1]) {
                local_2 = 1;
            }
            func_800AA20C(local_0, local_1);
        }
        if (local_2) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x13DF, 7, 0, 0x6A);
        } else {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x13DE, 7, 0, 0x6A);
        }
        _subaddiemulti_entrypoint_0(1);
        break;
    }
    func_80101FDC(param_0, param_1);
}

s32 func_808020D8_chtrashcangame(Actor *param_0, s32 param_1, TrashCanEventValue param_2)
{
    switch (param_1) {
        case 0x2E:
            switch (param_2.local_1[0]) {
                case 0x13ED:
                    func_80801EE8_chtrashcangame(param_0, 3);
                    return 1;
                case 0x13DE:
                case 0x13DF:
                    _gcfrontend_entrypoint_10(param_0);
                    return 1;
                default: return 1;
            }
            break;
        case 0x30:
            if (param_2.local_1[1]) return param_0->actorData[1];
            return param_0->actorData[2] + 1;
        case 0x95:
            _subaddiemulti_entrypoint_0(0);
            _subaddiemulti_entrypoint_4(0);
            return 1;
        case 0x3D:
            func_808019EC_chtrashcangame(param_0, param_2.local_0);
            return 1;
        default: return 0;
    }
    return 1;
}

int chtrashcangame_entrypoint_1()
{
  return (int)&D_808031FC_chtrashcangame;
}

void func_808021BC_chtrashcangame(Actor *param_0)
{
    f32 local_0[3];

    param_0->position[1] = func_800C6920(param_0->position, 1000.0f, -1000.0f, 0);
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    func_80102424(param_0, 1);
    param_0->unk58 = 0.0f;
    func_800F5A00(func_800F54E4(), local_0);
    param_0->rotation[1] = func_800F1DF4(param_0->position, local_0);
}

void func_8080223C_chtrashcangame(Actor *param_0)
{
    extern u8 D_8080326C_chtrashcangame[];
    extern u8 D_808032C0_chtrashcangame[];
    extern u8 D_80803300_chtrashcangame[];
    s32 local_0;

    switch (param_0->unk70_10) {
        case 1:
            if (func_80101E14(param_0, 0.01f)) {
                if (func_8010C754(param_0) < 1500 || func_800DB9B0()) {
                    if (!func_800D3948()) {
                        func_800BBCB8(param_0->position, param_0->position,
                                     1.0f, 5, D_8080326C_chtrashcangame);
                    }
                    func_800C4140(
                        (((u32)(func_800DC178(0.45f, 0.65f) * 1023.0f) & 0x7FF) << 21) + 0x1FFCB7,
                        param_0->position, 0x05DC0190);
                }
            }
            param_0->position[1] = *(f32 *)&param_0->actorData[1] +
                (func_80013970(func_80101F24(param_0) * 135.0f) - 0.707f) *
                (func_80103EF4(param_0) * 1.25f);
            param_0->scale = func_80101F24(param_0) * 0.8f + 0.2f;
            if (func_80101DDC(param_0)) {
                if (param_0->unk64_20) {
                    func_80102424(param_0, 3);
                } else {
                    param_0->unk58 = func_800DC178(2.0f, 3.0f);
                    func_80102424(param_0, 2);
                }
            }
            break;
        case 3:
            if (func_80101E14(param_0, 0.1f)) {
                if (func_8010C754(param_0) < 1500) {
                    func_800C4140(
                        (((u32)(func_800DC178(0.75f, 0.85f) * 1023.0f) & 0x7FF) << 21) + 0x157C9D,
                        param_0->position, 0x05DC0190);
                }
            }
            if (!func_800D3948() && func_80101E4C(param_0, D_80803300_chtrashcangame)) {
                local_0 = func_800BABB8(0, param_0->position, param_0->position,
                                      1.0f, D_808032C0_chtrashcangame);
                if (func_800DC0C0() < 0.5f) {
                    func_800BA994(local_0, -20, (s16)param_0->rotation[1] - 75,
                                 300, -45, (s16)param_0->rotation[1] - 75, 500);
                } else {
                    func_800BA994(local_0, -20, (s16)param_0->rotation[1] + 75,
                                 300, -45, (s16)param_0->rotation[1] + 75, 500);
                }
                func_800BA22C(local_0, 1);
            }
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 4);
            }
            break;
        case 2:
            if (func_800D90A4(&param_0->unk58)) {
                func_80102424(param_0, 4);
            }
            break;
        case 4:
            if (func_80101E14(param_0, 0.05f)) {
                if (func_8010C754(param_0) < 1500) {
                    if (!func_800D3948()) {
                        func_800BBCB8(param_0->position, param_0->position,
                                     1.0f, 5, D_8080326C_chtrashcangame);
                    }
                    func_800C4140(
                        (((u32)(func_800DC178(0.45f, 0.65f) * 1023.0f) & 0x7FF) << 21) + 0x1FFC01,
                        param_0->position, 0x05DC0190);
                }
            }
            if (func_80101DDC(param_0)) {
                (*(s32 *)&func_80106790(param_0->unk3C)->unk50)--;
                func_800FFA88(param_0->unk0);
            }
            param_0->position[1] = *(f32 *)&param_0->actorData[1] +
                (func_80013970(func_80101F24(param_0) * 135.0f) - 0.707f) *
                (func_80103EF4(param_0) * 1.25f);
            param_0->scale = func_80101F24(param_0) * 0.8f + 0.2f;
            break;
    }
    if (param_0->scale > 0.5f) {
        param_0->scale = 0.5f;
    }
    func_800F4F34(func_800F54E4(), param_0->position, func_80103EAC(param_0) * 2.0f, func_80103EAC(param_0) * 0.4f);
}

s32 func_8080292C_chtrashcangame(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    Actor *local_2;
    s32 local_3;
    s32 local_4;

    if (param_1 == 0x40) {
        local_0 = func_800B53A4(func_800D3948() ? 2 : 6);
        local_2 = func_80106790(param_0->unk3C);
        local_4 = 0;
        func_800BABB8(local_0, param_0->position, param_0->position, 1.0f, D_80803324_chtrashcangame);
        if (!func_800D3948()) {
            local_1 = func_800BABB8(0, param_0->position, param_0->position, 1.0f, D_80803364_chtrashcangame);
        } else {
            local_4 = _subaddiemulti_entrypoint_5(param_2);
        }
        switch (param_0->unk0->unk14) {
            case 0x805:
            case 0x99D:
                if (!func_800D3948()) {
                    func_800BAB80(local_1, D_80803394_chtrashcangame);
                }
                func_800BA670(local_0, 0x920);
                local_3 = 1;
                break;
            case 0x804:
            case 0x99E:
                if (!func_800D3948()) {
                    func_800BAB80(local_1, D_80803398_chtrashcangame);
                }
                func_800BA670(local_0, 0x921);
                local_3 = 2;
                break;
            case 0x806:
            case 0x99F:
                if (!func_800D3948()) {
                    func_800BAB80(local_1, D_8080339C_chtrashcangame);
                }
                func_800BA670(local_0, 0x922);
                local_3 = 3;
                break;
        }
        func_80800144_chtrashcangame(func_80106790(param_0->unk3C), local_4, local_3);
        func_800BA22C(local_0, func_800D3948() ? 2 : 6);
        if (!func_800D3948()) {
            func_800BA22C(local_1, 6);
        }
        *(s32 *)&local_2->unk50 -= 1;
        _chscorepoints_entrypoint_2(local_3, local_4, param_0->position, 1);
        func_800FFA88(param_0->unk0);
        func_800C4140((((u32)(func_800DC178(0.45f, 0.65f) * 1023.0f) & 0x7FF) << 21) +
            0x1FFC1F, param_0->position, 0x05DC0190);
        return 1;
    }
    return 0;
}

int chtrashcangame_entrypoint_2()
{
  return (int)&D_808033A0_chtrashcangame;
}

void func_80802C40_chtrashcangame(f32 *param_0)
{
    f32 local_0[3];
    s32 local_1;

    local_1 = func_800F54E4();
    if (func_800F64A4(local_1, 0x400)) {
        func_800EFA4C(local_0, param_0[1], 1300.0f, param_0[3]);
        local_0[1] += 150.0f;
        _sudeflect_entrypoint_0(local_0, 0.0f, 200.0f, 2);
    }
}

int *chtrashcangame_entrypoint_3()
{
    return &D_808033E8_chtrashcangame;
}

void func_80802CC0_chtrashcangame(Actor *param_0)
{
    _chdoormake_entrypoint_3(param_0, param_0->rotation[1], 90.0f, func_80103EF4(param_0), 0x802, 0);
    _chdoormake_entrypoint_8(param_0, 2);
    _chdoormake_entrypoint_5(param_0, 2.0f);
}

int chtrashcangame_entrypoint_4()
{
    return &D_80803430_chtrashcangame;
}
