#include "common.h"

extern int D_808002B0_chshockjump[];
extern int D_808002F8_chshockjump[];
extern void func_800F7B9C();
extern void _chexploder_entrypoint_5(void *param_0, int param_1, void *param_2, int param_3,
                                     float param_4, int param_5);
extern void _subaddieaudioquick_entrypoint_2(void *param_0, void *param_1, void *param_2);
extern u8 *func_80106790();
extern int D_80800340_chshockjump[];
extern f32 func_800F15F8(f32, f32, f32);

int chshockjump_entrypoint_0()
{
    return (int) &D_808002B0_chshockjump;
}

int chshockjump_entrypoint_1()
{
    return (int) &D_808002F8_chshockjump;
}

// Shock Spring Pad messages: 0x90 shatter, 0x91 start shock jump (interrupt 0x49).
int func_80800018_chshockjump(char unk_0, s32 msg_id, s32 sender)
{
    s32 exploder;
    switch (msg_id) {
        case 0x90:
            exploder = func_80106790(func_80101080(sender));
            _chexploder_entrypoint_6(exploder, 0x43C80000, 0x44160000);
            _chexploder_entrypoint_7(exploder, 0xC4160000, 0xC3C80000);
            goto block_6;

        case 0x91:
            func_800F7B9C(sender, 0x49);
            goto block_6;

        default:
            return 0;
    }
block_6:
    return 1;
}

// Flight Pad: message 0x91 starts the flight take-off (interrupt 0x4A).
s32 func_808000AC_chshockjump(s32 unk_0, s32 msg_id, s32 sender)
{
    if (msg_id == 0x91) {
        func_800F7B9C(sender, 0x4A);
    } else {
        return 0;
    }
    return 1;
}

void chshockjump_entrypoint_2(void)
{
    u8 *actor_copy;
    u8 *actor;

    actor = func_80106790();
    actor_copy = actor;
    _chexploder_entrypoint_5(actor, 0x756, actor + 4, *(int *) (actor + 0x48),
                             *(float *) (actor + 0x38), 0xC);
    _subaddieaudioquick_entrypoint_2(actor_copy, actor_copy + 4, &D_80800340_chshockjump);
}

// Draw: glow brighter when the move is learned and the player is Banjo-Kazooie.
void func_80800148_chshockjump(Actor *pad, s32 gfx)
{
    s32 ability;
    s32 alpha;
    s32 target_alpha;

    alpha = _subaddiefade_entrypoint_0(pad);
    if (pad->unk6C_9 == 0x210)
        ability = 13;
    else
        ability = 9;
    if (func_800C6E38(ability) && func_800F64A4(func_800F54E4(), 0x401)) {
        target_alpha = (s32) func_800F15F8((f32) alpha, 255.0f, 5.0f);
    } else {
        target_alpha = (s32) func_800F15F8((f32) alpha, 90.0f, 5.0f);
    }
    _subaddiefade_entrypoint_8(pad, target_alpha);
    func_80101870(pad, gfx);
}

void func_80800228_chshockjump(void *actor)
{
    s32 sect;
    sect = _subaddiesect_entrypoint_1(actor);
    *(s32 *) ((char *) actor + 0x28) = sect;
    if (sect == -1) {
        if (((u32) *(u16 *) ((char *) actor + 0x76) >> 7) != 0x33) {
            func_80102E08(actor);
        }
    } else {
        sect = *(u16 *) ((char *) actor + 0x76);
        _subaddiesect_entrypoint_2(actor, *(s32 *) ((char *) actor + 0x28),
                                   (((u32) sect & 0xFFFFu) >> 7) != 0x33);
    }
    func_8010A654(actor, func_800DA298(0x661));
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808002B0_chshockjump[18] = {0xD40210,
                                  0x6350001,
                                  0x0,
                                  (u32) func_80102EC0,
                                  (u32) func_80105834,
                                  (u32) func_80800148_chshockjump,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x40801800,
                                  0x0,
                                  (u32) func_80108ED0,
                                  0x0,
                                  (u32) func_80800228_chshockjump,
                                  (u32) func_80107C2C,
                                  -0x7FF7D3EE,
                                  (u32) func_80800018_chshockjump,
                                  0x0};
int D_808002F8_chshockjump[18] = {0x450234,
                                  0x6360001,
                                  0x0,
                                  (u32) func_80102EC0,
                                  (u32) func_80105834,
                                  (u32) func_80800148_chshockjump,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x40801800,
                                  0x0,
                                  (u32) func_80108ED0,
                                  0x0,
                                  (u32) func_80800228_chshockjump,
                                  (u32) func_80107C2C,
                                  -0x7FF7D3EE,
                                  (u32) func_808000AC_chshockjump,
                                  0x0};
int D_80800340_chshockjump[8] = {0x13048D, 0xD00D9, 0xF30018, 0x11388, 0x2EE00000, 0x0, 0x0, 0x0};
