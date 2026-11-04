#include "common.h"

extern void func_800EFD24(void *);
extern void *heap_alloc(int);
extern void func_800F18FC();
extern f32 func_800136E4(f32);
extern void func_800C53EC(int, int);
extern void func_8010F9C0(s32, int);
extern void *func_8011001C();

// State: position at 0x0, rotation at 0xC (roll at 0x14), letterbox flag at 0x18.
void *ncfixposrot_entrypoint_0()
{
    void *state;
    state = heap_alloc(0x1C);
    func_800EFD24(state);
    func_800EFD24((char *) state + 0xC);
    *(s16 *) ((char *) state + 0x18) = 0;
    return state;
}

void ncfixposrot_entrypoint_1(void *state)
{
    heap_free(state);
}

// Sets the rotation to look at the target and clears the roll.
void ncfixposrot_entrypoint_2(u8 *state, s32 target)
{
    func_800F18FC(target, state, state + 0xC, target);
    *(f32 *) (state + 0xC) = func_800136E4(-*(f32 *) (state + 0xC));
    *(f32 *) (state + 0x14) = 0.0f;
}

void ncfixposrot_entrypoint_3(void *state, f32 roll)
{
    *(f32 *) ((u8 *) state + 0x14) = func_800136E4(roll);
}

int ncfixposrot_entrypoint_4(s32 state[3])
{
    func_800EE7F8(&state[3]);
}

void ncfixposrot_entrypoint_5()
{
    func_800EE7F8();
}

s32 ncfixposrot_entrypoint_6(s32 state, s32 camera)
{
    func_8010FE14(camera, state, state + 0xC);
}

// Reads position and rotation from a camera-database node.
s32 ncfixposrot_entrypoint_7(s32 state, s32 node)
{
    // Matching: `| 0` is needed for the match.
    func_800A5800(node | 0);
    _cadbfunc_entrypoint_0(state);
    _cadbfunc_entrypoint_2(state + 0xC);
}

int ncfixposrot_entrypoint_8(s32 camera, s32 node)
{
    func_8010F9C0(camera, 3);
    return ncfixposrot_entrypoint_7(func_8011001C(camera), node);
}

// Leaves controller mode 3: removes the letterbox and restores the dynamic camera (mode 2).
void ncfixposrot_entrypoint_9(s32 camera)
{
    void *state;
    state = func_8011001C();
    if (*(s16 *) ((char *) state + 0x18) != 0) {
        func_800C53EC(0, 0);
        *(s16 *) ((char *) state + 0x18) = 0;
    }
    func_8010F9C0(camera, 2);
}

s32 ncfixposrot_entrypoint_10(s32 camera, s32 pos, s32 rot)
{
    s32 state;

    func_8010F9C0(camera, 3);
    state = func_8011001C(camera);
    func_800EE7F8(state, pos);
    func_800EE7F8(state + 0xC, rot);
}

s32 ncfixposrot_entrypoint_11(s32 camera, s32 pos, s32 target)
{
    s32 state;

    func_8010F9C0(camera, 3);
    state = func_8011001C(camera);
    func_800EE7F8(state, pos);
    ncfixposrot_entrypoint_2(state, target);
}

s32 ncfixposrot_entrypoint_12(s32 state, s32 out_pos)
{
    // Matching: `| 0` is needed for the match.
    func_800EE7F8(out_pos | 0, state | 0);
}

int ncfixposrot_entrypoint_13(s32 state, s32 out_rot)
{
    // Matching: `| 0` is needed for the match.
    func_800EE7F8(out_rot | 0, state + 0xC);
}

// Starts the letterbox.
void ncfixposrot_entrypoint_14(Actor *state)
{
    func_800C52F4(0, 0);
    *(s16 *) ((char *) state + 0x18) = 1;
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/fixposrot.data.s) is defined in C; values come from the ROM.
