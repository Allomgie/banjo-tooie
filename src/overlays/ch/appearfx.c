// The 'appear' effect actor (0x3D9), spawned at an actor that materialises: a rising sparkle swarm
// sized from its model, optional sound, music duck and fade-in, kept linked to the target.
#include "common.h"

extern int D_80800990_chappearfx[];
typedef struct {
    s32 sprite_id;
    s32 unk_4;
} AfxPair;
extern AfxPair D_80800970_chappearfx[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2530(f32);
typedef struct {
    // Same layout as AppearParticle; only the fields used for drawing are named.
    s16 unk_0, unk_2, unk_4, unk_6, unk_8, unk_A;
    f32 rotation;
    f32 scale;
} AFXE_;
extern s32 _chappearfx_entrypoint_3;
typedef struct {
    // Particles (AppearParticle, 0x14 bytes each) follow at +0x1C.
    s16 count;
    s16 max_count;
    s16 flags;
    s16 radius;
    s16 max_y;
    s16 min_y;
    u8 alpha;
    u8 music_ducked;
    s16 kind;
    s16 unk_10;
    s16 unk_12;
    u8 link[8];
} AppearFX49;
extern s32 D_80800974_chappearfx[][2];
extern u8 D_808009D8_chappearfx[];
extern Actor *func_80106790();
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void *func_80100074(Actor *, s32, s32);
extern f32 func_80103EAC(Actor *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddielink_entrypoint_0();
extern void rare_memcpy();
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *_subaddielink_entrypoint_4(void *);
typedef struct {
    // shorts: 0 orbit speed, 1 rise speed, 2 sprite variant, 3 angle, 4 height, 5 spin speed
    s16 shorts[6];
    f32 rotation, scale;
} AppearParticle;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC128(s32, s32);
extern int func_800DC298(f32);
void chappearfx_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, f32 param_3);
void func_80800554_chappearfx();
extern void func_80105834(), func_80107C2C(), func_8080000C_chappearfx(),
    func_80800014_chappearfx(), func_8080031C_chappearfx();

int *chappearfx_entrypoint_0()
{
    return &D_80800990_chappearfx;
}

void func_8080000C_chappearfx(s32 arg0)
{
}

void func_80800014_chappearfx(actor) Actor *actor;
{
    s16 *fx;
    AppearParticle *particle;
    AppearParticle *particles;
    s32 i;
    f32 dt;
    s32 finished;

    fx = func_80100094(actor, 0);
    if (!func_8001210C(1)) {
        func_80800554_chappearfx(actor);
    }
    switch ((s32) actor->unk70_10) {
        case 1:
            ((u8 *) fx)[0xD] = 1;
            func_800FCAE0(0x1C, -1, 0x1F4);
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 2);
                actor->unk58 = 1.2f;
            }
            break;
        case 2:
            finished = func_800D9078(&actor->unk58);
            ((u8 *) fx)[0xC] = (u32) func_800F10B4(actor->unk58, 0.0f, 1.2f, 16.0f, 255.0f);
            if (finished) {
                ((u8 *) fx)[0xD] = 0;
                func_800FCAE0(0x1C, 0, 0x1F4);
                func_800FCA90(0x1C);
                func_800FFAB0(actor);
            } else {
                ((u8 *) fx)[0xD] = 1;
                func_800FCAE0(0x1C, -1, 0x1F4);
            }
    }
    if ((((u16 *) fx)[2] & 8) && _subaddielink_entrypoint_2((u8 *) fx + 0x14)) {
        func_800EE7F8(actor->position,
                      _subaddielink_entrypoint_4((u8 *) fx + 0x14)->position);
    }
    dt = func_800D8FF8();
    particles = (AppearParticle *) ((u8 *) fx + 0x1C);
    particle = particles;
    // Move particles; remove those above the max height by copying the last one over.
    for (i = 0; i < fx[0];) {
        particle->shorts[4] += dt * particle->shorts[1];
        particle->shorts[3] += dt * particle->shorts[0];
        particle->rotation += dt * particle->shorts[5];
        if (particle->shorts[4] >= fx[4]) {
            fx[0]--;
            if (fx[0] > 0) {
                rare_memcpy(particle, particles + fx[0], sizeof(AppearParticle));
            }
            continue;
        }
        particle++;
        i++;
    }
}

void func_8080031C_chappearfx(actor) s32 actor;
{
    u8 *fx;

    fx = func_80100094(actor, 0);
    if (fx[0xD] != 0) {
        fx[0xD] = 0;
        func_800FCAE0(0x1C, 0, 0x1F4);
        func_800FCA90(0x1C);
    }
}

int func_80800360_chappearfx(actor, unk_1, unk_2)
s32 actor;
s32 unk_1;
s32 unk_2;
{
    if (unk_1 == 0x95) {
        _subaddielink_entrypoint_3(func_80100094(actor, 0) + 0x14);
        return 1;
    }
    return 0;
}

