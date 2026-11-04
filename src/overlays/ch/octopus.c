// Possibly the Jolly Roger's Lagoon octopus: when hit it appears to fade its tint into the
// background, stay hidden for 8 s and fade back. Not fully understood.
#include "common.h"

extern int D_808008F4_choctopus[];
extern void _subaddieDll_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_5();
extern void func_80102424();
extern f32 D_808008D4_choctopus;
extern s32 D_8080093C_choctopus[];
extern void *func_80100094();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80101CDC(Actor *, f32);
extern s32 D_80800950_choctopus[][3];
extern s32 D_80800980_choctopus[];
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
extern u8 D_808008C0_choctopus[];
extern u8 D_8080098C_choctopus[];
extern int D_80800998_choctopus[];
extern void func_80102FDC(u8 *, f32);
extern s32 _subaddiesect_entrypoint_1();
extern void _choctopus_entrypoint_1(void);
typedef union {
    s32 value;
    void *ptr;
} OctopusEventPayload;
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80103F38(Actor *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s32 _subaddiecustomhits_entrypoint_3(Actor *, f32 *, f32);
extern s32 func_800B1F8C(void *, f32 *, f32 *, f32, s32, s32, f32 *, f32, s32, s32);

int choctopus_entrypoint_0()
{
    return (int) &D_808008F4_choctopus;
}

void func_8080000C_choctopus(u8 *actor)
{
    func_80102FDC(actor, *(f32 *) (actor + 0x38) * 0.8f);
    *(s32 *) (actor + 0x30) = _subaddiesect_entrypoint_1(actor);
}

// Update: hit -> fade out (1.25 s), hidden (8 s), fade back in (3.75 s).
void func_80800054_choctopus(Actor *actor)
{
    void *expression;
    f32 *pos;
    expression = func_80100094(actor, 1);
    _subaddiesect_entrypoint_0(actor, actor->actorData[6], 2);
    if (expression) {
        _suexpression_entrypoint_10(expression, actor->unk0, 0);
    }
    pos = actor->position;
    _subaddieaudioloop_entrypoint_5(actor, pos, actor->unk70_10 == 1, 0x1194,
                                    &D_8080093C_choctopus);
    switch ((int) actor->unk70_10) {
        case 1:
            break;
        case 2:
            func_80101CDC(actor,
                          func_800F10B4(actor->unk58, 0.0f, 1.25f, 30.0f, D_808008D4_choctopus));
            if (func_800D9078(&actor->unk58)) {
                func_80102424(actor, 3);
                actor->unk58 = 8.0f;
            }
            break;
        case 3:
            if (func_800D9078(&actor->unk58)) {
                _subaddieaudioquick_entrypoint_2(actor, pos, (s32 *) D_808008C0_choctopus);
                func_80102424(actor, 4);
                func_80101CDC(actor, 30.0f);
                actor->unk58 = 3.75f;
            }
            break;
        case 4:
            func_80101CDC(actor,
                          func_800F10B4(actor->unk58, 0.0f, 3.75f, D_808008D4_choctopus, 30.0f));
            if (func_800D9078(&actor->unk58)) {
                func_80102424(actor, 1);
                if (expression) {
                    _suexpression_entrypoint_18(expression, 0);
                }
                _subaddieDll_entrypoint_4(actor, 0);
            }
    }
}

s32 func_808007E4_choctopus();

void func_80800210_choctopus()
{
    func_808007E4_choctopus();
}

// Tints the model towards the background colour by the current fade amount.
void func_80800230_choctopus(Actor *actor, s32 unk_1)
{
    s32 fade;
    s32 color[3];
    func_801015D0(actor);
    switch (actor->unk70_10) {
        case 2:
            fade = (s32) func_800F10B4(actor->unk58, 0.0f, 1.25f, 255.0f, 0);
            break;
        case 3:
            fade = 255;
            break;
        case 4:
            fade = (s32) func_800F10B4(actor->unk58, 0.0f, 3.75f, 0, 255.0f);
            break;
        default:
            fade = 0;
            break;
    }
    func_800F3214(color, D_80800950_choctopus[actor->unk74_7 - 50], D_80800980_choctopus,
                  (f32) fade / 255.0f);
    func_800DF5D8(color[0], color[1], color[2], 255);
}

void func_80800790_choctopus();

void func_80800428_choctopus();

s32 func_80800348_choctopus(Actor *actor, s32 event, OctopusEventPayload payload)
{
    switch (event) {
        case 0x40:
            func_80800428_choctopus(actor, payload.value);
            break;
        case 0x1F:
            func_80800230_choctopus(actor, payload.value);
            break;
        case 0x29:
            func_80800790_choctopus(actor);
            break;
        case 0x2A:
            func_808007E4_choctopus(actor);
            break;
        case 0x1C:
            if (actor->unk70_10 == 1)
                return 2;
            return 1;
        case 0x95:
            _subaddiecustomhits_entrypoint_0(actor, _choctopus_entrypoint_1);
            break;
        default:
            return 0;
    }
    return 1;
}

// Hit handler: only variant 1 or collision mode 5 starts the camouflage.
void func_80800428_choctopus(Actor *actor, s32 unk_1)
{
    s32 is_variant_1;
    s32 is_mode_5;
    u8 *expression;
    is_variant_1 = (*(s32 *) ((char *) actor + 0x6C) & 0x1FF) == 1;
    is_mode_5 = func_800CB854(0) == 5;
    if ((is_variant_1 != 0) || (is_mode_5 != 0)) {
        expression = func_80100094(actor, 1);
        switch ((u32) *(u16 *) ((char *) actor + 0x72) >> 0xA) {
            case 1:
                func_80102424(actor, 2, expression);
                _subaddieDll_entrypoint_4(actor, 1);
                *(f32 *) ((char *) actor + 0x58) = 1.25f;
                if (expression != 0) {
                    _suexpression_entrypoint_18(expression, 2);
                }
                _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4,
                                                 &D_808008C0_choctopus);
                if (is_mode_5 == 0) {
                    _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4,
                                                     &D_8080098C_choctopus);
                }
                break;

            case 3:
                *(f32 *) ((char *) actor + 0x58) = 8.0f;
        }
    }
}

