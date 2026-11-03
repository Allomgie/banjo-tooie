#include "core2/anctrl.h"

// TU-NOTE: AnimCtrl layout (the header struct is unpopulated): +0x00 timer, +0x04 subrange
// start, +0x08 subrange end, +0x0C duration, +0x10 transition duration, +0x14 start timer,
// +0x18 u16 anim index, +0x1A playback type (1 once, 2 loop, 3 stopped, 4 subrange loop),
// +0x1B flag bits (7 direction, 6 smooth transition, 5 default start, 4-3 timing mode),
// +0x1C embedded Animation.

extern f32 func_800D8FF8(void);
extern f32 _glintrosyncDll_entrypoint_5(void);
typedef struct {
    u32 pad_18 : 25;
    u32 smooth : 1;
    u32 pad_1B : 6;
} local_type_8008AA0C;
extern f32 func_8008C0D0(s32);
extern void func_8008C1F0(s32, s32);
typedef struct {
    u8 pad_0[0x18];
    u32 pad_18 : 24;
    u32 direction : 1;
    u32 pad_1B : 7;
} local_type_8008AAC0;
extern f32 func_8008C0C8(void *);
extern void func_8008C1C0(void *, f32);
typedef struct {
    f32 timer;
    f32 start;
    f32 end;
    u8 pad_C[0xC];
    u16 index;
    u8 playback_type;
    u8 direction : 1;
    u8 pad_1B : 7;
} S8008AB84;
typedef struct {
    u8 pad_0[0x18];
    u32 pad_18 : 24, direction : 1, pad_1B : 7;
} LocalState;
typedef struct {
    char pad_0[0x1B];
    u8 direction : 1;
    u8 smooth : 1;
    u8 default_start : 1;
    u8 pad_1B : 5;
} AcBf_anctrl_reset;
typedef struct {
    f32 timer;
    u8 pad_4[0x10];
    f32 start;
    u16 index;
    u8 playback_type;
    u8 direction : 1;
    u8 smooth : 1;
    u32 default_start : 1;
    u32 pad_1B : 5;
    u8 animation[4];
} S8008AFCC;
typedef struct {
    u8 pad_0[0x18];
    u32 pad_18 : 25;
    u32 smooth : 1;
    u32 pad_1B : 6;
} local_type_anctrl_start;
extern void func_8008C0AC(void *);
extern void func_8008C1B8(void *, s32);
extern void func_8008C1E4(void *, f32);
extern void func_8008C270(void *);
typedef struct {
    f32 timer;
    u8 pad_4[0x10];
    f32 start;
    u16 index;
    u8 playback_type;
    u8 direction : 1;
    u8 smooth : 1;
    u8 default_start : 1;
    u8 timing_mode : 2;
    u8 unk_1B_2 : 1;
    u8 unk_1B_1 : 1;
    u8 unk_1B_0 : 1;
} S8008B134;
typedef struct {
    char pad_0[0x1B];
    u8 direction : 1;
    u8 smooth : 1;
    u8 pad_1B : 6;
} AcBf_anctrl_setSmoothTransition;
extern AssetId func_8008C0C0(void *);
typedef struct {
    f32 timer;
    u8 pad_4[0x17];
    u8 direction : 1, pad_1B : 7;
} LocalAnimCtrl;
extern struct SomeStruct {
    u32 unk_18;
};
extern void func_8008C124(void *, s32);
extern s32 func_800E6A00(void);
s32 func_8008AEDC();
f32 func_8008B2AC(f32 param_0[3]);
void func_8008B518();

// Frame delta in seconds for the controller's timing mode (0 normal, 1 fixed 1/30, 2 intro sync).
f32 func_8008A990(u8 *ctrl)
{
    u32 timing_mode;

    timing_mode = (u32) (*(s32 *) ((char *) ctrl + 0x18) << 0x1B) >> 0x1E;
    switch (timing_mode) {
        case 0:
            return func_800D8FF8();
        case 1:
            return 0.033333f;
        case 2:
            return _glintrosyncDll_entrypoint_5();
        default:
            return func_800D8FF8();
    }
}

