#include "su/quiz.h"

extern f32 D_80801050_suquiz[][3][2];
extern f32 D_80801054_suquiz[][3][2];
extern s8 *D_80127614;
extern s32 func_800DC298(f32);
typedef struct { s32 local_0[4]; } Broad50QuizList;
extern Broad50QuizList D_808010E0_suquiz;
extern f32 func_800D9004(void);
extern void func_800DA524();
extern f32 D_80800F94_suquiz[][6][2];
extern f32 D_80800F74_suquiz[][2];
extern f32 D_80800F70_suquiz[];
extern int D_808010F0_suquiz[];
typedef struct { u8 pad0[0x18]; f32 f18; f32 f1C; u8 pad20[5]; u8 b25; s8 b26; s8 b27; s8 b28; s8 b29; } QuizState;
typedef struct { f32 a; f32 b; } QPair;
typedef struct { QPair p[6]; } QRow;
extern QRow D_80800F90_suquiz[];
extern s32 func_800D3948();
extern f32 func_800DC0C0();
extern f32 func_800DC178(f32, f32);
typedef struct { s32 local_0; f32 local_1; s32 local_2; } QuizPackedColor27;
extern QuizPackedColor27 D_808010FC_suquiz[][4];
int suquiz_entrypoint_10();
int suquiz_entrypoint_11();
void suquiz_entrypoint_21();
void suquiz_entrypoint_28();

s32 func_80800000_suquiz(u32 param_0)
{
    u8 local_0;

    switch (param_0) {
    case 0:
    case 1:
        if (suquiz_entrypoint_4() == 0) {
            local_0 = (D_80127614 + param_0)[0x31];
        } else {
            local_0 = 2;
        }
        return local_0;
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    default:
        return 0;
    }
}

f32 func_80800074_suquiz(s32 param_0, s32 param_1, s32 param_2) {
    return D_80801050_suquiz[param_1][param_2][0];
}

f32 func_8080009C_suquiz(s32 param_0, s32 param_1, s32 param_2) {
    return D_80801054_suquiz[param_1][param_2][0];
}

int func_808000C4_suquiz(s32 param_0)
{
  s8 _sfpad[16];
  s32 arr[2];
  func_80015E80(param_0, &arr[0]);
  return arr[1] == 1;
}

void suquiz_entrypoint_0(void)
{
    func_800DA544(0x6B6);
    if (!D_80127614) D_80127614 = (u8 *)heap_alloc(0x38);
    rare_memset(D_80127614, 0, 0x38);
    if (func_800D3948()) {
        suquiz_entrypoint_21(3, 0);
        suquiz_entrypoint_21(4, 1);
        suquiz_entrypoint_21(5, _gcstatusDll_entrypoint_11() < 3 ? -1 : 2);
        suquiz_entrypoint_21(6, _gcstatusDll_entrypoint_11() < 4 ? -1 : 3);
    } else {
        suquiz_entrypoint_21(0, -1);
        suquiz_entrypoint_21(1, -1);
        suquiz_entrypoint_21(2, 0);
        if (func_800DC298(0.5f)) D_80127614[0x31] = 0;
        else D_80127614[0x31] = 1;
        if (!(u8)D_80127614[0x31]) D_80127614[0x32] = 1;
        else D_80127614[0x32] = 0;
    }
}

void suquiz_entrypoint_1(void)
{
    f32 local_0;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    Broad50QuizList local_1;
    s32 local_6;
    if (1) {}

    local_0 = func_800D9004();
    local_1 = D_808010E0_suquiz;
    local_2 = 0;
    if (D_80127614) {
        local_6 = (u8)D_80127614[0x24];
        if (func_800D3948()) local_6 = local_6 && (f32)_gcstatusDll_entrypoint_17() > 0.0f;
        if (local_6) {
            *(f32 *)(D_80127614 + 0x20) -= local_0;
            if (*(f32 *)(D_80127614 + 0x20) <= 0.0f) {
                func_800C3F48(0x7FFFFE90);
                D_80127614[0x24] = 0;
            }
            func_800D2498(0x117, (s32)*(f32 *)(D_80127614 + 0x20), 0);
        }
        *(f32 *)(D_80127614 + 0x1C) += local_0;
        if (D_80127614[0x28] == -1) {
            if (func_800D3948()) { local_3 = 3; local_4 = 6; }
            else { local_3 = 0; local_4 = 2; }
            for (local_5 = local_3; local_5 <= local_4; local_5++) {
                if (local_5 != D_80127614[0x29] && suquiz_entrypoint_11(local_5) && func_808000C4_suquiz(suquiz_entrypoint_10(local_5))) {
                    local_1.local_0[local_2++] = local_5;
                }
            }
            if (local_2) D_80127614[0x28] = local_1.local_0[func_800DC128(0, local_2)];
            if (D_80127614[0x28] == -1 && *(f32 *)(D_80127614 + 0x18) <= *(f32 *)(D_80127614 + 0x1C)) {
                D_80127614[0x28] = D_80127614[0x26];
            }
            if (func_800DB9B0() && D_80127614[0x28] != -1) suquiz_entrypoint_28(0, D_80127614[0x28], 0);
        }
    }
}

