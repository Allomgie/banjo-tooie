#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern f32 func_8009C150(PlayerState *);
extern f32 func_800964DC(PlayerState *);
extern s32 D_80801110_bsjump[];
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8009BB24();
extern s32 D_80801120_bsjump[];
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_80801130_bsjump[];
extern f32 func_8009F308(PlayerState *);
extern s32 D_80801140_bsjump[];
extern void baanim_playForDuration_loop(PlayerState *, s32, f32);
extern void func_80093360(PlayerState *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern f32 func_8009BFD8(PlayerState *);
extern void func_8009BF5C(PlayerState *, f32);
extern s32 D_80801150_bsjump[];

void func_80800000_bsjump(int player)
{
    func_8009D7A4(player, 0x3F68F5C3, 0x3F8B851F);
}

// Normal jump: entry.
void bsjump_entrypoint_0(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 prev_state;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    player->unk164.word = baflag_isTrue(player, 2) && !func_8008E23C(player);
    prev_state = bs_getPreviousState(player);
    if (func_8009CBDC(player, prev_state) == 0xA)
        func_80098840(player);
    if (prev_state == 0x11) {
        anctrl_setSubrange(anim_ctrl, 0.0f, 0.6667f);
        anctrl_setStart(anim_ctrl, 0.5042f);
        anctrl_setDuration(anim_ctrl, 8.0f);
        anctrl_setPlaybackType(anim_ctrl, 1);
        player->unk15C.word = 1;
    } else {
        player->unk160.word = func_8009CA70(player, prev_state, 1);
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, 8);
        anctrl_setDuration(anim_ctrl, 1.9f);
        func_8008B1C8(anim_ctrl, 0.134f);
        anctrl_setStart(anim_ctrl, 0.3f);
        anctrl_setSubrange(anim_ctrl, 0.0f, 0.5042f);
        anctrl_setPlaybackType(anim_ctrl, 1);
        anctrl_start(anim_ctrl);
        func_8009FFD8(player, 1, 1, 3, 6);
        if (bastick_distance(player) != 0.0f)
            yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
        baphysics_set_target_yaw(player, yaw_getIdeal(player));
        _bswalk_entrypoint_1(player);
        baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                          baphysics_get_target_horizontal_velocity(player));
        if (player->unk160.word)
            baphysics_set_vertical_velocity(player, 610.0f);
        else
            baphysics_set_vertical_velocity(player, 710.0f);
        baphysics_set_gravity(player, -1350.0f);
        player->unk15C.word = 0;
        if (player->unk164.word)
            func_8009DE38(player, 0x422, 1.0f);
        else
            func_80800000_bsjump((int) player);
    }
}

