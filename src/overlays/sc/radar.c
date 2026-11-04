// Radar HUD of the multiplayer first-person shooter: per viewport, a background sprite and
// blips for the other players, placed relative to the viewer's facing.
#include "common.h"
#include "overlays/ba/playerstate.h"

#define SCRADAR_SET_CYCLE_TYPE(pkt, type)                                                          \
    {                                                                                              \
        Gfx *_g = (Gfx *) pkt;                                                                     \
        _g->words.w0 = _SHIFTL(0xE3, 24, 8) | _SHIFTL(32 - G_MDSFT_CYCLETYPE - 2, 8, 8) |          \
                       _SHIFTL(2 - 1, 0, 8);                                                       \
        _g->words.w1 = (unsigned int) type;                                                        \
    }

#define SCRADAR_FOG_COLOR(pkt, r, g, b, a) \
gDPSetColor(pkt, G_SETFOGCOLOR, _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(a, 0, 8) | _SHIFTL(b, 8, 8))
    #define SCRADAR_TEXTURE_RECT(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
{ \
        Gfx *_g = (Gfx *)pkt; \
        _g->words.w0 = _SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12); \
        _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12); \
        gImmp1(pkt, 0xE1, _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)); \
        gImmp1(pkt, 0xF1, _SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)); \
}

extern PlayerState *func_800F53D0(u32);
typedef struct {
    u8 pad_0[4];
    s16 x;
    s16 y;
    u8 color[4];
    u8 kind;
    u8 player;
    u8 pad_1[2];
} RadarIcon211;
typedef struct {
    s32 origin_x;
    s32 origin_y;
    u8 unk_8;
    u8 pad_0;
    s16 sprite_id;
    s16 friend_count;
    s16 enemy_count;
    RadarIcon211 friends[6];
    RadarIcon211 enemies[8];
} RadarView211;
extern s16 D_80800E30_scradar[];
extern u8 D_80800E3C_scradar[][2];
extern void func_800F5A00(s32, f32 *);
extern f32 func_800F5F24(u32);
typedef struct {
    f32 height;
    s16 x;
    s16 y;
    u8 pad_8[4];
    u8 kind;
    u8 player;
} RadarBlip;
extern void func_800E253C(f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_80013B70(f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800137F4(f32);
extern f32 func_80013788();
extern f32 func_800F0DC0(f32, f32);

// Draws one blip (cross, dot, blinking cross, arrow with height marker) by kind.
void func_80800000_scradar(gfx, origin, blip) Gfx **gfx;
s32 *origin;
void *blip;
{
    s32 screen_x;
    s32 screen_y;
    char *data;

    data = (char *) blip;
    screen_x = (origin[0] + *(s16 *) (data + 4)) & ~3;
    screen_y = (origin[1] + *(s16 *) (data + 6)) & ~3;

    gDPPipeSync((*gfx)++);

    switch (*(u8 *) (data + 0xC)) {
        case 0:
            SCRADAR_FOG_COLOR((*gfx)++, 0xFF, 0xFF, 0xFF, 0x80);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 4, screen_y, screen_x + 8, screen_y + 4,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x, screen_y - 4, screen_x + 4, screen_y + 8,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);
            break;

        case 1: {
            s32 alpha;
            alpha = *(u8 *) (data + 0xB);

            SCRADAR_FOG_COLOR((*gfx)++, *(u8 *) (data + 8) >> 2, *(u8 *) (data + 9) >> 2,
                              *(u8 *) (data + 0xA) >> 2, (alpha >> 1) + (alpha >> 2));

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 8, screen_y - 8, screen_x + 8, screen_y + 8,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);

            gDPPipeSync((*gfx)++);

            SCRADAR_FOG_COLOR((*gfx)++, *(u8 *) (data + 8), *(u8 *) (data + 9),
                              *(u8 *) (data + 0xA), alpha);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 4, screen_y - 4, screen_x + 4, screen_y + 4,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);
            break;
        }
        case 2:
            if (func_8001210C(4) == 0) {
                break;
            }

            SCRADAR_FOG_COLOR((*gfx)++, *(u8 *) (data + 8), *(u8 *) (data + 9),
                              *(u8 *) (data + 0xA), *(u8 *) (data + 0xB));

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 4, screen_y, screen_x + 8, screen_y + 4,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x, screen_y - 4, screen_x + 4, screen_y + 8,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);
            break;

        case 4: {
            s32 offset;
            offset = (s32) (*(f32 *) data * 8.0f);

            SCRADAR_FOG_COLOR((*gfx)++, 0, 0, 0, *(u8 *) (data + 0xB) >> 1);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 6, screen_y - 14, screen_x + 6, screen_y + 14,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 10, screen_y + offset - 6, screen_x + 10,
                                 screen_y + offset + 6, G_TX_RENDERTILE, 0, 0, 0x100, 0x100);

            gDPPipeSync((*gfx)++);
        }
        case 3: {
            s32 offset;
            offset = (s32) (*(f32 *) data * 8.0f);

            SCRADAR_FOG_COLOR((*gfx)++, *(u8 *) (data + 8), *(u8 *) (data + 9),
                              *(u8 *) (data + 0xA), *(u8 *) (data + 0xB));

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 2, screen_y - 10, screen_x + 2, screen_y + 10,
                                 G_TX_RENDERTILE, 0, 0, 0x100, 0x100);

            SCRADAR_TEXTURE_RECT((*gfx)++, screen_x - 6, screen_y + offset - 2, screen_x + 6,
                                 screen_y + offset + 2, G_TX_RENDERTILE, 0, 0, 0x100, 0x100);
        }
    }
}

