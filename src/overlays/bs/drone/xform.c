#include "common.h"
#include "overlays/ba/playerstate.h"

#define DXF (*(DroneXformData **) ((u8 *) this + 0x18C))
extern void func_800BA3FC(s32, s32);
extern void *D_808011F0_bsdronexform;
typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
} DroneTransformState;
typedef struct {
    u8 pad_0[0x18C];
    DroneTransformState *mem;
} DroneTransformPlayer;
extern void func_800BA7C4(s32, f32, f32);
extern u8 D_8080121C_bsdronexform[];
extern u8 D_80801248_bsdronexform[];
extern u8 D_80801274_bsdronexform[];
extern u8 D_808012B8_bsdronexform[];
extern u8 D_808012D0_bsdronexform[];
extern u8 D_808012F0_bsdronexform[];
extern u8 D_80801334_bsdronexform[];
extern u8 D_8080134C_bsdronexform[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
typedef struct {
    u8 pad_0[0x20];
    f32 elapsed;
    f32 scale;
    f32 wobble;
} DroneScaleData;
typedef struct {
    u8 pad_0[0x18C];
    DroneScaleData *mem;
} DroneScalePlayer;
extern void *func_800F53D0(s32);
extern f32 func_800F1074(f32, f32);
extern void _bsdronexform_entrypoint_0(void);
extern void func_8008C9D8();
extern f32 func_800D8FF8();
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 _batimer_get(s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F0F9C(f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern f32 func_8009C150(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 func_800CA3F4(s32, f32 *, f32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
typedef struct {
    u8 pad_0[0x1C];
    u8 spiral_active;
    u8 pad_1D[0x2C - 0x1D];
    f32 unk_2C;
    u8 pad_30[2];
    u8 phase;
} DroneXformData;
extern s32 _batimer_decrement(PlayerState *, s32);
extern void func_8009C118(PlayerState *, f32);
extern void func_800C59F0(s32, s32, s32);
extern s32 _badata_entrypoint_34(PlayerState *);
extern void bs_setState(PlayerState *, s32);

void func_80800000_bsdronexform(s32 player, s32 emitter, s32 unk_2)
{
    // Matching: the "| 0" is needed for the match.
    func_800BABB8(emitter | 0, 0, 0, 1.0f, &D_808011F0_bsdronexform);
    func_800BA3FC(emitter, unk_2);
}

void func_80800050_bsdronexform(PlayerState *player, s32 emitter, f32 dir_x, f32 dir_z)
{
    s16 vel_x;
    s16 vel_z;
    vel_x = dir_x * 30.0f;
    vel_z = dir_z * 30.0f;
    func_800BA930(emitter, vel_x, 10, vel_z, vel_x, 10, vel_z);
    func_800BA7C4(emitter, ((DroneTransformPlayer *) player)->mem->unk_14,
                  ((DroneTransformPlayer *) player)->mem->unk_14);
}

// Moves the two sparkle emitters along opposing spirals around the player.
void func_808000E4_bsdronexform(void *player)
{
    f32 angle;
    f32 phase;
    f32 dir_z;
    f32 dir_x;
    f32 time;
    f32 pos[3];

    func_8008FE68(&pos);
    time = *(f32 *) (*(u8 **) ((u8 *) player + 0x18C) + 8);
    phase = func_800F0F9C(time, 0.38f);
    dir_x = func_800137F4(360.0f * phase);
    dir_z = func_80013788();
    pos[0] += dir_x * *(f32 *) (*(u8 **) ((u8 *) player + 0x18C) + 0x18);
    pos[1] += func_800F1214(func_800F0F9C(time, 1.14f), 0.0f, 130.0f);
    pos[2] += dir_z * *(f32 *) (*(u8 **) ((u8 *) player + 0x18C) + 0x18);
    func_80800050_bsdronexform(player, *(s32 *) (*(u8 **) ((u8 *) player + 0x18C) + 4), dir_x,
                               dir_z);
    func_800BA75C(*(s32 *) (*(u8 **) ((u8 *) player + 0x18C) + 4), &pos);
    func_800BA22C(*(s32 *) (*(u8 **) ((u8 *) player + 0x18C) + 4), 1);
    func_8008FE68(&pos);
    angle = (1.0f - func_800F13C4(phase + 0.5f, 1.0f)) * 360.0f;
    pos[0] -= func_80013970(angle) * *(f32 *) (*(u8 **) ((u8 *) player + 0x18C) + 0x18);
    pos[1] += func_800F1214(func_800F0F9C(time, 1.14f), 130.0f, 0.0f);
    pos[2] -= func_800138D0(angle) * *(f32 *) (*(u8 **) ((u8 *) player + 0x18C) + 0x18);
    func_80800050_bsdronexform(player, **(s32 **) ((u8 *) player + 0x18C), dir_x, dir_z);
    func_800BA75C(**(s32 **) ((u8 *) player + 0x18C), &pos);
    func_800BA22C(**(s32 **) ((u8 *) player + 0x18C), 1);
}

// Frees both sparkle emitters.
void func_808002CC_bsdronexform(Actor *player)
{
    func_800B5450(*(*(void ***) ((char *) player + 0x18c) + 1));
    func_800B5450(**(void ***) ((char *) player + 0x18c));
}

// Creates the two sparkle emitters and sets the initial spiral parameters.
void func_80800304_bsdronexform(player) u8 *player;
{
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0))) = func_800B53A4(0x32);
    func_80800000_bsdronexform(
        player, (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0))), 0x6F7);
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (4))) = func_800B53A4(0x32);
    func_80800000_bsdronexform(
        player, (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (4))), 0x6F8);
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0x10))) = 0.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (8))) = 0.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0xC))) = 1.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0x18))) = 55.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0x14))) = 0.35f;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x18C)))) + (0x1C))) = 0;
}

