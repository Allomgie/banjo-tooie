#include "common.h"

typedef struct { u8 pad0[0x88]; s32 unk88; /* 0x88: Zeit-Offset */ } TTPlayer;
typedef struct { u8 pad0[8]; TTPlayer *unk8; /* 0x8 */ u8 padC[0xE]; s16 unk1A; /* 0x1A (nur 26CB0) */ } TTWrap;
typedef struct { u8 pad0[0x1C]; s32 unk1C; /* 0x1C: globale Zeit */ } TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern void func_80021884(TTPlayer *);
extern s32 func_80021928(s32);
extern void func_8002B684(TTPlayer *, s32, void *);
typedef struct { s32 unk0; s32 unk4; s16 type; s16 unkA; f32 unkC; s16 unk10; u8 unk12; u8 unk13; u8 unk14; u8 unk15; u8 pad16[2]; f32 unk18; s32 unk1C; void *unk20; } TTQEvtS;

void func_80026CB0(TTWrap *w, void *arg1, f32 arg2, s16 arg3, u8 arg4,
                   u8 arg5, u8 arg6, f32 arg7, u8 arg8, s32 arg9)
{
    TTQEvtS *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->unk0 = 0;
        evt->type = 0xD;
        evt->unkA = w->unk1A;
        evt->unk12 = arg4;
        evt->unk10 = arg3;
        evt->unk13 = arg5;
        evt->unkC = arg2;
        evt->unk14 = arg8;
        evt->unk15 = arg6;
        evt->unk18 = arg7;
        evt->unk1C = func_80021928(arg9);
        evt->unk20 = arg1;
        func_8002B684(w->unk8, 3, evt);
    }
}
