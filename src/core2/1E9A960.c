// SFX source system: a pool of positional sound sources with volume envelopes, pitch modes,
// distance falloff and panning, plus sfx id helpers and a small sound-script interpreter.
#include "core2/1E9A960.h"

#define MIN_C(a, b) ((a) < (b) ? (a) : (b))
#define MAX_C(a, b) ((a) > (b) ? (a) : (b))
#define C4350_MODE(mode)                                                                           \
    (local_1->flags.half.lower = (local_1->flags.half.lower & 0xFC3F) | ((mode) << 6))
#define C4350_IMM ((local_3 & 0xFF00) >> 8)
typedef struct {
    u8 pad0[0x78];
    u8 unk78;
    u8 pad79[7];
} Sub_C13E4;
typedef struct {
    Sub_C13E4 sub[4];
} E_C13E4;
typedef struct {
    u8 local_0[0x78];
    u8 local_1;
    u8 local_2[7];
} local_type_800C145C;
// TU-NOTE: D_80128B0C + 8 * n aliases D_80128B10[n - 1].local_1.
extern s32 D_80128B0C[];
typedef struct {
    s32 local_0;
    s32 local_1;
} local_type_800C15BC;
extern local_type_800C15BC D_80128B10[16];
extern u8 D_80128C08[];
typedef struct {
    u8 pad0[0x1B];
    u8 field1B;
    u8 field1C;
    u8 pad1D[3];
    s32 field20;
    s32 field24;
    u8 pad28[0x30];
    s16 field58;
    u16 field5A;
    u8 pad5C[4];
    u8 field60;
    u8 field61;
    u8 pad62[10];
    s32 field6C;
    u8 pad70[9];
    u8 field79;
} LocalSound_800C16F8;
extern f32 D_8011A878;
extern void func_800DC454(s32, s32);
extern void func_800EFB24(void *arg0, void *arg1, void *arg2);
extern f32 func_800EEFD4(void *arg0);
typedef struct SoundC {
    f32 local_0[3], local_1, local_2, local_3;
    s16 local_4;
    u8 local_5[6];
    u8 pad20[0x20];
    f32 local_6, local_7, local_8;
    s16 local_9, local_10;
    f32 local_11, local_12;
    s16 local_13, local_14, local_15, local_16;
    u8 local_17, local_18, local_19, local_20;
    void (*local_21)(u8, s32);
    s32 local_22;
    f32 local_23;
    u8 pad70[8];
    union {
        struct {
            u8 local_0, local_1;
            u16 local_2;
        } local_0;
        struct {
            u32 local_0 : 16;
            u32 local_1 : 3;
            u32 local_2 : 3;
            u32 local_3 : 4;
            u32 local_4 : 1;
            u32 local_5 : 1;
            u32 local_6 : 1;
            u32 local_7 : 1;
            u32 local_8 : 1;
            u32 local_9 : 1;
        } local_1;
    } local_24;
} SoundC;
extern void func_800E3980(f32 *);
extern void func_800E3A58(f32 *);
extern void func_800EF7B0(f32 *, f32 *, f32, f32, f32);
extern void func_800F1EA4(f32 *, f32 *);
typedef struct {
    char pad[0x70];
    f32 unk70;
    f32 unk74;
} Struct_800C1CCC;
extern s32 func_800EA05C(void);
extern s32 func_800EA068(s32);
extern s32 func_800A8184(void);
typedef struct {
    u8 pad_0[0x28];
    f32 field_28, field_2C, field_30, field_34, field_38, field_3C;
    f32 attack, decay, hold;
    s16 minimum, maximum;
    f32 drift, elapsed;
    s16 sound, volume, limit, context;
    u8 pad_60[0xC];
    f32 pitch;
    u8 pad_70[8];
    union {
        struct {
            u8 pad_78, handle;
            u16 pad_7A;
        } bytes;
        struct {
            u32 pad_78 : 16, policy : 3, state : 3, mode : 4;
            u32 stopping : 1, timed : 1, envelope : 1, pad_7B : 1, release : 1, pad_7C : 1;
        } bits;
    } flags;
} LocalSound_800C2000;
extern f32 func_800D8FF8(void);
extern f32 func_800DC264(f32, f32);
extern s32 func_800F0E28(s32, s32);
extern s32 func_800F1418(s32, s32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 local_0[0x78];
    u32 local_1 : 8;
    u32 local_2 : 11;
    u32 local_3 : 3;
    u32 local_4 : 10;
    u32 local_5;
} local_type_800C2718;
extern s32 func_800C0638(void);
typedef struct {
    u8 pad[0x78];
    u8 local_0;
    u8 pad79[7];
} SoundSlotC;
// TU-NOTE: D_80128C10 is D_80128B90 slot 1 (+0x80); D_80128C08 is the in-use byte (0x78) of slot 0.
extern s32 D_80128C10;
typedef struct {
    u8 local_0[0x54];
    f32 local_1;
    u8 local_2[10];
    u8 local_3;
    u8 local_4[21];
    u32 local_5 : 8;
    u32 local_6 : 11;
    u32 local_7 : 3;
    u32 local_8 : 4;
    u32 local_9 : 1;
    u32 local_10 : 5;
    u32 local_11;
} local_type_800C2B80;
extern local_type_800C2B80 D_80128B90[60];
extern void func_800EFD24(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct {
    u8 pad0[0x4C];
    s16 unk4C;
    s16 unk4E;
    f32 unk50;
    u8 pad54[6];
    s16 unk5A;
    u8 pad5C[0x1C];
    u32 pad78 : 28;
    u32 flag : 1;
    u32 pad78b : 3;
} S800C316C;
struct SomeStruct {
    u8 pad[0x28];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad2[0x42];
    u16 unk7A;
};
typedef struct {
    u8 pad0[0x7B];
    u8 f0 : 6;
    u8 bit : 1;
    u8 f2 : 1;
} S_C3B8C;
typedef struct {
    u8 local_0[0x58];
    s16 local_1;
    u8 local_2[0x1E];
    u32 local_3 : 16;
    u32 local_4 : 3;
    u32 local_5 : 3;
    u32 local_6 : 7;
    u32 local_7 : 1;
    u32 local_8 : 2;
} local_type_800C3BDC;
extern void func_800FECB8(s32);
extern float D_8011A870;
extern float D_8011A874;
typedef struct {
    f32 position[3];
    f32 radiusSquared[2];
    u8 pad14[6];
    s8 field1A;
    u8 field1B, field1C, field1D;
    u8 pad1E[10];
    f32 field28, field2C, field30, field34, field38, field3C;
    u8 pad40[24];
    s16 field58;
    u8 pad5A[4];
    s16 field5E;
    u8 field60, field61, field62, field63;
    void (*callback)(u8, s32);
    s32 callbackArgument;
    f32 field6C, field70, field74;
    union {
        u32 word;
        struct {
            unsigned pad : 29;
            unsigned enabled : 1;
            unsigned low : 2;
        } bits;
        struct {
            u16 upper, lower;
        } half;
        struct {
            u8 a, b, c, d;
        } byte;
    } flags;
} C4350State;
extern void func_800EE7F8(void *, void *);
extern s32 func_800DC214(s32, s32);
typedef struct {
    f32 local_0;
    s16 local_1, local_2;
} C4350Defaults;
extern float D_8012A990;
extern s16 D_8012A994;
extern s16 D_8012A996;
void func_800C2B80();
int func_800C3058(u8, unsigned int);
void func_800C32C4(u8, s32);
void func_800C368C(u8, s32);
void func_800C36F4(u8, s32);
void func_800C3798(u8 param_0, f32 param_1, f32 param_2);
f32 func_800C395C(u8);
int func_800C42E0();
int func_800C4B70();
void func_800C4B7C();

// Position of the listener (camera or nearest player) relative to a sound position.
void func_800C1070(s32 listener, s32 pos)
{
    s32 pad;
    s32 unk_0;
    f32 unk_1[3];

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            _plsu_entrypoint_0(listener, pos);
            return;
        }
        unk_0 = func_800F5EF8(_plsu_entrypoint_0(listener, pos));
        if (func_8010FFA8(unk_0) != 2) {
            func_8010FFB0(unk_0, listener, unk_1);
        }
    } else {
        func_800E3980(listener);
    }
}

