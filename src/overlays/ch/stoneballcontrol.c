// Probably Mayan Kickball in Mayahem Temple, built on su/kickball: the match controller, the
// three kinds of ball actors, and the stony kickers that chase and kick balls into goals.
#include "common.h"

extern s32 func_800EA05C(void);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800BBCB8(Actor *, int, float, int, void (*)(void));
extern f32 D_80804FFC_chstoneballcontrol[];
extern void *func_80100094(Actor *, u32);
extern int D_80805038_chstoneballcontrol[][4];
extern s32 D_80805088_chstoneballcontrol[];
typedef struct {
    u8 pad_0[0x39];
    u8 local_0;
} StoneBallController;
typedef struct {
    u8 pad_0[0x72];
    u8 local_0 : 6;
    u8 pad_1 : 2;
} StoneBallState;
typedef struct {
    u8 pad_0[0x20];
    s32 local_0[4];
    u8 local_1[4];
    u8 local_2[4];
    u8 pad_1;
    u8 local_3;
    u8 local_4;
    u8 local_5;
    u8 local_6;
} StoneballScoreState;
typedef struct {
    u8 local_0[0x64];
    u32 local_1 : 2;
    u32 local_2 : 1;
    u32 local_3 : 29;
} local_struct;
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
typedef struct {
    u8 pad[0x10];
    s32 a[9];
    u8 b[6];
    u8 count;
} StoneS;
typedef struct {
    u8 pad_0[0xA];
    u8 local_0[6];
    Unk80132ED0 *local_1[4];
    u8 pad_1[0x14];
    u8 local_2[4];
} StoneBallStart1773;
extern f32 _sukickball_entrypoint_15(s32);
extern void _sukickball_entrypoint_16(s32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct Mass45StoneCounts {
    s32 local_0[4];
} Mass45StoneCounts;
extern s32 D_808050BC_chstoneballcontrol[];
typedef struct StoneBallTypes {
    s32 local_0[2];
} StoneBallTypes;
extern StoneBallTypes D_808050CC_chstoneballcontrol;
typedef struct {
    u8 pad_0[0xA];
    u8 local_0[4];
    u8 pad_1[2];
    Unk80132ED0 *local_1[4];
} StoneBallPlayers1472;
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
typedef struct {
    Unk80132ED0 *local_0;
    s32 local_1;
    u32 local_2;
} StoneballSpatialEntry;
typedef struct {
    u8 pad_0[0x24];
    u32 local_0 : 10;
    u32 pad_1 : 22;
} StoneballMarkerC010;
extern s32 *func_800BE3F8(f32 *);
extern void *func_800E9E88(s32);
extern void *func_800E9EB4(s32);
typedef struct {
    u8 pad_0[0x1C];
    f32 local_0;
} StoneBallContact1472;
extern s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
extern void func_800C4140(s32, f32 *, s32);
extern s32 D_808052A0_chstoneballcontrol[];
extern f32 func_800D8FF8(void);
extern f32 func_800F5F24(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int D_808052CC_chstoneballcontrol[];
extern s32 D_80805314_chstoneballcontrol[];
extern int D_8080535C_chstoneballcontrol[];
typedef union {
    s32 local_0;
    void *local_1;
} StoneballControlEvent;
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct {
    u8 pad[0x65];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS101;
typedef struct {
    s32 a, b, c;
} W3;
extern u32 D_8080541C_chstoneballcontrol[3];
extern f32 func_800EEF94(void *);
extern void func_800F5D70(s32, f32 *);
extern void func_800F8294(s32, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800F7700(s32, s32, void *);
extern s32 _sukickball_entrypoint_12(void *, s32);
extern s32 func_800F52B8(s32, s32);
extern f32 func_800F1DF4(f32 *, void *);
typedef struct {
    u8 pad_0[0x64];
    u32 local_0 : 1;
    u32 pad_1 : 1;
    u32 local_1 : 1;
    u32 local_2 : 2;
    u32 pad_2 : 27;
} StoneBallFlags31;
typedef struct Mass45StoneVector_80804B60_chstoneballcontrol {
    f32 local_0[3];
} Mass45StoneVector_80804B60_chstoneballcontrol;
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
typedef struct {
    f32 unk0;
    u8 pad_4[0x1C];
    u8 unk20;
} BallControlLocal;
typedef struct {
    f32 local_0[4];
} StoneballDistancesC010;
typedef struct {
    f32 local_0[3];
} Mass45StoneVector_80803148_chstoneballcontrol;
typedef struct {
    f32 local_0;
    u8 pad_0[0x1C];
    u8 local_1;
} StoneballStateC010;
typedef struct {
    u8 pad_0[0x3A];
    u8 local_0;
} StoneballPlayersC010;
extern StoneballDistancesC010 D_808052B0_chstoneballcontrol;
extern Mass45StoneVector_80803148_chstoneballcontrol D_808052C0_chstoneballcontrol;
extern u8 _chstoneballcontrol_entrypoint_1[];
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    s32 local_0;
    f32 local_1;
    f32 local_2[3];
} StoneballDataTop50;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} StoneballEnableTop50;
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
void func_80802418_chstoneballcontrol();
s32 func_808026A0_chstoneballcontrol();
void func_8080282C_chstoneballcontrol();
void func_80802F14_chstoneballcontrol();
void func_80803148_chstoneballcontrol();
Actor *func_80804810_chstoneballcontrol();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_8080079C_chstoneballcontrol(),
    func_80800F9C_chstoneballcontrol();

// Match controller: round tables, ball spawning, team setup, intro text, scoring, round end.
int func_80800000_chstoneballcontrol(s32 param_0[4], s32 param_1, s32 param_2)
{
    u32 local_0;
    u32 local_1;
    local_0 = param_0[0];
    local_1 = param_2 | 0xE;
    return _subaddiedialog_entrypoint_11(local_0, param_1, local_1, param_0 + 1, 0x33);
}

// Stony team members: speed by difficulty, AI chase and kick, controller mode, knock-back, spin.
f32 func_80800040_chstoneballcontrol(Actor *param_0)
{
    return D_80804FFC_chstoneballcontrol[((u8 *) func_80100094(param_0, 0))[0x14]];
}

f32 func_80800070_chstoneballcontrol(Actor *param_0)
{
    return func_80800040_chstoneballcontrol(param_0) * 0.75f;
}

f32 func_8080009C_chstoneballcontrol(param_0)
Actor *param_0;
{
    return func_80800040_chstoneballcontrol(param_0) * 0.33f;
}

f32 func_808000C8_chstoneballcontrol(Actor *);

f32 func_808000C8_chstoneballcontrol(param_0)
Actor *param_0;
{
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
    StoneBallController *controller;

    controller = func_80100094(param_0, 0);
    _sukickball_entrypoint_17(param_0);

    if (!func_800DA298(0x6AD) && param_0->unk79_4 != 1 && !param_0->unk64_20) {
        if (param_0->unk79_4 == 2)
            _capod_entrypoint_14();
        switch (controller->local_0) {
            case 0:
            case 1:
            case 2:
                func_800A54F8(0);
        }
        func_80800000_chstoneballcontrol(param_0, 0xF1C, 0);
        ((StoneBallState *) param_0)->local_0 = 3;
    }
}

void func_80800210_chstoneballcontrol(s32 *param_0, s32 ball_kind)
{
    u8 *ball;

    // Matching: empty block steers IDO's code generation.
    if (1) {
    }
    switch (ball_kind) {
        case 1:
        case 6:
            ball = func_801084B0(0x155, &param_0);
            break;
        case 3:
            ball = func_801084B0(0x1B8, &param_0);
            break;
        case 2:
            ball = func_801084B0(0x29E, &param_0);
    }

    if (func_800EA05C() != 0xBB) {
        *(f32 *) (ball + 4) = func_800DC178(-470.0f, 470.0f);
        *(f32 *) (ball + 0xC) = func_800DC178(-470.0f, 470.0f);
    } else if (ball_kind != 6) {
        *(f32 *) (ball + 4) = func_800DC178(-2850.0f, -1350.0f);
        *(f32 *) (ball + 0xC) = func_800DC178(-1350.0f, -650.0f);
    } else {
        *(f32 *) (ball + 4) = -2100.0f;
        *(f32 *) (ball + 0xC) = -1000.0f;
    }
    *(s32 *) (ball + 0x3C) = param_0[0];
}

s32 func_80800360_chstoneballcontrol(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    f32 local_1;
    s16 *local_4;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_4 = (s16 *) &param_2;
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
            }

            if (_capod_entrypoint_17(local_1)) {
                _subaddiedialog_entrypoint_11(
                    param_0->unk0, local_0[0x39] + 0xF3E, 6,
                    (f32 *) ((u8 *) func_80106790(
                                 _sukickball_entrypoint_8(param_0, local_0[0x39] + 1)) +
                             4),
                    0);
                param_0->unk64_20 = 1;
            }

            return 3;

        case 0x2E:
            switch (local_4[0]) {
                case 0xF4D:
                case 0xF4E:
                    if (func_800D2054(0, local_0[0x39] + 0x8E, *(s32 *) (local_0 + 0x20)) == 1) {
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
                    func_800CE8D8(0, local_2,
                                  (s32) (f32) func_80800130_chstoneballcontrol(local_0[0x39]));
                    func_800CE88C(0, 1);
                    func_80801734_chstoneballcontrol(param_0, 0);
                    param_0->unk70_10 = 4;
                    break;
                case 0xF3E:
                case 0xF3F:
                case 0xF40:
                    param_0->unk64_20 = 0;
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
                case 3:
                    break;
                case 4:
                    _subaddiemulti_entrypoint_4(0);
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
    *(f32 *) (local_0 + 0) -= local_1;
    *(f32 *) (local_0 + 4) -= local_1;
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

            if (func_800CEAD0(0))
                func_80800908_chstoneballcontrol(param_0);
            return;
        case 7:
            func_8080145C_chstoneballcontrol(param_0);
            return;
        case 8:
            _sukickball_entrypoint_19(param_0, 1, local_0[0x3A]);
            if (param_0->unk58 > 0.0f)
                param_0->unk58 -= func_800D8FF8();
            else
                _gcgoto_entrypoint_1(0xBB, 4);
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
            }
        }
    } else {
        for (local_5 = 0; local_5 < local_0->local_4; local_5++) {
            if (local_1[local_5] == 1)
                local_0->local_1[local_5] = 1;
            else
                local_0->local_1[local_5] = 0;
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
    switch ((u32) *(u16 *) ((u8 *) param_0 + 0x72) >> 10) {
        case 2:
            if (((local_struct *) param_0)->local_2) {
                *(u8 *) ((u8 *) param_0 + 0x72) = (*(u8 *) ((u8 *) param_0 + 0x72) & 0xFF03) | 0x28;
                *(f32 *) ((u8 *) param_0 + 0x58) = 0.0f;
            }
            break;
        case 8:
            *(f32 *) ((u8 *) param_0 + 0x50) = 0.0f;
    }
}

void func_80800BCC_chstoneballcontrol(Actor *param_0, f32 *target)
{
    Vec3f offset = D_808050B0_chstoneballcontrol;
    f32 angle;
    f32 target_angle;

    if (!target)
        angle = param_0->rotation[1] + func_800DC178(110.0f, 250.0f);
    else {
        target_angle = func_80102D78(param_0, target);
        angle = func_800DC178(110.0f, 250.0f) + target_angle;
    }
    func_800EFCD8(offset.f, angle, 500.0f);
    func_800EE780(param_0->actorData, param_0->position, offset.f);
    *(f32 *) &param_0->actorData[3] = func_8080009C_chstoneballcontrol(param_0);
    if (*(f32 *) &param_0->actorData[0] > 720.0f)
        *(f32 *) &param_0->actorData[0] = 720.0f;
    if (*(f32 *) &param_0->actorData[2] > 720.0f)
        *(f32 *) &param_0->actorData[2] = 720.0f;
    if (*(f32 *) &param_0->actorData[0] < -720.0f)
        *(f32 *) &param_0->actorData[0] = -720.0f;
    if (*(f32 *) &param_0->actorData[2] < -720.0f)
        *(f32 *) &param_0->actorData[2] = -720.0f;
    *(f32 *) &param_0->actorData[7] = func_800DC178(0.25f, 1.0f);
    func_80800B4C_chstoneballcontrol(param_0, 7);
}

void func_80800D20_chstoneballcontrol(param_0) Actor *param_0;
{
    *(f32 *) &param_0->actorData[3] = func_8080009C_chstoneballcontrol(param_0);
    *(f32 *) &param_0->actorData[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        *(f32 *) &param_0->actorData[7] = -*(f32 *) &param_0->actorData[7];
    }
    func_80800B4C_chstoneballcontrol(param_0, 9);
    param_0->unk64_20 = 1;
}

// Kickball actors (three kinds): spawn, physics, kicked or scored, burst effects.
void func_80800DB4_chstoneballcontrol(Actor *param_0, f32 *center)
{
    u8 *state;
    Actor *kicker;
    f32 pos[3];
    s32 i;

    state = func_80100094(param_0, 0);
    for (i = 0; i < state[0x3A]; i++) {
        if (_sukickball_entrypoint_6(param_0, i)) {
            func_800F5A00(i, pos);

            if (func_800F0064(pos, 200.0f, center)) {
                func_800F7B9C(i, 0x38);
            }

        } else {
            kicker = func_80106790(_sukickball_entrypoint_8(param_0, i));

            if (func_800F0064(kicker->position, 200.0f, center)) {
                func_80800D20_chstoneballcontrol(kicker);
            }
        }
    }
}

int func_80800EBC_chstoneballcontrol(Actor *param_0, s32 param_1)
{
    switch (param_1) {
        case 0:
            func_800F82D4(param_0, 0);
            break;

        case 1:
            func_800F82D4(param_0, 2);
            _baattach_entrypoint_6(func_800F53D0(param_0) | 0, 3, 0, 0);
    }
}

void func_80800F24_chstoneballcontrol(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1 || func_800D395C()) {
        *((u8 *) (((char *) param_0) + 0x65)) =
            ((*((u8 *) (((char *) param_0) + 0x65))) & 0xFFFFu) | 8;
        _chintrotext_entrypoint_1(0x18AF, param_2 + (0xF ^ 0), 0, 0);
    } else {
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
    Actor *local_4;

    local_1 = func_80100094(param_0, 0);
    local_1[0x39] = _sukickball_entrypoint_3();
    local_1[0x3C] = 0;
    if (func_800DA298(0x667) || !func_80090178(0x80)) {
        func_800FFAB0(param_0);
        return;
    }
    if (func_800EA05C() != 0xBB)
        func_800DA3B8(0x65A, 1);
    local_1[0x3A] = ((s32 *) D_8080509C_chstoneballcontrol)[local_1[0x39]];
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
        case 3:
            break;
        case 4:
            local_0 = 0;
            do {
                if (func_800F6438(local_0))
                    func_800F4CEC(local_0, 0);
                local_0++;
            } while (local_0 != 8);
            local_1[0x3A] = _gcstatusDll_entrypoint_11();
    }
    func_8080128C_chstoneballcontrol(param_0);
    if (local_1[0x39] == 4)
        local_1[0xA] = 1;
    else
        local_1[0xA] = 2;
    local_1[0xB] = 1;
    local_1[0xC] = 1;
    local_1[0xD] = 1;
    for (local_0 = 0; local_0 < local_1[0x3A]; local_0++) {
        switch (local_1[local_0 + 0xA]) {
            case 1:
                local_4 = func_801084B0(0x1B6, &param_0);
                ((u32 *) (local_1 + 0x10))[local_0] = *(u32 *) local_4;
                *(u32 *) ((u8 *) local_4 + 0x3C) = *(u32 *) param_0;
            case 2:
                break;
        }
        func_80801330_chstoneballcontrol(param_0, local_0);
    }
    if (func_800EA05C() == 0xBB) {
        func_8080145C_chstoneballcontrol(param_0);
        *((u8 *) param_0 + 0x72) = (*((u8 *) param_0 + 0x72) & 0xFF03) | 0x1C;
    }
    _sukickball_entrypoint_18(param_0);
    local_1[0x3C] = 1;
}

int func_8080120C_chstoneballcontrol(param_0)
s32 param_0;
{
    Actor *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (*(u8 *) ((char *) local_0 + 0x3C) != 0) {
        func_800DA3B8(0x65A, 0);
        if (*(u8 *) ((char *) local_0 + 0x39) == 4) {
            for (local_1 = 0; local_1 < 8; local_1++) {
                if (func_800F6438(local_1)) {
                    func_800F4CC0(local_1);
                }
            }
        }
    }
}

void func_8080128C_chstoneballcontrol(s32 param_0)
{
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

int func_80801320_chstoneballcontrol(Actor *param_0)
{
    return (*(s32 *) ((char *) (param_0) + 0x6C)) & 0x1FF;
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
            func_800EE7F8((f32 *) (local_2 + 8), local_1->position);
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
    }
    local_0->local_2[param_1] = 0;
}

int func_8080145C_chstoneballcontrol(Actor *param_0)
{
    u8 *local_0;
    Mass45StoneCounts local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = *(Mass45StoneCounts *) D_808050BC_chstoneballcontrol;
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

void func_80801638_chstoneballcontrol(param_0, param_1) Actor *param_0;
s32 *param_1;
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
        }
    }
    param_1[0] = param_1[1] + param_1[2] + param_1[3];
}

