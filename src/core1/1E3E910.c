#include "common.h"

typedef struct { u8 pad0[0x88]; s32 unk88; /* 0x88: Zeit-Offset */ } TTPlayer;
typedef struct { u8 pad0[8]; TTPlayer *unk8; /* 0x8 */ u8 padC[0xE]; s16 unk1A; /* 0x1A (nur 26CB0) */ } TTWrap;
typedef struct { u8 pad0[0x1C]; s32 unk1C; /* 0x1C: globale Zeit */ } TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern void func_80021884(TTPlayer *);
extern s32 func_80021928(s32);
extern void func_8002B684(TTPlayer *, s32, void *);
typedef struct { s32 unk0; s32 unk4; s16 type; u8 padA[2]; s32 unkC; } TTQEvtC;
typedef struct { s32 unk0; s32 unk4; s16 type; u8 padA[2]; f32 unkC; } TTQEvtF;
typedef struct { s32 unk0; s32 unk4; s16 type; } TTQEvtE;
typedef struct { s32 unk0; s32 unk4; s16 type; u8 padA[2]; TTPlayer *unkC; } TTQEvtP;

void func_80026DE0(TTWrap *w, u8 arg1)
{
    TTQEvtC *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->type = 0xC;
        evt->unkC = arg1;
        evt->unk0 = 0;
        func_8002B684(w->unk8, 3, evt);
    }
}

void func_80026E90(TTWrap *w, f32 arg1)
{
    TTQEvtF *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->type = 7;
        evt->unkC = arg1;
        evt->unk0 = 0;
        func_8002B684(w->unk8, 3, evt);
    }
}

void func_80026F40(TTWrap *w, u8 arg1)
{
    TTQEvtC *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->type = 0x10;
        evt->unkC = arg1;
        evt->unk0 = 0;
        func_8002B684(w->unk8, 3, evt);
    }
}

void func_80026FF0(TTWrap *w)
{
    TTQEvtE *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->type = 0xF;
        evt->unk0 = 0;
        func_8002B684(w->unk8, 3, evt);
    }
}

void func_80027090(TTWrap *w)
{
    TTQEvtP *evt;

    if (w->unk8) {
        if (w->unk8->unk88) {
            evt = func_80021794();
            if (!evt)
                return;
            evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
            evt->type = 0;
            evt->unkC = w->unk8;
            func_8002B684(w->unk8, 3, evt);
        }
        else {
            func_80021884(w->unk8);
        }
        w->unk8 = 0;
    }
}
