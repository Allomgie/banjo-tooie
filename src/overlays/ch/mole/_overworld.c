#include "common.h"

typedef union OverworldMoleEvent { s32 local_0; s16 local_1[2]; } OverworldMoleEvent;
extern s32 D_808001E0_chmole_overworld[];
extern u8 D_80800190_chmole_overworld[];
extern void _sumole_entrypoint_4(s32, void *);
extern int D_808001F0_chmole_overworld[];

s32 func_80800000_chmole_overworld(Actor *param_0, s32 param_1, OverworldMoleEvent param_2)
{
    switch (param_1) {
        case 0x2F:
            if (param_2.local_1[1] == 3) {
                func_800D175C(D_808001E0_chmole_overworld[(s32)param_0->unk54], func_800D1A6C(D_808001E0_chmole_overworld[(s32)param_0->unk54]) - func_800D1A04(D_808001E0_chmole_overworld[(s32)param_0->unk54]));
                break;
            }
            return _sumole_entrypoint_3(param_0, param_1, param_2.local_0, D_80800190_chmole_overworld);
        default:
            return _sumole_entrypoint_3(param_0, param_1, param_2.local_0, D_80800190_chmole_overworld);
    }
    return 1;
}

void func_808000F4_chmole_overworld(Actor* arg0) 
{
    _sumole_entrypoint_0(arg0, 0);
    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->unk54 = arg0->unk74_7;
}
void func_80800160_chmole_overworld(s32 param_0) {
    _sumole_entrypoint_4(param_0, ((s32 *) D_80800190_chmole_overworld));
}

int chmole_overworld_entrypoint_0()
{
    return (int)&D_808001F0_chmole_overworld;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mole/_overworld.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808001F0_chmole_overworld -> int[] */
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800190_chmole_overworld[80] = { 0x0, 0x0, 0x0, 0x1, 0xD, 0xB8, 0xD, 0xAB, 0xD, 0xAC, 0x2C, 0xFF, 0x0, 0x2D, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0xD, 0xB9, 0xD, 0xAD, 0xD, 0xAE, 0x2D, 0xFF, 0x0, 0x6E, 0x2, 0x0, 0x0, 0x0, 0x0, 0x1, 0xD, 0xBA, 0xD, 0xAF, 0xD, 0xB0, 0x2E, 0xFF, 0x1, 0x3B, 0x3, 0x0, 0x0, 0x0, 0x0, 0x1, 0xD, 0xBB, 0xD, 0xB1, 0xD, 0xB2, 0x2F, 0xFF, 0x0, 0xC8, 0x4, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0xD, 0x4B, 0x0, 0x0, 0x18, 0xFF, 0x0, 0x55, 0xB, 0x0 };
s32 D_808001E0_chmole_overworld[4] = { 0x41, 0x43, 0x44, 0x42 };
int D_808001F0_chmole_overworld[20] = { 0x2EA0311, 0x1, 0x0, (u32)func_80800160_chmole_overworld, 0x0, (u32)func_8010A730, 0x1F40000, 0x0, 0x0, 0x80004, 0x0, 0x0, 0x0, (u32)func_808000F4_chmole_overworld, (u32)func_80107C2C, -0x7FFFDDFE, (u32)func_80800000_chmole_overworld, 0x0, 0x0, 0x0 };
