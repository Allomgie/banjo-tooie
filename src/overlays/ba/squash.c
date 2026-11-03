#include "common.h"

typedef struct {
    u8 unk_0;
    u8 state;
    u8 pad_2[2];
    f32 time;
    f32 scale;
} SquashState1559;
extern void func_8009ADF0(void *, s32, s32);
typedef struct {
    u8 index;
    u8 pad_1[3];
    f32 time;
    f32 scale;
} SquashState30;
extern u8 D_808006B0_basquash[];
extern u8 D_808006C4_basquash[];
extern s32 func_8009D454();
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F0F9C(f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800E0AF0(s32, f32);
extern void func_800E0B8C(s32, s32, f32, f32, f32, f32);
extern f32 func_800F1198(f32, f32, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);

s32 basquash_entrypoint_0()
{
    return 0xC;
}

// Sets the squash state: 1 idle, 2 squashed (5 s), 3 springing back.
void func_80800008_basquash(player, new_state) u8 *player;
s32 new_state;
{
    switch (new_state) {
        case 1:
            ((SquashState1559 *) *(void **) (player + 0x11C))->time = 0.0;
            ((SquashState1559 *) *(void **) (player + 0x11C))->scale = 0.0f;
            func_8009ADF0(player, 10, 0);
            break;
        case 2:
            ((SquashState1559 *) *(void **) (player + 0x11C))->unk_0 = 0;
            ((SquashState1559 *) *(void **) (player + 0x11C))->time = 5.0f;
            ((SquashState1559 *) *(void **) (player + 0x11C))->scale = 1.0f;
            func_8009ADF0(player, 10, 1);
            break;
        case 3:
            ((SquashState1559 *) *(void **) (player + 0x11C))->time = 1.7f;
    }
    ((SquashState1559 *) *(void **) (player + 0x11C))->state = new_state;
}

void basquash_entrypoint_1(s32 arg0)
{
}

// Resets to idle.
void basquash_entrypoint_2(u8 *player)
{
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x11C) + 2) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x11C) + 1) = 0;
    func_80800008_basquash(player, 1);
}

// Starts the squash.
void basquash_entrypoint_3(u8 *player, s32 kind)
{
    (*(u8 **) (player + 0x11C))[2] = kind;
    func_80800008_basquash(player, 2);
}

// Spring-back phase: plays a sound at each step and computes the wobbling scale.
void func_80800140_basquash(player) u8 *player;
{
    s32 pad[2]; // Matching: padding local needed for the stack layout.
    f32 phase;
    f32 wave;
    s32 step;
    SquashState30 *squash;
    f32 amplitude;
    f32 wave_phase;
    squash = *(SquashState30 **) (player + 0x11C);
    step = (s32) (squash->time / 0.5666666627f);
    if (step != squash->index) {
        func_8009D454(player, (u8) func_8009D454(player, 0, D_808006B0_basquash),
                      D_808006C4_basquash + step * 12);
        squash = *(SquashState30 **) (player + 0x11C);
    }
    squash->index = step;
    phase = func_800F13C4((*(SquashState30 **) (player + 0x11C))->time, 0.5666666627f);
    wave_phase = func_800F0F9C(phase, 0.15f);
    wave = func_80013970(wave_phase * 360.0f);
    amplitude = func_800F10B4(phase, 0.0f, 0.5666666627f, 0.0f, 0.6f);
    (*(SquashState30 **) (player + 0x11C))->scale = wave * amplitude + (f32) step / 3.0f;
}

// Applies the per-bone scale overrides; which bones depends on the model.
void func_80800260_basquash(player) u8 *player;
{
    f32 scale;
    f32 inv_scale;
    s32 bones;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;

    unk_0 = unk_1 = unk_2 = 0;
    bones = func_80092AD8(player);
    func_800E0AF0(bones, 1.0);
    scale = func_800F0E00(func_800F1198((*(f32 **) (player + 0x11C))[2], 0.0f, 1.0f, 1.0, 0.08f),
                            0.08f);
    inv_scale = 1 / scale;
    switch (func_80092B80(player)) {
        case 0x607:
        case 0x608:
        case 0x61F:
            unk_0 = 1;
            break;
        case 0x61C:
        case 0x83A:
            unk_1 = 1;
            break;
        case 0x60C:
            unk_2 = 1;
    }
    switch ((*(u8 **) (player + 0x11C))[2]) {
        case 1:
            if (unk_2) {
                func_800E0B8C(bones, 0x43, 1.0f, 1.0f, scale, 1.0f);
            } else if (unk_1) {
                func_800E0B8C(bones, 0x6B, 1.0f, 1.0f, scale, 1.0f);
            } else if (unk_0) {
                func_800E0B8C(bones, 1, 1.0f, 1.0f, scale, 1.0f);
                func_800E0B8C(bones, 0x1C, 1.0f, 1.0f, inv_scale, 1.0f);
                func_800E0B8C(bones, 0xE, 1.0f, 1.0f, inv_scale, 1.0f);
            } else {
                func_800E0B8C(bones, 1, 1.0f, 1.0f, scale, 1.0f);
                func_800E0B8C(bones, 0x1C, 1.0f, 1.0f, inv_scale, 1.0f);
                func_800E0B8C(bones, 0xE, 1.0f, 1.0f, inv_scale, 1.0f);
            }
            break;
        case 2:
            func_800E0B8C(bones, 3, 1.0f, scale, 1.0f, 1.0f);
            if (unk_0 || unk_1) {
                func_800E0B8C(bones, 0xA, 1.0f, inv_scale, scale, 1.0f);
                func_800E0B8C(bones, 0x18, 1.0f, inv_scale, scale, 1.0f);
                func_800E0B8C(bones, 0xE, 1.0f, inv_scale, scale, 1.0f);
                func_800E0B8C(bones, 0x1C, 1.0f, inv_scale, scale, 1.0f);
            }
    }
}

// Per-frame update.
void basquash_entrypoint_4(u8 *player)
{
    u8 state;

    func_800D9078(*(u8 **) ((s8 *) player + 0x11C) + 4);
    state = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x11C) + 1);
    switch (state) {
        case 2:
            func_80800260_basquash(player);
            if (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x11C) + 4) == 0.0f) {
                func_80800008_basquash(player, 3);
            }
        case 1:
            return;
        case 3:
            func_80800140_basquash(player);
            func_80800260_basquash(player);
            if (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x11C) + 4) == 0.0f) {
                func_80800008_basquash(player, 1);
            }
    }
}

// TU-NOTE: this overlay's .data (formerly squash.data.s) is defined here in C; values are from the ROM.
u8 D_808006B0_basquash[20] = {0x0, 0x13, 0x4, 0x1D, 0x0,  0x1B, 0x0, 0x16, 0x7F, 0xFF,
                              0x0, 0x1,  0x1, 0x2C, 0x15, 0x7C, 0x0, 0x0,  0x0,  0x0};
u8 D_808006C4_basquash[44] = {0x0,  0xB, 0x1, 0x0, 0x1,  0x80, 0x2,  0x0, 0x0, 0x11, 0x0,
                              0x0,  0x0, 0xB, 0x0, 0xC0, 0x1,  0x40, 0x2, 0x0, 0x0,  0x11,
                              0x0,  0x0, 0x0, 0xB, 0x0,  0x80, 0x1,  0x0, 0x2, 0x0,  0x0,
                              0x11, 0x0, 0x0, 0x0, 0x0,  0x0,  0x0,  0x0, 0x0, 0x0,  0x0};