s32 func_800C1104(s32 pos)
{
    f32 listener[3];
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            unk_0 = _plsu_entrypoint_0(listener, pos);
            if (func_800F5D18(unk_0) == 2) {
                return 1;
            }
            return 0;
        }
        unk_1 = _plsu_entrypoint_0(listener, pos);
        unk_2 = func_800F5EF8(unk_1);
        if (func_8010FFA8(unk_2) == 2) {
            if (func_800F5D18(unk_1) == 2) {
                return 1;
            }
            return 0;
        }
        if (func_8010FFD8(unk_2) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_800A5490() != 0) {
        return 1;
    }
    return 0;
}

// Set the release policy (bits 5-7 of byte 0x7A).
// Matching: the extra temporaries are needed for the match.
void func_800C11F8(u8 *slot, s32 policy)
{
    short policy_short;
    s32 policy_copy;
    policy_copy = policy;
    slot[0x7A] = (slot[0x7A] & ~0xE0) | ((policy_short = policy_copy) << 5);
}

// Set the slot state (bits 2-4 of byte 0x7A).
// Matching: the extra temporaries and the volatile pointer are needed for the match.
int func_800C1210(volatile u8 *slot, u32 state)
{
    u32 state_copy;
    unsigned short state_short;
    state_short = state;
    slot[0x7A] = (slot[0x7A] & 0xFFE3) | (((state_copy = state_short) << 2) & 0x1C);
}

s32 func_800C122C(s32 reverb, s32 unk_0, s32 unk_1, s32 unk_2)
{
    f32 value;
    if (unk_2) {
        if (!unk_0 || !unk_1)
            return reverb;
        return reverb + 128;
    }
    if (!unk_0 || !unk_1) {
        value = (reverb + (f32) D_8011A870 * 127.0f) * (f32) D_8011A874;
        return MAX_C(0.0f, MIN_C(127.0f, value));
    }
    value = (reverb + (f32) D_8011A870 * 127.0f) * (f32) D_8011A874;
    return MAX_C(0.0f, MIN_C(127.0f, value)) + 128.0f;
}

// Set, clear and test bits of the slot flag halfword (offset 0x7C).
void func_800C13A0(u16 *slot, unsigned int mask)
{
    slot[0x3E] |= mask;
}

void func_800C13B0(u16 *slot, unsigned long mask)
{
    slot[0x3E] &= ~mask;
}

int func_800C13C4(u16 *slot, unsigned long mask)
{
    return slot[0x3E] & mask;
}

s32 func_800C13D0(u8 *slot, s32 mask)
{
    return (*(u16 *) ((s8 *) slot + 0x7C) & mask) == 0;
}

// Mark all 60 slots as unused.
void func_800C13E4(void)
{
    s32 i;
    s32 j;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 4; j++) {
            ((E_C13E4 *) D_80128B90)[i].sub[j].unk78 = 0;
        }
    }
}

// Pointer to the 0x80-byte slot with the given id.
S_C3B8C *func_800C1414(u8 id)
{
    return (id << 7) + (u8 *) D_80128B90;
}

// Address of the voice entry for a 1-based voice handle.
int func_800C1430(s32 handle)
{
    return (int) &D_80128B10[handle - 1];
}

int func_800C1448(handle)
s32 handle;
{
    return D_80128B10[handle - 1].local_0;
}

// Allocate a free slot (ids 1..59); returns 0 if none is free.
u8 func_800C145C(void)
{
    s32 i;
    for (i = 1; i < 0x3C; i++) {
        if (((local_type_800C145C *) D_80128B90)[i].local_1 == 0) {
            ((local_type_800C145C *) D_80128B90)[i].local_1 = 1;
            return i;
        }
    }
    return 0;
}

// Release a voice handle.
int func_800C1568(s32 handle)
{
    *(s32 *) ((char *) D_80128B0C + handle * 8) = 0;
}

// Clear all 16 voice handles.
void func_800C157C(void)
{
    s32 i;
    for (i = 0; i < 16; i++) {
        ((s32(*)[2]) D_80128B10)[i][0] = 0;
        ((s32(*)[2]) D_80128B10)[i][1] = 0;
    }
}

// Allocate a free voice handle (1-based); returns 0 if all 16 are in use.
s32 func_800C15BC(void)
{
    s32 used;
    s32 i;
    do {
        used = 0;
        for (i = 0; i < 16; i++) {
            if (D_80128B10[i].local_1 != 0)
                used++;
            else if (D_80128B10[i].local_0 == 0) {
                D_80128B10[i].local_1 = 1;
                return i + 1;
            }
        }
    } while (used < 16);
    return 0;
}

// Free a slot and its voice handle.
void func_800C16A4(u8 id)
{
    u8 *slot;

    slot = func_800C1414(id);
    if (*(u8 *) ((char *) slot + 0x79) != 0) {
        func_800C1568(*(u8 *) ((char *) slot + 0x79));
        *(u8 *) ((char *) slot + 0x79) = 0;
    }
    D_80128C08[id << 7] = 0;
}

// Start the voice of a slot using the given voice handle.
void func_800C16F8(LocalSound_800C16F8 *slot, s32 handle)
{
    s32 unk_0;
    s32 reverb;

    if (handle) {
        if (slot->field79) {
            func_800C1568(slot->field79);
        }
        slot->field79 = (u16) handle;
        func_800C1210(slot, 1);
        func_800C13A0(slot, 4);
        func_800C13A0(slot, 8);
        func_800C13A0(slot, 16);
        slot->field20 = -1;
        slot->field24 = -1;
        if (func_800CCEF4(slot, &slot->field20, &slot->field24, 0, 0)) {
            if (func_800CBC00(slot->field20)) {
                switch (func_800CBBE0(slot->field20)) {
                    case 2:
                        slot->field60 = 25;
                        break;
                    case 3:
                        slot->field60 = 20;
                        break;
                    case 4:
                        slot->field60 = 15;
                        break;
                    case 5:
                        slot->field60 = 10;
                        break;
                    case 6:
                        slot->field60 = 5;
                        break;
                }
            }
        }
        unk_0 = func_800C13C4(slot, 0x400);
        reverb = func_800C122C(slot->field60, slot->field1B, slot->field1C, unk_0);
        func_800DC3D4(slot->field58 - 1001, slot->field6C, slot->field5A, slot->field61,
                      reverb, func_800C1430(slot->field79));
    }
}

// Stop the voice of a slot that is playing.
// Matching: the dummy label is needed for the match.
void func_800C1860(u8 *slot)
{
    u32 *flags_ptr;
    u32 flags;
    u8 handle;
    flags_ptr = (u32 *) ((char *) slot + 0x78);
    flags = *flags_ptr;
    if ((((flags << 7) << 12) >> 29) == 1) {
        func_800C13B0(slot, 0x20);
        func_800C1210(slot, 2);
        goto dummy_label_658801;
    dummy_label_658801:;
        handle = *(u8 *) ((char *) slot + 0x79);
        if (handle) {
            func_800DC4D4(func_800C1448(handle));
        }
    }
}

// Set the reverb of a voice.
void func_800C18C8(s32 handle, s32 reverb, s32 unk_0, s32 unk_1, s32 unk_2)
{
    if (handle != 0) {
        func_800DC48C(func_800C1448(handle), func_800C122C(reverb, unk_0, unk_1, unk_2));
    }
}

// Set the pan of a voice.
s32 func_800C191C(handle, pan)
s32 handle;
s32 pan;
{

if (handle) {
    func_800DC4B0(func_800C1448(handle), pan);
}

}

// Set the pitch of a voice.
// Matching: the "| 0" is needed for the match.
int func_800C1950(handle, pitch)
s32 handle;
s32 pitch;
{
    if (handle != 0) {
        func_800DC42C(func_800C1448(handle) | 0, pitch);
    }

}

