#include "common.h"

#define DOOR_EVENT_DATA_DEFINED
extern int D_808001F0_chminelobbydoor[];
extern int _chdoormake_entrypoint_3(s32, f32, s32, s32, s32, s32);
extern s32 func_800C6E38(s32);
extern void _subaddiedialog_entrypoint_7(Actor *, f32 *, void *);
typedef union { s32 word; s16 half[2]; } DoorEventData;
extern void func_8010108C(Actor *, s32, s32);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

int chminelobbydoor_entrypoint_0()
{
    return (int)&D_808001F0_chminelobbydoor;
}

void func_8080000C_chminelobbydoor(s32 param_0) {
    if ((func_800EA090() == 1) && ((func_800D0A9C(0xF, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(param_0, 1);
    }
    if (_chdoormake_entrypoint_3(param_0, 0, 0x42B40000, 0x43480000, 8, -1) != 0) {
        _chdoormake_entrypoint_5(param_0, 0x3FC00000);
        _chdoormake_entrypoint_8(param_0, 0xE);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mine/lobbydoor.data.s) is defined here in C;
 * the table precedes func_808000D0_chminelobbydoor, whose static fills the rest of the .data (source order). */
void func_808000A8_chminelobbydoor();
extern int func_80105834();
extern int func_80101870();
void func_8080000C_chminelobbydoor();
extern int func_80107C2C();
s32 func_8080018C_chminelobbydoor();
int D_808001F0_chminelobbydoor[18] = { 0xAC02B9, 0x8500004, 0x0, (u32)func_808000A8_chminelobbydoor, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x40020800, 0x0, 0x0, 0x0, (u32)func_8080000C_chminelobbydoor, (u32)func_80107C2C, -0x7FF7DBEE, (u32)func_8080018C_chminelobbydoor, 0x0 };

void func_808000D0_chminelobbydoor();

void func_808000A8_chminelobbydoor(s32 arg0)
{
    func_808000D0_chminelobbydoor();
    _chdoor_entrypoint_0(arg0);
}
void func_808000D0_chminelobbydoor(Actor *param_0)
{
    static struct { s32 w; s16 a; u16 b; s16 rest[16]; } D_80800238_chminelobbydoor = { 0x190, 0xFAA, 0xFAA, 0, 0x101, 0x120A, 0, 0x3F, 0, 0xA, 0x4000 };
    s32 local_0;

    local_0 = func_800C6E38(0x15) ? 1 : 0;
    local_0 += func_800C6E38(0x1A) ? 2 : 0;
    switch (local_0) {
    case 0:
    case 2: break;
    case 1:
        D_80800238_chminelobbydoor.a = 0xF9F;
        D_80800238_chminelobbydoor.b = 0xFA0;
        break;
    case 3:
        D_80800238_chminelobbydoor.a = 0xFA1;
        D_80800238_chminelobbydoor.b = 0xFA1;
        break;
    }
    _subaddiedialog_entrypoint_7(param_0, param_0->position, &D_80800238_chminelobbydoor);
}

s32 func_8080018C_chminelobbydoor(Actor *param_0, s32 param_1, DoorEventData param_2)
{
    if (param_1 == 0x2E) {
        if (param_2.half[0] == 0xFA1) {
            func_8010108C(param_0, 7, 0);
            return 1;
        }
        return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
}
