// Talon Torpedo state: remaining torpedo time (drained per frame, shown on the HUD), mode,
// body spin, tail bend and motor sound, with setters and getters for the torpedo state.
#include "common.h"
#include "playerstate.h"

extern void func_8009EA08(f32);
extern void func_800C2FDC();
// Talon Torpedo state at PlayerState+0xB0
typedef struct {
    f32 unk_0[3];
    u8 mode;
    u8 pad_D[3];
    f32 time_left;
    f32 spin_angle;
    f32 spin_rate;
    u8 sfx_handle;
} KazTorpedoState;
typedef struct {
    u8 pad_0[0xB0];
    KazTorpedoState *state;
} KazTorpedoPlayer;
extern f32 func_8009EA88(PlayerState *);
extern u8 D_80800420_bakaztorpedo[];
typedef struct {
    f32 tail_bend;
    f32 tail_bend_target;
    f32 unk_8;
    u8 mode;
    u8 pad_D[3];
    f32 time_left;
    f32 spin_angle;
    f32 spin_rate;
    u8 sfx_handle;
} KazTorpedoUpdateState;
typedef struct {
    u8 pad_0[0xB0];
    KazTorpedoUpdateState *state;
    u8 pad_B4[0xD0];
    s32 unk_184;
} KazTorpedoUpdatePlayer;
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800F1574(f32 *, f32);
extern void *func_80092AD8(void *);
extern void func_800E0AF0(void *, f32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void func_800C31DC(s32, f32);

s32 bakaztorpedo_entrypoint_0()
{
    return 0x20;
}

f32 bakaztorpedo_entrypoint_1(s32 player)
{
    return *(f32 *) (*(s32 *) (player + 0xB0) + 0x10);
}

void bakaztorpedo_entrypoint_2(u8 *player)
{
    func_8009EA08(*(f32 *) (*(u8 **) (player + 0xB0) + 0x10));
    func_800C2FDC(*(*(u8 **) (player + 0xB0) + 0x1C));
}

void bakaztorpedo_entrypoint_3(void *player)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xB0) + 0x10) = 20.0f;
}

void bakaztorpedo_entrypoint_4(PlayerState *player)
{
    ((KazTorpedoPlayer *) player)->state->unk_0[0] =
        ((KazTorpedoPlayer *) player)->state->unk_0[1] =
            ((KazTorpedoPlayer *) player)->state->unk_0[2] = 0.0f;
    ((KazTorpedoPlayer *) player)->state->time_left = func_8009EA88(player);
    ((KazTorpedoPlayer *) player)->state->mode = 1;
    ((KazTorpedoPlayer *) player)->state->spin_angle =
        ((KazTorpedoPlayer *) player)->state->spin_rate = 0.0f;
    ((KazTorpedoPlayer *) player)->state->sfx_handle =
        func_8009D454(player, 0, D_80800420_bakaztorpedo);
}

void bakaztorpedo_entrypoint_5(u8 *player, f32 bend_target, f32 unk_8)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xB0) + 4) = bend_target;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xB0) + 8) = unk_8;
}

void bakaztorpedo_entrypoint_6(void *player, s32 mode)
{
    ((s8 *) *(void **) ((char *) player + 0xB0))[12] = mode;
}

int bakaztorpedo_entrypoint_7(s32 player, f32 spin_rate)
{
    // Matching: the offset and address temporaries are needed for the match.
    int state_offset;
    int state_addr;
    state_offset = 0xB0;
    *(f32 *) (*(s32 *) (state_addr = player + state_offset) + (0x18 & 0xFFFFFFFF)) = spin_rate;
}

// Per frame: drain the torpedo time, update the HUD counter, spin the body bone and motor sfx
void bakaztorpedo_entrypoint_8(KazTorpedoUpdatePlayer *player)
{
    f32 drain_rate;
    f32 dt;
    f32 prev_time;
    void *bones;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 drain;
    s32 counter;
    f32 pitch;
    Vec3f pos;

    dt = func_800D8FF8();
    switch (player->state->mode) {
        case 2:
            drain_rate = 1.0f;
            break;
        case 3:
            drain_rate = 1.0f;
            break;
        case 4:
            drain_rate = 3.0f;
            break;
        default:
            drain_rate = 0.0f;
            break;
    }
    prev_time = player->state->time_left;
    unk_1 = func_8008E124(player);
    unk_2 = func_800C954C();
    unk_0 = func_800F8004(player->unk_184);
    drain = !unk_1 && !unk_2 && !unk_0;
    if (drain) {
        func_800F1574(&player->state->time_left, dt * drain_rate);
    }
    if (prev_time > 0.1f && player->state->time_left <= 0.1f) {
        func_800FC660(0x19);
    }
    counter = player->state->time_left > 0.0f
                  ? (s32) func_800F10B4(player->state->time_left, 0, 20.0f, 1.0f, 20.99f)
                  : 0;
    func_800D2498(0xCB, counter, 0);
    player->state->spin_angle =
        func_800136E4(player->state->spin_angle + player->state->spin_rate * dt);
    bones = func_80092AD8(player);
    func_800E0AF0(bones, 1.0f);
    func_800E0AFC(bones, 0x5D, 1.0f, 0, 0, player->state->spin_angle);
    if (player_inWater(player)) {
        func_8009C128(player, pos.f);
        pitch = func_800F10B4(player->state->spin_rate, 300.0f, 1200.0f, 0.7f, 1.5f);
        func_800C35E8(player->state->sfx_handle, pos.f);
        func_800C31DC(player->state->sfx_handle, pitch);
        func_800C3BDC(player->state->sfx_handle);
    }
    player->state->tail_bend =
        func_800F15F8(player->state->tail_bend, player->state->tail_bend_target, dt * 100.0f);
    func_800E0AFC(bones, 0x6C, 1.0f, player->state->tail_bend, 0, 0);
    func_800E0AFC(bones, 0x6C, 1.0f, 0, player->state->unk_8, 0);
}

// TU-NOTE: the .data of this overlay is defined here in C, values taken from the ROM.
u8 D_80800420_bakaztorpedo[32] = {0x2,  0x6, 0x0, 0x13, 0x6, 0x31, 0x0,  0x1B, 0x0, 0x16, 0x55,
                                  0xF0, 0x0, 0xA, 0x1,  0x0, 0x0,  0x11, 0x0,  0x0, 0x0,  0x0,
                                  0x0,  0x0, 0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0};
