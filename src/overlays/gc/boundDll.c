// Builder side of the map zone-volume system (core2/1EA5180): sets up and frees three zone lists,
// adds volumes from the map setup (merging into close groups) and recomputes centres and radii.
#include "common.h"

typedef struct {
    s32 a[6];
    u8 b[200];
    s32 c;
} BoundS;
extern void func_800B42DC(s32);
typedef struct {
    u8 pad_0[0xC];
    s16 radius;
    s16 half_height;
    u8 pad_1[4];
    u16 type : 11;
    u16 flag_a : 1;
    u16 kind : 3;
    u16 flag_b : 1;
} BoundItemProperties;
extern void *func_800B3CDC(void *, void *);
typedef struct {
    u32 unflagged_count : 23;
    u32 local_1 : 1;
    u32 flagged_count : 8;
    u8 pad_0[0x10];
    u32 key;
    u32 run;
} BoundNewRecord;
extern void *heap_realloc(void *, s32);
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    s16 r;
    s16 padE;
    f32 rsq;
    s32 pad14;
} BoundPt;
typedef struct {
    s32 unk0;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 rsq;
    s32 pad14[2];
} BoundSet;
typedef struct {
    f32 x;
    f32 z;
} BoundV2;
extern BoundV2 D_808015B0_gcboundDll;
extern BoundV2 D_808015B8_gcboundDll;
extern BoundV2 D_808015C0_gcboundDll;
extern BoundV2 D_808015C8_gcboundDll;
typedef struct {
    u8 pad_0[0x18];
    s16 id;
    u8 pad_1[2];
} BoundRecord1446;
typedef struct {
    u8 pad_0[0x14];
    u32 pad_1 : 11;
    u32 flag_a : 1;
    u32 pad_2 : 20;
} BoundHistory;
typedef struct {
    u32 unflagged_count : 23;
    u32 pad_0 : 1;
    u32 flagged_count : 8;
    u8 pad_1[0x16];
    s16 volume_count;
} BoundHistoryRecord;
typedef struct {
    u32 unk0 : 23;
    u32 pad0 : 1;
    u32 unk3 : 8;
    u8 pad4[0x10];
    s32 key;
    u8 run[2];
    s16 volume_count;
} GcBoundElem;
extern void func_800B422C(void *, void *);
extern void func_800B4290(void *);
extern void rare_memcpy(void *, void *, s32);
typedef struct {
    u8 unused[0x14];
    s32 key;
    s32 unused18;
} BoundRecord;
typedef struct {
    f32 pad_0;
    f32 y;
    s32 pad_1;
    s16 radius;
    u8 pad_2[10];
} BoundaryCircle;
extern s32 func_800F0064(f32 *, f32, void *);
int func_80800E6C_gcboundDll();
void func_80800EBC_gcboundDll();
// Merges groups with equal keys whose volumes overlap, packs the list and shrinks it.
void func_80800F6C_gcboundDll();
// Maps a kind id to its bit mask.
s32 func_8080132C_gcboundDll();
int func_808013D4_gcboundDll();
int func_8080141C_gcboundDll();
int func_80801450_gcboundDll();
// Returns 1 if pos, grown by margin, touches one of the group's volumes.
int func_80801484_gcboundDll();

// Resets the three group lists.
void gcboundDll_entrypoint_0(BoundS *state)
{
    s32 i;
    state->a[0] = state->a[1] = 0;
    state->a[2] = state->a[3] = 0;
    state->a[4] = state->a[5] = 0;
    for (i = 0; i < 200; i++) {
        state->b[i] = 1;
    }
    state->c = 0;
}

// Allocates the three group lists and the pool of 0x18-byte volumes.
int gcboundDll_entrypoint_1(Actor *builder)
{
    *(s32 *) ((char *) builder + 0x4) = heap_alloc(0);
    *(s32 *) ((char *) builder + 0xC) = heap_alloc(0);
    *(s32 *) ((char *) builder + 0x14) = heap_alloc(0);
    *(s32 *) ((char *) builder + 0xE0) = func_800B42FC(0x18, 0xA);
}

// Frees every group's volume run, then the list itself.
void func_808000AC_gcboundDll(s32 builder, s32 *count, u32 *list)
{
    u32 end;
    u32 base;
    u32 cur;

    base = *list;
    if (base != 0) {
        cur = base;
        end = (*count * 0x1C) + base;
        if (base < end) {
            do {
                func_800B422C(builder + 0xE0, cur + 0x18);
                cur += 0x1C;
            } while (cur < end);
            base = *list;
        }
        heap_free(base);
        *list = 0;
        *count = 0;
    }
}

