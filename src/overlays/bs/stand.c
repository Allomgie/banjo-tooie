// Banjo-Kazooie idle ("stand") state: idle fidget sequences with sound and rumble cues, turning
// in place, transitions to walk/run/crouch/jump/swim, a landing recovery state and drone wrappers.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
void baphysics_set_target_horizontal_velocity(s32, f32);

extern s32 D_80800D90_bsstand[];
extern void func_8009DF58(Actor *, s32, f32);
extern void _bamotor_entrypoint_1(Actor *, f32, f32, f32);
extern void func_8009514C(Actor *);
extern void func_800951B4(Actor *);
extern void func_800909EC(Actor *);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009DF94(PlayerState *, s32, f32, s32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_80090A2C();
extern void func_800A0CF4();
extern s32 D_80800D98_bsstand[];
extern s32 D_80800DA8_bsstand[];
extern s32 D_80800DB8_bsstand[];

// Returns the idle fidget sequence table selected for this actor.
u8 *func_80800000_bsstand(Actor *actor)
{
    return D_80800D90_bsstand[*(s32 *) ((char *) actor + 0x160)];
}

// Advances the sequence index, wrapping at the sequence length.
s32 func_80800018_bsstand(u8 *actor, s32 index)
{
    index++;
    if (index >= *(s32 *) (actor + 0x164)) {
        index = 0;
    }
    return index;
}

// Standing transition check: stick zone, buttons, first person, water.
s32 func_80800038_bsstand(player, default_state)
s32 player;
s32 default_state;
{
    s32 next_state;
    next_state = default_state;
    switch (bastick_getZone()) {
        case 1:
            next_state = 0x1F;
            break;

        case 2:
            next_state = 2;
            break;

        case 3:
            next_state = 3;
            break;

        case 4:
            next_state = 4;
    }

    if (bakey_held(player, 1) != 0) {
        next_state = 7;
    }
    if (bakey_pressed(player, 9) != 0) {
        next_state = func_800A055C(player, next_state);
    }
    if (bakey_pressed(player, 8) != 0) {
        next_state = bs_getTypeOfJump(player);
        if (func_8008D714(player) != 0) {
            next_state = 0xB8;
            goto block_18;
        }
        if (func_8008D790(player) != 0) {
            _baduo_entrypoint_12(player);
            // Matching: empty block steers IDO's register allocation.
            if ((!player && !player) && 0) {
            }
            return 0;
        }
    }
block_18:
    if (bainput_should_enter_first_person(player) != 0) {
        next_state = _badrone_entrypoint_24(player);
    }

    if (func_8008E148(player) != 0) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player) != 0) {
        next_state = 0x2D;
    }
    return func_800A02DC(player, next_state);
}

// Enter: start the idle animation and pick the fidget sequence set.
void bsstand_entrypoint_0(u8 *player)
{
    s32 last_state;
    int one;
    s32 prev_state;
    prev_state = bs_getPreviousState();
    last_state = prev_state;
    if (func_8009CBDC(player, prev_state) == 0xA) {
        func_80098840(player);
    }
    // Matching: extra temporary for the constant 1.
    one = 1;
    if (last_state == 0x5B) {
        baanim_playForDuration_once(player, 0x6F, 0x40B00000);
    } else {
        baanim_playForDuration_onceSmooth(player, 0x6F, 5.5f);
    }
    func_8009FFD8(player, one, 1, 1, 2);
    // Matching: the masked zero is needed for the match.
    baphysics_set_target_horizontal_velocity(player, 0 & 0xFFFFFFFFFFFFFFFFu);
    func_800909CC(player);
    if (func_8008E23C(player) != 0) {
        *(s32 *) ((s8 *) player + 0x160) = 0;
        *(s32 *) ((s8 *) player + 0x164) = 6;
    } else {
        *(s32 *) ((s8 *) player + 0x160) = 1;
        *(s32 *) ((s8 *) player + 0x164) = 0x15;
    }
    *(s32 *) ((s8 *) player + 0x15C) = 0;
    *(s32 *) ((s8 *) player + 0x168) = 0;
}

