#include "common.h"

extern int D_80802434_chchuffy;
extern u32 D_808024B4_chchuffy[];
extern void rom_read_word(u32, u32 *);
extern s16 D_8080247C_chchuffy[][4];
extern Actor *func_80106790(s32);
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F1828();
extern f32 func_800F1DF4();
typedef struct { u8 pad_0[0x4C]; f32 local_0[3]; f32 local_1[3]; } ChuffyPositionData;
typedef struct { u8 pad_0[0x2A8]; s32 local_0; } ChuffyInitData;
typedef struct { u8 pad_0[0xA]; u8 local_0 : 5; u8 pad_1 : 3; } ChuffyPropFlags;
typedef struct { s32 f0; s32 f4; u8 pad[0x6C]; u8 pad74:1; u8 flag:1; u8 rest:6; } FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern Actor *func_801084B0(s32, Actor **);
typedef struct { f32 local_0[2]; } ChuffyEffectPair;
typedef struct { f32 local_0[3]; } ChuffyEffectVector;
extern s32 D_80802568_chchuffy[];
extern s32 D_80802570_chchuffy[];
extern s32 D_8080257C_chchuffy[];
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern s32 D_80802588_chchuffy[];
extern s32 D_80802594_chchuffy[];
extern s16 D_8080247E_chchuffy[][4];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_808025A0_chchuffy;
typedef struct { u8 pad[0x7C]; u32 pad7C:19; u32 flag:1; u32 rest:12; } ChuffyS;
extern s32 D_808025E4_chchuffy;
extern u8 D_80802630_chchuffy[];
typedef struct { u8 pad_0[0x14]; f32 local_0[3]; u8 pad_1[0x1C]; f32 local_1; } ChuffySound1590;
extern s16 D_8080267C_chchuffy[];
extern s32 func_800C4350();
extern void func_800C3058(s32, s32);
extern s32 D_80802690_chchuffy;
extern u8 D_808023DC_chchuffy[];
extern u8 D_808026A4_chchuffy[];
extern void func_800EF1B8(f32 *, f32, u32);
extern f32 D_808026AC_chchuffy[3];
extern f32 D_808026B0_chchuffy;
extern f32 D_808026B8_chchuffy[3];
extern f32 D_808026BC_chchuffy;
extern f32 D_808026C4_chchuffy[3];
extern f32 D_808026D0_chchuffy[3];
extern f32 D_808026DC_chchuffy[3];
extern f32 D_808026E8_chchuffy[3];
extern s32 func_800F0064(f32 *, f32, f32 *);
extern void func_800F7F00(s32, f32 *, f32 *, f32, s32, s32, f32);
extern int D_808026F4_chchuffy;
typedef struct { u8 pad_0[0x14]; f32 origin[3]; u8 pad_1[0x44]; f32 positions[20][3]; f32 velocities[10][3]; f32 acceleration[10][3]; f32 strength[10]; u8 frame[10]; u8 pad_2[6]; s32 color[10]; } ChuffySmokeVectors;
extern f32 func_800DC178(f32, f32);
typedef struct { u8 pad0[0x14]; f32 unk14[3]; u8 pad20[0x18]; f32 unk38; f32 unk3C; u8 pad40[0x24]; f32 pos[10][3]; /* 0x064 */ f32 out[10][3]; /* 0x0DC */ f32 vel[10][3]; /* 0x154 */ f32 rise[10][3]; /* 0x1D0 */ f32 scale[10]; /* 0x244 */ s32 pad26C[3]; f32 unk278; s32 timer[10]; /* 0x27C */ } ChuffySmoke;
extern f32 func_800D8FF8(void);
extern void func_800EFD24(f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern s32 D_80802320_chchuffy;
extern s32 D_80802334_chchuffy;
extern s32 D_80802348_chchuffy;
extern s32 D_8080235C_chchuffy;
extern s32 D_80802374_chchuffy;
extern void _chchuffyglow_entrypoint_0(void);
extern void func_800E1610(s32, f32, f32, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800DC0C0(void);
extern f32 _sumumbofx_entrypoint_22(void *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, void *, void *, f32);
extern u8 D_8080238C_chchuffy[];
extern u8 D_808023A0_chchuffy[];
extern u8 D_808023C8_chchuffy[];
extern u8 D_808024D0_chchuffy[];
extern u8 D_808024E8_chchuffy[];
extern s32 func_80102320(Actor *, f32, f32);
extern s32 D_80802534_chchuffy[];
extern s32 D_808024FC_chchuffy[];
extern void func_80102424(Actor *, s32);
void func_808013E8_chchuffy();
void func_80802060_chchuffy();
void func_80800410_chchuffy();
void func_80800FBC_chchuffy();
void func_8080115C_chchuffy();
void func_808017D4_chchuffy();

int chchuffy_entrypoint_0()
{
    return (int)&D_80802434_chchuffy;
}

s32 func_8080000C_chchuffy(s32 param_0)
{
    u32 local_0;
    u32 local_3;
    u32 local_1;
    u32 local_2;
    u32 local_4;

    local_0 = D_808024B4_chchuffy[param_0];
    local_1 = (local_0 & 0xFFFF) + 0xB0000000;
    local_2 = (local_0 & 0xFFFF0000) >> 16;
    local_0 = 0;
    if (local_1 & 2) {
        rom_read_word((local_1 >> 2) << 2, &local_3);
        local_4 = (local_3 & 0xFFFF0000) >> 16;
        local_0 += local_4;
    } else {
        rom_read_word(local_1, &local_3);
        local_4 = local_3 & 0xFFFF;
        local_0 += local_4;
    }
    if (local_2) {
        local_2 += 0xB0000000;
        if (local_2 & 2) {
            local_2 = (local_2 >> 2) << 2;
            rom_read_word(local_2, &local_3);
            local_0 += (local_3 & 0xFFFF0000) >> 16;
        } else {
            rom_read_word(local_2, &local_3);
            local_0 += local_3 & 0xFFFF;
        }
    }
    return local_0 + 0xA0;
}

int func_80800110_chchuffy(s32 param_0)
{
  u32 local_2;
  s16 *local_0;
  s32 local_1;
  switch (param_0)
  {
    case 4:
      local_1 = func_800EA05C();
      for (local_2 = 0; local_2 < 7; local_2++)
    {
      if (func_8080000C_chchuffy(local_2) == local_1)
      {
        break;
      }
    }

      break;

    case 0:

    case 1:
      local_0 = (s16 *) (((u8 *) D_8080247C_chchuffy) + (param_0 * 2));
      for (local_2 = 0; local_2 < 7; local_2++, local_0 += 4)
    {
      if (func_800DA298(*local_0))
      {
        break;
      }
    }

      break;

  }

  if (local_2 >= 7)
  {
    return -1;
  }
  return local_2;
}

void func_808001DC_chchuffy(void) {
    s32 *local_0;
    s32 local_1;
    s32 local_2;

    local_1 = func_800EA05C();
    local_0 = (s32 *)D_8080247C_chchuffy;
    local_2 = 0;
    do {
        if (func_8080000C_chchuffy(local_2) == local_1) {
            func_800DA544((*(s16 *)((s8 *)(local_0) + (0))));
            func_800DA524((*(s16 *)((s8 *)(local_0) + (2))));
        } else {
            func_800DA524((*(s16 *)((s8 *)(local_0) + (0))));
        }
        local_2 += 1;
        local_0 += 2;
    } while (local_2 != 7);
}

int func_80800264_chchuffy(void)
{
  s32 local_0;
  s32 local_1;

  local_1 = func_800EA05C();
  for (local_0 = 0; local_0 < 7; local_0++) {
    if (func_8080000C_chchuffy(local_0) != local_1) {
      if (func_800DA298(D_8080247C_chchuffy[local_0][1])) {
        return 1;
      }
    }
  }
  return 0;
}

s32 chchuffy_entrypoint_1(s32 param_0, f32 *param_1, f32 *param_2)
{
    Actor *local_0;
    s32 local_1;

    local_0 = func_80106790(param_0);
    local_1 = (s32)func_80100094(local_0, 0);
    func_800EE7F8(param_1, (f32 *)(local_1 + 0x4C));
    param_2[0] = 90.0f - func_800F1828((f32 *)(local_1 + 0x4C), (f32 *)(local_1 + 0x58));
    param_2[1] = func_800F1DF4((f32 *)(local_1 + 0x4C), (f32 *)(local_1 + 0x58));
    param_2[2] = 0.0f;
    if ((s32)local_0->unk70_10 < 4) {
        return 1;
    }
    return 0;
}

void func_80800398_chchuffy(Actor *param_0)
{
    ChuffyPositionData *local_0;
    f32 local_1[3];
    local_0 = func_80100094(param_0, 0);
    local_1[0] = 90.0f - func_800F1828(local_0->local_0, local_0->local_1);
    local_1[1] = func_800F1DF4(local_0->local_0, local_0->local_1);
    local_1[2] = 0.0f;
    func_808013E8_chchuffy(param_0, local_0->local_0, local_1);
}

void func_80800410_chchuffy(param_0, param_1) Actor *param_0; s32 param_1;
{
    ChuffySmokeVectors *local_0;
    local_0 = (ChuffySmokeVectors *)func_80100094(param_0, 0);
    local_0->velocities[param_1][0] = func_800DC178(-13.0f, 13.0f);
    local_0->velocities[param_1][1] = func_800DC178(10.0f, 20.0f);
    local_0->velocities[param_1][2] = func_800DC178(-13.0f, 13.0f);
    local_0->acceleration[param_1][1] = func_800DC178(250.0f, 450.0f);
    func_800EE7F8(local_0->positions[param_1], local_0->origin);
    local_0->positions[param_1][2] += 25.0f;
    local_0->strength[param_1] = func_800DC178(0.2f, 0.4f);
    local_0->color[param_1] = func_800DC128(185, 250);
    local_0->frame[param_1] = func_800DC128(0, 6);
}

void func_80800524_chchuffy(Actor *param_0)
{
    ChuffyInitData *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_0->local_0 = 0x9DD;
    for (local_1 = 0; local_1 < 10; local_1++) {
        func_80800410_chchuffy(param_0, local_1);
    }
    ((ChuffyPropFlags *)param_0->unk0->unk0)->local_0 = 3;
}

void func_8080059C_chchuffy(Actor *param_0)
{
    f32 local_0;
    ChuffySmoke *local_1;
    s32 local_2;

    local_0 = func_800D8FF8();
    local_1 = func_80100094(param_0, 0);
    for (local_2 = 0; local_2 != 10; local_2++) {
        if (local_1->timer[local_2] < 10) {
            if (0.0f < local_1->unk278) {
                func_80800410_chchuffy(param_0, local_2);
            } else {
                local_1->rise[local_2][1] = 0.0f;
                func_800EFD24(local_1->vel[local_2]);
                func_800EE7F8(local_1->pos[local_2], local_1->unk14);
                local_1->scale[local_2] = 0.0f;
            }
        }
        if (local_1->timer[local_2] >= 0x3D) {
            local_1->scale[local_2] += 0.12f;
        } else {
            local_1->rise[local_2][1] -= 10.0f;
            local_1->scale[local_2] *= 0.9f;
        }
        local_1->timer[local_2] -= func_800DC128(6, 12);
        local_1->vel[local_2][0] += local_1->rise[local_2][1] * local_0;
        local_1->vel[local_2][1] *= 1.1f;
        local_1->vel[local_2][2] *= 1.1f;
        func_800EE780(local_1->out[local_2], local_1->pos[local_2], local_1->vel[local_2]);
    }
    if (0.0f < local_1->unk38) {
        func_80800410_chchuffy(param_0, param_0->unk6C_0);
        param_0->unk6C_0++;
        if (param_0->unk6C_0 == 10) {
            local_1->unk278 = 0.2f;
            param_0->unk6C_0 = 0;
        }
        local_1->unk3C = func_800DC178(27000.0f, 30000.0f);
    } else {
        local_1->unk278 -= func_800D8FF8();
    }
}

void func_80800818_chchuffy(FarmerState *param_0, s32 param_1, s32 param_2) {
    param_2 |= 4;
    _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, &param_0->f4, 0x6f);
    param_0->flag = 1;
}

int func_80800864_chchuffy(Actor *param_0, s32 param_1, void *param_2)
{
    Actor *local_0;

    switch (param_1) {
    case 0x3D:
        local_0 = func_801084B0(0x316, &param_0);
        *(s32 *)((u8 *)param_0 + 0x3C) = (s32)local_0->unk0;
        *(s32 *)((u8 *)local_0 + 0x3C) = (s32)param_0->unk0;
        break;
    case 0x3E:
        if (*(s32 *)((u8 *)param_0 + 0x3C)) {
            local_0 = func_80106790(*(s32 *)((u8 *)param_0 + 0x3C));
            if ((*(u32 *)((u8 *)param_2 + 0x24) >> 22) == 0) {
                switch ((*(u32 *)((u8 *)param_0->unk0 + 0x18) << 11) >> 28) {
                case 1:
                    local_0->unk64_20 = 1;
                    if (func_80090178(1)) _gcsectionskip_entrypoint_1(0, 0, 0, 1, 0);
                    else if (!param_0->unk74_30) func_80800818_chchuffy(param_0, 0x121E, 0);
                    break;
                case 2:
                    local_0->unk64_19 = 1;
                    if (func_80090178(-1)) _gcsectionskip_entrypoint_1(0, 0, 0, 2, 0);
                    break;
                }
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808016D0_chchuffy();

void func_8080130C_chchuffy();

void func_808009CC_chchuffy(Actor *param_0)
{
    u8 *local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(0x9DE)) {
            func_800DA3B8(0x9DE, 0);
            _capod_entrypoint_13(param_0->unk0, 0, 0, 0);
            func_80090734(2, local_0 + 0x2C);
            func_8080130C_chchuffy(param_0);
            func_808017D4_chchuffy(param_0, 2);
            *(f32 *)(local_0 + 4) = 0.0f;
            _chbaddiesetup_entrypoint_1(_chchuffyglow_entrypoint_0, param_0->unk0);
        }
        break;
    case 2:
        func_80800398_chchuffy(param_0);
        break;
    case 3:
        func_80800398_chchuffy(param_0);
        func_800DA544(0x95);
        func_800DA544(0x4ED);
        local_1 = func_80106790((s32)param_0->unk3C);
        func_80103140(local_1, 0x87A, local_1->unk0->unk16);
        func_8010A590(local_1);
        if (func_80101E14(param_0, 0.73f) || func_80101E14(param_0, 0.75f)) {
            func_800E1610(2, 100.0f, 0.65f, (f32 *)(local_0 + 0x20));
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802320_chchuffy);
        }
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80802334_chchuffy, 0.9f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80802348_chchuffy, 0.95f);
        if (func_80101F24(param_0) < 0.1f) {
            if (func_800DC0C0() < 0.04f) {
                _subaddieaudioquick_entrypoint_2(param_0, (f32 *)(local_0 + 0x4C), &D_8080235C_chchuffy);
            }
        } else if (func_80101F24(param_0) < 0.95f && func_800DC0C0() < 0.04f) {
            _subaddieaudioquick_entrypoint_2(param_0, (f32 *)(local_0 + 0x4C), &D_80802374_chchuffy);
        }
        if (func_80101E14(param_0, 0.95f)) {
            func_800DA3B8(0x9DF, 1);
        }
        break;
    case 4:
        func_80800398_chchuffy(param_0);
        if (_sumumbofx_entrypoint_22(func_80100094(param_0, 1)) < 0.05f) {
            _sumumbofx_entrypoint_1(param_0, 1);
            func_808017D4_chchuffy(param_0, 5);
        }
    case 5:
        if (*(f32 *)(local_0 + 4) < 20000.0f) {
            *(f32 *)(local_0 + 4) = *(f32 *)(local_0 + 4) + 250.0f;
        }
        break;
    case 6:
        if (*(f32 *)(local_0 + 0x38) <= 0.0f) {
            func_808017D4_chchuffy(param_0, 7);
        }
        break;
    case 7:
        if (*(f32 *)(local_0 + 4) > 10000.0f) {
            *(f32 *)(local_0 + 4) = *(f32 *)(local_0 + 4) - 250.0f;
        }
        if (func_80101DDC(param_0)) {
            func_800DA3B8(0x66B, 1);
            if (func_800DA298(0x6B7)) {
                _glcutDll_entrypoint_17();
                _capod_entrypoint_14();
            } else {
                _glcutDll_entrypoint_24(func_8080000C_chchuffy(func_80800110_chchuffy(1)), -1, 0x70);
                func_800FE844(0);
                func_800FE734(0);
            }
        }
        break;
    case 8:
        if (func_80101F24(param_0) > 0.75f) {
            if (*(f32 *)(local_0 + 4) < 20000.0f) {
                *(f32 *)(local_0 + 4) = *(f32 *)(local_0 + 4) + 250.0f;
            }
        }
        if (param_0->unk74_30) {
            if (param_0->unk58 > 0.0f) {
                param_0->unk58 -= func_800D8FF8();
            } else {
                if (!func_808016D0_chchuffy(param_0)) {
                    _glcutDll_entrypoint_17();
                    _capod_entrypoint_14();
                }
                func_808017D4_chchuffy(param_0, 5);
            }
        } else if (func_80101DDC(param_0)) {
            param_0->unk74_30 = 1;
            param_0->unk58 = 2.0f;
        }
        break;
    }
    switch (func_801022E4(param_0)) {
    case 0x99:
        func_8080115C_chchuffy(param_0);
        break;
    case 0x9A:
        func_80800FBC_chchuffy(param_0);
        break;
    }
    *(f32 *)(local_0 + 0x38) -= func_800D8FF8();
}

void func_80800EF4_chchuffy(s32 *param_0) {
    s32 local_0;

    local_0 = func_80800110_chchuffy(4);
    if (*(s16 *)((char *)&D_8080247C_chchuffy + (local_0 * 8) + 4) != -1) {
        _capod_entrypoint_13(*param_0, 0, *(s16 *)((char *)&D_8080247C_chchuffy + (local_0 * 8) + 4), 0x2830);
    }
}

void func_80800F54_chchuffy(s32 *param_0)
{
  s32 local_0;
  local_0 = func_80800110_chchuffy(4);
  if (D_8080247C_chchuffy[local_0][3] != -1)
  {
    _capod_entrypoint_13(*param_0, 0, D_8080247C_chchuffy[local_0][3], 0x2830);
    _chintrotext_entrypoint_2(1);
  }
}

void func_80801EAC_chchuffy();

void func_80801DDC_chchuffy();

void func_80801D94_chchuffy();

void func_80801D3C_chchuffy();

void func_80801CF8_chchuffy();

void func_80800FBC_chchuffy(param_0) Actor *param_0;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (func_800DC0C0() < 0.25f) { func_80801D3C_chchuffy(param_0, 1); }
    func_8080059C_chchuffy(param_0);
    if (func_80102320(param_0, 0.65f, 0.72f)) { func_80801EAC_chchuffy(param_0); }
    func_80801F04_chchuffy(param_0);
    func_80801DDC_chchuffy(param_0);
    if (func_80101E4C(param_0, D_808024D0_chchuffy)) {
        _subaddieaudioquick_entrypoint_2(param_0, local_0 + 8, D_8080238C_chchuffy);
        func_80801D94_chchuffy(param_0, 5);
        *(f32 *)(local_0 + 0x38) = 0.3f;
    }
    if (func_80101E4C(param_0, D_808024E8_chchuffy)) {
        _subaddieaudioquick_entrypoint_2(param_0, local_0 + 8, D_8080238C_chchuffy);
    }
    if (func_80101E14(param_0, 0.925f) || func_80101E14(param_0, 0.965f)) {
        _subaddieaudioquick_entrypoint_2(param_0, local_0 + 0x2C, D_808023A0_chchuffy);
        func_80801CF8_chchuffy(param_0, 5);
    }
    if (func_80101E14(param_0, 0.7f)) { *(f32 *)(local_0 + 0x38) = 3.0f; }
    _subaddieaudioquick_entrypoint_3(param_0, local_0 + 0x4C, D_808023C8_chchuffy, 0.88f);
}

