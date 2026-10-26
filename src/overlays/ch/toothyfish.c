#include "common.h"

typedef struct { u8 pad_0[0x18]; f32 local_0[5]; s32 local_1; f32 local_2; u8 local_3[5]; u8 local_4[5]; } ToothyFishState;
extern void *func_80100094(Actor *, u32);
extern u8 D_80801778_chtoothyfish[];
extern u8 D_80801760_chtoothyfish[];
extern u8 D_8080178C_chtoothyfish[];
extern u8 D_80801858_chtoothyfish[];
extern u8 D_8080179C_chtoothyfish[];
extern u8 D_80801864_chtoothyfish[];
extern u8 D_808017AC_chtoothyfish[];
extern Unk80132ED0 *_sueggmove_entrypoint_1(void *);
typedef struct { u8 pad0[0x18]; f32 f[5]; u8 pad1[7]; u8 b33[1]; u8 b34[1]; u8 b35[4]; u8 b39[5]; } ToothyFish;
extern void *D_80801870_chtoothyfish;
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_808017C4_chtoothyfish[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern f32 func_800DC178(f32, f32);
extern Actor *func_801084B0(s32, Actor **);
extern int D_80801914_chtoothyfish[];
extern u8 D_80801814_chtoothyfish[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA994(s32, s32, s32, s32, s32, s32, s32);
typedef struct { u8 pad0[0xC]; f32 unkC[3]; f32 unk18[5]; u8 pad2C[4]; f32 unk30; u8 unk34[5]; } ToothyData_808004A4_chtoothyfish;
extern void func_8010A624(Actor *);
extern void func_8010A63C(Actor *);
extern f32 func_800D8FF8(void);
extern void func_80105A9C(Actor *, f32);
extern void func_80105834(Actor *);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0AFC(s32, u8, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_8010CAC0(f32 *, s32);
extern s32 func_800F8B88(void);
extern void func_800E39A8(ToothyData_808004A4_chtoothyfish *, f32 *);
extern void _gcgoto_entrypoint_5(s32, s32, f32);
extern void func_80090358(f32 *, f32, s32, s32);
extern s32 func_800DC298(f32);
extern void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
typedef struct { u8 pad0[0x30]; f32 unk30; u8 unk34[5]; } ToothyData_80800B68_chtoothyfish;
extern s32 func_800F54E4(void);
extern void func_8010573C(Actor *, f32);
extern void func_80103014(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800F8294(s32, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800F608C(s32, s32);
extern void func_800F497C(s32);
extern void func_800F4A2C(s32, f32 *);
extern void func_800F49A8(s32, s32);
extern void func_800F4A00(s32, s32);
extern void func_800F49D4(s32, void *, Unk80132ED0 *);
extern void func_800F4A8C(s32, f32 *, f32);
extern void func_8010D5DC();
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_801015D0(Actor *);
extern void func_800DF744(s32, s32);
extern u8 D_808018B8_chtoothyfish[];
typedef struct { u8 pad0[0x7C]; u32 pad7C_15:17; u32 unk7C_14:1; u32 pad7C_0:14; } ToothyBits;
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
extern s32 func_80102D4C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
void func_808000E8_chtoothyfish();

void func_80800000_chtoothyfish(Actor *param_0)
{
    ToothyFishState *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_2 = 0;
    for (local_1 = 0; local_1 < 5; local_1++) {
        local_0->local_3[local_1] = func_800DA298(0x4F6 + local_1);
        if (local_0->local_3[local_1] == 0) {
            local_2++;
        }
        local_0->local_4[local_1] = 0;
        local_0->local_0[local_1] = 0.0f;
    }
    if (local_2 == 0) {
        func_808000E8_chtoothyfish(param_0, 4);
    }
    local_0->local_1 = 0;
    local_0->local_2 = 1.0f;
    param_0->unk6C_0 = _subaddiesect_entrypoint_1(param_0);
}

void func_808000E8_chtoothyfish(param_0, param_1) u8 *param_0; s32 param_1;
{
  u16 var_t6;
  var_t6 = *((u16 *) (((char *) param_0) + 0x72));
  if (param_1 != ((var_t6 & 0xFFFFu) >> 10))
  {
    func_80102424();
    if (param_1 != 1)
    {
      switch (param_1)
      {
        case 2:
          _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80801760_chtoothyfish);
          func_800FC660(0xE);
          return;

        case 3:
          _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80801778_chtoothyfish);
          func_800FC660(0x10);
          break;

        case 4:
          break;

      }

    }
  }
}

void func_80800188_chtoothyfish(f32 *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800DC128(0, 5);
    local_1 = func_800B53A4(local_0);
    func_800BABB8(local_1, param_0, 0, 1.0f, D_80801814_chtoothyfish);
    func_800BA568(local_1, (s16)(s32)(param_0[1] + param_1));
    func_800BA7C4(local_1, 0.16f * param_2, 0.3f * param_2);
    func_800BA7FC(local_1, 0.45f * param_2, 0.6f * param_2);
    func_800BA994(local_1, -75, (s16)(s32)(param_3 - 75.0f), 1200, -15, (s32)(param_3 + 75.0f), 1500);
    func_800BA22C(local_1, local_0);
}

void func_808002DC_chtoothyfish(Actor *param_0)
{
    f32 local_0[3];
    if (param_0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(param_0->unk0, 0xA, local_0);
        _subaddieaudioquick_entrypoint_4(param_0, local_0, D_8080178C_chtoothyfish, D_80801858_chtoothyfish);
        _subaddieaudioquick_entrypoint_4(param_0, local_0, D_8080179C_chtoothyfish, D_80801864_chtoothyfish);
    }
}

void func_80800350_chtoothyfish(Actor *param_0, u8 *param_1, s32 param_2)
{
    if ((param_1 + param_2)[0x39] >= 0x1E) {
        func_80108B04(param_0, param_2);
        param_0->unk74_29 = 1;
    } else {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808017AC_chtoothyfish);
        ((f32 *)param_1)[param_2 + 6] = 1.0f;
    }
}

void func_808003D4_chtoothyfish(Actor *param_0, u8 *param_1)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  u8 *local_3;
  s32 new_var;
  local_1 = 0;
 local_2 = 0; local_3 = param_1; do {
    local_2 += 1;
    if ((*((u8 *) (((char *) local_3) + 0x34))) == 0)
    {
      local_1 += 1;
    }
    local_3 += 1;
  }
  while (local_2 != 5);
  if (local_1 != (*((u8 *) (((char *) param_1) + 0x3E))))
  {
    if (local_1 != 0)
    {
      local_0 = local_1;
      func_808000E8_chtoothyfish(param_0, 2, local_1, param_1);
    }
    else
    {
      new_var = local_1;
      local_0 = new_var;
      func_808000E8_chtoothyfish(param_0, 3, local_1, param_1);
    }
    *((u8 *) (((char *) param_1) + 0x3E)) = (u8) local_1;
  }
}

void func_80800470_chtoothyfish(u8 *param_0)
{
    if (((u32)(*(u16 *)((char *)param_0 + 0x72)) >> 0xA) == 6) {
        func_808000E8_chtoothyfish(param_0, 5);
    }
}

void func_808004A4_chtoothyfish(Actor *param_0)
{
    ToothyData_808004A4_chtoothyfish *local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk64_19) {
        func_8010A624(param_0);
    } else {
        func_8010A63C(param_0);
        if (local_0->unk30 < 1.0f) {
            local_0->unk30 += 0.3f * func_800D8FF8();
        }
    }
    *(f32 *)&param_0->actorData[3] = local_0->unk30 * 200.0f;
    func_80105A9C(param_0, *(f32 *)&param_0->actorData[3]);
    func_80105834(param_0);
    param_0->rotation[0] = 0.0f;
    param_0->rotation[1] += func_800F1DCC(param_0->unk54, param_0->rotation[1]) * 0.1f;
    local_2 = func_8010262C(param_0->unk0, 5);
    if (local_2) {
        for (local_1 = 0; local_1 < 5; local_1++) {
            if (0.005f < local_0->unk18[local_1] || local_0->unk18[local_1] < -0.005f) {
                local_0->unk18[local_1] *= -0.9f;
            }
            func_800E0AFC(local_2, 90 - local_1, 1.0f, local_0->unk18[local_1] * 15.0f, local_0->unk18[local_1] * 15.0f, local_0->unk18[local_1] * 0);
        }
    }
    if (param_0->unk74_29) {
        func_808003D4_chtoothyfish(param_0, local_0);
    }
    switch (param_0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_80101E14(param_0, 0.999f)) {
            func_808000E8_chtoothyfish(param_0, 1);
        }
        break;
    case 3:
        if (func_80101E14(param_0, 0.25f)) {
            func_808000E8_chtoothyfish(param_0, 4);
        }
        break;
    case 4:
        func_800EEC30(local_3, -param_0->rotation[0] - 30.0f, param_0->rotation[1], param_0->scale * 80.0f);
        func_800EF04C(local_3, param_0->position);
        _sudeflect_entrypoint_0(local_3, param_0->scale * 70.0f, param_0->scale * 80.0f, 4);
        if (func_8010CAC0(local_3, param_0->scale * 70.0f) && func_800F8B88() != 3) {
            func_800E39A8(local_0, local_0->unkC);
            _gcgoto_entrypoint_5(0xF8, 1, param_0->rotation[1] + 180.0f);
            param_0->unk64_20 = 1;
            func_80090358(param_0->position, 4.0f, 0, 0);
            func_808000E8_chtoothyfish(param_0, 5);
        }
        break;
    case 6:
        local_0->unk30 = 0.0f;
        break;
    case 5:
        func_800EEC30(local_4, -param_0->rotation[0] - 20.0f, param_0->rotation[1], param_0->scale * 80.0f);
        func_800EF04C(local_4, param_0->position);
        if (!func_8010CAC0(local_4, param_0->scale * 150.0f)) {
            func_808000E8_chtoothyfish(param_0, 4);
        }
        break;
    }
    func_808002DC_chtoothyfish(param_0);
    if (param_0->unk7C_12) {
        if (func_800DC298(0.03f) || (param_0->unk70_10 == 2 && func_800DC298(0.1f))) {
            _subaddieskeleton_entrypoint_2(param_0->unk0, 6, local_5);
            func_80800188_chtoothyfish(local_5, 1000.0f, param_0->scale, param_0->rotation[1]);
        }
    }
}

