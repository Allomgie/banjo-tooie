#include "common.h"

extern int D_808001C0_chtemplebossdoor[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);

int chtemplebossdoor_entrypoint_0()
{
    return (int) &D_808001C0_chtemplebossdoor;
}

// Doors that open after 10 (variant 0) or 20 (variant 1) jade statues are broken.
void func_8080000C_chtemplebossdoor(Actor *actor)
{
    s32 required;
    s32 camera_arg;
    camera_arg = 0;
    switch (((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7) - 50) {
        case 0:
            required = 10;
            break;
        case 1:
            required = 20;
            camera_arg = 2;
            break;
    }
    if (func_800D035C(5) < required) {
        if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 190.0f, 0x40, -1)) {
            _chdoormake_entrypoint_5(actor, 1.5f);
            _chdoormake_entrypoint_8(actor, 5);
            _chdoormake_entrypoint_9(actor, 0, camera_arg, 0x30);
        }
    } else
        func_800FFA88(actor->unk0);
}

// Message 7: jade statue counter reached a threshold; 0x59: remove the door.
s32 func_808000E8_chtemplebossdoor(Actor *actor, s32 msg, s32 msg_data)
{
    s32 variant;

    switch (msg) {
        case 7:
            variant = actor->unk74_7 - 0x32;
            if (msg_data != variant)
                return 0;
            _subaddiedialog_entrypoint_11(actor->unk0, variant ? 0xF3B : 0xF3A, 0x106,
                                          actor->position, 0xB2);
            break;
        case 0x2E:
            func_80108BD4(actor, 0);
            return 1;
        case 0x59:
            _capod_entrypoint_14();
            func_800FFA88(actor->unk0);
            return 1;
    }
    return _chdoor_entrypoint_1(actor, msg, msg_data);
}
// TU-NOTE: the overlay .data is defined here in C because its tables point to functions of this file;
// IDO schedules some of them differently otherwise. Values are taken from the ROM.

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808001C0_chtemplebossdoor[20] = {0xAC02B4,
                                       0x83F0001,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080000C_chtemplebossdoor,
                                       (u32) func_80107C2C,
                                       -0x7FFFD3FE,
                                       (u32) func_808000E8_chtemplebossdoor,
                                       0x0,
                                       0x0,
                                       0x0};
