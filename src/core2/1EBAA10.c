#include "common.h"
#include "types.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern float D_8012CFB8[12];
extern u8 D_8012D004[1124];
extern float D_8012CFAC[16];
extern float D_8012CFA4[16];
typedef struct {
    u8 pad[0x74];
    u8 state, type, has_pos, phase;
    u8 tail[4];
} LocalEffect;
typedef union {
    u8 raw[1];
    LocalEffect fx[1];
} Union_D_8012CF90;
extern Union_D_8012CF90 D_8012CF90;
extern s32 func_800DC128(s32, s32);
// One shake slot is 0x7C bytes; the structs below are partial views of it.
typedef struct {
    u8 pad0[0x18];
    f32 duration;
    u8 pad1C[4];
    f32 peak;
    u8 pad24[8];
    f32 sign;
    f32 timer;
    u8 pad34[0x40];
    u8 state;
    u8 pad75[7];
} S8012CF90;
typedef struct {
    u8 pad0[0x74];
    u8 state;
    u8 pad75;
    u8 has_pos;
    u8 pad77[5];
} E124_E1720;
typedef struct {
    f32 pos[3], falloff[3];
    f32 duration, decay, peak, amp_end, amplitude, sign, timer;
    f32 curve[16];
    u8 state, axis, unk_76, phase, curve_count, pad[3];
} EffectE1804;
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F3780(f32, f32 *, s32);
typedef struct {
    f32 pos[3], near_dist, far_dist, min_scale;
    u8 pad0[16];
    f32 amplitude, sign;
    u8 pad1[0x44];
    u8 state, axis, has_pos, pad2[5];
} EntryE1A58;
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
void func_800E13F0(s32 param_0, f32 param_1);
void func_800E144C(s32 param_0, f32 param_1);
void func_800E146C(s32 param_0, f32 param_1);
void func_800E148C(s32 param_0, f32 param_1, f32 param_2);

// Shake offset along the rotated Y axis.
void func_800E1120(f32 *out, f32 *rot, f32 amount)
{
    f32 vec[3];
    func_800EFA4C(vec, 0.0f, amount, 0.0f);
    func_800EF8BC(vec, vec, rot[0]);
    func_800EF934(vec, vec, rot[1]);
    func_800EF04C(out, vec);
}

// Shake offset along the rotated Z axis.
void func_800E119C(f32 *out, f32 *rot, f32 amount)
{
    f32 vec[3];
    func_800EFA4C(vec, 0.0f, 0.0f, amount);
    func_800EF8BC(vec, vec, rot[0]);
    func_800EF934(vec, vec, rot[1]);
    func_800EF04C(out, vec);
}

// Shake offset along the rotated X axis.
void func_800E1218(f32 *out, f32 *rot, f32 amount)
{
    f32 vec[3];
    func_800EFA4C(vec, amount, 0.0f, 0.0f);
    func_800EF8BC(vec, vec, rot[0]);
    func_800EF934(vec, vec, rot[1]);
    func_800EF04C(out, vec);
}

void func_800E1294(s32 axis, f32 *out, f32 *rot, f32 amount)
{
    switch (axis) {
        case 1:
            func_800E1218(out, rot, amount);
            break;
        case 0:
            func_800E1120(out, rot, amount);
            break;
        case 2:
            func_800E119C(out, rot, amount);
            break;
        case 3:
            out[1] += amount;
    }
}

f32 func_800E1338(s32 slot)
{
    return *(f32 *) ((u8 *) D_8012CFB8 + slot * 124);
}

int func_800E1354(s32 slot)
{
    return D_8012D004[slot * 124] != 1;
}

void func_800E1378(s32 slot)
{
    func_800E13F0(slot, 30.0f);
    func_800E144C(slot, 0.65f);
    func_800E148C(slot, 1000.0f, 2000.0f);
    if (func_800EA068(0x20) != 0) {
        func_800E146C(slot, 0.0f);
        return;
    }
    func_800E146C(slot, 0.5f);
}

