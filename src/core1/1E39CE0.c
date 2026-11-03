#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

typedef struct {
    void *unk0;
    void *unk4; // self
    void *unk8; // handler (func_8002241C)
    u8 padC[8];
    void *unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[4];
    s16 unk34;
    u8 unk36;
    u8 unk37;
    s16 unk38;
    u8 pad3A[0xE];
    u8 unk48; // event queue base
    u8 pad49[0x13];
    s32 unk5C;
    void *unk60;
    s32 unk64;
    s32 unk68;
    void *unk6C; // free-list head of voice pool
    s32 unk70;
    s32 unk74;
    s32 unk78;
    f32 unk7C;
    f32 unk80;
    s32 unk84;
    u8 unk88;
    u8 unk89;
} TTChan;
typedef struct {
    s32 unk0; // voice count
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 padA[2];
    void *unkC; // arena
    s32 unk10;
    s32 unk14;
    s32 unk18;
} TTChanCfg;
typedef struct {
    void *unk0;
    u8 pad4[0x40];
} TTPoolElem;
extern void func_80026100(TTChan *);
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern void func_8002A0CC(TTChan *);
extern void func_800263C0(void *, void *, s32);
extern void func_80026860(TTChan *);
extern void *D_800411F4;
typedef struct {
    u8 pad0[0x14];
    u8 keyBase;
} Sound;
typedef struct {
    u8 pad0[0x10];
    void *clientPrivate;
    u8 pad14[8];
} HardwareVoice;
typedef struct VoiceState {
    struct VoiceState *next;
    HardwareVoice voice;
    Sound *sound;
    s16 unk24;
    s16 unk26;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
    void *oscState;
    void *oscState2;
} VoiceState;
typedef struct {
    u8 pad0[9];
    u8 unk9;
    u8 unkA;
    u8 padB[6];
    u8 enabled11;
    u8 tuning12;
    u8 pad13;
    f32 pitchBend;
    u8 pad18[0x38 - 0x18];
} ChannelState;
typedef struct {
    s16 type;
    u8 pad2[2];
    union {
        struct {
            HardwareVoice *voice;
        } note;
        struct {
            HardwareVoice *voice;
            s32 delta;
            u8 vol;
        } vol;
        struct {
            VoiceState *vs;
            void *oscState;
            u8 chan;
        } osc;
        struct {
            s16 vol;
        } spvol;
        struct {
            f32 unk0;
            f32 unk4;
        } evt18;
        struct {
            u8 unk0;
            u8 unk1;
            u8 unk2;
            u8 pad3;
            s32 param;
        } evt19;
        struct {
            void *seq;
        } spseq;
        struct {
            void *bank;
        } spbank;
    } msg;
} Event_8002241C;
typedef struct {
    u8 opaque[0x14];
} EventQueue_8002241C;
typedef struct {
    u8 pad0[0x18];
    void *target;
    s32 curTime;
    void *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    s32 chanMask;
    s16 vol;
    u8 pad36[2];
    Event_8002241C nextEvent;
    EventQueue_8002241C evtq;
    s32 frameTime;
    ChannelState *chanState;
    VoiceState *vAllocHead;
    u8 pad68[0x74 - 0x68];
    s32 (*updateOsc)(void *, f32 *);
    u8 pad78[4];
    f32 unk7C;
    f32 unk80;
} SeqPlayer_8002241C;
void func_80026FF0(HardwareVoice *);
void func_80027090(HardwareVoice *);
void func_8002A6A4(SeqPlayer_8002241C *, VoiceState *);
void func_80029670(SeqPlayer_8002241C *, HardwareVoice *);
s16 func_80029D54(VoiceState *, SeqPlayer_8002241C *);
void func_80026BE0();
void func_80026E90(HardwareVoice *, f32);
void func_8002A7E0(HardwareVoice *, f32);
void func_80026F40();
u8 func_80029E64(VoiceState *, SeqPlayer_8002241C *);
s32 func_8002A940();
void func_8002AA30(s32, s32, s32 *);
s32 func_8002A9B8();
void func_8002AA74();
void func_800266B0();
s32 func_800298E4(SeqPlayer_8002241C *, HardwareVoice *, s32);
void func_8002976C(SeqPlayer_8002241C *, HardwareVoice *, s32);
void func_8002A024(SeqPlayer_8002241C *, void *);
s32 func_8002645C(EventQueue_8002241C *, Event_8002241C *);
typedef struct {
    s16 type;
    u8 pad2[0xE];
} TTEvtD;
typedef struct {
    u8 pad0[0x18];
    void *unk18;
    u8 pad1C[0x10];
    s32 unk2C;
    u8 pad30[0x18];
    u8 evtq48;
} TTSeqD;
extern void func_80025084(void *, TTEvtD *, s32);
extern void func_80026500(void *, TTEvtD *, s32, s32);
typedef struct TTVceQ_s {
    struct TTVceQ_s *unk0;
    u8 unk4; // voice handle base
    u8 pad5[0x30];
    u8 unk35; // channel
    u8 pad36[2];
    u8 unk38; // status
} TTVceQ;
typedef struct {
    u8 pad0[0x1C];
    void *unk1C;
    u8 pad20[0x44];
    TTVceQ *unk64;
} TTSeqQ;
extern s32 func_80029F5C(TTVceQ *, void *);
typedef struct {
    u8 pad0[0x11];
    u8 unk11;
    s8 unk12;
    u8 pad13[1];
    f32 unk14;
    u8 pad18[0x20];
} TTChanK;
typedef struct {
    u8 pad0[0x14];
    u8 unk14;
} TTWaveK;
typedef struct TTVceK_s {
    struct TTVceK_s *unk0;
    u8 unk4; // voice handle base
    u8 pad5[0x1B];
    TTWaveK *unk20;
    u8 pad24[0x11];
    u8 unk35;
    u8 unk36;
} TTVceK;
typedef struct {
    u8 pad0[0x60];
    TTChanK *unk60;
    TTVceK *unk64;
} TTSeqK;
extern void func_8002A890();
extern f32 func_80028B74(s32);
extern s32 D_8007EA50[];
extern f32 func_80027170(s32);
void func_80026CB0(u8 *, s32, f32, s32, s32, s32, s32, f32, s32, s32);
typedef struct {
    s16 type;
    u8 pad2[2];
    void *unk4;
    union {
        s32 w;
        struct {
            u8 b0, b1, b2, b3;
        } b;
    } msg;
    u8 chan;
    u8 padD[3];
} SEvt;
typedef struct {
    u8 pad0[0x10];
    s32 samplesLeft;
    u8 pad14[8];
    s32 curTime;
    u8 pad20[4];
    s32 uspt;
    u8 pad28[4];
    s32 state;
    s32 chanMask;
    u8 pad34[0x50];
    s32 queue;
} TSeqP;
typedef struct {
    u8 pad0[4];
    u8 status;
    u8 type;
    u8 byte1;
    u8 byte2;
    s32 duration;
} TMidi;
typedef struct {
    u8 pad0[4];
    u8 priority;
    u8 pad5[2];
    u8 fxBus;
    u8 sustain;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    f32 unkC;
    u8 flags10;
    u8 enabled11;
    u8 tuning12;
    u8 param13;
    f32 pitchBend;
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 custom24;
    u8 attackVolume;
    u8 decayVolume;
    s8 detune;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    u8 pad30;
    u8 oscParam31;
    u8 program32;
    u8 unk33;
    u8 unk34;
    u8 pad35[3];
} TChan;
typedef struct {
    s32 attackTime;
    s32 decayTime;
    u8 pad8[4];
    u8 attackVolume;
    u8 decayVolume;
    u8 padE[6];
    u8 keyBase;
    s8 detune;
    u8 pad16[2];
    u8 wavetable[1];
} TSound;
typedef struct TVoice {
    struct TVoice *next;
    u8 voice[0x1C];
    TSound *sound;
    s16 unk24;
    s16 unk26;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
    void *oscState;
    void *oscState2;
} TVoice;
typedef struct Link {
    struct Link *next;
    struct Link *prev;
} Link;
typedef struct {
    u8 pad0[4];
    u8 status;
    u8 type;
    u8 pad6;
    u8 byte1;
    u8 byte2;
    u8 byte3;
} TempoEvent;
typedef struct {
    s16 type;
    u8 pad2[2];
    TempoEvent tempo;
} Event_80024A5C;
typedef struct EventListItem {
    Link node;
    s32 delta;
    Event_80024A5C evt;
} EventListItem;
typedef struct {
    u8 pad0[8];
    Link allocList;
} EventQueue_80024A5C;
typedef struct {
    u8 pad0[0x24];
    s32 uspt;
    u8 pad28[0x48 - 0x28];
    EventQueue_80024A5C evtq;
} SeqPlayer_80024A5C;
void func_80020E74(EventListItem *);
void func_80020E40(EventListItem *, EventListItem *);
typedef struct TTLinkQ_s {
    struct TTLinkQ_s *next;
    struct TTLinkQ_s *prev;
} TTLinkQ;
typedef struct {
    TTLinkQ freeList;
    TTLinkQ allocList;
} TTEvtqQ;
typedef struct {
    TTLinkQ node;
    s32 unk8; // delta
} TTItemQ;
typedef struct {
    u8 pad0[0x8];
    f32 unk8;
} TTSrcD90;
typedef struct {
    u8 pad0[0x18];
    TTSrcD90 *unk18;
    u8 pad1C[8];
    s32 unk24;
} TTSD90;
typedef struct {
    u8 pad0[0x18];
    void *unk18;
    u8 pad1C[8];
    s32 unk24;
    u8 pad28[4];
    s32 unk2C;
    u8 pad30[0x18];
    u8 evtq48;
} TTSeqT;
extern s32 func_8002ABE0(void *, s32 *);