void gcboundDll_entrypoint_2(u8 *builder)
{
    func_808000AC_gcboundDll(builder, builder, builder + 4);
    func_808000AC_gcboundDll(builder, builder + 8, builder + 0xC);
    func_808000AC_gcboundDll(builder, builder + 0x10, builder + 0x14);
    func_800B42DC(*(s32 *) (builder + 0xE0));
    *(s32 *) (builder + 0xE0) = 0;
}

// Appends a volume to the group's run and fills it in.
void func_808001A8_gcboundDll(u8 *builder, u8 *group, void *pos, s32 radius, s32 height,
                              s32 type, s32 flag_b, s32 flag_a, s32 kind)
{
    BoundItemProperties *volume;

    volume = func_800B3CDC(builder + 0xE0, group + 0x18);
    func_800EE88C(volume, pos);
    volume->radius = radius;
    volume->half_height = (s32) ((f32) height * 0.5f);
    volume->type = type;
    volume->flag_b = flag_b;
    volume->flag_a = flag_a;
    volume->kind = kind;
}

// Grows the list by one empty group and returns it.
BoundNewRecord *func_80800280_gcboundDll(s32 *count, BoundNewRecord **list, u32 key)
{
    BoundNewRecord *group;

    (*count)++;
    *list = heap_realloc(*list, *count * 0x1C);
    group = *list + *count - 1;
    group->unflagged_count = 0;
    group->flagged_count = 0;
    group->key = key;
    group->local_1 = 1;
    func_800B4290(&group->run);
    return group;
}

// Adds a volume to list 0, merging it into every nearby group with the same key, else new group.
void gcboundDll_entrypoint_3(u8 *builder, s32 key, s32 pos, s32 radius, s32 height,
                             s32 type, s32 flag_b, s32 flag_a)
{
    s32 group;
    s32 merged = 0;

    group = func_808013D4_gcboundDll(builder, key, flag_a, 0);
    while (group) {
        if (func_80801484_gcboundDll(builder, group, key, pos, radius)) {
            func_808001A8_gcboundDll(builder, group, pos, radius, height, type, flag_b,
                                     flag_a, 0);
            if (!flag_a)
                return;
            merged = 1;
        }
        group = func_808013D4_gcboundDll(builder, key, flag_a, group);
    }
    if (!flag_a || !merged) {
        func_808001A8_gcboundDll(builder, func_80800280_gcboundDll(builder, builder + 4, key),
                                 pos, radius, height, type, flag_b, flag_a, 0);
    }
}

// Adds a volume to list 1 (nearby group with the same key, else new group).
void gcboundDll_entrypoint_4(u8 *builder, s32 key, s32 pos, s32 radius, s32 kind_id,
                             s32 height)
{
    void *group;
    s32 kind;

    group = func_8080141C_gcboundDll(builder, key, NULL);
    while (group) {
        if (func_80801484_gcboundDll(builder, group, key, pos, radius))
            break;
        group = func_8080141C_gcboundDll(builder, key, group);
    }
    if (!group)
        group = func_80800280_gcboundDll((s32 *) (builder + 8),
                                           (BoundNewRecord **) (builder + 12), key);
    kind = func_8080132C_gcboundDll(kind_id);
    func_808001A8_gcboundDll(builder, group, pos, radius, height, 0, 0, 0, kind);
}

// Adds a volume to list 2 (nearby group with the same key, else new group).
void gcboundDll_entrypoint_5(u8 *builder, s32 key, s32 pos, s32 radius, s32 height,
                             s32 kind_id, s32 flag_b)
{
    void *group;

    group = func_80801450_gcboundDll(builder, key, NULL);
    while (group) {
        if (func_80801484_gcboundDll(builder, group, key, pos, radius))
            break;
        group = func_80801450_gcboundDll(builder, key, group);
    }
    if (!group)
        group = func_80800280_gcboundDll((s32 *) (builder + 16),
                                           (BoundNewRecord **) (builder + 20), key);
    func_808001A8_gcboundDll(builder, group, pos, radius, height, 0, flag_b, 0, kind_id);
}

// Start of the group's volumes.
int func_80800630_gcboundDll(builder, group)
Actor *builder;
s32 group;
{
    func_800B42A0(*(void **) ((char *) builder + 0xE0), group + 0x18);
}

