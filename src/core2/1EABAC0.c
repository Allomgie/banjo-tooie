// HUD item-counter layer: per-item state (group, target, rolling displayed value) and a slot
// allocator; shows, updates, hides and queries an item's HUD element via the infobar layer.
#include "core2/1EABAC0.h"

#define MAX_D2574(a, b) ((a) < (b) ? (b) : (a))
#define MIN_D2574(a, b) ((a) < (b) ? (a) : (b))
// Candidate infobar slots of one group.
typedef struct {
    s32 count;
    u8 *slots;
} E_D21F0;
extern E_D21F0 D_8011B45C[];
// Item id shown in each of the 48 infobar slots, -1 if free.
extern s16 D_8012B2C0[];
extern u8 *D_8011B460[];
// Same layout as EntryD2574, used to reset the entries.
typedef struct {
    u8 pad_0[4];
    s16 target;
    s16 extra;
    f32 displayed;
} A_D2438;
// HUD counter of one item; D_8011AFB0[id - 0xC0].
typedef struct {
    u8 group, sub_type;
    s16 unk_2, target, extra;
    f32 displayed; // rolls toward target
} EntryD2574;
extern EntryD2574 D_8011AFB0[];
extern f32 func_800D8FF8(void);
extern s32 func_800FA8E8(s32, s32);
extern s32 func_800FA874(s32, s32);
extern s32 func_800FA818(s32, s32);

// Returns the counter entry of an item id (index is id - 0xC0).
s32 *func_800D21D0(item_id)
s32 item_id;
{
    s32 offset;
    s32 table;
    s32 entry_offset;
    offset = 3;
    offset = offset << 2;
    offset = item_id * offset;
    table = &((s32 *) D_8011AFB0)[0];
    entry_offset = offset;
    entry_offset = entry_offset - 2304;
    return entry_offset + table;
}

// Returns the slot showing an item among the candidate slots of a group, or -1.
s32 func_800D21F0(s32 item_id, s32 group)
{
    u8 *cand;
    u8 *end;
    s32 slot;
    cand = D_8011B45C[group].slots;
    end = cand + D_8011B45C[group].count;
    while (cand < end) {
        slot = *cand;
        cand++;
        if (item_id == D_8012B2C0[slot]) {
            return slot;
        }
    }
    return -1;
}

// Returns the first free candidate slot of a group, or -1.
int func_800D225C(group)
s32 group;
{
    u32 end;
    u8 slot;
    u32 cand;
    u8 *list;
    // Matching: dead load through the uninitialized pointer, needed for the match.
    slot = *(u8 *) cand;
    list = (group * 8) + (u8 *) D_8011B45C;
    cand = *(u32 *) (list + 4);
    end = *(u32 *) list + cand;
    if (cand < end) {
    loop_1:
        slot = *(u8 *) cand;
        cand += 1;
        if (D_8012B2C0[slot] == -1) {
            return slot;
        }
        if (cand < end) {
            goto loop_1;
        }
    }
    return -1;
}

// Returns the first candidate slot of a group.
s32 func_800D22C8(group)
s32 group;
{
    return **(u8 **) ((char *) &D_8011B460 + (group * 8));
}

// Shows an entry's counter in the slot of its item (reused, free, or first of the group).
// Returns nonzero if it was shown.
s32 func_800D22E0(u8 *entry, s32 item_id)
{
    s32 result;
    s32 shown;
    s32 slot;
    s32 found;

    result = 0;
    found = func_800D21F0(item_id, *(u8 *) ((s8 *) entry + 0));
    slot = found;
    if (found < 0) {
        found = func_800D225C(*(u8 *) ((s8 *) entry + 0));
        slot = found;
    }
    if (found < 0) {
        found = func_800D22C8(*(u8 *) ((s8 *) entry + 0));
        slot = found;
    }
    if (found >= 0) {
        shown = func_800FA708((s32) *(f32 *) ((s8 *) entry + 8), slot,
                              *(u8 *) ((s8 *) entry + 1), *(u8 *) ((s8 *) entry + 2));
        result = shown;
        if (shown != 0) {
            func_800FA9B4(slot, *(s16 *) ((s8 *) entry + 6));
            D_8012B2C0[slot] = (s16) item_id;
        }
    }
    return result;
}

int func_800D2398(u8 *entry, int item_id)
{
    int slot = func_800D21F0(item_id, entry[0]);
    return (slot >= 0) && (func_800FA8E8(slot, entry[1]) == 1);
}

