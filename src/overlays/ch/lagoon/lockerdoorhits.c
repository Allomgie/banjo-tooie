#include "common.h"

extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 D_808003A0_chlagoonlockerdoorhits[];
extern u8 D_808003CC_chlagoonlockerdoorhits[];
extern u8 D_80800430_chlagoonlockerdoorhits[];
extern u16 D_808003E4_chlagoonlockerdoorhits[];
extern int D_8080045C_chlagoonlockerdoorhits[];
extern s16 D_808003F8_chlagoonlockerdoorhits[];
void func_808001B0_chlagoonlockerdoorhits();
void func_8080022C_chlagoonlockerdoorhits();

void func_80800000_chlagoonlockerdoorhits(u8 *param_0)
{
    s32 local_0;
    u8 *local_1;

    local_0 = ((u32) (u16) *(u16 *) ((s8 *) param_0 + 0x76) >> 7) - 0x33;
    if ((func_800DA298(0x3A8) != 0) && ((func_800DA564(0x3A4, 4) + 0x32) ==
                                        ((u32) (u16) *(u16 *) ((s8 *) param_0 + 0x76) >> 7))) {
        func_800FFAB0(param_0);
        return;
    }
    local_1 = (u8 *) (D_808003F8_chlagoonlockerdoorhits + local_0 * 3);
    *(f32 *) ((s8 *) param_0 + 4) =
        (f32) (((f32) *(s16 *) ((s8 *) local_1 + 0) * 100.0f) + 8500.0f);
    *(f32 *) ((s8 *) param_0 + 8) =
        (f32) (((f32) *(s16 *) ((s8 *) local_1 + 2) * 100.0f) + -8000.0f);
    *(f32 *) ((s8 *) param_0 + 0xC) =
        (f32) (((f32) *(s16 *) ((s8 *) local_1 + 4) * 100.0f) + -8200.0f);
    func_80103014(param_0);
}

s32 func_8080010C_chlagoonlockerdoorhits(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x40) {
        func_800DA3B8(0x3A8, 1);
        func_800FFAB0(param_0);
        func_800C4AF0(param_0->position, D_808003CC_chlagoonlockerdoorhits);
        func_800BABB8(0, param_0->position, param_0->position, param_0->scale,
                      D_808003A0_chlagoonlockerdoorhits);
        func_808001B0_chlagoonlockerdoorhits();
        return 1;
    } else if (param_1 == 0x95) {
        func_8080022C_chlagoonlockerdoorhits(param_0);
        return 1;
    }
    return 0;
}

void func_808001B0_chlagoonlockerdoorhits(void)
{
    s32 local_0;
    s32 local_2;

    local_0 = func_800DA564(0x3A4, 4);
    if (func_800DA298(0x3A8))
        local_2 = 0;
    else
        local_2 = 1;
    func_800BF744((local_0 * 2) + 9, local_2);
    if (func_800DA298(0x3A8))
        local_2 = 0;
    else
        local_2 = 0xF;
    func_800BF744((local_0 * 2) + 10, local_2);
}

void func_8080022C_chlagoonlockerdoorhits(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_4;
    local_0 = param_0->unk74_7 - 0x33;
    local_1 = func_800DA564(0x3A4, 4);
    if (!local_1) {
        while (!local_1 || local_1 >= 10) {
            local_1 = func_800DC090() & 15;
            func_800DA7A8(0x39F, func_800DC090() & 31, 5);
        }
        func_800DA7A8(0x3A4, local_1, 4);
    }
    local_4 = D_80800430_chlagoonlockerdoorhits + func_800DA564(0x39F, 5);
    for (local_2 = 0; local_2 < 9; local_2++) {
        func_800BF744(local_2 * 2 + 11, 1);
        func_800BF744(local_2 * 2 + 12, local_4[local_2]);
    }
    func_808001B0_chlagoonlockerdoorhits();
    if (func_800DA564(0x3A4, 4) + 0x32 == (s32) param_0->unk74_7)
        func_8010A590(param_0);
    func_80103140(param_0, D_808003E4_chlagoonlockerdoorhits[local_0], 0);
}

int chlagoonlockerdoorhits_entrypoint_0()
{
    return (int) &D_8080045C_chlagoonlockerdoorhits;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_8010A73C();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_808003A0_chlagoonlockerdoorhits[11] = {0x1910001D, 0x8FB0014, 0x2D0190,  0x258001B,
                                             -0x31F0258, 0x2201B3,  0x1CC01B3, 0x1B3001E,
                                             0x320046,   0xD004B,   0x191A0000};
u8 D_808003CC_chlagoonlockerdoorhits[24] = {0x0, 0x13, 0x4, 0x13, 0x0,  0x1B, 0x0, 0xA,
                                            0x0, 0xE6, 0x0, 0x16, 0x7F, 0xF8, 0x0, 0x1,
                                            0x4, 0xE2, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u16 D_808003E4_chlagoonlockerdoorhits[10] = {0x8E4, 0x8E5, 0x8E6, 0x8E7, 0x8E8,
                                             0x8E9, 0x8EA, 0x8EB, 0x8EC, 0x0};
s16 D_808003F8_chlagoonlockerdoorhits[28] = {
    0x11, 0x0,  0x19, 0x5,  0x0, 0xA,  -0xD, -0x3, 0x9,  -0x1F, -0xB, 0xA,  -0x17, -0xB,
    -0xB, -0x5, -0x6, -0x3, 0x6, -0x4, -0x9, 0x15, -0x4, -0x8,  0x0,  -0xA, -0x1B, 0x0};
u8 D_80800430_chlagoonlockerdoorhits[44] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB,
                                            0xC, 0xD, 0xE, 0x4, 0x1, 0x7, 0x3, 0x8, 0x2, 0xB, 0x5,
                                            0xA, 0x6, 0xD, 0x9, 0xE, 0xC, 0x2, 0x8, 0xB, 0x4, 0xA,
                                            0x1, 0xD, 0x6, 0xE, 0x5, 0x3, 0xC, 0x9, 0x7, 0x0, 0x0};
int D_8080045C_chlagoonlockerdoorhits[21] = {0x3750496,
                                             -0xFFFF,
                                             0x0,
                                             (u32) func_80102EC0,
                                             (u32) func_80105834,
                                             (u32) func_8010A73C,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x800,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             (u32) func_80800000_chlagoonlockerdoorhits,
                                             (u32) func_80107C2C,
                                             -0x7FFFD3FE,
                                             (u32) func_8080010C_chlagoonlockerdoorhits,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x0};
