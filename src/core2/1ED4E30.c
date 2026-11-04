// Music track manager: 6 track slots with fades, volume requests per owner, and play/stop APIs.
// The per-frame update drives the core1 sequence player and marks heard-track progress flags.
#include "core2/1ED4E30.h"
#include "freelist.h"

extern s16 D_80123DE0[];
extern void func_800DA544(s32);
extern void func_800FED70(s32);
typedef struct {
    u8 pad_0[0x38];
    void *requests;
    s32 unk_3C[5];
} S_FB650;
typedef struct {
    s32 volume;
    s32 step;
} R_FB650;
typedef struct {
    f32 delay, elapsed, normal_0, normal_1;
    f32 paused_0, paused_1, current_0, current_1;
    s32 volume, target;
    s16 track, step;
    u32 mask;
    u8 pad_30 : 4, unk_30_lo : 4;
    u8 stop_at_zero, unk_32, heard, muted;
    u8 pad_35[3];
    void *requests;
    u8 pad_3C[0x14];
} LocalState_800FB6E0;
extern f32 D_801359B4;
extern f32 D_801359B8;
extern u8 D_801357D0[400];
void func_800172D4(u8, s32);
typedef struct {
    u32 delay;
    f32 elapsed;
    u8 local_2[0x18];
    s32 volume;
    s32 target;
    s16 track;
    s16 step;
    u32 mask;
    u32 unk_30_hi : 4;
    u32 unk_30_rest : 28;
    u32 unk_34;
    FreeList *requests;
    s32 unk_3C[5];
} local_type_800FB808;
extern u8 D_80123E40;
extern void func_800FE614(void);
extern void func_80017864(void);
extern void func_80016E7C(void);
extern void func_80017244(void);
typedef struct {
    f32 delay, elapsed;
    f32 normal_0, normal_1;
    f32 paused_0, paused_1;
    f32 current_0, current_1;
    s32 volume, target;
    s16 track, step;
    u32 mask;
    u8 flag_30, stop_at_zero, pad_32[2], muted, pad_35[0x1B];
} LocalTrack;
extern u8 D_801359B1;
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
extern s32 func_80090200(void);
extern s32 func_800A5490(void);
extern s32 func_80017778(s32);
extern s32 func_800177C4(s32);
extern void func_80017534(u8, f32, f32);
extern void func_800175F0(void);
extern void func_800FDC58(s32);
extern void func_80017EC0(s32);
extern u32 func_800170D4(u8);
extern u32 func_80017070(u8);
extern void func_80017404(u8, s32);
typedef struct {
    f32 delay, elapsed, normal_0, normal_1;
    f32 paused_0, paused_1, current_0, current_1;
    s32 volume, target;
    s16 track, step;
    s32 mask;
    u8 pad_30 : 4, unk_30_lo : 4;
    u8 stop_at_zero, unk_32, heard, muted;
    u8 pad_35[3];
    void *requests;
    u8 pad_3C[0x14];
} LocalState_800FBF9C;
typedef struct {
    s32 volume, step;
} LocalEntry;
extern s32 func_80017764();
extern u8 D_80135964[];
extern u8 D_80135980[];
extern u8 D_8013598A[];
extern u8 D_80135988[];
typedef struct {
    f32 delay, elapsed, normal_0, normal_1;
    f32 paused_0, paused_1, current_0, current_1;
    s32 volume, target;
    s16 track, step;
    s32 mask;
    u8 pad_30[0x20];
} LocalState_800FC1CC;
typedef struct {
    f32 delay;
    f32 elapsed;
    u8 local_2[0x18];
    s32 volume;
    u8 pad_24[4];
    s16 track;
    s16 step;
    u8 pad_2C[5];
    u8 stop_at_zero;
    u8 pad_32[2];
    u8 muted;
    u8 pad_35[0x1B];
} local_type_800FC508;
typedef struct {
    u8 pad_0[0x30];
    u8 unk_30_hi : 4;
    u8 unk_30_lo : 4;
} local_2;
extern u8 D_801359B0[4];
extern s32 func_800FE7A8(s32);
typedef struct {
    u8 pad_0[8];
    f32 normal_0;
    f32 normal_1;
    u8 pad_10[0x18];
    s16 track;
    u8 pad_2A[6];
    u8 flags_30;
    u8 pad_31[0x1F];
} EntryFC9B4;
typedef struct {
    u8 pad_0[0x20];
    s32 volume;
    u8 pad_24[0xD];
    u8 stop_at_zero;
    u8 pad_32[2];
    u8 muted;
} S_FCA90;
extern s32 func_80017108(u8);
extern s32 func_80017210(s32);
extern s32 func_800178C4(s32, s32, s32);
typedef struct {
    f32 delay, elapsed, normal_0, normal_1;
    f32 paused_0, paused_1, current_0, current_1;
    s32 volume, target;
    s16 track, step;
    s32 mask;
    u8 pad_30 : 4, unk_30_lo : 4;
    u8 stop_at_zero, unk_32, heard, muted;
    u8 pad_35[3];
    void *requests;
    u8 pad_3C[0x14];
} LocalState_800FCED0;
extern s32 func_80017D74(s32, s32, f32);
void func_800FB908();
void func_800FCB00();
s32 func_800FCB54(s32, s32, s32, f32);
void func_800FCB9C(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4);

