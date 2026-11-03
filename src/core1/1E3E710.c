#include "common.h"

typedef struct {
    u8 pad0[0x88];
    s32 unk88;
} TTPlayer;
typedef struct {
    u8 pad0[8];
    TTPlayer *unk8;
    u8 padC[0xE];
    s16 unk1A;
} TTWrap;
typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
} TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern s32 func_80021928(s32);
extern void func_8002B684(TTPlayer *, s32, void *);

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 type;
    u8 padA[2];
    s32 unkC;
    s32 unk10;
} TTQEvtB;

void func_80026BE0(TTWrap *w, s16 arg1, s32 arg2)
{
    TTQEvtB *evt;

    if (w->unk8) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->unk4 = D_800411F4->unk1C + w->unk8->unk88;
        evt->type = 0xB;
        evt->unkC = arg1;
        evt->unk10 = func_80021928(arg2);
        evt->unk0 = 0;
        func_8002B684(w->unk8, 3, evt);
    }
}
