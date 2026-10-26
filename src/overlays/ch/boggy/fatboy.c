#include "ch/boggy/fatboy.h"

extern int D_80801120_chboggyfatboy[];
extern int D_808011DC_chboggyfatboy[];
extern s32 _chboggykids_entrypoint_0();
extern void func_800FFAB0();
extern s32 D_80801128_chboggyfatboy[];
extern void func_800EE940();
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 26; u32 local_0 : 1; u32 pad_2 : 5; } BoggyFatBoyFlags;
extern void _chboggyfatboy_entrypoint_0();
extern void func_80102FDC(Actor *, f32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern s32 _subaddietaxi_entrypoint_16;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct BoggyMealState { u8 pad_0[8]; u8 local_0 : 1; u8 pad_1 : 7; } BoggyMealState;
extern void *func_80100094(Actor *, s32);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_80801250_chboggyfatboy[];
extern u8 D_8080125C_chboggyfatboy[];
extern u8 D_80801264_chboggyfatboy[];
extern u8 D_80801290_chboggyfatboy[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_801022E4(Actor *);
extern s32 func_80101E4C(Actor *, f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800C4B7C(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s16 D_808012A0_chboggyfatboy[];
extern f32 D_808012AC_chboggyfatboy[];
extern u8 D_808012BC_chboggyfatboy[];
extern u8 D_808012CC_chboggyfatboy[];
extern u8 D_808012E8_chboggyfatboy[];
extern s32 D_80801148_chboggyfatboy[];
extern s32 D_80801224_chboggyfatboy[];
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800EE88C(f32 *, void *);
extern f32 func_801028C4(Actor *, f32 *, f32, f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 func_800D9154(f32 *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern u8 D_80801234_chboggyfatboy[];
extern u8 D_80801244_chboggyfatboy[];
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
extern void func_800C9C70(f32, s32, f32, s32, f32 *, f32, f32);
int func_80800FE0_chboggyfatboy();
s32 func_808005AC_chboggyfatboy();
extern void func_80101870(), func_80107C2C(), func_80108ED0(), func_8080052C_chboggyfatboy(), func_80800978_chboggyfatboy();
extern u8 D_80801154_chboggyfatboy[];

int chboggyfatboy_entrypoint_0()
{
    return (int)&D_80801120_chboggyfatboy;
}

int chboggyfatboy_entrypoint_1()
{
  return &D_808011DC_chboggyfatboy;
}

s32 func_80800018_chboggyfatboy(u8 *param_0) {
    if (!_chboggykids_entrypoint_0(param_0)) {
        func_800FFAB0(param_0);
        return 0;
    }
    *(f32 *)(param_0 + 0x24) = 270.0f;
    if (func_800DA298(0x8E)) {
        return 0;
    } else {
        return 1;
    }
    return 1;
}

void func_80800078_chboggyfatboy(s32 param_0) {
    _subaddieitem_entrypoint_0((s32)func_80100094(param_0, 0) + 0xC, 0x3CA, 0x190, 1);
}

void func_80800E80_chboggyfatboy();

void func_80800D84_chboggyfatboy();

void func_80800998_chboggyfatboy();

void func_808000AC_chboggyfatboy(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_5[4];
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_1 = 1;
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    }
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(0xBA)) {
            if (func_800DA298(0xBB)) {
                param_0->unk74_30 = 1;
            } else if (func_80800FE0_chboggyfatboy(0x3CA) && !func_8010CAC0(param_0->position, 800)) {
                param_0->unk74_30 = 0;
            }
        }
        _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_80801224_chboggyfatboy, D_80801128_chboggyfatboy, 4);
        break;
    case 5:
        func_800EE88C(local_2, local_0);
        if (func_801028C4(param_0, local_2, 0.2f, 30.0f, 180.0f) < 40.0f) {
            func_80102424(param_0, 6);
        }
        break;
    case 6:
        func_800EE88C(local_3, local_0);
        param_0->unk54 = func_80102D78(param_0, local_3);
        func_80102BF8(param_0, 0.2f, 30.0f, 180.0f);
        func_8010B990(param_0, 0x1005);
        if (func_800F0064(param_0->position, 100.0f, local_3)) {
            func_801058C4(param_0, *(s16 *)(local_0 + 6), param_0->actorData[3], 1);
            func_80105BAC(param_0);
            func_80102424(param_0, 7);
        }
        break;
    case 9:
        local_1 = 0;
        break;
    case 10:
        param_0->unk54 = func_80102D78(param_0, func_80106790(param_0->unk3C)->position);
        func_80102BF8(param_0, 0.2f, 30.0f, 180.0f);
        local_1 = 0;
        if (_subaddietaxi_entrypoint_1(param_0, 1)) {
            func_800DA544(0x8E);
            func_80102424(param_0, 12);
        }
        break;
    case 11:
        if (_subaddietaxi_entrypoint_11(param_0, 1) && _subaddietaxi_entrypoint_5(param_0, 1)) {
            _subaddietaxi_entrypoint_14(param_0, 1);
            func_80102424(param_0, 13);
        }
        local_1 = _subaddietaxi_entrypoint_12(param_0, 1);
        break;
    case 12:
        param_0->unk54 = func_80102D78(param_0, func_80106790(param_0->unk3C)->position);
        func_80102BF8(param_0, 0.2f, 30.0f, 180.0f);
        if (!param_0->unk64_20 && func_8010108C(func_80106790(param_0->unk3C), 0x31, param_0->unk6C_9) > 0) {
            param_0->unk64_20 = 1;
        }
        break;
    case 13:
        if (_subaddietaxi_entrypoint_15(param_0, 1)) {
            func_80102424(param_0, 1);
            func_8010A590(param_0);
        }
        break;
    case 14:
        func_80800D84_chboggyfatboy(param_0);
        if (func_80101DDC(param_0)) {
            func_80800998_chboggyfatboy(param_0);
            func_80102424(param_0, 5);
            _subaddieDll_entrypoint_4(param_0, 1);
        }
        break;
    case 15:
        if (_subaddieitem_entrypoint_3(param_0, 0, local_0 + 0xC)) {
            local_4 = func_800F64A4(func_800F54E4(), 0x200) ? 0x1111 : 0x1095;
            func_800DA544(0xBB);
            _subaddiedialog_entrypoint_11(param_0->unk0, local_4, 0xE, param_0->position, 0x3B);
            func_80102424(param_0, 4);
        }
        break;
    }
    if ((*(u32 *)(local_0 + 8) >> 31) && func_800D9154((f32 *)(local_0 + 0x20), 1.4f)) {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80801148_chboggyfatboy);
    }
    func_80800E80_chboggyfatboy(param_0);
    _subaddietaxi_entrypoint_9(param_0, 1);
    if (local_1) {
        _sudeflect_entrypoint_1(param_0->position, 100.0f, 0.0f, 70.0f, 10);
    }
}

void func_8080052C_chboggyfatboy(param_0) s32 param_0;
{
  s32 local_0 = param_0;
  func_80105834();
  func_80105230(local_0, 0);
  _sudeflect_entrypoint_0(local_0 + 4, 0x42C80000, 0x42480000, 10);
  if (func_80105A5C(local_0) != 0)
  {
    if ((local_0 && local_0) && local_0)
    {
    }
    if (func_800DA980(0x8C, 3) != 3)
    {
      func_80101180(0x13F, 0x4F, 0);
    }
    func_800FFAB0(local_0);
  }
}

s32 func_80800F40_chboggyfatboy();

void func_80800C5C_chboggyfatboy();

s32 func_80800AF0_chboggyfatboy();

void func_808009E0_chboggyfatboy();

void func_80800808_chboggyfatboy();

s32 func_808005AC_chboggyfatboy(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    f32 local_0[1];
    s32 pad_x;
    switch (param_1) {
    case 0x3E:
        func_80800AF0_chboggyfatboy(param_0, param_2);
        break;
    case 0x44:
        func_80800C5C_chboggyfatboy(param_0, param_2);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3((u32 *)D_80801234_chboggyfatboy, param_0->scale);
        break;
    case 0x29:
        func_80800F40_chboggyfatboy(param_0);
        break;
    case 0x95:
        func_808009E0_chboggyfatboy(param_0);
        param_0->unk74_30 = func_800DA298(0xBA);
        break;
    case 0x2E:
        func_80800808_chboggyfatboy(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0xB8:
        pad_x = param_2 & 0xFFFF;
        switch (pad_x) {
        case 1:
            if (func_800DA298(0xBA)) {
                return func_80800FE0_chboggyfatboy(0x3CA) ? 0x1093 : 0x1092;
            }
            return func_800F64A4(func_800F54E4(), 0x200) ? 0x110F : 0x1091;
        case 2:
            if (func_800DA298(0xBB)) return 0x1096;
            return func_80800FE0_chboggyfatboy(0x3CA) ? 0x1093 : 0x1092;
        }
        break;
    case 0x2D:
        _subaddieaudioquick_entrypoint_2(param_0, &param_0->position[0], D_80801244_chboggyfatboy);
        func_800C9C70(1.0f, 0x525, 1.05f, 22000, &param_0->position[0], 200.0f, 3000.0f);
        break;
    case 0x30:
        return 3 - func_800DA980(0x8C, 3);
    case 0x2A:
        func_80800FAC_chboggyfatboy(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800808_chboggyfatboy(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x1093:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x108B, 0x4E, param_0->position, 0x3D);
            break;
        case 0x1095:
        case 0x1111:
            func_80102424(param_0, 1);
            break;
        case 0x108B:
            if (param_2 > 0) {
                func_80102424(param_0, 0xF);
                _subaddieitem_entrypoint_2(local_0 + 0xC);
            } else {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1094, 0xE, param_0->position, 0x3D);
            }
            break;
        default:
            if (_subaddiedialog_entrypoint_9(param_0, param_1, D_80801128_chboggyfatboy, 4) == 1) {
                func_800DA544(0xBA);
                if (func_80800FE0_chboggyfatboy(0x3CA)) {
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x1093, 0xE, param_0->position, 0x3D);
                } else {
                    func_800C01A8(0x64, 0);
                    func_800C0850();
                    func_80102424(param_0, 1);
                }
            } else func_80102424(param_0, 1);
            break;
    }
}

void func_80800978_chboggyfatboy(Actor* arg0)
{
    func_80800FAC_chboggyfatboy(arg0);
}

void func_80800998_chboggyfatboy(Actor *param_0) {
    u8 *local_0 = (u8 *)func_80100094(param_0, 0);
    u8 *local_1 = (u8 *)func_80106790(*(void **)((u8 *)param_0 + 0x3C));
    *(s16 *)(local_0 + 6) = *(s32 *)(local_1 + 0x2C);
    func_800EE940(local_0, local_1 + 0x18);
}

void func_808009E0_chboggyfatboy(Actor *param_0)
{
    Actor *local_0;
    if (!func_80800018_chboggyfatboy(param_0)) {
        func_800FFAB0(param_0);
        return;
    }
    if (_subaddietaxi_entrypoint_13(param_0, 1, _chboggyfatboy_entrypoint_0, 7)) {
        func_80800078_chboggyfatboy(param_0);
        func_80102FDC(param_0, 1.0f);
    } else {
        if (((BoggyFatBoyFlags *)param_0)->local_0) {
            func_800FFAB0(param_0);
            return;
        }
        func_80800078_chboggyfatboy(param_0);
        func_80102FDC(param_0, 1.0f);
    }
    local_0 = _subaddiefind_entrypoint_2(0x13F, 0);
    param_0->unk3C = local_0 ? local_0->unk0 : 0;
    if (func_80800FE0_chboggyfatboy(0x3CA) && !func_800DA298(0xBB)) func_800DA524(0xBA);
    func_801088A8(param_0, 0x10002000, 0, 0);
}

s32 func_80800AF0_chboggyfatboy(s32 param_0, s32 param_1){
    if(func_800DA298(0xBB) && _subaddietaxi_entrypoint_2(param_0, 1)){
        func_80102424(param_0, 0x9);
    }
}

void func_80800B38_chboggyfatboy(s32 param_0, u8 *param_1, s32 param_2, s32 param_3) {
    if (func_800DA298(0x8E) == 0) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0, (*(s32 *)((s8 *)(param_1) + (0))), (*(s32 *)((s8 *)(param_1) + (4))), (*(s32 *)((s8 *)(param_1) + (8))), param_2, param_3);
    }
}

