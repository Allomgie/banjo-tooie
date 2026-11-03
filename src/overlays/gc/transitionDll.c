#include "common.h"

extern int D_80800CB0_gctransitionDll[];
extern int D_8080105C_gctransitionDll[];
extern f32 func_800A8AF0(s32);
typedef struct { u8 pad_0[4]; s32 local_0; u8 pad_1[0x14]; u8 local_1; } TransitionQueryState;
typedef struct { u8 a; u8 b; u8 pad[18]; } TransEntry;
extern TransEntry D_80800EA4_gctransitionDll[];
typedef struct { u32 w0, w1; } GfxW;
typedef struct { u8 pad0[0x18]; f32 unk18; } TransS18;
extern void func_800E41CC(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFD24(f32 *);
extern void func_800E3C8C(f32, f32);
extern void func_800E3BAC(f32 *);
extern void func_800E3C30(f32 *);
extern void func_800E3CE8(void);
extern void func_800E44FC(void *);
extern void func_8008B304(s32);
extern s32 func_8008B4D4(s32);
extern void func_800DF41C(s32);
extern void func_800DF830(s32);
extern s32 func_800D674C(s32);
extern s32 func_800DE448(f32 *, f32 *, f32, s32, s32);
extern void func_800B99CC();
extern void func_800E4208(void);
extern f32 func_800F1480(f32);
extern s32 func_800DE318(void);
extern u8 D_808010CC_gctransitionDll[];
extern u8 D_808010D8_gctransitionDll[];
extern f32 D_808010E4_gctransitionDll;
extern f32 D_808010E8_gctransitionDll;
extern f32 R_80800C80_gctransitionDll;
extern f32 R_80800C84_gctransitionDll;
extern f32 R_80800C88_gctransitionDll;
extern f32 R_80800C8C_gctransitionDll;
extern f32 R_80800C90_gctransitionDll;
typedef struct { u8 local_0[8]; u8 local_1; u8 local_2; u8 local_3; u8 local_4; f32 local_5; u8 local_6[12]; u8 local_7; u8 local_8; u8 local_9[6]; f32 local_10; f32 local_11; void *local_12; u32 local_13; } Transition49;
extern f32 _glintrosyncDll_entrypoint_5(void);
extern f32 func_800D8FF8(void);

int func_80800000_gctransitionDll(param_0) int param_0;
{
  s32 local_0;
  u8 *local_1 = &D_80800CB0_gctransitionDll[0];
  if ((*local_1) != 0)
  {
    do
    {
      if (param_0 == (*local_1))
      {
        return local_1;
      }
      local_1 += 0x14;
    }
    while (*local_1);
  }
  return 0;
}

int func_8080004C_gctransitionDll(unsigned long param_0)
{
  u16 *local_0;
  int new_var;
  int *new_var2;
  new_var2 = &D_8080105C_gctransitionDll[0];
  local_0 = new_var2;
  while ((*local_0) != 0)
  {
    ;
    if ((*local_0) == param_0)
    {
      return local_0;
    }
    local_0 += 2;
  }

  return local_0;
}

void func_80800098_gctransitionDll(s32 *param_0, f32 *param_1) {
    *param_1 *= func_800A8AF0(*param_0) * 0.75f;
}

void func_808000D8_gctransitionDll(u8 *param_0, s32 param_1, u8 *param_2) {
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_a3 = (*(s32 *)((s8 *)(param_0) + (0x2C)));
    if (temp_a3 != 0) {
        func_8008ADBC(temp_a3);
        (*(s32 *)((s8 *)(param_0) + (0x2C))) = 0;
    }
    (*(s32 *)((s8 *)(param_0) + (4))) = 0;
    (*(f32 *)((s8 *)(param_0) + (0x28))) = 0.0f;
    if (param_2 != NULL) {
        aligned4_memcpy(param_0 + 8, param_2, 0x14);
    } else {
        (*(u8 *)((s8 *)(param_0) + (8))) = 0U;
    }
    if (param_1 == 2) {
        (*(s32 *)((s8 *)(param_0) + (0x20))) = 0xB45;
    } else if (param_1 == 7) {
        (*(s32 *)((s8 *)(param_0) + (0x20))) = 0xB46;
    } else if (param_2 != NULL) {
        temp_v0 = (*(s32 *)((s8 *)(param_2) + (8)));
        if (temp_v0 != 0) {
            (*(s32 *)((s8 *)(param_0) + (0x20))) = temp_v0;
        }
    }
    if ((param_2 != NULL) && ((*(s32 *)((s8 *)(param_2) + (0xC))) != 0)) {
        temp_v0_2 = func_8008AD80(0);
        (*(s32 *)((s8 *)(param_0) + (0x2C))) = temp_v0_2;
        anctrl_reset(temp_v0_2);
        anctrl_setIndex((*(s32 *)((s8 *)(param_0) + (0x2C))), (*(s32 *)((s8 *)(param_2) + (0xC))));
        anctrl_setDuration((*(s32 *)((s8 *)(param_0) + (0x2C))), (*(s32 *)((s8 *)(param_2) + (4))));
        anctrl_setPlaybackType((*(s32 *)((s8 *)(param_0) + (0x2C))), 1);
        if (param_1 == 6) {
            func_8008B188((*(s32 *)((s8 *)(param_0) + (0x2C))), 0);
            func_80090684(1);
            func_800EA334(0);
        } else {
            osViBlack(1);
            func_8008B10C((*(s32 *)((s8 *)(param_0) + (0x2C))), 0x3E800000);
        }
        anctrl_start((*(s32 *)((s8 *)(param_0) + (0x2C))));
    }
    if (param_1 == 5) {
        func_800FC6B0(0x1D);
        func_800FCB54(0x1D, 0, 0x3E8, 0x3ECCCCCD);
        func_800FCA90(0x1D);
        func_800FC8EC(0x1D);
        goto block_27;
    }
    if (param_1 == 6) {
        if ((*(u8 *)((s8 *)(param_0) + (8))) == 0xA) {
            _gcaudiolist_entrypoint_0(1);
        } else {
            func_800FC6B0(0x1E);
            func_800FCB54(0x1E, 0, 0x3E8, 0x3E4CCCCD);
            func_800FCA90(0x1E);
            func_800FC8EC(0x1E);
        }
        goto block_27;
    }
    if ((param_1 == 1) && ((*(u8 *)((s8 *)(param_0) + (0x1C))) != 0)) {
        func_800C9214(param_0);
        return;
    }
block_27:
    (*(s32 *)((s8 *)(param_0) + (0x30))) = 0;
    (*(u8 *)((s8 *)(param_0) + (0x1C))) = (u8) param_1;
}

void gctransitionDll_entrypoint_0(u8 *self, GfxW **gdl)
{
    f32 vp_position[3];
    f32 vp_rotation[3];
    f32 percentage;
    f32 sp48[3];
    f32 scale;

    *(s32 *)(self + 0x4) += 1;
    if (self[0x1C] != 1) {
    func_800E41CC();
    if (*(s32 *)(self + 0x2C) != 0) {
        func_800EFA4C(vp_position, 0.0f, 0.0f, 350.0f);
    } else {
        func_800EFA4C(vp_position, 0.0f, 0.0f, 300.0f);
    }
    func_800EFD24(vp_rotation);
    func_800E3C8C(D_808010E4_gctransitionDll, D_808010E8_gctransitionDll);
    func_800E3BAC(vp_position);
    func_800E3C30(vp_rotation);
    func_800E3CE8();
    func_800E44FC(gdl);
    func_800EFD24(sp48);
    if (*(s32 *)(self + 0x2C) != 0) {
        { GfxW *_ga = (*gdl)++; _ga->w0 = 0xE3001201; _ga->w1 = 0; }
        { GfxW *_gb = (*gdl)++; _gb->w0 = 0xE3001801; _gb->w1 = 0xC0; }
        func_8008B304(*(s32 *)(self + 0x2C));
        func_800DF41C(func_8008B4D4(*(s32 *)(self + 0x2C)));
    }
    func_800DF830(0);
    if (self[0x1C] == 2 || self[0x1C] == 7) {
        func_800DE448(sp48, vp_rotation, 1.0f, 0, func_800D674C(*(s32 *)(self + 0x20)));
        if (*(s32 *)(self + 0x2C) != 0) {
            { GfxW *_gc = (*gdl)++; _gc->w0 = 0xE3001201; _gc->w1 = 0x2000; }
            { GfxW *_gd = (*gdl)++; _gd->w0 = 0xE3001801; _gd->w1 = 0; }
        }
        func_800E4208();
        return;
    }
    percentage = *(f32 *)(self + 0x28) / *(f32 *)(self + 0xC);
    if (self[0x1C] == 5) {
        switch (self[0x8]) {
            default:
                vp_rotation[2] = *(f32 *)(self + 0x24) - 90.0f * percentage;
                scale = *(f32 *)(self + 0x18) * percentage + 0.1f;
                break;
            case 0x10:
                scale = *(f32 *)(self + 0x18);
                break;
            case 0x16:
            case 0x18:
                vp_rotation[2] = 0;
                scale = *(f32 *)(self + 0x18) * percentage + 0.1f;
                break;
        }
        func_80800098_gctransitionDll(self, &scale);
        func_800DE448(sp48, vp_rotation, scale, 0, func_800D674C(*(s32 *)(self + 0x20)));
    } else if (self[0x1C] == 6) {
        switch (self[0x8]) {
            default:
                vp_rotation[2] = *(f32 *)(self + 0x24) - 90.0f * percentage;
                scale = (1.0f - percentage) * ((TransS18 *)self)->unk18 + 0.1f;
                break;
            case 0x11:
                scale = *(f32 *)(self + 0x18);
                break;
            case 0xA:
                vp_rotation[2] = 0;
                percentage = func_800F1480(percentage);
                scale = (1.0f - percentage) * ((TransS18 *)self)->unk18 + 0.1f;
                break;
            case 0x17:
            case 0x19:
                vp_rotation[2] = 0;
                scale = (1.0f - percentage) * ((TransS18 *)self)->unk18 + 0.1f;
                break;
        }
        if (!(*(s32 *)(self + 0x30) < 3) || self[0x8] != 0x11) {
            func_80800098_gctransitionDll(self, &scale);
            func_800DE448(sp48, vp_rotation, scale, 0, func_800D674C(*(s32 *)(self + 0x20)));
        } else {
            func_800DE318();
        }
    } else if (self[0x1C] == 3) {
        func_800B99CC((u32 **)gdl, (s32)((1.0f - percentage) * 255.0f + 0.5f), D_808010D8_gctransitionDll);
    } else if (self[0x1C] == 4) {
        func_800B99CC((u32 **)gdl, (s32)(percentage * 255.0f + 0.5f), D_808010D8_gctransitionDll);
    } else if (self[0x1C] == 8) {
        percentage = (percentage <= 0.5f) ? 1.0f : 1.0f - (percentage - 0.5f) / 0.5f;
        func_800B99CC((u32 **)gdl, (s32)(percentage * 255.0f + 0.5f), D_808010CC_gctransitionDll);
    } else if (self[0x1C] == 9) {
        func_800B99CC((u32 **)gdl, (s32)(percentage * 255.0f + 0.5f), D_808010CC_gctransitionDll);
    }
    if (*(s32 *)(self + 0x2C) != 0) {
        { GfxW *_ge = (*gdl)++; _ge->w0 = 0xE3001201; _ge->w1 = 0x2000; }
    }
    func_800E4208();
    }
}

void gctransitionDll_entrypoint_1(s32 param_0) {
    u8 *local_0;

    local_0 = func_80800000_gctransitionDll((*(u8 *)((s8 *)(func_8080004C_gctransitionDll(func_800EA05C())) + (2))));
    func_808000D8_gctransitionDll(param_0, (*(u8 *)((s8 *)(local_0) + (1))), local_0);
}

int gctransitionDll_entrypoint_2(u8 *param_0)
{
    return param_0[0x1C] == 1;
}

s32 gctransitionDll_entrypoint_3(u8 *param_0)
{
    return param_0[0x1C] != 1;
}

int gctransitionDll_entrypoint_4(TransitionQueryState *param_0)
{
    return param_0->local_1 == 4 ||
        (param_0->local_1 == 2 && param_0->local_0 < 2) ||
        param_0->local_1 == 6 ||
        param_0->local_1 == 9 ||
        (param_0->local_1 == 7 && param_0->local_0 < 2);
}

s32 gctransitionDll_entrypoint_5(s32 map){
    func_808000D8_gctransitionDll(map, 1, 0);
}

int gctransitionDll_entrypoint_6(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80800000_gctransitionDll((*(u8 *)((s8 *)(func_8080004C_gctransitionDll(func_800EA05C())) + (3))));
    func_808000D8_gctransitionDll(param_0, (*(u8 *)((s8 *)(local_0) + (1))), local_0);
}

void gctransitionDll_entrypoint_7(s32 param_0, s32 param_1) {
    TransEntry *local_0 = &D_80800EA4_gctransitionDll[param_1];
    func_808000D8_gctransitionDll(param_0, local_0->b, local_0);
}

void gctransitionDll_entrypoint_8(u8 *param_0, s32 param_1) {
    *(u8 *)((char *)param_0 + 8) = 0;
    *(s32 **)(param_0 + 0x20) = 0;
    *(s32 **)(param_0) = param_1;
    *(s8 *)(param_0 + 0x1C) = 0;
    *(f32 *)(param_0 + 0x24) = 0.0f;
    *(s8 *)(param_0 + 0x1D) = func_800E6A00();
    func_808000D8_gctransitionDll(param_0, 1, 0);
}

void gctransitionDll_entrypoint_9(Transition49 *param_0)
{
    f32 local_0;
    local_0 = param_0->local_8 ? _glintrosyncDll_entrypoint_5() : func_800D8FF8();
    if (param_0->local_1) {
        if (param_0->local_12) {
            func_8008ADE4(param_0->local_12);
            if (param_0->local_7 == 5) {
                switch (param_0->local_13) {
                case 0:
                case 3:
                    break;
                case 1:
                    func_80090684(1);
                    func_800EA334(0);
                    break;
                case 2:
                    func_800EA34C(0);
                    break;
                case 4:
                    osViBlack(0);
                    break;
                default:
                    param_0->local_11 += local_0;
                    break;
                }
            } else {
                switch (param_0->local_13) {
                case 0:
                case 1:
                    break;
                case 2:
                    func_800EA34C(0);
                    break;
                default:
                    param_0->local_11 += local_0;
                    break;
                }
            }
        } else param_0->local_11 += local_0;
        if (param_0->local_5 < param_0->local_11 ||
            (param_0->local_12 && anctrl_isStopped(param_0->local_12))) {
            param_0->local_11 = param_0->local_5;
            if (param_0->local_7 == 5 || param_0->local_7 == 6) {
                param_0->local_10 -= 90.0f;
                if (param_0->local_10 < -360.0f) param_0->local_10 += 360.0f;
                if (param_0->local_10 > 360.0f) param_0->local_10 -= 360.0f;
            }
            func_808000D8_gctransitionDll(param_0, param_0->local_3, 0);
            if (param_0->local_12) func_800EA170();
        }
        param_0->local_13++;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/transitionDll.data.s) is defined here in C.
 * Values are taken from the ROM. */
int D_80800CB0_gctransitionDll[125] = { 0x20080100, 0x40B00000, 0x0, 0x0, 0x0, 0x1E030100, 0x3FF33333, 0x0, 0x0, 0x0, 0x1F040200, 0x3FF33333, 0x0, 0x0, 0x0, 0x1030100, 0x3F333333, 0x0, 0x0, 0x0, 0x2040200, 0x3F333333, 0x0, 0x0, 0x0, 0x3050100, 0x3F000000, 0xB42, 0x0, 0x41C80000, 0x4060200, 0x3F000000, 0xB42, 0x0, 0x41C80000, 0x5050100, 0x40000000, 0xB43, 0x0, 0x40600000, 0x6060200, 0x3F666666, 0xB43, 0x0, 0x40600000, 0x7010100, 0x0, 0x0, 0x0, 0x0, 0x8080100, 0x3F8CCCCD, 0x0, 0x0, 0x0, 0x9090700, 0x3F333333, 0x0, 0x0, 0x0, 0xA060200, 0x40600000, 0xB47, 0x0, 0x406CCCCD, 0xB050100, 0x3E99999A, 0xB42, 0x0, 0x41C80000, 0xC060200, 0x3E99999A, 0xB42, 0x0, 0x41C80000, 0xD030100, 0x3F19999A, 0x0, 0x0, 0x0, 0xE050100, 0x3F800000, 0xB42, 0x0, 0x41C80000, 0xF060200, 0x3F800000, 0xB42, 0x0, 0x41C80000, 0x10050100, 0x40200000, 0x6F9, 0x1F5, 0x3E8A0F0A, 0x11060200, 0x40000000, 0x6F9, 0x1F5, 0x3E8A0F0A, 0x12050100, 0x3F99999A, 0xB42, 0x0, 0x41C80000, 0x13060200, 0x3F99999A, 0xB42, 0x0, 0x41C80000, 0x14060200, 0x400CCCCD, 0xB42, 0x0, 0x41C80000, 0x15050100, 0x400CCCCD, 0xB42, 0x0, 0x41C80000, 0x0, 0x0, 0x0, 0x0, 0x0 };
TransEntry D_80800EA4_gctransitionDll[22] = { 0xA, 0x6, 0x2, 0x0, 0x40, 0x60, 0x0, 0x0, 0x0, 0x0, 0xB, 0x47, 0x0, 0x0, 0x0, 0x0, 0x40, 0x6C, 0xCC, 0xCD, 0x10, 0x5, 0x1, 0x0, 0x40, 0x20, 0x0, 0x0, 0x0, 0x0, 0x6, 0xF9, 0x0, 0x0, 0x1, 0xF5, 0x3E, 0x8A, 0xF, 0xA, 0x11, 0x6, 0x2, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xF9, 0x0, 0x0, 0x1, 0xF5, 0x3E, 0x8A, 0xF, 0xA, 0x6, 0x6, 0x2, 0x0, 0x3F, 0x66, 0x66, 0x66, 0x0, 0x0, 0xB, 0x43, 0x0, 0x0, 0x0, 0x0, 0x40, 0x60, 0x0, 0x0, 0x5, 0x5, 0x1, 0x0, 0x40, 0x20, 0x0, 0x0, 0x0, 0x0, 0xB, 0x43, 0x0, 0x0, 0x0, 0x0, 0x40, 0x60, 0x0, 0x0, 0x9, 0x9, 0x7, 0x0, 0x3F, 0x33, 0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0x1, 0x0, 0x3F, 0x33, 0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE, 0x5, 0x1, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0xF, 0x6, 0x2, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x7, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0x1, 0x0, 0x3F, 0x8C, 0xCC, 0xCD, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x9, 0x7, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x5, 0x1, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x17, 0x6, 0x2, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x18, 0x5, 0x1, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x19, 0x6, 0x2, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x1A, 0x5, 0x1, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x1B, 0x6, 0x2, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x0, 0x0, 0xB, 0x42, 0x0, 0x0, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0, 0x1C, 0x5, 0x1, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0, 0x0, 0xB, 0x43, 0x0, 0x0, 0x0, 0x0, 0x40, 0x6C, 0xCC, 0xCD, 0x1D, 0x6, 0x2, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0, 0x0, 0xB, 0x43, 0x0, 0x0, 0x0, 0x0, 0x40, 0x6C, 0xCC, 0xCD, 0x1, 0x3, 0x1, 0x0, 0x3F, 0x33, 0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x4, 0x2, 0x0, 0x3F, 0x33, 0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_8080105C_gctransitionDll[28] = { 0xA11E04, 0xA20104, 0xA30104, 0xA40104, 0xA50109, 0xA60104, 0xA7080A, 0xA80104, 0xA90104, 0xAA0104, 0xAB0104, 0xAC0109, 0x18E1E04, 0x18C0104, 0x18D0104, 0x18F0104, 0x1900104, 0x17E0104, 0x1910104, 0x1920104, 0x1940104, 0x1950104, 0x1960104, 0x1970104, 0x1980104, 0x1930104, 0x1990104, 0x506 };
u8 D_808010CC_gctransitionDll[12] = { 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF };
u8 D_808010D8_gctransitionDll[12] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
f32 D_808010E4_gctransitionDll = 63.60261f;
f32 D_808010E8_gctransitionDll = 5e+02f;
static u32 D_808010E8_gctransitionDll_rest[1] = { 0x0 };
