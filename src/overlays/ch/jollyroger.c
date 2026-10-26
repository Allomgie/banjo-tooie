#include "common.h"

#define F94 ((ActorFlags94 *)((u8 *)this + 0x94))
extern int D_80801358_chjollyroger[];
extern void *D_808013A0_chjollyroger;
extern void *D_808013E8_chjollyroger;
extern void _suexpression_entrypoint_17(void *, s32);
extern void *_suexpression_entrypoint_7(Actor *, u32, u32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern u8 D_80801430_chjollyroger[];
extern u8 D_8080143C_chjollyroger[];
extern void _subaddieaudioquick_entrypoint_4(s32, s32, void *, void *);
extern u8 D_80801448_chjollyroger[];
extern u8 D_80801456_chjollyroger;
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, void *, s32, s32);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32, s32);
extern s32 D_80801200_chjollyroger[];
extern s32 D_80801238_chjollyroger[];
extern void *func_80100094(Actor *, u32);
extern s32 D_80801270_chjollyroger[];
extern s32 D_80801458_chjollyroger[];
extern void func_8010D5DC();
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_8008F990(f32 *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void func_800F8300(u32, s32, f32 *);
extern u8 unk28[];
extern u8 D_808012A8_chjollyroger[];
extern u8 D_808012B8_chjollyroger[];
extern Actor *_subaddiefind_entrypoint_2(s32, void *);
extern void _chexploder_entrypoint_3(Actor *, f32 *, s32);
typedef struct { u32 pad94_31 : 1; u32 unk94_30 : 1; u32 pad94_0 : 30; } ActorFlags94;
extern void *_suexpression_entrypoint_20(Actor *);
extern s32 func_800DA298(s32);
extern s32 _glcutDll_entrypoint_20(void);
extern void func_800D1824(s32);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern s32 func_801022E4(Actor *);
extern void _suexpression_entrypoint_18(void *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 _chbadshad_entrypoint_2(Actor *, s32, f32, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800DC298(f32);
extern void func_80102424(Actor *, s32);
extern s32 func_80101DDC(Actor *);
extern void func_80103DFC(Actor *, f32 *);
extern s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
void func_80800624_chjollyroger();
int func_80800CC4_chjollyroger();
int func_80800D28_chjollyroger();
int func_80800DD8_chjollyroger();
int func_80800E30_chjollyroger();
void func_80800E6C_chjollyroger();
int func_80800F3C_chjollyroger();
void func_80800FBC_chjollyroger();
s32 func_80801194_chjollyroger();

int chjollyroger_entrypoint_0()
{
    return (int)&D_80801358_chjollyroger;
}

int chjollyroger_entrypoint_1()
{
    return (int)&D_808013A0_chjollyroger;
}

int chjollyroger_entrypoint_2(void)
{
    return (int)&D_808013E8_chjollyroger;
}

s32 func_8080059C_chjollyroger();

void func_8080056C_chjollyroger();

void func_80800024_chjollyroger(Actor *this)
{
    void *expr;
    f32 item[3];

    expr = _suexpression_entrypoint_20(this);
    if (!func_800DA298(0) && !_glcutDll_entrypoint_20()) {
        func_800D1824(0x4E);
    }
    _suexpression_entrypoint_10(expr, this->unk0, 0);
    if (func_801022E4(this) == 0x155) {
        _suexpression_entrypoint_18(expr, 1);
    }
    func_800EE7F8((f32 *)this->actorData, this->position);
    if (this->unk7C_12 && _chbadshad_entrypoint_2(this, 3, 1.5, (f32 *)this->actorData)) {
        _sudeflect_entrypoint_1((f32 *)this->actorData, 250.0f, 0.0f, 80.0f, 10);
    }
    switch (this->unk70_10) {
    case 1:
        func_8080059C_chjollyroger(this, &D_80801200_chjollyroger, 7, 2);
        break;
    case 2:
    case 5:
        break;
    case 3:
        if (!func_8080059C_chjollyroger(this, &D_80801238_chjollyroger, 7, 5) && func_80101E14(this, 0.999f)) {
            if (this->unk64_19) {
                this->unk64_19 = 0;
            } else if (func_800DA298(0xC3) && func_800DC298(0.35f)) {
                func_80102424(this, 4);
                this->unk64_19 = 1;
            }
        }
        break;
    case 4:
        if (func_80101DDC(this)) {
            func_80102424(this, 3);
        } else {
            func_8080059C_chjollyroger(this, &D_80801238_chjollyroger, 7, 6);
        }
        func_8080056C_chjollyroger(this);
        break;
    case 6:
        if (func_80101E14(this, 0.999f)) {
            func_80102424(this, 5);
        }
        break;
    case 7:
    case 8:
        func_80103DFC(this, item);
        if (_subaddieitem_entrypoint_3(this, item, func_80100094(this, 0))) {
            _subaddiedialog_entrypoint_11(this->unk0, 0x1004, 0xE, this->position, 0x55);
            func_80102424(this, func_800DA298(0xC0) ? 5 : 2);
        }
        break;
    case 9:
        func_8080056C_chjollyroger(this);
        break;
    }
    if (func_801022E4(this) == 0x155) {
        F94->unk94_30 = 0;
    } else {
        F94->unk94_30 = 1;
    }
}

int func_808002E8_chjollyroger(Actor *param_0)
{
  if (_glcutDll_entrypoint_20())
  {
    func_80102424(param_0, 9);
  }
  else
  {
    if (func_800DA298(0xC0))
    {
      func_80102424(param_0, 4);
    }
  }
  _subaddieitem_entrypoint_0(func_80100094(param_0, 0), 0x4E4, -1, 3);
  _subaddieitem_entrypoint_1(func_80100094(param_0, 0), 2);
}

s32 func_80800370_chjollyroger(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    void *local_1;

    switch (param_1) {
    case 0xB:
        switch (param_2) {
        case 1:
            func_800F7F98(func_800F54E4(), 0);
            if (!func_800DA298(0xC2) && !func_800DA298(0x41)) {
                func_80800E6C_chjollyroger(param_0, 3, 1);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1002, 0x4E, param_0->position, 0x55);
                return 4;
            }
            func_80800E30_chjollyroger(param_0);
            func_80102424(param_0, 3);
            return 4;
        case 3:
            local_0 = func_800DA298(0xC0) ? 0x1043 : 0x1042;
            _subaddiedialog_entrypoint_11(param_0->unk0, local_0, 0xE, param_0->position, 0x55);
        default:
            return 3;
        }
    case 0x2E:
        func_80800624_chjollyroger(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_3(((s32 *) D_808012A8_chjollyroger), param_0->scale);
        return 1;
    case 0x57:
        return func_80800DD8_chjollyroger(param_0, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x95:
        local_1 = _suexpression_entrypoint_7(param_0, 1, 0x55);
        _suexpression_entrypoint_12(local_1, 60.0f, 20.0f);
        _suexpression_entrypoint_17(local_1, 1000);
        return 1;
    case 0x6E:
        param_0->unk64_16 = !param_2;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080056C_chjollyroger(s32 param_0) {
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 0x18, D_80801430_chjollyroger, D_8080143C_chjollyroger);
}

s32 func_8080059C_chjollyroger(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_0;

    D_80801456_chjollyroger = param_3;
    local_0 = _subaddiedialog_entrypoint_8(param_0, param_0->position, D_80801448_chjollyroger, param_1, param_2);
    if (!local_0) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9(param_0, local_0, param_1, param_2) != 3) {
        func_80800E6C_chjollyroger(param_0, 3, 0);
    }
    return 1;
}

void func_80800624_chjollyroger(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    s32 local_1;

    switch (param_1) {
        case 0x1002:
            if (param_2 > 0) {
                if (func_800D1A04(0x4E) < 2) {
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x1005, 14, param_0->position, 0x55);
                    return;
                }
                if (func_800F64A4(func_800F54E4(), 0x201)) {
                    func_80800FBC_chjollyroger(param_0, 13, 0);
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x1041, 14, param_0->position, 0x55);
                    return;
                }
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1225, 14, param_0->position, 0x55);
                return;
            }
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1003, 14, param_0->position, 0x55);
            return;
        case 0x1041:
            _subaddieitem_entrypoint_2(func_80100094(param_0, 0));
            local_0 = func_800DA298(0xC0) ? 8 : 7;
            func_80102424(param_0, local_0);
            return;
        case 0x1004:
            func_80101180(0x36A, 7, 0);
            func_80800F3C_chjollyroger(param_0, 3, 16);
            return;
        default:
            if (func_800DA298(0xC0)) {
                local_1 = _subaddiedialog_entrypoint_9(param_0, param_1, (s32)&D_80801238_chjollyroger, 7);
                switch (local_1) {
                    case 1:
                        if (!func_800D0A9C(0x24, 1)) {
                            func_800F7F98(func_800F54E4(), 1);
                            func_80800F3C_chjollyroger(param_0, 1, 32);
                            func_800D1000(0x24, 1, 0, 1, 0);
                            return;
                        }
                    case 2:
                        if (!func_800DA298(0xC2) && !func_800DA298(0x41)) {
                            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1002, 0x4E, param_0->position, 0x55);
                            return;
                        }
                        func_800C01A8(100, 0);
                        func_800C0850();
                    default:
                        func_80800E30_chjollyroger(param_0);
                        func_80102424(param_0, 3);
                        return;
                }
            } else {
                local_1 = _subaddiedialog_entrypoint_9(param_0, param_1, (s32)&D_80801200_chjollyroger, 7);
                if (local_1 == 1 || local_1 == 2) {
                    if (!func_800DA298(0xC2) && !func_800DA298(0x41)) {
                        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1002, 0x4E, param_0->position, 0x55);
                        return;
                    }
                    func_800C01A8(100, 0);
                    func_800C0850();
                }
                func_80800E30_chjollyroger(param_0);
                func_80102424(param_0, 1);
                return;
            }
    }
}

