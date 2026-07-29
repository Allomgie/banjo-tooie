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

typedef struct TTItemF_s { struct TTItemF_s *unk0; /* 0x00 */ u8 pad4[0x20]; } TTItemF;
typedef struct { u8 pad0[0x8]; s32 unk8; /* 0x08 */ u8 padC[0xB4]; } TTPlyrF;
typedef struct { u8 pad0[2]; s16 unk2; /* 0x02 */ u8 pad4[0x28]; void *unk2C; /* 0x2C */ void *unk30; /* 0x30 */ } TTVceF;
typedef struct { u8 pad0[0x14]; s32 unk14; /* 0x14 */ s32 unk18; /* 0x18 */ TTPlyrF **unk1C; /* 0x1C */ void *unk20; /* 0x20 */ u8 pad24[0x20]; TTVceF *unk44; /* 0x44 */ } TTSlotF;
typedef struct { u8 pad0[4]; void *(*unk4)(); /* 0x04 */ } TTSynthF;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04: Listenkopf next */ s32 unk8; /* 0x08: Listenkopf prev */ s32 unkC; /* 0x0C */ s32 unk10; /* 0x10 */ s32 unk14; /* 0x14 */ s32 unk18; /* 0x18 */ s32 unk1C; /* 0x1C */ s32 unk20; /* 0x20 */ void *unk24; /* 0x24 */ void *unk28; /* 0x28 */ TTItemF *unk2C; /* 0x2C */ TTSynthF *unk30; /* 0x30 */ TTSlotF *unk34; /* 0x34 */ s32 unk38; /* 0x38 */ s32 unk3C; /* 0x3C */ s32 unk40; /* 0x40 */ s32 unk44; /* 0x44 */ s32 unk48; /* 0x48 */ s32 unk4C; /* 0x4C */ } TTAMgrF;
typedef struct { u8 pad0[4]; s32 unk4; /* 0x04: Player-Anzahl */ s32 unk8; /* 0x08: Event-Anzahl */ s32 unkC; /* 0x0C */ void *unk10; /* 0x10 */ void *unk14; /* 0x14: Heap */ s32 unk18; /* 0x18 */ u8 unk1C[4]; /* 0x1C: FX-Flags pro Slot */ } TTCfgF;
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern void *func_80027220(s32, TTCfgF *, void *);
extern void *func_800272B0();
extern void func_800293B4(void *, void *, void *);
typedef struct { u32 w0; u32 w1; } TTAcmd4;
typedef struct TTSNode_s { struct TTSNode_s *next; /* 0x00 */ u8 pad4[4]; s32 (*unk8)(struct TTSNode_s *); /* 0x08: Handler */ u8 padC[4]; s32 unk10; /* 0x10: naechste Zeit */ } TTSNode;
typedef struct { TTSNode *unk0; /* 0x00 */ u8 pad4[0x18]; s32 unk1C; /* 0x1C: naechste Eventzeit */ s32 unk20; /* 0x20: aktuelle Zeit */ u8 pad24[0x20]; s32 unk44; /* 0x44: max Samples/Stueck */ s32 unk48; /* 0x48: DMEM-Position */ } TTAMgrS;
extern TTAcmd4 *func_800295D0(s32, TTAcmd4 *);
typedef struct TTLink_s { struct TTLink_s *next; struct TTLink_s *prev; } TTLink;
typedef struct TTFNode_s { struct TTFNode_s *next; /* 0x0 */ } TTFNode;
typedef struct { u8 pad0[0x4]; TTLink unk4; /* 0x04 */ u8 padC[0x8]; TTLink *unk14; /* 0x14 */ u8 pad18[0x14]; TTFNode *unk2C; /* 0x2C: Freelist-Kopf */ u8 pad30[0x10]; s32 unk40; /* 0x40 */ } TTAMgrN;
extern TTAMgrN *D_800411F4;
extern void func_80020E40(TTLink *, TTLink *);
extern void func_80020E74(TTLink *);
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
extern f32 D_80041980;
typedef struct TTPN_s { struct TTPN_s *next; /* 0x00 */ u8 pad4[0xC]; s32 unk10; /* 0x10: Zeitstempel */ } TTPN;
typedef struct { TTPN *unk0; /* 0x00 */ u8 pad4[0x1C]; s32 unk20; /* 0x20: globale Zeit */ } TTAMgrM;
extern u8 D_8007EA30;
extern u8 D_8007EA31;
extern u8 D_8007EA32;
extern u8 D_8007EA33[];
extern u8 D_8007EA34[];
extern u8 D_8007EA35[];

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
void func_80021820();
s32 func_800218C4();
s32 func_80021960(TTPN **out);
void func_80021AD0();

