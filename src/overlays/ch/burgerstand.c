#include "ch/burgerstand.h"

extern void func_80102424(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80090734(s32, f32 *);
extern void *func_80100094(Actor *, u32);
extern int D_80800C28_chburgerstand[];
extern void *D_80800C70_chburgerstand;
extern int D_80800CB8_chburgerstand[];
extern s32 D_80800D00_chburgerstand[];
extern s32 D_80800D48_chburgerstand[];
extern int func_80102320(Actor *, f32, f32);
extern s32 func_800F4EC8(s32, f32 *, f32, f32, f32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern int D_80800DA0_chburgerstand[];
extern int D_80800DCC_chburgerstand[];
extern int D_80800D7C_chburgerstand[];
extern int D_80800D88_chburgerstand[];
extern int D_80800D94_chburgerstand[];
extern int D_80800D60_chburgerstand[];
extern int D_80800DAC_chburgerstand[];
extern int D_80800D6C_chburgerstand[];
extern int D_80800DB8_chburgerstand[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80800DDC_chburgerstand[];
extern u8 D_80800DEC_chburgerstand[];
extern void _suexpression_entrypoint_7(s32, s32, s32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _suexpression_entrypoint_17(s32, s32);
extern s32 D_80800E14_chburgerstand[];
extern u8 D_80800BC0_chburgerstand[];
extern s32 _subaddiedialog_entrypoint_8();
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern void func_8010D254(f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_8010D5DC(void);
extern void func_8008F904(void *, Unk80132ED0 *);
extern void func_8008F990(f32 *, f32);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void _subaddiefade_entrypoint_9(Actor *, f32 *);
extern void _subaddiefade_entrypoint_11(Actor *, f32 *);
extern void func_80101FDC();
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern s32 _chswitch_entrypoint_10(s32, s32);
typedef union {
    u32 local_0;
    s16 local_1[2];
} StandEvent_chburgerstand;
extern u32 D_80800D50_chburgerstand[];
extern void func_80101EE4(Actor *, f32);
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
int func_808004DC_chburgerstand();
void func_808005AC_chburgerstand();
void func_80800754_chburgerstand();

int chburgerstand_entrypoint_0()
{
    return (int) D_80800C28_chburgerstand;
}

int chburgerstand_entrypoint_1()
{
    return &D_80800C70_chburgerstand;
}

int *chburgerstand_entrypoint_2()
{
    return D_80800CB8_chburgerstand;
}

int chburgerstand_entrypoint_3()
{
    return D_80800D00_chburgerstand;
}

void func_80800030_chburgerstand(u8 *param_0)
{
    f32 *new_var;
    u8 *new_var2;
    unsigned short new_var3;
    s32 temp_v0;
    unsigned char new_var4;
    new_var2 = param_0;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(new_var2, 4);
    } else {
        *(u8 *) ((s8 *) new_var2 + 0x65) = (u8) ((*(u8 *) ((s8 *) new_var2 + 0x65) & 0xFFFE) |
                                                 ((unsigned char) func_800DA298(0x9F) & 1));
    }
    new_var4 = (new_var3 = *(u16 *) ((s8 *) new_var2 + 0x64));
    func_80103110(new_var2, new_var4 & (1 ^ 0));
    temp_v0 = _subaddiefind_entrypoint_2(0x32F, 0);
    new_var = (f32 *) ((s8 *) new_var2 + 0x1C);
    if (temp_v0 != 0) {
        func_800EE7F8(new_var2 + 0x18, temp_v0 + 4);
        *new_var = (f32) *(f32 *) ((s8 *) new_var2 + 8);
    }
}

void func_808000C4_chburgerstand(Actor *param_0)
{
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
        if (func_801022E4(param_0) != 0xDC || !func_80102320(param_0, 0.32f, 0.95f))
            _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
    }
    func_800F4EC8(func_800F54E4(), (f32 *) param_0->actorData, 300.0f, -10.0f, 260.0f);
    switch (param_0->unk70_10) {
        case 1:
            func_808004DC_chburgerstand(param_0);
            func_808005AC_chburgerstand(param_0);
            func_80800754_chburgerstand(param_0);
            break;
        case 2:
            func_808004DC_chburgerstand(param_0);
            func_808005AC_chburgerstand(param_0);
            break;
        case 3:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800D48_chburgerstand,
                                             0.7f);
            if (func_80101DDC(param_0)) {
                func_800D175C(0x4B, 5 - func_800D1A04(0x4B));
                func_800FC660(14);
                func_80102424(param_0, 1);
                func_800FFA88(param_0->unk3C);
                param_0->unk3C = 0;
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x10FE, 6, param_0->position, 0x51);
            }
            break;
        case 4:
            func_808004DC_chburgerstand(param_0);
            func_808005AC_chburgerstand(param_0);
            break;
    }
}

void func_80800284_chburgerstand(Actor *arg0)
{
    func_80800720_chburgerstand(arg0);
}

void func_80800940_chburgerstand();

void func_8080087C_chburgerstand();

void func_808007A0_chburgerstand();

void func_808006B4_chburgerstand();

s32 func_808002A4_chburgerstand(Actor *param_0, s32 param_1, StandEvent_chburgerstand param_2)
{
    Actor *local_0;
    u32 local_1;
    switch (param_1) {
        default:
            return 0;
        case 0x2E:
            func_808007A0_chburgerstand(param_0, param_2.local_1[0], param_2.local_1[1]);
            return 1;
        case 0x2F:
            func_8080087C_chburgerstand(param_0, param_2.local_1[0], param_2.local_1[1]);
            return 1;
        case 0x32:
            func_80090734(2, param_0->position);
            return 1;
        case 0x3D:
            func_80800940_chburgerstand(param_0);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800D50_chburgerstand, param_0->scale);
            return 1;
        case 0xA:
            param_0->unk64_16 = 1;
            func_80102424(param_0, 2);
            func_80101EE4(param_0, 0.0f);
            func_80103110(param_0, 1);
            if (param_0->unk3C) {
                local_0 = func_80106790(param_0->unk3C);
                local_0->unk64_16 = param_0->unk64_16;
            }
            _capod_entrypoint_13(param_0->unk0, 0, 0x11, 0x30);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x10DF, 4, param_0->position, 0x50);
            return 1;
        case 0x29:
            func_808006B4_chburgerstand(param_0);
            return 1;
        case 0x2A:
            func_80800720_chburgerstand(param_0);
            return 1;
        case 0x95:
            if (!func_800D1A04(0x4B))
                func_80108B04(param_0, 0);
            break;
        case 0xB8:
            local_1 = param_2.local_0 & 0xFFFF;
            switch (local_1) {
                default:
                    return 0;
                case 1:
                    return param_0->unk3C ? 0x10AB : 0x10AC;
                case 2:
                    return param_0->unk3C ? 0x1106 : 0x1107;
            }
    }
    return 1;
}

