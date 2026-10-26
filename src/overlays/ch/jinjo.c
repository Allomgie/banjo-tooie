#include "common.h"

#define CODEX_JINJO_LOOKUP_DEFINED
extern void func_800FFAB0(Actor *);
extern int func_800D0CC8(int);
extern s16 D_80801368_chjinjo[];
extern void func_800FC74C(s32);
extern void _suexpression_entrypoint_8();
typedef struct { s16 local_0; s16 local_1; } JinjoLookup;
extern s16 D_80801300_chjinjo;
extern s16 D_80801302_chjinjo;
extern JinjoLookup D_80801304_chjinjo[8];
extern void _subaddieaudioquick_entrypoint_3(void *, void *, void *, f32);
extern s32 D_80801358_chjinjo;
extern void _subaddieaudioquick_entrypoint_2(void *param_0, void *param_1, void *param_2);
extern int func_80101E14(void *param_0, float param_1);
extern float D_8080133C_chjinjo;
extern float D_80801348_chjinjo;
typedef struct { u8 pad[0x6C]; u32 pad6C:11; u32 f:12; u32 rest:9; } JinjoState;
extern s32 D_80801330_chjinjo;
extern u16 D_80801390_chjinjo[];
extern s32 func_800C05B8();
extern int D_808013A4_chjinjo;
extern int D_808013EC_chjinjo;
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void *func_80100094(Actor *, u32);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_800901CC(f32 *, f32);
extern f32 func_80101F24(Actor *);
extern void func_80102424(Actor *, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800C4244(s32, f32, s32, f32 *, f32, f32);
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 28; u32 active : 1; u32 pad_2 : 3; u32 pad_3 : 11; u32 visible : 1; u32 pad_4 : 20; } JinjoActorFlags;
extern u8 D_80801324_chjinjo[];
extern void func_80108A30(s32, f32 *, f32, s32);
extern void _chjinjo_entrypoint_4(void);
typedef union { u32 local_0; Unk80132ED0 *local_1; } JinjoEventWord;
s16 chjinjo_entrypoint_0();
s16 chjinjo_entrypoint_2();
int func_8080102C_chjinjo();

void func_80800000_chjinjo(Actor *param_0)
{
  s32 temp_v0;
  s32 var_v0;
  *(u8 *)((u8 *)param_0 + 0x79) = (u8)((*(u8 *)((u8 *)param_0 + 0x79) & 0xFF0F) | 0x10);
  if (func_800DA298(0x653) != 0) func_800FFAB0(param_0);
  temp_v0 = *(s32 *)((u8 *)param_0 + 0x6C);
  if (((u32)(temp_v0 << 11) >> 20) == 0x48F) {
    var_v0 = chjinjo_entrypoint_2(-1);
  } else {
    var_v0 = func_800D0CC8(temp_v0 & 0x1FF);
  }
  if ((((u32)(*(s32 *)((u8 *)param_0 + 0x6C) << 11) >> 20) == 0x48F) &&
      ((f32)func_800D1338(var_v0) <= *(f32 *)((u8 *)param_0 + 0x48))) {
    func_800FFAB0(param_0);
  }
  if (param_0->unk64_20) func_800FC660(0x10);
}

int func_808000DC_chjinjo(int param_0)
{
  s32 local_0;
  int new_var;
  local_0 = (*((int *) (param_0 + 0x6C))) & 0x1FF;
  local_0 = func_800D0CC8(local_0);
  new_var = local_0 | local_0;
  return chjinjo_entrypoint_0(new_var);
}

s16 chjinjo_entrypoint_0(param_0) s32 param_0; {
    return D_80801368_chjinjo[param_0];
}

void func_80800120_chjinjo(u8 *param_0) {
    if (*(s32 *)(param_0 + 0x2C)) {
        func_800FC74C(0x1C);
        *(s32 *)(param_0 + 0x2C) = 0;
    }
    func_8080102C_chjinjo(param_0, 1);
    _suexpression_entrypoint_8(param_0, 1);
}

s32 chjinjo_entrypoint_1(s32 param_0, s32 param_1){
    func_800D0C78(param_0 + 0x51, 1, param_1 | 0);
}

