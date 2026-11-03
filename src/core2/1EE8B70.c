#include "common.h"

typedef struct {
    u8 pad_0[0x24];
    s32 brightness;
} LocalEntry;
typedef struct {
    u8 pad_0[8];
    u32 end, limit;
} LocalBuffer_8010F280;
// TU-NOTE: D_80137240 is the light buffer state; D_80137250 is the start of its sorted entries.
extern LocalBuffer_8010F280 D_80137240;
extern LocalEntry D_80137250[];
typedef struct {
    s32 dir[3];
    s32 inner, radius_sq, falloff;
    s32 rgb[3];
    s32 brightness;
} LightF384;
typedef struct {
    s32 pad_0;
    s32 unk_4;
    LightF384 *unk_8, *unk_C;
    LightF384 entries[1];
} StateF384;
extern void *func_800DF8B4(void *);
extern void func_800B237C(void *, f32 *, f32 *);
extern f32 func_800DF8C4(void *);
extern void func_80019224();
extern void *func_800C8760();
extern void func_800C8800();
extern void func_800193C4();
typedef struct {
    s16 xyz[3];
    u16 flags;
    s16 uv[2];
    u8 rgb[3], alpha;
} LocalVertex;
typedef struct {
    s16 xyz[3];
    u8 rgb[3], alpha;
} LocalColor;
typedef struct {
    u8 pad0[22];
    u16 unused : 15;
    u16 dirty : 1;
    LocalVertex vertices[1];
} LocalBuffer_8010F68C;
typedef struct {
    s32 xyz[3], inner, radiusSquared, falloff, rgb[3], unused;
} LocalLight;
extern s32 D_80137244;
extern LocalLight *D_80137248;
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 *unk8;
} S80137240;
extern s32 func_800DF8BC(s32);

// Inserts a light into the buffer sorted by descending brightness; NULL if full.
LocalEntry *func_8010F280(s32 key)
{
    u32 slot;
    s32 *dst;
    s32 *src;
    s32 bytes;
    slot = (u32) D_80137250;
    for (; (u32) slot < (u32) D_80137240.end; slot += sizeof(LocalEntry)) {
        if (((LocalEntry *) slot)->brightness < key)
            break;
    }
    if (slot == (u32) D_80137240.end) {
        if (D_80137240.end < D_80137240.limit) {
            D_80137240.end = D_80137240.end + sizeof(LocalEntry);
            return (LocalEntry *) slot;
        }
        return 0;
    }
    if (D_80137240.end == D_80137240.limit)
        D_80137240.end -= sizeof(LocalEntry);
    dst = (s32 *) (D_80137240.end + sizeof(LocalEntry));
    bytes = ((LocalEntry *) D_80137240.end - (LocalEntry *) slot) * sizeof(LocalEntry);
    dst--;
    src = (s32 *) (D_80137240.end - 4);
    while (bytes > 0) {
        *dst-- = *src--;
        bytes -= 4;
    }
    D_80137240.end += sizeof(LocalEntry);
    return (LocalEntry *) slot;
}