void func_8080115C_chchuffy(param_0) Actor *param_0; {
    u8 *sp24;

    sp24 = func_80100094(param_0, 0);
    if (func_800DC0C0() < 0.25f) {
        func_80801D3C_chchuffy(param_0, 1);
    }
    func_80801F04_chchuffy(param_0);
    func_8080059C_chchuffy(param_0);
    if (((u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA) != 5) {
        if (func_80102320(param_0, 0.21f, 0.31f) != 0) {
            func_80801EAC_chchuffy(param_0);
        }
        func_80801DDC_chchuffy(param_0);
        if (func_80101E4C(param_0, &D_808024FC_chchuffy) != 0) {
            _subaddieaudioquick_entrypoint_2(param_0, sp24 + 8, &D_8080238C_chchuffy);
            func_80801D94_chchuffy(param_0, 5);
            (*(f32 *)((s8 *)(sp24) + (0x38))) = 0.3f;
        }
        if (func_80101E4C(param_0, &D_80802534_chchuffy) != 0) {
            _subaddieaudioquick_entrypoint_2(param_0, sp24 + 8, &D_8080238C_chchuffy);
        }
        if ((func_80101E14(param_0, 0.02f) != 0) || (func_80101E14(param_0, 0.035f) != 0)) {
            _subaddieaudioquick_entrypoint_2(param_0, sp24 + 0x2C, &D_808023A0_chchuffy);
            func_80801CF8_chchuffy(param_0, 5);
        }
        if ((func_80101E14(param_0, 0.59f) != 0) || (func_80101E14(param_0, 0.49f) != 0)) {
            _subaddieaudioquick_entrypoint_2(param_0, sp24 + 0x20, &D_808023C8_chchuffy);
        }
    }
}

void func_8080130C_chchuffy(Actor *param_0)
{
    void *local_0;
    ChuffyEffectPair local_1;
    ChuffyEffectVector local_2;
    ChuffyEffectVector local_3;
    _sumumbofx_entrypoint_0(param_0, 1, 0x41, (s16)_chmumbopad_entrypoint_0(0));
    local_0 = func_80100094(param_0, 1);
    _sumumbofx_entrypoint_2(local_0);
    _sumumbofx_entrypoint_24(local_0, 2.25f);
    _sumumbofx_entrypoint_15(local_0, 3.0f);
    local_1 = *(ChuffyEffectPair *)D_80802568_chchuffy;
    local_2 = *(ChuffyEffectVector *)D_80802570_chchuffy;
    local_3 = *(ChuffyEffectVector *)D_8080257C_chchuffy;
    _sumumbofx_entrypoint_12(local_0, &local_2, &local_1, &local_3);
}

void func_808013E8_chchuffy(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, void *, s32, s32);
    extern s32 _sumumbofx_entrypoint_5(void *, f32);
    extern void _sumumbofx_entrypoint_18(void *, f32);
    extern void _sumumbofx_entrypoint_16(void *, f32);
    extern void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 func_80101E14(Actor *, f32);
    void *local_0;
    ChuffyEffectVector local_1;
    ChuffyEffectVector local_2;
    f32 local_3[3];
    f32 local_4[3];
    local_0 = func_80100094(param_0, 1);
    local_1 = *(ChuffyEffectVector *)D_80802588_chchuffy;
    local_2 = *(ChuffyEffectVector *)D_80802594_chchuffy;
    func_8010D254(local_3);
    func_800EFA4C(local_1.local_0, 0.0f, -675.0f, -155.0f);
    _sumumbofx_entrypoint_6(local_0, 700.0f, 300.0f, 0, 20, &local_1, param_1, param_2);
    func_800EFD24(&local_1);
    _sumumbofx_entrypoint_6(local_0, 900.0f, 150.0f, 20, 45, &local_1, param_1, param_2);
    func_800EFA4C(local_1.local_0, 160.0f, -150.0f, 260.0f);
    _sumumbofx_entrypoint_6(local_0, 750.0f, 45.0f, 45, 55, &local_1, param_1, param_2);
    func_800EFA4C(local_1.local_0, 160.0f, 650.0f, 235.0f);
    _sumumbofx_entrypoint_6(local_0, 275.0f, 90.0f, 55, 65, &local_1, param_1, param_2);
    switch (param_0->unk70_10) {
    case 2:
        if (_sumumbofx_entrypoint_27(local_0) && _sumumbofx_entrypoint_5(local_0, 4.6f)) {
            _sumumbofx_entrypoint_18(local_0, 4.0f);
            func_808017D4_chchuffy(param_0, 3);
        }
        break;
    case 3:
        if (func_80101E14(param_0, 0.8f)) {
            _chglowbo_entrypoint_6();
        }
        if (func_80101DDC(param_0)) {
            _sumumbofx_entrypoint_16(local_0, 2.0f);
            func_808017D4_chchuffy(param_0, 4);
            func_80090708(0);
        }
        break;
    }
    func_800EE7F8(local_4, (u8 *)param_0 + 0x18);
    local_4[1] += 500.0f;
    _sumumbofx_entrypoint_11(local_0, local_4);
    _sumumbofx_entrypoint_14(local_0);
}

