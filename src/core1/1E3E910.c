// Synth voice setters: alSynSetPan, alSynSetPitch, alSynSetFXMix, alSynStopVoice, alSynFreeVoice.
#include "common.h"

typedef struct {
    u8 pad0[0x88];
    s32 time_offset; // added to the global time when queuing events
} TTPlayer;
typedef struct {
    u8 pad0[8];
    TTPlayer *pvoice;
    u8 padC[0xE];
    s16 unk1A; // only used in 26CB0
} TTWrap;
typedef struct {
    u8 pad0[0x1C];
    s32 global_time; // current audio time
} TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern void func_80021884(TTPlayer *);
extern void func_8002B684(TTPlayer *, s32, void *);

typedef struct {
    s32 unk0;
    s32 time_stamp;
    s16 type;
    u8 padA[2];
    s32 value;
} TTQEvtC;
typedef struct {
    s32 unk0;
    s32 time_stamp;
    s16 type;
    u8 padA[2];
    f32 value;
} TTQEvtF;
typedef struct {
    s32 unk0;
    s32 time_stamp;
    s16 type;
} TTQEvtE;
typedef struct {
    s32 unk0;
    s32 time_stamp;
    s16 type;
    u8 padA[2];
    TTPlayer *voice;
} TTQEvtP;

// alSynSetPan: queue a pan event (type 0xC)
void func_80026DE0(TTWrap *wrap, u8 pan)
{
    TTQEvtC *evt;

    if (wrap->pvoice) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->time_stamp = D_800411F4->global_time + wrap->pvoice->time_offset;
        evt->type = 0xC;
        evt->value = pan;
        evt->unk0 = 0;
        func_8002B684(wrap->pvoice, 3, evt);
    }
}

// alSynSetPitch: queue a pitch event (type 7)
void func_80026E90(TTWrap *wrap, f32 pitch)
{
    TTQEvtF *evt;

    if (wrap->pvoice) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->time_stamp = D_800411F4->global_time + wrap->pvoice->time_offset;
        evt->type = 7;
        evt->value = pitch;
        evt->unk0 = 0;
        func_8002B684(wrap->pvoice, 3, evt);
    }
}

// alSynSetFXMix: queue an FX mix event (type 0x10)
void func_80026F40(TTWrap *wrap, u8 fx_mix)
{
    TTQEvtC *evt;

    if (wrap->pvoice) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->time_stamp = D_800411F4->global_time + wrap->pvoice->time_offset;
        evt->type = 0x10;
        evt->value = fx_mix;
        evt->unk0 = 0;
        func_8002B684(wrap->pvoice, 3, evt);
    }
}

// alSynStopVoice: queue a stop event (type 0xF)
void func_80026FF0(TTWrap *wrap)
{
    TTQEvtE *evt;

    if (wrap->pvoice) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->time_stamp = D_800411F4->global_time + wrap->pvoice->time_offset;
        evt->type = 0xF;
        evt->unk0 = 0;
        func_8002B684(wrap->pvoice, 3, evt);
    }
}

// alSynFreeVoice: queue a free event (type 0), or free the voice at once if it has no time offset
void func_80027090(TTWrap *wrap)
{
    TTQEvtP *evt;

    if (wrap->pvoice) {
        if (wrap->pvoice->time_offset) {
            evt = func_80021794();
            if (!evt)
                return;
            evt->time_stamp = D_800411F4->global_time + wrap->pvoice->time_offset;
            evt->type = 0;
            evt->voice = wrap->pvoice;
            func_8002B684(wrap->pvoice, 3, evt);
        } else {
            func_80021884(wrap->pvoice);
        }
        wrap->pvoice = 0;
    }
}
