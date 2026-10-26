#include "common.h"

extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800BBCB8(Actor *, int, float, int, void (*)(void));
extern f32 D_80804CB4_chcollballcontrol[];
extern void *func_80100094(Actor *, u32);
extern s32 D_80804CF0_chcollballcontrol[][6];
extern s32 D_80804D68_chcollballcontrol[];
typedef struct { u8 pad_0[0x20]; s32 local_0[4]; u8 local_1[4]; u8 local_2[4]; u8 pad_1; u8 local_3; u8 local_4; u8 local_5; u8 local_6; } CollballScoreState;
extern Actor *func_80106790();
extern Unk80132ED0 *_sukickball_entrypoint_8(Actor *, s32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 _sukickball_entrypoint_6(Actor *, s32);
extern u8 unk65[];
extern s32 D_80804D7C_chcollballcontrol[];
extern u8 _sukickball_entrypoint_3(void);
extern u8 _gcstatusDll_entrypoint_11(void);
extern u8 unk39[];
extern f32 _sukickball_entrypoint_15(s32);
typedef struct { u8 pad_0[10]; u8 local_0[4]; u8 pad_1[2]; Unk80132ED0 *local_1[4]; } CollisionBallPlayers;
typedef struct { s32 local_0[6]; } CollballCountRecord;
extern CollballCountRecord D_80804D90_chcollballcontrol;
typedef struct { u8 pad0[0x24]; u32 unk24_22 : 10; u32 pad24 : 22; } BallMarker;
typedef struct { BallMarker *marker; s32 pad4; s32 flags; } BallEntry;
extern s32 *func_800BE444(f32 *);
extern void *func_800E9E88(s32);
extern void *func_800E9EB4(s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC298(f32);
extern f32 D_80804CC8_chcollballcontrol[][2];
extern void *D_80804DA8_chcollballcontrol;
extern s32 D_80804DF0_chcollballcontrol;
extern void func_800B4470(f32 *, f32 *, void *, s32, f32, f32, s32, s32, s32);
extern void _sukickball_entrypoint_11(Actor *, s32);
extern void func_800F4F98();
typedef struct { u8 pad_0[0x14]; f32 local_0; f32 local_1; } CollisionBallLaunchState;
extern f32 func_800DC178(f32, f32);
extern s32 D_80804C64_chcollballcontrol[];
extern s32 D_80804E08_chcollballcontrol[];
extern u8 D_80804C74_chcollballcontrol[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 D_80804E4C_chcollballcontrol[];
extern u32 D_80804E94_chcollballcontrol[];
extern u32 D_80804EE4_chcollballcontrol[];
typedef struct { Unk80132ED0 *local_0; s32 local_1; u32 local_2; } CollballSpatialEntry;
typedef struct { u8 pad_0[0x24]; u32 local_0 : 10; u32 pad_1 : 22; } CollballMarkerC010;
extern s32 *func_800BE3F8(f32 *);
typedef struct { u8 pad_0[0x1C]; f32 local_0; } CollballContact1472;
extern s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
extern u8 D_80804C84_chcollballcontrol[];
extern void *D_80804F2C_chcollballcontrol[];
extern f32 func_800D8FF8(void);
extern u8 D_80804C98_chcollballcontrol[];
extern f32 func_800F5F24(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int D_80804F58_chcollballcontrol[];
extern s32 D_80804FA0_chcollballcontrol[];
extern int D_80804FE8_chcollballcontrol[];
typedef struct { u8 local_0[0x64]; u32 local_1 : 2; u32 local_2 : 1; u32 local_3 : 29; } local_struct;
typedef struct BallMotionVector_808032CC_chcollballcontrol { f32 local_0[3]; } BallMotionVector_808032CC_chcollballcontrol;
extern BallMotionVector_808032CC_chcollballcontrol D_80805098_chcollballcontrol;
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
typedef union { s32 local_0; void *local_1; } CollballControlEvent;
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct { u8 pad[0x65]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS101;
extern s32 D_808050B4_chcollballcontrol[];
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800EEF94();
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct { s32 a, b, c; } W3;
typedef struct { s32 local_0; u8 pad_0[0x10]; u8 local_1; } CollisionBallState;
typedef struct { u8 pad_0[0x64]; u8 local_0 : 1; u8 pad_1 : 1; u8 local_1 : 1; u8 local_2 : 2; u8 pad_2 : 3; } CollisionBallPlayerFlags;
typedef struct BallMotionVector_8080486C_chcollballcontrol { f32 local_0[3]; } BallMotionVector_8080486C_chcollballcontrol;
extern u8 D_808050C0_chcollballcontrol[];
extern f32 func_800136E4(f32);
extern Actor *func_801084B0(s32, Actor **);
extern s32 func_800D211C();
extern void func_800CE8D8(s32, f32, s32);
extern void func_800FDC28(s32);
extern s32 _capod_entrypoint_17(f32);
extern s32 func_800CEB54(s32, f32);
extern u8 D_80804DF4_chcollballcontrol[];
extern f32 func_800EFBFC(f32 *, f32 *);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct { f32 unk0; u8 pad_4[0x1C]; u8 unk20; } BallControlLocal;
typedef struct { f32 local_0[4]; } CollballDistancesC010;
typedef struct { f32 local_0[3]; } BallMotionVector_80802CE0_chcollballcontrol;
typedef struct { f32 local_0; u8 pad_0[0x1C]; u8 local_1; } CollballStateC010;
typedef struct { u8 pad_0[0x3A]; u8 local_0; } CollballPlayersC010;
extern CollballDistancesC010 D_80804F3C_chcollballcontrol;
extern BallMotionVector_80802CE0_chcollballcontrol D_80804F4C_chcollballcontrol;
extern u8 _chcollballcontrol_entrypoint_1[];
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct { s32 local_0; f32 local_1; f32 local_2[3]; } CollballDataTop50;
typedef struct { u8 pad_0[0x64]; u32 pad_1:2; u32 local_0:1; u32 pad_2:29; } CollballEnableTop50;
extern s32 _sukickball_entrypoint_5(Actor *, f32 *);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern void _sukickball_entrypoint_2(Actor *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, f32 *);
void func_80801108_chcollballcontrol();
void func_80801350_chcollballcontrol();
void func_80801500_chcollballcontrol();
void func_808015D4_chcollballcontrol();
void func_80801650_chcollballcontrol();
void func_808021D4_chcollballcontrol();
void func_80802264_chcollballcontrol();
void func_80802324_chcollballcontrol();
void func_808028D0_chcollballcontrol();
void func_80802964_chcollballcontrol();
void func_808029D8_chcollballcontrol();
void func_808030D0_chcollballcontrol();
void func_8080324C_chcollballcontrol();
void func_80803EF4_chcollballcontrol();
void func_80804A48_chcollballcontrol();
void func_80804AA8_chcollballcontrol();
f32 func_8080009C_chcollballcontrol();
f32 func_808000C8_chcollballcontrol();
void func_808006FC_chcollballcontrol();
void func_80800B5C_chcollballcontrol();
void func_808020F4_chcollballcontrol();
int func_8080237C_chcollballcontrol();
void func_808023FC_chcollballcontrol();
void func_80802A50_chcollballcontrol();
void func_80802CE0_chcollballcontrol();
s32 func_80803D54_chcollballcontrol();
Actor *func_8080451C_chcollballcontrol();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_808006FC_chcollballcontrol(), func_80800DD8_chcollballcontrol();

void func_80800000_chcollballcontrol(s32 *param_0, s32 param_1, s32 param_2)
{
    _subaddiedialog_entrypoint_11(param_0[0], param_1, param_2 | 0xE, param_0 + 1, 0x33);
}

f32 func_80800040_chcollballcontrol(Actor *param_0) {
    return D_80804CB4_chcollballcontrol[((u8 *)func_80100094(param_0, 0))[0x14]];
}

f32 func_80800070_chcollballcontrol(Actor *param_0) {
    return func_80800040_chcollballcontrol(param_0) * 0.75f;
}

f32 func_8080009C_chcollballcontrol(param_0) Actor *param_0; {
    return func_80800040_chcollballcontrol(param_0) * 0.33f;
}

f32 func_808000C8_chcollballcontrol(param_0) Actor *param_0; {
    return func_80800040_chcollballcontrol(param_0) * 0.05f;
}

f32 func_808000F4_chcollballcontrol(Actor *param_0)
{
    return func_808000C8_chcollballcontrol(param_0);
}

s32 func_80800114_chcollballcontrol(s32 param_0, s32 param_1) {
    return D_80804CF0_chcollballcontrol[param_0][param_1];
}

int func_80800138_chcollballcontrol(s32 param_0)
{
  return D_80804D68_chcollballcontrol[param_0];
}

void func_8080014C_chcollballcontrol(s32 param_0) {
    s32 local_0;
    u8 *local_1;
    u8 *local_2;

    local_1 = func_80100094(param_0, 0);
    local_0 = 0;
    local_2 = local_1;
    if ((s32) local_1[0x3A] > 0) {
        do {
            if (local_1[0x39] == 1) {
                *(s32 *)(local_2 + 0x20) = 0x32;
            } else {
                *(s32 *)(local_2 + 0x20) = 0;
            }
            local_0 += 1;
            local_2 += 4;
        } while (local_0 < (s32) local_1[0x3A]);
    }
}

void func_808001B8_chcollballcontrol(Actor *param_0, s32 param_1)
{
    Actor *local_0;

    switch (param_1) {
        case 1:
        case 6:
            local_0 = func_801084B0(0x1A1, &param_0);
            break;
        case 5:
            local_0 = func_801084B0(0x1A1, &param_0);
            local_0->unk64_19 = 1;
            break;
        case 3:
            local_0 = func_801084B0(0x1A3, &param_0);
            break;
        case 2:
            local_0 = func_801084B0(0x1A2, &param_0);
            break;
        case 4:
            local_0 = func_801084B0(0x1A2, &param_0);
            local_0->unk64_19 = 1;
            break;
    }
    local_0->position[0] = func_800DC178(-470.0f, 470.0f);
    local_0->position[2] = func_800DC178(-470.0f, 470.0f);
    local_0->unk3C = param_0->unk0;
}

s32 func_808002B8_chcollballcontrol(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    f32 local_1;
    s32 local_3;
    s32 local_2;
    s16 *local_4;
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
            _subaddiedialog_entrypoint_11(param_0->unk0, local_0[0x39] + 0x12C7, 6, (f32 *)((u8 *)func_80106790(((s32 *)(local_0 + 0x14))[local_0[0x39]]) + 4), 0);
            param_0->unk64_20 = 1;
        }
        return 3;
    case 0x2E:
        switch (local_4[0]) {
        case 0x12CC:
        case 0x12CD:
            if (func_800D2054(1, local_0[0x39] + 0x91, *(s32 *)(local_0 + 0x20) + 0x3E80) == 1) {
                func_80800000_chcollballcontrol(param_0, 0x12D4, 0x200);
                break;
            }
        case 0x127F:
        case 0x1280:
        case 0x12D4:
            func_80800000_chcollballcontrol(param_0, 0xCEB, 0x240);
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
                _gcgoto_entrypoint_1(0x12D, 5);
            }
            break;
        case 0x127A:
            func_800FDC28(0xF);
            func_8080014C_chcollballcontrol(param_0);
            local_2 = func_80800138_chcollballcontrol(local_0[0x39]);
            local_3 = func_80800138_chcollballcontrol(local_0[0x39]);
            func_800CE8D8(0, local_2, local_3);
            func_800CE88C(0, 1);
            func_80801500_chcollballcontrol(param_0, 0);
            param_0->unk70_10 = 4;
            break;
        case 0x12D1:
        case 0x12D2:
            _gcfrontend_entrypoint_10();
            break;
        case 0x12C7:
        case 0x12C8:
        case 0x12C9:
            param_0->unk64_20 = 0;
            break;
        }
        break;
    case 0x30:
        switch (local_4[0]) {
        case 0x12D1:
            return local_0[0x3B];
        case 0x12D4:
            return func_800D211C(local_0[0x39] + 0x91) - 0x3E80;
        }
        break;
    case 0x3D:
        func_808001B8_chcollballcontrol(param_0, param_2);
        break;
    case 0x49:
        switch (local_0[0x39]) {
        case 0:
        case 1:
        case 2:
            if (!func_800D395C()) {
                if (!func_800DA9E4(local_0[0x39] + 0x41F, 1)) {
                    _capod_entrypoint_13(param_0->unk0, 0, 1, 0x2020);
                    param_0->unk79_4 = 1;
                    break;
                }
            }
            func_800A54F8(0);
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

void func_808011E8_chcollballcontrol();

void func_808008FC_chcollballcontrol();

void func_808006FC_chcollballcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    *(f32 *)local_0 -= local_1;
    *(f32 *)(local_0 + 4) -= local_1;
    switch (param_0->unk70_10) {
    case 1:
        _sukickball_entrypoint_17(param_0);
        if (!func_800DA298(0x6AD) && param_0->unk79_4 != 1 && !param_0->unk64_20) {
            if (param_0->unk79_4 == 2) {
                _capod_entrypoint_14();
            }
            local_2 = local_0[0x39];
            if (local_2 == 0 || local_2 == 1 || local_2 == 2) {
                func_800A54F8(0);
            }
            func_80800000_chcollballcontrol(param_0, 0x127A, 0);
            param_0->unk70_10 = 3;
            return;
        }
        break;
    case 3:
        _sukickball_entrypoint_17(param_0);
        return;
    case 6:
        _sukickball_entrypoint_19(param_0, 1, local_0[0x3A]);
        return;
    case 4:
        _sukickball_entrypoint_19(param_0, 0, local_0[0x3A]);
        func_808011E8_chcollballcontrol(param_0);
        if (func_800CEB54(0, 6.0f)) {
            func_800FDC28(0x10);
            return;
        }
        if (func_800CEAD0(0)) {
            func_808008FC_chcollballcontrol(param_0);
            return;
        }
        break;
    case 7:
        func_808011E8_chcollballcontrol(param_0);
        return;
    case 8:
        _sukickball_entrypoint_19(param_0, 1, local_0[0x3A]);
        if (param_0->unk58 > 0.0f) {
            param_0->unk58 -= func_800D8FF8();
        } else {
            _gcgoto_entrypoint_1(0x12D, 5);
        }
        break;
    }
}

void func_808008FC_chcollballcontrol(Actor *param_0)
{
    CollballScoreState *local_0;
    s32 local_1[4];
    s32 local_2;
    s32 local_3[4];
    s32 local_4;
    s32 local_5;
    s32 local_6;

    local_0 = func_80100094(param_0, 0);
    param_0->unk70_10 = 6;
    func_80801500_chcollballcontrol(param_0, 1);
    func_800FDC28(0);
    local_2 = _sumultiscore_entrypoint_2(local_0->local_0, local_1, local_3, 1, local_0->local_4);
    if (local_0->local_3 < 4) {
        if (param_0->unk64_19) {
            switch (local_1[0]) {
            case 1:
                if (local_3[0] == 0) {
                    func_800FC6B0(0x16);
                    func_80800000_chcollballcontrol(param_0, 0x12CC, 0x200);
                    break;
                }
            case 2:
            case 3:
            case 4:
                func_80800000_chcollballcontrol(param_0, 0x12CD, 0x200);
                func_800FC6B0(0x17);
                break;
            }
        } else {
            switch (local_1[0]) {
            case 1:
                if (local_3[0] == 0) {
                    func_800D2054(1, local_0->local_3 + 0x91, local_0->local_0[0] + 16000);
                    func_800DA544(0xA17);
                    func_800FC6B0(0x16);
                    func_80101FDC(param_0, 8);
                    param_0->unk58 = 2.5f;
                    break;
                }
            case 2:
            case 3:
                func_80800000_chcollballcontrol(param_0, 0x127F, 0x200);
                func_800FC6B0(0x17);
                break;
            case 4:
                func_80800000_chcollballcontrol(param_0, 0x1280, 0x200);
                func_800FC6B0(0x17);
                break;
            }
        }
    } else {
        func_800AA200(1);
        for (local_5 = 0; local_5 < local_0->local_4; local_5++) {
            if (local_1[local_5] == 1) local_0->local_1[local_5] = 1;
            else local_0->local_1[local_5] = 0;
        }
        if (local_2 != 0) {
            local_4 = 0x12D1;
            local_0->local_5 = local_2;
        } else {
            local_4 = 0x12D2;
        }
        func_800FC6B0(0x10);
        func_80800000_chcollballcontrol(param_0, local_4, 0);
    }
}

void func_80800B5C_chcollballcontrol(param_0) Actor *param_0;
{
    *(f32 *)&param_0->actorData[3] = func_8080009C_chcollballcontrol(param_0);
    *(f32 *)&param_0->actorData[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        *(f32 *)&param_0->actorData[7] = -*(f32 *)&param_0->actorData[7];
    }
    func_8080324C_chcollballcontrol(param_0, 9);
    param_0->unk64_20 = 1;
}

void func_80800BF0_chcollballcontrol(Actor *param_0, f32 *param_1)
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
                func_80800B5C_chcollballcontrol(local_2);
            }
        }
    }
}

