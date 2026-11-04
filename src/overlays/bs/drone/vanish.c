// Drone mode "vanish": most likely the player dissolves in sparkles, fades out, and control
// returns after 2 s (used for teleports/warps out of sight).
#include "common.h"
#include "overlays/ba/playerstate.h"

typedef struct {
    u8 pad_0[0x18];
    u8 phase;
} DroneVanishState;
extern void _batimer_set(PlayerState *, s32, f32);
typedef struct {
    s32 emitter_a;
    s32 emitter_b;
} DroneVanishEmitters;
typedef struct {
    u8 pad_0[0x188];
    DroneVanishEmitters *emitters;
} DroneVanishEffectsPlayer;
extern s32 D_8080056C_bsdronevanish[];
extern s32 D_80800560_bsdronevanish[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA3FC(void *, f32 *);
extern void *D_80800578_bsdronevanish;
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80092778();
extern void func_800961AC();
extern f32 func_800D8FF8(void);

// Enters a vanish phase: 1 wait, 2 fade out with loop sound, 3 hidden for 2 s.
void func_80800000_bsdronevanish(PlayerState *player, s32 next_phase)
{
    switch (next_phase) {
        case 1:
            _batimer_set(player, 0, 0.3f);
            break;
        case 2:
            func_800FC618(0x1C, -1);
            func_800FCA90(0x1C);
            _batimer_set(player, 0, 0.4f);
            break;
        case 3:
            func_80093370(player, 0);
            func_800FCAE0(0x1C, 0, 2000);
            _batimer_set(player, 0, 2.0f);
    }
    ((DroneVanishState *) player->kazfly)->phase = next_phase;
}

// Spawns sparkles at the player's feet and 130 units above.
void func_808000CC_bsdronevanish(void *player)
{
    f32 pos[3];

    func_800F3BB0(player, pos);
    func_800BABB8(((DroneVanishEffectsPlayer *) player)->emitters->emitter_b, pos, NULL, 1.0f,
                  D_80800560_bsdronevanish);
    func_800BABB8(((DroneVanishEffectsPlayer *) player)->emitters->emitter_a, pos, NULL, 1.0f,
                  D_80800560_bsdronevanish);
    pos[1] += 130.0f;
    func_800BABB8(((DroneVanishEffectsPlayer *) player)->emitters->emitter_b, pos, NULL, 1.0f,
                  D_8080056C_bsdronevanish);
    func_800BABB8(((DroneVanishEffectsPlayer *) player)->emitters->emitter_a, pos, NULL, 1.0f,
                  D_8080056C_bsdronevanish);
}

void func_8080019C_bsdronevanish(Actor *emitter, f32 pos[3])
{
    func_800BABB8(emitter, 0, 0, 1.0f, &D_80800578_bsdronevanish);
    func_800BA3FC(emitter, pos);
}

// Frees both emitters.
void func_808001E4_bsdronevanish(player) Actor *player;
{
    func_800B5450(*(s32 *) ((s8 *) *(s32 **) ((s8 *) player + 0x188) + 4));
    func_800B5450(**(s32 **) ((s8 *) player + 0x188));
}

// Creates the two emitters (effects 0x9E5 and 0x9E2).
void func_8080021C_bsdronevanish(u8 *player)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 0x10) = 0.0f;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 8) = 0.0f;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 0xC) = 1.0f;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 0) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 0), 0x9E5);
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 4) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 4), 0x9E2);
}

// Runs the sparkle spawning in fixed 0.02 s steps until the accumulator catches up.
void func_808002A4_bsdronevanish(player) void *player;
{
    (*(f32 **) ((u8 *) player + 0x188))[4] -= func_800D8FF8();
    if ((*(f32 **) ((u8 *) player + 0x188))[4] < 0.0f) {
        do {
            func_808000CC_bsdronevanish(player);
            (*(f32 **) ((u8 *) player + 0x188))[2] +=
                0.02f * (*(f32 **) ((u8 *) player + 0x188))[3];
            (*(f32 **) ((u8 *) player + 0x188))[4] += 0.02f;
        } while ((*(f32 **) ((u8 *) player + 0x188))[4] < 0.0f);
    }
}

// Init.
void bsdronevanish_entrypoint_0(u8 *player)
{
    s32 duration;
    s32 anim_id;

    _bastatemem_entrypoint_0(player, 0x1C);
    _badata_entrypoint_3(player, &anim_id, &duration);
    baanim_playForDuration_loopSmooth(player, anim_id, duration);
    func_8009FFD8(player, 1, 1, 3, 7);
    func_800961AC(player, 6);
    func_8080021C_bsdronevanish(player);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x188) + 0x18) = 0;
    func_80800000_bsdronevanish(player, 1);
}

// Update: phase 3 ends the state after the 2 s wait.
void bsdronevanish_entrypoint_1(PlayerState *player)
{
    s32 next_state;
    s32 timer_done;
    next_state = 0;
    switch (*((u8 *) player->kazfly + 0x18)) {
        case 1:
            func_808002A4_bsdronevanish(player);
            if (_batimer_decrement(player, 0))
                func_80800000_bsdronevanish(player, 2);
            break;
        case 2:
            func_808002A4_bsdronevanish(player);
            timer_done = _batimer_decrement(player, 0);
            func_80092EBC(player,
                          (s32) func_800F10B4(_batimer_get(player, 0), 0.0f, 0.4f, 0.0f, 255.0f));
            if (timer_done)
                func_80800000_bsdronevanish(player, 3);
            break;
        case 3:
            if (_batimer_decrement(player, 0))
                next_state = _badata_entrypoint_34(player);
    }
    bs_setState(player, next_state);
}

// End.
s32 bsdronevanish_entrypoint_2(Actor *this)
{
    func_808001E4_bsdronevanish();
    func_800961AC(this, 1);
    func_80092778(this);
    _bastatemem_entrypoint_1(this);
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
s32 D_80800560_bsdronevanish[3] = {0x1B02BC, 0x4B0011A, 0x0};
s32 D_8080056C_bsdronevanish[3] = {0x1BFD44, -0x4AFFEE6, 0x0};
void *D_80800578_bsdronevanish = (void *) 0x00290015;
static u32 D_80800578_bsdronevanish_rest[9] = {0x4C00CC, 0xAFFD3, 0xFFD3,   0x2D0000, 0x2D0022,
                                               0x260038, 0x7000C, 0x2B008C, 0x8C0000};
