#include "common.h"

// TU-NOTE: D_80128410 is the cube grid: cubes +0x00, min +0x04, max +0x10, strides +0x1C,
// cube count +0x24, dims +0x28. D_80128444 is the sentinel cube for positions outside.
extern s32 D_80128454;
typedef struct {
    s32 pad0;
    s32 lo[3];
    s32 hi[3];
    u8 pad1C[0x24];
    f32 scale;
} StructBD708;
typedef struct {
    u32 unk_0, unk_4;
} GridCell;
typedef struct {
    GridCell *cubes;
    u8 pad_4[0x30];
    GridCell outside;
} GridState;
extern f32 D_80128450;
extern s32 D_80128414[];
extern void func_800EFB58(s32 *, s32 *, s32 *);
extern s32 D_80128444[];
extern s16 D_8012844C;
typedef struct {
    s16 unk_0[4];
} CellBE;
typedef struct {
    CellBE *cubes;
    s32 cube_min[3];
    s32 cube_max[3];
    s32 stride[2];
    s32 cube_count;
    s32 dims[3];
} GridBE;
extern CellBE *D_80128458[];
extern s32 func_800E9DC4();
extern int D_801284C8[];
extern s32 D_80128538[];
extern s32 func_800E9DCC();
extern s32 D_80128420;
extern s32 D_80128438;
extern s32 D_8012842C;
extern u8 D_8012844E[];

typedef union {
    StructBD708 StructBD708;
    GridState GridState;
    u8 *u8p;
    GridBE GridBE;
    s32 arr[1];
} Union_D_80128410;
extern Union_D_80128410 D_80128410;
extern s32 D_80128434;

void func_800BD570()
{
    _gccubeDll_entrypoint_1(&D_80128410);
}

int func_800BD594(s32 gfx)
{
    if (func_800EA068(0x200)) {
        func_8010A874(gfx);
    } else {
        func_800D3104(gfx, (s32 *) D_80128410.arr);
    }
}

void func_800BD5DC()
{
    _gccubeDll_entrypoint_2(&D_80128410);
}

void func_800BD600(void)
{
    *(s32 *) ((s8 *) (s32 *) D_80128410.arr + 0) =
        defrag(*(s32 *) ((s8 *) (s32 *) D_80128410.arr + 0));
    D_80128454 = defrag(*(s32 *) ((s8 *) (s32 *) D_80128410.arr + 0x44));
    func_800E9DF8();
    func_800D2EE4();
}

// World position to cube coordinates, clamped to the grid.
void func_800BD64C(s32 *cube, f32 *pos)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (pos[i] >= 0.0f)
            cube[i] = (s32) (*(f32 *) ((u8 *) D_80128410.arr + 0x40) * pos[i]);
        else
            cube[i] =
                (s32) (*(f32 *) ((u8 *) D_80128410.arr + 0x40) * pos[i] + -1.0f);
        if (cube[i] < D_80128410.arr[1 + i])
            cube[i] = D_80128410.arr[1 + i];
        if (D_80128410.arr[4 + i] < cube[i])
            cube[i] = D_80128410.arr[4 + i];
    }
}

// Cube range covering the box spanned by two positions, padded by radius.
void func_800BD708(s32 *cube_min, s32 *cube_max, f32 *pos_a, f32 *pos_b, f32 radius)
{
    s32 i;
    StructBD708 *grid = (StructBD708 *) D_80128410.arr;
    f32 coord, bound;
    for (i = 0; i < 3; i++) {
        coord = pos_a[i] <= pos_b[i] ? pos_a[i] : pos_b[i];
        bound = coord - radius;
        if (bound >= 0.0f)
            cube_min[i] = bound * D_80128410.StructBD708.scale;
        else
            cube_min[i] = bound * D_80128410.StructBD708.scale + -1.0f;
        if (cube_min[i] < D_80128410.StructBD708.lo[i])
            cube_min[i] = D_80128410.StructBD708.lo[i];
        coord = pos_b[i] <= pos_a[i] ? pos_a[i] : pos_b[i];
        bound = coord + radius;
        if (bound >= 0.0f)
            cube_max[i] = bound * D_80128410.StructBD708.scale;
        else
            cube_max[i] = bound * D_80128410.StructBD708.scale + -1.0f;
        if (grid->hi[i] < cube_max[i])
            cube_max[i] = grid->hi[i];
    }
}

