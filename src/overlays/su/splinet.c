// Time-keyed spline track: keys with frame times, hold/cut/branch flags and speed percentages,
// vec3 and scalar channels, looping, and cubic evaluation of the current time.
#include "common.h"

typedef struct {
    u8 pad[0x32];
    s16 flags_offset;
} SplineFlagsView;
typedef struct {
    u8 pad[0x30];
    s16 times_offset;
    s16 flags_offset;
    u8 pad34[0x10];
    f32 cur_time;
    f32 prev_time;
    u8 pad4C[2];
    s16 count;
    u8 bits[1];
} SplineS;
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x44];
    f32 cur_time;
    u8 pad_1[0xC];
    u32 flags;
} SplineTimeState;
typedef struct {
    u8 pad_0[0x30];
    s16 offsets[3];
    s16 vector_offsets[4];
    s16 pair_offsets[7];
    s16 index, count;
    u8 pad_1, vector_count, pair_count;
} SplineLayout1446;
typedef struct {
    u8 pad[0x30];
    s16 off0;
} SplineHdr30_80800384_susplinet;
typedef struct {
    u8 pad[0x30];
    s16 off0;
    s16 off1;
} SplineHdr30_susplinet_entrypoint_16;
extern s32 func_800DA9E4(s32, s32);
extern void func_800F0EF0(s32, f32 *);
extern void _mlspline_entrypoint_8(f32, s32, f32 *, u8 *);
extern void _mlspline_entrypoint_9(f32, s32, f32 *, u8 *);
typedef struct {
    u8 pad[0x30];
    s16 knots_offset;
    s16 pad32;
    s16 speeds_offset;
} SplHdr;
typedef struct {
    u8 pad[0x32];
    s16 unk32;
    s16 unk34;
} SplinetHdr;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad[0x30];
    s16 off30;
} SplineHdr30b;
extern s32 func_800EEDE8(void *, void *, f32);
extern f32 func_800EEAD4(void *, void *);
extern void _mlspline_entrypoint_4(f32, s32, void *, void *);
void func_80800D3C_susplinet_2arg();

// TU-NOTE: func_80800D3C_susplinet is also called with two arguments from susplinet_entrypoint_17,
// through the second name func_80800D3C_susplinet_2arg (undefined_syms.us.txt); no prototype, so the
// f32 argument is passed as its bit pattern.

// Sets or clears flag bits of a key.
void susplinet_entrypoint_0(SplineFlagsView *track, s32 key, s32 mask, s32 set)
{
    s16 *flags = (s16 *) ((u8 *) track + track->flags_offset);
    if (set) {
        flags[key] |= mask;
    } else if (flags[key] & mask) {
        flags[key] -= mask;
    }
}

// Key flag 4.
s32 func_80800048_susplinet(SplineS *track, s32 key)
{
    s16 *flags = (s16 *) ((u8 *) track + track->flags_offset);
    return flags[key] & 4;
}

// Key flag 2.
s32 func_80800068_susplinet(SplineS *track, s32 key)
{
    s16 *flags = (s16 *) ((u8 *) track + track->flags_offset);
    return flags[key] & 2;
}

// Sets or clears a bit in the bitset at +0x50.
void susplinet_entrypoint_1(s32 track, s32 bit, s32 set)
{
    if (set) {
        *(u8 *) (track + 0x50 + (bit / 8)) |= 1 << (bit & 7);
    } else {
        *(u8 *) (track + 0x50 + (bit / 8)) &= ~(1 << (bit & 7));
    }
}

// Tests a bit in the bitset at +0x50.
s32 func_808000FC_susplinet(s32 track, s32 bit)
{
    return (((u8 *) ((s32) track + (bit / 8)))[80] & (1 << (bit & 7))) ? 1 : 0;
}

// The current time has reached the last key.
s32 susplinet_entrypoint_2(SplineS *track)
{
    s16 *times = (s16 *) ((u8 *) track + track->times_offset);
    return times[track->count - 1] <= track->cur_time;
}

