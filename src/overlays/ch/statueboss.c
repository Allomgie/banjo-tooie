#include "common.h"

#define STATUE_STATE_1436
extern void *D_80802748_chstatueboss;
extern void func_800F608C();
extern void func_800FFAB0();
extern void func_80102424();
extern void func_80108B04();
extern void *func_80100094();
extern void func_8010D5DC(void);
extern void func_800F4A58(s32, void *, f32);
extern void _capod_entrypoint_13();
extern void _chintrotext_entrypoint_2();
extern void _subaddiedialog_entrypoint_11();
extern void _subaddiemarker_entrypoint_1();
extern void func_800F497C();
extern void func_800F49A8();
extern void func_800F49D4();
extern void func_800F8294();
extern void func_800FDC28();
extern void func_80109F08();
typedef struct { s32 state; f32 timer; f32 offset; } StatueResetJoint;
typedef struct { u8 states[0x18]; f32 timers[22]; f32 parts[5]; s16 phase; u8 pad_0[0x1A]; StatueResetJoint joints[6]; } StatueResetData;
extern s16 D_808025C0_chstatueboss[][6];
typedef struct { u8 states[0x18]; f32 timers[0x1B]; s16 phase; } StatueState1436;
extern s16 D_808027D4_chstatueboss[];
typedef struct { u8 pad_0[0x70]; f32 angles[5]; s16 start; } StatueBossAngles;
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 D_80802630_chstatueboss[];
typedef struct { u8 pad_0[0x70]; f32 local_0[5]; s16 local_1; } StatueBossRotations;
extern s32 func_800F20BC(f32, f32, f32);
extern f32 func_800F1F38(f32, f32, f32);
extern f32 mlAbsF(f32);
extern u8 D_8080265C_chstatueboss[];
extern void func_800E0AFC(s32, u8, f32, f32, f32, f32);
extern void func_800E0B8C(s32, u8, f32, f32, f32, f32);
extern void func_800E0C20(s32, u8, f32, f32, f32, f32);
extern int func_800D9078(f32 *);
extern u8 D_80802644_chstatueboss[];
extern u8 D_808027E0_chstatueboss[];
extern s16 D_80802624_chstatueboss[];
extern int D_808027E8_chstatueboss[];
extern Actor *func_80106790(s32);
extern void *func_800B2824(s32);
extern s32 func_800B1F8C(void *, f32 *, f32 *, f32, s32, s32, s32, f32, s32, s32);
extern s32 D_80802790_chstatueboss[];
extern s32 _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern s32 D_808027F8_chstatueboss[];
extern u8 D_80802850_chstatueboss[];
extern f32 D_8080264C_chstatueboss[];
extern u8 D_80802668_chstatueboss[];
extern f32 func_8010CD28(Actor *);
extern void func_800EEB9C(f32 *, f32, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct { f32 local_0[3]; f32 pad_0; f32 local_1; s32 pad_1; } StatueBossSpawn;
typedef struct { u8 pad_0[0x16C]; StatueBossSpawn local_0[4]; u8 local_1; } StatueBossSpawnList;
extern Actor *func_80108474(s32, f32 *, s32);
extern void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80102320(Actor *, f32, f32);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
extern s16 D_808027C0_chstatueboss[];
extern u8 _chstatueboss_entrypoint_1[];
extern u8 D_808027C8_chstatueboss[];
extern void func_800CE8D8(s32, f32, s32);
typedef struct { s32 local_0; f32 local_1; f32 local_2; } StatueJoint;
typedef struct { u8 pad_0[0x84]; s16 phase; u8 pad_1[0xA]; f32 position[3]; f32 angle; StatueJoint joints[6]; } StatueJointData;
extern s16 D_808025FC_chstatueboss[][4];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { f32 values[6]; } StatueAudioTimes;
typedef struct { f32 values[5]; } StatueAudioValues;
extern u8 D_80802804_chstatueboss[];
extern u8 D_8080281C_chstatueboss[];
extern u8 D_80802830_chstatueboss[];
extern u8 D_80802844_chstatueboss[];
extern f32 func_800DC178(f32, f32);
extern void func_800C4B64(f32);
extern s32 D_8080285C_chstatueboss[];
extern s32 D_80802894_chstatueboss[];
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
typedef struct { u8 pad_0[0x84]; s16 index; u8 pad_1[0xA]; f32 position[3]; f32 angle; } StatueBossProjectile;
typedef struct { f32 local_0[3]; f32 pad_0; f32 local_1; f32 pad_1; } StatueSpawn1772;
typedef struct { u8 pad_0[0x10C]; StatueSpawn1772 local_0[4]; } StatueSpawnData1772;
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
void func_80800BE0_chstatueboss();
void func_80801640_chstatueboss(s32 param_0, s32 param_1, volatile unsigned int param_2);
void func_80800DA8_chstatueboss();
void func_808010A0_chstatueboss();
void func_80801804_chstatueboss();
void func_80801AF0_chstatueboss();
void func_80801CA0_chstatueboss();
void func_80801ECC_chstatueboss();
void func_80802144_chstatueboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_8080000C_chstatueboss(), func_80800298_chstatueboss();
extern u8 D_80802670_chstatueboss[];

int chstatueboss_entrypoint_0()
{
  return &D_80802748_chstatueboss;
}

void func_8080000C_chstatueboss(param_0) Actor *param_0;
{
    u8 *local_1;
    s32 local_4;
    s32 local_0;
    local_1 = func_80100094(param_0, 0);
    if (func_800DA298(0x36F) && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(param_0);
        return;
    }
    func_80800BE0_chstatueboss(param_0);
    func_80109F08(param_0, 0x41);
    *(s16 *)(local_1 + 0x8A) = 0;
    *(s16 *)(local_1 + 0x88) = *(s16 *)(local_1 + 0x8A);
    for (local_4 = 0; local_4 < 4; local_4++) {
        _subaddiemarker_entrypoint_1(param_0, 0x154, local_4 + 0x32, local_1 + 0x10C + local_4 * 0x18, 1);
    }
    _subaddiemarker_entrypoint_1(param_0, 0x320, 0x32, (local_1 + 0xF4), 1);
    _subaddiemarker_entrypoint_1(param_0, 0x320, 0x33, local_1 + 0x16C, 4);
    local_0 = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        for (local_4 = 0; local_4 != 4; local_4++) {
            func_80801640_chstatueboss(param_0, local_4, 1);
        }
        func_80102424(param_0, 0x1A);
        return;
    }
    if (!func_800DA298(0x88)) {
        func_800F608C(local_0, 1);
        func_800F497C(local_0);
        func_800F49A8(local_0, 1);
        func_800F49D4(local_0, func_8010D5DC, param_0->unk0);
        func_800F4A58(local_0, (local_1 + 0xF4), 130.0f);
        local_1[0x1CD] = 1;
        _capod_entrypoint_13(param_0->unk0, 0, 0xC, 0x20);
        _chintrotext_entrypoint_2(1);
        return;
    }
    for (local_4 = 0; local_4 != 4; local_4++) {
        func_80801640_chstatueboss(param_0, local_4, 1);
    }
    func_800F608C(local_0, 1);
    func_800F8294(local_0, (local_1 + 0xF4));
    func_800F497C(local_0);
    func_80800DA8_chstatueboss(param_0, 6);
    _subaddiedialog_entrypoint_11(param_0->unk0, 0xF41, 6, param_0->position, 0xB2);
    func_80108B04(param_0, 3);
    func_80108B04(param_0, 4);
    local_1[0x1CC] = 1;
    local_1[0x1CD] = 1;
    _capod_entrypoint_13(param_0->unk0, 0, 0x12, 0x30);
    func_800FDC28(1);
}


































