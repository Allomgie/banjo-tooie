// Probably Klungo's spinning forcefield bubble: an animated sprite with a random spin, a point
// light and a looping hum that follow the fade alpha, and a light-fader effect when it pops.
#include "common.h"

extern int D_80800400_chklungoforcefield[];
extern u8 D_80800460_chklungoforcefield[];
extern u8 D_80800448_chklungoforcefield[];
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern u8 func_800E8B74(s32);
extern void func_800E8DB0(u8, s32);
extern void func_800E8D28(u8, f32);
typedef struct {
    u8 pad_0[0x18];
    s32 light;
    u8 pad_1C[8];
    u8 sprite;
} ForceS;
extern void func_800C8B84(s32);
extern void func_800E8C08(u8);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_801015D0(void);
extern void func_800DE448(f32 *, f32 *, f32, s32, void *);
extern void *func_8010347C(Unk80132ED0 *);
extern f32 D_8080046C_chklungoforcefield[];
extern f32 func_800D8FF8(void);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800C8E54(s32, f32, f32);

int *chklungoforcefield_entrypoint_0()
{
    return &D_80800400_chklungoforcefield;
}

// Actor fields used here: +0x18 light handle, +0x1C spin angle, +0x20 spin speed,
// +0x24 sprite animator id.
void func_8080000C_chklungoforcefield(Actor *actor)
{
    f32 spin_dir;
    s32 light;
    u8 sprite;

    spin_dir = func_800DC298(0.5f) ? 1.0f : -1.0f;
    *(f32 *) ((u8 *) actor + 0x20) = func_800DC178(30.0f, 45.0f) * spin_dir;
    light = func_800C8A98();
    *(s32 *) ((u8 *) actor + 0x18) = light;
    func_800C8CB8(light, actor->position);
    func_800C8E84(*(s32 *) ((u8 *) actor + 0x18), D_80800460_chklungoforcefield);
    sprite = func_800E8B74(0);
    *(u8 *) ((u8 *) actor + 0x24) = sprite;
    func_800E8DB0(sprite, 0xFF);
    func_800E8D28(*(u8 *) ((u8 *) actor + 0x24), 1.0f);
    func_800E8D5C(*(u8 *) ((u8 *) actor + 0x24), D_80800448_chklungoforcefield, 3);
    _subaddiefade_entrypoint_2(actor);
    func_8010A828(actor, 0x40);
}

void func_808000F0_chklungoforcefield(Actor *actor)
{
    f32 radius;

    *(f32 *) ((u8 *) actor + 0x1C) += *(f32 *) ((u8 *) actor + 0x20) * func_800D8FF8();
    _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_8080046C_chklungoforcefield);
    _subaddieaudioloop_entrypoint_1(
        actor,
        (s32) func_800F12D4(_subaddiefade_entrypoint_0(actor), 0.0f, 255.0f, 8000.0f, 32767.0f));
    if (*(s32 *) ((u8 *) actor + 0x18) != 0) {
        radius = func_800F12D4(_subaddiefade_entrypoint_0(actor), 0.0f, 255.0f, 300.0f, 800.0f);
        func_800C8E54(*(s32 *) ((u8 *) actor + 0x18), radius, 2.0f * radius);
    }
}

void func_808001D4_chklungoforcefield(ForceS *actor)
{
    if (actor->light) {
        func_800C8B84(actor->light);
        actor->light = 0;
    }
    if (actor->sprite) {
        func_800E8C08(actor->sprite);
        actor->sprite = 0;
    }
}

s32 func_80800228_chklungoforcefield(u8 *actor, s32 msg, s32 unused)
{
    s32 light;

    if (msg == 0x2C) {
        light = *(s32 *) ((s8 *) actor + 0x18);
        if (light != 0) {
            *(s32 *) ((s8 *) actor + 0x18) =
                _chlightfader_entrypoint_1(light, 0x4019999A, 2, actor);
        }
        _subaddiefade_entrypoint_3(actor);
        return 1;
    }
    return 0;
}

void func_80800288_chklungoforcefield(Actor *actor, s32 unused)
{
    f32 unk_0[3];
    f32 sprite_scale;
    s32 alpha;
    void *unk_1;
    s32 unk_2;

    alpha = *((u8 *) actor + 0x9B);
    sprite_scale =
        func_800F10B4((f32) func_800E8C58(*((u8 *) actor + 0x24)), 0.0f, 255.0f, 0.6f, 1.0f);
    func_800E3A58(unk_0);
    func_80101970(actor);
    unk_0[2] += *(f32 *) &actor->actorData[1];
    *((u8 *) actor + 0x9B) = (u32) ((f32) alpha * sprite_scale);
    func_800DF47C(func_801015D0, actor);
    unk_2 = func_801018D8(actor);
    unk_1 = func_8010347C(actor->unk0);
    func_800DE448(actor->position, unk_0, actor->scale, unk_2, unk_1);
    *((u8 *) actor + 0x9B) = alpha;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800400_chklungoforcefield[18] = {0xB40421,
                                         0x8220001,
                                         0x0,
                                         (u32) func_808000F0_chklungoforcefield,
                                         (u32) func_80105834,
                                         (u32) func_80800288_chklungoforcefield,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x100404,
                                         (u32) func_808001D4_chklungoforcefield,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_8080000C_chklungoforcefield,
                                         (u32) func_80107C2C,
                                         -0x7FFFE000,
                                         (u32) func_80800228_chklungoforcefield,
                                         0x0};
u8 D_80800448_chklungoforcefield[24] = {0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0,
                                        0x3F, 0x0,  0x0, 0x0, 0x3F, 0x80, 0x0, 0x0,
                                        0x3F, 0x80, 0x0, 0x0, 0x0,  0x0,  0x0, 0x0};
u8 D_80800460_chklungoforcefield[12] = {0x0, 0x0,  0x0, 0x20, 0x0, 0x0,
                                        0x0, 0xE0, 0x0, 0x0,  0x0, 0xFF};
f32 D_8080046C_chklungoforcefield[5] = {1.746925e-39f, 1.286037e-39f, 2.571401e-38f, 2.031591e-39f,
                                        0.0f};
