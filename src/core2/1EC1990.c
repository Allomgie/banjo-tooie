#include "common.h"

// Off-screen color buffer: D_8012D5F4 is the heap block, D_8012D5F0 its 64-byte-aligned address.
extern s32 D_8012D5F0;
extern s32 D_8012D5F4;
extern void func_800A9828();

// Allocate the 160x128 RGBA16 buffer and align it.
void func_800E80A0()
{
    if (!D_8012D5F4) {
        D_8012D5F0 = heap_alloc(0xA040);
        D_8012D5F4 = D_8012D5F0;
        while ((u32) D_8012D5F0 & 0x3F) {
            D_8012D5F0 += 2;
        }
    }
}

int func_800E8104()
{
    if (D_8012D5F4 != 0) {
        heap_free(D_8012D5F4);
        D_8012D5F4 = 0;
    }
    func_800A9800();
}

// Switch the render target to the buffer (160x128).
s32 func_800E8144(void)
{
    if (D_8012D5F4) {
        func_800A9828(D_8012D5F0, 0xA0, 0x80);
    }
}

// Set up color/depth target and clear while the buffer is active.
int func_800E817C(s32 gfx)
{
    if (D_8012D5F4 != 0) {
        func_800A9800();
        func_800E7C28(gfx);
        func_800E7CF4(gfx);
        func_800E7D4C(gfx);
        func_800A8B24(gfx, 0);
    }
}

s32 func_800E81D0(void)
{
    return D_8012D5F0;
}
