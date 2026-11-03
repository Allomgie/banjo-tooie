#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/yaw.h"
#include "overlays/ba/stick.h"

extern void *baanim_getAnimCtrlPtr();
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_800C3730(s32, f32, f32, f32);
extern void func_80093300(PlayerState *, f32);
extern void func_8009C1B4(PlayerState *, f32);
// TU-NOTE: the handler tables at the end are defined here; IDO schedules some functions differently otherwise.
typedef struct {
    f32 yaw;
    f32 speed;
    AnimCtrl *anim_ctrl;
} ShockMotion61;
extern f32 func_80092BF4(PlayerState *);
extern s32 D_80800870_bsbshock[];
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern void func_8009DF58(PlayerState *, s32, f32);
extern s32 D_80800880_bsbshock[];
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

// Charge state: crouch and loop the charge sound (sfx 0x41D).
void bsbshock_entrypoint_0(PlayerState *player)
{
    ShockMotion61 motion;
    AnimCtrl *anim_ctrl;
    s32 sound_source;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    motion.anim_ctrl = anim_ctrl;
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(motion.anim_ctrl, 0x48);
    func_8008B1C8(motion.anim_ctrl, 0.4f);
    anctrl_setDuration(motion.anim_ctrl, 4.2f);
    anctrl_setSubrange(motion.anim_ctrl, 0.0f, 0.1061f);
    anctrl_setPlaybackType(motion.anim_ctrl, 1);
    anctrl_start(motion.anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    if (bastick_distance(player) != 0.0f) {
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    }
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    _bswalk_entrypoint_1(player);
    motion.yaw = yaw_getIdeal(player);
    motion.speed = baphysics_get_target_horizontal_velocity(player);
    baphysics_set_horizontal_velocity(player, motion.yaw, motion.speed);
    func_800A0CE8(player, 1);
    func_800A0CF4(player, 1);
    func_8009D874(player);
    sound_source = func_800C2E04();
    *(u8 *) ((s8 *) player + 0x164) = sound_source;
    func_800C3418(sound_source & 0xFF, 0);
    func_800C2E40(*(u8 *) ((s8 *) player + 0x164));
    func_800C330C(*(u8 *) ((s8 *) player + 0x164), 3);
    func_800C301C(*(u8 *) ((s8 *) player + 0x164), 0x41D);
    func_800C3730(*(u8 *) ((s8 *) player + 0x164), 1.4f, 0.4f, -1.2f);
    func_80093300(player, -87.0f);
    func_8009C1B4(player, -87.0f);
    *(s32 *) ((s8 *) player + 0x15C) = 1;
    *(s32 *) ((s8 *) player + 0x160) = 0;
}

void bsbshock_entrypoint_1(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (player_isStable(player)) {
        if (func_8001211C() % 2) {
            func_8009FC80(player);
        }
    } else {
        func_8009FC80(player);
    }
    _bswalk_entrypoint_1(player);
    func_8009BB24(player, velocity);
    if (bakey_released(player, 8) && velocity[1] > 0.0f) {
        baphysics_reset_gravity(player);
    }
    switch (player->unk160.word) {
        case 0:
            if (func_8008E260(player)) {
                next_state = 0x3D;
            }
            if (func_8008DF8C(player, 0x82)) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 2.8f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                player->unk160.word = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.11f)) {
                func_800C3BDC(((u8 *) player)[0x164]);
            }
            if (anctrl_isAt(anim_ctrl, 0.4036000073f)) {
                anctrl_setDuration(anim_ctrl, 1.4f);
            }
            if (anctrl_isStopped(anim_ctrl)) {
                next_state = 1;
            }
    }
    if (func_8008DF8C(player, 0x3C)) {
        if (anctrl_getAnimTimer(anim_ctrl) < 0.3637000024f) {
            if (bakey_released(player, 8)) {
                player->unk15C.word = 0;
            }
        }
        if (player_isStable(player)) {
            baphysics_set_target_horizontal_velocity(player, 0.0f);
        }
    } else {
        if (bainput_func_80097DF4(player)) {
            next_state = 0x10;
        }
        if (bainput_should_beak_bust(player)) {
            next_state = 0xF;
        }
    }
    if (anctrl_isAt(anim_ctrl, 0.3637000024f) && player->unk15C.word) {
        next_state = 0x22;
    }
    if (anctrl_isAt(anim_ctrl, 0.4652999938f)) {
        baphysics_set_vertical_velocity(player, 180.0f);
        func_80093300(player, 0);
        func_8009C1B4(player, 87.0f);
    }
    if (velocity[1] < 0.0f && player_inWater(player)) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

