#include "common.h"

// Node prop record in a cube (0x14 bytes); the first three halfwords are the position.
typedef struct {
    u8 pad_0[4];
    u32 pad_4 : 25;
    u32 kind : 6;
    u32 enabled : 1;
    u16 id;
    u8 pad_A[8];
    u8 pad_12 : 7;
    u8 enabled_12 : 1;
    u8 pad_13;
} PropMarkerRecord;
extern PropMarkerRecord *func_800E9D68(s32);
extern PropMarkerRecord *func_800E9D90(s32);

typedef struct {
    s32 unk_0;
    u32 pad_4 : 25;
    u32 kind : 6;
    u32 enabled : 1;
    u16 id;
    u8 pad_A[8];
    u8 pad_12 : 7;
    u8 enabled_12 : 1;
    u8 pad_13;
} PropMarkerRecord32;

// First enabled kind-6 prop with the given id in the cube.
PropMarkerRecord *gspropmarker_entrypoint_0(s32 cube, s32 id)
{
    PropMarkerRecord *prop;
    PropMarkerRecord *end;

    if (cube && func_800E9DC4(cube)) {
        prop = func_800E9D68(cube);
        end = func_800E9D90(cube);
        for (; prop < end; prop++) {
            if ((prop->enabled == 1 || (prop->enabled == 0 && prop->enabled_12 == 1)) &&
                prop->kind == 6 && id == prop->id)
                return prop;
        }
    }
    return 0;
}

// Collects enabled kind-6 props whose id is in the -1 terminated list; returns the count.
s32 gspropmarker_entrypoint_1(s32 cube, s32 *ids, PropMarkerRecord32 **out, s32 max)
{
    s32 count;
    s32 pad0;
    PropMarkerRecord32 *prop;
    PropMarkerRecord32 *end;
    s32 *id_ptr;

    count = 0;
    if (!max) {
        return 0;
    }
    if (cube && func_800E9DC4(cube)) {
        prop = (PropMarkerRecord32 *) func_800E9D68(cube);
        end = (PropMarkerRecord32 *) func_800E9D90(cube);
        for (; prop < end && count < max; prop++) {
            if ((prop->enabled == 1 || prop->enabled == 0 && prop->enabled_12 == 1) &&
                prop->kind == 6) {
                for (id_ptr = ids; *id_ptr != -1; id_ptr++) {
                    if (prop->id == *id_ptr) {
                        out[count++] = prop;
                        break;
                    }
                }
            }
        }
    }
    return count;
}

// Writes the positions of enabled kind-6 props with the given id; returns the count.
s32 gspropmarker_entrypoint_2(s32 cube, s32 id, f32 out[][3], s32 max)
{
    s32 count;
    PropMarkerRecord *prop;
    PropMarkerRecord *end;

    count = 0;
    if (cube && func_800E9DC4(cube)) {
        prop = func_800E9D68(cube);
        end = func_800E9D90(cube);
        while (prop < end && count < max) {
            if ((prop->enabled == 1 || (prop->enabled == 0 && prop->enabled_12 == 1)) &&
                prop->kind == 6 && id == prop->id) {
                out[count][0] = ((s16 *) prop)[0];
                out[count][1] = ((s16 *) prop)[1];
                out[count][2] = ((s16 *) prop)[2];
                count++;
            }
            prop++;
        }
    }
    return count;
}

// Prop scale from the 23-bit parameter (x0.01, 0 = 1.0).
f32 gspropmarker_entrypoint_3(u32 *prop)
{
    u32 param = prop[3] & 0x7FFFFF;
    f32 scale;

    if (param != 0) {
        scale = param * 0.01f;
    } else {
        scale = 1.0f;
    }
    return scale;
}
