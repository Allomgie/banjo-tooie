#include "common.h"

extern s16 D_80800120_chsparkle[];
extern u8 D_8080012C_chsparkle[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern int D_80800164_chsparkle[];

void func_80800000_chsparkle(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[2];
    s32 local_4;
    s32 local_5;
    local_4 = func_800DC128(0, 5);
    local_5 = func_800B53A4(1);
    func_800BA3FC(local_5, D_80800120_chsparkle[local_4]);
    func_800E3980(local_0);
    func_800EE7F8(local_1, param_0->position);
    local_1[1] -= 200.0f;
    func_800F18FC(param_0->position, local_0, local_3);
    func_800EEB9C(local_2, local_3[1] + func_800DC178(-90.0f, 90.0f), 40.0f);
    func_800EF04C(local_2, param_0->position);
    local_2[1] += func_800DC178(0.0f, 120.0f);
    func_800BABB8(local_5, local_2, local_1, 1.0f, D_8080012C_chsparkle);
}

int chsparkle_entrypoint_0()
{
    return (int)&D_80800164_chsparkle;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/sparkle.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800164_chsparkle -> int[] */
extern void func_80105834();
extern void func_8010A730();
extern void func_80108ED0();
extern void func_80107C2C();
s16 D_80800120_chsparkle[6] = { 0x9E2, 0x9E3, 0x9E6, 0x9EA, 0x9E4, 0x0 };
u8 D_8080012C_chsparkle[56] = { 0x0, 0x2B, 0x0, 0x66, 0x0, 0x80, 0x0, 0x2C, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x27, 0xFF, 0x38, 0xFF, 0x38, 0x0, 0xC8, 0x0, 0xC8, 0x0, 0x22, 0x0, 0x40, 0x0, 0x4C, 0x0, 0x19, 0x0, 0x26, 0x0, 0x15, 0x0, 0x33, 0x0, 0xB3, 0x0, 0x33, 0x0, 0x2, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0 };
int D_80800164_chsparkle[19] = { 0x15804D6, 0x1, 0x0, (u32)func_80800000_chsparkle, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x4, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0, 0x0 };
