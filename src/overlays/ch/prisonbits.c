#include "common.h"

extern int D_80800F78_chprisonbits[];
extern int D_80800FC0_chprisonbits[];
extern int D_80801008_chprisonbits[];
extern s32 D_80801050_chprisonbits[];
extern int D_808010A8_chprisonbits[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
typedef struct { u8 rows[3][5]; } PrisonOrder30;
extern PrisonOrder30 D_808010F0_chprisonbits;
extern void *func_80100094(Actor *, u32);
typedef struct { u8 code[6]; u8 index; } PrisonCode;
extern u8 D_80801098_chprisonbits[];
extern f32 func_8010CD28(Actor *);
extern void _gcdialogcamera_entrypoint_3(u8 *, f32);
extern void func_800EFA4C(Vec3f *, f32, f32, f32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _suexpression_entrypoint_14(void *, f32, f32);
extern u8 D_80801100_chprisonbits[];
extern s32 D_8080111C_chprisonbits[];
extern s32 D_80801144_chprisonbits[];
extern s32 D_8080112C_chprisonbits[];
extern s32 D_80801138_chprisonbits[];
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32[3], void *, void *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32[3], void *, f32);
extern u8 marker[];
extern s32 local_0;
extern u8 position_x[];
extern u8 ActorMarker[];
extern s32 func_80090128(void);
extern s32 func_8010C500(s32);
extern f32 func_800D8FF8(void);
extern void func_80102128(u8 *, s32, s32, f32, s32);
extern void func_8010CE70();
extern s32 func_8010BF4C(u8 *, u8 *, f32, s32, s32);
extern s32 func_80102CF4(u8 *, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern void func_80102844(u8 *, f32, s32, u8 *);
extern void func_801058C4(u8 *, s32, f32, s32);
void func_80800344_chprisonbits();
int func_80800CC4_chprisonbits();
int func_80800DAC_chprisonbits();

int chprisonbits_entrypoint_0()
{
  return (int)&D_80800F78_chprisonbits;
}

int chprisonbits_entrypoint_1()
{
    return (int)&D_80800FC0_chprisonbits;
}

int *chprisonbits_entrypoint_2()
{
    return &D_80801008_chprisonbits;
}

int chprisonbits_entrypoint_3()
{
    return (int)D_80801050_chprisonbits;
}

int *chprisonbits_entrypoint_4()
{
    return &D_808010A8_chprisonbits;
}

void func_8080003C_chprisonbits()
{
    _chswitch_entrypoint_7();
}

void func_8080005C_chprisonbits(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    local_0 = _subaddiefind_entrypoint_2(0x120, NULL);
    param_0->position[0] = local_0->position[0] + param_2;
    param_0->position[2] = local_0->position[2];
    func_8080003C_chprisonbits(param_0, param_1);
}

void func_808000C0_chprisonbits(Actor *param_0)
{
    PrisonOrder30 local_0 = D_808010F0_chprisonbits;
    u8 *local_1;
    u8 *local_2;
    s32 local_3;
    local_1 = func_80100094(param_0, 1);
    local_1[6] = 0;
    local_1[0] = 0;
    if (!func_800DA564(0x32B, 2)) func_800DA7A8(0x32B, func_800DC128(0, 3) + 1, 2);
    local_2 = local_0.rows[func_800DA564(0x32B, 2) - 1];
    for (local_3 = 0; local_3 < 5; local_3++) local_1[local_3] = local_2[local_3];
    local_1[5] = 0;
    func_8080005C_chprisonbits(param_0, 0, -0xAF);
    param_0->unk64_19 = func_800DA298(0xD5);
}

void func_808001E0_chprisonbits(s32 arg0)
{
    func_8080003C_chprisonbits(arg0,1);
}

void func_80800200_chprisonbits(s32 param_0) {
    func_8080005C_chprisonbits(param_0, 2, 0xAF);
}

int func_80800224_chprisonbits(Actor *param_0)
{
  if (_chdoormake_entrypoint_0(param_0, 0x42B40000, 0x60, 0xD5))
  {
    _chdoormake_entrypoint_8(param_0, 5);
    _chdoormake_entrypoint_5(param_0, 0x40400000);
    _chdoormake_entrypoint_9(param_0, 0, 0, 0x10);
  }
}

int func_80800280_chprisonbits()
{
    func_800DA298();
}

s32 func_808002A0_chprisonbits(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 7:
            func_80101180(0x11F, 10, 0);
            break;
        case 10:
            func_80800344_chprisonbits(param_0);
            break;
        case 0x91:
            if (func_800DA298(0xD5)) return 0;
        default:
            return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

void func_80800344_chprisonbits(param_0) Actor *param_0;
{
    PrisonCode *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    if (local_0->code[local_0->index]) {
        local_1 = func_80800280_chprisonbits(local_0->code[local_0->index] - 1);
        if (!local_1) {
            local_1 = func_80800280_chprisonbits(local_0->code[0] - 1);
            if (local_1) {
                local_0->index = 0;
            }
        }
        if (local_1) {
            if (func_800DA298(0xD5)) {
                local_0->index = 0;
            } else {
                if (!local_0->code[++local_0->index]) {
                    func_800DA544(0xD5);
                    func_80101180(0x11E, 7, 0);
                }
            }
        } else if (func_80800280_chprisonbits(0) || func_80800280_chprisonbits(1) || func_80800280_chprisonbits(2)) {
            local_0->index = 0;
        }
    }
}

void func_8080044C_chprisonbits(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = local_0;
    _susubgame_entrypoint_0(param_0, local_0 + 0x1C, 1);
    _susubgame_entrypoint_12(local_0 + 0x1C, ((int *) D_80801098_chprisonbits));
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(param_0, 0xA);
        return;
    }
    if ((func_800DA298(0x5C) != 0) && (func_800EA05C() == 0xB9)) {
        func_800FFAB0(param_0);
        return;
    }
    func_80800DAC_chprisonbits(param_0);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(0x127, param_0), local_0 + 0x10);
}

s32 func_80800C84_chprisonbits();

void func_80800C18_chprisonbits();

s32 func_80800BB4_chprisonbits();

void func_80800518_chprisonbits(u8 *param_0)
{
    u8 *sp4C;
    u8 *sp2C;
    f32 sp3C[3];

    sp4C = func_80100094(param_0, 0);
    func_8010C820(param_0, 0x28, 0x1E);
    if (func_80100094(param_0, 1) != 0) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), *(s32 *)param_0, 0);
    }
    switch ((u32)*(u16 *)(param_0 + 0x72) >> 10) {
    case 3:
        if (func_80800BB4_chprisonbits(param_0) == 0 && func_80800C84_chprisonbits(param_0) == 0) {
            func_80102128(param_0, 0x1F, 0x11, func_80800DFC_chprisonbits(param_0) != 0 ? 1.0f : 0.4f, 2);
        }
        break;
    case 2:
        if (func_80800DFC_chprisonbits(param_0) != 0) {
            *(f32 *)(param_0 + 0x24) = 450.0f;
            func_8010CE70(param_0, (s32)(func_800D8FF8() * 350.0f), -1);
            func_8010B990(param_0, 0x300105);
            func_80800BB4_chprisonbits(param_0);
            break;
        }
        if (func_80800BB4_chprisonbits(param_0) == 0 && func_80800C84_chprisonbits(param_0) == 0) {
            func_80102128(param_0, 0x1F, 7, 0.3f, 3);
        }
        if ((func_8010BF4C(param_0, sp4C, 420.0f, (s32)(func_800D8FF8() * 350.0f), 0x300105) & 0x24) && func_80102CF4(param_0, 20.0f) != 0) {
            func_80800DAC_chprisonbits(param_0);
        }
        if (func_800F0064((f32 *)(param_0 + 4), 100.0f, (f32 *)sp4C) != 0) {
            func_80800DAC_chprisonbits(param_0);
        }
        break;
    case 5:
        func_80800C84_chprisonbits(param_0);
        func_8010CE70(param_0, 5, 6);
        break;
    case 6:
        func_8010CE70(param_0, 6, -1);
        break;
    case 7:
        *(f32 *)(param_0 + 0x24) = 350.0f;
        func_80102844(param_0, func_800D8FF8() * 350.0f, -1, sp2C = sp4C + 0x10);
        func_8010B990(param_0, 5);
        if (func_800F0064((f32 *)sp2C, 120.0f, (f32 *)(param_0 + 4)) != 0) {
            _capod_entrypoint_22();
            func_800F7F98(func_800F54E4(), 0);
            _susubgame_entrypoint_5(param_0, sp4C + 0x1C, 3, 1, 0x2000);
            _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0xF18, 0xE, (param_0 + 4), 0x32);
            func_80102424(param_0, 4);
        }
        break;
    case 4:
        func_80800C18_chprisonbits(param_0);
        func_8010CE70(param_0, 9, -1);
        break;
    case 9:
    case 10:
        break;
    case 8:
        sp2C = sp4C + 0x10;
        func_80102844(param_0, 8.0f, -1, sp2C);
        if (func_80102CF4(param_0, 60.0f) != 0) {
            sp3C[0] = *(f32 *)(sp4C + 0x10);
            sp3C[1] = *(f32 *)(param_0 + 8);
            sp3C[2] = *(f32 *)(sp4C + 0x18);
            *(f32 *)(param_0 + 0x24) = 300.0f;
            func_8010BF4C(param_0, sp2C, 300.0f, 6, 0x1005);
            if (func_800F0064((f32 *)(param_0 + 4), 100.0f, sp3C) != 0) {
                func_801058C4(param_0, _glsplinefind_entrypoint_1(0x127), *(f32 *)(param_0 + 0x24), 1);
            }
        }
        break;
    }
}

