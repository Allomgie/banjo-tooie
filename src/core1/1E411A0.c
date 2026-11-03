#include "common.h"
#define M127(v) ((v) >= 0x80 ? 0x7F : (v))

// Struct shapes follow libultra N_ALSeqPlayer; offsets are from the object file.
typedef struct TTVceU_s {
    struct TTVceU_s *next;
    u8 handle; // address is the handle seen by callers
    u8 pad5[0x1B];
    void *unk20;
} TTVceU;
typedef struct {
    u8 pad0[0x64];
    TTVceU *voice_head;
    TTVceU *voice_tail;
    TTVceU *free_list;
    u8 pad70[0x19];
    u8 voice_count;
} TTSeqV;
extern void func_800E90A4(void *, s32);
typedef struct {
    s16 type;
    u8 pad2[2];
    void *handle;
    u8 pad8[8];
} TTEvtP;
typedef struct TTItemS2_s {
    struct TTItemS2_s *next;
    u8 pad4[4];
    s32 delta;
    s16 type;
    u8 padE[2];
    void *data;
} TTItemS2;
typedef struct {
    u8 pad0[0x28];
    s32 unk28;
    u8 pad2C[8];
    u8 unk34;
    u8 pad35[2];
    u8 unk37;
    u8 unk38;
} TTVceS;
typedef struct {
    u8 pad0[0x10];
    TTVceS *voice;
} TTHdlS;
typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    u8 pad20[0x28];
    u8 evtq48;
    u8 pad49[7];
    TTItemS2 *evt_head;
} TTSeqS;
extern void func_80020E74(void *);
extern void func_80020E40(void *, void *);
extern void func_8002C5A0(TTHdlS *, s32);
extern void func_80026BE0(TTHdlS *, s32, s32);
extern void func_80026500(void *, TTEvtP *, s32, s32);
typedef struct TTItemE2_s {
    struct TTItemE2_s *next;
    u8 pad4[4];
    s32 delta;
    s16 type;
    u8 padE[2];
    void *data;
} TTItemE2;
typedef struct {
    u8 pad0[0x48];
    u8 evtq48;
    u8 pad49[7];
    TTItemE2 *evt_head;
} TTSeqE;
typedef struct TTVceA_s {
    struct TTVceA_s *next;
    u8 pad4[0x10];
    struct TTVceA_s *unk14;
    u8 pad18[0x10];
    s32 unk28;
    u8 pad2C[9];
    u8 channel;
    u8 key;
    u8 velocity;
} TTVceA;
typedef struct {
    u8 pad0[0x64];
    TTVceA *voice_head;
    TTVceA *voice_tail;
    TTVceA *free_list;
    u8 pad70[0x18];
    u8 max_voices;
    u8 voice_count;
} TTSeqA;
extern void func_800E9070(void *, s32);
typedef struct TTVceS2_s {
    struct TTVceS2_s *next;
    u8 pad4[0x31];
    u8 channel;
    u8 key;
    u8 pad37[2];
    u8 unk39;
} TTVceS2;
typedef struct {
    u8 pad0[0x64];
    TTVceS2 *voice_head;
} TTSeqS2;
typedef struct {
    u8 vel_min;
    u8 vel_max;
    u8 key_min;
    u8 key_max;
} TTKmB;
typedef struct {
    u8 pad0[0x33];
    u8 instrument;
    s8 keymap_cache;
    u8 pad35[3];
} TTChanB;
typedef struct {
    u8 pad0[0x60];
    TTChanB *chan_state;
} TTSeqB;
extern s32 func_800E9054(s32);
typedef struct {
    u8 pad0[0xD5];
    u8 sample_volume;
} Sound;
typedef struct {
    u8 pad0[0x20];
    Sound *sound;
    u8 pad24[0x10];
    u8 env_gain;
    u8 channel;
    u8 pad36;
    u8 velocity;
    u8 pad38[2];
    u8 tremolo;
} VoiceState;
typedef struct {
    u8 pad0[5];
    u8 vol;
    u8 pad6[3];
    u8 unk9;
    u8 padA[0x38 - 0xA];
} ChannelState_80029D54;
typedef struct {
    u8 pad0[0x34];
    s16 vol;
    u8 pad36[0x60 - 0x36];
    ChannelState_80029D54 *chan_state;
} SeqPlayer_80029D54;
typedef struct {
    u8 pad0[6];
    u8 fx_mix;
    u8 pad7[0x31];
} TTChanP;
typedef struct {
    u8 pad0[0x60];
    TTChanP *chan_state;
    u8 pad64[0x18];
    f32 unk7C;
    f32 unk80;
} TTSeqP;
typedef struct {
    u8 pad0[0x35];
    u8 channel;
} TTVceP;
typedef struct {
    u8 pad0[0x28];
    s32 unk28;
} TTVceR5;
typedef struct {
    u8 pad0[0xD4];
    u8 sample_pan;
} TTPlyrR;
typedef struct {
    u8 pad0[0x20];
    TTPlyrR *sound;
    u8 pad24[0x11];
    u8 channel;
} TTVceR6;
typedef struct {
    u8 pad0[3];
    u8 pan;
    u8 pad4[0x34];
} TTChanR;
typedef struct {
    u8 pad0[0x60];
    TTChanR *chan_state;
} TTSeqR6;
typedef struct {
    u8 pad0[0x36];
    u8 chan_count;
} TTSeqR8;
typedef struct {
    u8 pad0[0x33];
    u8 instrument;
    u8 pad34[4];
} TTChanR2;
typedef struct {
    u8 pad0[0x36];
    u8 chan_count;
    u8 pad37[0x29];
    TTChanR2 *chan_state;
} TTSeqR7;
typedef struct {
    s16 unk0;
    u8 unk2;
    u8 pan;
    u8 priority;
    u8 volume;
    u8 fx_mix;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    f32 pitch_bend;
    u8 pad18[0x32 - 0x18];
    u8 unk32;
    u8 pad33[0x38 - 0x33];
} ChannelState_8002A150;
typedef struct {
    u8 pad0[0x60];
    ChannelState_8002A150 *chan_state;
} SeqPlayer_8002A150;
typedef struct {
    u8 volume;
    u8 pan;
    u8 priority;
    u8 pad3[1];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s16 unkC;
} TTInstrI;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
} TTWaveI;
typedef struct {
    s16 unk0;
    u8 pad2[1];
    u8 pan;
    u8 priority;
    u8 volume;
    u8 pad6[0x12];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 pad30[1];
    u8 unk31;
    u8 pad32[1];
    u8 instrument;
    u8 pad34[4];
} TTChanI;
typedef struct {
    u8 pad0[0x60];
    TTChanI *chan_state;
} TTSeqI;
extern TTInstrI *func_800E93AC(s32);
extern TTWaveI *func_800E9300(s32, s32);
typedef struct TTItemE3_s {
    struct TTItemE3_s *next;
    u8 pad4[4];
    s32 delta;
    s16 type;
    u8 padE[2];
    void *data;
    void *unk14;
} TTItemE3;
typedef struct {
    u8 pad0[0x3B];
    u8 osc_flags;
} TTHdl2;
typedef struct {
    u8 pad0[0x48];
    u8 evtq48;
    u8 pad49[7];
    TTItemE3 *evt_head;
    u8 pad54[0x24];
    void (*stop_osc)(void *);
} TTSeqE2;
typedef struct {
    s32 unk0;
    s32 time;
    s16 type;
    u8 padA[2];
    union {
        s32 i;
        f32 f;
    } uC;
} TTQEvtV;
typedef struct {
    u8 pad0[0x88];
    s32 time_offset;
} TTVceV;
typedef struct {
    u8 pad0[0x8];
    TTVceV *voice;
} TTHdlV;
typedef struct {
    u8 pad0[0x1C];
    s32 time;
} TTAMgrV;
extern TTAMgrV *D_800411F4;
extern TTQEvtV *func_80021794(void);
extern s32 func_8002B684(TTVceV *, s32, TTQEvtV *);
typedef struct {
    u8 pad0[4];
    void *(*pull_fn)();
} TTSynthR;
typedef struct {
    u8 pad0[0x20];
    void *unk20;
    u8 pad24[0x20];
    void *unk44;
} TTSlotR;
typedef struct {
    u8 pad0[0x30];
    TTSynthR *synth;
    TTSlotR *slots;
} TTAMgrR;
extern void *func_800272B0();
extern void func_80027AF0();
typedef struct {
    s16 unk0;
    s16 unk2;
} TTFxA;
typedef struct {
    u8 pad0[0x40];
    s32 unk40;
} TTAMgrA;
extern void func_80028C04(void *, f32);

