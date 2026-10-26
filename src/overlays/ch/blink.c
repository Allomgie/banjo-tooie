#include "common.h"

extern f32 func_800DC178(f32, f32);
extern u8 func_800DC128(s32, s32);
typedef struct { f32 local_0[2]; f32 local_1[2]; f32 local_2[2]; u8 pad_0[0xC]; s32 local_3; s32 pad_1; } BlinkStorage;
extern void *func_8001B798();
typedef struct { f32 duration; u8 kind; u8 pad_0[3]; f32 minimum; f32 maximum; } BlinkStep;
typedef struct { u8 pad_0[0x18]; f32 timer; s32 index; } BlinkSequence;
extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);
typedef struct { f32 cur[2]; f32 target[2]; f32 speed[2]; } BlinkState;
extern f32 D_80800430_chblink;
extern void func_8001B754();
extern s32 D_80800580_chblink[][3];
extern f32 func_800F1214(f32, f32, f32);

void chblink_entrypoint_0(u8 *param_0, s32 param_1) {
    *(s32 *)(param_0 + 0x28) = param_1;
    *(f32 *)(param_0 + 0x18) = func_800DC178(0.0f, 5.0f);
    *(s32 *)(param_0 + 0x1C) = func_800DC128(0, 0x14);
}

s16 chblink_entrypoint_1(s32 param_0)
{
    s16 local_0;
    BlinkStorage *local_1;
    s32 local_2;
    local_0 = func_8001B668(0, 0x2C);
    local_1 = func_8001B798(local_0);
    local_1->local_3 = param_0;
    for (local_2 = 0; local_2 < 2; local_2++) {
        local_1->local_2[local_2] = 0.0f;
        local_1->local_1[local_2] = 0.0f;
        local_1->local_0[local_2] = 0.0f;
    }
    chblink_entrypoint_0(local_1, 2);
    return local_0;
}

int func_808000CC_chblink(volatile f32 *param_0, s32 param_1, f32 param_2, f32 param_3)
{
  f32 local_0;
 param_0[param_1 + 2] = param_2; if (param_3 != 0.0f) {
    param_0[param_1 + 4] = (param_0[param_1 + 2] - param_0[param_1]) / param_3;
  }
  else
  {
    param_0[param_1] = param_0[param_1 + 2];
  }
}

void func_80800118_chblink(BlinkSequence *param_0, BlinkStep *param_1, s32 param_2)
{
    f32 local_0;
    BlinkStep *local_1;
    local_0 = func_800D8FF8();
    while (local_0 > 0.0f) {
        param_0->timer -= local_0;
        if (param_0->timer > 0.0f) break;
        local_0 = mlAbsF(param_0->timer);
        local_1 = &param_1[param_0->index];
        func_808000CC_chblink(param_0, local_1->kind, local_1->minimum, local_1->maximum);
        local_1++;
        if (local_1->kind == 2) {
            local_1 = param_1;
            if (!param_2) {
                chblink_entrypoint_0(param_0, 1);
                break;
            }
            param_0->index = 0;
        } else {
            param_0->index++;
        }
        param_0->timer = local_1->duration;
    }
}

void chblink_entrypoint_2(param_0) s16 param_0;
{
    BlinkState *local_0;
    f32 local_1;
    s32 i;

    local_0 = func_8001B798(param_0);
    local_1 = func_800D8FF8();
    func_80800118_chblink(local_0, &D_80800430_chblink, 1);
    for (i = 0; i < 2; i++) {
        if (local_0->target[i] != local_0->cur[i]) {
            local_0->cur[i] += local_0->speed[i] * local_1;
            if ((0.0f < local_0->speed[i] && local_0->target[i] < local_0->cur[i]) || (local_0->speed[i] < 0.0f && local_0->cur[i] < local_0->target[i])) {
                local_0->cur[i] = local_0->target[i];
            }
        }
    }
}

void chblink_entrypoint_3(param_0) s16 param_0; {
    func_8001B754(param_0);
}

void chblink_entrypoint_4(param_0) s16 param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_8001B798(param_0);
    for (local_1 = 0; local_1 < 2; local_1++) {
        local_2 = D_80800580_chblink[*(s32 *)(local_0 + 0x24)][local_1];
        if (local_2 != -1) {
            func_800DF744(local_2, (s32)func_800F1214(*(f32 *)local_0, 1.0f, D_80800580_chblink[*(s32 *)(local_0 + 0x24)][2]));
        }
    }
}
