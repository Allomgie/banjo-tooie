/*
 * 1ED2190 -- second half of the former 1ECE0B0, from func_800F88A0 on.
 * See 1ECE0B0.c for why the range is two objects.
 *
 * Functions defined in 1ECE0B0 are declared here in exactly the form their
 * definitions had (prototype for ANSI, empty parameter list for K&R), so
 * every call compiles as it did in the combined file.
 */

#include "core2/1ECE0B0.h"
#include "types.h"
u8 func_800F8B88(void);
extern s32 func_800DB9B0(void);
extern s32 _plsu_entrypoint_1(s32);
extern s32 D_801354F0;
typedef struct { u8 local_0; u8 local_1; u8 local_2; u8 pad3[0x19]; u8 local_1C; u8 local_1D; u8 pad1E[4]; s16 local_22; u8 local_24[0xC]; u8 local_30[0xC]; } EntryF8B94;
extern u8 D_80135510[];
extern u8 D_8013551C[];
extern u8 D_80135500[];
void func_800EE7F8();
void *vector_begin();
void *vector_end();
void func_800EFA4C(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
extern u8 D_801354FA;
extern void* vector_defrag(void*);
extern f32 func_800EEB40(f32*, f32*);
void func_800A16BC(s32);
extern u8 D_80135520;
extern u8 D_80135522[];
extern u8 D_80135521[];
extern s32 func_800EA05C(void);
void func_800F8B94();
void func_800F8D80();
void func_800F911C();
void func_800F9198();
int func_800F9214();
int func_800F99E8();
int func_800F9A24();
int func_800F9A44();
void func_800F9C6C();
extern u8 D_801354F8[];
extern u8 D_801354F9;
extern u8 D_801354FC;
extern u8 D_801354FD;
extern f32 D_8013550C;
s32 func_800F5410();
u32 func_800F54E4(void);
int func_800F58F8(s32 arg0);
int func_800F5924(s32 arg0);
void func_800F5A00(s32 arg0,f32* a1);
void func_800F5B38();
void func_800F608C(s32 param_0, s32 param_1);
int func_800F6204();
s32 func_800F6224(s32 param_0);
int func_800F65D0(s32 param_0);
int func_800F6720();
void func_800F759C(s32 param_0);
void func_800F7B9C(s32 arg0,u32 a1);
void func_800F7CF4(s32 param_0, f32 param_1[3], s32 arg2);
void func_800F7E64(s32 param_0, f32 param_1[3]);
void func_800F80D8(u32 arg0);
void func_800F8128(s32 arg0);
void func_800F8268(s32 arg0,s32 a1, s32 a2);
void func_800F8294(s32 arg0,f32* a1);
void func_800F82C0();
void func_800F82D4(s32 arg0,s32 arg1);
void func_800F832C(s32 arg0,f32* a1);
void func_800F8358(s32 param_0, s32 param_1);

u8 *func_800F88A0(param_0) s32 param_0;
{
  u8 *local_0;
  u8 *local_1;
  local_0 = vector_begin(((void *) D_801354F0), param_0);
  local_1 = vector_end(((void *) D_801354F0));
  if (local_0 < local_1)
  {
    do
    {
      if (param_0 == (*local_0))
      {
        return local_0;
      }
      local_0 += 0x3C;
    } while (local_0 < local_1);
  }
  return 0;
}

void func_800F8914(u8 *param_0, s32 param_1) {
    func_800F5A00(param_1, param_0 + 0x24);
    func_800F5B38(param_1, param_0 + 0x30);
    _plcamera_entrypoint_14(param_1, param_0 + 4, param_0 + 0x10);
    (*(s8 *)((s8 *)(param_0) + (2))) = func_800F9214(param_1);
    (*(s8 *)((s8 *)(param_0) + (0))) = func_800F5410(param_1);
    (*(s8 *)((s8 *)(param_0) + (1))) = func_800F65D0(param_1);
    (*(s16 *)((s8 *)(param_0) + (0x22))) = func_800EA05C();
    (*(s8 *)((s8 *)(param_0) + (0x21))) = func_800EA090();
    (*(s8 *)((s8 *)(param_0) + (0x20))) = 2;
    (*(s8 *)((s8 *)(param_0) + (0x1D))) = func_800F58F8(param_1);
    (*(s8 *)((s8 *)(param_0) + (0x1C))) = func_800F5924(param_1);
}

int func_800F89BC()
{
  u8 *local_0 = (u8 *)((s32 *) D_801354F8);
  if (*local_0 == 2)
  {
    return 0xb;
  }
  return 1;
}

int func_800F89E4(s32 param_0, s32 param_1)
{
  s32 local_0;
  if (param_0 == 0xA)
  {
    func_800EE7F8(param_1 | 0, ((s32 *) D_80135500));
    local_0 = (*((s32 *) D_8013551C));
  }
  else if (param_0 == 0xB)
  {
    func_800EE7F8(param_1 | 0, ((s32 *) D_80135510));
    local_0 = (*((s32 *) D_8013551C));
  }
  return local_0;
}

f32 func_800F8A50(void)
{
	return D_8013550C;
}

int func_800F8A5C()
{
    return *(s16 *)(func_800F88A0() + 0x22);
}

int func_800F8A80()
{
  u8 *local_0;
  local_0++;
  local_0 = func_800F88A0();
    return local_0[0x21];
}

u8 func_800F8AA4()
{
  u8 *local_0 = vector_begin(((void *) D_801354F0));
  u8 *local_1 = vector_end(((void *) D_801354F0));
  while (local_0 < local_1)
  {
    u8 val = (*((u8 *) (((char *) local_0) + 1))) ^ 0;
    if (val != 0)
    {
      return *local_0;
    }
    local_0 += 0x3C;
  }

  return 0;
}

int func_800F8B0C(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800F88A0(param_0);
  func_800EE7F8(param_1, local_0 + 0x24);
}

int func_800F8B38(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800F88A0(param_0);
  func_800EE7F8(param_1, local_0 + 0x30);
}

s32 func_800F8B64(void) {
	return (s32)D_801354F9;
}

u8 func_800F8B70(void) {
	return D_801354FC;
}

u8 func_800F8B7C(void)
{
	return D_801354FD;
}

u8 func_800F8B88(void) {
	return D_801354F8[0];
}

void func_800F8B94(void)
{
    s32 local_1;
    EntryF8B94 *local_2;
    EntryF8B94 *local_3;
    EntryF8B94 *local_4;
    s32 *local_0;
    s32 local_5;

    local_2 = (EntryF8B94 *)vector_begin(D_801354F0);
    local_3 = (EntryF8B94 *)vector_end(D_801354F0);
    for (local_4 = local_2; local_4 < local_3; local_4++) {
        if (func_800EA05C() == local_4->local_22) {
            local_1 = func_800F6204(0);
            func_800F7E64(local_1, local_5 = local_4->local_0);
            func_800F8268(local_1, local_4->local_1D, local_4->local_1C);
            if (D_801354F8[1] != 0 && (local_4->local_0 == 0xA || local_4->local_0 == 0xB)) {
                if (local_4->local_0 == 0xA) {
                    local_0 = ((s32 *) D_80135500);
                } else {
                    local_0 = ((s32 *) D_80135510);
                }
                func_800F8294(local_1, local_0);
            } else {
                func_800F8294(local_1, local_4->local_24);
            }
            func_800F832C(local_1, local_4->local_30);
            if (local_4->local_1 != 0) {
                func_800F80D8(local_1);
            }
            if (D_801354F8[0] != 1 && (local_4->local_0 == 0xA || local_4->local_0 == 0xB)) {
                func_800F8358(local_1, 1);
            }
            local_5 = local_4->local_2;
            switch (local_5) {
            case 1:
                break;
            case 2:
                func_800F608C(local_1, 2);
                break;
            }
            if (local_4->local_1 != 0) {
                func_800F8D80(local_1, local_4);
            }
        }
    }
}

int func_800F8D50(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800F88A0(param_1 | 0);
  func_800F8D80(param_0, local_0 | 0);
}

void func_800F8D80(param_0, param_1) s32 param_0; s32 param_1;
{
  _plcamera_entrypoint_12(param_0, param_1 + 4, param_1 + 0x10);
}

int func_800F8DA8()
{
  int local_0;
  if (func_800F88A0())
  {
    local_0 = 1;
  }
  else
  {
    local_0 = 0;
  }
  return local_0 | 0;
}

void func_800F8DD8(void){
    func_800F9A24();
    vector_free(D_801354F0);
    D_801354F0 = 0;
}

void func_800F8E08(void)
{
  s32 *local_0;
  ;
  *((s32 **) (((char *) (((u8 *) &D_801354F0))) + 0)) = (s32 *) vector_new(0x3C, 2);
  *((u8 *) (((char *) (&D_801354F8)) + 0x1)) = 0;
  *((u8 *) (((char *) (&D_801354F8)) + 0x4)) = 0;
  *((u8 *) (((char *) (&D_801354F8)) + 0x5)) = 0;
  *((u8 *) (((char *) (&D_801354F8)) + 0x0)) = 0;
  func_800F911C(1);
  func_800EFD24(&D_80135500);
  func_800EFD24(&D_80135510);
  *((s32 *) (((char *) (&D_8013551C)) + 0)) = 0;
  func_800F9A44();
}

s32 func_800F8E78(){
    s32 local_0 = func_800F88A0();
    if (local_0 != 0) {
        vector_erase(((void *) D_801354F0), vector_index_of(((void *) D_801354F0), local_0));
    }
}

void func_800F8EBC(s32 a0)
{
    func_800F8E78(func_800F5410(a0));
}

void func_800F8EE4(s32 param_0) {
    s32 temp_v0;

    temp_v0 = func_800F88A0(func_800F5410());
    if (temp_v0 != 0) {
        func_800F8914(temp_v0, param_0);
        return;
    }
    func_800F8914(vector_push_back(&D_801354F0), param_0);
}

void func_800F8F3C(void)
{
  u8 *temp_s2;
  u8 *temp_v0;
  u8 *var_s0;
  s32 temp_v0_2;
  if (((*((u8 *) (((s8 *) (((u8 *) D_801354F8))) + 0))) == 2) && (((u8 *) D_801354F0) != 0))
  {
    temp_s2 = vector_begin(((u8 *) D_801354F0));
    temp_v0 = vector_end(((u8 *) D_801354F0));
    var_s0 = temp_s2;
    if (temp_s2 < temp_v0)
    {
      do
      {
        ;
        if ((*((u8 *) (((s8 *) var_s0) + 0))) == 0xA)
        {
          func_800EE7F8(var_s0 + 0x24, ((u32 *) D_80135500));
          *((s16 *) (((s8 *) var_s0) + 0x22)) = (s16) (*((s32 *) (((s8 *) (((u8 *) D_801354F8))) + 0x24)));
          func_800EFA4C(var_s0 + 0x30, 0.0f, *((f32 *) (((s8 *) (((u8 *) D_801354F8))) + 0x14)), 0.0f);
        }
        else
          if ((*((u8 *) (((s8 *) var_s0) + 0))) == 0xB)
        {
          func_800EE7F8(var_s0 + 0x24, ((u32 *) D_80135510));
          *((s16 *) (((s8 *) var_s0) + 0x22)) = (s16) (*((s32 *) (((s8 *) (((u8 *) D_801354F8))) + 0x24)));
          func_800EFA4C(var_s0 + 0x30, 0.0f, *((f32 *) (((s8 *) (((u8 *) D_801354F8))) + 0x14)), 0.0f);
        }
        var_s0 += 0x3C;
      }
      while (var_s0 < temp_v0);
    }
  }
}

int func_800F9070(s32 param_0, s32 param_1)
{
  u8 *local_0;
  local_0 = func_800F88A0(param_0);
  local_0++;
  *local_0 = param_1;
  local_0--;
}

void func_800F9098(s32 param_0)
{
  if (param_0 == 0xA)
  {
    func_800EE7F8(((int *) D_80135500));
  }
  else
    if (param_0 == 0xB)
  {
    func_800EE7F8(((int *) D_80135510));
  }
  (*((int *) D_8013551C)) = func_800EA05C();
}

void func_800F90EC(f32 param_0)
{
  D_8013550C = param_0;
}

void func_800F90F8(s32 arg0) {
	D_801354F9 = arg0;
}

void func_800F9104(unsigned int param_0)
{
  D_801354FC = param_0;
}

int func_800F9110(int param_0)
{
  D_801354FD = param_0;
}

void func_800F911C(param_0) s32 param_0; {
    if ((*((u8 *) D_801354F8)) == 3) {
        func_800CF840(0);
    }
    (*((u8 *) D_801354F8)) = param_0;
    if ((*((u8 *) D_801354F8)) == 3) {
        func_800CF840(1);
    }
}

int func_800F9178()
{
  D_801354FA = 0;
}

int func_800F9184()
{
  return !D_801354FA;
}

void func_800F9198()
{
  if (!D_801354FA)
  {
    func_800F90F8(0);
    func_800F9104(0);
    func_800F9110(0);
    D_801354FA = 1;
  }
  func_800F9C6C();
}

void func_800F91EC()
{
    D_801354F0 = (s32)vector_defrag((void*)D_801354F0);
}

int func_800F9214()
{
  if (func_800F6720())
  {
    return 2;
  }
  return 1;
}

void func_800F9240(f32 *param_0, s32 param_1) {
    f32 sp1C[3];
    func_800F5A00(param_1, sp1C);
    sp1C[0] += 200.0f;
    func_800EFA4C(param_0, sp1C[0], sp1C[1], sp1C[2] + 200.0f);
}

int func_800F929C()
{
  if (func_800F8B88() == 2)
  {
    return 0xB;
  }
  return 1;
}

void func_800F92CC(s32 *param_0, volatile s32 *param_1, s32 *param_2, s32 *param_3)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800F54E4();
    *param_0 = local_0;
    local_1 = func_800F5410(local_0);
    *param_1 = local_1;
    switch (local_1) {                            
    case 10:
        *param_3 = 0xB;
        break;
    case 11:
        *param_3 = 0xA;
        break;
    }
    *param_2 = _plsu_entrypoint_1(*param_3);
}

