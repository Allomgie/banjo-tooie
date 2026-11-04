// Indexed list of UI and jingle sound effects, played through the global sfx player.
#include "common.h"

extern void func_800C4AF0(s32, s32);
extern s32 D_808000F0_gcaudiolist[];

// Plays sound number `index` from the list.
int gcaudiolist_entrypoint_0(s32 index)
{
    u32 sound_idx;
    // Matching: the `| 0` and the temporary are needed for the match.
    sound_idx = index | 0;
    func_800C4AF0(0, D_808000F0_gcaudiolist[sound_idx]);
}

// Sets a sound parameter, then plays sound number `index` from the list.
void gcaudiolist_entrypoint_1(s32 index, s32 param)
{
    func_800C4B70(param);
    func_800C4AF0(0, D_808000F0_gcaudiolist[index]);
}

// TU-NOTE: the overlay .data is defined here in C (values taken from the ROM).
u32 D_80800080_gcaudiolist[3] = {0x130456, 0x18001B, 0x0};
u32 D_8080008C_gcaudiolist[3] = {0x130477, 0x18001B, 0x0};
u32 D_80800098_gcaudiolist[4] = {0x130469, 0xA0119, 0x1E001B, 0x200000};
u32 D_808000A8_gcaudiolist[4] = {0x13046A, 0xA0119, 0x1E001B, 0x200000};
u32 D_808000B8_gcaudiolist[3] = {0x13046C, 0x1E001B, 0x200000};
u32 D_808000C4_gcaudiolist[3] = {0x13046B, 0x1E001B, 0x200000};
u32 D_808000D0_gcaudiolist[4] = {0x13069E, 0x165208, 0x1B0020, 0x0};
u32 D_808000E0_gcaudiolist[4] = {0x13069E, 0x165208, 0x1B0020, 0x0};
s32 D_808000F0_gcaudiolist[8] = {(u32) &D_80800080_gcaudiolist, (u32) &D_8080008C_gcaudiolist,
                                 (u32) &D_80800098_gcaudiolist, (u32) &D_808000A8_gcaudiolist,
                                 (u32) &D_808000B8_gcaudiolist, (u32) &D_808000C4_gcaudiolist,
                                 (u32) &D_808000D0_gcaudiolist, (u32) &D_808000E0_gcaudiolist};
