#include "common.h"

extern int D_80800298_chfactorygoblin[];
extern u8 D_808002E0_chfactorygoblin[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
void func_8080007C_chfactorygoblin();

int chfactorygoblin_entrypoint_0()
{
    return (int) &D_80800298_chfactorygoblin;
}

int func_8080000C_chfactorygoblin(s32 param_0)
{
    _sucoaster_entrypoint_0(param_0, 0);
    func_8010A3E8(param_0, 0x3F400000);
}

s32 func_8080003C_chfactorygoblin(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0xB6) {
        func_8080007C_chfactorygoblin(param_0, param_1, param_2);
    }
    _sucoaster_entrypoint_21(param_0, param_1, param_2);
}

void func_8080007C_chfactorygoblin(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    local_4 = func_800DC128(6, 8);
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], param_0->scale * 200.0f);
    func_800EE7F8(local_1, local_0);
    local_1[1] -= 5.0f;
    local_3 = func_800B53A4(local_4);
    for (local_5 = 0; local_5 < local_4; local_5++) {
        func_800EEB9C(local_2, local_5 * (360.0f / local_4), 20.0f);
        func_800EF04C(local_2, local_0);
        func_800BABB8(local_3, local_2, local_1, param_0->scale * 0.5f,
                      &D_808002E0_chfactorygoblin);
    }
}

extern void _sucoaster_entrypoint_2();
extern void func_80105834();
extern void _sucoaster_entrypoint_20();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
u32 D_80800200_chfactorygoblin[38] = {
    0x0,        0x0,       0x40600000, 0x34E0001, 0x40600000, 0x34E0001, 0x3FA66666, 0x3480001,
    0x3F4CCCCD, 0x3490001, 0x3FA66666, 0x3480001, 0x3FA66666, 0x3480001, 0x3F800000, 0x34A0002,
    0x3F4CCCCD, 0x3490001, 0x3F800000, 0x34B0002, 0x3F4CCCCD, 0x3490001, 0x3ECCCCCD, 0x34D0002,
    0x3FC00000, 0x34C0002, 0x3FC00000, 0x34C0084, 0x40600000, 0x34E0001, 0x40600000, 0x34E0020,
    0x0,        0x0,       0x40600000, 0x34E0001, 0x3F4CCCCD, 0x3490001};
int D_80800298_chfactorygoblin[18] = {0x32603C3,
                                      0x7FF0001,
                                      (u32) &D_80800200_chfactorygoblin,
                                      (u32) _sucoaster_entrypoint_2,
                                      (u32) func_80105834,
                                      (u32) _sucoaster_entrypoint_20,
                                      0xBB80000,
                                      0x3FCCCCCD,
                                      0x0,
                                      0x43050329,
                                      (u32) _sucoaster_entrypoint_1,
                                      (u32) _sucoasterhit_entrypoint_0,
                                      0x0,
                                      (u32) func_8080000C_chfactorygoblin,
                                      (u32) func_80107C2C,
                                      -0x7BCDAFE3,
                                      (u32) func_8080003C_chfactorygoblin,
                                      -0x7FEDBAB0};
u8 D_808002E0_chfactorygoblin[64] = {
    0x0,  0x1D, 0x9,  0xE2, 0x0, 0x16, 0x3, 0x2,  0x0, 0x15, 0x0, 0x0,  0x0, 0xC0, 0x0, 0x2B,
    0x0,  0x99, 0x0,  0xCC, 0x0, 0x22, 0x0, 0x4C, 0x0, 0x59, 0x0, 0x26, 0x0, 0x33, 0x0, 0x2D,
    0x1,  0xC2, 0x2,  0x26, 0x0, 0xB,  0x0, 0x14, 0x0, 0x1E, 0x0, 0xA,  0x0, 0x0,  0x0, 0x1B,
    0xFC, 0xE0, 0xFD, 0xA8, 0x1, 0x1A, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
