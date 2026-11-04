#include "common.h"

extern void _dbpalette_entrypoint_0();

typedef struct Mass44PackedVertex {
    s16 unk_0[3];
    u8 color[3];
    u8 unk_9;
} Mass44PackedVertex;

// Builds a packed vertex-colour buffer for the model: vertex colour, optionally remapped
// through the palette and multiplied by the tint (skipped for white).
void *glpackvtx_entrypoint_0(s32 model, s32 palette, s32 *tint)
{
    s32 pad0;
    Mass44PackedVertex *buf;
    Mass44PackedVertex *out;
    Mass44PackedVertex *end;
    u8 *vtx;
    s32 rgb[4];
    s32 count;
    count = func_800B2344(model);
    buf = heap_alloc(count * sizeof(Mass44PackedVertex));
    end = buf + count;
    vtx = (u8 *) func_800B2190(model);
    for (out = buf; out < end; out++, vtx += 16) {
        if (palette) {
            _dbpalette_entrypoint_0(palette, *(u16 *) (vtx + 6) & 0x1FF, rgb);
            out->color[0] = (vtx[12] * rgb[0]) >> 8;
            out->color[1] = (vtx[13] * rgb[1]) >> 8;
            out->color[2] = (vtx[14] * rgb[2]) >> 8;
        } else {
            out->color[0] = vtx[12];
            out->color[1] = vtx[13];
            out->color[2] = vtx[14];
        }
        if (tint && (tint[0] != 255 || tint[1] != 255 || tint[2] != 255)) {
            out->color[0] = (out->color[0] * tint[0]) >> 8;
            out->color[1] = (out->color[1] * tint[1]) >> 8;
            out->color[2] = (out->color[2] * tint[2]) >> 8;
        }
        out->unk_0[0] = out->unk_0[1] = out->unk_0[2] = 0;
    }
    return buf;
}

// Frees a buffer from entrypoint_0.
s32 glpackvtx_entrypoint_1(void *buf)
{
    heap_free(buf);
}
