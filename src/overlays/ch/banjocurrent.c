// Probably a water-current actor with two kinds: one moves the player along the texture flow of
// the floor triangle, the other pushes the player outward from the map origin in waves.
#include "common.h"

extern void *D_808007D0_chbanjocurrent;
extern void func_800EE88C(f32 *, void *);
extern int D_80800818_chbanjocurrent[];
extern s32 func_800F54E4(void);
extern f32 func_800F5E7C(u32);
extern f32 func_800F5F7C(u32);
extern f32 func_80013A7C(f32);
extern f32 func_800D8FF8(void);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800137D4(f32);
extern f32 func_80013788(void);
extern void *func_800F5E50(s32);
extern void func_80102EC0(), func_80107C2C(), func_8010A730();

// Whether the active player may be affected by the current.
// Matching: the missing return leaves the call's result in v0.
int func_80800000_chbanjocurrent()
{
    func_800F4C24(func_800F54E4());
}

int chbanjocurrent_entrypoint_0()
{
    return (int) &D_808007D0_chbanjocurrent;
}

// Rotates three words left.
void func_80800034_chbanjocurrent(void *words)
{
    s32 temp;
    temp = *(s32 *) ((char *) words + 4);
    *(s32 *) ((char *) words + 4) = *(s32 *) ((char *) words + 8);
    *(s32 *) ((char *) words + 8) = *(s32 *) ((char *) words + 0);
    *(s32 *) ((char *) words + 0) = temp;
}

// Reads a triangle's vertex positions and UVs from the map model and sorts the vertex order by U.
void func_80800050_chbanjocurrent(u16 *vert_idx, f32 (*pos)[3], f32 (*uv)[2], s32 *order)
{
    s32 model;
    u8 *verts;
    u8 *vert;
    s32 i;
    model = func_800BEB28(1);
    if (!model)
        model = func_800BEB28(0);
    verts = (u8 *) func_800B2840(model) + 0x18;
    for (i = 0; i != 3; i++) {
        vert = verts + vert_idx[i] * 0x10;
        func_800EE88C(pos[i], vert);
        uv[i][0] = *(s16 *) (vert + 8);
        uv[i][1] = *(s16 *) (vert + 10);
        order[i] = i;
    }
    if (uv[order[2]][0] <= uv[order[1]][0])
        func_80800034_chbanjocurrent(order);
    if (uv[order[2]][0] <= uv[order[1]][0])
        func_80800034_chbanjocurrent(order);
}

// Kind 1: moves the player along the texture flow of its floor triangle.
void func_808001D0_chbanjocurrent(Actor *actor)
{
    f32 depth;
    f32 du;
    u32 player;
    f32 fade;
    f32 t;
    s32 state;
    f32 verts[3][3];
    f32 uvs[3][2];
    s32 order[3];
    f32 edge[3];
    f32 point[3];
    u16 *tri;
    f32 dir[3];
    s32 i;
    s32 vert1;
    f32 normal[3];
    f32 move[3];
    if (!func_80800000_chbanjocurrent(actor))
        return;
    player = func_800F54E4();
    state = func_8008FF94();
    if (!state)
        return;
    if (state == 2) {
        depth = func_800F5E7C(player) - func_800F5F7C(player);
        if (depth >= 1000.0f)
            return;
        if (depth < 0)
            depth = 0;
        fade = 1.0f - depth * 0.001f;
    } else {
        fade = 1.0f;
    }
    tri = func_800F5E50(player);
    state = (*(u32 *) ((u8 *) tri + 8) & 0x78000000) >> 27;
    if (!state)
        return;
    if (actor->rotation[1] != 0.0f && actor->rotation[1] != (t = state))
        return;
    func_80800050_chbanjocurrent(tri, verts, uvs, order);
    func_800EFB24(edge, verts[order[2]], verts[order[1]]);
    du = uvs[order[2]][0] - uvs[order[1]][0];
    if (du != 0.0f) {
        t = (uvs[order[0]][0] - uvs[order[1]][0]) / du;
        for (i = 0; i < 3; i++) {
            point[i] = verts[order[1]][i] + (edge[i] * t);
        }
        func_800EFB24(dir, point, verts[order[0]]);
        func_800EF2A0(dir);
    } else {
        func_800EFD24(dir);
    }
    // Matching: vert1 is an s32 holding the pointer; needed for the match.
    vert1 =verts[1];
    func_800EF3DC(vert1, verts[0]);
    func_800EF3DC(verts[2], verts[0]);
    func_800EE97C(normal, verts[1], verts[2]);
    func_800EF2A0(normal);
    func_800EF334(dir, func_80013A7C(normal[1]) * 0.05f + 1.0f);
    func_80090794(move);
    func_800EF174(move, dir, func_800D8FF8() * (u32) actor->unk74_7 * fade);
    if (actor->rotation[1] != 0.0f) {
        func_800907C0(move);
    }
}

