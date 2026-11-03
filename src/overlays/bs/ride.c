#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void baphysics_set_target_horizontal_velocity(Actor *param_0, f32 param_1);
extern void func_800A34E4(Actor *param_0, s32 param_1);
extern void func_800961AC(Actor *param_0, s32 param_1);
extern void func_8009FFD8(Actor *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern void func_800947EC(Actor *param_0, s32 param_1, s32 param_2);
extern void *func_8009EA64(Actor *param_0);
extern void *_subaddiefind_entrypoint_2(void *param_0, s32 param_1);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern s32 D_808009C0_bsride[];
extern void func_8009D89C(void *, f32);
// Row of the ride animation table, selected by interrupt id.
typedef struct {
    s16 interrupt_id;
    s16 anim_id;
    f32 duration;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    f32 subrange_end;
    f32 trigger_time;
} Mass47Ride;
extern Mass47Ride D_808009D0_bsride[];
extern void func_80093230(s32, f32);
extern int D_80800A70_bsride[];
extern f32 _chhandcart_entrypoint_1(s32);
extern s32 D_80800A80_bsride[];
extern void func_80099B94(void *);
extern int func_8009E6EC();
extern void func_8009E830(void *, int);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void _chflysaucer_entrypoint_0(s32, f32);
extern s32 D_80800A90_bsride[];
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);

// Find the ridden vehicle and lock the player to it.
// Matching: the extra pointer temporary is needed for the match.
void func_80800000_bsride(player) Actor *player;
{
    char *vehicle_slot;
    *(s32 *) (vehicle_slot = (char *) player + 0x15c) =
        *(s32 *) _subaddiefind_entrypoint_2(func_8009EA64(player), 0);
    baphysics_set_target_horizontal_velocity(player, 0);
    func_800A34E4(player, 0);
    func_800961AC(player, 8);
    func_8009FFD8(player, 1, 1, 3, 7);
    func_800947EC(player, 1, 1);
}

int func_8080008C_bsride(player)
PlayerState *player;
{
    player->unk15C.word = 0;
    func_800947EC(player, 1, 0);
    func_800A34E4(player, 1);
    func_800961AC(player, 1);
    baroll_setIdeal(player, 0.0f);
    func_8009BF5C(player, 0.0f);
}

s32 func_808000F0_bsride(s32 player)
{
    func_8009EAE8(0);
    return func_8080008C_bsride(player);
}

s32 func_8080011C_bsride(s32 player)
{
    if (func_8009E6EC() == 0x28) {
        func_808000F0_bsride(player);
        func_8009E830(player, 2);
    } else {
        func_80099B94(player);
    }
}

void func_8080016C_bsride()
{
    func_8080008C_bsride();
}

int func_8080018C_bsride(Actor *player)
{
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(player, 0x256, 0x3F666666);
    func_8009C128(player, (Actor *) ((char *) player + 0x16C));
}

// Scale the ride animation duration by the vehicle's speed.
void func_808001CC_bsride(PlayerState *player)
{
    s32 next_state;
    f32 dist;
    f32 duration;
    f32 delta[3];
    f32 pos[3];

    next_state = 0;
    func_8009C128(player, pos);
    func_800EFB24(delta, pos, &player->unk16C);
    func_800EE7F8(&player->unk16C, pos);
    dist = func_800EEF94(delta);
    duration = func_800F10B4(dist / func_800D8FF8(), 0.0f, 2000.0f, 0.9f, 0.22f);
    anctrl_setDuration(baanim_getAnimCtrlPtr(player), duration);
    if (!player->unk15C.word)
        next_state = 0x2F;
    bs_setState(player, next_state);
}

int bsride_entrypoint_0(s32 idx)
{
    return D_808009C0_bsride[idx];
}