void func_80020F70(TTCfgF *cfg)
{
    s32 i;
    s32 j;
    TTPlyrF *p;
    TTPlyrF *players;
    void *heap = cfg->unk14;
    TTItemF *items;
    TTItemF *item;

    ((TTAMgrF *) D_800411F4)->unk0 = 0;
    ((TTAMgrF *) D_800411F4)->unk38 = cfg->unk4;
    ((TTAMgrF *) D_800411F4)->unk20 = 0;
    ((TTAMgrF *) D_800411F4)->unk1C = 0;
    ((TTAMgrF *) D_800411F4)->unk40 = cfg->unk18;
    ((TTAMgrF *) D_800411F4)->unk44 = 0xB8;
    ((TTAMgrF *) D_800411F4)->unk24 = cfg->unk10;
    ((TTAMgrF *) D_800411F4)->unk48 = 0;
    ((TTAMgrF *) D_800411F4)->unk4C = 1;

    if (cfg->unkC >= 2)
        ((TTAMgrF *) D_800411F4)->unk3C = 1;
    else if (cfg->unkC <= 0)
        ((TTAMgrF *) D_800411F4)->unk3C = 1;
    else
        ((TTAMgrF *) D_800411F4)->unk3C = cfg->unkC;

    ((TTAMgrF *) D_800411F4)->unk34 = func_80020EE4(0, 0, heap, ((TTAMgrF *) D_800411F4)->unk3C, 0x48);

    for (i = 0; i < ((TTAMgrF *) D_800411F4)->unk3C; i++) {
        ((TTAMgrF *) D_800411F4)->unk34[i].unk14 = 0;
        ((TTAMgrF *) D_800411F4)->unk34[i].unk18 = cfg->unk4;
        ((TTAMgrF *) D_800411F4)->unk34[i].unk1C = func_80020EE4(0, 0, heap, cfg->unk4, 4);

        if (cfg->unk1C[i])
            ((TTAMgrF *) D_800411F4)->unk34[i].unk20 = func_80027220(i, cfg, heap);
        else
            ((TTAMgrF *) D_800411F4)->unk34[i].unk20 = 0;

        ((TTAMgrF *) D_800411F4)->unk34[i].unk44 = func_80020EE4(0, 0, heap, 1, 0x38);
        ((TTAMgrF *) D_800411F4)->unk34[i].unk44->unk2 = 0;
        ((TTAMgrF *) D_800411F4)->unk34[i].unk44->unk2C = func_80020EE4(0, 0, heap, 1, 8);
        ((TTAMgrF *) D_800411F4)->unk34[i].unk44->unk30 = func_80020EE4(0, 0, heap, 1, 8);
    }

    ((TTAMgrF *) D_800411F4)->unk30 = func_80020EE4(0, 0, heap, 1, 0x14);
    ((TTAMgrF *) D_800411F4)->unk30->unk4 = func_800272B0;
    ((TTAMgrF *) D_800411F4)->unk4 = 0;
    ((TTAMgrF *) D_800411F4)->unk8 = 0;
    ((TTAMgrF *) D_800411F4)->unk14 = 0;
    ((TTAMgrF *) D_800411F4)->unk18 = 0;
    ((TTAMgrF *) D_800411F4)->unkC = 0;
    ((TTAMgrF *) D_800411F4)->unk10 = 0;

    players = func_80020EE4(0, 0, heap, cfg->unk4, 0xC0);

    for (i = 0; i < cfg->unk4; i++) {
        p = (TTPlyrF *)(i * 0xC0 + (u8 *)players);
        func_80020E40(p, &((TTAMgrF *) D_800411F4)->unk4);
        p->unk8 = 0;
        func_800293B4(p, ((TTAMgrF *) D_800411F4)->unk24, heap);

        for (j = 0; j < ((TTAMgrF *) D_800411F4)->unk3C; j++) {
            (((TTAMgrF *) D_800411F4)->unk34[j].unk1C[((TTAMgrF *) D_800411F4)->unk34[j].unk14] = p, ((TTAMgrF *) D_800411F4)->unk34[j].unk14++);
        }
    }

    items = func_80020EE4(0, 0, heap, cfg->unk8, 0x24);
    ((TTAMgrF *) D_800411F4)->unk2C = 0;

    for (i = 0; i < cfg->unk8; i++) {
        item = (TTItemF *)(i * 0x24 + (u8 *)items);
        item->unk0 = ((TTAMgrF *) D_800411F4)->unk2C;
        ((TTAMgrF *) D_800411F4)->unk2C = item;
    }

    ((TTAMgrF *) D_800411F4)->unk28 = heap;
}

