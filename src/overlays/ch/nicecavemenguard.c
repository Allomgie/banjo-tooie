#include "ch/nicecavemenguard.h"

extern int D_80800920_chnicecavemenguard[];
extern void func_80102FDC(Actor *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_80105A9C(Actor *, f32);
extern s32 D_808009E8_chnicecavemenguard[];
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
typedef struct { s32 a, b, c; } Trip;
extern Trip D_808009F0_chnicecavemenguard;
extern s32 D_808009FC_chnicecavemenguard[];
extern void _subaddieaudioquick_entrypoint_4();
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern u8 D_80800968_chnicecavemenguard[];
extern u8 D_808008C0_chnicecavemenguard[];
extern u8 D_80800978_chnicecavemenguard[];
extern u8 D_80800984_chnicecavemenguard[];
extern f32 func_80101F24(Actor *);
extern s32 D_80800990_chnicecavemenguard[];
extern s32 D_8080099C_chnicecavemenguard[];
extern s32 D_808009DC_chnicecavemenguard[];
extern s32 D_808009AC_chnicecavemenguard[];
extern f32 D_808009BC_chnicecavemenguard[];
extern s16 D_808009CC_chnicecavemenguard[];
extern s16 D_808009D4_chnicecavemenguard[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(u8, f32);
s32 func_808003A8_chnicecavemenguard();
void func_808004FC_chnicecavemenguard();
void func_80800608_chnicecavemenguard();
extern void func_801018A4(), func_80102EC0(), func_80107C2C(), func_8080000C_chnicecavemenguard(), func_80800388_chnicecavemenguard();
extern u8 D_808008E8_chnicecavemenguard[];

int *chnicecavemenguard_entrypoint_0()
{
    return &D_80800920_chnicecavemenguard;
}

void func_8080000C_chnicecavemenguard(param_0) Actor *param_0;
{
    if (_glcutDll_entrypoint_20()) func_80102424(param_0, 6);
    else if (func_800DA298(0x186)) {
        func_800FFAB0(param_0);
        return;
    }
    func_80102FDC(param_0, param_0->scale * 1.25f);
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    func_800EF1B8((f32 *)param_0->actorData, param_0->rotation[1] + 180.0f, 150.0f);
    func_80105A9C(param_0, 400.0f);
    func_80105BAC(param_0);
}

void func_8080075C_chnicecavemenguard();

void func_80800730_chnicecavemenguard();

void func_80800600_chnicecavemenguard();

void func_808000D4_chnicecavemenguard(Actor *param_0)
{
  s32 local_0;
  f32 *local_4;
  u32 var_v0;
  local_0 = 0;
  func_800F7B9C(func_800F54E4(), 0x7E);
  if (func_80100094(param_0, 1) != 0)
  {
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
  }
  var_v0 = param_0->unk70_10;
  switch (var_v0)
  {
    case 1:
      local_0 = 1;
      func_80800600_chnicecavemenguard(param_0);
      if (func_800F64A4(func_800F54E4(), 0x60000) == 0)
    {
      _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_80800968_chnicecavemenguard, &D_808008C0_chnicecavemenguard, 5);
    }
      var_v0 = param_0->unk70_10;
      break;

    case 2:
      local_0 = 1;
      func_80800600_chnicecavemenguard(param_0);
      var_v0 = param_0->unk70_10;
      break;

    case 3:
      local_0 = 1;
      func_80800608_chnicecavemenguard(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      _subaddieaudioloop_entrypoint_2(param_0);
      _subaddiedialog_entrypoint_11(param_0->unk0, 0x17E7, 7, param_0->position, 0x96);
      func_80102424(param_0, 2);
    }
      var_v0 = param_0->unk70_10;
      break;

    case 4:
      func_80800730_chnicecavemenguard(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      _subaddiedialog_entrypoint_11(param_0->unk0, 0x17E8, 4, param_0->position, 0x96);
      func_80102424(param_0, 5);
    }
      var_v0 = param_0->unk70_10;
      break;

    case 5:
      func_8080075C_chnicecavemenguard(param_0);
      func_80105854(param_0);
      func_800F4F34(func_800F54E4(), param_0->position, 80.0f, 100.0f);
      if (func_80105A5C(param_0) != 0)
    {
      func_800DA544(0x186);
      _capod_entrypoint_14();
      func_800F7F98(func_800F54E4(), 0);
    }
      var_v0 = param_0->unk70_10;
      break;

    case 6:
      func_80800608_chnicecavemenguard(param_0);
      var_v0 = param_0->unk70_10;
      break;

  }

  local_4 = param_0->position;
  if (var_v0 != 5)
  {
    if (_sudeflect_entrypoint_0(local_4, 100.0f, 180.0f, 0xA) & 2)
    {
      _sudeflect_entrypoint_4(9, local_4);
    }
  }
  if ((local_0 != 0) && (_sudeflect_entrypoint_3((f32 *)param_0->actorData, param_0->rotation, &D_80800978_chnicecavemenguard, &D_80800984_chnicecavemenguard, 2) & 2))
  {
    _sudeflect_entrypoint_4(9, param_0->position);
  }
}

void func_80800388_chnicecavemenguard(Actor* arg0)
{
    func_8080080C_chnicecavemenguard(arg0);
}

s32 func_808007A8_chnicecavemenguard();

s32 func_808005D4_chnicecavemenguard();

s32 func_808003A8_chnicecavemenguard(param_0, param_1, param_2) u8 *param_0; s32 param_1; s16 param_2[3];
{
  s32 local_0;
  s16 (*new_var)[3];
  switch (param_1)
  {
    case 46:
      new_var = &param_2;
      func_808005D4_chnicecavemenguard(param_0, (*new_var)[0], (*new_var)[1]);
      goto block_13;

    case 29:
 do { } while (0);

    case 30:
      if ((func_800F52B8(func_800F54E4(), *((s32 **) param_0)) == 0x18) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x72))))) >> 0xA) == 1))
    {
      func_80102424(param_0, 3);
    }
      goto block_13;

    case 27:
      if ((func_800F52B8(func_800F54E4(), *((s32 **) param_0)) == 0x17) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x72))))) >> 0xA) == 1))
    {
      _capod_entrypoint_13(*((s32 **) param_0), 0, 6, 0x20);
      func_800F7F98(func_800F54E4(), 1);
      func_80102424(param_0, 4);
    }
      goto block_13;

    case 41:
      func_808007A8_chnicecavemenguard(param_0);
      goto block_13;

    case 42:
      func_8080080C_chnicecavemenguard(param_0);
      goto block_13;

    case 31:
      func_808004FC_chnicecavemenguard(param_0);
      goto block_13;

    default:
      return 0;

  }

  block_13:
  local_0 = 1;

  return local_0;
}

