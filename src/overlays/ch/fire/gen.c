#include "common.h"

extern void func_800DBE60(u8, s32, s32);
extern int D_808015B4_chfiregen[];
extern int D_808015FC_chfiregen[];
extern int D_80801644_chfiregen[];
extern s32 D_8080168C_chfiregen[];
extern int D_808016D4_chfiregen[];
extern int D_8080171C_chfiregen[];
typedef struct {
    u8 pad_0[0x72];
    u8 local_0 : 6;
    u8 pad_1 : 2;
} FireGeneratorMode;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern int D_808017BC_chfiregen[];
extern s32 D_80801804_chfiregen[];
extern int D_8080184C_chfiregen[];
extern int D_80801894_chfiregen[];
extern int D_808018DC_chfiregen[];
extern s32 D_80801924_chfiregen[];
extern int D_8080196C_chfiregen[];
extern int D_808019B4_chfiregen[];
extern int D_808019FC_chfiregen[];
extern int D_80801A44_chfiregen[];
extern s32 D_80801A8C_chfiregen[];
extern void *D_80801AD4_chfiregen;
extern void *_idworld_entrypoint_3(s32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC0C0(void);
extern void func_80101CDC(Actor *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800C31DC(u8, f32);
extern s32 func_800C4350();
extern f32 func_800D9004(void);
extern f32 func_80101D0C(Actor *);
extern u8 D_80801784_chfiregen[];
extern void *func_800B53A4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
extern f32 func_800D8FF8(void);
extern void func_800EDDDC(void *, f32 *, f32 *, f32);
void func_80800978_chfiregen();
void func_80800B4C_chfiregen();

// Message handler; 0x40 is a hit by an attacker.
s32 func_80800000_chfiregen(Actor *actor, s32 message, void *data)
{
    u8 unk_0;
    switch (message) {
        case 0x1F:
            unk_0 = func_800D731C(actor->unk0->unk14);
            func_801015D0(actor);
            if (unk_0)
                func_800DBE60(unk_0, 0, actor->unk79_4);
            break;
        case 0x40:
            func_80800978_chfiregen(actor, *(void **) &data);
            break;
        default:
            return 0;
    }
    return 1;
}

int chfiregen_entrypoint_0()
{
    return &D_808015B4_chfiregen;
}

int chfiregen_entrypoint_1()
{
    return (int) &D_808015FC_chfiregen;
}

int chfiregen_entrypoint_2()
{
    return &D_80801644_chfiregen;
}

int chfiregen_entrypoint_3()
{
    return (int) D_8080168C_chfiregen;
}

int chfiregen_entrypoint_4()
{
    return (int) &D_808016D4_chfiregen;
}

int *chfiregen_entrypoint_5()
{
    return &D_8080171C_chfiregen;
}

void func_808008F4_chfiregen();

// Torch update: burn timer, flare-ups, smoke and fire sound.
void func_808000EC_chfiregen(Actor *actor)
{
    extern u8 D_80801570_chfiregen[];
    extern s16 D_80801580_chfiregen[];

    f32 flare_timer;
    f32 dt;
    s32 model;
    s32 unk_0;

    dt = func_800D9004();

    _sudeflect_entrypoint_1(actor->position, 80.0f, 0, 75.0f, 10);

    if (actor->unk64_19) {
        ((f32 *) actor->actorData)[0] -= dt;

        if (((f32 *) actor->actorData)[0] < 0.0f) {
            ((f32 *) actor->actorData)[0] = 0.0;
            actor->unk64_19 = 0;
        }
    } else {
        ((f32 *) actor->actorData)[0] += dt;

        if (((f32 *) actor->actorData)[0] > 0.3f) {
            ((f32 *) actor->actorData)[0] = 0.3f;
            actor->unk64_19 = 1;
        }
    }

    actor->unk79_4 = (s32) func_800F10B4(((f32 *) actor->actorData)[0], 0.0, 0.3f, 0.0f, 4.49f);

    if (dt < actor->unk58) {
        actor->unk58 -= dt;
    } else {
        actor->unk58 = 0.0f;
        ((f32 *) actor->actorData)[5] = 0.0f;
    }

    actor->unk6C_0++;

    switch (actor->unk70_10) {
        case 2:
            if (((f32 *) actor->actorData)[6] <= 0.95f) {
                ((f32 *) actor->actorData)[6] += 0.05f;
            }

            if (((f32 *) actor->actorData)[7] <= (1.0f - 0.16f)) {
                ((f32 *) actor->actorData)[7] += 0.16f;
            }

            actor->unk54 += 0.0075f;

            if (actor->unk54 > (f32) 1.0) {
                actor->unk54 = 1.0;
            }

            if (actor->unk54 < 0.6f) {
                actor->unk54 = 0.6f;
            }

            if (actor->unk5F == 0) {
                actor->unk5F = func_800C4350(0, actor->position, D_80801580_chfiregen);
            }

            func_800C31DC(actor->unk5F, actor->unk54);

            func_800C4350(actor->unk5F, 0, 0);

            if (actor->unk58 <= 0.0f) {
                _subaddieaudioloop_entrypoint_2(actor);
                func_808008F4_chfiregen((s32 *) actor, 0);

                actor->unk70_10 = 1;
            }

            if (func_800DC0C0() < 0.005f) {
                actor->unk70_10 = 3;

                actor->rotation[0] = 1.0f;

                func_808008F4_chfiregen((s32 *) actor, 0);
                func_80101CDC(actor, 0.7f);
            }

            if (func_800DC0C0() < 0.08f && func_80101E14(actor, 0.1f)) {
                func_80800B4C_chfiregen(actor, 3);

                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801570_chfiregen);
            }

            if (func_800DC0C0() < 0.25f) {
                func_80800B4C_chfiregen(actor, 1);
            }
            break;
        case 1:
            if (((f32 *) actor->actorData)[6] > 0.02f) {
                ((f32 *) actor->actorData)[6] -= 0.02f;
            }

            if (((f32 *) actor->actorData)[7] >= 0.16f) {
                ((f32 *) actor->actorData)[7] -= 0.16f;
            }

            if (actor->unk58 != 0.0f) {
                func_808008F4_chfiregen((s32 *) actor, 1);

                actor->unk70_10 = 2;

                func_80101CDC(actor, 0.4f);
                actor->unk54 = 0.6f;
            }

            flare_timer = func_80101D0C(actor);

            if (flare_timer != 10000000.0f) {
                actor->unk54 -= 0.02f;

                if (actor->unk54 < 0.6f) {
                    actor->unk54 = 0.6f;
                }

                if (actor->unk5F == 0) {
                    actor->unk5F = func_800C4350(0, actor->position, D_80801580_chfiregen);
                }
                func_800C31DC(actor->unk5F, actor->unk54);

                func_800C4350(actor->unk5F, 0, 0);

                flare_timer += func_800DC178(0.05f, 0.15f);

                if (flare_timer > 4.0f) {
                    func_80800B4C_chfiregen(actor, 3);

                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80801570_chfiregen);

                    flare_timer = 10000000.0f;

                    _subaddieaudioloop_entrypoint_2(actor);
                }

                func_80101CDC(actor, flare_timer);
            }
            break;
        case 3:
            if (((f32 *) actor->actorData)[6] > 0.02f) {
                ((f32 *) actor->actorData)[6] -= 0.02f;
            }

            if (((f32 *) actor->actorData)[7] >= 0.16f) {
                ((f32 *) actor->actorData)[7] -= 0.16f;
            }

            if (func_800DC0C0() < 0.03f && func_80101E14(actor, 0.1f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801570_chfiregen);
            }

            if (actor->unk54 < 0.6f) {
                actor->unk54 = 0.6f;
            }

            if (actor->unk5F == 0) {
                actor->unk5F = func_800C4350(0, actor->position, D_80801580_chfiregen);

            } else {
                func_800C31DC(actor->unk5F, actor->unk54 - 0.2f);

                func_800C4350(actor->unk5F, 0, 0);
            }

            actor->unk70_10 = 2;

            func_808008F4_chfiregen((s32 *) actor, 1);
    }

    if (actor->rotation[2] != ((f32 *) actor->actorData)[6] && (s32) actor->unk50 != -1) {
        if (((f32 *) actor->actorData)[3] < 0.0f) {
            actor->rotation[2] = ((f32 *) actor->actorData)[6];
            ((f32 *) actor->actorData)[3] = 0.25f;
        } else {
            ((f32 *) actor->actorData)[3] -= dt;
        }
    }

    if (((f32 *) actor->actorData)[7] > 0.02f) {
        model = func_801039E4(actor->unk0);

        unk_0 = func_80103CB8(actor, model);

        _dbmorph_entrypoint_3(func_800B2768(model), unk_0, func_800B2840(model), 1,
                              &((f32 *) actor->actorData)[7]);
    }
}

