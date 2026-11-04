// Probably the player model tint: samples the floor triangle's vertex colors under the player,
// fades with height, applies fade and darkness flags, and smooths the stored color per frame.
#include "core2/1E7B250.h"

extern s32 func_80091E80(PlayerState *, s32);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_80096364(PlayerState *);
extern s32 func_80096628(PlayerState *);
extern void func_80096604(PlayerState *, f32 (*)[3]);
extern void func_800965E0();
extern s32 func_800F36D4(s32 *, s32 *);
extern void func_800EE84C(f32 *, s32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_800962D4(PlayerState *);
extern Unk80132ED0 *func_800965D4(PlayerState *);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _subaddiefade_entrypoint_9(Actor *, s32 *);
extern s32 func_800F40EC(PlayerState *);
extern s16 D_80119260[];
typedef struct {
    u8 state;
    u8 prev;
    u8 pad_2[2];
    f32 r;
    f32 g;
    f32 b;
} Sub1F78;
typedef struct {
    u8 pad_0[0x108];
    Sub1F78 *sub;
} Obj1F78;
// Tint state at PlayerState+0x108: mode and the smoothed RGB.
typedef struct {
    u8 mode;
    u8 pad_1[3];
    f32 color[3];
} StateA2060;
typedef struct {
    u8 pad_0[0x108];
    StateA2060 *tint;
} ActorA2060;
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800965C8(ActorA2060 *);

s32 func_800A1960()
{
    return 0x10;
}

// Player tint (RGB 0-255) from the floor triangle's vertex colors, height fade and floor flags.
void func_800A1968(PlayerState *player, f32 *color)
{
    f32 player_pos[3];
    f32 to_v0[3];
    f32 tmp_vec[3];
    f32 denom;
    f32 dist;
    f32 swap;
    u32 floor_flags;
    f32 blend;
    f32 edge_perp[3];
    f32 edge01[3];
    f32 hit_pos[3];
    u8 vertex_rgba[3][4];
    s32 vertex_rgb[3][3];
    s32 ambient;
    s32 i;
    s32 j;
    f32 tri_verts[3][3];
    Unk80132ED0 *fade_obj;
    s32 fade_tint[3];

    color[0] = color[1] = color[2] = 255.0f;
    if (!func_80091E80(player, 4))
        return;
    func_8009C128(player, player_pos);
    if (player_pos[1] - func_80096364(player) > 1000.0f)
        return;
    floor_flags = func_80096628(player);
    if (floor_flags & 0x200000)
        return;
    func_80096604(player, tri_verts);
    func_800965E0(player, vertex_rgba);
    for (i = 0; i < 3; i++) {
        tri_verts[i][1] = 0.0f;
        for (j = 0; j < 3; j++) {
            vertex_rgb[i][j] = vertex_rgba[i][j];
        }
    }
    if (func_800F36D4(vertex_rgb[0], vertex_rgb[1]) && func_800F36D4(vertex_rgb[0], vertex_rgb[2])) {
        func_800EE84C(color, vertex_rgb[0]);
    } else {
        player_pos[1] = 0.0f;
        func_800EFB24(to_v0, player_pos, tri_verts[0]);
        to_v0[1] = 0.0f;
        func_800EFB24(edge01, tri_verts[0], tri_verts[1]);
        edge01[1] = 0.0f;
        func_800EFB24(edge_perp, tri_verts[2], tri_verts[1]);
        edge_perp[1] = 0.0f;
        swap = edge_perp[0];
        edge_perp[0] = -edge_perp[2];
        edge_perp[2] = swap;
        denom = func_800EEAA4(to_v0, edge_perp);
        if (denom == 0.0f)
            denom = 0.1f;
        dist = -func_800EEAA4(edge01, edge_perp) / denom;
        func_800EFA4C(hit_pos, tri_verts[0][0] + to_v0[0] * dist, 0,
                      tri_verts[0][2] + to_v0[2] * dist);
        func_800EFB24(tmp_vec, hit_pos, tri_verts[1]);
        blend = func_800EEF94(tmp_vec) / (func_800EEF94(edge_perp) + 0.01f);
        for (i = 0; i < 3; i++) {
            color[i] =
                vertex_rgb[1][i] + (vertex_rgb[2][i] - vertex_rgb[1][i]) * blend;
        }
        func_800EFB24(tmp_vec, hit_pos, tri_verts[0]);
        blend = 1.0f - func_800EEF94(to_v0) / (func_800EEF94(tmp_vec) + 0.01f);
        for (i = 0; i < 3; i++) {
            color[i] =
                color[i] + (vertex_rgb[0][i] - color[i]) * blend;
        }
    }
    blend = func_800962D4(player) / 1000.0f;
    for (i = 0; i < 3; i++) {
        color[i] = color[i] + (255.0f - color[i]) * blend;
    }
    for (i = 0; i < 3; i++) {
        if (color[i] > 255.0f)
            color[i] = 255.0f;
        if (color[i] < 0.0f)
            color[i] = 0.0f;
    }
    if (func_80091E80(player, 4)) {
        fade_obj = func_800965D4(player);
        if (fade_obj) {
            _subaddiefade_entrypoint_9(func_80106790(fade_obj), fade_tint);
            for (i = 0; i < 3; i++) {
                color[i] = ((s32) color[i] * fade_tint[i]) >> 8;
            }
        }
    }
    if (**(u8 **) ((u8 *) player + 0x108) == 1)
        ambient = 50;
    else {
        switch (func_800F40EC(player)) {
            case 0:
                ambient = 200;
                break;
            default:
                ambient = 250;
                break;
        }
    }
    if (floor_flags & 0x4000000) {
        color[0] =
            (color[0] + color[1] + color[2]) * (255.0f - ambient) * 0.0013071895f + ambient;
        color[1] = color[0];
        color[2] = color[0];
    } else {
        denom = 0.0039215684f;
        color[0] = color[0] * (255.0f - ambient) * denom + ambient;
        color[1] = color[1] * (255.0f - ambient) * denom + ambient;
        color[2] = color[2] * (255.0f - ambient) * denom + ambient;
    }
}

void func_800A1F0C(u8 *player, s32 unk_0)
{
    u8 *state;
    state = *(u8 **) ((s8 *) player + 0x108);
    func_800EFA88(unk_0, (s32) (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x108) + 4) + 0.5f),
                  (s32) (*(f32 *) ((s8 *) state + 8) + 0.5f),
                  (s32) (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x108) + 0xC) + 0.5f));
}

