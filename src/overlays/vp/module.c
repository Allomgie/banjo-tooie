// Driver for map-mesh vertex effects: creates light/wibble/flicker/glow/scroll effects per
// map layer, updates them each frame, applies them to dirty visible vertex groups while
// drawing, and toggles them by id.
#include "common.h"

// Layer effect data from the map model.
typedef struct {
    u8 pad_0[0x20];
    s16 vtx_count;
    s16 unk_22;
    u8 pad_1[8];
    s32 effect_count;
    s32 effect_offsets[1];
} VpInput62;
// Module header; the entries follow it. Offsets are relative to the module.
typedef struct {
    s32 base_vtx_off;
    s32 scratch_off;
} VpOutput62;
typedef struct {
    u8 type;
    u8 enabled;
    u16 idx;
    void *payload;
} VpEntry62;
typedef struct {
    void *(*create)(VpInput62 *, void *);
    s32 unk_4[4];
} VpCallback62;
typedef struct {
    u8 type;
    u8 pad_0[3];
    void *payload;
} ViewModuleEntry;
typedef struct {
    u8 pad_0[8];
    ViewModuleEntry entries[1];
} ViewModuleEntries;
typedef struct {
    u8 pad_0[0x2C];
    s32 effect_count;
} ViewModuleHeader;
typedef struct {
    void *pad_0[2];
    void (*destroy)(void *);
    void *pad_1[2];
} ViewModuleType;
typedef struct {
    u8 type;
    u8 enabled;
    u8 pad_0[2];
    void *payload;
} ViewModuleUpdateEntry;
typedef struct {
    u8 pad_0[8];
    ViewModuleUpdateEntry entries[1];
} ViewModuleUpdateList;
typedef struct {
    void *pad_0;
    void (*update)(void *, ViewModuleHeader *);
    void *pad_1[3];
} ViewModuleUpdateType;
typedef struct {
    u8 type;
    u8 enabled;
    s16 idx;
    void *payload;
} VMEntry;
typedef struct {
    s32 base_vtx_off;
    s32 scratch_off;
    VMEntry entries[1];
} VMList;
typedef struct {
    u8 pad0[0x14];
    s32 group_count;
    u8 pad18[4];
    s32 groups_off;
    u8 pad20[0xC];
    s32 effect_count;
} VMHeader;
// Vertex group record (0x14 bytes): dirty flag and AABB bounds for the frustum test.
typedef struct {
    s16 first_vtx;
    u8 vtx_count;
    u8 dirty;
    u8 bbox_min[6];
    u8 bbox_max[10];
} VMTrack;
typedef struct {
    u16 key_off;
    u16 key_count;
} VMSub;
typedef struct {
    void *pad0[3];
    void (*apply)(void *, s32, void *, s32);
    void *pad10;
} VMType_vpmodule_entrypoint_3;
extern VMType_vpmodule_entrypoint_3 D_808008C0_vpmodule[];
extern s32 func_800E3DC0(void *, void *);
extern void aligned8_memcpy(void *, void *, s32);
typedef struct {
    void *pad0[4];
    void (*init)(void *, s32);
} VMType_808005C4_vpmodule;
typedef struct {
    u8 type;
    u8 enabled;
    s16 idx;
    u32 payload;
} ModuleEntry1279;
void func_808005C4_vpmodule();

// Maps an effect id to its kind: 0 light, 1 wibble, 2 flicker, 3 glow, 4 scroll.
int func_80800000_vpmodule(s32 effect_id)
{
    if (effect_id == 0) {
        return 0;
    }
    if (((effect_id >= 0x4B0) && (effect_id < 0x6A4)) || ((effect_id >= 0x834) && (effect_id < 0x898))) {
        return 1;
    }
    if ((effect_id >= 0xC8) && (effect_id < 0x12C)) {
        return 2;
    }
    if ((effect_id >= 0x1F4) && (effect_id < 0x258)) {
        return 3;
    }
    if ((effect_id >= 0x64) && (effect_id < 0xC8)) {
        return 4;
    }
    return -1;
}

// Creates the module for one layer: one state per effect, then runs the per-vertex init.
VpOutput62 *vpmodule_entrypoint_0(VpInput62 *fx_data, s32 out, s32 arg2)
{
    VpOutput62 *module;
    VpEntry62 *entry;
    u8 *def;
    u8 *vtx_base;
    s32 i;
    s32 size;
    s32 count;
    s32 kind;

    count = fx_data->effect_count;
    if (count == 0)
        return NULL;
    size = count * 8 + 8;
    while (size & 0xF)
        size++;
    size += fx_data->vtx_count * 16 + fx_data->unk_22 * 16;
    module = heap_alloc(size);
    entry = (VpEntry62 *) (module + 1);
    for (i = 0; i < count; i++, entry++) {
        def = (u8 *) fx_data + fx_data->effect_offsets[i];
        kind = func_80800000_vpmodule(*(s32 *) def);
        entry->type = kind;
        entry->enabled = 1;
        entry->idx = i;
        entry->payload =
            ((VpCallback62 *) D_808008C0_vpmodule)[kind].create(fx_data, def);
    }
    vtx_base = (u8 *) entry;
    while ((u32) vtx_base & 0xF)
        vtx_base++;
    module->base_vtx_off = vtx_base - (u8 *) module;
    _dbvpl_entrypoint_1(fx_data, vtx_base, out, arg2);
    module->scratch_off = module->base_vtx_off + fx_data->vtx_count * 16;
    func_808005C4_vpmodule(module, fx_data, out);
    return module;
}

