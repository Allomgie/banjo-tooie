#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy
#endif
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct { void *unk0; /* 0x00 */ void *unk4; /* 0x04 self */ void *unk8; /* 0x08 callback = func_8002241C */ u8 padC[8]; void *unk14; /* 0x14 */ s32 unk18; /* 0x18 */ s32 unk1C; /* 0x1C */ s32 unk20; /* 0x20 */ s32 unk24; /* 0x24 */ s32 unk28; /* 0x28 */ s32 unk2C; /* 0x2C */ u8 pad30[4]; s16 unk34; /* 0x34 */ u8 unk36; /* 0x36 */ u8 unk37; /* 0x37 */ s16 unk38; /* 0x38 */ u8 pad3A[0xE]; u8 unk48; /* 0x48 substruct base */ u8 pad49[0x13]; s32 unk5C; /* 0x5C */ void *unk60; /* 0x60 */ s32 unk64; /* 0x64 */ s32 unk68; /* 0x68 */ void *unk6C; /* 0x6C free-list head */ s32 unk70; /* 0x70 */ s32 unk74; /* 0x74 */ s32 unk78; /* 0x78 */ f32 unk7C; /* 0x7C */ f32 unk80; /* 0x80 */ s32 unk84; /* 0x84 */ u8 unk88; /* 0x88 */ u8 unk89; /* 0x89 */ } TTChan;
typedef struct { s32 unk0; /* 0x00 count */ s32 unk4; /* 0x04 */ u8 unk8; /* 0x08 */ u8 unk9; /* 0x09 */ u8 padA[2]; void *unkC; /* 0x0C arena */ s32 unk10; /* 0x10 */ s32 unk14; /* 0x14 */ s32 unk18; /* 0x18 */ } TTChanCfg;
typedef struct { void *unk0; /* 0x00 */ u8 pad4[0x40]; } TTPoolElem;
extern void func_80026100(TTChan *);
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern void func_8002A0CC(TTChan *);
extern void func_800263C0(void *, void *, s32);
extern void func_80026860(TTChan *);
extern void *D_800411F4;
typedef struct { u8 pad0[0x14]; u8 keyBase; } Sound;
typedef struct { u8 pad0[0x10]; void *clientPrivate; u8 pad14[8]; } HardwareVoice;
typedef struct VoiceState { struct VoiceState *next; HardwareVoice voice; Sound *sound; s16 unk24; s16 unk26; s32 envEndTime; f32 pitch; f32 vibrato; u8 envGain; u8 channel; u8 key; u8 velocity; u8 envPhase; u8 phase; u8 tremelo; u8 flags; void *oscState; void *oscState2; } VoiceState;
typedef struct { u8 pad0[9]; u8 unk9; u8 unkA; u8 padB[6]; u8 enabled11; u8 tuning12; u8 pad13; f32 pitchBend; u8 pad18[0x38 - 0x18]; } ChannelState;
typedef struct { s16 type; u8 pad2[2]; union { struct { HardwareVoice *voice; } note; struct { HardwareVoice *voice; s32 delta; u8 vol; } vol; struct { VoiceState *vs; void *oscState; u8 chan; } osc; struct { s16 vol; } spvol; struct { f32 unk0; f32 unk4; } evt18; struct { u8 unk0; u8 unk1; u8 unk2; u8 pad3; s32 param; } evt19; struct { void *seq; } spseq; struct { void *bank; } spbank; } msg; } Event_8002241C;
typedef struct { u8 opaque[0x14]; } EventQueue_8002241C;
typedef struct { u8 pad0[0x18]; void *target; s32 curTime; void *bank; s32 uspt; s32 nextDelta; s32 state; s32 chanMask; s16 vol; u8 pad36[2]; Event_8002241C nextEvent; EventQueue_8002241C evtq; s32 frameTime; ChannelState *chanState; VoiceState *vAllocHead; u8 pad68[0x74 - 0x68]; s32 (*updateOsc)(void *, f32 *); u8 pad78[4]; f32 unk7C; f32 unk80; } SeqPlayer_8002241C;
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
typedef struct { s16 type; /* 0x0 */ u8 pad2[0xE]; } TTEvtD;
typedef struct { u8 pad0[0x18]; void *unk18; /* 0x18 */ u8 pad1C[0x10]; s32 unk2C; /* 0x2C */ u8 pad30[0x18]; u8 evtq48; /* 0x48 */ } TTSeqD;
extern void func_80025084(void *, TTEvtD *, s32);
extern void func_80026500(void *, TTEvtD *, s32, s32);
typedef struct TTVceQ_s { struct TTVceQ_s *unk0; /* 0x00 */ u8 unk4; /* 0x04: Handle-Basis */ u8 pad5[0x30]; u8 unk35; /* 0x35: Kanal */ u8 pad36[2]; u8 unk38; /* 0x38: Status */ } TTVceQ;
typedef struct { u8 pad0[0x1C]; void *unk1C; /* 0x1C */ u8 pad20[0x44]; TTVceQ *unk64; /* 0x64 */ } TTSeqQ;
extern s32 func_80029F5C(TTVceQ *, void *);
typedef struct { u8 pad0[0x11]; u8 unk11; /* 0x11 */ s8 unk12; /* 0x12 */ u8 pad13[1]; f32 unk14; /* 0x14 */ u8 pad18[0x20]; } TTChanK;
typedef struct { u8 pad0[0x14]; u8 unk14; /* 0x14 */ } TTWaveK;
typedef struct TTVceK_s { struct TTVceK_s *unk0; /* 0x00 */ u8 unk4; /* 0x04: Handle-Basis */ u8 pad5[0x1B]; TTWaveK *unk20; /* 0x20 */ u8 pad24[0x11]; u8 unk35; /* 0x35 */ u8 unk36; /* 0x36 */ } TTVceK;
typedef struct { u8 pad0[0x60]; TTChanK *unk60; /* 0x60 */ TTVceK *unk64; /* 0x64 */ } TTSeqK;
extern void func_8002A890();
extern f32 func_80028B74(s32);
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
extern s32 D_8007EA50[];
extern f32 func_80027170(s32);
void func_80026CB0(u8 *, s32, f32, s32, s32, s32, s32, f32, s32, s32);
typedef struct { s16 type; u8 pad2[2]; void *unk4; union { s32 w; struct { u8 b0, b1, b2, b3; } b; } msg; u8 chan; u8 padD[3]; } SEvt;
typedef struct { u8 pad0[0x10]; s32 samplesLeft; u8 pad14[8]; s32 curTime; u8 pad20[4]; s32 uspt; u8 pad28[4]; s32 state; s32 chanMask; u8 pad34[0x50]; s32 queue; } TSeqP;
typedef struct { u8 pad0[4]; u8 status; u8 type; u8 byte1; u8 byte2; s32 duration; } TMidi;
typedef struct { u8 pad0[4]; u8 priority; u8 pad5[2]; u8 fxBus; u8 sustain; u8 unk9; u8 unkA; u8 unkB; f32 unkC; u8 flags10; u8 enabled11; u8 tuning12; u8 param13; f32 pitchBend; s32 attackTime; s32 decayTime; s32 releaseTime; u8 custom24; u8 attackVolume; u8 decayVolume; s8 detune; u8 tremType; u8 tremRate; u8 tremDepth; u8 tremDelay; u8 vibType; u8 vibRate; u8 vibDepth; u8 vibDelay; u8 pad30; u8 oscParam31; u8 program32; u8 unk33; u8 unk34; u8 pad35[3]; } TChan;
typedef struct { s32 attackTime; s32 decayTime; u8 pad8[4]; u8 attackVolume; u8 decayVolume; u8 padE[6]; u8 keyBase; s8 detune; u8 pad16[2]; u8 wavetable[1]; } TSound;
typedef struct TVoice { struct TVoice *next; u8 voice[0x1C]; TSound *sound; s16 unk24; s16 unk26; s32 envEndTime; f32 pitch; f32 vibrato; u8 envGain; u8 channel; u8 key; u8 velocity; u8 envPhase; u8 phase; u8 tremelo; u8 flags; void *oscState; void *oscState2; } TVoice;
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct { u8 pad0[4]; u8 status; u8 type; u8 pad6; u8 byte1; u8 byte2; u8 byte3; } TempoEvent;
typedef struct { s16 type; u8 pad2[2]; TempoEvent tempo; } Event_80024A5C;
typedef struct EventListItem { Link node; s32 delta; Event_80024A5C evt; } EventListItem;
typedef struct { u8 pad0[8]; Link allocList; } EventQueue_80024A5C;
typedef struct { u8 pad0[0x24]; s32 uspt; u8 pad28[0x48 - 0x28]; EventQueue_80024A5C evtq; } SeqPlayer_80024A5C;
void func_80020E74(EventListItem *);
void func_80020E40(EventListItem *, EventListItem *);
typedef struct TTLinkQ_s { struct TTLinkQ_s *next; struct TTLinkQ_s *prev; } TTLinkQ;
typedef struct { TTLinkQ freeList; /* 0x00 */ TTLinkQ allocList; /* 0x08 */ } TTEvtqQ;
typedef struct { TTLinkQ node; /* 0x00 */ s32 unk8; /* 0x08: delta */ } TTItemQ;
typedef struct { u8 pad0[0x8]; f32 unk8; /* 0x08 */ } TTSrcD90;
typedef struct { u8 pad0[0x18]; TTSrcD90 *unk18; /* 0x18 */ u8 pad1C[8]; s32 unk24; /* 0x24 */ } TTSD90;
typedef struct { u8 pad0[0x18]; void *unk18; /* 0x18 */ u8 pad1C[8]; s32 unk24; /* 0x24 */ u8 pad28[4]; s32 unk2C; /* 0x2C */ u8 pad30[0x18]; u8 evtq48; /* 0x48 */ } TTSeqT;
extern s32 func_8002ABE0(void *, s32 *);

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
s32 func_8002241C(void *param_0);
void func_80022D1C(TTSeqD *p);
void func_80023008(u8 *arg0, u8 *arg1);
void func_80024A5C(SeqPlayer_80024A5C *param_0, Event_80024A5C *param_1);
void func_80024C9C(TTEvtqQ *evtq, TTItemQ *item);
void func_80024D90(TTSD90 *p, f32 s);
void func_80024DD8(TTSeqT *p);