void func_80800930_chjollyroger(Actor *this)
{
    f32 vec[3];

    _sudeflect_entrypoint_1(this->position, 230.0f, 0.0f, 100.0f, 10);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(this), this->unk0, 0);
    switch (this->unk70_10) {
    case 1:
        if (func_800F64A4(func_800F54E4(), 0x201) && func_8010CA74(this->position, 0x4B0)) {
            func_80102424(this, 2);
            func_80800F3C_chjollyroger(this, 1, 0x220);
            func_800EE7F8(vec, this->position);
            func_800EF1B8(vec, this->rotation[1] + 20.0f, 250.0f);
            func_8008F8B0();
            func_8008F8D8(1);
            func_8008F904(func_8010D5DC, this->unk0);
            func_8008F990(vec, 250.0f);
        }
        break;
    case 2:
        if (this->unk64_20) {
            func_80800CC4_chjollyroger(this);
        }
        break;
    case 4:
        func_80105230(this, 0);
        func_80105854(this);
        if (func_80105A5C(this)) {
            func_800DA544(0xC0);
            func_800DA524(0xC3);
            func_80800E30_chjollyroger(this);
        }
        break;
    case 5:
        _subaddiedialog_entrypoint_8(this, this->position, &D_80801458_chjollyroger, &D_80801270_chjollyroger, 7);
        break;
    }
}