void func_808003BC_bsdronexform(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x18C) + 0xC) = value;
}

int func_808003CC_bsdronexform(s32 player, f32 value)
{
    *((f32 *) ((*((s32 *) (player + 396))) + 0x18)) = value;
}

func_808003DC_bsdronexform(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 396) + 20) = value;
}

void func_808003EC_bsdronexform(void *player, f32 *pos)
{
    s32 emitter;

    func_800BABB8(0, pos, 0, 1.0f, D_8080121C_bsdronexform);
    func_800BABB8(0, pos, 0, 1.0f, D_80801248_bsdronexform);
    emitter = func_800BABB8(0, pos, 0, 1.0f, D_80801274_bsdronexform);
    emitter = func_800BABB8(emitter, pos, 0, 1.0f, D_808012B8_bsdronexform);
    func_800BABB8(emitter, pos, 0, 1.0f, D_808012D0_bsdronexform);
    emitter = func_800BABB8(0, pos, 0, 1.0f, D_808012F0_bsdronexform);
    emitter = func_800BABB8(emitter, pos, 0, 1.0f, D_80801334_bsdronexform);
    func_800BABB8(emitter, pos, 0, 1.0f, D_8080134C_bsdronexform);
}

// Advances the spiral in fixed 0.017 s steps until the accumulator catches up.
void func_8080051C_bsdronexform(void *player)
{
    (*(f32 **) ((u8 *) player + 0x18C))[4] -= func_800D8FF8();

if ((*(f32 **) ((u8 *) player + 0x18C))[4] < 0.0f) {
    do {
        func_808000E4_bsdronexform(player);
        (*(f32 **) ((u8 *) player + 0x18C))[2] += 0.017f * (*(f32 **) ((u8 *) player + 0x18C))[3];
        (*(f32 **) ((u8 *) player + 0x18C))[4] += 0.017f;
    } while ((*(f32 **) ((u8 *) player + 0x18C))[4] < 0.0f);
}

}

// Draw callback: per-axis squash/stretch wobble of the player model.
void bsdronexform_entrypoint_0(s32 unk_0, s32 unk_1)
{
    f32 axis_scale[3];
    f32 *out;
    s32 i;
    DroneScalePlayer *player;

    player = func_800F53D0(unk_1);
    i = 0;
    out = axis_scale;
    do {
        *out = func_800F1074(player->mem->elapsed + (i / 3.0f) * 0.5f, 0.5f) *
                       (player->mem->scale * player->mem->wobble) +
                   player->mem->scale;
        i++;
        out++;
    } while (i != 3);
    func_800DFF64(unk_0, 3, axis_scale);
}

void func_8080069C_bsdronexform(s32 player)
{
    func_8008C9D8(player, 0);
}

