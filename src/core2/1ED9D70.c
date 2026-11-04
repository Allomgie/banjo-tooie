// Probably two unrelated parts: a 5-slot cache of grow-only heap scratch buffers freed after
// 31 idle frames, and a pool of per-actor model vertex-buffer instances with tinted variants.
#include "common.h"
#include "freelist.h"

extern void *defrag(void *arg);
// Scratch buffer slot (5 in D_801243A0): s16 elem_size and s16 count packed in unk_0,
// frame of last use, heap pointer. Slots are also accessed through byte offsets.
typedef struct {
    s32 unk_0;
    s32 last_frame;
    s32 buffer;
} D_801243A0_t;
extern D_801243A0_t D_801243A0[];
extern D_801243A0_t D_801243DC;
extern FreeList *D_80135A60;
// TU-NOTE: D_80135A60, D_80135A64 and D_80135A68 are one block {instances, variants,
// next_anim_id}, also read through LocalPools, State100B4C and OSPiInfo.
typedef struct {
    u8 pad_0[0x17];
    u8 unk_17;
} LocalObject_801007B8;
// Per-actor model instance: up to 2 private vertex copies and an optional packed variant.
typedef struct {
    LocalObject_801007B8 *vtx_copies[2];
    u8 variant_id, active, release_timer;
} LocalInstance;
// Refcounted colour-tinted packed-vertex variant, keyed by (model_id, anim_id, rgb).
typedef struct {
    void *packed_vtx;
    s16 model_id, anim_id;
    u8 refcount;
    u8 rgb[3];
} LocalCache;
typedef struct {
    FreeList *instances, *variants;
    s32 next_anim_id;
} LocalPools;
extern FreeList *D_80135A64;
extern void *func_800B2840(void *);
extern void *func_800D674C(s32);
extern LocalObject_801007B8 *func_800B2400(void *, s32);
extern void *_glpackvtx_entrypoint_0();
extern void _glpackvtx_entrypoint_1(void *);
extern void func_800F2F20();
extern void func_800F31EC();
extern s32 D_80135A68;
typedef struct {
    void *instances, *variants;
} State100B4C;
typedef struct {
    u8 pad_0[0x14];
    u32 pad_14 : 31;
    u32 unk_17 : 1;
} LocalObject_80100D24;
struct OSPiInfo {
    u32 unk_0;
    u32 unk_4;
};
void func_80100C74();

// Frame-aged scratch buffer cache (5 slots, heap alloc/realloc/free, defrag).
// Returns the slot's scratch buffer, grown to hold count elements. Never shrinks.
s32 func_80100480(s32 slot_id, s32 count)
{
    s32 old_buf;
    s32 new_buf;
    u8 *slot;

    slot = (u8 *) (s32 *) D_801243A0 + slot_id * 12;
    old_buf = *(s32 *) ((s8 *) slot + 8);
    if (old_buf == 0) {
        *(s16 *) ((s8 *) slot + 2) = count;
        new_buf = heap_alloc(*(s16 *) ((s8 *) slot + 2) * *(s16 *) ((s8 *) slot + 0));
        *(s32 *) ((s8 *) slot + 8) = new_buf;
    } else if (*(s16 *) ((s8 *) slot + 2) < count) {
        *(s16 *) ((s8 *) slot + 2) = count;
        new_buf =
            heap_realloc(old_buf, *(s16 *) ((s8 *) slot + 2) * *(s16 *) ((s8 *) slot + 0));
        *(s32 *) ((s8 *) slot + 8) = new_buf;
    }
    *(s32 *) ((s8 *) slot + 4) = func_8001211C();
    return *(s32 *) ((s8 *) slot + 8);
}

void func_8010052C(void)
{
}

// Frees scratch buffers unused for 31 frames or more.
// Matching: the line breaks in this function are needed for the match.
void func_80100534(void)
{
    s32 frame;
    ALBank *slot;
    frame = func_8001211C();
    slot = (ALBank *) (u8 *) D_801243A0; do {
        if ((*(s32 *) ((char *) slot + 0x8) != 0) && ((frame - *(s32 *) ((char *) slot + 0x4)) >= 0x1F))
        {
            heap_free(*(s32 *) ((char *) slot + 0x8));
            *(s32 *) ((char *) slot + 0x8) = 0;
            *(s16 *) ((char *) slot + 0x2) = 0;
            *(s32 *) ((char *) slot + 0x4) = 0;
        }
        slot = (ALBank *) ((char *) slot + 0xC);
    }
    while (slot != (ALBank *) (u8 *) &D_801243DC);
}

