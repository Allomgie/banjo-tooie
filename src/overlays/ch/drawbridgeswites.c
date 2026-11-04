// Probably three switch actors on the generic switch: two send raise/lower messages to the
// drawbridge, a third (CK laser grid deactivated) messages another actor.
#include "common.h"

extern int D_80800210_chdrawbridgeswitches[];
extern int D_80800258_chdrawbridgeswitches[];
extern int D_808002A0_chdrawbridgeswitches[];

s32 func_80800000_chdrawbridgeswitches(Actor *this, Gfx **dl, Mtx **m)
{
    _chswitch_entrypoint_7(this, dl, m);
    _chswitch_entrypoint_8(this, m);
}

// Forwards switch messages 7 and 8 to the drawbridge actor 0x49F.
int func_80800030_chdrawbridgeswitches(s32 actor, s32 msg, s32 arg, s32 bridge_msg_7,
                                       s32 bridge_msg_8)
{
    switch (msg) {
        case 7:
            func_80101180(0x49F, bridge_msg_7, 0);
            _chswitch_entrypoint_10(actor, msg, arg);
            return;

        case 8:
            func_80101180(0x49F, bridge_msg_8, 0);
            _chswitch_entrypoint_10(actor, msg, arg);
            return;

        default:
            _chswitch_entrypoint_10(actor, msg, arg);
    }
}

void func_808000D0_chdrawbridgeswitches(s32 actor)
{
    func_80800000_chdrawbridgeswitches(actor, 0xA20, 0x200);
}

void func_808000F4_chdrawbridgeswitches(s32 actor, s32 msg, s32 arg)
{
    func_80800030_chdrawbridgeswitches(actor, msg, arg, 0x69, 0x68);
}

int chdrawbridgeswitches_entrypoint_0()
{
    return &D_80800210_chdrawbridgeswitches;
}

void func_80800128_chdrawbridgeswitches(s32 actor)
{
    func_80800000_chdrawbridgeswitches(actor, 0xA21, 0x400);
}

void func_8080014C_chdrawbridgeswitches(s32 actor, s32 msg, s32 arg)
{
    func_80800030_chdrawbridgeswitches(actor, msg, arg, 0x6b, 0x6a);
}

int chdrawbridgeswitches_entrypoint_1()
{
    return (int) &D_80800258_chdrawbridgeswitches;
}

s32 func_80800180_chdrawbridgeswitches(s32 actor)
{
    func_80800000_chdrawbridgeswitches(actor, 0x58E, 1);
    _chswitch_entrypoint_9(actor);
}

// Switch for flag 0x58E: message 7 is forwarded to actor 0x395.
int func_808001B0_chdrawbridgeswitches(s32 actor, s32 msg, s32 arg)
{
    if (msg == 7) {
        func_80101180(0x395, 7, 0);
    }
    _chswitch_entrypoint_10(actor, msg | msg, arg);
}

int chdrawbridgeswitches_entrypoint_2()
{
    return &D_808002A0_chdrawbridgeswitches;
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void _chswitch_entrypoint_2();
extern void func_80107C2C();
int D_80800210_chdrawbridgeswitches[18] = {0x34304A0,
                                           0x7B80001,
                                           -0x7FEE5DE0,
                                           (u32) _chswitch_entrypoint_6,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x808,
                                           0x0,
                                           (u32) _chswitch_entrypoint_2,
                                           0x0,
                                           (u32) func_808000D0_chdrawbridgeswitches,
                                           (u32) func_80107C2C,
                                           -0x7FFFD3FE,
                                           (u32) func_808000F4_chdrawbridgeswitches,
                                           0x0};
int D_80800258_chdrawbridgeswitches[18] = {0x34304A1,
                                           0x7B90001,
                                           -0x7FEE5DE0,
                                           (u32) _chswitch_entrypoint_6,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x808,
                                           0x0,
                                           (u32) _chswitch_entrypoint_2,
                                           0x0,
                                           (u32) func_80800128_chdrawbridgeswitches,
                                           (u32) func_80107C2C,
                                           -0x7FFFD3FE,
                                           (u32) func_8080014C_chdrawbridgeswitches,
                                           0x0};
int D_808002A0_chdrawbridgeswitches[20] = {0x343053D,
                                           0x9420001,
                                           -0x7FEE5DE0,
                                           (u32) _chswitch_entrypoint_6,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x808,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_80800180_chdrawbridgeswitches,
                                           (u32) func_80107C2C,
                                           -0x7FFFD3FE,
                                           (u32) func_808001B0_chdrawbridgeswitches,
                                           0x0,
                                           0x0,
                                           0x0};
