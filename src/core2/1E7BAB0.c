#include "common.h"

#define STATE(p) (*(LocalState **) ((u8 *) (p) + 0xB4))
extern u8 D_80119270[];
// Light entry of the light set (see 1E8CC00.c).
typedef struct {
    u8 pad_0[0xC]; // direction
    s32 color[3];
    f32 distance;
} LocalHit;
// Player lighting state, found at PlayerState+0xB4.
typedef struct {
    s8 limit; // max number of lights
    u8 enabled;
    u8 pad_2[2]; // +2: active flag, +3: once-per-frame guard
    void *light_set;
    s32 color[3]; // smoothed light color
} LocalState;
extern f32 func_80092B8C(void *, f32 *);
extern s32 func_800B3494(void *, f32 *, f32);
extern s32 func_800B36C0(void *, s32 *, s32 *, f32);
extern void func_800B37A4(void *, LocalHit **, LocalHit **);
extern s32 func_800B38E8();
s32 func_800A25D0();
void func_800A25DC();

s32 func_800A21C0()
{
    return 0x14;
}

// Looks the current map up in D_80119270 (entries {s16 map, u8 limit, u8 enabled},
// terminated by -1) and stores limit/enabled in the player's lighting state.
void func_800A21C8(u8 *player)
{
    s32 map_id;
    s32 index;
    s8 limit;
    u8 *state;
    u8 *entry;

    map_id = func_800EA05C();
    index = 0;
    if (*(s16 *) D_80119270 != -1) {
        while (1) {
            if (map_id == *(s16 *) ((char *) D_80119270 + index * 4))
                break;
            index++;
            if (*(s16 *) ((char *) D_80119270 + index * 4) == -1)
                break;
        }
    }
    entry = (u8 *) ((char *) D_80119270 + (index * 4));
    *(u8 *) ((char *) *(u8 **) ((char *) player + 0xB4) + 0) = entry[2];
    *(u8 *) ((char *) *(u8 **) ((char *) player + 0xB4) + 1) = entry[3];
    if (*(s16 *) entry == -1 && func_800C8C18() > 0) {
        *(u8 *) ((char *) *(u8 **) ((char *) player + 0xB4) + 0) = 2;
        *(u8 *) ((char *) *(u8 **) ((char *) player + 0xB4) + 1) = 0;
    }
    state = *(u8 **) ((char *) player + 0xB4);
    limit = (s8) state[0];
    if (limit >= 3) {
        state[0] = 2U;
        limit = (s8) **(u8 **) ((char *) player + 0xB4);
    }
    func_800A25DC(player, limit);
}

void func_800A22A8(s32 player)
{
    func_800A25DC(player, 0);
}

// Scales each channel of color by tint / 256.
int func_800A22C8(s32 *color, s32 *tint)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        color[i] = (color[i] * tint[i]) / 256;
    }
}

// Sets the light set's ambient color to the global ambient light times tint.
void func_800A2314(s32 player, s32 tint)
{
    f32 ambient[3];
    func_800C87B8(ambient);
    func_800A22C8(ambient, tint);
    func_800B38A8(((s32 *) *(s32 **) (player + 0xB4))[1], ambient);
}

// Per-frame update: gathers lights near the player, adds the ambient/directional
// light tinted by the floor, and smooths the nearest light's color.
void func_800A235C(void *player)
{
    f32 unk_0[3];
    f32 pos[3];
    f32 range;
    s32 light_count;
    s32 floor_tint[3];
    LocalHit *first;
    LocalHit *end;
    s32 dir[3];
    s32 color[3];
    s32 i;
    s32 target[3];
    func_800A1F0C(player, floor_tint);
    func_800A2314(player, floor_tint);
    range = func_80092B8C(player, pos);
    func_8009C128(player, unk_0);
    func_800EF04C(pos, unk_0);
    light_count = func_800B3494(STATE(player)->light_set, pos, range);
    func_800B37A4(STATE(player)->light_set, &first, &end);
    if (light_count < STATE(player)->limit && STATE(player)->enabled) {
        func_800C8960(color, dir);
        func_800A22C8(color, floor_tint);
        light_count += func_800B36C0(STATE(player)->light_set, dir, color,
                                     light_count ? first->distance : 500.0f);
    }
    if (light_count) {
        func_800EE830(target, first->color);
        func_800EE830(first->color, STATE(player)->color);
        // Step the stored color toward the target by 40 per frame.
        for (i = 0; i < 3; i++) {
            if (first->color[i] < target[i]) {
                first->color[i] += 40;
                if (target[i] < first->color[i])
                    first->color[i] = target[i];
            } else if (target[i] < first->color[i]) {
                first->color[i] -= 40;
                if (first->color[i] < target[i])
                    first->color[i] = target[i];
            }
        }
        func_800EE830(STATE(player)->color, first->color);
    }
}

