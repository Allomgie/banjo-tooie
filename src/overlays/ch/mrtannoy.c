#include "ch/mrtannoy.h"

// Tannoy jingle: plays the sound, then a lower-pitched copy 0.2 s later.
void chmrtannoy_entrypoint_0(void)
{
    func_800C3FC0(0x3E9, 0.75f, 0x7FFF);
    func_800C9BB4(0.2f, 0x3E9, 0.58f, 0x7FFF);
}
// TU-NOTE: the .data of this overlay is defined here in C. Values come from the ROM.