extern s32 D_80135960[];

// Mark the track as heard and set its progress flag.
int func_800FB540(s32 *track)
{
    s32 i;
    if ((u8) *(u8 *) ((char *) track + 51) == 0) {
        func_800FED70(*(s16 *) ((char *) track + 0x28));
        *(u8 *) ((char *) track + 0x33) = 1;
        for (i = 0; i < 0x30; i++) {
            if (*(s16 *) ((char *) track + 0x28) == D_80123DE0[i]) {
                func_800DA544(i + 0x53E);
                break;
            }
        }
    }
}

// Clear the heard flag.
int func_800FB5BC(Actor *track)
{
    s32 *id_field = (s32 *) ((char *) track + 0x28);
    if (*(u8 *) ((char *) id_field + 0xB) != 0) {
        func_800FED90(*(s16 *) ((char *) track + 0x28));
        *(s8 *) ((char *) id_field + 0xB) = 0;
    }
}

// Return the slot playing track_id, else a free slot (NULL if none).
s32 *func_800FB5F8(track_id)
s32 track_id;
{
    LocalTrack *slot;
    LocalTrack *free_slot;

    free_slot = NULL;

    for (slot = (LocalTrack *) D_801357D0; slot < (LocalTrack *) D_801357D0 + 6;
         slot++) {

if (track_id == slot->track) {
    return (s32 *) slot;
}

if (free_slot == NULL && (s32) slot->track < 0) {
    free_slot = slot;
}

}

return (s32 *) free_slot;
}

// Reset the volume-request list to a single request.
void func_800FB650(S_FB650 *track, s32 volume, s32 step) {
    void *index;
    R_FB650 *entry;
    s32 i;
    freelist_clear(track->requests);
    for (i = 0; i < 5; i++) {
        track->unk_3C[i] = 0;
    }
    entry = freelist_next(&track->requests, &index);
    entry->volume = volume;
    entry->step = step;
}

s32 func_800FB6C0(s32 track, s32 volume){
    func_800FB650(track, volume, volume);
}

// Reset a track slot to its defaults.
void func_800FB6E0(LocalState_800FB6E0 *track, s32 param_1)
{
    track->delay = 0.0f;
    track->elapsed = 0.0f;
    track->normal_0 = D_801359B4;
    track->normal_1 = D_801359B8;
    track->current_0 = D_801359B4;
    track->current_1 = D_801359B8;
    track->volume = 0;
    track->target = 0;
    track->track = (s16)-1;
    track->step = 0;
    track->mask = -1;
    track->unk_30_lo = 0;
    track->stop_at_zero = 0;
    track->unk_32 = 0;
    track->muted = 0;
    track->paused_0 = (f32)0;
    track->paused_1 = 1.0f;
    if (param_1 == 0) track->heard = 0;
}

// Stop the track and reset its slot.
void func_800FB774(void *track)
{
    func_800FB6C0(track, func_80017764(*(s16 *)((u8 *)track + 0x28)));
    func_800FB5BC(track);
    *(s16 *)((u8 *)track + 0x28) = -1;
    ((u8 *)track)[0x30] &= 0xff0f;
    func_80017404((u8)((s32)((u8 *)track - D_801357D0) / 0x50), *(s16 *)((u8 *)track + 0x22));
    func_800FB6E0(track, 0);
    func_800172D4((u8)((s32)((u8 *)track - D_801357D0) / 0x50), -1);
}

