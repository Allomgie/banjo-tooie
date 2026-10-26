#include "common.h"

extern char D_80800B20_charmouredcaveman;
extern int func_800D0B68(int, int);
extern void func_800D1000(int, int, void *, int, int);
extern int func_800DA298(int);
extern int func_800DA564(int, int);
extern void func_800FFAB0(void *);
extern void func_80102424(void *, int);
extern void func_8010B990(void *, int);
extern int _glcutDll_entrypoint_20(void);
typedef struct { int unk2C; int unk28; unsigned short unk76_11; } CharmouredCavemanActor;
extern u8 D_80800BA4_charmouredcaveman[];
extern u8 D_80800BBC_charmouredcaveman[];
extern u8 D_80800BB0_charmouredcaveman[];
extern u8 D_80800B78_charmouredcaveman[];
extern int _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 D_80800C08_charmouredcaveman;
extern s32 D_80800C14_charmouredcaveman;
extern s32 D_80800C20_charmouredcaveman;
extern void _subaddiedialog_entrypoint_11(void *, int, int, void *, int);
extern void func_8010A570(void *);
typedef struct { u8 pad[0x65]; u8 pad65:4; u8 flag:1; u8 rest65:3; u8 pad66[0xC]; u16 f72:6; u16 rest:10; } CavemanState;
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 _subaddiefade_entrypoint_0(Actor *);
typedef struct { u32 pad_0 : 11; u32 local_0 : 1; u32 pad_1 : 20; } Broad51ArmouredFlags;
extern f32 func_800F2094(f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern u8 D_80800B68_charmouredcaveman[];
extern u8 _chbaddiesetup_entrypoint_10[];
typedef struct { u8 pad0[0x18]; u16 hi; u16 id : 11; u16 rest : 5; u32 pad1C; u32 pad20; u32 kind : 10; u32 rest24 : 22; } CaveMsg;
typedef struct { f32 local_0[4]; } CavemanFloats61;
typedef union { s16 local_0[4]; s32 local_1[2]; } CavemanShorts61;
extern CavemanFloats61 D_80800BCC_charmouredcaveman;
extern CavemanFloats61 D_80800BDC_charmouredcaveman;
extern s32 D_80800BEC_charmouredcaveman[];
extern s32 D_80800BF4_charmouredcaveman[];
extern u8 D_80800BFC_charmouredcaveman[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(u8, f32);
extern s32 func_80101E14(Actor *, f32);
int func_8080072C_charmouredcaveman();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(), func_8080000C_charmouredcaveman(), func_808000EC_charmouredcaveman();
extern u8 D_80800AE0_charmouredcaveman[];

char *charmouredcaveman_entrypoint_0()
{
  return &D_80800B20_charmouredcaveman;
}

void func_8080000C_charmouredcaveman(param_0) CharmouredCavemanActor *param_0;
{
  int local_1;
  int local_0;
  local_0 = ((unsigned int) (*((u16 *) (((char *) param_0) + 118)))) >> 7;
  local_0 = local_0 - 0x32;
  local_1 = local_0;
  *((s32 *) (((char *) param_0) + 44)) = local_1;
  *((s32 *) (((char *) param_0) + 40)) = local_1 + 0x17A;
  if (_glcutDll_entrypoint_20() != 0)
  {
    func_80102424(param_0, 7);
    goto block_9;
  }
  if (func_800DA298(0x5D) != 0)
  {
    if ((func_800DA564(0x17A, 5) == (*((s32 *) (((char *) param_0) + 44)))) && (func_800D0B68(0x31, 1) == 0))
    {
      func_800D1000(0x31, 1, &param_0->unk28, 3, 0);
    }
    func_800FFAB0(param_0);
    return;
  }
  if (func_800DA298(*((s32 *) (((char *) param_0) + 40))) != 0)
  {
    func_800FFAB0(param_0);
    return;
  }
  block_9:
  func_8010B990(param_0, 0x1000);

}

void func_808009D4_charmouredcaveman();

void func_8080095C_charmouredcaveman();

void func_80800640_charmouredcaveman();

void func_808000EC_charmouredcaveman(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 1;
    local_1 = func_8010D23C();
    local_2 = 0;
    if (param_0->unk70_10 != 6) {
        local_2 = _sudeflect_entrypoint_1(param_0->position, 250.0f, -10.0f, 140.0f, 10) & 8;
    }
    switch (param_0->unk70_10) {
    case 1:
        func_80800640_charmouredcaveman(param_0);
        if (local_2) {
            func_808009D4_charmouredcaveman(param_0, local_2);
        }
        if (local_1 && func_8010D278() != 0x11 && func_8010C9B0(param_0->position, 400)) {
            param_0->unk64_19 = 0;
            func_80102424(param_0, 4);
        }
        break;
    case 2:
        func_80800640_charmouredcaveman(param_0);
        local_0 = 0;
        break;
    case 3:
        func_8080072C_charmouredcaveman(param_0, local_2);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, param_0->unk64_20 ? 2 : 1);
        }
        break;
    case 4:
        func_808008B0_charmouredcaveman(param_0);
        if (func_80101DDC(param_0)) {
            if (param_0->unk64_19) {
                func_8080095C_charmouredcaveman(param_0);
            } else {
                func_80102424(param_0, 1);
            }
        }
        break;
    case 5:
        local_0 = 0;
        func_8080092C_charmouredcaveman(param_0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 6);
            _subaddiefade_entrypoint_5(param_0);
        }
        break;
    case 6:
        local_0 = 0;
        if (_subaddiefade_entrypoint_0(param_0) == 0) {
            local_2 = 0;
        } else {
            local_2 = 1;
        }
        ((Broad51ArmouredFlags *)((u8 *)param_0 + 0x74))->local_0 = param_0->unk64_16 = local_2;
        break;
    case 7:
        func_8080072C_charmouredcaveman(param_0, local_2);
        break;
    }
    if (local_0 && local_1) {
        if (func_8010D278() != 0x11) {
            param_0->unk54 = func_8010CD28(param_0);
        }
        func_80102BF8(param_0, 0.3f, 3.0f, 300.0f);
    }
}

