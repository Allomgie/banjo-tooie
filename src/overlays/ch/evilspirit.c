// Bottles' evil spirit, player 2 in the cut "Bottles' Revenge" mode (game mode 1). It takes over
// enemies near player 1 (message 1 take over, 2 release) and keeps a radar of nearby enemies.
#include "common.h"

#define TEXTURE_RECT48(pkt, xl, yl, xh, yh)                                                        \
    {                                                                                              \
        Gfx *_g = (Gfx *) (pkt);                                                                   \
        _g->words.w0 = _SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12);       \
        _g->words.w1 = _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12);                                   \
        gImmp1(pkt, 0xE1, 0);                                                                      \
        gImmp1(pkt, 0xF1, 0x01000100);                                                             \
    }
extern void *D_80802270_chevilspirit;
extern void *func_80100094(Actor *, u32);
extern f32 func_800DC178(f32, f32);
extern u8 D_808021D0_chevilspirit[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern int _susubgame_entrypoint_3(Actor *, void *, s32, s32);
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10 : 31;
    u32 unk_10_lsb : 1;
} local_marker;
typedef struct {
    local_marker *unk_0;
} local_actor;
extern s32 func_801017D0;
extern u8 D_808022D4_chevilspirit[];
extern u8 D_808022D8_chevilspirit[];
extern u8 D_808022DC_chevilspirit[];
extern Actor *_subaddielink_entrypoint_4(void *);
extern Actor *func_80106790();
typedef struct {
    u32 w0, w1;
} GfxW;
extern u16 D_808022E0_chevilspirit[];
extern s32 func_800EA05C(void);
extern s32 func_800D3934(void);
extern u16 D_808022E4_chevilspirit[];
extern void func_8008FE94();
extern f32 func_80090010(void);
extern f32 func_8010CD28(Actor *);
extern void func_8010105C(f32);
extern f32 func_80101068(void);
extern void func_800EF334(f32 *, f32);
extern u8 D_808022E8_chevilspirit[];
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct {
    u8 pad_0[8];
    s16 count;
    s16 cur;
    s32 ids[1];
} EvilList;
extern int func_800BDC5C(void);
typedef struct {
    u8 pad_0[0x64];
    u8 pad_1 : 2;
    u8 joystick : 1;
    u8 controller : 2;
    u8 pad_2 : 3;
} EvilSpiritActorFlags;
extern s16 D_808021E0_chevilspirit[];
extern int func_8010108C(void *, int, int);
extern void _subaddielink_entrypoint_0(void *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_808022F4_chevilspirit[];
extern int func_800EE7F8(f32 *, f32 *);
extern void func_800C8E54(s32, f32, f32);
extern void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
extern f32 D_80802320_chevilspirit[];
extern f32 D_8080232C_chevilspirit[];
extern f32 D_80802338_chevilspirit[];
extern f32 func_800F0F9C(f32, f32);
extern f32 func_800F3780(f32, f32 *, s32);
extern void func_800F3214(f32 *, f32 *, f32 *, f32);
extern f32 func_800D8FF8(void);
extern u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern s32 func_800C3058(u8, u32);
extern void func_800C330C(u8, s32);
extern void func_800C31DC(u8, f32);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C3BDC(u8);
extern s16 D_808022C8_chevilspirit[];
extern s16 D_808021EC_chevilspirit[];
extern s16 D_808022B8_chevilspirit[];
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_8010297C(Actor *, f32, f32, f32);
extern f32 func_80013B70(f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
typedef struct {
    u8 pad_0[8];
    s16 count;
    s16 cur;
    Unk80132ED0 *targets[1];
} EvilSpiritTargetList;
typedef struct {
    Unk80132ED0 *obj;
    s32 unk_4;
    u32 flags;
} EvilSpiritCubeEntry;
extern u8 D_80802350_chevilspirit[];
void func_808007B4_chevilspirit();
void func_80800E20_chevilspirit();
s32 func_80800F8C_chevilspirit();
void func_80801344_chevilspirit();
void func_80801458_chevilspirit();
s32 func_808015E0_chevilspirit(Actor *param_0, f32 param_1);
s32 func_80801988_chevilspirit();
int func_80801A6C_chevilspirit();
void func_80801B00_chevilspirit();
void func_80801C04_chevilspirit();
void func_80801E18_chevilspirit();
s32 func_80801EC4_chevilspirit();
void func_80802024_chevilspirit();
void func_80802090_chevilspirit();
void func_80800A4C_chevilspirit(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3,
                                Actor *param_4, f32 param_5, u8 *param_6);
void func_808013DC_chevilspirit();
void func_80801F1C_chevilspirit();

void *chevilspirit_entrypoint_0()
{
    return &D_80802270_chevilspirit;
}

void func_8080000C_chevilspirit(Actor *actor)
{
    void *state;

    state = func_80100094(actor, 0);
    if (func_80800F8C_chevilspirit(actor)) {
        _subaddieDll_entrypoint_0(actor);
        func_8010A828(actor, 9);
    }
    func_80801344_chevilspirit(actor);
    func_800EE7F8(actor->position, (f32 *) ((u8 *) actor + 0x18));
    actor->unk58 = func_800DC178(5.0f, 8.0f);
    _subaddielink_entrypoint_0(state);
    *(s32 *) ((u8 *) actor + 0x24) = 0;
    if (func_800EA068(16)) {
        // Digger Tunnel, flag 0x38 not set yet (first sight).
        if (func_800EA05C() == 0x141 && !func_800DA298(0x38)) {
            func_80102424(actor, 2);
            actor->unk58 = 3.0f;
        } else {
            func_80102424(actor, 3);
            actor->unk58 = 2.0f;
        }
    }
}

void func_80802118_chevilspirit();

s32 func_80801684_chevilspirit();

void func_808015A4_chevilspirit();

void func_80801398_chevilspirit();

void func_80800104_chevilspirit(Actor *actor)
{
    u8 *state;
    s32 timer_done;

    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            func_80801344_chevilspirit(actor);
            func_808012CC_chevilspirit(actor);
            break;
        case 2:
            func_80801344_chevilspirit(actor);
            if (func_800DB9B0()) {
                func_800DA544(0x38);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x15CA, 0x44, 0, 0xBB);
                func_80102424(actor, 3);
            }
            break;
        case 3:
            func_80801344_chevilspirit(actor);
            if (func_800D9078(&actor->unk58)) {
                s32 light = actor->actorData[3];

                if (light) {
                    actor->actorData[3] = _chlightfader_entrypoint_1(light, 1.0f, 2);
                }
                func_80802090_chevilspirit(actor, D_808022B8_chevilspirit);
                _subaddiefade_entrypoint_3(actor);
                func_8010A828(actor, 0xC);
                func_80102424(actor, 4);
                func_800DA524(0x6A7);
            }
            break;
        case 4:
            func_801078DC(actor, state + 0x3C);
            break;
        case 5:
            if (func_800C9510()) {
                func_80801A6C_chevilspirit(actor, 0);
            } else if (!func_80801840_chevilspirit(actor) ||
                       !func_80801EC4_chevilspirit(actor)) {
                func_80102424(actor, 8);
            } else {
                func_808015A4_chevilspirit(actor);
            }
            break;
        case 6:
            func_80116088(func_80110014(func_8008FFE8()), actor->position);
            if (func_800C9510()) {
                func_80801A6C_chevilspirit(actor, 0);
            } else if (!func_80801840_chevilspirit(actor)) {
                func_80102424(actor, 7);
                *(f32 *) &actor->actorData[4] = 1.5f;
            } else if (!func_80801EC4_chevilspirit(actor) &&
                       func_80801A6C_chevilspirit(actor, 3)) {
                func_80802090_chevilspirit(actor, D_808021EC_chevilspirit);
                func_80102424(actor, 8);
                *(f32 *) &actor->actorData[4] = 1.5f;
            } else if (!func_808018DC_chevilspirit(actor)) {
                func_80802090_chevilspirit(actor, D_808021EC_chevilspirit);
                func_80102424(actor, 8);
                *(f32 *) &actor->actorData[4] = 1.5f;
            } else {
                func_80801684_chevilspirit(actor);
                func_80801398_chevilspirit(actor);
            }
            break;
        case 7:
            if (!func_8001210C(7)) {
                func_8010297C(actor, actor->unk54, 40.0f, 60.0f);
            }
            func_80102BF8(actor, 0.2f, 15.0f, 1200.0f);
            if (func_800D9078(&actor->actorData[4])) {
                func_80802090_chevilspirit(actor, D_808021EC_chevilspirit);
                func_80102424(actor, 8);
            }
            func_808012CC_chevilspirit(actor);
            break;
        case 8:
            func_80801534_chevilspirit(actor);
            func_808012CC_chevilspirit(actor);
            break;
        case 10:
            func_801078DC(actor, state + 0x3C);
            if (_subaddiefade_entrypoint_0(actor) == 0) {
                func_80802090_chevilspirit(actor, D_808022C8_chevilspirit);
                func_80103140(actor, 0x90F, actor->unk0->unk16);
                func_80102424(actor, 0xB);
                _subaddiefade_entrypoint_2(actor);
            }
            break;
        case 11:
            func_801078DC(actor, state + 0x3C);
            if (_subaddiefade_entrypoint_0(actor) == 0xFF) {
                func_80102424(actor, 0xC);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x15CB, 6, actor->position, 0xBB);
            }
            break;
        case 13:
            timer_done = func_800D90A4(&actor->unk58);
            if (func_8010D23C()) {
                actor->unk54 = func_8010CD28(actor);
                func_80102BF8(actor, 0.2f, 15.0f, 1200.0f);
            }
            if (timer_done && func_8010CAC0(actor->position, 500)) {
                _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0, 4) + 0x15C6, 0x44,
                                              actor->position, 0xBB);
                func_80102424(actor, 0xE);
            }
            break;
        case 14:
            if (func_8010D23C()) {
                actor->unk54 = func_8010CD28(actor);
                func_80102BF8(actor, 0.2f, 15.0f, 1200.0f);
            }
    }
    func_80801E18_chevilspirit(actor);
    func_80802118_chevilspirit(actor);
}