// Set the volume of a voice; scaled by the global volume factor unless unscaled.
// Matching: "voice | voice" and reusing the local for the voice id are needed for the match.
void func_800C1984(s32 handle, s32 volume, s32 unscaled)
{
    s32 voice;
    voice = handle;

if (voice != 0) {
    if (unscaled == 0) {
        volume *= D_8011A878;
    }
    voice = func_800C1448(voice);
    func_800DC454(voice | voice, volume & 0xFFFF);
}

}

// Volume by distance to the listener: full inside the inner radius, fading to the
// far volume (s16 at 0x18) at the outer radius. Radii are squared.
// Matching: the delta vector is addressed through the neighbouring local; needed for the match.
s32 func_800C19E4(u8 *slot, s32 volume)
{
    s8 delta[8];
    s32 listener;
    s32 delta_tail;
    f32 dist_sq;
    f32 inner_sq;
    f32 outer_sq;
    s16 far_volume;
    s32 result;

    func_800C1070(&listener, slot);
    func_800EFB24((u8 *) &delta_tail - 8, slot, &listener);
    dist_sq = func_800EEFD4((u8 *) &delta_tail - 8);
    inner_sq = (*(f32 *) ((s8 *) slot + 0xC));

if (dist_sq < inner_sq) {
    result = volume;
} else {

outer_sq = (*(f32 *) ((s8 *) slot + 0x10));

if (dist_sq < outer_sq) {
    far_volume = *(s16 *) ((s8 *) slot + 0x18);
    result = (s32) ((f32) far_volume +
                    (((outer_sq - dist_sq) / (outer_sq - inner_sq)) * (f32) (volume - far_volume)));
} else {

result = (s32) (*(s16 *) ((s8 *) slot + 0x18));
}
}
return result;
}

// Compute the pan of a slot from its angle relative to the camera.
void func_800C1AA4(SoundC *slot)
{
    f32 camera_pos[3];
    f32 delta[3];
    f32 angles[3];
    f32 rotated[3];
    f32 camera_rot[3];
    s32 tmp;
    func_800E3980(camera_pos);
    func_800EFB24(delta, slot->local_0, camera_pos);
    if (delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2] < 10.0f) {
        slot->local_3 = 64.0f;
    } else {
        slot->local_5[2] = slot->local_5[3];
        if (!slot->local_5[2]) {
            func_800E3A58(camera_rot);
            camera_rot[1] = -camera_rot[1];
            camera_rot[0] = -camera_rot[0];
            camera_rot[2] = -camera_rot[2];
            func_800EF7B0(rotated, camera_rot, delta[0], delta[1], delta[2]);
            func_800F1EA4(rotated, angles);
            angles[0] = 180.0f - angles[0];

if (angles[0] < -90.0f) {
    angles[0] = -180.0f - angles[0];
    if (slot->local_5[1])
        slot->local_5[2] = 1;
} else if (angles[0] > 90.0f) {

angles[0] = 180.0f - angles[0];
if (slot->local_5[1])
    slot->local_5[2] = 1;
}
}
tmp = func_800C13C4(slot, 0x400);
func_800C18C8(slot->local_24.local_0.local_1, slot->local_17, slot->local_5[1],
              slot->local_5[2], tmp);
tmp = angles[0] * 0.7f + 64.0f;
if (slot->local_5[0])
    slot->local_3 += 0.07f * (tmp - slot->local_3);
else
    slot->local_3 = tmp;
}
func_800C191C(slot->local_24.local_0.local_1, (s32) slot->local_3);
}

s32 func_800C1CCC(Struct_800C1CCC *slot, s32 volume)
{
    s32 unk_0;
    if (func_800C13C4(slot, 0x40) != 0) {
        unk_0 = func_800C1104(slot);
        if (func_800C13C4(slot, 0x80) != 0) {
            if (unk_0 == 1) {
                volume = volume * slot->unk74;
            }
        } else if (unk_0 == 0) {
            volume = volume * slot->unk70;
        }
    }
    return volume;
}

// Apply pending pitch, reverb, volume and pan changes to the voice of a slot.
// Returns nonzero when the sound is nearly silent.
s32 func_800C1D80(u8 id)
{
    s32 quiet;
    s32 volume;
    s32 unk_0;
    s32 context_changed;
    u8 *slot;

    quiet = 0;
    slot = func_800C1414(id);
    if ((((u32) (*(s32 *) ((s8 *) (slot) + 0x78)) << 0x13) >> 0x1D == 1) &&
        (*(u8 *) ((s8 *) (slot) + 0x79) != 0)) {
        context_changed = func_800EA05C() != (*(s16 *) ((s8 *) (slot) + 0x5E));
        // Matching: the "- 0" and the unsigned compare are needed for the match.
        if ((u32) (func_800C13C4(slot, 4) - 0) > 0) {
            func_800C1950((*(u8 *) ((s8 *) (slot) + 0x79)),
                          (*(s32 *) ((s8 *) (slot) + 0x6C)));
        }
        if ((func_800C13C4(slot, 0x10) != 0) && ((*(u8 *) ((s8 *) (slot) + 0x1B)) == 0)) {
            func_800C18C8((*(u8 *) ((s8 *) (slot) + 0x79)), (*(u8 *) ((s8 *) (slot) + 0x60)),
                          (*(u8 *) ((s8 *) (slot) + 0x1B)), (*(u8 *) ((s8 *) (slot) + 0x1C)),
                          func_800C13C4(slot, 0x400));
        }
        if (func_800C13C4(slot, 2) != 0) {
            if (context_changed != 0) {
                func_800C1984((*(u8 *) ((s8 *) (slot) + 0x79)),
                              (*(s16 *) ((s8 *) (slot) + 0x5C)), func_800C13C4(slot, 0x200));

}
else
{
    if (*(u8 *) ((s8 *) slot + 0x63) != 0) {
        volume = func_800C19E4(slot, *(s16 *) ((s8 *) slot + 0x5A));
    } else {

volume = (*(s16 *) ((s8 *) (slot) + 0x5A));
}
if (volume < 0x64) {
    quiet = 1;
}
volume = func_800C1CCC(slot, volume);
(*(s16 *) ((s8 *) (slot) + 0x5C)) = volume;
func_800C1984((*(u8 *) ((s8 *) (slot) + 0x79)), volume, func_800C13C4(slot, 0x200));
if (func_800EA068(0x20) == 0) {
    func_800C1AA4(slot);
}
}
}
else
{
    if (func_800C13C4(slot, 0x100) != 0) {
        func_800C191C((*(u8 *) ((s8 *) (slot) + 0x79)), (*(u8 *) ((s8 *) (slot) + 0x61)));
    }
    if (context_changed != 0) {
        func_800C1984((*(u8 *) ((s8 *) (slot) + 0x79)), (*(s16 *) ((s8 *) (slot) + 0x5C)),
                      func_800C13C4(slot, 0x200));
    } else if (func_800C13C4(slot, 8) != 0) {
        volume = func_800C1CCC(slot, (*(s16 *) ((s8 *) (slot) + 0x5A)));
        (*(s16 *) ((s8 *) (slot) + 0x5C)) = volume;
        if (volume < 0x64) {
            quiet = 1;
        }
        func_800C1984((*(u8 *) ((s8 *) (slot) + 0x79)), volume, func_800C13C4(slot, 0x200));
    }
}
func_800C13B0(slot, 4);
func_800C13B0(slot, 8);
func_800C13B0(slot, 0x10);
}
if (func_800A8184() == 4) {
    quiet += 1;
}
return quiet;
}

