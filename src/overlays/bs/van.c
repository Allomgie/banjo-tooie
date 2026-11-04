// Player states of the Van transformation in Witchyworld: idle, drive (exhaust particles), jump,
// fall/landing, crash/death, bounce, rest, drone wrappers, and the coin-box state (spits coins in).
// Exports the van form hooks and the landing puff called from core2/1E7BFA0.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009590C(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern s32 D_80801B90_bsvan[];
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void _basudie_entrypoint_2(PlayerState *, f32, f32, f32);
extern void anctrl_setSubrange(void *, f32, f32);
extern void anctrl_setDuration(void *, f32);
extern void func_8009D820(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern f32 func_800F0E00(f32, f32);
extern s32 D_80801C8C_bsvan[];
extern s32 D_80801C9C_bsvan[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern void anctrl_setStart(void *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern s32 anctrl_isStopped(void *);
extern void func_8009D3A8(PlayerState *, s32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 func_8008DF8C(PlayerState *, s32);
extern int player_isStable(PlayerState *);
extern void func_800A2EAC(PlayerState *);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 _badrone_entrypoint_28(PlayerState *);
extern s32 player_inWater(PlayerState *);
extern s32 D_80801CAC_bsvan[];
extern void _bavan_entrypoint_7(PlayerState *, f32);
extern void anctrl_reset(void *);
extern void anctrl_setSmoothTransition(void *, s32);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 func_8009BB5C(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 D_80801CBC_bsvan[];
extern void func_80099B94(void);
extern s32 _bsdrone_entrypoint_3;
extern s32 D_80801CCC_bsvan[];
extern s32 D_80801CDC_bsvan[];
extern s32 D_80801CEC_bsvan[];
extern s32 D_80801CFC_bsvan[];
extern s32 D_80801D70_bsvan[];
extern s32 D_80801D80_bsvan[];
extern s32 func_800B5BE4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800BA77C(s32, s16, s16, s16);
extern s32 D_80801C40_bsvan[];
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void _bavan_entrypoint_5(PlayerState *, f32);
extern void _bavan_entrypoint_6(PlayerState *, f32);
extern void _bavan_entrypoint_4(PlayerState *, f32);
typedef struct {
    s32 handle;
    f32 position[3];
    s32 result;
} VanCoinState;
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern s32 D_80801D0C_bsvan[];
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_80092C90(PlayerState *, f32 *, s32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern void func_800BA994(s32, s32, s16, s32, s32, s32, s32);
extern s32 func_8008E148(PlayerState *);
extern s32 _badrone_entrypoint_25(PlayerState *);
extern s32 func_800A02DC(PlayerState *, s32);
extern void bs_setState(PlayerState *, s32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void _bsvan_entrypoint_15();
extern void _chbaddiesetup_entrypoint_1();
extern void bsvan_entrypoint_3(PlayerState *);

void func_80800000_bsvan(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 900.0f));
    }
}

s32 func_80800064_bsvan(s32 player, s32 next_state)
{
    if (bainput_should_enter_first_person()) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (bakey_pressed(player, 8)) {
        next_state = 0x115;
    }
    return next_state;
}

int func_808000BC_bsvan(Actor *player)
{
    if (bakey_pressed(player, 9)) {
        _bavan_entrypoint_1(player);
    }
}

void bsvan_entrypoint_0(player)
{
    if (!func_8009E74C(player, 0xD)) {
        _bastatemem_entrypoint_1(player);
        func_80092864(player, 1.0f);
        func_800947EC(player, 1, 0);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        func_8009C000(player);
        baroll_resetAngularVelocity(player);
        bastick_popZone(player);
        func_80095A40(player);
        func_8009E474(player);
        baflag_clear(player, 3);
        baflag_clear(player, 4);
        _bavan_entrypoint_2(player);
    }
}

void bsvan_entrypoint_1(player) PlayerState *player;
{
    if (!func_8009E77C(player, 13)) {
        _bastatemem_entrypoint_0(player, 0x14);
        _bavan_entrypoint_3(player);
        *(s32 *) player->kazfly = 0;
        player->unk174 = 1.0f;
        _batimer_set(player, 2, 0.0f);
        func_80092864(player, 2.29998779296875f);
        func_8009BFE4(player, 1000.0f, 12.0f);
        baroll_setAngularVelocity(player, 1000.0f, 12.0f);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 1.0f);
        func_800959C8(player, 110.0f, 65.0f);
        func_8009590C(player, 110.0f);
        func_8009E4AC(player);
        func_8009E55C(player, 0, 70.0f);
        func_8009E55C(player, 1, 78.0f);
        baflag_set(player, 3);
        baflag_set(player, 4);
        func_800947EC(player, 1, 1);
    }
}

// Landing dust puff, called from core2/1E7BFA0.
void bsvan_entrypoint_2(s32 player)
{
    f32 pos[3];
    s32 emitter;

    emitter = func_800B5BE4(8);
    func_8009C128(player, pos);
    func_800BABB8(emitter, pos, 0, 1.0f, &D_80801B90_bsvan);
}

void func_8080032C_bsvan(PlayerState *player)
{
    f32 pos[3];
    s32 emitter;
    func_80092C90(player, pos, 4);
    emitter = func_800B5BE4(8);
    func_800BABB8(emitter, pos, 0, 1.0f, D_80801C40_bsvan);
    func_800BA77C(emitter, 0, 0, (s32) func_800DC178(0.0f, 359.0f));
    func_800BA22C(emitter, 1);
}

void bsvan_entrypoint_3(player) PlayerState *player;
{
    f32 factor;
    f32 speed;

    _bavan_entrypoint_5(player, func_800F1DCC(yaw_getIdeal(player), yaw_get(player)));
    speed = func_8009BB5C(player);
    if (speed > 1.0f) {
        speed = func_800F10B4(speed, 30.0f, 900.0f, 45.0f, 1350.0f);
    } else {
        speed = 0.0f;
    }
    _bavan_entrypoint_6(player, speed);
    speed = func_8009BB5C(player);
    if (speed > 0.0f) {
        factor = func_800F10B4(speed, 30.0f, 900.0f, 0.8f, 1.25f);
    } else {
        factor = 0.8f;
    }
    if (!player_isStable(player)) {
        factor = func_800F13F0(1.9f, factor + 0.3f);
    }
    _bavan_entrypoint_4(player, factor);
    _bavan_entrypoint_8(player);
}

void func_808004F8_bsvan(s32 player)
{
    _basudie_entrypoint_6();
    bsvan_entrypoint_0(player);
}

void func_80800520_bsvan(PlayerState *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    bsvan_entrypoint_1(player);
    player->unk16C = 250.0f;
    _basudie_entrypoint_2(player, 250.0f, 420.0f, -1200.0f);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0xD7);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.3966f);
    anctrl_setDuration(anim_ctrl, 1.7f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009D820(player, 1.8f);
    player->unk15C.word = 0;
}

void func_808005E4_bsvan(PlayerState *player)
{
    _basudie_entrypoint_5(player);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
    switch (player->unk15C.word) {
        case 0:
            if (player_isStable(player)) {
                baanim_setEnd(player, 0.7453f);
                func_8009DF18(player, 0x417, 0.8f, 0x4650);
                func_8009DF18(player, 0x428, 1.8f, 0x4650);
                baphysics_set_vertical_velocity(player, 400.0f);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(player)) {
                baanim_setEnd(player, 1.0f);
                func_8009DF18(player, 0x417, 0.8f, 0x4650);
                func_8009DF18(player, 0x428, 1.8f, 0x4650);
                player->unk15C.word = 2;
            }
            break;
        case 2:
            player->unk15C.word = 3;
            break;
        case 3:
            if (player->unk16C > 0.0f) {
                player->unk16C = func_800F0E00(0.0f, player->unk16C - 10.0f);
            }
    }
    bsvan_entrypoint_3(player);
    bs_setState(player, 0);
}

int bsvan_entrypoint_4(s32 index)
{
    return D_80801C8C_bsvan[index];
}

void func_80800760_bsvan(s32 player)
{
    _bsdrone_entrypoint_2();
    bsvan_entrypoint_0(player);
}

void func_80800788_bsvan(s32 player)
{
    bsvan_entrypoint_1();
    _bsdrone_entrypoint_0(player);
}

void func_808007B0_bsvan(s32 player)
{
    _bsdrone_entrypoint_1();
    bsvan_entrypoint_3(player);
}

int bsvan_entrypoint_5(s32 index)
{
    return D_80801C9C_bsvan[index];
}

s32 func_808007EC_bsvan(Actor *player)
{
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
    bsvan_entrypoint_0(player);
}

void func_80800824_bsvan(PlayerState *player)
{
    void *anim_ctrl;

    bsvan_entrypoint_1(player);
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0xED);
    anctrl_setStart(anim_ctrl, 0.359f);
    anctrl_setDuration(anim_ctrl, 0.7f);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 3, 3, 6);
    yaw_setVelocityBounded(player, 300.0f, 6.5f);
    player->unk15C.word = 0;
}

