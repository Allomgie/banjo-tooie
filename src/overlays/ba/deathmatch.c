#include "common.h"
#include "playerstate.h"

extern u8 D_80800550_badeathmatch;
typedef struct { s16 local_0[8]; s16 local_1[8]; u8 local_2; } DeathmatchEggState;
typedef struct { u8 pad_0[0x158]; DeathmatchEggState *local_0; } DeathmatchEggPlayer;
typedef struct { u8 pad_0[0x21]; u8 local_0; u8 local_1; u8 local_2; } DeathmatchFlags1312;
extern s16 func_800F0D90();
typedef struct { u8 pad0[0x20]; u8 unk20; u8 unk21; } DeathmatchStateView;
typedef struct { u8 pad0[0x158]; DeathmatchStateView *unk158; } DeathmatchPlayerView;
extern void _batimer_set(PlayerState *, s32, f32);
typedef struct { s16 states[8]; s16 scores[8]; u8 pad_0, countdown; } DeathmatchScores1446;
typedef struct { u8 pad_0[0x158]; DeathmatchScores1446 *scores; } DeathmatchPlayer1446;
extern f32 _batimer_get(void *, s32);
void badeathmatch_entrypoint_8(PlayerState *param_0, f32 param_1);

void func_80800000_badeathmatch(void *arg0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x158)))) + (0x20))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x158)))) + (0x21))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x158)))) + (0x22))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x158)))) + (0x23))) = 0;
}

int func_80800028_badeathmatch(s32 param_0)
{
  u8 *local_0;
  local_0++;
  local_0 = &D_80800550_badeathmatch;
  local_0--;
  return local_0[param_0];
}

s32 badeathmatch_entrypoint_0(DeathmatchEggPlayer *param_0)
{
    DeathmatchEggState *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = param_0->local_0;
    local_2 = local_0->local_2;
    for (local_1 = 1; local_1 < 8; local_1++) {
        local_2 = func_80800028_badeathmatch(local_2);
        if (local_0->local_1[local_2]) break;
    }
    while (!local_0->local_0[local_2]) {
        local_2 = func_80800028_badeathmatch(local_2);
    }
    param_0->local_0->local_2 = local_2;
    func_800FC6B0(_gcegg_entrypoint_2(local_2));
    return local_2;
}

void badeathmatch_entrypoint_1(u8 *param_0) {
    s32 local_0;

    if (func_800EA068(0x40) != 0) {
        local_0 = heap_alloc(0x30);
        (*(s32 *)((s8 *)(param_0) + (0x158))) = local_0;
        aligned8_memset(local_0, 0, 0x30);
        func_80800000_badeathmatch(param_0);
    }
}

void badeathmatch_entrypoint_2(u8 *param_0)
{
  unsigned int new_var;
  s32 local_0;
  local_0 = *((s32 *) (((s8 *) param_0) + 0x158));
  new_var = local_0;
  if (local_0 != 0)
  {
    heap_free(new_var, param_0, *((s32 *) (((s8 *) param_0) + 0x158)));
    *((s32 *) (((s8 *) param_0) + 0x158)) = 0;
    func_800C968C(func_800A4C68(param_0), 9);
  }
}

void badeathmatch_entrypoint_3(PlayerState *param_0)
{
    DeathmatchFlags1312 *local_0;
    u8 local_1;

    if (func_800A3274() != 0x11 && bs_getCurrentState(param_0) != 0xD7) {
        local_0 = *(DeathmatchFlags1312 **)((u8 *)param_0 + 0x158);
        if (!local_0->local_0) {
            local_1 = local_0->local_2;
            if (((local_1 == 0) & 1) && bainput_func_80097D28(param_0)) {
                badeathmatch_entrypoint_0(param_0);
            }
        } else if (local_0->local_1 && _batimer_decrement(param_0, 0xD)) {
            badeathmatch_entrypoint_8(param_0, 0.0f);
        }
    }
}