// Time of the last key.
s32 susplinet_entrypoint_3(SplineS *track)
{
    s16 *times = (s16 *) ((u8 *) track + track->times_offset);
    return times[track->count - 1];
}

s32 susplinet_entrypoint_4(SplineS *track, f32 frame)
{
    if (track->prev_time <= frame && frame < func_800D8FF8() * 100.0f + track->cur_time) {
        return 1;
    }
    return 0;
}

int susplinet_entrypoint_5(f32 track[9], f32 frame)
{
    if (track[18] <= frame && frame < track[17])
        return 1;
    return 0;
}

susplinet_entrypoint_6(u8 *track)
{
    return track[0x53];
}

void susplinet_entrypoint_7(f32 (*points)[3], s32 idx, f32 *out)
{
    func_800EE7F8(out, points[idx]);
}

float susplinet_entrypoint_8(float *track, int idx)
{
    return track[idx + 9];
}

f32 susplinet_entrypoint_9(void *track)
{
    return ((f32 *) track)[17];
}

// Sets the current time, clamped at 0 and wrapped by the last key time when looping.
void susplinet_entrypoint_10(SplineTimeState *track, f32 frame)
{
    s32 length;
    length = susplinet_entrypoint_3((SplineS *) track);
    if (frame < 0.0f)
        frame = 0.0f;
    if (track->flags & 2) {
        while ((f32) length < frame)
            frame -= (f32) length;
    }
    track->cur_time = frame;
}

void susplinet_entrypoint_11(Actor *track, f32 frame)
{
    *(f32 *) ((u8 *) track + 0x48) = frame;
}

// Offset of the key time table (+0x30).
int susplinet_entrypoint_12(s32 track)
{
    // Matching: the temporary pointer and `(0, track)` are needed for the match.
    s16 *field;
    field = (s16 *) ((int) track + 0x30);
    return *field + (0, track);
}

// Offset of the speed table (+0x34).
int susplinet_entrypoint_13(s32 track)
{
    // Matching: the temporary pointer and `(0, track)` are needed for the match.
    s16 *field;
    field = (s16 *) ((int) track + 0x34);
    return *field + (0, track);
}

// Offset of vec3 channel idx.
s32 susplinet_entrypoint_14(s32 track, s32 idx)
{
    // Matching: the extra temporaries are needed for the match.
    unsigned long byte_off;
    s32 base;
    s8 *entry;
    byte_off = idx * 2;
    base = track;
    entry = (s8 *) (base + byte_off) + 0x36;
    return *(s16 *) entry + track;
}

// Offset of scalar channel idx.
s32 susplinet_entrypoint_15(s32 track, s32 idx)
{
    // Matching: the `^ 0` is needed for the match.
    return *(s16 *) ((s8 *) ((track ^ 0) + (idx * 2)) + 0x3E) + track;
}

// Finds the segment containing frame, searching from the cached index.
s16 func_80800384_susplinet(SplineLayout1446 *track, s16 frame)
{
    s16 *times;
    s16 *seg;
    s16 idx;
    s32 last;

    times = (s16 *) ((s32) track + ((SplineHdr30_80800384_susplinet *) track)->off0);
    idx = track->index;
    seg = (s16 *) ((u32) times + idx * sizeof(s16));
    if (frame < *seg && idx > 0) {
        do {
            idx--;
            seg = (s16 *) ((u32) times + idx * sizeof(s16));
        } while (frame < *seg && idx > 0);
    }
    if (seg[1] < frame) {
        last = track->count - 1;
        if (idx < last) {
            do {
                idx++;
            } while (times[idx + 1] < frame && idx < last);
        }
    }
    track->index = idx;
    return idx;
}

