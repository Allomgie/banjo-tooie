#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "core2/physics.h"
#include "overlays/ba/yaw.h"

extern s32 bakey_pressed(PlayerState *, s32);
extern s32 bakey_released(PlayerState *, s32);
extern s32 func_8008E148(PlayerState *);
extern void func_80099B94();
extern s32 _bsdrone_entrypoint_3;
extern u8 func_80099AA8[];
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern int func_8009E77C(PlayerState *, s32);
extern void func_800A0CD0(PlayerState *, s32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800A106C(PlayerState *, f32, f32);
extern s32 func_8008DF8C(s32, s32);
extern void func_8009D2F0(s32, s32, f32);
extern s32 D_80801E10_bsbansack[];
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void bainput_enable(PlayerState *, s32, s32);
extern s32 D_80801E20_bsbansack[];
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern s32 D_80801E30_bsbansack[];
extern f32 baphysics_get_vertical_velocity(PlayerState *);
typedef struct {
    s8 unk15A;
    s8 unk15B;
} ActorLocal_BSBansack;
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern s32 D_80801E40_bsbansack[];
typedef struct {
    u8 pad_0[0x15C];
    s8 unk15C;
    u8 pad_15D[19];
    f32 unk170;
    f32 unk174;
} BansackStruct;
extern void func_800931AC(BansackStruct *, int);
extern void func_8009328C(BansackStruct *, f32);
extern f32 func_80092BE8(BansackStruct *);
extern f32 func_800F1DCC(f32, f32);
extern void _batimer_set(BansackStruct *, int, u32);
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 D_80801E50_bsbansack[];
extern s32 D_80801E60_bsbansack[];
extern s32 D_80801E70_bsbansack[];
extern s32 D_80801E80_bsbansack[];
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern void bs_setState();
extern s32 D_80801E90_bsbansack[];
extern s32 D_80801EA0_bsbansack[];
extern void func_8009DBF0(PlayerState *, s32, f32);
extern f32 func_800964DC(PlayerState *);
extern f32 func_80096364(PlayerState *);
extern f32 func_800DC178(f32, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void func_8009BF5C(PlayerState *, f32);
extern s32 player_inWater(PlayerState *);
extern s32 player_isStable(PlayerState *);
extern void func_800A2EEC(PlayerState *, s32);
extern void func_8009D2D8(PlayerState *, s32);
extern void func_800A2FCC(PlayerState *, s32);

s32 func_80800000_bsbansack(PlayerState *player, s32 next_state, s32 check_pressed)
{
    if (check_pressed && bakey_pressed(player, 8)) {
        next_state = 0x169;
    }
    if (func_8008E148(player)) {
        next_state = 1;
    }
    if ((*(u8 *) ((u8 *) player + 0x15F) == 0) && bakey_released(player, 1)) {
        next_state = 0x164;
    }
    return next_state;
}

s32 func_80800084_bsbansack(PlayerState *player, s32 next_state)
{
    if (bakey_pressed(player, 8)) {
        next_state = 0x169;
    }
    if (func_8008E148(player)) {
        next_state = 1;
    }
    if ((*(u8 *) ((u8 *) player + 0x15F) == 0) && bakey_released(player, 1)) {
        next_state = 0x164;
    }
    return next_state;
}

// Handles interrupt ids 0x7F/0x80 (set/clear the flag at +0x15F); others go to the callback.
void func_80800100_bsbansack(u8 *player, s32 (*callback)(u8 *))
{
    s32 interrupt_id;

    interrupt_id = func_8009E6EC();
    switch (interrupt_id) {
        case 0x7F:
            *(s8 *) ((s8 *) player + 0x15F) = 1;
            return;
        case 0x80:
            *(s8 *) ((s8 *) player + 0x15F) = 0;
            return;
        default:
            callback(player);
        case 0xC:
            return;
    }
}

void func_80800168_bsbansack(s32 player)
{
    func_80800100_bsbansack(player, &func_80099B94);
}

void func_8080018C_bsbansack(s32 player)
{
    func_80800100_bsbansack(player, &_bsdrone_entrypoint_3);
}

void func_808001B0_bsbansack(s32 player)
{
    func_80800100_bsbansack(player, &func_80099AA8);
}

void func_808001D4_bsbansack(PlayerState *player)
{
    f32 zone_pos;

    zone_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(zone_pos, 100.0f, 500.0f));
    }
}

