#include "core2/1EDAEA0.h"

#define ACT(p) ((LocalActor_801015D0 *)(p))
extern s32 D_80135A90;
extern s16 D_80135A94;
typedef struct { u8 pad0[0x10]; s16 id; u8 pad12[2]; u16 model; } LocalDesc;
typedef struct { LocalDesc *desc; u8 pad4[0x6C]; u32 unused0:7, flag0:1, unused1:2, flag1:1, unused2:21; u32 word74; u32 unused3:16, mode:2, unused4:14; u32 unused5:19, disabled:1, unused6:7, updated:1, unused7:4; u8 pad80[0x1B], alpha; } LocalActor_801015D0;
extern f32 D_801243E0[2];
extern void (*D_801243E8[])(void);
typedef struct { u8 pad0[0x70]; u32 pad70_0 : 11; u32 unk70_11 : 1; u32 pad70_12 : 20; u8 pad74[0x20]; u32 pad94_0 : 1; u32 unk94_1 : 1; u32 pad94_2 : 30; } S80101970;
extern void func_800DF428(f32);
extern void func_800DF470(s32);
extern u8 *func_80100368(S80101970 *);
extern void func_800DF440(s32);
typedef struct { u8 pad[0x78]; u32 unused0:18, state:2, count:3, unused1:9; u32 unused2:19, disabled:1, unused3:12; } LocalActor_80101A50;
extern f32 func_800DC0C0(void);
f32 *func_80101918(f32 param_0);
void func_80101934();
void func_80101970();


void* func_800DE448(f32*, f32*, f32, f32*, s32);
void func_800DF47C(s32 (*arg0)(Actor*), Actor*);
f32* func_801027F4(Actor*);
s32 func_801015D0(Actor*);

int func_801015B0()
{
    return (int)&D_80135A90;
}

int func_801015BC()
{
  D_80135A94 = 0;
}

void func_801015C8(void) {
}

s32 func_801015D0(Actor *param_0)
{
    s32 local_7;
    LocalDesc *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    local_2 = func_801039E4(ACT(param_0)->desc);
    func_80103D48(param_0);
    local_3 = func_80104248(param_0);
    if (local_3) {
        if (!ACT(param_0)->disabled) func_8008B304(local_3);
        func_800DF41C(func_8008C27C(func_8008AEDC(local_3)));
    }
    local_0 = ACT(param_0)->desc;
    local_1 = _suexpression_entrypoint_20(param_0);
    if (local_1) _suexpression_entrypoint_19(local_1, param_0);
    if (local_0->id) {
        local_5 = func_80104248(param_0);
        local_4 = func_800B27E0(local_2);
        func_8010108C(param_0, 0x9C, local_2);
        if (local_5) {
            if (local_4) {
                if (!ACT(param_0)->disabled) func_8008C200(local_0->id, local_4, func_8008AEDC(local_5));
                func_800DF72C(func_800AE080(local_0->id));
            }
        } else if (local_4) func_800ADD80(local_0->id, local_4);
    }
    if (local_1) _suexpression_entrypoint_11(local_1, param_0);
    func_800DF410(ACT(param_0)->alpha);
    func_800DF830(ACT(param_0)->mode);
    func_800DF738(_subaddieskeleton_entrypoint_4(param_0));
    if (ACT(param_0)->flag0 || ACT(param_0)->flag1) func_800DF818(func_80103CDC(param_0, local_2));
    func_80106A98(param_0, local_2);
    func_80101934(param_0);
    local_6 = func_800D731C(ACT(param_0)->desc->model);
    local_7 = local_6 & 0xFF;
    if (local_6) func_800DF7E8(local_7);
    func_80103D70(param_0);
    ACT(param_0)->disabled = 1;
}

s32 func_801017D0(s32 *param_0)
{
  s32 *new_var;
  s32 local_0;
  local_0 = func_801039E4(*param_0);
  new_var = &local_0;
  return func_8010108C(param_0, 0x1F, *new_var);
}

// the real actor_draw?
s32 func_801018D8();

void func_80101808(Actor* arg0, s32 (*arg1)(Actor*)) {
    s32 pad[2];
    f32* sp2C;
    f32* sp28;

    func_800DF47C(arg1, arg0);
    sp28 = func_801027F4(arg0);
    sp2C = func_801018D8(arg0);
    func_800DE448(arg0->position, sp28, arg0->scale, sp2C, func_8010347C(arg0->unk0));
}

void func_80101870(Actor* arg0, void* arg1) {
    func_80101970(arg0);
    func_80101808(arg0, func_801015D0);
}

void func_801018A4(s32 param_0, s32 param_1)
{
  func_80101970();
  func_80101808(param_0, func_801017D0);
}

s32 func_801018D8(u8 *param_0)
{
    s32 local_0;

    local_0 = (*(u16 *)((char *)param_0 + 0x94) & 1) ? func_80101918(*(f32 *)((char *)param_0 + 0x38)) : 0;
    return local_0;
}

f32 *func_80101918(f32 param_0) {
    f32 *local_0 = D_801243E0;
    local_0[1] = -4.0f / param_0;
    return local_0;
}

void func_80101934(param_0) Actor * param_0;
{
  u32 new_var;
  u32 local_0;
  local_0 = 0xF & (*((s32 *) (((char *) param_0) + 0x74)));
  local_0 = 0xF & (*((s32 *) (((char *) param_0) + 0x74)));
  ;
  if (local_0 != 0)
  {
    D_801243E8[local_0]();
  }
}

void func_80101970(param_0) S80101970 * param_0;
{
  f32 var_f12;
  func_800DF470(param_0->unk70_11);
  var_f12 = (u32)*(u16 *)(func_80100368(param_0) + 0x1A);
  if (var_f12 != 0.0f)
  {
    func_800DF428(var_f12);
  }
  else if (!(*(s32 *)(*(u8 **)param_0 + 0x10) & 1))
  {
    if (func_800EA068(0x200) != 0)
    {
      var_f12 = 29999.0f;
    }
    else
    {
      var_f12 = (f32) func_800D2F20();
    }
    func_800DF428(var_f12);
  }
  if (param_0->unk94_1)
  {
    func_800DF440(0);
  }
}

void func_80101A50(LocalActor_80101A50 *param_0)
{
    if (!param_0->disabled) {
        switch (param_0->state) {
        case 0:
            if (func_800DC0C0() < 0.03f) param_0->state = 1;
            break;
        case 1:
            if (param_0->count == 3) param_0->state = 2;
            else param_0->count++;
            break;
        case 2:
            param_0->count--;
            if (!param_0->count) param_0->state = 0;
            break;
        }
    }
    func_800DF744(1, param_0->count + 1, param_0);
    func_800DF744(2, param_0->count + 1, param_0);
}

int func_80101BA0(s32 param_0)
{
  func_800DF744(1, 4);
  func_800DF744(2, 4);
}
