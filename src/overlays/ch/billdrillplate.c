#include "common.h"
#include "types.h"
#include "macros.h"

extern int D_80801124_chbilldrillplate;
extern int D_8080116C_chbilldrillplate;
extern s32 func_800DC298(f32);
typedef union { s32 word; Unk80132ED0 *marker; } BillDrillPlateEventPayload;
extern void _subaddiefade_entrypoint_14(void *arg);
extern void _subaddielink_entrypoint_0(void *param_0);
extern void *func_80100094(Actor *, u32);
extern Actor *_subaddiefind_entrypoint_0();
extern Actor *_subaddielink_entrypoint_4(void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern u8 D_80801220_chbilldrillplate[];
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_808010DC_chbilldrillplate[];
typedef struct { u16 unk0; u16 unk2; u8 pad[16]; } BilldrillPlateEntry;
extern BilldrillPlateEntry D_808010A0_chbilldrillplate[];
extern s32 func_800EA05C(void);
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 28; u32 bit : 1; u32 pad_2 : 3; } ChBDP;
extern void _chbounce_entrypoint_5();
extern void _subaddiefade_entrypoint_3();
extern void func_80101FDC();
extern s32 D_808011B4_chbilldrillplate;
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern void _chbounce_entrypoint_3(f32);
extern u8 D_808011C4_chbilldrillplate[];
extern u8 D_808011D4_chbilldrillplate[];
extern u8 D_808011E0_chbilldrillplate[];
extern u8 D_808011F0_chbilldrillplate[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern u32 D_80801234_chbilldrillplate;
extern u32 D_80801244_chbilldrillplate;
extern void *func_80101080(void);
extern void *func_80106790(void *);
extern void _chexploder_entrypoint_6(void *, f32, f32);
Actor *func_80800978_chbilldrillplate();
u8 *func_80800FCC_chbilldrillplate();
BilldrillPlateEntry *func_80801020_chbilldrillplate();

int *chbilldrillplate_entrypoint_0()
{
    return ((int *) D_808010DC_chbilldrillplate);
}

int chbilldrillplate_entrypoint_1()
{
    return (int)&D_80801124_chbilldrillplate;
}

int chbilldrillplate_entrypoint_2()
{
  return &D_8080116C_chbilldrillplate;
}

void func_80800024_chbilldrillplate(Actor *param_0)
{
    f32 local_0;
    if (func_800DA298(*(u16 *)((u8 *)func_80800FCC_chbilldrillplate(param_0) + 0xC))) {
        func_800FFAB0(param_0);
    } else {
        _subaddiefade_entrypoint_14(param_0);
        local_0 = func_800DC298(0.5f) ? -1.0f : 1.0f;
        ((f32 *)param_0->actorData)[4] = local_0 * 200.0f;
    }
}

void func_808002A0_chbilldrillplate();

void func_808000B0_chbilldrillplate(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 2:
            if (func_800D90A4((f32 *)((u8 *)param_0 + 0x2C))) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808011B4_chbilldrillplate);
                *(f32 *)((u8 *)param_0 + 0x2C) = 0.4f;
            }
            param_0->rotation[1] = func_800136E4(param_0->rotation[1] + func_800D8FF8() * 600.0f);
            param_0->position[1] += func_800D8FF8() * 50.0f;
            if (_subaddieDll_entrypoint_6(param_0, 0xB)) {
                _chbounce_entrypoint_3(param_0->rotation[1]);
                _chbounce_entrypoint_5(0x1B, param_0);
                func_80101FDC(param_0, 3);
                func_8010A624(param_0);
                func_8010A570(param_0);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808011B4_chbilldrillplate);
                *(f32 *)((u8 *)param_0 + 0x30) = 1.2f;
            }
            break;
        case 1: break;
        case 3:
            param_0->rotation[0] = func_800136E4(param_0->rotation[0] + func_800D8FF8() * *(f32 *)((u8 *)param_0 + 0x28));
            if (func_800D9078((f32 *)((u8 *)param_0 + 0x30))) { func_808002A0_chbilldrillplate(param_0); }
            if (!((ChBDP *)param_0)->bit) {
                _subaddiefade_entrypoint_3(param_0);
                func_80101FDC(param_0, 4);
                func_80103110(param_0, 0);
            }
            break;
    }
}

