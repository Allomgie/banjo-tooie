#include "su/jiggy.h"

extern JiggyData D_808008E0_sujiggy[11];


s32 func_80800000_sujiggy(s32 arg0)
{
    u32 sp2C;
    u32 temp_a2;
    u32 temp_t6;

    temp_a2 = (arg0 & 0xFFFF) + 0xB0000000;
    temp_t6 = ((arg0 & 0xFFFF0000) >> 0x10);
    if (temp_a2 & 2)
    {
        temp_a2 = (temp_a2 >> 2) << 2;
        rom_read_word(temp_a2, &sp2C);
        arg0 = (sp2C & 0xFFFF0000) >> 0x10;
    }
    else
    {
        rom_read_word(temp_a2, &sp2C);
        arg0 = sp2C & 0xFFFF;
    }

    if (temp_t6 != 0)
    {
        temp_t6 += 0xB0000000;
        if (temp_t6 & 2)
        {
            temp_t6 = (temp_t6 >> 2) << 2;
            rom_read_word(temp_t6, &sp2C);
            arg0 += (sp2C & 0xFFFF0000) >> 0x10;
        }
        else
        {
            rom_read_word(temp_t6, &sp2C);
            arg0 += sp2C & 0xFFFF;
        }
    }
    return arg0 + 0xA0;
}

s32 sujiggy_entrypoint_0()
{
    return func_800DA564(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, 4);
}

s32 sujiggy_entrypoint_1() 
{
    return 0xB;
}

u8 sujiggy_entrypoint_2(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].WorldCost;
}

f32 sujiggy_entrypoint_3(s32 arg0)
{
    return (f32)(_glreflight_entrypoint_0() & D_808008E0_sujiggy[arg0].unk9 & 0x7F);
}

s32 sujiggy_entrypoint_4(s32 arg0)
{
    return func_80800000_sujiggy(D_808008E0_sujiggy[arg0].unk4);
}

s32 sujiggy_entrypoint_5(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk8;
}

u8 sujiggy_entrypoint_6(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk11;
}

u8 sujiggy_entrypoint_7(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk12;
}

void sujiggy_entrypoint_8(void)
{
    s32 sp24;
    s32 s20;
    s32 sp1C;

    sp24 = sujiggy_entrypoint_0();
    if (func_800DA298(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen) == 0)
    {
        func_800DA7A8(GFLAG_C0D_UNK, 0, 8);
        func_800DA7A8(FLAG5_D57_UNK, 0, 4);
    }
    func_800DA524(FLAG5_D4D_UNK);
    func_800DA544(FLAG5_D4E_UNK);
    if (sp24 >= 0xA)
    {
        func_800DA3B8(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE, func_800DA298(FLAG_589_ATTEMPTED_JIGGYWIGGY_SPECIAL_PUZZLE));
    }
    else
    {
        func_800DA3B8(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE, func_800DA298(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen));
    }
    func_800DA3B8(FLAG5_D74_UNK, func_800DA298(FLAG_57B_UNK));
    func_800DA7A8(FLAG5_D50_UNK, sp24, 4);
    func_800DA524(FLAG5_D73_UNK);
    func_800FE844(2);
    func_800FE734(1);
    func_800FC6B0(0x2E);
    func_800A9B84();
    func_800A9B8C(0x151, 3);
    sp1C = sujiggy_entrypoint_4(sp24);
    func_800A9BA0(1, sp1C, sujiggy_entrypoint_5(sp24));
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
    if (func_800DA298(FLAG5_D4D_UNK) != 0)
    {
        func_800DA7A8(FLAG5_D57_UNK, 0, 4);
    }
    else
    {
        func_800DA7A8(FLAG5_D57_UNK, sujiggy_entrypoint_19() + 1, 4);
    }
    func_800A9C50();
}

void sujiggy_entrypoint_11(s32 arg0)
{
    func_800FC6B0(0x2EU);
    func_800FE844(2U);
    func_800FE734(1U);
    func_800DA7A8(FLAG5_D57_UNK, sujiggy_entrypoint_19() + 1, 4);
    func_800A9BA0(1, sujiggy_entrypoint_4(arg0), sujiggy_entrypoint_5(arg0));
}

