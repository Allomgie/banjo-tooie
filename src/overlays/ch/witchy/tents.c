// Probably Witchyworld tent scenery props: static, except on the Saucer of Peril map where the
// marker's collision bit is cleared.

#include "common.h"

extern int D_80800050_chwitchytents[];
extern int D_80800098_chwitchytents[];

// Saucer of Peril: clear the marker collidable bit.
s32 func_80800000_chwitchytents(s32 actor)
{
    if (func_800EA05C() == 0x124) {
        func_8010A624(actor);
    }
}

int chwitchytents_entrypoint_0()
{
    return &D_80800050_chwitchytents;
}

int chwitchytents_entrypoint_1()
{
    return (int) &D_80800098_chwitchytents;
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
int D_80800050_chwitchytents[18] = {0x15804C4,
                                    0x85D0001,
                                    0x0,
                                    (u32) func_80102EC0,
                                    (u32) func_80102EC0,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x1C0C,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chwitchytents,
                                    (u32) func_80107C2C,
                                    -0x7FFFD3FE,
                                    0x0,
                                    0x0};
int D_80800098_chwitchytents[18] = {0x15804C5,
                                    0x85D0001,
                                    0x0,
                                    (u32) func_80102EC0,
                                    (u32) func_80102EC0,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x1C0C,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chwitchytents,
                                    (u32) func_80107C2C,
                                    -0x7FFFD3FE,
                                    0x0,
                                    0x0};