// Normal jump: per-frame update and state transitions.
void bsjump_entrypoint_1(PlayerState *player)
{
    s32 next_state = 0;
    Vec3f unk_0;
    f32 height_diff;

    if (*(s32 *) ((u8 *) player + 0x164)) {
        func_8009FC80();
    }
    if (baflag_isTrue(player, 0xF)) {
        func_8009B7C0(player);
    } else {
        _bswalk_entrypoint_1(player);
    }
    func_8009BB24(player, unk_0.f);
    if ((bakey_released(player, 8) && unk_0.pos.y > 0.0f &&
         *(s32 *) ((u8 *) player + 0x164) == 0) ||
        !func_8008D544(player)) {
        baphysics_reset_gravity(player);
    }
    switch (*(s32 *) ((u8 *) player + 0x15C)) {
        case 0:
            if (baanim_isStopped(player)) {
                baanim_setEndAndDuration(player, 0.6667f, 4.0f);
                *(s32 *) ((u8 *) player + 0x15C) = 1;
            }
            if (func_8008DF8C(player, 0x82)) {
                baanim_setEndAndDuration(player, 1.0f, 1.4f);
                *(s32 *) ((u8 *) player + 0x15C) = 2;
            }
            break;
        case 1:
            if (baanim_isStopped(player)) {
                next_state = 0x2F;
            }
            if (*(s32 *) ((u8 *) player + 0x164)) {
                *(s32 *) ((u8 *) player + 0x164) = 0;
                next_state = 0x21;
            }
            if (func_8008DF8C(player, 0x5A)) {
                baanim_setEndAndDuration(player, 1.0f, 2.0f);
                *(s32 *) ((u8 *) player + 0x15C) = 2;
            }
        case 2:
            break;
    }
    if (func_8008E260(player)) {
        next_state = 0x3D;
    }
    if (bakey_released(player, 8)) {
        *(s32 *) ((u8 *) player + 0x164) = 0;
    }
    switch (func_800A3274(player)) {
        case 1:
            if (bainput_func_80097DF4(player)) {
                next_state = 0x10;
            }
            if (bainput_func_80097F08(player)) {
                height_diff = func_8009C150(player) - func_800964DC(player);
                if ((*(s32 *) ((u8 *) player + 0x160) && ((height_diff > 2.0f) != 0)) ||
                    *(s32 *) ((u8 *) player + 0x160) == 0) {
                    next_state = 0x11;
                }
            }
            if (bainput_should_beak_bust(player)) {
                next_state = 0xF;
            }
            break;
        case 10:
            if (bainput_func_80097EC8(player)) {
                next_state = 0xE4;
            }
    }
    if (func_8008DA24(player)) {
        next_state = 0xA8;
    }
    if (player_isStable(player)) {
        func_8009FE58(player);
        if (baphysics_get_target_horizontal_velocity(player) != 0.0f) {
            next_state = 4;
        } else {
            next_state = 0x20;
        }
    }
    if (unk_0.pos.y < 0.0f && player_inWater(player)) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

int bsjump_entrypoint_2(Actor *player)
{
    if (func_800C6E38(0xA)) {
        func_800C6DA0(0x3C);
    }
    if (bs_getNextState(player) != 0x11) {
        baphysics_reset_gravity(player);
    }
}

int bsjump_entrypoint_3(s32 index)
{
    return D_80801110_bsjump[index];
}

// Short hop / ledge jump-off: entry.
void bsjump_entrypoint_4(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (baflag_isTrue(player, 7)) {
        if (baphysics_get_vertical_velocity(player) > 700.0f)
            baphysics_set_vertical_velocity(player, 700.0f);
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0xB0);
    func_8008B1C8(anim_ctrl, 0.3f);
    anctrl_setDuration(anim_ctrl, 0.38f);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    player->unk15C.word = 0;
}

void bsjump_entrypoint_5(u8 *player)
{
    s32 next_state;
    s32 anim_ctrl;
    s32 unk_0;
    s32 unk_1;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if (baflag_isTrue(player, 0xF) != 0) {
        func_8009B7C0(player);
    } else {
        _bswalk_entrypoint_1(player);
    }
    // Matching: the odd pointer arithmetic on unk_0 is needed for the match.
    func_8009BB24(player, (s32 *) ((s8 *) &unk_0 - 8));
    switch (*(s32 *) ((s8 *) player + 0x15C)) {
        case 1:
            break;
        case 0:
            if (func_8008DF8C(player, 0x5A) != 0) {
                anctrl_reset(anim_ctrl);
                anctrl_setIndex(anim_ctrl, 8);
                anctrl_setStart(anim_ctrl, 0.6667f);
                anctrl_setDuration(anim_ctrl, 2.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                anctrl_start(anim_ctrl);
                *(s32 *) ((s8 *) player + 0x15C) = 1;
            }
    }
    if (baflag_isFalse(player, 0xF) != 0) {
        if (func_8008E260(player) != 0) {
            next_state = 0x3D;
        }
        unk_1 = func_800A3274(player);
        switch (unk_1) {
            case 1:
                if ((bainput_func_80097DF4(player) != 0) && (baflag_isFalse(player, 5) != 0)) {
                    next_state = 0x10;
                }
                if (bainput_func_80097F08(player) != 0) {
                    next_state = 0x11;
                }
                if (bainput_should_beak_bust(player) != 0) {
                    next_state = 0xF;
                }
                break;
            case 10:
                if (bainput_func_80097EC8(player) != 0) {
                    next_state = 0xE4;
                }
        }
        if (func_8008DA24(player) != 0) {
            next_state = 0xA8;
        }
        if (player_inWater(player) != 0) {
            next_state = 0x4C;
        }
    } else if ((player_inWater(player) != 0) &&
               ((func_800A046C(player), (baflag_isTrue(player, 6) != 0)) ||
                (baflag_isTrue(player, 0x14) != 0))) {
        next_state = 0xD;
    }
    if (player_isStable(player) != 0) {
        func_8009FE58(player);
        next_state = 0x20;
    }
    bs_setState(player, next_state);
}

void bsjump_entrypoint_6(s32 arg0)
{
}

int bsjump_entrypoint_7(s32 index)
{
    return D_80801120_bsjump[index];
}

// Forced-direction jump: entry.
void bsjump_entrypoint_8(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_80098840(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 8);
    anctrl_setDuration(anim_ctrl, 1.9f);
    func_8008B1C8(anim_ctrl, 0.134f);
    anctrl_setStart(anim_ctrl, 0.3f);
    anctrl_setSubrange(anim_ctrl, 0, 0.5042f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 1);
    func_8009D2D8(player, 3);
    baphysics_set_type(player, 3);
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    baphysics_set_target_horizontal_velocity(player, 120.0f);

    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 710.0f);
    baphysics_set_gravity(player, -1350.0f);
    func_800961AC(player, 6);
    player->unk15C.word = 0;
    func_80800000_bsjump(player);
}

void bsjump_entrypoint_9(Actor *player)
{
    s32 next_state;
    void *anim_ctrl;
    f32 unk_0[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_8009BB24(player, unk_0);
    if (unk_0[1] < 0.0f) {
        func_800961AC(player, 1);
    }
    switch (*(s32 *) ((char *) player + 0x15C)) {
        case 2:
            break;
        case 0:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 0.6667f);
                anctrl_setDuration(anim_ctrl, 4.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(s32 *) ((char *) player + 0x15C) = 1;
            }
            if (func_8008DF8C(player, 0x82) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 1.4f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(s32 *) ((char *) player + 0x15C) = 2;
            }
            break;
        case 1:
            if (func_8008DF8C(player, 0x5A) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 2.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(s32 *) ((char *) player + 0x15C) = 2;
            }
    }
    if (func_8008DA24(player) != 0) {
        next_state = 0xA8;
    }
    if (player_isStable(player) != 0) {
        func_8009FE58(player);
        next_state = 0x20;
    }
    bs_setState(player, next_state);
}

void bsjump_entrypoint_10(s32 player)
{
    func_800961AC(player, 0x1);
    baphysics_reset_gravity(player);
}

int bsjump_entrypoint_11(s32 index)
{
    return D_80801130_bsjump[index];
}

// Hover/held jump: entry.
void bsjump_entrypoint_12(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 smooth_transition;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    smooth_transition = 1;
    if (bs_getPreviousState(player) == 0x12)
        smooth_transition = 0;
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, smooth_transition);
    anctrl_setIndex(anim_ctrl, 8);
    func_8008B1C8(anim_ctrl, 0.3f);
    anctrl_setDuration(anim_ctrl, 1.9f);
    anctrl_setStart(anim_ctrl, 0.6667f);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_start(anim_ctrl);
    yaw_setIdeal(player, func_8009F308(player));
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 1);
    func_8009D2D8(player, 3);
    baphysics_set_type(player, 6);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009BA9C(player, 0);
    player->unk15C.word = 0;
    func_8008E944(player);
}