// End of the group's volumes.
u8 *func_80800654_gcboundDll(builder, group)
{
    return *(s16 *) (group + 0x1A) * 24 + func_80800630_gcboundDll(builder, group);
}

int func_80800688_gcboundDll()
{
    func_80800630_gcboundDll();
}

// End of the group's unflagged volumes.
int func_808006A8_gcboundDll(builder, group)
s32 builder[3];
u32 *group;
{
    return ((*group >> 9) * 0x18) + func_80800688_gcboundDll(builder);
}

int func_808006E0_gcboundDll()
{
    func_808006A8_gcboundDll();
}

int func_80800700_gcboundDll()
{
    func_80800654_gcboundDll();
}

// Refreshes the flagged/unflagged counts of every group in a list.
void func_80800720_gcboundDll(s32 builder, s32 count, u32 list)
{
    u32 end;
    u32 cur;

    end = (count * 0x1C) + list;
    cur = list;
    if (list < end) {
        do {
            func_80800EBC_gcboundDll(builder, cur);
            cur += 0x1C;
        } while (cur < end);
    }
}

// Sorts the volumes of every group so flagged ones come last, then refreshes all counts.
void gcboundDll_entrypoint_6(u8 *builder)
{
    s32 count;
    s32 i;
    u8 *group;
    u8 *vol_begin;
    u8 *vol_end;
    u8 *scan;
    u8 *cur;
    u8 *next;
    count = *(s32 *) builder;
    group = *(u8 **) (builder + 4);
    for (i = 0; i < count; i++, group += 28) {
        vol_begin = (u8 *) func_80800630_gcboundDll(builder, group);
        vol_end = (u8 *) func_80800654_gcboundDll(builder, group);
        for (scan = vol_end - 48; scan >= vol_begin; scan -= 24) {
            cur = scan;
            next = scan + 24;
            while (cur < vol_end && ((*(u32 *) (cur + 20) << 11) >> 31) &&
                   !((*(u32 *) (next + 20) << 11) >> 31)) {
                func_80800E6C_gcboundDll(cur, next);
                cur += 24;
                next += 24;
            }
        }
        func_80800EBC_gcboundDll(builder, group);
    }
    func_80800720_gcboundDll(builder, *(s32 *) (builder + 8), *(s32 *) (builder + 12));
    func_80800720_gcboundDll(builder, *(s32 *) (builder + 16), *(s32 *) (builder + 20));
}

// Recomputes each group's centre and bounding radius (squared) from its volumes.
void func_808008D8_gcboundDll(void *builder, s32 count, BoundSet *groups)
{
    // Matching: unused local.
    BoundSet *unk_0;
    BoundPt *vol;
    BoundPt *vol_begin;
    BoundPt *vol_end;
    BoundV2 box_min;
    BoundV2 box_max;
    BoundV2 corner_min;
    BoundV2 corner_max;
    BoundSet *group;
    f32 dist;

    if (groups == NULL || count == 0) {
        return;
    }
    for (group = groups; group < &groups[count]; group++) {
        box_min = D_808015B0_gcboundDll;
        box_max = D_808015B8_gcboundDll;
        corner_min = D_808015C0_gcboundDll;
        corner_max = D_808015C8_gcboundDll;
        vol_begin = func_80800688_gcboundDll(builder, group);
        vol_end = func_808006A8_gcboundDll(builder, group);
        for (vol = vol_begin; vol < vol_end; vol++) {
            corner_min.x = vol->x - vol->r;
            corner_min.z = vol->z - vol->r;
            corner_max.x = vol->x + vol->r;
            corner_max.z = vol->z + vol->r;
            if (vol == vol_begin || corner_min.x < box_min.x) {
                box_min.x = corner_min.x;
            }
            if (vol == vol_begin || corner_min.z < box_min.z) {
                box_min.z = corner_min.z;
            }
            if (vol == vol_begin || box_max.x < corner_max.x) {
                box_max.x = corner_max.x;
            }
            if (vol == vol_begin || box_max.z < corner_max.z) {
                box_max.z = corner_max.z;
            }
            vol->rsq = (f32) vol->r * (f32) vol->r;
        }
        vol_end = func_80800700_gcboundDll(builder, group);
        for (vol = func_808006E0_gcboundDll(builder, group); vol < vol_end; vol++) {
            vol->rsq = (f32) vol->r * (f32) vol->r;
        }
        group->cx = (box_min.x + box_max.x) * 0.5f;
        group->cz = (box_min.z + box_max.z) * 0.5f;
        group->cy = 0.0f;
        group->rsq = 0; // Matching: integer 0 here, needed for the match.
        vol_end = func_808006A8_gcboundDll(builder, group);
        for (vol = vol_begin; vol < vol_end; vol++) {
            corner_min.x = vol->x - group->cx;
            corner_min.z = vol->z - group->cz;
            dist = sqrtf(corner_min.z * corner_min.z + corner_min.x * corner_min.x);
            dist = vol->r + dist;
            if (group->rsq < dist * dist) {
                group->rsq = dist * dist;
            }
        }
    }
}