// Init tint state; state 2 for maps listed in D_80119260.
void func_800A1F78(Obj1F78 *player)
{
    s32 i;
    s32 map;

    map = func_800EA05C();
    player->sub->r = 255.0f;
    player->sub->g = 255.0f;
    player->sub->b = 255.0f;
    player->sub->state = 1;
    for (i = 0; D_80119260[i] != 0; i++) {
        if (map == D_80119260[i]) {
            player->sub->state = 2;
            break;
        }
    }
    player->sub->prev = player->sub->state;
}

// Push a new tint mode, or restore the previous one when mode is -1.
void func_800A2018(PlayerState *player, s32 mode)
{
    u8 *restore_state;
    u8 cur_mode;
    u8 *state;

    if (mode == -1) {
        restore_state = *(u8 ***) ((char *) player + 0x108);
        *(u8 *) restore_state = *(u8 *) (restore_state + 1);
        return;
    }
    state = *(u8 ***) ((char *) player + 0x108);
    cur_mode = *(u8 *) state;
    if (mode != cur_mode) {
        *(u8 *) (state + 1) = cur_mode;
        *(u8 *) *(u8 ***) ((char *) player + 0x108) = mode;
    }
}

void func_800A2058(s32 arg0)
{
}

// Per-frame: move the stored tint toward the target color by 40 per channel.
void func_800A2060(ActorA2060 *actor)
{
    s32 i;
    f32 target_color[3];
    switch (actor->tint->mode) {
        case 0:
            func_800EFA4C(target_color, 255.0f, 255.0f, 255.0f);
            break;
        case 3:
            func_800EE7F8(target_color, actor->tint->color);
            break;
        default:
            if (func_800965C8(actor))
                func_800A1968(actor, target_color);
            else
                func_800EE7F8(target_color, actor->tint->color);
    }
    for (i = 0; i < 3; i++) {
        if (actor->tint->color[i] < target_color[i]) {
            actor->tint->color[i] += 40.0f;
            if (target_color[i] < actor->tint->color[i])
                actor->tint->color[i] = target_color[i];
        } else if (target_color[i] < actor->tint->color[i]) {
            actor->tint->color[i] -= 40.0f;
            if (actor->tint->color[i] < target_color[i])
                actor->tint->color[i] = target_color[i];
        }
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E7B250.data.s) is defined here in C.
// Values are taken from the ROM.
s16 D_80119260[8] = {0x8, 0x9, 0x17, 0x137, 0x185, 0x0, 0x0, 0x0};
