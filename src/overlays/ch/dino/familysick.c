#include "common.h"

#define SFX (*(s32 *)&this->unk54)
#define F74 ((ActorFlags74 *)((u8 *)this + 0x74))
extern int D_80800E60_chdinofamilysick;
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _chbaddiesetup_entrypoint_6(void *, void *, s32, s32, s32, s32, s32);
extern void _subaddietaxi_entrypoint_16(void);
extern int D_80800EA8_chdinofamilysick;
extern u8 D_80800F48_chdinofamilysick[];
extern f32 func_800F3780(f32, void*, u32);
void func_80105A9C(u8*, f32);
void func_80105834();
typedef struct { u32 pad74_4 : 28; u32 unk74_0 : 4; } ActorFlags74;
extern u8 D_80800F68_chdinofamilysick[];
extern s32 func_800EA05C();
extern s32 _glcutDll_entrypoint_19(s32);
extern void func_80102424(Actor *, s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern s32 func_80105494(Actor *);
extern s32 func_800DA298(s32);
extern void func_800FFAB0(Actor *);
extern s32 func_800C8A98(void);
extern f32 func_80103EAC(Actor *);
extern void func_800C8E54(s32, f32, f32);
extern void func_800C8FB0(s32, s32, s32, s32);
extern void func_800C8F64(s32, s32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800C8CB8(s32, f32 *);
extern void func_801015D0(Actor *);
extern s32 func_801022E4(Actor *);
extern void func_800DF744(s32, s32);
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern int D_80800F78_chdinofamilysick;
typedef struct { u8 local_0[0x78]; u32 local_1 : 26; u32 local_2 : 1; u32 local_3 : 5; } DinoSickFlags49;
extern u32 D_80800E98_chdinofamilysick[];
extern void func_80101EE4(Actor *, f32);
extern u8 _chdinofamilysick_entrypoint_0[];
typedef struct { u32 local_0[3]; } Mass64DinoColor;
extern Mass64DinoColor D_80800F30_chdinofamilysick;
extern Mass64DinoColor D_80800F3C_chdinofamilysick;
extern f32 func_80101F24();
extern void func_800F3214(u32 *, u32 *, u32 *, f32);
extern void func_800C8E84(s32, u32 *);
extern s32 func_80105998(Actor *, f32);

int *chdinofamilysick_entrypoint_0()
{
  return &D_80800E60_chdinofamilysick;
}

void func_8080000C_chdinofamilysick(Actor *param_0)
{
  s32 pad0;
  f32 *local_1;
  f32 **new_var;
  switch ((*param_0).unk70_10)
  {
    case 1:
      local_1 = param_0->position;
      if (_subaddiedialog_entrypoint_4(local_1, 600, 0))
    {
      _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C7, 15, local_1, 0x39);
    }
      _sudeflect_entrypoint_1(local_1, param_0->scale * 235.0f, 0.0f, param_0->scale * 179.0f, 30);
      break;

    case 3:
      if (_subaddietaxi_entrypoint_1(param_0, 2))
    {
      func_800DA544(0x189);
      func_80102424(param_0, 5);
    }
      break;

    case 4:
      if (_subaddietaxi_entrypoint_11(param_0, 2) && _subaddietaxi_entrypoint_5(param_0, 2))
    {
      func_80102424(param_0, 1);
    }
      _sudeflect_entrypoint_1(param_0->position, param_0->scale * 235.0f, 0.0f, param_0->scale * 179.0f, 30);
      break;

    case 5:
      local_1 = param_0->position;
      new_var = &local_1;
      if (_subaddiedialog_entrypoint_4(local_1, 600, 0))
    {
      _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C8, 15, *new_var, 0x39);
    }
      _sudeflect_entrypoint_1(local_1, param_0->scale * 235.0f, 0.0f, param_0->scale * 179.0f, 30);
      break;

  }

  _subaddietaxi_entrypoint_9(param_0, 2);
  _chdinofamilyfx_entrypoint_0(param_0);
}

f32 func_808001FC_chdinofamilysick(s32 param_0, s32 param_1)
{
  s32 local_1;
  f32 local_0;
  _gccubesearch_entrypoint_9(0x52D, &local_1, 1);
  _gspropctrl_entrypoint_11(local_1, param_1);
  local_0 = _gspropctrl_entrypoint_12(local_1);
  return local_0;
}