// Cube pointer to cube coordinates.
void func_800BD860(s32 cube, s32 *coords)
{
    s32 index;
    s32 rest;
    s32 i;
    index = (cube - D_80128410.arr[0]) >> 3;
    coords[2] = index / D_80128410.arr[8];
    rest = index - coords[2] * D_80128410.arr[8];
    coords[1] = rest / D_80128410.arr[7];
    coords[0] = rest - coords[1] * D_80128410.arr[7];
    for (i = 0; i < 3; i++)
        coords[i] += D_80128410.arr[i + 1];
}

// Cube pointer to cube index, -1 for the outside cube.
s32 func_800BD948(GridCell *cube)
{
    return cube == &D_80128410.GridState.outside ? -1 : cube - D_80128410.GridState.cubes;
}

// World position to cube index, -1 if outside the grid.
s32 func_800BD97C(pos)
s32 *pos;
{
    s32 cube[3];
    s32 rel[3];
    s32 i;
    for (i = 0; i < 3; i++) {
        if (pos[i] >= 0)
            cube[i] = pos[i] * D_80128450;
        else
            cube[i] = pos[i] * D_80128450 + -1.0f;
    }
    if (cube[0] < D_80128410.arr[1] || cube[1] < D_80128410.arr[2] ||
        cube[2] < D_80128410.arr[3] || D_80128410.arr[4] < cube[0] ||
        D_80128410.arr[5] < cube[1] || D_80128410.arr[6] < cube[2])
        return -1;
    func_800EFB58(rel, cube, D_80128414);
    return rel[0] + rel[1] * D_80128410.arr[7] + rel[2] * D_80128410.arr[8];
}

// Cube coordinates to cube pointer; the outside cube if out of range.
int func_800BDAD4(OSViCommonRegs *coords)
{
    if (((s32 *) coords)[0] < D_80128410.arr[1] || ((s32 *) coords)[1] < D_80128410.arr[2] ||
        ((s32 *) coords)[2] < D_80128410.arr[3] || D_80128410.arr[4] < ((s32 *) coords)[0] ||
        D_80128410.arr[5] < ((s32 *) coords)[1] || D_80128410.arr[6] < ((s32 *) coords)[2]) {
        return (int) (&D_80128444);
    }

    return D_80128410.arr[0] + (((s32 *) coords)[0] - D_80128410.arr[1]) * 8 +
           (((s32 *) coords)[1] - D_80128410.arr[2]) * D_80128410.arr[7] * 8 +
           (((s32 *) coords)[2] - D_80128410.arr[3]) * D_80128410.arr[8] * 8;
}

// Cube index to cube pointer.
int func_800BDB9C(s32 index)
{
    int cube;
    if (index < 0) {
        cube = (u32) ((int *) D_80128444);
    } else {
        cube = (u32) (D_80128410.u8p + index * 8);
    }
    return cube;
}

int func_800BDBC4()
{
    func_800BDB9C(func_800BD97C());
}

s32 func_800BDBEC(f32 *pos)
{
    s32 pos_i[3];

    pos_i[0] = pos[0];
    pos_i[1] = pos[1];
    pos_i[2] = pos[2];
    return func_800BDBC4(pos_i);
}

int func_800BDC44()
{
    return (int) ((s32 *) D_80128444);
}

s32 func_800BDC50()
{
    return D_80128434;
}

int func_800BDC5C()
{
    return D_8012844C;
}

int func_800BDC68(s32 arg)
{
    s32 value;
    // Matching: the no-op OR is needed for the match.
    value = arg | 0;
    _gccubeDll_entrypoint_3(((s32 *) D_80128410.arr), value);
}

int func_800BDC90(s32 arg)
{
    s32 value;
    // Matching: the no-op OR is needed for the match.
    value = arg | 0;
    _gccubeDll_entrypoint_4(((s32 *) D_80128410.arr), value);
}