void func_8080090C_chprisonbits(Actor *param_0)
{
    u8 *local_0;

    func_80105834(param_0);
    if (func_80105A5C(param_0)) {
        local_0 = func_80100094(param_0, 0);
        func_800DA544(0x5C);
        _susubgame_entrypoint_4(param_0, local_0 + 0x1C);
        func_800FFAB0(param_0);
    }
}

int func_80800970_chprisonbits(Actor *param_0)
{
  s32 local_0;
  local_0 = func_80100094(param_0, 0);
  if (func_80100094(param_0, 1))
  {
    _suexpression_entrypoint_8(param_0, 1);
  }
  _susubgame_entrypoint_4(param_0, local_0 + 0x1C);
}

s32 func_808009C4_chprisonbits(Actor *param_0, s32 param_1, s32 param_2)
{
  s32 pad0;
    void *local_0;
    Vec3f local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2E:
        func_80800CC4_chprisonbits(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x49:
        if (param_2 == 0xC) {
            _susubgame_entrypoint_6(param_0, (u8 *)func_80100094(param_0, 0) + 0x1C, 0x11, 0x2820, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xF42, 0x44, &param_0->position, 0x32);
            func_80102424(param_0, 9);
            break;
        }
        return 0;
    case 0x29:
        _suexpression_entrypoint_7(param_0, 1, 0x32);
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 45.0f, 15.0f);
        _suexpression_entrypoint_14(func_80100094(param_0, 1), 1.0f, 1.0f);
        break;
    case 0x2A:
        _suexpression_entrypoint_8(param_0, 1, param_1);
        break;
    case 0x57:
        return _susubgame_entrypoint_3(param_0, (u8 *)local_0 + 0x1C, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x52:
        func_800EFA4C(&local_1, 0.0f, func_8010CD28(param_0), 0.0f);
        _gcdialogcamera_entrypoint_3(D_80801098_chprisonbits, param_0->scale);
        _gcdialogcamera_entrypoint_5(&local_1);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_80800BB4_chprisonbits(Actor *param_0)
{
    s32 local_0;

    local_0 = _subaddiedialog_entrypoint_7(param_0, param_0->position, D_80801100_chprisonbits);
    if (local_0 != 0 && local_0 != 0x1208) {
        _susubgame_entrypoint_5(param_0, (u8 *)func_80100094(param_0, 0) + 0x1C, 4, 0, 0);
    }
    return local_0;
}

void func_80800C18_chprisonbits(Actor *param_0)
{
    _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_8080111C_chprisonbits, &D_80801144_chprisonbits);
    _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_8080112C_chprisonbits, 0.75f);
    _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80801138_chprisonbits, 0.6f);
}