// Defragments the scratch buffers.
void func_801005B8()
{
    D_801243A0_t *slot = D_801243A0, *end = &D_801243DC;
    do {
        s32 buffer = slot->buffer;
        if (buffer != 0) {
            slot->buffer = (s32) defrag((void *) buffer);
        }
        slot++;
    } while (slot != end);
}

// Frees all scratch buffers.
// Matching: the line breaks in this function are needed for the match.
void func_80100610(void)
{
    s32 buffer;
    s8 *slot;
    slot = (s8 *) D_801243A0; do {
        buffer = *(s32 *) ((0, (s8 *) slot) - -8); // Matching: comma operator and "- -8" are needed.
        if (buffer != 0)
        {
            heap_free(buffer);
            *(s32 *) (8 + (s8 *) slot) = 0;
            *(s16 *) (slot + 2) = 0;
            *(s32 *) ((s8 *) slot + 4) = 0;
        }
        slot += 0xC;
    }
    while (slot != (s8 *) &D_801243DC);
}

void func_80100670()
{
    func_80100610();
}

// Per-actor model vertex-buffer instances and tinted vertex cache, with delayed release and defrag.
// Allocates an instance record, creating the freelist on first use.
int func_80100690(s32 out_index)
{
    if (!D_80135A60) {
        D_80135A60 = freelist_new(0xC, 2);
    }
    freelist_next(&D_80135A60, out_index);
}

// Allocates a packed-variant record, creating the freelist on first use.
int func_801006E0(s32 out_index)
{
    s32 *unk_0;
    // Matching: the do-while(0) wrapper and the pointer reuse are needed for the match.
    if (!(void *) D_80135A64) {
        unk_0 = freelist_new(0xC, 2);
        do {
            D_80135A64 = unk_0;
        } while (0);
    }
    unk_0 = &out_index;
    freelist_next((void **) &D_80135A64, *unk_0);
}

// Compares rgb with a cached tint; NULL rgb means white.
int func_8010072C(s32 *rgb, u8 *cached_rgb)
{
    if (rgb != 0)
        return rgb[0] == cached_rgb[0] && rgb[1] == cached_rgb[1] && rgb[2] == cached_rgb[2];
    return 255 == cached_rgb[0] && 255 == cached_rgb[1] && 255 == cached_rgb[2];
}

// Returns the id of the packed variant for (model_id, anim_id, rgb); builds it if missing.
s32 func_801007B8(void *model, s32 model_id, s32 anim_id, u8 *rgb)
{
    LocalCache *entry;
    void *anim_data;
    s32 cache_id;
    if ((*(LocalPools *) &D_80135A60).variants) {
        for (cache_id = 1; cache_id < freelist_capacity((*(LocalPools *) &D_80135A60).variants);
             cache_id++) {
            if (freelist_is_element_alive((*(LocalPools *) &D_80135A60).variants, cache_id)) {
                entry = freelist_at((*(LocalPools *) &D_80135A60).variants, cache_id);
                if (model_id == entry->model_id && anim_id == entry->anim_id &&
                    func_8010072C(rgb, entry->rgb)) {
                    entry->refcount++;
                    return cache_id;
                }
            }
        }
    }
    entry = func_801006E0(&cache_id);
    if (anim_id)
        anim_data = func_800D674C(anim_id);
    else
        anim_data = NULL;
    entry->packed_vtx = _glpackvtx_entrypoint_0(func_800B2840(model), anim_data, rgb);
    entry->model_id = model_id;
    entry->anim_id = anim_id;
    entry->refcount = 1;
    if (rgb)
        func_800F2F20(entry->rgb, rgb);
    else
        func_800F31EC(entry->rgb, 0xFF, 0xFF, 0xFF);
    return cache_id;
}

// Drops one reference to a packed variant and frees it at zero.
void func_80100938(s32 cache_id)
{
    u8 *entry;
    entry = freelist_at(D_80135A64, cache_id);
    entry[8]--;
    if (entry[8] == 0) {
        _glpackvtx_entrypoint_1(*(s32 *) entry);
        *(s32 *) entry = 0;
        *(s16 *) (entry + 4) = 0;
        freelist_erase(D_80135A64, cache_id);
        if (freelist_used_count(D_80135A64) == 0) {
            freelist_free(D_80135A64);
            D_80135A64 = 0;
        }
    }
}

