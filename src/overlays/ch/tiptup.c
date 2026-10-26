#include "common.h"

extern int D_80801448_chtiptup[];
extern int D_80801490_chtiptup[];
extern int D_808014D8_chtiptup[];
extern f32 D_80801398_chtiptup[];
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern s32 D_80801570_chtiptup[];
extern s32 D_80801360_chtiptup[];
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32[3], void *, void *, s32);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern void func_800D1000();
extern void func_800F82D4(void *param_0, s32 param_1);
extern void *func_800F54E4();
extern void func_80102424(Actor *param_0, s32 param_1);
extern s32 func_800DA298(s32 param_0);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
void func_80800614_chtiptup(f32 *, f32 *, s32, f32, void *);
extern s32 D_80801580_chtiptup[];
extern s32 D_808015B0_chtiptup[];
extern s32 D_808015C0_chtiptup[];
extern s32 D_808015CC_chtiptup[];
extern s32 D_808015DC_chtiptup[];
extern s32 D_808015EC_chtiptup[];
extern s32 D_80801600_chtiptup[];
extern u8 unk2C[];
extern void _capod_entrypoint_2();
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_5(f32 *);
extern u8 unk2A[];
typedef struct { u8 pad[0x95]; u8 local_0:7; u8 local_1:1; } TiptupFlags27;
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern int D_8080165C_chtiptup[];
extern int D_80801668_chtiptup[];
extern int D_80801674_chtiptup[];
extern int D_8080167C_chtiptup[];
extern u8 D_808016A0_chtiptup[];
extern u8 D_80801690_chtiptup[];
extern u8 D_808016AC_chtiptup[];
extern s32 func_800D9154(f32 *, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, void *, void *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 unk6E[];
extern u8 unk6C[];
extern u8 D_80801520_chtiptup[];
extern u8 D_8080152C_chtiptup[];
extern u8 D_8080154C_chtiptup[];
extern u8 D_80801558_chtiptup[];
extern u8 D_80801568_chtiptup[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 func_80101DDC(Actor *);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern s32 func_80105A5C(Actor *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s32 func_8001210C(s32);
extern f32 func_80105AE8(Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80105834(Actor *);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, void *);
extern s32 D_80801620_chtiptup[];
extern s32 D_8080162C_chtiptup[];
extern s32 D_80801638_chtiptup[];
extern s32 D_80801644_chtiptup[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
extern f32 func_800F3780(f32, s32 *, s32);
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
s32 func_80800534_chtiptup();
int func_80800578_chtiptup();
int func_80800774_chtiptup();
int func_808007CC_chtiptup();
void func_80800808_chtiptup();
int func_808008B4_chtiptup();
void func_80800934_chtiptup();
extern void func_80101870(), func_80102EC0(), func_80107C2C(), func_80108ED0(), func_80800C70_chtiptup();
extern u8 D_808013E0_chtiptup[];

int chtiptup_entrypoint_0()
{
    return (int)&D_80801448_chtiptup;
}

int chtiptup_entrypoint_1()
{
  return (int)&D_80801490_chtiptup;
}

int *chtiptup_entrypoint_2()
{
    return &D_808014D8_chtiptup;
}

void func_80800694_chtiptup();

void func_808004C4_chtiptup();

void func_80800024_chtiptup(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];

    _sudeflect_entrypoint_1(param_0->position, 250.0f, 0.0f, 70.0f, 0xE);
    func_80800694_chtiptup(param_0);
    switch (param_0->unk70_10) {
    case 1:
        func_808004C4_chtiptup(param_0);
        break;
    case 4:
        if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801520_chtiptup, 0.7f)) {
            func_80800614_chtiptup(param_0->position, param_0->position, 8, 1.5f, D_8080152C_chtiptup);
        }
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 5);
            _subaddieDll_entrypoint_4(param_0, 1);
        }
        break;
    case 5:
        if (!func_80105A5C(param_0) && func_800D9154(&param_0->unk58, 2.4f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801558_chtiptup);
        }
        if (!func_8001210C(3)) {
            local_0 = (func_80105AE8(param_0) < 0.45f) ? NULL : D_80801568_chtiptup;
            func_800EE7F8(local_1, param_0->position);
            func_800EF1B8(local_1, param_0->rotation[1], 5e+01f);
            local_1[1] -= 40.0f;
            func_80800614_chtiptup(param_0->position, local_1, 3, 1.0f, local_0);
        }
        func_80105834(param_0);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, func_80105A5C(param_0) == 0, D_8080154C_chtiptup);
        break;
    }
}

