#include "core2/1EDAEA0.h"

#define ACT(p) ((LocalActor_801015D0 *) (p))
extern s32 D_80135A90;
extern s16 D_80135A94;
typedef struct {
    u8 pad0[0x10];
    s16 id;
    u8 pad12[2];
    u16 model;
} LocalDesc;
typedef struct {
    LocalDesc *desc;
    u8 pad4[0x6C];
    u32 unused0 : 7, flag0 : 1, unused1 : 2, flag1 : 1, unused2 : 21;
    u32 word74;
    u32 unused3 : 16, mode : 2, unused4 : 14;
    u32 unused5 : 19, disabled : 1, unused6 : 7, updated : 1, unused7 : 4;
    u8 pad80[0x1B], alpha;
} LocalActor_801015D0;
extern f32 D_801243E0[2];
typedef void (*D_801243E8Entry)(void);
extern D_801243E8Entry D_801243E8[];
typedef struct {
    u8 pad0[0x70];
    u32 pad70_0 : 11;
    u32 unk70_11 : 1;
    u32 pad70_12 : 20;
    u8 pad74[0x20];
    u32 pad94_0 : 1;
    u32 unk94_1 : 1;
    u32 pad94_2 : 30;
} S80101970;
extern void func_800DF428(f32);
extern void func_800DF470(s32);
extern u8 *func_80100368(S80101970 *);
extern void func_800DF440(s32);
typedef struct {
    u8 pad[0x78];
    u32 unused0 : 18, state : 2, count : 3, unused1 : 9;
    u32 unused2 : 19, disabled : 1, unused3 : 12;
} LocalActor_80101A50;
extern f32 func_800DC0C0(void);
f32 *func_80101918(f32 scale);
void func_80101934();
void func_80101970();

void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
void func_800DF47C(s32 (*arg0)(Actor *), Actor *);
f32 *func_801027F4(Actor *);

int func_801015B0()
{
    return (int) &D_80135A90;
}

int func_801015BC()
{
    D_80135A94 = 0;
}

void func_801015C8(void)
{
}

// Draw callback: sets up the model renderer from the actor state.
s32 func_801015D0(Actor *actor)
{
    s32 unk_0;
    LocalDesc *desc;
    s32 expression;
    s32 unk_1;
    s32 anim_ctrl;
    s32 unk_2;
    s32 anim_ctrl_b;
    s32 unk_3;
    unk_1 = func_801039E4(ACT(actor)->desc);
    func_80103D48(actor);
    anim_ctrl = func_80104248(actor);
    if (anim_ctrl) {
        if (!ACT(actor)->disabled)
            func_8008B304(anim_ctrl);
        func_800DF41C(func_8008C27C(func_8008AEDC(anim_ctrl)));
    }
    desc = ACT(actor)->desc;
    expression = _suexpression_entrypoint_20(actor);
    if (expression)
        _suexpression_entrypoint_19(expression, actor);
    if (desc->id) {
        anim_ctrl_b = func_80104248(actor);
        unk_2 = func_800B27E0(unk_1);
        func_8010108C(actor, 0x9C, unk_1);
        if (anim_ctrl_b) {
            if (unk_2) {
                if (!ACT(actor)->disabled)
                    func_8008C200(desc->id, unk_2, func_8008AEDC(anim_ctrl_b));
                func_800DF72C(func_800AE080(desc->id));
            }
        } else if (unk_2)
            func_800ADD80(desc->id, unk_2);
    }
    if (expression)
        _suexpression_entrypoint_11(expression, actor);
    func_800DF410(ACT(actor)->alpha);
    func_800DF830(ACT(actor)->mode);
    func_800DF738(_subaddieskeleton_entrypoint_4(actor));
    if (ACT(actor)->flag0 || ACT(actor)->flag1)
        func_800DF818(func_80103CDC(actor, unk_1));
    func_80106A98(actor, unk_1);
    func_80101934(actor);
    unk_3 = func_800D731C(ACT(actor)->desc->model);
    unk_0 = unk_3 & 0xFF;
    if (unk_3)
        func_800DF7E8(unk_0);
    func_80103D70(actor);
    ACT(actor)->disabled = 1;
}