// Advances the smooth-transition blend of the embedded animation.
void func_8008AA0C(u8 *ctrl)
{
    s32 animation;
    f32 blend;
    // Matching: extra copy of the parameter.
    u8 *ctrl_copy = ctrl;
    if (((local_type_8008AA0C *) (ctrl + 0x18))->smooth) {
        // Matching: empty block steers IDO's register allocation.
        if (!ctrl_copy) {
        }
        animation = func_8008AEDC();
        blend = func_8008C0D0(animation);
        if (blend < 1.0f) {
            blend += func_8008A990(ctrl_copy) / *(f32 *) ((s8 *) ctrl_copy + 0x10);
            if (blend >= 1.0f) {
                func_8008C1F0(animation, 1);
                blend = 1.0f;
            }
            func_8008C1E4(animation, blend);
        }
    }
}

// Playback type 2: loops over the full range.
void func_8008AAC0(AnimCtrl *ctrl)
{
    void *animation;
    f32 step;
    f32 new_timer;
    animation = func_8008AEDC(ctrl);
    func_8008AA0C(ctrl);
    *(f32 *) ctrl = func_8008C0C8(animation);
    step = func_8008A990(ctrl) / func_8008B2AC(ctrl);
    if (!((local_type_8008AAC0 *) ctrl)->direction)
        step = -step;
    new_timer = *(f32 *) ctrl + step;
    if (new_timer < 0.0f)
        new_timer += 1.0f;
    new_timer -= (s32) new_timer;
    func_8008C1C0(animation, new_timer);
}

// Playback type 4: loops over the subrange.
void func_8008AB84(AnimCtrl *ctrl)
{
    s32 animation;
    S8008AB84 *state = (S8008AB84 *) ctrl;
    // Matching: stack padding needed for the match.
    s8 _sfpad[12];
    f32 delta;
    f32 step;
    f32 pos;
    f32 range;
    f32 phase;

    animation = func_8008AEDC();
    func_8008AA0C(ctrl);
    state->timer = func_8008C0C8(animation);
    delta = func_8008A990(ctrl);
    step = delta / func_8008B2AC(ctrl);
    if (!state->direction) {
        step = -step;
    }
    pos = state->timer + step;
    if (state->end <= pos) {
        range = state->end - state->start;
        phase = (pos - state->start) / range;
        pos = state->start + (phase - (s32) phase) * range;
    }
    func_8008C1C0(animation, pos);
}

// Playback type 1: plays once, then switches to stopped (3).
void func_8008AC4C(u8 *ctrl)
{
    s32 animation;
    f32 new_timer;
    f32 step;

    animation = func_8008AEDC(ctrl);
    func_8008AA0C(ctrl);
    *(f32 *) ctrl = func_8008C0C8(animation);
    step = func_8008A990(ctrl) / func_8008B2AC(ctrl);
    if (!((LocalState *) ctrl)->direction) {
        step = -step;
    }
    new_timer = *(f32 *) ctrl + step;
    if (new_timer < 0.0f) {
        new_timer = 0.0f;
        anctrl_setPlaybackType((AnimCtrl *) ctrl, 3);
    } else if (new_timer > *(f32 *) (ctrl + 8) || new_timer > 0.999999f) {
        if (new_timer > *(f32 *) (ctrl + 8))
            new_timer = *(f32 *) (ctrl + 8);
        if (new_timer > 0.999999f)
            new_timer = 0.999999f;
        anctrl_setPlaybackType((AnimCtrl *) ctrl, 3);
    } else {
        new_timer -= (f32) (s32) new_timer;
    }
    func_8008C1C0(animation, new_timer);
}

// Allocates and initializes a controller.
AnimCtrl *func_8008AD80(s32 unk_0)
{
    s32 *ctrl;

    ctrl = heap_alloc(func_8008C0B8() + 0x1C);
    func_8008B518(ctrl, unk_0);
    return ctrl;
}