void func_80800200_chtiptup(Actor *param_0)
{
  s32 *local_0;

  if ((func_800D0A9C(0x20, 1) != 0) && (_glcutDll_entrypoint_20() == 0)) {
    func_800FFAB0(param_0);
    return;
  }
  param_0->unk6C_0 = _subaddiesect_entrypoint_1(param_0);
  _subaddiesect_entrypoint_2(param_0, param_0->unk6C_0, 0);
  local_0 = _subaddiefind_entrypoint_2(0x359, 0);
  if (local_0 != 0) {
    param_0->unk3C = (Unk80132ED0 *)*local_0;
  }
  func_80105A9C(param_0, 4e+02f);
  if (_glcutDll_entrypoint_20() != 0) {
    func_80102424(param_0, 6);
  }
}

s32 func_808002C8_chtiptup(Actor *this){
    u8 local_0 = _subaddieaudioloop_entrypoint_3((*(u8 *)((char *)(this) + 40)));
    (*(u8 *)((char *)(this) + 40)) = local_0;
}

int func_808002F4_chtiptup(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    switch (param_1) {
    case 0x2E: func_80800578_chtiptup(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]); break;
    case 0x2F: func_80800534_chtiptup(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]); break;
    case 0x52: _gcdialogcamera_entrypoint_3(D_80801398_chtiptup, param_0->scale); break;
    case 0x57: return func_80800774_chtiptup(param_0, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0xB:
        if (param_2 == 4) {
            func_808007CC_chtiptup(param_0);
            func_800FFA88(param_0->unk3C);
            func_800FFAB0(param_0);
            return 4;
        }
        return 3;
    case 0x95: ((u8 *)param_0)[0x28] = 0; break;
    case 0xB8:
        local_0 = param_2 & 0xFFFF;
        local_1 = func_800DA298(0xBD);
        switch (local_0) {
        case 1: return local_1 ? 0xFF8 : 0xFF7;
        case 2: return local_1 ? 0xFF8 : 0x104F;
        case 3: return local_1 ? 0xFF8 : 0xFF7;
        }
    default: return 0;
    case 0x29:
    case 0x2A: break;
    }
    return 1;
}

void func_808004C4_chtiptup(Actor *param_0)
{
    s32 local_0;

    local_0 = _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_80801570_chtiptup, &D_80801360_chtiptup, 7);
    if (local_0 != 0) {
        if (_subaddiedialog_entrypoint_9(param_0, local_0, &D_80801360_chtiptup, 7) != 3) {
            func_80800808_chtiptup(param_0, 2, 0);
        }
    }
}

s32 func_80800534_chtiptup(s32 param_0, s32 param_1, s32 param_2) {
    func_80800934_chtiptup(param_0, 0x40, 0);
    func_800D1000(0x20, 1, 0, 0, 0);
}

int func_80800578_chtiptup(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0xFFA)
  {
    func_800F82D4(func_800F54E4(param_0), 0);
    func_80102424(param_0, 4);
    func_808008B4_chtiptup(param_0, 4, 0x30);
  }
  else
  {
    if ((*((s32 *) (((char *) param_0) + 0x2C))) != 0)
    {
      func_808007CC_chtiptup(param_0);
    }
    func_80102424(param_0, (func_800DA298(0xBE)) ? (3) : (1));
  }
}

