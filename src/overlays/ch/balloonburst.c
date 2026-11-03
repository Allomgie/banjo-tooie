#include "common.h"

extern int D_80801C40_chballoonburst[];
extern int D_80801C88_chballoonburst[];
extern int D_80801CD0_chballoonburst[];
extern void *func_80100094(Actor *, u32);
extern s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
extern void func_800F82D4(s32, s32);
extern void func_800F7C58(s32, f32 *, s32);
extern void func_80101FDC(Actor *, u32);
extern u32 func_800F54E4(void);
extern s32 func_800D211C(s32);
extern void _chintrotext_entrypoint_2(int);
extern int _susubgame_entrypoint_10(void *, int, int, int);
extern int _susubgame_entrypoint_5(void *, int, int, int, int);
extern int _susubgame_entrypoint_6(void *, int, int, int, int);
extern void func_800BF744(int, int);
extern void func_800F8300(int, int, int);
extern void func_800F4CEC(int, int);
extern u32 func_800FDC28(u32);
extern void func_800CE8D8(s32, f32, s32);
extern void func_800D2770(s32, s32);
extern void func_800F7C0C(s32, s32, f32);
extern void func_800FC6B0(u32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9154(f32 *, f32);
extern void _sumultiscore_entrypoint_6();
typedef union {
    s32 word;
    s16 halves[2];
} PairEventPayload;
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern s32 func_800DC298(f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);
extern void func_8010D930(s32, s32, void *, void *);
extern void *D_80801D18_chballoonburst;
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_80801D28_chballoonburst[];
extern s32 func_800B53A4();
extern void func_800BA22C();
extern void func_800BA670();
extern void func_800BABB8();
extern s32 D_80801D5C_chballoonburst[];
extern s32 D_80801D98_chballoonburst[];
extern u8 D_80801DBC_chballoonburst[];
extern u8 D_80801DF0_chballoonburst[];
extern Actor *func_80106790();
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800DC0C0(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 D_80801DFC_chballoonburst[];
void func_80800970_chballoonburst();
void func_808011A8_chballoonburst();
s32 func_80801254_chballoonburst();
int func_80801290_chballoonburst();
void func_80801338_chballoonburst();
void func_80801948_chballoonburst();
void func_80801A10_chballoonburst();
void func_80801A50_chballoonburst();
void func_80801ABC_chballoonburst();
void func_80801AFC_chballoonburst();
void func_80800BE8_chballoonburst();
void func_80801B6C_chballoonburst();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_80800024_chballoonburst(),
    func_80800098_chballoonburst(), func_808008F0_chballoonburst();

int *chballoonburst_entrypoint_0()
{
    return &D_80801C40_chballoonburst;
}

int chballoonburst_entrypoint_1()
{
    return (int) &D_80801C88_chballoonburst;
}

int chballoonburst_entrypoint_2(void)
{
    return (int) &D_80801CD0_chballoonburst;
}

void func_80800024_chballoonburst(param_0) Actor *param_0;
{
    u8 *local_0;
    u16 *field_0x6e;
    local_0 = func_80100094(param_0, 0);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    if (1) {
        field_0x6e = (u16 *) ((char *) param_0 + 0x6E);
        *field_0x6e &= 0xFE00 & 0xFFFFFFFFu;
        *(s32 *) ((char *) local_0 + 0xC) = 0;
        _susubgame_entrypoint_0(param_0, (char *) local_0 + 0x18, 0);
        _susubgame_entrypoint_11(0);
    }
}

s32 func_80800A7C_chballoonburst();

void func_80800098_chballoonburst(param_0) Actor *param_0;
{
    u8 *local_0 = func_80100094(param_0, 0);

    switch (param_0->unk70_10) {
        if (1) {
        }
        case 3:
            func_800D24E8(0xC1, *(s32 *) (local_0 + 4), 0);
            if (func_800D9154(&param_0->unk58, func_800DC178(0.5f, 1.0f)))
                func_80108B04(param_0, -1);
            if (func_800CEAD0(param_0->unk6C_0)) {
                *(s32 *) (local_0 + 0x10) = func_80800A7C_chballoonburst(param_0, local_0 + 0x14);
                func_800F8300(func_800F54E4(), 2, 0);
                func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
                func_80101FDC(param_0, 4);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(param_0, local_0 + 0x18, 5, 1, 0);
                func_80101FDC(param_0, 5);
                _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *) (local_0 + 0x10),
                                              *(s32 *) (local_0 + 0x14), NULL, 0x22);
            }
        case 1:
        case 2:
        case 5:
        case 6:
            break;
    }
}