s32 func_80800908_chtoothyfish(s32 param_0)
{
    param_0 &= 0x78000000;
    switch (param_0) {
    case 0x28000000:
        return 0;
    case 0x08000000:
        return 1;
    case 0x10000000:
        return 2;
    case 0x18000000:
        return 3;
    case 0x20000000:
        return 4;
    default:
        return -1;
    }
}

void func_8080096C_chtoothyfish(Actor *param_0, u8 *param_1)
{
    ToothyFish *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    local_1 = 1;
    local_2 = 0;
    if (param_0->unk7C_12 && param_1 != NULL) {
        switch (*(u32 *)(param_1 + 0x24) >> 22) {
        default: local_1 = 0; break;
        case 0x26C: local_2 = 10; break;
        case 0x26D: local_2 = 20; break;
        case 0x26F: local_2 = 30; break;
        case 0x26E: local_2 = 20; break;
        }
        if (local_2 && local_1 && _sueggmove_entrypoint_1(param_1) == param_0->unk0) {
            local_3 = func_80800908_chtoothyfish(_sueggmove_entrypoint_2(param_1));
            if (local_3 >= 0) {
                local_0->b39[local_3] += local_2;
                if (local_2 == 30) {
                    local_4 = local_3 - 1;
                    local_5 = local_3 + 1;
                    if (local_3 > 0 && !local_0->b33[local_3]) {
                        local_0->b39[local_4] += 10;
                        local_0->f[local_4] = 0.5f;
                        if (local_0->b39[local_4] >= 30) {
                            func_80108B04(param_0, local_4);
                        }
                    }
                    if (local_3 < 4 && !local_0->b35[local_3]) {
                        local_0->b39[local_5] += 10;
                        local_0->f[local_5] = 0.5f;
                        if (local_0->b39[local_5] >= 30) {
                            func_80108B04(param_0, local_5);
                        }
                    }
                }
                if (!local_0->b34[local_3]) {
                    func_80800350_chtoothyfish(param_0, local_0, local_3);
                }
            }
        }
    }
}

