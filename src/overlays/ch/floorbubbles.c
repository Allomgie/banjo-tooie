#include "common.h"

extern void *D_808002CC_chfloorbubbles;
extern void *func_80100094(Actor *, s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC128(s32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80800270_chfloorbubbles[];
typedef struct { f32 local_0; f32 local_1[2]; } FloorBubblePoint;
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(void *, f32, f32);
extern void _subaddie3d_entrypoint_0(void *, f32, f32, void *);
extern void _subaddie3d_entrypoint_1(void *, f32, f32, void *);

void func_80800000_chfloorbubbles(Actor *param_0)
{
    f32 (*local_0)[3];
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    if (func_800DC0C0() < 0.1f) {
        local_1 = func_800DC128(0, 5);
        local_2 = func_800B53A4(local_1);
        func_800BABB8(local_2, local_0[param_0->unk6C_0], NULL, 1.0f, D_80800270_chfloorbubbles);
        func_800BA568(local_2, (s16)((f32 *)param_0->actorData)[1]);
        func_800BA22C(local_2, local_1);
        if (func_800DC0C0() < 0.75f) {
            param_0->unk6C_0 = func_800DC128(0, 10);
        }
    }
}

void func_8080010C_chfloorbubbles(Actor *param_0)
{
    FloorBubblePoint *local_0;
    s32 local_1;
    f32 local_2;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 10; local_1++) {
        local_2 = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(&local_0[local_1], local_2, func_800DC178(0.0f, (f32)(s32)(param_0->unk74_7 * 10)));
        func_800EF04C(&local_0[local_1], param_0->position);
        _subaddie3d_entrypoint_0(&local_0[local_1], 100.0f, -100.0f, local_0[local_1].local_1);
    }
    _subaddie3d_entrypoint_1(param_0->position, 500.0f, 0.0f, (u8 *)param_0 + 0x1C);
}

void func_80800244_chfloorbubbles(s32 arg0) 
{
}
int chfloorbubbles_entrypoint_0()
{
  return &D_808002CC_chfloorbubbles;
}
