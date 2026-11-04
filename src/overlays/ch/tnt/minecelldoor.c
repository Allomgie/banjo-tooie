#include "common.h"

extern int D_80800140_chtntminecelldoor[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
void func_808000F4_chtntminecelldoor();

void *chtntminecelldoor_entrypoint_0()
{
    return &D_80800140_chtntminecelldoor;
}

void func_8080000C_chtntminecelldoor(s32 arg)
{
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg);
}

s32 func_80800034_chtntminecelldoor(Actor *actor, s32 message, s32 unk_2)
{
    f32 pos[3];
    switch (message) {
        case 5:
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, actor->rotation[1], 100.0f);
            pos[1] += 25.0f;
            _chexploder_entrypoint_3(actor, pos, 40);
            break;
        case 0x90:
            func_808000F4_chtntminecelldoor(actor);
            break;
        case 0x95:
            _chtntdetonator_entrypoint_1(actor, 0x85);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808000F4_chtntminecelldoor(actor) s32 actor;
{
    s32 exploder_copy;
    s32 exploder;

    exploder = func_80106790(func_80101080());
    exploder_copy = exploder; // Matching: extra copy needed for the match.
    _chexploder_entrypoint_13(exploder, 1);
    _chexploder_entrypoint_12(exploder_copy, 0x3C);
    func_800DA544(0x85);
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800140_chtntminecelldoor[36] = {0xAC014B,
                                        0x6AB0001,
                                        0x0,
                                        (u32) func_80102EC0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_8080000C_chtntminecelldoor,
                                        (u32) func_80107C2C,
                                        -0x7FF7D3FE,
                                        (u32) func_80800034_chtntminecelldoor,
                                        0x0,
                                        0x310001D,
                                        0x9DD002B,
                                        0x8000A00,
                                        0x220200,
                                        0x2800600,
                                        0x8000015,
                                        0x26,
                                        0x190000,
                                        0x7002D,
                                        0x320050,
                                        0x20DEA7,
                                        0x71C0000A,
                                        -0x31FFE7,
                                        -0x31FFCE,
                                        0x280032,
                                        0x31A0000,
                                        0x0,
                                        0x0};
