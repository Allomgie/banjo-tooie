// World-opening progression and Jiggywiggy challenge glue: world table (jiggy cost, puzzle,
// time limit, cutscene), opened-world count, entrance check, challenge start/retry/finish.
#include "su/jiggy.h"

extern JiggyData D_808008E0_sujiggy[11];

// World table, opened-world count, jiggies needed, entrance check and opening cutscene.
// Reads one or two packed 16-bit values from ROM and sums them, plus 0xA0.
s32 func_80800000_sujiggy(s32 packed)
{
    u32 word;
    u32 lo_addr;
    u32 hi_addr;

    lo_addr = (packed & 0xFFFF) + 0xB0000000;
    hi_addr = ((packed & 0xFFFF0000) >> 0x10);
    if (lo_addr & 2) {
        lo_addr = (lo_addr >> 2) << 2;
        rom_read_word(lo_addr, &word);
        packed = (word & 0xFFFF0000) >> 0x10;
    } else {
        rom_read_word(lo_addr, &word);
        packed = word & 0xFFFF;
    }

    if (hi_addr != 0) {
        hi_addr += 0xB0000000;
        if (hi_addr & 2) {
            hi_addr = (hi_addr >> 2) << 2;
            rom_read_word(hi_addr, &word);
            packed += (word & 0xFFFF0000) >> 0x10;
        } else {
            rom_read_word(hi_addr, &word);
            packed += word & 0xFFFF;
        }
    }
    return packed + 0xA0;
}

// Number of opened worlds (flag 0x35C, 4 bits).
s32 sujiggy_entrypoint_0()
{
    return func_800DA564(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, 4);
}

// Number of entries in the world table.
s32 sujiggy_entrypoint_1()
{
    return 0xB;
}

// Jiggy cost of a world.
u8 sujiggy_entrypoint_2(s32 world)
{
    return D_808008E0_sujiggy[world].WorldCost;
}

// Challenge start/retry/finish, attempts, time limit and best-time record.
f32 sujiggy_entrypoint_3(s32 world)
{
    return (f32) (_glreflight_entrypoint_0() & D_808008E0_sujiggy[world].unk9 & 0x7F);
}

s32 sujiggy_entrypoint_4(s32 world)
{
    return func_80800000_sujiggy(D_808008E0_sujiggy[world].unk4);
}

s32 sujiggy_entrypoint_5(s32 world)
{
    return D_808008E0_sujiggy[world].unk8;
}

u8 sujiggy_entrypoint_6(s32 world)
{
    return D_808008E0_sujiggy[world].unk11;
}

u8 sujiggy_entrypoint_7(s32 world)
{
    return D_808008E0_sujiggy[world].unk12;
}

// Start the Jiggywiggy challenge: copy flags to temporaries and start the special sequence.
void sujiggy_entrypoint_8(void)
{
    s32 opened;
    // Matching: unused local needed for the match.
    s32 unk_0;
    s32 picture;

    opened = sujiggy_entrypoint_0();
    if (func_800DA298(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen) == 0) {
        func_800DA7A8(GFLAG_C0D_UNK, 0, 8);
        func_800DA7A8(FLAG5_D57_UNK, 0, 4);
    }
    func_800DA524(FLAG5_D4D_UNK);
    func_800DA544(FLAG5_D4E_UNK);
    if (opened >= 0xA) {
        func_800DA3B8(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE,
                      func_800DA298(FLAG_589_ATTEMPTED_JIGGYWIGGY_SPECIAL_PUZZLE));
    } else {
        func_800DA3B8(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE,
                      func_800DA298(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen));
    }
    func_800DA3B8(FLAG5_D74_UNK, func_800DA298(FLAG_57B_UNK));
    func_800DA7A8(FLAG5_D50_UNK, opened, 4);
    func_800DA524(FLAG5_D73_UNK);
    func_800FE844(2);
    func_800FE734(1);
    func_800FC6B0(0x2E);
    func_800A9B84();
    func_800A9B8C(0x151, 3);
    picture = sujiggy_entrypoint_4(opened);
    func_800A9BA0(1, picture, sujiggy_entrypoint_5(opened));
}

void sujiggy_entrypoint_9()
{
    func_800DA544(FLAG5_D4D_UNK);
}

