#include "core2/1E76500.h"

s32 func_8009CC10() 
{
    return 0x84;
}

s32 func_8009CC18(PlayerState *param_0, f32 *param_1)
{
  int new_var2;
  f32 *new_var;
  u8 *local_0;
  u8 *new_var3;
  u8 *local_1;
  local_0 = *((u8 **) (((char *) param_0) + 0xF0));
  new_var2 = 0xC;
  local_1 = ((*((u8 *) (((char *) local_0) + 0x80))) * 0x10) + (new_var3 = local_0);
  if ((*((u8 *) (local_1 - 0xF))) == 0)
  {
    return 0;
  }
  new_var = param_1;
  func_800EE7F8(new_var, local_1 - new_var2);
 goto dummy_label_479513; dummy_label_479513: ;
  return 1;
}

s32 func_8009CC68(PlayerState *param_0)
{
  int new_var2;
  u8 *local_0;
  u8 local_1;
  u8 *new_var;
  local_0 = *((u8 **) (((u8 *) param_0) + 0xF0));
  new_var = local_0;
  local_1 = new_var[0x80];
  if (local_1 == 0)
  {
    return 0;
  }
  new_var2 = (local_1 * 0x10) - 0x10;
  return new_var[new_var2];
}

void func_8009CC90(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xF0)))) + (0x81))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xF0)))) + (0x80))) = 0;
}

void func_8009CCA4(u8 *param_0)
{
  u8 *temp_v0;
  int temp_v1;
  temp_v0 = *((u8 **) (((s8 *) param_0) + 0xF0));
  temp_v1 = *((u8 *) (((s8 *) temp_v0) + 0x80));
  if (temp_v1 != 0)
  {
    *((u8 *) (((s8 *) temp_v0) + 0x80)) = (u8) (temp_v1 - 1);
    if ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xF0)))) + 0x80))) == 0)
    {
      func_8009BDAC(param_0, 0x3F99999A);
      *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xF0)))) + 0x81)) = 0;
    }
  }
}

void func_8009CCFC(u8 *param_0, unsigned int param_1)
{
  u8 *local_0;
  unsigned int new_var;
  u8 *new_var2;
  local_0 = *((u8 **) (param_0 + 0xF0));
  *(local_0 + ((*((u8 *) (local_0 + 0x80))) * 0x10)) = param_1;
  local_0 = *((u8 **) (param_0 + 0xF0));
 if (0) { }
  *((s8 *) ((local_0 + ((*((u8 *) (local_0 + 0x80))) * 0x10)) + 1)) = 0;
  local_0 = *((u8 **) (param_0 + 0xF0));
  new_var2 = (u8 *) (local_0 + 0x80);
  func_800EFD24((local_0 + ((*new_var2) * 0x10)) + (new_var = 4));
  local_0 = *((u8 **) (param_0 + 0xF0));
  *((u8 *) (local_0 + 0x80)) = (*((u8 *) (local_0 + 0x80))) + 1;
}

void func_8009CD70(u8 *param_0, s32 param_1)
{
  u8 *temp_v0;
  u8 *temp_v0_2;
  u8 *temp_v0_3;
  temp_v0 = *((u8 **) (((char *) param_0) + 0xF0));
  *((s8 *) ((((char *) temp_v0) + ((*((u8 *) (((char *) temp_v0) + 0x80))) * 0x10)) - 0xF)) = 1;
  if (param_1 != 0)
  {
    temp_v0_2 = *((u8 **) (((char *) param_0) + 0xF0));
    func_800EE7F8((((char *) temp_v0_2) + ((*((u8 *) (((char *) temp_v0_2) + 0x80))) * 0x10)) - ((0, 0xC)));
  }
  else
  {
    temp_v0_3 = *((u8 **) (((char *) param_0) + 0xF0));
    func_800EFD24((((char *) temp_v0_3) + ((*((u8 *) (((char *) temp_v0_3) + 0x80))) * 0x10)) - ((0, 0xC)));
  }
}

/* Old style, so that the call further down may pass the two extra arguments
   the original sets up but this function never reads. */
int func_8009CDE0(param_0, param_1) Actor *param_0; s32 param_1;
{

    s32 local_1;
    local_1 = 0;
    switch (param_1)
    {
        case 1:
            if (func_8009E7C8(param_0, 0x1E) == 2)
            {
                local_1 = 1;
            }
            break;

        case 2:
            if (func_8009E7C8(param_0, 0x1C) == 2)
            {
                local_1 = 1;
            }
            break;

        case 3:
            if (func_8009E7C8(param_0, 0x1D) == 2)
            {
                local_1 = 1;
            }
            break;

        case 4:
            if (func_8009E7C8(param_0, 0x25) == 2)
            {
                local_1 = 1;
            }
            break;

        default:
            local_1 = 1;
            break;
    }

    if (local_1 != 0)
    {

        *(u8 *)((char *)(*(s32 **)((char *)param_0 + 0xF0)) + 0x81) = param_1;
    }
}

void func_8009CEE8(u8 *param_0)
{
  u8 **new_var;
  ;
  if ((*((u8 **) (param_0 + 0xF0)))[0x80] != 0)
  {
    (*((u8 **) (param_0 + 0xF0)))[0x81] = 0;
  }
}

void func_8009CF04(struct Actor *param_0)
{
  s32 local_0;
  u8 *new_var;
  u8 *local_1;
  u8 *local_2;
  int new_var2;
  u8 local_3;
  int local_4;
  local_1 = *((u8 **) (((u8 *) param_0) + 0xF0));
  local_3 = local_1[0x80];
  new_var2 = 0x81;
  if (local_3 != 0)
  {
 do { local_4 = *((u8 *) ((((char *) local_1) + ((local_3 & 0xFFFFFFFF) * 0x10)) - 0x10)); if (((s32) local_3) > 0) { local_0 = 0; local_2 = local_1; do { if ((local_4 && local_4) && local_4) { } new_var = &(*local_2); local_0 = local_0 + 0x10; if ((*new_var) == 1) { local_4 = 1; } local_2 += 0x10; } while (local_0 < (local_3 * 0x10)); } if (local_4 != local_1[new_var2]) { func_8009CDE0(param_0, local_4 ^ 0, local_4, local_1); } } while (0);
  }
}