int func_808005B4_chevilspirit(Actor *actor)
{
    s32 *slot = (s32 *) ((char *) actor + 0x24);
    if (*slot != 0) {
        func_800C8B84(*(s32 *) ((char *) actor + 0x24));
        *(s32 *) ((char *) actor + 0x24) = 0;
    }
}

int func_808005EC_chevilspirit(Actor *actor, s32 msg, s32 data)
{
    u8 *state;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 0x2E:
            func_80801F1C_chevilspirit(actor, ((s16 *) &data)[0], ((s16 *) &data)[1]);
            break;
        case 0x2F:
            func_80802024_chevilspirit(actor, ((s16 *) &data)[0], ((s16 *) &data)[1]);
            break;
        case 0x95:
            func_80801C04_chevilspirit(actor);
            break;
        case 0x1F:
            func_801015D0(actor);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(actor, state + 0x40, data & 0xFFFF,
                                           (data & 0xFFFF0000) >> 16);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808021D0_chevilspirit, actor->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800718_chevilspirit(Actor *actor, s32 gfx)
{
    s32 saved_flag;

    switch (func_800EB854()) {
        case 0:
        case 2:
            saved_flag = ((local_actor *) actor)->unk_0->unk_10_lsb;
            ((local_actor *) actor)->unk_0->unk_10_lsb = 0;
            func_80101808(actor, &func_801017D0);
            ((local_actor *) actor)->unk_0->unk_10_lsb = saved_flag;
            break;
        case 3:
            func_808007B4_chevilspirit(actor, gfx);
    }
}

// Draws the radar of nearby enemies.
void func_808007B4_chevilspirit(actor, gfx) Actor *actor;
Gfx **gfx;
{
    extern void func_800E253C(f32);
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 iter;
    s32 radar_pos[3];
    f32 player_pos[3];
    f32 unk_4[3];
    f32 rotation[3];
    s32 player;
    u8 *state;
    Actor *selected;
    Unk80132ED0 *selected_link;
    Actor *target;
    state = (u8 *) func_80100094(actor, 0);
    if (!func_800DB9B0()) {
        player = func_800F54E4();
        func_800F5A00(player, player_pos);
        func_8010FFB0(func_800F5EF8(player), unk_4, rotation);
        func_800A8A04(func_800A89F8(), &unk_0, &unk_1, &unk_2, &unk_3);
        radar_pos[0] = (unk_2 + unk_0 - 25) << 2;
        radar_pos[1] = (unk_3 + unk_1 - 21) << 2;
        func_800E253C(1.5f);
        func_800E257C((actor->alpha * 96) >> 8);
        func_800E2434(1);
        func_800E30E0(gfx, func_800D674C(0xB81), 0, radar_pos);
        func_800B9990(gfx);
        func_80800E20_chevilspirit(actor, gfx, radar_pos);
        selected = 0;
        if (*(s16 *) (state + 8) >= 2) {
            selected_link = ((Unk80132ED0 **) (state + 0xC))[*(s16 *) (state + 0xA)];
            if (selected_link && func_801069A4(selected_link)) {
                selected = (Actor *) func_80106790(selected_link);
            }
        }
        for (target = (Actor *) func_801067C4(&iter); target;
             target = (Actor *) func_8010682C(&iter)) {
            if (target->unk64_24) {
                func_80800A4C_chevilspirit(actor, gfx, radar_pos, player_pos, target, rotation[1],
                                           selected == target ? D_808022D8_chevilspirit
                                                                : D_808022DC_chevilspirit);
            }
        }
        target = (Actor *) _subaddielink_entrypoint_4(state);
        if (target) {
            func_80800A4C_chevilspirit(actor, gfx, radar_pos, player_pos, target, rotation[1],
                                       D_808022DC_chevilspirit);
        }
        func_80800A4C_chevilspirit(actor, gfx, radar_pos, player_pos, actor, rotation[1],
                                   D_808022D4_chevilspirit);
        gDPPipeSync((*gfx)++);
        gDPSetCycleType((*gfx)++, G_CYC_2CYCLE);
    }
}

void func_80800BFC_chevilspirit();

// Draws one radar blip if the actor is in range.
void func_80800A4C_chevilspirit(s32 actor, s32 gfx, f32 *center, f32 *player_pos,
                                Actor *target, f32 yaw, u8 *color)
{
    f32 delta[3];
    f32 dist;
    f32 angle;
    s16 offset[2];
    func_800EFB24(delta, player_pos, target->position);
    delta[1] = 0.0f;
    dist = delta[0] * delta[0] + delta[2] * delta[2];
    if (dist >= 4000000.0f) {
        return;
    }
    dist = sqrtf(dist);
    angle = func_80013B70(delta[0], delta[2], dist) - yaw;
    angle = func_800136E4(angle);
    color[3] = (u8) func_800F10B4(dist, 1600.0f, 2000.0f, 255.0f, 0.0f);
    if (color[3]) {
        dist *= 0.025f;
        offset[0] = (s16) (s32) (-func_800137F4(angle) * dist);
        offset[1] = (s16) (s32) (-func_80013788() * dist);
        func_80800BFC_chevilspirit(actor, gfx, center, offset, color);
    }
}

void func_80800BFC_chevilspirit(Actor *actor, Gfx **gfx, s32 *center, s16 *offset,
                                u8 *color)
{
    s32 x;
    s32 y;
    s32 alpha;

    x = (center[0] + offset[0]) & 0xFFFC;
    y = (center[1] + offset[1]) & 0xFFFC;
    gDPPipeSync((*gfx)++);
    alpha = (*((u8 *) actor + 0x9B) * color[3]) >> 8;
    gDPSetFogColor((*gfx)++, color[0] >> 2, color[1] >> 2, color[2] >> 2,
                   (alpha >> 1) + (alpha >> 2));
    TEXTURE_RECT48((*gfx)++, x - 8, y - 8, x + 8, y + 8);
    gDPPipeSync((*gfx)++);
    gDPSetFogColor((*gfx)++, color[0], color[1], color[2], alpha);
    TEXTURE_RECT48((*gfx)++, x - 4, y - 4, x + 4, y + 4);
}

// Matching: the line breaks in this function are needed for the match.
void func_80800E20_chevilspirit(actor, gfx, pos) u8 *actor; GfxW **gfx; u32 *pos;
{
    s32 x;
    s32 y;
    u32 state;

    state = (u32)*(u16 *)(actor + 0x72) >> 10;
    if (state != 1 && state != 2 && state != 3) {
        x = pos[0] & ~3;
        y = pos[1] & ~3;
        { GfxW *_g = (*gfx)++; _g->w0 = 0xE7000000; _g->w1 = 0; }
        { GfxW *_g = (*gfx)++; _g->w0 = 0xF8000000; _g->w1 = (((s32)(actor[0x9B] << 7) >> 8) & 0xFF) | ~0xFF; }
        { GfxW *_g = (*gfx)++; _g->w0 = (0xE4000000 | (((x + 8) & 0xFFF) << 12)) | ((y + 4) & 0xFFF); _g->w1 = (((x - 4) & 0xFFF) << 12) | (y & 0xFFF); }
        { GfxW *_g = (*gfx)++; _g->w0 = 0xE1000000; _g->w1 = 0; }
        { GfxW *_g = (*gfx)++; _g->w0 = 0xF1000000; _g->w1 = 0x01000100; }
        { GfxW *_g = (*gfx)++; _g->w0 = (0xE4000000 | (((x + 4) & 0xFFF) << 12)) | ((y + 8) & 0xFFF); _g->w1 = ((x & 0xFFF) << 12) | ((y - 4) & 0xFFF); }
        { GfxW *_g = (*gfx)++; _g->w0 = 0xE1000000; _g->w1 = 0; }
        { GfxW *_g = (*gfx)++; _g->w0 = 0xF1000000; _g->w1 = 0x01000100; }
    }
}

s32 func_80800F8C_chevilspirit(actor)
s32 actor;
{
    s32 i;
    s32 map = func_800EA05C();

if (func_800D3934() == 0) {
    return 0;
}

for (i = 0; i < 1; i++) {

if (map == D_808022E0_chevilspirit[i]) {
    return 0;
}

}
return 1;
}

s32 func_80800FF8_chevilspirit(s32 actor)
{
    s32 map = func_800EA05C();
    s32 i;
    for (i = 0; i < 2; i++) {
        if (map == D_808022E4_chevilspirit[i]) {
            return 1;
        }

}
return 0;
}

// Returns the link of the nearest enemy; if fill_list is set, also builds the sorted target list.
Unk80132ED0 *func_8080104C_chevilspirit(actor, fill_list)
Actor *actor;
s32 fill_list;
{
    extern s32 *func_800BE444(f32 *);
    extern EvilSpiritCubeEntry *func_800E9E88(s32);
    extern EvilSpiritCubeEntry *func_800E9EB4(s32);
    s32 *cube_ids;
    EvilSpiritTargetList *list;
    EvilSpiritCubeEntry *cube_entry;
    EvilSpiritCubeEntry *cube_end;
    Unk80132ED0 *link;
    Actor *enemy;
    f32 player_pos[3];
    Actor *nearest;
    f32 dist_sq;
    f32 nearest_dist_sq;
    s32 i;
    s32 j;
    Unk80132ED0 *swap;
    list = (EvilSpiritTargetList *) func_80100094(actor, 0);
    func_8010D254(player_pos);
    nearest = 0;
    nearest_dist_sq = 3.4028235e38f;
    cube_ids = func_800BE444(player_pos);
    list->count = 0;
    for (; *cube_ids; cube_ids++) {
        cube_entry = func_800E9E88(*cube_ids);
        cube_end = func_800E9EB4(*cube_ids);
        for (; cube_entry < cube_end; cube_entry++) {

if (cube_entry->flags & 1) {
    link = cube_entry->obj;
    if (*(u16 *) ((u8 *) link + 0x18) & 1) {
        enemy = (Actor *) func_80106790(link);
        if (enemy->unk64_24 && !func_801072A8(enemy)) {
            dist_sq = func_800EEB40(player_pos, enemy->position);

            if (dist_sq < func_800BDC5C() * func_800BDC5C()) {
                if (dist_sq < nearest_dist_sq) {
                    nearest = enemy;
                    nearest_dist_sq = dist_sq;
                }
                if (fill_list) {
                    list->targets[list->count] = link;
                    list->count++;
                }
            }
        }
    }
}

}
}
if (fill_list) {
    // Insertion sort of the collected links.
    for (i = 1; i < list->count; i++) {
        j = i;

while (j > 0 &&
       (s32) ((u32) *(u16 *) ((u8 *) list->targets[j] + 0x1A) >> 5) <
           (s32) ((u32) *(u16 *) ((u8 *) list->targets[j - 1] + 0x1A) >> 5)) {
    swap = list->targets[j];
    list->targets[j] = list->targets[j - 1];
    list->targets[j - 1] = swap;
    j--;
}

}
}
return nearest ? nearest->unk0 : 0;
}

int func_808012CC_chevilspirit(s32 actor)
{
    if (!func_8001210C(3) && !func_800C954C() && func_80801EC4_chevilspirit(actor)) {
        s32 target = func_8080104C_chevilspirit(actor, 0);
        if (target != 0 && func_80801988_chevilspirit(actor, target, 0) != 0) {
            func_80102424(actor, 5);

}
}
}

void func_80801344_chevilspirit(actor) u8 *actor;
{
    func_8008FE94(5, actor + 0x18);
    *(f32 *) (actor + 0x1C) += 100.0f;
    *(f32 *) (actor + 0x54) = func_80090010();
    func_808013DC_chevilspirit(actor);
}

void func_80801398_chevilspirit(Actor *actor)
{
    if (_subaddielink_entrypoint_4(func_80100094(actor, 0)) != 0) {
        func_80801458_chevilspirit(actor);
        func_808013DC_chevilspirit(actor);
    }
}

void func_808013DC_chevilspirit(actor) Actor *actor;
{
    actor->position[0] += 0.3f * (((f32 *) actor->actorData)[0] - actor->position[0]);
    actor->position[1] += 0.3f * (((f32 *) actor->actorData)[1] - actor->position[1]);
    actor->position[2] += 0.3f * (((f32 *) actor->actorData)[2] - actor->position[2]);
    func_80102BF8(actor, 0.2f, 15.0f, 1200.0f);
}

void func_80801458_chevilspirit(actor) Actor *actor;
{
    Actor *linked;
    linked = _subaddielink_entrypoint_4(func_80100094(actor, 0));
    func_8010105C(func_8010CD28(actor));
    if (func_8010108C(linked, 0x97, 0) <= 0) {
        func_800EE7F8((f32 *) &actor->actorData[0], linked->position);
        *(f32 *) &actor->actorData[1] +=
            linked->scale * (u32) *(u16 *) ((u8 *) linked + 0x6A) +
            *(f32 *) &actor->actorData[5];
    } else {
        func_80101038((f32 *) &actor->actorData[0]);
        func_800EF334((f32 *) &actor->actorData[0], linked->scale);
        func_800EF04C((f32 *) &actor->actorData[0], linked->position);
    }
    actor->unk54 = func_80101068();
}

int func_80801534_chevilspirit(Actor *actor)
{
    func_8008FE94(5, (u8 *) actor + 24);
    *(f32 *) ((char *) actor + 0x1C) += 100.0f;
    if (func_808015E0_chevilspirit(actor, 25.0f)) {
        func_80802090_chevilspirit(actor, &D_808022E8_chevilspirit);
        func_80102424(actor, 1);
    }
}

void func_808015A4_chevilspirit(s32 actor)
{
    func_80801458_chevilspirit();
    if (func_808015E0_chevilspirit(actor, 1e+02f) != 0) {
        func_80102424(actor, 6);
    }
}

s32 func_808015E0_chevilspirit(Actor *actor, f32 step)
{
    f32 unk_0[2];

    if (func_800EEB40(actor->position, (f32 *) actor->actorData) < step * step)
        return 1;
    func_800F18FC(actor->position, (f32 *) actor->actorData, unk_0);
    func_800EF214(actor->position, unk_0[0], unk_0[1], step);
    actor->unk54 = unk_0[1];
    func_80102BF8(actor, 0.2f, 15.0f, 1200.0f);
    return 0;
}

s32 func_80801684_chevilspirit(Actor *actor)
{
    EvilList *list;
    s32 *link;
    s32 link_id;
    s32 idx;
    s32 i;

    list = func_80100094(actor, 0);
    func_8080104C_chevilspirit(actor, 1);
    link = _subaddielink_entrypoint_4(func_80100094(actor, 0));
    if (link) {
        link_id = *link;
    } else {
        link_id = 0;
    }
    if (!link) {
        _subaddielink_entrypoint_0(func_80100094(actor, 0));
    }
    if (list->count >= 2) {
        idx = list->cur;
        while (idx >= list->count || list->ids[idx] == link_id) {
            if (idx >= list->count) {
                idx = 0;
            }

if (list->ids[idx] == link_id) {
    idx++;
}

}
list->cur = idx;
}
if (func_80016B54(1, 2) == 1 && list->count >= 2) {
    func_80801988_chevilspirit(actor, list->ids[list->cur], 0);
    list->cur = list->cur + 1;
    return 1;
}
for (i = 0; i < list->count; i++) {
    if (link_id != list->ids[i] && i == list->cur) {
        func_80801B00_chevilspirit(actor, func_80106790(list->ids[i]), 0x9DE);

// Matching: empty loop in an if (1) block, probably a stripped debug macro; 9 words differ without it.
if (1) {
    do {
    } while (0);
}

}
}
return 0;
}

int func_80801840_chevilspirit(actor)
Actor *actor;
{
    Actor *linked;
    linked = _subaddielink_entrypoint_2(func_80100094(actor, 0));
    if (!linked) {
        return 0;
    }
    linked = _subaddielink_entrypoint_4(func_80100094(actor, 0));
    if (!((*(u8 *) ((char *) (linked) + 0x64)) & 1)) {
        (*(u8 *) ((char *) (linked) + 0x64)) = (*(u8 *) ((char *) (linked) + 0x64)) & 0xFFDF;
        _subaddielink_entrypoint_0(func_80100094(actor, 0));
        func_8010108C(linked, 2, 0);
        return 0;
    }
    return 1;
}

int func_808018DC_chevilspirit(Actor *actor)
{
    Actor *linked;
    f32 player_pos[3];

    linked = _subaddielink_entrypoint_4(func_80100094(actor, 0));
    func_8010D254(player_pos);
    if (func_800EEB40(player_pos, linked->position) >
        (func_800BDC5C() + 300.0f) * (func_800BDC5C() + 300.0f)) {
        return func_80801A6C_chevilspirit(actor, 1);
    }
    return 1;
}

// Takes over the enemy behind target_link: stores the link and sets its joystick bit.
s32 func_80801988_chevilspirit(actor, target_link, skip_sound)
Actor *actor;
Unk80132ED0 *target_link;
s32 skip_sound;
{
    Actor *target;

    target = func_80106790(target_link);
    if (target_link == *(Unk80132ED0 **) func_80100094(actor, 0)) {
        return 1;
    }
    if (!func_80801A6C_chevilspirit(actor, 2)) {
        return 0;
    }
    _subaddielink_entrypoint_1(func_80100094(actor, 0), target_link);
    *(s32 *) ((u8 *) actor + 0x30) = 0;
    *(f32 *) ((u8 *) actor + 0x2C) = 0.0f;
    ((EvilSpiritActorFlags *) target)->joystick = 1;
    ((EvilSpiritActorFlags *) target)->controller = 1;
    if (skip_sound == 0) {
        func_80802090_chevilspirit(actor, D_808021E0_chevilspirit);
    }
    func_8010108C(target, 1, 0);
    return 1;
}

// Releases the linked enemy (message 2) unless message 0x46 returns > 0.
int func_80801A6C_chevilspirit(actor, arg)
s32 actor;
s32 arg;
{
    u8 *linked;

    if (func_80801840_chevilspirit() != 0) {
        linked = _subaddielink_entrypoint_4(func_80100094(actor, 0));
        if (func_8010108C(linked, 0x46, arg) > 0) {
            return 0;
        }
        (*(u8 *) ((s8 *) linked + 0x64)) = (u8) ((*(u8 *) ((s8 *) linked + 0x64)) & 0xFFDF);
        func_8010108C(linked, 2, 0);
        _subaddielink_entrypoint_0(func_80100094(actor, 0));
    }
    return 1;
}

void func_80801B00_chevilspirit(void *actor, Actor *target, s32 arg)
{
    f32 points[15][3];
    s32 i;
    s32 count;
    s32 unk_0;

    s32 unk_1 = ((u32) *(u16 *) ((u8 *) target->unk0 + 0x12) >> 1) & 3;
    if (func_8001210C(3) == unk_1) {
        count = _subaddievolume_entrypoint_0(target, points, 1, 15, (u8 *) actor + 0x30);
        if (count > 0) {
            unk_0 = func_800B53A4(count);
            func_800BA3FC(unk_0, arg);
            func_800BABB8(unk_0, NULL, NULL, 1.0f, D_808022F4_chevilspirit);
            for (i = 0; i < count; i++) {
                func_800BABB8(unk_0, points[i], NULL, 1.0f, NULL);
                func_800BA22C(unk_0, 1);
            }
        }
    }
}

void func_80801C04_chevilspirit(actor) Actor *actor;
{
    u8 *state;
    f32 marker[6];

    f32 *pos;

    state = func_80100094(actor, 0);
    _susubgame_entrypoint_0(actor, state + 0x40, 0);
    _susubgame_entrypoint_12((state + 0x40), D_808021D0_chevilspirit);
    if (!_subaddielink_entrypoint_3(func_80100094(actor, 0)) && actor->unk70_10 != 1 &&
        actor->unk70_10 != 2 && actor->unk70_10 != 3) {
        func_80102424(actor, 8);
    }
    // Spiral Mountain.
    if (func_800EA05C() == 0xAF) {
        _subaddiemarker_entrypoint_1(actor, 0x154, 0x32, marker, 1);
        if (!func_800D3934()) {
            // Tower of Tragedy finished: the actor is deleted.
            if (func_800DA298(0x3B)) {
                func_800FFAB0(actor);
                return;
            }
            func_800EE7F8(actor->position, marker);
            actor->rotation[1] = marker[4];
            func_80103140(actor, 0x90E, actor->unk0->unk16);
            func_80102424(actor, 0xD);
        } else if (!func_800DA298(0xCA)) { // talk not done yet
            pos = actor->position;
            func_800EE7F8(pos, marker);
            actor->rotation[1] = marker[4];
            func_80103140(actor, 0x90E, actor->unk0->unk16);
            func_80102424(actor, 9);
            func_800F82D4(func_800F54E4(), 1);
            _susubgame_entrypoint_6(actor, (state + 0x40), 8, 0x20, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x15C5, 6, pos, 0xBB);
        }
    }
    if (func_800BF8E4() && !func_80800FF8_chevilspirit(actor)) {
        ((f32 *) actor->actorData)[7] = 0.0f;
        actor->actorData[3] = func_800C8A98();
        func_800C8E54(actor->actorData[3], 150.0f, 450.0f);
        func_80801E18_chevilspirit(actor);
    } else
        actor->actorData[3] = 0;
}

void func_80801E18_chevilspirit(actor) Actor *actor;
{
    f32 color[3];
    f32 pos[3];
    f32 phase;
    f32 blend;

    if (actor->actorData[3]) {
        phase = func_800F0F9C(*(f32 *) &actor->actorData[7], 0.5f);
        blend = func_800F3780(phase, D_80802338_chevilspirit, 3);
        func_80103DFC(actor, pos);
        func_800F3214(color, D_80802320_chevilspirit, D_8080232C_chevilspirit, blend);
        func_800C8CB8(actor->actorData[3], pos);
        func_800C8E84(actor->actorData[3], color);
        *(f32 *) &actor->actorData[7] += func_800D8FF8();
    }
}

s32 func_80801EC4_chevilspirit(actor)
s32 actor;
{
    s32 player;
    player = func_800F54E4();
    if (func_800F6D24(player) != 0) {
        return 0;
    }
    if (func_800F8004(player) != 0) {
        return 0;
    }
    return 1;
}

void func_80801F1C_chevilspirit(actor, dialog_id, arg) Actor *actor;
s32 dialog_id;
s32 arg;
{
    u8 *state;

    state = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x15C5:
            func_80802090_chevilspirit(actor, (s16 *) D_80802350_chevilspirit);
            func_80102424(actor, 0xA);
            _subaddiefade_entrypoint_5(actor);
            break;
        case 0x15CB:
            func_80102424(actor, 8);
            _susubgame_entrypoint_4(actor, state + 0x40);
            func_800F82D4(func_800F54E4(), 0);
            _plcamera_entrypoint_8(func_800F54E4());
            func_800DA544(0xCA);
            break;
        case 0x15C6:
        case 0x15C7:
        case 0x15C8:
        case 0x15C9:
            func_80102424(actor, 0xD);
            actor->unk58 = func_800DC178(5.0f, 8.0f);
    }
}

