// Egg explosion actor used by grenade, proximity and clockwork eggs: grows a blast sphere, spawns
// particles, light, camera shake and rumble, and damages actors and players in range.
#include "common.h"

extern int D_80800994_cheggsplode[];
typedef struct {
    u8 pad_0[6];
    s16 unk_6;
    u8 pad_8[8];
    s32 light;
} CodexEggSplodeData;
extern u32 D_808009DC_cheggsplode[];
extern void *func_80100094(Actor *, s32);
typedef struct {
    u8 pad_0[0x10];
    s32 light;
} ExplosiveEggLight;
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern s32 D_808008B0_cheggsplode[];
extern s32 D_80800980_cheggsplode[];
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_800187B4(s32, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 func_800F6BE4(s32);
extern s32 func_800F693C(s32);
extern Actor *func_801084B0(s32, f32 *);
typedef struct {
    s32 owner;
    s16 kind;
    s16 unk_6;
    s32 pad_8;
    f32 radius;
} EggExplosion;
extern Actor *func_80108474(s32, f32 *, s32);
extern u8 D_808009E8_cheggsplode[];
extern s32 func_800B53A4(s32);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern int func_800D3948(void);
extern int func_800F6CC8(int);
typedef struct {
    s32 owner;
    s16 kind;
    s16 unk_6;
    f32 time;
    f32 max_radius;
    s32 light;
} EggSplodeLocal;
extern u8 D_80800820_cheggsplode[];
extern u8 D_80800868_cheggsplode[];
extern u8 D_808008E0_cheggsplode[];
extern f32 func_800D8FF8(void);
extern s32 func_8010CC10(f32 *, f32);
extern void func_80109C4C(f32 *, f32, s32, s32, s32, s32, s32);
extern void func_800C8E54(s32, f32, f32);
void func_808006F0_cheggsplode();
void func_80800778_cheggsplode();

int cheggsplode_entrypoint_0()
{
    return (int) &D_80800994_cheggsplode;
}

s32 func_808007D4_cheggsplode();

// Grows the blast over ~0.45 s and damages actors and players in range.
void func_8080000C_cheggsplode(actor, unk_0) Actor *actor;
s32 unk_0;
{
    f32 radius;
    f32 prev_time;
    f32 progress;
    EggSplodeLocal *data;
    s32 owner;
    s32 unk_1;
    s32 player;

    // Matching: needed for the match.
    data = func_80100094(*(Actor **) &actor, 0);
    prev_time = data->time;
    data->time += func_800D8FF8();
    progress = data->time * 2.2222223f;
    // Smoke and fire particles, once at 0.12 s.
    if (0.12f < data->time && prev_time < 0.12f) {
        func_800BABB8(0, actor->position, 0, 1.0f, D_80800820_cheggsplode);
        func_800BABB8(0, actor->position, 0, 1.0f, D_80800868_cheggsplode);
        if (!func_800D3948()) {
            func_800BABB8(0, actor->position, 0, 1.0f, D_808008E0_cheggsplode);
        }
    }
    if (1.0f < progress) {
        progress = 1.0f;
        actor->unk70_10 = 5;
    }
    radius = (data->max_radius - 50.0f) * progress + 50.0f;
    if (data->unk_6 == 0 && func_800F6BE4(data->owner) && func_8010CC10(actor->position, radius)) {
        owner = data->owner;
        unk_1 = _gcegg_entrypoint_7(data->kind);
        func_8010CCE0();
        for (player = func_8010CCEC(); player != -1; player = func_8010CCEC()) {
            if (func_808007D4_cheggsplode(actor, player)) {
                func_800F7A7C(player, owner, unk_1, 5, actor->position);
                func_80800778_cheggsplode(actor, player);
            }
        }
    }
    if (data->unk_6 == 0) {
        func_800CB840(7, actor);
        func_80109C4C(actor->position, radius, 2, 0, 0, *(s32 *) actor, unk_0);
        func_800CB870();
    }
    if (data->light != 0) {
        func_800C8E54(data->light, 1.5f * radius, 3.5f * radius);
    }
}

s32 func_808002A8_cheggsplode(Actor *actor, s32 msg, s32 unk_0)
{
    CodexEggSplodeData *data;

    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x9F:
            if (!func_800D3948()) {
                data->unk_6 = 1;
            }
            return 1;
        case 0x95:
            if (func_800BF8E4() > 0) {
                data->light = func_800C8A98();
                func_800C8E84(data->light, D_808009DC_cheggsplode);
                func_800C8CB8(data->light, actor->position);
            }
            return 1;
    }
    return 0;
}

// States 2-4 run the blast; state 5 fades the light out.
void func_8080035C_cheggsplode(Actor *actor)
{
    ExplosiveEggLight *data;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 2:
        case 3:
            func_8080000C_cheggsplode(actor, 0x26F);
            return;
        case 4:
            func_8080000C_cheggsplode(actor, 0x270);
            return;
        case 5:
            if (data->light)
                data->light = _chlightfader_entrypoint_1(data->light, 1.0f, 2);
            func_800FFAB0(actor);
    }
}

