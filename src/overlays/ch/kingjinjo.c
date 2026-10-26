#include "common.h"

extern int D_808011A8_chkingjinjo;
extern int D_808011F0_chkingjinjo;
typedef struct { u8 pad_0[0x75]; u8 p0 : 3; u8 f10 : 1; u8 p1 : 4; u8 pad_1[5]; u8 p2 : 6; u8 f2 : 1; u8 p3 : 1; } KJFlags;
extern void *func_80100094();
extern f32 func_800DC178(f32, f32);
extern int D_808012A0_chkingjinjo;
extern int D_808012B0_chkingjinjo;
extern int _gcdialogcamera_entrypoint_0(int, int);
extern u8 unk6E[];
extern u8 unk6C[];
extern u8 unk6A[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern u8 D_808012C0_chkingjinjo[];
extern u8 D_808012E8_chkingjinjo[];
extern u8 D_808012D0_chkingjinjo[];
extern u8 D_808012F8_chkingjinjo[];
extern u8 D_808012DC_chkingjinjo[];
extern u8 D_80801304_chkingjinjo[];
extern void func_800DF744(int, int);
extern void func_80101870(void *, void *);
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } KJState;
extern u8 D_80801238_chkingjinjo[];
extern u8 D_80801254_chkingjinjo[];
extern u8 D_80801264_chkingjinjo[];
extern u8 D_80801274_chkingjinjo[];
extern u8 D_80801284_chkingjinjo[];
extern int func_800C3D78();
extern u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern f32 func_8010CD28(Actor *);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern s32 func_80102320(Actor *, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_80101E14(void *, f32);
extern int func_8010CD88(u8 *, f32, f32);
extern void func_8010D5DC();
extern void func_80102424(Actor *, s32);
extern s32 *_subaddiefind_entrypoint_2(s32, s32);
extern s32 func_800DA298(s32);
extern void func_801032B0(Actor *, s32, s32);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern s32 _glcutDll_entrypoint_20(void);
extern s32 func_800F54E4(void);
extern void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
extern void func_800F497C(s32);
extern void func_800F49A8(s32, s32);
extern void func_800F49D4(s32, void *, Unk80132ED0 *);
extern void func_800F4A58(s32, f32 *, f32);
extern s32 _suexpression_entrypoint_7(Actor *, s32, s16);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _suexpression_entrypoint_17(s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _gcgoto_entrypoint_1(s32, s32);
extern void func_801015D0(Actor *);
int func_80800C18_chkingjinjo();
void func_80800C60_chkingjinjo();
s32 func_80800634_chkingjinjo();
void func_808009FC_chkingjinjo();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0(), func_80800018_chkingjinjo();
extern u8 D_80801130_chkingjinjo[];

int chkingjinjo_entrypoint_0()
{
    return (int)&D_808011A8_chkingjinjo;
}

int *chkingjinjo_entrypoint_1()
{
    return &D_808011F0_chkingjinjo;
}

void func_80800018_chkingjinjo(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 *local_2;
    s32 pad_v[2];
    f32 local_1[3];
    local_0 = func_80100094(param_0, 0);
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 0xB);
        ((KJFlags *)param_0)->f10 = 0;
        return;
    }
    if (func_800DA298(0x360)) {
        _subaddiemarker_entrypoint_1(param_0, 0x154, 0x32, local_1, 1);
        local_2 = param_0->position;
        func_800EE7F8(local_2, local_1);
        param_0->rotation[1] = func_800DC178(0.0f, 360.0f);
        _subaddieDll_entrypoint_1(param_0);
        _subaddierouteDll_entrypoint_3(param_0, local_0, local_2);
        func_80102424(param_0, 6);
        func_8010A590(param_0);
        func_80104E78(param_0);
        ((KJFlags *)param_0)->f10 = 1;
        *(f32 *)((u8 *)param_0 + 0x58) = func_800DC178(8.0f, 12.0f);
        *(f32 *)(local_0 + 0xC) = func_800DC178(4.0f, 6.0f);
        ((KJFlags *)param_0)->f2 = 1;
        return;
    }
    if (func_800DA298(0x3B)) {
        if (!func_800DA298(0x43)) {
            func_800FFAB0(param_0);
            return;
        }
        func_80102424(param_0, 9);
        ((KJFlags *)param_0)->f10 = 0;
        return;
    }
    ((KJFlags *)param_0)->f10 = 0;
}

