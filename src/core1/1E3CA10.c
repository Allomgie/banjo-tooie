// libultra compact MIDI sequence (alCSeq) parser: event extraction, byte-stream decompression,
// markers and seeking.
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

u32 func_80025224(TTCSeq_80025224 *seq, u32 track, TTEvent_80025224 *event, s32 loops_on);
u8 func_80025BF0(TTCSeq_80025BF0 *seq, u32 track);
u32 func_80025DE4(void *seq, u32 track);

// alCSeqNew: initialise from a compressed MIDI header.
void func_80024EE0(TTCSeq_80024EE0 *seq, u8 *data)
{
    u32 i, offset, track_bit;

    seq->base = (TTCMidiHdr_80024EE0 *) data;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    seq->deltaFlag = 1;

    for (i = 0; i < seq->base->nTracks; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = 0;
        seq->curBULen[i] = 0;
        offset = seq->base->trackOffset[i];
        if (offset) {
            track_bit = 1 << i;
            seq->validTracks |= track_bit;
            seq->curLoc[i] = (u8 *) ((u32) data + offset);
            seq->evtDeltaTicks[i] = func_80025DE4(seq, i);
        } else
            seq->curLoc[i] = 0;
    }

    seq->qnpt = 1.0f / (f32) seq->base->division;
}

// alCSeqNextEvent: pick the track with the smallest delta and read its next event.
void func_80025084(TTCSeq_80025084 *seq, TTEvent_80025084 *evt, s32 loops_on)
{
    u32 i;
    u32 first_time = 0xFFFFFFFF;
    u32 first_track;
    u32 last_delta = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag)
                seq->evtDeltaTicks[i] -= last_delta;
            if (seq->evtDeltaTicks[i] < first_time) {
                first_time = seq->evtDeltaTicks[i];
                first_track = i;
            }
        }
    }

    func_80025224(seq, first_track, evt, loops_on);

    evt->msg.ticks = first_time;
    seq->lastTicks += first_time;
    seq->lastDeltaTicks = first_time;
    if (evt->type != 0x12)
        seq->evtDeltaTicks[first_track] += func_80025DE4(seq, first_track);
    seq->deltaFlag = 1;
}