// Initialise the track manager.
void func_800FB808(void) {
    local_type_800FB808 *track;
    s32 i;
    if (D_80123E40) func_800FB908();
    D_80123E40 = 1;
    D_801359B4 = 0;
    D_801359B8 = 1.0f;
    for (track = ((local_type_800FB808 *) D_801357D0); track < &((local_type_800FB808 *) D_801357D0)[6]; track++) {
        track->track = -1;
        track->volume = 0;
        track->step = 0;
        track->target = 0;
        track->elapsed = 0.0f;
        track->unk_30_hi = 0;
        track->requests = freelist_new(8, 4);
        func_800FB6E0(track, 0);
        for (i = 0; i < 5; i++) track->unk_3C[i] = 0;
    }
    func_800FE614();
    func_80017864();
}

// Matching: the line breaks in this function are needed for the match.
// Shut down the sequence player and free every slot's request list.
void func_800FB908()
{
    u8 *slot;
    func_80017244();
    func_80016E7C();
    slot = &D_801357D0[0]; while (1) {
        freelist_free(*((void **)(slot + 0x38)));
        slot += 0x50;
        *((u32 *) (slot - 0x18)) = 0;

if (slot >= (u8 *) D_801359B0) {
    break;
}

}

((u8 *) &D_80123E40)[0] = 0;
}

// Per-frame update: blend pan/tempo pairs, drive the sequence player, run fades.
void func_800FB968(void)
{
    s32 index;
    LocalTrack *track;
    f32 local_2;
    s32 paused;
    u32 unk_0;
    u32 unk_1;
    s32 unk_2;
    u32 unk_3;

    local_2 = func_800D8FF8();
    paused = D_801359B1;
    if (func_80090200()) {
        paused = func_800A5490();
        D_801359B1 = paused;
    }
    for (track = ((LocalTrack *) D_801357D0); track < ((LocalTrack *) D_801357D0) + 6;
         track++) {
        if (track->track < 0)
            continue;
        track->elapsed = func_800F13F0(track->elapsed + local_2, 600.0f);

if (track->elapsed > 1.0f && func_80017778(track - (LocalTrack *) D_801357D0)) {
    func_800FB774(track);
    continue;
}

if (paused) {
    if (track->paused_0 != track->current_0 || track->paused_1 != track->current_1) {
        track->current_0 += (track->paused_0 - track->current_0) * 0.05f;
        track->current_1 += (track->paused_1 - track->current_1) * 0.05f;
        func_80017534(track - (LocalTrack *) D_801357D0, track->current_0, track->current_1);
    }
} else {

if (track->normal_0 != track->current_0 || track->normal_1 != track->current_1) {
    track->current_0 += (track->normal_0 - track->current_0) * 0.05f;
    track->current_1 += (track->normal_1 - track->current_1) * 0.05f;
    func_80017534(track - (LocalTrack *) D_801357D0, track->current_0, track->current_1);
}

}
}
func_800175F0();
func_800FDC58(paused);
for (track = (LocalTrack *) D_801357D0; track < (LocalTrack *) D_801357D0 + 6; track++) {
    if (track->track < 0)
        continue;
    index = track - (LocalTrack *) D_801357D0;
    func_80017EC0(index);
    unk_0 = func_800170D4(index);
    unk_1 = func_80017070(index);
    unk_2 = func_800177C4(index);
    unk_0 &= unk_1;
    unk_3 = track->mask & unk_1;
    if ((unk_2 && unk_3) || (!unk_2 && !unk_0)) {
        if (unk_0 || unk_3) {
            func_80017404(index, (s16) track->volume);
            track->muted = 0;
        } else {

func_80017404(index, 0);
track->muted = 1;
}
}
}
if (!((u8 *) D_801359B0)[0])
    return;
((u8 *) D_801359B0)[0] = 0;
for (track = ((LocalTrack *) D_801357D0); track < ((LocalTrack *) D_801357D0) + 6; track++) {
    if (track->track < 0)
        continue;
    if (track->step) {
        if (track->delay > 0.0f) {
            track->delay -= func_800D8FF8();
            ((u8 *) D_801359B0)[0] = 1;
            continue;
        }
        if (track->step < 0) {
            track->volume += track->step;

if (track->stop_at_zero && !track->target && track->volume <= 0) {
    func_800FB774(track);
} else {

if (track->target >= track->volume) {
    track->volume = track->target;
    track->step = 0;
} else {

((u8 *) D_801359B0)[0] = 1;
}
if (!track->muted) func_80017404(track - ((LocalTrack *) D_801357D0), (s16)track->volume);
}
continue;
}
if (track->volume < track->target) {
    if (!track->volume) track->elapsed = 0.0f;
    track->volume += track->step;
    if (track->volume >= track->target) {
        track->volume = track->target;
        track->step = 0;
    } else {
        ((u8 *) D_801359B0)[0] = 1;
    }
    if (!track->muted) func_80017404(track - ((LocalTrack *) D_801357D0), (s16)track->volume);
    continue;
}
track->step = 0;
}
}
}