void func_8008ADBC(s32 ctrl)
{
    func_8008B5E8();
    heap_free(ctrl);
}

// Per-frame update: dispatches on the playback type.
void func_8008ADE4(u8 *ctrl)
{
    struct {
        u8 pad_0[0x18];
        unsigned int pad_18 : 29;
        unsigned int unk_1B_2 : 1;
    } *bits = (void *) ctrl;

    switch (ctrl[0x1A]) {
        case 1:
            func_8008AC4C(ctrl);
            func_8008C1CC(&ctrl[0x1C], bits->unk_1B_2);
            break;
        case 2:
            func_8008AAC0(ctrl);
            func_8008C1CC(&ctrl[0x1C], bits->unk_1B_2);
            break;
        case 4:
            func_8008AB84(ctrl);
            func_8008C1CC(&ctrl[0x1C], bits->unk_1B_2);
            break;
        case 3:
            func_8008AA0C(ctrl);
            func_8008C1CC(&ctrl[0x1C], bits->unk_1B_2);
        case 0:
            break;
    }
}

AnimCtrl *func_8008AEB4(AnimCtrl *ctrl)
{
    return defrag(ctrl);
}

void anctrl_setIndex(AnimCtrl *ctrl, AssetId anim_id)
{
    *(s16 *) ((u8 *) ctrl + 0x18) = anim_id;
}

s32 func_8008AEDC(ctrl)
s32 ctrl;
{
    return ctrl + 0x1C;
}

int func_8008AEE4(s32 ctrl)
{
    func_8008C1D4(ctrl + 0x1C);
}

int func_8008AF04(s32 ctrl)
{
    func_8008C1DC(ctrl + 0x1C);
}

void anctrl_reset(AnimCtrl *ctrl)
{
    *(u8 *) ((char *) ctrl + 0x1A) = 2;
    ((AcBf_anctrl_reset *) ctrl)->default_start = 1;
    *(f32 *) ((char *) ctrl + 0x0) = 0.0f;
    *(f32 *) ((char *) ctrl + 0x14) = 0.0f;
    anctrl_setSmoothTransition(ctrl, 1);
    anctrl_setSubrange(ctrl, 0, 1.0f);
    anctrl_setDuration(ctrl, 2.5678000450134277f);
    func_8008B1C8(ctrl, 0.2f);
    func_8008B188(ctrl, 1);
    func_8008B2E8(ctrl, func_800E6A00() ? 2 : 0);
}

// Puts the animation timer at the start position.
void func_8008AFCC(AnimCtrl *ctrl)
{
    S8008AFCC *state = (S8008AFCC *) ctrl;

if (state->default_start) {
    if (state->direction == 1) {
        func_8008C1C0(state->animation, 0.0f);
    } else {
        func_8008C1C0(state->animation, 0.999999f);
    }
} else {

func_8008C1C0(state->animation, state->start);
}
state->timer = func_8008C0C8(state->animation);
}

void anctrl_start(AnimCtrl *ctrl)
{
    if (((local_type_anctrl_start *) ctrl)->smooth && func_8008C0C0((u8 *) ctrl + 0x1C)) {
        func_8008C0AC((u8 *) ctrl + 0x1C);
        func_8008C1B8((u8 *) ctrl + 0x1C, *(s16 *) ((u8 *) ctrl + 0x18));
        func_8008AFCC(ctrl);
        func_8008C1E4((u8 *) ctrl + 0x1C, 0.0f);
    } else {
        func_8008C270((u8 *) ctrl + 0x1C);
        func_8008C1B8((u8 *) ctrl + 0x1C, *(s16 *) ((u8 *) ctrl + 0x18));
        func_8008AFCC(ctrl);
        func_8008C1E4((u8 *) ctrl + 0x1C, 1.0f);
    }
}

void func_8008B10C(AnimCtrl *ctrl, f32 timer)
{
    func_8008C1C0((u8 *) ctrl + 0x1C, timer);
}

