// Probably the Hailfire Peaks lava hand: rises from the lava near the player, swipes left or right,
// burns with flame models and sinks or dies when hit by an egg. Also holds the attached flame child.
#include "common.h"

typedef struct LavaHandContactState {
    u8 pad_0[0x7A];
    u8 local_0 : 2;
    u8 pad_1 : 6;
} LavaHandContactState;
extern f32 func_800F1F0C(f32 *, f32 *, f32);
extern void func_800C8E54(s32, f32, f32);
extern s32 D_808013A0_chlavahand[];
extern s32 D_80801330_chlavahand[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_80101870(Actor *, void *);
extern Actor *func_80106790(Unk80132ED0 *);
extern int D_808013D0_chlavahand[];
typedef struct {
    u8 pad[0x7A];
    u16 top : 2;
    u16 rest : 14;
} LavaHandTop;
extern void func_800DF830();
extern void func_800DE498(f32 *, f32 *, s32, f32, s32, f32 *);
extern void func_800DF410();
extern void *D_80801418_chlavahand;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} LavaHandFlags;
extern f32 func_80101F24(Actor *);
extern void func_800C4140(s32, f32 *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern s32 func_800EEB9C(f32 *, f32, f32);
typedef union {
    u32 local_0;
    s16 local_1[2];
} Mass64LavaHandEvent;
typedef struct {
    u32 pad78_3 : 29;
    u32 unk78_2 : 1;
    u32 pad78_0 : 2;
} ActorFlags78;
extern void func_800FFA88(Unk80132ED0 *);
void func_80800FB4_chlavahand();
void func_808011BC_chlavahand(s32 skeleton, f32 position[3], f32 rotation[3], s32 bone_index,
                              f32 scale, s32 alpha, s32 unk_6);

// Lava hand (Hailfire Peaks): rises from the lava near the player, swipes, burns, sinks when hit by an egg.
void func_80800000_chlavahand(Actor *actor)
{
    actor->unk64_24 = 1;
    actor->unk64_16 = 0;
    actor->unk54 = actor->scale;
}

void func_80800024_chlavahand(Actor *actor)
{
    f32 player_pos[3];
    f32 side;

    ((LavaHandContactState *) actor)->local_0 = 1;
    func_800F5A00(func_800F54E4(), player_pos);
    side = func_800F1F0C(actor->position, player_pos, actor->rotation[1]);
    if (side >= -90.0f && side <= 0.0f) {
        func_80103140(actor, 0x925, actor->unk0->unk16);
        func_80102424(actor, 2);
    } else if (side <= 90.0f && side > 0.0f) {
        func_80103140(actor, 0x92C, actor->unk0->unk16);
        func_80102424(actor, 3);
    }
    func_8010A590(actor);
}

void func_80800A30_chlavahand();

void func_80800910_chlavahand();

void func_80800124_chlavahand(Actor *actor)
{
    extern u8 D_80801324_chlavahand[];

    f32 anim_progress;
    s32 distance;
    f32 progress;
    s32 state;
    f32 fade;
    f32 factor;
    s32 next_state;

    switch (actor->unk70_10) {
        case 1:
            if (((LavaHandFlags *) actor)->local_0) {
                if (_subaddiejoy_entrypoint_6(actor, 1)) {
                    func_80800024_chlavahand(actor);
                }
            } else if (func_800D90A4((char *) actor + 0x58)) {
                if (func_8010C9FC((char *) actor + 4, (s32) ((f32) actor->unk74_7 * 10.0f), 200,
                                  -200)) {
                    func_80800024_chlavahand(actor);
                }
            }

            *(f32 *) ((char *) actor + 0x38) = 0.1f;
            break;

        case 2:
        case 3:
            anim_progress = func_80101F24(actor);
            distance = func_8010C754(actor);

            if (anim_progress <= 0.09f) {
                *(f32 *) ((char *) actor + 0x38) =
                    func_800F10B4(anim_progress, 0.0f, 0.09f, 0.1f, *(f32 *) ((char *) actor + 0x54));
            } else if (anim_progress >= 0.80f) {
                *(f32 *) ((char *) actor + 0x38) =
                    func_800F10B4(anim_progress, 0.80f, 1.0f, *(f32 *) ((char *) actor + 0x54), 0.1f);
            } else {
                *(f32 *) ((char *) actor + 0x38) = *(f32 *) ((char *) actor + 0x54);
            }

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, distance < 1000,
                                            D_80801324_chlavahand);

            factor = func_800F10B4((f32) distance, 1000.0f, 0.0f, 0.8f, 1.2f);

            _subaddieaudioloop_entrypoint_0(actor, factor);

            factor = func_80013970(func_80101F24(actor) * 180.0f);

            _subaddieaudioloop_entrypoint_1(actor, (s32) (factor * 16000.0f));

            if (func_80101E14(actor, 0.2f)) {
                func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x1B5E01,
                              (char *) actor + 4, 0x04B000FA);
            } else if (func_80101E14(actor, 0.52f)) {
                func_800C4140(((u16) (u32) (func_800DC178(1.15f, 1.25f) * 1023.0f) << 21) +
                                  0x1B5E01,
                              (char *) actor + 4, 0x04B000FA);
            } else if (func_80101DDC(actor)) {
                if (((LavaHandFlags *) actor)->local_0) {
                    *(f32 *) ((char *) actor + 0x58) = 1.0f;
                } else {
                    *(f32 *) ((char *) actor + 0x58) = 2.0f;
                }

                func_80102424(actor, 1);
                _subaddieaudioloop_entrypoint_2(actor);
            }

            *(f32 *) ((char *) actor + 0x2C) = *(f32 *) ((char *) actor + 0x38) * 150.0f;

            *(f32 *) ((char *) actor + 0x30) = *(f32 *) ((char *) actor + 0x38) * 300.0f;
            break;

        case 4:
        case 5:
            progress = func_80101F24(actor);

            if (func_800DC0C0() < 0.1f) {
                func_80800A30_chlavahand(actor);
            }

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                            D_80801324_chlavahand);

            factor = func_800F1214(progress, 0.8f, 1.2f);

            _subaddieaudioloop_entrypoint_0(actor, factor);

            _subaddieaudioloop_entrypoint_1(actor, (s32) (progress * 16000.0f));

            *(f32 *) ((char *) actor + 0x38) = func_800F15F8(
                *(f32 *) ((char *) actor + 0x38), *(f32 *) ((char *) actor + 0x54), 0.1f);

            if (func_80101E14(actor, 0.02f)) {
                func_800C4140(((u16) (u32) (func_800DC178(1.4f, 1.5f) * 1023.0f) << 21) + 0x1D4E05,
                              (char *) actor + 4, 0x04B000FA);
            } else if (func_80101E14(actor, 0.7f)) {
                func_800C4140(0x665F4601, (char *) actor + 4, 0x04B000FA);
            }

            if (func_80101DDC(actor)) {
                state = actor->unk70_10;

                func_8010A800(actor, 2);
                func_80107070(actor, 2);

                if (state == 4) {
                    next_state = 6;
                } else {
                    next_state = 7;
                }

                func_80102424(actor, next_state);
                break;
            }

            factor = 1.0f + progress;

            *(f32 *) ((char *) actor + 0x2C) =
                *(f32 *) ((char *) actor + 0x54) * 150.0f * factor;

            *(f32 *) ((char *) actor + 0x30) =
                *(f32 *) ((char *) actor + 0x54) * 300.0f * factor;
            break;

        case 6:
        case 7:
            fade = (f32) *(u8 *) ((char *) actor + 0x9B) / 255.0f;

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                            D_80801324_chlavahand);

            factor = func_800F1214(fade, 0.8f, 1.2f);

            _subaddieaudioloop_entrypoint_0(actor, factor);

            _subaddieaudioloop_entrypoint_1(actor, (s32) (fade * 16000.0f));

            if (func_800DC0C0() < fade) {
                func_80800A30_chlavahand(actor);
            }

            *(f32 *) ((char *) actor + 0x2C) =
                (*(f32 *) ((char *) actor + 0x54) * 150.0f * 2.0f) * fade;

            *(f32 *) ((char *) actor + 0x30) =
                (*(f32 *) ((char *) actor + 0x54) * 300.0f * 2.0f) * fade;
            break;

        case 8:
            if (*(u8 *) ((char *) actor + 0x5F) != 0) {
                _subaddieaudioloop_entrypoint_2(actor);
            }

        case 9:
            break;
    }

    func_80800910_chlavahand(actor);
}