s16 chjinjo_entrypoint_2(param_0) s32 param_0;
{
    s32 local_0;

    if (param_0 == -1) {
        param_0 = func_800EA05C();
    }
    if (param_0 == D_80801300_chjinjo) {
        return D_80801302_chjinjo;
    }
    for (local_0 = 0; local_0 < 8; local_0++) {
        if (param_0 == D_80801304_chjinjo[local_0].local_0) {
            return D_80801304_chjinjo[local_0].local_1;
        }
    }
    return -1;
}

s32 chjinjo_entrypoint_3(s32 param_0)
{
    s32 local_0;
    if (param_0 == D_80801302_chjinjo) return D_80801300_chjinjo;
    for (local_0 = 0; local_0 < 8; local_0++) {
        if (param_0 == D_80801304_chjinjo[local_0].local_1) return D_80801304_chjinjo[local_0].local_0;
    }
    return -1;
}

void func_80800F80_chjinjo();

void func_808002E0_chjinjo(Actor *param_0)
{
    extern u8 D_8080137C_chjinjo[];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    s32 local_3;
    f32 local_4;
    s32 local_5;
    f32 local_6;
    f32 local_7[3];
    s32 local_8;
    s32 local_9;

    local_2 = func_800D8FF8();
    if (!((JinjoActorFlags *)param_0)->active) {
        return;
    }
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    if (param_0->unk74_29) {
        func_800E3980(local_0);
    } else {
        func_8010D254(local_0);
    }
    if (param_0->unk6C_9 == 0x48F) {
        func_8010C908(param_0, param_0->position);
    }
    func_800F1E6C(param_0->position, local_0, &local_4);
    local_6 = func_800F1DCC(param_0->rotation[1], local_4);

    switch (param_0->unk70_10) {
        case 1:
            if (func_800DC0C0() < 0.015f) {
                if (func_800901CC(param_0->position, 55.0f)) {
                    func_80102424(param_0, 3);
                } else {
                    func_80102424(param_0, 2);
                }
            }
            break;
        case 2:
            func_80800F14_chjinjo(param_0);
            if (func_80101E14(param_0, 0.999f)) {
                func_80102424(param_0, 1);
            }
            break;
        case 3:
            func_80800F80_chjinjo(param_0);
            if (func_80101E14(param_0, 0.999f)) {
                func_80102424(param_0, 1);
            }
            break;
        case 4:
            func_80800EE4_chjinjo(param_0);
            if (func_80101E14(param_0, 0.999f)) {
                func_80102424(param_0, 1);
            } else {
                if (local_6 >= 0.0f) {
                    param_0->rotation[1] -= 80.0f * local_2;
                } else {
                    param_0->rotation[1] += 80.0f * local_2;
                }
            }
            break;
        case 6:
            func_80800EE4_chjinjo(param_0);
            if (local_6 >= 0.0f) {
                param_0->rotation[1] -= 120.0f * local_2;
            } else {
                param_0->rotation[1] += 120.0f * local_2;
            }
            if (func_80101E14(param_0, 0.0f)) {
                param_0->unk79_4--;
                if (param_0->unk79_4 == 0) {
                    func_80102424(param_0, 7);
                    func_80102FE8(param_0, 0);
                    func_800FC63C(2, 0x6D60);
                }
            }
            break;
        case 7:
        case 8:
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 0, 0);
            local_5 = param_0->unk70_10 == 7;
            if (!local_5 || func_80101F24(param_0) > 0.1f) {
                func_8008FFBC(local_1);
                func_800EF334(local_1, local_2 * 6.0f);
                func_800EF04C(local_1, local_0);
                func_800EF3DC(local_1, param_0->position);
                func_800EF334(local_1, local_2 * 3.0f);
                func_800EF04C(param_0->position, local_1);
                if (local_5 || func_80101F24(param_0) < 0.8f) {
                    for (local_3 = 0; local_3 < 4; local_3++) {
                        if (func_800DC0C0() < 0.3f) {
                            _subaddieskeleton_entrypoint_0(param_0, 3, local_7);
                            func_800EF214(local_7, func_800DC178(0.0f, 360.0f),
                                func_800DC178(0.0f, 360.0f), 15.0f);
                            _fxtwinkle_entrypoint_0(local_7);
                        }
                    }
                }
            }
            if (local_5) {
                if (func_80101F24(param_0) < 0.2f) {
                    if (local_6 >= 0.0f) {
                        param_0->rotation[1] -= 120.0f * local_2;
                    } else {
                        param_0->rotation[1] += 120.0f * local_2;
                    }
                }
                if (func_80101E14(param_0, 0.1f)) {
                    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080137C_chjinjo);
                    param_0->actorData[5] = 1;
                    func_800FC63C(0x1C, 0x7FFF);
                    func_800FCA90(0x1C);
                    func_800C4244(0x4A2, 0.8f, 0x7FFF, param_0->position, 300.0f, 2000.0f);
                } else if (func_80101E14(param_0, 0.434f) || func_80101E14(param_0, 0.811f)) {
                    func_800C4244(0x4A2, 0.9f, 0x7FFF, param_0->position, 300.0f, 2000.0f);
                }
            } else {
                if (func_80101E14(param_0, 0.214f)) {
                    func_800C4244(0x4A2, 1.1f, 0x7FFF, param_0->position, 300.0f, 2000.0f);
                } else if (func_80101E14(param_0, 0.55f)) {
                    func_800C4244(0x43A, 1.5f, 0x7FFF, param_0->position, 300.0f, 2000.0f);
                } else if (func_80101E14(param_0, 0.75f)) {
                    if (func_800FCCD4(2)) {
                        func_800FCAE0(2, 0, 4000);
                        func_800FCA90(2);
                    }
                } else if (func_80101E14(param_0, 0.85f)) {
                    _subaddieaudioloop_entrypoint_2(param_0);
                    func_800C3EB8(0x411);
                    func_800FC74C(0x1C);
                    param_0->actorData[5] = 0;
                }
                if (func_80101F24(param_0) > 0.75f) {
                    local_8 = _subaddiefade_entrypoint_0(param_0);
                    if (local_8 >= 7) {
                        local_8 -= 7;
                    }
                    if (func_80101F24(param_0) > 0.9f) {
                        if (local_8 >= 21) {
                            local_8 -= 21;
                        } else {
                            local_8 = 0;
                        }
                    }
                    _subaddiefade_entrypoint_1(param_0, local_8);
                }
                if (func_80101E14(param_0, 0.999f)) {
                    func_80102424(param_0, 9);
                    ((JinjoActorFlags *)param_0)->visible = 0;
                    param_0->unk64_16 = ((JinjoActorFlags *)param_0)->visible;
                }
            }
            if (local_5) {
                if (func_80101E14(param_0, 0.96f) || func_80101E14(param_0, 0.999f)) {
                    func_80102424(param_0, 8);
                }
            }
            break;
        case 9:
            if (param_0->unk74_30) {
                local_9 = func_800D0CC8(param_0->unk6C_0);
                if (param_0->unk64_19) {
                    func_800F82D4(param_0->actorData[4], 0);
                    func_800DA7A8(0x6D0, local_9, 4);
                    _glcutDll_entrypoint_6(0x142, 0x84);
                } else {
                    func_8080102C_chjinjo(param_0, 0);
                }
                param_0->unk74_30 = 0;
                param_0->unk64_19 = 0;
            }
            func_800FFAB0(param_0);
            break;
    }
    if ((s32)param_0->unk70_10 < 4 && (local_6 > 45.0f || local_6 < -45.0f)) {
        func_80102424(param_0, 4);
    }
}