void vpmodule_entrypoint_1(ViewModuleEntries *list, ViewModuleHeader *hdr)
{
    ViewModuleEntry *entry;
    ViewModuleEntry *end;
    entry = list->entries;
    end = entry + hdr->effect_count;
    for (; entry < end; entry++) {
        ((ViewModuleType *) D_808008C0_vpmodule)[entry->type].destroy(entry->payload);
    }
    heap_free(list);
}

void vpmodule_entrypoint_2(ViewModuleUpdateList *list, ViewModuleHeader *hdr)
{
    ViewModuleUpdateEntry *entry;
    ViewModuleUpdateEntry *end;
    end = (ViewModuleUpdateEntry *) ((hdr->effect_count * sizeof(ViewModuleUpdateEntry)) +
                                     (u8 *) list + 8);
    for (entry = list->entries; entry < end; entry++) {
        if (entry->enabled)
            ((ViewModuleUpdateType *) D_808008C0_vpmodule)[entry->type].update(entry->payload,
                                                                               hdr);
    }
}

// Draw step: for each dirty, visible vertex group, copies it to the scratch buffer, applies
// all effects, and scatters the result into the output vertex buffer.
void vpmodule_entrypoint_3(VMList *mod, VMHeader *hdr, u8 *out)
{
    s32 pad;
    VMEntry *fx_end;
    VMTrack *groups;
    VMTrack *group;
    VMTrack *groups_end;
    VMEntry *fx;
    u8 *scratch;
    u8 *scratch_end;
    u8 *def;
    VMSub *sub;
    u8 *key;
    u8 *key_end;
    u8 *dst;
    s32 group_idx;

    groups = (VMTrack *) ((u8 *) hdr + hdr->groups_off);
    groups_end = groups + hdr->group_count;
    fx_end = (VMEntry *) ((hdr->effect_count * sizeof(VMEntry)) + (u8 *) mod + 8);
    for (group = groups; group < groups_end; group++) {
        if (!group->dirty) {
            continue;
        }
        if (!func_800E3DC0(group->bbox_min, group->bbox_max)) {
            continue;
        }
        scratch = (u8 *) mod + mod->scratch_off;
        aligned8_memcpy(scratch, (u8 *) mod + mod->base_vtx_off + group->first_vtx * 16, group->vtx_count * 16);
        group_idx = group - groups;
        for (fx = mod->entries; fx < fx_end; fx++) {
            def = (u8 *) hdr + *((s32 *) ((u8 *) hdr + 0x30) + fx->idx);
            sub = (VMSub *) (def + 0x14) + group_idx;
            if (sub->key_count == 0) {
                continue;
            }
            key = (u8 *) ((s32 *) def + hdr->group_count) + sub->key_off + 0x14;
            key_end = key + sub->key_count;
            for (; key < key_end; key += 2) {
                D_808008C0_vpmodule[fx->type].apply(fx->payload, group_idx, scratch + key[1] * 16, key[0]);
            }
        }
        dst = out + 0x18;
        scratch_end = scratch + group->vtx_count * 16;
        for (; scratch < scratch_end; scratch += 16) {
            aligned8_memcpy(dst + (*(u16 *) (scratch + 6) & 0x7FFF) * 16, scratch, 16);
        }
        group->dirty = 0;
    }
}

