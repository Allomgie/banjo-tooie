#include "common.h"

extern s32 _badialog_entrypoint_0;
extern s32 _badialog_entrypoint_1;
extern s32 _badialog_entrypoint_2;

int badialog_entrypoint_0(void *param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = func_800F53D0(((*((u16 *) (((char *) param_0) + 0x1A))) & 0xFFFFFFFFu) >> 5);
  func_8009AD20(local_0, param_1);
  func_8009AD2C(local_0, param_2);
  func_8009E7C8(local_0, 0x81);
}

void badialog_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
}
s32 badialog_entrypoint_2(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
int badialog_entrypoint_3(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0[3];
  s32 local_1;
  func_8009C128(param_0, local_0);
  local_1 = func_8008E938(param_0) | 0;
  func_800C0534(param_1, param_2, local_0, local_1,
                &_badialog_entrypoint_0, &_badialog_entrypoint_1,
                &_badialog_entrypoint_2, 0);
}

int badialog_entrypoint_4(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  if (func_800DA298(param_3 | 0) != 0)
  {
    return 0;
  }
  if (badialog_entrypoint_3(param_0, param_1, param_2))
  {
    func_800DA3B8(param_3, 1);
  }
  return func_800DA298(param_3);
}
