// Loader for the non-relocatable core2 overlay: DMAs the compressed image, inflates text and
// data with rarezip, clears bss and stores the CRC words of the decompressed parts in its bss.
#include "buffers.h"

void rom_dma_read(u8 *, u8 *, u32);
u8 *func_8001A0A8();
void func_8001A2B0();
void func_8001C1E0(u8 **, u8 **);
s32 func_8001C26C();
s32 func_8001C28C();
extern u8 *D_8007E994;

// Loads a non-relocatable overlay (core2): DMAs the compressed image, inflates .text and
// .data/.rodata, zeroes .bss and stores the CRC words at the start of .bss.
void func_80019EC0(s32 overlay_index, u8 *ovl_start, u8 *ovl_end, u8 *ovl_rom_start,
                   u8 *ovl_rom_end, u8 *ovl_text_start, u8 *ovl_text_end, u8 *ovl_rodata_start,
                   u8 *ovl_data_end, u8 *ovl_bss_start, u8 *ovl_bss_end)
{
    u8 *compressed_data;
    s32 crc2;
    s32 crc1;
    s32 *ovl_bss;

    // Sync the CPU cache and RDRAM before loading the overlay.
    osWritebackDCacheAll();
    osInvalDCache(ovl_start, ovl_end - ovl_start);
    osInvalICache(ovl_start, ovl_end - ovl_start);
    if (ovl_bss_start != NULL) {
        osInvalDCache(ovl_bss_start, ovl_bss_end - (u8 *) ovl_bss_start);
    }

    // Compressed ROM range of the overlay.
    ovl_rom_start = D_80012010[overlay_index].rom_start;
    ovl_rom_end = D_80012010[overlay_index].rom_end;

    // Buffer for the compressed data: the z-buffer (after the RCP is idle), or the heap end for index 0.
    if (overlay_index != 0) {
        func_8001A2B0();
        compressed_data = func_8001A0A8();
    } else {
        compressed_data = D_8007E994;
    }

    rom_dma_read(compressed_data, ovl_rom_start, ovl_rom_end - ovl_rom_start);

    // Inflate .text and get its checksums.
    func_8001C1E0(&compressed_data, &ovl_start);

    crc1 = func_8001C26C();
    crc2 = func_8001C28C();

    // Inflate .data/.rodata.
    func_8001C1E0(&compressed_data, &ovl_start);

    if (ovl_bss_start != NULL) {
        bzero(ovl_bss_start, ovl_bss_end - ovl_bss_start);
        osWritebackDCacheAll();
        ovl_bss = (s32 *) ovl_bss_start;
        *ovl_bss++ = crc1;
        *ovl_bss++ = crc2;
        // Matching: this dead increment is needed for the match.
        ovl_bss_start += 2;
        *ovl_bss++ = func_8001C26C();
        *ovl_bss++ = func_8001C28C();
    }
}
