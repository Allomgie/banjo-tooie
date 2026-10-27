#include "common.h"

typedef struct { s32 unk0; u8 unk4; u8 pad5[4]; u8 unk9; u8 padA[5]; u8 unkF; u8 unk10; u8 unk11; } StatusB400;
extern StatusB400 D_8012B400;
extern u8 D_80800230_gcstatusDll[4][2];
extern u8 D_8012B3FC[];
extern u8 D_8012762C;
void gcstatusDll_entrypoint_3();
void gcstatusDll_entrypoint_6();

void gcstatusDll_entrypoint_0(void)
{
    s32 i;

    D_8012B400.unk4 = 2;
    for (i = 0; i < 4; i++) {
        gcstatusDll_entrypoint_3(i, D_80800230_gcstatusDll[i][0]);
        gcstatusDll_entrypoint_6(i, D_80800230_gcstatusDll[i][1]);
    }
    D_8012B400.unk9 = 1;
    D_8012B400.unkF = 0;
    D_8012B400.unk10 = 0;
    D_8012B400.unk11 = 2;
    D_8012B400.unk0 = 0x173;
}

void gcstatusDll_entrypoint_1(s32 param_0)
{
    (*(s32 *)((u8 *)((u8 *) D_8012B3FC) + 0x4)) = param_0;
}

void gcstatusDll_entrypoint_2(long param_0)
{
  (*(u8 *)((u8 *)((u8 *) D_8012B3FC) + 0x8)) = param_0;
}

void gcstatusDll_entrypoint_3(param_0, param_1) s32 param_0; s32 param_1;
{
  D_8012B3FC[(param_0) + 9] = param_1;
}

void gcstatusDll_entrypoint_4(long param_0)
{
  (*(u8 *)((u8 *)((u8 *) D_8012B3FC) + 0xd)) = param_0;
}

int gcstatusDll_entrypoint_5(s32 param_0)
{
  u8 *local_0 = ((u8 *) D_8012B3FC);
  local_0[0x12] = param_0;
}

void gcstatusDll_entrypoint_6(param_0, param_1) s32 param_0; s32 param_1;
{
  D_8012B3FC[param_0 + 0xE] = param_1;
}

int gcstatusDll_entrypoint_7(int param_0)
{
  u8 *local_0 = &D_8012B3FC;
  local_0[0x13] = param_0;
}

void gcstatusDll_entrypoint_8(long param_0)
{
  (*(u8 *)((u8 *)((u8 *) D_8012B3FC) + 0x14)) = param_0;
}

int gcstatusDll_entrypoint_9(unsigned int param_0)
{
  D_8012B3FC[0x15] = param_0;
}

int gcstatusDll_entrypoint_10()
{
  u8 *local_0 = &D_8012B3FC;
  return local_0[8];
}

int gcstatusDll_entrypoint_11()
{
  u8 new_var;
  u8 *local_0 = &D_8012B3FC;
  new_var = local_0[8];
  if (D_8012762C != 0x1B)
  {
    return 1;
  }
  return new_var;
}

int gcstatusDll_entrypoint_12()
{
  return ((int *) D_8012B3FC)[1];
}

int gcstatusDll_entrypoint_13(s32 param_0)
{
  u8 *local_0 = &D_8012B3FC;
  return local_0[param_0 + 9];
}

s32 gcstatusDll_entrypoint_14(void)
{
  s32 addr;
  unsigned int new_var;
  u8 *local_0 = (u8 *) (((s32 *) D_8012B3FC));
  int new_var2;
  addr = 0xFF;
  addr++;
  addr = 0x0000000E;
  addr--;
  new_var2 = addr;
  new_var2 = addr & new_var2;
  new_var = local_0[addr & (addr ^ 0)];
  return (new_var = local_0[new_var2]) ^ 0;
}

int gcstatusDll_entrypoint_15()
{
  u8 *local_0 = &D_8012B3FC[0x12];
  return *local_0;
}

int gcstatusDll_entrypoint_16(s32 param_0)
{
  u8 *local_0 = &(*(u8 *)((u8 *)((u8 *) D_8012B3FC) + 0xe));
  return local_0[param_0];
}

int gcstatusDll_entrypoint_17()
{
  u8 new_var;
  u8 *local_0 = &D_8012B3FC;
  return new_var = local_0[0x13];
}

int gcstatusDll_entrypoint_18()
{
  u8 new_var;
  u8 *local_0 = ((u8 *) D_8012B3FC);
  new_var = local_0[0x14];
  return new_var;
}

unsigned int gcstatusDll_entrypoint_19(void)
{
  unsigned char new_var;
  new_var = ((s8 *) D_8012B3FC)[0x15];
  return new_var;
}

int gcstatusDll_entrypoint_20()
{
  int local_0;
  if (func_800D3948())
  {
    local_0 = gcstatusDll_entrypoint_14();
    switch (local_0)
    {
      case 0:

      local_0 = local_0;
      case 1:
 case 2:
        break;

      case 4:
        break;

      case 3:
      case 5:
        return 1;

      case 6:
        break;

      default:
        break;
        return 1;

    }

  }
  return 0;
}