int func_80800238_bsbansack(arg)
s32 arg;
{
    s32 player;
    // Matching: the "| 0" copy is needed for the match.
    player = arg | 0;
    if (func_8009E74C(player, 0x12)) {
        if (_babackpack_get_state(player) != 4) {
            func_800A0CD0(player, 0);
            _babackpack_set_state(player, 4);
        }
    } else {
        if (_babackpack_get_state(player) != 1) {
            _babackpack_set_state(player, 1);
        }
        func_800A0CD0(player, 1);
        bastick_popZone(player);
        func_800A1040(player);
    }
}

void func_808002D4_bsbansack(player) PlayerState *player;
{
    if (!func_8009E77C(player, 0x12)) {
        func_800A0CD0(player, 0);
        _babackpack_set_state(player, 4);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 1.0f);
        func_800A106C(player, -10.0f, 10.0f);
        baphysics_set_target_horizontal_velocity(player, 0.0f);
        player->unk15C.bytes[3] = 0;
    }
}

void func_80800368_bsbansack(s32 player)
{
    if (func_8008DF8C(player, 0x1E)) {
        func_8009D2F0(player, 0, 0.5f);
    } else {
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
    }
}

void func_808003C0_bsbansack(s32 player)
{
    baphysics_set_gravity(player, 1e+02f);
    baphysics_set_terminal_velocity(player, 0x4305547B);
    func_800961AC(player, 3);
}

int func_80800400_bsbansack(player)
Actor *player;
{
    baphysics_reset_terminal_velocity();
    baphysics_reset_gravity(player);
    func_800961AC(player, 1);
}

void func_80800434_bsbansack(s32 player)
{
    func_80800400_bsbansack();
    func_80800238_bsbansack(player);
}

void func_8080045C_bsbansack(s32 player)
{
    func_808002D4_bsbansack(player);
    baanim_playForDuration_loopSmooth(player, 0x28B, 1.5f);
    func_8009FFD8(player, 1, 1, 1, 2);
    func_808003C0_bsbansack(player);
}

s32 func_808004B0_bsbansack(s32 player)
{
    s32 next_state = 0;
    s32 zone = bastick_getZone(player);
    if (zone > 0)
        next_state = 0x166;
    bs_setState(player, func_80800084_bsbansack(player, next_state));
}

int bsbansack_entrypoint_0(s32 index)
{
    return D_80801E10_bsbansack[index];
}

int func_80800508_bsbansack(u8 *player)
{
    if (!player[0x15E]) {
        func_808002D4_bsbansack();
    }
    func_80800238_bsbansack(player);
}

