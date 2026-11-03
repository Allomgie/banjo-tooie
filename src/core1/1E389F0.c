#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

typedef struct {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
} TTHeap;

void func_80020EC0(u8 *param_0, s32 param_1, s32 param_2)
{
    M2C_FIELD(param_0, s32 *, 0) = param_1;
    M2C_FIELD(param_0, s32 *, 8) = param_2;
    M2C_FIELD(param_0, s32 *, 4) = (s32) M2C_FIELD(param_0, s32 *, 0);
    M2C_FIELD(param_0, s32 *, 0xC) = 0;
}

void *func_80020EE4(u8 *file, s32 line, TTHeap *hp, s32 num, s32 size)
{
    s32 bytes;
    u8 *ptr = 0;

    bytes = (num * size + 0xF) & ~0xF;

    if ((hp->cur + bytes) <= (hp->base + hp->len)) {
        ptr = hp->cur;
        hp->cur += bytes;
    } else {
    }

    return ptr;
}