void func_808004FC_chnicecavemenguard(param_0) Actor *param_0;
{
    func_801015D0(param_0);
    func_800DF744(5, 1);
    func_800DF744(6, 1);
    func_800DF744(8, 3);
    switch (param_0->unk70_10) {
        case 5:
            func_800DF744(4, 0);
            func_800DF744(7, 0);
            break;
        case 4:
            if (func_80101F24(param_0) > 0.26f) {
                func_800DF744(4, 0);
                func_800DF744(7, 1);
                break;
            }
        default:
            func_800DF744(4, 1);
            func_800DF744(7, 0);
            break;
    }
}

s32 func_808005D4_chnicecavemenguard(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 != 0x17E8)
        func_80102424(param_0, 1);
}

void func_80800600_chnicecavemenguard(s32 arg0) 
{
}
void func_80800608_chnicecavemenguard(param_0) Actor *param_0;
{
    s32 local_0;

    if (!param_0->unk5F) {
        param_0->unk5F = func_800C4350(0, param_0->position, &D_808009DC_chnicecavemenguard);
    }
    for (local_0 = 0; local_0 < 4; local_0++) {
        if (func_80101E14(param_0, D_808009AC_chnicecavemenguard[local_0])) {
            func_800C301C(param_0->unk5F, D_808009CC_chnicecavemenguard[local_0]);
            func_800C31DC(param_0->unk5F, D_808009BC_chnicecavemenguard[local_0] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(param_0->unk5F, D_808009D4_chnicecavemenguard[local_0]);
            func_800C3BDC(param_0->unk5F);
            break;
        }
    }
    _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80800990_chnicecavemenguard, &D_8080099C_chnicecavemenguard);
}

void func_80800730_chnicecavemenguard(u8 *param_0) {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_808009E8_chnicecavemenguard, 0.0f);
}

void func_8080075C_chnicecavemenguard(u8 *param_0) {
    Trip local_0 = D_808009F0_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_808009FC_chnicecavemenguard, &local_0);
}

