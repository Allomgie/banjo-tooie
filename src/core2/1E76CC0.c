#include "core2/1E76CC0.h"

#define SOUND(p) (*(LocalSound **)((u8 *)(p) + 0x104))
#define QQ (*(S_9DA40 **)((u8 *)param_0 + 0x104))
s32 func_800C4350();
extern s32 D_80119210[4];
extern void func_800C3394();
extern void func_800C330C(u8, s32);
extern void func_800C3418(u8, s32);
extern void func_800C431C(u8, s32);
typedef struct { u8 pad0; u8 handle; u8 pad2[0x12]; f32 pitch; } LocalSound;
extern s32 func_800C2E04(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern u8 D_80119208[];
f32 func_800DC0C0();
extern s16 D_80119200[1];
extern void func_800C35E8(u8, f32 *);
extern void func_800C301C(u8, s32);
extern void func_800C31DC(u8, f32);
extern void func_800C3058(u8, s32);
extern void func_800C3BDC(u8);
typedef struct { u8 pad0[0xC]; s32 unkC; } S_9DA40;
extern s32 _badata_entrypoint_19(PlayerState *, s32, s32 *, f32 *, s32 *);
extern s32 func_8009C128(PlayerState *param_0, f32 *param_1);
extern void func_800C4208(s32 param_0, f32 param_1, s32 param_2, f32 *param_3, f32 param_4, f32 param_5);
extern f32 func_800DC178(f32, f32);
void func_800C4244(s32 param_0, f32 param_1, s32 param_2, f32 *param_3, f32 param_4, f32 param_5);
extern void func_800C2E40(u8);
extern void func_800C368C(u8, s32);
extern void func_800C33DC(u8, s32);
extern s32 func_800DC128(s32, s32);
void func_8009DAAC();
void func_8009DB04(PlayerState *param_0, s32 param_1, f32 param_2, s32 param_3);
void func_8009DE38(PlayerState *param_0, s32 param_1, f32 param_2);
void func_8009DF18(PlayerState *param_0, s32 param_1, f32 param_2, s32 param_3);

s32 func_8009D3D0() 
{
    return 0x20;
}

int func_8009D3D8(s32 arg0)
{
    func_8009E674(arg0,0x2);
}

void func_8009D3F8(s32 param_0, s32 param_1) {
  u8 *local_0;
  local_0 = func_800F53D0(param_1);
  func_8009DB04(local_0, 0x411, *((f32 *)((*((u8 **)(local_0 + 0x104))) + 0x14)), 0x55f0);
  func_800C2FDC(*((u8 *)((*((u8 **)(local_0 + 0x104))) + 1)));
  *((u8 *)((*((u8 **)(local_0 + 0x104))) + 1)) = 0;
}

s32 func_8009D454(PlayerState *param_0, s32 param_1, s32 *param_2) {
    u16 local_0[5];
    s32 a0;
    func_8009C128(param_0, local_0);
    a0 = (u8)((u8 *)&param_1)[3];
    if (a0 == 0) {
        a0 = func_800C4350(a0, local_0, D_80119210) & 0xFF;
    }
    return func_800C4350(a0, local_0, param_2);
}

int func_8009D4A8(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  func_800C4AF0(local_0, param_1);
}

void func_8009D4D8(u8 *param_0) {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0x18))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0x1C))) = 1;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (8))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0xC))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0x10))) = 0;
    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0))) = func_800C2E04();
    func_800C330C((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0))), 3);
    func_800C3418((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0))), 0);
    func_800C431C((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0))), 0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (0x14))) = 1.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (1))) = 0;
    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (2))) = func_800C2E04();
    func_800C3418((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (2))), 0);
    func_800C431C((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (2))), 0);
    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (3))) = func_800C2E04();
    func_800C3418((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (3))), 0);
    func_800C431C((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (3))), 0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x104)))) + (4))) = 0;
}