void func_80800910_chlavahand(Actor *actor)
{
    f32 light_pos[3];
    s32 light;
    actor->unk64_16 = (s32) actor->unk70_10 >= 2 && (s32) actor->unk70_10 <= 7;
    light = actor->actorData[4];
    if (light && !(*(u16 *) ((u8 *) actor + 0x64) & 1)) {
        func_800C8B84(light);
        actor->actorData[4] = 0;
        light = 0;
    } else if (!light && (*(u16 *) ((u8 *) actor + 0x64) & 1)) {
        actor->actorData[4] = func_800C8A98();
        func_800C8CB8(actor->actorData[4], actor->position);
        func_800C8FB0(actor->actorData[4], 0xFF, 0xE1, 0xF);
        func_800C8F64(actor->actorData[4], 1);
        func_800C8E54(actor->actorData[4], *(f32 *) ((u8 *) actor + 0x2C),
                      *(f32 *) ((u8 *) actor + 0x30));
        func_800C8FE0(actor->actorData[4], 1);
        light = actor->actorData[4];
    }
    if (light) {
        _subaddieskeleton_entrypoint_0(actor, 0x2D, light_pos);
        func_800C8CB8(actor->actorData[4], light_pos);
        func_800C8E54(actor->actorData[4], *(f32 *) ((u8 *) actor + 0x2C),
                      *(f32 *) ((u8 *) actor + 0x30));
    }
}

