// Probably the fire-spitting gargoyle of Hailfire Peaks Lava Side: turns its head to the player
// and fires a ballistic fireball; an egg hit destroys it.
#include "common.h"

typedef struct {
    u8 pad[0x48];
    f32 f48;
    u8 pad4C[8];
    f32 f54;
    f32 f58;
    u8 pad5C[8];
    u8 pad64 : 7;
    u8 flag : 1;
} GargS;
extern f32 func_800DC178(f32, f32);
extern void func_80105010(GargS *);
extern int D_80800D7C_chlavagargoyle[];
typedef struct {
    s32 rgb[3];
} GargoyleLightColor;
extern GargoyleLightColor D_80800E44_chlavagargoyle;
extern f32 func_80103EAC(Actor *);
typedef union {
    s32 local_0;
    s16 local_1[2];
} GargoyleMessage37;
extern u8 D_80800E98_chlavagargoyle[];
extern u8 D_80800E50_chlavagargoyle[];
extern u8 _chlavagargoyle_entrypoint_1[];
extern u8 D_80800ED8_chlavagargoyle[];
extern int D_80800F20_chlavagargoyle[];
extern u8 D_80800D2C_chlavagargoyle[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern s32 func_800E0AFC(s32, s32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 unk_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 unk_1 : 1;
    u32 pad_5 : 2;
} Mass63GargoyleFlags;
extern Actor *func_80108528(s32, f32[3], s32, Actor **);
extern f32 func_800EEAD4(f32[3], f32[3]);
extern void func_800EEB9C(f32[3], f32, f32);
extern void func_800EEBF0(f32[3], f32[3], f32);
extern void func_800BBCB8(f32[3], f32[3], f32, s32, void *);
extern int func_8010D12C(s32, f32[3], f32, s32);
extern u8 D_80800D3C_chlavagargoyle[];
extern f32 func_800D8FF8(void);
extern int func_800D91EC(f32 *, f32);
extern f32 func_80013970(f32);
extern int func_800EE7F8(f32 *, f32 *);
extern int func_800EF174(f32 *, f32 *, f32);
extern int func_800EFA4C(f32 *, f32, f32, f32);
extern int func_800BF340(f32 *, f32 *, f32 *, s32, f32);
extern u8 D_80800DD0_chlavagargoyle[];
extern u8 D_80800DC4_chlavagargoyle[];
extern u8 D_80800E08_chlavagargoyle[];
int func_80800B8C_chlavagargoyle();
s32 func_8080064C_chlavagargoyle();

void func_80800000_chlavagargoyle(GargS *state)
{
    state->flag = 1;
    state->f58 = func_800DC178(5.0f, 8.0f);
    func_80105010(state);
    state->f54 = state->f48;
}

void func_80800054_chlavagargoyle(Actor *actor)
{
    s32 head_bone;
    f32 anim_progress;
    f32 player_pos[3];
    func_8010C908(actor, actor->position);
    if (!((Mass63GargoyleFlags *) actor)->unk_1) {
        switch (actor->unk70_10) {
            case 1:
                if (((Mass63GargoyleFlags *) actor)->unk_0) {
                    if (func_8080064C_chlavagargoyle(actor) &&
                        _subaddiejoy_entrypoint_6(actor, 1)) {
                        func_80102424(actor, 2);
                    }
                } else if (func_800D90A4(&actor->unk58) &&
                           func_8080064C_chlavagargoyle(actor)) {
                    func_80102424(actor, 2);
                }
                break;
            case 2:
                anim_progress = func_80101F24(actor);
                if (func_80101DDC(actor)) {
                    if (((Mass63GargoyleFlags *) actor)->unk_0) {
                        actor->unk58 = 4.0f;
                    } else {
                        actor->unk58 = func_800DC178(5.0f, 8.0f);
                    }
                    func_80102424(actor, 1);
                    _subaddieaudioloop_entrypoint_2(actor);
                } else if (anim_progress <= 0.35f) {
                    _subaddieaudioloop_entrypoint_5(actor, actor->position, 1, 2500,
                                                    D_80800D2C_chlavagargoyle);
                    _subaddieaudioloop_entrypoint_0(
                        actor, func_800F10B4(anim_progress, 0.0f, 0.35f, 0.8f, 0.9f));
                } else if (anim_progress >= 0.65f) {
                    _subaddieaudioloop_entrypoint_5(actor, actor->position, 1, 2500,
                                                    D_80800D2C_chlavagargoyle);
                    _subaddieaudioloop_entrypoint_0(
                        actor, func_800F10B4(anim_progress, 0.65f, 1.0f, 0.9f, 0.8f));
                } else {
                    _subaddieaudioloop_entrypoint_2(actor);
                }
                if (func_80101E14(actor, 0.18f) && func_8080064C_chlavagargoyle(actor)) {
                    func_80108B04(actor, 0);
                    func_800C4140(0xA63B5DD1, actor->position, 0xFA000FA);
                }
            case 3:
                break;
        }
    }
    head_bone = func_8010262C(actor->unk0, 2);
    // Turn the head bone toward the player.
    if (head_bone) {
        func_800F5A00(func_800F54E4(), player_pos);
        actor->unk54 =
            func_80013728(func_800F1DF4(actor->position, player_pos) - actor->rotation[1]);
        actor->unk54 = func_800136E4(
            func_800F0D50(actor->unk54, func_80013728(-75.0f), func_80013728(75.0f)));
        actor->unk50 = func_800F1FF0(actor->unk50, actor->unk54, 0.5f, 1.0f, 7.0f);
        func_800E0AFC(head_bone, 0x12, -1.0f, 0.0f, actor->unk50, 0.0f);
    }
}

s32 func_80800394_chlavagargoyle(Actor *actor, s32 msg, s32 arg)
{
    Actor *fireball;
    f32 dir[2];
    f32 player_pos[3];
    f32 *fireball_pos;
    f32 offset[3];
    f32 push[3];
    f32 len;

    switch (msg) {
        // Fire: spawn the fireball (actor 0x402) aimed at the player.
        case 0x3D:
            fireball = func_80108528(0x402, actor->position, 0, &actor);
            func_800F5A00(func_800F54E4(), player_pos);
            fireball_pos = fireball->position;
            fireball->unk58 = func_800EEAD4(fireball_pos, player_pos) / 1100.0f;
            func_8010D12C(func_800F54E4(), player_pos, fireball->unk58, 0);
            len = func_800EEAD4(fireball_pos, player_pos);
            fireball->unk58 = len / 1100.0f;
            ((f32 *) fireball->actorData)[7] =
                func_800F10B4(len, 300.0f, 3000.0f, 100.0f, 600.0f);
            func_800F18FC(fireball_pos, player_pos, dir);
            func_800EEBF0(&((f32 *) fireball->actorData)[4], dir, 1100.0f);
            return 1;
        // Hit by egg: gargoyle is destroyed via skeletonexplode.
        case 0x40:
            func_800EEB9C(offset, actor->rotation[1] - 180.0f, 400.0f);
            func_800EF04C(offset, actor->position);
            _chskeletonexplode_entrypoint_6(actor, offset, 0x902, actor->unk0->unk16);
            func_80107070(actor, 2);
            func_80102424(actor, 3);
            return 1;
        case 1:
            actor->unk58 = 4.0f;
            func_80102424(actor, 1);
            return 1;
        case 2:
            func_80102424(actor, 1);
            return 1;
        case 0x97:
            len = func_80103EAC(actor);
            func_800EEB9C(push, actor->rotation[1], len);
            push[1] += 2.0f * len;
            func_80101010(push);
            return 1;
        case 0xF:
            _chskeletonexplode_entrypoint_4(func_80106790(func_80101080()), 2);
            func_800BBCB8(actor->position, (f32 *) actor->actorData, 1.0f, 2,
                          D_80800D3C_chlavagargoyle);
            func_800C4140(0x7FFB5C13, actor->position, 0x04B000FA);
            func_800C4140(0x7FFB5C17, actor->position, 0x04B000FA);
            return 1;
        default:
            return 0;
    }
}

// Returns nonzero when the player is in firing range.
s32 func_8080064C_chlavagargoyle(actor)
s32 actor;
{
    f32 range;

    range = (f32) func_8010C710();

if (func_8010CD88(actor, 0x42340000, 0x42960000) == 0) {
    return 0;
}

if (range >= 9000000.0f || range < 90000.0f) {
    return 0;
}

return func_800F6478(func_800F54E4());
}

int chlavagargoyle_entrypoint_0()
{
    return &D_80800D7C_chlavagargoyle;
}

void func_8080099C_chlavagargoyle();

void func_808006EC_chlavagargoyle(Actor *actor)
{
    s32 dist;
    f32 prev_pos[3];
    f32 hit_normal[3];

    dist = func_8010C754();

if (func_800D91EC(&((f32 *) actor->actorData)[3], 3.0f)) {
    func_80800B8C_chlavagargoyle(actor, (s32) actor->position, (s32) actor->position);
    return;
}

func_800EE7F8(prev_pos, actor->position);

if (((f32 *) actor->actorData)[3] <= actor->unk58) {
    func_800EF174((f32 *) actor->actorData, &((f32 *) actor->actorData)[4], func_800D8FF8());
    func_800EFA4C(actor->position, ((f32 *) actor->actorData)[0],
                  ((f32 *) actor->actorData)[1] +
                      ((f32 *) actor->actorData)[7] *
                          func_80013970(func_800F10B4(((f32 *) actor->actorData)[3], 0.0f,
                                                      actor->unk58, 0.0f, 180.0f)),
                  ((f32 *) actor->actorData)[2]);
} else {

((f32 *) actor->actorData)[5] += -2000.0f * func_800D8FF8();
func_800EF174(actor->position, &((f32 *) actor->actorData)[4], func_800D8FF8());
}
func_8080099C_chlavagargoyle(actor, actor->position);
_subaddieaudioloop_entrypoint_4(actor, actor->position, dist < 1000,
                                D_80800DC4_chlavagargoyle);
_subaddieaudioloop_entrypoint_0(actor, func_800F10B4((f32) dist, 1000.0f, 0.0f, 0.8f, 1.1f));
if (func_8001210C(1)) {
    func_800BBCB8(actor->position, NULL, actor->scale, 1, D_80800DD0_chlavagargoyle);
    func_800BBCB8(actor->position, NULL, actor->scale, 1, D_80800E08_chlavagargoyle);
}
if (func_800BF340(prev_pos, actor->position, hit_normal, 0x20020, func_80103EAC(actor))) {
    func_800EFA4C(((f32 *) actor->actorData), actor->position[0], actor->position[1] + 50.0f,
                  actor->position[2]);
    func_800C8CB8(actor->unk14, ((f32 *) actor->actorData));
    func_800EFB24(((f32 *) actor->actorData), actor->position, prev_pos);
    func_800EFDE8(((f32 *) actor->actorData), ((f32 *) actor->actorData), hit_normal);
    func_800EFB24(((f32 *) actor->actorData), actor->position, ((f32 *) actor->actorData));
    func_80800B8C_chlavagargoyle(actor, (s32) actor->position,
                                 (s32) ((f32 *) actor->actorData));
}
actor->rotation[1] += actor->unk54 * func_800D8FF8();
actor->rotation[0] += actor->unk50 * func_800D8FF8();
}

void func_8080099C_chlavagargoyle(Actor *actor, f32 *pos)
{
    s32 flicker;
    GargoyleLightColor color = D_80800E44_chlavagargoyle;
    flicker = func_800DC128(0, 10);
    func_800C8CB8(actor->unk14, pos);
    color.rgb[0] -= flicker;
    color.rgb[1] -= flicker;
    func_800C8E84(actor->unk14, color.rgb);
}

s32 func_80800A2C_chlavagargoyle(Actor *actor, s32 msg, GargoyleMessage37 arg)
{
    f32 light_size[2];
    f32 *pos;

    switch (msg) {
        case 0x3E:
            pos = (f32 *) actor->actorData;
            func_800F5A00(func_800F54E4(), pos);
            func_80800B8C_chlavagargoyle(actor, actor->position, pos);
            return 1;
        case 0x40:
            func_80800B8C_chlavagargoyle(actor, actor->position, actor->actorData);
            return 1;
        case 0x95:
            actor->scale = 0.5f;
            actor->unk54 = func_800DC178(180.0f, 360.0f);
            actor->unk50 = func_800DC178(180.0f, 360.0f);
            pos = actor->position;
            func_800EE7F8((f32 *) actor->actorData, pos);
            *(f32 *) &actor->actorData[3] = 0.0f;
            light_size[0] = func_80103EAC(actor) * 10.0f;
            light_size[1] = func_80103EAC(actor) * 15.0f;
            actor->unk14 = func_800C8A98();
            func_800C8F64(actor->unk14, 3);
            func_800C8D4C(actor->unk14, light_size);
            func_800C8FE0(actor->unk14, 1);
            func_800C8CB8(actor->unk14, pos);
            return 1;
    }
    return 0;
}

int func_80800B8C_chlavagargoyle(actor, pos, target)
Actor *actor;
s32 pos;
s32 target;
{
    s32 emitter;

    emitter = func_800B53A4(6);
    func_800BA544(emitter, &_chlavagargoyle_entrypoint_1);
    func_800BABB8(emitter, pos, pos, *(s32 *) ((char *) actor + 0x38),
                  D_80800E50_chlavagargoyle);
    func_800BA22C(emitter, 6);
    func_800BBCB8(pos, pos, *(f32 *) ((char *) actor + 0x38), 2,
                  D_80800E98_chlavagargoyle);
    func_800C4140(0x7FFB5C13, (u8 *) ((char *) actor + 4), 0x04B000FA);
    func_800C4140(0x7FFB5C17, (u8 *) ((char *) actor + 4), 0x04B000FA);
    _subaddieaudioloop_entrypoint_2(actor);
    _chlightfader_entrypoint_1(*(s32 *) ((char *) actor + 0x14), 0x3FC00000, 5);
    func_800FFA88(*(s32 *) ((char *) actor + 0));
}

void chlavagargoyle_entrypoint_1(s32 unk_0, s32 pos)
{
    func_800BBCB8(pos, 0, 1.0f, 1, &D_80800ED8_chlavagargoyle);
}

int chlavagargoyle_entrypoint_2()
{
    return (int) &D_80800F20_chlavagargoyle;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800CF0_chlavagargoyle[10] = {0x0,       0x0,        0x3F800000, 0x4340044,  0x3F800000,
                                     0x434000A, 0x3F800000, 0x4340044,  0x3F800000, 0x4340044};
u32 D_80800D18_chlavagargoyle[5] = {0x20000, 0x30000, 0x30003, 0x40000, 0x10000};
u8 D_80800D2C_chlavagargoyle[16] = {0x0, 0x13, 0x3, 0xF1, 0x0, 0x16, 0x61, 0xA8,
                                    0x0, 0xA,  0x1, 0x0,  0x0, 0x0,  0x0,  0x0};
u8 D_80800D3C_chlavagargoyle[64] = {
    0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x1,  0x0,  0x2, 0x80, 0x0, 0x16, 0x10, 0x0,  0x0,  0x22,
    0x1, 0x80, 0x2,  0x0,  0x4, 0x80, 0x6,  0x0,  0x0, 0x15, 0x0, 0x0,  0x0,  0x26, 0x0,  0x19,
    0x0, 0x0,  0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0, 0x64, 0x0, 0x20, 0x87, 0x87, 0x87, 0xA0,
    0x0, 0xA,  0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0,  0x64, 0x0,  0x0};
int D_80800D7C_chlavagargoyle[18] = {0x10D0401,
                                     0x9000001,
                                     (u32) &D_80800CF0_chlavagargoyle,
                                     (u32) func_80800054_chlavagargoyle,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x1F400000,
                                     0x0,
                                     0x0,
                                     0x800220,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800000_chlavagargoyle,
                                     (u32) func_80107C2C,
                                     -0x7FDDBBEF,
                                     (u32) func_80800394_chlavagargoyle,
                                     (u32) &D_80800D18_chlavagargoyle};
u8 D_80800DC4_chlavagargoyle[12] = {0x0, 0x13, 0x4, 0x83, 0x0, 0xA, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_80800DD0_chlavagargoyle[56] = {
    0x0, 0x1D, 0x9, 0xCE, 0x0,  0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15,
    0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99,
    0x0, 0x2B, 0x0, 0xA6, 0x0,  0xA6, 0x0,  0x1B, 0x1, 0x2C, 0x1, 0x2C, 0x0, 0x18,
    0x0, 0x0,  0x0, 0x0,  0x19, 0x0,  0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0, 0x0};
u8 D_80800E08_chlavagargoyle[60] = {
    0x0,  0x1D, 0x9,  0xCA, 0x0,  0x16, 0x10, 0x0,  0x0,  0x32, 0x0, 0x2,  0x0, 0x15, 0x0,
    0x19, 0x0,  0xF3, 0x0,  0x22, 0x0,  0x80, 0x1,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x2B,
    0x1,  0x0,  0x1,  0x0,  0x0,  0x1B, 0x1,  0xF4, 0x1,  0xF4, 0x0, 0x18, 0x0, 0x0,  0x0,
    0xB,  0xF,  0x0,  0xF,  0x0,  0x0,  0x1F, 0xA0, 0xA0, 0xA0, 0x0, 0x0,  0x0, 0x0,  0x0};
GargoyleLightColor D_80800E44_chlavagargoyle = {0xFF, 0x78, 0x32};
u8 D_80800E50_chlavagargoyle[72] = {
    0x0,  0x1D, 0x8,  0x90, 0x0,  0x7,  0x0,  0x2,  0x0,  0x4,  0x0,  0x80, 0x0,  0x16, 0x15,
    0x86, 0x0,  0x2B, 0x2,  0x0,  0x2,  0x80, 0x0,  0x2D, 0x0,  0xFA, 0x1,  0xF4, 0x0,  0x1B,
    0xFC, 0x18, 0xFC, 0xE0, 0x0,  0x23, 0x0,  0x73, 0x0,  0x27, 0xFE, 0x70, 0xFE, 0x70, 0x1,
    0x90, 0x1,  0x90, 0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0xE,  0x0,  0x1,  0x0,  0xA,
    0x0,  0x31, 0xFF, 0xF6, 0x0,  0x0,  0x0,  0x33, 0x0,  0x1,  0x0,  0x0};
u8 D_80800E98_chlavagargoyle[64] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0,  0x2B, 0x2,  0x0,  0x2, 0x80, 0x0,  0x16, 0x10, 0x0,  0x0, 0x22,
    0x0, 0x80, 0x1, 0x0,  0x4,  0x80, 0x6,  0x0,  0x0, 0x15, 0x0,  0x59, 0x0,  0x59, 0x0, 0x19,
    0x0, 0x0,  0x0, 0x7,  0x0,  0x2C, 0xFF, 0x9C, 0x0, 0x64, 0xFF, 0x9C, 0x0,  0x64, 0x0, 0xC8,
    0x0, 0x64, 0x0, 0x20, 0x91, 0x7D, 0x64, 0xAA, 0x0, 0xE,  0x0,  0x1,  0x0,  0xA,  0x0, 0x0};
u8 D_80800ED8_chlavagargoyle[72] = {
    0x0,  0x1D, 0x9,  0xCE, 0x0,  0x16, 0x12, 0x0,  0x0,  0x32, 0x0,  0x2,  0x0,  0x15, 0x0,
    0x4C, 0x0,  0xE6, 0x0,  0x22, 0x0,  0x66, 0x0,  0x66, 0x0,  0x19, 0x0,  0x19, 0x0,  0x2B,
    0x0,  0xC0, 0x0,  0xC0, 0x0,  0x1B, 0x1,  0x90, 0x1,  0x90, 0x0,  0x18, 0x0,  0x0,  0x0,
    0x0,  0xF,  0x0,  0xF,  0x0,  0x0,  0x17, 0x0,  0x80, 0x0,  0x2C, 0x0,  0x0,  0x0,  0x64,
    0x0,  0x0,  0x0,  0x0,  0x0,  0xC8, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
int D_80800F20_chlavagargoyle[20] = {0x10A0402,
                                     0x8900001,
                                     0x0,
                                     (u32) func_808006EC_chlavagargoyle,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x4,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     0x0,
                                     (u32) func_80800A2C_chlavagargoyle,
                                     0x0,
                                     0x0,
                                     0x0};
