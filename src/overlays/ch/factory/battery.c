#include "common.h"

extern int D_80801B34_chfactorybattery;
extern s32 _gccubesearch_entrypoint_12(f32 *, s32, f32 *, Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80102FDC(Actor *, f32);
typedef struct { u32 pad : 7; u32 flag : 1; u32 pad2 : 24; } BitTest7;
extern void* _subaddietaxi_entrypoint_16;
typedef struct Mass44BatteryFlags { u8 pad_0[0x78]; u32 pad_1:26; u32 local_0:1; u32 pad_2:5; } Mass44BatteryFlags;
extern void func_8010A3E8(Actor *, f32);
extern void _chfactorybattery_entrypoint_0();
typedef union { s32 local_0; void *local_1; } FactoryBatteryEvent60;
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct { u8 pad_0[0x50]; s32 local_0; } BatteryParticleHolder;
extern f32 func_80103EAC(Actor *);
extern s32 func_800C8A98(void);
extern int D_80801BA8_chfactorybattery;
extern void _chdoormake_entrypoint_9();
extern s32 _chdoormake_entrypoint_1(Actor *, f32, s32, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef union { s32 word; void *pointer; } FactoryBatteryEvent;
extern int D_80801BF0_chfactorybattery;
extern Vec3f D_80801B3C_chfactorybattery;
extern Vec3f D_80801B48_chfactorybattery;
extern Vec3f D_80801B54_chfactorybattery;
extern f32 func_800DC178(f32, f32);
extern void func_800F3214(f32 *, f32 *, f32 *, f32);
extern u8 D_80801B78_chfactorybattery[];
extern u8 D_80801B60_chfactorybattery[];
extern f32 func_80103EF4(Actor *);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
typedef struct { u8 pad0[0x70]; u32 unk70_25:7; u32 pad70_16:9; u32 pad70_10:6; u32 unk70_4:6; u32 pad70_0:4; } BatteryKeys;
typedef struct { u8 pad0[6]; u16 unk6; } BatteryRoute;
extern f32 D_80801B88_chfactorybattery[];
extern void *func_80100094(Actor *, s32);
extern void _subaddiefx_entrypoint_0(Actor *, s32, void *);
extern s32 func_800D90A4(f32 *);
extern s32 _subaddietaxi_entrypoint_1(Actor *, s32);
extern s32 _subaddietaxi_entrypoint_11(Actor *, s32);
extern s32 _subaddietaxi_entrypoint_5(Actor *, s32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, f32 *, s32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 func_8010C500(Actor *);
extern f32 *func_800CC63C(s32, s32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F54E4(void);
extern f32 func_8010CD50(Actor *, s32);
extern void _subaddierouteDll_entrypoint_6(Actor *, BatteryRoute *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, BatteryRoute *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, BatteryRoute *, s32, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern s32 func_800DC128(s32, s32);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern s32 func_80102CCC(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_8010BA80(Actor *, s32, s32);
extern s32 func_8010C9FC(f32 *, s32, s32, s32);
extern void func_8010108C(Actor *, s32, s32);
extern void _subaddietaxi_entrypoint_9(Actor *, s32);
extern f32 func_8010A40C(Actor *);
int func_80800444_chfactorybattery();
int func_80800480_chfactorybattery();
int func_808004E8_chfactorybattery();
int func_80800558_chfactorybattery();
f32 func_80800580_chfactorybattery();
int func_80800678_chfactorybattery();
void func_808006E4_chfactorybattery();
s32 func_80801040_chfactorybattery();
void func_8080130C_chfactorybattery();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0();
extern u8 D_80801AB0_chfactorybattery[], D_80801AC4_chfactorybattery[], boot_thread_stack[];

int *chfactorybattery_entrypoint_0()
{
    return &D_80801B34_chfactorybattery;
}

s32 func_8080000C_chfactorybattery(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    local_1 = _gccubesearch_entrypoint_12(local_0, 0x28C, param_0->position, param_0);
    func_800EE7F8(param_0->position, local_0);
    return local_1;
}

void func_80800050_chfactorybattery(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    switch (func_800CB3E0(param_1)) {
    case 6: break;
    case 1:
        param_0->unk6C_0 = param_1;
        func_80102FDC(param_0, 0.45f);
        func_8080130C_chfactorybattery(param_0, 6);
        ((BitTest7 *)((u8 *)param_0 + 0x64))->flag = 1;
        break;
    case 3:
        param_0->unk6C_0 = param_1;
        func_80102FDC(param_0, 0.45f);
        _subaddietaxi_entrypoint_10(param_0, param_1, 4);
        break;
    case 4:
        param_0->rotation[1] = func_80800580_chfactorybattery(local_0);
        param_0->unk6C_0 = param_1;
        func_80102FDC(param_0, 0.45f);
        _subaddietaxi_entrypoint_0(param_0, param_1, local_0, 3);
        break;
    }
    if (param_0 && !(*(u32 *)((u8 *)param_0 + 0x6C) >> 21)) param_0->unk6C_0 = param_1;
}

void func_8080019C_chfactorybattery(volatile unsigned long param_0, u8 *param_1, s32 param_2, s32 param_3)
{
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0, *((s32 *) (((u8 *) param_1) + 0)), *((s32 *) (((u8 *) param_1) + 4)), *((s32 *) (((u8 *) param_1) + 8)), param_2, param_3);
}

int func_808001F8_chfactorybattery(Actor *param_0)
{
    func_80102FDC(param_0, 0.45f);
    func_8010A3E8(param_0, 0.6f);
    if (((Mass44BatteryFlags *)param_0)->local_0) {
        if (func_80800678_chfactorybattery(param_0)) {
            if (!func_80800558_chfactorybattery(param_0)) {
                if (_subaddietaxi_entrypoint_13(param_0, func_80800678_chfactorybattery(param_0), _chfactorybattery_entrypoint_0, 3)) param_0->unk64_24 = 1;
                else { func_800FFAB0(param_0); return 0; }
            } else { func_800FFAB0(param_0); return 0; }
        } else {
            *((u8 *)param_0 + 0x64) &= 0xFFFE;
            *((u8 *)param_0 + 0x64) &= 0xE7;
            if (func_80800444_chfactorybattery()) func_8080130C_chfactorybattery(param_0, 13);
            else { func_800FFAB0(param_0); return 0; }
        }
    } else {
        if (func_80800678_chfactorybattery(param_0)) {
            if (func_80800558_chfactorybattery(param_0)) { func_800FFAB0(param_0); return 0; }
        } else { func_800FFAB0(param_0); return 0; }
    }
    func_808006E4_chfactorybattery(param_0);
    func_8080130C_chfactorybattery(param_0, param_0->unk70_10);
    if (param_0->unk70_10 != 3 && param_0->unk70_10 != 4 && param_0->unk70_10 != 5 && param_0->unk70_10 != 13) {
        if ((*(u32 *)((u8 *)param_0 + 0x70) >> 25) == 0 || ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) == 0) {
            func_8080000C_chfactorybattery(param_0);
            _subaddieDll_entrypoint_1(param_0);
        }
        _subaddierouteDll_entrypoint_1(param_0);
    }
    return 1;
}

s32 func_808003C0_chfactorybattery(FactoryBatteryEvent60 param_0, f32 *param_1, f32 *param_2)
{
    if (!func_80800444_chfactorybattery()) {
        if (func_808004E8_chfactorybattery()) {
            func_80800580_chfactorybattery(param_2);
            if (func_800EEAD4(param_2, param_1) < 1000.0f) {
                return 2;
            }
            return 1;
        }
    }
    return 1;
}

int func_80800444_chfactorybattery()
{
  s32 local_0;
  local_0 = func_80800480_chfactorybattery();
  if (local_0 != 0)
  {
    return func_800DA298(local_0 | 0);
  }
  return 0;
}

int func_80800480_chfactorybattery()
{
  switch (func_800EA05C())
  {
    case 0x101 :
      return 0x1B0;

    case 0x106 :
      return 0x1B1;

    case 0x109 :
      return 0x1B2;

    case 0x10B :
      return 0x1B3;

    default :
      return 0;

  }

}

int func_808004E8_chfactorybattery(void)
{
    return func_800EA05C() == 0x101 ||
        func_800EA05C() == 0x106 ||
        func_800EA05C() == 0x109 ||
        func_800EA05C() == 0x10B;
}

int func_80800558_chfactorybattery()
{
  s32 local_0;
  local_0 = func_80800678_chfactorybattery();
  func_800DA298(local_0 + 0x1B1);
}

f32 func_80800580_chfactorybattery(param_0) s32 param_0; {
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    switch (temp_v0) {
    case 0x101:
        func_800EFA4C(param_0, 0x451D9000, 0x443B8000, 0xC51E1000);
        return 310.0f;
    case 0x106:
        func_800EFA4C(param_0, 0x45C4F800, 0x44C1C000, 0xC4768000);
        return 180.0f;
    case 0x109:
        func_800EFA4C(param_0, 0xC3928000, 0x42480000, 0x4524A000);
        return 180.0f;
    case 0x10B:
        func_800EFA4C(param_0, 0x4565E000, 0x43AF0000, 0xC4F94000);
        return 90.0f;
    default:
        return 0.0f;
    }
}

int func_80800678_chfactorybattery(param_0) Actor *param_0;
{
    u32 temp_v1;
    u32 temp_v0;

    temp_v1 = (*(u32 *)((char *)(param_0) + 0x6C));
    temp_v0 = temp_v1 >> 21;
    switch (temp_v0) {
        case 0x51:
            return 3;
        case 0x5C:
            return 4;
        case 0x63:
            return 5;
        case 0x65:
            return 6;
        case 0:
            return temp_v1 & 0x1FF;
        default:
            return 0;
    }
}

void func_808006E4_chfactorybattery(param_0) Actor *param_0;
{
    f32 local_0[2];
    f32 local_1;

    local_1 = func_80103EAC(param_0);
    local_0[0] = local_1 + local_1;
    local_0[1] = func_80103EAC(param_0) * 4.0f;
    ((BatteryParticleHolder *)param_0)->local_0 = func_800C8A98();
    if (((BatteryParticleHolder *)param_0)->local_0) {
        func_800C8F64(((BatteryParticleHolder *)param_0)->local_0, 3);
        func_800C8D4C(((BatteryParticleHolder *)param_0)->local_0, local_0);
        func_800C8FE0(((BatteryParticleHolder *)param_0)->local_0, 0);
    }
}

void func_80800760_chfactorybattery(Actor *param_0)
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    Vec3f local_3;
    Vec3f local_4;

    if (_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_0.f) &&
        *(s32 *)((u8 *)param_0 + 0x50)) {
        if (param_0->unk70_10 == 1 || param_0->unk70_10 == 9) {
            local_1 = D_80801B3C_chfactorybattery;
            func_800C8CB8(*(s32 *)((u8 *)param_0 + 0x50), local_0.f);
            func_800C8E84(*(s32 *)((u8 *)param_0 + 0x50), local_1.f);
            func_800C8FE0(*(s32 *)((u8 *)param_0 + 0x50), 1);
            return;
        }
        if (param_0->unk79_4) {
            local_3 = D_80801B48_chfactorybattery;
            local_4 = D_80801B54_chfactorybattery;
            func_800F3214(local_2.f, local_3.f, local_4.f, func_800DC178(0.7f, 1.0f));
            func_800C8CB8(*(s32 *)((u8 *)param_0 + 0x50), local_0.f);
            func_800C8E84(*(s32 *)((u8 *)param_0 + 0x50), local_2.f);
            func_800C8FE0(*(s32 *)((u8 *)param_0 + 0x50), 1);
            return;
        }
        func_800C8FE0(*(s32 *)((u8 *)param_0 + 0x50), 0);
    }
}

void func_808008C8_chfactorybattery(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 9:
        param_0->unk79_4 = 0;
        break;
    case 5:
    case 7:
    case 10:
    case 13:
        param_0->unk79_4 = func_800DC128(1, 4);
        break;
    }
}

void func_80800948_chfactorybattery(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
        break;
    case 6:
    case 8:
    case 10:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801B60_chfactorybattery, 0x3F000000);
        break;
    }
    if (param_0->unk79_4) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801B78_chfactorybattery);
    }
}

