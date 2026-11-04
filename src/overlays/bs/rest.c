// The "held by an external lock" states: while a cutscene, dialog or actor holds the player, the
// player stands in a hold animation and faces the lock's target. Exports helpers that other
// character families wrap as their own rest states, plus three Banjo-Kazooie rest states.
#include "overlays/bs/rest.h"

extern enum bs_state_e bsrest_entrypoint_13(PlayerState *self);
extern void bsrest_entrypoint_17(PlayerState *self, s32);

static void func_80800000_bsrest(PlayerState *self)
{
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    if (player_isStable(self) != 0) {
        func_8009BA9C(self, NULL);
    }
}

static void func_8080003C_bsrest(PlayerState *self)
{
    if (baflag_isFalse(self, BA_FLAG_18) == 0) {
        baflag_clear(self, BA_FLAG_18);
        func_80110C2C(func_800A4CA8(self));
    }
}

// Lock type 4: aim the first-person camera at the lock's target.
static void func_80800080_bsrest(PlayerState *self)
{
    f32 pos[3];
    PlayerState *unk_0;

    unk_0 = func_800A4CA8(self);
    if (func_8009CC68(self) == 4) {
        baflag_set(self, BA_FLAG_18);
        func_80110BF0(unk_0);
        func_800F3BD0(self, 5, pos);
        _ncba1p_entrypoint_6(unk_0, pos);
    }
}

static void func_808000E4_bsrest(PlayerState *self)
{
    PlayerState *unk_0;
    f32 dir[3];
    f32 pos[3];
    f32 target[3];
    f32 pos_tmp[3];

    unk_0 = func_800A4CA8(self);
    if ((func_8009CC68(self) == 4) && (baflag_isFalse(self, BA_FLAG_18) == 0)) {
        func_800F3BD0(self, 5, pos_tmp);
        _ncba1p_entrypoint_6(unk_0, pos_tmp);
        func_800F3BD0(self, 5, pos);
        func_8009CC18(self, target);
        func_800A516C(dir, target, pos);
        _ncba1p_entrypoint_7(unk_0, dir);
    }
}

// Turn to face the lock's target.
void bsrest_entrypoint_0(PlayerState *self)
{
    f32 yaw;
    f32 pos[3];
    f32 target[3];

    if (func_8009CC68(self) != 0) {
        func_8009C128(self, pos);
        if (func_8009CC18(self, target) == 0) {
            func_801160DC(func_800A4CA8(self), 0);
            return;
        }

        if (func_800F1E6C(pos, target, &yaw) != 0) {
            yaw_setIdeal(self, yaw);
        }
    }
}

static void func_8080020C_bsrest(PlayerState *self, enum asset_e anim_id, f32 duration)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (anim_id == ASSET_50_ANIM_BSREST_UNKNOWN) {
        func_800A0CF4(self, 1);
        switch (anctrl_getIndex(baanim_getAnimCtrlPtr(self))) {
            case ASSET_50_ANIM_BSREST_UNKNOWN:
                baanim_playForDuration_loopSmooth(self, anim_id, duration);
                break;
            case ASSET_5B_ANIM_BSREST_UNKNOWN:
                anctrl_reset(anim_ctrl);
                anctrl_setIndex(anim_ctrl, ASSET_5B_ANIM_BSREST_UNKNOWN);
                anctrl_setDuration(anim_ctrl, 0.4f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                break;
            default:
                baanim_playForDuration_onceSmooth(self, ASSET_5B_ANIM_BSREST_UNKNOWN, 0.5f);
                anctrl_setPlaybackType(anim_ctrl, 1);
        }
    } else {
        baanim_playForDuration_loopSmooth(self, anim_id, duration);
    }

    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    func_80800000_bsrest(self);
    bsrest_entrypoint_0(self);
}

static s32 func_8080032C_bsrest(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    s32 released;
    enum asset_e anim_index;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    bsrest_entrypoint_0(self);
    released = 0;
    anim_index = anctrl_getIndex(anim_ctrl);
    switch (anim_index) {
        case ASSET_5B_ANIM_BSREST_UNKNOWN:
            if (baanim_isStopped(self) != 0) {
                if (func_8008B28C(anim_ctrl) != 0) {
                    baanim_playForDuration_loopSmooth(self, ASSET_50_ANIM_BSREST_UNKNOWN, 11.4f);
                } else if (func_8009CC68(self) == 0) {
                    released = 1;
                }
            }
            break;
        case ASSET_50_ANIM_BSREST_UNKNOWN:
            if (func_8009CC68(self) == 0) {
                released = 1;
            }
            break;
        default:
            if (func_8009CC68(self) == 0) {
                released = 1;
            }
    }

    return released;
}

static void func_808003FC_bsrest(PlayerState *self)
{
    if (func_800A0C20(self) != 0) {
        func_800A0D14(self, 0, 0.5f);
    }
}

void bsrest_entrypoint_1(PlayerState *self)
{
    enum asset_e asset_id;
    f32 duration;

    _badata_entrypoint_9(self, &asset_id, &duration);
    func_8080020C_bsrest(self, asset_id, duration);
}

