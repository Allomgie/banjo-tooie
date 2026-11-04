// ROM asset decompression: a 4-slot streaming loader, a full DEFLATE decoder and a synchronous
// load-and-inflate by asset id; also holds a stray getter for an unrelated global byte.
#include "common.h"
// TU-NOTE: ROM asset inflate: a 4-slot streaming loader (D_8012D560) driving a DEFLATE decoder.
// TU-NOTE: D_8012D564, D_8012D568 and D_8012D56C are slots 1-3 of D_8012D560, declared separately.
// TU-NOTE: the bit-reader macros below spell out local_7, local_8, param_0->local_0 and similar,
// so those names are kept.

#define NEED_E4(n) \
while (local_8 < n) { \
        if (param_0->local_1 >= 0x1800) { \
            param_0->local_1 = 0; \
            func_8001311C(param_0->local_0, param_0->local_10); \
            param_0->local_10 += 0x1800; \
    } \
        local_7 |= (u32)param_0->local_0[param_0->local_1++] << local_8; \
        local_8 += 8; \
}

#define DUMP_E4(n) local_7 >>= (n); local_8 -= (n);
#define NEEDBITS(n) { while (local_12 < (n)) { \
    if (param_0->cursor>=0x1800) { param_0->cursor=0; func_8001311C(param_0->input,param_0->rom); param_0->rom+=0x1800; } \
    local_13 |= (u32)param_0->input[param_0->cursor++] << local_12; local_12+=8; } }
#define DUMPBITS(n) { local_13 >>= (n); local_12 -= (n); }
#define NEED_BITS(n) \
while (local_2 < n) { \
        if (param_0->field_4 >= 0x1800) { \
            param_0->field_4 = 0; \
            func_8001311C(param_0->field_0, param_0->field_30); \
            param_0->field_30 += 0x1800; \
    } \
        local_1 |= (u32)param_0->field_0[param_0->field_4++] << local_2; \
        local_2 += 8; \
}

#define DUMP_BITS(n)                                                                               \
    local_1 >>= (n);                                                                               \
    local_2 -= (n);
extern void *D_8012D564;
extern void *D_8012D568;
extern void *D_8012D56C;
typedef struct LocalStream {
    u32 *input;
    s32 cursor;
    void *output;
    u32 bits, bit_count, written;
    void *literal, *distance;
    s32 literal_bits, distance_bits;
    void *pool;
    u32 count, rom;
    void *allocation;
    u8 state, final;
    s16 id, limit;
} LocalStream;
extern LocalStream *D_8012D560[];
extern void *heap_alloc(s32);
extern void heap_free();
extern u32 func_800D5A6C(s32);
typedef struct {
    void *input;
    u8 pad_4[0x24];
    void *pool;
    u8 pad_2C[8];
    void *allocation;
} S_E4B1C;
extern int D_8012D570;
extern int func_8001311C(s32, s32);
typedef struct HuftE4 {
    u8 e, b;
    union {
        u16 n;
        struct HuftE4 *t;
    } v;
} HuftE4;
typedef struct {
    u8 *local_0;
    s32 local_1;
    u8 *output;
    u32 bits, bit_count, written;
    HuftE4 *literal, *distance;
    s32 literal_bits, distance_bits;
    u8 pad_28[8];
    u32 local_10;
    u8 pad_34[8];
    s16 limit;
} StreamE4;
extern u16 D_801232C0[];
struct LocalHuft {
    u8 e, b;
    union {
        u16 n;
        struct LocalHuft *t;
    } v;
};
typedef struct {
    u8 pad_0[0x28];
    struct LocalHuft *pool;
    u32 count;
} LocalInflate_800E589C;
typedef struct {
    u8 *input;
    s32 cursor;
    u8 *output;
    u32 bits, bit_count, written;
    struct LocalHuft *literal, *distance;
    s32 literal_bits, distance_bits;
    struct LocalHuft *pool;
    u32 count, rom;
} LocalInflate_800E5EC0;
extern u8 D_801231F0[];
extern u16 D_80123204[];
extern u16 D_80123244[];
extern u16 D_80123264[];
extern u16 D_801232A0[];
typedef struct {
    u8 *field_0;
    s32 field_4;
    u8 *output;
    u32 bits, bit_count, written;
    u8 pad_18[0x18];
    u32 field_30;
} InflateStream;
extern u32 func_800D5950(s32);
extern void rom_read_word(u32, u32 *);
extern void func_800D5FDC(u32);
extern void func_80117248(u32, u32, void *);
extern u8 D_801275E0;
void func_800E4B1C();
s32 func_800E4D28();
s32 func_800E4E54();
s32 func_800E5EC0();
s32 func_800E659C();
s32 func_800E6728();

