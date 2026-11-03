#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(s32);
extern s32 bastick_getZone(s32);
extern void baphysics_set_target_horizontal_velocity(s32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void _badata_entrypoint_4(PlayerState *, s32 *, f32 *);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
typedef struct {
    u8 pad_0[0x191];
    u8 curve_type;
} DroneBitten1472;
extern f32 _bamovegoto_entrypoint_3(void *);
extern f32 func_80013970(f32);
extern void func_8008E95C();
extern void func_800961A0();
extern void _bsdronebitten_entrypoint_4(void);
extern void _bsdronebitten_entrypoint_5(void);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void _bamovegoto_entrypoint_8(void *, f32);
extern void _bamovegoto_entrypoint_7(void *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct _AnCtrl AnCtrl;
extern void func_8009DB04(PlayerState *, s32, f32, s32);

// Sets the horizontal velocity from the stick position.
void func_80800000_bsdronebitten(s32 player)
{
    f32 stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 500.0f));
    }
}

void bsdronebitten_entrypoint_0(s32 player)
{
    func_8008E95C();
    bastick_popZone(player);
}

// Mode 1 enter: snapped up in place.
void bsdronebitten_entrypoint_1(PlayerState *player)
{
    f32 duration;
    s32 anim_id;

    _badata_entrypoint_4(player, &anim_id, &duration);
    baanim_playForDuration_loopSmooth(player, anim_id, duration);
    func_8009FFD8(player, 1, 1, 3, 6);
    baphysics_set_vertical_velocity(player, 900.0f);
    baphysics_set_gravity(player, -1200.0f);
    bastick_pushZone(player);
    bastick_setZoneMax(player, 0, 0.12f);
    bastick_setZoneMax(player, 1, 1.0f);
    func_8008E944(player);
    func_8009D9D4(player);
}

void bsdronebitten_entrypoint_2()
{
    func_80099AA8();
}

void bsdronebitten_entrypoint_3(PlayerState *player)
{
    s32 next_state;
    // Matching: unused local is needed for the match.
    s32 unk_0;
    s32 falling;
    next_state = 0;
    func_80800000_bsdronebitten(player);
    if (func_800F64A4(player->unk184, 0x201) && func_8008DA24(player))
        next_state = 0xA8;
    falling = baphysics_get_vertical_velocity(player) < 0.0f;
    if (func_8008DF8C(player, 0x96) || (falling && player_inWater(player)))
        next_state = _badata_entrypoint_24(player);
    bs_setState(player, next_state);
}

// Goto height curve callback: reshapes the progress by curve type.
f32 bsdronebitten_entrypoint_4(u8 *player, f32 progress)
{
    f32 remaining;
    switch (player[0x191]) {
        case 1:
            return progress;

        case 2:
            remaining = 1.0f - progress;
            return 1.0f - remaining * remaining;

        default:
            return progress;
    }
}

// Goto arc callback: curve type 2 adds an arc to the height.
void bsdronebitten_entrypoint_5(DroneBitten1472 *player, f32 *pos, f32 progress)
{
    f32 arc_height;
    switch (player->curve_type) {
        case 1:
            break;

        case 2:
            arc_height =
                (_bamovegoto_entrypoint_3(player) * (func_80013970(progress * 180.0f) * 1.0f)) *
                0.5f;
            pos[1] += arc_height;
    }
}

s32 bsdronebitten_entrypoint_6(Actor *player)
{
    func_800961A0(player, 0);
    func_8008E95C(player);
    _bafpctrl_entrypoint_19(player);
}

// Mode 2 enter: carried along a goto arc to the target point.
void bsdronebitten_entrypoint_7(u8 *player)
{
    f32 distance;
    f32 unk_0;
    s32 anim_id;
    f32 start_pos[3];

    _badata_entrypoint_4(player, &anim_id, &unk_0);
    baanim_playForDuration_loopSmooth(player, anim_id, unk_0);
    func_8009FFD8(player, 1, 1, 3, 2);
    func_8009C128(player, start_pos);
    distance = func_800EEAD4(start_pos, (f32 *) (*(u8 **) (player + 0x54) + 0x34));
    player[0x191] = (*(u8 **) (player + 0x54))[0x30];
    _bamovegoto_entrypoint_0(player);
    if (player[0x191] == 1) {
        _bamovegoto_entrypoint_8(player, 2400.0f);
    } else {
        unk_0 = func_800F10B4(distance, 100.0f, 5000.0f, 0.4f, 4.5f);
        _bamovegoto_entrypoint_7(player, unk_0);
    }
    _bamovegoto_entrypoint_12(player, *(u8 **) (player + 0x54) + 0x34);
    _bamovegoto_entrypoint_11(player, _bsdronebitten_entrypoint_4, _bsdronebitten_entrypoint_5);
    _bamovegoto_entrypoint_13(player);
    func_800961A0(player, 1);
    func_8008E944(player);
    func_8009D9D4(player);
    player[0x190] = 0;
}

void bsdronebitten_entrypoint_8()
{
    func_80099AA8();
}

int func_80800478_bsdronebitten(int player, s32 unk_0)
{
    s32 anim_id;
    s32 player_copy;
    player_copy = player;
    // Matching: the empty if is needed for the match.
    if (player && player) {
    }
    if (func_8008E124(player_copy)) {
        anim_id = _badata_entrypoint_32(player_copy);
    } else {
        anim_id = _badata_entrypoint_34();
    }
    return anim_id;
}

int func_808004C4_bsdronebitten(Actor *player, s32 anim_id, f32 duration)
{
    AnCtrl *anim_ctrl;
    extern AnCtrl *baanim_getAnimCtrlPtr(Actor *);
    extern void anctrl_reset(AnCtrl *);
    extern void anctrl_setIndex(AnCtrl *, s32);
    extern void anctrl_setDuration(AnCtrl *, f32);
    extern void anctrl_setPlaybackType(AnCtrl *, s32);
    extern void anctrl_setSmoothTransition(AnCtrl *, s32);
    extern void anctrl_start(AnCtrl *);
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_start(anim_ctrl);
    *(s8 *) ((char *) player + 0x190) = 1;
}

// Mode 2 update: on landing, shakes, dusts and dies or plays the get-up anim.
void bsdronebitten_entrypoint_9(PlayerState *player)
{
    s32 next_state = 0;

    switch (((u8 *) player)[0x190]) {
        case 0:
            if (_bamovegoto_entrypoint_4(player)) {
                func_8009D9D4(player);
                func_8009DB04(player, 0x417, 0.8f, 0x4650);
                _bashake_entrypoint_0(player, 3, 1);
                _badust_entrypoint_8(player);
                if (!func_800A1718(player)) {
                    next_state = _badata_entrypoint_20(player);
                } else {
                    switch (func_800A3274(player)) {
                        case 1:
                        case 10:
                            func_808004C4_bsdronebitten(player, 0xD2, 2.25f);
                            break;
                        case 11:
                            func_808004C4_bsdronebitten(player, 0x11E, 1.6f);
                            break;
                        default:
                            next_state = func_80800478_bsdronebitten(player, 0);
                    }
                }
            }
            break;
        case 1:
            if (baanim_isStopped(player))
                next_state = func_80800478_bsdronebitten(player, 0);
    }
    bs_setState(player, next_state);
}
