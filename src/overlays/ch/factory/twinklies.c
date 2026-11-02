#include "common.h"

extern int D_80802218_chfactorytwinklies;
extern int D_80802260_chfactorytwinklies;
extern int D_808022A8_chfactorytwinklies;
extern int D_80802338_chfactorytwinklies;
extern int D_80802380_chfactorytwinklies;
extern void *func_80100094(Actor *, u32);
extern u32 func_800FDC28(u32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern s32 func_800D211C(s32);
typedef struct TwinklieNodeIndex { u8 pad_0[0x70]; u32 local_0 : 7; u32 pad_1 : 25; } TwinklieNodeIndex;
typedef struct TwinklieMarkerFlag { u8 pad_0[0x2A]; u8 pad_1 : 2; u8 local_0 : 1; u8 pad_2 : 5; } TwinklieMarkerFlag;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800FC6B0(u32);
typedef struct { s32 local_0[16]; s32 local_1[4][3]; } TwinkliesPlayers;
typedef union { s32 word; s16 halves[2]; } TwinklyEventArg;
typedef struct { s32 local_0[8]; s32 local_1[8]; u8 local_2[0x60]; s32 local_3; } Mass47Twinklies;
typedef struct { u8 pad[0x28]; s32 f28; s32 f2C; u8 pad30[0x46]; u16 f76:9; u16 pad76:7; } TwinkS;
typedef struct { s32 total[4]; u8 pad10[0x30]; s32 cnt[4][3]; } TwinkData;
extern void func_800F5A2C(s32, s32, f32 *);
extern void func_80102FDC(Actor *, f32);
typedef union { s32 local_0; Unk80132ED0 *local_1; } TemplateEventValue1161;
extern u8 D_8080243C_chfactorytwinklies[];
extern s16 D_80802478_chfactorytwinklies[];
extern u8 D_80802468_chfactorytwinklies[];
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800BA22C(s32, s32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9078();
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800DC0C0(void);
extern s32 func_800D9154(f32 *, f32);
extern void func_800F7ECC(s32, s32, f32);
extern s32 func_800F54E4(void);
extern void func_800F82D4(s32, s32);
extern void _susubgame_entrypoint_4(Actor *, void *);
extern s32 _susubgame_entrypoint_10(Actor *, s32, s32, s32);
extern void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
extern void _chintrotext_entrypoint_2(s32);
extern void _chmrtannoy_entrypoint_0(void);
extern void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern s32 _susubgame_entrypoint_3(Actor *, void *, s32, s32);
extern s32 func_800D395C(void);
extern void func_800CE8D8(s32, f32, s32);
typedef struct { u8 pad_0[0x40]; s32 local_0[4][3]; } TwinkliesCounterState;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F849C(s32, f32);
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 18; u32 flag : 1; u32 pad_2 : 13; } TW28;
extern void func_8010A3E8(Actor *, f32);
extern void func_800C8E54(s32, f32, f32);
extern u8 D_808023C8_chfactorytwinklies[];
extern u8 D_808023EC_chfactorytwinklies[];
extern u8 D_80802400_chfactorytwinklies[];
typedef struct { u8 pad[0x64]; u8 p64:7; u8 b64_0:1; u8 p65a:4; u8 b65_3:1; u8 p65b:3; u8 pad66[0xF]; u8 p75a:3; u8 b75_4:1; u8 p75b:4; } TwC;
typedef struct { u8 pad[0x28]; u32 hi : 18; u32 b13 : 1; u32 lo : 13; } TwA;
typedef struct { u8 pad[0x64]; u32 b31 : 1; u32 b30 : 1; u32 b29 : 1; u32 mid : 9; u32 b19 : 1; u32 rest : 19; } TwB;
extern u8 D_808021C0_chfactorytwinklies[];
extern u8 D_80802414_chfactorytwinklies[];
extern u8 D_80802428_chfactorytwinklies[];
extern f32 func_800D8FF8(void);
extern s32 func_800CEAD0(s32);
extern void *_chlightfader_entrypoint_1();
extern void func_8010A570(void *);
extern void func_80101FDC(void *, s32);
extern void _subaddiefade_entrypoint_3(void *);
extern f32 func_80101F24(void *);
extern f32 func_800F3780(f32, void *, s32);
extern s32 func_80101E14(void *, s32);
extern void func_8010D930(s32, s32, void *, void *);
extern f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
extern void func_80102BF8(void *, s32, s32, s32);
extern void func_8010C3A8(void *, s32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 _subaddierouteDll_entrypoint_4(void *);
extern void _subaddierouteDll_entrypoint_7(void *, void *, s32, s32, f32, s32);
extern void _subaddierouteDll_entrypoint_6(void *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(void *, void *, s32, s32, f32, f32);
extern void func_800FFAB0(void *);
extern void func_80103DFC(void *, f32 *);
extern void func_800C8CB8(void *, f32 *);
extern f32 func_80013970(f32);
extern void func_800EFE50(void *, void *, void *, f32);
int func_80801108_chfactorytwinklies();
int func_80801174_chfactorytwinklies();
s32 func_80801608_chfactorytwinklies();
void func_80801DD8_chfactorytwinklies();
void func_808006C0_chfactorytwinklies();
void func_80800D00_chfactorytwinklies();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080145C_chfactorytwinklies();
extern u8 D_808021E8_chfactorytwinklies[];
extern void *D_808022F0_chfactorytwinklies[];

int chfactorytwinklies_entrypoint_0()
{
    return (int)&D_80802218_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_1()
{
  return &D_80802260_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_2()
{
  return &D_808022A8_chfactorytwinklies;
}

s32 chfactorytwinklies_entrypoint_3()
{
    return (s32)&D_808022F0_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_4()
{
    return (int)&D_80802338_chfactorytwinklies;
}

int chfactorytwinklies_entrypoint_5()
{
    return (int)&D_80802380_chfactorytwinklies;
}

void func_80800048_chfactorytwinklies(Actor *param_0)
{
    u8 *local_0 = (u8 *)func_80100094(param_0, 0);
    s32 local_2;
    s32 local_1 = func_800F54E4();

    for (local_2 = 0; local_2 < _gcstatusDll_entrypoint_11(); local_2++) {
        ((s32 *)local_0)[local_2] = 0;
        ((s32 (*)[3])(local_0 + 0x40))[local_2][0] = 0;
        ((s32 (*)[3])(local_0 + 0x40))[local_2][1] = 0;
        ((s32 (*)[3])(local_0 + 0x40))[local_2][2] = 0;
    }
    func_800946C4(func_800F53D0(local_1), 1);
    _susubgame_entrypoint_0(param_0, local_0 + 0xAC, 0);
    _susubgame_entrypoint_11(0);
    func_800A16BC(1);
    switch (func_800F5410(local_1)) {
        case 10: func_800D2748(0xEF, 0x57); break;
        case 11: func_800D2748(0xEF, 0x58); break;
        case 13: func_800D2748(0xEF, 0x59); break;
        case 7: func_800D2748(0xEF, 0x5A); break;
        default: func_800D2748(0xEF, 0x5B); break;
    }
}

s32 func_80800B80_chfactorytwinklies();

void func_808001A0_chfactorytwinklies(Actor *param_0)
{
    u8 *local_0;
    s32 local_2;
    s32 local_1;
    f32 local_3;
    s32 local_4;
    s32 *local_5;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 3:
        local_1 = func_800F54E4();
        func_800D2498(0xEF, ((s32 *)local_0)[local_1], 0);
        local_5 = (s32 *)((u8 *)local_0 + local_1 * 12);
        for (local_4 = 0; local_4 < 3; local_4++) {
            func_800D2498(local_4 + 0xF0, *(local_5 + 0x10), 0);
            local_5++;
        }
        func_80800D00_chfactorytwinklies(param_0);
        if (func_800CEAD0(0)) {
            *(s32 *)(local_0 + 0xA4) = func_80800B80_chfactorytwinklies(param_0, local_0 + 0xA8);
            func_800F7ECC(func_800F54E4(), 3, 0.0f);
            func_800F8300(func_800F54E4(), 2, 0);
            func_80101FDC(param_0, 4);
            return;
        }
        if (func_800D9154(&param_0->unk58, func_800DC178(1.0f, 1.199996948f))) {
            local_3 = func_800DC0C0();
            if (local_3 < 0.1666f) local_2 = 0;
            else if (local_3 < 0.5f) local_2 = 1;
            else local_2 = 2;
            func_80108B04(param_0, local_2);
            return;
        }
        break;
    case 1:
        return;
    case 4:
        if (_susubgame_entrypoint_9()) {
            _susubgame_entrypoint_5(param_0, local_0 + 0xAC, 5, 1, 0);
            if (1) {}
            _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *)(local_0 + 0xA4),
                                         *(s32 *)(local_0 + 0xA8), 0, 0xA3);
            func_80101FDC(param_0, 5);
            return;
        }
        break;
    case 7:
        if (func_800D0B68(0x3B, 1)) {
            func_800F8300(func_800F54E4(), 2, 0);
            if (1) {}
            *(s32 *)(local_0 + 0xA4) = 0xCEB;
            *(s32 *)(local_0 + 0xA8) = 0x46;
            func_80101FDC(param_0, 4);
        }
        break;
    }
}

void func_80800A84_chfactorytwinklies();

s32 func_808009EC_chfactorytwinklies();

void func_80800748_chfactorytwinklies();

s32 func_8080040C_chfactorytwinklies(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2E:
        func_80800748_chfactorytwinklies(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x30:
        return func_808009EC_chfactorytwinklies(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x3D:
        func_80800A84_chfactorytwinklies(param_0, param_2);
        return 1;
    case 0xB:
        if (param_2 == 0x15) {
            func_800F82D4(func_800F54E4(), 0);
            func_80101FDC(param_0, 7);
            _susubgame_entrypoint_4(param_0, local_0 + 0xAC);
            return 4;
        }
        return 3;
    case 0x49:
        if (_susubgame_entrypoint_10(param_0, 1, 800, 456)) {
            _susubgame_entrypoint_6(param_0, local_0 + 0xAC, 0, 0x20, 0);
            _chintrotext_entrypoint_2(1);
            return 1;
        }
        _chmrtannoy_entrypoint_0();
        _susubgame_entrypoint_5(param_0, local_0 + 0xAC, 5, 1, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, param_0->position, 0xA3);
        func_800F82D4(func_800F54E4(), 2);
        return 1;
    case 0x57:
        return _susubgame_entrypoint_3(param_0, local_0 + 0xAC, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x32:
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(param_0->unk0, func_800D395C() ? 0x1385 : 0x1344, 0x46, param_0->position, 0xA3);
        func_800F82D4(func_800F54E4(), 2);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080064C_chfactorytwinklies(param_0) Actor *param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_800A16BC(0);
    if (func_800CEAA8(0)) {
        func_800CE88C(0, 0);
    }
    if (_susubgame_entrypoint_2(param_0, local_0 + 0xAC)) {
        _susubgame_entrypoint_4(param_0, local_0 + 0xAC);
    }
    func_800FDC28(0);
}

void func_808006C0_chfactorytwinklies(param_0) Actor *param_0;
{
    f32 local_0 = 60.0f;
    _subaddiemulti_entrypoint_2(param_0);
    func_80101FDC(param_0, 3);
    func_800CE8D8(0, local_0, (s32)local_0);
    func_800CE88C(0, 1);
    param_0->unk58 = 0.01f;
    if (func_800DA298(0x6A7)) _subaddiemulti_entrypoint_4(0x17);
    func_800FDC28(12);
}

void func_80800748_chfactorytwinklies(Actor *param_0, s32 param_1, s32 param_2) {
    u8 *local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {                                 
    case 0x1344:
    case 0x1385:
        if (param_2 > 0) {
            _susubgame_entrypoint_6(param_0, local_0 + 0xAC, 6, 0x20, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1345, 0x44, 0, 0xA3);
            func_80108B04(param_0, 0);
        } else {
            _susubgame_entrypoint_5(param_0, local_0 + 0xAC, 5, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0xA3);
        }
        _gcfrontend_entrypoint_9(0x6D);
        return;
    case 0x1345:
        _susubgame_entrypoint_5(param_0, local_0 + 0xAC, 5, 1, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0xA3);
        return;
    case 0xCEB:
        func_800F82D4(func_800F54E4(), 0);
        func_80101FDC(param_0, 6);
        if (func_800D395C() != 0) {
            if (param_2 > 0) {
                _gcfrontend_entrypoint_11();
                return;
            }
            _gcfrontend_entrypoint_10();
            return;
        }
        if (param_2 > 0) {
            _gcgoto_entrypoint_1(0x10A, 1);
            return;
        }
        local_1 = _subaddiefind_entrypoint_2(0x21A, 0);
        if (local_1 != 0) {
            _subaddiefade_entrypoint_3(local_1);
            func_8010A570(local_1);
        }
        _susubgame_entrypoint_4(param_0, local_0 + 0xAC);
        return;
    case 0xCEC:
        _susubgame_entrypoint_4(param_0, local_0 + 0xAC);
        func_808006C0_chfactorytwinklies(param_0);
        return;
    case 0x1346:
        _susubgame_entrypoint_6(param_0, local_0 + 0xAC, 0x15, 0x10, 0);
        func_800D1000(0x3B, 1, 0, 1, 0);
        return;
    case 0x1347:
    case 0x1374:
    case 0x1375:
    case 0x1376:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, 0, 0xA3);
        return;
    }
}

s32 func_808009EC_chfactorytwinklies(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x1347:
        return local_0[func_800F54E4()];
    case 0x1345:
        return 0x28;
    case 0x1375:
    case 0x1385:
        return func_800D211C(0x83);
    }
    return 0;
}

void func_80800A84_chfactorytwinklies(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    Actor *local_1;
    f32 local_2[3];
    s32 local_3;

    switch (param_1) {
        case 0:
        case 1:
        case 2:
            local_0 = func_80100094(param_0, 0);
            if (_susubgame_entrypoint_2(param_0, local_0 + 0xAC)) {
                func_800EE7F8(local_2, param_0->position);
            } else {
                func_800CD08C(((TwinklieNodeIndex *)param_0)->local_0 - 1, local_2);
            }
            local_2[1] = 0.0f;
            local_3 = func_800DC128(0, 359);
            local_1 = func_80108528(param_1 + 0x443, local_2, local_3, &param_0);
            local_1->unk3C = param_0->unk0;
            local_1->actorData[5] = param_1;
            ((TwinklieMarkerFlag *)local_1->unk0)->local_0 = _susubgame_entrypoint_2(param_0, local_0 + 0xAC);
            break;
    }
}

s32 func_80800B80_chfactorytwinklies(Actor *param_0, s32 *param_1)
{
    s32 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    u32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;

    local_0 = func_80100094(param_0, 0);
    local_1 = local_0[func_800F54E4()];
    local_6 = func_800D0A9C(0x3B, 1);
    local_7 = func_800D395C();
    local_8 = func_800D2054(0, 0x83, local_1);
    local_3 = local_8 == 1 && (local_6 || local_7);
    local_4 = local_1 >= 40;
    local_5 = local_4 && !local_6 && !local_7;
    func_800FDC28(0);
    func_800FC6B0((local_5 || local_3) ? 0x16 : 0x17);
    *param_1 = 6;
    if (local_5) {
        local_2 = 0x1346;
    } else if (local_3) {
        local_2 = 0x1347;
    } else if (!func_800D395C()) {
        if (local_6) {
            if (local_8 == 0) local_2 = 0x1376;
            else local_2 = 0x1375;
        } else {
            local_2 = 0x1374;
        }
    } else {
        local_2 = 0xCEB;
        *param_1 = 0x46;
    }
    return local_2;
}

void func_80800D00_chfactorytwinklies(param_0) Actor *param_0;
{
    TwinkliesCounterState *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = (TwinkliesCounterState *)func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < _gcstatusDll_entrypoint_11(); local_1++) {
        local_2 = local_0->local_0[local_1][0] + local_0->local_0[local_1][1] + local_0->local_0[local_1][2];
        func_800F849C(local_1, func_800F10B4((f32)local_2, 0.0f, 10.0f, 1.0f, 0.6f));
    }
}

void func_80800DE0_chfactorytwinklies(param_0) Actor *param_0;
{
    TwinkliesPlayers *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    func_800A16BC(1);
    for (local_1 = 0; local_1 < _gcstatusDll_entrypoint_11(); local_1++) {
        local_0->local_0[local_1] = 0;
        local_0->local_1[local_1][0] = 0;
        local_0->local_1[local_1][1] = 0;
        local_0->local_1[local_1][2] = 0;
        func_800946C4(func_800F53D0(local_1), 1);
        func_800D2748(local_1 + 0xC3, local_1 + 0x5B);
    }
    _subaddiemulti_entrypoint_3(10);
}

void func_808013BC_chfactorytwinklies();

void func_808011B0_chfactorytwinklies();

void func_80800E9C_chfactorytwinklies(Actor *param_0)
{
    s32 local_0;
    s32 local_3;
    s32 local_1;
    s32 local_6;
    f32 local_4;
    f32 local_2;
    local_1 = param_0->unk70_10;
    switch (local_1) {
    case 1:
        if (!func_800C954C() && !func_800DA298(0x6AD)) {
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0xA3);
            func_80101FDC(param_0, 2);
        }
        break;
    case 3:
        func_808013BC_chfactorytwinklies(param_0, 0);
        func_80800D00_chfactorytwinklies(param_0);
        if (func_800CEAD0(0)) { func_808011B0_chfactorytwinklies(param_0); break; }
        local_6 = _subaddiefind_entrypoint_9(0x444);
        local_1 = _subaddiefind_entrypoint_9(0x443);
            if (1) {}
        if (_subaddiefind_entrypoint_9(0x445) + local_1 + local_6 < 4) {
            local_2 = func_800DC178(1.0f, 1.199997f);
            if (func_800D9154(&param_0->unk58, local_2 / _gcstatusDll_entrypoint_11())) {
                local_4 = func_800DC0C0();
                if (local_4 < 0.25f) local_3 = 0;
                else if (local_4 < 0.6f) local_3 = 1;
                else local_3 = 2;
                func_80108B04(param_0, local_3);
            }
        }
        break;
    case 5:
    case 6: func_808013BC_chfactorytwinklies(param_0, 1); break;
    }
}

s32 func_8080105C_chfactorytwinklies(Actor *param_0, s32 param_1, TwinklyEventArg param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80801108_chfactorytwinklies(param_0, param_2.halves[0], param_2.halves[1]);
            break;
        case 0x30:
            return func_80801174_chfactorytwinklies(param_0, param_2.halves[0], param_2.halves[1]);
        case 0x3D:
            func_80800A84_chfactorytwinklies(param_0, param_2.word);
            break;
        case 0x95:
            _subaddiemulti_entrypoint_1(0, 0);
            _subaddiemulti_entrypoint_4(0);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80801108_chfactorytwinklies(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  switch (param_1)
  {
    case 0xCEC:
      func_808006C0_chfactorytwinklies((Actor *)param_0);
      break;

    case 0x1348:

    case 0x1349:
      if (param_0)
    {
    }
      _subaddiemulti_entrypoint_2(param_0);
      func_80101FDC(param_0, 6);
      _gcfrontend_entrypoint_10();

  }

}

int func_80801174_chfactorytwinklies(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0x1348)
  {
    return *(s32 *)((u8 *)func_80100094(param_0, 0) + 0xA0) + 1;
  }
  return 0;
}

void func_808011B0_chfactorytwinklies(Actor *param_0)
{
    Mass47Twinklies *local_6;
    s32 local_0[8];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_7;

    local_6 = func_80100094(param_0, 0);
    local_4 = -1;
    for (local_1 = 0; local_1 < _gcstatusDll_entrypoint_11(); local_1++) {
        local_0[local_1] = local_6->local_0[local_1];
        if (local_4 < local_0[local_1]) {
            local_4 = local_0[local_1];
        }
        func_800AA20C(local_1, local_0[local_1]);
    }
    for (local_1 = 0; local_1 < _gcstatusDll_entrypoint_11(); local_1++) {
        if (local_4 == local_0[local_1]) {
            local_6->local_1[local_1] = 1;
        }
    }
    for (local_7 = 1; local_7 < _gcstatusDll_entrypoint_11(); local_7++) {
        for (local_2 = local_7; local_2 > 0 &&
             local_0[local_2 - 1] < local_0[local_2]; local_2--) {
            local_3 = local_0[local_2];
            local_0[local_2] = local_0[local_2 - 1];
            local_0[local_2 - 1] = local_3;
        }
    }
    func_800FC6B0(0x16);
    if (local_0[0] != local_0[1]) {
        for (local_2 = 0; local_6->local_0[local_2] != local_0[0]; local_2++) {
        }
        local_6->local_3 = local_2;
        local_5 = 0x1348;
    } else {
        local_5 = 0x1349;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    func_80101FDC(param_0, 5);
    _subaddiedialog_entrypoint_11(param_0->unk0, local_5, 6, 0, 0xA3);
}

void func_808013BC_chfactorytwinklies(Actor *param_0, s32 param_1)
{
    s32 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < _gcstatusDll_entrypoint_11(); local_1++) {
        func_800D24E8(local_1 + 0xC3, local_0[local_1], 0);
        if (param_1 && local_0[local_1 + 8]) func_800D28A0(local_1 + 0xC3);
    }
}

void func_8080145C_chfactorytwinklies(param_0) TwinkS *param_0; {
    s32 local_0 = param_0->f76 - 0x32;
    param_0->f2C = local_0;
    switch (local_0) {
    case 0:
        param_0->f28 = 0x20000000;
        break;
    case 1:
        param_0->f28 = 0x10000000;
        break;
    case 2:
        param_0->f28 = 0x8000000;
        break;
    }
}

void func_808014B0_chfactorytwinklies(Actor *param_0)
{
    s32 *p;
    s32 *row; /* unused: frame slot only */
    s32 pts;
    TwinkData *data;
    s32 j; /* unused: frame slot only */
    s32 n;
    s32 local_0;
    s32 i;
    data = func_80100094(func_80106790(param_0->unk3C), 0);
    if (func_800CEAA8(0) && !func_800CEAD0(0)) {
        for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
            if (func_800F6C5C(i) && (func_800F55FC(i) & param_0->actorData[4])) {
                n = data->cnt[i][param_0->actorData[5]];
                if (n > 0) {
                    pts = (3 - param_0->actorData[5]) * n;
                    p = &data->total[i];
                    *p += pts;
                    data->cnt[i][param_0->actorData[5]] = 0;
                    func_800F5A2C(i, 5, &local_0);
                    _chscorepoints_entrypoint_2(pts, i, &local_0, 1);
                    func_80108B04(param_0, i);
                }
            }
        }
    }
}

s32 func_80801608_chfactorytwinklies(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    Actor *local_1;
    f32 local_2[3];
    Actor *local_3;
    switch (param_1) {
    case 0x3D:
        func_800F5A2C(param_2, 5, local_2);
        local_1 = func_80108528(*(s32 *)((u8 *)param_0 + 0x2C) + 0x443, local_2, func_800DC128(0, 0x167), &param_0);
        local_0 = (u8 *)func_80100094(local_1, 0);
        func_800EE7F8((f32 *)(local_0 + 0x1C), param_0->position);
        func_800EE7F8((f32 *)(local_0 + 0x10), local_2);
        func_80101FDC(local_1, 5);
        func_80102FDC(local_1, 0.2f);
        break;
    case 0x95:
        if (func_800EA05C() == 0x17D) local_3 = _subaddiefind_entrypoint_2(0x44D, 0);
        else local_3 = _subaddiefind_entrypoint_2(0x442, 0);
        param_0->unk3C = local_3->unk0;
        break;
    default:
        return 0;
    }
    return 1;
}

f32 func_80801FAC_chfactorytwinklies();

f32 func_80801ED0_chfactorytwinklies();

void func_8080171C_chfactorytwinklies(param_0) Actor *param_0;
{
    u8 *local_0;
    local_0 = (u8 *)func_80100094(param_0, 0);
    func_8010A3E8(param_0, 0.3f);
    if (param_0->unk70_10 == 1) {
        param_0->position[1] -= 250.0f;
        *(f32 *)((u8 *)param_0 + 0x28) = 0.6f;
        *(f32 *)((u8 *)param_0 + 0x30) = func_80801ED0_chfactorytwinklies(param_0);
        *(f32 *)((u8 *)param_0 + 0x58) = func_80801FAC_chfactorytwinklies(param_0);
        _subaddieDll_entrypoint_1(param_0);
        _subaddierouteDll_entrypoint_3(param_0, local_0, param_0->position);
        _subaddierouteDll_entrypoint_1(param_0);
        *(s32 *)(local_0 + 12) = 0;
        *(s32 *)((u8 *)param_0 + 0x50) = func_800C8A98();
        func_800C8E54(*(s32 *)((u8 *)param_0 + 0x50), 500.0f, 800.0f);
        func_800C8E84(*(s32 *)((u8 *)param_0 + 0x50), D_808023C8_chfactorytwinklies + *(s32 *)((u8 *)param_0 + 0x2C) * 12);
        if (((TW28 *)param_0->unk0)->flag) {
            ((u8 *)param_0)[0x64] &= ~1;
            *(f32 *)((u8 *)param_0 + 0x58) = 5.5f;
        }
        func_8010D930(4, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_808023EC_chfactorytwinklies);
    } else {
        func_8010D930(4, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_80802400_chfactorytwinklies);
        func_8010A570(param_0);
        *(f32 *)((u8 *)param_0 + 0x58) = 1.2f;
        ((u8 *)param_0)[0x64] &= ~1;
    }
}

s32 func_8080207C_chfactorytwinklies();

s32 func_80802020_chfactorytwinklies();

f32 func_80801F5C_chfactorytwinklies();

void func_808018A0_chfactorytwinklies(u8 *param_0)
{
    void *local_5C;
    f32 local_58;
    f32 local_54;
    f32 local_50;
    f32 tmp;
    s32 done;
    f32 local_44;
    f32 local_38[3];
    local_5C = func_80100094(param_0, 0);
    local_58 = func_800D8FF8();
    if (((u32) (*((u16 *) (param_0 + 0x72)))) >> 10 != 4) {
        if (func_800CEAD0(0) != 0 && !((TwA *) *((u8 **) param_0))->b13) {
            if (*((void **) (param_0 + 0x50)) != NULL) {
                *((void **) (param_0 + 0x50)) = _chlightfader_entrypoint_1(*((void **) (param_0 + 0x50)), 0x3F266666, 2);
            }
            func_8010A570(param_0);
            func_80101FDC(param_0, 4);
            _subaddiefade_entrypoint_3(param_0);
        }
    }
    switch ((((u32) (*((u16 *) (param_0 + 0x72)))) >> 10)) {
        case 1:
            if (func_80802020_chfactorytwinklies(param_0) != 0) {
                func_80101FDC(param_0, 2);
            }
            break;

        case 2:
            local_54 = func_800F3780(func_80101F24(param_0), D_808021C0_chfactorytwinklies, 5);
            if (func_80101E14(param_0, 0x3E800000) != 0) {
                func_8010D930(2, *((u32 *) (param_0 + 0x70)) & 1, param_0 + 4, D_80802414_chfactorytwinklies);
            }
            if (((TwB *) param_0)->b29) {
                local_50 = _subaddiejoy_entrypoint_9(param_0, param_0 + 0x54, 3);
                *((f32 *) (param_0 + 0x24)) = func_80801F5C_chfactorytwinklies(param_0) * 1.4f;
                func_80102BF8(param_0, 0x3E4CCCCD, 0x41000000, 0x44160000);
                func_8010C3A8(param_0, 0x201025, local_50 * local_54);
            } else {
                if (_subaddierouteDll_entrypoint_4(param_0) != 0) {
                    _subaddierouteDll_entrypoint_7(param_0, local_5C, *((s32 *) (param_0 + 0x48)),
                        *((s32 *) (param_0 + 0x54)), 400.0f, 0x4802);
                    *((s32 *) ((u8 *) local_5C + 0xC)) = (s32) (*((u16 *) ((u8 *) local_5C + 6)));
                }
                _subaddierouteDll_entrypoint_6(param_0, local_5C, *((s32 *) ((u8 *) local_5C + 0xC)),
                    0x3F, 0.4f, 20, 40);
                _subaddierouteDll_entrypoint_5(param_0, local_5C, *((s32 *) ((u8 *) local_5C + 0xC)),
                    0x3E4CCCCD, 4.0f, 200.0f);
                *((f32 *) (param_0 + 0x24)) = func_800F15F8(*((f32 *) (param_0 + 0x24)), *((f32 *) (param_0 + 0x30)), local_58 * 800.0f);
                if (!((TwA *) *((u8 **) param_0))->b13) {
                    func_8010C3A8(param_0, 0x1325, local_54);
                }
            }
            if (func_800D9078(param_0 + 0x58) != 0) {
                if (*((void **) (param_0 + 0x50)) != NULL) {
                    *((void **) (param_0 + 0x50)) = _chlightfader_entrypoint_1(*((void **) (param_0 + 0x50)), 0x3F800000, 2);
                }
                func_80101FDC(param_0, 3);
                *((f32 *) (param_0 + 0x28)) = 0.6f;
                param_0[0x64] = param_0[0x64] & ~1;
            }
            break;

        case 3:
            if (!(((TwB *) param_0)->b19)) {
                tmp = func_800F10B4(*((f32 *) (param_0 + 0x28)), 0.0f, 0.6f, 1.0f, 0.0f);
                if (0.3f < tmp) {
                    param_0[0x75] = param_0[0x75] & ~0x10;
                    func_8010D930(5, *((u32 *) (param_0 + 0x70)) & 1, param_0 + 4, D_80802428_chfactorytwinklies);
                    ((TwC *) param_0)->b65_3 = 1;
                }
            }
            if (func_8080207C_chfactorytwinklies(param_0) != 0) {
                func_800FFAB0(param_0);
            }
            break;

        case 4:
            break;

        case 5:
            done = func_800D9078(param_0 + 0x58);
            local_44 = func_800F12D4(*((f32 *) (param_0 + 0x58)), 0.0f, 1.2f, 1.0f, 0.0f);
            *((f32 *) (param_0 + 0x44)) += func_800D8FF8() * 100.0f;
            *((f32 *) (param_0 + 0x48)) += func_800D8FF8() * 60.0f;
            tmp = func_800D8FF8();
            *((f32 *) (param_0 + 0x38)) = func_800F15F8(*((f32 *) (param_0 + 0x38)), 1.0f, tmp + tmp);
            func_800EFE50(param_0 + 4, (u8 *) local_5C + 0x10, (u8 *) local_5C + 0x1C, local_44);
            *((f32 *) (param_0 + 8)) += 80.0f * func_80013970(local_44 * 180.0f);
            if (done != 0) {
                func_800FFAB0(param_0);
            }
            break;

        default:
            break;
    }
    if (*((void **) (param_0 + 0x50)) != NULL) {
        func_80103DFC(param_0, local_38);
        local_38[1] = local_38[1] + 100.0f;
        func_800C8CB8(*((void **) (param_0 + 0x50)), local_38);
    }
}

void func_80801D58_chfactorytwinklies(param_0) u8 *param_0;
{
  int new_var;
  s32 new_var2;
  s32 temp_a3;
  if (param_0)
  {
  }
  new_var2 = *((s32 *) (((u8 *) param_0) + 0x50));
  temp_a3 = *((s32 *) (((u8 *) param_0) + 0x50));
  if (temp_a3 != 0)
  {
    new_var = 0x50;
    *((s32 *) (((u8 *) param_0) + new_var)) = _chlightfader_entrypoint_1(new_var2, 0x3F800000, 2, *((s32 *) (((u8 *) param_0) + 0x50)));
  }
}

s32 func_80801D94_chfactorytwinklies(Actor *param_0, s32 param_1, TemplateEventValue1161 param_2)
{
    switch (param_1) {
    case 0x3E:
        func_80801DD8_chfactorytwinklies(param_0, (u32)*(u16 *)((u8 *)param_2.local_1 + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801DD8_chfactorytwinklies(param_0, param_1) Actor *param_0; s32 param_1;
{
    Actor *local_3;
    u8 *local_0;
    s32 local_1;
    f32 local_2[3];

    local_3 = func_80106790(param_0->unk3C);
    local_0 = func_80100094(local_3, 0);
    local_1 = func_800B53A4(12);
    func_80103DFC(param_0, local_2);
    func_800BABB8(local_1, local_2, local_2, 1.0f, D_8080243C_chfactorytwinklies);
    func_800BA3FC(local_1, D_80802478_chfactorytwinklies[param_0->actorData[5]]);
    func_800BA22C(local_1, 12);
    (*(s32 (*)[3])(local_0 + 0x40 + param_1 * 12))[param_0->actorData[5]]++;
    func_8010D930(1, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_80802468_chfactorytwinklies);
    func_800FFAB0(param_0);
}

f32 func_80801ED0_chfactorytwinklies(Actor *param_0)
{
    switch (*(s32 *)&param_0->actorData[5]) {
        case 0:
            return func_800DC178(800.0f, 900.0f);
        case 1:
            return func_800DC178(600.0f, 700.0f);
        default:
            return func_800DC178(400.0f, 500.0f);
    }
}

f32 func_80801F5C_chfactorytwinklies(void *param_0) {
    s32 local_0;

    local_0 = *(s32 *)((char *)param_0 + 0x2C);
    switch (local_0) {
    case 0:
        return 900.0f;
    case 1:
        return 700.0f;
    default:
        return 500.0f;
    }
}

f32 func_80801FAC_chfactorytwinklies(Actor *param_0)
{
    switch (*(s32 *)&param_0->actorData[5]) {
        case 0:
            return func_800DC178(4.0f, 4.0f);
        case 1:
            return func_800DC178(4.0f, 4.0f);
        default:
            return func_800DC178(4.0f, 4.0f);
    }
}

s32 func_80802020_chfactorytwinklies(u8 *param_0) {
    s32 local_0 = func_800D9078(param_0 + 0x28);
    *(f32 *)(param_0 + 8) = func_800F12D4(*(f32 *)(param_0 + 0x28), 0.0f, 0.6f, 0.0f, -250.0f);
    return local_0;
}

s32 func_8080207C_chfactorytwinklies(u8 *param_0) {
    s32 local_0 = func_800D9078(param_0 + 0x28);
    *(f32 *)(param_0 + 8) = func_800F12D4(*(f32 *)(param_0 + 0x28), 0.0f, 0.6f, -250.0f, 0.0f);
    return local_0;
}
