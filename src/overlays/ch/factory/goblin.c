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

int func_8080000C_chfactorygoblin(s32 actor)
{
    _sucoaster_entrypoint_0(actor, 0);
    func_8010A3E8(actor, 0x3F400000);
}

s32 func_8080003C_chfactorygoblin(s32 actor, s32 msg, s32 arg)
{
    if (msg == 0xB6) {
        func_8080007C_chfactorygoblin(actor, msg, arg);
    }
    _sucoaster_entrypoint_21(actor, msg, arg);
}

// Attack/stomp: emit a ring of 6-8 particles in front of the actor.
void func_8080007C_chfactorygoblin(actor) Actor *actor;
{
    f32 center[3];
    f32 target[3];
    f32 offset[3];
    s32 emitter;
    s32 count;
    s32 i;
    count = func_800DC128(6, 8);
    func_800EE7F8(center, actor->position);
    func_800EF1B8(center, actor->rotation[1], actor->scale * 200.0f);
    func_800EE7F8(target, center);
    target[1] -= 5.0f;
    emitter = func_800B53A4(count);
    for (i = 0; i < count; i++) {
        func_800EEB9C(offset, i * (360.0f / count), 20.0f);
        func_800EF04C(offset, center);
        func_800BABB8(emitter, offset, target, actor->scale * 0.5f,
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
