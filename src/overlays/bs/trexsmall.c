// Player states of the small (baby) T-Rex in Terrydactyland: idle, walk, run, jump, fall, landing,
// roar (needs the Roar ability; short or long by B hold), death, bounce, rest, drone wrappers.
// Also the roar-range test that the core attack classifier uses.
#include "bs/trexsmall.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void _badust_entrypoint_5(s32, f32, f32);

extern s32 func_800C2FDC(u8);
extern u8 D_80801AF0_bstrexsmall[];
typedef struct {
    u8 pad_0[0x15E];
    u8 roar_state;
    u8 pad_15F;
    u8 sfx_id;
} TrexSmallState;
extern s32 bastick_getZone();
extern f32 bastick_getZonePosition(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_8009D3A8(PlayerState *, s32);
extern int baanim_isStopped(PlayerState *);
extern int D_80801B08_bstrexsmall[];
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_80092864(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009590C(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void _basudie_entrypoint_3(PlayerState *, f32, f32, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void func_8009D820(PlayerState *, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern f32 func_800F0E00(f32, f32);
extern int D_80801B18_bstrexsmall[];
extern s32 D_80801B28_bstrexsmall[];
extern s32 D_80801B38_bstrexsmall[];
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 func_800DC0C0(void);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8009DBB0(PlayerState *, s32, f32, f32, s32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 D_80801B48_bstrexsmall[];
extern s32 D_80801B58_bstrexsmall[];
extern int D_80801B68_bstrexsmall[];
extern s32 D_80801B78_bstrexsmall[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern int bs_setState(PlayerState *, s32);
extern int baanim_isAt(PlayerState *, int);
extern int D_80801B88_bstrexsmall[];
extern int D_80801B98_bstrexsmall[];
extern s32 D_80801BA8_bstrexsmall[];
extern s32 D_80801BB8_bstrexsmall[];
extern void func_800C3058();
extern s32 func_800C3920(u8, s32, void *);
extern f32 func_800D8FF8(void);
extern s32 func_800F0E28(s32, s32);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_8008DAE8(PlayerState *, f32 *, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
void bstrexsmall_entrypoint_2();
void bstrexsmall_entrypoint_3();

// B pressed and T-Rex Roar ability unlocked.
int func_80800000_bstrexsmall(u8 *player)
{
    return bakey_pressed(player, 9) && func_800C6E38(0x20);
}

int func_8080003C_bstrexsmall(PlayerState *arg0)
{
    return bakey_pressed(arg0, BUTTON_A);
}

void func_8080005C_bstrexsmall()
{
    func_80099B94();
}

int func_8080007C_bstrexsmall(Actor *actor)
{
    switch (func_8009E6EC()) {
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x25:
            break;

        default:
            func_80099B94(actor);
    }
}

void func_808000C8_bstrexsmall(PlayerState *player, s32 mode)
{
    TrexSmallState *ts = (TrexSmallState *) player;
    if (ts->roar_state == 0)
        ts->sfx_id = 0;
    ts->roar_state = mode;
    switch (mode) {
        case 0:
        case 1:
            if (ts->sfx_id) {
                func_800C2FDC(ts->sfx_id);
                ts->sfx_id = 0;
            }
            break;
        case 2:
            ts->sfx_id = func_8009D454(player, 0, D_80801AF0_bstrexsmall);
    }
}

s32 func_80800154_bstrexsmall(Actor *player, s32 state)
{
    s32 next_state;
    s32 zone;

    zone = bastick_getZone();
    switch (zone) {
        case 0:
            next_state = 0x145;
            break;
        case 1:
            next_state = 0x146;
            break;
        case 2:
            next_state = 0x144;
    }
    if (bs_getCurrentState(player) != next_state) {
        state = next_state;
    }
    if (func_80800000_bstrexsmall(player) != 0) {
        state = 0x143;
    }
    if (func_8008DD04(player) != 0) {
        state = 0x13E;
    }
    if (func_8080003C_bstrexsmall(player) != 0) {
        state = 0x13F;
    }
    return state;
}

int func_8080020C_bstrexsmall(PlayerState *player, s32 state)
{
    switch (bastick_getZone(player)) {
        case 0:
            break;
        case 1:
            state = 0x146;
            break;
        case 2:
            state = 0x144;
            break;
    }
    if (bainput_should_enter_first_person(player)) {
        state = _badrone_entrypoint_24(player);
    }
    if (func_80800000_bstrexsmall(player)) {
        state = 0x143;
    }
    if (func_8008DD04(player)) {
        state = 0x13E;
    }
    if (func_8080003C_bstrexsmall(player)) {
        state = 0x13F;
    }
    return state;
}

void func_808002B8_bstrexsmall(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    switch (bastick_getZone(player)) {
        case 0:
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            break;
        case 1:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(stick_pos, 100.0f, 300.0f));
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(stick_pos, 300.0f, 600.0f));
    }
}

void bstrexsmall_entrypoint_1();

void func_80800364_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_80800384_bstrexsmall(Actor *this)
{
    bstrexsmall_entrypoint_2();
    func_8009FFD8(this, 1, 3, 3, 2);
    yaw_setVelocityBounded(this, 5e+02f, 6.5f);
}

void func_808003D0_bstrexsmall(PlayerState *player)
{
    s32 next_state = 0;

    func_8009D3A8(player, 0);
    bstrexsmall_entrypoint_3(player);
    if (baanim_isStopped(player)) {
        next_state = 0x145;
    }
    bs_setState(player, func_8080020C_bstrexsmall(player, next_state));
}

int bstrexsmall_entrypoint_0(int index)
{
    return D_80801B08_bstrexsmall[index];
}

void bstrexsmall_entrypoint_1(player) s32 player;
{
    if (func_8009E74C(player, 0x10) == 0) {
        func_808000C8_bstrexsmall(player, 0);
        bastick_popZone(player);
        func_80092864(player, 1.0f);
        func_8009E474(player);
        func_80095A40(player);
        func_8009590C(player, 0);
        baphysics_reset_gravity(player);
        func_800947EC(player, 1, 0);
    }
}

void bstrexsmall_entrypoint_2(player) PlayerState *player;
{
    if (!func_8009E77C(player, 0x10)) {
        *((u8 *) player + 0x15E) = 0;
        func_808000C8_bstrexsmall(player, 1);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 0.6f);
        bastick_setZoneMax(player, 2, 1.0f);
        func_80092864(player, 1.5f);
        func_8009E4AC(player);
        func_8009E55C(player, 0, 70.0f);
        func_8009E53C(player, 0, 0.0f);
        func_8009E55C(player, 1, 80.0f);
        func_8009E53C(player, 1, 0.0f);
        func_800959C8(player, 100.0f, 56.0f);
        func_8009590C(player, 125.0f);
        baphysics_set_gravity(player, -3000.0f);
        func_800947EC(player, 1, 1);
    }
}

void bstrexsmall_entrypoint_3(player) u8 *player;
{
    // Matching: padding local, needed for the match.
    s32 pad[2];
    s32 unk_0;
    s32 unk_1;
    s32 sfx_id;

    sfx_id = player[0x160];
    if (sfx_id != 0 && player[0x15E] == 3) {
        unk_0 = func_800C3920(sfx_id, sfx_id, player);
        unk_1 = func_800F0E28(0, (f32) unk_0 - func_800D8FF8() * 60000.0f);
        if (unk_1 != 0) {
            func_800C3058(player[0x160], unk_1);
        } else {
            func_808000C8_bstrexsmall(player, 1);
        }
    }
}

void func_80800680_bstrexsmall(s32 player)
{
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        _badust_entrypoint_5(player, angle, 2.3e+02f);
    }
}

void func_8080070C_bstrexsmall(s32 player)
{
    _basudie_entrypoint_6();
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
}

void func_80800744_bstrexsmall(PlayerState *player)
{
    AnimCtrl *anim;

    anim = baanim_getAnimCtrlPtr(player);
    player->unk16C = 250.0f;
    anctrl_reset(anim);
    anctrl_setSmoothTransition(anim, 0);
    anctrl_setIndex(anim, 0x148);
    anctrl_setSubrange(anim, 0.0f, 0.12f);
    anctrl_setDuration(anim, 4.5f);
    anctrl_setPlaybackType(anim, 1);
    anctrl_start(anim);
    _basudie_entrypoint_3(player, player->unk16C, 800.0f, -2400.0f, 10.0f);
    func_8009BFE4(player, 1000.0f, 12.0f);
    func_8009D820(player, 1.4f);
    player->unk15C.bytes[0] = 0;
}

void func_80800818_bstrexsmall(PlayerState *player)
{
    AnimCtrl *anim;

    anim = baanim_getAnimCtrlPtr(player);
    _basudie_entrypoint_5(player);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
    switch (player->unk15C.bytes[0]) {
        case 3:
            break;
        case 0:
            if (func_8008DF8C(player, 0x5A))
                player->unk15C.bytes[0] = 1;
            break;
        case 1:
            if (player_isStable(player)) {
                func_8009DF18(player, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(player, 1.0f, 1.0f, 0.4f);
                func_80800680_bstrexsmall(player);
                func_8009E058(player);
                baanim_setEndAndDuration(player, 0.6f, 2.5f);
                player->unk15C.bytes[0] = 2;
            }
            break;
        case 2:
            player->unk16C = func_800F0E00(player->unk16C - 7.0f, 0.0f);
            if (player->unk16C > 140.0f)
                _badust_entrypoint_9(player);
            if (anctrl_isStopped(anim)) {
                baanim_setEnd(player, 1.0f);
                player->unk15C.bytes[0] = 3;
                player->unk16C = 0.0f;
            }
    }
    bs_setState(player, 0);
}

int bstrexsmall_entrypoint_4(int index)
{
    return D_80801B18_bstrexsmall[index];
}

void func_80800998_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_1();
    _bsdrone_entrypoint_2(arg0);
}

void func_808009C0_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_2();
    _bsdrone_entrypoint_0(arg0);
}

void func_808009E8_bstrexsmall(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstrexsmall_entrypoint_3(arg0);
}

int bstrexsmall_entrypoint_5(s32 index)
{
    return D_80801B28_bstrexsmall[index];
}

void func_80800A24_bstrexsmall(PlayerState *player, s32 substate)
{
    AnimCtrl *anim;

    anim = baanim_getAnimCtrlPtr(player);
    switch (substate) {
        case 1:
            anctrl_reset(anim);
            anctrl_setIndex(anim, 0x1D1);
            anctrl_setDuration(anim, 4.0f);
            anctrl_setSubrange(anim, 0.0f, 0.715f);
            anctrl_setPlaybackType(anim, 1);
            anctrl_setStart(anim, 0.45f);
            anctrl_start(anim);
            break;
        case 2:
            baanim_setEndAndDuration(player, 1.0f, 0.8f);
    }
    player->unk15C.bytes[0] = substate;
}

void func_80800AF0_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_80800B10_bstrexsmall(Actor *actor)
{
    bstrexsmall_entrypoint_2();
    ((char *) actor)[0x15C] = 0;
    func_80800A24_bstrexsmall(actor, 1);
}

void func_80800B40_bstrexsmall(PlayerState *player)
{
    int next_state;

    next_state = 0;
    bstrexsmall_entrypoint_3(player);
    func_808002B8_bstrexsmall(player);
    switch (player->unk15C.bytes[0]) {
        case 1:
            if (func_8008DF8C(player, 0x82)) {
                func_80800A24_bstrexsmall(player, 2);
            }
            break;
        case 2:
            func_8009D3A8(player, 0);
            if (player_isStable(player)) {
                func_800A2E18(player);
                baphysics_set_target_horizontal_velocity(player, 0.0f);
                next_state = 0x13B;
            }
    }
    bs_setState(player, next_state);
}

int bstrexsmall_entrypoint_6(s32 index)
{
    return D_80801B38_bstrexsmall[index];
}

// Roar range test used by the core attack classifier.
s32 bstrexsmall_entrypoint_7(PlayerState *player, f32 *target_pos)
{
    f32 dist_sq;
    f32 pos[3];

    func_8009C128(player, pos);
    dist_sq = func_800EFC7C(pos, target_pos);
    if (dist_sq < 40000.0f) {
        return 1;
    }
    if (dist_sq > 250000.0f) {
        return 0;
    }
    if (!func_8008DAE8(player, target_pos, 90.0f)) {
        return 0;
    }
    return 1;
}

void func_80800CA4_bstrexsmall(PlayerState *player, s32 substate)
{
    AnimCtrl *anim;
    s32 pad;
    f32 velocity;
    f32 yaw;

    anim = baanim_getAnimCtrlPtr(player);
    player->unk15C.bytes[0] = substate;
    switch (substate) {
        case 1:
            anctrl_reset(anim);
            anctrl_setIndex(anim, 0x1D1);
            anctrl_setDuration(anim, 2.2f);
            anctrl_setSubrange(anim, 0.0f, 0.715f);
            anctrl_setPlaybackType(anim, 1);
            anctrl_setStart(anim, 0.194f);
            anctrl_start(anim);
            func_8009FFD8(player, 1, 1, 3, 6);
            if (bastick_distance(player) != 0.0f) {
                yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
            }
            baphysics_set_target_yaw(player, yaw_getIdeal(player));
            yaw = yaw_getIdeal(player);
            velocity = baphysics_get_target_horizontal_velocity(player);
            baphysics_set_horizontal_velocity(player, yaw, velocity);
            baphysics_set_vertical_velocity(player, 1100.0f);
            baphysics_set_gravity(player, -1800.0f);
            if (func_800DC0C0() > 0.5f) {
                func_8009DBB0(player, 0x4D8, 1.3f, 1.35f, 22000);
            } else {
                func_8009DBB0(player, 0x4D9, 1.3f, 1.35f, 22000);
            }
            break;
        case 2:
            baanim_setEndAndDuration(player, 1.0f, 0.8f);
            break;
        case 0:
            baphysics_set_gravity(player, -3000.0f);
    }
}

void func_80800E94_bstrexsmall(s32 arg0)
{
    func_80800CA4_bstrexsmall(arg0, 0);
    bstrexsmall_entrypoint_1(arg0);
}

void func_80800EC0_bstrexsmall(Actor *actor)
{
    bstrexsmall_entrypoint_2();
    ((char *) actor)[0x15C] = 0;
    func_80800CA4_bstrexsmall(actor, 1);
}

void func_80800EF0_bstrexsmall(PlayerState *player)
{
    s32 next_state = 0;
    f32 velocity[3];

    bstrexsmall_entrypoint_3(player);
    func_8009BB24(player, velocity);
    if (bakey_released(player, 8) && velocity[1] > 0.0f) {
        baphysics_reset_gravity(player);
    }
    switch (*((u8 *) player + 0x15C)) {
        case 1:
            func_808002B8_bstrexsmall(player);
            if (func_8008DF8C(player, 0x82)) {
                func_80800CA4_bstrexsmall(player, 2);
            }
            break;
        case 2:
            func_8009D3A8(player, 0);
            func_808002B8_bstrexsmall(player);
            if (player_isStable(player)) {
                func_800A2E18(player);
                baphysics_set_target_horizontal_velocity(player, 0.0f);
                next_state = 0x13B;
            }
    }
    bs_setState(player, next_state);
}

int bstrexsmall_entrypoint_8(s32 index)
{
    return D_80801B48_bstrexsmall[index];
}

void func_80801004_bstrexsmall(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexsmall_entrypoint_1(arg0);
}

int func_8080102C_bstrexsmall(Actor *actor)
{
    bstrexsmall_entrypoint_2(actor);
    _babounce_entrypoint_4(actor, 1);
    _babounce_entrypoint_5(actor, 0x147, 0x3F30A3D7);
}

int func_8080106C_bstrexsmall(Actor *actor)
{
    s32 next_state;
    next_state = 0;
    bstrexsmall_entrypoint_3(actor);
    if (baanim_isAt(actor, 0x3F000000) != 0) {
        func_800951B4(actor);
    }
    if (_babounce_entrypoint_9(actor) != 0) {
        next_state = 0x145;
    }
    return bs_setState(actor, next_state);
}

int bstrexsmall_entrypoint_9(s32 index)
{
    return D_80801B58_bstrexsmall[index];
}

void func_808010E8_bstrexsmall(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexsmall_entrypoint_1(arg0);
}

int func_80801110_bstrexsmall(Actor *actor)
{
    Actor *unk_0;
    unk_0 = actor;
    bstrexsmall_entrypoint_2(unk_0);
    _babounce_entrypoint_4(actor, 2);
    _babounce_entrypoint_5(actor, 0x147, 0x3F30A3D7);
}

s32 func_80801150_bstrexsmall(s32 player)
{
    s32 next_state = 0;

    bstrexsmall_entrypoint_3(player);
    if (_babounce_entrypoint_9(player)) {
        next_state = 0x145;
    }
    bs_setState(player, next_state);
}

int bstrexsmall_entrypoint_10(int index)
{
    return D_80801B68_bstrexsmall[index];
}

void func_808011A8_bstrexsmall(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstrexsmall_entrypoint_1(arg0);
}

void func_808011D0_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_2();
    _bsrest_entrypoint_16(arg0);
}

int func_808011F8_bstrexsmall(Actor *actor)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = _bsrest_entrypoint_13(actor);
    }
    bstrexsmall_entrypoint_3(actor);
    bs_setState(actor, next_state);
}

