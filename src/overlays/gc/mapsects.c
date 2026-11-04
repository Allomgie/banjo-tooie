// Map-sections manager for maps split into streamed sections (Jolly Roger's Lagoon): activates,
// loads, draws and queries sections by player position and camera frustum.
#include "common.h"
#include "maps.h"

typedef struct {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5;
    u8 local_6[8];
    s16 local_7;
    s16 local_8;
    void *local_9;
    void *local_10;
    u32 local_11 : 1;
    u32 local_12 : 1;
    u32 local_13 : 1;
    u32 local_14 : 1;
    u32 local_15 : 1;
    u32 local_16 : 2;
    u32 local_17 : 1;
    u32 local_18 : 24;
    void *local_19;
    void *local_20;
} MapSectionInit50;
typedef struct {
    u8 local_0[0x68];
    MapSectionInit50 *local_1;
    u8 local_2[0xB];
    u8 local_3;
} MapSectionListInit50;
extern void *func_800BF704(void);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 D_808029B0_gcmapsects[3];
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
typedef struct {
    u8 pad_0[0x44];
    void *local_0;
    void *local_1;
    u8 pad_1[0xC];
} MapSectionTextures;
typedef struct {
    u8 pad_0[0x68];
    MapSectionTextures *local_0;
} MapSections;
typedef struct {
    u8 pad0[0x40];
    u16 unk40;
    u16 unk42;
    u8 pad44[8];
    u32 unk4C_31 : 1;
    u32 pad4C_30 : 1;
    u32 unk4C_29 : 1;
    u32 unk4C_28 : 1;
    u32 pad4C_0 : 28;
    s32 unk50[2];
} MapSect_808003F4_gcmapsects;
typedef struct {
    u8 pad0[0x68];
    MapSect_808003F4_gcmapsects *sects;
} MapSects;
extern s32 func_800D70F8(s32, s32);
extern s32 func_800D73CC();
extern s32 func_800D6CEC(s32);
extern s32 func_800E4AF0(s32);
extern void func_800E4BB8(s32);
extern void _idworldmake_entrypoint_2(s32);
extern void _glidmake_entrypoint_4(s32);
typedef struct {
    u8 pad_0[0x40];
    u16 local_0[2];
    u8 pad_1[0xC];
    s32 local_1[2];
} CodexMapSectionRecord65;
typedef struct {
    u8 pad_0[0x68];
    CodexMapSectionRecord65 *local_0;
    u8 pad_1[0x15];
    u8 local_1;
} CodexMapSectionContext65;
typedef struct {
    u8 pad_0[0x38];
    u8 local_0[4];
    u8 pad_1[0x1C];
} MapSectionNeighbors;
typedef struct {
    u8 pad_0[0x68];
    MapSectionNeighbors *local_0;
} MapSectionNeighborList;
extern void func_800D5B24();
typedef struct {
    u8 pad_0[0x4C];
    u32 pad_1 : 3;
    u32 local_0 : 1;
    u32 pad_2 : 28;
} MapSectionLoadedFlags1041;
typedef struct MapSectObject {
    u8 pad_0[0x40];
    u16 local_0;
    u8 pad_1[10];
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 local_4 : 1;
    u32 pad_2 : 28;
    u8 pad_3[8];
} MapSectObject;
typedef struct MapSectCollection {
    u8 pad_0[0x68];
    MapSectObject *local_0;
    u8 pad_1[11];
    u8 local_1;
} MapSectCollection;
typedef struct {
    u8 pad_0[0xC];
    f32 first[3];
    f32 second[3];
    u8 pad_1[0x34];
} MapSectionBounds;
typedef struct {
    u8 pad_0[0x68];
    MapSectionBounds *sections;
    u8 pad_1[0xB];
    u8 count;
} MapSectionBoundsList;
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef struct Mass43CullSection {
    u8 pad_0[0xC];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    u8 pad_1[4];
    u8 local_4[4];
    u8 pad_2[0x10];
    u32 local_5 : 1;
    u32 local_6 : 1;
    u32 local_7 : 1;
    u32 pad_3 : 1;
    u32 local_8 : 1;
    u32 pad_4 : 2;
    u32 local_9 : 1;
    u32 pad_5 : 24;
    u8 pad_6[8];
} Mass43CullSection;
typedef struct Mass43MapObject {
    u8 pad_0[0x68];
    Mass43CullSection *local_0;
    u8 pad_1[0xF];
    u8 local_1;
    u8 pad_2[2];
    u8 local_2;
} Mass43MapObject;
extern s32 func_800E3E8C(f32 *, f32);
typedef struct MapSectionSearchRecord_gcmapsects_entrypoint_6 {
    u8 pad_0[12];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    u8 pad_1[0x20];
} MapSectionSearchRecord_gcmapsects_entrypoint_6;
typedef struct MapSectionSearchList {
    u8 pad_0[0x68];
    MapSectionSearchRecord_gcmapsects_entrypoint_6 *local_0;
    u8 pad_1[8];
    s16 local_1;
    u8 pad_2;
    u8 local_2;
} MapSectionSearchList;
extern s32 func_800EFED0(f32 *, f32 *, f32 *);
typedef struct Mass43CullObject {
    u8 pad_0[0x68];
    Mass43CullSection *local_0;
    u8 pad_1[0xF];
    u8 local_1;
    u8 pad_2[2];
    u8 local_2;
} Mass43CullObject;
typedef struct MapSectionActivation {
    u8 pad_0[0x24];
    f32 local_0[3];
    f32 local_1;
    u8 pad_1[0x18];
    u32 pad_2 : 1;
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 pad_3 : 29;
    u8 pad_4[8];
} MapSectionActivation;
typedef struct MapSectionActivationList {
    u8 pad_0[0x68];
    MapSectionActivation *local_0;
} MapSectionActivationList;
typedef struct {
    u8 pad_0[0x3C];
    u8 local_0[4];
    u8 pad_1[0xC];
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_2 : 30;
    u8 pad_3[8];
} MapSectionLinks;
typedef struct {
    u8 pad_0[0x68];
    MapSectionLinks *local_0;
} MapSectionState;
extern void func_8008FE68(f32 *);
extern u32 func_800F54E4(void);
extern void func_800F4CC0(s32);
extern void func_800F4CEC(s32, s32);
typedef struct {
    u8 local_0[0x40];
    u16 local_1;
    u8 local_2[0xA];
    u32 local_3 : 1;
    u32 local_4 : 1;
    u32 local_5 : 1;
    u32 local_6 : 2;
    u32 local_7 : 1;
    u32 local_8 : 26;
    u8 local_9[8];
} MapSectionUpdate50;
typedef struct MapSectionListUpdate50 {
    u8 local_0[0x68];
    MapSectionUpdate50 *local_1;
    void (*local_2)(struct MapSectionListUpdate50 *);
    u8 local_3[7];
    u8 local_4;
    u8 local_5;
    u8 local_6;
    u8 local_7;
    u8 local_8;
    u8 local_9;
    u8 local_10;
    u8 local_11;
    u8 local_12;
    u8 local_13[3];
    u8 local_14;
} MapSectionListUpdate50;
extern MapId func_800EA05C(void);
extern void _gcmapsects_lagoontop_entrypoint_0(void);
extern void _gcmapsects_lagoonmid_entrypoint_0(void);
extern void _gcmapsects_lagoonbot_entrypoint_0(void);
typedef struct {
    u8 pad_0[0x4C];
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_1 : 2;
    u32 local_3 : 1;
    u32 pad_2 : 26;
    u8 pad_3[8];
} MapSectorRecord1358;
typedef struct {
    u8 pad_0[0x68];
    MapSectorRecord1358 *local_0;
    s32 local_1;
    f32 local_2;
    s16 local_3;
    u8 local_4;
    u8 local_5;
    u8 local_6;
    u8 local_7;
    u8 local_8;
    u8 local_9;
    u8 local_10;
    u8 local_11;
    u8 local_12;
    u8 local_13;
    u8 local_14;
    u8 local_15;
    u8 local_16;
    u8 local_17;
} MapSectorManager1358;
typedef struct {
    u8 pad_0[0x40];
    u16 local_0;
    u8 pad_1[2];
    s32 local_2;
    u8 pad_5[4];
    u32 local_3 : 1;
    u32 local_1 : 1;
    u32 pad_3 : 30;
    u8 pad_4[8];
} MapSectionRenderItem_gcmapsects_entrypoint_20;
typedef struct {
    u8 pad_0[0x68];
    MapSectionRenderItem_gcmapsects_entrypoint_20 *local_0;
    u8 pad_1[0xB];
    u8 local_1;
} MapSectionRenderList;
extern void *func_800D674C(s32);
extern void *func_800B2720(void *);
extern void *func_800B2840(void *);
extern s32 func_800AD2C8(void *, void *, void *, void *,
                         MapSectionRenderItem_gcmapsects_entrypoint_20 *, s32, s32, f32);