// Forward declarations of the functions in this file.
void func_8002A150(SeqPlayer_8002A150 *seq, s32 chan);
void func_8002A318(TTSeqI *seq, s32 bank, s32 chan);

// Unlinks the voice with the given handle and puts it on the free list.
void func_80029670(TTSeqV *seq, void *handle)
{
    TTVceU *prev;
    TTVceU *voice;

    prev = 0;
    for (voice = seq->voice_head; voice != 0; voice = voice->next) {
        if ((void *) &voice->handle == handle) {
            if (prev != 0)
                prev->next = voice->next;
            else
                seq->voice_head = voice->next;

            if (seq->voice_tail == voice)
                seq->voice_tail = prev;

            func_800E90A4(voice->unk20, 1);

            voice->next = seq->free_list;
            seq->free_list = voice;
            seq->voice_count--;
            return;
        }
        prev = voice;
    }
}

void func_8002976C(TTSeqS *seq, TTHdlS *handle, s32 ticks)
{
    TTEvtP evt;
    TTVceS *voice;
    TTItemS2 *item;
    TTItemS2 *next;
    TTItemS2 *cur;
    TTItemS2 *cur_next;

    voice = handle->voice;

    if (voice->unk38 == 0) {
        // Drop queued type-6 events of this handle.
        item = seq->evt_head;
        while (item != 0) {
            next = item->next;
            // Matching: cur and cur_next are extra copies needed for the match.
            cur = item;
            cur_next = next;

            if (cur->type == 6) {
                if (cur->data == handle) {
                    if (cur_next != 0) {
                        cur_next->delta += cur->delta;
                    }
                    func_80020E74(item);
                    func_80020E40(item, &seq->evtq48);
                }
            }

            item = next;
        }
    }

    voice->unk37 = 0;
    voice->unk38 = 3;
    voice->unk34 = 0;
    voice->unk28 = seq->unk1C + ticks;

    func_8002C5A0(handle, 0);
    func_80026BE0(handle, 0, ticks);

    evt.type = 5;
    evt.handle = handle;
    ticks += 0x7D00;
    func_80026500(&seq->evtq48, &evt, ticks, 0);
}