// Merges overlapping groups in each of the three lists.
s32 gcboundDll_entrypoint_7(void *builder)
{
    func_80800F6C_gcboundDll(builder, builder, (s32) builder + 4);
    func_80800F6C_gcboundDll(builder, (s32) builder + 8, (s32) builder + 0xC);
    func_80800F6C_gcboundDll(builder, (s32) builder + 0x10, (s32) builder + 0x14);
}

// Finds the record with the smallest id >= min_id; best_id tracks the smallest id seen so far.
BoundRecord1446 *func_80800CA8_gcboundDll(s32 count, BoundRecord1446 *list, s32 min_id,
                                          s32 *best_id)
{
    BoundRecord1446 *best;
    BoundRecord1446 *cur;
    BoundRecord1446 *end;

    best = NULL;
    if (!list || min_id == *best_id) {
        return NULL;
    }
    cur = list;
    end = list + count;
    while (cur < end) {
        if (cur->id >= min_id) {
            if (*best_id == 0 || cur->id < *best_id) {
                *best_id = cur->id;
                best = cur;
            }
            if (cur->id == min_id) {
                return cur;
            }
        }
        cur++;
    }
    return best;
}

void func_80800D40_gcboundDll(Actor *builder)
{
    s32 idx;
    s32 found;
    s32 best_id;
    s32 record;

    idx = func_800B4374(*(s32 *) ((char *) builder + 0xE0));
    if (idx != 0) {
        do {
            best_id = 0;
            found = 0;
            record = func_80800CA8_gcboundDll(*(s32 *) ((char *) builder + 0),
                                            *(s32 *) ((char *) builder + 4), idx, &best_id);
            if (record != 0) {
                found = record;
            }
            record = func_80800CA8_gcboundDll(*(s32 *) ((char *) builder + 8),
                                            *(s32 *) ((char *) builder + 0xC), idx, &best_id);
            if (record != 0) {
                found = record;
            }
            record = func_80800CA8_gcboundDll(*(s32 *) ((char *) builder + 0x10),
                                            *(s32 *) ((char *) builder + 0x14), idx, &best_id);
            if (record != 0) {
                found = record;
            }
            if (found != 0) {
                func_800B4134((char *) builder + 0xE0, found + 0x18);
                idx = best_id + 1;
            }
        } while (found != 0);
    }
    func_800B4354((char *) builder + 0xE0);
}

s32 gcboundDll_entrypoint_8(s32 *builder)
{
    func_808008D8_gcboundDll(builder, builder[0], builder[1]);
    func_808008D8_gcboundDll(builder, builder[2], builder[3]);
    func_808008D8_gcboundDll(builder, builder[4], builder[5]);
    func_80800D40_gcboundDll(builder);
}

// Swaps two volumes.
int func_80800E6C_gcboundDll(a, b)
s32 *a;
s32 *b;
{
    u8 tmp[24];
    rare_memcpy(tmp, a, sizeof(tmp));
    rare_memcpy(a, b, sizeof(tmp));
    rare_memcpy(b, tmp, sizeof(tmp));
}

// Counts the trailing flagged volumes of a group and stores the split in its counts.
void func_80800EBC_gcboundDll(builder, group) s32 builder;
BoundHistoryRecord *group;
{
    BoundHistory *begin;
    BoundHistory *cur;
    s32 flagged = 0;

    begin = (BoundHistory *) func_80800630_gcboundDll(builder, group);
    cur = (BoundHistory *) func_80800654_gcboundDll(builder, group) - 1;
    while (cur >= begin && cur->flag_a) {
        flagged++;
        cur--;
    }
    group->unflagged_count = group->volume_count - flagged;
    group->flagged_count = flagged;
}

