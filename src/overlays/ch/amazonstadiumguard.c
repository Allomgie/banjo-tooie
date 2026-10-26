#include "common.h"

extern void *D_80800700_chamazonstadiumguard;
extern f32 D_808006B0_chamazonstadiumguard[];
extern u8 D_80800760_chamazonstadiumguard[];
extern void _suexpression_entrypoint_12(void *, f32, f32);
typedef union { s32 local_0; struct { s16 local_0; s16 local_1; } local_1; } AmazonGuardMessage37;
extern s32 D_80800770_chamazonstadiumguard[];
extern s32 D_8080078C_chamazonstadiumguard[];
extern void _subaddiedialog_entrypoint_7(void *, void *, void *);
extern s32 func_8010D278(void);
extern s32 D_808007A8_chamazonstadiumguard[];
extern s32 D_808007C4_chamazonstadiumguard[];
extern s32 D_808007D0_chamazonstadiumguard[];
extern u8 D_80800748_chamazonstadiumguard[];
extern u8 D_80800754_chamazonstadiumguard[];
extern void *func_80100094(Actor *, s32);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern s32 func_80101DDC(Actor *);
extern void func_80102424(Actor *, s32);
extern s32 func_8010CAC0(f32 *, s32);
extern void func_80102078(Actor *, f32);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_80103014(Actor *);
extern void func_801020DC(Actor *, s32);
extern s32 func_800DB9B0(void);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 _chbadshad_entrypoint_2(Actor *, s32, f32, f32 *);
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sudeflect_entrypoint_4(s32, f32 *);
extern void _sudeflect_entrypoint_3(f32 *, f32 *, void *, void *, s32);
void func_80800488_chamazonstadiumguard();

void *chamazonstadiumguard_entrypoint_0()
{
    return &D_80800700_chamazonstadiumguard;
}

void func_8080000C_chamazonstadiumguard(f32 *param_0)
{
  param_0[10] = param_0[1];
  param_0[11] = param_0[2];
  param_0[12] = param_0[3];
}

void func_80800648_chamazonstadiumguard();

void func_808005CC_chamazonstadiumguard();

void func_80800530_chamazonstadiumguard();

void func_80800028_chamazonstadiumguard(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 *local_4;

    local_0 = 0;
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    }
    switch (param_0->unk70_10) {
    case 1:
        local_0 = 1;
        func_80800530_chamazonstadiumguard(param_0);
        func_80800648_chamazonstadiumguard(param_0);
        break;
    case 2:
        local_0 = 1;
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
        }
        break;
    case 3:
        local_0 = 1;
        if (!func_8010CAC0(param_0->position, 500)) {
            func_80102078(param_0, 0.5f);
            func_80102424(param_0, 1);
        } else {
            func_808005CC_chamazonstadiumguard(param_0);
        }
        break;
    case 4:
        local_0 = 1;
        break;
    case 5:
        if (func_80101DDC(param_0)) {
            if (_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_1)) {
                param_0->position[0] = local_1[0];
                param_0->position[2] = local_1[2];
            } else {
                param_0->position[0] = D_808006B0_chamazonstadiumguard[0];
                param_0->position[2] = D_808006B0_chamazonstadiumguard[1];
            }
            func_80103014(param_0);
            func_801020DC(param_0, 0);
            func_80102424(param_0, 6);
        }
        break;
    case 6:
        func_80800620_chamazonstadiumguard(param_0);
        func_80800648_chamazonstadiumguard(param_0);
        local_4 = param_0->position;
        if (!func_800DB9B0() && !func_8010CAC0(local_4, 3000) && !param_0->unk7C_12) {
            func_800EE7F8(local_4, (f32 *)&param_0->actorData[4]);
            func_80103014(param_0);
            func_80102424(param_0, 1);
        }
        break;
    case 7:
        func_80800648_chamazonstadiumguard(param_0);
        break;
    case 8:
        func_80800648_chamazonstadiumguard(param_0);
        break;
    }
    if (param_0->unk7C_12) {
        if ((s32)param_0->unk70_10 >= 5) {
            local_3 = 0.8f;
        } else {
            local_3 = 1.0f;
        }
        if (_chbadshad_entrypoint_2(param_0, 3, 2.5f, local_2)) {
            if (_sudeflect_entrypoint_1(local_2, 350.0f, 0.0f, local_3 * 160.0f, 10) & 2) {
                _sudeflect_entrypoint_4(9, param_0->position);
            }
        }
    }
    if (local_0) {
        _sudeflect_entrypoint_3((f32 *)&param_0->actorData[4], param_0->rotation, D_80800748_chamazonstadiumguard, D_80800754_chamazonstadiumguard, 2);
    }
}