// Per-frame update of a slot: volume envelope, pitch mode, release policy, voice start/stop.
void func_800C2000(u8 id)
{
    LocalSound_800C2000 *slot;
    s32 quiet;
    f32 dt;
    s32 handle;
    s32 bound, current;
    f32 t;

    dt = func_800D8FF8();
    slot = func_800C1414(id);
    slot->elapsed += dt;
    if (slot->flags.bits.stopping) {
        if (slot->decay == 0.0f) {
            slot->volume = 0;
        } else {
            slot->volume -= (slot->maximum / slot->decay) * dt;
            slot->volume = func_800F0E28(0, slot->volume);
            if (func_800EA05C() != slot->context) {
                slot->limit = func_800F1418(slot->limit, slot->volume);
            }
        }
        if (slot->volume <= 0) {
            func_800C2FDC(id);
            return;
        }
        func_800C13A0(slot, 8);
    } else if (slot->flags.bits.envelope) {
        if (slot->elapsed < slot->attack) {
            slot->volume =
                (slot->elapsed / slot->attack) * (slot->minimum + slot->maximum) / 2;
        } else if (slot->elapsed <= slot->attack + slot->hold) {
            if (slot->volume < slot->minimum || slot->maximum < slot->volume) {
                slot->volume = (slot->minimum + slot->maximum) / 2;
            }
            slot->volume += func_800DC264(-1.0f, 1.0f) * slot->drift;
            // Matching: the clamp goes through temporaries instead of MIN_C/MAX_C.
            current = slot->volume;
            bound = slot->maximum;
            slot->volume = bound < current ? bound : current;
            current = slot->volume;
            bound = slot->minimum;
            slot->volume = current < bound ? bound : current;
        } else {
            slot->volume =
                (1.0f - (slot->elapsed - slot->attack - slot->hold) / slot->decay) *
                (slot->minimum + slot->maximum) / 2;
        }
        if (func_800EA05C() != slot->context) {
            slot->limit = func_800F1418(slot->limit, slot->volume);
        }
        func_800C13A0(slot, 8);
    }
    if (slot->flags.bits.timed &&
        slot->attack + slot->hold + slot->decay <= slot->elapsed) {
        if (slot->flags.bits.release) {
            func_800C2FDC(id);
            return;
        }
        func_800C1860(slot);
    }
    if (slot->flags.bytes.handle && slot->flags.bits.state == 1 &&
        func_800C1448(slot->flags.bytes.handle)) {
        // Pitch modes: 0 constant, 1 sweep, 2 random wobble, 3 and 4 curves.
        switch (slot->flags.bits.mode) {
            case 0:
                break;
            case 1:
                slot->pitch += slot->field_28 * dt;
                if (slot->field_28 > 0.0f) {
                    slot->pitch = func_800F13F0(slot->pitch, slot->field_2C);
                } else {
                    slot->pitch = func_800F0E00(slot->pitch, slot->field_2C);
                }
                func_800C13A0(slot, 4);
                break;
            case 2:
                slot->pitch += func_800DC264(-slot->field_30, slot->field_30) * dt;
                slot->pitch =
                    func_800F0D50(slot->pitch, slot->field_2C, slot->field_28);
                func_800C13A0(slot, 4);
                break;
            case 3:
                slot->pitch =
                    func_800F10B4(slot->elapsed, slot->field_28, slot->field_2C,
                                  slot->field_30, slot->field_34);
                func_800C13A0(slot, 4);
                break;
            case 4:
                t = slot->elapsed;
                if (t < slot->field_28) {
                    slot->pitch = func_800F10B4(t, 0.0f, slot->field_28,
                                                   slot->field_34, slot->field_38);
                } else if (t < slot->field_28 + slot->field_2C) {
                    slot->pitch = slot->field_38;
                } else {
                    slot->pitch =
                        func_800F10B4(t - (slot->field_28 + slot->field_2C), 0.0f,
                                      slot->field_30, slot->field_38, slot->field_3C);
                }
                func_800C13A0(slot, 4);
        }
    }
    switch (slot->flags.bits.policy) {
        case 1:
            if (slot->flags.bits.state == 0 ||
                (slot->flags.bits.state == 1 && !slot->flags.bytes.handle)) {
                func_800C2FDC(id);
                return;
            }
            break;
        case 2:
            if (slot->flags.bits.state == 1 && func_800C13D0(slot, 1))
                func_800C3CE8(id);
            else
                func_800C13B0(slot, 1);
        case 3:
            break;
    }
    quiet = func_800C1D80(id);
    if (slot->flags.bits.state == 1 && func_800C42E0(slot->sound)) {
        if (func_800C13C4(slot, 0x20)) {
            if (!quiet) {
                handle = func_800C15BC();
                osSetThreadPri(0, 0x33);
                func_800C16F8(slot, handle);
                func_800C13B0(slot, 0x20);
                func_800C1D80(id);
                osSetThreadPri(0, 0x14);
            }
        } else if (quiet) {
            func_800C1860(slot);
            func_800C1210(slot, 1);
            func_800C13A0(slot, 0x20);
        }
    }
    if (slot->flags.bytes.handle && !func_800C1448(slot->flags.bytes.handle)) {
        func_800C1568(slot->flags.bytes.handle);
        slot->flags.bytes.handle = 0;
    }
}

// Returns 1 when a finished slot (state 3) has no live voice left.
// Matching: the constants held in locals are needed for the match.
s32 func_800C269C(u8 id)
{
    int handle_offset;
    int shift;
    s32 flags_copy;
    u8 *slot;
    s32 flags;
    slot = func_800C1414(id);
    shift = 0x1D;
    flags = *((s32 *) (((char *) slot) + 0x78));
    handle_offset = 0x79;
    flags_copy = *((s32 *) (((char *) slot) + 0x78));
    if ((((u32) (flags << 0x13)) >> shift) != 3) {
        return 0;
    }
    if ((*((u8 *) (((char *) slot) + handle_offset))) == 0) {
        return 1;
    }
    if (func_800C1448(*((u8 *) (((char *) slot) + handle_offset))) != 0) {
        return 0;
    }
    return 1;
}

// Per-frame update of all active slots; eases the global volume factor D_8011A878 between 0.5 and 1.
void func_800C2718()
{
    s32 id, unk_0, unk_1;
    local_type_800C2718 *slot;
    if (func_800C0638()) {
        D_8011A878 -= func_800D8FF8();
        if (D_8011A878 < 0.5f) {
            D_8011A878 = 0.5f;
        }
    } else {
        D_8011A878 += func_800D8FF8();
        if (D_8011A878 > 1.0f) {
            D_8011A878 = 1.0f;
        }
    }
    slot = ((local_type_800C2718 *) &D_80128C10);
    id = 1;
    do {
        if (slot->local_1 != 0) {
            if (slot->local_3 != 3) {
                func_800C2000(id);
            }
            if (func_800C269C(id)) {
                func_800C16A4(id);
            }
        }
        slot++;
        id++;
    } while (id < 0x3C);
}

// Allocate a slot and play a simple sound with the given parameters.
void func_800C2840(s32 sfx_id, f32 pitch, s32 volume, s32 reverb, s32 unk_0)
{
    s32 result;
    u8 slot_id;
    result = func_800C2E04();
    slot_id = result;
    if (result != 0) {
        func_800C301C(slot_id, sfx_id);
        func_800C3058(slot_id, volume);
        func_800C31DC(slot_id, pitch);
        func_800C32C4(slot_id, reverb);
        func_800C330C(slot_id, 1);
        func_800C3418(slot_id, unk_0);
        func_800C36F4(slot_id, 0);
        func_800C3BDC(slot_id);
    }
}

// Reset all voice handles and slots.
void func_800C28D8()
{
    func_800C157C();
    func_800C13E4();
}

// Stop all slots and update until none is active.
void func_800C2900(void)
{
    s32 i;
    s32 active;
    for (i = 1; i < 60; i++) {
        if (((SoundSlotC *) D_80128B90)[i].local_0)
            func_800C2FDC(i);
    }
    do {
        active = 0;
        func_800C2718();
        for (i = 1; i < 60; i++) {
            if (((SoundSlotC *) D_80128B90)[i].local_0)
                active++;
        }
    } while (active);
}

int func_800C2A08()
{
    func_800C28D8();
    func_800C4308(0.0f, 1.0f);
    func_800C4B64(1.0f);
    func_800C4B70(0x55F0);
    func_800C4B7C(-1);
}

void func_800C2A5C(s32 unk_0, s32 unk_1)
{
}
void func_800C2A68()
{
    func_80017244();
    func_80016E7C();
}

