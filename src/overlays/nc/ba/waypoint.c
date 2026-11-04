#include "common.h"

// Waypoint: a point plus a plane (normal and offset).
typedef struct {
    f32 point[3];
    f32 normal[3];
    f32 offset;
    s32 pad_1C;
} CameraWaypoint61;
typedef struct {
    s32 count;
    CameraWaypoint61 entries[4];
} CameraWaypointList61;
typedef struct {
    u8 pad_0[0x5C];
    CameraWaypointList61 *list;
} CameraWaypointOwner61;
typedef struct {
    f32 point[3];
    f32 normal[3];
    f32 offset;
    f32 key; // distance to the player, sort key
} CameraWaypoint62;
typedef struct {
    s32 count;
    CameraWaypoint62 entries[4];
} CameraWaypointList62;
typedef struct {
    u8 pad_0[0x5C];
    CameraWaypointList62 *list;
} CameraWaypointOwner62;
extern f32 func_800EEAD4(f32 *, f32 *);
extern void aligned4_memcpy(void *, void *, s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);

s32 ncbawaypoint_entrypoint_0()
{
    return 0x84;
}

// Clears the waypoint list.
void ncbawaypoint_entrypoint_1(u8 *owner)
{
    **(s32 **) ((s8 *) owner + 0x5C) = 0;
}

// Adds a waypoint; returns 0 when the list is full.
s32 ncbawaypoint_entrypoint_2(CameraWaypointOwner61 *owner, f32 *point, f32 *normal,
                              f32 offset)
{
    CameraWaypoint61 *entry;

    if (owner->list->count >= 4) {
        return 0;
    }
    entry = &owner->list->entries[owner->list->count];
    func_800EE7F8(entry->point, point);
    func_800EE7F8(entry->normal, normal);
    entry->offset = offset;
    owner->list->count++;
    return 1;
}

// Sorts waypoints by distance to pos and routes pos through those whose plane the
// line pos->target crosses; returns the added distance.
f32 ncbawaypoint_entrypoint_3(CameraWaypointOwner62 *owner, f32 *pos, f32 *target)
{
    CameraWaypoint62 *end;
    CameraWaypoint62 *p;
    CameraWaypoint62 *q;
    CameraWaypoint62 tmp;
    f32 d1;
    f32 d2;
    f32 sum;

    sum = 0.0f;
    if (owner->list->count != 0) {
        end = &owner->list->entries[owner->list->count];
        for (p = owner->list->entries; p < end; p++) {
            p->key = func_800EEAD4(p->point, pos);
        }
        // Insertion sort by key.
        for (p = owner->list->entries + 1; p < end; p++) {
            q = p - 1;
            aligned4_memcpy(&tmp, p, sizeof(CameraWaypoint62));
            while (q >= owner->list->entries && tmp.key < q->key) {
                aligned4_memcpy(q + 1, q, sizeof(CameraWaypoint62));
                q--;
            }
            aligned4_memcpy(q + 1, &tmp, sizeof(CameraWaypoint62));
        }
        for (p = owner->list->entries; p < end; p++) {
            d1 = func_800EEAA4(target, p->normal) - p->offset;
            d2 = func_800EEAA4(pos, p->normal) - p->offset;
            if ((d2 <= 0.0f && d1 <= 0.0f) || (0.0f <= d2 && 0.0f <= d1)) {
                continue;
            }
            sum += func_800EEAD4(pos, p->point);
            func_800EE7F8(pos, p->point);
        }
    }
    return sum;
}
