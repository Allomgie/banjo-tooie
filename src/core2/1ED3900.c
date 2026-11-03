#include "core2/1ED3900.h"

// The 48 slots of D_80123880 are accessed through several overlapping views.
// Layout of a slot (28 bytes):
//   0x00 target_x, 0x02 target_y, 0x04 side (slide direction), 0x06 pos_x, 0x08 pos_y,
//   0x0A dx, 0x0B dy (slide direction signs), 0x0C state (0 hidden, 1 sliding in, 2 shown,
//   3 sliding out), 0x0D step (0..10), 0x0E sub_type, 0x10 active, 0x14 auto-hide timer,
//   0x18 handle of the scinfobar overlay object.
typedef struct {
    s16 target_x;
    s16 target_y;
    u8 side;
    u8 unk_5;
    s16 pos_x;
    s16 pos_y;
    s8 dx;
    s8 dy;
    u8 state;
    u8 step;
    u8 sub_type;
    u8 unk_F;
    u8 active;
    u8 hidden;
    u8 unk_12;
    u8 pad_13;
    u8 pad_14;
    u8 pad_15;
    u8 pad_16;
    u8 pad_17;
    u8 pad_18;
    u8 pad_19;
    u8 pad_1A;
} D_80123880_t;
extern u8 D_801357B0;
extern s32 _scinfobar_entrypoint_0(s32, s32, s32);
extern void _scinfobar_entrypoint_6(s32, s32);
typedef struct {
    s16 target_x;
    s16 target_y;
    u8 side;
    u8 unk_5;
    s16 pos_x;
    s16 pos_y;
    u8 dx;
    u8 dy;
    u8 state;
    u8 step;
    s8 sub_type;
    u8 unk_F;
    u8 active;
    u8 hidden;
    u8 unk_12;
    u8 pad_13;
    u8 pad_14;
    u8 pad_15;
    u8 pad_16;
    u8 pad_17;
    s32 handle;
} D_80123880_type;
typedef struct {
    u8 pad_0[6];
    s16 pos_x, pos_y;
    s8 dx, dy;
    u8 state;
    s8 step, sub_type;
    u8 pad_F;
    u8 active, hidden;
    u8 pad_12[2];
    f32 timer; // auto-hide countdown in seconds
    void *handle;
} EntryFA2C0;
extern f32 func_800D8FF8(void);
extern void _scinfobar_entrypoint_2(void *);
extern s32 _scinfobar_entrypoint_21(void *);
extern s32 D_801239B4;
extern s32 D_80123998;
extern s32 D_80123D6C;
extern s8 D_80123DC0[10];
typedef struct {
    s16 target_x, target_y;
    u8 side, unk_5;
    s16 pos_x, pos_y;
    s8 dx, dy;
    u8 state, step;
    s8 sub_type;
    u8 unk_F, active, hidden, unk_12, pad_13;
    f32 timer;
    s32 handle;
} InfobarState;
extern s32 defrag(s32);
extern void _scinfobar_entrypoint_1(s32);
typedef struct {
    u8 pad_0[24];
    int handle;
} local_struct;
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 handle;
} Struct_80123880;
typedef struct {
    s16 target_x;
    s16 target_y;
    u8 side;
    u8 unk_5;
    s16 pos_x;
    s16 pos_y;
    u8 pad_A[4];
    s8 sub_type;
    u8 pad_F[2];
    u8 hidden;
    u8 unk_12;
    u8 pad_13;
    f32 timer;
    s32 handle;
} local_type;
extern int _scinfobar_entrypoint_23(s32);
extern int _scinfobar_entrypoint_7(s32, s32);
extern s32 _scinfobar_entrypoint_16(s32);
extern int _scinfobar_entrypoint_22(s32);
typedef struct {
    s32 pad_0[3];
    s8 pad_C[2];
    s8 sub_type;
    s8 pad_F;
    s32 pad_10[2];
    s32 handle;
} S80123880;
typedef struct {
    u8 pad_0[0xC];
    u8 state;
    u8 pad_D;
    s8 sub_type;
    u8 pad_F[9];
    s32 handle;
} EntryFA;
// One slot, viewed through the struct each function needs.
typedef union {
    InfobarState i;
    D_80123880_t t;
    D_80123880_type ty;
    EntryFA2C0 e2;
    EntryFA ea;
    S80123880 s;
    Struct_80123880 st;
    local_type lt;
} Elem80123880;
extern Elem80123880 D_80123880[48];
extern u8 D_80123898[];
extern void _scinfobar_entrypoint_5(s32, s32);
int func_800FA874();