void func_808008D4_bsvan(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_8009D3A8(player, 0);
    func_80800000_bsvan(player);
    func_8009BB24(player, velocity);
    switch (player->unk15C.word) {
        case 0:
            if (func_8008DF8C(player, 0x82)) {
                baanim_setEnd(player, 0.6939f);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(player)) {
                func_800A2EAC(player);
                baphysics_set_target_horizontal_velocity(player, 0.0f);
                baanim_setEndAndDuration(player, 1.0, 1.0f);
                player->unk15C.word = 2;
            }
        case 2:
            break;
    }
    if (player_isStable(player) && (bastick_getZone(player) > 0 ||
                                     (player->unk15C.word == 2 && anctrl_isStopped(anim_ctrl)))) {
        if (baflag_isTrue(player, 0x19))
            next_state = _badrone_entrypoint_28(player);
        else
            next_state = 0x11A;
    }
    if (player_inWater(player))
        next_state = 0x11D;
    func_808000BC_bsvan(player);
    bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

int bsvan_entrypoint_6(s32 index)
{
    return D_80801CAC_bsvan[index];
}

void func_80800A5C_bsvan(PlayerState *player)
{
    void *anim_ctrl;
    f32 speed;
    f32 yaw;
    bsvan_entrypoint_1(player);
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0xED);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.359f);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setStart(anim_ctrl, 0.15f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 3, 1, 6);
    yaw_setVelocityBounded(player, 300.0f, 6.5f);
    if (bastick_distance(player) != 0.0f)
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800000_bsvan(player);
    yaw = yaw_getIdeal(player);
    speed = baphysics_get_target_horizontal_velocity(player);
    baphysics_set_horizontal_velocity(player, yaw, speed);
    baphysics_set_vertical_velocity(player, 693.5f);
    baphysics_set_gravity(player, -1200.0f);
    func_8009D7A4(player, 1.35f, 1.45f);
    _bavan_entrypoint_7(player, 0);
    player->unk15C.word = 0;
}