s32 func_8002241C(void *arg);
void func_80022D1C(TTSeqD *player);
void func_80023008(u8 *player, u8 *evt);
void func_80024A5C(SeqPlayer_80024A5C *player, Event_80024A5C *evt);
void func_80024C9C(TTEvtqQ *evtq, TTItemQ *item);
void func_80024D90(TTSD90 *player, f32 tempo);
void func_80024DD8(TTSeqT *player);

// alCSPNew: sets up the channel and voice pools and registers the handler.
void func_800221B0(TTChan *player, TTChanCfg *cfg)
{
    s32 i;
    void *evt_buf;
    TTPoolElem *vs;
    TTPoolElem *voices;
    void *arena;

    arena = cfg->unkC;
    player->unk20 = 0;
    player->unk18 = 0;
    player->unk14 = D_800411F4;
    func_80026100(player);
    player->unk24 = 0x1E8;
    player->unk28 = 0;
    player->unk2C = 0;
    player->unk34 = 0x7FFF;
    player->unk37 = cfg->unk9;
    player->unk5C = 0x3E80;
    player->unk1C = 0;
    player->unk70 = cfg->unk10;
    player->unk74 = cfg->unk14;
    player->unk78 = cfg->unk18;
    player->unk7C = 0.0f;
    player->unk80 = 1.0f;
    player->unk84 = 0;
    player->unk89 = 0;
    player->unk88 = cfg->unk0;
    player->unk38 = 9;
    player->unk36 = cfg->unk8;
    player->unk60 = func_80020EE4(0, 0, arena, cfg->unk8, 0x38);
    func_8002A0CC(player);
    voices = func_80020EE4(0, 0, arena, cfg->unk0, 0x44);
    player->unk6C = 0;
    for (i = 0; i < cfg->unk0; i++) {
        vs = &voices[i];
        vs->unk0 = player->unk6C;
        player->unk6C = vs;
    }
    player->unk64 = 0;
    player->unk68 = 0;
    evt_buf = func_80020EE4(0, 0, arena, cfg->unk4, 0x1C);
    func_800263C0(&player->unk48, evt_buf, cfg->unk4);
    player->unk0 = 0;
    player->unk8 = func_8002241C;
    player->unk4 = player;
    func_80026860(player);
}

