#include "common.h"

typedef struct { f32 position[3]; s32 color[3]; f32 weight; } LocalLight;
typedef struct { s32 unused, ambient[3]; u8 transformed, count, pad[2]; void *list; LocalLight *begin, *end; } LocalState;
extern LocalState D_80137060;
extern LocalLight *D_80137078;
extern LocalLight *D_8013707C;
extern s32 D_80137064[3];
extern s32 func_800B3784(void *);
extern void func_800B37A4(void *, LocalLight **, LocalLight **);
extern void func_800192FC(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800B37B8(void *, s32 *);
extern void func_800B388C(s32, s32);
extern void func_800B237C(s32, f32*, f32*);
extern f32 func_800DF8C4(s32);
extern void func_800B3494(s32, f32*, f32);
extern void func_800B3748(s32);
extern void func_800B38C8(s32);
extern void func_80019224(f32*, f32*);
extern void func_800B37E4(void *, s32);
extern s32 func_800DF8D4(void);
extern void func_800B3370();
typedef struct { f32 local_0[3]; s32 local_1[3]; s32 pad18; } LightE4C4;
typedef struct { s16 local_0[3]; u8 local_1[3]; u8 pad9; } ColorE4C4;
typedef struct { s8 local_0[3]; u8 pad3; } NormalE4C4;
typedef struct { u8 pad[12]; u8 local_0[4]; } VertexE4C4;
typedef struct { void *local_0; s32 local_1[3]; u8 local_2, local_3; u8 pad12[6]; LightE4C4 *local_4, *local_5; } StateE4C4;
extern u8 *func_800DF8B4(void *);
extern NormalE4C4 *func_800DF8CC(void *);
extern ColorE4C4 *func_800DF8BC(void *);

extern s32 D_80137074;

void func_8010E070(void)
{
    LocalLight *local_0;
    f32 local_1;
    f32 local_2;
    D_80137060.count = func_800B3784(D_80137060.list);
    func_800B37A4(D_80137060.list, &D_80137078, &D_8013707C);
    if (!D_80137060.transformed) {
        for (local_0 = D_80137060.begin; local_0 < D_80137060.end; local_0++) {
            func_800192FC(local_0->position, local_0->position);
            func_800EF368(local_0->position, 256.0f);
        }
    }
    if (D_80137060.count >= 2) {
        local_1 = 0.0f;
        for (local_0 = D_80137060.begin; local_0 < D_80137060.end; local_0++) {
            local_1 += local_0->weight;
        }
        local_1 = 1.0f / local_1;
        for (local_0 = D_80137060.begin; local_0 < D_80137060.end; local_0++) {
            local_2 = 1.0f - local_0->weight * local_1;
            local_0->color[0] *= local_2;
            local_0->color[1] *= local_2;
            local_0->color[2] *= local_2;
        }
    }
    func_800B37B8(D_80137060.list, D_80137064);
}

void func_8010E204(s32 param_0, s32 param_1, s32 param_2) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;

    func_800B388C(D_80137074, param_1 < 0 ? -param_1 : param_1);
    func_800B237C(func_800DF8B4(param_0), local_0, &local_1);
    local_2 = func_800DF8C4(param_0);
    func_80019224(local_0, local_0);
    local_1 *= local_2;
    func_800B3494(D_80137074, local_0, local_1);
    if (param_1 < 0) {
        func_800B3748(D_80137074);
    }
    func_800B38C8(D_80137074);
}

void func_8010E2C4(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  *((s32 *) (((s8 *) (((u8 *) &D_80137060))) + 0)) = param_0;
  *((s8 *) (((s8 *) (((u8 *) &D_80137060))) + 0x10)) = func_800DF8D4();
  if (param_2 != 0)
  {
    func_800B37E4(*((s32 *) (((s8 *) (((u8 *) &D_80137060))) + 0x14)), param_2);
  }
  else
  {
    if (!param_0)
    {
    }
    func_8010E204(param_0, param_1, param_3);
  }
  func_8010E070();
}

void func_8010E334()
{
    D_80137074 = func_800B3310(4);
}

void func_8010E358()
{
  if (D_80137074 != 0)
  {
    D_80137074 = func_800B38E8(D_80137074);
  }
}

s32 func_8010E390(void){
    func_800B3370(D_80137074);
    D_80137074 = 0;
}

s32 func_8010E3B8()
{
    return D_80137074;
}