void func_80800BDC_bsvan(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    f32 velocity[3];
    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_8080032C_bsvan(player);
    func_80800000_bsvan(player);
    func_8009BB24(player, velocity);
    if (bakey_released(player, 8) && velocity[1] > 0.0f)
        baphysics_reset_gravity(player);
    switch (player->unk15C.word) {
        case 0:
            if (func_8008DF8C(player, 0x82)) {
                baanim_setEndAndDuration(player, 1.0, 0.7f);
                player->unk15C.word = 2;
            } else if (anctrl_isStopped(anim_ctrl)) {
                baanim_setEndAndDuration(player, 0.69f, 3.0f);
                player->unk15C.word = 1;
            }
            break;
        case 1:
            if (func_8008DF8C(player, 0x82)) {
                baanim_setEndAndDuration(player, 1.0, 1.0f);
                player->unk15C.word = 2;
            }
            break;
        case 2:
            func_8009D3A8(player, 0);
            if (player_isStable(player)) {
                func_800A2EAC(player);
                baanim_setEndAndDuration(player, 1.0, 1.0f);
                player->unk15C.word = 3;
            }
            break;
        case 3:
            func_8009D2D8(player, 3);
            func_8009D3A8(player, 0);
            if (func_8009BB5C(player) > 0.0f)
                next_state = 0x116;
            else if (anctrl_isStopped(anim_ctrl))
                next_state = 0x11A;
            if (bakey_pressed(player, 8))
                next_state = 0x115;
    }
    if (baphysics_get_vertical_velocity(player) < 0.0f && player_inWater(player))
        next_state = 0x11D;
    func_808000BC_bsvan(player);
    bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

void func_80800E0C_bsvan(Actor *player)
{
    baphysics_reset_gravity();
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
    bsvan_entrypoint_0(player);
}

int bsvan_entrypoint_7(s32 index)
{
    return D_80801CBC_bsvan[index];
}

void func_80800E60_bsvan(player, idle_handler) PlayerState *player;
void (*idle_handler)(PlayerState *);
{
    switch (func_8009E6EC(player)) {
        case 0x46:
            ((VanCoinState *) player->kazfly)->handle = func_80099A4C(player);
            ((VanCoinState *) player->kazfly)->result =
                _chfaircoinbox_entrypoint_0(((VanCoinState *) player->kazfly)->handle,
                                            ((VanCoinState *) player->kazfly)->position);
            func_8009E830(player, 2);
            bs_setState(player, 0x121);
            break;
        default:
            idle_handler(player);
            break;
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x2E:
        case 0x4E:
        case 0x51:
        case 0x52:
            break;
    }
}

void bsvan_entrypoint_8(s32 player)
{
    func_80800E60_bsvan(player, func_80099B94);
}

void bsvan_entrypoint_9(s32 player)
{
    func_80800E60_bsvan(player, &_bsdrone_entrypoint_3);
}

void func_80800F50_bsvan()
{
    bsvan_entrypoint_0();
}

void func_80800F70_bsvan(PlayerState *player)
{
    bsvan_entrypoint_1(player);
    baanim_playForDuration_loopSmooth(player, 0xEC, 1.0f);
    func_8009FFD8(player, 2, 3, 1, 0xE);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 900.0f, 1.0f, 0.4f);
    func_8008CA30(player, 1.0f);
    yaw_setVelocityBounded(player, 300.0f, 6.5f);
    func_8009BFE4(player, 1000.0f, 12.0f);
    baroll_setAngularVelocity(player, 1000.0f, 12.0f);
}

