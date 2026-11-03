#include "ch/mole.h"

extern MoveData D_808000C0_chmole_cuckoo[];
extern D_808000D0 D_808000D0_chmole_cuckoo[];

void func_80800000_chmole_cuckoo(Actor* a0, u32 a1,u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808000C0_chmole_cuckoo);
}

void func_80800024_chmole_cuckoo(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_cuckoo(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808000C0_chmole_cuckoo);
}

void* chmole_cuckoo_entrypoint_0()
{
	return D_808000D0_chmole_cuckoo;
}


/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mole/_cuckoo.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000D0_chmole_cuckoo -> D_808000D0[] (uses written as NAME[0]) */
extern void func_8010A730();
extern void func_80107C2C();
MoveData D_808000C0_chmole_cuckoo[1] = { 0x200, 0xDB5, 0xDB3, 0xDB4, 0x2A, 0xFF, 0x2FD, 0x19, 0x0 };
D_808000D0 D_808000D0_chmole_cuckoo[1] = { 0x2EA0376, 0x1, 0x0, (void *)func_80800090_chmole_cuckoo, 0x0, (void *)func_8010A730, 0x1F40000, 0x0, 0x0, 0x80004, 0x0, 0x0, 0x0, (void *)func_80800024_chmole_cuckoo, (void *)func_80107C2C, 0x80002202, (u32)func_80800000_chmole_cuckoo, 0x0, 0x0 };
static u32 D_808000D0_chmole_cuckoo_rest[1] = { 0x0 };