// Find the lowest-volume request (ties: lowest step).
void func_800FBEC8(s32 track, u32 *out_volume, u32 *out_step) {
    s32 capacity;
    s32 volume;
    s32 local_2;
    s32 min_volume;
    s32 min_step;
    s32 *entry;

    capacity = freelist_capacity(*(s32 **)((char *)track + 0x38));
    min_volume = 0x7FFF;
    min_step = 0x40000000;
    local_2 = 1;
    if (capacity >= 2) {
        do {
            if ((freelist_is_element_alive(*(s32 **)((char *)track + 0x38), local_2) != 0) && ((entry = freelist_at(*(s32 **)((char *)track + 0x38), local_2), volume = *(s32 *)((char *)entry + 0), (volume < min_volume)) || ((min_volume == volume) && (*(s32 *)((char *)entry + 4) < min_step)))) {
                min_volume = volume;
                min_step = *(s32 *)((char *)entry + 4);
            }
            local_2 += 1;
        } while (local_2 < capacity);
    }
    *out_volume = min_volume;
    *out_step = min_step;
}

// Add or update a volume request (index in *request); outputs the winning request.
void func_800FBF9C(LocalState_800FBF9C *track, s32 *out_volume, s32 *out_step, s32 *request)
{
    s32 volume;
    LocalEntry *local_2;
    s32 step;
    LocalEntry *entry;
    volume = *out_volume;
    step = *out_step;
    if (*request != 0 && !freelist_is_element_alive(track->requests, *request)) {
        *request = 0;
    }
    if (volume < 0) {
        local_2 = freelist_at(track->requests, 1);
        volume = local_2->volume < func_80017764(track->track) ? func_80017764(track->track) : local_2->volume;
        if (*request != 0) {
            *out_step = ((LocalEntry *) freelist_at(track->requests, *request))->step;
            freelist_erase(track->requests, *request);
            *request = 0;
            func_800FBEC8(track, out_volume, &step);
            return;
        }
    }
    if (*request == 0) {
        entry = freelist_at(track->requests, 1);
        if (entry->volume < volume || (volume == entry->volume && step >= entry->step)) {
            func_800FB650(track, volume, step);
        } else {
            freelist_next(&track->requests, request);
        }
    }
    if (*request != 0) {
        entry = freelist_at(track->requests, *request);
        entry->volume = volume;
        entry->step = step;
    }
    func_800FBEC8(track, out_volume, out_step);
}

// Start the dedicated track (slot 5) unless it is already set.
void func_800FC124(u32 track_id)
{
    s32 volume;
    if (track_id != (*((s16 *) (((char *) (&D_80135988)) + 0))))
    {
        func_800FB6E0(&D_80135960, 0);
        func_800172D4(5, track_id);
        *((s16 *) (((char *) (&D_80135988)) + 0)) = (s16) track_id;
        volume = func_80017764(track_id);
        // Matching: empty block steers IDO's register allocation.
        if (1) { }
        *((s32 *) (((char *) (&D_80135980)) + 0)) = volume;
        *((s16 *) (((char *) (&D_8013598A)) + 0)) = 0;
        *((f32 *) (((char *) (&D_80135964)) + 0)) = 0.0f;
        func_800FB6C0(&D_80135960, volume);
    }
}