void func_808009C8_chfactorybattery(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
        case 4:
        case 5:
        case 9:
        case 13:
            func_800F4EC8(func_800F54E4(), param_0->position, func_80103EF4(param_0), 0.0f, func_80103EAC(param_0) * 0.25f);
            break;
        case 8:
        case 10:
            if (param_0->unk79_4 == 0) {
                func_800F4EC8(func_800F54E4(), param_0->position, func_80103EF4(param_0), 0.0f, func_80103EAC(param_0) * 0.25f);
            }
            break;
    }
}

void func_80800AB8_chfactorybattery(Actor *param_0)
{
    f32 local_0;
    BatteryRoute *local_1;
    f32 local_x;
    f32 local_2;
    f32 local_3;

    switch (param_0->unk70_10) {
    case 1:
        _subaddiefx_entrypoint_0(param_0, 4, func_80100094(param_0, 0));
        if (func_800D90A4(&param_0->unk58)) {
            func_8080130C_chfactorybattery(param_0, 6);
        }
        break;
    case 3:
        if (_subaddietaxi_entrypoint_1(param_0, func_80800678_chfactorybattery(param_0))) {
            func_8080130C_chfactorybattery(param_0, 5);
        }
        break;
    case 4:
        if (_subaddietaxi_entrypoint_11(param_0, func_80800678_chfactorybattery(param_0))) {
            if (_subaddietaxi_entrypoint_5(param_0, func_80800678_chfactorybattery(param_0))) {
                func_8080130C_chfactorybattery(param_0, 6);
            }
        }
        break;
    case 6:
        local_0 = func_800F3780(func_80101F24(param_0), D_80801B88_chfactorybattery, 4);
        local_1 = func_80100094(param_0, 1);
        if (_subaddierouteDll_entrypoint_4(param_0)) {
            if (func_8010C500(param_0)) {
                local_2 = func_800F1DF4(func_800CC63C(((BatteryKeys *)param_0)->unk70_25 - 1, ((BatteryKeys *)param_0)->unk70_4 - 1), param_0->position);
                param_0->unk54 = func_8010CD50(param_0, func_800F54E4()) - 180.0f;
                if (local_2 + 90.0f < param_0->unk54) {
                    param_0->unk54 = local_2 + 90.0f;
                } else if (param_0->unk54 < local_2 - 90.0f) {
                    param_0->unk54 = local_2 - 90.0f;
                }
            } else {
                _subaddierouteDll_entrypoint_6(param_0, local_1, param_0->unk74_7, 0x3F, 0.4f, 0x14, 0x28);
            }
            _subaddierouteDll_entrypoint_7(param_0, local_1, param_0->rotation[1], param_0->unk54, 200.0f, 0x4803);
            param_0->unk74_7 = local_1->unk6;
        }
        _subaddierouteDll_entrypoint_5(param_0, local_1, param_0->unk74_7, 0.3f, 1.0f, 300.0f * local_0);
        func_8010C3A8(param_0, 0x305425, local_0);
        break;
    case 7:
        if (func_800D90A4(&param_0->unk58)) {
            func_8080130C_chfactorybattery(param_0, 6);
        }
        break;
    case 10:
        if (func_800D90A4(&param_0->unk58)) {
            func_8080130C_chfactorybattery(param_0, 8);
        }
    case 8:
        if (param_0->unk64_20) {
            if (_subaddiejoy_entrypoint_6(param_0, 1)) {
                if (func_800D90A4(&param_0->unk58)) {
                    param_0->unk64_20 = 0;
                    param_0->unk79_4 = 0;
                    param_0->unk58 = 1.0f;
                } else {
                    param_0->unk79_4 = func_800DC128(1, 4);
                }
            } else {
                param_0->unk79_4 = 0;
            }
        } else if (func_800D90A4(&param_0->unk58) && _subaddiejoy_entrypoint_6(param_0, 1)) {
            param_0->unk64_20 = 1;
            param_0->unk58 = 2.0f;
            param_0->unk79_4 = func_800DC128(1, 4);
        }
        local_3 = 600.0f;
        local_3 *= _subaddiejoy_entrypoint_3(param_0);
        if (0.5f < func_80101F24(param_0)) {
            if (!func_80102CCC(param_0)) {
                func_80102BAC(param_0, 1.5f, 1.0f, 20.0f);
            } else {
                local_x = (0.5f < func_80101F24(param_0)) ? (func_80101F24(param_0) - 0.5f) * 2.0f : 0.0f;
                ((f32 *)param_0->actorData)[3] = func_80013970(local_x * 180.0f) * local_3;
                func_8010BA80(param_0, 0x201005, 0x20);
            }
        }
        break;
    case 9:
        _subaddiefx_entrypoint_0(param_0, 4, func_80100094(param_0, 0));
        if (func_800D90A4(&param_0->unk58)) {
            func_8080130C_chfactorybattery(param_0, 8);
        }
        break;
    case 5:
    case 13:
        if (func_8010C9FC(param_0->position, func_80103EAC(param_0), func_80103EF4(param_0), 0)) {
            func_8010108C(param_0, 0x3E, 0);
        }
        break;
    }
    func_808009C8_chfactorybattery(param_0);
    func_80800948_chfactorybattery(param_0);
    func_808008C8_chfactorybattery(param_0);
    func_80800760_chfactorybattery(param_0);
    _subaddietaxi_entrypoint_9(param_0, func_80800678_chfactorybattery(param_0));
}