int func_808004DC_chburgerstand(param_0)
s32 param_0;
{
    s32 local_0;
    local_0 = param_0 | 0;
    _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, D_80800D7C_chburgerstand, 0.02f);
    _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, D_80800D88_chburgerstand, 0.04f);
    _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, D_80800D94_chburgerstand, 0.11f);
    _subaddieaudioquick_entrypoint_4(local_0, local_0 + 4, D_80800D60_chburgerstand,
                                     D_80800DAC_chburgerstand);
    _subaddieaudioquick_entrypoint_4(local_0, local_0 + 4, D_80800D6C_chburgerstand,
                                     D_80800DB8_chburgerstand);
    _subaddieaudioquick_entrypoint_4(local_0, local_0 + 4, D_80800DA0_chburgerstand,
                                     D_80800DCC_chburgerstand);
}

void func_808005AC_chburgerstand(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;

    if (func_80101E4C(param_0, D_80800DDC_chburgerstand) &&
        _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_0)) {
        local_0[1] -= 30.0f;
        local_1 = func_800BABB8(0, local_0, NULL, param_0->scale, D_80800DEC_chburgerstand);
        func_800BA994(local_1, 45, (s16) (param_0->rotation[1] - 50.0f),
                      (s16) (param_0->scale * 10.0f), 60, (s32) (param_0->rotation[1] + 50.0f),
                      (s32) (param_0->scale * 20.0f));
        func_800BA22C(local_1, 3);
    }
}