void func_800F9354(s32 *param_0, s32 *param_1, s32 *param_2) {
    s32 local_0;
    s32 local_1;

    local_0 = func_800F54E4();
    *param_0 = local_0;
    local_1 = func_800F5410(local_0);
    *param_1 = local_1;
    switch (local_1) {
    case 10:
        *param_2 = 0xB;
        return;
    case 11:
        *param_2 = 0xA;
        return;
    }
}

int func_800F93C4(s32 *param_0, s32 *param_1)
{
  s32 local_0;
  local_0 = func_800F54E4();
  *param_0 = local_0;
  *param_1 = func_800F5410(local_0 | 0);
}

int func_800F9400(s32 param_0)
{
  if (param_0 == 0xA || param_0 == 1)
  {
    func_800C964C(0xC);
  }
  else
  {
    func_800C964C(0xE);
  }
}

int func_800F9444(s32 param_0)
{
  if (param_0 == 0xA || param_0 == 1)
  {
    func_800C964C(0xD);
  }
  else
  {
    func_800C964C(0xF);
  }
}

void func_800F9488(s32 param_0)
{
  s32 sp5C;
  s32 sp58;
  s32 sp54;
  s32 sp50;
  f32 sp44[3];
  f32 sp38[3];
  f32 sp2C[3];
  f32 sp20[3];

  switch (D_80135520)
  {
    case 3:
      if (param_0 == 1)
      {
        func_800F92CC(&sp58, &sp5C, &sp50, &sp54);
        func_800F82D4(sp58, 0);
        func_800F8268(sp58, 1, 1);
      }
      break;

    case 6:
      if (param_0 == 1)
      {
        func_800F9354(&sp58, &sp5C, &sp54);
        func_800F8EBC(sp58);
        func_800F8268(sp58, 1, 1);
        func_800F82D4(sp58, 0);
      }
      break;

    case 9:
      if (param_0 == 1)
      {
        func_800F93C4(&sp58, &sp5C);
        func_800F8EBC(sp58);
        func_800F8268(sp58, 1, 1);
        func_800F82D4(sp58, 0);
      }
      break;

    case 15:
      if (param_0 == 1)
      {
        func_800F93C4(&sp58, &sp5C);
        func_800F8E78(0xA);
      }
      break;
  }

  switch (D_80135520 = param_0)
  {
    case 2:
      func_800F92CC(&sp58, &sp5C, &sp50, &sp54);
      func_800F82D4(sp58, 2);
      func_800F8268(sp58, 0, 1);
      func_800F9444(sp5C);
      return;

    case 3:
      func_800F92CC(&sp58, &sp5C, &sp50, &sp54);
      func_800F8128(sp50);
      func_800F8EE4(sp58);
      func_800F8EBC(sp50);
      func_800F9400(sp54);
      return;

    case 4:
      func_800F9354(&sp58, &sp5C, &sp54);
      func_800F82D4(sp58, 2);
      func_800F9444(sp5C);
      return;

    case 5:
      func_800F9354(&sp58, &sp5C, &sp54);
      func_800F9070(sp54, 1);
      func_800F8268(sp58, 0, 1);
      func_800F8EE4(sp58);
      func_800F9070(sp5C, 0);
      func_800A7990(func_800F8A5C(sp54), 0, 0);
      return;

    case 6:
      func_800F9354(&sp58, &sp5C, &sp54);
      func_800F82D4(sp58, 2);
      func_800F9400(sp5C);
      return;

    case 7:
      func_800F9444(func_800F929C());
      return;

    case 8:
      sp54 = func_800F929C();
      func_800F9070(sp54, 1);
      if (func_800DB9B0() == 0)
      {
        func_800A7990(func_800F8A5C(sp54), 0, 0);
        return;
      }
      break;

    default:
      return;

    case 9:
      func_800F93C4(&sp58, &sp5C);
      func_800F82D4(sp58, 2);
      func_800F9400(sp5C);
      return;

    case 10:
      func_800F93C4(&sp58, &sp5C);
      sp50 = _plsu_entrypoint_1(0x11);
      func_800F8128(sp58);
      func_800F759C(sp50);
      func_800F8268(sp58, 1, 1);
      return;

    case 11:
      sp50 = D_80135522[0];
      sp58 = D_80135521[0];
      func_800F8128(sp50);
      func_800F759C(sp58);
      func_800F8268(sp50, 1, 1);
      return;

    case 13:
      func_800F93C4(&sp58, &sp5C);
      func_800F82D4(sp58, 2);
      func_800F9444(0xB);
      return;

    case 14:
      func_800F9070(0xA, 1);
      func_800A7990(func_800F8A5C(0xA), 0, 0);
      return;

    case 15:
      func_800F93C4(&sp58, &sp5C);
      sp50 = func_800F6224(sp58);
      func_800F7E64(sp50, 0xB);
      func_800F608C(sp50, 1);
      func_800F9240(sp44, sp58);
      func_800F7CF4(sp50, 0x50, sp44);
      func_800F9400(0xA);
      return;

    case 16:
      sp58 = _plsu_entrypoint_1(0xB);
      sp50 = _plsu_entrypoint_1(0xA);
      func_800F5A00(sp58, sp20);
      func_800F5A00(sp50, sp2C);
      if (func_800EEB40(sp20, sp2C) < 4.84e+04f)
      {
        func_800EE7F8(sp38, sp20);
      }
      else
      {
        func_800F9240(sp38, sp50);
      }
      func_800F7CF4(sp58, 0x50, sp38);
      func_800F8128(sp50);
      func_800F8EBC(sp50);
      func_800F8268(sp50, 1, 1);
      return;

    case 17:
      sp58 = _plsu_entrypoint_1(0xB);
      sp50 = _plsu_entrypoint_1(0xA);
      func_800F759C(sp58);
      func_800D5234(0);
      func_800A16BC(0);
      func_800F8128(sp50);
      func_800F8EBC(sp50);
      func_800F7B9C(sp50, 0x60);
      func_800F8268(sp50, 1, 1);
      break;
  }
}

