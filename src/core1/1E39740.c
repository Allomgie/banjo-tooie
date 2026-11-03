#include "common.h"
#ifndef M2C_MACROS_H
#endif

// TU-NOTE: TTV2C (free-list view) and TTOsc (update view) overlay the same 0x2C-byte oscillator state.
typedef struct TTV2C_s {
    struct TTV2C_s *next;
    u8 type;
    u8 pad5[0x1D];
    s16 max_count;
    s16 cur_count;
    u8 pad26[2];
    union {
        struct {
            u8 depth;
            u8 base;
        } b;
        f32 fdepth;
    } u;
} TTV2C;
typedef struct {
    u8 pad0[4];
    u8 type;
    u8 pad5[0x1D];
    u16 max_count;
    u16 cur_count;
    u8 pad26[2];
    union {
        struct {
            u8 depth;
            u8 base;
        } b;
        f32 fdepth;
    } u;
} TTOsc;
extern f32 func_8001395C(f32);
extern f32 func_80027170(s32);
typedef s32 M2C_UNK;
extern M2C_UNK *D_8007EA40;
typedef struct TTN2C_s {
    struct TTN2C_s *next;
    u8 pad4[0x28];
} TTN2C;
typedef struct {
    u8 pad0[0xC];
    void *heap;
    void *init_osc;
    void *update_osc;
    void *stop_osc;
} TTDrv;
extern TTN2C *D_8007EA44;
extern void *func_80020EE4(void *, s32, void *, s32, s32);

// Pow by squaring: 1.030993f ** exponent (cents to pitch ratio).
f32 func_80021C10(u8 exponent)
{
    f32 base;
    f32 ratio;

    base = 1.030993f;
    ratio = 1.0f;

    while (exponent) {
        if (exponent & 1)
            ratio *= base;
        base *= base;
        exponent >>= 1;
    }

    return ratio;
}

// initOsc callback: takes a state from the free list; returns the volume scaled by 1 << 14.
s32 func_80021C8C(TTV2C **out, f32 *out_value, u8 type, u8 key, u8 vel, u8 vol)
{
    TTV2C *osc;
    s32 ret = 0;

    if (!vol)
        return 0;

    if ((TTV2C *) D_8007EA40) {
        osc = (TTV2C *) D_8007EA40;
        D_8007EA40 = ((TTV2C *) D_8007EA40)->next;
        osc->type = type;
        *out = osc;
        ret = vol << 14;

        switch (type) {
            case 1:
                osc->cur_count = 0;
                osc->max_count = 0x103 - key;
                osc->u.b.depth = vel >> 1;
                osc->u.b.base = 0x7F - osc->u.b.depth;
                *out_value = (f32) (u32) osc->u.b.base;
                break;
            case 0x80:
                osc->u.fdepth = func_80021C10(vel);
                osc->cur_count = 0;
                osc->max_count = 0x103 - key;
                *out_value = 1.0f;
                break;
            default:
                break;
        }
    }

    return ret;
}

// updateOsc callback: advances the sine phase (type 1 tremolo, type 0x80 vibrato); returns 0x3E80.
s32 func_80021E1C(void *osc_state, f32 *out_value)
{
    f32 sine;
    TTOsc *osc = (TTOsc *) osc_state;
    s32 delta_time = 0x3E80;

    switch (osc->type) {
        case 1:
            osc->cur_count++;
            if (osc->cur_count >= osc->max_count)
                osc->cur_count = 0;
            sine = (f32) osc->cur_count / (f32) osc->max_count;
            sine = func_8001395C(sine * 6.2831855f);
            sine = osc->u.b.depth * sine;
            *out_value = osc->u.b.base + sine;
            break;

        case 0x80:
            osc->cur_count++;
            if (osc->cur_count >= osc->max_count)
                osc->cur_count = 0;
            sine = (f32) osc->cur_count / (f32) osc->max_count;
            sine = func_8001395C(sine * 6.2831855f) * osc->u.fdepth;
            *out_value = func_80027170((s32) sine);
            break;

        default:
            break;
    }

    return delta_time;
}

// stopOsc callback: returns the state to the free list.
void func_80022060(M2C_UNK *osc)
{
    *osc = D_8007EA40;
    D_8007EA40 = osc;
}

void func_80022084(TTDrv *drv, s32 count)
{
    TTN2C *node;
    s32 i;

    D_8007EA44 = func_80020EE4(0, 0, drv->heap, count, 0x2C);
    D_8007EA40 = D_8007EA44;
    // Matching: duplicated store needed for the match.
    D_8007EA40 = D_8007EA44;

    node = D_8007EA44;
    for (i = 0; i < count - 1; i++) {
        node->next = D_8007EA44 + i + 1;
        node = node->next;
    }
    node->next = 0;

    drv->init_osc = func_80021C8C;
    drv->update_osc = func_80021E1C;
    drv->stop_osc = func_80022060;
}