void func_800221B0(TTChan *c, TTChanCfg *cfg)
{
    s32 i;
    void *p30;
    TTPoolElem *elem;
    TTPoolElem *base;
    void *arena;

    arena = cfg->unkC;
    c->unk20 = 0;
    c->unk18 = 0;
    c->unk14 = D_800411F4;
    func_80026100(c);
    c->unk24 = 0x1E8;
    c->unk28 = 0;
    c->unk2C = 0;
    c->unk34 = 0x7FFF;
    c->unk37 = cfg->unk9;
    c->unk5C = 0x3E80;
    c->unk1C = 0;
    c->unk70 = cfg->unk10;
    c->unk74 = cfg->unk14;
    c->unk78 = cfg->unk18;
    c->unk7C = 0.0f;
    c->unk80 = 1.0f;
    c->unk84 = 0;
    c->unk89 = 0;
    c->unk88 = cfg->unk0;
    c->unk38 = 9;
    c->unk36 = cfg->unk8;
    c->unk60 = func_80020EE4(0, 0, arena, cfg->unk8, 0x38);
    func_8002A0CC(c);
    base = func_80020EE4(0, 0, arena, cfg->unk0, 0x44);
    c->unk6C = 0;
    for (i = 0; i < cfg->unk0; i++) {
        elem = &base[i];
        elem->unk0 = c->unk6C;
        c->unk6C = elem;
    }
    c->unk64 = 0;
    c->unk68 = 0;
    p30 = func_80020EE4(0, 0, arena, cfg->unk4, 0x1C);
    func_800263C0(&c->unk48, p30, cfg->unk4);
    c->unk0 = 0;
    c->unk8 = func_8002241C;
    c->unk4 = c;
    func_80026860(c);
}