void func_80801034_bsvan(s32 player)
{
    s32 next_state;
    next_state = 0;
    func_8009D3A8(player, 0);
    func_80800000_bsvan(player);
    func_8080032C_bsvan(player);
    if (bastick_getZone(player) == 0) {
        next_state = 0x11A;
    }
    if (func_8008E148(player) != 0) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (func_8008DD04(player) != 0) {
        next_state = 0x114;
    }
    func_808000BC_bsvan(player);
    if (bakey_pressed(player, 8) != 0) {
        next_state = 0x115;
    }
    if (player_inWater(player) != 0) {
        next_state = 0x11B;
    }
    bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

int bsvan_entrypoint_10(s32 index)
{
    return D_80801CCC_bsvan[index];
}

void func_80801118_bsvan(s32 player)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(player);
}

// Matching: the extra temporary is needed for the match.
int func_80801140_bsvan(Actor *player)
{
    int unk_0;
    bsvan_entrypoint_1(player);
    _babounce_entrypoint_4(player, 1);
    _babounce_entrypoint_5(player, 0xef, unk_0 = 0x3F0346DC);
    unk_0 = 0x3DD21FF3;
    func_8008B10C(baanim_getAnimCtrlPtr(player), unk_0);
}

void func_80801198_bsvan(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (baanim_isAt(player, 0.5f) != 0) {
        func_800951B4(player);
    }
    if (_babounce_entrypoint_2(player) != 0) {
        func_80800000_bsvan(player);
    }
    if (_babounce_entrypoint_9(player) != 0) {
        next_state = 0x11A;
    }
    bs_setState(player, next_state);
}