// Stop the dedicated track.
void func_800FC1A8()
{
    func_800FB774(&D_80135960);
}

// Fade every track except the dedicated one.
void func_800FC1CC(s32 volume, s32 step)
{
    s32 i;
    for (i = 0; i < 5; i++) {
        if (((LocalState_800FC1CC *) D_801357D0)[i].track >= 0) {
            func_800FCB00(((LocalState_800FC1CC *) D_801357D0)[i].track, volume, step, 1);
        }
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_800FC240(s32 volume, s32 step)
{
    s16 *id_ptr;
    do { s32 *slot = (s32 *) (((int *) D_801357D0)); do { s16 track_id = *((s16 *) (((char *) slot) + 0x28)); if ((track_id >= 0) && (func_800FE7A8(track_id) == 0)) { id_ptr = &(*((s16 *) (((char *) slot) + 0x28))); func_800FCB00(*id_ptr, volume, step, 1); } slot += 0x50 / (sizeof(s32)); } while (slot != ((s32 *) (((int *) D_80135960)))); } while (0);
}

// Matching: the line breaks in this function are needed for the match.
void func_800FC2C4(s32 volume, s32 step)
{
    u8 *end;
    u8 *slot;
    do { end = ((s32 *) D_80135960); slot = ((s32 *) D_801357D0); } while (0);
    do
    {
        s16 track_id;
        track_id = *((s16 *) (((s8 *) slot) + 0x28));
        if ((((short) track_id) >= 0) && ((((u32) (*((u32 *) (((s8 *) slot) + 0x30)))) >> 0x1C) == 0))
        {
            func_800FCB00(track_id, volume, step, 1);
        }
        slot += 0x50;
    }
    while (slot != end);
}

// Matching: the line breaks in this function are needed for the match.
void func_800FC348(u32 volume, u32 step, u32 request)
{
    u8 *base;
    u8 *slot;
    base = ((u8 *) D_801357D0); slot = ((u8 *) D_801357D0); do {
        if (((*((s16 *) (((char *) slot) + 0x28))) >= 0) && (!func_800FE7A8(*((s16 *) (((char *) slot) + 0x28)))))
        {
            func_800FCB00(*((s16 *) (((char *) slot) + 0x28)), volume, step, request);
        }
        slot += 0x50;
    }
    while (slot != ((u8 *) (&D_80135960)));
}

// Per-frame volume step for fading from current to target over seconds.
int func_800FC3D8(s32 track_id, s32 current, s32 target, f32 seconds)
{
    int zero;
    s32 steps;
    if (seconds == 0.0f)
    {
        return 0x7FFF;
    }
    if (target == (-1))
    {
        // Matching: the extra zero temporary is needed for the match.
        zero = 0;
        target = func_80017764(track_id) | zero;
    }
    if (current == target)
    {
        return 1;
    }
    if (seconds == 0.0f)
    {
        steps = current - target;
    }
    else
    {
        steps = ((current - target) / (seconds * 30.0f)) + 1.0f;
        if (steps < 0)
        {
            steps = -steps;
        }
        else
            if (steps == 0)
        {
            steps = 1;
        }
    }
    return steps;
}

s32 func_800FC4B0(s32 track_id, s32 current, s32 target, f32 seconds) {
    u8 *slot;

    if (current == -1) {
        slot = func_800FB5F8();
        if (slot == NULL) {
            return 0;
        }
        current = (*(s32 *)((u8 *)slot + 0x20));
    }
    return func_800FC3D8(track_id, current, target, seconds);
}

void func_800FC508(s32 track_id, s32 volume, s32 force, s32 base_volume) {
    local_type_800FC508 *slot;
    if (volume == -1) volume = func_80017764();
    if (base_volume == -1) base_volume = volume;
    slot = func_800FB5F8(track_id);
    if (slot) {
        if (slot->track < 0 || force != 0) {
            func_800FB6E0(slot, force);
            slot->track = track_id;
            slot->step = 0;
            slot->stop_at_zero = 0;
            slot->elapsed = 0.0f;
            func_800FB6C0(slot, base_volume);
            func_800172D4((u8)(slot - ((local_type_800FC508 *) D_801357D0)), track_id);
        }
        if (!slot->muted) func_80017404((u8)(slot - ((local_type_800FC508 *) D_801357D0)), (s16)volume);
        slot->volume = volume;
        func_800FB540(slot);
    }
}

int func_800FC618(s32 track_id, s32 volume)
{
    func_800FC508(track_id, volume, 0, -1);
}

void func_800FC63C(u32 track_id, u32 volume) {
    func_800FC508(track_id, volume, 1, -1);
}

void func_800FC660(u32 track_id) {
    func_800FC508(track_id, -1, 1, -1);
}

int func_800FC688(s32 track_id, s32 base_volume)
{
    // Matching: `| 0` is needed for the match.
    func_800FC508(track_id, 1, 1, base_volume | 0);
}

// Start the track in a free slot (if idle) at its default volume.
void func_800FC6B0(u32 track_id)
{
    u32 volume;
    u32 slot;
    slot = func_800FB5F8();
    if (slot != 0)
    {
        if ((*((s16 *) (((char *) slot) + 0x28))) < 0)
        {
            func_800FB6E0(slot, 0);
            *((s16 *) (((char *) slot) + 0x2A)) = 0;
            *((s16 *) (((char *) slot) + 0x28)) = (s16) track_id;
        // Matching: `if (1)` is needed for the match.
            if (1)
            {
                *((f32 *) (((char *) slot) + 0x4)) = 0.0f;
                func_800172D4((((s32) (slot - ((u32) (((u8 *) D_801357D0))))) / 80), track_id);
                volume = func_80017764(track_id);
            }
        // Matching: the comma expression is needed for the match.
            *((u32 *) (((0, (char *) slot)) + 0x20)) = volume;
            func_800FB6C0(slot, volume);
        }
        func_800FB540(slot);
    }
}

// Stop the track if it is playing.
void func_800FC74C(u32 track_id)
{
    void *slot;
    slot = func_800FB5F8(track_id);
    if (slot != 0)
    {
        if ((*((s16 *) (((u8 *) slot) + 0x28))) >= 0)
        {
            func_800FB774(slot);
        }
    }
}

void func_800FC788(s32 track_id, s32 value)
{
    local_2 *slot;
    slot = func_800FB5F8(track_id);
    if (slot != 0)
    {
        slot->unk_30_hi = value;
    }
}

// Matching: the line breaks in this function are needed for the match.
// Stop all tracks.
void func_800FC7C4()
{
    u8 *slot;
    u8 *end;
    slot = (u8 *) (&D_801357D0); end = (u8 *) (&D_801359B0);
    do
    {
        if ((*((s16 *) (slot + 0x28))) >= 0)
        {
            func_800FB774(slot);
        }
        slot += 0x50;
    }
    while (slot < end);
}

// Matching: the line breaks in this function are needed for the match.
// Stop all tracks for which func_800FE7A8 is 0.
void func_800FC81C()
{
    u8 *slot;
    slot = &D_801357D0; do {
        if ((((s16) (*((s16 *) (slot + 0x28)))) >= 0) && (func_800FE7A8(*((s16 *) (slot + 0x28))) == 0))
        {
            func_800FB774(slot);
        }
        slot += 0x50;
    }
    while (((u32) slot) < ((u32) (&D_801359B0)));
}

// Matching: the line breaks in this function are needed for the match.
// Stop all tracks whose high flag nibble (byte 0x30) is 0.
void func_800FC884(void)
{
    u8 *slot;
    slot = &D_801357D0; do {
        if ((((s16) (*((s16 *) (slot + 0x28)))) >= 0) && ((((u32 *) (slot + 0x30))[0] >> 0x1C) == 0))
        {
            func_800FB774(slot);
        }
        slot += 0x50;
    }
    while (((u32) slot) < ((u32) (((u8 *) D_801359B0))));
}

// Set the default normal and paused pairs.
int func_800FC8EC()
{
    Actor *slot = func_800FB5F8();
    if (slot != NULL)
    {
        (*(f32 *)((char *)(slot) + 0xC)) = 1.0f;
        (*(f32 *)((char *)(slot) + 0x14)) = 1.0f;
        (*(f32 *)((char *)(slot) + 0x8)) = 0.0f;
        (*(f32 *)((char *)(slot) + 0x10)) = 0.25f;
    }
}

// Set the track's normal pair and flag it in byte 0x30.
void func_800FC934(s32 track_id, f32 pair_0, f32 pair_1)
{
    s32 flags;
    Actor *slot;
    Actor *found;
    char mask;
    // Matching: the extra temporaries are needed for the match.
    found = func_800FB5F8(track_id);
    slot = found;
    if (slot != 0)
    {
        mask = 0xFFFFFFFFFFFFFFFFu;
        *((f32 *) (((u8 *) slot) + 8)) = pair_0;
        *((f32 *) (((u8 *) slot) + 12)) = pair_1;
        flags = 1;
        flags = (((*((u8 *) (((u8 *) slot) + 48))) & mask) & 0xFFF0) | flags;
        *((u8 *) (((u8 *) slot) + 48)) = flags;
    }
}

// Set the track's paused pair.
void func_800FC97C(void *track_id, f32 pair_0, f32 pair_1) {
    void *slot = func_800FB5F8(track_id);
    if (slot) {
        *(f32 *)((u8 *)slot + 0x10) = pair_0;
        *(f32 *)((u8 *)slot + 0x14) = pair_1;
    }
}

// Set the default pair and apply it to tracks whose low flag nibble is clear.
void func_800FC9B4(s32 enable, f32 value) {
    s32 i;

    if (enable != 0) {
        D_801359B4 = value;
        D_801359B8 = 1.0f;
    } else {
        D_801359B4 = 0.0f;
        D_801359B8 = 1.0f;
    }
    for (i = 0; i < 5; i++) {
        if (((EntryFC9B4 *) D_801357D0)[i].track >= 0 && func_800FE7A8(((EntryFC9B4 *) D_801357D0)[i].track) == 0 && !(((EntryFC9B4 *) D_801357D0)[i].flags_30 & 0xF)) {
            ((EntryFC9B4 *) D_801357D0)[i].normal_0 = D_801359B4;
            ((EntryFC9B4 *) D_801357D0)[i].normal_1 = D_801359B8;
        }
    }
}

// Stop the track once its volume reaches zero (now, if already silent or muted).
void func_800FCA90(u32 track_id) {
    S_FCA90 *slot = func_800FB5F8(track_id);
    if (slot != 0) {
        slot->stop_at_zero = 1;
        if ((slot->volume == 0) || (slot->muted != 0)) { func_800FB774(slot); }
    }
}

void func_800FCAE0(u32 track_id, u32 volume, u32 step)
{
    func_800FCB54(track_id, volume, step, 0);
}

void func_800FCB00(track_id, volume, step, request) s32 track_id; s32 volume; s32 step; s32 request; {
    func_800FCB9C(track_id, volume, step, 0, (s32)func_800FB5F8() + (request * 4) + 0x3C);
}

s32 func_800FCB54(s32 track_id, s32 volume, s32 step, f32 delay)
{
    s32 slot = func_800FB5F8();
    func_800FCB9C(track_id, volume, step, 0, slot + 0x3C);
}

// Start the track if idle (volume != 0), then fade toward volume.
void func_800FCB9C(s32 track_id, s32 volume, s32 step, f32 delay, s32 request)
{
    u8 index;
    u8 *slot;
    slot = func_800FB5F8();
    if (slot != 0)
    {
        if ((*((s16 *) (((s8 *) slot) + 0x28))) < 0)
        {
            if (volume != 0)
            {
                func_800FB6E0(slot, 0);
                index = (((s32) (((u8 *) slot) - ((u8 *) (((u8 *) D_801357D0))))) / 80);
                func_800172D4(index, track_id);
                *((s16 *) (((s8 *) slot) + 0x28)) = (s16) track_id;
                *((s32 *) (((s8 *) slot) + 0x20)) = 0;
                *((f32 *) (((s8 *) slot) + 4)) = 0.0f;
                func_800FB6C0(slot, 0);
                if ((*((u8 *) (((s8 *) slot) + 0x34))) == 0)
                {
                    func_80017404((u8) index, 0);
                }
                goto block_5;
            }
        }
        else
        {
            block_5:
            func_800FBF9C(slot, &volume, &step, request);

            *((f32 *) (((s8 *) slot) + 0)) = delay;
            if ((*((s32 *) (((s8 *) slot) + 0x20))) < volume)
            {
                *((s16 *) (((s8 *) slot) + 0x2A)) = (s16) step;
            }
            else
            {
                *((s16 *) (((s8 *) slot) + 0x2A)) = (s16) (-step);
            }
            *((s32 *) (((s8 *) slot) + 0x24)) = volume;
            if (volume != 0)
            {
                func_800FB540(slot);
            }
            else
            {
                func_800FB5BC(slot);
            }
            (*((u8 *) D_801359B0)) = 1;
        }
    }
}

// Return 1 if the track is playing.
s32 func_800FCCD4(s32 track_id)
{
    s32 *slot;
    s32 playing;
    slot = func_800FB5F8(track_id);
    if (slot == NULL || *(s16 *)((char *)slot + 0x28) == -1) {
        playing = 0;
    } else {
        playing = 1;
    }
    return playing;
}

void func_800FCD14(s32 track_id, s32 param_1)
{
    s32 slot;
    slot = func_800FB5F8(track_id);
    if (slot != 0)
    {
        slot -= (s32)&((s32 *) D_801357D0)[0];
        slot /= 0x50;
        slot &= 0xFF;
        func_800174C0(slot, param_1);
    }
}

// Defragment every slot's request list.
void func_800FCD5C(void)
{
    s8 *slot;
    s32 list;
    if (D_80123E40 != 0) { slot = (s8 *) (((s32 *) D_801357D0)); do {
            list = freelist_defrag(*((s32 *) (slot + 0x38)));
            slot += 0x50;
            *((s32 *) (slot - 0x18)) = list;
        }
        while (((u32) slot) < ((u32) (((s32 *) D_801359B0))));
    }
}

int func_800FCDB4()
{
    Actor *slot;
    slot = func_800FB5F8();
    if (slot != NULL)
    {
        return (*(s32 *)((char *)(slot) + 0x2C));
    }
    return 0;
}

s32 func_800FCDE0(s32 param_0, s32 param_1, s32 param_2)
{
    s32 index;
    void *slot;
    slot = func_800FB5F8();
    if (!slot) { return 0; }
    if (((u8 *) slot)[50] != 0 && ((s32 *) slot)[11] == param_1)
    {
        return 1;
    }
    index = (((s32) slot) - ((s32) ((s32 *) D_801357D0))) / 0x50;
    if (func_80017108((u8)index) == param_0)
    {
        if (func_80017210((u8)index) == 1 || func_800177C4(index))
        {
            if (func_800178C4(index, param_1, param_2))
            {
                ((s32 *) slot)[11] = param_1;
                ((u8 *) slot)[50] = 1;
                return 1;
            }
        }
    }
    ((s32 *) slot)[11] = param_1;
    ((u8 *) slot)[50] = 0;
    return 0;
}

int func_800FCED0(s32 param_0, s32 param_1, f32 param_2)
{
    LocalState_800FCED0 *slot;
    slot = func_800FB5F8();
    if (slot != NULL) {
        if (func_80017108(slot - ((LocalState_800FCED0 *) D_801357D0)) != param_0) return 0;
        return func_80017D74(slot - ((LocalState_800FCED0 *) D_801357D0), param_1, param_2);
    }
    return 0;
}

// Return the track's progress flag; 1 if it has none.
int func_800FCF50(int track_id)
{
    s32 i;
    for (i = 0; i < 0x30; i++)
    {
        if (track_id == ((s16 *) D_80123DE0)[i])
        {
            return func_800DA298(i + 0x53E);
        }
    }

    return 1;
}

// TU-NOTE: the .data of this file is defined here in C; values taken from the ROM.
s16 D_80123DE0[48] = { 0x32, 0x33, 0x55, 0x39, 0x38, 0x3E, 0x42, 0x48, 0x40, 0x49, 0x47, 0x4C, 0x45, 0x4B, 0x4F, 0x50, 0x53, 0x3B, 0x52, 0x4E, 0x3F, 0x63, 0x41, 0x56, 0x57, 0x61, 0x76, 0x75, 0x7E, 0x82, 0x7A, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x62, 0x7F, 0x5E, 0x5F, 0x1F, 0x20, 0x65, 0x66, 0x64, 0x54, 0x9A };
u8 D_80123E40 = 0x0;