s32 func_80801040_chfactorybattery(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 t;

    switch (param_1) {
    case 0x3E:
        switch ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) {
        case 1:
        case 4:
        case 9:
            if (_subaddietaxi_entrypoint_2(param_0, func_80800678_chfactorybattery(param_0))) {
                func_8080130C_chfactorybattery(param_0, 2);
            }
            return 1;
        case 6:
        case 7:
            func_8080130C_chfactorybattery(param_0, 7);
            return 1;
        case 8:
        case 10:
            if (((u32)*(u8 *)((u8 *)param_0 + 0x79) >> 4) != 0) {
                func_8080130C_chfactorybattery(param_0, 0xA);
            }
            return 1;
        case 5:
        case 13:
            func_800F7A2C(func_800F54E4(), 5, (u8 *)param_0 + 4);
            return 1;
        }
        return 1;
    case 0x40:
        switch ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) {
        case 1:
        case 6:
            func_8080130C_chfactorybattery(param_0, 1);
            return 1;
        case 8:
        case 9:
        case 10:
            func_8080130C_chfactorybattery(param_0, 9);
            return 1;
        }
        return 1;
    case 1:
        t = (u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10;
        if (t == 1 || t == 6 || t == 7) {
            func_8080130C_chfactorybattery(param_0, 8);
            return 1;
        }
        return 1;
    case 2:
        func_80107070(param_0, 1);
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, (u32)*(u8 *)((u8 *)param_0 + 0x79) >> 4);
        return 1;
    case 0x44:
        func_80800050_chfactorybattery(param_0, param_2);
        return 1;
    case 0x29:
        *(s16 *)(*(s32 *)param_0 + 0x20) = (s32)(func_8010A40C(param_0) * 120.0f);
        return 1;
    case 0x95:
        func_808001F8_chfactorybattery(param_0);
        return 1;
    case 0x4D:
        func_8080000C_chfactorybattery(param_0);
 if (1) {}
        t = (u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10;
        if (((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) != 3 && ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) != 4 && t != 5 && t != 0xD) {
            _subaddieDll_entrypoint_1(param_0);
            _subaddierouteDll_entrypoint_1(param_0);
        }
        return 1;
    default:
        return 0;
    }
}

