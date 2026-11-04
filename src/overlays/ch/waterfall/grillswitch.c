#include "common.h"

extern u32 D_80800090_chwaterfallgrillswitch[];

// Message 7: tell the grille (actor kind 0x11B) to open.
int func_80800000_chwaterfallgrillswitch(s32 actor, s32 message, s32 unk_2)
{
    if (message == 7) {
        func_80101180(0x11B, 7, 0);
    }
    _chswitch_entrypoint_10(actor, message | message, unk_2); // Matching: `| message` needed for the match.
}

s32 func_80800054_chwaterfallgrillswitch(Actor *this)
{
    _chswitch_entrypoint_7(this, 0);
    _chswitch_entrypoint_8(this, 0x201);
}

int chwaterfallgrillswitch_entrypoint_0()
{
    return (int) &D_80800090_chwaterfallgrillswitch;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800090_chwaterfallgrillswitch[20] = {0xC011C,
                                             0x6800001,
                                             (u32) &D_8011A248,
                                             (u32) _chswitch_entrypoint_6,
                                             (u32) func_80102EC0,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x808,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800054_chwaterfallgrillswitch,
                                             (u32) func_80107C2C,
                                             0x80002C02,
                                             (u32) func_80800000_chwaterfallgrillswitch,
                                             0x0,
                                             0x0,
                                             0x0};
