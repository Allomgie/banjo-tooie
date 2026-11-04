#include "common.h"

extern int D_80800180_chspiralgrill[];
extern u8 D_808001C8_chspiralgrill[];

int *chspiralgrill_entrypoint_0()
{
    return &D_80800180_chspiralgrill;
}

// Spiral Mountain grate hiding the pink Stop 'n' Swop egg; reacts to egg hits.
s32 func_8080000C_chspiralgrill(s32 actor)
{
    func_8010A800(actor, 0);
    func_80109EEC(actor, 0x40);
}

// Egg hit (0x40): shatters the grate, camera shot, sets FLAG_033_PHYSICAL_SM_PinkSnsEggGrateBroken.

int func_8080003C_chspiralgrill(s32 actor, s32 msg, s32 payload)
{
    f32 pos[3];
    s32 unk_0;
    s32 *target;
    s32 exploder;
    switch (msg) {
        case 0x40:
            unk_0 = 0x10;
            func_800EE7F8(pos, (f32 *) ((char *) actor + 0x4));
            func_800EF1B8(pos, *(s32 *) ((char *) actor + 0x48), 0x43960000);
            pos[1] += 120.0f;
            _chexploder_entrypoint_3(actor, pos, 0xC);
            target = _subaddiefind_entrypoint_2(0x51A, 0);
            if (target != 0) {
                unk_0 = 0x11;
            }
            _capod_entrypoint_13(target != 0 ? *target : *(s32 *) ((char *) actor + 0x0),
                                 *(s32 *) ((char *) actor + 0x0), 0x1A, unk_0);
            func_800DA544(0x33);
            goto block_11;
        case 0x90:
            exploder = func_80106790(func_80101080());
            _subaddieaudioquick_entrypoint_2(actor, (f32 *) ((char *) actor + 0x4),
                                             &D_808001C8_chspiralgrill);
            _chexploder_entrypoint_6(exploder, 0x44160000, 0x44480000);
            _chexploder_entrypoint_14(exploder, 3);
            goto block_11;
        default:
            return 0;
    }
block_11:
    return 1;
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800180_chspiralgrill[18] = {0xB04FA,
                                    0x9520001,
                                    0x0,
                                    (u32) func_80102EC0,
                                    (u32) func_80102EC0,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x330000,
                                    0xC00,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_8080000C_chspiralgrill,
                                    (u32) func_80107C2C,
                                    -0x7FFFF400,
                                    (u32) func_8080003C_chspiralgrill,
                                    0x0};
u8 D_808001C8_chspiralgrill[24] = {0x0, 0x13, 0x4, 0xC8, 0x0,  0x16, 0x5D, 0xC0,
                                   0x0, 0x1,  0x0, 0xC8, 0x17, 0x70, 0x0,  0xA,
                                   0x1, 0x4C, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0};
