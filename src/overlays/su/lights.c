#include "common.h"

typedef struct { u8 local_0; u8 local_1; u8 pad_0[0x32]; f32 local_2; u32 pad_1; } LightSlot;
extern void *D_80127EF0;
extern void *vector_new(s32, s32);
extern void *vector_end(void *);
extern void *vector_begin(void *);
extern void *vector_push_back(void **);
extern void func_800C8E84();
typedef struct { u8 pad_0; u8 local_0; u8 pad_1[2]; s32 local_1[3]; s32 local_2[3]; u8 pad_2[0x18]; f32 local_3; f32 local_4; } LightColorStep;
typedef struct { u8 local_0; u8 local_1; u8 pad_0[0x1A]; f32 local_2[3]; f32 local_3[3]; f32 local_4; f32 local_5; } LightPositionState;
extern void func_800C8D4C(s32, f32 *);
typedef struct { u8 pad_0; u8 handle; u8 pad_1[2]; s32 center[3]; s32 range[3]; u8 pad_2[0x18]; f32 time; f32 speed; } LightState30;
extern f32 func_800DC0C0(void);
typedef struct { u8 pad[4]; s32 x[3]; s32 y[3]; u8 pad2[0x18]; f32 f34; } LightS;
typedef struct { u8 unused[0x1C]; f32 position[3]; f32 velocity[3]; f32 timer; } LightMotionState;
typedef struct { u8 local_0; u8 pad_0[0x33]; f32 local_1; f32 local_2; } LightUpdate27;
typedef struct { void (*local_0)(LightUpdate27 *); void (*local_1)(LightUpdate27 *); } LightCallbacks27;
extern LightCallbacks27 D_80800A00_sulights[];
extern f32 func_800D8FF8(void);
extern void func_800EE830(s32 *, s32 *);
typedef struct { u32 local_0; s32 local_1[3]; s32 local_2[3]; u8 pad_0[0x1C]; f32 local_3; } CodexLightTween;
typedef struct { s32 local_0; s32 local_1[3]; s32 local_2[3]; u8 pad_0[0x1C]; f32 local_3; } LightColorTransition;
void sulights_entrypoint_0(s32 param_0, s32 *param_1, s32 *param_2, f32 param_3);
void sulights_entrypoint_2(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3);

f32 *func_80800000_sulights(s32 param_0, s32 param_1)
{
    LightSlot *local_0;
    LightSlot *local_1;

    if (!D_80127EF0) D_80127EF0 = vector_new(sizeof(LightSlot), 1);
    local_1 = vector_end(D_80127EF0);
    local_0 = vector_begin(D_80127EF0);
    while (local_0 < local_1 && local_0->local_0) local_0++;
    if (local_0 == local_1) local_0 = vector_push_back(&D_80127EF0);
    local_0->local_0 = param_0;
    local_0->local_1 = param_1;
    local_0->local_2 = 0.0f;
    return (f32 *)local_0;
}

s32 func_808000D0_sulights(u8 *param_0){
    *param_0 = 0;
}

void func_808000D8_sulights(LightColorStep *param_0)
{
    s32 local_0[4];
    s32 local_1;
    f32 local_2;
    local_2 = param_0->local_3 / param_0->local_4;
    for (local_1 = 0; local_1 < 3; local_1++) {
        local_0[local_1] = param_0->local_1[local_1] + param_0->local_2[local_1] * local_2;
    }
    func_800C8E84(param_0->local_0, local_0);
}

void func_80800194_sulights(LightPositionState *param_0)
{
    s32 local_2;
    f32 local_0[2];
    f32 local_1;
    local_1 = param_0->local_4 / param_0->local_5;
    for (local_2 = 0;  local_2 < 2; local_2++) {
        local_0[local_2] = param_0->local_2[local_2] + param_0->local_3[local_2] * local_1;
    }
    func_800C8D4C(param_0->local_1, local_0);
}

void func_8080021C_sulights(LightState30 *param_0)
{
    s32 local_2;
    s32 local_0[3];
    f32 local_1;
    local_1 = func_800DC0C0() > 0.5f ? 1.0f : -1.0f;
    func_800C8900(param_0->handle, local_0);
    for (local_2 = 0; local_2 < 3; local_2++) {
        local_0[local_2] += local_1 * (param_0->speed * param_0->range[local_2] * param_0->time);
        if (param_0->range[local_2] + param_0->center[local_2] < local_0[local_2])
            local_0[local_2] = param_0->range[local_2] + param_0->center[local_2];
        if (local_0[local_2] < param_0->center[local_2] - param_0->range[local_2])
            local_0[local_2] = param_0->center[local_2] - param_0->range[local_2];
    }
    func_800C8E84(param_0->handle, local_0);
    param_0->time = 0.0f;
}

void func_80800340_sulights(LightS *param_0) {
    s32 i;
    param_0->f34 = 0.0f;
    for (i = 0; i < 3; i++) {
        param_0->x[i] += param_0->y[i];
        param_0->y[i] *= -1;
    }
}

void func_8080038C_sulights(LightMotionState *param_0)
{
    s32 local_0;

    param_0->timer = 0.0f;
    for (local_0 = 0; local_0 < 2; local_0++) {
        param_0->position[local_0] += param_0->velocity[local_0];
        param_0->velocity[local_0] *= -1.0f;
    }
}