void func_8080232C_chstatueboss();

void func_80801A6C_chstatueboss(u8 *param_0, f32 param_1);

void func_80801448_chstatueboss();

void func_8080124C_chstatueboss();

void func_808011B4_chstatueboss();

void func_80800298_chstatueboss(param_0) Actor *param_0;
{
    extern s32 D_80802790_chstatueboss[];
    extern u8 D_808027AC_chstatueboss[];
    extern void _chbaddiesetup_entrypoint_10(void);

    u8 *local_0;
    s32 local_4;
    s32 local_3;
    s32 local_5;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = (u8 *)func_80100094(param_0, 0);
    local_4 = 0;
    local_3 = 0;
    local_5 = 0;

    _sudeflect_entrypoint_1(
        param_0->position,
        400.0f,
        -100.0f,
        550.0f,
        2
    );

    if ((s32)param_0->unk70_10 >= 7) {
        func_800D2498(
            0xF3,
            0x10 - *(s16 *)(local_0 + 0x8A),
            0
        );
    }

    if (!func_800D0B68(1, 1)) {
        if (_subaddieskeleton_entrypoint_2(
                param_0->unk0,
                0xA,
                local_1)) {
            if (local_1[1] < param_0->position[1]) {
                local_1[1] = param_0->position[1];
            }

            func_800D1254(1, 1, local_1);
        }
    }

    switch (param_0->unk70_10) {
        case 1:
            if (!func_800DA298(0x6AD)) {
                if (*(u8 *)(local_0 + 0x1D0) == 0) {
                    *(u8 *)(local_0 + 0x1D0) = 1;

                    _subaddiedialog_entrypoint_11(
                        param_0->unk0,
                        0xF43,
                        0x44,
                        param_0->position,
                        0xB2
                    );
                }
            }

            if (*(u8 *)(local_0 + 0x1CF) != 0 &&
                *(u8 *)(local_0 + 0x1CE) != 0) {
                func_800F82D4(func_800F54E4(), 0);
                func_80800DA8_chstatueboss(param_0, 2);
            }
            break;

        case 2:
            break;

        case 3:
            if (func_80101E14(param_0, 0.1f)) {
                func_80801C78_chstatueboss(param_0);
            }

            func_80801A6C_chstatueboss(param_0, 0.35f);

            if (func_80101DDC(param_0)) {
                _subaddiedialog_entrypoint_11(
                    param_0->unk0,
                    0xF33,
                    6,
                    param_0->position,
                    0xB2
                );

                func_80800DA8_chstatueboss(param_0, 4);
            }
            break;


        case 5:
            if (_subaddieaudioquick_entrypoint_4(
                    param_0,
                    param_0->position,
                    &D_80802790_chstatueboss,
                    D_808027AC_chstatueboss)) {
                func_800E15CC(0, 10.0f, 0.8f);
                func_80018820(0, 2.0f, 0.25f);
            }

            local_5 = func_80102320(
                param_0,
                0.6f,
                0.99f
            );

            func_80801AC4_chstatueboss(param_0, local_5);

            if (func_80101DDC(param_0)) {
                _subaddiedialog_entrypoint_11(
                    param_0->unk0,
                    0xF34,
                    6,
                    param_0->position,
                    0xB2
                );

                func_80800DA8_chstatueboss(param_0, 6);
            }
            break;

        case 4:
        case 6:
        case 23:
            func_80801AF0_chstatueboss(param_0);
            break;

        case 7:
            if (_subaddieskeleton_entrypoint_0(
                    param_0,
                    0x2D,
                    local_2)) {
                func_800EF1B8(local_2, func_800F1DF4(local_2, param_0->position), 120.0f);
                _sudeflect_entrypoint_0(
                    local_2,
                    0.0f,
                    250.0f,
                    2
                );
            }

            if (_subaddieskeleton_entrypoint_0(
                    param_0,
                    0x2C,
                    local_2)) {
                func_800EF1B8(local_2, func_800F1DF4(local_2, param_0->position), 120.0f);
                _sudeflect_entrypoint_0(
                    local_2,
                    0.0f,
                    250.0f,
                    2
                );
            }

            local_3 = 1;
            local_4 = 1;
            break;

        case 8:
            func_80801A6C_chstatueboss(param_0, 0.65f);

            if (func_80101DDC(param_0)) {
                func_80800DA8_chstatueboss(param_0, 9);
            }
            break;

        case 9:
            func_80801AF0_chstatueboss(param_0);
            local_3 = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80801C78_chstatueboss(param_0);
                func_80800DA8_chstatueboss(param_0, 0xB);
            }
            break;


        case 11:
            local_3 = 1;
            local_4 = 1;
            break;

        case 12:
            func_80801A6C_chstatueboss(param_0, 0.7f);

            if (func_80101DDC(param_0)) {
                func_80800DA8_chstatueboss(param_0, 0xD);
            }
            break;

        case 13:
            func_80801AF0_chstatueboss(param_0);
            local_3 = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80801C78_chstatueboss(param_0);
                func_80800DA8_chstatueboss(param_0, 0xF);
            }
            break;

        case 15:
            local_3 = 1;
            local_4 = 1;
            break;

        case 16:
            func_80801A6C_chstatueboss(param_0, 0.7f);

            if (func_80101DDC(param_0)) {
                func_80800DA8_chstatueboss(param_0, 0x11);
            }
            break;

        case 17:
            func_80801AF0_chstatueboss(param_0);
            local_3 = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80801C78_chstatueboss(param_0);
                func_80800DA8_chstatueboss(param_0, 0x13);
            }
            break;

        case 19:
            local_3 = 1;
            local_4 = 1;
            break;

        case 20:
            func_80801A6C_chstatueboss(param_0, 0.85f);

            if (func_80101DDC(param_0)) {
                func_80800DA8_chstatueboss(param_0, 0x15);
            }
            break;

        case 21:
            func_8080232C_chstatueboss(param_0);
            func_80801AF0_chstatueboss(param_0);
            local_3 = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80800DA8_chstatueboss(param_0, 0x17);
            }
            break;

        case 24:
            func_8080232C_chstatueboss(param_0);

            if (func_800CEAD0(0)) {
                func_800E15CC(0, 30.0f, 0.8f);
                func_80018820(0, 3.0f, 0.25f);

                _chbaddiesetup_entrypoint_5(
                    _chbaddiesetup_entrypoint_10,
                    5,
                    *(s32 *)&param_0->position[0],
                    *(s32 *)&param_0->position[1],
                    *(s32 *)&param_0->position[2],
                    *(s32 *)&param_0->rotation[1]
                );

                _chexploder_entrypoint_5(
                    param_0,
                    0x7CC,
                    param_0->position,
                    *(f32 *)(local_0 + 0x80),
                    param_0->scale,
                    0
                );

                func_80108B04(param_0, 2);
                func_800DA544(0x36F);
                func_800FDC28(0);
            }
            break;

        case 25:
            if (func_800D9078(&param_0->unk58)) {
                _gcfrontend_entrypoint_10();
            }
            break;

        case 10:
        case 14:
        case 18:
        case 22:
            local_3 = 2;
            break;

        case 26:
            func_80801AF0_chstatueboss(param_0);
            break;
    }

    switch (local_3) {
    case 1:
        func_808011B4_chstatueboss(param_0);
        break;
    case 2:
        func_8080124C_chstatueboss(param_0);
        break;
    }

    if (local_5 == 0) {
        local_5 = (local_3 == 1);
    }

    func_80801AC4_chstatueboss(param_0, local_5);
    func_80801804_chstatueboss(param_0, local_4);
    func_80801448_chstatueboss(param_0);
}

