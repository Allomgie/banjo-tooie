#include "common.h"

extern int D_808000F8_chdiggerfly;
extern void *D_80800140_chdiggerfly;
extern void _sucoasterfly_entrypoint_1();
extern void func_80102FDC(u8 *, f32);
extern void func_8010A3E8(u8 *, f32);

int chdiggerfly_entrypoint_0()
{
    return (int)&D_808000F8_chdiggerfly;
}

int chdiggerfly_entrypoint_1()
{
  return &D_80800140_chdiggerfly;
}

void func_80800018_chdiggerfly(u8 *param_0) {
    _sucoasterfly_entrypoint_1(param_0, 0);
    func_80102FDC(param_0, *(f32 *)(param_0 + 0x38) * 0.75f);
    func_8010A3E8(param_0, 0.75f);
}
