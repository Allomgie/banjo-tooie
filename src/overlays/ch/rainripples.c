#include "common.h"

extern u32 D_80800290_chrainripples[];
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 D_808002D8_chrainripples[];
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
f32 func_808001FC_chrainripples();

char *chrainripples_entrypoint_0()
{
  return &D_80800290_chrainripples;
}

void func_8080000C_chrainripples(u8 *param_0) {
    *(f32 *)(param_0 + 0x2C) = func_808001FC_chrainripples(param_0) + 4.0f;
}

void func_80800040_chrainripples(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_7;
    u8 *local_4;
    f32 local_5[3];
    f32 local_6;
    local_0 = func_800B7C98();
    if (local_0 && _fxrain_entrypoint_3(local_0)) {
        local_6 = func_800D8FF8();
        local_1 = (s32)((f32)param_0->unk74_7 * local_6);
        local_2 = func_800CC5F4((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1);
        local_3 = 0;
        if (local_1) local_3 = func_800B5BE4(3);
        for (local_7 = 0; local_7 < local_1; local_7++) {
            local_4 = (u8 *)func_800CC63C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, param_0->actorData[4]);
            func_800EE7F8(local_5, local_4);
            local_6 = func_800DC178(0.0f, 359.0f);
            func_800EF1B8(local_5, local_6, func_800DC178(0.0f, *(s16 *)(local_4 + 0xC)));
            local_5[1] = ((f32 *)param_0->actorData)[5];
            func_800BABB8(local_3, local_5, 0, 1.0f, &D_808002D8_chrainripples);
            param_0->actorData[4]++;
            if ((s32)param_0->actorData[4] >= local_2) param_0->actorData[4] = 0;
        }
    }
}

f32 func_808001FC_chrainripples(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    func_800EE7F8(local_0, param_0->position);
    func_800EE7F8(local_1, param_0->position);
    local_0[1] += 100.0f;
    local_1[1] -= 100.0f;
    if (func_800BEF00(local_0, local_1, local_2, 0x1F00)) {
        return local_1[1];
    }
    return param_0->position[1];
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/rainripples.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800290_chrainripples -> u32[], D_808002D8_chrainripples -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800290_chrainripples[18] = { 0xA503DF, 0x1, 0x0, (u32)func_80800040_chrainripples, (u32)func_80105834, (u32)func_80101870, 0x13880000, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, (u32)func_8080000C_chrainripples, (u32)func_80107C2C, 0x80000602, 0x0, 0x0 };
s32 D_808002D8_chrainripples[10] = { 0x1D09DB, 0x161201, 0x2B00CC, 0x1000015, 0x80, 0x220019, 0x190099, 0x100001F, -0x200, 0x11A0000 };
