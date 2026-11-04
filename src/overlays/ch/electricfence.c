#include "common.h"

extern int D_808004C0_chelectricfence[];
extern void func_800BBCB8(s32, s32, float, s32, void *);
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern s32 func_800C8A98(void);
extern void func_800C8CB8(s32, s32);
extern void func_800C8E84(s32, void *);
extern void func_800C8E54(s32, s32, s32);
extern void _chlightfader_entrypoint_1(s32, s32, int);
extern void *D_80800558_chelectricfence;
extern void *D_8080051C_chelectricfence;
extern void *D_8080058C_chelectricfence;
extern void *D_80800598_chelectricfence;
extern u8 D_808005A4_chelectricfence[];
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800BABB8(s32, void *, s32, f32, void *);
extern void func_800BA8F8(s32, f32, f32);
extern u8 D_80800508_chelectricfence[];
extern f32 func_800EC75C(void *, f32 *);

int *chelectricfence_entrypoint_0()
{
    return &D_808004C0_chelectricfence;
}

// Switches the fence off at the Saucer of Peril map (0x124).
int func_8080000C_chelectricfence(s32 actor)
{
    if (func_800EA05C() == 0x124) {
        func_8010A624(actor);
        func_8010A570(actor);
    }
    func_80104004(actor, actor + 0x18, actor + 0x28);
}

void chelectricfence_entrypoint_2();

void func_80800060_chelectricfence(Actor *actor)
{
    if (func_800D9078(&actor->unk58))
        func_8010A590(actor);
    _subaddieaudioloop_entrypoint_5(actor, actor->position, actor->unk70_10 == 1, -1,
                                    D_80800508_chelectricfence);
    if (actor->unk70_10 == 1 && actor->unk7C_12 && func_800DC298(0.2f)) {
        chelectricfence_entrypoint_2(actor, (f32 *) &actor->actorData[0],
                                     (f32 *) &actor->actorData[4]);
    }
}

void chelectricfence_entrypoint_1();

s32 func_8080010C_chelectricfence(Actor *actor, s32 message, u32 *data)
{
    f32 hit_pos[3];
    u32 *hit;

    switch (message) {
        case 0x3F:
            hit = *(u32 **) &data;
            func_800EC75C(hit, hit_pos);
            chelectricfence_entrypoint_1((s32) actor, (s32) hit_pos);
            actor->unk58 = 0.2f;
            func_8010A570(actor);
            if (hit[0x24 / 4] >> 22 == 0) {
            }
            break;
        case 0x95:
            func_8010A5B0(actor, func_800F6438(func_800F54E4()) &&
                                       !func_800F64A4(func_800F54E4(), 0x8000));
            break;
        default:
            return 0;
    }
    return 1;
}

// Shared electric zap effect: spark bursts, sound and a fading light.
void chelectricfence_entrypoint_1(s32 actor, s32 pos)
{
    s32 light;
    s32 light_id;

    func_800BBCB8(pos, pos, 1.0f, 3, &D_80800558_chelectricfence);
    func_800BBCB8(pos, pos, 1.0f, 12, &D_8080051C_chelectricfence);
    _subaddieaudioquick_entrypoint_2(actor, pos, &D_8080058C_chelectricfence);
    light_id = func_800C8A98();
    light = light_id;
    func_800C8CB8(light_id, pos);
    func_800C8E84(light, &D_80800598_chelectricfence);
    func_800C8E54(light, 0x43960000, 0x44160000);
    _chlightfader_entrypoint_1(light, 0x3F4CCCCD, 5);
}

// Spark arc between two random points on the fence bounding box.
void chelectricfence_entrypoint_2(Actor *actor, f32 *box_min, f32 *box_max)
{
    f32 from[3];
    f32 to[3];
    f32 dir[3];
    f32 z;
    s32 emitter;
    f32 scale;

    z = func_800DC298(0.5f) ? box_min[2] : box_max[2];
    func_800EFA4C(from, func_800DC178(box_min[0], box_max[0]),
                  func_800DC178(box_min[1], box_max[1]), z);
    func_800EFA4C(to, func_800DC178(box_min[0], box_max[0]),
                  func_800DC178(box_min[1], box_max[1]), z);
    func_800EF934(from, from, actor->rotation[1]);
    func_800EF04C(from, actor->position);
    func_800EF934(to, to, actor->rotation[1]);
    func_800EF04C(to, actor->position);
    func_800EFB24(dir, to, from);
    func_800EF368(dir, 400.0f);
    scale = func_800EEAD4(to, from) / 500.0f;
    emitter = func_800B5BE4(0x12);
    func_800BABB8(emitter, from, 0, 1.8f, D_808005A4_chelectricfence);
    func_800BA930(emitter, (s16) dir[0], (s16) dir[1], (s16) dir[2], (s16) dir[0],
                  (s16) dir[1], (s16) dir[2]);
    func_800BA8F8(emitter, scale, scale);
    func_800BA22C(emitter, 1);
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and
// IDO's assembler schedules them differently otherwise. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808004C0_chelectricfence[18] = {0x33103D3,
                                      0x79D0001,
                                      0x0,
                                      (u32) func_80800060_chelectricfence,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x17700000,
                                      0x0,
                                      0x0,
                                      0xC00,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_8080000C_chelectricfence,
                                      (u32) func_80107C2C,
                                      -0x7FFFE000,
                                      (u32) func_8080010C_chelectricfence,
                                      0x0};
u8 D_80800508_chelectricfence[20] = {0x0, 0x13, 0x5, 0xB7, 0x0,  0xE,  0x0, 0xF3, 0x1, 0xC,
                                     0x0, 0x19, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0,  0x0, 0x0};
void *D_8080051C_chelectricfence = (void *) 0x001D09CD;
static u32 D_8080051C_chelectricfence_rest[14] = {
    0x1BFC18,  0xFCE0002D, 0x12C0190, 0xE0014,  0x140016, 0x11000018, 0x1,
    0xA000F00, 0x220040,   0x590019,  0x330015, 0xCC,     0x2B0119,   0x14C0000};
void *D_80800558_chelectricfence = (void *) 0x001D09DD;
static u32 D_80800558_chelectricfence_rest[12] = {0x2D000A,   0x1E000E, 0x140014,  0x20C0C0,
                                                  0xC0C00016, 0x80022,  0xCC0100,  0x1330166,
                                                  0x150000,   0x99002B, 0x119014C, 0x0};
void *D_8080058C_chelectricfence = (void *) 0x001304B0;
static u32 D_8080058C_chelectricfence_rest[2] = {0xA014C, 0x180000};
void *D_80800598_chelectricfence = (void *) 0x000000E0;
static u32 D_80800598_chelectricfence_rest[2] = {0xE0, 0xFF};
u8 D_808005A4_chelectricfence[60] = {
    0x0, 0x34, 0x0, 0x1D, 0x9, 0xCD, 0x0,  0x16, 0x12, 0x0, 0x0,  0x18, 0x0,  0x0, 0x0,
    0x4, 0x1E, 0x0, 0x23, 0x0, 0x0,  0x22, 0x0,  0x40, 0x0, 0x59, 0x0,  0x19, 0x0, 0x33,
    0x0, 0x15, 0x0, 0x19, 0x0, 0xE6, 0x0,  0x1,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,
    0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0};
