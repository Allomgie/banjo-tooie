#include "common.h"

extern int D_80132DB4;
extern s32 func_800B3CDC();
extern void func_800BE4C4(void);
extern s32 D_80132DB0;
typedef struct { u32 local_0:30; u32 local_1:1; u32 local_2:1; u32 local_3; u32 local_4:16; u32 local_5:5; u32 local_6:5; u32 local_7:1; u32 local_8:1; u32 local_9:1; u32 local_10:1; u32 local_11:1; u32 local_12:1; } local_type;
extern f32 func_800DC0C0(void);
typedef struct { u8 pad[4]; u32 unused:16; u32 value:9; u32 flags:6; u32 flag:1; s16 short_value; u8 byte_a, byte_b; void *pointer; u32 unused2:22; u32 flag12b:1; u32 flag12a:1; u32 flag13a:1; u32 flag13b:1; u32 flag13c:1; u32 flag13d:1; u32 pair13a:2; u32 pair13b:2; } LocalRecord;
void func_800EBE24(u32);
void *func_800B422C(u32 *, s32);
u32 *func_800BE5C4();
extern void func_800B42A0();
void func_800E9CF4();
s32 func_800E9D68();
int func_800E9DD4();
int func_800E9E88();
int func_800E9EB4();

void func_800E96E0()
{
    func_800EA3A0();
    func_800EBB6C();
}

void func_800E9708()
{
    func_800EA370();
}

void func_800E9728()
{
  func_800EA390();
  func_800EB70C();
  D_80132DB0 = func_800B42FC(0x14, 0xA);
  D_80132DB4 = func_800B42FC(0xC, 0xA);
}

void func_800E9774(void) {
    func_800EA398();
    func_800EB750();
    func_800B42DC(((int) D_80132DB0));
    D_80132DB0 = 0;
    func_800B42DC(D_80132DB4);
    D_80132DB4 = 0;
}

int func_800E97C0()
{
  if (func_800EA09C() != 1)
  {
    func_800EA45C();
    func_800A5CFC();
    func_800EA51C();
  }
}

u8 *func_800E9804(param_0) u8 * param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;

    local_1 = *(s32 *)((u8 *) &D_80132DB4);
    local_2 = (s32) *(s16 *)(param_0 + 4);
    local_3 = func_800B3CDC(((u8 *) &D_80132DB4), param_0 + 4, param_0);
    local_0 = local_3;
    local_3[0xB] = (u8) (local_3[0xB] & 0xFFFE);
    if (local_1 != *(s32 *)((u8 *) &D_80132DB4)) {
        func_800BE4C4();
    } else if (local_2 != *(s16 *)(param_0 + 4)) {
        func_800E9CF4(param_0);
    }
    return local_0;
}

int func_800E9898(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_800B3CDC(&D_80132DB0, local_0);
}

local_type *func_800E98C0(void) {
    local_type *local_0;
    local_0 = func_800E9804();
    local_0->local_12 = 0;
    local_0->local_11 = 0;
    local_0->local_5 = 0;
    local_0->local_1 = 0;
    local_0->local_6 = (u32)(func_800DC0C0() * 32.0f);
    local_0->local_9 = 0;
    local_0->local_10 = 0;
    local_0->local_8 = 1;
    return local_0;
}

void func_800E99E0()
{
  typedef struct {
    u8 pad_0[0xB];
    u8 local_7 : 1;
    u8 local_6 : 1;
    u8 local_5 : 1;
    u8 local_4 : 1;
    u8 local_3 : 1;
    u8 local_2 : 1;
    u8 local_1 : 1;
    u8 local_0 : 1;
  } Struct800E99E0;
  Struct800E99E0 *local_8;

  local_8 = func_800E9804();
  local_8->local_0 = 1;
  local_8->local_3 = 0;
  local_8->local_2 = 0;
  local_8->local_4 = 1;
}

void func_800E9A24(s32 param_0)
{
    LocalRecord *local_0;
    local_0 = func_800E9898(param_0);
    local_0->byte_b = 0;
    local_0->value = 50;
    local_0->flags = 0;
    local_0->flag = 0;
    local_0->byte_a = 0;
    local_0->short_value = 0;
    local_0->pointer = 0;
    local_0->flag12b = 0;
    local_0->flag12a = 1;
    local_0->flag13a = 0;
    local_0->flag13b = 0;
    local_0->flag13c = 0;
    local_0->flag13d = 0;
    local_0->pair13a = 0;
    local_0->pair13b = 0;
}