void func_8080167C_chchuffy(s32 *param_0)
{
  if (_glcutDll_entrypoint_19(0x72))
  {
    _capod_entrypoint_14();
    func_800D9290();
    _glcutDll_entrypoint_21();
  }
  else
  {
    *param_0 = 0xD0;
  }
}

s32 func_808016D0_chchuffy(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800EA05C();
    switch (local_0) {
        case 0xEC:
            if (func_800DA298(0x98) && !func_800DA298(0x588) && !func_800DA298(0x8A)) {
                func_8080167C_chchuffy(&local_0);
                _glcutDll_entrypoint_24(0xEA, local_0, 0x1F);
                return 1;
            }
            break;
        case 0x114:
            if (func_800DA298(0x588)) {
                func_8080167C_chchuffy(&local_0);
                _glcutDll_entrypoint_24(0x114, -1, 0x35);
                return 1;
            } else if (func_800DA298(0x189) && func_800DA298(0x15E)) {
                func_8080167C_chchuffy(&local_0);
                _glcutDll_entrypoint_24(0x114, -1, 0x38);
                return 1;
            }
            break;
    }
    return 0;
}

void func_808017D4_chchuffy(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    u32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 5) {
        func_8010A570(param_0);
    }
    func_80102424(param_0, param_1);
    local_1 = param_0->unk70_10;
    switch (local_1) {
        case 6:
            func_80800EF4_chchuffy(param_0);
            *(f32 *)(local_0 + 0x38) = 1.2f;
            break;
        case 8:
            func_800DA3B8(0x6E4, func_800DA298(0x6B7));
            if (func_800DA9E4(0x6B7, 0)) {
                _glcutDll_entrypoint_6(func_800EA05C(), 0x72);
            }
            param_0->unk74_30 = 0;
            func_80800F54_chchuffy(param_0);
            func_808001DC_chchuffy();
            break;
        case 5:
            func_8010A590(param_0);
            break;
        case 1:
            func_8010A590(param_0);
            break;
    }
}

