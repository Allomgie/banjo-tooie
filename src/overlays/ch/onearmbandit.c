#include "common.h"
extern s32 func_800DC298(f32);

extern int D_808012BC_chonearmbandit;
extern int D_80801304_chonearmbandit;
typedef union { s32 word; Actor **actors; } BanditMessage30;
extern u8 D_80801280_chonearmbandit[];
typedef struct { s16 a, b; } S16Pair;
typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest72:10; u8 pad74[4]; u32 pad78:29; u32 flag:1; u32 rest78:2; } BanditState;
typedef struct { u8 pad0[0x64]; u32 pad64 : 2; u32 unk64_29 : 1; u32 pad64_0 : 29; } BanditActor;
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800F54E4(void);
extern void func_8010D09C(s32, f32 *, f32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_800136E4(f32);
extern void *func_80100094(Actor *, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern f32 D_808011FC_chonearmbandit[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _subaddiejoy_entrypoint_10(Actor *, f32, f32);
extern s32 D_80801364_chonearmbandit[];
typedef struct { u8 local_0[0x64]; u32 local_1:2; u32 local_2:1; u32 local_3:29; } BanditFlags49;
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F20BC(f32, f32, f32);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern u8 func_801015D0[];
extern void func_800EFA4C(f32 *, void *, void *, f32);
extern void func_800BBCB8();
extern void func_800C4AF0(void *, void *);
extern void func_800FFAB0(void *);
extern void func_8010A570(void *);
extern void *D_808013A4_chonearmbandit;
extern void *D_808013DC_chonearmbandit;
extern int D_808013E8_chonearmbandit;
typedef struct { u8 pad0[0x64]; u32 pad64_30:2; u32 unk64_29:1; u32 pad64_0:29; u8 pad68[0x10]; u32 pad78_3:29; u32 unk78_2:1; u32 pad78_0:2; } BanditBits;
extern f32 D_808011F0_chonearmbandit[];
extern f32 D_8080134C_chonearmbandit[];
extern s32 func_8010C9B0(f32 *, s32);
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_8010D278(void);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80108B04(Actor *, s32);
extern s32 func_80101DDC(Actor *);
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; } OneArmBanditFlags;
extern u8 D_80801354_chonearmbandit[];
typedef union { f32 local_0[3]; s32 local_1[3]; } DeferredPosition1864;
typedef union { f32 local_0; s32 local_1; } DeferredAngle1864;
extern s32 D_8080139C_chonearmbandit[];
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chbaddiesetup_entrypoint_10();
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
int func_80800040_chonearmbandit();
void func_808006F8_chonearmbandit();
int func_80800AB8_chonearmbandit();
void func_808010AC_chonearmbandit();
void func_80801114_chonearmbandit();
s32 func_80801154_chonearmbandit();
void func_80800680_chonearmbandit();
int func_80800D00_chonearmbandit();

int chonearmbandit_entrypoint_0()
{
    return (int)&D_808012BC_chonearmbandit;
}

int chonearmbandit_entrypoint_1()
{
    return (int)&D_80801304_chonearmbandit;
}

void func_80800018_chonearmbandit(u8 *param_0) {
    *(f32 *)(param_0 + 0x24) = 400.0f;
    func_80800040_chonearmbandit();
}

int func_80800040_chonearmbandit(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_80100094(param_0, 1);
  _subaddierouteDll_entrypoint_3(param_0, local_0 | 0, param_0 + 4);
  _subaddierouteDll_entrypoint_1(param_0);
}





































void func_80800A14_chonearmbandit(Actor *param_0, f32 param_1);

s32 func_808008E0_chonearmbandit(Actor *param_0, f32 param_1);

void func_80800740_chonearmbandit(Actor *param_0, f32 param_1);

void func_8080007C_chonearmbandit(Actor *param_0)
{
    f32 *local_0;

    if (((BanditBits *)param_0)->unk78_2) {
        return;
    }
    switch (param_0->unk70_10) {
    case 1:
        if (((BanditBits *)param_0)->unk64_29) {
            func_80800680_chonearmbandit(param_0, 2);
            return;
        }
        if (func_8010C9B0(param_0->position, 1500)) {
            func_80800680_chonearmbandit(param_0, 4);
        }
        break;
    case 2:
        if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_808011F0_chonearmbandit, 0.75f)) {
            _subaddiejoy_entrypoint_10(param_0, 0.8f, 0.2f);
        }
        func_808008E0_chonearmbandit(param_0, 0.0f);
        if (_subaddiejoy_entrypoint_6(param_0, 1)) {
            func_80800680_chonearmbandit(param_0, 3);
        } else if (_subaddiejoy_entrypoint_6(param_0, 0)) {
            func_80800680_chonearmbandit(param_0, 5);
        }
        if (!((BanditBits *)param_0)->unk64_29) {
            func_80800680_chonearmbandit(param_0, 3);
        }
        break;
    case 3:
        local_0 = param_0->position;
        if (_subaddieaudioquick_entrypoint_3(param_0, local_0, D_808011F0_chonearmbandit, 0.75f)) {
            _subaddiejoy_entrypoint_10(param_0, 0.8f, 0.2f);
        }
        func_80800A14_chonearmbandit(param_0, 0.7f);
        func_808008E0_chonearmbandit(param_0, 0.0f);
        if (func_80101E14(param_0, 0.999f)) {
            if (((BanditBits *)param_0)->unk64_29) {
                if (!_subaddiejoy_entrypoint_6(param_0, 1)) {
                    func_80800680_chonearmbandit(param_0, 2);
                }
            } else if (!func_8010C9B0(local_0, 800)) {
                func_80800680_chonearmbandit(param_0, 4);
            }
        }
        break;
    case 4:
        local_0 = param_0->position;
        _subaddieaudioquick_entrypoint_3(param_0, local_0, D_808011F0_chonearmbandit, 0.75f);
        if (func_80101E14(param_0, 0.999f)) {
            if (((BanditBits *)param_0)->unk64_29) {
                func_80800680_chonearmbandit(param_0, 2);
                return;
            }
            if (!func_8010C9B0(local_0, 1500)) {
                func_80800680_chonearmbandit(param_0, 1);
                return;
            }
            if (func_8010C9B0(local_0, 800)) {
                func_80800680_chonearmbandit(param_0, (func_8010D278() == 0x10) ? 6 : 2);
            }
            return;
        }
        func_80800740_chonearmbandit(param_0, 0.0f);
        if (func_8010C9B0(local_0, 1500)) {
            if (func_80102CF4(param_0, 8.0f)) {
                func_80800680_chonearmbandit(param_0, 5);
            }
        } else {
            func_80800680_chonearmbandit(param_0, 1);
        }
        break;
    case 5:
        local_0 = param_0->position;
        _subaddieaudioquick_entrypoint_3(param_0, local_0, D_8080134C_chonearmbandit, 0.1f);
        if (func_80101E14(param_0, 0.25f)) {
            func_80108B04(param_0, 0);
        }
        if (func_80101DDC(param_0)) {
            param_0->unk58 -= func_800D8FF8();
            if (param_0->unk58 < 0.0f) {
                if (((BanditBits *)param_0)->unk64_29) {
                    func_80800680_chonearmbandit(param_0, 2);
                    return;
                }
                func_80800680_chonearmbandit(param_0, func_8010C9B0(local_0, 800) ? ((func_8010D278() == 0x10) ? 6 : 2) : 4);
            }
        }
        break;
    case 7:
        if (func_80101DDC(param_0)) {
            func_80800680_chonearmbandit(param_0, 1);
        }
        break;
    case 6:
        local_0 = param_0->position;
        _subaddieaudioquick_entrypoint_3(param_0, local_0, D_808011F0_chonearmbandit, 0.75f);
        if (func_80101E14(param_0, 0.999f)) {
            if (((BanditBits *)param_0)->unk64_29) {
                func_80800680_chonearmbandit(param_0, 2);
            } else if (!func_8010C9B0(local_0, 800)) {
                func_80800680_chonearmbandit(param_0, 4);
            }
        }
        func_808008E0_chonearmbandit(param_0, 180.0f);
        break;
    }
}