typedef struct MapSectCollisionQueryFlags {
    u32 pad_0 : 1;
    u32 local_0 : 1;
    u32 pad_1 : 30;
} MapSectCollisionQueryFlags;
extern int func_800AD894(s32, s32, f32 *, f32 *, void *, f32 *, f32);
extern s32 func_800AB868(void *, void *, void *, s32, f32, void *, void *, void *, s32);
typedef struct {
    u8 pad_0[0x4C];
    u32 pad_1 : 1;
    u32 local_0 : 1;
    u32 pad_2 : 30;
} MapSectFlags;
typedef struct {
    u8 pad_0[0x4C];
    u32 pad_1 : 1;
    u32 local_0 : 1;
    u32 pad_2 : 30;
    u8 pad_3[8];
} MapSection1864;
extern s32 func_800AC848(s32, s32, void *, s32, f32, s32, s32, f32, s32, s32, s32);
typedef struct {
    u8 pad_0[0x40];
    u16 local_0;
    u8 pad_1[2];
    s32 local_2;
    u8 pad_5[4];
    u32 local_3 : 1;
    u32 local_1 : 1;
    u32 pad_3 : 30;
    u8 pad_4[8];
} MapSectionRenderItem_gcmapsects_entrypoint_26;
extern void func_800BEB58(void *);
extern void func_800D62E4(s32);
extern s32 func_800AD1AC(void *, void *, MapSectionRenderItem_gcmapsects_entrypoint_26 *, s32, f32,
                         s32, f32, s32, s32);
typedef struct {
    u8 pad_0[0x40];
    u16 local_0;
    u8 pad_1[2];
    s32 local_2;
    u8 pad_5[4];
    u32 local_3 : 1;
    u32 local_1 : 1;
    u32 pad_3 : 30;
    u8 pad_4[8];
} MapSectionRenderItem_gcmapsects_entrypoint_18;
extern void func_800BF774(void);
extern void func_800DF830(s32);
extern u8 func_800D731C(s32);
extern void func_800DF7E8(u8);
extern void func_800DF7DC(s32);
extern void func_800DF818(void *);
extern void func_800DF440(s32);
extern void func_800DF428(f32);
extern void func_800DF4B0(s32);
extern s32 func_800DE448(MapSectionRenderItem_gcmapsects_entrypoint_18 *, s32, f32, s32, void *);

typedef struct {
    f32 pos[3];
    u8 padC[0x42 - 0xC];
    u16 model;
    u8 pad44[4];
    s32 unk48;
    u32 unk4C_31 : 1;
    u32 pad4C : 31;
    u8 pad50[8];
} MapSect_gcmapsects_entrypoint_19;
typedef struct {
    u8 pad0[0x68];
    MapSect_gcmapsects_entrypoint_19 *sects;
    u8 pad6C[0x77 - 0x6C];
    u8 count;
} MapSectsData;

