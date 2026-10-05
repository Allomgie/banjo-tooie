#include "common.h"

typedef struct { u8 pad0[0x64]; u32 pad64_0:14; u32 unk64_14:1; u16 unk64_15:1; u16 pad64_16:16; u8 pad68[0x14]; s32 pad7C:16; s32 unk7E_15:1; s32 pad7E:15; } S8010A79C;
extern u8 *func_80100368(S8010A79C *);

void func_8010A730(s32 arg0, s32 arg1) {
}
int func_8010A73C(s32 *param_0, s32 param_1)
{
  func_801039E4(*param_0);
}

void func_8010A764(s32 param_0, s32 param_1) {
    ((void (*)(s32, s32))*(s32*)(func_80100368(param_0) + 0x14))(param_0, param_1);
}

void func_8010A79C(S8010A79C *param_0, s32 param_1)
{
    if (param_0->unk7E_15) {
        if (!param_0->unk64_14) {
            if (param_0->unk64_15) {
                (*(void (**)(S8010A79C *, s32))(func_80100368(param_0) + 0x14))(param_0, param_1);
            }
        }
    }
}

void func_8010A800(u8 **param_0, s32 param_1)
{
  unsigned short new_var3;
  int new_var2;
  u8 *local_0;
  u8 *new_var;
  local_0 = *param_0;
  new_var = local_0;
  new_var2 = 2;
  *((u16 *) (((s8 *) new_var) + 0x2A)) = (u16) (((*((u16 *) (((s8 *) new_var) + 0x2A))) & 0xFE01) | (((new_var3 = 1 << param_1) * new_var2) & 0x1FE));
}

void func_8010A828(u8 **param_0, s32 param_1)
{
  unsigned short new_var2;
  u16 new_var;
  u16 new_var3;
  u8 *local_0;
  local_0 = *param_0;
  new_var = (u16) (((param_1 * 2) & (0x1FE & 0xFFFFFFFFu)) | ((*((u16 *) (((s8 *) local_0) + 0x2A))) & 0xFE01));
  new_var2 = param_1 * 2;
  new_var3 = *((u16 *) (((s8 *) local_0) + 0x2A));
  new_var = (u16) ((new_var2 & (0x1FE & 0xFFFFFFFFu)) | (new_var3 & 0xFE01));
  *((u16 *) (((s8 *) local_0) + 0x2A)) = new_var;
}

u32 func_8010A848(u8 **param_0) {
    return (u32) ((*(s32 *)((s8 *)(*param_0) + (0x28))) << 0x17) >> 0x18;
}

int func_8010A85C(u8 *param_0, s32 param_1)
{
  int new_var;
  param_0[0x77] = (param_0[0x77] & 0xFFF0) | (new_var = (param_1 & 0xF) & 0xFFFF);
}

void func_8010A874(Image *param_0)
{
  void *local_0;
  u16 local_2[2];
  unsigned int local_3;
  u16 local_1[6];
  s32 local_4;
  s32 local_5;
  func_800EB800();
  func_800E3A30(&local_1);
  param_0 = func_801067C4(&local_2);
  if (param_0 != 0)
  {
    do
    {
      local_0 = *((void **) (((char *) param_0) + 0x0));
      if ((((*((u16 *) (((char *) local_0) + 0x14))) != 0) && ((*((u16 *) (((char *) param_0) + 0x64))) & 1)) && (((*((u8 *) (((char *) param_0) + 0x78))) == 0) || (_subaddiezone_entrypoint_1(param_0) != 0)))
      {
        local_5 = 1;
        local_4 = 0;
        local_3 = ((u32) ((*((s32 *) (((char *) local_0) + 0x28))) << 0x17)) >> 0x18;
        do
        {
          if (local_3 & local_5)
          {
            func_800EB3D0(*((s32 *) (((char *) local_0) + 0x0)), local_4, &local_1);
          }
          local_4 += 1;
          local_5 *= 2;
        }
        while (local_4 != 7);
      }
      param_0 = func_8010682C(&local_2);
    }
    while (param_0 != 0);
  }
}