s32 func_8080074C_scradar(u8 *output, u8 r, u8 g, u8 b)
{
    output[0] = r;
    output[1] = g;
    output[2] = b;
}

// Blip kind: 3/4 for special forms (character 0xC/6), 2 for state 0x20, else 1.
s32 func_80800768_scradar(u32 player)
{
    switch (func_800F5410(player)) {
        case 0xC:
            return 3;
        case 6:
            return 4;
    }
    if (func_8009E674(func_800F53D0(player), 0x20)) {
        return 2;
    }
    return 1;
}

// Computes blip position relative to the viewer, distance capped at 5000 and scaled by 0.01.
void func_808007D4_scradar(RadarBlip *blip, f32 *viewer_pos, f32 viewer_angle)
{
    s32 player;
    f32 rel_pos[3];
    f32 dist;
    f32 value;

    player = blip->player;
    func_800F5A00(player, rel_pos);
    func_800EFB24(rel_pos, viewer_pos, rel_pos);
    dist = sqrtf(rel_pos[0] * rel_pos[0] + rel_pos[2] * rel_pos[2]);
    value = func_800136E4(func_80013B70(rel_pos[0], rel_pos[2], dist) - viewer_angle);
    if (dist > 5000.0f) {
        dist = 5000.0f;
    }
    dist *= 0.01f;
    blip->x = -func_800137F4(value) * dist;
    blip->y = -func_80013788() * dist;
    blip->kind = func_80800768_scradar(player);
    switch (blip->kind) {
        case 1:
        case 2:
            value = 0.0f;
            break;
        case 3:
        case 4:
            value = func_800F0DC0(rel_pos[1] * 0.001f, 1.0f);
            break;
        default:
            value = 0.0f;
            break;
    }
    blip->height = value;
}

RadarView211 B_80800E50_scradar[4];

