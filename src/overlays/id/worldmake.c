#include "common.h"

typedef struct {
    s32 owner;
    s16 mesh_id;
    u8 type;
    u8 enabled;
    u8 state[0xA0];
} WorldMakeStateRecord;
typedef struct {
    void (*init)(void *, s32, s32, s16, s32);
    void (*destroy)(void *);
} WorldMakeCallbacks;
extern void *D_80127EF8;
extern WorldMakeCallbacks D_80800AB0_idworldmake[];
extern void *vector_new(u32, u32);
extern void *vector_push_back(void **);
typedef struct {
    s32 owner;
    u8 pad_0[2];
    u8 type;
    u8 pad_1;
    u8 state[0xA0];
} WorldCreationItem;
typedef struct {
    u8 pad_0[8];
    void *entries;
} WorldCreationList;
extern WorldCreationList D_80127EF0;
extern void *vector_begin(void *);
extern void *vector_end(void *);
typedef struct {
    u8 pad_0[6];
    u8 type;
    u8 pad_7;
    u8 state[0xA0];
} WorldMakeRecord;
extern void vector_free(void *);

// Creates one effect entry and runs the init of its type.
void func_80800000_idworldmake(s32 owner, s32 mesh_id, s32 type, s32 local_id, s32 arg)
{
    WorldMakeStateRecord *entry;
    if (D_80127EF8 == NULL)
        D_80127EF8 = vector_new(sizeof(WorldMakeStateRecord), 2);
    entry = vector_push_back(&D_80127EF8);
    entry->type = type;
    entry->owner = owner;
    entry->mesh_id = mesh_id;
    entry->enabled = 1;
    D_80800AB0_idworldmake[entry->type].init(entry->state, local_id, owner, entry->mesh_id,
                                             arg);
}

// Creates an entry for each mesh id of the model; the type follows from the id range.
void idworldmake_entrypoint_0(s32 owner, s32 arg)
{
    s16 *count_ptr;
    s16 *list;
    s16 *cur;
    s16 mesh_id;
    s32 i;
    list = _glidmake_entrypoint_1();
    count_ptr = list;
    cur = list + 1;
    i = 0;
    if (*list > 0) {
        do {
            mesh_id = *cur;
            if ((mesh_id >= 0x65) && (mesh_id < 0xC8))
                func_80800000_idworldmake(owner, mesh_id, 1, mesh_id - 0x64, arg);
            else if ((mesh_id >= 0xC8) && (mesh_id < 0x12C))
                func_80800000_idworldmake(owner, mesh_id, 0, mesh_id - 0xC8, arg);
            else if ((mesh_id >= 0x12C) && (mesh_id < 0x190))
                func_80800000_idworldmake(owner, mesh_id, 3, mesh_id - 0x12C, arg);
            else if ((mesh_id >= 0x190) && (mesh_id < 0x1F4))
                func_80800000_idworldmake(owner, mesh_id, 2, mesh_id - 0x190, arg);
            else if ((mesh_id >= 0x1F4) && (mesh_id < 0x258))
                func_80800000_idworldmake(owner, mesh_id, 4, mesh_id - 0x1F4, arg);
            else if ((mesh_id >= 0x258) && (mesh_id < 0x2BC))
                func_80800000_idworldmake(owner, mesh_id, 2, mesh_id - 0x258, arg);
            else if ((mesh_id >= 0x2BC) && (mesh_id < 0x320))
                func_80800000_idworldmake(owner, mesh_id, 5, mesh_id - 0x2BC, arg);
            else if ((mesh_id >= 0x320) && (mesh_id < 0x384))
                func_80800000_idworldmake(owner, mesh_id, 6, mesh_id - 0x320, arg);
            else if ((mesh_id >= 0x384) && (mesh_id < 0x3E8))
                func_80800000_idworldmake(owner, mesh_id, 8, mesh_id - 0x384, arg);
            else if ((mesh_id >= 0x3E8) && (mesh_id < 0x44C))
                func_80800000_idworldmake(owner, mesh_id, 7, mesh_id - 0x3E8, arg);
            else if ((mesh_id >= 0x44C) && (mesh_id < 0x4B0))
                func_80800000_idworldmake(owner, mesh_id, 9, mesh_id - 0x44C, arg);
            else if ((mesh_id >= 0x4B0) && (mesh_id < 0x6A4))
                func_80800000_idworldmake(owner, mesh_id, 0xA, mesh_id - 0x4B0, arg);
            else if ((mesh_id >= 0x6A4) && (mesh_id < 0x708))
                func_80800000_idworldmake(owner, mesh_id, 0xB, mesh_id - 0x6A4, arg);
            else if ((mesh_id >= 0x708) && (mesh_id < 0x76C))
                func_80800000_idworldmake(owner, mesh_id, 0xC, mesh_id - 0x708, arg);
            else if ((mesh_id >= 0x76C) && (mesh_id < 0x7D0))
                func_80800000_idworldmake(owner, mesh_id, 0xD, mesh_id - 0x76C, arg);
            else if ((mesh_id >= 0x7D0) && (mesh_id < 0x834))
                func_80800000_idworldmake(owner, mesh_id, 0xE, mesh_id - 0x7D0, arg);
            else if ((mesh_id >= 0x834) && (mesh_id < 0x898))
                func_80800000_idworldmake(owner, mesh_id, 0xA, mesh_id - 0x4B0, arg);
            else if ((mesh_id >= 0x898) && (mesh_id < 0x8FC))
                func_80800000_idworldmake(owner, mesh_id, 0xF, mesh_id - 0x898, arg);
            i += 1;
            cur += *(s16 *) ((u8 *) cur + 2);
            cur += 2;
        } while (i < *count_ptr);
    }
}

