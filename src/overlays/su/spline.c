// Spline path follower component: several vec3 and scalar channels of control points sharing
// one point count, progress with speed and looping, sampled via ml/spline.
#include "common.h"

extern f32 func_800EEAD4();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad[0x70];
    s16 offsets[4];
    s16 count;
    s16 pad7A;
    s16 current;
} SuSplineOffsetView;
extern f32 func_800D8FF8(void);
extern void _mlspline_entrypoint_6(void);
extern void _mlspline_entrypoint_7(void);
extern void _mlspline_entrypoint_8(void);
extern f32 _mlspline_entrypoint_13(s32, void *, f32, f32, f32, void (*)());
typedef struct {
    u8 pad0[0x58];
    f32 progress;
    u8 pad5C[12];
    s16 offsets[8];
    s16 count;
    s16 index;
    u8 pad7C[14];
    u8 flags;
} SplineAdvance32;
typedef struct SplineAdvanceState {
    u8 pad_0[0x58];
    f32 progress;
    u8 pad_1[12];
    s16 offsets[8];
    s16 count;
    s16 index;
    u8 pad_2[14];
    u8 flags;
} SplineAdvanceState;
extern void func_800EE7F8(void *, void *);
extern void func_800F0EF0(s32, void *);
extern void _mlspline_entrypoint_0(f32, s32, void *, void *);
extern void _mlspline_entrypoint_1(f32, s32, void *, void *);
extern void _mlspline_entrypoint_2(f32, s32, void *, void *);
extern void _mlspline_entrypoint_3(f32, s32, void *, void *);
extern void _mlspline_entrypoint_4(f32, s32, void *, void *);
extern void _mlspline_entrypoint_9(f32, s32, void *, void *);
extern void func_800EFD24();

// Sets or clears a bit in the bitset at +0x7E.
void suspline_entrypoint_0(s32 spline, s32 bit, s32 set)
{
    if (set) {
        *(u8 *) (spline + 0x7E + (bit / 8)) |= 1 << (bit & 7);
    } else {
        *(u8 *) (spline + 0x7E + (bit / 8)) &= ~(1 << (bit & 7));
    }
}

// Tests a bit in the bitset at +0x7E.
int func_80800074_suspline(u8 *spline, s32 bit)
{
    return (((u8 *) ((s32) spline + (bit / 8)))[126] & (1 << (bit & 7))) ? 1 : 0;
}

// Tests a bit in the bitset at +0x87 (per-channel angle flag).
int func_808000B4_suspline(u8 *spline, s32 bit)
{
    return (((u8 *) spline + bit / 8)[0x87] & (1 << (bit & 7))) ? 1 : 0;
}

// Progress has reached the end.
s32 suspline_entrypoint_1(spline)
Actor *spline;
{
    return spline->unk58 >= 0.99f;
}

int suspline_entrypoint_2(f32 spline[4], f32 value)
{
    if (spline[23] <= value && value < spline[22])
        return 1;
    return 0;
}

void suspline_entrypoint_3(f32 (*points)[3], s32 idx, f32 *out)
{
    func_800EE7F8(out, points[idx]);
}

float suspline_entrypoint_4(float *spline, int idx)
{
    return ((float *) ((char *) spline + (idx * 4)))[0x30 / 4];
}

s32 suspline_entrypoint_5(s32 spline, f32 *src)
{
    func_800EE7F8(spline + 0x3C, src);
}

f32 suspline_entrypoint_6(void *spline)
{
    return ((f32 *) spline)[22];
}

suspline_entrypoint_7(u8 *spline)
{
    return spline[0x8B];
}

s32 suspline_entrypoint_8(Actor *this, f32 progress)
{
    this->unk58 = progress;
}

int suspline_entrypoint_9(f32 *spline, f32 value)
{
    f32 tmp; // Matching: extra temporary needed for the match.
    spline[23] = (tmp = value);
}

// Offset of vec3 channel idx.
s32 suspline_entrypoint_10(s32 spline, s32 idx)
{
    // Matching: the `^ 0` is needed for the match.
    return *(s16 *) ((s8 *) ((spline ^ 0) + (idx * 2)) + 0x68) + spline;
}