void func_808006B4_chburgerstand(s32 param_0)
{
    if (func_80100094((Actor *) param_0, 1) == 0) {
        _suexpression_entrypoint_7(param_0, 1, 0x50);
        _suexpression_entrypoint_12(func_80100094((Actor *) param_0, 1), 50.0f, 20.0f);
        _suexpression_entrypoint_17(func_80100094((Actor *) param_0, 1), 0x3E8);
    }
}

void func_80800720_chburgerstand(Actor *arg0)
{
    if (func_80100094(arg0, 1) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

void func_80800754_chburgerstand(param_0) u8 *param_0;
{

if (_subaddiedialog_entrypoint_8(param_0, param_0 + 4, D_80800E14_chburgerstand,
                                 &D_80800BC0_chburgerstand, 5)) {
    func_80090734(1, (f32 *) (param_0 + 4));
}

}

void func_808007A0_chburgerstand(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x10DF:
            _capod_entrypoint_14();
            func_80102424(param_0, 1);
            return;
        case 0x10FE:
            func_8008FC9C(0);
            func_80102424(param_0, 1);
            return;
        default:
            if (param_0->unk3C &&
                _subaddiedialog_entrypoint_9(param_0, param_1, D_80800BC0_chburgerstand, 5) == 2) {
                func_80102424(param_0, 3);
                func_80102424(func_80106790(param_0->unk3C), 2);
            } else {
                func_80102424(param_0, 1);
                func_80090708(0);
            }
    }

}

void func_8080087C_chburgerstand(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    f32 local_3;

if (param_0->unk3C) {
    local_2 = _subaddiedialog_entrypoint_9(param_0, param_1, D_80800BC0_chburgerstand, 5);
    if (local_2 != 2) {
        return;
    }
    func_8010D254(local_1);
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], 340.0f);
    local_3 = func_800EEAD4(local_1, local_0);
    if (local_3 > 50.0f) {
        func_80090708(0);
        func_8008F8B0();
        func_8008F904(func_8010D5DC, param_0->unk0);
        func_8008F990(local_0, 170.0f);
    }
}

}

void func_80800940_chburgerstand(Actor *param_0)
{
    Actor *local_1;
    f32 local_0[3];

    local_1 = func_801084B0(0x32C, &param_0);
    func_80102FDC(local_1, param_0->scale);
    _subaddiefade_entrypoint_9(param_0, local_0);
    _subaddiefade_entrypoint_11(local_1, local_0);
    param_0->unk3C = local_1->unk0;
    local_1->unk64_16 = param_0->unk64_16;
}

void func_808009C4_chburgerstand(s32 arg0)
{
}
void func_808009CC_chburgerstand(Actor *param_0)
{
    s32 local_0;

    if (func_800EA05C() == 0x124)
        func_8010A624(param_0);
    param_0->position[1] -= 225.0f;

if (_glcutDll_entrypoint_20()) {
    local_0 = -1;
    func_80101FDC(param_0, 4);
} else {

local_0 = 0x9F;
}
if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 225.0f, 32, local_0)) {
    _chdoormake_entrypoint_5(param_0, 2.0f);
    _chdoormake_entrypoint_5(param_0, 2.0f);
    _chdoormake_entrypoint_8(param_0, 3);
}
}