void func_808018F8_chchuffy(Actor *param_0)
{
    s32 local_0;

    local_0 = func_80800110_chchuffy(4);
    if (func_800DA298(((s16 (*)[4])D_8080247C_chchuffy)[local_0][0])) {
        if (func_80800264_chchuffy()) {
            func_808017D4_chchuffy(param_0, 6);
        } else {
            func_808017D4_chchuffy(param_0, 5);
        }
    } else if (func_800DA298(D_8080247E_chchuffy[local_0][0])) {
        func_808017D4_chchuffy(param_0, 8);
    } else {
        func_800FFAB0(param_0);
    }
}

void func_808019A4_chchuffy(Actor *param_0, s32 param_1)
{
  u8 *new_var2;
  int new_var;
  u8 *local_0;
  f32 local_1[3];
  u8 *local_2;
  u8 *local_3;
  f32 *local_4;
  s32 local_5;
  s32 local_6;
  local_0 = func_80100094(param_0, 0);
  func_800EFD24(param_0->position);
  if (func_80100094(param_0, 1) != 0)
  {
    local_6 = _sumumbofx_entrypoint_10(func_80100094(param_0, 1));
    func_800DF5D8(local_6, 255, local_6, 255);
  }
  func_80101870(param_0, param_1);
  new_var2 = local_0 + 8;
  func_800DBEFC(*((s32 *) (((u8 *) param_0->unk0) + 4)), 7, local_0 + 0x14);
  func_800DBEFC(*((s32 *) (((u8 *) param_0->unk0) + 4)), 5, new_var2);
  func_800DBEFC(*((s32 *) (((u8 *) param_0->unk0) + 4)), 8, local_0 + 0x20);
  func_800DBEFC(*((s32 *) (((u8 *) param_0->unk0) + 4)), 4, local_0 + 0x2C);
  func_800DBEFC(*((s32 *) (((u8 *) param_0->unk0) + 4)), 10, local_0 + 0x4C);
  func_800DBEFC(*((s32 *) (((u8 *) param_0->unk0) + 4)), 9, local_0 + 0x58);
  if (func_80100094(param_0, 1) != 0)
  {
    _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
  }
  if (((s32) param_0->unk70_10) >= 6)
  {
    func_800E2588(1);
    func_800E2594(param_1, func_800D674C(*((s32 *) (local_0 + 0x2A8))));
    local_2 = local_0;
    local_3 = local_0;
 local_5 = 0; local_4 = (f32 *) (local_0 + 0xDC); for (; local_5 != 0x78; local_5 += 12, local_2 += 4, local_3++, local_4 += 3) {
      local_1[0] = *((f32 *) (local_2 + 0x244));
      new_var = 0x244;
      local_1[1] = *((f32 *) (local_2 + new_var));
      local_1[2] = *((f32 *) (local_2 + new_var));
      func_800E2720(param_1, local_3[0x26C], 0, local_4, local_1, *((s32 *) (local_2 + 0x27C)));
    }

    func_800E2A14(param_1);
  }
}

