#include "common.h"

// Light buffer entry (0x28 bytes) as seen by the sorted insertion.
typedef struct {
    u8 pad_0[0x24];
    f32 distance;
} LocalEntry;
extern LocalEntry D_8013709C[];
// Light in model space: position, inner radius (x256), radius squared, falloff factor
// (16384 / (outer - inner)), color, distance to the model.
typedef struct {
    s32 position[3], inner, radius2, inverse, color[3];
    f32 distance;
} LocalLight;
extern void func_800C8800(void *, f32 *);
extern void func_800C883C(void *, f32 *);
extern void func_800C8900(void *, s32 *);
extern void func_800193C4(f32 *, f32 *);
typedef struct {
    u8 pad_0[40];
} Entry10EACC;
extern s32 func_800DF8B4(s32);
extern f32 func_800DF8C4(s32);
extern void func_800DF900(s32);
extern void func_800B237C(s32, f32 *, f32 *);
extern void func_80019224(f32 *, f32 *);
extern s32 func_800C8760(s32, s32);
extern s32 func_800C878C(s32, s32, s32);
// Draw state (D_80137080): entries follow the header (D_8013709C).
typedef struct {
    s32 model;
    s32 ambient[3];
    u8 flags[4]; // [0]: flag from func_800DF8D4, [1]: number of lights
    union {
        u32 addr;
        Entry10EACC *entry;
        LocalLight *light;
    } cursor; // end of the used entries
    union {
        u32 addr;
        Entry10EACC *entry;
        LocalLight *light;
    } limit; // end of the buffer for this model
    Entry10EACC entries[1];
} Struct80137080;
extern Struct80137080 D_80137080;
typedef struct {
    s16 position[3];
    u8 color[4];
} LocalPackedVertex;
typedef struct {
    s16 position[3];
    u16 flags;
    s16 texture[2];
    u8 color[4];
} LocalVertex;
extern s32 func_800B2344(void *);
extern s32 D_80137084;

// Returns the lighting state.
int func_8010E810()
{
    return (int) &D_80137080;
}

// Reserves the slot for a light at the given distance in the buffer, keeping it
// sorted by distance. Farther entries move up; the farthest is dropped when the
// buffer is full. Returns 0 if there is no room.
LocalEntry *func_8010E81C(f32 distance)
{
    u32 entry;
    s32 *dst;
    s32 *src;
    s32 bytes;
    entry = (u32) D_8013709C;
    for (; (u32) entry < (u32) D_80137080.cursor.addr; entry += sizeof(LocalEntry)) {
        if (distance < ((LocalEntry *) entry)->distance)
            break;
    }
    if (entry == (u32) D_80137080.cursor.addr) {
        if (D_80137080.cursor.addr < D_80137080.limit.addr) {
            D_80137080.cursor.addr = D_80137080.cursor.addr + sizeof(LocalEntry);
            return (LocalEntry *) entry;
        }
        return 0;
    }
    if (D_80137080.cursor.addr == D_80137080.limit.addr)
        D_80137080.cursor.addr -= sizeof(LocalEntry);
    dst = (s32 *) (D_80137080.cursor.addr + sizeof(LocalEntry));
    bytes = ((LocalEntry *) D_80137080.cursor.addr - (LocalEntry *) entry) * sizeof(LocalEntry);
    dst--;
    src = (s32 *) (D_80137080.cursor.addr - 4);
    while (bytes > 0) {
        *dst-- = *src--;
        bytes -= 4;
    }
    D_80137080.cursor.addr += sizeof(LocalEntry);
    return (LocalEntry *) entry;
}

// Adds a world light if it reaches the model's bounding sphere (center pos, radius),
// converted to model space. scale is the model scale.
LocalLight *func_8010E924(void *light, f32 *pos, f32 radius, f32 scale)
{
    LocalLight *slot;
    f32 dist;
    f32 delta[3];
    f32 light_pos[3];
    f32 radii[2]; // inner, outer
    func_800C8800(light, light_pos);
    func_800C883C(light, radii);
    delta[0] = light_pos[0] - pos[0];
    delta[1] = light_pos[1] - pos[1];
    delta[2] = light_pos[2] - pos[2];
    dist = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
    if (dist >= radii[1] + radius)
        return 0;
    slot = func_8010E81C(dist);
    if (!slot)
        return 0;
    slot->distance = dist;
    func_800193C4(delta, light_pos);
    slot->position[0] = delta[0];
    slot->position[1] = delta[1];
    slot->position[2] = delta[2];
    radii[0] /= scale;
    radii[1] /= scale;
    slot->inner = radii[0] * 256.0f;
    slot->radius2 = radii[1] * radii[1];
    slot->inverse = 16384.0f / (radii[1] - radii[0]);
    func_800C8900(light, slot->color);
    return slot;
}