// Runs each effect's optional per-vertex init over all groups, then scatters the vertices.
void func_808005C4_vpmodule(mod, hdr, out) VMList *mod;
VMHeader *hdr;
u8 *out;
{
    s32 pad;
    VMEntry *fx_end;
    VMTrack *groups;
    VMTrack *group;
    VMTrack *groups_end;
    VMEntry *fx;
    u8 *scratch;
    u8 *scratch_end;
    u8 *def;
    VMSub *sub;
    u8 *key;
    u8 *key_end;
    u8 *dst;
    s32 group_idx;
    s32 v;

    groups = (VMTrack *) ((u8 *) hdr + hdr->groups_off);
    groups_end = groups + hdr->group_count;
    fx_end = (VMEntry *) ((hdr->effect_count * sizeof(VMEntry)) + (u8 *) mod + 8);
    for (group = groups; group < groups_end; group++) {
        scratch = (u8 *) mod + mod->scratch_off;
        aligned8_memcpy(scratch, (u8 *) mod + mod->base_vtx_off + group->first_vtx * 16, group->vtx_count * 16);
        for (fx = mod->entries; fx < fx_end; fx++) {
            if (((VMType_808005C4_vpmodule *) D_808008C0_vpmodule)[fx->type].init == NULL) {
                continue;
            }
            def = (u8 *) hdr + *((s32 *) ((u8 *) hdr + 0x30) + fx->idx);
            group_idx = group - groups;
            sub = (VMSub *) (def + 0x14) + group_idx;
            if (sub->key_count == 0) {
                continue;
            }
            key = (u8 *) ((s32 *) def + hdr->group_count) + sub->key_off + 0x14;
            key_end = key + sub->key_count;
            for (; key < key_end; key++) {
                v = key[1];
                ((VMType_808005C4_vpmodule *) D_808008C0_vpmodule)[fx->type].init(scratch + v * 16,
                                                                                  *key++);
            }
        }
        aligned8_memcpy((u8 *) mod + mod->base_vtx_off + group->first_vtx * 16, scratch, group->vtx_count * 16);
        dst = out + 0x18;
        scratch_end = scratch + group->vtx_count * 16;
        for (; scratch < scratch_end; scratch += 16) {
            aligned8_memcpy(dst + (*(u16 *) (scratch + 6) & 0x7FFF) * 16, scratch, 16);
        }
    }
}

// Enables or disables the effect with the given id. Returns 1 if found.
s32 vpmodule_entrypoint_4(u8 *list, u8 *hdr, s32 id, int enabled)
{
    ModuleEntry1279 *entry;
    ModuleEntry1279 *end;
    s32 *def;

    entry = (ModuleEntry1279 *) (list + 8);
    end = entry + *(s32 *) (hdr + 0x2C);
    while (entry < end) {
        def = (s32 *) (hdr + *((s32 *) (hdr + 0x30) + entry->idx));
        if (*def == id) {
            entry->enabled = enabled;
            return 1;
        }
        entry++;
    }
    return 0;
}

// TU-NOTE: the overlay's .data is defined here in C. The table holds pointers to functions of
// this file, and IDO's assembler schedules some of them differently unless it is in the same
// unit. Values taken from the ROM. Records of 5 callbacks: create, update, destroy, apply, init.
extern void _vplight_entrypoint_0();
extern void _vplight_entrypoint_2();
extern void _vplight_entrypoint_1();
extern void _vplight_entrypoint_3();
extern void _vplight_entrypoint_4();
extern void _vpwibble_entrypoint_0();
extern void _vpwibble_entrypoint_2();
extern void _vpwibble_entrypoint_1();
extern void _vpwibble_entrypoint_3();
extern void _vpflicker_entrypoint_0();
extern void _vpflicker_entrypoint_2();
extern void _vpflicker_entrypoint_1();
extern void _vpflicker_entrypoint_3();
extern void _vpglow_entrypoint_0();
extern void _vpglow_entrypoint_2();
extern void _vpglow_entrypoint_1();
extern void _vpglow_entrypoint_3();
extern void _vpscroll_entrypoint_0();
extern void _vpscroll_entrypoint_2();
extern void _vpscroll_entrypoint_1();
extern void _vpscroll_entrypoint_3();
VMType_vpmodule_entrypoint_3 D_808008C0_vpmodule[5] = {(void *) _vplight_entrypoint_0,
                                                       (void *) _vplight_entrypoint_2,
                                                       (void *) _vplight_entrypoint_1,
                                                       (void *) _vplight_entrypoint_3,
                                                       (void *) _vplight_entrypoint_4,
                                                       (void *) _vpwibble_entrypoint_0,
                                                       (void *) _vpwibble_entrypoint_2,
                                                       (void *) _vpwibble_entrypoint_1,
                                                       (void *) _vpwibble_entrypoint_3,
                                                       0,
                                                       (void *) _vpflicker_entrypoint_0,
                                                       (void *) _vpflicker_entrypoint_2,
                                                       (void *) _vpflicker_entrypoint_1,
                                                       (void *) _vpflicker_entrypoint_3,
                                                       0,
                                                       (void *) _vpglow_entrypoint_0,
                                                       (void *) _vpglow_entrypoint_2,
                                                       (void *) _vpglow_entrypoint_1,
                                                       (void *) _vpglow_entrypoint_3,
                                                       0,
                                                       (void *) _vpscroll_entrypoint_0,
                                                       (void *) _vpscroll_entrypoint_2,
                                                       (void *) _vpscroll_entrypoint_1,
                                                       (void *) _vpscroll_entrypoint_3,
                                                       0};