void func_808006BC_bsdronexform(u8 *player)
{
    *(f32 *) (*(u8 **) (player + 0x18C) + 0x20) = 0.0f;
    *(f32 *) (*(u8 **) (player + 0x18C) + 0x24) = 1.0f;
    *(f32 *) (*(u8 **) (player + 0x18C) + 0x28) = 0.0f;
    func_8008C9D8(player, _bsdronexform_entrypoint_0);
}

func_80800704_bsdronexform(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x18C) + 0x28) = value;
}

void func_80800714_bsdronexform(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x18C) + 0x24) = value;
}

void func_80800724_bsdronexform(u8 *player)
{
    *(f32 *) (*(u8 **) (player + 0x18C) + 0x20) += func_800D8FF8(player);
}

// Enters a phase of the transformation sequence (1-9) and sets up its timer.
void func_80800758_bsdronexform(player, next_phase) PlayerState *player;
s32 next_phase;
{
    s32 anim_id;
    f32 duration;
    f32 pos[3];
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x18C)))) + 0x32)) = next_phase;

switch (next_phase) {
    case 1:
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x18C) + 0x1C) = 1;
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x18C) + 0x2C) = func_8009C150(player);
        func_808003BC_bsdronexform(player, 0.28f);
        func_808003CC_bsdronexform(player, 180.0f);
        func_808003DC_bsdronexform(player, 0.04f);
        func_80800704_bsdronexform(player, 0.05f);
        baphysics_set_type(player, 7);
        _batimer_set(player, 0, 2.8f);
        func_8009DF18(player, 0x5D2, 1.0f, 0x4E20);
        return;

    case 2:
        _batimer_set(player, 0, 0.5f);
        baphysics_set_type(player, 0xB);
        return;

    case 3:
        _batimer_set(player, 0, 0.05f);
        return;

    case 4:
        _batimer_set(player, 0, 0.8f);
        return;

    case 5:
        func_8009C128(player, pos);
        pos[1] += 30.0f;
        func_800CA3F4(func_800A4C48(player), pos, 80.0f);
        func_808003EC_bsdronexform(player, pos);
        _batimer_set(player, 0, 0.1f);
        return;

    case 6:
        // The actual form switch happens in this phase.
        func_8009C128(player, pos);
        func_800E1610(2, 80.0f, 0.85f, pos);
        func_8009DE38(player, 0x490, 1.0f);
        func_800D5034(func_800A3274(player), func_800A33F8(player));
        func_800A3410(player, func_800A33F8(player));
        func_80092778(player);
        _badata_entrypoint_5(player, &anim_id, &duration);
        baanim_playForDuration_loopSmooth(player, anim_id, duration);
        _batimer_set(player, 0, 0.1f);
        return;

    case 7:
        _batimer_set(player, 0, 0.8f);
        return;

    case 8:
        _batimer_set(player, 0, 1.0f);
        return;

    case 9:
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x18C) + 0x1C) = 0;
        _batimer_set(player, 0, 0.7f);
        baphysics_set_type(player, 7);
}

}

// End.
void bsdronexform_entrypoint_1(s32 player)
{
    func_800961AC(player, 1);
    func_800C59F0(0xFF, 0xFF, 0xFF);
    func_808002CC_bsdronexform(player);
    func_8080069C_bsdronexform(player);
    func_8009CEE8(player);
    baflag_clear(player, 0x1B);
    _badronemem_entrypoint_1(player);
}

// Init.
void bsdronexform_entrypoint_2(PlayerState *player)
{
    f32 duration;
    s32 anim_id;

    _badronemem_entrypoint_0(player, 0x34);
    _badata_entrypoint_2(player, &anim_id, &duration);
    baanim_playForDuration_loopSmooth(player, anim_id, duration);
    func_8009FFD8(player, 1, 1, 3, 7);
    func_8009BA9C(player, 0);
    func_8009B94C(player, 0);
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    func_800961AC(player, 6);
    func_80800304_bsdronexform(player);
    func_808006BC_bsdronexform(player);
    (*(u8 **) ((u8 *) player + 0x18C))[0x31] = func_800A3274(player);
    (*(u8 **) ((u8 *) player + 0x18C))[0x30] = func_800A33F8(player);
    baflag_set(player, 0x1B);
    (*(u8 **) ((u8 *) player + 0x18C))[0x32] = 0;
    func_80800758_bsdronexform(player, 1);
}

f32 func_80800B5C_bsdronexform(s32 player, s32 timer_id, f32 duration, f32 from, f32 to)
{
    return func_800F10B4(_batimer_get(player, timer_id), duration, 0.0f, from, to);
}

