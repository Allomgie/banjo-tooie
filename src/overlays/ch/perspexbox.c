#include "common.h"

extern s32 D_80800090_chperspexbox[];
extern s32 D_80800124_chperspexbox[];
extern void *D_80800138_chperspexbox;

int func_80800000_chperspexbox(s32 *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 7) {
        func_800BABB8(0, param_0 + 1, param_0 + 1, param_0[0x0E], &D_80800090_chperspexbox);
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 1, &D_80800124_chperspexbox);
        func_800FC6B0(0x18);
        func_800FFAB0(param_0);
        return 1;
    }
    return 0;
}

int chperspexbox_entrypoint_0()
{
    return &D_80800138_chperspexbox;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_80800090_chperspexbox[37] = {
    0x410001D, 0x9DD002B, 0x2000300, 0x220180,    0x2000480,  0x6000015, 0x26,       0x190000,
    0x7002D,   0x320064,  0x2071DE,  -0x583FFFF6, -0x63FFE7,  -0x63FF9C, 0x4B0064,   0x41A0710,
    0x1D08F3,  0x14002D,  0x1900258, 0x1BFCE0,    -0x257FFDE, 0xE60100,  0xE600E6,   0x1E0032,
    0x32000D,  0x4B071A,  0x710001D, 0x8F70014,   0x2D0190,   0x258001B, -0x31F0258, 0x2200E6,
    0x10000E6, 0xE6001E,  0x320032,  0xD004B,     0x71A0000};
s32 D_80800124_chperspexbox[5] = {0x13048D, 0xA00E6, 0x166D60, 0x104E2, 0x9C40000};
void *D_80800138_chperspexbox = (void *) 0x015804C0;
static u32 D_80800138_chperspexbox_rest[17] = {0x8F20001,
                                               0x0,
                                               0x0,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x43A0000,
                                               0x20C00,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x0,
                                               0x0,
                                               (u32) func_80107C2C,
                                               0x80082402,
                                               (u32) func_80800000_chperspexbox,
                                               0x0};
