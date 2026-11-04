#include "common.h"

extern void func_80102B6C(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct {
    u8 pad_0[0x70];
    u32 pad_70_10 : 22;
    u32 unk70_4 : 6;
    u32 pad_70_0 : 4;
} EelRouteActor;
extern void func_800EEC30(f32[3], f32, f32, f32);
extern void func_800EF04C(f32[3], f32[3]);
extern s32 func_800CC338(f32[3], s32, s32);
typedef struct LagoonFishItem {
    f32 pos[3];
    f32 rot[3];
    u8 pad_0[0xC];
    f32 scale;
    u8 pad_1[4];
    u8 model_idx;
    u8 pad_2[3];
} LagoonFishItem;
extern void *func_80100094(Actor *, u32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern f32 func_800DC178(f32, f32);
typedef struct {
    s16 a, b;
} S16Pair;
extern u8 D_8012762C;
extern void func_80103140();
extern void *D_80800B70_chlagoonfish;
typedef struct {
    f32 pos[3];
    f32 unk_C[3];
    f32 target[3];
    f32 scale;
    f32 speed;
    u8 model_idx;
    u8 pad_2D[3];
} LagoonFishParticle;
extern void func_800EF214(f32 *, f32, f32, f32);
typedef struct {
    f32 pos[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 target[3];
    f32 pad24;
    f32 unk28;
    f32 pad2C;
} LagoonFish;
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800DC0C0(void);
extern f32 func_800D8FF8(void);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
void func_80800A44_chlagoonfish();

// Spawns the per-fish buffer with random start positions.
void func_80800000_chlagoonfish(actor) Actor *actor;
{
    LagoonFishParticle *fish;
    u32 i;
    f32 unk_0;
    f32 unk_1;
    func_80100074(actor, 0, actor->unk6C_0 * sizeof(LagoonFishParticle));
    fish = func_80100094(actor, 0);
    for (i = 0; i < actor->unk6C_0; i++, fish++) {
        func_800EE7F8(fish->pos, actor->position);
        unk_0 = func_800DC178(-45.0f, 45.0f);
        unk_1 = func_800DC178(180.0f, 360.0f);
        func_800EF214(fish->pos, unk_0, unk_1, func_800DC178(50.0f, 250.0f));
        fish->scale = func_800DC178(actor->scale * 0.4f, actor->scale);
        fish->model_idx = func_800DC128(0, 3);
        fish->target[0] = func_800DC178(-400.0f, 400.0f);
        fish->target[1] = func_800DC178(-400.0f, 400.0f);
        fish->target[2] = func_800DC178(-400.0f, 400.0f);
        fish->speed = 400.0f;
    }
}

void func_808001A0_chlagoonfish(Actor *actor)
{
    s32 variant;
    variant = actor->unk74_7;
    if (variant < 0x33) {
        func_800FFAB0(actor);
    } else {
        actor->unk6C_0 = variant - 0x32;
        func_80800000_chlagoonfish(actor);
        func_80800A44_chlagoonfish(actor, 1);
        *(f32 *) &actor->actorData[3] = actor->scale * 600.0f;
        *(f32 *) &actor->actorData[7] = _subaddiesect_entrypoint_1(actor);
    }
}

void func_80800240_chlagoonfish(actor) s32 actor;
{
    func_80100074(actor, 0, 0);
}

void func_80800264_chlagoonfish()
{
    func_80800240_chlagoonfish();
}

void func_80800284_chlagoonfish(Actor *actor)
{
    func_80102B6C(actor, 2.0f);
    func_80102B2C(actor, 2.0f);

if ((func_8010B990(actor, 0x500106) & 0x24) && actor->unk70_10 != 2) {
    func_80800A44_chlagoonfish(actor, 2);
}

}

s32 func_808002F8_chlagoonfish(Actor *actor)
{
    f32 pos[3];
    s32 route_idx;

    func_800EEC30(pos, actor->rotation[0], actor->rotation[1], 200.0f);
    func_800EF04C(pos, actor->position);
    route_idx = func_800CC338(pos, (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1,
                            ((*(u32 *) ((u8 *) actor + 0x70) << 22) >> 26) - 1);

if (route_idx != -1) {
    ((EelRouteActor *) actor)->unk70_4 = route_idx + 1;
    return 1;
}

return 0;
}

void func_8080038C_chlagoonfish(Actor *actor)
{
    LagoonFish *fish;
    f32 player_vec[3];
    f32 player_speed;
    f32 unk_0;
    s32 parity;
    u32 i;
    f32 steer[3];
    f32 angle_diff;
    f32 target_dir[3];

if (func_80100094(actor, 0) == NULL) {
    func_80800000_chlagoonfish(actor);
}

switch (actor->unk70_10) {
    case 1:
        func_80800284_chlagoonfish(actor);
        if (!func_808002F8_chlagoonfish(actor)) {
            func_80800A44_chlagoonfish(actor, 2);
        } else if (600.0f * actor->scale < *(f32 *) &actor->actorData[3]) {
            *(f32 *) &actor->actorData[3] -= 5.0f * actor->scale;
        }
        if (func_800DC0C0() < 0.2f) {
            actor->unk50 += func_800DC178(-15.0f, 15.0f);
        }
        if (func_800DC0C0() < 0.2f) {
            actor->unk54 += func_800DC178(-15.0f, 15.0f);
        }
        break;
    case 2:
        actor->unk54 = func_800F1DF4(actor->position, (f32 *) actor->actorData);
        actor->unk50 = func_800F1828(actor->position, (f32 *) actor->actorData);
        func_80800284_chlagoonfish(actor);
        if (func_800EFFB4((f32 *) actor->actorData, 200.0f, actor->position)) {
            if (func_808002F8_chlagoonfish(actor)) {
                func_80800A44_chlagoonfish(actor, 1);
            }
        } else if (600.0f * actor->scale < *(f32 *) &actor->actorData[3]) {
            *(f32 *) &actor->actorData[3] -= 15.0f * actor->scale;
        }
}

unk_0 = func_800D8FF8();
parity = func_8001210C(1);
fish = func_80100094(actor, 0);
func_8008FFBC(player_vec);
player_speed = mlAbsF(player_vec[0]) + mlAbsF(player_vec[1]) + mlAbsF(player_vec[2]);
func_8008FE68(player_vec);
for (i = 0; i < actor->unk6C_0; i++) {
    func_800EF214(fish->pos, fish->unkC, fish->unk10, fish->unk28 * unk_0);

if ((parity && (i & 1)) || (!parity && !(i & 1))) {
    if (func_800EFFB4(fish->pos, player_speed * 0.5f, player_vec)) {
        func_800F18FC(player_vec, fish->pos, steer);
        if (fish->unk28 < 400.0f * actor->scale) {
            fish->unk28 += 50.0f * actor->scale;
        }
    } else {
        func_800EE780(target_dir, actor->position, fish->target);
        func_800F18FC(fish->pos, target_dir, steer);
        if (fish->unk28 > 400.0f * actor->scale) {
            fish->unk28 -= 50.0f * actor->scale;
        }
    }
    if (func_800DC0C0() < 0.02f) {
        fish->target[0] = func_800DC178(-400.0f, 400.0f);
        fish->target[1] = func_800DC178(-400.0f, 400.0f);
        fish->target[2] = func_800DC178(-400.0f, 400.0f);
    }
    angle_diff = func_800F1DCC(steer[1], fish->unk10);
    if (angle_diff > 1.0f) {
        if (fish->unk14 < 8.0f) {
            fish->unk14 += 2.0f;
        }
        fish->unk10 += fish->unk14 * 0.5f;
        fish->unk14 *= 0.9f;
    } else if (angle_diff < -1.0f) {
        if (-8.0f < fish->unk14) {
            fish->unk14 -= 2.0f;
        }
        fish->unk10 += fish->unk14 * 0.5f;
        fish->unk14 *= 0.9f;
    }
    angle_diff = func_800F1DCC(steer[0], fish->unkC);
    if (angle_diff > 1.0f) {
        if (fish->unkC < 10.0f) {
            fish->unkC += 1.0f;
        }
    } else if (angle_diff < -1.0f) {
        if (-10.0f < fish->unkC) {
            fish->unkC -= 1.0f;
        }
    }
}

fish++;
}
}

void func_80800908_chlagoonfish(Actor *actor, s32 param_1)
{
    s32 i;
    LagoonFishItem *fish;
    void *models[3];

    fish = func_80100094(actor, 0);
    if (fish != NULL) {
        for (i = 0; i < 3; i++) {
            models[i] = (void *) func_800D674C(actor->unk0->unk14 + i);

}
for (i = 0; i < actor->unk6C_0; i++, fish++) {
    if (models[fish->model_idx] != NULL) {
        func_800DF830(1);
        func_800DE448(fish->pos, fish->rot, fish->scale, NULL,
                      (s32) models[fish->model_idx]);
    }

}
}
}

void func_808009FC_chlagoonfish(u8 *actor)
{
    u32 route;

    route = *(u32 *) (actor + 0x70);
    func_800EE7F8(actor + 0x18, func_800CC63C((route >> 25) - 1, ((route << 22) >> 26) - 1));
}

void func_80800A44_chlagoonfish(actor, state) Actor *actor;
s32 state;
{
    func_80101FDC(actor, state);
    switch (state) {
        case 1:
            actor->unk54 = actor->rotation[1] + func_800DC178(-90.0f, 90.0f);
            actor->unk50 = actor->rotation[0] + func_800DC178(-90.0f, 90.0f);
            break;
        case 2:
            func_808009FC_chlagoonfish(actor);
    }
}

s32 func_80800AE0_chlagoonfish(u8 **actor, s32 msg, S16Pair arg)
{
    if (msg == 0x95) {
        if (D_8012762C == 0x15) {
            func_80103140(actor, 0x698, *(u16 *) (*actor + 0x16));
        }
    } else {
        return 0;
    }
    return 1;
}

int chlagoonfish_entrypoint_0()
{
    return &D_80800B70_chlagoonfish;
}

extern void func_80105834();
extern void func_80107C2C();
void *D_80800B70_chlagoonfish = (void *) 0x02E4031F;
static u32 D_80800B70_chlagoonfish_rest[19] = {0x73F0001,
                                               0x0,
                                               (u32) func_8080038C_chlagoonfish,
                                               (u32) func_80105834,
                                               (u32) func_80800908_chlagoonfish,
                                               0x1D4C0000,
                                               0x0,
                                               0x0,
                                               0x401,
                                               (u32) func_80800264_chlagoonfish,
                                               0x0,
                                               0x0,
                                               (u32) func_808001A0_chlagoonfish,
                                               (u32) func_80107C2C,
                                               0x80004402,
                                               (u32) func_80800AE0_chlagoonfish,
                                               0x0,
                                               0x0,
                                               0x0};
