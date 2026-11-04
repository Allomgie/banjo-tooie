#include "common.h"

extern int D_808001F0_chminelobbydoor[];
extern int _chdoormake_entrypoint_3(s32, f32, s32, s32, s32, s32);
extern s32 func_800C6E38(s32);
extern void _subaddiedialog_entrypoint_7(Actor *, f32 *, void *);
typedef union {
    s32 word;
    s16 half[2];
} DoorEventData;
extern void func_8010108C(Actor *, s32, s32);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

int chminelobbydoor_entrypoint_0()
{
    return (int) &D_808001F0_chminelobbydoor;
}

// Entrance door of Ordnance Storage: starts open on entry via exit 1 unless the jiggy is missing.
void func_8080000C_chminelobbydoor(s32 door)
{
    if ((func_800EA090() == 1) && ((func_800D0A9C(0xF, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(door, 1);
    }
    if (_chdoormake_entrypoint_3(door, 0, 0x42B40000, 0x43480000, 8, -1) != 0) {
        _chdoormake_entrypoint_5(door, 0x3FC00000);
        _chdoormake_entrypoint_8(door, 0xE);
    }
}

// TU-NOTE: the overlay .data is defined here in C; the table precedes func_808000D0_chminelobbydoor,
// whose static fills the rest of the .data (source order).
void func_808000A8_chminelobbydoor();
extern int func_80105834();
extern int func_80101870();
extern int func_80107C2C();
s32 func_8080018C_chminelobbydoor();
int D_808001F0_chminelobbydoor[18] = {0xAC02B9,
                                      0x8500004,
                                      0x0,
                                      (u32) func_808000A8_chminelobbydoor,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x40020800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_8080000C_chminelobbydoor,
                                      (u32) func_80107C2C,
                                      -0x7FF7DBEE,
                                      (u32) func_8080018C_chminelobbydoor,
                                      0x0};

void func_808000D0_chminelobbydoor();

void func_808000A8_chminelobbydoor(s32 door)
{
    func_808000D0_chminelobbydoor();
    _chdoor_entrypoint_0(door);
}

// Picks the talk dialogs from the learned moves (bit 0 = 0x15, bit 1 = 0x1A).
void func_808000D0_chminelobbydoor(Actor *door)
{
    static struct {
        s32 w;
        s16 a;
        u16 b;
        s16 rest[16];
    } D_80800238_chminelobbydoor = {0x190, 0xFAA, 0xFAA, 0, 0x101, 0x120A, 0, 0x3F, 0, 0xA, 0x4000};
    s32 moves;

    moves = func_800C6E38(0x15) ? 1 : 0;
    moves += func_800C6E38(0x1A) ? 2 : 0;
    switch (moves) {
        case 0:
        case 2:
            break;
        case 1:
            D_80800238_chminelobbydoor.a = 0xF9F;
            D_80800238_chminelobbydoor.b = 0xFA0;
            break;
        case 3:
            D_80800238_chminelobbydoor.a = 0xFA1;
            D_80800238_chminelobbydoor.b = 0xFA1;
    }
    _subaddiedialog_entrypoint_7(door, door->position, &D_80800238_chminelobbydoor);
}

// Message 0x2E: finishing dialog 0xFA1 opens the door (message 7 to itself).
s32 func_8080018C_chminelobbydoor(Actor *door, s32 message, DoorEventData data)
{
    if (message == 0x2E) {
        if (data.half[0] == 0xFA1) {
            func_8010108C(door, 7, 0);
            return 1;
        }
        return 1;
    }
    return _chdoor_entrypoint_1(door, message, data.word);
}