int func_800F99E8()
{
  u8 *local_0 = (u8 *)((s32 *) &D_80135520);
  return *local_0 != 1;
}

int func_800F99FC()
{
  u8 *local_0 = &D_80135520;
  if (*local_0 == 0x0E)
  {
    return 1;
  }
  return 0;
}

int func_800F9A24()
{
  func_800F9488(0);
}

int func_800F9A44()
{
  D_80135520 = 0;
  func_800F9488(1);
}

int func_800F9A6C()
{
  if (_plsu_entrypoint_2())
  {
    func_800F9488(2);
  }
  else
  {
    func_800F9488(4);
  }
}

void func_800F9AAC(long param_0, int param_1)
{
  *((s8 *) (((s8 *) (&D_80135520)) + 1)) = param_0;
  *((s8 *) (((s8 *) (&D_80135520)) + 2)) = param_1;
  func_800F9488(0xB);
}

void func_800F9ADC()
{
    func_800F9488(0xC);
}

void func_800F9AFC()
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  func_800F93C4(&local_1, &local_0);
  local_2 = _plsu_entrypoint_1(func_800F929C());
  func_800F8128(local_2);
  func_800F8EBC(local_2);
  func_800F8268(local_2, 1, 1);
}

int func_800F9B54()
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800F54E4();
  local_1 = _plsu_entrypoint_1(0x11);
  func_800F8128(local_0);
  func_800F8268(local_0, 1, 1);
  func_800F82C0(local_1);
}

