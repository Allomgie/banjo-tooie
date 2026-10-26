#include "common.h"

extern s32 D_80802590_chtntmineshoot;
extern s32 D_8080259C_chtntmineshoot;
extern void func_800C4AF0(int, void *);
extern int D_808025A8_chtntmineshoot;
extern s16 D_808025CC_chtntmineshoot[];
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_800187B4(s32, f32, f32, f32);
extern u32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern s32 D_808025DC_chtntmineshoot;
extern f32 func_800F5F24(s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 D_808025F8_chtntmineshoot[];
extern u8 D_80802644_chtntmineshoot[];
extern void _subaddierouteDll_entrypoint_3();
extern void *func_80100094(Actor *, u32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_8010CD28(Actor *);
extern f32 func_800136E4(f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct { u8 pad_0; u8 state; u8 pad_1[2]; u8 mode; u8 pad_2[3]; f32 time; } MineShootState;
extern f32 func_800DC0C0(void);
extern f32 func_800D8FF8(void);
extern int D_80802690_chtntmineshoot;
extern s32 func_800C2E04(void);
extern void func_800C330C(s32, s32);
extern void func_800C431C(s32, s32);
extern void _susubgame_entrypoint_11(s32);
extern u8 unkC[];
extern Actor *func_80106790(Unk80132ED0 *);
extern int D_808026D8_chtntmineshoot;
extern Vec3f D_80802720_chtntmineshoot;
extern u8 D_8080272C_chtntmineshoot[];
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 13; u32 local_0 : 1; u32 pad_2 : 18; } MineShootFlags35;
extern void _bsfirstp_entrypoint_18(void);
extern int D_80802774_chtntmineshoot;
typedef struct MineEntry { s32 f00; s16 f04; s16 f06; f32 f08; f32 f0C; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; f32 f28; f32 f2C; } MineEntry;
extern u8 D_808027BC_chtntmineshoot[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EFA98(u8 *, f32 *, f32);
extern s32 func_80103140(void *, u16, u16);
extern void func_800DF5D8();
extern void func_80101870(void *param_0, s32 param_1);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
extern s32 func_800F1EA4(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern s32 D_8080287C_chtntmineshoot;
extern s32 D_808028C4_chtntmineshoot;
extern int func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 D_808028E4_chtntmineshoot[];
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern u8 D_80802580_chtntmineshoot[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F13F0(f32, f32);
extern void func_80101CDC(Actor *, f32);
extern void func_800FE820(f32);
extern void func_800CE8D8(s32, f32, s32);
typedef struct { s32 local_0; s32 local_1; f32 local_2; s32 pad_0; s32 local_3; } Mass63TntState;
extern void _gcfrontend_entrypoint_9();
extern void func_800CE88C();
extern void func_800D2498();
extern void func_800D284C();
extern void func_800F49D4();
extern void func_800F7B9C();
extern void func_800F7C58();
extern void func_800F7F98();
extern void func_80101180();
extern void func_80101FDC();
extern f32 func_800CEA60(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u8 pad_0[12]; u8 local_0; u8 pad_1[3]; s32 local_1; } MineCountdown1570;
extern void func_800C35E8();
extern void func_800C301C(s32, s32);
extern void func_800C3058(s32, s32);
extern void func_800C3BDC(s32);
extern void func_800C3CE8(s32);
extern u8 func_800D9078();
void func_80800440_chtntmineshoot();
int func_80800BCC_chtntmineshoot();
void func_80800BF4_chtntmineshoot();
void func_80800C90_chtntmineshoot();
int func_80801A18_chtntmineshoot();
void func_80801F90_chtntmineshoot();
s32 func_808021C4_chtntmineshoot();
void func_808022A8_chtntmineshoot();
void func_80802320_chtntmineshoot();
void func_80800830_chtntmineshoot();
void func_80800E64_chtntmineshoot();
void func_80801318_chtntmineshoot();
void func_8080146C_chtntmineshoot();
void func_80801A54_chtntmineshoot();

void func_80800000_chtntmineshoot(s32 param_0)
{
  func_800C4AF0(param_0 + 4, &D_80802590_chtntmineshoot);
  func_800C4AF0(param_0 + 4, &D_8080259C_chtntmineshoot);
}

void func_8080003C_chtntmineshoot(s32 param_0)
{
    func_800BBCB8(param_0 + 4, 0, 1.0f, 4, &D_808025A8_chtntmineshoot);
}

void func_80800078_chtntmineshoot(f32 *param_0, f32 param_1)
{
    f32 local_0[3];

    if (param_0 != NULL) {
        func_800C4AF0(param_0, D_808025CC_chtntmineshoot);
        if (param_1 != 0.0f) func_800E1610(0, 50.0f, param_1, param_0);
    } else {
        func_800F5A00(func_800F54E4(), local_0);
        func_800C4AF0(local_0, D_808025CC_chtntmineshoot);
        if (param_1 != 0.0f) func_800E1610(0, 50.0f, param_1, local_0);
    }
    func_800187B4(0, 0.5f, 2.0f, 0.5f);
}

void func_80800150_chtntmineshoot(u8 *param_0) {
    _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, 1, &D_808025DC_chtntmineshoot);
    (*(s8 *)((s8 *)(param_0) + (0x5F))) = 0;
}

void func_80800188_chtntmineshoot(f32 *param_0)
{
    f32 local_0[3];
    u32 local_1;
    if (param_0) {
        func_800EE7F8(local_0, param_0);
    } else {
        local_1 = func_800F54E4();
        func_800F5A00(local_1, local_0);
        func_800EF1B8(local_0, func_800F5F24(local_1), 200.0f);
    }
    func_800BBCB8(local_0, 0, 1.0f, 1, D_808025F8_chtntmineshoot);
    func_800BBCB8(local_0, 0, 1.0f, 1, D_80802644_chtntmineshoot);
}

void func_80800228_chtntmineshoot(s32 param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    func_80800BCC_chtntmineshoot(param_0);
    func_80800440_chtntmineshoot(param_0, 0);
    _subaddierouteDll_entrypoint_3(param_0, local_0 + 0x18, param_0 + 4);
}

s32 func_80800AD0_chtntmineshoot();

s32 func_808004BC_chtntmineshoot();

void func_80800280_chtntmineshoot(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80800AD0_chtntmineshoot(param_0);
    switch (param_0->unk70_10) {
    case 1:
        if (func_8010D248()) {
            func_808004BC_chtntmineshoot(param_0, 2);
        }
        param_0->unk54 = func_8010CD28(param_0);
        func_80102BF8(param_0, 0.1f, 4.0f, 360.0f);
        break;
    case 2:
        local_1 &= 4;
        if (local_1) {
            *(f32 *)&param_0->actorData[3] = 0.0f;
        }
        if (local_0[0x14] == 4) {
            if (local_1) {
                param_0->unk54 = func_800136E4(param_0->rotation[1]
                    + func_800DC178(140.0f, 220.0f));
                func_808004BC_chtntmineshoot(param_0, 3);
            } else {
                func_808004BC_chtntmineshoot(param_0, 1);
            }
        }
        break;
    case 3:
        func_80102BF8(param_0, 0.75f, 4.0f, 360.0f);
        if (param_0->unk54 == param_0->rotation[1]) {
            func_808004BC_chtntmineshoot(param_0, 1);
        }
        break;
    case 4:
        func_80800000_chtntmineshoot(param_0);
        func_80108B04(param_0, 4);
        break;
    case 5:
        func_8080003C_chtntmineshoot(param_0);
        func_80108B04(param_0, 5);
        break;
    }
    func_8008FB10(param_0->position, func_80103EF4(param_0),
        0.0f, func_80103EAC(param_0));
}

void func_80800440_chtntmineshoot(param_0, param_1) s32 param_0; s32 param_1;
{
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    sp1C = temp_v0;
    if (*temp_v0 != 2)
    {
        if (param_1 != 0)
        {
            if ((param_1 == 1) || (param_1 == 2))
            {
                _subaddieDll_entrypoint_4(param_0, 1);
            }
        }
        else
        {
            _subaddieDll_entrypoint_4(param_0, 0);
        }
        *sp1C = (u8) param_1;
    }
}

s32 func_808004BC_chtntmineshoot(Actor *param_0, s32 param_1)
{
    switch (param_1) {
        case 2:
            func_80102424(param_0, param_1);
            func_80800830_chtntmineshoot(param_0, 1);
            break;
        case 4:
            func_80102424(param_0, 4);
            func_80800830_chtntmineshoot(param_0, 2);
            func_8010A570(param_0);
            func_80800440_chtntmineshoot(param_0, 2);
            break;
        case 5:
            func_80102424(param_0, 5);
            func_80800830_chtntmineshoot(param_0, 2);
            func_8010A570(param_0);
            func_80800440_chtntmineshoot(param_0, 2);
            func_800187B4(0, 0.5f, 2.0f, 0.75f);
        default:
            func_80102424(param_0, param_1);
            break;
    }
    return 1;
}

s32 func_808005AC_chtntmineshoot(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95: _subaddierouteDll_entrypoint_1(param_0); break;
    case 0xA: func_80800BF4_chtntmineshoot(param_0, 1); break;
    case 5: func_808004BC_chtntmineshoot(param_0, 5); break;
    case 0x40:
        func_80101180(0x2BC, 5, 0);
        func_808004BC_chtntmineshoot(param_0, 5);
        func_80800078_chtntmineshoot(param_0->position, 0.95f);
        break;
    case 0x3F:
        func_80101180(0x2BC, 0x4F, 0);
        func_808004BC_chtntmineshoot(param_0, 4);
        func_80800BF4_chtntmineshoot(param_0, 2);
        break;
    case 0x3D:
        if (param_0->unk7C_12) func_80801F90_chtntmineshoot(&param_0, param_2);
        func_800FFAB0(param_0);
    default: return 0;
    }
    return 1;
}

void func_808006D0_chtntmineshoot(Actor *param_0, s32 param_1)
{
    u8 *local_0 = func_80100094(param_0, 0);
    s32 local_1;
    f32 local_2[3];

    func_800DF744(3, local_0[1] != 2);
    if (local_0[4]) func_800DF5D8(*((u8 *)param_0 + 0x98), *((u8 *)param_0 + 0x99), *((u8 *)param_0 + 0x9A), *((u8 *)param_0 + 0x9B));
    func_80101870(param_0, param_1);
    if (param_0->unk7C_12) {
        func_80800C90_chtntmineshoot(param_0);
        if (local_0[1] == 1) {
            param_0->unk50 += 1.0f;
            if (param_0->unk50 >= 16.0f) param_0->unk50 = 0.0f;
            func_800DBEFC(func_80104130(), 4, param_0->actorData);
            local_1 = func_800D674C(0x9C6);
            func_800EFA4C(local_2, 0.5f, 0.5f, 0.5f);
            func_800E2588(1);
            func_800E24D8(1);
            func_800E2AA4(param_1, local_1, (s32)param_0->unk50, 0, param_0->actorData, local_2);
        }
    }
}

void func_80800830_chtntmineshoot(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 1:
        func_800F5A00(func_800F54E4(), local_4);
        local_3 = func_800F13F0(func_800EEAD4(local_4, param_0->position), 2000.0f) * 0.0005f;
        ((f32 *)param_0->actorData)[3] = param_0->scale * (1.0f - local_3) * 500.0f;
        local_1 = local_3 * 0.6699999571f + 0.33f;
        local_2 = (local_3 * 200.0f + 200.0f) * param_0->scale;
        func_800EFA4C((f32 *)&param_0->actorData[4], 0.0f, local_2, 0.0f);
        ((f32 *)param_0->actorData)[7] = (-local_2 - local_2) / local_1;
        local_1 += local_3 * 0.5f;
        func_80101CDC(param_0, local_1);
        func_800C4AF0(param_0->position, D_80802580_chtntmineshoot);
        func_80800440_chtntmineshoot(param_0, 1);
        break;
    case 2:
        if (((f32 *)param_0->actorData)[5] > 0.0f) {
            ((f32 *)param_0->actorData)[5] = 0.0f;
        }
        break;
    case 3:
        func_800EFD24(&param_0->actorData[4]);
        ((f32 *)param_0->actorData)[7] = 0.0f;
        break;
    case 4:
        func_800EFD24(&param_0->actorData[4]);
        ((f32 *)param_0->actorData)[7] = 0.0f;
        ((f32 *)param_0->actorData)[3] = 0.0f;
        func_80800440_chtntmineshoot(param_0, 0);
        break;
    }
    local_0[0x14] = param_1;
}

s32 func_80800A1C_chtntmineshoot(Actor *param_0)
{
    s32 local_1;
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    param_0->unk54 = func_800136E4(func_8010CD28(param_0) + 180.0f);
    _subaddierouteDll_entrypoint_7(param_0, local_0 + 0x18, param_0->rotation[1], param_0->unk54, 200.0f, 0x4000);
    func_80102BF8(param_0, 0.1f, 4.0f, 100.0f);
    local_1 = func_8010B990(param_0, 0x325);
    local_1 |= func_8010B990(param_0, 0x4004);
    return local_1;
}

s32 func_80800AD0_chtntmineshoot(u8 *param_0)
{
  s32 _pad;

  s32 ret_val;
  f32 *new_var;
  s32 temp_v0_2;
  s32 temp_v0_3;
  int temp_v1;
  u8 *temp_v0;
  temp_v0 = func_80100094(param_0, 0);
  ret_val = 0;
  new_var = &(*((f32 *) (((s8 *) param_0) + 0x24)));
  temp_v1 = *((u8 *) (((s8 *) temp_v0) + 0x14));
  switch (temp_v1)
  {
    case 4:
      break;

    case 1:
      temp_v0_2 = func_80800A1C_chtntmineshoot(param_0);
      ret_val = temp_v0_2;
      if (temp_v0_2 & 8)
    {
      func_80800830_chtntmineshoot(param_0, 3);
    }
      break;

    case 2:
      *((f32 *) (((s8 *) param_0) + 0x24)) = (*new_var) * 0.5f;
      temp_v0_3 = func_80800A1C_chtntmineshoot(param_0);
      ret_val = temp_v0_3;
      if (temp_v0_3 & 8)
    {
      func_80800830_chtntmineshoot(param_0, 4);
    }
      break;

    case 3:
      *((f32 *) (((s8 *) param_0) + 0x24)) = (*((f32 *) (((s8 *) param_0) + 0x24))) * 0.5f;
      ret_val = func_80800A1C_chtntmineshoot(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      func_80800830_chtntmineshoot(param_0, 4);
    }
      break;

  }

  return ret_val;
}

int func_80800BCC_chtntmineshoot(param_0) int param_0;
{
  u8 *local_0;
  int new_var;
  new_var = 0 & 0xFFFFFFFF;
  local_0 = func_80100094(param_0, 0);
  local_0[1] = 0;
  local_0[4] = 0;
}

void func_80800BF4_chtntmineshoot(param_0, param_1) Actor *param_0; s32 param_1;
{
    MineShootState *local_0;
    local_0 = func_80100094(param_0, 0);
    local_0->state = param_1;
    switch (param_1) {
    case 0:
        local_0->mode = 0;
        break;
    case 1:
        if (func_800DC090() & 1) local_0->mode = 1;
        else local_0->mode = 2;
        local_0->time = func_800DC0C0();
        break;
    case 2:
        local_0->mode = 3;
        break;
    }
}

void func_80800C90_chtntmineshoot(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    switch (local_0[4]) {
    case 2:
        *(f32 *)(local_0 + 8) -= local_1 * 4.0f;
        if (*(f32 *)(local_0 + 8) < 0.0f) {
            *(f32 *)(local_0 + 8) = 0.0f;
            local_0[4] = 1;
        }
        break;
    case 1:
        *(f32 *)(local_0 + 8) += local_1 * 4.0f;
        if (*(f32 *)(local_0 + 8) > 1.0f) {
            *(f32 *)(local_0 + 8) = 1.0f;
            local_0[4] = 2;
        }
        break;
    case 3:
        *(f32 *)(local_0 + 8) += local_1 * 4.0f;
        if (*(f32 *)(local_0 + 8) > 1.0f) {
            *(f32 *)(local_0 + 8) = 1.0f;
            local_0[4] = 0;
        }
        break;
    }
    local_2 = *(f32 *)(local_0 + 8) * 224.0f;
    *((u8 *)param_0 + 0x98) = 255 - (s32)(local_2 * 0.5f);
    *((u8 *)param_0 + 0x9A) = *((u8 *)param_0 + 0x99) = (s32)local_2 + 31;
    *((u8 *)param_0 + 0x9B) = 255;
}

int chtntmineshoot_entrypoint_0()
{
  return (int)&D_80802690_chtntmineshoot;
}

void func_80800E10_chtntmineshoot(s32 param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    local_0[0xC] = func_800C2E04();
    func_800C330C(local_0[0xC], 3);
    func_800C431C(local_0[0xC], 0);
    _susubgame_entrypoint_11(0);
}

void func_80800E64_chtntmineshoot(param_0, param_1) Actor *param_0; s32 param_1;
{
    Mass63TntState *local_0;
    void *local_1;
    s32 pad[2];
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    if (param_1 != param_0->unk70_10) {
        switch (param_1) {
        case 2:
            local_0->local_1 = 0;
            func_800D2498(0x102, local_0->local_0, 0);
            break;
        case 3:
            _gcfrontend_entrypoint_9(0x63);
            func_800CE8D8(0, (u32)param_0->unk74_7, param_0->unk74_7);
            func_800CE88C(0, 1);
            func_80101180(0x2BE, 10, 0);
            break;
        case 4:
            func_800FE820(1.0f);
            local_0->local_1 = 1;
            _susubgame_entrypoint_11(0);
            func_80801974_chtntmineshoot(param_0, 0xFA2);
            break;
        case 5:
            local_0->local_1 = 2;
            local_0->local_3 = 0;
            _susubgame_entrypoint_11(0);
            break;
        case 7:
            _susubgame_entrypoint_11(0);
            func_800D284C(0xCC);
            func_800D284C(0x102);
            break;
        case 8:
            local_1 = func_800F54E4();
            func_800F49D4(local_1, 0, 0);
            func_800F7B9C(local_1, 0x8F);
            func_800F7B9C(local_1, 0x62);
            func_800F7C58(local_1, 0x61, 0);
            func_80801974_chtntmineshoot(param_0, func_800D211C(0x95) ? 0xFB3 : 0xCEC);
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 9:
            local_0->local_1 = 0;
            local_0->local_2 = 0.0f;
            func_800D2498(0xCC, (s32)local_0->local_2, 0);
            func_800D2498(0x102, local_0->local_0, 0);
            func_80101180(0x2BE, 10, 0);
            break;
        case 11:
            switch (func_800D2054(1, 0x95, (s32)local_0->local_2)) {
            case -1: local_2 = 0xFB6; break;
            case 0: local_2 = 0xFB5; break;
            case 1: local_2 = 0xFB4; break;
            }
            func_80801974_chtntmineshoot(param_0, local_2);
            break;
        case 10:
            local_0->local_3 = 0;
            break;
        case 12:
            func_80801974_chtntmineshoot(param_0, 0xCEB);
            break;
        }
        func_80101FDC(param_0, param_1);
    }
}

void func_80801128_chtntmineshoot(Actor *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800CEA60(0);
    if (local_0 > 10.0f) {
        local_1 = func_800F10B4(local_0, param_0->unk74_7, 0.0f, 1.0f, 1.4f);
    } else {
        local_1 = func_800F10B4(local_0, 10.0f, 0.0f, 1.4f, 1.55f);
    }
    func_800FE820(local_1);
}

void func_808011D4_chtntmineshoot(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
        case 2:
            func_800D24E8(0x102, *(s32 *)local_0, 0);
            break;
        case 3:
            func_800D24E8(0x102, *(s32 *)local_0, 0);
            func_80801128_chtntmineshoot(param_0);
            if (func_800CEAD0(0)) func_80800E64_chtntmineshoot(param_0, 5);
            break;
        case 5:
            func_80801318_chtntmineshoot(param_0);
            break;
        case 9:
            *(f32 *)(local_0 + 8) = func_800F13F0(*(f32 *)(local_0 + 8) + func_800D8FF8(), 999.0f);
            func_800D2498(0x102, *(s32 *)local_0, 0);
            func_800D2498(0xCC, (s32)*(f32 *)(local_0 + 8), 0);
            break;
        case 11:
            func_800D2498(0xCC, (s32)*(f32 *)(local_0 + 8), 0);
            break;
        case 10:
            func_8080146C_chtntmineshoot(param_0);
            break;
    }
}

void func_80801318_chtntmineshoot(param_0) Actor *param_0;
{
    MineCountdown1570 *local_1;
    f32 local_0[3];

    local_1 = func_80100094(param_0, 0);
    func_800F5A00(func_800F54E4(), local_0);
    switch (local_1->local_1) {
        case 0:
            func_800C35E8(local_1->local_0, param_0->position);
            func_800C301C(local_1->local_0, 0x414);
            func_800C3058(local_1->local_0, 0x7FFF);
            func_800C3BDC(local_1->local_0);
            param_0->unk58 = 1.0f;
            local_1->local_1 = 1;
            break;
        case 1:
            if (func_800D9078(&param_0->unk58)) {
                func_800C3CE8(local_1->local_0);
                func_80101180(0x2BE, 5, 0);
                func_80801974_chtntmineshoot(param_0, 0xFA3);
                local_1->local_1 = 2;
            }
            break;
        case 2:
            func_80800078_chtntmineshoot(NULL, 0.95f);
            func_80800188_chtntmineshoot(NULL);
            param_0->unk58 = func_800DC178(0.67f, 1.0f);
            local_1->local_1 = 3;
            break;
        case 3:
            if (func_800D9078(&param_0->unk58)) local_1->local_1 = 2;
            break;
    }
}

void func_8080146C_chtntmineshoot(param_0) Actor *param_0;
{
    u8 *local_1;
    f32 local_0[3];
    local_1 = func_80100094(param_0, 0);
    func_800F5A00(func_800F54E4(), local_0);
    switch (*(u32 *)(local_1 + 0x10)) {
        case 0:
            func_800C35E8(local_1[0xC], param_0->position);
            func_800C301C(local_1[0xC], 0x414);
            func_800C3058(local_1[0xC], 0x7FFF);
            func_800C3BDC(local_1[0xC]);
            param_0->unk58 = 1.0f;
            *(u32 *)(local_1 + 0x10) = 1;
            *(f32 *)(local_1 + 0x14) = 5.0f;
            break;
        case 1:
            if (func_800D9078(&param_0->unk58)) {
                func_800C3CE8(local_1[0xC]);
                func_80101180(0x2BE, 5, 0);
                *(u32 *)(local_1 + 0x10) = 2;
            }
            break;
        case 2:
            func_80800078_chtntmineshoot(0, 0.95f);
            func_80800188_chtntmineshoot(0);
            param_0->unk58 = func_800DC178(0.67f, 1.0f);
            *(u32 *)(local_1 + 0x10) = 3;
            break;
        case 3:
            if (func_800D9078((f32 *)(local_1 + 0x14))) {
                func_80800078_chtntmineshoot(0, 0.95f);
                func_80800150_chtntmineshoot(param_0);
                *(u32 *)(local_1 + 0x10) = 4;
                param_0->unk58 = 1.0f;
            } else if (func_800D9078(&param_0->unk58)) { *(u32 *)(local_1 + 0x10) = 2; }
            break;
        case 4:
            if (func_800D9078(&param_0->unk58)) { func_80800E64_chtntmineshoot(param_0, 0xC); }
            break;
    }
}

int func_80801604_chtntmineshoot(s32 param_0)
{
  Actor *local_0;
  local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_11(0);
  func_800D284C(0x102);
  if ((*(u8 *)((char *)(local_0) + 0xC)) != 0)
  {
    func_800C2FDC((*(u8 *)((char *)(local_0) + 0xC)));
    (*(u8 *)((char *)(local_0) + 0xC)) = 0;
  }
}

s32 func_80801658_chtntmineshoot(Actor **param_0)
{
    Actor *local_4;
    Unk80132ED0 *local_0;
    Prop *local_1[20];
    s32 local_2;
    s32 local_3;

    local_4 = *param_0;
    local_0 = local_4->unk0;
    if (!func_800D0A9C(0xF, 1) || func_800D395C()) {
        local_2 = _gccubesearch_entrypoint_9(0x2BA, local_1, 20);
    } else {
        local_2 = 0;
    }
    for (local_3 = 0; local_3 < local_2; local_3++) {
        func_801085CC(0x2BE, local_1[local_3], local_1[local_3]->FlagOrRotation);
    }
    *param_0 = func_80106790(local_0);
    return local_2;
}

s32 func_80801714_chtntmineshoot(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_4;
    s32 local_3;
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x49:
        if (func_800D395C()) {
            local_1 = func_80801658_chtntmineshoot(&param_0);
            *(s32 *)func_80100094(param_0, 0) = local_1;
            func_80800E64_chtntmineshoot(param_0, 8);
        } else if (!func_800D0A9C(0xF, 1)) {
            local_2 = func_80801658_chtntmineshoot(&param_0);
            *(s32 *)func_80100094(param_0, 0) = local_2;
            func_80800E64_chtntmineshoot(param_0, 2);
        } else {
            *local_0 = 0;
        }
        break;
    case 5:
        local_4 = func_800D395C() ? 0xA : 5;
        func_80800E64_chtntmineshoot(param_0, local_4);
        local_5 = func_800F54E4();
        func_800F7F98(local_5, 1);
        break;
    case 0x4F:
        if (--*local_0) {
            if (!func_800D395C() && param_0->unk70_10 == 2) func_80800E64_chtntmineshoot(param_0, 3);
            if (param_0->unk70_10 == 3) func_800FC660(0xE);
        } else {
            local_3 = func_800D395C() ? 0xB : 4;
            func_800FC660(0x10);
            func_80800E64_chtntmineshoot(param_0, local_3);
        }
        break;
    case 0x30:
        return func_80801A18_chtntmineshoot(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x2E:
        func_80801A54_chtntmineshoot(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x9F:
        func_80800E64_chtntmineshoot(param_0, 7);
        break;
    case 0x96:
        if (!func_800D395C()) return 0;
        func_80800E64_chtntmineshoot(param_0, 0xC);
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80801974_chtntmineshoot(Actor *param_0, s32 param_1)
{
    s32 local_0;

    local_0 = 7;
    switch (param_1) {
    case 0xFA2:
    case 0xFA3:
    default:
        func_800F7F98(func_800F54E4(), 1);
        break;
    case 0xCEC:
    case 0xFB3:
        local_0 = 0x23;
        break;
    case 0xCEB:
        local_0 = 0x144;
        break;
    case 0xFA4:
        break;
    }
    _subaddiedialog_entrypoint_11(param_0->unk0, param_1, local_0, 0, 0x3F);
    return 1;
}

int func_80801A18_chtntmineshoot(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0xFB3)
  {
    return func_800D211C(0x95);
  }
  return 0;
}

void func_80801A54_chtntmineshoot(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
        case 0xFA3:
            func_80800078_chtntmineshoot(0, 0.95f);
            func_80800150_chtntmineshoot(param_0);
            func_800A7AD4(1, 5);
            _gcgoto_entrypoint_1(0x163, 3);
            break;
        case 0xFA2:
            _glcutDll_entrypoint_6(0x163, 0x18);
            break;
        case 0xFB3:
            func_80801974_chtntmineshoot(param_0, 0xCEC);
            break;
        case 0xCEC:
            func_800F7F98(func_800F54E4(), 0);
            func_80800E64_chtntmineshoot(param_0, 9);
            break;
        case 0xFB4:
        case 0xFB5:
        case 0xFB6:
            func_80800E64_chtntmineshoot(param_0, 0xC);
            break;
        case 0xCEB:
            func_800F7F98(func_800F54E4(), 0);
            if (param_2 > 0) _gcfrontend_entrypoint_11();
            else _gcfrontend_entrypoint_10();
            break;
    }
}

int chtntmineshoot_entrypoint_1()
{
    return &D_808026D8_chtntmineshoot;
}

void func_80801BA0_chtntmineshoot(void)
{
    Vec3f local_0 = D_80802720_chtntmineshoot;
    func_800BBCB8(local_0.f, 0, 1.0f, 2, D_8080272C_chtntmineshoot);
    func_800E1610(0, 20.0f, 0.9f, local_0.f);
}

void func_80801C10_chtntmineshoot(s32 arg0) 
{
}
void func_80801C18_chtntmineshoot(s32 arg0) 
{
}
void func_80801C20_chtntmineshoot(Actor *param_0)
{
    if (!((MineShootFlags35 *)param_0)->local_0) {
        ((MineShootFlags35 *)param_0)->local_0 = 1;
        if (param_0->unk70_10 != 3) {
            switch (func_800EA090()) {
            case 3:
                func_800C964C(6);
                func_80801BA0_chtntmineshoot();
                func_80800078_chtntmineshoot(0, 0.25f);
                func_80101FDC(param_0, 4);
                _capod_entrypoint_13(param_0->unk0, 0, 7, 0x2000);
                break;
            case 2:
                func_80101FDC(param_0, 4);
                _capod_entrypoint_13(param_0->unk0, 0, 2, 0x2000);
                break;
            case 1:
                if (func_800C6E38(0x15) && func_800F5410(0) == 1 && !func_800DA9E4(0x6B9, 1)) {
                    func_80101FDC(param_0, 2);
                    _capod_entrypoint_13(param_0->unk0, 0, 5, 0x2020);
                    func_800F49D4(func_800F54E4(), _bsfirstp_entrypoint_18, 0);
                }
                break;
            }
        }
    }
}

void func_80801D6C_chtntmineshoot(Actor *param_0)
{
    func_80801C20_chtntmineshoot(param_0);
    switch (param_0->unk70_10) {
    case 2:
        break;
    case 3:
        if (func_800D9078(&param_0->unk58)) {
            func_800D1000(0xF, 1, 0, 1, 0);
            func_80101FDC(param_0, 1);
        }
        break;
    case 4:
        break;
    }
}

s32 func_80801DEC_chtntmineshoot(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0xB:
            if (param_0->unk70_10 == 4) {
                func_800F7F98(func_800F54E4(), 0);
                func_800F7B9C(func_800F54E4(), 0x73);
                func_80101FDC(param_0, 1);
                if (!func_800D0A9C(0xF, 1)) {
                    if (func_800EA090() == 2) { func_80801974_chtntmineshoot(param_0, 0xFAB); }
                    else { func_80801974_chtntmineshoot(param_0, 0xFA4); }
                }
            }
            return 3;
        case 0x49:
            if (_glcutDll_entrypoint_19(0x18)) {
                _capod_entrypoint_13(param_0->unk0, 0, 0, 0x900);
                func_80101FDC(param_0, 3);
                param_0->unk58 = 0.15f;
                return 1;
            }
            break;
        case 0x2E: func_800F7F98(func_800F54E4(), 0); return 1;
        case 0x77:
            if (param_0->unk70_10 == 2) {
                func_800F7B9C(param_2, 0x73);
                func_80101FDC(param_0, 1);
                _capod_entrypoint_14();
                func_800F7B9C(func_800F54E4(), 0x99);
                return 1;
            }
            break;
    }
    return 0;
}

int *chtntmineshoot_entrypoint_2()
{
    return &D_80802774_chtntmineshoot;
}

void func_80801F90_chtntmineshoot(param_0, param_1) u8 *param_0; s32 param_1;
{
    s32 i;
    s32 v1;
    u8 *obj;
    f32 vec[3];
    u8 *spawned;
    MineEntry *base;
    MineEntry *e;
    f32 f20;
    s32 *q;

    base = (MineEntry *) D_808027BC_chtntmineshoot;
    if (param_1 == 4) {
        v1 = 0;
    } else {
        v1 = 1;
    }
    base = (MineEntry *) ((u8*)base + v1 * 0x60);
    e = base;
    f20 = *((f32 *) (*((u8 **) param_0) + 0x48));

    for (i = 0; i < 5; ) {
        {
            spawned = func_801084B0(0x2C3, param_0);
            q = (s32 *) (*((u8 **) param_0) + 0x98);
            *((s32 *) (spawned + 0x98)) = *q;
            func_80101FDC(spawned, e->f00);
            func_80103140(spawned, e->f06, *((u16 *) (*((u8 **) spawned) + 0x16)));
            *((f32 *) (spawned + 0x34)) = e->f08;
            *((f32 *) (spawned + 0x54)) = e->f0C;
            *((f32 *) (spawned + 0x48)) = func_800DC178(-30.0f, 30.0f) + f20;
            f20 = f20 + 72.0f;
            func_800EEB9C(vec, *((f32 *) (spawned + 0x48)), e->f10);
            vec[1] = e->f14;
            func_800EF04C(spawned + 4, vec);
            vec[1] = 0.0f;
            func_800EFA98(spawned + 0x28, vec, func_800DC178(e->f18, e->f1C));
            *((f32 *) (spawned + 0x2C)) = func_800DC178(e->f20, e->f24);
            *((f32 *) (spawned + 0x50)) = func_800DC178(e->f28, e->f2C);
            e = base + 1;
            i++;
        }
    }
}

void func_80802140_chtntmineshoot(s32 arg0) 
{
}
void func_80802148_chtntmineshoot(s32 param_0, s32 param_1)
{
    u8 *local_0;
    local_0 = (u8 *)param_0 + 0x98;
    func_800DF5D8(*local_0, *(local_0 + 1), *(local_0 + 2), *(local_0 + 3));
    func_80101870((void *)param_0, param_1);
    func_80802320_chtntmineshoot((void *)param_0);
}

int func_80802198_chtntmineshoot(s32 param_0)
{
  s32 local_0;
  local_0 = func_808021C4_chtntmineshoot(param_0);
  func_808022A8_chtntmineshoot(param_0, local_0 | 0);
}

s32 func_808021C4_chtntmineshoot(param_0) Actor *param_0;
{
    s32 local_0;
    f32 local_1[3];
    f32 local_4;
    f32 local_2[3];
    f32 local_3[3];

    local_4 = func_800D8FF8();
    *(f32 *)((u8 *)param_0 + 0x2C) += *(f32 *)((u8 *)param_0 + 0x34) * local_4;
    if (*(f32 *)((u8 *)param_0 + 0x2C) < param_0->unk54) {
        *(f32 *)((u8 *)param_0 + 0x2C) = param_0->unk54;
    }
    func_800EFA20(local_2, (f32 *)((u8 *)param_0 + 0x28), local_4);
    func_800EE780(local_1, param_0->position, local_2);
    local_0 = func_800FAB50(param_0->position, local_1, local_3, 0x024200A1, 15.0f);
    if (local_0 != 0) {
        func_800F059C((f32 *)((u8 *)param_0 + 0x28), (f32 *)((u8 *)param_0 + 0x28), local_3);
    }
    func_800EE7F8(param_0->position, local_1);
    return local_0 != 0 ? 1 : 0;
}

void func_808022A8_chtntmineshoot(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0;
    if (param_1) {
        if (func_800F1EA4((f32 *)&param_0->actorData[4], &local_0)) param_0->rotation[1] = local_0;
        func_800EF334((f32 *)&param_0->actorData[4], 0.8f);
        _subaddiefade_entrypoint_3(param_0);
    }
    param_0->rotation[0] += param_0->unk50 * func_800D8FF8();
}

void func_80802320_chtntmineshoot(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;

    switch (param_0->unk70_10) {
    case 5:
        if (!(func_800DC090() & 3) && _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_0)) {
            local_1 = func_800BABB8(0, local_0, NULL, 1.0f, &D_8080287C_chtntmineshoot);
            func_800BA3FC(local_1, func_8001211C() & 1 ? 0x9E3 : 0x9E2);
            func_800BA22C(local_1, 1);
        }
        break;
    case 3:
        if ((func_800DC090() & 0xF) < 3U && _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_0)) {
            local_2 = func_800BABB8(0, local_0, NULL, 1.0f, &D_808028C4_chtntmineshoot);
            func_800BA4B0(local_2, *((u8 *)param_0 + 0x9B));
            func_800BA22C(local_2, 1);
        }
        break;
    }
}

int chtntmineshoot_entrypoint_3()
{
    return D_808028E4_chtntmineshoot;
}