// Releases an instance: frees its vertex copies and packed variant, then the record.
int func_801009C4(ALTempoEvent *instance, s32 instance_id)
{
    ALTempoEvent **copy;
    s32 offset;
    s32 variant_id;
    offset = 0;
    copy = instance;
    do {
        if (*copy) {
            func_800B23E0(*copy);
        }
        offset += 4;
        copy += 1;
    } while (offset != 8);
    variant_id = *(u8 *) ((char *) instance + 0x8);
    if (variant_id != 0) {
        func_80100938(variant_id ^ 0); // Matching: "^ 0" is needed for the match.
    }
    *(s8 *) ((char *) instance + 0x9) = 0;
    freelist_erase(*(s32 *) (u8 *) &D_80135A60, instance_id);
    if (freelist_used_count(*(s32 *) (u8 *) &D_80135A60) == 0) {
        freelist_free(*(s32 *) (u8 *) &D_80135A60);
        *(s32 *) (u8 *) &D_80135A60 = 0;
    }
}

// Returns the instance's vertex buffer buf_index, or 0 if the instance is inactive.
int func_80100A74(instance_id, buf_index)
s16 instance_id;
s32 buf_index;
{
    u8 *instance;
    int offset;
    instance = freelist_at((int) D_80135A60, (long) instance_id);
    // Matching: the extra temporary holding the field offset is needed for the match.
    return instance[offset = 9] ? *((s32 *) instance + buf_index) : 0;
}

// Returns the instance's packed vertex buffer, or 0 if it has none.
s32 func_80100AC4(instance_id)
s16 instance_id;
{
    u8 *instance;
    u8 *variant;
    instance = freelist_at(D_80135A60, instance_id);

    if (instance[8] == 0) {
        return 0;
    }

    variant = freelist_at(((s32) D_80135A64), instance[8]);
    return variant[8] ? *(s32 *) variant : 0;
}

// Resets the counter for unique anim ids.
void func_80100B3C()
{
    D_80135A68 = 0x3667;
}

// Frees all instances and packed variants.
void func_80100B4C(void)
{
    s32 i;
    func_80100C74();
    func_80100C74();
    for (i = 1; (*((State100B4C *) &D_80135A60)).instances &&
                      i < freelist_capacity((*((State100B4C *) &D_80135A60)).instances);
         i++) {
        if (freelist_is_element_alive((*((State100B4C *) &D_80135A60)).instances, i))
            func_801009C4(freelist_at((*((State100B4C *) &D_80135A60)).instances, i), i);
    }
    if ((*((State100B4C *) &D_80135A60)).instances) {
        freelist_free((*((State100B4C *) &D_80135A60)).instances);
        (*((State100B4C *) &D_80135A60)).instances = 0;
    }

    if ((*(State100B4C *) &D_80135A60).variants) {
        for (i = 1; i < freelist_capacity((*(State100B4C *) &D_80135A60).variants);
             i++) {
            if (freelist_is_element_alive((*(State100B4C *) &D_80135A60).variants, i))
                _glpackvtx_entrypoint_1(
                    *(void **) freelist_at((*(State100B4C *) &D_80135A60).variants, i));
        }
        freelist_free((*(State100B4C *) &D_80135A60).variants);
        (*(State100B4C *) &D_80135A60).variants = 0;
    }
}

// Counts down each instance's release timer and releases the instance at zero.
void func_80100C74()
{
    s32 i;
    u8 *instance;
    i = 1;

    if (D_80135A60 == 0) {
        return;
    }

    if (freelist_capacity(D_80135A60) < 2) {
        return;
    }

    for (;;) {
        if (!freelist_is_element_alive(D_80135A60, i)) {
            goto next;
        }
        instance = freelist_at(D_80135A60, i);
        if (instance[0xA] == 0) {
            goto next;
        }
        if (--instance[0xA] != 0) {
            goto next;
        }
        func_801009C4(instance, i);
    next:
        i++;

        if ((D_80135A60 == 0) || (i >= freelist_capacity(D_80135A60))) {
            break;
        }
    }
}

