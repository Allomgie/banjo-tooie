#include "common.h"

extern int D_808000F8_chlagoonpirate;
extern void _sucoaster_entrypoint_0();
extern void func_80102FDC(u8 *, f32);
extern void func_8010A3E8(u8 *, f32);

int chlagoonpirate_entrypoint_0()
{
  return (int)&D_808000F8_chlagoonpirate;
}

void func_8080000C_chlagoonpirate(u8 *param_0) {
    _sucoaster_entrypoint_0(param_0, 0);
    func_80102FDC(param_0, *(f32 *)(param_0 + 0x38) * 1.5f);
    func_8010A3E8(param_0, 0.8f);
}
