#include "common.h"

extern void *D_80800190_chdummyjigsaw;
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern void func_800EF214(f32 *, f32, f32, f32);

void func_80800000_chdummyjigsaw(Actor *actor)
{
    f32 pos[3];
    s32 i;

    if (actor->unk7C_12) {
        // up to 4 chances per frame for a twinkle around the actor
        for (i = 0; i < 4; i++) {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(actor, pos);
                func_800EF214(pos, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f),
                              40.0f);
                _fxtwinkle_entrypoint_2(pos, 0x9E2);
            }
        }
    }
    // spin about Y, 230 deg/s
    actor->rotation[1] += func_800D8FF8() * 230.0f;
    actor->rotation[1] = func_800136E4(actor->rotation[1]);
}

int func_80800128_chdummyjigsaw(Actor *actor, s32 msg, s32 data)
{
    // touched while collectable: delete self
    if ((msg == 0x3E) && actor->unk64_20) {
        func_800FFA88(actor->unk0);
        return 1;
    }
    return 0;
}

int chdummyjigsaw_entrypoint_0()
{
    return &D_80800190_chdummyjigsaw;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_80800190_chdummyjigsaw = (void *) 0x012F0298;
static u32 D_80800190_chdummyjigsaw_rest[19] = {0x6100001,
                                                0x0,
                                                (u32) func_80800000_chdummyjigsaw,
                                                (u32) func_80105834,
                                                (u32) func_80101870,
                                                0x9C40000,
                                                0x0,
                                                0x0,
                                                0x4,
                                                0x0,
                                                (u32) func_80108ED0,
                                                0x0,
                                                0x0,
                                                (u32) func_80107C2C,
                                                0x80004000,
                                                (u32) func_80800128_chdummyjigsaw,
                                                0x0,
                                                0x0,
                                                0x0};
