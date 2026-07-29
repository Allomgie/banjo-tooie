#include "common.h"

typedef struct { u8 pad0[0x88]; s32 unk88; /* 0x88: Zeit-Offset */ } TTPlayer;
typedef struct { u8 pad0[8]; TTPlayer *unk8; /* 0x8 */ u8 padC[0xE]; s16 unk1A; /* 0x1A (nur 26CB0) */ } TTWrap;
typedef struct { u8 pad0[0x1C]; s32 unk1C; /* 0x1C: globale Zeit */ } TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern void func_80021884(TTPlayer *);
extern s32 func_80021928(s32);
extern void func_8002B684(TTPlayer *, s32, void *);
typedef struct { s32 unk0; s32 unk4; s16 type; u8 padA[2]; s32 unkC; } TTQEvtG;
typedef struct { u32 division; u32 nTracks; u32 trackOffset[32]; } TTCMidiHdr;
typedef struct { TTCMidiHdr *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 deltaFlag; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq;

void func_8002AB30(TTWrap *w, u8 arg1)
{
    TTQEvtG *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->type = 0x11;
        evt->unkC = arg1;
        evt->unk0 = 0;
        func_8002B684(w->unk8, 3, evt);
    }
}

s32 func_8002ABE0(TTCSeq *seq, s32 *pDeltaTicks)
{
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 lastTicks = seq->lastDeltaTicks;

    if (!seq->validTracks)
        return 0;

    for (i = 0; i < seq->base->nTracks; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag)
                seq->evtDeltaTicks[i] -= lastTicks;
            if (seq->evtDeltaTicks[i] < firstTime)
                firstTime = seq->evtDeltaTicks[i];
        }
    }

    seq->deltaFlag = 0;
    *pDeltaTicks = firstTime;

    return 1;
}