// Sets the time; at a branch key (flag 1) jumps depending on game flag 0x644.
void susplinet_entrypoint_16(SplineLayout1446 *this, f32 frame, f32 new_frame)
{
    s16 *times;
    s16 *key_flags;
    s16 k;
    s16 i;
    s16 j;

    times = (s16 *) ((s32) this + ((SplineHdr30_susplinet_entrypoint_16 *) this)->off0);
    key_flags = (s16 *) ((s32) this + ((SplineHdr30_susplinet_entrypoint_16 *) this)->off1);
    k = func_80800384_susplinet(this, frame);
    i = k + 1;
    j = i + 1;
    if (j >= this->count) {
        susplinet_entrypoint_10(this, new_frame);
        return;
    }
    if (times[i] != times[j]) {
        susplinet_entrypoint_10(this, new_frame);
        return;
    }
    if (new_frame < times[i]) {
        susplinet_entrypoint_10(this, new_frame);
        return;
    }
    if (key_flags[i] & 1) {
        if (func_800DA9E4(0x644, 0) == 0) {
            susplinet_entrypoint_10(this, times[i]);
        } else {
            susplinet_entrypoint_10(this, times[j] + 1);
        }
        return;
    }
    susplinet_entrypoint_10(this, new_frame);
}

// Picks the four key indices around frame (wrapping when looping).
// Returns the segment-local parameter.
f32 func_80800620_susplinet(u8 *track, s16 *keys, f32 frame)
{
    f32 frame_copy; // Matching: extra copy needed for the match.
    s16 *times;
    times = (s16 *) ((s32) track + ((SplineHdr30b *) track)->off30);
    frame_copy = frame;
    keys[1] = func_80800384_susplinet(track, (s16) (s32) frame_copy);
    keys[0] = keys[1] - 1;
    keys[2] = keys[1] + 1;
    if (!(*(u32 *) (track + 0x54) & 2)) {
        if (keys[2] >= *(s16 *) (track + 0x4E))
            keys[2] = *(s16 *) (track + 0x4E) - 1;
        keys[3] = keys[2] + 1;
        if (keys[3] >= *(s16 *) (track + 0x4E))
            keys[3] = *(s16 *) (track + 0x4E) - 1;
        if (keys[0] < 0)
            keys[0] = 0;
    } else {
        if (keys[2] >= *(s16 *) (track + 0x4E))
            keys[2] = keys[2] - *(s16 *) (track + 0x4E) + 1;
        keys[3] = keys[2] + 1;
        if (keys[3] >= *(s16 *) (track + 0x4E))
            keys[3] = keys[3] - *(s16 *) (track + 0x4E) + 1;
        if (keys[0] < 0)
            keys[0] = *(s16 *) (track + 0x4E) + keys[0] - 1;
    }
    if (func_80800048_susplinet(track, keys[1]))
        keys[0] = keys[1];
    if (func_80800068_susplinet(track, keys[2]))
        keys[3] = keys[2];
    return func_800F10B4(frame, times[keys[1]], times[keys[2]], 0.333f, 0.666f);
}

