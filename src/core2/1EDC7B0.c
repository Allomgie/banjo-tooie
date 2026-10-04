#include "common.h"

typedef struct { u8 pad_0[0x74]; union { struct { u32 local_0 : 13; u32 local_1 : 1; u32 local_2 : 18; } local_3; struct { u8 local_4; u8 local_5 : 5; u8 local_6 : 1; u8 local_7 : 2; } local_8; } local_9; } Struct80102F14_80102F14;
typedef struct { u8 pad_0[0x78]; union { struct { u32 local_0 : 13; u32 local_1 : 1; u32 local_2 : 18; } local_3; struct { u8 local_4; u8 local_5 : 5; u8 local_6 : 1; u8 local_7 : 2; } local_8; } local_9; } Struct80102F14_80102F44;
typedef struct { u8 pad0[4]; f32 pos[3]; u8 pad10[0x28]; f32 unk38; u8 pad3C[4]; Unk80132ED0 *unk40; u8 pad44[0x20]; u16 pad64_0:15; u16 unk64_15:1; u16 pad66; u8 pad68[0xC]; u32 pad74_0:11; u32 unk74_11:1; u32 pad74_12:20; u8 pad78[4]; u32 pad7C_0:19; u32 unk7C_19:1; u32 pad7C_20:12; } S80103040;
typedef struct { u8 pad0[0x1C]; f32 unk1C; } R80103040;
extern R80103040 *func_80100368(S80103040 *);
extern void _chbadshad_entrypoint_1(S80103040 *, f32 *, f32);
extern S80103040 *func_80106790(Unk80132ED0 *);
int func_80102FA0();

void func_80102EC0(s32 arg0) 
{
}
s32 func_80102EC8(u8 *param_0, s32 param_1)
{
  s32 local_0;
  u32 local_1;
  u32 local_2;
  local_2 = *((u32 *) (((char *) param_0) + 0x70));
  local_1 = local_2 >> 0x19;
  if (1)
  {
  }
  if (1)
  {
    if (1)
    {
    }
  }
  if (1)
  {
  }
  local_0 = local_1 == 0;
  local_1 = local_2 >> 0x19;
  if (local_0 == 0)
  {
    local_0 = 0;
    ;
    return (func_800CC338(param_1, local_1 - 1, (((u32) (local_2 << 0x16)) >> 0x1A) - 1, local_1) + 1) != local_0;
  }
}

s32 func_80102F14(void *param_0)
{
    Struct80102F14_80102F14 *local_0;

    local_0 = param_0;
    if (local_0->local_9.local_3.local_1) {
        return 1;
    }
    local_0->local_9.local_8.local_6 = 1;
    return 0;
}

s32 func_80102F44(void *param_0)
{
    Struct80102F14_80102F44 *local_0;

    local_0 = param_0;
    if (local_0->local_9.local_3.local_1) {
        return 1;
    }
    local_0->local_9.local_8.local_6 = 1;
    return 0;
}

int func_80102F74(s32 param_0, s32 param_1)
{
  func_80102FA0(func_80100368(param_0), param_1);
}

int func_80102FA0(param_0, param_1) s32 * param_0; s32 param_1;
{
    s32 local_0;

    if (param_1 & 0x80000000) {
        local_0 = param_0[15];
    } else {
        local_0 = param_0[9];
    }
    return (local_0 & 0x7FFFFFFF & param_1) ? 1 : 0;
}

int func_80102FDC(f32 *param_0, f32 param_1)
{
  int new_var;
  new_var = 14;
  param_0[new_var] = param_1;
}

int func_80102FE8(u8 *param_0, s32 param_1)
{
  if (!param_1)
  {
  }
  if (((!(param_1 & 0xFF)) && (!param_1)) && (!param_1))
  {
  }
  if (param_1 != 0)
  {
    param_0[0x77] |= 0x20;
  }
  else
  {
    param_0[0x77] &= ~0x20;
  }
}

void func_80103014(s32 param_0)
{
  s32 *local_0 = (s32 *) (param_0 + 4);
  int new_var;
  new_var = 0xFFFFFFFFu;
  func_800EC124(param_0 + 4, local_0[new_var], param_0 + 0x44);
}

void func_80103040(S80103040 *param_0) {
    S80103040 *v;
    if (param_0->unk74_11) {
        if (param_0->unk7C_19) {
            R80103040 *r = func_80100368(param_0);
            _chbadshad_entrypoint_1(param_0, param_0->pos, param_0->unk38 * r->unk1C);
        } else if (param_0->unk40 != NULL) {
            v = func_80106790(param_0->unk40);
            if (v->unk7C_19 || !v->unk64_15) {
                R80103040 *r = func_80100368(param_0);
                _chbadshad_entrypoint_1(param_0, param_0->pos, param_0->unk38 * r->unk1C);
            }
        }
    }
}

int func_80103110(u8 *param_0, s32 param_1)
{
  int new_var;
  new_var = param_1;
  if (new_var)
  {
    if (((!(new_var & 0xFF)) && (!new_var)) && (!new_var))
    {
    }
    param_0[0x7E] |= (long) 0x40;
  }
  else
  {
    param_0[0x7E] &= ~0x40;
  }
}
