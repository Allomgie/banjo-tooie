#include "common.h"
typedef struct { u8 pad_0[7]; u8 local_0; u8 pad_1[4]; } MorphPreset_suexpressmorph_entrypoint_0;
extern MorphPreset_suexpressmorph_entrypoint_0 D_80801320_suexpressmorph[];

#define CODEX_MORPH_PRESET_VIEW
extern s16 D_80801324_suexpressmorph;
extern s16 D_8080132C_suexpressmorph[];
typedef struct { s16 local_0; s16 pad_0; f32 local_1[4]; f32 local_2[4]; } Broad51MorphRow;
typedef struct { Broad51MorphRow *local_0; s16 pad_0; u8 local_1; u8 local_2; s32 pad_1; } Broad51MorphPreset;
typedef struct { u8 pad_0[7]; u8 local_0; u8 pad_1[4]; } MorphPreset_suexpressmorph_entrypoint_1;
typedef struct MorphValues { f32 local_0; f32 local_1[4]; f32 local_2[4]; } MorphValues;
typedef struct { s16 local_0; s16 local_1; u8 pad_0[2]; u8 local_2; u8 pad_1; f32 local_3[3]; } MorphParameters1358;
typedef struct { u8 pad_0 : 7; u8 local_0 : 1; u8 pad_1[11]; } MorphEntry1358;
extern MorphEntry1358 D_80801328_suexpressmorph[];
typedef struct { u8 pad_0[7]; u8 local_0; u8 pad_1[4]; } MorphPreset_suexpressmorph_entrypoint_5;
typedef struct { f32 f[9]; } MorphRow;
typedef struct { MorphRow *rows; s16 pad4; u8 pad6; u8 count; s32 pad8; } MorphPreset_808000EC_suexpressmorph;
extern f32 func_800D8FF8(void);
void func_808000EC_suexpressmorph();

s32 func_80800000_suexpressmorph(s32 param_0) {
    s8 *var_v0;
    s32 var_v1;

    var_v0 = (s8 *)&D_8080132C_suexpressmorph;
    var_v1 = 1;
    if (param_0 == D_80801324_suexpressmorph) {
        return 0;
    }
loop_3:
    if (param_0 == (*(s16 *)((s8 *)(var_v0) + 4))) {
        return var_v1;
    }
    if (param_0 == (*(s16 *)((s8 *)(var_v0) + 0x10))) {
        return var_v1 + 1;
    }
    if (param_0 == (*(s16 *)((s8 *)(var_v0) + 0x1C))) {
        return var_v1 + 2;
    }
    if (param_0 == (*(s16 *)((s8 *)(var_v0) + 0x28))) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x30;
    if (var_v1 == 0x11) {
        return -1;
    }
    goto loop_3;
}

s32 suexpressmorph_entrypoint_0(param_0) s16 param_0;
{
    s32 idx;
    s32 x;

    idx = func_80800000_suexpressmorph(param_0);
    if (idx == -1) {
        return 0;
    }
    x = D_80801320_suexpressmorph[idx].local_0 * 4;
    x += 8;
    x += D_80801320_suexpressmorph[idx].local_0 * 4;
    return x;
}

