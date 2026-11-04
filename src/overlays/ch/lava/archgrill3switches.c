// Probably the three switch variants of the Hailfire Peaks arch grill: each wraps the generic
// switch with its own flag and sends press/release messages to the arch grill actor.
#include "common.h"

extern int D_808001F0_chlavaarchgrill3switches[];
extern int D_80800238_chlavaarchgrill3switches[];
extern int D_80800280_chlavaarchgrill3switches[];

void func_80800000_chlavaarchgrill3switches()
{
    _chswitch_entrypoint_7();
}

// Wrapper: on press (7) / release (8) send a message to the arch grill (type 0x288), then run the generic switch.
void func_80800020_chlavaarchgrill3switches(s32 actor, s32 msg, s32 data, s32 press_msg,
                                            s32 release_msg)
{
    switch (msg) {
        case 7:
            func_80101180(0x288, press_msg, 0);
            _chswitch_entrypoint_10(actor, msg, data);
            return;
        case 8:
            func_80101180(0x288, release_msg, 0);
            _chswitch_entrypoint_10(actor, msg, data);
            return;
        default:
            _chswitch_entrypoint_10(actor, msg, data);
    }
}

s32 func_808000C0_chlavaarchgrill3switches(s32 actor)
{
    func_80800000_chlavaarchgrill3switches(actor, 0xA1D);
    _chswitch_entrypoint_8(actor, 0x200);
}

void func_808000F0_chlavaarchgrill3switches(s32 actor, s32 msg, s32 data)
{
    func_80800020_chlavaarchgrill3switches(actor, msg, data, 0x63, 0x64);
}

int *chlavaarchgrill3switches_entrypoint_0()
{
    return &D_808001F0_chlavaarchgrill3switches;
}

int func_80800124_chlavaarchgrill3switches(Actor *actor)
{
    func_80800000_chlavaarchgrill3switches(actor, 0xA1E);
    _chswitch_entrypoint_8(actor, 0x400);
}

void func_80800154_chlavaarchgrill3switches(s32 actor, s32 msg, s32 data)
{
    func_80800020_chlavaarchgrill3switches(actor, msg, data, 0x61, 0x62);
}

int chlavaarchgrill3switches_entrypoint_1()
{
    return &D_80800238_chlavaarchgrill3switches;
}

int func_80800188_chlavaarchgrill3switches(Actor *actor)
{
    func_80800000_chlavaarchgrill3switches(actor, 0xA1F);
    _chswitch_entrypoint_8(actor, 0x200);
}

void func_808001B8_chlavaarchgrill3switches(s32 actor, s32 msg, s32 data)
{
    func_80800020_chlavaarchgrill3switches(actor, msg, data, 0x5d, 0x5e);
}

int chlavaarchgrill3switches_entrypoint_2(void)
{
    return (int) &D_80800280_chlavaarchgrill3switches;
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808001F0_chlavaarchgrill3switches[18] = {0x3430492,
                                               0x7B80001,
                                               -0x7FEE5DE0,
                                               (u32) _chswitch_entrypoint_6,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x40000808,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_808000C0_chlavaarchgrill3switches,
                                               (u32) func_80107C2C,
                                               -0x7FF7D7EE,
                                               (u32) func_808000F0_chlavaarchgrill3switches,
                                               0x0};
int D_80800238_chlavaarchgrill3switches[18] = {0x3430493,
                                               0x7B90001,
                                               -0x7FEE5DE0,
                                               (u32) _chswitch_entrypoint_6,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x40000808,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_80800124_chlavaarchgrill3switches,
                                               (u32) func_80107C2C,
                                               -0x7FF7D7EE,
                                               (u32) func_80800154_chlavaarchgrill3switches,
                                               0x0};
int D_80800280_chlavaarchgrill3switches[20] = {0x3430494,
                                               0x7B80001,
                                               -0x7FEE5DE0,
                                               (u32) _chswitch_entrypoint_6,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x40000808,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_80800188_chlavaarchgrill3switches,
                                               (u32) func_80107C2C,
                                               -0x7FF7D7EE,
                                               (u32) func_808001B8_chlavaarchgrill3switches,
                                               0x0,
                                               0x0,
                                               0x0};
