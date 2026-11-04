// Player states of the Detonator (TNT) transformation: idle, hop-walk, jump, fall, self and
// targeted detonation, death, bounces, rest and drone; exports the form hooks used by tntswim.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

extern u8 D_80802230_bstnt[];
extern s32 func_8009D454();
extern f32 _batimer_get(PlayerState *, s32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void _bapulse_entrypoint_3(PlayerState *, f32, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_8080223C_bstnt[];
extern u8 D_80802284_bstnt[];
extern s32 D_808022FC_bstnt[];
extern void func_800EE7F8(f32 *);
extern s32 func_800A4C48(s32);
extern void func_800CA3F4(s32, f32 *, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern s32 D_80802328_bstnt[];
extern s32 D_808023C8_bstnt[];
extern f32 func_800F0E00(f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_80092BE8(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void func_8009328C(PlayerState *, f32);
extern s32 D_808023F8_bstnt[];
extern s32 D_80802408_bstnt[];
extern void func_80092864(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern f32 _bapulse_entrypoint_1(PlayerState *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 D_80802418_bstnt[];
extern s32 D_8080246C_bstnt[];
extern s32 D_808024B8_bstnt[];
extern s32 D_80802504_bstnt[];
extern s32 D_8080254C_bstnt[];
extern s32 D_8080255C_bstnt[];
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern void baanim_setEnd(PlayerState *, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 D_8080256C_bstnt[];
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern s32 D_8080257C_bstnt[];
typedef struct bstnt_struct {
    char pad[0x15C];
    int unk15C;
} BSTNT;
extern s32 D_8080258C_bstnt[];
extern s32 D_8080259C_bstnt[];
extern s32 D_808025AC_bstnt[];
extern s32 D_808025BC_bstnt[];
extern s32 D_808025CC_bstnt[];
extern u8 D_808022CC_bstnt[];
extern s32 func_800B5BE4(s32);
extern void func_800BABB8(s32, void *, s32, f32, void *);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA5BC(s32, f32, f32);
extern void func_800BA994();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 baanim_getTimer(PlayerState *);
extern int baanim_isAt(PlayerState *, f32);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern f32 func_800136E4(f32);
extern f32 func_800D8FF8(void);
void bstnt_entrypoint_4();
int bstnt_entrypoint_8();

void func_80800000_bstnt(s32 player)
{
    func_8009DF94(player, 0x504, 0x3F800000, 0x7FFF);
}

void func_80800028_bstnt(player) u8 *player;
{
    unsigned int handle;
    handle = *(u8 *) ((u8 *) player + 0x160);
    if (handle != 0) {
        func_800C2FDC(handle & 0xFF, handle, player);
    }
    *(u8 *) ((u8 *) player + 0x160) = 0U;
}

void func_80800060_bstnt(player) s32 player;
{
}

void func_80800068_bstnt(u8 *player)
{
    player[0x160] = func_8009D454(player, 0, D_80802230_bstnt);
}

void func_8080009C_bstnt(u8 *player)
{
    u8 handle;
    handle = *(u8 *) ((s8 *) player + 0x160);
    if (handle != 0) {
        // Matching: empty block steers IDO's register allocation.
        if ((handle && handle) && handle) {
        }
        func_800C2FDC(handle & 0xFF, handle, player);
    }
    *(u8 *) ((s8 *) player + 0x160) = 0U;
}

extern void func_80800164_bstnt(PlayerState *);

void func_808000D4_bstnt(PlayerState *player, f32 timer)
{
    if (_batimer_get(player, 2) == 0.0f) {
        _bapulse_entrypoint_3(player, 0.0f, 0.15f);
        func_80092744(player, 1);
        func_80092750(player, 255, 255, 255, 255);
    }
    _batimer_set(player, 2, timer);
}

void func_80800164_bstnt(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 600.0f));
    }
}

s32 func_808001C8_bstnt(s32 player, s32 state)
{
    if (bakey_pressed(player, 8)) {
        state = 0x107;
    }
    if (bstnt_entrypoint_8(player)) {
        state = 0x10E;
    }
    return state;
}

s32 func_80800218_bstnt(u8 *player, s32 state)
{
    s32 next_state;

    next_state = state;
    if (bainput_should_enter_first_person() != 0) {
        next_state = _badrone_entrypoint_24(player);
    }
    if (bakey_pressed(player, 8) != 0) {
        next_state = 0x107;
    }
    if (bstnt_entrypoint_8(player) != 0) {
        next_state = 0x10E;
    }
    if ((*(u8 *) ((char *) player + 0x168) != 0) && (player_isStable(player) != 0)) {
        next_state = 0x10D;
    }
    return next_state;
}

void func_808002AC_bstnt(s32 player, s32 pos)
{
    func_800BBCB8(pos | 0, 0, 1.0f, 8, &D_8080223C_bstnt);
    func_800BBCB8(pos, 0, 1.0f, 0xC, &D_80802284_bstnt);
}

void func_8080030C_bstnt(player, pos) void *player;
void *pos;
{
    f32 scale;
    f32 offset[3];
    f32 size;
    s32 emitter;
    s32 angle;
    s32 unk_0;

    emitter = func_800B5BE4(8);
    func_800BABB8(emitter, pos, 0, 1.0f, D_808022CC_bstnt);
    scale = 0.43f;
    func_800BA8F8(emitter, scale, scale);
    size = 19.0f / scale;
    func_800BA5BC(emitter, size, size);
    for (angle = 0; angle != 360; angle += 45) {
        func_800EFA4C(&offset, 0.0f, angle, 480.0f);
        func_800BA994(emitter, (s16) offset[0], (s16) offset[1], (s16) offset[2],
                      (s16) offset[0], (s16) offset[1], (s16) offset[2]);
        func_800BA22C(emitter, 1);
        func_800EFA4C(&offset, -45.0f, angle, 430.0f);
        func_800BA994(emitter, (s16) offset[0], (s16) offset[1], (s16) offset[2],
                      (s16) offset[0], (s16) offset[1], (s16) offset[2]);
        func_800BA22C(emitter, 1);
    }
}

void func_808004F8_bstnt(player) s32 player;
{
    f32 pos[3];
    func_800EE7F8(pos);
    func_800CA3F4(func_800A4C48(player), pos, 80.0f);
    func_800BBCB8(pos, 0, 1.0f, 1, &D_808022FC_bstnt);
}

void func_80800554_bstnt(s32 player)
{
    s8 _sfpad[8];
    s32 pos;
    s32 emitter_ref;
    s32 emitter;

    func_8009C128(player, &pos);
    func_800CA3F4(func_800A4C48(player), &pos, 2e+01f);
    emitter = func_800B5BE4(8);
    emitter_ref = emitter;
    func_800BABB8(emitter, &pos, 0, 1.0f, &D_80802328_bstnt);
    func_800CA3F4(func_800A4C48(player), &pos, 45.0f);
    func_800BABB8(emitter_ref, &pos, 0, 1.0f, &D_808023C8_bstnt);
}

extern void func_8009DB04(PlayerState *, s32, f32, s32);

s32 func_808005F4_bstnt(void *player)
{
    s32 pos[3];

    func_8009C128(player, pos);
    _bashake_entrypoint_0(player, 3, 2);
    func_8009DB04(player, 0x413, 1.0f, 0x7FFF);
    func_808004F8_bstnt(player, pos);
    func_8080030C_bstnt(player, pos);
    func_808002AC_bstnt(player, pos);
}

int func_80800668_bstnt(Actor *actor)
{
    func_8009E474(actor);
    baflag_clear(actor, 0x32);
}

void func_80800694_bstnt()
{
    func_8009E4AC();
}

s32 func_808006B4_bstnt(Actor *player, s32 fuse)
{
    *(u8 *) ((char *) player + 0x169) = fuse;
    baflag_set(player, 0x32);
    func_8009E55C(player, 1, 0x43480000);
}

s32 func_808006EC_bstnt(void *player)
{
    func_8009E55C(player, 1, 0x41E00000);
    baflag_clear(player, 0x32);
}

void func_80800720_bstnt(PlayerState *player)
{
    player->unk168.bytes[1] = (u32) func_800F0E00((f32) (player->unk168.bytes[1] - 1), 0.0f);
    if (!player->unk168.bytes[1])
        func_808006EC_bstnt(player);
}

extern void baroll_setIdeal(PlayerState *, f32);

extern void func_8009BF5C(PlayerState *, f32);

void func_808007EC_bstnt(PlayerState *player, s32 substate)
{
    player->unk15C.word = substate;

switch (substate) {
    case 1:
        baanim_playForDuration_onceSmooth(player, 0xE6, 0x3FC00000);
        func_8009FFD8(player, 1, 1, 3, 2);
        baphysics_set_target_horizontal_velocity(player, 0.0f);
        func_808000D4_bstnt(player, 10.0f);
        break;
    case 2:
        func_808006B4_bstnt(player, 10);
        func_808005F4_bstnt(player);
        func_800A17A8(player, -1);
        func_800931AC(player, 3);
        player->unk16C = 800.0f;
        player->unk170 = yaw_get(player);
        func_8009328C(player, player->unk170);
        break;
    case 0:
        yaw_setIdeal(player, func_80092BE8(player));
        yaw_applyIdeal(player);
        func_800931AC(player, 1);
        func_808000D4_bstnt(player, 0.1f);
        func_8009BC34(player);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
}

}

s32 func_8080092C_bstnt(u8 *player)
{
    func_80800668_bstnt(player);
    func_80800028_bstnt(player);
    func_808007EC_bstnt(player, 0);
}

void func_80800960_bstnt(Actor *actor)
{
    func_80800694_bstnt(actor);
    func_80800060_bstnt(actor);
    *(s32 *) ((char *) actor + 0x15C) = 0;
    func_808007EC_bstnt(actor, 1);
}

void func_80800998_bstnt(PlayerState *player)
{
    s32 next_state = 0;
    f32 dt = func_800D8FF8();
    func_8009D3A8(player, 0);

if (player_inWater(player)) {
    baphysics_set_gravity(player, -10.0f);
    baphysics_set_terminal_velocity(player, -20.0f);
}

switch (*(s32 *) ((u8 *) player + 0x15C)) {
    case 1:
        if (baanim_isAt(player, 0.1587f))
            func_80800068_bstnt(player);
        if (baanim_isAt(player, 0.277f))
            func_80800000_bstnt(player);
        if (baanim_isAt(player, 0.434f))
            func_808007EC_bstnt(player, 2);
        break;
    case 2:
        func_8080009C_bstnt(player);
        player->unk170 = func_800136E4(player->unk170 + player->unk16C * dt);
        func_8009328C(player, player->unk170);
        if (baanim_getTimer(player) > 0.78f)
            player->unk16C = func_800F0E00(0.0f, player->unk16C - 750.0f * dt);
        if (baanim_isAt(player, 0.5f))
            func_80800554_bstnt(player);
        if (player->unk16C == 0.0f)
            next_state = 0x10C;
}

func_80800720_bstnt(player);
bstnt_entrypoint_4(player);
bs_setState(player, next_state);
}

int bstnt_entrypoint_0(s32 index)
{
    return D_808023F8_bstnt[index];
}

void func_80800B60_bstnt(u8 *player, s32 substate)
{
    f32 yaw;
    f32 player_pos[3];
    f32 target_pos[3];
    *((s32 *) (((s8 *) player) + 0x15C)) = substate;

switch (substate) {
    case 1:
        baanim_playForDuration_onceSmooth(player, 0xE2, 0x3F333333);
        func_8009FFD8(player, 1, 1, 3, 0);
        func_8010114C(*(s32 *) ((s8 *) player + 0x164), 6, 0);
        func_80101038(target_pos);
        func_8009C128(player, player_pos);
        func_800F1E6C(player_pos, target_pos, &yaw);
        yaw_setIdeal(player, yaw);
        _bamovegoto_entrypoint_0(player);
        _bamovegoto_entrypoint_12(player, target_pos);
        _bamovegoto_entrypoint_7(player, 0x3F333333);
        _bamovegoto_entrypoint_13(player);
        return;
    case 2:
        baanim_playForDuration_onceSmooth(player, 0xE3, 0x4059999A);
        func_8009FFD8(player, 1, 1, 3, 6);
        baphysics_set_target_horizontal_velocity(player, 0.0f);
        func_8008F880(*(s32 *) ((s8 *) player + 0x164), target_pos);
        func_8009C128(player, player_pos);
        func_800F1E6C(target_pos, player_pos, &yaw);
        yaw_setIdeal(player, yaw);
}

}

void func_80800CB0_bstnt(s32 player)
{
    func_80800028_bstnt();
    func_800951B4(player);
}
void func_80800CD8_bstnt(Actor *actor)
{
    func_80800060_bstnt();
    *(s32 *) ((char *) actor + 0x15c) = 0;
    func_80800B60_bstnt(actor, 1);
}

void func_80800D08_bstnt(u8 *player)
{
    s32 next_state;
    s32 substate;

    next_state = 0;
    substate = (*(s32 *) ((s8 *) (player) + (0x15C)));

switch (substate) {
    case 1:
        if (_bamovegoto_entrypoint_4(player) != 0) {
            func_80800B60_bstnt(player, 2);
        }
        break;
    case 2:
        if (baanim_isAt(player, 0.1183f) != 0) {
            func_80800068_bstnt(player);
        }
        if (baanim_isAt(player, 0.592f) != 0) {
            func_80800000_bstnt(player);
        }
        if (baanim_isAt(player, 0.65f) != 0) {
            func_8009514C(player);
        }
        if (baanim_isAt(player, 0.665f) != 0) {
            func_8010114C(*(s32 *) ((s8 *) player + 0x164), 5, *(s32 *) ((s8 *) player + 0x184));
            func_8080009C_bstnt(player);
        }
        if (baanim_isAt(player, 0.85f) != 0) {
            func_800951B4(player);
        }
        if (baanim_isStopped(player) != 0) {
            next_state = 0x10C;
        }
}

bstnt_entrypoint_4(player);
bs_setState(player, next_state);
}

int bstnt_entrypoint_1(s32 index)
{
    return D_80802408_bstnt[index];

}

void bstnt_entrypoint_2(player) s32 player;
{
    if (func_8009E74C(player, 0xC) == 0) {
        func_800947EC(player, 1, 0);
        func_80092864(player, 1.0f);
        func_8009C000(player);
        baroll_resetAngularVelocity(player);
        bastick_popZone(player);
        func_80095A40(player);
        func_80092744(player, 0);
    }

}

void bstnt_entrypoint_3(player) PlayerState *player;
{
    if (!func_8009E77C(player, 12)) {
        *(s32 *) ((u8 *) player + 0x164) = 0;
        *(s8 *) ((u8 *) player + 0x168) = 0;
        *(s8 *) ((u8 *) player + 0x16A) = 0;
        _batimer_set(player, 2, 0.0f);
        func_80092864(player, 0.899993896484375f);
        func_8009BFE4(player, 1000.0f, 12.0f);
        baroll_setAngularVelocity(player, 1000.0f, 12.0f);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.12f);
        bastick_setZoneMax(player, 1, 1.0f);
        func_800959C8(player, 85.0f, 38.0f);
        func_800947EC(player, 1, 1);
    }

}

void bstnt_entrypoint_4(player) PlayerState *player;
{
    s32 tint;

if (_batimer_decrement(player, 2)) {
    func_80092744(player, 0);
    _bapulse_entrypoint_2(player);
} else if (_batimer_get(player, 2) > 0.0f) {

_bapulse_entrypoint_4(player);
tint = (s32) func_800F12D4(_bapulse_entrypoint_1(player), 0.0f, 1.0f, 0.0f, 255.0f);
func_80092750(player, 255, tint, tint, 255);
}
player->unk168.bytes[0] = 0;
}

void func_80801058_bstnt(s32 player)
{
    _basudie_entrypoint_8();
    bstnt_entrypoint_2(player);
}
void func_80801080_bstnt(s32 player)
{
    f32 pos[3];

    bstnt_entrypoint_3();
    _basudie_entrypoint_9(player, 0x42480000);
    func_80800554_bstnt(player);
    func_8009C128(player, pos);
    func_808004F8_bstnt(player, pos);
    func_8080030C_bstnt(player, pos);
    func_808002AC_bstnt(player, pos);
    func_8009DB04(player, 0x693, 1.0f, 0x7FFF);
    func_8009D9D4(player);
    func_800BBCB8(pos, 0, 1.0f, 1, &D_80802418_bstnt);
    func_800BBCB8(pos, 0, 1.0f, 1, &D_8080246C_bstnt);
    func_800BBCB8(pos, 0, 1.0f, 1, &D_808024B8_bstnt);
    func_800BBCB8(pos, 0, 1.0f, 9, &D_80802504_bstnt);
}

void func_80801190_bstnt(s32 player)
{
    _basudie_entrypoint_10();
    bstnt_entrypoint_4(player);
}
int bstnt_entrypoint_5(s32 index)
{
    return D_8080254C_bstnt[index];
}

void func_808011CC_bstnt(s32 player)
{
    bstnt_entrypoint_3();
    _bsdrone_entrypoint_0(player);
}
void func_808011F4_bstnt(s32 player)
{
    _bsdrone_entrypoint_1();
    bstnt_entrypoint_4(player);
}
void func_8080121C_bstnt(s32 player)
{
    bstnt_entrypoint_2();
    _bsdrone_entrypoint_2(player);
}
int bstnt_entrypoint_6(s32 index)
{
    return D_8080255C_bstnt[index];
}

void func_80801258_bstnt(PlayerState *player)
{
    AnimCtrl *anim;
    bstnt_entrypoint_3(player);
    anim = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim);
    anctrl_setIndex(anim, 0xE5);
    anctrl_setStart(anim, 0.5036f);
    anctrl_setDuration(anim, 0.7f);
    anctrl_setPlaybackType(anim, 3);
    anctrl_start(anim);
    func_8009FFD8(player, 1, 1, 3, 6);
    player->unk15C.word = 0;
}

void func_808012F8_bstnt(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim;
    f32 unk_0[3];

    next_state = 0;
    anim = baanim_getAnimCtrlPtr(player);
    func_8009D3A8(player, 0);
    func_80800164_bstnt(player);
    func_8009BB24(player, unk_0);
    switch (player->unk15C.word) {
        case 2:
            break;

case 0:
    if (func_8008DF8C(player, 0x82)) {
        baanim_setEnd(player, 0.6538f);
        player->unk15C.word = 1;
    }

break;

case 1:
    if (player_isStable(player)) {
        func_800A2EAC(player);
        baphysics_set_target_horizontal_velocity(player, 0);
        baanim_setEndAndDuration(player, 1.0f, 1);
        player->unk15C.word = 2;
    }

}
if (player_inWater(player))
    next_state = 0x111;
if (player_isStable(player) &&
    (bastick_getZone(player) > 0 || (player->unk15C.word == 2 && anctrl_isStopped(anim)))) {
    if (baflag_isTrue(player, 0x19))
        next_state = _badrone_entrypoint_28(player);
    else
        next_state = 0x10C;
}
bstnt_entrypoint_4(player);
bs_setState(player, next_state);
}

s32 func_80801464_bstnt(Actor *actor)
{
    func_8009BF5C(actor, 0);
    baroll_setIdeal(actor, 0);
    bstnt_entrypoint_2(actor);
}

int bstnt_entrypoint_7(s32 index)
{
    return D_8080256C_bstnt[index];
}

// B pressed and the detonation counter allows it; otherwise plays the error sound.
int bstnt_entrypoint_8(player)
Actor *player;
{
    if (!bakey_pressed(player, 9)) {
        return 0;
    }
    if (func_800A1718(player) >= 2) {
        return 1;
    }
    func_800FC660(0xf);
    return 0;
}

void func_8080150C_bstnt(PlayerState *player)
{
    AnimCtrl *anim;
    f32 unk_0;
    f32 yaw;
    bstnt_entrypoint_3();
    anim = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim);
    anctrl_setSmoothTransition(anim, 0);
    anctrl_setIndex(anim, 0xE2);
    anctrl_setSubrange(anim, 0.0f, 0.4008f);
    anctrl_setDuration(anim, 1.0f);
    anctrl_setPlaybackType(anim, 1);
    anctrl_start(anim);
    func_8009FFD8(player, 1, 3, 1, 6);
    yaw_setVelocityBounded(player, 1200.0f, 10.0f);
    if (bastick_distance(player) != 0.0f) {
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    }
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800164_bstnt(player);
    yaw = yaw_getIdeal(player);
    baphysics_set_horizontal_velocity(player, yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 693.5f);
    baphysics_set_gravity(player, -1200.0f);
    func_8009D7A4(player, 1.35f, 1.45f);
    *((s32 *) (((u8 *) player) + 0x15C)) = 0;
}

void func_8080166C_bstnt(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim;

    next_state = 0;
    anim = baanim_getAnimCtrlPtr(player);
    func_80800164_bstnt(player);
    if (bakey_released(player, 8) && baphysics_get_vertical_velocity(player) > 0.0f) {
        baphysics_reset_gravity(player);

}
switch (*(s32 *) ((u8 *) player + 0x15C)) {
    case 0:
        if (func_8008DF8C(player, 0x82)) {
            baanim_setEndAndDuration(player, 1, 0.7f);
            *(s32 *) ((u8 *) player + 0x15C) = 2;
        } else if (anctrl_isStopped(anim)) {

baanim_setEndAndDuration(player, 0.651f, 3.0f);
*(s32 *) ((u8 *) player + 0x15C) = 1;
}
break;
case 1:
    if (func_8008DF8C(player, 0x82)) {
        baanim_setEndAndDuration(player, 1, 1.0f);
        *(s32 *) ((u8 *) player + 0x15C) = 2;
    }
    break;
case 2:
    func_8009D3A8(player, 0);
    if (player_isStable(player)) {
        func_800A2EAC(player);
        baanim_setEndAndDuration(player, 1, 1.0f);
        *(s32 *) ((u8 *) player + 0x15C) = 3;
    }
    break;
case 3:
    baphysics_set_target_horizontal_velocity(player, func_8009BB5C(player) * 0.25f);
    func_8009D2D8(player, 3);
    func_8009D3A8(player, 0);
    if (anctrl_isStopped(anim)) {
        if (func_8009BB5C(player) > 0.0f)
            next_state = 0x108;
        else
            next_state = 0x10C;
    }
    }
    if (baphysics_get_vertical_velocity(player) < 0.0f && player_inWater(player))
        next_state = 0x111;
    if (bstnt_entrypoint_8(player))
        next_state = 0x10E;
    if (player_isStable(player) && bakey_pressed(player, 8))
        next_state = 0x107;
    bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
    }

    void func_808018D0_bstnt(s32 player)
    {
        baphysics_reset_gravity();
        func_8009BF5C(player, 0);
        baroll_setIdeal(player, 0);
        bstnt_entrypoint_2(player);
    }

    int bstnt_entrypoint_9(s32 index)
    {
        return D_8080257C_bstnt[index];
    }

    // Interrupt 0x42 hands over the actor to detonate at.
void bstnt_entrypoint_10(u8 *player)
    {
        if (func_8009E6EC() == 0x42) {
            (*(s32 *) ((s8 *) (player) + (0x164))) = func_80099A4C(player);
            (*(s8 *) ((s8 *) (player) + (0x168))) = 1;
            func_8009E830(player, 2);
            return;
        }
        func_80099B94(player);
    }

    void func_80801980_bstnt(PlayerState *player, s32 substate)
    {
        extern f32 func_800DC178(f32, f32);
        extern f32 func_800F10B4(f32, f32, f32, f32, f32);
        AnimCtrl *anim;
        f32 speed;
        f32 anim_duration;
        f32 jump_velocity;
        anim = (void *) baanim_getAnimCtrlPtr(player);
        player->unk15C.word = substate;
        switch (substate) {
            case 1: {
                func_8009DB04(player, 0x3F0, func_800DC178(0.96f, 1.04f), 10000);
                func_800A2EEC(player, 4);
                func_8009FFD8(player, 1, 1, 1, 2);

if (bastick_distance(player) != 0.0f) {
    yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
}

baphysics_set_target_yaw(player, yaw_getIdeal(player));
func_80800164_bstnt(player);
baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                  baphysics_get_target_horizontal_velocity(player));
speed = baphysics_get_target_horizontal_velocity(player);
anim_duration = func_800F10B4(speed, 30.0f, 600.0f, 0.35f, 0.7f);
jump_velocity = func_800F10B4(speed, 30.0f, 600.0f, 346.75f, 693.5f);
anctrl_reset(anim);
anctrl_setIndex(anim, 0xE2);
anctrl_setSubrange(anim, 0.0f, 0.4008f);
anctrl_setDuration(anim, anim_duration);
anctrl_setPlaybackType(anim, 1);
anctrl_start(anim);
baphysics_set_vertical_velocity(player, jump_velocity);
break;

}
case 2:
    baanim_setEndAndDuration(player, 0.651f, 3.0f);
    break;
case 3:
    baanim_setEndAndDuration(player, 0.93f, 0.7f);
    break;
case 4:
    player->unk16C = func_8009BB5C(player) * 0.25f;
    func_8009D2D8(player, 3);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
    func_800A2FCC(player, 0);
    baanim_setEndAndDuration(player, 0.93f, 0.7f);
    break;
case 0:
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    }
    }

    void func_80801C0C_bstnt(BSTNT *player)
    {
        BSTNT *tnt;
        tnt = player;
        bstnt_entrypoint_3();
        tnt->unk15C = 0;
        func_80801980_bstnt(tnt, 1);
    }

    void func_80801C3C_bstnt(PlayerState *player)
    {
        s32 next_state = 0;
        AnimCtrl *anim;
        f32 unk_0[3];

        anim = baanim_getAnimCtrlPtr(player);
        func_80800164_bstnt(player);
        func_8009BB24(player, unk_0);
        switch ((u32) player->unk15C.word) {
            case 1:
                if (func_8008DF8C(player, 0x82))
                    func_80801980_bstnt(player, 3);
                else if (anctrl_isStopped(anim))
                    func_80801980_bstnt(player, 2);
                next_state = func_808001C8_bstnt(player, 0);
                break;
            case 2:
                if (func_8008DF8C(player, 0x82))
                    func_80801980_bstnt(player, 3);
                next_state = func_808001C8_bstnt(player, 0);
                break;
            case 3:
                func_8009D3A8(player, 0);
                if (player_isStable(player))
                    func_80801980_bstnt(player, 4);
                next_state = func_808001C8_bstnt(player, 0);
                break;
            case 4:
                if (player->unk168.bytes[0] && player_isStable(player))
                    next_state = 0x10D;
                func_8009D3A8(player, 0);
                if (anctrl_isStopped(anim)) {
                    if (baphysics_get_target_horizontal_velocity(player) > 0.0f) {
                        func_80801980_bstnt(player, 1);
                    } else {

next_state = 0x10C;
}
}
else
{
    baphysics_set_target_horizontal_velocity(player, player->unk16C);
}
next_state = func_80800218_bstnt(player, next_state);
}
if (player_inWater(player))
    next_state = 0x111;
bstnt_entrypoint_4(player);
bs_setState(player, next_state);
}

void func_80801E20_bstnt(s32 player)
{
    func_80801980_bstnt(player, 0);
    bstnt_entrypoint_2(player);
}

int bstnt_entrypoint_11(s32 index)
{
    return D_8080258C_bstnt[index];
}

s32 func_80801E60_bstnt(void *player)
{
    bstnt_entrypoint_3();
    _babounce_entrypoint_4(player, 1);
    _babounce_entrypoint_5(player, 0xE9, 0x3ED0FF97);
}

void func_80801EA0_bstnt(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (baanim_isAt(player, 0.5f) != 0) {
        func_800951B4(player);
    }
    if (_babounce_entrypoint_2(player) != 0) {
        func_80800164_bstnt(player);
    }
    if (_babounce_entrypoint_9(player) != 0) {
        next_state = 0x10C;
    }
    bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

void func_80801F20_bstnt(s32 player)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(player);
}
int bstnt_entrypoint_12(s32 index)
{
    return D_8080259C_bstnt[index];
}

s32 func_80801F5C_bstnt(s32 player)
{
    bstnt_entrypoint_3(player);
    _babounce_entrypoint_4(player, 2);
    _babounce_entrypoint_5(player, 0xE9, 0x3ED0FF97);
}

int func_80801F9C_bstnt(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_babounce_entrypoint_2(player)) {
        func_80800164_bstnt(player);
    }
    if (_babounce_entrypoint_9(player)) {
        next_state = 0x10C;
    }
    bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

void func_80802000_bstnt(s32 player)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(player);
}
int bstnt_entrypoint_13(s32 index)
{
    return D_808025AC_bstnt[index];
}