// Interrupt-driven ride animation: look up the interrupt in the table and switch animation.
void func_808002A0_bsride(void *player)
{
    s32 unk_0;
    s32 interrupt;
    void *anim_ctrl;
    s32 same_anim;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    Mass47Ride *row;

    interrupt = func_8009E6EC(player);
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    for (row = D_808009D0_bsride; row->interrupt_id; row++) {
        if (interrupt == row->interrupt_id) {
            same_anim = anctrl_getIndex(anim_ctrl) == row->anim_id;
            unk_1 = row->unk_A == 1 && *(s32 *) ((u8 *) player + 0x160) == 0;
            unk_2 = row->unk_A == 1 && *(s32 *) ((u8 *) player + 0x160) == 1;
            unk_3 = row->unk_A == 0 && *(s32 *) ((u8 *) player + 0x160) == 0;
            unk_0 = row->unk_9 == 1 && row->trigger_time < anctrl_getAnimTimer(anim_ctrl);
            if (unk_1 || (unk_3 && !same_anim) || (unk_2 && unk_0)) {
                anctrl_reset(anim_ctrl);
                anctrl_setIndex(anim_ctrl, row->anim_id);
                anctrl_setDuration(anim_ctrl, row->duration);
                if (row->unk_8 == 1) {
                    anctrl_setPlaybackType(anim_ctrl, 2);
                } else {
                    anctrl_setPlaybackType(anim_ctrl, 1);
                    anctrl_setSubrange(anim_ctrl, 0.0f, row->subrange_end);
                }
                anctrl_start(anim_ctrl);
                if (row->unk_A == 1) {
                    func_8009D89C(player, 1.0f);
                }
                *(s32 *) ((u8 *) player + 0x160) = row->unk_A;
            }
            func_8009E830(player, 2);
            return;
        }
    }
    func_8080011C_bsride(player);
}

void func_808004AC_bsride(s32 player)
{
    func_80093230(player, 1.0f);
    func_8080008C_bsride(player);
}

s32 func_808004D8_bsride(Actor *player)
{
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(player, 0x281, 0x3F333333);
    func_80093230(player, 1.35f);
    *(s32 *) ((char *) player + 0x160) = 0;
}

void func_80800524_bsride(PlayerState *player)
{
    s32 next_state = 0;
    if (*(s32 *) ((u8 *) player + 0x160) == 1 && baanim_isStopped(player)) {
        baanim_playForDuration_loopSmooth(player, 0x281, 0x3F333333);
        *(s32 *) ((u8 *) player + 0x160) = 0;
    }
    if (*(s32 *) ((u8 *) player + 0x15C) == 0) {
        next_state = 0x2F;
    }
    bs_setState(player, next_state);
}

int bsride_entrypoint_1(int idx)
{
    return D_80800A70_bsride[idx];
}

void func_808005B8_bsride()
{
    func_8080008C_bsride();
}

s32 func_808005D8_bsride(s32 player)
{
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(player, 0x83, 0x3FE66666);
}

// Hand-cart ride: pump animation synced to the cart.
void func_8080060C_bsride(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 next_state;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (player->unk15C.word != 0) {
        next_state = 0;
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
        func_8008B10C(anim_ctrl, _chhandcart_entrypoint_1(player->unk15C.word));
    } else {
        next_state = 0x2F;
    }
    bs_setState(player, next_state);
}

s32 func_8080066C_bsride(Actor *player)
{
    if (func_8009E6EC() == 0x28) {
        func_808000F0_bsride(player);
        func_8009E830(player, 2);
    } else {
        func_80099B94(player);
    }
}

int bsride_entrypoint_2(s32 idx)
{
    return D_80800A80_bsride[idx];
}

// Set the flying-saucer aiming mode (0 off, 1 and 2 first-person control).
int func_808006D0_bsride(Actor *player, s32 mode)
{
    s32 *mode_slot = (s32 *) ((char *) player + 0x160);
    *mode_slot = mode;
    if (mode != 0) {
        switch (mode) {
            case 1:
                _bafpctrl_entrypoint_14(player, 1);
                func_800F817C(*(s32 *) ((char *) player + 0x184), 1);
                break;

            case 2:
                _bafpctrl_entrypoint_9(player, 0);
                _bafpctrl_entrypoint_11(player, 0xf, 1);
                _bafpctrl_entrypoint_14(player, 3);
                baflag_set(player, 0x24);
        }

    } else {
        _bafpctrl_entrypoint_14(player, 1);
        _bafpctrl_entrypoint_11(player, 0xf, 0);
        baflag_clear(player, 0x2E);
    }
}

