// This seems to be a per-object light set: a distance-sorted heap block of light entries that can
// gather nearby scene lights with falloff, add the global light, be copied and defragmented.
#include "common.h"
void func_800B38C8();

extern void *heap_alloc(u32);
// Light set: a heap block with the ambient color at +0, a cursor and an end pointer,
// followed by 0x1C-byte entries {f32 dir[3], s32 color[3], f32 distance} sorted by
// distance. The structs below are views of it.
struct Actor_800B3310 {
    u8 pad_0[0xC]; // ambient color
    s32 capacity;
    void *cursor;
    void *end;
};
typedef struct {
    u8 pad_0[0x18];
    f32 distance;
} LocalEntry;
typedef struct {
    u8 pad_0[0x10];
    LocalEntry *cursor, *end;
    LocalEntry entries[1];
} LocalBuffer;
typedef struct {
    f32 dir[3];
    s32 color[3];
    f32 distance;
} LightB3494;
typedef struct {
    u8 pad_0[0x10];
    LightB3494 *cursor;
    s32 pad_14;
    LightB3494 entries[1];
} CollectionB3494;
extern void *func_800C8760(s32, s32);
extern void *func_800C878C(void *, s32, s32);
extern void func_800C8800(void *, f32 *);
extern void func_800C8898(void *, f32 *);
extern void func_800C8900(void *, s32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE830();
extern f32 func_800EEF94(f32 *);
typedef struct {
    u8 pad_0[0x1C];
} local_entry;
typedef struct {
    u8 pad_0[0x10];
    local_entry *cursor;
    local_entry *end;
    local_entry entries[1];
} local_type;
extern void *defrag(void *);
int func_800B3784();

// Light set alloc/free, sorted insert, gather nearby lights, global light, copy, count, ambient.
// Allocates a light set with room for capacity entries; ambient starts as the global one.
struct Actor_800B3310 *func_800B3310(s32 capacity)
{
    struct Actor_800B3310 *set;

    set = heap_alloc(capacity * 0x1C + 0x18);
    func_800B38C8(set);
    set->cursor = (void *) ((u8 *) set + 0x18);
    set->end = (void *) ((u8 *) set->cursor + capacity * 0x1C);
    set->capacity = capacity;
    return set;
}

void func_800B3370(void *set)
{
    heap_free(set);
}

// Reserves the slot for an entry at the given distance, keeping the set sorted by
// distance. Farther entries move up; the farthest is dropped when the set is full.
// Returns 0 if there is no room.
LocalEntry *func_800B3390(LocalBuffer *set, f32 distance)
{
    LocalEntry *entry;
    s32 *dst;
    s32 *src;
    s32 bytes;
    entry = (LocalEntry *) ((u8 *) set + 0x18);
    for (; entry < set->cursor; entry++) {
        if (distance < entry->distance)
            break;
    }
    if (entry == set->cursor) {
        if (set->cursor < set->end) {
            set->cursor = set->cursor + 1;
            return entry;
        }
        return 0;
    }
    if (set->cursor == set->end)
        set->cursor--;
    dst = (s32 *) (set->cursor + 1);
    bytes = (set->cursor - entry) * sizeof(LocalEntry);
    dst--;
    src = (s32 *) set->cursor - 1;
    while (bytes > 0) {
        *dst-- = *src--;
        bytes -= 4;
    }
    set->cursor++;
    return entry;
}

// Adds the scene lights within range of pos: unit direction, color faded between the
// inner and outer radius.
void func_800B3494(CollectionB3494 *set, f32 *pos, f32 range)
{
    f32 dist, scale;
    void *light;
    LightB3494 *slot;
    f32 delta[3];
    f32 light_pos[3];
    f32 radii[3]; // inner radius, outer radius, falloff factor
    s32 light_color[3];
    s32 i;
    set->cursor = set->entries;
    for (light = func_800C8760(0, 1); light; light = func_800C878C(light, 0, 1)) {
        func_800C8800(light, light_pos);
        func_800C8898(light, radii);
        func_800EFB24(delta, light_pos, pos);
        dist = func_800EEF94(delta);
        if (dist >= radii[1] + range)
            continue;
        slot = func_800B3390(set, dist);
        if (!slot)
            continue;
        slot->distance = dist;
        scale = 1.0f / dist;
        for (i = 0; i < 3; i++) {
            slot->dir[i] = delta[i] * scale;
        }
        dist -= range;
        func_800C8900(light, light_color);
        if (dist <= radii[0]) {
            func_800EE830(slot->color, light_color);
        } else {
            scale = 1.0f - (dist - radii[0]) * radii[2];
            for (i = 0; i < 3; i++)
                slot->color[i] = light_color[i] * scale;
        }
    }
    func_800B3784(set);
}

// Appends an entry; returns 1 on success, 0 if the set is full.
int func_800B36C0(s32 *set, s32 dir, s32 *color, f32 distance)
{
    s32 cursor = set[4];
    if ((u32) cursor < (u32) set[5]) {
        func_800EE7F8((void *) cursor, dir);
        func_800EE830((void *) ((u32) set[4] + 0xC), color);
        *(f32 *) ((u32) set[4] + 0x18) = distance;
        set[4] += 0x1C;
        return 1;
    }
    return 0;
}

// Adds the global directional light with distance 500.0.
int func_800B3748(s32 set)
{
    f32 dir[3];
    f32 color[3];
    func_800C8960(color, dir);
    func_800B36C0(set, dir, color, 5e+02f);
}

// Returns the number of entries.
int func_800B3784(set)
s32 *set;
{
    return (set[4] - (s32) set - 0x18) / 0x1C;
}

// Returns the first entry and the end (cursor) of the entries.
int func_800B37A4(s32 set[5], s32 *out_first, s32 *out_end)
{
    out_first[0] = (s32 *) ((s8 *) set + 0x18);
    out_end[0] = *(s32 *) ((s8 *) set + 0x10);
}

int func_800B37B8(s32 src, s32 dst)
{
    // Matching: the "| 0" operands are needed for the match.
    func_800EE830(dst | 0, src | 0);
}

// Copies the entries of src that fit, and its ambient color, into dst.
void func_800B37E4(u8 *dst, u8 *src)
{
    u8 *entry;
    *(u32 *) (dst + 0x10) = (u32) (dst + 0x18);
    entry = src + 0x18;
    if ((u32) entry < *(u32 *) (src + 0x10)) {
        if (*(u32 *) (dst + 0x10) < *(u32 *) (dst + 0x14)) {
            do {
                aligned4_memcpy(*(u32 *) (dst + 0x10), (u32) entry, 0x1C);
                entry += 0x1C;
                *(u32 *) (dst + 0x10) += 0x1C;
            } while (((u32) entry < *(u32 *) (src + 0x10)) &&
                     (*(u32 *) (dst + 0x10) < *(u32 *) (dst + 0x14)));
        }
    }
    func_800EE830(dst, src);
}

// Limits the set to count entries by moving the end pointer.
int func_800B388C(s32 *set, s32 count)
{
    set[5] = (s32) ((u8 *) set + (count * 7) * 4) + 0x18;
}

// Sets the ambient color of a set.
void func_800B38A8()
{
    func_800EE830();
}

// Sets the ambient color of a set to the global ambient light.
void func_800B38C8()
{
    func_800C87B8();
}

// Defrag with pointer re-basing.
// Defragments the set's heap block and fixes the pointers if it moved.
local_type *func_800B38E8(local_type *set)
{
    s32 used;
    s32 capacity;
    local_type *moved;
    used = set->cursor - set->entries;
    capacity = set->end - set->entries;
    moved = defrag(set);
    if (moved != set) {
        set = moved;
        set->cursor = used + set->entries;
        set->end = capacity + set->entries;
    }
    return set;
}