void func_800BDCB8()
{
    _gccubeDll_entrypoint_0(&D_80128410);
}

void func_800BDCDC()
{
    _gccubeDll_entrypoint_5(&D_80128410);
}

void func_800BDD00()
{
    _gccubeDll_entrypoint_6(&D_80128410);
}

// Gathers the non-empty cubes of the 3x3x3 neighbourhood around pos into a static list.
CellBE **func_800BDD24(s32 *pos)
{
    s32 unk_0;
    s32 n;
    s32 plane_start;
    s32 center[3];
    s32 cur[3];
    s32 cube_idx;
    for (n = 0; n < 3; n++) {
        // Matching: both branches of the conditional are identical.
        center[n] = ((pos[n] >= 0) ? pos[n] * D_80128450
                                                    : pos[n] * D_80128450) -
                           D_80128410.GridBE.cube_min[n];
    }
    n = 0;
    if (center[0] > 0 && center[0] < D_80128410.GridBE.dims[0] - 1 && center[1] > 0 &&
        center[1] < D_80128410.GridBE.dims[1] - 1 && center[2] > 0 &&
        center[2] < D_80128410.GridBE.dims[2] - 1) {
        plane_start = (center[0] - 1) + (center[1] - 1) * D_80128410.GridBE.stride[0] +
                  (center[2] - 1) * D_80128410.GridBE.stride[1];
        cube_idx = plane_start;
        for (cur[0] = 0; cur[0] < 3;
             cur[0]++, plane_start += D_80128410.GridBE.stride[1], cube_idx = plane_start) {
            for (cur[1] = 0; cur[1] < 3;
                 cur[1]++, cube_idx += D_80128410.GridBE.stride[0] - 3) {
                for (cur[2] = 0; cur[2] < 3; cur[2]++, cube_idx++) {

if (func_800E9DC4((s16 *) (cube_idx + D_80128410.GridBE.cubes))) {
    D_80128458[n++] = cube_idx + D_80128410.GridBE.cubes;
}

}
}
}
}
else
{
    for (cur[0] = center[0] - 1; cur[0] < center[0] + 2; cur[0]++) {
        if (cur[0] >= 0 && cur[0] < D_80128410.GridBE.dims[0]) {
            for (cur[1] = center[1] - 1; cur[1] < center[1] + 2; cur[1]++) {
                if (cur[1] >= 0 && cur[1] < D_80128410.GridBE.dims[1]) {
                    for (cur[2] = center[2] - 1; cur[2] < center[2] + 2; cur[2]++) {
                        if (cur[2] >= 0 && cur[2] < D_80128410.GridBE.dims[2]) {
                            cube_idx = cur[0] + cur[1] * D_80128410.GridBE.stride[0] +
                                      cur[2] * D_80128410.GridBE.stride[1];
                            if (func_800E9DC4((s16 *) (cube_idx + D_80128410.GridBE.cubes))) {
                                D_80128458[n++] = cube_idx + D_80128410.GridBE.cubes;
                            }
                        }
                    }
                }
            }

}
}
}
D_80128458[n] = 0;
return D_80128458;
}

