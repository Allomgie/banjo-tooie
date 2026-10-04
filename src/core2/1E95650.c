#include "common.h"
#include <PR/gbi.h>

#define LOCAL_MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct { u8 pad[6]; s16 local_0[3]; f32 local_1; f32 local_2[8]; s16 local_3; u8 pad_1[7]; u8 local_4:1; u8 pad_2:7; u8 pad_3[2]; } EntryBBD60;
typedef struct { s16 pad_0; u16 local_0; u8 pad_1[8]; s16 local_1[3]; u8 pad_2[0x41]; u8 local_2; u8 pad_3[0x2C]; u8 local_3[4]; u8 pad_4[8]; EntryBBD60 *local_4; EntryBBD60 *local_5; } StateBBD60;
extern void func_800DF5D8(u32, u32, u32, s32);
extern void func_800DF830(s32);
extern s32 func_800DE448(f32 *, f32 *, f32, s32, s32);
typedef struct { u8 pad[0x5C]; f32 period, phase[3], amplitude[3]; } LocalPulse;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F13C4(f32, f32);
extern f32 mlAbsF(f32);
typedef struct { u8 pad[6]; s16 local_0[3]; f32 local_1; f32 pad10[2]; f32 local_2; f32 local_3; u8 pad20[12]; s16 local_4; u16 pad2E; s16 local_5; u8 pad32[7]; u8 local_6:1; u8 pad39:7; u8 pad3A[2]; } EntryBF;
typedef struct { u16 local_0; u16 local_1; u8 pad4[8]; s16 local_2[3]; u8 pad12[0x41]; u8 local_3; u8 pad54[8]; f32 local_4; u8 pad60[0x20]; u8 local_5[4]; u8 pad84[8]; EntryBF *local_6, *local_7; } StateBF;
extern void *func_800D674C(s32);
extern void func_800E2588(u32);
extern void func_800E24F8(s32, s32, s32);
extern void func_800E2440(s32, s32, s32);
extern void func_800E24B4(s32);
extern void func_800E24D8(s32);
extern void func_800E2594(s32, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800E28A4(s32, s32, s32, f32 *, f32 *, f32 *, s32);
extern s32 func_800E2720(s32, s32, s32, f32 *, f32 *, s32);
extern void func_800E2530(f32);
extern void func_800E2A14(s32);
extern Gfx D_8011A730[];
void func_800BC474();

void func_800BBD60(param_0, param_1) StateBBD60 * param_0; s32 param_1; {
    s32 local_0;
    f32 local_1[3];
    EntryBBD60 *local_2;
    local_0 = func_800D674C(param_0->local_0);
    for (local_2 = param_0->local_4; local_2 < param_0->local_5; local_2++) {
        local_1[0] = local_2->local_0[0] + param_0->local_1[0];
        local_1[1] = local_2->local_0[1] + param_0->local_1[1];
        local_1[2] = local_2->local_0[2] + param_0->local_1[2];
        func_800DF5D8(param_0->local_3[0], param_0->local_3[1], param_0->local_3[2], (s32)((f32)(u32)param_0->local_3[3] * local_2->local_1));
        func_800DF830(param_0->local_2);
        local_2->local_4 |= func_800DE448(local_1, local_2->local_2, local_2->local_3 * 0.00390625f, 0, local_0) ? 1 : 0;
    }
}

void func_800BBED8(LocalPulse *param_0, f32 param_1, f32 *param_2)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    local_1 = param_0->period * 0.5f;
    for (local_0 = 0; local_0 < 3; local_0++) {
        if (param_0->amplitude[local_0] != 0.0f) {
            local_2 = func_800F13C4(param_0->phase[local_0] + param_1, param_0->period);
            local_2 = mlAbsF(local_2 - local_1);
            local_2 = func_800F10B4(local_2, 0.0f, local_1, 1.0f - param_0->amplitude[local_0], param_0->amplitude[local_0] + 1.0f);
            param_2[local_0] *= local_2;
        }
    }
}

