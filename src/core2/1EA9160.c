// Collectible registry: 9 categories (0 Jinjo, 1 Jiggy, 2-5, 6 note nests, 7, 8), each with an index range and per-category tables.
#include "core2/1EA9160.h"
extern s32 func_80106790(s32);
void func_800DA544(s32);

extern s16 D_8011AE64[];
extern s16 D_8011AE6C[];
extern s16 D_8011AE74[];
extern s16 D_8011AE76;
extern struct {
    s16 unk0;
    s16 unk2;
} D_8011AE84[32];
typedef struct {
    u8 field_0, field_1, field_2;
} LocalRecord;
extern void func_800DC324(s32);
void _subaddieDll_entrypoint_4(Actor *, s32);
extern u8 D_8011AB40[];
extern u8 D_8011ABC8[];
extern u8 D_8011AC7C[];
extern u8 D_8011ACB0[];
extern u8 D_8011ACD4[];
extern u8 D_8011AD08[];
typedef struct {
    u8 field0, pad[2];
} LocalThree;
typedef struct {
    u8 field0, field1;
} LocalTwo;
extern LocalThree D_8011AB3D[];
extern LocalTwo D_8011ABC6[];
extern LocalTwo D_8011AC7A[];
extern LocalTwo D_8011ACAE[];
extern LocalTwo D_8011ACD2[];
extern s32 _chnests_entrypoint_13(s32);
extern s32 func_800EA05C(void);
extern u8 D_8012B190[];
struct D_8012B18C_struct {
    int a;
    int b;
    int c;
    int d;
    int e;
};
extern struct D_8012B18C_struct D_8012B18C[];
extern f32 D_8012B180[3];
extern u8 D_8011AB3F[];
extern u8 D_8011ABC7[];
extern u8 D_8011ACD3[];
extern u8 D_8011AC7B[];
extern u8 D_8011ACAF[];
extern u8 D_8011AE3B[];
extern u8 D_8011AE5B[];
extern s32 D_8011AF28[];
extern s32 D_8011AF04[];
extern s32 func_800D395C(void);
extern s32 func_800DA298(u32);
extern s32 _glcutDll_entrypoint_20(void);
extern void func_800DA524(s32);
extern void func_800FC660(u32);
extern u8 D_8011AB3E[];

extern s32 D_8011AE60;

// Sets the first jiggy index of the 10 movable-jiggy slots.
void func_800CF870(s32 base)
{
    D_8011AE60 = base;
}

s32 func_800CF87C()
{
    return D_8011AE60;
}

// Checks (index, category) against a small pair table; 1 if found.
// Matching: the line breaks in this function are needed for the match.
s32 func_800CF888(s32 index, s32 category)
{
    s16 *entry;
    do { entry = D_8011AE64; loop_1: if ((index == entry[0]) && (category == entry[1])) { return 1; } entry += (0, 2); if (entry == D_8011AE6C) { return entry[0] * 0; } } while (0);
    goto loop_1;
}

// Checks (index, category) against a small pair table; 1 if found.
// Matching: the line breaks in this function are needed for the match.
s32 func_800CF8D0(s32 index, s32 category)
{
    s16 *entry;
    do { entry = D_8011AE6C; loop_1: if ((index == entry[0]) && (category == entry[1])) { return 1; } entry += (0, 2); if (entry == D_8011AE74) { return entry[0] * 0; } } while (0);
    goto loop_1;
}

// Entry number (0-8) of (index, category) in the table at D_8011AE74, -1 if absent.
s32 func_800CF918(index, category)
s32 index;
s32 category;
{
    s32 entry_idx;
    struct {
        s16 unk0;
        s16 unk2;
    } *entry;
    if ((index == *(s16 *) D_8011AE74) && (category == D_8011AE76)) {
        return 0;
    }
    entry_idx = 1;
    entry = &D_8011AE84;
loop_4:
    if ((index == entry->unk0) && (category == entry->unk2)) {
        return entry_idx;
    }

    if ((index == entry[4].unk0) && (category == entry[4].unk2)) {
        return entry_idx + 1;
    }
    if ((index == entry[8].unk0) && (category == entry[8].unk2)) {
        return entry_idx + 2;
    }
    if ((index == entry[12].unk0) && (category == entry[12].unk2)) {
        return entry_idx + 3;
    }
    entry_idx += 4;
    entry += 0x10;
    if (entry_idx == 9) {
        return -1;
    }
    goto loop_4;
}