// Offset of scalar channel idx.
s32 suspline_entrypoint_11(s32 spline, s32 idx)
{
    // Matching: the chain of `& 0xFFFFFFFFu` is needed for the match.
    return *(s16 *) ((s8 *) (spline +
                             ((((((((((((idx * 2) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
                                     0xFFFFFFFFu) &
                                    0xFFFFFFFFu) &
                                   0xFFFFFFFFu) &
                                  0xFFFFFFFFu) &
                                 0xFFFFFFFFu) &
                                0xFFFFFFFFu) &
                               0xFFFFFFFFu) &
                              0xFFFFFFFFu)) +
                     0x70) +
           spline;
}

// Sets the flags byte at +0x8A (1 = paused, 2 = loop).
void suspline_entrypoint_12(s32 spline, s32 flags)
{
    // Matching: the pointer round trip through `flags` is needed for the match.
    s32 flags_value;
    s32 *flags_ptr;
    flags_ptr = &flags;
    ((u8 *) spline)[0x8A] = (flags_value = *flags_ptr);
}

// Picks the four control point indices around progress (wrapping when looping).
// Returns the segment-local parameter.
f32 func_80800224_suspline(u8 *spline, f32 *progress, s16 *keys)
{
    if (*(s16 *) (spline + 0x78) >= 4) {
        if (spline[0x8A] & 2) {
            keys[1] = (f32) *(s16 *) (spline + 0x78) * *progress;
        } else {
            keys[1] = (f32) (*(s16 *) (spline + 0x78) - 1) * *progress;
        }
        keys[0] = keys[1] - 1;
        keys[2] = keys[1] + 1;
        if (keys[2] >= *(s16 *) (spline + 0x78)) {
            if (spline[0x8A] & 2) {
                keys[2] -= *(s16 *) (spline + 0x78);
            } else {
                keys[2] = *(s16 *) (spline + 0x78) - 1;
            }
        }
        keys[3] = keys[2] + 1;
        if (keys[3] >= *(s16 *) (spline + 0x78)) {
            if (spline[0x8A] & 2) {
                keys[3] -= *(s16 *) (spline + 0x78);
            } else {
                keys[3] = *(s16 *) (spline + 0x78) - 1;
            }
        }
        if (keys[0] < 0) {
            if (spline[0x8A] & 2) {
                keys[0] += *(s16 *) (spline + 0x78);
            } else {
                keys[0] = 0;
            }
        }
        if (func_80800074_suspline(spline, keys[1])) {
            if (spline[0x8A] & 2) {
                *progress = (keys[1] + 1) / (f32) *(s16 *) (spline + 0x78);
            } else {
                *progress = (keys[1] + 1) / (f32) (*(s16 *) (spline + 0x78) - 1);
            }
            spline[0x8B] = 1;
        } else {
            spline[0x8B] = 0;
        }
        if (func_80800074_suspline(spline, keys[2])) {
            keys[3] = keys[2];
        }
        if (func_80800074_suspline(spline, keys[0])) {
            keys[0] = keys[1];
        }
        if (spline[0x8A] & 2) {
            return func_800F10B4(*progress, keys[1] / (f32) *(s16 *) (spline + 0x78),
                                 (keys[1] + 1) / (f32) *(s16 *) (spline + 0x78), 0.333f,
                                 0.666f);
        }
        return func_800F10B4(*progress, keys[1] / (f32) (*(s16 *) (spline + 0x78) - 1),
                             keys[2] / (f32) (*(s16 *) (spline + 0x78) - 1), 0.333f, 0.666f);
    }
    return 0.0f;
}

// Samples the current scalar channel into +0x60 and scales it by the time step into +0x64.
void suspline_entrypoint_13(u8 *spline)
{
    f32 t;
    s16 keys[4];
    f32 samples[4];
    f32 *points;

    if (!(spline[0x8A] & 1)) {
        points = (f32 *) (spline + ((SuSplineOffsetView *) spline)
                                         ->offsets[((SuSplineOffsetView *) spline)->current]);
        if (*(s16 *) (spline + 0x78) >= 4) {
            t = func_80800224_suspline(spline, (f32 *) (spline + 0x58), keys);
            samples[0] = points[keys[0]];
            samples[1] = points[keys[1]];
            samples[2] = points[keys[2]];
            samples[3] = points[keys[3]];
            _mlspline_entrypoint_9(t, 4, samples, (f32 *) (spline + 0x60));
        } else if (*(s16 *) (spline + 0x78) == 3) {
            _mlspline_entrypoint_3(*(f32 *) (spline + 0x58), *(s16 *) (spline + 0x78), points,
                                   (f32 *) (spline + 0x60));
        } else {
            _mlspline_entrypoint_1(*(f32 *) (spline + 0x58), *(s16 *) (spline + 0x78), points,
                                   (f32 *) (spline + 0x60));
        }
        if (*(f32 *) (spline + 0x54) < 0.05f) {
            *(f32 *) (spline + 0x54) = 0.05f;
        }
        *(f32 *) (spline + 0x64) = *(f32 *) (spline + 0x60) * func_800D8FF8();
    }
}

// Advances progress along the spline at speed * step (+0x54, +0x64).
void suspline_entrypoint_14(SplineAdvance32 *spline)
{
    f32 progress;
    s32 count;
    u8 *points;

    if ((progress = spline->progress) < 0.9999f && !(spline->flags & 1)) {
        points = (u8 *) spline + spline->offsets[spline->index];
        count = spline->count;
        if (count >= 4) {
            spline->progress = _mlspline_entrypoint_13(count, points, progress,
                                                        *(f32 *) ((u8 *) spline + 0x54) *
                                                            *(f32 *) ((u8 *) spline + 0x64),
                                                        1.0f, _mlspline_entrypoint_8);
        } else if (count >= 3) {
            spline->progress = _mlspline_entrypoint_13(count, points, progress,
                                                        *(f32 *) ((u8 *) spline + 0x54) *
                                                            *(f32 *) ((u8 *) spline + 0x64),
                                                        1.0f, _mlspline_entrypoint_7);
        } else {
            spline->progress = _mlspline_entrypoint_13(count, points, progress,
                                                        *(f32 *) ((u8 *) spline + 0x54) *
                                                            *(f32 *) ((u8 *) spline + 0x64),
                                                        1.0f, _mlspline_entrypoint_6);
        }
    }
}

// Same as entrypoint_14 with the step passed in.
void suspline_entrypoint_15(SplineAdvanceState *spline, f32 step)
{
    s32 num_points;
    void *points;

    if (spline->progress < 0.9999f && !(spline->flags & 1)) {
        points = (u8 *) spline + spline->offsets[spline->index];
        num_points = spline->count;
        if (num_points >= 4) {
            spline->progress = _mlspline_entrypoint_13(num_points, points, spline->progress, step,
                                                       1.0f, _mlspline_entrypoint_8);
        } else if (num_points >= 3) {
            spline->progress = _mlspline_entrypoint_13(num_points, points, spline->progress, step,
                                                       1.0f, _mlspline_entrypoint_7);
        } else {
            spline->progress = _mlspline_entrypoint_13(num_points, points, spline->progress, step,
                                                       1.0f, _mlspline_entrypoint_6);
        }
    }
}

// Constant-speed correction of the speed scale.
void suspline_entrypoint_16(u8 *spline)
{
    if (!suspline_entrypoint_1(spline) && 0.0f != *(f32 *) (spline + 0x64) &&
        !func_800EECE0((f32 *) (spline + 0x48), (f32 *) (spline + 0x3C))) {
        *(f32 *) (spline + 0x54) *=
            *(f32 *) (spline + 0x64) /
            func_800EEAD4((f32 *) (spline + 0x48), (f32 *) (spline + 0x3C));
    }
}

// Samples all vec3 and scalar channels at the current progress.
void suspline_entrypoint_17(u8 *spline)
{
    f32 progress;
    u8 *vec_channels[4];
    u8 *scalar_channels[4];
    s32 i;
    f32 t;
    s16 keys[4];
    f32 scalar_pts[4];
    f32 pt3[3];
    f32 pt2[3];
    f32 pt1[3];
    f32 pt0[3];
    progress = *(f32 *) (spline + 0x58);
    func_800EE7F8(spline + 0x48, spline + 0x3C);
    for (i = 0; i < spline[0x88]; i++) {
        vec_channels[i] = spline + *(s16 *) (spline + 0x68 + i * 2);
    }
    for (i = 0; i < spline[0x89]; i++) {
        scalar_channels[i] = spline + *(s16 *) (spline + 0x70 + i * 2);
    }
    if (*(s16 *) (spline + 0x78) >= 4) {
        t = func_80800224_suspline(spline, &progress, keys);
        for (i = 0; i < spline[0x88]; i++) {
            func_800EE7F8(pt0, (f32 *) vec_channels[i] + 3 * keys[0]);
            func_800EE7F8(pt1, (f32 *) vec_channels[i] + 3 * keys[1]);
            func_800EE7F8(pt2, (f32 *) vec_channels[i] + 3 * keys[2]);
            func_800EE7F8(pt3, (f32 *) vec_channels[i] + 3 * keys[3]);
            if (func_808000B4_suspline(spline, i)) {
                func_800F0EF0(4, pt0);
            }
            _mlspline_entrypoint_4(t, 4, pt0, spline + 0xC * i);
        }
        for (i = 0; i < spline[0x89]; i++) {
            scalar_pts[0] = ((f32 *) scalar_channels[i])[keys[0]];
            scalar_pts[1] = ((f32 *) scalar_channels[i])[keys[1]];
            scalar_pts[2] = ((f32 *) scalar_channels[i])[keys[2]];
            scalar_pts[3] = ((f32 *) scalar_channels[i])[keys[3]];
            _mlspline_entrypoint_9(t, 4, scalar_pts, spline + 0x30 + i * 4);
        }
    } else {
        if (*(s16 *) (spline + 0x78) == 3) {
            for (i = 0; i < spline[0x88]; i++) {
                _mlspline_entrypoint_2(progress, *(s16 *) (spline + 0x78), vec_channels[i],
                                       spline + 0xC * i);
            }
            for (i = 0; i < spline[0x89]; i++) {
                _mlspline_entrypoint_3(progress, *(s16 *) (spline + 0x78), scalar_channels[i],
                                       spline + 0x30 + i * 4);
            }
        } else {
            for (i = 0; i < spline[0x88]; i++) {
                _mlspline_entrypoint_0(progress, *(s16 *) (spline + 0x78), vec_channels[i],
                                       spline + 0xC * i);
            }
            for (i = 0; i < spline[0x89]; i++) {
                _mlspline_entrypoint_1(progress, *(s16 *) (spline + 0x78), scalar_channels[i],
                                       spline + 0x30 + i * 4);
            }
        }
    }
    if (progress > 0.9998999834f) {
        progress = 0.9998999834f;
    }
    *(f32 *) (spline + 0x58) = progress;
}

// Fills the channel offset tables: vec3 channels first, then scalar channels.
void func_80800C8C_suspline(u8 *spline)
{
    s32 offset;
    s32 i;
    u8 *vec_slot;
    u8 *scalar_slot;
    offset = 0x8C;
    i = 0;
    vec_slot = spline;
    if ((s32) *(u8 *) (spline + 0x88) > 0) {
        do {
            *(s16 *) (vec_slot + 0x68) = offset;
            i++;
            vec_slot += 2;
            offset += *(s16 *) (spline + 0x78) * 0xC;
        } while (i < (s32) *(u8 *) (spline + 0x88));
        i = 0;
    }
    scalar_slot = spline;
    if ((s32) *(u8 *) (spline + 0x89) > 0) {
        do {
            *(s16 *) (scalar_slot + 0x70) = offset;
            i++;
            scalar_slot += 2;
            offset += *(s16 *) (spline + 0x78) * 4;
        } while (i < (s32) *(u8 *) (spline + 0x89));
    }
}

// Total byte size for count points (0x8C header + channel data).
s32 suspline_entrypoint_18(unsigned int count, s32 vec_channels, s32 scalar_channels)
{
    return (count * ((vec_channels * 0xC) + (scalar_channels * 4))) + 0x8C;
}

// Initializes a spline block.
void suspline_entrypoint_19(spline, count, vec_channels, scalar_channels, unk_4, current) u8 *spline;
s32 count;
s32 vec_channels;
s32 scalar_channels;
s32 unk_4;
s32 current;
{
    s32 i;

    func_800EFD24((f32 *) (spline + 0x3C));
    func_800EFD24((f32 *) (spline + 0x48));
    spline[0x7E] = 0;
    *(f32 *) (spline + 0x60) = 0.0f;
    *(f32 *) (spline + 0x64) = 0.0f;
    for (i = 1; i < 9; i++) {
        spline[0x7E + i] = 0;
    }
    *(s16 *) (spline + 0x7A) = unk_4;
    *(s16 *) (spline + 0x7C) = current;
    *(s16 *) (spline + 0x78) = count;
    spline[0x88] = vec_channels;
    spline[0x89] = scalar_channels;
    spline[0x87] = 0;
    *(f32 *) (spline + 0x54) = 1.0f;
    func_800EFD24((f32 *) (spline + 0x48));
    *(f32 *) (spline + 0x58) = 0.0f;
    *(f32 *) (spline + 0x5C) = -0.01f;
    spline[0x8B] = 0;
    spline[0x8A] = 0;
    func_80800C8C_suspline(spline);
}

int suspline_entrypoint_20(s32 block, s32 count, s32 vec_channels, s32 scalar_channels, f32 unk_4[3],
                           f32 current[3])
{
    s32 size;
    s32 scalar_count; // Matching: extra copy needed for the match.
    scalar_count = scalar_channels;
    size = suspline_entrypoint_18(count, vec_channels, scalar_count);
    func_80100074(block, 1, size);
    suspline_entrypoint_19(func_80100094(block, 1), count, vec_channels, scalar_channels, unk_4, current);
}