s32 suquiz_entrypoint_2(void) {
    if (((s32) D_80127614)) {
        func_800DA524(0x6B6);
        heap_free(((s32) D_80127614));
        D_80127614 = FALSE;
    }
}

int suquiz_entrypoint_3()
{
  if (func_800DA298(0x441))
  {
    return 4;
  }
  if (func_800DA298(0x6E3))
  {
    func_800DA524(0x6E3);
    func_800DA524(0x6EB);
    return 5;
  }
  switch (func_800DA564(0x442, 3))
  {
    case 0 :
      return 0;

    case 1 :
      return 1;

    case 2 :
      return 2;

    case 3 :
      return 3;

    case 4 :
      return 6;

  }

  return 0;
}

int suquiz_entrypoint_4()
{
  switch (func_800DA564(0x442, 3))
  {
    case 2 :
      return 1;

    case 3 :
      return 2;

    case 4 :
      return 3;

    default :
      return 0;

  }

}

int suquiz_entrypoint_5()
{

  if (func_800DA298(0x6B6))
  {
    int *ptr = &((int *) &D_80127614)[0];
    return (*(s8 *)(*ptr + 0x28)) + 1 != 0;
  }
  else
  {
    return 0;
  }
}

s8 suquiz_entrypoint_6(void) {
    if (func_800DA298(0x6B6) != 0) {
        return *(s8 *)((char *)((u8 *) D_80127614) + 0x28);
    }
    return -1;
}

u8 suquiz_entrypoint_7(void)
{
  if (func_800DA298(0x6B6) != 0)
  {
    return ((u8 *) D_80127614)[0x25];
  }
  return 6U;
}

f32 suquiz_entrypoint_8(s32 param_0) {
    return D_80800F94_suquiz[suquiz_entrypoint_4()][param_0][0];
}

s32 suquiz_entrypoint_9(s32 param_0) {
    switch (param_0) {
    case 1:
        return func_800DA298(0x582);
    case 0:
        return func_800DA298(0x583);
    }
    return 0;
}

int suquiz_entrypoint_10(param_0) s32 param_0;
{
    if (func_800DA298(0x6B6)) return *(D_80127614 + param_0 + 0x2A);
    return 0;
}

int suquiz_entrypoint_11(param_0) s32 param_0;
{
  if (func_800DA298(0x6B6))
  {
    return (suquiz_entrypoint_10(param_0) + 1) != 0;
  }
  return 0;
}

void suquiz_entrypoint_12(void) {
    func_800DC298(D_80800F74_suquiz[suquiz_entrypoint_4()][0]);
}

int suquiz_entrypoint_13(int param_0)
{
    func_800EE7F8(param_0, ((int) D_80127614));
}

void suquiz_entrypoint_14(s32 param_0) {
    func_800EE7F8(param_0, ((s32) D_80127614) + 0xC);
}

s8 suquiz_entrypoint_15(s32 param_0) {
    if (func_800DA298(0x6B6) != 0) {
        return ((u8 *) D_80127614)[0x27];
    }
    return 0;
}

s32 suquiz_entrypoint_16(void) {
    if (func_800DA298(0x6B6)) {
        return *(f32 *)(((u8 *) D_80127614) + 0x20) <= 0.0f;
    }
    return 1;
}

s32 suquiz_entrypoint_17()
{
    return func_800DA298(FLAG2_6E3_UNK);
}