int func_800D23E8(u8 *entry, int item_id)
{
    int slot = func_800D21F0(item_id, entry[0]);
    return (slot >= 0) && (func_800FA874(slot, entry[1]) == 1);
}

// Resets all counters and frees all slots.
void func_800D2438(void)
{
    s32 i;
    for (i = 0; i < 91; i++) {
        ((A_D2438 *) D_8011AFB0)[i].target = -1;
        ((A_D2438 *) D_8011AFB0)[i].extra = 0;
        ((A_D2438 *) D_8011AFB0)[i].displayed = 0.0f;
    }
    for (i = 0; i < 48; i++) {
        ((s16 *) D_8012B2C0)[i] = -1;
    }
}

// Initializes an unused counter with a value and extra, then shows it.
void func_800D2498(u32 item_id, u32 value, u32 extra)
{
    u32 *entry = func_800D21D0();
    *(u16 *) ((u8 *) entry + 4) = value;
    *(float *) ((u8 *) entry + 8) = (s32) value;
    *(u16 *) ((u8 *) entry + 6) = extra;
    func_800D22E0(entry, item_id);
}

// Sets the target value and extra of a counter and shows it (unused entries have target -1).
s32 func_800D24E8(Gtexture *item_id, s32 value, s32 extra)
{
    s32 result;
    s16 *entry;
    entry = func_800D21D0(item_id);
    if (entry[2] < 0) {
        func_800D2498((u32) item_id, value, extra);
    } else {
        entry[2] = value;
        entry[3] = extra;
        result = func_800D22E0(entry, item_id);
        if (result == 0) {
            *(f32 *) &entry[4] = entry[2];
        }
        return result;
    }
}

// Per frame: rolls the displayed value of each shown counter toward its target.
void func_800D2574(void)
{
    s32 i;
    s32 slot;
    s32 item_id;
    f32 dt;
    f32 diff;
    f32 dir;
    dt = func_800D8FF8();
    for (i = 0; i < 91; i++) {
        item_id = i + 0xC0;
        slot = func_800D21F0(item_id, D_8011AFB0[i].group);
        if (slot < 0)
            continue;
        if (func_800FA8E8(slot, D_8011AFB0[i].sub_type) != 1) {
            D_8012B2C0[slot] = -1;
            continue;
        }
        if (func_800FA874(slot, D_8011AFB0[i].sub_type)) {
            if (D_8011AFB0[i].target != (s32) D_8011AFB0[i].displayed) {
                diff = D_8011AFB0[i].target - D_8011AFB0[i].displayed;
                dir = diff >= 0.0f ? 1.0f : -1.0f;
                D_8011AFB0[i].displayed +=
                    dir * MIN_D2574(1.0f, MAX_D2574(diff, 8.0f) * dt);
                func_800D22E0(&D_8011AFB0[i], item_id);
            }
        }
    }
}

int func_800D2748(s32 item_id, s32 sub_type)
{
    u8 *field;
    field = func_800D21D0(item_id);
    field++;
    *field = sub_type;
}

// Sets the value immediately, without rolling.
void func_800D2770(s32 item_id, s32 value)
{
    void *entry;
    entry = func_800D21D0(item_id);
    // Matching: the temporary in its own block is needed for the match.
    {
        float value_f;
        value_f = (float) value;
        *(float *) ((char *) entry + 8) = value_f;
    }
    *(s16 *) ((char *) entry + 4) = value;
}

s32 func_800D27A4(s32 item_id)
{
    u8 *entry = func_800D21D0(item_id);
    return entry[1];
}

// Returns the slot showing the item, or -1.
int func_800D27C8(u8 *item_id)
{
    u8 *entry;
    entry = func_800D21D0();
    func_800D21F0(item_id, *entry);
}

void func_800D27F4(s32 item_id)
{
    func_800D23E8(func_800D21D0(), item_id);
}

void func_800D2820(s32 item_id)
{
    func_800D2398(func_800D21D0(), item_id);
}

int func_800D284C(u32 item_id)
{
    u8 *entry = func_800D21D0(item_id);
    int slot = func_800D21F0(item_id, entry[0]);
    return (slot >= 0) && (func_800FA818(slot, entry[1]) == 1);
}

