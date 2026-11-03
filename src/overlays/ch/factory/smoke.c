#include "common.h"

extern void *D_80800100_chfactorysmoke;
extern int D_80800148_chfactorysmoke[];
extern void func_800BBCB8(int, int, float, int, int *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9078(f32 *);

int chfactorysmoke_entrypoint_0()
{
  return &D_80800100_chfactorysmoke;
}

void func_8080000C_chfactorysmoke(u8 *param_0) {
    *(f32 *)(param_0 + 0x58) = func_800DC178(0.55f, 0.65f);
}

void func_80800044_chfactorysmoke(Actor *param_0)
{
    if (param_0->unk70_10 == 1 && func_800D9078(&param_0->unk58)) {
        func_808000A8_chfactorysmoke(param_0);
        param_0->unk58 = func_800DC178(0.55f, 0.65f);
    }
}

int func_808000A8_chfactorysmoke(s32 param_0)
{
  s32 local_0;
  local_0 = &D_80800148_chfactorysmoke;
  func_800BBCB8(param_0 + 4, 0, 1.0f, 4, local_0);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/factory/smoke.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800148_chfactorysmoke -> int[] */
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
void *D_80800100_chfactorysmoke = (void *)0x009D03D5;
static u32 D_80800100_chfactorysmoke_rest[17] = { 0x1, 0x0, (u32)func_80800044_chfactorysmoke, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)func_8080000C_chfactorysmoke, (u32)func_80107C2C, 0x80000602, 0x0, 0x0 };
int D_80800148_chfactorysmoke[26] = { 0x1D09DD, 0x180000, 0xF66, 0x10D40001, 0x0, 0xFA0000, 0x15E, 0x2CFFCD, 0x1C2FFBF, 0x3C0226, 0x46000B, 0x6D00C4, 0x0, 0x1F80C4, -0x6BFFFFEA, 0x2000027, 0xD001A, 0x31002A, 0x220240, 0x2B0053A, 0x6750015, 0xCC, 0x2A0000, 0x260180, 0x1C00000, 0x0 };
