#include "core2/1E6EC70.h"

extern s32 D_80117E60;
typedef struct { u8 pad0[0xC]; u8 unkC; } P_95588;
typedef struct { u8 pad0[0x7C]; P_95588 *unk7C; } S_95588;
extern void func_8009C128(PlayerState *param_0, s32 param_1);
void func_800956B8();

s32 func_80095380(void)
{
	return 0x18;
}

u8 func_80095388(u32 *param_0, s32 param_1, u8 *param_2, s32 param_3)
{
    s32 v0 = param_3 + 0x3E8;
    s16 *local_1 = (s16 *)(param_2 + 12);
    s32 sum;
    s16 val;

    if (local_1[0] >= 0) {
        do {
            val = local_1[0];
            sum = val + v0;
            if (sum < param_1) {
                *param_0 = (u8)((u8 *)local_1)[2];
                return ((u8 *)local_1)[3];
            }
            local_1 += 2;
            val = local_1[0];
        } while (val >= 0);
    }
    return 0;
}

s32 func_800953E0(s32 param_0, s32 *param_1, s32 param_2) {
    s32 temp_v0;

    *param_1 = 0;
    if (param_2 < 0) {
        return 0;
    }
    temp_v0 = func_800A3274(param_0);
    switch (temp_v0) {
    case 10:
        if (func_8009E71C(param_0, 0x13) != 0) {
            return func_80095388(param_1, param_2, &D_80117E60, 0x3E8);
        }
    default: ;
    case 2:
    case 3: ;
    case 4:
    case 5: ;
    case 6:
    case 7: ;
    case 8:
    case 9: ;
    case 11:
    case 12: ;
    case 13:
    case 14: ;
    case 15:
    case 16: ;
    case 17:
    case 18: ;
    case 19:
        return func_80095388(param_1, param_2, &D_80117E60, 0);
    }
}

void func_80095490(Actor *param_0)
{
  char *new_var;
  f32 sp20;
  f32 sp1C;
  func_8009C128(param_0, &sp1C);
  if (1 != 0)
  {
    u8 *temp_v0 = *((u8 **) (((char *) param_0) + 0x7C));
    new_var = (char *) temp_v0;
    *((s32 *) (((char *) (*((u8 **) (((char *) param_0) + 0x7C)))) + 0x14)) = func_800953E0(param_0, temp_v0 + 0x10, (s32) ((*((f32 *) (new_var + 0x4))) - sp20));
  }
}

s32 func_800954E8(u8 *param_0, s32 *param_1) {
    if (func_800D3E40(0x3) != 0) {
        *param_1 = 0;
    } else {
        *param_1 = *(*( (s32 **)(param_0 + 0x7C) ) + 4);
    }
    return *(*( (s32 **)(param_0 + 0x7C) ) + 5);
}

f32 func_80095534(void *param_0)
{
  s32 local_24;
  struct { s32 a; f32 b; } local_1C;
  func_8009C128(param_0, &local_1C);
  local_24 = (s32)(*(f32 *)(*(s32 *)((char *)param_0 + 0x7C) + 4) - local_1C.b);
  return (f32)local_24;
}

s32 func_8009557C(PlayerState *param_0)
{
  char *new_var4;
  char *new_var;
  char *new_var5;
  PlayerState *new_var3;
  s32 *local_0;
  s32 **new_var2;
  new_var5 = (char *) (new_var3 = param_0);
  new_var4 = new_var5;
  new_var = new_var4;
  local_0 = *(new_var2 = (s32 **) (new_var + 0x7C));
  new_var4 = *(new_var2 = (s32 **) (new_var + 0x7C));
  local_0 = new_var4;
  return new_var4[0xC];
}

void func_80095588(S_95588 *param_0, s32 param_1) {
    param_0->unk7C->unkC = param_1;
    if ((param_0->unk7C->unkC == 2) || (param_0->unk7C->unkC == 3)) {
        func_800956B8(param_0);
    }
}

void func_800955CC(Actor *param_0) {
    func_8009C128(param_0, *(u32 **)((u8 *)param_0 + 0x7c));
    *(*(u8 **)((u8 *)param_0 + 0x7c) + 0xc) = 0;
    func_80095588(param_0, 1);
    *(*(u32 **)((u8 *)param_0 + 0x7c) + 4) = 0;
    *(*(u32 **)((u8 *)param_0 + 0x7c) + 5) = *(*(u32 **)((u8 *)param_0 + 0x7c) + 4);
}

void func_8009561C(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_0 = func_800F3ED0();
  local_1 = player_isStable(param_0);
  local_2 = bs_getCurrentState(param_0);
  if ((local_1 != 0) || (func_800F40EC(param_0) != 0) || (local_2 == 0xBE) || (local_2 == 0x15C) || (local_0 == 0xA))
  {
    func_800956B8(param_0);
    func_80095588(param_0, 1);
  }
  func_80095490(param_0);
  return;
}

void func_800956B8(param_0) PlayerState * param_0;
{
  func_8009C128(param_0, *(s32 *)((char *)param_0 + 0x7c));
}
