// Coloured twinkle map-mesh effect: keeps 1-20 sparkles alive (default 5), each fading vertex
// colours towards a palette colour; updates only while the mesh is in view.
#include "common.h"

// One sparkle: blend factor towards a palette colour, around one vertex position.
typedef struct {
    f32 blend;
    s16 x;
    s16 y;
    s16 z;
    u8 unk_A;
    u8 rate;
    u8 palette_idx;
    u8 done;
    u8 padE[6];
} IdTwinkle_idtwinklecolour_entrypoint_0;
typedef struct {
    s16 bbox_min[3];
    s16 bbox_max[3];
    s16 vtx_count;
    s16 center[3];
    s32 radius_sq;
    s16 radius_min;
    s16 radius_max;
    u8 pad1C[4];
    s16 cur;
    s16 count;
    IdTwinkle_idtwinklecolour_entrypoint_0 *sparkles;
} IdTwinkleColour_idtwinklecolour_entrypoint_0;
extern s32 func_800DC214(s32, s32);
typedef struct {
    f32 f;
    s16 x;
    s16 y;
    s16 z;
    s16 padA;
    u8 idx;
    u8 padD[7];
} TwinkleEntry;
typedef struct {
    u8 pad0[0x22];
    s16 count;
    TwinkleEntry *list;
} TwinkleSet;
extern u8 D_80800970_idtwinklecolour[][3];
extern u8 _idtwinklecolour_entrypoint_0[];
extern u8 _idtwinklecolour_entrypoint_1[];
extern void heap_free();
typedef struct {
    u8 pad0[0xD];
    u8 done;
    u8 padE[6];
} IdTwinkle_idtwinklecolour_entrypoint_4;
typedef struct {
    s16 bbox_min[3];
    s16 bbox_max[3];
    s16 vtx_count;
    u8 padE[0xA];
    s16 radius_min;
    s16 radius_max;
    u8 pad1C[6];
    s16 count;
    IdTwinkle_idtwinklecolour_entrypoint_4 *sparkles;
} IdTwinkleColour_idtwinklecolour_entrypoint_4;
extern void _glidmake_entrypoint_2();
extern s16 _glidmake_entrypoint_3(s32, s32);
extern void *heap_alloc(s32);
extern f32 func_800D8FF8(void);
extern void _idtwinklecolour_entrypoint_2(void);
extern void _glid_entrypoint_0(s32, s32, void (*)(void), void *);

void idtwinklecolour_entrypoint_0(s32 arg0, s16 *pos, s32 arg2,
                                  IdTwinkleColour_idtwinklecolour_entrypoint_0 *this)
{
    s32 i;
    s32 dist_sq;
    s32 delta[3];

    // Neighbour callback: restarts sparkle `cur` on vertex pos if it is near the centre.
    if (!this->sparkles[this->cur].done) {
        return;
    }
    for (i = 0; i < 3; i++) {
        delta[i] = pos[i] - this->center[i];
    }
    dist_sq = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    if (this->radius_sq < dist_sq) {
        return;
    }
    for (i = 0; i < this->count; i++) {
        if (this->sparkles[i].x == pos[0] && this->sparkles[i].y == pos[1] &&
            this->sparkles[i].z == pos[2]) {
            return;
        }
    }
    this->sparkles[this->cur].x = pos[0];
    this->sparkles[this->cur].y = pos[1];
    this->sparkles[this->cur].z = pos[2];
    this->sparkles[this->cur].blend = 0.0f;
    this->sparkles[this->cur].rate = 10;
    this->sparkles[this->cur].unk_A = 1;
    this->sparkles[this->cur].done = 0;
    this->sparkles[this->cur].palette_idx = func_800DC214(0, 1);
}

// Callback: counts vertices and stores the position of the randomly chosen one as centre.
void idtwinklecolour_entrypoint_1(s32 param_0, s16 *pos, s32 param_2, s16 *this)
{
    if (!(*(s16 *) ((s8 *) this + 0x1E) != *(s16 *) ((s8 *) this + 0x1C))) {
        this[7] = pos[0];
        this[8] = pos[1];
        this[9] = pos[2];
    }
    *(s16 *) ((s8 *) this + 0x1C) = *(s16 *) ((s8 *) this + 0x1C) + 1;
}