int func_80800CF8_chcollballcontrol(s32 param_0, s32 param_1)
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

void func_80800D60_chcollballcontrol(Actor *param_0, s32 param_1, s32 param_2)
{
  if (param_1 || func_800D395C())
  {
    *((u8 *) (((char *) param_0) + 0x65)) = ((*((u8 *) (((char *) param_0) + 0x65))) & 0xFFFFu) | 8;
    _chintrotext_entrypoint_1(0x18b5, param_2 + (0xe ^ 0), 0, 0);
  }
  else
  {
    *((u8 *) (((char *) param_0) + (0x65 & 0xFFFFFFFFu))) &= ~8;
    _chintrotext_entrypoint_2(1);
  }
}

void func_80800DD8_chcollballcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    Actor *local_5;

    local_0 = func_80100094(param_0, 0);
    local_0[0x3C] = 0;
    if (!func_80090178(0x80)) {
        func_800FFAB0(param_0);
        return;
    }
    func_800DA3B8(0x65A, 1);
    local_0[0x39] = _sukickball_entrypoint_3();
    local_0[0x3A] = D_80804D7C_chcollballcontrol[local_0[0x39]];
    switch (local_0[0x39]) {
    case 0:
        func_80800D60_chcollballcontrol(param_0, func_800DA298(0x368), local_0[0x39]);
        break;
    case 1:
        func_80800D60_chcollballcontrol(param_0, func_800DA298(0x369), local_0[0x39]);
        break;
    case 2:
        func_80800D60_chcollballcontrol(param_0, func_800D0A9C(0x44, 1), local_0[0x39]);
        break;
    case 4:
        for (local_2 = 0; local_2 < 8; local_2++) {
            if (func_800F6438(local_2)) func_800F4CEC(local_2, 0);
        }
        local_0[0x3A] = _gcstatusDll_entrypoint_11();
        break;
    }
    for (local_3 = 0, local_4 = 0; local_3 < local_0[0x3A]; local_3++, local_4 += 4) {
        local_1 = func_80100094(param_0, 0);
        local_1[local_3 + 0x34] = 0;
        *(s32 *)(local_1 + local_4 + 0x10) = 0;
    }
    local_3 = 0;
    if (local_0[0x39] == 4) local_0[0xA] = 1;
    else local_0[0xA] = 2;
    local_0[0xB] = 1;
    local_0[0xC] = 1;
    local_0[0xD] = 1;
    if (local_3 < local_0[0x3A]) {
        local_1 = local_0;
        do {
            switch (local_1[0xA]) {
            case 2:
                break;
            case 1:
                local_5 = func_801084B0(0x19F, &param_0);
                    ((Unk80132ED0 **)(local_0 + 0x10))[local_3] = local_5->unk0;
                local_5->unk3C = param_0->unk0;
                break;
            }
            func_80801108_chcollballcontrol(param_0, local_3);
            local_3++;
            local_1++;
        } while (local_3 < local_0[0x3A]);
    }
    _sukickball_entrypoint_18(param_0);
    local_0[0x3C] = 1;
}

