#include "core1/1E29B60.h"

extern char core1_BSS_START;
extern char core1_BSS_END;
extern void func_80013620(void);
extern s32 D_800459CC;
extern void func_8001A2B0();
extern void func_800A7B24();
extern void func_800155BC();
extern void func_800A7BB8();
extern s32 D_8007E994;
extern u8 core2_DATA_START[];
s32 D_800459D0;
s32 D_800459D4;
u64 D_800459D8;
extern u8 core2_RODATA_END[];
extern s32 D_80043384;
extern f32 func_800D9004(void);
extern u8 D_80045938[];
extern u8 D_80045788[];

int func_80012520();

// core1 entry: clears BSS and creates the idle thread.
void func_80012030(s32 unk_0)
{
    bzero(&core1_BSS_START, &core1_BSS_END - &core1_BSS_START);
    osWritebackDCacheAll();
    osInitialize();
    func_80013620();
}

void func_8001207C(void)
{
    func_800D5E74();
}

// Switches the game mode (1 = in-game).
void func_8001209C(s32 new_mode)
{
    s32 mode;
    // Matching: the double assignment is needed for the match.
    mode = (mode = new_mode);
    func_8001A2B0();
    func_800155BC();
    if (D_80043380 == 1) {
        // Matching: empty block steers IDO's register allocation.
        if (!mode) {
        }
        func_800A7B24();
    }
    func_8001207C();
    D_80043380 = mode;
    if (mode == 1) {
        func_800A7BB8(D_800459CC);
    }
}

// Frame counter masked with `mask`; used as a timer by other TUs.
s32 func_8001210C(s32 mask)
{
    return D_800459C8 & mask;
}

s32 func_8001211C(void)
{
    return D_800459C8;
}

void func_80012128(void)
{
    D_800459C8 = 0;
}

// Starts in-game mode on the intro cutscene map.
int func_80012134()
{
    s32 map;
    map = _cosection_entrypoint_1();
    // Matching: `| 0` is needed for the match.
    func_8001253C(map | 0);
    func_80012520(1);
}

// Starts in-game mode on the Spiral Mountain map.
s32 func_80012164()
{
    s32 map;
    map = _cosection_entrypoint_0();
    // Matching: `| 0` is needed for the match.
    func_8001253C(map | 0);
    func_80012520(1);
}

s32 func_80012194(void)
{
    return D_8007E994 - (s32) core2_VRAM_END;
}

s32 func_800121AC()
{
    return core2_VRAM_END - (s32) &func_80012030 + 0xFFF21DD0;
}

void func_800121D0(void)
{
    s32 size;
    s32 addr;
    size = func_80012194();
    // Matching: `if (1)` wrapper is needed for the match.
    if (1) {
        addr = func_8001E830() + size;
        while (addr & 0xF) {
            addr--;
        }
    }
}

#if 0

#else

// One-time init of all subsystems, then enters the intro cutscene mode.
void func_80012214(void)
{
    D_800459D0 = osGetMemSize();
    func_8001DDF0();
    init_crc_check();
    func_80014FE8();
    func_8001E7E8();
    func_8001C1C0();
    func_80019EC0(0, core2_VRAM, core2_VRAM_END, core2_ROM_START, core2_ROM_END, core2_TEXT_START,
                  core2_TEXT_END, core2_DATA_START, core2_RODATA_END, core2_BSS_START,
                  core2_BSS_END);
    heap_setup(1);
    func_80014E6C();
    D_80043388.unk400 = 0x01020304;
    D_80043388.unk404 = 0x05060708;
    D_800459D8 = 0x0102030405060708ULL;
    func_801168F0();
    func_800815CC();
    func_8001A080();
    func_8001A2D0();
    func_800121D0();
    func_80016734();
    func_800184E8();
    func_800125B0();
    func_8001A3A0();
    func_800D66AC();
    func_800D5D70();
    func_800E692C();
    _gcstatusDll_entrypoint_0();
    func_800C929C();
    D_80043380 = 0;
    D_800459C8 = 0;
    func_800A5BE0();
    func_800D740C();
    func_8001253C(_cosection_entrypoint_1());
    func_8001209C(1);
}

#endif

s32 func_800123B0()
{
    return D_800459D0;
}

s32 func_800123BC(void)
{
    if (func_800A7D84()) {
        func_800A7840(0);
    }
    func_800A5D1C();
}

// One iteration of the main loop.
void func_800123F4(void)
{
    func_8001207C();
    if ((D_80043380 != 1) || (func_800A8184() != 4)) {
        D_800459C8 += 1;
    }
    if (func_80012530() == 1) {
        func_800A7D30();
    }
    func_8001608C();
    func_80018444();
    if (D_80043380 == 1) {
        func_800123BC();
    }
    func_8008160C(1);
    func_8001E010();
    if (func_800D9004() <= 0.05f) {
        do_crc_check();
    }
    if (D_80043384 != 0) {
        func_8001209C(D_80043384 - 1);
        D_80043384 = 0;
    }
}

// Main thread entry.
void func_800124EC(s32 unk_0)
{
    func_80012214();

    while (1) {
        func_800123F4();
    }
}

// Requests a mode switch, applied at the end of the frame.
int func_80012520(mode)
s32 mode;
{
    D_80043384 = mode + 1;
}

int func_80012530()
{
    return D_80043380;
}

// Sets the map to start when entering mode 1.
void func_8001253C(map) s32 map;
{
    D_800459CC = map;
}

// Creates the main game thread.
void func_80012548()
{
    func_8001DD28(&D_80045788, &D_80045938, 6, &func_800124EC, 0, (u8 *) D_80045938 - 0x1B0, 0x14);
}

int *func_80012598()
{
    return (int *) D_80045788;
}

// TU-NOTE: this .data table is defined here (not in asm) because it points at functions of this
// file, and IDO's assembler only schedules them as in the original when the table is in the same unit.
extern void rom_read_word();
extern void func_8001EB10();
u32 D_8003C9D0[28] = {0x9,
                      0x4,
                      0xA,
                      0x3,
                      0xB,
                      0x2,
                      0xC,
                      0x5,
                      0x0,
                      0x1,
                      0x6,
                      0xD,
                      0xFFFFFFFF,
                      0x486A756E,
                      0x6B446972,
                      0x653A3636,
                      0x37383132,
                      0x0,
                      (u32) rom_read_word,
                      (u32) sprintf,
                      (u32) sqrtf,
                      (u32) func_8001EB10,
                      (u32) guOrtho,
                      (u32) osEepromLongRead,
                      (u32) osEepromLongWrite,
                      0x0,
                      0x0,
                      0x0};