void func_800F9BA4()
{
    func_800D9240(0x11);
}

void func_800F9BC4()
{
  if (func_800F8B88() == 3)
  {
    if (!func_800DB9B0())
    {
      switch (D_80135520 - 0xD)
      {
        case 0 :
          break;

        case 1 :
          break;

        case 2 :
          break;

        case 3 :
          break;

        case 4 :
          break;

        case 5 :
          break;

        case 6 :
          break;

        default :
          func_800BEAF4();
          func_800F9488(0x12);

      }

    }
  }
}

int func_800F9C38()
{
  if (func_800F8B88() == 3)
  {
    func_800F9488(0x13);
  }
}

void func_800F9C6C(void)
{
    s32 local_1;
    s32 local_0;
    switch (D_80135520) {
    case 2:
        if (!func_800C9510()) func_800F9488(3);
        break;
    case 3:
        if (func_800C95D4()) func_800F9488(1);
        break;
    case 4:
        if (!func_800C9510()) func_800F9488(5);
        break;
    case 5:
        func_800F9488(6);
        break;
    case 6:
        if (func_800C95D4()) func_800F9488(1);
        break;
    case 7:
        if (!func_800C9510()) func_800F9488(8);
        break;
    case 8:
        func_800F9488(9);
        break;
    case 9:
        if (func_800C95D4()) func_800F9488(1);
        break;
    case 10:
        func_800F9488(1);
        break;
    case 11:
        func_800F9488(1);
        break;
    case 12:
        if (_plsu_entrypoint_1(func_800F929C()) == -1) func_800F9488(7); else func_800F9488(10);
        break;
    case 13:
        if (!func_800C9510()) func_800F9488(14);
        break;
    case 14:
        func_800F9488(15);
        break;
    case 15:
        if (func_800C95D4()) func_800F9488(1);
        break;
    case 16:
        func_800F9488(1);
        break;
    case 17:
        func_800F9488(1);
        break;
    case 18:
        local_0 = func_800F8A5C(10);
        if (local_0 == func_800EA05C()) func_800F9488(16); else func_800F9488(13);
        break;
    case 19:
        local_0 = func_800F8A5C(10);
        if (local_0 == func_800EA05C()) func_800F9488(17);
        break;
    }
}
