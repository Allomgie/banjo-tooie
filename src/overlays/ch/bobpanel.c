#include "common.h"

void _sudeflect_entrypoint_1(s32, f32, f32, f32, s32);
f32 func_80103EF4(void);
f32 func_80103EAC(s32);
extern int D_808000C0_chbobpanel[];

void func_80800000_chbobpanel(s32 param_0)
{
  f32 local_1;
  f32 local_0;
  local_0 = func_80103EF4();
  local_1 = 0.0f;
  _sudeflect_entrypoint_1(param_0 + 4, local_0, local_1, func_80103EAC(param_0), 0x1E);
}

int func_8080004C_chbobpanel(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x1F)
  {
    func_801015D0(param_0);
    func_800DF744(2, 3);
    func_800DF744(3, 1);
    func_800DF744(4, 1);
    return 1;
  }
  return 0;
}

int chbobpanel_entrypoint_0()
{
    return (int)&D_808000C0_chbobpanel;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/bobpanel.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000C0_chbobpanel -> int[] */
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000C0_chbobpanel[20] = { 0x1580532, 0x8C80001, 0x0, (u32)func_80800000_chbobpanel, (u32)func_80105834, (u32)func_801018A4, 0x0, 0x0, 0x0, 0x1000, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_8080004C_chbobpanel, 0x0, 0x0, 0x0 };
