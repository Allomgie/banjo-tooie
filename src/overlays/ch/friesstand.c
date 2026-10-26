#include "ch/friesstand.h"

extern void func_80102424(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80090734(s32, f32 *);
extern void *func_80100094(Actor *, u32);
extern int D_80800EC8_chfriesstand;
extern int D_80800F10_chfriesstand;
extern s32 D_80800FA0_chfriesstand[];
extern int D_80801000_chfriesstand;
extern int D_8080100C_chfriesstand;
extern int D_8080102C_chfriesstand;
extern int D_80801038_chfriesstand;
extern int D_80801044_chfriesstand;
extern int D_80801050_chfriesstand;
extern int D_8080101C_chfriesstand;
extern int D_8080105C_chfriesstand;
extern s32 D_80801088_chfriesstand;
extern u8 D_80800E50_chfriesstand[];
extern s32 _subaddiedialog_entrypoint_8();
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern void _capod_entrypoint_14(void);
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
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void func_80101180(s32, s32, s32);
extern s32 _chswitch_entrypoint_10(Actor *, s32);
extern s32 D_80800FE8_chfriesstand;
extern s32 func_80102320(Actor *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800F4EC8(s32, f32 *, f32, f32, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
typedef union { u32 local_0; s16 local_1[2]; } StandEvent_chfriesstand;
extern u32 D_80800FF0_chfriesstand[];
extern void func_80101EE4(Actor *, f32);
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
extern u8 D_8080106C_chfriesstand[];
extern void func_800BABB8(s32, f32 *, s32, f32, void *);
extern void func_800BA994();
void func_808006D4_chfriesstand();

int chfriesstand_entrypoint_0()
{
    return (int)&D_80800EC8_chfriesstand;
}

int chfriesstand_entrypoint_1()
{
    return (int)&D_80800F10_chfriesstand;
}

int chfriesstand_entrypoint_2()
{
    extern int D_80800F58_chfriesstand;
    return (int)&D_80800F58_chfriesstand;
}

int chfriesstand_entrypoint_3()
{
    return D_80800FA0_chfriesstand;
}

void func_80800030_chfriesstand(Actor *param_0)
{
  s32 temp_v0;
  Actor *new_var;
  new_var = param_0;
  if (_glcutDll_entrypoint_20() != 0)
  {
    func_80102424(new_var, 5);
  }
  else
  {
    *((u8 *) (((u8 *) new_var) + 0x65)) = (u8) (((*((u8 *) (((u8 *) new_var) + 0x65))) & 0xFFFE) | ((func_800DA298(0xA0) & 0xFFFFu) & 1));
  }
  func_80103110(new_var, (*((u16 *) (((u8 *) param_0) + 0x64))) & 1);
  temp_v0 = _subaddiefind_entrypoint_2(0x331, 0);
  if (temp_v0 != 0)
  {
    func_800EE7F8(((u8 *) param_0) + 0x18, temp_v0 + 4);
    *((f32 *) (((u8 *) param_0) + 0x1C)) = (f32) (*((f32 *) (((u8 *) param_0) + 8)));
  }
}

void func_808009A4_chfriesstand();

void func_808005F0_chfriesstand();

void func_808000C4_chfriesstand(Actor *param_0)
{
    s32 local_1;

    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
        if (func_801022E4(param_0) != 0xD0 || !func_80102320(param_0, 0.45f, 0.85f)) {
            _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
        }
    }
    func_800F4EC8(func_800F54E4(), (f32 *)param_0->actorData, 300.0f, -10.0f, 200.0f);
    switch (param_0->unk70_10) {
    case 1:
        func_808005F0_chfriesstand(param_0);
        if (func_80101E14(param_0, 0.999f)) {
            if (param_0->unk6C_0 < 2U) param_0->unk6C_0++;
            else func_80102424(param_0, 2);
        }
        func_808009A4_chfriesstand(param_0);
        return;
    case 2:
        func_80800620_chfriesstand(param_0);
        func_808006D4_chfriesstand(param_0);
        if (func_80101DDC(param_0)) {
            param_0->unk6C_0 = 0;
            func_80102424(param_0, 1);
        }
        func_808009A4_chfriesstand(param_0);
        return;
    case 3:
        func_808005F0_chfriesstand(param_0);
        return;
    case 4:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80800FE8_chfriesstand, 0.7f);
        if (func_80101E14(param_0, 0.837f)) {
            if (param_0->unk3C) {
                func_800FC660(0xE);
                func_800D175C(0x4C, 5 - func_800D1A04(0x4C));
                func_800FFA88(param_0->unk3C);
                param_0->unk3C = 0;
            }
            if (func_800F64A4(func_800F54E4(), 0x200)) local_1 = 0x110B;
            else local_1 = 0x10FD;
            _subaddiedialog_entrypoint_11(param_0->unk0, local_1, 6, param_0->position, 0x51);
        }
        if (func_80101DDC(param_0)) {
            param_0->unk6C_0 = 0;
            func_80102424(param_0, 1);
        }
        return;
    case 5:
        func_808005F0_chfriesstand(param_0);
        if (func_80101DDC(param_0)) func_80102424(param_0, 6);
        break;
    case 6:
        func_80800620_chfriesstand(param_0);
        func_808006D4_chfriesstand(param_0);
        if (func_80101DDC(param_0)) func_80102424(param_0, 5);
        break;
    }
}

void func_80800398_chfriesstand(Actor* arg0)
{
    func_80800970_chfriesstand(arg0);
}

void func_80800BB0_chfriesstand();

void func_80800AEC_chfriesstand();

void func_808009F0_chfriesstand();

s32 func_80800904_chfriesstand();

s32 func_808003B8_chfriesstand(Actor *param_0, s32 param_1, StandEvent_chfriesstand param_2)
{
    Actor *local_0;
    u32 local_1;
    switch (param_1) {
    default:
        return 0;
    case 0x2E:
        func_808009F0_chfriesstand(param_0, param_2.local_1[0], param_2.local_1[1]);
        return 1;
    case 0x2F:
        func_80800AEC_chfriesstand(param_0, param_2.local_1[0], param_2.local_1[1]);
        return 1;
    case 0x32:
        func_80090734(2, param_0->position);
        return 1;
    case 0x3D:
        func_80800BB0_chfriesstand(param_0);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800FF0_chfriesstand, param_0->scale);
        return 1;
    case 0xA:
        param_0->unk64_16 = 1;
        func_80102424(param_0, 3);
        func_80101EE4(param_0, 0.0f);
        func_80103110(param_0, 1);
        if (param_0->unk3C) {
            local_0 = func_80106790(param_0->unk3C);
            local_0->unk64_16 = param_0->unk64_16;
        }
        _capod_entrypoint_13(param_0->unk0, 0, 0x16, 0x30);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x10E0, 4, param_0->position, 0x51);
        return 1;
    case 0x29:
        func_80800904_chfriesstand(param_0);
        return 1;
    case 0x2A:
        func_80800970_chfriesstand(param_0);
        return 1;
    case 0x95:
        if (!func_800D1A04(0x4C)) func_80108B04(param_0, 0);
        break;
    case 0xB8:
        local_1 = param_2.local_0 & 0xFFFF;
        switch (local_1) {
        default: return 0;
        case 1: return param_0->unk3C ? 0x10AE : 0x10AF;
        case 2: return param_0->unk3C ? 0x1109 : 0x110A;
        }
    }
    return 1;
}

