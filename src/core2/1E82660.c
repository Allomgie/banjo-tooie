#include "core2/1E82660.h"

// Player view slots (D_801276D0). A camera instance per slot follows at +0x58.
typedef struct {
    s16 used, viewport_count; // slots in use, viewports in use
    u8 quad_use[4];     // use count per split-screen quadrant
    s16 quadrant[8];    // quadrant of each slot, -1 = unused
    s32 viewport[8];    // viewport index of each slot
    s32 view[8];        // projection/view object of each slot
} LocalState;
extern s32 D_801276D0[];
extern s32 D_801276F0[];
extern void func_8010FC38(s32);
typedef struct {
    s16 used;
    s16 viewport_count;
} Struct800A8FDC;
extern s16 D_801276D2;
extern u8 D_801276D4;
extern u8 D_801276D5;
extern u8 D_801276D6;
extern u8 D_801276D7[];
typedef struct {
    s16 used, viewport_count;
    u8 quad_use[4];
    s16 quadrant[8];
    s32 viewport[8];
    void *view[8];
    s32 camera[8];
} StateA907C;
extern void *func_800CA334(void);
extern s32 func_8010FB34(void *, s32);
extern void func_80110164();
extern s32 D_80127728[];
extern s32 D_80127708[];
extern s32 D_801276E8[];
extern f32 func_800EEB40(s32 *param_0, s32 param_1);
extern s32 func_800A88C4();
extern s32 func_800A8984(s32 param_0);
extern s32 func_800CA384(s32 param_0);
extern s32 func_80110068(s32 param_0, s32 param_1);
extern s32 D_801276EC[];
extern s32 D_801276F4[];
extern s32 D_80127754;
extern s16 D_80127750;
extern s16 D_80127752;
void func_800A91F4();
int func_800A9420();
void func_800A9828();

// Init: viewport count = number of players if the map allows split screen, else 1.
void func_800A8D70(s32 param_0, s32 param_1)
{
    s32 i;
    _gcstatusDll_entrypoint_1();
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(param_0), 0x20))
        (*(LocalState *) D_801276D0).viewport_count = _gcstatusDll_entrypoint_11();
    else
        (*(LocalState *) D_801276D0).viewport_count = 1;
    for (i = 0; i < (*(LocalState *) D_801276D0).viewport_count; i++)
        func_800A877C(i);
    for (i = 0; i < 8; i++)
        (*(LocalState *) D_801276D0).quadrant[i] = -1;
    for (i = 0; i < 4; i++)
        (*(LocalState *) D_801276D0).quad_use[i] = 0;
    for (i = 0; i < 8; i++)
        (*(LocalState *) D_801276D0).view[i] = 0;
    for (i = 0; i < 8; i += 4) {
        (*(LocalState *) D_801276D0).viewport[i + 1] = 0;
        (*(LocalState *) D_801276D0).viewport[i + 2] = 0;
        (*(LocalState *) D_801276D0).viewport[i + 3] = 0;
        (*(LocalState *) D_801276D0).viewport[i] = 0;
    }
    (*(LocalState *) D_801276D0).used = 0;
}

// Matching: the line breaks in this function are needed for the match.
void func_800A8E9C()
{
    s32 *slot;
    s32 *end;
    do { slot = D_801276D0; end = D_801276F0; } while (0); // Matching: do/while (0) is needed for the match.
    do
    {
        if (slot[0x16] != 0)
        {
            func_8010FC38(slot[0x16]);
        }
        slot++;
    }
    while (slot != end);
}

// Matching: the line breaks in this function are needed for the match.
void func_800A8EF0(s32 param_0, s32 viewport)
{
    s32 *slot;
    s32 camera;
    slot = (s32 *) (u8 *) D_801276D0; do { camera = *(s32 *) ((char *) slot + 0x58); if ((camera != 0) && (viewport == *(s32 *) ((char *) slot + 0x18))) {
            func_8010FAEC(param_0, camera);
        }
        slot += 1;
    }
    while (slot != (s32 *) (u8 *) D_801276F0);
}

// Release all slots and viewports.
int func_800A8F68()
{
    s32 i;
    for (i = 0; i < 8; i++) {
        func_800A91F4(i);
    }

    while (((s16 *) D_801276D0)[1] != 0) {
        func_800A87FC(((s16 *) D_801276D0)[1] - 1);
        ((s16 *) D_801276D0)[1]--;
    }
}

s32 func_800A8FDC(void)
{
    Struct800A8FDC *state;

    func_800A877C(D_801276D2);
    state = (Struct800A8FDC *) D_801276D0;
    return state->viewport_count++;
}

// Index of the first free quadrant, -1 if none.
int func_800A9010()
{
    if (D_801276D4 == 0) {
        return 0;
    }
    if (D_801276D5 == 0) {
        return 1;
    }
    if (D_801276D6 == 0) {
        return 2;
    }
    if (!(D_801276D7[0] != 0)) {
        return 3;
    }
    return -1;
}

