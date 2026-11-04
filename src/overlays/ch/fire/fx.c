#include "common.h"

extern void *D_80801200_chfirefx;
extern int D_80801248_chfirefx[];
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 25;
    u32 unk_74 : 1;
    u32 pad_2 : 6;
} FireFxSpawnFlags;
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 pad_0[0x14];
    u16 sound_near;
    u16 sound_far;
} FireFxData_80800AA8_chfirefx;
extern s16 D_80801290_chfirefx[];
extern s32 func_800DA298(s32);
extern void func_8010D640(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C3584(u8, f32, f32);
extern void func_800C3BDC();
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern Actor *_subaddielink_entrypoint_4(void *);
typedef struct {
    s32 max_audible;
    s32 count;
    struct {
        u32 words[2];
    } links[16];
} FireFxResetLinks;
typedef struct {
    s32 max_audible;
    s32 count;
    s32 links[1][2];
} FireFxLocal;
extern void func_80103110(Actor *, s32);
extern void func_8010D254(f32 *);
typedef struct {
    s32 unk_0;
    s32 count;
    u32 links[1][2];
} FireFxLinks;
extern void _subaddielink_entrypoint_1();
extern void *func_80100074(Actor *, s32, s32);
typedef struct {
    u8 pad_0[4];
    f32 scale;
    s16 count;
    s16 limit;
    s16 capacity;
    s16 slow_spawn;
    s16 flags;
    s16 size;
    u16 sound_near;
    u16 sound_far;
    void *link[2];
} FireEffectState961;
typedef struct {
    f32 frame;
    s16 rise_speed;
    s16 flip;
    s16 pos_x;
    s16 pos_y;
    s16 pos_z;
    s16 unk_E;
    s32 scale;
} FirePart;
typedef struct {
    u8 pad_0[4];
    f32 scale;
    s16 count;
    s16 limit;
    s16 capacity;
    s16 pad_E;
    u16 flags;
    s16 size;
    u8 pad_14[0xC];
    FirePart parts[1];
} FireData;
extern s32 func_800F54E4(void);
extern u8 func_800D9078(f32 *);
extern s32 func_800F6438(s32);
extern s32 func_800F6AA4(s32);
extern s32 func_800F6478(s32);
extern s32 func_8010CEF8(Actor *, s32);
extern s32 func_800F7B9C(s32, s32);
extern void _chhotwaterpoolbits_entrypoint_5(Actor *, f32);
extern f32 func_800D8FF8(void);
extern void rare_memcpy(void *, void *, s32);
extern void func_800EE88C();
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800E2588();
extern void func_800E2594();
extern void func_800E2A14();
extern f32 func_800F0E00(f32, f32);
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
typedef struct {
    f32 frame;
    s16 rise_speed;
    s16 flip;
    s16 pos[3];
    s16 unk_E;
    f32 scale;
} FireParticle48;
typedef struct {
    u8 pad_0[4];
    f32 scale;
    s16 count;
    s16 limit;
    u8 pad_C[2];
    s16 slow_spawn;
    u8 pad_10[2];
    s16 size;
    u8 pad_14[0xC];
    FireParticle48 particles[1];
} FireFxData_80800884_chfirefx;
extern void func_800EE940();
extern u8 D_808012A8_chfirefx[];
extern s32 func_800C8A98(void);
extern void func_800C8E54(s32, f32, f32);
extern s32 func_800F2F60(s32 *, s32 *, f32);
extern s32 func_8010CAC0(f32 *, s32);
extern s32 _subaddiezone_entrypoint_1(Actor *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
typedef struct {
    u32 pad_0 : 26;
    u32 unk_74 : 1;
    u32 pad_1 : 5;
} Broad51FireFlags;
void func_8080116C_chfirefx();
void chfirefx_entrypoint_2(Actor *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4);
s32 func_80800884_chfirefx();
void func_80800C18_chfirefx();

int chfirefx_entrypoint_0()
{
    return &D_80801200_chfirefx;
}

int chfirefx_entrypoint_1()
{
    return D_80801248_chfirefx;
}

// Spawn entrypoint: reads the spawn parameters off the actor.
void func_80800018_chfirefx(Actor *actor)
{
    s32 flags;
    flags = 0xD;
    if (((FireFxSpawnFlags *) actor)->unk_74) {
        flags = 0x2D;
    }
    ((FireFxSpawnFlags *) actor)->unk_74 = 0;
    chfirefx_entrypoint_2(actor, actor->scale, (f32) actor->unk74_7,
                          (s32) actor->rotation[1], flags);
}

// Init: allocates the particle pool and links this fire to the sound limiter.
void chfirefx_entrypoint_2(Actor *actor, f32 scale, f32 size, s32 capacity, s32 flags)
{
    FireEffectState961 *data;
    Actor *limiter;

    data = func_80100074(actor, 0, capacity * 0x14 + 0x20);
    data->capacity = capacity;
    data->count = 0;
    data->limit = data->count;
    data->slow_spawn = 0;
    data->scale = scale;
    data->flags = flags;
    data->size = (s32) size;
    data->sound_near = (u32) (scale * 150.0f);
    data->sound_far = (u32) (scale * 850.0f);
    if ((flags & 8) && size <= 70.0f) {
        data->slow_spawn = 1;
    }
    if (flags & 0x10) {
        data->slow_spawn = 1;
    }
    limiter = _subaddiefind_entrypoint_2(0x289, 0);
    _subaddielink_entrypoint_1(data->link, limiter != NULL ? limiter->unk0 : NULL);
    actor->unk64_20 = func_800EA05C() == 0xED;
}

void func_80800E9C_chfirefx();

// Update: ramps the particle limit, spawns/ages/moves particles, updates light and sound.
void chfirefx_entrypoint_3(Actor *actor)
{
    s32 i;
    FireData *data;
    s32 player;
    f32 dt;
    f32 rates[2];
    FirePart *part;
    f32 scaled_dt;
    FirePart *parts;
    // Matching: the u32 holder keeps 2 in s1; s32 or a literal is worse.
    u32 k0 = 2;
    f32 pos[1];
    f32 push[3];

    data = func_80100094(actor, 0);
    player = func_800F54E4();
    func_800D9078(&actor->unk58);
    switch (actor->unk70_10) {
        case 2:
            data->limit += 2;
            if (data->limit >= data->capacity) {
                data->limit = data->capacity;
            }
            if ((data->flags & 4) && func_800F6438(player) && !func_800F6AA4(player) &&
                func_800F6478(player) && func_8010CEF8(actor, data->size) &&
                k0 == func_800F7B9C(player, 0x51)) {
                _chhotwaterpoolbits_entrypoint_5(actor, 0.75f);
            }
            break;
        case 1:
            data->limit -= 2;
            if (data->limit < 0) {
                data->limit = 0;
            }
    }
    if (func_80800884_chfirefx(actor)) {
        dt = func_800D8FF8();
        scaled_dt = data->scale * dt;
        rates[1] = scaled_dt * 50.0f;
        rates[0] = scaled_dt * 400.0f;
        part = parts = data->parts;
        for (i = 0; i < data->count;) {
            part->frame += dt * 15.0f;
            if ((s32) part->frame >= 9) {
                data->count--;
                if (data->count > 0) {
                    rare_memcpy(part, &parts[data->count], 0x14);
                }
                continue;
            } else {
                part->rise_speed += rates[0];
                part->pos_y += dt * part->rise_speed;
                func_800EE88C(pos, &part->pos_x);
                func_800EF04C(pos, actor->position);
                if ((0.4f * data->size) * (0.4f * data->size) <
                    func_800EFC7C(pos, actor->position)) {
                    func_800EFB24(push, actor->position, pos);
                    push[1] = 0.0f;
                    func_800EF368(push, rates[1]);
                    part->pos_x += push[0];
                    part->pos_z += push[2];
                }
                part++;
                i++;
            }
        }
    }
    if (data->flags & 1) {
        func_80800C18_chfirefx(actor);
    }
    func_80800E9C_chfirefx(actor);
}

// Draw: culls by view, then draws every particle as a sprite.
void chfirefx_entrypoint_4(Actor *actor, s32 gfx)
{
    f32 size;
    u8 *data;
    u8 *part;
    f32 *pos;
    f32 part_pos[3];
    f32 part_scale[3];
    s32 i;
    s32 sprite;
    data = func_80100094(actor, 0);
    pos = actor->position;
    if (!func_800E3E8C(pos, (func_800F0E00(75.0f, *(s16 *) (data + 0x12)) * 2.5f) * 0.6f)) {
        return;
    }
    actor->unk7C_12 = 1;
    if (*(s16 *) (data + 8)) {
        part = data + 0x20;
        sprite = func_800D674C(0x9CE);
        func_800E2588(1);
        func_800E2594(gfx, sprite);
        func_800E24D8(1);
        for (i = 0; i < *(s16 *) (data + 8); i++, part += 0x14) {
            size = (*(f32 *) (data + 4) * *(f32 *) (part + 0x10)) * 0.5f;
            func_800EE88C(part_pos, part + 8);
            func_800EF04C(part_pos, pos);
            func_800EFA4C(part_scale, size, size, size);
            func_800E2720(gfx, (s32) *(f32 *) part, *(s16 *) (part + 6), part_pos,
                          part_scale, 0xC0);
        }
        func_800E2A14(gfx);
    }
}

s32 chfirefx_entrypoint_5(Actor *actor, s32 msg, s32 unk_2)
{
    u8 *data;

    switch (msg) {
        case 0x95:
            data = func_80100094(actor, 0);
            _subaddielink_entrypoint_3(data + 0x18);
            *(s32 *) data = 0;
            if (*(u16 *) (data + 0x10) & 1) {
                func_80800C18_chfirefx(actor);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Sets the radii used for the fire sound.
void chfirefx_entrypoint_6(actor, sound_near, sound_far) s32 actor;
s16 sound_near;
s16 sound_far;
{
    u8 *data = func_80100094(actor, 0);
    *(s16 *) (data + 0x14) = sound_near;
    *(s16 *) (data + 0x16) = sound_far;
}

// Spawns up to 2 new particles per call while below the current limit.
s32 func_80800884_chfirefx(actor)
Actor *actor;
{
    FireFxData_80800884_chfirefx *data;
    FireParticle48 *particle;
    f32 cam_pos[3];
    s32 offset[3];
    s32 spawned;
    f32 angle;
    f32 angle_jitter;

    data = func_80100094(actor, 0);
    spawned = 0;

    if (data->count >= data->limit) {
        return 1;
    }

    if (data->slow_spawn == 1) {
        if (actor->unk58 != 0.0f) {
            return 1;
        }
        actor->unk58 = 0.06f;
    }

    func_800E3980(cam_pos);

    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    while (data->count < data->limit && spawned < 2) {
        particle = &data->particles[data->count];
        particle->frame = 0.0f;
        particle->rise_speed = (s32) (data->scale * func_800DC128(30, 40));
        particle->scale = func_800DC178(0.8f, 1.2f);
        particle->flip = func_800DC298(0.5f);
        angle = func_800F1DF4(actor->position, cam_pos);
        angle_jitter = func_800DC178(-90.0f, 90.0f);
        func_800EEB9C((f32 *) offset, angle_jitter + angle,
                      func_800DC178(data->size * 0.25f, data->size));
        func_800EE940(particle->pos, offset);
        data->count++;
        spawned++;
    }

    return 1;
}

// Starts or stops the looping fire sound depending on state and distance to the camera.
void func_80800AA8_chfirefx(Actor *actor)
{
    FireFxData_80800AA8_chfirefx *data;
    f32 cam_pos[3];
    s32 audible;

    data = func_80100094(actor, 0);
    audible = (actor->unk70_10 == 2);

    if (actor->unk64_20) {
        audible &= (func_800DA298(0) == 0);
    }

    func_8010D640(cam_pos);

    if (audible &&
        (f32) (data->sound_far * data->sound_far) < func_800EEB40(cam_pos, actor->position)) {
        audible = 0;
    }

    if (audible) {
        if (actor->unk5F == 0) {
            actor->unk5F = func_800C4350(actor->unk5F, actor->position, D_80801290_chfirefx);
        }
        if (actor->unk5F) {
            func_800C4350(actor->unk5F, actor->position, NULL);
            func_800C3584(actor->unk5F, (f32) (u32) data->sound_near, (f32) (u32) data->sound_far);
            func_800C3BDC(actor->unk5F);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(actor);
    }
}

// Creates, moves, colors and fades the flickering point light.
void func_80800C18_chfirefx(actor) Actor *actor;
{
    u8 *data;
    f32 light_pos[3];
    s32 created;
    s32 visible;
    s32 light_type;
    s32 color[3];

    data = func_80100094(actor, 0);
    created = 0;
    if (*(s16 *) (data + 8) == 0) {
        if (*(s32 *) data) {
            *(s32 *) data = _chlightfader_entrypoint_1(*(s32 *) data, 1.6f, 1);
        }

    } else {
        if (*(s32 *) data == 0) {
            light_type = 9;
            *(s32 *) data = func_800C8A98();
            if (!(*(u16 *) (data + 0x10) & 0x20)) {
                light_type = 11;
            }
            func_800C8F64(*(s32 *) data, light_type);
            func_800C8E54(*(s32 *) data, func_800F0E00(75.0f, *(s16 *) (data + 0x12)) * 2.5f,
                          (func_800F0E00(75.0f, *(s16 *) (data + 0x12)) * 2.5f) * 3.0f);
            func_800EE7F8(light_pos, actor->position);
            light_pos[1] += *(s16 *) (data + 0x12) * 0.4f;
            func_800C8CB8(*(s32 *) data, light_pos);
            created = 1;
        }

        visible =
            ((*(u32 *) ((u8 *) actor + 0x7C) << 19) >> 31) ||
            func_8010CAC0(actor->position,
                          (s32) ((func_800F0E00(75.0f, *(s16 *) (data + 0x12)) * 2.5f) * 3.0f));

        if (*((u8 *) actor + 0x78)) {
            if (!_subaddiezone_entrypoint_1(actor)) {
                visible = 0;
            }
        }

        if (created || visible) {
            if (!((Broad51FireFlags *) ((u8 *) actor + 0x74))->unk_74) {
                func_800EE7F8(light_pos, actor->position);
                light_pos[1] += *(s16 *) (data + 0x12) * 0.4f;
                func_800C8CB8(*(s32 *) data, light_pos);
            }
            func_800F2F60(color, (s32 *) D_808012A8_chfirefx, func_800DC178(0.8f, 1.0f));
            func_800C8E84(*(s32 *) data, color);
        }
    }
}

// Registers with the sound limiter if one is linked, otherwise handles sound itself.
void func_80800E9C_chfirefx(Actor *actor)
{
    Actor *limiter;

    limiter = _subaddielink_entrypoint_4((u8 *) func_80100094(actor, 0) + 0x18);
    if (limiter == NULL || actor->unk70_10 != 2) {
        func_80800AA8_chfirefx(actor);
    } else {
        func_8080116C_chfirefx(limiter, actor);
    }
}

void func_80800F00_chfirefx(Actor *actor)
{
    FireFxResetLinks *data;
    s32 i;
    data = func_80100094(actor, 0);
    for (i = 0; i < 16; i++) {
        _subaddielink_entrypoint_0(&data->links[i]);
    }
    data->count = 0;
    data->max_audible = (s32) actor->rotation[1];
}

// Sound limiter: only the nearest max_audible linked fires get to play their sound.
void func_80800F7C_chfirefx(Actor *actor)
{
    Actor *fires[16];
    s32 i;
    s32 j;
    s32 num;
    f32 dist[16];
    f32 cam_pos[3];
    FireFxLocal *data;
    f32 tmp_dist;
    Actor *tmp_actor;

    data = func_80100094(actor, 0);
    for (i = 0, num = 0; i < data->count; i++) {
        fires[num] = _subaddielink_entrypoint_4(data->links[i]);

        if (fires[num] != NULL) {
            num++;
        }
    }
    func_80103110(actor, 0);
    data->count = 0;
    if (num == 0) {
        return;
    }
    if (data->max_audible >= num) {
        for (i = 0; i < num; i++) {
            func_80800AA8_chfirefx(fires[i]);
        }
        return;
    }
    func_8010D254(cam_pos);
    for (i = 0; i < num; i++) {
        dist[i] = func_800EEB40(cam_pos, fires[i]->position);
    }
    for (j = 1; j < num; j++) {
        i = j;
        while (i > 0 && dist[i] < dist[i - 1]) {
            tmp_dist = dist[i];
            dist[i] = dist[i - 1];
            dist[i - 1] = tmp_dist;
            tmp_actor = fires[i];
            fires[i] = fires[i - 1];
            fires[i - 1] = tmp_actor;
            i--;
        }
    }
    for (i = 0; i < data->max_audible; i++) {
        func_80800AA8_chfirefx(fires[i]);
    }
}

// Adds a fire to the limiter's link list for this frame.
void func_8080116C_chfirefx(limiter, fire) Actor *limiter;
Actor *fire;
{
    FireFxLinks *data;

    data = func_80100094(limiter, 0);
    _subaddielink_entrypoint_1(data->links[data->count++], fire->unk0);
    func_80103110(limiter, 1);
}

extern void _chfirefx_entrypoint_3();
extern void func_80105834();
extern void _chfirefx_entrypoint_4();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
extern void _chfirefx_entrypoint_5();
extern void func_80102EC0();
extern void func_8010A730();
void *D_80801200_chfirefx = (void *) 0x031403AC;
static u32 D_80801200_chfirefx_rest[17] = {0xFFFF0002,
                                           0x0,
                                           (u32) _chfirefx_entrypoint_3,
                                           (u32) func_80105834,
                                           (u32) _chfirefx_entrypoint_4,
                                           0xED80000,
                                           0x0,
                                           0x0,
                                           0x20000,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_80800018_chfirefx,
                                           (u32) func_80107C2C,
                                           (u32) ((u8 *) boot_thread_stack + 0x1F22),
                                           (u32) _chfirefx_entrypoint_5,
                                           0x0};
int D_80801248_chfirefx[18] = {0x1580289,
                               0x1,
                               0x0,
                               (u32) func_80800F7C_chfirefx,
                               (u32) func_80102EC0,
                               (u32) func_8010A730,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x880000,
                               (u32) func_80800F00_chfirefx,
                               (u32) func_80107C2C,
                               -0x7FFFD1FE,
                               0x0,
                               0x0};
s16 D_80801290_chfirefx[12] = {0x13, 0x483, 0x206, 0x7,   0x16, 0x1F40,
                               0xE,  0x133, 0x170, 0x180, 0x3,  0x0};
u8 D_808012A8_chfirefx[24] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x40,
                              0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