s32 func_80800370_charmouredcaveman(Actor *param_0, s32 param_1, s32 param_2)
{
  CaveMsg *sp5C;
  f32 sp50[3];
  s32 pad_x;
  s32 sp40[3];
  s32 sp3C;
  s32 sp38;
  f32 *sp2C;
  switch (param_1)
  {
    case 0x40:
      sp5C = (CaveMsg *) (*(s32 *) &param_2);
      if (sp5C->kind == 0x270)
      {
        if ((_sueggmisc_entrypoint_0(sp5C) == 0) && ((((u32) (param_0->unk0->unk18 << 0xB)) >> 0x1C) == 1))
        {
          func_800EC398(sp5C, sp50);
          sp2C = param_0->position;
          if (func_800F2094(func_800F1DF4(sp2C, sp50), param_0->rotation[1]) > 100.0f)
          {
            func_80109600(param_0, sp5C);
            func_8010A570(param_0);
            func_80102424(param_0, 5);
            _subaddieDll_entrypoint_4(param_0, 1);
            func_80103DFC(param_0, sp40);
            _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, 4, sp40[0], sp40[1], sp40[2], *((s32 *) (((s8 *) param_0) + 0x48)));
            sp3C = func_800DA564(0x17A, 5) == 0;
            func_800DA544(*((s32 *) (((s8 *) param_0) + 0x28)));
            if (sp3C != 0)
            {
              sp38 = 0x17E3;
            }
            else
              if (func_800DA564(0x17A, 5) == 0x1F)
            {
              sp38 = 0x1806;
              func_800DA544(0x5D);
              func_800DA7A8(0x17A, *((s32 *) (((s8 *) param_0) + 0x2C)), 5);
              func_800D1000(0x31, 1, sp2C, 1, 0);
            }
            else
            {
              sp38 = 0x17E4;
            }
            _subaddiedialog_entrypoint_11(param_0->unk0, sp38, 0x44, sp2C, 0xA6);
            *((u8 *) (((s8 *) param_0) + 0x75)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x75))) & 0xFFFD);
            return 1;
          }
        }
      }

    case 0x3E:
    case 0x3F:
      if ((((CaveMsg *) (*(s32 *) &param_2))->kind == 0) && (func_800F64A4(((CaveMsg *) (*(s32 *) &param_2))->id, 0x10000) != 0))
      {
        return 0;
      }
      func_808009D4_charmouredcaveman(param_0);
      func_80109600(param_0, *(s32 *) &param_2);
      break;

    case 0x30:
      return 5 - func_800DA980(0x17A, 5);

    case 0x2E:
      pad_x = *(s16 *) &param_2;
      if (pad_x == 0x17E2)
      {
        func_800DA544(0x66C);
        *((u8 *) (((s8 *) param_0) + 0x65)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x65))) & 0xFFEF);
        func_8010A590(param_0);
        func_80102424(param_0, 1);
      }
      else
      {
        func_800FFAB0(param_0);
      }
      break;

    case 0x52:
      _gcdialogcamera_entrypoint_3(&D_80800B68_charmouredcaveman, *((s32 *) (((s8 *) param_0) + 0x38)));
      break;

    default:
      return 0;

  }
  return 1;
}