void func_80800194_chkingjinjo(Actor *param_0)
{
    u8 *local_1;
    f32 local_0[3];
    u8 sfx;

    local_1 = func_80100094(param_0, 0);
    switch (((KJState *)param_0)->st) {
    case 3:
        func_80800AE4_chkingjinjo(param_0, D_80801238_chkingjinjo);
        break;
    case 5:
        if (func_800D9078(&param_0->unk58)) {
            func_800F5A00(func_800F54E4(), local_0);
            local_0[1] += 200.0f;
            func_800D1000(0x5A, 1, local_0, 1, 0);
            func_80102424(param_0, 4);
        }
        break;
    case 6:
        if (func_800D9078(local_1 + 0xC)) {
            sfx = param_0->unk5F;
            if (sfx == 0) {
                param_0->unk5F = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
                sfx = param_0->unk5F;
            }
            param_0->unk5F = func_800C4350(sfx, param_0->position, D_80801254_chkingjinjo);
            *(f32 *)(local_1 + 0xC) = func_800DC178(4.0f, 6.0f);
        }
        if (!func_800C0638()) {
            if (func_8010CAC0(param_0->position, 1000)) {
                if (func_800D90A4(&param_0->unk58)) {
                    _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0, 6) + 0x152F, 0x44, param_0->position, 0xA5);
                    param_0->unk58 = (func_800DC178(8.0f, 12.0f));
                }
            }
        }
        if (func_8010D248()) {
            if (func_8010C500(param_0)) {
                param_0->unk54 = func_8010CD28(param_0);
            }
        }
        *(f32 *)&param_0->actorData[3] = param_0->scale * 60.0f;
        _subaddierouteDll_entrypoint_7(param_0, local_1, param_0->rotation[1], param_0->unk54, 400.0f, 0x4000);
        _subaddierouteDll_entrypoint_6(param_0, local_1, *(u16 *)(local_1 + 6), 0x7F, 0.2f, 0x14, 0x28);
        _subaddierouteDll_entrypoint_5(param_0, local_1, *(u16 *)(local_1 + 6), 0.1f, 4.0f, 80.0f);
        func_8010B990(param_0, 0x1405);
        if (func_8010C9B0(param_0->position, 0xC8)) {
            if (func_8010CD88(param_0, 180.0f, 60.0f)) {
                func_80102424(param_0, 8);
            }
        }
        break;
    case 7:
        if (func_80101E14(param_0, 0.3f)) {
            if (param_0->unk5F != 0 && func_800C3D78(param_0->unk5F)) {
                func_800C3CE8(param_0->unk5F);
            }
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801264_chkingjinjo);
        }
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 6);
        }
        break;
    case 8:
        if (func_8010D248()) {
            if (func_8010C500(param_0)) {
                param_0->unk54 = func_8010CD28(param_0);
            }
        }
        func_80102BF8(param_0, 0.1f, 4.0f, 80.0f);
        if (func_80101E14(param_0, 0.3f)) {
            if (param_0->unk5F != 0 && func_800C3D78(param_0->unk5F)) {
                func_800C3CE8(param_0->unk5F);
            }
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801274_chkingjinjo);
        }
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 6);
        }
        break;
    case 9:
        func_80800AE4_chkingjinjo(param_0, D_80801284_chkingjinjo);
        break;
    }
    if (func_800DA298(0x360)) {
        func_800F4EC8(func_800F54E4(), param_0->position, param_0->scale * 300.0f, 0, param_0->scale * 90.0f);
    } else {
        if (func_801022E4(param_0) == 0x3A9 && func_80102320(param_0, 0.55f, 0.95f)) {
            _suexpression_entrypoint_18(_suexpression_entrypoint_20(param_0), 1);
        }
    }
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
}