// Sequence player handler; processes queued events, returns ticks until the next one.
s32 func_8002241C(void *arg)
{
    SeqPlayer_8002241C *player = (SeqPlayer_8002241C *) arg;
    Event_8002241C evt;
    HardwareVoice *hw_voice;
    s32 delay;
    VoiceState *vstate;
    void *osc_state;
    f32 osc_value;
    u8 chan_idx;

    do {
        switch (player->nextEvent.type) {
            case 0:
                func_80022D1C(player);
                break;
            case 9:
                evt.type = 9;
                func_80026500(&player->evtq, &evt, player->frameTime, 1);
                break;
            case 5:
                hw_voice = player->nextEvent.msg.note.voice;
                func_80026FF0(hw_voice);
                func_80027090(hw_voice);
                vstate = (VoiceState *) hw_voice->clientPrivate;
                if (vstate->flags) {
                    func_8002A6A4(player, vstate);
                }
                func_80029670(player, hw_voice);
                break;
            case 6:
                hw_voice = player->nextEvent.msg.vol.voice;
                vstate = (VoiceState *) hw_voice->clientPrivate;
                if (vstate->envPhase == 0) {
                    vstate->envPhase = 1;
                }
                delay = player->nextEvent.msg.vol.delta;
                vstate->envEndTime = player->curTime + delay;
                vstate->envGain = player->nextEvent.msg.vol.vol;
                func_80026BE0(hw_voice, func_80029D54(vstate, player), delay);
                break;
            case 22:
                vstate = player->nextEvent.msg.osc.vs;
                osc_state = player->nextEvent.msg.osc.oscState;
                delay = (*player->updateOsc)(osc_state, &osc_value);
                vstate->tremelo = (u8) osc_value;
                func_80026BE0(&vstate->voice, func_80029D54(vstate, player),
                              func_80029F5C(vstate, player->curTime));
                evt.type = 22;
                evt.msg.osc.vs = vstate;
                evt.msg.osc.oscState = osc_state;
                func_80026500(&player->evtq, &evt, delay, 0);
                break;
            case 23:
                vstate = player->nextEvent.msg.osc.vs;
                osc_state = player->nextEvent.msg.osc.oscState;
                chan_idx = player->nextEvent.msg.osc.chan;
                delay = (*player->updateOsc)(osc_state, &osc_value);
                vstate->vibrato = osc_value;
                func_80026E90(&vstate->voice, vstate->pitch * vstate->vibrato *
                                                   player->chanState[chan_idx].pitchBend);
                if (player->chanState[chan_idx].enabled11) {
                    func_8002A7E0(&vstate->voice,
                                  (440.0f *
                                   func_80028B74((player->chanState[chan_idx].tuning12 +
                                                  (vstate->key - vstate->sound->keyBase)) -
                                                 0x40) *
                                   player->chanState[chan_idx].pitchBend) *
                                      vstate->vibrato);
                }
                evt.type = 23;
                evt.msg.osc.vs = vstate;
                evt.msg.osc.oscState = osc_state;
                evt.msg.osc.chan = chan_idx;
                func_80026500(&player->evtq, &evt, delay, 0);
                break;
            case 2:
            case 21:
                func_80023008(player, &player->nextEvent);
                break;
            case 7:
                func_80024A5C(player, &player->nextEvent);
                break;
            case 10:
                player->vol = player->nextEvent.msg.spvol.vol;
                for (vstate = player->vAllocHead; vstate != 0; vstate = vstate->next) {
                    func_80026BE0(&vstate->voice, func_80029D54(vstate, player),
                                  func_80029F5C(vstate, player->curTime));
                }
                break;
            case 24:
                player->unk7C = player->nextEvent.msg.evt18.unk0;
                player->unk80 = player->nextEvent.msg.evt18.unk4;
                for (vstate = player->vAllocHead; vstate != 0;) {
                    if (vstate->envPhase != 3) {
                        func_80026F40(&vstate->voice, func_80029E64(vstate, player));
                    }
                    vstate = vstate->next;
                }
                break;
            case 25:
                if (player->nextEvent.msg.evt19.unk1 < 8) {
                    s32 unk_0 = func_8002A940(player->nextEvent.msg.evt19.unk0);
                    if (unk_0) {
                        func_8002AA30(unk_0,
                                      (player->nextEvent.msg.evt19.unk2 << 3) |
                                          (player->nextEvent.msg.evt19.unk1 & 7),
                                      &player->nextEvent.msg.evt19.param);
                    }
                } else {
                    s32 unk_1 = func_8002A9B8(player->nextEvent.msg.evt19.unk0);
                    if (unk_1) {
                        func_8002AA74(unk_1, player->nextEvent.msg.evt19.unk1,
                                      &player->nextEvent.msg.evt19.param);
                    }
                }
                break;
            case 15:
                if (player->state != 1) {
                    player->state = 1;
                    func_80024DD8(player);
                }
                break;
            case 16:
                if (player->state == 2) {
                    for (vstate = player->vAllocHead; vstate != 0;
                         vstate = player->vAllocHead) {
                        func_80026FF0(&vstate->voice);
                        func_80027090(&vstate->voice);
                        if (vstate->flags) {
                            func_8002A6A4(player, vstate);
                        }
                        func_80029670(player, &vstate->voice);
                    }
                    player->state = 0;
                }
                break;
            case 17:
                if (player->state == 1) {
                    func_800266B0(&player->evtq, 0);
                    func_800266B0(&player->evtq, 21);
                    func_800266B0(&player->evtq, 2);
                    for (vstate = player->vAllocHead; vstate != 0; vstate = vstate->next) {
                        if (func_800298E4(player, &vstate->voice, 0xC350)) {
                            func_8002976C(player, &vstate->voice, 0xC350);
                        }
                    }
                    for (chan_idx = 0; chan_idx < 32; chan_idx++) {
                        player->chanState[chan_idx].unk9 = player->chanState[chan_idx].unkA;
                        if (player->chanState[chan_idx].unk9 == 0) {
                            player->chanMask &= (1 << chan_idx) ^ -1;
                        } else {
                            player->chanMask |= 1 << chan_idx;
                        }
                    }
                    player->state = 2;
                    evt.type = 16;
                    func_80026500(&player->evtq, &evt, 0x7FFFFFFF, 0);
                }
                break;
            case 12:
                chan_idx = player->nextEvent.msg.evt19.unk0;
                player->chanState[chan_idx].pad0[4] = player->nextEvent.msg.evt19.unk1;
                break;
            case 13:
                player->target = player->nextEvent.msg.spseq.seq;
                player->chanMask = -1;
                func_8002A024(player, player->bank);
                goto switch_join;
            // Matching: these gotos are needed for the match.
            case 14:
                goto switch_join;
            case 1:
            case 3:
            case 4:
                goto switch_join;
        }
    switch_join:
        player->nextDelta = func_8002645C(&player->evtq, &player->nextEvent);
    } while (player->nextDelta == 0);

    player->curTime += player->nextDelta;
    return player->nextDelta;
}

