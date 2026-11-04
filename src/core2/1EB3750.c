// Game-flag storage: byte-array bit helpers, the global flag API over six flag blocks, save
// buffer serialization and a small heap-allocated bitset.
#include <ultra64.h>
#include "memory.h"
#include "core1/1E29B60.h"
#include "core2/1EB3750.h"

void _gldbDll_entrypoint_1(void);
void _gldbDll_entrypoint_2(void);
s32 _glgamedata_entrypoint_3(u8 *, s32, s32 *, u32 *);

// TU-NOTE: six flag blocks: D_8011B990 (32-bit word), D_8012C770[0..2] (heap blocks of 176/22/32 bytes),
// D_8012C780 (12 bytes, global flags) and D_8012C78C (6 bytes).
u32 D_8011B990 = 0;
s32 D_8011B994 = 0x6C9;

u8 *D_8012C770[3];
u8 D_8012C780[12];
u8 D_8012C78C[6];

#define D_8012C770_0_LENGTH (1408 / 8)
#define D_8012C770_1_LENGTH (176 / 8)
#define D_8012C770_2_LENGTH (256 / 8)

// Byte-array bit helpers and the heap-allocated bitset.
// Returns a single bit from a byte array.
s32 bitfield_get_bit(u8 *array, s32 index)
{
    s32 ret;
    if (array[index / 8] & (1 << (index & 7))) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

// Reads length bits starting at start_index into an integer.
s32 bitfield_get_n_bits(u8 *array, s32 start_index, s32 length)
{
    s32 ret = 0;
    s32 i;

    for (i = 0; i < length; i++) {
        ret |= (bitfield_get_bit(array, start_index + i) << i);
    }
    return ret;
}

// Sets or clears a single bit in a byte array.
void bitfield_set_bit(u8 *array, s32 index, s32 set)
{
    if (set) {
        array[index / 8] |= (1 << (index & 7));
    } else {
        array[index / 8] &= ~(1 << (index & 7));
    }
}

// Sets or clears length bits starting at start_index.
void bitfield_set_n_bits(u8 *array, s32 start_index, s32 set, s32 length)
{
    s32 i;

    for (i = 0; i < length; i++) {
        bitfield_set_bit(array, start_index + i, (1 << i) & set);
    }
}

// GameFlag get/set API, flag block alloc/free/reset and save-data copy in/out.
void func_800D9FFC(void)
{
    s32 i;
    s32 flags[1];
    flags[0] = D_8011B994;
    for (i = 0; i < ARRLEN(flags); i++) {
        func_800DA524(flags[i]);
    }
}

void func_800DA048(void)
{
    D_8011B990 = 0;
}

void func_800DA054(s32 block, s32 length)
{
    if (D_8012C770[block] == NULL) {
        D_8012C770[block] = heap_alloc_sided(length, 0);
    }
    rare_memset(D_8012C770[block], 0, length);
}

void func_800DA0B4(void)
{
    func_800DA054(0, D_8012C770_0_LENGTH);
}

void func_800DA0D8(void)
{
    func_800DA054(1, D_8012C770_1_LENGTH);
    _gldbDll_entrypoint_2();
}

void func_800DA104(void)
{
    func_800DA054(2, D_8012C770_2_LENGTH);
    _gldbDll_entrypoint_1();
}

void func_800DA130(void)
{
    if (func_8001210C(0x3FF) == 0x3FF) {
        _gldbDll_entrypoint_2();
    } else if (func_8001210C(0x7FF) == 0x7FF) { // Unreachable: if 0x3FF fails, 0x7FF fails too.
        _gldbDll_entrypoint_1();
    }
}

void func_800DA188(void)
{
    s32 i;

    for (i = 0; i < ARRLEN(D_8012C770); i++) {
        if (D_8012C770[i] != NULL) {
            heap_free(D_8012C770[i]);
            D_8012C770[i] = NULL;
        }
    }
}

void func_800DA1E0(void)
{
    s32 i;

    for (i = 0; i < ARRLEN(D_8012C770); i++) {
        if (D_8012C770[i] != NULL) {
            D_8012C770[i] = defrag(D_8012C770[i]);
        }
    }
}

void func_800DA238(void)
{
    s32 i;

    for (i = 0; i < ARRLEN(D_8012C780); i++) {
        D_8012C780[i] = 0;
    }
}

void func_800DA268(void)
{
    s32 i;

    for (i = 0; i < ARRLEN(D_8012C78C); i++) {
        D_8012C78C[i] = 0;
    }
}

// Get flag value.
s32 func_800DA298(GameFlag index)
{
    if ((index >= 0) && (index < 0x20)) {
        return ((1 << index) & D_8011B990) ? 1 : 0;
    }
    if ((index > 0x28) && (index < 0x5A5)) {
        return bitfield_get_bit(D_8012C770[0], index - 0x28);
    }
    if ((index > 0x640) && (index < 0x6ED)) {
        return bitfield_get_bit(D_8012C770[1], index - 0x640);
    }
    if ((index > 0x9C4) && (index < 0xAC4)) {
        return bitfield_get_bit(D_8012C770[2], index - 0x9C4);
    }
    if ((index > 0xBB8) && (index < 0xC16)) {
        return bitfield_get_bit(D_8012C780, index - 0xBB8);
    }
    if ((index > 0xD48) && (index < 0xD75)) {
        return bitfield_get_bit(D_8012C78C, index - 0xD48);
    }
    return 0;
}

// Set flag value.
void func_800DA3B8(GameFlag index, s32 set)
{
    if ((index >= 0) && (index < 0x20)) {
        if (set != 0) {
            D_8011B990 |= 1 << index;
        } else {
            D_8011B990 &= ~(1 << index);
        }
    } else if ((index > 0x28) && (index < 0x5A5)) {
        bitfield_set_bit(D_8012C770[0], index - 0x28, set);
    } else if ((index > 0x640) && (index < 0x6ED)) {
        bitfield_set_bit(D_8012C770[1], index - 0x640, set);
    } else if ((index > 0x9C4) && (index < 0xAC4)) {
        bitfield_set_bit(D_8012C770[2], index - 0x9C4, set);
    } else if ((index > 0xBB8) && (index < 0xC16)) {
        if (bitfield_get_bit(D_8012C780, index - 0xBB8) != set) {
            func_800DA544(FLAG5_D54_IF_GLOBALFLAGS_CHANGED);
        }
        bitfield_set_bit(D_8012C780, index - 0xBB8, set);
    } else if ((index > 0xD48) && (index < 0xD75)) {
        bitfield_set_bit(D_8012C78C, index - 0xD48, set);
    }
}

// Clear flag.
void func_800DA524(GameFlag index)
{
    func_800DA3B8(index, 0);
}

// Set flag.
void func_800DA544(GameFlag index)
{
    func_800DA3B8(index, 1);
}

// Get length flag bits starting at start_index as an integer.
s32 func_800DA564(GameFlag start_index, s32 length)
{
    if ((start_index >= 0) && (start_index < 0x20)) {
        s32 ret = 0;
        s32 i;

        for (i = 0; i < length; i++) {
            ret |= ((D_8011B990 & (1 << (start_index + i))) ? 1 : 0) << i;
        }
        return ret;
    } else if ((start_index > 0x28) && (start_index < 0x5A5)) {
        return bitfield_get_n_bits(D_8012C770[0], start_index - 0x28, length);
    } else if ((start_index > 0x640) && (start_index < 0x6ED)) {
        return bitfield_get_n_bits(D_8012C770[1], start_index - 0x640, length);
    } else if ((start_index > 0x9C4) && (start_index < 0xAC4)) {
        return bitfield_get_n_bits(D_8012C770[2], start_index - 0x9C4, length);
    } else if ((start_index > 0xBB8) && (start_index < 0xC16)) {
        return bitfield_get_n_bits(D_8012C780, start_index - 0xBB8, length);
    } else if ((start_index > 0xD48) && (start_index < 0xD75)) {
        return bitfield_get_n_bits(D_8012C78C, start_index - 0xD48, length);
    } else {
        return 0;
    }
}

// Set length flag bits starting at start_index from set.
void func_800DA7A8(GameFlag start_index, s32 set, s32 length)
{
    if ((start_index >= 0) && (start_index < 0x20)) {
        s32 i = 0;
        // Matching: no-op init expression in the for loop.
        for (0; i < length; i++) {
            func_800DA3B8(start_index + i, (1 << i) & set);
        }
    } else if ((start_index > 0x28) && (start_index < 0x5A5)) {
        bitfield_set_n_bits(D_8012C770[0], start_index - 0x28, set, length);
    } else if ((start_index > 0x640) && (start_index < 0x6ED)) {
        bitfield_set_n_bits(D_8012C770[1], start_index - 0x640, set, length);
    } else if ((start_index > 0x9C4) && (start_index < 0xAC4)) {
        bitfield_set_n_bits(D_8012C770[2], start_index - 0x9C4, set, length);
    } else if ((start_index > 0xBB8) && (start_index < 0xC16)) {
        if (bitfield_get_n_bits(D_8012C780, start_index - 0xBB8, length) != set) {
            func_800DA544(FLAG5_D54_IF_GLOBALFLAGS_CHANGED);
        }
        bitfield_set_n_bits(D_8012C780, start_index - 0xBB8, set, length);
    } else if ((start_index > 0xD48) && (start_index < 0xD75)) {
        bitfield_set_n_bits(D_8012C78C, start_index - 0xD48, set, length);
    }
}

// Increment the length-bit value at start_index; returns the new value.
s32 func_800DA944(GameFlag start_index, s32 length)
{
    s32 ret = func_800DA564(start_index, length) + 1;
    func_800DA7A8(start_index, ret, length);
    return ret;
}

// Count set flags in the range.
s32 func_800DA980(GameFlag start_index, s32 length)
{
    s32 ret = 0;
    s32 i;

    for (i = 0; i < length; i++) {
        ret += func_800DA298(i + start_index);
    }

    return ret;
}

// Returns the previous flag value and sets the new one.
s32 func_800DA9E4(GameFlag index, s32 set)
{
    s32 ret = func_800DA298(index);
    func_800DA3B8(index, set);
    return ret;
}

s32 func_800DAA1C(void)
{
    return D_8011B990;
}

void func_800DAA28(s32 val)
{
    D_8011B990 = val;
}

typedef struct {
    s32 num_bits;
    u32 words[];
} BitFieldBuffer;

BitFieldBuffer *func_800DAA34(s32 num_bits)
{
    BitFieldBuffer *bitfield = heap_alloc(((num_bits + 31) >> 5) * sizeof(u32) + sizeof(BitFieldBuffer));
    bitfield->num_bits = num_bits;
}

void func_800DAA6C(BitFieldBuffer *bitfield)
{
    heap_free(bitfield);
}

void func_800DAA8C(BitFieldBuffer *bitfield, s32 num_bits, s32 length)
{
    s32 i;

    bitfield->num_bits = num_bits;
    for (i = 1; i < length; i++) {
        bitfield->words[i - 1] = 0;
    }
}

void func_800DAAF8(BitFieldBuffer *bitfield, s32 index, s32 set)
{
    if (set) {
        bitfield->words[index >> 5] |= 1 << (index & 0x1F);
    } else {
        // Matching: subtracts the masked bit instead of using &= ~.
        bitfield->words[index >> 5] -= (bitfield->words[index >> 5] & (1 << (index & 0x1F)));
    }
}

s32 func_800DAB54(BitFieldBuffer *bitfield, s32 index)
{
    return (bitfield->words[index >> 5] & (1 << (index & 0x1F))) ? 1 : 0;
}

void func_800DAB8C(BitFieldBuffer *bitfield, s32 set)
{
    s32 i;
    for (i = 0; i < bitfield->num_bits; i++) {
        func_800DAAF8(bitfield, i, set);
    }
}

void func_800DABF0(s32 *out_length, u8 **out_data)
{
    *out_length = ARRLEN(D_8012C780);
    *out_data = D_8012C780;
}

s32 func_800DAC08(void)
{
    return D_8012C770_0_LENGTH;
}

void func_800DAC10(u8 *src, s32 length)
{
    s32 length_clamped;
    length_clamped = MIN(D_8012C770_0_LENGTH, length);
    rare_memcpy(D_8012C770[0], src, length_clamped);
}

void func_800DAC50(u8 *dst)
{
    rare_memcpy(dst, D_8012C770[0], D_8012C770_0_LENGTH);
}

// Reads a flag from a save image.
s32 func_800DAC78(u8 *save, s32 index)
{
    s32 offset;
    u32 unk_0;
    if (_glgamedata_entrypoint_3(save, 6, &offset, &unk_0)) {
        return bitfield_get_bit(save + offset, index - 0x28);
    } else {
        return -1;
    }
}