void func_80800A8C_chburgerstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0, FLAG_09F_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800AB8_chburgerstand(s32 param_0, s32 param_1)
{
    if (param_1 == 7) {
        func_80101180(0x32F, 7, 0);
        func_80101180(0x32B, 0xA, 0);
    } else {
        return _chswitch_entrypoint_10(param_0, param_1);
    }
    return 1;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
extern void func_80102EC0();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
u8 D_80800BC0_chburgerstand[40] = {0x0,  0x0, 0x0,  0x1,  0x10, 0xAA, 0x1,  0x0,  0x0,  0x0,
                                   0x0,  0x1, 0xFF, 0xFF, 0x2,  0x0,  0x0,  0x0,  0x2,  0x0,
                                   0x11, 0x5, 0x1,  0x0,  0x0,  0x0,  0x2,  0x0,  0xFF, 0xFE,
                                   0x2,  0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0x10, 0x3,  0x0};
u32 D_80800BE8_chburgerstand[10] = {0x0,      0x0,        0x41940000, 0xDC0001,   0x41940000,
                                    0xDC0001, 0x3FE00000, 0xDD0002,   0x41940000, 0xDC0001};
u32 D_80800C10_chburgerstand[6] = {0x0, 0x0, 0x3FE00000, 0xD90044, 0x3FE00000, 0xD90002};
int D_80800C28_chburgerstand[18] = {0x1B7032B,
                                    0x6AE0001,
                                    (u32) &D_80800BE8_chburgerstand,
                                    (u32) func_808000C4_chburgerstand,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x7D00000,
                                    0x0,
                                    0x0,
                                    0x40000160,
                                    (u32) func_80800284_chburgerstand,
                                    0x0,
                                    0x0,
                                    (u32) func_80800030_chburgerstand,
                                    (u32) func_80107C2C,
                                    (u32) ((u8 *) boot_thread_stack + 0x1F32),
                                    (u32) func_808002A4_chburgerstand,
                                    0x0};
void *D_80800C70_chburgerstand = (void *) 0x01B8032C;
static u32 D_80800C70_chburgerstand_rest[17] = {0x6AF0001,
                                                (u32) &D_80800C10_chburgerstand,
                                                (u32) func_80102EC0,
                                                (u32) func_80105834,
                                                (u32) func_80101870,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x4,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) func_808009C4_chburgerstand,
                                                (u32) func_80107C2C,
                                                0x80102812,
                                                0x0,
                                                0x0};
int D_80800CB8_chburgerstand[18] = {0xAC032F,
                                    0x7740001,
                                    0x0,
                                    (u32) _chdoor_entrypoint_0,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x40000C00,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_808009CC_chburgerstand,
                                    (u32) func_80107C2C,
                                    -0x7FFFD3FE,
                                    (u32) _chdoor_entrypoint_1,
                                    0x0};
s32 D_80800D00_chburgerstand[18] = {0x3430330,
                                    0x7600001,
                                    (u32) &D_8011A270,
                                    (u32) _chswitch_entrypoint_6,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x808,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800A8C_chburgerstand,
                                    (u32) func_80107C2C,
                                    -0x7FFFD3EE,
                                    (u32) func_80800AB8_chburgerstand,
                                    0x0};
s32 D_80800D48_chburgerstand[2] = {0x1303FF, 0x0};
u32 D_80800D50_chburgerstand[4] = {0x436B0000, 0x432A0000, 0x42C80000, 0x42DC0000};
int D_80800D60_chburgerstand[3] = {0x130430, 0xD0099, 0xB30000};
int D_80800D6C_chburgerstand[4] = {0x130449, 0xD00B3, 0xCC0016, 0x2EE00000};
int D_80800D7C_chburgerstand[3] = {0x130500, 0xD00F3, 0x10C0000};
int D_80800D88_chburgerstand[3] = {0x130502, 0xD00C0, 0xD90000};
int D_80800D94_chburgerstand[3] = {0x130503, 0xD00D9, 0xF30000};
int D_80800DA0_chburgerstand[3] = {0x130501, 0xD00F3, 0x10C0000};
int D_80800DAC_chburgerstand[3] = {0x3F1EB852, 0x3F266666, -0x40800000};
int D_80800DB8_chburgerstand[5] = {0x3F051EB8, 0x3F0CCCCD, 0x3F3851EC, 0x3F400000, -0x40800000};
int D_80800DCC_chburgerstand[4] = {0x3E4CCCCD, 0x3E77CED9, 0x3E99999A, -0x40800000};
u8 D_80800DDC_chburgerstand[16] = {0x3D, 0xF5, 0xC2, 0x8F, 0x3F, 0x1E, 0xB8, 0x52,
                                   0x3F, 0x26, 0x66, 0x66, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800DEC_chburgerstand[40] = {0x3, 0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0, 0x16, 0x2, 0x8,
                                   0x0, 0x1F, 0x50, 0xC0, 0x50, 0x0,  0x0, 0x22, 0x0, 0x33,
                                   0x0, 0x4C, 0x0,  0xCC, 0x1,  0x0,  0x0, 0x15, 0x0, 0x0,
                                   0x0, 0x99, 0x0,  0x2B, 0x1,  0x0,  0x1, 0x33, 0x0, 0x0};
s32 D_80800E14_chburgerstand[7] = {0x9D0000, 0x1900050, 0x6, 0x7320200, 0x0, 0x0, 0x0};