void func_808005F0_chfriesstand(s32 param_0)
{
  _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_80801000_chfriesstand, &D_8080100C_chfriesstand);
}

int func_80800620_chfriesstand(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_8080102C_chfriesstand, 0.0799999982f);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80801038_chfriesstand, 0.230000004f);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80801044_chfriesstand, 0.340000004f);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80801050_chfriesstand, 0.419999987f);
  _subaddieaudioquick_entrypoint_4(local_0, local_0 + 4, &D_8080101C_chfriesstand, &D_8080105C_chfriesstand);
}

void func_808006D4_chfriesstand(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    f32 local_2;
    f32 local_3;
    if (func_80101E14(param_0, 0.345f)) {
        if (!_subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_0)) return;
        func_800EF1B8(local_0, param_0->rotation[1], 20.0f); local_1 = func_800B53A4(12); func_800BABB8(local_1, local_0, 0, param_0->scale, D_8080106C_chfriesstand);
        func_800BA610(local_1, -100, -100);
        local_2 = param_0->rotation[1]; local_3 = param_0->scale; func_800BA994(local_1, 15, (s16)(s32)(local_2 - 50.0f), (s16)(s32)(local_3 * 300.0f), 20, (s32)(local_2 + 50.0f), (s32)(local_3 * 450.0f));
        func_800BA22C(local_1, 12);
    }
    if (func_80101E14(param_0, 0.43f) && _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_0)) {
        local_1 = func_800B53A4(5); func_800BABB8(local_1, local_0, 0, param_0->scale * 1.2f, D_8080106C_chfriesstand);
        func_800BA610(local_1, -800, -1000);
        local_2 = param_0->rotation[1] + 90.0f; local_3 = param_0->scale; func_800BA994(local_1, -25, (s16)(s32)(local_2 - 10.0f), (s16)(s32)(local_3 * 200.0f), -15, (s32)(local_2 + 10.0f), (s32)(local_3 * 400.0f));
        func_800BA22C(local_1, 5);
    }
}

