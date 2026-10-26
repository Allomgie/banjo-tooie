#include "common.h"

extern int D_80801240_chamazongoldhordeofficial;
extern void *func_80100094(Actor *, u32);
extern void func_8010A3E8(Actor *, f32);
typedef struct { s16 local_0[3]; u16 local_1 : 9; u16 pad_0 : 7; u32 pad_1; u32 local_2 : 9; u32 pad_2 : 23; } GoldHordeProp;
extern s16 D_808012D0_chamazongoldhordeofficial[];
extern f32 D_808012DC_chamazongoldhordeofficial[];
extern s16 D_808012F4_chamazongoldhordeofficial[];
extern s32 D_808012FC_chamazongoldhordeofficial[];
extern void func_800EEB9C(f32 *, f32, f32);

extern s32 func_80101E14(Actor *, f32);
extern void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern f32 func_800136E4(f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA994(s32, s32, s16, s32, s32, s32, s32);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 func_800F640C(s32, s32);
extern s32 func_800F54E4(void);
extern s32 func_8008FE14(void);
extern s32 D_80801324_chamazongoldhordeofficial;
extern s32 D_80801340_chamazongoldhordeofficial;
extern s32 D_8080135C_chamazongoldhordeofficial;
void _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
typedef struct { u8 pad[0x68]; u8 cycles; } GoldHordeOfficialState;
extern u8 D_808011D0_chamazongoldhordeofficial[];
extern u8 D_80801368_chamazongoldhordeofficial[];
extern u8 D_80801380_chamazongoldhordeofficial[];
typedef struct { u8 pad_0[8]; s16 local_0; s16 local_1; s16 local_2[15]; s16 local_3[15]; u8 local_4; u8 local_5[15]; u8 local_6[15]; u8 local_7; u8 pad_1[2]; s16 local_8; u8 local_9[1]; } GoldOfficialState601;
extern s32 D_80801288_chamazongoldhordeofficial;
extern s32 D_80801294_chamazongoldhordeofficial;
extern s32 D_808012A0_chamazongoldhordeofficial;
extern s32 D_808012BC_chamazongoldhordeofficial;
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern f32 func_800D8FF8(void);
extern void func_80102924(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern f32 func_800F5F7C(s32);
extern f32 func_8010CD28(Actor *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_8008F990(f32 *, f32);
extern void func_8010D5DC(Unk80132ED0 *);
extern void func_800902E4(f32 *, f32, s32, Actor **);
extern u8 D_808011C0_chamazongoldhordeofficial[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
void func_80800DB4_chamazongoldhordeofficial();
void func_80800E18_chamazongoldhordeofficial();
int func_80800F40_chamazongoldhordeofficial();

int chamazongoldhordeofficial_entrypoint_0()
{
    return (int)&D_80801240_chamazongoldhordeofficial;
}

void func_8080000C_chamazongoldhordeofficial(Actor *param_0)
{
    GoldHordeProp *local_0[15];
    u8 *local_1;
    s32 local_2;

    local_1 = func_80100094(param_0, 0);
    func_8010A3E8(param_0, 0.65f);
    _subaddieDll_entrypoint_10(0x125, local_1);
    *(s16 *)(local_1 + 8) = -999;
    *(s16 *)(local_1 + 0x6A) = 1;
    local_1[0x48] = _gccubesearch_entrypoint_9(0x122, local_0, 15);
    for (local_2 = 0; local_2 < local_1[0x48]; local_2++) {
        ((s16 *)(local_1 + 0xC))[local_2] = local_0[local_2]->local_0[0];
        ((s16 *)(local_1 + 0x2A))[local_2] = local_0[local_2]->local_0[2];
        local_1[0x49 + local_2] = local_0[local_2]->local_1;
        local_1[0x58 + local_2] = local_0[local_2]->local_2 >> 1;
    }
    func_80800DB4_chamazongoldhordeofficial(param_0, -1);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x127, param_0->position), (u8 *)param_0 + 0x18);
    _susubgame_entrypoint_0(param_0, (u8 *)func_80100094(param_0, 0) + 0x6C, 0);
    _susubgame_entrypoint_12((u8 *)func_80100094(param_0, 0) + 0x6C, ((s32 *) D_808011C0_chamazongoldhordeofficial));
}

void func_80800E94_chamazongoldhordeofficial();

void func_80800E64_chamazongoldhordeofficial();

s32 func_80800C60_chamazongoldhordeofficial();

void func_80800A84_chamazongoldhordeofficial();

void func_80800150_chamazongoldhordeofficial(Actor *param_0)
{
    GoldOfficialState601 *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[3];

    local_0 = func_80100094(param_0, 0);
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    _sudeflect_entrypoint_0(param_0->position, 150.0f, 150.0f, 10);
    switch (param_0->unk70_10) {
    case 1:
        func_80800E64_chamazongoldhordeofficial((s32)param_0);
        if (local_0->local_0 == -999) {
            _subaddieDll_entrypoint_12(local_0, &local_0->local_0);
        }
        if (func_80800F40_chamazongoldhordeofficial(param_0, local_0->local_0, local_0->local_1)) {
            func_80800E18_chamazongoldhordeofficial(param_0);
        }
        func_80800C60_chamazongoldhordeofficial(param_0);
        break;
    case 2:
        func_80800E64_chamazongoldhordeofficial((s32)param_0);
        if (func_80800F40_chamazongoldhordeofficial(param_0,
            local_0->local_2[local_0->local_7], local_0->local_3[local_0->local_7])) {
            func_80102424(param_0, 3);
        }
        func_80800C60_chamazongoldhordeofficial(param_0);
        break;
    case 3:
        func_80800E64_chamazongoldhordeofficial((s32)param_0);
        func_80102924(param_0, (f32)(local_0->local_6[local_0->local_7] * 2));
        func_80102B2C(param_0, func_800D8FF8() * 180.0f);
        if (func_80102CF4(param_0, 10.0f)) {
            func_80102424(param_0, 4);
        }
        func_80800C60_chamazongoldhordeofficial(param_0);
        break;
    case 4:
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80801288_chamazongoldhordeofficial, &D_808012A0_chamazongoldhordeofficial);
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80801294_chamazongoldhordeofficial, &D_808012BC_chamazongoldhordeofficial);
        func_80800A84_chamazongoldhordeofficial(param_0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 5);
        }
        func_80800C60_chamazongoldhordeofficial(param_0);
        break;
    case 5:
        func_80800E64_chamazongoldhordeofficial((s32)param_0);
        func_80102924(param_0, (f32)(local_0->local_6[local_0->local_7] * 2 + local_0->local_8 * 120));
        func_80102B2C(param_0, func_800D8FF8() * 630.0f);
        if (func_80102CF4(param_0, 10.0f)) {
            if (local_0->local_8 == 1) {
                local_0->local_8 = -1;
            } else {
                local_0->local_8 = 1;
            }
            func_80102424(param_0, 1);
        }
        func_80800C60_chamazongoldhordeofficial(param_0);
        break;
    case 6:
        func_80800C60_chamazongoldhordeofficial(param_0);
        func_80800E94_chamazongoldhordeofficial(param_0);
        break;
    case 7:
        func_8010CEAC(param_0);
        break;
    case 9:
        func_8010CEAC(param_0);
        break;
    case 10:
        local_1 = func_800F54E4();
        func_8010CEAC(param_0);
        if (!param_0->unk64_19 && func_800F5F7C(local_1) < 10.0f &&
            func_800F56AC(local_1) != 0x12 && func_800F64A4(local_1, 1)) {
            func_800EEB9C(local_2, func_8010CD28(param_0), 400.0f);
            func_800EF04C(local_2, param_0->position);
            func_8008F8B0();
            func_8008F904(func_8010D5DC, param_0->unk0);
            func_8008F8D8(1);
            func_8008F990(local_2, 300.0f);
            _susubgame_entrypoint_6(param_0, (u8 *)func_80100094(param_0, 0) + 0x6C, 0x12, 0x60, 0);
            func_80102424(param_0, 7);
            param_0->unk64_19 = 1;
        }
        break;
    case 11:
        func_8010CEAC(param_0);
        func_80800E94_chamazongoldhordeofficial(param_0);
        func_800902E4(param_0->position, 500.0f, 0x1D9, &param_0);
        if (func_8008FE14() == 0x1D9 && func_80090818()) {
            func_800EEB9C(local_3, func_8010CD28(param_0), 200.0f);
            func_800EF04C(local_3, param_0->position);
            func_80090768(local_3);
            func_800DA544(0x5A);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xF2D, 0xE, param_0->position, 0x31);
            func_80102424(param_0, 6);
        }
        break;
    }
}