// Draws all particles as sprites.
void func_808003A0_chappearfx(Actor *actor, void *gfx)
{
    u8 *fx;
    u8 *particle;
    s32 i;
    void *sprite;
    f32 pos[3];
    f32 size[3];
    f32 scale;
    fx = func_80100094(actor, 0);
    particle = fx + 0x1C;
    actor->unk7C_12 = 1;
    if (*(s16 *) fx) {
        sprite = func_800D674C(D_80800970_chappearfx[*(s16 *) (fx + 0xE)].sprite_id);
        func_800E2588((*(u16 *) (fx + 4) & 0x10) ? 0 : 1);
        func_800E2594(gfx, sprite);
        func_800E24D8(1);
        for (i = 0; i < *(s16 *) fx; i++, particle += 0x14) {
            scale = actor->scale * ((AFXE_ *) particle)->scale;
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, *(s16 *) (particle + 6), *(s16 *) (fx + 6));
            pos[1] += *(s16 *) (particle + 8);
            func_800EFA4C(size, scale, scale, scale);
            func_800E2530(*(f32 *) (particle + 0xC));
            func_800E2720(gfx, 0, *(s16 *) (particle + 4), pos, size, fx[0xC]);
        }
        func_800E2A14(gfx);
    }
}

// Adds one particle with randomised parameters.
void func_80800554_chappearfx(actor) Actor *actor;
{
    s16 *fx;
    AppearParticle *particle;
    f32 rise_speed;
    fx = func_80100094(actor, 0);
    if (fx[0] < fx[1]) {
        particle = (AppearParticle *) fx;
        particle += fx[0];
        particle = (AppearParticle *) ((u8 *) particle + 0x1C);
        particle->shorts[3] = func_800DC178(0.0f, 359.0f);
        particle->shorts[0] = func_800DC128(250, 350);
        rise_speed = func_800F10B4(fx[4] - fx[5], 0.0f, 500.0f, 30.0f, 350.0f);
        particle->shorts[1] = func_800DC178(0.8f, 1.2f) * rise_speed;
        particle->shorts[4] = fx[5];
        particle->shorts[2] = func_800DC298(0.5f);
        particle->scale = func_800DC178(0.8f, 1.4f);
        particle->rotation = func_800DC178(0.0f, 360.0f);
        particle->shorts[5] = func_800DC128(-200, 200);
        fx[0]++;
    }
}

void chappearfx_entrypoint_1(s32 *target_ref, s32 flags, s32 kind, s32 size_scale)
{
    _chbaddiesetup_entrypoint_4(&_chappearfx_entrypoint_3, *target_ref, flags, kind, size_scale);
}

void chappearfx_entrypoint_2(Actor **target_ref, f32 *flags, s32 kind, s32 size_scale)
{
    chappearfx_entrypoint_3(*target_ref, flags, kind, *(f32 *) &size_scale);
}

void chappearfx_entrypoint_3(s32 target_ref, s32 flags, s32 kind, f32 size_scale)
{
    Actor *target;
    Actor *appear;
    s32 radius;
    s32 max_y;
    s32 min_y;
    s32 count;
    f32 scale;
    AppearFX49 *fx;
    // Matching: the copy through casts is needed for the match.
    *(f32 *) &scale = *(f32 *) &size_scale;
    target = func_80106790(target_ref);
    appear = func_80108528(0x3D9, target->position, 0, &target);

    radius = (func_80103EAC(target) + 20.0f) * scale;
    max_y = func_800F0E00(50.0f, *(s16 *) ((u8 *) target + 0x8A) * target->scale);
    min_y = func_800F13F0(0.0f, *(s16 *) ((u8 *) target + 0x88) * target->scale);
    count = func_800F10B4(max_y - min_y, 0.0f, 500.0f, 15.0f, 40.0f);

    fx = func_80100074(appear, 0, count * 20 + 28);
    appear->unk58 = 3.0f;
    fx->max_count = count;
    fx->count = 0;
    fx->unk_12 = radius + 400;
    fx->radius = radius;
    fx->unk_10 = radius;
    fx->max_y = max_y;
    fx->min_y = min_y;
    fx->alpha = 255;
    fx->flags = flags;
    _subaddielink_entrypoint_0(fx->link);
    fx->kind = kind;
    func_80102FDC(appear, D_80800974_chappearfx[kind][0]);

    // Flags: 2 = sound, 4 = func_800FC660, 8 = link to target, 0x20 = fade target.
    if (flags & 2)
        _subaddieaudioquick_entrypoint_2(appear, appear->position, D_808009D8_chappearfx);
    if (flags & 4)
        func_800FC660(0x10);
    if (flags & 8)
        _subaddielink_entrypoint_1(fx->link, target->unk0);
    if (flags & 0x20)
        _subaddiefade_entrypoint_2(target);
}

// TU-NOTE: The overlay .data is defined here in C. Its tables point at functions of this file,
// and IDO's assembler schedules some of them differently unless they are in the same unit.
// Values are taken from the ROM. D_80800974_chappearfx = D_80800970_chappearfx + 0x4 (linker
// symbol). The extern of D_80800990_chappearfx is declared as int[] to match the object.

AfxPair D_80800970_chappearfx[4] = {0x9E3, 0x3E99999A, 0x9E1, 0x3E99999A,
                                    0x9E4, 0x3E99999A, 0x9E9, 0x3E99999A};
int D_80800990_chappearfx[18] = {0xA003D9,
                                 -0xFFFF,
                                 0x0,
                                 (u32) func_80800014_chappearfx,
                                 (u32) func_80105834,
                                 (u32) func_808003A0_chappearfx,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x20000,
                                 (u32) func_8080031C_chappearfx,
                                 0x0,
                                 0x0,
                                 (u32) func_8080000C_chappearfx,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 (u32) func_80800360_chappearfx,
                                 0x0};
u8 D_808009D8_chappearfx[24] = {0x0, 0x13, 0x4, 0x80, 0x0, 0x18, 0x0, 0xD, 0x0, 0xE6, 0x1, 0x19,
                                0x0, 0x2,  0x0, 0x1B, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