int func_80801038_chcollballcontrol(param_0) s32 param_0;
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

void func_808010B8_chcollballcontrol(Actor *param_0, s32 param_1)
{
    param_0->unk6C_0 = param_1;
    if (param_1 == 2) {
        param_0->unk64_24 = 1;
    } else {
        param_0->unk64_24 = 0;
    }
}

int func_808010F8_chcollballcontrol(s32 param_0[3])
{
    return (*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF;
}

void func_80801108_chcollballcontrol(param_0, param_1) Actor *param_0; s32 param_1;
{
    CollisionBallPlayers *local_2;
    Actor *local_0;
    f32 local_1[3];

    local_2 = (CollisionBallPlayers *)func_80100094(param_0, 0);
    switch (local_2->local_0[param_1]) {
    case 1:
        local_0 = func_80106790(local_2->local_1[param_1]);
        _sukickball_entrypoint_16(param_1, local_0->position);
        local_0->rotation[1] = _sukickball_entrypoint_15(param_1);
        local_0->unk54 = local_0->rotation[1];
        func_808010B8_chcollballcontrol(local_0, param_1);
        break;
    case 2:
        func_800F82D4(param_1, 2);
        local_1[0] = 0.0f;
        local_1[1] = _sukickball_entrypoint_15(param_1);
        local_1[2] = 0.0f;
        func_800F832C(param_1, local_1);
        _sukickball_entrypoint_16(param_1, local_1);
        func_800F8294(param_1, local_1);
        break;
    }
}

void func_808011E8_chcollballcontrol(Actor *param_0)
{
    s32 local_1;
    CollballCountRecord local_0;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    local_0 = D_80804D90_chcollballcontrol;
    local_1 = -1;
    func_80801350_chcollballcontrol(param_0, &local_0);
    if (local_0.local_0[1] < func_80800114_chcollballcontrol(local_2[0x39], 1)) local_1 = 1;
    else if (local_0.local_0[2] < func_80800114_chcollballcontrol(local_2[0x39], 2)) local_1 = 2;
    else if (local_0.local_0[3] < func_80800114_chcollballcontrol(local_2[0x39], 3)) local_1 = 3;
    else if (local_0.local_0[4] < func_80800114_chcollballcontrol(local_2[0x39], 4)) local_1 = 4;
    else if (local_0.local_0[5] < func_80800114_chcollballcontrol(local_2[0x39], 5)) local_1 = 5;
    if (local_1 >= 0) {
        func_80108B04(param_0, local_1);
        return;
    }
    if (local_0.local_0[0] < func_80800114_chcollballcontrol(local_2[0x39], 0)) {
        func_80801650_chcollballcontrol(param_0);
    }
}

void func_80801350_chcollballcontrol(param_0, param_1) Actor *param_0; s32 *param_1;
{
    s32 i;
    s32 *local_0;
    BallEntry *local_1;
    BallEntry *local_2;

    for (i = 0; i < 6; i++) {
        param_1[i] = 0;
    }
    local_0 = func_800BE444(param_0->position);
    for (; *local_0; local_0++) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (local_1->flags & 1) {
                switch (local_1->marker->unk24_22) {
                case 0x44:
                    if (func_80106790(local_1->marker)->unk64_19) {
                        param_1[5]++;
                    } else {
                        param_1[1]++;
                    }
                    break;
                case 0x43:
                    if (func_80106790(local_1->marker)->unk64_19) {
                        param_1[4]++;
                    } else {
                        param_1[2]++;
                    }
                    break;
                case 0x42:
                    param_1[3]++;
                    break;
                }
            }
        }
    }
    param_1[0] = param_1[1] + param_1[2] + param_1[3] + param_1[4] + param_1[5];
}

void func_80801500_chcollballcontrol(param_0, param_1) s32 param_0; s32 param_1; {
    s32 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if ((s32)*(u8 *)((char *)local_0 + 0x3A) > 0) {
        do {
            func_808015D4_chcollballcontrol(param_0, local_1, param_1);
            local_1 += 1;
        } while (local_1 < (s32)*(u8 *)((char *)local_0 + 0x3A));
    }
}

void func_80801578_chcollballcontrol(Unk80132ED0 *param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80106790(param_0);
  switch (param_1)
  {
    case 0 :
      func_8080324C_chcollballcontrol(local_0, 2);
      break;

    case 1 :
      func_8080324C_chcollballcontrol(local_0, 0xB);

  }

}

void func_808015D4_chcollballcontrol(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    CollisionBallPlayers *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (local_0->local_0[param_1]) {
    case 0:
        break;
    case 2:
        func_80800CF8_chcollballcontrol(param_1, param_2);
        break;
    case 1:
        func_80801578_chcollballcontrol(local_0->local_1[param_1], param_2);
        break;
    }
}

void func_80801650_chcollballcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800DC0C0();
    if (func_800EA05C() == 0x12D && param_0->unk70_10 == 1) {
        return;
    }
    if (local_1 < D_80804CC8_chcollballcontrol[local_0[0x39]][0] && local_0[0x39] != 1) {
        local_2 = func_800DC298(0.5f) || !local_0[0x39] ? 1 : 5;
    } else if (local_1 < D_80804CC8_chcollballcontrol[local_0[0x39]][1]) {
        local_2 = func_800DC298(0.5f) ? 2 : 4;
    } else {
        local_2 = 3;
    }
    func_80108B04(param_0, local_2);
}

int chcollballcontrol_entrypoint_0()
{
  return &D_80804DA8_chcollballcontrol;
}

void func_80801764_chcollballcontrol(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 2 && param_1 != param_0->unk70_10) {
        if (param_0->unk3C) {
            if (_sukickball_entrypoint_6(func_80106790(param_0->unk3C), local_0[0x20])) func_800F4F98(local_0[0x20], param_0->unk0);
            _sukickball_entrypoint_11(func_80106790(param_0->unk3C), local_0[0x20]);
        }
    }
    if (param_0->unk70_10 == 3 && param_1 == 2 && (param_0->unk0->unk24 >> 22) == 0x42) {
        *(f32 *)(local_0 + 0x14) = 20.0f;
        *(f32 *)(local_0 + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(param_0);
        func_808021D4_chcollballcontrol(param_0);
        param_1 = 4;
    }
    func_80101FDC(param_0, param_1);
    if (param_0->unk70_10 == 6) {
        func_808021D4_chcollballcontrol(param_0);
        _subaddiefade_entrypoint_3(param_0);
        func_800B4470(param_0->position, 0, &D_80804DF0_chcollballcontrol, 1, 0.75f, 0.0f, 125, 250, 0);
        switch (param_0->unk0->unk24 >> 22) {
        case 0x44: func_80802264_chcollballcontrol(param_0, 1); break;
        case 0x43: func_80802264_chcollballcontrol(param_0, 2); break;
        }
    }
}