// Init: camera shake, rumble and the first particle effects.
void func_8080041C_cheggsplode(Actor *actor)
{
    u8 *data;
    s32 owner;

    data = func_80100094(actor, 0);
    owner = *(s32 *) data;
    if (!func_800F6BE4(owner)) {
        owner = func_800F54E4();
    }
    *(f32 *) (data + 8) = 0.0f;
    func_800E1610(0, 20.0f, 0.6f, actor->position);
    func_800187B4(func_800F54F0(owner), 0.85f, 0.45f, 0.6f);
    actor->position[1] += 60.0f;
    func_800BABB8(0, actor->position, 0, 1.0f, &D_808008B0_cheggsplode);
    if (*(s16 *) (data + 4) != 5) {
        func_808006F0_cheggsplode(actor);
    }
    func_8010D930(6, -1, actor->position, &D_80800980_cheggsplode);
    *(s32 *) (data + 0x10) = 0;
    if (func_800F6BE4(owner)) {
        func_80800778_cheggsplode(actor, owner);
    }
}

// Blast radius: 250 or 190 depending on the owner.
f32 func_80800548_cheggsplode(s32 owner)
{
    f32 radius;
    if (func_800F6BE4(owner)) {
        if (func_800F693C(owner)) {
            radius = 250.0f;
        } else {
            radius = 190.0f;
        }
        return radius;
    }
    return 190.0f;
}

// Spawns the explosion actor (0x2B2) for kinds 4 and 6.
void cheggsplode_entrypoint_1(f32 *pos, s32 owner, s32 kind)
{
    Actor *actor;
    EggExplosion *data;

    actor = func_801084B0(0x2B2, pos);
    data = func_80100094(actor, 0);
    data->unk_6 = 0;
    data->kind = kind;
    data->owner = owner;
    switch (kind) {
        case 6:
            actor->unk70_10 = 3;
            data->radius = 350.0f;
            break;
        case 4:
            actor->unk70_10 = 2;
            data->radius = func_80800548_cheggsplode(owner);
    }
}

// Spawns the explosion actor (0x2B2); kind 5 sets the radius.
void cheggsplode_entrypoint_2(f32 *pos, f32 unk_0, s32 owner, s32 kind, s32 unk_1)
{
    Actor *actor;
    EggExplosion *data;

    actor = func_80108474(0x2B2, pos, (s32) unk_0);
    data = func_80100094(actor, 0);
    data->owner = owner;
    data->kind = kind;
    data->unk_6 = unk_1 == 0;
    if (kind == 5) {
        actor->unk70_10 = 4;
        data->radius = func_80800548_cheggsplode(owner);
    }
}

// Spawns the blast particle emitter.
void func_808006F0_cheggsplode(actor) Actor *actor;
{
    u16 unk_0;
    s32 emitter;

    emitter = func_800B53A4(6);
    if (actor->unk70_10 == 3) {
        unk_0 = 0x875;
    } else {
        unk_0 = 0x9B1;
    }
    func_800BA670(emitter, unk_0);
    func_800BABB8(emitter, actor->position, actor->position, 0.25f, D_808009E8_cheggsplode);
    func_800BA22C(emitter, 6);
}

void func_80800778_cheggsplode(actor, player) s32 actor;
s32 player;
{
    if (func_800D3948() == 0) {
        if (func_800F6BE4(player) && func_800F6CC8(player)) {
            void *data = func_80100094(actor, 0);
            *(u16 *) ((char *) data + 6) = 1;
        }
    }
}

s32 func_808007D4_cheggsplode(s32 actor, s32 player)
{
    s32 result;
    result = func_800F6478(player);
    if (result == 0) {
        return 0;
    }
    return 1;
}

// TU-NOTE: .data is defined in C (values from the ROM). The tables point to functions of this file; IDO's
// assembler schedules some of them differently unless they are in the same unit. D_808008B0_cheggsplode and
// D_80800980_cheggsplode are s32[], D_80800994_cheggsplode is int[].
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800820_cheggsplode[72] = {0x7, 0x10, 0x0,  0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x2,  0x0,  0x99,
                                 0x0, 0x16, 0x10, 0x0,  0x0, 0x1E, 0x0, 0x32, 0x0, 0x32, 0x0,  0xE,
                                 0x0, 0x6E, 0x0,  0x78, 0x0, 0x26, 0x0, 0x0,  0x0, 0x0,  0xFF, 0x9C,
                                 0x0, 0x0,  0x0,  0x0,  0x0, 0x64, 0x0, 0x19, 0x0, 0x1,  0x0,  0x1,
                                 0x0, 0x22, 0x0,  0x99, 0x0, 0xCC, 0x1, 0x99, 0x2, 0x0,  0x0,  0x2A,
                                 0x0, 0xA,  0x0,  0xA,  0x0, 0x80, 0x0, 0x8C, 0x0, 0xF,  0x0,  0x0};