// Per-frame sound, rumble and effect cues for the long fidget animation.
void func_80800274_bsstand(Actor *player, void *anim_ctrl)
{
    if (anctrl_isAt(anim_ctrl, 0.2057f)) {
        func_8009DF94(player, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(player, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(anim_ctrl, 0.2057f)) {
        func_8009514C(player);
    }

    if (anctrl_isAt(anim_ctrl, 0.2555f)) {
        func_8009DF94(player, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(player, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(anim_ctrl, 0.2896f)) {
        func_8009DF94(player, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(player, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(anim_ctrl, 0.3f)) {
        func_8009DF94(player, 0x445, 1.0f, 28000);
    }

    if (anctrl_isAt(anim_ctrl, 0.3607f)) {
        func_800951B4(player);
    }

    if (anctrl_isAt(anim_ctrl, 0.4183f)) {
        func_8009DF58(player, 0x43EF, 1.6f);
    }

    if (anctrl_isAt(anim_ctrl, 0.455f)) {
        func_8009DF58(player, 0x43EF, 1.45f);
    }

    if (anctrl_isAt(anim_ctrl, 0.49f)) {
        func_8009DF58(player, 0x43EF, 1.4f);
    }

    if (anctrl_isAt(anim_ctrl, 0.5397f)) {
        func_800909EC(player);
    }

    if (anctrl_isAt(anim_ctrl, 0.6619f)) {
        func_8009DF94(player, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(player, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(anim_ctrl, 0.6688f)) {
        func_8009514C(player);
    }

    if (anctrl_isAt(anim_ctrl, 0.6964f)) {
        func_8009DF94(player, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(player, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(anim_ctrl, 0.7747f)) {
        func_800951B4(player);
    }

    if (anctrl_isAt(anim_ctrl, 0.7822f)) {
        func_8009DF94(player, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(anim_ctrl, 0.8322f)) {
        func_8009DF94(player, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(anim_ctrl, 0.8669f)) {
        func_8009DF94(player, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(anim_ctrl, 0.9048f)) {
        func_8009DF94(player, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(anim_ctrl, 0.9649f)) {
        func_800909EC(player);
    }
}

// Update: turn in place, run fidget cues, advance the sequence, check transitions.
void bsstand_entrypoint_1(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 start_time;
    s32 seq_flags;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (bastick_getZone(player) == 0 && bastick_distance(player) > 0.0f) {
        player->unk168.word = 1;
        yaw_setUpdateType(player, 3);
        yaw_setVelocityBounded(player, 200.0f, 14.0f);
    } else {
        if (player->unk168.word) {
            yaw_setIdeal(player, yaw_get(player));
        }
        player->unk168.word = 0;
        yaw_setUpdateType(player, 1);
    }
    next_state = func_80800038_bsstand(player, 0);
    seq_flags = func_80800000_bsstand(player)[player->unk15C.word];
    if (seq_flags & 8) {
        if (seq_flags & 4) {
            if (anctrl_isAt(anim_ctrl, 0.0909f)) {
                func_8009D874(player);
            }
            if (anctrl_isAt(anim_ctrl, 0.0909f)) {
                func_800A0CF4(player, 1);
            }
            if (anctrl_isAt(anim_ctrl, 0.6818f)) {
                func_800A0CF4(player, 0);
            }
        }
        if (seq_flags & 2) {
            if (anctrl_isAt(anim_ctrl, 0.7727f)) {
                func_800A0CF4(player, 1);
            }
            if (anctrl_isAt(anim_ctrl, 0.9999f)) {
                func_800A0CF4(player, 0);
            }
        }
    } else if (seq_flags & 0x20) {
        if (anctrl_getIndex(anim_ctrl) == 0x95) {
            func_80800274_bsstand(player, anim_ctrl);
            if (anctrl_isAt(anim_ctrl, 0.37f)) {
                anctrl_reset(anim_ctrl);
                func_8008B1C8(anim_ctrl, 0.1f);
                anctrl_setIndex(anim_ctrl, 0xF6);
                anctrl_setDuration(anim_ctrl, 5.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                anctrl_start(anim_ctrl);
            }
        } else {
            if (anctrl_isAt(anim_ctrl, 0.069f)) {
                func_8009DF94(player, 0x434, 1.4f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.1677f)) {
                func_8009DF94(player, 0x4454, 1.0f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.2441f)) {
                func_8009DF94(player, 0x4454, 1.03f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.3141f)) {
                func_8009DF94(player, 0x4454, 1.06f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.3859f)) {
                func_8009DF94(player, 0x4454, 1.5f, 32000);
            }
            if (anctrl_isAt(anim_ctrl, 0.414f)) {
                func_8009DF18(player, 0x41E, 1.0f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.6187f)) {
                func_8009DF94(player, 0x445B, 1.7f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.7108f)) {
                func_8009DF94(player, 0x445B, 1.6f, 18000);
            }
            if (anctrl_isAt(anim_ctrl, 0.7927f)) {
                func_8009DF94(player, 0x445B, 1.5f, 18000);
            }
        }
    } else if (seq_flags & 0x10) {
        func_80800274_bsstand(player, anim_ctrl);
    }
    if (anctrl_isAt(anim_ctrl, 0.9999f)) {
        player->unk15C.word = func_80800018_bsstand(player, player->unk15C.word);
        seq_flags = func_80800000_bsstand(player)[player->unk15C.word];
        if (seq_flags & 0x10) {
            baanim_playForDuration_onceSmooth(player, 0x95, 5.5f);
            anctrl_start(anim_ctrl);
            func_800A0CF4(player, 1);
            func_80090A2C(player);
        } else if (seq_flags & 0x40) {
            baanim_playForDuration_onceSmooth(player, 0xAE, 4.3f);
            anctrl_start(anim_ctrl);
            func_800A0CF4(player, 0);
            func_80090A2C(player);
        } else if (seq_flags & 0x20) {
            baanim_playForDuration_onceSmooth(player, 0x95, 5.5f);
            func_800A0CF4(player, 1);
            func_80090A2C(player);
        } else if (seq_flags & 8) {
            if (anctrl_getIndex(anim_ctrl) == 0x6F) {
                start_time = anctrl_getAnimTimer(anim_ctrl);
            } else {
                start_time = 0.0f;
                func_800909CC(player);
            }
            anctrl_reset(anim_ctrl);
            anctrl_setIndex(anim_ctrl, 0x6F);
            anctrl_setDuration(anim_ctrl, 5.5f);
            anctrl_setPlaybackType(anim_ctrl, 2);
            anctrl_setStart(anim_ctrl, start_time);
            anctrl_start(anim_ctrl);
            func_800A0CF4(player, 0);
        }
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    bs_setState(player, next_state);
}

s32 bsstand_entrypoint_2(Actor *actor)
{
    func_800A0CF4(actor, 0);
    func_80090A2C(actor);
    func_800951B4(actor);
}

int bsstand_entrypoint_3(s32 index)
{
    return D_80800D98_bsstand[index];
}

void bsstand_entrypoint_4(Actor *actor)
{
    func_8009FFD8(actor, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(actor, 0 & 0xFFFFFFFFFFFFFFFF);
}

// Landing-recovery state.
void bsstand_entrypoint_5(s32 player)
{
    // Matching: the stack temporaries are needed for the match.
    s32 default_state;
    s32 anim_ctrl;
    s32 ctrl;

    default_state = 0;
    ctrl = baanim_getAnimCtrlPtr(player);
    anim_ctrl = ctrl;
    if (anctrl_getIndex(ctrl) == 0xD2) {
        if (anctrl_isAt(anim_ctrl, 0.8264f) != 0) {
            func_8009DF18(player, 0x449, 1.0f, 0x36B0);
        }
        if (anctrl_isAt(anim_ctrl, 0.8864f) != 0) {
            func_8009DF18(player, 0x449, 1.0f, 0x36B0);
        }
    }
    if (anctrl_isStopped(anim_ctrl) != 0) {
        default_state = 1;
    }
    bs_setState(player, func_80800038_bsstand(player, default_state));
}

void bsstand_entrypoint_6(s32 unk_0)
{
}

int bsstand_entrypoint_7(s32 index)
{
    return D_80800DA8_bsstand[index];
}

void bsstand_entrypoint_8()
{
    func_80800038_bsstand();
}

void bsstand_entrypoint_9()
{
    _bsdrone_entrypoint_0();
}

void bsstand_entrypoint_10(PlayerState *player)
{
    _bsdrone_entrypoint_1(player);
}

void bsstand_entrypoint_11(s32 player)
{
    _bafpctrl_entrypoint_10(player, 0);
    _bsdrone_entrypoint_2(player);
}

int bsstand_entrypoint_12(s32 index)
{
    return D_80800DB8_bsstand[index];
}

// TU-NOTE: the overlay .data is defined here in C. The tables point to functions of this
// file; IDO's assembler schedules some of them differently unless they share the unit.
// Values are taken from the ROM.
extern void _bsstand_entrypoint_2();
extern void _bsstand_entrypoint_0();
extern void _bsstand_entrypoint_1();
extern void func_8009AB78();
extern void _bsstand_entrypoint_6();
extern void _bsstand_entrypoint_4();
extern void _bsstand_entrypoint_5();
extern void _bsstand_entrypoint_11();
extern void _bsstand_entrypoint_9();
extern void _bsstand_entrypoint_10();
extern void _bsdrone_entrypoint_3();
u32 D_80800D70_bsstand[2] = {0x8080840, 0x8080000};
u32 D_80800D78_bsstand[6] = {0x90A0C10, 0x9090A09, 0x20090A0C, 0x1009090A, 0x910090A, 0x20000000};
s32 D_80800D90_bsstand[2] = {(u32) &D_80800D70_bsstand, (u32) &D_80800D78_bsstand};
s32 D_80800D98_bsstand[4] = {(u32) _bsstand_entrypoint_2, (u32) _bsstand_entrypoint_0,
                             (u32) _bsstand_entrypoint_1, (u32) func_8009AB78};
s32 D_80800DA8_bsstand[4] = {(u32) _bsstand_entrypoint_6, (u32) _bsstand_entrypoint_4,
                             (u32) _bsstand_entrypoint_5, (u32) func_8009AB78};
s32 D_80800DB8_bsstand[6] = {(u32) _bsstand_entrypoint_11,
                             (u32) _bsstand_entrypoint_9,
                             (u32) _bsstand_entrypoint_10,
                             (u32) _bsdrone_entrypoint_3,
                             0x0,
                             0x0};
