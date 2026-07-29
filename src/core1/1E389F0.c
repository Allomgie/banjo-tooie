#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy
#endif

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
typedef struct { u8 *base; /* 0x0 */ u8 *cur; /* 0x4 */ s32 len; /* 0x8 */ s32 count; /* 0xC */ } TTHeap;

void func_80020EC0(u8 *param_0, s32 param_1, s32 param_2) {
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
    }
    else {
    }

    return ptr;
}