void func_80802268_chstatueboss();

void func_808020EC_chstatueboss();

void func_80801F74_chstatueboss();

void func_80801518_chstatueboss();

void func_80801320_chstatueboss();

s32 func_80800934_chstatueboss(Actor *param_0, s32 param_1, u32 param_2)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2E:
        func_808010A0_chstatueboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x40:
        func_80801518_chstatueboss(param_0, *(u32 *)&param_2);
        break;
    case 0xB:
        if (param_2 == 0x10) {
            func_80800DA8_chstatueboss(param_0, 3);
            return 4;
        }
        return 3;
    case 0x3D:
        switch (param_2) {
        case 0:
            func_80801ECC_chstatueboss(param_0);
            break;
        case 1:
            func_80802144_chstatueboss(param_0);
            break;
        case 2:
            func_80801F74_chstatueboss(param_0);
            break;
        case 3:
            func_808020EC_chstatueboss(param_0);
            break;
        case 4:
            func_80802268_chstatueboss(param_0);
            break;
        }
        break;
    case 0x90:
        func_80801CA0_chstatueboss(param_0);
        break;
    case 0x32:
        local_0[0x1CE] = 1;
        func_800F82D4(func_800F54E4(), 2);
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x146, param_0->position, 0xB2);
        break;
    case 0x9F:
        func_800FDC28(0);
        func_80800DA8_chstatueboss(param_0, D_808027C0_chstatueboss[*(s16 *)(local_0 + 0x84)]);
        break;
    case 0x9C:
        func_80801320_chstatueboss(param_0);
        break;
    case 0x95:
        _subaddiecustomhits_entrypoint_0(param_0, &_chstatueboss_entrypoint_1);
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800B74_chstatueboss(param_0, param_1) s32 param_0; s32 param_1;
{
  u8 *local_0;
  s32 local_1;
  local_0 = func_80100094(param_0, 0);
  for (local_1 = 1; local_1 < 0x16; local_1++)
  {
    func_800DF744(local_1 | 0, local_0[local_1]);
  }

  func_80101870(param_0, param_1);
}

