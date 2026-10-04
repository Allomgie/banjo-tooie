#include "core2/1EEEF00.h"

#define STATE(p) (*(LocalState **)((u8 *)(p)+0x3C))
extern f32 func_80013728(f32);
extern f32 func_80013A7C(f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF2A0(f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern void func_800F5680(s32, f32 *);
extern s32 func_800F6C5C(s32);
extern void func_801107B0();
extern void func_801107F0();
extern s32 func_80110840();
extern f32 func_800D8FF8(void);
extern f32 func_800F1344(f32, f32, f32, u32, f32);
extern f32 func_800136E4(f32);
extern f32 mlAbsF(f32);
extern void func_801160DC(void *,f32);
typedef struct { u8 pad0[0xC]; s32 mode; u8 pad10, flag11, flag12, pad13; f32 low, high; u8 pad1C, active, pad1E[2]; f32 target, current, velocity, elapsed, duration; } LocalState;
extern f32 func_80013B7C(f32, f32);
typedef struct { u8 pad[0x1D]; u8 active; u8 pad1[2]; f32 goal, current, unused, elapsed, duration; } LocalTurn;
typedef struct { u8 pad[0x3C]; LocalTurn *turn; } LocalActor;

s32 func_80115610() 
{
    return 0x38;
}

void func_80115618(u8 *param_0, f32 param_1, f32 param_2) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_5;
    s32 local_3;
    f32 local_6;
    f32 local_4[3];


    local_3 = func_80110840(param_0);
    if (func_800F6C5C(local_3) != 0) {
        func_800F5680(local_3, local_0);
        if (0.6f < local_0[1]) {
            func_801107B0(param_0, local_1);
            func_801107F0(param_0, local_4);
            func_800EF3DC(local_1, local_4);
            func_800EF2A0(local_1);
            local_5 = func_80013A7C(func_800EEAA4(local_1, local_0));
            local_6 = func_800F1DCC(90.0f, local_5);
            local_2 = func_80013728(param_1 + local_6 + param_2);
            if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x11))) != 0) {
                if ((*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0))) < local_2) {
                    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0))) = local_2;
                }
            } else {
                (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0))) = local_2;
                (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x11))) = 1U;
            }
            if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x12))) != 0) {
                local_2 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0)));
                if ((*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (4))) < local_2) {
                    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (4))) = local_2;
                }
            }
        }
    }
}

f32 func_80115750(u8 *param_0, f32 param_1) {
    f32 local_2;
    f32 local_3;
    f32 local_0;
    f32 local_1;
    if ((*(u8 **)(param_0 + 0x3C))[0x10] && !(*(u8 **)(param_0 + 0x3C))[0x1C]) {
        func_80115618(param_0, param_1, *(f32 *)(*(u8 **)(param_0 + 0x3C) + 8));
    }
    local_0 = *(f32 *)(*(u8 **)(param_0 + 0x3C) + 0);
    local_1 = *(f32 *)(*(u8 **)(param_0 + 0x3C) + 4);
    if ((*(u8 **)(param_0 + 0x3C))[0x11] && func_800F1DCC(param_1, local_0) < 0.0f) param_1 = local_0;
    if ((*(u8 **)(param_0 + 0x3C))[0x12] && func_800F1DCC(local_1, param_1) < 0.0f) param_1 = local_1;
    return param_1;
}

void func_80115828(u8 *param_0, f32 param_1, f32 param_2) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0))) = param_1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (4))) = param_2;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x11))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x12))) = 1;
}

func_80115858(s32 param_0, s32 param_1){
    *(s32*)(*(s32*)(param_0 + 0x3C) + 0xc) = param_1;
}

void func_80115864(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x3C)))[28] = v;
}

void func_80115870(u8 *param_0, f32 param_1) {
    if (param_1 == 0.0f) {
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x10))) = 0;
    } else {
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (0x10))) = 1;
    }
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x3C)))) + (8))) = param_1;
}

void func_801158B0(s32 param_0, f32 param_1, f32 param_2)
{
  int new_var;
  f32 *temp;
  ;
  new_var = 0x14;
  (*((f32 **) (param_0 + 0x3C)))[new_var / 4] = param_1;
 ; (*((f32 **) (param_0 + 0x3C)))[0x18 / 4] = param_2;
}

