#include "common.h"

extern void func_80095870(void *, f32 *, f32 *);
extern s32 func_8009588C(void *);
extern void *func_800C6C94(f32 *, f32, f32 *, u32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800FAB50(f32 *, f32 *, f32 *, u32, f32);

// Sweeps a sphere from the player's centre; on a hit, pushes the player out along the hit normal.
void bahitspline_entrypoint_0(void *player)
{
    void *hit;
    f32 center_height;
    f32 radius;
    f32 pos[3];
    f32 center[3];
    f32 normal[3];
    f32 sweep_from[3];
    f32 sweep_to[3];
    u32 flags;
    f32 offset[3];

    func_80095870(player, &center_height, &radius);
    func_8009C128(player, pos);
    func_800EFA4C(center, pos[0], pos[1] + center_height, pos[2]);
    func_800EE7F8(sweep_to, center);
    flags = func_8009588C(player);
    hit = func_800C6C94(sweep_to, radius, normal, flags);
    if (hit) {
        func_800EFA20(offset, normal, radius * 1.01f);
        func_800EE780(sweep_from, sweep_to, offset);
        if (func_800FAB50(sweep_from, sweep_to, normal, flags, radius)) {
            func_800EFB24(offset, sweep_to, center);
            func_800EF04C(pos, offset);
            func_8009C0F8(player, pos);
            func_8009C21C(player);
        }
    }
}

void bahitspline_entrypoint_1(s32 arg0)
{
}

void bahitspline_entrypoint_2(void *player)
{
}
