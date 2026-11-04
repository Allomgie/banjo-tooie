#include "common.h"

// Zone list layout: u8 count, u8 pad, then 14-byte entries (6 s16 box bounds, inside flag at 0xC).
typedef struct {
    u8 pad_0[12];
    u8 inside;
    u8 pad_D;
} DbZoneFlag27;
typedef struct {
    u8 pad_0[12];
    u8 inside;
    u8 pad_D;
} ZoneEntry;
typedef struct {
    u8 count;
    u8 pad_1;
    ZoneEntry entries[1];
} ZoneList;
typedef struct {
    s16 unk_0;
    s16 box[6];
} ZoneEnt;
typedef struct {
    s16 box[7];
} DbQueryZone1262_dbzone_entrypoint_3;
extern void func_800EE940();

typedef struct DbQueryZone1262_dbzone_entrypoint_4 {
    s16 box[7];
} DbQueryZone1262_dbzone_entrypoint_4;

// Returns 1 if any of the 'count' zones listed in 'ids' is flagged inside.
s32 dbzone_entrypoint_0(u8 *list, u8 *ids, u32 count)
{
    DbZoneFlag27 *zones;

    zones = (DbZoneFlag27 *) (list + 2);
    for (; count; count--) {
        if (zones[*ids].inside) {
            return 1;
        }
        ids++;
    }
    return 0;
}

// Point-in-box test: box is {min x, y, z, max x, y, z}.
int func_8080010C_dbzone(void *zone, s16 *point)
{
    s16 *box;

    box = zone;
    return point[0] >= box[0] && point[0] <= box[3] && point[1] >= box[1] &&
           point[1] <= box[4] && point[2] >= box[2] && point[2] <= box[5];
}

// Updates every zone's inside flag for a position moved into model space.
void dbzone_entrypoint_1(ZoneList *list, f32 *pos, f32 scale, f32 *origin)
{
    s32 i;
    ZoneEntry *e;
    ZoneEntry *end;
    s32 pad;
    s16 point[3];

    scale = 1.0f / scale;
    for (i = 0; i < 3; i++) {
        point[i] = (pos[i] - origin[i]) * scale;
    }
    e = list->entries;
    end = &e[list->count];
    for (; e < end; e++) {
        e->inside = func_8080010C_dbzone(e, point);
    }
}

void dbzone_entrypoint_2(ZoneEnt *zones, f32 *pos, s32 index)
{
    s32 point[3];
    func_800EE940(point, pos);
    func_8080010C_dbzone(zones[index].box, point);
}

// Returns the index of the first zone containing pos, or -1.
s32 dbzone_entrypoint_3(u8 *list, f32 *pos)
{
    DbQueryZone1262_dbzone_entrypoint_3 *zone;
    DbQueryZone1262_dbzone_entrypoint_3 *end;
    DbQueryZone1262_dbzone_entrypoint_3 *first;
    s16 point[3];

    end =
        (DbQueryZone1262_dbzone_entrypoint_3 *) (list + 2 +
                                                 list[0] *
                                                     sizeof(DbQueryZone1262_dbzone_entrypoint_3));
    func_800EE940(point, pos);
    first = (DbQueryZone1262_dbzone_entrypoint_3 *) (list + 2);
    for (zone = first; zone < end; zone++) {
        if (func_8080010C_dbzone(zone, point)) {
            return zone - first;
        }
    }
    return -1;
}

// Writes the indices of all zones containing pos to 'out'; returns how many.
s32 dbzone_entrypoint_4(u8 *list, f32 *pos, u8 *out)
{
    DbQueryZone1262_dbzone_entrypoint_4 *zone;
    DbQueryZone1262_dbzone_entrypoint_4 *end;
    DbQueryZone1262_dbzone_entrypoint_4 *first;
    s16 point[3];
    s32 count = 0;

    end =
        (DbQueryZone1262_dbzone_entrypoint_4 *) (list + 2 +
                                                 list[0] *
                                                     sizeof(DbQueryZone1262_dbzone_entrypoint_4));
    func_800EE940(point, pos);
    first = (DbQueryZone1262_dbzone_entrypoint_4 *) (list + 2);
    for (zone = first; zone < end; zone++) {
        if (func_8080010C_dbzone(zone, point)) {
            out[count++] = zone - first;
        }
    }
    return count;
}