void sulights_entrypoint_0(s32 param_0, s32 *param_1, s32 *param_2, f32 param_3)
{
    s32 local_1;
    CodexLightTween *local_0;

    local_0 = (CodexLightTween *)func_80800000_sulights(1, param_0);
    if (param_3 < 0.001f) {
        local_0->local_3 = 0.001f;
    } else {
        local_0->local_3 = param_3;
    }
    func_800EE830(local_0->local_1, param_1);
    for (local_1 = 0; local_1 != 3; local_1++) {
        local_0->local_2[local_1] = param_2[local_1] - param_1[local_1];
    }
    func_800C8E84(param_0, param_1);
}

s32 sulights_entrypoint_1(s32 param_0, s32 param_1, f32 param_2) {
    f32 local_0[3];

    func_800C8900(param_0, local_0);
    sulights_entrypoint_0(param_0, local_0, param_1, param_2);
}

void sulights_entrypoint_2(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    f32 *local_0;
    s32 local_1;
    local_0 = func_80800000_sulights(2, param_0);
    local_0[14] = param_3 < 0.001f ? 0.001f : param_3;
    for (local_1 = 0; local_1 < 2; local_1++) {
        local_0[7 + local_1] = param_1[local_1];
        local_0[10 + local_1] = param_2[local_1] - param_1[local_1];
    }
    func_800C8D4C(param_0, param_1);
}

s32 sulights_entrypoint_3(s32 param_0, s32 param_1, f32 param_2) {
    f32 local_0[2];

    func_800C883C(param_0, local_0);
    sulights_entrypoint_2(param_0, local_0, param_1, param_2);
}

void sulights_entrypoint_4(s32 param_0, s32 *param_1, s32 *param_2, f32 param_3)
{
    LightColorTransition *local_0;
    f32 local_1;
    local_0 = (LightColorTransition *)func_80800000_sulights(3, param_0);
    if (param_3 < 0.001f) local_1 = 0.001f;
    else local_1 = param_3;
    local_0->local_3 = 4.0f / local_1;
    local_0->local_1[0] = param_1[0];
    local_0->local_1[1] = param_1[1];
    local_0->local_1[2] = param_1[2];
    local_0->local_2[0] = param_2[0];
    local_0->local_2[1] = param_2[1];
    local_0->local_2[2] = param_2[2];
    func_800C8E84(param_0, param_1);
}

void sulights_entrypoint_5(s32 param_0, s32 *param_1, s32 *param_2, f32 param_3)
{
    LightColorTransition *local_0;
    s32 local_1;

    local_0 = (LightColorTransition *)func_80800000_sulights(4, param_0);
    if (param_3 < 0.001f) {
        local_0->local_3 = 0.001f;
    } else {
        local_0->local_3 = param_3 * 0.5f;
    }
    local_0->local_1[0] = param_1[0];
    local_0->local_1[1] = param_1[1];
    local_0->local_1[2] = param_1[2];
    for (local_1 = 0; local_1 < 3; local_1++) {
        local_0->local_2[local_1] = param_2[local_1] - param_1[local_1];
    }
    func_800C8E84(param_0, param_1);
}

void sulights_entrypoint_6(s32 param_0[3], f32 param_1[3], f32 param_2[3], f32 param_3)
{
  s32 local_0;
  int local_2;
  f32 *local_1 = func_80800000_sulights(5, param_0);
  if (param_3 < 0.001f)
  {
    local_1[14] = 0.001f;
  }
  else
  {
    local_1[14] = param_3 / 2.0f;
  }
  for (local_0 = 0; local_0 < 2; local_0++)
  {
    local_1[7 + local_0] = param_1[local_0];
    local_2 = 10 + local_0;
    local_1[local_2] = param_2[local_0] - param_1[local_0];
  }

  func_800C8D4C(param_0, param_1);
}

void sulights_entrypoint_7(long param_0)
{
  u8 *local_0;
  u8 *local_2;
  u8 *local_3;
  if (D_80127EF0 != 0) {
    local_3 = vector_end(D_80127EF0);
    local_2 = vector_begin(D_80127EF0);
    local_0 = local_2;
    if (local_2 < local_3) {
      do {
        if ((local_0[0] != 0) && (param_0 == local_0[1])) {
          func_808000D0_sulights(local_0);
        }
        local_0 += 0x3C;
      } while (local_0 < local_3);
    }
  }
}

s32 sulights_entrypoint_8(void){
    if(((s32) D_80127EF0) != 0){
        vector_free(((s32) D_80127EF0));
        D_80127EF0 = 0;
    }
}

void sulights_entrypoint_9(void)
{
    LightUpdate27 *local_0;
    LightUpdate27 *local_1;
    f32 local_2;

    local_2 = func_800D8FF8();
    local_1 = vector_end(D_80127EF0);
    for (local_0 = vector_begin(D_80127EF0); local_0 < local_1; local_0++) {
        if (local_0->local_0) {
            local_0->local_1 += local_2;
            if (local_0->local_1 > local_0->local_2) {
                local_0->local_1 = local_0->local_2;
            }
            D_80800A00_sulights[local_0->local_0 - 1].local_0(local_0);
            if (local_0->local_1 >= local_0->local_2) {
                if (D_80800A00_sulights[local_0->local_0 - 1].local_1) {
                    D_80800A00_sulights[local_0->local_0 - 1].local_1(local_0);
                }
            }
        }
    }
}