// Collects the world lights reaching the model's bounding sphere (at most |limit|)
// and stores their count.
void func_8010EACC(s32 model, s32 limit, f32 *param_2)
{
    s32 unk_0;
    f32 center[3];
    f32 radius;
    f32 scale;
    s32 light;
    D_80137080.limit.entry = (limit < 0 ? -limit : limit) + D_80137080.cursor.entry;
    func_800B237C(func_800DF8B4(model), center, &radius);
    scale = func_800DF8C4(model);
    func_80019224(center, center);
    radius *= scale;
    func_800DF900(model);
    for (light = func_800C8760(0, 1); light; light = func_800C878C(light, 0, 1)) {
        func_8010E924(light, center, radius, scale);
    }
    D_80137080.flags[1] = D_80137080.cursor.entry - D_80137080.entries;
    mlMtxPop();
}

// Shades every vertex: ambient plus the falloff-weighted color of each light, times
// the vertex base color, clamped to 255 (fixed point). Vertices with flag 0x1000 are
// skipped. Without lights only the ambient color is applied.
void func_8010EBE4(void *vertex_buf, void *param_1, LocalPackedVertex *colors)
{
    LocalVertex *vertex;
    LocalPackedVertex *colors_end;
    LocalLight *light;
    s32 acc_r, acc_g, acc_b;
    s32 dx, dy, dz;
    s32 dist_sq, falloff, attenuation, dist, value;

    dist_sq = func_800B2344(vertex_buf); // vertex count, reused as squared distance below
    vertex = (LocalVertex *) ((u8 *) vertex_buf + 0x18);
    colors_end = colors + dist_sq;
    if (D_80137080.flags[1]) {
        for (; colors < colors_end; colors++, vertex++) {
            if (!(vertex->flags & 0x1000)) {
                acc_r = D_80137080.ambient[0];
                acc_g = D_80137080.ambient[1];
                acc_b = D_80137080.ambient[2];
                light = (LocalLight *) D_8013709C;
                for (; (u32) light < (u32) D_80137080.cursor.light; light++) {
                    dx = light->position[0] - vertex->position[0];
                    dy = light->position[1] - vertex->position[1];
                    dz = light->position[2] - vertex->position[2];
                    dist_sq = dx * dx + dy * dy + dz * dz;
                    if (dist_sq < light->radius2) {
                        dist = sqrtf(dist_sq) * 256.0f;
                        falloff = 0x10000;
                        if (light->inner < dist) {
                            attenuation =
                                0x4000 - ((light->inverse * (dist - light->inner)) >> 8);
                            falloff = attenuation << 16;
                            falloff >>= 14;
                        }
                        acc_r += (light->color[0] * falloff) >> 16;
                        acc_g += (light->color[1] * falloff) >> 16;
                        acc_b += (light->color[2] * falloff) >> 16;
                    }
                }
                value = (colors->color[0] * acc_r) >> 8;
                if (value >= 256)
                    value = 255;
                vertex->color[0] = value;
                value = (colors->color[1] * acc_g) >> 8;
                if (value >= 256)
                    value = 255;
                vertex->color[1] = value;
                value = (colors->color[2] * acc_b) >> 8;
                if (value >= 256)
                    value = 255;
                vertex->color[2] = value;
            }
        }
    } else {
        s32 ambient_r, ambient_g, ambient_b;
        ambient_r = D_80137080.ambient[0];
        ambient_g = D_80137080.ambient[1];
        ambient_b = D_80137080.ambient[2];
        for (; colors < colors_end; colors++, vertex++) {
            if (!(vertex->flags & 0x1000)) {
                vertex->color[0] = (colors->color[0] * ambient_r) >> 8;
                vertex->color[1] = (colors->color[1] * ambient_g) >> 8;
                vertex->color[2] = (colors->color[2] * ambient_b) >> 8;
            }
        }
    }
}

// Begin callback: gathers the lights for the model, takes the global ambient color and
// shades the model's vertices.
void func_8010EECC(s32 model, s32 limit, s32 param_2, s32 param_3)
{
    s32 pad;
    s32 normals;
    s32 vertices;
    D_80137080.model = model;
    D_80137080.flags[0] = func_800DF8D4();
    D_80137080.cursor.addr = (u32) D_8013709C;
    func_8010EACC(model, limit, param_3);
    func_800C87B8(&D_80137084);
    vertices = func_800DF8B4(model);
    normals = func_800DF8CC(model);
    func_8010EBE4(vertices, normals, func_800DF8BC(model));
}