void suquiz_entrypoint_18(u32 param_0)
{
  switch (param_0)
  {
    case 0:
      func_800DA524(0x441);
      func_800DA7A8(0x442, 0, 3);
      return;
    case 1:
      func_800DA524(0x441);
      func_800DA7A8(0x442, 1, 3);
      _gcfrontend_entrypoint_9(0x74);
      return;
    case 2:
      func_800DA524(0x441);
      func_800DA7A8(0x442, 2, 3);
      _gcfrontend_entrypoint_9(0x75);
      return;
    case 3:
      func_800DA524(0x441);
      func_800DA7A8(0x442, 3, 3);
      _gcfrontend_entrypoint_9(0x76);
      return;
    case 4:
      func_800DA544(0x441);
      func_800DA7A8(0x442, 4, 3);
      _gcfrontend_entrypoint_9(0x84);
    default:
      return;
  }
}

void suquiz_entrypoint_19(s32 param_0)
{
    s32 i;
    s32 end;
    s32 start;
    s32 r;
    s32 temp;
    s32 unused1; /* honest note: unused locals in the original too (frame/slot layout: sp38 at 0x38, frame 0x58) */
    s32 unused2;
    f32 sp38;
    f32 v;
    f32 f20;

    switch (param_0) {
    case 0:
    case 2:
        ((QuizState *) D_80127614)->b26 = -1;
        ((QuizState *) D_80127614)->b28 = -1;
        ((QuizState *) D_80127614)->b29 = -1;
        break;
    case 1:
        ((QuizState *) D_80127614)->b26 = -1;
        break;
    case 4:
        ((QuizState *) D_80127614)->b29 = ((QuizState *) D_80127614)->b28;
        ((QuizState *) D_80127614)->b26 = -1;
        ((QuizState *) D_80127614)->b28 = -1;
        break;
    case 3:
    case 5:
        break;
    }
    switch (param_0) {
    case 0:
    case 1:
    case 2:
    case 4:
        r = func_800D3948();
        end = 2;
        if (r != 0) {
            start = 3;
            end = 6;
        } else {
            start = 0;
        }
        for (i = start; i <= end; i++) {
            if (i != ((QuizState *) D_80127614)->b29 && suquiz_entrypoint_9(i) == 0 && suquiz_entrypoint_11(i) == 0) {
                temp = func_80800000_suquiz(i);
                f20 = func_80800074_suquiz(i, param_0, temp);
                if (func_800DC0C0() <= f20) {
                    end = suquiz_entrypoint_4();
                    f20 = func_800DC178(D_80800F90_suquiz[end].p[param_0].a, D_80800F90_suquiz[suquiz_entrypoint_4()].p[param_0].b - 0.4f);
                    sp38 = func_8080009C_suquiz(i, param_0, temp);
                    v = func_800DC0C0();
                    ((QuizState *) D_80127614)->b26 = i;
                    ((QuizState *) D_80127614)->f18 = f20;
                    ((QuizState *) D_80127614)->b27 = v <= sp38;
                    break;
                }
            }
        }
    
        break;
    }
    ((QuizState *) D_80127614)->f1C = 0.0f;
    ((QuizState *) D_80127614)->b25 = param_0;
}

void suquiz_entrypoint_20(s32 param_0)
{
    if (param_0 != 0)
    {
        if (param_0 == 1)
        {
            func_800DA544(0x582);
        }
    }
    else
    {
        func_800DA544(0x583);
    }
}

void suquiz_entrypoint_21(param_0, param_1) s32 param_0; unsigned long param_1;
{
  *((s8 *) (((s8 *) (D_80127614 + param_0)) + 0x2A)) = param_1;
}

int suquiz_entrypoint_22(s32 param_0, s32 param_1)
{
  func_800EE7F8(((int) D_80127614), param_0);
  func_800EE7F8(((int) D_80127614) + 0xC, param_1);
}

void suquiz_entrypoint_23(void) {
    if (func_800D3948() != 0) {
        *(f32 *)((char *)((u8 *) D_80127614) + 0x20) = (f32) ((f32) _gcstatusDll_entrypoint_17() * 60.0f);
    } else {
        *(f32 *)((char *)((u8 *) D_80127614) + 0x20) = *(f32 *)((char *)D_80800F70_suquiz + suquiz_entrypoint_4() * 8);
    }
    *(s8 *)((char *)((u8 *) D_80127614) + 0x24) = 1;
}

void suquiz_entrypoint_24(s32 param_0, unsigned int param_1)
{
  s32 new_var;
  *((s16 *) (((s8 *) ((s16 *) D_80127614)) + 0x34)) = param_1;
  func_800DA544(0x6E3);
  func_800DA524(0x6EB);
  new_var = param_0;
  _glcutDll_entrypoint_6(new_var, 0x8A);
}