void func_80801588_chtoothyfish();

s32 func_80800B68_chtoothyfish(Actor *param_0, s32 param_1, s32 param_2)
{
    ToothyData_80800B68_chtoothyfish *local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x49:
        if (param_0->unk64_20) {
            local_3 = func_800F54E4();
            func_8010573C(param_0, 0.73f);
            func_80103014(param_0);
            func_800EEC30(local_1, -param_0->rotation[0], param_0->rotation[1], param_0->scale * 150.0f);
            func_800EF04C(local_1, param_0->position);
            func_800EFA4C(local_2, 0.0f, param_0->rotation[1], 0.0f);
            func_800F8294(local_3, local_1);
            func_800F832C(local_3, local_2);
            func_800F608C(local_3, 5);
            func_800F497C(local_3);
            func_800F4A2C(local_3, local_1);
            func_800F49A8(local_3, 1);
            func_800F4A00(local_3, 1);
            func_800F49D4(local_3, func_8010D5DC, param_0->unk0);
            func_800EEC30(local_1, -param_0->rotation[0], param_0->rotation[1], param_0->scale * 350.0f);
            func_800EF04C(local_1, param_0->position);
            func_800F4A8C(local_3, local_1, 2.0f);
            local_0->unk30 = 0.0f;
            param_0->unk79_4 = 0xF;
            param_0->unk64_20 = 0;
            param_0->unk64_19 = 1;
            param_0->unk58 = 5.0f;
            _capod_entrypoint_13(param_0->unk0, 0, 0x2E, 0xA4C);
            return 1;
        }
        break;
    case 0x32:
        param_0->unk64_19 = 0;
        break;
    case 0x3E:
        func_8080096C_chtoothyfish(param_0, param_2);
        return 1;
    case 0x3D:
        func_80801588_chtoothyfish(param_0, param_2);
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        for (local_4 = 0; local_4 < 5; local_4++) {
            if (local_0->unk34[local_4]) {
                func_800DF744(local_4 + 3, 0);
            } else {
                func_800DF744(local_4 + 3, 1);
            }
        }
        return 1;
    default:
        return 0;
    }
    return 1;
}