s32 func_80800BA0_chboggyfatboy(s32 param_0, s32 param_1, f32 *param_2)
{
    Actor *local_0;

    local_0 = _subaddiefind_entrypoint_2(0x13F, 0);
    if (local_0 != NULL) {
        if (func_800CBC3C(param_1) + 1 == (*(u32 *)((u8 *)local_0 + 0x70) >> 25)) {
            func_800EE7F8(param_2, local_0->position);
            func_800EF1B8(param_2, local_0->rotation[1] - 45.0f, 180.0f);
            return 2;
        }
    }
    func_800C05B8(0x1097, 1, 0, 0, 0, 0, 0);
    return 1;
}

void func_80800C5C_chboggyfatboy(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    Actor *local_1;

    func_80102FDC(param_0, 1.0f);
    switch (func_800CB3E0(param_1)) {
        case 1:
            func_80102424(param_0, 1);
            func_8010A590(param_0);
            break;
        case 3:
            _subaddietaxi_entrypoint_10(param_0, param_1, 11);
            break;
        case 4:
            local_1 = _subaddiefind_entrypoint_2(0x13F, 0);
            func_800EE7F8(local_0, local_1->position);
            func_800EF1B8(local_0, local_1->rotation[1] - 45.0f, 180.0f);
            func_8010A570(param_0);
            _subaddietaxi_entrypoint_0(param_0, param_1, local_0, 10);
            break;
        case 6:
            _subaddiefind_entrypoint_2(0x13F, 0);
            func_80102424(param_0, 12);
            func_8010A570(param_0);
            param_0->unk64_20 = 1;
            break;
    }
}