s32 func_8002241C(void *param_0)
{
    SeqPlayer_8002241C *local_0 = (SeqPlayer_8002241C *)param_0;
    Event_8002241C local_1;
    HardwareVoice *local_2;
    s32 local_3;
    VoiceState *local_4;
    void *local_5;
    f32 local_6;
    u8 local_7;

    do {
        switch (local_0->nextEvent.type) {
        case 0:
            func_80022D1C(local_0);
            break;
        case 9:
            local_1.type = 9;
            func_80026500(&local_0->evtq, &local_1, local_0->frameTime, 1);
            break;
        case 5:
            local_2 = local_0->nextEvent.msg.note.voice;
            func_80026FF0(local_2);
            func_80027090(local_2);
            local_4 = (VoiceState *)local_2->clientPrivate;
            if (local_4->flags) {
                func_8002A6A4(local_0, local_4);
            }
            func_80029670(local_0, local_2);
            break;
        case 6:
            local_2 = local_0->nextEvent.msg.vol.voice;
            local_4 = (VoiceState *)local_2->clientPrivate;
            if (local_4->envPhase == 0) {
                local_4->envPhase = 1;
            }
            local_3 = local_0->nextEvent.msg.vol.delta;
            local_4->envEndTime = local_0->curTime + local_3;
            local_4->envGain = local_0->nextEvent.msg.vol.vol;
            func_80026BE0(local_2, func_80029D54(local_4, local_0), local_3);
            break;
        case 22:
            local_4 = local_0->nextEvent.msg.osc.vs;
            local_5 = local_0->nextEvent.msg.osc.oscState;
            local_3 = (*local_0->updateOsc)(local_5, &local_6);
            local_4->tremelo = (u8)local_6;
            func_80026BE0(&local_4->voice, func_80029D54(local_4, local_0),
                         func_80029F5C(local_4, local_0->curTime));
            local_1.type = 22;
            local_1.msg.osc.vs = local_4;
            local_1.msg.osc.oscState = local_5;
            func_80026500(&local_0->evtq, &local_1, local_3, 0);
            break;
        case 23:
            local_4 = local_0->nextEvent.msg.osc.vs;
            local_5 = local_0->nextEvent.msg.osc.oscState;
            local_7 = local_0->nextEvent.msg.osc.chan;
            local_3 = (*local_0->updateOsc)(local_5, &local_6);
            local_4->vibrato = local_6;
            func_80026E90(&local_4->voice,
                local_4->pitch * local_4->vibrato * local_0->chanState[local_7].pitchBend);
            if (local_0->chanState[local_7].enabled11) {
                func_8002A7E0(&local_4->voice,
                    (440.0f * func_80028B74((local_0->chanState[local_7].tuning12 +
                    (local_4->key - local_4->sound->keyBase)) - 0x40) *
                    local_0->chanState[local_7].pitchBend) * local_4->vibrato);
            }
            local_1.type = 23;
            local_1.msg.osc.vs = local_4;
            local_1.msg.osc.oscState = local_5;
            local_1.msg.osc.chan = local_7;
            func_80026500(&local_0->evtq, &local_1, local_3, 0);
            break;
        case 2:
        case 21:
            func_80023008(local_0, &local_0->nextEvent);
            break;
        case 7:
            func_80024A5C(local_0, &local_0->nextEvent);
            break;
        case 10:
            local_0->vol = local_0->nextEvent.msg.spvol.vol;
            for (local_4 = local_0->vAllocHead; local_4 != 0; local_4 = local_4->next) {
                func_80026BE0(&local_4->voice, func_80029D54(local_4, local_0),
                             func_80029F5C(local_4, local_0->curTime));
            }
            break;
        case 24:
            local_0->unk7C = local_0->nextEvent.msg.evt18.unk0;
            local_0->unk80 = local_0->nextEvent.msg.evt18.unk4;
            for (local_4 = local_0->vAllocHead; local_4 != 0;) {
                if (local_4->envPhase != 3) {
                    func_80026F40(&local_4->voice, func_80029E64(local_4, local_0));
                }
                local_4 = local_4->next;
            }
            break;
        case 25:
            if (local_0->nextEvent.msg.evt19.unk1 < 8) {
                s32 local_8 = func_8002A940(local_0->nextEvent.msg.evt19.unk0);
                if (local_8) {
                    func_8002AA30(local_8,
                        (local_0->nextEvent.msg.evt19.unk2 << 3) |
                        (local_0->nextEvent.msg.evt19.unk1 & 7),
                        &local_0->nextEvent.msg.evt19.param);
                }
            } else {
                s32 local_9 = func_8002A9B8(local_0->nextEvent.msg.evt19.unk0);
                if (local_9) {
                    func_8002AA74(local_9, local_0->nextEvent.msg.evt19.unk1,
                                 &local_0->nextEvent.msg.evt19.param);
                }
            }
            break;
        case 15:
            if (local_0->state != 1) {
                local_0->state = 1;
                func_80024DD8(local_0);
            }
            break;
        case 16:
            if (local_0->state == 2) {
                for (local_4 = local_0->vAllocHead; local_4 != 0; local_4 = local_0->vAllocHead) {
                    func_80026FF0(&local_4->voice);
                    func_80027090(&local_4->voice);
                    if (local_4->flags) {
                        func_8002A6A4(local_0, local_4);
                    }
                    func_80029670(local_0, &local_4->voice);
                }
                local_0->state = 0;
            }
            break;
        case 17:
            if (local_0->state == 1) {
                func_800266B0(&local_0->evtq, 0);
                func_800266B0(&local_0->evtq, 21);
                func_800266B0(&local_0->evtq, 2);
                for (local_4 = local_0->vAllocHead; local_4 != 0; local_4 = local_4->next) {
                    if (func_800298E4(local_0, &local_4->voice, 0xC350)) {
                        func_8002976C(local_0, &local_4->voice, 0xC350);
                    }
                }
                for (local_7 = 0; local_7 < 32; local_7++) {
                    local_0->chanState[local_7].unk9 = local_0->chanState[local_7].unkA;
                    if (local_0->chanState[local_7].unk9 == 0) {
                        local_0->chanMask &= (1 << local_7) ^ -1;
                    } else {
                        local_0->chanMask |= 1 << local_7;
                    }
                }
                local_0->state = 2;
                local_1.type = 16;
                func_80026500(&local_0->evtq, &local_1, 0x7FFFFFFF, 0);
            }
            break;
        case 12:
            local_7 = local_0->nextEvent.msg.evt19.unk0;
            local_0->chanState[local_7].pad0[4] = local_0->nextEvent.msg.evt19.unk1;
            break;
        case 13:
            local_0->target = local_0->nextEvent.msg.spseq.seq;
            local_0->chanMask = -1;
            func_8002A024(local_0, local_0->bank);
            goto switch_join;
        case 14:
            goto switch_join;
        case 1:
        case 3:
        case 4:
            goto switch_join;
        }
switch_join:
        local_0->nextDelta = func_8002645C(&local_0->evtq, &local_0->nextEvent);
    } while (local_0->nextDelta == 0);

    local_0->curTime += local_0->nextDelta;
    return local_0->nextDelta;
}