// Same as func_800BDD24 but writes into out and returns the count.
s32 func_800BE09C(CellBE **out, s32 *pos)
{
    s32 unk_0;
    s32 n;
    s32 plane_start;
    s32 center[3];
    s32 cur[3];
    s32 cube_idx;
    for (n = 0; n < 3; n++) {
        // Matching: both branches of the conditional are identical.
        center[n] = ((pos[n] >= 0) ? pos[n] * D_80128450
                                                    : pos[n] * D_80128450) -
                           D_80128410.GridBE.cube_min[n];
    }
    n = 0;
    if (center[0] > 0 && center[0] < D_80128410.GridBE.dims[0] - 1 && center[1] > 0 &&
        center[1] < D_80128410.GridBE.dims[1] - 1 && center[2] > 0 &&
        center[2] < D_80128410.GridBE.dims[2] - 1) {
        plane_start = (center[0] - 1) + (center[1] - 1) * D_80128410.GridBE.stride[0] +
                  (center[2] - 1) * D_80128410.GridBE.stride[1];
        cube_idx = plane_start;
        for (cur[0] = 0; cur[0] < 3;
             cur[0]++, plane_start += D_80128410.GridBE.stride[1], cube_idx = plane_start) {
            for (cur[1] = 0; cur[1] < 3;
                 cur[1]++, cube_idx += D_80128410.GridBE.stride[0] - 3) {
                for (cur[2] = 0; cur[2] < 3; cur[2]++, cube_idx++) {

if (func_800E9DCC((s16 *) (cube_idx + D_80128410.GridBE.cubes))) {
    out[n++] = cube_idx + D_80128410.GridBE.cubes;
}

}
}
}
}
else
{
    for (cur[0] = center[0] - 1; cur[0] < center[0] + 2; cur[0]++) {
        if (cur[0] >= 0 && cur[0] < D_80128410.GridBE.dims[0]) {
            for (cur[1] = center[1] - 1; cur[1] < center[1] + 2; cur[1]++) {
                if (cur[1] >= 0 && cur[1] < D_80128410.GridBE.dims[1]) {
                    for (cur[2] = center[2] - 1; cur[2] < center[2] + 2; cur[2]++) {
                        if (cur[2] >= 0 && cur[2] < D_80128410.GridBE.dims[2]) {
                            cube_idx = cur[0] + cur[1] * D_80128410.GridBE.stride[0] +
                                      cur[2] * D_80128410.GridBE.stride[1];
                            if (func_800E9DCC((s16 *) (cube_idx + D_80128410.GridBE.cubes))) {
                                out[n++] = cube_idx + D_80128410.GridBE.cubes;
                            }
                        }
                    }
                }
            }

}
}
}
return n;
}

int *func_800BE3F8(s32 src)
{
    f32 pos_f[3];
    func_800EE904(pos_f, src);
    D_801284C8[func_800BE09C(&D_801284C8, pos_f)] = 0;
    return D_801284C8;
}

s32 func_800BE444(s32 src)
{
    f32 pos_f[3];
    s32 count;
    func_800EE904(pos_f, src);
    count = func_800BE09C(&D_80128538, pos_f);
    if (func_800E9DCC(((void **) D_80128444))) {
        D_80128538[count] = (s32) ((void **) D_80128444);
        count++;
    }
    D_80128538[count] = 0;
    return (s32) D_80128538;
}

void func_800BE4C4(void)
{
    u32 cube;
    int cubes_end2;
    u32 cubes_end;
    cube = *((u32 *) (((u8 *) D_80128410.arr)));
    cubes_end = ((*((s32 *) (&((u8 *) D_80128410.arr)[0x24]))) * 8) + cube;
    // Matching: duplicate of cubes_end, needed for the match.
    cubes_end2 = ((*((s32 *) (&((u8 *) D_80128410.arr)[0x24]))) * 8) + cube;
    if (cube < cubes_end) {
        do {
            func_800E9CF4((u8 *) cube);
            cube += 8;
        } while (cube < cubes_end2);
    }
    func_800E9CF4(((u8 *) D_80128444));
}

// Start and end of the cube array.
int func_800BE52C(s32 *out_begin, s32 *out_end)
{
    *out_begin = D_80128410.arr[0];
    *out_end = D_80128410.arr[0] + (D_80128410.arr[9] << 3);
}

int func_800BE554(s32 src_min, s32 src_max)
{
    func_800EE830(src_min, ((s32 *) D_80128414));
    func_800EE830(src_max, &D_80128420);
}

int func_800BE58C(s32 src_a, s32 src_b)
{
    func_800EE830(src_a, &D_80128438);
    func_800EE830(src_b, &D_8012842C);
}

int func_800BE5C4(s32 cube)
{
    s32 base = (s32) ((u8 *) D_80128410.arr);
    if (cube == base + 0x34) {
        return (s32) D_8012844E;
    }
    return *(s32 *) (base + 0x44) + ((cube - *(s32 *) (base)) >> 3);
}