void func_80800A30_chlavahand(Actor *actor)
{
    f32 pos[3];
    if (actor->unk7C_12 && _subaddieskeleton_entrypoint_0(
                                 actor, D_808013A0_chlavahand[func_800DC128(0, 0xD)], pos)) {
        func_800BABB8(0, pos, NULL, actor->scale, D_80801330_chlavahand);
    }
}

s32 func_80800AAC_chlavahand(Actor *actor, s32 event, Mass64LavaHandEvent event_data)
{
    Actor *child;
    f32 offset[3];
    f32 height;

    switch (event) {
        case 0x3D:
            child = func_80108528(0x400, actor->position, 0, &actor);
            func_80103140(child, 0x927, 0);
            child->unk3C = actor->unk0;
            actor->unk3C = child->unk0;
            *(u32 *) &child->unk50 = (u32) ((u16 *) actor->unk0)[9] >> 1;
            child = func_80108528(0x400, actor->position, 0, &actor);
            func_80103140(child, 0x926, 0);
            child->unk3C = actor->unk0;
            *(u32 *) &child->unk50 = (u32) ((u16 *) actor->unk0)[9] >> 1;
            *(u16 *) ((u8 *) child + 0x7C) = *(u16 *) ((u8 *) actor + 0x7C);
            return 1;
        case 0x40:
            if ((s32) actor->unk70_10 == 2) {
                func_80102424(actor, 4);
            } else if ((s32) actor->unk70_10 == 3) {
                func_80102424(actor, 5);
            }
            *((u8 *) actor + 0x7A) = (*((u8 *) actor + 0x7A) & ~0xC0) | 0x80;
            func_8010A570(actor);
            return 1;
        case 1:
            func_80102424(actor, 1);
            return 1;
        case 2:
            actor->unk58 = 2.0f;
            func_80102424(actor, 1);
            return 1;
        case 0x95:
            func_80108B04(actor, 0);
            *(u16 *) ((u8 *) actor + 0x7C) = (u32) ((actor->unk74_7 * 10.0f) * 1.2f);
            return 1;
        case 0x97:
            height = (1.0f / actor->scale) * 200.0f;
            func_800EEB9C(offset, actor->rotation[1], height);
            offset[1] += height;
            func_80101010(offset);
            return 1;
        default:
            return 0;
    }
}

void func_80800D8C_chlavahand(Actor *actor, s32 position)
{
    s32 state;

    func_80101870(actor, (void *) position);
    if (actor->unk3C && actor->unk7C_12) {
        state = actor->unk70_10;
        if (state >= 2 && state < 8) {
            func_80800FB4_chlavahand(func_80106790(actor->unk3C), position);
        }
    }
}

int chlavahand_entrypoint_0()
{
    return (int) &D_808013D0_chlavahand;
}

// Flame child: scales and fades with its parent hand.
void func_80800E0C_chlavahand(Actor *this)
{
    Actor *parent;
    f32 t;

    if (((u32) *(u16 *) ((u8 *) this->unk3C + 0x12) >> 1) == *(s32 *) &this->unk50) {
        parent = func_80106790(this->unk3C);
        if (!((ActorFlags78 *) &parent->unk78)->unk78_2 && 0.2f < parent->scale) {
            switch (parent->unk70_10) {
                case 2:
                case 3:
                    this->scale =
                        func_80013970(func_80101F24(this) * 180.0f) * parent->scale + parent->scale;
                    this->alpha = 0xFF;
                    break;
                case 4:
                case 5:
                    t = func_80101F24(parent);
                    if (t < 0.99f) {
                        this->scale = func_800F10B4(t, 0.0f, 1.0f, 1.0f, 2.0f) * parent->scale;
                    }
                    this->alpha = 0xFF;
                    break;
                case 6:
                case 7:
                    this->scale = func_800F10B4((u32) parent->alpha, 255.0f, 0.0f, 2.0f, 0.0f) *
                                  parent->scale;
                    this->alpha = parent->alpha;
                    break;
                default:
                    return;
            }
            this->unk64_16 = 1;
        }
    } else {
        func_800FFA88(this->unk0);
    }
}