s32 func_80800C84_chprisonbits(s32 param_0)
{
    if (func_800DA298(0x514) != 0)
    {
        func_80102424(param_0, 7);
        return 1;
    }
    return 0;
}

int func_80800CC4_chprisonbits(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  u32 local_0;
  int new_var;
  local_0 = (s32)func_80100094(param_0 | 0, 0) | 0;
  switch (param_1)
  {
    case 0xF18:
      new_var = local_0;
      func_80102424(param_0 | 0, 8, param_1);
      _susubgame_entrypoint_6(param_0 | 0, new_var + 0x1C, 0xE, 0x2030, 0);
      return;

    case 0xF42:
      _susubgame_entrypoint_4(param_0 | 0, local_0 + 0x1C, param_1);
      _glcutDll_entrypoint_17();
      return;

    case 0xF4F:
      _susubgame_entrypoint_4(param_0 | 0, local_0 + 0x1C, param_1);
      func_80102424(param_0 | 0, 3);
      return;

    default:
      _susubgame_entrypoint_4(param_0 | 0, local_0 + 0x1C, param_1);
      func_80102424(param_0 | 0, 3);
      return;
  }
}

int func_80800DAC_chprisonbits(param_0) Actor *param_0;
{
    s32 *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800CD08C(((u32)(*(s32 *)((char *)param_0 + 0x70)) >> 25) - 1, local_0);
    *(f32 *)((char *)(local_0) + 0x4) = *(f32 *)((char *)param_0 + 0x8);
}

