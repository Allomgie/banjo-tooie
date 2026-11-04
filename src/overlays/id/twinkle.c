#include "common.h"

typedef struct {
    u8 pad_0[8];
    s16 position[3];
    s16 pad_1;
} TwinklePoint;
typedef struct {
    u8 pad_0[0xE];
    s16 center[3];
    s32 radius_sq;
    u8 pad_1[0x10];
    s16 count;
    u8 pad_2[2];
    TwinklePoint *points;
} TwinkleContext;
typedef struct {
    s16 position[3];
    u16 flags;
    s16 texcoords[2];
    u8 color[4];
} TwinkleVertex88;
typedef struct {
    f32 fade;
    f32 delay;
    s16 position[3];
    s16 pad_0;
} TwinklePoint88;
typedef struct {
    u8 pad_0[0x28];
    s16 count;
    s16 pad_1;
    TwinklePoint88 *points;
} TwinkleData88;
typedef struct {
    f32 fade;
    f32 delay;
    u8 pad_0[6];
    u8 done;
    u8 rate;
} TwinkleItem31;
typedef struct {
    u8 pad_0[0xC];
    s16 vertex_count;
    u8 pad_1[6];
    s32 radius_sq;
    s16 min_radius;
    s16 max_radius;
    u8 pad_2[8];
    s16 counter;
    s16 center_index;
    s16 count;
    u8 pad_3[2];
    TwinkleItem31 *points;
} TwinkleState31;
extern void _idtwinkle_entrypoint_1();
extern void _idtwinkle_entrypoint_0();
extern f32 func_800DC264(f32, f32);
typedef struct Mass43TwinkleItem {
    f32 fade;
    f32 delay;
    u8 pad_0[6];
    u8 done;
    s8 rate;
} Mass43TwinkleItem;
typedef struct Mass43TwinkleObject {
    u8 pad_0[0x1C];
    f32 timer;
    f32 max_delay;
    u8 pad_1[4];
    s16 count;
    u8 pad_2[2];
    Mass43TwinkleItem *points;
} Mass43TwinkleObject;
extern f32 func_800D8FF8(void);
extern void _idtwinkle_entrypoint_2();

// Vertex callback: collects up to 10 distinct vertices within the radius of the centre.
void idtwinkle_entrypoint_0(s32 unk_0, s16 *pos, s32 unk_2, TwinkleContext *ctx)
{
    s32 i;
    s32 dist_sq;
    s32 diff[3];

    for (i = 0; i < 3; i++) {
        diff[i] = pos[i] - ctx->center[i];
    }
    dist_sq = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
    if (ctx->radius_sq >= dist_sq) {
        for (i = 0; i < ctx->count; i++) {
            if (ctx->points[i].position[0] == pos[0] &&
                ctx->points[i].position[1] == pos[1] &&
                ctx->points[i].position[2] == pos[2])
                break;
        }
        if (i == ctx->count && ctx->count < 10) {
            ctx->points[ctx->count].position[0] = pos[0];
            ctx->points[ctx->count].position[1] = pos[1];
            ctx->points[ctx->count].position[2] = pos[2];
            ctx->count++;
        }
    }
}

// Vertex callback: takes the vertex with the chosen index as centre.
void idtwinkle_entrypoint_1(s32 unk_0, s16 *pos, s32 unk_2, s16 *state)
{
    if (!(state[19] != state[18])) {
        state[7] = pos[0];
        state[8] = pos[1];
        state[9] = pos[2];
    }
    state[18]++;
}

// Kernel: lerps the colour of the sparkle points towards white.
void idtwinkle_entrypoint_2(s32 unk_0, TwinkleVertex88 *src, TwinkleVertex88 *dst,
                            s32 count, TwinkleData88 *data)
{
    TwinkleVertex88 *end;
    f32 fade;
    s32 i;

    end = src + count;
    while (src < end) {
        for (i = 0; i < data->count; i++) {
            if (src->position[0] == data->points[i].position[0] &&
                src->position[1] == data->points[i].position[1] &&
                src->position[2] == data->points[i].position[2]) {
                break;
            }
        }
        if (i != data->count) {
            fade = data->points[i].fade;
            dst->color[0] =
                (u32) ((u32) src->color[0] + (255 - src->color[0]) * fade);
            dst->color[1] =
                (u32) ((u32) src->color[1] + (255 - src->color[1]) * fade);
            dst->color[2] =
                (u32) ((u32) src->color[2] + (255 - src->color[2]) * fade);
        }
        src++;
        dst++;
    }
}