void func_80022D1C(TTSeqD *p)
{
    TTEvtD evt;

    if (p->unk18 == 0)
        return;

    func_80025084(p->unk18, &evt, 1);

    switch (evt.type) {
    case 1:
        func_80023008(p, &evt);
        func_80024DD8(p);
        break;

    case 3:
        func_80024A5C(p, &evt);
        func_80024DD8(p);
        break;

    case 4:
        p->unk2C = 2;
        evt.type = 0x10;
        func_80026500(&p->evtq48, &evt, 0x7FFFFFFF, 0);
        break;

    case 0x12:
    case 0x13:
    case 0x14:
        func_80024DD8(p);
        break;

    default:
        break;
    }
}

void func_80022E20(TTSeqQ *p, u8 chan)
{
    TTVceQ *v;
    s16 vol;

    for (v = p->unk64; v != 0; v = v->unk0) {
        if (v->unk35 == chan && v->unk38 != 3) {
            vol = func_80029D54(v, p);
            func_80026BE0(&v->unk4, vol, func_80029F5C(v, p->unk1C));
        }
    }
}

void func_80022ECC(TTSeqK *p, u8 chan)
{
    TTVceK *it;
    s16 vel;
    s8 d;
    f32 base;

    d = p->unk60[chan].unk12 - 0x40;
    base = p->unk60[chan].unk14;

    for (it = p->unk64; it != 0; it = it->unk0) {
        if (it->unk35 == chan) {
            vel = p->unk60[chan].unk11;
            func_8002A890(&it->unk4, vel);

            if (vel != 0) {
                func_8002A7E0(&it->unk4,
                    func_80028B74(it->unk36 - it->unk20->unk14 + d) * 440.0f * base);
            }
        }
    }
}