s32 func_808007A8_chnicecavemenguard(s32 param_0)
{
  s32 local_0;
  if (!func_80100094(param_0, 1))
  {
    _suexpression_entrypoint_7(param_0, 1, 0x96);
    local_0 = func_80100094(param_0, 1);
    _suexpression_entrypoint_12(local_0, 0x42700000, 0x41700000);
    _suexpression_entrypoint_17(local_0, 0x320);
  }
}

void func_8080080C_chnicecavemenguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/nicecavemenguard.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800920_chnicecavemenguard -> int[], D_80800990_chnicecavemenguard -> s32[], D_8080099C_chnicecavemenguard -> s32[], D_808009DC_chnicecavemenguard -> s32[], D_808009E8_chnicecavemenguard -> s32[], D_808009FC_chnicecavemenguard -> s32[] */
u8 D_808008C0_chnicecavemenguard[40] = { 0x0, 0x0, 0x2, 0x1, 0x17, 0xE5, 0x1, 0x0, 0x0, 0x0, 0x4, 0x1, 0x17, 0xE6, 0x2, 0x0, 0x0, 0x0, 0x4, 0x0, 0x18, 0x1B, 0x1, 0x0, 0x0, 0x0, 0x2, 0x0, 0x18, 0x1C, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xE, 0x3, 0x0 };
u8 D_808008E8_chnicecavemenguard[56] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0xA0, 0x0, 0x0, 0x2, 0xED, 0x0, 0x1, 0x40, 0xA0, 0x0, 0x0, 0x2, 0xED, 0x0, 0x1, 0x40, 0x80, 0x0, 0x0, 0x2, 0xEE, 0x0, 0x2, 0x3F, 0xB3, 0x33, 0x33, 0x2, 0xEF, 0x0, 0x2, 0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xF0, 0x0, 0x1, 0x40, 0x80, 0x0, 0x0, 0x2, 0xEE, 0x0, 0x1 };
int D_80800920_chnicecavemenguard[18] = { 0x30E03A5, 0x7EE0001, (u32)&D_808008E8_chnicecavemenguard, (u32)func_80102EC0, (u32)func_808000D4_chnicecavemenguard, (u32)func_801018A4, 0x5DC0000, 0x3FC00000, 0x18607E7, 0x40840124, (u32)func_80800388_chnicecavemenguard, 0x0, 0x0, (u32)func_8080000C_chnicecavemenguard, (u32)func_80107C2C, -0x7BEFEBEE, (u32)func_808003A8_chnicecavemenguard, 0x0 };
u8 D_80800968_chnicecavemenguard[16] = { 0x3, 0x23, 0x0, 0x0, 0x1, 0x5E, 0x0, 0x96, 0x0, 0x0, 0x0, 0xC, 0x2, 0x3C, 0x2, 0x0 };
u8 D_80800978_chnicecavemenguard[12] = { 0xC3, 0x96, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0, 0xC3, 0xAF, 0x0, 0x0 };
u8 D_80800984_chnicecavemenguard[12] = { 0x43, 0x96, 0x0, 0x0, 0x43, 0xE1, 0x0, 0x0, 0x43, 0x16, 0x0, 0x0 };
s32 D_80800990_chnicecavemenguard[3] = { 0x130417, 0xD00C0, 0xD90000 };
s32 D_8080099C_chnicecavemenguard[4] = { 0x3F23D70A, 0x3F3AE148, 0x3F51EB85, -0x40800000 };
s32 D_808009AC_chnicecavemenguard[4] = { 0x0, 0x3E6B851F, 0x3EA3D70A, 0x3ED70A3D };
f32 D_808009BC_chnicecavemenguard[4] = { 0.9f, 1.1f, 1.05f, 1.0f };
s16 D_808009CC_chnicecavemenguard[4] = { 0x5BE, 0x5BC, 0x5BD, 0x5BD };
s16 D_808009D4_chnicecavemenguard[4] = { 0x7D00, 0x55F0, 0x55F0, 0x55F0 };
s32 D_808009DC_chnicecavemenguard[3] = { 0x3060001, 0xC80BB8, 0x70000 };
s32 D_808009E8_chnicecavemenguard[2] = { 0x1305B6, 0x180000 };
Trip D_808009F0_chnicecavemenguard = { 0x3D75C28F, 0x3F0F5C29, -0x40800000 };
s32 D_808009FC_chnicecavemenguard[5] = { 0x130404, 0xD00F3, 0x10C0016, 0x36B00000, 0x0 };