// Group: section setup, streaming, per-frame activation, draw passes, init/free, accessors.
// Appends a section record with its AABB and bounding sphere.
void gcmapsects_entrypoint_0(s16 opaque_model, s16 translucent_model, f32 *origin, f32 *box_min, f32 *box_max,
                             f32 unk_0)
{
    MapSectionListInit50 *list;
    s32 slot;
    list = func_800BF704();
    slot = list->local_3;
    func_800EE7F8(list->local_1[slot].local_0, origin);
    func_800EE7F8(list->local_1[slot].local_1, box_min);
    func_800EE7F8(list->local_1[slot].local_2, box_max);
    func_800EF3DC(list->local_1[slot].local_1, D_808029B0_gcmapsects);
    func_800EF04C(list->local_1[slot].local_2, D_808029B0_gcmapsects);
    func_800EE780(list->local_1[slot].local_3, list->local_1[slot].local_1,
                  list->local_1[slot].local_2);
    func_800EF334(list->local_1[slot].local_3, 0.5f);
    list->local_1[slot].local_4 =
        func_800EEAD4(list->local_1[slot].local_3, list->local_1[slot].local_1);
    list->local_1[slot].local_7 = opaque_model;
    list->local_1[slot].local_8 = translucent_model;
    list->local_1[slot].local_6[0] = 255;
    list->local_1[slot].local_6[1] = 255;
    list->local_1[slot].local_6[2] = 255;
    list->local_1[slot].local_6[3] = 255;
    list->local_1[slot].local_6[4] = 255;
    list->local_1[slot].local_6[5] = 255;
    list->local_1[slot].local_6[6] = 255;
    list->local_1[slot].local_6[7] = 255;
    list->local_1[slot].local_11 = 0;
    list->local_1[slot].local_12 = 0;
    list->local_1[slot].local_13 = 0;
    list->local_1[slot].local_14 = 0;
    list->local_1[slot].local_15 = 1;
    list->local_1[slot].local_17 = 1;
    list->local_1[slot].local_9 = 0;
    list->local_1[slot].local_10 = 0;
    list->local_1[slot].local_5 = unk_0;
    list->local_1[slot].local_19 = 0;
    list->local_1[slot].local_20 = 0;
    list->local_3++;
}

// Creates the section's opaque and translucent textures from its model assets.
void func_80800250_gcmapsects(u8 *manager, s32 sect_index)
{
    s32 asset;
    s32 offset;
    s32 opaque_asset;
    s32 translucent_asset;
    u16 opaque_id;
    u16 translucent_id;
    u8 *sect;
    offset = sect_index * 0x58;
    sect = *(s32 *) ((s8 *) manager + 0x68) + offset;
    if (*(s32 *) ((s8 *) sect + 0x44) == 0) {
        opaque_id = *(u16 *) ((s8 *) sect + 0x40);
        if (opaque_id != 0) {
            opaque_asset = func_800D674C(opaque_id & 0xFFFFFFFF);
        // Matching: the `^ 0` is needed for the match.
            asset = opaque_asset ^ 0;
            if (func_800B27FC(opaque_asset) != 0) {
                *(s32 *) ((s8 *) (*(s32 *) ((s8 *) manager + 0x68) + offset) + 0x44) =
                    _dbtex_entrypoint_0(func_800B27FC(asset));
            }
            func_800D6CEC(*(u16 *) ((s8 *) (*(s32 *) ((s8 *) manager + 0x68) + offset) + 0x40));
            sect = *(s32 *) ((s8 *) manager + 0x68) + offset;
        }
    }
    if (*(s32 *) ((s8 *) sect + 0x48) == 0) {
        translucent_id = *(u16 *) ((s8 *) sect + 0x42);
        if (translucent_id) {
            translucent_asset = func_800D674C(translucent_id);
            asset = translucent_asset;
            if (func_800B27FC(translucent_asset) != 0) {
                *(s32 *) ((s8 *) (*(s32 *) ((s8 *) manager + 0x68) + offset) + 0x48) =
                    _dbtex_entrypoint_0(func_800B27FC(asset));
            }
            func_800D6CEC(*(u16 *) ((s8 *) (*(s32 *) ((s8 *) manager + 0x68) + offset) + 0x42));
        }
    }
}

// Frees the section's textures.
void func_8080035C_gcmapsects(MapSections *manager, s32 sect_index)
{
    if (manager->local_0[sect_index].local_0) {
        _dbtex_entrypoint_1(manager->local_0[sect_index].local_0);
        manager->local_0[sect_index].local_0 = NULL;
    }
    if (manager->local_0[sect_index].local_1) {
        _dbtex_entrypoint_1(manager->local_0[sect_index].local_1);
        manager->local_0[sect_index].local_1 = NULL;
    }
}

// Unloads the section's model assets, streaming state and vertex instances.
void func_808003F4_gcmapsects(MapSects *manager, s32 sect_index)
{
    s32 i;
    u16 translucent_id;

    manager->sects[sect_index].unk4C_29 = 0;
    manager->sects[sect_index].unk4C_31 = 0;
    if (manager->sects[sect_index].unk4C_28) {
        func_800D70F8(manager->sects[sect_index].unk40, 0);
        manager->sects[sect_index].unk4C_28 = 0;
    }
    if (func_800D73CC(manager->sects[sect_index].unk40)) {
        func_800D6CEC(manager->sects[sect_index].unk40);
    }
    translucent_id = manager->sects[sect_index].unk42;
    if (translucent_id && func_800D73CC(translucent_id)) {
        func_800D70F8(manager->sects[sect_index].unk42, 0);
        func_800D6CEC(manager->sects[sect_index].unk42);
    }
    if (func_800E4AF0(manager->sects[sect_index].unk40)) {
        func_800E4BB8(manager->sects[sect_index].unk40);
    }
    for (i = 0; i < 2; i++) {
        if (manager->sects[sect_index].unk50[i]) {
            _idworldmake_entrypoint_2(manager->sects[sect_index].unk50[i]);
            _glidmake_entrypoint_4(manager->sects[sect_index].unk50[i]);
            manager->sects[sect_index].unk50[i] = 0;
        }
    }
}