void func_80023008(u8 *arg0, u8 *arg1)
{
  u8 *spDC;
  TVoice *spD8;
  s32 spD4;
  u8 spD3;
  u8 spD2;
  u8 spD1;
  u8 spD0;
  u8 spCF;
  TMidi *spC8;
  s16 spC6;
  SEvt evtB4;
  s32 spB0;
  TVoice *spAC;
  u8 spAB;
  TChan *spA4;
  s32 spA0;
  ALVoiceConfig sp98;
  TSound *sp94;
  s16 sp92;
  f32 sp8C;
  f32 sp88;
  u8 sp87;
  u8 sp86;
  f32 sp80;
  s32 sp7C;
  u8 *sp78;
  f32 sp74;
  f32 sp70;
  u8 sp6F;
  u8 sp6E;
  s32 sp68;
  s32 sp64;
  f32 sp60;
  f32 sp5C;
  s32 sp58;
  s32 sp54;
  f32 sp50;
  s32 sp4C;
  spC8 = (TMidi *) (arg1 + 4);
  spD4 = spC8->status & 0xF0;
  spD3 = spC8->type;
  spD0 = (spD2 = spC8->byte1);
  spCF = (spD1 = spC8->byte2);
  switch (spD4)
  {
    case 0x90:
      if (spD1 != 0)
    {
      sp7C = 0;
      if (((*((s32 *) (((s8 *) arg0) + 0x2C))) != 1) || (!((*((s32 *) (((s8 *) arg0) + 0x30))) & (1 << spD3))))
      {
        if (spC8->duration != 0)
        {
          evtB4.type = 0x15;
          evtB4.msg.b.b0 = 0x80;
          evtB4.msg.b.b1 = spD3;
          evtB4.msg.b.b2 = spD2;
          evtB4.msg.b.b3 = 0;
          spB0 = ((TSeqP *) arg0)->uspt * spC8->duration;
          D_8007EA50[spD3] = spB0;
          func_80026500(arg0 + 0x48, &evtB4, spB0, 0);
        }
        goto dummy_label_257363;
      }
        spA4 = (TChan *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38));
        sp94 = func_80029BA0(arg0, spD2, spD1, spD3);
        if (sp94 == 0)
        {
          return;
        }
        sp98.priority = (s16) (*((u8 *) (((s8 *) spA4) + 4)));
        sp98.fxBus = (s16) (*((u8 *) (((s8 *) spA4) + 7)));
        sp98.unityPitch = 0;
        spAC = func_80029A04(arg0, spD2, spD1, spD3, sp94);
        if (spAC == 0)
        {
          return;
        }
        spDC = spAC->voice;
        func_800268D0(spDC, &sp98);
        *((s16 *) (((s8 *) spAC) + 0x26)) = (s16) (*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x33)));
        *((s16 *) (((s8 *) spAC) + 0x24)) = (s16) (*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x34)));
        *((u8 **) (((s8 *) spAC) + 0x20)) = sp94;
        *((s8 *) (((s8 *) spAC) + 0x38)) = 0;
        if (((s32) (*((u8 *) (((s8 *) spA4) + 8)))) >= 0x40)
        {
          *((u8 *) (((s8 *) spAC) + 0x39)) = 2U;
        }
        else
        {
          *((u8 *) (((s8 *) spAC) + 0x39)) = 0U;
        }
        sp92 = (*((s8 *) (((s8 *) sp94) + 0x15))) + ((spD2 - (*((u8 *) (((s8 *) sp94) + 0x14)))) * 0x64);
        if (spA4->custom24 != 0)
        {
          sp92 += spA4->detune;
        }
        *((f32 *) (((s8 *) spAC) + 0x2C)) = func_80027170(sp92);
        if (spA4->custom24 != 0)
        {
          *((u8 *) (((s8 *) spAC) + 0x34)) = spA4->attackVolume;
          *((s32 *) (((s8 *) spAC) + 0x28)) = ((TSeqP *) arg0)->curTime + spA4->attackTime;
        }
        else
        {
          *((u8 *) (((s8 *) spAC) + 0x34)) = sp94->attackVolume;
          *((s32 *) (((s8 *) spAC) + 0x28)) = ((TSeqP *) arg0)->curTime + sp94->attackTime;
        }
        *((u8 *) (((s8 *) spAC) + 0x3B)) = 0U;
        if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
        {
          spA0 = (s32) (*((u8 *) (((s8 *) spA4) + 0x28)));
        }
        else
        {
          sp78 = func_800E93AC(*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x33)));
          spA0 = (s32) (*((u8 *) (((s8 *) sp78) + 4)));
        }
        sp88 = 127.0f;
        if ((spA0 != 0) && ((*((s32 (**)(s32 *, f32 *, u8, u8, s32, s32, s32)) (((s8 *) arg0) + 0x70))) != 0))
        {
          if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
          {
            spB0 = (*((s32 (**)(s32 *, f32 *, u8, u8, s32, s32, s32)) (((s8 *) arg0) + 0x70)))(&sp7C, &sp88, *((u8 *) (((s8 *) spA4) + 0x28)), *((u8 *) (((s8 *) spA4) + 0x29)), (s32) (*((u8 *) (((s8 *) spA4) + 0x2A))), (s32) (*((u8 *) (((s8 *) spA4) + 0x2B))), (s32) (*((u8 *) (((s8 *) spA4) + 0x31))));
          }
          else
          {
            spB0 = (*((s32 (**)(s32 *, f32 *, u8, u8, s32, s32, s32)) (((s8 *) arg0) + 0x70)))(&sp7C, &sp88, *((u8 *) (((s8 *) sp78) + 4)), *((u8 *) (((s8 *) sp78) + 5)), (s32) (*((u8 *) (((s8 *) sp78) + 6))), (s32) (*((u8 *) (((s8 *) sp78) + 7))), (s32) (*((u8 *) (((s8 *) spA4) + 0x31))));
          }
          if (spB0 != 0)
          {
            evtB4.type = 0x16;
            evtB4.unk4 = spAC;
            evtB4.msg.w = sp7C;
            func_80026500(arg0 + 0x48, &evtB4, spB0, 0);
            *((u8 *) (((s8 *) spAC) + 0x3B)) = (u8) ((*((u8 *) (((s8 *) spAC) + 0x3B))) | 1);
            *((s32 *) (((s8 *) spAC) + 0x3C)) = sp7C;
          }
        }
        *((s8 *) (((s8 *) spAC) + 0x3A)) = (s8) ((u32) sp88);
        sp88 = 1.0f;
        if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
        {
          spA0 = (s32) (*((u8 *) (((s8 *) spA4) + 0x2C)));
        }
        else
        {
          spA0 = (s32) (*((u8 *) (((s8 *) sp78) + 8)));
        }
        if ((spA0 != 0) && ((*((s32 (**)(s32 *, f32 *, u8, u8, s32, s32, s32)) (((s8 *) arg0) + 0x70))) != 0))
        {
          if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
          {
            spB0 = (*((s32 (**)(s32 *, f32 *, u8, u8, s32, s32, s32)) (((s8 *) arg0) + 0x70)))(&sp7C, &sp88, *((u8 *) (((s8 *) spA4) + 0x2C)), *((u8 *) (((s8 *) spA4) + 0x2D)), (s32) (*((u8 *) (((s8 *) spA4) + 0x2E))), (s32) (*((u8 *) (((s8 *) spA4) + 0x2F))), (s32) (*((u8 *) (((s8 *) spA4) + 0x31))));
          }
          else
          {
            spB0 = (*((s32 (**)(s32 *, f32 *, u8, u8, s32, s32, s32)) (((s8 *) arg0) + 0x70)))(&sp7C, &sp88, *((u8 *) (((s8 *) sp78) + 8)), *((u8 *) (((s8 *) sp78) + 9)), (s32) (*((u8 *) (((s8 *) sp78) + 0xA))), (s32) (*((u8 *) (((s8 *) sp78) + 0xB))), (s32) (*((u8 *) (((s8 *) spA4) + 0x31))));
          }
          if (spB0 != 0)
          {
            evtB4.type = 0x17;
            evtB4.unk4 = spAC;
            evtB4.msg.w = sp7C;
            evtB4.chan = spD3;
            func_80026500(arg0 + 0x48, &evtB4, spB0, 0);
            *((u8 *) (((s8 *) spAC) + 0x3B)) = (u8) ((*((u8 *) (((s8 *) spAC) + 0x3B))) | 2);
            *((s32 *) (((s8 *) spAC) + 0x40)) = sp7C;
          }
        }
        *((f32 *) (((s8 *) spAC) + 0x30)) = sp88;
        sp8C = spAC->pitch * spA4->pitchBend * spAC->vibrato;
        sp87 = func_80029E64(spAC, arg0);
        sp86 = *((u8 *) (((s8 *) spA4) + 0x11));
        if (sp86 != 0)
        {
          sp80 = 440 * func_80028B74((sp92 / 100) + spA4->tuning12 - 0x40) * spA4->pitchBend;
        }
        else
        {
          sp80 = 127.0f;
        }
        spAB = func_80029FA0(spAC, arg0);
        spC6 = func_80029D54(spAC, arg0);
        if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
        {
          spB0 = *((s32 *) (((s8 *) spA4) + 0x18));
        }
        else
        {
          spB0 = *((s32 *) (((s8 *) sp94) + 0));
        }
        func_80026CB0(spDC, sp94->wavetable, sp8C, spC6, ((s32) spAB) ^ 0, (s32) sp87, (s32) sp86, sp80, (s32) (*((u8 *) (((s8 *) spA4) + 0x13))), spB0);
        evtB4.type = 6;
        evtB4.unk4 = spDC;
        if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
        {
          evtB4.chan = *((u8 *) (((s8 *) spA4) + 0x26));
          evtB4.msg.w = *((s32 *) (((s8 *) spA4) + 0x1C));
        }
        else
        {
          evtB4.chan = *((u8 *) (((s8 *) sp94) + 0xD));
          evtB4.msg.w = *((s32 *) (((s8 *) sp94) + 4));
        }
        func_80026500(arg0 + 0x48, &evtB4, spB0, 0);
        if (spC8->duration != 0)
        {
          evtB4.type = 0x15;
          evtB4.msg.b.b0 = 0x80;
          evtB4.msg.b.b1 = spD3;
          evtB4.msg.b.b2 = spD2;
          evtB4.msg.b.b3 = 0;
          spB0 = ((TSeqP *) arg0)->uspt * spC8->duration;
          D_8007EA50[spD3] = spB0;
          func_80026500(arg0 + 0x48, &evtB4, spB0, 0);
        }
        if ((spA4->flags10 & 1) && (((TSeqP *) arg0)->queue != 0))
        {
          osSendMesg(((TSeqP *) arg0)->queue, (D_8007EA50[spD3] & ~0xFF) | (spA4->flags10 >> 2), 0);
        }
        goto dummy_label_257363;
    }

    case 0x80:
      spAC = func_80029B18(arg0, spD2, spD3);

      if (spAC == 0)
      {
        return;
      }
      spA4 = (TChan *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38));
      if ((*((u8 *) (((s8 *) spAC) + 0x39))) == 2)
      {
        *((u8 *) (((s8 *) spAC) + 0x39)) = 4U;
      }
      else
      {
        *((u8 *) (((s8 *) spAC) + 0x39)) = 3U;
        if (spA4->custom24 != 0)
        {
          func_8002976C(arg0, spAC->voice, spA4->releaseTime);
        }
        else
        {
          func_8002976C(arg0, spAC->voice, *((s32 *) (((s8 *) (*((u8 **) (((s8 *) spAC) + 0x20)))) + 8)));
        }
      }
      if ((spA4->flags10 & 2) && (((TSeqP *) arg0)->queue != 0))
      {
        osSendMesg(((TSeqP *) arg0)->queue, ((spD2 << 0x10) | 8) | (spA4->flags10 >> 2), 0);
      }
      goto dummy_label_257363;

    case 0xA0:
      spAC = func_80029B18(arg0, spD2, spD3);
      if (spAC == 0)
    {
      return;
    }
      *((u8 *) (((s8 *) spAC) + 0x37)) = spCF;
      func_80026BE0(spAC->voice, func_80029D54(spAC, arg0), func_80029F5C(spAC, *((s32 *) (((s8 *) arg0) + 0x1C))));
      goto dummy_label_257363;

    case 0xD0:
      for (spD8 = *((TVoice **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = spD8->next)
    {
      if (spD8->channel == spD3)
      {
        spD8->velocity = spD0;
        func_80026BE0(spD8->voice, func_80029D54(spD8, arg0), func_80029F5C(spD8, *((s32 *) (((s8 *) arg0) + 0x1C))));
      }
    }

      goto dummy_label_257363;

    case 0xB0:
      switch ((s32) spD0)
    {
      case 0xA:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 3)) = spCF;
        for (spD8 = *((u8 **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = *((u8 **) (((s8 *) spD8) + 0)))
      {
        if ((*((u8 *) (((s8 *) spD8) + 0x35))) == spD3)
        {
          spAB = func_80029FA0(spD8, arg0);
          func_80026DE0(spD8->voice, spAB);
        }
      }

        break;

      case 0xFD:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xB)) = spCF;
        break;

      case 0xFF:
        if ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xB))) == 0)
      {
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xB)) = 0x88;
      }
        if ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xA))) != spCF)
      {
        sp74 = (f32) (spCF - (*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 9))));
        sp70 = sp74 / ((f32) ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xB))) & 0x7F));
        if (sp70 < 0.0f)
        {
          sp70 = -sp70;
        }
        *((f32 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xC)) = sp70;
        if ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xA))) == (*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 9))))
        {
          *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xA)) = spCF;
        }
        else
        {
          *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xA)) = spCF;
          break;
        }
      }
      else
      {
        break;
      }
        spC8->byte1 = 0xFEU;

      case 0xFE:
        sp6F = *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 9));
        sp6E = *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xA));
        sp60 = *((f32 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xC));
        spD1 = *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xB));
        sp68 = sp6E - sp6F;
        if (sp68 > 0)
      {
        if ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xB))) & 0x80)
        {
          sp60 *= 2.0f;
        }
        sp64 = (s32) sp60;
        if (sp64 == 0)
        {
          sp64 = 1;
          sp5C = 1.0f / sp60;
        }
        else
        {
          sp5C = ((f32) sp64) / sp60;
        }
        if (sp68 > sp64)
        {
          sp68 = sp64;
        }
      }
      else
      {
        sp64 = (s32) sp60;
        if (sp64 == 0)
        {
          sp64 = 1;
          sp5C = sp60;
        }
        else
        {
          sp5C = ((f32) sp64) / sp60;
        }
        sp64 = -sp64;
        if (sp68 < sp64)
        {
          sp68 = sp64;
        }
      }
        sp6F += sp68;
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 9)) = sp6F;
        if (sp6F != sp6E)
      {
        func_80026500(arg0 + 0x48, arg1, (s32) (((f32) (((TSeqP *) arg0)->uspt * 0x64)) * sp5C), 0);
      }
      if (sp6F != 0)
      {
        ((TSeqP *) arg0)->chanMask |= 1 << spD3;
      }
      else
      {
        ((TSeqP *) arg0)->chanMask &= ~(1 << spD3);
      }
        func_80022E20(arg0, spD3);
        break;

      case 0xFC:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 9)) = spCF;
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0xA)) = spCF;
      if (spCF == 0)
      {
        ((TSeqP *) arg0)->chanMask &= (1 << spD3) ^ -1;
      }
      else
      {
        ((TSeqP *) arg0)->chanMask |= 1 << spD3;
      }
        func_80022E20(arg0, spD3);
        break;

      case 0x21:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x11)) = spCF;
        func_80022ECC(arg0, spD3);
        break;

      case 0x22:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x12)) = spCF;
        func_80022ECC(arg0, spD3);
        break;

      case 0x23:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x13)) = spCF;
        for (spD8 = *((u8 **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = *((u8 **) (((s8 *) spD8) + 0)))
      {
        if ((*((u8 *) (((s8 *) spD8) + 0x35))) == spD3)
        {
          func_8002AB30(spD8->voice, spCF);
        }
      }

        break;

      case 0x1E:
        if (((TSeqP *) arg0)->queue != 0)
      {
        osSendMesg(((TSeqP *) arg0)->queue, ((spCF & 7) | 0x10) | ((((TSeqP *) arg0)->samplesLeft << 5) & ~0xFF), 0);
      }
        break;

      case 0x7:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 5)) = spCF;
        for (spD8 = *((u8 **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = *((u8 **) (((s8 *) spD8) + 0)))
      {
        if (((*((u8 *) (((s8 *) spD8) + 0x35))) == spD3) && ((*((u8 *) (((s8 *) spD8) + 0x38))) != 3))
        {
          spC6 = func_80029D54(spD8, arg0);
          func_80026BE0(spD8->voice, spC6, func_80029F5C(spD8, *((s32 *) (((s8 *) arg0) + 0x1C))));
        }
      }

        break;

      case 0x10:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 4)) = spCF;
        break;

      case 0x40:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 8)) = spCF;
        for (spD8 = *((u8 **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = *((u8 **) (((s8 *) spD8) + 0)))
      {
        if (((*((u8 *) (((s8 *) spD8) + 0x35))) == spD3) && ((*((u8 *) (((s8 *) spD8) + 0x39))) != 3))
        {
          if (((s32) spCF) >= 0x40)
          {
            if ((*((u8 *) (((s8 *) spD8) + 0x39))) == 0)
            {
              *((u8 *) (((s8 *) spD8) + 0x39)) = 2U;
            }
          }
          else
            if ((*((u8 *) (((s8 *) spD8) + 0x39))) == 2)
          {
            *((u8 *) (((s8 *) spD8) + 0x39)) = 0U;
          }
          else
            if ((*((u8 *) (((s8 *) spD8) + 0x39))) == 4)
          {
            *((u8 *) (((s8 *) spD8) + 0x39)) = 3U;
            if ((*((u8 *) (((s8 *) spA4) + 0x24))) != 0)
            {
              func_8002976C(arg0, spD8->voice, (0x3E80 > (*((s32 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x20)))) ? (0x3E80) : (*((s32 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x20))));
            }
            else
            {
              func_8002976C(arg0, spD8->voice, (0x3E80 > (*((s32 *) (((s8 *) (*((u8 **) (((s8 *) spAC) + 0x20)))) + 8)))) ? (0x3E80) : (*((s32 *) (((s8 *) (*((u8 **) (((s8 *) spAC) + 0x20)))) + 8))));
            }
          }
        }
      }

        break;

      case 0x5B:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 6)) = (u8) (((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 6))) & 0x80) | spCF);
        spCF = (u8) (((s32) (*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 6)))) >> 7);

      case 0x41:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 6)) = (u8) (((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 6))) & 0x7F) | (spCF << 7));
        for (spD8 = *((u8 **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = *((u8 **) (((s8 *) spD8) + 0)))
      {
        if (((*((u8 *) (((s8 *) spD8) + 0x35))) == spD3) && ((*((u8 *) (((s8 *) spD8) + 0x38))) != 3))
        {
          func_80026F40(spD8->voice, *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 6)));
        }
      }

        break;

      case 0x5C:
        if (((s32) spCF) < (*((s32 *) (((s8 *) ((u8 *) D_800411F4)) + 0x3C))))
      {
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 7)) = spCF;
      }
        break;

      case 0x1A:
        break;

      case 0x20:
        *((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x32)) = spCF;
        break;

      case 0x29:
        sp58 = (s32) (((f32) (*((s32 *) (((s8 *) arg0) + 0x24)))) / (*((f32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x18)))) + 8))));
        sp58 = 0x03938700 / sp58;
        sp58 = (sp58 + (spCF & 0xFFFFFFFFu)) - 0x40;
        func_80024D90(arg0, (f32) (0x03938700 / sp58));
        break;

      default:
        break;

    }

      goto dummy_label_257363;

    case 0xC0:
      spA0 = ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x32))) << 7) + spD2;
    if (spA0 < func_800E9048())
    {
      func_8002A318(arg0, spA0, spD3);
    }
    else
    {
    }
      goto dummy_label_257363;

    case 0xE0:
      sp54 = ((spCF << 7) + spD0) - 0x2000;
      sp4C = ((s32) ((*((s16 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0))) * sp54)) / 8192;
      sp50 = func_80027170(sp4C);
      *((f32 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x60))) + (spD3 * 0x38))) + 0x14)) = sp50;
      for (spD8 = *((TVoice **) (((s8 *) arg0) + 0x64)); spD8 != 0; spD8 = spD8->next)
    {
      if (spD8->channel == spD3)
      {
        func_80026E90(spD8->voice, spD8->pitch * sp50 * spD8->vibrato);
        if (((TChan *) (*((s32 *) (((s8 *) arg0) + 0x60))))[spD3].enabled11 != 0)
        {
          func_8002A7E0(spD8->voice, 440 * func_80028B74((spD8->key - spD8->sound->keyBase) + ((TChan *) (*((s32 *) (((s8 *) arg0) + 0x60))))[spD3].tuning12 - 0x40) * sp50 * spD8->vibrato);
        }
      }
    }

      goto dummy_label_257363;

    default:
      break;
	  

  }

  dummy_label_257363:
  ;
}

