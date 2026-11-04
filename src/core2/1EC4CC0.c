// Probably the prop/marker layer on top of the cube prop lists: a pool of 200 markers, per-layer
// distance-sorted draw lists and a nearest-prop search.
#include "common.h"

typedef struct {
    s32 pad;
    s16 pos[3];
} MarkerEB;
typedef struct {
    MarkerEB *prop;
    s32 dist_sq;
} EntryEB;
extern void *vector_new(s32, s32);
extern void *vector_push_back(void **);
extern EntryEB *vector_begin(void *);
extern EntryEB *vector_end(void *);
extern void _gspropprop_entrypoint_3(void *param_0, s32 param_1, void *param_2);
typedef struct {
    u8 pad[0x28];
    u32 pad2 : 23;
    u32 layer_mask : 8;
    u32 pad3 : 1;
} ObjectEB5E0;
typedef struct {
    ObjectEB5E0 *object;
    s32 pad;
    u32 pad2 : 27;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad3 : 1;
    u32 local_3 : 1;
    u32 has_object : 1;
} EntryEB5E0;
extern void func_800E3A30(f32 *);
extern void _gspropprop_entrypoint_2(EntryEB5E0 *);
typedef struct {
    void *lists[7];
    s16 cur_layer;
} G_EB70C;
// TU-NOTE: D_80132E80 holds the 7 per-layer draw lists (vectors). D_80132E9C is the
// address of its last field (cur_layer), which is read as an s16 and also serves as
// the end marker of the list array.
G_EB70C D_80132E80;
extern void vector_free(void *vec);
extern void *D_80132E9C;
extern void vector_clear(void *vec);
extern s32 D_80132EC0;
typedef struct {
    s32 pad;
    s16 pos_xy[2];
    union {
        struct {
            s16 z;
            u16 pad;
        } zpos;
        struct {
            u32 pad : 30;
            u32 local_0 : 1;
            u32 local_1 : 1;
        } bits;
    } u;
} EntryEB8C0;
typedef struct {
    s16 pos[3];
    u8 pad[14];
} PropEB8C0;
typedef struct {
    s32 pos[3];
    s32 best_dist_sq, kind;
    void *best_cube, *best_entry;
    s32 best_kind;
    s32 (*callback)(PropEB8C0 *, void *);
    void *callback_data;
} SearchEB8C0;
extern SearchEB8C0 D_80132EA0;
extern s32 func_800E9DCC(void *);
extern s32 func_800E9DC4(void *);
extern EntryEB8C0 *func_800E9E88(void *);
extern EntryEB8C0 *func_800E9EB4(void *);
extern PropEB8C0 *func_800E9D68(void *);
extern PropEB8C0 *func_800E9D90(void *);
extern s32 D_80123540[];
extern s32 D_8013546C;
typedef struct {
    u8 pad0[0x12];
    u16 unk12;
    u8 pad14[0x1C];
} Sub_EBB94;
typedef struct {
    Sub_EBB94 sub[4];
} E_EBB94;
typedef struct {
    E_EBB94 arr[50];
    u8 flags[25];
} G_EBB94;
typedef struct MarkerEntry MarkerEntry;
typedef struct {
    MarkerEntry *entry;
    u8 pad_4[0x18];
    s16 cube_id;
} MarkerRef;
extern MarkerEntry *func_800E99E0(void);
extern s32 func_800DC214(s32, s32, s32 *);
extern s32 func_800BD948(void *);
// TU-NOTE: D_80132ED0 is the marker pool: 200 markers of 0x30 bytes (0x2580 bytes), a
// 25-byte allocation bitmap at +0x2580 and the running marker id at +0x259C.
extern u8 D_80132ED0[];
extern u8 D_80135450;
extern u8 D_80123554[];
typedef struct {
    u8 pad_0[8];
    void (*draw_cb)(void);
    u8 pad_C[6];
    u16 id : 15;
    u16 field_13 : 1;
    u8 pad_14[0x10];
    u32 field_24 : 10;
    u32 pad_24 : 22;
    u32 pad_28 : 22;
    u32 field_2A : 1;
    u32 pad_2B : 9;
    u32 pad_2C;
} MarkerCreate;
typedef struct {
    u8 pad_0[0x10];
    u32 flags;
    u8 pad_14[8];
    s16 cube_id;
    u8 pad_1E[10];
    u32 pad_28 : 21;
    u32 field_28 : 1;
    u32 pad_29 : 10;
} MarkerMove;
extern s32 func_800BD97C(s32 *);
extern void func_800CDFD0(MarkerMove *);
typedef struct {
    u8 pad[0x24];
    u32 pad1 : 16;
    u32 local_0 : 9;
    u32 pad2 : 7;
    u32 local_1 : 9;
    u32 local_2 : 9;
    u32 pad3 : 14;
} MarkerEC124;
extern f32 func_800136E4(f32);
typedef struct {
    u8 pad0[0x14];
    u16 unk14;
    u16 pad16;
    u16 unk18;
} S_EC428;
typedef struct {
    u8 pad0[0x14];
    u16 unk14;
    u8 pad16[0xA];
    s16 unk20;
} S_EC48C;
extern s32 func_800B0CFC(void *);
typedef struct {
    u8 pad[0x18];
    u32 radius : 11;
    u32 pad_1 : 4;
    u32 has_object : 1;
    u32 pad_2 : 16;
} EntryEC5C0;
typedef struct {
    u8 pad0[8];
    u32 f0 : 30;
    u32 bit : 1;
    u32 f2 : 1;
} S_EC708;
int func_800EC7D4();
s32 func_800EC800();
s32 func_800EC854();