// Torch actor id -> scratch flag index (0..5).
s32 func_80800824_chfiregen(actor)
Actor *actor;
{
    switch (actor->unk6C_9) {
        case 0x1AA:
            return 0;
        case 0x1AC:
            return 1;
        case 0x1AE:
            return 2;
        case 0x1B0:
            return 3;
        case 0x1B2:
            return 4;
        case 0x1B4:
            return 5;
    }
    return 0;
}

// Torch actor id -> cutscene index, -1 if none.
s32 func_80800890_chfiregen(actor)
Actor *actor;
{
    switch (actor->unk6C_9) {
        case 0x1AA:
            return 0;
        case 0x1AC:
            return 5;
        case 0x1AE:
            return 8;
        case 0x1B0:
            return 11;
        case 0x1B2:
            return 15;
        default:
            return -1;
    }
}

// Sets the torch's flag; the first lighting also plays the camera cutscene (flag 0x678).
void func_808008F4_chfiregen(s32 *actor, s32 state)
{
    s32 cutscene;

    func_800DA3B8(func_80800824_chfiregen((Actor *) actor), state);
    if ((state != 0) && (func_800DA298(0x678) == 0)) {
        cutscene = func_80800890_chfiregen(actor);
        if (cutscene != -1) {
            func_800DA3B8(0x678, 1);
            _capod_entrypoint_13(*actor, 0, cutscene, 0x10);
        }
    }
}

