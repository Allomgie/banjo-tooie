#include "common.h"

extern s32 D_808004E0_subaddiefx[];
extern s32 D_80800500_subaddiefx[];
extern f32 func_80103EAC();
extern f32 func_8010A40C();
extern f32 func_80103EF4();
extern s32 _subaddieskeleton_entrypoint_2(s32, s32, s32 *);
extern void func_800EE7F8(void *, void *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern f32 func_80013970(f32);
extern s32 func_800B5BE4(s32);
extern void func_800BA3FC(s32, s32);
extern void func_800BABB8(s32, f32 *, s32, f32, s32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern u8 *func_80104118(void);
extern void func_800E3980(f32 *);
extern f32 func_800EEB40(f32 *, s32 *);
extern s32 _subaddieaudioloop_entrypoint_7();

typedef struct {
    s32 ring_a : 15;
    s32 ring_b : 15;
    u32 counted : 2;
    s16 phase_a;
    s16 phase_b;
} FxState;

// Per-frame stun effect: two counter-rotating rings of 4 particles around the bone (or above the
// actor); keeps one shared loop sound at the user nearest the camera.
void subaddiefx_entrypoint_0(u8 *actor, s32 bone, FxState *state)
{
    f32 center[3];
    f32 radius;
    f32 pos[3];
    f32 offset[3];
    f32 value;
    f32 bob_b;
    f32 dt;
    f32 extra_radius;
    f32 bob_a;
    f32 angle;
    s32 emitter_a;
    s32 emitter_b;
    s32 i;
    f32 cam_pos[3];
    u8 *shared;
    angle = func_80103EAC(actor);
    radius = func_8010A40C(actor) * angle;
    if ((bone == -1) ||
        (_subaddieskeleton_entrypoint_2(*(s32 *) (actor + 0), bone, (s32 *) center) == 0)) {
        func_800EE7F8(center, actor + 4);
        value = func_80103EF4(actor);
        center[1] += 0.8f * value;
    }
    if (((Actor *) actor)->unk7C_12) {
        extra_radius = 0.0f;
        dt = func_800D8FF8();
        bob_a = state->phase_a * 0.00390625f;
        bob_b = state->phase_b * 0.00390625f;
        emitter_a = func_800B5BE4(0x15);
        emitter_b = func_800B5BE4(0x16);
        func_800BA3FC(emitter_a, 0x9E0);
        func_800BA3FC(emitter_b, 0x9E9);
        for (i = 0, angle = 0.0f; i != 4; i++) {
            func_800EEB9C(offset, state->ring_a + angle, radius + extra_radius);
            func_800EE780(pos, center, offset);
            value = func_80013970(bob_a + angle);
            pos[1] += 30.0f * value;
            func_800BABB8(emitter_a, pos, 0, 1.0f, &D_808004E0_subaddiefx);
            func_800EEB9C(offset, state->ring_b + angle, radius + extra_radius);
            extra_radius = 40.0f;
            func_800EE780(pos, center, offset);
            value = func_80013970(bob_b + angle);
            pos[1] += 30.0f * value;
            func_800BABB8(emitter_b, pos, 0, 1.0f, &D_808004E0_subaddiefx);
            angle += 90.0f;
        }
        state->ring_a = func_800136E4(state->ring_a + 390.0f * dt);
        state->ring_b = func_800136E4(state->ring_b - 430.0f * dt);
        bob_a += dt * 100.0f;
        bob_b += dt * 150.0f;
        state->phase_a = 256.0f * bob_a;
        state->phase_a = 256.0f * bob_b;
    }
    shared = func_80104118();
    if ((*(s16 *) (shared + 0xE) == 0) || (shared[0xD] == 0)) {
        func_800EE7F8(shared, center);
        shared[0xD] = 1;
    } else {
        func_800E3980(cam_pos);
        value = func_800EEB40(cam_pos, (s32 *) center);
        if (value < func_800EEB40(cam_pos, (s32 *) shared)) {
            func_800EE7F8(shared, center);
        }
    }
    shared[0xC] = _subaddieaudioloop_entrypoint_7(
        shared[0xC], shared, 1, &D_80800500_subaddiefx, *(s32 *) (actor + 0x70) & 1);
    if (state->counted == 0) {
        state->counted = 1;
        *(s16 *) (shared + 0xE) = (s16) (*(s16 *) (shared + 0xE) + 1);
    }
}

// Stop the effect; the shared loop sound stops when the last user leaves.
void subaddiefx_entrypoint_1(s32 unk_0, u8 *state)
{
    u8 *shared;
    u8 *shared_copy;

    if (*(s32 *) state & 3) {
        shared = func_80104118();
        *(s16 *) ((s8 *) state + 4) = 0;
        *(s16 *) ((s8 *) state + 6) = 0;
        *(u8 *) ((s8 *) state + 3) = (u8) (*(u8 *) ((s8 *) state + 3) & 0xFFFC);
        *(s8 *) ((s8 *) shared + 0xD) = 0;
        *(s16 *) ((s8 *) shared + 0xE) = (s16) (*(s16 *) ((s8 *) shared + 0xE) - 1);
        if (*(s16 *) ((s8 *) shared + 0xE) == 0) {
            // Matching: the extra copy of the pointer is needed for the match.
            shared_copy = shared;
            *(s8 *) ((s8 *) shared_copy + 0xC) =
                _subaddieaudioloop_entrypoint_3(*(u8 *) ((s8 *) shared + 0xC), state);
        }
    }
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM); the externs of
// D_808004E0_subaddiefx and D_80800500_subaddiefx are declared as s32[] to match the object.
s32 D_808004E0_subaddiefx[8] = {0x161100, 0x220040, 0x4C0000, 0x15, 0x0, 0x2B0026, 0x26011A, 0x0};
s32 D_80800500_subaddiefx[4] = {0x1305C3, 0xD00F3, 0x10C0000, 0x0};
