#include "common.h"

void func_800A54C0(s32 param_0) {
    s32 local_0;

    local_0 = func_8011001C(func_8008FFE8());
    if (local_0 != 0) {
        _ncfixposrot_entrypoint_2(local_0, param_0);
    }
}

void func_800A54F8(s32 arg0)
{
    _ncfixposrot_entrypoint_8(func_8008FFE8(),arg0);
}

int func_800A5524()
{
  s32 local_0;
  local_0 = func_8008FFE8();
  _ncfixposrot_entrypoint_9(local_0 | 0);
}
