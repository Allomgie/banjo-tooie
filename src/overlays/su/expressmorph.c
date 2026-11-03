#include "common.h"
typedef struct {
    void *rows;
    u8 pad_4[3];
    u8 local_0;
    u32 unk8;
} MorphPreset_suexpressmorph_entrypoint_0;
extern MorphPreset_suexpressmorph_entrypoint_0 D_80801320_suexpressmorph[];

extern s16 D_80801324_suexpressmorph;
extern u32 D_8080132C_suexpressmorph[];
typedef struct {
    s16 local_0;
    s16 pad_0;
    f32 local_1[4];
    f32 local_2[4];
} Broad51MorphRow;
typedef struct {
    Broad51MorphRow *local_0;
    s16 pad_0;
    u8 local_1;
    u8 local_2;
    s32 pad_1;
} Broad51MorphPreset;
typedef struct MorphValues {
    f32 local_0;
    f32 local_1[4];
    f32 local_2[4];
} MorphValues;
typedef struct {
    s16 local_0;
    s16 local_1;
    u8 pad_0[2];
    u8 local_2;
    u8 pad_1;
    f32 local_3[3];
} MorphParameters1358;
typedef struct {
    u8 pad_0 : 7;
    u8 local_0 : 1;
    u8 pad_1[11];
} MorphEntry1358;
extern MorphEntry1358 D_80801328_suexpressmorph[];
typedef struct {
    u8 pad_0[7];
    u8 local_0;
    u8 pad_1[4];
} MorphPreset_suexpressmorph_entrypoint_5;
typedef struct {
    f32 f[9];
} MorphRow;
typedef struct {
    MorphRow *rows;
    s16 pad4;
    u8 pad6;
    u8 count;
    s32 pad8;
} MorphPreset_808000EC_suexpressmorph;
extern f32 func_800D8FF8(void);

s32 func_80800000_suexpressmorph(s32 param_0)
{
    s8 *var_v0;
    s32 var_v1;

    var_v0 = (s8 *) &D_8080132C_suexpressmorph;
    var_v1 = 1;
    if (param_0 == D_80801324_suexpressmorph) {
        return 0;
    }
loop_3:
    if (param_0 == *(s16 *) ((s8 *) var_v0 + 4)) {
        return var_v1;
    }
    if (param_0 == *(s16 *) ((s8 *) var_v0 + 0x10)) {
        return var_v1 + 1;
    }
    if (param_0 == *(s16 *) ((s8 *) var_v0 + 0x1C)) {
        return var_v1 + 2;
    }
    if (param_0 == *(s16 *) ((s8 *) var_v0 + 0x28)) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x30;
    if (var_v1 == 0x11) {
        return -1;
    }
    goto loop_3;
}

s32 suexpressmorph_entrypoint_0(param_0)
s16 param_0;
{
    s32 idx;
    s32 x;

    idx = func_80800000_suexpressmorph(param_0);
    if (idx == -1) {
        return 0;
    }
    x = D_80801320_suexpressmorph[idx].local_0 * 4;
    x += 8;
    x += D_80801320_suexpressmorph[idx].local_0 * 4;
    return x;
}