// Bind `slot` to a quadrant (-1 = first free) and viewport (-1 = quadrant); creates its
// view object and camera instance. Returns the quadrant, or -1 if none is free.
s32 func_800A907C(s32 slot, s32 quadrant, s32 viewport)
{
    quadrant = quadrant == -1 ? func_800A9010() : quadrant;
    if (quadrant == -1)
        return -1;
    if ((*(StateA907C *) D_801276D0).view[slot])
        return (*(StateA907C *) D_801276D0).quadrant[slot];
    if (viewport == -1)
        viewport = quadrant;
    if (viewport >= (*(StateA907C *) D_801276D0).viewport_count)
        viewport = (*(StateA907C *) D_801276D0).viewport_count - 1;
    (*(StateA907C *) D_801276D0).used++;
    (*(StateA907C *) D_801276D0).quadrant[slot] = quadrant;
    (*(StateA907C *) D_801276D0).quad_use[quadrant]++;
    (*(StateA907C *) D_801276D0).view[slot] = func_800CA334();
    (*(StateA907C *) D_801276D0).camera[slot] =
        func_8010FB34((*(StateA907C *) D_801276D0).view[slot], slot);
    (*(StateA907C *) D_801276D0).viewport[slot] = viewport;
    if ((*(StateA907C *) D_801276D0).quad_use[quadrant] == 1)
        func_800A88C4(viewport, (*(StateA907C *) D_801276D0).view[slot]);
    return quadrant;
}

void func_800A91A8(s32 slot)
{
    if (slot >= 0) {
        s32 idx = slot;
        if (((s16 *) D_801276D0)[idx + 4] != -1) {
            func_800A88C4(((s16 *) D_801276D0)[idx + 4], (s32 *) (s16 *) D_801276D0[idx + 0xE]);
        }
    }
}

// Release a slot: free its camera instance and view object, drop its quadrant use.
void func_800A91F4(slot) s32 slot;
{
    s16 *quadrant_ptr;
    u8 *slot_ptr;
    u8 *state;
    if (slot >= 0) {
        quadrant_ptr = &((s16 *) D_801276D0)[slot];
        slot_ptr = (u8 *) (s16 *) D_801276D0 + (slot * 4);
        if (*(s16 *) ((s8 *) quadrant_ptr + 8) != -1) {
            func_8010FBD4(*(s32 *) ((s8 *) slot_ptr + 0x58));
            *(s32 *) ((s8 *) slot_ptr + 0x58) = 0;
            if (func_800A8984(*(s16 *) ((s8 *) quadrant_ptr + 8)) == *(s32 *) ((s8 *) slot_ptr + 0x38)) {
                // Matching: empty block is needed for the match.
                if (1) {
                }
                func_800A8948(*(s16 *) ((s8 *) quadrant_ptr + 8));
            }
            func_800CA364(*(s32 *) ((s8 *) slot_ptr + 0x38));
            // Matching: empty do/while is needed for the match.
            do {
            } while (0);
            *(s32 *) ((s8 *) slot_ptr + 0x38) = 0;
            state = (u8 *) (s16 *) D_801276D0;
            state += *(s16 *) ((s8 *) quadrant_ptr + 8);
            *(u8 *) ((s8 *) state + 4) = (u8) (*(u8 *) ((s8 *) state + 4) - 1);
            *(s16 *) ((s8 *) quadrant_ptr + 8) = -1;
            ((s16 *) D_801276D0)[0] -= 1;
        }
    }
}

// Matching: the line breaks in this function are needed for the match.
// Broadcast a call to all camera instances.
void func_800A92A8(s32 param_0, s32 param_1)
{
    s32 *p;
    p = (s32 *) D_801276D0; do { if (p[(0x58 / 4) & 0xFFFFFFFFFFFFFFFFu] != 0) {
            func_8010FE00(p[0x58 / 4], param_0, param_1);
        }
        p++;
    }
    while (p != (s32 *) D_801276F0);
}

// Broadcast a call to all camera instances.
void func_800A9318(s32 param_0)
{
    s32 i;
    s32 *slots = (s32 *) (int *) D_801276D0;
    for (i = 0; i < 8; i++) {
        if (slots[i + 0x58 / 4] != 0) {
            func_8010FE34(slots[i + 0x58 / 4], param_0);
        }
    }
}

void func_800A9378(void)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if ((s32 *) D_801276D0[i + 0x16]) {
            if (func_800A9420(i) != 0) {
                func_80110164((s32 *) D_801276D0[i + 0x16]);
            }
        }
    }
}

int func_800A93E4(s32 slot)
{
    return D_80127728[slot];
}

int func_800A93F8(s32 slot)
{
    return D_80127708[slot];
}

int func_800A940C(s32 slot)
{
    return D_801276E8[slot];
}

// Whether the slot's view object is the one bound to its viewport.
int func_800A9420(slot)
s32 slot;
{
    return D_801276D0[slot + 0x38 / 4] == func_800A8984(D_801276D0[slot + 6]);
}

s16 func_800A9460()
{
    return ((s16 *) D_801276D0)[0];
}