void func_8080130C_chfactorybattery(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_0;

    switch (param_1) {
    case 1:
    case 9:
        *(u8*)((char*)param_0 + 0x79) = (u8) (*(u8*)((char*)param_0 + 0x79) & 0xFF0F);
        *(f32*)((char*)param_0 + 0x58) = 6.0f;
        break;
    case 6:
        *(f32*)((char*)param_0 + 0x24) = 800.0f;
        if (func_80100094(param_0, 0) == 0) {
            func_80100074(param_0, 0, 8);
        }
        if (func_80100094(param_0, 1) == 0) {
            func_80100074(param_0, 1, 0xC);
            _subaddierouteDll_entrypoint_3(param_0, func_80100094(param_0, 1), param_0 + 4);
        }
        if (func_80100094(param_0, 0) != 0) {
            _subaddiefx_entrypoint_1(param_0, func_80100094(param_0, 0));
        }
        break;
    case 7:
    case 10:
        func_800F7A2C(func_800F54E4(), 5, param_0 + 4);
        *(f32*)((char*)param_0 + 0x58) = 1.0f;
        break;
    case 8:
        *(u8*)((char*)param_0 + 0x65) = (u8) (*(u8*)((char*)param_0 + 0x65) & 0xFFEF);
        *(u8*)((char*)param_0 + 0x79) = (u8) (*(u8*)((char*)param_0 + 0x79) & 0xFF0F);
        *(f32*)((char*)param_0 + 0x58) = 0.0f;
        if (func_80100094(param_0, 0) != 0) {
            _subaddiefx_entrypoint_1(param_0, func_80100094(param_0, 0));
        }
        break;
    case 5:
        local_0 = func_80800480_chfactorybattery();
        if (local_0 != 0) {
            func_800DA544(local_0);
            func_800DA544(func_80800678_chfactorybattery(param_0) + 0x1B1);
        }
        /* fallthrough */
    case 13:
        func_8010A570(param_0);
        break;
    }
    func_80102424(param_0, param_1);
}