void func_80800D84_chboggyfatboy(Actor *param_0)
{
    BoggyMealState *local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    if (func_80101E14(param_0, 0.8f)) {
        local_0->local_0 = 1;
    }
    if (_subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801250_chboggyfatboy, D_80801290_chboggyfatboy) || _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_8080125C_chboggyfatboy, 0.64f)) {
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 120.0f;
        func_800EE7F8(local_2, local_1);
        local_2[1] -= 30.0f;
        func_800BBCB8(local_1, local_2, 1.0f, 8, D_80801264_chboggyfatboy);
    }
}

void func_80800E80_chboggyfatboy(Actor *param_0)
{
    if (func_801022E4(param_0) == 0x246) {
        if (func_80101E14(param_0, 0.0f)) {
            func_800C4B7C(D_808012A0_chboggyfatboy[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012BC_chboggyfatboy);
        }
        if (func_80101E14(param_0, 0.5f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012CC_chboggyfatboy);
        }
        if (func_80101E4C(param_0, D_808012AC_chboggyfatboy)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012E8_chboggyfatboy);
        }
    }
}

s32 func_80800F40_chboggyfatboy(Actor *this){
    if(!func_80100094(this, 1)){
        _suexpression_entrypoint_7(this, 1, 0x3d);
        _suexpression_entrypoint_12(func_80100094(this, 1), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(this, 1), 0x3E8);
    }
}