int bstrexsmall_entrypoint_11(int index)
{
    return D_80801B78_bstrexsmall[index];
}

int func_80801258_bstrexsmall(actor, message)
Actor *actor;
s32 message;
{
    f32 pos[3];
    func_8009C128(actor, pos);
    func_801013A8(pos, message, *(s32 *) ((char *) actor + 0x184));
}

int func_80801294_bstrexsmall(PlayerState *player, s32 substate)
{
    switch (((u8 *) player)[0x15C]) {
        case 2:
            func_80801258_bstrexsmall(player, 0x1D, substate);
            break;
        case 3:
            func_80801258_bstrexsmall(player, 0x1E, substate);
    }
    ((u8 *) player)[0x15C] = substate;
    switch (substate) {
        case 0:
            func_808000C8_bstrexsmall(player, 3);
            break;
        case 1:
            bstrexsmall_entrypoint_2(player);
            baanim_playForDuration_onceSmooth(player, 0x1D0, 3.1f);
            func_8009FFD8(player, 1, 3, 8, 2);
            yaw_setVelocityBounded(player, 55.0f, 0.8f);
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            ((u8 *) player)[0x15D] = 1;
            break;
        case 2:
            anctrl_setSubrange(baanim_getAnimCtrlPtr(player), 0.0f, 0.29f);
            break;
        case 3:
            anctrl_setSubrange(baanim_getAnimCtrlPtr(player), 0.0f, 0.49f);
    }
}

