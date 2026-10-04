#include "core2/1E6A730.h"

extern s32 D_80117DB0;
extern f32 func_800DC178(f32, f32);
extern void func_8009DF94(s32, s32, f32, s32);
extern s32 func_8008FD48();
extern void func_80092E5C();
extern void func_80092DE4();
extern void func_800BABB8(s32, s32, s32, s32, s32 *);
int func_800DC128(int, int);
extern f32 func_800D8FF8(void);
extern void func_800D9078(void *);
extern f32 func_800DC0C0(void);
extern s32 func_800F40EC(void *);
typedef struct { u8 pad[0x10]; f32 local_0, local_1; } ParticleTimers91290;
typedef struct { u8 pad[0x30]; ParticleTimers91290 *local_0; } Player91290;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80092C90(PlayerState *, f32 *, s32);
extern void *func_8009FBB0(PlayerState *, f32 *, f32);
extern void func_800BA930(void *, s32, s32, s32, s32, s32, s32);
extern void func_800BA6B0(void *, s32, s32, s32, s32, s32, s32);
extern void func_800BA7C4(void *, f32, f32);
extern void func_800BA7FC(void *, f32, f32);
extern void func_800BA8F8(void *, f32, f32);
extern void func_800BA22C(void *, s32);
void func_800910BC();

s32 func_80090E40(void)
{
	return 0x18;
}

void func_80090E48(u8 *param_0)
{
  s32 pad1;
  s32 pad2;
  s32 local_0;
  u8 *local_1;
  if (((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 0xD))) == 0) || (func_8008FD48(param_0) != 1))
  {
    func_80092E5C(param_0, &local_0);
  }
  else
  {
    func_80092DE4(param_0, &local_0);
  }
  func_800BABB8(func_8009FBB0(param_0, &local_0, 0.0f), ((*((f32 *) (((s8 *) local_1) + 0))) == 0.0f) * 0, 0, 0x3F800000, &D_80117DB0);
  local_1 = *((u8 **) (((s8 *) param_0) + 0x30));
  if (((*((u8 *) (((s8 *) local_1) + 0xF))) != 0) && ((*((f32 *) (((s8 *) local_1) + 0))) == 0.0f))
  {
    *((f32 *) (((s8 *) local_1) + 0)) = 0.12f;
    func_8009DF94(param_0, 0x3ED, func_800DC178(0.5, 0.7f), 0x1770);
  }
}

void func_80090F38(u8 *param_0) {
    f32 temp_f0;

    *(f32 *)(*(u8 **)(param_0 + 0x30) + 8) = 0.0f;
    temp_f0 = func_800DC0C0();
    if (temp_f0 < 0.5f) {
        *(f32 *)(*(u8 **)(param_0 + 0x30) + 4) = func_800DC178(0.6f, 0.7f);
        *(s8 *)(*(u8 **)(param_0 + 0x30) + 0xC) = 1;
        return;
    }
    if (temp_f0 < 0.7f) {
        *(f32 *)(*(u8 **)(param_0 + 0x30) + 4) = func_800DC178(0.7, 1.0f);
        *(s8 *)(*(u8 **)(param_0 + 0x30) + 0xC) = func_800DC128(1, 4);
        return;
    }
    *(f32 *)(*(u8 **)(param_0 + 0x30) + 4) = func_800DC178(2.3f, 2.6f);
    *(s8 *)(*(u8 **)(param_0 + 0x30) + 0xC) = func_800DC128(6, 0xF);
}

void func_80091030(u8 *param_0) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x30)))) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x30)))) + (4))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x30)))) + (0xC))) = 1;
}

void func_80091054(s32 arg0) 
{

}

void func_8009105C(PlayerState *param_0) {
    (*(s8 **)((u8 *)param_0 + 0x30))[0xC] = 0;
    (*(f32 **)((u8 *)param_0 + 0x30))[1] = 2.0f;
    (*(s8 **)((u8 *)param_0 + 0x30))[0xE] = 0;
    (*(f32 **)((u8 *)param_0 + 0x30))[4] = 0.0f;
    (*(f32 **)((u8 *)param_0 + 0x30))[5] = 0.0f;
    (*(s8 **)((u8 *)param_0 + 0x30))[0xF] = 1;
    func_800910BC(param_0, 1);
}