s32 func_80800520_chonearmbandit(Actor *param_0, s32 param_1, BanditMessage30 param_2)
{
    switch (param_1) {
    case 0x3F:
        func_808006F8_chonearmbandit(param_0, param_2.word);
        break;
    case 0x40:
        _chexploder_entrypoint_4(param_0, (*param_2.actors)->position, 4);
        break;
    case 0x3D:
        if (!func_801072A8(param_0)) func_80800AB8_chonearmbandit(param_0);
        break;
    case 0x90:
        func_80800D00_chonearmbandit(param_0);
        break;
    case 2:
        if ((s32)param_0->unk70_10 > 0 && !_subaddieDll_entrypoint_3(param_0)) func_80107070(param_0, 1);
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(param_0);
        break;
    case 0x38:
        func_80101074(D_80801280_chonearmbandit);
        return 5;
    default:
        return 0;
    }
    return 1;
}

s32 func_8080063C_chonearmbandit(s32 param_0, s32 param_1) {
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(param_0, param_1);
}

void func_80800680_chonearmbandit(param_0, param_1) Actor *param_0; s32 param_1;
{
    func_80102424(param_0, param_1);
    if (param_1 == 5) {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801354_chonearmbandit);
        if (((OneArmBanditFlags *)param_0)->local_0) {
            param_0->unk58 = 0.36f;
        } else {
            param_0->unk58 = 1.2f;
        }
    }
}

