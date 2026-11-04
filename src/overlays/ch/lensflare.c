// Sun lens flare actor: checks that the map has a flare and an active sky, registers a z-buffer
// occlusion probe and draws the flare while the sun point is visible.
#include "common.h"

typedef struct {
    s32 map_id;
    s32 flare_table;
} LensFlareMap59;
extern LensFlareMap59 D_808008F0_chlensflare[];
extern int D_80800928_chlensflare[];
extern void func_800EFA88();
typedef struct {
    u32 r : 8;
    u32 g : 8;
    u32 b : 8;
    u32 a : 8;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 pad_D[3];
} FlareElem;
typedef struct {
    FlareElem *elems;
    s32 unk_4;
} FlareDef;
extern FlareDef D_808008F4_chlensflare[];
extern s32 func_800BFFB4(s32, s32, f32 *);
extern void func_800E8830(s32, f32 *);
extern s32 func_800E88AC(s32, f32 *);
extern f32 mlAbsF(f32);
extern void func_800E40DC(f32, f32, f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800B99CC(Gfx **, s32, f32 *);
extern void func_800E2588(s32);
extern void func_800E24F8(s32, s32, s32);
extern s32 func_800D674C(s32);
extern void func_800E2594(Gfx **, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800E3980(f32 *);
extern f32 func_800EEFD4(f32 *);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800E2530(f32);
extern void func_800E2720(Gfx **, s32, s32, f32 *, f32 *, s32);
extern void func_800E2A14(Gfx **);
typedef struct {
    u8 pad_0[0x24];
    s32 flare_index;
    u8 pad_28[0xC];
    f32 occlusion;
    u8 pad_38[0x18];
    u8 probe_id;
    u8 pad_51[0x13];
    u32 pad_64_21 : 11;
    u32 unk_64_20 : 1;
    u32 pad_64_0 : 20;
} LensFlare;
extern void func_80105834(), func_80107C2C(), func_80800084_chlensflare();

// Called by su/autobaddies: 1 if the current map is in the map table and the sky is active.
s32 chlensflare_entrypoint_0(void)
{
    s32 i = 0;
    s32 map;

    map = func_800EA05C();
    if (!_gcskyDll_entrypoint_3())
        return 0;
    for (; D_808008F0_chlensflare[i].map_id != -1; i++) {
        if (map == D_808008F0_chlensflare[i].map_id)
            return 1;
    }
    return 0;
}

// Init: look up the current map in the table and store its index.
void func_80800084_chlensflare(actor) Actor *actor;
{
    s32 cur_map;
    s32 index;
    LensFlareMap59 *entry;
    cur_map = func_800EA05C();
    entry = D_808008F0_chlensflare;
    index = 0;
    while (1) {
        if (entry->map_id == -1) {
            func_800FFAB0(actor);
            return;
        }
        if (cur_map == entry->map_id) {
            actor->actorData[3] = index;
            break;
        }
        entry++;
        index++;
    }
    *(f32 *) &actor->actorData[7] = 1.01f;
}

// Draw: fade the flare by the sun's screen distance and occlusion, then draw its elements.
void func_808000FC_chlensflare(LensFlare *flare, Gfx **gfx)
{
    f32 unk_0[3];
    f32 unk_1[3];
    f32 unk_2[3];
    f32 screen_pos[2];
    f32 fade;
    FlareElem *elems;
    FlareElem *end_elem;
    s32 i;
    f32 color[3];
    f32 elem_pos[3];
    s32 alpha;
    f32 unk_3[3];
    f32 unk_4[3];
    s32 prev_alpha;

    if (!func_800BFFB4(0, 4, unk_0)) {
        return;
    }
    func_800E8830(flare->probe_id, unk_0);
    if (func_800E88AC(flare->probe_id, screen_pos) == 1 || flare->unk_64_20) {
        fade = (mlAbsF(screen_pos[0] - 152.0f) * mlAbsF(screen_pos[0] - 152.0f) +
                mlAbsF(screen_pos[1] - 114.0f) * mlAbsF(screen_pos[1] - 114.0f)) /
               19602.0f;
        if (flare->occlusion < fade) {
            flare->occlusion *= 1.35f;
            if (fade < flare->occlusion) {
                flare->occlusion = fade;
            } else {
                fade = flare->occlusion;
            }
        } else {
            flare->occlusion /= 1.35f;
            if (flare->occlusion < fade) {
                flare->occlusion = fade;
            } else {
                fade = flare->occlusion;
            }
        }
    } else {
        if (flare->occlusion < 1.01f) {
            flare->occlusion *= 1.35f;
        }
        if (1.0f < flare->occlusion) {
            flare->occlusion = 1.01f;
            return;
        }
        fade = flare->occlusion;
    }
    if (1.0f < fade) {
        return;
    }
    screen_pos[0] = 304.0f - screen_pos[0];
    screen_pos[1] = 228.0f - screen_pos[1];
    func_800E40DC(screen_pos[0], screen_pos[1], unk_1, unk_2);
    func_800EFB24(unk_2, unk_1, unk_0);
    elems = D_808008F4_chlensflare[flare->flare_index].elems;
    for (i = 0; elems[i].unk_C != 0; i++) {
    }
    end_elem = (FlareElem *) ((u8 *) elems + i * 16);
    if (end_elem->r) {
        func_800EFA88(color, end_elem->r, end_elem->g, end_elem->b);
        func_800B99CC(gfx, end_elem->a * (1 - fade), color);
    }
    prev_alpha = 0;
    func_800E2588(0);
    func_800E24F8(elems->r, elems->g, elems->b);
    func_800E2594(gfx, func_800D674C(0x9D2));
    for (i = 0; elems[i].unk_C != 0; i++) {
        alpha = elems[i].a * (1.0f - fade);
        if (alpha == prev_alpha) {
            alpha++;
        }
        prev_alpha = alpha;
        func_800E24F8(elems[i].r, elems[i].g, elems[i].b);
        func_800EFA4C(unk_1, elems[i].unk_4 + fade, elems[i].unk_4 + fade,
                      elems[i].unk_4 + fade);
        func_800EE7F8(elem_pos, unk_0);
        func_800EF174(elem_pos, unk_2, elems[i].unk_8);
        func_800E3980(unk_4);
        func_800EFB24(unk_3, elem_pos, unk_4);
        if (400000000.0f < func_800EEFD4(unk_3)) {
            func_800EFA98(unk_3, unk_3, 20000.0f);
            func_800EE780(elem_pos, unk_4, unk_3);
        }
        switch (elems[i].unk_C) {
            case 1:
                func_800E2530(0.0f);
                func_800E2720(gfx, 0, 0, elem_pos, unk_1, alpha);
                break;
            case 2:
                func_800E2530(45.0f);
                func_800E2720(gfx, 0, 0, elem_pos, unk_1, alpha);
                break;
            case 3:
                func_800E2720(gfx, 1, 0, elem_pos, unk_1, alpha);
        }
    }
    func_800E2A14(gfx);
    flare->unk_64_20 = 0;
}

// Message 0x95 registers the z-buffer occlusion probe.
int func_80800634_chlensflare(actor, msg, unk_2)
s32 *actor;
s32 msg;
s32 unk_2;
{
    if (msg == 0x95) {
        *(u8 *) ((char *) actor + 0x50) = func_800E8714(0);
        return 1;
    }
    return 0;
}

int *chlensflare_entrypoint_1()
{
    return &D_80800928_chlensflare;
}

// TU-NOTE: the .data of this overlay is defined here in C, values taken from the ROM.
// Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
// functions differently unless the tables are defined in the same unit.
// D_808008F4_chlensflare = D_808008F0_chlensflare + 0x4 is a linker symbol in undefined_syms.us.txt.
// The extern of D_80800928_chlensflare is declared int[] to match the object.
u32 D_808006B0_chlensflare[32] = {
    0xFFFF64C8, 0x40000000, 0x3F000000, 0x1000000, 0xC8B43CB4, 0x3FC00000, 0x3F19999A, 0x2000000,
    0xFFFF64C8, 0x40000000, 0x3F333333, 0x3000000, 0xC8B43CB4, 0x3FC00000, 0x3F4CCCCD, 0x2000000,
    0xC8E646C8, 0x3F800000, 0x3F666666, 0x3000000, 0xB4E6E6B4, 0x3F4CCCCD, 0x3F733333, 0x1000000,
    0xB4E6E6B4, 0x3F4CCCCD, 0x3F7AE148, 0x2000000, 0xFFEBEB6E, 0x0,        0x0,        0x0};
u32 D_80800730_chlensflare[28] = {
    0xFFFF64C8, 0x40000000, 0x3F000000, 0x1000000,  0xC8B43CB4, 0x3FC00000, 0x3F19999A,
    0x2000000,  0xFFFF64C8, 0x40000000, 0x3F333333, 0x3000000,  0xC8B43CB4, 0x3FC00000,
    0x3F4CCCCD, 0x2000000,  0xC8E646C8, 0x3F800000, 0x3F666666, 0x3000000,  0xB4E6E6B4,
    0x3F4CCCCD, 0x3F733333, 0x1000000,  0xFFEBEB6E, 0x0,        0x0,        0x0};
u32 D_808007A0_chlensflare[24] = {
    0xFFE6A0E6, 0x40000000, 0x3F333333, 0x1000000, 0xE6E6A0C8, 0x40000000, 0x3F4CCCCD, 0x2000000,
    0xC8C8E6D2, 0x40000000, 0x3F666666, 0x3000000, 0xF0B4B4DC, 0x40000000, 0x3F733333, 0x1000000,
    0xF0DCA0D2, 0x40000000, 0x3F7851EC, 0x2000000, 0xFFFFE678, 0x0,        0x0,        0x0};
u32 D_80800800_chlensflare[32] = {
    0xFFFF6400, 0x40000000, 0x3F000000, 0x1000000, 0xFAFA64B4, 0x3F9AE148, 0x3E99999A, 0x2000000,
    0xFFFF32B4, 0x3F87AE14, 0x3F000000, 0x1000000, 0xFFFF32AA, 0x3FA00000, 0x3F333333, 0x2000000,
    0xFFFF506E, 0x3F800000, 0x3F75C28F, 0x3000000, 0xBEE6E600, 0x3F4CCCCD, 0x3F733333, 0x1000000,
    0xB4E6E600, 0x3F4CCCCD, 0x3F7AE148, 0x1000000, 0xFFFFB450, 0x0,        0x0,        0x0};
u32 D_80800880_chlensflare[28] = {
    0xFFFFA0CD, 0x3F666666, 0x3F19999A, 0x3000000,  0xFFFF647D, 0x3F8147AE, 0x3F400000,
    0x2000000,  0xFFFF9696, 0x3F8E147B, 0x3F68F5C3, 0x3000000,  0xFFFFC8E6, 0x3F8147AE,
    0x3F75C28F, 0x1000000,  0xC8E64600, 0x3F800000, 0x3F666666, 0x3000000,  0xAAE6E600,
    0x3F4CCCCD, 0x3F733333, 0x1000000,  0xFFFF9B64, 0x3F35C28F, 0x0,        0x0};
LensFlareMap59 D_808008F0_chlensflare[7] = {
    0xB8,  (u32) &D_80800730_chlensflare, 0x100, (u32) &D_80800800_chlensflare,
    0x136, (u32) &D_80800880_chlensflare, 0x161, (u32) &D_80800880_chlensflare,
    0xA7,  (u32) &D_80800880_chlensflare, 0x1A7, (u32) &D_808007A0_chlensflare,
    -0x1,  (u32) &D_808006B0_chlensflare};
int D_80800928_chlensflare[18] = {0x11703FE,
                                  -0xFFFF,
                                  0x0,
                                  0x0,
                                  (u32) func_80105834,
                                  (u32) func_808000FC_chlensflare,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x20400,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80800084_chlensflare,
                                  (u32) func_80107C2C,
                                  -0x7FFFFBFE,
                                  (u32) func_80800634_chlensflare,
                                  0x0};