s32 func_80800240_chbilldrillplate(Actor *param_0, s32 param_1, BillDrillPlateEventPayload param_2)
{
    switch (param_1) {
    case 0x3F:
        if (_subaddieDll_entrypoint_5(param_0, param_2.word)) {
            func_80103110(param_0, 1);
            func_80101FDC(param_0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808002A0_chbilldrillplate(Actor *param_0)
{
    Actor *local_0[4];
    s32 local_1;
    s32 local_3;
    s32 local_2;
    u16 *local_4;

    local_1 = _subaddiefind_entrypoint_4(0x3DC, local_0, 4);
    local_2 = local_1;
    for (local_3 = 0; local_3 < local_1; local_3++) {
        if ((s32)local_0[local_3]->unk70_10 >= 3) {
            local_2--;
        }
    }
    if (local_2 == 3 || local_2 == 0) {
        local_4 = func_80800FCC_chbilldrillplate();
        if (local_2 == 0) {
            func_800DA544(local_4[6]);
        }
        _glcutDll_entrypoint_6(local_4[1], local_4[7]);
    }
}

void func_80800358_chbilldrillplate(Actor *param_0)
{
  void *local_0;
  void *local_1;
  void *local_2;
  unsigned short local_3;
  float local_4;
  float local_5;
  local_0 = (0, func_80801020_chbilldrillplate());
  local_2 = func_80100094(param_0, 0);
  local_1 = local_2;
  *((float *) (((char *) param_0) + 0x34)) = 600.0f;
  local_4 = *((float *) (((char *) param_0) + 0x8));
  *((float *) (((char *) param_0) + 0x28)) = local_4;
  local_3 = (*((unsigned short *) (((char *) local_0) + 0x4))) ^ 0;
  local_5 = (float) local_3;
  *((float *) (((char *) param_0) + 0x8)) = (float) (local_4 + local_5);
  _subaddielink_entrypoint_0(local_2);
  _subaddiefade_entrypoint_14(param_0);
  if (*((unsigned short *) (((char *) local_0) + 0x10)))
  {
    *((float *) (((char *) local_1) + 0x8)) = 25.f;
  }
}

s32 func_80800C98_chbilldrillplate(Actor *param_0, f32 *param_1, f32 param_2);

void func_80800B9C_chbilldrillplate();

void func_80800408_chbilldrillplate(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    s32 local_2;
    Vec3f local_3;
    f32 local_4;
    s32 local_5;
    Actor *local_6;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        break;
    case 2:
        if (!param_0->unk64_20) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808011C4_chbilldrillplate);
            param_0->unk64_20 = 1;
        }
        _subaddieDll_entrypoint_7(param_0, 8);
        if (_subaddielink_entrypoint_2(local_0)) {
            _subaddieDll_entrypoint_7(_subaddielink_entrypoint_4(local_0), 8);
        }
        if (func_800D9078(&param_0->unk58)) {
            func_80800B9C_chbilldrillplate(param_0);
            func_80101FDC(param_0, 4);
        }
        break;
    case 3:
        if (!param_0->unk64_20) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808011C4_chbilldrillplate);
            param_0->unk64_20 = 1;
        }
        if (func_800D9078((f32 *)&param_0->actorData[6])) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808011D4_chbilldrillplate);
        }
        _subaddieDll_entrypoint_7(param_0, 8);
        if (_subaddielink_entrypoint_2(local_0)) {
            _subaddieDll_entrypoint_7(_subaddielink_entrypoint_4(local_0), 8);
        }
        if (func_800D9078(&param_0->unk58)) {
            func_80101FDC(param_0, 1);
            func_80103110(param_0, 0);
        }
        break;
    case 4:
        local_4 = func_800D8FF8();
        param_0->position[1] -= *(f32 *)&param_0->actorData[7] * local_4;
        *(f32 *)&param_0->actorData[7] += 2500.0f * local_4;
        func_80800C98_chbilldrillplate(param_0, &local_1, *(f32 *)&param_0->actorData[7] * local_4);
        if (param_0->position[1] < local_1) {
            param_0->position[1] = local_1;
            *(f32 *)&param_0->actorData[7] = 600.0f;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808011E0_chbilldrillplate);
            local_5 = func_800B53A4(8);
            for (local_2 = 0; local_2 != 8; local_2++) {
                func_800EE7F8(local_3.f, param_0->position);
                func_800EF1B8(local_3.f, (f32)local_2 * 45.0f, func_800DC178(100.0f, 120.0f));
                func_800BABB8(local_5, local_3.f, param_0->position, 1.5f, D_808011F0_chbilldrillplate);
            }
            func_800E15CC(0, 30.0f, 0.9f);
            func_80018820(0, 2.0f, 0.3f);
            func_80101FDC(param_0, 5);
            func_80103110(param_0, 0);
        }
        if (_subaddielink_entrypoint_2(local_0)) {
            local_6 = _subaddielink_entrypoint_4(local_0);
            local_6->position[1] = *(f32 *)(local_0 + 8) + param_0->position[1];
            func_80103014(local_6);
        }
        break;
    }
}

