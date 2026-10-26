#include "common.h"

extern int D_80800130_chcamwaypoint;
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void *func_80110014(s32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern void _ncbawaypoint_entrypoint_2(void *, f32 *, f32 *, f32);

int chcamwaypoint_entrypoint_0()
{
    return (int)&D_80800130_chcamwaypoint;
}

void func_8080000C_chcamwaypoint(Actor *param_0)
{
    func_800EEBF0((f32 *)param_0->actorData, param_0->rotation, 1.0f);
    *(f32 *)&param_0->actorData[3] = func_800EEAA4(param_0->position, (f32 *)param_0->actorData);
}

void func_8080005C_chcamwaypoint(Actor *param_0)
{
    void *local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3[3];

    local_1 = func_8008FFE8();
    if (func_8010FAE4(local_1) == 2) {
        local_0 = func_80110014(local_1);
        local_2 = (f32)((s32)param_0->unk74_7 * 10);
        func_8008FE68(local_3);
        if (!func_800EFFB4(param_0->position, local_2, local_3)) {
            func_801107F0(local_0, local_3);
            if (!func_800EFFB4(param_0->position, local_2, local_3)) return;
        }
        _ncbawaypoint_entrypoint_2(local_0, param_0->position, (f32 *)param_0->actorData, *(f32 *)&param_0->actorData[3]);
    }
}