void func_80801734_chstoneballcontrol(param_0, param_1) s32 param_0;
s32 param_1;
{
    s32 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if ((s32) *(u8 *) ((char *) local_0 + 0x3A) > 0) {
        do {
            func_80801808_chstoneballcontrol(param_0, local_1, param_1);
            local_1 += 1;
        } while (local_1 < (s32) *(u8 *) ((char *) local_0 + 0x3A));
    }
}

void func_808017AC_chstoneballcontrol(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    switch (param_1) {
        case 0:
            func_80800B4C_chstoneballcontrol(local_0, 2);
            break;

        case 1:
            func_80800B4C_chstoneballcontrol(local_0, 0xB);
    }
}

void func_80801808_chstoneballcontrol(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
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
            if (_sukickball_entrypoint_6(func_80106790(param_0->unk3C), local_0[0x20]))
                func_800F4F98(local_0[0x20], param_0->unk0);
            _sukickball_entrypoint_11(func_80106790(param_0->unk3C), local_0[0x20]);
        }
    }
    if (param_0->unk70_10 == 3 && param_1 == 2 && (param_0->unk0->unk24 >> 22) == 0x253) {
        *(f32 *) (local_0 + 0x14) = 20.0f;
        *(f32 *) (local_0 + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(param_0);
        func_808024F8_chstoneballcontrol(param_0);
        param_1 = 4;
    }
    func_80101FDC(param_0, param_1);
    if (param_0->unk70_10 == 6) {
        func_808024F8_chstoneballcontrol(param_0);
        _subaddiefade_entrypoint_3(param_0);
        func_800B4470(param_0->position, 0, &D_8080511C_chstoneballcontrol, 1, 0.75f, 0.0f, 125,
                      250, 0);
        switch (param_0->unk0->unk24 >> 22) {
            case 0x267:
                func_80802588_chstoneballcontrol(param_0, 1);
                break;
            case 0x254:
                func_80802588_chstoneballcontrol(param_0, 2);
                break;
        }
    }
}