void func_800E13F0(s32 slot, f32 amplitude)
{
    *(f32 *) ((u8 *) D_8012CFB8 + slot * 124) = amplitude;
}

void func_800E1410(s32 slot, f32 amp_delta, f32 duration)
{
    float target;
    f32 current;
    u8 *entry;
    f32 *amp_ptr;
    entry = (u8 *) ((slot * 0x7C) + D_8012CF90.raw);
    amp_ptr = (f32 *) (entry + 0x28);
    current = *amp_ptr;
    target = current + amp_delta;
    *(f32 *) (entry + 0x24) = current;
    *(f32 *) (entry + 0x30) = duration;
    *(f32 *) (entry + 0x20) = target;
    *(f32 *) (entry + 0x18) = duration;
}

void func_800E144C(s32 slot, f32 decay)
{
    *(f32 *) ((u8 *) D_8012CFAC + slot * 124) = decay;
}

void func_800E146C(s32 slot, f32 min_scale)
{
    *(f32 *) ((u8 *) D_8012CFA4 + slot * 124) = min_scale;
}

// Sets the near/far distances for position-based falloff.
void func_800E148C(s32 slot, f32 near_dist, f32 far_dist)
{
    f32 *entry = (f32 *) ((char *) (f32 *) D_8012CF90.raw + slot * 124);
    entry[3] = near_dist;
    entry[4] = far_dist;
}

void func_800E14B8(s32 slot, f32 *pos)
{
    func_800EE7F8((f32 *) &D_8012CF90.raw[slot * 124], pos);
    D_8012CF90.raw[slot * 124 + 0x76] = 1;
}

void func_800E14F8(s32 slot, u8 *curve, s16 count)
{
    u8 *entry = (u8 *) (int *) D_8012CF90.raw;
    entry += slot * 124;
    entry[120] = count;
    rare_memcpy(entry + 52, curve, (u32) count << 3);
}

// Picks a free slot (random one if all are in use) and starts it.
s32 func_800E1540(s32 axis)
{
    s32 i;
    LocalEffect *entry;
    for (i = 0; i < 10; i++) {
        if (D_8012CF90.fx[i].state == 1)
            break;
    }
    if (i == 10) {
        i = func_800DC128(0, 10);
    }
    entry = &D_8012CF90.fx[i];
    entry->type = axis;
    entry->state = 2;
    entry->phase = 0;
    return i;
}

s32 func_800E15CC(s32 axis, f32 amplitude, f32 decay)
{
    s32 slot;

    slot = func_800E1540(axis);
    func_800E13F0(slot, amplitude);
    func_800E144C(slot, decay);
    return slot;
}

s32 func_800E1610(s32 axis, f32 amplitude, f32 decay, f32 *pos)
{
    s32 slot;
    slot = func_800E1540(axis);
    func_800E13F0(slot, amplitude);
    func_800E144C(slot, decay);
    func_800E14B8(slot, pos);
    return slot;
}

// Starts a curve-driven shake (state 4).
s32 func_800E1664(s32 axis, f32 peak, f32 duration, s32 pos, s32 curve, s16 count)
{
    s32 slot;
    S8012CF90 *entry;
    slot = func_800E1540(axis);
    func_800E14F8(slot, curve, count);
    entry = &((S8012CF90 *) D_8012CF90.raw)[slot];
    entry->state = 4;
    entry->peak = peak;
    entry->timer = 0.0f;
    entry->duration = duration;
    if (peak >= 0.0f) {
        entry->sign = 1.0f;
    } else {
        entry->sign = -1.0f;
    }
    if (pos != 0) {
        func_800E14B8(slot, pos);
    }
    return slot;
}

// Stops a shake slot.
void func_800E1720(s32 slot)
{
    ((E124_E1720 *) D_8012CF90.raw)[slot].state = 1;
    ((E124_E1720 *) D_8012CF90.raw)[slot].has_pos = 0;
}