void func_80800640_charmouredcaveman(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80800BA4_charmouredcaveman, D_80800BBC_charmouredcaveman);
    _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800BB0_charmouredcaveman, 0.83f);
    if (local_0 && param_0->unk7C_12) {
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += param_0->scale * 180.0f;
        func_800EE7F8(local_2, local_1);
        local_2[1] -= param_0->scale * 10.0f;
        func_800BBCB8(local_1, local_2, 1.0f, 8, D_80800B78_charmouredcaveman);
    }
}

int func_8080072C_charmouredcaveman(param_0) Actor *param_0;
{
    CavemanFloats61 local_0;
    CavemanFloats61 local_1;
    CavemanShorts61 local_2;
    CavemanShorts61 local_3;
    s32 local_4;
    local_0 = D_80800BCC_charmouredcaveman;
    local_1 = D_80800BDC_charmouredcaveman;
    local_2 = *(CavemanShorts61 *)D_80800BEC_charmouredcaveman;
    local_3 = *(CavemanShorts61 *)D_80800BF4_charmouredcaveman;
    if (param_0->unk5F == 0) param_0->unk5F = func_800C4350(0, param_0->position, D_80800BFC_charmouredcaveman);
    for (local_4 = 0; local_4 < 4; local_4++) {
        if (func_80101E14(param_0, local_0.local_0[local_4])) {
            func_800C301C(param_0->unk5F, local_2.local_0[local_4]);
            func_800C31DC(param_0->unk5F, local_1.local_0[local_4] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(param_0->unk5F, local_3.local_0[local_4]);
            func_800C3BDC(param_0->unk5F);
            break;
        }
    }
}

int func_808008B0_charmouredcaveman(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = param_0 + 4;
 if (1) { }
  local_1 = _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800C08_charmouredcaveman, 0.3f);
  if (_subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800C14_charmouredcaveman, 0.5f))
  {
    func_80018820(0, 0x3F800000, 0x3ECCCCCD);
    func_800E15CC(0, 0x41A00000, 0x3F59999A);
  }
}

int func_8080092C_charmouredcaveman(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800C20_charmouredcaveman, 0.1f);
}

void func_8080095C_charmouredcaveman(u8 *param_0)
{
  int new_var;
  param_0[0x65] &= 0xFFF7;
  if (func_800DA298(0x66C) == 0)
  {
    new_var = !param_0;
    _subaddiedialog_entrypoint_11(*((s32 *) param_0), 0x17E2, 0xE, 4 + param_0, 0xA6);
    if ((new_var && (!param_0)) && (!param_0))
    {
    }
    param_0[0x65] |= 0x10;
    func_8010A570(param_0);
  }
  func_80102424(param_0, 3);
}

void func_808009D4_charmouredcaveman(CavemanState *param_0) {
    switch (param_0->f72) {
    case 3:
        break;
    case 4:
        param_0->flag = 1;
        break;
    default:
        func_8080095C_charmouredcaveman(param_0);
        break;
    }
}
