#include "common.h"

extern f32 func_800F2290(f32 *, f32 *);
extern void func_800F2388(f32 *, f32 *, f32 *);

// Computes S and T of point relative to entry along the two axes.
void func_80800000_dbshift(f32 *entry, f32 *axis_u, f32 *point, f32 *axis_v, f32 *out)
{
    f32 denom;
    f32 rel[2];
    denom = func_800F2290(axis_u, axis_v);
    func_800F2388(rel, point, entry);
    out[0] = func_800F2290(rel, axis_v) / denom;
    out[1] = func_800F2290(rel, axis_u) / denom;
}

// Returns the record count.
int dbshift_entrypoint_0(s32 section[1])
{
    return section[0];
}

// Writes projected S/T coordinates (x64 fixed point) for the vertices of one shift record.
void dbshift_entrypoint_1(s32 *section, s32 model, s32 record_idx, s32 point)
{
    u8 *vtx;
    u8 *entry;
    s32 i;
    u8 *record;
    f32 st[2];
    if (record_idx >= 0 && record_idx < *section) {
        record = (u8 *) section + 4;
        for (i = 0; i < record_idx; i++)
            record += *(s16 *) (record + 0x1A) * 8 + 0x1C;
        vtx = *(s16 *) (record + 0x18) * 0x10 + (u8 *) func_800B2190(model);
        entry = record + 0x1C;
        for (i = 0; i < *(s16 *) (record + 0x1A);
             i++, entry += 8, vtx += 0x10) {
            func_80800000_dbshift(entry, record, point, record + 8, st);
            *(s16 *) (vtx + 8) =
                (s32) ((-st[0] * *(f32 *) (record + 0x10) - 0.5f) * 64.0f);
            *(s16 *) (vtx + 0xA) =
                (s32) ((st[1] * *(f32 *) (record + 0x14) - 0.5f) * 64.0f);
        }
    }
}
