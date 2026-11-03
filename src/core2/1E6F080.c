// TU-NOTE: 0x1E6F080..0x1E71260 is two objects. This one ends with func_8009679C; the second
// (1E700B0) starts at func_800967C0. The .rodata gap after the func_80095C94 jump table marks the
// boundary, since IDO aligns each object's .rodata to 16 bytes.
#include "core2/1E6F080.h"
#include "types.h"
#include "macros.h"

#define LOCAL_COLLISION(p) (*(LocalCollision **) ((u8 *) (p) + 0x94))
extern f32 func_800985B8(void);
extern f32 func_8009864C();
extern void func_80098590();
extern void func_800F1E6C(void *, f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 yaw_get();
extern void yaw_setIdeal(void *, f32);
extern void yaw_applyIdeal();
void func_800C68A0(s32 param_0, f32 param_1);
struct UnkStruct {
    char pad_0[0x50];
    s32 unk_50;
};
extern s32 func_800C5BA4(s32);
extern f32 func_800F13F0(f32, f32);
typedef struct {
    void *floor;
    f32 radius, height;
    u8 pad_0C[12];
    u8 prev_stable;
    u8 pad_19[3];
    void *triangle;
    u8 pad_20[0x30];
    Actor *stood_actor;
    u8 hit, unk_55, stable, pad_57;
    f32 sweep_delta[3];
    f32 target_radius, target_height;
    u8 triangle_copy[12];
    f32 position[3];
    f32 prev_position[3];
    f32 frame_delta[3];
    s32 mode;
    u8 below_water, clamped, restore, hit_count, active;
} LocalCollision;
extern s32 func_80091E80(PlayerState *, s32);
extern s32 func_8008E454(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_8009C15C(PlayerState *, f32 *);
extern void func_8009C0F8(PlayerState *, f32 *);
extern s32 func_800BEAAC(f32 *, f32 *);
extern void func_800C68E8(void *, s32, f32);
extern void func_800CB840(s32, s32);
extern void func_800CB870(void);
extern s32 func_800C670C(void *);
extern f32 func_800A0E58(PlayerState *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800D4584(LocalCollision *, f32 *, f32 *, f32 *);
extern void _bahitspline_entrypoint_2(PlayerState *);
extern s32 func_800F1418(s32, s32);
extern void func_800FB508(void *, void *);
extern void func_8010114C(Actor *, s32, s32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void baflag_clear(PlayerState *, s32);
extern s32 player_isStable(PlayerState *);
extern void _bahitspline_entrypoint_0(void);
extern void _bahitspline_entrypoint_1(PlayerState *, s32);
f32 func_8009C150(void);
f32 func_800C6784(s32);
f32 func_800C67D8(s32);
f32 func_800F0E00(f32, f32);
extern void func_800C675C(s32, f32 *);
extern void func_80013A7C(f32);
struct unk_struct_94 {
    u8 pad_0[0x50];
    s32 *unk_50;
    u8 pad_54[0x40];
    struct unk_struct_94 *unk_94;
};
extern void func_800EE7F8(f32 *, f32 *);
extern void *func_800C6C94(f32 *, f32, f32 *, u32);
void func_80095A08();
int func_80096254();
void func_80096260();
s32 func_80096530();
int func_80096768();
void func_80097858();
void func_8009788C();
void func_800978A4();

s32 func_80095790()
{
    return 0xAC;
}

// Mode 5 (climbing): clamp the collision Y to the climb range and update yaw.
void func_80095798(u8 *player)
{
    f32 dir[3];
    f32 min_y;
    f32 max_y;
    f32 target_yaw;
    min_y = func_800985B8();
    max_y = func_8009864C(player);
    if (max_y < *(f32 *) (*(u8 **) (player + 0x94) + 0x7C)) {
        *(f32 *) (*(u8 **) (player + 0x94) + 0x7C) = max_y;
    }
    if (*(f32 *) (*(u8 **) (player + 0x94) + 0x7C) < min_y) {
        *(f32 *) (*(u8 **) (player + 0x94) + 0x7C) = min_y;
    }
    func_80098590(player, dir);
    func_800F1E6C(*(u8 **) (player + 0x94) + 0x78, dir, &target_yaw);
    if (mlAbsF(func_800F1DCC(target_yaw, yaw_get(player))) > 1.0f) {
        yaw_setIdeal(player, target_yaw);
        yaw_applyIdeal(player);
    }
}

void func_80095870(u8 *player, f32 *out_radius, f32 *out_height)
{
    *out_radius = (*(f32 **) (player + 0x94))[1];
    *out_height = (*(f32 **) (player + 0x94))[2];
}

s32 func_8009588C(u8 *player)
{
    return *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x94) + 0x14);
}

s32 func_80095898(void *player)
{
    return ((u8 *) *(void **) ((char *) player + 0x94))[162];
}

int func_800958A4(Actor *player, f32 y_offset, f32 unk_0)
{
    f32 pos[4];
    f32 out[3];
    s32 result;
    func_8009C128(player, pos);
    pos[1] += y_offset;
    if (func_800C6C94(pos, unk_0, out, (*(s32 **) ((u8 *) player + 0x94))[5]) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void func_8009590C(s32 *player, f32 unk_0)
{
    if (unk_0 == 0.0f) {
        func_800C68A0(*(s32 *) player[0x25], 56.0f);
    } else {
        func_800C68A0(*(s32 *) player[0x25], unk_0);
    }
}

s32 func_80095964(Actor *player, s32 enable)
{
    if (enable) {
        func_80095A08(player, 8, 1);
        func_80095A08(player, 4, 0);
    } else {
        func_80095A08(player, 8, 0);
        func_80095A08(player, 4, 1);
    }
}

// Set the target and current radius/height.
void func_800959C8(PlayerState *player, f32 radius, f32 height)
{
    f32 *collision;
    // Matching: the temporary pointer is needed for the match.
    *(f32 *) ((u8 *) ((u8 **) player)[37] + 0x64) = radius;
    collision = (f32 *) ((u8 **) player)[37];
    *(f32 *) ((char *) collision + 4) = *(f32 *) ((u8 *) collision + 0x64);
    *(f32 *) ((u8 *) ((u8 **) player)[37] + 0x68) = height;
    collision = (f32 *) ((u8 **) player)[37];
    *(f32 *) ((char *) collision + 8) = *(f32 *) ((u8 *) collision + 0x68);
}

func_800959FC(s32 player, s32 flags)
{
    *(s32 *) (*(s32 *) (player + 0x94) + 0x14) = flags;
}

void func_80095A08(player, mask, enable) PlayerState *player;
s32 mask;
s32 enable;
{
    if (enable != 0) {
        *(s32 *) (*(u8 **) ((u8 *) player + 0x94) + 0x14) |= mask;
    } else {
        *(s32 *) ((*(u8 **) ((u8 *) player + 0x94)) + 0x14) &= ~mask;
    }
}

// Reset radius/height to the defaults (80, 35).
// Matching: the cast and the extra temporaries are needed for the match.
void func_80095A40(PlayerState *player)
{
    float radius;
    PlayerState *state;
    state = player;
    func_800959C8(state, radius = (unsigned long) 80.0f, 35.0f);
}

func_80095A64(void *collision)
{
    ((struct UnkStruct *) collision)->unk_50 = 0;
}

int func_80095A6C(s32 actor, s32 *collision)
{
    collision[20] = actor;
}

void func_80095A74(s32 player, s32 enable)
{
    if (func_800EA05C() == 0xB8) {
        if (enable != 0) {
            func_80095A08(player, 8, 1);
        }

        else {
            func_80095A08(player, 8, 0);
        }
    }
}

// Initialize the collision component.
void func_80095AD0(u8 *player)
{
    u8 zero;

    *(u8 *) (*(u8 **) (player + 0x94) + 0xa3) = 0;
    // Matching: the zero is reloaded from the stored field and reused.
    zero = *(u8 *) (*(u8 **) (player + 0x94) + 0xa3);
    *(u8 *) (*(u8 **) (player + 0x94) + 0x54) = zero;
    *(u8 *) (*(u8 **) (player + 0x94) + 0xa1) = zero;
    *(u8 *) (*(u8 **) (player + 0x94) + 0x18) = zero;
    *(u8 *) (*(u8 **) (player + 0x94) + 0x56) = zero;
    *(u8 *) (*(u8 **) (player + 0x94) + 0xa0) = zero;
    func_800959FC(player, 0x400005);
    *(s32 *) (*(u8 **) (player + 0x94)) = func_800C5A38();
    func_800EFD24(*(u8 **) (player + 0x94) + 0x90);
    func_800EFD24(*(u8 **) (player + 0x94) + 0x78);
    func_800EFD24(*(u8 **) (player + 0x94) + 0x84);
    func_800EFD24(*(u8 **) (player + 0x94) + 0x44);
    *(s32 *) (*(u8 **) (player + 0x94) + 0x1c) = 0;
    *(u8 *) (*(u8 **) (player + 0x94) + 0xa2) = 0;
    func_80095A40(player);
    *(f32 *) (*(u8 **) (player + 0x94) + 4) = *(f32 *) (*(u8 **) (player + 0x94) + 0x64);
    *(f32 *) (*(u8 **) (player + 0x94) + 8) = *(f32 *) (*(u8 **) (player + 0x94) + 0x68);
    func_80096254(player, 1);
    func_8009590C(player, 0);
    *(s32 *) (*(u8 **) (player + 0x94) + 0x9c) = 0;
    func_800961AC(player, 1);
    baflag_clear(player, 1);
    baflag_clear(player, 2);
    *(void (**)(s32, void *))(*(u8 **) (player + 0x94) + 0xc) = func_80095A6C;
    *(void (**)(void *))(*(u8 **) (player + 0x94) + 0x10) = func_80095A64;
    *(u8 *) (*(u8 **) (player + 0x94) + 0xa4) = 0;
}

s32 func_80095C10(s32 player)
{
    return func_800C5BA4(*(s32 *) (*(s32 *) (player + 0x94)));
}

// Move current toward target by at most step.
f32 func_80095C34(f32 target, f32 current, f32 step)
{
    if (current < target)
        current = func_800F13F0(target, current + step);
    else if (target < current)
        current = func_800F0E00(target, current - step);
    return current;
}

// Per-frame update: sweep the player against the world, derive the medium, notify the stood-on actor.
void func_80095C94(PlayerState *player)
{
    f32 saved_pos[3];
    f32 pos[3];
    f32 prev_pos[3];
    f32 unk_0;
    f32 water_level;

    LOCAL_COLLISION(player)->active = 1;
    LOCAL_COLLISION(player)->stood_actor = NULL;
    if (!func_80091E80(player, 4))
        return;
    if (!func_8008E454(player))
        return;

    func_8009C128(player, saved_pos);
    if (func_800BEAAC(saved_pos, &unk_0)) {
        func_800C68E8(LOCAL_COLLISION(player)->floor, 1, unk_0);
    } else {
        func_800C68E8(LOCAL_COLLISION(player)->floor, 0, unk_0);
    }
    LOCAL_COLLISION(player)->clamped = 0;
    LOCAL_COLLISION(player)->hit = 0;
    LOCAL_COLLISION(player)->unk_55 = 0;
    LOCAL_COLLISION(player)->triangle = NULL;
    LOCAL_COLLISION(player)->prev_stable = LOCAL_COLLISION(player)->stable;
    func_800CB840(1, player->unk184);
    LOCAL_COLLISION(player)->radius =
        func_80095C34(LOCAL_COLLISION(player)->target_radius, LOCAL_COLLISION(player)->radius, 1.0f);
    LOCAL_COLLISION(player)->height =
        func_80095C34(LOCAL_COLLISION(player)->target_height, LOCAL_COLLISION(player)->height, 1.0f);

    // Dispatch on collision mode.
    switch (LOCAL_COLLISION(player)->mode) {
        // Normal sweep (modes 1, 3, 4, 9); mode 3 also clamps below the water surface.
        case 1:
        case 3:
        case 4:
        case 9:
            func_8009C128(player, LOCAL_COLLISION(player)->position);
            func_8009C15C(player, LOCAL_COLLISION(player)->prev_position);

            if (LOCAL_COLLISION(player)->mode == 3) {
                void *floor_info = LOCAL_COLLISION(player)->floor;
                if (func_800C670C(floor_info)) {
                    f32 water_y = func_800C67D8(floor_info);
                    f32 offset = func_800A0E58(player);
                    if (water_y - offset < LOCAL_COLLISION(player)->position[1]) {
                        LOCAL_COLLISION(player)->position[1] = water_y - offset;
                        LOCAL_COLLISION(player)->clamped = 1;
                        baphysics_set_vertical_velocity(player, 1.0f);
                    }
                }
            }

            func_800EFB24(LOCAL_COLLISION(player)->sweep_delta, LOCAL_COLLISION(player)->position,
                          LOCAL_COLLISION(player)->prev_position);
            func_800D4584(LOCAL_COLLISION(player), LOCAL_COLLISION(player)->prev_position,
                          LOCAL_COLLISION(player)->position, LOCAL_COLLISION(player)->sweep_delta);
            func_8009C0F8(player, LOCAL_COLLISION(player)->position);
            break;
        // Climbing clamp.
        case 5:
            func_8009C128(player, LOCAL_COLLISION(player)->position);
            func_8009C15C(player, LOCAL_COLLISION(player)->prev_position);
            func_800EFB24(LOCAL_COLLISION(player)->sweep_delta, LOCAL_COLLISION(player)->position,
                          LOCAL_COLLISION(player)->prev_position);
            func_800D4584(LOCAL_COLLISION(player), LOCAL_COLLISION(player)->prev_position,
                          LOCAL_COLLISION(player)->position, LOCAL_COLLISION(player)->sweep_delta);
            func_80095798(player);
            func_8009C0F8(player, LOCAL_COLLISION(player)->position);
            break;
        // Ledge.
        case 7:
            func_800978A4(player);
            break;
        // Alternate.
        case 8:
            func_80096768(player);
            break;
        // Hit spline (falls through to clear the hit flags).
        case 10:
            _bahitspline_entrypoint_2(player);
        case 2:
        case 6:
            LOCAL_COLLISION(player)->hit = 0;
            LOCAL_COLLISION(player)->unk_55 = 0;
            LOCAL_COLLISION(player)->stable = 0;
    }
    if (func_800C670C(LOCAL_COLLISION(player)->floor)) {
        water_level = func_800C67D8(LOCAL_COLLISION(player)->floor);
        LOCAL_COLLISION(player)->below_water = LOCAL_COLLISION(player)->position[1] < water_level;
    }
    if (func_80096530(player))
        LOCAL_COLLISION(player)->stable = 1;
    if (LOCAL_COLLISION(player)->below_water &&
        LOCAL_COLLISION(player)->position[1] <
            func_800C67D8(LOCAL_COLLISION(player)->floor) - func_800A0E58(player)) {
        func_80096254(player, 3);

        if (LOCAL_COLLISION(player)->stable && baphysics_get_vertical_velocity(player) < 0.0f) {
            baphysics_set_vertical_velocity(player, -1.0f);
        }

    } else if (LOCAL_COLLISION(player)->stable) {
        func_80096260(player);

        if (baphysics_get_vertical_velocity(player) < 0.0f) {
            if (!(func_80096628(player) & 0x8000))
                baphysics_set_vertical_velocity(player, -1.0f);
        }

    } else {
        func_80096254(player, 1);
    }
    if (LOCAL_COLLISION(player)->restore)
        func_8009C0F8(player, saved_pos);
    func_800CB870();
    if (LOCAL_COLLISION(player)->hit) {
        LOCAL_COLLISION(player)->hit_count = func_800F1418(LOCAL_COLLISION(player)->hit_count + 1, 3);
    } else {
        LOCAL_COLLISION(player)->hit_count = 0;
    }
    func_8009C15C(player, prev_pos);
    func_8009C128(player, pos);
    func_800EFB24(LOCAL_COLLISION(player)->frame_delta, pos, prev_pos);
    if (LOCAL_COLLISION(player)->triangle) {
        func_800FB508(LOCAL_COLLISION(player)->triangle_copy, LOCAL_COLLISION(player)->triangle);
        LOCAL_COLLISION(player)->triangle = LOCAL_COLLISION(player)->triangle_copy;
    }
    baflag_clear(player, 1);
    baflag_clear(player, 2);
    if (LOCAL_COLLISION(player)->stood_actor && player_isStable(player)) {
        func_8010114C(LOCAL_COLLISION(player)->stood_actor, 0x91, player->unk184);
    }
}

void func_800961A0(void *player, s32 restore)
{
    ((s8 *) (*(void **) ((char *) player + 0x94)))[162] = restore;
}

// Switch collision mode, running the leave/enter hooks for modes 7 and 10.
void func_800961AC(player, mode) PlayerState *player;
s32 mode;
{
    s32 old_mode;
    u8 *collision;
    collision = *((u8 **) (((char *) player) + 0x94));
    old_mode = *((s32 *) (((char *) collision) + 0x9C));
    switch (old_mode) {
        case 7:
            func_80097858();
            break;

        case 10:
            _bahitspline_entrypoint_0();
    }

    collision = *((u8 **) (((char *) player) + 0x94));

    *((s32 *) (((char *) collision) + 0x9C)) = mode;
    switch (mode) {
        case 7:
            func_8009788C(player, mode);
            return;

        case 10:
            _bahitspline_entrypoint_1(player, mode);
    }
}

// Set the medium: 1 air, 2 ground, 3 water, 4 surface type 0x18.
func_80096254(player, medium) s32 player;
s32 medium;
{
    *(s32 *) (*(s32 *) (player + 0x94) + 0xA8) = medium;
}

// Set the ground medium from the floor surface type.
void func_80096260(player) PlayerState *player;
{
    s32 surface;
    surface = func_80096628(player);
    if (func_800C84B0(surface) == 0x18) {
        func_80096254(player, 4);
        return;
    }
    func_80096254(player, 2);
}

void func_800962B0(PlayerState *player, s32 unk_0)
{
    func_800C68D4(*(*(PlayerState ***) ((u8 *) player + 0x94)), unk_0);
}

f32 func_800962D4(void *player)
{
    f32 player_y;
    player_y = func_8009C150();
    return player_y - func_800C6784(*(*(s32 **) ((s8 *) player + 0x94)));
}

// Matching: the empty block steers IDO's register allocation.
f32 func_8009630C(PlayerState *player)
{
    f32 player_y;
    f32 floor_y;
    f32 y;
    y = func_8009C150();
    if (y) {
    }
    player_y = y;
    floor_y = func_800C6784(*(*((s32 **) (((char *) player) + 0x94))));
    return player_y - func_800F0E00(floor_y, func_800C67D8(*(*((s32 **) (((char *) player) + 0x94)))));
}

f32 func_80096364(PlayerState *player)
{
    return func_800C6784(*(s32 *) (*(s32 **) ((u8 *) player + 0x94)));
}

s32 func_80096388(PlayerState *player)
{
    return *(s32 *) ((char *) (*(struct ba_unk_9C **) ((char *) player + 0x94)) + 156);
}

void func_80096394(u8 *player, s32 out)
{
    func_800EE7F8(out, *(u32 *) (player + 0x94) + 0x90);
}

void func_800963C0(PlayerState *player, f32 out[3])
{
    func_800C675C(*(s32 *) (*(s32 **) ((u8 *) player + 0x94)), out);
}

int func_800963E4(f32 player[3])
{
    f32 vec[3];
    func_800963C0(player, vec);
    func_80013A7C(vec[1]);
}

// Matching: the `* 0` comparison and the extra pointer are needed for the match.
s32 func_8009640C(u8 *player)
{
    s32 was_unstable;
    u8 *collision;
    u8 *prev_stable;
    collision = *((u8 **) (player + 0x94));
    was_unstable = (*(prev_stable = collision + 0x18)) == 0;
    if (was_unstable != (was_unstable * 0)) {
        return (*((u8 *) (collision + 0x56))) != 0;
    }
}

s32 func_80096434(PlayerState *player)
{
    return *(s32 *) ((char *) (*(struct ba_flag_s **) ((char *) player + 0x94)) + 0x74);
}

void func_80096440(PlayerState *player, f32 *out)
{
    func_800EE7F8(out, *(s32 *) ((char *) player + 0x94) + 0x44);
}

void func_8009646C(s32 *player, s32 out)
{
    s32 offset;
    s32 dst;

    offset = 0;
    dst = out;
    do {
        func_800EE7F8(dst, player[37] + offset + 0x20);
        offset += 0xC;
        dst += 0xC;
    } while (offset != 0x24);
}

// Current medium.
s32 func_800964D0(void *player)
{
    return ((s32 *) *(void **) ((char *) player + 0x94))[42];
}

f32 func_800964DC(PlayerState *player)
{
    return func_800C67D8(*(s32 *) *(s32 **) ((u8 *) player + 0x94));
}

s32 func_80096500(PlayerState *player)
{
    return *((char *) *(s32 *) ((char *) player + 0x94) + 0xA1);
}

s32 func_8009650C(PlayerState *player)
{
    return *((char *) *(s32 *) ((char *) player + 0x94) + 0x55);
}

s32 func_80096518(void *player)
{
    return ((u8 *) *(void **) ((char *) player + 0x94))[86];
}

u8 func_80096524(u8 *player)
{
    return ((u8 **) player)[37][0xA0];
}

// True once the hit count has saturated at 3.
// Matching: the no-op mask is needed for the match.
s32 func_80096530(player)
struct SomeStruct *player;
{
    u8 *collision;
    collision = *(s32 *) ((char *) player + 0x94) & 0xFFFFFFFFFFFFFFFFu;
    return collision[0xA3] == 3;
}

s32 func_80096544(PlayerState *player)
{
    func_800C670C(**(s32 **) ((s8 *) player + 0x94));
}

// Compare the floor flags (mask 0x1F00) against expected.
// Matching: the redundant copies are needed for the match.
s32 func_80096568(s32 *player, s32 expected)
{
    s32 floor_info;
    s32 flags;
    s32 collision;
    s32 collision_copy;
    s32 masked;
    s32 expected_copy;
    expected_copy = expected;
    collision = player[0x25];
    collision_copy = player[0x25];
    floor_info = *(s32 **) (collision + 0);
    flags = func_800C6744(floor_info);
    masked = flags & 0x1F00;
    return masked == expected_copy;
}

// Floor flags masked by mask.
// Matching: the redundant copies are needed for the match.
s32 func_8009659C(u8 *player, s32 mask)
{
    s32 *collision;
    s32 floor_copy;
    s32 *collision_copy;
    s32 floor_info;
    collision_copy = *(s32 **) ((u8 *) player + 0x94);
    collision = *(s32 **) ((u8 *) player + 0x94);
    floor_info = *collision;
    floor_copy = floor_info;
    return func_800C6744(floor_copy) & mask;
}

s32 func_800965C8(s32 player)
{
    return ((u8 **) (player + 0x94))[0][0xA4];
}

struct unk_struct_94 *func_800965D4(struct unk_struct_94 *player)
{
    return player->unk_94->unk_50;
}

void func_800965E0(u8 *player)
{
    func_800C67F8(**(s32 **) ((s8 *) player + 0x94));
}

void func_80096604(u8 *player)
{
    func_800C6840(**(s32 **) ((s8 *) player + 0x94));
}

s32 func_80096628(player)
PlayerState *player;
{
    func_800C6744(*(void **) *(s32 *) ((char *) player + 0x94));
}

void func_8009664C(void *player)
{
    func_800C674C(**(s32 **) ((u8 *) player + 0x94));
}

// Matching: the empty block and the temporary pointer are needed for the match.
void func_80096670(void *player)
{
    s32 **collision;
    {
    }
    collision = &(*((s32 **) (((char *) player) + 0x94)));
    func_800C67C8(*(*collision));
}

void func_80096694(PlayerState *player)
{
    func_800C84B0(func_80096628(player));
}

void func_800966BC(u8 *player)
{
    func_800C67E0(*(*(s32 **) ((s8 *) (player) + (0x94))));
}

void func_800966E0(void *player)
{
    func_800C67E8(*(*(s32 **) ((s8 *) player + 0x94)));
}

void func_80096704(void *player)
{
    func_800C5B84(*(*((s32 **) (((char *) player) + 0x94))));
}

// Matching: `^ 0` is needed for the match.
void func_80096728(u8 *player)
{
    s32 floor;
    floor = *(*((s32 **) (((u8 *) player) + 0x94)));
    if (floor != 0) {
        *(*((s32 **) (((u8 *) player) + 0x94))) = func_800C5BC4(floor ^ 0, floor, player);
    }
}

int func_80096768(player)
Actor *player;
{
    f32 pos[3];
    func_8009C128(player, pos);
    func_800D4D5C(pos, *(s32 *) ((char *) player + 0x94));
}

void func_8009679C(u8 *player)
{
    func_800C68DC(*(*(s32 **) ((s8 *) (player) + (0x94))));
}