void func_80800BE0_chstatueboss(param_0) Actor *param_0;
{
    StatueResetData *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 != 4; local_1++)
        func_80801640_chstatueboss((s32)param_0, local_1, 0);
    func_80801640_chstatueboss((s32)param_0, 4, 1);
    for (local_2 = 0; local_2 < 4; local_2++) {
        for (local_1 = 0; D_808025C0_chstatueboss[local_2][local_1] != -1; local_1++) {
            local_3 = D_808025C0_chstatueboss[local_2][local_1];
            local_0->states[local_3] = 2;
        }
    }
    for (local_1 = 0; local_1 < 5; local_1++)
        local_0->parts[local_1] = 0.0f;
    for (local_1 = 0; local_1 < 6; local_1++) {
        local_0->joints[local_1].state = 0;
        local_0->joints[local_1].timer = 0.0f;
        local_0->joints[local_1].offset = 0.0f;
    }
    for (local_1 = 1; local_1 < 22; local_1++)
        local_0->timers[local_1] = 0.0f;
    local_0->phase = 0;
}

void func_80800D30_chstatueboss(Actor *param_0)
{
    StatueState1436 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    local_1 = local_0->phase;
    local_2 = 0;
    while (D_808025C0_chstatueboss[local_1][local_2] != -1) {
        local_3 = D_808025C0_chstatueboss[local_1][local_2];
        local_0->states[local_3] = 1;
        local_2++;
    }
}

void func_80801E90_chstatueboss();

void func_80801E24_chstatueboss();

void func_80800DA8_chstatueboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    func_80102424(param_0, param_1);
    switch (param_1) {
        case 2:
            func_80801E24_chstatueboss(param_0, 16, 48);
            func_80101180(0x450, 8, 0);
            return;
        case 3:
            func_80801E24_chstatueboss(param_0, 0, 48);
            func_80108B04(param_0, 3);
            func_800FDC28(1);
            return;
        case 5:
            for (local_0 = 0; local_0 != 4; local_0++) {
                func_80801640_chstatueboss(param_0, local_0, 1);
            }
            _chintrotext_entrypoint_1(0x18B9, 4, 1, 0);
            func_80801E24_chstatueboss(param_0, 6, 48);
            func_80101180(0x449, 7, 0);
            func_80108B04(param_0, 4);
            return;
        case 8:
            *(s16 *)(local_1 + 0x88) = 0;
            *(s16 *)(local_1 + 0x84) = 1;
            _chexploder_entrypoint_5(param_0, 0x7C8, param_0->position,
                *(f32 *)(local_1 + 0x70), param_0->scale, 0);
            return;
        case 12:
            *(s16 *)(local_1 + 0x88) = 0;
            *(s16 *)(local_1 + 0x84) = 2;
            _chexploder_entrypoint_5(param_0, 0x7C9, param_0->position,
                *(f32 *)(local_1 + 0x74), param_0->scale, 0);
            return;
        case 16:
            *(s16 *)(local_1 + 0x88) = 0;
            *(s16 *)(local_1 + 0x84) = 3;
            _chexploder_entrypoint_5(param_0, 0x7CA, param_0->position,
                *(f32 *)(local_1 + 0x78), param_0->scale, 0);
            return;
        case 9:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xF35, 6, param_0->position, 0xB2);
            func_80801E24_chstatueboss(param_0, 10, 48);
        case 13:
        case 17:
        case 21:
            func_80108B04(param_0, 1);
            return;
        case 7:
            func_800FDC28(2);
            func_800DA544(0x88);
            _gcfrontend_entrypoint_9(0x23);
            func_80801E90_chstatueboss(param_0);
        case 11:
        case 15:
        case 19:
            func_8010A590(param_0);
            func_80800D30_chstatueboss(param_0);
            return;
        case 20:
            *(s16 *)(local_1 + 0x88) = 0;
            func_8010A570(param_0);
            _chexploder_entrypoint_5(param_0, 0x7CB, param_0->position,
                *(f32 *)(local_1 + 0x7C), param_0->scale, 0);
            return;
        case 23:
            func_80801E24_chstatueboss(param_0, 20, 48);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xF36, 6, param_0->position, 0xB2);
            return;
        case 24:
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808027C8_chstatueboss);
            func_800CE88C(0, 1);
            func_800CE8D8(0, 3.0f, 3);
            return;
        case 25:
            param_0->unk64_16 = 0;
            param_0->unk58 = 6.0f;
        default:
            return;
    }
}

void func_808010A0_chstatueboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0xF33: func_80800DA8_chstatueboss(param_0, 5); break;
        case 0xF41: func_80800DA8_chstatueboss(param_0, 7); break;
        case 0xF34: func_80800DA8_chstatueboss(param_0, 7); break;
        case 0xF36:
            func_80801E90_chstatueboss(param_0);
            func_80800DA8_chstatueboss(param_0, 24);
            break;
        case 0xF43: local_0[0x1CF] = 1; break;
        case 0xF35: func_80801E90_chstatueboss(param_0); break;
        case 0xCEB:
            if (param_2 > 0) _gcfrontend_entrypoint_11();
            else _gcfrontend_entrypoint_10();
            break;
    }
}

int func_808011A0_chstatueboss(s32 param_0)
{
  return D_808027D4_chstatueboss[param_0];
}

