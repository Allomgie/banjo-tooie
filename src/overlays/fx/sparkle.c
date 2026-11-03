#include "common.h"

extern u32 D_808003AC_fxsparkle[];
extern void func_800BABB8(u32, s32, s32, f32, u32);
extern u32 _fxspgold_entrypoint_2(void);
int fxsparkle_entrypoint_1();

int fxsparkle_entrypoint_0(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_800EE88C(local_0, param_0 | 0);
  fxsparkle_entrypoint_1(local_0, param_1);
}

int fxsparkle_entrypoint_1(param_0, param_1) s32 param_0; s32 param_1;
{
    u32 local_0;
    u32 *local_1 = &D_808003AC_fxsparkle[param_1];
    local_0 = _fxspgold_entrypoint_2();
    if (*local_1 != 0)
    {
        func_800BABB8(local_0 | 0, param_0, 0, 1.0f, *local_1);
    }
}

void fxsparkle_entrypoint_2()
{
    _fxspgold_entrypoint_0();
}

s32 fxsparkle_entrypoint_3(s32 param_0, f32 position[3], s32 param_2, s32 param_3) {
    _fxspgold_entrypoint_1(param_0, position, param_2, param_3);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/fx/sparkle.data.s) is defined here in C.
 * Values are taken from the ROM. */
u32 D_808000D0_fxsparkle[10] = { 0x1D09E2, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000A, 0x240051, 0x510A1A, 0x0 };
u32 D_808000F8_fxsparkle[10] = { 0x1D09E2, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000A, 0x240051, 0x51071A, 0x0 };
u32 D_80800120_fxsparkle[7] = { 0x1D09E2, 0x1E0007, 0x7002C, 0xFFBA0064, 0xFFBA0046, 0xFA0046, 0x51A0000 };
u32 D_8080013C_fxsparkle[7] = { 0x1D09E5, 0x1E0007, 0x7002C, 0xFFBA0064, 0xFFBA0046, 0xFA0046, 0x51A0000 };
u32 D_80800158_fxsparkle[9] = { 0x1D09E4, 0x1E000C, 0xC002C, 0xFFB50064, 0xFFB5004B, 0xFA004B, 0x24004C, 0x4C051A, 0x0 };
u32 D_8080017C_fxsparkle[9] = { 0x1D09E2, 0x1E0007, 0x7002C, 0xFFB50064, 0xFFB5004B, 0xFA004B, 0x24004C, 0x4C051A, 0x0 };
u32 D_808001A0_fxsparkle[11] = { 0x1D09E4, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000F, 0x240066, 0x66002B, 0x1800180, 0x71A0000 };
u32 D_808001CC_fxsparkle[12] = { 0x1D09E2, 0x1E000A, 0xA002C, 0xFFB50064, 0xFFB5004B, 0xFA004B, 0xAFFF8, 0x5FFF8, 0xFFFB0023, 0x80024, 0x450045, 0x51A0000 };
u32 D_808001FC_fxsparkle[10] = { 0x1D09E2, 0x2C0000, 0x640000, 0xFA, 0xC, 0xF0024, 0x40004C, 0x2B0080, 0x180021A, 0x0 };
u32 D_80800224_fxsparkle[4] = { 0x1D09E2, 0x240100, 0x200011A, 0x0 };
u32 D_80800234_fxsparkle[24] = { 0x1D09E2, 0x150000, 0xCC001E, 0x70007, 0xB0014, 0x3C0032, 0x2C, 0xFFBA0096, 0xFFBA0046, 0xFA0046, 0x240066, 0x66002B, 0x1800180, 0x51A002B, 0x1000100, 0x2CFF88, 0x5AFF88, 0x780096, 0x78051A, 0x2B00CC, 0xCC051A, 0x2B0066, 0x66051A, 0x0 };
u32 D_80800294_fxsparkle[6] = { 0x1D09E0, 0x240066, 0x66000C, 0x14001B, 0xFE70FF38, 0x31A0000 };
u32 D_808002AC_fxsparkle[7] = { 0x1D09E1, 0x1E0007, 0x7002C, 0xFFBA0064, 0xFFBA0046, 0xFA0046, 0x51A0000 };
u32 D_808002C8_fxsparkle[10] = { 0x1D09DE, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000A, 0x240051, 0x51071A, 0x0 };
u32 D_808002F0_fxsparkle[10] = { 0x1D09DF, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000A, 0x240051, 0x51071A, 0x0 };
u32 D_80800318_fxsparkle[10] = { 0x1D09E4, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000A, 0x240051, 0x51071A, 0x0 };
u32 D_80800340_fxsparkle[10] = { 0x1D09E1, 0x1E000A, 0xA002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xC000A, 0x240051, 0x51071A, 0x0 };
u32 D_80800368_fxsparkle[10] = { 0x1D09E2, 0x1E0032, 0x32002C, 0xFF9C0064, 0xFF9C0064, 0xFA0064, 0xE0014, 0x1E0024, 0x510051, 0x11A0000 };
u32 D_80800390_fxsparkle[7] = { 0x1D09E3, 0x1E0007, 0x7002C, 0xFFBA0064, 0xFFBA0046, 0xFA0046, 0x51A0000 };
u32 D_808003AC_fxsparkle[21] = { (u32)&D_808000D0_fxsparkle, (u32)&D_808000F8_fxsparkle, (u32)&D_80800120_fxsparkle, (u32)&D_8080013C_fxsparkle, (u32)&D_80800158_fxsparkle, (u32)&D_8080017C_fxsparkle, (u32)&D_808001A0_fxsparkle, (u32)&D_808001CC_fxsparkle, (u32)&D_808001FC_fxsparkle, (u32)&D_80800224_fxsparkle, (u32)&D_80800234_fxsparkle, (u32)&D_80800294_fxsparkle, (u32)&D_808002AC_fxsparkle, (u32)&D_808002C8_fxsparkle, (u32)&D_808002F0_fxsparkle, (u32)&D_80800318_fxsparkle, (u32)&D_80800340_fxsparkle, (u32)&D_808000F8_fxsparkle, (u32)&D_80800368_fxsparkle, (u32)&D_808000F8_fxsparkle, (u32)&D_80800390_fxsparkle };
