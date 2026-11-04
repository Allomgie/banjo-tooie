// Player shadow: a blob shadow and a real-time projected shadow rendered to an offscreen image,
// plus the shadow actor (init, update, draw gate) and the setters the player model code uses.
#include "common.h"

#define A6250_CMD(head, first, second)                                                             \
    {                                                                                              \
        A6250Command *local_command = (*(head))++;                                                 \
        local_command->word0 = (first);                                                            \
        local_command->word1 = (second);                                                           \
    }
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void *func_800D674C(s32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern f32 func_800F554C(s32);
extern int func_800F1988(f32 *, f32 *, f32 *);
extern void func_800DF830(s32);
extern Gfx D_8011A2F8[];
extern Gfx D_8011A350[];
struct __OSBlockInfo {
    u32 field0;
    u32 field4;
    u32 field8;
    u32 fieldC;
};
extern struct __OSBlockInfo D_8011A380;
extern struct __OSBlockInfo D_8011A390;
extern void func_800DF580(struct __OSBlockInfo *, struct __OSBlockInfo *);
typedef struct {
    u32 word0, word1;
} A6250Command;
extern s32 func_800F53D0(u32);
extern s32 func_800F5410(u32);
extern s32 _bapreload_entrypoint_1(s32, s32 *);
extern void *func_80092B04(s32, s32);
extern void func_800F274C(f32[4][4]);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_80013A7C(f32);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800F254C(f32[4][4], f32 *, f32);
extern void func_800F23D0(f32[4][4], f32 *, f32 *);
extern void func_80019CD4(void);
extern f32 func_80092BE8(s32);
extern f32 func_8009BFCC(s32);
extern f32 baroll_get(s32);
extern void mlMtxRotYaw(f32);
extern void mlMtxRotPitch(f32);
extern void mlMtxRotRoll(f32);
extern void mlMtxGet(f32[4][4]);
extern void func_800F27D4(f32[4][4], f32[4][4], f32[4][4]);
extern void *func_8008CA74(s32);
extern void func_800DF41C(void *);
extern void **func_800DF330(void);
extern void *func_800B27E0(void *);
extern void *func_80092E80(s32);
extern void func_800AE708(void *, void *, void **, void *);
extern void func_800DF72C(void *);
extern void func_800A06E8(s32);
extern void func_800DF540(f32[4][4]);
extern A6250Command **func_800A7180(void);
extern void *func_8001575C(void);
extern f32 func_80092BDC(s32);
extern s32 func_80092738(s32);
extern void _babackpack_entrypoint_2(s32);
extern f32 _babackpack_get_scale(s32);
extern void *_babackpack_entrypoint_1(s32);
extern void func_800E7CF4(A6250Command **);
extern void *func_800B2840(void *);
extern f32 func_800B2354(void *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800E4190(f32 *, f32 *, s32 *);
extern s32 func_800C6A7C(s32 *param_0, s32 *param_1, f32 *param_2, s32 param_3);
extern void func_800EE7F8();
extern void func_800F5680(s32 param_0, f32 *param_1);
extern f32 mlAbsF(f32 param_0);
extern void func_800EF174();
typedef struct {
    u8 pad_0[0x7E];
    u8 unk_7E_a : 3;
    u8 unk_7E_b : 1;
    u8 unk_7E_c : 4;
} Struct800A69F0;
typedef struct {
    s32 pad_0;
    f32 pos[3];
    u8 pad_10[0x14];
    f32 floor_y;
    u8 pad_28[0x4E];
    u16 owner_bits;
} ActorA6B24;
extern f32 func_800F5BC4(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EFD24(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800C8760(s32, s32);
extern void *func_800C878C(void *, s32, s32);
extern s32 func_800C89A8(void *);
extern void func_800C8800(void *, f32 *);
extern void func_800C8898(void *, f32 *);
typedef struct {
    u8 pad[0x58];
    f32 scale;
    u8 pad1[0x18];
    u32 unk_74 : 2, blocked : 1, pad_74 : 29;
} LocalActor;
extern s16 D_8011A2E0[];
typedef struct {
    u8 pad0[4];
    f32 pos[3];
    u8 pad10[0x14];
    f32 floor_y;
    u8 pad28[0x3C];
    u32 pad64 : 11;
    u32 flag64 : 1;
    u32 pad64b : 20;
    u8 pad68[0xC];
    u32 pad74 : 1;
    u32 flag74_1 : 1;
    u32 flag74_2 : 1;
    u32 pad74b : 13;
    u16 owner_idx : 9;
    u16 pad76 : 7;
} S800A6FF0;
extern void func_800F5A00(s32, f32 *);
extern f32 func_800F5628(s32);
extern s32 func_800F8874(s32);
typedef struct {
    u8 pad0[0x65];
    u8 unk_65 : 7;
    u8 enabled : 1;
    u8 pad66[0x10];
    u16 owner_idx : 9;
    u16 unk_76 : 7;
} S_A70D0;
extern S_A70D0 *func_80106790(s32);
extern s32 D_8011A3A0[];

// Blob and projected (render-to-texture) shadow drawing, light-based shadow direction.
// Cheap blob shadow: model 0x637 scaled by the height above the floor.
void func_800A5DB0(u8 *shadow)
{
    s32 unk_0;
    f32 pos[3];
    f32 rot[3];
    f32 scale;
    f32 floor_y;
    f32 floor_normal[3];
    f32 height_scale;
    func_800EE7F8(pos, (f32 *) (shadow + 4));
    floor_y = *(f32 *) (shadow + 0x24);
    height_scale = func_800F10B4(pos[1] - floor_y, 0.0f, 300.0f, 0.43f, 0.28f);
    scale = func_800F554C((u32) *(u16 *) (shadow + 0x76) >> 7);
    scale *= height_scale * *(f32 *) (shadow + 0x58);
    pos[1] = floor_y;
    func_800F5680((u32) *(u16 *) (shadow + 0x76) >> 7, floor_normal);
    func_800F1988(floor_normal, (f32 *) (shadow + 0x44), (f32 *) (shadow + 0x48));
    rot[0] = *(f32 *) (shadow + 0x44);
    rot[1] = *(f32 *) (shadow + 0x48);
    rot[2] = 0.0f;
    func_800EF334(floor_normal, 0);
    func_800EE780((f32 *) (shadow + 4), pos, floor_normal);
    func_800DF830(3);
    func_800DE448((f32 *) (shadow + 4), rot, scale, 0, (s32) func_800D674C(0x637));
}

// Blits a rectangle of the offscreen shadow image to the screen with alpha, in texrect strips.
// Matching: the line breaks in this function are needed for the match.
void func_800A5EC4(Gfx **gfx, void *image, s32 x, s32 y, s32 width, s32 height, s32 alpha)
{
    Gfx *dl;
    s32 strip_h;
    s32 y_end;

    dl = *gfx;
    if (width) {
        width = (width + 15) & 0xFFF0;
        if (height) {
            strip_h = 4096 / width;
            do {
                { Gfx *_g = dl++; _g->words.w0 = 0xDE000000; _g->words.w1 = (u32)((u8 *)D_8011A2F8 - 0x80000000); } { Gfx *_g = dl++; _g->words.w0 = 0xF9000000; _g->words.w1 = 1; }
                { Gfx *_g = dl++; _g->words.w0 = 0xFA000000; _g->words.w1 = ((alpha << 7) / 255) & 0xFF; }
            } while (0);
            y_end = y + height;
            { Gfx *_g = dl++; _g->words.w0 = 0xFD48012F; _g->words.w1 = osVirtualToPhysical(image); }
            { Gfx *_g = dl++; _g->words.w0 = 0xF5480000 | ((((width + 7) >> 3) & 0x1FF) << 9); _g->words.w1 = 0x07080200; }
            { Gfx *_g = dl++; _g->words.w0 = 0xF5480000 | ((((width + 7) >> 3) & 0x1FF) << 9); _g->words.w1 = 0x00080200; }
            for (; y < y_end; y += strip_h) {
                if (y_end - y < strip_h) {
                    strip_h = y_end - y;
                }
                { Gfx *_g = dl++; _g->words.w0 = 0xE6000000; _g->words.w1 = 0; } { Gfx *_g = dl++; _g->words.w0 = 0xF4000000 | (((x << 2) & 0xFFF) << 12) | ((y << 2) & 0xFFF); _g->words.w1 = (7 << 24) | ((((x + width - 1) << 2) & 0xFFF) << 12) | (((y + strip_h - 1) << 2) & 0xFFF); } { Gfx *_g = dl++; _g->words.w0 = 0xF2000000 | (((x << 2) & 0xFFF) << 12) | ((y << 2) & 0xFFF); _g->words.w1 = (0 << 24) | ((((x + width - 1) << 2) & 0xFFF) << 12) | (((y + strip_h - 1) << 2) & 0xFFF); }
                { Gfx *_g = dl++; _g->words.w0 = 0xE4000000 | ((((x + width) * 4) & 0xFFF) << 12) | (((y + strip_h) * 4) & 0xFFF);
                    _g->words.w1 = (((x * 4) & 0xFFF) << 12) | ((y * 4) & 0xFFF); }
                { Gfx *_g = dl++; _g->words.w0 = 0xE1000000; _g->words.w1 = (((x << 5) & 0xFFFF) << 16) | ((y << 5) & 0xFFFF); }
                { Gfx *_g = dl++; _g->words.w0 = 0xF1000000; _g->words.w1 = 0x04000400; }
            }
            { Gfx *_g = dl++; _g->words.w0 = 0xDE000000; _g->words.w1 = (u32)((u8 *)D_8011A350 - 0x80000000); }
            *gfx = dl;
        }
    }
}

void func_800A61D4(void)
{
    struct __OSBlockInfo unk_0 = D_8011A380;
    struct __OSBlockInfo unk_1 = D_8011A390;
    func_800DF580(&unk_0, &unk_1);
    func_800DF830(3);
}

// Renders the projected shadow of the player (and backpack) into the offscreen image, then blits its screen bounds.
void func_800A6250(u8 *shadow, f32 *pos, f32 *normal, f32 *light_dir, s32 alpha)
{
    f32 proj[4][4];
    f32 rot_mtx[4][4];
    s32 owner;
    void *model;
    void *base_model;
    f32 dot;
    s32 unk_0;
    f32 angle;
    f32 axis[3];
    union {
        f32 matrix[4][4];
        u64 alignment;
    } tilt;
    void **unk_1;
    void *base_data;
    void *model_data;
    s32 i, j, k;

    owner = func_800F53D0((u32) *(u16 *) (shadow + 0x76) >> 7);
    // Matching: kept as a separate call; nesting it creates a hidden stack temp.
    i = func_800F5410((u32) *(u16 *) (shadow + 0x76) >> 7);
    model = func_800D674C(_bapreload_entrypoint_1(i, &unk_0));
    base_model = func_80092B04(owner, 0);
    func_800F274C(proj);
    dot = func_800EEAA4(light_dir, normal);
    // Reject a degenerate direction; limit shallow angles.
    if (dot < 0.01f)
        return;
    if (dot < 0.4f) {
        angle = func_80013A7C(0.4f);
        func_800EE97C(axis, normal, light_dir);
        func_800F254C(tilt.matrix, axis, angle);
        func_800F23D0(tilt.matrix, light_dir, normal);
        dot = func_800EEAA4(light_dir, normal);
    }
    // Oblique projection onto the floor: I - normal * light_dir^T / dot.
    dot = 1.0f / dot;
    proj[0][0] = 1.0f - normal[0] * light_dir[0] * dot;
    proj[0][1] = -normal[0] * light_dir[1] * dot;
    proj[0][2] = -normal[0] * light_dir[2] * dot;
    proj[1][0] = -normal[1] * light_dir[0] * dot;
    proj[1][1] = 1.0f - normal[1] * light_dir[1] * dot;
    proj[1][2] = -normal[1] * light_dir[2] * dot;
    proj[2][0] = -normal[2] * light_dir[0] * dot;
    proj[2][1] = -normal[2] * light_dir[1] * dot;
    proj[2][2] = 1.0f - normal[2] * light_dir[2] * dot;
    func_80019CD4();
    mlMtxRotYaw(func_80092BE8(owner));
    mlMtxRotPitch(func_8009BFCC(owner));
    mlMtxRotRoll(baroll_get(owner));
    mlMtxGet(rot_mtx);
    func_800F27D4(rot_mtx, proj, proj);
    // Select or transfer render data when the model differs from the base model.
    if (model != base_model) {
        if (unk_0)
            func_800DF41C(func_8008CA74(owner));
        else {
            unk_1 = func_800DF330();
            base_data = func_800B27E0(base_model);
            model_data = func_800B27E0(model);
            if (*unk_1) {
                func_800AE708(func_80092E80(owner), base_data, unk_1, model_data);
                func_800DF72C(*unk_1);
            }
        }
    } else
        func_800DF72C(func_80092E80(owner));
    func_800A06E8(owner);
    func_800DF540(proj);
    func_800A61D4();
    {
        A6250Command **dl;
        dl = func_800A7180();
        // Pipe sync, select the offscreen image as color image, set up the fill pass.
        A6250_CMD(dl, 0xE7000000, 0);
        A6250_CMD(dl, 0xFF48012F, (u32) func_8001575C() + 0x80000000);
        A6250_CMD(dl, 0xE3000800, 0);
        A6250_CMD(dl, 0xE3000A01, 0x00300000);
        A6250_CMD(dl, 0xF7000000, 0xFFFEFFFE);
        A6250_CMD(dl, 0xE200001C, 0);
        A6250_CMD(dl, 0xF64BC38C, 0);
        func_800DE448(pos, 0, func_80092BDC(owner), 0, model);
        // Render the optional backpack through the same projection.
        if (func_80092738(owner)) {
            _babackpack_entrypoint_2(owner);
            func_800DF540(proj);
            func_800A61D4();
            func_800DE448(pos, 0, _babackpack_get_scale(owner), 0,
                          _babackpack_entrypoint_1(owner));
        }
    }
    {
        A6250Command **dl;
        dl = func_800A7180();
        A6250_CMD(dl, 0xE7000000, 0);
        func_800E7CF4(dl);
        {
            f32 corners[8][3];
            f32 screen[8][2];
            s32 idx;
            f32 screen_min[2];
            f32 screen_max[2];
            f32 val;
            f32(*unk_2)[2]; // Matching: unused local keeps the stack layout.
            f32 radius;
            s32 min_px[2];
            s32 max_px[2];
            s32 unk_3; // Matching: unused local keeps the visibility output at sp+0x50.
            s32 valid;
            // Eight corners of the model bounds: x/z span +/-radius, y spans 0..radius.
            radius = func_800B2354(func_800B2840(model)) * func_80092BDC(owner);
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 2; j++) {
                    for (k = 0; k < 2; k++) {
                        idx = i * 4 + j * 2 + k;
                        corners[idx][0] = (i ? -1.0f : 1.0f) * radius;
                        corners[idx][1] = (j ? 0 : 1.0f) * radius;
                        corners[idx][2] = (k ? -1.0f : 1.0f) * radius;
                    }
                }
            }
            for (i = 0; i < 8; i++) {
                func_800F23D0(proj, corners[i], corners[i]);
                func_800EF04C(corners[i], pos);
            }
            for (i = 0; i < 8; i++) {
                // Abort if a corner has no valid screen point.
                func_800E4190(corners[i], screen[i], &valid);
                if (!valid)
                    return;
            }
            // Bound the projected corners, clamp to 304x228, truncate to pixels.
            screen_min[0] = screen_max[0] = screen[0][0];
            screen_min[1] = screen_max[1] = screen[0][1];
            for (i = 1; i < 8; i++) {
                val = screen[i][0];
                if (val < screen_min[0])
                    screen_min[0] = val;
                else if (screen_max[0] < val)
                    screen_max[0] = val;
                val = screen[i][1];
                if (val < screen_min[1])
                    screen_min[1] = val;
                else if (screen_max[1] < val)
                    screen_max[1] = val;
            }
            if (screen_min[0] < 0.0f)
                screen_min[0] = 0.0f;
            if (screen_min[0] > 304.0f)
                screen_min[0] = 304.0f;
            if (screen_max[0] < 0.0f)
                screen_max[0] = 0.0f;
            if (screen_max[0] > 304.0f)
                screen_max[0] = 304.0f;
            if (screen_min[1] < 0.0f)
                screen_min[1] = 0.0f;
            if (screen_min[1] > 228.0f)
                screen_min[1] = 228.0f;
            if (screen_max[1] < 0.0f)
                screen_max[1] = 0.0f;
            if (screen_max[1] > 228.0f)
                screen_max[1] = 228.0f;
            min_px[0] = screen_min[0];
            min_px[1] = screen_min[1];
            max_px[0] = screen_max[0];
            max_px[1] = screen_max[1];
            // The last two arguments are extents, not corners.
            func_800A5EC4(dl, func_8001575C(), min_px[0], min_px[1],
                          max_px[0] - min_px[0], max_px[1] - min_px[1], alpha);
        }
    }
}

// Draws one projected shadow along light_dir; raycasts for the floor normal unless the actor is on the floor.
s32 func_800A69F0(u8 *shadow, s32 *pos, u8 *light_dir, s32 alpha)
{
    f32 normal[3];
    f32 floor_y;
    f32 start[3];

    func_800EE7F8(pos, shadow + 4);
    floor_y = *(f32 *) ((s8 *) shadow + 0x24);
    if ((mlAbsF(*(f32 *) ((s8 *) pos + 4) - floor_y) < 0.1f) ||
        (0.99f < *(f32 *) ((s8 *) light_dir + 4))) {
        func_800F5680((u32) *(u16 *) ((s8 *) shadow + 0x76) >> 7, normal);
        *(f32 *) ((s8 *) pos + 4) = floor_y;
        func_800A6250(shadow, pos, normal, light_dir, alpha);
        goto block_6;
    }
    func_800EE7F8(start, pos);
    func_800EF174(pos, light_dir, 0xC4FA0000);
    if (func_800C6A7C(start, pos, normal, 0x20020) == 0) {
        return 1;
    }
    func_800A6250(shadow, pos, normal, light_dir, alpha);
block_6:
    ((Struct800A69F0 *) shadow)->unk_7E_b = 1;
    return 1;
}

// Draws up to two shadows from nearby point lights (distance fade), else one from the default light.
void func_800A6B24(ActorA6B24 *shadow)
{
    void *light;
    s32 count;
    f32 center[3];
    f32 radius, dist, factor;
    f32 dir[3], light_pos[3], light_range[3];
    s32 unk_0;
    s32 alpha;
    f32 default_pos[3], default_dir[3];
    if (shadow->pos[1] - shadow->floor_y > 2000.0f)
        return;
    radius = func_800F5BC4((u32) shadow->owner_bits >> 7, center);
    func_800EF04C(center, shadow->pos);
    count = 0;
    for (light = func_800C8760(0, 1); light && count < 2;
         light = func_800C878C(light, 0, 1)) {
        alpha = 255;
        if (func_800C89A8(light) & 8)
            continue;
        func_800C8800(light, light_pos);
        func_800C8898(light, light_range);
        func_800EFB24(dir, light_pos, center);
        dist =
            sqrtf(dir[0] * dir[0] + dir[1] * dir[1] + dir[2] * dir[2]);
        if (dist == 0.0f || dist >= light_range[1] + radius)
            continue;
        factor = -1.0f / dist;
        dir[0] *= factor;
        dir[2] *= factor;
        dir[1] *= -factor;
        dir[0] = -dir[0];
        dir[2] = -dir[2];
        dist -= radius;
        if (dist > light_range[0]) {
            factor = 1.0f - (dist - light_range[0]) * light_range[2];
            alpha = 255.0f * factor;
        }
        func_800A69F0(shadow, light_pos, dir, alpha);
        count++;
    }
    if (!count) {
        func_800EFD24(default_pos);
        func_800EFA4C(default_dir, 0, 1.0f, 0);
        func_800A69F0(shadow, default_pos, default_dir, 255);
    }
}

// Player shadow actor: init, update, draw gate, owner/scale/flag setters, despawn, descriptor.
// Draw: updates position/floor from the owner, then draws the blob or projected shadow.
void func_800A6DAC(u8 *shadow, s32 unk_0)
{
    if ((func_800F6438((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7) != 0) &&
        (func_800F6640((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7) != 0) &&
        (func_800F6E80((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7) != 0) &&
        !(func_800F55FC((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7) & 0x80000000) &&
        ((func_800F65D0((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7) != 0) ||
         (((u32) (*(s32 *) ((s8 *) shadow + 0x74) << 1) >> 31) &&
          ((func_800F8B88() < 2) ||
           ((func_800F5410((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7) == 0xB) &&
            (_plsu_entrypoint_1(0x11) != -1)))))) {
        func_800F5A00((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7, shadow + 4);
        *(f32 *) ((s8 *) shadow + 0x24) =
            func_800F5628((u32) (u16) *(u16 *) ((s8 *) shadow + 0x76) >> 7);
        if (((u32) (*(s32 *) ((s8 *) shadow + 0x64) << 11) >> 31)) {
            func_800A5DB0(shadow);
            return;
        }
        func_800A6B24(shadow);
    }
}

// Init: the shadow is blocked on maps in D_8011A2E0, in some demo/challenge modes and with 2+ cameras.
void func_800A6EF4(LocalActor *actor)
{
    s32 i;
    s32 map_id;
    map_id = func_800EA05C();
    func_8010A800(actor, 5);
    actor->blocked = 0;
    actor->scale = 1.0f;
    for (i = 0; D_8011A2E0[i] != -1; i++) {
        if (map_id == D_8011A2E0[i]) {
            actor->blocked = 1;
            break;
        }
    }
    if ((func_800A9C98() && func_800A9CD0() != 2) || func_800BCC84() || func_800D3948() ||
        func_800A946C() >= 2)
        actor->blocked = 1;
}

// Update: copies the owner position and floor.
void func_800A6FF0(S800A6FF0 *shadow)
{
    func_800F5A00(shadow->owner_idx, shadow->pos);
    shadow->floor_y = func_800F5628(shadow->owner_idx);
    shadow->flag64 = shadow->flag74_2;
    shadow->flag74_1 = func_800F8874(shadow->owner_idx);
}

int func_800A7088(Actor *actor)
{
    // Matching: the copies of actor and the divisor 2 are needed for the match.
    Actor *actor_copy;
    int divisor;
    s32 owner;
    Actor *actor_alias;
    divisor = 2;
    actor_copy = actor;
    actor_alias = actor_copy;
    owner = (((u16 *) actor_alias)[0x76 / divisor] & 0xFFFFFFFFu) >> 7;
    func_800F7364(owner);
}

void func_800A70B0()
{
    func_800FFA88();
}

// Setter: owner index.
void func_800A70D0(s32 handle, s32 owner)
{
    func_80106790(handle)->owner_idx = owner;
}

// Setter: scale.
int func_800A7108(s32 handle, f32 scale)
{
    Actor *actor;
    actor = func_80106790(handle);
    actor->unk58 = scale;
}

// Setter: enable bit.
void func_800A7130(s32 handle, s32 enable)
{
    func_80106790(handle)->enabled = enable;
}

int func_800A7168()
{
    return (int) D_8011A3A0;
}

// TU-NOTE: the .data of this file is defined here in C (formerly asm/data/core2/1E7F6A0.data.s).
// Its tables hold pointers to functions of this file; IDO's assembler schedules some of them
// differently unless the tables are in the same unit. D_8011A3A0 is declared s32[] (uses written as NAME[0]).
extern void func_80102EC0();
extern void func_80107C2C();
s16 D_8011A2E0[12] = {0xDE, 0xDF, 0xE0, 0xC6, 0xC8, 0xC9, 0x12E, 0x12F, 0x130, -0x1, 0x0, 0x0};
Gfx D_8011A2F8[11] = {0xE7000000, 0x0,      0xD9C0FFFA, 0x0, 0xD7000002, 0xFFFFFFFF,
                      0xE200001C, 0x504240, 0xE3000A01, 0x0, 0xFCFFE7FF, 0xFFCF9FCF,
                      0xE3001201, 0x0,      0xE3000C00, 0x0, 0xE3001801, 0xC0,
                      0xE2001E01, 0x1,      0xDF000000, 0x0};
Gfx D_8011A350[6] = {0xE7000000, 0x0, 0xE3001201, 0x2000, 0xE3000C00, 0x80000,
                     0xE3001801, 0x0, 0xE2001E01, 0x0,    0xDF000000, 0x0};
struct __OSBlockInfo D_8011A380 = {0x0, 0x0, 0x0, 0xFF};
struct __OSBlockInfo D_8011A390 = {0x0, 0x0, 0x0, 0x0};
s32 D_8011A3A0[20] = {0x320215,
                      -0xFFFF,
                      0x0,
                      (u32) func_800A6FF0,
                      (u32) func_80102EC0,
                      (u32) func_800A6DAC,
                      0x0,
                      0x0,
                      0x0,
                      0x8000004,
                      (u32) func_800A7088,
                      0x0,
                      0x0,
                      (u32) func_800A6EF4,
                      (u32) func_80107C2C,
                      -0x7FFFFFFE,
                      0x0,
                      0x0,
                      0x0,
                      0x0};
