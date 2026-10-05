#include "common.h"

extern void func_800DFCC0();
typedef struct { s16 field_0, field_2, field_4; } LocalEntry;
typedef struct { LocalEntry *field_0, *field_4; } LocalPool;
typedef union { LocalPool p; u32 a[2]; s32 s; } Pool80126CC0;
Pool80126CC0 D_80126CC0;
extern LocalEntry *D_80126CC4;
extern void *heap_realloc(void *, u32);
s32 func_800DFCE8();
s32 func_800DFD10();
typedef struct { u8 pad_0[8]; u8 field_8; u8 pad_9; s16 field_A, field_C, field_E; u8 pad_10[10]; u8 field_1A, field_1B, field_1C, field_1D; } LocalObject;
LocalEntry *func_8008BAC0();
void func_8008BBC0();
int func_8008C1B8();
void func_8008C1C0(f32 *param_0, f32 param_1);
int func_8008C1D4();
int func_8008C1E4(f32 *param_0, f32 param_1);

void func_8008B610(void) {
    s32 local_0;
    s32 local_1;

    local_1 = heap_alloc(0x3C);
    local_0 = local_1 + 0x3C;
    (*(s32 *)((s8 *)(((s32 *) D_80126CC0.a)) + (0))) = local_1;
    (*(s32 *)((s8 *)(((s32 *) D_80126CC0.a)) + (4))) = local_0;
    func_8008BBC0(local_1, local_0);
}

void func_8008B64C(void)
{
  s16 *p;
  for (p = (s16 *)D_80126CC0.a[0]; p < (s16 *)D_80126CC0.a[1]; p += 3) {
    if (p[2] != 0) {
      if (p[0] != 0) {
        func_800DFCC0(p[0]);
        p[0] = 0;
      }
      p[2] = 0;
    }
  }
  heap_free((void *)D_80126CC0.a[0]);
  D_80126CC0.a[1] = 0;
  D_80126CC0.a[0] = 0;
}

int func_8008B6E0()
{
  s16 *local_0;
  local_0 = (s16 *) ((s32 *) D_80126CC0.a)[0];
  while (local_0 < ((s16 *) ((s32 *) D_80126CC0.a)[1]))
  {
    if (((local_0[2] != 0) && (local_0[0] != 0)) && (local_0[1] <= 0x3A))
    {
      func_800DFCC0(local_0[0]);
      local_0[0] = 0;
    }
    local_0 += 3;
  }

}

void func_8008B768(void)
{
    LocalEntry *local_0;
    s32 local_1 = 0;
    for (local_0 = D_80126CC0.p.field_0; local_0 < D_80126CC0.p.field_4; local_0++) {
        if (local_0->field_4) {
            local_0->field_2 = 0;
            func_800DFCC0(local_0->field_0);
            local_0->field_0 = 0;
            local_1 = local_0 - D_80126CC0.p.field_0 + 1;
        }
    }
    if (local_1 < 10) local_1 = 10;
    D_80126CC0.p.field_0 = heap_realloc(D_80126CC0.p.field_0, local_1 * sizeof(LocalEntry));
    D_80126CC0.p.field_4 = D_80126CC0.p.field_0 + local_1;
}

void func_8008B850(void)
{
    LocalEntry *local_0;
    for (local_0 = D_80126CC0.p.field_0; local_0 < D_80126CC0.p.field_4; local_0++) {
        if (!local_0->field_4) continue;
        if (local_0->field_0) {
            local_0->field_2--;
            if (local_0->field_2 <= 0) {
                func_800DFCC0(local_0->field_0);
                local_0->field_0 = 0;
            }
        }
    }
}

s16 func_8008B8E0(void)
{
  s32 sp1C;
  LocalEntry *local_1;
  local_1 = func_8008BAC0(&sp1C);
  local_1->field_2 = 0;
  local_1->field_0 = 0;
  return sp1C;
}

