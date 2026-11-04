// Level music theme controller: picks a track variation (channel mask, BPM) from the map zone,
// section and progress flags, runs aux music tracks and ambient loops, and tracks volume ducks.
#include "core2/1ED68A0.h"

// Per-slot fade time recorded when the aux track started.
extern f32 D_80135A30[];
extern u8 D_801359D5;
// Per-slot "in use this frame" marks for the aux tracks.
extern u8 D_80135A3C[];
// Number of active aux tracks.
extern s32 D_80135A40;
// Ids of the 3 aux music tracks (0 = free slot).
extern s32 D_80135A20[];
extern s32 func_800CBBE0();
extern f32 func_800EEAD4(void *, void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800EFFB4(void *, f32, void *);
extern s32 _gcmapsects_entrypoint_7(void *);
extern f32 func_800D8FF8(void);
extern s32 D_80123F68[];
extern s32 D_80124004[];
extern s32 D_8012401C[];
extern s32 D_80124028[];
extern s32 D_80124034[];
extern s32 D_80124040[];
extern s32 D_801241D8[];
extern f32 D_801241E4[4];
extern f32 D_801241F4[3];
extern f32 D_80124200[3];
extern f32 D_8012420C[3];
extern f32 D_80124218[3];
extern s8 D_801359D1;
extern u8 D_80135A1E;
extern f32 D_80135A44;
typedef struct {
    s32 unk0;
    s32 unk4;
} E_FDBB8;
extern u8 D_80135A00;
extern E_FDBB8 D_80124224[];
typedef struct {
    u8 pad0[0x18];
    u8 unk18;
    u8 pad19[0x27];
    u8 unk40;
} G_FDC28;
typedef struct {
    f32 value_00; // Volume passed to func_800FC934.
    f32 value_04; // Multiplier for the tempo-derived value.
    s16 value_08; // Main music track id; -1 means none.
    u8 pad_0A[5];
    u8 value_0F, value_10;
    u8 pad_11[2];
    u8 value_13, value_14, pad_15, value_16, value_17, value_18;
    u8 pad_19[7];
    s16 value_20, value_22;
    u8 pad_24[4];
    s32 value_28;
    u8 pad_2C[0x10];
    f32 value_3C;
    u8 value_40, value_41;
} FDC58State;
// Track-variation entry: channel mask and BPM for each of the two variants.
typedef struct {
    s32 local_0[2];
    s16 local_1[2];
} FDC58Entry;
extern FDC58Entry D_80123E84[];
extern FDC58Entry D_80123FC8[];
extern FDC58Entry D_80124064[];
extern FDC58Entry D_801241CC;
extern FDC58Entry D_8012419C[];
extern FDC58Entry D_80124010;
extern FDC58Entry D_80124124[];
// Entry selected this frame, and the entry last applied to the tracks.
extern FDC58Entry *D_80135A04;
extern FDC58Entry *D_80135A08;
extern u8 D_801359E8[];
extern u8 D_801359EC[];
extern s32 D_80135A2C;
extern void func_8008FE68(f32 *);
extern s32 func_800CBC00(s32);
extern s32 func_800CCEF4(f32 *, void *, void *, s32, s32);
extern s32 func_800FCCD4();
extern void func_800FCAE0(s32, s32, s32);
extern void func_800FCA90();
extern void func_800FC97C(s32, f32, f32);
extern s32 func_800FCDE0(s32, s32, f32);
extern s32 func_800FCED0(s32, s32, f32);
extern void func_800FC934(s32, f32, f32);
extern s16 D_801359C8;
extern u8 D_80135A01;
extern u8 D_801359D7;
void func_800C77DC(int);
void func_800FC74C();
typedef struct {
    u8 local_0[0x16];
    u8 local_1;
    u8 local_2;
    u8 local_3[0x1C];
    u8 local_4[2];
    s16 local_5[2];
    u8 local_6[0x16];
} local_type;
// Volume-duck request counters, one per category (defined here).
u8 D_80135A10[14];
extern u8 D_801359D6;

extern s16 D_801359E2;
void _cothemedll_entrypoint_3(void *, s32);
s16 _cothemedll_entrypoint_1(s32);
extern u8 D_801359CE;
extern s8 D_801359CF;
extern u8 D_801359D8;
extern s16 D_801359CA;
extern s16 D_801359E4;
extern s32 D_801242DC[];
extern s32 D_80123E60;
extern f32 D_80124314[][2];
extern f32 D_80135A0C[1];
extern s32 func_80017764(s32);
extern s32 func_800FC4B0(s32, s32, s32, f32);
extern void func_800FC688(s32, s32);
extern void func_800FCB00(s32, s32, s32, s32);
extern float D_801359F0;
extern u8 D_8012762C;
typedef struct {
    u8 pad[0x34];
    u8 field_34[2];
    s16 field_36[2];
} AudioState;
// TU-NOTE: D_801359C0 is one state block viewed through several struct layouts by different functions.
typedef union {
    G_FDC28 G_FDC28;
    FDC58State FDC58State;
    local_type local_type;
    AudioState AudioState;
    f32 f;
} Union_D_801359C0;
extern Union_D_801359C0 D_801359C0;
typedef struct {
    s16 field_0, field_2;
    f32 field_4;
} AudioRecord;
extern s16 D_80123E5E[][4];
extern AudioRecord D_80123E64[];
extern s32 func_800EA05C(void);
extern void func_800C3648(u8, s32);
extern void func_800C3058(u8, s32);
extern void func_800C3A40(u8, f32, f32, f32);
extern void func_800C2FDC(u8);
extern s32 func_800C2E04(void);
extern void func_800C330C(u8, s32);
extern void func_800C301C(u8, s32);
extern void func_800C31DC(u8, f32);
extern void func_800C36F4(u8, s32);
extern void func_800C368C(u8, s32);
extern void func_800C33DC(u8, s32);
extern void func_800C3BDC(u8);
void func_800FE914();
void func_800FEDC4(s32 slot, s32 sound_id, f32 volume, f32 fade_time);

// Theme state: zone/section track variations, aux track slots, ambient loops, duck requests, fades.
// Applies the entry to track_id in aux slot, starting the track if the slot is empty.
void func_800FCFB0(s32 slot, s32 track_id, u8 *entry, s32 variant, f32 fade_time)
{
    if (track_id == D_80135A20[slot]) {
        if (variant != 0) {
            if (*(s16 *) ((s8 *) entry + 0xA) != -1) {
                func_800FCED0(track_id, 0x03938700 / *(s16 *) ((s8 *) entry + 0xA), fade_time);
            }
            func_800FCDE0(track_id, *(s32 *) ((s8 *) entry + 4), fade_time);
        } else {
            if (*(s16 *) ((s8 *) entry + 8) != -1) {
                func_800FCED0(track_id, 0x03938700 / *(s16 *) ((s8 *) entry + 8), fade_time);
            }
            func_800FCDE0(track_id, *(s32 *) ((s8 *) entry + 0), fade_time);
        }
        D_80135A3C[slot] = 1;
        return;
    }
    if (D_80135A20[slot] == 0) {
        D_80135A20[slot] = track_id;
        if (func_800FCCD4(track_id) == 0) {
            func_800FC688(track_id, func_80017764(track_id));
            D_801359D5 = 1;
        }
        if (track_id == 0x4B) {
            func_800FC97C(track_id, 0.125f, 1.0f);
        } else {
            func_800FC97C(track_id, 0.25f, 1.0f);
        }
        if (variant != 0) {
            if (*(s16 *) ((s8 *) entry + 0xA) != -1) {
                func_800FCED0(track_id, 0x03938700 / *(s16 *) ((s8 *) entry + 0xA), fade_time);
            }
            func_800FCDE0(track_id, *(s32 *) ((s8 *) entry + 4), fade_time);
        } else {
            if (*(s16 *) ((s8 *) entry + 8) != -1) {
                func_800FCED0(track_id, 0x03938700 / *(s16 *) ((s8 *) entry + 8), fade_time);
            }
            func_800FCDE0(track_id, *(s32 *) ((s8 *) entry + 0), fade_time);
        }
        D_80135A3C[slot] = 1;
        D_80135A30[slot] = fade_time;
        if (D_80135A40 == -1) {
            D_80135A40 = 1;
            return;
        }
        D_80135A40 += 1;
    }
}

// Chooses the track entry and ambient sounds for the current theme state; pos is the player position.
void func_800FD2A0(u8 *pos, s32 variant)
{
    f32 x;
    f32 volume_copy;
    f32 volume;
    f32 z;
    s32 zone;
    s32 region;
    s32 side;
    s32 section_17;
    s32 section_18;
    s32 section_19;

    switch (*(s16 *) ((s8 *) (u8 *) &D_801359C0 + 0x20)) {
        case 1:
            zone = func_800CBBE0(*(s32 *) ((s8 *) (u8 *) &D_801359C0 + 0x28));
            if (zone != 2) {
                if (zone == 3) {
                    if ((*(f32 *) ((s8 *) &D_801241E4 + 8) > (x = *(f32 *) pos)) ||
                        (z = *(f32 *) ((s8 *) pos + 8),
                         (z < *(f32 *) ((s8 *) &D_801241E4 + 4))) ||
                        (*(f32 *) ((s8 *) &D_801241E4 + 0) < x) ||
                        (*(f32 *) ((s8 *) &D_801241E4 + 0xC) < z)) {
                        region = 0;
                    } else {
                        if (*(f32 *) ((s8 *) &D_801241E4 + 0) <
                            ((x + z) - *(f32 *) ((s8 *) &D_801241E4 + 4))) {
                            side = 1;
                        } else {
                            side = 2;
                        }
                        region = side;
                    }
                    if (region == 2) {
                        D_80135A04 = D_80123F68;
                    }
                }
            } else {
                if (*(f32 *) ((s8 *) pos + 4) > 2000.0f) {
                    func_800FCFB0(0, 0x4A, (s32 *) D_80123E84, variant, 1.75f);
                    (s32 *) D_80135A04 = (s32 *) D_80123FC8;
                }
            }
            break;
        case 7:
            func_800FEDC4(0, 1, 1.0f, 1.75f);
            return;
        case 12:
            func_800FEDC4(0, 2, 1.0f, 1.75f);
            func_800FEDC4(1, 3, 1.0f, 1.75f);
            return;
        case 13:
            func_800FEDC4(0, 2, 0.9f, 1.75f);
            func_800FEDC4(1, 3, 0.9f, 1.75f);
            return;
        // Ambient volume scales with the distance to a fixed point.
        case 14:
            volume =
                func_800F10B4(func_800EEAD4(pos, &D_801241F4), 2500.0f, 3500.0f, 0.8f, 0.0f);
            // Matching: the extra copy of the volume is needed for the match.
            volume_copy = volume;
            func_800FEDC4(0, 2, volume, 1.75f);
            func_800FEDC4(1, 3, volume_copy, 1.75f);
            return;
        case 21:
            func_800FEDC4(
                0, 4,
                func_800F10B4(func_800EEAD4(pos, &D_80124200), 2500.0f, 5000.0f, 1.0f, 0.0f),
                1.75f);
            return;
        case 23:
            func_800FEDC4(0, 2, 0.7f, 1.75f);
            func_800FEDC4(1, 3, 0.7f, 1.75f);
            return;
        case 20:
            func_800FEDC4(
                0, 2,
                func_800F10B4(func_800EEAD4(pos, &D_8012420C), 2500.0f, 3500.0f, 0.5f, 0.0f),
                1.75f);
            return;
        // States 17-19 keep the previous map section when the query returns -1.
        // D_80135A1E remembers which of the two section transition paths ran.
        case 17:
            section_17 = _gcmapsects_entrypoint_7(pos);
            if (section_17 != -1) {
                D_801359D1 = section_17;
            }
            switch (*(u8 *) ((s8 *) (u8 *) &D_801359C0 + 0x11)) {
                case 2:
                case 3:
                case 4:

                    func_800FCFB0(0, 0x4B, D_8012401C, variant, 1.75f);
                    (s32 *) D_80135A04 = (s32 *) &D_80124010;
            }
            break;
        case 18:
            section_18 = _gcmapsects_entrypoint_7(pos);
            if (section_18 != -1) {
                D_801359D1 = section_18;
            }
            switch (*(u8 *) ((s8 *) (u8 *) &D_801359C0 + 0x11)) {
                case 3:
                    if (variant != 0) {
                        func_800FCFB0(0, 0x4B, D_8012401C, variant, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, D_80124004, variant, 1.75f);
                    }
                    (s32 *) D_80135A04 = (s32 *) &D_80124010;
                    break;
                case 0:
                case 2:
                    func_800FCFB0(0, 0x4B, D_8012401C, variant, 1.75f);
                    (s32 *) D_80135A04 = (s32 *) &D_80124010;
                    D_80135A1E = 0;
                    break;
                case 1:
                    if (D_80135A1E != 0) {
                        func_800FCFB0(0, 0x4B, D_80124028, variant, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, D_8012401C, variant, 1.75f);
                    }
                    (s32 *) D_80135A04 = (s32 *) &D_80124010;
            }
            break;
        case 19:
            section_19 = _gcmapsects_entrypoint_7(pos);
            if (section_19 != -1) {
                D_801359D1 = section_19;
            }
            switch (*(u8 *) ((s8 *) (u8 *) &D_801359C0 + 0x11)) {
                case 0:
                case 1:
                case 2:
                case 3:

                    if (variant != 0) {
                        func_800FCFB0(0, 0x4B, D_80124028, variant, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, D_80124004, variant, 1.75f);
                    }
                    (s32 *) D_80135A04 = (s32 *) &D_80124010;
                    D_80135A1E = 1;
            }
            break;
        case 22:
            if (variant != 0) {
                func_800FCFB0(0, 0x4B, D_8012401C, variant, 1.75f);
            } else {
                func_800FCFB0(0, 0x4B, D_80124004, variant, 1.75f);
            }
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        case 5:
            if (*(u8 *) ((s8 *) (u8 *) &D_801359C0 + 0x40) == 0) {
                func_800FCFB0(0, 0x4B, D_80124004, variant, 1.75f);
            }
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        case 6:
            func_800FCFB0(0, 0x4B, D_80124040, variant, 1.75f);
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        case 8:
            if (func_800DA298(0x9F0) != 0) {
                func_800FCFB0(1, 0x50, (s32 *) D_80123E84, variant, 1.75f);
            } else {
                func_800FCFB0(0, 0x4F, (s32 *) D_80123E84, variant, 1.75f);
            }
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        case 9:
            func_800FCFB0(0, 0x4B, D_80124034, variant, 1.75f);
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        case 10:
            func_800FCFB0(0, 0x4B, D_8012401C, variant, 1.75f);
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        case 11:
            func_800FCFB0(0, 0x4B, D_80124028, variant, 1.75f);
            (s32 *) D_80135A04 = (s32 *) &D_80124010;
            return;
        // Advances or retreats the blend by delta time inside or outside the test region.
        // This is threshold gating, not a clamp: one step may cross 0 or 0.5.
        case 15:
            if (func_800DA298(0x360)) {
                if (func_800EFFB4(pos, 1750.0f, &D_80124218)) {
                    if (D_80135A44 < 0.5f) {
                        D_80135A44 += func_800D8FF8();
                    }
                } else {
                    if (D_80135A44 > 0.0f) {
                        D_80135A44 -= func_800D8FF8();
                    }
                }
                if (D_80135A44 > 0.0f) {
                    if (D_80135A44 >= 0.5f) {
                        (s32 *) D_80135A04 = (s32 *) &D_801241CC;
                    } else {
                        D_80135A04 = D_801241D8;
                    }
                }
            }
            break;
        case 16:
            if (D_80135A44 >= 1.0f) {
                func_800FCFB0(0, 0x8D, (s32 *) D_80123E84, variant, 1.75f);
            }
            D_80135A44 = 1.0f;
    }
}

void func_800FDBB8(s32 variant)
{
    if (D_80124224[D_80135A00].unk0 != -1) {
        func_800FCFB0(D_80124224[D_80135A00].unk0, D_80124224[D_80135A00].unk4, (u8 *) D_80123E84,
                      variant, 0.0f);
        (u8 *) D_80135A04 = (u8 *) &D_80124010;
    }
}

u32 func_800FDC28(u32 param_0)
{
    if (param_0 != D_801359C0.G_FDC28.unk40) {
        D_801359C0.G_FDC28.unk40 = param_0;
        if ((param_0 & 0xFF) == 0) {
            D_801359C0.G_FDC28.unk18 = 1;
        }
    }
}

// Per-frame theme update: selects the entry and applies it to the main and aux tracks.
void func_800FDC58(s32 variant)
{
    f32 pos[3];
    s32 retry_count;
    s32 i;
    s32 temp;
    // Matching: the unused locals and the double cast are needed for the match.
    s32 *unused;
    f32 unk_0;
    FDC58State *state = (FDC58State *) (u32) (FDC58State *) &D_801359C0;

    // Keep the retry counter from before this frame's update for func_800FE914.
    retry_count = D_801359C0.FDC58State.value_0F;
    if (D_801359C0.FDC58State.value_41 != 0)
        return;
    if (D_801359C0.FDC58State.value_16 == 0)
        return;
    if (D_801359C0.FDC58State.value_3C > 0.0f) {
        D_801359C0.FDC58State.value_3C -= func_800D8FF8();
    }
    if (func_80090200() == 0)
        return;
    if (func_8008FF94() == 2)
        variant = 1;
    else
        variant = 0;

    if (D_801359C0.FDC58State.value_17 == 0) {
        if (D_801359C0.FDC58State.value_22 != -1) {
            D_80135A04 = &D_80123E84[D_801359C0.FDC58State.value_22];
        } else
            D_80135A04 = 0;
        func_8008FE68(pos);
        // Clear the in-use marks; func_800FCFB0 re-marks the slots still wanted this frame.
        for (i = 0; i < 3; i++)
            D_80135A3C[i] = 0;
        if (func_800CCEF4(pos, D_801359E8, D_801359EC, 0, 0)) {
            temp = func_800CBBE0(D_801359C0.FDC58State.value_28);
            if (!func_800CBC00(D_801359C0.FDC58State.value_28)) {
                D_80135A04 = &D_80123E84[temp];
            } else {
                switch (func_800CBBE0(D_801359C0.FDC58State.value_28)) {
                    case 0:
                        func_800FCFB0(0, 0x47, D_80123E84, variant, 1.75f);
                        D_80135A04 = D_80123FC8;
                        break;
                    case 1:
                        func_800FCFB0(0, 0x4A, D_80123E84, variant, 1.75f);
                        D_80135A04 = D_80123FC8;
                        break;
                    case 7:
                        D_80135A1E = 1;
                        break;
                    case 8:
                        D_80135A1E = 0;
                        break;
                    case 9:
                        func_800FCFB0(0, 0x4A, D_80123E84, variant, 1.75f);
                        D_80135A04 = D_80124064;
                        break;
                    case 12:
                        if (func_800DA298(0x360))
                            D_80135A04 = &D_801241CC;
                        break;
                    case 13:
                        D_80135A44 = 0.0f;
                        break;
                    case 14:
                        func_800FCFB0(0, 0x4A, D_80123E84, variant, 1.75f);
                        break;
                    case 15:
                        func_800FCFB0(0, 0x8D, D_80123E84, variant, 1.75f);
                        D_80135A04 = D_8012419C;
                        break;
                    case 16:
                        if (func_800DA298(0x3B) && !func_800DA298(0x43)) {
                            func_800FCFB0(0, 0x9A, D_80123E84, variant, 1.75f);
                            D_80135A04 = &D_80124010;
                        } else
                            D_80135A04 = D_80124124;
                        break;
                    case 17:
                        if (func_800DA298(0x3B) && !func_800DA298(0x43)) {
                            func_800FCFB0(0, 0x9A, D_80123E84, variant, 1.75f);
                            D_80135A04 = &D_80124010;
                        }
                }
            }
        }
        if (D_801359C0.FDC58State.value_20)
            func_800FD2A0(pos, variant);
        func_800FDBB8(variant);
        // Stop aux tracks that were not re-marked this frame or have finished.
        if (D_80135A40 > 0) {
            for (i = 0; i != 3; i++) {
                if (D_80135A20[i]) {
                    if (!D_80135A3C[i] || !func_800FCCD4(D_80135A20[i])) {
                        unk_0 = 666.0f;
                        func_800FCAE0(D_80135A20[i], 0, (s32) unk_0);
                        func_800FCA90(D_80135A20[i]);
                        D_80135A20[i] = 0;
                        D_80135A3C[i] = 0;
                        D_80135A30[i] = 0.0f;
                        D_80135A40--;
                    }
                }
            }
        }
    }
    func_800FE914(retry_count);
    if (D_801359C0.FDC58State.value_17 == 0) {
        // Reapply the entry after an entry or variant change, or a pending retry.
        if (D_80135A04 != D_80135A08 || variant != D_801359C0.FDC58State.value_10 ||
            D_801359C0.FDC58State.value_0F || D_801359C0.FDC58State.value_18) {
            if (!D_801359C0.FDC58State.value_0F)
                temp = 1;
            else {
                D_801359C0.FDC58State.value_0F--;
                temp = 0;
                if (D_801359C0.FDC58State.value_08 != -1)
                    func_800FC97C(D_801359C0.FDC58State.value_08, 0.25f, 1.0f);
            }
            D_80135A08 = D_80135A04;
            D_801359C0.FDC58State.value_10 = variant;
            // A failed call sets value_0F so the next frame retries.
            // Tempo is 60000000 / BPM in integer division, then scaled by value_04.
            if (D_80135A04 && D_801359C0.FDC58State.value_08 != -1) {
                if (variant) {
                    if (!func_800FCDE0(D_801359C0.FDC58State.value_08, D_80135A04->local_0[1],
                                       (f32) temp))
                        D_801359C0.FDC58State.value_0F = 1;
                    if (D_80135A04->local_1[1] != -1) {
                        if (!func_800FCED0(D_801359C0.FDC58State.value_08,
                                           (s32) ((60000000 / D_80135A04->local_1[1]) *
                                                  D_801359C0.FDC58State.value_04),
                                           (f32) temp))
                            D_801359C0.FDC58State.value_0F = 1;
                    }
                } else {
                    if (!func_800FCDE0(D_801359C0.FDC58State.value_08, D_80135A04->local_0[0],
                                       (f32) temp))
                        D_801359C0.FDC58State.value_0F = 1;
                    if (D_80135A04->local_1[0] != -1) {
                        if (!func_800FCED0(D_801359C0.FDC58State.value_08,
                                           (s32) ((60000000 / D_80135A04->local_1[0]) *
                                                  D_801359C0.FDC58State.value_04),
                                           (f32) temp))
                            D_801359C0.FDC58State.value_0F = 1;
                    }
                }
            }
            D_801359C0.FDC58State.value_18 = D_801359C0.FDC58State.value_0F;
        }
        // Refresh main and aux volumes once, then clear the dirty flag.
        // D_80135A2C is the end of D_80135A20; the loops only use its address.
        if (D_801359C0.FDC58State.value_14) {
            if (D_801359C0.FDC58State.value_13) {
                if (D_801359C0.FDC58State.value_08 != -1)
                    func_800FC934(D_801359C0.FDC58State.value_08, D_801359C0.FDC58State.value_00,
                                  1.0f);
                temp = 0;
                do {
                    if (D_80135A20[temp])
                        func_800FC934(D_80135A20[temp], D_801359C0.FDC58State.value_00, 1.0f);
                    temp++;
                } while (&D_80135A2C != &D_80135A20[temp]);
            } else {
                if (D_801359C0.FDC58State.value_08 != -1)
                    func_800FC934(D_801359C0.FDC58State.value_08, 0, 1.0f);
                temp = 0;
                do {
                    if (D_80135A20[temp])
                        func_800FC934(D_80135A20[temp], 0, 1.0f);
                    temp++;
                } while (&D_80135A2C != &D_80135A20[temp]);
            }
            D_801359C0.FDC58State.value_14 = 0;
        }
    }
}

// Stops the main track and the marked aux tracks.
void func_800FE3EC()
{
    if (D_801359C8 != -1) {
        func_800FCA90(D_801359C8);
    }
    if (D_80135A40 <= 0) {
        return;
    }
    {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (D_80135A20[i] != 0) {
                if (D_80135A3C[i] != 0) {
                    func_800FCA90(D_80135A20[i]);
                    D_80135A20[i] = 0;
                    D_80135A3C[i] = 0;
                    D_80135A30[i] = 0.0f;
                    D_80135A40 -= 1;
                }
            }
        }
    }
}