// Matching: index is reused as the loop counter.
void func_800CF9E4(s32 index, s32 category, s32 target)
{
    u8 *entry;
    s32 unk_0[3];
    s32 entry_idx;
    entry_idx = func_800CF918(index, category);
    for (index = 0; index < 3; index++)
        unk_0[index] = ((u8 *) D_8011AE74)[entry_idx * 16 + 12 + index];
    entry = (u8 *) D_8011AE74 + entry_idx * 16;
    func_800C8D4C(target, entry + 4);
    func_800C8E84(target, unk_0);
    func_800C8F64(target, entry[15]);
}

// Matching: the argument-less call is needed for the match.
void func_800CFA70()
{
    func_800CF918();
}

// Assigns each of the 45 Jinjos a family 0-8; family f gets f + 1 members.
// The RNG is seeded from a saved value.
s32 func_800CFA90(void)
{
    s32 family_count[9];
    s32 seed;
    s32 family;
    s32 i;

    if (func_800DA9E4(0x6A0, 1)) {
        return 0;
    }
    if (!func_800DA298(0x379)) {
        seed = func_800DC128(0, 0x21);
        func_800DA7A8(0x37A, seed, 5);
        func_800DA544(0x379);
    } else {
        seed = func_800DA564(0x37A, 5);
    }
    func_800DC330();
    func_800DC324(seed);
    for (i = 0; i < 9; i++) {
        family_count[i] = 0;
    }
    for (i = 0; i < 45; i++) {
        family = func_800DC128(0, 9);
        while (family < family_count[family]) {
            family = func_800DC128(0, 9);
        }
        family_count[family]++;
        ((LocalRecord *) D_8011AB40)[i].field_1 = family;
    }
    func_800DC354();
    return 1;
}

void func_800CFBC8(Actor *actor, u32 index, s32 category, s32 unk_0)
{
    func_8010108C(actor, 0x13, index);
    if (func_800CF888(index, category)) {
        _subaddieDll_entrypoint_4(actor, 1);
    }
    if (func_800CF8D0(index, category)) {
        func_8010108C(actor, 0x12, 1);
    }
    if (func_800CF918(index, category) != -1) {
        func_8010108C(actor, 0x55, 1);
    }
}

// Movable-jiggy slot (0-9) for a jiggy index, -1 if out of range.
s32 func_800CFC5C(s32 index)
{
    index -= D_8011AE60;
    if (-1 < index && index < 0xA) {
        return index;
    }
    return -1;
}

// Counts the items of a category located in a world (note nests weighted by value).
u32 func_800CFC8C(s32 category, s32 world)
{
    s32 nest_id;
    s32 last;
    s32 i;
    s32 count;
    u8 entry_world;
    u8 *entry;
    count = 0;
    switch (category) {
        case 0:
            i = func_800D0820(category);
            if (func_800D0894(category) >= i) {
                entry = D_8011AB40 + (i * 3);
                do {
                    entry_world = *(u8 *) ((s8 *) entry + -3);
                    i += 1;
                    entry += 3;
                    if (world == (entry_world & 0xFF)) {
                        count += 1;
                    }
                } while (func_800D0894(category) >= i);
            }
            return count;

        case 1:
            i = func_800D0820(category);
            if (func_800D0894(category) >= i) {
                entry = D_8011ABC8 + (i * 2);
                do {
                    if (world == entry[-2]) {
                        count += 1;
                    }
                    i += 1;
                    entry += 2;

                } while (func_800D0894(category) >= i);
            }
            return count;

        case 2:
            i = func_800D0820(category);
            if (func_800D0894(category) >= i) {
                entry = D_8011AC7C + (i * 2);
                do {
                    if (world == entry[-2]) {
                        count += 1;
                    }
                    i += 1;
                    entry += 2;

                } while (func_800D0894(category) >= i);
            }
            return count;

        case 3:
            i = func_800D0820(category);
            if (func_800D0894(category) >= i) {
                entry = D_8011ACB0 + (i * 2);
                do {
                    if (world == entry[-2]) {
                        count += 1;
                    }
                    i += 1;
                    entry += 2;
                } while (func_800D0894(category) >= i);
            }
            return count;

        case 4:
            i = func_800D0820(category);
            if (func_800D0894(category) >= i) {
                entry = D_8011ACD4 + (i * 2);
                do {
                    if (world == entry[-2]) {
                        count += 1;
                    }
                    i += 1;
                    entry += 2;
                } while (func_800D0894(category) >= i);
            }
            return count;

        case 5:
            last = func_800D0894(category);
            return (last - func_800D0820(category)) + 1;

        case 6:
            i = func_800D0820(category);
            if (func_800D0894(category) >= i) {
                entry = D_8011AD08 + (i * 2);
                do {
                    if (world == *(u8 *) ((s8 *) entry + -2)) {
                        if (*(u8 *) ((s8 *) entry + -1) != 0) {
                            nest_id = 0x1DA;
                        } else {
                            nest_id = 0x1D9;
                        }
                        count += _chnests_entrypoint_13(nest_id);
                    }
                    i += 1;
                    entry += 2;
                } while (func_800D0894(category) >= i);
            }
            return count;

        case 7:
            last = func_800D0894(category);
            return (last - func_800D0820(category)) + 1;

        case 8:
            last = func_800D0894(category);
            return (last - func_800D0820(category)) + 1;

        default:
            return -1;
    }
}