int func_80800630_chamazongoldhordeofficial(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _suexpression_entrypoint_8(local_0, 1);
  if (_susubgame_entrypoint_2(local_0, (s32)func_80100094(local_0, 0) + 0x6C))
  {
    _susubgame_entrypoint_4(local_0, (s32)func_80100094(local_0, 0) + 0x6C);
  }
}

void func_80800690_chamazongoldhordeofficial(u8 *param_0)
{
    s32 local_6;

    local_6 = _gccubesearch_entrypoint_15((*(u32 *)(param_0 + 0x6C) << 11) >> 20, *(u32 *)(param_0 + 0x6C) >> 21, param_0 + 4, param_0);
    _gspropctrl_entrypoint_11(local_6, param_0 + 4);
    *(f32 *)(param_0 + 0x48) = (f32)_gspropctrl_entrypoint_12(local_6);
}

void func_80801060_chamazongoldhordeofficial();

void func_80800CD8_chamazongoldhordeofficial();

s32 func_808006F8_chamazongoldhordeofficial(u8 *param_0, s32 param_1, s32 param_2) {
    f32 sp3C[3];
    f32 sp30[3];

    switch (param_1) {
    case 0x3D:
        func_80801060_chamazongoldhordeofficial(param_0);
        break;
    case 0x2E:
        func_80800CD8_chamazongoldhordeofficial(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0xB:
        if (param_2 == 4) {
            _capod_entrypoint_14();
            _glcutDll_entrypoint_6(0x119, 0x34);
            return 4;
        }
        return 3;
    case 0x52:
        func_800EFA4C(sp3C, 0, func_8010CD28(param_0), 0);
        _gcdialogcamera_entrypoint_3(&D_808011C0_chamazongoldhordeofficial, *(s32 *)(param_0 + 0x38));
        _gcdialogcamera_entrypoint_5(sp3C);
        break;
    case 0x57:
        return _susubgame_entrypoint_3(param_0, (s32)func_80100094(param_0, 0) + 0x6C, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 0x10);
    case 0x95:
        _suexpression_entrypoint_7(param_0, 1, 0x31);
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 0x42A00000, 0x41200000);
        if (func_800DA298(0x5A) != 0 || _glcutDll_entrypoint_20() != 0) {
            func_80102424(param_0, 6);
            if (_glcutDll_entrypoint_20() == 0) {
                func_80108B04(param_0, 0);
            }
            if (func_800DA298(0x59C) == 0 && _glcutDll_entrypoint_20() == 0) {
                _susubgame_entrypoint_5(param_0, (s32)func_80100094(param_0, 0) + 0x6C, 3, 1, 0x2000);
                _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0xF59, 0xE, param_0 + 4, 0x31);
            }
        } else if (func_80800C18_chamazongoldhordeofficial() != 0 && func_8008FD48() == 1) {
            func_80800690_chamazongoldhordeofficial(param_0);
            func_80102424(param_0, 0xA);
        } else if (func_800EA090() == 1 && func_800DA298(0x59C) == 0 && func_8008FD48() == 1) {
            func_80800690_chamazongoldhordeofficial(param_0);
            func_800EEB9C(sp30, *(f32 *)(param_0 + 0x48), 3e+02f);
            func_800EF04C(sp30, param_0 + 4);
            func_8008F8B0();
            func_8008F904(&func_8010D5DC, *(s32 *)param_0);
            func_8008F8D8(1);
            func_8008F990(sp30, 3e+02f);
            _susubgame_entrypoint_6(param_0, (s32)func_80100094(param_0, 0) + 0x6C, 0xF, 0x60, 0);
            func_80102424(param_0, 9);
        } else {
            func_80800E18_chamazongoldhordeofficial(param_0);
        }
        break;
    case 0x32:
        func_800904C8(0x8D);
        if (((u32)*(u16 *)(param_0 + 0x72) >> 0xA) == 9) {
            _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0xF0D, 0xE, param_0 + 4, 0x31);
        } else {
            func_80102424(param_0, 0xB);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800A84_chamazongoldhordeofficial(Actor *param_0)
{
    f32 local_0[2];
    f32 local_2[3];
    u32 i;
    s32 local_3;

    if (param_0->unk7C_12) {
        for (i = 0; i < 6; i++) {
            if (func_80101E14(param_0, D_808012DC_chamazongoldhordeofficial[i])) {
                _subaddieskeleton_entrypoint_2(param_0->unk0, D_808012D0_chamazongoldhordeofficial[i], local_2);
                local_0[0] = func_800136E4(param_0->rotation[1] + 180.0f - 45.0f);
                local_0[1] = func_800136E4(local_0[0] + 90.0f);
                for (i = 0; D_808012F4_chamazongoldhordeofficial[i] != -1; i++) {
                    local_3 = func_800BABB8(0, local_2, NULL, 1.0f, D_808012FC_chamazongoldhordeofficial);
                    func_800BA994(local_3, 0x118, local_0[0], 0x258, 0x140, local_0[1], 0x320);
                    func_800BA670(local_3, D_808012F4_chamazongoldhordeofficial[i]);
                    func_800BA22C(local_3, 2);
                }
                return;
            }
        }
    }
}

int func_80800C18_chamazongoldhordeofficial(void) {
    return func_800F640C(func_800F54E4(), 0x1D9) != 0 || func_8008FE14() == 0x1D9;
}

s32 func_80800C60_chamazongoldhordeofficial(s32 param_0) {
    if (func_800F56AC(func_800F54E4()) == 0x12) {
        return 0;
    }
    if (func_800DA298(0x5A) != 0) {
        return _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_80801340_chamazongoldhordeofficial);
    }
    return _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_80801324_chamazongoldhordeofficial);
}