void func_80024A5C(SeqPlayer_80024A5C *param_0, Event_80024A5C *param_1)
{
    TempoEvent *local_0 = &param_1->tempo;
    s32 local_1;
    s32 local_2;
    u32 local_3;
    s32 local_4;
    s32 local_5 = 0;
    EventListItem *local_6;
    EventListItem *local_7;
    EventListItem *local_8 = 0;

    if (param_1->tempo.status == 0xFF) {
        if (param_1->tempo.type == 0x51) {
            local_2 = param_0->uspt;
            local_1 = (local_0->byte1 << 16) | (local_0->byte2 << 8) | local_0->byte3;
            func_80024D90(param_0, (f32)local_1);

            local_6 = (EventListItem *)param_0->evtq.allocList.next;
            while (local_6) {
                local_5 += local_6->delta;
                local_7 = (EventListItem *)local_6->node.next;
                if (local_6->evt.type == 0x15) {
                    func_80020E74(local_6);
                    if (local_8) {
                        func_80020E40(local_6, local_8);
                    } else {
                        local_6->node.next = 0;
                        local_6->node.prev = 0;
                        local_8 = local_6;
                    }
                    local_4 = local_5;
                    if (local_7) {
                        local_5 -= local_6->delta;
                        local_7->delta += local_6->delta;
                    }
                    local_6->delta = local_4;
                }
                local_6 = local_7;
            }

            local_6 = local_8;
            while (local_6) {
                local_7 = (EventListItem *)local_6->node.next;
                local_3 = local_6->delta / local_2;
                local_6->delta = local_3 * param_0->uspt;
                func_80024C9C(&param_0->evtq, local_6);
                local_6 = local_7;
            }
        }
    }
}

