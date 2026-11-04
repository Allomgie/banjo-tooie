// Jolly Roger's Lagoon doubloon: a spinning gold coin with random twinkles. On collection it
// shows the first-time dialog, marks its registry slot, bumps the counter, plays sound and sparkle.
#include "ch/doubloon.h"

extern u8 D_80800290_chdoubloon[];
extern int D_808002A0_chdoubloon[];
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
void chdoubloon_entrypoint_1();

void func_80800000_chdoubloon(void *actor)
{
    *(float *) ((char *) actor + 0x44) = 0.0f;
}

s32 func_8080000C_chdoubloon(s32 actor)
{
    chdoubloon_entrypoint_1(actor);
    func_80103110(actor, 0);
}

void chdoubloon_entrypoint_0(Actor *actor)
{
    func_80101870();
    if (actor->unk7C_12) {
        func_80103110(actor, 1);
    }
}

// Spins the coin and spawns random twinkles.
void chdoubloon_entrypoint_1(actor) Actor *actor;
{
    f32 twinkle_pos[3];
    s32 i;
    f32 unk_1[2];
    f32 unk_2[3];

    actor->rotation[1] += func_800D8FF8() * 300.0f;
    if (actor->unk7C_12) {
        func_800E3980(unk_2);
        func_800F18FC(actor->position, unk_2, unk_1);
        for (i = 0; i != 4; i++) {
            if (func_800DC0C0() < 0.015f) {
                func_800EEC30(twinkle_pos, unk_1[0] + func_800DC178(-90.0f, 90.0f),
                              unk_1[1] + func_800DC178(-90.0f, 90.0f), 30.0f);
                func_800EF04C(twinkle_pos, actor->position);
                twinkle_pos[1] += 30.0f;
                _fxtwinkle_entrypoint_1(twinkle_pos, 0x9E2);
            }
        }
    }
}

// Message 0x3E: collected. 0x13: store registry index.
s32 func_808001D4_chdoubloon(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x3E:
            _sudialog_entrypoint_0(0x165, 4);
            func_800D0BD4(*(s32 *) &actor->unk54, 7);
            func_800D1844(0x4E);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800290_chdoubloon);
            _fxsparkle_entrypoint_1(actor->position, 0x13);
            func_800FFAB0(actor);
            return 1;
        case 0x13:
            *(s32 *) &actor->unk54 = data;
            break;
        default:
            return 0;
    }
    return 1;
}

int *chdoubloon_entrypoint_2()
{
    return &D_808002A0_chdoubloon;
}

extern void func_80105834();
extern void _chdoubloon_entrypoint_0();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800290_chdoubloon[16] = {0x0, 0x1B, 0x0, 0x13, 0x6,  0x34, 0x0, 0x2,
                                0x0, 0x14, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
int D_808002A0_chdoubloon[20] = {0x13404E5,
                                 0x7C00001,
                                 0x0,
                                 (u32) func_8080000C_chdoubloon,
                                 (u32) func_80105834,
                                 (u32) _chdoubloon_entrypoint_0,
                                 0xBB8,
                                 0x0,
                                 0x0,
                                 0x4,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chdoubloon,
                                 (u32) func_80107C2C,
                                 -0x7FFFE000,
                                 (u32) func_808001D4_chdoubloon,
                                 0x0,
                                 0x0,
                                 0x0};
