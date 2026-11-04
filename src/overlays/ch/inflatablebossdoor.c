// Door to Mr. Patch's arena (Big Top), scaled 1.4x. Opens via chdoormake when flag 0x9C is set;
// its state depends on the boss retry flag, whether Banjo-Kazooie are allowed, and replay mode.
#include "ch/inflatablebossdoor.h"

extern s32 D_80800140_chinflatablebossdoor[];

s32 *chinflatablebossdoor_entrypoint_0(void)
{
    return &D_80800140_chinflatablebossdoor;
}

void func_8080000C_chinflatablebossdoor(Actor *door)
{
    s32 retry_flag;
    s32 allow_bk;
    s32 replay;

    // Door state depends on the retry flag, BK allowed and replay mode.
    retry_flag = func_800DA298(FLAG_17F_RETRY_BOSS_MR_PATCH);
    allow_bk = func_800F64A4(func_800F54E4(), ALLOW_BK);
    replay = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80101FDC(door, 1U);
    } else if ((retry_flag == 0) && (replay != 0)) {
        func_80101FDC(door, 4U);
    } else if ((retry_flag != 0) && (allow_bk != 0)) {
        func_80101FDC(door, 1U);
    }
    func_80102FDC(door, door->scale * 1.4f);
    func_8010A800(door, 0);
    // Opens when flag 0x9C is set.
    if (_chdoormake_entrypoint_3(door, 0.0f, 90.0f, 600.0f, 0x822, 0x9C) != 0) {
        _chdoormake_entrypoint_5(door, 4.0f);
        _chdoormake_entrypoint_6(door, 0x3F4CCCCD);
    }
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
s32 D_80800140_chinflatablebossdoor[20] = {0xAC046E,
                                           0x9430001,
                                           0x0,
                                           (u32) _chdoor_entrypoint_0,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x9C0000,
                                           0xC00,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_8080000C_chinflatablebossdoor,
                                           (u32) func_80107C2C,
                                           -0x7FF7D3FE,
                                           (u32) _chdoor_entrypoint_1,
                                           0x0,
                                           0x0,
                                           0x0};