void func_80800F6C_gcboundDll(builder, count, list) u8 *builder;
s32 *count;
GcBoundElem **list;
{
    GcBoundElem *cur;
    GcBoundElem *other;
    u8 *vol_a;
    u8 *vol_b;
    u8 *b_end;
    u8 *a_end;
    u8 *vol_c;
    s32 go;

    if (list == NULL || count == NULL) {
        return;
    }
    for (cur = *list; cur < *list + *count; cur++) {
        for (other = cur + 1; other < *list + *count; other++) {
            if (cur->key == other->key && cur->volume_count != 0 && other->volume_count != 0) {
                a_end = func_80800654_gcboundDll(builder, cur);
                go = 1;
                for (vol_a = func_80800630_gcboundDll(builder, cur); vol_a < a_end && go; vol_a += 0x18) {
                    b_end = func_80800654_gcboundDll(builder, other);
                    for (vol_b = func_80800630_gcboundDll(builder, other); vol_b < b_end && go; vol_b += 0x18) {
                        if (func_800F0064(vol_a, *(s16 *) (vol_b + 0xC) + *(s16 *) (vol_a + 0xC), vol_b)) {
                            for (vol_c = func_80800630_gcboundDll(builder, other); vol_c < b_end;
                                 vol_c += 0x18) {
                                rare_memcpy(func_800B3CDC(builder + 0xE0, cur->run), vol_c, 0x18);
                            }
                            func_800B422C(builder + 0xE0, other->run);
                            other->unk0 = other->unk3 = 0;
                            other = cur;
                            go = 0;
                        }
                    }
                }
            }
        }
    }
    for (cur = *list; cur < *list + *count; cur++) {
        if (cur->volume_count == 0) {
            go = 1;
            for (other = cur + 1; other < *list + *count && go; other++) {
                if (other->volume_count != 0) {
                    rare_memcpy(cur, other, sizeof(GcBoundElem));
                    go = 0;
                    func_800B4290(other->run);
                }
            }
        }
    }
    for (cur = *list; cur < *list + *count && cur->volume_count != 0; cur++) {
    }
    *count = cur - *list;
    *list = heap_realloc(*list, *count * sizeof(GcBoundElem));
}

s32 func_8080132C_gcboundDll(kind_id)
s32 kind_id;
{

switch (kind_id) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 4;
    default:
        return 7;
}

}

// Next record after prev (the first if prev is NULL) whose key matches, or any record if any is set.
BoundRecord *func_80801370_gcboundDll(s32 count, BoundRecord *list, BoundRecord *prev,
                                      s32 key, s32 any)
{
    BoundRecord *end = list + count;

if (prev == NULL) {
    prev = list - 1;
}

for (prev++; prev < end; prev++) {

if (key == prev->key || any) {
    return prev;
}

}
return NULL;
}

int func_808013D4_gcboundDll(builder, key, any, prev)
s32 *builder;
s32 key;
s32 any;
s32 prev;
{
    func_80801370_gcboundDll(*builder, *(builder + 1), prev, key, any);
}

int func_8080141C_gcboundDll(builder, key, prev)
u8 *builder;
s32 key;
s32 prev;
{
    func_80801370_gcboundDll(*(s32 *) (builder + 8), *(s32 *) (builder + 0xC), prev, key, 0);
}

int func_80801450_gcboundDll(builder, key, prev)
u8 *builder;
s32 key;
s32 prev;
{
    func_80801370_gcboundDll(*(s32 *) (builder + 0x10), *(s32 *) (builder + 0x14), prev, key,
                             0);
}

int func_80801484_gcboundDll(builder, group, unused, pos, margin)
s32 builder;
s32 group;
s32 unused;
s16 *pos;
s32 margin;
{
    BoundaryCircle *end;
    BoundaryCircle *cur;
    f32 pos_f[3];
    f32 dy;
    func_800EE88C(pos_f, pos);
    end = (BoundaryCircle *) func_80800654_gcboundDll(builder, group);
    cur = (BoundaryCircle *) func_80800630_gcboundDll(builder, group);
    for (; cur < end; cur++) {
        dy = pos[1] - cur->y;

if (dy * dy < 250000.0f) {
    if (func_800F0064(pos_f, (f32) (cur->radius + margin), cur))
        return 1;
}

}
return 0;
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/boundDll.data.s) is defined here in C; values from the ROM.
BoundV2 D_808015B0_gcboundDll ={0.0f, 0.0f};
BoundV2 D_808015B8_gcboundDll = {0.0f, 0.0f};
BoundV2 D_808015C0_gcboundDll = {0.0f, 0.0f};
BoundV2 D_808015C8_gcboundDll = {0.0f, 0.0f};