int badeathmatch_entrypoint_4(int param_0)
{
  switch (param_0 - 0x40)
  {
    case 0 :
      return 1;

    case 1 :
      return 2;

    case 2 :
      return 3;

    case 3 :
      return 4;

    case 4 :
      return 5;

    case 5 :
      return 6;

  }

  return 0;
}

s16 badeathmatch_entrypoint_5(u8 *param_0, s32 param_1, s32 param_2)
{
    s16 local_0;
    s32 local_2;
    u8 *q;
    u8 *p;

    q = (u8 *)(param_1 * 2 + (s32)*(u8 **)(param_0 + 0x158));
    local_0 = *(s16 *)q;
    if (local_0 < 0) {
        return 1;
    }
    local_2 = *(s16 *)(q + 0x10) + param_2;
    *(s16 *)(*(u8 **)(param_0 + 0x158) + param_1 * 2 + 0x10) = func_800F0D90(local_2, 0, local_0, param_0);
    if (param_2 > 0) {
        p = *(u8 **)(param_0 + 0x158);
        local_2 = param_1 * 16;
        local_2 += *(s32 *)(param_0 + 0x184);
        if (*((s16 *)p + p[0x20] + 8) == 0) {
            p[0x20] = param_1;
        }
        func_80101238(0x72, local_2);
    }
    return *(s16 *)(*(u8 **)(param_0 + 0x158) + param_1 * 2 + 0x10);
}

u8 badeathmatch_entrypoint_6(DeathmatchPlayerView *param_0)
{
    DeathmatchStateView *local_0;
    u8 local_1;

    local_0 = param_0->unk158;
    if (local_0->unk21) {
        local_1 = 7;
    } else {
        local_1 = local_0->unk20;
    }
    return local_1;
}

void badeathmatch_entrypoint_7(s32 param_0, s32 param_1) {
    *(u8 *)(*(s32 *)(param_0 + 0x158) + 0x20) = param_1;
}

void badeathmatch_entrypoint_8(PlayerState *param_0, f32 param_1)
{
    if (param_1 != 0.0f) (*(u8 **)((u8 *)param_0 + 0x158))[0x21] = 1;
    else (*(u8 **)((u8 *)param_0 + 0x158))[0x21] = 0;
    if (param_1 > 0.0f) (*(u8 **)((u8 *)param_0 + 0x158))[0x22] = 1;
    else (*(u8 **)((u8 *)param_0 + 0x158))[0x22] = 0;
    _batimer_set(param_0, 0xD, param_1);
    if (!(*(u8 **)((u8 *)param_0 + 0x158))[0x21]) func_80101180(0x1CD, 0x76, 0);
}

s32 badeathmatch_entrypoint_9(DeathmatchPlayer1446 *param_0, s32 param_1)
{
    DeathmatchScores1446 *local_0;
    s32 local_1;
    s32 local_2;
    s16 *local_3;

    local_0 = param_0->scores;
    local_3 = local_0->states + param_1;
    if (local_0->countdown) {
        return (s32)(_batimer_get(param_0, 0xD) + 0.5f);
    }
    local_1 = local_3[0];
    local_2 = local_3[8];
    if (local_1 < 0) {
        local_1 = 1;
    } else {
        local_1 = local_2;
    }
    return local_1;
}

void badeathmatch_entrypoint_10(u8 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    (*(s16 **)(param_0 + 0x158))[param_1 + 8] = param_2;
    (*(s16 **)(param_0 + 0x158))[param_1] = param_3;
}

void badeathmatch_entrypoint_11(u8 *param_0, s32 param_1, s32 param_2) {
    u8 *local_0;
    u8 *local_1;

    if (param_2 != 0) {
        local_0 = (*(u8 **)((s8 *)(param_0) + (0x158)));
        (*(u8 *)((s8 *)(local_0) + (0x23))) = (u8) ((*(u8 *)((s8 *)(local_0) + (0x23))) | param_1);
        return;
    }
    local_1 = (*(u8 **)((s8 *)(param_0) + (0x158)));
    (*(u8 *)((s8 *)(local_1) + (0x23))) = (u8) ((*(u8 *)((s8 *)(local_1) + (0x23))) & ~param_1);
}
