#include "common.h"

typedef struct {
    u16 id : 12;
    u16 type : 4;
    s16 n;
} AnimTrack;
// Animation header: frame range, track count, then the tracks.
// Each track is a header followed by n 4-byte keyframes.
typedef struct {
    u16 id : 12;
    u16 type : 4;
    s16 n;
} EntryE0170;
typedef struct {
    s16 start;
    s16 end;
    s16 track_count;
    s16 pad_6;
    EntryE0170 tracks[1];
} StateE0170;
extern f32 func_800E04C0(EntryE0170 *, f32, s32);
extern void func_800E084C(s32, f32 *, s32);
f32 func_800E0414(u8 *param_0, f32 param_1);

// Evaluates all tracks of one bone at normalized time into a 9-float transform
// [rot xyz, scale xyz, trans xyz].
void func_800E0050(u8 *anim, f32 norm_time, s32 bone_id, f32 *xform)
{
    f32 frame;
    s32 found;
    s32 i;
    AnimTrack *track;
    s32 type;
    frame = func_800E0414(anim, norm_time);
    xform[0] = xform[1] = xform[2] = 0.0f;
    xform[6] = xform[7] = xform[8] = 0.0f;
    xform[3] = xform[4] = xform[5] = 1.0f;
    found = 0;
    track = (AnimTrack *) (anim + 8);
    for (i = 0; i < *(s16 *) (anim + 4); i++) {
        type = track->type;
        if (bone_id != track->id) {
            if (found) {
                return;
            }
        } else {
            found = 1;
            if (type >= 9) {
                type -= 9;
            }
            xform[type] = func_800E04C0(track, frame, 0);
        }
        track = (AnimTrack *) ((u8 *) track + track->n * 4 + 4);
    }
}

// Evaluates every bone of the animation at normalized time and stores each
// bone's 9-float transform into the pose.
void func_800E0170(StateE0170 *anim, f32 norm_time, s32 use_span, s32 pose)
{
    f32 frame;
    s32 span;
    EntryE0170 *entry;
    s32 cur_id;
    f32 values[12];
    s32 i;
    s32 channel;
    frame = func_800E0414(anim, norm_time);
    span = use_span ? anim->end - anim->start : 0;
    entry = anim->tracks;
    cur_id = 0;
    for (i = 0; i < anim->track_count; i++) {
        if (cur_id != entry->id) {
            if (cur_id)
                func_800E084C(pose, values, cur_id);
            cur_id = entry->id;
            values[0] = values[1] = values[2] = 0.0f;
            values[3] = values[4] = values[5] = 1.0f;
            values[6] = values[7] = values[8] = 0.0f;
        }
        channel = entry->type;
        if (channel >= 9)
            channel -= 9;
        values[channel] = func_800E04C0(entry, frame, span);
        entry += entry->n;
        entry++;
    }
    func_800E084C(pose, values, cur_id);
}

// Collects the channel-7 values of all tracks whose id is in [min_id, max_id].
void func_800E02F8(u8 *anim, f32 norm_time, s32 use_span, s32 min_id, s32 max_id, f32 *out)
{
    f32 frame;
    s32 span;
    s32 i;
    s32 count;
    u32 header;
    u32 id;
    u8 *track;

    frame = func_800E0414(anim, norm_time);
    count = 0;
    if (use_span != 0) {
        span = *(s16 *) ((s8 *) anim + 2) - *(s16 *) ((s8 *) anim + 0);
    } else {
        span = 0;
    }
    track = anim + 8;
    i = 0;
    if (*(s16 *) ((s8 *) anim + 4) > 0) {
        do {
            header = *(u16 *) ((s8 *) track + 0);
            id = header >> 4;
            if (((s32) id >= min_id) && (max_id >= (s32) id) &&
                ((header & 0xF) == 7)) {
                *(out + count) = func_800E04C0(track, frame, span);
                count += 1;
            }
            i += 1;
            track += (*(s16 *) ((s8 *) track + 2) * 4) + 4;
        } while (i < *(s16 *) ((s8 *) anim + 4));
    }
}

// Maps normalized time (0..1) to a frame between start and end.
f32 func_800E0414(u8 *anim, f32 norm_time)
{
    s16 start_copy;
    s16 *start_ptr;
    s16 start;
    // Matching: the extra pointer and copy are needed for the match.
    start_ptr = (s16 *) ((s8 *) anim + 0);
    start = *start_ptr;
    return (norm_time * (f32) (*(s16 *) ((s8 *) anim + 2) - start)) + (f32) (start_copy = start);
}

// Returns the end frame.
s16 func_800E0440(s32 anim)
{
    return *(s16 *) (anim + 2);
}

// Returns the start frame.
s16 func_800E0448(s16 *anim)
{
    return anim[0];
}

// Returns the frame count.
func_800E0450(s16 *anim)
{
    return (anim[1] - anim[0]) + 1;
}

// Returns the track count.
func_800E0464(s16 *anim)
{
    return anim[2];
}

// Maps a frame to normalized time; the end frame gives just under 1.
float func_800E046C(u8 *anim, s32 frame)
{
    s16 start;
    if (frame == *(s16 *) ((char *) anim + 2)) {
        return 0.999999f;
    }
    start = *(s16 *) ((char *) anim + 0);
    return (float) (frame - start) / (float) (*(s16 *) ((char *) anim + 2) - start);
}

func_800E04AC(void *param_0)
{
}