// Creates or frees the section's vertex instances.
void func_808005D0_gcmapsects(CodexMapSectionContext65 *manager, s32 sect_index, s32 model_asset)
{
    s32 i;

    if (!model_asset) {
        for (i = 0; i < 2; i++) {
            if (manager->local_0[sect_index].local_1[i]) {
                _idworldmake_entrypoint_2(manager->local_0[sect_index].local_1[i]);
                _glidmake_entrypoint_4(manager->local_0[sect_index].local_1[i]);
                manager->local_0[sect_index].local_1[i] = 0;
            }
        }
    } else {
        for (i = 0; i < 2; i++) {
            if (manager->local_0[sect_index].local_0[i] && (manager->local_1 & (1 << i)) &&
                !manager->local_0[sect_index].local_1[i]) {
                if (func_800B274C(i
                                      ? func_800D674C(manager->local_0[sect_index].local_0[i])
                                      : model_asset)) {
                    manager->local_0[sect_index].local_1[i] =
                        _glidmake_entrypoint_5(manager->local_0[sect_index].local_0[i],
                                               manager->local_0[sect_index].pad_0);
                } else {
                    manager->local_0[sect_index].local_1[i] = 0;
                }
                if (manager->local_0[sect_index].local_1[i]) {
                    _idworldmake_entrypoint_0(manager->local_0[sect_index].local_1[i], 2);
                }
            }
        }
        for (i = 0; i < 2; i++) {
            if (manager->local_0[sect_index].local_1[i]) {
                _glid_entrypoint_5(
                    manager->local_0[sect_index].local_1[i],
                    func_800B2840(i ? func_800D674C(manager->local_0[sect_index].local_0[1])
                                          : model_asset));
            }
        }
    }
}

void gcmapsects_entrypoint_1(sect_index, flag) s16 sect_index;
s32 flag;
{
    // Matching: the temporary assigned inside the expression is needed for the match.
    int shifted;
    u8 *sect;
    s8 *list_ptr;
    list_ptr = (s8 *) func_800BF704() + 0x68;
    sect = *(s32 *) list_ptr + (sect_index * 0x58);
    *(u8 *) ((s8 *) sect + 0x4C) = (u8) ((*(u8 *) ((s8 *) sect + 0x4C) & 0xFFF7) |
                                            ((shifted = (flag & 0xFFFFu) * 8) & 8));
}

void gcmapsects_entrypoint_2(sect_index, flag) s16 sect_index;
s32 flag;
{
    short mask16;
    int flags;
    u8 *sect;
    sect = *(s32 *) ((s8 *) func_800BF704() + 0x68) + (sect_index * 0x58);
    // Matching: the redundant masks below are needed for the match.
    mask16 = 0xFFFFu;
    flags = (*(u8 *) ((s8 *) sect + 0x4C) & 0xFFFFu) & mask16;
    *(u8 *) ((s8 *) sect + 0x4C) =
        (u8) ((flag & 1) |
              (((((((flags & mask16) & mask16) & mask16) & 0xFFFFu) & mask16) &
                mask16) &
               0xFFFE));
}

// Links two sections as neighbours (up to 4 links each, 0xFF = free slot).
void gcmapsects_entrypoint_3(sect_a, sect_b) s16 sect_a;
s16 sect_b;
{
    MapSectionNeighborList *list;
    s32 i;

    list = func_800BF704();
    for (i = 0; i < 4; i++) {
        if (list->local_0[sect_a].local_0[i] == 0xFF) {
            list->local_0[sect_a].local_0[i] = sect_b;
            break;
        }
    }
    for (i = 0; i < 4; i++) {
        if (list->local_0[sect_b].local_0[i] == 0xFF) {
            list->local_0[sect_b].local_0[i] = sect_a;
            break;
        }
    }
}

// Loads and locks the model assets of the active sections.
void func_80800A08_gcmapsects(u8 *manager, s32 load_all)
{
    s32 i = 0;
    s32 offset;
    u8 *sect;
    u16 model_id;
    while (i < manager[0x77]) {
        offset = i * 88;
        sect = *(u8 **) (manager + 0x68) + offset;
        if (((*(u32 *) (sect + 0x4C) << 2) >> 31) || load_all) {
            model_id = *(u16 *) (sect + 0x40);
            if (model_id && !func_800D73CC(model_id)) {
                func_800D5B24();
                func_800D674C(*(u16 *) (*(u8 **) (manager + 0x68) + offset + 0x40));
                func_800D70F8(*(u16 *) (*(u8 **) (manager + 0x68) + offset + 0x40), 1);
                ((MapSectionLoadedFlags1041 *) (*(u8 **) (manager + 0x68) + offset))->local_0 = 1;
            }
            model_id = *(u16 *) (*(u8 **) (manager + 0x68) + offset + 0x42);
            if (model_id && !func_800D73CC(model_id)) {
                func_800D5B24();
                func_800D674C(*(u16 *) (*(u8 **) (manager + 0x68) + offset + 0x42));
                func_800D70F8(*(u16 *) (*(u8 **) (manager + 0x68) + offset + 0x42), 1);
            }
        }
        func_80800250_gcmapsects(manager, i);
        i++;
    }
    if (!func_800DB9B0())
        manager[0x78] = 1;
}

void func_80800B58_gcmapsects(MapSectCollection *manager)
{
    s32 i;

    for (i = 0; i < manager->local_1; i++) {
        if (manager->local_0[i].local_3 &&
            !func_800D73CC(manager->local_0[i].local_0)) {
            if (func_800E488C(manager->local_0[i].local_0)) {
                func_800D674C(manager->local_0[i].local_0);
                func_800D70F8(manager->local_0[i].local_0, 1);
                manager->local_0[i].local_4 = 1;
            } else {
                manager->local_0[i].local_1 = 0;
                manager->local_0[i].local_2 = 0;
            }
        }
    }
}

// Unloads all sections.
int func_80800C54_gcmapsects(u8 *manager)
{
    s32 i;
    // Matching: the alias of the parameter is needed for the match.
    u8 *map = manager;
    for (i = 0; i < manager[0x77]; i++) {
        func_808003F4_gcmapsects(map, i);
        func_8080035C_gcmapsects(map, i);
    }
}