// Per-frame prop draw ordering: distance-sorted draw lists for 7 layers, and their drawing.
// Inserts the prop into the distance-sorted draw list of the given layer.
void func_800EB3D0(MarkerEB *prop, s32 layer, s16 *ref_pos)
{
    s32 dx, dy, dz;
    EntryEB *slot, *begin, *last;
    void *list;
    if (!D_80132E80.lists[layer])
        D_80132E80.lists[layer] = vector_new(8, 5);
    vector_push_back(&D_80132E80.lists[layer]);
    dx = prop->pos[0] - ref_pos[0];
    dy = prop->pos[1] - ref_pos[1];
    dz = prop->pos[2] - ref_pos[2];
    dx = dx * dx + dy * dy + dz * dz;
    list = D_80132E80.lists[layer];
    begin = vector_begin(list);
    last = vector_end(list) - 1;
    slot = last - 1;
    while (slot >= begin) {
        if (dx < slot->dist_sq)
            break;
        slot--;
    }
    slot++;
    if (slot < last)
        aligned4_memmove(slot + 1, slot, (last - slot) * sizeof(EntryEB));
    slot->dist_sq = dx;
    slot->prop = prop;
}

// Draws every entry of the given layer's list.
void func_800EB51C(s32 layer, s32 param_1)
{
    // Matching: stack padding needed for the match.
    s8 _sfpad[8];
    void *begin;
    void *list;
    void *end;
    u8 *cur;
    void *entry;
    list = D_80132E80.lists[layer];
    if (list != 0) {
        begin = vector_begin(list);
        end = vector_end(list);
        if (end != begin) {
            *(s16 *) &D_80132E9C = (s16) layer;
            cur = (u8 *) begin;
            if (begin < end) {
                do {
                    entry = *(void **) cur;
                    if (*(s32 *) ((u8 *) *(void **) cur + 8) & 1) {
                        // Matching: the extra block and `^ 0` are needed for the match.
                        {
                            func_800EC7D4(*(s32 *) *(void **) cur, param_1 ^ 0,
                                          *(void **) cur);
                        }
                    } else {
                        _gspropprop_entrypoint_3(entry, param_1, *(void **) cur);
                    }
                    cur += 8;
                } while (cur < (u8 *) end);
            }
        }
    }
}