s32 func_80800738_chbilldrillplate(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;
    Actor *local_3;
    u16 local_4;
    Actor *local_5;

    if (param_1 == 0x49) {
        local_0 = func_80801020_chbilldrillplate();
        if (param_2 == *(u16 *)(local_0 + 0xE)) {
            func_80103110(param_0, 1);
            if (func_800DA298(*(u16 *)(local_0 + 0xC))) {
                func_80101FDC(param_0, 2);
                param_0->unk58 = 1.0f;
                func_800FC660(16);
                local_5 = func_80800978_chbilldrillplate(param_0);
                local_5->actorData[5] = 0;
                _capod_entrypoint_13(local_5->unk0, 0, *(u16 *)(local_0 + 8), 0x900);
                return 1;
            }
            param_0->actorData[5] = 1;
            ((f32 *)param_0->actorData)[6] = 0.5f;
            func_80101FDC(param_0, 3);
            param_0->unk58 = 1.0f;
            _capod_entrypoint_13(param_0->unk0, 0, *(u16 *)(local_0 + 0xA), 0x900);
            return 1;
        }
    }
    if (param_1 == 0x95) {
        local_1 = func_80100094(param_0, 0);
        local_2 = func_80801020_chbilldrillplate();
        if (local_2[0x12]) {
            _subaddieDll_entrypoint_0(param_0);
        }
        func_80103140(param_0, *(u16 *)(local_2 + 6), *(u16 *)((u8 *)param_0->unk0 + 0x16));
        _subaddielink_entrypoint_0(local_1);
        local_4 = *(u16 *)(local_2 + 0x10);
        if (local_4) {
            local_5 = _subaddiefind_entrypoint_0(param_0->position, local_4, -1, 0);
            if (local_5 != NULL) {
                _subaddielink_entrypoint_1(local_1, local_5->unk0);
            }
        }
        if (!_glcutDll_entrypoint_19(*(u16 *)(local_2 + 0xE))) {
            if (func_800DA298(*(u16 *)(local_2 + 0xC))) {
                param_0->actorData[5] = 0;
                param_0->position[1] = ((f32 *)param_0->actorData)[4];
            } else {
                param_0->actorData[5] = 1;
            }
        }
        local_5 = _subaddielink_entrypoint_4(local_1);
        if (local_5 != NULL) {
            local_5->position[1] = *(f32 *)(local_1 + 8) + param_0->position[1];
            func_80103014(local_5);
        }
    }
    return 0;
}

s32 func_80800924_chbilldrillplate(s32 param_0, s32 param_1){
    s32 local_0 = func_80801020_chbilldrillplate();
    s32 local_1;
    if ((*(u8*)(local_0 + 0x13)) != 0){
        local_1 = 0;
    } else {
        local_1 = *(s32*)(param_0 + 0x2C);
    }
    func_800DF744(1, local_1);
    func_80101870(param_0, param_1);
}

Actor *func_80800978_chbilldrillplate(param_0) Actor *param_0;
{
    Vec3f local_0;
    Vec3f local_1;

    switch (func_800EA05C()) {
    case 0x101:
        func_800EFA4C(local_0.f, 180.0f, 480.0f, 180.0f);
        func_800EF04C(local_0.f, param_0->position);
        func_80108528(0x473, local_0.f, 0, &param_0);
        func_800EFA4C(local_0.f, -180.0f, 480.0f, 180.0f);
        func_800EF04C(local_0.f, param_0->position);
        func_80108528(0x473, local_0.f, 0, &param_0);
        func_800EFA4C(local_0.f, 180.0f, 480.0f, -180.0f);
        func_800EF04C(local_0.f, param_0->position);
        func_80108528(0x473, local_0.f, 0, &param_0);
        func_800EFA4C(local_0.f, -180.0f, 480.0f, -180.0f);
        func_800EF04C(local_0.f, param_0->position);
        func_80108528(0x473, local_0.f, 0, &param_0);
        break;
    case 0x107:
        func_800EFA4C(local_1.f, 130.0f, 20.0f, 130.0f);
        func_800EF04C(local_1.f, param_0->position);
        func_80108528(0x473, local_1.f, 0, &param_0);
        func_800EFA4C(local_1.f, -130.0f, 20.0f, 130.0f);
        func_800EF04C(local_1.f, param_0->position);
        func_80108528(0x473, local_1.f, 0, &param_0);
        func_800EFA4C(local_1.f, 130.0f, 20.0f, -130.0f);
        func_800EF04C(local_1.f, param_0->position);
        func_80108528(0x473, local_1.f, 0, &param_0);
        func_800EFA4C(local_1.f, -130.0f, 20.0f, -130.0f);
        func_800EF04C(local_1.f, param_0->position);
        func_80108528(0x473, local_1.f, 0, &param_0);
        break;
    }
    return param_0;
}