// Group: geometry queries on the active section models (point lookup, ray, sweep, sphere).
// Returns the index of the section whose AABB contains point, or -1.
s32 gcmapsects_entrypoint_4(f32 *point)
{
    MapSectionBoundsList *list;
    s32 i;
    list = func_800BF704();
    if (!list->count)
        return -1;
    for (i = 0; i < list->count; i++) {
        if (func_800EFED0(list->sections[i].first, list->sections[i].second,
                          point))
            return i;
    }
    return -1;
}

u32 gcmapsects_entrypoint_5(s32 sect_index)
{
    u8 *list;

    if (sect_index == -1) {
        return 1U;
    }
    list = func_800BF704();
    if (*(u8 *) ((s8 *) list + 0x77) == 0) {
        return 1U;
    }
    return (u32) (*(s32 *) ((s8 *) (*(s32 *) ((s8 *) list + 0x68) + (sect_index * 0x58)) + 0x4C) *
                  2) >>
           0x1F;
}

// Activates the section and its neighbours if the point is inside it; returns the index or -1.
s32 func_80800DC8_gcmapsects(Mass43MapObject *map, s32 sect_index, f32 *point)
{
    s32 i;

    if (func_800EFFB4(map->local_0[sect_index].local_2, map->local_0[sect_index].local_3,
                      point) &&
        func_800EFED0(map->local_0[sect_index].local_0, map->local_0[sect_index].local_1,
                      point)) {
        map->local_0[sect_index].local_5 = 1;
        map->local_0[sect_index].local_7 = 1;
        map->local_0[sect_index].local_6 = 1;
        if (map->local_0[sect_index].local_8)
            map->local_1 = 1;
        if (map->local_0[sect_index].local_9)
            map->local_2 = 1;
        for (i = 0; i < 4; i++) {
            if (map->local_0[sect_index].local_4[i] == 0xFF)
                break;
            map->local_0[map->local_0[sect_index].local_4[i]].local_5 = 1;
            map->local_0[map->local_0[sect_index].local_4[i]].local_7 = 1;
        }
        return sect_index;
    }
    return -1;
}

s32 gcmapsects_entrypoint_6(MapSectionSearchList *map, f32 *point, f32 *out_value)
{
    f32 neg_one = -1.0f;
    s32 i;
    s32 search_all;
    s32 cached_idx;
    f32 best_value;
    f32 section_value;
    search_all = 1;
    best_value = -1.0f;
    cached_idx = map->local_1;
    if (cached_idx != -1 &&
        func_800EFED0(map->local_0[cached_idx].local_0, map->local_0[cached_idx].local_1, point)) {
        search_all = 0;
        section_value = map->local_0[cached_idx].local_4;
        if (neg_one != section_value && (best_value < section_value || best_value == -1.0f)) {
            best_value = section_value;
        }
    }
    // Matching: the empty test reads the loop counter before it is initialised, which overlaps its live range with search_all.
    if (i) {
    }
    if (search_all) {
        for (i = 0; i < map->local_2; i++) {
            if (func_800EFFB4(map->local_0[i].local_2, map->local_0[i].local_3,
                              point) &&
                func_800EFED0(map->local_0[i].local_0, map->local_0[i].local_1,
                              point)) {
                section_value = map->local_0[i].local_4;
                if (neg_one != section_value && (best_value < section_value || best_value == -1.0f)) {
                    best_value = section_value;
                }
            }
        }
    }
    if (best_value != -1.0f) {
        if (best_value - 2000.0f < point[1] && point[1] < best_value + 2000.0f) {
            return 0;
        }
        *out_value = best_value;
        return 1;
    }
    return 0;
}

// Activates the section and its neighbours if it is inside the view frustum.
int func_80801174_gcmapsects(Mass43CullObject *map, s32 sect_index)
{
    s32 i;
    if (map->local_0[sect_index].local_5)
        return 1;
    if (func_800E3E8C(map->local_0[sect_index].local_2, map->local_0[sect_index].local_3) &&
        func_800E3D0C(map->local_0[sect_index].local_0, map->local_0[sect_index].local_1)) {
        map->local_0[sect_index].local_5 = 1;
        map->local_0[sect_index].local_7 = 1;

        if (map->local_0[sect_index].local_8)
            map->local_1 = 1;
        if (map->local_0[sect_index].local_9)
            map->local_2 = 1;
        for (i = 0; i < 4; i++) {
            if (map->local_0[sect_index].local_4[i] == 0xFF)
                break;
            map->local_0[map->local_0[sect_index].local_4[i]].local_5 = 1;
            map->local_0[map->local_0[sect_index].local_4[i]].local_7 = 1;
        }
        return 1;
    }
    return 0;
}

// Activates the section if the point is inside its bounding sphere.
s32 func_80801320_gcmapsects(MapSectionActivationList *map, s32 sect_index, f32 *point)
{
    if (map->local_0[sect_index].local_2) {
        return 1;
    }
    if (func_800EFFB4(map->local_0[sect_index].local_0, map->local_0[sect_index].local_1,
                      point)) {
        map->local_0[sect_index].local_3 = 1;
        map->local_0[sect_index].local_2 = 1;
        return 1;
    }
    return 0;
}

void func_808013C0_gcmapsects(MapSectionState *map, s32 sect_index)
{
    s32 i;
    u8 neighbor;
    if (map->local_0[sect_index].local_2) {
        for (i = 0; i < 4; i++) {
            neighbor = map->local_0[sect_index].local_0[i];
            if (neighbor == 0xFF)
                break;
            map->local_0[neighbor].local_1 = 0;
        }
    }
}

// Returns the index of the section containing point (last found section first), or -1.
s32 gcmapsects_entrypoint_7(f32 *point)
{
    MapSectionSearchList *map;
    s32 i;

    map = func_800BF704();
    i = map->local_1;
    if (i != -1 && func_800EFED0(map->local_0[i].local_0,
                                       map->local_0[i].local_1, point)) {
        return i;
    }
    for (i = 0; i < map->local_2; i++) {
        if (func_800EFFB4(map->local_0[i].local_2, map->local_0[i].local_3,
                          point) &&
            func_800EFED0(map->local_0[i].local_0, map->local_0[i].local_1,
                          point)) {
            return i;
        }
    }
    return -1;
}

