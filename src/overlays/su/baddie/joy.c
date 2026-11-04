#include "common.h"
// TU-NOTE: the .data of this overlay is defined here in C; values come from the ROM.

typedef struct {
    u8 pad0[0x64];
    u32 pad64_29 : 3;
    u32 unk64_27 : 2;
    u32 pad64_0 : 27;
} BaddieJoyActorView;
extern s32 func_80016A74(s32, s32);
extern f32 func_800E3A80(void);
extern f32 func_800136E4(f32);
typedef struct {
    f32 x;
    f32 y;
} JoyStickVector1409;
typedef struct {
    u32 pad_0 : 3;
    u32 controller : 2;
    u32 pad_1 : 27;
} JoyControllerSelector1408;
extern f32 func_80013B70(f32, f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void func_80015F28(s32, s32 *);
extern void func_80015E80(s32, s32 *);
typedef struct JoyControllerFlags {
    u32 pad_0 : 3;
    u32 controller : 2;
    u32 pad_1 : 27;
} JoyControllerFlags;
typedef struct {
    u8 pad[0x64];
    u32 pad64 : 2;
    u32 flag : 1;
    u32 f : 2;
    u32 rest : 27;
} JoyS;
extern void func_80018820(s32, f32, f32);

// Stick direction as a world yaw relative to the camera; fallback_yaw if the stick is idle.
s32 subaddiejoy_entrypoint_0(BaddieJoyActorView *actor, s32 fallback_yaw)
{
    s32 yaw;

    yaw = func_80016A74(actor->unk64_27, 0);
    if (yaw == -1) {
        yaw = fallback_yaw;
    } else {
        yaw = (s32) func_800E3A80() + yaw + 0x5A;
    }
    return (s32) func_800136E4((f32) yaw);
}

// Tests whether the actor's controller has a button pressed.
int subaddiejoy_entrypoint_1(Actor *actor)
{
    u32 buttons[3];
    func_80015F28((*(u32 *) ((char *) actor + 0x64) << 3) >> 30, buttons);
    return buttons[0] == 1;
}

// Like entry 0, with a mode passed through to the stick query.
s32 subaddiejoy_entrypoint_2(BaddieJoyActorView *actor, s32 fallback_yaw, s32 mode)
{
    s32 yaw;

    yaw = func_80016A74(actor->unk64_27, mode);
    if (yaw == -1) {
        yaw = fallback_yaw;
    } else {
        yaw = (s32) func_800E3A80() + yaw + 0x5A;
    }
    return (s32) func_800136E4((f32) yaw);
}

// Returns the stick magnitude clamped to 1 and writes the stick yaw into the actor.
f32 subaddiejoy_entrypoint_3(Actor *actor)
{
    JoyStickVector1409 stick;
    f32 magnitude;
    f32 camera_yaw;
    f32 angle;

    func_80016068(((JoyControllerSelector1408 *) ((u8 *) actor + 0x64))->controller,
                  (f32 *) &stick);
    magnitude = sqrtf(stick.y * stick.y + stick.x * stick.x);
    if (magnitude != 0.0f) {
        angle = func_80013B70(stick.y, stick.x, magnitude);
        camera_yaw = func_800E3A80();
        actor->unk54 = func_800136E4(camera_yaw + angle + 90.0f);
        magnitude = func_800F13F0(1.0f, magnitude);
    }
    return magnitude;
}

// Tests whether any button is pressed or held on the actor's controller.
s32 subaddiejoy_entrypoint_4(BaddieJoyActorView *actor)
{
    s32 btn_a[3];
    s32 btn_b[6];

    func_80015F28(actor->unk64_27, btn_a);
    if (btn_a[0] != 0) {
        return 1;
    }
    func_80015E80(actor->unk64_27, btn_b);
    if ((btn_b[0] != 0) || (btn_b[1] != 0)) {
        return 1;
    }
    return 0;
}

// Tests whether a button was pressed (edge) on the actor's controller.
s32 subaddiejoy_entrypoint_5(BaddieJoyActorView *actor)
{
    s32 btn_a[3];
    s32 btn_b[6];

    func_80015F28(actor->unk64_27, btn_a);
    if (btn_a[0] == 1) {
        return 1;
    }
    func_80015E80(actor->unk64_27, btn_b);
    if ((btn_b[0] == 1) || (btn_b[1] == 1)) {
        return 1;
    }
    return 0;
}

// Matching: needed for the match.
void subaddiejoy_entrypoint_6(Actor *actor)
{
    char *controller_word;
    controller_word = (char *) actor + 0x64;
    func_80016B30(((*(int *) controller_word << 3) & 0xFFFFFFFF) >> (unsigned short) 30);
}

// Matching: needed for the match.
void subaddiejoy_entrypoint_7(Actor *actor)
{
    func_80016B54((u32) (*(s32 *) ((char *) actor + 0x64) * 8) >> 0x1E);
}

// Matching: needed for the match.
void subaddiejoy_entrypoint_8(Actor *actor)
{
    func_80016068(((*(int *) ((char *) actor + 0x64) & 0xFFFFFFFF) << 3) >> 30);
}

// Returns the stick magnitude clamped to 1. flags: 1 = write the stick yaw to out_yaw,// 2 = write the actor's current yaw when the stick is idle.
f32 subaddiejoy_entrypoint_9(Actor *actor, f32 *out_yaw, s32 flags)
{
    f32 stick[2];
    f32 magnitude;
    f32 yaw;

    func_80016068(((JoyControllerFlags *) ((u8 *) actor + 0x64))->controller, stick);
    magnitude = sqrtf(stick[0] * stick[0] + stick[1] * stick[1]);
    if (magnitude != 0.0f) {
        yaw =
            func_800136E4(func_80013B70(stick[1], stick[0], magnitude) + func_800E3A80() + 90.0f);
        magnitude = func_800F13F0(1.0f, magnitude);
        if (flags & 1) {
            *out_yaw = yaw;
        }
    } else if (flags & 2) {
        *out_yaw = actor->rotation[1];
    }
    return magnitude;
}

// Rumbles the actor's controller when its rumble bit is set.
void subaddiejoy_entrypoint_10(JoyS *actor, f32 unk_0, f32 unk_1)
{
    if (actor->flag) {
        func_80018820(actor->f, unk_0, unk_1);
    }
}
