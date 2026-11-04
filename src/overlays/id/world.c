// Map-mesh effect registry, runtime side: finds entries in D_80127EF8 by mesh id and type,
// has typed getters, and runs the per-frame dispatcher over the enabled entries.
#include "common.h"
#include "vector.h"

typedef struct {
    s32 owner;
    s16 mesh_id;
    u8 type;
    u8 enabled;
    u8 state[0xA0];
} WorldLookupRecord;
extern Vector *D_80127EF8;
typedef struct {
    s32 owner;
    s16 mesh_id;
    u8 type;
    u8 enabled;
    u8 state[0xA0];
} WorldItemRecord61;
typedef struct {
    s32 pad_0[2];
    Vector *entries;
} WorldItemList61;
extern WorldItemList61 D_80127EF0;
typedef void (*WorldDrawFn)(void *, s32, s32);
extern WorldDrawFn D_808002C0_idworld[];

// Finds the effect entry with this mesh id and type.
WorldLookupRecord *func_80800000_idworld(s32 mesh_id, s32 type)
{
    WorldLookupRecord *entry;
    WorldLookupRecord *end;

    if (D_80127EF8 == NULL) {
        return NULL;
    }
    end = vector_end(D_80127EF8);
    for (entry = vector_begin(D_80127EF8); entry < end; entry++) {
        if (type == entry->type && mesh_id == entry->mesh_id) {
            return entry;
        }
    }
    return NULL;
}

// Typed getters: return the entry state (entry + 8) or 0. Types: glowa 6, flasha 8, twinkle 12, mesh-group animator 2.
int idworld_entrypoint_0(s32 mesh_id)
{
    int result;
    int entry;
    entry = func_80800000_idworld(mesh_id, 6);
    if (entry) {
        result = entry + 8;
    } else {
        result = 0;
    }
    return result | 0; // Matching:  is needed for the match.
}

int idworld_entrypoint_1(s32 mesh_id)
{
    int result;
    int entry;
    entry = func_80800000_idworld(mesh_id, 8);
    if (entry) {
        result = entry + 8;
    } else {
        result = 0;
    }
    return result | 0; // Matching:  is needed for the match.
}

int idworld_entrypoint_2(s32 mesh_id)
{
    int result;
    int entry;
    entry = func_80800000_idworld(mesh_id, 0xC);
    if (entry) {
        result = entry + 8;
    } else {
        result = 0;
    }
    return result | 0; // Matching:  is needed for the match.
}

int idworld_entrypoint_3(s32 mesh_id)
{
    int result;
    int entry;
    entry = func_80800000_idworld(mesh_id, 2);
    if (entry) {
        result = entry + 8;
    } else {
        result = 0;
    }
    return result | 0; // Matching:  is needed for the match.
}

// Wibble (type 10) state by owner and mesh id.
u8 *idworld_entrypoint_4(s32 owner, s32 mesh_id)
{
    WorldLookupRecord *entry;
    WorldLookupRecord *end;

    if (D_80127EF8 == NULL) {
        return NULL;
    }
    end = vector_end(D_80127EF8);
    for (entry = vector_begin(D_80127EF8); entry < end; entry++) {
        if (entry->type == 10 && owner == entry->owner && mesh_id == entry->mesh_id) {
            return entry->state;
        }
    }
    return NULL;
}

// Per-frame: runs the update of every enabled entry.
void idworld_entrypoint_5(void)
{
    WorldItemRecord61 *entry;
    WorldItemRecord61 *end;

    end = vector_end(D_80127EF0.entries);
    for (entry = vector_begin(D_80127EF0.entries); entry < end; entry++) {
        if (entry->enabled) {
            D_808002C0_idworld[entry->type](entry->state, entry->owner,
                                            entry->mesh_id);
        }
    }
}

// TU-NOTE: this overlay's .data is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit.
extern void _idlight_entrypoint_3();
extern void _idscroll_entrypoint_3();
extern void func_800EE108();
extern void _idwater_entrypoint_4();
extern void _idglow_entrypoint_3();
extern void _idwave_entrypoint_3();
extern void _idglowa_entrypoint_4();
extern void _idflash_entrypoint_3();
extern void _idflasha_entrypoint_4();
extern void func_800EC9E0();
extern void _idwibble_entrypoint_3();
extern void _idbounce_entrypoint_5();
extern void _idtwinkle_entrypoint_5();
extern void _idflame_entrypoint_4();
extern void _idtwinklea_entrypoint_2();
extern void _idtwinklecolour_entrypoint_5();
WorldDrawFn D_808002C0_idworld[16] = {(void *) _idlight_entrypoint_3,
                                      (void *) _idscroll_entrypoint_3,
                                      (void *) func_800EE108,
                                      (void *) _idwater_entrypoint_4,
                                      (void *) _idglow_entrypoint_3,
                                      (void *) _idwave_entrypoint_3,
                                      (void *) _idglowa_entrypoint_4,
                                      (void *) _idflash_entrypoint_3,
                                      (void *) _idflasha_entrypoint_4,
                                      (void *) func_800EC9E0,
                                      (void *) _idwibble_entrypoint_3,
                                      (void *) _idbounce_entrypoint_5,
                                      (void *) _idtwinkle_entrypoint_5,
                                      (void *) _idflame_entrypoint_4,
                                      (void *) _idtwinklea_entrypoint_2,
                                      (void *) _idtwinklecolour_entrypoint_5};