void func_80800CD8_chamazongoldhordeofficial(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0 = param_0;
  switch (param_1)
  {
    case 0xF2D:
      _susubgame_entrypoint_4(local_0, (s32)func_80100094(local_0, 0) + 0x6C);
      func_800D1000(5, 1, 0, 1, 0);
      _capod_entrypoint_13(*(s32*)((char*)local_0 + 0x0), 0, 4, 0x2830);
      return;
    case 0xF0D:
    case 0xF59:
      _susubgame_entrypoint_4(local_0, (s32)func_80100094(local_0, 0) + 0x6C);
      func_800DA544(0x59C);
      _glcutDll_entrypoint_6(0xB8, 0xD);
      return;
    default:
      func_80800E18_chamazongoldhordeofficial(local_0);
    case 0xF2E:
      return;
  }
}

void func_80800DB4_chamazongoldhordeofficial(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    do {
        local_0[0x67] = func_800DC128(0, local_0[0x48] - 1);
    } while (param_1 == local_0[0x67]);
    *(f32 *)&param_0->actorData[3] = 700.0f;
}

void func_80800E18_chamazongoldhordeofficial(param_0) void *param_0;
{
  void *local_0 = func_80100094(param_0, 0);
  func_80800DB4_chamazongoldhordeofficial(param_0, ((u8 *) local_0)[0x67]);
  func_80102424(param_0, 2);
  *((s16 *) (((u8 *) local_0) + 0x8)) = -999;
}