void func_808002F4_chamazonstadiumguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
s32 func_80800328_chamazonstadiumguard(Actor *param_0, s32 param_1, AmazonGuardMessage37 param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800488_chamazonstadiumguard(param_0, param_2.local_1.local_0, param_2.local_1.local_1);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800760_chamazonstadiumguard, *(s32 *)&param_0->scale);
            break;
        case 0x95:
            if (_glcutDll_entrypoint_20()) {
                func_80102424(param_0, 8);
            } else if (func_800EA090() == 4) {
                param_0->position[0] = D_808006B0_chamazonstadiumguard[0];
                param_0->position[2] = D_808006B0_chamazonstadiumguard[1];
                func_80103014(param_0);
                func_801020DC(param_0, 0);
                func_80102424(param_0, 6);
            }
            break;
        case 0x29:
            _suexpression_entrypoint_7(param_0, 1, 0x30);
            _suexpression_entrypoint_12((void *)func_80100094(param_0, 1), 65.0f, 15.0f);
            break;
        case 0x2A:
            if (func_80100094(param_0, 1)) _suexpression_entrypoint_8(param_0, 1);
            break;
        default: return 0;
    }
    return 1;
}

void func_80800488_chamazonstadiumguard(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2;
{
  switch (param_1)
  {
    case 0xF0A:
      func_800C01A8(0x64, 0, param_0);
      _capod_entrypoint_13(*param_0, 0, 0x24, 0x2010);
      func_80102424(param_0, 5);
      return;

    case 0xF0C:
      func_80102424(param_0, 6);
      return;

    case 0xF09:
      if (1)
    {
 goto dummy_label_907775; dummy_label_907775: ;
    }
      ;
      ;
      ;

    case 0xF0B:
      func_80102424(param_0, 3);
      return;

  }

}

void func_80800530_chamazonstadiumguard(s32 param_0)
{
    s32 local_0;
    if (func_8010CAC0(param_0 + 4, 0x1F4)) {
        local_0 = func_8010D284();
        if (local_0 == 5) {
            return;
        }
        if (func_8010D284() == 10) {
            return;
        }
        local_0 = func_8010D278();
        if (local_0 == 8) {
            if (func_800DA298(0x59) != 0) {
                local_0 = 5;
            } else {
                local_0 = 2;
            }
            func_80102424(param_0, local_0);
        } else {
            func_80102424(param_0, 2);
        }
    }
}

void func_808005CC_chamazonstadiumguard(s32 param_0)
{
  s32 local_0;
  local_0 = func_8010D278();
  if (local_0 == 8)
  {
    _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_80800770_chamazonstadiumguard);
  }
  else
  {
    _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_8080078C_chamazonstadiumguard);
  }
}

int func_80800620_chamazonstadiumguard(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddiedialog_entrypoint_7(param_0, local_0, &D_808007A8_chamazonstadiumguard);
}

void func_80800648_chamazonstadiumguard(s32 param_0)
{
  _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_808007C4_chamazonstadiumguard, &D_808007D0_chamazonstadiumguard);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/amazonstadiumguard.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800770_chamazonstadiumguard -> s32[], D_8080078C_chamazonstadiumguard -> s32[], D_808007A8_chamazonstadiumguard -> s32[], D_808007C4_chamazonstadiumguard -> s32[], D_808007D0_chamazonstadiumguard -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
f32 D_808006B0_chamazonstadiumguard[2] = { -6221.0f, -5709.0f };
u32 D_808006B8_chamazonstadiumguard[18] = { 0x0, 0x0, 0x40E00000, 0x1990000, 0x3F8CCCCD, 0x19A004A, 0x40800000, 0x19B0049, 0x40800000, 0x19B0000, 0x40400000, 0x19C004A, 0x40E00000, 0x1990249, 0x40E00000, 0x1990000, 0x40E00000, 0x1990000 };
void *D_80800700_chamazonstadiumguard = (void *)0x015F0116;
static u32 D_80800700_chamazonstadiumguard_rest[17] = { 0x6610001, (u32)&D_808006B8_chamazonstadiumguard, (u32)func_80800028_chamazonstadiumguard, (u32)func_80105834, (u32)func_80101870, 0x1F400000, 0x0, 0x0, 0x160, (u32)func_808002F4_chamazonstadiumguard, 0x0, 0x0, (u32)func_8080000C_chamazonstadiumguard, (u32)func_80107C2C, 0x86006502, (u32)func_80800328_chamazonstadiumguard, 0x0 };
u8 D_80800748_chamazonstadiumguard[12] = { 0xC3, 0x48, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0, 0xC4, 0x9, 0x80, 0x0 };
u8 D_80800754_chamazonstadiumguard[12] = { 0x43, 0x48, 0x0, 0x0, 0x43, 0xE1, 0x0, 0x0, 0xC2, 0x48, 0x0, 0x0 };
u8 D_80800760_chamazonstadiumguard[16] = { 0x43, 0x66, 0x0, 0x0, 0x43, 0x20, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0 };
s32 D_80800770_chamazonstadiumguard[7] = { 0x59012C, 0xF0A0000, -0x1, 0x0, 0x300000, 0xE0000, 0x4000000 };
s32 D_8080078C_chamazonstadiumguard[7] = { 0x58012C, 0xF090F0B, 0x201, 0x120E0000, 0x300000, 0xE0000, 0x4000000 };
s32 D_808007A8_chamazonstadiumguard[7] = { 0x12C, 0xF0C, 0x80, 0x0, 0x300000, 0xE0000, 0x7000000 };
s32 D_808007C4_chamazonstadiumguard[3] = { 0x130564, 0xD00F3, 0x10C0000 };
s32 D_808007D0_chamazonstadiumguard[4] = { 0x3F2E147B, 0x3F4CCCCD, 0x3F6B851F, -0x40800000 };
