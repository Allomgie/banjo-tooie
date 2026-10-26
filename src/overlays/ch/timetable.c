#include "common.h"

extern void func_80102FDC(f32 *, f32);
extern s32 D_80800730_chtimetable;
extern s32 D_80800744_chtimetable;
extern s32 D_80800758_chtimetable;
extern s32 D_8080076C_chtimetable[];
typedef struct TimetableEntry { s32 local_0[5]; } TimetableEntry;
extern s32 D_8080073C_chtimetable[];
extern int D_80800738_chtimetable[];
extern s32 D_8080080C_chtimetable;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_808007CC_chtimetable;
extern s32 _gccubesearch_entrypoint_1();
extern void _gspropctrl_entrypoint_11(s32, f32 *);
extern u8 D_808007BC_chtimetable[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
void func_80800000_chtimetable();

void func_80800000_chtimetable(param_0, param_1, param_2) u8 *param_0; s32 param_1; f32 *param_2; {
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(param_1 + 0x51F, param_0 + 4), param_2);
    param_2[2] = -1100.0f;
    param_2[1] = -50.0f;
}

void func_80800058_chtimetable(f32 *param_0) {
    func_80102FDC(param_0, param_0[14] * 0.75f);
    func_80800000_chtimetable(param_0, 0, param_0 + 10);
    func_80800000_chtimetable(param_0, 1, param_0 + 6);
}

s32 func_808000B0_chtimetable(param_0) s32 param_0; {
    s8 *var_v0;
    s32 var_v1;

    if (param_0 == D_80800730_chtimetable) {
        return 0;
    }
    if (param_0 == D_80800744_chtimetable) {
        return 1;
    }
    var_v0 = &D_8080076C_chtimetable;
    var_v1 = 3;
    if (param_0 == D_80800758_chtimetable) {
        return 2;
    }
loop_7:
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0)))) {
        return var_v1;
    }
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0x14)))) {
        return var_v1 + 1;
    }
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0x28)))) {
        return var_v1 + 2;
    }
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0x3C)))) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x50;
    if (var_v1 == 0xB) {
        return -1;
    }
    goto loop_7;
}

s32 func_8080016C_chtimetable(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (!func_800DA298(0x86)) {
        return 0;
    }
    if (param_2 == 0x12A && !func_800DA298(0x171)) {
        return 0;
    }
    local_0 = func_808000B0_chtimetable(param_2);
    if (((TimetableEntry *) &D_80800730_chtimetable)[local_0].local_0[4] != -1) {
        if (!func_800DA298(((TimetableEntry *) &D_80800730_chtimetable)[local_0].local_0[4])) {
            return 0;
        }
    }
    if (func_800DA298(((TimetableEntry *) &D_80800730_chtimetable)[local_0].local_0[1])) {
        return 0;
    }
    return 1;
}

void func_8080025C_chtimetable(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0 = func_808000B0_chtimetable(param_2);
  func_800DA544(*(s32 *)((u8 *)D_8080073C_chtimetable + local_0 * 20));
  func_800DA544(0x6B7);
  _glcutDll_entrypoint_0();
  _glcutDll_entrypoint_7(param_1);
  _glcutDll_entrypoint_10(param_2);
  _glcutDll_entrypoint_22(0x72);
  _glcutDll_entrypoint_16();
}

int func_808002D4_chtimetable()
{
  int new_var;
  int idx = func_808000B0_chtimetable();
  new_var = idx;
  new_var = (new_var * 5) & 0xFFFFFFFFFFFFFFFF;
  idx = (new_var & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
  return D_80800738_chtimetable[(((idx & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF];
}

s32 func_80800308_chtimetable(void)
{
  s32 *local_0;
 local_0 = &D_80800730_chtimetable; loop_1: if (func_800DA298(*((s32 *) (((s8 *) local_0) + 4))) != 0) {
    return *((s32 *) (((s8 *) local_0) + 0));
  }

  local_0 += 5;
  if (local_0 == (&D_8080080C_chtimetable))
  {
    return -1;
  }
  goto loop_1;
}

int func_80800364_chtimetable(Actor *param_0, s32 param_1, u32 param_2)
{
  s32 local_0;
  s32 local_1;
  param_2 |= 6;
  if (!param_1)
  {
    if (func_800DA298(0x95) != 0)
    {
      local_0 = func_80800308_chtimetable();
      local_1 = func_800EA05C();
      if (local_0 == local_1)
      {
        param_1 = 0xCF4;
      }
      else
      {
        param_1 = func_808002D4_chtimetable(local_0);
      }
    }
    else
    {
      param_1 = 0xCF3;
    }
  }
  _subaddiedialog_entrypoint_11(*((s32 **) (((char *) param_0) + 0x0)), param_1, param_2, (Actor *) (((char *) param_0) + 0x4), 0x42);
  param_0->unk74_30 = 1;
  return 1;
}

void func_80800404_chtimetable(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    if (!param_0->unk74_30) {
        func_8010D254(local_0);
        func_800EFA4C(local_1, -500.0f, 0.0f, -700.0f);
        func_800EFA4C(local_2, 0.0f, 1500.0f, 700.0f);
        func_800EF04C(local_1, (f32 *)&param_0->actorData[4]);
        func_800EF04C(local_2, (f32 *)&param_0->actorData[4]);
        if (func_800EFED0(local_1, local_2, local_0)) {
            if (!param_0->unk64_20) {
                func_80800364_chtimetable(param_0, 0xD07, 1);
                param_0->unk64_20 = 1;
            }
        } else param_0->unk64_20 = 0;
        func_800EFA4C(local_1, 0.0f, 0.0f, -700.0f);
        func_800EFA4C(local_2, 500.0f, 1500.0f, 700.0f);
        func_800EF04C(local_1, (f32 *)param_0->actorData);
        func_800EF04C(local_2, (f32 *)param_0->actorData);
        if (func_800EFED0(local_1, local_2, local_0)) {
            if (!param_0->unk64_19) {
                func_80800364_chtimetable(param_0, 0xD07, 1);
                param_0->unk64_19 = 1;
            }
        } else param_0->unk64_19 = 0;
    }
    if (param_0->unk70_10 == 1 && _subaddiedialog_entrypoint_5(param_0->position, 250, 60, 0)) {
        func_80800364_chtimetable(param_0, 0, 9);
    }
}

s32 func_808005B8_chtimetable(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        param_0->unk74_30 = 0;
        switch (((s16 *)&param_2)[0]) {
        case 0xD06:
            if (((s16 *)&param_2)[1] == 1) {
                func_8080025C_chtimetable(param_0, func_80800308_chtimetable(), func_800EA05C());
            }
            break;
        case 0xCF5:
        case 0xCF6:
        case 0xCF7:
        case 0xCF8:
        case 0xCF9:
        case 0xCFA:
        case 0xCFB:
            if (func_8080016C_chtimetable(param_0, func_80800308_chtimetable(), func_800EA05C())) {
                func_80800364_chtimetable(param_0, 0xD06, 0x48);
                return 1;
            }
        case 0xCF4:
            func_800C0850();
            return 1;
        }
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808007BC_chtimetable, param_0->scale);
        return 1;
    default:
        return 0;
    }
    return 1;
}

int chtimetable_entrypoint_0()
{
  return (int)&D_808007CC_chtimetable;
}
