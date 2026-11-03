#include "common.h"

extern f32 func_800E42C0(void);
extern s32 func_800E3D0C(f32 *, f32 *);
// Cube-grid visibility culling (func_800D2F20 to func_800D3104), then the font table and
// glyph lookup.
typedef struct {
    s16 pad_0[4];
} CellD31;
typedef struct {
    CellD31 *cells;
    s32 origin[3]; // cube coordinates of the first cell
    s32 pad_10[3];
    s32 stride[2]; // cell index step for y and z
    s32 pad_24;
    s32 size[3]; // cell count per axis
    CellD31 unk_34;
} GridD31;
extern void func_800EB800(void);
extern void func_800E3980(f32 *);
extern void func_800E3958(f32 *);
extern void func_800BD64C(s32 *, f32 *);
extern void func_800EFB58(s32 *, s32 *, s32 *);
extern void func_800EFD3C(s32 *);
extern void func_800EFA88(s32 *, s32, s32, s32);
extern s32 func_800BCC58(void);
extern s32 func_800F0E28(s32, s32);
extern s32 func_800BDC5C(void);
extern s32 func_800E9DCC();
extern f32 mlAbsF(f32);
extern void func_800EB5E0(CellD31 *, void *);
extern s8 D_8012B370[];
typedef struct {
    s16 asset_id;
    u8 width; // default glyph width
    u8 unk_3;
    s32 texture; // loaded on first use
} Entry_8011B560;

// Font table: asset id and default glyph width of the four fonts.
Entry_8011B560 D_8011B560[4] = {
    {0x0C21, 8, 0, 0},
    {0x0C22, 0x10, 0, 0},
    {0x0C20, 0x10, 0, 0},
    {0x0C23, 6, 0, 0},
};
// Charset of the custom encoding; the index is the glyph number.
u8 D_8011B580[] = "0123456789:ABCDEFGHIJKLMNOPQRSTUVWXYZ@%?()<>\".;-!/'";
extern s32 func_800D6C34(s32);

// TU-NOTE: the .rodata of this file starts with these constants (formerly
// asm/data/core2/1EAC810.rodata.s); each is a 16-byte object whose zero words belong to it, as
// the alignment in the ROM shows.
const struct {
    f32 sqrt2;
    f32 pad_4[3];
} D_80125B00 = {1.4142135f};

// Far distance: cube size * 4.
int func_800D2F20()
{
    return func_800BDC5C() << 2;
}

// Visibility of one cube: sphere test around the camera, then the frustum box test.
s32 func_800D2F44(s32 cell, s32 *coord, s32 size, f32 *cam_pos)
{
    f32 box_min[3];
    f32 box_max[3];
    f32 offset[3];
    f32 radius;
    s32 i;
    radius = func_800E42C0();
    offset[0] = coord[0] * size + size / 2 - cam_pos[0];
    offset[1] = coord[1] * size + size / 2 - cam_pos[1];
    offset[2] = coord[2] * size + size / 2 - cam_pos[2];
    radius = radius * 4.0f * (D_80125B00.sqrt2 * size);
    if (radius * radius <
        offset[0] * offset[0] + offset[1] * offset[1] + offset[2] * offset[2])
        return 0;
    for (i = 0; i < 3; i++) {
        box_min[i] = coord[i] * size - 150;
        box_max[i] = box_min[i] + (size + 300);
    }
    return func_800E3D0C(box_min, box_max);
}

// Draws the props of every visible cube of the grid around the camera.
void func_800D3104(void *unk_0, GridD31 *grid)
{
    f32 cam_pos[3];
    f32 cam_dir[3];
    s32 cube_size;
    s32 cam_cube[3];
    s32 min_cube[3];
    s32 max_cube[3];
    s32 axis;
    f32 max_abs;
    f32 abs_val;
    s32 x;
    s32 y;
    s32 z;
    CellD31 *cell;
    s32 cube_coord[3];
    func_800EB800();
    func_800E3980(cam_pos);
    func_800E3958(cam_dir);
    func_800BD64C(cam_cube, cam_pos);
    func_800EFB58(cam_cube, cam_cube, grid->origin);
    func_800EFD3C(min_cube);
    func_800EFA88(max_cube, grid->size[0] - 1, grid->size[1] - 1,
                  grid->size[2] - 1);
    if (!func_800BCC58()) {
        // Along the dominant view axis, trim the range on the side behind the camera.
        axis = 0;
        max_abs = mlAbsF(cam_dir[0]);
        abs_val = mlAbsF(cam_dir[1]);
        if (max_abs < abs_val) {
            max_abs = abs_val;
            axis = 1;
        }
        abs_val = mlAbsF(cam_dir[2]);
        if (max_abs < abs_val)
            axis = 2;
        if (cam_dir[axis] < 0.0f)
            max_cube[axis] = cam_cube[axis];
        else if (axis == 1)
            min_cube[axis] = func_800F0E28(0, cam_cube[axis] - 1);
        else
            min_cube[axis] = cam_cube[axis];
    }
    // Clamp the range to the draw distance.
    for (axis = 0; axis < 3; axis++) {
        if (func_800E42C0() * 4.0f < cam_cube[axis] - min_cube[axis])
            min_cube[axis] = cam_cube[axis] - func_800E42C0() * 4.0f;
        if (func_800E42C0() * 4.0f < max_cube[axis] - cam_cube[axis])
            max_cube[axis] = cam_cube[axis] + func_800E42C0() * 4.0f;
    }
    func_800EB5E0(&grid->unk_34, unk_0);
    cube_size = func_800BDC5C();
    for (x = min_cube[0]; x <= max_cube[0]; x++) {
        for (y = min_cube[1]; y <= max_cube[1]; y++) {
            for (z = min_cube[2]; z <= max_cube[2]; z++) {
                cell = grid->cells + x + y * grid->stride[0] +
                       grid->stride[1] * z;
                cube_coord[0] = grid->origin[0] + x;
                cube_coord[1] = grid->origin[1] + y;
                cube_coord[2] = grid->origin[2] + z;
                if (func_800E9DCC((s16 *) cell) &&
                    func_800D2F44(cell, cube_coord, cube_size, cam_pos))
                    func_800EB5E0(cell, unk_0);
            }
        }
    }
}

