#include "common.h"

extern s32 D_80011000;
extern s32 D_8000E800;
extern s32 *D_80124A8C;
struct LocalHuft {
    u8 e, b;
    union {
        u16 n;
        struct LocalHuft *t;
    } v;
};
extern struct LocalHuft *D_80124A80;
extern u32 D_80137388;

// Points the huft table storage at the shared static scratch buffers.
void func_801168F0()
{
    D_80124A8C = &D_80011000;
    D_80124A80 = &D_8000E800;
}

// huft_build from zlib inflate. Tables come from a linear pool (D_80124A80 + D_80137388), not malloc.
void func_80116914(u32 *lengths, u32 n, u32 simple_count, u16 *base_values, u16 *extra_bits,
                   struct LocalHuft **out_table, s32 *out_bits)
{
    unsigned remaining;
    unsigned counts[16 + 1];
    unsigned fill;
    int max_len;
    int level;
    register unsigned i;
    register unsigned j;
    register int len;
    int table_bits;
    register unsigned *ptr;
    register struct LocalHuft *table;
    struct LocalHuft entry;
    struct LocalHuft *tables[16];
    unsigned values[288];
    register int shift;
    unsigned offsets[16 + 1];
    unsigned *offset_ptr;
    int dummy;
    unsigned table_size;

    bzero(counts, sizeof(counts));
    ptr = lengths;
    i = n;
    do {
        counts[*ptr]++;
        ptr++;
    } while (--i);
    if (counts[0] == n) {
        *out_table = (struct LocalHuft *) NULL;
        *out_bits = 0;
        return;
    }

    table_bits = *out_bits;
    for (j = 1; j <= 16; j++)
        if (counts[j])
            break;
    len = j;
    if ((unsigned) table_bits < j)
        table_bits = j;
    for (i = 16; i; i--)
        if (counts[i])
            break;
    max_len = i;
    if ((unsigned) table_bits > i)
        table_bits = i;
    *out_bits = table_bits;

    for (dummy = 1 << j; j < i; j++, dummy <<= 1) {
        (dummy -= counts[j]);
    }
    dummy -= counts[i];
    counts[i] += dummy;

    offsets[1] = j = 0;
    ptr = counts + 1;
    offset_ptr = offsets + 2;
    while (--i) {
        *offset_ptr++ = (j += *ptr++);
    }

    ptr = lengths;
    i = 0;
    do {
        if ((j = *ptr++) != 0)
            values[offsets[j]++] = i;
    } while (++i < n);

    offsets[0] = i = 0;
    ptr = values;
    level = -1;
    shift = -table_bits;
    tables[0] = (struct LocalHuft *) NULL;
    table = (struct LocalHuft *) NULL;
    table_size = 0;

    for (; len <= max_len; len++) {
        remaining = counts[len];
        while (remaining--) {
            while (len > shift + table_bits) {
                level++;
                shift += table_bits;

                table_size =
                    (table_size = max_len - shift) > (unsigned) table_bits ? table_bits : table_size;
                if ((fill = 1 << (j = len - shift)) > remaining + 1) {
                    fill -= remaining + 1;
                    offset_ptr = counts + len;
                    while (++j < table_size) {
                        if ((fill <<= 1) <= *++offset_ptr)
                            break;
                        fill -= *offset_ptr;
                    }
                }
                table_size = 1 << j;

                table = D_80124A80 + D_80137388;

                D_80137388 += table_size + 1;
                *out_table = table + 1;
                *(out_table = &table->v.t) = (struct LocalHuft *) NULL;
                tables[level] = ++table;

                if (level) {
                    offsets[level] = i;
                    entry.b = (u8) table_bits;
                    entry.e = (u8) (16 + j);
                    entry.v.t = table;
                    j = i >> (shift - table_bits);
                    tables[level - 1][j] = entry;
                }
            }

            entry.b = (u8) (len - shift);
            if (ptr >= values + n)
                entry.e = 99; // invalid code
            else if (*ptr < simple_count) {
                entry.e = (u8) (*ptr < 256 ? 16 : 15);
                entry.v.n = *ptr;
                ptr++;
            } else {
                entry.e = *((u8 *) extra_bits + (*ptr - simple_count));
                entry.v.n = base_values[*ptr++ - simple_count];
            }

            fill = 1 << (len - shift);
            for (j = i >> shift; j < table_size; j += fill)
                table[j] = entry;

            for (j = 1 << (len - 1); i & j; j >>= 1)
                i ^= j;
            i ^= j;

            while ((i & ((1 << shift) - 1)) != offsets[level]) {
                level--;
                shift -= table_bits;
            }
        }
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EF01E0.data.s) is defined here in C;
// values are taken from the ROM.
struct LocalHuft *D_80124A80 = 0;
static u32 D_80124A80_rest[2] = {0x0, 0x0};
s32 *D_80124A8C = 0;
