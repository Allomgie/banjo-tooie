#include "common.h"

extern u8 D_808000F0_chcrackarchwall[];
extern u8 D_80800130_chcrackarchwall[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef union {
    s32 word;
    s16 half[2];
} CrackWallEventValue;
extern int D_80800144_chcrackarchwall[];

// Message handler. The flag to check/set is the placement parameter (u16 at +0x76 >> 7).
s32 func_80800000_chcrackarchwall(Actor *actor, s32 msg, CrackWallEventValue value)
{
    switch (msg) {
        case 0x95:
            // Already broken at load: remove self
            if (func_800DA298((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7))
                func_800FFAB0(actor);
            break;
        case 0x40:
            // Broken: set the flag and explode
            func_800DA544((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7);
            _chexploder_entrypoint_3(actor, actor->position, 12);
            break;
        case 0x90:
            // Destroyed: debris particles and sound
            func_800BABB8(0, actor->position, actor->position, actor->scale,
                          D_808000F0_chcrackarchwall);
            func_800C4AF0(actor->position, D_80800130_chcrackarchwall);
            break;
        default:
            return 0;
    }
    return 1;
}

int chcrackarchwall_entrypoint_0()
{
    return (int) &D_80800144_chcrackarchwall;
}

// TU-NOTE: the data table below is defined in this file because it points to its
// functions; IDO schedules those differently otherwise. Values are from the ROM.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_808000F0_chcrackarchwall[64] = {
    0x9,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x2, 0x0,  0x3,  0x0,  0x0,  0x22, 0x1, 0x80,
    0x2,  0x0,  0x4, 0x80, 0x6,  0x0,  0x0, 0x15, 0x0, 0x0,  0x0,  0x26, 0x0,  0x19, 0x0, 0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0, 0x64, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x0, 0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0,  0x64, 0x9,  0x1A, 0x0, 0x0};
u8 D_80800130_chcrackarchwall[20] = {0x0,  0x13, 0x4, 0x13, 0x0, 0xA,  0x0, 0xE6, 0x0, 0x16,
                                     0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0};
int D_80800144_chcrackarchwall[19] = {0xAC012B,
                                      0x8F90001,
                                      0x0,
                                      (u32) func_80102EC0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FFFD400,
                                      (u32) func_80800000_chcrackarchwall,
                                      0x0,
                                      0x0};
