#include "gc/introtext.h"

typedef struct { u32 pad_0 : 10; u32 local_0 : 16; u32 local_1 : 6; } IntroTextRecord;
extern IntroTextRecord D_80800250_gcintrotext[];
extern u16 D_8080056C_gcintrotext;
extern u16 D_8080056E_gcintrotext;
extern u16 D_80800570_gcintrotext[24];
IntroTextRecord *func_808000C8_gcintrotext();
int func_808001AC_gcintrotext();

void gcintrotext_entrypoint_0()
{
    func_800DA544(FLAG2_6CB_UNK);
}

s32 gcintrotext_entrypoint_1(void)
{
  s32 out;
  unsigned long long new_var;
  out = (new_var = (func_800DA9E4(0x6CB, 0)) ? (1) : (0));
  if (!out)
  {
  }
  return out;
}

s32 gcintrotext_entrypoint_2(s32 param_0, s32 *param_1, s32 *param_2)
{
    IntroTextRecord *local_0;
    if (param_0 == -1) param_0 = func_800EA05C();
    local_0 = func_808000C8_gcintrotext(param_0);
    if (local_0 == NULL) return -1;
    *param_1 = local_0->local_0;
    *param_2 = local_0->local_1;
    return func_808001AC_gcintrotext(param_0);
}

IntroTextRecord *func_808000C8_gcintrotext(param_0) s32 param_0;
{
    s32 local_0;

    for (local_0 = 0; local_0 < 199; local_0++) {
        if (param_0 == D_80800250_gcintrotext[local_0].pad_0) {
            return &D_80800250_gcintrotext[local_0];
        }
    }
    return NULL;
}

int func_808001AC_gcintrotext(param_0) s32 param_0;
{
    s32 local_0;
    if (param_0 == D_8080056C_gcintrotext) return 0;
    if (param_0 == D_8080056E_gcintrotext) return 0;
    for (local_0 = 0; local_0 < 24; local_0++) {
        if (param_0 == D_80800570_gcintrotext[local_0]) return 0;
    }
    return 1;
}