void func_80800790_chballoonburst();

void func_80800704_chballoonburst();

u32 func_8080066C_chballoonburst();

void func_808003C4_chballoonburst();

s32 func_808001FC_chballoonburst(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x2E:
            func_808003C4_chballoonburst(param_0, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
            break;
        case 0x2F:
            func_80800704_chballoonburst(param_0, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
            break;
        case 0x30:
            return func_8080066C_chballoonburst(param_0, ((s16 *) &param_2)[0],
                                                ((s16 *) &param_2)[1]);
        case 0x3D:
            func_80800BE8_chballoonburst(param_0, param_2);
            break;
        case 0xE:
            if (param_2 == 4 && param_0->unk3C)
                _capod_entrypoint_19(func_80106790(param_0->unk3C)->position);
            return 3;
        case 0x32:
            _subaddiedialog_entrypoint_11(param_0->unk0, func_800D395C() ? 0x1118 : 0x10BE, 0x46, 0,
                                          0x22);
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(param_0, local_0 + 0x18, param_2 & 0xFFFF,
                                           (u32) (param_2 & 0xFFFF0000) >> 16);
        case 0x95:
            func_80800790_chballoonburst(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003C4_chballoonburst(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x10BE:

        case 0x1118:
            if (param_2 > 0) {
                func_800DA544(0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x10BF, 0x44, 0, 0x22);
                func_80108B04(param_0, 0);
            } else {
                _plcamera_entrypoint_8(func_800F54E4());
                _susubgame_entrypoint_5(param_0, local_0 + 0x18, 5, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0x22);
            }
            _gcfrontend_entrypoint_9(0x68);
            return;

        case 0x10BF:
            _susubgame_entrypoint_5(param_0, local_0 + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0x22);
            return;

        case 0x10C0:

        case 0x10F8:

        case 0x10F9:

        case 0x10FA:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, 0, 0x22);
            return;

        case 0xCEB:
            local_1 = func_800F54E4();
            func_800F82D4(local_1, 0);
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
                _gcgoto_entrypoint_1(0xE4, 1);
            } else {
                func_800F4CC0(local_1);
                _susubgame_entrypoint_4(param_0, local_0 + 0x18);
            }
            func_800F7C58(local_1, 0x5D, 0);
            return;

        case 0xCEC:
            _susubgame_entrypoint_4(param_0, local_0 + 0x18);
            func_80800970_chballoonburst(param_0, 0);
            return;

        case 0x10D2:
            _susubgame_entrypoint_4(param_0, local_0 + 0x18);
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0xE1, 0x22);
    }
}

u32 func_8080066C_chballoonburst(Actor *param_0, s32 param_1, s32 param_2)
{
    u32 local_0;

    switch (param_1) {
        case 0x10BE:
            return param_2 == 0 ? param_0->unk74_7 : 0x32;
        case 0x10C0:
        case 0x10F9:
            return func_800D211C(0x80);
        case 0x1118:
            if (param_2 == 0) {
                local_0 = param_0->unk74_7;
            } else {
                local_0 = func_800D211C(0x80);
            }
            return local_0;
    }
    return 0;
}

void func_80800704_chballoonburst(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0 = param_0;
    switch (param_2) {
        case 1:
            func_80108B04(local_0, 1);
            func_800DA544(3);
            break;

        case 2:
            func_80108B04(local_0, 2);
            func_800DA544(2);
            break;

        case 3:
            func_800DA544(1);
            *(s32 *) ((char *) param_0 + 0x3c) = 0;
    }
}

void func_80800790_chballoonburst(void *param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F54E4();
    func_800BF744(1, 1);
    func_800BF744(2, 0);
    func_800F4CEC(local_1, 0x77);
    if ((((u32) ((u16 *) param_0)[0x39] >> 10) == 1)) {
        if (_susubgame_entrypoint_10(param_0, 2, 0x320, 0x1AE) != 0) {
            _chintrotext_entrypoint_2(1);
            _susubgame_entrypoint_6(param_0, local_0 + 0x18, 0, 0x20, 0);
        } else {
            _susubgame_entrypoint_5(param_0, local_0 + 0x18, 5, 1, 0);
            _subaddiedialog_entrypoint_11(*(void **) param_0, 0xCEC, 5, 0, 0x22);
            func_800F82D4(local_1, 2);
        }
        func_800F7C58(local_1, 0x5D, 1);
        func_80101FDC(param_0, 2);
        return;
    }
    func_800F8300(local_1, 2, 0);
    _susubgame_entrypoint_5(param_0, local_0 + 0x18, 5, 1, 0);
    _subaddiedialog_entrypoint_11(*(void **) param_0, 0xCEB, 0x46, 0, 0x22);
}