// Update: runs the 9 timed phases (squash/stretch, red screen tint, form switch in phase 6).
void bsdronexform_entrypoint_3(PlayerState *this)
{
    int timer_done;

    if (DXF->spiral_active)
        func_8080051C_bsdronexform(this);

    func_80800724_bsdronexform(this);

switch (DXF->phase) {
    case 1:
        timer_done = _batimer_decrement(this, 0);
        func_8009C118(this, DXF->unk_2C + func_80800B5C_bsdronexform(this, 0, 2.8f, 0.0f, 90.0f));
        func_808003BC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 0.28f, 1.0f));
        func_808003CC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 180.0f, 55.0f));
        func_808003DC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 0.04f, 0.35f));
        func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 1.0f, 0.8f));
        func_80800704_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 0.05f, 0.4f));
        func_800C59F0((s32) func_80800B5C_bsdronexform(this, 0, 2.8f, 255.0f, 200.0f),
                      (s32) func_80800B5C_bsdronexform(this, 0, 2.8f, 255.0f, 80.0f),
                      (s32) func_80800B5C_bsdronexform(this, 0, 2.8f, 255.0f, 80.0f));

        if (timer_done)
            func_80800758_bsdronexform(this, 2);

        break;

    case 2:
        timer_done = _batimer_decrement(this, 0);
        func_80800704_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.5f, 0.4f, 0.6f));
        if (timer_done)
            func_80800758_bsdronexform(this, 3);
        break;

    case 3:
        timer_done = _batimer_decrement(this, 0);
        func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.05f, 0.8f, 1.2f));
        if (timer_done)
            func_80800758_bsdronexform(this, 4);
        break;

    case 4:
        timer_done = _batimer_decrement(this, 0);
        func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.8f, 1.2f, 0.09f));
        if (timer_done)
            func_80800758_bsdronexform(this, 5);
        break;

    case 5:
        timer_done = _batimer_decrement(this, 0);
        if (timer_done)
            func_80800758_bsdronexform(this, 6);
        break;

    case 6:
        timer_done = _batimer_decrement(this, 0);
        if (timer_done)
            func_80800758_bsdronexform(this, 7);
        break;

    case 7:
        timer_done = _batimer_decrement(this, 0);
        func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.8f, 0.09f, 1.0f));
        if (timer_done)
            func_80800758_bsdronexform(this, 8);
        break;

    case 8:
        func_808003DC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 1.0f, 0.35f, 0.03f));
        func_80800704_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 1.0f, 0.6f, 0.05f));
        func_800C59F0((s32) func_80800B5C_bsdronexform(this, 0, 1.0f, 200.0f, 255.0f),
                      (s32) func_80800B5C_bsdronexform(this, 0, 1.0f, 80.0f, 255.0f),
                      (s32) func_80800B5C_bsdronexform(this, 0, 1.0f, 80.0f, 255.0f));
        if (_batimer_decrement(this, 0))
            func_80800758_bsdronexform(this, 9);
        break;

    case 9:
        timer_done = _batimer_decrement(this, 0);
        func_8009C118(this, DXF->unk_2C + func_80800B5C_bsdronexform(this, 0, 0.7f, 90.0f, 0.0f));
        if (timer_done)
            bs_setState(this, _badata_entrypoint_34(this));
}

}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
void *D_808011F0_bsdronexform = (void *) 0x0029001B;
static u32 D_808011F0_bsdronexform_rest[10] = {0xFFCEFFCE, 0x150066,  0xCC0025, 0x70007,  0x270000,
                                               0x12C0000,  0x12C002B, 0xA600A6, 0x161000, 0x0};
u8 D_8080121C_bsdronexform[44] = {0x1,  0x10, 0x0,  0x1D, 0x9,  0xBA, 0x0,  0x15, 0x0, 0xB3, 0x0,
                                  0xCC, 0x0,  0x18, 0x0,  0x0,  0x0,  0x0,  0xC,  0x0, 0xC,  0x0,
                                  0x0,  0x22, 0x3,  0x33, 0x3,  0x33, 0x3,  0x33, 0x3, 0x33, 0x0,
                                  0x2B, 0x0,  0xCC, 0x0,  0xCC, 0x1,  0x1A, 0x0,  0x0, 0x0,  0x0};