// Collects the props of one cube into the per-layer draw lists.
void func_800EB5E0(s32 cube, s32 layer)
{
    EntryEB5E0 *entry;
    f32 ref_pos[3];
    EntryEB5E0 *end;
    ObjectEB5E0 *object;
    func_800E3A30(ref_pos);
    entry = func_800E9E88(cube);
    end = func_800E9EB4(cube);
    for (; entry < end; entry++) {
        if (entry->local_1) {
            if (!entry->local_3)
                _gspropprop_entrypoint_2(entry);
            if (entry->has_object) {
                object = entry->object;
                if (func_800EC800(object)) {
                    for (layer = 0; layer < 7; layer++) {
                        if (object->layer_mask & (1 << layer))
                            func_800EB3D0(entry, layer, ref_pos);
                    }
                }
            } else
                func_800EB3D0(entry, entry->local_2 ? 1 : 0, ref_pos);
        }
    }
}

// Resets the 7 draw lists.
void func_800EB70C(void)
{
    s32 i;
    D_80132E80.cur_layer = -1;
    for (i = 0; i < 7; i++) {
        D_80132E80.lists[i] = 0;
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_800EB750()
{
    void **slot = D_80132E80.lists;
    slot = slot; do { void *list; do { list = *slot; if (0 != list) { vector_free(list); *slot = 0; } slot += 1; } while (slot != &D_80132E9C); } while (0); // Matching: self-assignment and do-while(0) wrapper needed for the match.
}

// Matching: the line breaks in this function are needed for the match.
void func_800EB7A8(void)
{
    s32 *cur;
    s32 list;
    cur = (s32 *) &D_80132E80; do {
        list = *cur;
        if (list != 0)
        {
            *cur = vector_defrag(list);
        }
        cur += 1;
    }
    while (cur != (s32 *) &D_80132E9C);
}

// Matching: the line breaks in this function are needed for the match.
void func_800EB800()
{
    void **slot = D_80132E80.lists;
    slot = slot; do { void *list; do { list = *slot; if (0 != list) { vector_clear(list); } slot += 1; } while (slot != &D_80132E9C); } while (0); // Matching: self-assignment and do-while(0) wrapper needed for the match.
}

int func_800EB854()
{
    return *(s16 *) &D_80132E9C;
}

// Nearest-prop query over the cube prop lists (state in D_80132EA0).
// Sets the filter callback (and its argument) of the nearest-prop search.
void func_800EB860(s32 callback, s32 callback_data)
{
    *(s32 *) ((char *) (s32 *) &D_80132EA0 + 0x20) = callback;
    *(s32 *) ((char *) (s32 *) &D_80132EA0 + 0x24) = callback_data;
}

void func_800EB874()
{
    D_80132EC0 = 0;
}

// Starts a nearest-prop search around pos.
int func_800EB880(OSViCommonRegs *pos, s32 kind, u32 radius)
{
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 0x0) = *(u32 *) ((char *) pos + 0x0);
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 4) = *(u32 *) ((char *) pos + 0x4);
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 8) = *(u32 *) ((char *) pos + 0x8);
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 0xC) = radius * radius;
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 0x10) = kind;
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 0x14) = 0;
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 0x18) = 0;
    *(u32 *) ((char *) (u32 *) &D_80132EA0 + 0x1C) = 0;
}