void func_808008F0_chballoonburst(param_0) s32 param_0;
{
    s32 local_0;
    local_0 = func_80100094(param_0, 0);
    if (func_800CEAA8(*(s32 *) ((char *) param_0 + 0x6C) & 0x1FF)) {
        func_800CE88C(*(s32 *) ((char *) param_0 + 0x6C) & 0x1FF, 0);
    }
    if (_susubgame_entrypoint_2(param_0, local_0 + 0x18)) {
        _susubgame_entrypoint_4(param_0, local_0 + 0x18);
    }
}

void func_80800970_chballoonburst(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 local_0;
    _subaddiemulti_entrypoint_2();
    func_80101FDC(param_0, 3);
    func_800D2770(0xC1, 0);
    func_800CE8D8(param_0->unk6C_0, (f32) param_0->unk74_7, param_0->unk74_7);
    func_800CE88C(param_0->unk6C_0, 1);
    func_800DA524(0);
    func_800DA524(3);
    func_800DA524(2);
    func_800DA524(1);
    func_800FDC28(0xC);
    for (local_0 = 0; local_0 < _gcstatusDll_entrypoint_11(); local_0++) {
        func_800F7B9C(local_0, 0x69);
        func_800F7C0C(local_0, 0x5F, -1.0f);
    }
}

s32 func_80800A7C_chballoonburst(Actor *param_0, s32 *param_1)
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
    local_1 = local_0[1];
    local_6 = func_800D0A9C(0x19, 1);
    local_7 = func_800D395C();
    local_8 = func_800D2054(0, 0x80, local_1);
    local_3 = local_8 == 1 && (local_6 || local_7);
    local_4 = local_1 >= 50;
    local_5 = local_4 && !local_6 && !local_7;
    func_800FDC28(0);
    func_800FC6B0((local_5 || local_3) ? 0x16 : 0x17);
    *param_1 = 6;
    if (local_5) {
        local_2 = 0x10D2;
    } else if (local_3) {
        local_2 = 0x10C0;
    } else if (!func_800D395C()) {
        if (local_6) {
            if (local_8 == 0)
                local_2 = 0x10FA;
            else
                local_2 = 0x10F9;
        } else {
            local_2 = 0x10F8;
        }
    } else {
        local_2 = 0xCEB;
        *param_1 = 0x46;
    }
    return local_2;
}

void func_80800BE8_chballoonburst(param_0, param_1) Actor *param_0;
s32 param_1;
{
    f32 local_0[3];
    Actor *local_5;
    u8 *local_1;
    f32 local_3;
    s32 local_4;
    s32 local_2;
    s32 flag;

    local_1 = func_80100094(param_0, 0);
    local_2 = func_800DA298(0);
    if (local_2) {
        if (param_0->unk3C) {
            func_800EE7F8(local_0, func_80106790(param_0->unk3C)->position);
        } else {
            func_800EFA4C(local_0, 1400.0f, 350.0f, -1400.0f);
        }
    } else {
        local_0[0] = func_800DC178(-1800.0f, 1800.0f);
        local_0[1] = func_800DC178(100.0f, 200.0f);
        local_0[2] = func_800DC178(-1800.0f, 1800.0f);
    }
    local_5 = func_80108528(0x350, local_0, (s32) func_800DC178(0.0f, 360.0f), &param_0);
    local_3 = func_800DC0C0();
    if (local_3 < 0.1666f) {
        local_4 = 0;
    } else {
        if (local_3 < 0.5f) {
            local_4 = 1;
        } else {
            local_4 = 2;
        }
    }
    if (param_1 != -1) {
        local_4 = param_1;
    }
    local_5->actorData[4] = 2 - local_4;
    flag = *(s32 *) (local_1 + 0xC);
    local_5->unk64_20 = (flag == 0);
    switch (local_4) {
        case 0:
            func_80102424(local_5, 4);
            func_801032B0(local_5, 0x78C, 0);
            local_5->unk54 = 350.0f;
            break;
        case 1:
            func_80102424(local_5, 3);
            func_801032B0(local_5, 0x78D, 0);
            local_5->unk54 = 300.0f;
            break;
        case 2:
            func_80102424(local_5, 2);
            func_801032B0(local_5, 0x796, 0);
            local_5->unk54 = 250.0f;
    }
    local_5->unk3C = param_0->unk0;
    local_5->unk6C_0 = param_0->unk6C_0;
    local_5->unk64_19 = *(s32 *) (local_1 + 0xC);
    if (local_2) {
        local_5->unk54 = 50.0f;
        _susubgame_entrypoint_6(param_0, local_1 + 0x18, 4, 0xA0, 0);
        if (param_1 != -1 && param_0->unk3C) {
            func_80801B6C_chballoonburst(func_80106790(param_0->unk3C));
        }
        param_0->unk3C = local_5->unk0;
    }
}