void func_808011B4_chstatueboss(Actor *param_0)
{
    StatueBossAngles *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = local_0->start; local_1 < 5; local_1++) {
        local_0->angles[local_1] += func_800D8FF8() * D_80802630_chstatueboss[local_1];
        local_0->angles[local_1] = func_800136E4(local_0->angles[local_1]);
    }
}

void func_8080124C_chstatueboss(Actor *param_0)
{
    StatueBossRotations *local_0;
    s32 local_1;
    f32 local_2;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = local_0->local_1; local_1 < 5; local_1++) {
        if (!func_800F20BC(local_0->local_0[local_1], 0.0f, 5.0f)) {
            local_2 = func_800D8FF8();
            local_0->local_0[local_1] = func_800F1F38(local_0->local_0[local_1],
                0.0f, mlAbsF(D_80802630_chstatueboss[local_1]) * local_2);
            local_0->local_0[local_1] = func_800136E4(local_0->local_0[local_1]);
        }
    }
}

void func_80801320_chstatueboss(Actor *param_0)
{
    s32 local_2;
    u8 *local_0;
    s32 local_1;

    local_2 = func_8010262C(param_0->unk0, 12);
    if (local_2) {
        local_0 = func_80100094(param_0, 0);
        for (local_1 = 0; local_1 < 5; local_1++) {
            func_800E0AFC(local_2, (u8)func_808011A0_chstatueboss(local_1),
                1.0f, 0.0f, *(f32 *)(local_0 + 0x70 + local_1 * 4), 0.0f);
        }
        func_800E0B8C(local_2, 0x52, 1.0f, 1.0f, 2.0f, 1.0f);
        for (local_1 = 0; local_1 < 6; local_1++) {
            func_800E0C20(local_2, D_8080265C_chstatueboss[local_1 * 2 + 1],
                1.0f, 0.0f, *(f32 *)(local_0 + 0xA8 + local_1 * 12), 0.0f);
        }
    }
}

void func_80801448_chstatueboss(Actor *param_0)
{
    StatueState1436 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_4 = local_0->phase;
    for (local_1 = 0; D_808025C0_chstatueboss[local_4][local_1] != -1; local_1++) {
        local_2 = D_808025C0_chstatueboss[local_4][local_1];
        if (local_0->states[local_2] == 2 && func_800D9078(&local_0->timers[local_2])) {
            local_0->states[local_2] = 1;
        }
    }
}

void func_80801518_chstatueboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_3;
    s32 local_2;
    s32 local_1;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_1 = *(s16 *)(local_0 + 0x84);
    local_2 = *(s16 *)(local_0 + 0x86);
    for (local_3 = 0; D_808025C0_chstatueboss[local_1][local_3] != -1; local_3++) {
        if (local_2 == D_808025C0_chstatueboss[local_1][local_3]) {
            local_0[local_2] = 2;
            *(f32 *)(local_0 + local_2 * 4 + 0x18) = 2.5f;
            func_800FC660(14);
            (*(s16 *)(local_0 + 0x8A))++;
            func_800EC398(param_1, local_0 + 0xE8);
            (*(s16 *)(local_0 + 0x88))++;
            if (!func_800DA298(0x681)) {
                local_4 = *(s16 *)(D_80802644_chstatueboss + local_1 * 2);
            } else {
                local_4 = 100;
            }
            if (local_4 == *(s16 *)(local_0 + 0x88)) {
                func_80800DA8_chstatueboss(param_0, *(s16 *)(D_808027E0_chstatueboss + local_1 * 2));
            }
            break;
        }
    }
}

void func_80801640_chstatueboss(s32 param_0, s32 param_1, volatile unsigned int param_2)
{
  s32 local_0;
  s16 local_1;
  local_0 = func_80100094(param_0, 0);
  local_1 = D_80802624_chstatueboss[param_1];
  local_0 += local_1;
  *((u8 *) local_0) = param_2;
}

int chstatueboss_entrypoint_1()
{
    return (int)&D_808027E8_chstatueboss;
}

s32 func_80801694_chstatueboss(Actor *param_0)
{
    StatueState1436 *local_0;
    s32 local_1;
    u32 local_2;
    s32 local_3;
    s32 local_4;
    local_0 = func_80100094(param_0, 0);
    local_3 = local_0->phase;
    local_2 = 0;
    for (local_1 = 0; D_808025C0_chstatueboss[local_3][local_1] != 0xFFFFFFFF; local_1++) {
        local_4 = D_808025C0_chstatueboss[local_3][local_1];
        if (local_0->states[local_4] == 1)
            local_2 |= 1U << (local_4 - 1);
    }
    return 0xFFFFFFFF ^ local_2;
}

s32 func_80801724_chstatueboss(u8 *param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    s32 local_4;
    u8 *local_0;
    s32 local_1;
    Actor *local_2;
    void *local_3;

    local_2 = func_80106790((s32)param_0);
    local_0 = (u8 *)func_80100094(local_2, 0);
    local_1 = func_80103AA0(param_0);
    if (!local_1 || !(local_4 = func_800AE0E8(*(s16 *)(param_0 + 16)))) return 0;
    param_4 = func_80801694_chstatueboss(local_2);
    local_3 = func_800B2824(local_1);
    *(s16 *)(local_0 + 0x86) = func_800B1F8C(local_3, local_2->position, local_2->rotation, local_2->scale, 0,
        func_800AE080(*(s16 *)(param_0 + 16)), param_1, param_2, param_3, param_4);
    return *(s16 *)(local_0 + 0x86);
}