// Checks one cube's markers and props against the current nearest-prop search.
void func_800EB8C0(void *cube)
{
    EntryEB8C0 *marker, *markers_end;
    PropEB8C0 *prop, *props_end;
    s32 dist_sq;
    if (func_800E9DCC(cube) && (D_80132EA0.kind == 1 || D_80132EA0.kind == 2)) {
        marker = func_800E9E88(cube);
        markers_end = func_800E9EB4(cube);
        for (; marker < markers_end; marker++) {
            if (marker->u.bits.local_1)
                continue;
            dist_sq = (marker->pos_xy[0] - D_80132EA0.pos[0]) *
                          (marker->pos_xy[0] - D_80132EA0.pos[0]) +
                      (marker->pos_xy[1] - D_80132EA0.pos[1]) *
                          (marker->pos_xy[1] - D_80132EA0.pos[1]) +
                      (marker->u.zpos.z - D_80132EA0.pos[2]) *
                          (marker->u.zpos.z - D_80132EA0.pos[2]);
            if (dist_sq < D_80132EA0.best_dist_sq &&
                (marker->u.bits.local_0 ? 2 : 1) == D_80132EA0.kind) {
                D_80132EA0.best_dist_sq = dist_sq;
                D_80132EA0.best_cube = cube;
                D_80132EA0.best_entry = marker;
                D_80132EA0.best_kind = D_80132EA0.kind;
            }
        }
    }
    if (func_800E9DC4(cube) && D_80132EA0.kind == 3) {
        prop = func_800E9D68(cube);
        props_end = func_800E9D90(cube);
        for (; prop < props_end; prop++) {
            if ((prop->pos[0] - D_80132EA0.pos[0]) *
                            (prop->pos[0] - D_80132EA0.pos[0]) +
                        (prop->pos[1] - D_80132EA0.pos[1]) *
                            (prop->pos[1] - D_80132EA0.pos[1]) +
                        (prop->pos[2] - D_80132EA0.pos[2]) *
                            (prop->pos[2] - D_80132EA0.pos[2]) <
                    D_80132EA0.best_dist_sq &&
                (!D_80132EA0.callback || D_80132EA0.callback(prop, D_80132EA0.callback_data))) {
                D_80132EA0.best_dist_sq = (prop->pos[0] - D_80132EA0.pos[0]) *
                                         (prop->pos[0] - D_80132EA0.pos[0]) +
                                     (prop->pos[1] - D_80132EA0.pos[1]) *
                                         (prop->pos[1] - D_80132EA0.pos[1]) +
                                     (prop->pos[2] - D_80132EA0.pos[2]) *
                                         (prop->pos[2] - D_80132EA0.pos[2]);
                D_80132EA0.best_cube = cube;
                D_80132EA0.best_entry = prop;
                D_80132EA0.best_kind = D_80132EA0.kind;
            }
        }
    }
}

// Returns the best result of the search; cube and entry via the out parameters.
int func_800EBB30(s32 *cube_out, s32 *entry_out)
{
    *cube_out = ((s32 *) &D_80132EA0)[5];
    *entry_out = ((s32 *) &D_80132EA0)[6];
    return ((s32 *) &D_80132EA0)[7];
}

// Marker pool and API: alloc/free, create, move between cubes, accessors and draw callback.
int func_800EBB50()
{
    return (int) D_80123540;
}

// Resets the running marker id.
void func_800EBB5C()
{
    D_8013546C = 0x6B7;
}

void func_800EBB6C(void)
{
}

int func_800EBB74()
{
    return (u8 *) D_80132ED0 ? 1 : 0;
}

// Frees all markers: clears the allocation bitmap and the marker ids.
void func_800EBB94(void)
{
    s32 i;
    s32 j;
    for (i = 0; i < 25; i++) {
        (*(G_EBB94 *) D_80132ED0).flags[i] = 0;
    }
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 4; j++) {
            (*(G_EBB94 *) D_80132ED0).arr[i].sub[j].unk12 &= 1;
        }
    }
}

void func_800EBC04(void)
{
}

struct MarkerEntry {
    MarkerRef *marker;
    s16 pos[3];
    u16 field_A : 5;
    u16 room : 5;
    u16 field_B5 : 1;
    u16 pad_B : 3;
    u16 field_B1 : 1;
};

// Adds a cube entry for the marker and links both ways.
void func_800EBC0C(void *cube, s32 *pos, MarkerRef *marker, s32 param_3)
{
    MarkerEntry *entry;
    entry = func_800E99E0();
    entry->pos[0] = pos[0];
    entry->pos[1] = pos[1];
    entry->pos[2] = pos[2];
    entry->marker = marker;
    entry->field_B1 = param_3;
    entry->field_A = 0;
    entry->field_B5 = 0;
    entry->room = func_800DC214(0, 0x20, pos);
    marker->entry = entry;
    marker->cube_id = func_800BD948(cube);
}