void func_8009D5E0(u8 *param_0)
{
  u8 *local_0;
  u8 local_1;
  u8 local_2;
  local_0 = *((u8 **) (((s8 *) param_0) + 0x104));
  local_2 = *((u8 *) (((s8 *) local_0) + 1));
  if (local_2 != 0)
  {
    if (((!local_0) && (!local_0)) && (!local_0))
    {
    }
    func_800C2FDC(local_2 & 0xFF, local_2);
    local_0 = *((u8 **) (((s8 *) param_0) + 0x104));
  }
  func_800C2FDC(*local_0);
  func_800C2FDC(*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x104)))) + 3)));
  func_800C2FDC(*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x104)))) + 2)));
  local_1 = *((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x104)))) + 4));
  if (local_1 != 0)
  {
    func_800C2FDC(local_1);
  }
}

void func_8009D658(PlayerState *param_0)
{
    f32 local_0[3];
    if (SOUND(param_0)->handle == 0) {
        SOUND(param_0)->handle = func_800C2E04();
        func_800C301C(SOUND(param_0)->handle, 0x410);
        func_800C3394(SOUND(param_0)->handle, func_8009D3F8, param_0->unk184);
        func_800C3058(SOUND(param_0)->handle, 0x6D60);
        func_800C330C(SOUND(param_0)->handle, 2);
        func_800C3418(SOUND(param_0)->handle, 0);
        func_800C431C(SOUND(param_0)->handle, 0);
    }
    func_8009C128(param_0, local_0);
    SOUND(param_0)->pitch += func_800DC0C0() * 0.1f - 0.05f;
    SOUND(param_0)->pitch = func_800F0E00(SOUND(param_0)->pitch, 0.9f);
    SOUND(param_0)->pitch = func_800F13F0(SOUND(param_0)->pitch, 1.5f);
    func_800C35E8(SOUND(param_0)->handle, local_0);
    func_800C31DC(SOUND(param_0)->handle, SOUND(param_0)->pitch);
    func_800C3BDC(SOUND(param_0)->handle);
}

void func_8009D7A4(u8 *param_0, f32 param_1, f32 param_2) {
    u8 *ptr;
    f32 result;

    result = func_800DC178(param_1, param_2);
    func_8009DF18(param_0, *(s16 *)(D_80119208 + (*(s32 *)((char *)*(u8 **)((char *)param_0 + 0x104) + 0x18) * 2)), result, 0x61A8);

    ptr = *(u8 **)((char *)param_0 + 0x104);
    *(s32 *)((char *)ptr + 0x18) = *(s32 *)((char *)ptr + 0x18) + 1;

    ptr = *(u8 **)((char *)param_0 + 0x104);
    if (*(s32 *)((char *)ptr + 0x18) >= 3) {
        *(s32 *)((char *)ptr + 0x18) = 0;
    }
}

void func_8009D820(PlayerState *param_0, f32 param_1)
{
    f32 f = func_800DC0C0(param_0);
    s32 a = f < 0.5f ? 0x585 : 0x586;
    func_8009DE38(param_0, a, param_1);
}

void func_8009D874(PlayerState *param_0)
{
  func_8009DE38(param_0, 0x442E, 1.1169999837875366f);
}

void func_8009D89C(u8 *param_0, f32 param_1)
{
  s32 local_0[3];
  func_8009C128(param_0, &local_0[0]);
  func_800C35E8(*(*(u8 **)((s8 *)param_0 + 0x104)), &local_0);
  func_800C301C(*(*(u8 **)((s8 *)param_0 + 0x104)), D_80119200[*(u32 *)(*(u8 **)((s8 *)param_0 + 0x104) + 8)]);
  func_800C31DC(*(*(u8 **)((s8 *)param_0 + 0x104)), param_1);
  func_800C3BDC(*(*(u8 **)((s8 *)param_0 + 0x104)));
  *(u32 *)(*(u8 **)((s8 *)param_0 + 0x104) + 8) = *(u32 *)(*(u8 **)((s8 *)param_0 + 0x104) + 8) + 1;
  if (*(u32 *)(*(u8 **)((s8 *)param_0 + 0x104) + 8) >= 4)
    *(u32 *)(*(u8 **)((s8 *)param_0 + 0x104) + 8) = 0;
}