// Removes the type-5 event of match if it fires after more than limit ticks; returns 0 if it fires sooner.
u8 func_800298E4(TTSeqE *seq, void *match, s32 limit)
{
    TTItemE2 *item;
    TTItemE2 *next;
    TTItemE2 *cur;
    s32 sum;
    u8 found;

    sum = 0;
    found = 1;

    item = seq->evt_head;
    while (item != 0) {
        next = item->next;
        // Matching: cur is an extra copy of item needed for the match.
        cur = item;

        sum += cur->delta;

        if (cur->type == 5) {
            if (cur->data == match) {
                if (sum > limit) {
                    if (next != 0)
                        next->delta += cur->delta;
                    func_80020E74(item);
                    func_80020E40(item, &seq->evtq48);
                } else {
                    found = 0;
                }
                break;
            }
        }

        item = next;
    }

    return found;
}

// Takes a voice from the free list and appends it to the active list.
TTVceA *func_80029A04(TTSeqA *seq, u8 key, u8 velocity, u8 chan, void *e)
{
    TTVceA *voice;

    voice = seq->free_list;

    if (seq->voice_count > seq->max_voices)
        return 0;

    if (voice != 0) {
        seq->free_list = voice->next;
        voice->next = 0;

        if (seq->voice_head == 0)
            seq->voice_head = voice;
        else
            seq->voice_tail->next = voice;

        seq->voice_tail = voice;
        voice->channel = chan;
        voice->key = key;
        voice->velocity = velocity;
        voice->unk14 = voice;
        voice->unk28 = 0;
        seq->voice_count++;

        func_800E9070(e, 1);
    }

    return voice;
}

TTVceS2 *func_80029B18(TTSeqS2 *seq, u8 key, u8 chan)
{
    TTVceS2 *voice;

    for (voice = seq->voice_head; voice != 0; voice = voice->next) {
        if (voice->key == key && voice->channel == chan && voice->unk39 != 3 && voice->unk39 != 4) {
            return voice;
        }
    }

    return 0;
}

