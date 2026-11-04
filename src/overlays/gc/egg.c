// Probably the egg type table: 14-byte records per egg kind (item, actor, model, ability, flags)
// with lookups by actor or projectile id, field getters and an "egg unlocked" check.
#include "common.h"

extern u8 D_80800200_gcegg[];
extern u8 D_8080020C_gcegg[];
extern int D_80800202_gcegg[];
extern int D_80800206_gcegg[];
extern u8 D_80800209_gcegg[][14];
extern u8 D_8080020A_gcegg[][14];
extern u8 D_8080020B_gcegg[];

// Searches the 14-byte egg records, unrolled by 4.
// Matching: the line breaks in this function are needed for the match.
u8 gcegg_entrypoint_0(s32 id)
{
    int field_offset;
    u8 *rec;
    u8 *end;
    field_offset = 0x32; rec = D_80800200_gcegg; loop_1: if (id == *(s16 *) (rec + 0)) {
        return rec[8];
    }

    if (id == *(s16 *) (rec + 0xE))
    {
        return rec[0x16];
    }
    if (id == *(s16 *) (rec + 0x1C))
    {
        return rec[0x24];
    }
    if (id == *(s16 *) (rec + 0x2A))
    {
        return rec[field_offset];
    }
    end = D_8080020C_gcegg + 0x64;
    rec += 0x38;
    if (rec == end)
    {
        return 0U;
    }
    goto loop_1;
}

// Searches the 14-byte egg records, unrolled by 4.
// Matching: the line breaks in this function are needed for the match.
u8 gcegg_entrypoint_1(s32 id)
{
    u8 *rec;
    u8 *rec_copy;
    s16 *id_ptr;
    rec = &D_80800200_gcegg; loop_1: if (id == *(s16 *) (rec + 4)) { return *(rec + 8); }
    if (id == *(s16 *) (rec + 0x12))
    {
        return *(rec + 0x16);
    }
    id_ptr = (s16 *) (rec + 0x20);
    if (id == *id_ptr)
    {
        return *(rec + 0x24);
    }
    if (id == *(s16 *) (rec + 0x2E))
    {
        return *(rec + 0x32);
    }
    rec += 0x38;
    if ((rec_copy = rec) == (D_8080020C_gcegg + 0x64))
    {
        return 0U;
    }
    goto loop_1;
}

short gcegg_entrypoint_2(s32 egg)
{
    return *(s16 *) ((char *) D_80800202_gcegg + egg * 14);
}

s16 gcegg_entrypoint_3(s32 egg)
{
    return *(s16 *) ((char *) D_80800206_gcegg + egg * 14);
}

s32 gcegg_entrypoint_4(s32 egg)
{
    return D_8080020C_gcegg[egg * 14];
}

u8 gcegg_entrypoint_5(s32 egg)
{
    return D_80800209_gcegg[egg][0];
}

// True if the egg is unlocked: ability 0x3C or func_800C6E38 says so.
int gcegg_entrypoint_6(s32 egg)
{
    s32 ability = D_8080020A_gcegg[egg][0];
    return ability == 0x3C || func_800C6E38(ability) != 0;
}

// Returns 1 in normal mode, otherwise the per-kind flag.
u8 gcegg_entrypoint_7(s32 egg)
{
    // Matching: the temporary is needed for the match.
    u8 flag;
    if (func_800D3948() == 0U) {
        return 1;
    }
    return flag = D_8080020B_gcegg[egg * 0xE];
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/gc/egg.data.s) is defined here in C.
// Values are from the ROM. Linker aliases (undefined_syms.us.txt) into D_80800200_gcegg:
// D_80800202 = +0x2, D_80800206 = +0x6, D_80800209 = +0x9, D_8080020A = +0xA, D_8080020B = +0xB.
u8 D_80800200_gcegg[12] = {0x1, 0x58, 0x0, 0x71, 0x0, 0x0, 0x0, 0x4, 0x0, 0x40, 0x3C, 0x1};
u8 D_8080020C_gcegg[100] = {
    0x3,  0x0,  0x2,  0x6C, 0x0,  0x71, 0x1,  0x5A, 0x0,  0x4,  0x1,  0x40, 0x31, 0x1,  0x3,
    0x0,  0x2,  0x6D, 0x0,  0x6E, 0x1,  0x5B, 0x0,  0x6A, 0x2,  0x41, 0x2C, 0x2,  0x4,  0x0,
    0x2,  0x6E, 0x0,  0x6F, 0x1,  0x5C, 0x0,  0x6B, 0x3,  0x42, 0x2F, 0x0,  0x3,  0x0,  0x2,
    0x6F, 0x0,  0x70, 0x1,  0x5D, 0x0,  0x6C, 0x4,  0x43, 0x2D, 0x4,  0xC,  0x0,  0x2,  0x70,
    0x0,  0x6D, 0x1,  0x5E, 0x0,  0x69, 0x5,  0x44, 0x2E, 0x4,  0x4,  0x0,  0x1,  0x6D, 0x0,
    0x79, 0x1,  0x60, 0x0,  0x78, 0x6,  0x45, 0x3C, 0x4,  0x3,  0x0,  0x2,  0x71, 0x0,  0x71,
    0x1,  0x5F, 0x0,  0x4,  0x7,  0x40, 0x3C, 0x1,  0x5,  0x0};