int chbanjocurrent_entrypoint_1()
{
    return (int) &D_80800818_chbanjocurrent;
}

// Sine-wave magnitude (returned) and horizontal direction (out_xz) of the radial push.
f32 func_80800514_chbanjocurrent(f32 *offset, f32 *out_xz, f32 phase)
{
    f32 dist;
    f32 wave;
    f32 speed;
    f32 scale;

    dist = func_800EEF94(offset);
    wave = func_800137D4(func_800136D0((dist - phase) * 0.015707964f)) * 20.0f;
    speed = func_80013788() * 20.0f * 0.015707964f;
    if (dist != 0.0f) {
        scale = speed / dist;
        out_xz[0] = offset[0] * scale;
        out_xz[1] = offset[2] * scale;
    } else {
        out_xz[0] = offset[0] * speed;
        out_xz[1] = offset[2] * speed;
    }
    return wave;
}

// Kind 2: pushes the player radially from the map origin with a travelling sine wave.
void func_808005F4_chbanjocurrent(Actor *actor)
{
    // Matching: unused local, needed for the match.
    f64 unk_0;
    s32 player;
    f32 fade;
    f32 depth;
    s32 state;
    f32 pos[3];
    f32 push[2];
    if (!func_80800000_chbanjocurrent())
        return;
    player = func_800F54E4();
    actor->unk58 += (func_800D8FF8() * (f32) actor->unk74_7) * 4.0f;
    state = func_8008FF94();
    if (!state)
        return;
    if (state == 2) {
        depth = func_800F5E7C(player) - func_800F5F7C(player);
        if (depth >= 2000.0f)
            return;
        if (depth < 0.0f)
            depth = 0.0f;
        fade = 1.0f - depth * 0.0005f;
    } else
        fade = 1.0f;
    state = (*(u32 *) ((u8 *) func_800F5E50(player) + 8) & 0x78000000) >> 27;
    if (state && actor->rotation[1] == (depth = state)) {
        func_80090794(pos);
        func_80800514_chbanjocurrent(pos, push, actor->unk58);
        pos[0] += (push[0] * 8.0f) * fade;
        pos[2] += (push[1] * 8.0f) * fade;
        func_800907C0(pos);
    }
}

// TU-NOTE: .data is defined here in C. The tables hold pointers to functions of this file, and
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
// D_80800818_chbanjocurrent is declared as int[] to match the object.
void *D_808007D0_chbanjocurrent =(void *) 0x015801D1;
static u32 D_808007D0_chbanjocurrent_rest[17] = {0x2,
                                                 0x0,
                                                 (u32) func_808001D0_chbanjocurrent,
                                                 (u32) func_80102EC0,
                                                 (u32) func_8010A730,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_80107C2C,
                                                 0x80002602,
                                                 0x0,
                                                 0x0};
int D_80800818_chbanjocurrent[18] = {0x15801D6,
                                     0x1,
                                     0x0,
                                     (u32) func_808005F4_chbanjocurrent,
                                     (u32) func_80102EC0,
                                     (u32) func_8010A730,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFD9FE,
                                     0x0,
                                     0x0};