s32 chjinjo_entrypoint_4(s32 param_0, s32 param_1, s32 param_2) {
    _glcutDll_entrypoint_6(0x142, 0x84);
}

s32 func_80800C10_chjinjo(Actor *param_0, s32 param_1, JinjoEventWord param_2)
{
    Unk80132ED0 *local_0;
    s32 local_1;
    u32 local_2;
    s32 local_3;
    s32 local_4;

    switch (param_1) {
    case 0x29:
        _suexpression_entrypoint_7(param_0, 1, (s16)func_808000DC_chjinjo(param_0));
        _suexpression_entrypoint_12(_suexpression_entrypoint_20(param_0), 65.0f, 30.0f);
        break;
    case 0x2A:
        _suexpression_entrypoint_8(param_0, 1);
        break;
    case 0x3E:
        if ((s32)param_0->unk70_10 < 5) {
            local_0 = (*(JinjoEventWord *)&param_2).local_1;
            if (func_8010A6B0(param_0, (u32)*(u16 *)((u8 *)local_0 + 0x1A) >> 5)) {
                local_1 = func_800D0CC8(param_0->unk6C_0);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801324_chjinjo);
                func_80102424(param_0, 6);
                _subaddieDll_entrypoint_4(param_0, 1);
                func_8010A570(param_0);
                if (!func_800DA9E4(0x35, 1)) {
                    func_800C05B8(0xCDA, 0xC, 0, 0, _chjinjo_entrypoint_4, 0, func_808000DC_chjinjo(param_0));
                }
                func_800D0BD4(param_0->unk6C_0, 0);
                local_4 = func_800D1338(local_1);
                func_800D24E8(local_1 + 0xE1, local_4, func_800D129C(local_1));
                func_80801098_chjinjo(param_0, (u32)*(u16 *)((u8 *)local_0 + 0x1A) >> 5);
            }
        }
        break;
    case 0x13:
        param_0->unk6C_0 = param_2.local_0;
        if (param_0->unk6C_0 == 0x1E) {
            param_0->unk74_29 = 1;
        }
        break;
    case 0x7E:
        if (param_0->rotation[1] == 0.0f) {
            func_80108A30(0x4D6, param_0->position, 0, 0x32);
        }
        break;
    case 0x14:
        param_0->unk64_20 = 1;
        break;
    case 0x95:
        local_2 = *(u32 *)((u8 *)param_0 + 0x6C);
        if ((local_2 << 11 >> 20) == 0x48F) {
            local_3 = chjinjo_entrypoint_2(-1);
        } else {
            local_3 = func_800D0CC8(local_2 & 0x1FF);
        }
        func_80103140(param_0, 0x643, (u16)(local_3 + 0xC31));
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800EE4_chjinjo(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80801358_chjinjo, 0.6f);
}