s32 sujiggy_entrypoint_12(void)
{
    return func_800DA564(FLAG5_D50_UNK, 4);
}

s32 sujiggy_entrypoint_13()
{
    return func_800DA298(FLAG5_D4F_UNK);
}

s32 sujiggy_entrypoint_14(void)
{
    s32 sp1C;

    if (sujiggy_entrypoint_21() != 0)
    {
        if (func_800DA298(FLAG5_D4D_UNK) != 0)
        {
            sp1C = 2;
        }
        else
        {
            sp1C = 3;
        }
    }
    else if (func_800DA298(FLAG5_D4D_UNK) != 0)
    {
        sp1C = 1;
    }
    else
    {
        sp1C = 0;
    }
    func_800DA7A8(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, func_800DA564(FLAG5_D50_UNK, 4), 4);
    if (sujiggy_entrypoint_21() != 0)
    {
        func_800DA3B8(FLAG_589_ATTEMPTED_JIGGYWIGGY_SPECIAL_PUZZLE, func_800DA298(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE));
    }
    else
    {
        func_800DA3B8(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen, func_800DA298(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE));
    }
    func_800DA3B8(FLAG_57B_UNK, func_800DA298(FLAG5_D74_UNK));
    if (sp1C == 1)
    {
        func_800DA944(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, 4);
    }
    func_800DA524(FLAG5_D4F_UNK);
    func_800DA524(FLAG5_D4E_UNK);
    if (func_800DA298(FLAG5_D73_UNK) != 0)
    {
        func_800D2054(1, 0x96, sujiggy_entrypoint_24());
        func_800DA524(FLAG5_D73_UNK);
    }
    return sp1C;
}

void sujiggy_entrypoint_15(s32 arg0, s32 arg1)
{
    if (func_800DA298(FLAG_58A_UNK) != 0)
    {
        _glcutDll_entrypoint_6(func_80800000_sujiggy(D_808008E0_sujiggy[arg0].unkC), arg0 + 0x7A);
        return;
    }
    if (arg1 != 0)
    {
        _glcutDll_entrypoint_6(0x14FU, 0x67U);
        return;
    }
    func_800DA544(FLAG_58A_UNK);
    _glcutDll_entrypoint_24(func_80800000_sujiggy(D_808008E0_sujiggy[arg0].unkC), 0x151, arg0 + 0x7A);
}

s32 sujiggy_entrypoint_16(void)
{
    s32 sp24;
    s32 temp_v1;
    s32 sp1C;
    s32 a1;

    sp24 = sujiggy_entrypoint_0();
    if (sujiggy_entrypoint_1() == sp24)
    {
        return 0;
    }
    sp1C = sujiggy_entrypoint_2(sp24);
    temp_v1 = sp1C - func_800D035C(1);
    if (temp_v1 > 0)
    {
        sp1C = temp_v1;
    }
    else
    {
        sp1C = 0;
    }
    return sp1C;
}

s32 sujiggy_entrypoint_17(void)
{
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 var_v1;

    sp24 = sujiggy_entrypoint_0();
    if (sujiggy_entrypoint_1() == sp24)
    {
        return -1;
    }
    sp1C = func_800D035C(1);
    if (sp1C >= sujiggy_entrypoint_2(sp24))
    {
        var_v1 = 1;
    }
    else
    {
        var_v1 = 0;
    }
    return var_v1;
}

s32 sujiggy_entrypoint_18(void)
{
    return (sujiggy_entrypoint_19() < 3) ^ 1;
}

s32 sujiggy_entrypoint_19(void)
{
    return func_800DA564(FLAG5_D57_UNK, 4);
}

int sujiggy_entrypoint_20(s32 arg0)
{
    return (_glcutDll_entrypoint_19(arg0 + 0x7A) == 0) && (arg0 < sujiggy_entrypoint_0()) && func_800DA298(arg0 + 0x392) == 0;
}