void bsjump_entrypoint_13(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 unk_0[3];
    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_8009BB24(player, unk_0);
    switch (player->unk15C.word) {
        case 0:
            if (func_8008DF8C(player, 0x5A)) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 2.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                player->unk15C.word = 1;
            }
        case 1:
            break;
    }
    if (player_isStable(player))
        next_state = 1;
    bs_setState(player, next_state);
}

void bsjump_entrypoint_14()
{
    func_8008E95C();
}

int bsjump_entrypoint_15(s32 index)
{
    return D_80801140_bsjump[index];
}

s32 bsjump_entrypoint_16(s32 player)
{
    return *(s32 *) (player + 0x160);
}

// Fall-landing bounce: entry.
void bsjump_entrypoint_17(PlayerState *player)
{
    baanim_playForDuration_loop(player, 0x68, 0.35f);
    func_8009FFD8(player, 1, 1, 3, 6);
    func_80093360(player, 60.0f);
    if (func_8009557C(player) == 1) {
        _batimer_set(player, 0, 0.5f);
        _batimer_set(player, 1, 0.41f);
        func_8009DF18(player, 0x439, 1.0f, 0x55F0);
    } else {
        _batimer_set(player, 0, 0.0f);
        _batimer_set(player, 1, 0.01f);
    }
    player->unk15C.word = 0;
}