// Pulls the next event from the cseq parser and dispatches it.
void func_80022D1C(TTSeqD *player)
{
    TTEvtD evt;

    if (player->unk18 == 0)
        return;

    func_80025084(player->unk18, &evt, 1);

    switch (evt.type) {
        case 1:
            func_80023008(player, &evt);
            func_80024DD8(player);
            break;

        case 3:
            func_80024A5C(player, &evt);
            func_80024DD8(player);
            break;

        case 4:
            player->unk2C = 2;
            evt.type = 0x10;
            func_80026500(&player->evtq48, &evt, 0x7FFFFFFF, 0);
            break;

        case 0x12:
        case 0x13:
        case 0x14:
            func_80024DD8(player);
            break;

        default:
            break;
    }
}

// Refreshes volume of all active voices on a channel.
void func_80022E20(TTSeqQ *player, u8 chan)
{
    TTVceQ *v;
    s16 vol;

    for (v = player->unk64; v != 0; v = v->unk0) {
        if (v->unk35 == chan && v->unk38 != 3) {
            vol = func_80029D54(v, player);
            func_80026BE0(&v->unk4, vol, func_80029F5C(v, player->unk1C));
        }
    }
}

// Re-applies pitch/tuning to active voices on a channel.
void func_80022ECC(TTSeqK *player, u8 chan)
{
    TTVceK *it;
    s16 vel;
    s8 d;
    f32 base;

    d = player->unk60[chan].unk12 - 0x40;
    base = player->unk60[chan].unk14;

    for (it = player->unk64; it != 0; it = it->unk0) {
        if (it->unk35 == chan) {
            vel = player->unk60[chan].unk11;
            func_8002A890(&it->unk4, vel);

            if (vel != 0) {
                func_8002A7E0(&it->unk4,
                              func_80028B74(it->unk36 - it->unk20->unk14 + d) * 440.0f * base);
            }
        }
    }
}

