#include "common.h"

extern void *D_808005D0_changlerbossbubble;
extern void func_800EC75C(void *arg0, f32 *arg1);
extern void func_800EFD4C();
extern f32 func_800D8FF8(void);
extern void func_80015E80(s32, s32 *);
typedef struct {
    u8 pad0[0x18];
    u32 pad18 : 16;
    u32 id : 11;
    u32 lo18 : 5;
    u32 pad1C;
    u32 pad20;
    u32 hi24 : 10;
    u32 lo24 : 22;
} BubbleArg;
extern f32 func_800F5BF0(s32, f32 *);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80800668_changlerbossbubble[];
extern u8 D_80800618_changlerbossbubble[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA568();
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern s32 _chbubble_entrypoint_0(s32, f32 *, f32 *, f32, f32);
void func_80800450_changlerbossbubble();
void func_80800334_changlerbossbubble();

int changlerbossbubble_entrypoint_0()
{
    return (int) &D_808005D0_changlerbossbubble;
}

void func_8080000C_changlerbossbubble(Actor *actor)
{
    f32 unk_0[3];
    func_800EC75C(*(s32 **) actor, unk_0);
    func_800EFD4C((void *) ((u8 *) *(void **) actor + 0x1E));
    *(f32 *) ((u8 *) actor + 0x34) = 0.75f;
}

// Trapped player mashes buttons; 10 presses break free.
void func_80800054_changlerbossbubble(Actor *actor)
{
    s32 buttons[6];
    s32 controller;

    actor->unk58 += func_800D8FF8();
    func_800EFD4C((u8 *) actor->unk0 + 0x1E);
    switch (actor->unk70_10) {
        case 1:
            if (func_8010B990(actor, 0x400007) & 0x20)
                func_80800334_changlerbossbubble(actor);
            break;
        case 2:
            controller = func_800F54F0(actor->unk6C_0);
            func_80800450_changlerbossbubble(actor);
            func_80015E80(controller, buttons);
            if (buttons[0] == 1 || buttons[1] == 1) {
                if (++*(s32 *) ((u8 *) actor + 0x1C) >= 10) {
                    func_800F7B9C(actor->unk6C_0, 0x70);
                    return;
                }
                func_800F7B9C(actor->unk6C_0, 0x7B);
            }
            if (func_800D9078(actor->actorData)) {
                if (actor->unk3C)
                    func_8010114C(actor->unk3C, 0xA, 0);
            }
    }
}

int func_80800194_changlerbossbubble(s32 player)
{
    s32 form;
    if (!func_800F64A4(player, 0xA01)) {
        return 0;
    }
    if (!func_800F6D24(player)) {
        return 1;
    }
    form = func_800F8B88();
    if (form == 3) {
        return 1;
    }
    return 0;
}

s32 func_80800200_changlerbossbubble(Actor *actor, s32 msg, Unk80132ED0 *param_2)
{
    BubbleArg *arg;

    switch (msg) {
        case 0x2C:
            func_80800334_changlerbossbubble(actor);
            break;
        case 0x3E:
            // Matching: param_2 is read through its home slot.
            arg = *(BubbleArg **) &param_2;
            if (arg->hi24 == 0 && func_80800194_changlerbossbubble(arg->id) &&
                func_800F7BC8(arg->id, 0x6F, actor->unk0) == 2) {
                func_8010A570(actor);
                func_80101FDC(actor, 2);
                *(f32 *) &actor->actorData[0] = 3.0f;
                actor->unk6C_0 = arg->id;
                func_80102FDC(actor, func_800F5BF0(actor->unk6C_0, actor->position) * 0.015f);
                break;
            }
            func_80800334_changlerbossbubble(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

// Pop: sound and particles, then despawn.
void func_80800334_changlerbossbubble(actor) Actor *actor;
{
    s32 particle_id;
    s32 emitter;
    f32 scale;
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800668_changlerbossbubble);
    particle_id = func_800DC128(3, 4);
    emitter = func_800B53A4(particle_id);
    scale = actor->scale;
    func_800BABB8(emitter, actor->position, actor->position, 1.0f,
                  D_80800618_changlerbossbubble);
    func_800BA568(emitter, (s16) (actor->position[1] + 1000.0f));
    func_800BA7C4(emitter, 0.25f * scale, 0.6f * scale);
    func_800BA7FC(emitter, 0.1f * scale, 0.2f * scale);
    func_800BA22C(emitter, particle_id);
    func_800FFA88(actor->unk0);
}

void func_80800450_changlerbossbubble(actor) u8 *actor;
{
    func_800F5BF0((*(s32 *) ((s8 *) (actor) + (0x6C))) & 0x1FF, (f32 *) (actor + 4));
}

// Draw with a wobbling scale.
void func_80800480_changlerbossbubble(Actor *actor, s32 param_1)
{
    f32 cam_pos[3];
    f32 draw_pos[3];
    f32 wobble[2];
    func_800EE7F8(draw_pos, actor->position);
    func_800E3980(cam_pos);
    func_800F18FC(draw_pos, cam_pos, wobble);
    func_800EEBF0(cam_pos, wobble, 75.0f);
    func_800EF04C(draw_pos, cam_pos);
    wobble[0] = func_80013970(func_800F13C4(actor->unk58, *(f32 *) ((u8 *) actor + 0x34)) /
                               *(f32 *) ((u8 *) actor + 0x34) * 360.0f) *
                     0.1f +
                 1.0f;
    wobble[1] = func_800138D0(func_800F13C4(actor->unk58, *(f32 *) ((u8 *) actor + 0x34)) /
                               *(f32 *) ((u8 *) actor + 0x34) * 360.0f) *
                     0.15f +
                 1.0f;
    actor->unk7C_12 = _chbubble_entrypoint_0(param_1, draw_pos, wobble, actor->scale, 0.0f);
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
// TU-NOTE: .data of this overlay is defined here in C.
void *D_808005D0_changlerbossbubble = (void *) 0x02A90460;
static u32 D_808005D0_changlerbossbubble_rest[17] = {0x9CB0001,
                                                     0x0,
                                                     (u32) func_80800054_changlerbossbubble,
                                                     (u32) func_80105834,
                                                     (u32) func_80800480_changlerbossbubble,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x4,
                                                     0x0,
                                                     (u32) func_80108ED0,
                                                     0x0,
                                                     (u32) func_8080000C_changlerbossbubble,
                                                     (u32) func_80107C2C,
                                                     0x0,
                                                     (u32) func_80800200_changlerbossbubble,
                                                     0x0};
u8 D_80800618_changlerbossbubble[80] = {
    0x0, 0x1D, 0x9, 0xCB, 0x0, 0x16, 0x12, 0x0,  0x0, 0x1,  0x0,  0x0,  0x0,  0x23, 0x0, 0x0,
    0x0, 0x0,  0x0, 0x32, 0x0, 0x0,  0x0,  0x1B, 0x0, 0x96, 0x0,  0xC8, 0x0,  0x7,  0x0, 0x1,
    0x0, 0x15, 0x0, 0x0,  0x0, 0xCC, 0x0,  0xE,  0x0, 0x32, 0x0,  0x3C, 0x0,  0x2D, 0x0, 0x64,
    0x0, 0xC8, 0x0, 0x2B, 0x1, 0x80, 0x2,  0x80, 0x0, 0x1F, 0x50, 0xF0, 0xFF, 0x0,  0x0, 0x2F,
    0x0, 0x40, 0x0, 0x40, 0x0, 0x0,  0x0,  0x0,  0x0, 0x19, 0x0,  0x0,  0x0,  0x33, 0x0, 0x0};
u8 D_80800668_changlerbossbubble[24] = {0x0, 0x13, 0x4, 0xB1, 0x0, 0xD, 0x0, 0xF3,
                                        0x1, 0xC,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0,
                                        0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