void bsjump_entrypoint_18(PlayerState *player)
{
    s32 next_state = 0;
    if (_batimer_decrement(player, 1))
        func_8009DF18(player, 0x446, 1.0f, 32000);
    _batimer_decrement(player, 0);
    _bswalk_entrypoint_1(player);
    if (_batimer_isZero(player, 1))
        func_8009BF5C(player, func_8009BFD8(player) + 20.0f);
    if (_batimer_isNonzero(player, 0)) {
        switch (func_800A3274(player)) {
            case 1:
                if (bainput_func_80097DF4(player))
                    next_state = 0x10;
                if (bainput_func_80097F08(player))
                    next_state = 0x11;
                if (bainput_should_beak_bust(player))
                    next_state = 15;
                break;
            case 10:
                if (bainput_func_80097EC8(player))
                    next_state = 0xE4;
        }
    }
    if (player_inWater(player))
        next_state = 0x4C;
    if (player_isStable(player))
        next_state = 0x72;
    bs_setState(player, next_state);
}

void bsjump_entrypoint_19(PlayerState *player)
{
    switch (bs_getNextState(player)) {
        case 0xF:
        case 0x10:
        case 0x11:
            func_80095588(player, 3);
    }
    func_800A042C(player);
    func_80093360(player, 0.0f);
    func_8009E0DC(player);
}

int bsjump_entrypoint_20(s32 index)
{
    return D_80801150_bsjump[index];
}

// TU-NOTE: the overlay .data tables are defined in C here; IDO schedules some functions differently otherwise. Values are from the ROM.
extern void _bsjump_entrypoint_2();
extern void _bsjump_entrypoint_0();
extern void _bsjump_entrypoint_1();
extern void func_80099B94();
extern void _bsjump_entrypoint_6();
extern void _bsjump_entrypoint_4();
extern void _bsjump_entrypoint_5();
extern void _bsjump_entrypoint_10();
extern void _bsjump_entrypoint_8();
extern void _bsjump_entrypoint_9();
extern void _bsjump_entrypoint_14();
extern void _bsjump_entrypoint_12();
extern void _bsjump_entrypoint_13();
extern void func_80099AA8();
extern void _bsjump_entrypoint_19();
extern void _bsjump_entrypoint_17();
extern void _bsjump_entrypoint_18();
s32 D_80801110_bsjump[4] = {(u32) _bsjump_entrypoint_2, (u32) _bsjump_entrypoint_0,
                            (u32) _bsjump_entrypoint_1, (u32) func_80099B94};
s32 D_80801120_bsjump[4] = {(u32) _bsjump_entrypoint_6, (u32) _bsjump_entrypoint_4,
                            (u32) _bsjump_entrypoint_5, (u32) func_80099B94};
s32 D_80801130_bsjump[4] = {(u32) _bsjump_entrypoint_10, (u32) _bsjump_entrypoint_8,
                            (u32) _bsjump_entrypoint_9, (u32) func_80099B94};
s32 D_80801140_bsjump[4] = {(u32) _bsjump_entrypoint_14, (u32) _bsjump_entrypoint_12,
                            (u32) _bsjump_entrypoint_13, (u32) func_80099AA8};
s32 D_80801150_bsjump[4] = {(u32) _bsjump_entrypoint_19, (u32) _bsjump_entrypoint_17,
                            (u32) _bsjump_entrypoint_18, (u32) func_80099B94};
