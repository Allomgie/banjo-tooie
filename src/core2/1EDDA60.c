#include "common.h"

extern s32 D_80136E70;

int func_80104170()
{
  s32 local_0;
  local_0 = func_8008B4F4();
  D_80136E70 = freelist_new(local_0 | 0, 0x20);
}

s32 func_801041A0(void){
    freelist_free(D_80136E70);
    D_80136E70 = 0;
}

void func_801041C8()
{
  if (D_80136E70 != 0)
  {
    D_80136E70 = freelist_defrag(D_80136E70);
  }
}

s32 func_80104200(param_0) s16 param_0;{
    s32 local_0;
    local_0 = (param_0)? freelist_at(D_80136E70, param_0): 0;
    return local_0;
}

int func_80104248(s32 param_0)
{
  s16 local_0;
  local_0 = *(s16*)((char*)param_0 + 0x8c);
  func_80104200(local_0);
}

int func_80104268(s16 *param_0)
{
  s32 local_1;
  s32 local_0;
  local_1 = 0;
  local_0 = freelist_next(&D_80136E70, &local_1);
  func_8008B518(local_0 | 0, 0 | 0);
  *param_0 = local_1;
  return local_0;
}

int func_801042B8(s32 param_0)
{
  func_80104268(param_0 + 0x8C);
}

void func_801042D8(s16 *param_0)
{
  s32 local_0;
  local_0 = func_80104200(*param_0);
  if (local_0 != 0)
  {
    func_8008B5E8(local_0);
    freelist_erase(((int) D_80136E70), *param_0);
    *param_0 = 0;
  }
}

int func_80104328(s32 param_0)
{
  func_801042D8(param_0 + 0x8C);
}