void func_80801804_chstatueboss(Actor *param_0, s32 param_1)
{
    StatueJointData *local_4;
    s32 local_6;
    s32 local_1;
    f32 local_0[3];
    f32 local_3;
    f32 local_2[3];
    s32 local_7;
    s32 local_8;

    local_4 = func_80100094(param_0, 0);
    local_1 = local_4->phase;
    if (func_800F6438(func_800F54E4())) {
        local_3 = func_8010CD28(param_0);
        for (local_6 = 0; local_6 < 6; local_6++) {
            switch (local_4->joints[local_6].local_0) {
            case 1:
                local_7 = func_800D90A4(&local_4->joints[local_6].local_1);
                local_4->joints[local_6].local_2 = func_800F10B4(local_4->joints[local_6].local_1, 0.0f, 0.6f, -2.0f, 0.0f);
                if (local_7) {
                    local_4->joints[local_6].local_0 = 2;
                    local_4->joints[local_6].local_1 = 1.2f;
                }
                break;
            case 2:
                local_7 = func_800D90A4(&local_4->joints[local_6].local_1);
                local_4->joints[local_6].local_2 = func_800F10B4(local_4->joints[local_6].local_1, 0.0f, 1.2f, 0.0f, -2.0f);
                if (local_7) local_4->joints[local_6].local_0 = 0;
                break;
            }
        }
        if (param_1 && func_8010D248()) {
            func_8008FE68(local_2);
            for (local_6 = 0; D_808025FC_chstatueboss[local_1][local_6] != -1; local_6++) {
                if (1) {}
                local_8 = D_808025FC_chstatueboss[local_1][local_6] - 4;
                func_800D9078(&local_4->joints[local_8].local_1);
                if (!local_4->joints[local_8].local_0 &&
                    _subaddieskeleton_entrypoint_2(param_0->unk0, D_808025FC_chstatueboss[local_1][local_6], local_0) &&
                    func_800F20BC(func_800F1DF4(param_0->position, local_0), local_3, 25.0f)) {
                    func_80108B04(param_0, 0);
                    func_800EE7F8(local_4->position, local_0);
                    local_4->angle = func_800F1DF4(local_0, local_2);
                    local_4->joints[local_8].local_1 = 0.6f;
                    local_4->joints[local_8].local_0 = 1;
                }
            }
        }
    }
}

void func_80801A6C_chstatueboss(u8 *param_0, f32 param_1) {
    if (_subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80802790_chstatueboss, param_1)) {
        func_800E15CC(0, 20.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
    }
}

int func_80801AC4_chstatueboss(s32 param_0, s32 param_1)
{
  _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, param_1 | 0, &D_808027F8_chstatueboss);
}

void func_80801AF0_chstatueboss(param_0) Actor *param_0;
{
    StatueAudioTimes local_0;
    StatueAudioValues local_1;
    StatueAudioValues local_2;
    s32 local_3;
    local_0 = *(StatueAudioTimes *)D_80802804_chstatueboss;
    local_1 = *(StatueAudioValues *)D_8080281C_chstatueboss;
    local_2 = *(StatueAudioValues *)D_80802830_chstatueboss;
    for (local_3 = 0; local_0.values[local_3] != -1.0f; local_3++) {
        if (func_80101E14(param_0, local_0.values[local_3])) {
            func_800C4B64(local_1.values[local_3] + func_800DC178(-0.05f, 0.05f));
            func_800C4B70((s32)local_2.values[local_3]);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80802844_chstatueboss);
            return;
        }
    }
}

int func_80801C78_chstatueboss(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_80802850_chstatueboss);
}

void func_80801CA0_chstatueboss(param_0) Actor *param_0;
{
    s32 local_3;
    u8 *local_0;
    Actor *local_1;
    local_3 = 0;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_80106790((Unk80132ED0 *)func_80101080());
    _chexploder_entrypoint_12(local_1, 40);
    _chexploder_entrypoint_6(local_1, 1200.0f, 1600.0f);
    _chexploder_entrypoint_15(local_1, 1, 1.25f);
    switch (param_0->unk70_10) {
    case 8: local_3 = 80; func_80801640_chstatueboss(param_0, 0, 0); break;
    case 12: local_3 = 80; func_80801640_chstatueboss(param_0, 1, 0); break;
    case 16: local_3 = 80; func_80801640_chstatueboss(param_0, 2, 0); break;
    case 20: local_3 = 80; func_80801640_chstatueboss(param_0, 3, 0); break;
    case 24: local_3 = 80; func_80801640_chstatueboss(param_0, 4, 0); break;
    }
    _subaddieaudioquick_entrypoint_2(local_1, local_1->position, &D_80802894_chstatueboss);
    func_800BBCB8(local_1->position, local_1->position, 1.0f, 6, &D_8080285C_chstatueboss);
    local_1 = func_80106790(*(Unk80132ED0 **)(local_0 + 0x8C));
    local_1->position[1] -= param_0->scale * local_3;
}