// Hit: lights the torch if the attacker is class 0x26D; burn time is (id - 50) s, 1.5x when relit quickly.
void func_80800978_chfiregen(actor, attacker) Actor *actor;
void *attacker;
{
    if ((*(u32 *) ((u8 *) attacker + 0x24) >> 22) == 0x26D) {
        if ((s32) *(f32 *) &actor->actorData[5] == 0) {
            actor->unk6C_0 = 0;
        }
        if ((s32) *(f32 *) &actor->actorData[5] < 2) {
            *(f32 *) &actor->actorData[5] += 1.0f;
            actor->unk58 = (s32) actor->unk74_7 - 50;
        } else if ((s32) *(f32 *) &actor->actorData[5] == 2) {
            *(f32 *) &actor->actorData[5] += 1.0f;
            if (actor->unk6C_0 < 40) {
                func_800FC63C(14, 0x7FBC);
                actor->unk58 = ((s32) actor->unk74_7 - 50) * 1.5f;
            }
        }
    }
}

void func_80800A78_chfiregen(Actor *actor)
{
    actor->scale = 3.0f;
    actor->unk50 = -1.0f;
    actor->unk64_20 = 0;
    ((f32 *) actor->actorData)[3] = func_800DC178(0.0f, 0.25f);
    ((f32 *) actor->actorData)[0] = func_800DC178(0.0f, 1.0f);
    actor->unk64_19 = func_800DC298(0.5f);
    if (func_800DA298(func_80800824_chfiregen(actor))) {
        actor->unk58 = (s32) actor->unk74_7 - 0x32;
        ((FireGeneratorMode *) actor)->local_0 = 2;
    }
}

