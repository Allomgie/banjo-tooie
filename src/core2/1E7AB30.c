#include "core2/1E7AB30.h"

extern u8 unk9[];
extern u8 D_80127090[];
extern u8 unk6[];
extern s32 func_800D5210(void);
extern void func_800D2748();
extern u8 D_80127094;
extern u8 D_80127097;
extern void func_800D284C(u32);
extern u8 D_80127092;
extern u8 D_80127099;
extern void func_800F9EC0(s32, s32);
extern s32 func_800A3274(PlayerState *);
extern u8 func_800D4EB8(s32);
extern void func_800D4E18(s32, s32);
extern void _batimer_set(PlayerState *, s32, f32);
extern u8 unk184[];
extern u8 unk158[];
int func_800A1624();

void func_800A1240(s32 param_0) {
    D_80127090[9] = func_800D5210();
    D_80127090[6] = (u8)param_0;
    func_800D2748(0xcf, D_80127090[9]);
    func_800D2748(0xcd, D_80127090[9]);
}

void func_800A1294(s32 param_0) {
    s32 local_0;
    s32 local_1;

    if ((D_80127094 == 0) && (func_800D3948() == 0) && (func_800DA298(0x6B6) == 0) && (func_800D3E40(9) == 0) && (D_80127097 == 0) && (local_0 = func_8008FD48(), local_1 = func_800D4EB8(local_0), (local_1 != 0))) {
        if (param_0 != 0) {
            func_800D2498(0xCF, func_800D4E7C(local_0), local_1);
            return;
        }
        func_800D24E8(0xCF, func_800D4E7C(local_0), local_1);
    }
}

void func_800A1364()
{
  ((unsigned char *) D_80127090)[1] = 0;
  ((unsigned char *) D_80127090)[0] = 0;
  func_800D517C();
  func_800A1240(func_8009E958());
}

void func_800A13A0(void) {
    (*((u8 *) D_80127090)) = 1;
}

void func_800A13B0(s32 param_0) {
    (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (2))) = _gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(), 0x1000);
    (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (1))) = 0;
    if (func_800F8B64() != 0) {
        (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (1))) = 1;
        (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (3))) = 1;
    }
    if (func_800F99E8() != 0) {
        (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (1))) = 1;
    }
    (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (4))) = 1;
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(param_0), 0x1000) != 0) {
        (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (5))) = 1;
        return;
    }
    (*(s8 *)((s8 *)(((s32 *) D_80127090)) + (5))) = 0;
}

void func_800A1450(void)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u8 local_3;

    local_0 = 0;
    if (D_80127090[3] != 0) {
        func_800D5034(0, func_8008FD48());
        D_80127090[3] = 0;
    }
    if (D_80127090[0] != 0) {
        if (func_80090128() != 0 && D_80127090[2] == 0) {
            D_80127090[1] = 1;
        }
        D_80127090[0] = 0;
    }
    if (D_80127090[4] != 0) {
        func_800A1240(func_8008FD48());
        D_80127090[4] = 0;
    }
    if (D_80127090[1] != 0) {
        if (func_800C95D4() != 0) {
            local_0 = 1;
            D_80127090[1] = 0;
        }
    } else {
        local_1 = func_800D4E7C(func_8008FD48());
        if (local_1 != 0 && local_1 < 3) {
            local_0 = 1;
        }
    }
    if (D_80127090[7] != 0) {
        local_0 = 0;
        func_800A1624(0);
        func_800CE864(1);
        func_800CF7F4(0);
        local_2 = func_800D2820(0xCF) || func_800D2820(0xCD);
        if (D_80127090[8] != 0x11) {
            func_800D284C(0xC9);
            local_2 |= func_800D2820(0xC9);
        }
        if (local_2 == 0) {
            local_3 = D_80127090[7];
            D_80127090[7] = 0;
            if (local_3 == 1) {
                func_800A1240(D_80127090[8]);
                func_800A1294(1);
                D_80127090[8] = 0;
            } else {
                D_80127090[6] = 0;
            }
        }
    }
    if (func_80090128() != 0 && local_0 != 0 && D_80127090[5] == 0) {
        func_800A1294(0);
    }
}