void func_80800614_chtiptup(f32 *param_0, f32 *param_1, s32 param_2, f32 param_3, void *param_4)
{
    s32 local_0;

    local_0 = func_800B53A4(param_2);
    func_800BABB8(local_0, param_0, param_1, param_3, &D_80801580_chtiptup);
    if (param_4 != 0) {
        func_800BABB8(local_0, param_0, param_1, param_3, param_4);
    }
    func_800BA22C(local_0, param_2);
}

void func_80800694_chtiptup(u8 *param_0) {
    switch (func_801022E4()) {
    case 0x18A:
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_808015B0_chtiptup, 0.7f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_808015C0_chtiptup, 0.35f);
        _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_808015CC_chtiptup, &D_808015DC_chtiptup);
        break;
    case 0x189:
        if (func_80101E4C(param_0, &D_80801600_chtiptup) != 0) {
            if (param_0[0x28] == 0) {
                param_0[0x28] = _subaddieaudioquick_entrypoint_1(param_0, param_0 + 4);
            }
            func_800C4350(param_0[0x28], param_0 + 4, &D_808015EC_chtiptup);
        }
        break;
    }
}

int func_80800774_chtiptup(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if ((*(s32 *)((char *)(param_0) + 0x2C)) != 2)
    {
      func_80800808_chtiptup(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

int func_808007CC_chtiptup(param_0) Actor *param_0;
{
    s32 *ptr = (s32 *)((char *)param_0 + 0x2C);
    if (*ptr != 0) {
        _capod_entrypoint_3(0, param_0);
        *ptr = 0;
    }
}

void func_80800808_chtiptup(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_0->actorData[5]) {
    case 0:
        _capod_entrypoint_2(param_0->unk0, 0x16, 0);
    case 1:
    case 3:
        _capod_entrypoint_8(1);
        param_0->actorData[5] = 2;
        _gcdialogcamera_entrypoint_3(D_80801398_chtiptup, param_0->scale);
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_5(param_0->rotation);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        break;
    }
}

int func_808008B4_chtiptup(param_0, param_1, param_2) Unk80132ED0 *param_0; s32 param_1; s32 param_2;
{
  Unk80132ED0 *local_0;
  s32 local_1;
  local_0 = param_0;
  local_1 = (*(s32 *)((char *)(param_0) + 0x2C));
  switch (local_1)
  {
    case 0 :
      _capod_entrypoint_2((*(s32 *)((char *)(param_0) + 0x0)), 0x16, param_2, param_0);
      
    case 2 :
    case 3 :
      (*(s32 *)((char *)(param_0) + 0x2C)) = 1;
      
    case 1 :
      _capod_entrypoint_6((*(s32 *)((char *)(local_0) + 0x0)), param_1, param_2, param_0);
      return;
  }
}

void func_80800934_chtiptup(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    s32 local_0;

    local_0 = *(s32*)((char*)param_0 + 0x2C);
    switch (local_0) {
    case 0:
        _capod_entrypoint_2(*(s32*)((char*)param_0 + 0), 0x16, param_2, param_0);
        
    case 1: ;
    case 2:
        *(s32*)((char*)param_0 + 0x2C) = 3;
        
    case 3:
        _capod_entrypoint_20(*(s32*)((char*)param_0 + 0), param_1, param_2, param_0);
        return;
    }
}

void func_80800E9C_chtiptup();

void func_808009B4_chtiptup(Actor *param_0)
{
    Actor *local_0;
    Actor *local_1;

    if (_subaddieskeleton_entrypoint_3(param_0->unk0, 4, (f32 *)param_0->actorData)) {
        _chbadshad_entrypoint_1(param_0, (f32 *)param_0->actorData, 0.8f);
    }
    switch (param_0->unk70_10) {
    case 1:
        return;
    case 2:
        func_80800E2C_chtiptup(param_0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
            func_8010A590(param_0);
            local_0 = func_80106790(param_0->unk3C);
            func_800F82D4(func_800F54E4(), 0);
            if (1) {}
            _subaddiedialog_entrypoint_11(local_0->unk0, 0xFF9, 0xC, local_0->position, 0x54);
        }
        break;
    case 3:
    case 7:
        if (func_80101E14(param_0, 0.2f)) {
            param_0->unk64_19 = (param_0->unk64_19 ^ 1) & 1;
            if (param_0->unk64_19) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80801620_chtiptup);
            }
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_8080162C_chtiptup, 0.4f);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 5);
            _subaddieDll_entrypoint_4(param_0, 1);
            func_800DA544(0xBE);
            local_1 = func_80106790(param_0->unk3C);
            func_80102424(local_1, 3);
            _subaddieaudioquick_entrypoint_2(local_1, local_1->position, &D_80801638_chtiptup);
            func_80800808_chtiptup(local_1, 3, 1);
            _subaddiedialog_entrypoint_11(local_1->unk0, 0xFFA, 0x46, local_1->position, 0x54);
            _subaddieDll_entrypoint_4(local_1, 1);
        }
        break;
    case 5:
        func_80800E9C_chtiptup(param_0);
        func_80105A9C(param_0, func_800F3780(func_80101F24(param_0), D_80801644_chtiptup, 3) * 200.0f);
        func_80105854(param_0);
        break;
    case 6:
        func_80800E2C_chtiptup(param_0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 7);
        }
        break;
    }
    if (func_800F52B8(func_800F54E4(), param_0->unk0) != 1) {
        func_800F4F34(func_800F54E4(), (f32 *)param_0->actorData, 0.0f, 30.0f);
    }
}

