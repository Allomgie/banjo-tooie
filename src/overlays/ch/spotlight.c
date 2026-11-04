// Most likely the spotlights of Mr. Patch's arena: they switch on when the fight starts, flicker,
// then track the boss (actor 0x13C) with a point light and cone model, and turn off when he loses.
#include "common.h"

extern int D_808009B0_chspotlight[];
extern void *func_80100094(Actor *, u32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 func_801017D0[];
typedef struct {
    s32 light;
    f32 anchor[3];
    f32 light_pos[3];
} CodexSpotlightData;
extern s32 D_80800998_chspotlight[];
extern s32 D_808009A4_chspotlight[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern int func_800F3214(s32 *, s32 *, s32 *, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 D_80800990_chspotlight[];
extern void func_800C8D4C(s32, f32 *);
typedef struct {
    u8 pad_0[4];
    f32 target[3];
    u8 pad_10[0x18];
    f32 unk_28;
    u8 pad_2C[4];
    f32 unk_30;
    u8 pad_34[4];
    f32 unk_38;
} SpotlightAim;
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102B2C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
typedef struct {
    s32 light;
    u8 pad_4[12];
    f32 light_pos[3];
    f32 rest_yaw;
    f32 brightness;
    s32 lit;
    f32 angle_a;
    f32 speed_a;
    f32 angle_b;
    f32 speed_b;
    f32 dist;
} Mass47Spotlight;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern f32 func_80102D78(Actor *, f32 *);
typedef struct {
    s32 light;
    u8 pad_4[0x18];
    f32 rest_yaw;
    f32 brightness;
    s32 lit;
} SpotlightState;
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800D8FF8(void);
typedef struct {
    u8 pad_0[0x28];
    f32 angle_a;
    f32 speed_a;
    f32 angle_b;
    f32 speed_b;
    f32 dist;
} SpotlightMotion;
int func_808008A4_chspotlight();
extern void func_80105834(), func_80107C2C(), func_80800210_chspotlight();

int chspotlight_entrypoint_0()
{
    return (int) &D_808009B0_chspotlight;
}

// Finds the boss (actor 0x13C) and stores its id.
s32 func_808008EC_chspotlight();

// Init: creates the point light and randomizes the light motion.
void func_8080000C_chspotlight(Actor *spotlight)
{
    Mass47Spotlight *data;
    Actor *boss;
    s32 unk_0;
    f32 rate;
    f32 *pos_ptr[1];

    data = func_80100094(spotlight, 0);
    func_800EE7F8(data->light_pos, spotlight->position);
    if (func_800DA298(0x9C) || !func_808008EC_chspotlight(spotlight)) {
        func_80101FDC(spotlight, 5);
    } else if (func_808008A4_chspotlight(spotlight)) {
        boss = func_80106790(spotlight->unk3C);
        func_800EE7F8(data->light_pos, boss->position);
        spotlight->rotation[1] = spotlight->unk54 = func_80102D78(spotlight, boss->position);
    }
    if ((s32) spotlight->unk74_7 < 0x34) {
        pos_ptr[0] = data->light_pos;
        data->light = func_800C8A98();
        data->rest_yaw = spotlight->rotation[1];
        data->lit = 0;
        data->brightness = 0.0f;
        func_800C8D4C(data->light, D_80800990_chspotlight);
        func_800C8E84(data->light, (u8 *) D_80800998_chspotlight);
        func_800C8CB8(data->light, pos_ptr[0]);
        func_800C8FE0(data->light, 0);
    } else {
        data->light = 0;
    }
    data->angle_a = func_800DC178(0.0f, 360.0f);
    rate = func_800DC178(20.0f, 60.0f);
    data->speed_a = (func_800DC298(0.5f) ? 1.0f : -1.0f) * rate;
    data->angle_b = func_800DC178(0.0f, 360.0f);
    rate = func_800DC178(20.0f, 60.0f);
    data->speed_b = (func_800DC298(0.5f) ? 1.0f : -1.0f) * rate;
    data->dist = 525.0f;
}

void func_808007F4_chspotlight(u8 *spotlight, f32 level);

void func_80800210_chspotlight(spotlight) Actor *spotlight;
{
    SpotlightState *state;
    s32 pad0;
    f32 level;
    s32 flag;

    state = func_80100094(spotlight, 0);
    _sudeflect_entrypoint_1(spotlight->position, spotlight->scale * 200.0f, 0.0f,
                            spotlight->scale * 125.0f, 10);
    switch (spotlight->unk70_10) {
        case 1:
            flag = spotlight->unk74_7 == 0x33 ? 2 : 4;
            if (func_800DA298(flag)) {
                func_80101FDC(spotlight, 2);
                state->lit = 1;
                if (state->light)
                    func_800C8FE0(state->light, 1);
            }
            break;
        case 2:
            level = state->brightness;
            level += 0.06f;
            if (level > 1.0f) {
                level = 1.0f;
                state->brightness = level;
                func_80101FDC(spotlight, 3);
            } else {
                state->brightness = level;
                if (level < 0.9f && func_800DC298(0.6f)) {
                    level *= func_800DC178(0.25f, 0.5f);
                    state->lit = 0;
                } else {
                    state->lit = 1;
                }
            }
            func_808007F4_chspotlight(spotlight, level);
            break;
        case 3:
            func_808007F4_chspotlight(spotlight, 1.0f);
            break;
        case 4:
            func_80102B2C(spotlight, func_800D8FF8() * 60.0f);
            func_80102B6C(spotlight, func_800D8FF8() * 60.0f);
            if (func_80102CCC(spotlight) && func_80102CA4(spotlight)) {
                spotlight->rotation[1] = state->rest_yaw;
                spotlight->rotation[0] = 0.0f;
                func_80101FDC(spotlight, 5);
            }
    }
}

void func_8080047C_chspotlight(Actor *spotlight)
{
    u8 *data;
    s32 model;
    f32 rot[3];
    f32 matrix[4];

    data = func_80100094(spotlight, 0);
    model = func_801040D0();
    func_801015D0(spotlight);
    func_800DF41C(model);
    func_800EFA4C(rot, spotlight->rotation[0] + 90.0f, 0.0f, 0.0f);
    func_800D93A0(matrix, rot);
    func_800DFF2C(model, 1, matrix);
    func_800DF744(1, *(s32 *) (data + 0x24));
}

int func_80800518_chspotlight(actor, unk_0)
s32 actor;
s32 unk_0;
{
    f32 vec[3];
    func_80102780(actor, vec);
    vec[0] = 0.0f;
    func_800DF47C(&func_801017D0, actor);
    func_800DE448(actor + 4, vec, *(s32 **) (actor + 0x38), 0,
                  func_8010347C(*(s32 *) actor));
}

void func_80800580_chspotlight(spotlight) Actor *spotlight;
{
    SpotlightMotion *motion;
    Actor *boss;
    f32 dt;
    motion = func_80100094(spotlight, 0);
    boss = func_80106790(spotlight->unk3C);
    dt = func_800D8FF8();
    motion->angle_a += motion->speed_a * dt;
    motion->angle_b += motion->speed_b * dt;
    motion->dist = *(f32 *) ((u8 *) boss + 0x28) * 1500.0f;
}

void func_80800600_chspotlight(Actor *spotlight, f32 level)
{
    CodexSpotlightData *data;
    s32 color[3];

    data = func_80100094(spotlight, 0);
    func_800EEC30(data->light_pos, -spotlight->rotation[0], spotlight->rotation[1],
                  func_800EEAD4(spotlight->position, data->anchor));
    func_800EF04C(data->light_pos, spotlight->position);
    if (data->light) {
        func_800F3214(color, D_80800998_chspotlight, D_808009A4_chspotlight, level);
        func_800C8E84(data->light, color);
        func_800C8CB8(data->light, data->light_pos);
    }
}

void func_808006B8_chspotlight(Actor *spotlight)
{
    s32 *light;
    f32 range[2];
    Actor *boss;
    light = func_80100094(spotlight, 0);
    if (light[0]) {
        boss = func_80106790(spotlight->unk3C);
        range[0] = D_80800990_chspotlight[0] * *(f32 *) &boss->actorData[4];
        range[1] = D_80800990_chspotlight[1] * *(f32 *) &boss->actorData[4];
        func_800C8D4C(light[0], range);
    }
}

void func_80800730_chspotlight(Actor *spotlight)
{
    f32 angles[2];
    SpotlightAim *aim;

    aim = func_80100094(spotlight, 0);
    if (!func_800DA298(0)) {
        if (func_8010114C(spotlight->unk3C, 6, 4))
            func_80101038(aim->target);
        if (func_800DA298(4))
            func_800EF214(aim->target, aim->unk_28, aim->unk_30, aim->unk_38);
        func_800F18FC(spotlight->position, aim->target, angles);
        spotlight->unk50 = -angles[0];
        spotlight->unk54 = angles[1];
        func_80102B2C(spotlight, 2.0f);
        func_80102B6C(spotlight, 2.0f);
    }
}

void func_808007F4_chspotlight(u8 *param_0, f32 param_1)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (func_808008A4_chspotlight(param_0) == 0) {
        func_80101FDC(param_0, 4);
        *(f32 *) ((s8 *) param_0 + 0x50) = 0.0f;
        *(f32 *) ((s8 *) param_0 + 0x54) = (f32) *(f32 *) ((s8 *) local_0 + 0x1C);
        local_1 = *(s32 *) ((s8 *) local_0 + 0);
        *(s32 *) ((s8 *) local_0 + 0x24) = 0;
        *(f32 *) ((s8 *) local_0 + 0x20) = 0.0f;
        if (local_1 != 0) {
            func_800C8FE0(local_1, 0);
        }
    } else {
        func_80800580_chspotlight(param_0);
        func_80800730_chspotlight(param_0);
        func_80800600_chspotlight(param_0, param_1);
        func_808006B8_chspotlight(param_0);
    }
}

int func_808008A4_chspotlight(param_0)
Actor *param_0;
{
    s32 local_0;
    if (!param_0->unk3C) {
        return 0;
    }
    local_0 = func_800DA298(3);
    if (local_0 != 0) {
        return 0;
    }
    return 1;
}

s32 func_808008EC_chspotlight(Actor *this)
{
    Actor *local_0 = _subaddiefind_entrypoint_0(this->position, 0x13C, -1, 0);
    if (local_0) {
        this->unk3C = local_0->unk0;
    }
    return local_0;
}

int func_80800934_chspotlight(spotlight, msg, unk_0)
s32 spotlight;
s32 msg;
s32 unk_0;
{
    if (msg == 0x1F) {
        func_8080047C_chspotlight(spotlight);
        return 1;
    }
    return 0;
}

f32 D_80800990_chspotlight[2] = {8e+02f, 1.6e+03f};
s32 D_80800998_chspotlight[3] = {0x0, 0x0, 0x0};
s32 D_808009A4_chspotlight[3] = {0xC0, 0xC0, 0xC0};
int D_808009B0_chspotlight[20] = {0x2AF034D,
                                  0x7550001,
                                  0x0,
                                  (u32) func_80800210_chspotlight,
                                  (u32) func_80105834,
                                  (u32) func_80800518_chspotlight,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x21400,
                                  0x0,
                                  0x0,
                                  0x3C0000,
                                  (u32) func_8080000C_chspotlight,
                                  (u32) func_80107C2C,
                                  -0x7FFFFBFE,
                                  (u32) func_80800934_chspotlight,
                                  0x0,
                                  0x0,
                                  0x0};