void func_800C2A90()
{
    func_800C2900();
    func_800C2A68();
}

// Free all finished slots; repeats until none is waiting for its voice.
void func_800C2AB8(void)
{
    s8 *slot;
    s32 slot_id;
    s32 index;
    s32 pending;
    func_800C2B80();
    do {
        slot = (s8 *) (&D_80128C10);
        index = 1;
        pending = 0;
    loop_2:
        if ((*((u8 *) (slot + 0x78))) != 0) {
            slot_id = index & 0xFF;
            if ((((u32) (((s32) (*((s32 *) (slot + 0x78)))) << 0x13)) >> 0x1D) == 3) {
                if (func_800C269C(index & 0xFF) != 0) {
                    func_800C16A4(slot_id);
                } else {
                    pending += 1;
                }
            }
        }

        index += 1;
        slot += 0x80;
        if (index != 0x3C) {
            goto loop_2;
        }
    } while (pending != 0);
}

// Tick per-slot countdowns (255 means none); stop a slot at zero.
void func_800C2B80(void)
{
    s32 i;
    for (i = 1; i < 60; i++) {
        if (!D_80128B90[i].local_5)
            continue;
        if (D_80128B90[i].local_7 == 3)
            continue;
        if (D_80128B90[i].local_3 == 255)
            continue;
        {
            if (!D_80128B90[i].local_3)
                func_800C2FDC(i);
            else if (--D_80128B90[i].local_3 == 0) {
                D_80128B90[i].local_1 = 0.0f;
                D_80128B90[i].local_9 = 1;
            }
        }
    }
}

// Set a newly allocated slot to its default values.
void func_800C2C4C(u8 id)
{
    SoundC *slot;
    slot = func_800C1414(id);
    slot->local_21 = 0;
    slot->local_13 = -1;
    slot->local_15 = 0;
    slot->local_14 = 0x55F0;
    slot->local_17 = 0;
    slot->local_18 = 0x3F;
    slot->local_24.local_0.local_1 = 0;
    slot->local_19 = 0xFF;
    slot->local_23 = 1.0f;
    slot->local_16 = func_800EA05C();
    slot->local_20 = 1;
    slot->local_24.local_1.local_3 = 0;
    slot->local_24.local_1.local_5 = 0;
    slot->local_8 = 3.0f;
    slot->local_24.local_1.local_8 = 1;
    slot->local_24.local_1.local_6 = 0;
    slot->local_24.local_1.local_4 = 0;
    slot->local_24.local_1.local_7 = 0;
    slot->local_6 = 1.0f;
    slot->local_7 = 1.0f;
    slot->local_12 = 0.0f;
    func_800C1210(slot, 0);
    func_800C11F8(slot, 0);
    func_800C13A0(slot, 1);
    func_800C13A0(slot, 4);
    func_800C13A0(slot, 8);
    func_800C13A0(slot, 0x10);
    slot->local_1 = 6.25e+04f;
    slot->local_2 = 1.44e+06f;
    slot->local_3 = 64.0f;
    slot->local_4 = 10;
    slot->local_5[0] = 0;
    slot->local_5[1] = 0;
    slot->local_5[2] = 0;
    slot->local_5[3] = 0;
    func_800EFD24(slot->local_0);
    func_800C13B0(slot, 2);
    func_800C13B0(slot, 0x20);
    func_800C13B0(slot, 0x200);
    func_800C13B0(slot, 0x400);
    func_800C3418(id, 2);
    func_800C3798(id, 0.2f, 0.1f);
}

// Allocate and initialise a slot; returns 0 if none is free.
u8 func_800C2E04()
{
    u8 id;
    id = func_800C145C();
    if (!id) {
        return 0;
    }
    func_800C2C4C(id);
    return id;
}

void func_800C2E40(u8 id)
{
    SoundC *slot;
    func_800C3CE8(id);
    slot = func_800C1414(id);
    slot->local_21 = 0;
    slot->local_13 = -1;
    slot->local_15 = 0;
    slot->local_14 = 0x55F0;
    slot->local_17 = 0;
    slot->local_18 = 0x3F;
    slot->local_19 = 0xFF;
    slot->local_23 = 1.0f;
    slot->local_16 = func_800EA05C();
    slot->local_20 = 1;
    slot->local_24.local_1.local_3 = 0;
    slot->local_24.local_1.local_5 = 0;
    slot->local_8 = 3.0f;
    slot->local_24.local_1.local_8 = 1;
    slot->local_24.local_1.local_6 = 0;
    slot->local_24.local_1.local_4 = 0;
    slot->local_24.local_1.local_7 = 0;
    slot->local_6 = 1.0f;
    slot->local_7 = 1.0f;
    slot->local_12 = 0.0f;
    func_800C1210(slot, 0);
    func_800C11F8(slot, 0);
    func_800C13A0(slot, 1);
    func_800C13A0(slot, 4);
    func_800C13A0(slot, 8);
    func_800C13A0(slot, 0x10);
    slot->local_1 = 6.25e+04f;
    slot->local_2 = 1.44e+06f;
    slot->local_3 = 64.0f;
    slot->local_4 = 10;
    slot->local_5[0] = 0;
    slot->local_5[1] = 0;
    func_800EFD24(slot->local_0);
    func_800C13B0(slot, 2);
    func_800C13B0(slot, 0x20);
    func_800C3418(id, 2);
    func_800C3798(id, 0.2f, 0.1f);
}

// Stop a slot and mark it finished (state 3).
// Matching: the volatile local is needed for the match.
s32 func_800C2FDC(u8 id)
{
    volatile u8 *slot;
    slot = func_800C1414(id);
    func_800C3CE8(id);
    func_800C1210(slot, 3);
    return 0;
}

void func_800C301C(u8 id, s32 sfx_id)
{
    if (id != 0) {
        s8 *slot = func_800C1414(id);
        *(s16 *) ((char *) slot + 0x58) = sfx_id;
    }
}

// Set the volume; without an envelope the min/max volume follow it.
int func_800C3058(u8 id, unsigned int volume)
{
    Actor *slot;
    if (id != 0) {
        slot = func_800C1414(id);
        *((s16 *) (((char *) slot) + 0x5A)) = volume;
        if ((((u32) (*(s32 *) (((char *) slot) + 0x78) << 28) >> 31) == 0)) {
            *((s16 *) (((char *) slot) + 0x4C)) = volume;
            *((s16 *) (((char *) slot) + 0x4E)) = volume;
            *((f32 *) (((char *) slot) + 0x50)) = 0.0f;
        }
        func_800C13A0(slot, 8);
    }
}

// Set the volume scaled by the distance to the listener: full up to near_dist, silent from far_dist.
void func_800C30B8(s32 id, s32 volume, f32 *pos, f32 near_dist, f32 far_dist)
{
    f32 listener[3];
    f32 scale;
    f32 dist;
    func_800C1070(listener, pos);
    dist = func_800EEAD4(pos, listener);
    if (far_dist <= dist)
        scale = 0.0f;
    else if (near_dist <= dist)
        scale = 1.0f - (dist - near_dist) / (far_dist - near_dist);
    else
        scale = 1.0f;
    func_800C3058((u8) id, (s32) (volume * scale));
}

// Enable the volume envelope with the given min/max volume and drift.
void func_800C316C(u8 id, s32 minimum, s32 maximum, f32 drift)
{
    S800C316C *slot;
    if (id != 0) {
        slot = func_800C1414(id);
        slot->flag = 1;
        slot->unk4C = minimum;
        slot->unk4E = maximum;
        slot->unk50 = drift;
        slot->unk5A = 0;
        func_800C13A0(slot, 8);
    }
}

// Set the pitch.
void func_800C31DC(u8 id, f32 pitch)
{
    u8 *slot;
    if (id != 0) {
        slot = func_800C1414(id);
        *(f32 *) ((u8 *) slot + 0x6C) = pitch;
        func_800C13A0(slot, 4);
    }
}