// Creates a single entry for mesh_id, with the type taken from range_id.
void idworldmake_entrypoint_1(s32 owner, s32 range_id, volatile unsigned int mesh_id, s32 arg)
{
    s16 *count_ptr;
    int step;
    s16 *list;
    s16 *cur;
    s16 cur_id;
    s32 i;
    list = _glidmake_entrypoint_1();
    count_ptr = list;
    cur = list + 1;
    i = 0;
    if (*list > 0) {
        do {
            // Matching: the cast and + 0 are needed for the match.
            cur_id = *(s16 *) ((s8 *) cur + 0);
            if (mesh_id == cur_id) {
                if ((range_id >= 0x65) && (range_id < 0xC8)) {
                    func_80800000_idworldmake(owner, cur_id, 1, range_id - 0x64, arg);
                } else if ((range_id >= 0xC8) && (range_id < 0x12C)) {
                    func_80800000_idworldmake(owner, cur_id, 0, range_id - 0xC8, arg);
                } else if ((range_id >= 0x12C) && (range_id < 0x190)) {
                    func_80800000_idworldmake(owner, cur_id, 3, range_id - 0x12C, arg);
                } else if ((range_id >= 0x190) && (range_id < 0x1F4)) {
                    func_80800000_idworldmake(owner, cur_id, 2, range_id - 0x190, arg);
                } else if ((range_id >= 0x1F4) && (range_id < 0x258)) {
                    func_80800000_idworldmake(owner, cur_id, 4, range_id - 0x1F4, arg);
                } else if ((range_id >= 0x258) && (range_id < 0x2BC)) {
                    func_80800000_idworldmake(owner, cur_id, 2, range_id - 0x258, arg);
                } else if ((range_id >= 0x320) && (range_id < 0x384)) {
                    func_80800000_idworldmake(owner, cur_id, 6, range_id - 0x320, arg);
                } else if ((range_id >= 0x384) && (range_id < 0x3E8)) {
                    func_80800000_idworldmake(owner, cur_id, 8, range_id - 0x384, arg);
                } else if ((range_id >= 0x3E8) && (range_id < 0x44C)) {
                    func_80800000_idworldmake(owner, cur_id, 7, range_id - 0x3E8, arg);
                } else if ((range_id >= 0x44C) && (range_id < 0x4B0)) {
                    func_80800000_idworldmake(owner, cur_id, 9, range_id - 0x44C, arg);
                } else if ((range_id >= 0x6A4) && (range_id < 0x708)) {
                    func_80800000_idworldmake(owner, cur_id, 0xB, range_id - 0x6A4, arg);
                } else if ((range_id >= 0x708) && (range_id < 0x76C)) {
                    func_80800000_idworldmake(owner, cur_id, 0xC, range_id - 0x708, arg);
                } else if ((range_id >= 0x76C) && (range_id < 0x7CF)) {
                    func_80800000_idworldmake(owner, cur_id, 0xD, range_id - 0x76C, arg);
                } else if ((range_id >= 0x2BC) && (range_id < 0x320)) {
                    func_80800000_idworldmake(owner, cur_id, 5, range_id - 0x2BC, arg);
                } else if ((range_id >= 0x4B0) && (range_id < 0x6A4)) {
                    func_80800000_idworldmake(owner, cur_id, 0xA, range_id - 0x4B0, arg);
                } else if ((range_id >= 0x898) && (range_id < 0x8FC)) {
                    func_80800000_idworldmake(owner, cur_id, 0xF, range_id - 0x898, arg);
                }
            }
            i += 1;
            // Matching: the step temporary is needed for the match.
            cur = &cur[*(s16 *) ((s8 *) cur + 2)] + (step = 2);
        } while (i < *count_ptr);
    }
}

// Removes all entries of an owner.
void idworldmake_entrypoint_2(s32 owner)
{
    WorldCreationItem *entry;
    WorldCreationItem *end;

    end = vector_end(D_80127EF0.entries);
    for (entry = vector_begin(D_80127EF0.entries); entry < end; entry++) {
        if (entry->owner == owner) {
            D_80800AB0_idworldmake[entry->type].destroy(entry->state);
            vector_erase(D_80127EF0.entries, vector_index_of(D_80127EF0.entries, entry));
            entry = vector_begin(D_80127EF0.entries);
            end = vector_end(D_80127EF0.entries);
        }
    }
}