// Spawns a smoke particle emitter.
void func_80800B4C_chfiregen(actor, param_1) Actor *actor;
s32 param_1;
{
    void *emitter;
    f32 pos[3];

    if (actor->unk7C_12) {
        func_800DBEFC(actor->unk0->unk4, 4, pos);
        pos[1] -= 100.0f;
        emitter = func_800B53A4(param_1);
        func_800BA3FC(emitter, func_800DC298(0.7f) ? 0x9DC : 0x9CA);
        func_800BABB8(emitter, pos, NULL, 1.0f, D_80801784_chfiregen);
        func_800BA22C(emitter, param_1);
    }
}

void *chfiregen_entrypoint_6(void)
{
    return &D_808017BC_chfiregen;
}

s32 chfiregen_entrypoint_7()
{
    return D_80801804_chfiregen;
}

int chfiregen_entrypoint_8()
{
    return (int) &D_8080184C_chfiregen;
}

int *chfiregen_entrypoint_9()
{
    return &D_80801894_chfiregen;
}

int chfiregen_entrypoint_10()
{
    return (int) &D_808018DC_chfiregen;
}

s32 chfiregen_entrypoint_11()
{
    return D_80801924_chfiregen;
}

// Light actor update: fades the dynamic light in or out from the torch flag.
void func_80800C44_chfiregen(Actor *actor)
{
    f32 dt;
    s32 i;
    s32 color[3];

    dt = func_800D8FF8();
    if (*(f32 *) &actor->actorData[3] > 0.0f) {
        *(f32 *) &actor->actorData[3] -= dt;
        return;
    }
    if (func_800DA298(actor->unk6C_0)) {
        if (actor->unk70_10 != 3) {
            actor->unk70_10 = 2;
        }
    } else {
        if (actor->unk70_10 != 1) {
            actor->unk70_10 = 4;
        }
    }
    switch (actor->unk70_10) {
        case 2:
            if (*(f32 *) &actor->actorData[6] <= 0.85f) {
                *(f32 *) &actor->actorData[6] += 0.15f;
            } else {
                actor->unk70_10 = 3;
            }
            break;
        case 4:
            if (*(f32 *) &actor->actorData[6] >= 0.08f) {
                *(f32 *) &actor->actorData[6] -= 0.08f;
            } else {
                actor->unk70_10 = 1;
            }
    }
    if (actor->rotation[2] != *(f32 *) &actor->actorData[6]) {
        for (i = 0; i < 3; i++) {
            color[i] =
                (s32) (((f32 *) actor->actorData)[i] * *(f32 *) &actor->actorData[6]);
        }
        func_800C8E84((s32) actor->unk50, color);
        actor->rotation[2] = *(f32 *) &actor->actorData[6];
        *(f32 *) &actor->actorData[3] = 0.15f;
    }
}

void func_80800E54_chfiregen(Actor *actor)
{
    f32 color[3];
    if ((s32) actor->unk50 != -1) {
        func_800EE904(color, (u8 *) actor + 0x18);
        func_800C8E84((s32) actor->unk50, color);
    }
}

