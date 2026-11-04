// Hover mover (baphysics): springs the player toward a hover anchor with clamped per-axis
// acceleration and integrates position; also setters for the anchor used by the taxi state.

#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800EE7F8(int);

void bamovehover_entrypoint_0(s32 actor)
{
}

void bamovehover_entrypoint_1(u8 *actor)
{
    func_800EFD24(*(s32 *) ((s8 *) actor + 0xC8) + 0xAC);
    func_800EFD24(*(s32 *) ((s8 *) actor + 0xC8) + 0xB8);
    func_800EFA4C(*(s32 *) ((s8 *) actor + 0xC8) + 0x10, 0x41855556, 0x42055556, 0x42480000);
}

// Springs the player toward the hover anchor, clamping acceleration per axis.
void bamovehover_entrypoint_2(PlayerState *player)
{
    f32 dt;
    f32 target_vel[3];
    s32 i;
    f32 offset;
    f32 dist;
    f32 max_step;

    dt = func_800D8FF8();
    func_800EF174(*(f32 **) ((u8 *) player + 0xC8) + 0xAC / 4,
                  *(f32 **) ((u8 *) player + 0xC8) + 0xB8 / 4, dt);
    for (i = 0; i < 3; i++) {
        offset = (*(f32 **) ((u8 *) player + 0xC8))[0xAC / 4 + i] -
                  (*(f32 **) ((u8 *) player + 0xC8))[1 + i];
        dist = mlAbsF(offset);
        if (dist > 5.0f) {
            max_step = 220.0f * dt;
            dist = func_800F10B4(dist, 5.0f, 40.0f, 50.0f, 150.0f);
            target_vel[i] = offset > 0.0f ? dist : -dist;
            (*(f32 **) ((u8 *) player + 0xC8))[4 + i] = func_800F15F8(
                (*(f32 **) ((u8 *) player + 0xC8))[4 + i], target_vel[i], max_step);
        }
    }
    func_800EF174(*(f32 **) ((u8 *) player + 0xC8) + 1, *(f32 **) ((u8 *) player + 0xC8) + 4,
                  dt);
}

void bamovehover_entrypoint_3(Actor *actor)
{
    func_800EE7F8(*(int *) ((char *) actor + 0xC8) + 0xAC);
}

void bamovehover_entrypoint_4(Actor *actor, s32 unk_0)
{
    if (!unk_0) {
        func_800EFD24(*(s32 *) ((char *) actor + 0xC8) + 0xB8);
    } else {
        func_800EE7F8(*(s32 *) ((char *) actor + 0xC8) + 0xB8);
    }
}