void func_80801B8C_chchuffy(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0[1] = 0;
    *(f32 *)(local_0 + 0x3C) = 0.0f;
    *(f32 *)(local_0 + 4) = 20000.0f;
    local_0[0] = 0;
    *(f32 *)(local_0 + 0x48) = 1.0f;
    func_80800524_chchuffy(param_0);
    if (func_800EA05C() == 0xD7) {
        if (func_80800110_chchuffy(0) == -1) {
            if (!func_800DA298(0x95)) {
                func_808017D4_chchuffy(param_0, 1);
            } else {
                func_808017D4_chchuffy(param_0, 5);
            }
        } else {
            func_808018F8_chchuffy(param_0);
        }
    } else {
        func_808018F8_chchuffy(param_0);
    }
    if (!param_0->unk64_17) {
        func_80108B04(param_0, 0);
    }
}

void func_80801C78_chchuffy(s32 param_0)
{
  u8 *local_0;
  local_0 = func_80100094(param_0, 0);
  {
    if ((*local_0) != 0)
    {
      func_800C2FDC(*local_0);
      *local_0 = 0;
    }
    if (local_0[1] != 0)
    {
      func_800C2FDC(local_0[1]);
      local_0[1] = 0;
    }
  }
  if (func_80100094(param_0, 1) != 0)
  {
    _sumumbofx_entrypoint_1(param_0, 1);
  }
}