int func_800D28A0(u8 *item_id)
{
    u8 *entry;
    int slot;
    entry = func_800D21D0();
    slot = func_800D21F0(item_id, *entry);
    if (slot >= 0) {
        func_800FAA74(slot);
        return 1;
    }
    return 0;
}

u32 func_800D28E8(s32 item_id)
{
    u8 *entry = func_800D21D0(item_id);
    return entry[2];
}

// TU-NOTE: .data is defined here in C (values from the ROM). D_8011B460 is a linker
// symbol for D_8011B45C + 0x4.
EntryD2574 D_8011AFB0[91] = {
    0x9,  0x40, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x5B, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x58, 0x0,
    0x0,  0x0,  0.0f,  0xC,  0x0,  0x0,   0x0,  0x0,  0.0f,  0xD,  0x0,  0x0,   0x0,  0x0,  0.0f,
    0xE,  0x0,  0x0,   0x0,  0x0,  0.0f,  0xF,  0x0,  0x0,   0x0,  0x0,  0.0f,  0x9,  0x41, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x42, 0x0,   0x0,  0x0,  0.0f,  0x0,  0x37, 0x0,   0x0,  0x0,  0.0f,
    0x9,  0x2F, 0x0,   0x0,  0x0,  0.0f,  0x0,  0x5F, 0x0,   0x0,  0x0,  0.0f,  0xB,  0xE,  0x0,
    0x0,  0x0,  0.0f,  0x1,  0x1,  0x300, 0x0,  0x0,  0.0f,  0x0,  0x35, 0x0,   0x0,  0x0,  0.0f,
    0x0,  0x1,  0x200, 0x0,  0x0,  0.0f,  0x2,  0x2,  0x0,   0x0,  0x0,  0.0f,  0x4,  0x3,  0x800,
    0x0,  0x0,  0.0f,  0x5,  0x4,  0x800, 0x0,  0x0,  0.0f,  0x7,  0x5,  0x800, 0x0,  0x0,  0.0f,
    0x6,  0x6,  0x800, 0x0,  0x0,  0.0f,  0x8,  0x7,  0x800, 0x0,  0x0,  0.0f,  0xA,  0x8,  0x0,
    0x0,  0x0,  0.0f,  0x3,  0x9,  0x800, 0x0,  0x0,  0.0f,  0x3,  0xA,  0x800, 0x0,  0x0,  0.0f,
    0x9,  0xD,  0x0,   0x0,  0x0,  0.0f,  0x9,  0xC,  0x0,   0x0,  0x0,  0.0f,  0x9,  0x3B, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x38, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x3C, 0x0,   0x0,  0x0,  0.0f,
    0x9,  0x2A, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x2B, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x3D, 0x0,
    0x0,  0x0,  0.0f,  0xA,  0x18, 0x100, 0x0,  0x0,  0.0f,  0xA,  0x17, 0x100, 0x0,  0x0,  0.0f,
    0xA,  0xB,  0x100, 0x0,  0x0,  0.0f,  0xA,  0x1A, 0x100, 0x0,  0x0,  0.0f,  0xA,  0x16, 0x100,
    0x0,  0x0,  0.0f,  0xA,  0x14, 0x100, 0x0,  0x0,  0.0f,  0xA,  0x13, 0x100, 0x0,  0x0,  0.0f,
    0xA,  0x15, 0x100, 0x0,  0x0,  0.0f,  0xA,  0x19, 0x100, 0x0,  0x0,  0.0f,  0x9,  0x1E, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x8,  0x0,   0x0,  0x0,  0.0f,  0x9,  0x43, 0x0,   0x0,  0x0,  0.0f,
    0x9,  0x2C, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x3E, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x0,  0x0,
    0x0,  0x0,  0.0f,  0xE,  0x48, 0x0,   0x0,  0x0,  0.0f,  0xD,  0x49, 0x0,   0x0,  0x0,  0.0f,
    0xC,  0x4A, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x44, 0x0,   0x0,  0x0,  0.0f,  0xB,  0xE,  0x0,
    0x0,  0x0,  0.0f,  0x9,  0x12, 0x0,   0x0,  0x0,  0.0f,  0x10, 0xE,  0x0,   0x0,  0x0,  0.0f,
    0x9,  0x5B, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x58, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x27, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x28, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x45, 0x0,   0x0,  0x0,  0.0f,
    0x9,  0x2F, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x46, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x47, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x12, 0x0,   0x0,  0x0,  0.0f,  0xB,  0xE,  0x0,   0x0,  0x0,  0.0f,
    0x9,  0x4B, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x4C, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x4D, 0x0,
    0x0,  0x0,  0.0f,  0xB,  0xE,  0x0,   0x0,  0x0,  0.0f,  0x3,  0x29, 0x0,   0x0,  0x0,  0.0f,
    0xB,  0x55, 0x0,   0x0,  0x0,  0.0f,  0xB,  0x54, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x3F, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x4E, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x56, 0x0,   0x0,  0x0,  0.0f,
    0x9,  0x50, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x4F, 0x0,   0x0,  0x0,  0.0f,  0x9,  0x51, 0x0,
    0x0,  0x0,  0.0f,  0x9,  0x8,  0x0,   0x0,  0x0,  0.0f,  0x11, 0x52, 0x0,   0x0,  0x0,  0.0f,
    0x12, 0x53, 0x0,   0x0,  0x0,  0.0f,  0x13, 0x5B, 0x0,   0x0,  0x0,  0.0f,  0x14, 0x11, 0x0,
    0x0,  0x0,  0.0f,  0x15, 0x33, 0x0,   0x0,  0x0,  0.0f,  0x16, 0x1E, 0x0,   0x0,  0x0,  0.0f,
    0x17, 0x5B, 0x0,   0x0,  0x0,  0.0f,  0x18, 0x39, 0x0,   0x0,  0x0,  0.0f,  0x19, 0x3A, 0x0,
    0x0,  0x0,  0.0f,  0x12, 0x1D, 0x0,   0x0,  0x0,  0.0f,  0x0,  0x1,  0x700, 0x0,  0x0,  0.0f,
    0x8,  0x0,  0x0,   0x0,  0x0,  0.0f};
