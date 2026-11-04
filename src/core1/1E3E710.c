// alSynSetVol: queues a volume change with ramp time for a synth voice.
#include "common.h"

typedef struct {
    u8 pad_0[0x88];
    s32 time_offset;
} TTPlayer;
typedef struct {
    u8 pad_0[8];
    TTPlayer *pvoice;
    u8 pad_C[0xE];
    s16 unk_1A;
} TTWrap;
typedef struct {
    u8 pad_0[0x1C];
    s32 param_samples;
} TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern s32 func_80021928(s32);
extern void func_8002B684(TTPlayer *, s32, void *);

typedef struct {
    s32 next;
    s32 delta;
    s16 type;
    u8 pad_A[2];
    s32 vol;
    s32 ramp_time;
} TTQEvtB;

// Queues a volume change with a ramp time.
void func_80026BE0(TTWrap *w, s16 volume, s32 ramp)
{
    TTQEvtB *evt;

    if (w->pvoice) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->delta = D_800411F4->param_samples + w->pvoice->time_offset;
        evt->type = 0xB;
        evt->vol = volume;
        evt->ramp_time = func_80021928(ramp);
        evt->next = 0;
        func_8002B684(w->pvoice, 3, evt);
    }
}