// True if index lies within the index range of the category.
s32 func_800CFFBC(index, category)
s32 category;
{
    s32 last;
    if (index >= func_800D0820(category | 0)) {
        last = func_800D0894(category);
        if (!(last < index)) {
            return 1;
        }
    }
    return 0;
}

// TU-NOTE: the header prototype takes the category as s32, not s16 (also push core2/1EA9160.h).
// Counts the collected items of a category in a world.
s32 func_800D0018(s32 category, s32 world)
{
    s32 i;
    s32 count = 0;
    switch (category) {
        case 0:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category) && world == D_8011AB3D[i].field0)
                    count++;
            }
            return count;
        case 1:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category) && world == D_8011ABC6[i].field0)
                    count++;
            }
            return count;
        case 2:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category) && world == D_8011AC7A[i].field0)
                    count++;
            }
            return count;
        case 3:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category) && world == D_8011ACAE[i].field0)
                    count++;
            }
            return count;
        case 4:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category) && world == D_8011ACD2[i].field0)
                    count++;
            }
            return count;
        case 6:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category) &&
                    world == ((LocalTwo *) D_8011AD08)[i - 1].field0)
                    count += _chnests_entrypoint_13(
                        ((LocalTwo *) D_8011AD08)[i - 1].field1 ? 0x1DA : 0x1D9);
            }
            return count;
        default:
            for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
                if (func_800D0B68(i, category))
                    count++;
            }
            return count;
    }
}

// Counts the collected items of a category (note nests weighted by value).
s32 func_800D035C(s32 category)
{
    s32 i;
    s32 count = 0;
    if (category == 6) {
        for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
            if (func_800D0B68(i, category)) {
                count += _chnests_entrypoint_13(D_8011AD08[i * 2 - 1] ? 0x1DA : 0x1D9);
            }
        }
    } else {
        for (i = func_800D0820(category); i <= func_800D0894(category); i++) {
            if (func_800D0B68(i, category))
                count++;
        }
    }
    return count;
}

// Matching: the `| 0` operands are needed for the match.
int func_800D046C(s32 unk_0, s32 index, s32 category)
{
    s32 flag;
    flag = func_800D0A80(index | 0, category | 0);
    func_800DAC78(unk_0, flag | 0);
}

// Matching: the parameter copies and the `| s1` operands are needed for the match.
int func_800D04A0(s32 unk_0, s32 category)
{
    s32 i;
    s32 cat;
    s32 count;
    s32 last;
    s32 unk_1;

    unk_1 = unk_0;
    cat = category;
    count = 0;
    i = func_800D0820(cat | cat);
    last = func_800D0894(cat | cat);
    if (last >= i) {
        do {
            if (func_800D046C(unk_1, i, cat) == 1) {
                count++;
            }
            i++;
            last = func_800D0894(cat | cat);
        } while (last >= i);
    }

    return count;
}

// Movable-jiggy slot data: position in D_8012B180, actor in D_8012B18C, marker in D_8012B190.
void func_800D053C(u32 index, u32 category)
{
    s32 slot;
    if (category == 1) {
        slot = func_800CFC5C(index);
        if (slot != -1) {
            *(u16 *) &D_8012B190[slot * 20] = (u16) (short) func_800EA05C();
        }
    }
}

