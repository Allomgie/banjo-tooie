#include "common.h"

extern void func_80102424(Actor *, s32);
extern void *D_80800880_chbkcart;
typedef struct { u8 pad_0[0x74]; u32 pad_a : 1; u32 f74 : 1; u32 pad_b : 30; u32 pad_c : 29; u32 f4 : 1; u32 pad_d : 2; } BkCartBits2;
typedef struct { f32 x; f32 y; f32 z; } V3C;
extern u8 D_80800828_chbkcart[];
extern V3C D_80800864_chbkcart;
extern u8 D_80800858_chbkcart[];
extern u8 *func_80100094();
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F3780(f32, u8 *, s32);
extern void func_8010C3A8(u8 *, s32, f32);
extern s32 func_80101E14(u8 *, f32);
extern void func_801026CC(u8 *, V3C, f32);
extern f32 func_80101F24();
extern void _subaddierouteDll_entrypoint_5(u8 *, u8 *, s32, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_6(u8 *, u8 *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(u8 *, u8 *, f32, f32, f32, s32);
extern s32 D_80800870_chbkcart;
extern f32 func_8010CD50(Actor *, s32);
extern void _chbounce_entrypoint_3(f32);
extern Actor *_chbounce_entrypoint_5(s32, Actor *);
extern Actor *_chbounce_entrypoint_7(s32, f32 *, s32);
typedef struct { u32 pad_0 : 29; u32 local_0 : 1; u32 pad_1 : 2; } Broad51CartFlags;

void func_80800000_chbkcart(Actor *param_0)
{
    switch ((s32)param_0->unk74_7 - 50) {
        case 0:
            if (func_800D1A04(0x53) || func_800DA298(0x3E2)) {
                func_800FFA88(param_0->unk0);
                return;
            }
            break;
        case 1:
            if (func_800DA298(0x3E3) || func_800DA298(0x3E4)) {
                func_800FFA88(param_0->unk0);
                return;
            }
            break;
        case 2:
            if (func_800DA298(0x3E5) || func_800DA298(0x3E6)) {
                func_800FFA88(param_0->unk0);
                return;
            }
            break;
    }
    _subaddierouteDll_entrypoint_3(param_0, func_80100094(param_0, 0), param_0->position);
    if (!func_800DA298(0x342)) {
        func_80102424(param_0, 1);
    } else {
        func_80102424(param_0, 2);
    }
}

void func_80800130_chbkcart(u8 *param_0)
{
    u8 *sp44;

    sp44 = func_80100094(param_0, 0);
    switch ((u32)*(u16 *)(param_0 + 0x72) >> 10) {
    case 1:
        if (func_8010CA74(param_0 + 4, 0x258) && !((BkCartBits2 *)param_0)->f74) {
            _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0x154B, 0xF, param_0 + 4, 0x6F);
            ((BkCartBits2 *)param_0)->f74 = 1;
        }
        func_8010CEAC(param_0);
        if (func_800DA298(0x342)) {
            func_80102424(param_0, 2);
        }
        break;
    case 2:
        if (!((BkCartBits2 *)param_0)->f4) {
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                if (func_8010C500(param_0) || (f32)func_8010C710(param_0) < 1000000.0f) {
                    *(f32 *)(param_0 + 0x54) = func_8010CD50(param_0, func_800F54E4()) - 180.0f;
                } else {
                    _subaddierouteDll_entrypoint_6(param_0, sp44, (s32)*(f32 *)(param_0 + 0x28), 0x3F, 0.4f, 0x14, 0x28);
                }
                _subaddierouteDll_entrypoint_7(param_0, sp44, *(f32 *)(param_0 + 0x48), *(f32 *)(param_0 + 0x54), 200.0f, 0x4803);
                *(f32 *)(param_0 + 0x28) = (f32)(u32)*(u16 *)(sp44 + 6);
            }
            _subaddierouteDll_entrypoint_5(param_0, sp44, (s32)*(f32 *)(param_0 + 0x28), 0.15f, 8.0f, 200.0f);
            if (func_8010CB84(param_0 + 4, 0x5DC)) {
                *(f32 *)(param_0 + 0x2C) = 400.0f;
            } else {
                *(f32 *)(param_0 + 0x2C) = 150.0f;
            }
            *(f32 *)(param_0 + 0x24) = func_800F15F8(*(f32 *)(param_0 + 0x24), *(f32 *)(param_0 + 0x2C), func_800D8FF8() * 300.0f);
            func_801026CC(param_0, D_80800864_chbkcart, *(f32 *)(param_0 + 0x24));
            func_8010C3A8(param_0, 0x305425, func_800F3780(func_80101F24(param_0), D_80800828_chbkcart, 6));
            if (func_80101E4C(param_0, D_80800858_chbkcart)) {
                func_800C4140(0xBFCFA447, param_0 + 4, 0x04B000FA);
            }
        }
        break;
    case 3:
        if (func_80101E14(param_0, 0.58f)) {
            func_800C4140(0xBFD77447, param_0 + 4, 0x04B000FA);
        } else if (func_80101DDC(param_0)) {
            func_80102424(param_0, 2);
        }
        break;
    case 4:
        if (func_80101E14(param_0, 0.58f)) {
            func_800C4140(0xBFD77447, param_0 + 4, 0x04B000FA);
        } else if (func_80101DDC(param_0)) {
            _subaddiefade_entrypoint_3(param_0);
        }
        break;
    }
}

s32 func_808004DC_chbkcart(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    switch (param_1) {
    case 0x40:
        if (!((Broad51CartFlags *)((u8 *)param_0 + 0x78))->local_0) {
            func_80102424(param_0, 4);
            _chbounce_entrypoint_3(func_8010CD50(param_0, func_800F54E4()) + 210.0f);
            param_0 = _chbounce_entrypoint_5(0x13, param_0);
            func_80108B04(param_0, 0);
            func_8010A570(param_0);
            func_800C4140(0x7FFB5C16, param_0->position, 0x04B000FA);
        }
        return 1;
    case 0x3F:
        if (!((Broad51CartFlags *)((u8 *)param_0 + 0x78))->local_0) {
            func_80102424(param_0, 3);
            func_800C4140(0x7FFB5C16, param_0->position, 0x04B000FA);
        }
        return 1;
    case 0x95:
        _subaddierouteDll_entrypoint_1(param_0);
        return 1;
    case 0x3D:
        _chbounce_entrypoint_3(func_8010CD50(param_0, func_800F54E4()) + 150.0f);
        switch (param_0->unk74_7 - 0x32) {
        case 0:
            local_0 = _chbounce_entrypoint_7(0x14, param_0->position, 0x513);
            local_0->rotation[0] = 90.0f;
            local_0->scale = 0.5f;
            break;
        case 1:
            local_0 = _chbounce_entrypoint_7(0x12, param_0->position, 0x517);
            func_80103140(local_0, 0x975, param_0->unk0->unk16);
            func_80102424(local_0, 1);
            break;
        case 2:
            local_0 = _chbounce_entrypoint_7(0x12, param_0->position, 0x517);
            func_80103140(local_0, 0x974, param_0->unk0->unk16);
            func_80102424(local_0, 1);
            break;
        }
        func_8010A590(local_0);
        return 1;
    case 0x2E:
        func_800DA544(0x342);
        func_80102424(param_0, 2);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_3(&D_80800870_chbkcart, *(s32 *)&param_0->scale);
        return 3;
    }
    return 0;
}

int chbkcart_entrypoint_0()
{
  return &D_80800880_chbkcart;
}