void func_80800EDC_chballoonburst(Actor *param_0)
{
    Actor *local_1;
    local_1 = func_80100094(param_0, 0);
    *(u16 *) ((char *) param_0 + 0x6E) = (*(u16 *) ((char *) param_0 + 0x6E) & 0xFE00) | 5;
    *(s32 *) ((char *) local_1 + 0x0C) = 1;
    _subaddiemulti_entrypoint_3(0xA);
    _sumultiscore_entrypoint_3((u8 *) local_1 + 0x30);
    _sumultiscore_entrypoint_4((u8 *) local_1 + 0x30, 6, 0, 1);
}

void func_80800F4C_chballoonburst(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    _sumultiscore_entrypoint_6(local_0 + 0x30);
    switch (param_0->unk70_10) {
        case 1:
            if (!func_800C954C() && !func_800DA298(0x6AD)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0x22);
                func_80101FDC(param_0, 2);
            }
            return;
        case 3:
            if (_subaddiefind_entrypoint_9(0x350) < 8) {
                if (func_800D9154(&param_0->unk58,
                                  func_800DC178(0.5f, 1.0f) / (f32) _gcstatusDll_entrypoint_11())) {
                    func_80108B04(param_0, -1);
                }
            }
            if (func_800CEAD0(param_0->unk6C_0)) {
                func_80801338_chballoonburst(param_0);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(param_0, local_0 + 0x18, 5, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *) (local_0 + 0x10),
                                              *(s32 *) (local_0 + 0x14), 0, 0x22);
                func_80101FDC(param_0, 5);
            }
    }
}

s32 func_808010D8_chballoonburst(s32 param_0, s32 param_1)
{
    s32 local_0;

    local_0 = func_80100094(param_0, 0);
    _sumultiscore_entrypoint_12(local_0 + 0x30, param_1, 1);
}