void func_80801920_chcollballcontrol(Actor *param_0)
{
  void *local_0;
  local_0 = func_80100094(param_0, 0 * 0);
  *((u8 *) (((char *) local_0) + 0x20)) = 0x7F;
  *((float *) (((char *) local_0) + 4)) = 0.0f;
  *((float *) (((char *) local_0) + 0)) = .0f;
  *((float *) (((char *) param_0) + 0x24)) = 0.0f;
}

void func_80801964_chcollballcontrol(Actor *param_0)
{
    CollisionBallLaunchState *local_0;

    local_0 = func_80100094(param_0, 0);
    param_0->unk74_17 = 0;
    func_8010A590(param_0);
    param_0->scale = 1.5f;
    param_0->rotation[0] = func_800DC178(0.0f, 45.0f);
    param_0->rotation[2] = func_800DC178(0.0f, 45.0f);
    func_80801920_chcollballcontrol(param_0);
    if (param_0->unk64_19) {
        local_0->local_0 = 20.0f;
        local_0->local_1 = 8.0f;
    }
    param_0->alpha = 0;
    param_0->position[1] = -75.0f;
}

void func_80802764_chcollballcontrol();

void func_808022F0_chcollballcontrol();

void func_808020B0_chcollballcontrol();

void func_80801A20_chcollballcontrol(Actor *param_0)
{
    u8 *local_0;
    Actor *local_1;
    f32 local_4[3];
    f32 local_3[3];
    f32 local_5[3];
    Actor *local_2;
    Actor *local_9;
    f32 local_6;
    f32 local_7;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80106790(param_0->unk3C);
    switch (param_0->unk70_10) {
    case 5:
        if (param_0->position[1] < 25.0f)
            param_0->position[1] += 5.0f;
        if ((f32)(u32)param_0->alpha < 240.0f) {
            param_0->alpha = (u32)((f32)(u32)param_0->alpha + 15.0f);
        } else if (param_0->position[1] >= 25.0f) {
            param_0->unk70_10 = 1;
            param_0->alpha = 0xFF;
        }
        break;
    case 1:
        func_80802CE0_chcollballcontrol(param_0);
        func_80802764_chcollballcontrol(param_0);
        func_808020B0_chcollballcontrol(param_0);
        break;
    case 2:
        func_800EE7F8(local_3, param_0->position);
        func_80802764_chcollballcontrol(param_0);
        if (_sukickball_entrypoint_6(local_1, local_0[0x20])) {
            func_800F5A00(local_0[0x20], local_4);
            param_0->unk54 = func_800F5F24(local_0[0x20]);
            param_0->position[1] = 0.0f;
            func_800EFCD8(param_0->position, param_0->unk54, 60.0f);
            func_800EF04C(param_0->position, local_4);
            func_800F5D70(local_0[0x20], local_5);
            param_0->unk50 = local_5[0] * local_5[0] + local_5[2] * local_5[2];
            func_800EE7F8((f32 *)param_0->actorData, local_4);
        } else {
            local_2 = func_80106790(_sukickball_entrypoint_8(local_1, local_0[0x20]));
            param_0->position[1] = 0.0f;
            func_800EFCD8(param_0->position, local_2->rotation[1], 60.0f);
            func_800EF04C(param_0->position, local_2->position);
            param_0->unk54 = local_2->rotation[1];
            param_0->unk50 = *(f32 *)&local_2->actorData[3] * *(f32 *)&local_2->actorData[3];
            func_800EE7F8((f32 *)param_0->actorData, local_2->position);
        }
        if (func_800EFBFC(local_3, param_0->position) > 25.0f) {
            if (func_800DC0C0() < 0.1f) {
                func_800B4470(local_3, 0, D_80804DF4_chcollballcontrol,
                    1, 0.75f, 0.0f, 75, 150, 0);
            }
        }
        func_800D9078(local_0);
        func_80802CE0_chcollballcontrol(param_0);
        if (_sukickball_entrypoint_7(local_1, local_0[0x20])) {
            local_9 = func_80106790(_sukickball_entrypoint_8(local_1, local_0[0x20]));
            if (local_9->unk64_20 == 1) {
                func_808030D0_chcollballcontrol(param_0);
                local_9->unk58 = 0.0f;
                local_9->unk64_20 = 0;
            }
        }
        func_808020B0_chcollballcontrol(param_0);
        break;
    case 3:
        func_80802764_chcollballcontrol(param_0);
        func_800EF1B8(param_0->position, param_0->rotation[1],
            *(f32 *)&param_0->actorData[3] * func_800D8FF8());
        *(f32 *)&param_0->actorData[3] -= 6.0f;
        if ((param_0->unk0->unk24 >> 22) == 0x42) {
            if (*(f32 *)&param_0->actorData[3] < 600.0f) {
                *(f32 *)(local_0 + 0x14) += *(f32 *)(local_0 + 0x18);
                *(f32 *)(local_0 + 0x18) += 0.5f;
            }
        }
        if (*(f32 *)&param_0->actorData[3] <= 0.0f) {
            func_80801764_chcollballcontrol(param_0, 1);
            func_808021D4_chcollballcontrol((u8 *)param_0);
        }
        func_80802CE0_chcollballcontrol(param_0);
        if (func_800DC0C0() < 0.15f && *(f32 *)&param_0->actorData[3] > 120.0f) {
            func_800B4470(param_0->position, 0, D_80804DF4_chcollballcontrol,
                1, 0.75f, 0.0f, 50, 100, 0);
        }
        func_808020B0_chcollballcontrol(param_0);
        break;
    case 4:
        func_80802764_chcollballcontrol(param_0);
        func_808020F4_chcollballcontrol((u8 *)param_0);
        break;
    case 6:
        *(f32 *)&param_0->actorData[3] -= 15.0f;
        func_808020F4_chcollballcontrol((u8 *)param_0);
        break;
    }
    if (*(f32 *)&param_0->actorData[3] > 30.0f) {
        local_6 = func_800137AC(param_0->rotation[1]);
        local_7 = func_800137C4();
        param_0->rotation[0] += ((local_6 * *(f32 *)&param_0->actorData[3]) + (local_6 * *(f32 *)&param_0->actorData[3])) / 30.0f;
        param_0->rotation[2] -= ((local_7 * *(f32 *)&param_0->actorData[3]) + (local_7 * *(f32 *)&param_0->actorData[3])) / 30.0f;
    }
    if ((param_0->unk0->unk24 >> 22) == 0x42) {
        if (param_0->unk70_10 != 4 && param_0->unk70_10 != 6 && param_0->unk7C_12) {
            if (func_800DC0C0() < 0.1f)
                func_808022F0_chcollballcontrol((s32)(local_0 + 8));
        }
    }
    if (param_0->unk64_19)
        *(f32 *)(local_0 + 0x14) += *(f32 *)(local_0 + 0x18);
    if (*(f32 *)(local_0 + 0x1C) > 0.0f)
        *(f32 *)(local_0 + 0x1C) -= func_800D8FF8();
}

void func_808020B0_chcollballcontrol(Actor *param_0) {
    s32 local_0;

    local_0 = func_8080237C_chcollballcontrol();
    *(f32*)((char*)param_0 + 0x8) = 30.0f;
    if (local_0 != -1) {
        func_808023FC_chcollballcontrol(param_0, local_0);
    }
}

void func_808020F4_chcollballcontrol(param_0) u8 *param_0;
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

void func_808021D4_chcollballcontrol(param_0) u8 *param_0; {
    s32 local_0;

    local_0 = func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C))));
    if (((u32) (*(u32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0)))) + (0x24))) >> 0x16) == 0x42) {
        func_80802324_chcollballcontrol(param_0 + 4);
        func_80802A50_chcollballcontrol(param_0);
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80804C64_chcollballcontrol);
        _subaddiefade_entrypoint_3(param_0);
        func_80801764_chcollballcontrol(param_0, 4);
        func_80800BF0_chcollballcontrol(local_0, param_0 + 4);
    }
}

void func_80802264_chcollballcontrol(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;

    local_0 = func_800BABB8(0, param_0->position, NULL, 1.0f, D_80804E08_chcollballcontrol);
    func_800BA670(local_0, param_1 == 1 ? 0x679 : 0x67A);
    func_800BA22C(local_0, 10);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80804C74_chcollballcontrol);
}

void func_808022F0_chcollballcontrol(param_0) s32 param_0; {
    func_800BBCB8(param_0, 0, 1.0f, 2, &D_80804E4C_chcollballcontrol);
}

void func_80802324_chcollballcontrol(param_0) Actor *param_0;
{
    func_800BBCB8(param_0, 0, 1.0f, 10, D_80804E94_chcollballcontrol);
    func_800BBCB8(param_0, 0, 1.0f, 5, D_80804EE4_chcollballcontrol);
}