int func_80801B00_chstoneballcontrol(Actor *param_0)
{
    void *local_0;
    local_0 = func_80100094(param_0, 0 * 0);
    *(u8 *) ((char *) local_0 + 0x20) = 0x7F;
    *(float *) ((char *) local_0 + 4) = 0.0f;
    *(float *) ((char *) local_0 + 0) = .0f;
    *(float *) ((char *) param_0 + 0x24) = 0.0f;
}

void func_80801B44_chstoneballcontrol(Actor *param_0)
{
    param_0->unk74_17 = 0;
    func_8010A590(param_0);
    *(f32 *) ((u8 *) param_0 + 0x38) = 1.5f;
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

    local_0 = (char *) func_80100094(param_0, 0);
    local_1 = func_80106790(*(void **) ((char *) param_0 + 0x3C));

    if (!func_80090178(0x80)) {
        func_8008FB58(param_0->position, 0.0f, 25.0f);
    }

    switch (param_0->unk70_10) {
        case 5:
            if (func_800EA05C() != 0xBB) {
                if (param_0->position[1] < 25.0f) {
                    param_0->position[1] += 5.0f;
                }

                if ((f32) (u32) param_0->alpha < 240.0f) {
                    *(u8 *) ((char *) param_0 + 0x9B) = (u32) ((f32) (u32) param_0->alpha + 15.0f);
                    break;
                }

                if (25.0f <= param_0->position[1]) {
                    param_0->unk70_10 = 1;
                    *(u8 *) ((char *) param_0 + 0x9B) = 0xFF;
                }

            } else {
                if (param_0->position[1] < -325.0f) {
                    param_0->position[1] += 5.0f;
                }

                if ((f32) (u32) param_0->alpha < 240.0f) {
                    *(u8 *) ((char *) param_0 + 0x9B) = (u32) ((f32) (u32) param_0->alpha + 15.0f);
                    break;
                }

                if (-325.0f <= param_0->position[1]) {
                    param_0->unk70_10 = 1;
                    *(u8 *) ((char *) param_0 + 0x9B) = 0xFF;
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

            if (_sukickball_entrypoint_6(local_1, *(u8 *) (local_0 + 0x20))) {
                func_800F5A00(*(u8 *) (local_0 + 0x20), local_4);

                *(f32 *) ((char *) param_0 + 0x54) = func_800F5F24(*(u8 *) (local_0 + 0x20));

                *(f32 *) ((char *) param_0 + 8) = 0.0f;

                func_800EFCD8(param_0->position, *(f32 *) ((char *) param_0 + 0x54), 60.0f);

                func_800EF04C(param_0->position, local_4);

                func_800F5D70(*(u8 *) (local_0 + 0x20), local_5);

                *(f32 *) ((char *) param_0 + 0x50) =
                    (local_5[0] * local_5[0]) + (local_5[2] * local_5[2]);

                func_800EE7F8((char *) param_0 + 0x18, local_4);
            } else {
                local_2 =
                    func_80106790(_sukickball_entrypoint_8(local_1, *(u8 *) (local_0 + 0x20)));

                *(f32 *) ((char *) param_0 + 8) = 0.0f;

                func_800EFCD8((char *) param_0 + 4, local_2->rotation[1], 60.0f);

                func_800EF04C((char *) param_0 + 4, local_2->position);

                *(f32 *) ((char *) param_0 + 0x54) = local_2->rotation[1];

                *(f32 *) ((char *) param_0 + 0x50) =
                    *(f32 *) &local_2->actorData[3] * *(f32 *) &local_2->actorData[3];

                func_800EE7F8((char *) param_0 + 0x18, local_2->position);
            }

            if (func_800EFBFC(local_3, (char *) param_0 + 4) > 25.0f) {
                if (func_800DC0C0() < 0.1f) {
                    func_800B4470(local_3, 0, D_80805120_chstoneballcontrol, 1, 0.75f, 0.0f, 75,
                                  150, 0);
                }
            }

            func_800D9078(local_0);
            func_80803148_chstoneballcontrol(param_0);

            if (_sukickball_entrypoint_7(local_1, *(u8 *) (local_0 + 0x20))) {
                local_10 =
                    func_80106790(_sukickball_entrypoint_8(local_1, *(u8 *) (local_0 + 0x20)));

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

            func_800EF1B8(param_0->position, *(f32 *) ((char *) param_0 + 0x48),
                          *(f32 *) ((char *) param_0 + 0x24) * func_800D8FF8());

            *(f32 *) ((char *) param_0 + 0x24) -= 6.0f;

            if ((param_0->unk0->unk24 >> 22) == 0x253) {
                if (*(f32 *) ((char *) param_0 + 0x24) < 600.0f) {
                    *(f32 *) (local_0 + 0x14) += *(f32 *) (local_0 + 0x18);

                    *(f32 *) (local_0 + 0x18) += 0.5f;
                }
            }

            if (*(f32 *) ((char *) param_0 + 0x24) <= 0.0f) {
                func_80801944_chstoneballcontrol(param_0, 1);
                func_808024F8_chstoneballcontrol(param_0);
            }

            func_80803148_chstoneballcontrol(param_0);

            if (func_800DC0C0() < 0.15f && *(f32 *) ((char *) param_0 + 0x24) > 120.0f) {
                func_800B4470(param_0->position, 0, D_80805120_chstoneballcontrol, 1, 0.75f, 0.0f,
                              50, 100, 0);
            }

            func_808023AC_chstoneballcontrol(param_0);
            break;

        case 4:
            func_80802C30_chstoneballcontrol(param_0);
            func_80802418_chstoneballcontrol(param_0);
            break;

        case 6:
            *(f32 *) ((char *) param_0 + 0x24) -= 15.0f;
            func_80802418_chstoneballcontrol(param_0);
    }

    if (*(f32 *) ((char *) param_0 + 0x24) > 30.0f) {
        local_6 = func_800137AC(*(f32 *) ((char *) param_0 + 0x48));

        local_7 = func_800137C4();

        *(f32 *) ((char *) param_0 + 0x44) += ((local_6 * *(f32 *) ((char *) param_0 + 0x24)) +
                                               (local_6 * *(f32 *) ((char *) param_0 + 0x24))) /
                                              30.0f;

        *(f32 *) ((char *) param_0 + 0x4C) -= ((local_7 * *(f32 *) ((char *) param_0 + 0x24)) +
                                               (local_7 * *(f32 *) ((char *) param_0 + 0x24))) /
                                              30.0f;
    }

    if ((param_0->unk0->unk24 >> 22) == 0x253) {
        if (param_0->unk70_10 != 4 && param_0->unk70_10 != 6 && param_0->unk7C_12) {
            if (func_800DC0C0() < 0.1f) {
                func_80802614_chstoneballcontrol(local_0 + 8);
            }
        }
    }

    if (*(f32 *) (local_0 + 0x1C) > 0.0f) {
        *(f32 *) (local_0 + 0x1C) -= func_800D8FF8();
    }
}

void func_808023AC_chstoneballcontrol(Actor *param_0)
{
    s32 local_0;
    local_0 = func_808026A0_chstoneballcontrol(param_0);
    if (func_800EA05C() != 0xBB)
        param_0->position[1] = 30.0f;
    else
        param_0->position[1] = -320.0f;
    if (local_0 != -1)
        func_8080282C_chstoneballcontrol(param_0, local_0);
}

void func_80802418_chstoneballcontrol(param_0) u8 *param_0;
{
    f32 local_0;
    u8 local_1;
    local_1 = *((u8 *) (((s8 *) param_0) + 0x9B));
    *((f32 *) (((s8 *) param_0) + 8)) = (f32) ((*((f32 *) (((s8 *) param_0) + 8))) - 5.0f);
    local_1 += 0;
    local_0 = (f32) local_1;
    *((u8 *) (((s8 *) param_0) + 0x9B)) = (u8) ((u32) (local_0 * 0.7f));
    *((f32 *) (((s8 *) param_0) + 0x38)) = (f32) ((*((f32 *) (((s8 *) param_0) + 0x38))) * 0.95f);
}

void func_808024F8_chstoneballcontrol(ball) u8 *ball;
{
    s32 controller;

    controller = func_80106790((*(s32 *) ((s8 *) (ball) + (0x3C))));
    if (((u32) (*(u32 *) ((s8 *) ((*(u8 **) ((s8 *) (ball) + (0)))) + (0x24))) >> 0x16) ==
        0x253) {
        func_80802648_chstoneballcontrol(ball + 4);
        func_80802F14_chstoneballcontrol(ball);
        _subaddieaudioquick_entrypoint_2(ball, ball + 4, &D_80804FD4_chstoneballcontrol);
        _subaddiefade_entrypoint_3(ball);
        func_80801944_chstoneballcontrol(ball, 4);
        func_80800DB4_chstoneballcontrol(controller, ball + 4);
    }
}

void func_80802588_chstoneballcontrol(ball, variant) Actor *ball;
s32 variant;
{
    s32 effect;

    effect = func_800BABB8(0, ball->position, NULL, 1.0f, D_80805134_chstoneballcontrol);
    func_800BA670(effect, variant == 1 ? 0x679 : 0x67A);
    func_800BA22C(effect, 10);
    _subaddieaudioquick_entrypoint_2(ball, ball->position, D_80804FE8_chstoneballcontrol);
}

void func_80802614_chstoneballcontrol(s32 target)
{
    func_800BBCB8(target, 0, 1.0f, 2, &D_80805178_chstoneballcontrol);
}

void func_80802648_chstoneballcontrol(target) Actor *target;
{
    func_800BBCB8(target, 0, 1.0f, 10, D_808051C0_chstoneballcontrol);
    func_800BBCB8(target, 0, 1.0f, 5, D_80805210_chstoneballcontrol);
}

s32 func_808026A0_chstoneballcontrol(ball)
Actor *ball;
{
    s32 i;

    if (func_800EA05C() == 0xBB) {
        if (ball->position[0] < -3055.0f) {
            return 2;
        }
        if (ball->position[0] > -1145.0f) {
            return 0;
        }
        if (ball->position[2] < -1555.0f) {
            return 3;
        }
        if (ball->position[2] > -445.0f) {
            return 1;
        }
        for (i = 0; i < 6; i++) {
            if (func_800F0064(ball->position, 100.0f, D_80805258_chstoneballcontrol[i])) {
                return 1;
            }
        }
        return -1;
    }
    if (ball->position[0] < -675.0f) {
        return 2;
    }
    if (ball->position[0] > 675.0f) {
        return 0;
    }
    if (ball->position[2] < -675.0f) {
        return 3;
    }
    if (ball->position[2] > 675.0f) {
        return 1;
    }
    return -1;
}

void func_80802FBC_chstoneballcontrol();

void func_8080282C_chstoneballcontrol(ball, side) u8 *ball;
s32 side;
{
    f32 side_z;

    f32 edge_z;
    if (func_800EA05C() != 0xBB) {
        switch (side) {
            case 0:
                side_z = *((f32 *) (((s8 *) ball) + 0xC));

                if ((side_z > -183.0f) && (side_z < 183.0f)) {
                    if ((((u32) (u16) *(u16 *) ((s8 *) ball + 0x72) >> 0xA) != 4) &&
                        (*(f32 *) ((s8 *) ball + 4) > 720.0f)) {
                        func_80802FBC_chstoneballcontrol(ball, 0);
                    }
                    if (*(f32 *) ((s8 *) ball + 4) > 801.0f) {
                        *(f32 *) ((s8 *) ball + 4) = 846.0f;
                        *(f32 *) ((s8 *) ball + 0x24) = 0.0f;
                    }
                }

                else {
                    *((f32 *) (((s8 *) ball) + 4)) = 720.0f;
                    *((f32 *) (((s8 *) ball) + 0x24)) = 0.0f;
                    func_80801944_chstoneballcontrol(ball, 6);
                }
                break;

            case 1:
                if ((*(f32 *) ((s8 *) ball + 4) < 183.0f) &&
                    (*(f32 *) ((s8 *) ball + 4) > -183.0f)) {
                    if ((((u32) (u16) *(u16 *) ((s8 *) ball + 0x72) >> 0xA) != 4) &&
                        (*(f32 *) ((s8 *) ball + 0xC) > 720.0f)) {
                        func_80802FBC_chstoneballcontrol(ball, 1);
                    }
                    if (*(f32 *) ((s8 *) ball + 0xC) > 801.0f) {
                        *(f32 *) ((s8 *) ball + 0xC) = 846.0f;
                        *(f32 *) ((s8 *) ball + 0x24) = 0.0f;
                    }
                }

                else {
                    *((f32 *) (((s8 *) ball) + 0xC)) = 720.0f;
                    *((f32 *) (((s8 *) ball) + 0x24)) = 0.0f;
                    func_80801944_chstoneballcontrol(ball, 6);
                }
                break;

            case 2:
                if ((*(f32 *) ((s8 *) ball + 0xC) < 183.0f) &&
                    (*(f32 *) ((s8 *) ball + 0xC) > -183.0f)) {
                    if ((((u32) (u16) *(u16 *) ((s8 *) ball + 0x72) >> 0xA) != 4) &&
                        (*(f32 *) ((s8 *) ball + 4) < -720.0f)) {
                        func_80802FBC_chstoneballcontrol(ball, 2);
                    }
                    if (*(f32 *) ((s8 *) ball + 4) < -801.0f) {
                        *(f32 *) ((s8 *) ball + 4) = -846.0f;
                        *(f32 *) ((s8 *) ball + 0x24) = 0.0f;
                    }
                }

                else {
                    *((f32 *) (((s8 *) ball) + 4)) = -720.0f;
                    *((f32 *) (((s8 *) ball) + 0x24)) = 0.0f;
                    func_80801944_chstoneballcontrol(ball, 6);
                }
                break;

            case 3:
                if ((*(f32 *) ((s8 *) ball + 4) > -183.0f) &&
                    (*(f32 *) ((s8 *) ball + 4) < 183.0f)) {
                    if ((((u32) (u16) *(u16 *) ((s8 *) ball + 0x72) >> 0xA) != 4) &&
                        (*(f32 *) ((s8 *) ball + 0xC) < -720.0f)) {
                        func_80802FBC_chstoneballcontrol(ball, 3);
                    }
                    if (*(f32 *) ((s8 *) ball + 0xC) < -801.0f) {
                        *(f32 *) ((s8 *) ball + 0xC) = -846.0f;
                        *(f32 *) ((s8 *) ball + 0x24) = 0.0f;
                    }
                }

                else {
                    *((f32 *) (((s8 *) ball) + 0xC)) = -720.0f;
                    *((f32 *) (((s8 *) ball) + 0x24)) = 0.0f;
                    func_80801944_chstoneballcontrol(ball, 6);
                }
        }
    } else {
        if (((((*((f32 *) (((s8 *) ball) + 4))) > (-1145.0f)) ||
              ((*((f32 *) (((s8 *) ball) + 4))) < (-3255.0f))) ||
             ((edge_z = *((f32 *) (((s8 *) ball) + 0xC)), edge_z > (-745.0f)))) ||
            (edge_z < (-1255.0f))) {
            *((f32 *) (((s8 *) ball) + 0x24)) = 0.0f;
            func_80801944_chstoneballcontrol(ball, 6);
        }
    }
}

// Collides the ball with nearby actors found through the spatial cells.
void func_80802C30_chstoneballcontrol(Actor *ball)
{
    s32 *cell_list;
    StoneballSpatialEntry *entry;
    StoneballSpatialEntry *entry_end;
    Unk80132ED0 *other;

    cell_list = func_800BE3F8(ball->position);
    while (*cell_list) {
        entry = func_800E9E88(*cell_list);
        entry_end = func_800E9EB4(*cell_list);
        while (entry < entry_end) {
            if (entry->local_2 & 1) {
                other = entry->local_0;
                if (other != ball->unk0) {
                    if (0x267 == ((StoneballMarkerC010 *) other)->local_0 ||
                        0x253 == ((StoneballMarkerC010 *) other)->local_0 ||
                        0x254 == ((StoneballMarkerC010 *) other)->local_0) {
                        func_80802D9C_chstoneballcontrol(ball, func_80106790(other));
                    }
                    if (((StoneballMarkerC010 *) other)->local_0 == 0) {
                        func_80802E30_chstoneballcontrol(
                            ball, (u32) *(u16 *) ((u8 *) other + 0x1A) >> 5);
                    }
                    if (0x237 == ((StoneballMarkerC010 *) other)->local_0) {
                        func_80802EA0_chstoneballcontrol(ball, func_80106790(other));
                    }
                }
            }

            entry++;
        }
        cell_list++;
    }
}

void func_80802D9C_chstoneballcontrol(ball, other) Actor *ball;
Actor *other;
{
    StoneBallContact1472 *data;

    data = func_80100094(ball, 0);
    if (_sukickball_entrypoint_13(ball->position, other->position, 60.0f)) {
        if (data->local_0 <= 0.0f) {
            func_800C4140(0x7FFF4482, ball->position, 0x138801F4);
            data->local_0 = 0.75f;
        }
    }
}

void func_80802E30_chstoneballcontrol(ball, slot) Actor *ball;
void *slot;
{
    Actor *controller;
    f32 slot_pos[3];
    controller = func_80106790(ball->unk3C);
    if (ball->unk70_10 != 2 && _sukickball_entrypoint_12(controller, slot)) {
        func_800F5A00(slot, slot_pos);
        _sukickball_entrypoint_13(slot_pos, ball->position, 60.0f);
    }
}

void func_80802EA0_chstoneballcontrol(ball, other) void *ball;
void *other;
{
    s32 controller;
    void *other_copy;
    controller = func_80106790(((void **) ball)[15]);
    other_copy = other;
    // Matching: the repeated masks and the extra copy are needed for the match.
    if ((((((((*((u16 *) (((char *) ball) + 0x72))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
            0xFFFFFFFFu) &
           0xFFFFFFFFu) &
          0xFFFFFFFFu) >>
         10) != 2) {
        if (_sukickball_entrypoint_12(controller, func_80801320_chstoneballcontrol(other_copy)) != 0) {
            _sukickball_entrypoint_13(((char *) other) + 4, ((char *) ball) + 4, 60.0f);
        }
    }
}

void func_80802F14_chstoneballcontrol(ball) Actor *ball;
{
    BallControlLocal *data;
    Actor *controller;

    data = func_80100094(ball, 0);
    controller = func_80106790(ball->unk3C);
    if (data->unk20 != 0x7F) {
        if (_sukickball_entrypoint_6(controller, data->unk20)) {
            func_800F4F98(data->unk20, ball->unk0);
            _sukickball_entrypoint_11(controller, data->unk20);
        } else {
            _sukickball_entrypoint_11(controller, data->unk20);
        }
        data->unk20 = 0x7F;
        data->unk0 = 10000000.0f;
    }
}

void func_80802FBC_chstoneballcontrol(Actor *ball, s32 side)
{
    Actor *controller;

    controller = func_80106790(ball->unk3C);
    func_80802F14_chstoneballcontrol(ball);
    switch (ball->unk0->unk24 >> 22) {
        case 0x267:
            _sukickball_entrypoint_9(controller, D_808052A0_chstoneballcontrol[side], 1);
            break;
        case 0x253:
            _sukickball_entrypoint_9(controller, D_808052A0_chstoneballcontrol[side], 3);
            break;
        case 0x254:
            _sukickball_entrypoint_9(controller, D_808052A0_chstoneballcontrol[side], 2);
    }
    ball->unk70_10 = 4;
    _subaddiefade_entrypoint_3(ball);
}

void chstoneballcontrol_entrypoint_1(Unk80132ED0 *actor_ref, s32 event, u32 value, s32 extra)
{
    Actor *ball;
    f32 *data;

    ball = func_80106790(actor_ref);
    data = func_80100094(ball, 0);
    switch (event) {
        case 3:
            func_80801944_chstoneballcontrol(ball, 1);
            break;
        case 1:
            data[1] = func_800D8FF8() * value;
            func_80803538_chstoneballcontrol(ball);
    }
}

void func_80803148_chstoneballcontrol(ball) Actor *ball;
{
    StoneballStateC010 *data = func_80100094(ball, 0);
    StoneballDistancesC010 distances = D_808052B0_chstoneballcontrol;
    Actor *controller;
    StoneballPlayersC010 *match_data;
    s32 i;
    s32 best_slot;
    f32 best_dist;

    controller = func_80106790(ball->unk3C);
    match_data = func_80100094(controller, 0);
    if ((controller->unk70_10 == 4 || controller->unk70_10 == 7) &&
        (data->local_0 == 0.0f || ball->unk70_10 == 1)) {
        best_slot = 0x7F;
        best_dist = 10000000.0f;
        for (i = 0; i < match_data->local_0; i++) {
            if ((ball->unk70_10 != 2 || i != data->local_1) &&
                !_sukickball_entrypoint_12(controller, i)) {
                Mass45StoneVector_80803148_chstoneballcontrol kicker_pos =
                    D_808052C0_chstoneballcontrol;

                if (_sukickball_entrypoint_6(controller, i)) {
                    if (func_800F6C5C(i) && func_800F5410(i) == 8) {
                        func_800F5A00(i, kicker_pos.local_0);
                        if (func_800EFFB4(ball->position, 65.0f, kicker_pos.local_0)) {
                            distances.local_0[i] =
                                func_800EEB40(ball->position, kicker_pos.local_0);
                        }
                    }
                } else {
                    func_800EE7F8(
                        kicker_pos.local_0,
                        func_80106790(_sukickball_entrypoint_8(controller, i))->position);
                    if (func_800EFFB4(ball->position, 65.0f, kicker_pos.local_0)) {
                        distances.local_0[i] =
                            func_800EEB40(ball->position, kicker_pos.local_0);
                    }
                }
            }
        }
        for (i = 0; i < match_data->local_0; i++) {
            if (ball->unk70_10 != 2 || i != data->local_1) {
                if (distances.local_0[i] < best_dist) {
                    best_dist = distances.local_0[i];
                    best_slot = i;
                }
            }
        }
        if (best_slot != 0x7F) {
            if (data->local_1 != 0x7F) {
                if (_sukickball_entrypoint_7(controller, data->local_1)) {
                    _sukickball_entrypoint_11(controller, data->local_1);
                } else {
                    func_800F4F98(data->local_1, ball->unk0);
                    _sukickball_entrypoint_11(controller, data->local_1);
                }
            }

            data->local_1 = best_slot;
            data->local_0 = 1.5f;

            if (_sukickball_entrypoint_6(controller, data->local_1)) {
                func_800F4950(data->local_1, ball->unk0, _chstoneballcontrol_entrypoint_1);
            } else {
                Actor *kicker = func_80106790(_sukickball_entrypoint_8(controller, data->local_1));

                ((u8 *) kicker)[0x65] &= ~0x10;
            }
            switch (((StoneballMarkerC010 *) ball->unk0)->local_0) {
                case 0x267:
                    _sukickball_entrypoint_10(controller, data->local_1, 1);
                    break;
                case 0x253:
                    _sukickball_entrypoint_10(controller, data->local_1, 3);
                    break;
                case 0x254:
                    _sukickball_entrypoint_10(controller, data->local_1, 2);
                default:
                    break;
            }
            func_80801944_chstoneballcontrol(ball, 2);
            *(f32 *) ((u8 *) ball + 0x24) = 0.0f;
        }
    }
}

int func_80803538_chstoneballcontrol(ball)
Actor *ball;
{
    Actor *controller;
    u8 *data;
    Actor *kicker;
    controller = func_80106790(ball->unk3C);
    data = func_80100094(ball, 0);
    if (_sukickball_entrypoint_6(controller, data[0x20])) {
        ball->rotation[1] = func_800F5F24(data[0x20]);
        *(f32 *) ((u8 *) ball + 0x24) =
            func_800F10B4(*(f32 *) (data + 4), 0.0f, 1.0f, 450.0f, 900.0f);
        func_800F4F98(data[0x20], ball->unk0);
        _sukickball_entrypoint_11(controller, data[0x20]);
    } else {
        kicker = func_80106790(_sukickball_entrypoint_8(controller, data[0x20]));
        ball->rotation[1] = kicker->rotation[1];
        *(f32 *) ((u8 *) ball + 0x24) =
            func_800F10B4(*(f32 *) ((u8 *) kicker + 0x58), 8.0f, 16.0f, 450.0f, 900.0f);
        *(f32 *) ((u8 *) kicker + 0x58) = 0.0f;
        _sukickball_entrypoint_11(controller, data[0x20]);
    }
    ball->unk70_10 = 3;
    data[0x20] = 0x7F;
    *(f32 *) data = 0.0f;
    func_800C4140(0x7FFF453C, ball->position, 0x3E800640);
}

void func_8080367C_chstoneballcontrol(s32 ball)
{
    func_80801944_chstoneballcontrol(ball, 0);
}

int chstoneballcontrol_entrypoint_2()
{
    return (int) &D_808052CC_chstoneballcontrol;
}

int chstoneballcontrol_entrypoint_3()
{
    return D_80805314_chstoneballcontrol;
}

int chstoneballcontrol_entrypoint_4()
{
    return (int) &D_8080535C_chstoneballcontrol;
}

s32 func_808036C0_chstoneballcontrol(Actor *kicker, s32 event, StoneballControlEvent data)
{
    s32 *reader;

    reader = func_80100094(kicker, 0);
    switch (event) {
        case 1:
            func_800BD268(*reader, (*(u32 *) ((u8 *) kicker + 0x64) << 3) >> 30);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80804B60_chstoneballcontrol();

void func_80804304_chstoneballcontrol();

void func_80804218_chstoneballcontrol();

void func_80803724_chstoneballcontrol(Actor *kicker)
{
    extern Vec3f D_8080540C_chstoneballcontrol;
    extern u8 D_80805418_chstoneballcontrol[];

    StoneballDataTop50 *data;
    char *controller;
    f32 dt;
    Vec3f offset;
    f32 slide;

    data = func_80100094(kicker, 0);
    dt = func_800D8FF8();
    controller = (char *) func_80106790(*(void **) ((char *) kicker + 0x3C));

    func_800BD2D0(data->local_0);
    data->local_1 -= dt;

    switch (kicker->unk70_10) {
        case 10:
            *(f32 *) ((char *) kicker + 0x2C) = 0.0f;
            *(f32 *) ((char *) kicker + 0x24) = _subaddiejoy_entrypoint_3(kicker);

            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                *(f32 *) ((char *) kicker + 0x24) =
                    func_800F10B4(*(f32 *) ((char *) kicker + 0x24), 0.0f, 1.0f, 0.0f,
                                  func_80800070_chstoneballcontrol(kicker));
            } else {
                *(f32 *) ((char *) kicker + 0x24) =
                    func_800F10B4(*(f32 *) ((char *) kicker + 0x24), 0.0f, 1.0f, 0,
                                  func_80800040_chstoneballcontrol(kicker));
            }

            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                if (func_800BCFC4(data->local_0, 1)) {
                    *(f32 *) ((char *) kicker + 0x58) =
                        func_800F10B4((f32) func_800BCD78(data->local_0, 1, 1) * func_800D8FF8(),
                                      0.0f, 1.0f, 450.0f, 900.0f);

                    kicker->unk64_20 = 1;
                }
            }

            func_80804B60_chstoneballcontrol(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chstoneballcontrol(kicker),
                                     func_80800040_chstoneballcontrol(kicker));

            if (func_800BD030(data->local_0, 9)) {
                func_80800B4C_chstoneballcontrol(kicker, 8);
            }
            break;

        case 8:
            if (*(f32 *) ((char *) kicker + 0x50) == 0) {
                if (func_80101E14(kicker, 0.3077f)) {
                    anctrl_setPlaybackType(func_80104248(kicker), 3);

                    *(f32 *) ((char *) kicker + 0x50) = 1.0f;
                    *(f32 *) ((char *) kicker + 0x24) = 1050.0f;

                    func_800B4470(kicker->position, 0, D_80805418_chstoneballcontrol, 1, 0.75f,
                                  0.0f, 125, 250, 0);
                }
            } else if (*(f32 *) ((char *) kicker + 0x50) != 0) {
                *(f32 *) ((char *) kicker + 0x50) += dt;

                if (*(f32 *) ((char *) kicker + 0x50) > 2.5f ||
                    *(f32 *) ((char *) kicker + 0x24) < 150.0f) {
                    func_80800B4C_chstoneballcontrol(kicker, 2);

                    *(f32 *) ((char *) kicker + 0x24) = func_8080009C_chstoneballcontrol(kicker);
                } else {
                    *(f32 *) ((char *) kicker + 0x24) *= 0.9f;
                }
            }

            *(f32 *) ((char *) kicker + 0x2C) = 0;

            func_800EEB9C((char *) kicker + 0x28, *(f32 *) ((char *) kicker + 0x48),
                          *(f32 *) ((char *) kicker + 0x24) * dt);

            func_800EF04C(kicker->position, (char *) kicker + 0x28);

            if (((StoneballEnableTop50 *) kicker)->local_0) {
                _subaddiejoy_entrypoint_3(kicker);

                if (!func_80102CF4(kicker, 8.0f)) {
                    func_80102B2C(kicker, 8.0f);
                }
            }

            func_80804304_chstoneballcontrol(kicker);
            break;

        case 12:
            if (*(f32 *) ((char *) kicker + 0x24) < 150.0f) {
                func_80800B4C_chstoneballcontrol(kicker, 2);

                *(f32 *) ((char *) kicker + 0x24) = func_8080009C_chstoneballcontrol(kicker);
            } else {
                *(f32 *) ((char *) kicker + 0x24) *= 0.9f;
            }

            *(f32 *) ((char *) kicker + 0x2C) = 0.0f;

            func_800EEB9C((char *) kicker + 0x28, *(f32 *) ((char *) kicker + 0x54),
                          *(f32 *) ((char *) kicker + 0x24) * dt);

            func_800EF04C(kicker->position, (char *) kicker + 0x28);
            break;
        case 2:
            if (((StoneballEnableTop50 *) kicker)->local_0) {
                kicker->unk70_10 = 10;
                *(f32 *) ((char *) kicker + 0x58) = 0.0f;
            }

            if (!func_80804810_chstoneballcontrol(kicker)) {
                func_80800B4C_chstoneballcontrol(kicker, 1);
            }

            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                if (func_800DC0C0() < 0.95f) {
                    func_80800B4C_chstoneballcontrol(kicker, 5);
                } else {
                    *(f32 *) ((char *) kicker + 0x34) = func_800DC178(0.0f, 2.5f);

                    func_80800B4C_chstoneballcontrol(kicker, 4);
                }
            }

            func_80804B60_chstoneballcontrol(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chstoneballcontrol(kicker),
                                     func_80800040_chstoneballcontrol(kicker));
            break;

        case 1:
            _sukickball_entrypoint_16(kicker->unk6C_0, (char *) kicker + 0x18);

            func_80804B60_chstoneballcontrol(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chstoneballcontrol(kicker),
                                     func_80800040_chstoneballcontrol(kicker));

            if (func_80804810_chstoneballcontrol(kicker)) {
                func_80800B4C_chstoneballcontrol(kicker, 2);
            }

            if (func_800EFFB4(kicker->position, 50.0f, (char *) kicker + 0x18)) {
                func_80800B4C_chstoneballcontrol(kicker, 3);
            }
            break;

        case 3:
            if (func_80804810_chstoneballcontrol(kicker)) {
                func_80800B4C_chstoneballcontrol(kicker, 2);
            }

            _sukickball_entrypoint_14(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chstoneballcontrol(kicker),
                                     func_80800040_chstoneballcontrol(kicker));
            break;

        case 4:
            offset = D_8080540C_chstoneballcontrol;

            if (*(f32 *) ((char *) kicker + 0x34) > 0.0f) {
                *(f32 *) ((char *) kicker + 0x34) -= dt;
            } else {
                func_80800B4C_chstoneballcontrol(kicker, 5);
            }

            if (!_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                func_80800B4C_chstoneballcontrol(kicker, 1);
            }

            _sukickball_entrypoint_16(kicker->unk6C_0, (char *) kicker + 0x18);

            func_800EFCD8(offset.f, _sukickball_entrypoint_15(kicker->unk6C_0), 250.0f);

            func_800EF04C((char *) kicker + 0x18, offset.f);

            if (func_800F0064(kicker->position, 100.0f, (f32 *) ((char *) kicker + 0x18)) ||
                _sukickball_entrypoint_12(controller, kicker->unk6C_0) == 3) {
                func_80800B4C_chstoneballcontrol(kicker, 5);
            }

            func_80804B60_chstoneballcontrol(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chstoneballcontrol(kicker),
                                     func_80800040_chstoneballcontrol(kicker));
            break;

        case 5:
            func_808040B8_chstoneballcontrol(kicker);
            func_80804218_chstoneballcontrol(kicker);
            func_80800B4C_chstoneballcontrol(kicker, 6);
            break;

        case 6:
            if (_sukickball_entrypoint_12(controller, kicker->unk6C_0)) {
                func_80804218_chstoneballcontrol(kicker);
            } else {
                func_80800B4C_chstoneballcontrol(kicker, 2);
            }
            break;

        case 7:
            if (*(f32 *) ((char *) kicker + 0x34) > 0.0f) {
                *(f32 *) ((char *) kicker + 0x34) -= dt;
            } else {
                func_80800B4C_chstoneballcontrol(kicker, 2);
            }

            func_80804B60_chstoneballcontrol(kicker);

            _sukickball_entrypoint_2(kicker, func_8080009C_chstoneballcontrol(kicker),
                                     func_80800040_chstoneballcontrol(kicker));
            break;

        case 9:
            slide = *(f32 *) ((char *) kicker + 0x34);

            *(f32 *) ((char *) kicker + 0x58) = 0.0f;
            *(f32 *) ((char *) kicker + 0x48) += slide;
            kicker->unk64_20 = 0;

            if (slide > 1.0f) {
                *(f32 *) ((char *) kicker + 0x34) = slide * 0.95f;
            } else if (slide < -1.0f) {
                *(f32 *) ((char *) kicker + 0x34) = slide * 0.95f;
            } else {
                func_80800B4C_chstoneballcontrol(kicker, 2);
                *(f32 *) ((char *) kicker + 0x34) = 0.0f;
            }
    }

    if (_sukickball_entrypoint_5(kicker, data->local_2)) {
        if (kicker->unk70_10 == 8) {
            func_80800B4C_chstoneballcontrol(kicker, 2);
        } else if (!((StoneballEnableTop50 *) kicker)->local_0) {
            func_80800BCC_chstoneballcontrol(kicker, 0);
        }
    } else {
        func_800EE7F8(data->local_2, kicker->position);
    }
}

s32 func_80803FF4_chstoneballcontrol(current, stage)
s32 current;
s32 stage;
{
    s32 pick;

    pick = current;
    switch (stage) {
        case 0:
            if (func_800DC298(0.1499938965f))
                return 0;
            break;
        case 1:
            if (func_800DC298(0.2249908447f))
                return 0;
            break;
        case 2:
            if (func_800DC298(0.299987793f))
                return 0;
    }
    while (pick == current)
        pick = func_800DC128(1, 4);
    return pick;
}

int func_808040B8_chstoneballcontrol(Actor *kicker)
{
    s32 controller;

    u8 *data;

    controller = func_80106790(*((s32 *) ((char *) kicker + 0x3C)));
    data = func_80100094(controller, 0);
    switch (_sukickball_entrypoint_12(controller, (*((s32 *) ((char *) kicker + 0x6C))) & 0x1FF)) {
        case 1:
            _sukickball_entrypoint_4((*((s32 *) ((char *) kicker + 0x6C))) & 0x1FF,
                                     (s32 *) ((char *) kicker + 0x18));
            return;
        case 3:
            func_8080419C_chstoneballcontrol(
                kicker,
                func_80803FF4_chstoneballcontrol((*((s32 *) ((char *) kicker + 0x6C))) & 0x1FF,
                                                 *(u8 *) ((char *) data + 0x39)));
            return;
        case 2:
            _sukickball_entrypoint_4(
                func_80803FF4_chstoneballcontrol((*((s32 *) ((char *) kicker + 0x6C))) & 0x1FF,
                                                 *(u8 *) ((char *) data + 0x39)),
                (s32 *) ((char *) kicker + 0x18));

        case 0:
            return;
    }
}

void func_8080419C_chstoneballcontrol(kicker, slot) u8 *kicker;
s32 slot;
{
    s32 controller;

    controller = func_80106790(*(s32 *) ((char *) kicker + 0x3C));
    if (_sukickball_entrypoint_6(controller, slot) != 0) {
        func_800F5A00(slot, (s32 *) ((char *) kicker + 0x18));
        return;
    }
    func_800EE7F8((s32 *) ((char *) kicker + 0x18),
                  func_80106790(_sukickball_entrypoint_8(controller, slot))->position);
}

void func_80804218_chstoneballcontrol(Actor *kicker)
{
    if (_sukickball_entrypoint_12(func_80106790(kicker->unk3C), kicker->unk6C_0) == 1) {
        _sukickball_entrypoint_4(kicker->unk6C_0, (f32 *) ((u8 *) kicker + 0x18));
    }
    *(f32 *) ((u8 *) kicker + 0x54) = func_80102D78(kicker, (f32 *) ((u8 *) kicker + 0x18));
    if (!func_80102CF4(kicker, 16.0f)) {
        func_80102B2C(kicker, 16.0f);
    } else if (!func_80102CF4(kicker, 4.0f)) {
        func_80102B2C(kicker, 4.0f);
    } else {
        kicker->unk58 = func_800DC178(10.0f, 16.0f);
        kicker->unk64_20 = 1;
        func_80800B4C_chstoneballcontrol(kicker, 2);
    }
}

void func_80804304_chstoneballcontrol(u8 *kicker)
{
    u8 *other;
    u8 *pos;
    u8 *unk_0;
    u8 *data;
    s32 i;
    f32 other_pos[3];
    f32 other_speed;
    f32 other_step;
    f32 other_vel[3];
    f32 impulse[3];
    f32 player_pos[3];
    f32 own_speed;
    f32 kicker_pos[3];

    other = 0;
    data = func_80100094(func_80106790(*(void **) (kicker + 0x3C)), 0);
    i = 0;
    if ((s32) *(u8 *) (data + 0x3A) > 0) {
        do {
            pos = kicker + 4;
            if (i != (*(s32 *) (kicker + 0x6C) & 0x1FF)) {
                unk_0 = func_80106790(*(void **) (kicker + 0x3C));

                if (_sukickball_entrypoint_7(unk_0, i) != 0) {
                    other = func_80106790(_sukickball_entrypoint_8(unk_0, i));
                    other_pos[0] = *(f32 *) (other + 4);
                    other_pos[1] = *(f32 *) (other + 8);
                    other_pos[2] = *(f32 *) (other + 0xC);
                } else {
                    func_800F5A00(i, other_pos);
                }
                if (func_800EFFB4(pos, 90.0f, other_pos) != 0) {
                    own_speed = func_800EEF94(kicker + 0x28);

                    if (_sukickball_entrypoint_6(unk_0, i) != 0) {
                        func_800F5D70(i, other_vel);
                        other_speed = func_800EEF94(other_vel);
                        other_step = func_800D8FF8() * other_speed;
                    } else {
                        other_speed = func_800EEF94(other + 0x28);
                        other_step = func_800D8FF8() * other_speed;
                    }
                    if (other_step < own_speed) {
                        if (_sukickball_entrypoint_6(unk_0, i) != 0) {
                            _sukickball_entrypoint_13(pos, other_pos, 60.0f);
                            func_800F8294(i, other_pos);
                            if (((u32) *(u16 *) (kicker + 0x72) >> 10) == 8) {
                                *(W3 *) impulse = *(W3 *) D_8080541C_chstoneballcontrol;
                                func_800F5A00(i, player_pos);
                                func_800EF1B8(impulse, func_80102D78(kicker, player_pos), 150.0f);
                                func_800F7700(i, 3, pos);
                            }
                        } else {
                            unk_0 = other + 4;
                            _sukickball_entrypoint_13(pos, unk_0, 60.0f);

                            if (((u32) *(u16 *) (kicker + 0x72) >> 10) == 8) {
                                *(f32 *) (other + 0x58) = 1.5f;
                                ((BitS101 *) other)->b4 = 1;
                                func_80800B4C_chstoneballcontrol(other, 0xC);
                                *(f32 *) (other + 0x24) = *(f32 *) (kicker + 0x24) * 0.75f;
                                *(f32 *) (other + 0x54) = func_80102D78(kicker, (f32 *) unk_0);
                                *(f32 *) (kicker + 0x24) = *(f32 *) (kicker + 0x24) * 0.5f;
                            }
                        }
                    } else {
                        _sukickball_entrypoint_13(other_pos, pos, 60.0f);
                        if (func_800DC0C0() < 0.5f &&
                            _sukickball_entrypoint_12(unk_0, *(s32 *) (kicker + 0x6C) & 0x1FF) == 0) {
                            func_80800BCC_chstoneballcontrol(kicker, other_pos);
                        }
                        if (_sukickball_entrypoint_6(unk_0, i) != 0 &&
                            func_800F52B8(i, *(s32 *) kicker) == 2) {
                            func_800F5A00(i, kicker_pos);
                            *(f32 *) (kicker + 0x54) = func_800F1DF4(kicker_pos, pos);
                            func_80800B4C_chstoneballcontrol(kicker, 0xC);
                            *(f32 *) (kicker + 0x24) = (other_step * 0.75f) / func_800D8FF8();
                        }
                        *(f32 *) (kicker + 0x58) = 1.5f;
                        ((BitS101 *) kicker)->b4 = 1;
                    }
                }
            }
            i++;
        } while (i < (s32) *(u8 *) (data + 0x3A));
    }
}

void func_808046C4_chstoneballcontrol(Actor *kicker)
{
    u8 *data;

    data = func_80100094(kicker, 0);
    ((StoneBallFlags31 *) kicker)->local_0 = 1;
    kicker->scale = 0.5f;
    func_8010A590(kicker);
    switch (func_800EA05C()) {
        case 0xC6:
            *(u8 *) (data + 0x14) = 0;
            break;
        case 0xC8:
            *(u8 *) (data + 0x14) = 1;
            break;
        case 0xC9:
            *(u8 *) (data + 0x14) = 2;
            break;
        case 0xBB:
            *(u8 *) (data + 0x14) = 3;
            break;
        case 0x17F:
            *(u8 *) (data + 0x14) = 4;
            if (kicker->unk6C_0 < (u32) _gcstatusDll_entrypoint_11()) {
                ((StoneBallFlags31 *) kicker)->local_1 = 1;
                ((StoneBallFlags31 *) kicker)->local_2 = kicker->unk6C_0;
            }
    }
    *(s32 *) data = func_800BD0DC(2);
    func_800BD268(*(s32 *) data, kicker->unk6C_0);
    func_800BD28C(*(s32 *) data, 2);
}

void func_808047E8_chstoneballcontrol(s32 kicker)
{
    func_800BD09C(*(u32 *) func_80100094(kicker, 0));
}

Actor *func_80804810_chstoneballcontrol(kicker)
Actor *kicker;
{
    Actor *ball;
    f32 dist;
    Actor *alt;
    f32 angle;
    f32 speed;

    ball = _subaddiefind_entrypoint_0(kicker->position, 0x155, -1, &dist);
    if (ball == NULL) {
        ball = _subaddiefind_entrypoint_0(kicker->position, 0x29E, -1, &dist);
        if (ball == NULL) {
            ball = _subaddiefind_entrypoint_0(kicker->position, 0x1B8, -1, &dist);
            if (ball == NULL) {
                return NULL;
            }
        }
    } else if ((ball->unk70_10 == 2 &&
                !func_800F0064(kicker->position, 100.0f, ball->position)) ||
               ball->unk70_10 == 6 || ball->unk70_10 == 4 || ball->unk70_10 == 3) {
        switch (ball->unk70_10) {
            case 2:
                alt = _subaddiefind_entrypoint_0(kicker->position, 0x155, 2, &dist);
                break;
            case 3:
                alt = _subaddiefind_entrypoint_0(kicker->position, 0x155, 3, &dist);
                break;
            case 6:
                alt = _subaddiefind_entrypoint_0(kicker->position, 0x155, 6, &dist);
                break;
            case 4:
                alt = _subaddiefind_entrypoint_0(kicker->position, 0x155, 4, &dist);
        }
        if (alt && (alt->unk70_10 == 1 || alt->unk70_10 == 3)) {
            ball = alt;
        }
    }
    if (ball->unk70_10 == 2) {
        angle = ball->unk54 - func_80102D78(kicker, (f32 *) ball->actorData);
        speed = 0.0f;
        angle = func_800136E4(angle);
        if (angle < 90.0f) {
            angle = ball->unk54 + 65.0f;
            speed = ball->unk50 * 0.006666666828f;
        } else if (angle > 270.0f) {
            angle = ball->unk54 - 65.0f;
            speed = ball->unk50 * 0.006666666828f;
        } else if (ball->unk50 > 10.0f) {
            speed = ball->unk50 * 0.002857142827f;
        }
        if (speed < 25.0f) {
            speed = 25.0f;
        }
        if (speed < 30.0f) {
            kicker->unk54 = func_80102D78(kicker, (f32 *) ball->actorData);
            if (!func_80102CF4(kicker, 45.0f) && func_80102CF4(kicker, 90.0f) &&
                func_800DC0C0() < 0.8f) {
                func_80800B4C_chstoneballcontrol(kicker, 8);
            }
        }
        func_800EFCD8((f32 *) kicker->actorData, angle, speed);
        func_800EF04C((f32 *) kicker->actorData, ball->position);
    } else {
        func_800EE7F8((f32 *) kicker->actorData, ball->position);
    }
    return ball;
}

void func_80804B60_chstoneballcontrol(Actor *actor)
{
    Mass45StoneVector_80804B60_chstoneballcontrol unk_0 =
        *(Mass45StoneVector_80804B60_chstoneballcontrol *) D_80805428_chstoneballcontrol;
    Actor *unk_1;

    unk_1 = func_80106790(actor->unk3C);
    if (actor->unk70_10 != 10) {
        actor->unk54 = func_80102D78(actor, (f32 *) actor->actorData);
        if (!func_80102CF4(actor, 240.0f)) {
            func_80804DA0_chstoneballcontrol(actor);
        } else {
            func_80804D40_chstoneballcontrol(actor);
        }
        if (!func_80102CF4(actor, 16.0f)) {
            func_80102B2C(actor, 16.0f);
        } else if (!func_80102CF4(actor, 4.0f)) {
            func_80102B2C(actor, 4.0f);
        }
    } else {
        if (!func_80102CF4(actor, 32.0f)) {
            func_80102B2C(actor, 32.0f);
        } else if (!func_80102CF4(actor, 16.0f)) {
            func_80102B2C(actor, 16.0f);
        } else if (!func_80102CF4(actor, 4.0f)) {
            func_80102B2C(actor, 4.0f);
        }
    }
    if (_sukickball_entrypoint_12(unk_1, actor->unk6C_0) &&
        func_80800070_chstoneballcontrol(actor) < ((f32 *) actor->actorData)[3]) {
        ((f32 *) actor->actorData)[3] = func_80800070_chstoneballcontrol(actor);
    }
    func_800EFCD8((f32 *) &actor->actorData[4], actor->rotation[1],
                  ((f32 *) actor->actorData)[3] * func_800D8FF8());
    func_800EE780(actor->position, actor->position, (f32 *) &actor->actorData[4]);
    func_80804304_chstoneballcontrol(actor);
    actor->rotation[1] = func_800136E4(actor->rotation[1]);
}

void func_80804D40_chstoneballcontrol(actor) Actor *actor;
{
    if (((f32 *) actor->actorData)[3] < func_80800040_chstoneballcontrol(actor)) {
        ((f32 *) actor->actorData)[3] += func_808000C8_chstoneballcontrol(actor);
    } else {
        ((f32 *) actor->actorData)[3] = func_80800040_chstoneballcontrol(actor);
    }
}

void func_80804DA0_chstoneballcontrol(actor) u8 *actor;
{
    if (func_8080009C_chstoneballcontrol(actor) < *(f32 *) (actor + 0x24)) {
        *(f32 *) (actor + 0x24) -= func_808000F4_chstoneballcontrol(actor);
    }
}

int *chstoneballcontrol_entrypoint_5()
{
    return &D_80805434_chstoneballcontrol;
}

extern void _sukickball_entrypoint_0();
extern void _sukickball_entrypoint_1();
u32 D_80804FC0_chstoneballcontrol[5] = {0x1304B1, 0xA00A6, 0x164E20, 0x101F4, 0x13880000};
s32 D_80804FD4_chstoneballcontrol[5] = {0x130413, 0xA0100, 0x167D00, 0x101F4, 0x13880000};
u8 D_80804FE8_chstoneballcontrol[20] = {0x0,  0x13, 0x4, 0xF4, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                                        0x4E, 0x20, 0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0, 0x0};
f32 D_80804FFC_chstoneballcontrol[5] = {1e+02f, 1.5e+02f, 2e+02f, 0.0f, 4e+02f};
f32 D_80805010_chstoneballcontrol[5][2] = {1.0f, 0.0f,    0.75f,   1.0f,    0.75f,
                                           1.0f, 0.3333f, 0.6666f, 0.3333f, 0.6666f};
int D_80805038_chstoneballcontrol[5][4] = {0x2, 0x0, 0x0, 0x0, 0x3, 0x1, 0x1, 0x0, 0x4, 0x1,
                                           0x0, 0x1, 0x4, 0x0, 0x0, 0x2, 0x5, 0x2, 0x1, 0x1};
s32 D_80805088_chstoneballcontrol[5] = {0x2D, 0x2D, 0x2D, 0x0, 0x3C};
u8 D_8080509C_chstoneballcontrol[20] = {0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0,
                                        0x0, 0x4, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x4};
Vec3f D_808050B0_chstoneballcontrol = {0.0f, 0.0f, 0.0f};
s32 D_808050BC_chstoneballcontrol[4] = {0x0, 0x0, 0x0, 0x0};
StoneBallTypes D_808050CC_chstoneballcontrol = {0x15501B8, 0x29EFFFF};
void *D_808050D4_chstoneballcontrol = (void *) 0x023901B7;
static u32 D_808050D4_chstoneballcontrol_rest[17] = {0x6370001,
                                                     0x0,
                                                     (u32) func_8080079C_chstoneballcontrol,
                                                     (u32) func_80105834,
                                                     (u32) func_8010A730,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x80004,
                                                     (u32) func_8080120C_chstoneballcontrol,
                                                     0x0,
                                                     0x400000,
                                                     (u32) func_80800F9C_chstoneballcontrol,
                                                     (u32) func_80107C2C,
                                                     0x80000202,
                                                     (u32) func_80800360_chstoneballcontrol,
                                                     0x0};
s32 D_8080511C_chstoneballcontrol = -0x38;
u8 D_80805120_chstoneballcontrol[20] = {0xFF, 0xFF, 0xFF, 0xC8, 0x0, 0x0,  0x0, 0xFF, 0x0, 0x0,
                                        0x0,  0xFF, 0x0,  0x0,  0x0, 0xFF, 0x0, 0x0,  0x0, 0xC8};
s32 D_80805134_chstoneballcontrol[17] = {
    0xA10000A, -0x320000,  -0x31FFCE, 0x320032,  0x2CFF83, 0x4BFF83, 0x7D0096,  0x7D001B, -0xF9015E,
    0x27FD30,  -0x2CFFD30, 0x2D00022, 0x1000180, 0x800100, 0x2A0080, 0x1000300, 0x4000000};
s32 D_80805178_chstoneballcontrol[18] = {
    0x1D09E2, 0x1BFF06, -0xF9FFEB, 0x6600CC, 0x220040, 0x4C0007, 0x70027,  0xC8,      0xF0,
    0x161000, 0xC000F,  0x2C0000,  0x640000, 0xFA,     0x2A,     0x800100, 0x3000400, 0x0};
u8 D_808051C0_chstoneballcontrol[80] = {
    0x0,  0x1D, 0x6,  0x78, 0x0, 0x15, 0x0, 0x66, 0x0,  0xCC, 0x0,  0xA,  0xFF, 0xFB, 0x0,  0x0,
    0xFF, 0xFB, 0x0,  0x5,  0x0, 0x0,  0x0, 0x5,  0x0,  0x2C, 0xFF, 0x6,  0x0,  0x64, 0xFF, 0x6,
    0x1,  0x2C, 0x0,  0xFA, 0x1, 0x2C, 0x0, 0x1B, 0xFF, 0x6A, 0xFE, 0xD4, 0x0,  0x22, 0x0,  0x80,
    0x0,  0x80, 0x1,  0x0,  0x3, 0x0,  0x0, 0x27, 0xFD, 0x30, 0xFD, 0x30, 0x2,  0xD0, 0x2,  0xD0,
    0x0,  0x16, 0x10, 0x0,  0x0, 0x2A, 0x0, 0x80, 0x1,  0x0,  0x3,  0x0,  0x4,  0x0,  0x0,  0x0};
u8 D_80805210_chstoneballcontrol[72] = {
    0x0,  0x1D, 0x9,  0xDC, 0x0,  0x19, 0x0,  0x1,  0x0,  0x6, 0x23, 0x2,  0x0,  0xA, 0xFF,
    0xFB, 0x0,  0x19, 0xFF, 0xF1, 0x0,  0x5,  0x0,  0x32, 0x0, 0xF,  0x0,  0x2C, 0x0, 0x0,
    0x0,  0x60, 0x0,  0x0,  0x0,  0x0,  0x0,  0xD8, 0x0,  0x0, 0x0,  0x22, 0x1,  0xA, 0x3,
    0x0,  0x2,  0x0,  0x5,  0x0,  0x0,  0x2A, 0x0,  0x0,  0x0, 0x2,  0x4,  0x0,  0x7, 0x0,
    0x0,  0x15, 0x0,  0x4C, 0x0,  0xB3, 0x0,  0x16, 0x0,  0x4, 0x0,  0x0};
f32 D_80805258_chstoneballcontrol[6][3] = {
    -1.15e+03f, -3e+02f, -1e+03f, -1.55e+03f, -3e+02f, -4e+02f,   -2.1e+03f,  -3e+02f, -4e+02f,
    -2.65e+03f, -3e+02f, -4e+02f, -1.55e+03f, -3e+02f, -1.6e+03f, -2.65e+03f, -3e+02f, -1.6e+03f};
s32 D_808052A0_chstoneballcontrol[4] = {0x0, 0x2, 0x1, 0x3};
StoneballDistancesC010 D_808052B0_chstoneballcontrol = {1e+07f, 1e+07f, 1e+07f, 1e+07f};
Mass45StoneVector_80803148_chstoneballcontrol D_808052C0_chstoneballcontrol = {0.0f, 0.0f, 0.0f};
int D_808052CC_chstoneballcontrol[18] = {0x2670155,
                                         0x6700005,
                                         0x0,
                                         (u32) func_80801BE0_chstoneballcontrol,
                                         (u32) func_80105834,
                                         (u32) _sukickball_entrypoint_0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x800004,
                                         (u32) func_8080367C_chstoneballcontrol,
                                         0x0,
                                         0x240000,
                                         (u32) func_80801B44_chstoneballcontrol,
                                         (u32) func_80107C2C,
                                         -0x7FFFFFFE,
                                         0x0,
                                         0x0};
s32 D_80805314_chstoneballcontrol[18] = {0x25301B8,
                                         0x6770005,
                                         0x0,
                                         (u32) func_80801BE0_chstoneballcontrol,
                                         (u32) func_80105834,
                                         (u32) _sukickball_entrypoint_0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x800006,
                                         (u32) func_8080367C_chstoneballcontrol,
                                         0x0,
                                         0x240000,
                                         (u32) func_80801B44_chstoneballcontrol,
                                         (u32) func_80107C2C,
                                         -0x7FFFFFFE,
                                         0x0,
                                         0x0};
int D_8080535C_chstoneballcontrol[18] = {0x254029E,
                                         0x6720005,
                                         0x0,
                                         (u32) func_80801BE0_chstoneballcontrol,
                                         (u32) func_80105834,
                                         (u32) _sukickball_entrypoint_0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x800004,
                                         (u32) func_8080367C_chstoneballcontrol,
                                         0x0,
                                         0x240000,
                                         (u32) func_80801B44_chstoneballcontrol,
                                         (u32) func_80107C2C,
                                         -0x7FFFFFFE,
                                         0x0,
                                         0x0};
u32 D_808053A4_chstoneballcontrol[26] = {
    0x0,        0x0,        0x3F800000, 0x1D70001,  0x3F800000, 0x1D70001,  0x3F99999A,
    0x1D70001,  0x3F800000, 0x1D70001,  0x3F800000, 0x1D70001,  0x3F800000, 0x1D70001,
    0x3F800000, 0x1D70001,  0x3F800000, 0x1EB0002,  0x4B189680, 0x1D70001,  0x3F800000,
    0x1D70001,  0x40000000, 0x1D70001,  0x4B189680, 0x1D70001};
Vec3f D_8080540C_chstoneballcontrol = {0.0f, 0.0f, 0.0f};
u8 D_80805418_chstoneballcontrol[4] = {0xFF, 0xFF, 0xFF, 0xC8};
u32 D_8080541C_chstoneballcontrol[3] = {0x0, 0x0, 0x0};
s32 D_80805428_chstoneballcontrol[3] = {0x0, 0x0, 0x0};
int D_80805434_chstoneballcontrol[19] = {0x23701B6,
                                         0x66A000B,
                                         (u32) &D_808053A4_chstoneballcontrol,
                                         (u32) func_80803724_chstoneballcontrol,
                                         (u32) func_80105834,
                                         (u32) _sukickball_entrypoint_1,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x4,
                                         (u32) func_808047E8_chstoneballcontrol,
                                         0x0,
                                         0x180000,
                                         (u32) func_808046C4_chstoneballcontrol,
                                         (u32) func_80107C2C,
                                         -0x7FFFFFFD,
                                         (u32) func_808036C0_chstoneballcontrol,
                                         0x0,
                                         0x0};
