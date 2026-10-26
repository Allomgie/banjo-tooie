#include "common.h"

typedef struct { u8 pad_0[0x184]; s16 local_0; u16 pad_1; s32 local_1; } SplineFindList;
typedef struct { u8 pad_0[2]; u8 local_0; u8 pad_1[0x11]; f32 local_1[1][3]; } SplineFindPath;
extern void *func_800D7400(void);
extern void *func_8001B798();
typedef struct { u8 pad_0[0x184]; s16 spline_list; s16 pad_1; s32 count; } SplineLevelData;
typedef struct { u8 pad_0[2]; u8 count; u8 pad_1[0x11]; f32 positions[1][3]; } SplinePointList;
s32 glsplinefind_entrypoint_2();
s32 glsplinefind_entrypoint_3();

s32 glsplinefind_entrypoint_0(f32 param_0[3], f32 param_1[3]) {
    f32 local_0[3];
    s32 out;

    out = _gccubesearch_entrypoint_2(param_0, local_0);
    if (out == 0) {
        return -1;
    }
    func_800EE84C(param_1, local_0);
    return glsplinefind_entrypoint_2(local_0);
}

int glsplinefind_entrypoint_1(s32 param_0)
{
  s32 local_0[3];
  if (!_gccubesearch_entrypoint_2(param_0, local_0))
  {
    return -1;
  }
  return glsplinefind_entrypoint_2(local_0);
}

s32 glsplinefind_entrypoint_2(this) Actor *this;{
    f32 local_0[3];
    func_800EE84C(local_0, this);
    return glsplinefind_entrypoint_3(local_0);
}

s32 glsplinefind_entrypoint_3(param_0) f32 param_0[3];
{
    SplineFindList *local_0;
    SplineFindPath *local_1;
    f32 (*local_2)[3];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s16 *local_7;

    local_0 = func_800D7400();
    for (local_3 = 0, local_4 = 0; local_3 < local_0->local_1; local_3++, local_4 += 2) {
        local_7 = func_8001B798(local_0->local_0);
        local_5 = 0;
        local_1 = func_8001B798(*(s16 *)((u8 *)local_7 + local_4));
        local_6 = local_1->local_0;
        local_2 = local_1->local_1;
        if (local_6 > 0) {
            do {
                if (func_800EECE0(param_0, *local_2)) return local_3;
                local_5++;
                local_2++;
            } while (local_5 != local_6);
        }
    }
    return -1;
}

s32 glsplinefind_entrypoint_4(f32 *param_0, f32 *param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_6[3];
    f32 local_7[3];
    SplineLevelData *local_3;
    SplinePointList *local_4;
    f32 *local_5;
    local_3 = func_800D7400();
    func_800EE84C(local_6, param_0);
    func_800EE84C(local_7, param_1);
    for (local_0 = 0; local_0 < local_3->count; local_0++) {
        local_4 = func_8001B798(((s16 *)func_8001B798(local_3->spline_list))[local_0]);
        local_1 = local_4->count;
        local_5 = local_4->positions[0];
        for (local_2 = 0; local_2 < local_1; local_2++, local_5 += 3) {
            if (func_800EECE0(local_6, local_5) && func_800EECE0(local_7, local_5 + 3)) return local_0;
        }
    }
    return -1;
}
