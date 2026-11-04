#include "common.h"
// TU-NOTE: the .data tables at the end are defined in this file because IDO's assembler
// schedules the functions they point to differently otherwise. Values come from the ROM.

extern void *func_80100094(Actor *, u32);
typedef struct SparkRoomColor {
    f32 rgb[3];
} SparkRoomColor;
extern SparkRoomColor D_80801094_chfactorysparkroom;
extern f32 D_808010A8_chfactorysparkroom[4][3];
extern u8 D_808010A0_chfactorysparkroom[];
extern f32 D_808010D8_chfactorysparkroom[3];
extern void func_800C8B84();
typedef struct {
    f32 idle_timer;
    f32 active_timer;
    u8 pad_8[0x14];
    s32 light;
} FactorySpark;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC090(void);
extern void *func_800D7520(void *);
extern void func_800C7A68(void *, f32, f32 *);
extern s32 func_800C8A98(void);
extern void func_800C8F64(s32, s32);
extern void func_800C8FE0(s32, s32);
extern void func_800C8E84(s32, void *);
extern void func_800C8CB8(s32, f32 *);
extern void func_800C8D4C(s32, void *);
typedef struct {
    u32 a;
    u32 b;
    u32 c;
} FsrTbl;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 v10[2];
    void *p18;
    s32 h1C;
} FsrRec;
extern FsrTbl D_808010FC_chfactorysparkroom;
typedef struct {
    FactorySpark sparks[16];
    s32 light_0;
    s32 light_1;
    s32 light_2;
    s32 light_3;
} FactorySparkPool;
extern int D_80801108_chfactorysparkroom[];
extern void func_8010A63C();
extern void func_80108B04();
extern u8 D_80801150_chfactorysparkroom[];
extern s32 _chswitch_entrypoint_10(Actor *, s32, s32);
extern int D_8080115C_chfactorysparkroom[];
typedef struct {
    f32 v[3];
} SparkVec;
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 pad10[8];
    s32 unk18;
    s32 unk1C;
} Spark;
typedef struct {
    u8 pad0[0x70];
    u32 pad70_1 : 31;
    u32 unk70_0 : 1;
} SparkBits;
extern SparkVec D_8080107C_chfactorysparkroom;
extern SparkVec D_80801088_chfactorysparkroom;
extern f32 D_80801060_chfactorysparkroom[];
extern f32 D_80801070_chfactorysparkroom[];
extern s32 func_800D90A4(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800DC0C0(void);
extern void func_800F3214(f32 *, SparkVec *, SparkVec *, f32);
extern u8 _subaddieaudioloop_entrypoint_7();
extern s32 func_800F581C(s32);
extern s32 func_800F55FC(s32);
extern s32 func_800F6C5C(s32);
extern void func_800F796C(s32, s32);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
extern void func_80018820(s32, f32, f32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
typedef struct {
    s32 color[3];
} SparkRoomBlendColor;
extern SparkRoomBlendColor D_808010E4_chfactorysparkroom;
extern SparkRoomBlendColor D_808010F0_chfactorysparkroom;
typedef struct {
    f32 total_time;
    f32 time_left;
    f32 t_from;
    f32 t_to;
    u8 pad_10[8];
    s32 spline;
    u8 pad_1C[4];
} SparkDraw241;
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_80013970(f32);
extern void *func_800D674C(s32);
extern s32 func_800DE498(void *, f32 *, f32 *, f32, f32 *, void *);
void func_80800DC8_chfactorysparkroom();
void func_808006D0_chfactorysparkroom(Actor *actor, f32 param_1);
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chfactorysparkroom(),
    func_80800838_chfactorysparkroom(), func_80800D30_chfactorysparkroom();

// Controller init: finds the wire props and attaches a spline to each.
void func_80800000_chfactorysparkroom(actor) Actor *actor;
{
    s32 wires[16];
    u32 i;
    s32 *wire;
    Vec3f spline_pos;
    u8 *sparks;
    u8 *spark;

    sparks = func_80100094(actor, 0);
    actor->unk6C_0 = _gccubesearch_entrypoint_9(0x299, wires, 0x10);
    i = 0;
    wire = wires;
    spark = sparks;
    while (i < actor->unk6C_0) {
        *(f32 *) (spark + 0x10) = (f32) _gspropctrl_entrypoint_8(*wire) * 10.0f;
        *(f32 *) (spark + 0x14) = (f32) _gspropctrl_entrypoint_8(*wire) * 20.0f;
        _gspropctrl_entrypoint_11(*wire, spline_pos.f);
        *(s32 *) (spark + 0x18) = _glsplinefind_entrypoint_3(spline_pos.f);
        i++;
        wire++;
        spark += 0x20;
    }
    ((u8 *) actor)[0x50] = _subaddieaudioloop_entrypoint_7(
        ((u8 *) actor)[0x50], actor->position, 0, (u8 *) D_80801070_chfactorysparkroom,
        *(u32 *) ((u8 *) actor + 0x70) & 1);
}

void func_80800BE0_chfactorysparkroom();

void func_80800B60_chfactorysparkroom();

void func_808007E0_chfactorysparkroom();

void func_808005E0_chfactorysparkroom();

// Controller update: sparks along the wires, buzz loop, zap on the electrified floor.
void func_8080013C_chfactorysparkroom(actor) Actor *actor;
{
    f32 loud_pos[3];
    u32 i;
    Spark *spark;
    f32 min_dist;
    f32 spark_pos[3];
    f32 player_pos[3];
    f32 t;
    f32 dist;
    SparkVec color_a;
    SparkVec color_b;
    f32 color[3];
    f32 flash_pos[3];
    Spark *data;

    min_dist = 10000000.0f;
    data = func_80100094(actor, 0);
    for (i = 0, spark = data; i < actor->unk6C_0; i++, spark++) {
        if (spark->unk4 == 0.0f) {
            if (func_800D90A4(&spark->unk0) && (s32) actor->actorData[7] < 4) {
                func_80800BE0_chfactorysparkroom(actor, i);
            }
        } else if (func_800D90A4(&spark->unk4)) {
            func_80800B60_chfactorysparkroom(actor, i);
        } else {
            t =
                func_800F10B4(spark->unk4, spark->unk0, 0.0f, spark->unk8, spark->unkC);
            color_a = D_8080107C_chfactorysparkroom;
            color_b = D_80801088_chfactorysparkroom;
            func_800F5A00(func_800F54E4(), player_pos);
            func_800C7A68(func_800D7520(spark->unk18), t, spark_pos);
            if ((dist = func_800EFC7C(player_pos, spark_pos)) < min_dist) {
                min_dist = dist;
                func_800EE7F8(loud_pos, spark_pos);
            }
            spark_pos[1] += 50.0f;
            func_800F3214(color, &color_a, &color_b, func_800DC0C0() * 0.2f + 0.8f);
            func_800C8E84(spark->unk1C, color);
            func_800C8CB8(spark->unk1C, spark_pos);
        }
    }
    if (min_dist < 10000000.0f) {
        *(u8 *) &actor->unk50 = _subaddieaudioloop_entrypoint_7(*(u8 *) &actor->unk50, loud_pos,
                                                                  1, D_80801060_chfactorysparkroom,
                                                                  ((SparkBits *) actor)->unk70_0);
    } else {
        *(u8 *) &actor->unk50 = _subaddieaudioloop_entrypoint_7(*(u8 *) &actor->unk50, loud_pos,
                                                                  0, D_80801060_chfactorysparkroom,
                                                                  ((SparkBits *) actor)->unk70_0);
    }
    if (actor->unk54 == 0.0f) {
        if ((func_800F581C(func_800F54E4()) & 0x8000000) ||
            (func_800F55FC(func_800F54E4()) & 0x8000000)) {
            if (func_800F6C5C(func_800F54E4())) {
                func_800F5A00(func_800F54E4(), actor->position);
                func_800F796C(func_800F54E4(), 3);
                _chelectricfence_entrypoint_1(actor, actor->position);
                func_80018820(0, 5.0f, actor->unk74_7 / 10.0f);
                actor->unk54 = actor->unk74_7 / 10.0f;
                func_800EE7F8(flash_pos, actor->position);
                flash_pos[1] += 500.0f;
                func_808005E0_chfactorysparkroom(actor, flash_pos);
            }
        }
    } else if (func_800D90A4(&actor->unk54)) {
        func_808007E0_chfactorysparkroom(actor);
        _subaddieaudioloop_entrypoint_2(actor);
    } else {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                        D_80801070_chfactorysparkroom);
        if (actor->unk54 < actor->unk74_7 / 10.0f * 0.3f) {
            func_808006D0_chfactorysparkroom(
                actor,
                func_800F10B4(actor->unk54, 0.0f, actor->unk74_7 / 10.0f * 0.3f, 0.0f, 1.0f));
        }
    }
}

// Creates the four flashing room lights.
void func_808005E0_chfactorysparkroom(Actor *actor, f32 *center)
{
    s32 i;
    SparkRoomColor color = D_80801094_chfactorysparkroom;
    u8 *data;

    data = func_80100094(actor, 0);
    func_800EE7F8(D_808010D8_chfactorysparkroom, center);
    for (i = 0; i < 4; i++) {
        *(s32 *) (data + 0x200 + i * 4) = func_800C8A98();
        func_800C8CB8(*(s32 *) (data + 0x200 + i * 4),
                      D_808010A8_chfactorysparkroom[i]);
        func_800C8D4C(*(s32 *) (data + 0x200 + i * 4), D_808010A0_chfactorysparkroom);
        func_800C8F64(*(s32 *) (data + 0x200 + i * 4), 3);
        func_800C8FE0(*(s32 *) (data + 0x200 + i * 4), 3);
        func_800C8E84(*(s32 *) (data + 0x200 + i * 4), color.rgb);
    }
}

// Sets the flicker color of the four room lights.
void func_808006D0_chfactorysparkroom(Actor *actor, f32 blend)
{
    SparkRoomBlendColor color_off = D_808010E4_chfactorysparkroom;
    SparkRoomBlendColor color_on = D_808010F0_chfactorysparkroom;
    u8 *data;
    SparkRoomBlendColor blended;
    s32 i;
    data = (u8 *) func_80100094(actor, 0);
    if (blend > 0.5f)
        blend = func_800DC0C0() * 0.2f + 0.8f;
    else
        blend += blend;
    func_800F3214(&blended, &color_off, &color_on, blend);
    for (i = 0; i < 4; i++) {
        func_800C8E84(((s32 *) (data + 0x200))[i], &blended);
    }
}

// Frees the four room lights.
void func_808007E0_chfactorysparkroom(s32 actor)
{
    u8 *data = func_80100094(actor, 0);
    s32 i;
    for (i = 0; i < 4; i++) {
        func_800C8B84(((s32 *) (data + 0x200))[i]);
        ((s32 *) (data + 0x200))[i] = 0;
    }
}

// Draws the arcs of the spark zap.
void func_80800838_chfactorysparkroom(actor, param_1) Actor *actor;
void *param_1;
{
    SparkDraw241 *sparks;
    f32 t;
    Vec3f spark_pos;
    Vec3f spark_rot;
    u32 i;
    void *arc_model;
    Vec3f bone_pos;
    Vec3f bone_rot;
    u32 player;
    f32 scale;

    sparks = func_80100094(actor, 0);
    for (i = 0; i < actor->unk6C_0; i++) {
        if (sparks[i].time_left > 0.0f) {
            t = func_800F10B4(sparks[i].time_left, sparks[i].total_time, 0.0f,
                                    sparks[i].t_from, sparks[i].t_to);
            func_800C7A68(func_800D7520(sparks[i].spline), t, spark_pos.f);
            func_800E3980(spark_rot.f);
            func_800F1E6C(spark_pos.f, spark_rot.f, &actor->rotation[1]);
            actor->scale = func_80013970(t * 180.0f);
            if (actor->scale > 0.5f) {
                actor->scale = func_800DC0C0() * 0.2f + 0.8f;
            } else {
                actor->scale += actor->scale;
            }
            spark_rot.pos.x = -90.0f;
            spark_rot.pos.y = actor->rotation[1] - 90.0f;
            spark_rot.pos.z = 0.0f;
            func_800DF830(1);
            func_800DF744(1, func_800DC128(1, 5));
            func_800DE498(param_1, spark_pos.f, spark_rot.f, actor->scale, NULL,
                          func_8010347C(actor->unk0));
        }
    }
    if ((actor->unk74_7 / 10.0f) * 0.3f < actor->unk54) {
        arc_model = func_800D674C(0x6B9);
        for (i = 0; i < 10; i++) {
            player = func_800F54E4();
            func_800F5A2C(player, i, bone_pos.f);
            func_800F1E6C(actor->position, bone_pos.f, &bone_rot.pos.y);
            bone_rot.pos.x = func_800F1828(bone_pos.f, actor->position);
            bone_rot.pos.z = 0.0f;
            bone_rot.pos.y -= 90.0f;
            scale = func_800EEAD4(actor->position, bone_pos.f) / 100.0f;
            func_800DF830(1);
            func_800DF744(1, func_800DC128(1, 5));
            func_800DE498(param_1, actor->position, bone_rot.f, scale, NULL, arc_model);
        }
    }
}

// Ends a spark and frees its light.
void func_80800B60_chfactorysparkroom(Actor *actor, s32 index)
{
    FactorySpark *sparks;
    sparks = func_80100094(actor, 0);
    sparks[index].idle_timer = func_800DC178(1.0f, 3.0f);
    sparks[index].active_timer = 0.0f;
    func_800C8B84(sparks[index].light);
    sparks[index].light = 0;
    actor->actorData[7]--;
}

// Starts a spark on its wire.
void func_80800BE0_chfactorysparkroom(u8 *actor, s32 index)
{
    FsrTbl color;
    f32 pos[3];
    FsrRec *obj;

    color = D_808010FC_chfactorysparkroom;
    obj = func_80100094(actor, 0);
    obj[index].f4 = func_800DC178(4.0f, 5.0f);
    obj[index].f0 = obj[index].f4;
    if (func_800DC090() & 1) {
        obj[index].f8 = 0.0f;
        obj[index].fC = 1.0f;
    } else {
        obj[index].f8 = 1.0f;
        obj[index].fC = 0.0f;
    }
    func_800C7A68(func_800D7520(obj[index].p18), obj[index].f8, pos);
    pos[1] = pos[1] + 50.0f;
    if (obj[index].h1C == 0) {
        obj[index].h1C = func_800C8A98();
        func_800C8F64(obj[index].h1C, 3);
    }
    func_800C8FE0(obj[index].h1C, 1);
    func_800C8E84(obj[index].h1C, &color);
    func_800C8CB8(obj[index].h1C, pos);
    func_800C8D4C(obj[index].h1C, obj[index].v10);
    *(s32 *) (actor + 0x34) = *(s32 *) (actor + 0x34) + 1;
}

void func_80800D30_chfactorysparkroom(actor) u8 *actor;
{
    u32 i;

    i = 0;

if (*(s32 *) ((s8 *) actor + 0x6C) & 0x1FF) {
    do {
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((s8 *) actor + 0x50));
        i += 1;
        *(u8 *) ((s8 *) actor + 0x50) = 0U;
    } while (i < (u32) (*(s32 *) ((s8 *) actor + 0x6C) & 0x1FF));
}

}