void func_8009D940(s32 param_0, s32 param_1, f32 param_2, s32 param_3)
{
  f32 sp24[3];
  func_8009DAAC(&param_1, &param_2);
  func_8009C128(param_0, sp24);
  func_800C35E8(*(u8 *)(*(u32 *)(param_0 + 0x104)), sp24);
  func_800C301C(*(u8 *)(*(u32 *)(param_0 + 0x104)), param_1);
  func_800C31DC(*(u8 *)(*(u32 *)(param_0 + 0x104)), param_2);
  func_800C3058(*(u8 *)(*(u32 *)(param_0 + 0x104)), param_3);
  func_800C3BDC(*(u8 *)(*(u32 *)(param_0 + 0x104)));
}

void func_8009D9D4(PlayerState *param_0) {
    f32 c;
    s32 b;
    s32 a;
    if (_badata_entrypoint_17(param_0, *(s32 *)(*(u8 **)((u8 *)param_0 + 0x104) + 0xC), &b, &c, &a) == 0) {
        *(s32 *)(*(u8 **)((u8 *)param_0 + 0x104) + 0xC) = 0;
    } else {
        *(s32 *)(*(u8 **)((u8 *)param_0 + 0x104) + 0xC) += 1;
    }
    func_8009D940(param_0, b, c, a);
}

void func_8009DA40(PlayerState *param_0) {
    f32 v2C;
    s32 v28;
    s32 v24;
    if (_badata_entrypoint_19(param_0, QQ->unkC, &v28, &v2C, &v24) == 0) {
        QQ->unkC = 0;
    } else {
        QQ->unkC = QQ->unkC + 1;
    }
    func_8009D940(param_0, v28, v2C, v24);
}

void func_8009DAAC(param_0, param_1) s32 * param_0; f32 * param_1;
{
  s32 *new_var2;
  s32 local_0;
  int new_var;
  new_var2 = param_0;
  local_0 = *new_var2;
  new_var = local_0 & (~0xFFF);
  *new_var2 = 0xFFF;
  *new_var2 = local_0 & (*new_var2);
  if (!new_var)
  {
  }
  if ((new_var == 0x4000) && (func_8009EA2C() != 0))
  {
    *param_1 -= 0.2f;
  }
}

void func_8009DB04(PlayerState *param_0, s32 param_1, f32 param_2, s32 param_3)
{
  f32 local_2[3];
  func_8009DAAC(&param_1, &param_2);
  func_8009C128(param_0, local_2);
  if (func_8009D3D8(param_0))
  {
    func_800C4208(param_1, param_2, param_3, local_2, 250.0f, 5.4e+03f);
  }
  else
  {
    func_800C4244(param_1, param_2, param_3, local_2, 250.0f, 5.4e+03f);
  }
}

void func_8009DBB0(void *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4) {
    func_8009DB04(param_0, param_1, func_800DC178(param_2, param_3), param_4);
}

void func_8009DBF0(PlayerState *param_0, s32 param_1, f32 param_2) {
    f32 local_0;
    f32 local_1;
    s32 sp24;

    func_8009DAAC(&param_1, &param_2);
    func_8009C128(param_0, &sp24);
    if (func_8009D3D8(param_0) != 0) {
        func_800C4208(param_1, param_2, 0x55F0, &sp24, 250.0f, 5.4e+03f);
    } else {
        func_800C4244(param_1, param_2, 0x55F0, &sp24, 250.0f, 5.4e+03f);
    }
}

void func_8009DC98(s32 param_0, s32 param_1, f32 param_2, f32 param_3)
{
  func_8009DBB0(param_0, param_1, param_2, param_3, 0x55F0);
}

