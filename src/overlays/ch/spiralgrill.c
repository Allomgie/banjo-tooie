#include "common.h"

extern int D_80800180_chspiralgrill;
extern u8 D_808001C8_chspiralgrill[];

int *chspiralgrill_entrypoint_0()
{
    return &D_80800180_chspiralgrill;
}

s32 func_8080000C_chspiralgrill(s32 param_0){
    func_8010A800(param_0, 0);
    func_80109EEC(param_0, 0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spiralgrill/func_8080003C_chspiralgrill.s")