// Decode one event of a track: meta events (tempo, end of track, loop start/end) or a MIDI message.
u32 func_80025224(TTCSeq_80025224 *seq, u32 track, TTEvent_80025224 *event, s32 loops_on)
{
    u32 offset;
    u8 status, loop_count, cur_count, *ptr;

    status = func_80025BF0(seq, track);

    if (status == 0xFF) { // meta event
        u8 type = func_80025BF0(seq, track);

        if (type == 0x51) { // tempo
            event->type = 3;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.byte1 = func_80025BF0(seq, track);
            event->msg.tempo.byte2 = func_80025BF0(seq, track);
            event->msg.tempo.byte3 = func_80025BF0(seq, track);
            seq->lastStatus[track] = 0;
        } else if (type == 0x2F) { // end of track
            u32 track_mask;

            track_mask = 0x01 << track;
            seq->validTracks = seq->validTracks ^ track_mask;

            if (seq->validTracks)
                event->type = 0x12; // track end
            else
                event->type = 4; // sequence end
        } else if (type == 0x2E) { // loop start
            status = func_80025BF0(seq, track);
            event->msg.midi.duration = status << 8;
            status = func_80025BF0(seq, track);
            event->msg.midi.duration += status;
            seq->lastStatus[track] = 0;
            event->type = 0x13;
        } else if (type == 0x2D) { // loop end
            ptr = seq->curLoc[track];
            loop_count = *ptr++;
            cur_count = *ptr;
            if (cur_count == 0 || loops_on == 0) {
                *ptr = loop_count; // reload the counter
                seq->curLoc[track] = ptr + 5;
            } else {
                if (cur_count != 0xFF) // 0xFF loops forever
                    *ptr = cur_count - 1;
                ptr++;
                offset = *ptr++ << 24;
                offset += *ptr++ << 16;
                offset += *ptr++ << 8;
                offset += *ptr++;
                seq->curLoc[track] = ptr - offset; // jump back to the loop start
            }
            seq->lastStatus[track] = 0;
            event->type = 0x14;
        }
    } else {
        event->type = 1; // MIDI message
        if (status & 0x80) {
            event->msg.midi.status = status & 0xF0;
            event->msg.midi.chan = track;
            event->msg.midi.byte1 = func_80025BF0(seq, track);
            seq->lastStatus[track] = event->msg.midi.status;
        } else { // running status
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

// alCSeqSetLoc: restore the sequence position from a marker.
void func_80025680(TTCSeq_80025680 *seq, TTCSeqMarker *marker)
{
    u32 i;

    seq->validTracks = marker->validTracks;
    seq->lastTicks = marker->lastTicks;
    seq->lastDeltaTicks = marker->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        seq->curLoc[i] = marker->curLoc[i];
        seq->curBUPtr[i] = marker->curBUPtr[i];
        seq->curBULen[i] = marker->curBULen[i];
        seq->lastStatus[i] = marker->lastStatus[i];
        seq->evtDeltaTicks[i] = marker->evtDeltaTicks[i];
    }
}

// alCSeqGetLoc: save the sequence position into a marker.
void func_80025750(TTCSeq_80025750 *seq, TTCSeqMarker *marker)
{
    u32 i;

    marker->validTracks = seq->validTracks;
    marker->lastTicks = seq->lastTicks;
    marker->lastDeltaTicks = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->nTracks; i++) {
        marker->curLoc[i] = seq->curLoc[i];
        marker->curBUPtr[i] = seq->curBUPtr[i];
        marker->curBULen[i] = seq->curBULen[i];
        marker->lastStatus[i] = seq->lastStatus[i];
        marker->evtDeltaTicks[i] = seq->evtDeltaTicks[i];
    }
}

// Replay a copy of the sequence and save a marker at the last event before the given tick.
void func_80025820(TTCSeq_80025820 *seq, TTCSeqMarker *marker, u32 ticks)
{
    TTEvent_80025820 evt;
    TTCSeq_80025820 temp_seq;
    s32 i;

    func_80024EE0(&temp_seq, (u8 *) seq->base);

    do {
        marker->validTracks = temp_seq.validTracks;
        marker->lastTicks = temp_seq.lastTicks;
        marker->lastDeltaTicks = temp_seq.lastDeltaTicks;

        for (i = 0; i < seq->base->nTracks; i++) {
            marker->curLoc[i] = temp_seq.curLoc[i];
            marker->curBUPtr[i] = temp_seq.curBUPtr[i];
            marker->curBULen[i] = temp_seq.curBULen[i];
            marker->lastStatus[i] = temp_seq.lastStatus[i];
            marker->evtDeltaTicks[i] = temp_seq.evtDeltaTicks[i];
        }

        func_80025084(&temp_seq, &evt, 0);

        if (evt.type == 4) // sequence end
            break;

    } while (temp_seq.lastTicks < ticks);
}

// Scan the sequence for loop-start events (id in [start, start + count)) and save a marker for each.
void func_8002597C(TTCSeq_8002597C *seq, TTCSeqMarker *markers, u32 count, u32 start)
{
    TTEvent_8002597C evt;
    TTCSeq_8002597C temp_seq;
    u32 i;
    s32 remaining;
    TTCSeqMarker m;

    func_80024EE0(&temp_seq, (u8 *) seq->base);

    for (remaining = 0; remaining < count; remaining++)
        markers[remaining].lastTicks = 0;

    do {
        m.validTracks = temp_seq.validTracks;
        m.lastTicks = temp_seq.lastTicks;
        m.lastDeltaTicks = temp_seq.lastDeltaTicks;

        for (i = 0; i < seq->base->nTracks; i++) {
            m.curLoc[i] = temp_seq.curLoc[i];
            m.curBUPtr[i] = temp_seq.curBUPtr[i];
            m.curBULen[i] = temp_seq.curBULen[i];
            m.lastStatus[i] = temp_seq.lastStatus[i];
            m.evtDeltaTicks[i] = temp_seq.evtDeltaTicks[i];
        }

        func_80025084(&temp_seq, &evt, 0);

        if (evt.type == 0x13) { // loop start
            if (((evt.msg.midi.duration >> 8) >= start) &&
                ((evt.msg.midi.duration >> 8) < start + count)) {
                if (markers[(evt.msg.midi.duration >> 8) - start].lastTicks == 0) {
                    markers[(evt.msg.midi.duration >> 8) - start] = m;
                    if (--remaining <= 0)
                        return;
                }
            }
        }
    } while (evt.type != 4); // sequence end
}

// __getTrackByte: next byte of a track, expanding 0xFE back-references (offset, length) into earlier data.
u8 func_80025BF0(TTCSeq_80025BF0 *seq, u32 track)
{
    u8 byte;

    if (seq->curBULen[track]) {
        byte = *seq->curBUPtr[track];
        seq->curBUPtr[track]++;
        seq->curBULen[track]--;
    } else {
        byte = *seq->curLoc[track];
        seq->curLoc[track]++;
        if (byte == 0xFE) {
            u8 back_lo, back_hi, len, next;
            u32 back;

            next = *seq->curLoc[track];
            seq->curLoc[track]++;
            if (next != 0xFE) { // 0xFE 0xFE is a literal 0xFE
                back_hi = next;
                back_lo = *seq->curLoc[track];
                seq->curLoc[track]++;
                len = *seq->curLoc[track];
                seq->curLoc[track]++;
                back = (u32) back_hi;
                back = back << 8;
                back += back_lo;
                seq->curBUPtr[track] = seq->curLoc[track] - (back + 4);
                seq->curBULen[track] = (u32) len;

                byte = *seq->curBUPtr[track];
                seq->curBUPtr[track]++;
                seq->curBULen[track]--;
            }
        }
    }

    return byte;
}

// __readVarLen: variable-length quantity (7 bits per byte, high bit = more).
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
