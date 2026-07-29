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

typedef struct { u32 division; /* 0x0 */ u32 nTracks; /* 0x4 */ u32 trackOffset[32]; /* 0x8 */ } TTCMidiHdr_80024EE0;
typedef struct { TTCMidiHdr_80024EE0 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 deltaFlag; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80024EE0;
typedef struct { u32 unk0; u32 nTracks; } TTCMidiHdr_80025084;
typedef struct { TTCMidiHdr_80025084 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 deltaFlag; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80025084;
typedef struct { s16 type; /* 0x0 (lh im Target) */ struct { s32 ticks; /* 0x4 */ u8 status; /* 0x8 */ u8 byte1; /* 0x9 */ u8 byte2; /* 0xA */ s32 duration; /* 0xC */ } msg; } TTEvent_80025084;
typedef struct { u32 division; u32 nTracks; u32 trackOffset[32]; } TTCMidiHdr_80025224;
typedef struct { TTCMidiHdr_80025224 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 deltaFlag; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80025224;
typedef struct { s16 type; /* 0x0 */ union { struct { s32 ticks; /* 0x4 */ u8 status; /* 0x8 */ u8 chan; /* 0x9 (Tooie: Track-Nummer) */ u8 byte1; /* 0xA */ u8 byte2; /* 0xB */ s32 duration; /* 0xC */ } midi; struct { s32 ticks; /* 0x4 */ u8 status; /* 0x8 */ u8 type; /* 0x9 */ u8 unkA; /* 0xA */ u8 byte1; /* 0xB */ u8 byte2; /* 0xC */ u8 byte3; /* 0xD */ } tempo; } msg; } TTEvent_80025224;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
typedef struct { u32 unk0; u32 nTracks; /* 0x4: loop bound, reloaded via seq->base */ } TTCMidiHdr_80025680;
typedef struct { TTCMidiHdr_80025680 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 unk14; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80025680;
typedef struct { u32 validTracks; /* 0x00 */ u32 lastTicks; /* 0x04 */ u32 lastDeltaTicks; /* 0x08 */ u8 *curLoc[32]; /* 0x0C */ u8 *curBUPtr[32]; /* 0x8C */ u8 curBULen[32]; /* 0x10C */ u8 lastStatus[32]; /* 0x12C */ u32 evtDeltaTicks[32]; /* 0x14C */ } TTCSeqMarker;
typedef struct { u32 unk0; u32 nTracks; } TTCMidiHdr_80025750;
typedef struct { TTCMidiHdr_80025750 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 unk14; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80025750;
typedef struct { u32 division; u32 nTracks; u32 trackOffset[32]; } TTCMidiHdr_80025820;
typedef struct { TTCMidiHdr_80025820 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 deltaFlag; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80025820;
typedef struct { s16 type; union { struct { s32 ticks; u8 status; u8 chan; u8 byte1; u8 byte2; s32 duration; } midi; } msg; } TTEvent_80025820;
typedef struct { u32 division; u32 nTracks; u32 trackOffset[32]; } TTCMidiHdr_8002597C;
typedef struct { TTCMidiHdr_8002597C *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 deltaFlag; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_8002597C;
typedef struct { s16 type; union { struct { s32 ticks; u8 status; u8 chan; u8 byte1; u8 byte2; s32 duration; } midi; } msg; } TTEvent_8002597C;
typedef struct { u32 unk0; u32 nTracks; } TTCMidiHdr_80025BF0;
typedef struct { TTCMidiHdr_80025BF0 *base; /* 0x00 */ u32 validTracks; /* 0x04 */ f32 qnpt; /* 0x08 */ u32 lastTicks; /* 0x0C */ u32 lastDeltaTicks; /* 0x10 */ s32 unk14; /* 0x14 */ u8 *curLoc[32]; /* 0x18 */ u8 *curBUPtr[32]; /* 0x98 */ u8 curBULen[32]; /* 0x118 */ u8 lastStatus[32]; /* 0x138 */ u32 evtDeltaTicks[32]; /* 0x158 */ } TTCSeq_80025BF0;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
u32 func_80025224(TTCSeq_80025224 *seq, u32 track, TTEvent_80025224 *event, s32 loopsOn);
u8 func_80025BF0(TTCSeq_80025BF0 *seq, u32 track);
u32 func_80025DE4(void *seq, u32 track);

void func_80024EE0(TTCSeq_80024EE0 *seq, u8 *ptr)
{
    u32 i, tmpOff, flagTmp;

    seq->base = (TTCMidiHdr_80024EE0 *)ptr;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    seq->deltaFlag = 1;

    for (i = 0; i < seq->base->nTracks; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = 0;
        seq->curBULen[i] = 0;
        tmpOff = seq->base->trackOffset[i];
        if (tmpOff) {
            flagTmp = 1 << i;
            seq->validTracks |= flagTmp;
            seq->curLoc[i] = (u8 *)((u32)ptr + tmpOff);
            seq->evtDeltaTicks[i] = func_80025DE4(seq, i);
        }
        else
            seq->curLoc[i] = 0;
    }

    seq->qnpt = 1.0f / (f32)seq->base->division;
}

void func_80025084(TTCSeq_80025084 *seq, TTEvent_80025084 *evt, s32 loopsOn)
{
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 firstTrack;
    u32 lastTicks = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag)
                seq->evtDeltaTicks[i] -= lastTicks;
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
                firstTrack = i;
            }
        }
    }

    func_80025224(seq, firstTrack, evt, loopsOn);

    evt->msg.ticks = firstTime;
    seq->lastTicks += firstTime;
    seq->lastDeltaTicks = firstTime;
    if (evt->type != 0x12)
        seq->evtDeltaTicks[firstTrack] += func_80025DE4(seq, firstTrack);
    seq->deltaFlag = 1;
}

u32 func_80025224(TTCSeq_80025224 *seq, u32 track, TTEvent_80025224 *event, s32 loopsOn)
{
    u32 offset;
    u8 status, loopCt, curLpCt, *tmpPtr;

    status = func_80025BF0(seq, track);

    if (status == 0xFF)   /* AL_MIDI_Meta */
    {
        u8 type = func_80025BF0(seq, track);

        if (type == 0x51)   /* AL_MIDI_META_TEMPO */
        {
            event->type = 3;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.byte1 = func_80025BF0(seq, track);
            event->msg.tempo.byte2 = func_80025BF0(seq, track);
            event->msg.tempo.byte3 = func_80025BF0(seq, track);
            seq->lastStatus[track] = 0;
        }
        else if (type == 0x2F)   /* AL_MIDI_META_EOT */
        {
            u32 flagMask;

            flagMask = 0x01 << track;
            seq->validTracks = seq->validTracks ^ flagMask;

            if (seq->validTracks)
                event->type = 0x12;   /* AL_TRACK_END */
            else
                event->type = 4;      /* AL_SEQ_END_EVT */
        }
        else if (type == 0x2E)   /* AL_CMIDI_LOOPSTART_CODE */
        {
            status = func_80025BF0(seq, track);
            event->msg.midi.duration = status << 8;
            status = func_80025BF0(seq, track);
            event->msg.midi.duration += status;
            seq->lastStatus[track] = 0;
            event->type = 0x13;   /* AL_CSP_LOOPSTART */
        }
        else if (type == 0x2D)   /* AL_CMIDI_LOOPEND_CODE */
        {
            tmpPtr = seq->curLoc[track];
            loopCt = *tmpPtr++;
            curLpCt = *tmpPtr;
            if (curLpCt == 0 || loopsOn == 0)
            {
                *tmpPtr = loopCt;
                seq->curLoc[track] = tmpPtr + 5;
            }
            else
            {
                if (curLpCt != 0xFF)
                    *tmpPtr = curLpCt - 1;
                tmpPtr++;
                offset = (*tmpPtr++) << 24;
                offset += (*tmpPtr++) << 16;
                offset += (*tmpPtr++) << 8;
                offset += *tmpPtr++;
                seq->curLoc[track] = tmpPtr - offset;
            }
            seq->lastStatus[track] = 0;
            event->type = 0x14;   /* AL_CSP_LOOPEND */
        }
    }
    else
    {
        event->type = 1;   /* AL_SEQ_MIDI_EVT */
        if (status & 0x80)
        {
            event->msg.midi.status = status & 0xF0;
            event->msg.midi.chan = track;
            event->msg.midi.byte1 = func_80025BF0(seq, track);
            seq->lastStatus[track] = event->msg.midi.status;
        }
        else
        {
            event->msg.midi.status = seq->lastStatus[track];
            event->msg.midi.byte1 = status;
            event->msg.midi.chan = track;
        }

        if (((event->msg.midi.status & 0xF0) != 0xC0) &&
            ((event->msg.midi.status & 0xF0) != 0xD0))
        {
            event->msg.midi.byte2 = func_80025BF0(seq, track);
            if ((event->msg.midi.status & 0xF0) == 0x90)
            {
                event->msg.midi.duration = func_80025DE4(seq, track);
            }
        }
        else
            event->msg.midi.byte2 = 0;
    }
    return 1;
}

s32 func_80025668(u8 *param_0) {
    return M2C_FIELD(param_0, s32 *, 0xC);
}

void func_80025680(TTCSeq_80025680 *seq, TTCSeqMarker *m)
{
    u32 i;

    seq->validTracks    = m->validTracks;
    seq->lastTicks      = m->lastTicks;
    seq->lastDeltaTicks = m->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        seq->curLoc[i]        = m->curLoc[i];
        seq->curBUPtr[i]      = m->curBUPtr[i];
        seq->curBULen[i]      = m->curBULen[i];
        seq->lastStatus[i]    = m->lastStatus[i];
        seq->evtDeltaTicks[i] = m->evtDeltaTicks[i];
    }
}

void func_80025750(TTCSeq_80025750 *seq, TTCSeqMarker *m)
{
    u32 i;

    m->validTracks    = seq->validTracks;
    m->lastTicks      = seq->lastTicks;
    m->lastDeltaTicks = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        m->curLoc[i]        = seq->curLoc[i];
        m->curBUPtr[i]      = seq->curBUPtr[i];
        m->curBULen[i]      = seq->curBULen[i];
        m->lastStatus[i]    = seq->lastStatus[i];
        m->evtDeltaTicks[i] = seq->evtDeltaTicks[i];
    }
}

void func_80025820(TTCSeq_80025820 *seq, TTCSeqMarker *m, u32 ticks)
{
    TTEvent_80025820 evt;
    TTCSeq_80025820 tempSeq;
    s32 i;

    func_80024EE0(&tempSeq, (u8 *)seq->base);

    do {
        m->validTracks    = tempSeq.validTracks;
        m->lastTicks      = tempSeq.lastTicks;
        m->lastDeltaTicks = tempSeq.lastDeltaTicks;

        for (i = 0; i < seq->base->nTracks; i++)
        {
            m->curLoc[i]        = tempSeq.curLoc[i];
            m->curBUPtr[i]      = tempSeq.curBUPtr[i];
            m->curBULen[i]      = tempSeq.curBULen[i];
            m->lastStatus[i]    = tempSeq.lastStatus[i];
            m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }

        func_80025084(&tempSeq, &evt, 0);

        if (evt.type == 4)   /* AL_SEQ_END_EVT */
            break;

    } while (tempSeq.lastTicks < ticks);
}

void func_8002597C(TTCSeq_8002597C *seq, TTCSeqMarker *markers, u32 count, u32 start)
{
    TTEvent_8002597C evt;
    TTCSeq_8002597C tempSeq;
    u32 i;
    s32 remaining;
    TTCSeqMarker m;

    func_80024EE0(&tempSeq, (u8 *)seq->base);

    for (remaining = 0; remaining < count; remaining++)
        markers[remaining].lastTicks = 0;

    do {
        m.validTracks    = tempSeq.validTracks;
        m.lastTicks      = tempSeq.lastTicks;
        m.lastDeltaTicks = tempSeq.lastDeltaTicks;

        for (i = 0; i < seq->base->nTracks; i++)
        {
            m.curLoc[i]        = tempSeq.curLoc[i];
            m.curBUPtr[i]      = tempSeq.curBUPtr[i];
            m.curBULen[i]      = tempSeq.curBULen[i];
            m.lastStatus[i]    = tempSeq.lastStatus[i];
            m.evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }

        func_80025084(&tempSeq, &evt, 0);

        if (evt.type == 0x13)   /* AL_CSP_LOOPSTART */
        {
            if (((evt.msg.midi.duration >> 8) >= start) &&
                ((evt.msg.midi.duration >> 8) < start + count))
            {
                if (markers[(evt.msg.midi.duration >> 8) - start].lastTicks == 0)
                {
                    markers[(evt.msg.midi.duration >> 8) - start] = m;
                    if (--remaining <= 0)
                        return;
                }
            }
        }
    } while (evt.type != 4);   /* AL_SEQ_END_EVT */
}

u8 func_80025BF0(TTCSeq_80025BF0 *seq, u32 track)
{
    u8 theByte;

    if (seq->curBULen[track]) {
        theByte = *seq->curBUPtr[track];
        seq->curBUPtr[track]++;
        seq->curBULen[track]--;
    } else {
        theByte = *seq->curLoc[track];
        seq->curLoc[track]++;
        if (theByte == 0xFE) {
            u8 loBackUp, hiBackUp, theLen, nextByte;
            u32 backup;

            nextByte = *seq->curLoc[track];
            seq->curLoc[track]++;
            if (nextByte != 0xFE) {
                hiBackUp = nextByte;
                loBackUp = *seq->curLoc[track];
                seq->curLoc[track]++;
                theLen = *seq->curLoc[track];
                seq->curLoc[track]++;
                backup = (u32)hiBackUp;
                backup = backup << 8;
                backup += loBackUp;
                seq->curBUPtr[track] = seq->curLoc[track] - (backup + 4);
                seq->curBULen[track] = (u32)theLen;

                theByte = *seq->curBUPtr[track];
                seq->curBUPtr[track]++;
                seq->curBULen[track]--;
            }
        }
    }

    return theByte;
}

u32 func_80025DE4(void *seq, u32 track)
{
    u32 value;
    u32 c;

    value = (u32)func_80025BF0(seq, track);
    if (value & 0x00000080) {
        value &= 0x7f;
        do {
            c = (u32)func_80025BF0(seq, track);
            value = (value << 7) + (c & 0x7f);
        } while (c & 0x80);
    }
    return value;
}
