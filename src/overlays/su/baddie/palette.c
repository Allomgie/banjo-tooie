#include "common.h"

typedef struct { u16 local_0; u16 pad_0; u16 local_1; u8 pad_1[10]; u8 local_2[0x800]; } BaddiePalette;
extern void *func_800D674C(s32);
extern void func_801032B0(Actor *, s32, u16);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
typedef struct { u16 cur; u16 prev; s16 f4; s16 pad; f32 f8; f32 fC; } PalS;
extern void func_800B25D8();
extern void func_80100F0C();
extern void *func_80103C94(Actor *);
extern void *func_800B2840(void *);
void subaddiepalette_entrypoint_4();

void subaddiepalette_entrypoint_0(Actor *param_0, BaddiePalette *param_1, u16 param_2)
{
    rare_memcpy(param_1->local_2, func_800D674C(param_2), 0x800);
    func_800D6CEC(param_2);
    param_1->local_0 = param_2;
    param_1->local_1 = 0;
    subaddiepalette_entrypoint_4(param_0, param_1);
    func_801032B0(param_0, param_0->unk0->unk14, param_2);
}

void subaddiepalette_entrypoint_1(Actor *param_0, BaddiePalette *param_1)
{
    s32 local_0[4];
    s32 local_1[4];
    s32 local_2[4];
    f32 local_4;
    int local_3;
    void *local_5;
    void *local_6;
    s32 local_7;
    switch (*(s16 *)&param_1->local_1) {
    case 0:
        break;
    case 1:
    {
        local_3 = func_800D9078((u8 *)param_1 + 8);
        local_4 = func_800F12D4(*(f32 *)((u8 *)param_1 + 8), 0.0f,
            *(f32 *)((u8 *)param_1 + 12), 1.0f, 0.0f);
        local_5 = func_800D674C(param_1->pad_0);
        local_6 = func_800D674C(param_1->local_0);
        for (local_7 = 0; local_7 != 512; local_7++) {
            _dbpalette_entrypoint_0(local_5, local_7, local_0);
            _dbpalette_entrypoint_0(local_6, local_7, local_1);
            func_800F3214(local_2, local_0, local_1, local_4);
            _dbpalette_entrypoint_1(param_1->local_2, local_7, local_2);
        }
        subaddiepalette_entrypoint_4(param_0, param_1);
        if (local_3) param_1->local_1 = 0;
        break;
    }
    }
}

s32 subaddiepalette_entrypoint_2(u8 **param_0, PalS *param_1, u16 param_2, f32 param_3) {
    if (param_1->cur == param_2) {
        return 0;
    }
    param_1->f4 = 1;
    param_1->fC = param_3;
    param_1->f8 = param_3;
    param_1->prev = param_1->cur;
    param_1->cur = param_2;
    *(u16 *)(*param_0 + 0x16) = param_2;
    return 1;
}

void subaddiepalette_entrypoint_3(Actor *param_0, u8 *param_1, void *param_2)
{
    s16 local_1;

    local_1 = *(s16 *)(param_1 + 6);
    if (local_1 != 0) {
        if (*(s16 *)&param_0->pad60 != 0 && (u32)((u8 *)param_0)[0x7B] >> 6) {
            func_80100F0C(*(s16 *)&param_0->pad60, param_1 + 0x10);
            func_800DF720(func_80100AC4(*(s16 *)&param_0->pad60));
        } else {
            func_800B25D8(func_80103C94(param_0), func_800B2840(param_2), param_1 + 0x10);
        }
        local_1 = *(s16 *)(param_1 + 6);
    }
    if (local_1) *(s16 *)(param_1 + 6) = local_1 - 1;
}

void subaddiepalette_entrypoint_4(param_0, param_1) u8 *param_0; u8 *param_1;
{
  *((s16 *) (((u8 *) param_1) + 6)) = 1;
  if ((((*((s16 *) (((u8 *) param_0) + 0x60))) == 0) || ((((unsigned long) ((u8) (*((u8 *) (((u8 *) param_0) + 0x7B))))) >> 6) == 0)) && ((*((u8 *) (((u8 *) param_0) + 0x70))) & 1))
  {
    *((s16 *) (((u8 *) param_1) + 6)) = (s16) ((*((s16 *) (((u8 *) param_1) + 6))) + 1);
  }
}
