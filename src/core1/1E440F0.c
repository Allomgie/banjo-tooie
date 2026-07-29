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
typedef struct { u32 w0; u32 w1; } TTAcmd;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04 */ } TTLoopH;
typedef struct { u8 pad0[0x14]; u32 unk14; /* 0x14: Loop-Startposition */ u32 unk18; /* 0x18: Endposition */ s32 unk1C; /* 0x1C: Loop-Count */ TTLoopH *unk20; /* 0x20 */ u32 unk24; /* 0x24 */ u8 pad28[8]; u32 unk30; /* 0x30: aktuelle Position */ u32 unk34; /* 0x34: Phase (0..15) */ s32 unk38; /* 0x38: Flags */ s32 unk3C; /* 0x3C: ROM-Cursor */ } TTVceH;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04: Laenge (auf 9er quantisiert) */ s32 unk8; /* 0x08: Queue {head,tail} */ s32 unkC; /* 0x0C */ s32 unk10; /* 0x10 */ u8 unk14[0x20]; /* 0x14: State-Block */ s32 unk34; /* 0x34 */ u8 pad38[0x80]; s32 unkB8; /* 0xB8 */ } TTWave;
typedef struct { u8 pad0[0x10]; void *unk10; /* 0x10: State-Ziel */ s32 unk14; /* 0x14 */ s32 unk18; /* 0x18 */ s32 unk1C; /* 0x1C */ TTWave *unk20; /* 0x20 */ s32 unk24; /* 0x24 */ u8 pad28[8]; s32 unk30; /* 0x30 */ s32 unk34; /* 0x34 */ s32 unk38; /* 0x38 */ s32 unk3C; /* 0x3C */ } TTVoiceF;
typedef struct { u8 pad0[0xC]; s32 unkC; /* 0x0C */ s32 unk10; /* 0x10 */ u8 pad14[0x14]; s32 (*unk28)(s32, s32, s32); /* 0x28: DMA-Callback */ s32 unk2C; /* 0x2C */ u8 pad30[8]; s32 unk38; /* 0x38 */ s32 unk3C; /* 0x3C */ } TTVoiceG;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
TTAcmd *func_8002CE70(TTAcmd *p, TTVoiceG *v, s32 arg2, s32 len, s16 arg4, s16 arg5, s32 flags);

s32 func_8002C5C0(u8 *param_0) {
    if (M2C_FIELD(param_0, s32 *, 4) == M2C_FIELD(param_0, s32 *, 0)) {
        return 0;
    } else {
        return 1;
    }
}