// Random-walk the pitch within [min_pitch, max_pitch]; step back into the range when outside.
void func_800C3224(u8 id, f32 min_pitch, f32 max_pitch, f32 step)
{
    f32 pitch;
    pitch = func_800C395C(id);
    if (pitch < min_pitch)
        pitch += step;
    else if (max_pitch < pitch)
        pitch -= step;
    else {
        pitch += func_800DC264(-step, step);
        pitch = func_800F0D50(pitch, min_pitch, max_pitch);
    }
    func_800C31DC(id, pitch);
}

// Set the reverb.
void func_800C32C4(u8 id, s32 reverb)
{
    u8 *slot;
    if (id != 0) {
        slot = func_800C1414(id);
        *(u8 *) (slot + 0x60) = reverb;
        func_800C13A0(slot, 0x10);
    }
}

// Set the release policy.
void func_800C330C(u8 id, s32 policy)
{
    u8 *slot;
    if (id != 0) {
        slot = func_800C1414(id);
        func_800C11F8(slot, policy);
    }
}

// Set a fixed pan.
void func_800C334C(u8 id, s32 pan)
{
    u8 *slot;
    if (id != 0) {
        slot = func_800C1414(id);
        *(u8 *) (slot + 97) = pan;
        func_800C13A0(slot, 0x100);
    }
}

void func_800C3394(u8 handle, s32 unk_0, s32 unk_1)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        *(s32 *) (slot + 0x64) = unk_0;
        *(s32 *) (slot + 0x68) = unk_1;
    }
}

void func_800C33DC(u8 handle, s32 positional)
{
    if (handle != 0) {
        s8 *slot = func_800C1414(handle);
        slot[0x1B] = (s8) positional;
    }
}

void func_800C3418(u8 handle, s32 mode)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        switch (mode) {
            case 0:
                func_800C13B0(slot, 0x40);
                func_800C13B0(slot, 0x80);
                return;

            case 1:
                func_800C13A0(slot, 0x40);
                func_800C13B0(slot, 0x80);
                return;

            case 2:
                func_800C13A0(slot, 0x40);
                func_800C13A0(slot, 0x80);
        }
    }
}

void func_800C34CC(u8 handle, s32 flag)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        if (flag != 0) {
            func_800C13B0(slot, 0x200);
        } else {
            func_800C13A0(slot, 0x200);
        }
    }
}

void func_800C3528(u8 handle, s32 flag)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        if (flag != 0) {
            func_800C13A0(slot, 0x400);
        } else {
            func_800C13B0(slot, 0x400);
        }
    }
}

void func_800C3584(u8 handle, f32 min_dist, f32 max_dist)
{
    void *slot;
    if (handle) {
        slot = func_800C1414(handle);
        *(f32 *) ((char *) slot + 0xc) = min_dist * min_dist;
        *(f32 *) ((char *) slot + 0x10) = max_dist * max_dist;
        func_800C368C(handle, 1);
    }
}

void func_800C35E8(u8 handle, s32 pos)
{
    void *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        func_800EE7F8(slot, pos);
        func_800C368C(handle, 1);
        *(s16 *) ((u8 *) slot + 0x5E) = func_800EA05C();
    }
}

void func_800C3648(u8 handle, s32 unk_0)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        *(u16 *) (slot + 0x5E) = func_800EA05C();
    }
}

void func_800C368C(u8 handle, s32 positional)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        if (positional != 0) {
            func_800C13A0(slot, 0x2);
        } else {
            func_800C13B0(slot, 0x2);
        }
        func_800C33DC(handle, positional);
    }
}

void func_800C36F4(u8 handle, s32 value)
{
    if (handle != 0) {
        s8 *slot = func_800C1414(handle);
        slot[0x62] = (s8) value;
    }
}

void func_800C3730(u8 handle, f32 pitch, f32 unk_0, f32 unk_1)
{
    s32 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        // Matching: the comma expression in the offset is needed for the match.
        *((u16 *) (((u8 *) slot) + 0x7a)) =
            ((*((u16 *) (((u8 *) slot) + ((0, 0x7a))))) & 0xfc3f) | 0x40;
        *((f32 *) (((u8 *) slot) + 0x28)) = unk_1;
        *((f32 *) (((u8 *) slot) + 0x2c)) = unk_0;
        func_800C31DC(handle, pitch);
    }
}

void func_800C3798(u8 handle, f32 unk_0, f32 unk_1)
{
    u8 *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        *(f32 *) (slot + 0x70) = unk_0;
        *(f32 *) (slot + 0x74) = unk_1;
    }
}

void func_800C37E0(u8 handle, f32 pitch_a, f32 pitch_b, f32 unk_0)
{
    void *slot;
    if (handle != 0) {
        slot = func_800C1414(handle);
        *((u16 *) (((u8 *) slot) + 0x7A)) =
            ((*((u16 *) (((u8 *) slot) + 0x7A))) & 0xFC3F) | 0x80;
        *((f32 *) (((u8 *) slot) + 0x30)) = unk_0;
        *((f32 *) (((u8 *) slot) + 0x2C)) = pitch_a;
        *((f32 *) (((u8 *) slot) + 0x28)) = pitch_b;
        func_800C31DC(handle, (pitch_a + pitch_b) * 0.5f);
    }
}

void func_800C3868(u8 handle, f32 unk_0, f32 unk_1, f32 pitch, f32 unk_2)
{
    struct SomeStruct *slot;

    if (handle != 0) {
        slot = (struct SomeStruct *) func_800C1414(handle);
        slot->unk7A = (slot->unk7A & 0xFC3F) | 0xC0;
        slot->unk28 = unk_0;
        slot->unk2C = unk_1;
        slot->unk30 = pitch;
        slot->unk34 = unk_2;
        func_800C31DC(handle, pitch);
    }
}

// Returns the sfx id.
s16 func_800C38E4(u8 handle)
{
    if (handle == 0) {
        return 0;
    }
    return *(s16 *) ((u8 *) func_800C1414(handle) + 0x58);
}

// Returns the volume.
s16 func_800C3920(u8 handle)
{
    if (handle == 0) {
        return 0;
    }
    return *(s16 *) ((u8 *) func_800C1414(handle) + 0x5A);
}

// Returns the pitch (1.0 when there is no source).
f32 func_800C395C(u8 handle)
{
    if (handle == 0) {
        return 1.0f;
    }
    return *(f32 *) ((u8 *) func_800C1414(handle) + 0x6C);
}

// Returns the release policy.
s32 func_800C39A0(u8 handle)
{
    return (u32) *(u16 *) ((u8 *) func_800C1414(handle) + 0x7A) >> 0xD;
}

s32 func_800C39D0(u8 *slot)
{
    int volume;
    if (func_800C13C4(slot, 0x800) != 0) {
        return 1;
    }
    if (((*((u8 *) (((s8 *) slot) + 0x63))) != 0) && (func_800C13C4(slot, 2) != 0)) {
        volume = func_800C19E4(slot, *((s16 *) (((s8 *) slot) + 0x5A)));
    } else {
        volume = *((s16 *) (((s8 *) slot) + 0x5A));
    }
    return volume >= 0x65;
}

// Starts a volume envelope from attack, hold and decay times.
void func_800C3A40(u8 handle, f32 attack, f32 hold, f32 decay)
{
    SoundC *slot;
    if (!handle)
        return;
    slot = func_800C1414(handle);
    slot->local_24.local_1.local_5 = 1;
    slot->local_24.local_1.local_8 = 1;
    slot->local_6 = attack;
    slot->local_7 = decay;
    slot->local_8 = hold;
    slot->local_12 = 0;
    if (!slot->local_24.local_1.local_6) {
        slot->local_24.local_1.local_6 = 1;
        slot->local_9 = slot->local_14;
        slot->local_10 = slot->local_14;
        slot->local_14 = 0;
        slot->local_11 = 0.0f;
    }
}

// Scales the source volume.
void func_800C3AE0(u8 handle, f32 scale)
{
    SoundC *slot;
    if (!handle)
        return;
    slot = func_800C1414(handle);
    if (slot->local_24.local_1.local_6) {
        slot->local_9 *= scale;
        slot->local_10 *= scale;
    } else {
        slot->local_14 *= scale;
    }
}

