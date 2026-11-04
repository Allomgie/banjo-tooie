// Probably Weldar's fireball: flies straight to its target with a point light, explodes into
// particles on impact, and is drawn as a spinning sprite.
#include "common.h"

extern void *D_80800410_chweldarbossfireball;
extern u8 D_80800458_chweldarbossfireball[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
extern void func_800C8E54(s32, f32, f32);
extern u32 D_80800468_chweldarbossfireball[];
extern u32 D_80800474_chweldarbossfireball[];
extern f32 func_800D8FF8(void);
extern void *func_801040D0(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800D93A0(f32 *, f32 *);
typedef union {
    s32 word;
    Unk80132ED0 *marker;
} WeldarFireballEventPayload;
extern Actor *func_80106790();
extern u8 D_80800480_chweldarbossfireball[];
extern u8 D_808004C4_chweldarbossfireball[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
void func_808002E0_chweldarbossfireball();
s32 func_80800404_chweldarbossfireball();

void *chweldarbossfireball_entrypoint_0()
{
    return &D_80800410_chweldarbossfireball;
}

// Init: sets direction and speed (1800 u/s) and creates the point light.
void func_8080000C_chweldarbossfireball(Actor *fireball)
{
    f32 angles[2];

    fireball->actorData[7] = 0;
    fireball->unk50 = func_800DC178(0.0f, 360.0f);
    _subaddieaudioquick_entrypoint_2(fireball, fireball->position, D_80800458_chweldarbossfireball);
    func_800EFB24((f32 *) &fireball->actorData[4], (f32 *) &fireball->actorData[0],
                  fireball->position);
    func_800F18FC(fireball->position, (f32 *) &fireball->actorData[0], angles);
    fireball->rotation[0] = -angles[0];
    fireball->rotation[1] = angles[1];
    func_800EF368((f32 *) &fireball->actorData[4], 1800.0f);
    fireball->actorData[7] = func_800C8A98();
    func_800C8E54(fireball->actorData[7], 500.0f, 800.0f);
}

void func_808000C4_chweldarbossfireball(Actor *fireball)
{
    fireball->unk50 += func_800D8FF8() * 500.0f;
    if (fireball->unk70_10 == 1) {
        if (func_8010B990(fireball, 0x400007) & 0x20) {
            func_808002E0_chweldarbossfireball(fireball);
        }
        func_80800404_chweldarbossfireball(fireball);
    }
    if (fireball->actorData[7]) {
        func_800C8CB8(fireball->actorData[7], fireball->position);
        func_800C8E84(fireball->actorData[7], func_8001210C(1) ? D_80800474_chweldarbossfireball
                                                              : D_80800468_chweldarbossfireball);
    }
}

int func_8080017C_chweldarbossfireball(Actor *fireball)
{
    s32 light;
    s32 *light_slot = (s32 *) ((char *) fireball + ((((0x34 & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu));
    light = *light_slot;
    if (light != 0) {
        func_800C8B84(light);
        *light_slot = 0;
    }
}

int func_808001B4_chweldarbossfireball(Actor *fireball, s32 arg)
{
    s32 *unk_0;
    unk_0 = (s32 *) ((char *) fireball + 0x38);
    func_80101970(fireball);
    func_800DF830(2);
    func_800DE448((s32 *) ((char *) fireball + 0x4), (s32 *) ((char *) fireball + 0x44), *unk_0, 0,
                  func_800D674C(0x89D));
    func_801018A4(fireball, arg);
}

void func_80800214_chweldarbossfireball(Actor *fireball, void *payload)
{
    void *model;
    f32 euler[3];
    f32 quat[4];
    model = func_801040D0(fireball);
    func_801015D0(fireball);
    func_800DF41C(model);
    func_800EFA4C(euler, fireball->unk50, 0.0f, 0.0f);
    func_800D93A0(quat, euler);
    func_800DFF2C(model, 0x2A, quat);
}

s32 func_80800284_chweldarbossfireball(Actor *fireball, s32 msg,
                                       WeldarFireballEventPayload payload)
{
    switch (msg) {
        case 64:
            func_808002E0_chweldarbossfireball(fireball);
            break;
        case 31:
            func_80800214_chweldarbossfireball(fireball, payload.word);
            break;
        default:
            return 0;
    }
    return 1;
}

// TU-NOTE: .bss is defined here, ahead of its first use: IDO places .bss objects used before
// their definition first, the rest in definition order.
u8 B_808004E0_chweldarbossfireball[16];

// Explodes into particles, fades the light out and deletes the fireball.
void func_808002E0_chweldarbossfireball(fireball) Actor *fireball;
{
    f32 pos[3];
    f32 particle_pos[3];
    f32 *target_pos;
    Actor *target;
    f32 light_pos[3];
    target = func_80106790(fireball->unk3C);
    func_80103DFC(fireball, pos);
    func_800EE7F8(particle_pos, pos);
    if (target) {
        target_pos = target->position;
    } else {
        target_pos = (f32 *) B_808004E0_chweldarbossfireball;
    }
    func_800EF1B8(particle_pos, func_800F1DF4(fireball->position, target_pos), 60.0f);
    particle_pos[1] -= 40.0f;
    func_800BBCB8(pos, particle_pos, 1.0f, 10, D_80800480_chweldarbossfireball);
    _subaddieaudioquick_entrypoint_2(fireball, fireball->position, D_808004C4_chweldarbossfireball);
    if (fireball->actorData[7]) {
        func_800EE7F8(light_pos, fireball->position);
        light_pos[1] += 100.0f;
        func_800C8CB8(fireball->actorData[7], light_pos);
        fireball->actorData[7] = _chlightfader_entrypoint_1(fireball->actorData[7], 1.4f, 1);
    }
    func_8010A570(fireball);
    func_800FFAB0(fireball);
}

s32 func_80800404_chweldarbossfireball(param_0)
s32 param_0;
{
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and the
// assembler schedules them differently otherwise. Values are taken from the ROM.
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_80800410_chweldarbossfireball = (void *) 0x03000124;
static u32 D_80800410_chweldarbossfireball_rest[17] = {0x89C0001,
                                                       0x0,
                                                       (u32) func_808000C4_chweldarbossfireball,
                                                       (u32) func_80105834,
                                                       (u32) func_808001B4_chweldarbossfireball,
                                                       0x0,
                                                       0x0,
                                                       0x0,
                                                       0x1004,
                                                       (u32) func_8080017C_chweldarbossfireball,
                                                       (u32) func_80108ED0,
                                                       0x0,
                                                       (u32) func_8080000C_chweldarbossfireball,
                                                       (u32) func_80107C2C,
                                                       0x0,
                                                       (u32) func_80800284_chweldarbossfireball,
                                                       0x0};
u8 D_80800458_chweldarbossfireball[16] = {0x0, 0x13, 0x6, 0x1,  0x0, 0x18, 0x0, 0x2,
                                          0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,  0x0, 0x0};
u32 D_80800468_chweldarbossfireball[3] = {0x0, 0xE0, 0xFF};
u32 D_80800474_chweldarbossfireball[3] = {0xFF, 0xFF, 0xFF};
u8 D_80800480_chweldarbossfireball[68] = {
    0x0, 0x1D, 0x9, 0xE5, 0x0,  0x16, 0x5,  0x86, 0x0, 0x2B, 0x1, 0x33, 0x1, 0x99,
    0x0, 0x27, 0x0, 0xC8, 0x0,  0xC8, 0x1,  0x90, 0x1, 0x90, 0x0, 0x2D, 0x1, 0xF4,
    0x2, 0x58, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x22, 0x1, 0x0,  0x1, 0x33,
    0x0, 0x80, 0x0, 0x99, 0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0, 0xE,  0x0, 0x1E,
    0x0, 0x32, 0x0, 0x4,  0x0,  0xCC, 0x0,  0x7,  0x0, 0x3,  0x0, 0x0};
u8 D_808004C4_chweldarbossfireball[28] = {0x0, 0x13, 0x4, 0x13, 0x0, 0x16, 0x61, 0xA8, 0x0, 0x2,
                                          0x0, 0xD,  0x1, 0x26, 0x1, 0x40, 0x0,  0x0,  0x0, 0x0,
                                          0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0};
