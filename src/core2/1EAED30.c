#include "common.h"
    #include "vector.h"

    // Pending-release entry: reference count and asset pointer.
    typedef struct {s32 count, asset;} local_type;
extern Vector *D_8012B7F0;
extern void *D_8012B7F8;
extern s32 D_8012B7F4;
extern u8 D_8012B7E4;
extern u8 D_8012B7E5;
extern void *D_8012B450[];
extern u8 D_8012B658[];
extern s16 D_8012B6E0[];
extern void heap_free(void *);
extern s32 D_8011B900;

extern u32 D_8012B444;
extern s32 D_8012B448;
extern u8 D_8012B7E6;
// ROM asset table word: offset, flags (bit 0 = compressed), type.
typedef struct { u32 offset:26; u32 flags:2; u32 type:4; } AssetD5B34;
extern s32 func_800E4AF0(s32);
extern void *func_800E4BF4(s32);
extern void *_gldbDll_entrypoint_0(s32, s32 *);
extern void *func_800E6950(s32, s32, s32);
extern void *heap_alloc(s32);
extern void rom_dma_read(void *, s32, s32);
extern u8 assets_ROM_START[];
typedef struct { u32 offset:26; u32 flags:2; u32 type:4; } LocalRomEntry;
typedef union {
    AssetD5B34 AssetD5B34;
    LocalRomEntry LocalRomEntry;
    u32 raw;
} Union_D_8012B440;
extern Union_D_8012B440 D_8012B440;
extern s32 rom_read_word(u32, void *);
s32 func_800D56C4();

extern s32 D_8012B7E8;

// Queues an asset for deferred release (counts repeated requests).
void func_800D5440(asset) s32 asset; {
    local_type *entry;
    local_type *end;
    end = vector_end(D_8012B7F0);
    for (entry = vector_begin(D_8012B7F0); entry < end && asset != entry->asset; entry++) {}
    if (entry < end) entry->count++;
    else {
        entry = vector_push_back(&D_8012B7F0);
        entry->count = 1;
        entry->asset = asset;
    }
}

// Nonzero when the asset is queued for release in either vector.
int func_800D54F0(asset) s32 asset;
{
    void *vec_limit;
    void **vec;
    void *end;
    void *begin;
    s32 *it;
    vec = ((void * *) &D_8012B7F0); vec_limit = &D_8012B7F8; loop_1: end = vector_end(*vec);
    begin = vector_begin(*vec);
    it = (s32 *) begin;

if (begin < end) {
    if (asset != *(s32 *) ((char *) begin + 4)) {
    loop_3:
        it += 2;

        if (it < (s32 *) end) {
            if (asset != *(s32 *) ((char *) it + 4)) {
                goto loop_3;
            }
        }
    }
}

vec += 1;

if (it < (s32 *) end) {
    return 1;
}

if (vec == vec_limit) {
    return 0;
}

goto loop_1;
}

// Creates the two deferred-release vectors.
void func_800D55A0()
{
    D_8012B7F0 = vector_new(8, 0x10);
    D_8012B7F4 = vector_new(8, 0x10);
}

// Swaps the two release vectors and releases everything queued in the new first one.
void func_800D55DC(void)
{
    s32 i;
    u32 end;
    s32 tmp;
    s32 *it;
    tmp = ((s32 *) &D_8012B7F0)[0];
    ((s32 *) &D_8012B7F0)[0] = ((s32 *) &D_8012B7F0)[1];
    ((s32 *) &D_8012B7F0)[1] = tmp;
    end = vector_end(((s32 *) &D_8012B7F0)[0]);

    for (it = (s32 *) vector_begin(((s32 *) &D_8012B7F0)[0]); (u32) it < end; it += 2) {
        for (i = 0; i < it[0]; i++) {
            func_800D56C4(it[1]);
        }
    }

    vector_clear(((s32 *) &D_8012B7F0)[0]);
}

int func_800D5688()
{
    D_8012B7F0 = vector_defrag(((int) D_8012B7F0));
    D_8012B7F4 = vector_defrag(*((((int *) &D_8012B7F0)) + 1));
}

// Drops one reference; on the last one frees the asset and swap-removes its slot.
// Returns 0 freed, 1 still referenced, 2 not found, 3 null.
s32 func_800D56C4(asset) void *asset;
{
    s32 slot;
    u8 last;

    if (asset) {
        for (slot = 0; slot < D_8012B7E4 && asset != D_8012B450[slot]; slot++) {
        }
        if (slot == D_8012B7E4)
            return 2;
        D_8012B7E5 = slot;
        if (D_8012B658[slot] == 1) {
            heap_free(asset);
            last = D_8012B7E4 - 1;
            D_8012B7E4 = last;
            D_8012B658[slot] = D_8012B658[last];
            D_8012B450[slot] = D_8012B450[D_8012B7E4];
            D_8012B6E0[slot] = D_8012B6E0[D_8012B7E4];
            return 0;
        } else {
            D_8012B658[slot]--;
            return 1;
        }
    }

    return 3;
}