// Resets all slots; each starts off its target position, one full slide away.
void func_800FA010()
{
    s32 i;
    f32 slide_len = 0.0f;
    for (i = 0; i < 48; i++) {
        D_80123880[i].t.active = 0;
    }

    // Total distance covered by the 10 easing steps.
    for (i = 0; i < sizeof(D_80123DC0); i++) {
        slide_len += D_80123DC0[i];
    }

    for (i = 0; i < 48; i++) {
        if (D_80123880[i].t.side & 1) {
            D_80123880[i].t.dx = 0;
        } else {
            D_80123880[i].t.dx = 1 - D_80123880[i].t.side;
        }
        if (D_80123880[i].t.side & 1) {
            D_80123880[i].t.dy = D_80123880[i].t.side - 2;
        } else {
            D_80123880[i].t.dy = 0;
        }
        D_80123880[i].t.state = 0;
        D_80123880[i].t.hidden = 0;
        D_80123880[i].t.unk_12 = 0;
        D_80123880[i].t.pos_x =
            (s16) (D_80123880[i].t.target_x - (D_80123880[i].t.dx * slide_len));
        D_80123880[i].t.pos_y =
            (s16) (D_80123880[i].t.target_y - (D_80123880[i].t.dy * slide_len));
    }

    D_801357B0 = 1;
}

// Moves a slot to a new state (0 hidden, 1 sliding in, 2 shown, 3 sliding out) and
// creates, shows, hides or frees its overlay object accordingly.
void func_800FA130(s32 slot, s32 new_state)
{
    if (new_state != D_80123880[slot].ty.state) {
        D_80123880[slot].ty.state = new_state;
        switch (new_state) {
            case 1:
                if (D_80123880[slot].ty.handle) {
                    break;
                }
                D_80123880[slot].ty.handle = _scinfobar_entrypoint_0(
                    D_80123880[slot].ty.sub_type, D_80123880[slot].ty.unk_5,
                    D_80123880[slot].ty.unk_12);
                break;
            case 2:
                if (D_80123880[slot].ty.pos_x != D_80123880[slot].ty.target_x ||
                    D_80123880[slot].ty.pos_y !=
                        *(s16 *) ((char *) &D_80123880[slot].ty + 2)) {
                    D_80123880[slot].ty.pos_x = D_80123880[slot].ty.target_x;
                    D_80123880[slot].ty.pos_y = D_80123880[slot].ty.target_y;
                }
                if (D_80123880[slot].ty.hidden) {
                    break;
                }
                _scinfobar_entrypoint_6(D_80123880[slot].ty.handle, 1);
                break;
            case 3:
                _scinfobar_entrypoint_6(D_80123880[slot].ty.handle, 0);
                break;
            case 0:
                if (D_80123880[slot].ty.handle) {
                    _scinfobar_entrypoint_1(D_80123880[slot].ty.handle);
                    D_80123880[slot].ty.handle = 0;
                }
        }
    }
}

// Requests slide-in (show = 1) or slide-out (show = 0) for a slot.
void func_800FA240(s32 slot, long show)
{
    u8 *entry;
    entry = (u8 *) (u8 *) D_80123880 + (slot * 28);
    entry[0x10] = show;
    switch (show) {
        case 0:
            if (entry[0xC] != 0) {
                func_800FA130(slot, 3);
            }
            return;

        case 1:
            if (entry[0xC] != 2) {
                func_800FA130(slot, 1);
            }
    }
}

// Per frame: counts down the auto-hide timers, then advances the slide animations.
void func_800FA2C0(void)
{
    s32 i;
    // Matching: one-element array for the frame delta, needed for the match.
    f32 dt[1];
    s32 dist;
    dt[0] = func_800D8FF8();
    for (i = 0; i < 48; i++) {
        if (D_80123880[i].e2.active == 1 &&
            func_800FA874(i, D_80123880[i].e2.sub_type)) {
            if (D_80123880[i].e2.timer >= 0.0f) {
                D_80123880[i].e2.timer -= dt[0];
                if (D_80123880[i].e2.timer < 0.0f) {
                    D_80123880[i].e2.timer = 0.0f;
                    func_800FA240(i, 0);
                }
            }
        }
    }
    for (i = 0; i < 48; i++) {
        if (D_80123880[i].e2.handle)
            _scinfobar_entrypoint_2(D_80123880[i].e2.handle);
        switch (D_80123880[i].e2.state) {
            case 1: // sliding in
                if ((u32) D_80123880[i].e2.step < 10) {
                    dist = D_80123DC0[D_80123880[i].e2.step];
                    D_80123880[i].e2.pos_x += D_80123880[i].e2.dx * dist;
                    D_80123880[i].e2.pos_y += D_80123880[i].e2.dy * dist;
                    D_80123880[i].e2.step++;
                }
                if ((u32) D_80123880[i].e2.step >= 10) {
                    D_80123880[i].e2.step = 10;
                    func_800FA130(i, 2);
                }
                break;
            case 2: // shown
                if (_scinfobar_entrypoint_21(D_80123880[i].e2.handle) &&
                    !D_80123880[i].e2.hidden) {
                    _scinfobar_entrypoint_6(D_80123880[i].e2.handle, 1);
                }
                break;
            case 3: // sliding out
                if (_scinfobar_entrypoint_21(D_80123880[i].e2.handle)) {
                    if (D_80123880[i].e2.step > 0) {
                        D_80123880[i].e2.step--;
                        dist = D_80123DC0[D_80123880[i].e2.step];
                        D_80123880[i].e2.pos_x -= D_80123880[i].e2.dx * dist;
                        D_80123880[i].e2.pos_y -= D_80123880[i].e2.dy * dist;
                    }
                    if (D_80123880[i].e2.step <= 0) {
                        D_80123880[i].e2.step = 0;
                        func_800FA130(i, 0);
                    }
                }
        }
    }
}