// Maps frame to a segment parameter through the arc-length table (30 samples) and a
// trapezoid speed profile from the key speed percentages.
f32 func_808007D0_susplinet(u8 *track, f32 frame, s16 *keys, u8 *pts)
{
    s16 *knots;
    s16 *lens;
    s32 pad1;
    f32 arc_len[30];
    s32 pad2;
    f32 cur_pt[3];
    f32 prev_pt[3];
    s32 i;
    f32 mid_speed;
    f32 end_speed;
    f32 start_speed;
    f32 duration;
    f32 pad80;
    f32 frac;
    f32 speed;
    f32 edge_speed;
    f32 half_frac;
    f32 dist;
    s32 k;

    knots = (s16 *) ((s32) track + ((SplHdr *) track)->knots_offset);
    lens = (s16 *) ((s32) track + ((SplHdr *) track)->speeds_offset);
    if ((f32) knots[keys[2]] <= frame) {
        return 0.666f;
    }
    if (frame <= (f32) knots[keys[1]]) {
        return 0.333f;
    }
    if (func_800EEDE8(pts + 0xC, pts + 0x18, 25.0f) != 0) {
        return func_800F10B4(frame, (f32) knots[keys[1]], (f32) knots[keys[2]], 0.333f,
                             0.666f);
    }
    for (i = 0; i != 30; i++) {
        _mlspline_entrypoint_4(func_800F10B4((f32) i, 0.0f, 29.0f, 0.333f, 0.666f), 4, pts,
                               cur_pt);
        if (i > 0) {
            arc_len[i] = arc_len[i - 1] + func_800EEAD4(prev_pt, cur_pt);
        } else {
            arc_len[i] = 0.0f;
        }
        func_800EE7F8(prev_pt, cur_pt);
    }
    start_speed = (f32) lens[keys[1]] * 0.01f;
    end_speed = (f32) lens[keys[2]] * 0.01f;
    duration = (f32) knots[keys[2]] - (f32) knots[keys[1]];
    mid_speed = ((((arc_len[29] * 4.0f) / duration) - start_speed) - end_speed) * 0.5f;
    frac = func_800F10B4(frame, (f32) knots[keys[1]], (f32) knots[keys[2]], 0.0f, 1.0f);
    if (frac < 0.5f) {
        speed = func_800F10B4(frame, (f32) knots[keys[1]],
                             (f32) knots[keys[1]] + (0.5f * duration), start_speed, mid_speed);
        half_frac = func_800F10B4(frame, (f32) knots[keys[1]], (f32) knots[keys[1]] + (0.5f * duration),
                          0.0f, 1.0f);
        edge_speed = start_speed;
    } else {
        speed = func_800F10B4(frame, (f32) knots[keys[1]] + (0.5f * duration),
                             (f32) knots[keys[2]], mid_speed, end_speed);
        half_frac = func_800F10B4(frame, (f32) knots[keys[1]] + (0.5f * duration), (f32) knots[keys[2]],
                          0.0f, 1.0f);
        edge_speed = mid_speed;
    }

    if (speed < edge_speed) {
        dist = (edge_speed + speed) * 0.25f * duration * half_frac;
    } else {
        dist = (speed + edge_speed) * 0.25f * duration * half_frac;
    }
    if (0.5f <= frac) {
        dist += (0.25f * duration) * (start_speed + mid_speed);
    }
    k = 0;
    while (k < 28 && arc_len[k + 1] < dist) {
        k++;
    }
    dist = func_800F10B4(dist, arc_len[k], arc_len[k + 1], (f32) k * 0.03448275849f,
                      (f32) (k + 1) * 0.03448275849f);
    return func_800F10B4(dist, 0.0f, 1.0f, 0.333f, 0.666f);
}

// Matching: `times` is a third parameter that is only written, never read on entry; it gives
// the value a register without a stack slot.
void func_80800D3C_susplinet(u8 *track, f32 frame, s16 *times)
{
    s16 *speeds;
    u8 *vec_channels[5];
    u8 *scalar_channels[3];
    s32 i;
    s16 keys[4];
    f32 t;
    f32 scalar_pts[4];
    f32 pt3[3];
    f32 pt2[3];
    f32 pt1[3];
    f32 pt0[3];
    s32 off0;
    s32 off1;
    s32 off2;
    s32 off3;

    speeds = (s16 *) ((s32) track + ((SplHdr *) track)->speeds_offset);
    times = (s16 *) ((s32) track + ((SplHdr *) track)->knots_offset);
    if ((f32) times[*(s16 *) (track + 0x4E) - 1] < frame) {
        frame = times[*(s16 *) (track + 0x4E) - 1];
    } else if (frame < (f32) times[0]) {
        frame = times[0];
    }
    for (i = 0; i < track[0x51]; i++) {
        vec_channels[i] = track + *(s16 *) (track + 0x36 + i * 2);
    }
    for (i = 0; i < track[0x52]; i++) {
        scalar_channels[i] = track + *(s16 *) (track + 0x3E + i * 2);
    }
    if (*(s16 *) (track + 0x4E) >= 4) {
        t = func_80800620_susplinet(track, keys, frame);
        if (keys[0] != keys[1] && times[keys[0]] == times[keys[1]] &&
            susplinet_entrypoint_5(track, times[keys[1]])) {
            track[0x53] = 1;
        } else {
            track[0x53] = 0;
        }
        off0 = keys[0] * 3;
        off1 = keys[1] * 3;
        off2 = keys[2] * 3;
        off3 = keys[3] * 3;
        for (i = 0; i < track[0x51]; i++) {
            func_800EE7F8(pt0, (f32 *) vec_channels[i] + off0);
            func_800EE7F8(pt1, (f32 *) vec_channels[i] + off1);
            func_800EE7F8(pt2, (f32 *) vec_channels[i] + off2);
            func_800EE7F8(pt3, (f32 *) vec_channels[i] + off3);
            if (i == 0 && *speeds != -1) {
                t = func_808007D0_susplinet(track, frame, keys, pt0);
            }
            if (func_808000FC_susplinet(track, i)) {
                func_800F0EF0(4, pt0);
            }
            _mlspline_entrypoint_4(t, 4, pt0, track + i * 12);
            if (i == 0) {
                _mlspline_entrypoint_8(t, 4, pt0, track + i * 12 + 0x18);
            }
        }
        for (i = 0; i < track[0x52]; i++) {
            scalar_pts[0] = ((f32 *) scalar_channels[i])[keys[0]];
            scalar_pts[1] = ((f32 *) scalar_channels[i])[keys[1]];
            scalar_pts[2] = ((f32 *) scalar_channels[i])[keys[2]];
            scalar_pts[3] = ((f32 *) scalar_channels[i])[keys[3]];
            _mlspline_entrypoint_9(t, 4, scalar_pts, track + 0x24 + i * 4);
        }
    }
}