u32 D_8011B3F4[1] = {0x0};
u32 D_8011B3F8[1] = {0x1000000};
u32 D_8011B3FC[1] = {0x2000000};
u32 D_8011B400[1] = {0x3000000};
u32 D_8011B404[1] = {0x4000000};
u32 D_8011B408[1] = {0x5000000};
u32 D_8011B40C[1] = {0x6000000};
u32 D_8011B410[1] = {0x7000000};
u32 D_8011B414[1] = {0x8090000};
u32 D_8011B418[1] = {0x9080B2E};
u32 D_8011B41C[1] = {0xA000000};
u32 D_8011B420[1] = {0xB2E0908};
u32 D_8011B424[1] = {0xC000000};
u32 D_8011B428[1] = {0xD000000};
u32 D_8011B42C[1] = {0xE000000};
u32 D_8011B430[1] = {0xF000000};
u32 D_8011B434[1] = {0x10000000};
u32 D_8011B438[1] = {0x23000000};
u32 D_8011B43C[1] = {0x24000000};
u32 D_8011B440[1] = {0x25000000};
u32 D_8011B444[1] = {0x26000000};
u32 D_8011B448[1] = {0x27000000};
u32 D_8011B44C[1] = {0x28000000};
u32 D_8011B450[1] = {0x29000000};
u32 D_8011B454[1] = {0x2A000000};
u32 D_8011B458[1] = {0x2D000000};
E_D21F0 D_8011B45C[26] = {
    0x1, (void *) &D_8011B3F4, 0x1, (void *) &D_8011B3F8, 0x1, (void *) &D_8011B3FC,
    0x1, (void *) &D_8011B400, 0x1, (void *) &D_8011B404, 0x1, (void *) &D_8011B408,
    0x1, (void *) &D_8011B40C, 0x1, (void *) &D_8011B410, 0x2, (void *) &D_8011B414,
    0x4, (void *) &D_8011B418, 0x1, (void *) &D_8011B41C, 0x4, (void *) &D_8011B420,
    0x1, (void *) &D_8011B424, 0x1, (void *) &D_8011B428, 0x1, (void *) &D_8011B42C,
    0x1, (void *) &D_8011B430, 0x1, (void *) &D_8011B434, 0x1, (void *) &D_8011B438,
    0x1, (void *) &D_8011B43C, 0x1, (void *) &D_8011B440, 0x1, (void *) &D_8011B444,
    0x1, (void *) &D_8011B448, 0x1, (void *) &D_8011B44C, 0x1, (void *) &D_8011B450,
    0x1, (void *) &D_8011B454, 0x1, (void *) &D_8011B458};