// Picks a random centre vertex and gathers the sparkle points around it.
void func_80800478_idtwinkle(TwinkleState31 *twinkle, s32 unk_1, s32 unk_2)
{
    s32 radius;
    s32 i;

    twinkle->center_index = func_800DC214(0, twinkle->vertex_count);
    twinkle->counter = 0;
    _glid_entrypoint_2(unk_1, unk_2, _idtwinkle_entrypoint_1, twinkle);
    radius = func_800DC214(twinkle->min_radius, twinkle->max_radius);
    twinkle->radius_sq = radius * radius;
    twinkle->count = 0;
    _glid_entrypoint_2(unk_1, unk_2, _idtwinkle_entrypoint_0, twinkle);
    for (i = 0; i < twinkle->count; i++) {
        twinkle->points[i].fade = 0.0f;
        twinkle->points[i].rate = 10;
        twinkle->points[i].done = 0;
        twinkle->points[i].delay = func_800DC264(0.0f, 1.0f);
    }
}

// Frees the point array.
int idtwinkle_entrypoint_3(Actor *actor)
{
    heap_free(*(s32 *) ((char *) actor + 0x2C));
}

// Init: radius from the mesh bounding box; allocates 10 points of 16 bytes.
void idtwinkle_entrypoint_4(u8 *state, s32 mesh_param, s32 model, s32 mesh_id)
{
    s16 bbox_min[3];
    s16 bbox_max[3];
    s16 size[3];
    s32 i;
    s32 size_sq = 0;
    _glidmake_entrypoint_2(model, mesh_id, bbox_min, bbox_max);
    *(s16 *) (state + 12) = _glidmake_entrypoint_3(model, mesh_id);
    for (i = 0; i < 3; i++) {
        size[i] = bbox_max[i] - bbox_min[i];
        size_sq += size[i] * size[i];
    }
    *(s16 *) (state + 0x1A) = (s32) sqrtf((f32) size_sq) * 0.25f;
    *(s16 *) (state + 0x18) = *(s16 *) (state + 0x1A) * 0.5f;
    *(f32 *) (state + 0x20) = mesh_param * 0.1f + 1.0f;
    *(f32 *) (state + 0x1C) = func_800DC264(0.0f, *(f32 *) (state + 0x20));
    *(void **) (state + 0x2C) = heap_alloc(0xA0);
    *(s16 *) (state + 0x28) = 0;
}

// Update: fades each point in and out (+-10/s); restarts after a random delay.
void idtwinkle_entrypoint_5(Mass43TwinkleObject *twinkle, s32 unk_1, s32 unk_2)
{
    s32 pad[1]; // Matching: unused local, needed for the match.
    f32 dt = func_800D8FF8();
    s32 finished = 0;
    s32 i;
    if (twinkle->timer > 0.0f) {
        twinkle->timer -= dt;
        if (twinkle->timer <= 0.0f)
            func_80800478_idtwinkle(twinkle, unk_1, unk_2);
    } else {
        for (i = 0; i < twinkle->count; i++) {
            if (twinkle->points[i].delay > 0.0f)
                twinkle->points[i].delay -= dt;
            else if (!twinkle->points[i].done) {
                twinkle->points[i].fade += twinkle->points[i].rate * dt;
                if (twinkle->points[i].fade >= 1.0f) {
                    twinkle->points[i].fade = 1.0f;
                    twinkle->points[i].rate = -twinkle->points[i].rate;
                } else if (twinkle->points[i].fade < 0.0f) {
                    twinkle->points[i].fade = 0.0f;
                    twinkle->points[i].done = 1;
                }
            } else
                finished++;
        }
        _glid_entrypoint_0(unk_1, unk_2, _idtwinkle_entrypoint_2);
        if (finished == twinkle->count)
            twinkle->timer = func_800DC264(0.0f, twinkle->max_delay);
    }
}

// Returns the range of the current sparkle points.
void idtwinkle_entrypoint_6(u8 *state, s32 *out_begin, s32 *out_end)
{
    *out_begin = *(s32 *) ((s8 *) state + 0x2C);
    *out_end = (*(s16 *) ((s8 *) state + 0x28) * 0x10) + *(s32 *) ((s8 *) state + 0x2C);
}

// TU-NOTE: this overlay's .data is defined here in C; values are taken from the ROM.