void func_80800244_chdinofamilysick(Actor *param_0, s32 param_1)
{
    f32 local_0[3];

    switch (func_800CB3E0(param_1)) {
    case 1:
        func_80102424(param_0, 1);
        break;
    case 3:
        _subaddietaxi_entrypoint_10(param_0, param_1, 4);
        break;
    case 4:
        param_0->rotation[1] = func_808001FC_chdinofamilysick(param_1, local_0);
        func_80102424(param_0, 3);
        _subaddietaxi_entrypoint_0(param_0, param_1, local_0, -1);
        break;
    case 6:
        func_80102424(param_0, 5);
        break;
    }
}

void func_8080030C_chdinofamilysick(s32 param_0[3], s32 param_1[3], s32 param_2, s32 param_3)
{
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0, param_1[0], param_1[1], param_1[2], param_2, param_3);
  if (param_0)
  {
  }
}

s32 func_80800368_chdinofamilysick(s32 param_0, s32 param_1, s32 param_2) {
    if (func_800EA05C(param_0) == 0x121) {
        func_808001FC_chdinofamilysick(param_0, param_2);
        return 2;
    }
    return 1;
}

s32 func_808003B0_chdinofamilysick(Actor *param_0, s32 param_1, s32 param_2)
{
    u32 local_0;
    switch (param_1) {
    case 0x3E:
        local_0 = param_0->unk70_10;
        if (local_0 == 1 || local_0 == 2 || local_0 == 4) {
            if (func_800DA298(0x15D) && _subaddietaxi_entrypoint_2(param_0, 2))
                func_80102424(param_0, 2);
            return 1;
        }
        return 0;
    case 0x44:
        func_80800244_chdinofamilysick(param_0, param_2);
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        if (func_801022E4(param_0) == 0x3F7) {
            func_800DF744(3, 1);
            return 1;
        }
        func_800DF744(1, 0);
        func_800DF744(2, 1);
        func_800DF744(3, 2);
        return 1;
    case 0x37:
        func_80101EE4(param_0, 0.0f);
        return 1;
    case 0x95:
        if (_glcutDll_entrypoint_20()) {
            func_800FFAB0(param_0);
            return 1;
        }
        if (((DinoSickFlags49 *)param_0)->local_2) {
            if (func_800DA298(0x189) || func_800DA298(0x15E)) {
                func_800FFAB0(param_0);
                return 1;
            }
            if (!_subaddietaxi_entrypoint_13(param_0, 2, &_chdinofamilysick_entrypoint_0, 7)) {
                func_800FFAB0(param_0);
                return 1;
            }
        } else if (func_800CB3E0(2) == 6 || func_800DA298(0x189) || func_800DA298(0x15E)) {
            func_800FFAB0(param_0);
        }
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_3(D_80800E98_chdinofamilysick, param_0->scale);
        return 3;
    default:
        return 0;
    }
}

int *chdinofamilysick_entrypoint_1()
{
    return &D_80800EA8_chdinofamilysick;
}

void func_808005F8_chdinofamilysick(s32 *param_0) {
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    switch (temp_v0) {                              
    case 0x114:
        if (_glcutDll_entrypoint_19(0x38) == 0) {
            func_800FFA88(*param_0);
            return;
        }
        return;
    case 0x118:
        if (_glcutDll_entrypoint_20() != 0) {
            if (func_80105494(param_0) != 0) {
                func_800FFAB0(param_0);
                return;
            }
            func_80102424(param_0, 7);
            return;
        }
        if (_glcutDll_entrypoint_19(0x38) == 0) {
            if (func_80105494(param_0) == 0) {
                if ((func_800DA298(0x189) == 0) && (func_800DA298(0x15E) != 0)) {
                    func_80102424(param_0, 6);
                    return;
                }
                func_800FFAB0(param_0);
                return;
            }
            func_800FFAB0(param_0);
            return;
        }
        break;
    case 0x121:
        if (func_800DA298(0x189) != 0) {
            if (func_800DA298(0x15E) != 0) {
                func_80102424(param_0, 3);
                return;
            }
            func_80102424(param_0, 1);
            return;
        }
        func_800FFA88(*param_0);
        return;
    default:
        func_800FFA88(*param_0);
        break;
    }
}

void func_80800A1C_chdinofamilysick();