void func_800910BC(param_0, param_1) PlayerState * param_0; s32 param_1;
{
  s32 *local_0;
  ;
  if ((*((u8 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0xE))) == 4)
  {
    *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0x4)) = 0.0f;
    *((u8 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0xC)) = 0;
    *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0x14)) = 0.0f;
    *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0x10)) = *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0x14));
  }
  *((u8 *) (((char *) (*((s32 **) (((char *) param_0) + 0x30)))) + 0xE)) = param_1;
}

void func_80091104(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x30)))[15] = v;
}

void func_80091110(u8 *param_0)
{
  f32 sp24;
  f32 temp_f0;
  u8 *temp_v0;
  u8 *temp_v0_2;
  u8 *temp_v0_3;
  u8 *temp_v0_4;
  s8 *new_var;
  func_800D9078(*((u8 **) (((s8 *) param_0) + 0x30)));
  if ((func_800F40EC(param_0) == 2) && ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 0xE))) != 4))
  {
    temp_f0 = func_800D8FF8();
    new_var = (s8 *) param_0;
    sp24 = temp_f0;
    temp_v0 = *((u8 **) (new_var + 0x30));
    if ((*((u8 *) (((s8 *) temp_v0) + 0xC))) != 0)
    {
      *((f32 *) (((s8 *) (*((u8 **) (new_var + 0x30)))) + 8)) = (f32) ((*((f32 *) (((s8 *) (*((u8 **) (new_var + 0x30)))) + 8))) - temp_f0);
      if ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 8))) < 0.0f)
      {
        *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 8)) = func_800DC178(0.066f, 0.1f);
        temp_v0_2 = *((u8 **) (((s8 *) param_0) + 0x30));
        *((u8 *) (((s8 *) temp_v0_2) + 0xC)) = (u8) ((*((u8 *) (((s8 *) temp_v0_2) + 0xC))) - 1);
        func_80090E48(param_0);
      }
    }
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 4)) = (f32) ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 4))) - sp24);
    ;
    if (!((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 4))) > 0.0f))
    {
      if ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 0xE))) == 3)
      {
        func_80091030(param_0);
      }
      else
      {
        func_80090F38(param_0);
      }
      temp_v0_4 = *((u8 **) (((s8 *) param_0) + 0x30));
      if ((*((u8 *) (((s8 *) temp_v0_4) + 0xE))) == 2)
      {
        *((s8 *) (((s8 *) temp_v0_4) + 0xD)) = 1;
        return;
      }
      if (func_800DC0C0() >= 0.5f)
      {
        *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 0xD)) = 0;
        return;
      }
      *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x30)))) + 0xD)) = 1;
    }
  }
}

void func_80091290(PlayerState *param_0, f32 param_1, s32 param_2, s32 param_3) {
    f32 local_0;
    f32 local_1[3];
    void *local_2;
    s32 local_3;
    f32 local_5;
    local_0 = func_800F10B4(param_1, 5.0f, 20.0f, 4.0f, 0.7f);
    func_80092C90(param_0, local_1, param_3);
    ((Player91290 *)param_0)->local_0->local_0 += param_1 * func_800D8FF8();
    local_3 = (s32)((Player91290 *)param_0)->local_0->local_0;
    ((Player91290 *)param_0)->local_0->local_0 -= local_3;
    local_2 = func_8009FBB0(param_0, local_1, 40.0f);
    func_800BA930(local_2, -60, -50, -60, 60, 100, 60);
    if (param_2) {
        func_800BA6B0(local_2, -50, -70, -50, 50, 70, 50);
        local_5 = 0.09f;
        func_800BA7C4(local_2, local_5, 0.1f);
        func_800BA7FC(local_2, 0.2f, 0.22f);
    } else {
        func_800BA7C4(local_2, 0.09f, 0.09f);
        func_800BA7FC(local_2, 0.12f, 0.12f);
    }
    func_800BA8F8(local_2, local_0, local_0);
    for (param_3 = 0; param_3 < local_3; param_3++) func_800BA22C(local_2, 1);
    if (param_1 > 3.0f) param_1 = func_800F10B4(param_1, 3.0f, 60.0f, 3.0f, 8.0f);
    ((Player91290 *)param_0)->local_0->local_1 += param_1 * func_800D8FF8();
    local_3 = (s32)((Player91290 *)param_0)->local_0->local_1;
    ((Player91290 *)param_0)->local_0->local_1 -= local_3;
}

void func_800914FC(s32 param_1, f32 param_2, s32 param_3)
{
    func_80091290(param_1, param_2, param_3, 4);
}