// Handles one MIDI message: note on/off, aftertouch, controllers, program change, pressure, pitch bend.
void func_80023008(u8 *player, u8 *evt)
{
    u8 *hw_voice;
    TVoice *it;
    s32 cmd;
    u8 midi_chan;
    u8 note;
    u8 vel;
    u8 ctrl;
    u8 value;
    TMidi *midi;
    s16 volume;
    SEvt out_evt;
    s32 delay;
    TVoice *vs;
    u8 pan;
    TChan *chan_state;
    s32 unk_0;
    ALVoiceConfig voice_cfg;
    TSound *snd;
    s16 note_cents;
    f32 pitch_mul;
    f32 osc_value;
    u8 unk_1;
    u8 enabled;
    f32 freq;
    s32 osc_state;
    u8 *prog_def;
    f32 fade_diff;
    f32 fade_step;
    u8 cur_vol;
    u8 target_vol;
    s32 change;
    s32 max_change;
    f32 fade_speed;
    f32 interval;
    s32 unk_2;
    s32 bend_raw;
    f32 bend_ratio;
    s32 bend_cents;
    midi = (TMidi *) (evt + 4);
    cmd = midi->status & 0xF0;
    midi_chan = midi->type;
    ctrl = (note = midi->byte1);
    value = (vel = midi->byte2);
    switch (cmd) {
        case 0x90:
            if (vel != 0) {
                osc_state = 0;
                if ((*(s32 *) ((s8 *) player + 0x2C) != 1) ||
                    !(*(s32 *) ((s8 *) player + 0x30) & (1 << midi_chan))) {
                    if (midi->duration != 0) {
                        out_evt.type = 0x15;
                        out_evt.msg.b.b0 = 0x80;
                        out_evt.msg.b.b1 = midi_chan;
                        out_evt.msg.b.b2 = note;
                        out_evt.msg.b.b3 = 0;
                        delay = ((TSeqP *) player)->uspt * midi->duration;
                        D_8007EA50[midi_chan] = delay;
                        func_80026500(player + 0x48, &out_evt, delay, 0);
                    }
                    goto dummy_label_257363;
                }
                chan_state = (TChan *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38));
                snd = func_80029BA0(player, note, vel, midi_chan);
                if (snd == 0) {
                    return;
                }
                voice_cfg.priority = (s16) *(u8 *) ((s8 *) chan_state + 4);
                voice_cfg.fxBus = (s16) *(u8 *) ((s8 *) chan_state + 7);
                voice_cfg.unityPitch = 0;
                vs = func_80029A04(player, note, vel, midi_chan, snd);
                if (vs == 0) {
                    return;
                }
                hw_voice = vs->voice;
                func_800268D0(hw_voice, &voice_cfg);
                *(s16 *) ((s8 *) vs + 0x26) =
                    (s16) *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x33);
                *(s16 *) ((s8 *) vs + 0x24) =
                    (s16) *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x34);
                *(u8 **) ((s8 *) vs + 0x20) = snd;
                *(s8 *) ((s8 *) vs + 0x38) = 0;
                if ((s32) *(u8 *) ((s8 *) chan_state + 8) >= 0x40) {
                    *(u8 *) ((s8 *) vs + 0x39) = 2U;
                } else {
                    *(u8 *) ((s8 *) vs + 0x39) = 0U;
                }
                note_cents =
                    *(s8 *) ((s8 *) snd + 0x15) + ((note - *(u8 *) ((s8 *) snd + 0x14)) * 0x64);
                if (chan_state->custom24 != 0) {
                    note_cents += chan_state->detune;
                }
                *(f32 *) ((s8 *) vs + 0x2C) = func_80027170(note_cents);
                if (chan_state->custom24 != 0) {
                    *(u8 *) ((s8 *) vs + 0x34) = chan_state->attackVolume;
                    *(s32 *) ((s8 *) vs + 0x28) = ((TSeqP *) player)->curTime + chan_state->attackTime;
                } else {
                    *(u8 *) ((s8 *) vs + 0x34) = snd->attackVolume;
                    *(s32 *) ((s8 *) vs + 0x28) = ((TSeqP *) player)->curTime + snd->attackTime;
                }
                *(u8 *) ((s8 *) vs + 0x3B) = 0U;
                if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                    unk_0 = (s32) *(u8 *) ((s8 *) chan_state + 0x28);
                } else {
                    prog_def = func_800E93AC(
                        *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x33));
                    unk_0 = (s32) *(u8 *) ((s8 *) prog_def + 4);
                }
                osc_value = 127.0f;
                if ((unk_0 != 0) &&
                    (*(s32(**)(s32 *, f32 *, u8, u8, s32, s32, s32))((s8 *) player + 0x70) != 0)) {
                    if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                        delay =
                            (*(s32(**)(s32 *, f32 *, u8, u8, s32, s32, s32))((s8 *) player + 0x70))(
                                &osc_state, &osc_value, *(u8 *) ((s8 *) chan_state + 0x28),
                                *(u8 *) ((s8 *) chan_state + 0x29), (s32) *(u8 *) ((s8 *) chan_state + 0x2A),
                                (s32) *(u8 *) ((s8 *) chan_state + 0x2B),
                                (s32) *(u8 *) ((s8 *) chan_state + 0x31));
                    } else {
                        delay =
                            (*(s32(**)(s32 *, f32 *, u8, u8, s32, s32, s32))((s8 *) player + 0x70))(
                                &osc_state, &osc_value, *(u8 *) ((s8 *) prog_def + 4), *(u8 *) ((s8 *) prog_def + 5),
                                (s32) *(u8 *) ((s8 *) prog_def + 6), (s32) *(u8 *) ((s8 *) prog_def + 7),
                                (s32) *(u8 *) ((s8 *) chan_state + 0x31));
                    }
                    if (delay != 0) {
                        out_evt.type = 0x16;
                        out_evt.unk4 = vs;
                        out_evt.msg.w = osc_state;
                        func_80026500(player + 0x48, &out_evt, delay, 0);
                        *(u8 *) ((s8 *) vs + 0x3B) = (u8) (*(u8 *) ((s8 *) vs + 0x3B) | 1);
                        *(s32 *) ((s8 *) vs + 0x3C) = osc_state;
                    }
                }
                *(s8 *) ((s8 *) vs + 0x3A) = (s8) (u32) osc_value;
                osc_value = 1.0f;
                if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                    unk_0 = (s32) *(u8 *) ((s8 *) chan_state + 0x2C);
                } else {
                    unk_0 = (s32) *(u8 *) ((s8 *) prog_def + 8);
                }
                if ((unk_0 != 0) &&
                    (*(s32(**)(s32 *, f32 *, u8, u8, s32, s32, s32))((s8 *) player + 0x70) != 0)) {
                    if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                        delay =
                            (*(s32(**)(s32 *, f32 *, u8, u8, s32, s32, s32))((s8 *) player + 0x70))(
                                &osc_state, &osc_value, *(u8 *) ((s8 *) chan_state + 0x2C),
                                *(u8 *) ((s8 *) chan_state + 0x2D), (s32) *(u8 *) ((s8 *) chan_state + 0x2E),
                                (s32) *(u8 *) ((s8 *) chan_state + 0x2F),
                                (s32) *(u8 *) ((s8 *) chan_state + 0x31));
                    } else {
                        delay =
                            (*(s32(**)(s32 *, f32 *, u8, u8, s32, s32, s32))((s8 *) player + 0x70))(
                                &osc_state, &osc_value, *(u8 *) ((s8 *) prog_def + 8), *(u8 *) ((s8 *) prog_def + 9),
                                (s32) *(u8 *) ((s8 *) prog_def + 0xA),
                                (s32) *(u8 *) ((s8 *) prog_def + 0xB),
                                (s32) *(u8 *) ((s8 *) chan_state + 0x31));
                    }
                    if (delay != 0) {
                        out_evt.type = 0x17;
                        out_evt.unk4 = vs;
                        out_evt.msg.w = osc_state;
                        out_evt.chan = midi_chan;
                        func_80026500(player + 0x48, &out_evt, delay, 0);
                        *(u8 *) ((s8 *) vs + 0x3B) = (u8) (*(u8 *) ((s8 *) vs + 0x3B) | 2);
                        *(s32 *) ((s8 *) vs + 0x40) = osc_state;
                    }
                }
                *(f32 *) ((s8 *) vs + 0x30) = osc_value;
                pitch_mul = vs->pitch * chan_state->pitchBend * vs->vibrato;
                unk_1 = func_80029E64(vs, player);
                enabled = *(u8 *) ((s8 *) chan_state + 0x11);
                if (enabled != 0) {
                    freq =
                        440 * func_80028B74((note_cents / 100) + chan_state->tuning12 - 0x40) * chan_state->pitchBend;
                } else {
                    freq = 127.0f;
                }
                pan = func_80029FA0(vs, player);
                volume = func_80029D54(vs, player);
                if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                    delay = *(s32 *) ((s8 *) chan_state + 0x18);
                } else {
                    delay = *(s32 *) ((s8 *) snd + 0);
                }
                // Matching: the `^ 0` on the pan argument is needed for the match.
                func_80026CB0(hw_voice, snd->wavetable, pitch_mul, volume, (s32) pan ^ 0, (s32) unk_1,
                              (s32) enabled, freq, (s32) *(u8 *) ((s8 *) chan_state + 0x13), delay);
                out_evt.type = 6;
                out_evt.unk4 = hw_voice;
                if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                    out_evt.chan = *(u8 *) ((s8 *) chan_state + 0x26);
                    out_evt.msg.w = *(s32 *) ((s8 *) chan_state + 0x1C);
                } else {
                    out_evt.chan = *(u8 *) ((s8 *) snd + 0xD);
                    out_evt.msg.w = *(s32 *) ((s8 *) snd + 4);
                }
                func_80026500(player + 0x48, &out_evt, delay, 0);
                if (midi->duration != 0) {
                    out_evt.type = 0x15;
                    out_evt.msg.b.b0 = 0x80;
                    out_evt.msg.b.b1 = midi_chan;
                    out_evt.msg.b.b2 = note;
                    out_evt.msg.b.b3 = 0;
                    delay = ((TSeqP *) player)->uspt * midi->duration;
                    D_8007EA50[midi_chan] = delay;
                    func_80026500(player + 0x48, &out_evt, delay, 0);
                }
                if ((chan_state->flags10 & 1) && (((TSeqP *) player)->queue != 0)) {
                    osSendMesg(((TSeqP *) player)->queue,
                               (D_8007EA50[midi_chan] & ~0xFF) | (chan_state->flags10 >> 2), 0);
                }
                goto dummy_label_257363;
            }

        case 0x80:
            vs = func_80029B18(player, note, midi_chan);

            if (vs == 0) {
                return;
            }
            chan_state = (TChan *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38));
            if (*(u8 *) ((s8 *) vs + 0x39) == 2) {
                *(u8 *) ((s8 *) vs + 0x39) = 4U;
            } else {
                *(u8 *) ((s8 *) vs + 0x39) = 3U;
                if (chan_state->custom24 != 0) {
                    func_8002976C(player, vs->voice, chan_state->releaseTime);
                } else {
                    func_8002976C(player, vs->voice,
                                  *(s32 *) ((s8 *) *(u8 **) ((s8 *) vs + 0x20) + 8));
                }
            }
            if ((chan_state->flags10 & 2) && (((TSeqP *) player)->queue != 0)) {
                osSendMesg(((TSeqP *) player)->queue, ((note << 0x10) | 8) | (chan_state->flags10 >> 2), 0);
            }
            goto dummy_label_257363;

        case 0xA0:
            vs = func_80029B18(player, note, midi_chan);
            if (vs == 0) {
                return;
            }
            *(u8 *) ((s8 *) vs + 0x37) = value;
            func_80026BE0(vs->voice, func_80029D54(vs, player),
                          func_80029F5C(vs, *(s32 *) ((s8 *) player + 0x1C)));
            goto dummy_label_257363;

        case 0xD0:
            for (it = *(TVoice **) ((s8 *) player + 0x64); it != 0; it = it->next) {
                if (it->channel == midi_chan) {
                    it->velocity = ctrl;
                    func_80026BE0(it->voice, func_80029D54(it, player),
                                  func_80029F5C(it, *(s32 *) ((s8 *) player + 0x1C)));
                }
            }

            goto dummy_label_257363;

        case 0xB0:
            switch ((s32) ctrl) {
                case 0xA:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 3) = value;
                    for (it = *(u8 **) ((s8 *) player + 0x64); it != 0;
                         it = *(u8 **) ((s8 *) it + 0)) {
                        if (*(u8 *) ((s8 *) it + 0x35) == midi_chan) {
                            pan = func_80029FA0(it, player);
                            func_80026DE0(it->voice, pan);
                        }
                    }

                    break;

                case 0xFD:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xB) = value;
                    break;

                case 0xFF:
                    if (*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xB) ==
                        0) {
                        *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xB) =
                            0x88;
                    }
                    if (*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xA) !=
                        value) {
                        fade_diff =
                            (f32) (value -
                                   *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                            9));
                        fade_step =
                            fade_diff /
                            (f32) (*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                            0xB) &
                                   0x7F);
                        if (fade_step < 0.0f) {
                            fade_step = -fade_step;
                        }
                        *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xC) =
                            fade_step;
                        if (*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                     0xA) ==
                            *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 9)) {
                            *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xA) =
                                value;
                        } else {
                            *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xA) =
                                value;
                            break;
                        }
                    } else {
                        break;
                    }
                    midi->byte1 = 0xFEU;

                case 0xFE:
                    cur_vol = *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 9);
                    target_vol = *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xA);
                    fade_speed = *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xC);
                    vel = *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xB);
                    change = target_vol - cur_vol;
                    if (change > 0) {
                        if (*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xB) &
                            0x80) {
                            fade_speed *= 2.0f;
                        }
                        max_change = (s32) fade_speed;
                        if (max_change == 0) {
                            max_change = 1;
                            interval = 1.0f / fade_speed;
                        } else {
                            interval = (f32) max_change / fade_speed;
                        }
                        if (change > max_change) {
                            change = max_change;
                        }
                    } else {
                        max_change = (s32) fade_speed;
                        if (max_change == 0) {
                            max_change = 1;
                            interval = fade_speed;
                        } else {
                            interval = (f32) max_change / fade_speed;
                        }
                        max_change = -max_change;
                        if (change < max_change) {
                            change = max_change;
                        }
                    }
                    cur_vol += change;
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 9) = cur_vol;
                    if (cur_vol != target_vol) {
                        func_80026500(player + 0x48, evt,
                                      (s32) ((f32) (((TSeqP *) player)->uspt * 0x64) * interval), 0);
                    }
                    if (cur_vol != 0) {
                        ((TSeqP *) player)->chanMask |= 1 << midi_chan;
                    } else {
                        ((TSeqP *) player)->chanMask &= ~(1 << midi_chan);
                    }
                    func_80022E20(player, midi_chan);
                    break;

                case 0xFC:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 9) = value;
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0xA) = value;
                    if (value == 0) {
                        ((TSeqP *) player)->chanMask &= (1 << midi_chan) ^ -1;
                    } else {
                        ((TSeqP *) player)->chanMask |= 1 << midi_chan;
                    }
                    func_80022E20(player, midi_chan);
                    break;

                case 0x21:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x11) = value;
                    func_80022ECC(player, midi_chan);
                    break;

                case 0x22:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x12) = value;
                    func_80022ECC(player, midi_chan);
                    break;

                case 0x23:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x13) = value;
                    for (it = *(u8 **) ((s8 *) player + 0x64); it != 0;
                         it = *(u8 **) ((s8 *) it + 0)) {
                        if (*(u8 *) ((s8 *) it + 0x35) == midi_chan) {
                            func_8002AB30(it->voice, value);
                        }
                    }

                    break;

                case 0x1E:
                    if (((TSeqP *) player)->queue != 0) {
                        osSendMesg(((TSeqP *) player)->queue,
                                   ((value & 7) | 0x10) |
                                       ((((TSeqP *) player)->samplesLeft << 5) & ~0xFF),
                                   0);
                    }
                    break;

                case 0x7:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 5) = value;
                    for (it = *(u8 **) ((s8 *) player + 0x64); it != 0;
                         it = *(u8 **) ((s8 *) it + 0)) {
                        if ((*(u8 *) ((s8 *) it + 0x35) == midi_chan) &&
                            (*(u8 *) ((s8 *) it + 0x38) != 3)) {
                            volume = func_80029D54(it, player);
                            func_80026BE0(it->voice, volume,
                                          func_80029F5C(it, *(s32 *) ((s8 *) player + 0x1C)));
                        }
                    }

                    break;

                case 0x10:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 4) = value;
                    break;

                case 0x40:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 8) = value;
                    for (it = *(u8 **) ((s8 *) player + 0x64); it != 0;
                         it = *(u8 **) ((s8 *) it + 0)) {
                        if ((*(u8 *) ((s8 *) it + 0x35) == midi_chan) &&
                            (*(u8 *) ((s8 *) it + 0x39) != 3)) {
                            if ((s32) value >= 0x40) {
                                if (*(u8 *) ((s8 *) it + 0x39) == 0) {
                                    *(u8 *) ((s8 *) it + 0x39) = 2U;
                                }
                            } else if (*(u8 *) ((s8 *) it + 0x39) == 2) {
                                *(u8 *) ((s8 *) it + 0x39) = 0U;
                            } else if (*(u8 *) ((s8 *) it + 0x39) == 4) {
                                *(u8 *) ((s8 *) it + 0x39) = 3U;
                                if (*(u8 *) ((s8 *) chan_state + 0x24) != 0) {
                                    func_8002976C(
                                        player, it->voice,
                                        (0x3E80 > *(s32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) +
                                                                    (midi_chan * 0x38)) +
                                                            0x20))
                                            ? 0x3E80
                                            : *(s32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) +
                                                                (midi_chan * 0x38)) +
                                                        0x20));
                                } else {
                                    func_8002976C(
                                        player, it->voice,
                                        (0x3E80 >
                                         *(s32 *) ((s8 *) *(u8 **) ((s8 *) vs + 0x20) + 8))
                                            ? 0x3E80
                                            : *(s32 *) ((s8 *) *(u8 **) ((s8 *) vs + 0x20) + 8));
                                }
                            }
                        }
                    }

                    break;

                case 0x5B:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 6) =
                        (u8) ((*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                        6) &
                               0x80) |
                              value);
                    value =
                        (u8) ((s32) *
                                  (u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                          6) >>
                              7);

                case 0x41:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 6) =
                        (u8) ((*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                        6) &
                               0x7F) |
                              (value << 7));
                    for (it = *(u8 **) ((s8 *) player + 0x64); it != 0;
                         it = *(u8 **) ((s8 *) it + 0)) {
                        if ((*(u8 *) ((s8 *) it + 0x35) == midi_chan) &&
                            (*(u8 *) ((s8 *) it + 0x38) != 3)) {
                            func_80026F40(
                                it->voice,
                                *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) +
                                         6));
                        }
                    }

                    break;

                case 0x5C:
                    if ((s32) value < *(s32 *) ((s8 *) (u8 *) D_800411F4 + 0x3C)) {
                        *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 7) = value;
                    }
                    break;

                case 0x1A:
                    break;

                case 0x20:
                    *(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x32) = value;
                    break;

                case 0x29:
                    unk_2 = (s32) ((f32) *(s32 *) ((s8 *) player + 0x24) /
                                  *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x18) + 8));
                    unk_2 = 0x03938700 / unk_2;
                    unk_2 = (unk_2 + (value & 0xFFFFFFFFu)) - 0x40;
                    func_80024D90(player, (f32) (0x03938700 / unk_2));
                    break;

                default:
                    break;
            }

            goto dummy_label_257363;

        case 0xC0:
            unk_0 = (*(u8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x32) << 7) +
                   note;
            // Matching: the empty else block is needed for the match.
            if (unk_0 < func_800E9048()) {
                func_8002A318(player, unk_0, midi_chan);
            } else {
            }
            goto dummy_label_257363;

        case 0xE0:
            bend_raw = ((value << 7) + ctrl) - 0x2000;
            bend_cents = (s32) (*(s16 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0) *
                          bend_raw) /
                   8192;
            bend_ratio = func_80027170(bend_cents);
            *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x60) + (midi_chan * 0x38)) + 0x14) = bend_ratio;
            for (it = *(TVoice **) ((s8 *) player + 0x64); it != 0; it = it->next) {
                if (it->channel == midi_chan) {
                    func_80026E90(it->voice, it->pitch * bend_ratio * it->vibrato);
                    if (((TChan *) *(s32 *) ((s8 *) player + 0x60))[midi_chan].enabled11 != 0) {
                        func_8002A7E0(
                            it->voice,
                            440 *
                                func_80028B74(
                                    (it->key - it->sound->keyBase) +
                                    ((TChan *) *(s32 *) ((s8 *) player + 0x60))[midi_chan].tuning12 -
                                    0x40) *
                                bend_ratio * it->vibrato);
                    }
                }
            }

            goto dummy_label_257363;

        default:
            break;
    }

