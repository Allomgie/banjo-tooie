#include "common.h"

#define ENT D_80801818_suexpressjoint[*(s16 *) (param_0 + 6)]
extern s16 D_80801820_suexpressjoint;
extern s16 D_80801830_suexpressjoint[];
extern s32 D_80801838_suexpressjoint[];
extern int D_80801824_suexpressjoint;
typedef struct {
    u8 pad_0[4];
    s16 id;
    s16 preset;
    u8 intensity;
    u8 pad_9[0x17];
    u8 values[32];
} ExpressionJoint_suexpressjoint_entrypoint_2;
// One bone override: bone index, sign flags, pose (9 floats per weight).
typedef struct {
    u8 bone;
    u8 sign_flags;
    u8 pad_2[2];
    f32 *pose;
} SejItem;
typedef u8 SejRow[4];
// One joint preset.
typedef struct {
    SejItem *list;
    SejRow *data;
    u16 id;
    u8 default_row;
    u8 item_count;
    u8 weight_count;
    u8 pad_D[3];
} SejEnt;
extern SejEnt D_80801818_suexpressjoint[];
typedef struct {
    f32 timer;
    s16 id;
    s16 preset;
    u8 intensity;
    u8 pad_9[3];
    f32 w[4];
    f32 sum;
    u8 values[32];
} ExpressionJoint_suexpressjoint_entrypoint_3;
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void *func_801040A8(s32);
extern void *func_800AE6BC(void *);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void func_800E0C20(void *, s32, f32, f32, f32, f32);
extern void func_800E0B8C(void *, s32, f32, f32, f32, f32);

// Returns the preset index for a preset id, or -1 if unknown.
s32 func_80800000_suexpressjoint(s32 id)
{
    s8 *entry;
    s32 index;

    if (id == D_80801820_suexpressjoint) {
        return 0;
    }
    entry = D_80801838_suexpressjoint;
    index = 2;
    if (id == D_80801830_suexpressjoint[0]) {
        return 1;
    }
loop_5:
    if (id == *(s16 *) ((s8 *) entry + 8)) {
        return index;
    }
    if (id == *(s16 *) ((s8 *) entry + 0x18)) {
        return index + 1;
    }
    if (id == *(s16 *) ((s8 *) entry + 0x28)) {
        return index + 2;
    }
    if (id == *(s16 *) ((s8 *) entry + 0x38)) {
        return index + 3;
    }
    index += 4;
    entry += 0x40;
    if (index == 0x16) {
        return -1;
    }
    goto loop_5;
}

// Returns the block size for a preset id (weight count + 0x20).
int suexpressjoint_entrypoint_0(id)
s16 id;
{
    s32 index;
    int size;
    index = func_80800000_suexpressjoint(id);
    if (index == -1) {
        return 0;
    }
    size = ((u8 *) &D_80801824_suexpressjoint)[index * 0x10] + 0x20;
    return size;
}

void suexpressjoint_entrypoint_1(s16 *block, s16 id)
{
    block[2] = id;
    block[3] = func_80800000_suexpressjoint(block[2]);
}

// Initialises the block from the preset's default pose.
void suexpressjoint_entrypoint_2(ExpressionJoint_suexpressjoint_entrypoint_2 *block, s16 id)
{
    u8 *dst;
    s32 i;
    dst = block->values;
    suexpressjoint_entrypoint_1((s16 *) block, id);
    block->intensity = 0;
    for (i = 0; i < D_80801818_suexpressjoint[block->preset].weight_count; i++) {
        *dst++ = D_80801818_suexpressjoint[block->preset]
                     .data[D_80801818_suexpressjoint[block->preset].default_row][i];
    }
}

