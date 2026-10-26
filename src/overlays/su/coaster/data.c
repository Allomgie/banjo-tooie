#include "common.h"

extern s32 D_8080041C_sucoasterdata;
extern s32 D_808003C0_sucoasterdata[][23];
extern u8 D_808006FC_sucoasterdata[];
extern u8 D_80800750_sucoasterdata[];
extern u8 D_808007A4_sucoasterdata[];
extern u8 D_808007F8_sucoasterdata[];
extern u8 D_8080084C_sucoasterdata[];
extern u8 D_808008A0_sucoasterdata[];
extern u8 D_808008F4_sucoasterdata[];
extern u8 D_80800948_sucoasterdata[];
extern u8 D_80800990_sucoasterdata[];

s32 sucoasterdata_entrypoint_0(u8 **param_0)
{
  s32 *local_0;
  s32 local_1;
  u32 local_2;
 local_1 = 1; local_2 = ((u32) (*((u32 *) (((s8 *) (*param_0)) + 0x24)))) >> 0x16; if (local_2 == (*((u16 *) D_808003C0_sucoasterdata))) { return 0; } local_0 = &D_8080041C_sucoasterdata; loop_3: if (local_2 == (*((u16 *) (((s8 *) local_0) + 0)))) { return local_1;
  }

  if (local_2 == (*((u16 *) (((s8 *) local_0) + 0x5C))))
  {
    return local_1 + 1;
  }
  if (local_2 == (*((u16 *) (((s8 *) local_0) + 0xB8))))
  {
    return local_1 + 2;
  }
  if (local_2 == (*((u16 *) (((s8 *) local_0) + 0x114))))
  {
    return local_1 + 3;
  }
  local_1 += 4;
  local_0 += 0x5C;
  if (local_1 == 9)
  {
    return 0;
  }
  goto loop_3;
}

s32 *sucoasterdata_entrypoint_1(s32 param_0)
{
  return D_808003C0_sucoasterdata[param_0];
}

int sucoasterdata_entrypoint_2(int param_0)
{
    switch (param_0) {
    case 0:
        return 0x3C;
    case 1:
        return 0x3C;
    case 2:
        return 0x5A;
    case 3:
        return 0x78;
    case 4:
        return 0x32;
    case 5:
        return 0x78;
    case 6:
        return 0x50;
    case 7:
        return 0x28;
    case 8:
        return 0x78;
    }
    return 0;
}

int sucoasterdata_entrypoint_3(s32 param_0)
{
    switch (param_0)
    {
        case 0:
            return 0xf0;
        case 1:
            return 0xd2;
        case 2:
            return 0xb4;
        case 3:
            return 0x12c;
        case 4:
            return 0x78;
        case 5:
            return 0x12c;
        case 6:
            return 0xc8;
        case 7:
            return 0xaa;
        case 8:
            return 0xc8;
    }
    return 0;
}

int sucoasterdata_entrypoint_4(int param_0)
{
    switch (param_0)
    {
        case 0:
            return 0x140;
        case 1:
            return 0x12C;
        case 2:
            return 0x154;
        case 3:
            return 0x168;
        case 4:
            return 0x190;
        case 5:
            return 0x17C;
        case 6:
            return 0x1A4;
        case 7:
            return 0x1B8;
        case 8:
            return 0x1CC;
        default:
            return 0;
    }
}

void *sucoasterdata_entrypoint_5(s32 param_0, s32 param_1, s32 *param_2)
{
    switch (param_0) {
    case 0:
        *param_2 = 7;
        return D_8080084C_sucoasterdata;
    case 1:
        *param_2 = 7;
        return D_80800990_sucoasterdata;
    case 3:
        switch (param_1) {
        case 0x327:
            *param_2 = 7;
            return D_808006FC_sucoasterdata;
        case 0x328:
            *param_2 = 7;
            return D_80800750_sucoasterdata;
        case 0x329:
            *param_2 = 7;
            return D_808007A4_sucoasterdata;
        case 0x32A:
            *param_2 = 7;
            return D_808007F8_sucoasterdata;
        }
        break;
    case 5:
        *param_2 = 7;
        return D_808008A0_sucoasterdata;
    case 6:
        *param_2 = 7;
        return D_808008F4_sucoasterdata;
    case 7:
        *param_2 = 6;
        return D_80800948_sucoasterdata;
    }
    *param_2 = 0;
    return NULL;
}
