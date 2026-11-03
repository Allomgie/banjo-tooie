#include "common.h"
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/physics.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"
#include "core2/1ECE0B0.h"
#include "core2/1EB5E70.h"

#define BAANIM_DEBUG_LOG()                                                                         \
    do {                                                                                           \
    } while (0)
extern f32 func_800A8258(void);
extern void func_80098218(PlayerState *, s32);

extern f32 func_80013970(f32);

#define BAANIM_BIGHEAD 0x4
#define BAANIM_SMALLHEAD 0x8
#define BAANIM_LONGBODY 0x10
#define BAANIM_BIGKAZOOIEHEAD 0x20
#define BAANIM_BIGWINGS 0x40
#define BAANIM_WISHYWASHY 0x80

f32 D_80117C70[3] = {0.0f, 5.0f, 0.0f};
// Bottles bonus modifications.
s32 D_80117C7C[7] = {BAANIM_BIGHEAD,
                     0x2 | 0x1,
                     BAANIM_BIGWINGS | BAANIM_BIGKAZOOIEHEAD,
                     BAANIM_LONGBODY | BAANIM_SMALLHEAD,
                     BAANIM_LONGBODY | BAANIM_SMALLHEAD | 0x2 | 0x1,
                     BAANIM_BIGWINGS | BAANIM_BIGKAZOOIEHEAD | BAANIM_BIGHEAD | 0x2 | 0x1,
                     BAANIM_WISHYWASHY};

s32 baanim_get_size(void)
{
    return sizeof(BaAnim);
}

void __baanim_update_scaleToHorizontalVelocity(PlayerState *player)
{
    f32 velocity[3];
    f32 speed;
    f32 scale;
    f32 relative_duration;
    f32 duration;

    scale = player->anim->scalable_duration ? player->anim->duration_scale : 1.0f;
    func_8009BB24(player, velocity);
    speed = sqrtf(velocity[0] * velocity[0] + velocity[2] * velocity[2]);
    relative_duration = func_800F1198(speed, player->anim->speed_min, player->anim->speed_max,
                         player->anim->duration_relative_min * scale,
                         player->anim->duration_relative_max * scale);
    duration = func_800F0D50(relative_duration, player->anim->duration_min, player->anim->duration_max);
    anctrl_setDuration(player->anim->anctrl, duration);
    func_8008ADE4(player->anim->anctrl);
}

void __baanim_update_scaleToVerticalVelocity(PlayerState *player)
{
    f32 speed;
    f32 relative_duration;
    f32 duration;

    speed = mlAbsF(baphysics_get_vertical_velocity(player));
    relative_duration = func_800F1198(speed, player->anim->speed_min, player->anim->speed_max,
                         player->anim->duration_relative_min, player->anim->duration_relative_max);
    duration = func_800F0D50(relative_duration, player->anim->duration_min, player->anim->duration_max);
    anctrl_setDuration(player->anim->anctrl, duration);
    func_8008ADE4(player->anim->anctrl);
}

// Fills dst with a per-axis oscillating scale.
void __baanim_oscillateScale(f32 dst[3], f32 phase,f32 min, f32 osc_size)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        dst[i] =
            min +
            osc_size * (0.5f + 0.5f * func_80013970(
                                          360.0f *
                                          func_800F0F9C(phase + (2.0f * ((f32) i / 3.0f)), 2.0f)));
    };
}

#ifndef NONMATCHING