int suquiz_entrypoint_25()
{
  if (!func_800DA298(0x6EB))
  {
    _glcutDll_entrypoint_17();
    func_800DA544(0x6EB);
  }
}

int suquiz_entrypoint_26()
{
    return *(short *)(((u32) D_80127614) + 0x34);
}

int suquiz_entrypoint_27()
{
  func_80108474(0x217, &D_808010F0_suquiz, 0);
}

void suquiz_entrypoint_28(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    func_800C3F48(((D_808010FC_suquiz[param_1][param_0].local_0 & 0x7FF) + (((D_808010FC_suquiz[param_1][param_0].local_2 >> 5) & 0x3FF) << 11)) + (u32)((u16)(u32)(D_808010FC_suquiz[param_1][param_0].local_1 * 1023.0f) << 21));
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/quiz.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80800F94_suquiz = D_80800F90_suquiz + 0x4, D_80801054_suquiz = D_80801050_suquiz + 0x4
 * extern declarations adjusted to the object (same addresses): D_808010F0_suquiz -> int[] */
f32 D_80800F70_suquiz[1] = { 1.8e+02f };
f32 D_80800F74_suquiz[3][2] = { 0.33f, 1.8e+02f, 0.33f, 1.8e+02f, 0.0f, 0.0f };
static u32 D_80800F74_suquiz_rest[1] = { 0x3EA8F5C3 };
QRow D_80800F90_suquiz[4] = { 3.0f, 5.0f, 2.0f, 3.0f, 2.0f, 6.0f, -1.0f, 6.0f, 2.0f, 6.0f, -1.0f, 6.0f, 3.0f, 5.0f, 2.0f, 3.0f, 2.0f, 6.0f, -1.0f, 6.0f, 1.5f, 6.0f, -1.0f, 6.0f, 2.0f, 5.0f, 2.0f, 3.0f, 2.0f, 6.0f, -1.0f, 6.0f, 1.0f, 6.0f, -1.0f, 6.0f, 2.0f, 5.0f, 2.0f, 3.0f, 2.0f, 6.0f, -1.0f, 6.0f, 1.0f, 6.0f, -1.0f, 6.0f };
f32 D_80801050_suquiz[6][3][2] = { 0.1f, 0.9f, 0.2f, 0.9f, 0.25f, 0.9f, 0.4f, 0.8f, 0.6f, 0.8f, 0.7f, 0.8f, 0.4f, 0.8f, 0.6f, 0.8f, 0.7f, 0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.9f, 0.7f, 0.9f, 0.8f, 0.9f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
Broad50QuizList D_808010E0_suquiz = { -0x1, -0x1, -0x1, -0x1 };
int D_808010F0_suquiz[3] = { 0x0, 0x0, 0x0 };
QuizPackedColor27 D_808010FC_suquiz[7][4] = { 0x620, 1.0f, 0x7D00, 0x650, 1.0f, 0x7D00, 0x652, 1.0f, 0x7D00, 0x681, 1.0f, 0x7D00, 0x621, 1.0f, 0x7D00, 0x64E, 1.0f, 0x7D00, 0x64F, 1.0f, 0x7D00, 0x680, 1.0f, 0x7D00, 0x622, 1.0f, 0x7D00, 0x3EA, 1.0f, 0x7D00, 0x3EB, 1.0f, 0x7D00, 0x427, 1.0f, 0x7D00, 0x620, 1.0f, 0x7D00, 0x5A2, 1.0f, 0x7D00, 0x5A4, 1.0f, 0x7D00, 0x50F, 1.0f, 0x7D00, 0x621, 1.0f, 0x7D00, 0x68F, 1.0f, 0x7D00, 0x68C, 1.0f, 0x7D00, 0x683, 1.0f, 0x7D00, 0x659, 1.0f, 0x7D00, 0x3EA, 1.0f, 0x7D00, 0x3EB, 1.0f, 0x7D00, 0x427, 1.0f, 0x7D00, 0x622, 1.0f, 0x7D00, 0x654, 1.0f, 0x7D00, 0x655, 1.0f, 0x7D00, 0x67F, 1.0f, 0x7D00 };
static u32 D_808010FC_suquiz_rest[1] = { 0x0 };
