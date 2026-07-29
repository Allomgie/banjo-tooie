#include "common.h"

extern u16 D_8003F778[];
typedef struct { u8 local_0[30][0x38]; s32 local_1; s32 local_2; s32 local_3; s32 local_4; } Struct8001D800;
extern Struct8001D800 D_8007D170;
extern s32 D_8007D800;
extern s32 D_8007D804;
extern s32 D_8007D810;
extern s32 D_8007D80C;

u16 func_8001D450(unsigned short param_0)
{
  unsigned short r = ((param_0 & 0xF800) / 2) & 0xF800;
  unsigned short g = ((param_0 & 0x07C0) / 2) & 0x07C0;
  unsigned short b = ((param_0 & 0x003E) / 2) & 0x003E;
  
  return r | g | b | 1;
}

u8 func_8001D4C4(u8 param_0, u8 param_1, f32 param_2) {
    f32 local_0;
    f32 local_1;

    local_0 = (f32)(u32)param_0;
    local_1 = (f32)(u32)param_1;
    return (u8)(((local_1 - local_0) * param_2) + local_0);
}

void func_8001D5C4(u16 *param_0, u8 *param_1)
{
  u16 local_1 = ((*param_0) >> 8) & 0xF8;
  u16 local_2 = ((*param_0) >> 3) & 0xF8;
  u16 local_3 = ((*param_0) << 2) & 0xF8;
  f32 local_4;

  if (param_1[3] != 0)
  {
    local_4 = ((f32) ((u32) param_1[3])) * (1.0f / 256.0f);
    local_1 = func_8001D4C4(local_1, param_1[0], local_4) & 0xF8;
    local_2 = func_8001D4C4((u8) local_2, param_1[1], local_4) & 0xF8;
    local_3 = func_8001D4C4((u8) local_3, param_1[2], local_4) & 0xF8;
  }

  *param_0 = (((local_1 << 8) | (local_2 << 3)) | (local_3 >> 2)) | 1;
}

void func_8001D6C0(u16 *param_0, s32 param_1, s32 param_2, u8 param_3)
{
  u16 *local_2;
  u16 *local_3;
  s32 local_4;
  s32 local_5;
  param_1 += 2;
  param_2 += 1;
  param_0 += ((param_2 * 0x850) + (param_1 * 5)) + 0x260;
  for (local_4 = 0; local_4 < 7; local_4++)
  {
    local_3 = &D_8003F778[((u32) (local_4 * 0x1DC)) + (((((u8) param_3) * 5) - 0xA0) ^ 0)];
    local_2 = param_0 + (local_4 * 0x130);
    osInvalDCache(local_2, 5);
    for (local_5 = 0; local_5 < 5; local_5++)
    {
      local_2[local_5] = (local_3[local_5] != 0x11)
          ? local_3[local_5]
          : func_8001D450(local_2[local_5]);
    }

    osWritebackDCache(local_2, 5);
  }

}

void func_8001D800(param_0) u8 param_0;
{
  if (!(&D_8007D170))
  {
  }
  while (1)
  {
    switch (param_0)
    {
      case 9:
        D_8007D170.local_1 = (D_8007D170.local_1 + 7) & (~7);
        if (D_8007D170.local_1 >= 0x38)
      {
        param_0 = 10;
        continue;
      }
        return;

      case 10:
        D_8007D170.local_1 = 0;
        D_8007D170.local_2++;
        if (D_8007D170.local_2 >= 30)
      {
        D_8007D170.local_2 -= 30;
        D_8007D170.local_3 = 1;
      }
        if (D_8007D170.local_3 == 0)
      {
        return;
      }
        (&D_8007D170)->local_4--;
        if (D_8007D170.local_4 < 0)
      {
        D_8007D170.local_4 += 30;
      }
        bzero(D_8007D170.local_0[D_8007D170.local_2], 0x38);
        return;

      case 12:
        bzero(D_8007D170.local_0, 0x690);

      case 13:
        D_8007D170.local_1 = 0;
        D_8007D170.local_2 = 0;
        D_8007D170.local_4 = 0;
        D_8007D170.local_3 = 0;
        return;

      default:
        if ((param_0 < 0x20) || (param_0 >= 0x7F))
      {
        return;
      }
        D_8007D170.local_0[D_8007D170.local_2][D_8007D170.local_1] = param_0;
        D_8007D170.local_1++;
        if (D_8007D170.local_1 >= 0x38)
      {
        param_0 = 10;
        continue;
      }
        return;

    }

  }

}

void func_8001D96C()
{
    func_8001D800(0xC);
}

void func_8001D98C(param_0) u16 param_0;
{
  if (param_0 < 0x38)
  {
    D_8007D800 = param_0;
  }
}

void func_8001D9AC(param_0) u16 param_0;
{
  if (param_0 < 0x1E)
  {
    D_8007D804 = param_0;
  }
}

void func_8001D9CC(param_0, param_1) u16 param_0; u16 param_1;
{
  func_8001D98C((unsigned int) param_0);
  func_8001D9AC(param_1);
}

void func_8001DA00(u8 *param_0, u8 *param_1) {
    D_8007D810 = 0;
    while (param_1--) {
        func_8001D800(*param_0++);
    }
}

void func_8001DA58(void) {
}

void func_8001DA60(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_4;
  u8 *local_5;
  u8 *local_6;
  s32 local_7;
  if (D_8007D810 == 0)
  {
    if (param_0 == 0)
    {
      param_0 = func_80014ED4();
    }
    osInvalDCache(param_0, func_80014EC8());
    local_5 = ((u8 *) &D_8007D170);
    local_4 = 0;
    do
    {
      local_2 = 1;
      local_0 = ((s32) (local_4 + D_8007D80C)) % 30;
      local_1 = 0;
      local_6 = local_5;
local_loop:
      local_7 = *local_6;
      if (local_2 != 0)
      {
        if ((local_7 != 0) && (local_7 != 0x20))
        {
          local_2 = 0;
          goto local_block;
        }
      }
      else
      {
local_block:
        if (local_7)
        {
          func_8001D6C0(param_0, local_1, local_0, local_7);
        }
      }
      local_1 += 1;
      local_6 += 1;
      if (local_1 != 0x38)
      {
        goto local_loop;
      }
      local_4 += 1;
      local_5 += 0x38;
    }
    while (local_4 != 0x1E);
    osWritebackDCache(param_0, func_80014EC8());
  }
}

void func_8001DB90(u16 *param_0, s32 param_1, s32 param_2, u8 *param_3)
{
  u32 i;
  s32 j;
  s32 row;
  s32 prod;
  param_1 += 2;
  param_2 += 1;
  row = param_2 * 2128;
  prod = param_1 * 5;
  param_0 += (row + prod) + 0x260;
  for (i = 0; i != 0x850; i += 0x130)
  {
    u16 *addr = i + param_0;
    osInvalDCache(addr, 5);
    for (j = 0; j != 5; j++)
    {
      func_8001D5C4(j + addr, param_3);
      osWritebackDCache(addr, 5);
    }
  }
}

int func_8001DC6C()
{
  int new_var;
  if (((int *) &D_8007D170)[424])
  {
    new_var = 0x1B4;
    ((int *) &D_8007D170)[424] = 0;
    new_var = new_var * 0;
  }
  else
  {
    ((int *) &D_8007D170)[424] = 1;
  }
}