// Pose post-process hook: bottles bonus bone scaling and per-transformation bone tweaks.
void __baanim_applyBottlesBonus(s32 pose, s32 player_id)
{
    f32 scale[3];
    f32 phase;
    PlayerState *player;
    static s32 D_80126CD0;

    player = func_800F53D0(player_id);

    func_80098218(player, pose);
    func_800DFC20(pose, player->anim->unkE, player->anim->unk10);
    if (player->anim->unkC) {
        func_800EFD24(scale);
        func_800DFFA0(pose, player->anim->unkE, scale);
    }
    phase = func_800A8258();

    if (D_80126CD0 & 1) {
        BAANIM_DEBUG_LOG();
        __baanim_oscillateScale(scale, phase, 2.0f, 1.0f);
        func_800DFF64(pose, 0x6, scale);
        func_800DFF64(pose, 0x14, scale);
    }
    if (D_80126CD0 & 2) {
        BAANIM_DEBUG_LOG();
        __baanim_oscillateScale(scale, phase, 2.0f, 1.0f);
        func_800DFF64(pose, 0x10, scale);
        func_800DFF64(pose, 0x1E, scale);
    }
    if (D_80126CD0 & BAANIM_BIGHEAD) {
        BAANIM_DEBUG_LOG();
        __baanim_oscillateScale(scale, phase, 2.0f, 1.0f);
        func_800DFF64(pose, 0x12, scale);
    }
    if (D_80126CD0 & BAANIM_SMALLHEAD) {
        BAANIM_DEBUG_LOG();
        __baanim_oscillateScale(scale, phase, 0.2f, 0.5f);
        func_800DFF64(pose, 0x12, scale);
    }
    if (D_80126CD0 & BAANIM_LONGBODY) {
        BAANIM_DEBUG_LOG();
        func_800DFFA0(pose, 1, D_80117C70);
    }
    if (D_80126CD0 & BAANIM_BIGKAZOOIEHEAD) {
        BAANIM_DEBUG_LOG();
        __baanim_oscillateScale(scale, phase, 2.0f, 1.0f);
        func_800DFF64(pose, 0x6C, scale);
    }
    if (D_80126CD0 & BAANIM_BIGWINGS) {
        BAANIM_DEBUG_LOG();
        __baanim_oscillateScale(scale, phase, 2.0f, 1.0f);
        func_800DFF64(pose, 0x64, scale);
        func_800DFF64(pose, 0x67, scale);
    }
    if (func_8010FFD8(func_800A4C88(player))) {
        __baanim_oscillateScale(scale, phase, 0.9f, 0.2f);
        func_800DFF64(pose, player->anim->unkE, scale);
    }
    if (player->anim->unk4 != NULL) {
        player->anim->unk4(pose, player_id);
    }
}

