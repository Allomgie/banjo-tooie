#include "common.h"

extern s32 func_800EA05C(void);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800BBCB8(Actor *, int, float, int, void (*)(void));
extern f32 D_80804FFC_chstoneballcontrol[];
extern void *func_80100094(Actor *, u32);
extern int D_80805038_chstoneballcontrol[][4];
extern s32 D_80805088_chstoneballcontrol[];
typedef struct { u8 pad_0[0x39]; u8 local_0; } StoneBallController;
typedef struct { u8 pad_0[0x72]; u8 local_0 : 6; u8 pad_1 : 2; } StoneBallState;
typedef struct { u8 pad_0[0x20]; s32 local_0[4]; u8 local_1[4]; u8 local_2[4]; u8 pad_1; u8 local_3; u8 local_4; u8 local_5; u8 local_6; } StoneballScoreState;
typedef struct { u8 local_0[0x64]; u32 local_1 : 2; u32 local_2 : 1; u32 local_3 : 29; } local_struct;
extern void func_800EE780(f32 *, f32 *, f32 *);
extern Vec3f D_808050B0_chstoneballcontrol;
extern f32 func_800DC178(f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern Actor *func_80106790();
extern Unk80132ED0 *_sukickball_entrypoint_8(Actor *, s32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 _sukickball_entrypoint_6(Actor *, s32);
extern void func_800F5A00(void *, f32 *);
extern u8 unk65[];
extern u8 unk39[];
typedef struct { u8 pad[0x10]; s32 a[9]; u8 b[6]; u8 count; } StoneS;
extern u8 unk6A[];
typedef struct { u8 pad_0[0xA]; u8 local_0[6]; Unk80132ED0 *local_1[4]; u8 pad_1[0x14]; u8 local_2[4]; } StoneBallStart1773;
extern f32 _sukickball_entrypoint_15(s32);
extern void _sukickball_entrypoint_16(s32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct Mass45StoneCounts { s32 local_0[4]; } Mass45StoneCounts;
extern s32 D_808050BC_chstoneballcontrol[];
typedef struct StoneBallTypes { s32 local_0[2]; } StoneBallTypes;
extern StoneBallTypes D_808050CC_chstoneballcontrol;
typedef struct { u8 pad_0[0xA]; u8 local_0[4]; u8 pad_1[2]; Unk80132ED0 *local_1[4]; } StoneBallPlayers1472;
extern f32 D_80805010_chstoneballcontrol[][2];
extern f32 func_800DC0C0(void);
extern void *D_808050D4_chstoneballcontrol;
extern s32 D_8080511C_chstoneballcontrol;
extern void func_800B4470(f32 *, f32 *, void *, s32, f32, f32, s32, s32, s32);
extern void _sukickball_entrypoint_11(Actor *, s32);
extern void func_800F4F98();
extern s32 D_80804FD4_chstoneballcontrol[];
extern s32 D_80805134_chstoneballcontrol[];
extern u8 D_80804FE8_chstoneballcontrol[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 D_80805178_chstoneballcontrol[];
extern u8 D_808051C0_chstoneballcontrol[];
extern u8 D_80805210_chstoneballcontrol[];
typedef struct { Unk80132ED0 *local_0; s32 local_1; u32 local_2; } StoneballSpatialEntry;
typedef struct { u8 pad_0[0x24]; u32 local_0 : 10; u32 pad_1 : 22; } StoneballMarkerC010;
extern s32 *func_800BE3F8(f32 *);
extern void *func_800E9E88(s32);
extern void *func_800E9EB4(s32);
typedef struct { u8 pad_0[0x1C]; f32 local_0; } StoneBallContact1472;
extern s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
extern void func_800C4140(s32, f32 *, s32);
extern s32 D_808052A0_chstoneballcontrol[];
extern f32 func_800D8FF8(void);
extern f32 func_800F5F24(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int D_808052CC_chstoneballcontrol[];
extern s32 D_80805314_chstoneballcontrol[];
extern int D_8080535C_chstoneballcontrol[];
typedef union { s32 local_0; void *local_1; } StoneballControlEvent;
extern u8 position_x[];
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct { u8 pad[0x65]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS101;
typedef struct { s32 a, b, c; } W3;
extern u32 D_8080541C_chstoneballcontrol[3];
extern f32 func_800EEF94(void *);
extern void func_800F5D70(s32, f32 *);
extern void func_800F8294(s32, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800F7700(s32, s32, void *);
extern s32 _sukickball_entrypoint_12(void *, s32);
extern s32 func_800F52B8(s32, s32);
extern f32 func_800F1DF4(f32 *, void *);
typedef struct { u8 pad_0[0x64]; u32 local_0 : 1; u32 pad_1 : 1; u32 local_1 : 1; u32 local_2 : 2; u32 pad_2 : 27; } StoneBallFlags31;
typedef struct Mass45StoneVector_80804B60_chstoneballcontrol { f32 local_0[3]; } Mass45StoneVector_80804B60_chstoneballcontrol;
extern s32 D_80805428_chstoneballcontrol[3];
extern f32 func_800136E4(f32);
extern int D_80805434_chstoneballcontrol[];
extern s32 func_800D211C();
extern void func_800CE8D8(s32, f32, s32);
extern void func_800FDC28(s32);
extern s32 _capod_entrypoint_17(f32);
extern s32 func_800CEB54(s32, f32);
extern u8 D_8080509C_chstoneballcontrol[];
extern Actor *func_801084B0(s32, Actor **);
extern void func_8008FB58(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EFBFC(f32 *, f32 *);
extern void func_800D9078(f32 *);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern s32 _sukickball_entrypoint_7(Actor *, s32);
extern f32 D_80805258_chstoneballcontrol[][3];
typedef struct { f32 unk0; u8 pad_4[0x1C]; u8 unk20; } BallControlLocal;
typedef struct { f32 local_0[4]; } StoneballDistancesC010;
typedef struct { f32 local_0[3]; } Mass45StoneVector_80803148_chstoneballcontrol;
typedef struct { f32 local_0; u8 pad_0[0x1C]; u8 local_1; } StoneballStateC010;
typedef struct { u8 pad_0[0x3A]; u8 local_0; } StoneballPlayersC010;
extern StoneballDistancesC010 D_808052B0_chstoneballcontrol;
extern Mass45StoneVector_80803148_chstoneballcontrol D_808052C0_chstoneballcontrol;
extern u8 _chstoneballcontrol_entrypoint_1[];
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct { s32 local_0; f32 local_1; f32 local_2[3]; } StoneballDataTop50;
typedef struct { u8 pad_0[0x64]; u32 pad_1:2; u32 local_0:1; u32 pad_2:29; } StoneballEnableTop50;
extern s32 _sukickball_entrypoint_5(Actor *, f32 *);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern void _sukickball_entrypoint_2(Actor *, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800DC298(f32);
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, f32 *);
void func_80801638_chstoneballcontrol();
void func_80801734_chstoneballcontrol();
void func_80801808_chstoneballcontrol();
void func_80801884_chstoneballcontrol();
void func_808024F8_chstoneballcontrol();
void func_80802588_chstoneballcontrol();
void func_80802648_chstoneballcontrol();
void func_80802D9C_chstoneballcontrol();
void func_80802E30_chstoneballcontrol();
void func_80802EA0_chstoneballcontrol();
int func_80803538_chstoneballcontrol();
void func_8080419C_chstoneballcontrol();
void func_80804D40_chstoneballcontrol();
void func_80804DA0_chstoneballcontrol();
f32 func_8080009C_chstoneballcontrol();
void func_8080079C_chstoneballcontrol();
void func_80800D20_chstoneballcontrol();
void func_80800F9C_chstoneballcontrol();
void func_80802418_chstoneballcontrol();
s32 func_808026A0_chstoneballcontrol();
void func_8080282C_chstoneballcontrol();
void func_80802F14_chstoneballcontrol();
void func_80803148_chstoneballcontrol();
s32 func_80803FF4_chstoneballcontrol();
Actor *func_80804810_chstoneballcontrol();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_8080079C_chstoneballcontrol(), func_80800F9C_chstoneballcontrol();

int func_80800000_chstoneballcontrol(s32 param_0[4], s32 param_1, s32 param_2)
{
  u32 local_0;
  u32 local_1;
  local_0 = param_0[0];
  local_1 = param_2 | 0xE;
  return _subaddiedialog_entrypoint_11(local_0, param_1, local_1, param_0 + 1, 0x33);
}

f32 func_80800040_chstoneballcontrol(Actor *param_0) {
    return D_80804FFC_chstoneballcontrol[((u8 *)func_80100094(param_0, 0))[0x14]];
}

f32 func_80800070_chstoneballcontrol(Actor *param_0) {
    return func_80800040_chstoneballcontrol(param_0) * 0.75f;
}

f32 func_8080009C_chstoneballcontrol(param_0) Actor *param_0; {
    return func_80800040_chstoneballcontrol(param_0) * 0.33f;
}

f32 func_808000C8_chstoneballcontrol(Actor *);
f32 func_808000C8_chstoneballcontrol(param_0) Actor *param_0; {
    return func_80800040_chstoneballcontrol(param_0) * 0.05f;
}

f32 func_808000F4_chstoneballcontrol(Actor *param_0)
{
    return func_808000C8_chstoneballcontrol(param_0);
}

int func_80800114_chstoneballcontrol(s32 param_0, s32 param_1)
{
  return D_80805038_chstoneballcontrol[param_0][param_1];
}

int func_80800130_chstoneballcontrol(s32 param_0)
{
  return D_80805088_chstoneballcontrol[param_0];
}

void func_80800144_chstoneballcontrol(Actor *param_0)
{
    StoneBallController *local_0;

    local_0 = func_80100094(param_0, 0);
    _sukickball_entrypoint_17(param_0);
    if (!func_800DA298(0x6AD) && param_0->unk79_4 != 1 && !param_0->unk64_20) {
        if (param_0->unk79_4 == 2) _capod_entrypoint_14();
        switch (local_0->local_0) {
        case 0:
        case 1:
        case 2:
            func_800A54F8(0);
            break;
        }
        func_80800000_chstoneballcontrol(param_0, 0xF1C, 0);
        ((StoneBallState *)param_0)->local_0 = 3;
    }
}

void func_80800210_chstoneballcontrol(s32 *param_0, s32 param_1)
{
    u8 *local_0;

    if (1) {}
    switch (param_1) {
    case 1:
    case 6:
        local_0 = func_801084B0(0x155, &param_0);
        break;
    case 3:
        local_0 = func_801084B0(0x1B8, &param_0);
        break;
    case 2:
        local_0 = func_801084B0(0x29E, &param_0);
        break;
    }
    if (func_800EA05C() != 0xBB) {
        *(f32 *)(local_0 + 4) = func_800DC178(-470.0f, 470.0f);
        *(f32 *)(local_0 + 0xC) = func_800DC178(-470.0f, 470.0f);
    } else if (param_1 != 6) {
        *(f32 *)(local_0 + 4) = func_800DC178(-2850.0f, -1350.0f);
        *(f32 *)(local_0 + 0xC) = func_800DC178(-1350.0f, -650.0f);
    } else {
        *(f32 *)(local_0 + 4) = -2100.0f;
        *(f32 *)(local_0 + 0xC) = -1000.0f;
    }
    *(s32 *)(local_0 + 0x3C) = param_0[0];
}

s32 func_80800360_chstoneballcontrol(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    f32 local_1;
    s16 *local_4;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_4 = (s16 *)&param_2;
    switch (param_1) {
    case 0xB:
        param_0->unk79_4 = 2;
        return 3;
    case 0xE:
        switch (local_0[0x39]) {
        case 0:
            local_1 = 0.5f;
            break;
        case 1:
            local_1 = 0.5f;
            break;
        case 2:
            local_1 = 0.5f;
            break;
        }
        if (_capod_entrypoint_17(local_1)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, local_0[0x39] + 0xF3E, 6, (f32 *)((u8 *)func_80106790(_sukickball_entrypoint_8(param_0, local_0[0x39] + 1)) + 4), 0);
            param_0->unk64_20 = 1;
        }
        return 3;
    case 0x2E:
        switch (local_4[0]) {
        case 0xF4D:
        case 0xF4E:
            if (func_800D2054(0, local_0[0x39] + 0x8E, *(s32 *)(local_0 + 0x20)) == 1) {
                func_80800000_chstoneballcontrol(param_0, 0xF57, 0);
                break;
            }
        case 0xF21:
        case 0xF22:
        case 0xF57:
            func_80800000_chstoneballcontrol(param_0, 0xCEB, 0x40);
            break;
        case 0xF51:
        case 0xF52:
            _gcfrontend_entrypoint_10();
            break;
        case 0xCEB:
            if (func_800D395C()) {
                if (local_4[1] == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else if (local_4[1] == 1) {
                _gcgoto_entrypoint_1(func_800EA05C(), 1);
            } else {
                _gcgoto_entrypoint_1(0xBB, 4);
            }
            break;
        case 0xF1C:
            func_800FDC28(0xD);
            local_2 = func_80800130_chstoneballcontrol(local_0[0x39]);
            func_800CE8D8(0, local_2, (s32)(f32)func_80800130_chstoneballcontrol(local_0[0x39]));
            func_800CE88C(0, 1);
            func_80801734_chstoneballcontrol(param_0, 0);
            param_0->unk70_10 = 4;
            break;
        case 0xF3E:
        case 0xF3F:
        case 0xF40:
            param_0->unk64_20 = 0;
            break;
        }
        break;
    case 0x30:
        switch (local_4[0]) {
        case 0xF51:
            return local_0[0x3B];
        case 0xF57:
            return func_800D211C(local_0[0x39] + 0x8E);
        }
        break;
    case 0x3D:
        func_80800210_chstoneballcontrol(param_0, param_2);
        break;
    case 0x49:
        switch (local_0[0x39]) {
        case 0:
        case 1:
        case 2:
            if (!func_800D395C()) {
                if (!func_800DA9E4(local_0[0x39] + 0x41C, 1)) {
                    _capod_entrypoint_13(param_0->unk0, 0, 1, 0x2020);
                    param_0->unk79_4 = 1;
                    break;
                }
            }
            func_800A54F8(0);
            break;
        case 3:
            break;
        case 4:
            _subaddiemulti_entrypoint_4(0);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800908_chstoneballcontrol();

void func_8080079C_chstoneballcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    *(f32 *)(local_0 + 0) -= local_1;
    *(f32 *)(local_0 + 4) -= local_1;
    switch (param_0->unk70_10) {
        case 1:
            func_80800144_chstoneballcontrol(param_0);
            return;
        case 3:
            _sukickball_entrypoint_17(param_0);
            return;
        case 6:
            _sukickball_entrypoint_19(param_0, 1, local_0[0x3A]);
            return;
        case 4:
            _sukickball_entrypoint_19(param_0, 0, local_0[0x3A]);
            func_8080145C_chstoneballcontrol(param_0);
            if (func_800CEB54(0, 6.0f)) {
                func_800FDC28(0xE);
                return;
            }
            if (func_800CEAD0(0)) func_80800908_chstoneballcontrol(param_0);
            return;
        case 7:
            func_8080145C_chstoneballcontrol(param_0);
            return;
        case 8:
            _sukickball_entrypoint_19(param_0, 1, local_0[0x3A]);
            if (param_0->unk58 > 0.0f) param_0->unk58 -= func_800D8FF8();
            else _gcgoto_entrypoint_1(0xBB, 4);
            break;
    }
}

void func_80800908_chstoneballcontrol(Actor *param_0)
{
    StoneballScoreState *local_0;
    s32 local_1[4];
    s32 local_3[4];
    s32 local_2;
    s32 local_4;
    s32 local_5;
    s32 local_6;

    local_0 = func_80100094(param_0, 0);
    param_0->unk70_10 = 6;
    func_800FDC28(0);
    func_80801734_chstoneballcontrol(param_0, 1);
    local_2 = _sumultiscore_entrypoint_2(local_0->local_0, local_1, local_3, 0, local_0->local_4);
    if (local_0->local_3 < 3) {
        if (param_0->unk64_19) {
            switch (local_1[0]) {
            case 1:
                if (local_3[0] == 0) {
                    func_800FC6B0(0x16);
                    func_80800000_chstoneballcontrol(param_0, 0xF4D, 0x200);
                    break;
                }
            case 2:
            case 3:
            case 4:
                func_80800000_chstoneballcontrol(param_0, 0xF4E, 0x200);
                func_800FC6B0(0x17);
                break;
            }
        } else {
            switch (local_1[0]) {
            case 1:
                if (local_3[0] == 0) {
                    func_800D2054(0, local_0->local_3 + 0x8E, local_0->local_0[0]);
                    func_800DA544(0x9CB);
                    func_800FC6B0(0x16);
                    func_80101FDC(param_0, 8);
                    param_0->unk58 = 2.5f;
                    break;
                }
            case 2:
            case 3:
                func_800FC6B0(0x17);
                func_80800000_chstoneballcontrol(param_0, 0xF21, 0x200);
                break;
            case 4:
                func_80800000_chstoneballcontrol(param_0, 0xF22, 0x200);
                func_800FC6B0(0x17);
                break;
            }
        }
    } else {
        for (local_5 = 0; local_5 < local_0->local_4; local_5++) {
            if (local_1[local_5] == 1) local_0->local_1[local_5] = 1;
            else local_0->local_1[local_5] = 0;
        }
        if (local_2 != 0) {
            local_4 = 0xF51;
            local_0->local_5 = local_2;
        } else {
            local_4 = 0xF52;
        }
        func_800FC6B0(0x10);
        func_80800000_chstoneballcontrol(param_0, local_4, 0);
    }
}

void func_80800B4C_chstoneballcontrol(Actor *param_0, s32 param_1)
{
  func_80102424(param_0, param_1);
  switch ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) {
    case 2:
      if (((local_struct *)param_0)->local_2) {
        *(u8 *)((u8 *)param_0 + 0x72) = (*(u8 *)((u8 *)param_0 + 0x72) & 0xFF03) | 0x28;
        *(f32 *)((u8 *)param_0 + 0x58) = 0.0f;
      }
      break;
    case 8:
      *(f32 *)((u8 *)param_0 + 0x50) = 0.0f;
      break;
  }
}

void func_80800BCC_chstoneballcontrol(Actor *param_0, f32 *param_1)
{
    Vec3f local_0 = D_808050B0_chstoneballcontrol;
    f32 local_1;
    f32 local_2;

    if (!param_1) local_1 = param_0->rotation[1] + func_800DC178(110.0f, 250.0f);
    else {
        local_2 = func_80102D78(param_0, param_1);
        local_1 = func_800DC178(110.0f, 250.0f) + local_2;
    }
    func_800EFCD8(local_0.f, local_1, 500.0f);
    func_800EE780(param_0->actorData, param_0->position, local_0.f);
    *(f32 *)&param_0->actorData[3] = func_8080009C_chstoneballcontrol(param_0);
    if (*(f32 *)&param_0->actorData[0] > 720.0f) *(f32 *)&param_0->actorData[0] = 720.0f;
    if (*(f32 *)&param_0->actorData[2] > 720.0f) *(f32 *)&param_0->actorData[2] = 720.0f;
    if (*(f32 *)&param_0->actorData[0] < -720.0f) *(f32 *)&param_0->actorData[0] = -720.0f;
    if (*(f32 *)&param_0->actorData[2] < -720.0f) *(f32 *)&param_0->actorData[2] = -720.0f;
    *(f32 *)&param_0->actorData[7] = func_800DC178(0.25f, 1.0f);
    func_80800B4C_chstoneballcontrol(param_0, 7);
}

void func_80800D20_chstoneballcontrol(param_0) Actor *param_0;
{
    *(f32 *)&param_0->actorData[3] = func_8080009C_chstoneballcontrol(param_0);
    *(f32 *)&param_0->actorData[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        *(f32 *)&param_0->actorData[7] = -*(f32 *)&param_0->actorData[7];
    }
    func_80800B4C_chstoneballcontrol(param_0, 9);
    param_0->unk64_20 = 1;
}

void func_80800DB4_chstoneballcontrol(Actor *param_0, f32 *param_1)
{
    u8 *local_1;
    Actor *local_2;
    f32 local_0[3];
    s32 local_3;

    local_1 = func_80100094(param_0, 0);
    for (local_3 = 0; local_3 < local_1[0x3A]; local_3++) {
        if (_sukickball_entrypoint_6(param_0, local_3)) {
            func_800F5A00(local_3, local_0);
            if (func_800F0064(local_0, 200.0f, param_1)) {
                func_800F7B9C(local_3, 0x38);
            }
        } else {
            local_2 = func_80106790(_sukickball_entrypoint_8(param_0, local_3));
            if (func_800F0064(local_2->position, 200.0f, param_1)) {
                func_80800D20_chstoneballcontrol(local_2);
            }
        }
    }
}

int func_80800EBC_chstoneballcontrol(Actor *param_0, s32 param_1)
{
  switch (param_1)
  {
    case 0 :
      func_800F82D4(param_0, 0);
      break;

    case 1 :
      func_800F82D4(param_0, 2);
      _baattach_entrypoint_6(func_800F53D0(param_0) | 0, 3, 0, 0);

  }

}

void func_80800F24_chstoneballcontrol(Actor *param_0, s32 param_1, s32 param_2)
{
  if (param_1 || func_800D395C())
  {
    *((u8 *) (((char *) param_0) + 0x65)) = ((*((u8 *) (((char *) param_0) + 0x65))) & 0xFFFFu) | 8;
    _chintrotext_entrypoint_1(0x18AF, param_2 + (0xF ^ 0), 0, 0);
  }
  else
  {
    *((u8 *) (((char *) param_0) + (0x65 & 0xFFFFFFFFu))) &= ~8;
    _chintrotext_entrypoint_2(1);
  }
}

void func_80801330_chstoneballcontrol();

void func_8080128C_chstoneballcontrol();

void func_80800F9C_chstoneballcontrol(param_0) Actor *param_0;
{
    s32 local_0;
    u8 *local_1;
    u8 *local_2;
    u8 *local_3;
    Actor *local_4;

    local_1 = func_80100094(param_0, 0);
    local_1[0x39] = _sukickball_entrypoint_3();
    local_1[0x3C] = 0;
    if (func_800DA298(0x667) || !func_80090178(0x80)) {
        func_800FFAB0(param_0);
        return;
    }
    if (func_800EA05C() != 0xBB) func_800DA3B8(0x65A, 1);
    local_1[0x3A] = ((s32 *)D_8080509C_chstoneballcontrol)[local_1[0x39]];
    switch (local_1[0x39]) {
    case 0:
        local_1[0x39] = 0;
        func_80800F24_chstoneballcontrol(param_0, func_800DA298(0x5E), local_1[0x39]);
        break;
    case 1:
        func_80800F24_chstoneballcontrol(param_0, func_800DA298(0x5F), local_1[0x39]);
        break;
    case 2:
        func_80800F24_chstoneballcontrol(param_0, func_800D0A9C(3, 1), local_1[0x39]);
        break;
    case 3:
        break;
    case 4:
        local_0 = 0;
        do {
            if (func_800F6438(local_0)) func_800F4CEC(local_0, 0);
            local_0++;
        } while (local_0 != 8);
        local_1[0x3A] = _gcstatusDll_entrypoint_11();
        break;
    }
    func_8080128C_chstoneballcontrol(param_0);
    if (local_1[0x39] == 4) local_1[0xA] = 1;
    else local_1[0xA] = 2;
    local_1[0xB] = 1;
    local_1[0xC] = 1;
    local_1[0xD] = 1;
    for (local_0 = 0; local_0 < local_1[0x3A]; local_0++) {
        switch (local_1[local_0 + 0xA]) {
        case 1:
            local_4 = func_801084B0(0x1B6, &param_0);
            ((u32 *)(local_1 + 0x10))[local_0] = *(u32 *)local_4;
            *(u32 *)((u8 *)local_4 + 0x3C) = *(u32 *)param_0;
            break;
        case 2:
            break;
        }
        func_80801330_chstoneballcontrol(param_0, local_0);
    }
    if (func_800EA05C() == 0xBB) {
        func_8080145C_chstoneballcontrol(param_0);
        *((u8 *)param_0 + 0x72) = (*((u8 *)param_0 + 0x72) & 0xFF03) | 0x1C;
    }
    _sukickball_entrypoint_18(param_0);
    local_1[0x3C] = 1;
}

int func_8080120C_chstoneballcontrol(param_0) s32 param_0;
{
  Actor *local_0;
  s32 local_1;
  local_0 = func_80100094(param_0, 0);
  if ((*(u8 *)((char *)(local_0) + 0x3C)) != 0)
  {
    func_800DA3B8(0x65A, 0);
    if ((*(u8 *)((char *)(local_0) + 0x39)) == 4)
    {
      for (local_1 = 0; local_1 < 8; local_1++)
      {
        if (func_800F6438(local_1))
        {
          func_800F4CC0(local_1);
        }
      }

    }
  }
}

void func_8080128C_chstoneballcontrol(s32 param_0) {
    StoneS *local_0 = func_80100094(param_0, 0);
    s32 i;
    for (i = 0; i < local_0->count; i++) {
        local_0->b[i] = 0;
        local_0->a[i] = 0;
    }
}

void func_808012E0_chstoneballcontrol(Actor *param_0, s32 param_1)
{
    param_0->unk6C_0 = param_1;
    if (param_1 == 2) {
        param_0->unk64_24 = 1;
    } else {
        param_0->unk64_24 = 0;
    }
}

int func_80801320_chstoneballcontrol(Actor *param_0){
    return (*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF;
}

void func_80801330_chstoneballcontrol(Actor *param_0, s32 param_1)
{
    StoneBallStart1773 *local_0;
    Actor *local_1;
    u8 *local_2;
    f32 local_3[3];

    local_0 = func_80100094(param_0, 0);
    switch (local_0->local_0[param_1]) {
        case 1:
            local_1 = func_80106790(local_0->local_1[param_1]);
            local_2 = func_80100094(local_1, 0);
            _sukickball_entrypoint_16(param_1, local_1->position);
            func_800EE7F8((f32 *)(local_2 + 8), local_1->position);
            local_1->rotation[1] = _sukickball_entrypoint_15(param_1);
            local_1->unk54 = local_1->rotation[1];
            func_808012E0_chstoneballcontrol(local_1, param_1);
            break;
        case 2:
            if (func_800EA05C() != 0xBB) {
                func_800F82D4(param_1, 2);
                local_3[0] = 0.0f;
                local_3[1] = _sukickball_entrypoint_15(param_1);
                local_3[2] = 0.0f;
                func_800F832C(param_1, local_3);
                _sukickball_entrypoint_16(param_1, local_3);
                func_800F8294(param_1, local_3);
            }
            break;
    }
    local_0->local_2[param_1] = 0;
}

int func_8080145C_chstoneballcontrol(Actor *param_0)
{
    u8 *local_0;
    Mass45StoneCounts local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = *(Mass45StoneCounts *)D_808050BC_chstoneballcontrol;
    local_2 = -1;
    func_80801638_chstoneballcontrol(param_0, &local_1);
    if (local_0[0x39] == 3) {
        if (func_800DA298(0x5F) || func_800DA298(0x9EA)) {
            if (local_1.local_0[0] <= 0) {
                local_2 = 3;
            }
        } else if (func_800DA298(0x5E) || func_800DA298(0x9E9)) {
            if (local_1.local_0[0] <= 0) {
                local_2 = 2;
            }
        } else if (local_1.local_0[0] <= 0) {
            local_2 = 1;
        }
        if (local_2 != -1) {
            func_80108B04(param_0, local_2);
        }
    } else {
        if (local_1.local_0[1] < func_80800114_chstoneballcontrol(local_0[0x39], 1)) {
            local_2 = 1;
        } else if (local_1.local_0[2] < func_80800114_chstoneballcontrol(local_0[0x39], 2)) {
            local_2 = 2;
        } else if (local_1.local_0[3] < func_80800114_chstoneballcontrol(local_0[0x39], 3)) {
            local_2 = 3;
        }
        if (local_2 >= 0) {
            func_80108B04(param_0, local_2);
            return;
        }
        if (local_1.local_0[0] < func_80800114_chstoneballcontrol(local_0[0x39], 0)) {
            func_80801884_chstoneballcontrol(param_0);
        }
    }
}

void func_80801638_chstoneballcontrol(param_0, param_1) Actor *param_0; s32 *param_1;
{
    Actor *local_0[20];
    StoneBallTypes local_1 = D_808050CC_chstoneballcontrol;
    s32 local_2;
    s32 local_5;

    local_2 = _subaddiefind_entrypoint_6(local_1.local_0, local_0, 20);
    param_1[0] = param_1[1] = param_1[2] = 0;
    for (local_5 = 0; local_5 < local_2; local_5++) {
        switch (local_0[local_5]->unk6C_9) {
        case 0x155:
            param_1[1]++;
            break;
        case 0x29E:
            param_1[2]++;
            break;
        case 0x1B8:
            param_1[3]++;
            break;
        }
    }
    param_1[0] = param_1[1] + param_1[2] + param_1[3];
}

void func_80801734_chstoneballcontrol(param_0, param_1) s32 param_0; s32 param_1;
{
    s32 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if ((s32)*(u8 *)((char *)local_0 + 0x3A) > 0) {
        do {
            func_80801808_chstoneballcontrol(param_0, local_1, param_1);
            local_1 += 1;
        } while (local_1 < (s32)*(u8 *)((char *)local_0 + 0x3A));
    }
}

void func_808017AC_chstoneballcontrol(Unk80132ED0 *param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80106790(param_0);
  switch (param_1)
  {
    case 0 :
      func_80800B4C_chstoneballcontrol(local_0, 2);
      break;

    case 1 :
      func_80800B4C_chstoneballcontrol(local_0, 0xB);

  }

}

void func_80801808_chstoneballcontrol(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    StoneBallPlayers1472 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (local_0->local_0[param_1]) {
    case 0:
        break;
    case 2:
        func_80800EBC_chstoneballcontrol(param_1, param_2);
        break;
    case 1:
        func_808017AC_chstoneballcontrol(local_0->local_1[param_1], param_2);
        break;
    }
}

void func_80801884_chstoneballcontrol(param_0) Actor *param_0;
{
    u8 *local_1;
    f32 local_0;
    f32 *local_2;
    s32 local_3;

    local_1 = func_80100094(param_0, 0);
    local_0 = func_800DC0C0();
    if (func_800EA05C() != 0xBB || param_0->unk70_10 != 1) {
        local_2 = D_80805010_chstoneballcontrol[local_1[0x39]];
        if (local_0 < local_2[0]) {
            local_3 = 1;
        } else if (local_0 < local_2[1]) {
            local_3 = 2;
        } else {
            local_3 = 3;
        }
        func_80108B04(param_0, local_3);
    }
}

int chstoneballcontrol_entrypoint_0()
{
  return &D_808050D4_chstoneballcontrol;
}

void func_80801944_chstoneballcontrol(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 2 && param_1 != param_0->unk70_10) {
        if (param_0->unk3C) {
            if (_sukickball_entrypoint_6(func_80106790(param_0->unk3C), local_0[0x20])) func_800F4F98(local_0[0x20], param_0->unk0);
            _sukickball_entrypoint_11(func_80106790(param_0->unk3C), local_0[0x20]);
        }
    }
    if (param_0->unk70_10 == 3 && param_1 == 2 && (param_0->unk0->unk24 >> 22) == 0x253) {
        *(f32 *)(local_0 + 0x14) = 20.0f;
        *(f32 *)(local_0 + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(param_0);
        func_808024F8_chstoneballcontrol(param_0);
        param_1 = 4;
    }
    func_80101FDC(param_0, param_1);
    if (param_0->unk70_10 == 6) {
        func_808024F8_chstoneballcontrol(param_0);
        _subaddiefade_entrypoint_3(param_0);
        func_800B4470(param_0->position, 0, &D_8080511C_chstoneballcontrol, 1, 0.75f, 0.0f, 125, 250, 0);
        switch (param_0->unk0->unk24 >> 22) {
        case 0x267: func_80802588_chstoneballcontrol(param_0, 1); break;
        case 0x254: func_80802588_chstoneballcontrol(param_0, 2); break;
        }
    }
}

int func_80801B00_chstoneballcontrol(Actor *param_0)
{
  void *local_0;
  local_0 = func_80100094(param_0, 0 * 0);
  *((u8 *) (((char *) local_0) + 0x20)) = 0x7F;
  *((float *) (((char *) local_0) + 4)) = 0.0f;
  *((float *) (((char *) local_0) + 0)) = .0f;
  *((float *) (((char *) param_0) + 0x24)) = 0.0f;
}

void func_80801B44_chstoneballcontrol(Actor *param_0)
{
    param_0->unk74_17 = 0;
    func_8010A590(param_0);
    *(f32 *)((u8 *)param_0 + 0x38) = 1.5f;
    param_0->rotation[0] = func_800DC178(0.0f, 45.0f);
    param_0->rotation[2] = func_800DC178(0.0f, 45.0f);
    func_80801B00_chstoneballcontrol(param_0);
    if (func_800EA05C() != 0xBB) {
        param_0->position[1] = -75.0f;
    } else {
        param_0->position[1] = -425.0f;
    }
}

void func_80802C30_chstoneballcontrol();

void func_80802614_chstoneballcontrol();

void func_808023AC_chstoneballcontrol();

void func_80801BE0_chstoneballcontrol(Actor *param_0)
{
    extern u8 D_80805120_chstoneballcontrol[];

    char *local_0;
    Actor *local_1;
    f32 local_4[3];
    f32 local_3[3];
    f32 local_5[3];
    Actor *local_2;
    Actor *local_10;
    f32 local_6;
    f32 local_7;

    local_0 = (char *)func_80100094(param_0, 0);
    local_1 = func_80106790(
        *(void **)((char *)param_0 + 0x3C)
    );

    if (!func_80090178(0x80)) {
        func_8008FB58(
            param_0->position,
            0.0f,
            25.0f
        );
    }

    switch (param_0->unk70_10) {
        case 5:
            if (func_800EA05C() != 0xBB) {
                if (param_0->position[1] < 25.0f) {
                    param_0->position[1] += 5.0f;
                }
                if ((f32)(u32)param_0->alpha < 240.0f) {
                    *(u8 *)((char *)param_0 + 0x9B) =
                        (u32)((f32)(u32)param_0->alpha + 15.0f);
                    break;
                }

                if (25.0f <= param_0->position[1]) {
                    param_0->unk70_10 = 1;
                    *(u8 *)((char *)param_0 + 0x9B) = 0xFF;
                }
            } else {
                if (param_0->position[1] < -325.0f) {
                    param_0->position[1] += 5.0f;
                }
                if ((f32)(u32)param_0->alpha < 240.0f) {
                    *(u8 *)((char *)param_0 + 0x9B) =
                        (u32)((f32)(u32)param_0->alpha + 15.0f);
                    break;
                }

                if (-325.0f <= param_0->position[1]) {
                    param_0->unk70_10 = 1;
                    *(u8 *)((char *)param_0 + 0x9B) = 0xFF;
                }
            }
            break;

        case 1:
            func_80803148_chstoneballcontrol(param_0);
            func_80802C30_chstoneballcontrol(param_0);
            func_808023AC_chstoneballcontrol(param_0);
            break;

        case 2:
            func_800EE7F8(local_3, param_0->position);
            func_80802C30_chstoneballcontrol(param_0);

            if (_sukickball_entrypoint_6(
                    local_1,
                    *(u8 *)(local_0 + 0x20))) {
                func_800F5A00(
                    *(u8 *)(local_0 + 0x20),
                    local_4
                );

                *(f32 *)((char *)param_0 + 0x54) =
                    func_800F5F24(
                        *(u8 *)(local_0 + 0x20)
                    );

                *(f32 *)((char *)param_0 + 8) = 0.0f;

                func_800EFCD8(
                    param_0->position,
                    *(f32 *)((char *)param_0 + 0x54),
                    60.0f
                );

                func_800EF04C(param_0->position, local_4);

                func_800F5D70(
                    *(u8 *)(local_0 + 0x20),
                    local_5
                );

                *(f32 *)((char *)param_0 + 0x50) =
                    (local_5[0] * local_5[0]) +
                    (local_5[2] * local_5[2]);

                func_800EE7F8(
                    (char *)param_0 + 0x18,
                    local_4
                );
            } else {
                local_2 = func_80106790(
                    _sukickball_entrypoint_8(
                        local_1,
                        *(u8 *)(local_0 + 0x20)
                    )
                );

                *(f32 *)((char *)param_0 + 8) = 0.0f;

                func_800EFCD8(
                    (char *)param_0 + 4,
                    local_2->rotation[1],
                    60.0f
                );

                func_800EF04C(
                    (char *)param_0 + 4,
                    local_2->position
                );

                *(f32 *)((char *)param_0 + 0x54) =
                    local_2->rotation[1];

                *(f32 *)((char *)param_0 + 0x50) =
                    *(f32 *)&local_2->actorData[3] *
                    *(f32 *)&local_2->actorData[3];

                func_800EE7F8(
                    (char *)param_0 + 0x18,
                    local_2->position
                );
            }

            if (func_800EFBFC(
                    local_3,
                    (char *)param_0 + 4) > 25.0f) {
                if (func_800DC0C0() < 0.1f) {
                    func_800B4470(
                        local_3,
                        0,
                        D_80805120_chstoneballcontrol,
                        1,
                        0.75f,
                        0.0f,
                        75,
                        150,
                        0
                    );
                }
            }

            func_800D9078(local_0);
            func_80803148_chstoneballcontrol(param_0);

            if (_sukickball_entrypoint_7(
                    local_1,
                    *(u8 *)(local_0 + 0x20))) {
                local_10 = func_80106790(
                    _sukickball_entrypoint_8(
                        local_1,
                        *(u8 *)(local_0 + 0x20)
                    )
                );

                if (local_10->unk64_20 == 1) {
                    func_80803538_chstoneballcontrol(param_0);

                    local_10->unk58 = 0.0f;
                    local_10->unk64_20 = 0;
                }
            }

            func_808023AC_chstoneballcontrol(param_0);
            break;

        case 3:
            func_80802C30_chstoneballcontrol(param_0);

            func_800EF1B8(
                param_0->position,
                *(f32 *)((char *)param_0 + 0x48),
                *(f32 *)((char *)param_0 + 0x24) * func_800D8FF8()
            );

            *(f32 *)((char *)param_0 + 0x24) -= 6.0f;

            if ((param_0->unk0->unk24 >> 22)
                == 0x253) {
                if (*(f32 *)((char *)param_0 + 0x24) < 600.0f) {
                    *(f32 *)(local_0 + 0x14) +=
                        *(f32 *)(local_0 + 0x18);

                    *(f32 *)(local_0 + 0x18) += 0.5f;
                }
            }

            if (*(f32 *)((char *)param_0 + 0x24) <= 0.0f) {
                func_80801944_chstoneballcontrol(param_0, 1);
                func_808024F8_chstoneballcontrol(param_0);
            }

            func_80803148_chstoneballcontrol(param_0);

            if (func_800DC0C0() < 0.15f &&
                *(f32 *)((char *)param_0 + 0x24) > 120.0f) {
                func_800B4470(
                    param_0->position,
                    0,
                    D_80805120_chstoneballcontrol,
                    1,
                    0.75f,
                    0.0f,
                    50,
                    100,
                    0
                );
            }

            func_808023AC_chstoneballcontrol(param_0);
            break;

        case 4:
            func_80802C30_chstoneballcontrol(param_0);
            func_80802418_chstoneballcontrol(param_0);
            break;

        case 6:
            *(f32 *)((char *)param_0 + 0x24) -= 15.0f;
            func_80802418_chstoneballcontrol(param_0);
            break;
    }

    if (*(f32 *)((char *)param_0 + 0x24) > 30.0f) {
        local_6 =
            func_800137AC(
                *(f32 *)((char *)param_0 + 0x48)
            );

        local_7 = func_800137C4();

        *(f32 *)((char *)param_0 + 0x44) +=
            ((local_6 * *(f32 *)((char *)param_0 + 0x24)) +
             (local_6 * *(f32 *)((char *)param_0 + 0x24))) / 30.0f;

        *(f32 *)((char *)param_0 + 0x4C) -=
            ((local_7 * *(f32 *)((char *)param_0 + 0x24)) +
             (local_7 * *(f32 *)((char *)param_0 + 0x24))) / 30.0f;
    }

    if ((param_0->unk0->unk24 >> 22)
        == 0x253) {
            if (param_0->unk70_10 != 4 &&
            param_0->unk70_10 != 6 &&
            (param_0->unk7C_12)) {
            if (func_800DC0C0() < 0.1f) {
                func_80802614_chstoneballcontrol(local_0 + 8);
            }
        }
    }

    if (*(f32 *)(local_0 + 0x1C) > 0.0f) {
        *(f32 *)(local_0 + 0x1C) -= func_800D8FF8();
    }
}

void func_808023AC_chstoneballcontrol(Actor *param_0)
{
    s32 local_0;
    local_0 = func_808026A0_chstoneballcontrol(param_0);
    if (func_800EA05C() != 0xBB) param_0->position[1] = 30.0f;
    else param_0->position[1] = -320.0f;
    if (local_0 != -1) func_8080282C_chstoneballcontrol(param_0, local_0);
}

void func_80802418_chstoneballcontrol(param_0) u8 *param_0;
{
  f32 local_0;
  u8 local_1;
  local_1 = *((u8 *) (((s8 *) param_0) + 0x9B));
  *((f32 *) (((s8 *) param_0) + 8)) = (f32) ((*((f32 *) (((s8 *) param_0) + 8))) - 5.0f);
  local_1 += 0;
  local_0 = (f32) local_1;
  if (((s32) local_1) < 0)
  {
  }
  *((u8 *) (((s8 *) param_0) + 0x9B)) = (u8) ((u32) (local_0 * 0.7f));
  *((f32 *) (((s8 *) param_0) + 0x38)) = (f32) ((*((f32 *) (((s8 *) param_0) + 0x38))) * 0.95f);
}

void func_808024F8_chstoneballcontrol(param_0) u8 *param_0; {
    s32 local_0;

    local_0 = func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C))));
    if (((u32) (*(u32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0)))) + (0x24))) >> 0x16) == 0x253) {
        func_80802648_chstoneballcontrol(param_0 + 4);
        func_80802F14_chstoneballcontrol(param_0);
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80804FD4_chstoneballcontrol);
        _subaddiefade_entrypoint_3(param_0);
        func_80801944_chstoneballcontrol(param_0, 4);
        func_80800DB4_chstoneballcontrol(local_0, param_0 + 4);
    }
}

void func_80802588_chstoneballcontrol(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;

    local_0 = func_800BABB8(0, param_0->position, NULL, 1.0f, D_80805134_chstoneballcontrol);
    func_800BA670(local_0, param_1 == 1 ? 0x679 : 0x67A);
    func_800BA22C(local_0, 10);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80804FE8_chstoneballcontrol);
}

void func_80802614_chstoneballcontrol(s32 param_0) {
    func_800BBCB8(param_0, 0, 1.0f, 2, &D_80805178_chstoneballcontrol);
}

void func_80802648_chstoneballcontrol(param_0) Actor *param_0;
{
    func_800BBCB8(param_0, 0, 1.0f, 10, D_808051C0_chstoneballcontrol);
    func_800BBCB8(param_0, 0, 1.0f, 5, D_80805210_chstoneballcontrol);
}

s32 func_808026A0_chstoneballcontrol(param_0) Actor *param_0;
{
    s32 i;

    if (func_800EA05C() == 0xBB) {
        if (param_0->position[0] < -3055.0f) {
            return 2;
        }
        if (param_0->position[0] > -1145.0f) {
            return 0;
        }
        if (param_0->position[2] < -1555.0f) {
            return 3;
        }
        if (param_0->position[2] > -445.0f) {
            return 1;
        }
        for (i = 0; i < 6; i++) {
            if (func_800F0064(param_0->position, 100.0f, D_80805258_chstoneballcontrol[i])) {
                return 1;
            }
        }
        return -1;
    }
    if (param_0->position[0] < -675.0f) {
        return 2;
    }
    if (param_0->position[0] > 675.0f) {
        return 0;
    }
    if (param_0->position[2] < -675.0f) {
        return 3;
    }
    if (param_0->position[2] > 675.0f) {
        return 1;
    }
    return -1;
}

void func_80802FBC_chstoneballcontrol();

void func_8080282C_chstoneballcontrol(param_0, param_1) u8 *param_0; s32 param_1;
{
  f32 temp_f0;

  f32 temp_f0_6;
  if (func_800EA05C() != 0xBB)
  {
    switch (param_1)
    {
      case 0:
        temp_f0 = *((f32 *) (((s8 *) param_0) + 0xC));
        if ((temp_f0 > (-183.0f)) && (temp_f0 < 183.0f))
      {
        if ((((u32)((u16) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 0xA) != 4) && ((*((f32 *) (((s8 *) param_0) + 4))) > 720.0f))
        {
          func_80802FBC_chstoneballcontrol(param_0, 0);
        }
        if ((*((f32 *) (((s8 *) param_0) + 4))) > 801.0f)
        {
          *((f32 *) (((s8 *) param_0) + 4)) = 846.0f;
          *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
          return;
        }
      }
      else
      {
        *((f32 *) (((s8 *) param_0) + 4)) = 720.0f;
        *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
        func_80801944_chstoneballcontrol(param_0, 6);
        return;
      }
        break;

      case 1:
        if (((*((f32 *) (((s8 *) param_0) + 4))) < 183.0f) && ((*((f32 *) (((s8 *) param_0) + 4))) > (-183.0f)))
      {
        if ((((u32)((u16) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 0xA) != 4) && ((*((f32 *) (((s8 *) param_0) + 0xC))) > 720.0f))
        {
          func_80802FBC_chstoneballcontrol(param_0, 1);
        }
        if ((*((f32 *) (((s8 *) param_0) + 0xC))) > 801.0f)
        {
          *((f32 *) (((s8 *) param_0) + 0xC)) = 846.0f;
          *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
          return;
        }
      }
      else
      {
        *((f32 *) (((s8 *) param_0) + 0xC)) = 720.0f;
        *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
        func_80801944_chstoneballcontrol(param_0, 6);
        return;
      }
        break;

      case 2:
        if (((*((f32 *) (((s8 *) param_0) + 0xC))) < 183.0f) && ((*((f32 *) (((s8 *) param_0) + 0xC))) > (-183.0f)))
      {
        if ((((u32)((u16) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 0xA) != 4) && ((*((f32 *) (((s8 *) param_0) + 4))) < (-720.0f)))
        {
          func_80802FBC_chstoneballcontrol(param_0, 2);
        }
        if ((*((f32 *) (((s8 *) param_0) + 4))) < (-801.0f))
        {
          *((f32 *) (((s8 *) param_0) + 4)) = -846.0f;
          *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
          return;
        }
      }
      else
      {
        *((f32 *) (((s8 *) param_0) + 4)) = -720.0f;
        *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
        func_80801944_chstoneballcontrol(param_0, 6);
        return;
      }
        break;

      case 3:
        if (((*((f32 *) (((s8 *) param_0) + 4))) > (-183.0f)) && ((*((f32 *) (((s8 *) param_0) + 4))) < 183.0f))
      {
        if ((((u32)((u16) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 0xA) != 4) && ((*((f32 *) (((s8 *) param_0) + 0xC))) < (-720.0f)))
        {
          func_80802FBC_chstoneballcontrol(param_0, 3);
        }
        if ((*((f32 *) (((s8 *) param_0) + 0xC))) < (-801.0f))
        {
          *((f32 *) (((s8 *) param_0) + 0xC)) = -846.0f;
          *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
          return;
        }
      }
      else
      {
        *((f32 *) (((s8 *) param_0) + 0xC)) = -720.0f;
        *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
        func_80801944_chstoneballcontrol(param_0, 6);
        return;
      }
        break;

    }

  }
  else
  {
    if (((((*((f32 *) (((s8 *) param_0) + 4))) > (-1145.0f)) || ((*((f32 *) (((s8 *) param_0) + 4))) < (-3255.0f))) || ((temp_f0_6 = *((f32 *) (((s8 *) param_0) + 0xC)), temp_f0_6 > (-745.0f)))) || (temp_f0_6 < (-1255.0f)))
    {
      *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
      func_80801944_chstoneballcontrol(param_0, 6);
    }
  }
}

void func_80802C30_chstoneballcontrol(Actor *param_0)
{
    s32 *local_0;
    StoneballSpatialEntry *local_1;
    StoneballSpatialEntry *local_2;
    Unk80132ED0 *local_3;

    local_0 = func_800BE3F8(param_0->position);
    while (*local_0) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        while (local_1 < local_2) {
            if (local_1->local_2 & 1) {
                local_3 = local_1->local_0;
                if (local_3 != param_0->unk0) {
                    if (0x267 == ((StoneballMarkerC010 *)local_3)->local_0 || 0x253 == ((StoneballMarkerC010 *)local_3)->local_0 || 0x254 == ((StoneballMarkerC010 *)local_3)->local_0) {
                        func_80802D9C_chstoneballcontrol(param_0, func_80106790(local_3));
                    }
                    if (((StoneballMarkerC010 *)local_3)->local_0 == 0) {
                        func_80802E30_chstoneballcontrol(param_0, (u32)*(u16 *)((u8 *)local_3 + 0x1A) >> 5);
                    }
                    if (0x237 == ((StoneballMarkerC010 *)local_3)->local_0) {
                        func_80802EA0_chstoneballcontrol(param_0, func_80106790(local_3));
                    }
                }
            }
            local_1++;
        }
        local_0++;
    }
}

void func_80802D9C_chstoneballcontrol(param_0, param_1) Actor *param_0; Actor *param_1;
{
    StoneBallContact1472 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (_sukickball_entrypoint_13(param_0->position, param_1->position, 60.0f)) {
        if (local_0->local_0 <= 0.0f) {
            func_800C4140(0x7FFF4482, param_0->position, 0x138801F4);
            local_0->local_0 = 0.75f;
        }
    }
}

void func_80802E30_chstoneballcontrol(param_0, param_1) Actor *param_0; void *param_1;
{
    Actor *local_1;
    f32 local_0[3];
    local_1 = func_80106790(param_0->unk3C);
    if (param_0->unk70_10 != 2 && _sukickball_entrypoint_12(local_1, param_1)) {
        func_800F5A00(param_1, local_0);
        _sukickball_entrypoint_13(local_0, param_0->position, 60.0f);
    }
}

void func_80802EA0_chstoneballcontrol(param_0, param_1) void *param_0; void *param_1;
{
  s32 local_0;
  s32 new_var;
  void *new_var2;
  local_0 = func_80106790(((void **) param_0)[15]);
  new_var2 = param_1;
  ;
  if ((((((((*((u16 *) (((char *) param_0) + 0x72))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 10) != 2)
  {
    if (_sukickball_entrypoint_12(local_0, func_80801320_chstoneballcontrol(new_var2)) != 0)
    {
      _sukickball_entrypoint_13(((char *) param_1) + 4, ((char *) param_0) + 4, 60.0f);
    }
  }
}

void func_80802F14_chstoneballcontrol(param_0) Actor *param_0;
{
    BallControlLocal *local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80106790(param_0->unk3C);
    if (local_0->unk20 != 0x7F) {
        if (_sukickball_entrypoint_6(local_1, local_0->unk20)) {
            func_800F4F98(local_0->unk20, param_0->unk0);
            _sukickball_entrypoint_11(local_1, local_0->unk20);
        } else {
            _sukickball_entrypoint_11(local_1, local_0->unk20);
        }
        local_0->unk20 = 0x7F;
        local_0->unk0 = 10000000.0f;
    }
}

void func_80802FBC_chstoneballcontrol(Actor *param_0, s32 param_1)
{
    Actor *local_0;

    local_0 = func_80106790(param_0->unk3C);
    func_80802F14_chstoneballcontrol(param_0);
    switch (param_0->unk0->unk24 >> 22) {
        case 0x267:
            _sukickball_entrypoint_9(local_0, D_808052A0_chstoneballcontrol[param_1], 1);
            break;
        case 0x253:
            _sukickball_entrypoint_9(local_0, D_808052A0_chstoneballcontrol[param_1], 3);
            break;
        case 0x254:
            _sukickball_entrypoint_9(local_0, D_808052A0_chstoneballcontrol[param_1], 2);
            break;
    }
    param_0->unk70_10 = 4;
    _subaddiefade_entrypoint_3(param_0);
}

void chstoneballcontrol_entrypoint_1(Unk80132ED0 *param_0, s32 param_1, u32 param_2, s32 param_3)
{
    Actor *local_0;
    f32 *local_1;

    local_0 = func_80106790(param_0);
    local_1 = func_80100094(local_0, 0);
    switch (param_1) {
    case 3:
        func_80801944_chstoneballcontrol(local_0, 1);
        break;
    case 1:
        local_1[1] = func_800D8FF8() * param_2;
        func_80803538_chstoneballcontrol(local_0);
        break;
    }
}

void func_80803148_chstoneballcontrol(param_0) Actor *param_0;
{
    StoneballStateC010 *local_0 = func_80100094(param_0, 0);
    StoneballDistancesC010 local_1 = D_808052B0_chstoneballcontrol;
    Actor *local_2;
    StoneballPlayersC010 *local_3;
    s32 local_4;
    s32 local_5;
    f32 local_6;

    local_2 = func_80106790(param_0->unk3C);
    local_3 = func_80100094(local_2, 0);
    if ((local_2->unk70_10 == 4 || local_2->unk70_10 == 7) &&
        (local_0->local_0 == 0.0f || param_0->unk70_10 == 1)) {
        local_5 = 0x7F;
        local_6 = 10000000.0f;
        for (local_4 = 0; local_4 < local_3->local_0; local_4++) {
            if ((param_0->unk70_10 != 2 || local_4 != local_0->local_1) &&
                !_sukickball_entrypoint_12(local_2, local_4)) {
                Mass45StoneVector_80803148_chstoneballcontrol local_7 = D_808052C0_chstoneballcontrol;

                if (_sukickball_entrypoint_6(local_2, local_4)) {
                    if (func_800F6C5C(local_4) && func_800F5410(local_4) == 8) {
                        func_800F5A00(local_4, local_7.local_0);
                        if (func_800EFFB4(param_0->position, 65.0f, local_7.local_0)) {
                            local_1.local_0[local_4] = func_800EEB40(param_0->position, local_7.local_0);
                        }
                    }
                } else {
                    func_800EE7F8(local_7.local_0, func_80106790(_sukickball_entrypoint_8(local_2, local_4))->position);
                    if (func_800EFFB4(param_0->position, 65.0f, local_7.local_0)) {
                        local_1.local_0[local_4] = func_800EEB40(param_0->position, local_7.local_0);
                    }
                }
            }
        }
        for (local_4 = 0; local_4 < local_3->local_0; local_4++) {
            if (param_0->unk70_10 != 2 || local_4 != local_0->local_1) {
                if (local_1.local_0[local_4] < local_6) {
                    local_6 = local_1.local_0[local_4];
                    local_5 = local_4;
                }
            }
        }
        if (local_5 != 0x7F) {
            if (local_0->local_1 != 0x7F) {
                if (_sukickball_entrypoint_7(local_2, local_0->local_1)) {
                    _sukickball_entrypoint_11(local_2, local_0->local_1);
                } else {
                    func_800F4F98(local_0->local_1, param_0->unk0);
                    _sukickball_entrypoint_11(local_2, local_0->local_1);
                }
            }
            local_0->local_1 = local_5;
            local_0->local_0 = 1.5f;
            if (_sukickball_entrypoint_6(local_2, local_0->local_1)) {
                func_800F4950(local_0->local_1, param_0->unk0, _chstoneballcontrol_entrypoint_1);
            } else {
                Actor *local_8 = func_80106790(_sukickball_entrypoint_8(local_2, local_0->local_1));

                ((u8 *)local_8)[0x65] &= ~0x10;
            }
            switch (((StoneballMarkerC010 *)param_0->unk0)->local_0) {
            case 0x267:
                _sukickball_entrypoint_10(local_2, local_0->local_1, 1);
                break;
            case 0x253:
                _sukickball_entrypoint_10(local_2, local_0->local_1, 3);
                break;
            case 0x254:
                _sukickball_entrypoint_10(local_2, local_0->local_1, 2);
                break;
                        default:
                break;
}
            func_80801944_chstoneballcontrol(param_0, 2);
            *(f32 *)((u8 *)param_0 + 0x24) = 0.0f;
        }
    }
}

int func_80803538_chstoneballcontrol(param_0) Actor *param_0;
{
    Actor *local_0;
    u8 *local_1;
    Actor *local_2;
    local_0 = func_80106790(param_0->unk3C);
    local_1 = func_80100094(param_0, 0);
    if (_sukickball_entrypoint_6(local_0, local_1[0x20])) {
        param_0->rotation[1] = func_800F5F24(local_1[0x20]);
        *(f32 *)((u8 *)param_0 + 0x24) = func_800F10B4(*(f32 *)(local_1 + 4), 0.0f, 1.0f, 450.0f, 900.0f);
        func_800F4F98(local_1[0x20], param_0->unk0);
        _sukickball_entrypoint_11(local_0, local_1[0x20]);
    } else {
        local_2 = func_80106790(_sukickball_entrypoint_8(local_0, local_1[0x20]));
        param_0->rotation[1] = local_2->rotation[1];
        *(f32 *)((u8 *)param_0 + 0x24) = func_800F10B4(*(f32 *)((u8 *)local_2 + 0x58),
            8.0f, 16.0f, 450.0f, 900.0f);
        *(f32 *)((u8 *)local_2 + 0x58) = 0.0f;
        _sukickball_entrypoint_11(local_0, local_1[0x20]);
    }
    param_0->unk70_10 = 3;
    local_1[0x20] = 0x7F;
    *(f32 *)local_1 = 0.0f;
    func_800C4140(0x7FFF453C, param_0->position, 0x3E800640);
}

void func_8080367C_chstoneballcontrol(s32 arg0)
{
    func_80801944_chstoneballcontrol(arg0,0);
}

int chstoneballcontrol_entrypoint_2()
{
    return (int)&D_808052CC_chstoneballcontrol;
}

int chstoneballcontrol_entrypoint_3()
{
    return D_80805314_chstoneballcontrol;
}

int chstoneballcontrol_entrypoint_4()
{
    return (int)&D_8080535C_chstoneballcontrol;
}

s32 func_808036C0_chstoneballcontrol(Actor *param_0, s32 param_1, StoneballControlEvent param_2)
{
    s32 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 1:
        func_800BD268(*local_0, (*(u32 *)((u8 *)param_0 + 0x64) << 3) >> 30);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80804B60_chstoneballcontrol();

void func_80804304_chstoneballcontrol();

void func_80804218_chstoneballcontrol();

void func_80803724_chstoneballcontrol(Actor *param_0)
{
    extern Vec3f D_8080540C_chstoneballcontrol;
    extern u8 D_80805418_chstoneballcontrol[];

    StoneballDataTop50 *local_0;
    char *local_1;
    f32 local_2;
    Vec3f local_5;
    f32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_2 = func_800D8FF8();
    local_1 = (char *)func_80106790(
        *(void **)((char *)param_0 + 0x3C)
    );

    func_800BD2D0(local_0->local_0);
    local_0->local_1 -= local_2;

    switch (param_0->unk70_10) {
        case 10:
            *(f32 *)((char *)param_0 + 0x2C) = 0.0f;
            *(f32 *)((char *)param_0 + 0x24) =
                _subaddiejoy_entrypoint_3(param_0);

            if (_sukickball_entrypoint_12(local_1, param_0->unk6C_0)) {
                *(f32 *)((char *)param_0 + 0x24) = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x24), 0.0f, 1.0f, 0.0f,
                    func_80800070_chstoneballcontrol(param_0));
            } else {
                *(f32 *)((char *)param_0 + 0x24) = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x24), 0.0f, 1.0f, 0,
                    func_80800040_chstoneballcontrol(param_0));
            }

            if (_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                if (func_800BCFC4(local_0->local_0, 1)) {
                    *(f32 *)((char *)param_0 + 0x58) =
                        func_800F10B4(
                            (f32)func_800BCD78(local_0->local_0, 1, 1) * func_800D8FF8(),
                            0.0f,
                            1.0f,
                            450.0f,
                            900.0f
                        );

                    param_0->unk64_20 = 1;
                }
            }

            func_80804B60_chstoneballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chstoneballcontrol(param_0),
                func_80800040_chstoneballcontrol(param_0));

            if (func_800BD030(local_0->local_0, 9)) {
                func_80800B4C_chstoneballcontrol(param_0, 8);
            }
            break;

        case 8:
            if (*(f32 *)((char *)param_0 + 0x50) == 0) {
                if (func_80101E14(param_0, 0.3077f)) {
                    anctrl_setPlaybackType(func_80104248(param_0), 3);

                    *(f32 *)((char *)param_0 + 0x50) = 1.0f;
                    *(f32 *)((char *)param_0 + 0x24) = 1050.0f;

                    func_800B4470(
                        param_0->position,
                        0,
                        D_80805418_chstoneballcontrol,
                        1,
                        0.75f,
                        0.0f,
                        125,
                        250,
                        0
                    );
                }
            } else if (*(f32 *)((char *)param_0 + 0x50) != 0) {
                *(f32 *)((char *)param_0 + 0x50) += local_2;

                if (*(f32 *)((char *)param_0 + 0x50) > 2.5f ||
                    *(f32 *)((char *)param_0 + 0x24) < 150.0f) {
                    func_80800B4C_chstoneballcontrol(param_0, 2);

                    *(f32 *)((char *)param_0 + 0x24) =
                        func_8080009C_chstoneballcontrol(param_0);
                } else {
                    *(f32 *)((char *)param_0 + 0x24) *= 0.9f;
                }
            }

            *(f32 *)((char *)param_0 + 0x2C) = 0;

            func_800EEB9C(
                (char *)param_0 + 0x28,
                *(f32 *)((char *)param_0 + 0x48),
                *(f32 *)((char *)param_0 + 0x24) * local_2
            );

            func_800EF04C(
                param_0->position,
                (char *)param_0 + 0x28
            );

            if (((StoneballEnableTop50 *)param_0)->local_0) {
                _subaddiejoy_entrypoint_3(param_0);

                if (!func_80102CF4(param_0, 8.0f)) {
                    func_80102B2C(param_0, 8.0f);
                }
            }

            func_80804304_chstoneballcontrol(param_0);
            break;

        case 12:
            if (*(f32 *)((char *)param_0 + 0x24) < 150.0f) {
                func_80800B4C_chstoneballcontrol(param_0, 2);

                *(f32 *)((char *)param_0 + 0x24) =
                    func_8080009C_chstoneballcontrol(param_0);
            } else {
                *(f32 *)((char *)param_0 + 0x24) *= 0.9f;
            }

            *(f32 *)((char *)param_0 + 0x2C) = 0.0f;

            func_800EEB9C(
                (char *)param_0 + 0x28,
                *(f32 *)((char *)param_0 + 0x54),
                *(f32 *)((char *)param_0 + 0x24) * local_2
            );

            func_800EF04C(
                param_0->position,
                (char *)param_0 + 0x28
            );
            break;
        case 2:
            if (((StoneballEnableTop50 *)param_0)->local_0) {
                param_0->unk70_10 = 10;
                *(f32 *)((char *)param_0 + 0x58) = 0.0f;
            }

            if (!func_80804810_chstoneballcontrol(param_0)) {
                func_80800B4C_chstoneballcontrol(param_0, 1);
            }

            if (_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                if (func_800DC0C0() < 0.95f) {
                    func_80800B4C_chstoneballcontrol(param_0, 5);
                } else {
                    *(f32 *)((char *)param_0 + 0x34) =
                        func_800DC178(0.0f, 2.5f);

                    func_80800B4C_chstoneballcontrol(param_0, 4);
                }
            }

            func_80804B60_chstoneballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chstoneballcontrol(param_0),
                func_80800040_chstoneballcontrol(param_0));
            break;

        case 1:
            _sukickball_entrypoint_16(
                param_0->unk6C_0,
                (char *)param_0 + 0x18
            );

            func_80804B60_chstoneballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chstoneballcontrol(param_0),
                func_80800040_chstoneballcontrol(param_0));

            if (func_80804810_chstoneballcontrol(param_0)) {
                func_80800B4C_chstoneballcontrol(param_0, 2);
            }

            if (func_800EFFB4(
                    param_0->position,
                    50.0f,
                    (char *)param_0 + 0x18)) {
                func_80800B4C_chstoneballcontrol(param_0, 3);
            }
            break;

        case 3:
            if (func_80804810_chstoneballcontrol(param_0)) {
                func_80800B4C_chstoneballcontrol(param_0, 2);
            }

            _sukickball_entrypoint_14(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chstoneballcontrol(param_0),
                func_80800040_chstoneballcontrol(param_0));
            break;

        case 4:
            local_5 = D_8080540C_chstoneballcontrol;

            if (*(f32 *)((char *)param_0 + 0x34) > 0.0f) {
                *(f32 *)((char *)param_0 + 0x34) -= local_2;
            } else {
                func_80800B4C_chstoneballcontrol(param_0, 5);
            }

            if (!_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                func_80800B4C_chstoneballcontrol(param_0, 1);
            }

            _sukickball_entrypoint_16(
                param_0->unk6C_0,
                (char *)param_0 + 0x18
            );

            func_800EFCD8(
                local_5.f,
                _sukickball_entrypoint_15(param_0->unk6C_0),
                250.0f
            );

            func_800EF04C(
                (char *)param_0 + 0x18,
                local_5.f
            );

            if (func_800F0064(param_0->position, 100.0f, (f32 *)((char *)param_0 + 0x18))
                    || _sukickball_entrypoint_12(local_1, param_0->unk6C_0) == 3) {
                func_80800B4C_chstoneballcontrol(param_0, 5);
            }

            func_80804B60_chstoneballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chstoneballcontrol(param_0),
                func_80800040_chstoneballcontrol(param_0));
            break;

        case 5:
            func_808040B8_chstoneballcontrol(param_0);
            func_80804218_chstoneballcontrol(param_0);
            func_80800B4C_chstoneballcontrol(param_0, 6);
            break;

        case 6:
            if (_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                func_80804218_chstoneballcontrol(param_0);
            } else {
                func_80800B4C_chstoneballcontrol(param_0, 2);
            }
            break;

        case 7:
            if (*(f32 *)((char *)param_0 + 0x34) > 0.0f) {
                *(f32 *)((char *)param_0 + 0x34) -= local_2;
            } else {
                func_80800B4C_chstoneballcontrol(param_0, 2);
            }

            func_80804B60_chstoneballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chstoneballcontrol(param_0),
                func_80800040_chstoneballcontrol(param_0));
            break;

        case 9:
            local_4 = *(f32 *)((char *)param_0 + 0x34);

            *(f32 *)((char *)param_0 + 0x58) = 0.0f;
            *(f32 *)((char *)param_0 + 0x48) += local_4;
            param_0->unk64_20 = 0;

            if (local_4 > 1.0f) {
                *(f32 *)((char *)param_0 + 0x34) =
                    local_4 * 0.95f;
            } else if (local_4 < -1.0f) {
                *(f32 *)((char *)param_0 + 0x34) =
                    local_4 * 0.95f;
            } else {
                func_80800B4C_chstoneballcontrol(param_0, 2);
                *(f32 *)((char *)param_0 + 0x34) = 0.0f;
            }
            break;

    }

    if (_sukickball_entrypoint_5(param_0, local_0->local_2)) {
        if (param_0->unk70_10 == 8) {
            func_80800B4C_chstoneballcontrol(param_0, 2);
        } else if (!((StoneballEnableTop50 *)param_0)->local_0) {
            func_80800BCC_chstoneballcontrol(param_0, 0);
        }
    } else {
        func_800EE7F8(
            local_0->local_2,
            param_0->position
        );
    }
}

s32 func_80803FF4_chstoneballcontrol(param_0, param_1) s32 param_0; s32 param_1;
{
    s32 local_0;

    local_0 = param_0;
    switch (param_1) {
    case 0:
        if (func_800DC298(0.1499938965f)) return 0;
        break;
    case 1:
        if (func_800DC298(0.2249908447f)) return 0;
        break;
    case 2:
        if (func_800DC298(0.299987793f)) return 0;
        break;
    }
    while (local_0 == param_0) local_0 = func_800DC128(1, 4);
    return local_0;
}

int func_808040B8_chstoneballcontrol(Actor *param_0)
{
    s32 local_0;

    u8 *local_3;

    local_0 = func_80106790(*((s32 *)((char *)param_0 + 0x3C)));
    local_3 = func_80100094(local_0, 0);
    switch (_sukickball_entrypoint_12(local_0, (*((s32 *)((char *)param_0 + 0x6C))) & 0x1FF)) {
    case 1:
        _sukickball_entrypoint_4((*((s32 *)((char *)param_0 + 0x6C))) & 0x1FF, (s32 *)((char *)param_0 + 0x18));
        return;
    case 3:
        func_8080419C_chstoneballcontrol(param_0, func_80803FF4_chstoneballcontrol((*((s32 *)((char *)param_0 + 0x6C))) & 0x1FF, *(u8 *)((char *)local_3 + 0x39)));
        return;
    case 2:
        _sukickball_entrypoint_4(func_80803FF4_chstoneballcontrol((*((s32 *)((char *)param_0 + 0x6C))) & 0x1FF, *(u8 *)((char *)local_3 + 0x39)), (s32 *)((char *)param_0 + 0x18));
        
    case 0:
        return;
    }
}

void func_8080419C_chstoneballcontrol(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_0;

    local_0 = func_80106790(*(s32 *)((char *)param_0 + 0x3C));
    if (_sukickball_entrypoint_6(local_0, param_1) != 0) {
        func_800F5A00(param_1, (s32 *)((char *)param_0 + 0x18));
        return;
    }
    func_800EE7F8((s32 *)((char *)param_0 + 0x18), func_80106790(_sukickball_entrypoint_8(local_0, param_1))->position);
}

void func_80804218_chstoneballcontrol(Actor *param_0)
{
    if (_sukickball_entrypoint_12(func_80106790(param_0->unk3C), param_0->unk6C_0) == 1) {
        _sukickball_entrypoint_4(param_0->unk6C_0, (f32 *)((u8 *)param_0 + 0x18));
    }
    *(f32 *)((u8 *)param_0 + 0x54) = func_80102D78(param_0, (f32 *)((u8 *)param_0 + 0x18));
    if (!func_80102CF4(param_0, 16.0f)) {
        func_80102B2C(param_0, 16.0f);
    } else if (!func_80102CF4(param_0, 4.0f)) {
        func_80102B2C(param_0, 4.0f);
    } else {
        param_0->unk58 = func_800DC178(10.0f, 16.0f);
        param_0->unk64_20 = 1;
        func_80800B4C_chstoneballcontrol(param_0, 2);
    }
}

void func_80804304_chstoneballcontrol(u8 *p0)
{
    u8 *s4;
    u8 *s3;
    u8 *s0;
    u8 *local_0;
    s32 i;
    f32 vC0[3];
    f32 f20;
    f32 f24;
    f32 vAC[3];
    f32 vA0[3];
    f32 v94[3];
    f32 f22;
    f32 v84[3];

    s4 = 0;
    local_0 = func_80100094(func_80106790(*(void **)(p0 + 0x3C)), 0);
    i = 0;
    if ((s32)*(u8 *)(local_0 + 0x3A) > 0) {
        do {
            s3 = p0 + 4;
            if (i != (*(s32 *)(p0 + 0x6C) & 0x1FF)) {
                s0 = func_80106790(*(void **)(p0 + 0x3C));
                if (_sukickball_entrypoint_7(s0, i) != 0) {
                    s4 = func_80106790(_sukickball_entrypoint_8(s0, i));
                    vC0[0] = *(f32 *)(s4 + 4);
                    vC0[1] = *(f32 *)(s4 + 8);
                    vC0[2] = *(f32 *)(s4 + 0xC);
                } else {
                    func_800F5A00(i, vC0);
                }
                if (func_800EFFB4(s3, 90.0f, vC0) != 0) {
                    f22 = func_800EEF94(p0 + 0x28);
                    if (_sukickball_entrypoint_6(s0, i) != 0) {
                        func_800F5D70(i, vAC);
                        f20 = func_800EEF94(vAC);
                        f24 = func_800D8FF8() * f20;
                    } else {
                        f20 = func_800EEF94(s4 + 0x28);
                        f24 = func_800D8FF8() * f20;
                    }
                    if (f24 < f22) {
                        if (_sukickball_entrypoint_6(s0, i) != 0) {
                            _sukickball_entrypoint_13(s3, vC0, 60.0f);
                            func_800F8294(i, vC0);
                            if (((u32)*(u16 *)(p0 + 0x72) >> 10) == 8) {
                                *(W3 *)vA0 = *(W3 *)D_8080541C_chstoneballcontrol;
                                func_800F5A00(i, v94);
                                func_800EF1B8(vA0, func_80102D78(p0, v94), 150.0f);
                                func_800F7700(i, 3, s3);
                            }
                        } else {
                            s0 = s4 + 4;
                            _sukickball_entrypoint_13(s3, s0, 60.0f);
                            if (((u32)*(u16 *)(p0 + 0x72) >> 10) == 8) {
                                *(f32 *)(s4 + 0x58) = 1.5f;
                                ((BitS101 *)s4)->b4 = 1;
                                func_80800B4C_chstoneballcontrol(s4, 0xC);
                                *(f32 *)(s4 + 0x24) = *(f32 *)(p0 + 0x24) * 0.75f;
                                *(f32 *)(s4 + 0x54) = func_80102D78(p0, (f32 *)s0);
                                *(f32 *)(p0 + 0x24) = *(f32 *)(p0 + 0x24) * 0.5f;
                            }
                        }
                    } else {
                        _sukickball_entrypoint_13(vC0, s3, 60.0f);
                        if (func_800DC0C0() < 0.5f && _sukickball_entrypoint_12(s0, *(s32 *)(p0 + 0x6C) & 0x1FF) == 0) {
                            func_80800BCC_chstoneballcontrol(p0, vC0);
                        }
                        if (_sukickball_entrypoint_6(s0, i) != 0 && func_800F52B8(i, *(s32 *)p0) == 2) {
                            func_800F5A00(i, v84);
                            *(f32 *)(p0 + 0x54) = func_800F1DF4(v84, s3);
                            func_80800B4C_chstoneballcontrol(p0, 0xC);
                            *(f32 *)(p0 + 0x24) = (f24 * 0.75f) / func_800D8FF8();
                        }
                        *(f32 *)(p0 + 0x58) = 1.5f;
                        ((BitS101 *)p0)->b4 = 1;
                    }
                }
            }
            i++;
        } while (i < (s32)*(u8 *)(local_0 + 0x3A));
    }
}

void func_808046C4_chstoneballcontrol(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    ((StoneBallFlags31 *)param_0)->local_0 = 1;
    param_0->scale = 0.5f;
    func_8010A590(param_0);
    switch (func_800EA05C()) {
        case 0xC6:
            *(u8 *)(local_0 + 0x14) = 0;
            break;
        case 0xC8:
            *(u8 *)(local_0 + 0x14) = 1;
            break;
        case 0xC9:
            *(u8 *)(local_0 + 0x14) = 2;
            break;
        case 0xBB:
            *(u8 *)(local_0 + 0x14) = 3;
            break;
        case 0x17F:
            *(u8 *)(local_0 + 0x14) = 4;
            if (param_0->unk6C_0 < (u32)_gcstatusDll_entrypoint_11()) {
                ((StoneBallFlags31 *)param_0)->local_1 = 1;
                ((StoneBallFlags31 *)param_0)->local_2 = param_0->unk6C_0;
            }
            break;
    }
    *(s32 *)local_0 = func_800BD0DC(2);
    func_800BD268(*(s32 *)local_0, param_0->unk6C_0);
    func_800BD28C(*(s32 *)local_0, 2);
}

void func_808047E8_chstoneballcontrol(s32 param_0) {
    func_800BD09C(*(u32 *)func_80100094(param_0, 0));
}

Actor *func_80804810_chstoneballcontrol(param_0) Actor *param_0;
{
    Actor *local_1;
    f32 local_0;
    Actor *local_2;
    f32 local_3;
    f32 local_4;

    local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x155, -1, &local_0);
    if (local_1 == NULL) {
        local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x29E, -1, &local_0);
        if (local_1 == NULL) {
            local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x1B8, -1, &local_0);
            if (local_1 == NULL) {
                return NULL;
            }
        }
    } else if ((local_1->unk70_10 == 2 && !func_800F0064(param_0->position, 100.0f, local_1->position)) ||
               local_1->unk70_10 == 6 || local_1->unk70_10 == 4 || local_1->unk70_10 == 3) {
        switch (local_1->unk70_10) {
        case 2:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x155, 2, &local_0);
            break;
        case 3:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x155, 3, &local_0);
            break;
        case 6:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x155, 6, &local_0);
            break;
        case 4:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x155, 4, &local_0);
            break;
        }
        if (local_2 && (local_2->unk70_10 == 1 || local_2->unk70_10 == 3)) {
            local_1 = local_2;
        }
    }
    if (local_1->unk70_10 == 2) {
        local_3 = local_1->unk54 - func_80102D78(param_0, (f32 *)local_1->actorData);
        local_4 = 0.0f;
        local_3 = func_800136E4(local_3);
        if (local_3 < 90.0f) {
            local_3 = local_1->unk54 + 65.0f;
            local_4 = local_1->unk50 * 0.006666666828f;
        } else if (local_3 > 270.0f) {
            local_3 = local_1->unk54 - 65.0f;
            local_4 = local_1->unk50 * 0.006666666828f;
        } else if (local_1->unk50 > 10.0f) {
            local_4 = local_1->unk50 * 0.002857142827f;
        }
        if (local_4 < 25.0f) {
            local_4 = 25.0f;
        }
        if (local_4 < 30.0f) {
            param_0->unk54 = func_80102D78(param_0, (f32 *)local_1->actorData);
            if (!func_80102CF4(param_0, 45.0f) && func_80102CF4(param_0, 90.0f) && func_800DC0C0() < 0.8f) {
                func_80800B4C_chstoneballcontrol(param_0, 8);
            }
        }
        func_800EFCD8((f32 *)param_0->actorData, local_3, local_4);
        func_800EF04C((f32 *)param_0->actorData, local_1->position);
    } else {
        func_800EE7F8((f32 *)param_0->actorData, local_1->position);
    }
    return local_1;
}

