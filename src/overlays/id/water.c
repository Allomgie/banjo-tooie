#include "common.h"

typedef struct { s16 local_0[2]; f32 local_1; f32 local_2; s16 local_3[3]; u16 pad_0; f32 local_4[3]; } WaterEffectState;
extern f32 func_800DC264(f32, f32);
typedef struct { s16 x; s16 y; f32 t; f32 amp; s16 lo; s16 hi; s16 out; s16 pad12; f32 cur; f32 prev; f32 max; } WaterState;
extern f32 func_800D8FF8(void);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern u8 _idwater_entrypoint_0[];
extern void _glid_entrypoint_2(s32, s32, void *, void *);

void idwater_entrypoint_0(s32 param_0, s16 *param_1, s16 *param_2, s16 *param_3)
{
  param_2[1] = param_3[8] + param_1[1];
  param_2[4] = param_1[4] + param_3[0];
  param_2[5] = param_1[5] + param_3[1];
}

int idwater_entrypoint_1(param_0) s16 param_0[5];
{
  unsigned char new_var4;
  s16 *new_var2;
  s16 *new_var;
  int new_var3;
  new_var3 = 0xFFu;
  new_var4 = 0xFFu;
  new_var4 = ((new_var4 & new_var3) & new_var3) & new_var3;
  new_var2 = &param_0[((((((new_var4 & new_var3) & new_var4) & 0xFFu) & new_var3) & new_var4) & new_var4) & new_var3];
  return *(s16*)((s8*)param_0 + 16);
  ;
}

void idwater_entrypoint_2(s32 arg0) 
{
}
void idwater_entrypoint_3(WaterEffectState *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    param_0->local_0[0] = 0;
    param_0->local_0[1] = 0;
    param_0->local_1 = func_800DC264(0.0f, 1.0f);
    param_0->local_2 = (f32)param_1;
    param_0->local_3[0] = 0;
    param_0->local_3[1] = 0;
    param_0->local_3[2] = 0;
    param_0->local_4[0] = 0.0f;
    param_0->local_4[1] = 0.0f;
    param_0->local_4[2] = 0.0f;
}

void idwater_entrypoint_4(WaterState *param_0, s32 param_1, s32 param_2)
{
    f32 local_0;
    f32 local_1;
    f32 local_2[2];
    f32 local_4;
    f32 local_5;

    local_1 = func_800D8FF8();
    param_0->t += local_1;
    local_5 = func_800138D0(param_0->t * 0.2f * 180.0f);
    local_2[0] = (150.0f * local_5 + func_80013970(param_0->t * 0.08f * 180.0f) * 100.0f) * 0.8f;
    local_5 = func_80013970(param_0->t * 0.5f * 180.0f);
    local_2[1] = (50.0f * local_5 + func_800138D0(param_0->t * 0.22f * 180.0f) * 100.0f) * 0.8f;
    if (local_2[0] >= 0.0f) {
        param_0->x = local_2[0] + 0.5f;
    } else {
        param_0->x = local_2[0] - 0.5f;
    }
    if (local_2[1] >= 0.0f) {
        param_0->y = local_2[1] + 0.5f;
    } else {
        param_0->y = local_2[1] - 0.5f;
    }
    local_5 = func_800138D0(param_0->t * 0.5f * 180.0f);
    local_4 = func_80013970(param_0->t * 0.11f * 180.0f) * (param_0->amp * 0.25f) + param_0->amp * 0.75f * local_5;
    if (param_0->cur < param_0->max) {
        param_0->prev = param_0->cur;
        param_0->cur += local_1;
        if (param_0->max < param_0->cur) {
            param_0->cur = param_0->max;
        }
    }
    if (param_0->cur < param_0->max) {
        local_0 = param_0->lo + param_0->cur / param_0->max * (param_0->hi - param_0->lo);
    } else {
        local_0 = param_0->hi;
    }
    local_0 += local_4;
    if (local_0 >= 0.0f) {
        param_0->out = local_0 + 0.5f;
    } else {
        param_0->out = local_0 - 0.5f;
    }
    _glid_entrypoint_2(param_1, param_2, _idwater_entrypoint_0, param_0);
}