s32 func_8080110C_chballoonburst(Actor *param_0, s32 param_1, PairEventPayload param_2)
{
    switch (param_1) {
        case 0x2E:
            func_808011A8_chballoonburst(param_0, param_2.halves[0], param_2.halves[1]);
            break;
        case 0x30:
            return func_80801254_chballoonburst(param_0, param_2.halves[0], param_2.halves[1]);
        case 0x3D:
            func_80800BE8_chballoonburst(param_0, -1);
            break;
        case 0x95:
            func_80801290_chballoonburst(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808011A8_chballoonburst(param_0, param_1, param_2) s32 param_0;
s32 param_1;
s32 param_2;
{
    s32 local_0;

switch (param_1) {
    case 0xCEC:
        func_80800970_chballoonburst(param_0, 1);
        return;
    case 0x10CF:;
    case 0x10D0:
        local_0 = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            do {
                func_800F7C58(local_0, 0x5D, 1);
                local_0 += 1;
            } while (local_0 < _gcstatusDll_entrypoint_11());
        }
        _subaddiemulti_entrypoint_2();
        func_80101FDC(param_0, 6);
        _gcfrontend_entrypoint_10();
}

}

s32 func_80801254_chballoonburst(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    s32 new_var;
    new_var = param_1;

if (new_var == 0x10cf) {
    s32 local_0;
    local_0 = func_80100094(param_0, 0);
    return *(s32 *) ((char *) local_0 + 8) + 1;
}

return 0;
}

int func_80801290_chballoonburst(param_0)
Actor *param_0;
{
    s32 *local_0 = (s32 *) param_0;
    s32 local_1;

    func_800BF744(1, 1);
    func_800BF744(2, 0);
    func_800BF544(0, 0, 0);

if (((u32) *(u16 *) ((char *) local_0 + 0x72) >> 10) == 1) {
    _subaddiemulti_entrypoint_1(2, 0);
}

local_1 = 0;

if (_gcstatusDll_entrypoint_11() > 0) {
    do {
        func_800F7C58(local_1, 0x5D, 1);
        func_800F4CEC(local_1, 0x77);
        local_1 += 1;
    } while (local_1 < _gcstatusDll_entrypoint_11());
}

}

void func_80801338_chballoonburst(param_0) Actor *param_0;
{
    u8 *local_1;
    s32 local_0[8];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_8;
    s32 local_5;
    s32 local_7;

    local_1 = func_80100094(param_0, 0);
    local_2 = -1;
    for (local_3 = 0; local_3 < _gcstatusDll_entrypoint_11(); local_3++) {
        local_0[local_3] = _sumultiscore_entrypoint_8(local_1 + 0x30, local_3, 6);

if (local_2 < local_0[local_3]) {
    local_2 = local_0[local_3];
}

func_800AA20C(local_3, local_0[local_3]);

}
for (local_3 = 0; local_3 < _gcstatusDll_entrypoint_11(); local_3++) {
    if (local_2 == local_0[local_3]) {
        _sumultiscore_entrypoint_11(local_1 + 0x30, local_3, 6, 3.0f);
    }

}
for (local_4 = 1; local_4 < _gcstatusDll_entrypoint_11(); local_4++) {
    for (local_8 = local_4; local_8 > 0 && local_0[local_8 - 1] < local_0[local_8]; local_8--) {
        local_5 = local_0[local_8];
        local_0[local_8] = local_0[local_8 - 1];
        local_0[local_8 - 1] = local_5;
    }
}
func_800FC6B0(0x16);
if (local_0[0] != local_0[1]) {
    for (local_8 = 0; _sumultiscore_entrypoint_8(local_1 + 0x30, local_8, 6) != local_0[0];
         local_8++) {
    }
    *(s32 *) (local_1 + 8) = local_8;
    local_7 = 0x10CF;
} else {
    local_7 = 0x10D0;
}
_subaddiemulti_entrypoint_1(0, 0);
*(s32 *) (local_1 + 0x10) = local_7;
*(s32 *) (local_1 + 0x14) = 6;
func_80101FDC(param_0, 4);
}

void func_8080154C_chballoonburst(Actor *param_0)
{
    f32 local_0;
    local_0 = func_800DC298(0.5f) ? 1.0f : -1.0f;
    param_0->unk50 = func_800DC178(100.0f, 200.0f) * local_0;
    _subaddiefade_entrypoint_2(param_0);
    func_8010A800(param_0, 2);
    func_80801AFC_chballoonburst(param_0);
}

void func_808015D4_chballoonburst(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    f32 local_5;

    local_0 = func_800D8FF8();
    local_1 = 0;
    local_2 = func_800DA298(0);
    local_3 = 0;
    local_4 = 1;
    if (func_800CEAD0(param_0->unk6C_0)) {
        func_8010A570(param_0);
    }
    param_0->rotation[1] = func_800136E4(param_0->rotation[1] + param_0->unk50 * local_0);
    if (param_0->position[1] < 2800.0f) {
        param_0->position[1] += local_0 * param_0->unk54;
    } else {
        local_1 = 1;
    }
    if (_subaddiefade_entrypoint_0(param_0) == 255) {
        func_8010A800(param_0, 0);
    }
    switch (param_0->unk70_10) {
        case 4:
            local_3 = func_800DA298(3);
            break;
        case 3:
            local_3 = func_800DA298(2);
            break;
        case 2:
            local_3 = func_800DA298(1);
            break;
        case 5:
            local_5 = func_800F10B4(param_0->unk58, 0.0f, 1.4f, 0.2f, 1.0f);
            local_4 = 0;
            func_80102FDC(param_0, local_5);
            if (func_800D90A4(&param_0->unk58)) {
                func_8010A570(param_0);
                func_800FFAB0(param_0);
                return;
            }
    }
    if (local_4 && ((!local_2 && local_1) || (local_2 && local_3))) {
        func_80801B6C_chballoonburst(param_0);
    }
}

int func_808017A4_chballoonburst(Actor *param_0, s32 param_1, u8 *param_2)
{
    u8 *local_2;
    u8 *local_3;
    s32 local_0;
    s32 local_1;
    switch (param_1) {
        case 0x40:
            if ((s32) param_0->unk70_10 >= 2 && (s32) param_0->unk70_10 < 6) {
                local_3 = (*(u8 **) &param_2);
                local_0 = _subaddiemulti_entrypoint_5(local_3);
                local_1 = param_0->actorData[4] + 1;
                local_2 = func_80100094(func_80106790(param_0->unk3C), 0);

if (*(s32 *) (local_2 + 0xC)) {
    _sumultiscore_entrypoint_7(local_2 + 0x30, local_0, 6, local_1);
} else {
    *(s32 *) (local_2 + 4) += local_1;
}

_chscorepoints_entrypoint_2(local_1, local_0, param_0->position, 1);
func_80801948_chballoonburst(param_0);
func_8010A570(param_0);
func_800FFAB0(param_0);

if (*(u16 *) (local_3 + 0x18) & 1) {
    func_8010114C(local_3, 0x98, 0);
}

}
break;
case 0x29:
    if (param_0->unk64_20) {
        func_8010DC50(4);
    }
    break;

case 0x2A:
    if (param_0->unk64_20) {
        func_8010DCB4(4);
    }
    break;

case 0x1F:
    local_3 = param_2;

if (param_0->unk64_20) {
    func_8010DD20(param_0, 4, local_3);
}

else
{
    func_801015D0(param_0);
}
break;
default:
    return 0;
    }
    return 1;
    }

    void func_80801948_chballoonburst(param_0) Actor *param_0;
    {
        func_8010D930(1, (*(s32 *) ((u8 *) param_0 + 0x70)) & 1, (u8 *) param_0 + 4,
                      &D_80801D18_chballoonburst);
        if (param_0->unk64_20) {
            func_80801A50_chballoonburst(param_0, 0x771, 2);
            func_80801A50_chballoonburst(param_0, 0x772, 3);
            func_80801A50_chballoonburst(param_0, 0x773, 4);
            func_80801ABC_chballoonburst(param_0);
            func_80801A10_chballoonburst(param_0);
            return;
        }
        func_80801A50_chballoonburst(param_0, 0x771, 2);
        func_80801A50_chballoonburst(param_0, 0x772, 2);
        func_80801A50_chballoonburst(param_0, 0x773, 2);
    }

    void func_80801A10_chballoonburst(param_0) s32 param_0;
    {
        int new_var;
        new_var = param_0 + 4;
        func_800BBCB8(new_var, new_var, *((f32 *) ((param_0 ^ 0) + 0x38)), 8,
                      &D_80801D28_chballoonburst);
    }

    void func_80801A50_chballoonburst(param_0, param_1, param_2) s32 param_0;
    s32 param_1;
    s32 param_2;
    {
        s32 local_0;
        s32 local_1;
        s32 local_2;

        local_1 = func_800B53A4(param_2);
        local_0 = local_1;
        func_800BA670(local_1, param_1);
        local_2 = param_0 + 4;
        func_800BABB8(local_0, local_2, local_2, *(s32 **) ((char *) param_0 + 0x38),
                      &D_80801D5C_chballoonburst);
        func_800BA22C(local_0, param_2);
    }

    void func_80801ABC_chballoonburst(param_0) s32 param_0;
    {
        func_800BBCB8(param_0 + 4, 0, *((f32 *) ((param_0 ^ 0) + 0x38)), 1,
                      &D_80801D98_chballoonburst);
    }

    void func_80801AFC_chballoonburst(param_0) Actor *param_0;
    {
        if (param_0->unk64_20) {
            func_800BBCB8(param_0->position, 0, param_0->scale, 0xE, D_80801DBC_chballoonburst);
        }
        func_8010D930(4, *(u32 *) ((u8 *) param_0 + 0x70) & 1, param_0->position,
                      D_80801DF0_chballoonburst);
    }

    void func_80801B6C_chballoonburst(param_0) Actor *param_0;
    {
        if (param_0->unk70_10 != 5) {
            param_0->unk58 = 1.4f;
            func_80102424(param_0, 5);
            func_8010D930(5, *(u32 *) ((u8 *) param_0 + 0x70) & 1, param_0->position,
                          D_80801DFC_chballoonburst);
        }
    }

    extern void func_801018A4();
    extern void func_80108ED0();
    int D_80801C40_chballoonburst[18] = {0x2B1034F,
                                         0x1,
                                         0x0,
                                         (u32) func_80800098_chballoonburst,
                                         (u32) func_80105834,
                                         (u32) func_8010A730,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x400000,
                                         (u32) func_808008F0_chballoonburst,
                                         0x0,
                                         0x54C0000,
                                         (u32) func_80800024_chballoonburst,
                                         (u32) func_80107C2C,
                                         -0x7FFFF9FE,
                                         (u32) func_808001FC_chballoonburst,
                                         0x0};
    int D_80801C88_chballoonburst[18] = {0x2B1044C,
                                         -0xFFFF,
                                         0x0,
                                         (u32) func_80800F4C_chballoonburst,
                                         (u32) func_80105834,
                                         (u32) func_808010D8_chballoonburst,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x400400,
                                         (u32) func_808008F0_chballoonburst,
                                         0x0,
                                         0x54C0000,
                                         (u32) func_80800EDC_chballoonburst,
                                         (u32) func_80107C2C,
                                         -0x7FFFFBFE,
                                         (u32) func_8080110C_chballoonburst,
                                         0x0};
    int D_80801CD0_chballoonburst[18] = {0x2B20350,
                                         -0xFFFF,
                                         0x0,
                                         (u32) func_808015D4_chballoonburst,
                                         (u32) func_80105834,
                                         (u32) func_801018A4,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x4,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_8080154C_chballoonburst,
                                         (u32) func_80107C2C,
                                         -0x7FDFFF80,
                                         (u32) func_808017A4_chballoonburst,
                                         0x0};
    void *D_80801D18_chballoonburst = (void *) 0x001304FB;
    static u32 D_80801D18_chballoonburst_rest[3] = {0x180001, 0x7D01388, 0x0};
    s32 D_80801D28_chballoonburst[13] = {0x113001D, 0x9E20016, 0x10000015, 0xB3,    0x2B0133,
                                         0x1990022, 0x4C0059,  0x260033,   0xE000A, 0x14002D,
                                         0x4B005DC, 0x1BFF9C,  -0xC80000};
    s32 D_80801D5C_chballoonburst[15] = {0x1130016, 0x10000015, 0xCC,     0x2B0133,  0x1990022,
                                         0x1000100, 0x660099,   0xE000A,  0x14002D,  0x4B005DC,
                                         0x1BFF9C,  -0xC7FFD9,  0xC800C8, 0x1900190, 0x0};
    s32 D_80801D98_chballoonburst[9] = {0x1D09DD, 0x2B0200, 0x2800022, 0x3000380, 0x8000A00,
                                        0x150000, 0x260019, 0x7,       0x0};
    u8 D_80801DBC_chballoonburst[52] = {
        0x1,  0x13, 0x0,  0x1D, 0x9,  0xE5, 0x0,  0x1B, 0x0,  0xC8, 0x3,  0x20, 0x0,
        0xB,  0x0,  0x78, 0x0,  0x8C, 0x0,  0x64, 0x0,  0x0,  0x0,  0x23, 0x0,  0x99,
        0x0,  0x2B, 0x1,  0x33, 0x1,  0x66, 0x0,  0x15, 0x0,  0x0,  0x0,  0x8C, 0x0,
        0x16, 0x12, 0x0,  0x0,  0x1E, 0xFF, 0xB0, 0xFF, 0xB0, 0x0,  0x0,  0x0,  0x0};
    u8 D_80801DF0_chballoonburst[12] = {0x0, 0x13, 0x3, 0xED, 0x0, 0x1,
                                        0x3, 0xE8, 0x9, 0xC4, 0x0, 0x0};
    u8 D_80801DFC_chballoonburst[36] = {0x0, 0x13, 0x4,  0xFD, 0x0, 0xD,  0x0,  0xF3, 0x1,
                                        0xC, 0x0,  0x15, 0x0,  0x0, 0x1,  0x33, 0x0,  0x33,
                                        0x0, 0x1,  0x3,  0xE8, 0x9, 0xC4, 0x0,  0x0,  0x0,
                                        0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0};
