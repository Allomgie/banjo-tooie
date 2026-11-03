#include "common.h"

extern s32 D_8007DB54;

s32 glreflight_entrypoint_0(void)
{
    return D_8007DB54 ^ 0xACC903EE;
}
/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gl/reflight.data.s) is defined here in C.
 * Values are taken from the ROM. */