TTAcmd *func_8002C5F8(TTVceH *state, s16 *arg1, s32 count, TTAcmd *cmdIn)
{
    TTAcmd *cmd = cmdIn;
    s16 var7A;
    s32 t74;
    s32 n70;
    s32 sz6C;
    s32 rem68;
    s32 len64;
    s32 skip60;
    s32 len5C;
    s32 addr58;
    s32 pad54;
    s32 pos50;
    s32 flag4C = 0;
    s32 flag48 = 0;
    TTVceH *v = state;
    TTAcmd *p0;
    TTAcmd *p1;
    TTAcmd *p2;

    if (count == 0)
        return cmd;

    var7A = 0;

    p0 = cmd++;
    p0->w0 = (v->unk24 & 0xFFFFFF) | 0x0B000000;
    p0->w1 = ((u32)v->unk20 + 0x38) & 0x1FFFFFFF;

    flag48 = (v->unk30 + count > v->unk18) && (v->unk1C != 0);

    if (flag48)
        len5C = v->unk18 - v->unk30;
    else
        len5C = count;

    if (v->unk34)
        pad54 = 0x10 - v->unk34;
    else
        pad54 = 0;

    t74 = len5C - pad54;
    if (t74 < 0)
        t74 = 0;

    n70 = (t74 + 0xF) >> 4;
    sz6C = n70 * 9;

    if (flag48) {
        cmd = func_8002CE70(cmd, v, t74, sz6C, *arg1, var7A, v->unk38);

        if (v->unk34)
            *arg1 = *arg1 + v->unk34 * 2;
        else
            *arg1 = *arg1 + 0x20;

        v->unk34 = v->unk14 & 0xF;
        v->unk3C = v->unk20->unk0 + (v->unk14 >> 4) * 9 + 9;
        v->unk30 = v->unk14;
        pos50 = *arg1;

        while (count > len5C) {
            count -= len5C;
            addr58 = (((n70 + 1) << 5) + pos50 + 0x10) & ~0x1F;
            pos50 += len5C * 2;

            if (v->unk1C != -1 && v->unk1C != 0)
                v->unk1C--;

            len5C = (count < v->unk18 - v->unk14) ? count : v->unk18 - v->unk14;

            t74 = len5C + v->unk34 - 0x10;
            if (t74 < 0)
                t74 = 0;

            n70 = (t74 + 0xF) >> 4;
            sz6C = n70 * 9;

            cmd = func_8002CE70(cmd, v, t74, sz6C, addr58, var7A, v->unk38 | 2);

            p1 = cmd++;
            p1->w0 = ((v->unk34 * 2 + addr58) & 0xFFFFFF) | 0x0A000000;
            p1->w1 = ((pos50 & 0xFFFF) << 16) | ((len5C * 2) & 0xFFFF);
        }

        v->unk34 = (v->unk34 + count) & 0xF;
        v->unk30 = v->unk30 + count;
        v->unk3C = v->unk3C + n70 * 9;
        return cmd;
    }

    {
        len5C = n70 << 4;

        rem68 = (v->unk3C + sz6C) - (v->unk20->unk0 + v->unk20->unk4);
        if (rem68 < 0)
            rem68 = 0;

        skip60 = rem68 / 9 << 4;

        if (skip60 > len5C + pad54)
            skip60 = len5C + pad54;

        sz6C = sz6C - rem68;

        if (skip60 - (skip60 & 0xF) < count) {
            flag4C = 1;

            cmd = func_8002CE70(cmd, v, len5C - skip60, sz6C, *arg1, var7A, v->unk38);

            if (v->unk34)
                *arg1 = *arg1 + v->unk34 * 2;
            else
                *arg1 = *arg1 + 0x20;

            v->unk34 = (v->unk34 + count) & 0xF;
            v->unk30 = v->unk30 + count;
            v->unk3C = v->unk3C + n70 * 9;
        } else {
            v->unk34 = 0;
            v->unk3C = v->unk3C + n70 * 9;
        }

        if (skip60 != 0) {
            v->unk34 = 0;

            if (flag4C)
                len64 = (pad54 + len5C - skip60) * 2;
            else
                len64 = 0;

            p2 = cmd++;
            p2->w0 = ((*arg1 + len64) & 0xFFFFFF) | 0x02000000;
            p2->w1 = skip60 * 2;
        }
    }

    return cmd;
}

s32 func_8002CC9C(TTVoiceF *arg0, s32 type, TTWave *val)
{
    TTVoiceF *v = arg0;

    switch (type) {
        case 5:
            v->unk20 = val;
            v->unk3C = v->unk20->unk0;
            v->unk30 = 0;
            v->unk20->unk4 = (v->unk20->unk4 / 9) * 9;
            v->unk24 = v->unk20->unk34 * 2 * v->unk20->unkB8 * 8;
            if (func_8002C5C0(&v->unk20->unk8)) {
                v->unk14 = v->unk20->unk8;
                v->unk18 = v->unk20->unkC;
                v->unk1C = v->unk20->unk10;
                bcopy(v->unk20->unk14, v->unk10, 0x20);
            }
            else {
                v->unk14 = v->unk18 = v->unk1C = 0;
            }
            break;
        case 4:
            v->unk34 = 0;
            v->unk38 = 1;
            v->unk30 = 0;
            if (v->unk20) {
                v->unk3C = v->unk20->unk0;
                if (func_8002C5C0(&v->unk20->unk8)) {
                    v->unk1C = v->unk20->unk10;
                }
            }
            break;
        default:
            break;
    }

    return 0;
}

TTAcmd *func_8002CE70(TTAcmd *p, TTVoiceG *v, s32 arg2, s32 len,
                       s16 arg4, s16 arg5, s32 flags)
{
    s32 rem;
    s32 x;
    TTAcmd *c1;
    TTAcmd *c2;
    TTAcmd *c3;

    if (len > 0) {
        x = v->unk28(v->unk3C, len, v->unk2C);
        rem = x & 7;
        len = len + rem;
        c1 = p++;
        c1->w0 = ((((len - (len & 7)) + 8) & 0xFFF) << 12 | 0x04000000) | (arg5 & 0xFFF);
        c1->w1 = x - rem;
        if (1) {
        }
    }
    else {
        rem = 0;
    }

    if (flags & 2) {
        c2 = p++;
        c2->w0 = 0x0F000000;
        c2->w1 = v->unk10 & 0x1FFFFFFF;
    }

    c3 = p++;
    c3->w0 = ((v->unkC & 0x1FFFFFFF) & 0xFFFFFF) | 0x01000000;
    c3->w1 = ((flags & 0xF) << 28) | (((arg2 * 2) & 0xFFF) << 16) | ((rem & 0xF) << 12) | (arg4 & 0xFFF);

    v->unk38 = 0;

    return p;
}