void anctrl_setPlaybackType(ctrl, type) AnimCtrl *ctrl;
s32 type;
{
    S8008B134 *state = (S8008B134 *) ctrl;
    state->playback_type = type & 0xFFu;
    switch (type) {
        case 1:
        case 3:
            state->unk_1B_2 = 0;
            break;
        case 2:
        case 4:
            state->unk_1B_2 = 1;
    }
}

void func_8008B188(ctrl, direction) AnimCtrl *ctrl;
s32 direction;
{
    // Matching: the two temporaries are needed for the match.
    unsigned short shifted;
    unsigned char value;
    value = direction;
    *((u8 *) (((char *) ctrl) + 0x1B)) =
        ((*((u8 *) (((char *) ctrl) + 0x1B))) & 0xFF7F) | (shifted = value << 7);
}

void anctrl_setSmoothTransition(ctrl, smooth) AnimCtrl *ctrl;
s32 smooth;
{
    ((AcBf_anctrl_setSmoothTransition *) ctrl)->smooth = smooth;
}

void anctrl_setDuration(AnimCtrl *ctrl, f32 duration)
{
    *(f32 *) ((u8 *) ctrl + 0xC) = duration;
}

void func_8008B1C8(AnimCtrl *ctrl, f32 transition_duration)
{
    *(f32 *) ((char *) ctrl + 0x10) = transition_duration;
}

void anctrl_setSubrange(AnimCtrl *ctrl, f32 start, f32 end)
{
    *(f32 *) ((char *) ctrl + 0x4) = start - (s32) start;
    if (end != 1.0f) {
        *(f32 *) ((char *) ctrl + 0x8) = end - (s32) end;
    } else {
        *(f32 *) ((char *) ctrl + 0x8) = end;
    }
}

// Gets the subrange start and end.
func_8008B238(f32 ctrl[3], f32 *start, f32 *end)
{
    *start = ctrl[1];
    *end = ctrl[2];
}

void anctrl_setStart(AnimCtrl *ctrl, f32 start)
{
    // Clears the default-start flag.
    (*(u8 *) ((char *) (ctrl) + 27)) &= ~0x20;
    *(f32 *) ((char *) ctrl + 0x14) = start;
}

AssetId anctrl_getIndex(AnimCtrl *ctrl)
{
    return func_8008C0C0((u8 *) ctrl + 0x1C);
}

s32 anctrl_getPlaybackType(AnimCtrl *ctrl)
{
    return *(u8 *) ((u8 *) ctrl + 0x1A);
}