int func_8080237C_chcollballcontrol(param_0) f32 param_0[3];
{
  if (param_0[1] < -675.0f)
  {
    return 2;
  }
  else
    if (param_0[1] > 675.0f)
  {
    return 0;
  }
  if (param_0[3] < -675.0f)
  {
    return 3;
  }
  else
    if (param_0[3] > 675.0f)
  {
    return 1;
  }
  return -1;
}

void func_80802AF8_chcollballcontrol();

void func_808023FC_chcollballcontrol(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_1) {
    case 0:
        if (-183.0f < param_0->position[2] && param_0->position[2] < 183.0f) {
            if (param_0->unk70_10 != 4 && 720.0f < param_0->position[0]) {
                func_80802AF8_chcollballcontrol(param_0, 0);
            }
            if (801.0f < param_0->position[0]) {
                param_0->position[0] = 846.0f;
                ((f32 *)param_0->actorData)[3] = 0.0f;
            }
        } else {
            param_0->position[0] = 720.0f;
            ((f32 *)param_0->actorData)[3] = 0.0f;
            func_80801764_chcollballcontrol(param_0, 6);
        }
        break;
    case 1:
        if (param_0->position[0] < 183.0f && -183.0f < param_0->position[0]) {
            if (param_0->unk70_10 != 4 && 720.0f < param_0->position[2]) {
                func_80802AF8_chcollballcontrol(param_0, 1);
            }
            if (801.0f < param_0->position[2]) {
                param_0->position[2] = 846.0f;
                ((f32 *)param_0->actorData)[3] = 0.0f;
            }
        } else {
            param_0->position[2] = 720.0f;
            ((f32 *)param_0->actorData)[3] = 0.0f;
            func_80801764_chcollballcontrol(param_0, 6);
        }
        break;
    case 2:
        if (param_0->position[2] < 183.0f && -183.0f < param_0->position[2]) {
            if (param_0->unk70_10 != 4 && param_0->position[0] < -720.0f) {
                func_80802AF8_chcollballcontrol(param_0, 2);
            }
            if (param_0->position[0] < -801.0f) {
                param_0->position[0] = -846.0f;
                ((f32 *)param_0->actorData)[3] = 0.0f;
            }
        } else {
            param_0->position[0] = -720.0f;
            ((f32 *)param_0->actorData)[3] = 0.0f;
            func_80801764_chcollballcontrol(param_0, 6);
        }
        break;
    case 3:
        if (-183.0f < param_0->position[0] && param_0->position[0] < 183.0f) {
            if (param_0->unk70_10 != 4 && param_0->position[2] < -720.0f) {
                func_80802AF8_chcollballcontrol(param_0, 3);
            }
            if (param_0->position[2] < -801.0f) {
                param_0->position[2] = -846.0f;
                ((f32 *)param_0->actorData)[3] = 0.0f;
            }
        } else {
            param_0->position[2] = -720.0f;
            ((f32 *)param_0->actorData)[3] = 0.0f;
            func_80801764_chcollballcontrol(param_0, 6);
        }
        break;
    }
}

void func_80802764_chcollballcontrol(Actor *param_0)
{
    s32 *local_0;
    CollballSpatialEntry *local_1;
    CollballSpatialEntry *local_2;
    Unk80132ED0 *local_3;

    local_0 = func_800BE3F8(param_0->position);
    while (*local_0) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        while (local_1 < local_2) {
            if (local_1->local_2 & 1) {
                local_3 = local_1->local_0;
                if (local_3 != param_0->unk0) {
                    if (0x44 == ((CollballMarkerC010 *)local_3)->local_0 || 0x42 == ((CollballMarkerC010 *)local_3)->local_0 || 0x43 == ((CollballMarkerC010 *)local_3)->local_0) {
                        func_808028D0_chcollballcontrol(param_0, func_80106790(local_3));
                    }
                    if (((CollballMarkerC010 *)local_3)->local_0 == 0) {
                        func_80802964_chcollballcontrol(param_0, (u32)*(u16 *)((u8 *)local_3 + 0x1A) >> 5);
                    }
                    if (0x40 == ((CollballMarkerC010 *)local_3)->local_0) {
                        func_808029D8_chcollballcontrol(param_0, func_80106790(local_3));
                    }
                }
            }
            local_1++;
        }
        local_0++;
    }
}

void func_808028D0_chcollballcontrol(param_0, param_1) Actor *param_0; Actor *param_1;
{
    CollballContact1472 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (_sukickball_entrypoint_13(param_0->position, param_1->position, 60.0f)) {
        if (local_0->local_0 <= 0.0f) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80804C84_chcollballcontrol);
            local_0->local_0 = 0.75f;
        }
    }
}

void func_80802964_chcollballcontrol(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_1;
    f32 local_0[3];

    local_1 = func_80106790(*(s32 **)(param_0 + 0x3C));
    if ((((u32)((u16)(*(u16 *)(param_0 + 0x72))) >> 10) != 2) && (_sukickball_entrypoint_12(local_1, param_1) != 0)) {
        func_800F5A00(param_1, local_0);
        _sukickball_entrypoint_13(local_0, param_0 + 4, 62.999996185302734f);
    }
}

void func_808029D8_chcollballcontrol(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_1;

    local_1 = func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C))));
    if (((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x72)))) >> 0xA) != 2) {
        if (_sukickball_entrypoint_12(local_1, func_808010F8_chcollballcontrol(param_1)) != 0) {
            _sukickball_entrypoint_13(param_1 + 4, param_0 + 4, 62.999996185302734f);
        }
    }
}

void func_80802A50_chcollballcontrol(param_0) Actor *param_0;
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

void func_80802AF8_chcollballcontrol(Actor *param_0, s32 param_1)
{
    Actor *local_0;
    local_0 = func_80106790(param_0->unk3C);
    func_80802A50_chcollballcontrol(param_0);
    switch (*(u32 *)((u8 *)param_0->unk0 + 0x24) >> 22) {
    case 0x44:
        if (param_0->unk64_19)
            _sukickball_entrypoint_9(local_0, D_80804F2C_chcollballcontrol[param_1], 5);
        else _sukickball_entrypoint_9(local_0, D_80804F2C_chcollballcontrol[param_1], 1);
        break;
    case 0x42:
        _sukickball_entrypoint_9(local_0, D_80804F2C_chcollballcontrol[param_1], 3);
        break;
    case 0x43:
        if (param_0->unk64_19)
            _sukickball_entrypoint_9(local_0, D_80804F2C_chcollballcontrol[param_1], 4);
        else _sukickball_entrypoint_9(local_0, D_80804F2C_chcollballcontrol[param_1], 2);
        break;
    }
    param_0->unk70_10 = 4;
    _subaddiefade_entrypoint_3(param_0);
}

void chcollballcontrol_entrypoint_1(Unk80132ED0 *param_0, s32 param_1, u32 param_2, s32 param_3)
{
    Actor *local_0;
    f32 *local_1;

    local_0 = func_80106790(param_0);
    local_1 = func_80100094(local_0, 0);
    switch (param_1) {
    case 3:
        func_80801764_chcollballcontrol(local_0, 1);
        break;
    case 1:
        local_1[1] = func_800D8FF8() * param_2;
        func_808030D0_chcollballcontrol(local_0);
        break;
    }
}

void func_80802CE0_chcollballcontrol(param_0) Actor *param_0;
{
    CollballStateC010 *local_0 = func_80100094(param_0, 0);
    CollballDistancesC010 local_1 = D_80804F3C_chcollballcontrol;
    Actor *local_2;
    CollballPlayersC010 *local_3;
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
                BallMotionVector_80802CE0_chcollballcontrol local_7 = D_80804F4C_chcollballcontrol;

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
                func_800F4950(local_0->local_1, param_0->unk0, _chcollballcontrol_entrypoint_1);
            } else {
                Actor *local_8 = func_80106790(_sukickball_entrypoint_8(local_2, local_0->local_1));

                ((u8 *)local_8)[0x65] &= ~0x10;
            }
            switch (((CollballMarkerC010 *)param_0->unk0)->local_0) {
            case 0x44:
                _sukickball_entrypoint_10(local_2, local_0->local_1, 1);
                break;
            case 0x42:
                _sukickball_entrypoint_10(local_2, local_0->local_1, 3);
                break;
            case 0x43:
                _sukickball_entrypoint_10(local_2, local_0->local_1, 2);
                break;
                        default:
                break;
}
            func_80801764_chcollballcontrol(param_0, 2);
            *(f32 *)((u8 *)param_0 + 0x24) = 0.0f;
        }
    }
}

