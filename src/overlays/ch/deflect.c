#include "common.h"

extern void _sudeflect_entrypoint_0(u8 *, f32, f32, s32);
extern int D_80800090_chdeflect[];

// Remove self once the Grip Grab move is learned
s32 func_80800000_chdeflect(s32 actor)
{
    if (func_800C6E38(0x14) != 0) {
        func_800FFAB0(actor);
    }
}

// Push players out of a cylinder (radius = scale * 100)
void func_80800034_chdeflect(u8 *actor)
{
    _sudeflect_entrypoint_0(actor + 4, 0.0f, *(f32 *) (actor + 0x38) * 100.0f, 2);
}

int chdeflect_entrypoint_0()
{
    return (int) &D_80800090_chdeflect;
}

// TU-NOTE: the data table below is defined in this file because it points to its
// functions; IDO schedules those differently otherwise. Values are from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800090_chdeflect[20] = {0x1580535,
                                0x1,
                                0x0,
                                (u32) func_80800034_chdeflect,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x7D00000,
                                0x0,
                                0x0,
                                0x0,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800000_chdeflect,
                                (u32) func_80107C2C,
                                -0x7FFFFC00,
                                0x0,
                                0x0,
                                0x0,
                                0x0};