// Asynchronous 4-slot asset streaming state machine, slot lookup/free/defrag, load by asset id.
// Returns the slot streaming asset_id, or -1.
int func_800E4730(asset_id)
s32 asset_id;
{
    s32 stream;

    stream = *(u32 *) D_8012D560;
    if (stream != 0 && asset_id == *(s16 *) ((char *) stream + 0x3A)) {
        return 0;
    }

    stream = (u32) D_8012D564;
    if (stream != 0 && asset_id == *(s16 *) ((char *) stream + 0x3A)) {
        return 1;
    }

    stream = (u32) D_8012D568;
    if (stream != 0 && asset_id == *(s16 *) ((char *) stream + 0x3A)) {
        return 2;
    }

    stream = (u32) D_8012D56C;
    if (stream != 0 && asset_id == *(s16 *) ((char *) stream + 0x3A)) {
        return 3;
    }

    return -1;
}

// Returns the first free stream slot, or -1.
int func_800E47CC()
{
    s16 *stream;

    stream = *(void **) D_8012D560;
    if (stream == 0) {
        return 0;
    }
    if (*(s16 *) ((char *) stream + 0x3a) == -1) {
        return 0;
    }

    stream = D_8012D564;
    if (stream == 0) {
        return 1;
    }
    if (*(s16 *) ((char *) stream + 0x3a) == -1) {
        return 1;
    }

    stream = D_8012D568;
    if (stream == 0) {
        return 2;
    }
    if (*(s16 *) ((char *) stream + 0x3a) == -1) {
        return 2;
    }

    stream = D_8012D56C;
    if (stream == 0) {
        return 3;
    }
    if (*(s16 *) ((char *) stream + 0x3a) == -1) {
        return 3;
    }

    return -1;
}

// Advances the stream for asset_id by one step; returns 1 once decoding is complete.
s32 func_800E488C(s32 asset_id)
{
    s32 slot;
    LocalStream *stream;
    s32 unk_0[3];
    u32 value;
    s32 unk_1;

    slot = func_800E4730(asset_id);
    if (slot == -1) {
        // Not streaming yet: claim a free slot.
        slot = func_800E47CC();
        if (slot < 0)
            return 0;
        D_8012D560[slot] = heap_alloc(0x40);
        D_8012D560[slot]->state = 1;
        D_8012D560[slot]->id = asset_id;
        D_8012D560[slot]->limit = 0x9C4;
    }
    stream = D_8012D560[slot];
    if (stream->state == 0)
        return 1;
    switch (stream->state) {
        case 1:
            // Allocate buffers, read the first chunk and the output size from the header.
            stream->allocation = 0;
            stream->bits = 0;
            stream->bit_count = 0;
            stream->written = 0;
            stream->pool = heap_alloc(0x2800);
            stream->rom = func_800D5A6C(stream->id);
            stream->input = heap_alloc(0x1800);
            func_8001311C(stream->input, stream->rom);
            stream->rom += 0x1800;
            value = *stream->input;
            value = (value >> 16) << 4;
            stream->cursor = 2;
            stream->allocation = heap_alloc(value);
            if (!stream->allocation) {
                func_800E4B1C(slot);
                return 0;
            }
            stream->output = stream->allocation;
            stream->state = 2;
            return 0;
        case 2:
            stream->count = 0;
            // Read the next block header and set up its decoder.
            // Matching: unk_0 and unk_1 are extra temporaries needed for the match.
            unk_0[0] = 0;
            value = func_800E4D28(stream);
            unk_1 = unk_0[0];
            switch (value) {
                case 2: // dynamic Huffman
                    unk_0[0] = unk_1;
                    func_800E5EC0(stream);
                    stream->state = 3;
                    break;
                case 0: // stored
                    func_800E6728(stream);
                    stream->state = 4;
                    break;
                case 1: // fixed Huffman
                    func_800E659C(stream);
                    stream->state = 4;
            }
            return 0;
        case 3:
            // Decode with the per-call code budget.
            if (!func_800E4E54(stream))
                stream->state = 4;
            return 0;
        case 4:
            // Block finished: after the final one, free the buffers and write back the cache.
            if (stream->final) {
                if (stream->pool) {
                    heap_free(stream->pool);
                    stream->pool = 0;
                }
                if (stream->input) {
                    heap_free(stream->input);
                    stream->input = 0;
                }
                stream->state = 0;
                osWritebackDCache(stream->allocation, stream->written);
                return 1;
            } else {
                stream->state = 2;
                return 0;
            }
        case 0:
            return 1;
    }
    return 0;
}