s32 func_808013E8_bstrexsmall(s32 player)
{
    bstrexsmall_entrypoint_1();
    func_80801294_bstrexsmall(player, 0);
}

s32 func_80801414_bstrexsmall(s32 player)
{
    s32 result;
    *(u8 *) ((char *) player + 0x15C) = 0;

    result = func_80801294_bstrexsmall(player, 1);
}

void func_80801438_bstrexsmall(PlayerState *player)
{
    s32 next_state;
    u8 substate;

    next_state = 0;
    bstrexsmall_entrypoint_3(player);
    if ((func_800DB9B0() != 0) && (func_8009D2E4(player) == 8)) {
        func_8009D2D8(player, 2);
    }
    substate = *(u8 *) ((s8 *) player + 0x15C);
    switch (substate) {
        case 1:
            if (baanim_isAt(player, 0x3E051EB8) != 0) {
                func_808000C8_bstrexsmall(player, 2);
            }
            if (bakey_newlyReleased(player, 9) != 0) {
                *(u8 *) ((s8 *) player + 0x15D) = 0U;
            }
            if (baanim_isAt(player, 0x3E4CCCCD) != 0) {
                if (*(u8 *) ((s8 *) player + 0x15D) != 0) {
                    func_80801294_bstrexsmall(player, 3);
                } else {
                    func_80801294_bstrexsmall(player, 2);
                }
            }
            break;
        case 2:
            if (baanim_isAt(player, 0x3E800000) != 0) {
                func_808000C8_bstrexsmall(player, 3);
            }
            if (baanim_isStopped(player) != 0) {
                next_state = 0x145;
            }
            break;
        case 3:
            if (baanim_isAt(player, 0x3EE66666) != 0) {
                func_808000C8_bstrexsmall(player, 3);
            }
            if (baanim_isStopped(player) != 0) {
                next_state = 0x145;
            }
    }
    bs_setState(player, next_state);
}

