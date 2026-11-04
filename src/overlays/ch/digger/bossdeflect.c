// Possibly an inert helper actor of the Hag 1 fight (likely actor 0x50A): init sets three
// size fields to 500, update and messages do nothing.
#include "common.h"

extern int D_80800040_chdiggerbossdeflect[];

int *chdiggerbossdeflect_entrypoint_0()
{
    return &D_80800040_chdiggerbossdeflect;
}

// Init: sets the three collision/size s16 fields to 500.
func_8080000C_chdiggerbossdeflect(actor)
{
    s16 size = 0x1F4;
    *(s16 *) ((char *) actor + 0x62) = size;
    *(s16 *) ((char *) actor + 0x6A) = size;
    *(s16 *) ((char *) actor + 0x68) = size;
}

void func_80800020_chdiggerbossdeflect(s32 arg0)
{
}

s32 func_80800028_chdiggerbossdeflect(s32 param_0, s32 param_1, s32 param_2)
{
    s32 out;
    // Messages are ignored.
    out = 0;
    return out;
}

extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
int D_80800040_chdiggerbossdeflect[20] = {0x15804FF,
                                          0x1,
                                          0x0,
                                          (u32) func_80800020_chdiggerbossdeflect,
                                          (u32) func_80102EC0,
                                          (u32) func_8010A730,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x4,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_8080000C_chdiggerbossdeflect,
                                          (u32) func_80107C2C,
                                          -0x7FFFE7FA,
                                          (u32) func_80800028_chdiggerbossdeflect,
                                          0x0,
                                          0x0,
                                          0x0};