// Creates an instance with up to copy_count private vertex copies (max 2) and, if
// with_variant is set, a packed variant. Returns the instance id.
s16 func_80100D24(void *model, s32 model_id, s32 copy_count, s32 with_variant, s32 anim_id, u8 *rgb)
{
    LocalObject_80100D24 *copy;
    s32 instance_id;
    LocalInstance *instance;
    void *vtx_list;
    s32 i;
    instance = func_80100690(&instance_id);
    vtx_list = func_800B2840(model);
    for (i = 0; i < 2; i++) {
        if (i < copy_count) {
            copy = func_800B2400(vtx_list, 0);
            instance->vtx_copies[i] = copy;
            copy->unk_17 = 1;
        } else {
            instance->vtx_copies[i] = NULL;
        }
    }
    if (with_variant)
        instance->variant_id = func_801007B8(model, model_id, anim_id, rgb);
    else
        instance->variant_id = 0;
    instance->active = 1;
    instance->release_timer = 0;
    return instance_id;
}

// Starts the 2-frame release countdown for an instance.
s32 func_80100E18(instance_id)
s16 instance_id;
{
    s32 instance = freelist_at(D_80135A60, instance_id);
    *(u8 *) (instance + 0xA) = 2;
}

// Defragments the instance freelist, the packed variants and the variant freelist.
void func_80100E54()
{
    struct OSPiInfo *entry;
    u32 defragged;
    struct OSPiInfo *instances;
    instances = (struct OSPiInfo *) (*(struct OSPiInfo *) &D_80135A60).unk_0;
    if (instances != 0) {
        (*(struct OSPiInfo *) &D_80135A60).unk_0 =
            (defragged = (u32) freelist_defrag((void *) (*(struct OSPiInfo *) &D_80135A60).unk_0));
    }
    entry = (struct OSPiInfo *) (*(struct OSPiInfo *) &D_80135A60).unk_4;
    if (entry != 0) {
        int i;
        for (i = 1;
             i < freelist_capacity((void *) (*(struct OSPiInfo *) &D_80135A60).unk_4);
             i++) {
            if (freelist_is_element_alive((void *) (*(struct OSPiInfo *) &D_80135A60).unk_4,
                                          i)) {
                entry = (struct OSPiInfo *) freelist_at(
                    (void *) (*(struct OSPiInfo *) &D_80135A60).unk_4, i);
                // Matching: the empty if with a repeated test is needed for the match.
                if (((!(*(struct OSPiInfo *) &D_80135A60).unk_0 &&
                      !(*(struct OSPiInfo *) &D_80135A60).unk_0) &&
                     !(*(struct OSPiInfo *) &D_80135A60).unk_0) != 0) {
                }
                entry->unk_0 = (u32) defrag((void *) entry->unk_0);
            }

            // Matching: empty do-while(0) and empty if below are needed for the match.
            do {
            } while (0);
        }

        if (!entry) {
        }
        (*((struct OSPiInfo *) &D_80135A60)).unk_4 =
            (u32) freelist_defrag((void *) (*((struct OSPiInfo *) &D_80135A60)).unk_4);
    }
}

// Gives the instance its own packed variant built from anim_data, with a unique anim id.
void func_80100F0C(s16 instance_id, void *anim_data)
{
    LocalInstance *instance;
    LocalCache *variant;
    void *model;
    s32 model_id;
    s32 new_variant_id;
    instance = freelist_at((*((LocalPools *) &D_80135A60)).instances, instance_id);
    if (instance->variant_id) {
        variant = freelist_at(D_80135A64, instance->variant_id);
        if (variant->refcount) {
            model_id = variant->model_id;

            if (variant->anim_id < 0x3666) {
                func_80100938(instance->variant_id);
                variant = func_801006E0(&new_variant_id);
                instance->variant_id = new_variant_id;
            } else {
                _glpackvtx_entrypoint_1(variant->packed_vtx);
            }
            model = func_800D674C(model_id);
            variant->packed_vtx = _glpackvtx_entrypoint_0(func_800B2840(model), anim_data, NULL);
            variant->model_id = model_id;
            variant->anim_id = (*((LocalPools *) &D_80135A60)).next_anim_id;
            (*((LocalPools *) &D_80135A60)).next_anim_id++;
            variant->refcount = 1;
        }
    }
}

// TU-NOTE: the .data of this file is defined here in C (values from the ROM).
// D_801243DC = D_801243A0 + 0x3C is a linker symbol (end of the 5 slots).
// D_801243A0 is declared as D_801243A0_t[].
D_801243A0_t D_801243A0[5] = {0x30000, 0x0,     0x0, 0x40000, 0x0,     0x0, 0xC0000, 0x0,
                              0x0,     0xC0000, 0x0, 0x0,     0x60000, 0x0, 0x0};