int bstrexsmall_entrypoint_12(int index)
{
    return D_80801B88_bstrexsmall[index];
}

void func_808015BC_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_808015DC_bstrexsmall(PlayerState *player)
{
    bstrexsmall_entrypoint_2(player);
    baanim_playForDuration_loopSmooth(player, 0x1CF, 0.7f);
    func_8009FFD8(player, 2, 3, 1, 2);
    yaw_setVelocityBounded(player, 500.0f, 6.5f);
    baanim_setDurationRange(player, 0.1f, 10.0f);
    func_8008C9F0(player, 300.0f, 600.0f, 0.86f, 0.48f);
    func_8008CA30(player, 1.0f);
}

void func_80801688_bstrexsmall(s32 player)
{
    bstrexsmall_entrypoint_3();
    func_808002B8_bstrexsmall(player);
    func_8009D3A8(player, 0);
    func_800A2CE8(player, 0x3F11F8A1, 3);
    func_800A2CE8(player, 0x3D8FC505, 4);
    bs_setState(player, func_80800154_bstrexsmall(player, 0));
}

int bstrexsmall_entrypoint_13(int index)
{
    return D_80801B98_bstrexsmall[index];
}

void func_80801718_bstrexsmall(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bstrexsmall_entrypoint_1(arg0);
}