// Returns 1 if the asset has a stream slot.
int func_800E4AF0()
{
    s32 slot;
    slot = func_800E4730();
    if (slot < 0) {
        // Matching: the `| 0` is needed for the match.
        return 0 | 0;
    }
    {
        return 1;
    }
}

// Frees a stream slot and its buffers.
void func_800E4B1C(slot) s32 slot;
{

if ((S_E4B1C **) D_8012D560[slot] == 0) {
    return;
}

if (((S_E4B1C **) D_8012D560)[slot]->allocation != 0) {
    heap_free(((S_E4B1C **) D_8012D560)[slot]->allocation);
}

if (((S_E4B1C **) D_8012D560)[slot]->input != 0) {
    heap_free(((S_E4B1C **) D_8012D560)[slot]->input);
}

if (((S_E4B1C **) D_8012D560)[slot]->pool != 0) {
    heap_free(((S_E4B1C **) D_8012D560)[slot]->pool);
}

heap_free(((S_E4B1C **) D_8012D560)[slot]);
((S_E4B1C **) D_8012D560)[slot] = 0;
}

// Cancels the stream for the asset, if any; returns 1 if a slot was freed.
int func_800E4BB8()
{
    s32 slot;
    slot = func_800E4730();

if (slot < 0) {
    return 0;
}
{
    func_800E4B1C(slot);
    return 1;
}

}

// Runs the asset's stream to completion, frees its slot and returns the decoded buffer
// (0 if the asset is not being streamed).
s32 func_800E4BF4(s32 asset_id)
{
    s32 slot;
    s32 buffer;

    slot = func_800E4730();

if (slot == -1) {
    return 0;
}

// Matching: the guarded do-while is needed for the match.
if (func_800E488C(asset_id) == 0) {
    do {
    } while (func_800E488C(asset_id) == 0);
}
{
    void **slot_ptr = &((void **) D_8012D560)[slot];
    buffer = *(s32 **) ((char *) *slot_ptr + 0x34);
    heap_free(*slot_ptr);
    *slot_ptr = NULL;
    return buffer;
}

}

// Runs defrag() on each stream slot and on D_8012D570.
int func_800E4C7C()
{
    s32 i;

for (i = 0; i < 4; i++) {
    if (((int *) D_8012D560)[i] != 0) {
        ((int *) D_8012D560)[i] = defrag(((int *) D_8012D560)[i]);
    }
}

D_8012D570 = defrag(D_8012D570);
}

// Frees all stream slots.
int func_800E4CE8()
{
    s32 i;

for (i = 0; i < 4; i++) {
    func_800E4B1C(i);
}

}