s32 sujiggy_entrypoint_21(void)
{
    s32 var_v0;
    if (func_800DA298(FLAG5_D4E_UNK) != 0)
    {
        var_v0 = func_800DA564(FLAG5_D50_UNK, 4);
    }
    else
    {
        var_v0 = sujiggy_entrypoint_0();
    }
    return var_v0 >= 10;
}

u8 sujiggy_entrypoint_22(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk13;
}

u16 sujiggy_entrypoint_23(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk14;
}

s32 sujiggy_entrypoint_24(void)
{
    return func_800DA564(GFLAG_C0D_UNK, 8);
}

s32 sujiggy_entrypoint_25(s32 arg0)
{
    s32 temp_v0;

    temp_v0 = sujiggy_entrypoint_24();
    if (arg0 == 0)
    {
        return 0;
    }
    if ((temp_v0 == 0) || (arg0 < temp_v0))
    {
        func_800DA7A8(GFLAG_C0D_UNK, arg0, 8);
        return 2;
    }
    if (temp_v0 == arg0)
    {
        return 1;
    }
    return 0;
}
/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/jiggy.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_808008E9_sujiggy = D_808008E0_sujiggy + 0x9, D_808008F1_sujiggy = D_808008E0_sujiggy + 0x11, D_808008F2_sujiggy = D_808008E0_sujiggy + 0x12, D_808008F3_sujiggy = D_808008E0_sujiggy + 0x13, D_808008E4_sujiggy = D_808008E0_sujiggy + 0x4, D_808008E8_sujiggy = D_808008E0_sujiggy + 0x8, D_808008EC_sujiggy = D_808008E0_sujiggy + 0xC, D_808008F4_sujiggy = D_808008E0_sujiggy + 0x14 */
JiggyData D_808008E0_sujiggy[11] = { 0x1, 0x0, 0x0, 0x0, 0x9400CC0, 0x1, 0x64, 0x0, 0x0, 0x5400B74, 0x7A, 0xF, 0x0, 0x0, 0x391, 0x0, 0x4, 0x0, 0x0, 0x0, 0x954, 0x1, 0x64, 0x0, 0x0, 0x5400290, 0x7B, 0xD, 0x0, 0x0, 0x393, 0x0, 0x8, 0x0, 0x0, 0x0, 0xB20, 0x1, 0x64, 0x0, 0x0, 0x6E40A68, 0x7C, 0xB, 0x0, 0x0, 0x489, 0x0, 0xE, 0x0, 0x0, 0x0, 0x96C, 0x1, 0x64, 0x0, 0x0, 0x5400C68, 0x7D, 0x9, 0x0, 0x0, 0x392, 0x0, 0x14, 0x0, 0x0, 0x0, 0xDAE0CC8, 0x1, 0x64, 0x0, 0x0, 0x5400CC8, 0x7E, 0x7, 0x0, 0x0, 0x396, 0x0, 0x1C, 0x0, 0x0, 0x0, 0xDAE, 0x1, 0x64, 0x0, 0x0, 0x5400004, 0x7F, 0x5, 0x0, 0x0, 0x4DB, 0x0, 0x24, 0x0, 0x0, 0x0, 0xAF60CC0, 0x1, 0x64, 0x0, 0x0, 0x5400C68, 0x80, 0x4, 0x0, 0x1, 0x394, 0x0, 0x2D, 0x0, 0x0, 0x0, 0x9E60004, 0x1, 0x64, 0x0, 0x0, 0x5400CC8, 0x81, 0x3, 0x0, 0x1, 0x412, 0x0, 0x37, 0x0, 0x0, 0x0, 0x5400B98, 0x1, 0x64, 0x0, 0x0, 0x5400004, 0x82, 0x2, 0x0, 0x1, 0x48D, 0x0, 0x46, 0x0, 0x0, 0x0, 0x5400480, 0x1, 0x64, 0x0, 0x0, 0x5400B98, 0x83, 0x0, 0x0, 0x0, 0x48D, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5400B80, 0x1, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0xF, 0x0, 0x0, 0x0 };
static u32 D_808008E0_sujiggy_rest[2] = { 0x0, 0x0 };