void func_80800FAC_chboggyfatboy(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
int func_80800FE0_chboggyfatboy(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_800F54E4();
  if (!func_800F64A4(local_0 | 0, 0x201))
  {
    return 0;
  }
  else
  {
    return 0 < func_800F640C(local_0, param_0) | 0;
  }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/boggy/fatboy.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80801120_chboggyfatboy -> int[], D_80801148_chboggyfatboy -> s32[], D_808011DC_chboggyfatboy -> int[], D_80801224_chboggyfatboy -> s32[] */
int D_80801120_chboggyfatboy[2] = { (u32)func_80800BA0_chboggyfatboy, (u32)func_80800B38_chboggyfatboy };
s32 D_80801128_chboggyfatboy[8] = { 0x201, -0xFF00, 0x601, -0x1FE00, 0x400, 0x11100100, -0x12001, 0x12220300 };
s32 D_80801148_chboggyfatboy[3] = { 0x130524, 0xA00CC, 0x0 };
u8 D_80801154_chboggyfatboy[136] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x3F, 0x40, 0x0, 0x0, 0x2, 0x47, 0x0, 0x1, 0x3F, 0x40, 0x0, 0x0, 0x2, 0x47, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x3F, 0x40, 0x0, 0x0, 0x2, 0x47, 0x0, 0x1, 0x3F, 0x40, 0x0, 0x0, 0x2, 0x47, 0x0, 0x1, 0x3F, 0x40, 0x0, 0x0, 0x2, 0x47, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x40, 0xA0, 0x0, 0x0, 0x2, 0x48, 0x0, 0x2, 0x40, 0x9C, 0xCC, 0xCD, 0x2, 0x46, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_808011DC_chboggyfatboy[18] = { 0x1940142, 0x75B0001, (u32)&D_80801154_chboggyfatboy, (u32)func_808000AC_chboggyfatboy, (u32)func_8080052C_chboggyfatboy, (u32)func_80101870, 0x9C40000, 0x40000000, 0x0, 0x40040164, (u32)func_80800978_chboggyfatboy, (u32)func_80108ED0, 0x240000, 0x0, (u32)func_80107C2C, -0x7FEFAFEC, (u32)func_808005AC_chboggyfatboy, 0x0 };
s32 D_80801224_chboggyfatboy[4] = { 0x0, 0x190003D, 0xE, 0x463C0400 };
u8 D_80801234_chboggyfatboy[16] = { 0x43, 0x34, 0x0, 0x0, 0x43, 0xC, 0x0, 0x0, 0x43, 0xC, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0 };
u8 D_80801244_chboggyfatboy[12] = { 0x0, 0x13, 0x4, 0xA4, 0x0, 0xA, 0x1, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801250_chboggyfatboy[12] = { 0x0, 0x13, 0x4, 0x17, 0x0, 0xD, 0x0, 0xE6, 0x1, 0x19, 0x0, 0x0 };
u8 D_8080125C_chboggyfatboy[8] = { 0x0, 0x13, 0x4, 0xE, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801264_chboggyfatboy[44] = { 0x0, 0x1D, 0x9, 0xE3, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x22, 0x0, 0x38, 0x0, 0x42, 0x0, 0x23, 0x0, 0x2E, 0x0, 0x2B, 0x0, 0x66, 0x0, 0x80, 0x0, 0x2D, 0x1, 0x2C, 0x1, 0x90, 0x0, 0xB, 0x0, 0x14, 0x0, 0x1E, 0x0, 0xA, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801290_chboggyfatboy[16] = { 0x3D, 0xF5, 0xC2, 0x8F, 0x3E, 0x8A, 0x3D, 0x71, 0x3E, 0xCC, 0xCC, 0xCD, 0xBF, 0x80, 0x0, 0x0 };
s16 D_808012A0_chboggyfatboy[6] = { 0x540, 0x42B, 0x558, 0x559, 0x557, 0x0 };
f32 D_808012AC_chboggyfatboy[4] = { 0.6f, 0.72f, 0.86f, -1.0f };
u8 D_808012BC_chboggyfatboy[16] = { 0x0, 0x21, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x19, 0x4E, 0x20, 0x5D, 0xC0, 0x0, 0x0 };
u8 D_808012CC_chboggyfatboy[28] = { 0x0, 0x13, 0x4, 0x86, 0x0, 0xD, 0x0, 0xC0, 0x0, 0xD9, 0x0, 0x15, 0x0, 0xC, 0x0, 0xCC, 0x0, 0x33, 0x0, 0x19, 0x6D, 0x60, 0x7D, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_808012E8_chboggyfatboy[24] = { 0x0, 0x13, 0x5, 0xCA, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