void func_800D0594(s32 index, s32 category, short marker)
{
    s32 slot;
    if (category == 1) {
        slot = func_800CFC5C(index);
        if (slot != -1) {
            *(s16 *) ((char *) &D_8012B190 + (slot * 20)) = marker;
        }
    }
}

void func_800D05E4(s32 index, long category, s32 actor)
{
    if (category == 1) {
        s32 slot = func_800CFC5C(index);
        if (slot != -1) {
            D_8012B18C[slot].a = actor;
        }
    }
}

// Matching: the chain of `& 0xFFFFFFFFFFFFFFFF` masks is needed for the match.
s32 func_800D0634(u32 index, u32 category)
{
    int word_index2;
    int word_index;
    s32 slot;
    if (category == 1) {
        slot = func_800CFC5C(index);
        if (slot != -1) {
            word_index = (((((((slot * 5) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) &
                          0xFFFFFFFFFFFFFFFF) &
                         0xFFFFFFFFFFFFFFFF) &
                        0xFFFFFFFFFFFFFFFF) &
                       0xFFFFFFFFFFFFFFFF) &
                      0xFFFFFFFFFFFFFFFF;
            word_index2 = word_index & 0xFFFFFFFFFFFFFFFF;
            return (
                (s32 *) D_8012B18C)[((word_index2 & 0xFFFFFFFFFFFFFFFF) & (short) 0xFFFFFFFFFFFFFFFF) &
                                    0xFFFFFFFFFFFFFFFF];
        }
    }
    return 0;
}

s32 func_800D0684(s32 index, s32 category)
{
    s32 slot;
    if (category == 1) {
        slot = func_800CFC5C(index);
        if (slot != -1) {
            return *(s16 *) ((char *) (s16 *) D_8012B190 + slot * 20);
        }
    }
    return 0;
}

// World of an item, -1 if the category has none.
s32 func_800D06D4(s32 index, s32 category)
{
    switch (category) {
        case 1:
            return ((u8 *) D_8011ABC6)[index * 2];

        case 0:
            return ((u8 *) D_8011AB3D)[index * 3];

        case 4:
            return ((u8 *) D_8011ACD2)[index * 2];

        case 3:
            return ((u8 *) D_8011ACAE)[index * 2];

        case 2:
            return ((u8 *) D_8011AC7A)[index * 2];

        case 5:
            return 0x10;

        case 6:
            return -1;

        default:
            return -1;
    }
}

// Writes pos into the slot position.
void func_800D0778(s32 index, s32 category, s32 *pos)
{
    s32 slot;

    if (category == 1) {
        slot = func_800CFC5C(index);
        if (slot != -1) {
            func_800EE7F8((f32 *) ((u8 *) &D_8012B180 + slot * 0x14), pos);
        }
    }
}

// Reads the slot position into pos.
void func_800D07CC(s32 index, s32 category, s32 *pos)
{
    s32 slot;

    if (category == 1) {
        slot = func_800CFC5C(index);
        if (slot != -1) {
            func_800EE7F8(pos, (u8 *) D_8012B180 + slot * 0x14);
        }
    }
}

// First index of a category (1-based).
s32 func_800D0820(category)
s32 category;
{
    switch (category) {
        case 0:
            return 1;

        case 1:
            return 1;

        case 2:
            return 1;

        case 3:
            return 1;

        case 4:
            return 1;

        case 5:
            return 1;

        case 6:
            return 1;

        case 7:
            return 1;

        case 8:
            return 1;

        default:
            return -1;
    }
}

// Last index of a category, i.e. its item count.
s32 func_800D0894(category)
s32 category;
{

switch (category) {
    case 0:
        return 0x2D;
    case 1:
        return 0x5A;
    case 2:
        return 0x19;
    case 3:
        return 0x11;
    case 4:
        return 0x19;
    case 5:
        return 0x19;
    case 6:
        return 0x99;
    case 7:
        return 0x1E;
    case 8:
        return 0x4;
}

return -1;
}

// Game flag for an item taken from the per-item table byte, 0 if none.
// Matching: the per-category offset temporaries are needed for the match.
s32 func_800D0908(index, category)
s32 index;
s32 category;
{
    s32 off_1;
    s32 off_4;
    s32 off_2;
    s32 off_0;
    s32 off_3;
    off_0 = index * 3;
    off_1 = index << 1;
    off_4 = index << 1;
    off_2 = index << 1;
    off_3 = index << 1;

switch (category) {
    case 0:
        if (D_8011AB3F[off_0]) {
            return D_8011AF28[category] + D_8011AB3F[off_0] - 1;
        }
        break;

    case 1:
        if (D_8011ABC7[off_1]) {
            return D_8011AF28[category] + D_8011ABC7[off_1] - 1;
        }
        break;

    case 4:
        if (D_8011ACD3[off_4]) {
            return D_8011AF28[category] + D_8011ACD3[off_4] - 1;
        }
        break;

    case 2:
        if (D_8011AC7B[off_2]) {
            return D_8011AF28[category] + D_8011AC7B[off_2] - 1;
        }
        break;

    case 3:
        if (D_8011ACAF[off_3]) {
            return D_8011AF28[category] + D_8011ACAF[off_3] - 1;
        }
        break;

    case 7:
        if (D_8011AE3B[index]) {
            return D_8011AF28[category] + D_8011AE3B[index] - 1;
        }
        break;

    case 8:
        if (D_8011AE5B[index]) {
            return D_8011AF28[category] + D_8011AE5B[index] - 1;
        }
}

return 0;
}

// Collected game flag for an item.
s32 func_800D0A80(index, category)
s32 index;
s32 category;
{
    return D_8011AF04[category] + index - 1;
}

s32 func_800D0A9C(u32 index, u32 category)
{
    s32 flag;
    flag = func_800D0908(index, category);
    if (flag == 0)
        return 1;
    return (func_800DA298(flag) || _glcutDll_entrypoint_20() || func_800D395C()) ? 1 : 0;
}

// Matching: the argument-less call to func_800D0908 is needed for the match.
int func_800D0B08()
{
    s32 flag;
    extern s32 func_800D0908();
    flag = func_800D0908();

if (flag != 0) {
    func_800DA544(flag);
}

}

void func_800D0B38(s32 index, s32 category)
{
    s32 flag = func_800D0908(index, category);

if (flag != 0) {
    func_800DA524(flag);
}

}

// 1 if the item is collected, 0 if not, -1 if it has no flag.
s32 func_800D0B68(index, category)
u32 index;
u32 category;
{
    s32 flag;
    flag = func_800D0A80(index, category);
    if (flag == 0)
        return -1;
    return (func_800DA298(flag) || _glcutDll_entrypoint_20() || func_800D395C()) ? 1 : 0;
}

// Sets the collected flag, updates the HUD count and notifies 0xB7.
void func_800D0BD4(s32 index, u32 category)
{
    s32 flag;
    flag = func_800D0A80(index, category);

if (flag != 0) {
    func_800DA544(flag);
    if (category != 0) {
        if (category != 1) {
            if (category == 6) {
                func_800D24E8(0xD0, func_800D035C(6), 0);
            }
        } else {
            func_800D24E8(0xD6, func_800D035C(1), 0);
            goto block_6;
        }
    } else {
    block_6:
        func_80101238(0xB7, (index << 0x10) | (category & 0xFFFF));
    }
}

}

void func_800D0C78(u32 index, u32 category, u32 unk_0)
{
    if (category == 1) {
        func_800D0B08();
        func_800D0BD4(index, category);
        if (!unk_0) {
            func_800FC660(5);
        }
    }

}

// Family of a Jinjo.
int func_800D0CC8(s32 index)
{
    return D_8011AB3E[index * 3];
}

// Spawns the actor with the given id; spawn_mode picks the spawn function.
int func_800D0CE0(s32 actor_id, s32 pos, u32 spawn_mode, s32 *out_flag)
{
    *out_flag = 0;

switch (spawn_mode) {
    case 0:
        _chbounce_entrypoint_7(0x1C, pos, actor_id);
        break;
    case 1:
        _chbounce_entrypoint_7(0x1D, pos, actor_id);
        break;
    case 4:
        _chbounce_entrypoint_7(0x1E, pos, actor_id);
        break;
    case 3:
        *out_flag = 1;
    case 2:
        func_80108474(actor_id, pos, 0);
        break;
    case 5:
        _chbounce_entrypoint_7(0x1F, pos, actor_id);
        break;
    case 6:
        _chbounce_entrypoint_7(0x20, pos, actor_id);
        break;
    default:
        return 0;
}

}

// Spawns the collectible actor for a packed (index << 16 | category) id.
s32 func_800D0DAC(s32 packed_id, s32 *pos, u32 spawn_mode, u8 *parent)
{
    u16 category;
    s32 index;
    s32 *actor;
    s32 out_flag;

    category = packed_id;
    index = (packed_id >> 16) & 0xFFFF;

switch (category) {
    case 1:
        actor = func_800D0CE0(0x21F, pos, spawn_mode, &out_flag);
        if (out_flag == 0) {
            func_8010108C(actor, 0x14, 1);
        }
        func_800D05E4(index, category, *actor);
        break;
    case 0:
        actor = func_800D0CE0(0x1F4, pos, spawn_mode, &out_flag);
        if (out_flag == 0) {
            func_8010108C(actor, 0x14, 1);
        }
        break;
    case 4:
        actor = func_800D0CE0(0x136, pos, spawn_mode, &out_flag);
        if (out_flag == 0) {
            func_8010108C(actor, 0x14, 1);
        }
        break;
    case 2:
        actor = func_800D0CE0(0x220, pos, spawn_mode, &out_flag);
        break;
    case 3:
        actor = func_800D0CE0(0x21B, pos, spawn_mode, &out_flag);
        break;
    case 7:
        actor = func_800D0CE0(0x4E5, pos, spawn_mode, &out_flag);
        break;
    case 8:
        actor = func_800D0CE0(0x3C6, pos, spawn_mode, &out_flag);
        break;
    default:
        break;
}

func_800CFBC8(actor, index, category, 0);

if (parent != NULL && (*(u16 *) (parent + 0x18) & 1)) {
    func_80101074(*actor);
    func_8010114C(parent, 0xD, packed_id);
}

return *actor;
}

void func_800D0F9C(s32 packed_id, s32 x, s32 y, s32 z, s32 spawn_mode, s32 parent)
{
    f32 unk_0;
    f32 pos[3];
    pos[0] = (f32) x;
    pos[1] = (f32) y;
    pos[2] = (f32) z;
    func_800D0DAC(packed_id, pos, spawn_mode, parent);
}

// Spawns an unflagged, uncollected item through the baddie setup (callback func_800D0F9C).
void func_800D1000(u32 index, u32 category, f32 *pos, u32 spawn_mode, Unk80132ED0 *parent)
{
    s32 pos_i[3];
    s32 unk_0;
    f32 slot_pos[3];

if ((func_800D0A9C(index, category) == 0) && (func_800D0B68(index, category) == 0)) {
    func_800D0B08(index, category);
    func_800D053C(index, category);
    if (pos != NULL) {
        func_800EE904(pos_i, pos);
    } else {
        func_800D07CC(index, category, slot_pos);
        func_800EE904(pos_i, slot_pos);
    }
    _chbaddiesetup_entrypoint_6(&func_800D0F9C, (index << 0x10) | (category & 0xFFFF), pos_i[0], pos_i[1],
                                pos_i[2], spawn_mode, parent);
}

}

// Spawns an unflagged, uncollected item; returns the actor handle or 0.
s32 func_800D10D4(s32 index, s32 category, s32 *pos, s32 spawn_mode, s32 parent)
{
    s32 slot_pos[4];

if (func_800D0A9C(index, category) != 0) {
    return 0;
}

if (func_800D0B68(index, category) != 0) {
    return 0;
}

func_800D0B08(index, category);
func_800D053C(index, category);

if (pos != NULL) {
    return func_800D0DAC((index << 0x10) | (category & 0xFFFF), pos, spawn_mode, parent);
}

func_800D07CC(index, category, slot_pos);
return func_800D0DAC((index << 0x10) | (category & 0xFFFF), slot_pos, spawn_mode, parent);

}

void func_800D119C(s32 index, s32 category)
{
    if (func_800D0B68(index, category) == 0 && func_800D0A9C(index, category) != 0) {
        if (category == 1) {
            func_800FFA88(func_800D0634(index, 1));
            func_800D05E4(index, 1, 0);
        }
        func_800D0B38(index, category);
    }

}

// Reads the position of the item actor into pos.
void func_800D1218(s32 index, s32 category, s32 pos)
{
    s32 handle;
    handle = func_800D0634(index, category);

if (handle != 0) {
    handle = func_80106790(handle);
    func_800EE7F8(pos, handle + 4);
}

}

// Moves the item actor to pos.
void func_800D1254(s32 index, s32 category, s32 pos)
{
    s32 handle;
    s32 actor;
    handle = func_800D0634(index, category);

if (handle != 0) {
    actor = func_80106790(handle);
    func_800EE7F8(actor + 4, pos);
    func_80103014(actor);
}

}

// Counts the Jinjos of a family.
s32 func_800D129C(u32 family)
{
    s32 first;
    s32 count;
    s32 i;
    count = 0;
    first = func_800D0820(0);
    i = first;

while (i <= func_800D0894(0)) {
    if (D_8011AB40[i * 3 - 2] == family) {
        count++;
    }
    i++;
}

return count;
}

// Counts the collected Jinjos of a family.
u32 func_800D1338(u32 family)
{
    s32 i;
    s32 count;
    count = 0;
    i = func_800D0820(0);

while (func_800D0894(0) >= i) {
    if (family == D_8011AB40[i * 3 - 2]) {
        if (func_800D0B68(i, 0) != 0) {
            count++;
        }
    }
    i++;
}

return count;
}

// Category 6 only: index just before the first nest of a world, else 0.
s32 func_800D13E8(s32 category, s32 world)
{
    s32 i;

if (category == 6) {
    i = func_800D0820(category);
    while (func_800D0894(category) >= i) {
        if (((u8 *) D_8011AD08)[(i * 2) - 2] == world) {
            i--;
            return i;
        }
        i++;
    }
}

return 0;
}

// TU-NOTE: the data below is defined here in C (values from the ROM). Labels inside an object are linker symbols
// in undefined_syms.us.txt: D_8011AB3D/3E/3F = D_8011AB30 + 0xD/0xE/0xF, D_8011ABC6/7 = D_8011AB40 + 0x86/0x87,
// D_8011AC7A/B = D_8011ABC8 + 0xB2/0xB3, D_8011ACAE/F = D_8011AC7C + 0x32/0x33, D_8011ACD2/3 = D_8011ACB0 + 0x22/0x23,
// D_8011AE3B = D_8011AD08 + 0x133.
u32 D_8011AB30[4] = {0x40400000, 0x0, 0x0, 0x0};
u8 D_8011AB40[136] = {
    0x10, 0x9, 0x0, 0x10, 0x9, 0x0, 0x10, 0x9, 0x0, 0x10, 0x9, 0x0, 0x10, 0x9, 0x0, 0xF,  0x9, 0x0,
    0xF,  0x9, 0x0, 0xF,  0x9, 0x0, 0xF,  0x9, 0x0, 0xF,  0x9, 0x0, 0x12, 0x9, 0x0, 0x12, 0x9, 0x0,
    0x12, 0x9, 0x0, 0x12, 0x9, 0x0, 0x12, 0x9, 0x0, 0x14, 0x9, 0x0, 0x14, 0x9, 0x0, 0x14, 0x9, 0x0,
    0x14, 0x9, 0x0, 0x14, 0x9, 0x1, 0x15, 0x9, 0x0, 0x15, 0x9, 0x0, 0x15, 0x9, 0x0, 0x15, 0x9, 0x0,
    0x15, 0x9, 0x0, 0x16, 0x9, 0x0, 0x16, 0x9, 0x0, 0x16, 0x9, 0x0, 0x16, 0x9, 0x0, 0x16, 0x9, 0x0,
    0x17, 0x9, 0x0, 0x17, 0x9, 0x0, 0x17, 0x9, 0x0, 0x17, 0x9, 0x0, 0x17, 0x9, 0x0, 0x18, 0x9, 0x0,
    0x18, 0x9, 0x0, 0x18, 0x9, 0x0, 0x18, 0x9, 0x0, 0x18, 0x9, 0x0, 0x1A, 0x9, 0x0, 0x1A, 0x9, 0x0,
    0x1A, 0x9, 0x0, 0x1A, 0x9, 0x0, 0x13, 0x9, 0x0, 0x0};
u8 D_8011ABC8[180] = {
    0x10, 0x0,  0x10, 0x0,  0x10, 0x2,  0x10, 0x1,  0x10, 0x4,  0x10, 0x0,  0x10, 0x0,  0x10,
    0x0,  0x10, 0x0,  0x10, 0x3,  0xF,  0x6,  0xF,  0x5,  0xF,  0x0,  0xF,  0x0,  0xF,  0x2E,
    0xF,  0x14, 0xF,  0x0,  0xF,  0x0,  0xF,  0x0,  0xF,  0x0,  0x12, 0xC,  0x12, 0x10, 0x12,
    0x15, 0x12, 0x11, 0x12, 0x29, 0x12, 0x0,  0x12, 0xF,  0x12, 0x0,  0x12, 0x0,  0x12, 0x7,
    0x14, 0x2C, 0x14, 0x8,  0x14, 0xB,  0x14, 0x0,  0x14, 0x0,  0x14, 0xE,  0x14, 0x24, 0x14,
    0x9,  0x14, 0x0,  0x14, 0x22, 0x15, 0x0,  0x15, 0x0,  0x15, 0x12, 0x15, 0x18, 0x15, 0xD,
    0x15, 0x20, 0x15, 0x19, 0x15, 0x0,  0x15, 0x13, 0x15, 0x0,  0x16, 0x0,  0x16, 0x0,  0x16,
    0x31, 0x16, 0x2A, 0x16, 0x0,  0x16, 0x17, 0x16, 0x0,  0x16, 0x0,  0x16, 0x1F, 0x16, 0x0,
    0x17, 0x25, 0x17, 0x1A, 0x17, 0x16, 0x17, 0x2D, 0x17, 0x0,  0x17, 0x30, 0x17, 0x0,  0x17,
    0x1E, 0x17, 0x28, 0x17, 0x0,  0x18, 0x27, 0x18, 0x23, 0x18, 0x1C, 0x18, 0x2F, 0x18, 0x2B,
    0x18, 0x26, 0x18, 0x0,  0x18, 0x21, 0x18, 0x0,  0x18, 0x0,  0x1A, 0x0,  0x1A, 0x0,  0x1A,
    0x0,  0x1A, 0x0,  0x1A, 0x0,  0x1A, 0x0,  0x1A, 0x0,  0x1A, 0x0,  0x1A, 0x0,  0x1A, 0x1D};
u8 D_8011AC7C[52] = {0x10, 0x0,  0x10, 0x0,  0x10, 0x0,  0xF,  0x4,  0xF,  0x0,  0xF,  0x3,  0x12,
                     0x0,  0x12, 0x0,  0x12, 0x0,  0x14, 0x1,  0x14, 0x0,  0x14, 0x0,  0x15, 0x0,
                     0x15, 0x0,  0x15, 0x0,  0x16, 0x0,  0x16, 0x0,  0x16, 0x0,  0x17, 0x0,  0x17,
                     0x0,  0x17, 0x0,  0x18, 0x2,  0x18, 0x0,  0x18, 0x0,  0x1A, 0x0,  0x0,  0x0};
u8 D_8011ACB0[36] = {0x10, 0x0, 0x10, 0x0, 0xF,  0x0, 0xF,  0x0, 0x12, 0x0, 0x12, 0x0,
                     0x14, 0x0, 0x14, 0x0, 0x15, 0x0, 0x15, 0x0, 0x16, 0x0, 0x16, 0x0,
                     0x17, 0x0, 0x17, 0x0, 0x18, 0x0, 0x18, 0x0, 0x1A, 0x0, 0x0,  0x0};
u8 D_8011ACD4[52] = {0x10, 0x0,  0x10, 0x0,  0x10, 0x0,  0xF,  0x4,  0xF,  0x0,  0xF,  0x0,  0x12,
                     0x0,  0x12, 0x0,  0x12, 0x3,  0x14, 0x1,  0x14, 0x2,  0x14, 0x0,  0x15, 0x0,
                     0x15, 0x0,  0x15, 0x0,  0x16, 0x6,  0x16, 0x0,  0x16, 0x0,  0x17, 0x0,  0x17,
                     0x0,  0x17, 0x0,  0x18, 0x8,  0x18, 0x5,  0x18, 0x7,  0x13, 0x0,  0x0,  0x0};
u8 D_8011AD08[328] = {
    0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0,
    0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0,
    0x10, 0x1, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0,
    0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0, 0xF,  0x0,
    0xF,  0x0, 0xF,  0x1, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0,
    0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0, 0x12, 0x0,
    0x12, 0x0, 0x12, 0x0, 0x12, 0x1, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0,
    0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x0,
    0x14, 0x0, 0x14, 0x0, 0x14, 0x0, 0x14, 0x1, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0,
    0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0,
    0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x0, 0x15, 0x1, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0,
    0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0,
    0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x0, 0x16, 0x1, 0x17, 0x0, 0x17, 0x0,
    0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0,
    0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x0, 0x17, 0x1, 0x18, 0x0,
    0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0,
    0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x18, 0x1,
    0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0,
    0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0, 0x1A, 0x0,
    0x1A, 0x1, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,
    0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x1,  0x2};
