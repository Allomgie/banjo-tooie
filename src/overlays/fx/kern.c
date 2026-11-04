#include "common.h"

typedef struct {
    u8 prev;
    u8 cur;
    s8 dx;
    s8 dy;
} FxKernPair59;
extern FxKernPair59 D_80800420_fxkern[];
typedef struct {
    f32 x;
    f32 y;
} KernPos;
extern s32 func_800D36C4(s32, s32);
extern void func_800B8C98(s32);
extern void func_800B7F14(s32);
extern void func_800B8DEC(s32, s32, s32, s32);
extern void func_800B811C(s32);
typedef struct {
    f32 x;
    f32 y;
} FxKernMetrics;
extern void func_800B8CF0(f32);

// Looks up the kerning offset (dx, dy) for the pair (prev, cur); '*' matches any prev.
void func_80800000_fxkern(u8 cur, u8 prev, s32 *out_dx, s32 *out_dy)
{
    s32 i;

    *out_dx = *out_dy = 0;
    for (i = 0; D_80800420_fxkern[i].prev; i++) {
        if (D_80800420_fxkern[i].cur == cur &&
            (D_80800420_fxkern[i].prev == prev ||
             D_80800420_fxkern[i].prev == '*')) {
            *out_dx = D_80800420_fxkern[i].dx;
            *out_dy = D_80800420_fxkern[i].dy;
            return;
        }
    }
}

// TU-NOTE: .bss is defined here in C, ahead of its first use: IDO places .bss objects
// used before their definition first, the rest in definition order.
float B_80800480_fxkern;
KernPos B_80800488_fxkern[65];

// Fills B_80800488_fxkern with per-character offsets for str; returns the last index.
s32 func_80800084_fxkern(u8 *str)
{
    s32 i;
    s32 dx;
    s32 dy;

    B_80800488_fxkern[0].x = 0.0f;
    B_80800488_fxkern[0].y = 0.0f;
    // Matching: the casts on the scale global are needed for the match.
    for (i = 1; str[i] != 0 && i != 0x40; i++) {
        B_80800488_fxkern[i].x = B_80800488_fxkern[i - 1].x;
        B_80800488_fxkern[i].x +=
            ((f32 *) &B_80800480_fxkern)[0] * (func_800D36C4(1, str[i - 1]) / 2);
        B_80800488_fxkern[i].x +=
            ((f32 *) &B_80800480_fxkern)[0] * (func_800D36C4(1, str[i]) / 2);
        B_80800488_fxkern[i].x += ((f32 *) &B_80800480_fxkern)[0] * -4.0f;
        func_80800000_fxkern(str[i], str[i - 1], &dx, &dy);
        B_80800488_fxkern[i].x += ((f32 *) &B_80800480_fxkern)[0] * dx;
        B_80800488_fxkern[i].y = dy;
        B_80800488_fxkern[i].y *= ((f32 *) &B_80800480_fxkern)[0];
    }
    return i - 1;
}

// Prints characters last..0 of str at (x, y) plus their kerning offsets.
int func_80800224_fxkern(s32 unk_0, s32 x, s32 y, u8 *str, s32 last)
{
    func_800B8C98(1);
    func_800B7F14(unk_0);
    // Matching: the f32 pair cast is needed for the match.
    for (; last >= 0; last--) {
        func_800B8DEC(unk_0, ((f32(*)[2]) B_80800488_fxkern)[last][0] + x,
                      ((f32(*)[2]) B_80800488_fxkern)[last][1] + y, str[last]);
    }
    func_800B811C(unk_0);
}

s32 fxkern_entrypoint_0(s32 unk_0, s32 x, s32 y, s32 str)
{
    s32 last = func_80800084_fxkern(str);

    return func_80800224_fxkern(unk_0, x, y, str, last);
}

// Prints str horizontally centred on the 304-pixel screen.
void fxkern_entrypoint_1(s32 unk_0, s32 y, s32 str)
{
    s32 last;
    FxKernMetrics *positions;

    last = func_80800084_fxkern(str);
    // Matching: the double cast is needed for the match.
    positions = (FxKernMetrics *) (f32 *) B_80800488_fxkern;
    func_80800224_fxkern(unk_0, (s32) ((304.0f - positions[last].x) / 2), y, str,
                         last);
}

int fxkern_entrypoint_2()
{
    func_800B8C50();
    B_80800480_fxkern = 1.0f;
}

void fxkern_entrypoint_3(f32 scale)
{
    func_800B8CF0(scale);
    B_80800480_fxkern = scale;
}

// TU-NOTE: .data is defined here in C; values are taken from the ROM.
FxKernPair59 D_80800420_fxkern[24] = {
    0x41, 0x56, -0x3, 0x0,  0x57, 0x41, -0x3, 0x0, 0x56, 0x41, -0x3, 0x0, 0x59, 0x41, -0x2, 0x0,
    0x4D, 0x4F, -0x1, 0x0,  0x44, 0x41, -0x1, 0x0, 0x52, 0x4F, -0x2, 0x0, 0x54, 0x41, -0x2, 0x0,
    0x53, 0x54, -0x1, 0x0,  0x41, 0x4D, -0x1, 0x0, 0x43, 0x4F, -0x1, 0x0, 0x4F, 0x56, -0x1, 0x0,
    0x4C, 0x4F, -0x1, 0x0,  0x4D, 0x55, -0x1, 0x0, 0x55, 0x4D, -0x1, 0x0, 0x4D, 0x41, -0x2, 0x0,
    0x4D, 0x30, -0x1, 0x0,  0x48, 0x49, 0x1,  0x0, 0x49, 0x50, 0x1,  0x0, 0x45, 0x45, 0x0,  0x1,
    0x5A, 0x45, 0x0,  -0x1, 0x2A, 0x53, 0x1,  0x0, 0x2A, 0x27, 0x3,  0x0, 0x0,  0x0,  0x0,  0x0};