void func_80800798_bsride(Actor *player)
{
    switch (func_8009E6EC()) {
        case 0x28:
            func_808000F0_bsride(player);
            func_8009E830(player, 2);
            return;

        case 0x4B:
            if (*(s32 *) ((u8 *) player + 0x160) == 2) {
                func_808006D0_bsride(player, 1);
                func_8009E830(player, 2);
                return;
            }
            func_808006D0_bsride(player, 2);
            func_8009E830(player, 2);
            return;

        default:
            func_80099B94(player);
    }
}

void func_8080084C_bsride(s32 player)
{
    func_808006D0_bsride(player, 0);
    func_8080008C_bsride(player);
}

// Flying-saucer ride setup.
// Matching: the extra temporaries, the all_ones mask and the (long long) cast are needed for the match.
void func_80800878_bsride(u8 *player)
{
    int all_ones;
    s8 *mode_slot;
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(player, 0x481, 0x3F547AE1);
    func_8009FFD8(player, 1, 1, 3, 7);
    baphysics_set_target_horizontal_velocity(player, (long long) 0);
    func_800A34E4(player, 0);
    func_800961AC(player, 6);
    all_ones = 0xFFFFFFFFu;
    mode_slot = (s8 *) player + 0x160;
    *(s32 *) mode_slot = 0;
    func_808006D0_bsride(player, 1 & all_ones);
}

void func_80800904_bsride(PlayerState *player)
{
    void *anim_ctrl;
    s32 next_state;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    switch (player->unk160.word) {
        case 1:
            break;
        case 2:
            baflag_set(player, 0x2E);
    }
    if (player->unk15C.word) {
        _chflysaucer_entrypoint_0(player->unk15C.word, anctrl_getAnimTimer(anim_ctrl));
    } else
        next_state = 0x2F;
    bs_setState(player, next_state);
}

int bsride_entrypoint_3(s32 idx)
{
    return D_80800A90_bsride[idx];
}

// TU-NOTE: the overlay's .data is defined here in C. The tables hold pointers to functions of
// this file, and IDO's assembler schedules some of them differently unless they are in the same
// unit. Values are taken from the ROM.
s32 D_808009C0_bsride[4] ={(u32) func_8080016C_bsride, (u32) func_8080018C_bsride,
                            (u32) func_808001CC_bsride, (u32) func_8080011C_bsride};
Mass47Ride D_808009D0_bsride[8] = {
    0x74, 0x281, 0.7f,  0x1,  0x0,   0x0,   0x0,  0.0f,  0.0f,  0x75, 0x250, 0.7f,
    0x0,  0x0,   0x0,   0x0,  0.5f,  0.0f,  0x76, 0x251, 0.7f,  0x0,  0x0,   0x0,
    0x0,  0.5f,  0.0f,  0x77, 0x252, 0.7f,  0x0,  0x1,   0x1,   0x0,  1.0f,  0.75f,
    0x78, 0x253, 0.7f,  0x0,  0x1,   0x1,   0x0,  1.0f,  0.75f, 0x79, 0x254, 0.7f,
    0x0,  0x1,   0x1,   0x0,  1.0f,  0.75f, 0x7A, 0x255, 0.7f,  0x0,  0x1,   0x1,
    0x0,  1.0f,  0.75f, 0x0,  0x0,   0.0f,  0x0,  0x0,   0x0,   0x0,  0.0f,  0.0f};
int D_80800A70_bsride[4] = {(u32) func_808004AC_bsride, (u32) func_808004D8_bsride,
                            (u32) func_80800524_bsride, (u32) func_808002A0_bsride};
s32 D_80800A80_bsride[4] = {(u32) func_808005B8_bsride, (u32) func_808005D8_bsride,
                            (u32) func_8080060C_bsride, (u32) func_8080066C_bsride};
s32 D_80800A90_bsride[4] = {(u32) func_8080084C_bsride, (u32) func_80800878_bsride,
                            (u32) func_80800904_bsride, (u32) func_80800798_bsride};
