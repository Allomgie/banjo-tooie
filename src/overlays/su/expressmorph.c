// Morph part of the expression component: per-model morph presets, expression row selection for
// the current dialog speaker, hold timers, smooth weight blending and applying it via db/morph.
#include "common.h"
typedef struct {
    void *rows;
    u8 pad_4[3];
    u8 weight_count;
    u32 unk_8;
} MorphPreset_suexpressmorph_entrypoint_0;
extern MorphPreset_suexpressmorph_entrypoint_0 D_80801320_suexpressmorph[];

extern s16 D_80801324_suexpressmorph;
extern u32 D_8080132C_suexpressmorph[];
// One expression row: key, target weights (-1 = keep), hold times.
typedef struct {
    s16 key;
    s16 pad_2;
    f32 target[4];
    f32 hold[4];
} Broad51MorphRow;
// One morph preset.
typedef struct {
    Broad51MorphRow *rows;
    s16 pad_4;
    u8 row_count;
    u8 weight_count;
    s32 pad_8;
} Broad51MorphPreset;
typedef struct MorphValues {
    f32 key;
    f32 target[4];
    f32 hold[4];
} MorphValues;
typedef struct {
    s16 id;
    s16 preset;
    u8 pad_4[2];
    u8 unk_6;
    u8 pad_7;
    f32 weights[3];
} MorphParameters1358;
typedef struct {
    u8 pad_0 : 7;
    u8 unk_8 : 1;
    u8 pad_1[11];
} MorphEntry1358;
extern MorphEntry1358 D_80801328_suexpressmorph[];
typedef struct {
    u8 pad_0[7];
    u8 weight_count;
    u8 pad_8[4];
} MorphPreset_suexpressmorph_entrypoint_5;
typedef struct {
    f32 values[9];
} MorphRow;
typedef struct {
    MorphRow *rows;
    s16 pad_4;
    u8 pad_6;
    u8 count;
    s32 pad_8;
} MorphPreset_808000EC_suexpressmorph;
extern f32 func_800D8FF8(void);

// Returns the preset index for a preset id, or -1 if unknown.
s32 func_80800000_suexpressmorph(s32 id)
{
    s8 *entry;
    s32 index;

    entry = (s8 *) &D_8080132C_suexpressmorph;
    index = 1;
    if (id == D_80801324_suexpressmorph) {
        return 0;
    }
loop_3:
    if (id == *(s16 *) ((s8 *) entry + 4)) {
        return index;
    }
    if (id == *(s16 *) ((s8 *) entry + 0x10)) {
        return index + 1;
    }
    if (id == *(s16 *) ((s8 *) entry + 0x1C)) {
        return index + 2;
    }
    if (id == *(s16 *) ((s8 *) entry + 0x28)) {
        return index + 3;
    }
    index += 4;
    entry += 0x30;
    if (index == 0x11) {
        return -1;
    }
    goto loop_3;
}

// Returns the block size for a preset id (weights and hold timers).
s32 suexpressmorph_entrypoint_0(id)
s16 id;
{
    s32 index;
    s32 size;

    index = func_80800000_suexpressmorph(id);
    if (index == -1) {
        return 0;
    }
    size = D_80801320_suexpressmorph[index].weight_count * 4;
    size += 8;
    size += D_80801320_suexpressmorph[index].weight_count * 4;
    return size;
}