void *chtoothyfish_entrypoint_0()
{
    return &D_80801870_chtoothyfish;
}

void func_80800E04_chtoothyfish(Actor *param_0)
{
    Actor *local_0;

    local_0 = func_80106790(param_0->unk3C);
    _subaddieskeleton_entrypoint_2(param_0->unk3C, param_0->unk6C_0 + 4, param_0->position);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808017C4_chtoothyfish);
    param_0->scale = local_0->scale;
    param_0->rotation[2] = local_0->rotation[2];
    param_0->rotation[0] = local_0->rotation[0];
    func_800EFCD8((f32 *)&param_0->actorData[4], func_800F1DF4(local_0->position, param_0->position), 3000.0f);
    *(f32 *)&param_0->actorData[5] = 200.0f;
    *(f32 *)&param_0->actorData[7] = -1000.0f;
    func_80103140(param_0, (u16)(param_0->unk6C_0 + 0x73A), param_0->unk0->unk16);
}

void func_80800EDC_chtoothyfish(s32 arg0) 
{
}
void func_80800EE4_chtoothyfish(Actor *param_0, s32 param_1)
{
    func_80101FDC(param_0, param_1);
    switch (param_1) {
    case 2:
        param_0->unk50 = func_800DC178(165.0f, 195.0f);
        break;
    case 4:
        param_0->unk50 = func_800DC178(45.0f, 135.0f);
        break;
    }
}

void func_80800F6C_chtoothyfish(f32 *param_0, f32 param_1, f32 param_2)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800DC128(0, 5);
    local_1 = func_800B53A4(local_0);
    func_800BABB8(local_1, param_0, NULL, 1.0f, D_808018B8_chtoothyfish);
    func_800BA568(local_1, (s16)(param_0[1] + param_1));
    func_800BA7C4(local_1, 0.08f * param_2, 0.15f * param_2);
    func_800BA7FC(local_1, 0.09f * param_2, 0.18f * param_2);
    func_800BA22C(local_1, local_0);
}