void func_808030D0_chcollballcontrol(param_0) Actor *param_0;
{
    f32 local_3;
    Actor *local_0;
    Actor *local_1;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    local_0 = func_80106790(param_0->unk3C);
    if (_sukickball_entrypoint_6(local_0, local_2[0x20])) {
        param_0->rotation[1] = func_800F5F24(local_2[0x20]);
        local_3 = func_800F10B4(*(f32 *)(local_2 + 4), 0.0f, 1.0f, 450.0f, 900.0f);
        *(f32 *)((u8 *)param_0 + 0x24) = local_3;
        func_800F4F98(local_2[0x20], param_0->unk0);
        _sukickball_entrypoint_11(local_0, local_2[0x20]);
    } else {
        local_1 = func_80106790(_sukickball_entrypoint_8(local_0, local_2[0x20]));
        param_0->rotation[1] = local_1->rotation[1];
        local_3 = func_800F10B4(local_1->unk58, 8.0f, 16.0f, 450.0f, 900.0f);
        *(f32 *)((u8 *)param_0 + 0x24) = local_3;
        local_1->unk58 = 0.0f;
        _sukickball_entrypoint_11(local_0, local_2[0x20]);
    }
    param_0->unk70_10 = 3;
    local_2[0x20] = 0x7F;
    *(f32 *)local_2 = 0.0f;
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80804C98_chcollballcontrol);
}

void func_80803208_chcollballcontrol(s32 arg0)
{
    func_80801764_chcollballcontrol(arg0,0);
}

int *chcollballcontrol_entrypoint_2()
{
    return &D_80804F58_chcollballcontrol;
}

int chcollballcontrol_entrypoint_3()
{
    return D_80804FA0_chcollballcontrol;
}

int chcollballcontrol_entrypoint_4()
{
    return (int)&D_80804FE8_chcollballcontrol;
}

void func_8080324C_chcollballcontrol(param_0, param_1) Actor *param_0; s32 param_1;
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

void func_808032CC_chcollballcontrol(Actor *param_0, f32 *param_1)
{
    BallMotionVector_808032CC_chcollballcontrol local_0;
    f32 local_2;
    f32 local_1;

    local_0 = D_80805098_chcollballcontrol;
    if (param_1 == NULL) {
        local_2 = func_800DC178(110.0f, 250.0f);
        local_2 += param_0->rotation[1];
    } else {
        local_1 = func_80102D78(param_0, param_1);
        local_2 = func_800DC178(110.0f, 250.0f) + local_1;
    }
    func_800EFCD8(local_0.local_0, local_2, 500.0f);
    func_800EE780((f32 *)((u8 *)param_0 + 0x18), param_0->position, local_0.local_0);
    *(f32 *)((u8 *)param_0 + 0x24) = func_8080009C_chcollballcontrol(param_0);
    if (*(f32 *)((u8 *)param_0 + 0x18) > 720.0f) {
        *(f32 *)((u8 *)param_0 + 0x18) = 720.0f;
    }
    if (*(f32 *)((u8 *)param_0 + 0x20) > 720.0f) {
        *(f32 *)((u8 *)param_0 + 0x20) = 720.0f;
    }
    if (*(f32 *)((u8 *)param_0 + 0x18) < -720.0f) {
        *(f32 *)((u8 *)param_0 + 0x18) = -720.0f;
    }
    if (*(f32 *)((u8 *)param_0 + 0x20) < -720.0f) {
        *(f32 *)((u8 *)param_0 + 0x20) = -720.0f;
    }
    *(f32 *)((u8 *)param_0 + 0x34) = func_800DC178(0.25f, 1.0f);
    func_8080324C_chcollballcontrol(param_0, 7);
}

s32 func_80803420_chcollballcontrol(Actor *param_0, s32 param_1, CollballControlEvent param_2)
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

void func_8080486C_chcollballcontrol();

void func_8080405C_chcollballcontrol();

void func_80803F70_chcollballcontrol();

void func_80803E18_chcollballcontrol();

void func_80803484_chcollballcontrol(Actor *param_0)
{
    extern Vec3f D_808050A4_chcollballcontrol;
    extern u8 D_808050B0_chcollballcontrol[];

    CollballDataTop50 *local_0;
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
                    func_80800070_chcollballcontrol(param_0));
            } else {
                *(f32 *)((char *)param_0 + 0x24) = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x24), 0.0f, 1.0f, 0,
                    func_80800040_chcollballcontrol(param_0));
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

            func_8080486C_chcollballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chcollballcontrol(param_0),
                func_80800040_chcollballcontrol(param_0));

            if (func_800BD030(local_0->local_0, 9)) {
                func_8080324C_chcollballcontrol(param_0, 8);
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
                        D_808050B0_chcollballcontrol,
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
                    func_8080324C_chcollballcontrol(param_0, 2);

                    *(f32 *)((char *)param_0 + 0x24) =
                        func_8080009C_chcollballcontrol(param_0);
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

            if (((CollballEnableTop50 *)param_0)->local_0) {
                _subaddiejoy_entrypoint_3(param_0);

                if (!func_80102CF4(param_0, 8.0f)) {
                    func_80102B2C(param_0, 8.0f);
                }
            }

            func_8080405C_chcollballcontrol(param_0);
            break;

        case 12:
            if (*(f32 *)((char *)param_0 + 0x24) < 150.0f) {
                func_8080324C_chcollballcontrol(param_0, 2);

                *(f32 *)((char *)param_0 + 0x24) =
                    func_8080009C_chcollballcontrol(param_0);
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
            if (((CollballEnableTop50 *)param_0)->local_0) {
                func_8080324C_chcollballcontrol(param_0, 0xA);
                *(f32 *)((char *)param_0 + 0x58) = 0.0f;
            }

            if (!func_8080451C_chcollballcontrol(param_0)) {
                func_8080324C_chcollballcontrol(param_0, 1);
            }

            if (_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                if (func_800DC0C0() < 0.95f) {
                    func_8080324C_chcollballcontrol(param_0, 5);
                } else {
                    *(f32 *)((char *)param_0 + 0x34) =
                        func_800DC178(0.0f, 2.5f);

                    func_8080324C_chcollballcontrol(param_0, 4);
                }
            }

            func_8080486C_chcollballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chcollballcontrol(param_0),
                func_80800040_chcollballcontrol(param_0));
            break;

        case 1:
            _sukickball_entrypoint_16(
                param_0->unk6C_0,
                (char *)param_0 + 0x18
            );

            func_8080486C_chcollballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chcollballcontrol(param_0),
                func_80800040_chcollballcontrol(param_0));

            if (func_8080451C_chcollballcontrol(param_0)) {
                func_8080324C_chcollballcontrol(param_0, 2);
            }

            if (func_800EFFB4(
                    param_0->position,
                    50.0f,
                    (char *)param_0 + 0x18)) {
                func_8080324C_chcollballcontrol(param_0, 3);
            }
            break;

        case 3:
            if (func_8080451C_chcollballcontrol(param_0)) {
                func_8080324C_chcollballcontrol(param_0, 2);
            }

            _sukickball_entrypoint_14(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chcollballcontrol(param_0),
                func_80800040_chcollballcontrol(param_0));
            break;

        case 4:
            local_5 = D_808050A4_chcollballcontrol;

            if (*(f32 *)((char *)param_0 + 0x34) > 0.0f) {
                *(f32 *)((char *)param_0 + 0x34) -= local_2;
            } else {
                func_8080324C_chcollballcontrol(param_0, 5);
            }

            if (!_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                func_8080324C_chcollballcontrol(param_0, 1);
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
                func_8080324C_chcollballcontrol(param_0, 5);
            }

            func_8080486C_chcollballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chcollballcontrol(param_0),
                func_80800040_chcollballcontrol(param_0));
            break;

        case 5:
            func_80803E18_chcollballcontrol(param_0);
            func_80803F70_chcollballcontrol(param_0);
            func_8080324C_chcollballcontrol(param_0, 6);
            break;

        case 6:
            if (_sukickball_entrypoint_12(
                    local_1,
                    param_0->unk6C_0)) {
                func_80803F70_chcollballcontrol(param_0);
            } else {
                func_8080324C_chcollballcontrol(param_0, 2);
            }
            break;

        case 7:
            if (*(f32 *)((char *)param_0 + 0x34) > 0.0f) {
                *(f32 *)((char *)param_0 + 0x34) -= local_2;
            } else {
                func_8080324C_chcollballcontrol(param_0, 2);
            }

            func_8080486C_chcollballcontrol(param_0);

            _sukickball_entrypoint_2(param_0,
                func_8080009C_chcollballcontrol(param_0),
                func_80800040_chcollballcontrol(param_0));
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
                func_8080324C_chcollballcontrol(param_0, 2);
                *(f32 *)((char *)param_0 + 0x34) = 0.0f;
            }
            break;

    }

    if (_sukickball_entrypoint_5(param_0, local_0->local_2)) {
        if (param_0->unk70_10 == 8) {
            func_8080324C_chcollballcontrol(param_0, 2);
        } else if (!((CollballEnableTop50 *)param_0)->local_0) {
            func_808032CC_chcollballcontrol(param_0, 0);
        }
    } else {
        func_800EE7F8(
            local_0->local_2,
            param_0->position
        );
    }
}

s32 func_80803D54_chcollballcontrol(param_0, param_1) s32 param_0; s32 param_1;
{
    s32 local_0;

    local_0 = param_0;
    switch (param_1) {
    case 0:
        if (func_800DC298(0.1999969482f)) return 0;
        break;
    case 1:
        if (func_800DC298(0.2249908447f)) return 0;
        break;
    case 2:
        if (func_800DC298(0.3299865723f)) return 0;
        break;
    }
    while (local_0 == param_0) local_0 = func_800DC128(1, 4);
    return local_0;
}