void func_800BBFDC(param_0, param_1) StateBF * param_0; s32 param_1;
{
    void *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    EntryBF *local_4;
    s32 local_5;
    local_0 = func_800D674C(param_0->local_1);
    local_5 = (param_0->local_0 & 0x800) ? 1 : 0;
    if (!(param_0->local_0 & 0x20) && (param_0->local_5[0] != 255 || param_0->local_5[1] != 255 || param_0->local_5[2] != 255 || param_0->local_5[3] != 255)) {
        func_800E2588(param_0->local_3);
        func_800E24F8(param_0->local_5[0], param_0->local_5[1], param_0->local_5[2]);
        func_800E2440(param_0->local_5[0] < 8 ? 0 : param_0->local_5[0] - 8,
        param_0->local_5[1] < 8 ? 0 : param_0->local_5[1] - 8,
        param_0->local_5[2] < 8 ? 0 : param_0->local_5[2] - 8);
        func_800E24B4(0);
    } else {
        func_800E2588(param_0->local_3 ? 2 : 0);
    }
    func_800E24D8(param_0->local_0 & 0x200 ? 1 : 0);
    func_800E2594(param_1, local_0);
    if (param_0->local_0 & 1) func_800EFA4C(local_2, 90.0f, 0.0f, 0.0f);
    for (local_4 = param_0->local_6; local_4 < param_0->local_7; local_4++) {
        local_1[0] = local_4->local_0[0] + param_0->local_2[0];
        local_1[1] = local_4->local_0[1] + param_0->local_2[1];
        local_1[2] = local_4->local_0[2] + param_0->local_2[2];
        local_3[0] = local_3[1] = local_3[2] = local_4->local_5 * 0.00390625f;
        if (param_0->local_4 != 0.0f) func_800BBED8(param_0, local_4->local_3, local_3);
        if (param_0->local_0 & 1) {
            local_4->local_6 |= func_800E28A4(param_1, local_4->local_4 >> 8, local_5, local_1, local_2, local_3,
            (s32)((u32)param_0->local_5[3] * local_4->local_1));
        } else {
            func_800E2530(local_4->local_2);
            local_4->local_6 |= func_800E2720(param_1, local_4->local_4 >> 8, local_5, local_1, local_3,
            (s32)((u32)param_0->local_5[3] * local_4->local_1));
        }
    }
    func_800E2A14(param_1);
}

void func_800BC358(void *param_0, s32 param_1, s32 param_2)
{
  int new_var2;
  void *new_var;
  u16 field0;
  char *new_var3;
  u8 field10;
  (void) param_1;
  if (!param_1)
  {
  }
  field0 = (new_var2 = *((u16 *) param_0));
  new_var = param_0;
  new_var = new_var;
  new_var2 = field0 & 4;
  if (new_var2 == param_2)
  {
    field10 = *((u8 *) (new_var3 = ((char *) new_var) + 0xA));
    switch (field10)
    {
      case 0:
        func_800BBD60();
        return;

      case 7:
        func_800BBFDC();
        break;

    }

  }
}

int func_800BC3B8(s32 param_0, s32 param_1)
{
  func_800BC358(param_0, param_1, 4);
  func_800BC358(param_0, param_1, 0);
}

void* func_800BC3F0(void* arg0) 
{
    return defrag(arg0);
}
void func_800BC410(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_1[4];
    func_800E7FCC(local_1);
    func_800BC474(param_0, local_1[0], local_1[1], local_1[2], local_1[3], param_1, param_2, param_3);
}

void func_800BC474(param_0, param_1, param_2, param_3, param_4, param_5, param_6, param_7) Gfx ** param_0; s32 param_1; s32 param_2; s32 param_3; s32 param_4; s32 param_5; s32 param_6; s32 param_7; {
    gDma1p((*param_0)++, 0xDE, (u8 *)D_8011A730 - 0x80000000, 0, G_DL_PUSH);
    gDPSetFillColor((*param_0)++, (GPACK_RGBA5551(param_5, param_6, param_7, 1) << 16) | GPACK_RGBA5551(param_5, param_6, param_7, 1));
    gDPFillRectangle((*param_0)++, LOCAL_MAX(param_1, 0), LOCAL_MAX(param_2, 0), LOCAL_MAX(param_1 + param_3 - 1, 0), LOCAL_MAX(param_2 + param_4 - 1, 0));
}

void func_800BC580(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    func_800BC474(param_0, param_1, param_2, param_3, param_4, 0, 0, 0);
}

void func_800BC5B0(Gfx **param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    gDma1p((*param_0)++, 0xDE, (u8 *)D_8011A730 - 0x80000000, 0, G_DL_PUSH);
    gDPSetFillColor((*param_0)++, 0xFFFCFFFC);
    gDPFillRectangle((*param_0)++, LOCAL_MAX(param_1, 0), LOCAL_MAX(param_2, 0), LOCAL_MAX(param_1 + param_3 - 1, 0), LOCAL_MAX(param_2 + param_4 - 1, 0));
}
