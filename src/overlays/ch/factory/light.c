#include "common.h"

extern int D_80800B90_chfactorylight[];
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 pad_0[15];
    u8 alpha;
} FactoryLightVertex;
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct {
    u8 pad_0[0x10];
    s32 r;
    s32 g;
    s32 b;
} FactoryLightColor;
extern void func_801015D0(Actor *);
extern void func_80101808(Actor *, void (*)(Actor *));
extern void func_800EE7F8(f32[3], f32[3]);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
extern void func_80103014(Actor *);
typedef struct {
    f32 f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;
} ADF_;
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} FLightState;
extern u8 _chfactorylight_entrypoint_1[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800F3214(f32 *, f32 *, f32 *, s32);
extern void func_800C4140(u32, f32 *, u32);
extern int func_800D9154(f32 *, f32);
extern void func_800C8CB8(s32 param_0, f32 param_1[3]);
extern void func_800C8E84(s32 param_0, u32 param_1[3]);
extern s32 func_800D90A4(f32 *param_0);
extern void func_800EF04C(f32 *param_0, f32 *param_1);
extern void func_80101FDC(Actor *param_0, u32 param_1);
extern s32 func_801065A4(s32 param_0);
typedef struct {
    u8 pad0[0x7C];
    u32 pad7C : 16;
    u32 flag : 1;
    u32 rest : 15;
} FactoryLightFlags;
typedef struct {
    s32 ids[2];
    f32 angles[2];
    u8 color[1];
} FactoryLights50;
extern void func_800C8E54(s32, f32, f32);
void func_80800830_chfactorylight();
void func_808008E4_chfactorylight();
extern void func_80105834(), func_80107C2C(), func_80800408_chfactorylight(),
    func_808006B8_chfactorylight();

int *chfactorylight_entrypoint_0()
{
    return &D_80800B90_chfactorylight;
}

s32 func_8080000C_chfactorylight(actor)
s32 actor;
{
    func_80800830_chfactorylight(actor);
    func_8010A800(actor, 2);
}

void func_80800038_chfactorylight(Actor *actor)
{
    s32 *slot;
    s32 i;
    f32 color[1];
    s32 *lights;
    s32 *light_data;
    f32 pos[3];
    f32 dt;
    s32 near;
    f32 color_end[3];
    u16 t;
    lights = func_80100094(actor, 0);
    dt = func_800D8FF8();
    light_data = lights;
    func_800EE7F8(pos, actor->position);
    func_800EF1B8(pos, *(f32 *) &actor->rotation[1], actor->scale * 300.0f);
    near = func_800E3E8C(pos, actor->scale * 1300.0f);

switch (((FLightState *) actor)->st) {
    case 1:
        func_800F2E60(color, (u8 *) light_data + 0x10);
        actor->unk54 = 1.0f;
        break;
    case 2:
        func_800EFD3C(color);
        actor->unk54 = 0.0f;
        break;
    case 3:
        if (func_800D90A4(&actor->unk58)) {
            func_80101FDC(actor, 1);
        }
        actor->unk54 = func_800F10B4(actor->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
        func_800EFD3C(color_end);
        func_800F3214(color, color_end, (f32 *) ((u8 *) light_data + 0x10), *(s32 *) &actor->unk54);
}

actor->rotation[2] = func_800136E4(
    ((dt * (*((f32 *) (&actor->actorData[7])))) * actor->unk54) + actor->rotation[2]);

if (actor->unk78 && !_subaddiezone_entrypoint_1(actor)) {
    near = 0;
}

for (i = 0, slot = lights; i < 8; i += 4, slot++) {
    *(f32 *) &slot[2] = func_800136E4(
        *(f32 *) &slot[2] + dt * ((ADF_ *) actor->actorData)->f7 * actor->unk54);
    func_800EEC30(pos, *(f32 *) &slot[2], actor->rotation[1] + 90.0f,
                  actor->scale * 500.0f);
    func_800EF04C(pos, actor->position);
    func_800EF1B8(pos, *(f32 *) &actor->rotation[1], actor->scale * 300.0f);

if (near) {
    func_800C8CB8(slot[0], pos);
    func_800C8E84(slot[0], color);
}

}
if (actor->unk7C_12) {
    if (func_801065A4(actor)) {
        _glid_entrypoint_0(func_801065A4(actor), 1, _chfactorylight_entrypoint_1, actor->unk0);
    }

}
if (func_800EA05C() == 0x10D) {
    if (((FLightState *) actor)->st == 3 || ((FLightState *) actor)->st == 1) {
        if (func_800D9154(&actor->actorData[3], 1.3f)) {
            t = (u32) (func_800F1214(actor->unk54, 0.9f, 1.1f) * 1023.0f);
            func_800C4140((t << 21) + 0x1F4566, actor->position, 0x138800FA);
        }
    }

}
}

void func_80800408_chfactorylight(actor) Actor *actor;
{
    s32 i;
    s32 *lights;

    lights = func_80100094(actor, 0);
    for (i = 0; i < 2; i++) {
        if (lights[i] != 0) {
            func_800C8B84(lights[i]);
            lights[i] = 0;
        }

}
}

// Vertex callback: scales vertex alpha by the lamp intensity.
void chfactorylight_entrypoint_1(s32 param_0, FactoryLightVertex *src,
                                 FactoryLightVertex *verts, s32 count, Unk80132ED0 *ctx)
{
    Actor *actor;
    FactoryLightVertex *end;
    actor = func_80106790(ctx);
    end = verts + count;
    for (; verts < end; src++, verts++) {
        verts->alpha = (u32) (src->alpha * actor->unk54);
    }
}

s32 func_8080057C_chfactorylight(actor, msg, value)
Actor *actor;
s32 msg;
s32 value;
{
    s32 enable;
    s32 i;
    s32 *lights;

    switch (msg) {
        case 0xA:
            if (value)
                enable = 1;
            else
                enable = 0;
            lights = func_80100094(actor, 0);

if (!((FactoryLightFlags *) actor)->flag) {
    func_808008E4_chfactorylight(actor);
    ((FactoryLightFlags *) actor)->flag = 1;
}

if (func_800EA05C() == 0x10D) {
    func_80101FDC(actor, enable ? 3 : 2);
    actor->unk58 = 5.0f;
    *(f32 *) ((u8 *) actor + 0x24) = 1.3f;
} else {

func_80101FDC(actor, enable ? 1 : 2);
}
for (i = 0; i < 8; i += 4) {
    func_800C8FE0(*(s32 *)((u8 *)lights + i), enable);
}
break;
case 0x95:
func_808008E4_chfactorylight(actor);
break;
default:
return 0;
}
return 1;
}

void func_808006B8_chfactorylight(actor, param_1) Actor *actor; s32 param_1;
{
    FactoryLightColor *color;
    f32 intensity;

    color = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
        case 3:
        intensity = actor->unk54;
        func_800DF5D8((s32)(color->r * intensity),
        (s32)(color->g * intensity),
        (s32)(color->b * intensity), 255);
    }
    func_80101970(actor);
    func_80101808(actor, func_801015D0);
}

// Matching: the line breaks in this function are needed for the match.
// Picks the beacon colour (RGB) from the variant.
void func_80800778_chfactorylight(Actor *actor, u32 *rgb)
{
    u32 color;

    switch (*(u32 *)((u8 *)actor + 0x6C) & 0x1FF) {
        case 0: color = 0xFFFF2000; break;
        case 1: color = 0x20FF0000; break;
        case 2: color = 0xFF202000; break;
        case 3: color = 0x0096FF00; break;
        case 4: color = 0x20FFFF00; break;
        case 5: color = 0xFF802000; break;
        case 6: color = 0xFF60FF00; break;
        case 7: color = 0xFFFFFF00; break;
        default: color = 0xFFFF2000; break;
    }
    rgb[0] = (color & 0xFF000000) >> 24; rgb[1] = (color & 0x00FF0000) >> 16; rgb[2] = (color & 0x0000FF00) >> 8;
}

// Snaps the lamp to the wall via a raycast.
void func_80800830_chfactorylight(actor) Actor *actor;
{
    f32 start[3];
    f32 end[3];
    f32 hit[3];
    func_800EE7F8(start, actor->position);
    func_800EF1B8(start, actor->rotation[1], 100.0f);
    func_800EE7F8(end, actor->position);
    func_800EF1B8(end, actor->rotation[1], -200.0f);
    if (func_800BEF00(start, end, hit, actor->unk14)) {
        func_800EE7F8(actor->position, end);
        func_800EF1B8(actor->position, actor->rotation[1], actor->scale * 5.0f);
        func_80103014(actor);
    }
}

// Sets up the two orbiting point lights; in Quality Control starts on if flag 0x1BD is set.
void func_808008E4_chfactorylight(actor) Actor *actor;
{
    FactoryLights50 *lights;
    f32 scale;
    f32 pos[3];
    f32 angle;
    s32 i;
    s32 variant;
    lights = (FactoryLights50 *)func_80100094(actor, 0);
    variant = actor->unk74_7 - 0x32;
    if (variant < 0 || variant >= 8) variant = 0;
    actor->unk6C_0 = variant;
    *(f32 *)&actor->actorData[7] = func_800DC128(200, 300);
    func_80800778_chfactorylight(actor, lights->color);
    for (i = 0; i != 2; i++) {
        lights->ids[i] = func_800C8A98();
        angle = i * 180.0f;
        lights->angles[i] = angle;
        func_800C8E84(lights->ids[i], lights->color);
        func_800EEC30(pos, angle, actor->rotation[1] + 90.0f, actor->scale * 500.0f);
        func_800EF04C(pos, actor->position);
        func_800EF1B8(pos, actor->rotation[1], actor->scale * 300.0f);
        func_800C8CB8(lights->ids[i], pos);
        scale = actor->scale;
        func_800C8E54(lights->ids[i], scale * 350.0f, scale * 800.0f);
    }
    if (func_800EA05C() == 0x10D) {
        if (func_800DA298(0x1BD)) {
            func_80101FDC(actor, 1);
            func_800C8FE0(lights->ids[0], 1);
            func_800C8FE0(lights->ids[1], 1);
            *(f32 *)&actor->actorData[3] = 1.3f;
        } else {
            func_80101FDC(actor, 2);
            func_800C8FE0(lights->ids[0], 0);
            func_800C8FE0(lights->ids[1], 0);
        }
    }
}

int D_80800B90_chfactorylight[20] = { 0x2A303A7, 0x7430001, 0x0, (u32)func_80800038_chfactorylight, (u32)func_80105834, (u32)func_808006B8_chfactorylight, 0x0, 0x0, 0x0, 0x5C00, (u32)func_80800408_chfactorylight, 0x0, 0x1C0000, (u32)func_8080000C_chfactorylight, (u32)func_80107C2C, -0x7FFFDBFE, (u32)func_8080057C_chfactorylight, 0x0, 0x0, 0x0 };
