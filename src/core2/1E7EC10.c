#include "common.h"

extern const u8 D_801255C0[];
extern f32 D_801270A0[];
extern f32 D_801270B0[];
extern f32 D_801270C0[];
extern f32 D_801270D0[];
extern f32 D_801270E0[];
extern void func_800EFA4C(f32 *a0, f32 a1, f32 a2, f32 a3);
extern void func_800EF8BC(f32 *a0, f32 *a1, f32 a2);

// Precomputes four frustum edge directions (D_801270A0..D_801270D0) and the centre direction
// (D_801270E0).
void func_800A5320(void)
{
    f32 down[3];
    f32 edge[3];
    f32 center[3];

    func_800EFA4C(down, 0.0f, -1.0f, 0.0f);
    func_800EF8BC(center, down, 68.0f);
    func_800EFA4C(edge, *(f32 *) D_801255C0 * center[1], 0.0f, center[2]);

    D_801270E0[0] = center[0];
    D_801270E0[1] = center[1];
    D_801270E0[2] = center[2];
    D_801270A0[0] = edge[0] + center[0];
    D_801270A0[1] = edge[1] + center[1];
    D_801270A0[2] = center[2];
    D_801270B0[0] = edge[0] - center[0];
    D_801270B0[1] = edge[1] - center[1];
    D_801270B0[2] = center[2];
    D_801270C0[0] = -edge[0] - center[0];
    D_801270C0[1] = -edge[1] - center[1];
    D_801270C0[2] = center[2];
    D_801270D0[0] = -edge[0] + center[0];
    D_801270D0[1] = -edge[1] + center[1];
    D_801270D0[2] = center[2];
}

void func_800A5430(s32 angles[2], volatile s32 unk_0, f32 distance, unsigned int unk_1)
{
    extern void func_800EF4E4(void *, s32, s32, f32, f32, f32);
    extern void func_800EE780(s32, void *, s32);
    s8 offset[12];
    // Matching: reusing ptr as the second argument is needed for the match.
    s32 *ptr = angles;
    func_800EF4E4(offset, ptr[0], ptr[1], 0.0f, 0.0f, -distance);
    func_800EE780(unk_1, ptr = (s32 *) offset, unk_0);
}

int func_800A5490()
{
    s32 unk_0;
    unk_0 = func_8008FFE8();
    // Matching: `| 0` is needed for the match.
    func_8010FFD8(unk_0 | 0);
}

// TU-NOTE: this .data object (formerly asm/data/core2/1E7EC10.data.s) is defined here in C;
// values are taken from the ROM.
const u8 D_801255C0[16] = {0x3F, 0xAA, 0xAA, 0xAB, 0x0, 0x0, 0x0, 0x0,
                           0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