void func_8080203C_bstnt(s32 player)
{
    _bsrest_entrypoint_14();
    bstnt_entrypoint_2(player);
}
void func_80802064_bstnt(s32 player)
{
    bstnt_entrypoint_3();
    _bsrest_entrypoint_16(player);
}
int func_8080208C_bstnt(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = _bsrest_entrypoint_13(player);
    }
    bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

int bstnt_entrypoint_14(s32 index)
{
    return D_808025BC_bstnt[index];
}

void func_808020EC_bstnt(s32 player)
{
    bstnt_entrypoint_2();
    func_80090A2C(player);
}
int func_80802114_bstnt(Actor *player)
{
    int anim_id;
    s32 tnt;
    tnt = player;
    bstnt_entrypoint_3(player);
    anim_id = 0xe5;
    baanim_playForDuration_loopSmooth(tnt, anim_id, 0x40D00000);
    func_8009FFD8(tnt, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(tnt, 0);
    func_800909CC(tnt);
}

void func_8080217C_bstnt(PlayerState *player)
{
    s32 next_state;
    next_state = 0;
    if (bastick_getZone(player) > 0)
        next_state = 0x108;
    if (player_inWater(player))
        next_state = 0x111;
    next_state = func_80800218_bstnt(player, next_state);
    bstnt_entrypoint_4(player);
    bs_setState(player, next_state);
}

int bstnt_entrypoint_15(s32 index)
{
    return D_808025CC_bstnt[index];
}

// TU-NOTE: this overlay's .data is defined here in C. The tables hold pointers to functions
// of this file; IDO's assembler schedules some functions differently unless they are in the same unit.
extern void _bstnt_entrypoint_10();
extern void _basudie_entrypoint_11();
extern void _bsdrone_entrypoint_3();
extern void func_80099AA8();
u8 D_80802230_bstnt[12] = {0x3, 0x6, 0x0, 0x13, 0x5, 0x7, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0};
u8 D_8080223C_bstnt[72] = {0x0,  0x1D, 0x9,  0xE2, 0x0,  0x1B, 0xF8, 0x30, 0xFB, 0x50, 0x0, 0x2C,
                           0xFF, 0x38, 0x1,  0xC2, 0xFF, 0x38, 0x0,  0xC8, 0x3,  0x20, 0x0, 0xC8,
                           0x0,  0x16, 0x10, 0x0,  0x0,  0x27, 0x0,  0x0,  0x0,  0xC8, 0x0, 0x0,
                           0x0,  0xF0, 0x0,  0x22, 0x0,  0x26, 0x0,  0x26, 0x0,  0x1C, 0x0, 0x1C,
                           0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0x2B, 0x1,  0x4C, 0x1, 0xB3,
                           0x0,  0x4,  0x0,  0xB3, 0x0,  0x7,  0x0,  0x2,  0x0,  0x0,  0x0, 0x0};
u8 D_80802284_bstnt[72] = {0x0,  0x1D, 0x9,  0xE2, 0x0,  0x1B, 0xF8, 0x30, 0xFB, 0x50, 0x0, 0x2C,
                           0xFE, 0x70, 0x0,  0xFA, 0xFE, 0x70, 0x1,  0x90, 0x1,  0x90, 0x1, 0x90,
                           0x0,  0x16, 0x10, 0x0,  0x0,  0x27, 0x0,  0x0,  0x0,  0xC8, 0x0, 0x0,
                           0x0,  0xF0, 0x0,  0x22, 0x0,  0x26, 0x0,  0x26, 0x0,  0x1C, 0x0, 0x1C,
                           0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0x2B, 0x1,  0x4C, 0x1, 0xB3,
                           0x0,  0x4,  0x0,  0x99, 0x0,  0x7,  0x0,  0x2,  0x0,  0x0,  0x0, 0x0};
u8 D_808022CC_bstnt[48] = {0x0,  0x1D, 0x9, 0xDC, 0x0, 0x18, 0x0, 0x0,  0x0,  0x0,  0x1,  0x0,
                           0x1,  0x0,  0x0, 0x15, 0x0, 0x0,  0x0, 0x19, 0x0,  0x20, 0xDE, 0xA7,
                           0x71, 0xDC, 0x0, 0x1E, 0x0, 0x28, 0x0, 0x28, 0x0,  0x22, 0x0,  0x80,
                           0x0,  0x80, 0x1, 0x0,  0x1, 0x0,  0x0, 0x16, 0x10, 0x0,  0x0,  0x0};
s32 D_808022FC_bstnt[11] = {0x1D09D6, 0x150019,  0x4C0016,  0x1000001E, 0x1E001E, 0x190000,
                            0x22,     0x1000100, 0x4000400, 0x2B0100,   0x1000000};
s32 D_80802328_bstnt[40] = {
    0x1D09DC,  0x2CFFD8,  0x32FFD8, 0x280064,  0x280015, 0x140066, 0x20DEA7,  0x71500022,
    0x1000180, 0x2000300, 0x161000, 0x180000,  0x30000,  0x2B,     0x2CC03CC, 0x210000,
    0x0,       0xAFF9C,   0x280000, -0x63FFD8, 0x11A,    0x210000, 0x5A,      0xA0064,
    0x280000,  0x640028,  0x11A,    0x210000,  0xB4,     0xA0000,  0x28FF9C,  0x28,
    -0x63FEE6, 0x210000,  0x10E,    0xA0000,   0x280064, 0x28,     0x64011A,  0x0};
s32 D_808023C8_bstnt[12] = {0x210000, 0x78,    0x2B0480, 0x480002C, -0x27FFE2, -0x27FFD8,
                            0x3C0028, 0xAFFF6, 0xAFFF6,  0xA0019,   0xA031A,   0x0};
s32 D_808023F8_bstnt[4] = {(u32) func_8080092C_bstnt, (u32) func_80800960_bstnt,
                           (u32) func_80800998_bstnt, (u32) _bstnt_entrypoint_10};
s32 D_80802408_bstnt[4] = {(u32) func_80800CB0_bstnt, (u32) func_80800CD8_bstnt,
                           (u32) func_80800D08_bstnt, (u32) _bstnt_entrypoint_10};
s32 D_80802418_bstnt[21] = {0x1D0962, 0x160002,  0x150000,  0xB3001E,   0x1E001E,  0x2EFFA8,
                            0x2BC,    -0x57FE99, 0x2BC001B, -0x5DB05DC, 0x3040B,   0x36B00008,
                            0xE60119, 0x40099,   0x70004,   0x2B0266,   0x2660026, 0x38400C8,
                            0x384,    0xC80000,  0x0};
s32 D_8080246C_bstnt[19] = {0x1D0963, 0x160002,  0x150000,  0xB3001E,  0x1E001E,
                            0x2EFFAB, 0x28A,     -0x54FE99, 0x28A001B, -0x5DB05DC,
                            0x800E6,  0x1190004, 0x990007,  0x4002B,   0x2660266,
                            0x260384, 0xC80000,  0x38400C8, 0x0};
s32 D_808024B8_bstnt[19] = {0x1D0964, 0x160002,  0x150000,  0xB3001E,  0x1E001E,
                            0x2EFFB0, 0x258,     -0x4FFE99, 0x258001B, -0x5DB05DC,
                            0x800E6,  0x1190004, 0x990007,  0x4002B,   0x2660266,
                            0x260384, 0xC80000,  0x38400C8, 0x0};
s32 D_80802504_bstnt[18] = {0x1D0961, 0xB001E,   0x320050,  0x1E0015,   0xB3,     0x2EFFC4,
                            0xC8,     -0x27FE99, 0x190001B, -0x5DB05DC, 0x40099,  0x70003,
                            0x2B0200, 0x2800026, -0xC700C8, -0xC7FF38,  0xC800C8, 0x0};
s32 D_8080254C_bstnt[4] = {(u32) func_80801058_bstnt, (u32) func_80801080_bstnt,
                           (u32) func_80801190_bstnt, (u32) _basudie_entrypoint_11};
s32 D_8080255C_bstnt[4] = {(u32) func_8080121C_bstnt, (u32) func_808011CC_bstnt,
                           (u32) func_808011F4_bstnt, (u32) _bsdrone_entrypoint_3};
s32 D_8080256C_bstnt[4] = {(u32) func_80801464_bstnt, (u32) func_80801258_bstnt,
                           (u32) func_808012F8_bstnt, (u32) _bstnt_entrypoint_10};
s32 D_8080257C_bstnt[4] = {(u32) func_808018D0_bstnt, (u32) func_8080150C_bstnt,
                           (u32) func_8080166C_bstnt, (u32) _bstnt_entrypoint_10};
s32 D_8080258C_bstnt[4] = {(u32) func_80801E20_bstnt, (u32) func_80801C0C_bstnt,
                           (u32) func_80801C3C_bstnt, (u32) _bstnt_entrypoint_10};
s32 D_8080259C_bstnt[4] = {(u32) func_80801F20_bstnt, (u32) func_80801E60_bstnt,
                           (u32) func_80801EA0_bstnt, (u32) func_80099AA8};
s32 D_808025AC_bstnt[4] = {(u32) func_80802000_bstnt, (u32) func_80801F5C_bstnt,
                           (u32) func_80801F9C_bstnt, (u32) func_80099AA8};
s32 D_808025BC_bstnt[4] = {(u32) func_8080203C_bstnt, (u32) func_80802064_bstnt,
                           (u32) func_8080208C_bstnt, (u32) _bstnt_entrypoint_10};
s32 D_808025CC_bstnt[5] = {(u32) func_808020EC_bstnt, (u32) func_80802114_bstnt,
                           (u32) func_8080217C_bstnt, (u32) _bstnt_entrypoint_10, 0x0};