TTAcmd4 *func_80021574(TTAcmd4 *cmd, s32 *outLen, s32 arg2, s32 budget)
{
    TTSNode *node;
    TTAcmd4 *p;
    TTAcmd4 *prev;
    s32 samples;
    s32 pos;

    p = cmd;
    pos = arg2;

    if (!((TTAMgrS *) D_800411F4)->unk0) {
        *outLen = 0;
        return cmd;
    }

    for (((TTAMgrS *) D_800411F4)->unk1C = func_80021960(&node);
         ((TTAMgrS *) D_800411F4)->unk1C - ((TTAMgrS *) D_800411F4)->unk20 < budget;
         ((TTAMgrS *) D_800411F4)->unk1C = func_80021960(&node)) {
        ((TTAMgrS *) D_800411F4)->unk1C &= ~0xF;
        node->unk10 += func_800218C4(node->unk8(node));
    }
    ((TTAMgrS *) D_800411F4)->unk1C &= ~0xF;

    if (budget > 0) {
        do {
            samples = (((TTAMgrS *) D_800411F4)->unk44 < budget) ? ((TTAMgrS *) D_800411F4)->unk44 : budget;

            prev = p;
            ((TTAMgrS *) D_800411F4)->unk48 = pos;
            p = func_800295D0(((TTAMgrS *) D_800411F4)->unk20, prev);

            budget -= samples;
            pos += samples * 2 * 2;
            ((TTAMgrS *) D_800411F4)->unk20 += samples;
        } while (budget > 0);
    }

    *outLen = ((u8 *)p - (u8 *)cmd) >> 3;
    func_80021820();

    return p;
}

TTFNode *func_80021794(void)
{
    TTFNode *n = 0;

    if (D_800411F4->unk2C) {
        n = D_800411F4->unk2C;
        D_800411F4->unk2C = D_800411F4->unk2C->next;
        n->next = 0;
    }
    return n;
}

void func_800217F4(M2C_UNK *param_0) {
    *param_0 = M2C_FIELD(((u8 *) D_800411F4), M2C_UNK **, 0x2C);
    M2C_FIELD(((u8 *) D_800411F4), M2C_UNK **, 0x2C) = param_0;
}

void func_80021820(void)
{
    TTLink *p;

    while (p = D_800411F4->unk14) {
        func_80020E74(p);
        func_80020E40(p, &D_800411F4->unk4);
    }
}

void func_80021884(TTLink *p)
{
    func_80020E74(p);
    func_80020E40(p, (TTLink *)&D_800411F4->unk14);
}

s32 func_800218C4(t) s32 t;
{
    f32 x;

    x = (f32)t * D_800411F4->unk40 / D_80041980 + 0.5f;
    return (s32)x;
}

s32 func_80021928(s32 t)
{
    return func_800218C4(t) & ~0xF;
}

s32 func_80021960(TTPN **out)
{
    s32 min = 0x7FFFFFFF;
    TTPN *p;

    *out = 0;
    for (p = ((TTAMgrM *) D_800411F4)->unk0; p != 0; p = p->next) {
        if (p->unk10 - ((TTAMgrM *) D_800411F4)->unk20 < min) {
            *out = p;
            min = p->unk10 - ((TTAMgrM *) D_800411F4)->unk20;
        }
    }

    return (*out)->unk10;
}

void func_80021A00(mode) u8 mode;
{
    s32 i;

    D_8007EA30 = 0;
    D_8007EA31 = 0;
    D_8007EA32 = 0;

    switch (mode) {
        case 1:
            D_8007EA31 = 1;
            break;
        case 3:
            D_8007EA32 = 1;
            break;
        case 4:
            D_8007EA30 = 1;
            break;
    }

    for (i = 0; i <= 0; i++) {
        func_80021AD0(i, 0);
    }
}

void func_80021AD0(idx, mode) s32 idx; s32 mode;
{
    if (!mode)
        mode = D_8007EA35[idx];

    D_8007EA33[idx] = 0;
    D_8007EA34[idx] = 0;

    switch (mode) {
        case 2:
            if (D_8007EA30)
                D_8007EA34[idx] = 1;
            break;
        case 3:
            if (D_8007EA30)
                D_8007EA33[idx] = 1;
            break;
        case 4:
            if (!D_8007EA31)
                D_8007EA33[idx] = 1;
            break;
        case 5:
            if (!D_8007EA31) {
                D_8007EA33[idx] = 1;
                D_8007EA34[idx] = 1;
            }
            break;
    }

    D_8007EA35[idx] = mode;
}