void func_80800540_bsbansack(PlayerState *player)
{
    player->unk15C.bytes[2] = 0;
    baanim_playForDuration_onceSmooth(player, 0x143, 2.0f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009DE38(player, 0x583, 1.0f);
    bainput_enable(player, 2, 0);
}

void func_808005BC_bsbansack(Actor *player)
{
    s32 anim_ctrl;
    s32 next_state;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    bainput_enable(player, 2, 1);
    if (anctrl_isAt(anim_ctrl, 0.19f) != 0) {
        func_8009DE38(player, 0x57C, 1.0f);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f) != 0) {
        func_8009DBF0(player, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(anim_ctrl, 0.48f) != 0) {
        func_8009FE58(player);
    }
    if (anctrl_isAt(anim_ctrl, 0.52f) != 0) {
        func_8009DE38(player, 0x584, 1.0f);
    }
    if (anctrl_isAt(anim_ctrl, 0.123f) != 0) {
        func_800A0CD0(player, 0);
        _babackpack_set_state(player, 2);
    }
    if (anctrl_isAt(anim_ctrl, 0.5145f) != 0) {
        *(s8 *) ((char *) player + 0x15E) = 1;
        func_808002D4_bsbansack(player);
    }
    if (baanim_isStopped(player) != 0) {
        next_state = 0x165;
    }
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_1(s32 index)
{
    return D_80801E20_bsbansack[index];
}

void func_80800710_bsbansack(PlayerState *player)
{
    if (func_8009E6EC(player) == 0xC) {
        if (anctrl_getAnimTimer(baanim_getAnimCtrlPtr(player)) > 0.42f) {
            func_80099B94(player);
        }
    } else {
        func_80800168_bsbansack(player);
    }
}

void func_8080077C_bsbansack(s32 player)
{
    baphysics_reset_gravity();
    func_80800238_bsbansack(player);
}

void func_808007A4_bsbansack(PlayerState *player)
{
    func_808002D4_bsbansack(player);
    baanim_playForDuration_onceSmooth(player, 0x28A, 1.0f);
    func_8009FFD8(player, 1, 1, 3, 6);
    baphysics_set_gravity(player, -800.0f);
    baphysics_set_vertical_velocity(player, 300.0f);
}

void func_80800810_bsbansack(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 next_state;
    f32 unk_0;
    f32 unk_1;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    if (anctrl_isAt(anim_ctrl, 0.2f)) {
        func_8009DE38(player, 0x583, 1.1f);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f)) {
        func_8009DBF0(player, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(anim_ctrl, 0.73f)) {
        func_8009FE58(player);
    }
    if (anctrl_isAt(anim_ctrl, 0.77f)) {
        func_8009DE38(player, 0x584, 1.1f);
    }
    if (anctrl_getAnimTimer(anim_ctrl) < 0.515f) {
        func_808001D4_bsbansack(player);
    } else {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    }
    if (anctrl_isAt(anim_ctrl, 0.7307f)) {
        _babackpack_set_state(player, 1);
        func_800A0CD0(player, 1);
    }
    if (baanim_isStopped(player)) {
        next_state = 1;
    }
    if (anctrl_getAnimTimer(anim_ctrl) > 0.8f && bastick_getZone(player) > 0) {
        next_state = 4;
    }
    if (anctrl_getAnimTimer(anim_ctrl) > 0.95f && player_inWater(player)) {
        unk_1 = func_800964DC(player);
        unk_0 = func_80096364(player);
        if (unk_1 - unk_0 > 80.0f) {
            next_state = 0x4C;
        }
    }
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_2(s32 index)
{
    return D_80801E30_bsbansack[index];
}

void func_80800A14_bsbansack(PlayerState *player)
{
    if (player->unk15C.bytes[1] == 0) {
        player->unk15C.bytes[1] = 1;
        if (baphysics_get_vertical_velocity(player) < 0.0f) {
            baphysics_set_vertical_velocity(player, 0.0f);
        }
        func_808003C0_bsbansack(player);
    }
}

void func_80800A78_bsbansack(s32 player)
{
    if (*(u8 *) (player + 0x15D) != 0) {
        *(u8 *) (player + 0x15D) = 0;
        func_80800400_bsbansack();
    }
}

int func_80800AA4_bsbansack(PlayerState *player)
{
    return player_inWater(player) && (baphysics_get_vertical_velocity(player) < 0.0f);
}

void func_80800AF4_bsbansack(player, state) PlayerState *player;
s32 state;
{
    AnimCtrl *anim_ctrl;
    f32 velocity;

    *((u8 *) player + 0x15C) = state;
    switch (state) {
        case 1:
            anim_ctrl = baanim_getAnimCtrlPtr(player);
            func_80800A78_bsbansack(player);
            func_8009DB04(player, 0x3F0, func_800DC178(0.96f, 1.04f), 10000);
            func_8009FFD8(player, 1, 1, 1, 2);
            baphysics_set_gravity(player, -1350.0f);
            if (bastick_distance(player) != 0.0f) {
                yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
            }
            velocity = func_8009BB5C(player);
            baphysics_set_target_horizontal_velocity(player, velocity);
            baphysics_set_target_yaw(player, yaw_getIdeal(player));
            baphysics_set_horizontal_velocity(player, yaw_getIdeal(player), velocity);
            anctrl_reset(anim_ctrl);
            anctrl_setIndex(anim_ctrl, 0x144);
            anctrl_setSubrange(anim_ctrl, 0.0f, 0.35f);
            anctrl_setDuration(anim_ctrl, 0.7f);
            anctrl_setPlaybackType(anim_ctrl, 1);
            anctrl_start(anim_ctrl);
            baphysics_set_vertical_velocity(player, 710.0f);
            break;
        case 2:
            baanim_setEndAndDuration(player, 0.65f, 3.0f);
            break;
        case 3:
            if (player_inWater(player))
                func_80800A14_bsbansack(player);
            baanim_setEndAndDuration(player, 0.98f, 0.7f);
            break;
        case 4:
            if (player_inWater(player))
                func_80800A14_bsbansack(player);
            func_8009D2D8(player, 3);
            func_800A2FCC(player, 0);
            baanim_setEndAndDuration(player, 0.98f, 0.7f);
            break;
        case 0:
            func_80800A78_bsbansack(player);
            baphysics_reset_gravity(player);
            func_8009BF5C(player, 0.0f);
            baroll_setIdeal(player, 0.0f);
    }
}

void func_80800D4C_bsbansack(s32 player)
{
    func_80800AF4_bsbansack(player, 0);
    func_80800238_bsbansack(player);
}

void func_80800D78_bsbansack(Actor *player)
{
    ActorLocal_BSBansack *locals;
    func_808002D4_bsbansack();
    locals = (ActorLocal_BSBansack *) ((u8 *) player + 0x15A);
    // Matching: the increment needed for the match.
    locals++;
    locals->unk15B = 0;
    locals->unk15A = 0;
    func_80800AF4_bsbansack(player, 1);
}

void func_80800DAC_bsbansack(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (bakey_released(player, 8) && baphysics_get_vertical_velocity(player) > 0.0f) {
        baphysics_reset_gravity(player);
    }
    func_808001D4_bsbansack(player);
    switch (*((u8 *) player + 0x15C)) {
        case 1:
            if (baanim_isAt(player, 0.1f))
                func_8009D7A4(player, 0.95f, 1.05f);
            if (func_8008DF8C(player, 0x82) || func_80800AA4_bsbansack(player)) {
                func_80800AF4_bsbansack(player, 3);
            } else if (anctrl_isStopped(anim_ctrl)) {
                func_80800AF4_bsbansack(player, 2);
            }
            next_state = func_80800000_bsbansack(player, 0, 0);
            break;
        case 2:
            if (func_8008DF8C(player, 0x5A) || func_80800AA4_bsbansack(player)) {
                func_80800AF4_bsbansack(player, 3);
            }
            next_state = func_80800000_bsbansack(player, 0, 0);
            break;
        case 3:
            func_80800368_bsbansack(player);
            if (player_isStable(player) || player_inWater(player)) {
                func_80800AF4_bsbansack(player, 4);
            }
            next_state = func_80800000_bsbansack(player, 0, 0);
            break;
        case 4:
            func_80800368_bsbansack(player);
            if (anctrl_isStopped(anim_ctrl)) {
                if (baphysics_get_target_horizontal_velocity(player) > 0.0f)
                    next_state = 0x166;
                else if (player_inWater(player))
                    next_state = 0x167;
                else
                    next_state = 0x165;
            } else {
                baphysics_set_target_horizontal_velocity(player, 0.0f);
            }
            next_state = func_80800084_bsbansack(player, next_state);
    }
    if (func_8008E260(player))
        next_state = 0x3D;
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_3(s32 index)
{
    return D_80801E40_bsbansack[index];
}

int func_8080101C_bsbansack(BansackStruct *player, int state)
{
    f32 yaw;
    f32 unk_0;
    f32 delta;
    f32 wrapped;

    switch (state) {
        case 0:
            yaw_setIdeal(player, player->unk174);
            yaw_applyIdeal(player);
            func_800931AC(player, 1);
            break;
        case 1:
            yaw = yaw_get(player);
            player->unk174 = yaw;
            func_8009328C(player, yaw);
            func_800931AC(player, 3);
            _batimer_set(player, 0, 0x3F99999A);
            break;
        case 2:
            unk_0 = func_80092BE8(player);
            player->unk170 = unk_0;
            delta = func_800F1DCC(player->unk174, unk_0);
            wrapped = delta;
            if (delta < 0.0f) {
                wrapped = 360.0f + delta;
            }
            if (wrapped < 180.0f) {
                wrapped += 360.0f;
            }
            player->unk174 = (f32) (player->unk170 + wrapped);
            _batimer_set(player, 0, 0x3F000000);
    }
    player->unk15C = (s8) state;
}

void func_80801158_bsbansack(s32 player)
{
    func_8080101C_bsbansack(player, 0);
}

s32 func_80801178_bsbansack(s32 player)
{
    // Matching: unused result variable needed for the match.
    s32 result;
    *(u8 *) ((char *) player + 0x15C) = 0;

    result = func_8080101C_bsbansack(player, 1);
}

int func_8080119C_bsbansack(PlayerState *player)
{
    f32 range;
    f32 blend;
    f32 rate;
    f32 delta_time;
    f32 unk_0;

    unk_0 = func_80092BE8(player);
    delta_time = func_800D8FF8();
    _batimer_decrement(player, 0);
    switch (*((u8 *) player + 0x15C)) {
        case 1:
            rate = func_800F10B4(_batimer_get(player, 0), 0.0f, 1.2f, 700.0f, 1400.0f);
            unk_0 += rate * delta_time;
            func_8009328C(player, unk_0);
            if (func_8008DF8C(player, 1)) {
                player->unk16C = rate;
                func_8080101C_bsbansack(player, 2);
            }
            return 0;
        case 2:
            blend = func_800F10B4(_batimer_get(player, 0), 0.0f, 0.5f, 1.0f, 0.0f);
            range = player->unk174 - player->unk170;
            unk_0 = func_80013970(blend * 90.0f) * range + player->unk170;
            func_8009328C(player, unk_0);
            if (_batimer_get(player, 0) != 0.0f)
                return 0;
            return 1;
        default:
            return 0;
    }
}

void func_80801318_bsbansack(s32 player)
{
    func_80801158_bsbansack(player);
    _babounce_entrypoint_3(player);
    func_80800238_bsbansack(player);
}

void func_80801348_bsbansack(Actor *player)
{
    func_808002D4_bsbansack();
    baanim_playForDuration_onceSmooth(player, 0x28C, 1.2f);
    _babounce_entrypoint_4(player, 1);
    func_80801178_bsbansack(player);
}

void func_80801390_bsbansack(Actor *actor)
{
    s32 player;
    s32 next_state;
    // Matching: the copy into a local is needed for the match.
    player = actor;
    next_state = 0;
    if (_babounce_entrypoint_2(player)) {
        func_808001D4_bsbansack(player);
    }
    _babounce_entrypoint_10(player);
    if (func_8080119C_bsbansack(player) != 0) {
        next_state = 0x165;
    }
    if (func_8008DF8C(player, 1) != 0) {
        if (bastick_getZone(player) > 0) {
            next_state = 0x166;
        }
        next_state = func_80800084_bsbansack(player, next_state);
    }
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_4(s32 index)
{
    return D_80801E50_bsbansack[index];
}

void func_8080143C_bsbansack(s32 player)
{
    func_80801158_bsbansack(player);
    _babounce_entrypoint_3(player);
    func_80800238_bsbansack(player);
}

void func_8080146C_bsbansack(Actor *player)
{
    func_808002D4_bsbansack();
    baanim_playForDuration_onceSmooth(player, 652, 1.2f);
    _babounce_entrypoint_4(player, 2);
    func_80801178_bsbansack(player);
}

void func_808014B4_bsbansack(Actor *actor)
{
    s32 player;
    s32 next_state;
    // Matching: the copy into a local is needed for the match.
    player = actor;
    next_state = 0;
    if (_babounce_entrypoint_2(player)) {
        func_808001D4_bsbansack(player);
    }
    _babounce_entrypoint_10(player);
    if (func_8080119C_bsbansack(player) != 0) {
        next_state = 0x165;
    }
    if (func_8008DF8C(player, 1) != 0) {
        if (bastick_getZone(player) > 0) {
            next_state = 0x166;
        }
        next_state = func_80800084_bsbansack(player, next_state);
    }
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_5(s32 index)
{
    return D_80801E60_bsbansack[index];
}

void func_80801560_bsbansack(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800238_bsbansack(player);
}

void func_80801588_bsbansack(s32 player)
{
    func_808002D4_bsbansack();
    _bsdrone_entrypoint_0(player);
}

void func_808015B0_bsbansack(PlayerState *player)
{
    _bsdrone_entrypoint_1(player);
}

int bsbansack_entrypoint_6(s32 index)
{
    return D_80801E70_bsbansack[index];
}

void func_808015E4_bsbansack(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800238_bsbansack(player);
}

void func_8080160C_bsbansack(s32 player)
{
    func_808002D4_bsbansack();
    _bsrest_entrypoint_16(player);
}

int func_80801634_bsbansack(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20(player)) {
        next_state = 0x165;
    }
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_7(s32 index)
{
    return D_80801E80_bsbansack[index];
}

void func_80801680_bsbansack(player, state) PlayerState *player;
s32 state;
{
    AnimCtrl *anim_ctrl;
    f32 velocity;
    f32 duration;
    f32 jump_velocity;
    s32 in_water;
    s32 do_jump;
    f32 duration_scale;

    player->unk15C.bytes[0] = state;
    switch (state) {
        case 1:
            anim_ctrl = baanim_getAnimCtrlPtr(player);
            in_water = player_inWater(player);
            do_jump = player_isStable(player) || in_water;
            func_80800A78_bsbansack(player);
            func_8009DB04(player, 0x3F0, func_800DC178(0.96f, 1.04f), 10000);
            func_800A2EEC(player, 4);
            func_8009FFD8(player, 1, 1, 1, 2);
            if (bastick_distance(player) != 0.0f) {
                yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
            }
            func_808001D4_bsbansack(player);
            velocity = baphysics_get_target_horizontal_velocity(player);
            if (in_water) {
                duration = func_800F10B4(velocity, 100.0f, 500.0f, 0.35f, 0.7f * 0.6f);
                jump_velocity = func_800F10B4(velocity, 100.0f, 500.0f, 346.75f, 693.5f * 0.6f);
            } else {
                duration = func_800F10B4(velocity, 100.0f, 500.0f, 0.35f, 0.7f);
                jump_velocity = func_800F10B4(velocity, 100.0f, 500.0f, 346.75f, 693.5f);
            }
            baphysics_set_target_yaw(player, yaw_getIdeal(player));
            baphysics_set_horizontal_velocity(player, yaw_getIdeal(player), velocity);
            anctrl_reset(anim_ctrl);
            anctrl_setIndex(anim_ctrl, 0x144);
            anctrl_setSubrange(anim_ctrl, 0, 0.6466f);
            anctrl_setDuration(anim_ctrl, duration);
            anctrl_setPlaybackType(anim_ctrl, 1);
            anctrl_start(anim_ctrl);
            if (do_jump) {
                baphysics_set_vertical_velocity(player, jump_velocity);
            }
            break;
        case 2:
            baanim_setEndAndDuration(player, 0.7965f, 3.0f);
            break;
        case 3:
            if (player_inWater(player)) {
                func_80800A14_bsbansack(player);
            }
            baanim_setEndAndDuration(player, 0.98f, 0.7f);
            break;
        case 4:
            duration_scale = 1.0f;
            player->unk16C = func_8009BB5C(player) * 0.25f;
            func_8009D2D8(player, 3);
            baphysics_set_target_horizontal_velocity(player, player->unk16C);
            func_800A2FCC(player, 0);
            if (player_inWater(player)) {
                func_80800A14_bsbansack(player);
                duration_scale = 0.4f;
            }
            baanim_setEndAndDuration(player, 0.98f, 0.7f * duration_scale);
            break;
        case 0:
            func_80800A78_bsbansack(player);
            func_8009BF5C(player, 0.0f);
            baroll_setIdeal(player, 0.0f);
    }
}

void func_80801A04_bsbansack(s32 player)
{
    func_80801680_bsbansack(player, 0);
    func_80800238_bsbansack(player);
}

void func_80801A30_bsbansack(void *player)
{
    func_808002D4_bsbansack();
    *(u8 *) ((char *) player + 0x15D) = 0;
    *(u8 *) ((char *) player + 0x15C) = 0;
    func_80801680_bsbansack(player, 1);
}

void func_80801A64_bsbansack(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808001D4_bsbansack(player);
    switch (player->unk15C.bytes[0]) {
        case 1:
            if (baanim_isAt(player, 0.05f))
                func_8009DEC0(player, 0x58A, 0.95f, 1.05f, 9000, 11000);
            if (func_8008DF8C(player, 0x82) || func_80800AA4_bsbansack(player))
                func_80801680_bsbansack(player, 3);
            else if (anctrl_isStopped(anim_ctrl))
                func_80801680_bsbansack(player, 2);
            next_state = func_80800000_bsbansack(player, 0, 1);
            break;
        case 2:
            if (func_8008DF8C(player, 0x82) || func_80800AA4_bsbansack(player))
                func_80801680_bsbansack(player, 3);
            next_state = func_80800000_bsbansack(player, 0, 1);
            break;
        case 3:
            func_80800368_bsbansack(player);
            if (player_isStable(player) || player_inWater(player))
                func_80801680_bsbansack(player, 4);
            next_state = func_80800000_bsbansack(player, 0, 1);
            break;
        case 4:
            func_80800368_bsbansack(player);
            if (anctrl_isStopped(anim_ctrl)) {
                if (baphysics_get_target_horizontal_velocity(player) > 0.0f)
                    func_80801680_bsbansack(player, 1);
                else if (player_inWater(player))
                    next_state = 0x167;
                else
                    next_state = 0x165;
            } else
                baphysics_set_target_horizontal_velocity(player, player->unk16C);
            next_state = func_80800084_bsbansack(player, next_state);
    }
    if (func_8008E260(player))
        next_state = 0x3D;
    bs_setState(player, next_state);
}

int bsbansack_entrypoint_8(s32 index)
{
    return D_80801E90_bsbansack[index];
}

void func_80801CB4_bsbansack()
{
    func_80800238_bsbansack();
}

void func_80801CD4_bsbansack(s32 player)
{
    func_808002D4_bsbansack();
    baanim_playForDuration_loopSmooth(player, 0x289, 1.0f);
    func_8009FFD8(player, 1, 1, 1, 2);
}

void func_80801D20_bsbansack(PlayerState *player)
{
    s32 next_state;
    next_state = 0;
    if (bastick_getZone(player) > 0)
        next_state = 0x166;
    if (player_inWater(player))
        next_state = 0x167;
    next_state = func_80800084_bsbansack(player, next_state);
    if (func_8008E260(player))
        next_state = 0x3D;
    bs_setState(player, next_state);
}

s32 bsbansack_entrypoint_9(s32 index)
{
    return D_80801EA0_bsbansack[index];
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of
// this file; IDO schedules some of them differently unless the tables are in the same unit.
s32 D_80801E10_bsbansack[4] = {(u32) func_80800434_bsbansack, (u32) func_8080045C_bsbansack,
                               (u32) func_808004B0_bsbansack, (u32) func_80800168_bsbansack};
s32 D_80801E20_bsbansack[4] = {(u32) func_80800508_bsbansack, (u32) func_80800540_bsbansack,
                               (u32) func_808005BC_bsbansack, (u32) func_80800168_bsbansack};
s32 D_80801E30_bsbansack[4] = {(u32) func_8080077C_bsbansack, (u32) func_808007A4_bsbansack,
                               (u32) func_80800810_bsbansack, (u32) func_80800710_bsbansack};
s32 D_80801E40_bsbansack[4] = {(u32) func_80800D4C_bsbansack, (u32) func_80800D78_bsbansack,
                               (u32) func_80800DAC_bsbansack, (u32) func_80800168_bsbansack};
s32 D_80801E50_bsbansack[4] = {(u32) func_80801318_bsbansack, (u32) func_80801348_bsbansack,
                               (u32) func_80801390_bsbansack, (u32) func_808001B0_bsbansack};
s32 D_80801E60_bsbansack[4] = {(u32) func_8080143C_bsbansack, (u32) func_8080146C_bsbansack,
                               (u32) func_808014B4_bsbansack, (u32) func_808001B0_bsbansack};
s32 D_80801E70_bsbansack[4] = {(u32) func_80801560_bsbansack, (u32) func_80801588_bsbansack,
                               (u32) func_808015B0_bsbansack, (u32) func_8080018C_bsbansack};
s32 D_80801E80_bsbansack[4] = {(u32) func_808015E4_bsbansack, (u32) func_8080160C_bsbansack,
                               (u32) func_80801634_bsbansack, (u32) func_80800168_bsbansack};
s32 D_80801E90_bsbansack[4] = {(u32) func_80801A04_bsbansack, (u32) func_80801A30_bsbansack,
                               (u32) func_80801A64_bsbansack, (u32) func_80800168_bsbansack};
s32 D_80801EA0_bsbansack[4] = {(u32) func_80801CB4_bsbansack, (u32) func_80801CD4_bsbansack,
                               (u32) func_80801D20_bsbansack, (u32) func_80800168_bsbansack};