s32 gcmapsects_entrypoint_8(Actor *this)
{
    this->unk78 = 0;
}

// Activates sections from the player position.
void func_80801554_gcmapsects(u8 *map)
{
    s32 i;
    f32 player_pos[3];
    s32 found;
    s32 result;

    func_8008FE68(player_pos);
    if (func_80090128()) {
        if (!map[0x80]) {
            found = -1;
            for (i = 0; i < map[0x77]; i++) {
                result = func_80800DC8_gcmapsects(map, i, player_pos);
                if (result != -1) {
                    found = result;
                }
            }
            *(s16 *) (map + 0x74) = found;
            map[0x82] = 1;
        } else {
            for (i = 0; i < map[0x77]; i++) {
                func_80801320_gcmapsects(map, i, player_pos);
            }
        }
    }
}

void func_80801640_gcmapsects(map) u8 *map;
{
    s32 i;
    f32 pos[3];
    s32 j;

    func_800E3980(pos);

if (*(u8 *) ((char *) map + 0x80) == 0) {
    i = 0;
    if ((s32) *(u8 *) ((char *) map + 0x77) > 0) {
        do {
            func_80800DC8_gcmapsects(map, i, pos);
            i += 1;
        } while (i < (s32) *(u8 *) ((char *) map + 0x77));
    }
} else {

j = 0;

if ((s32) *(u8 *) ((char *) map + 0x77) > 0) {
    do {
        func_80801174_gcmapsects(map, j);
        func_80801320_gcmapsects(map, j, pos);
        j += 1;
    } while (j < (s32) *(u8 *) ((char *) map + 0x77));
    j = 0;
}

if ((s32) *(u8 *) ((char *) map + 0x77) > 0) {
    do {
        func_808013C0_gcmapsects(map, j);
        j += 1;
    } while (j < (s32) *(u8 *) ((char *) map + 0x77));
}

}
}

void func_80801724_gcmapsects(u8 *map, s32 mode)
{
    switch (map[0x7F]) {
        case 1:
            break;
        case 2:
            func_800F4CC0(func_800F54E4());
    }
    map[0x7F] = mode;
    switch (map[0x7F]) {
        case 1:
            break;
        case 2:
            func_800F4CEC(func_800F54E4(), 0x77);
    }
}

// Per-frame update.
void gcmapsects_entrypoint_9(MapSectionListUpdate50 *map)
{
    s32 i;
    map->local_8 = map->local_6;
    map->local_11 = map->local_10;
    for (i = 0; i < map->local_4; i++) {
        map->local_1[i].local_3 = 0;
        map->local_1[i].local_4 = 0;
        map->local_1[i].local_7 = map->local_1[i].local_5;
        map->local_1[i].local_5 = map->local_14;
    }
    switch (map->local_12) {
        case 1:
            if (func_800DB9B0())
                func_80801724_gcmapsects(map, 2);
            break;
        case 2:
            if (!func_800DB9B0())
                func_80801724_gcmapsects(map, 1);
            break;
    }
    switch (map->local_12) {
        case 1:
            func_80801554_gcmapsects(map);
            func_80801640_gcmapsects(map);
            break;
        case 2:
            map->local_5 = 0;
    }
    if (map->local_2)
        map->local_2(map);
    for (i = 0; i < map->local_4; i++) {
        if (!map->local_1[i].local_5)
            func_808003F4_gcmapsects(map, i);
    }
    if (!map->local_5)
        func_80800A08_gcmapsects(map, map->local_14);
    else
        func_80800B58_gcmapsects(map);
    for (i = 0; i < map->local_4; i++) {
        if (map->local_1[i].local_5)
            func_808005D0_gcmapsects(map, i,
                                     func_800D6B0C(map->local_1[i].local_1));
    }
}

void gcmapsects_entrypoint_10(s32 count)
{
    u8 *map;
    u8 *map_alias;

    map = func_800BF704();
    if (count != 0) {
        (*(s8 *) ((s8 *) (map) + (0x76))) = (s8) count;
        // Matching: the extra pointer copy is needed for the match.
        map_alias = map;
        (*(s32 *) ((s8 *) (map_alias) + (0x68))) = heap_alloc((count & 0xFF) * 0x58, count);
    }
}

void gcmapsects_entrypoint_11(void *unk_0, s32 unk_1)
{
    u8 *map;
    map = func_800BF704();
    map[0x79] = (s8) unk_0;
    map[0x7D] = (s8) unk_1;
}

void gcmapsects_entrypoint_12(s32 unk_0)
{
    *(s32 *) ((char *) func_800BF704() + 0x6C) = unk_0;
}

void gcmapsects_entrypoint_13(s32 unk_0)
{
    s32 map;

    map = func_800BF704();
    *(u8 *) (map + 0x80) = unk_0;
}

void gcmapsects_entrypoint_14(s32 unk_0)
{
    s8 *map = func_800BF704();
    map[0x81] = (s8) unk_0;
}

// Init; only the Jolly Roger's Lagoon maps (0x1A7-0x1A9) set up sections.
void gcmapsects_entrypoint_15(MapSectorManager1358 *map)
{
    s32 i;
    s32 map_id;

    map->local_0 = NULL;
    map->local_5 = 0;
    map->local_4 = 0;
    map->local_6 = 0;
    map->local_10 = 0;
    map->local_9 = 1;
    map->local_12 = 1;
    map->local_8 = 1;
    map->local_13 = 3;
    map->local_3 = -1;
    map->local_16 = 0;
    map->local_1 = 0;
    map->local_7 = 0;
    map->local_11 = 0;
    map->local_14 = 0;
    map->local_15 = 0;
    map->local_2 = 0.0f;
    map_id = func_800EA05C();
    switch (map_id) {
        case 0x1A7:
            _gcmapsects_lagoontop_entrypoint_0();
            map->local_17 = 1;
            break;
        case 0x1A8:
            _gcmapsects_lagoonmid_entrypoint_0();
            map->local_17 = 1;
            break;
        case 0x1A9:
            _gcmapsects_lagoonbot_entrypoint_0();
            map->local_17 = 1;
    }
    if (map->local_5) {
        func_80801724_gcmapsects(map, 1);
    }
    for (i = 0; i < map->local_5; i++) {
        map->local_0[i].local_0 = 0;
        map->local_0[i].local_1 = 1;
        map->local_0[i].local_3 = map->local_0[i].local_2;
        map->local_0[i].local_2 = map->local_17;
    }
    func_80800A08_gcmapsects(map, map->local_17);
}