u8 D_80801248_bsdronexform[44] = {0x1,  0x10, 0x0,  0x1D, 0x9,  0xB8, 0x0,  0x15, 0x0, 0x19, 0x0,
                                  0xCC, 0x0,  0x18, 0x0,  0x0,  0x0,  0x0,  0xF,  0x0, 0xF,  0x0,
                                  0x0,  0x22, 0x3,  0x0,  0x3,  0x0,  0x3,  0x0,  0x3, 0x0,  0x0,
                                  0x2B, 0x0,  0xA6, 0x0,  0xA6, 0x1,  0x1A, 0x0,  0x0, 0x0,  0x0};
u8 D_80801274_bsdronexform[68] = {
    0x11, 0x10, 0x0, 0x1D, 0x9,  0xE2, 0x0, 0x2C, 0xFF, 0x6A, 0x0,  0xA,  0xFF, 0x6A,
    0x0,  0x96, 0x0, 0x32, 0x0,  0x96, 0x0, 0x1B, 0xFF, 0xCE, 0xFF, 0xCE, 0x0,  0x15,
    0x0,  0x0,  0x0, 0x99, 0x0,  0x22, 0x0, 0x47, 0x0,  0x51, 0x0,  0x7,  0x0,  0x7,
    0x0,  0x27, 0x0, 0x0,  0x1,  0x2C, 0x0, 0x0,  0x1,  0x2C, 0x0,  0x2B, 0x2,  0x0,
    0x2,  0x0,  0x0, 0x16, 0x10, 0x0,  0x8, 0x1A, 0x0,  0x0,  0x0,  0x0};
u8 D_808012B8_bsdronexform[24] = {0x0,  0x2C, 0xFE, 0xD4, 0x0, 0x96, 0xFE, 0xD4,
                                  0x1,  0x2C, 0x0,  0xC8, 0x1, 0x2C, 0x0,  0x1B,
                                  0xFF, 0x6A, 0xFF, 0x6A, 0x5, 0x1A, 0x0,  0x0};
u8 D_808012D0_bsdronexform[32] = {0x0, 0x2C, 0xFF, 0x9C, 0x0,  0xA,  0xFF, 0x9C, 0x0,  0x64, 0x0,
                                  0xF, 0x0,  0x64, 0x0,  0x1B, 0xFD, 0x44, 0xFD, 0x44, 0x0,  0x4,
                                  0x0, 0x66, 0x0,  0x7,  0x0,  0x3,  0x4,  0x1A, 0x0,  0x0};
u8 D_808012F0_bsdronexform[68] = {
    0x11, 0x10, 0x0, 0x1D, 0x9,  0xE5, 0x0, 0x2C, 0xFF, 0xCE, 0x0,  0x3C, 0xFF, 0xCE,
    0x0,  0x32, 0x0, 0x96, 0x0,  0x32, 0x0, 0x1B, 0xFF, 0xCE, 0xFF, 0xCE, 0x0,  0x15,
    0x0,  0x0,  0x0, 0x99, 0x0,  0x22, 0x0, 0x47, 0x0,  0x51, 0x0,  0x7,  0x0,  0x7,
    0x0,  0x27, 0x0, 0x0,  0x1,  0x2C, 0x0, 0x0,  0x1,  0x2C, 0x0,  0x2B, 0x2,  0x0,
    0x2,  0x0,  0x0, 0x16, 0x10, 0x0,  0x8, 0x1A, 0x0,  0x0,  0x0,  0x0};
u8 D_80801334_bsdronexform[24] = {0x0,  0x2C, 0xFE, 0x70, 0x0, 0x96, 0xFE, 0x70,
                                  0x1,  0x90, 0x0,  0xC8, 0x1, 0x90, 0x0,  0x1B,
                                  0xFF, 0x38, 0xFF, 0x38, 0x5, 0x1A, 0x0,  0x0};
u8 D_8080134C_bsdronexform[36] = {0x0,  0x2C, 0xFF, 0x38, 0x0,  0xA,  0xFF, 0x38, 0x0,
                                  0xC8, 0x0,  0x14, 0x0,  0xC8, 0x0,  0x1B, 0xFC, 0xAE,
                                  0xFC, 0xAE, 0x0,  0x4,  0x0,  0x66, 0x0,  0x7,  0x0,
                                  0x3,  0x4,  0x1A, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};

// TU-NOTE: the .bss is defined here ahead of its first use; IDO places .bss objects used before their definition first.
u8 D_80801370[64];