void func_80800AEC_chjollyroger(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800DA298(0xC0) || _glcutDll_entrypoint_20();
    switch (func_800EA05C()) {
    case 0xED:
        if (!local_0) {
            func_800FFAB0(param_0);
        } else {
            func_80102424(param_0, _glcutDll_entrypoint_20() ? 7 : 5);
        }
        break;
    case 0xF8:
        if (local_0) {
            func_800FFAB0(param_0);
        }
        break;
    }
}

s32 func_80800BA0_chjollyroger(Actor *param_0, s32 param_1, s32 param_2)
{
    void *local_0;

    switch (param_1) {
    case 0x2E:
        func_80800D28_chjollyroger(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x32:
        param_0->unk64_20 = 1;
        func_800F8300(func_800F54E4(), 1, param_0->position);
        break;
    case 0x57:
        return func_80800DD8_chjollyroger(param_0, param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
    case 0x52:
        _gcdialogcamera_entrypoint_3(((s32 *) D_808012B8_chjollyroger), param_0->scale);
        break;
    case 0x95:
        local_0 = _suexpression_entrypoint_7(param_0, 1, 0x56);
        _suexpression_entrypoint_12(local_0, 60.0f, 20.0f);
        _suexpression_entrypoint_17(local_0, 1000);
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800CC4_chjollyroger(param_0) s32 param_0[3];
{
  s32 local_0;
  local_0 = func_800F54E4();
  if (func_800F64A4(local_0 | 0, 0x200))
  {
    local_0 = 0x1054;
  }
  else
  {
    local_0 = 0xFFB;
  }
  _subaddiedialog_entrypoint_11(param_0[0], local_0, 6, param_0 + 1, 0x56);
  func_80102424(param_0, 3);
}

int func_80800D28_chjollyroger(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  if ((param_1 == 0xFFB) || (param_1 == 0x1054))
  {
    func_80102424(param_0, 4);
    func_80105A9C(param_0, 0x43AF0000);
    func_80105BAC(param_0);
    func_800F82D4(func_800F54E4(), 0);
    func_80800F3C_chjollyroger(param_0, 4, 0x30);
    return;
  }
  func_80102424(param_0, 5);
}

void func_80800DB8_chjollyroger(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
int func_80800DD8_chjollyroger(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if ((*(s32 *)((char *)(param_0) + 0x28)) != 2)
    {
      func_80800E6C_chjollyroger(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

int func_80800E30_chjollyroger(param_0) Actor *param_0;
{
    s32 *ptr = (s32 *)((char *)param_0 + 0x28);
    if (*ptr)
    {
        _capod_entrypoint_3(0, param_0);
        *ptr = 0;
    }
}

void func_80800E6C_chjollyroger(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    void *local_0;

    switch (param_0->actorData[4]) {
    case 0:
        _capod_entrypoint_2(param_0->unk0, 0x10, 0);
    case 1:
    case 3:
        _capod_entrypoint_8(1);
        param_0->actorData[4] = 2;
        _gcdialogcamera_entrypoint_3(param_0->unk6C_9 == 0x360 ? D_808012A8_chjollyroger : D_808012B8_chjollyroger, param_0->scale);
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_5(param_0->rotation);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        break;
    }
}

int func_80800F3C_chjollyroger(param_0, param_1, param_2) s32 param_0[2]; s32 param_1; s32 param_2;
{
  switch (param_0[10])
  {
    case 0:
      _capod_entrypoint_2(param_0[0], 0x10, param_2, param_0);
      
    case 2:
    case 3:
      param_0[10] = 1;
      
    case 1:
      _capod_entrypoint_6(param_0[0], param_1, param_2, param_0);
      return;
  }
}

void func_80800FBC_chjollyroger(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    s32 local_0;

    local_0 = *(s32*)((char*)param_0 + 0x28);
    switch (local_0) {
    case 0:
        _capod_entrypoint_2(*(s32*)((char*)param_0 + 0), 0x10, param_2, param_0);
        
    case 1: ;
    case 2:
        *(s32*)((char*)param_0 + 0x28) = 1;
        
    case 3:
        _capod_entrypoint_20(*(s32*)((char*)param_0 + 0), param_1, param_2, param_0);
        return;
    }
}

s32 func_8080103C_chjollyroger(s32 param_0) {
    if (_chdoormake_entrypoint_0(param_0, 0xC2F00000, 0x8000, 0xC2)) {
        _chdoormake_entrypoint_8(param_0, 1);
        _chdoormake_entrypoint_5(param_0, 0x40600000);
    }
    func_8010A800(param_0, 0);
    func_8010A63C(param_0);
}

s32 func_808010A0_chjollyroger(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    Actor *local_1;

    switch (param_1) {
        case 0x90:
            func_80801194_chjollyroger(param_0);
            break;
        case 0x40:
            local_1 = _subaddiefind_entrypoint_2(0x360, NULL);
            func_800EE7F8(local_0, param_0->position);
            func_800EF1B8(local_0, param_0->rotation[1] - 90.0f, 100.0f);
            local_0[1] += 25.0f;
            _chexploder_entrypoint_3(param_0, local_0, 40);
            _subaddiedialog_entrypoint_11(local_1->unk0, 0x1044, 0x4C, local_1->position, 0x55);
            func_80102424(local_1, 2);
            break;
        default:
            return _chdoor_entrypoint_1(param_0, param_1, param_2);
    }
    return 1;
}

s32 func_80801194_chjollyroger(param_0) s32 param_0; {
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800DA544(0x41);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/jollyroger.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * D_80801456_chjollyroger is a label inside D_80801448_chjollyroger, defined in undefined_syms.us.txt.
 * extern views adjusted to the object (address-neutral): D_80801200_chjollyroger -> s32[], D_80801238_chjollyroger -> s32[], D_80801270_chjollyroger -> s32[], D_80801358_chjollyroger -> int[], D_80801458_chjollyroger -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void func_80108ED0();
extern void _bsbtrot_entrypoint_8();
s32 D_80801200_chjollyroger[14] = { 0x1, 0xFFE0100, 0x1, 0xFFF0200, 0x200, 0x10500100, 0x200, 0xFFF0200, 0x400, 0x10510100, 0x400, 0xFFF0200, -0x12001, 0x12100300 };
s32 D_80801238_chjollyroger[14] = { 0x1, 0x10000100, 0x1, 0x10010200, 0x200, 0x10520100, 0x200, 0x10010200, 0x400, 0x10530100, 0x400, 0x10010200, -0x12001, 0x12100300 };
s32 D_80801270_chjollyroger[14] = { 0x1, 0xFFC0100, 0x1, 0xFFD0200, 0x200, 0xFFC0100, 0x200, 0x10560200, 0x400, 0x10550100, 0x400, 0xFFD0200, -0x12001, 0x12100300 };
u8 D_808012A8_chjollyroger[16] = { 0x43, 0x9D, 0x80, 0x0, 0x42, 0xF0, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0, 0x43, 0x20, 0x0, 0x0 };
u8 D_808012B8_chjollyroger[16] = { 0x43, 0x34, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0, 0x43, 0x16, 0x0, 0x0 };
u32 D_808012C8_chjollyroger[20] = { 0x0, 0x0, 0x41180000, 0x1540001, 0x411E6666, 0x1540001, 0x40733333, 0x3E40001, 0x40E33333, 0x1550002, 0x40733333, 0x3E40001, 0x40E33333, 0x1550001, 0x411E6666, 0x1540001, 0x40733333, 0x3E40001, 0x40E33333, 0x1550001 };
u32 D_80801318_chjollyroger[16] = { 0x0, 0x0, 0x41100000, 0x1560001, 0x41100000, 0x1560001, 0x41100000, 0x1560001, 0x3F4CCCCD, 0x1570001, 0x41100000, 0x1560001, 0x41100000, 0x1560001, 0x41100000, 0x1560001 };
int D_80801358_chjollyroger[18] = { 0x2F30360, 0x6D60001, (u32)&D_808012C8_chjollyroger, (u32)func_80800024_chjollyroger, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x520, (u32)func_80800DB8_chjollyroger, 0x0, 0x140000, (u32)func_808002E8_chjollyroger, (u32)func_80107C2C, -0x7DFFDAFE, (u32)func_80800370_chjollyroger, 0x0 };
void *D_808013A0_chjollyroger = (void *)0x02F40361;
static u32 D_808013A0_chjollyroger_rest[17] = { 0x6D80001, (u32)&D_80801318_chjollyroger, (u32)func_80800930_chjollyroger, (u32)func_80800930_chjollyroger, (u32)func_80101870, 0x0, 0x3FC00000, 0x0, 0x40120, (u32)func_80800DB8_chjollyroger, 0x0, 0x0, (u32)func_80800AEC_chjollyroger, (u32)func_80107C2C, 0x80000502, (u32)func_80800BA0_chjollyroger, 0x0 };
void *D_808013E8_chjollyroger = (void *)0x019C036A;
static u32 D_808013E8_chjollyroger_rest[17] = { 0x7630001, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x410000, 0x0, 0x0, (u32)func_80108ED0, 0x0, (u32)func_8080103C_chjollyroger, (u32)func_80107C2C, (u32)_bsbtrot_entrypoint_8, (u32)func_808010A0_chjollyroger, 0x0 };
u8 D_80801430_chjollyroger[12] = { 0x0, 0x13, 0x4, 0x51, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_8080143C_chjollyroger[12] = { 0x3D, 0xE1, 0x47, 0xAE, 0x3F, 0x73, 0x33, 0x33, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80801448_chjollyroger[16] = { 0x0, 0xC3, 0x0, 0x0, 0x1, 0xF4, 0x0, 0x55, 0x0, 0x0, 0x0, 0xE, 0x6, 0x3C, 0x0, 0x0 };
s32 D_80801458_chjollyroger[22] = { 0xC40000, 0x2440056, 0xE, 0x63C0600, 0x310001D, 0x9DD002B, 0x8000A00, 0x220200, 0x2800600, 0x8000015, 0x26, 0x190000, 0x7002D, 0x320050, 0x20DEA7, 0x71C0000A, -0x31FFE7, -0x31FFCE, 0x280032, 0x31A0000, 0x0, 0x0 };