// Frees all sections.
void gcmapsects_entrypoint_16(u8 *map)
{
    if (map[0x77] || map[0x76]) {
        func_80800C54_gcmapsects(map);
        heap_free(*(void **) (map + 0x68));
        *(void **) (map + 0x68) = NULL;
        map[0x77] = 0;
        map[0x76] = 0;
        map[0x78] = 0;
        map[0x7B] = 1;
        map[0x7E] = 1;
        map[0x7C] = 0;
        map[0x7F] = 3;
        *(f32 *) (map + 0x70) = 0.0f;

}
}

void gcmapsects_entrypoint_17(u8 *map)
{
    s8 *map_alias;
    func_80801640_gcmapsects();
    // Matching: the alias of the parameter is needed for the match.
    map_alias = (s8 *) map;
    if (*(u8 *) ((s8 *) map + 0x7A) != *(u8 *) ((s8 *) map + 0x7B)) {
        if (*(u8 *) ((s8 *) map + 0x7B) != 0) {
            func_800BFF4C();
        }

else
{
    func_800BFF28();
}
*((u8 *) (((s8 *) map) + 0x7A)) = (u8) (*((u8 *) (((s8 *) map) + 0x7B)));

}
func_800BF4DC(1, *(u8 *) (map_alias + 0x7E), map);
}

// Draws the opaque section models.
void gcmapsects_entrypoint_18(MapSectionRenderList *map, s32 unk_0)
{
    s32 i;
    void *model;
    void *model_data;
    s32 model_id;
    u8 unk_1;

    for (i = 0; i < map->local_1; i++) {
        if (!map->local_0[i].local_3) {
            continue;
        }

model_id = map->local_0[i].local_0;

if (!model_id) {
    continue;
}

model = func_800D674C(model_id);

if (!model) {
    continue;
}

model_data = func_800B2840(model);
func_800BF774();
func_800DF830(1);
unk_1 = func_800D731C(model_id);

if (unk_1) {
    func_800DF7E8(unk_1);
}

func_800DF7DC(map->local_0[i].local_2);
func_800DF818(model_data);
func_800DF440(0);
func_800DF428(29999.0f);
func_800DF4B0(2);

if (!func_800DE448(&map->local_0[i], 0, 1.0f, 0, model)) {
    func_800D62E4(map->local_0[i].local_0);
}

}
}

// Draws the translucent section models.
void gcmapsects_entrypoint_19(MapSectsData *map, s32 unk_0)
{
    s32 i;
    s32 model;
    s32 model_data;
    u16 model_id;

    for (i = 0; i < map->count; i++) {
        if (!map->sects[i].unk4C_31) {
            continue;
        }

model_id = map->sects[i].model;

if (!model_id) {
    continue;
}

model = func_800D674C(model_id);

if (model == 0) {
    continue;
}

model_data = func_800B2840(model);
func_800BF774();
func_800DF830(2);
func_800DF440(0);
func_800DF428(29999.0f);
func_800DF7DC(map->sects[i].unk48);
func_800DF818(model_data);
func_800DF4B0(2);

if (!func_800DE448(&map->sects[i], 0, 1.0f, 0, model)) {
    func_800D62E4(map->sects[i].model);
}

}
}

s32 gcmapsects_entrypoint_20(MapSectionRenderList *map, void *unk_0, void *unk_1,
                             s32 unk_2, s32 unk_3, f32 unk_4)
{
    void *model;
    void *geo;
    s32 i;

    for (i = 0; i < map->local_1; i++) {
        if (map->local_0[i].local_1) {
            model = func_800D674C(map->local_0[i].local_0);
            geo = func_800B2720(model);
            return func_800AD2C8(geo, func_800B2840(model), unk_0, unk_1,
                                 &map->local_0[i], unk_2, unk_3, unk_4);
        }

}
return 0;
}

int gcmapsects_entrypoint_21(u8 *map, f32 *unk_0, f32 *unk_1, void *unk_2, f32 unk_3)
{
    s32 model;
    s32 geo;
    int count;
    int i;
    u8 *sect;
    int offset;

    count = map[0x77];
    i = 0;
    offset = 0;
    if (count > 0) {
        sect = *(u8 **) (map + 0x68);
        do {
            if (((MapSectCollisionQueryFlags *) (sect + 0x4C))->local_0) {
                model = func_800D674C(*(u16 *) (sect + 0x40));
                geo = func_800B2720(model);
                return func_800AD894(geo, func_800B2840(model), unk_0, unk_1, unk_2,
                                     (f32 *) (*(u8 **) (map + 0x68) + offset), unk_3);
            }
            i++;
            offset += 0x58;
            sect += 0x58;
        } while (i < map[0x77]);
    }
    return 0;
}