void func_80800FB4_chlavahand(actor, position) Actor *actor;
s32 position;
{
    s32 rotation;
    s32 skeleton;

    rotation = func_800D674C(actor->unk0->unk14);
    skeleton = func_80106790(*(s32 *) ((u8 *) actor + 0x3C));
    func_801015D0(actor);
    if (actor->unk0->unk14 == 0x927) {
        func_808011BC_chlavahand(skeleton, position, rotation, 0x2A, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
        func_808011BC_chlavahand(skeleton, position, rotation, 0x2C, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
        func_808011BC_chlavahand(skeleton, position, rotation, 0x2D, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
        func_808011BC_chlavahand(skeleton, position, rotation, 0x2F, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
        func_808011BC_chlavahand(skeleton, position, rotation, 0x30, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
        func_808011BC_chlavahand(skeleton, position, rotation, 0x32, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
    } else {
        func_808011BC_chlavahand(skeleton, position, rotation, 0x33, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
        func_808011BC_chlavahand(skeleton, position, rotation, 0x35, actor->scale,
                                 *(u8 *) ((u8 *) actor + 0x9B), ((LavaHandTop *) actor)->top);
    }
    actor->unk7C_12 = 1;
}

void func_808011BC_chlavahand(s32 skeleton, f32 position[3], f32 rotation[3], s32 bone_index,
                              f32 scale, s32 alpha, s32 unk_6)
{
    f32 bone_pos[3];

    _subaddieskeleton_entrypoint_0(skeleton, bone_index, bone_pos);
    func_800DF410(alpha);
    func_800DF830(0x2);
    func_800DE498(position, bone_pos, 0, scale, 0, rotation);
}

int chlavahand_entrypoint_1()
{
    return &D_80801418_chlavahand;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_8010A730();
u32 D_808012C0_chlavahand[20] = {0x0,        0x0,        0x400CCCCD, 0x4230044,  0x400CCCCD,
                                 0x4230042,  0x400CCCCD, 0x4B40042,  0x3F99999A, 0x4240042,
                                 0x3F99999A, 0x4B50042,  0x3F99999A, 0x4240084,  0x3F99999A,
                                 0x4B50084,  0x3F99999A, 0x4240084,  0x400CCCCD, 0x4230044};
u32 D_80801310_chlavahand[5] = {0x10000, 0x60000, 0x60003, 0x80000, 0x90000};
u8 D_80801324_chlavahand[12] = {0x0, 0x13, 0x4, 0x83, 0x0, 0xA, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0};
s32 D_80801330_chlavahand[28] = {
    0x110001D,  0x9DC0018, 0x13,      0x6000A00, 0x1B01C2, 0x2580020,  -0x6991A538,
    0x220033,   0x330200,  0x3000015, 0x660073,  0x2A0100, 0x1000200,  0x2800016,
    0x1010011A, 0x110001D, 0x927001B, 0x1C20258, 0x20966E, 0x5AFF0022, 0x1000200,
    0x0,        0x150019,  0x19002B,  0x1000180, 0x70001,  0x161010,   0x11A0000};
s32 D_808013A0_chlavahand[12] = {0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
                                 0x30, 0x31, 0x32, 0x33, 0x34, 0x35};
int D_808013D0_chlavahand[18] = {0x10903E9,
                                 0x9250001,
                                 (u32) &D_808012C0_chlavahand,
                                 (u32) func_80800124_chlavahand,
                                 (u32) func_80105834,
                                 (u32) func_80800D8C_chlavahand,
                                 0x5DC0000,
                                 0x0,
                                 0x0,
                                 0x20068,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chlavahand,
                                 (u32) func_80107C2C,
                                 -0x7FDFFBFF,
                                 (u32) func_80800AAC_chlavahand,
                                 (u32) &D_80801310_chlavahand};
void *D_80801418_chlavahand = (void *) 0x01580400;
static u32 D_80801418_chlavahand_rest[17] = {0x9270001,
                                             0x0,
                                             (u32) func_80800E0C_chlavahand,
                                             (u32) func_80105834,
                                             (u32) func_8010A730,
                                             0x5DC0000,
                                             0x0,
                                             0x0,
                                             0x21004,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             0x0,
                                             (u32) func_80107C2C,
                                             0x80000002,
                                             0x0,
                                             0x0};
