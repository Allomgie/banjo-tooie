// Drone mode "suck under": probably the player is pulled down while a per-form anim plays
// (e.g. sinking into a hazard); only a few interrupts get through.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_8009BA9C(s32, f32 *);
extern f32 _batimer_get(PlayerState *, s32);

// Pull the player down at a constant velocity.
void func_80800000_bsdronesuckunder(s32 player)
{
    f32 velocity[3];

    func_800EFA4C(velocity, 0.0f, -333.3333f, 0.0f);
    func_8009BA9C(player, velocity);
}

extern void func_800961A0(Actor *a0, s32 a1);

void bsdronesuckunder_entrypoint_0(s32 player)
{
    func_800961A0(player, 0);
}

int bsdronesuckunder_entrypoint_1(Actor *player)
{
    extern void _badata_entrypoint_4(Actor * a0, s32 * a1, f32 * a2);
    extern void _batimer_set(Actor * a0, s32 a1, f32 a2);
    extern void baanim_playForDuration_loopSmooth(Actor * a0, s32 a1, f32 a2);
    extern void func_8009FFD8(Actor * a0, s32 a1, s32 a2, s32 a3, s32 a4);

    f32 anim_duration;
    s32 anim_id;
    _badata_entrypoint_4(player, &anim_id, &anim_duration);
    baanim_playForDuration_loopSmooth(player, anim_id, anim_duration);
    func_8009FFD8(player, 1, 1, 3, 8);
    _batimer_set(player, 0xa, 0.3f);
    func_800961A0(player, 1);
    func_80800000_bsdronesuckunder(player);
}

// Only interrupts 0x26, 0x51, 0x52 and 0x6A get through.
int bsdronesuckunder_entrypoint_2(Actor *player)
{
    switch (func_8009E6EC(player)) {
        case 0x26:

        case 0x51:

        case 0x52:

            // Matching: empty if is needed for the match.
            if (player) {
            }
        case 0x6A:
            func_80099B94(player);
            break;

        default:
            func_80099AA8();
    }
}

void bsdronesuckunder_entrypoint_3(PlayerState *player)
{
    _batimer_decrement(player, 0xA);
    if (_batimer_get(player, 0xA) != 0.0f) {
        func_80800000_bsdronesuckunder(player);
    } else {
        func_8009BA9C(player, 0);
    }
}