s32 func_800A946C(void)
{
    return D_801276D2;
}

// Slot bound to `viewport`; prefers one whose view object is active, else the last match.
int func_800A9478(s32 viewport)
{
    s32 i;
    s32 fallback;
    fallback = -1;
    for (i = 0; i < 8; i++) {
        if (func_800F6438(i) && (D_801276D0[i + 6] == viewport)) {
            if (func_800A9420(i)) {
                return i;
            }
            // Matching: the bare block is needed for the match.
            {
                fallback = i;
            }
        }
    }

    return fallback;
}

// Matching: the line breaks in this function are needed for the match.
// Of all view positions, copy the one nearest to `point` into `out_pos`.
void func_800A9514(s32 out_pos, s32 point) {
    s8 _sfpad[8];
    s32 pos;
    u8 *slot;
    f32 dist;
    f32 min_dist;
    s32 view;

    min_dist = 3.4028235e+38f;
    slot = (u8 *)&D_801276D0; do {
        view = *(s32 *)(slot + 0x38);
        if (view != 0) {
            func_800CA7E4(view, &pos);
            dist = func_800EEB40(&pos, point);
            if (dist < min_dist) {
                min_dist = dist;
                func_800EE7F8(out_pos, &pos);
            }
        }
        slot += 4;
    } while (slot != (u8 *)&D_801276F0);
}

// Matching: the line breaks in this function are needed for the match.
// Refresh each slot's view object (rebinding its viewport if it changed) and camera instance.
void func_800A95C4(void)
{
    s8 *slot;
    s8 *end;
    s32 old_view;
    s32 new_view;
    s32 camera;
    end = (s8 *) &D_801276F0; slot = (s8 *) &D_801276D0; do { if (*(s32 *) (slot + 0x38) != 0) { old_view = *(s32 *) (slot + 0x38);
            new_view = func_800CA384(old_view);
            *(s32 *) (slot + 0x38) = new_view;
            if ((new_view != old_view) && (func_800A8984(*(s32 *) (slot + 0x18)) == old_view))
            {
                func_800A88C4(*(s32 *) (slot + 0x18), *(s32 *) (slot + 0x38));
            }
        }
        camera = *(s32 *) (slot + 0x58);
        if (camera != 0)
        {
            *(s32 *) (slot + (0, 0x58)) = func_80110068(camera, *(s32 *) (slot + 0x38)); // Matching: comma expression is needed for the match.
        }
        slot = slot + 4;
    }
    while (slot != end);
}

int func_800A965C()
{
    return 4 - D_801276D2;
}

// Matching: the line breaks in this function are needed for the match.
// Store the free quadrants in `out`; returns their count.
s32 func_800A9670(s32 *out)
{
    s32 count = 0;
    do { if (D_801276D4 == 0) { out[count++] = 0; } if (D_801276D5 == 0) { out[count++] = 1; } if (D_801276D6 == 0) { out[count++] = 2; } if (*(u8 *) D_801276D7 == 0) { out[count++] = 3; } } while (0); // Matching: do/while (0) is needed for the match.
    return count;
}

// Slot using `quadrant`, -1 if none.
s32 func_800A96F0(s32 quadrant)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (quadrant == ((s16 *) D_801276D0)[i + 4]) {
            return i;
        }
    }

    return -1;
}

s32 func_800A9768(s32 quadrant)
{
    u8 *quadrants;
    s32 slot;

    quadrants = (u8 *) (u8 *) D_801276D0;
    slot = 0;
loop_1:
    if (quadrant == *(s16 *) (quadrants + 8)) {
        return *(s32 *) ((u8 *) &D_801276E8 + (slot * 4));
    }
    if (quadrant == *(s16 *) (quadrants + 0xA)) {
        return *(s32 *) ((u8 *) &D_801276EC + (slot * 4));
    }
    if (quadrant == *(s16 *) (quadrants + 0xC)) {
        return *(s32 *) ((u8 *) &D_801276F0 + (slot * 4));
    }
    if (quadrant == *(s16 *) (quadrants + 0xE)) {
        return *(s32 *) ((u8 *) &D_801276F4 + (slot * 4));
    }
    slot += 4;
    quadrants += 8;
    if (slot == 8) {
        return -1;
    }
    goto loop_1;
}

int func_800A9800()
{
    func_800A9828(0, 0, 0);
}

// Set the render target; 0 selects the default framebuffer and size (0x130 x 0xE4).
void func_800A9828(buffer, width, height) s32 buffer;
s32 width;
s32 height;
{
    D_80127754 = buffer;
    if (width != 0) {
        D_80127750 = width;
    } else {
        D_80127750 = 0x130;
    }
    if (height != 0) {
        D_80127752 = height;
    } else {
        D_80127752 = 0xE4;
    }
    func_800E7F60();
    func_800A8D00(D_80127750, D_80127752);
}

int func_800A989C(void)
{
    return (int) D_80127754 ? (int) D_80127754 : func_80014F00();
}