// DEFLATE core: block header, Huffman table build, stored/fixed/dynamic block decoding.
// Reads the 3-bit block header: stores the final-block flag and returns the block type
// (0 stored, 1 fixed, 2 dynamic). stream is a LocalStream: +0 input, +4 cursor, +0xC bits,
// +0x10 bit_count, +0x30 rom, +0x39 final.
s32 func_800E4D28(stream)
u8 *stream;
{
    s32 bit_count;
    u8 *input;
    u32 bits;

    bit_count = *(s32 *) ((s8 *) stream + 0x10);
    bits = *(u32 *) ((s8 *) stream + 0xC);

if (bit_count == 0) {
    do {
        if (*(s32 *) ((s8 *) stream + 4) >= 0x1800) {
            *(s32 *) ((s8 *) stream + 4) = 0;
            func_8001311C(*(s32 *) ((s8 *) stream + 0), *(s32 *) ((s8 *) stream + 0x30));
            *(s32 *) ((s8 *) stream + 0x30) += 0x1800;
        }
        input = (u8 *) *(s32 *) ((s8 *) stream + 0);
        bits |= *(input + *(s32 *) ((s8 *) stream + 4)) << bit_count;
        *(s32 *) ((s8 *) stream + 4) += 1;
        bit_count += 8;
    } while (bit_count == 0);
}

bit_count -= 1;
*(s8 *) ((s8 *) stream + 0x39) = (s8) (bits & 1);
bits >>= 1;

if ((u32) bit_count < 2) {
    do {
        if (*(s32 *) ((s8 *) stream + 4) >= 0x1800) {
            *(s32 *) ((s8 *) stream + 4) = 0;
            func_8001311C(*(s32 *) ((s8 *) stream + 0), *(s32 *) ((s8 *) stream + 0x30));
            *(s32 *) ((s8 *) stream + 0x30) += 0x1800;
        }
        input = (u8 *) *(s32 *) ((s8 *) stream + 0);
        bits |= *(input + *(s32 *) ((s8 *) stream + 4)) << bit_count;
        *(s32 *) ((s8 *) stream + 4) += 1;
        bit_count += 8;
    } while ((u32) bit_count < 2);
}

*(u32 *) ((s8 *) stream + 0xC) = bits >> 2;
bit_count -= 2;
*(s32 *) ((s8 *) stream + 0x10) = bit_count;
return bits & 3;
}

// Decodes literal/length and distance codes into the output; returns 1 when the per-call
// code budget runs out, 0 at the end of the block.
s32 func_800E4E54(param_0)
StreamE4 *param_0;
{
    u32 op;
    u32 length;
    u32 copy_pos;
    u32 out_pos;
    u32 literal_mask;
    u32 distance_mask;
    s32 codes_done = 0;
    HuftE4 *literal_table;
    HuftE4 *distance_table;
    u8 *out;
    HuftE4 *entry;
    u32 local_7;
    u32 local_8;
    out = param_0->output;
    literal_table = param_0->literal;
    distance_table = param_0->distance;
    local_7 = param_0->bits;
    local_8 = param_0->bit_count;
    out_pos = param_0->written;
    literal_mask = D_801232C0[param_0->literal_bits];
    distance_mask = D_801232C0[param_0->distance_bits];
    for (;;) {

// Literal/length code.
NEED_E4(param_0->literal_bits)
if ((op = (entry = literal_table + (local_7 & literal_mask))->e) > 16) {
    do {
        DUMP_E4(entry->b)
        op -= 16;
        NEED_E4(op)
    } while ((op =
                  (entry = entry->v.t + (local_7 & D_801232C0[op]))->e) >
             16);
}

DUMP_E4(entry->b)
// op: 16 literal, 15 end of block, else extra length bits.
if (op == 16) {
    out[out_pos++] = entry->v.n;
} else {

if (op == 15)
    break;
NEED_E4(op)
length = entry->v.n + (local_7 & D_801232C0[op]);

DUMP_E4(op)
// Distance code.
NEED_E4(param_0->distance_bits)
if ((op = (entry = distance_table + (local_7 & distance_mask))->e) > 16) {
    do {
        DUMP_E4(entry->b)
        op -= 16;
        NEED_E4(op)
    } while ((op =
                  (entry = entry->v.t + (local_7 & D_801232C0[op]))->e) >
             16);
}

DUMP_E4(entry->b)
NEED_E4(op)
copy_pos = out_pos - entry->v.n - (local_7 & D_801232C0[op]);

DUMP_E4(op)
// Copy the match.
do {
    out[out_pos++] = out[copy_pos++];
} while (--length);

}
// Budget spent: save the state and yield.
if (param_0->limit < codes_done++) {
    param_0->written = out_pos;
    param_0->bits = local_7;
    param_0->bit_count = local_8;
    return 1;

}
}
param_0->written = out_pos;
param_0->bits = local_7;
param_0->bit_count = local_8;
return 0;
}