// Light actor init: picks the flag index from the actor id and creates the light.
void func_80800EB8_chfiregen(Actor *actor)
{
    s32 light;
    f32 light_color[3];
    s32 color[3];

    *(f32 *) &actor->actorData[3] = func_800DC178(0.0f, 0.15f);
    actor->unk50 = -1.0f;
    switch (actor->unk6C_9) {
        case 0x1AB:
            actor->unk6C_0 = 0;
            break;
        case 0x1AD:
            actor->unk6C_0 = 1;
            break;
        case 0x1AF:
            actor->unk6C_0 = 2;
            break;
        case 0x1B1:
            actor->unk6C_0 = 3;
            break;
        case 0x1B3:
            actor->unk6C_0 = 4;
            break;
        case 0x1B5:
            actor->unk6C_0 = 5;
            break;
    }
    light = func_800C9128(actor->position);
    actor->unk50 = (f32) light;
    func_800C8800(light, light_color);
    func_800EE7F8((f32 *) actor->actorData, light_color);
    func_800C8900(light, color);
    func_800EE84C((f32 *) actor->actorData, color);
    func_800EFA88(color, 0, 0, 0);
    func_800C8E84((s32) actor->unk50, color);
}

int chfiregen_entrypoint_12()
{
    return &D_8080196C_chfiregen;
}

int chfiregen_entrypoint_13()
{
    return (int) &D_808019B4_chfiregen;
}

int chfiregen_entrypoint_14()
{
    return (int) &D_808019FC_chfiregen;
}

int chfiregen_entrypoint_15()
{
    return (int) D_80801A44_chfiregen;
}

int chfiregen_entrypoint_16()
{
    return (int) D_80801A8C_chfiregen;
}

int chfiregen_entrypoint_17()
{
    return &D_80801AD4_chfiregen;
}

// Mesh group animator for this mesh-glow variant.
void *func_8080105C_chfiregen(u8 *actor)
{
    s32 group_id;
    u32 actor_id;

    actor_id = (u32) (*(s32 *) ((s8 *) actor + 0x6C) << 0xB) >> 0x14;
    switch (actor_id) {
        case 0x2AA:
            group_id = 0x1AD;
            break;
        case 0x2AB:
            group_id = 0x1AE;
    }
    return _idworld_entrypoint_3(group_id);
}

// Second mesh group animator for this mesh-glow variant.
void *func_808010B4_chfiregen(void *actor)
{
    s32 group_id;
    u32 actor_id;

    actor_id = (u32) (*(s32 *) ((s8 *) actor + 0x6C) << 0xB) >> 0x14;
    switch (actor_id) {
        case 0x2AA:
            group_id = 0x1B0;
            break;
        case 0x2AB:
            group_id = 0x1B1;
    }
    return _idworld_entrypoint_3(group_id);
}

// Mesh-glow actor update: fades the map-mesh colour groups in or out from the torch flag.
void func_8080110C_chfiregen(Actor *actor)
{
    f32 dt;
    void *mesh;
    f32 glow[4];

    dt = func_800D8FF8();
    if (((f32 *) actor->actorData)[3] > 0.0f) {
        ((f32 *) actor->actorData)[3] -= dt;
    } else {
        if (func_800DA298(actor->unk6C_0)) {
            if (actor->unk70_10 != 3) {
                actor->unk70_10 = 2;
            }
        } else if (actor->unk70_10 != 1) {
            actor->unk70_10 = 4;
        }
        switch (actor->unk70_10) {
            case 2:
                if (((f32 *) actor->actorData)[6] <= 0.85f) {
                    ((f32 *) actor->actorData)[6] += 0.15f;
                } else {
                    actor->unk70_10 = 3;
                }
                break;
            case 4:
                if (((f32 *) actor->actorData)[6] >= 0.08f) {
                    ((f32 *) actor->actorData)[6] -= 0.08f;
                } else {
                    actor->unk70_10 = 1;
                }
        }
        if (actor->rotation[2] != ((f32 *) actor->actorData)[6]) {
            glow[0] = ((f32 *) actor->actorData)[6];
            glow[1] = ((f32 *) actor->actorData)[6];
            glow[2] = ((f32 *) actor->actorData)[6];
            glow[3] = ((f32 *) actor->actorData)[6];
            mesh = func_8080105C_chfiregen(actor);
            if (mesh) {
                func_800EDDDC(mesh, glow, glow, 5.0f);
            }
            mesh = func_808010B4_chfiregen(actor);
            if (mesh) {
                func_800EDDDC(mesh, glow, glow, 5.0f);
            }
            actor->rotation[2] = ((f32 *) actor->actorData)[6];
            ((f32 *) actor->actorData)[3] = 0.15f;
        }
    }
}