// Draws all live slots. While func_800A9C98() or func_800DB9B0() is set, only slots
// 10, 11 and 45 are drawn.
void func_800FA508(s32 gfx)
{
    InfobarState *info;
    s32 restricted;
    s32 i;
    if (D_801357B0) {
        restricted = func_800A9C98() || func_800DB9B0();
        for (i = 0; i < 48; i++) {
            info = &D_80123880[i];
            if (info->handle) {
                s32 hideable = info != (InfobarState *) &D_801239B4 &&
                               info != (InfobarState *) &D_80123998 &&
                               info != (InfobarState *) &D_80123D6C;
                if (!restricted || !hideable)
                    _scinfobar_entrypoint_24(gfx, info->handle, info->pos_x,
                                             info->pos_y);
            }
        }
    }
}

// Matching: the line breaks in this function are needed for the match.
// Runs defrag() on the overlay handle of every slot.
void func_800FA608(void)
{
    s32 *cur;
    s32 handle;
    cur = (s32 *) D_80123880; do {
        handle = cur[6];
        if (handle != 0)
        {
            cur[6] = defrag(handle);
        }
        cur += 7;
    }
    while (cur != (s32 *) &D_80123DC0);
}

// Matching: the line breaks in this function are needed for the match.
// Frees the overlay object of every slot.
void func_800FA660()
{
    int handle;
    local_struct *slot;
    u8 *end;
    end = (u8 *) &D_80123DC0; slot = (local_struct *) D_80123880;
    do
    {
        handle = slot->handle;
        if (handle != 0)
        {
            _scinfobar_entrypoint_1((void *) handle);
            slot->handle = 0;
        }
        slot += 1;
    }
    while ((u8 *) slot != end);
}

void func_800FA6B8(s32 slot, s32 unk_0, s32 value)
{
    _scinfobar_entrypoint_3(D_80123880[slot].st.handle, unk_0);
    _scinfobar_entrypoint_8(D_80123880[slot].st.handle, value);
}

// Shows a slot's counter with a value and restarts its 2.0 s auto-hide timer.
// Returns 1 on success, 0 if the overlay object does not accept the change.
int func_800FA708(u32 value, s32 slot, s32 sub_type, u32 unk_0)
{
    local_type *info = &D_80123880[slot].lt;
    if (sub_type != info->sub_type || unk_0 != info->unk_12) {
        if (info->handle && _scinfobar_entrypoint_23(info->handle))
            return 0;
        if (info->handle && !_scinfobar_entrypoint_7(info->handle, sub_type))
            return 0;
    }
    D_80123880[slot].lt.sub_type = sub_type;
    D_80123880[slot].lt.hidden = 0;
    D_80123880[slot].lt.unk_12 = unk_0;
    func_800FA240(slot, 1);
    info->timer = 2.0f;
    if (_scinfobar_entrypoint_16(info->handle) != sub_type &&
        _scinfobar_entrypoint_22(info->handle)) {
        _scinfobar_entrypoint_6(info->handle, 0);
    }
    func_800FA6B8(slot, unk_0, value);
    return 1;
}

// Slides out the slot if it holds this sub-type. Returns 1 if it did.
s32 func_800FA818(s32 slot, s32 sub_type)
{
    S80123880 *info;
    info = &D_80123880[slot].s;
    if (info->handle == 0 || sub_type != info->sub_type) {
        return 0;
    }
    func_800FA240(slot, 0);
    return 1;
}