s32 func_80800904_chfriesstand(Actor *this)
{
  if (!func_80100094(this, 1))
  {
    _suexpression_entrypoint_7(this, 1, 0x51);
    _suexpression_entrypoint_12(func_80100094(this, 1), 0x42480000, 0x41A00000);
    _suexpression_entrypoint_17(func_80100094(this, 1), 0x3E8);
  }
}

void func_80800970_chfriesstand(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808009A4_chfriesstand(u8 *param_0) {
    if (_subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_80801088_chfriesstand, &D_80800E50_chfriesstand, 5)) {
        func_80090734(1, (f32 *)(param_0 + 4));
    }
}

void func_808009F0_chfriesstand(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x10E0:
            _capod_entrypoint_14();
            param_0->unk6C_0 = 0;
            func_80102424(param_0, 1);
            break;
        case 0x10FD:
        case 0x110B:
            func_8008FC9C(0);
            func_80102424(param_0, 1);
            break;
        default:
            if (param_0->unk3C && _subaddiedialog_entrypoint_9(param_0, param_1, D_80800E50_chfriesstand, 5) == 2) {
                func_80102424(param_0, 4);
                func_80102424(func_80106790(param_0->unk3C), 2);
            } else {
                param_0->unk6C_0 = 0;
                func_80102424(param_0, 1);
                func_80090708(0);
            }
            break;
    }
}

void func_80800AEC_chfriesstand(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    f32 local_3;

    if (param_0->unk3C) {
        local_2 = _subaddiedialog_entrypoint_9(param_0, param_1, D_80800E50_chfriesstand, 5);
        if (local_2 != 2) {
            return;
        }
        func_8010D254(local_1);
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], 255.0f);
        local_3 = func_800EEAD4(local_1, local_0);
        if (local_3 > 50.0f) {
            func_80090708(0);
            func_8008F8B0();
            func_8008F904(func_8010D5DC, param_0->unk0);
            func_8008F990(local_0, 170.0f);
        }
    }
}

void func_80800BB0_chfriesstand(Actor *param_0)
{
    Actor *local_1;
    f32 local_0[3];

    local_1 = func_801084B0(0x32E, &param_0);
    func_80102FDC(local_1, param_0->scale);
    _subaddiefade_entrypoint_9(param_0, local_0);
    _subaddiefade_entrypoint_11(local_1, local_0);
    param_0->unk3C = local_1->unk0;
    local_1->unk64_16 = param_0->unk64_16;
}

void func_80800C34_chfriesstand(s32 arg0) 
{
}
void func_80800C3C_chfriesstand(Actor *param_0)
{
    int local_0;

    if (func_800EA05C() == 0x124) {
        func_8010A624(param_0);
    }
    param_0->position[1] -= 225.0f;
    if (_glcutDll_entrypoint_20()) {
        local_0 = -1;
        func_80101FDC(param_0, 4);
    } else {
        local_0 = 0xA0;
    }
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 225.0f, 0x20, local_0)) {
        _chdoormake_entrypoint_5(param_0, 2.0f);
        _chdoormake_entrypoint_8(param_0, 3);
    }
}

void func_80800CF0_chfriesstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_0A0_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800D1C_chfriesstand(Actor *param_0, s32 param_1)
{
    if (param_1 == 7) {
        func_80101180(0x331, 7, 0);
        func_80101180(0x32D, 10, 0);
    } else {
        return _chswitch_entrypoint_10(param_0, param_1);
    }
    return 1;
}