void func_808012F8_chfiregen(s32 actor)
{
}

void func_80801300_chfiregen(Actor *actor)
{
    void *mesh;
    f32 glow[4];

    glow[0] = *(f32 *) ((u8 *) actor + 0x30);
    glow[1] = *(f32 *) ((u8 *) actor + 0x30);
    glow[2] = *(f32 *) ((u8 *) actor + 0x30);
    glow[3] = *(f32 *) ((u8 *) actor + 0x30);
    *(f32 *) ((u8 *) actor + 0x24) = func_800DC178(0.0f, 0.15f);
    switch (actor->unk6C_9) {
        case 0x2A7:
            actor->unk6C_0 = 0;
            break;
        case 0x2A8:
            actor->unk6C_0 = 1;
            break;
        case 0x2A9:
            actor->unk6C_0 = 2;
            break;
        case 0x2AA:
            actor->unk6C_0 = 3;
            break;
        case 0x2AB:
            actor->unk6C_0 = 4;
            break;
        case 0x2AC:
            actor->unk6C_0 = 5;
            break;
    }
    mesh = (void *) func_8080105C_chfiregen(actor);
    if (mesh)
        func_800EDDDC(mesh, glow, glow, 5.0f);
    mesh = (void *) func_808010B4_chfiregen(actor);
    if (mesh)
        func_800EDDDC(mesh, glow, glow, 5.0f);
}

