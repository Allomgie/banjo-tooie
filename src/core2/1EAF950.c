// Two unrelated halves: a frame-aged level-2 asset cache (sorted by id, GC and defrag), and
// the spline path system with per-actor spline following.
#include "core2/1EAF950.h"

typedef struct {
    s32 pad[2];
    u32 local_0 : 14;
    u32 pad2 : 18;
} EntryD6060;
extern s16 D_8012BE62;
void aligned4_memmove(void *dst, void *src, int length);
typedef struct {
    u32 unk0_0 : 27;
    u32 unk0_27 : 4;
    u32 unk0_31 : 1;
    s32 unk4;
    u32 unk8_0 : 14;
    u32 unk8_14 : 1;
    u16 unk8_15 : 1;
    u16 unkA_0 : 4;
    u16 unkA_4 : 12;
} S8012B800;
extern s16 D_8012BE64;
typedef struct {
    u32 age : 27, kind : 4, pinned : 1;
    void *data;
    union {
        struct {
            u32 unused : 14, blocked : 1, rest : 17;
        } bits;
        struct {
            u16 flags;
            u8 unused, id;
        } fields;
    } extra;
} LocalAsset;
extern s32 func_8001211C(void);
extern s32 func_800D56C4(void *);
extern void func_800D5E54(void *);
typedef struct {
    u32 age : 27, type : 4, busy : 1;
    void *asset;
    u32 unused0 : 14, locked : 1, active : 1, unused1 : 16;
} LocalEntry_800D6550;
extern void *func_800D5804(void *, s32);
typedef struct {
    u32 local_0 : 27;
    u32 local_1 : 4;
    u32 local_2 : 1;
    s32 local_3;
    u16 local_4 : 14;
    u16 local_5 : 2;
    u16 local_6;
} local_type_800D66AC;
s16 D_8011B910 = -1;
typedef struct {
    u32 age : 27, type : 4, busy : 1;
    ImageStruct *asset;
    u32 id : 14, locked : 1, active : 1, refs : 4, unused : 4, slot : 8;
} LocalEntry_800D674C;
typedef struct {
    u8 pad[0x2C];
    s32 off;
} Img2C;
extern ImageStruct *func_800D5B34(s32);
typedef struct {
    u32 local_0 : 27;
    u32 local_1 : 4;
    u32 local_2 : 1;
    s32 local_3;
    u32 local_4 : 14;
    u32 local_5 : 1;
    u32 local_6 : 1;
    u32 local_7 : 16;
} EntryD725C;
typedef struct {
    u8 local_0[10];
    u16 local_1 : 4;
    u16 local_2 : 12;
} local_type_800D6CEC;
extern s16 D_8012BE60;
typedef struct {
    u32 age : 27, type : 4, busy : 1;
    void *asset;
    u32 unused0 : 16, references : 4, unused1 : 12;
} LocalEntry_800D6E54;
typedef struct {
    u8 pad0[0xA];
    u16 fld : 4;
    u16 rest : 12;
} E_D7050;
typedef union {
    u8 raw[1];
    EntryD6060 EntryD6060[1];
    ImageStruct ImageStruct[1];
    S8012B800 S8012B800[1];
    local_type_800D66AC local_type_800D66AC[1];
    LocalEntry_800D674C LocalEntry_800D674C[1];
    EntryD725C EntryD725C[1];
    local_type_800D6CEC local_type_800D6CEC[1];
    LocalEntry_800D6E54 LocalEntry_800D6E54[1];
    E_D7050 E_D7050[1];
} Union_D_8012B800;
// Asset cache: up to 136 entries of 12 bytes, sorted by asset id (entry layouts above).
extern Union_D_8012B800 D_8012B800;
extern u32 D_8012B80A[];
extern s32 D_8012BFFC;
typedef struct {
    f32 local_0;
    u8 pad[16];
} EntryD75DC;
typedef struct {
    s32 local_0;
    EntryD75DC local_1[1];
} BlockD75DC;
extern s16 D_8012BFF6;
extern void *func_8001B798();
extern f32 func_800C7AE4(void *, s32, f32);
typedef struct {
    u8 pad0[0x24];
    u32 unused0 : 16, flag0 : 1, flag1 : 1, flag2 : 1, unused1 : 4, field0 : 3, unused2 : 6;
    u32 unused3 : 26, field1 : 6;
} LocalState_800D7754;
typedef struct {
    u32 pad0 : 21;
    s32 path : 10;
    u32 flag0 : 1;
    u8 pad4[8];
    f32 position;
    u8 pad10[4];
    f32 speed;
    u8 pad18[0xC];
    u32 pad24a : 18, player : 1, pad24b : 4, focus : 3, pad24c : 6;
    u32 pad28 : 26, follow : 6;
    u8 pad2C[4];
    f32 startSpeed, endSpeed, start, end;
    u32 yawEnd : 9, yawStart : 9, pitchStart : 9, pad40 : 5;
    u32 globalTime : 1, mode : 2, pitchEnd : 9, pad44 : 20;
} LocalSpline_800D7948;
typedef struct {
    u8 pad0[4];
    s16 position[3];
} LocalMarker;
typedef union {
    struct {
        u32 pad0 : 1, direct : 1, pad1 : 30;
    } flags;
    struct {
        u16 pad0;
        s16 position[3];
        LocalMarker **marker;
    } data;
} LocalFocus;
extern LocalFocus *D_8012C014;
extern s32 D_8012BF70[];
extern f32 D_8012C000;
extern LocalSpline_800D7948 *func_80105494();
extern void func_800C810C(void *, f32, f32 *, f32 *);
extern void func_8008FE68(f32 *);
extern u8 *func_80106790(s32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
typedef struct {
    u8 local_0[0x24];
    u32 local_1 : 16;
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 local_4 : 14;
} FlagsD7DE8;
typedef struct {
    u8 pad0[0x10];
    u32 flags;
} LocalNode;
typedef struct {
    s32 count;
    LocalNode nodes[1];
} LocalList;
typedef struct {
    u8 pad0[0xC];
    f32 position;
    u8 pad10[0x28];
    f32 start, end;
} LocalState_800D7E38;
typedef struct {
    u32 pad0 : 21;
    s32 path : 10;
    u32 initialized : 1;
    u8 pad4[8];
    f32 position, previous, speed;
    u32 pad18a : 1, introSync : 1, pad18b : 30;
    u8 pad1C[4];
    f32 wait;
    u32 pad24a : 19, waitMode : 4, pad24b : 9;
    u32 pad28a : 6, event : 8, pad28b : 2, sequence : 9, resetSequence : 1, pad28c : 6;
    f32 cap;
} LocalSpline_800D8070;
extern u8 D_8012BE6F[];
extern f32 func_800C8070(void *, f32, f32, s32 *);
extern f32 func_800C7E28(void *);
extern void func_800C7A68(void *, f32, f32 *);
extern f32 _glintrosyncDll_entrypoint_5(void);
extern f32 func_800D8FF8(void);
extern s32 _seqdefine_entrypoint_0(s32);
extern s32 func_800DA298(s32);
extern s32 _capod_entrypoint_16(f32);
extern void func_800DA524(s32);
typedef struct {
    u8 pad0[0x188];
    s32 unk188;
    u8 pad18C[0x10];
    s32 unk19C;
    u8 pad1A0[4];
    s32 unk1A4;
} S8012BE70;
extern s32 defrag(s32);
extern u8 D_8012BFF4[];

extern u8 D_8012BE70[];

// Frame-aged asset cache on top of the level-1 loader: get, touch, free, GC by age, defrag.
// Returns the sorted insert position for id and opens a gap there.
s32 func_800D6060(s32 id)
{
    s32 mid;
    s32 hi, lo;
    u32 mid_word;
    s32 move_count;
    hi = D_8012BE62 - 1;
    mid = 0;
    lo = 0;
    while (lo <= hi) {
        mid = (hi + lo) >> 1;
        mid_word = *(u32 *) ((u8 *) &D_8012B800.EntryD6060[mid] + 8);
        if ((s32) (mid_word >> 18) < id) {
            lo = mid + 1;
            if (lo < D_8012BE62) {
                if (id < (s32) D_8012B800.EntryD6060[lo].local_0) {
                    mid = lo;
                    break;
                }
            } else {
                mid = D_8012BE62;
                break;
            }
        } else {
            hi = mid - 1;
            if (hi >= 0) {
                if ((s32) D_8012B800.EntryD6060[hi].local_0 < id)
                    break;
            } else {
                mid = 0;
                break;
            }
        }
    }
    if (mid < 0)
        mid = 0;
    else if (D_8012BE62 < mid)
        mid = D_8012BE62;
    if (mid < D_8012BE62) {
        move_count = D_8012BE62 - mid;
        aligned4_memmove(&D_8012B800.EntryD6060[mid + 1], &D_8012B800.EntryD6060[mid],
                         move_count * 12);
    }
    return mid;
}

// Removes an entry and invalidates the vacated last slot.
void func_800D61B4(ImageStruct *entry)
{
    s16 marked;
    u16 half;
    s32 tail_count;
    tail_count = (D_8012BE62 - (entry - D_8012B800.ImageStruct)) - 1;
    if (tail_count > 0) {
        aligned4_memmove(entry, entry + 1, tail_count * 12);
    }
    D_8012BE62 -= 1;
    *(u8 *) ((u8 *) &D_8012B800.ImageStruct[D_8012BE62] + 3) &= 0xFFE1;
    // Matching: the copies of the halfword are needed for the match.
    half = *(u16 *) ((u8 *) &D_8012B800.ImageStruct[D_8012BE62] + 8);
    marked = half;
    marked = marked | 0xFFFC;
    *(u16 *) ((u8 *) &D_8012B800.ImageStruct[D_8012BE62] + 8) = marked;
}

// Binary search by id; returns the entry index or -1.
s32 func_800D6254(id)
s32 id;
{
    s32 mid;
    s32 hi;
    s32 lo;
    u32 mid_id;
    hi = D_8012BE62 - 1;
    lo = 0;

if (hi >= 0) {
loop_2:
    mid = (s32) (hi + lo) >> 1;
    mid_id = (u32) *(u32 *) ((u8 *) (u32 *) D_8012B800.raw + mid * 0xC + 8) >> 0x12;
    if ((s32) mid_id < id) {
        lo = mid + 1;
        goto block_7;
    }
    if (id < (s32) mid_id) {
        hi = mid - 1;
        goto block_7;
    }
    return mid;
block_7:
    if (hi >= lo) {
        goto loop_2;
    }
}

return -1;
}

void func_800D62E4(void)
{
    S8012B800 *entry;

if (D_8012BE64 != 0) {
    entry = &D_8012B800.S8012B800[func_800D6254()];
    if (entry->unk0_27 == 2 && entry->unk8_14 && !entry->unk8_15) {
        entry->unk8_14 = 0;
    }
    D_8012BE64 = 0;
}

}

// Evicts an entry: frees its asset and removes it from the array.
int func_800D6378(Actor *entry)
{
    u32 result;

switch ((*(u32 *) entry << 27) >> 28) {
    case 1:
        break;
    case 2:
        result = func_800D56C4(*(u32 *) ((char *) entry + 4));
        if (*(u8 *) ((char *) entry + 0xB) != 0) {
            func_800DBB9C(*(u8 *) ((char *) entry + 0xB) & 0xFF);
            *(u8 *) ((char *) entry + 0xB) = 0;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        result = func_800D56C4(*(u32 *) ((char *) entry + 4));
}

func_800D61B4(entry);
return result;
}

s32 func_800D6408(LocalAsset *entry)
{
    s32 result;

switch (entry->kind) {
    case 6:
    case 7:
        if ((s32) (entry->age + 1) < func_8001211C())
            result = func_800D56C4(entry->data);
        else {
            func_800D5E54(entry->data);
            result = -1;
        }
        break;
    case 2:
        if ((s32) (entry->age + 1) < func_8001211C())
            result = func_800D56C4(entry->data);
        else if (!entry->extra.bits.blocked && !(entry->extra.fields.flags & 1) &&
                 !entry->pinned)
            result = func_800D56C4(entry->data);
        else {
            func_800D5E54(entry->data);
            result = -1;
        }
        if (entry->extra.fields.id) {
            func_800DBB9C(entry->extra.fields.id & 0xFF);
            entry->extra.fields.id = 0;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
        result = func_800D56C4(entry->data);
    case 1:
        break;
}

func_800D61B4(entry);
return result;

}

s32 func_800D6550(LocalEntry_800D6550 *entry)
{
    switch (entry->type) {
        case 1:
        case 9:
            return 0;
        case 3:
        case 4:
        case 5:
        case 8:
            if (!func_800D5E94(entry->asset))
                entry->asset = func_800D5804(entry->asset, 1);
            return 1;
        case 6:
        case 7:
            if ((s32) (entry->age + 1) < func_8001211C()) {
                entry->asset = func_800D5804(entry->asset, 1);
                return 1;
            }
            return 0;
        case 2:
            if ((s32) (entry->age + 1) < func_8001211C()) {
                if (!func_800D5E94(entry->asset))
                    entry->asset = func_800D5804(entry->asset, 1);
            } else {
                if (!entry->locked && !entry->active && !entry->busy) {
                    if (!func_800D5E94(entry->asset))
                        entry->asset = func_800D5804(entry->asset, 1);
                    return 1;
                }
                return 0;
            }
    }

return 0;
}

// Clears all 136 entries and resets the entry count.
void func_800D66AC(void)
{
    s32 i;
    for (i = 0; i < 136; i++) {
        D_8012B800.local_type_800D66AC[i].local_1 = 0;
        D_8012B800.local_type_800D66AC[i].local_4 = -1;
        D_8012B800.local_type_800D66AC[i].local_3 = 0;
    }
    D_8011B910 = -1;
    D_8012BE62 = 0;
}

// Returns the cached asset for id, loading and inserting it on a miss.
ImageStruct *func_800D674C(s32 id)
{
    s32 index;
    s32 asset_kind;
    LocalEntry_800D674C *entry;
    ImageStruct *asset;
    void *anim_data;
    index = func_800D6254(id);
    if (index != -1) {
        D_8011B910 = index;
        D_8012BE64 = id;

if (D_8012B800.LocalEntry_800D674C[index].type == 2) {
    if (func_8001211C() == D_8012B800.LocalEntry_800D674C[index].age) {
        if (D_8012B800.LocalEntry_800D674C[index].locked)
            D_8012B800.LocalEntry_800D674C[index].active = 1;
        else
            D_8012B800.LocalEntry_800D674C[index].locked = 1;
    } else {
        if (func_8001211C() == D_8012B800.LocalEntry_800D674C[index].age + 1)
            D_8012B800.LocalEntry_800D674C[index].busy =
                D_8012B800.LocalEntry_800D674C[index].locked ||
                D_8012B800.LocalEntry_800D674C[index].active;
        D_8012B800.LocalEntry_800D674C[index].locked = 1;
        D_8012B800.LocalEntry_800D674C[index].active = 0;
    }
}

D_8012B800.LocalEntry_800D674C[index].age = func_8001211C();
return D_8012B800.LocalEntry_800D674C[index].asset;
}
if ((u32) D_8012BE62 >= 135)
    return 0;
asset_kind = func_800D58FC(id);
asset = func_800D5B34(id);
if (!asset) {
    D_8012BE64 = 0;
    return 0;
}
index = func_800D6060(id);
entry = &D_8012B800.LocalEntry_800D674C[index];
D_8012BE62++;
D_8011B910 = index;
entry->age = func_8001211C();
entry->asset = asset;
entry->refs = 0;
entry->unused = 0;
entry->id = id;
D_8012BE64 = id;

// Cache kind from the asset-table kind.
switch (asset_kind) {
    case 0:
        entry->type = 2;
        entry->locked = 1;
        entry->active = 0;
        entry->slot = 0;
        anim_data = ((Img2C *) entry->asset)->off
                      ? (void *) ((s32) entry->asset + ((Img2C *) entry->asset)->off)
                      : 0;
        if (anim_data) {
            entry->slot = func_800DBA84();
            func_800DBBF8(entry->slot, anim_data);
        }
        break;
    case 1:
        entry->type = 1;
        break;
    case 3:
    case 10:
        entry->type = 4;
        break;
    case 5:
        entry->type = 3;
        break;
    case 6:
        entry->type = 5;
        break;
    case 7:
        entry->type = 6;
        break;
    case 8:
        entry->type = 7;
        break;
    case 2:
        entry->type = 8;
        break;
    case 9:
        entry->type = 9;
        break;
}

return asset;
}

// Touches the entry for id and returns its asset, or 0 if not cached.
s32 func_800D6B0C(s32 id)
{
    s32 index;
    index = func_800D6254(id);

if (index != -1) {
    D_8012BE64 = id;
    if (D_8012B800.EntryD725C[index].local_1 == 2) {
        if (D_8012B800.EntryD725C[index].local_0 == func_8001211C()) {
            if (D_8012B800.EntryD725C[index].local_5) {
                D_8012B800.EntryD725C[index].local_6 = 1;
            } else {
                D_8012B800.EntryD725C[index].local_5 = 1;
            }
        } else {
            D_8012B800.EntryD725C[index].local_5 = 1;
        }
    }
    D_8012B800.EntryD725C[index].local_0 = func_8001211C();
    return D_8012B800.EntryD725C[index].local_3;
}

return 0;

}

// Returns 1 if an entry exists for the id.
int func_800D6C34()
{
    if (func_800D6254() != -1) {
        return 1;
    }
    {
        return 0;
    }

}

// Tries to evict every entry whose id is outside 0x1DDD-0x1ED7.
void func_800D6C64()
{
    s32 i;
    s32 count;
    u32 id;
    count = D_8012BE62 - 1;

for (i = count; i >= 0; i--) {
    id = ((u32 *) &D_8012B800.raw[i * 12])[2];
    id = id >> 0x12;
    // Matching: assigning count inside the condition is needed for the match.
    if (((count = id) <= 0x1DDC) || (count >= 0x1ED8)) {
        func_800D6408(&D_8012B800.raw[i * 12]);
    }
}

}

// Tries to evict the entry for the id unless it has references; returns 2 if not cached.
s32 func_800D6CEC(void)
{
    s32 index = func_800D6254();

if (index != -1) {
    if (D_8012B800.local_type_800D6CEC[index].local_1)
        return 1;
    return func_800D6408(&D_8012B800.local_type_800D6CEC[index]);
}

return 2;
}

// Incremental defrag step: scans up to 32 entries per call, handling at most 8.
void func_800D6D68(void)
{
    s32 scanned;
    s32 handled;

    scanned = 0;
    handled = 0;

while (scanned < 0x20 && handled < 8) {
    u8 *entry = (u8 *) &D_8012B800.raw + D_8012BE60 * 0xc;
    if ((*(u32 *) (entry + 8) >> 18) != 0x3FFF) {
        if (!(*(u8 *) (entry + 0xA) & 0xF)) {
            func_800D6550(entry);
            handled++;
        }
    }
    D_8012BE60++;
    if (D_8012BE60 >= D_8012BE62) {
        D_8012BE60 = 0;
    }
    scanned++;
}

}

// Age-based garbage collection under memory pressure; mode selects the age limit and scan budget.
void func_800D6E54(s32 mode)
{
    s32 now;
    s32 cutoff;
    s32 budget;
    LocalEntry_800D6E54 *entry;
    f32 load;
    static s32 D_8011B914 = 0;
    // Fill ratio of the 136-entry array.
    load = D_8012BE62 * 0.007352941f;

if (load > 0.85f || !func_800A9F30() || mode != 1) {
    now = func_8001211C();
    cutoff = now - func_800A9F14(mode);
    budget = mode == 1 ? 8 : D_8012BE62 - 1;
    for (; budget >= 0; budget--) {
        entry = &D_8012B800.LocalEntry_800D6E54[D_8011B914];
        if (entry->type && !entry->references &&
            ((s32) entry->age < cutoff ||
             (mode == 3 && (entry->type == 1 || entry->type == 2 || entry->type == 6 ||
                               entry->type == 7 || entry->type == 5 || entry->type == 8)))) {
            func_800D6378(entry);
            if (D_8011B914 > 0)
                D_8011B914--;
        }
        if (D_8011B914 >= D_8012BE62 - 1)
            D_8011B914 = 0;
        else
            D_8011B914++;
    }
}

}

// TU-NOTE: the rest of this file's .data (formerly asm/data/core2/1EF5210.data.s) is defined here in C,
// values from the ROM. They follow the function-static D_8011B914 of func_800D6E54, as in the ROM.
// D_8011B918 and D_8011B924 are not referenced by name anywhere.
s32 D_8011B918[2] = {0, 0};
s32 D_8011B920 = 0;
u32 D_8011B924[15] = {0xFFFFFFFF, 0xFF,       0xFF,     0xFFFF00FF, 0xFF00FF,
                      0xFF808080, 0xFF8000FF, 0x808080, 0x8080,     0xFF400000,
                      0x40800000, 0x40400000, 0x0,      0x0,        0x0};

// Adds or subtracts one from the refcount of an entry.
void func_800D7050(s32 index, s32 increment)
{
    if (increment != 0) {
        D_8012B800.E_D7050[index].fld++;
    }

else
{
    D_8012B800.E_D7050[index].fld--;
}
}

// Adjusts the refcount of the most recently touched entry.
void func_800D70D0(s32 increment)
{
    func_800D7050(D_8011B910, increment);
}

// Adjusts the refcount of the entry for id; returns 1 if found.
int func_800D70F8(s32 id, s32 increment)
{
    s32 index;
    index = func_800D6254(id);

if (index != -1) {
    // Matching: the | 0 is needed for the match.
    func_800D7050(index | 0, increment);
    return 1;
}

return 0;
}

// Returns the refcount of the entry for the id, or -1 if not cached.
u32 func_800D7138(void)
{
    s32 index;

    index = func_800D6254();

if (index != -1) {
    return (u32) *(u16 *) ((u8 *) D_8012B80A + index * 12) >> 12;
}

return -1U;
}

// Increments or decrements a 4-bit counter in the entry.
void func_800D7184(s32 index, s32 increment)
{
    u8 *entry;
    unsigned char byte_copy;
    s32 byte;

// Matching: the * 0 and the extra copy through byte_copy are needed for the match.
if (increment != (0xFFF0 * 0)) {
    entry = (u8 *) (u8 *) D_8012B800.raw + (index * 0xC);
    byte = entry[0xA];
    entry[0xA] = (u8) ((byte & 0xFFF0) | (((byte_copy = byte) + 1) & 0xF));
    return;
}

entry = ((u8 *) (((u8 *) D_8012B800.raw))) + (index * 0xC);
byte = entry[0xA];
entry[0xA] = (u8) ((byte & (0xFFF0 & 0xFFFFFFFFu)) | (((entry[0xA] & 0xFFu) - 1) & 0xF));
}

// Adjusts func_800D7184's counter for the most recently touched entry.
int func_800D71F4(s32 increment)
{
    s16 index;
    s16 index_copy;
    // Matching: the copy of the index and the | 0 are needed for the match.
    index = D_8011B910;
    index_copy = index;
    func_800D7184(index_copy, increment | 0);
}

// Adjusts the 4-bit counter of the entry for id; returns 1 if found.
int func_800D721C(s32 id, s32 increment)
{
    s32 index;
    index = func_800D6254(id);

if (index != -1) {
    // Matching: needed for the match.
    func_800D7184(index | 0, increment);
    return 1;
}

return 0;
}

// Returns the asset for id, loading it on a miss; a cached asset must also pass func_800D5EB4.
int func_800D725C(s32 id)
{
    s32 index;
    s32 unk_0;
    s32 asset;
    EntryD725C *entry;
    index = func_800D6254(id);

if (index == -1) {
    return (s32) func_800D674C(id);
} else {

D_8011B910 = index;
D_8012B800.EntryD725C[index].local_0 = func_8001211C();
entry = &D_8012B800.EntryD725C[index];
unk_0 = func_800D5950(id);
asset = entry->local_3;

if (func_800D5EB4(id, asset, unk_0)) {
    return entry->local_3;
}

return 0;
}
}

// Returns the anim-texture slot of a model entry, or 0.
u8 func_800D731C(void)
{
    s32 index;

    index = func_800D6254();
    if (index != -1 && ((u32) (*((u32 *) ((u8 *) D_8012B800.raw + index * 12)) << 27) >> 28) == 2) {
        return ((u8 *) ((u8 *) D_8012B800.raw + index * 12))[11];
    }
    return 0;
}

void func_800D738C()
{
    func_800D58FC();
}

void func_800D73AC()
{
    func_800D59C0();
}

// Returns 1 if the id has an entry.
int func_800D73CC()
{
    s32 index;
    s32 found;
    index = func_800D6254();
    // Matching: the | 0 operations here and in the return are needed for the match.
    if (index == -1) {
        found = 0 | 0;
    } else {
        found = 1;
    }
    return found | 0;
}

// Spline paths: path/node registry, per-actor spline following and orientation, spline clock.
// Spline path system starts here.
int func_800D7400()
{
    return (int) ((s32 *) D_8012BE70);
}

int func_800D740C()
{
    D_8012BFFC = 0;
}

void func_800D7418()
{
    _glsplineDll_entrypoint_0(&D_8012BE70);
}

void func_800D743C()
{
    _glsplineDll_entrypoint_1(&D_8012BE70);
}

void func_800D7460()
{
    func_800D743C();
    func_800D7418();
}

// Appends a value to each of two parallel lists in the spline table; returns the new index.
s32 func_800D7488(value_a, value_b)
s16 value_a;
s16 value_b;
{
    s32 list_a;
    char *count_ptr;
    s32 new_size;
    s16 *handle_ptr;
    s32 list_b;
    new_size = (*((s32 *) (((char *) D_8012BE70) + 0x188)) += 1);
    handle_ptr = (s16 *) (((char *) D_8012BE70) + 0x184);
    new_size = new_size * 2;
    list_a = func_8001B710(*handle_ptr, new_size);
    list_b = func_8001B710(*((s16 *) (((char *) D_8012BE70) + 0x186)),
                            (*((s32 *) (((char *) D_8012BE70) + 0x188))) * 2);
    count_ptr = ((char *) D_8012BE70) + 0x188;
    *((s16 *) ((list_a + ((*((s32 *) count_ptr)) * 2)) - 2)) = value_a;
    *((s16 *) ((list_b + ((*((s32 *) count_ptr)) * 2)) - 2)) = value_b;
    return (*((s32 *) count_ptr)) - 1;
}

// Returns the spline path with the given index, or NULL for -1.
void *func_800D7520(s32 path)
{
    if (path == -1) {
        return 0;
    }
    return func_8001B798(
        *(s16 *) ((u8 *) func_8001B798(*(s16 *) ((u8 *) D_8012BFF4)) + (path << 1)));
}

// Returns the node data of a path (past its count word), or NULL if it has none.
u8 *func_800D7570(s32 path)
{
    s32 *handles;
    u8 *nodes;
    handles = func_8001B798(*(s16 *) ((s32 *) &D_8012BFF6));
    if (path == -1) {
        return NULL;
    }
    nodes = func_8001B798(*(s16 *) ((char *) handles + path * 2));
    if (*(s32 *) nodes == 0) {
        return NULL;
    }
    return nodes + 4;
}

// Number of the path's nodes passed at the given position.
s32 func_800D75DC(s32 path, f32 position)
{
    s16 *handles;
    BlockD75DC *block;
    EntryD75DC *node;
    s32 passed;
    handles = func_8001B798(D_8012BFF6);
    if (path == -1)
        return 0;
    block = func_8001B798(handles[path]);
    if (block->local_0 == 0)
        return 0;
    for (node = block->local_1, passed = 0;
         node < block->local_0 + block->local_1 &&
         (node->local_0 < position || (position == 1.0f && 1.0f == node->local_0));
         node++) {
        passed++;
    }
    return passed;
}

f32 func_800D7708(s32 path, s32 param_1, s32 param_2)
{
    void *path_data;
    f32 unk_0;
    f32 unk_1;
    path_data = func_800D7520(path);
    unk_0 = func_800C7AE4(path_data, param_1, 1.0f);
    unk_1 = (f32) param_2;
    unk_1 = unk_1 / 4;
    return unk_0 / unk_1;
}

// Sets the spline's flag bits for the given mode (1-7).
void func_800D7754(void *actor, s32 mode)
{
    LocalState_800D7754 *spline = func_80105494(actor);
    switch (mode) {
        case 1:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 1;
            spline->flag0 = 1;
            spline->flag1 = 1;
            break;
        case 2:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 0;
            spline->flag0 = 0;
            break;
        case 3:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 0;
            spline->flag0 = 1;
            break;
        case 4:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 0;
            spline->flag1 = 0;
            break;
        case 5:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 0;
            spline->flag1 = 1;
            break;
        case 6:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 0;
            spline->flag0 = 0;
            spline->flag1 = 0;
            break;
        case 7:
            spline->field1 = 0;
            spline->field0 = 0;
            spline->flag2 = 0;
            spline->flag0 = 1;
            spline->flag1 = 1;
    }
}

void func_800D7900(s32 actor)
{
}
// Points the actor's yaw (0x54) and pitch (0x50) at a target position.
void func_800D7908(void *actor, void *target)
{
    f32 angles[3];
    func_800A516C(angles, target, (void *) ((char *) actor + 4));
    *(f32 *) ((char *) actor + 84) = angles[1];
    *(f32 *) ((char *) actor + 80) = angles[0];
}

// Sets the actor's yaw/pitch for its spline position: from the path tangent, a focus target or
// interpolated angles.
void func_800D7948(u8 *actor, s32 flags, s32 param_2, s32 param_3)
{
    LocalSpline_800D7948 *spline;
    f32 path_pos[3];
    f32 path_angles[3];
    s32 i;
    f32 focus_pos[3];
    LocalFocus *focus;
    LocalMarker *marker;
    f32 player_pos[3];
    f32 time;
    f32 blend;
    spline = func_80105494(actor);
    // Yaw (0x100) and pitch (0x200) from the path tangent.
    if (flags & 0x300) {
        func_800C810C(func_800D7520(spline->path), spline->position, path_pos, path_angles);

if (flags & 1) {
    if (flags & 0x100)
        *(f32 *) (actor + 0x54) = path_angles[1];
    if (flags & 0x200)
        *(f32 *) (actor + 0x50) = path_angles[0];
} else {

if (flags & 0x100) {
    if (path_angles[1] >= 180.0f)
        *(f32 *) (actor + 0x54) = path_angles[1] - 180.0f;
    else
        *(f32 *) (actor + 0x54) = path_angles[1] + 180.0f;
}

if (flags & 0x200)
    *(f32 *) (actor + 0x50) = 360.0f - path_angles[0];
}
}
// Look target: focus point, follow actor or player.
if (spline->focus) {
    focus = (LocalFocus *) ((u8 *) D_8012C014 + spline->focus * sizeof(LocalFocus) -
                              sizeof(LocalFocus));
    if (focus->flags.direct) {
        for (i = 0; i < 3; i++)
            focus_pos[i] = focus->data.position[i];
    } else {
        for (i = 0; i < 3; i++)
            focus_pos[i] = (*focus->data.marker)->position[i];
    }
    func_800D7908(actor, focus_pos);
} else if (spline->follow) {
    func_800D7908(actor, (f32 *) (func_80106790(D_8012BF70[spline->follow]) + 4));
} else if (spline->player) {
    func_8008FE68(player_pos);
    func_800D7908(actor, player_pos);
} else {
    // Interpolated yaw, pitch and speed over [start, end].
    time = spline->globalTime ? D_8012C000 : spline->position;
    if (spline->start <= time && time < spline->end) {
        blend = (time - spline->start) / (spline->end - spline->start);

if (spline->mode & 1) {
    if (flags & 0x800)
        *(f32 *) (actor + 0x54) = func_800136E4(
            func_800F1DCC(spline->yawEnd, spline->yawStart) * blend + spline->yawStart);
    if (flags & 0x1000)
        *(f32 *) (actor + 0x50) = func_800136E4(
            func_800F1DCC(spline->pitchEnd, spline->pitchStart) * blend + spline->pitchStart);
}

if (spline->mode & 2)
    spline->speed = (spline->endSpeed - spline->startSpeed) * blend + spline->startSpeed;
}
else if (spline->start != 0.0f || spline->end != 0.0f)
{
    spline->start = 0;
    spline->globalTime = 0;
    spline->end = 0;
}
}
func_800D7900(actor);
*(f32 *) (actor + 0x48) = *(f32 *) (actor + 0x54);
*(f32 *) (actor + 0x44) = *(f32 *) (actor + 0x50);
}

// Yaw/pitch flag mask for func_800D7948, chosen by the spline's two mode bits.
s32 func_800D7DE8(u8 *actor)
{
    FlagsD7DE8 *spline;
    spline = (FlagsD7DE8 *) func_80105494(actor);
    return (spline->local_2 ? 0x800 : 0x100) + (spline->local_3 ? 0x1000 : 0x200);
}

// Triggers the nodes passed between two indices, forward or backward. -9999 means the path end.
s32 func_800D7E38(void *actor, s32 path, s32 first_node, s32 end_node_index, s32 end_offset, s32 direction)
{
    s32 unk_0[2];
    s32 node_count;
    s16 *handles;
    s32 result;
    LocalNode *node;
    f32 saved_position;
    LocalState_800D7E38 *spline;
    LocalList *list;
    LocalNode *end_node;
    s32 step;
    handles = func_8001B798(D_8012BFF6);
    result = 0;
    spline = func_80105494(actor);
    list = func_8001B798(handles[path]);
    node_count = list->count;
    if (!node_count)
        return 0;
    node = (first_node == -9999 ? node_count - 1 : first_node) + list->nodes;
    step = direction * 20;
    end_node = (end_node_index == -9999 ? node_count + end_offset : end_node_index) + list->nodes;
    while (node != end_node && result != 1) {
        if ((step >= 20 && !(node->flags & 1)) ||
            (step < 0 && (node->flags & 1) == 1)) {
            if (D_8011B920 == 1)
                saved_position = spline->position;
            result = _glsplinenode_entrypoint_1(((s32 *) D_8012BE70), actor, node, list);

if (spline->start != 0.0f || spline->end != 0.0f) {
    if (!(spline->position >= spline->start && spline->position < spline->end)) {
        spline->start = 0.0f;
        spline->end = 0.0f;
    }
}

}
node = (LocalNode *) ((u8 *) node + step);
}
if (D_8011B920 == 1 && result == 1)
    spline->position = 1e-05f + saved_position;
return result;
}

// Advances the actor along its spline path unless a wait (timer, sequence, event or cap) holds it,
// triggers the nodes crossed and updates the orientation. Returns 0 if the actor has no path.
s32 func_800D8070(u8 *actor, s32 flags, s32 param_2, s32 param_3)
{
    s32 nodes_before;
    s32 nodes_after;
    s32 wrapped;
    LocalSpline_800D8070 *spline;
    f32 speed;
    void *path_data;
    s16 *paths;
    s32 mask_before;
    s32 mask_after;
    wrapped = 0;
    spline = func_80105494(actor);
    speed = spline->speed;
    if (spline->path == -1)
        return 0;
    spline->previous = spline->position;
    nodes_before = func_800D75DC(spline->path, spline->position);
    if (spline->wait == 0.0f && !spline->waitMode && !spline->sequence && !spline->event &&
        spline->cap == 0.0f) {
        paths = func_8001B798((*((s16 *) D_8012BFF4)));
        path_data = func_8001B798(paths[spline->path]);
        spline->position = func_800C8070(path_data, spline->position, speed, &wrapped);
        func_800C7A68(path_data, spline->position, (f32 *) (actor + 4));
    } else {
        // Waiting: the position is held.
        if (spline->wait != 0.0f) {
            spline->wait -= spline->introSync ? _glintrosyncDll_entrypoint_5() : func_800D8FF8();
            if (spline->wait < 0.0f)
                spline->wait = 0.0f;

}
if (spline->sequence && func_800DA298(_seqdefine_entrypoint_0(spline->sequence - 1))) {
    if (spline->resetSequence) {
        spline->resetSequence = 0;
        func_800DA524(_seqdefine_entrypoint_0(spline->sequence - 1));
    }

spline->sequence = 0;

}
if (spline->event && !D_8012BE6F[spline->event])
    spline->event = 0;
if (spline->cap > 0.0f && _capod_entrypoint_16(spline->cap))
    spline->cap = 0.0f;
}
nodes_after = func_800D75DC(spline->path, spline->position);
if (!spline->initialized) {
    spline->initialized = 1;
    *(f32 *) (actor + 0x48) = *(f32 *) (actor + 0x54);
    *(f32 *) (actor + 0x44) = *(f32 *) (actor + 0x50);
}
if (nodes_before == nodes_after && wrapped == 0) {
    func_800D7948(actor, flags, param_2, param_3);
} else {
    mask_before = func_800D7DE8(actor);
    if (speed > 0.0f) {
        if (!wrapped) {
            if (func_800D7E38(actor, spline->path, nodes_before, nodes_after, 0, 1) == 2)
                D_8012BFFC = 1;
        } else if (!func_800D7E38(actor, spline->path, nodes_before, -9999, 0, 1)) {

func_800D7E38(actor, spline->path,
              func_800D75DC(spline->path, func_800C7E28(func_800D7520(spline->path))), nodes_after, 0,
              1);
}
}
else if (speed < 0.0f)
{
    if (!wrapped) {
        func_800D7E38(actor, spline->path, nodes_before - 1, nodes_after - 1, 0, -1);
    } else if (!func_800D7E38(actor, spline->path, nodes_before - 1, -1, 0, -1)) {
        func_800D7E38(actor, spline->path, -9999, nodes_after - 1, 0, -1);
    }
}
mask_after = func_800D7DE8(actor);
if (mask_before == mask_after || (mask_before != mask_after && mask_before != (flags & 0x3F00))) {
    func_800D7948(actor, flags, param_2, param_3);
} else {
    func_800D7948(actor, (flags & ~0x3F00) | (mask_after & 0x3F00), param_2, param_3);
}
}
return 1;
}

// Repeats the spline step while the table's word 99 is set.
s32 func_800D8588(s32 actor, s32 flags, s32 param_2, s32 param_3)
{
    s32 total;
    u8 *spline;

    total = 0;
    spline = func_80105494();
    do {
        ((s32 *) D_8012BE70)[99] = 0;
        total += func_800D8070(actor, flags, param_2, param_3);
    } while (((s32 *) D_8012BE70)[99] != 0);
    if (*spline) {
        _glsplinecs_entrypoint_1(D_8012BE70, actor);
    }
    return (total) ? (1) : (0);
}

int func_800D8648(s32 path, s32 param_1)
{
    s32 path_data;
    path_data = func_800D7520(path);
    func_800EE7F8(path_data + 0x14, param_1);
}

void func_800D8674(void)
{
    s32 i;
    if ((*((S8012BE70 *) D_8012BE70)).unk1A4 != 0) {
        (*((S8012BE70 *) D_8012BE70)).unk1A4 = defrag((*((S8012BE70 *) D_8012BE70)).unk1A4);
    }
    // Matching: the empty loop is needed for the match.
    for (i = 0; i < (*((S8012BE70 *) D_8012BE70)).unk188; i++) {
    }
    if ((*((S8012BE70 *) D_8012BE70)).unk19C != 0) {
        (*((S8012BE70 *) D_8012BE70)).unk19C = defrag((*((S8012BE70 *) D_8012BE70)).unk19C);
    }
}

void func_800D86F0(s32 index, f32 unk_1, s32 unk_2)
{
    s32 table;
    s32 path;
    table = func_8001B798(*(s16 *) D_8012BFF4);
    // Matching: the (s16) cast on an s16 value is needed for the match.
    path = func_8001B798((s16) ((s16 *) table)[index]);
    func_800C7A68(path, unk_1, unk_2);
}

void func_800D8744(void)
{
    f32 delta_time;

    *(f32 *) &D_8012BE70[0x194] = *(f32 *) &D_8012BE70[0x190];

    if (D_8012BE70[0x1A8] != 0) {
        delta_time = _glintrosyncDll_entrypoint_5();
    } else {
        delta_time = func_800D8FF8();
    }
    D_8012C000 = *(f32 *) &D_8012BE70[0x190] + delta_time * 60.0f;
}

void func_800D87B0()
{
    _glsplineDll_entrypoint_2(&D_8012BE70);
}

int func_800D87D4(s32 *value, s32 index)
{
    D_8012BF70[index] = *value;
}

int func_800D87EC(s32 index)
{
    return D_8012BF70[index];
}

void func_800D8800(void)
{
}

int func_800D8808(s32 index)
{
    if (index != 0) {
        ((s8 *) D_8012C014)[(index - 1) * 12] &= ~0x80;
    }
}