// Moves the marker's entry from the old cube to the new one.
void func_800EBCD0(s32 *marker, s32 *pos, u32 old_cube, s32 new_cube)
{
    u8 *entry;
    s32 unk_0;
    u16 saved_bits;

    entry = *marker;
    saved_bits = *(u16 *) ((char *) entry + 0xA);
    func_800EBC0C(new_cube, pos, marker, func_800E9AC0(old_cube, entry));
    *(u16 *) ((char *) *marker + 0xA) = saved_bits;
}

void func_800EBD2C(s32 marker, s32 pos, s32 cube_id)
{
    func_800EBCD0(marker, pos, func_800BDB9C(*(s16 *) (marker + 0x1C)), func_800BDB9C(cube_id));
}

// Allocates a marker slot from the pool; returns 0 when the pool is full.
u8 *func_800EBD78(void)
{
    s32 tmp_mask;
    s32 test;
    s32 mask;
    s32 bit_idx;
    s32 byte_idx;
    s32 bits;
    u8 *bitmap_byte;
    byte_idx = 0;
    if (D_80135450 == 0xFF) {
    loop_2:
        byte_idx += 1;

        if (byte_idx < 0x19) {
            if (*(u8 *) ((D_80132ED0 + byte_idx) + 0x2580) == 0xFF) {
                goto loop_2;
            }
        }
    }
    if (byte_idx == 0x19) {
        return 0;
    }
    bitmap_byte = D_80132ED0 + byte_idx;
    bits = *(u8 *) (bitmap_byte + 0x2580);
    mask = 0x80;
    bit_idx = 0;
    if (bits & 0x80) {
        do {
            tmp_mask = (mask = mask >> 1);
            test = bits & tmp_mask;
            bit_idx += 1;
        } while (test != 0);
    }
    *(u8 *) (bitmap_byte + 0x2580) = (u8) (bits | mask);
    return (D_80132ED0 + (byte_idx * 0x180)) + (bit_idx * 0x30);
}

// Returns a marker slot to the pool.
void func_800EBE24(u8 *marker)
{
    s32 offset;
    u8 *bitmap_byte;
    s32 slot_idx;

    offset = (s32) marker - (s32) &D_80132ED0;
    *(u16 *) ((char *) marker + 0x12) = *(u16 *) ((char *) marker + 0x12) & 1;
    slot_idx = offset / 48;
    bitmap_byte = (u8 *) &D_80132ED0 + (slot_idx >> 3);
    bitmap_byte[0x2580] = bitmap_byte[0x2580] & ((u32 *) &D_80123554)[slot_idx & 7];
}

int func_800EBE74(s32 pos, s32 *marker, s32 param_2)
{
    u32 cube;
    if (marker[4] & 1) {
        cube = func_800BDC44() | 0;
    } else {
        cube = func_800BDBC4(pos) | 0;
    }
    func_800EBC0C(cube, pos, marker, param_2);
}

MarkerCreate *func_800EBED4(s32 *pos, s32 param_1, s32 param_2, s32 param_3)
{
    MarkerCreate *marker;
    marker = func_800EBD78();
    bzero(marker, 0x30);
    marker->id = func_800EC854();
    marker->field_24 = param_2;
    marker->field_13 = param_3;
    marker->draw_cb = func_800EBB50;
    marker->field_2A = 1;
    func_800EBE74(pos, marker, param_1);
    return marker;
}

int func_800EBF8C(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    f32 pos[3];
    func_800EE904(pos, param_0 | 0);
    func_800EBED4(pos, param_1, param_2, param_3);
}

s32 func_800EBFD4(s32 map, s32 exit, s32 direction)
{
    func_800EBF8C(map, exit, direction, 0);
}

// Frees the marker: removes its cube entry and returns the slot to the pool.
void func_800EBFF4(u8 *marker)
{
    func_800E9AC0(func_800BDB9C(*(s16 *) ((s8 *) marker + 0x1C)), *(s32 *) ((s8 *) marker + 0));
    func_800EBE24(marker);
}

