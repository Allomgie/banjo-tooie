#include "core2/1EA0AA0.h"

typedef struct {
    u8 pad_0[6];
    u16 value : 9; // marker parameter, 0..100
    u16 rest : 7;
} E_C71B0;
typedef struct {
    u8 pad_0[4];
    E_C71B0 *unk_4;
} S_C71B0;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_8011A8A0[];
extern void func_800FF000(s32);
extern s32 _gccubesearch_entrypoint_14(s32, s32);
extern unsigned char D_8012760D[7];
typedef struct {
    u8 state;
    s8 disabled;
} LocalState;

typedef struct {
    u8 state;
    s8 suspend;
} D_8012760C_unk;
extern u8 D_8011A904;
extern s16 D_8011A910[];
extern u8 D_8012760C;
extern u8 D_8012AAF0;

// Scale from the marker parameter (0..100); 50 returns the default.
f32 func_800C71B0(s32 marker, f32 default_scale)
{
    u32 param = ((S_C71B0 *) marker)->unk_4->value;
    f32 scale;
    if (param == 50) {
        scale = default_scale;
    } else {
        scale = func_800F10B4((f32) param, 50.0f, 100.0f, 0.0f, 1.0f);
    }
    return scale;
}

// Marker callback: music volume scale.
void func_800C7230(s32 marker)
{
    func_800FF01C(func_800C71B0(marker, 0.2f));
}

// Marker callback: sfx reverb scale.
void func_800C725C(s32 marker)
{
    func_800C4308(func_800C71B0(marker, 0.51f), 1.0f);
}

// Marker callback: music track volume.
void func_800C7290(s32 marker)
{
    func_800FC9B4(1, func_800C71B0(marker, 0.2f));
}

void func_800C72C0(s32 *entry)
{
    if (D_8011A904 != 0) {
        D_8011A904 = 0;
        entry[1] = 0;
    }
}

void func_800C72E4(s32 entry)
{
}

void func_800C72EC(s32 *entry)
{
    if (D_8011A904 != 0) {
        D_8011A904 = 0;
        entry[1] = 0;
    }
}

void func_800C7310(s32 entry)
{
    _gcgoto_entrypoint_8(0, 0);
}

// Returns 1 if a cube with this marker exists.
s32 func_800C7338(s32 marker_id)
{
    f32 pos[3];

    if (_gccubesearch_entrypoint_3(marker_id, pos) != 0) {
        return 1;
    }
    return 0;
}

// Stores divisor in *out if the marker exists and *out is still unset.
void func_800C7364(s32 marker_id, s32 divisor, s32 *out)
{
    if ((func_800C7338(marker_id) != 0) && (*out == 0)) {
        *out = divisor;
    }
}

// On map load: look up each marker, run its init callback, then set the
// frame-rate divisor from markers 0x7B..0x7F (default 2).
void func_800C73A4(void)
{
    s32 *entry = (s32 *) &D_8011A8A0;
    s32 divisor;
    func_800FF000(0);
    func_800FC9B4(0, 0);
    while (entry != (s32 *) &D_8011A8A0 + 0x19) {
        entry[1] = _gccubesearch_entrypoint_14(*(s16 *) entry, 0);
        if (entry[1]) {
            if (entry[2]) {
                ((void (*)(s32 *)) entry[2])(entry);
            }
        }
        entry += 5;
    }
    divisor = 0;
    func_800C7364(0x7b, 1, &divisor);
    func_800C7364(0x7c, 2, &divisor);
    func_800C7364(0x7d, 3, &divisor);
    func_800C7364(0x7e, 4, &divisor);
    func_800C7364(0x7f, 5, &divisor);
    if (divisor == 0)
        divisor = 2;
    func_80015178(divisor);
}

// Per frame: run the update callback of each found marker.
void func_800C7494(void)
{
    void (*update)(void *);
    u8 *entry;

    if (D_8012AAF0 != 0) {
        entry = (s32 *) D_8011A8A0;
        do {
            if (*(s32 *) ((char *) entry + 0x4) != 0) {
                update = *(void (**)(void *))((char *) entry + 0xC);
                if (update != NULL) {
                    update(entry);
                }
            }
            entry += 0x14;
        } while (entry != ((u8 *) (s32 *) D_8011A8A0 + 0x64));
    }
}

// Run the exit callback of each found marker and reset the sfx reverb.
void func_800C7500(void)
{
    u8 *entry;

    entry = &D_8011A8A0;
    do {
        if (*(u32 *) ((char *) entry + 0x4) != 0) {
            if (*(u32 *) ((char *) entry + 0x10) != 0) {
                ((void (*)(u8 *)) * (u32 *) ((char *) entry + 0x10))(entry);
            }
        }
        entry = (u8 *) ((char *) entry + 0x14);
    } while (entry != ((u8 *) D_8011A8A0 + 0x64));
    func_800C4308(0.0f, 1.0f);
}

void func_800C7574(s32 unk_0, s32 unk_1)
{
    if (unk_1 == 2) {
        D_8012AAF0 = 1;
        return;
    }
    D_8012AAF0 = 0;
}

// Track id for a zone music state.
s32 func_800C75A0(s32 state)
{
    return D_8011A910[state];
}

u8 func_800C75B4(void)
{
    return (*(D_8012760C_unk *) &D_8012760C).state;
}

