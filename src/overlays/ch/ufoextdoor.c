#include "common.h"

typedef union {
    s32 word;
    Unk80132ED0 *marker;
} UfoMessage1438;
extern s32 D_80800100_chufoextdoor[];
extern s32 D_80800114_chufoextdoor[];
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern int D_80800148_chufoextdoor[];

// Message 0x3E: hit; only Talon Torpedo (attack 0x14) smashes the door.
s32 func_80800000_chufoextdoor(Actor *actor, s32 message, UfoMessage1438 hit)
{
    f32 *position;
    f32 debris_pos[3];

    if (message == 0x3E) {
        if (hit.marker->unk24 >> 22) {
            return 0;
        }
        if (func_800F52B8((u32) ((u16 *) hit.marker)[0xD] >> 5, actor->unk0) != 0x14) {
            return 0;
        }
        position = actor->position;
        func_800EE7F8(debris_pos, position);
        func_800EF1B8(debris_pos, actor->rotation[1], -100.0f);
        _chexploder_entrypoint_3(actor, debris_pos, 0xE);
        func_800BBCB8(position, debris_pos, 0.8f, 5, D_80800114_chufoextdoor);
        _subaddieaudioquick_entrypoint_2(actor, position, D_80800100_chufoextdoor);
        func_800DA544(0x3AB);
        return 1;
    }
    return 0;
}

int *chufoextdoor_entrypoint_0()
{
    return &D_80800148_chufoextdoor;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_80800100_chufoextdoor[5] = {0x1304A0, 0xA00E6, 0x166D60, 0x2001B, 0x0};
s32 D_80800114_chufoextdoor[13] = {0x1D09DD,    0x2B0300, 0x4000022, 0x1800200, 0x4800600,
                                   0x150000,    0x990019, 0x7,       0x2D0032,  0x4B0020,
                                   -0x7F373F40, 0xE0050,  0x640000};
int D_80800148_chufoextdoor[18] = {0x37C049A,
                                   0x93C0001,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x3AB0000,
                                   0x804,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800000_chufoextdoor,
                                   0x0};
