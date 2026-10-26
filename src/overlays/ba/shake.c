#include "common.h"
#include "playerstate.h"

extern f32 D_80800100_bashake[][3];
extern f32 D_8080013C_bashake[][2];
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);

void bashake_entrypoint_0(PlayerState *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    func_800E1610(0, D_80800100_bashake[param_1][0], D_8080013C_bashake[param_2][0], local_0);
    _bamotor_entrypoint_1(param_0, D_80800100_bashake[param_1][1], D_80800100_bashake[param_1][2], D_8080013C_bashake[param_2][1]);
}

void bashake_entrypoint_1(PlayerState *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    func_8009C128(param_0, local_0);
    func_800E1610(0, D_80800100_bashake[param_1][0], D_8080013C_bashake[param_2][0], local_0);
}
