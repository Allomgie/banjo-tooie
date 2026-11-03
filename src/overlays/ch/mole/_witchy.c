#include "ch/mole.h"

extern MoveData D_808000C0_chmole_witchy[];
extern D_808000D0 D_808000F0_chmole_witchy[];

void func_80800000_chmole_witchy(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_witchy);
}

void func_80800024_chmole_witchy(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_witchy(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_witchy);
}

void* chmole_witchy_entrypoint_0()
{
	return D_808000F0_chmole_witchy;
}


/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mole/_witchy.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000F0_chmole_witchy -> D_808000D0[] (uses written as NAME[0]) */
extern void func_8010A730();
extern void func_80107C2C();
MoveData D_808000C0_chmole_witchy[3] = { 0x1, 0xD63, 0xD64, 0xD65, 0x1B, 0xFF, 0xB4, 0x5, 0x0, 0x1, 0xD66, 0xD67, 0xD68, 0x1C, 0xFF, 0xA0, 0x6, 0x0, 0x200, 0xD69, 0xD6A, 0xD6B, 0x29, 0xFF, 0xAA, 0x7, 0x0 };
D_808000D0 D_808000F0_chmole_witchy[1] = { 0x2EA0182, 0x1, 0x0, (void *)func_80800090_chmole_witchy, 0x0, (void *)func_8010A730, 0x1F40000, 0x0, 0x0, 0x80004, 0x0, 0x0, 0x0, (void *)func_80800024_chmole_witchy, (void *)func_80107C2C, 0x80002202, (u32)func_80800000_chmole_witchy, 0x0, 0x0 };
static u32 D_808000F0_chmole_witchy_rest[1] = { 0x0 };