void func_80802024_chevilspirit(actor, dialog_id, arg) s32 actor;
s32 dialog_id;
s32 arg;
{
    s32 state;

    state = func_80100094(actor, 0);
    if ((func_800C07F4() == 0) && (dialog_id == 0x15C5) && (arg == 1)) {
        _susubgame_entrypoint_6(actor, state + 0x40, 5, 0x20, 0);
    }
}

// Plays the sound script on the actor, creating its audio handle first if needed.
void func_80802090_chevilspirit(Actor *actor, s16 *script)
{
    u8 sound;

    sound = actor->unk5F;
    if (sound == 0) {
        actor->unk5F = _subaddieaudioquick_entrypoint_1(actor, actor->position);
        func_800C330C(actor->unk5F, 3);
        sound = actor->unk5F;
    }
    func_800C3058(sound, 0x55F0);
    func_800C31DC(actor->unk5F, 1.0f);
    func_800C4350(actor->unk5F, actor->position, script);
    func_800C3BDC(actor->unk5F);
}

void func_80802118_chevilspirit(u8 *actor)
{
    if ((((u8 *) actor)[0x5F] != 0) &&
        (func_800C3D78(((u8 *) actor)[0x5F] & 0xFF, ((u8 *) actor)[0x5F]) == 0)) {
        func_800C2FDC(((u8 *) actor)[0x5F]);
        ((u8 *) actor)[0x5F] = 0U;
    }
}