void func_8080106C_chtoothyfish(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;

    local_1 = func_800D8FF8();
    func_800EFA20(local_0, (f32 *)&param_0->actorData[4], local_1);
    switch (param_0->unk70_10) {
    case 1:
        func_800EF04C(param_0->position, local_0);
        ((f32 *)param_0->actorData)[4] *= 0.7f;
        ((f32 *)param_0->actorData)[6] *= 0.7f;
        ((f32 *)param_0->actorData)[5] += ((f32 *)param_0->actorData)[7] * local_1;
        if (((f32 *)param_0->actorData)[5] < -50.0f) {
            func_80800EE4_chtoothyfish(param_0, 2);
        }
        param_0->rotation[0] += 400.0f * local_1;
        param_0->rotation[1] += 200.0f * local_1;
        if (func_800DC298(0.2f)) {
            func_80800F6C_chtoothyfish(param_0->position, 200.0f, param_0->scale);
        }
        break;
    case 2:
        func_800EF04C(param_0->position, local_0);
        ((f32 *)param_0->actorData)[4] *= 0.7f;
        ((f32 *)param_0->actorData)[6] *= 0.7f;
        ((f32 *)param_0->actorData)[5] += ((f32 *)param_0->actorData)[7] * local_1;
        if (_subaddie3d_entrypoint_0(param_0->position, 0.0f, param_0->scale * -200.0f, (f32 *)&param_0->actorData[1])) {
            if (((f32 *)param_0->actorData)[1] + 20.0f * param_0->scale < local_0[1] + param_0->position[1]) {
                param_0->position[1] = local_0[1] + param_0->position[1];
            } else {
                func_80800EE4_chtoothyfish(param_0, 4);
            }
        } else if (func_80102D4C(param_0, 4.0f)) {
            func_80800EE4_chtoothyfish(param_0, 3);
        } else {
            func_80102B6C(param_0, 4.0f);
        }
        if (func_800DC298(0.2f)) {
            func_80800F6C_chtoothyfish(param_0->position, 200.0f, param_0->scale);
        }
        break;
    case 3:
        ((f32 *)param_0->actorData)[4] *= 0.7f;
        ((f32 *)param_0->actorData)[6] *= 0.7f;
        ((f32 *)param_0->actorData)[5] += ((f32 *)param_0->actorData)[7] * local_1;
        param_0->position[0] += ((f32 *)param_0->actorData)[4];
        param_0->position[2] += ((f32 *)param_0->actorData)[6];
        if (_subaddie3d_entrypoint_0(param_0->position, 0.0f, param_0->scale * -200.0f, (f32 *)&param_0->actorData[1])) {
            if (((f32 *)param_0->actorData)[1] + 50.0f * param_0->scale < local_0[1] + param_0->position[1]) {
                param_0->position[1] = local_0[1] + param_0->position[1];
            } else {
                func_80800EE4_chtoothyfish(param_0, 4);
            }
        } else {
            param_0->position[1] += local_0[1];
        }
        if (!func_80102D4C(param_0, 3.0f)) {
            func_80102B6C(param_0, 3.0f);
        }
        if (!func_80102CF4(param_0, 3.0f)) {
            func_80102B2C(param_0, 3.0f);
        }
        if (func_800DC298(0.1f)) {
            param_0->unk50 = func_800DC178(140.0f, 220.0f);
        }
        if (func_800DC298(0.1f)) {
            param_0->unk54 = param_0->rotation[1] + func_800DC178(-90.0f, 90.0f);
        }
        if (func_800DC298(0.2f)) {
            func_80800F6C_chtoothyfish(param_0->position, 200.0f, param_0->scale);
        }
        break;
    case 4:
        if (((f32 *)param_0->actorData)[1] + 10.0f * param_0->scale < param_0->position[1]) {
            param_0->position[1] += ((f32 *)param_0->actorData)[5] * local_1;
        } else if (param_0->position[1] < ((f32 *)param_0->actorData)[1]) {
            param_0->position[1] += 4.0f;
        }
        if (!func_80102D4C(param_0, 8.0f)) {
            func_80102B6C(param_0, 8.0f);
        } else {
            func_80800EE4_chtoothyfish(param_0, 5);
        }
        break;
    case 5:
        if (((f32 *)param_0->actorData)[1] + 10.0f * param_0->scale < param_0->position[1]) {
            param_0->position[1] += ((f32 *)param_0->actorData)[5] * local_1;
        } else if (param_0->position[1] < ((f32 *)param_0->actorData)[1] + 5.0f * param_0->scale) {
            param_0->position[1] += 4.0f;
        } else {
            ((ToothyBits *)param_0)->unk7C_14 = 0;
        }
        break;
    }
}

void func_80801588_chtoothyfish(Actor *param_0, s32 param_1)
{
    Actor *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = func_801084B0(0x310, &param_0);
    func_800DA544(param_1 + 0x4F6);
    local_1[param_1 + 0x34] = 1;
    local_0->unk3C = param_0->unk0;
    local_0->unk6C_0 = param_1;
}

