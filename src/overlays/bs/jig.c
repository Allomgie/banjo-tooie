// Jiggy celebration player states: the classic jiggy dance driving chjigsawdance with jingle
// and fanfare, and a shorter celebration that follows it.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern u8 D_8012762C;
extern void *baanim_getAnimCtrlPtr();
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 anctrl_isAt(void *, f32);
extern f32 func_8009F308(PlayerState *);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void _bsjig_entrypoint_2(void);
extern s32 D_808005B0_bsjig[];
extern void anctrl_setDuration(void *, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_808005C0_bsjig[];

int bsjig_entrypoint_0(enum jig_e state)
{
    return state == (enum jig_e) 0x44;
}

void bsjig_entrypoint_1(u8 *player)
{
    s32 anim_ctrl;
    s32 ctrl;
    s32 unk_0;
    ctrl = baanim_getAnimCtrlPtr();
    anim_ctrl = ctrl;
    anctrl_reset(ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x2E);
    anctrl_setDuration(anim_ctrl, 4.3f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    yaw_setIdeal(player, func_8009F308(player));
    func_8009FFD8(player, 1, 1, 3, 2);
    // Matching: the constant product and mask are needed for the match.
    baphysics_set_target_horizontal_velocity(player, (0 * 23) * (2 & 0xFFFFFFFFFFFFFFFFu));
    unk_0 = func_800D0018(1, D_8012762C) != 0;
    // Matching: redundant reassignment needed for the match.
    if (unk_0 == 0) {
        unk_0 = 0;
    }
    *(s32 *) ((s8 *) player + 0x160) = unk_0;
    func_800FC660(5, unk_0);
    func_800A4DFC(player, 9);
    func_800C52F4(func_800A4C68(player), 2);
    func_800A0CF4(player, 1);
    func_8009DE38(player, 0x422, 1.0f);
    baflag_clear(player, 7);
    baflag_clear(player, 0xF);
    func_8008E944(player);
    _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(player)), 1);
    // Matching: multiplying by 0 is needed for the match.
    *(s32 *) ((s8 *) player + 0x15C) = anim_ctrl * 0;
}

void bsjig_entrypoint_2(void)
{
    s32 unk_0;
    s32 unk_1;

    unk_1 = func_800F53D0();
    // Matching: the copy is needed for the match.
    unk_0 = unk_1;
    if (func_800A32F8(unk_1) != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(unk_0)), 4);
    }
}

void bsjig_entrypoint_3(PlayerState *player)
{
    s32 next_state = 0;
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    yaw_setIdeal(player, func_8009F308(player));
    if (anctrl_isAt(anim_ctrl, 0.6502f)) {
        func_8009D874(player);
    }
    if (anctrl_isAt(anim_ctrl, 0.835f)) {
        player->unk15C.word++;
        func_8009DE38(player, 0x434, 1.3f);
    }
    if (anctrl_isAt(anim_ctrl, 0.94f)) {
        func_8009DE38(player, 0x3EA, 1.0f);
    }
    if (anctrl_isStopped(anim_ctrl)) {
        if (player->unk160.word) {
            next_state = 0x34;
        } else {
            next_state = 1;
        }
    }
    func_8009919C(player, _bsjig_entrypoint_2, player->unk184);
    bs_setState(player, next_state);
}

void bsjig_entrypoint_4(player) Actor *player;
{
    s32 held_actor;
    held_actor = func_800A32F8();
    if (held_actor != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(held_actor), 5);
        func_800A34D8(player, 0);
    }
}

int bsjig_entrypoint_5(Actor *player)
{
    bsjig_entrypoint_4();
    func_800A0CF4(player, 0);
    func_800A4E30(player);
    func_800C53EC(func_800A4C68(player), 2);
    func_8008E95C(player);
    func_8009CEE8(player);
}

int bsjig_entrypoint_6(s32 index)
{
    return D_808005B0_bsjig[index];
}

s32 bsjig_entrypoint_7(Actor *player)
{
    if (func_8009E6EC() == 0x26) {
        func_80099B94(player);
    } else {
        func_80099AA8(player);
    }
}

int bsjig_entrypoint_8(Actor *player)
{
    s32 player_addr;
    // Matching: the int copy is needed for the match.
    player_addr = (s32) player;
    func_8008E95C(player_addr);
    func_800A0CF4(player_addr, 0);
    func_800A4E30(player_addr);
    func_800C53EC(func_800A4C68(player_addr), 2);
    func_8009CEE8(player_addr);
}

void bsjig_entrypoint_9(PlayerState *player)
{
    void *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    player->unk164.word = bs_getPreviousState(player) == 0x44;
    baflag_clear(player, 0x1A);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x282);
    anctrl_setDuration(anim_ctrl, 3.6f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    yaw_setIdeal(player, func_8009F308(player));
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800FC660(0x1B);
    func_800A4DFC(player, 9);
    func_800C52F4(func_800A4C68(player), 2);
    func_800A0CF4(player, 1);
    func_8009DE38(player, 0x422, 1.0f);
    func_8008E944(player);
}

int bsjig_entrypoint_10(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if ((baanim_isAt(player, 0x3F170A3D) != 0) || (baanim_isAt(player, 0x3F570A3D) != 0)) {
        func_8009DF18(player, 0x3EA, 0x3F800000, 0x7530);
    }
    if (baanim_isStopped(player) != 0) {
        next_state = 1;
    }
    return bs_setState(player, next_state);
}

int bsjig_entrypoint_11(s32 index)
{
    return D_808005C0_bsjig[index];
}

// TU-NOTE: the overlay .data tables are defined in C here; IDO schedules some functions differently otherwise. Values are from the ROM.
extern void _bsjig_entrypoint_5();
extern void _bsjig_entrypoint_1();
extern void _bsjig_entrypoint_3();
extern void _bsjig_entrypoint_7();
extern void _bsjig_entrypoint_8();
extern void _bsjig_entrypoint_9();
extern void _bsjig_entrypoint_10();
s32 D_808005B0_bsjig[4] = {(u32) _bsjig_entrypoint_5, (u32) _bsjig_entrypoint_1,
                           (u32) _bsjig_entrypoint_3, (u32) _bsjig_entrypoint_7};
s32 D_808005C0_bsjig[4] = {(u32) _bsjig_entrypoint_8, (u32) _bsjig_entrypoint_9,
                           (u32) _bsjig_entrypoint_10, (u32) _bsjig_entrypoint_7};