void func_800EC030(u8 **marker, u8 *pos)
{
    *(s16 *) ((s8 *) *marker + 4) = (s16) *(s32 *) ((s8 *) pos + 0);
    *(s16 *) ((s8 *) *marker + 6) = (s16) *(s32 *) ((s8 *) pos + 4);
    *(s16 *) ((s8 *) *marker + 8) = (s16) *(s32 *) ((s8 *) pos + 8);
}

// Moves the marker to pos; re-cubes it when the cube changed.
void func_800EC058(s32 *pos, MarkerMove *marker)
{
    s32 cube_id;
    if (marker->flags & 1)
        cube_id = -1;
    else
        cube_id = func_800BD97C(pos);
    if (cube_id == marker->cube_id)
        func_800EC030(marker, pos);
    else
        func_800EBD2C(marker, pos, cube_id);
    if (marker->field_28)
        func_800CDFD0(marker);
}

int func_800EC0EC(s32 param_0, s32 marker)
{
    f32 pos[3];
    func_800EE904(pos, param_0 | 0);
    func_800EC058(pos, marker);
}

void func_800EC124(void *param_0, MarkerEC124 *marker, f32 *param_2)
{
    marker->local_0 = func_800136E4(param_2[0]);
    marker->local_1 = func_800136E4(param_2[1]);
    marker->local_2 = func_800136E4(param_2[2]);
    func_800EC0EC(param_0, marker);
}

void func_800EC340(u16 *marker, s32 value)
{
    // Matching: extra copy and `if (1)` needed for the match.
    short bits_copy;
    u16 bits = marker[13];
    bits_copy = bits;
    if (1) {
        bits = bits_copy;
        marker[13] = ((value << 3) << 2) | ((bits & 0x1F) & 0xFFFFFFFF);
    }
}

func_800EC358(s32 marker, s32 param_1)
{
    s32 value;
    value = param_1;
    ((s32 *) marker)[3] = value;
}

int func_800EC360(s32 marker, unsigned long param_1)
{
    *(s16 *) (marker + 0x14) = param_1;
}

int func_800EC368(s32 marker, int param_1)
{
    *(s16 *) ((char *) marker + 22) = param_1;
}

void func_800EC370(u8 **marker, u8 *pos_out)
{
    *(s16 *) (pos_out + 0) = *(s16 *) (*marker + 4);
    *(s16 *) (pos_out + 2) = *(s16 *) (*marker + 6);
    *(s16 *) (pos_out + 4) = *(s16 *) (*marker + 8);
}

void func_800EC398(s32 *marker, s32 out)
{
    func_800EE88C(out, *(s32 *) (marker + 0) + 0x4);
}

// Calls the callback stored in the marker.
void func_800EC3C4(u8 *marker)
{
    (*(s32(**)())((s8 *) marker + 8))();
}

int func_800EC3E8(Actor *marker)
{
    if ((*(u16 *) ((char *) marker + 0x14) == 0) ||
        (*(u16 *) ((char *) marker + 0x14) == 0xFFFF)) {
        return 0;
    }
    {
        return func_800D674C(*(u16 *) ((char *) marker + 0x14) | 0);
    }
}

s32 func_800EC428(S_EC428 *marker)
{
    if ((marker->unk18 & 1) != 0) {
        return func_801039E4(marker);
    }
    if ((marker->unk14 == 0) || (marker->unk14 == 0xFFFF)) {
        return 0;
    }
    return func_800D674C(marker->unk14);
}

f32 func_800EC48C(S_EC48C *marker)
{
    f32 radius;
    if ((marker->unk14 == 0) || (marker->unk14 == 0xFFFF)) {
        return 0.0f;
    }
    radius = (f32) func_800B0CFC(func_800EC3E8(marker)) * 0.5f;
    marker->unk20 = (s16) radius;
    return radius;
}