// Per-frame update: eases the weights toward the pose row requested by the dialog box.
void suexpressjoint_entrypoint_3(s32 unk_0, ExpressionJoint_suexpressjoint_entrypoint_3 *joint,
                                 s32 unk_2)
{
    f32 target[4];
    s32 row;
    f32 unk_1;
    u8 *cur;
    f32 step;
    s32 i;

    joint->sum = 0.0f;
    cur = joint->values;
    row = D_80801818_suexpressjoint[joint->preset].default_row;
    if (unk_2 != 0 && func_800D52F4() == joint->id) {
        row = func_800D52A4() - 1;
        if (row < 0) {
            row = D_80801818_suexpressjoint[joint->preset].default_row;
        }
        if (func_800D5298() != 0) {
            joint->timer = 0.05f;
        }
        if (joint->timer > 0.0f) {
            joint->timer = joint->timer - func_800D8FF8();
        } else if (joint->timer < 0.0f) {
            row = D_80801818_suexpressjoint[joint->preset].default_row;
            joint->timer = 0.0f;
        }
        step = (100 - joint->intensity) * 0.2f;
        if (step < 2.0f) {
            step = 2.0f;
        }
        joint->intensity = (u32) func_800F15F8((f32) (u32) joint->intensity, 100.0f, step);
    } else {
        joint->intensity = (u32) ((f32) (u32) joint->intensity - (f32) (u32) joint->intensity * 0.2f);
    }
    for (i = 0; i < D_80801818_suexpressjoint[joint->preset].weight_count; i++) {
        target[i] = (f32) (u32) D_80801818_suexpressjoint[joint->preset].data[row][i];
        *cur = (u32) ((target[i] - (f32) *cur) * 0.15f + (f32) *cur);
        joint->w[i] = (f32) (u32) *cur * 0.01f;
        cur++;
        joint->sum += joint->w[i];
    }
    if (joint->sum != 0.0f) {
        for (i = 0; i < D_80801818_suexpressjoint[joint->preset].weight_count; i++) {
            joint->w[i] = joint->w[i] / joint->sum;
        }
    }
}

// Draw time: writes the weighted bone overrides, scaled by the block's intensity.
void suexpressjoint_entrypoint_4(u8 *param_0, s32 unk_1)
{
    s32 k;
    f32 intensity;
    void *bones;
    f32 trans[3];
    f32 rot[3];
    f32 scl[3];
    s32 item;
    s32 j;

    intensity = (f32) (u32) param_0[8] * 0.01f;
    bones = func_800AE6BC(func_801040A8(unk_1));
    for (item = 0; item < ENT.item_count; item++) {
        for (j = 0; j < 3; j++) {
            rot[j] = 0.0f;
            trans[j] = 0.0f;
            scl[j] = 0.0f;
            for (k = 0; k < ENT.weight_count; k++) {
                rot[j] = (((f32(*)[9]) ENT.list[item].pose)[k][j] *
                          ((f32 *) (param_0 + 0xC))[k]) +
                         rot[j];
                trans[j] = (((f32(*)[9]) ENT.list[item].pose)[k][j + 3] *
                            ((f32 *) (param_0 + 0xC))[k]) +
                           trans[j];
                scl[j] = (((f32(*)[9]) ENT.list[item].pose)[k][j + 6] *
                          ((f32 *) (param_0 + 0xC))[k]) +
                         scl[j];
            }
        }
        if (ENT.list[item].sign_flags & 1) {
            func_800E0AFC(bones, ENT.list[item].bone, intensity, trans[0], trans[1], trans[2]);
        } else {
            func_800E0AFC(bones, ENT.list[item].bone, -intensity, trans[0], trans[1], trans[2]);
        }
        if (ENT.list[item].sign_flags & 2) {
            func_800E0C20(bones, ENT.list[item].bone, intensity, rot[0], rot[1], rot[2]);
        } else {
            func_800E0C20(bones, ENT.list[item].bone, -intensity, rot[0], rot[1], rot[2]);
        }
        if (ENT.list[item].sign_flags & 4) {
            func_800E0B8C(bones, ENT.list[item].bone, intensity, scl[0], scl[1], scl[2]);
        } else {
            func_800E0B8C(bones, ENT.list[item].bone, -intensity, scl[0], scl[1], scl[2]);
        }
    }
}

