#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

typedef struct {
    u32 division;
    u32 nTracks;
    u32 trackOffset[32];
} TTCMidiHdr_80024EE0;
typedef struct {
    TTCMidiHdr_80024EE0 *base;
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
} TTCSeq_80024EE0;
typedef struct {
    u32 unk0;
    u32 nTracks;
} TTCMidiHdr_80025084;
typedef struct {
    TTCMidiHdr_80025084 *base;
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
} TTCSeq_80025084;
typedef struct {
    s16 type;
    struct {
        s32 ticks;
        u8 status;
        u8 byte1;
        u8 byte2;
        s32 duration;
    } msg;
} TTEvent_80025084;
typedef struct {
    u32 division;
    u32 nTracks;
    u32 trackOffset[32];
} TTCMidiHdr_80025224;
typedef struct {
    TTCMidiHdr_80025224 *base;
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
} TTCSeq_80025224;
typedef struct {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 chan;
            u8 byte1;
            u8 byte2;
            s32 duration;
        } midi;
        struct {
            s32 ticks;
            u8 status;
            u8 type;
            u8 unkA;
            u8 byte1;
            u8 byte2;
            u8 byte3;
        } tempo;
    } msg;
} TTEvent_80025224;
typedef struct {
    u32 unk0;
    u32 nTracks;
} TTCMidiHdr_80025680;
typedef struct {
    TTCMidiHdr_80025680 *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    s32 unk14;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} TTCSeq_80025680;
typedef struct {
    u32 validTracks;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} TTCSeqMarker;
typedef struct {
    u32 unk0;
    u32 nTracks;
} TTCMidiHdr_80025750;
typedef struct {
    TTCMidiHdr_80025750 *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    s32 unk14;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} TTCSeq_80025750;
typedef struct {
    u32 division;
    u32 nTracks;
    u32 trackOffset[32];
} TTCMidiHdr_80025820;
typedef struct {
    TTCMidiHdr_80025820 *base;
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
} TTCSeq_80025820;
typedef struct {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 chan;
            u8 byte1;
            u8 byte2;
            s32 duration;
        } midi;
    } msg;
} TTEvent_80025820;
typedef struct {
    u32 division;
    u32 nTracks;
    u32 trackOffset[32];
} TTCMidiHdr_8002597C;
typedef struct {
    TTCMidiHdr_8002597C *base;
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
} TTCSeq_8002597C;
typedef struct {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 chan;
            u8 byte1;
            u8 byte2;
            s32 duration;
        } midi;
    } msg;
} TTEvent_8002597C;
typedef struct {
    u32 unk0;
    u32 nTracks;
} TTCMidiHdr_80025BF0;
typedef struct {
    TTCMidiHdr_80025BF0 *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    s32 unk14;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} TTCSeq_80025BF0;

u32 func_80025224(TTCSeq_80025224 *seq, u32 track, TTEvent_80025224 *event, s32 loopsOn);
u8 func_80025BF0(TTCSeq_80025BF0 *seq, u32 track);
u32 func_80025DE4(void *seq, u32 track);

void func_80024EE0(TTCSeq_80024EE0 *seq, u8 *ptr)
{
    u32 i, tmpOff, flagTmp;

    seq->base = (TTCMidiHdr_80024EE0 *) ptr;
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
            seq->curLoc[i] = (u8 *) ((u32) ptr + tmpOff);
            seq->evtDeltaTicks[i] = func_80025DE4(seq, i);
        } else
            seq->curLoc[i] = 0;
    }

    seq->qnpt = 1.0f / (f32) seq->base->division;
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

    if (status == 0xFF) {
        u8 type = func_80025BF0(seq, track);

        if (type == 0x51) {
            event->type = 3;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.byte1 = func_80025BF0(seq, track);
            event->msg.tempo.byte2 = func_80025BF0(seq, track);
            event->msg.tempo.byte3 = func_80025BF0(seq, track);
            seq->lastStatus[track] = 0;
        } else if (type == 0x2F) {
            u32 flagMask;

            flagMask = 0x01 << track;
            seq->validTracks = seq->validTracks ^ flagMask;

            if (seq->validTracks)
                event->type = 0x12;
            else
                event->type = 4;
        } else if (type == 0x2E) {
            status = func_80025BF0(seq, track);
            event->msg.midi.duration = status << 8;
            status = func_80025BF0(seq, track);
            event->msg.midi.duration += status;
            seq->lastStatus[track] = 0;
            event->type = 0x13;
        } else if (type == 0x2D) {
            tmpPtr = seq->curLoc[track];
            loopCt = *tmpPtr++;
            curLpCt = *tmpPtr;
            if (curLpCt == 0 || loopsOn == 0) {
                *tmpPtr = loopCt;
                seq->curLoc[track] = tmpPtr + 5;
            } else {
                if (curLpCt != 0xFF)
                    *tmpPtr = curLpCt - 1;
                tmpPtr++;
                offset = *tmpPtr++ << 24;
                offset += *tmpPtr++ << 16;
                offset += *tmpPtr++ << 8;
                offset += *tmpPtr++;
                seq->curLoc[track] = tmpPtr - offset;
            }
            seq->lastStatus[track] = 0;
            event->type = 0x14;
        }
    } else {
        event->type = 1;
        if (status & 0x80) {
            event->msg.midi.status = status & 0xF0;
            event->msg.midi.chan = track;
            event->msg.midi.byte1 = func_80025BF0(seq, track);
            seq->lastStatus[track] = event->msg.midi.status;
        } else {
            event->msg.midi.status = seq->lastStatus[track];
            event->msg.midi.byte1 = status;
            event->msg.midi.chan = track;
        }

        if (((event->msg.midi.status & 0xF0) != 0xC0) &&
            ((event->msg.midi.status & 0xF0) != 0xD0)) {
            event->msg.midi.byte2 = func_80025BF0(seq, track);
            if ((event->msg.midi.status & 0xF0) == 0x90) {
                event->msg.midi.duration = func_80025DE4(seq, track);
            }
        } else
            event->msg.midi.byte2 = 0;
    }
    return 1;
}