void func_800C3B8C(u8 handle, s32 flag)
{
    if (handle != 0) {
        func_800C1414(handle)->bit = flag;
    }
}

// Starts playback of the source.
void func_800C3BDC(u8 handle)
{
    local_type_800C3BDC *slot;
    u32 voice;
    if (handle != 0) {
        slot = func_800C1414(handle);
        if (slot->local_7) {
            func_800FEC60(4);
        }
        if ((func_800C39D0(slot) != 0) ||
            (func_800C42E0(*(s16 *) ((char *) slot + 0x58)) != 0)) {
            if (slot->local_4 == 2) {
                func_800C13A0(slot, 1);
                if (slot->local_5 == 1) {
                    return;
                }
                goto block_10;
            }
            if (slot->local_5 == 1) {
                func_800C3CE8(handle);
            }
        block_10:
            voice = func_800C15BC();
            osSetThreadPri(0, 0x33);
            func_800C16F8(slot, voice);
            func_800C1D80(handle);
            osSetThreadPri(0, 0x14);
        }
    }
}

// Stops the voice and calls the stop callback.
void func_800C3CE8(u8 handle)
{
    SoundC *slot;
    if (!handle)
        return;
    slot = func_800C1414(handle);
    if (slot->local_24.local_1.local_2 != 1)
        return;
    func_800C1860(slot);
    if (slot->local_24.local_1.local_7)
        func_800FECB8(4);
    if (slot->local_21)
        slot->local_21(handle, slot->local_22);
}

// Returns nonzero while the source's voice is playing.
int func_800C3D78(u8 handle)
{
    SoundC *slot;
    if (!(handle != 0))
        return 0;
    slot = func_800C1414(handle);
    return (handle != 0) && slot->local_24.local_1.local_2 == 1 &&
           slot->local_24.local_0.local_1 && func_800C1448(slot->local_24.local_0.local_1);
}

// Returns 1 if a playing source uses the sfx id.
s32 func_800C3E00(s32 sfx_id)
{
    s32 *slot;
    s32 handle;
    slot = &D_80128C10;
    handle = 1;
loop_1:
    if ((((*((u8 *) (((s8 *) slot) + 0x78))) != 0) && (func_800C3D78(handle) != 0)) &&
        (sfx_id == (*((s16 *) (((s8 *) slot) + 0x58))))) {
        return 1;
    }

    handle += 1;
    slot += 0x20;
    if (handle == 0x3C) {
        // Matching: the "* 0" is needed for the match.
        handle = ((*((u8 *) (((s8 *) slot) + 0x78))) != 0) * 0;
        return handle;
    }
    goto loop_1;
}

void func_800C3E88(s32 sfx_id)
{
    func_800C2840(sfx_id, 1.0f, 0x55F0, 0, 2);
}

void func_800C3EB8(int sfx_id)
{
    func_800C2840(sfx_id, 1.0f, 0x55F0, 0, 0);
}

void func_800C3EE4(s32 sfx_id, s32 volume)
{
    func_800C2840(sfx_id, 1.0f, volume, 0, 2);
}

void func_800C3F14(s32 sfx_id, f32 pitch)
{
    func_800C2840(sfx_id, pitch, 0x55F0, 0, 2);
}

// Packed sfx id: id in bits 0-10, volume in bits 11-20, pitch/1024 in bits 21-31.
void func_800C3F48(u32 packed)
{
    u32 sfx_id = packed & 0x7FF;
    u32 volume = (packed >> 6) & 0x7FE0;
    u32 unk_0 = 0;
    f32 pitch = (f32) ((packed >> 21) & 0x7FF);
    pitch = pitch / (f32) 1024;
    func_800C2840(sfx_id, pitch, volume, unk_0, 2);
}

void func_800C3FC0(s32 sfx_id, f32 pitch, s32 volume)
{
    func_800C2840(sfx_id, pitch, volume, 0, 2);
}

void func_800C3FF0(s32 sfx_id, f32 pitch, s32 volume)
{
    func_800C2840(sfx_id, pitch, volume, 0, 0);
}

// Plays a positional sound unless it is farther than max_dist.
void func_800C401C(s32 sfx_id, f32 pitch, s32 volume, f32 *pos, f32 min_dist, f32 max_dist,
                   s32 mode)
{
    u8 handle;
    f32 ref_pos[3];
    func_800C1070(ref_pos, pos);
    if (!(max_dist <= func_800EEAD4(ref_pos, pos))) {
        handle = func_800C2E04();
        if (handle) {
            func_800C3418(handle, mode);
            func_800C301C(handle, sfx_id);
            func_800C3058(handle, volume);
            func_800C31DC(handle, pitch);
            func_800C3584(handle, min_dist, max_dist);
            func_800C35E8(handle, pos);
            func_800C330C(handle, 1);
            func_800C33DC(handle, 1);
            func_800C36F4(handle, 0);
            func_800C3BDC(handle);
        }
    }
}

void func_800C4104(s32 sfx_id, f32 pitch, s32 volume, s32 pos, f32 min_dist, f32 max_dist)
{
    func_800C401C(sfx_id, pitch, volume, pos, min_dist, max_dist, 2);
}

// Packed sfx id as in func_800C3F48; packed_dist holds min_dist (low 16) and max_dist (high 16).
void func_800C4140(s32 packed_sfx, f32 *pos, s32 packed_dist)
{
    func_800C401C((u32) packed_sfx & 0x7FF, (f32) (((u32) packed_sfx >> 21) & 0x7FF) / 1024,
                  ((u32) packed_sfx >> 6) & 0x7FE0, pos, (f32) ((u32) packed_dist & 0xFFFF),
                  (f32) (((u32) packed_dist >> 16) & 0xFFFF), 2);
}

void func_800C4208(s32 sfx_id, f32 pitch, s32 volume, s32 pos, f32 min_dist, f32 max_dist)
{
    func_800C401C(sfx_id, pitch, volume, pos, min_dist, max_dist, 1);
}

void func_800C4244(s32 sfx_id, f32 pitch, s32 volume, s32 pos, f32 min_dist, f32 max_dist)
{
    func_800C401C(sfx_id, pitch, volume, pos, min_dist, max_dist, 0);
}

void func_800C427C()
{
    func_800C2718();
}

// Allocates a source with the sfx id and returns its handle.
int func_800C429C(s32 sfx_id, s32 unk_0)
{
    u8 handle;
    handle = func_800C2E04();
    func_800C301C(handle, sfx_id);
    func_800C330C(handle, unk_0);
    return handle;
}

int func_800C42E0(sfx_id)
s32 sfx_id;
{
    s32 id;
    // Matching: the no-op "| 0" is needed for the match.
    id = sfx_id | 0;
    func_800DC548(0, id - 0x3E9);
}

void func_800C4308(f32 unk_0, f32 unk_1)
{
    D_8011A870 = unk_0;
    D_8011A874 = unk_1;
}

void func_800C431C(u8 handle, s32 value)
{
    *(u8 *) ((u8 *) func_800C1414(handle) + 0x63) = value;
}

