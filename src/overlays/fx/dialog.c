#include "common.h"

extern f32 B_808002A0_fxdialog;
extern void func_800E2554(f32, f32);
extern void func_800E257C(s32);
extern f32 B_808002A4_fxdialog;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800DF944(u32, f32 *, f32, f32, f32 *, s32, s32);

// TU-NOTE: .bss is defined here, ahead of its first use: IDO places .bss objects used
// before their definition first, the rest in definition order. Labels inside an object
// (B_808002A0_fxdialog, B_808002A4_fxdialog) are linker symbols in undefined_syms.us.txt.
f32 B_80800290_fxdialog[8];

void fxdialog_entrypoint_0(void)
{
    // Matching: the odd pointer cast chains reproduce the original address arithmetic.
    *(s32 *) ((s8 *) (s32 *) &B_80800290_fxdialog + 0xC) = 0;
    *(s32 *) ((s8 *) (s32 *) &B_80800290_fxdialog + 8) = 0;
    *(f32 *) ((s8 *) (s32 *) &B_80800290_fxdialog + 0x10) = 1.0f;
    *(f32 *) ((s8 *) (s32 *) &B_80800290_fxdialog + 4) = 0.0f;
    *(f32 *) ((s8 *) (s32 *) &B_80800290_fxdialog + 0) =
        (f32) *(f32 *) ((s8 *) (s32 *) &B_80800290_fxdialog + 4);
}

void fxdialog_entrypoint_1(s32 x, s32 y)
{
    // Matching: extra temporary pointer to the base address.
    char *base;
    base = (char *) &B_80800290_fxdialog;
    *(s32 *) ((char *) &B_80800290_fxdialog + 0x8) = x << 2;
    *(s32 *) ((char *) &B_80800290_fxdialog + 0xC) = y << 2;
    *(f32 *) (base + 0x0) = (f32) x;
    *(f32 *) ((char *) &B_80800290_fxdialog + 0x4) = (f32) y;
}

fxdialog_entrypoint_2(f32 scale)
{
    if (scale > 0.0f) {
        *(f32 *) ((char *) (u8 *) &B_80800290_fxdialog + 0x10) = scale;
        *(f32 *) ((char *) (u8 *) &B_80800290_fxdialog + 0x14) = 1.0f / scale;
    }
}

void fxdialog_entrypoint_3(u32 unk_0, f32 unk_1, s32 unk_2, s32 unk_3)
{
    f32 unk_4[2];
    f32 vec[3];
    s32 unk_5;

    unk_5 = func_801040D0(unk_0);
    unk_4[1] = -24.0f;
    unk_4[0] = 0.0f;
    func_800EFA4C(vec, unk_1 * 0.041666667f * B_808002A4_fxdialog - 2.0f, 0.0f, 0.0f);
    func_800DFFA0(unk_5, 0x2A, vec);
    func_800DF41C(unk_5);
    func_800DF410(unk_3);
    func_800DF944(unk_0, (f32 *) (s32 *) &B_80800290_fxdialog, unk_2 * 90.0f,
                  ((f32 *) (s32 *) &B_80800290_fxdialog)[4], unk_4, 0, func_800D674C(0x9F1));
}

void fxdialog_entrypoint_4(s32 unk_0, s32 unk_1, s32 unk_2, f32 dx, f32 dy,
                           s32 unk_3, s32 flip)
{
    s32 pos[2];
    f32 scale_x;
    f32 scale_y;

    scale_x = flip ? -B_808002A0_fxdialog : B_808002A0_fxdialog;
    scale_y = B_808002A0_fxdialog;
    func_800E2554(scale_x, scale_y);
    func_800E257C(unk_3);
    pos[0] = ((s32 *) &B_80800290_fxdialog)[2] + dx * 4.0f * scale_x;
    pos[1] = ((s32 *) &B_80800290_fxdialog)[3] + dy * 4.0f * scale_y;
    func_800E30E0(unk_0, func_800D674C(unk_1), unk_2, pos);
}

// TU-NOTE: the .data of this overlay is defined in C; values are taken from the ROM.