// Frees all entries.
void idworldmake_entrypoint_3(void)
{
    WorldMakeRecord *end;
    WorldMakeRecord *entry;

    if (D_80127EF8 != 0) {
        end = vector_end(D_80127EF8);
        entry = vector_begin(D_80127EF8);
        while (entry < end) {
            D_80800AB0_idworldmake[entry->type].destroy(entry->state);
            entry++;
        }
        vector_free(D_80127EF8);
        D_80127EF8 = 0;
    }
}

void idworldmake_entrypoint_4(void)
{
}

// Enables or disables all entries of an owner.
void idworldmake_entrypoint_5(s32 owner, s32 enabled)
{
    WorldMakeStateRecord *entry;
    WorldMakeStateRecord *end;

    end = vector_end(D_80127EF8);
    entry = vector_begin(D_80127EF8);
    while (entry < end) {
        if (owner == entry->owner) {
            entry->enabled = enabled;
        }
        entry++;
    }
}

// Sets the enabled flag for an owner, except for types in type_mask.
void idworldmake_entrypoint_6(s32 owner, s32 enabled, s32 type_mask)
{
    WorldMakeStateRecord *entry;
    WorldMakeStateRecord *end;

    end = vector_end(D_80127EF8);
    entry = vector_begin(D_80127EF8);
    while (entry < end) {
        if (owner == entry->owner && !((1 << entry->type) & type_mask)) {
            entry->enabled = enabled;
        }
        entry++;
    }
}

// Sets the enabled flag of one owner and mesh id.
void idworldmake_entrypoint_7(s32 owner, s32 mesh_id, s32 enabled)
{
    WorldMakeStateRecord *entry;
    WorldMakeStateRecord *end;

    end = vector_end(D_80127EF8);
    entry = vector_begin(D_80127EF8);
    while (entry < end) {
        if (owner == entry->owner && mesh_id == entry->mesh_id) {
            entry->enabled = enabled;
        }
        entry++;
    }
}

// TU-NOTE: this overlay data is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit.
extern void _idlight_entrypoint_2();
extern void _idlight_entrypoint_1();
extern void _idscroll_entrypoint_2();
extern void _idscroll_entrypoint_1();
extern void func_800EDB20();
extern void func_800EDAF4();
extern void _idwater_entrypoint_3();
extern void _idwater_entrypoint_2();
extern void _idglow_entrypoint_2();
extern void _idglow_entrypoint_1();
extern void _idwave_entrypoint_2();
extern void _idwave_entrypoint_1();
extern void _idglowa_entrypoint_3();
extern void _idglowa_entrypoint_2();
extern void _idflash_entrypoint_2();
extern void _idflash_entrypoint_1();
extern void _idflasha_entrypoint_3();
extern void _idflasha_entrypoint_2();
extern void func_800EC898();
extern void func_800EC890();
extern void _idwibble_entrypoint_2();
extern void _idwibble_entrypoint_1();
extern void _idbounce_entrypoint_4();
extern void _idbounce_entrypoint_3();
extern void _idtwinkle_entrypoint_4();
extern void _idtwinkle_entrypoint_3();
extern void _idflame_entrypoint_3();
extern void _idflame_entrypoint_2();
extern void _idtwinklea_entrypoint_0();
extern void _idtwinklea_entrypoint_1();
extern void _idtwinklecolour_entrypoint_4();
extern void _idtwinklecolour_entrypoint_3();
WorldMakeCallbacks D_80800AB0_idworldmake[16] = {(void *) _idlight_entrypoint_2,
                                                 (void *) _idlight_entrypoint_1,
                                                 (void *) _idscroll_entrypoint_2,
                                                 (void *) _idscroll_entrypoint_1,
                                                 (void *) func_800EDB20,
                                                 (void *) func_800EDAF4,
                                                 (void *) _idwater_entrypoint_3,
                                                 (void *) _idwater_entrypoint_2,
                                                 (void *) _idglow_entrypoint_2,
                                                 (void *) _idglow_entrypoint_1,
                                                 (void *) _idwave_entrypoint_2,
                                                 (void *) _idwave_entrypoint_1,
                                                 (void *) _idglowa_entrypoint_3,
                                                 (void *) _idglowa_entrypoint_2,
                                                 (void *) _idflash_entrypoint_2,
                                                 (void *) _idflash_entrypoint_1,
                                                 (void *) _idflasha_entrypoint_3,
                                                 (void *) _idflasha_entrypoint_2,
                                                 (void *) func_800EC898,
                                                 (void *) func_800EC890,
                                                 (void *) _idwibble_entrypoint_2,
                                                 (void *) _idwibble_entrypoint_1,
                                                 (void *) _idbounce_entrypoint_4,
                                                 (void *) _idbounce_entrypoint_3,
                                                 (void *) _idtwinkle_entrypoint_4,
                                                 (void *) _idtwinkle_entrypoint_3,
                                                 (void *) _idflame_entrypoint_3,
                                                 (void *) _idflame_entrypoint_2,
                                                 (void *) _idtwinklea_entrypoint_0,
                                                 (void *) _idtwinklea_entrypoint_1,
                                                 (void *) _idtwinklecolour_entrypoint_4,
                                                 (void *) _idtwinklecolour_entrypoint_3};