// Like func_800E4E54, but runs to the end of the block (no code budget).
s32 func_800E5390(StreamE4 *param_0)
{
    u32 op;
    u32 length;
    u32 copy_pos;
    u32 out_pos;
    u32 literal_mask;
    u32 distance_mask;
    u8 *out;
    HuftE4 *literal_table;
    HuftE4 *distance_table;
    HuftE4 *entry;
    u32 local_7;
    u32 local_8;
    out = param_0->output;
    literal_table = param_0->literal;
    distance_table = param_0->distance;
    local_7 = param_0->bits;
    local_8 = param_0->bit_count;
    out_pos = param_0->written;
    literal_mask = D_801232C0[param_0->literal_bits];
    distance_mask = D_801232C0[param_0->distance_bits];
    for (;;) {
        // Literal/length code.
        NEED_E4(param_0->literal_bits)
        if ((op = (entry = literal_table + (local_7 & literal_mask))->e) > 16) {
            do {
                DUMP_E4(entry->b)
                op -= 16;
                NEED_E4(op)
            } while (
                (op = (entry = entry->v.t + (local_7 & D_801232C0[op]))
                               ->e) > 16);

}
DUMP_E4(entry->b)
// op: 16 literal, 15 end of block, else extra length bits.
if (op == 16) {
    out[out_pos++] = entry->v.n;
} else {
    if (op == 15)
        break;
    NEED_E4(op)
    length = entry->v.n + (local_7 & D_801232C0[op]);

DUMP_E4(op)
// Distance code.
NEED_E4(param_0->distance_bits)
if ((op = (entry = distance_table + (local_7 & distance_mask))->e) > 16) {
    do {
        DUMP_E4(entry->b)
        op -= 16;
        NEED_E4(op)
    } while ((op =
                  (entry = entry->v.t + (local_7 & D_801232C0[op]))->e) >
             16);
}

DUMP_E4(entry->b)
NEED_E4(op)
copy_pos = out_pos - entry->v.n - (local_7 & D_801232C0[op]);

DUMP_E4(op)
// Copy the match.
do {
    out[out_pos++] = out[copy_pos++];
} while (--length);

}
}
param_0->written = out_pos;
param_0->bits = local_7;
param_0->bit_count = local_8;
return 0;
}

// Builds a Huffman lookup table (inflate huft_build) from num_codes code lengths; codes
// >= num_simple use base/extra. table_out and bits_out receive the table and its lookup
// bits (bits_out is also the requested size). Returns nonzero if the code is incomplete.
int func_800E589C(u32 *lengths, u32 num_codes, u32 num_simple, u16 *base, u16 *extra,
                  struct LocalHuft **table_out, s32 *bits_out, LocalInflate_800E589C *stream)
{
    unsigned remaining;
    unsigned bl_count[16 + 1];
    unsigned stride;
    int max_len;
    int level;
    register unsigned code;
    register unsigned j;
    register int len;
    int lookup_bits;
    register unsigned *ptr;
    register struct LocalHuft *table;
    struct LocalHuft entry;
    struct LocalHuft *tables[16];
    unsigned values[288];
    register int prefix_bits;
    unsigned offsets[16 + 1];
    unsigned *count_ptr;
    int dummy;
    unsigned entries;

    bzero(bl_count, sizeof(bl_count));
    ptr = lengths;
    code = num_codes;
    do {
        bl_count[*ptr]++;
        ptr++;
    } while (--code);
    if (bl_count[0] == num_codes) {
        *table_out = (struct LocalHuft *) NULL;
        *bits_out = 0;
        return 0;
    }

    lookup_bits = *bits_out;
    for (j = 1; j <= 16; j++)
        if (bl_count[j])
            break;
    len = j;
    if ((unsigned) lookup_bits < j)
        lookup_bits = j;
    for (code = 16; code; code--)
        if (bl_count[code])
            break;
    max_len = code;
    if ((unsigned) lookup_bits > code)
        lookup_bits = code;
    *bits_out = lookup_bits;

    for (dummy = 1 << j; j < code; j++, dummy <<= 1) {
        (dummy -= bl_count[j]);
    }
    dummy -= bl_count[code];
    bl_count[code] += dummy;