s32 gcmapsects_entrypoint_22(u8 *map, void *unk_0, void *unk_1, void *unk_2, s32 flags)
{
    s32 result;
    s32 i;
    s32 offset;
    u8 *sect;
    void *model;
    void *geo;
    void *trans_geo;

    result = 0;
    if (map[0x77] == 0) {
        return 0;
    }
    func_800BEB58(0);
    i = 0;
    if (i < map[0x77]) {
        offset = 0;
        do {
            sect = *(u8 **) (map + 0x68) + offset;
            if (((MapSectFlags *) sect)->local_0) {
                model = func_800D674C(*(u16 *) (sect + 0x40));
                if (model) {
                    func_800D62E4(*(u16 *) (*(u8 **) (map + 0x68) + offset + 0x40));
                    if ((flags & 0x1F00) == 0x1F00) {
                        result = 0;
                    } else {
                        geo = func_800B2720(model);
                        result = func_800AB868(geo, (void *) func_800B2840(model),
                                                *(u8 **) (map + 0x68) + offset, 0, 1.0f,
                                                unk_0, unk_1, unk_2, flags);
                    }
                    if (result) {
                        func_800BEB58(model);
                        return result;
                    }
                    if (*(u16 *) (*(u8 **) (map + 0x68) + offset + 0x42)) {
                        model =
                            func_800D674C(*(u16 *) (*(u8 **) (map + 0x68) + offset + 0x42));
                        func_800D62E4(*(u16 *) (*(u8 **) (map + 0x68) + offset + 0x42));
                        trans_geo = func_800B2720(model);
                        if (trans_geo) {
                            result = func_800AB868(trans_geo, func_800B2840(model),
                                                    *(u8 **) (map + 0x68) + offset, 0, 1.0f,
                                                    unk_0, unk_1, unk_2, flags);
                        }
                    }
                }
            }
            i++;
            offset += 0x58;
        } while (i < map[0x77]);
    }
    return result;
}

s32 gcmapsects_entrypoint_23(u8 *map, s32 unk_0, s32 unk_1, f32 unk_2, s32 unk_3,
                             s32 unk_4, s32 unk_5)
{
    s32 offset;
    s32 geo;
    void *model;
    s32 result;
    s32 i;
    u8 *sect;
    result = 0;
    if (map[0x77] == 0)
        return 0;
    func_800BEB58(0);
    for (i = 0, offset = 0; i < map[0x77]; i++, offset += 0x58) {
        sect = *(u8 **) (map + 0x68) + offset;

if (((MapSection1864 *) sect)->local_0) {
    model = (void *) func_800D674C(*(u16 *) (sect + 0x40));
    if (model) {
        func_800D62E4(*(u16 *) (*(u8 **) (map + 0x68) + offset + 0x40));
        geo = func_800B2720(model);
        result =
            func_800AC848(geo, func_800B2840(model), *(u8 **) (map + 0x68) + offset, 0,
                          1.0f, unk_0, unk_1, unk_2, unk_3, unk_4, unk_5);
        if (result) {
            func_800BEB58(model);
            return result;
        }
    }
}

}
return result;
}

s32 gcmapsects_entrypoint_24(u8 *map)
{
    s32 ready;
    s8 *map_alias;
    // Matching: the alias of the parameter is needed for the match.
    map_alias = (s8 *) map;
    ready = (*((u8 *) (map_alias + 0x82))) != 0;
    if (ready != 0) {
        return ((*((s16 *) (((s8 *) map) + 0x74))) + 1) == 0;
    }
}

// Collision query against one section's opaque model, then its translucent model
int gcmapsects_entrypoint_25(u8 *state, u32 section_idx, s32 arg2, s32 arg3, s32 arg4,
                             u32 mask)
{
    s32 hit;
    s32 model;
    s32 offset;
    hit = 0;
    if (!state[0x77])
        return 0;
    func_800BEB58(0);
    offset = section_idx * 0x58;
    model = func_800D674C(*(u16 *) (*(u8 **) (state + 0x68) + offset + 0x40));
    // Matching: empty block steers IDO's code generation.
    if (1) {
    }
    if (model) {
        func_800D62E4(*(u16 *) (*(u8 **) (state + 0x68) + offset + 0x40));

if ((mask & 0x1F00) != 0x1F00) {
    hit = func_800AB868(func_800B2720(model), func_800B2840(model),
                            *(u8 **) (state + 0x68) + offset, 0, 1.0f, arg2, arg3, arg4,
                            mask);
}

if (hit)
    func_800BEB58(model);

else if (*(u16 *) (*(u8 **) (state + 0x68) + offset + 0x42))
{
    model = func_800D674C(*(u16 *) (*(u8 **) (state + 0x68) + offset + 0x42));
    func_800D62E4(*(u16 *) (*(u8 **) (state + 0x68) + offset + 0x42));
    if (func_800B2720(model))
        hit = func_800AB868(func_800B2720(model), func_800B2840(model),
                                *(u8 **) (state + 0x68) + offset, 0, 1.0f, arg2, arg3,
                                arg4, mask);
}

}
return hit;
}

s32 gcmapsects_entrypoint_26(MapSectionRenderList *sections, s32 arg1, f32 arg2, s32 arg3,
                             s32 arg4)
{
    void *model;
    s32 hit;
    s32 i;
    void *geo;

    hit = 0;
    if (sections->local_1 == 0) {
        return 0;

}
func_800BEB58(0);
for (i = 0; i < sections->local_1; i++) {
    if (sections->local_0[i].local_1) {
        model = func_800D674C(sections->local_0[i].local_0);
        if (model) {
            func_800D62E4(sections->local_0[i].local_0);
            geo = func_800B2720(model);
            hit = func_800AD1AC(geo, func_800B2840(model), &sections->local_0[i], 0,
                                    1.0f, arg1, arg2, arg3, arg4);
            if (hit) {
                func_800BEB58(model);
                return hit;
            }
        }
    }

}
return hit;
}

s32 gcmapsects_entrypoint_27(s32 section_idx)
{
    u8 *state;
    s32 offset;

    state = func_800BF704();
    if ((*(u8 *) ((s8 *) (state) + (0x77))) == 0) {
        return 0;

}
offset = section_idx * 0x58;
if (((u32) *(u32 *) ((s8 *) (*(s32 *) ((s8 *) state + 0x68) + offset) + 0x4C) >> 0x1F) != 0) {
    if (func_800D6B0C(*(u16 *) ((s8 *) (*(s32 *) ((s8 *) state + 0x68) + offset) + 0x40),
                      state) != 0) {
        func_800D62E4(*(u16 *) ((s8 *) (*(s32 *) ((s8 *) state + 0x68) + offset) + 0x40));
        return 1;
    }

}
return 0;
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
f32 D_808029B0_gcmapsects[3] = {5e+01f, 5e+01f, 5e+01f};
