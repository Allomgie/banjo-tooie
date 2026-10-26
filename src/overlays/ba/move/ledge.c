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

void bamoveledge_entrypoint_1(s32 arg0) 
{
}
void bamoveledge_entrypoint_2(s32 arg0) 
{
}
void bamoveledge_entrypoint_3(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    func_8009BC08(param_0, local_1);
    func_8009BB24(param_0, local_0);
    func_800EF334(local_0, func_800D8FF8());
    func_800EF04C(local_1, local_0);
    func_8009B98C(param_0, local_1);
}