int func_80800DFC_chprisonbits(s32 param_0) {
    return func_800DA298(0x5B) == 0 && func_80090128() != 0 && func_8010C500(param_0) != 0;
}

void chprisonbits_entrypoint_5(s32 param_0, s32 param_1) {
    s32 *local_0;

    local_0 = _subaddiefind_entrypoint_2(0x117, 0);
    if ((local_0 != NULL) && (func_800DA298(0x6A4) == 0)) {
        _susubgame_entrypoint_6(local_0, (s32)func_80100094(local_0, 0) + 0x1C, 2, 0x430, 0);
        _subaddiedialog_entrypoint_11(*local_0, 0xF4F, 0x44, local_0 + 1, 0x32);
        func_80102424(local_0, 9);
        func_800DA544(0x6A4);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/prisonbits.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800F78_chprisonbits -> int[], D_80800FC0_chprisonbits -> int[], D_80801008_chprisonbits -> int[], D_808010A8_chprisonbits -> int[], D_8080111C_chprisonbits -> s32[], D_8080112C_chprisonbits -> s32[], D_80801138_chprisonbits -> s32[], D_80801144_chprisonbits -> s32[] */
extern void _chdoor_entrypoint_0();
extern int func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
u32 D_80800F20_chprisonbits[22] = { 0x0, 0x0, 0x0, 0x0, 0x3ECCCCCD, 0x1DA0001, 0x40A66666, 0x1D90001, 0x40066666, 0x1DB0001, 0x3E99999A, 0x1DA0001, 0x40A66666, 0x1D90001, 0x3E99999A, 0x1DA0001, 0x3E99999A, 0x1DA0001, 0x40A66666, 0x1D90001, 0x40A66666, 0x1D90001 };
int D_80800F78_chprisonbits[18] = { 0xE011E, 0x6470001, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x800, 0x0, 0x0, 0x0, (u32)func_80800224_chprisonbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)_chdoor_entrypoint_1, 0x0 };
int D_80800FC0_chprisonbits[18] = { 0xF011F, 0x6440001, (u32)&D_8011A270, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, 0x0, 0x0, 0x7, (u32)func_808000C0_chprisonbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_808002A0_chprisonbits, 0x0 };
int D_80801008_chprisonbits[18] = { 0x130120, 0x6450001, (u32)&D_8011A270, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, 0x0, 0x0, 0x0, (u32)func_808001E0_chprisonbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_808002A0_chprisonbits, 0x0 };
s32 D_80801050_chprisonbits[18] = { 0x150121, 0x6460001, (u32)&D_8011A270, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, 0x0, 0x0, 0x0, (u32)func_80800200_chprisonbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_808002A0_chprisonbits, 0x0 };
u8 D_80801098_chprisonbits[16] = { 0x42, 0xA0, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0, 0x41, 0x20, 0x0, 0x0 };
int D_808010A8_chprisonbits[18] = { 0x360117, 0x66D0003, (u32)&D_80800F20_chprisonbits, (u32)func_80800518_chprisonbits, (u32)func_8080090C_chprisonbits, (u32)func_80101870, 0x9C40000, 0x3F800000, 0x0, 0x121, (u32)func_80800970_chprisonbits, 0x0, 0x340000, (u32)func_8080044C_chprisonbits, (u32)func_80107C2C, -0x7FFFBB7E, (u32)func_808009C4_chprisonbits, 0x0 };
PrisonOrder30 D_808010F0_chprisonbits = { 0x3, 0x2, 0x1, 0x2, 0x3, 0x1, 0x3, 0x1, 0x2, 0x2, 0x2, 0x1, 0x3, 0x1, 0x1 };
u8 D_80801100_chprisonbits[28] = { 0x0, 0x5B, 0x1, 0x5E, 0xF, 0x16, 0xF, 0x17, 0x0, 0x0, 0x2, 0x81, 0x12, 0x8, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0 };
s32 D_8080111C_chprisonbits[4] = { 0x130402, 0x1636B0, 0xA0119, 0x0 };
s32 D_8080112C_chprisonbits[3] = { 0x13044C, 0x163A98, 0x0 };
s32 D_80801138_chprisonbits[3] = { 0x13043A, 0xD01CC, 0x1FD0000 };
s32 D_80801144_chprisonbits[3] = { 0x3E8A3D71, 0x3F000000, -0x40800000 };
