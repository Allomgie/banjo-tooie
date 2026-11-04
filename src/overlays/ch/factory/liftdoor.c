// Probably the GI elevator-shaft doors: a doormake door with open flag variant+0xC, and a
// call switch that sets that flag and sends message 7 to the lift actor (0x3B8).
#include "common.h"

extern int D_80800140_chfactoryliftdoor[];
extern int D_80800188_chfactoryliftdoor[];
extern int _chdoormake_entrypoint_3(u8 *, f32, s32, s32, s32, s32);

typedef struct {
    s16 a, b;
} S16Pair;

int chfactoryliftdoor_entrypoint_0()
{
    return &D_80800140_chfactoryliftdoor;
}

int chfactoryliftdoor_entrypoint_1()
{
    return (int) &D_80800188_chfactoryliftdoor;
}

void func_80800018_chfactoryliftdoor(u8 *door)
{
    u32 flag;
    u32 variant;
    s32 unk_2;

    flag = *(u16 *) ((u8 *) door + 0x76);
    variant = flag >> 7;
    // Open flag is variant + 0xC.
    flag = variant + 0xC;
    unk_2 = 1;

    if (_chdoormake_entrypoint_3(door, 0, 0x42B40000, 0x43960000, unk_2, flag) != 0) {
        _chdoormake_entrypoint_5(door, 0x3FC00000);
        _chdoormake_entrypoint_8(door, 4);
    }
    func_8010A800(door, 0);
}

void func_8080008C_chfactoryliftdoor(Actor *actor)
{
    s32 flag;

    flag = actor->unk74_7 + 0xC;
    _chswitch_entrypoint_14(actor, flag);
    func_80109EEC(actor, 0x40);
    func_80105010(actor);
    if (func_800DA298(flag)) {
        func_8010A570(actor);
    }
}

// Call switch: sends message 7 to the lift actor (0x3B8).
s32 func_808000F0_chfactoryliftdoor(Actor *actor, s32 msg, S16Pair data)
{
    if (msg == 7) {
        func_80101180(0x3B8, msg, 0);
        func_8010A570(actor);
    } else {
        return 0;
    }
    return 1;
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern void _chswitch_entrypoint_13();
extern void _chswitch_entrypoint_0();
extern void _bsbtrot_entrypoint_10();
int D_80800140_chfactoryliftdoor[18] = {0xAC03B8,
                                        0x7480001,
                                        0x0,
                                        (u32) _chdoor_entrypoint_0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000800,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800018_chfactoryliftdoor,
                                        (u32) func_80107C2C,
                                        -0x7FF7D3AE,
                                        (u32) _chdoor_entrypoint_1,
                                        0x0};
int D_80800188_chfactoryliftdoor[18] = {0xA903B9,
                                        0x7490001,
                                        -0x7FEE5D68,
                                        (u32) _chswitch_entrypoint_13,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x808,
                                        0x0,
                                        (u32) _chswitch_entrypoint_0,
                                        0x0,
                                        (u32) func_8080008C_chfactoryliftdoor,
                                        (u32) func_80107C2C,
                                        (u32) _bsbtrot_entrypoint_10,
                                        (u32) func_808000F0_chfactoryliftdoor,
                                        0x0};
