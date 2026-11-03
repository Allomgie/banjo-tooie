#include "ch/mineentrygrill.h"

extern s32 D_80800140_chmineentrygrille[];
extern u32 D_80800180_chmineentrygrille[];
extern u32 D_80800194_chmineentrygrille[];

s32 func_80800000_chmineentrygrille(Actor* arg0, s32 arg1, u32 arg2) 
{
    Actor* temp_v0;

    switch (arg1) 
    {
    case 0x7:
        _chexploder_entrypoint_3(arg0, arg0->position, 8);
        //Set Flag True
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        return 1;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_13(temp_v0, 6);
        _chexploder_entrypoint_15(temp_v0, 2, 1.0f);

        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800140_chmineentrygrille);
        func_800C4AF0(arg0->position, &D_80800180_chmineentrygrille); 
        return 1;
    default:
        return 0;
    }
}

void func_808000C4_chmineentrygrille(s32 arg0) 
{
    if (_sujiggy_entrypoint_20(1) != 0)
    {
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        func_800FFAB0(arg0);
        return;
    }
    //Check if the cheat is not active and something about cutscenes
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7B) == 0))
    {
        func_800FFAB0(arg0);
    }
}

void* chmineentrygrille_entrypoint_0(void) {
    return &D_80800194_chmineentrygrille;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mine/entrygrille.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800180_chmineentrygrille -> u32[], D_80800194_chmineentrygrille -> u32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800140_chmineentrygrille[16] = { 0x610001D, 0x9DD002B, 0x2000300, 0x220180, 0x2000480, 0x6000015, 0x26, 0x190000, 0x7002D, 0x320064, 0x20DEA7, 0x71C0000A, -0x63FFE7, -0x63FF9C, 0x4B0064, 0x61A0000 };
u32 D_80800180_chmineentrygrille[5] = { 0x130413, 0xA00E6, 0x166D60, 0x11964, 0x19640000 };
u32 D_80800194_chmineentrygrille[19] = { 0xAC0393, 0x9690001, 0x0, 0x0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x3930000, 0x20C00, 0x0, 0x0, 0x0, (u32)func_808000C4_chmineentrygrille, (u32)func_80107C2C, 0x80002802, (u32)func_80800000_chmineentrygrille, 0x0, 0x0 };