// Defragments an asset's heap block and updates its table entry if it moved.
s32 func_800D5804(s32 asset, s32 *param_1)
{
    s32 i;
    s32 slot;
    s32 moved;
    s32 *table;
    i = 0;
    table = ((s32 *) D_8012B450);

    if ((s32) D_8012B7E4 > 0) {
        if (asset != *table) {
        loop_2:
            i += 1;

if (i < (s32) D_8012B7E4) {
    if (asset != ((s32 *) D_8012B450)[i]) {
        goto loop_2;
    }
}

}
}

if (i == D_8012B7E4) {
    return asset;
}

// Matching: the copy of the index is needed for the match.
slot = i;
moved = defrag(asset);

if (moved != asset) {
    ((s32 *) D_8012B450)[slot] = moved;
}

return moved;
}

void func_800D58AC()
{
    func_800D5688();
}

int func_800D58CC()
{
    func_8001A2B0();
    func_800D55DC();
    func_800D55DC();
}

// Returns the asset type from the ROM table.
s32 func_800D58FC(s32 id)
{
    s32 id_copy;
    // Matching: the copy of the parameter is needed for the match.
    id_copy = id;
    rom_read_word(((long) D_8011B900) + (id_copy * 4), ((s32 *) &D_8012B440.raw));
    return ((s32) D_8012B440.raw) & 0xF;
}

// Number of assets in the ROM table.
s32 func_800D593C()
{
    return 0x3666;
}

// Size of the last asset that was loaded.
s32 func_800D5944()
{
    return D_8012B7E8;
}

// Size of an asset in the ROM (distance to the next table entry).
s32 func_800D5950(s32 id)
{
    rom_read_word((u32) D_8011B900 + id * 4, &D_8012B440.raw);
    rom_read_word((u32) D_8011B900 + id * 4 + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440.raw >> 6);
}

// Nonzero when the asset is compressed.
s32 func_800D59C0(s32 id)
{
    s32 *rom_table;
    // Matching: the pointer local is needed for the match.
    rom_table = &D_8011B900;
    rom_read_word((*rom_table) + (id * 4), ((s32 *) &D_8012B440.raw));
    return (((u32) (((s32) D_8012B440.raw) << 0x1A)) >> 0x1E) & 1;
}

// Nonzero when the asset is loaded.
s32 func_800D5A04(s32 id)
{
    s32 idx;

    idx = 0;

    if (((s32) D_8012B7E4 > 0) && (id != ((s16 *) D_8012B6E0)[idx])) {
    loop_2:
        idx += 1;
        if (idx < (s32) D_8012B7E4) {
            if (id != ((s16 *) D_8012B6E0)[idx]) {
                goto loop_2;
            }

}
}

if (idx < (s32) D_8012B7E4) {
    return 1;
}

return 0;
}

// ROM address of an asset's data.
s32 func_800D5A6C(s32 id)
{
    int entry_addr;
    s32 *rom_table;
    // Matching: the pointer local is needed for the match.
    rom_table = &D_8011B900;
    entry_addr = (*rom_table) + (id * 4);
    rom_read_word(entry_addr, &D_8012B440.raw);
    return D_8012B448 + (((u32) D_8012B440.raw) >> 6);
}

// Finds the slot of an asset id; -1 when slot 0x82 is reached.
s32 func_800D5AB4(unsigned int id)
{
    s16 *first;
    s32 slot;
    first = &D_8012B6E0[0];
    slot = 0;

    if (((s32) D_8012B7E4 > 0) && (id != *first)) {
        do {
            slot += 1;

if (slot < (s32) D_8012B7E4) {
    if (id != D_8012B6E0[slot]) {
        continue;
    }
}

break;
}
while (1)
    ;
}

D_8012B7E5 = slot;

if (slot == 0x82) {
    return -1;
}

return slot;
}

void func_800D5B24()
{
    D_8012B7E6 = 1;
}

