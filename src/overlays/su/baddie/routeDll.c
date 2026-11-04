#include "common.h"

typedef struct {
    s16 handle;
    s16 count;
} RouteAllocation;
extern void *func_800CC63C(s32, s32);
extern f32 func_800EFC7C(void *, void *);
typedef struct SubaddieRouteNode {
    u8 pad_0[0xC];
    s16 radius;
} SubaddieRouteNode;
typedef struct {
    s16 handle;
    s16 count;
} RouteSlot;
extern s16 *func_801015B0(void);
extern u8 *func_80106F30(Actor *);
extern s32 func_800CC5F4();
extern void *func_8001B798();
extern s16 func_8001B668(s32, s32);
typedef struct {
    u8 pad_0[0x70];
    u32 route : 7;
    u32 pad_1 : 25;
} RouteSel;
typedef struct {
    s16 id;
    s16 count;
} RouteEntry;
extern void func_8001B754();
extern void func_800EE88C(f32 *, void *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_80102D98(Actor *, s32, s32, s32, f32, f32);
typedef struct {
    f32 center[3];
    s16 radius;
} RouteSphere1506;
typedef struct {
    u8 pad_0[6];
    u16 flags;
} RouteResult1506;
extern s32 func_800CC61C(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800F13F0(f32, f32);
typedef struct {
    u8 center[0xC];
    s16 radius;
} RoutePlane49;
extern int func_800F05F8(f32 *, f32 *, RoutePlane49 *, f32, f32 *);
extern f32 func_800F0E00(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 *func_800BE444(f32 *);
extern f32 func_800F1DCC(f32, f32);
typedef struct {
    s16 handle;
    s16 pad_2;
} RouteDirectory62;
extern void *func_800CC684(s32, s32);
extern s32 func_800F0064(f32 *, f32, f32 *);
typedef struct {
    f32 center[3];
    s16 radius;
    s16 half_height;
} Broad51RouteNode;
typedef struct {
    u32 route : 7;
    u32 pad_1 : 15;
    u32 node : 6;
    u32 pad_0 : 4;
} Broad51RouteFlags;
extern s32 func_800F00A4(void *, f32, f32, f32, f32 *);
extern s32 func_8010BFA4(f32 *, f32 *, void *, f32);
typedef struct {
    u8 pad_0[0x70];
    u32 route : 7;
    u32 pad_1 : 15;
    u32 node : 6;
    u32 pad_2 : 4;
} RouteSelection211;
typedef struct {
    u8 pad_0[0x18];
    u16 unk_18;
    u8 pad_1[10];
    u32 unk_24 : 10;
    u32 pad_2 : 22;
} RouteContactMarker;
typedef struct {
    u8 pad_0[0x64];
    u32 unk_64 : 1;
    u32 pad_1 : 31;
} RouteContactActor;
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800EC708(Unk80132ED0 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct {
    s32 marker;
    s32 unk_4;
    u32 flags;
} Broad42RouteRecord;
typedef struct {
    f32 center[3];
    f32 radius;
} Broad42RouteSphere;
extern f32 func_800EEB40(f32 *, f32 *);
extern Broad42RouteRecord *func_800E9E88(s32);
extern Broad42RouteRecord *func_800E9EB4(s32);
extern f32 func_8008FE3C(f32 *);
extern void func_800EF11C(f32 *, void *);
extern f32 func_800EFBFC(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x60];
    u32 pad_1 : 16;
    u32 unk_62 : 16;
} RouteClampFlags;
int func_80800564_subaddierouteDll();
s32 func_80800F34_subaddierouteDll();
s32 func_8080160C_subaddierouteDll(Actor *actor, s32 result, f32 yaw, f32 dist,
                                   s32 flags, s32 cubes);
s32 func_80800D88_subaddierouteDll(Actor *actor, u8 *result, f32 yaw, s32 flags,
                                   s32 *cubes);
s32 func_80801784_subaddierouteDll();
f32 func_8080183C_subaddierouteDll(Actor *actor, f32 dist);

// Build the table of route slots, one per zone group.
void func_80800000_subaddierouteDll(void)
{
    s32 size;
    RouteAllocation *dll;
    dll = func_801015B0();
    dll->count = func_800CC5E8();
    size = dll->count * 4;
    if (size) {
        dll->handle = func_8001B668(0, size);
        func_8001B7F0(dll->handle, 0, size);
        func_801015BC();
    } else
        dll->handle = 0;
}

// Free all route graphs (map unload).
void subaddierouteDll_entrypoint_0(void)
{
    s32 slots;
    s32 offset;
    s32 i;
    u8 *dll;

    dll = func_801015B0();
    if (*(s16 *) dll != 0) {
        i = 0;
        offset = 0;
        if (*(s16 *) (dll + 2) > 0) {
            do {
                slots = (s32) func_8001B798(*(s16 *) dll);
                if (*(s16 *) (slots + offset) != 0) {
                    func_8001B754(*(s16 *) (slots + offset));
                }
                i += 1;
                offset += 4;
            } while (i < *(s16 *) (dll + 2));
        }
        func_8001B754(*(s16 *) dll);
        *(s16 *) dll = 0;
    }
    *(s16 *) (dll + 2) = 0;
}

// Fill per-node offsets and return the size of the adjacency data of a zone group.
s32 func_8080011C_subaddierouteDll(s32 group, s16 *offsets)
{
    u8 *node_a;
    u8 *node_b;
    s32 count;
    s32 size;
    s32 i;
    s32 neighbours;
    s32 j;

    count = func_800CC5F4();
    size = (count * 2 + 3) & ~3;
    for (i = 0; i < count; i++) {
        offsets[i] = size;
        node_a = func_800CC63C(group, i);
        neighbours = 1;
        for (j = 0; j < count; j++) {
            if (i != j) {
                node_b = func_800CC63C(group, j);
                if (func_800EFC7C(node_a, node_b) <
                    (f32) ((*(s16 *) (node_b + 0xC) + *(s16 *) (node_a + 0xC)) *
                           (*(s16 *) (node_b + 0xC) + *(s16 *) (node_a + 0xC)))) {
                    neighbours++;
                }
            }
        }
        size += (neighbours + 3) & ~3;
    }
    return size;
}

// Write the neighbour list of one node: count, then neighbour indices.
void func_8080024C_subaddierouteDll(u8 *list, s32 group, s32 index)
{
    u8 *cursor = list + 1;
    SubaddieRouteNode *other;
    SubaddieRouteNode *node;
    s32 count;
    s32 i;

    count = func_800CC5F4(group);
    node = func_800CC63C(group, index);
    for (i = 0; i < count; i++) {
        if (index != i) {
            other = func_800CC63C(group, i);
            if (func_800EFC7C(node, other) < (f32) ((node->radius + other->radius) *
                                                         (node->radius + other->radius))) {
                *cursor++ = i;
            }
        }
    }
    list[0] = cursor - list - 1;
}

// Assign the actor's route; builds the zone graph on first use, else adds a reference.
void subaddierouteDll_entrypoint_1(Actor *actor)
{
    s16 offsets[128];
    s32 pad[2];
    s32 route;
    s16 *dll;
    u8 *unk_0;
    s32 count;
    RouteSlot *slots;
    s16 *table;
    s16 *graph;
    s32 i;

    route = (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1;
    dll = func_801015B0();
    if (*dll == 0) {
        func_80800000_subaddierouteDll();
    }
    if (route < 0) {
        unk_0 = func_80106F30(actor);
        if (unk_0 != NULL && (*(u32 *) (unk_0 + 0xC) >> 20) != 0) {
            route = (*(u32 *) (unk_0 + 0xC) >> 20) - 1;
        }
    }
    count = func_800CC5F4(route);
    slots = func_8001B798(*dll);
    if (slots[route].handle != 0) {
        slots[route].count++;
        return;
    }
    slots[route].handle = func_8001B668(0, func_8080011C_subaddierouteDll(route, offsets));
    slots[route].count = 1;
    table = func_8001B798(slots[route].handle);
    for (i = 0; i < count; i++) {
        table[i] = offsets[i];
        graph = func_8001B798(((RouteSlot *) func_8001B798(*dll))[route].handle);
        func_8080024C_subaddierouteDll((u8 *) graph + graph[i], route, i);
    }
}

// Drop one reference to the actor's route graph; free it at zero.
void subaddierouteDll_entrypoint_2(Actor *actor)
{
    s32 route;
    RouteEntry *slots;

    route = ((RouteSel *) actor)->route - 1;
    slots = func_8001B798(*func_801015B0());
    slots[route].count--;
    if (slots[route].count == 0) {
        func_8001B754(slots[route].id);
        slots[route].id = 0;
    }
}

s32 subaddierouteDll_entrypoint_3(s32 unk_0, s32 result, s32 unk_2)
{
    rare_memset(result, 0, 0xC);
    return func_80800564_subaddierouteDll(unk_0, result);
}

// Clear the steering result.
int func_80800564_subaddierouteDll(unk_0, result)
s32 unk_0;
s32 *result;
{
    *(s16 *) ((char *) result + 0x6) = 0;
    result[2] = 0;
}

s32 subaddierouteDll_entrypoint_4(u8 **unk_0)
{
    s32 value;
    value = (((u16) *(u16 *) ((s8 *) *unk_0 + 0x12) & 0xFFFFFFFFu) >> 1) & 3;
    return func_8001210C(3) == value;
}

void func_808005B0_subaddierouteDll(Actor *actor, void *target, f32 unk_2, f32 unk_3,
                                    f32 unk_4)
{
    f32 target_pos[3];
    func_800EE88C(target_pos, target);
    actor->unk54 = func_800136E4(func_800F1DF4(actor->position, target_pos) + 180.0f);
    if (!func_80102CF4(actor, 40.0f)) {
        func_80102BF8(actor, unk_2, unk_3, unk_4);
    }
}

// With flag 4 the actor turns away from the target first.
void subaddierouteDll_entrypoint_5(s32 actor, s32 target, s32 flags, f32 unk_3, f32 unk_4,
                                   f32 unk_5)
{
    if (flags & 4) {
        func_808005B0_subaddierouteDll(actor, target, unk_3, unk_4, unk_5);
    } else {
        func_80102BF8(actor, unk_3, unk_4, unk_5);
    }
}

s32 subaddierouteDll_entrypoint_6(Actor *actor, s32 unk_1, u32 flags, s32 unk_3,
                                  s32 unk_4, s32 unk_5, s32 unk_6)
{
    if (flags & 0x1C) {
        return 0;
    }
    return func_80102D98(actor, unk_3, 0, unk_4, (f32) unk_5, (f32) unk_6);
}

// Returns 0 and sets result flag 2 when the step is blocked.
s32 func_808006D0_subaddierouteDll(Actor *actor, s32 result, f32 yaw, f32 dist,
                                   s32 flags)
{
    f32 step[3];
    f32 t[2];
    s32 route;
    s32 count;
    s32 i;
    RouteSphere1506 *zone;

    route = (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1;
    count = func_800CC61C(route);
    if (!count)
        return 1;
    func_800EEB9C(step, yaw, dist);
    for (i = count - 1; i >= 0; i--) {
        zone = (RouteSphere1506 *) func_800CC684(route, i);
        if (func_800F05F8(actor->position, step, zone->center, zone->radius,
                          t) == 2 &&
            t[0] >= 0.0f && t[1] >= 0.0f &&
            func_800F13F0(t[0], t[1]) < 1.0f) {
            ((RouteResult1506 *) result)->flags |= 2;
            return 0;
        }
    }
    return 1;
}

// TU-NOTE: the .bss of this file is defined here in C, ahead of its first use: IDO places .bss objects
// used before their definition first, the rest in definition order.
s16 B_808018E0_subaddierouteDll[32];

// Walk the step through the neighbouring zones; returns 0 and sets result flag 1 if it leaves them.
s32 func_80800828_subaddierouteDll(Actor *actor, u8 *result, f32 yaw, f32 dist,
                                   s32 flags)
{
    f32 end[3];
    f32 pos[3];
    f32 step[3];
    f32 t[2];
    s32 route;
    s32 node;
    RoutePlane49 *zone;
    node = ((*(u32 *) ((u8 *) actor + 0x70) << 22) >> 26) - 1;
    route = (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1;
    func_800EE7F8(pos, actor->position);
    func_800EEB9C(step, yaw, dist);
    func_800EE7F8(pos, actor->position);
    end[0] = pos[0] + step[0];
    end[2] = pos[2] + step[2];
    B_808018E0_subaddierouteDll[0] = node;
    B_808018E0_subaddierouteDll[1] = -1;
    for (;;) {
        zone = func_800CC63C(route, node);
        if (func_800F0064(zone, zone->radius, end))
            return 1;
        switch (func_800F05F8(pos, step, zone, zone->radius, t)) {
            case 0:
                return 1;
            case 1:
                if (t[0] < 0.0f)
                    return 1;
                break;
            case 2:
                t[0] = func_800F0E00(t[0], t[1]);
                if (t[0] < 0.0f)
                    return 1;
                break;
        }
        pos[0] += step[0] * t[0];
        pos[2] += step[2] * t[0];
        step[0] -= step[0] * t[0];
        step[2] -= step[2] * t[0];
        node =
            func_80800F34_subaddierouteDll(pos, route, node, B_808018E0_subaddierouteDll);
        if (node == -1) {
            *(u16 *) (result + 6) |= 1;
            return 0;
        }
    }
}

// Probe ahead at 0.6 of the actor's height; returns 0 and sets result flag 8 or 0x10 if something is hit.
s32 func_80800A74_subaddierouteDll(Actor *actor, u8 *result, f32 yaw, f32 dist,
                                   s32 flags)
{
    f32 to[3];
    f32 from[3];
    f32 hit[3];
    f32 slope_dir;

    f32 diff;

    if (!(flags & 0x2000) &&
        !func_800CC6CC((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1,
                       ((*(u32 *) ((u8 *) actor + 0x70) << 22) >> 26) - 1)) {
        return 1;
    }
    func_800EE7F8(from, actor->position);
    func_800EE7F8(to, actor->position);
    func_800EF1B8(to, yaw, dist);
    from[1] += 0.6f * func_800EC708(actor->unk0);
    to[1] = from[1];
    if (func_800BEF00(from, to, hit, actor->unk14)) {
        if (func_800F1EA4(hit, &slope_dir)) {
            diff = func_800F1DCC(yaw + 180.0f, slope_dir);
            *(u16 *) (result + 6) |= (diff > 0.0f ? 0x10 : 8);
        }
        return 0;
    }
    return 1;
}

// Steer towards target: try the heading yaw, then probe in 30-degree steps left and right.
s32 subaddierouteDll_entrypoint_7(Actor *actor, s32 result, f32 yaw, f32 target, f32 dist, s32 flags)
{
    s32 *cubes;
    Actor *self = actor; // Matching: unused alias, needed for the match.
    s32 i;
    f32 angle_a;
    f32 angle_b;
    f32 step_a;
    f32 step_b;
    f32 tmp;
#define Y (*(f32 *) &yaw)

    func_80800564_subaddierouteDll();
    if (flags & 0x1000) {
        dist = func_8080183C_subaddierouteDll(actor, dist);
    }
    cubes = func_800BE444(actor->position);
    if (flags & 0x800) {
        func_80800D88_subaddierouteDll(actor, result, Y, flags, cubes);
    }
    if (flags & 0x4000) {
        tmp = Y;
        Y = target;
        target = tmp;
    }
    angle_a = func_800F1DCC(target, Y);
    if (func_8080160C_subaddierouteDll(actor, result, Y, dist, flags, cubes)) {
        return 1;
    }
    if (angle_a < 0.0f) {
        step_a = -30.0f;
        step_b = 30.0f;
    } else {
        step_a = 30.0f;
        step_b = -30.0f;
    }
    angle_a = Y;
    angle_b = angle_a;
    i = 4;
    do {
        angle_a = func_800136E4(angle_a + step_a);
        if (func_8080160C_subaddierouteDll(actor, result, angle_a, dist, flags, cubes)) {
            return 1;
        }
        angle_b = func_800136E4(angle_b + step_b);
        if (func_8080160C_subaddierouteDll(actor, result, angle_b, dist, flags, cubes)) {
            return 1;
        }
    } while (--i != 0);
    return 0;
}

// Search the nearby cubes for another actor overlapping the step; fills result and returns 1.
s32 func_80800D88_subaddierouteDll(Actor *actor, u8 *result, f32 yaw, s32 flags,
                                   s32 *cubes)
{
    f32 radius;
    f32 dist_sq;
    f32 pos[1];
    Broad42RouteRecord *record;
    Broad42RouteRecord *end;
    Broad42RouteSphere sphere;
    s32 marker;
    s32 *cube;

    radius = func_800EC708(actor->unk0) * 0.7f;
    func_800EE7F8(pos, actor->position);
    func_800EF11C(pos, (u8 *) actor->unk0 + 0x1E);
    func_800EF1B8(pos, yaw, 0.6f * radius);
    cube = cubes;
    if (cube == NULL) {
        cube = func_800BE444(actor->position);
    }
    while (*cube) {
        record = func_800E9E88(*cube);
        end = func_800E9EB4(*cube);
        while (record < end) {
            if (record->flags & 1) {
                marker = record->marker;
                if (func_80801784_subaddierouteDll(actor, marker, flags, &sphere)) {
                    dist_sq = func_800EEB40(pos, sphere.center);
                    if (dist_sq < (radius + sphere.radius) * (radius + sphere.radius)) {
                        func_800EE940(result, &sphere);
                        *(s32 *) (result + 8) = marker;
                        *(u16 *) (result + 6) |= 4;
                        return 1;
                    }
                }
            }
            record++;
        }
        cube++;
    }
    return 0;
}

// Find a neighbour of the node that contains pos and is not in visited; appends it and returns its neighbour index, or -1.
s32 func_80800F34_subaddierouteDll(pos, route, node, visited)
Actor *pos;
s32 route;
s32 node;
s16 *visited;
{
    u8 *data;
    s32 count;
    s32 i;
    s32 seen;
    s32 k;
    u8 *zone;

    data = func_8001B798((s16 *) func_801015B0()[0]);
    data = func_8001B798(((RouteDirectory62 *) data)[route].handle);
    data = ((s16 *) data)[node] + data;
    count = *data++;
    for (i = 0; i < count; i++, data++) {
        seen = 0;
        for (k = 0; visited[k] != -1; k++) {
            if (!seen && visited[k] == *data)
                seen = 1;
        }
        if (!seen) {
            zone = func_800CC63C(route, *data);
            if (func_800F0064(zone, (f32) *(s16 *) (zone + 0xC), pos)) {
                visited[k] = *data;
                visited[k + 1] = -1;
                return i;
            }
        }
    }
    return -1;
}

// Update the actor's current node as it moves; returns 1 and resets its position to pos if it is outside the zones.
s32 subaddierouteDll_entrypoint_8(Actor *actor, f32 *pos, s32 unk_2, s32 unk_3)
{
    s32 route;
    s32 count;
    s32 i;
    s16 *dll;
    s32 node;
    u8 *data;
    Broad51RouteNode *zone;
    route = ((Broad51RouteFlags *) ((u8 *) actor + 0x70))->route - 1;
    node = ((Broad51RouteFlags *) ((u8 *) actor + 0x70))->node - 1;
    dll = (s16 *) func_801015B0();
    count = func_800CC61C(route);
    for (i = 0; i < count; i++) {
        zone = func_800CC684(route, i);
        if (zone->center[1] - zone->half_height < actor->position[1] &&
            actor->position[1] < zone->center[1] + zone->half_height &&
            func_800F0064(zone->center, zone->radius, actor->position)) {
            func_800EE7F8(actor->position, pos);
            return 1;
        }
    }
    zone = func_800CC63C(route, node);
    if (zone->center[1] - zone->half_height < actor->position[1] &&
        actor->position[1] < zone->center[1] + zone->half_height &&
        func_800F0064(zone->center, zone->radius, actor->position)) {
        return 0;
    }
    dll = func_8001B798(*dll);
    data = func_8001B798(*(s16 *) ((u8 *) dll + route * 4));
    data = ((s16 *) data)[node] + data;
    count = *data++;
    for (i = 0; i < count; i++, data++) {
        zone = func_800CC63C(route, *data);
        if (zone->center[1] - zone->half_height < actor->position[1] &&
            actor->position[1] < zone->center[1] + zone->half_height &&
            func_800F0064(zone->center, zone->radius, actor->position)) {
            ((Broad51RouteFlags *) ((u8 *) actor + 0x70))->node = *data + 1;
            return 0;
        }
    }
    func_800EE7F8(actor->position, pos);
    return 1;
}

// Like entrypoint_8, with flag 2 resetting the position at once.
s32 subaddierouteDll_entrypoint_9(Actor *actor, f32 *pos, s32 unk_2, s32 flags)
{
    u8 *zone;
    s32 route;
    s32 node;
    s32 i;
    s32 count;
    s32 j;
    u8 *data;
    void *dll;

    route = (s32) ((RouteSelection211 *) actor)->route - 1;
    node = (s32) ((RouteSelection211 *) actor)->node - 1;
    dll = func_801015B0();
    count = func_800CC61C(route);
    for (i = 0; i < count; i++) {
        zone = func_800CC684(route, i);
        if (func_800F00A4(zone, (f32) *(s16 *) (zone + 0xC), (f32) *(s16 *) (zone + 0xE),
                          (f32) - *(s16 *) (zone + 0xE), actor->position)) {
            if (flags & 2) {
                func_800EE7F8(actor->position, pos);
                return 1;
            }
            if (!func_8010BFA4(actor->position, pos, zone,
                               (f32) *(s16 *) (zone + 0xC))) {
                return 1;
            }
            for (j = 0; j < count; j++) {
                zone = func_800CC684(route, j);
                if (j != i &&
                    func_800F0064(zone, (f32) *(s16 *) (zone + 0xC), actor->position)) {
                    func_800EE7F8(actor->position, pos);
                    return 1;
                }
            }
            break;
        }
    }
    zone = func_800CC63C(route, node);
    if (func_800F00A4(zone, (f32) *(s16 *) (zone + 0xC), (f32) *(s16 *) (zone + 0xE),
                      (f32) - *(s16 *) (zone + 0xE), actor->position)) {
        return 0;
    }
    data = func_8001B798(((s16 *) dll)[0]);
    data = func_8001B798(((RouteDirectory62 *) data)[route].handle);
    data = ((s16 *) data)[node] + data;
    count = *data++;
    for (i = 0; i < count; i++, data++) {
        zone = func_800CC63C(route, *data);
        if (func_800F00A4(zone, (f32) *(s16 *) (zone + 0xC), (f32) *(s16 *) (zone + 0xE),
                          (f32) - *(s16 *) (zone + 0xE), actor->position)) {
            ((RouteSelection211 *) actor)->node = *data + 1;
            return 0;
        }
    }
    func_800EE7F8(actor->position, pos);
    return 1;
}

// Run the enabled probes for heading yaw (flags 0x200, 0x100, 0x400 skip one each); on success set the actor's heading and return 1.
s32 func_8080160C_subaddierouteDll(Actor *actor, s32 result, f32 yaw, f32 dist,
                                   s32 flags, s32 cubes)
{
    if (!(flags & 0x200) &&
        !func_808006D0_subaddierouteDll(actor, result, yaw, dist, flags)) {
        return 0;
    }
    if (!(flags & 0x100) &&
        !func_80800828_subaddierouteDll(actor, result, yaw, dist, flags)) {
        return 0;
    }
    if (!(flags & 0x400) &&
        !func_80800A74_subaddierouteDll(actor, result, (f32) func_800DC128(-20, 20) + yaw,
                                        dist, flags)) {
        return 0;
    }
    actor->unk54 = yaw;
    return 1;
}

s32 func_808016F0_subaddierouteDll(RouteContactMarker **owner, RouteContactMarker *other,
                                   s32 flags)
{
    if (*owner == other)
        return 2;
    if ((flags & 2) && (other->unk_18 & 1)) {
        return ((RouteContactActor *) func_80106790((Unk80132ED0 *) other))->unk_64 ? 0 : 4;
    }
    if ((flags & 1) && !other->unk_24)
        return 1;
    return 3;
}

// Build the bounding sphere of another marker (center, radius at index 3); returns 0 to ignore it.
s32 func_80801784_subaddierouteDll(owner, other, flags, sphere)
RouteContactMarker **owner;
RouteContactMarker *other;
s32 flags;
f32 *sphere;
{
    f32 radius;
    Actor *other_actor;

    switch (func_808016F0_subaddierouteDll(owner, other, flags)) {
        case 0:
            other_actor = func_80106790((Unk80132ED0 *) other);
            radius = func_800EC708((Unk80132ED0 *) *owner) * 0.7f;
            sphere[3] = radius;
            func_800EE7F8(sphere, other_actor->position);
            func_800EF11C(sphere, (u8 *) other + 0x1E);
            return 1;
        case 1:
            sphere[3] = func_8008FE3C(sphere) * 4.0f;
            return 1;
    }
    return 0;
}

// Limit the step distance (used with flag 0x1000).
f32 func_8080183C_subaddierouteDll(Actor *actor, f32 dist)
{
    f32 value;
    value = func_800F13F0(dist, func_800EFBFC(actor->position, (f32 *) actor->actorData));
    return func_800F0E00(value, (actor->scale * 1.2f) * ((RouteClampFlags *) actor)->unk_62);
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