// Builds D_8012B370: char to glyph index in the custom charset, -1 if absent.
void func_800D34A0()
{
    s32 charset_len;
    s32 ch;
    int index;

    charset_len = func_800E7188(D_8011B580);
    for (ch = 0; ch != 0x80; ch += 1) {
        index = 0;
        if (charset_len > 0) {
            do {
                if (ch == D_8011B580[index]) {
                    D_8012B370[ch] = index;
                    break;
                }
                index += 1;
            } while (index != charset_len);
        }
        if (index == charset_len) {
            D_8012B370[ch] = -1;
        }
    }
}

s32 func_800D674C(s32 a0);

// Returns the font texture, loading it on first use.
s32 func_800D3524(s32 font)
{
    if (D_8011B560[font].texture == 0) {
        D_8011B560[font].texture = func_800D674C(D_8011B560[font].asset_id);
    }
    return D_8011B560[font].texture;
}

// Default glyph width of the font, scaled by 0.8.
int func_800D3574(s32 font)
{
    s32 offset = font * 8;
    return (int) ((f32) ((u8 *) D_8011B560 + 2)[offset] * 0.8f);
}

// Default glyph width of the font.
u8 func_800D35BC(s32 font)
{
    u8 *width_ptr;
    // Matching: the pointer temporary is needed for the match.
    width_ptr = &((u8 *) D_8011B560 + 2)[font * 8];
    return *width_ptr;
}

// Maps a character to its glyph index (encoding 0 ASCII range, 1 custom charset, 2 raw byte,
// 3 digits); -1 if there is none.
int func_800D35D0(encoding, ch)
s32 encoding;
s32 ch;
{
    s8 glyph;
    if ((((encoding != 2) && (encoding != 0)) && (ch >= 0x61)) && (ch < 0x7B)) {
        ch -= 0x20;
    }
    switch (encoding) {
        case 0:
            if ((ch >= 0x21) && (ch < 0x7B)) {
                return ch - 0x21;
            }
            break;

        case 1:
            if (ch < 0x80) {
                glyph = D_8012B370[ch];
                if (glyph >= 0) {
                    return glyph;
                }
            }
            break;

        case 2:
            if ((ch > 0) && (ch < 0xFD)) {
                return ch;
            }
            break;

        case 3:
            if ((ch >= 0x30) && (ch < 0x3B)) {
                return ch - 0x30;
            }
            {
                return 0xb;
            }
    }

    return -1;
}

// Drops the cached font textures.
void func_800D36A8(void)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8011B560[i].texture = 0;
    }
}

// Glyph width of a character, or the font's default width if it has no glyph.
int func_800D36C4(s32 font)
{
    s32 texture;
    s32 glyph;

    // Matching: the argument-less call is needed for the match.
    glyph = func_800D35D0();
    texture = func_800D3524(font);
    if ((glyph < 0) || (texture == 0)) {
        return func_800D3574(font);
    }
    return *(u8 *) ((char *) func_800B0D6C(texture, glyph) + 2);
}

s32 func_800D3724(s32 font)
{
    s32 *entry;
    s32 result;
    entry = (s32 *) D_8011B560 + (font * 2);
    if (entry[1] != 0) {
        result = func_800D6C34(*(s16 *) entry);
    } else {
        // Matching: the empty if blocks are needed for the match.
        if (1) {
        }
        if (1) {
        }
        if (1) {
        }
        result = 1;
        // Matching: this empty test is needed for the match.
        if (!font) {
        }
    }
    return result;
}