    offsets[1] = j = 0;
    ptr = bl_count + 1;
    count_ptr = offsets + 2;
    while (--code) {
        *count_ptr++ = (j += *ptr++);
    }

    ptr = lengths;
    code = 0;
    do {
        if ((j = *ptr++) != 0)
            values[offsets[j]++] = code;
    } while (++code < num_codes);

    offsets[0] = code = 0;
    ptr = values;
    level = -1;
    prefix_bits = -lookup_bits;
    tables[0] = (struct LocalHuft *) NULL;
    table = (struct LocalHuft *) NULL;
    entries = 0;

    for (; len <= max_len; len++) {
        remaining = bl_count[len];
        while (remaining--) {
            while (len > prefix_bits + lookup_bits) {
                level++;
                prefix_bits += lookup_bits;

                entries =
                    (entries = max_len - prefix_bits) > (unsigned) lookup_bits ? lookup_bits : entries;
                if ((stride = 1 << (j = len - prefix_bits)) > remaining + 1) {
                    stride -= remaining + 1;
                    count_ptr = bl_count + len;
                    while (++j < entries) {
                        if ((stride <<= 1) <= *++count_ptr)
                            break;
                        stride -= *count_ptr;
                    }
                }
                entries = 1 << j;

                table = stream->pool + stream->count;

                stream->count += entries + 1;
                *table_out = table + 1;
                *(table_out = &table->v.t) = (struct LocalHuft *) NULL;
                tables[level] = ++table;

                if (level) {
                    offsets[level] = code;
                    entry.b = (u8) lookup_bits;
                    entry.e = (u8) (16 + j);
                    entry.v.t = table;
                    j = code >> (prefix_bits - lookup_bits);
                    tables[level - 1][j] = entry;
                }
            }


entry.b = (u8) (len - prefix_bits);
if (ptr >= values + num_codes)
    entry.e = 99;

else if (*ptr < num_simple)
{
    entry.e = (u8) (*ptr < 256 ? 16 : 15);
    entry.v.n = *ptr;
    ptr++;
}

else
{
    entry.e = *((u8 *) extra + (*ptr - num_simple));
    entry.v.n = base[*ptr++ - num_simple];
}

stride = 1 << (len - prefix_bits);
for (j = code >> prefix_bits; j < entries; j += stride)
    table[j] = entry;

for (j = 1 << (len - 1); code & j; j >>= 1)
    code ^= j;
code ^= j;


while ((code & ((1 << prefix_bits) - 1)) != offsets[level]) {
    level--;
    prefix_bits -= lookup_bits;
}

}
}

return dummy != 0 && max_len != 1;
}