f32 func_800EC504(u8 *marker)
{
    f32 radius;
    s32 center_z;
    s32 center_y;
    s32 center_x;
    s32 model;
    s32 unk_0;

    if (*(u16 *) (marker + 0x14) == 0 || *(u16 *) (marker + 0x14) == 0xFFFF) {
        return 1.0f;
    }
    unk_0 = func_800D73CC(*(u16 *) (marker + 0x14));
    model = func_800D674C(*(u16 *) (marker + 0x14));
    if (model == 0) {
        return 1.0f;
    }
    func_800D62E4(*(u16 *) (marker + 0x14), model);
    func_800B237C(func_800B2840(model), &center_x, &radius);
    func_800EE940(marker + 0x1E, &center_x);
    if (unk_0 == 0) {
        func_800D6CEC(*(u16 *) (marker + 0x14));
    }
    return radius;
}

// Returns the marker's radius, cached in the marker and computed by calc on first use.
f32 func_800EC5C0(EntryEC5C0 **marker_ref, f32 (*calc)(EntryEC5C0 *))
{
    EntryEC5C0 *marker;
    f32 radius;
    marker = *marker_ref;
    radius = marker->radius;
    if (radius == 0.0f) {
        radius = marker->radius = calc(marker);
    }
    if (marker->has_object) {
        radius *= ((f32 *) func_80106790((Unk80132ED0 *) marker))[14];
    }
    return radius;
}

f32 func_800EC708(S_EC708 **marker_ref)
{
    S_EC708 *marker = *marker_ref;
    if (marker->bit) {
        return func_800EC5C0(marker, func_800EC504);
    } else {
        return func_800EC5C0(marker, func_800EC48C);
    }
}

f32 func_800EC75C(s32 marker, s32 param_1)
{
    f32 radius;
    f32 pos[3];
    u8 *bytes = (u8 *) marker;
    radius = func_800EC708(marker);
    func_800EE88C(param_1, bytes + 0x1e);
    if (*(u16 *) (bytes + 0x18) & 1) {
        u8 *object = func_80106790(bytes);
        func_800EF334(param_1, *(s32 *) (object + 0x38));
    }
    func_800EC398(bytes, pos);
    func_800EF04C(param_1, pos);
    return radius;
}

int func_800EC7D4(param_0, param_1)
s32 param_0;
s32 param_1;
{
    func_8010A79C(func_80106790(param_0) | 0, param_1);
}

s32 func_800EC800(marker)
u8 *marker;
{
    s32 has_object;
    has_object = (*(u16 *) ((u8 *) marker + 0x18) & 1) != 0;
    if (0 != has_object) {
        return *(u16 *) ((u8 *) marker + 0x14) != 0;
    }
}

// Steps the running marker id back, wrapping to 0x7FFF below 0x6B7.
int func_800EC828()
{
    ((int *) D_80132ED0)[0x967]--;
    if (((int *) D_80132ED0)[0x967] < 0x6B7) {
        ((int *) D_80132ED0)[0x967] = 0x7FFF;
    }
}

// Returns the next marker id; wraps from 0x8000 to 0x6B7.
s32 func_800EC854(void)
{
    s32 id;

    id = *(s32 *) ((s8 *) (s16 *) D_80132ED0 + 0x259c);
    if (++*(s32 *) ((s8 *) (s16 *) D_80132ED0 + 0x259c) >= 0x8000) {
        *(s32 *) ((s8 *) (s16 *) D_80132ED0 + 0x259c) = 0x6b7;
    }
    return id;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EC4CC0.data.s) is defined
// here in C, values taken from the ROM. D_80123540 is declared as s32[] (uses written
// as NAME[0]).
s32 D_80123540[5] = {0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_80123554[44] = {0x0,  0x0,  0x0, 0x7F, 0x0,  0x0,  0x0, 0xBF, 0x0,  0x0,  0x0,
                     0xDF, 0x0,  0x0, 0x0,  0xEF, 0x0,  0x0, 0x0,  0xF7, 0x0,  0x0,
                     0x0,  0xFB, 0x0, 0x0,  0x0,  0xFD, 0x0, 0x0,  0x0,  0xFE, 0x0,
                     0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0};
