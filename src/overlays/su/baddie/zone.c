#include "common.h"

typedef struct { u8 pad[0x70]; u32 pad70:13; u32 flag:1; u32 rest:18; u8 pad74[4]; u8 f78; } ZoneS;
extern s32 _glzone_entrypoint_5();
extern s32 func_800BEC28(s32);
extern void _glzone_entrypoint_4(int, int);
extern int func_800BEC1C(void);

void subaddiezone_entrypoint_0(ZoneS *param_0) {
    if (!param_0->flag) {
        param_0->f78 = _glzone_entrypoint_5(func_800BEC28(0), (u8 *)param_0 + 4, param_0->f78);
    }
}

void subaddiezone_entrypoint_1(Actor *param_0)
{
  int local_0;
  unsigned int new_var;
  int new_var2;
  local_0 = func_800BEC1C();
  new_var = (*param_0).unk78;
  new_var = local_0;
  new_var2 = new_var | new_var;
  _glzone_entrypoint_4(new_var2, param_0->unk78);
}