void bsbshock_entrypoint_2(PlayerState *player)
{
    // Free the charge sound source.
    func_800C2FDC(*((u8 *) player + 0x164));
    func_800A0CE8(player, 0);
    func_800A0CF4(player, 0);
    if (func_80092BF4(player) != 0.0f) {
        func_80093300(player, 0.0f);
        func_8009C1B4(player, 87.0f);
    }
}

int bsbshock_entrypoint_3(s32 index)
{
    return D_80800870_bsbshock[index];
}

// Jump state: launch with vertical velocity 1250 and gravity -1200.
void bsbshock_entrypoint_4(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 stick_dist;
    f32 yaw;
    f32 stick_angle;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x49);
    anctrl_setDuration(anim_ctrl, 0.8f);
    anctrl_setStart(anim_ctrl, 0.6739f);
    anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    stick_dist = bastick_distance(player);
    if (stick_dist != 0.0f) {
        stick_angle = bastick_getAngleRelativeToBanjo(player);
        yaw_setIdeal(player, stick_angle);
    }
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    _bswalk_entrypoint_1(player);
    yaw = yaw_getIdeal(player);
    baphysics_set_horizontal_velocity(player, yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 1250.0f);
    baphysics_set_gravity(player, -1200.0f);
    func_8009DBF0(player, 0x408, 1.0f);
    func_800A0CE8(player, 1);
    func_800A0CF4(player, 1);
    func_800C6DA0(0x45);
    func_80093300(player, -87.0f);
    func_8009C1B4(player, -87.0f);
    func_8009DF58(player, 0x43A, 1.0f);
    player->unk160.word = 0;
}

void bsbshock_entrypoint_5(Actor *player)
{
    s32 next_state;
    f32 velocity[3];
    s32 anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    _bswalk_entrypoint_1(player);
    func_8009BB24(player, velocity);
    if (anctrl_isAt(anim_ctrl, 0.7618f) != 0) {
        anctrl_setDuration(anim_ctrl, 3.0f);
    }
    if ((bakey_released(player, 8) != 0) && (velocity[1] > 0.0f)) {
        baphysics_reset_gravity(player);
    }
    if (*(s32 *) ((s8 *) player + 0x160) == 0) {
        func_8009FC80(player);
        if (velocity[1] < 0.0f) {
            next_state = 0x2F;
        }
    }
    if (player_isStable(player) == 0) {
        if (func_8008E260(player) != 0) {
            next_state = 0x3D;
        }
        if (bainput_func_80097DF4(player) != 0) {
            next_state = 0x10;
        }
        if (bainput_should_beak_bust(player) != 0) {
            next_state = 0xF;
        }
        if (func_8008DA24(player) != 0) {
            next_state = 0xA8;
        }
    }
    bs_setState(player, next_state);
}

void bsbshock_entrypoint_6(s32 player)
{
    if (bs_getNextState() != 0x11) {
        baphysics_reset_gravity(player);
    }
    func_800A0CE8(player, 0);
    func_800A0CF4(player, 0);
    // Matching: the mask is needed for the match.
    func_80093300(player, 0 & 0xFFFFFFFFFFFFFFFF);
    func_8009C1B4(player, 87.0f);
}

int bsbshock_entrypoint_7(s32 index)
{
    return D_80800880_bsbshock[index];
}

extern void _bsbshock_entrypoint_2();
extern void _bsbshock_entrypoint_0();
extern void _bsbshock_entrypoint_1();
extern void func_80099B94();
extern void _bsbshock_entrypoint_6();
extern void _bsbshock_entrypoint_4();
extern void _bsbshock_entrypoint_5();
s32 D_80800870_bsbshock[4] = {(u32) _bsbshock_entrypoint_2, (u32) _bsbshock_entrypoint_0,
                              (u32) _bsbshock_entrypoint_1, (u32) func_80099B94};
s32 D_80800880_bsbshock[4] = {(u32) _bsbshock_entrypoint_6, (u32) _bsbshock_entrypoint_4,
                              (u32) _bsbshock_entrypoint_5, (u32) func_80099B94};