// Vertex kernel: fades the colour of vertices that belong to a sparkle towards its palette colour.
void idtwinklecolour_entrypoint_2(s32 arg0, Vtx *src, Vtx *dst, s32 vtx_count,
                                  TwinkleSet *set)
{
    Vtx *end;
    s32 i;
    u8 *target;
    f32 blend;

    end = src + vtx_count;
    for (; src < end; src++, dst++) {
        for (i = 0; i < set->count; i++) {
            if (src->v.ob[0] == set->list[i].x &&
                src->v.ob[1] == set->list[i].y &&
                src->v.ob[2] == set->list[i].z) {
                break;
            }
        }
        if (i == set->count) {
            continue;
        }
        blend = set->list[i].f;
        target = D_80800970_idtwinklecolour[set->list[i].idx];
        dst->v.cn[0] = (u32) src->v.cn[0] + (target[0] - src->v.cn[0]) * blend;
        dst->v.cn[1] = (u32) src->v.cn[1] + (target[1] - src->v.cn[1]) * blend;
        dst->v.cn[2] = (u32) src->v.cn[2] + (target[2] - src->v.cn[2]) * blend;
    }
}

// Re-seeds sparkle `index`: picks a random vertex as centre and a random radius.
void func_80800574_idtwinklecolour(s32 param_0, s32 arg1, s32 arg2, s32 index)
{
    s32 *this;
    int value;
    this = (s32 *) param_0;
    value = func_800DC214(0, *(s16 *) ((char *) this + 0xC));
    *(s16 *) ((char *) this + 0x1E) = value;
    *(s16 *) ((char *) this + 0x1C) = 0;
    *(s16 *) ((char *) this + 0x20) = index;
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_1, this);
    value = func_800DC214(*(s16 *) ((char *) this + 0x18), *(s16 *) ((char *) this + 0x1A));
    *(s32 *) ((char *) this + 0x14) = value * value;
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_0, this);
}

void idtwinklecolour_entrypoint_3(void *this)
{
    heap_free(((void **) this)[9]);
}

void idtwinklecolour_entrypoint_4(IdTwinkleColour_idtwinklecolour_entrypoint_4 *this, s32 count,
                                  s32 arg2, s32 arg3)
{
    s16 diff[3];
    s32 i;
    s32 sum;

    sum = 0;
    _glidmake_entrypoint_2(arg2, arg3, this->bbox_min, this->bbox_max);
    this->vtx_count = _glidmake_entrypoint_3(arg2, arg3);
    for (i = 0; i < 3; i++) {
        diff[i] = this->bbox_max[i] - this->bbox_min[i];
        sum += diff[i] * diff[i];
    }
    sum = sqrtf(sum);
    this->count = count;
    this->radius_max = sum * 0.25f;
    this->radius_min = this->radius_max * 0.5f;
    // Sparkle count comes from the mesh id parameter; 5 if out of range 1..20.
    if (this->count <= 0 || this->count > 20) {
        this->count = 5;
    }
    this->sparkles = heap_alloc(this->count * sizeof(IdTwinkle_idtwinklecolour_entrypoint_4));
    bzero(this->sparkles, this->count * sizeof(IdTwinkle_idtwinklecolour_entrypoint_4));
    for (i = 0; i < this->count; i++) {
        this->sparkles[i].done = 1;
        func_80800574_idtwinklecolour(this, arg2, arg3, i);
    }
}

// Per-frame update; only runs while the mesh is in view.
void idtwinklecolour_entrypoint_5(u8 *this, s32 arg1, s32 arg2)
{
    f32 dt;
    s32 i;
    s32 offset;
    u8 *sparkle;
    dt = func_800D8FF8();
    if (func_800E3DC0(this, this + 6)) {
        // Fade each sparkle in, then back out; finished ones are flagged for re-seeding.
        for (i = 0; i < *(s16 *) (this + 0x22); i++) {
            offset = i * 0x14;
            sparkle = *(u8 **) (this + 0x24) + offset;
            *(f32 *) sparkle += (f32) *(s8 *) (sparkle + 0xB) * dt;
            sparkle = *(u8 **) (this + 0x24) + offset;
            if (*(f32 *) sparkle >= 1.0f) {
                *(f32 *) sparkle = 1.0f;
                sparkle = *(u8 **) (this + 0x24) + offset;
                *(s8 *) (sparkle + 0xB) = -*(s8 *) (sparkle + 0xB);
            } else if (*(f32 *) sparkle < 0.0f) {
                *(f32 *) sparkle = 0.0f;
                (*(u8 **) (this + 0x24) + offset)[0xD] = 1;
            }
        }
        _glid_entrypoint_0(arg1, arg2, _idtwinklecolour_entrypoint_2, this);
        for (i = 0; i < *(s16 *) (this + 0x22); i++) {
            offset = i * 0x14;
            if ((*(u8 **) (this + 0x24) + offset)[0xD])
                func_80800574_idtwinklecolour(this, arg1, arg2, i);
        }
    }
}

// TU-NOTE: the overlay's .data (palette table) is defined here in C; values taken from the ROM.
u8 D_80800970_idtwinklecolour[5][3] = {0xFF, 0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0,
                                       0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
