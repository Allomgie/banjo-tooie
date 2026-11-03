#include "buffers.h"

extern u8 core2_compressed_ROM_END[];
extern u8 core2_compressed_ROM_START[];

// Seeds entry 0 of the overlay ROM table with the compressed ROM range of core2.
void func_80000670(void)
{
    D_80012010[0].rom_start = core2_compressed_ROM_START;
    D_80012010[0].rom_end = core2_compressed_ROM_END;
}