s32 func_8008B90C(param_0) s16 param_0;
{
    s16 *ptr = (s16 *)(param_0 * 6 + D_80126CC0.s - 6);
    s32 result;

    if (*ptr) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void func_8008B954(param_0) s16 param_0;
{
  u8 *local_2;
  unsigned int local_1;
  local_2 = (param_0 * 6) + D_80126CC0.s;
  local_1 = *((s16 *) (local_2 - 6));
  local_2 -= 6;
  if (local_1 != 0)
  {
    func_800DFCC0((s16) local_1, local_1);
    *((s16 *) local_2) = 0;
  }
  *((s16 *) (local_2 + 4)) = 0;
  *((s16 *) (local_2 + 2)) = *((s16 *) (local_2 + 4));
}

s32 func_8008B9C4(s16 param_0, s32 *param_1)
{
  u8 *local_2;
  s32 local_1;
  local_2 = (param_0 * 6) + D_80126CC0.s;
  local_1 = *((s16 *) (local_2 - 6));
  local_2 -= 6;
  *((s16 *) (local_2 + 2)) = 0x3C;
  if (local_1 != 0)
  {
    *param_1 = func_800DFCE8((s16) local_1);
    return 0;
  }
  *((s16 *) local_2) = func_800DFD10();
  local_1 = *((s16 *) local_2);
  *param_1 = func_800DFCE8(local_1);
  return 1;
}

void func_8008BA5C()
{
  int local_0;
  local_0 = (((int *) D_80126CC0.a)[1] - ((int *) D_80126CC0.a)[0]) / 6;
  ((int *) D_80126CC0.a)[0] = defrag(((int *) D_80126CC0.a)[0]);
  ((int *) D_80126CC0.a)[1] = ((int *) D_80126CC0.a)[0] + (((0, local_0)) * 6);
}

LocalEntry *func_8008BAC0(param_0) s32 * param_0;
{
    LocalEntry *local_0;
    s32 local_1;
    s32 local_2;
    for (local_0 = D_80126CC0.p.field_0; local_0 < D_80126CC0.p.field_4; local_0++) {
        if (!local_0->field_4) break;
    }
    if (local_0 == D_80126CC0.p.field_4) {
        local_1 = D_80126CC0.p.field_4 - D_80126CC0.p.field_0;
        local_2 = local_1 + 10;
        D_80126CC0.p.field_0 = heap_realloc(D_80126CC0.p.field_0, local_2 * sizeof(LocalEntry));
        D_80126CC4 = D_80126CC0.p.field_0 + local_2;
        local_0 = D_80126CC0.p.field_0 + local_1;
        func_8008BBC0(local_0, D_80126CC0.p.field_4);
    }
    local_0->field_4 = 1;
    *param_0 = local_0 - D_80126CC0.p.field_0 + 1;
    return local_0;
}

void func_8008BBC0(param_0, param_1) u32 param_0; u32 param_1;
{
  s16 temp_t6;
  u32 new_var;
  u32 var_v0;
  var_v0 = param_0;
  if (param_0 < param_1)
  {
    do
    {
      *((s16 *) (((s8 *) var_v0) + 4)) = 0;
      new_var = *((s16 *) (((s8 *) var_v0) + 4));
      temp_t6 = new_var;
      var_v0 += 6;
      new_var = var_v0;
      *((s16 *) (((s8 *) new_var) + (-6))) = 0;
      *((s16 *) (((s8 *) new_var) + (-4))) = temp_t6;
    }
    while (var_v0 < param_1);
  }
}

void func_8008BBF0(s32 arg0, s32 arg1)
{
  s32 sp1C;
  long new_var;
  new_var = arg1 * 2;
  if (func_8008B9C4(*((s16 *) ((arg0 + new_var) + 0xA)), &sp1C) == 0)
  {
    func_800DFAD0(sp1C);
  }
}

int func_8008BC2C(u8 *param_0)
{
  u8 local_0;
  local_0 = param_0[1];
  func_8008BBF0(param_0, param_0[8]);
}

void func_8008BC4C(s32 arg0)
{
    func_8008BBF0(arg0,0x2);
}

int func_8008BC6C(s16 *param_0, s32 param_1)
{
  char new_var3;
  int new_var4;
  s16 *new_var2;
  int new_var;
  new_var = param_1;
  new_var3 = -1;
  new_var2 = param_0;
  func_8008B90C(*((s16 *) (((s8 *) (&new_var2[new_var])) + (new_var4 = 10))));
}

int func_8008BC94(param_0) u8 * param_0;
{
  u8 local_0;
  local_0 = param_0[1];
  func_8008BC6C(param_0, param_0[8]);
}

int func_8008BCB4(u8 *param_0)
{
  s32 local_8;
  u8 *new_var2;
  void *new_var;
  new_var = param_0;
  new_var2 = (u8 *) param_0;
  ;
  if (new_var2[8] != 0) {
    local_8 = 0;
  } else {
    local_8 = 1;
  }
  func_8008BC6C(new_var, local_8);
}

int func_8008BCEC(s16 *param_0, s32 param_1)
{
  s32 local_0;
  func_8008B9C4(param_0[param_1 + 5], &local_0);
  return local_0;
}

int func_8008BD1C(param_0) u8 * param_0;
{
  u8 local_0;
  local_0 = param_0[1];
  func_8008BCEC(param_0, param_0[8]);
}

int func_8008BD3C(void *param_0)
{
  s32 local_8;
  u8 *new_var2;
  void *new_var;
  new_var = param_0;
  new_var2 = (u8 *) param_0;
  ;
  if (new_var2[8] != 0) {
    local_8 = 0;
  } else {
    local_8 = 1;
  }
  func_8008BCEC(new_var, local_8);
}

int func_8008BD74(s32 arg0)
{
    func_8008BCEC(arg0,0x2);
}

void func_8008BD94(u8 *param_0) {
    if (((*(u8 *)((s8 *)param_0 + 0x1B)) == 1) && (func_8008BC94() != 0)) {
        if ((*(u8 *)((s8 *)param_0 + 8)) != 0) {
            (*(u8 *)((s8 *)param_0 + 8)) = 0U;
        } else {
            (*(u8 *)((s8 *)param_0 + 8)) = 1U;
        }
    }
    (*(u8 *)((s8 *)param_0 + 0x1B)) = 0U;
    if (((*(f32 *)((s8 *)param_0 + 0x14)) < 1.0f) && (func_8008BCB4(param_0) != 0)) {
        func_800E0170(func_800D674C(*(s16 *)((s8 *)param_0 + 0x18)), *(s32 *)((s8 *)param_0 + 0x10), *(u8 *)((s8 *)param_0 + 0x1E), func_8008BD1C(param_0));
        func_800DFD64(func_8008BD1C(param_0), func_8008BD3C(param_0), func_8008BD1C(param_0), *(s32 *)((s8 *)param_0 + 0x14));
        return;
    }
    func_800E0170(func_800D674C(*(s16 *)((s8 *)param_0 + 0x18)), *(s32 *)((s8 *)param_0 + 0x10), *(u8 *)((s8 *)param_0 + 0x1E), func_8008BD1C(param_0));
}

void func_8008BEB4(param_0) void * param_0;
{
  int new_var;
  s32 local_2;
  s32 local_1;
  s32 local_0;
  local_0 = ((u8 *) param_0)[0x1B];
  new_var = 0;
  if ((local_0 == 1) && (!((u8 *) param_0)[0x1D]))
  {
    if (func_8008BC94() != 0)
    {
      if (((u8 *) param_0)[0x8] != new_var)
      {
        ((u8 *) param_0)[0x8] = 0;
      }
      else
      {
        ((u8 *) param_0)[0x8] = 1;
      }
      func_8008BC4C(param_0);
    }
  }
  else
    if (local_0 == 2)
  {
    func_8008BC2C(param_0);
  }
  ((u8 *) param_0)[0x1B] = new_var;
  if (((*((float *) (&((u8 *) param_0)[0x14]))) < 1.0f) || ((u8 *) param_0)[0x1A])
  {
    if (func_8008BCB4(param_0) != 0)
    {
      if (!((u8 *) param_0)[0x1D])
      {
        ((u8 *) param_0)[0x1A] = 0;
        local_2 = func_800D674C(*((s16 *) (((u8 *) param_0) + 0x18)));
        func_800E0170(local_2, *((s32 *) (((u8 *) param_0) + 0x10)), ((u8 *) param_0)[0x1E], func_8008BD74(param_0));
        local_1 = func_8008BD1C(param_0);
        local_2 = func_8008BD3C(param_0);
        func_800DFD64(local_1, local_2, func_8008BD74(param_0), *((s32 *) (((u8 *) param_0) + 0x14)));
        return;
      }
    }
  }
  local_2 = func_800D674C(*((s16 *) (((u8 *) param_0) + 0x18)));
  func_800E0170(local_2, *((s32 *) (((u8 *) param_0) + 0x10)), ((u8 *) param_0)[0x1E], func_8008BD1C(param_0));
  if (((u8 *) param_0)[0x1D] != 0)
  {
    if ((*((s16 *) (((u8 *) param_0) + 0x18))) != new_var)
    {
      ((u8 *) param_0)[0x1D] = 0;
    }
  }
}

void func_8008C038(u8 *param_0) {
    if ((*(u8 *)((s8 *)(param_0) + (0x1C))) == 1) {
        func_8008BEB4();
    } else {
        func_8008BD94(param_0);
    }
    if ((*(s32 (**)(s32, s32))((s8 *)(param_0) + (0))) != NULL) {
        (*(s32 (**)(s32, s32))((s8 *)(param_0) + (0)))(func_8008BD1C(param_0), (*(s32 *)((s8 *)(param_0) + (4))));
    }
}

void func_8008C0AC(s32 param_0) {
    *(u8 *)(param_0 + 0x1B) = 1;
}

s32 func_8008C0B8(void)
{
	return 0x20;
}

s32 func_8008C0C0(s32 param_0) {
    return (s16)*(s16 *)(param_0 + 0x18);
}

f32 func_8008C0C8(f32 param_0[5])
{
  f32 new_var3;
  int new_var;
  int new_var2;
  new_var = 3;
  new_var++;
  ;
  return param_0[new_var2 = new_var];
  new_var--;
}

f32 func_8008C0D0(f32 *arg) {
    return arg[5];
}

s32 func_8008C0D8(s32 *param_0)
{
    func_8008B954(*(s16 *)((u8 *)param_0 + 0xA));
    func_8008B954(*(s16 *)((u8 *)param_0 + 0xC));
    if (*((u8 *)param_0 + 0x1C) == 1) {
        func_8008B954(*(s16 *)((u8 *)param_0 + 0xE));
    }
}

void func_8008C124(LocalObject *param_0, s32 param_1)
{
    param_0->field_1C = param_1;
    func_8008C1B8(param_0, 0);
    func_8008C1C0(param_0, 0);
    func_8008C1E4(param_0, 1.0f);
    func_8008C1D4(param_0, 0);
    param_0->field_1B = 0;
    param_0->field_1D = 1;
    param_0->field_1A = 0;
    param_0->field_8 = 0;
    param_0->field_A = func_8008B8E0();
    param_0->field_C = func_8008B8E0();
    if (param_0->field_1C == 1) param_0->field_E = func_8008B8E0();
}

int func_8008C1B8(param_0, param_1) s32 param_0; int param_1;
{
  *((s16 *) (((u8 *) param_0) + 0x18)) = param_1;
}

void func_8008C1C0(f32 *param_0, f32 param_1)
{
  int new_var;
  new_var = 3 & 0xFFFFFFFFu;
  new_var++;
  param_0[new_var] = param_1;
  new_var--;
}

void func_8008C1CC(s32 param_0, s32 param_1) {
    *(u8 *)(param_0 + 0x1E) = param_1;
}

func_8008C1D4(param_0, param_1) s32 * param_0; s32 param_1;{
    *param_0 = param_1;
}

func_8008C1DC(s32 *param_0, s32 param_1){
    param_0[1] = param_1;
}

func_8008C1E4(f32 *param_0, f32 param_1){
    param_0[5] = param_1;
}

func_8008C1F0(u8 *param_0, s32 param_1){
    u8 local_0 = 1;
    param_0[0x1A] = local_0;
}

int func_8008C200(param_0, param_1, param_2) s16 param_0; s32 param_1; s32 param_2;
{
  u32 local_0;
  local_0 = func_8008BD1C(param_2 | 0);
  func_800AE1E8(param_0, param_1, local_0 | 0);
}

int func_8008C238(param_0, param_1, param_2) s16 param_0; s32 param_1; s32 param_2;
{
  u32 local_0;
  local_0 = func_8008BD1C(param_2 | 0);
  func_800AE290(param_0, param_1, local_0 | 0);
}

func_8008C270(param_0)
    s32 param_0;
{
    ((u8*)param_0)[0x1B] = 2;
}

int func_8008C27C()
{
  func_8008BD1C();
}