void func_80800E64_chamazongoldhordeofficial(s32 param_0)
{
  _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, ((s32 *) D_808011D0_chamazongoldhordeofficial), &D_8080135C_chamazongoldhordeofficial);
}

void func_80800E94_chamazongoldhordeofficial(Actor *param_0)
{
    GoldHordeOfficialState *local_0;
    s32 local_1;

    _subaddieaudioquick_entrypoint_4(param_0, param_0->position,
        D_808011D0_chamazongoldhordeofficial, D_80801368_chamazongoldhordeofficial);
    if (func_80101E14(param_0, 0.5f)) {
        local_0 = func_80100094(param_0, 0);
        local_0->cycles++;
        local_1 = _glcutDll_entrypoint_20() ? 1 : 5;
        if (local_1 < local_0->cycles) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                D_80801380_chamazongoldhordeofficial);
            local_0->cycles = 0;
        }
    }
}

int func_80800F40_chamazongoldhordeofficial(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;
    local_0[0] = param_1;
    local_0[1] = param_0->position[1];
    local_0[2] = param_2;
    if (func_800F0064(param_0->position, 200.0f, local_0)) local_1 = func_800D8FF8() * 630.0f;
    else local_1 = func_800D8FF8() * 180.0f;
    func_80102924(param_0, func_80102D78(param_0, local_0));
    func_80102B2C(param_0, local_1);
    local_2 = func_800F0064(param_0->position, 80.0f, local_0);
    if (!local_2) func_8010B990(param_0, 0x201005);
    return func_80102CF4(param_0, 10.0f) && local_2;
}

void func_80801060_chamazongoldhordeofficial(Actor *param_0)
{
    extern void func_800EEB9C(f32 *, f32, f32);
    extern f32 func_800F1DCC(f32, f32);
    f32 local_0[3];
    Actor *local_1;

    func_800EEB9C(local_0, param_0->rotation[1], 200.0f);
    func_800EF04C(local_0, param_0->position);
    local_1 = (Actor *)func_80108528(0x1D9, local_0, 0, &param_0);
    local_1->rotation[1] = func_800F1DCC(param_0->rotation[1], 180.0f);
}