// TU-NOTE: the overlay .data is defined here in C. Its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless defined in the same unit.
// Values are from the ROM. The D_8080... table externs at the top are declared as arrays to match the object.
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_8010A730();
u8 D_80801570_chfiregen[16] = {0x0, 0x13, 0x4, 0xB5, 0x0, 0xD, 0x0, 0xE6,
                               0x1, 0x19, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
s16 D_80801580_chfiregen[10] = {0x206, 0x13, 0x4B4, 0x16, 0x61A8, 0x1, 0x1F4, 0x1388, 0x0, 0x0};
u32 D_80801594_chfiregen[8] = {0x0,        0x0,       0x4B189680, 0x1D80000,
                               0x3ECCCCCD, 0x1D80000, 0x3F19999A, 0x1D80000};
int D_808015B4_chfiregen[18] = {0x24401AA,
                                0x66C0001,
                                (u32) &D_80801594_chfiregen,
                                (u32) func_808000EC_chfiregen,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x0,
                                0x0,
                                0x0,
                                0x880044,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800A78_chfiregen,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800000_chfiregen,
                                0x0};
int D_808015FC_chfiregen[18] = {0x24401AC,
                                0x66C0001,
                                (u32) &D_80801594_chfiregen,
                                (u32) func_808000EC_chfiregen,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x0,
                                0x0,
                                0x0,
                                0x880044,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800A78_chfiregen,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800000_chfiregen,
                                0x0};
int D_80801644_chfiregen[18] = {0x24401AE,
                                0x66C0001,
                                (u32) &D_80801594_chfiregen,
                                (u32) func_808000EC_chfiregen,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x0,
                                0x0,
                                0x0,
                                0x880044,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800A78_chfiregen,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800000_chfiregen,
                                0x0};
s32 D_8080168C_chfiregen[18] = {0x24401B0,
                                0x66C0001,
                                (u32) &D_80801594_chfiregen,
                                (u32) func_808000EC_chfiregen,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x0,
                                0x0,
                                0x0,
                                0x880044,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800A78_chfiregen,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800000_chfiregen,
                                0x0};
int D_808016D4_chfiregen[18] = {0x24401B2,
                                0x66C0001,
                                (u32) &D_80801594_chfiregen,
                                (u32) func_808000EC_chfiregen,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x0,
                                0x0,
                                0x0,
                                0x880044,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800A78_chfiregen,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800000_chfiregen,
                                0x0};
int D_8080171C_chfiregen[26] = {0x24401B4,
                                0x66C0001,
                                (u32) &D_80801594_chfiregen,
                                (u32) func_808000EC_chfiregen,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x0,
                                0x0,
                                0x0,
                                0x880044,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800A78_chfiregen,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800000_chfiregen,
                                0x0,
                                0xFF,
                                0xFF,
                                0xFF,
                                0x64,
                                0x28,
                                0x0,
                                0x42C80000,
                                0x43960000};
u8 D_80801784_chfiregen[56] = {0x0, 0x19, 0x0, 0x1,  0x0, 0x6, 0x23, 0x2,  0x0, 0x2C, 0x0, 0x0,
                               0x0, 0x60, 0x0, 0x0,  0x0, 0x0, 0x0,  0xD8, 0x0, 0x0,  0x0, 0x22,
                               0x1, 0xA,  0x1, 0xEB, 0x2, 0x0, 0x3,  0x99, 0x0, 0x2A, 0x0, 0x0,
                               0x0, 0x2,  0x4, 0x0,  0x7, 0x0, 0x0,  0x15, 0x0, 0x4C, 0x0, 0xB3,
                               0x0, 0x16, 0x0, 0x4,  0x0, 0x0, 0x0,  0x0};
int D_808017BC_chfiregen[18] = {0x24501AB,
                                0x4,
                                0x0,
                                (u32) func_80800C44_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800E54_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80800EB8_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
s32 D_80801804_chfiregen[18] = {0x24501AD,
                                0x4,
                                0x0,
                                (u32) func_80800C44_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800E54_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80800EB8_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_8080184C_chfiregen[18] = {0x24501AF,
                                0x4,
                                0x0,
                                (u32) func_80800C44_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800E54_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80800EB8_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_80801894_chfiregen[18] = {0x24501B1,
                                0x4,
                                0x0,
                                (u32) func_80800C44_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800E54_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80800EB8_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_808018DC_chfiregen[18] = {0x24501B3,
                                0x4,
                                0x0,
                                (u32) func_80800C44_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800E54_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80800EB8_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
s32 D_80801924_chfiregen[18] = {0x24501B5,
                                0x4,
                                0x0,
                                (u32) func_80800C44_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800E54_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80800EB8_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_8080196C_chfiregen[18] = {0x20702A7,
                                0x4,
                                0x0,
                                (u32) func_8080110C_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_808012F8_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80801300_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_808019B4_chfiregen[18] = {0x20702A8,
                                0x4,
                                0x0,
                                (u32) func_8080110C_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_808012F8_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80801300_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_808019FC_chfiregen[18] = {0x20702A9,
                                0x4,
                                0x0,
                                (u32) func_8080110C_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_808012F8_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80801300_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
int D_80801A44_chfiregen[18] = {0x20702AA,
                                0x4,
                                0x0,
                                (u32) func_8080110C_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_808012F8_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80801300_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
s32 D_80801A8C_chfiregen[18] = {0x20702AB,
                                0x4,
                                0x0,
                                (u32) func_8080110C_chfiregen,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x0,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_808012F8_chfiregen,
                                0x0,
                                0x0,
                                (u32) func_80801300_chfiregen,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0};
void *D_80801AD4_chfiregen = (void *) 0x020702AC;
static u32 D_80801AD4_chfiregen_rest[18] = {0x4,
                                            0x0,
                                            (u32) func_8080110C_chfiregen,
                                            (u32) func_80105834,
                                            (u32) func_8010A730,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x80004,
                                            (u32) func_808012F8_chfiregen,
                                            0x0,
                                            0x0,
                                            (u32) func_80801300_chfiregen,
                                            (u32) func_80107C2C,
                                            0x80000002,
                                            0x0,
                                            0x0,
                                            0x0};
