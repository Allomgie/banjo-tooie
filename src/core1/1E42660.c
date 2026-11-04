// Two synth helpers: posts a per-voice delay param event, finds the next compact-MIDI delta.
#include "common.h"

typedef struct {
    u8 pad0[0x88];
    s32 time_offset; // 0x88
} TTPlayer;
typedef struct {
    u8 pad0[8];
    TTPlayer *player;
    u8 padC[0xE];
    s16 unk_1A; // only used by 26CB0
} TTWrap;
typedef struct {
    u8 pad0[0x1C];
    s32 global_time; // 0x1C
} TTAMgrT;
extern TTAMgrT *D_800411F4;
extern void *func_80021794(void);
extern void func_8002B684(TTPlayer *, s32, void *);

typedef struct {
    s32 unk_0;
    s32 time;
    s16 type;
    u8 padA[2];
    s32 value;
} TTQEvtG;
typedef struct {
    u32 division;
    u32 nTracks;
    u32 trackOffset[32];
} TTCMidiHdr;
typedef struct {
    TTCMidiHdr *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    s32 deltaFlag;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} TTCSeq;

// Synth API: posts param event 0x11 to a voice.
// Posts a synth param event (type 0x11, per-voice delay byte) to the voice's player.
void func_8002AB30(TTWrap *voice, u8 delay)
{
    TTQEvtG *evt;

    if (voice->player) {
        evt = func_80021794();
        if (!evt)
            return;
        evt->time = D_800411F4->global_time + voice->player->time_offset;
        evt->type = 0x11;
        evt->value = delay;
        evt->unk_0 = 0;
        func_8002B684(voice->player, 3, evt);
    }
}

// Compact MIDI sequence: next delta across tracks.
// __n_alCSeqNextDelta: smallest pending delta tick over the valid tracks.
s32 func_8002ABE0(TTCSeq *seq, s32 *out_delta)
{
    u32 i;
    u32 min_delta = 0xFFFFFFFF;
    u32 last_delta = seq->lastDeltaTicks;

    if (!seq->validTracks)
        return 0;

    for (i = 0; i < seq->base->nTracks; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag)
                seq->evtDeltaTicks[i] -= last_delta;
            if (seq->evtDeltaTicks[i] < min_delta)
                min_delta = seq->evtDeltaTicks[i];
        }
    }

    seq->deltaFlag = 0;
    *out_delta = min_delta;

    return 1;
}
