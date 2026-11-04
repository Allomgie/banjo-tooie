#include "common.h"

extern void _subaddiedraw25d_entrypoint_0(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E24E4(void (*)(), Actor *);
typedef struct {
    u32 pad : 30;
    u32 flag : 1;
    u32 pad2 : 1;
} BitTest30;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 30;
    u32 colored : 1;
    u32 pad_2 : 1;
} Draw25dFlags;
typedef struct {
    u8 pad_0[8];
    u32 pad_1 : 26;
    u32 flipped : 1;
    u32 pad_2 : 5;
} Draw25dMarkerInfo;
void subaddiedraw25d_entrypoint_3();

// Draw callback: sets a flag on the actor.
int subaddiedraw25d_entrypoint_0(u8 *actor)
{
    actor[0x7E] = (actor[0x7E] & 0xFFFFu) | 0x10;
}

// Draw the actor's sprite model as a rotated billboard.
void subaddiedraw25d_entrypoint_1(Actor *actor, s32 unk_0)
{
    f32 scale[3];
    f32 rot[3];
    Unk80132ED0 *obj;
    s32 model;
    u8 *info;

    obj = actor->unk0;
    model = func_80103AE4(obj);
    scale[0] = scale[1] = scale[2] = actor->scale;
    func_800EFA4C(rot, actor->rotation[0], actor->rotation[1], 0.0f);
    if (*(u16 *) ((u8 *) actor + 0x78) & 3) {
        func_800E257C(*((u8 *) actor + 0x9B));
        func_800E2588(1);
    } else if (func_800AF5A8(model) & 0xB00) {
        func_800E2588(1);
    } else {
        func_800E2588(3);
    }
    if (((BitTest30 *) ((u8 *) actor + 0x78))->flag) {
        func_800E24F8(*((u8 *) actor + 0x98), *((u8 *) actor + 0x99), *((u8 *) actor + 0x9A));
    }
    subaddiedraw25d_entrypoint_3(actor);
    func_800E24E4(_subaddiedraw25d_entrypoint_0, actor);
    info = *(u8 **) obj;
    func_800E2C54(unk_0, model, (u32) *(u16 *) (info + 0xA) >> 11,
                  (*(u32 *) (info + 8) << 26) >> 31, actor->position, rot, scale);
}

// Draw the actor's sprite model as a plain billboard.
void subaddiedraw25d_entrypoint_2(Actor *actor, s32 unk_0)
{
    f32 scale[3];
    Unk80132ED0 *obj;
    s32 model;
    u8 *info;
    obj = actor->unk0;
    model = func_80103AE4(obj);
    scale[0] = scale[1] = scale[2] = actor->scale;
    if (*(u16 *) ((u8 *) actor + 0x78) & 3) {
        func_800E257C(actor->alpha);
        func_800E2588(1);
    } else {
        if (func_800AF5A8(model) & 0xB00)
            func_800E2588(1);
        else
            func_800E2588(3);
    }
    if (((Draw25dFlags *) actor)->colored)
        func_800E24F8(actor->pad98, actor->pad99, actor->pad9A);
    subaddiedraw25d_entrypoint_3(actor);
    func_800E24E4(_subaddiedraw25d_entrypoint_0, actor);
    info = *(u8 **) obj;
    func_800E2AA4(unk_0, model, (u32) *(u16 *) (info + 0xA) >> 11,
                  ((Draw25dMarkerInfo *) info)->flipped, actor->position, scale);
}

// Set the environment light from the ActorInfo (+0x1A) or the default.
void subaddiedraw25d_entrypoint_3(actor) u8 *actor;
{
    u16 light;

    func_800E24C0((u32) ((*(s32 *) ((s8 *) (actor) + (0x70))) << 0xB) >> 0x1F);
    light = (*(u16 *) ((s8 *) (func_80100368(actor)) + (0x1A)));

if (light != 0) {
    func_800E249C(light);
    return;
}

if (!(*(s32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 0x10) & 1)) {
    func_800E249C(func_800D2F20(light));
}

}