void func_808006F8_chonearmbandit(BanditState *param_0, S16Pair param_1) {
    if (!param_0->flag && param_0->f72 != 7) {
        func_80800680_chonearmbandit(param_0, 7);
    }
}

void func_80800740_chonearmbandit(Actor *param_0, f32 param_1)
{
    f32 local_0[3];
    f32 local_3;
    f32 local_1;
    f32 local_2;

    if (((BanditActor *)param_0)->unk64_29) {
        _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
        func_80102BF8(param_0, 0.2f, 6.0f, 220.0f);
        return;
    }
    local_2 = func_800D8FF8();
    func_8010D09C(func_800F54E4(), local_0, 0.8f);
    switch (param_0->unk70_10) {
    case 2:
    case 3:
    case 6:
        if (_subaddierouteDll_entrypoint_4(param_0)) {
            param_0->unk54 = func_800136E4(func_80102D78(param_0, local_0) + param_1);
            _subaddierouteDll_entrypoint_7(param_0, func_80100094(param_0, 1), param_0->rotation[1], param_0->unk54, 200.0f, 0x4000);
        }
        break;
    default:
        param_0->unk54 = func_800136E4(func_80102D78(param_0, local_0) + param_1);
        break;
    }
    local_1 = func_800F1DCC(func_800F1FF0(param_0->rotation[1], param_0->unk54, 0.15f, local_2 * 4.0f, local_2 * 120.0f), param_0->rotation[1]);
    local_1 *= func_800F3780(func_80101F24(param_0), ((u8 *) D_808011FC_chonearmbandit), 3);
    param_0->rotation[1] = func_800136E4(param_0->rotation[1] + local_1);
}

s32 func_808008E0_chonearmbandit(Actor *param_0, f32 param_1)
{
    f32 local_0;
    f32 local_3;
    f32 local_1;
    s32 local_2;

    local_0 = *(f32 *)&param_0->actorData[3];
    if (((OneArmBanditFlags *)param_0)->local_0) {
        local_1 = _subaddiejoy_entrypoint_9(param_0, 0, 0);
        local_3 = func_80101F24(param_0);
        *(f32 *)&param_0->actorData[3] = func_800F3780(local_3, D_808011FC_chonearmbandit, 3) *
            (param_0->scale * (local_1 * 400.0f));
    } else {
        local_3 = func_80101F24(param_0);
        *(f32 *)&param_0->actorData[3] = func_800F3780(local_3, D_808011FC_chonearmbandit, 3) *
            (param_0->scale * 400.0f);
    }
    func_80800740_chonearmbandit(param_0, param_1);
    if (((OneArmBanditFlags *)param_0)->local_0) {
        func_8010B990(param_0, 0x205025);
    } else {
        func_8010B990(param_0, 0x5425);
    }
    local_2 = 0;
    if (*(f32 *)&param_0->actorData[3] > 0.0f) {
        local_2 = 1;
    }
    *(f32 *)&param_0->actorData[3] = local_0;
    return local_2;
}

