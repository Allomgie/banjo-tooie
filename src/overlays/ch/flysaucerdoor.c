// Probably the door that blocks the Saucer of Peril crate, built on chdoormake and opened by a
// switch; on first opening it sets a flag, plays a cutscene and lets the crate continue.

#include "ch/flysaucerdoor.h"

extern int D_80800160_chflysaucerdoor[];
extern u32 D_808001A8_chflysaucerdoor[];

int chflysaucerdoor_entrypoint_0()
{
    return (int) &D_80800160_chflysaucerdoor;
}

int chflysaucerdoor_entrypoint_1()
{
    return (int) &D_808001A8_chflysaucerdoor;
}

// Door setup on top of the generic door maker.
void func_80800018_chflysaucerdoor(Actor *this)
{
    s32 unk_0 = 0x45;
    s32 unk_1 = 0x8;
    _chdoormake_entrypoint_3(this, *(s32 *) ((u8 *) this + 0x48), 0x42B40000, 0x43960000, unk_0,
                             unk_1);
    _chdoormake_entrypoint_5(this, 0x40600000);
    _chdoormake_entrypoint_8(this, 0x10);
}

// Message handler: 7 = switch pressed (sets flag 0xB3, cutscene), 11 = door finished opening.
s32 func_8080006C_chflysaucerdoor(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 7:
            if (!func_800DA9E4(0xB3, 1)) {
                _glcutDll_entrypoint_6(0xD6, 0x25);
                _capod_entrypoint_13(actor->unk0, 0, 3, 0x830);
                _subaddieDll_entrypoint_4(actor, 1);
            }
            return func_80101180(0x30C, msg, arg);
        case 11:
            _glcutDll_entrypoint_17();
            if (func_800DA298(0x91)) {
                _glcutDll_entrypoint_6(0xCA, 0x16);
                return 3;
            }
            _capod_entrypoint_14();
            return 4;
        default:
            return 0;
    }
}

// Door switch.
void func_80800140_chflysaucerdoor(s32 arg0)
{
    _chswitch_entrypoint_14(arg0, FLAG0_008_UNK);
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern void _chswitch_entrypoint_13();
extern void _chswitch_entrypoint_0();
int D_80800160_chflysaucerdoor[18] = {0x2D1030C,
                                      0x76A0001,
                                      0x0,
                                      (u32) _chdoor_entrypoint_0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x5DC0000,
                                      0x0,
                                      0xB30000,
                                      0x80C04,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800018_chflysaucerdoor,
                                      (u32) func_80107C2C,
                                      -0x7FFFDFFE,
                                      (u32) _chdoor_entrypoint_1,
                                      0x0};
u32 D_808001A8_chflysaucerdoor[18] = {0x2D2030D,
                                      0x6850001,
                                      0x8011A298,
                                      (u32) _chswitch_entrypoint_13,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x808,
                                      0x0,
                                      (u32) _chswitch_entrypoint_0,
                                      0x0,
                                      (u32) func_80800140_chflysaucerdoor,
                                      (u32) func_80107C2C,
                                      0x80002C00,
                                      (u32) func_8080006C_chflysaucerdoor,
                                      0x0};
