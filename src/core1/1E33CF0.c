#include "types.h"
#include "buffers.h"

void func_8001D1E0(void);
u32 func_8001D31C(void);
u32 func_8001D32C(void);
s32 func_8001C324(u8 *, u8 *, void *);
u8 *func_8001D30C();

extern s32 D_8007C700;

void func_8001C1C0()
{
    func_8001D1E0();
}

// Inflates one member from *src to *dst; advances both cursors (dst rounded up to 16).
s32 func_8001C1E0(u8 **src, u8 **dst)
{
    D_8007C700 = func_8001C324(*src, *dst, &D_8000E800);
    *dst += D_8007C700;
    *dst = ((uintptr_t) *dst & 0xF) ? (u8 *) (((uintptr_t) *dst & ~0xF) + 0x10) : *dst;
    *src = func_8001D30C();
    return 1;
}

// Running CRC1 of the decompressor.
u32 func_8001C26C()
{
    func_8001D31C();
}

// Running CRC2 of the decompressor.
u32 func_8001C28C()
{
    return func_8001D32C();
}

// Inflates from src to dst without advancing any cursor.
s32 func_8001C2AC(u8 *src, u8 *dst)
{
    D_8007C700 = func_8001C324(src, dst, D_8000E800);
    return 0;
}

// Size of the last decompressed output.
s32 func_8001C2D8()
{
    return D_8007C700;
}