void func_80800A14_chonearmbandit(Actor *param_0, f32 param_1)
{
    f32 local_0[3];
    if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, ((u8 *) D_808011F0_chonearmbandit), param_1)) {
        if (_subaddieskeleton_entrypoint_2(param_0->unk0, 5, local_0)) {
            if (param_0->position[1] < local_0[1]) local_0[1] = param_0->position[1];
            func_800BBCB8(local_0, local_0, 0x3F333333, 6, D_80801364_chonearmbandit);
        }
        _subaddiejoy_entrypoint_10(param_0, 1.4f, 0.3f);
    }
}

int func_80800AB8_chonearmbandit(param_0) Actor *param_0;
{
  f32 local_1[3];
  f32 local_0[3];
  Actor *local_2;
  f32 local_3;
  if (!_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_0))
  {
    func_800EE7F8(local_0, param_0->position);
    if (local_0)
    {
    }
    local_0[1] += param_0->scale * 60.0f;
  }
  local_2 = func_80108528(0x35B, local_0, (s32) param_0->rotation[1], &param_0);
  func_80102FDC(local_2, param_0->scale);
  func_8010D09C(func_800F54E4(), local_1, 0.8f);
  local_1[1] += 60.0f;
  if (((BanditFlags49 *) param_0)->local_2)
  {
    local_3 = func_800136E4(func_800F1DF4(local_2->position, local_1));
    if (func_800F20BC(local_3, param_0->rotation[1], 8.0f))
    {
      local_2->rotation[1] = local_3;
    }
    else
    {
      local_2->rotation[1] = param_0->rotation[1];
    }
  }
  else
  {
    s32 pad0;
    local_2->rotation[1] = func_800136E4(func_800F1DF4(local_2->position, local_1));
    local_3 = func_800F1DCC(local_2->rotation[1], param_0->rotation[1]);
    if (local_3 < (-60.0f))
    {
      local_2->rotation[1] = param_0->rotation[1] - 60.0f;
    }
    else
      if (local_3 > 60.0f)
    {
      local_2->rotation[1] = param_0->rotation[1] + 60.0f;
    }
  }
  local_2->rotation[0] = func_800136E4(func_800F1828(local_2->position, local_1));
  if (local_2->rotation[0] > 180.0f)
  {
    if (local_2->rotation[0] < 350.0f)
    {
      local_2->rotation[0] = 350.0f;
    }
  }
  else
    if (local_2->rotation[0] > 10.0f)
  {
    local_2->rotation[0] = 10.0f;
  }
  func_80108944(local_2, param_0);
}

s32 func_80800E78_chonearmbandit();

int func_80800D00_chonearmbandit(Actor *param_0)
{
    f32 local_0[3];
    Actor *local_1;
    s32 local_6;
    DeferredPosition1864 local_2;
    DeferredAngle1864 local_3;
    s32 local_4;
    local_1 = func_80106790(func_80101080(param_0));
    _chexploder_entrypoint_9(local_1, 3, 0);
    _chexploder_entrypoint_9(local_1, 4, 1);
    _chexploder_entrypoint_6(local_1, 1000.0f, 1200.0f);
    _subaddiefade_entrypoint_9(param_0, local_0);
    _subaddiefade_entrypoint_11(local_1, local_0);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_8080139C_chonearmbandit);
    _subaddiejoy_entrypoint_10(param_0, 1.4f, 0.3f);
    *((u8 *)param_0 + 0x64) &= ~1;
    local_6 = func_80800E78_chonearmbandit(param_0);
    if (local_6) func_800D1000(local_6, 8, param_0->position, 1, 0);
    else if (func_8010A430(param_0)) {
        local_3.local_0 = func_800DC178(0.0f, 359.0f);
        if (func_800DC298(0.5f)) local_4 = 0x18;
        else local_4 = 0x19;
        func_80103DFC(param_0, local_2.local_0);
        _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, local_4, local_2.local_1[0], local_2.local_1[1], local_2.local_1[2], local_3.local_1);
    }
    if (!func_80107070(param_0, 3)) func_800FFAB0(param_0);
}