s32 func_801017D0(s32 *actor)
{
    // Matching: extra pointer temporary needed for the match.
    s32 *unk_0;
    s32 unk_1;
    unk_1 = func_801039E4(*actor);
    unk_0 = &unk_1;
    return func_8010108C(actor, 0x1F, *unk_0);
}

s32 func_801018D8();

// Registers the pre-draw callback and draws the actor model.
void func_80101808(Actor *actor, s32 (*draw_fn)(Actor *))
{
    // Matching: padding reserves stack space.
    s32 pad[2];
    f32 *flip;
    f32 *rotation;

    func_800DF47C(draw_fn, actor);
    rotation = func_801027F4(actor);
    flip = func_801018D8(actor);
    func_800DE448(actor->position, rotation, actor->scale, flip, func_8010347C(actor->unk0));
}

void func_80101870(Actor *actor, void *arg1)
{
    func_80101970(actor);
    func_80101808(actor, func_801015D0);
}

void func_801018A4(s32 actor, s32 param_1)
{
    func_80101970();
    func_80101808(actor, func_801017D0);
}

s32 func_801018D8(u8 *actor)
{
    s32 flip;

    flip = (*(u16 *) ((char *) actor + 0x94) & 1)
                  ? func_80101918(*(f32 *) ((char *) actor + 0x38))
                  : 0;
    return flip;
}

f32 *func_80101918(f32 scale)
{
    f32 *flip = D_801243E0;
    flip[1] = -4.0f / scale;
    return flip;
}

// Calls the draw-mode callback selected by the low bits of the actor flags.
void func_80101934(actor) Actor *actor;
{
    u32 draw_mode;
    draw_mode = 0xF & *(s32 *) ((char *) actor + 0x74);
    if (draw_mode != 0) {
        D_801243E8[draw_mode]();
    }
}

// Sets the draw distance for the model renderer.
void func_80101970(actor) S80101970 *actor;
{
    f32 draw_dist;
    func_800DF470(actor->unk70_11);
    draw_dist = (u32) *(u16 *) (func_80100368(actor) + 0x1A);
    if (draw_dist != 0.0f) {
        func_800DF428(draw_dist);
    } else if (!(*(s32 *) (*(u8 **) actor + 0x10) & 1)) {
        // Draw distance is fixed when flag 0x200 is set.
        if (func_800EA068(0x200) != 0) {
            draw_dist = 29999.0f;
        } else {
            draw_dist = (f32) func_800D2F20();
        }
        func_800DF428(draw_dist);
    }
    if (actor->unk94_1) {
        func_800DF440(0);
    }
}

// Eye-blink state machine.
void func_80101A50(LocalActor_80101A50 *actor)
{
    if (!actor->disabled) {
        switch (actor->state) {
            case 0:
                if (func_800DC0C0() < 0.03f)
                    actor->state = 1;
                break;
            case 1:
                if (actor->count == 3)
                    actor->state = 2;
                else
                    actor->count++;
                break;
            case 2:
                actor->count--;
                if (!actor->count)
                    actor->state = 0;
        }
    }
    func_800DF744(1, actor->count + 1, actor);
    func_800DF744(2, actor->count + 1, actor);
}

int func_80101BA0(s32 param_0)
{
    func_800DF744(1, 4);
    func_800DF744(2, 4);
}

// TU-NOTE: .data is defined here because IDO schedules functions of this file differently otherwise.
f32 D_801243E0[2] = {0.0f, -4.0f};
D_801243E8Entry D_801243E8[6] = {0, (void *) func_80101A50, (void *) func_80101BA0, 0, 0, 0};
