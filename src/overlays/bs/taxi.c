#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void bainput_enable(PlayerState *, s32, s32);
extern int D_80802130_bstaxi[];
extern void func_8009C128(PlayerState *, f32 *);
extern s32 _bapackctrl_entrypoint_1(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern f32 yaw_get(PlayerState *);
extern void func_800CB598(s32, f32 *, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_8009BF5C(s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 func_80096364(PlayerState *);
extern u8 D_80802140_bstaxi[];
extern f32 _batimer_get(PlayerState *, s32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800F3BB0(PlayerState *, f32 *);
extern s32 D_80802188_bstaxi[];
extern s32 D_80802198_bstaxi[];
extern s32 D_808021A8_bstaxi[];
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 bakey_released(PlayerState *, s32);
extern void baphysics_reset_gravity(PlayerState *);
extern s32 func_8008DF8C(PlayerState *, s32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void func_8009D3A8(PlayerState *, s32);
extern s32 player_isStable(PlayerState *);
extern void func_8009FE58(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern void func_8009D2D8(PlayerState *, s32);
extern s32 bakey_pressed(PlayerState *, s32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 player_inWater(PlayerState *);
extern s32 func_8008E148(PlayerState *);
extern s32 func_8008E260(PlayerState *);
extern void bs_setState(PlayerState *, s32);
extern s32 D_808021B8_bstaxi[];
extern void func_800A2CE8(PlayerState *, f32, s32);
extern s32 D_808021C8_bstaxi[];
extern s32 D_808021D8_bstaxi[];
extern s32 D_808021E8_bstaxi[];
extern s32 D_808021F8_bstaxi[];
extern s32 D_808020D0_bstaxi[];
extern s32 D_808020F0_bstaxi[];
extern s32 D_80802110_bstaxi[];
extern s32 baanim_isAt(PlayerState *, f32);
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern void func_800CB5D4(s32, f32 *, f32);
extern void _bapackctrl_entrypoint_4();
extern void func_800A0CD0();
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void _babackpack_entrypoint_6();
extern f32 func_80099A34(PlayerState *);
extern void func_8009DC98(PlayerState *, s32, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009DFD4(PlayerState *, s32, f32, f32, s32, s32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void _subaddietaxi_entrypoint_8(s32, f32 *, f32, f32, s32);

void func_80800000_bstaxi(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 200.0f));
    }
}

// Maps buttons to Taxi Pack states: Z release -> 0x127, B -> 0x124, A -> 0x126.
int func_80800064_bstaxi(s32 player, s32 next_state)
{
    if (bakey_released(player, 1)) {
        next_state = 0x127;
    }
    if (bakey_pressed(player, 9)) {
        next_state = 0x124;
    }
    if (bakey_pressed(player, 8)) {
        next_state = 0x126;
    }
    // Matching: no-op `| 0` is needed for the match.
    return next_state | 0;
}

void bstaxi_entrypoint_0(player)
{
    if (!func_8009E74C(player, 0xE)) {
        func_800A0CD0(player, 1);
        _babackpack_set_state(player, 1);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        bastick_popZone(player);
        func_8009E474(player);
    }
}

void bstaxi_entrypoint_1(player) PlayerState *player;
{
    if (!func_8009E77C(player, 0xE)) {
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 1.0f);
        func_8009E4AC(player);
    }
}

void bstaxi_entrypoint_2(void *player)
{
    ((u32 *) player)[0x58] = 0;
    bstaxi_entrypoint_0(player);
}

void bstaxi_entrypoint_3(PlayerState *player)
{
    bstaxi_entrypoint_1(player);
    baanim_playForDuration_onceSmooth(player, 0x129, 5.0f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    bainput_enable(player, 0, 0);
}

void bstaxi_entrypoint_4(PlayerState *player)
{
    s32 next_state;
    f32 pack_pos[3];
    s32 slot;
    next_state = 0;
    bainput_enable(player, 0, 1);
    func_8009D3A8(player, 0);
    if (baanim_isAt(player, 0.0161f)) {
        _babackpack_set_state(player, 3);
        func_800A0CD0(player, 0);
    }
    if (baanim_isAt(player, 0.33f))
        func_8009D454(player, 0, &D_808020D0_bstaxi);
    if (baanim_isAt(player, 0.435f))
        func_8009D454(player, 0, &D_808020F0_bstaxi);
    if (baanim_isAt(player, 0.545f))
        func_8009D454(player, 0, &D_80802110_bstaxi);
    if (baanim_isAt(player, 0.5662f)) {
        _babackpack_entrypoint_6(player, pack_pos, 0);
        slot = _bapackctrl_entrypoint_1(player);
        _bapackctrl_entrypoint_4(player, 0);
        func_8009DB04(player, 0x5C2, 1.8f, 0x7FFF);
        func_800CB598(slot, pack_pos, yaw_get(player));
    }
    if (baanim_isAt(player, 0.8153f)) {
        _babackpack_set_state(player, 1);
        func_800A0CD0(player, 1);
    }
    if (baanim_isStopped(player))
        next_state = 1;
    if (baanim_getTimer(player) > 0.8153f && bastick_getZone(player) > 0)
        next_state = 2;
    bs_setState(player, next_state);
}

int bstaxi_entrypoint_5(s32 player)
{
    return D_80802130_bstaxi[player];
}

void func_80800420_bstaxi(PlayerState *player)
{
    f32 pos[3];
    s32 slot;
    func_8009C128(player, pos);
    pos[1] += 50.0f;
    slot = _bapackctrl_entrypoint_1(player);
    _bapackctrl_entrypoint_4(player, 0);
    func_8009DB04(player, 0x5C2, 1.8f, 0x7FFF);
    func_800CB598(slot, pos, yaw_get(player));
}

void func_808004A8_bstaxi(s32 player)
{
    s32 interrupt;

    interrupt = func_8009E6EC();
    switch (interrupt) {
        case 0x1F:;
        case 0x20:
        case 0x21:;
        case 0x24:
        case 0x2D:;
        case 0x2E:
        case 0x45:;
        case 0x4E:
        case 0x51:;
        case 0x52:
        case 0x59:;
        case 0x5A:
        case 0x5B:;
        case 0x5C:
            func_80800420_bstaxi(player);
            func_80099B94(player);
            return;
        case 0x15:;
        case 0x1C:
        case 0x1D:;
        case 0x1E:
        case 0x25:;
        case 0x43:
            func_80800420_bstaxi(player);
            func_80099B94(player);
            return;
        default:
            func_80099B94(player);
    }
}

void func_80800524_bstaxi(PlayerState *player)
{
    f32 stick_dist;
    f32 speed;
    f32 angle;
    f32 velocity[3];
    stick_dist = bastick_distance(player);
    if (stick_dist == 0.0f)
        _bamovehover_entrypoint_4(player, NULL);
    else {
        angle = bastick_getAngleRelativeToBanjo(player);
        speed = func_800F10B4(stick_dist, 0.0f, 1.0f, 0.0f, 400.0f);
        func_800EEB9C(velocity, angle, speed);
        _bamovehover_entrypoint_4(player, velocity);
    }
}

s32 func_808005B8_bstaxi(Actor *player)
{
    baroll_setIdeal(player, 0);
    func_8009BF5C(player, 0);
    bstaxi_entrypoint_0(player);
}

// Starts the timed hover.
void func_808005F0_bstaxi(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 pos[3];
    f32 height;

    bstaxi_entrypoint_1(player);
    _batimer_set(player, 0, *(f32 *) ((u8 *) player + 0x16C));
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x24A);
    anctrl_setDuration(anim_ctrl, 3.0f);
    func_8008B1C8(anim_ctrl, 0.6f);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 3, 1, 0x13);
    yaw_setVelocityBounded(player, 300.0f, 3.5f);
    func_8009C128(player, pos);
    height = func_80096364(player) + 200.0f;
    if (height < pos[1]) {
        height = pos[1] + 200.0f;
    }
    pos[1] = height;
    _bamovehover_entrypoint_3(player, pos);
}

// Hover update: counts down the timer and unloads the passenger when it ends or on B.
void func_808006F4_bstaxi(PlayerState *player)
{
    s32 next_state = 0;
    s32 done = 0;
    s32 unk_0;
    f32 pos[3];
    _batimer_decrement(player, 0);
    func_800D2498(0x100, (s32) _batimer_get(player, 0), 0);
    func_80800524_bstaxi(player);
    if (func_8001210C(1)) {
        unk_0 = func_800B5BE4(0x1C);
        func_800F3BB0(player, pos);
        func_800BABB8(unk_0, pos, pos, 1.0f, D_80802140_bstaxi);
        func_800BA22C(unk_0, 1);
    }
    if (_batimer_isZero(player, 0)) {
        done = 1;
        next_state = 0x2F;
    } else if (bakey_pressed(player, 9)) {
        done = 1;
        next_state = 0x2F;
    }
    if (done)
        func_80800420_bstaxi(player);
    bs_setState(player, next_state);
}

int bstaxi_entrypoint_6(s32 player)
{
    return D_80802188_bstaxi[player];
}

void bstaxi_entrypoint_7()
{
    bstaxi_entrypoint_0();
}

int bstaxi_entrypoint_8(Actor *player)
{
    bstaxi_entrypoint_1(player);
    baanim_playForDuration_onceSmooth(player, 0xf3, 1.1f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    bainput_enable(player, 0, 0);
}

void bstaxi_entrypoint_9(PlayerState *player)
{
    s32 next_state = 0;
    f32 anim_time;
    bainput_enable(player, 0, 1);
    if (baanim_isAt(player, 0.3f))
        func_8009DEC0(player, 0x588, 0.95f, 1.05f, 20000, 22000);
    func_8009D3A8(player, 0);
    if (baanim_isAt(player, 0.084f)) {
        _babackpack_set_state(player, 3);
        func_800A0CD0(player, 0);
    }
    if (baanim_isStopped(player))
        next_state = 0x125;
    anim_time = baanim_getTimer(player);
    if (anim_time > 0.6723f) {
        if (bastick_getZone(player) > 0)
            next_state = 0x123;
        if (bakey_released(player, 1))
            next_state = 0x127;
    }
    if (anim_time > 0.2f && bakey_pressed(player, 9))
        next_state = 0x124;
    bs_setState(player, next_state);
}

int bstaxi_entrypoint_10(s32 player)
{
    return D_80802198_bstaxi[player];
}

// Switches sub-state; the current one is stored at +0x15C.
void func_80800A18_bstaxi(void *player, unsigned int sub_state)
{
    switch (sub_state) {
        case 0:
            if (((u8 *) player)[0x15c] == 3) {
                _bapackctrl_entrypoint_5(player, 2);
            }
            break;

        case 1:
            ((u8 *) player)[0x15d] = 0;
            baanim_playForDuration_onceSmooth(player, 0x121, 1.1f);
            bainput_enable(player, 0, 0);
            break;

        case 2:
            baanim_playForDuration_loopSmooth(player, 0x12B, 4.5f);
            break;

        case 3:
            baanim_playForDuration_onceSmooth(player, 0x12D, 2.8f);
            break;

        case 4:
            baanim_playForDuration_onceSmooth(player, 0x12C, 1.4f);
    }

    ((u8 *) player)[0x15c] = sub_state;
}

void bstaxi_entrypoint_11(s32 player)
{
    func_80800A18_bstaxi(player, 0);
    bstaxi_entrypoint_0(player);
}

void bstaxi_entrypoint_12(s32 player)
{
    bstaxi_entrypoint_1();
    func_8009FFD8(player, 1, 1, 3, 2);
    // Matching: the masked zero is needed for the match.
    baphysics_set_target_horizontal_velocity(
        player, ((0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
    func_80800A18_bstaxi(player, 1);
}

void bstaxi_entrypoint_13(PlayerState *player)
{
    s32 next_state = 0;
    f32 anim_time;
    Vec3f pos;
    Vec3f hit_pos;
    Vec3f pack_pos;
    s32 slot;

    anim_time = baanim_getTimer(player);
    func_8009D3A8(player, 0);
    switch (((u8 *) player)[0x15C]) {
        case 1:
            bainput_enable(player, 0, 1);
            if (baanim_isAt(player, 0.084f)) {
                _babackpack_set_state(player, 3);
                func_800A0CD0(player, 0);
            }
            if (bakey_pressed(player, 9)) {
                ((u8 *) player)[0x15D] = 1;
            }
            if ((anim_time > 0.3883f && ((u8 *) player)[0x15D]) || baanim_isStopped(player)) {
                func_80800A18_bstaxi(player, 2);
            }
            break;
        case 2:
            if (bakey_pressed(player, 9) || ((u8 *) player)[0x15D]) {
                ((u8 *) player)[0x15D] = 0;
                func_8009C128(player, pos.f);
                func_800EF1B8(pos.f, yaw_get(player), 45.0f);
                pos.pos.y += 80.0f;
                // Ray probe blocks dropping inside walls.
                if (func_800C6C94(pos.f, 40.0f, hit_pos.f, 0x420020)) {
                    func_800FC6B0(0xF);
                } else {
                    func_80800A18_bstaxi(player, 3);
                }
            }
            if (bakey_released(player, 1)) {
                func_80800A18_bstaxi(player, 4);
            }
            break;
        case 3:
            if (baanim_isAt(player, 0.16f)) {
                _babackpack_entrypoint_6(player, pack_pos.f, 0);
                slot = _bapackctrl_entrypoint_1(player);
                _bapackctrl_entrypoint_4(player, 0);
                func_8009DEC0(player, 0x53C, 0.95f, 1.05f, 0x6978, 0x6D60);
                func_800CB5D4(slot, pack_pos.f, yaw_get(player));
            }
            if (baanim_isAt(player, 0.6511f)) {
                _babackpack_set_state(player, 1);
                func_800A0CD0(player, 1);
            }
            if (anim_time > 0.6511f) {
                next_state = 0x20;
            }
            break;
        case 4:
            if (baanim_isAt(player, 0.48f)) {
                func_8009DEC0(player, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
            }
            if (baanim_isAt(player, 0.5053f)) {
                _babackpack_set_state(player, 1);
                func_800A0CD0(player, 1);
            }
            if (anim_time > 0.5053f) {
                next_state = 0x20;
            }
    }
    bs_setState(player, next_state);
}

int bstaxi_entrypoint_14(s32 player)
{
    return D_808021A8_bstaxi[player];
}

void bstaxi_entrypoint_15(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    bstaxi_entrypoint_1(player);
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x125);
    anctrl_setStart(anim_ctrl, 0.1522f);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.3824f);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    if (bastick_distance(player) != 0.0f)
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800000_bstaxi(player);
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 500.0f);
    baphysics_set_gravity(player, -1900.0f);
    func_8009D7A4(player, 0.91f, 1.09f);
    *(u8 *) ((u8 *) player + 0x15C) = 0;
}

// Jump while carrying (A).
void bstaxi_entrypoint_16(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_80800000_bstaxi(player);
    func_8009BB24(player, velocity);
    if (bakey_released(player, 8) && 0.0f < velocity[1]) {
        baphysics_reset_gravity(player);
    }
    switch (player->unk15C.bytes[0]) {
        case 0:
            if (func_8008DF8C(player, 0x82)) {
                baanim_setEndAndDuration(player, 1.0, 0.7f);
                player->unk15C.bytes[0] = 2;
            } else if (anctrl_isStopped(anim_ctrl)) {
                baanim_setEndAndDuration(player, 0.472f, 3.0f);
                player->unk15C.bytes[0] = 1;
            }
            break;
        case 1:
            if (func_8008DF8C(player, 0x82)) {
                baanim_setEndAndDuration(player, 1.0, 1.0f);
                player->unk15C.bytes[0] = 2;
            }
            break;
        case 2:
            func_8009D3A8(player, 0);
            if (player_isStable(player)) {
                func_8009FE58(player);
                baanim_setEndAndDuration(player, 1.0, 1.0f);
                player->unk15C.bytes[0] = 3;
            }
            break;
        case 3:
            baphysics_set_target_horizontal_velocity(player, func_8009BB5C(player) * 0.25f);
            func_8009D2D8(player, 3);
            func_8009D3A8(player, 0);
            if (0.0f < func_8009BB5C(player)) {
                next_state = 0x123;
            } else if (anctrl_isStopped(anim_ctrl)) {
                next_state = 0x125;
            }
            if (bakey_pressed(player, 9)) {
                next_state = 0x124;
            }
    }
    if (baphysics_get_vertical_velocity(player) < 0.0f && player_inWater(player)) {
        next_state = 0x4C;
    }
    if (player_isStable(player) && bakey_pressed(player, 8)) {
        next_state = 0x126;
    }
    if (func_8008E148(player)) {
        next_state = 1;
    }
    if (func_8008E260(player)) {
        next_state = 0x3D;
    }
    bs_setState(player, next_state);
}

void bstaxi_entrypoint_17(s32 player)
{
    baphysics_reset_gravity(player);
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    bstaxi_entrypoint_0(player);
}

int bstaxi_entrypoint_18(s32 player)
{
    return D_808021B8_bstaxi[player];
}

void bstaxi_entrypoint_19()
{
    bstaxi_entrypoint_0();
}

void bstaxi_entrypoint_20(PlayerState *player)
{
    bstaxi_entrypoint_1(player);
    baanim_playForDuration_loopSmooth(player, 0xF4, 1.0f);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 200.0f, 1.1f, 0.53f);
    func_8008CA30(player, 1.0f);
}

void bstaxi_entrypoint_21(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_8009D3A8(player, 0);
    func_800A2CE8(player, 0.1f, 4);
    func_800A2CE8(player, 0.6f, 3);
    func_80800000_bstaxi(player);
    if (!bastick_getZone(player))
        next_state = 0x125;
    next_state = func_80800064_bstaxi(player, next_state);
    if (func_8008E148(player))
        next_state = 1;
    if (func_8008E260(player))
        next_state = 0x3D;
    if (player_inWater(player))
        next_state = 0x4C;
    bs_setState(player, func_800A02DC(player, next_state));
}

int bstaxi_entrypoint_22(s32 player)
{
    return D_808021C8_bstaxi[player];
}

void bstaxi_entrypoint_23()
{
    bstaxi_entrypoint_0();
}

int bstaxi_entrypoint_24(Actor *player)
{
    bstaxi_entrypoint_1(player);
    baanim_playForDuration_onceSmooth(player, 0x128, 1.4f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
}

void bstaxi_entrypoint_25(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_8009D3A8(player, 0);
    if (baanim_isAt(player, 0.5053f)) {
        _babackpack_set_state(player, 1);
        func_800A0CD0(player, 1);
    }
    if (baanim_isAt(player, 0.48f))
        func_8009DEC0(player, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
    if (baanim_getTimer(player) > 0.5053f)
        next_state = 0x20;
    bs_setState(player, next_state);
}

int bstaxi_entrypoint_26(s32 player)
{
    return D_808021D8_bstaxi[player];
}

// Sets sub-state; +0x160 is the passenger actor, +0x164 its slot, +0x16C the hover time.
void func_80801600_bstaxi(player, sub_state) u8 *player;
u32 sub_state;
{
    // Matching: the unused pad local is needed for the match.
    s8 _sfpad[8];
    s32 unk_0;
    s32 passenger;

switch (sub_state) {
    case 0:
        if (func_8008E0C8(player) != 0) {
            _bapackctrl_entrypoint_5(player, 1);
        }
        baflag_clear(player, 0x33);
        func_8009E55C(player, 2, 0.0f);
        passenger = *(s32 *) ((s8 *) player + 0x160);
        if (passenger != 0) {
            func_800FFA88(passenger);
            *(s32 *) ((s8 *) player + 0x160) = 0;
        }
        break;
    case 1:
        *(s32 *) ((s8 *) player + 0x160) = 0;
        *(f32 *) ((s8 *) player + 0x16C) = 0.0f;
        func_8009E55C(player, 2, 50.0f);
        func_8009E4E0(player, 2, &_babackpack_entrypoint_6);
        break;
    case 2:
        _bapackctrl_entrypoint_4(player, *(u8 *) ((s8 *) player + 0x164));
        baflag_clear(player, 0x33);
        _batimer_set(player, 0, 0.5f);
        func_8009C128(player, &unk_0);
        _subaddietaxi_entrypoint_7(*(s32 *) ((s8 *) player + 0x160));
        break;
    case 3:
        func_8009DBB0(player, 0x5AD, 0x3F666666, 0x3F8CCCCD, 0x3E80);
        break;
    case 4:
        func_800CB698(*(u8 *) ((s8 *) player + 0x164), 2);
        func_800FFA88(*(s32 *) ((s8 *) player + 0x160));
        *(s32 *) ((s8 *) player + 0x160) = 0;
        break;
    case 5:
        baanim_playForDuration_onceSmooth(player, 0x126, 2.5f);
}

(*(s8 *) ((s8 *) (player) + (0x15C))) = (s8) sub_state;
}

void bstaxi_entrypoint_27(s32 player)
{
    func_80801600_bstaxi(player, 0);
    bstaxi_entrypoint_0(player);
}

void bstaxi_entrypoint_28(PlayerState *player)
{
    bstaxi_entrypoint_1(player);
    baanim_playForDuration_onceSmooth(player, 0xF5, 0.7f);
    func_8009FFD8(player, 1, 1, 3, 2);
    player->unk15C.bytes[0] = 0;
    func_80801600_bstaxi(player, 1);

}

void bstaxi_entrypoint_29(PlayerState *player)
{
    switch (func_8009E6EC(player)) {
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x24:
        case 0x2D:
        case 0x2E:
        case 0x45:
        case 0x4E:
        case 0x51:
        case 0x52:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
            if (player->unk16C > 0.0f) {
                func_808004A8_bstaxi(player);
                return;
            }
            if (player->unk160.word == 0) {
                func_80099B94(player);
            }
            return;
        case 0x15:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x25:
        case 0x43:
            if (player->unk16C > 0.0f) {
                func_808004A8_bstaxi(player);
            }
            break;
        case 0x48:
            if (player->unk160.word) {
                func_8009E830(player, 1);
                return;
            }
            player->unk160.word = func_80099A4C(player);
            player->unk164.bytes[0] = func_80099A58(player);
            func_80801600_bstaxi(player, 2);
            func_8009E830(player, 2);
            return;
        case 0x6E:
            player->unk16C = func_80099A34(player);
            func_8009E830(player, 2);
            return;
        default:
            func_80099B94(player);
    }

}

void bstaxi_entrypoint_30(PlayerState *player)
{
    s32 next_state = 0;
    f32 pack_pos[3];
    f32 unk_2;
    f32 unk_3;

    func_8009D3A8(player, 0);

switch (((u8 *) player)[0x15C]) {
    case 1:
        func_80800000_bstaxi(player);
        if (baflag_isTrue(player, 0x33)) {
            baflag_clear(player, 0x33);
        }
        if (baanim_isAt(player, 0.2f)) {
            baflag_set(player, 0x33);
        }
        if (baanim_isAt(player, 0.35f)) {
            func_80801600_bstaxi(player, 3);
        }
        break;
    case 2:
        if (baanim_isAt(player, 0.44f)) {
            func_8009DC98(player, 0x5AC, 0.95f, 1.05f);
        }
        if (baanim_isAt(player, 0.64f)) {
            baphysics_set_target_horizontal_velocity(player, 0);
        }
        _babackpack_entrypoint_6(player, pack_pos, 0);
        unk_3 = func_800F10B4(_batimer_get(player, 0), 0.0f, 0.5f, 0, 1.0f);
        unk_2 = func_800F10B4(_batimer_get(player, 0), 0.19999999f, 0.5f, 0.0f, 1.0f);
        _subaddietaxi_entrypoint_8(*(s32 *) ((u8 *) player + 0x160), pack_pos, unk_2, unk_3,
                                   _bapackctrl_entrypoint_1(player));
        if (_batimer_decrement(player, 0)) {
            func_80801600_bstaxi(player, 4);
        }
        break;
    case 3:
        if (baanim_isAt(player, 0.64f)) {
            baphysics_set_target_horizontal_velocity(player, 0);
        }
        if (baanim_isStopped(player)) {
            next_state = 0x125;
        }
        break;
    case 4:
        if (baanim_isStopped(player)) {
            func_80801600_bstaxi(player, 5);
        }
        break;
    case 5:
        if (baanim_isAt(player, 0.1f)) {
            func_8009DF18(player, 0x5AF, 1.0f, 0x6D60);
        }
        if (baanim_isAt(player, 0.3f)) {
            func_8009DF18(player, 0x5AF, 0.9f, 0x6D60);
        }
        if (baanim_isAt(player, 0.5f)) {
            func_8009DFD4(player, 0x5AE, 0.95f, 1.05f, 0x4E20, 0x55F0);
        }
        if (baanim_isAt(player, 0.707f)) {
            _babackpack_set_state(player, 1);
            func_800A0CD0(player, 1);
            _bapackctrl_entrypoint_5(player, 5);
            func_8009E55C(player, 2, 0);
        }
        if (baanim_isStopped(player)) {
            if (*(f32 *) ((u8 *) player + 0x16C) != 0.0f) {
                next_state = 0x6F;
            } else {
                next_state = 1;
            }
        }
}

bs_setState(player, next_state);
}

int bstaxi_entrypoint_31(s32 player)
{
    return D_808021E8_bstaxi[player];
}

void bstaxi_entrypoint_32(s32 player)
{
    func_80090A2C();
    bstaxi_entrypoint_0(player);
}
void bstaxi_entrypoint_33(Actor *player)
{
    // Matching: the extra temporaries (anim_id, player_copy) are needed for the match.
    int anim_id;
    s32 player_copy;
    player_copy = player;
    bstaxi_entrypoint_1(player);
    anim_id = 0x124;
    baanim_playForDuration_loopSmooth(player_copy, anim_id, 6.0f);
    func_8009FFD8(player_copy, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(player_copy, 0);
    func_800909CC(player_copy);
}

void bstaxi_entrypoint_34(Actor *player)
{
    s32 next_state = 0;
    func_8009D3A8(player, 0);

if (bastick_getZone(player) > 0) {
    next_state = 0x123;
}

next_state = func_80800064_bstaxi(player, next_state);

if (func_8008E148(player)) {
    next_state = 1;
}

if (func_8008E260(player)) {
    next_state = 0x3D;
}

if (player_inWater(player)) {
    next_state = 0x4C;
}

bs_setState(player, func_800A02DC(player, next_state));
}

int bstaxi_entrypoint_35(s32 player)
{
    return D_808021F8_bstaxi[player];
}

extern void _bstaxi_entrypoint_2();
extern void _bstaxi_entrypoint_3();
extern void _bstaxi_entrypoint_4();
extern int func_80099B94();
extern void _bstaxi_entrypoint_7();
extern void _bstaxi_entrypoint_8();
extern void _bstaxi_entrypoint_9();
extern void _bstaxi_entrypoint_11();
extern void _bstaxi_entrypoint_12();
extern void _bstaxi_entrypoint_13();
extern void _bstaxi_entrypoint_17();
extern void _bstaxi_entrypoint_15();
extern void _bstaxi_entrypoint_16();
extern void _bstaxi_entrypoint_19();
extern void _bstaxi_entrypoint_20();
extern void _bstaxi_entrypoint_21();
extern void _bstaxi_entrypoint_23();
extern void _bstaxi_entrypoint_24();
extern void _bstaxi_entrypoint_25();
extern void _bstaxi_entrypoint_27();
extern void _bstaxi_entrypoint_28();
extern void _bstaxi_entrypoint_30();
extern void _bstaxi_entrypoint_29();
extern void _bstaxi_entrypoint_32();
extern void _bstaxi_entrypoint_33();
extern void _bstaxi_entrypoint_34();
s32 D_808020D0_bstaxi[8] = {0x3060013,  0x41D0015, 0x40,     0x190016,
                            0x5208000C, 0x40,      0xCC0119, 0x110000};
s32 D_808020F0_bstaxi[8] = {0x3060013,  0x41D0015, 0x40,     0x190016,
                            0x5DC0000C, 0x40,      0xCC0133, 0x110000};
s32 D_80802110_bstaxi[8] = {0x3060013,  0x41D0015, 0x40,     0x190016,
                            0x6978000C, 0x40,      0xE60166, 0x110000};
int D_80802130_bstaxi[4] = {(u32) _bstaxi_entrypoint_2, (u32) _bstaxi_entrypoint_3,
                            (u32) _bstaxi_entrypoint_4, (u32) func_80099B94};
u8 D_80802140_bstaxi[72] = {0x0, 0x1D, 0x9, 0xE6, 0x0, 0x1B, 0xFD, 0x44, 0x1,  0x2C, 0x0,  0x2D,
                            0x0, 0x64, 0x0, 0xC8, 0x0, 0xD,  0x0,  0x1E, 0x0,  0x16, 0x10, 0x2,
                            0x0, 0x27, 0x0, 0x0,  0x0, 0x64, 0x0,  0x0,  0x0,  0xC8, 0x0,  0x22,
                            0x0, 0x0,  0x0, 0x0,  0x0, 0x4C, 0x0,  0x99, 0x0,  0x15, 0x0,  0x33,
                            0x0, 0xB3, 0x0, 0x2B, 0x0, 0xC0, 0x1,  0x0,  0x0,  0x4,  0x0,  0x99,
                            0x0, 0x7,  0x0, 0x3,  0x0, 0x31, 0xFF, 0xF6, 0xFF, 0xF6, 0x0,  0x0};
s32 D_80802188_bstaxi[4] = {(u32) func_808005B8_bstaxi, (u32) func_808005F0_bstaxi,
                            (u32) func_808006F4_bstaxi, (u32) func_808004A8_bstaxi};
s32 D_80802198_bstaxi[4] = {(u32) _bstaxi_entrypoint_7, (u32) _bstaxi_entrypoint_8,
                            (u32) _bstaxi_entrypoint_9, (u32) func_80099B94};
s32 D_808021A8_bstaxi[4] = {(u32) _bstaxi_entrypoint_11, (u32) _bstaxi_entrypoint_12,
                            (u32) _bstaxi_entrypoint_13, (u32) func_80099B94};
s32 D_808021B8_bstaxi[4] = {(u32) _bstaxi_entrypoint_17, (u32) _bstaxi_entrypoint_15,
                            (u32) _bstaxi_entrypoint_16, (u32) func_80099B94};
s32 D_808021C8_bstaxi[4] = {(u32) _bstaxi_entrypoint_19, (u32) _bstaxi_entrypoint_20,
                            (u32) _bstaxi_entrypoint_21, (u32) func_80099B94};
s32 D_808021D8_bstaxi[4] = {(u32) _bstaxi_entrypoint_23, (u32) _bstaxi_entrypoint_24,
                            (u32) _bstaxi_entrypoint_25, (u32) func_80099B94};
s32 D_808021E8_bstaxi[4] = {(u32) _bstaxi_entrypoint_27, (u32) _bstaxi_entrypoint_28,
                            (u32) _bstaxi_entrypoint_30, (u32) _bstaxi_entrypoint_29};
s32 D_808021F8_bstaxi[6] = {(u32) _bstaxi_entrypoint_32,
                            (u32) _bstaxi_entrypoint_33,
                            (u32) _bstaxi_entrypoint_34,
                            (u32) func_80099B94,
                            0x0,
                            0x0};