// TU-NOTE: the overlay's .data is defined here in C (values from the ROM). Its tables point to
// functions of this file, and IDO's assembler schedules some of them differently unless the
// tables are in the same unit. D_808022E2_chevilspirit = D_808022E0_chevilspirit + 0x2
// (linker symbol in undefined_syms.us.txt).
extern void func_80105834();
extern void func_80107C2C();
u8 D_808021D0_chevilspirit[16] = {0x43, 0x7, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0,
                                  0x43, 0x7, 0x0, 0x0, 0x42, 0x20, 0x0, 0x0};
s16 D_808021E0_chevilspirit[6] = {0x13, 0x4EA, 0xD, 0xF3, 0x10C, 0x0};
s16 D_808021EC_chevilspirit[6] = {0x13, 0x4EB, 0xD, 0xF3, 0x10C, 0x0};
u32 D_808021F8_chevilspirit[30] = {
    0x0,        0x0,       0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001,
    0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001,
    0x40A00000, 0x49B0001, 0x40A00000, 0x3EF0001, 0x40A00000, 0x3EF0001, 0x40A00000, 0x49B0001,
    0x40A00000, 0x49B0001, 0x40A00000, 0x3EF0001, 0x40A00000, 0x3EF0001};
void *D_80802270_chevilspirit = (void *) 0x018A0153;
static u32 D_80802270_chevilspirit_rest[17] = {0x90F0001,
                                               (u32) &D_808021F8_chevilspirit,
                                               (u32) func_80800104_chevilspirit,
                                               (u32) func_80105834,
                                               (u32) func_80800718_chevilspirit,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x8001100,
                                               (u32) func_808005B4_chevilspirit,
                                               0x0,
                                               0x580000,
                                               (u32) func_8080000C_chevilspirit,
                                               (u32) func_80107C2C,
                                               0x80000402,
                                               (u32) func_808005EC_chevilspirit,
                                               0x0};