dummy_label_257363:;
}

// Tempo meta event: sets the new tempo and rescales queued note-off events.
void func_80024A5C(SeqPlayer_80024A5C *player, Event_80024A5C *evt)
{
    TempoEvent *meta = &evt->tempo;
    s32 new_tempo;
    s32 old_uspt;
    u32 ticks;
    s32 abs_time;
    s32 acc_delta = 0;
    EventListItem *item;
    EventListItem *next_item;
    EventListItem *noteoff_head = 0;

    if (evt->tempo.status == 0xFF) {
        if (evt->tempo.type == 0x51) {
            old_uspt = player->uspt;
            new_tempo = (meta->byte1 << 16) | (meta->byte2 << 8) | meta->byte3;
            func_80024D90(player, (f32) new_tempo);

            item = (EventListItem *) player->evtq.allocList.next;
            while (item) {
                acc_delta += item->delta;
                next_item = (EventListItem *) item->node.next;
                if (item->evt.type == 0x15) {
                    func_80020E74(item);
                    if (noteoff_head) {
                        func_80020E40(item, noteoff_head);
                    } else {
                        item->node.next = 0;
                        item->node.prev = 0;
                        noteoff_head = item;
                    }
                    abs_time = acc_delta;
                    if (next_item) {
                        acc_delta -= item->delta;
                        next_item->delta += item->delta;
                    }
                    item->delta = abs_time;
                }
                item = next_item;
            }

            item = noteoff_head;
            while (item) {
                next_item = (EventListItem *) item->node.next;
                ticks = item->delta / old_uspt;
                item->delta = ticks * player->uspt;
                func_80024C9C(&player->evtq, item);
                item = next_item;
            }
        }
    }
}