// Reset the zone music layer to the main theme.
void func_800C75C0(void)
{
    func_800C77DC(1);
    func_800FC81C();
}

void func_800C75E8(void)
{
    (*(D_8012760C_unk *) &D_8012760C).state = 0;
    (*(D_8012760C_unk *) &D_8012760C).suspend = 0;
    func_800C77DC(1);
}

// Start a track (mode != 0), or fade it out and stop it (mode 0).
void func_800C7618(s32 track, s32 mode)
{
    if (mode != 0) {
        if (func_800FCCD4(track) != 0) {
            if (mode == 1) {
                func_800FCDE0(track, 0, 0x3FC00000);
            } else {
                func_800FCDE0(track, -1, 0x3FC00000);
            }
            func_800FCAE0(track, mode, 0x3E8);
            return;
        }
        func_800FC660(track);
        func_800FC788(track, 1);
        return;
    }
    func_800FCAE0(track, mode, 0x3E8);
    func_800FCA90(track);
    func_800FC788(track, 0);
}

// Suspend the zone music layer (warp pads, cutscenes); nests via a counter.
void func_800C76E8()
{
    s8 suspend;
    suspend = *(s8 *) ((char *) &D_8012760C + 1);
    if (((suspend == 0) && (D_8012760C != 0)) && (D_8012760C != 1)) {
        func_800C7618(func_800C75A0(D_8012760C), 1);
        func_800FECB8(0xA);
        suspend = D_8012760D[0];
    }
    // Matching: empty block needed for the match.
    if (!D_8012760C && !D_8012760C) {
    }
    *(s8 *) ((char *) &D_8012760C + 1) = (s8) (suspend + 1);
}

// Resume the zone music layer; counterpart of func_800C76E8.
void func_800C775C(void)
{
    // Matching: the reuse of unk_0, the assignment inside the condition and
    // the `| 0` are needed for the match.
    int unk_0;
    unk_0 = 1;
    if (((s8 *) &D_8012760C)[unk_0] == 1) {
        if ((((u8 *) (s8 *) &D_8012760C)[0] != 0) &&
            ((unk_0 = ((u8 *) (s8 *) &D_8012760C)[0]) != 1)) {
            func_800C7618(func_800C75A0(((u8 *) (s8 *) &D_8012760C)[0]) | 0, -1);
            func_800FEC60(0xA);
        }
    }
    ((s8 *) &D_8012760C)[1]--;
    if ((s8) ((s8 *) &D_8012760C)[1] < 0) {
        ((s8 *) &D_8012760C)[1] = 0;
    }
}

// Switch the zone music layer to new_state; state 1 is the main theme.
void func_800C77DC(s32 new_state)
{
    switch ((*(LocalState *) &D_8012760C).state) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            func_800C7618(func_800C75A0((*(LocalState *) &D_8012760C).state), 0);
            break;
        case 1:
        default:
            if (!(*(LocalState *) &D_8012760C).disabled)
                func_800FEC60(10);
    }
    (*(LocalState *) &D_8012760C).state = new_state;
    if (!(*(LocalState *) &D_8012760C).disabled) {
        switch ((*(LocalState *) &D_8012760C).state) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                func_800C7618(func_800C75A0((*(LocalState *) &D_8012760C).state), -1);
                break;
            case 1:
            default:
                func_800FECB8(10);
        }
    }
}

void func_800C78CC(u32 suspend)
{
    if (suspend != 0) {
        func_800C76E8();
        return;
    }
    func_800C775C();
}

// Restart the alternative track if it stopped playing.
void func_800C7900(void)
{
    // Matching: the second copy of the track id is needed for the match.
    s32 track_copy;
    s32 track;

    if (((*(D_8012760C_unk *) &D_8012760C).suspend == 0) &&
        ((s32) (*(D_8012760C_unk *) &D_8012760C).state >= 2) && (func_8001210C(3) != 0)) {
        track = func_800C75A0((*(D_8012760C_unk *) &D_8012760C).state);
        track_copy = track;
        if (func_800FCCD4(track) == 0) {
            func_800C7618(track_copy, -1);
        }
    }
}

// TU-NOTE: the .data of this file is defined here in C (values from the ROM).
// The tables point to functions of this file; IDO's assembler schedules some of
// them differently unless the tables are in the same unit.
// D_8011A8A0: 5 words per entry {marker id (s16), found cube, init, update, exit}.

s32 D_8011A8A0[25] = {0x2510000,
                      0x0,
                      (u32) func_800C72C0,
                      (u32) func_800C72E4,
                      0x0,
                      0x2160000,
                      0x0,
                      (u32) func_800C72EC,
                      (u32) func_800C7310,
                      0x0,
                      0x2540000,
                      0x0,
                      (u32) func_800C7290,
                      0x0,
                      0x0,
                      0x2530000,
                      0x0,
                      (u32) func_800C7230,
                      0x0,
                      0x0,
                      0x2520000,
                      0x0,
                      (u32) func_800C725C,
                      0x0,
                      0x0};
u8 D_8011A904 = 0x1;
static u32 D_8011A904_rest[2] = {0x0, 0x0};
s16 D_8011A910[16] = {0x0,  0x0, 0x20, 0x1F, 0x64, 0x65, 0x66, 0x7E,
                      0x82, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
