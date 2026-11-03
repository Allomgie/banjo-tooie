#include "buffers.h"

void rom_dma_read(u8 *, u8 *, u32);
u8 *func_8001A0A8();
void func_8001A2B0();
void func_8001C1E0(u8 **, u8 **);
s32 func_8001C26C();
s32 func_8001C28C();
extern u8 *D_8007E994;

void func_80019EC0(s32 overlay_index, u8 *ovl_start, u8 *ovl_end, u8 *ovl_rom_start,
                   u8 *ovl_rom_end, u8 *ovl_text_start, u8 *ovl_text_end, u8 *ovl_rodata_start,
                   u8 *ovl_data_end, u8 *ovl_bss_start, u8 *ovl_bss_end)
{
    u8 *compressed_data;
    s32 crc2;
    s32 crc1;
    s32 *ovl_bss;

    osWritebackDCacheAll();
    osInvalDCache(ovl_start, ovl_end - ovl_start);
    osInvalICache(ovl_start, ovl_end - ovl_start);
    if (ovl_bss_start != NULL) {
        osInvalDCache(ovl_bss_start, ovl_bss_end - (u8 *) ovl_bss_start);
    }

    ovl_rom_start = D_80012010[overlay_index].rom_start;
    ovl_rom_end = D_80012010[overlay_index].rom_end;

    if (overlay_index != 0) {
        func_8001A2B0();
        compressed_data = func_8001A0A8();
    } else {
        compressed_data = D_8007E994;
    }

    rom_dma_read(compressed_data, ovl_rom_start, ovl_rom_end - ovl_rom_start);

    func_8001C1E0(&compressed_data, &ovl_start);

    crc1 = func_8001C26C();
    crc2 = func_8001C28C();

    func_8001C1E0(&compressed_data, &ovl_start);

    if (ovl_bss_start != NULL) {
        bzero(ovl_bss_start, ovl_bss_end - ovl_bss_start);
        osWritebackDCacheAll();
        ovl_bss = (s32 *) ovl_bss_start;
        *ovl_bss++ = crc1;
        *ovl_bss++ = crc2;
        ovl_bss_start += 2;
        *ovl_bss++ = func_8001C26C();
        *ovl_bss++ = func_8001C28C();
    }
}