void func_80800C70_chtiptup(param_0) Actor *param_0;
{
    if (func_800DA298(0xBE) && !_glcutDll_entrypoint_20()) {
        func_800FFAB0(param_0);
    } else {
        param_0->unk6C_0 = _subaddiesect_entrypoint_1(param_0);
        _subaddiesect_entrypoint_2(param_0, param_0->unk6C_0, 0);
        if (_glcutDll_entrypoint_20()) {
            func_80102424(param_0, 6);
        } else if (func_800DA298(0xBD)) {
            func_80102424(param_0, 3);
            func_8010A590(param_0);
        } else {
            func_80102424(param_0, 1);
            func_80103110(param_0, 0);
            param_0->unk64_16 = 0;
        }
        func_80105BAC(param_0);
        ((TiptupFlags27 *)param_0)->local_1 = 1;
    }
}

s32 func_80800D78_chtiptup(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    switch (param_1) {
    case 0x40:
        func_800F8300(func_800F54E4(), 2, param_0->position);
        func_8010A570(param_0);
        func_80102424(param_0, 4);
        _subaddieDll_entrypoint_4(param_0, 1);
        func_800FC660(0xE);
        return 1;
    case 0x95:
        local_0 = _subaddiefind_entrypoint_2(0x358, 0);
        if (local_0) {
            param_0->unk3C = local_0->unk0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800E2C_chtiptup(s32 param_0)
{
  s32 local_0;
 local_0 = param_0 + 0x18; _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_8080165C_chtiptup, 0.02f);
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80801668_chtiptup, 0.14f);
  _subaddieaudioquick_entrypoint_4(param_0, local_0, &D_80801674_chtiptup, &D_8080167C_chtiptup);
}

void func_80800E9C_chtiptup(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    if (func_800D9154(&param_0->unk58, 2.2f))
        _subaddieaudioquick_entrypoint_2(param_0, param_0->actorData, D_808016A0_chtiptup);
    if (_subaddieaudioquick_entrypoint_3(param_0, param_0->actorData, D_80801690_chtiptup, 0.1f)) {
        func_800EFA4C(local_0, *(f32 *)param_0->actorData, param_0->position[1], *(f32 *)(param_0->actorData + 2));
        func_800EFA4C(local_1, *(f32 *)param_0->actorData, param_0->position[1], *(f32 *)(param_0->actorData + 2));
        func_800EFA4C(local_2, *(f32 *)param_0->actorData, param_0->position[1], *(f32 *)(param_0->actorData + 2));
        func_800EF1B8(local_0, param_0->rotation[1], 20.0f);
        func_800EF1B8(local_1, param_0->rotation[1] + 70.0f, 10.0f);
        func_800EF1B8(local_2, param_0->rotation[1] - 70.0f, 10.0f);
        local_0[1] -= 10.0f;
        func_80800614_chtiptup(local_1, local_0, 1, 0.5f, D_808016AC_chtiptup);
        func_80800614_chtiptup(local_2, local_0, 1, 0.5f, D_808016AC_chtiptup);
    }
}

void func_80800FE8_chtiptup(u8 *param_0) {
    s32 temp_v0;

    if (_subaddieskeleton_entrypoint_2(*(s32 *)((s8 *)param_0 + 0), 4, param_0 + 0x18) != 0) {
        _chbadshad_entrypoint_1(param_0, param_0 + 0x18, 1.0f);
    }
    switch ((u32)(*(u16 *)((s8 *)param_0 + 0x72)) >> 0xA) {
    case 1:
        temp_v0 = _plsu_entrypoint_3(*(s32 *)((s8 *)param_0 + 0));
        if (temp_v0 != -1) {
            func_800F7BC8(temp_v0, 0x53, *(s32 *)((s8 *)param_0 + 0));
            return;
        }
        return;
    case 2:
        if (func_80101DDC(param_0) != 0) {
            func_80102424(param_0, 3);
            func_800DA544(0xBD);
            return;
        }
        break;
    case 3:
        func_800F4F34(func_800F54E4(), param_0 + 0x18, 3e+01f, 8e+01f);
        break;
    }
}

void func_808010CC_chtiptup(Actor *param_0)
{
  u16 local_0;
  s32 local_1;
  local_0 = ((*((u16 *) (((char *) param_0) + 0x6E))) & 0xFE00) | ((u16) (_subaddiesect_entrypoint_1() & 0x1FF));
  *((u16 *) (((char *) param_0) + 0x6E)) = local_0;
  local_1 = (*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF;
  _subaddiesect_entrypoint_2(param_0, local_1, 0);
  if (_glcutDll_entrypoint_20() != 0)
  {
    func_80102424(param_0, 4);
    return;
  }
  if (func_800DA298(0xBD) != 0)
  {
    func_8010A570(param_0);
    func_80102424(param_0, 3);
    return;
  }
  func_8010A63C(param_0);
  func_80102424(param_0, 1);
}

s32 func_80801180_chtiptup(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    Actor *local_1;
    f32 local_2[3];
    f32 *local_4;
    Actor *local_3;
    switch (param_1) {
    case 0x18:
        local_4 = param_0->position;
        func_800EE7F8(local_2, local_4);
        func_800EF1B8(local_2, param_0->rotation[1] + 40.0f, 150.0f);
        func_800F77E8(func_800F54E4(), local_2);
        func_800F8300(func_800F54E4(), 2, local_4);
        func_80102424(param_0, 2);
        func_8010A570(param_0);
        local_0 = (Actor *)func_80106790(param_0->unk3C);
        local_1 = (Actor *)func_80106790(local_0->unk3C);
        func_8010A624(param_0);
        func_80102424(local_0, 2);
        func_80103110(local_0, 1);
        local_0->unk64_16 = 1;
        func_800DA544(0xBC);
        func_808008B4_chtiptup(local_1, 0xB, 0x820);
        break;
    case 0x95:
        local_3 = _subaddiefind_entrypoint_2(0x359, 0);
        if (local_3) param_0->unk3C = local_3->unk0;
        else param_0->unk3C = 0;
        break;
    case 0x40:
        local_3 = _subaddiefind_entrypoint_2(0x358, 0);
        if (local_3 && local_3->unk70_10 == 1) {
            _subaddiedialog_entrypoint_11(local_3->unk0, 0x1045, 0xE, local_3->position, 0x54);
            func_80102424(local_3, 2);
        }
        break;
    default: return 0;
    }
    return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/tiptup.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801360_chtiptup -> s32[], D_80801448_chtiptup -> int[], D_80801490_chtiptup -> int[], D_808014D8_chtiptup -> int[], D_80801570_chtiptup -> s32[], D_80801580_chtiptup -> s32[], D_808015B0_chtiptup -> s32[], D_808015C0_chtiptup -> s32[], D_808015CC_chtiptup -> s32[], D_808015DC_chtiptup -> s32[], D_808015EC_chtiptup -> s32[], D_80801600_chtiptup -> s32[], D_80801620_chtiptup -> s32[], D_8080162C_chtiptup -> s32[], D_80801638_chtiptup -> s32[], D_8080165C_chtiptup -> int[], D_80801668_chtiptup -> int[], D_80801674_chtiptup -> int[], D_8080167C_chtiptup -> int[] */
s32 D_80801360_chtiptup[14] = { 0x1, 0xFF60100, 0x1, -0xFE00, 0x200, 0x104D0100, 0x200, -0x1FE00, 0x400, 0x104E0100, 0x400, -0x2FE00, -0x12001, 0x120B0300 };
f32 D_80801398_chtiptup[4] = { 2.2e+02f, 2e+02f, 1.4e+02f, 8e+01f };
u32 D_808013A8_chtiptup[14] = { 0x0, 0x0, 0x40D66666, 0x18A0001, 0x40D66666, 0x18A0001, 0x40900000, 0x1890001, 0x3FA00000, 0x1880002, 0x3F800000, 0x1870101, 0x40900000, 0x1890001 };
u8 D_808013E0_chtiptup[64] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0xE5, 0xC2, 0x8F, 0x1, 0x84, 0x0, 0x44, 0x40, 0xE5, 0xC2, 0x8F, 0x1, 0x84, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x1, 0x85, 0x0, 0x1, 0x3F, 0x4C, 0xCC, 0xCD, 0x1, 0x86, 0x0, 0x2, 0x3F, 0x2B, 0x85, 0x1F, 0x1, 0x8B, 0x0, 0x1, 0x40, 0xE5, 0xC2, 0x8F, 0x1, 0x84, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x1, 0x85, 0x0, 0x1 };
u32 D_80801420_chtiptup[10] = { 0x0, 0x0, 0x40E5C28F, 0x1830044, 0x40E5C28F, 0x1830002, 0x40E5C28F, 0x1830084, 0x40E5C28F, 0x1830002 };
int D_80801448_chtiptup[18] = { 0x2B90358, 0x6C80001, (u32)&D_808013A8_chtiptup, (u32)func_80102EC0, (u32)func_80800024_chtiptup, (u32)func_80101870, 0x5DC0000, 0x3FCCCCCD, 0x0, 0x40100, (u32)func_808002C8_chtiptup, 0x0, 0x0, (u32)func_80800200_chtiptup, (u32)func_80107C2C, -0x79FFBBEE, (u32)func_808002F4_chtiptup, 0x0 };
int D_80801490_chtiptup[18] = { 0x2BA0359, 0x6C70001, (u32)&D_808013E0_chtiptup, (u32)func_80102EC0, (u32)func_808009B4_chtiptup, (u32)func_80101870, 0x5DC0000, 0x0, 0x0, 0x40140, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800C70_chtiptup, (u32)func_80107C2C, -0x7BFFFBEE, (u32)func_80800D78_chtiptup, 0x0 };
int D_808014D8_chtiptup[18] = { 0x2BB035A, 0x6C60001, (u32)&D_80801420_chtiptup, (u32)func_80800FE8_chtiptup, (u32)func_80800FE8_chtiptup, (u32)func_80101870, 0x5DC0000, 0x0, 0x0, 0x40068, 0x0, (u32)func_80108ED0, 0x0, (u32)func_808010CC_chtiptup, (u32)func_80107C2C, -0x7DFFDBF0, (u32)func_80801180_chtiptup, 0x0 };
u8 D_80801520_chtiptup[12] = { 0x0, 0x13, 0x4, 0x17, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080152C_chtiptup[32] = { 0x0, 0xB, 0x0, 0x14, 0x0, 0x14, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2D, 0x0, 0xC8, 0x0, 0xFA, 0x0, 0x1E, 0xFF, 0xFB, 0xFF, 0xFB, 0x0, 0x1B, 0x0, 0xC8, 0x1, 0x2C, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080154C_chtiptup[12] = { 0x0, 0x13, 0x4, 0x10, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801558_chtiptup[16] = { 0x0, 0x13, 0x6, 0x12, 0x0, 0xD, 0x1, 0x66, 0x1, 0x80, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0 };
u8 D_80801568_chtiptup[8] = { 0x0, 0x20, 0xE0, 0xE0, 0xE0, 0xC0, 0x0, 0x0 };
s32 D_80801570_chtiptup[4] = { 0xBC0000, 0x15E0054, 0xC, 0x6320200 };
s32 D_80801580_chtiptup[12] = { 0x1D09C9, 0x206046, 0x1EC80016, 0x80022, 0x660080, 0x9900CC, 0x150033, 0x99002B, 0x9900CC, 0xD0014, 0x2D0032, 0x640000 };
s32 D_808015B0_chtiptup[4] = { 0x130626, 0xD00C0, 0xD90016, 0x46500000 };
s32 D_808015C0_chtiptup[3] = { 0x1304D7, 0xD0166, 0x1800000 };
s32 D_808015CC_chtiptup[4] = { 0x130449, 0x162710, 0xD00F3, 0x10C0000 };
s32 D_808015DC_chtiptup[4] = { 0x3D75C28F, 0x3DCCCCCD, 0x3E0F5C29, -0x40800000 };
s32 D_808015EC_chtiptup[5] = { 0x3060013, 0x62F000D, 0xF3010C, 0x180011, 0x0 };
s32 D_80801600_chtiptup[8] = { 0x3D75C28F, 0x3E051EB8, 0x3E570A3D, 0x3E99999A, 0x3ECCCCCD, 0x3EF5C28F, 0x3F0F5C29, -0x40800000 };
s32 D_80801620_chtiptup[3] = { 0x130532, 0xD0173, 0x18C0000 };
s32 D_8080162C_chtiptup[3] = { 0x13043A, 0xA017D, 0x20000 };
s32 D_80801638_chtiptup[3] = { 0x13061F, 0xA00E6, 0x0 };
s32 D_80801644_chtiptup[6] = { 0x0, 0x0, 0x3E4CCCCD, 0x3F800000, 0x3EE66666, 0x0 };
int D_8080165C_chtiptup[3] = { 0x13041D, 0xA0133, 0x20000 };
int D_80801668_chtiptup[3] = { 0x130561, 0x180002, 0x0 };
int D_80801674_chtiptup[2] = { 0x13044A, 0x20000 };
int D_8080167C_chtiptup[5] = { 0x3EF5C28F, 0x3F000000, 0x3F59999A, 0x3F6147AE, -0x40800000 };
u8 D_80801690_chtiptup[16] = { 0x0, 0x13, 0x4, 0x1B, 0x0, 0xD, 0x0, 0xB3, 0x0, 0xCC, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x0 };
u8 D_808016A0_chtiptup[12] = { 0x0, 0x13, 0x6, 0x3B, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_808016AC_chtiptup[20] = { 0x0, 0xC, 0x0, 0x0, 0x0, 0x2D, 0x0, 0x64, 0x0, 0x96, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