void func_80804B60_chstoneballcontrol(Actor *param_0)
{
    Mass45StoneVector_80804B60_chstoneballcontrol local_0 = *(Mass45StoneVector_80804B60_chstoneballcontrol *)D_80805428_chstoneballcontrol;
    Actor *local_1;

    local_1 = func_80106790(param_0->unk3C);
    if (param_0->unk70_10 != 10) {
        param_0->unk54 = func_80102D78(param_0, (f32 *)param_0->actorData);
        if (!func_80102CF4(param_0, 240.0f)) {
            func_80804DA0_chstoneballcontrol(param_0);
        } else {
            func_80804D40_chstoneballcontrol(param_0);
        }
        if (!func_80102CF4(param_0, 16.0f)) {
            func_80102B2C(param_0, 16.0f);
        } else if (!func_80102CF4(param_0, 4.0f)) {
            func_80102B2C(param_0, 4.0f);
        }
    } else {
        if (!func_80102CF4(param_0, 32.0f)) {
            func_80102B2C(param_0, 32.0f);
        } else if (!func_80102CF4(param_0, 16.0f)) {
            func_80102B2C(param_0, 16.0f);
        } else if (!func_80102CF4(param_0, 4.0f)) {
            func_80102B2C(param_0, 4.0f);
        }
    }
    if (_sukickball_entrypoint_12(local_1, param_0->unk6C_0) &&
        func_80800070_chstoneballcontrol(param_0) < ((f32 *)param_0->actorData)[3]) {
        ((f32 *)param_0->actorData)[3] = func_80800070_chstoneballcontrol(param_0);
    }
    func_800EFCD8((f32 *)&param_0->actorData[4], param_0->rotation[1],
        ((f32 *)param_0->actorData)[3] * func_800D8FF8());
    func_800EE780(param_0->position, param_0->position, (f32 *)&param_0->actorData[4]);
    func_80804304_chstoneballcontrol(param_0);
    param_0->rotation[1] = func_800136E4(param_0->rotation[1]);
}