// Reads a dynamic-Huffman block header and builds its literal/length and distance tables.
s32 func_800E5EC0(param_0)
LocalInflate_800E5EC0 *param_0;
{
    int i;
    unsigned j;
    unsigned prev_len;
    unsigned mask;
    unsigned total;
    struct LocalHuft *literal_table;
    struct LocalHuft *distance_table;
    int literal_bits;
    int distance_bits;
    unsigned num_clen;
    unsigned num_lit;
    unsigned num_dist;

    unsigned lengths[286 + 30];
    register unsigned local_12;
    register u32 local_13;

    literal_bits = param_0->literal_bits;
    distance_bits = param_0->distance_bits;
    literal_table = param_0->literal;
    distance_table = param_0->distance;
    local_13 = param_0->bits;
    local_12 = param_0->bit_count;

    // Table sizes: 257 + HLIT literal/length codes, 1 + HDIST distance codes, 4 + HCLEN.
    NEEDBITS(5)
    num_lit = 257 + ((unsigned) local_13 & 0x1f);
    DUMPBITS(5)
    NEEDBITS(5)
    num_dist = 1 + ((unsigned) local_13 & 0x1f);
    DUMPBITS(5)
    NEEDBITS(4)
    num_clen = 4 + ((unsigned) local_13 & 0xf);
    DUMPBITS(4)

    // Code length code lengths, in permuted order.
    for (j = 0; j < num_clen; j++) {
        NEEDBITS(3)
        lengths[D_801231F0[j]] = (unsigned) local_13 & 7;
        DUMPBITS(3)
    }
    for (; j < 19; j++)
        lengths[D_801231F0[j]] = 0;

    // Build the code length decoding table.
    literal_bits = 7;
    func_800E589C(lengths, 19, 19, NULL, NULL, &literal_table, &literal_bits, param_0);

    // Read the literal/length and distance code lengths.
    total = num_lit + num_dist;
    mask = D_801232C0[literal_bits];
    i = prev_len = 0;
    while ((unsigned) i < total) {
        NEEDBITS((unsigned) literal_bits)
        j = (distance_table = literal_table + ((unsigned) local_13 & mask))->b;
        DUMPBITS(j)
        j = distance_table->v.n;
        if (j < 16)
            lengths[i++] = prev_len = j;
        else if (j == 16) { // repeat previous length 3-6 times
            NEEDBITS(2)
            j = 3 + ((unsigned) local_13 & 3);
            DUMPBITS(2)
            while (j--)
                lengths[i++] = prev_len;
        } else if (j == 17) { // 3-10 zero lengths
            NEEDBITS(3)
            j = 3 + ((unsigned) local_13 & 7);
            DUMPBITS(3)
            while (j--)
                lengths[i++] = 0;
            prev_len = 0;
        } else { // 11-138 zero lengths
            NEEDBITS(7)
            j = 11 + ((unsigned) local_13 & 0x7f);
            DUMPBITS(7)
            while (j--)
                lengths[i++] = 0;
            prev_len = 0;
        }
    }

    param_0->bits = local_13;
    param_0->bit_count = local_12;

    // Build the literal/length and distance tables.
    literal_bits = 9;
    func_800E589C(lengths, num_lit, 257, D_80123204, D_80123244, &literal_table, &literal_bits, param_0);
    distance_bits = 6;
    func_800E589C(lengths + num_lit, num_dist, 0, D_80123264, D_801232A0, &distance_table, &distance_bits,
                  param_0);

    param_0->literal_bits = literal_bits;
    param_0->distance_bits = distance_bits;
    param_0->literal = literal_table;
    param_0->distance = distance_table;

    return 0;
}

// Builds the fixed-Huffman tables and decodes the block.
s32 func_800E659C(stream)
s32 *stream;
{
    s32 i;
    void *literal_table;
    void *distance_table;
    u32 literal_bits;
    u32 distance_bits;
    u32 lengths[288];
    // Fixed code lengths: 0-143 are 8, 144-255 are 9, 256-279 are 7, 280-287 are 8.
    for (i = 0; i < 144; i++) {
        lengths[i] = 8;
    }
    for (; i < 256; i++) {
        lengths[i] = 9;
    }
    for (; i < 280; i++) {
        lengths[i] = 7;
    }
    for (; i < 288; i++) {
        lengths[i] = 8;
    }
    literal_bits = 7;
    func_800E589C(lengths, 288, 257, D_80123204, D_80123244, &literal_table, &literal_bits, stream);
    for (i = 0; i < 30; i++) {
        lengths[i] = 5;
    }
    distance_bits = 5;
    func_800E589C(lengths, 30, 0, D_80123264, D_801232A0, &distance_table, &distance_bits, stream);
    // Words 6-9 of the stream: literal, distance, literal_bits, distance_bits.
    stream[8] = literal_bits;
    stream[9] = distance_bits;
    stream[6] = (s32) literal_table;
    stream[7] = (s32) distance_table;
    func_800E5390(stream);
    return 0;
}

// Copies a stored (uncompressed) block to the output.
s32 func_800E6728(param_0)
InflateStream *param_0;
{
    u32 length;
    u32 local_1;
    u32 local_2;
    u32 out_pos;
    u8 *out;
    u32 skip;
    out = param_0->output;
    local_1 = param_0->bits;
    local_2 = param_0->bit_count;
    out_pos = param_0->written;
    skip = local_2 & 7;
    // Skip to a byte boundary.
    DUMP_BITS(skip)
    NEED_BITS(16)
    // Block length.
    length = local_1 & 0xFFFF;
    DUMP_BITS(16)
    // Skip the one's complement of the length.
    NEED_BITS(16)
    DUMP_BITS(16)
    while (length--) {
        NEED_BITS(8)
        out[out_pos++] = local_1;
        DUMP_BITS(8)
    }
    param_0->written = out_pos;
    param_0->bits = local_1;
    param_0->bit_count = local_2;
    return 0;
}

