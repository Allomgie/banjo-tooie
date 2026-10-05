#include "common.h"

typedef struct { u16 id:12; u16 type:4; s16 n; } AnimTrack;
typedef struct { u16 local_0:12; u16 local_7:4; s16 local_1; } EntryE0170;
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 pad; EntryE0170 local_3[1]; } StateE0170;
extern f32 func_800E04C0(EntryE0170 *, f32, s32);
extern void func_800E084C(s32, f32 *, s32);
extern float D_80125D70;
f32 func_800E0414(u8 *param_0, f32 param_1);

void func_800E0050(u8 *param_0, f32 param_1, s32 param_2, f32 *param_3) {
    f32 local_0;
    s32 found;
    s32 i;
    AnimTrack *p;
    s32 type;
    local_0 = func_800E0414(param_0, param_1);
    param_3[0] = param_3[1] = param_3[2] = 0.0f;
    param_3[6] = param_3[7] = param_3[8] = 0.0f;
    param_3[3] = param_3[4] = param_3[5] = 1.0f;
    found = 0;
    p = (AnimTrack *)(param_0 + 8);
    for (i = 0; i < *(s16 *)(param_0 + 4); i++) {
        type = p->type;
        if (param_2 != p->id) {
            if (found) {
                return;
            }
        } else {
            found = 1;
            if (type >= 9) {
                type -= 9;
            }
            param_3[type] = func_800E04C0(p, local_0, 0);
        }
        p = (AnimTrack *)((u8 *)p + p->n * 4 + 4);
    }
}

void func_800E0170(StateE0170 *param_0, f32 param_1, s32 param_2, s32 param_3) {
    f32 local_1;
    s32 local_2;
    EntryE0170 *local_3;
    s32 local_4;
    f32 local_0[12];
    s32 local_5;
    s32 local_6;
    local_1 = func_800E0414(param_0, param_1);
    local_2 = param_2 ? param_0->local_1 - param_0->local_0 : 0;
    local_3 = param_0->local_3;
    local_4 = 0;
    for (local_5 = 0; local_5 < param_0->local_2; local_5++) {
        if (local_4 != (local_3->local_0)) {
            if (local_4) func_800E084C(param_3, local_0, local_4);
            local_4 = local_3->local_0;
            local_0[0] = local_0[1] = local_0[2] = 0.0f; local_0[3] = local_0[4] = local_0[5] = 1.0f; local_0[6] = local_0[7] = local_0[8] = 0.0f;
        }
        local_6 = local_3->local_7;
        if (local_6 >= 9) local_6 -= 9;
        local_0[local_6] = func_800E04C0(local_3, local_1, local_2);
        local_3 += local_3->local_1;
        local_3++;
    }
    func_800E084C(param_3, local_0, local_4);
}

void func_800E02F8(u8 *param_0, f32 param_1, s32 param_2, s32 param_3, s32 param_4, f32 *param_5) {
    f32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    u32 local_4;
    u32 local_5;
    u8 *local_6;

    local_0 = func_800E0414(param_0, param_1);
    local_3 = 0;
    if (param_2 != 0) {
        local_1 = (*(s16 *)((s8 *)param_0 + 2)) - (*(s16 *)((s8 *)param_0 + 0));
    } else {
        local_1 = 0;
    }
    local_6 = param_0 + 8;
    local_2 = 0;
    if ((*(s16 *)((s8 *)param_0 + 4)) > 0) {
        do {
            local_4 = (*(u16 *)((s8 *)local_6 + 0));
            local_5 = local_4 >> 4;
            if (((s32)local_5 >= param_3) && (param_4 >= (s32)local_5) && ((local_4 & 0xF) == 7)) {
                *(param_5 + local_3) = func_800E04C0(local_6, local_0, local_1);
                local_3 += 1;
            }
            local_2 += 1;
            local_6 += ((*(s16 *)((s8 *)local_6 + 2)) * 4) + 4;
        } while (local_2 < (*(s16 *)((s8 *)param_0 + 4)));
    }
}

f32 func_800E0414(u8 *param_0, f32 param_1)
{
  s16 new_var2;
  s16 *new_var;
  s16 temp_v0;
  new_var = (s16 *) (((s8 *) param_0) + 0);
  temp_v0 = *new_var;
  return (param_1 * ((f32) ((*((s16 *) (((s8 *) param_0) + 2))) - temp_v0))) + ((f32) (new_var2 = temp_v0));
}

s16 func_800E0440(s32 param_0)
{
  return *(s16 *)(param_0 + 2);
}

s16 func_800E0448(s16 *param_0) {
    return param_0[0];
}

func_800E0450(s16 *param_0){
    return (param_0[1] - param_0[0]) + 1;
}

func_800E0464(s16 *param_0) {
    return param_0[2];
}

float func_800E046C(u8 *param_0, s32 param_1)
{
  s16 temp_v0;
  s16 temp_v1;
  ;
  if (param_1 == (*((s16 *) (((char *) param_0) + 2))))
  {
    return D_80125D70;
  }
  temp_v1 = *((s16 *) (((char *) param_0) + 0));
  return ((float) (param_1 - temp_v1)) / ((float) ((*((s16 *) (((char *) param_0) + 2))) - temp_v1));
}

func_800E04AC(void *param_0){
    s32 local_0;
}