// Returns nonzero if the slot holds this sub-type and is fully slid in.
int func_800FA874(slot, sub_type)
s32 slot;
s32 sub_type;
{
    InfobarState *info = &D_80123880[slot];
    if (!info->handle || sub_type != info->sub_type)
        return 0;
    return info->state == 2 && _scinfobar_entrypoint_22(info->handle);
}

// Returns -1 if the slot does not hold this sub-type, else whether it is not hidden.
s32 func_800FA8E8(s32 slot, s32 sub_type)
{
    // Matching: the second pointer to the same slot is needed for the match.
    s8 *entry_s8;
    u8 *entry;
    entry = ((s32 *) D_80123880);
    entry = (slot * 0x1C) + entry;
    entry_s8 = (s8 *) entry;

if ((*(s32 *) ((s8 *) entry + 0x18) == 0) || (sub_type != *(s8 *) (entry_s8 + 0xE))) {
    return -1;
}

return (*((u8 *) (((s8 *) entry) + 0xC))) != 0;
}

// Returns -1 if the slot is not live or holds another sub-type, else whether it is fully
// slid in. Returns int, not s32; the header declaration must match.
int func_800FA934(s32 slot, s32 sub_type)
{
    EntryFA *info = &D_80123880[slot].ea;
    s32 handle = info->handle;
    if (!handle || sub_type != info->sub_type)
        return -1;
    return info->state == 2 && _scinfobar_entrypoint_21(handle) != 0;

}

// Enables or disables drawing of the counters.
int func_800FA9A8(int enabled)
{
    {
        D_801357B0 = enabled;
    }

}

void func_800FA9B4(s32 slot, s32 extra)
{
    s32 offset;
    void *handle;

    offset = slot * 28;
    handle = *(void **) ((char *) &D_80123898 + offset);

if (handle != NULL) {
    _scinfobar_entrypoint_9((s32) handle, extra);
}

}

void func_800FA9F4(s32 slot, s32 unk_0)
{
    s32 offset;
    void *handle;

    offset = slot * 28;
    handle = *(void **) ((char *) &D_80123898 + offset);

if (handle != NULL) {
    _scinfobar_entrypoint_4((s32) handle, unk_0);
}

}

void func_800FAA34(s32 slot)
{
    s32 handle;
    handle = *(s32 *) &((s8 *) D_80123898)[slot * 0x1C];

if (handle != 0) {
    _scinfobar_entrypoint_5(handle, 1);
}

}

void func_800FAA74(s32 slot)
{
    s32 handle;
    handle = *(s32 *) &((s8 *) D_80123898)[slot * 0x1C];

if (handle != 0) {
    _scinfobar_entrypoint_5(handle, 2);
}

}

// Switches a live slot to another sub-type and restarts its 2.0 s timer.
// Returns 1 on success.
int func_800FAAB4(s32 slot, s32 sub_type)
{
    InfobarState *info = &D_80123880[slot];
    if (!info->handle)
        return 0;
    info->sub_type = sub_type;
    func_800FA240(slot, 1);
    if (!_scinfobar_entrypoint_7(info->handle, sub_type))
        return 0;
    info->timer = 2.0f;
    _scinfobar_entrypoint_6(info->handle, 0);
    info->hidden = 1;
    return 1;
}

// TU-NOTE: .data is defined here in C (values from the ROM). Linker symbols inside
// D_80123880: D_80123898 = +0x18, D_80123998 = +0x118, D_801239B4 = +0x134,
// D_80123D6C = +0x4EC.
Elem80123880 D_80123880[48] = {
    0x16,  0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0x18, 0x3, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x18, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x32, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x4C, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x66, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x80, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x9A, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0xB4, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0xCE, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x87,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xCE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0x18, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x61,  0x18, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0xAC,  0x18, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0xF7,  0x18, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x86,  0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0x3F, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0x59, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0x8D, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xA7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x3F, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x59, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x73, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0x8D, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0xA7, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x1C,  0x3F, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x1C,  0x63, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x1C,  0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x1C,  0xAB, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x114, 0x3F, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x114, 0x63, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x114, 0x87, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x114, 0xAB, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0xF7,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x86,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0xF7,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x61,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0xAC,  0xCE, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x116, 0xAA, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xCE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x11A, 0xCE, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xAA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x16,  0xB4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0,
    0x87,  0x73, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0x0};
// Easing: distance moved per slide step.
s8 D_80123DC0[10] = {0x15, 0x11, 0xD, 0xA, 0x7, 0x5, 0x3, 0x2, -0x1, -0x1};
// TU-NOTE: zero padding after D_80123DC0.
static u32 D_80123DC0_rest[5] = {0x0, 0x0, 0x0, 0x0, 0x0};
