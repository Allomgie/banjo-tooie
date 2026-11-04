// Probably a grab-bag of player-state helpers: input-driven state selection, a combined mode
// setup helper, push-out-of-volume routines, effect spawns at the player, and the return warp.

#include "core2/1E78BF0.h"
#include "common.h"

extern void func_8009C128(PlayerState *, f32 *);
extern void *func_800A4C48(PlayerState *);
extern void func_800CA7E4(void *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern void func_800A30B4(PlayerState *, f32 *, f32 *);
extern void func_800F4200(PlayerState *, f32 *);
extern void func_800F4648(PlayerState *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F0DC0(f32, f32);
extern s32 func_800F1660(f32, f32);
extern void func_80019CD4(void);
extern void func_8001980C(f32 *, f32 *, f32, s32);
extern void func_80019750(f32 *, f32 *, f32, s32);
extern void func_800193C4(f32 *, f32 *);
extern void func_800A3148(s32, f32 *, f32 *, f32 *);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800EF368(f32 *, f32);
extern void func_800A3200(s32, f32 *, f32 *);
extern f32 func_800964DC(PlayerState *);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern s32 func_800966E0(PlayerState *);
extern void _fxripple_entrypoint_1(s32, f32 *, s32);
extern u8 D_80119220[];
extern f32 func_800DC178(f32 a0, f32 a1);
extern void func_800BBCB8(f32 *a0, int a1, int a2, int a3, void *a4);
extern s32 func_80096544(PlayerState *);
extern void func_80092C24(PlayerState *, f32 *);
extern void func_80092C00(PlayerState *, f32 *);
extern void *_fxsplash_entrypoint_2(f32 *, f32);
extern void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
extern void func_800BA22C(void *, s32);
extern void func_8009BF5C(s32 param_0, f32 param_1);
extern void baroll_setIdeal(s32 param_0, f32 param_1);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern s32 func_800A3274(PlayerState *);
extern s32 player_isStable(PlayerState *);
extern BanjoStateId _badrone_entrypoint_28(PlayerState *);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 func_8009E674(PlayerState *, s32);
extern void baflag_clear(PlayerState *, s32);
extern void func_8009BFBC(PlayerState *);
extern void baroll_applyIdeal(PlayerState *);
extern s32 baflag_isFalse(PlayerState *, s32);
extern void _bsjig_entrypoint_4(PlayerState *);
extern void func_800FC660(s32);
s32 func_800A0064();
int func_800A055C();

// Group: common bs helpers (input-driven state selection, mode setup, look-at, death jingle).
s32 func_8009F300()
{
    return 0x4;
}

f32 func_8009F308(PlayerState *player)
{
    f32 player_pos[3];
    f32 other_pos[3];
    f32 unk_0;
    func_8009C128(player, player_pos);
    func_800CA7E4(func_800A4C48(player), other_pos);
    func_800F1E6C(player_pos, other_pos, &unk_0);
    return unk_0;
}

int func_8009F354(Actor *player)
{
    s32 state;
    if (baflag_isTrue(player, 0xF)) {
        return 0;
    }
    baflag_set(player, 0xF);
    state = _badata_entrypoint_24(player);
    if (bs_getCurrentState(player) != state) {
        return state;
    }
    return 0;
}

// Time until a vertical trajectory has fallen to target_height (60 Hz steps).
f32 func_8009F3BC(PlayerState *player, f32 height, f32 target_height, f32 velocity, f32 accel)
{
    f32 time = 0.0f;
    f32 vel = velocity;
    while (0.0f < vel || target_height < height) {
        time += 0.01666666754f;
        height += vel * 0.01666666754f;
        vel += accel * 0.01666666754f;
    }
    return time;
}

// Group: push the player out of solid actor volumes (rotated box, box, cylinder, sphere).
// Pushes the player out of a rotated box; returns 1 if pushed.
s32 func_8009F440(PlayerState *player, f32 *box_pos, f32 *box_rot, f32 *box_min, f32 *box_max,
                  f32 push_speed)
{
    f32 local_pos[3];
    f32 player_pos[3];
    f32 player_max[3];
    f32 player_min[3];
    f32 push[3];
    f32 gap_min, gap_max, step, overlap_x, overlap_z;
    func_800A30B4(player, player_min, player_max);
    func_800F4200(player, player_pos);
    func_80019CD4();
    func_8001980C(box_pos, box_rot, 1.0f, 0);
    func_800193C4(local_pos, player_pos);
    func_800EF04C(player_min, local_pos);
    func_800EF04C(player_max, local_pos);
    if (player_max[1] <= box_min[1] || box_max[1] <= player_min[1])
        return 0;
    gap_max = box_max[0] - player_min[0];
    gap_min = box_min[0] - player_max[0];
    if (0.0f <= gap_min || gap_max <= 0.0f)
        return 0;
    overlap_x = gap_max < -gap_min ? gap_max : gap_min;
    gap_max = box_max[2] - player_min[2];
    gap_min = box_min[2] - player_max[2];
    if (0.0f <= gap_min || gap_max <= 0.0f)
        return 0;
    overlap_z = gap_max < -gap_min ? gap_max : gap_min;
    step = func_800D8FF8() * push_speed;
    if (func_800F1660(overlap_x, overlap_z)) {
        func_800EFA4C(push, 0.0f, 0.0f, func_800F0DC0(overlap_z, step));
    } else {
        func_800EFA4C(push, func_800F0DC0(overlap_x, step), 0.0f, 0.0f);
    }
    func_800EF04C(local_pos, push);
    func_80019CD4();
    func_80019750(box_pos, box_rot, 1.0f, 0);
    func_800193C4(player_pos, local_pos);
    func_800F4648(player, player_pos);
    return 1;
}

// Pushes the player out of an unrotated box; returns 1 if pushed.
s32 func_8009F678(PlayerState *player, f32 *box_min, f32 *box_max, f32 push_speed)
{
    f32 player_pos[3];
    f32 player_max[3];
    f32 player_min[3];
    f32 push[3];
    f32 gap_min, gap_max, step, overlap_x, overlap_z;
    func_800A30B4(player, player_min, player_max);
    func_800F4200(player, player_pos);
    func_800EF04C(player_min, player_pos);
    func_800EF04C(player_max, player_pos);
    if (player_max[1] <= box_min[1] || box_max[1] <= player_min[1])
        return 0;
    gap_max = box_max[0] - player_min[0];
    gap_min = box_min[0] - player_max[0];
    if (0.0f <= gap_min || gap_max <= 0.0f)
        return 0;
    overlap_x = gap_max < -gap_min ? gap_max : gap_min;
    gap_max = box_max[2] - player_min[2];
    gap_min = box_min[2] - player_max[2];
    if (0.0f <= gap_min || gap_max <= 0.0f)
        return 0;
    overlap_z = gap_max < -gap_min ? gap_max : gap_min;
    step = func_800D8FF8() * push_speed;
    if (func_800F1660(overlap_x, overlap_z)) {
        func_800EFA4C(push, 0.0f, 0.0f, func_800F0DC0(overlap_z, step));
    } else {
        func_800EFA4C(push, func_800F0DC0(overlap_x, step), 0.0f, 0.0f);
    }
    func_800EF04C(player_pos, push);
    func_800F4648(player, player_pos);
    return 1;
}

// Pushes the player out of a cylinder; returns 1 if pushed.
s32 func_8009F860(s32 player, f32 *center, f32 top, f32 bottom, f32 radius, f32 push_speed)
{
    f32 reach;
    f32 dist;
    f32 unk_0;
    f32 push;
    f32 player_radius;
    f32 player_y_offset;
    f32 half_height;
    f32 player_pos[3];
    f32 offset[3];
    s32 unk_1[2];
    func_800A3148(player, &player_radius, &player_y_offset, &half_height);
    func_800F4200(player, player_pos);
    half_height *= 0.5f;
    if ((player_pos[1] + player_y_offset) + half_height < center[1] + bottom)
        return 0;
    if (center[1] + top < (player_pos[1] + player_y_offset) - half_height)
        return 0;
    func_800EFA4C(offset, player_pos[0] - center[0], 0.0f, player_pos[2] - center[2]);
    dist = offset[0] * offset[0] + offset[1] * offset[1] + offset[2] * offset[2];
    reach = radius + player_radius;
    if (reach * reach < dist)
        return 0;
    dist = sqrtf(dist);
    push = func_800F13F0(func_800D8FF8() * push_speed, reach - dist);
    if (dist == 0.0f) {
        dist = func_800DC0C0();
        func_800EFA4C(offset, dist, 0.0f, func_800DC0C0());
    }
    func_800EF368(offset, push);
    func_800EF04C(player_pos, offset);
    func_800F4648(player, player_pos);
    return 1;
}

// Pushes the player out of a sphere; returns 1 if pushed.
s32 func_8009FA20(s32 player, f32 *center, f32 y_offset, f32 radius, f32 push_speed)
{
    f32 reach;
    f32 dist;
    f32 unk_0;
    f32 push;
    f32 player_radius;
    f32 player_y_offset;
    f32 player_pos[3];
    f32 offset[3];
    f32 sphere_pos[3];
    f32 rand_y[2];
    func_800EFA4C(sphere_pos, center[0], center[1] + y_offset, center[2]);
    func_800A3200(player, &player_radius, &player_y_offset);
    func_800F4200(player, player_pos);
    func_800EFA4C(offset, player_pos[0] - sphere_pos[0], player_pos[1] + player_y_offset - sphere_pos[1],
                  player_pos[2] - sphere_pos[2]);
    dist = offset[0] * offset[0] + offset[1] * offset[1] + offset[2] * offset[2];
    reach = radius + player_radius;
    if (reach * reach < dist)
        return 0;
    dist = sqrtf(dist);
    push = func_800F13F0(func_800D8FF8() * push_speed, reach - dist);
    if (dist == 0.0f) {
        dist = func_800DC0C0();
        rand_y[0] = func_800DC0C0();
        func_800EFA4C(offset, dist, rand_y[0], func_800DC0C0());
    }
    func_800EF368(offset, push);
    func_800EF04C(player_pos, offset);
    func_800F4648(player, player_pos);
    return 1;
}

// Group: spawn air bubbles, ripples, sparkles and splashes at the player.
// Spawns an air bubble.
s32 func_8009FBB0(PlayerState *player, f32 pos[3], f32 unk_0)
{
    return _fxairbub_entrypoint_1(pos, unk_0, func_800964DC(player), 1.0f);
}

int func_8009FBE8(s32 player, s32 unk_0)
{
    f32 player_pos[3];
    f32 other_pos[3];
    func_8009C128(player, player_pos);
    func_800CA7E4(func_800A4C48(player), other_pos);
    func_800EFB24(unk_0, other_pos, player_pos);
}

// Spawns a ripple at the player.
void func_8009FC34(PlayerState *player, s32 unk_0)
{
    f32 pos[3];
    func_8009C128(player, pos);
    pos[1] = func_800964DC(player);
    _fxripple_entrypoint_1(unk_0, pos, func_800966E0(player));
}

// Spawns a sparkle at a random offset around the player.
int func_8009FC80(int player)
{
    f32 pos[3];
    func_8009C128(player, &pos[0]);
    pos[0] += func_800DC178(-30.0f, 30.0f);
    pos[1] += func_800DC178(95.0f, 105.0f);
    pos[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(&pos[0], 0, 0x3F800000, 1, D_80119220);
}

// Spawns a splash at the player if in water.
void func_8009FD24(PlayerState *player, s32 unk_0)
{
    f32 pos[3];
    f32 yaw;
    void *splash;
    if (func_80096544(player)) {
        if (unk_0)
            func_80092C24(player, pos);
        else
            func_80092C00(player, pos);
        pos[1] = func_800964DC(player);
        yaw = yaw_get(player);
        splash = _fxsplash_entrypoint_2(pos, 8.0f);
        func_800BA994(splash, -140, yaw - 35.0f, 200, -120, yaw + 35.0f, 250);
        func_800BA22C(splash, 3);
        func_800BA994(splash, -100, yaw - 35.0f, 300, -90, yaw + 35.0f, 400);
        func_800BA22C(splash, 2);
    }
}

void func_8009FE58(PlayerState *player)
{
    func_800A2E18(player);
}

void func_8009FE78(u8 *player)
{
    **(s32 **) ((s8 *) player + 0x12C) = 0;
}

BanjoStateId bs_getTypeOfJump(PlayerState *self)
{
    if (bakey_held(self, 1) && func_8008D370(self)) {
        return 0x12;
    }
    if (baflag_isTrue(self, 2)) {
        return 0x05;
    }
    if (func_8008D3B0(self)) {
        return 0x23;
    }
    return 0x05;
}

// Matching: the extra copy of the callback pointer is needed for the match.
void func_8009FF00(s32 player)
{
    s32 (*callback)(s32, f32);
    s32 (*callback_copy)(s32, f32);

    callback = _badata_entrypoint_28();
    if (callback != NULL) {
        callback_copy = callback;
        callback_copy(player, func_8009BB5C(player));
    }
}

// Starts anim_id unless it is already playing.
int func_8009FF44(PlayerState *player, enum asset_e anim_id, f32 param_2, f32 param_3, f32 param_4,
                  f32 param_5)
{
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (anctrl_getIndex(anim_ctrl) != anim_id) {
        anctrl_setIndex(anim_ctrl, anim_id);
        anctrl_start(anim_ctrl);
    }
    func_8008CA4C(player, 2);
    baanim_setDurationRange(player, 0.234500006f, 3.98760009f);
    func_8008C9F0(player, param_2, param_3, param_4, param_5);
}

// Sets anim update type, yaw update type, turn mode and physics type in one call.
void func_8009FFD8(PlayerState *player, BaAnimUpdateType anim_update_type, YawType yaw_type, s32 turn_mode, BaPhysicsType physics_type)
{
    func_8008CA4C(player, anim_update_type);
    yaw_setUpdateType(player, yaw_type);
    func_8009D2D8(player, turn_mode);
    baphysics_set_type(player, physics_type);
}

// Turns toward the target of the top lock request, if it has one.
int func_800A0024(s32 player)
{
    f32 target_pos[3];
    if (func_8009CC68(player) && func_8009CC18(player, target_pos)) {
        func_800A0064(player, target_pos);
    }
}

s32 func_800A0064(player, target)
s32 player;
s32 target;
{
    f32 player_pos[3];
    f32 angles[3];

    func_8009C128(player, player_pos);
    func_800F18FC(player_pos, target, angles);
    func_8009BF5C(player, -angles[0]);
    yaw_setIdeal(player, angles[1]);
    baroll_setIdeal(player, 0);
}

s32 func_800A00CC(PlayerState *player, f32 target[3])
{
    f32 player_pos[3];
    f32 angles[3];
    func_8009C128(player, player_pos);
    func_800F18FC(player_pos, target, angles);
    yaw_setIdeal(player, angles[1]);
}

void func_800A0110(s32 player, s32 anim_ctrl)
{
    f32 duration;
    s32 anim_id;

    _badata_entrypoint_3(player, &anim_id, &duration);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
}

int func_800A0150(s32 music_id)
{
    func_800FC240(0, 0xFA0);
    func_800FC660(music_id);
}

// Death music trigger.
void func_800A0180(PlayerState *player)
{
    s32 music_id = _badata_entrypoint_16(player);

if (func_800D395C() != 0) {
    if (func_800FCCD4(music_id) == 0) {
        func_800A0150(music_id);
    }
} else if (baflag_isTrue(player, 0x41) == 0) {

baflag_set(player, 0x41);
func_800A0150(music_id);
func_800FE4E4();
}
}

// Picks the next state from input: jump, attack, beak barge, first person.
BanjoStateId func_800A01F8(PlayerState *player, BanjoStateId state)
{
    if (baflag_isTrue(player, 0xF)) {
        return state;
    }
    if (bakey_pressed(player, 8)) {
        state = bs_getTypeOfJump(player);
    }
    if (bakey_pressed(player, 9)) {
        state = func_800A055C(player, state);
    }
    if (bakey_held(player, 1) && bainput_should_beak_barge(player)) {
        state = 0x13;
    }
    if (bainput_should_enter_first_person(player)) {
        state = _badrone_entrypoint_24(player);
    }
    if (func_8008E148(player)) {
        state = _badrone_entrypoint_25(player);
    }
    return state;
}

BanjoStateId func_800A02DC(PlayerState *player, BanjoStateId state)
{
    s32 transform;
    transform = func_800A3274(player);
    if (!player_isStable(player))
        return state;
    if (baflag_isTrue(player, 0x19))
        state = _badrone_entrypoint_28(player);
    if (baflag_isTrue(player, 0x1A))
        state = 0x34;
    if (baflag_isTrue(player, 0xE))
        state = transform == 0xB ? 0x47 : 0x25;
    if (baflag_isTrue(player, 0x10) || baflag_isTrue(player, 0x37) ||
        baflag_isTrue(player, 0x38)) {
        if (transform != 0xB && !func_8009E674(player, 0x40))
            state = 0x14;
    }
    if (baflag_isTrue(player, 6))
        state = 0x53;
    if (baflag_isTrue(player, 7))
        state = 0x44;
    if (baflag_isTrue(player, 0x14))
        state = 0x53;
    baflag_clear(player, 0xF);
    return state;
}

void func_800A042C(PlayerState *player)
{
    func_8009BF5C(player, 0.0f);
    func_8009BFBC(player);
    baroll_setIdeal(player, 0.0f);
    baroll_applyIdeal(player);
}

void func_800A046C(PlayerState *player)
{
    if (baflag_isFalse(player, 7) != 0) {
        return;
    }

if (baflag_isTrue(player, 0xF) && baflag_isFalse(player, 6) && baflag_isFalse(player, 0x14)) {
    baflag_clear(player, 0xF);
}

baflag_clear(player, 7);
_bsjig_entrypoint_4(player);
func_800FC660(5);
}

int func_800A04F4(s32 player, s32 state)
{
    // Matching: the zero temporary and the empty block below are needed for the match.
    int zero;
    zero = 0;

if (func_8008E23C(player)) {
    if (func_8008D568(player) != zero) {
        return 0xE4;
    }
    return state;
}
{
    if (!player) {
    }
    if (func_8008D694() != zero) {
        return 0x31;
    }
    return state;
}

}

int func_800A055C(player, state)
s32 player;
s32 state;
{
    // Matching: empty block, needed for the match.
    if (player) {
    }

if (func_8008E23C(player)) {
    if (func_8008D568(player) != 0) {
        return 0xE4;
    }
    return state;
}

if (func_8008D1B0() != 0) {
    if (func_8009EA2C()) {
        return 0x18A;
    }
    return 6;
}

return state;
}

// Group: warp the player to the stored return map and entrance.
// Warps to the stored return point.
void func_800A05DC(s32 player)
{
    s16 unk_0;
    s16 unk_1;
    s16 map;
    s16 exit;
    s16 unk_2;
    s32 unk_3;
    s32 unk_4;
    s32 unk_5;

    unk_0 = 0;
    unk_1 = 0;
    func_800F9110(1);

if (func_800A9C98() != 0) {
    func_800A9CDC();
    return;
}

if (func_8008E23C(player) != 0) {
    func_800F8F3C();
    if (func_800F8DA8(0xA) != 0) {
        unk_5 = 0xA;
    } else {
        unk_5 = 0xB;
    }
    unk_3 = unk_5;
    unk_0 = func_800F89E4(unk_5, &unk_4);
    if (func_800EA05C() != unk_0) {
        unk_2 = func_800F8A80(unk_3);
    } else {
        unk_2 = func_800EA090(unk_3);
    }
    unk_1 = unk_2;
}

if (unk_0 != 0) {
    func_8009EB24(unk_0, unk_1);
}

func_8009EC08(&map, &exit);

if (unk_0 != 0) {
    func_8009EBD0();
}

func_800A794C(map, exit, 1);
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E78BF0.data.s) is defined here in C;
// values are taken from the ROM.
u8 D_80119220[48] = {0x0, 0x1D, 0x9, 0xE1, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x22,
                     0x0, 0x66, 0x0, 0x59, 0x0, 0x19, 0x0, 0x19, 0x0, 0x27, 0x1, 0x90,
                     0x1, 0x90, 0x3, 0x20, 0x3, 0x20, 0x0, 0x2B, 0x0, 0x80, 0x0, 0x80,
                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