// Binary search of the instrument's keymaps for the sample matching key and velocity.
void *func_80029BA0(TTSeqB *seq, u8 key, u8 vel, u8 chan)
{
    s32 instr;
    s32 hi;
    s32 lo;
    s32 mid;
    TTKmB *keymap;
    void *wave;

    instr = seq->chan_state[chan].instrument;
    hi = 1;
    lo = func_800E9054(instr);

    while (lo >= hi) {
        mid = (hi + lo) / 2;

        wave = func_800E9300(instr, mid - 1);
        keymap = (TTKmB *) ((u8 *) wave + 0x10);

        if (key >= keymap->key_min && key <= keymap->key_max && vel >= keymap->vel_min && vel <= keymap->vel_max) {
            seq->chan_state[chan].keymap_cache = mid - 1;
            return wave;
        } else if (key < keymap->key_min || (vel < keymap->vel_min && key <= keymap->key_max))
            lo = mid - 1;
        else
            hi = mid + 1;
    }

    return 0;
}

s16 func_80029D54(VoiceState *voice, SeqPlayer_80029D54 *seq)
{
    u32 voice_gain;
    u32 chan_gain;

    voice_gain = (voice->tremolo * voice->velocity * voice->env_gain) >> 6;
    chan_gain = (seq->chan_state[voice->channel].vol *
               (voice->sound->sample_volume * seq->vol)) >>
              14;
    if (seq->chan_state[voice->channel].unk9 != 0xFF) {
        chan_gain = ((seq->chan_state[voice->channel].unk9 * chan_gain) + 1) >> 8;
    }
    voice_gain *= chan_gain;
    voice_gain >>= 15;
    return voice_gain;
}

// Voice fx mix: channel fx mix adjusted and clamped to 0..0x7F; bit 7 is kept.
u8 func_80029E64(TTVceP *voice, TTSeqP *seq)
{
    s32 hi;
    s32 x;

    hi = seq->chan_state[voice->channel].fx_mix & 0x80;
    x = (s32) ((f32) ((seq->chan_state[voice->channel].fx_mix & 0x7F) + (s32) (seq->unk7C * 127.0f)) * seq->unk80);

    return ((M127(x) < 0) ? 0 : M127(x)) | hi;
}

s32 func_80029F5C(TTVceR5 *voice, s32 time)
{
    s32 delta;

    delta = voice->unk28 - time;
    if (delta >= 0)
        return delta;
    else
        return 0x3E8;
}

// Voice pan: channel pan plus sample pan, centered on 0x40 and clamped to 0..0x7F.
u8 func_80029FA0(TTVceR6 *voice, TTSeqR6 *seq)
{
    s32 pan;

    pan = seq->chan_state[voice->channel].pan + voice->sound->sample_pan - 0x40;

    // Matching: the empty blocks are needed for the match.
    if (pan > 0) {
    } else {
        pan = 0;
    }
    if (pan < 0x7F) {
    } else {
        pan = 0x7F;
    }

    return pan;
}

void func_8002A024(TTSeqR8 *seq, s32 unused)
{
    s32 i;
    s32 instr;

    for (instr = 0; func_800E9054(instr) == 0; instr++)
        ;

    for (i = 0; i < seq->chan_count; i++) {
        func_8002A150(seq, i);
        func_8002A318(seq, instr, i);
    }
}

void func_8002A0CC(TTSeqR7 *seq)
{
    s32 i;

    for (i = 0; i < seq->chan_count; i++) {
        seq->chan_state[i].instrument = 0;
        func_8002A150(seq, i);
    }
}

// Resets a channel to the default state.
void func_8002A150(SeqPlayer_8002A150 *seq, s32 chan)
{
    seq->chan_state[chan].unk2 = 0;
    seq->chan_state[chan].fx_mix = 0;
    seq->chan_state[chan].pan = 0x40;
    seq->chan_state[chan].volume = 0x7F;
    seq->chan_state[chan].priority = 5;
    seq->chan_state[chan].unk8 = 0;
    seq->chan_state[chan].unk0 = 0xC8;
    seq->chan_state[chan].pitch_bend = 1.0f;
    seq->chan_state[chan].unk10 = 0;
    seq->chan_state[chan].unk9 = 0xFF;
    seq->chan_state[chan].unkA = 0xFF;
    seq->chan_state[chan].unkB = 0;
    seq->chan_state[chan].unk7 = 0;
    seq->chan_state[chan].unk13 = 0;
    seq->chan_state[chan].unk12 = 0;
    seq->chan_state[chan].unk11 = 0;
    seq->chan_state[chan].unk32 = 0;
}

