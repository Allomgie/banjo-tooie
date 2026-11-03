#include "common.h"

// Light entry of the light set (see 1E8CC00.c); weight is the entry's distance.
typedef struct {
    f32 dir[3];
    s32 color[3];
    f32 weight;
} LocalLight;
// Per-draw lighting state (D_80137060).
typedef struct {
    s32 model, ambient[3];
    u8 transformed, count, pad_12[2];
    void *light_set;
    LocalLight *begin, *end;
} LocalState;
extern LocalState D_80137060;
extern LocalLight *D_80137078;
extern LocalLight *D_8013707C;
extern s32 D_80137064[3];
extern s32 func_800B3784(void *);
extern void func_800B37A4(void *, LocalLight **, LocalLight **);
extern void func_800192FC(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800B37B8(void *, s32 *);
extern void func_800B388C(s32, s32);
extern void func_800B237C(s32, f32 *, f32 *);
extern f32 func_800DF8C4(s32);
extern void func_800B3494(s32, f32 *, f32);
extern void func_800B3748(s32);
extern void func_800B38C8(s32);
extern void func_80019224(f32 *, f32 *);
extern void func_800B37E4(void *, s32);
extern s32 func_800DF8D4(void);
extern void func_800B3370();
// Views used by func_8010E4C4: light entry, per-vertex color record (s16 accumulator
// plus u8 base color), vertex normal, output vertex, and the state D_80137060.
typedef struct {
    f32 dir[3];
    s32 color[3];
    s32 pad_18;
} LightE4C4;
typedef struct {
    s16 accum[3];
    u8 base[3];
    u8 pad_9;
} ColorE4C4;
typedef struct {
    s8 xyz[3];
    u8 pad_3;
} NormalE4C4;
typedef struct {
    u8 pad_0[12];
    u8 color[4];
} VertexE4C4;
typedef struct {
    void *model;
    s32 ambient[3];
    u8 transformed, count;
    u8 pad_12[6];
    LightE4C4 *begin, *end;
} StateE4C4;
extern u8 *func_800DF8B4(void *);
extern NormalE4C4 *func_800DF8CC(void *);
extern ColorE4C4 *func_800DF8BC(void *);

extern s32 D_80137074;

// Prepares the draw state from the light set: count, begin/end, directions
// normalized to length 256, reweighted colors, and the ambient color.
void func_8010E070(void)
{
    LocalLight *light;
    f32 total;
    f32 scale;
    D_80137060.count = func_800B3784(D_80137060.light_set);
    func_800B37A4(D_80137060.light_set, &D_80137078, &D_8013707C);
    if (!D_80137060.transformed) {
        for (light = D_80137060.begin; light < D_80137060.end; light++) {
            func_800192FC(light->dir, light->dir);
            func_800EF368(light->dir, 256.0f);
        }
    }
    if (D_80137060.count >= 2) {
        total = 0.0f;
        for (light = D_80137060.begin; light < D_80137060.end; light++) {
            total += light->weight;
        }
        total = 1.0f / total;
        for (light = D_80137060.begin; light < D_80137060.end; light++) {
            scale = 1.0f - light->weight * total;
            light->color[0] *= scale;
            light->color[1] *= scale;
            light->color[2] *= scale;
        }
    }
    func_800B37B8(D_80137060.light_set, D_80137064);
}

// Fills the light set with the world lights around the model's bounding sphere.
// A negative limit also adds the global directional light.
void func_8010E204(s32 model, s32 limit, s32 param_2)
{
    f32 center[3];
    f32 radius;
    f32 scale;

    func_800B388C(D_80137074, limit < 0 ? -limit : limit);
    func_800B237C(func_800DF8B4(model), center, &radius);
    scale = func_800DF8C4(model);
    func_80019224(center, center);
    radius *= scale;
    func_800B3494(D_80137074, center, radius);
    if (limit < 0) {
        func_800B3748(D_80137074);
    }
    func_800B38C8(D_80137074);
}

// Begin callback: copies the given light set (src_set), or else gathers lights for
// the model, then prepares the draw state.
void func_8010E2C4(s32 model, s32 limit, s32 src_set, s32 param_3)
{
    *(s32 *) ((s8 *) (u8 *) &D_80137060 + 0) = model;
    *(s8 *) ((s8 *) (u8 *) &D_80137060 + 0x10) = func_800DF8D4();
    if (src_set != 0) {
        func_800B37E4(*(s32 *) ((s8 *) (u8 *) &D_80137060 + 0x14), src_set);
    } else {
        // Matching: the empty if is needed for the match.
        if (!model) {
        }
        func_8010E204(model, limit, param_3);
    }
    func_8010E070();
}

// Creates the light set (4 entries).
void func_8010E334()
{
    D_80137074 = func_800B3310(4);
}

// Defragments the light set.
void func_8010E358()
{
    if (D_80137074 != 0) {
        D_80137074 = func_800B38E8(D_80137074);
    }
}

// Frees the light set.
s32 func_8010E390(void)
{
    func_800B3370(D_80137074);
    D_80137074 = 0;
}

s32 func_8010E3B8()
{
    return D_80137074;
}

// Rotates vec by the upper 3x3 of mtx and scales the result to length 256 into out
// (zero if the length is 0).
void func_8010E3C4(f32 mtx[4][4], s32 *out, f32 *vec)
{
    s32 i;
    f32 len;
    f32 rotated[3];
    for (i = 0; i < 3; i++) {
        rotated[i] = vec[0] * mtx[i][0] + vec[1] * mtx[i][1] +
                           vec[2] * mtx[i][2];
    }
    len = sqrtf(rotated[0] * rotated[0] + rotated[1] * rotated[1] + rotated[2] * rotated[2]);
    if (len > 0.0f) {
        len = 256.0f / len;
        out[0] = rotated[0] * len;
        out[1] = rotated[1] * len;
        out[2] = rotated[2] * len;
    } else {
        out[0] = out[1] = out[2] = 0;
    }
}

// Lights a range of vertices: ambient plus the sum over lights of max(0, N.L) * light
// color (>> 15), times the vertex base color, clamped to 255. Without lights only
// ambient is applied. Advances *vertex_cursor by count.
void func_8010E4C4(void *mtx, s32 *vertex_cursor, s32 count)
{
    VertexE4C4 *vertex;
    NormalE4C4 *normal;
    ColorE4C4 *color;
    ColorE4C4 *color_end;
    ColorE4C4 *color_iter;
    LightE4C4 *light;
    NormalE4C4 *normal_iter;
    s32 value;
    s32 ambient_r;
    s32 ambient_g;
    s32 ambient_b;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 unk_4;
    s32 model_dir[3];
    s32 dir_x;
    s32 dir_y;
    s32 dir_z;
    s32 light_r;
    s32 light_g;
    s32 light_b;
    vertex =
        (VertexE4C4 *) (func_800DF8B4((*(StateE4C4 *) &D_80137060).model) + 0x18) + *vertex_cursor;
    normal = func_800DF8CC((*(StateE4C4 *) &D_80137060).model) + *vertex_cursor;
    color = func_800DF8BC((*(StateE4C4 *) &D_80137060).model) + *vertex_cursor;
    color_end = color + count;
    *vertex_cursor += count;
    if ((*(StateE4C4 *) &D_80137060).count) {
        ambient_r = (*(StateE4C4 *) &D_80137060).ambient[0];
        ambient_g = (*(StateE4C4 *) &D_80137060).ambient[1];
        ambient_b = (*(StateE4C4 *) &D_80137060).ambient[2];
        for (color_iter = color; color_iter < color_end; color_iter++) {
            color_iter->accum[0] = ambient_r;
            color_iter->accum[1] = ambient_g;
            color_iter->accum[2] = ambient_b;
        }
        for (light = (*(StateE4C4 *) &D_80137060).begin;
             light < (*(StateE4C4 *) &D_80137060).end; light++) {
            color_iter = color;
            normal_iter = normal;
            if ((*(StateE4C4 *) &D_80137060).transformed) {
                func_8010E3C4(mtx, model_dir, light);
                dir_x = model_dir[0];
                dir_y = model_dir[1];
                dir_z = model_dir[2];
            } else {
                dir_x = light->dir[0];
                dir_y = light->dir[1];
                dir_z = light->dir[2];
            }
            light_r = light->color[0];
            light_g = light->color[1];
            light_b = light->color[2];
            for (; color_iter < color_end; color_iter++, normal_iter++) {
                value = dir_x * normal_iter->xyz[0] + dir_y * normal_iter->xyz[1] +
                        dir_z * normal_iter->xyz[2];
                if (value > 0) {
                    color_iter->accum[0] += (value * light_r) >> 15;
                    color_iter->accum[1] += (value * light_g) >> 15;
                    color_iter->accum[2] += (value * light_b) >> 15;
                }
            }
        }
        for (; color < color_end; color++, vertex++) {
            value = (color->accum[0] * color->base[0]) >> 8;
            if (value >= 256)
                value = 255;
            vertex->color[0] = value;
            value = (color->accum[1] * color->base[1]) >> 8;
            if (value >= 256)
                value = 255;
            vertex->color[1] = value;
            value = (color->accum[2] * color->base[2]) >> 8;
            if (value >= 256)
                value = 255;
            vertex->color[2] = value;
        }
    } else {
        ambient_r = (*(StateE4C4 *) &D_80137060).ambient[0];
        ambient_g = (*(StateE4C4 *) &D_80137060).ambient[1];
        ambient_b = (*(StateE4C4 *) &D_80137060).ambient[2];
        for (; color < color_end; color++, vertex++) {
            vertex->color[0] = (color->base[0] * ambient_r) >> 8;
            vertex->color[1] = (color->base[1] * ambient_g) >> 8;
            vertex->color[2] = (color->base[2] * ambient_b) >> 8;
        }
    }
}

// Clears the model and the light array bounds of the draw state.
void func_8010E7F4()
{
    ((s32 *) &D_80137060)[0] = 0;
    ((s32 *) &D_80137060)[6] = 0;
    ((s32 *) &D_80137060)[7] = 0;
}