void func_801158CC(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void func_801158EC(f32 param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5)
{
  f32 *new_var;
  f32 sp38;
  f32 *new_var2;
  f32 sp30;
  f32 sp2C;
  f32 sp28;
  f32 var_f0;
  if (param_0 == (*param_1))
  {
    *param_2 = 0.0f;
    return;
  }
  sp30 = func_800D8FF8();
  sp38 = func_800F1DCC(param_0, *param_1);
  if (mlAbsF(sp38) < param_5)
  {
    *param_2 = func_800F1344(sp38, 0.0f, param_5, 0x41200000, param_4);
  }
  else
  {
    var_f0 = param_3 * sp30;
    if (sp38 < 0.0f)
    {
      var_f0 = -var_f0;
    }
    *param_2 += var_f0;
    if ((*param_2) < 0.0f)
    {
      if ((*param_2) < (-param_4))
      {
        *param_2 = -param_4;
      }
    }
    else
      if (param_4 < (*param_2))
    {
      *param_2 = param_4;
    }
  }
  sp2C = (*param_2) * sp30;
  sp28 = mlAbsF(sp2C);
  if ((mlAbsF(sp38) < sp28) && ((sp2C * sp38) > 0.0f))
  {
    *param_2 = 0.0f;
    new_var2 = &(*(new_var = &param_0));
    sp2C = 0.0f;
    *param_1 = *new_var2;
  }
  *param_1 = func_800136E4((*param_1) + sp2C);
}

void func_80115A9C(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[2];
    s32 local_4;
    STATE(param_0)->flag11 = STATE(param_0)->flag12 = 0;
    switch (STATE(param_0)->mode) {
    case 1: func_80115828(param_0, STATE(param_0)->low, STATE(param_0)->high); break;
    case 2: func_80115828(param_0, -80.0f, 80.0f); break;
    }
    if (STATE(param_0)->active) {
        STATE(param_0)->elapsed += func_800D8FF8();
        func_801158CC(param_0, local_0);
        func_801107F0(param_0, local_2);
        func_800EFB24(local_1, local_2, local_0);
        func_800F1A88(local_1, local_3);
        if (STATE(param_0)->duration < STATE(param_0)->elapsed) local_3[0] = STATE(param_0)->target;
        local_4 = mlAbsF(STATE(param_0)->target - local_3[0]) < 1.0f;
        func_80115828(param_0, STATE(param_0)->current, STATE(param_0)->target);
        func_801158EC(STATE(param_0)->target, &STATE(param_0)->current, &STATE(param_0)->velocity, 800.0f, 160.0f, 100.0f);
        func_801160DC(param_0, 0);
        if (local_4) STATE(param_0)->active = 0;
    }
}

void func_80115C40(void *param_0, float param_1)
{
    float temp_f0;
    void *temp_v0;

    temp_v0 = (*(void **)((char *)param_0 + 0x3C));
    if (((*(u8 *)((char *)temp_v0 + 0x11)) == 0) || !(param_1 < (*(float *)((char *)temp_v0 + 0)))) {
        if ((*(u8 *)((char *)temp_v0 + 0x12)) != 0) {
            temp_f0 = (*(float *)((char *)temp_v0 + 4));
            if (temp_f0 < param_1) {
                param_1 = temp_f0;
            }
        }
        (*(float *)((char *)temp_v0 + 0)) = param_1;
        (*(u8 *)((char *)(*(void **)((char *)param_0 + 0x3C)) + 0x11)) = 1U;
    }
}

void func_80115CA4(u8 *param_0, f32 param_1) {
    u8 *temp_v0;
    f32 temp_f0;
    temp_v0 = *(u8 **)((s8 *)(param_0) + 0x3C);
    if (*((u8 *)((s8 *)temp_v0 + 0x12)) == 0 || !(*(f32 *)((s8 *)temp_v0 + 4) < param_1)) {
        if (*((u8 *)((s8 *)temp_v0 + 0x11)) != 0) {
            temp_f0 = *(f32 *)((s8 *)temp_v0);
            if (param_1 < temp_f0) {
                param_1 = temp_f0;
            }
        }
        *(f32 *)((s8 *)temp_v0 + 4) = param_1;
        *(*(u8 **)((s8 *)(param_0) + 0x3C) + 0x12) = 1;
    }
}

void func_80115D08(void *p0, s32 p1, f32 p2, f32 p3, f32 p4) {
    f32 r;
    f32 a;
    f32 b;
    r = func_80013B7C(p3, p2);
    if (0.0f <= p4) { a = r; b = r + p4; }
    else { a = r + p4; b = r - p4; }
    func_801158B0(p0, func_800136E4(a), func_800136E4(b));
}

int func_80115D88(Actor *param_0)
{
    f32 local_0[3];
    f32 local_2[3];
    f32 local_1[3];

    func_801107F0(param_0, local_0);
    func_801158CC(param_0, local_1);
    func_800EFB24(local_2, local_0, local_1);
    func_800F1884(local_2, *((u8 **)((u8 *)param_0 + 0x3c)) + 0x24);
    *(f32 *)(*((u8 **)((u8 *)param_0 + 0x3c)) + 0x28) = 0.0f;
}

void func_80115DEC(LocalActor *param_0, f32 param_1, f32 param_2)
{
    if (!param_0->turn->active) func_80115D88(param_0);
    param_0->turn->goal = param_1;
    param_0->turn->elapsed = 0.0f;
    param_0->turn->duration = mlAbsF(func_800F1DCC(param_0->turn->goal, param_0->turn->current)) * 1.2f / param_2;
    param_0->turn->active = 1;
}

f32 func_80115E88(u32 param_0)
{

    return *(f32 *)((*(u32 **)(param_0 + 0x3C)) + 6);
}