s16 D_808022B8_chevilspirit[8] = {0x13, 0x4EE, 0x1B, 0xD, 0xF3, 0x10C, 0x0, 0x0};
s16 D_808022C8_chevilspirit[6] = {0x13, 0x4ED, 0xD, 0xF3, 0x10C, 0x0};
u8 D_808022D4_chevilspirit[4] = {0xFF, 0x0, 0x0, 0xFF};
u8 D_808022D8_chevilspirit[4] = {0xFF, 0xFF, 0x0, 0xFF};
u8 D_808022DC_chevilspirit[4] = {0xFF, 0xFF, 0xFF, 0xFF};
u16 D_808022E0_chevilspirit[2] = {0x15F, 0x0};
u16 D_808022E4_chevilspirit[2] = {0x15F, 0xAF};
u8 D_808022E8_chevilspirit[12] = {0x0, 0x13, 0x4, 0xEC, 0x0, 0xD, 0x1, 0x26, 0x1, 0x40, 0x0, 0x0};
u8 D_808022F4_chevilspirit[44] = {0x0,  0x15, 0x0, 0x19, 0x0,  0x99, 0x0,  0x22, 0x0, 0x28, 0x0,
                                  0x33, 0x0,  0xF, 0x0,  0x14, 0x0,  0x16, 0x10, 0x0, 0x0,  0x2B,
                                  0x0,  0x33, 0x0, 0x66, 0x0,  0x2C, 0x0,  0x0,  0x0, 0x46, 0x0,
                                  0x0,  0x0,  0x0, 0x0,  0x5A, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0};
f32 D_80802320_chevilspirit[3] = {3.57e-43f, 1.35e-43f, 4.5e-44f};
f32 D_8080232C_chevilspirit[3] = {3.57e-43f, 1.8e-43f, 4.5e-44f};
f32 D_80802338_chevilspirit[6] = {0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f};
u8 D_80802350_chevilspirit[16] = {0x0, 0x13, 0x4, 0xEE, 0x0, 0xD, 0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