void func_80803E18_chcollballcontrol(u8 *param_0) {
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = _sukickball_entrypoint_12(func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C)))), (*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF);
    switch (local_1) {                              
    case 2:
        _sukickball_entrypoint_4((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF, param_0 + 0x18);
        return;
    case 3:
        func_80803EF4_chcollballcontrol(param_0, func_80803D54_chcollballcontrol((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF, (*(u8 *)((s8 *)(local_0) + (0x14)))));
        return;
    case 1:
        _sukickball_entrypoint_4(func_80803D54_chcollballcontrol((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF, (*(u8 *)((s8 *)(local_0) + (0x14)))), param_0 + 0x18);
        
    case 0:
        return;
    }
}

void func_80803EF4_chcollballcontrol(param_0, param_1) s32 *param_0; s32 param_1;
{
    s32 local_0;

    local_0 = func_80106790(*(s32 *)((char *)param_0 + 0x3C));
    if (_sukickball_entrypoint_6(local_0, param_1) != 0) {
        func_800F5A00(param_1, (s32 *)((char *)param_0 + 0x18));
        return;
    }
    func_800EE7F8((s32 *)((char *)param_0 + 0x18), func_80106790(_sukickball_entrypoint_8(local_0, param_1))->position);
}

void func_80803F70_chcollballcontrol(Actor *param_0)
{
    if (_sukickball_entrypoint_12(func_80106790(param_0->unk3C), param_0->unk6C_0) == 2) {
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
        func_8080324C_chcollballcontrol(param_0, 2);
    }
}

void func_8080405C_chcollballcontrol(u8 *param_0)
{
    u8 *kick;
    u8 *other;
    s32 i;
    u8 *local_0;
    f32 spBC[3];
    f32 f20;
    f32 f24;
    f32 spA8[3];
    f32 sp9C[3];
    f32 sp90[3];
    f32 f22;
    f32 sp80[3];

    other = 0;
    kick = func_80106790(*(s32 *)(param_0 + 0x3C));
    local_0 = func_80100094(kick, 0);
    i = 0;
    if ((s32)*(u8 *)(local_0 + 0x3A) > 0) {
        do {
            if (i != (*(s32 *)(param_0 + 0x6C) & 0x1FF)) {
                if (_sukickball_entrypoint_7(kick, i) != 0) {
                    other = func_80106790(_sukickball_entrypoint_8(kick, i));
                    spBC[0] = *(f32 *)(other + 4);
                    spBC[1] = *(f32 *)(other + 8);
                    spBC[2] = *(f32 *)(other + 0xC);
                } else {
                    func_800F5A00(i, spBC);
                }
                if (func_800EFFB4(((f32 *)(param_0 + 4)), 90.0f, spBC) != 0) {
                    f22 = func_800EEF94((f32 *)(param_0 + 0x28));
                    if (_sukickball_entrypoint_6(kick, i) != 0) {
                        func_800F5D70(i, spA8);
                        f20 = func_800EEF94(spA8);
                        f24 = func_800D8FF8() * f20;
                    } else {
                        f20 = func_800EEF94((f32 *)(other + 0x28));
                        f24 = func_800D8FF8() * f20;
                    }
                    if (f24 <= f22) {
                        if (_sukickball_entrypoint_6(kick, i) != 0) {
                            _sukickball_entrypoint_13(((f32 *)(param_0 + 4)), spBC, 60.0f);
                            func_800F8294(i, spBC);
                            if (((u32)*(u16 *)(param_0 + 0x72) >> 10) == 8) {
                                *(W3 *)sp9C = *(W3 *)&D_808050B4_chcollballcontrol;
                                func_800F5A00(i, sp90);
                                func_800EEB9C(sp9C, func_80102D78(param_0, sp90), 150.0f);
                                func_800EF04C(sp9C, sp90);
                                func_800F7700(i, 3, ((f32 *)(param_0 + 4)));
                            }
                        } else {
                            _sukickball_entrypoint_13(((f32 *)(param_0 + 4)), ((f32 *)(other + 4)), 60.0f);
                            if (((u32)*(u16 *)(param_0 + 0x72) >> 10) == 8) {
                                *(f32 *)(other + 0x58) = 1.5f;
                                ((BitS101 *)other)->b4 = 1;
                                func_8080324C_chcollballcontrol(other, 0xC);
                                *(f32 *)(other + 0x24) = *(f32 *)(param_0 + 0x24) * 0.75f;
                                *(f32 *)(other + 0x54) = func_80102D78(param_0, ((f32 *)(other + 4)));
                                *(f32 *)(param_0 + 0x24) = *(f32 *)(param_0 + 0x24) * 0.5f;
                            }
                        }
                    } else {
                        _sukickball_entrypoint_13(spBC, ((f32 *)(param_0 + 4)), 60.0f);
                        if (func_800DC0C0() < 0.5f && _sukickball_entrypoint_12(kick, *(s32 *)(param_0 + 0x6C) & 0x1FF) == 0) {
                            func_808032CC_chcollballcontrol(param_0, spBC);
                        }
                        if (_sukickball_entrypoint_6(kick, i) != 0 && func_800F52B8(i, *(s32 *)param_0) == 2) {
                            func_800F5A00(i, sp80);
                            *(f32 *)(param_0 + 0x54) = func_800F1DF4(sp80, ((f32 *)(param_0 + 4)));
                            func_8080324C_chcollballcontrol(param_0, 0xC);
                            *(f32 *)(param_0 + 0x24) = (f24 * 0.75f) / func_800D8FF8();
                        }
                        *(f32 *)(param_0 + 0x58) = 1.5f;
                        ((BitS101 *)param_0)->b4 = 1;
                    }
                }
            }
            i++;
        } while (i < (s32)*(u8 *)(local_0 + 0x3A));
    }
}

void func_80804420_chcollballcontrol(Actor *param_0)
{
    CollisionBallState *local_0;

    local_0 = func_80100094(param_0, 0);
    ((CollisionBallPlayerFlags *)param_0)->local_0 = 1;
    param_0->scale = 0.5f;
    func_8010A590(param_0);
    local_0->local_1 = _sukickball_entrypoint_3();
    if (local_0->local_1 == 4 && param_0->unk6C_0 < (u32)_gcstatusDll_entrypoint_11()) {
        ((CollisionBallPlayerFlags *)param_0)->local_1 = 1;
        ((CollisionBallPlayerFlags *)param_0)->local_2 = param_0->unk6C_0;
    }
    local_0->local_0 = func_800BD0DC(2);
    func_800BD268(local_0->local_0, param_0->unk6C_0);
    func_800BD28C(local_0->local_0, 2);
}

void func_808044F4_chcollballcontrol(s32 param_0) {
    func_800BD09C(*(s32 *)func_80100094(param_0, 0));
}

Actor *func_8080451C_chcollballcontrol(param_0) Actor *param_0;
{
    Actor *local_1;
    f32 local_0;
    Actor *local_2;
    f32 local_3;
    f32 local_4;

    local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x1A1, -1, &local_0);
    if (local_1 == NULL) {
        local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x1A2, -1, &local_0);
        if (local_1 == NULL) {
            local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x1A3, -1, &local_0);
            if (local_1 == NULL) {
                return NULL;
            }
        }
    } else if ((local_1->unk70_10 == 2 && !func_800F0064(param_0->position, 100.0f, local_1->position)) ||
               local_1->unk70_10 == 6 || local_1->unk70_10 == 4 || local_1->unk70_10 == 3) {
        switch (local_1->unk70_10) {
        case 2:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x1A1, 2, &local_0);
            break;
        case 3:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x1A1, 3, &local_0);
            break;
        case 6:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x1A1, 6, &local_0);
            break;
        case 4:
            local_2 = _subaddiefind_entrypoint_0(param_0->position, 0x1A1, 4, &local_0);
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
                func_8080324C_chcollballcontrol(param_0, 8);
            }
        }
        func_800EFCD8((f32 *)param_0->actorData, local_3, local_4);
        func_800EF04C((f32 *)param_0->actorData, local_1->position);
    } else {
        func_800EE7F8((f32 *)param_0->actorData, local_1->position);
    }
    return local_1;
}

