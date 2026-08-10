#include "common.h"

void func_80091E48(u8 *param_0, int param_1);
void func_80091F74(u8 *param_0, s32 param_1);
int func_80091FE4();

s32 func_80091E10(void)
{
	return 0x4;
}

void func_80091E18(s32 arg0) 
{
}
void func_80091E20(void *param_0)
{
  *(s8 *)(*(s32 *)((char *)param_0 + 0x48) + 0x3) = 0;
  func_80091E48(param_0, 0x7F);
}

void func_80091E48(u8 *param_0, int param_1)
{
  u8 *temp_v0;
  u8 *new_var;
  temp_v0 = *((u8 **) (((s8 *) param_0) + 0x48));
  *(temp_v0 + (*((u8 *) (((s8 *) temp_v0) + 3)))) = param_1;
  temp_v0 = *((u8 **) (((s8 *) param_0) + 0x48));
  *((u8 *) (((s8 *) (new_var = temp_v0)) + 3)) = (u8) ((*((u8 *) (((s8 *) temp_v0) + 3))) + 1);
}

int func_80091E6C(u8 *param_0)
{
  u8 *local_0;
  local_0 = *(u8 **)(param_0 + 0x48);
  local_0[3]--;
}

s32 func_80091E80(u8 *param_0, s32 param_1)
{
  u8 *temp_v1;
  temp_v1 = *((u8 **) (((s8 *) param_0) + 0x48));
  return (unsigned long) (param_1 == ((*((u8 *) (((s8 *) (temp_v1 + (*((u8 *) (((s8 *) temp_v1) + 3))))) + (-((0, 1)))))) & param_1));
}

s32 func_80091EA0(void)
{
	return 0x1;
}

void func_80091EA8(s32 arg0)
{
    func_80091F74(arg0,0);
}

void func_80091EC8(void *param_0)
{
  int new_var;
  s32 *t6;
  char new_var2;
  new_var = (new_var2 = 4);
  new_var2 = 0x90 / new_var2;
  *((s8 *) ((*((s32 **) (((char *) param_0) + 76))) + new_var)) = (new_var = 0);
  func_80091F74(param_0, 1);
}

int func_80091EF0(s32 param_0)
{
  if (func_80091FE4(param_0))
  {
    func_80091F74(param_0, 3);
  }
  else
  {
    func_80091F74(param_0, 2);
  }
}

void func_80091F30(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  u8 local_3;
  s32 local_4;
  s32 local_5;
  local_5 = param_0;
  local_2 = *((s32 *) (param_0 + 0x4C));
  ;
  if ((*((u8 *) (*((s32 *) (param_0 + 0x4C))))) != 2)
  {
    goto LAB_80091F68;
  }
  local_4 = func_80091FE4();
  if (local_4 == 0)
  {
    goto LAB_80091F64;
  }
  func_80091F74(param_0, 3);
  LAB_80091F64:
  LAB_80091F68:
  ;


  ;
  ;
}

void func_80091F74(u8 *param_0, s32 param_1) {
    if (param_1 == 3) {
        if (func_800F8B70() == 0) {
            func_800F9104(1);
            if (func_80101238(0x96, (*(s32 *)((s8 *)(param_0) + 0x184))) == 0) {
                func_800A05DC(param_0);
            }
            goto block_4;
        }
    } else {
block_4:
        *(*(s8 **)((s8 *)(param_0) + 0x4C)) = (s8) param_1;
    }
}

int func_80091FE4()
{
  s32 local_0;
  local_0 = func_800DB9B0() == 0;
  return local_0 | 0;
}