int chtoothyfish_entrypoint_1()
{
    return (int)&D_80801914_chtoothyfish;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/toothyfish.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80801914_chtoothyfish -> int[] */
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_80101870();
u8 D_80801760_chtoothyfish[24] = { 0x0, 0x13, 0x5, 0x44, 0x0, 0xD, 0x0, 0xCC, 0x1, 0x33, 0x0, 0x16, 0x7F, 0xFF, 0x0, 0x1, 0xF, 0xA0, 0x1D, 0x4C, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801778_chtoothyfish[20] = { 0x0, 0x13, 0x5, 0xCE, 0x0, 0xA, 0x0, 0x66, 0x0, 0x16, 0x7F, 0xFF, 0x0, 0x1, 0xF, 0xA0, 0x1D, 0x4C, 0x0, 0x0 };
u8 D_8080178C_chtoothyfish[16] = { 0x0, 0x13, 0x3, 0xED, 0x0, 0xD, 0x0, 0x40, 0x0, 0x4C, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0 };
u8 D_8080179C_chtoothyfish[16] = { 0x0, 0x13, 0x3, 0xED, 0x0, 0xD, 0x0, 0x4C, 0x0, 0x59, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0 };
u8 D_808017AC_chtoothyfish[24] = { 0x0, 0x13, 0x5, 0x46, 0x0, 0xD, 0x0, 0xCC, 0x0, 0xE6, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x1, 0xF, 0xA0, 0x1D, 0x4C, 0x0, 0x0, 0x0, 0x0 };
u8 D_808017C4_chtoothyfish[24] = { 0x0, 0x13, 0x5, 0x47, 0x0, 0xD, 0x0, 0xCC, 0x0, 0xE6, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x1, 0xF, 0xA0, 0x1D, 0x4C, 0x0, 0x0, 0x0, 0x0 };
u32 D_808017DC_chtoothyfish[14] = { 0x0, 0x0, 0x40000000, 0x1190001, 0x3F99999A, 0xFA0042, 0x3FC00000, 0xFA0042, 0x40000000, 0x11A0001, 0x40000000, 0x11A0001, 0x40000000, 0x11A0001 };
u8 D_80801814_chtoothyfish[68] = { 0x0, 0x1D, 0x9, 0xD9, 0x0, 0x16, 0x10, 0x4, 0x0, 0x1, 0x0, 0x0, 0x0, 0x23, 0x0, 0x0, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0, 0x7, 0x0, 0x1, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0x2B, 0x1, 0x80, 0x4, 0x80, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0 };
u8 D_80801858_chtoothyfish[12] = { 0x3E, 0x2E, 0x14, 0x7B, 0x3F, 0x2E, 0x14, 0x7B, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80801864_chtoothyfish[12] = { 0x3E, 0xDC, 0x28, 0xF6, 0x3F, 0x68, 0xF5, 0xC3, 0xBF, 0x80, 0x0, 0x0 };
void *D_80801870_chtoothyfish = (void *)0x02D4030F;
static u32 D_80801870_chtoothyfish_rest[17] = { 0x6C50001, (u32)&D_808017DC_chtoothyfish, (u32)func_808004A4_chtoothyfish, (u32)func_808004A4_chtoothyfish, (u32)func_801018A4, 0x2EE02AF8, 0x0, 0x0, 0xC68, (u32)func_80800470_chtoothyfish, (u32)func_80108ED0, 0x400000, (u32)func_80800000_chtoothyfish, (u32)func_80107C2C, 0x0, (u32)func_80800B68_chtoothyfish, 0x0 };
u8 D_808018B8_chtoothyfish[92] = { 0x0, 0x1D, 0x9, 0xD9, 0x0, 0x16, 0x10, 0x4, 0x0, 0x2C, 0x0, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x0, 0x0, 0xB, 0x0, 0xF, 0x0, 0x1E, 0x0, 0xF, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x23, 0x0, 0x0, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0, 0x7, 0x0, 0x1, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x80, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0 };
int D_80801914_chtoothyfish[19] = { 0x2D50310, 0x73A0001, 0x0, (u32)func_8080106C_chtoothyfish, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x800, (u32)func_80800EDC_chtoothyfish, 0x0, 0x0, (u32)func_80800E04_chtoothyfish, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0, 0x0 };