// Inserts an item into the delta-ordered event list.
void func_80024C9C(TTEvtqQ *evtq, TTItemQ *item)
{
    s32 int_mask;
    TTLinkQ *node;
    TTItemQ *next_item;

    int_mask = osSetIntMask(1);

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            func_80020E40(item, node);
            break;
        } else {
            next_item = (TTItemQ *) node->next;

            if (item->unk8 < next_item->unk8) {
                next_item->unk8 = next_item->unk8 - item->unk8;
                func_80020E40(item, node);
                break;
            }

            item->unk8 = item->unk8 - next_item->unk8;
        }
    }

    osSetIntMask(int_mask);
}

// Sets microseconds per tick from the tempo.
void func_80024D90(TTSD90 *player, f32 tempo)
{
    if (player->unk18)
        player->unk24 = (s32) ((f32) tempo * player->unk18->unk8);
    else
        player->unk24 = 0x1E8;
}

// Posts the next sequence event.
void func_80024DD8(TTSeqT *player)
{
    TTEvtD evt;
    s32 delta;

    if (player->unk2C != 1 || player->unk18 == 0)
        return;

    if (func_8002ABE0(player->unk18, &delta) == 0)
        return;

    evt.type = 0;
    func_80026500(&player->evtq48, &evt, player->unk24 * delta, 0);
}

void func_80024E70(u8 *player, u8 value)
{
    M2C_FIELD(player, u8 *, 0x88) = value;
}
