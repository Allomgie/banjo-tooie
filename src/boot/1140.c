// Boot copy of the rarezip front-end: inflates one member from src to dst (advancing both),
// reads the CRC words and the last output size; identical to core1/1E33CF0.c.
#include "types.h"
#include "buffers.h"

void func_80001590(void);
u32 func_800016CC(void);
u32 func_800016DC(void);
s32 func_800006D4(u8 *, u8 *, void *);
u8 *func_800016BC();

extern s32 D_800064F0;

// TU-NOTE: copy of core1's 1E33CF0.c.
void func_80000540()
{
    func_80001590();
}

// Inflates one member from *src to *dst; advances both cursors (dst rounded up to 16).
s32 func_80000560(u8 **src, u8 **dst)
{
    D_800064F0 = func_800006D4(*src, *dst, &D_8000E800);
    *dst += D_800064F0;
    *dst = ((uintptr_t) *dst & 0xF) ? (u8 *) (((uintptr_t) *dst & ~0xF) + 0x10) : *dst;
    *src = func_800016BC();
    return 1;
}

u32 func_800005EC()
{
    return func_800016CC();
}

u32 func_8000060C()
{
    return func_800016DC();
}

// Inflates from src to dst without advancing any cursor.
s32 func_8000062C(u8 *src, u8 *dst)
{
    D_800064F0 = func_800006D4(src, dst, D_8000E800);
    return 0;
}

// Size of the last decompressed output.
s32 func_80000658()
{
    return D_800064F0;
}
