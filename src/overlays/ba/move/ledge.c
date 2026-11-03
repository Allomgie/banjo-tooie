#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8009BC08(PlayerState *, f32 *);
extern void func_8009BB24(PlayerState *, f32 *);
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_8009B98C(PlayerState *, f32 *);

s32 bamoveledge_entrypoint_0()
{
    return 0x4;
}

void bamoveledge_entrypoint_1(s32 actor)
{
}

void bamoveledge_entrypoint_2(s32 actor)
{
}

// Integrates position from velocity while hanging on a ledge.
void bamoveledge_entrypoint_3(PlayerState *player)
{
    f32 velocity[3];
    f32 pos[3];

    func_8009BC08(player, pos);
    func_8009BB24(player, velocity);
    func_800EF334(velocity, func_800D8FF8());
    func_800EF04C(pos, velocity);
    func_8009B98C(player, pos);
}