void func_80801748_bstrexsmall(PlayerState *player)
{
    AnimCtrl *anim;
    f32 unk_0;

    anim = baanim_getAnimCtrlPtr(player);
    bstrexsmall_entrypoint_2(player);
    unk_0 = bs_getPreviousState(player) == 0x143 ? 0.5f : 0.2f;
    anctrl_reset(anim);
    func_8008B1C8(anim, unk_0);
    anctrl_setIndex(anim, 0x1D2);
    anctrl_setDuration(anim, 8.5f);
    anctrl_setStart(anim, 0.13f);
    anctrl_setPlaybackType(anim, 2);
    anctrl_start(anim);
    func_8009FFD8(player, 1, 3, 2, 2);
    yaw_setVelocityBounded(player, 500.0f, 6.5f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800909CC(player);
}

void func_80801844_bstrexsmall(s32 player)
{
    s32 unk_0;
    unk_0 = player;
    func_8009D3A8(player, 0);
    bstrexsmall_entrypoint_3(player);
    if (baanim_isAt(unk_0, 0x3DC28F5C) != 0) {
        func_8009DF18(unk_0, 0x570, 1.2f, 0x4650);
    }
    if (baanim_isAt(unk_0, 0x3F0B851F) != 0) {
        func_8009DEC0(unk_0, 0x56F, 0x3F99999A, 0x3FB33333, 0x4E20, 0x55F0);
    }
    if (baanim_isAt(unk_0, 0x3F51EB85) != 0) {
        func_8009DF18(unk_0, 0x570, 1.2f, 0x4E20);
    }
    if (baanim_isAt(unk_0, 0x3F6B851F) != 0) {
        func_8009DF18(unk_0, 0x570, 1.3f, 0x32C8);
    }
    func_808002B8_bstrexsmall(unk_0);
    bs_setState(unk_0, func_8080020C_bstrexsmall(unk_0, 0));
}

int bstrexsmall_entrypoint_14(s32 index)
{
    return D_80801BA8_bstrexsmall[index];
}

void func_80801970_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

void func_80801990_bstrexsmall(PlayerState *player)
{
    bstrexsmall_entrypoint_2(player);
    baanim_playForDuration_loopSmooth(player, 0x1CE, 1.2f);
    func_8009FFD8(player, 2, 3, 1, 2);
    yaw_setVelocityBounded(player, 500.0f, 6.5f);
    baanim_setDurationRange(player, 0.1f, 10.0f);
    func_8008C9F0(player, 100.0f, 300.0f, 1.15f, 0.61f);
    func_8008CA30(player, 1.0f);
}

int func_80801A3C_bstrexsmall(Actor *actor)
{
    Actor *unk_0;
    unk_0 = actor;
    bstrexsmall_entrypoint_3(unk_0);
    func_808002B8_bstrexsmall(unk_0);
    func_8009D3A8(unk_0, 0);
    func_800A2CE8(unk_0, 0x3F65CFAB, 3);
    func_800A2CE8(unk_0, 0x3ECB9F56, 4);
    bs_setState(unk_0, func_80800154_bstrexsmall(unk_0, 0));
}

int bstrexsmall_entrypoint_15(s32 index)
{
    return D_80801BB8_bstrexsmall[index];
}

// TU-NOTE: The .data of this overlay is defined here in C. The tables hold pointers to
// functions of this file; IDO's assembler schedules some of them differently unless the
// tables are in the same unit. Values are taken from the ROM.
extern void _basudie_entrypoint_11();
extern void _bsdrone_entrypoint_3();
u8 D_80801AF0_bstrexsmall[24] = {0x3, 0x6,  0x0, 0x16, 0x6D, 0x60, 0x0, 0xE,  0x1, 0xCC, 0x1, 0xF3,
                                 0x0, 0x80, 0x0, 0x13, 0x5,  0x6C, 0x0, 0x11, 0x0, 0x0,  0x0, 0x0};
int D_80801B08_bstrexsmall[4] = {(u32) func_80800364_bstrexsmall, (u32) func_80800384_bstrexsmall,
                                 (u32) func_808003D0_bstrexsmall, (u32) func_8080005C_bstrexsmall};
int D_80801B18_bstrexsmall[4] = {(u32) func_8080070C_bstrexsmall, (u32) func_80800744_bstrexsmall,
                                 (u32) func_80800818_bstrexsmall, (u32) _basudie_entrypoint_11};
s32 D_80801B28_bstrexsmall[4] = {(u32) func_80800998_bstrexsmall, (u32) func_808009C0_bstrexsmall,
                                 (u32) func_808009E8_bstrexsmall, (u32) _bsdrone_entrypoint_3};
s32 D_80801B38_bstrexsmall[4] = {(u32) func_80800AF0_bstrexsmall, (u32) func_80800B10_bstrexsmall,
                                 (u32) func_80800B40_bstrexsmall, (u32) func_8080005C_bstrexsmall};
s32 D_80801B48_bstrexsmall[4] = {(u32) func_80800E94_bstrexsmall, (u32) func_80800EC0_bstrexsmall,
                                 (u32) func_80800EF0_bstrexsmall, (u32) func_8080005C_bstrexsmall};
s32 D_80801B58_bstrexsmall[4] = {(u32) func_80801004_bstrexsmall, (u32) func_8080102C_bstrexsmall,
                                 (u32) func_8080106C_bstrexsmall, (u32) func_8080005C_bstrexsmall};
int D_80801B68_bstrexsmall[4] = {(u32) func_808010E8_bstrexsmall, (u32) func_80801110_bstrexsmall,
                                 (u32) func_80801150_bstrexsmall, (u32) func_8080005C_bstrexsmall};
s32 D_80801B78_bstrexsmall[4] = {(u32) func_808011A8_bstrexsmall, (u32) func_808011D0_bstrexsmall,
                                 (u32) func_808011F8_bstrexsmall, (u32) func_8080005C_bstrexsmall};
int D_80801B88_bstrexsmall[4] = {(u32) func_808013E8_bstrexsmall, (u32) func_80801414_bstrexsmall,
                                 (u32) func_80801438_bstrexsmall, (u32) func_8080007C_bstrexsmall};
int D_80801B98_bstrexsmall[4] = {(u32) func_808015BC_bstrexsmall, (u32) func_808015DC_bstrexsmall,
                                 (u32) func_80801688_bstrexsmall, (u32) func_8080005C_bstrexsmall};
s32 D_80801BA8_bstrexsmall[4] = {(u32) func_80801718_bstrexsmall, (u32) func_80801748_bstrexsmall,
                                 (u32) func_80801844_bstrexsmall, (u32) func_8080005C_bstrexsmall};
s32 D_80801BB8_bstrexsmall[6] = {(u32) func_80801970_bstrexsmall,
                                 (u32) func_80801990_bstrexsmall,
                                 (u32) func_80801A3C_bstrexsmall,
                                 (u32) func_8080005C_bstrexsmall,
                                 0x0,
                                 0x0};