void bsrest_entrypoint_2(PlayerState *self)
{
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_77;
    }

    if (func_8080032C_bsrest(self) != 0) {
        next_state = bsrest_entrypoint_13(self);
    }

    bs_setState(self, next_state);
}

void bsrest_entrypoint_3(PlayerState *self)
{
    func_808003FC_bsrest(self);
}

s32 bsrest_entrypoint_4(s32 idx)
{
    return D_80800910_bsrest[idx];
}

void bsrest_entrypoint_5(PlayerState *self)
{
    enum asset_e asset_id;
    f32 duration;

    _badata_entrypoint_10(self, &asset_id, &duration);
    func_8080020C_bsrest(self, asset_id, duration);
}

void bsrest_entrypoint_6(PlayerState *self)
{
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_77;
    }

    if (func_8080032C_bsrest(self) != 0) {
        next_state = bsrest_entrypoint_13(self);
    }

    bs_setState(self, next_state);
}

void bsrest_entrypoint_7(PlayerState *self)
{
    func_808003FC_bsrest(self);
}

s32 bsrest_entrypoint_8(s32 idx)
{
    return D_80800920_bsrest[idx];
}

void bsrest_entrypoint_9(PlayerState *self)
{
    enum asset_e asset_id;
    f32 duration;

    _badata_entrypoint_11(self, &asset_id, &duration);
    func_8080020C_bsrest(self, asset_id, duration);
    func_80800080_bsrest(self);
}

void bsrest_entrypoint_10(PlayerState *self)
{
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    func_808000E4_bsrest(self);
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_77;
    }

    if (func_8080032C_bsrest(self) != 0) {
        next_state = bsrest_entrypoint_13(self);
    }

    bs_setState(self, next_state);
}

void bsrest_entrypoint_11(PlayerState *self)
{
    func_808003FC_bsrest(self);
    func_8080003C_bsrest(self);
}

s32 bsrest_entrypoint_12(s32 idx)
{
    return D_80800930_bsrest[idx];
}

enum bs_state_e bsrest_entrypoint_13(PlayerState *self)
{
    if (_bafpctrl_entrypoint_4(self) == 3) {
        return _badrone_entrypoint_24(self);
    }

    return _badata_entrypoint_34(self);
}

void bsrest_entrypoint_14(PlayerState *self)
{
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_8080003C_bsrest(self);
}

void bsrest_entrypoint_15(PlayerState *self, s32 face_target)
{
    f32 duration;
    enum asset_e asset_id;

    switch (func_8009CC68(self)) {
        case 1:
            _badata_entrypoint_9(self, &asset_id, &duration);
            break;
        case 3:
            _badata_entrypoint_10(self, &asset_id, &duration);
            break;
        default:
        case 2:
            _badata_entrypoint_11(self, &asset_id, &duration);
    }
    if (asset_id != 0) {
        baanim_playForDuration_loopSmooth(self, asset_id, duration);
    }
    bsrest_entrypoint_17(self, face_target);
}

void bsrest_entrypoint_16(PlayerState *self)
{
    bsrest_entrypoint_15(self, 1);
}

void bsrest_entrypoint_17(PlayerState *self, s32 face_target)
{
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    func_80800000_bsrest(self);
    func_80800080_bsrest(self);
    if (face_target != 0) {
        bsrest_entrypoint_0(self);
    }
}

void bsrest_entrypoint_18(PlayerState *self)
{
    bsrest_entrypoint_17(self, 1);
}

s32 bsrest_entrypoint_19(PlayerState *self, s32 face_target)
{
    if (face_target != 0) {
        bsrest_entrypoint_0(self);
        if (_badata_entrypoint_15(self) != 0) {
            func_8009D3A8(self, 0);
        }
    } else {
        func_801160DC(func_800A4CA8(self), 0);
    }

    func_808000E4_bsrest(self);
    if (func_8009CC68(self) == 0) {
        return 1;
    }

    return 0;
}

s32 bsrest_entrypoint_20(PlayerState *self)
{
    return bsrest_entrypoint_19(self, 1);
}

// TU-NOTE: the overlay's .data is defined here in C. The tables hold pointers to functions of
// this file, and IDO's assembler schedules some of them differently unless they are in the same
// unit. Values are taken from the ROM.
extern void func_80099B94();
s32 D_80800910_bsrest[4] = {(u32) _bsrest_entrypoint_3, (u32) _bsrest_entrypoint_1,
                            (u32) _bsrest_entrypoint_2, (u32) func_80099B94};
s32 D_80800920_bsrest[4] = {(u32) _bsrest_entrypoint_7, (u32) _bsrest_entrypoint_5,
                            (u32) _bsrest_entrypoint_6, (u32) func_80099B94};
s32 D_80800930_bsrest[4] = {(u32) _bsrest_entrypoint_11, (u32) _bsrest_entrypoint_9,
                            (u32) _bsrest_entrypoint_10, (u32) func_80099B94};