s32 func_800A1618(s32 param_0){
    D_80127092 = param_0;
}

int func_800A1624(param_0) s32 param_0;
{
  if (param_0 != 0)
  {
    func_800A1294(0);
  }
  else
  {
    func_800D284C(0xCF);
  }
}

void func_800A1658(unsigned int param_0)
{
  if ((param_0 != D_80127090[6]) || ((D_80127090[8] != 0) && (param_0 != D_80127090[8])))
  {
    D_80127090[7] = 1;
    D_80127090[8] = param_0;
  }
}

int func_800A1694()
{
  (*((s8 *) &D_80127097)) = 2;
}

u8 func_800A16A4()
{
  return D_80127097;
}

s32 func_800A16B0(void)
{
  return D_80127099;
}

void func_800A16BC(s32 param_0)
{
    if (param_0 != 0) {
        *(u8*)((char*)&D_80127090 + 0x5) += 1;
    } else {
        *(u8*)((char*)&D_80127090 + 0x5) -= 1;
    }
}

int func_800A16F4(int param_0)
{
  unsigned short new_var;
  _batimer_set(param_0, 0xE, 3.0f);
  new_var = 0;
}

s32 func_800A1718(PlayerState *param_0)
{
    if ((*(s32 *)((char *)param_0 + 0x158)) != 0)
    {
        func_800F9F04(*(s32 *)((char *)param_0 + 0x184));
    }
    else
    {
        func_800D4E7C(func_800A3274((s32)param_0));
    }
}

int func_800A1760(Actor *param_0)
{
    s32 *local_0 = (s32 *)((char *)param_0 + 0x158);
    if (*(s32 *)((char *)(param_0) + 0x158))
    {
        func_800F9F18(*(s32 *)((char *)(param_0) + 0x184), param_0);
    }
    else
    {
        func_800D4EB8(func_800A3274(param_0));
    }
}

void func_800A17A8(PlayerState *param_0, s32 param_1)
{
  s32 local_0;
  if ((*(s32 *)((char *)(param_0) + 0x158)) != 0)
  {
    func_800F9EC0((*(s32 *)((char *)(param_0) + 0x184)), param_1);
  }
  else
  {
    local_0 = func_800A3274(param_0);
    if (param_1 < 0 && D_80127092 != 0)
    {
      return;
    }
    if (func_800D4EB8(local_0))
    {
      if (func_800D3E40(9))
      {
        param_1 = func_800D4EB8(local_0);
      }
      func_800D4E18(local_0, param_1);
      func_800A1294(0);
      if (func_800D3E40(4))
      {
        _batimer_set(param_0, 0xE, 3.0f);
      }
    }
  }
}

int func_800A1870(Actor *param_0, s32 param_1)
{
  s32 new_var;
  if (*((s32 *) (((char *) param_0) + 0x158)))
  {
    new_var = *((s32 *) (((char *) param_0) + 0x184));
    func_800F9F2C(new_var);
  }
  else
  {
    func_800D4FB8(func_800A3274(param_0), param_1);
    if (((!param_1) && (!param_1)) && (!param_1))
    {
    }
    func_800A1294(1);
  }
}

int func_800A18C8(Actor *param_0)
{
  func_800F9F74((*(s32 *)((char *)(param_0) + 0x184)));
}

void func_800A18E8(s32 param_0) {
    s32 local_0;
    s32 local_1;

    if (_batimer_decrement(param_0, 0xE) != 0) {
        local_0 = func_800A3274(param_0);
        local_1 = func_800D4E7C(local_0);
        if (local_1 != 0) {
            if (local_1 < func_800D4EB8(local_0)) {
                func_800FC660(8);
                func_800A17A8(param_0, 1);
            }
        }
    }
}