void func_8010E3C4(f32 param_0[4][4], s32 *param_1, f32 *param_2) {
    s32 local_1;
    f32 local_2;
    f32 local_0[3];
    for (local_1 = 0; local_1 < 3; local_1++) {
        local_0[local_1] = param_2[0] * param_0[local_1][0] + param_2[1] * param_0[local_1][1] + param_2[2] * param_0[local_1][2];
    }
    local_2 = sqrtf(local_0[0] * local_0[0] + local_0[1] * local_0[1] + local_0[2] * local_0[2]);
    if (local_2 > 0.0f) {
        local_2 = 256.0f / local_2;
        param_1[0] = local_0[0] * local_2;
        param_1[1] = local_0[1] * local_2;
        param_1[2] = local_0[2] * local_2;
    } else {
        param_1[0] = param_1[1] = param_1[2] = 0;
    }
}

void func_8010E4C4(void *param_0, s32 *param_1, s32 param_2)
{
    VertexE4C4 *local_0;
    NormalE4C4 *local_1;
    ColorE4C4 *local_2;
    ColorE4C4 *local_3;
    ColorE4C4 *local_4;
    LightE4C4 *local_5;
    NormalE4C4 *local_6;
    s32 local_14;
    s32 local_15;
    s32 local_16;
    s32 local_17;
    s32 local_18;
    s32 local_19;
    s32 local_20;
    s32 local_21;
    s32 local_22;
    s32 local_7[3];
    s32 local_8;
    s32 local_9;
    s32 local_10;
    s32 local_11;
    s32 local_12;
    s32 local_13;
    local_0 = (VertexE4C4 *)(func_800DF8B4((*((StateE4C4 *) &D_80137060)).local_0) + 0x18) + *param_1;
    local_1 = func_800DF8CC((*((StateE4C4 *) &D_80137060)).local_0) + *param_1;
    local_2 = func_800DF8BC((*((StateE4C4 *) &D_80137060)).local_0) + *param_1;
    local_3 = local_2 + param_2;
    *param_1 += param_2;
    if ((*((StateE4C4 *) &D_80137060)).local_3) {
        local_15 = (*((StateE4C4 *) &D_80137060)).local_1[0];
        local_16 = (*((StateE4C4 *) &D_80137060)).local_1[1];
        local_17 = (*((StateE4C4 *) &D_80137060)).local_1[2];
        for (local_4 = local_2; local_4 < local_3; local_4++) {
            local_4->local_0[0] = local_15;
            local_4->local_0[1] = local_16;
            local_4->local_0[2] = local_17;
        }
        for (local_5 = (*((StateE4C4 *) &D_80137060)).local_4; local_5 < (*((StateE4C4 *) &D_80137060)).local_5; local_5++) {
            local_4 = local_2;
            local_6 = local_1;
            if ((*((StateE4C4 *) &D_80137060)).local_2) {
                func_8010E3C4(param_0, local_7, local_5);
                local_8 = local_7[0];
                local_9 = local_7[1];
                local_10 = local_7[2];
            } else {
                local_8 = local_5->local_0[0];
                local_9 = local_5->local_0[1];
                local_10 = local_5->local_0[2];
            }
            local_11 = local_5->local_1[0];
            local_12 = local_5->local_1[1];
            local_13 = local_5->local_1[2];
            for (; local_4 < local_3; local_4++, local_6++) {
                local_14 = local_8 * local_6->local_0[0] + local_9 * local_6->local_0[1] + local_10 * local_6->local_0[2];
                if (local_14 > 0) {
                    local_4->local_0[0] += (local_14 * local_11) >> 15;
                    local_4->local_0[1] += (local_14 * local_12) >> 15;
                    local_4->local_0[2] += (local_14 * local_13) >> 15;
                }
            }
        }
        for (; local_2 < local_3; local_2++, local_0++) {
            local_14 = (local_2->local_0[0] * local_2->local_1[0]) >> 8;
            if (local_14 >= 256) local_14 = 255;
            local_0->local_0[0] = local_14;
            local_14 = (local_2->local_0[1] * local_2->local_1[1]) >> 8;
            if (local_14 >= 256) local_14 = 255;
            local_0->local_0[1] = local_14;
            local_14 = (local_2->local_0[2] * local_2->local_1[2]) >> 8;
            if (local_14 >= 256) local_14 = 255;
            local_0->local_0[2] = local_14;
        }
    } else {
        local_15 = (*((StateE4C4 *) &D_80137060)).local_1[0];
        local_16 = (*((StateE4C4 *) &D_80137060)).local_1[1];
        local_17 = (*((StateE4C4 *) &D_80137060)).local_1[2];
        for (; local_2 < local_3; local_2++, local_0++) {
            local_0->local_0[0] = (local_2->local_1[0] * local_15) >> 8;
            local_0->local_0[1] = (local_2->local_1[1] * local_16) >> 8;
            local_0->local_0[2] = (local_2->local_1[2] * local_17) >> 8;
        }
    }
}

void func_8010E7F4()
{
  ((s32 *) &D_80137060)[0] = 0;
  ((s32 *) &D_80137060)[6] = 0;
  ((s32 *) &D_80137060)[7] = 0;
}