// TU-NOTE: the overlay .data is defined here in C, values taken from the ROM.
// D_80801820 = D_80801818 + 0x8 and D_80801824 = D_80801818 + 0xC are linker
// symbols (undefined_syms.us.txt). The externs D_80801830 (s16[]) and D_80801838
// (s32[]) are declared as arrays over the objects defined below.
u32 D_80800A60_suexpressjoint[27] = {
    0x0, 0x0,        0x0,        0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x408F0A3D, 0x3F7D70A4, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x3FF851EC, 0x3F07AE14, 0x0, 0x0, 0x0, 0x3F333333, 0x3F6147AE, 0x3F800000};
u32 D_80800ACC_suexpressjoint[27] = {
    0x0, 0x0,        0x0,        0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0xBF9D70A4, 0x3F000000, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x3EC7AE14, 0x3F000000, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800B38_suexpressjoint[27] = {
    0x0, 0x0, 0x0,        0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0,        0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x3F47AE14, 0x0, 0x0, 0x0, 0x3F47AE14, 0x3F800000, 0x3F800000};
u32 D_80800BA4_suexpressjoint[6] = {0x2A010000, (u32) &D_80800A60_suexpressjoint,
                                    0x2B010000, (u32) &D_80800ACC_suexpressjoint,
                                    0x2C010000, (u32) &D_80800B38_suexpressjoint};
u32 D_80800BBC_suexpressjoint[3] = {0x64000000, 0x640000, 0x6400};
u32 D_80800BC8_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC0700000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC0B8F5C3, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800C58_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41C8B852, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x4178A3D7, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC117D70A, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800CE8_suexpressjoint[4] = {0x12010000, (u32) &D_80800BC8_suexpressjoint, 0x35000000,
                                    (u32) &D_80800C58_suexpressjoint};
u32 D_80800CF8_suexpressjoint[5] = {0x64000000, 0x640000, 0x6400, 0x64, 0x323200};
u32 D_80800D0C_suexpressjoint[18] = {
    0x0, 0x0, 0x0, 0x41F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC1600000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800D54_suexpressjoint[2] = {0x2B000000, (u32) &D_80800D0C_suexpressjoint};
u32 D_80800D5C_suexpressjoint[3] = {0x64000000, 0x640000, 0x320000};
u32 D_80800D68_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x40A00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC1700000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800DF8_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0xC0A00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800E88_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC1F00000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80800F18_suexpressjoint[6] = {0x2A010000, (u32) &D_80800D68_suexpressjoint,
                                    0x4A010000, (u32) &D_80800DF8_suexpressjoint,
                                    0x4F010000, (u32) &D_80800E88_suexpressjoint};
u32 D_80800F30_suexpressjoint[24] = {
    0x64000000, 0x320000,   0x640000,   0x6400, 0x32,       0x64,       0x0,        0x0,
    0x0,        0x41A00000, 0x0,        0x0,    0x40400000, 0x40400000, 0x40400000, 0x0,
    0x0,        0x0,        0xC1F00000, 0x0,    0x0,        0x40800000, 0x40800000, 0x40800000};
u32 D_80800F90_suexpressjoint[2] = {0x3010000, (u32) &D_80800E88_suexpressjoint};
u32 D_80800F98_suexpressjoint[2] = {0x64000000, 0x640000};
u32 D_80800FA0_suexpressjoint[4] = {0x2A010000, (u32) &D_80800D68_suexpressjoint, 0x4A010000,
                                    (u32) &D_80800DF8_suexpressjoint};
u32 D_80800FB0_suexpressjoint[3] = {0x64000000, 0x320000, 0x640000};
u32 D_80800FBC_suexpressjoint[18] = {
    0x0, 0x0, 0x0, 0xC1C347AE, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC11C7AE1, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80801004_suexpressjoint[18] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0xC005C28F, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_8080104C_suexpressjoint[18] = {
    0x0, 0x0, 0x0, 0xC1B80000, 0x0, 0x0, 0x3F19999A, 0x3F19999A, 0x3F19999A,
    0x0, 0x0, 0x0, 0xC17EB852, 0x0, 0x0, 0x3F19999A, 0x3F19999A, 0x3F19999A};
u32 D_80801094_suexpressjoint[6] = {0x52000000, (u32) &D_80800FBC_suexpressjoint,
                                    0x51010000, (u32) &D_80801004_suexpressjoint,
                                    0x53000000, (u32) &D_8080104C_suexpressjoint};
u32 D_808010AC_suexpressjoint[2] = {0x64000000, 0x640000};
u32 D_808010B4_suexpressjoint[9] = {0x0, 0x0,        0x0,        0x0,       0x0,
                                    0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808010D8_suexpressjoint[9] = {0x0, 0x0,        0x0,        0x0,       0x0,
                                    0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808010FC_suexpressjoint[4] = {0x12000000, (u32) &D_808010B4_suexpressjoint, 0x2A000000,
                                    (u32) &D_808010D8_suexpressjoint};
u32 D_8080110C_suexpressjoint[3] = {0x64000000, 0x64000000, 0x64000000};
u32 D_80801118_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808011A8_suexpressjoint[2] = {0x12010000, (u32) &D_80801118_suexpressjoint};
u32 D_808011B0_suexpressjoint[5] = {0x1E000000, 0x640028, 0x506432, 0x3232, 0x32001E};
u32 D_808011C4_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80801254_suexpressjoint[2] = {0x12010000, (u32) &D_808011C4_suexpressjoint};
u32 D_8080125C_suexpressjoint[3] = {0x32000000, 0x640032, 0x6432};
u32 D_80801268_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808012F8_suexpressjoint[2] = {0x12010000, (u32) &D_80801268_suexpressjoint};
u32 D_80801300_suexpressjoint[3] = {0x32000000, 0x640032, 0x6432};
u32 D_8080130C_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_8080139C_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_8080142C_suexpressjoint[4] = {0x29010000, (u32) &D_8080130C_suexpressjoint, 0x2A000000,
                                    (u32) &D_8080139C_suexpressjoint};
u32 D_8080143C_suexpressjoint[3] = {0x64000000, 0x640032, 0x6432};
u32 D_80801448_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x41200000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41A00000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x42200000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41F00000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808014D8_suexpressjoint[2] = {0x2A030000, (u32) &D_80801448_suexpressjoint};
u32 D_808014E0_suexpressjoint[3] = {0x32000000, 0x640032, 0x6432};
u32 D_808014EC_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0,        0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40000000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_8080157C_suexpressjoint[2] = {0x12010000, (u32) &D_808014EC_suexpressjoint};
u32 D_80801584_suexpressjoint[3] = {0x32000000, 0x640032, 0x6432};
u32 D_80801590_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x40A00000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41100000, 0x0, 0x40C00000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41100000, 0x0, 0xC0C00000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41200000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_80801620_suexpressjoint[2] = {0x12010000, (u32) &D_80801590_suexpressjoint};
u32 D_80801628_suexpressjoint[3] = {0x64000000, 0x640000, 0x6400};
u32 D_80801634_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x40A00000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41100000, 0x0, 0x40C00000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41100000, 0x0, 0xC0C00000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x41200000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808016C4_suexpressjoint[2] = {0x12010000, (u32) &D_80801634_suexpressjoint};
u32 D_808016CC_suexpressjoint[4] = {0x64000000, 0x320000, 0x3200, 0x320000};
u32 D_808016DC_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x40400000, 0x0, 0xC0000000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0x40400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40800000, 0x0, 0xC0400000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x40A00000, 0x0, 0x0,        0x3F800000, 0x3F800000, 0x3F800000};
u32 D_8080176C_suexpressjoint[36] = {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x3F800000};
u32 D_808017FC_suexpressjoint[4] = {0x12010000, (u32) &D_808016DC_suexpressjoint, 0x2A000000,
                                    (u32) &D_8080176C_suexpressjoint};
u32 D_8080180C_suexpressjoint[3] = {0x64000000, 0x640000, 0x6400};
// Preset table: the first entry is D_80801818, the rest continues at D_80801830/D_80801838.
SejEnt D_80801818_suexpressjoint[1] = {(void *) &D_80800F18_suexpressjoint,
                                       (void *) &D_80800F30_suexpressjoint,
                                       0xC,
                                       0x0,
                                       0x3,
                                       0x4,
                                       0x0,
                                       0x0,
                                       0x0};
static u32 D_80801818_suexpressjoint_rest[2] = {(u32) &D_80800F18_suexpressjoint,
                                                (u32) &D_80800F30_suexpressjoint};
s16 D_80801830_suexpressjoint[4] = {0xD, 0x3, 0x400, 0x0};
s32 D_80801838_suexpressjoint[82] = {(u32) &D_80800F18_suexpressjoint,
                                     (u32) &D_80800F30_suexpressjoint,
                                     0xE0003,
                                     0x4000000,
                                     (u32) &D_80800CE8_suexpressjoint,
                                     (u32) &D_80800CF8_suexpressjoint,
                                     0x100002,
                                     0x4000000,
                                     (u32) &D_80800CE8_suexpressjoint,
                                     (u32) &D_80800CF8_suexpressjoint,
                                     0x770002,
                                     0x4000000,
                                     (u32) &D_80800D54_suexpressjoint,
                                     (u32) &D_80800D5C_suexpressjoint,
                                     0x3A0101,
                                     0x2000000,
                                     (u32) &D_80800BA4_suexpressjoint,
                                     (u32) &D_80800BBC_suexpressjoint,
                                     0x420103,
                                     0x3000000,
                                     (u32) &D_80800FA0_suexpressjoint,
                                     (u32) &D_80800FB0_suexpressjoint,
                                     0x5B0002,
                                     0x3000000,
                                     (u32) &D_80800F90_suexpressjoint,
                                     (u32) &D_80800F98_suexpressjoint,
                                     0x5C0001,
                                     0x2000000,
                                     (u32) &D_80801094_suexpressjoint,
                                     (u32) &D_808010AC_suexpressjoint,
                                     0x750003,
                                     0x2000000,
                                     (u32) &D_80801094_suexpressjoint,
                                     (u32) &D_808010AC_suexpressjoint,
                                     0x760003,
                                     0x2000000,
                                     (u32) &D_808011A8_suexpressjoint,
                                     (u32) &D_808011B0_suexpressjoint,
                                     0x790001,
                                     0x4000000,
                                     (u32) &D_80801254_suexpressjoint,
                                     (u32) &D_8080125C_suexpressjoint,
                                     0x7A0001,
                                     0x4000000,
                                     (u32) &D_808012F8_suexpressjoint,
                                     (u32) &D_80801300_suexpressjoint,
                                     0x7E0001,
                                     0x4000000,
                                     (u32) &D_808010FC_suexpressjoint,
                                     (u32) &D_8080110C_suexpressjoint,
                                     0x7F0002,
                                     0x1000000,
                                     (u32) &D_8080142C_suexpressjoint,
                                     (u32) &D_8080143C_suexpressjoint,
                                     0x800002,
                                     0x4000000,
                                     (u32) &D_808010FC_suexpressjoint,
                                     (u32) &D_8080110C_suexpressjoint,
                                     0xAB0002,
                                     0x1000000,
                                     (u32) &D_808014D8_suexpressjoint,
                                     (u32) &D_808014E0_suexpressjoint,
                                     0x220001,
                                     0x4000000,
                                     (u32) &D_8080157C_suexpressjoint,
                                     (u32) &D_80801584_suexpressjoint,
                                     0xAE0001,
                                     0x4000000,
                                     (u32) &D_80801620_suexpressjoint,
                                     (u32) &D_80801628_suexpressjoint,
                                     0x400001,
                                     0x4000000,
                                     (u32) &D_808016C4_suexpressjoint,
                                     (u32) &D_808016CC_suexpressjoint,
                                     0x6F0001,
                                     0x4000000,
                                     (u32) &D_808017FC_suexpressjoint,
                                     (u32) &D_8080180C_suexpressjoint,
                                     0xAF0002,
                                     0x4000000,
                                     0x0,
                                     0x0};