void func_80804D40_chstoneballcontrol(param_0) Actor *param_0;
{
    if (((f32 *)param_0->actorData)[3] < func_80800040_chstoneballcontrol(param_0)) {
        ((f32 *)param_0->actorData)[3] += func_808000C8_chstoneballcontrol(param_0);
    } else {
        ((f32 *)param_0->actorData)[3] = func_80800040_chstoneballcontrol(param_0);
    }
}

void func_80804DA0_chstoneballcontrol(param_0) u8 *param_0; {
    if (func_8080009C_chstoneballcontrol(param_0) < *(f32 *)(param_0 + 0x24)) {
        *(f32 *)(param_0 + 0x24) -= func_808000F4_chstoneballcontrol(param_0);
    }
}

int *chstoneballcontrol_entrypoint_5()
{
    return &D_80805434_chstoneballcontrol;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/stoneballcontrol.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80804FD4_chstoneballcontrol -> s32[], D_80805178_chstoneballcontrol -> s32[], D_808052CC_chstoneballcontrol -> int[], D_8080535C_chstoneballcontrol -> int[], D_80805434_chstoneballcontrol -> int[] */
extern void _sukickball_entrypoint_0();
extern void _sukickball_entrypoint_1();
u32 D_80804FC0_chstoneballcontrol[5] = { 0x1304B1, 0xA00A6, 0x164E20, 0x101F4, 0x13880000 };
s32 D_80804FD4_chstoneballcontrol[5] = { 0x130413, 0xA0100, 0x167D00, 0x101F4, 0x13880000 };
u8 D_80804FE8_chstoneballcontrol[20] = { 0x0, 0x13, 0x4, 0xF4, 0x0, 0xA, 0x1, 0x0, 0x0, 0x16, 0x4E, 0x20, 0x0, 0x1, 0x1, 0xF4, 0x13, 0x88, 0x0, 0x0 };
f32 D_80804FFC_chstoneballcontrol[5] = { 1e+02f, 1.5e+02f, 2e+02f, 0.0f, 4e+02f };
f32 D_80805010_chstoneballcontrol[5][2] = { 1.0f, 0.0f, 0.75f, 1.0f, 0.75f, 1.0f, 0.3333f, 0.6666f, 0.3333f, 0.6666f };
int D_80805038_chstoneballcontrol[5][4] = { 0x2, 0x0, 0x0, 0x0, 0x3, 0x1, 0x1, 0x0, 0x4, 0x1, 0x0, 0x1, 0x4, 0x0, 0x0, 0x2, 0x5, 0x2, 0x1, 0x1 };
s32 D_80805088_chstoneballcontrol[5] = { 0x2D, 0x2D, 0x2D, 0x0, 0x3C };
u8 D_8080509C_chstoneballcontrol[20] = { 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x4 };
Vec3f D_808050B0_chstoneballcontrol = { 0.0f, 0.0f, 0.0f };
s32 D_808050BC_chstoneballcontrol[4] = { 0x0, 0x0, 0x0, 0x0 };
StoneBallTypes D_808050CC_chstoneballcontrol = { 0x15501B8, 0x29EFFFF };
void *D_808050D4_chstoneballcontrol = (void *)0x023901B7;
static u32 D_808050D4_chstoneballcontrol_rest[17] = { 0x6370001, 0x0, (u32)func_8080079C_chstoneballcontrol, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x80004, (u32)func_8080120C_chstoneballcontrol, 0x0, 0x400000, (u32)func_80800F9C_chstoneballcontrol, (u32)func_80107C2C, 0x80000202, (u32)func_80800360_chstoneballcontrol, 0x0 };
s32 D_8080511C_chstoneballcontrol = -0x38;
u8 D_80805120_chstoneballcontrol[20] = { 0xFF, 0xFF, 0xFF, 0xC8, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xC8 };
s32 D_80805134_chstoneballcontrol[17] = { 0xA10000A, -0x320000, -0x31FFCE, 0x320032, 0x2CFF83, 0x4BFF83, 0x7D0096, 0x7D001B, -0xF9015E, 0x27FD30, -0x2CFFD30, 0x2D00022, 0x1000180, 0x800100, 0x2A0080, 0x1000300, 0x4000000 };
s32 D_80805178_chstoneballcontrol[18] = { 0x1D09E2, 0x1BFF06, -0xF9FFEB, 0x6600CC, 0x220040, 0x4C0007, 0x70027, 0xC8, 0xF0, 0x161000, 0xC000F, 0x2C0000, 0x640000, 0xFA, 0x2A, 0x800100, 0x3000400, 0x0 };
u8 D_808051C0_chstoneballcontrol[80] = { 0x0, 0x1D, 0x6, 0x78, 0x0, 0x15, 0x0, 0x66, 0x0, 0xCC, 0x0, 0xA, 0xFF, 0xFB, 0x0, 0x0, 0xFF, 0xFB, 0x0, 0x5, 0x0, 0x0, 0x0, 0x5, 0x0, 0x2C, 0xFF, 0x6, 0x0, 0x64, 0xFF, 0x6, 0x1, 0x2C, 0x0, 0xFA, 0x1, 0x2C, 0x0, 0x1B, 0xFF, 0x6A, 0xFE, 0xD4, 0x0, 0x22, 0x0, 0x80, 0x0, 0x80, 0x1, 0x0, 0x3, 0x0, 0x0, 0x27, 0xFD, 0x30, 0xFD, 0x30, 0x2, 0xD0, 0x2, 0xD0, 0x0, 0x16, 0x10, 0x0, 0x0, 0x2A, 0x0, 0x80, 0x1, 0x0, 0x3, 0x0, 0x4, 0x0, 0x0, 0x0 };
u8 D_80805210_chstoneballcontrol[72] = { 0x0, 0x1D, 0x9, 0xDC, 0x0, 0x19, 0x0, 0x1, 0x0, 0x6, 0x23, 0x2, 0x0, 0xA, 0xFF, 0xFB, 0x0, 0x19, 0xFF, 0xF1, 0x0, 0x5, 0x0, 0x32, 0x0, 0xF, 0x0, 0x2C, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0xD8, 0x0, 0x0, 0x0, 0x22, 0x1, 0xA, 0x3, 0x0, 0x2, 0x0, 0x5, 0x0, 0x0, 0x2A, 0x0, 0x0, 0x0, 0x2, 0x4, 0x0, 0x7, 0x0, 0x0, 0x15, 0x0, 0x4C, 0x0, 0xB3, 0x0, 0x16, 0x0, 0x4, 0x0, 0x0 };
f32 D_80805258_chstoneballcontrol[6][3] = { -1.15e+03f, -3e+02f, -1e+03f, -1.55e+03f, -3e+02f, -4e+02f, -2.1e+03f, -3e+02f, -4e+02f, -2.65e+03f, -3e+02f, -4e+02f, -1.55e+03f, -3e+02f, -1.6e+03f, -2.65e+03f, -3e+02f, -1.6e+03f };
s32 D_808052A0_chstoneballcontrol[4] = { 0x0, 0x2, 0x1, 0x3 };
StoneballDistancesC010 D_808052B0_chstoneballcontrol = { 1e+07f, 1e+07f, 1e+07f, 1e+07f };
Mass45StoneVector_80803148_chstoneballcontrol D_808052C0_chstoneballcontrol = { 0.0f, 0.0f, 0.0f };
int D_808052CC_chstoneballcontrol[18] = { 0x2670155, 0x6700005, 0x0, (u32)func_80801BE0_chstoneballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x0, 0x0, 0x0, 0x800004, (u32)func_8080367C_chstoneballcontrol, 0x0, 0x240000, (u32)func_80801B44_chstoneballcontrol, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
s32 D_80805314_chstoneballcontrol[18] = { 0x25301B8, 0x6770005, 0x0, (u32)func_80801BE0_chstoneballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x0, 0x0, 0x0, 0x800006, (u32)func_8080367C_chstoneballcontrol, 0x0, 0x240000, (u32)func_80801B44_chstoneballcontrol, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
int D_8080535C_chstoneballcontrol[18] = { 0x254029E, 0x6720005, 0x0, (u32)func_80801BE0_chstoneballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x0, 0x0, 0x0, 0x800004, (u32)func_8080367C_chstoneballcontrol, 0x0, 0x240000, (u32)func_80801B44_chstoneballcontrol, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
u32 D_808053A4_chstoneballcontrol[26] = { 0x0, 0x0, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F99999A, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1EB0002, 0x4B189680, 0x1D70001, 0x3F800000, 0x1D70001, 0x40000000, 0x1D70001, 0x4B189680, 0x1D70001 };
Vec3f D_8080540C_chstoneballcontrol = { 0.0f, 0.0f, 0.0f };
u8 D_80805418_chstoneballcontrol[4] = { 0xFF, 0xFF, 0xFF, 0xC8 };
u32 D_8080541C_chstoneballcontrol[3] = { 0x0, 0x0, 0x0 };
s32 D_80805428_chstoneballcontrol[3] = { 0x0, 0x0, 0x0 };
int D_80805434_chstoneballcontrol[19] = { 0x23701B6, 0x66A000B, (u32)&D_808053A4_chstoneballcontrol, (u32)func_80803724_chstoneballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_1, 0x0, 0x0, 0x0, 0x4, (u32)func_808047E8_chstoneballcontrol, 0x0, 0x180000, (u32)func_808046C4_chstoneballcontrol, (u32)func_80107C2C, -0x7FFFFFFD, (u32)func_808036C0_chstoneballcontrol, 0x0, 0x0 };
