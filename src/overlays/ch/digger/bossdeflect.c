#include "common.h"

extern int D_80800040_chdiggerbossdeflect[];

int *chdiggerbossdeflect_entrypoint_0()
{
    return &D_80800040_chdiggerbossdeflect;
}

func_8080000C_chdiggerbossdeflect(param_0){
    s16 local_0 = 0x1F4;
    (*(s16 *)((char *)(param_0) + 0x62)) = local_0;
    (*(s16 *)((char *)(param_0) + 0x6A)) = local_0;
    (*(s16 *)((char *)(param_0) + 0x68)) = local_0;
}

void func_80800020_chdiggerbossdeflect(s32 arg0) 
{
}
s32 func_80800028_chdiggerbossdeflect(s32 param_0, s32 param_1, s32 param_2){
    s32 out;
    out = 0;
    return out;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/digger/bossdeflect.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800040_chdiggerbossdeflect -> int[] */
extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
int D_80800040_chdiggerbossdeflect[20] = { 0x15804FF, 0x1, 0x0, (u32)func_80800020_chdiggerbossdeflect, (u32)func_80102EC0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, (u32)func_8080000C_chdiggerbossdeflect, (u32)func_80107C2C, -0x7FFFE7FA, (u32)func_80800028_chdiggerbossdeflect, 0x0, 0x0, 0x0 };
