#include "common.h"

typedef struct { u8 pad_0[8]; s16 local_0[3]; s16 pad_1; } TwinklePoint;
typedef struct { u8 pad_0[0xE]; s16 local_0[3]; s32 local_1; u8 pad_1[0x10]; s16 local_2; u8 pad_2[2]; TwinklePoint *local_3; } TwinkleContext;
typedef struct { s16 position[3]; u16 flags; s16 texcoords[2]; u8 color[4]; } TwinkleVertex88;
typedef struct { f32 local_0; f32 local_1; s16 position[3]; s16 pad_0; } TwinklePoint88;
typedef struct { u8 pad_0[0x28]; s16 local_0; s16 pad_1; TwinklePoint88 *local_1; } TwinkleData88;
typedef struct { f32 local_0; f32 local_1; u8 pad_0[6]; u8 local_2; u8 local_3; } TwinkleItem31;
typedef struct { u8 pad_0[0xC]; s16 local_0; u8 pad_1[6]; s32 local_1; s16 local_2; s16 local_3; u8 pad_2[8]; s16 local_4; s16 local_5; s16 local_6; u8 pad_3[2]; TwinkleItem31 *local_7; } TwinkleState31;
extern void _idtwinkle_entrypoint_1();
extern void _idtwinkle_entrypoint_0();
extern f32 func_800DC264(f32, f32);
typedef struct Mass43TwinkleItem { f32 local_0; f32 local_1; u8 pad_0[6]; u8 local_2; s8 local_3; } Mass43TwinkleItem;
typedef struct Mass43TwinkleObject { u8 pad_0[0x1C]; f32 local_0; f32 local_1; u8 pad_1[4]; s16 local_2; u8 pad_2[2]; Mass43TwinkleItem *local_3; } Mass43TwinkleObject;
extern f32 func_800D8FF8(void);
extern void _idtwinkle_entrypoint_2();

void idtwinkle_entrypoint_0(s32 param_0, s16 *param_1, s32 param_2, TwinkleContext *param_3)
{
    s32 local_5;
    s32 local_6;
    s32 local_0[3];

    for (local_5 = 0; local_5 < 3; local_5++) {
        local_0[local_5] = param_1[local_5] - param_3->local_0[local_5];
    }
    local_6 = local_0[0] * local_0[0] + local_0[1] * local_0[1] + local_0[2] * local_0[2];
    if (param_3->local_1 >= local_6) {
        for (local_5 = 0; local_5 < param_3->local_2; local_5++) {
            if (param_3->local_3[local_5].local_0[0] == param_1[0] && param_3->local_3[local_5].local_0[1] == param_1[1] && param_3->local_3[local_5].local_0[2] == param_1[2]) break;
        }
        if (local_5 == param_3->local_2 && param_3->local_2 < 10) {
            param_3->local_3[param_3->local_2].local_0[0] = param_1[0];
            param_3->local_3[param_3->local_2].local_0[1] = param_1[1];
            param_3->local_3[param_3->local_2].local_0[2] = param_1[2];
            param_3->local_2++;
        }
    }
}

void idtwinkle_entrypoint_1(s32 param_0, s16 *param_1, s32 param_2, s16 *param_3)
{
  if (!(param_3[19] != param_3[18])) {
    param_3[7] = param_1[0];
    param_3[8] = param_1[1];
    param_3[9] = param_1[2];
  }
  param_3[18]++;
}

void idtwinkle_entrypoint_2(s32 param_0, TwinkleVertex88 *param_1,
    TwinkleVertex88 *param_2, s32 param_3, TwinkleData88 *param_4)
{
    TwinkleVertex88 *local_0;
    f32 local_1;
    s32 local_2;

    local_0 = param_1 + param_3;
    while (param_1 < local_0) {
        for (local_2 = 0; local_2 < param_4->local_0; local_2++) {
            if (param_1->position[0] == param_4->local_1[local_2].position[0] &&
                param_1->position[1] == param_4->local_1[local_2].position[1] &&
                param_1->position[2] == param_4->local_1[local_2].position[2]) {
                break;
            }
        }
        if (local_2 != param_4->local_0) {
            local_1 = param_4->local_1[local_2].local_0;
            param_2->color[0] = (u32)((u32)param_1->color[0] + (255 - param_1->color[0]) * local_1);
            param_2->color[1] = (u32)((u32)param_1->color[1] + (255 - param_1->color[1]) * local_1);
            param_2->color[2] = (u32)((u32)param_1->color[2] + (255 - param_1->color[2]) * local_1);
        }
        param_1++;
        param_2++;
    }
}

