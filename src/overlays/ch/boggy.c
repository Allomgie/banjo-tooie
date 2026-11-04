#include "common.h"

extern s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
extern void func_80101FDC(s32, s32);
extern void func_800DA544(s32);
extern void func_800F82D4(s32, s32);
extern s32 func_800F54E4(void);
typedef union {
    s32 word;
    s16 half[2];
} BoggyMessage32;
extern s32 D_80800820_chboggy[];
extern Actor *func_80106790();
extern s32 _chbounce_entrypoint_9(s32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800902E4(f32 *, f32, s32, Actor **);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_80800740_chboggy[];
extern u8 D_80800704_chboggy[];
extern u8 D_808006A0_chboggy[];
extern u8 D_80800710_chboggy[];
extern u8 D_808006F8_chboggy[];
extern u8 D_808006C8_chboggy[];
extern u8 D_8080074C_chboggy[];
extern u8 D_80800800_chboggy[];
extern u8 D_80800790_chboggy[];
extern u8 D_808006B0_chboggy[];
extern u8 D_808006E8_chboggy[];
extern u8 D_80800760_chboggy[];
extern u8 D_808006B8_chboggy[];
extern u8 D_80800730_chboggy[];
extern u8 D_808006D8_chboggy[];
extern u8 D_80800720_chboggy[];
extern u8 D_80800810_chboggy[];
extern u8 D_808007C8_chboggy[];
typedef struct {
    u8 pad[0x7C];
    u32 pad7C : 19;
    u32 flag : 1;
    u32 rest : 12;
} BoggyS;
extern s32 func_80104130(void);
extern void func_800DBEFC();
extern void *_idworld_entrypoint_0(s32);
extern f32 _idglowa_entrypoint_1(void *);
extern s16 D_80800830_chboggy[];
extern s32 func_800C4350();
extern void func_800C3A40(u8, f32, f32, f32);
extern int D_80800840_chboggy[];
typedef struct {
    u8 pad[0x38];
    f32 f38;
    u8 pad3C[8];
    f32 f44;
    u8 pad48[4];
    f32 f4C;
    u8 pad50[0x26];
    u16 f76 : 9;
    u16 pad76 : 7;
} BoggyState;
extern int D_80800888_chboggy[];
void func_80800554_chboggy();

void func_80800000_chboggy(s32 actor)
{
    *(f32 *) ((u8 *) actor + 0x38) = 0.18f;
    if (func_800DA298(0x439) != 0 || _glcutDll_entrypoint_20() != 0) {
        func_80101FDC(actor, 3);
    }
}

void func_80800054_chboggy(s32 actor, s32 msg_a, s32 msg_b)
{
    s32 dialog_a;
    s32 dialog_b;
    dialog_a = _subaddiedialog_entrypoint_9(actor, msg_a, (s32 *) D_80800790_chboggy, 7);
    dialog_b = _subaddiedialog_entrypoint_9(actor, msg_a, (s32 *) D_808007C8_chboggy, 7);
    if (dialog_a == 1) {
        func_80101FDC(actor, 1);
        func_800DA544(0x447);
    } else if (dialog_b == 1) {
        func_800F82D4(func_800F54E4() | 0, 0 | 0);
    }
}

s32 func_808000EC_chboggy(Actor *actor, s32 msg_type, BoggyMessage32 msg)
{
    s32 state;

    switch (msg_type) {
        case 0x2E:
            func_80800054_chboggy(actor, msg.half[0], msg.half[1]);
            break;
        case 0x1F:
            func_800DF3E0();
            func_801015D0(actor);
            state = actor->unk70_10 == 1 ? 1 : 2;
            func_800DF744(3, state);
            break;
        case 0x7D:
            func_80101FDC(actor, 2);
            break;
        case 0x3D:
            // Spawn the jiggy (collectible 0x40) via bounce.
            if (msg.word == 0x22B) {
                _subaddieaudioquick_entrypoint_2(actor, &actor->actorData[4],
                                                 D_80800820_chboggy);
                *(f32 *) &actor->actorData[1] -= 60.0f;
                ((f32 *) _chbounce_entrypoint_9((s32) func_80106790(
                    func_800D10D4(0x40, 1, actor->actorData, 0, 0))))[1] = 0.0f;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800220_chboggy(Actor *actor)
{
    u32 state;
    _sudeflect_entrypoint_0(actor->position, 175.0f, 175.0f, 0xE);
    func_80800554_chboggy(actor);
    state = actor->unk70_10;
    switch (state) {
        case 1:
            _subaddieaudioquick_entrypoint_3(actor, (f32 *) &actor->actorData[4],
                                             &D_808006A0_chboggy, 0.1298000067f);
            _subaddieaudioquick_entrypoint_4(actor, (f32 *) &actor->actorData[4],
                                             &D_80800704_chboggy, &D_80800740_chboggy);
            _subaddieaudioquick_entrypoint_3(actor, (f32 *) &actor->actorData[4],
                                             &D_80800710_chboggy, 0.4199999869f);
            _subaddieaudioquick_entrypoint_3(actor, (f32 *) &actor->actorData[4],
                                             &D_808006F8_chboggy, 0.5799999833f);
            _subaddieaudioquick_entrypoint_4(actor, (f32 *) &actor->actorData[4],
                                             &D_808006C8_chboggy, &D_8080074C_chboggy);
            // Take the carried fish (actor 0x4D7) when it is brought close.
            if (((func_800DA298(0x447) != 0) &&
                 ((func_800902E4(actor->position, 400.0f, 0x4D7, &actor),
                   func_800F640C(func_800F54E4(), 0x4D7) != 0) ||
                  (func_8008FE14() == 0x4D7))) &&
                (func_80090818() != 0)) {
                func_80090768((f32 *) actor->actorData);
                func_800D1824(0x51);
                func_800F8300(func_800F54E4(), 2, actor->position);
            }
            // Flag 0x437 is set along with 0x439.
            if (func_800DA298(0x439) != 0) {
                func_800DA544(0x437);
            }
            _subaddiedialog_entrypoint_8(actor, actor->position, &D_80800800_chboggy,
                                         &D_80800790_chboggy, 7);
            return;

        case 2:
            _subaddieaudioquick_entrypoint_3(actor, (f32 *) &actor->actorData[4],
                                             &D_808006B0_chboggy, 0.05000000075f);
            _subaddieaudioquick_entrypoint_4(actor, (f32 *) &actor->actorData[4],
                                             &D_808006E8_chboggy, &D_80800760_chboggy);
            _subaddieaudioquick_entrypoint_4(actor, (f32 *) &actor->actorData[4],
                                             &D_808006B8_chboggy, &D_80800730_chboggy);
            if (((func_80101E14(actor, 0.6000000238f) != 0) && (func_800D0B68(0x40, 1) == 0)) &&
                (func_800D0A9C(0x40, 1) == 0)) {
                func_80108B04(actor, 0x22B);
            }
            if (func_80101E14(actor, 0.9900000095f) != 0) {
                func_80101FDC(actor, 3);
            }
            return;

        case 3:
            _subaddieaudioquick_entrypoint_3(actor, (f32 *) &actor->actorData[4],
                                             &D_808006D8_chboggy, 0.2199999988f);
            _subaddieaudioquick_entrypoint_4(actor, (f32 *) &actor->actorData[4],
                                             &D_808006B8_chboggy, &D_80800720_chboggy);
            _subaddiedialog_entrypoint_8(actor, actor->position, &D_80800810_chboggy,
                                         &D_808007C8_chboggy, 7);
    }
}

void func_80800504_chboggy(BoggyS *actor)
{
    func_801018A4(actor);
    if (actor->flag) {
        func_800DBEFC(func_80104130(), 4, (u8 *) actor + 0x18);
    }
}

void func_80800554_chboggy(unk_0) s32 unk_0;
{
    s32 glow_step;
    s32 pad0;
    u8 glow_id;
    void *world;

    world = _idworld_entrypoint_0(0x35C);
    if (world != NULL) {
        glow_step = (s32) (_idglowa_entrypoint_1(world) * 32.0f);
        if (glow_step == 0x13)
            func_800DA544(0xA2E);
        if (glow_step == 0x12 && func_800DA298(0xA2E)) {
            glow_id = func_800C4350(0, NULL, D_80800830_chboggy);
            func_800C36F4(glow_id, 1);
            func_800C3A40(glow_id, 1.0f, 1.4f, 1.0f);
            func_800C3BDC(glow_id);
            func_800DA524(0xA2E);
        }
    }
}

int chboggy_entrypoint_0()
{
    return (int) &D_80800840_chboggy;
}

void func_80800634_chboggy(BoggyState *state)
{
    state->f44 = state->f76;
    state->f4C = state->f38 * 100.0f;
    state->f38 = 2.0f;
}

int chboggy_entrypoint_1()
{
    return (int) &D_80800888_chboggy;
}

extern void func_80105834();
extern void func_80107C2C();
extern void func_80102EC0();
extern void func_80101870();
u8 D_808006A0_chboggy[16] = {0x0, 0x13, 0x4,  0x9E, 0x0, 0xA, 0x0, 0xCC,
                             0x0, 0x16, 0x3A, 0x98, 0x0, 0x0, 0x0, 0x0};
u8 D_808006B0_chboggy[8] = {0x0, 0x13, 0x4, 0xA4, 0x0, 0x18, 0x0, 0x0};
u8 D_808006B8_chboggy[16] = {0x0, 0x13, 0x4, 0x2,  0x0,  0xD,  0x0, 0xCC,
                             0x0, 0xE6, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x0};
u8 D_808006C8_chboggy[16] = {0x0, 0x13, 0x4, 0x2,  0x0,  0xD,  0x0, 0xCC,
                             0x0, 0xE6, 0x0, 0x16, 0x23, 0x28, 0x0, 0x0};
u8 D_808006D8_chboggy[16] = {0x0, 0x13, 0x4, 0x9F, 0x0,  0xD,  0x0, 0xCC,
                             0x0, 0xE6, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x0};
u8 D_808006E8_chboggy[16] = {0x0, 0x13, 0x4,  0x30, 0x0, 0xA, 0x0, 0xE6,
                             0x0, 0x16, 0x27, 0x10, 0x0, 0x0, 0x0, 0x0};
u8 D_808006F8_chboggy[12] = {0x0, 0x13, 0x6, 0x13, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x0, 0x0, 0x0};
u8 D_80800704_chboggy[12] = {0x0, 0x13, 0x5, 0xBB, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x0, 0x0, 0x0};
u8 D_80800710_chboggy[16] = {0x0, 0x13, 0x6,  0x63, 0x0, 0xA, 0x0, 0xCC,
                             0x0, 0x16, 0x23, 0x28, 0x0, 0x0, 0x0, 0x0};
u8 D_80800720_chboggy[16] = {0x3E, 0x4B, 0xF,  0x28, 0x3E, 0x84, 0x3F, 0xE6,
                             0x3E, 0xA2, 0xF8, 0x38, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800730_chboggy[16] = {0x3E, 0x40, 0xD1, 0xB7, 0x3E, 0x69, 0xC7, 0x7A,
                             0x3E, 0x89, 0x5E, 0x9E, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800740_chboggy[12] = {0x3E, 0x75, 0xC2, 0x8F, 0x3E, 0xB3, 0x33, 0x33, 0xBF, 0x80, 0x0, 0x0};
u8 D_8080074C_chboggy[20] = {0x3F, 0x38, 0x4B, 0x5E, 0x3F, 0x4A, 0x36, 0xE3, 0x3F, 0x59,
                             0x93, 0xC,  0x3F, 0x63, 0xD0, 0x7D, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800760_chboggy[16] = {0x3E, 0xB3, 0x33, 0x33, 0x3E, 0xF0, 0xA3, 0xD7,
                             0x3F, 0x7,  0xAE, 0x14, 0xBF, 0x80, 0x0,  0x0};
u32 D_80800770_chboggy[8] = {0x0,        0x0,       0x41100000, 0x4410001,
                             0x41100000, 0x4420002, 0x40ACCCCD, 0x4430001};
u8 D_80800790_chboggy[56] = {0x0,  0x0,  0x0,  0x1,  0x12, 0xBF, 0x1, 0x0, 0x0,  0x0,  0x0, 0x1,
                             0x12, 0xC0, 0x2,  0x0,  0x0,  0x0,  0x2, 0x0, 0x12, 0xDC, 0x1, 0x0,
                             0x0,  0x0,  0x2,  0x0,  0x12, 0xC0, 0x2, 0x0, 0x0,  0x0,  0x4, 0x0,
                             0x12, 0xDD, 0x1,  0x0,  0x0,  0x0,  0x4, 0x0, 0x12, 0xDE, 0x2, 0x0,
                             0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB,  0x3, 0x0};
u8 D_808007C8_chboggy[56] = {0x0,  0x0,  0x0,  0x1,  0x12, 0xC1, 0x1, 0x0, 0x0,  0x0,  0x0, 0x1,
                             0x12, 0xC2, 0x2,  0x0,  0x0,  0x0,  0x2, 0x0, 0x12, 0xC1, 0x1, 0x0,
                             0x0,  0x0,  0x2,  0x0,  0x12, 0xC2, 0x2, 0x0, 0x0,  0x0,  0x4, 0x0,
                             0x12, 0xC1, 0x1,  0x0,  0x0,  0x0,  0x4, 0x0, 0x12, 0xC2, 0x2, 0x0,
                             0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB,  0x3, 0x0};
u8 D_80800800_chboggy[16] = {0x4, 0x37, 0x0, 0x0, 0x1, 0x90, 0x0, 0x47,
                             0x0, 0x0,  0x0, 0xC, 0x3, 0x64, 0x0, 0x0};
u8 D_80800810_chboggy[16] = {0x4, 0x39, 0x0, 0x0, 0x1, 0x90, 0x0, 0x47,
                             0x0, 0x0,  0x0, 0xC, 0x3, 0x64, 0x0, 0x0};
s32 D_80800820_chboggy[4] = {0x130430, 0xA0133, 0x167FBC, 0x0};
s16 D_80800830_chboggy[8] = {0x306, 0x13, 0x666, 0x17, 0x1F40, 0x2328, 0xF, 0x0};
int D_80800840_chboggy[18] = {0x37904A5,
                              0x8F10001,
                              (u32) &D_80800770_chboggy,
                              (u32) func_80800220_chboggy,
                              (u32) func_80105834,
                              (u32) func_80800504_chboggy,
                              0x0,
                              0x0,
                              0x0,
                              0x50A,
                              0x0,
                              0x0,
                              0x140000,
                              (u32) func_80800000_chboggy,
                              (u32) func_80107C2C,
                              -0x7FFFCBFA,
                              (u32) func_808000EC_chboggy,
                              0x0};
int D_80800888_chboggy[18] = {0x1580530,
                              0x5EE0001,
                              0x0,
                              (u32) func_80102EC0,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x0,
                              0x0,
                              0x0,
                              0x20800,
                              0x0,
                              0x0,
                              0x0,
                              (u32) func_80800634_chboggy,
                              (u32) func_80107C2C,
                              -0x7FF7D3FE,
                              0x0,
                              0x0};