// Initialises a channel from the instrument and its first sample.
void func_8002A318(TTSeqI *seq, s32 bank, s32 chan)
{
    TTInstrI *instr;
    TTWaveI *wave;

    instr = func_800E93AC(bank);

    seq->chan_state[chan].instrument = bank;
    seq->chan_state[chan].pan = instr->pan;
    seq->chan_state[chan].volume = instr->volume;
    seq->chan_state[chan].priority = instr->priority;
    seq->chan_state[chan].unk0 = instr->unkC;

    if (func_800E9054(bank) == 0)
        return;

    wave = func_800E9300(bank, 0);

    seq->chan_state[chan].unk18 = wave->unk0;
    seq->chan_state[chan].unk1C = wave->unk4;
    seq->chan_state[chan].unk20 = wave->unk8;
    seq->chan_state[chan].unk25 = wave->unkC;
    seq->chan_state[chan].unk26 = wave->unkD;
    seq->chan_state[chan].unk27 = 0;
    seq->chan_state[chan].unk28 = instr->unk4;
    seq->chan_state[chan].unk29 = instr->unk5;
    seq->chan_state[chan].unk2A = instr->unk6;
    seq->chan_state[chan].unk2B = instr->unk7;
    seq->chan_state[chan].unk2C = instr->unk8;
    seq->chan_state[chan].unk2D = instr->unk9;
    seq->chan_state[chan].unk2E = instr->unkA;
    seq->chan_state[chan].unk2F = instr->unkB;
    seq->chan_state[chan].unk24 = 0;
    seq->chan_state[chan].unk31 = 0;
}

// Removes queued oscillator events (types 0x16/0x17) of the handle.
void func_8002A6A4(TTSeqE2 *seq, TTHdl2 *handle)
{
    TTItemE3 *item;
    TTItemE3 *next;
    s16 type;

    item = seq->evt_head;
    while (item != 0) {
        next = item->next;
        type = item->type;

        if (type == 0x16 || type == 0x17) {
            if (item->data == handle) {
                seq->stop_osc(item->unk14);
                func_80020E74(item);

                if (next != 0) {
                    next->delta += item->delta;
                }

                func_80020E40(item, &seq->evtq48);

                if (type == 0x16)
                    handle->osc_flags = handle->osc_flags & 0xFE;
                else
                    handle->osc_flags = handle->osc_flags & 0xFD;

                if (handle->osc_flags == 0)
                    return;
            }
        }

        item = next;
    }
}

// Posts param event 0x13 (float value) to the handle's voice.
void func_8002A7E0(TTHdlV *handle, f32 val)
{
    TTQEvtV *evt;

    if (handle->voice != 0) {
        evt = func_80021794();
        if (evt == 0)
            return;

        evt->time = D_800411F4->time + handle->voice->time_offset;
        evt->type = 0x13;
        evt->uC.f = val;
        evt->unk0 = 0;
        func_8002B684(handle->voice, 3, evt);
    }
}

// Posts param event 0x12 (integer value) to the handle's voice.
void func_8002A890(TTHdlV *handle, u8 val)
{
    TTQEvtV *evt;

    if (handle->voice != 0) {
        evt = func_80021794();
        if (evt == 0)
            return;

        evt->time = D_800411F4->time + handle->voice->time_offset;
        evt->type = 0x12;
        evt->uC.i = val;
        evt->unk0 = 0;
        func_8002B684(handle->voice, 3, evt);
    }
}

// Matching: old-style parameter declaration needed for the match.
void *func_8002A940(idx)
s16 idx;
{
    TTSynthR *synth;

    synth = ((TTAMgrR *) D_800411F4)->synth;
    if (synth->pull_fn == func_800272B0)
        return ((TTAMgrR *) D_800411F4)->slots[idx].unk20;
    else
        return 0;
}

// Matching: old-style parameter declaration needed for the match.
void *func_8002A9B8(idx)
s16 idx;
{
    TTSynthR *synth;

    synth = ((TTAMgrR *) D_800411F4)->synth;
    if (synth->pull_fn == func_800272B0)
        return ((TTAMgrR *) D_800411F4)->slots[idx].unk44;
    else
        return 0;
}

void func_8002AA30(void *p, s16 x, void *y)
{
    // Matching: the extra copy of p is needed for the match.
    void *v = p;

    func_80027AF0(v, x, y);
}

void func_8002AA74(TTFxA *p, s16 type, s32 *val)
{
    if (type == 8) {
        p->unk2 = (s32) ((f32) *val * 0.1f);
    } else if (type == 9) {
        p->unk0 = *val;
    }

    func_80028C04(p, (f32) ((TTAMgrA *) D_800411F4)->unk40);
}