int func_800E1748()
{
    s32 i;
    for (i = 0; i < 10; i++) {
        func_800E1720(i);
    }
}

void func_800E1788(void)
{
    s8 *entry;
    s32 i;

    entry = (s32 *) D_8012CF90.raw;
    i = 0;
    do {
        *(s8 *) ((s8 *) entry + 0x74) = 1;
        *(f32 *) ((s8 *) entry + 0x30) = 0.0f;
        *(s8 *) ((s8 *) entry + 0x76) = 0;
        func_800EFD24(entry);
        func_800E1378(i);
        i += 1;
        entry += 0x7C;
    } while (i != 0xA);
}

// Per-frame update of all shake slots.
void func_800E1804(void)
{
    EffectE1804 *entry;
    s32 i;
    f32 dt;
    dt = func_800D8FF8();
    for (i = 0; i < 10; i++) {
        entry = &((EffectE1804 *) D_8012CF90.raw)[i];
        switch (entry->state) {
            case 2:
                if (entry->amplitude >= 0.0f)
                    entry->sign = 1.0f;
                else
                    entry->sign = -1.0f;
                entry->state = 3;
                entry->phase = 0;
                break;
            case 3:
                if (entry->timer != 0.0f) {
                    entry->timer = func_800F0E00(0.0f, entry->timer - dt);
                    if (entry->phase)
                        entry->amplitude = func_800F10B4(entry->timer, entry->duration, 0.0f,
                                                         entry->amp_end, entry->peak);
                } else if (entry->phase) {
                    entry->amplitude *= entry->decay * entry->decay;
                }
                entry->phase ^= 1;
                entry->sign = -entry->sign;
                if (entry->decay != 1 && mlAbsF(entry->amplitude) < 0.001f)
                    func_800E1720(i);
                break;
            case 4:
                if (entry->timer < entry->duration) {
                    entry->timer = func_800F13F0(entry->duration, entry->timer + dt);
                    entry->amplitude = func_800F3780(entry->timer / entry->duration,
                                                     entry->curve, entry->curve_count) *
                                       entry->peak;
                    entry->sign = -entry->sign;
                } else
                    func_800E1720(i);
        }
    }
}

// Applies the summed shake of all active slots to the camera position/rotation.
void func_800E1A58(f32 *pos, f32 *rot)
{
    f32 scale;
    f32 cam_pos[3];
    s32 i;
    func_800EE7F8(cam_pos, pos);
    for (i = 0; i < 10; i++) {
        scale = 1;
        if (((EntryE1A58 *) D_8012CF90.raw)[i].state == 1)
            continue;
        if (((EntryE1A58 *) D_8012CF90.raw)[i].has_pos) {
            scale = func_800F0E00(
                func_800F10B4(
                    func_800EEAD4(cam_pos, ((EntryE1A58 *) D_8012CF90.raw)[i].pos),
                    ((EntryE1A58 *) D_8012CF90.raw)[i].near_dist,
                    ((EntryE1A58 *) D_8012CF90.raw)[i].far_dist, 1.0f, 0.0f),
                ((EntryE1A58 *) D_8012CF90.raw)[i].min_scale);
            if (scale == 0)
                continue;
        }
        switch (((EntryE1A58 *) D_8012CF90.raw)[i].state) {
            case 2:
                func_800E1294(((EntryE1A58 *) D_8012CF90.raw)[i].axis, pos, rot,
                              ((EntryE1A58 *) D_8012CF90.raw)[i].amplitude * scale);
                break;
            case 3:
            case 4:
                func_800E1294(((EntryE1A58 *) D_8012CF90.raw)[i].axis, pos, rot,
                              ((EntryE1A58 *) D_8012CF90.raw)[i].sign *
                                  ((EntryE1A58 *) D_8012CF90.raw)[i].amplitude * scale);
        }
    }
}
