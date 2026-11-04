#include "common.h"

extern int D_80800080_chTalTorpWall[];
extern u32 D_80800098_chTalTorpWall[];

void func_80800000_chTalTorpWall(s32 arg0)
{
}

int func_80800008_chTalTorpWall(s32 actor, s32 msg, s32 param_2)
{
    // 0x40: hit by the Talon Torpedo
    if (msg == 0x40) {
        _chexploder_entrypoint_3(actor, actor + 4, 0xE);
        _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80800080_chTalTorpWall);
        func_800DA544(0x3AA);
        return 1;
    }
    return 0;
}

u8 *chTalTorpWall_entrypoint_0(void)
{
    return D_80800098_chTalTorpWall;
}

// TU-NOTE: the overlay .data is defined here in C because its tables point to functions of this file;
// IDO schedules some of them differently otherwise. Values are taken from the ROM.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800080_chTalTorpWall[6] = {0x1B0013, 0x4F4000A, 0xCC0016, 0x6D600001, 0x4E209C4, 0x0};
u32 D_80800098_chTalTorpWall[18] = {0x3770499,
                                    0x9510001,
                                    0x0,
                                    (u32) func_80102EC0,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x3AA0000,
                                    0x800,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80800000_chTalTorpWall,
                                    (u32) func_80107C2C,
                                    0x80002C00,
                                    (u32) func_80800008_chTalTorpWall,
                                    0x0};
