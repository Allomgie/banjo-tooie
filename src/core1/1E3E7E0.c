// alSynStartVoiceParams: queues a voice start with wavetable, pitch, volume, pan and FX mix.
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
    s16 unk_A;
    f32 pitch;
    s16 vol;
    u8 pan;
    u8 fx_mix;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[2];
    f32 unk_18;
    s32 ramp_time;
    void *wavetable;
} TTQEvtS;

// Queues a start-voice update.
void func_80026CB0(TTWrap *w, void *wave, f32 pitch_arg, s16 vol_arg, u8 pan_arg, u8 fx_mix_arg, u8 unk_0, f32 unk_1,
                   u8 unk_2, s32 ramp)
{
    TTQEvtS *evt;

    if (w->pvoice) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->delta = D_800411F4->param_samples + w->pvoice->time_offset;
        evt->next = 0;
        evt->type = 0xD;
        evt->unk_A = w->unk_1A;
        evt->pan = pan_arg;
        evt->vol = vol_arg;
        evt->fx_mix = fx_mix_arg;
        evt->pitch = pitch_arg;
        evt->unk_14 = unk_2;
        evt->unk_15 = unk_0;
        evt->unk_18 = unk_1;
        evt->ramp_time = func_80021928(ramp);
        evt->wavetable = wave;
        func_8002B684(w->pvoice, 3, evt);
    }
}