// Interprets a sound script on a source; handle 0 allocates a new one.
s32 func_800C4350(u8 handle, f32 *pos, s16 *script)
{
    C4350State *local_1;
    s16 sfx_id;
    s32 local_3;
    s32 unk_0;
    s32 unk_1;
    f32 operand_0;
    f32 operand_1;
    f32 operand_2;
    f32 operand_3;
    f32 operand_4;
    f32 operand_5;
    s32 play_at_end = 0; // Deferred play request, set by opcodes.
    if (!handle) {
        unk_0 = func_800C2E04();
        handle = unk_0;
        if (!unk_0)
            return 0;
        local_1 = (C4350State *) func_800C1414(handle);
    } else
        local_1 = (C4350State *) func_800C1414(handle);
    // A position enables positional handling and records its context.
    if (pos) {
        func_800EE7F8(local_1, pos);
        func_800C13A0(local_1, 2);
        local_1->field1B = 1;
        local_1->field5E = func_800EA05C();
    }
    if (!script) {
        if (handle)
            func_800C3BDC(handle);
        return handle;
    }
    while ((local_3 = *script++) != 0) {
        switch (local_3 & 0xFF) {
            case 1: // Two distance operands, stored squared.
                operand_0 = script[0];
                operand_1 = script[1];
                if (pos) {
                    local_1->field1B = 1;
                    local_1->radiusSquared[0] = operand_0 * operand_0;
                    local_1->radiusSquared[1] = operand_1 * operand_1;
                    func_800C13A0(local_1, 2);
                }
                script += 2;
                break;
            case 2:
                local_1->field63 = C4350_IMM;
                break;
            case 32:
                if (C4350_IMM)
                    func_800C13B0(local_1, 0x200);
                else
                    func_800C13A0(local_1, 0x200);
                break;
            case 34:
                if (C4350_IMM)
                    func_800C13B0(local_1, 0x400);
                else
                    func_800C13A0(local_1, 0x400);
                break;
            case 36:
                if (C4350_IMM)
                    func_800C13A0(local_1, 0x800);
                else
                    func_800C13B0(local_1, 0x800);
                break;
            // These exits bypass the deferred play.
            case 3:
                return handle;
            case 4:
                func_800C2FDC(handle);
                return 0;
            case 5:
                local_1->field60 = C4350_IMM;
                func_800C13A0(local_1, 0x10);
                break;
            case 6:
                func_800C11F8(local_1, C4350_IMM);
                break;
            case 7:
                local_1->field62 = C4350_IMM;
                break;
            case 8:
                local_1->field61 = C4350_IMM;
                func_800C13A0(local_1, 0x100);
                break;
            case 9:
                if ((u8) C4350_IMM)
                    local_1->field1A = 1;
                else
                    local_1->field1A = 0;
                break;
            case 10:
                operand_0 = *script++ * 0.00390625f;
                local_1->field6C = operand_0;
                func_800C13A0(local_1, 4);
                break;
            // Modes select different layouts for the fractional operands.
            case 11:
                operand_0 = script[0] * 0.00390625f;
                operand_1 = script[1] * 0.00390625f;
                operand_2 = script[2] * 0.00390625f;
                script += 3;
                C4350_MODE(1);
                local_1->field6C = operand_0;
                local_1->field2C = operand_1;
                local_1->field28 = operand_2;
                func_800C13A0(local_1, 4);
                break;
            case 12:
                operand_0 = *script++ * 0.00390625f;
                operand_1 = *script++ * 0.00390625f;
                operand_2 = *script++ * 0.00390625f;
                operand_3 = *script++ * 0.00390625f;
                C4350_MODE(3);
                local_1->field28 = operand_0;
                local_1->field2C = operand_1;
                local_1->field30 = operand_2;
                local_1->field34 = operand_3;
                func_800C13A0(local_1, 4);
                break;
            case 13: { // Random value between two /256 operands.
                f32 operand_0, operand_1;
                operand_0 = script[0] * 0.00390625f;
                operand_1 = script[1] * 0.00390625f;
                script += 2;
                local_1->field6C = func_800DC264(operand_0, operand_1);
                func_800C13A0(local_1, 4);
                break;
            }
            case 29:
                operand_0 = (*((C4350Defaults *) &D_8012A990)).local_0;
                local_1->field6C = operand_0;
                func_800C13A0(local_1, 4);
                break;
            case 14:
                operand_0 = script[0] * 0.00390625f;
                operand_1 = script[1] * 0.00390625f;
                operand_2 = script[2] * 0.00390625f;
                script += 3;
                C4350_MODE(2);
                local_1->field2C = operand_0;
                local_1->field28 = operand_1;
                local_1->field30 = operand_2;
                local_1->field6C = (operand_0 + operand_1) * 0.5f;
                func_800C13A0(local_1, 4);
                break;
            case 15:
                func_800C11F8(local_1, 1);
                play_at_end = 1;
                local_1->field62 = 0;
                break;
            case 16:
                func_800C2E40(handle);
                break;
            case 17:
                play_at_end = 1;
                break;
            case 18: // Cancel the deferred play; call the stop callback if active.
                play_at_end = 0;
                if (((local_1->flags.word << 19) >> 29) == 1) {
                    func_800C1860(local_1);
                    if (local_1->callback) {
                        (local_1->callback)(handle, local_1->callbackArgument);
                    }
                }
                break;
            case 19:
                sfx_id = *script++;
                local_1->field58 = sfx_id;
                break;
            case 20:
                if (pos) {
                    local_1->field1B = C4350_IMM;
                    if (C4350_IMM)
                        func_800C13A0(local_1, 2);
                    else
                        func_800C13B0(local_1, 2);
                }
                break;
            case 21: {
                operand_0 = script[0] * 0.00390625f;
                operand_1 = script[1] * 0.00390625f;
                operand_2 = script[2] * 0.00390625f;
                script += 3;
                func_800C3A40(handle, operand_0, operand_1, operand_2);
                break;
            }
            case 31:
                local_1->field1D = 1;
                break;
            case 22:
                func_800C3058(handle, *script++);
                break;
            case 23: // Unlike the fractional opcodes, the third operand is unscaled.
                unk_0 = script[0];
                unk_1 = script[1];
                operand_0 = script[2];
                script += 3;
                func_800C316C(handle, unk_0, unk_1, operand_0);
                break;
            case 24:
                func_800C3058(handle, 0x7FFF);
                break;
            case 25:
                func_800C3058(handle, func_800DC214(script[0], script[1]));
                script += 2;
                break;
            case 30:
                func_800C3058(handle, (*((C4350Defaults *) &D_8012A990)).local_1);
                break;
            case 26:
                operand_0 = script[0] * 0.00390625f;
                operand_1 = script[1] * 0.00390625f;
                script += 2;
                local_1->field70 = operand_0;
                local_1->field74 = operand_1;
                break;
            case 27:
                func_800C3418(handle, C4350_IMM);
                break;
            case 28:
                local_1->flags.bits.enabled = 1;
                break;
            case 33:
                func_800C301C(handle, (*((C4350Defaults *) &D_8012A990)).local_2);
                break;
            case 35:
                operand_0 = *script++ * 0.00390625f;
                operand_1 = *script++ * 0.00390625f;
                operand_2 = *script++ * 0.00390625f;
                operand_3 = *script++ * 0.00390625f;
                operand_4 = *script++ * 0.00390625f;
                operand_5 = *script++ * 0.00390625f;
                C4350_MODE(4);
                local_1->field28 = operand_0;
                local_1->field2C = operand_1;
                local_1->field30 = operand_2;
                local_1->field34 = operand_3;
                local_1->field38 = operand_4;
                local_1->field3C = operand_5;
                func_800C13A0(local_1, 4);
        }
    }
    // A zero terminator plays only when an opcode requested it.
    if (play_at_end)
        func_800C3BDC(handle);
    return handle;
}

// Runs a script on a new source and plays it.
void func_800C4AF0(f32 *pos, void *script)
{
    s32 result;
    u8 handle;
    result = func_800C4350(0, pos, script);
    handle = result;
    if (result == 0) {
        return;
    }
    if (pos == 0) {
        func_800C33DC(handle, 0);
    }
    func_800C330C(handle, 1);
    func_800C36F4(handle, 0);
    func_800C3BDC(handle);
}

// Sets the default pitch used by script opcode 29.
void func_800C4B64(f32 pitch)
{
    D_8012A990 = pitch;
}

// Sets the default volume used by script opcode 30.
int func_800C4B70(volume)
int volume;
{
    // Matching: the empty block is needed for the match.
    {
    }
    D_8012A994 = volume;
}

// Sets the default sfx id used by script opcode 33.
void func_800C4B7C(sfx_id) unsigned int sfx_id;
{
    D_8012A996 = sfx_id;
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
float D_8011A870 = 0.0f;
float D_8011A874 = 1.0f;
f32 D_8011A878 = 1.0f;