void func_80801CF8_chchuffy(s32 unused, s32 param_1) {
    func_800BBCB8((f32 *)((u8 *)func_80100094((Actor *)unused, 0) + 0x2C), 0, 1.0f, param_1, &D_808025A0_chchuffy);
}

void func_80801D3C_chchuffy(ChuffyS *param_0, s32 param_1) {
    u8 *local_0 = (u8 *)func_80100094((Actor *)param_0, 0) + 8;
    if (param_0->flag) {
        func_800BBCB8((f32 *)local_0, 0, 1.0f, param_1, &D_808025E4_chchuffy);
    }
}

void func_80801D94_chchuffy(Actor *param_0, s32 param_1)
{
    func_800BBCB8((u8 *)func_80100094((*(Actor * *)&param_0), 0) + 8, 0, 1.0f, param_1, D_80802630_chchuffy);
}

void func_80801DDC_chchuffy(Actor *param_0)
{
    ChuffySound1590 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk5F == 0) param_0->unk5F = func_800C4350(0, local_0->local_0, D_8080267C_chchuffy);
    else {
        if (local_0->local_1 > 2000.0f && param_0->unk7C_12) {
            func_800C3058(param_0->unk5F, (s32)local_0->local_1);
            func_800C4350(param_0->unk5F, local_0->local_0, NULL);
        }
        local_0->local_1 -= 1000.0f;
    }
}