void func_80801E24_chstatueboss(s32 *param_0, s32 param_1, s32 param_2) {
    s32 *local_0;
    s32 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    if (*(u8 *)((char *)local_1 + 0x1CD) != 0) {
        param_2 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(*param_0, 0, param_1, param_2);
    *(u8 *)((char *)local_0 + 0x1CD) = 1;
}

void func_80801E90_chstatueboss(s32 param_0) {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if (sp1C[0x1CD] != 0) {
        _capod_entrypoint_14();
        sp1C[0x1CD] = 0;
    }
}

void func_80801ECC_chstatueboss(param_0) Actor *param_0;
{
    StatueBossProjectile *local_0;
    Actor *local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_80108528(0x448, local_0->position, (s32)local_0->angle, &param_0);
    local_1->rotation[1] = local_0->angle;
    if (!func_800DA298(0x682)) *(f32 *)&local_1->actorData[3] = D_8080264C_chstatueboss[local_0->index];
    else *(f32 *)&local_1->actorData[3] = 10000.0f;
    _subaddieaudioquick_entrypoint_2(param_0, local_0->position, D_80802668_chstatueboss);
}

void func_80801F74_chstatueboss(Actor *param_0)
{
    u8 *local_0;
    f32 local_2;
    Actor *local_3;
    s32 local_4;
    f32 local_1[3];
    local_0 = func_80100094(param_0, 0);
    local_2 = func_8010CD28(param_0);
    for (local_4 = 0; local_4 < 10; local_4++) {
        func_800EEB9C(local_1, local_2, 50.0f);
        func_800EF04C(local_1, param_0->position);
        local_1[1] += 100.0f;
        local_3 = func_80108528(0x448, local_1, (s32)local_2, &param_0);
        local_3->rotation[1] = local_2;
        *(f32 *)((u8 *)local_3 + 0x24) = D_8080264C_chstatueboss[3];
        local_2 += 36.0f;
    }
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802668_chstatueboss);
    func_800D1254(1, 1, param_0->position);
    if (func_800D395C()) func_80800DA8_chstatueboss(param_0, 0x19);
    else {
        func_80101180(0x450, 7, 0);
        func_800FFAB0(param_0);
    }
    func_800FFA88(*(void **)(local_0 + 0x8C));
    *(void **)(local_0 + 0x8C) = NULL;
}

void func_808020EC_chstatueboss(u8 *param_0) {
    u8 *local_0;
    s32 *local_1;
    s32 *local_2;

    local_0 = func_80100094(param_0, 0);
    local_2 = func_801084B0(0x44F, &param_0);
    local_1 = local_2;
    func_80102FDC(local_2, (*(s32 *)((s8 *)(param_0) + (0x38))));
    (*(s32 *)((s8 *)(local_0) + (0x8C))) = (s32) *local_1;
}

void func_80802144_chstatueboss(param_0) Actor *param_0;
{
    Actor *local_0;
    StatueSpawnData1772 *local_1;
    s32 local_2;
    s32 local_4;

    local_1 = func_80100094(param_0, 0);
    local_4 = 1;
    switch (param_0->unk70_10) {
        case 13:
            local_4 = 2;
            break;
        case 17:
            local_4 = 3;
            break;
        case 21:
            local_4 = 4;
            break;
    }
    for (local_2 = 0; local_2 < local_4; local_2++) {
        local_0 = func_80108528(0x112, local_1->local_0[local_2].local_0, (s32)local_1->local_0[local_2].local_1, &param_0);
        _chappearfx_entrypoint_1(local_0, 0x2A, 0, 0.6f);
        func_80100120(local_0);
        _sucoaster_entrypoint_4(local_0);
        local_0->unk74_17 = 0;
    }
}

void func_80802268_chstatueboss(Actor *param_0)
{
    StatueBossSpawnList *local_0;
    Actor *local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    for (local_2 = 0; local_2 < 4; local_2++) {
        local_1 = func_80108474(0x1C8, local_0->local_0[local_2].local_0, (s32)local_0->local_0[local_2].local_1);
        local_1->unk74_7 = 0x33;
        if (local_0->local_1 == 0) _chappearfx_entrypoint_2(local_1, 0x20, 0, 1.0f);
    }
}