void func_800E692C()
{
    D_8012D570 = heap_alloc(0x40);
}

// Synchronously loads and decompresses an asset. Allocates on heap_side unless dest is
// given; returns the buffer (0 if the allocation fails).
void *func_800E6950(s32 asset_id, s32 heap_side, void *dest)
{
    union {
        s32 side;
        void *buffer;
    } target;
    u32 rom_addr;
    u32 size;
    u32 header[1];

    target.side = heap_side;
    rom_addr = func_800D5A6C(asset_id);
    rom_read_word(rom_addr, header);
    // Decompressed size is (header >> 16) * 16.
    // Matching: the stores back to header[0] are needed for the match.
    size = header[0];
    header[0] = (size >>= 16);
    size = header[0] * 16;
    header[0] = size;
    func_800D5FDC(header[0]);
    if (!dest) {
        target.buffer = heap_alloc_sided(size, target.side);
        if (!target.buffer) {
            return 0;
        }
    } else {
        target.buffer = dest;
    }
    func_80117248(rom_addr, func_800D5950(asset_id), target.buffer);
    // Matching: empty block steers IDO's register allocation.
    if (!target.buffer) {
    }
    osWritebackDCache(target.buffer, size);
    return target.buffer;
}

// Getter of a global byte used as the default animation playback mode.
s32 func_800E6A00(void)
{
    return D_801275E0;
}

// Order in which the code length code lengths are stored.
u8 D_801231F0[20] = {0x10, 0x11, 0x12, 0x0, 0x8, 0x7, 0x9, 0x6, 0xA, 0x5,
                     0xB,  0x4,  0xC,  0x3, 0xD, 0x2, 0xE, 0x1, 0xF, 0x0};
// Length codes: base lengths.
u16 D_80123204[32] = {0x3,  0x4,  0x5,  0x6,  0x7,  0x8,  0x9,   0xA,  0xB,  0xD,  0xF,
                      0x11, 0x13, 0x17, 0x1B, 0x1F, 0x23, 0x2B,  0x33, 0x3B, 0x43, 0x53,
                      0x63, 0x73, 0x83, 0xA3, 0xC3, 0xE3, 0x102, 0x0,  0x0,  0x0};
// Length codes: extra bits (byte table).
u16 D_80123244[16] = {0x0,   0x0,   0x0,   0x0,   0x101, 0x101, 0x202, 0x202,
                      0x303, 0x303, 0x404, 0x404, 0x505, 0x505, 0x63,  0x6300};
// Distance codes: base distances.
u16 D_80123264[30] = {0x1,   0x2,   0x3,   0x4,   0x5,    0x7,    0x9,    0xD,    0x11,   0x19,
                      0x21,  0x31,  0x41,  0x61,  0x81,   0xC1,   0x101,  0x181,  0x201,  0x301,
                      0x401, 0x601, 0x801, 0xC01, 0x1001, 0x1801, 0x2001, 0x3001, 0x4001, 0x6001};
// Distance codes: extra bits (byte table).
u16 D_801232A0[16] = {0x0,   0x0,   0x101, 0x202, 0x303, 0x404, 0x505, 0x606,
                      0x707, 0x808, 0x909, 0xA0A, 0xB0B, 0xC0C, 0xD0D, 0x0};
// Bit masks: (1 << n) - 1.
u16 D_801232C0[40] = {0x0,    0x1,    0x3,    0x7,    0xF,    0x1F,   0x3F,   0x7F,   0xFF, 0x1FF,
                      0x3FF,  0x7FF,  0xFFF,  0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF, 0x0,    0x0,  0x0,
                      0x0,    0x0,    0x0,    0x0,    0x4E61, 0x4E00, 0x734E, 0x614E, 0x0,  0x0,
                      0x494E, 0x4600, 0x2D49, 0x4E46, 0x0,    0x0,    0x0,    0x0,    0x0,  0x0};