// Evaluates the track at its current time.
void susplinet_entrypoint_17(track) u8 *track;
{
    track[0x58] = 1;
    func_80800D3C_susplinet_2arg(track, *(s32 *) (track + 0x44));
    track[0x58] = 0;
}

// Fills the offset tables: key times, key flags, vec3 channels, scalar channels.
void func_8080111C_susplinet(SplineLayout1446 *track)
{
    s32 offset;
    s32 i;

    track->offsets[0] = 0x5C;
    offset = 0x5C + track->count * 2;
    track->offsets[1] = offset;
    offset += track->count * 2;
    for (i = 0; i < track->vector_count; i++) {
        track->vector_offsets[i] = offset;
        offset += track->count * 12;
    }
    for (i = 0; i < track->pair_count; i++) {
        track->pair_offsets[i] = offset;
        offset += track->count * 4;
    }
    track->offsets[2] = offset;
}

s32 func_808011B8_susplinet(s32 vec_channels, s32 scalar_channels)
{
    return (vec_channels * 0xC) + (scalar_channels * 4) + 6;
}

// Total byte size for count keys (0x5C header + per-key data).
s32 susplinet_entrypoint_18(s32 count, s32 vec_channels, s32 scalar_channels)
{
    int size;
    s32 key_size;
    // Matching: the `| 0` operands and the `if (1)` are needed for the match.
    key_size = func_808011B8_susplinet(vec_channels | 0, scalar_channels | 0);
    size = count * key_size;
    if (1) {
        return size + 0x5C;
    }
}

// Initializes a track: no flags, speeds = -1 (none), clears flag 0x644.
void susplinet_entrypoint_19(u8 *track, s32 count, s32 vec_channels, s32 scalar_channels)
{
    s16 *key_flags;
    s16 *speeds;
    s32 i;

    *(s16 *) (track + 0x4E) = count;
    track[0x51] = vec_channels;
    track[0x52] = scalar_channels;
    track[0x50] = 0;
    *(s16 *) (track + 0x4C) = 0;
    track[0x58] = 0;
    *(f32 *) (track + 0x44) = 0.0f;
    *(f32 *) (track + 0x48) = 0.0f;
    func_8080111C_susplinet(track);
    key_flags = (s16 *) ((s32) track + ((SplinetHdr *) track)->unk32);
    speeds = (s16 *) ((s32) track + ((SplinetHdr *) track)->unk34);
    for (i = 0; i < count; i++) {
        key_flags[i] = 0;
        speeds[i] = -1;
    }
    func_800DA524(0x644);
}