// Returns the asset for an id, loading it if needed; counts a reference.
// Returns 0 when the table is full.
void *func_800D5B34(s32 id)
{
    s32 size;
    s32 idx;
    void *asset;
    s32 unk_0;
    unk_0 = D_8012B7E6;
    D_8012B7E6 = 0;
    idx = func_800D5AB4(id);
    if (idx < 0)
        return 0;

    if (idx < D_8012B7E4) {
        D_8012B658[idx]++;
        return D_8012B450[idx];
    }

    idx = id * 4;
    rom_read_word(D_8011B900 + idx, ((AssetD5B34 *) &D_8012B440.raw));
    if (!D_8012B440.AssetD5B34.type && !unk_0)
        unk_0 = 2;

    if (func_800E4AF0(id)) {
        asset = func_800E4BF4(id);
    } else if (D_8012B440.AssetD5B34.type == 10) {
        asset = _gldbDll_entrypoint_0(id, &D_8012B7E8);
    } else if (D_8012B440.AssetD5B34.flags & 1) {
        asset = func_800E6950(id, unk_0, 0);
    } else {
        rom_read_word(D_8011B900 + idx + 4, ((AssetD5B34 *) &D_8012B444));
        rom_read_word(D_8011B900 + idx, ((AssetD5B34 *) &D_8012B440.raw));
        size = (*((AssetD5B34 *) &D_8012B444)).offset - D_8012B440.AssetD5B34.offset;
        D_8012B7E8 = size;
        if (size & 1)
            size++;
        asset = heap_alloc(size);
        rom_dma_read(asset, D_8012B448 + D_8012B440.AssetD5B34.offset, size);
    }
    D_8012B7E5 = D_8012B7E4;
    D_8012B658[D_8012B7E4] = 1;
    D_8012B450[D_8012B7E4] = asset;
    D_8012B6E0[D_8012B7E4] = id;
    D_8012B7E4++;
    return asset;
}

// Initializes the asset cache; D_8012B448 becomes the asset data base in the ROM.
void func_800D5D70()
{
    long long offset;
    u8 *rom_start;
    u8 *base;
    D_8012B7E6 = 0;
    rom_start = (u8 *) assets_ROM_START;
    func_800D55A0();
    D_8012B7E4 = 0;
    // Matching: the extra locals are needed for the match.
    offset = 0xD9A4;
    base = rom_start;
    ((void *) D_8012B448) = (void *) (base + offset);
    func_800E4CE8();
}

// Size of an asset in the ROM (distance to the next table entry).
s32 func_800D5DB8(s32 id)
{
    rom_read_word((u32) D_8011B900 + id * 4, &D_8012B440.raw);
    rom_read_word((u32) D_8011B900 + id * 4 + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440.raw >> 6);
}

// Queues the asset behind *ref for release and clears *ref.
int func_800D5E28(s32 *ref)
{
    s32 asset;
    asset = *ref;
    func_800D5440(asset);
    ref[0] = 0;
}

void func_800D5E54()
{
    func_800D5440();
}

void func_800D5E74(void)
{
    func_800D55DC();
}

void func_800D5E94()
{
    func_800D54F0();
}

// Reads an asset into a caller buffer; returns its size (rounded up to 16 when
// uncompressed) or 0 on failure.
s32 func_800D5EB4(s32 id, void *buffer, s32 capacity)
{
    s32 size;
    s32 rem;
    s32 result;
    if (func_800D5AB4(id) < 0)
        return 0;
    result = id * 4;
    rom_read_word(D_8011B900 + result, ((LocalRomEntry *) &D_8012B440.raw));
    if (D_8012B440.LocalRomEntry.flags & 1) {
        func_800E6950(id, 0, buffer);
        result = D_8012B7E8;
    } else {
        rom_read_word(D_8011B900 + result + 4, ((LocalRomEntry *) &D_8012B444));
        size = (*((LocalRomEntry *) &D_8012B444)).offset - D_8012B440.LocalRomEntry.offset;
        if (size & 1)
            size++;
        rem = size & 0xF;
        result = size;
        if (rem)
            result = size - rem + 0x10;
        if (capacity >= size)
            rom_dma_read(buffer, D_8012B440.LocalRomEntry.offset + ((u32) D_8012B448), size);
        else
            return 0;
    }
    return result;
}

// Sets the size of the last loaded asset.
int func_800D5FDC(s32 size)
{
    D_8012B7E8 = size;
}

// Returns the loaded asset for an id, or 0 if it is not loaded.
s32 func_800D5FE8(s32 id)
{
    s32 i;
    s32 count;
    count = D_8012B7E4;
    i = 0;
    while (i < count && id != D_8012B6E0[i]) {
        i++;
    }
    if (i >= count) {
        return 0;
    }
    return ((s32 *) D_8012B450)[i];
}

// TU-NOTE: the .data of this file is defined here in C (values from the ROM).
s32 D_8011B900 = 0x5188;
