// Storage manager of the camera node database: allocates and frees the header (8 per-kind node
// arrays), inserts nodes at a slot with re-indexing and gives them per-kind default fields.
#include "common.h"

typedef struct {
    s32 counts[8];
    s16 handles[8];
    u8 pad_30[8];
    s32 slot_count;
    u8 pad_3C[4];
} CameraDatabase;
extern void *heap_alloc(s32);
extern Vec3f D_80800630_cadbmgrDll[];
extern void _cadbfunc_entrypoint_7(f32, f32);
extern void _cadbfunc_entrypoint_9(f32, f32);
extern void _cadbfunc_entrypoint_11(f32);
extern void _cadbfunc_entrypoint_13(f32);
extern void _cadbfunc_entrypoint_15(f32);
extern void _cadbfunc_entrypoint_19(f32);
extern void _cadbfunc_entrypoint_21(f32);
extern void _cadbfunc_entrypoint_33(f32);
extern s32 func_800A57EC(s32);
typedef struct CameraDbManager {
    s32 counts[8];
    s16 handles[8];
    s32 unk_30;
    s32 unk_34;
} CameraDbManager;
extern void func_8001B754();
extern s32 func_8001B798();
extern void *rare_memcpy(void *dest, const void *src, u32 n);
s32 func_808003D8_cadbmgrDll();
s32 func_808004C4_cadbmgrDll();
int func_80800528_cadbmgrDll();
void func_808005AC_cadbmgrDll();

void cadbmgrDll_entrypoint_0(CameraDatabase **db, s32 num_slots)
{
    s32 i;

    *db = heap_alloc(num_slots * 2 + 0x40);
    for (i = 1; i <= 8; i++) {
        (*db)->handles[i - 1] = 0;
        (*db)->counts[i - 1] = 0;
    }
    (*db)->slot_count = num_slots;
    func_800A56A4();
}

int cadbmgrDll_entrypoint_1(void *db_ptr)
{
    void **db;
    db = db_ptr;
    func_800A56A4();
    heap_free(*db);
    *db = 0;
}

// Set default camera parameters for the node in slot; some depend on its kind.
void func_808000F4_cadbmgrDll(s32 slot)
{
    Vec3f zero_vec = *(Vec3f *) D_80800630_cadbmgrDll;
    s32 kind;

    kind = func_800A5854(slot);
    func_800A5800(slot);
    if (kind == 1 || kind == 2 || kind == 3 || kind == 5) {
        func_800E3980(zero_vec.f);
        _cadbfunc_entrypoint_1(zero_vec.f);
        func_800E3A58(zero_vec.f);
        _cadbfunc_entrypoint_3(zero_vec.f);
    } else {
        _cadbfunc_entrypoint_1(zero_vec.f);
        _cadbfunc_entrypoint_3(zero_vec.f);
    }
    _cadbfunc_entrypoint_5(zero_vec.f);
    _cadbfunc_entrypoint_7(1.75f, 3.75f);
    _cadbfunc_entrypoint_9(2.75f, 12.0f);
    _cadbfunc_entrypoint_11(150.0f);
    _cadbfunc_entrypoint_13(40.0f);
    _cadbfunc_entrypoint_15(1.0f);
    _cadbfunc_entrypoint_17(-1);
    _cadbfunc_entrypoint_19(1000.0f);
    _cadbfunc_entrypoint_21(1000.0f);
    _cadbfunc_entrypoint_25(0);
    _cadbfunc_entrypoint_27(0);
    _cadbfunc_entrypoint_23(0);
    _cadbfunc_entrypoint_31(0);
    _cadbfunc_entrypoint_33(0.0f);
    _cadbfunc_entrypoint_35(0);
    switch (kind) {
        case 4:
            _cadbfunc_entrypoint_27(0);
            _cadbfunc_entrypoint_23(10);
            break;
        case 1:
            _cadbfunc_entrypoint_28(2, 1);
            break;
        case 7:
            _cadbfunc_entrypoint_25(1);
    }
}