// Clears the once-per-frame guard byte.
void func_800A2534(void *player)
{
    ((s8 *) *(void **) ((char *) player + 0xB4))[3] = 0;
}

// Draws with the floor tint when dynamic lighting is inactive, otherwise updates the
// lights once per frame and draws with the light set.
void func_800A2540(u8 *player, s32 param_1)
{
    s32 tint_b;
    s32 tint_g;
    s32 tint_r;
    u8 *state;
    if (func_800A25D0() == 0) {
        func_800A1F0C(player, &tint_r);
        func_800DF5D8(tint_r, tint_g, tint_b, param_1);
        return;
    }
    state = *(u8 **) ((s8 *) player + 0xB4);
    if (*(u8 *) ((s8 *) state + 3) == 0) {
        func_800A235C(player);
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xB4) + 3) = 1;
        // Matching: the bare block is needed for the match.
        {
            state = *(u8 **) ((s8 *) player + 0xB4);
        }
    }
    func_800DF660(1, 0, *(s32 *) ((s8 *) state + 4), param_1);
}

// Returns the active flag.
s32 func_800A25D0(player)
s32 player;
{
    return ((u8 *) *(u8 **) (player + 0xb4))[2];
}

// Sets the active flag and allocates or frees the light set to match.
void func_800A25DC(player, enable) u8 *player;
s32 enable;
{
    u8 *state;
    s32 new_set;

if (enable != 0) {
    (*(u8 **) (player + 0xB4))[2] = 1;
} else {

(*(u8 **) (player + 0xB4))[2] = 0;

}

state = *(u8 **) (player + 0xB4);
if (state[2] != 0) {
    if (*(s32 *) (state + 4) == 0) {
        new_set = func_800B3310((s8) state[0], enable);
        *(s32 *) (*(u8 **) (player + 0xB4) + 4) = new_set;
    }

}
else
{
    if (*(s32 *) (state + 4) != 0) {
        func_800B3370(*(s32 *) (state + 4), enable);
        *(s32 *) (*(u8 **) (player + 0xB4) + 4) = 0;
    }

}
}

// Defragments the light set.
void func_800A266C(u8 *player)
{
    s32 light_set = *((s32 *) ((*((u8 **) (player + 0xB4))) + 4));
    s32 new_set;
    if (light_set) {
        // Matching: the "^ 0" is needed for the match.
        new_set = func_800B38E8(light_set ^ 0, light_set, player);
        *((s32 *) ((*((u8 **) (player + 0xB4))) + 4)) = new_set;
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E7BAB0.data.s) is
// defined here in C; the values are taken from the ROM.
u8 D_80119270[176] = {
    0x1,  0x24, 0x1, 0x1, 0x0, 0xB9, 0x1, 0x1, 0x0, 0xC4, 0x1, 0x1, 0x0, 0xF1, 0x2, 0x1,
    0x0,  0xE7, 0x1, 0x1, 0x1, 0x88, 0x0, 0x0, 0x1, 0x82, 0x0, 0x0, 0x1, 0x64, 0x0, 0x0,
    0x1,  0x65, 0x0, 0x0, 0x1, 0x66, 0x0, 0x0, 0x0, 0xFD, 0x0, 0x0, 0x0, 0xFE, 0x0, 0x0,
    0x1,  0x1C, 0x0, 0x0, 0x1, 0x1D, 0x0, 0x0, 0x0, 0xE4, 0x0, 0x0, 0x1, 0x7B, 0x0, 0x0,
    0x0,  0xE5, 0x0, 0x0, 0x1, 0x7C, 0x0, 0x0, 0x1, 0x7D, 0x0, 0x0, 0x1, 0x83, 0x0, 0x0,
    0x1,  0x23, 0x0, 0x0, 0x1, 0x10, 0x1, 0x1, 0x0, 0xFC, 0x1, 0x1, 0x0, 0x9,  0x0, 0x0,
    0x0,  0x8,  0x0, 0x0, 0x0, 0x19, 0x0, 0x0, 0x0, 0xB0, 0x0, 0x0, 0x1, 0x85, 0x0, 0x0,
    0x1,  0x50, 0x2, 0x1, 0x0, 0xB8, 0x1, 0x1, 0x0, 0xC7, 0x1, 0x1, 0x0, 0xD6, 0x1, 0x1,
    0x1,  0xA7, 0x1, 0x1, 0x1, 0xA8, 0x1, 0x1, 0x1, 0xA9, 0x1, 0x1, 0x1, 0x12, 0x1, 0x1,
    0x1,  0x0,  0x1, 0x1, 0x1, 0x27, 0x1, 0x1, 0x1, 0x28, 0x1, 0x1, 0x1, 0x36, 0x1, 0x1,
    0xFF, 0xFF, 0x2, 0x1, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
