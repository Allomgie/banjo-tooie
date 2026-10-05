#include "core2/1EEBA50.h"

extern f32 func_800F5BC4(s32, s32);
extern void *func_80110840(void *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F10B4(f32,f32,f32,f32,f32);
extern f32 func_800F5AE0(void *);
extern f32 func_80013728(f32);
extern void func_800EFA4C(f32 *,f32,f32,f32);
extern void func_800EF368(f32 *,f32);
extern void func_800EE7F8(void *, s32);
void func_801124D0();

s32 func_80112160() 
{
    return 0x34;
}

f32 func_80112168(PlayerState *param_0, s32 param_1)
{
  f32 local_2C;
  f32 local_20[3];
  s32 local_1C;

  local_1C = func_80110840(param_0);
  local_2C = func_800F5BC4(local_1C, param_1);
  func_800F5A00(local_1C, local_20);
  func_800EF04C(param_1, local_20);
  return local_2C;
}

void func_801121B8(PlayerState* arg0, f32* arg1)
{
    func_80112168(arg0,arg1);
}

int func_801121D8(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_80110840(param_0);
  func_800F5A00(local_0 | 0, param_1);
}

void func_80112204(PlayerState *param_0, s32 param_1)
{
  Vec3f local_0;
  func_80112168(param_0, param_1);
  func_800F5470(func_80110840(param_0), &local_0);
  if (1)
  {
    *((f32 *) (((char *) param_1) + 0)) = local_0.f[0];
    *((f32 *) (((char *) param_1) + 8)) = local_0.f[2];
  }
  return;
}

void func_80112250(void *param_0, f32 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2, local_3, local_4;
    void *local_5;
    local_5 = func_80110840(param_0);
    func_80112168(param_0, param_1);
    func_801107F0(param_0, local_1);
    local_2 = func_800EEAD4(local_1, param_1);
    func_800EFA4C(local_0, 0.0f, 200.0f, 0.0f);
    func_800F51F0(local_5, local_0, local_0);
    local_3 = func_800F10B4(local_2, 700.0f, 1500.0f, 100.0f, 200.0f);
    local_4 = func_80013728(func_800F5AE0(local_5));
    if (local_4 < 0.0f) local_3 *= func_800F10B4(local_4, -30.0f, -60.0f, 1.0f, 0.0f);
    func_800EF368(local_0, local_3);
    func_800EF04C(param_1, local_0);
}

void func_80112354(PlayerState *param_0, f32 *param_1)
{
  f32 *var_a;
  func_80112168(param_0, param_1);
  ;
  param_1[0] = (*((f32 **) (((char *) param_0) + 0x30)))[10];
  param_1[2] = (*((f32 **) (((char *) param_0) + 0x30)))[12];
}

int func_80112398(Actor *param_0)
{
  s32 *local_0;
  ;
  *((s32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0x0)) = 0;
  func_801124D0(param_0, 1);
  func_800EFD24(&(*((s32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0x4))));
}

void func_801123D4(u8 *param_0) {
    f32 local_0[3];
    switch (*(*(s32 **)(param_0 + 0x30))) {
    case 1:
    case 5:
        func_801121B8(param_0, local_0);
        break;
    case 4:
        func_801121D8(param_0, local_0);
        break;
    case 3:
        func_80112250(param_0, local_0);
        break;
    case 2:
        func_80112204(param_0, local_0);
        break;
    case 6:
        func_80112354(param_0, local_0);
        break;
    }
    if (func_8010FFD0(func_80110898(param_0)) != 0) {
        func_800EE7F8(*(u8 **)(param_0 + 0x30) + 4, local_0);
        return;
    }
    func_80111F70(param_0, local_0, *(s32 *)(param_0 + 0x30) + 4, *(s32 *)(param_0 + 0x30) + 0x10, *(s32 *)(param_0 + 0x30) + 0x14);
}

void func_801124D0(param_0, param_1) void * param_0; s32 param_1;
{
    if (param_1 == 6) {
        func_801121B8(param_0, *(s32 *)((u8 *)param_0 + 0x30) + 0x28);
    }
    **(s32 **)((u8 *)param_0 + 0x30) = param_1;
}

u32 func_80112518(void *param_0) {
    return ((u32 **)param_0)[0x30 / 4][0];
}

void func_80112524(PlayerState *param_0, f32 param_1[3]) {
    func_800EE7F8(param_1, *(s32 *)((char *)param_0 + 0x30) + 4);
}

f32 func_80112550(PlayerState* arg0, f32* arg1)
{
    func_80112168(arg0,arg1);
}

void func_80112570(void *param_0, s32 param_1, f32 param_2) {
    func_800EE7F8((*(u8 **)((u8 *)param_0 + 0x30)) + 0x18, param_1);
    *(f32 *)((*(u8 **)((u8 *)param_0 + 0x30)) + 0x24) = param_2;
}