// Collects the type-2 world lights that reach the model, ranked by brightness.
void func_8010F384(void *model, s32 param_1, s32 param_2)
{
    f32 scale;
    f32 model_pos[3];
    f32 radius;
    void *light;
    LightF384 *entry;
    f32 dist;
    s32 brightness;
    f32 delta[3];
    f32 light_pos[3];
    f32 light_range[2];
    s32 light_rgb[4];
    (*(StateF384 *) &D_80137240).unk_C =
        (*(StateF384 *) &D_80137240).unk_8 + (param_1 < 0 ? -param_1 : param_1);
    func_800B237C(func_800DF8B4(model), model_pos, &radius);
    scale = func_800DF8C4(model);
    func_80019224(model_pos, model_pos);
    radius *= scale;
    func_800DF900(model);
    for (light = func_800C8760(0, 2); light; light = func_800C878C(light, 0, 2)) {
        func_800C8800(light, light_pos);
        func_800C883C(light, light_range);
        delta[0] = light_pos[0] - model_pos[0];
        delta[1] = light_pos[1] - model_pos[1];
        delta[2] = light_pos[2] - model_pos[2];
        dist =
            sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
        if (dist >= light_range[1] + radius)
            continue;
        func_800C8900(light, light_rgb);
        brightness =
            (light_rgb[0] + light_rgb[1] + light_rgb[2]) * (1.0f - dist / (light_range[1] + radius));
        entry = func_8010F280(brightness);
        if (entry) {
            entry->brightness = brightness;
            func_800193C4(delta, light_pos);
            entry->dir[0] = delta[0];
            entry->dir[1] = delta[1];
            entry->dir[2] = delta[2];
            light_range[0] /= scale;
            light_range[1] /= scale;
            entry->inner = light_range[0] * 256.0f;
            entry->radius_sq = light_range[1] * light_range[1];
            entry->falloff = 16384.0f / (light_range[1] - light_range[0]);
            func_800EE830(entry->rgb, light_rgb);
        }
    }
    (*(StateF384 *) &D_80137240).unk_4 =
        (*(StateF384 *) &D_80137240).unk_8 - (*(StateF384 *) &D_80137240).entries;
    mlMtxPop();
}

// Adds the light contributions onto the base colours; restores them when no light applies.
void func_8010F68C(LocalBuffer_8010F68C *buffer, LocalColor *colors)
{
    LocalVertex *vertex;
    LocalColor *colors_end;
    LocalLight *light;
    s32 r, g, b;
    s32 dx, dy, dz;
    s32 dist_sq, weight, dist, falloff_term;
    colors_end = colors + func_800B2344(buffer);
    vertex = buffer->vertices;
    if (D_80137244) {
        for (; colors < colors_end; colors++, vertex++) {
            if (vertex->flags & 0x1000)
                continue;
            {
                r = colors->rgb[0];
                g = colors->rgb[1];
                b = colors->rgb[2];
                for (light = (LocalLight *) D_80137250; (u32) light < (u32) D_80137248;
                     light++) {
                    dx = light->xyz[0] - vertex->xyz[0];
                    dy = light->xyz[1] - vertex->xyz[1];
                    dz = light->xyz[2] - vertex->xyz[2];
                    dist_sq = dx * dx + dy * dy + dz * dz;
                    dist = dist_sq;
                    if (dist_sq >= light->radiusSquared)
                        continue;
                    {
                        if (dist_sq)
                            dist = sqrtf(dist_sq) * 256.0f;
                        if (light->inner < dist) {
                            falloff_term =
                                0x4000 - ((light->falloff * (dist - light->inner)) >> 8);
                            weight = falloff_term << 2;
                        } else
                            weight = 0x10000;
                        r += (light->rgb[0] * weight) >> 16;
                        g += (light->rgb[1] * weight) >> 16;
                        b += (light->rgb[2] * weight) >> 16;
                    }
                }
                if (r >= 256)
                    r = 255;
                vertex->rgb[0] = r;
                if (g >= 256)
                    g = 255;
                vertex->rgb[1] = g;
                if (b >= 256)
                    b = 255;
                vertex->rgb[2] = b;
            }
        }
        buffer->dirty = 1;
    } else if (buffer->dirty) {
        for (; colors < colors_end; colors++, vertex++) {
            if (vertex->flags & 0x1000)
                continue;
            {
                vertex->rgb[0] = colors->rgb[0];
                vertex->rgb[1] = colors->rgb[1];
                vertex->rgb[2] = colors->rgb[2];
            }
        }
        buffer->dirty = 0;
    }
}

void func_8010F950(s32 model, s32 arg1, s32 arg2, s32 arg3)
{
    (*(S80137240 *) &D_80137240).unk0 = model;
    (*(S80137240 *) &D_80137240).unk8 = (u8 *) D_80137250;
    func_8010F384(model, arg1, arg3);
    func_8010F68C(func_800DF8B4((*(S80137240 *) &D_80137240).unk0),
                  func_800DF8BC((*(S80137240 *) &D_80137240).unk0));
}
