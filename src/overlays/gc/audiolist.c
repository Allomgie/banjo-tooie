#include "common.h"

extern void func_800C4AF0(s32, s32);
extern s32 D_808000F0_gcaudiolist[];

int gcaudiolist_entrypoint_0(s32 param_0)
{
    u32 local_0;
    local_0 = param_0 | 0;
    func_800C4AF0(0, D_808000F0_gcaudiolist[local_0]);
}

void gcaudiolist_entrypoint_1(s32 param_0, s32 param_1)
{
    func_800C4B70(param_1);
    func_800C4AF0(0, D_808000F0_gcaudiolist[param_0]);
}

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