void func_808000EC_suexpressmorph(param_0, param_1) f32 *param_0; u8 *param_1;
{
    f32 *local_0;
    f32 *local_1;
    f32 *local_2;
    s32 off;
    s32 i;

    local_0 = (f32 *)(param_1 + 8);
    local_1 = param_0;
    local_2 = local_0 + ((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].count;
    off = 0;
    i = 0;
    for (; i < ((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].count; i++, off += 4, local_1++, local_0++, local_2++) {
        if (*local_2 <= 0) {
            *local_1 = *(f32 *)((s32)((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].rows[param_1[5]].f + off + 4);
        } else {
            *local_2 -= func_800D8FF8();
            if (local_1) {}
        }
        if (*local_1 < *local_0) {
            *local_0 += (*local_1 - *local_0) * 0.2f;
            if (*local_0 < 0.0f) *local_0 = 0.0f;
        } else if (*local_0 < *local_1) {
            *local_0 += (*local_1 - *local_0) * 0.2f;
            if (*local_0 > 1.0f) *local_0 = 1.0f;
        }
    }
}

void func_808002BC_suexpressmorph(f32 *param_0, u8 *param_1)
{
    s32 local_2;
    f32 *local_3;
    s32 local_4;
    Broad51MorphRow *local_5;
    s32 local_1;
    s32 local_0;
    local_0 = -1;
    local_3 = (f32 *)(param_1 + 8) + ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_2;
    if (func_800D52F4() == *(s16 *)param_1) {
        local_2 = func_800D52A4() + 1;
        local_1 = 0;
        if (local_1 < (&((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)])->local_1) {
            local_5 = (&((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)])->local_0;
            do {
                if (local_2 == local_5->local_0) {
                    local_0 = local_1;
                }
                local_1++;
                local_5++;
            } while (local_1 < (&((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)])->local_1);
        }
        if (func_800D5298()) {
            for (local_1 = 0; local_1 < ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_2; local_1++, local_3++) {
                if (((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_0[local_0].local_1[local_1] != -1.0f) {
                    if (*local_3 < ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_0[local_0].local_2[local_1]) {
                        *local_3 = ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_0[local_0].local_2[local_1];
                        param_0[local_1] = ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_0[local_0].local_1[local_1];
                    }
                }
            }
        } else {
            for (local_1 = 0; local_1 < ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_2; local_1++) {
                if (((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_0[local_0].local_1[local_1] != -1.0f) {
                    param_0[local_1] = ((Broad51MorphPreset *)D_80801320_suexpressmorph)[*(s16 *)(param_1 + 2)].local_0[local_0].local_1[local_1];
                }
            }
        }
    }
}

void suexpressmorph_entrypoint_1(u8 *param_0)
{
    f32 local_0[4];
    s32 local_1;

    for (local_1 = 0; local_1 < D_80801320_suexpressmorph[*(s16 *)(param_0 + 2)].local_0; local_1++) {
        local_0[local_1] = (*(MorphValues **)&D_80801320_suexpressmorph[*(s16 *)(param_0 + 2)])[param_0[5]].local_1[local_1];
    }
    func_808002BC_suexpressmorph(local_0, param_0);
    func_808000EC_suexpressmorph(local_0, param_0);
}

void suexpressmorph_entrypoint_2(MorphParameters1358 *param_0, u8 **param_1)
{
  s32 pad0;
  s32 local_0;
  s32 local_2;
  u8 *local_1;
  s32 local_3;
  local_0 = func_80103AA0(*param_1);
  if (local_0)
  {
    local_1 = (u8 *) func_80103CDC(param_1, local_0);
    if (local_1)
    {
      local_2 = func_800B2840(local_0);
      local_3 = func_800B2768(local_0);
      _dbmorph_entrypoint_3(local_3, local_1, local_2, param_0->local_2, param_0->local_3);
      if (D_80801328_suexpressmorph[param_0->local_1].local_0)
      {
        if ((((((!local_3) && (!local_3)) && (!local_3)) & 0xFFu) & 0xFFu) & 0xFFu)
        {
        }
        local_1[0x17] |= 1;
        _dbmorph_entrypoint_4(local_3, local_1, local_2, param_0->local_2, func_800AE080(*((s16 *) ((*param_1) + 0x10))));
      }
    }
  }
}

void suexpressmorph_entrypoint_3(s16 *param_0, s16 param_1)
{
    param_0[0] = param_1;
    param_0[1] = func_80800000_suexpressmorph(param_0[0]);
}

void suexpressmorph_entrypoint_4(s32 param_0, s32 param_1)
{
    *(u8 *)((char *)param_0 + 6) = param_1;
}

void suexpressmorph_entrypoint_5(u8 *param_0, s16 param_1)
{
    f32 *local_0;
    f32 *local_1;
    s32 local_2;

    suexpressmorph_entrypoint_3(param_0, param_1);
    param_0[5] = 0;
    param_0[6] = 1;
    local_0 = (f32 *)(param_0 + 8);
    local_1 = local_0 + ((MorphPreset_suexpressmorph_entrypoint_5 *) D_80801320_suexpressmorph)[*(s16 *)(param_0 + 2)].local_0;
    for (local_2 = 0; local_2 < ((MorphPreset_suexpressmorph_entrypoint_5 *) D_80801320_suexpressmorph)[*(s16 *)(param_0 + 2)].local_0; local_2++) {
        *local_0++ = 0.0f;
        *local_1++ = 0.0f;
    }
}
