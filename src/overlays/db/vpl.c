#include "common.h"

typedef struct {
    s16 position[3];
    u16 flags;
    s16 uv[2];
    u8 color[4];
} DbVplVertex;

// Find the record with the given id in the offset table (count at +0x2C, offsets at +0x30).
s32 *dbvpl_entrypoint_0(u8 *model, s32 id)
{
    s32 i;
    s32 *rec;
    for (i = 0; i < *(s32 *) (model + 0x2C); i++) {
        rec = (s32 *) (model + ((s32 *) (model + 0x30))[i]);
        if (*rec == id) {
            return rec;
        }
    }
    return 0;
}

// Copy the vertices of a module into the map vertex buffer at their stored index,
// scaling RGB by tint (0..255) and re-tagging the index.
void dbvpl_entrypoint_1(s32 unk_0, DbVplVertex *map_vtx, s32 module, s32 *tint)
{
    DbVplVertex *first;
    DbVplVertex *src;
    DbVplVertex *end;
    DbVplVertex *dst;
    s32 c;
    u32 index;

    func_800B2324(module, &first, &end);
    for (src = first; src < end; src++) {
        index = src->flags & 0x7FFF;
        if (index != 0x7FFF) {
            dst = &map_vtx[index];
            if (tint[0] != 255 || tint[1] != 255 || tint[2] != 255) {
                for (c = 0; c < 3; c++) {
                    src->color[c] = (src->color[c] * tint[c]) >> 8;
                }
            }
            aligned8_memcpy(dst, src, sizeof(DbVplVertex));
            dst->flags &= 0x8000;
            dst->flags |= (src - first) & 0x7FFF;
        }
    }
}