int bsvan_entrypoint_11(s32 index)
{
    return D_80801CDC_bsvan[index];
}

void func_80801224_bsvan(s32 player)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(player);
}

// Matching: the extra temporary is needed for the match.
int func_8080124C_bsvan(Actor *player)
{
    int unk_0;
    bsvan_entrypoint_1(player);
    {
        unk_0 = 2;
        _babounce_entrypoint_4(player, unk_0);
        unk_0 = 0x3F0346DC;
        _babounce_entrypoint_5(player, 0xef, unk_0);
        func_8008B10C(baanim_getAnimCtrlPtr(player), 0x3DD21FF3);
    }
}

s32 func_808012A4_bsvan(s32 player)
{
    s32 next_state = 0;

    if (_babounce_entrypoint_2(player)) {
        func_80800000_bsvan(player);
    }

    if (_babounce_entrypoint_9(player)) {
        next_state = 0x11A;
    }

    bs_setState(player, next_state);
}

int bsvan_entrypoint_12(s32 index)
{
    return D_80801CEC_bsvan[index];
}

void func_8080130C_bsvan(s32 player)
{
    _bsrest_entrypoint_14();
    bsvan_entrypoint_0(player);
}

void func_80801334_bsvan(s32 player)
{
    bsvan_entrypoint_1();
    _bsrest_entrypoint_16(player);
}

s32 func_8080135C_bsvan(Actor *player)
{
    s32 next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = _bsrest_entrypoint_13(player);
    }
    bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

int bsvan_entrypoint_13(s32 index)
{
    return D_80801CFC_bsvan[index];
}

void func_808013BC_bsvan(s32 player)
{
    bsvan_entrypoint_0();
    func_80090A2C(player);
}