#else
void __baanim_applyBottlesBonus(s32 pose, s32 player_id)
{
#endif

    void baanim_init(PlayerState * player)
    {
        player->anim->unk3C = NULL;
        player->anim->anctrl = func_8008AD80(1);
        anctrl_setSmoothTransition(player->anim->anctrl, 0);
        player->anim->unk4 = NULL;
        func_8008B304(player->anim->anctrl);
        func_8008AEE4(player->anim->anctrl, __baanim_applyBottlesBonus);
        func_8008AF04(player->anim->anctrl, player->unk184);
        player->anim->state = 0;
        func_8008CA4C(player, 1);
        baanim_setDurationRange(player, 0.01f, 100.0f);
        func_8008C9F0(player, 0.0f, 1000.0f, 0.1f, 10.0f);
        func_8008C9E4(player, 0);
        func_8008C984(player, 3);
        player->anim->scalable_duration = 0;
        player->anim->duration_scale = 1.0f;
    }

    void baanim_free(PlayerState * player)
    {
        func_8008ADBC(player->anim->anctrl);
        func_8008CFF0(player);
    }

    void baanim_update(PlayerState * player)
    {
        switch (player->anim->state) {
            case BAANIM_UPDATE_2_SCALE_HORZ:
                __baanim_update_scaleToHorizontalVelocity(player);
                break;

            case BAANIM_UPDATE_3_SCALE_VERT:
                __baanim_update_scaleToVerticalVelocity(player);
                break;

            case BAANIM_UPDATE_1_NORMAL:
                func_8008ADE4(player->anim->anctrl);
                break;

            case BAANIM_UPDATE_4_UNKOWN:
                func_8008ADE4(player->anim->anctrl);
                func_8008ADE4(player->anim->unk3C);

            case BAANIM_UPDATE_0_NONE:
                break;
        }
    }

    void baanim_defrag(PlayerState * player)
    {
        player->anim->anctrl = func_8008AEB4(player->anim->anctrl);
    }

    void func_8008C958(PlayerState * player, f32 unk_0[3])
    {
        func_800EE7F8(unk_0, player->anim->unk10);
    }

    void func_8008C984(PlayerState * player, s32 bone_index)
    {
        player->anim->unkE = bone_index;
    }

    void func_8008C990(PlayerState * player, f32 unk_0)
    {
        func_8008B10C(player->anim->anctrl, unk_0);
    }

    void baanim_setDurationRange(PlayerState * player, f32 min, f32 max)
    {
        player->anim->duration_min = min;
        player->anim->duration_max = max;
    }

    void func_8008C9D8(PlayerState * player, void (*callback)(s32, s32))
    {
        player->anim->unk4 = callback;
    }

    void func_8008C9E4(PlayerState * player, s32 unk_0)
    {
        player->anim->unkC = unk_0;
    }

    void func_8008C9F0(PlayerState * player, f32 speed_min, f32 speed_max, f32 duration_min,
                       f32 duration_max)
    {
        player->anim->speed_min = speed_min;
        player->anim->speed_max = speed_max;
        player->anim->duration_relative_min = duration_min;
        player->anim->duration_relative_max = duration_max;
        player->anim->scalable_duration = 0;
    }

    void func_8008CA30(PlayerState * player, f32 scale)
    {
        player->anim->duration_scale = scale;
        player->anim->scalable_duration = 1;
    }

    // Normal mode becomes dual mode while a secondary AnimCtrl exists.
    void func_8008CA4C(PlayerState * player, BaAnimUpdateType state)
    {
        if ((player->anim->unk3C != NULL) && (state == 1)) {
            state = BAANIM_UPDATE_4_UNKOWN;
        }
        player->anim->state = state;
    }

    s32 func_8008CA74(PlayerState * player)
    {
        return func_8008B4D4(player->anim->anctrl);
    }

    void func_8008CA98(PlayerState * player)
    {
        func_8008B304(player->anim->anctrl);
    }

    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState * player)
    {
        return player->anim->anctrl;
    }

    f32 baanim_getTimer(PlayerState * player)
    {
        return anctrl_getAnimTimer(player->anim->anctrl);
    }

    int baanim_isStopped(PlayerState * player)
    {
        return anctrl_isStopped(player->anim->anctrl);
    }

    int baanim_isAt(PlayerState * player, f32 time)
    {
        return anctrl_isAt(player->anim->anctrl, time);
    }

    void baanim_playForDuration_loopSmooth(PlayerState * player, AssetId anim_id, f32 duration)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setPlaybackType(player->anim->anctrl, 2);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_playForDuration_loop(PlayerState * player, AssetId anim_id, f32 duration)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setSmoothTransition(player->anim->anctrl, 0);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setPlaybackType(player->anim->anctrl, 2);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_playForDuration_loopStartingAt(PlayerState * player, AssetId anim_id, f32 duration,
                                               f32 start)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setStart(player->anim->anctrl, start);
        anctrl_setPlaybackType(player->anim->anctrl, 2);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_playForDuration_onceSmooth(PlayerState * player, AssetId anim_id, f32 duration)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setPlaybackType(player->anim->anctrl, 1);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_playForDuration_onceSmoothStartingAt(PlayerState * player, AssetId anim_id,
                                                     f32 duration, f32 start)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setStart(player->anim->anctrl, start);
        anctrl_setPlaybackType(player->anim->anctrl, 1);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_playForDuration_once(PlayerState * player, AssetId anim_id, f32 duration)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setSmoothTransition(player->anim->anctrl, 0);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setPlaybackType(player->anim->anctrl, 1);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_playForDuration_onceStartingAt(PlayerState * player, AssetId anim_id, f32 duration,
                                               f32 start)
    {
        anctrl_reset(player->anim->anctrl);
        anctrl_setSmoothTransition(player->anim->anctrl, 0);
        anctrl_setIndex(player->anim->anctrl, anim_id);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setStart(player->anim->anctrl, start);
        anctrl_setPlaybackType(player->anim->anctrl, 1);
        anctrl_start(player->anim->anctrl);
    }

    void baanim_setEnd(PlayerState * player, f32 end_position)
    {
        anctrl_setSubrange(player->anim->anctrl, 0.0f, end_position);
        anctrl_setPlaybackType(player->anim->anctrl, 1);
    }

    void baanim_setEndAndDuration(PlayerState * player, f32 end_position, f32 duration)
    {
        anctrl_setSubrange(player->anim->anctrl, 0.0f, end_position);
        anctrl_setDuration(player->anim->anctrl, duration);
        anctrl_setPlaybackType(player->anim->anctrl, 1);
    }

    // Creates the secondary AnimCtrl.
    void func_8008CF7C(PlayerState * player)
    {
        if (player->anim->unk3C != NULL) {
            return;
        }
        player->anim->unk3C = func_8008AD80(1);
        anctrl_setSmoothTransition(player->anim->unk3C, 0);
        if (player->anim->state == BAANIM_UPDATE_1_NORMAL) {
            player->anim->state = BAANIM_UPDATE_4_UNKOWN;
        }
    }

    // Frees the secondary AnimCtrl.
    void func_8008CFF0(PlayerState * player)
    {
        if (player->anim->unk3C != NULL) {
            func_8008ADBC(player->anim->unk3C);
        }
        player->anim->unk3C = NULL;
        if (player->anim->state == BAANIM_UPDATE_4_UNKOWN) {
            player->anim->state = BAANIM_UPDATE_1_NORMAL;
        }
    }

    AnimCtrl *func_8008D04C(PlayerState * player)
    {
        return player->anim->unk3C;
    }

    void func_8008D058(PlayerState * player)
    {
        func_8008B304(player->anim->unk3C);
        func_800DF41C(func_8008B4D4(player->anim->unk3C));
    }
