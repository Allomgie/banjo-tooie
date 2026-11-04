// Probably the GI lobby door: stays shut on entry unless conditions hold, triggers a Mr. Tannoy
// announcement on approach, and opens (message 7) when dialog 0x1370 ends.
#include "common.h"

extern int D_80800160_chfactorylobbydoor[];
extern int _chdoormake_entrypoint_3(s32, f32, s32, s32, s32, s32);
extern s32 D_808001A8_chfactorylobbydoor[];
typedef union {
    s32 word;
    s16 half[2];
} DoorEventData;
extern void func_8010108C(Actor *, s32, s32);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

int chfactorylobbydoor_entrypoint_0()
{
    return (int) &D_80800160_chfactorylobbydoor;
}

// Init: keeps the door shut on entry under some conditions, then builds the door.
void func_8080000C_chfactorylobbydoor(s32 door)
{
    if ((func_800EA090() == 1) && ((func_800D0A9C(0x35, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(door, 1);
    }
    if (_chdoormake_entrypoint_3(door, 0, 0x42B40000, 0x43480000, 8, -1) != 0) {
        _chdoormake_entrypoint_5(door, 0x3FC00000);
        _chdoormake_entrypoint_8(door, 0x5);
    }
}

void func_808000A8_chfactorylobbydoor(s32 door)
{
    func_808000D0_chfactorylobbydoor();
    _chdoor_entrypoint_0(door);
}

// Mr. Tannoy announcement when the player approaches.
int func_808000D0_chfactorylobbydoor(s32 actor)
{
    s32 started;
    started = _subaddiedialog_entrypoint_7(actor, actor + 4, &D_808001A8_chfactorylobbydoor);
    if (started != 0) {
        _chmrtannoy_entrypoint_0();
    }
}

// Dialog 0x1370 (message 0x2E) opens the door.
s32 func_80800108_chfactorylobbydoor(Actor *actor, s32 msg, DoorEventData data)
{
    if (msg == 0x2E) {
        if (data.half[0] == 0x1370) {
            func_8010108C(actor, 7, 0);
        }
        return 1;
    }
    return _chdoor_entrypoint_1(actor, msg, data.word);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800160_chfactorylobbydoor[18] = {0xAC02C2,
                                         0x84F0004,
                                         0x0,
                                         (u32) func_808000A8_chfactorylobbydoor,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000800,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_8080000C_chfactorylobbydoor,
                                         (u32) func_80107C2C,
                                         -0x7FF7DBEE,
                                         (u32) func_80800108_chfactorylobbydoor,
                                         0x0};
s32 D_808001A8_chfactorylobbydoor[10] = {0x190,   0x13701370, 0x100, 0x12230000, 0xA30000,
                                         0xA4000, 0x0,        0x0,   0x0,        0x0};
