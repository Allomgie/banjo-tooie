#include "common.h"

extern void func_80112E50(void *param_0, int param_1, int param_2);

s32 func_80114D90() 
{
    return 0x8;
}

void func_80114D98(u8 *param_0, s32 param_1) {
    s16 *local_0;
    s32 local_1;

    if ((param_1 == 0) || (param_1 == 1)) {
        local_1 = param_1 * 2;
        (*(s16 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (8))) + local_1)) + (4))) = 1;
        local_0 = (*(s32 *)((s8 *)(param_0) + (8))) + local_1;
        *local_0 += 1;
    }
}

void func_80114DD8(void *param_0)
{
  s16 *temp_v0;
  s16 *var_v0;
  var_v0 = *((s16 **) (((s8 *) param_0) + 8));
  if ((*((s16 *) (((s8 *) var_v0) + 4))) == 0)
  {
    if ((*((s16 *) (((s8 *) var_v0) + 0))) >= 5)
    {
      func_80112E50(param_0, 0xC0A00000, 2);
      var_v0 = *((s16 **) (((s8 *) param_0) + 8));
    }
    *var_v0 = 0;
    var_v0 = *((s16 **) (((s8 *) param_0) + 8));
  }
  if ((*((s16 *) (((s8 *) var_v0) + 6))) == 0)
  {
    if ((*((s16 *) (((s8 *) var_v0) + 2))) >= 5)
    {
      func_80112E50(param_0, 0x40A00000, 2);
      var_v0 = *((s16 **) (((s8 *) param_0) + 8));
    }
    *((s16 *) (((s8 *) var_v0) + 2)) = 0;
    var_v0 = *((s16 **) (((s8 *) param_0) + 8));
  }
  *((s16 *) (((s8 *) var_v0) + 6)) = 0;
  if (var_v0)
  {
  }
  temp_v0 = *((s16 **) (((s8 *) param_0) + 8));
  *((s16 *) (((s8 *) temp_v0) + 4)) = (s16) (*((s16 *) (((s8 *) temp_v0) + 6)));
}