// Insert a node of the given kind at slot and re-index later nodes of that kind.
int cadbmgrDll_entrypoint_2(s32 *db, s32 kind, s32 slot)
{
    s32 node_index;
    s32 i;

    if (((u8 *) db)[0x3C + slot * 2])
        return 0;
    node_index = func_808004C4_cadbmgrDll(db, kind, slot);
    for (i = 0; i < db[14]; i++) {
        if (((u8 *) db)[0x3C + i * 2] == kind &&
            ((u8 *) db)[0x3D + i * 2] >= node_index) {
            ((u8 *) db)[0x3D + i * 2]++;
        }
    }
    ((u8 *) db)[0x3C + slot * 2] = kind;
    ((u8 *) db)[0x3D + slot * 2] = node_index;
    func_808003D8_cadbmgrDll(db, kind, db[kind - 1] + 1);
    if (db[kind - 1] - 1 > node_index)
        func_80800528_cadbmgrDll(db, kind, node_index);
    func_808000F4_cadbmgrDll(slot);
    return 1;
}

// Resize the node buffer of a kind to count entries (0 frees it).
s32 func_808003D8_cadbmgrDll(db, kind, count)
CameraDbManager *db;
s32 kind;
s32 count;
{
    if (count != 0) {
        if (db->counts[kind - 1] != 0) {
            func_8001B710(db->handles[kind - 1], func_800A57EC(kind) * count);
        } else {
            db->handles[kind - 1] = func_8001B668(0, func_800A57EC(kind));
        }
    } else {
        if (db->counts[kind - 1] != 0) {
            func_8001B754(db->handles[kind - 1]);
            db->handles[kind - 1] = 0;
        }
    }
    db->counts[kind - 1] = count;
    db->unk_30 = -1;
    db->unk_34 = 0;
    return 1;
}

s32 func_808004C4_cadbmgrDll(db, kind, slot)
s32 *db;
s32 kind;
u32 slot;
{
    s32 i;
    s32 index;
    u8 entry_index;
    u8 *entry;

    i = db[14] - 1;
    index = db[kind - 1];

if (i >= 0) {
    entry = (u8 *) db + (i * 2);
    do {
        if ((kind == *(u8 *) ((char *) entry + 0x3C)) && ((s32) slot < i)) {
            entry_index = *(u8 *) ((char *) entry + 0x3D);
            if (index >= (s32) entry_index) {
                index = (s32) entry_index;
            }
        }
        i -= 1;
        entry -= 2;
    } while (i >= 0);
}

return index;
}

// Shift the nodes of a kind above index up by one entry.
int func_80800528_cadbmgrDll(db, kind, index)
s32 db[4];
s32 kind;
s32 index;
{
    s32 kind_arg;
    unsigned long long one;
    s32 dst;
    s32 src;
    s32 offset;
    // Matching: the u64 temporary, inline assignment and comma expression are needed for the match.
    one = 1;
    dst = one;
    dst = (*((s32 *) (((s8 *) (&db[kind])) + (offset = -4)))) - dst;

if (index < dst) {
    do {
        src = dst - one;
        kind_arg = (0, kind);
        func_808005AC_cadbmgrDll(db, kind_arg, src, dst);
        dst = src;
    } while (index < dst);
}

}

// Copy one node entry of a kind from src to dst.
void func_808005AC_cadbmgrDll(db, kind, src, dst) s32 db;
s32 kind;
s32 src;
s32 dst;
{
    s32 stride;
    int base;
    stride = func_800A57EC(kind);
    base = func_8001B798(*((s16 *) (((s8 *) (db + ((kind * 2) & 0xFFFFFFFFu))) + 0x1E)));
    rare_memcpy(base + (dst * stride), base + (src * stride), stride);
}

Vec3f D_80800630_cadbmgrDll[1] = {0.0f, 0.0f, 0.0f};

// TU-NOTE: overlay .data is defined here in C (values taken from the ROM); D_80800630_cadbmgrDll is declared as Vec3f[].