// Matching: the extra temporary is needed for the match.
int func_808013E4_bsvan(Actor *player)
{
    int unk_0;
    extern void func_800909CC(Actor * a0);
    bsvan_entrypoint_1(player);
    baanim_playForDuration_loopSmooth(player, 0xee, 1.0f);
    unk_0 = 1;
    func_8009FFD8(player, unk_0, 3, 1, 2);
    yaw_setVelocityBounded(player, 300.0f, 6.5f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800909CC(player);
}

void func_8080145C_bsvan(PlayerState *this)
{
    s32 next;
    f32 rot[2];
    f32 pos[3];
    f32 dir[3];
    f32 target[3];
    s32 handle;

    next = 0;
    func_8009D3A8(this, 0);
    if (baanim_isAt(this, 0.0122f) || baanim_isAt(this, 0.5122f)) {
        handle = func_800B5BE4(8);
        func_8009C128(this, pos);
        func_80092C90(this, target, 4);
        func_800EFB24(dir, target, pos);
        func_800F1A88(dir, rot);
        rot[0] = -rot[0] - 10;
        func_800BA994(handle, (s16) rot[0], rot[1] - 10.0f, 150, (s16) rot[0],
                      (s32) (rot[1] + 10.0f), 200);
        func_800BA77C(handle, 0, 0, func_800DC178(0.0f, 359.0f));
        func_800BABB8(handle, target, 0, 1.0f, &D_80801D0C_bsvan);
    }
    func_808000BC_bsvan(this);
    if (bastick_getZone(this) > 0) {
        next = 0x116;
    }
    if (func_8008E148(this)) {
        next = _badrone_entrypoint_25(this);
    }
    if (player_inWater(this)) {
        next = 0x11D;
    }
    next = func_800A02DC(this, func_80800064_bsvan(this, next));
    bsvan_entrypoint_3(this);
    bs_setState(this, next);
}

int bsvan_entrypoint_14(s32 index)
{
    return D_80801D70_bsvan[index];
}

// Coin-box state: switch to the given phase and run its entry action.
void func_8080164C_bsvan(player, phase) PlayerState *player;
s32 phase;
{
    f32 pos[3];
    func_8009C128(player, pos);
    switch (phase) {
        case 1:
            yaw_setIdeal(player,
                         func_800F1DF4(pos, (f32 *) ((u8 *) player->kazfly + 4)) + 180.0f);
            break;
        case 2:
            baanim_playForDuration_onceSmooth(player, 0xF1, 1.2f);
            break;
        case 3:
            if (player->unk15C.word == 2)
                _batimer_set(player, 3, 0.001f);
            else
                _batimer_set(player, 3, 0.5f);
            break;
        case 4:
            baanim_playForDuration_onceSmooth(player, 0xF2, 1.3f);
            break;
        case 5:
            yaw_setIdeal(player, func_800F1DF4(pos, (f32 *) ((u8 *) player->kazfly + 4)));
    }
    player->unk15C.word = phase;
}

// Matching: the duplicate load into unk_0 is needed for the match.
void func_80801770_bsvan(u8 *player)
{
    s32 *box_handle;
    s32 *unk_0;
    s32 *state;
    state = *(s32 **) (player + 0x188);
    unk_0 = *(s32 **) (player + 0x188);
    box_handle = *state;
    _chfaircoinbox_entrypoint_1(box_handle);
    bsvan_entrypoint_0(player);
}

void func_808017A0_bsvan(Actor *player)
{
    bsvan_entrypoint_1(player);
    baanim_playForDuration_loopSmooth(player, 0xEE, 1.0f);
    func_8009FFD8(player, 1, 3, 3, 2);
    yaw_setVelocityBounded(player, 3e+02f, 6.5f);
    *(s32 *) ((char *) player + 0x15C) = 0;
    func_8080164C_bsvan(player, 1);
}

// Spawns one coin above the van, aimed at the coin box.
void bsvan_entrypoint_15()
{
    s32 *player;
    f32 pos[3];
    f32 target[3];

    player = func_800F53D0();
    func_8009C128(player, pos);
    func_800EE7F8(target, *(s32 *) ((char *) player + 0x188) + 4);
    pos[1] += 20.0f;
    target[1] += 40.0f;
    _chfaircoin_entrypoint_0(pos, target, 0x3F000000);
}

void func_80801890_bsvan(PlayerState *player)
{
    s32 next_state;
    f32 yaw;
    next_state = 0;
    func_8009D3A8(player, 0);
    switch (player->unk15C.word) {
        case 1:
            yaw = yaw_get(player);
            if (yaw_getIdeal(player) == yaw)
                func_8080164C_bsvan(player, 2);
            break;
        case 2:
            if (baanim_isAt(player, 0.08f))
                func_8009DF18(player, 0x56D, 1.0f, 0x55F0);
            if (baanim_isAt(player, 0.5049f))
                func_8080164C_bsvan(player, 3);
            break;
        case 3:
            if (_batimer_decrement(player, 3)) {
                _chbaddiesetup_entrypoint_1(&_bsvan_entrypoint_15, player->unk184);
                (*(s32 *) ((u8 *) player->kazfly + 0x10))--;
                if (*(s32 *) ((u8 *) player->kazfly + 0x10))
                    func_8080164C_bsvan(player, 3);
                else
                    func_8080164C_bsvan(player, 4);
            }
            break;
        case 4:
            if (baanim_isStopped(player))
                func_8080164C_bsvan(player, 5);
            break;
        case 5:
            yaw = yaw_get(player);
            if (yaw_getIdeal(player) == yaw) {
                if (func_8008E124(player))
                    next_state = 0x119;
                else
                    next_state = 0x11A;
            }
    }
    bsvan_entrypoint_3(player);
    bs_setState(player, next_state);
}

int bsvan_entrypoint_16(s32 index)
{
    return D_80801D80_bsvan[index];
}

extern void _basudie_entrypoint_11();
extern void _bsvan_entrypoint_9();
extern void _bsvan_entrypoint_8();
extern void func_80099AA8();
s32 D_80801B90_bsvan[44] = {
    0x1D09DC,  0x2CFFD8,  0x32FFD8, 0x280064,  0x280015,  0x140066,  0x20F0F0,  -0xFAFFFDE,
    0x1800199, 0x2800300, 0x161000, 0x180000,  0x30000,   0x2B,      0x1800199, 0x210000,
    0x0,       0xAFFB0,   0x3C0000, -0x4FFFC4, 0x11A,     0x2B0199,  0x1B30021, 0x0,
    0x5A000A,  0x50003C,  0x50,     0x3C0000,  0x11A002B, 0x1B301CC, 0x210000,  0xB4,
    0xA0000,   0x3CFFB0,  0x3C,     -0x4FFEE6, 0x2B01CC,  0x1E60021, 0x0,       0x10E000A,
    0x3C,      0x500000,  0x3C0050, 0x11A0000};
s32 D_80801C40_bsvan[19] = {0x1D09DC,   0xA0000,   0x0,       0x0,       0x2C,
                            -0x13FF06,  -0x13FFEC, 0x15E0014, 0x150014,  0x660020,
                            -0xF0F0FB0, 0x220033,  0x6600CC,  0x1330016, 0x10000018,
                            0x6,        0x0,       0x2B0099,  0xB30000};
s32 D_80801C8C_bsvan[4] = {(u32) func_808004F8_bsvan, (u32) func_80800520_bsvan,
                           (u32) func_808005E4_bsvan, (u32) _basudie_entrypoint_11};
s32 D_80801C9C_bsvan[4] = {(u32) func_80800760_bsvan, (u32) func_80800788_bsvan,
                           (u32) func_808007B0_bsvan, (u32) _bsvan_entrypoint_9};
s32 D_80801CAC_bsvan[4] = {(u32) func_808007EC_bsvan, (u32) func_80800824_bsvan,
                           (u32) func_808008D4_bsvan, (u32) _bsvan_entrypoint_8};
s32 D_80801CBC_bsvan[4] = {(u32) func_80800E0C_bsvan, (u32) func_80800A5C_bsvan,
                           (u32) func_80800BDC_bsvan, (u32) _bsvan_entrypoint_8};
s32 D_80801CCC_bsvan[4] = {(u32) func_80800F50_bsvan, (u32) func_80800F70_bsvan,
                           (u32) func_80801034_bsvan, (u32) _bsvan_entrypoint_8};
s32 D_80801CDC_bsvan[4] = {(u32) func_80801118_bsvan, (u32) func_80801140_bsvan,
                           (u32) func_80801198_bsvan, (u32) func_80099AA8};
s32 D_80801CEC_bsvan[4] = {(u32) func_80801224_bsvan, (u32) func_8080124C_bsvan,
                           (u32) func_808012A4_bsvan, (u32) func_80099AA8};
s32 D_80801CFC_bsvan[4] = {(u32) func_8080130C_bsvan, (u32) func_80801334_bsvan,
                           (u32) func_8080135C_bsvan, (u32) _bsvan_entrypoint_8};
s32 D_80801D0C_bsvan[25] = {0x1D09DC,    0x150014, 0x660016,  0x1000000A, 0x0,
                            0x0,         0x0,      0x220019,  0x3300B3,   0xCC0020,
                            -0x373700B0, 0x180000, 0x20000,   0x2B,       0xCC00E6,
                            0x11A0022,   0x33004C, 0x133014C, 0x20F0F0,   -0xFAFFFE8,
                            0x30006,     0x0,      0x2B0119,  0x133011A,  0x0};
s32 D_80801D70_bsvan[4] = {(u32) func_808013BC_bsvan, (u32) func_808013E4_bsvan,
                           (u32) func_8080145C_bsvan, (u32) _bsvan_entrypoint_8};
s32 D_80801D80_bsvan[4] = {(u32) func_80801770_bsvan, (u32) func_808017A0_bsvan,
                           (u32) func_80801890_bsvan, (u32) _bsvan_entrypoint_8};
