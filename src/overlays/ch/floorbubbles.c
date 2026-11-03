#include "common.h"

extern void *D_808002CC_chfloorbubbles;
extern void *func_80100094(Actor *, s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC128(s32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80800270_chfloorbubbles[];
typedef struct {
    f32 local_0;
    f32 local_1[2];
} FloorBubblePoint;
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(void *, f32, f32);
extern void _subaddie3d_entrypoint_0(void *, f32, f32, void *);
extern void _subaddie3d_entrypoint_1(void *, f32, f32, void *);

void func_80800000_chfloorbubbles(Actor *param_0)
{
    f32(*local_0)[3];
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    if (func_800DC0C0() < 0.1f) {
        local_1 = func_800DC128(0, 5);
        local_2 = func_800B53A4(local_1);
        func_800BABB8(local_2, local_0[param_0->unk6C_0], NULL, 1.0f, D_80800270_chfloorbubbles);
        func_800BA568(local_2, (s16) ((f32 *) param_0->actorData)[1]);
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
        func_800EEB9C(&local_0[local_1], local_2,
                      func_800DC178(0.0f, (f32) (s32) (param_0->unk74_7 * 10)));
        func_800EF04C(&local_0[local_1], param_0->position);
        _subaddie3d_entrypoint_0(&local_0[local_1], 100.0f, -100.0f, local_0[local_1].local_1);
    }
    _subaddie3d_entrypoint_1(param_0->position, 500.0f, 0.0f, (u8 *) param_0 + 0x1C);
}

void func_80800244_chfloorbubbles(s32 arg0)
{
}

int chfloorbubbles_entrypoint_0()
{
    return &D_808002CC_chfloorbubbles;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800270_chfloorbubbles[92] = {
    0x0,  0x1D, 0x9,  0xD9, 0x0, 0x16, 0x10, 0x4,  0x0, 0x2C, 0x0, 0x0,  0x0,  0x32, 0x0,  0x0,
    0x0,  0x0,  0x0,  0x46, 0x0, 0x0,  0x0,  0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0,  0x7,  0x0,  0x1,
    0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0,  0x2B, 0x1, 0x80, 0x2, 0x80, 0x0,  0xA,  0xFF, 0xF4,
    0xFF, 0x9C, 0xFF, 0xF4, 0x0, 0xC,  0x0,  0x0,  0x0, 0xC,  0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF,
    0x0,  0x22, 0x0,  0x1E, 0x0, 0x26, 0x0,  0x14, 0x0, 0x19, 0x0, 0x2F, 0x0,  0x40, 0x0,  0x40,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x19, 0x0,  0x0,  0x0, 0x33, 0x0, 0x0};
void *D_808002CC_chfloorbubbles = (void *) 0x020F02AF;
static u32 D_808002CC_chfloorbubbles_rest[20] = {0x6740001,
                                                 0x0,
                                                 (u32) func_80800000_chfloorbubbles,
                                                 (u32) func_80105834,
                                                 (u32) func_8010A730,
                                                 0x9C40000,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_80800244_chfloorbubbles,
                                                 0x0,
                                                 0x780000,
                                                 (u32) func_8080010C_chfloorbubbles,
                                                 (u32) func_80107C2C,
                                                 0x80000602,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0};