// Gets the direction flag.
s32 func_8008B28C(AnimCtrl *ctrl)
{
    u8 *flags;
    flags = &((u8 *) ctrl)[0x1B];
    // Matching: the repeated masks are needed for the match.
    return (((((((((*flags) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) &
               0xFFFFFFFF) &
              0xFFFFFFFF) &
             0xFFFFFFFF) &
            0xFFFFFFFF) >>
           7;
}

// Gets the smooth-transition flag.
u32 func_8008B29C(struct SomeStruct *ctrl)
{
    u32 bits;
    u32 result;
    result = *((s32 *) (((char *) ctrl) + 0x18));
    bits = result;
    // Matching: empty block steers IDO's register allocation.
    if ((!bits) && (!bits)) {
    }
    bits = bits << 0x19;
    result = bits >> 0x1F;
    return result;
}

// Gets the duration.
f32 func_8008B2AC(f32 ctrl[3])
{
    return ctrl[3];
}

f32 anctrl_getAnimTimer(AnimCtrl *ctrl)
{
    return func_8008C0C8((u8 *) ctrl + 0x1C);
}

// Gets the controller's own timer.
f32 func_8008B2D4(f32 ctrl[3])
{
    return ctrl[0];
}

// Sets the controller's own timer.
func_8008B2DC(f32 *ctrl, f32 timer)
{
    *ctrl = timer;
}

// Sets the timing mode read by func_8008A990.
void func_8008B2E8(ctrl, timing_mode) AnimCtrl *ctrl;
s32 timing_mode;
{
    typedef struct {
        u8 pad_0[0x1B];
        u8 pad_1B : 3;
        u8 timing_mode : 2;

}
Struct8008B2E8;

((Struct8008B2E8 *) ctrl)->timing_mode = timing_mode;
}

int func_8008B304(s32 ctrl)
{
    func_8008C038(ctrl + 0x1C);
}

s32 anctrl_isStopped(AnimCtrl *ctrl)
{
    return anctrl_getPlaybackType(ctrl) == 3;
}

// True if `target` was crossed between the controller timer and the animation timer.
int anctrl_isAt(AnimCtrl *ctrl, f32 target)
{
    f32 anim_timer;
    anim_timer = func_8008C0C8((u8 *) ctrl + 0x1C);
    if (anim_timer == ((LocalAnimCtrl *) ctrl)->timer)
        return 0;
    if (((LocalAnimCtrl *) ctrl)->direction == 1) {
        if (((LocalAnimCtrl *) ctrl)->timer < anim_timer) {
            return ((LocalAnimCtrl *) ctrl)->timer <= target && target < anim_timer;
        } else {

return ((LocalAnimCtrl *) ctrl)->timer <= target || target < anim_timer;
}
}
else
{
    if (anim_timer < ((LocalAnimCtrl *) ctrl)->timer) {
        return target <= ((LocalAnimCtrl *) ctrl)->timer && anim_timer < target;
    } else {
        return target <= ((LocalAnimCtrl *) ctrl)->timer || anim_timer < target;
    }
}
}

// Sets the flag at bit 2 of byte 0x1B.
// Matching: the temporaries and the empty block are needed for the match.
void func_8008B4A8(u8 *ctrl, u32 value)
{
    int offset;
    char shifted;
    ctrl[offset = 0x1B] = (u8) ((ctrl[offset] & 0xFFFB) | ((shifted = value * 4) & 4));
    {
    }
}

// Gets the flag at bit 2 of byte 0x1B.
// Matching: the temporary, the empty if and the comma expression are needed for the match.
int func_8008B4C4(ctrl)
{
    u32 saved;
    u32 bits;
    bits = (*((s32 *) (((char *) ctrl) + 24))) << 29;
    saved = bits;
    if (((bits && bits) & 0xFFFFFFFF) && bits) {
    }
    bits = (0, saved >> 31);
    return bits;
}

s32 func_8008B4D4(AnimCtrl *ctrl)
{
    func_8008C27C(ctrl + 0x1C);
}

int func_8008B4F4()
{
    return func_8008C0B8() + 0x1C;
}

// Initializes a controller with default settings.
void func_8008B518(ctrl, unk_0) AnimCtrl *ctrl;
s32 unk_0;
{
    func_8008C124((u8 *) ctrl + 0x1C, 1);
    ((S8008B134 *) ctrl)->playback_type = 0;
    ((S8008B134 *) ctrl)->index = 0;
    ((S8008B134 *) ctrl)->default_start = 1;
    ((S8008B134 *) ctrl)->timer = 0.0f;
    ((S8008B134 *) ctrl)->start = 0.0f;
    if (func_800E6A00() != 0) {
        ((S8008B134 *) ctrl)->timing_mode = 2;
    } else {
        ((S8008B134 *) ctrl)->timing_mode = 0;
    }
    ((S8008B134 *) ctrl)->unk_1B_2 = 1;
    anctrl_setSubrange(ctrl, 0.0f, 1.0f);
    anctrl_setDuration(ctrl, 2.1234f);
    func_8008B1C8(ctrl, 0.2f);
    anctrl_setSmoothTransition(ctrl, 1);
    func_8008B188(ctrl, 1);
}

int func_8008B5E8(s32 ctrl)
{
    func_8008C0D8(ctrl + 0x1C);
}