// Stops the main and aux tracks; returns 0 without doing anything while D_801359D7 is set.
int func_800FE4E4(void)
{
    s32 i;
    if (D_801359D7 != 0)
        return 0;
    {
        func_800C77DC(1);
        func_800FDC28(0);
        if (D_801359C8 != -1) {
            func_800FC74C(D_801359C8);
        }
        if ((int) D_80135A40 > 0) {
            for (i = 0; i < 3; i++) {
                if ((int *) D_80135A20[i] && D_80135A3C[i]) {
                    func_800FC74C((int *) D_80135A20[i]);
                    (int *) D_80135A20[i] = 0;
                    D_80135A3C[i] = 0;
                    D_80135A30[i] = 0.0f;
                    (int) D_80135A40--;
                }
            }
        }
        D_80135A01 = 1;
        return 1;
    }
}

// Resets the aux track slots, the ambient sound slots and the duck counters.
void func_800FE614(void)
{
    s32 i;
    D_801359C0.local_type.local_1 = 1;
    D_801359C0.local_type.local_2 = 0;
    D_80135A40 = -1;
    for (i = 0; i < 2; i++) {
        D_801359C0.local_type.local_4[i] = 0;
        D_801359C0.local_type.local_5[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        D_80135A20[i] = 0;
        D_80135A30[i] = 0.0f;
        D_80135A3C[i] = 0;
    }
    for (i = 0; i < 14; i++) {
        D_80135A10[i] = 0;
    }
    func_800FDC28(0);
}

void func_800FE6F8(long enable)
{
    if ((enable == 0) && (D_801359D6 != 0)) {
        func_800FE4E4();
    }
    D_801359D6 = enable;
}

void func_800FE734(u32 param_0)
{
    D_801359D7 = param_0;
}

void func_800FE740(void)
{
    s32 unk_0;

    unk_0 = func_800EA05C();
    if (D_80135A10[6] != 0) {
        D_80135A10[6] = 0;
    }
    D_80135A08 = 0;
    *(f32 *) D_80135A0C = 0.0f;
    _cothemedll_entrypoint_3(&D_801359C0, unk_0);
    D_801359E2 = _cothemedll_entrypoint_1(unk_0);
}

// Returns 1 if track_id is the main track or a marked aux track.
s32 func_800FE7A8(s32 track_id)
{
    s32 i;
    u8 *mark;
    if (track_id == D_801359C8) {
        i = 1;
        return i;
    }
    if (D_80135A40 > 0) {
        mark = D_80135A3C;
        for (i = 0; i < 3; i++) {
            if (*mark) {
                if (track_id == D_80135A20[i]) {
                    return 1;
                }
            }
            mark++;
        }
    }
    return 0;
}

func_800FE820(f32 speed)
{
    ((f32 *) &D_801359C0)[1] = 1.0f / speed;
    *(u8 *) &((f32 *) &D_801359C0)[4] = 0xFF;
}

void func_800FE844(u32 param_0)
{
    D_801359CE = param_0;
}

void func_800FE850()
{
    func_800DA544(FLAG2_674_UNK);
}

void func_800FE870()
{
    func_800DA544(FLAG2_675_UNK);
}

u8 func_800FE890()
{
    return D_801359CE;
}

void func_800FE89C()
{
    D_801359CF = 1;
}

void func_800FE8AC()
{
    D_801359D8 = 1;
}

int func_800FE8BC(unsigned long param_0, s32 param_1)
{
    u32 unk_0;
    // Matching: the `| 0` copies are needed for the match.
    unk_0 = param_0 | 0;
    _cothemedll_entrypoint_5(&D_801359C0, unk_0, param_1 | 0);
}

int func_800FE8EC(s32 param_0)
{
    s32 unk_0;
    // Matching: the `| 0` copy is needed for the match.
    unk_0 = param_0 | 0;
    _cothemedll_entrypoint_4(&D_801359C0, unk_0);
}

// Applies the lowest volume limit among the active duck requests to the main and aux tracks.
// instant skips the fade.
void func_800FE914(instant) s32 instant;
{
    s32 volume;
    f32 fade_time;
    s32 i;
    f32 temp;
    s32 result;
    s32 j;

    volume = D_801359CA;
    fade_time = 1.75f;
    for (i = 0; i != 14; i++) {
        if (D_80135A10[i]) {
            switch (i) {
                case 3:
                    temp = D_801359CA * D_801359F0;
                    if (temp < volume)
                        volume = temp;
                    break;
                default:
                    if (D_801242DC[i] < volume)
                        volume = D_801242DC[i];
                    break;
            }
            if (D_80124314[i][0] < fade_time)
                fade_time = D_80124314[i][0];
            if (D_80135A0C[0] < D_80124314[i][1])
                D_80135A0C[0] = D_80124314[i][1];
        }
    }
    if (D_801359E4 < volume)
        fade_time = D_80135A0C[0];
    if (volume != D_801359E4 || D_80123E60) {
        s16 *main_track = &D_801359C8;
        if (*main_track != -1) {
            if (!func_800FCCD4(D_801359C8)) {
                func_800FC688(*main_track, func_80017764(*main_track));
            }
            result = func_800FC4B0(*main_track, -1, volume, instant ? 0.0f : fade_time);
            if (result)
                func_800FCB00(*main_track, volume, result, 0);
        }
        D_80123E60 = 0;
    }
    if (volume != D_801359E4 || D_801359D5 || D_80123E60) {
        if (D_80135A40 > 0) {
            for (j = 0; j != 3; j++) {
                if (D_80135A20[j] && D_80135A3C[j] &&
                    func_800FCCD4(D_80135A20[j])) {
                    if (instant)
                        fade_time = 0.0f;
                    else
                        fade_time = (temp = fade_time < D_80135A30[j] ? fade_time
                                                                      : D_80135A30[j]);
                    result = func_800FC4B0(D_80135A20[j], -1, volume, fade_time);
                    if (result)
                        func_800FCB00(D_80135A20[j], volume, result, 0);
                }
            }
        } else {
            D_80135A0C[0] = 0.0f;
        }
        D_801359D5 = 0;
    }
    D_801359E4 = volume;
}

void func_800FEC1C(f32 scale)
{
    D_801359F0 = scale;
}

int func_800FEC28(s32 request)
{
    int result;
    u8 *unk_0 = &D_8012762C;
    // Matching: the all-ones mask and the `0 |` are needed for the match.
    result = 0xFFFFFFFFFFFFFFFF;
    result = request & result;
    if (!result) {
        result = 0;
        if (*unk_0 == 0xD) {
            return 7;
        }
        {
            return 0 | result;
        }
    }
    return result;
}

// Adds a duck request.
void func_800FEC60(u32 request)
{
    s32 index = func_800FEC28(request);
    D_80135A10[index] += 1;
    if (index == 3) {
        D_801359F0 = 1.0f;
    }
    D_80123E60 = 1;
}

// Removes a duck request.
void func_800FECB8(u32 request)
{
    s32 i;
    D_80135A10[func_800FEC28(request)]--;
    // Matching: the empty loop is needed for the match.
    for (i = 0; i < 14; i++) {
    }
    D_80123E60 = 1;
}

void func_800FED0C(u32 id, u32 delta)
{
    u32 idx;
    switch (id - 1) {
        case 0:
        default:
            return;
        case 1:
            idx = 0xC;
            break;
        case 4:
        case 9:
        case 10:
        case 11:
        case 12:
        case 17:
        case 21:
        case 22:
        case 23:
        case 26:
        case 45:
        case 48:
        case 57:
        case 67:
        case 82:
        case 95:
        case 118:
        case 130:
            idx = 0xD;
            break;
        case 42:
        case 103:
            idx = 0xD;
    }
    D_80135A10[idx] += delta;
    D_80123E60 = 1;
}

void func_800FED70(s32 id)
{
    func_800FED0C(id, 1);
}

int func_800FED90(s32 id)
{
    int i;
    func_800FED0C(id, -1);
    // Matching: the empty loop is needed for the match.
    for (i = 2; i < 0xE; i += 4) {
    }
}

// Starts, updates or stops the looping ambient sound source in slot.
void func_800FEDC4(s32 slot, s32 sound_id, f32 volume, f32 fade_time)
{
    if (sound_id == D_801359C0.AudioState.field_36[slot] && sound_id != 0) {
        func_800C3648(D_801359C0.AudioState.field_34[slot], func_800EA05C());
        func_800C3058(D_801359C0.AudioState.field_34[slot],
                      (s32) (D_80123E5E[sound_id][0] * volume));
        return;
    }
    if (D_801359C0.AudioState.field_34[slot]) {
        if (fade_time != 0.0f)
            func_800C3A40(D_801359C0.AudioState.field_34[slot], 0.0f, 0.0f, fade_time);
        else
            func_800C2FDC(D_801359C0.AudioState.field_34[slot]);
        D_801359C0.AudioState.field_34[slot] = 0;
    }
    if (sound_id) {
        D_801359C0.AudioState.field_34[slot] = func_800C2E04();
        func_800C330C(D_801359C0.AudioState.field_34[slot], 3);
        func_800C301C(D_801359C0.AudioState.field_34[slot], D_80123E64[sound_id - 1].field_0);
        func_800C3058(D_801359C0.AudioState.field_34[slot],
                      (s32) (D_80123E64[sound_id - 1].field_2 * volume));
        func_800C31DC(D_801359C0.AudioState.field_34[slot], D_80123E64[sound_id - 1].field_4);
        func_800C36F4(D_801359C0.AudioState.field_34[slot], 255);
        func_800C368C(D_801359C0.AudioState.field_34[slot], 0);
        func_800C33DC(D_801359C0.AudioState.field_34[slot], 0);
        func_800C3BDC(D_801359C0.AudioState.field_34[slot]);
    }
    D_801359C0.AudioState.field_36[slot] = sound_id;
}

// Reads the channel mask and BPM of entry index for the given variant.
void func_800FEF94(s32 unused, s32 index, s32 variant, s32 *mask, s16 *bpm)
{
    u8 *entry;

    if (variant != 0) {
        entry = (index * 12) + (u8 *) D_80123E84;
        *mask = *(s32 *) ((s8 *) entry + 4);
        *bpm = *(s16 *) ((s8 *) entry + 0xA);
        return;
    }
    entry = (index * 12) + (u8 *) D_80123E84;
    *mask = *(s32 *) ((s8 *) entry + 0);
    *bpm = *(s16 *) ((s8 *) entry + 8);
}

func_800FF000(s32 enable)
{
    *(u8 *) ((char *) (u8 *) &D_801359C0 + 0x13) = enable;
    *(f32 *) ((char *) (u8 *) &D_801359C0 + 0x0) = 0.2f;
}

void func_800FF01C(f32 volume)
{
    ((u8 *) (f32 *) &D_801359C0)[0x13] = 1;
    ((u8 *) (f32 *) &D_801359C0)[0x14] = 1;
    D_801359C0.f = volume;
}

int func_800FF038(s32 param_0)
{
    s32 unk_0;
    // Matching: the `| 0` copy is needed for the match.
    unk_0 = param_0 | 0;
    _cothemedll_entrypoint_2(&D_801359C0, unk_0);
}

// 1D trapezoidal motion profile (accel, max speed, decel limits).
// Steps an accel/cruise/decel motion profile by dt; returns the distance moved and updates *velocity.
f32 func_800FF060(f32 distance, f32 *velocity, f32 accel, f32 decel, f32 max_speed, f32 dt)
{
    f32 brake_time;
    // Matching: the constant held in a temporary is needed for the match.
    f32 two;
    f32 brake_dist;
    f32 accel_dist;
    f32 cruise_dist;
    f32 temp;
    f32 speed;
    f32 cruise_time;
    f32 accel_time;
    f32 decel_dir;
    // Matching: volatile is needed for the match.
    volatile f32 accel_span;
    f32 decel_time;
    f32 decel_dist;
    f32 scratch;
    f32 new_speed;
    s32 dir;
    decel_dir = decel;
    if (distance < 0.0f) {
        dir = -1;
    } else {
        dir = 1;
    }
    distance *= (f32) dir;
    speed = *velocity * (f32) dir;
    if (speed < 0.0f) {
        decel_dir = -decel_dir;
        if (decel_dir < accel) {
            scratch = accel;
        } else {
            scratch = decel_dir;
        }
        brake_time = 0.0f - (speed / scratch);
        if (dt < brake_time) {
            brake_time = dt;
        }
        temp = (scratch * brake_time) + speed;
        brake_dist = ((speed + temp) * brake_time) * 0.5f;
    } else {
        brake_time = 0;
        temp = speed;
        brake_dist = brake_time;
    }

    speed = temp;
    temp *= temp;
    scratch = temp;
    two = 2.0f;
    distance -= brake_dist;
    dt -= brake_time;
    accel_time = ((scratch * .5f) + (decel * distance)) / (decel - accel);
    accel_span = accel_time;
    if (accel_time > 0.0f) {
        temp = two * accel;
        scratch += temp * accel_span;
        temp = sqrtf(scratch);
        if (max_speed <= temp) {
            temp = max_speed;
        }
        accel_time = (temp - speed) / accel;
        if (dt < accel_time) {
            accel_time = dt;
        }
        new_speed = (accel * accel_time) + speed;
        accel_dist = ((speed + new_speed) * 0.5f) * accel_time;
    } else {
        new_speed = speed;
        accel_time = 0.0f;
        accel_dist = 0.0f;
    }

    if (new_speed == 0.0f) {
        *velocity = 0.0f;
        return (f32) dir * brake_dist;
    }
    dt -= accel_time;
    speed = new_speed;
    distance -= accel_dist;
    if (dt > 0.0f) {
        scratch = (0.0f - (new_speed * new_speed)) / (two * decel);
        if (scratch < distance) {
            cruise_time = (distance - scratch) / new_speed;
            if (dt < cruise_time) {
                cruise_time = dt;
            }
            cruise_dist = cruise_time * new_speed;
        } else {
            cruise_dist = 0.0f;
            cruise_time = 0.0f;
        }
    } else {
        cruise_dist = 0.0f;
        cruise_time = 0.0f;
    }
    distance -= cruise_dist;
    dt -= cruise_time;
    if (dt > 0.0f) {
        decel_time = dt;
        new_speed = (decel * dt) + speed;
        if (new_speed < 0.0f) {
            new_speed = 0.0f;
            cruise_time = -speed / decel;
            decel_time = cruise_time;
        }
        decel_dist = ((speed + new_speed) * 0.5f) * decel_time;
    } else {
        decel_dist = 0.0f;
    }
    distance -= decel_dist;
    *velocity = (f32) dir * new_speed;
    return (((brake_dist + accel_dist) + cruise_dist) + decel_dist) * (f32) dir;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1ED68A0.data.s) is defined here in C; values come from the ROM.
// TU-NOTE: D_80123E5E is a linker symbol (undefined_syms.us.txt) at D_80123E50 + 0xE.
// TU-NOTE: the externs D_80123F68, D_80123FC8, D_80124004, D_8012401C, D_80124028, D_80124034, D_80124040, D_80124064,
// D_80124124, D_8012419C and D_801241D8 are declared as arrays over the objects below (same addresses); uses are written NAME[0].
u32 D_80123E50[4] = {0x0, 0x0, 0x0, 0x0};
s32 D_80123E60 = 0x0;
AudioRecord D_80123E64[4] = {0x486, 0x32C8, 0.6f, 0x66A, 0x2710, 1.0f,
                             0x669, 0x2710, 1.0f, 0x616, 0x61A8, 0.5f};
FDC58Entry D_80123E84[19] = {
    -0x1,        -0x1,  -0x1, -0x1, 0x63FF,      0x1C00, 0x50, 0x50, 0x1FE0000,  0x1C00, 0x50, 0x50,
    0x73FF,      0xC00, 0x78, 0x69, 0x41C00000,  0x0,    0x78, 0x69, 0x41C00000, 0x0,    0x78, 0x69,
    -0x41E00000, 0x0,   0x5F, 0x69, 0x401D0000,  0x0,    0x78, 0x69, 0x401F0000, 0x0,    0x78, 0x69,
    0x73DF,      0x0,   0x78, 0x69, 0xE108,      0x0,    0x78, 0x69, 0x4FF,      0x300,  0x82, 0x64,
    0x7FF0000,   0x300, 0x64, 0x64, 0x7C610000,  0x300,  0x5A, 0x64, 0x7EF0000,  0x0,    0x64, 0x64,
    0x113800,    0x0,   0x64, 0x64, -0x7FA00000, 0x0,    0x6E, 0x64, 0xC090,     0x0,    0x75, 0x64,
    0x0,         0x0,   0x82, 0x64};
s32 D_80123F68[24] = {0xFF,      0x0,       0xB400B4, 0x1F00,     0x0, 0xA500B4,
                      0x1FF0000, 0x1FF0000, 0xAA00AA, -0x1F80000, 0x0, 0xB400B4,
                      0x60FF,    0x0,       0xB400B4, 0x13F0000,  0x0, 0xAA00B4,
                      0x72,      0x0,       0xB400B4, 0x30098050, 0x0, 0xB400B4};
FDC58Entry D_80123FC8[5] = {0x0,  0x0,  0xB4,  0xB4,   0xE00, 0x0,  0xA5,     0xB4, 0xCFF, 0x3000,
                            0x64, 0x5F, 0xFFF, 0x3000, 0x64,  0x5F, 0x3F0000, 0x0,  0x5C,  0x5C};
s32 D_80124004[3] = {0x3F80000, 0x60000, 0x640064};
FDC58Entry D_80124010 = {0x0, 0x0, 0x5F, 0x5F};
s32 D_8012401C[3] = {0x0, 0xFE, 0x5F006E};
s32 D_80124028[3] = {0x0, 0x1F00, 0x5F0064};
s32 D_80124034[3] = {0x0, 0xE001, 0x5F0064};
s32 D_80124040[9] = {-0x1FF0000, 0x70000,  0x640064, 0xC1FF,  0x600,
                     0x96008F,   0x7F0000, 0x600,    0x8F008F};
FDC58Entry D_80124064[16] = {0xD000,     0x0,      0x96, 0x8F, 0x3F,      0xF00000, 0x8E, 0x8E,
                             0x1FD0,     0xF00000, 0x89, 0x89, 0xFE040,   0xF00000, 0x82, 0x82,
                             0xFFF,      0x40000,  0x66, 0x5F, 0x2FE40,   0x40000,  0x5F, 0x5F,
                             0x2FE40,    0x40000,  0x5F, 0x5F, 0xFF90000, 0x40000,  0x66, 0x5F,
                             -0x26E0000, 0x40000,  0x5F, 0x5F, -0x1,      -0x1,     0x50, 0x50,
                             0x7FE,      0x1800,   0x7D, 0x74, 0xE001,    0x1800,   0x74, 0x74,
                             0x3F0000,   0x1800,   0x74, 0x74, 0x3C80000, 0x1800,   0x74, 0x74,
                             0x1C080000, 0x1800,   0x74, 0x74, 0x41FE,    -0x1,     0x69, 0x69};
FDC58Entry D_80124124[10] = {0x601,    -0x1, 0x66, 0x66, 0x80FE,    -0x1, 0x73, 0x73,
                             0xF00,    -0x1, 0x73, 0x73, 0x7F,      0x80, 0x66, 0x66,
                             0x1F00,   0x80, 0x66, 0x66, 0xE000,    0x80, 0x66, 0x66,
                             0x70000,  0x80, 0x66, 0x66, 0x1C0000,  0x80, 0x66, 0x66,
                             0xE00000, 0x80, 0x66, 0x66, 0x3000A00, 0x80, 0x66, 0x66};
FDC58Entry D_8012419C[4] = {0xC040000,   0x80, 0x66, 0x66, 0x30800000, 0x80, 0x66, 0x66,
                            -0x20000000, 0x80, 0x66, 0x66, -0x1,       -0x1, 0x7D, 0x7D};
FDC58Entry D_801241CC = {0xB000, -0x1, 0x4B, 0x69};
s32 D_801241D8[3] = {0xE060, -0x1, 0x5A0069};
f32 D_801241E4[4] = {3.25e+03f, 6.75e+03f, 7e+02f, 9.3e+03f};
f32 D_801241F4[3] = {-6326.0f, 7e+02f, -6.1e+03f};
f32 D_80124200[3] = {0.0f, 5.3e+03f, 2.1e+03f};
f32 D_8012420C[3] = {5.98e+03f, 1.5e+03f, 1.53e+03f};
f32 D_80124218[3] = {0.0f, 0.0f, 0.0f};
E_FDBB8 D_80124224[23] = {-0x1, -0x1, 0x2, 0x54, 0x1, 0x38, 0x1, 0x48, 0x1, 0x4C, 0x1, 0x3B,
                          0x1,  0x4E, 0x1, 0x63, 0x1, 0x56, 0x1, 0x56, 0x1, 0x61, 0x1, 0x55,
                          0x1,  0x49, 0x1, 0x3D, 0x2, 0x43, 0x1, 0x84, 0x2, 0x43, 0x1, 0x49,
                          0x1,  0x5B, 0x1, 0x76, 0x1, 0x7A, 0x1, 0x42, 0x2, 0x7C};
s32 D_801242DC[14] = {0x2710, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3A98, 0x0, 0x0, 0x0, 0x0, 0xFA0, 0x0};
f32 D_80124314[15][2] = {0.5f,  0.5f,  1.75f, 1.75f, 1.75f, 1.75f, 1.75f, 1.75f, 0.0f, 0.25f,
                         1.75f, 1.75f, 0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f, 0.5f,
                         0.5f,  0.5f,  1.75f, 1.75f, 0.0f,  0.05f, 0.0f,  0.05f, 0.0f, 0.0f};