// Builds per-viewport blip lists (friendly up to 6, others up to 8).
void scradar_entrypoint_0(void)
{
    s32 view_count;
    s32 special_form = 0;
    s32 team;
    s32 view_idx;
    RadarView211 *view;
    s32 player;
    s32 viewer;
    u8 shade;
    RadarIcon211 *icon;
    f32 viewer_angle;
    s32 vp_x;
    s32 vp_y;
    s32 vp_w;
    s32 vp_h;
    Vec3f viewer_pos;
    RadarView211 *cur_view;
    s32 k;
    s32 unk_0;

    view_count = func_800A946C();
    if (func_80800768_scradar(0) == 4) {
        special_form = 1;
    }
    for (viewer = 0; viewer < view_count; viewer++) {
        team = _gcstatusDll_entrypoint_16(viewer);
        B_80800E50_scradar[viewer].friend_count = 1;
        B_80800E50_scradar[viewer].sprite_id = D_80800E30_scradar[team];
        B_80800E50_scradar[viewer].enemy_count = 0;
        B_80800E50_scradar[viewer].unk_8 = D_80800E3C_scradar[team][special_form];
    }
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            viewer = func_800A940C(player);
            team = _gcstatusDll_entrypoint_16(viewer);
            shade = func_80092258(func_800F53D0(player));
            for (view_idx = 0; view_idx < view_count; view_idx++) {
                view = &B_80800E50_scradar[view_idx];
                if (_gcstatusDll_entrypoint_16(view_idx) == team) {
                    if (view_idx == viewer && func_800A9420(player)) {
                        icon = &view->friends[0];
                        icon->color[3] = 0xC0;
                    } else {
                        icon =
                            (RadarIcon211 *) ((view->friend_count++ << 4) + (u8 *) view + 0x10);
                        icon->color[3] = 0x60;
                    }
                } else {
                    icon = (RadarIcon211 *) ((view->enemy_count++ << 4) + (u8 *) view + 0x70);
                    icon->color[3] = shade;
                }
                icon->player = player;
            }
        }
    }
    for (viewer = 0; viewer < view_count; viewer++) {
        cur_view = B_80800E50_scradar + viewer;
        func_800A8A04(viewer, &vp_x, &vp_y, &vp_w, &vp_h);
        cur_view->origin_x = (vp_w + vp_x - 25) << 2;
        cur_view->origin_y = (vp_h + vp_y - 19) << 2;
        if (cur_view->friend_count) {
            cur_view->friends[0].x = 0;
            cur_view->friends[0].y = 0;
            cur_view->friends[0].kind = 0;
            icon = &cur_view->friends[0];
            func_800F5A00(cur_view->friends[0].player, viewer_pos.f);
            viewer_angle = func_800F5F24(icon->player) + 180.0f;
            for (k = 1; k < cur_view->friend_count; k++) {
                icon = (RadarIcon211 *) ((u8 *) cur_view + (k << 4) + 0x10);
                func_808007D4_scradar((RadarBlip *) icon, viewer_pos.f, viewer_angle);
                func_8080074C_scradar(icon->color, 255, 255, 255);
            }
            for (k = 0; k < cur_view->enemy_count; k++) {
                func_8080074C_scradar((u8 *) cur_view + (k << 4) + 0x78, 255, 32, 32);
                func_808007D4_scradar((RadarBlip *) ((u8 *) cur_view + (k << 4) + 0x70),
                                      viewer_pos.f, viewer_angle);
            }
        }
    }
}

// Draws the radar background and blips for every viewport.
void scradar_entrypoint_1(Gfx **gfx)
{
    RadarView211 *view;
    s32 view_count;
    s32 i;
    s32 j;
    s32 fb;
    view_count = func_800A946C();
    for (i = 0; i < view_count; i++) {
        view = &B_80800E50_scradar[i];
        if (view->friend_count) {
            func_800E253C(1.25f);
            func_800E257C(view->unk_8);
            func_800E2434(1);
            fb = func_800A7180();
            func_800E30E0(fb, func_800D674C(view->sprite_id), 0, view);
        }
    }
    func_800B9990(gfx);
    for (i = 0; i < view_count; i++) {
        if (B_80800E50_scradar[i].friend_count) {
            view = &B_80800E50_scradar[i];
            for (j = 0; j < view->friend_count; j++) {
                func_80800000_scradar(gfx, &view->origin_x,
                                      (u8 *) view + (j << 4) + 0x10);
            }
            for (j = 0; j < view->enemy_count; j++) {
                func_80800000_scradar(gfx, &view->origin_x,
                                      (u8 *) view + (j << 4) + 0x70);
            }
        }
    }
    gDPPipeSync((*gfx)++);
    SCRADAR_SET_CYCLE_TYPE((*gfx)++, G_CYC_2CYCLE);
}

s16 D_80800E30_scradar[6] = {0xB81, 0xB81, 0xB81, 0xB81, 0xB84, 0xB83};
u8 D_80800E3C_scradar[10][2] = {0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x60, 0x80,
                                0x70, 0x90, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