void func_8080232C_chstatueboss(Actor *param_0)
{
    f32 local_0[3];

    if (_subaddieskeleton_entrypoint_0(param_0, 0x1E, local_0)) {
        func_800EF1B8(local_0, func_800F1DF4(param_0->position, local_0), 8e+01f);
        local_0[1] = param_0->position[1];
        _sudeflect_entrypoint_1(local_0, 300.0f, -50.0f, 250.0f, 2);
    }
    if (_subaddieskeleton_entrypoint_0(param_0, 0x10, local_0)) {
        func_800EF1B8(local_0, func_800F1DF4(param_0->position, local_0), 80.0f);
        local_0[1] = param_0->position[1];
        _sudeflect_entrypoint_1(local_0, 300.0f, -50.0f, 250.0f, 2);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/statueboss.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80802790_chstatueboss -> s32[], D_808027E8_chstatueboss -> int[], D_808027F8_chstatueboss -> s32[], D_80802850_chstatueboss -> u8[], D_8080285C_chstatueboss -> s32[], D_80802894_chstatueboss -> s32[] */
s16 D_808025C0_chstatueboss[5][6] = { 0x8, 0x9, 0xA, 0xB, 0xC, -0x1, 0xD, 0xE, 0xF, 0x10, -0x1, 0x0, 0x11, 0x12, 0x13, -0x1, 0x0, 0x0, 0x14, 0x15, -0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
s16 D_808025FC_chstatueboss[5][4] = { -0x1, 0x0, 0x0, 0x0, 0x4, -0x1, 0x0, 0x0, 0x5, 0x6, -0x1, 0x0, 0x7, 0x8, 0x9, -0x1, 0x0, 0x0, 0x0, 0x0 };
s16 D_80802624_chstatueboss[6] = { 0x3, 0x4, 0x5, 0x6, 0x7, 0x0 };
f32 D_80802630_chstatueboss[5] = { 3e+01f, -5e+01f, 7e+01f, -9e+01f, 1.1e+02f };
u8 D_80802644_chstatueboss[8] = { 0x0, 0x4, 0x0, 0x4, 0x0, 0x4, 0x0, 0x4 };
f32 D_8080264C_chstatueboss[4] = { 0.0f, 2.4e+03f, 2.8e+03f, 3.2e+03f };
u8 D_8080265C_chstatueboss[12] = { 0x0, 0x35, 0x0, 0x41, 0x0, 0x40, 0x0, 0x50, 0x0, 0x51, 0x0, 0x4F };
u8 D_80802668_chstatueboss[8] = { 0x0, 0x13, 0x4, 0xAC, 0x0, 0x2, 0x0, 0x0 };
u8 D_80802670_chstatueboss[216] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x20, 0x0, 0x0, 0x3, 0x9, 0x0, 0x44, 0x40, 0x20, 0x0, 0x0, 0x3, 0x9, 0x0, 0x44, 0x40, 0x20, 0x0, 0x0, 0x3, 0x9, 0x0, 0x2, 0x40, 0x66, 0x66, 0x66, 0x3, 0xA, 0x0, 0x1, 0x40, 0xA0, 0x0, 0x0, 0x3, 0x3, 0x2, 0x2, 0x40, 0x66, 0x66, 0x66, 0x3, 0x4, 0x0, 0x1, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x5, 0x0, 0x44, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x5, 0x0, 0x2, 0x40, 0x66, 0x66, 0x66, 0x3, 0x20, 0x0, 0x1, 0x40, 0x66, 0x66, 0x66, 0x3, 0x4, 0x0, 0x1, 0x3F, 0x8C, 0xCC, 0xCD, 0x3, 0x6, 0x0, 0x44, 0x3F, 0x8C, 0xCC, 0xCD, 0x3, 0x6, 0x0, 0x2, 0x40, 0x66, 0x66, 0x66, 0x3, 0x21, 0x0, 0x1, 0x40, 0x66, 0x66, 0x66, 0x3, 0x20, 0x0, 0x1, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x7, 0x0, 0x44, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x7, 0x0, 0x2, 0x40, 0x66, 0x66, 0x66, 0x3, 0x22, 0x0, 0x1, 0x40, 0x66, 0x66, 0x66, 0x3, 0x21, 0x0, 0x1, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x8, 0x0, 0x44, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x8, 0x0, 0x2, 0x40, 0x66, 0x66, 0x66, 0x3, 0xA, 0x0, 0x1, 0x40, 0x66, 0x66, 0x66, 0x3, 0x22, 0x0, 0x1, 0x40, 0x66, 0x66, 0x66, 0x3, 0xA, 0x0, 0x1, 0x40, 0x53, 0x33, 0x33, 0x3, 0xB, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x66, 0x66, 0x66, 0x3, 0x4, 0x0, 0x1 };
void *D_80802748_chstatueboss = (void *)0x01BC0447;
static u32 D_80802748_chstatueboss_rest[17] = { 0x7F40001, (u32)&D_80802670_chstatueboss, (u32)func_80800298_chstatueboss, (u32)func_80105834, (u32)func_80800B74_chstatueboss, 0x752F, 0x0, 0x0, 0x560, 0x0, (u32)func_80108ED0, 0x1D40000, (u32)func_8080000C_chstatueboss, (u32)func_80107C2C, 0x80800402, (u32)func_80800934_chstatueboss, 0x0 };
s32 D_80802790_chstatueboss[7] = { 0x1304CC, 0xD00F3, 0x10C0002, 0x0, 0x1304F9, 0xA00C0, 0x20000 };
u8 D_808027AC_chstatueboss[20] = { 0x3D, 0xCC, 0xCC, 0xCD, 0x3E, 0x61, 0x47, 0xAE, 0x3E, 0xB3, 0x33, 0x33, 0x3F, 0x0, 0x0, 0x0, 0xBF, 0x80, 0x0, 0x0 };
s16 D_808027C0_chstatueboss[4] = { 0xA, 0xE, 0x12, 0x16 };
u8 D_808027C8_chstatueboss[12] = { 0x0, 0x13, 0x4, 0xF9, 0x0, 0xA, 0x0, 0xD9, 0x0, 0x2, 0x0, 0x0 };
s16 D_808027D4_chstatueboss[6] = { 0x2A, 0x2E, 0x36, 0x42, 0x52, 0x0 };
u8 D_808027E0_chstatueboss[8] = { 0x0, 0x8, 0x0, 0xC, 0x0, 0x10, 0x0, 0x14 };
int D_808027E8_chstatueboss[4] = { 0x0, 0x0, 0x0, (u32)func_80801724_chstatueboss };
s32 D_808027F8_chstatueboss[3] = { 0x1304AD, 0x1661A8, 0x20000 };
u8 D_80802804_chstatueboss[24] = { 0x3E, 0xCC, 0xCC, 0xCD, 0x3F, 0x1C, 0x28, 0xF6, 0x3F, 0x42, 0x8F, 0x5C, 0x3F, 0x5E, 0xB8, 0x52, 0x3F, 0x7D, 0x70, 0xA4, 0xBF, 0x80, 0x0, 0x0 };
u8 D_8080281C_chstatueboss[20] = { 0x3F, 0x33, 0x33, 0x33, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0xC, 0xCC, 0xCD, 0x3F, 0x0, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0 };
u8 D_80802830_chstatueboss[20] = { 0x46, 0xFA, 0x0, 0x0, 0x46, 0xEA, 0x60, 0x0, 0x46, 0xDA, 0xC0, 0x0, 0x46, 0xCB, 0x20, 0x0, 0x46, 0xC3, 0x50, 0x0 };
u8 D_80802844_chstatueboss[12] = { 0x0, 0x13, 0x4, 0xBA, 0x0, 0x2, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x0 };
u8 D_80802850_chstatueboss[12] = { 0x0, 0x13, 0x4, 0xF9, 0x0, 0xA, 0x0, 0xC0, 0x0, 0x2, 0x0, 0x0 };
s32 D_8080285C_chstatueboss[14] = { 0x1D09DD, 0x2B0300, 0x4000022, 0x2800380, 0x4800580, 0x150000, 0x990019, 0x7, 0x2D0064, 0x96001F, -0x21588F00, 0xB0096, 0xC80064, 0xA0000 };
s32 D_80802894_chstatueboss[3] = { 0x130413, 0x180002, 0x0 };