// Updates hold timers and blends the current weights toward the targets.
void func_808000EC_suexpressmorph(targets, block) f32 *targets;
u8 *block;
{
    f32 *weight;
    f32 *target;
    f32 *hold;
    s32 off;
    s32 i;

    weight = (f32 *) (block + 8);
    target = targets;
    hold =
        weight +
        ((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
            .count;
    off = 0;
    i = 0;
    for (;
         i <
         ((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
             .count;
         i++, off += 4, target++, weight++, hold++) {
        if (*hold <= 0) {
            *target = *(f32 *) ((s32) ((MorphPreset_808000EC_suexpressmorph *)
                                           D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                                    .rows[block[5]]
                                    .values +
                                off + 4);
        } else {
            *hold -= func_800D8FF8();
            // Matching: empty block steers register allocation.
            if (target) {
            }
        }
        if (*target < *weight) {
            *weight += (*target - *weight) * 0.2f;
            if (*weight < 0.0f)
                *weight = 0.0f;
        } else if (*weight < *target) {
            *weight += (*target - *weight) * 0.2f;
            if (*weight > 1.0f)
                *weight = 1.0f;
        }
    }
}

// While this actor is the dialog speaker, picks the expression row and raises targets.
void func_808002BC_suexpressmorph(f32 *targets, u8 *block)
{
    s32 key;
    f32 *hold;
    s32 unk_0;
    Broad51MorphRow *row;
    s32 i;
    s32 match;
    match = -1;
    hold = (f32 *) (block + 8) +
           ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)].weight_count;
    if (func_800D52F4() == *(s16 *) block) {
        key = func_800D52A4() + 1;
        i = 0;
        if (i < (&((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)])
                    ->row_count) {
            row = (&((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)])
                      ->rows;
            do {
                if (key == row->key) {
                    match = i;
                }
                i++;
                row++;
            } while (i <
                     (&((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)])
                         ->row_count);
        }
        if (func_800D5298()) {
            for (i = 0;
                 i <
                 ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)].weight_count;
                 i++, hold++) {
                if (((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                        .rows[match]
                        .target[i] != -1.0f) {
                    if (*hold <
                        ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                            .rows[match]
                            .hold[i]) {
                        *hold = ((
                            Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                                    .rows[match]
                                    .hold[i];
                        targets[i] = ((
                            Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                                         .rows[match]
                                         .target[i];
                    }
                }
            }
        } else {
            for (i = 0;
                 i <
                 ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)].weight_count;
                 i++) {
                if (((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                        .rows[match]
                        .target[i] != -1.0f) {
                    targets[i] =
                        ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                            .rows[match]
                            .target[i];
                }
            }
        }
    }
}

void suexpressmorph_entrypoint_1(u8 *block)
{
    f32 targets[4];
    s32 i;

    for (i = 0; i < D_80801320_suexpressmorph[*(s16 *) (block + 2)].weight_count;
         i++) {
        targets[i] =
            (*(MorphValues **) &D_80801320_suexpressmorph[*(s16 *) (block + 2)])[block[5]]
                .target[i];
    }
    func_808002BC_suexpressmorph(targets, block);
    func_808000EC_suexpressmorph(targets, block);
}

// Draw time: applies the weights to the model's vertices via db/morph.
void suexpressmorph_entrypoint_2(MorphParameters1358 *block, u8 **unk_0)
{
    s32 pad0;
    s32 model;
    s32 unk_1;
    u8 *vertices;
    s32 unk_2;
    model = func_80103AA0(*unk_0);
    if (model) {
        vertices = (u8 *) func_80103CDC(unk_0, model);
        if (vertices) {
            unk_1 = func_800B2840(model);
            unk_2 = func_800B2768(model);
            _dbmorph_entrypoint_3(unk_2, vertices, unk_1, block->unk_6, block->weights);
            if (D_80801328_suexpressmorph[block->preset].unk_8) {
                // Matching: empty block, needed for the match.
                if (((((!unk_2 && 1) && !unk_2) & 0xFFu) & 0xFFu) & 0xFFu) {
                }
                vertices[0x17] |= 1;
                _dbmorph_entrypoint_4(unk_2, vertices, unk_1, block->unk_6,
                                      func_800AE080(*(s16 *) (*unk_0 + 0x10)));
            }
        }
    }
}

void suexpressmorph_entrypoint_3(s16 *block, s16 id)
{
    block[0] = id;
    block[1] = func_80800000_suexpressmorph(block[0]);
}

void suexpressmorph_entrypoint_4(s32 block, s32 flag)
{
    *(u8 *) ((char *) block + 6) = flag;
}

// Initialises the block: row 0, weights and hold timers cleared.
void suexpressmorph_entrypoint_5(u8 *block, s16 id)
{
    f32 *weight;
    f32 *hold;
    s32 i;

    suexpressmorph_entrypoint_3(block, id);
    block[5] = 0;
    block[6] = 1;
    weight = (f32 *) (block + 8);
    hold = weight + ((MorphPreset_suexpressmorph_entrypoint_5 *)
                         D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                        .weight_count;
    for (i = 0; i < ((MorphPreset_suexpressmorph_entrypoint_5 *)
                         D_80801320_suexpressmorph)[*(s16 *) (block + 2)]
                        .weight_count;
         i++) {
        *weight++ = 0.0f;
        *hold++ = 0.0f;
    }
}

// TU-NOTE: the overlay .data is defined here in C, values taken from the ROM.
// D_80801324 = D_80801320 + 0x4 and D_80801328 = D_80801320 + 0x8 are linker symbols
// (undefined_syms.us.txt). The extern D_8080132C is declared as u32[] over the object below.
u32 D_808007E0_suexpressmorph[108] = {
    0x0,        0xBF800000, 0xBF800000, 0xBF800000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x3E19999A, 0x0,        0xBF800000, 0xBF800000, 0x3EB33333, 0x3EB33333,
    0x0,        0x0,        0x20000,    0x0,        0x3F800000, 0xBF800000, 0xBF800000, 0x3EB33333,
    0x3EB33333, 0x0,        0x0,        0x30000,    0x3F800000, 0x0,        0xBF800000, 0xBF800000,
    0x3EB33333, 0x3EB33333, 0x0,        0x0,        0x40000,    0xBF800000, 0xBF800000, 0xBF800000,
    0xBF800000, 0x3EB33333, 0x3EB33333, 0x0,        0x0,        0x50000,    0xBF800000, 0xBF800000,
    0xBF800000, 0xBF800000, 0x3EB33333, 0x3EB33333, 0x0,        0x0,        0xC0000,    0xBF800000,
    0xBF800000, 0x3F800000, 0xBF800000, 0x0,        0x0,        0x3E800000, 0x0,        0xD0000,
    0xBF800000, 0xBF800000, 0x0,        0xBF800000, 0x0,        0x0,        0x3E800000, 0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x3EB33333, 0x3EB33333, 0x0,
    0x0,        0xE0000,    0x3F800000, 0x0,        0x0,        0x0,        0x3EB33333, 0x3EB33333,
    0x0,        0x0,        0xF0000,    0x0,        0x3F800000, 0x0,        0x0,        0x3EB33333,
    0x3EB33333, 0x0,        0x0,        0x100000,   0x3F800000, 0x3F000000, 0x0,        0x0,
    0x3EB33333, 0x3EB33333, 0x0,        0x0};
u32 D_80800990_suexpressmorph[36] = {
    0x0,        0xBF800000, 0xBF800000, 0xBF800000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0xBF800000, 0xBF800000, 0xBF800000, 0x3EB33333, 0x3EB33333,
    0x3EB33333, 0x3EB33333, 0x20000,    0x3F000000, 0xBF800000, 0xBF800000, 0xBF800000, 0x3EB33333,
    0x3EB33333, 0x3EB33333, 0x3EB33333, 0x30000,    0x3F800000, 0xBF800000, 0xBF800000, 0xBF800000,
    0x3EB33333, 0x3EB33333, 0x3EB33333, 0x3EB33333};
u32 D_80800A20_suexpressmorph[45] = {
    0x0,        0x0,        0x0,        0x0,        0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0x0,        0xBF800000, 0x3EB33333, 0x3EB33333,
    0x3EB33333, 0x3EB33333, 0x20000,    0x3F800000, 0x0,        0x0,        0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0x0,        0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x0,        0x3F800000,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
u32 D_80800AD4_suexpressmorph[63] = {
    0x0,        0x0,        0x0,        0xBF800000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0xBF800000, 0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3EB33333, 0x3EB33333, 0x20000,    0x3F800000, 0x0,        0xBF800000, 0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0xBF800000, 0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x3EB33333, 0x40000,    0x0,        0x3F800000, 0xBF800000,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x3EB33333, 0x50000,    0x0,        0x3F800000,
    0xBF800000, 0xBF800000, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x3EB33333, 0x60000,    0x0,
    0x3F800000, 0xBF800000, 0xBF800000, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x3EB33333};
u32 D_80800BD0_suexpressmorph[45] = {
    0x0,        0x0,        0x0,        0x0,        0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0x3F800000, 0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x20000,    0x3F800000, 0x0,        0x0,        0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0x0,        0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x3F800000, 0x0,        0x0,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
u32 D_80800C84_suexpressmorph[45] = {
    0x0,        0x3F800000, 0x0,        0x0,        0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x3F800000, 0x0,        0x0,        0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x20000,    0x0,        0x3F800000, 0x0,        0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x0,        0x3F800000, 0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x3F800000, 0x0,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
u32 D_80800D38_suexpressmorph[45] = {
    0x0,        0x3E4CCCCD, 0x0,        0x0,        0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x3E4CCCCD, 0x0,        0x0,        0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x20000,    0x0,        0x3F800000, 0x0,        0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0x3F000000, 0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x3F800000, 0x0,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
u32 D_80800DEC_suexpressmorph[54] = {
    0x0,        0x3E4CCCCD, 0x0,        0x0,        0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x3E4CCCCD, 0x0,        0x0,        0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x20000,    0x0,        0x3F800000, 0x0,        0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x0,        0x3F800000, 0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x3F800000, 0x0,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x50000,    0x0,        0x0,
    0x3F800000, 0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
u32 D_80800EC4_suexpressmorph[45] = {
    0x0,        0x3F4CCCCD, 0x0,        0xBF800000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x3F4CCCCD, 0x0,        0xBF800000, 0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x20000,    0x0,        0x3F800000, 0xBF800000, 0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F4CCCCD, 0xBF800000, 0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x3F800000, 0xBF800000,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
u32 D_80800F78_suexpressmorph[45] = {
    0x0,        0x3E99999A, 0x0,        0xBF800000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x3F4CCCCD, 0x0,        0xBF800000, 0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD,
    0x3E19999A, 0x3EB33333, 0x20000,    0x0,        0x3F666666, 0xBF800000, 0xBF800000, 0x3DCCCCCD,
    0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F666666, 0xBF800000, 0xBF800000,
    0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x3F4CCCCD, 0xBF800000,
    0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333};
u32 D_8080102C_suexpressmorph[45] = {
    0x0,        0x0,        0x0,        0x0,        0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0x0,        0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD,
    0x3E19999A, 0x3EB33333, 0x20000,    0x0,        0x3F4CCCCD, 0x0,        0xBF800000, 0x3DCCCCCD,
    0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x30000,    0x3F4CCCCD, 0x0,        0x0,        0xBF800000,
    0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x40000,    0x0,        0x0,        0x3F666666,
    0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333};
u32 D_808010E0_suexpressmorph[45] = {
    0x0,        0x0,        0x0,        0xBF800000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0xBF800000, 0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD,
    0x3E19999A, 0x3EB33333, 0x20000,    0x3DCCCCCD, 0x3F800000, 0xBF800000, 0xBF800000, 0x3DCCCCCD,
    0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0xBF800000, 0xBF800000,
    0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x40000,    0x3F800000, 0x0,        0xBF800000,
    0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333};
u32 D_80801194_suexpressmorph[54] = {
    0x0,        0x0,        0x0,        0x3F000000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0x3F800000, 0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD,
    0x3E19999A, 0x3EB33333, 0x20000,    0x3F000000, 0x0,        0x0,        0xBF800000, 0x3DCCCCCD,
    0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0x0,        0xBF800000,
    0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x40000,    0x3F000000, 0x0,        0x0,
    0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333, 0x50000,    0x3F000000, 0x3F000000,
    0x0,        0xBF800000, 0x3DCCCCCD, 0x3DCCCCCD, 0x3E19999A, 0x3EB33333};
u32 D_8080126C_suexpressmorph[45] = {
    0x0,        0x0,        0x0,        0x3F000000, 0xBF800000, 0x0,        0x0,        0x0,
    0x0,        0x10000,    0x0,        0x0,        0x3F800000, 0xBF800000, 0x3E19999A, 0x3E19999A,
    0x3E19999A, 0x3EB33333, 0x20000,    0x3F800000, 0x0,        0x0,        0xBF800000, 0x3E19999A,
    0x3E19999A, 0x3E19999A, 0x3EB33333, 0x30000,    0x0,        0x3F800000, 0x0,        0xBF800000,
    0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333, 0x40000,    0x3F800000, 0x0,        0x0,
    0xBF800000, 0x3E19999A, 0x3E19999A, 0x3E19999A, 0x3EB33333};
// Preset table (0xC bytes per entry); entries 1.. continue at D_8080132C.
MorphPreset_suexpressmorph_entrypoint_0 D_80801320_suexpressmorph[1] = {
    (void *) &D_80800990_suexpressmorph, 0x0, 0x2A, 0x4, 0x1, 0x0};
u32 D_8080132C_suexpressmorph[49] = {(u32) &D_808007E0_suexpressmorph,
                                     0x360803,
                                     0x0,
                                     (u32) &D_80800AD4_suexpressmorph,
                                     0x790702,
                                     0x0,
                                     (u32) &D_80800D38_suexpressmorph,
                                     0x7A0503,
                                     0x0,
                                     (u32) &D_80800BD0_suexpressmorph,
                                     0x7C0503,
                                     0x0,
                                     (u32) &D_80800C84_suexpressmorph,
                                     0x7D0503,
                                     0x1000000,
                                     (u32) &D_80800EC4_suexpressmorph,
                                     0x7E0502,
                                     0x0,
                                     (u32) &D_80800A20_suexpressmorph,
                                     0x7F0503,
                                     0x0,
                                     (u32) &D_80800F78_suexpressmorph,
                                     0x800502,
                                     0x1000000,
                                     (u32) &D_80800DEC_suexpressmorph,
                                     0x7B0603,
                                     0x0,
                                     (u32) &D_80800A20_suexpressmorph,
                                     0xAB0503,
                                     0x0,
                                     (u32) &D_80800F78_suexpressmorph,
                                     0x220502,
                                     0x0,
                                     (u32) &D_80800F78_suexpressmorph,
                                     0x4D0502,
                                     0x1000000,
                                     (u32) &D_8080102C_suexpressmorph,
                                     0xAE0503,
                                     0x0,
                                     (u32) &D_808010E0_suexpressmorph,
                                     0x400503,
                                     0x1000000,
                                     (u32) &D_80801194_suexpressmorph,
                                     0x6F0603,
                                     0x0,
                                     (u32) &D_8080126C_suexpressmorph,
                                     0xAF0503,
                                     0x0,
                                     0x0};