void func_80800768_chdinofamilysick(Actor *param_0)
{
    Mass64DinoColor local_0;
    Mass64DinoColor local_1;
    Mass64DinoColor local_2;

    switch (param_0->unk70_10) {
    case 1:
        if (_subaddiedialog_entrypoint_4(param_0->position, 600, 0)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C8, 0xF, param_0->position, 0x39);
        }
        break;
    case 2:
        local_1 = D_80800F30_chdinofamilysick;
        local_2 = D_80800F3C_chdinofamilysick;
        func_800F3214(local_0.local_0, local_1.local_0, local_2.local_0, func_80101F24(param_0));
        func_800C8E84(*(s32 *)&param_0->unk54, local_0.local_0);
        break;
    case 3:
        if (_subaddiedialog_entrypoint_4(param_0->position, 600, 0)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C9, 0xF, param_0->position, 0x39);
        }
        _sudeflect_entrypoint_1(param_0->position, param_0->scale * 235.0f, 0.0f, param_0->scale * 179.0f, 30);
        break;
    case 4:
        if (func_80105A5C(param_0)) {
            _glcutDll_entrypoint_24(0x118, -1, 0x38);
            func_800FFA88(param_0->unk0);
        } else {
            if (func_80105998(param_0, 0.15f)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x180D, 0xF, param_0->position, 0x39);
            }
            func_80800A1C_chdinofamilysick(param_0);
        }
        break;
    case 5:
        if (func_80105A5C(param_0)) {
            func_800DA524(0x189);
            func_80101180(0x290, 0x33, 0);
            func_80102424(param_0, 6);
            *((u8 *)param_0 + 0x77) &= ~0xF;
        } else {
            func_80800A1C_chdinofamilysick(param_0);
        }
        break;
    case 6:
        if (_subaddiedialog_entrypoint_4(param_0->position, 600, 0)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17CA, 0xF, param_0->position, 0x39);
        }
        break;
    }
    _sudeflect_entrypoint_1(param_0->position, param_0->scale * 235.0f, 0.0f, param_0->scale * 179.0f, 30);
    _chdinofamilyfx_entrypoint_0(param_0);
}

void func_80800A1C_chdinofamilysick(u8 *param_0)
{
  f32 temp_f2;
  f32 var_f0;
  temp_f2 = func_800F3780(func_80101F24(), &D_80800F48_chdinofamilysick, 4);
  if ((((u32) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 10) == 4)
  {
    var_f0 = 0.75f;
  }
  else
  {
    var_f0 = 1.0f;
  }
  func_80105A9C(param_0, (var_f0 * 1.0f) * (temp_f2 * 1200.0f));
  func_80105834(param_0);
}

s32 func_80800AB0_chdinofamilysick(Actor *this, s32 msg, s32 arg)
{
    f32 vec[3];

    switch (msg) {
    case 0x49:
        switch (func_800EA05C()) {
        case 0x114:
            if (_glcutDll_entrypoint_19(0x38)) {
                func_80102424(this, 4);
                _capod_entrypoint_13(this->unk0, 0, 5, 0x2831);
                F74->unk74_0 = 0;
                return 1;
            }
            break;
        case 0x118:
            if (_glcutDll_entrypoint_19(0x38)) {
                if (func_80105494(this)) {
                    func_80102424(this, 5);
                    _capod_entrypoint_13(this->unk0, 0, 0xC, ((func_800DA298(0x8A) && func_800DA298(0x15F)) ? 0 : 0x100) | 0x2831);
                    F74->unk74_0 = 0;
                    return 1;
                }
                func_800FFAB0(this);
                return 0;
            }
            break;
        case 0x121:
            if (_glcutDll_entrypoint_19(0x71)) {
                SFX = func_800C8A98();
                func_800C8E54(SFX, func_80103EAC(this) * 1.5f, func_80103EAC(this) * 2.0f);
                func_800C8FB0(SFX, 0, 0xFF, 0);
                func_800C8F64(SFX, 3);
                func_800EEC30(vec, 45.0f, this->rotation[1], func_80103EAC(this) * 2.0f);
                func_800EF04C(vec, this->position);
                func_800C8CB8(SFX, vec);
                func_80102424(this, 2);
                return 1;
            }
            break;
        }
        return 0;
    case 0x1F:
        func_801015D0(this);
        if (func_801022E4(this) == 0x3F7) {
            func_800DF744(3, 1);
        } else {
            func_800DF744(1, 0);
            func_800DF744(2, 1);
            func_800DF744(3, 2);
        }
        return 1;
    case 0x33:
        func_80102424(this, 3);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(this->position);
        _gcdialogcamera_entrypoint_3(D_80800F68_chdinofamilysick, this->scale);
        return 3;
    }
    return 0;
}

int chdinofamilysick_entrypoint_2()
{
  return &D_80800F78_chdinofamilysick;
}