s32 func_80800540_choctopus(Unk80132ED0 *hit, f32 *hit_pos, f32 radius, s32 unk_3,
                            s32 hit_flags)
{
    Actor *actor;
    s32 unk_0;
    f32 abs_angle;
    f32 box_a[3];
    s32 result;
    f32 box_b[3];
    s32 unk_9;
    f32 value;
    f32 *actor_pos;
    void *unk_4;
    actor = func_80106790(hit);
    if (_subaddiecustomhits_entrypoint_3(actor, hit_pos, radius))
        return 0;
    switch (func_800CB854(&unk_0)) {
        case 2:
            value = func_80103F38(actor, box_a) * 0.8f;
            return func_800EFFB4(box_a, radius + value, hit_pos);
        case 5:
            value = func_80103F38(actor, box_b) * 0.8f;
            result = func_800EFFB4(box_b, radius + value, hit_pos);
            break;
        default:
            unk_4 = (void *) func_80103D98(hit);
            if (!unk_4)
                return 0;
            actor_pos = actor->position;
            value = func_800F1DCC(actor->rotation[1], func_800F1DF4(actor_pos, hit_pos));
            abs_angle = mlAbsF(value);
            hit_flags = 0;
            if (abs_angle < 90.0f)
                hit_flags = 8;
            if (abs_angle > 35.0f)
                hit_flags |= 2;
            if (value < 35.0f)
                hit_flags |= 0x10;
            if (value > -35.0f)
                hit_flags |= 4;
            if (func_800EFC7C(actor_pos, hit_pos) > SQ(actor->scale * 800.0f))
                hit_flags |= 0x201;
            result = func_800B1F8C(unk_4, actor_pos, actor->rotation, actor->scale, 0,
                                    func_801040A8(actor), hit_pos, radius, unk_3, hit_flags);
    }
    if (result)
        actor->unk6C_0 = result;
    return result;
}

int choctopus_entrypoint_1()
{
    return (int) &D_80800998_choctopus;
}

void func_80800790_choctopus(Actor *actor)
{
    if (!func_80100094(actor, 1)) {
        _suexpression_entrypoint_7(actor, 1, 0xB6);
        _suexpression_entrypoint_12(func_80100094(actor, 1), 0x42A00000, 0x41F00000);
    }
}

s32 func_808007E4_choctopus(s32 actor)
{
    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_808008C0_choctopus[12] = {0x0, 0x13, 0x5, 0x2B, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u32 D_808008CC_choctopus[2] = {0x0, 0x0};
f32 D_808008D4_choctopus = 1.0f;
static u32 D_808008D4_choctopus_rest[7] = {0x1720001, 0x3F800000, 0x1720001, 0x3F800000,
                                           0x1720020, 0x3F800000, 0x1720001};
int D_808008F4_choctopus[18] = {0x2F1035E,
                                0x6D00001,
                                (u32) &D_808008CC_choctopus,
                                (u32) func_80800054_choctopus,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x157C,
                                0x0,
                                0x0,
                                0x528,
                                (u32) func_80800210_choctopus,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_8080000C_choctopus,
                                (u32) func_80107C2C,
                                -0x7FCFDBFE,
                                (u32) func_80800348_choctopus,
                                0x0};
s32 D_8080093C_choctopus[5] = {0x13062C, 0xA0066, 0x167530, 0x105DC, 0x11940000};
s32 D_80800950_choctopus[4][3] = {0x34, 0x83, 0x42, 0x3B, 0xB2, 0x9E,
                                  0x4C, 0x7D, 0x96, 0x71, 0x75, 0x7A};
s32 D_80800980_choctopus[3] = {0x20, 0x80, 0xFF};
u8 D_8080098C_choctopus[12] = {0x0, 0x13, 0x4, 0xA4, 0x0, 0x2, 0x0, 0xA, 0x0, 0xCC, 0x0, 0x0};
int D_80800998_choctopus[6] = {0x0, 0x0, 0x0, (u32) func_80800540_choctopus, 0x0, 0x0};