void func_80800B9C_chbilldrillplate(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    switch (func_800EA05C()) {
        case 0x101:
            func_800EFA4C(local_0, 180.0f, 680.0f, 180.0f);
            func_800EF04C(local_0, param_0->position);
            func_80101010(local_0);
            func_80101180(0x473, 5, 0);
            _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80801220_chbilldrillplate);
            break;
        case 0x107:
            func_800EFA4C(local_1, 130.0f, 220.0f, 130.0f);
            func_800EF04C(local_1, param_0->position);
            func_80101010(local_1);
            func_80101180(0x473, 5, 0);
            _subaddieaudioquick_entrypoint_2(param_0, local_1, D_80801220_chbilldrillplate);
            break;
    }
}

s32 func_80800C98_chbilldrillplate(Actor *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;

    func_800EE7F8(local_0, param_0->position);
    func_800EE7F8(local_1, param_0->position);
    local_0[1] += 20.0f + param_2;
    local_1[1] -= 20.0f;
    func_8010A624(param_0);
    if (func_800C6A7C(local_0, local_1, local_2, 0x20020)) local_3 = 1;
    else local_3 = 0;
    func_8010A63C(param_0);
    if (local_3) *param_1 = local_1[1];
    return local_3;
}

int func_80800D5C_chbilldrillplate(s32 param_0)
{
  if (func_800DA298(*(u16 *)(func_80800FCC_chbilldrillplate() + 0xC)))
  {
    func_800FFAB0(param_0);
    return;
  }
  _subaddiefade_entrypoint_14(param_0);
}

void func_80800DA4_chbilldrillplate(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_3;
    s32 local_4;
    if (param_0->unk70_10 == 2 && func_800D9078((u8 *)param_0 + 0x58)) {
            func_800EE7F8(local_0, param_0->position);
        local_0[1] -= 150.0f;
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80801234_chbilldrillplate);
        local_3 = func_800B53A4(5);
        for (local_4 = 0; local_4 != 5; local_4++) {
            func_800EE7F8(local_1, param_0->position);
            func_800EF1B8(local_1, local_4 * 72.0f, func_800DC178(100.0f, 120.0f));
            func_800BABB8(local_3, local_1, local_0, 1.4f, &D_80801244_chbilldrillplate);
        }
        _chexploder_entrypoint_3(param_0, local_0, 8);
    }
}

s32 func_80800F24_chbilldrillplate(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x95:
            if (func_800DA298(*(u16 *)((u8 *)func_80800FCC_chbilldrillplate() + 0xC))) {
                func_80101FDC(param_0, 2);
                param_0->unk58 = 0.16f;
                func_80103110(param_0, 1);
            }
            break;
        case 0x90:
            _chexploder_entrypoint_6(func_80106790(func_80101080()), 500.0f, 600.0f);
            return 1;
        default: return 0;
    }
    return 1;
}

u8 *func_80800FCC_chbilldrillplate(void)
{
  s32 local_0;
  u8 *local_1;
  local_0 = func_800EA05C();
 local_1 = (u8 *) (((u8 *) D_808010A0_chbilldrillplate)); loop_1: if (local_0 == (*((u16 *) local_1))) { return local_1;
  }

  local_1 += 0x14;
  if (((u8 *) local_1) == ((u8 *) (&D_808010DC_chbilldrillplate)))
  {
    return 0;
  }
  goto loop_1;
}

BilldrillPlateEntry *func_80801020_chbilldrillplate(void)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800EA05C();
    for (local_1 = 0; local_1 < 3; local_1++) {
        if (D_808010A0_chbilldrillplate[local_1].unk2 == local_0) {
            return &D_808010A0_chbilldrillplate[local_1];
        }
    }
    return NULL;
}