s32 func_80800634_chkingjinjo(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s16 *local_8;
    s32 local_9;
    s32 local_10;
    s32 local_11;
    s32 *local_0;
    f32 local_1[3];
    s32 local_2;
    void (*local_3)();
    s32 local_6;
    s32 local_7;
    f32 local_4[3];
    s32 local_5;

    switch (param_1) {
    case 0x2E:
        local_8 = (s16 *)&param_2;
        func_808009FC_chkingjinjo(param_0, local_8[0], local_8[1]);
        break;
    case 0x3F:
        if (param_0->unk70_10 != 7) {
            func_80102424(param_0, 7);
        }
        break;
    case 0x52:
        func_80800B28_chkingjinjo(param_0);
        break;
    case 0x95:
        local_0 = _subaddiefind_entrypoint_2(0x147, 0);
        if (local_0 != NULL) {
            param_0->unk3C = *local_0;
        } else {
            param_0->unk3C = 0;
        }
        if (func_800DA298(0x360)) {
            func_801032B0(param_0, 0x897, ((u16 *)param_0->unk0)[0xB]);
            _subaddierouteDll_entrypoint_1(param_0);
        } else {
            if (!func_800DA298(0x1A5) && !func_800DA298(0x3B) && !_glcutDll_entrypoint_20()) {
                local_2 = func_800F54E4();
                _subaddiemarker_entrypoint_1(param_0, 0x154, 0x33, local_1, 1);
                func_800F497C(local_2);
                func_800F49A8(local_2, 1);
                func_800F49D4(local_2, func_8010D5DC, param_0->unk0);
                func_800F4A58(local_2, local_1, 300.0f);
                func_80800CFC_chkingjinjo(param_0, 5, 0x20);
                func_80102424(param_0, 1);
            }
            func_801032B0(param_0, 0x896, ((u16 *)param_0->unk0)[0xB]);
        }
        if (param_0->unk70_10 == 2) {
            local_3 = func_8010D5DC;
            local_5 = func_800F54E4();
            _subaddiemarker_entrypoint_1(param_0, 0x154, 0x34, local_4, 1);
            func_800F497C(local_5);
            func_800F49A8(local_5, 1);
            func_800F49D4(local_5, local_3, param_0->unk0);
            func_800F4A58(local_5, local_4, 300.0f);
            func_80800CFC_chkingjinjo(param_0, 0x17, 0x2020);
        }
        if (func_800DA298(0x360)) {
            local_10 = 0xA5;
        } else {
            local_10 = 0xAE;
        }
        local_6 = _suexpression_entrypoint_7(param_0, 1, local_10);
        _suexpression_entrypoint_12(local_6, 60.0f, 20.0f);
        _suexpression_entrypoint_17(local_6, 1500);
        break;
    case 0x57:
        return func_80800BBC_chkingjinjo(param_0, param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
    case 0x0B:
        if (param_2 == 1) {
            func_80800C60_chkingjinjo(param_0, 3, 1);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1535, 6, param_0->position, 0xAE);
            return 4;
        }
        return 3;
    case 0x32:
        local_9 = param_0->unk70_10;
        switch (local_9) {
        case 1:
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x14FD, 0xE, param_0->position, 0xAE);
            break;
        case 2:
            _gcgoto_entrypoint_1(0x142, 1);
            break;
        }
        break;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808009D0_chkingjinjo(param_0) s32 param_0; {
    func_80800C18_chkingjinjo();
    _suexpression_entrypoint_8(param_0, 1);
}

void func_808009FC_chkingjinjo(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    s32 var_a1;

    switch (param_1) {                                 
    case 0x14FD:
        func_800DA544(0x1A5);
        func_80800CFC_chkingjinjo(param_0, 1, 0x30);
        func_80102424(param_0, 5);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 0.4f;
        return;
    case 0x1535:
        func_80800C18_chkingjinjo(param_0);
        func_80102424(param_0, 2);
        _glcutDll_entrypoint_6(0x143, 0x65);
        return;
    default:
        if (func_800DA298(0x360) == 0) {
            if ((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF) {
                func_80800C18_chkingjinjo(param_0);
            }
            if (func_800DA298(0x3B) != 0) {
                var_a1 = 9;
            } else {
                var_a1 = 3;
            }
            func_80102424(param_0, var_a1);
        }
        return;
    }
}

int func_80800AE4_chkingjinjo(s32 param_0[3], s32 param_1)
{
  s32 local_0;
  local_0 = _subaddiedialog_entrypoint_7(param_0, param_0 + 1, param_1 | 0);
  if (local_0 != 0 && local_0 != 0x1208)
  {
    func_80800C60_chkingjinjo(param_0, 3, 0);
  }
}

int func_80800B28_chkingjinjo(s32 param_0)
{
  f32 local_1[3];
  s32 pad0;
  if (func_801022E4() == 0x3A9)
  {
    func_800EE7F8(&local_1, param_0 + 4);
    func_800EF1B8(&local_1, *(s32 **)(param_0 + 0x48), 0xC2480000);
    _gcdialogcamera_entrypoint_3(&D_808012A0_chkingjinjo, *(s32 **)(param_0 + 0x38));
    _gcdialogcamera_entrypoint_4(&local_1);
    _gcdialogcamera_entrypoint_5(param_0 + 0x44);
    return;
  }
  _gcdialogcamera_entrypoint_3(&D_808012B0_chkingjinjo, *(s32 **)(param_0 + 0x38));
  _gcdialogcamera_entrypoint_4(param_0 + 4);
  _gcdialogcamera_entrypoint_5(param_0 + 0x44);
}

int func_80800BBC_chkingjinjo(Actor *param_0, s32 param_1, s32 param_2)
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if (((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF) != 2)
    {
      func_80800C60_chkingjinjo(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

int func_80800C18_chkingjinjo(param_0) Actor *param_0;
{
  if ((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF)
  {
    _capod_entrypoint_3(0, param_0);
    (*(u16 *)((char *)(param_0) + 0x6E)) &= 0xFE00;
  }
}

void func_80800C60_chkingjinjo(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    s32 local_0;

    local_0 = *(s32 *)((char *)param_0 + 0x6C) & 0x1FF;
    switch (local_0) {
    case 0:
        _capod_entrypoint_2(*(s32 *)((char *)param_0 + 0x0), 0x17, 0, param_0);
        
    case 1:
        _capod_entrypoint_8(1);
        *(u16 *)((char *)param_0 + 0x6E) = (u16) ((*(u16 *)((char *)param_0 + 0x6E) & 0xFE00) | 2);
        func_80800B28_chkingjinjo(param_0);
        _gcdialogcamera_entrypoint_8();
        
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

int func_80800CFC_chkingjinjo(Actor *param_0, s32 param_1, s32 param_2)
{
  s32 new_var;
  s32 temp_t6;
  new_var = *((s32 *) (((char *) param_0) + 0x6C));
  temp_t6 = new_var & 0x1FF;
  switch (temp_t6 & 0xFFFF)
  {
    case 0:
      _capod_entrypoint_2(*((s32 *) (((char *) param_0) + 0x0)), 0x17, param_2, param_0);

    case 2:
      *((u16 *) (((char *) param_0) + 0x6E)) = (u16) (((*((u16 *) (((char *) param_0) + 0x6E))) & 0xFE00) | 1);

    case 1:
      _capod_entrypoint_6(*((s32 *) (((char *) param_0) + 0x0)), param_1, param_2, param_0);
      return;
      if (!param_0)
    {
    }

  }

}

void func_80800D80_chkingjinjo(Actor *param_0)
{
  if (_glcutDll_entrypoint_20() != 0) {
    param_0->unk64_19 = 1;
    param_0->unk6C_0 = 1;
    return;
  }
  if ((func_800DA298(0x3B) != 0) && (func_800DA298(0x43) == 0)) {
    param_0->unk6C_0 = 1;
    return;
  }
  if (func_800DA298(0x360) != 0) {
    func_80102424(param_0, 2);
    param_0->unk64_19 = 0;
    param_0->unk6C_0 = 2;
    return;
  }
  param_0->unk64_19 = 1;
  param_0->unk6C_0 = 1;
}

void func_80800E58_chkingjinjo(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    if (param_0->unk70_10 == 1 && param_0->unk64_19) {
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_808012C0_chkingjinjo, D_808012E8_chkingjinjo);
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_808012D0_chkingjinjo, D_808012F8_chkingjinjo);
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_808012DC_chkingjinjo, D_80801304_chkingjinjo);
    }
    func_800EFA4C(local_0, -280.0f, 0.0f, -250.0f);
    func_800EFA4C(local_1, 170.0f, 400.0f, 80.0f);
    func_800EF334(local_0, param_0->scale);
    func_800EF334(local_1, param_0->scale);
    func_800EF04C(local_0, param_0->position);
    func_800EF04C(local_1, param_0->position);
    _sudeflect_entrypoint_2(local_0, local_1, 0xA);
}

s32 func_80800F60_chkingjinjo(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
void func_80800F74_chkingjinjo(u8 *param_0, s32 param_1)
{
    func_800DF744(3, (*(s32 *)((u8 *)(param_0) + 0x6C)) & 0x1FF);
    func_800DF744(4, (u32)((*(s32 *)((u8 *)(param_0) + 0x64)) << 0xC) >> 0x1F);
    func_80101870(param_0, param_1);
}