s32 func_80800E78_chonearmbandit(s32 param_0)
{
    s32 local_0;

    local_0 = ((u32)(*(u16 *)((char *)param_0 + 0x76)) >> 7) - 0x31;
    if (func_800D0A9C(local_0, 8) != 0)
    {
        return 0;
    }
    return local_0;
}

void func_80800EBC_chonearmbandit(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    if (func_800D90A4(&param_0->unk58) && !param_0->unk7C_12 && !param_0->unk64_20) {
        func_8010A570(param_0);
        _subaddiefade_entrypoint_3(param_0);
        param_0->unk64_20 = 1;
    }
    param_0->unk54 += local_0 * *(f32 *)&param_0->actorData[4];
    if (func_8001210C(1)) func_80801114_chonearmbandit(param_0);
    if (param_0->unk70_10 == 1) func_80801154_chonearmbandit(param_0);
}

void func_80800F80_chonearmbandit(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800DC298(0.5f) ? -1.0f : 1.0f;
    ((f32 *)param_0->actorData)[4] = func_800DC178(600.0f, 800.0f) * local_0;
    param_0->unk58 = 4.0f;
    ((f32 *)param_0->actorData)[3] = 1000.0f;
}

int func_80801008_chonearmbandit(unsigned long param_0, s32 param_1, s32 param_2)
{
  s32 *new_var2;
  s32 *new_var;
  if (param_1 == 0x40)
  {
    new_var = &param_2;
    new_var2 = new_var;
    func_808010AC_chonearmbandit(param_0, (*new_var2) | 0);
    return 1;
  }
  return 0;
  if (!new_var2)
  {
  }
}

void func_80801040_chonearmbandit(ALSeqPlayer *param_0, s32 param_1)
{
    f32 local_0[3];
    void *new_var;
    func_800EFA4C(local_0, *(ALSeqMarker ***)((char *)param_0 + 0x50), *(ALSeqMarker ***)((char *)param_0 + 0x54), 0);
    func_800DF47C(&func_801015D0, param_0);
    new_var = func_8010347C(*(ALSeqMarker ***)param_0);
    func_800DE448(&((ALSeqMarker ***)param_0)[1], local_0, *(ALVoiceState ***)((char *)param_0 + 0x38), 0, new_var);
}

void func_808010AC_chonearmbandit(param_0, param_1) void *param_0; void *param_1;
{
  func_800BBCB8(((char *) param_0) + 4, ((char *) param_0) + 4, *((void **) (((char *) param_0) + 0x38)), 6, &D_808013A4_chonearmbandit);
  func_800C4AF0(((char *) param_0) + 4, &D_808013DC_chonearmbandit);
  func_8010A570(param_0);
  func_800FFAB0(param_0);
}

void func_80801114_chonearmbandit(param_0) u8 *param_0;
{
    func_800BBCB8(param_0 + 4, 0, *(s32 **)(param_0 + 0x38), 1, &D_808013E8_chonearmbandit);
}

s32 func_80801154_chonearmbandit(param_0) Actor *param_0;
{
    s32 local_0 = 6;

    if (!param_0->unk64_20) {
        local_0 = 0x100006;
    }
    if (func_8010B990(param_0, local_0) & 0x30) {
        func_801096C8(param_0, 0);
        func_808010AC_chonearmbandit(param_0, 0);
        return 1;
    }
    return 0;
}