s32 func_80025668(u8 *param_0)
{
    return M2C_FIELD(param_0, s32 *, 0xC);
}

void func_80025680(TTCSeq_80025680 *seq, TTCSeqMarker *m)
{
    u32 i;

    seq->validTracks = m->validTracks;
    seq->lastTicks = m->lastTicks;
    seq->lastDeltaTicks = m->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        seq->curLoc[i] = m->curLoc[i];
        seq->curBUPtr[i] = m->curBUPtr[i];
        seq->curBULen[i] = m->curBULen[i];
        seq->lastStatus[i] = m->lastStatus[i];
        seq->evtDeltaTicks[i] = m->evtDeltaTicks[i];
    }
}

void func_80025750(TTCSeq_80025750 *seq, TTCSeqMarker *m)
{
    u32 i;

    m->validTracks = seq->validTracks;
    m->lastTicks = seq->lastTicks;
    m->lastDeltaTicks = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        m->curLoc[i] = seq->curLoc[i];
        m->curBUPtr[i] = seq->curBUPtr[i];
        m->curBULen[i] = seq->curBULen[i];
        m->lastStatus[i] = seq->lastStatus[i];
        m->evtDeltaTicks[i] = seq->evtDeltaTicks[i];
    }
}

void func_80025820(TTCSeq_80025820 *seq, TTCSeqMarker *m, u32 ticks)
{
    TTEvent_80025820 evt;
    TTCSeq_80025820 tempSeq;
    s32 i;

    func_80024EE0(&tempSeq, (u8 *) seq->base);

    do {
        m->validTracks = tempSeq.validTracks;
        m->lastTicks = tempSeq.lastTicks;
        m->lastDeltaTicks = tempSeq.lastDeltaTicks;

        for (i = 0; i < seq->base->nTracks; i++) {
            m->curLoc[i] = tempSeq.curLoc[i];
            m->curBUPtr[i] = tempSeq.curBUPtr[i];
            m->curBULen[i] = tempSeq.curBULen[i];
            m->lastStatus[i] = tempSeq.lastStatus[i];
            m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }

        func_80025084(&tempSeq, &evt, 0);

        if (evt.type == 4)
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

    func_80024EE0(&tempSeq, (u8 *) seq->base);

    for (remaining = 0; remaining < count; remaining++)
        markers[remaining].lastTicks = 0;

    do {
        m.validTracks = tempSeq.validTracks;
        m.lastTicks = tempSeq.lastTicks;
        m.lastDeltaTicks = tempSeq.lastDeltaTicks;

        for (i = 0; i < seq->base->nTracks; i++) {
            m.curLoc[i] = tempSeq.curLoc[i];
            m.curBUPtr[i] = tempSeq.curBUPtr[i];
            m.curBULen[i] = tempSeq.curBULen[i];
            m.lastStatus[i] = tempSeq.lastStatus[i];
            m.evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }

        func_80025084(&tempSeq, &evt, 0);

        if (evt.type == 0x13) {
            if (((evt.msg.midi.duration >> 8) >= start) &&
                ((evt.msg.midi.duration >> 8) < start + count)) {
                if (markers[(evt.msg.midi.duration >> 8) - start].lastTicks == 0) {
                    markers[(evt.msg.midi.duration >> 8) - start] = m;
                    if (--remaining <= 0)
                        return;
                }
            }
        }
    } while (evt.type != 4);
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
                backup = (u32) hiBackUp;
                backup = backup << 8;
                backup += loBackUp;
                seq->curBUPtr[track] = seq->curLoc[track] - (backup + 4);
                seq->curBULen[track] = (u32) theLen;

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

    value = (u32) func_80025BF0(seq, track);
    if (value & 0x00000080) {
        value &= 0x7f;
        do {
            c = (u32) func_80025BF0(seq, track);
            value = (value << 7) + (c & 0x7f);
        } while (c & 0x80);
    }
    return value;
}
