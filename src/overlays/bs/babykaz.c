// Most likely the states of Clockwork Kazooie, the player-controlled egg: idle, walk, jump, fall,
// rest, drone, wind-up spin, fuse timer, and the explosion that returns control to Banjo-Kazooie.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void func_8009C128(s32, f32 *);
extern f32 yaw_get(s32);
extern s32 _bababykaz_entrypoint_4(s32);
extern void _cheggclockwork_entrypoint_3(f32 *, f32, s32, s32);
extern void *func_80092AD8(PlayerState *);
extern void func_800E0AF0(void *, f32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone();
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 D_80801730_bsbabykaz[];
extern s32 func_8009E69C(PlayerState *, s32);
extern void func_800A4D6C(PlayerState *, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void func_8009590C(PlayerState *, f32);
extern void func_800947EC(PlayerState *, s32, s32);
extern s32 D_80801740_bsbabykaz[];
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 D_80801750_bsbabykaz[];
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 D_80801760_bsbabykaz[];
extern s32 D_80801770_bsbabykaz[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80801780_bsbabykaz[];
extern s32 D_80801790_bsbabykaz[];
extern s32 func_8009E6EC(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern s32 _bababykaz_entrypoint_5(PlayerState *);
extern u8 D_8012762C;
extern void func_800F3BB0(PlayerState *, f32 *);
extern s32 D_808017A0_bsbabykaz[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800C6A7C(f32 *, f32 *, f32 *, s32);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern void func_800A106C(PlayerState *, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern int func_800EA068(int flags);

void bsbabykaz_entrypoint_3();
void bsbabykaz_entrypoint_4();
void bsbabykaz_entrypoint_5();

void bsbabykaz_entrypoint_0(s32 player)
{
    f32 pos[3];
    func_8009C128(player, pos);
    _cheggclockwork_entrypoint_3(pos, yaw_get(player), _bababykaz_entrypoint_4(player),
                                 *(s32 *) (player + 0x160));
}

unsigned int func_80800050_bsbabykaz(void *player)
{
    // Matching: the zero goes through a temporary.
    float value = 0.0f;
    *(float *) ((char *) player + 0x170) = value;
}

void func_8080005C_bsbabykaz(PlayerState *player)
{
    void *unk_0;
    unk_0 = func_80092AD8(player);
    func_800E0AF0(unk_0, 1.0f);
    func_800E0AFC(unk_0, 0x5B, 1.0f, -50.0f, 0.0f, 0.0f);
    func_800E0AFC(unk_0, 0x5D, 1.0f, 0.0f, player->unk170, 0.0f);
    player->unk170 += func_800D8FF8() * 500.0f;
}

int func_808000F8_bsbabykaz(Actor *player)
{
    if (bakey_pressed(player, 9)) {
        _bababykaz_entrypoint_7(player, 1);
    }
    _bababykaz_entrypoint_3(player);
}

void func_80800134_bsbabykaz(PlayerState *player)
{
    f32 zone_pos;

    zone_pos = bastick_getZonePosition(player);
    switch (bastick_getZone(player)) {
        case 0:
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            break;
        case 1:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(zone_pos, 80.0f, 400.0f));
    }
}

int func_808001A8_bsbabykaz(s32 player, s32 next_state)
{
    if (bastick_getZone() == 1) {
        next_state = 0x135;
    }
    if (bakey_pressed(player, 8)) {
        next_state = 0x134;
    }
    if (func_808000F8_bsbabykaz(player)) {
        next_state = 0x94;
    }
    return next_state;
}

void func_80800214_bsbabykaz(s32 *player)
{
    s8 _sfpad[8];
    s32 pos;

    func_8009C128(player, &pos);
    func_801013A8(&pos, 0x39, 0);
    bs_setState(player, 0x5A);
    _bababykaz_entrypoint_9(player);
    func_800F82C0(player[0x184 / 4]);
    func_800F9AFC();
}

void bsbabykaz_entrypoint_1(PlayerState *player)
{
    s32 state = func_8009E6EC(player);

    switch (state) {
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x23:
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
        case 0x91:
            bs_setState(player, 0x94);
            func_8009E830(player, 2);
            break;
        case 0x66:
            func_8009E830(player, 1);
            break;
        case 0x87:
            bs_setState(player, 0x94);
            func_8009E830(player, 2);
            _batimer_set(player, 0, 0.0f);
            break;
        case 0x86:
            func_80800214_bsbabykaz(player);
            func_8009E830(player, 2);
            break;
        case 0x8E:
            *(s32 *) ((u8 *) player + 0x160) = 0;
            bs_setState(player, 0x94);
            func_8009E830(player, 2);
            _batimer_set(player, 0, 0.0f);
            break;
        default:
            func_80099B94(player);
    }
}

void func_808003D0_bsbabykaz()
{
    bsbabykaz_entrypoint_3();
}

int func_808003F0_bsbabykaz(Actor *player)
{
    // Matching: extra copy of the pointer.
    Actor *player_copy;
    bsbabykaz_entrypoint_4();
    player_copy = player;
    func_8009FFD8(player_copy, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(player_copy, 0);
}

int func_80800438_bsbabykaz(Actor *player)
{
    s32 next_state;
    next_state = 0;
    bsbabykaz_entrypoint_5(player);
    if (baanim_isStopped(player)) {
        next_state = 0x136;
    }
    if (func_8008DD04(player)) {
        next_state = 0x133;
    }
    bs_setState(player, func_808001A8_bsbabykaz(player, next_state));
}

s32 bsbabykaz_entrypoint_2(s32 slot)
{
    return D_80801730_bsbabykaz[slot];
}

void bsbabykaz_entrypoint_3(player) PlayerState *player;
{
    if (!func_8009E69C(player, 0x20)) {
        bastick_popZone(player);
        func_800A4D6C(player, 1.0f, 1.0f);
        func_80095A40(player);
        func_8009590C(player, 0.0f);
        func_800A1040(player);
        func_8009E474(player);
        func_800947EC(player, 1, 0);
        func_80092864(player, 1.0f);
        func_80095A74(player, 0);
    }
}

void bsbabykaz_entrypoint_4(player) PlayerState *player;
{
    if (!func_8009E6C4(player, 0x20)) {
        _bababykaz_entrypoint_7(player, 0);
        func_800A106C(player, 20.0f, 40.0f);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 1.0f);
        func_800A4D6C(player, 0.329986572265625f, 0.329986572265625f);
        func_800959C8(player, 35.0f, 12.0f);
        func_8009590C(player, 35.0f);
        func_8009E4AC(player);
        func_8009E55C(player, 0, 20.0f);
        func_8009E53C(player, 0, 0.0f);
        func_8009E55C(player, 1, 0.0f);
        _bababykaz_entrypoint_10(player, -1);
        _bababykaz_entrypoint_6(player);
        func_800947EC(player, 1, 1);
        func_80800050_bsbabykaz(player);
        player->unk160.word = 1;
        func_80092864(player, 0.29998779296875f);
        func_80095A74(player, 1);
    }
}

void bsbabykaz_entrypoint_5(player) s32 player;
{
    s32 unk_0;

if (func_8008DD70() == 0) {
    unk_0 = _bababykaz_entrypoint_5(player);
    if ((unk_0 != -1) && (func_800F7180(unk_0) == 0)) {
        _bababykaz_entrypoint_7(player, 1);
    }
    if ((player_isStable(player) != 0) && (func_80096694(player) == 0x14)) {
        _bababykaz_entrypoint_7(player, 1);
    }
}

func_8080005C_bsbabykaz(player);
_bababykaz_entrypoint_11(player);
}

void func_8080072C_bsbabykaz(s32 player)
{
    bsbabykaz_entrypoint_3();
    _bsdrone_entrypoint_2(player);
}
void func_80800754_bsbabykaz(s32 player)
{
    bsbabykaz_entrypoint_4();
    _bsdrone_entrypoint_0(player);
}
void func_8080077C_bsbabykaz(s32 player)
{
    s32 player_copy;
    s32 unk_0;
    // Matching: the copy and the `| 0` only exist to steer IDO's register allocation.
    unk_0 = (player_copy = player | 0);
    _bsdrone_entrypoint_1(player_copy);
    bsbabykaz_entrypoint_5(player_copy);

if ((_bababykaz_entrypoint_3(player_copy) != 0) && (_badrone_entrypoint_3(player_copy) != 1)) {
    bs_setState(player_copy, 0x94);
}

}

int bsbabykaz_entrypoint_6(s32 slot)
{
    return D_80801740_bsbabykaz[slot];
}

void func_808007EC_bsbabykaz()
{
    bsbabykaz_entrypoint_3();
}

void func_8080080C_bsbabykaz(u8 *player)
{
    bsbabykaz_entrypoint_4();
    baanim_playForDuration_loopSmooth(player, 0xA9, 0.38f);
    func_8009FFD8(player, 1, 1, 3, 6);
    *(s32 *) ((u8 *) player + 0x15C) = 0;
}

void func_80800864_bsbabykaz(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    bsbabykaz_entrypoint_5(player);
    if (baflag_isTrue(player, 15))
        func_8009B7C0(player);
    else
        func_80800134_bsbabykaz(player);
    func_8009BB24(player, velocity);

switch (player->unk15C.word) {
    case 1:
        break;
    case 0:
        if (func_8008DF8C(player, 90)) {
            anctrl_reset(anim_ctrl);
            anctrl_setIndex(anim_ctrl, 0xA9);
            anctrl_setStart(anim_ctrl, 0.6667f);
            anctrl_setDuration(anim_ctrl, 2.0f);
            anctrl_setPlaybackType(anim_ctrl, 1);
            anctrl_start(anim_ctrl);
            player->unk15C.word = 1;
        }
}

if (player_isStable(player)) {
    func_8009FE58(player);
    if (anctrl_getPlaybackType(anim_ctrl) == 1)
        next_state = 0x132;
    else
        next_state = 0x136;
}

if (func_808000F8_bsbabykaz(player))
    next_state = 0x94;
bs_setState(player, next_state);
}

int bsbabykaz_entrypoint_7(s32 slot)
{
    return D_80801750_bsbabykaz[slot];
}

void func_808009C4_bsbabykaz(s32 player)
{
    baphysics_reset_gravity();
    bsbabykaz_entrypoint_3(player);
}
void func_808009EC_bsbabykaz(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    bsbabykaz_entrypoint_4(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0xA9);
    anctrl_setDuration(anim_ctrl, 1.9f);
    func_8008B1C8(anim_ctrl, 0.134f);
    anctrl_setStart(anim_ctrl, 0.3f);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.5042f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);

if (bastick_distance(player) != 0.0f) {
    yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
}

baphysics_set_target_yaw(player, yaw_getIdeal(player));
func_80800134_bsbabykaz(player);
baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                  baphysics_get_target_horizontal_velocity(player));
baphysics_set_vertical_velocity(player, 475.0f);
baphysics_set_gravity(player, -1200.0f);
player->unk15C.word = 0;
func_8009DE38(player, 0x432, 1.4f);
}

void func_80800B54_bsbabykaz(Actor *player)
{
    s32 next_state;
    s32 *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    bsbabykaz_entrypoint_5(player);

if (baflag_isTrue(player, 0xF) != 0) {
    func_8009B7C0(player);
} else {

func_80800134_bsbabykaz(player);
}
func_8009BB24(player, velocity);
if (((bakey_released(player, 8) != 0) && (velocity[1] > 0.0f)) || (func_8008D544(player) == 0)) {
    baphysics_reset_gravity(player);
}
switch (*(s32 *) ((char *) player + 0x15C)) {
    case 2:
        break;

case 0:
    if (anctrl_isStopped(anim_ctrl) != 0) {
        baanim_setEndAndDuration(player, 0x3F2AACDA, 0x40800000);
        *(s32 *) ((char *) player + 0x15C) = 1;
    }

if (func_8008DF8C(player, 0x82) != 0) {
    baanim_setEndAndDuration(player, 0x3F800000, 0x3FB33333);
    *(s32 *) ((char *) player + 0x15C) = 2;
}

break;

case 1:
    if (baanim_isStopped(player) != 0) {
        next_state = 0x133;
    }

if (func_8008DF8C(player, 0x5A) != 0) {
    baanim_setEndAndDuration(player, 0x3F800000, 0x40000000);
    *(s32 *) ((char *) player + 0x15C) = 2;
}

}
if (player_isStable(player) != 0) {
    func_8009FE58(player);
    next_state = 0x132;
}
if (func_808000F8_bsbabykaz(player) != 0) {
    next_state = 0x94;
}
bs_setState(player, next_state);
}

int bsbabykaz_entrypoint_8(s32 slot)
{
    return D_80801760_bsbabykaz[slot];
}

void func_80800D18_bsbabykaz(s32 player)
{
    _bsrest_entrypoint_14();
    bsbabykaz_entrypoint_3(player);
}
void func_80800D40_bsbabykaz(s32 player)
{
    bsbabykaz_entrypoint_4();
    _bsrest_entrypoint_16(player);
}
int func_80800D68_bsbabykaz(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = 0x136;
    }
    bsbabykaz_entrypoint_5(player);
    if (_bababykaz_entrypoint_3(player)) {
        next_state = 0x94;
    }
    bs_setState(player, next_state);
}

int bsbabykaz_entrypoint_9(s32 slot)
{
    return D_80801770_bsbabykaz[slot];
}

s32 func_80800DD4_bsbabykaz(Actor *player)
{
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
    bsbabykaz_entrypoint_3(player);
}

void func_80800E0C_bsbabykaz(PlayerState *player)
{
    bsbabykaz_entrypoint_4(player);
    baanim_playForDuration_loopSmooth(player, 0xA6, 0.66f);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 80.0f, 400.0f, 0.54f, 0.35f);
    func_8008CA30(player, 1.0f);
    func_8009BFE4(player, 1000.0f, 12.0f);
    baroll_setAngularVelocity(player, 1000.0f, 12.0f);
}

void func_80800EC8_bsbabykaz(s32 player)
{
    s32 next_state;

    next_state = 0;
    bsbabykaz_entrypoint_5();
    func_8009D2F0(player, 0, 0x3F000000);
    if (baanim_isAt(player, 0x3EF0A3D7) != 0) {
        func_8009DBB0(player, 0x555, 0x3FA00000, 0x3FACCCCD, 0x2710);
    }
    if (baanim_isAt(player, 0x3F7851EC) != 0) {
        func_8009DBB0(player, 0x556, 0x3FA00000, 0x3FACCCCD, 0x2710);
    }
    func_80800134_bsbabykaz(player);
    if ((bastick_getZone(player) == 0) && (func_8009BCD4(player, 0x40400000) != 0)) {
        next_state = 0x136;
    }
    if (func_8008E148(player) != 0) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (func_8008DD04(player) != 0) {
        next_state = 0x133;
    }
    if (bakey_pressed(player, 8) != 0) {
        next_state = 0x134;
    }
    if (func_808000F8_bsbabykaz(player) != 0) {
        next_state = 0x94;
    }
    bs_setState(player, next_state);
}

int bsbabykaz_entrypoint_10(s32 slot)
{
    return D_80801780_bsbabykaz[slot];
}

void func_80801014_bsbabykaz(s32 player)
{
    func_80090A2C();
    func_800951B4(player);
    bsbabykaz_entrypoint_3(player);
}

void func_80801044_bsbabykaz(Actor *player)
{
    // Matching: the pointer copy and the anim id temporary are needed for the match.
    int anim_id;
    s32 player_copy;
    player_copy = player;
    bsbabykaz_entrypoint_4(player);
    anim_id = 0xa4;
    baanim_playForDuration_loopSmooth(player_copy, anim_id, 6.5f);
    func_8009FFD8(player_copy, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(player_copy, 0);
    func_800909CC(player_copy);
}

int func_808010AC_bsbabykaz(Actor *player)
{
    s32 next_state;
    next_state = 0;
    bsbabykaz_entrypoint_5(player);
    if (func_8008E148(player)) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (func_8008DD04(player)) {
        next_state = 0x133;

}
return bs_setState(player, func_808001A8_bsbabykaz(player, next_state));
}

int bsbabykaz_entrypoint_11(s32 slot)
{
    return D_80801790_bsbabykaz[slot];
}

void func_80801134_bsbabykaz(player, stage) Actor *player;
s32 stage;
{
    f32 timer;
    f32 timer_2;
    switch (stage) {
        case 1:
            if (func_800EA068(0x400)) {
                timer = 0.3f;
            }

else
{
    timer = 2.0f;
}
_batimer_set(player, 0, timer);
break;

case 2:
    if (func_800EA068(0x400)) {
        timer_2 = 0.3f;
    }

else
{
    timer_2 = 2.0f;
}
_batimer_set(player, 0, timer_2);
}

*((s32 *) (((u8 *) player) + 0x15c)) = stage;
}

void func_808011EC_bsbabykaz(PlayerState *player)
{
    switch (func_8009E6EC(player)) {
        case 0x87:
            _batimer_set(player, 0, 0.0f);
            func_8009E830(player, 2);
            break;

case 0x17:
    if (func_80099A58(player) == 1) {
        func_800F9BA4();
        func_80801134_bsbabykaz(player, 3);
        func_8009E830(player, 2);
    }

break;

case 0x94:
    if (player->unk15C.word == 2) {
        func_800F9B54();
        func_80801134_bsbabykaz(player, 3);
    }

case 0x86:
    break;
    }
    }

    void func_808012C4_bsbabykaz(s32 player)
    {
        func_80091E6C();
        bsbabykaz_entrypoint_3(player);
    }
    void func_808012EC_bsbabykaz(PlayerState *player)
    {
        s32 unk_0;
        bsbabykaz_entrypoint_4(player);
        unk_0 = _bababykaz_entrypoint_5(player);
        _bababykaz_entrypoint_10(player, unk_0);
        bsbabykaz_entrypoint_0(player);
        _bababykaz_entrypoint_9(player);
        func_80091E48(player, 0x20);
        if (unk_0 < 0) {
            func_80801134_bsbabykaz(player, 1);
        } else {
            func_800F80D8(unk_0);
            func_800F8EBC(unk_0);
            func_80801134_bsbabykaz(player, 2);
        }
    }

    void func_80801384_bsbabykaz(PlayerState *player)
    {
        s32 timer_done;
        Vec3f pos_a;
        // Matching: unk_0 is never used; it only occupies a stack slot.
        s32 unk_0;
        Vec3f pos_b;
        s32 unk_1;

        if (player->unk15C.word != 3) {
            _batimer_decrement(player, 0);
            timer_done = _batimer_isZero(player, 0);

if (!func_8009CC68(player) && !func_800DB9B0() && !func_800F6D24(func_800F54E4())) {
    switch (player->unk15C.word) {
        case 1:
            if (timer_done) {
                func_800F3BB0(player, pos_a.f);
                if (D_8012762C == 0x18)
                    unk_1 = func_80101180(0x418, 0x39, 0);
                else
                    unk_1 = 0;
                if (unk_1 != 1)
                    func_800F9ADC();
                func_80801134_bsbabykaz(player, 3);
            }
            break;
        case 2:
            if (timer_done) {
                func_800F3BB0(player, pos_b.f);
                func_801013A8(pos_b.f, 0x39, 0);
                func_800F9ADC();
                func_80801134_bsbabykaz(player, 3);
            }
        case 3:
            break;
    }
}

}
}

int bsbabykaz_entrypoint_12(s32 slot)
{
    return D_808017A0_bsbabykaz[slot];
}

void bsbabykaz_entrypoint_13(s32 player)
{
    _bababykaz_entrypoint_7(player, 1);
}

s32 bsbabykaz_entrypoint_14(f32 *pos)
{
    f32 head_offset;
    f32 feet[3];
    f32 hit[3];
    f32 head[3];
    f32 head_copy[3];

    func_800EE7F8(feet, pos);
    head_offset = 35.0f;
    func_800EFA4C(head, pos[0], pos[1] + head_offset, pos[2]);
    if (func_800C6A7C(head, feet, hit, 0x400005))
        return 0;
    func_800EE7F8(feet, pos);
    func_800EE7F8(head_copy, head);
    if (func_800C6A7C(feet, head, hit, 0x400005))
        return 0;
    func_800EE7F8(head, head_copy);
    if (func_800C6C94(head, 12.0f, hit, 0x400005))
        return 0;
    return 1;
}

// TU-NOTE: the state tables (formerly babykaz.data.s) are defined here. Seven of them
// referenced the overlay's own bsbabykaz_entrypoint_1, but Rare's post-link tool redirected
// those words to the core2 trampoline _bsbabykaz_entrypoint_1 (0x800827C0) and left them out
// of the reloc list. The local reference matters for codegen: taking the function's address
// in data makes as1 schedule the switch dispatch in bsbabykaz_entrypoint_1 as in the ROM.
// The addend reproduces the redirect with a standard linker, as in bs/btrot.c.
s32 D_80801730_bsbabykaz[4] = {(u32) func_808003D0_bsbabykaz, (u32) func_808003F0_bsbabykaz,
                               (u32) func_80800438_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_80801740_bsbabykaz[4] = {(u32) func_8080072C_bsbabykaz, (u32) func_80800754_bsbabykaz,
                               (u32) func_8080077C_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_80801750_bsbabykaz[4] = {(u32) func_808007EC_bsbabykaz, (u32) func_8080080C_bsbabykaz,
                               (u32) func_80800864_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_80801760_bsbabykaz[4] = {(u32) func_808009C4_bsbabykaz, (u32) func_808009EC_bsbabykaz,
                               (u32) func_80800B54_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_80801770_bsbabykaz[4] = {(u32) func_80800D18_bsbabykaz, (u32) func_80800D40_bsbabykaz,
                               (u32) func_80800D68_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_80801780_bsbabykaz[4] = {(u32) func_80800DD4_bsbabykaz, (u32) func_80800E0C_bsbabykaz,
                               (u32) func_80800EC8_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_80801790_bsbabykaz[4] = {(u32) func_80801014_bsbabykaz, (u32) func_80801044_bsbabykaz,
                               (u32) func_808010AC_bsbabykaz,
                               (u32) bsbabykaz_entrypoint_1 + (0x800827C0 - 0x80800270)};
s32 D_808017A0_bsbabykaz[4] = {(u32) func_808012C4_bsbabykaz, (u32) func_808012EC_bsbabykaz,
                               (u32) func_80801384_bsbabykaz, (u32) func_808011EC_bsbabykaz};