void func_8080486C_chcollballcontrol(Actor *param_0)
{
    BallMotionVector_8080486C_chcollballcontrol local_0 = *(BallMotionVector_8080486C_chcollballcontrol *)D_808050C0_chcollballcontrol;
    Actor *local_1;

    local_1 = func_80106790(param_0->unk3C);
    if (param_0->unk70_10 != 10) {
        param_0->unk54 = func_80102D78(param_0, (f32 *)param_0->actorData);
        if (!func_80102CF4(param_0, 240.0f)) {
            func_80804AA8_chcollballcontrol(param_0);
        } else {
            func_80804A48_chcollballcontrol(param_0);
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
        func_80800070_chcollballcontrol(param_0) < ((f32 *)param_0->actorData)[3]) {
        ((f32 *)param_0->actorData)[3] = func_80800070_chcollballcontrol(param_0);
    }
    func_800EFCD8((f32 *)&param_0->actorData[4], param_0->rotation[1],
        ((f32 *)param_0->actorData)[3] * func_800D8FF8());
    func_800EF04C(param_0->position, (f32 *)&param_0->actorData[4]);
    func_8080405C_chcollballcontrol(param_0);
    param_0->rotation[1] = func_800136E4(param_0->rotation[1]);
}

void func_80804A48_chcollballcontrol(param_0) Actor *param_0;
{
    if (((f32 *)param_0->actorData)[3] < func_80800040_chcollballcontrol(param_0)) {
        ((f32 *)param_0->actorData)[3] += func_808000C8_chcollballcontrol(param_0);
    } else {
        ((f32 *)param_0->actorData)[3] = func_80800040_chcollballcontrol(param_0);
    }
}

void func_80804AA8_chcollballcontrol(param_0) u8 *param_0; {
    if (func_8080009C_chcollballcontrol(param_0) < *(f32 *)(param_0 + 0x24)) {
        *(f32 *)(param_0 + 0x24) -= func_808000F4_chcollballcontrol(param_0);
    }
}

int chcollballcontrol_entrypoint_5()
{
    extern void *D_808050CC_chcollballcontrol;
    return (int)&D_808050CC_chcollballcontrol;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/collballcontrol.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80804C64_chcollballcontrol -> s32[], D_80804E4C_chcollballcontrol -> s32[], D_80804F58_chcollballcontrol -> int[], D_80804FE8_chcollballcontrol -> int[], D_808050B4_chcollballcontrol -> s32[] */
extern void _sukickball_entrypoint_0();
extern void _sukickball_entrypoint_1();
u32 D_80804C50_chcollballcontrol[5] = { 0x1304B1, 0xA00A6, 0x164E20, 0x101F4, 0x13880000 };
s32 D_80804C64_chcollballcontrol[4] = { 0x130413, 0x180001, 0x1F41388, 0x0 };
u8 D_80804C74_chcollballcontrol[16] = { 0x0, 0x13, 0x4, 0xF4, 0x0, 0x16, 0x4E, 0x20, 0x0, 0x1, 0x1, 0xF4, 0x13, 0x88, 0x0, 0x0 };
u8 D_80804C84_chcollballcontrol[20] = { 0x0, 0x13, 0x4, 0x82, 0x0, 0xA, 0x1, 0x0, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x1, 0x1, 0xF4, 0x13, 0x88, 0x0, 0x0 };
u8 D_80804C98_chcollballcontrol[28] = { 0x0, 0x13, 0x5, 0x3C, 0x0, 0xA, 0x1, 0x0, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x2, 0x0, 0x1, 0x1, 0xF4, 0x13, 0x88, 0x0, 0x0, 0x0, 0x0 };
f32 D_80804CB4_chcollballcontrol[5] = { 1.5e+02f, 225.0f, 3e+02f, 0.0f, 4e+02f };
f32 D_80804CC8_chcollballcontrol[5][2] = { 1.0f, 0.0f, 0.75f, 1.0f, 0.75f, 0.75f, 0.3333f, 0.6666f, 0.3333f, 0.6666f };
s32 D_80804CF0_chcollballcontrol[5][6] = { 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x1, 0x0, 0x1, 0x0, 0x5, 0x1, 0x1, 0x0, 0x1, 0x1, 0x4, 0x0, 0x0, 0x2, 0x0, 0x0, 0x5, 0x1, 0x0, 0x1, 0x0, 0x1 };
s32 D_80804D68_chcollballcontrol[5] = { 0x2D, 0x2D, 0x2D, 0x0, 0x3C };
s32 D_80804D7C_chcollballcontrol[5] = { 0x4, 0x4, 0x4, 0x1, 0x4 };
CollballCountRecord D_80804D90_chcollballcontrol = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
void *D_80804DA8_chcollballcontrol = (void *)0x003F019E;
static u32 D_80804DA8_chcollballcontrol_rest[17] = { 0x6370001, 0x0, (u32)func_808006FC_chcollballcontrol, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x80004, (u32)func_80801038_chcollballcontrol, 0x0, 0x400000, (u32)func_80800DD8_chcollballcontrol, (u32)func_80107C2C, 0x80000202, (u32)func_808002B8_chcollballcontrol, 0x0 };
s32 D_80804DF0_chcollballcontrol = -0x38;
u8 D_80804DF4_chcollballcontrol[20] = { 0xFF, 0xFF, 0xFF, 0xC8, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xC8 };
s32 D_80804E08_chcollballcontrol[17] = { 0xA10000A, -0x320000, -0x31FFCE, 0x320032, 0x2CFF83, 0x4BFF83, 0x7D0096, 0x7D001B, -0xF9015E, 0x27FD30, -0x2CFFD30, 0x2D00022, 0x1000180, 0x800100, 0x2A0080, 0x1000300, 0x4000000 };
s32 D_80804E4C_chcollballcontrol[18] = { 0x1D09E2, 0x1BFF06, -0xF9FFEB, 0x6600CC, 0x220040, 0x4C0007, 0x70027, 0xC8, 0xF0, 0x161000, 0xC000F, 0x2C0000, 0x640000, 0xFA, 0x2A, 0x800100, 0x3000400, 0x0 };
u32 D_80804E94_chcollballcontrol[20] = { 0x1D0678, 0x150066, 0xCC000A, 0xFFFB0000, 0xFFFB0005, 0x5, 0x2CFF06, 0x64FF06, 0x12C00FA, 0x12C001B, 0xFF6AFED4, 0x220080, 0x800100, 0x3000027, 0xFD30FD30, 0x2D002D0, 0x161000, 0x2A0080, 0x1000300, 0x4000000 };
u32 D_80804EE4_chcollballcontrol[18] = { 0x1D09DC, 0x190001, 0x62302, 0xAFFFB, 0x19FFF1, 0x50032, 0xF002C, 0x60, 0x0, 0xD80000, 0x22010A, 0x3000200, 0x500002A, 0x2, 0x4000700, 0x15004C, 0xB30016, 0x40000 };
void *D_80804F2C_chcollballcontrol[4] = { 0, (void *)0x00000002, (void *)0x00000001, (void *)0x00000003 };
CollballDistancesC010 D_80804F3C_chcollballcontrol = { 1e+07f, 1e+07f, 1e+07f, 1e+07f };
BallMotionVector_80802CE0_chcollballcontrol D_80804F4C_chcollballcontrol = { 0.0f, 0.0f, 0.0f };
int D_80804F58_chcollballcontrol[18] = { 0x4401A1, 0x6700005, 0x0, (u32)func_80801A20_chcollballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x0, 0x0, 0x0, 0x4, (u32)func_80803208_chcollballcontrol, 0x0, 0x240000, (u32)func_80801964_chcollballcontrol, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
s32 D_80804FA0_chcollballcontrol[18] = { 0x4201A3, 0x6770005, 0x0, (u32)func_80801A20_chcollballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x0, 0x0, 0x0, 0x6, (u32)func_80803208_chcollballcontrol, 0x0, 0x240000, (u32)func_80801964_chcollballcontrol, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
int D_80804FE8_chcollballcontrol[18] = { 0x4301A2, 0x6720005, 0x0, (u32)func_80801A20_chcollballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x0, 0x0, 0x0, 0x4, (u32)func_80803208_chcollballcontrol, 0x0, 0x240000, (u32)func_80801964_chcollballcontrol, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
u32 D_80805030_chcollballcontrol[26] = { 0x0, 0x0, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F99999A, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1D70001, 0x3F800000, 0x1EB0002, 0x4B189680, 0x1D70001, 0x3F800000, 0x1D70001, 0x40000000, 0x1D70001, 0x4B189680, 0x1D70001 };
BallMotionVector_808032CC_chcollballcontrol D_80805098_chcollballcontrol = { 0.0f, 0.0f, 0.0f };
Vec3f D_808050A4_chcollballcontrol = { 0.0f, 0.0f, 0.0f };
u8 D_808050B0_chcollballcontrol[4] = { 0xFF, 0xFF, 0xFF, 0xC8 };
s32 D_808050B4_chcollballcontrol[3] = { 0x0, 0x0, 0x0 };
u8 D_808050C0_chcollballcontrol[12] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
void *D_808050CC_chcollballcontrol = (void *)0x0040019F;
static u32 D_808050CC_chcollballcontrol_rest[20] = { 0x66A000B, (u32)&D_80805030_chcollballcontrol, (u32)func_80803484_chcollballcontrol, (u32)func_80105834, (u32)_sukickball_entrypoint_1, 0x0, 0x0, 0x0, 0x4, (u32)func_808044F4_chcollballcontrol, 0x0, 0x180000, (u32)func_80804420_chcollballcontrol, (u32)func_80107C2C, 0x80000003, (u32)func_80803420_chcollballcontrol, 0x0, 0x0, 0x0, 0x0 };