void func_80024C9C(TTEvtqQ *evtq, TTItemQ *item)
{
    s32 msk;
    TTLinkQ *node;
    TTItemQ *nextItem;

    msk = osSetIntMask(1);

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            func_80020E40(item, node);
            break;
        } else {
            nextItem = (TTItemQ *)node->next;

            if (item->unk8 < nextItem->unk8) {
                nextItem->unk8 = nextItem->unk8 - item->unk8;
                func_80020E40(item, node);
                break;
            }

            item->unk8 = item->unk8 - nextItem->unk8;
        }
    }

    osSetIntMask(msk);
}

void func_80024D90(TTSD90 *p, f32 s)
{
    if (p->unk18)
        p->unk24 = (s32)((f32)s * p->unk18->unk8);
    else
        p->unk24 = 0x1E8;
}

void func_80024DD8(TTSeqT *p)
{
    TTEvtD evt;
    s32 delta;

    if (p->unk2C != 1 || p->unk18 == 0)
        return;

    if (func_8002ABE0(p->unk18, &delta) == 0)
        return;

    evt.type = 0;
    func_80026500(&p->evtq48, &evt, p->unk24 * delta, 0);
}

void func_80024E70(u8 *param_0, u8 param_1) {
    M2C_FIELD(param_0, u8 *, 0x88) = param_1;
}
