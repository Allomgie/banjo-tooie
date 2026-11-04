#include "common.h"

typedef struct {
    u8 pad_0[0x10];
    u16 offset;
    u16 pad_1;
    s32 count;
} LightMesh1400;
extern u8 *func_800B2190(void *);
extern s8 *_dbvtxnormal_entrypoint_0(s32, s32);
extern s32 func_800C8760(s32, s32);
extern void func_800C8800(s32, f32 *);
extern void func_800C8898(s32, f32 *);
extern void func_800C8900(s32, s32 *);
extern s32 func_800C878C(s32, s32, s32);

// Multiplies the RGB of the listed vertices by a tint colour (skipped for white).
void dblight_entrypoint_0(LightMesh1400 *section, void *model, u32 *tint)
{
    u8 *vtx_base;
    s32 i;
    s32 j;
    u8 *vtx;
    s16 *idx_list;

    if (tint[0] != 255 || tint[1] != 255 || tint[2] != 255) {
        idx_list = (s16 *) (section->offset * 4 + (u8 *) section + 0x18);
        vtx_base = func_800B2190(model);
        for (i = 0; i < section->count; i++, idx_list++) {
            vtx = vtx_base + *idx_list * 16;
            for (j = 0; j < 3; j++) {
                vtx[j + 0xC] = (s32) (vtx[j + 0xC] * tint[j]) >> 8;
            }
        }
    }
}

// Bakes the static point lights (type 4) into the listed vertex colours.
void dblight_entrypoint_1(u8 *section, s32 model, s32 normals_id)
{
    s32 light;
    s16 *end;
    s32 r;
    u8 *vtx_base;
    s32 g;
    s32 b;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 dist;
    f32 n_dot_l;
    f32 scale;
    u8 *vtx;
    f32 to_light[3];
    f32 radii[3];
    s32 color[3];
    f32 light_pos[3];
    s16 *idx;
    s8 *normal;
    s32 unk_0;
    vtx_base = func_800B2190(model);
    idx = (s16 *) (section + *(u16 *) (section + 0x10) * 4 + 0x18);
    end = idx + *(s32 *) (section + 0x14);
    for (; idx < end; idx++) {
        vtx = vtx_base + *idx * 16;
        normal = _dbvtxnormal_entrypoint_0(normals_id, *idx);
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
        r = vtx[0xC];
        g = vtx[0xD];
        nx = normal[0] * 0.007874015f;
        ny = normal[1] * 0.007874015f;
        b = vtx[0xE];
        nz = normal[2] * 0.007874015f;
        light = func_800C8760(0, 4);
        if (light != 0) {
            do {
                func_800C8800(light, light_pos);
                to_light[0] = light_pos[0] - *(s16 *) (vtx + 0);
                to_light[1] = light_pos[1] - *(s16 *) (vtx + 2);
                to_light[2] = light_pos[2] - *(s16 *) (vtx + 4);
                dist = sqrtf(to_light[0] * to_light[0] + to_light[1] * to_light[1] + to_light[2] * to_light[2]);
                func_800C8898(light, radii);
                if (!(radii[1] < dist)) {
                    func_800C8900(light, color);
                    if (dist != 0.0f) {
                        scale = 1.0f / dist;
                        to_light[0] = to_light[0] * scale;
                        to_light[1] = to_light[1] * scale;
                        to_light[2] = to_light[2] * scale;
                        n_dot_l = to_light[0] * nx + to_light[1] * ny + to_light[2] * nz;
                        // Back-facing: only lit when the vertex is two-sided (0x8000).
                        if (n_dot_l < 0) {
                            if (!(*(u16 *) (vtx + 6) & 0x8000)) {
                                goto next;
                            }
                            n_dot_l = -n_dot_l;
                        }
                        color[0] = (s32) (color[0] * n_dot_l);
                        color[1] = (s32) (color[1] * n_dot_l);
                        color[2] = (s32) (color[2] * n_dot_l);
                    }
                    // Full intensity inside the inner radius, linear falloff to the outer one.
                    if (dist <= radii[0]) {
                        r += color[0];
                        g += color[1];
                        b += color[2];
                    } else {
                        scale = 1.0f - ((dist - radii[0]) * radii[2]);
                        r += scale * color[0];
                        g += scale * color[1];
                        b += scale * color[2];
                    }
                }
            next:
                light = func_800C878C(light, 0, 4);
            } while (light != 0);
        }
        if (r >= 0x100) {
            r = 0xFF;
        }
        if (g >= 0x100) {
            g = 0xFF;
        }
        if (b >= 0x100) {
            b = 0xFF;
        }
        vtx[0xC] = r;
        vtx[0xD] = g;
        vtx[0xE] = b;
    }
}