void func_80801EAC_chchuffy(u8 *param_0) {
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    *local_0 = _subaddieaudioloop_entrypoint_7(*local_1, local_1 + 0x20, 1, &D_80802690_chchuffy, (*(s32 *)((s8 *)(param_0) + (0x70))) & 1);
}

int func_80801F04_chchuffy(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0[1] == 0) {
        local_0[1] = func_800C4350(0, local_0 + 0x20, D_808023DC_chchuffy);
    } else {
        func_800C3058(local_0[1], (s32)*(f32 *)(local_0 + 4));
        func_800C4350(local_0[1], local_0 + 0x20, 0);
    }
}

s32 func_80801F84_chchuffy(s32 param_0){
    func_800EFD24(param_0 + 4);
}

s32 func_80801FA4_chchuffy(Actor *param_0, s32 param_1, Unk80132ED0 *param_2)
{
    s32 local_0;

    switch (param_1) {
    case 0x95:
        local_0 = func_800DA298(0x95) ? 0x87A : 0x879;
        func_80103140(param_0, (u16)local_0, param_0->unk0->unk16);
        func_8010A5B0(param_0, func_800DA298(0x95));
        break;
    case 0x2E:
        param_0->unk74_30 = 0;
        break;
    case 0x3E:
        func_80802060_chchuffy(param_0, (*(Unk80132ED0 * *)&param_2));
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80802060_chchuffy(param_0, param_1) u8 *param_0; u8 *param_1; {
    s32 temp_v0;
    f32 local_38[3];
    f32 local_2C[3];
    u32 local_28;
    f32 local_1C[3];

    local_28 = (u32) (*(u16 *)((u8 *)param_1 + 0x1A)) >> 5;
    if ((func_800F6C5C(local_28) != 0) && (func_800F55D0(local_28) == (*(s32 *)((u8 *)param_0 + 0)))) {
        func_800F5A00(local_28, local_38);
        temp_v0 = _gccubesearch_entrypoint_6(&D_808026A4_chchuffy, local_38);
        if (temp_v0 != 0) {
            _gspropctrl_entrypoint_11(temp_v0, local_2C);
        } else {
            chchuffy_entrypoint_1((*(s32 *)((u8 *)param_0 + 0x3C)), local_2C, local_1C);
            if (local_38[2] < local_2C[2]) {
                func_800EF1B8(local_2C, (*(f32 *)((u8 *)param_0 + 0x48)) - 180.0f, (u32)0x43FA0000);
            } else {
                func_800EF1B8(local_2C, (*(f32 *)((u8 *)param_0 + 0x48)), (u32)0x43FA0000);
            }
            local_2C[0] = local_38[0];
        }
        func_800F77E8(local_28, local_2C);
    }
}

void func_80802164_chchuffy(Actor *param_0)
{
    f32 local_0[3];

    func_8010A654(param_0, func_800DB9B0() == 0);
    if (func_800DA298(0x95)) {
        func_8010D254(local_0);
        if (func_800F0064(local_0, 130.0f, D_808026AC_chchuffy) &&
            D_808026B0_chchuffy < local_0[1] && local_0[1] <= D_808026BC_chchuffy) {
            func_800F7F00(func_800F54E4(), D_808026AC_chchuffy, D_808026B8_chchuffy, 80.0f, 2, 2, 0.0f);
        }
        if (param_0->unk64_20 && !func_80090178(1)) {
            func_8008FA94(D_808026C4_chchuffy, D_808026D0_chchuffy);
        }
        if (param_0->unk64_19 && !func_80090178(-1)) {
            func_8008FA94(D_808026DC_chchuffy, D_808026E8_chchuffy);
        }
    }
}

int *chchuffy_entrypoint_2()
{
    return &D_808026F4_chchuffy;
}
