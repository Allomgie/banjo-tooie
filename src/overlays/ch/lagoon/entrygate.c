#include "ch/lagoonentrygate.h"

extern s32 _chdoormake_entrypoint_0(Actor *, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern int D_80800150_chlagoonentrygate[];

void func_80800000_chlagoonentrygate(Actor *param_0)
{
    s32 local_0;
    if (_sujiggy_entrypoint_20(3)) func_800DA544(0x395);
    if (func_800D3E40(0xB) && !_glcutDll_entrypoint_19(0x7D)) {
        local_0 = -1;
        func_80101FDC(param_0, 4);
    } else local_0 = 0x395;
    _chdoormake_entrypoint_0(param_0, -150.0f, 0, local_0);
    _chdoormake_entrypoint_5(param_0, 0.0f);
}

void func_8080008C_chlagoonentrygate(Actor *param_0)
{
  u16 local_0;
  Actor *local_1 = param_0;

  local_0 = *(u16 *)((u8 *)local_1 + 0x72);
  if (((local_0 & 0xFFFFu) >> 10) == 3) {
    if (!local_1->unk64_20) {
      func_800C3F48(0x66509D6D);
      local_1->unk64_20 = 1;
      *(f32 *)((u8 *)local_1 + 0x34) = 1.5f;
    } else if (func_800D90A4((u8 *)local_1 + 0x34) != 0) {
      func_800C3F48(0x66509CA1);
      *(f32 *)((u8 *)local_1 + 0x34) = 1.0f;
    }
  }
  _chdoor_entrypoint_0(param_0);
}

int chlagoonentrygate_entrypoint_0()
{
  return &D_80800150_chlagoonentrygate;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lagoon/entrygate.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800150_chlagoonentrygate -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_80800150_chlagoonentrygate[20] = { 0xAC0392, 0x96E0001, 0x0, (u32)func_8080008C_chlagoonentrygate, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_80800000_chlagoonentrygate, (u32)func_80107C2C, -0x7FFFDBFE, (u32)_chdoor_entrypoint_1, 0x0, 0x0, 0x0 };