u8 D_80800868_cheggsplode[72] = {0x5, 0x10, 0x0,  0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x2,  0x0,  0x99,
                                 0x0, 0x16, 0x10, 0x0,  0x0, 0x1E, 0x0, 0x32, 0x0, 0x32, 0x0,  0xE,
                                 0x0, 0x1E, 0x0,  0x3C, 0x0, 0x26, 0x0, 0x0,  0x0, 0x0,  0xFF, 0x9C,
                                 0x0, 0x0,  0x0,  0x0,  0x0, 0x64, 0x0, 0x19, 0x0, 0x0,  0x0,  0x0,
                                 0x0, 0x22, 0x0,  0x99, 0x0, 0xCC, 0x2, 0x0,  0x2, 0xCC, 0x0,  0x2A,
                                 0x0, 0x8,  0x0,  0x8,  0x0, 0x66, 0x0, 0x66, 0x0, 0xF,  0x0,  0x0};
s32 D_808008B0_cheggsplode[12] = {0x110001D, 0x9D60015, 0x200CC,  0x161000,  0x1E0032, 0x320019,
                                  0x0,       0x2200CC,  0xCC0380, 0x380002B, 0x590059, 0x11A0000};
u8 D_808008E0_cheggsplode[160] = {
    0x4, 0x10, 0x0,  0x1D, 0x9, 0xDC, 0x0, 0x2C, 0xFF, 0xD8, 0x0, 0x32, 0xFF, 0xD8, 0x0,  0x28,
    0x0, 0x64, 0x0,  0x28, 0x0, 0x15, 0x0, 0x14, 0x0,  0x66, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0x6E,
    0x0, 0x22, 0x1,  0x0,  0x1, 0x80, 0x2, 0x0,  0x3,  0x0,  0x0, 0x16, 0x10, 0x0,  0x0,  0x18,
    0x0, 0x0,  0x0,  0x3,  0x0, 0x0,  0x0, 0x0,  0x0,  0x2B, 0x2, 0xCC, 0x3,  0xCC, 0x0,  0x21,
    0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0xA,  0xFF, 0x9C, 0x0, 0x28, 0x0,  0x0,  0xFF, 0x9C,
    0x0, 0x28, 0x0,  0x0,  0x1, 0x1A, 0x0, 0x21, 0x0,  0x0,  0x0, 0x0,  0x0,  0x5A, 0x0,  0xA,
    0x0, 0x64, 0x0,  0x28, 0x0, 0x0,  0x0, 0x64, 0x0,  0x28, 0x0, 0x0,  0x1,  0x1A, 0x0,  0x21,
    0x0, 0x0,  0x0,  0x0,  0x0, 0xB4, 0x0, 0xA,  0x0,  0x0,  0x0, 0x28, 0xFF, 0x9C, 0x0,  0x0,
    0x0, 0x28, 0xFF, 0x9C, 0x1, 0x1A, 0x0, 0x21, 0x0,  0x0,  0x0, 0x0,  0x1,  0xE,  0x0,  0xA,
    0x0, 0x0,  0x0,  0x28, 0x0, 0x64, 0x0, 0x0,  0x0,  0x28, 0x0, 0x64, 0x1,  0x1A, 0x0,  0x0};
s32 D_80800980_cheggsplode[5] = {0x130413, 0x18000D, 0xF3010C, 0x103E8, 0x13880000};
int D_80800994_cheggsplode[18] = {0x16A02B2,
                                  0x1,
                                  0x0,
                                  (u32) func_8080035C_cheggsplode,
                                  (u32) func_80105834,
                                  (u32) func_8010A730,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x140000,
                                  (u32) func_8080041C_cheggsplode,
                                  (u32) func_80107C2C,
                                  -0x7FFFF9FE,
                                  (u32) func_808002A8_cheggsplode,
                                  0x0};
u32 D_808009DC_cheggsplode[3] = {0xFF, 0xC0, 0x40};
u8 D_808009E8_cheggsplode[72] = {0x1, 0x13, 0x0,  0x16, 0x14, 0x0,  0x0, 0x15, 0x0, 0x0,  0x0, 0xCC,
                                 0x0, 0x4,  0x0,  0xCC, 0x0,  0x7,  0x0, 0x1,  0x0, 0x2B, 0x0, 0x99,
                                 0x0, 0xCC, 0x0,  0x22, 0x1,  0x0,  0x1, 0x0,  0x0, 0x66, 0x0, 0x99,
                                 0x0, 0xE,  0x0,  0xA,  0x0,  0x14, 0x0, 0x2D, 0x4, 0xB0, 0x5, 0x78,
                                 0x0, 0x1B, 0xFC, 0x18, 0xFB, 0x50, 0x0, 0x27, 0x0, 0xC8, 0x0, 0xC8,
                                 0x1, 0x90, 0x1,  0x90, 0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