void func_80800478_idtwinkle(TwinkleState31 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    param_0->local_5 = func_800DC214(0, param_0->local_0);
    param_0->local_4 = 0;
    _glid_entrypoint_2(param_1, param_2, _idtwinkle_entrypoint_1, param_0);
    local_0 = func_800DC214(param_0->local_2, param_0->local_3);
    param_0->local_1 = local_0 * local_0;
    param_0->local_6 = 0;
    _glid_entrypoint_2(param_1, param_2, _idtwinkle_entrypoint_0, param_0);
    for (local_1 = 0; local_1 < param_0->local_6; local_1++) {
        param_0->local_7[local_1].local_0 = 0.0f;
        param_0->local_7[local_1].local_3 = 10;
        param_0->local_7[local_1].local_2 = 0;
        param_0->local_7[local_1].local_1 = func_800DC264(0.0f, 1.0f);
    }
}

int idtwinkle_entrypoint_3(Actor *param_0)
{
  heap_free((*(s32 *)((char *)(param_0) + 0x2C)));
}

void idtwinkle_entrypoint_4(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s16 local_0[3];
    s16 local_1[3];
    s16 local_2[3];
    s32 local_4;
    s32 local_3 = 0;
    _glidmake_entrypoint_2(param_2, param_3, local_0, local_1);
    *(s16 *)(param_0 + 12) = _glidmake_entrypoint_3(param_2, param_3);
    for (local_4 = 0; local_4 < 3; local_4++) {
        local_2[local_4] = local_1[local_4] - local_0[local_4];
        local_3 += local_2[local_4] * local_2[local_4];
    }
    *(s16 *)(param_0 + 0x1A) = (s32)sqrtf((f32)local_3) * 0.25f;
    *(s16 *)(param_0 + 0x18) = *(s16 *)(param_0 + 0x1A) * 0.5f;
    *(f32 *)(param_0 + 0x20) = param_1 * 0.1f + 1.0f;
    *(f32 *)(param_0 + 0x1C) = func_800DC264(0.0f, *(f32 *)(param_0 + 0x20));
    *(void **)(param_0 + 0x2C) = heap_alloc(0xA0);
    *(s16 *)(param_0 + 0x28) = 0;
}

void idtwinkle_entrypoint_5(Mass43TwinkleObject *param_0, s32 param_1, s32 param_2)
{
    s32 pad[1];
    f32 local_0 = func_800D8FF8();
    s32 local_1 = 0;
    s32 local_2;
    if (param_0->local_0 > 0.0f) {
        param_0->local_0 -= local_0;
        if (param_0->local_0 <= 0.0f) func_80800478_idtwinkle(param_0, param_1, param_2);
    } else {
        for (local_2 = 0; local_2 < param_0->local_2; local_2++) {
            if (param_0->local_3[local_2].local_1 > 0.0f) param_0->local_3[local_2].local_1 -= local_0;
            else if (!param_0->local_3[local_2].local_2) {
                param_0->local_3[local_2].local_0 += param_0->local_3[local_2].local_3 * local_0;
                if (param_0->local_3[local_2].local_0 >= 1.0f) {
                    param_0->local_3[local_2].local_0 = 1.0f;
                    param_0->local_3[local_2].local_3 = -param_0->local_3[local_2].local_3;
                } else if (param_0->local_3[local_2].local_0 < 0.0f) {
                    param_0->local_3[local_2].local_0 = 0.0f;
                    param_0->local_3[local_2].local_2 = 1;
                }
            } else local_1++;
        }
        _glid_entrypoint_0(param_1, param_2, _idtwinkle_entrypoint_2);
        if (local_1 == param_0->local_2) param_0->local_0 = func_800DC264(0.0f, param_0->local_1);
    }
}

void idtwinkle_entrypoint_6(u8 *param_0, s32 *param_1, s32 *param_2)
{
  *param_1 = *((s32 *) (((s8 *) param_0) + 0x2C));
  *param_2 = ((*((s16 *) (((s8 *) param_0) + 0x28))) * 0x10) + (*((s32 *) (((s8 *) param_0) + 0x2C)));
}