int func_80800D90_chfactorysparkroom(actor, event, param_2)
s32 actor;
s32 event;
s32 param_2;
{
    if (event == 0x95) {
        func_80800DC8_chfactorysparkroom(actor);
        return 1;
    }

return 0;
}

// Resets all sparks.
void func_80800DC8_chfactorysparkroom(actor) Actor *actor;
{
    FactorySparkPool *pool;
    u32 i;

    pool = func_80100094(actor, 0);
    actor->actorData[7] = 0;
    actor->unk54 = 0.0f;
    for (i = 0; i < actor->unk6C_0; i++) {
        pool->sparks[i].light = 0;
        pool->sparks[i].idle_timer = func_800DC178(0.0f, 3.0f);
        pool->sparks[i].active_timer = 0.0f;

}
pool->light_1 = 0;
pool->light_2 = 0;
pool->light_3 = 0;
pool->light_0 = 0;
}

int *chfactorysparkroom_entrypoint_0()
{
    return &D_80801108_chfactorysparkroom;
}

s32 func_80800E94_chfactorysparkroom(s32 actor)
{
    _subaddiefade_entrypoint_14();
    func_8010A63C(actor);
    _chswitch_entrypoint_7(actor, 0xA2F);
}

// Light switch events.
s32 func_80800EC8_chfactorysparkroom(Actor *actor, s32 event, s32 param_2)
{
    Vec3f spawn_pos;
    switch (event) {
        case 7:
            if (func_800DA298(0x1BD)) {
                if (!func_800DA298(0x1BC)) {
                    func_800DA544(0xA04);
                    _glcutDll_entrypoint_6(0x10D, 0x41);
                    return 1;
                }
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1365, 7, actor->position, 0xA3);
                func_800DA524(0x1BD);
                func_80108B04(actor, 0);
                return 1;
            }

if (!func_800DA298(0x1BD) && !actor->unk74_30) {
    actor->unk74_30 = 1;
    _chmrtannoy_entrypoint_0();
    _subaddiedialog_entrypoint_11(actor->unk0, 0x133C, 7, actor->position, 0xA3);
}

return 1;
case 0x3D:
    spawn_pos = *(Vec3f *) D_80801150_chfactorysparkroom;
    func_80108528(0x47C, spawn_pos.f, 0, &actor);
    return 1;
default:
    return _chswitch_entrypoint_10(actor, event, param_2);
    }
    }

    int *chfactorysparkroom_entrypoint_1()
    {
        return &D_8080115C_chfactorysparkroom;
    }

    extern void _chswitch_entrypoint_6();
    extern void func_80101870();
    f32 D_80801060_chfactorysparkroom[4] = {1.746733e-39f, 2.048407e-39f, 1.194184e-39f,
                                            2.8101662e-38f};
    f32 D_80801070_chfactorysparkroom[3] = {1.746733e-39f, 2.059617e-39f, 0.0f};
    SparkVec D_8080107C_chfactorysparkroom = {0.0f, 0.0f, 0.0f};
    SparkVec D_80801088_chfactorysparkroom = {3.57e-43f, 3.57e-43f, 3.57e-43f};
    SparkRoomColor D_80801094_chfactorysparkroom = {3.57e-43f, 3.57e-43f, 3.57e-43f};
    u8 D_808010A0_chfactorysparkroom[8] = {0x44, 0x5A, 0xC0, 0x0, 0x44, 0xD4, 0x80, 0x0};
    f32 D_808010A8_chfactorysparkroom[4][3] = {875.0f,  5e+02f, 875.0f, 875.0f,  5e+02f, -875.0f,
                                               -875.0f, 5e+02f, 875.0f, -875.0f, 5e+02f, -875.0f};
    f32 D_808010D8_chfactorysparkroom[3] = {0.0f, 0.0f, 0.0f};
    SparkRoomBlendColor D_808010E4_chfactorysparkroom = {0x0, 0x0, 0x0};
    SparkRoomBlendColor D_808010F0_chfactorysparkroom = {0xFF, 0xFF, 0xFF};
    FsrTbl D_808010FC_chfactorysparkroom = {0xFF, 0xFF, 0xFF};
    int D_80801108_chfactorysparkroom[18] = {0x1580413,
                                             0x6B90001,
                                             0x0,
                                             (u32) func_8080013C_chfactorysparkroom,
                                             (u32) func_80105834,
                                             (u32) func_80800838_chfactorysparkroom,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x20400,
                                             (u32) func_80800D30_chfactorysparkroom,
                                             (u32) func_80108ED0,
                                             0x2100000,
                                             (u32) func_80800000_chfactorysparkroom,
                                             (u32) func_80107C2C,
                                             -0x7FFFFC00,
                                             (u32) func_80800D90_chfactorysparkroom,
                                             0x0};
    u8 D_80801150_chfactorysparkroom[12] = {0xC5, 0x1C, 0x40, 0x0, 0x0, 0x0,
                                            0x0,  0x0,  0x0,  0x0, 0x0, 0x0};
    int D_8080115C_chfactorysparkroom[21] = {0x34303ED,
                                             0x8830001,
                                             -0x7FEE5DE0,
                                             (u32) _chswitch_entrypoint_6,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x8,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800E94_chfactorysparkroom,
                                             (u32) func_80107C2C,
                                             -0x7FF7D3EE,
                                             (u32) func_80800EC8_chfactorysparkroom,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x0};
