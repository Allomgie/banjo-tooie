// Probably per-actor floor info: a freelist of 0x2C-byte records (handle in the s16 at actor+0x8E)
// with the floor triangle, vertex colours, packed normal and collision flags. Used to
// tint actors by the floor colour and to play footsteps.
#include "common.h"

extern s32 D_80136E80;
extern s32 D_80136EB0;
extern u8 D_80136E88[];
extern s32 D_80136EAC;
extern s32 D_80136E8B;
// Floor-info record (0x2C bytes) from the freelist at D_80136E80.
typedef struct {
    u8 normal[3];
    u8 valid;
    s16 verts[3][3];
    u16 height;
    u8 colors[3][4];
    s32 flags;
    u8 tinted;
} local_type;
extern local_type *freelist_next(void *, s32 *);
extern void func_800EFD4C();
extern f32 func_800F0E00(f32, f32);
typedef struct {
    u8 pad[0x70];
    u32 pad0 : 29;
    u32 unk_70 : 1;
    u32 pad1 : 2;
    u32 pad2 : 26;
    u32 unk_74 : 1;
    u32 pad3 : 5;
    u32 pad4 : 30;
    u32 unk_78 : 1;
    u32 pad5 : 1;
} Flags104780;
extern void func_800AAD28(f32 *);
extern void func_800EE940();
typedef struct {
    u8 pad_0[4];
    s16 verts[3][3];
    u8 pad_16[2];
    u8 colors[3][4];
    u32 flags;
} LocalRecord;
extern void func_800EFA88(s32 *, s32, s32, s32);
extern void func_800EE830(s32 *, s32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EE88C();
extern s32 func_800F36D4(s32 *, s32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern u8 *func_800BEF00(f32 *, f32 *, f32 *, s32);
extern s32 func_800F1B78(f32 *, f32 *, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800C696C(s32, f32, f32, s32, s32);
extern void func_800EFA4C(s32, float, float, float);
typedef struct {
    s32 pad;
    f32 pos[3];
    u8 pad2[0x60];
    u32 pad3 : 31;
    u32 unk_70 : 1;
} Actor105230;
extern f32 D_80124420[];
extern f32 D_8012442C[];
extern s32 func_800D3948(void);
extern void func_8010D640(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_80101E14(Actor105230 *, f32);
extern s32 _fxstep_entrypoint_15(s32, s32, s32 *, s32 *, f32 *);
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern void func_800C4B7C(s32);
extern void func_8010D930(s32, s32, f32 *, f32 *);
void func_8010486C();
void func_801048E4();
void func_80104958();
void func_801049B4();
void func_80104D80();
int func_80104E24();
int func_80105390(s32 param_0[3], s32 param_1[3]);
int func_801053D4();

// Floor record pool, floor raycast, ground vertex-colour tint and floor normal/height getters.
void func_80104350()
{
    D_80136E80 = freelist_new(0x2C, 8);
}

s32 func_80104378(void)
{
    freelist_free(D_80136E80);
    D_80136E80 = 0;
}

void func_801043A0()
{
    if (D_80136E80 != 0) {
        D_80136E80 = freelist_defrag(D_80136E80);
    }
}

// Returns the actor's floor-info record, or 0 if it has none.
s32 func_801043D8(param_0)
u8 *param_0;
{
    s16 handle;

    handle = *(s16 *) (param_0 + 0x8E);
    if (handle == 0) {
        return 0;
    }
    return freelist_at((int) D_80136E80, handle);
}

// Like func_801043D8, but returns a zeroed dummy record when the actor has none.
int func_80104410(param_0)
Actor *param_0;
{
    s16 handle = *(s16 *) ((char *) param_0 + 0x8E);
    if (handle == 0) {
        *(u8 *) &D_80136E8B = 0;
        D_80136EAC = 0;
        *(u8 *) &D_80136EB0 = 0;
        return (int) &D_80136E88;
    }
    return freelist_at((u8 *) D_80136E80, handle);
}

// Allocates and initialises a floor-info record for the actor.
void func_80104460(u8 *param_0)
{
    s32 handle = 0;
    local_type *record;
    s32 i;
    s32 j;

    record = freelist_next((u8 *) &D_80136E80, &handle);
    *(u16 *) (param_0 + 0x8E) = handle;
    record->valid = 0;
    record->flags = 0;
    record->tinted = 0;
    for (i = 0; i < 3; i++) {
        func_800EFD4C(record->verts[i]);
        for (j = 0; j < 4; j++) {
            record->colors[i][j] = 0xFF;
        }
    }
}

void func_80104504(u8 *param_0)
{
    s16 handle;

    handle = *(s16 *) ((s8 *) param_0 + 0x8E);
    if (handle != 0) {
        freelist_erase(D_80136E80, handle, param_0);
        *(s16 *) ((s8 *) param_0 + 0x8E) = 0;
    }
}

// Returns whether the actor has a valid floor-info record.
int func_80104544()
{
    s32 record;
    record = func_801043D8();
    return record && ((u8 *) record)[3] != 0;
}

// Marks the actor's floor-info record invalid.
void func_80104580()
{
    s32 record;
    record = func_801043D8();
    if (record != 0) {
        *(u8 *) (record + 3) = 0;
    }
}

// Stores the hit triangle in the actor's record and sets the actor colour once.
void func_801045AC(s32 param_0, s32 param_1, u8 *param_2, s32 param_3)
{
    s32 _pad;

    f32 raw_tint[3];
    f32 tint[3];
    u8 *record;

    record = func_80104410();
    func_80104958(record);
    func_800AAAE0(record + 0x18);
    func_8010486C(record, param_1);
    *(s16 *) ((s8 *) record + 0x16) = (s16) (s32) *(f32 *) ((s8 *) param_2 + 4);
    *(s8 *) ((s8 *) record + 3) = 1;
    *(s32 *) ((s8 *) record + 0x24) = param_3;
    if (*(u8 *) ((s8 *) record + 0x28) == 0) {
        func_801049B4(record, param_2, raw_tint);
        func_80104D80(raw_tint, 0x28);
        func_80104E24(raw_tint, tint);
        _subaddiefade_entrypoint_11(param_0, tint);
        *(u8 *) ((s8 *) record + 0x28) = 1U;
    }
}

// Outputs floor position, height above it and tilt; returns 0 if there is no usable floor.
s32 func_80104668(s32 param_0, u8 *param_1, u8 *param_2, u8 *param_3, f32 *param_4)
{
    u8 *record;
    f32 normal[3];

    if (func_80104544() == 0) {
        return 0;
    }
    record = func_801043D8(param_0);
    if (*(s32 *) ((s8 *) record + 0x24) & 0x8000) {
        return 0;
    }
    func_800EE7F8(param_2, param_1);
    *(f32 *) ((s8 *) param_2 + 4) = (f32) *(s16 *) ((s8 *) record + 0x16);
    *param_4 = func_800F0E00(0.0f, *(f32 *) ((s8 *) param_1 + 4) - *(f32 *) ((s8 *) param_2 + 4));
    func_801048E4(record, normal);
    func_800F1988(normal, param_3, param_3 + 4);
    *(f32 *) ((s8 *) param_3 + 8) = 0.0f;
    return 1;
}

// Returns the floor height; optionally outputs the floor normal.
f32 func_8010473C(s32 param_0, s32 param_1)
{
    s16 *record;

    record = func_801043D8(param_0);
    if (param_1 != 0) {
        func_801048E4(record, param_1);
    }
    return (f32) record[0x16 / sizeof(s16)];
}

// Smooths the actor colour at +0x98 towards the current floor tint: (3 * old + new) / 4.
void func_80104780(u8 *param_0)
{
    u8 *record;
    s32 raw_tint[3];
    s32 tint[3];
    s32 i;
    record = func_801043D8();
    if (((Flags104780 *) param_0)->unk_78 && !((Flags104780 *) param_0)->unk_74 && record[3]) {
        func_801049B4(record, (f32 *) (param_0 + 4), raw_tint);
        func_80104D80(raw_tint, 40);
        func_80104E24(raw_tint, tint);
        if (((Flags104780 *) param_0)->unk_70 && !(*(u32 *) (record + 0x24) & 0x04200000)) {
            func_80105390(tint, tint);
        }
        for (i = 0; i < 3; i++) {
            param_0[0x98 + i] = (param_0[0x98 + i] * 3 + tint[i]) >> 2;
        }
    }
}

// Packs a unit normal into the record as signed bytes (x127).
void func_8010486C(record, normal) u8 *record;
f32 *normal;
{
    s32 i;
    for (i = 0; i < 3; i++) {
        record[i] = (s8) (normal[i] * 127.0f);
    }
}

// Unpacks the record's normal back to floats (/127).
void func_801048E4(record, normal) s8 *record;
f32 *normal;
{
    s32 i;
    f32 scale = 0.007874015f;
    for (i = 0; i < 3; i++) {
        normal[i] = (f32) record[i] * scale;
    }
}

// Stores the three floor vertices from func_800AAD28 in the record.
void func_80104958(record) void *record;
{
    f32 verts[3][3];
    s16 *dst;
    s32 i;
    func_800AAD28(&verts[0][0]);
    dst = (s16 *) ((u8 *) record + 4);
    for (i = 0; i < 3; i++) {
        func_800EE940(dst, verts[i]);
        dst += 3;
    }
}

// Interpolates the triangle's vertex colours at pos (written to out_color).
// Returns white if flag 0x200000 is set; greys the result if 0x4000000 is set.
void func_801049B4(record, pos, out_color) LocalRecord *record;
f32 *pos;
s32 *out_color;
{
    f32 pos_copy[3];
    f32 v0_to_pos[3];
    f32 seg[3];
    f32 denom;
    s32 i;
    f32 t;
    s32 j;
    f32 perp[3];
    f32 v1_to_v0[3];
    f32 edge_pt[3];
    s32 vert_col[3][3];
    f32 ratio;
    f32 vert[3][3];
    f32 normal[3];
    f32 v0_to_v1[3];
    f32 v0_to_v2[3];
    f32 v1_to_v2[3];
    // Matching: unused local needed for the match.
    s32 unk_0;
    if ((record->flags & 0x200000)) {
        func_800EFA88(out_color, 255, 255, 255);
        return;
    }
    func_800EE7F8(pos_copy, pos);
    for (i = 0; i < 3; i++) {
        func_800EE88C(vert[i], record->verts[i]);
        for (j = 0; j < 3; j++) {
            vert_col[i][j] = record->colors[i][j];
        }
    }
    // All three vertex colours equal: no interpolation needed.
    if (func_800F36D4(vert_col[0], vert_col[1]) && func_800F36D4(vert_col[0], vert_col[2])) {
        func_800EE830(out_color, vert_col[0]);
        return;
    }
    func_800EFB24(v0_to_pos, pos_copy, vert[0]);
    func_800EFB24(v1_to_v0, vert[0], vert[1]);
    func_800EFB24(v0_to_v1, vert[1], vert[0]);
    func_800EFB24(v0_to_v2, vert[2], vert[0]);
    func_800EFB24(v1_to_v2, vert[2], vert[1]);
    func_800EE97C(normal, v0_to_v1, v0_to_v2);
    func_800EE97C(perp, v1_to_v2, normal);
    denom = func_800EEAA4(v0_to_pos, perp);
    if (denom == 0.0f)
        denom = 0.1f;
    t = -func_800EEAA4(v1_to_v0, perp) / denom;
    func_800EFA4C(edge_pt, vert[0][0] + v0_to_pos[0] * t, 0,
                  vert[0][2] + v0_to_pos[2] * t);
    func_800EFB24(seg, edge_pt, vert[1]);
    t = func_800EEF94(seg);
    ratio = t / (func_800EEF94(perp) + 0.01f);
    for (i = 0; i < 3; i++)
        out_color[i] =
            vert_col[1][i] + (vert_col[2][i] - vert_col[1][i]) * ratio;
    func_800EFB24(seg, edge_pt, vert[0]);
    t = func_800EEF94(v0_to_pos);
    ratio = 1.0f - t / (func_800EEF94(seg) + 0.01f);
    for (i = 0; i != 3; i++)
        out_color[i] =
            out_color[i] + (vert_col[0][i] - out_color[i]) * ratio;
    if (record->flags & 0x4000000)
        func_80105390(out_color, out_color);
}

// Brightens the colour towards white by amount/256.
void func_80104D80(colors, amount) s32 *colors;
s32 amount;
{
    f32 scale = 1.0f - amount * 0.00390625f;
    s32 i;
    for (i = 0; i < 3; i++) {
        colors[i] = colors[i] * scale + amount;
    }
}

// Clamps three colour components to 0..255.
int func_80104E24(src, dst)
s32 *src;
s32 *dst;
{
    s32 loaded;
    // Matching: the odd loop setup and the extra temporary are needed for the match.
    s32 offset;
    s32 value;
    value = 0;
    for (offset = value; offset < 0xC; offset = offset - -4) {
        loaded = (value = *((s32 *) (((u8 *) src) + offset)));
        if (loaded < 0) {
            *((s32 *) (((u8 *) dst) + offset)) = 0;
        } else if (0x100 <= value) {
            *((s32 *) (((u8 *) dst) + offset)) = 0xFF;
        } else {
            *((s32 *) (((u8 *) dst) + offset)) = value;
        }
    }
}

// Raycasts down to the floor and tints the actor from it; white on a miss.
// hit_pos starts as the ray end point and receives the hit position.
s32 func_80104E78(u8 *param_0)
{
    f32 hit_pos[3];
    f32 ray_start[3];
    f32 normal[3];
    u8 *hit;
    func_800EE7F8(hit_pos, (f32 *) (param_0 + 4));
    func_800EE7F8(ray_start, (f32 *) (param_0 + 4));
    hit_pos[1] -= 300.0f;
    ray_start[1] += 100.0f;
    hit = func_800BEF00(ray_start, hit_pos, normal, *(s32 *) (param_0 + 0x14));
    if (hit) {
        func_801045AC(param_0, normal, hit_pos, *(s32 *) (hit + 8));
        return 1;
    }
    _subaddiefade_entrypoint_12(param_0, 255, 255, 255);
    return 0;
}

// Like func_80104E78, but only when update_tint is set; with snap_to_floor it also
// moves the actor to the floor height.
void func_80104F2C(u8 *param_0, s32 update_tint, s32 snap_to_floor)
{
    f32 hit_pos[3];
    f32 ray_start[3];
    f32 normal[3];
    u8 *hit;
    f32 unk_0[3];
    if (update_tint || snap_to_floor) {
        func_800EE7F8(hit_pos, (f32 *) (param_0 + 4));
        func_800EE7F8(ray_start, (f32 *) (param_0 + 4));
        hit_pos[1] -= 300.0f;
        ray_start[1] += 100.0f;
        hit = func_800BEF00(ray_start, hit_pos, normal, *(s32 *) (param_0 + 0x14));
        if (hit) {
            if (update_tint)
                func_801045AC(param_0, normal, hit_pos, *(s32 *) (hit + 8));

if (snap_to_floor) {
    *(f32 *) (param_0 + 8) = hit_pos[1];
    if (func_800F1B78(unk_0, normal, *(f32 *) (param_0 + 0x48), 1.0f)) {
        *(f32 *) (param_0 + 0x44) = unk_0[0];
        *(f32 *) (param_0 + 0x4C) = unk_0[2];
    }
}

}
}
}

// Variant that probes along the actor's heading (+-80 units) instead of straight down.
s32 func_80105010(u8 *param_0)
{
    u8 *record;
    f32 front[3];
    f32 back[3];
    f32 normal[3];
    u8 *hit;
    s32 raw_tint[3];
    s32 tint[3];
    record = func_80104410();
    func_800EE7F8(front, (f32 *) (param_0 + 4));
    func_800EE7F8(back, (f32 *) (param_0 + 4));
    func_800EF1B8(front, *(f32 *) (param_0 + 0x48), 80.0f);
    func_800EF1B8(back, *(f32 *) (param_0 + 0x48), -80.0f);
    hit = func_800BEF00(front, back, normal, *(s32 *) (param_0 + 0x14));
    if (hit) {
        func_80104958(record);
        func_800AAAE0(record + 0x18);
        func_8010486C(record, normal);
        *(s16 *) (record + 0x16) = back[1];
        record[3] = 1;
        *(s32 *) (record + 0x24) = *(s32 *) (hit + 8);
        func_801049B4(record, back, raw_tint);
        func_80104D80(raw_tint, 40);
        func_80104E24(raw_tint, tint);
        _subaddiefade_entrypoint_11(param_0, tint);
        record[0x28] = 1;
        return 1;
    }
    _subaddiefade_entrypoint_12(param_0, 255, 255, 255);
    return 0;
}

void func_80105138(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
    s32 pos;
    if (param_1 != 0) {
        // Matching: `| 0` needed for the match.
        pos = param_1 | 0;
    } else {
        pos = param_0 + 4;
    }
    func_800C696C(pos, param_2, param_3, *(s32 *) (param_0 + 0x14), param_4);
}

// Returns the floor collision flags, or 0 if the actor has no floor record.
s32 func_8010518C(actor)
ALLink *actor;
{
    if (!func_80104544(actor)) {
        return 0;
    }
    return *(s32 *) ((char *) func_801043D8(actor) + 0x24);
}

// Outputs the floor normal; (0, 1, 0) and 0 if there is no record.
int func_801051C8(s32 param_0, s32 param_1)
{
    if (!func_80104544()) {
        func_800EFA4C(param_1, 0.0f, 1.0f, 0.0f);
        return 0;
    }
    func_801048E4(func_801043D8(param_0), param_1);
    return 1;
}

// Anim-frame-triggered footstep sfx chosen by floor material.
// Plays a footstep sfx when the animation is at a frame of the -1.0 terminated list
// (default D_80124420). Only within 1500 units of the player.
s32 func_80105230(Actor105230 *actor, f32 *frames)
{
    // Matching: unused local needed for the match.
    s32 unk_0;
    f32 player_pos[3];
    s32 index;
    s32 unk_1, unk_2;
    f32 unk_3;
    f32 *frame;
    // Matching: the one-element array is needed for the match.
    f32 *actor_pos[1];
    index = 0;
    if (func_800D3948())
        return 0;
    func_8010D640(player_pos);
    actor_pos[0] = actor->pos;
    if (2.25e+06f <= func_800EEB40(player_pos, actor_pos[0]))
        return 0;
    frame = frames ? frames : D_80124420;
    for (; *frame != -1.0f; frame++, index++) {
        if (func_80101E14(actor, *frame)) {
            if (_fxstep_entrypoint_15(func_801053D4(actor), index & 1, &unk_1, &unk_2,
                                      &unk_3)) {
                func_800C4B64(unk_3);
                func_800C4B70(unk_2);
                func_800C4B7C(unk_1);
                func_8010D930(2, actor->unk_70, actor_pos[0], D_8012442C);
            }

return 1;
}
}
return 0;
}

// Sets all three components of dst to the average of src (grey).
int func_80105390(s32 dst[3], s32 src[3])
{
    dst[2] = (dst[1] = (dst[0] = ((src[0] + src[1]) + src[2]) / 3.0f));
}

// Returns the material of the floor under the actor (1 if unknown).
int func_801053D4()
{
    s32 flags;
    s32 material;
    flags = func_8010518C();
    // Matching: `| 0` needed for the match.
    material = func_800C84B0(flags | 0);
    if (material == 0) {
        material = 1;
    }
    return material;
}

// TU-NOTE: the .data of this file is defined here in C; values come from the ROM.
f32 D_80124420[3] ={0.0f, 0.5f, -1.0f};
f32 D_8012442C[5] = {3.030612e-39f, 2.755066e-39f, 1.8369201e-38f, 0.0f, 0.0f};