s32 func_808014C0_chfactorybattery(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0) {
        _subaddiefx_entrypoint_1(param_0, func_80100094(param_0, 0));
    }
}

int chfactorybattery_entrypoint_1()
{
  return (int)&D_80801BA8_chfactorybattery;
}

void func_8080150C_chfactorybattery(Actor *param_0)
{

    switch (func_800EA05C()) {
    case 0x101:
        func_80103140(param_0, 0x87F, 0);
        _chdoormake_entrypoint_1(param_0, -90.0f, 0x4C, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(param_0, 0, 6, 0x10);
        break;
    case 0x106:
        _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, func_80103EF4(param_0) * 0.75f, 0x44, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(param_0, 0, 3, 0x10);
        break;
    case 0x109:
        _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, func_80103EF4(param_0) * 0.75f, 0x44, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(param_0, 0, 1, 0x10);
        break;
    case 0x10B:
        _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, func_80103EF4(param_0) * 0.75f, 0x44, func_80800480_chfactorybattery());
        _chdoormake_entrypoint_9(param_0, 0, 1, 0x10);
        break;
    }
    _chdoormake_entrypoint_8(param_0, 4);
    _chdoormake_entrypoint_5(param_0, 3.0f);
    _chdoormake_entrypoint_6(param_0, 1.0f);
    if (func_800DA298(func_80800480_chfactorybattery())) {
        param_0->unk74_30 = 1;
        param_0->unk74_29 = param_0->unk74_30;
    }
}

void func_80801728_chfactorybattery(Actor *param_0)
{
    if (!func_800DA298(0x343) && func_8010CA74(param_0->position, 750) && !func_800DA298(func_80800480_chfactorybattery())) {
        func_800DA544(0x343);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1352, 6, param_0->position, 0);
        param_0->unk74_30 = 1;
    }
    if (!param_0->unk74_29 && func_800DA298(func_80800480_chfactorybattery())) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1353, 6, param_0->position, 0);
        param_0->unk74_29 = 1;
    }
    _chdoor_entrypoint_0(param_0);
}

s32 func_80801804_chfactorybattery(Actor *param_0, s32 param_1, FactoryBatteryEvent param_2)
{
    if (param_1 == 0x95) {
        if (func_800EA05C() == 0x101) {
            func_80103140(param_0, 0x87F, 0);
        }
        return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
    } else {
        return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
    }
}

int chfactorybattery_entrypoint_2()
{
    return (int)&D_80801BF0_chfactorybattery;
}