u32 func_800E9AC0(u8 *param_0, u8 *param_1) {
    u32 local_0;
    s32 local_3;
    s32 local_1;
    s32 local_2;

    local_0 = (u32) (*(s32 *)((char *)param_1 + 0x8) << 0x1E) >> 0x1F;
    local_3 = (s32) (param_1 - func_800E9E88()) / 12;
    local_1 = ((s32) D_80132DB4);
    local_2 = (s32) *(s16 *)((char *)param_0 + 0x4);
    func_800B3FD0(((s32 *) &D_80132DB4), param_0 + 4, local_3, param_0);
    if (local_1 != ((s32) D_80132DB4)) {
        func_800BE4C4();
    } else if ((local_2 + 1) != *(s16 *)((char *)param_0 + 0x4)) {
        func_800E9CF4(param_0);
    }
    return local_0;
}

int func_800E9B74(s32 param_0, s32 param_1)
{
  s32 local_0;
  u8 *local_1;
  local_0 = (param_1 - func_800E9D68()) / 0x14;
  if (local_0 < func_800E9DD4(param_0))
  {
    local_1 = func_800BE5C4(param_0);
    --*local_1;
  }
  func_800B3FD0(&D_80132DB0, param_0, local_0);
}

int func_800E9BF4(s16 *param_0, s32 param_1)
{
  if ((param_1 < 0) || (param_1 >= param_0[1]))
  {
    return 0;
  }
  return func_800E9D68(param_0) + (param_1 * 0x14);
}

void func_800E9C44(s32 param_0)
{
  s32 local_0;
  s32 *local_1;
  s32 *local_2;
  s32 *local_3;
  local_0 = func_800E9E88(param_0);
  if (local_0 != 0)
  {
    local_1 = func_800E9E88(param_0);
    local_2 = func_800E9EB4(param_0);
    while (local_1 < local_2)
    {
      if (local_1[2] & 1)
      {
        func_800EBE24(local_1[0]);
      }
      local_1 += 3;
    }

    func_800B422C(((u32 *) &D_80132DB4), param_0 + 4);
  }
  local_1 += 3;
  func_800B422C(((u32 *) &D_80132DB0), param_0);
  local_3 = func_800BE5C4(param_0);
  *((u8 *) local_3) = 0;
}

void func_800E9CF4(param_0) u8 * param_0;
{
    u32 sp1C;
    u32 temp_v0;
    u32 var_v1;

    if ((*(s16 *)((s8 *)param_0 + 6)) != 0)
    {
        sp1C = func_800E9E88();
        temp_v0 = func_800E9EB4(param_0);
        var_v1 = sp1C;
        if (var_v1 < temp_v0)
        {
            do
            {
                if (((*(s32 *)((s8 *)var_v1 + 8)) & 1) == 1)
                {
                    *(*(u32 **)((s8 *)var_v1)) = var_v1;
                }
                var_v1 += 0xC;
            } while (var_v1 < temp_v0);
        }
    }
}

s32 func_800E9D68(param_0) s32 param_0;{
    s32 local_0 = param_0;
    func_800B42A0(D_80132DB0, local_0);
}

s32 func_800E9D90(u8 *param_0)
{
  return ((*((s16 *) (((s8 *) param_0) + 2))) * 0x14) + func_800E9D68();
}

func_800E9DC4(s16 *param_0) {
    return param_0[1];
}

func_800E9DCC(s16 *param_0){
    return param_0[3];
}

int func_800E9DD4()
{
  u8 *local_0;
  local_0 = func_800BE5C4();
  return *local_0;
}

void func_800E9DF8(void)
{
    void *local_0;
    D_80132DB0 = defrag(((void *) D_80132DB0));
    local_0 = defrag(((void *) D_80132DB4));
    if (local_0 != ((void *) D_80132DB4)) {
        D_80132DB4 = local_0;
        func_800BE4C4();
    }
}

int func_800E9E4C(s32 param_0[3], s32 param_1)
{
  u8 *local_0;
  local_0 = func_800B4290(param_0 + 1);
  local_0 = func_800B4290(param_0);
  local_0 = (s32 *) func_800BE5C4(param_0);
  *local_0 = 0;
}

int func_800E9E88(param_0) u32 param_0;
{
    func_800B42A0(((u32) D_80132DB4), param_0 + 4, param_0);
}

int func_800E9EB4(param_0) s16 * param_0;
{
  volatile long new_var2;
  char new_var;
  new_var = 1;
  new_var = 0;
  ;
  return ((unsigned int) ((*((s16 *) (((s8 *) (&param_0[(new_var ^ new_var) ^ new_var])) - -6))) * 0xC)) + func_800E9E88();
}

void func_800E9EE8(s32 param_0) {
    s32 temp_v0;
    s32 sp18;

    temp_v0 = _gccubesearch_entrypoint_17(param_0, &sp18);
    if (temp_v0 != 0) {
        func_800E9B74(sp18, temp_v0);
    }
}