void func_808000EC_suexpressmorph(param_0, param_1) f32 *param_0;
u8 *param_1;
{
    f32 *local_0;
    f32 *local_1;
    f32 *local_2;
    s32 off;
    s32 i;

    local_0 = (f32 *) (param_1 + 8);
    local_1 = param_0;
    local_2 =
        local_0 +
        ((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
            .count;
    off = 0;
    i = 0;
    for (;
         i <
         ((MorphPreset_808000EC_suexpressmorph *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
             .count;
         i++, off += 4, local_1++, local_0++, local_2++) {
        if (*local_2 <= 0) {
            *local_1 = *(f32 *) ((s32) ((MorphPreset_808000EC_suexpressmorph *)
                                            D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                                     .rows[param_1[5]]
                                     .f +
                                 off + 4);
        } else {
            *local_2 -= func_800D8FF8();
            if (local_1) {
            }
        }
        if (*local_1 < *local_0) {
            *local_0 += (*local_1 - *local_0) * 0.2f;
            if (*local_0 < 0.0f)
                *local_0 = 0.0f;
        } else if (*local_0 < *local_1) {
            *local_0 += (*local_1 - *local_0) * 0.2f;
            if (*local_0 > 1.0f)
                *local_0 = 1.0f;
        }
    }
}

void func_808002BC_suexpressmorph(f32 *param_0, u8 *param_1)
{
    s32 local_2;
    f32 *local_3;
    s32 local_4;
    Broad51MorphRow *local_5;
    s32 local_1;
    s32 local_0;
    local_0 = -1;
    local_3 = (f32 *) (param_1 + 8) +
              ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)].local_2;
    if (func_800D52F4() == *(s16 *) param_1) {
        local_2 = func_800D52A4() + 1;
        local_1 = 0;
        if (local_1 < (&((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)])
                          ->local_1) {
            local_5 = (&((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)])
                          ->local_0;
            do {
                if (local_2 == local_5->local_0) {
                    local_0 = local_1;
                }
                local_1++;
                local_5++;
            } while (local_1 <
                     (&((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)])
                         ->local_1);
        }
        if (func_800D5298()) {
            for (local_1 = 0;
                 local_1 <
                 ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)].local_2;
                 local_1++, local_3++) {
                if (((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                        .local_0[local_0]
                        .local_1[local_1] != -1.0f) {
                    if (*local_3 <
                        ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                            .local_0[local_0]
                            .local_2[local_1]) {
                        *local_3 = ((
                            Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                                       .local_0[local_0]
                                       .local_2[local_1];
                        param_0[local_1] = ((
                            Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                                               .local_0[local_0]
                                               .local_1[local_1];
                    }
                }
            }
        } else {
            for (local_1 = 0;
                 local_1 <
                 ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)].local_2;
                 local_1++) {
                if (((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                        .local_0[local_0]
                        .local_1[local_1] != -1.0f) {
                    param_0[local_1] =
                        ((Broad51MorphPreset *) D_80801320_suexpressmorph)[*(s16 *) (param_1 + 2)]
                            .local_0[local_0]
                            .local_1[local_1];
                }
            }
        }
    }
}

void suexpressmorph_entrypoint_1(u8 *param_0)
{
    f32 local_0[4];
    s32 local_1;

    for (local_1 = 0; local_1 < D_80801320_suexpressmorph[*(s16 *) (param_0 + 2)].local_0;
         local_1++) {
        local_0[local_1] =
            (*(MorphValues **) &D_80801320_suexpressmorph[*(s16 *) (param_0 + 2)])[param_0[5]]
                .local_1[local_1];
    }
    func_808002BC_suexpressmorph(local_0, param_0);
    func_808000EC_suexpressmorph(local_0, param_0);
}

void suexpressmorph_entrypoint_2(MorphParameters1358 *param_0, u8 **param_1)
{
    s32 pad0;
    s32 local_0;
    s32 local_2;
    u8 *local_1;
    s32 local_3;
    local_0 = func_80103AA0(*param_1);
    if (local_0) {
        local_1 = (u8 *) func_80103CDC(param_1, local_0);
        if (local_1) {
            local_2 = func_800B2840(local_0);
            local_3 = func_800B2768(local_0);
            _dbmorph_entrypoint_3(local_3, local_1, local_2, param_0->local_2, param_0->local_3);
            if (D_80801328_suexpressmorph[param_0->local_1].local_0) {
                if (((((!local_3 && 1) && !local_3) & 0xFFu) & 0xFFu) & 0xFFu) {
                }
                local_1[0x17] |= 1;
                _dbmorph_entrypoint_4(local_3, local_1, local_2, param_0->local_2,
                                      func_800AE080(*(s16 *) (*param_1 + 0x10)));
            }
        }
    }
}

void suexpressmorph_entrypoint_3(s16 *param_0, s16 param_1)
{
    param_0[0] = param_1;
    param_0[1] = func_80800000_suexpressmorph(param_0[0]);
}

void suexpressmorph_entrypoint_4(s32 param_0, s32 param_1)
{
    *(u8 *) ((char *) param_0 + 6) = param_1;
}

void suexpressmorph_entrypoint_5(u8 *param_0, s16 param_1)
{
    f32 *local_0;
    f32 *local_1;
    s32 local_2;

    suexpressmorph_entrypoint_3(param_0, param_1);
    param_0[5] = 0;
    param_0[6] = 1;
    local_0 = (f32 *) (param_0 + 8);
    local_1 = local_0 + ((MorphPreset_suexpressmorph_entrypoint_5 *)
                             D_80801320_suexpressmorph)[*(s16 *) (param_0 + 2)]
                            .local_0;
    for (local_2 = 0; local_2 < ((MorphPreset_suexpressmorph_entrypoint_5 *)
                                     D_80801320_suexpressmorph)[*(s16 *) (param_0 + 2)]
                                    .local_0;
         local_2++) {
        *local_0++ = 0.0f;
        *local_1++ = 0.0f;
    }
}

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