int func_80800F14_chjinjo(Actor *param_0)
{
  if (func_80101E14(param_0, 0.2f))
  {
    if ((((*((u32 *) ((u8 *)param_0 + 0x6C))) << 11) >> 20) == 0x48F)
    {
      _subaddieaudioquick_entrypoint_2(param_0, &param_0->position, &D_80801348_chjinjo);
    }
    else
    {
      _subaddieaudioquick_entrypoint_2(param_0, &param_0->position, &D_8080133C_chjinjo);
    }
  }
}

void func_80800F80_chjinjo(Actor *param_0) {
    if (param_0->unk6C_9 != 0x48F) {
        _subaddieaudioquick_entrypoint_3(param_0, (u8 *)param_0 + 4, &D_80801330_chjinjo, 0.2f);
    }
}

void func_80800FC4_chjinjo(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800D0CC8(param_0->unk6C_0);
    func_800C05B8(D_80801390_chjinjo[local_0], 0x44, NULL, NULL, 0, 0,
        func_808000DC_chjinjo(param_0));
}

int func_8080102C_chjinjo(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (param_0->unk74_30) {
        chjinjo_entrypoint_1(func_800D0CC8(*(u32 *)((u8 *)param_0 + 0x6C) & 0x1FF), param_1);
        param_0->unk74_30 = 0;
        return 1;
    }
    return 0;
}

int func_80801098_chjinjo(Actor *param_0, u32 param_1)
{
    s32 local_2;
    s32 local_0;
    s32 local_1;

    local_1 = func_800D0CC8(param_0->unk6C_0);
    param_0->unk64_19 = 0;
    param_0->unk74_30 = 0;
    param_0->actorData[4] = param_1;

    local_2 = func_800D1338(local_1) == func_800D129C(local_1);
    if (func_800D035C(0) == 1) {
        func_800DA7A8(0x6D0, func_800D0CC8(param_0->unk6C_0), 4);
    } else if (local_2) {
        param_0->unk74_30 = 1;
        if (!func_800DA298(0x43D)) {
            param_0->unk64_19 = 1;
            func_800F82D4(param_0->actorData[4], 2);
        } else func_80800FC4_chjinjo(param_0);
    }
    return param_0->unk74_30;
}

int *chjinjo_entrypoint_5()
{
    return &D_808013A4_chjinjo;
}

int chjinjo_entrypoint_6(void)
{
    return (int)&D_808013EC_chjinjo;
}