void sujiggy_entrypoint_10(void)
{
    func_800FE844(2U);
    func_800FE734(1U);
    func_800DA544(FLAG5_D4F_UNK);
    if (func_800DA298(FLAG5_D4D_UNK) != 0) {
        func_800DA7A8(FLAG5_D57_UNK, 0, 4);
    } else {
        func_800DA7A8(FLAG5_D57_UNK, sujiggy_entrypoint_19() + 1, 4);
    }
    func_800A9C50();
}

// Retry the challenge for the given world.
void sujiggy_entrypoint_11(s32 world)
{
    func_800FC6B0(0x2EU);
    func_800FE844(2U);
    func_800FE734(1U);
    func_800DA7A8(FLAG5_D57_UNK, sujiggy_entrypoint_19() + 1, 4);
    func_800A9BA0(1, sujiggy_entrypoint_4(world), sujiggy_entrypoint_5(world));
}

s32 sujiggy_entrypoint_12(void)
{
    return func_800DA564(FLAG5_D50_UNK, 4);
}

s32 sujiggy_entrypoint_13()
{
    return func_800DA298(FLAG5_D4F_UNK);
}

// Finish the challenge: write the temporary flags back and record the best time.
s32 sujiggy_entrypoint_14(void)
{
    s32 result;

    if (sujiggy_entrypoint_21() != 0) {
        if (func_800DA298(FLAG5_D4D_UNK) != 0) {
            result = 2;
        } else {
            result = 3;
        }
    } else if (func_800DA298(FLAG5_D4D_UNK) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    func_800DA7A8(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, func_800DA564(FLAG5_D50_UNK, 4), 4);
    if (sujiggy_entrypoint_21() != 0) {
        func_800DA3B8(FLAG_589_ATTEMPTED_JIGGYWIGGY_SPECIAL_PUZZLE,
                      func_800DA298(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE));
    } else {
        func_800DA3B8(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen,
                      func_800DA298(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE));
    }
    func_800DA3B8(FLAG_57B_UNK, func_800DA298(FLAG5_D74_UNK));
    if (result == 1) {
        func_800DA944(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, 4);
    }
    func_800DA524(FLAG5_D4F_UNK);
    func_800DA524(FLAG5_D4E_UNK);
    if (func_800DA298(FLAG5_D73_UNK) != 0) {
        func_800D2054(1, 0x96, sujiggy_entrypoint_24());
        func_800DA524(FLAG5_D73_UNK);
    }
    return result;
}

// Play the opening cutscene of a world.
void sujiggy_entrypoint_15(s32 world, s32 arg1)
{
    if (func_800DA298(FLAG_58A_UNK) != 0) {
        _glcutDll_entrypoint_6(func_80800000_sujiggy(D_808008E0_sujiggy[world].unkC), world + 0x7A);
        return;
    }
    if (arg1 != 0) {
        _glcutDll_entrypoint_6(0x14FU, 0x67U);
        return;
    }
    func_800DA544(FLAG_58A_UNK);
    _glcutDll_entrypoint_24(func_80800000_sujiggy(D_808008E0_sujiggy[world].unkC), 0x151,
                            world + 0x7A);
}

// Jiggies still needed to open the next world.
s32 sujiggy_entrypoint_16(void)
{
    s32 opened;
    s32 missing;
    s32 needed;

    opened = sujiggy_entrypoint_0();
    if (sujiggy_entrypoint_1() == opened) {
        return 0;
    }
    needed = sujiggy_entrypoint_2(opened);
    missing = needed - func_800D035C(1);
    if (missing > 0) {
        needed = missing;
    } else {
        needed = 0;
    }
    return needed;
}

// Whether there are enough jiggies for the next world (-1 when all are open).
s32 sujiggy_entrypoint_17(void)
{
    s32 opened;
    // Matching: unused local needed for the match.
    s32 unk_0;
    s32 jiggies;
    s32 enough;

    opened = sujiggy_entrypoint_0();
    if (sujiggy_entrypoint_1() == opened) {
        return -1;
    }
    jiggies = func_800D035C(1);
    if (jiggies >= sujiggy_entrypoint_2(opened)) {
        enough = 1;
    } else {
        enough = 0;
    }
    return enough;
}

s32 sujiggy_entrypoint_18(void)
{
    // Matching: the ^ 1 is needed for the match.
    return (sujiggy_entrypoint_19() < 3) ^ 1;
}

s32 sujiggy_entrypoint_19(void)
{
    return func_800DA564(FLAG5_D57_UNK, 4);
}

// Whether the entrance of a world may open.
int sujiggy_entrypoint_20(s32 world)
{
    return (_glcutDll_entrypoint_19(world + 0x7A) == 0) && (world < sujiggy_entrypoint_0()) &&
           func_800DA298(world + 0x392) == 0;
}

s32 sujiggy_entrypoint_21(void)
{
    s32 worlds;
    if (func_800DA298(FLAG5_D4E_UNK) != 0) {
        worlds = func_800DA564(FLAG5_D50_UNK, 4);
    } else {
        worlds = sujiggy_entrypoint_0();
    }
    return worlds >= 10;
}

u8 sujiggy_entrypoint_22(s32 world)
{
    return D_808008E0_sujiggy[world].unk13;
}

u16 sujiggy_entrypoint_23(s32 world)
{
    return D_808008E0_sujiggy[world].unk14;
}

// Best time of the challenge (global flag 0xC0D, 8 bits).
s32 sujiggy_entrypoint_24(void)
{
    return func_800DA564(GFLAG_C0D_UNK, 8);
}

// Store a new best time; returns 2 for a new best, 1 for a tie, 0 otherwise.
s32 sujiggy_entrypoint_25(s32 time)
{
    s32 best;

    best = sujiggy_entrypoint_24();
    if (time == 0) {
        return 0;
    }
    if ((best == 0) || (time < best)) {
        func_800DA7A8(GFLAG_C0D_UNK, time, 8);
        return 2;
    }
    if (best == time) {
        return 1;
    }
    return 0;
}

// TU-NOTE: the .data of this overlay is defined here in C (values from the ROM). Linker symbols
// D_808008E4/E8/E9/EC/F1/F2/F3/F4_sujiggy are offsets +0x4/0x8/0x9/0xC/0x11/0x12/0x13/0x14 into
// D_808008E0_sujiggy.

JiggyData D_808008E0_sujiggy[11] = {0x1,  0x0,       0x0,  0x0, 0x9400CC0, 0x1, 0x64,  0x0,
                                    0x0,  0x5400B74, 0x7A, 0xF, 0x0,       0x0, 0x391, 0x0,
                                    0x4,  0x0,       0x0,  0x0, 0x954,     0x1, 0x64,  0x0,
                                    0x0,  0x5400290, 0x7B, 0xD, 0x0,       0x0, 0x393, 0x0,
                                    0x8,  0x0,       0x0,  0x0, 0xB20,     0x1, 0x64,  0x0,
                                    0x0,  0x6E40A68, 0x7C, 0xB, 0x0,       0x0, 0x489, 0x0,
                                    0xE,  0x0,       0x0,  0x0, 0x96C,     0x1, 0x64,  0x0,
                                    0x0,  0x5400C68, 0x7D, 0x9, 0x0,       0x0, 0x392, 0x0,
                                    0x14, 0x0,       0x0,  0x0, 0xDAE0CC8, 0x1, 0x64,  0x0,
                                    0x0,  0x5400CC8, 0x7E, 0x7, 0x0,       0x0, 0x396, 0x0,
                                    0x1C, 0x0,       0x0,  0x0, 0xDAE,     0x1, 0x64,  0x0,
                                    0x0,  0x5400004, 0x7F, 0x5, 0x0,       0x0, 0x4DB, 0x0,
                                    0x24, 0x0,       0x0,  0x0, 0xAF60CC0, 0x1, 0x64,  0x0,
                                    0x0,  0x5400C68, 0x80, 0x4, 0x0,       0x1, 0x394, 0x0,
                                    0x2D, 0x0,       0x0,  0x0, 0x9E60004, 0x1, 0x64,  0x0,
                                    0x0,  0x5400CC8, 0x81, 0x3, 0x0,       0x1, 0x412, 0x0,
                                    0x37, 0x0,       0x0,  0x0, 0x5400B98, 0x1, 0x64,  0x0,
                                    0x0,  0x5400004, 0x82, 0x2, 0x0,       0x1, 0x48D, 0x0,
                                    0x46, 0x0,       0x0,  0x0, 0x5400480, 0x1, 0x64,  0x0,
                                    0x0,  0x5400B98, 0x83, 0x0, 0x0,       0x0, 0x48D, 0x0,
                                    0x0,  0x0,       0x0,  0x0, 0x5400B80, 0x1, 0x64,  0x0,
                                    0x0,  0x0,       0x0,  0x0, 0xF,       0x0, 0x0,   0x0};
