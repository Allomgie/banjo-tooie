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

typedef struct TTV2C_s { struct TTV2C_s *next; /* 0x00 */ u8 unk4; /* 0x04 */ u8 pad5[0x1D]; s16 unk22; /* 0x22 */ s16 unk24; /* 0x24 */ u8 pad26[2]; union { struct { u8 unk28; /* 0x28 */ u8 unk29; /* 0x29 */ } b; f32 f; /* 0x28 */ } u28; } TTV2C;
typedef struct { u8 pad0[4]; u8 type; /* 0x04 */ u8 pad5[0x1D]; u16 maxCount; /* 0x22 */ u16 curCount; /* 0x24 */ u8 pad26[2]; union { struct { u8 depth; /* 0x28 */ u8 base; /* 0x29 */ } b; f32 fdepth; /* 0x28 */ } u; } TTOsc;
extern f32 D_80041994;
extern f32 D_80041998;
extern f32 func_8001395C(f32);
extern f32 func_80027170(s32);
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
extern M2C_UNK *D_8007EA40;
typedef struct TTN2C_s { struct TTN2C_s *unk0; /* 0x00: next; sizeof = 0x2C */ u8 pad4[0x28]; } TTN2C;
typedef struct { u8 pad0[0xC]; void *unkC; /* 0x0C: Heap */ void *unk10; /* 0x10: Callback 1 */ void *unk14; /* 0x14: Callback 2 */ void *unk18; /* 0x18: Callback 3 */ } TTDrv;
extern TTN2C *D_8007EA44;
extern void *func_80020EE4(void *, s32, void *, s32, s32);

/* func_80021C10 (TU core1/1E39740): pow-by-squaring mit u8-Exponent, Basis D_80041990. */
extern f32 D_80041990;

f32 func_80021C10(u8 exp)
{
    f32 x;
    f32 ratio;

    x = D_80041990;
    ratio = 1.0f;

    while (exp) {
        if (exp & 1)
            ratio *= x;
        x *= x;
        exp >>= 1;
    }

    return ratio;
}

s32 func_80021C8C(TTV2C **out, f32 *outPitch, u8 type, u8 key, u8 vel, u8 vol)
{
    TTV2C *v;
    s32 ret = 0;

    if (!vol)
        return 0;

    if (((TTV2C *) D_8007EA40)) {
        v = ((TTV2C *) D_8007EA40);
        D_8007EA40 = ((TTV2C *) D_8007EA40)->next;
        v->unk4 = type;
        *out = v;
        ret = vol << 14;

        switch (type) {
            case 1:
                v->unk24 = 0;
                v->unk22 = 0x103 - key;
                v->u28.b.unk28 = vel >> 1;
                v->u28.b.unk29 = 0x7F - v->u28.b.unk28;
                *outPitch = (f32)(u32)v->u28.b.unk29;
                break;
            case 0x80:
                v->u28.f = func_80021C10(vel);
                v->unk24 = 0;
                v->unk22 = 0x103 - key;
                *outPitch = 1.0f;
                break;
            default:
                break;
        }
    }

    return ret;
}

s32 func_80021E1C(void *oscState, f32 *updateVal)
{
    f32 findex;
    TTOsc *statePtr = (TTOsc *)oscState;
    s32 deltaTime = 0x3E80;

    switch (statePtr->type) {
    case 1:
        statePtr->curCount++;
        if (statePtr->curCount >= statePtr->maxCount)
            statePtr->curCount = 0;
        findex = (f32)statePtr->curCount / (f32)statePtr->maxCount;
        findex = func_8001395C(findex * D_80041994);
        findex = statePtr->u.b.depth * findex;
        *updateVal = statePtr->u.b.base + findex;
        break;

    case 0x80:
        statePtr->curCount++;
        if (statePtr->curCount >= statePtr->maxCount)
            statePtr->curCount = 0;
        findex = (f32)statePtr->curCount / (f32)statePtr->maxCount;
        findex = func_8001395C(findex * D_80041998) * statePtr->u.fdepth;
        *updateVal = func_80027170((s32)findex);
        break;

    default:
        break;
    }

    return deltaTime;
}

void func_80022060(M2C_UNK *param_0) {
    *param_0 = D_8007EA40;
    D_8007EA40 = param_0;
}

void func_80022084(TTDrv *drv, s32 count)
{
    TTN2C *p;
    s32 i;

    D_8007EA44 = func_80020EE4(0, 0, drv->unkC, count, 0x2C);
    D_8007EA40 = D_8007EA44;
    D_8007EA40 = D_8007EA44;

    p = D_8007EA44;
    for (i = 0; i < count - 1; i++) {
        p->unk0 = D_8007EA44 + i + 1;
        p = p->unk0;
    }
    p->unk0 = 0;

    drv->unk10 = func_80021C8C;
    drv->unk14 = func_80021E1C;
    drv->unk18 = func_80022060;
}