void func_8009DCCC(void *param_0, u8 param_1, s32 param_2, f32 param_3, s32 param_4) {
    f32 local_0[3];
    func_8009DAAC(&param_2, &param_3);
    func_8009C128(param_0, local_0);
    func_800C2E40(param_1);
    func_800C431C(param_1, 0);
    if (func_8009D3D8(param_0)) func_800C3418(param_1, 1);
    else func_800C3418(param_1, 0);
    if ((*(u8 **)((u8 *)param_0 + 0x104))[0x1C]) func_800C35E8(param_1, local_0);
    else func_800C368C(param_1, 0);
    func_800C33DC(param_1, 0);
    func_800C330C(param_1, 3);
    func_800C301C(param_1, param_2);
    func_800C31DC(param_1, param_3);
    func_800C3058(param_1, param_4);
    func_800C3BDC(param_1);
}

s32 func_8009DDD0(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x104)))[2];
}

void func_8009DDDC(PlayerState *param_0)
{
  s32 local_0[3];
  func_8009C128(param_0, &local_0);
  func_800C35E8(*((*((u8 **) (((char *) param_0) + 0x104))) + 3), &local_0);
}

void func_8009DE14(void *param_0) {
    func_800C3D78(*((u8 *)(*(u32 **)((u8 *)param_0 + 0x104)) + 2));
}

void func_8009DE38(PlayerState *param_0, s32 param_1, f32 param_2) {
    func_8009DCCC(param_0, (*(u8 *)((char *)*(void **)((char *)param_0 + 0x104) + 2)), param_1, param_2, 0x55F0);
}

void func_8009DE74(PlayerState *param_0, s32 param_1, f32 param_2, f32 param_3) {
    func_8009DCCC(param_0, (*(u8 **)((u8 *)param_0 + 0x104))[2], param_1,
                  func_800DC178(param_2, param_3), 0x55F0);
}

void func_8009DEC0(PlayerState *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5) {
    s32 u;
    f32 t;
    t = func_800DC178(param_2, param_3);
    u = func_800DC128(param_4, param_5);
    func_8009DCCC(param_0, (*(u8 **)((u8 *)param_0 + 0x104))[2], param_1, t, u);
}

void func_8009DF18(PlayerState *param_0, s32 param_1, f32 param_2, s32 param_3) {
    func_8009DCCC(param_0, (*(u8 **)((u8 *)param_0 + 0x104))[2], param_1, param_2, param_3);
}

void func_8009DF58(PlayerState *param_0, s32 param_1, f32 param_2) {
    u8 local_0 = ((u8 *)*((s32 *)((char *)param_0 + 0x104)))[3];
    func_8009DCCC(param_0, local_0, param_1, param_2, 0x55f0);
}

void func_8009DF94(PlayerState *param_0, s32 param_1, f32 param_2, s32 param_3) {
    func_8009DCCC(param_0, (*(u8 **)((u8 *)param_0 + 0x104))[3], param_1, param_2, param_3);
}

void func_8009DFD4(PlayerState *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5) {
    s32 u;
    f32 t;
    t = func_800DC178(param_2, param_3);
    u = func_800DC128(param_4, param_5);
    func_8009DCCC(param_0, (*(u8 **)((u8 *)param_0 + 0x104))[3], param_1, t, u);
}

int func_8009E02C(int param_0)
{
  int new_var2;
  f32 new_var;
  new_var2 = 0x417;
  new_var = 0.8f;
  func_8009DF18(param_0, new_var2, new_var, 0x7FFF);
}

void func_8009E058(PlayerState *param_0)
{
  func_8009DF18(param_0, 0x417, 0.800000011920929f, 0x4650);
}

int func_8009E084(int param_0)
{
  unsigned char new_var;
  func_8009DF18(param_0, 0x417, 1.0f, 14000);
  new_var = 0;
}

void func_8009E0AC(u8 *param_0, unsigned long param_1)
{
  *((s8 *) (((s8 *) (*((u8 **) (0x104 + ((s8 *) param_0))))) + 0x1C)) = param_1;
}

void func_8009E0B8(void *param_0) {
    func_800C3CE8(*(*(u8 **)((s8 *)param_0 + 0x104)));
}

void func_8009E0DC(PlayerState *param_0) {
    func_800C3CE8((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + 0x104))) + 2)));
}

void func_8009E100(PlayerState *param_0) {
    func_800C3CE8(*(*(u8 **)((u8 *)param_0 + 0x104) + 3));
}
