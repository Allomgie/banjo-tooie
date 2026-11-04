#include "common.h"

extern int D_80800150_chminegrill2switches[];
extern void *D_80800198_chminegrill2switches;

s32 func_80800000_chminegrill2switches(Actor *actor, s32 flag, s32 mask)
{
    _chswitch_entrypoint_7(actor, flag);
    _chswitch_entrypoint_8(actor, mask);
}

// Forwards the switch message and, on message 7, tells the grill door (actor 0x4C2).
s32 func_80800030_chminegrill2switches(actor, msg, arg, door_msg)
s32 actor;
s32 msg;
s32 arg;
s32 door_msg;
{

if (msg == 7) {
    func_80101180(0x4C2, door_msg, 0);
    _chswitch_entrypoint_10(actor, msg, arg);
} else {

_chswitch_entrypoint_10(actor, msg, arg);
}
}

void func_80800094_chminegrill2switches(s32 actor)
{
    func_80800000_chminegrill2switches(actor, 0xA26, 0x200);
}

void func_808000B8_chminegrill2switches(s32 actor, s32 msg, s32 arg)
{
    func_80800030_chminegrill2switches(actor, msg, arg, 0x7A, 0x79);
}

int *chminegrill2switches_entrypoint_0()
{
    return &D_80800150_chminegrill2switches;
}

int func_808000EC_chminegrill2switches(int actor)
{
    // Matching: the temporary chain is needed for the match.
    int flag;
    int flag_value;
    flag = (flag_value = 0xA28);
    func_80800000_chminegrill2switches(actor, flag, 0x400);
}

void func_80800110_chminegrill2switches(s32 actor, s32 msg, s32 arg)
{
    func_80800030_chminegrill2switches(actor, msg, arg, 0x7c, 0x7b);
}

int chminegrill2switches_entrypoint_1()
{
    return &D_80800198_chminegrill2switches;
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void _chswitch_entrypoint_2();
extern void func_80107C2C();
int D_80800150_chminegrill2switches[18] = {0x343049D,
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
                                           (u32) func_80800094_chminegrill2switches,
                                           (u32) func_80107C2C,
                                           -0x7FF7D3FE,
                                           (u32) func_808000B8_chminegrill2switches,
                                           0x0};
void *D_80800198_chminegrill2switches = (void *) 0x0343049E;
static u32 D_80800198_chminegrill2switches_rest[17] = {0x7B90001,
                                                       0x8011A220,
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
                                                       (u32) func_808000EC_chminegrill2switches,
                                                       (u32) func_80107C2C,
                                                       0x80082C02,
                                                       (u32) func_80800110_chminegrill2switches,
                                                       0x0};
