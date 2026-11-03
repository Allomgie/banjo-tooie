// TU-NOTE: the overlay .data (D_808003D0_bscrashout) is defined in this file. It points at
// functions of this file; IDO schedules some of them differently unless they share the unit.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 yaw_getIdeal(void *);
extern void baphysics_set_target_yaw(void *, f32);
extern f32 func_80099A34(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_applyIdeal(PlayerState *);
extern void func_8009D89C(PlayerState *, f32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void func_800F1574(f32 *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 baanim_isAt(PlayerState *, f32);
extern s32 D_808003D0_bscrashout[];
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);

// Sounds at set anim points, plus dust early in the anim.
void func_80800000_bscrashout(player) PlayerState *player;
{
    if (baanim_isAt(player, 0.3659f)) {
        func_8009DB04(player, 0x417, 1.0f, 0x36B0);
    }
    if (baanim_isAt(player, 0.6862f)) {
        func_8009DB04(player, 0x417, 0.8f, 0x4650);
        func_8009DB04(player, 0x427, 1.0f, 0x55F0);
    }
    if (baanim_getTimer(player) < 0.8f) {
        _badust_entrypoint_9(player);
    }
}

// Sub-state switch: 1 = crash anim, 2 = get up, 3 = death.
void func_808000B0_bscrashout(u8 *player, s32 state)
{
    *(s32 *) ((s8 *) player + 0x15C) = state;
    switch (state) {
        case 1:
            baanim_playForDuration_onceSmooth(player, 0x3E, 0x3FB33333);
            func_8009FFD8(player, 1, 3, 3, 3);
            baphysics_set_target_yaw(player, yaw_getIdeal(player));
            baphysics_set_target_horizontal_velocity(player, *(f32 *) ((s8 *) player + 0x16C));
            baphysics_set_horizontal_velocity(player, 0x42C80000,
                                              *(s32 *) ((s8 *) player + 0x16C));
            return;
        case 2:
            func_800951B4(player);
            baanim_playForDuration_onceSmooth(player, 0xD2, 0x40100000);
            return;
        case 3:
            func_800A0180(player);
            func_800A4DFC(player, 0xA);
            _ncbadie_entrypoint_3(func_800A4CA8(player), 0x41F00000);
            _basudie_entrypoint_1(player);
            _batimer_set(player, 0, 0x404CCCCD);
    }
}

void bscrashout_entrypoint_0(s32 player)
{
    func_8009BD88();
    func_8008E95C(player);
    func_800951B4(player);
}

void bscrashout_entrypoint_1(PlayerState *player)
{
    yaw_setIdeal(player, func_80099A34(player));
    yaw_applyIdeal(player);
    func_8009D89C(player, 1.0f);
    _bamotor_entrypoint_1(player, 1.0f, 0.5f, 0.5f);
    func_8008E944(player);
    func_8009514C(player);
    player->unk15C.word = 0;
    player->unk16C = 600.0f;
    func_808000B0_bscrashout(player, 1);
}

void bscrashout_entrypoint_2(PlayerState *player)
{
    s32 next_state = 0;
    func_800F1574(&player->unk16C, func_800D8FF8() * 300.0f);
    baphysics_set_target_horizontal_velocity(player, *(f32 *) &player->unk16C);
    switch (player->unk15C.word) {
        case 1:
            func_80800000_bscrashout(player);
            if (baanim_isAt(player, 0.2f) && !func_800A1718(player))
                func_808000B0_bscrashout(player, 3);
            if (baanim_isStopped(player))
                func_808000B0_bscrashout(player, 2);
            break;
        case 2:
            if (baanim_isStopped(player))
                next_state = 1;
            break;
        case 3:
            func_80800000_bscrashout(player);
            if (_batimer_decrement(player, 0))
                _basudie_entrypoint_0(player);
    }
    bs_setState(player, next_state);
}

int bscrashout_entrypoint_3(s32 index)
{
    return D_808003D0_bscrashout[index];
}

extern void _bscrashout_entrypoint_0();
extern void _bscrashout_entrypoint_1();
extern void _bscrashout_entrypoint_2();
extern void func_80099AA8();
s32 D_808003D0_bscrashout[4] = {(u32) _bscrashout_entrypoint_0, (u32) _bscrashout_entrypoint_1,
                                (u32) _bscrashout_entrypoint_2, (u32) func_80099AA8};
