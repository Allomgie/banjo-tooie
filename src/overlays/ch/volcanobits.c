// Hailfire Peaks volcano pieces: an eruption controller throwing lava rocks, the rock that
// explodes on impact, the volcano switches (one spawns a Jiggy) and the platforms they raise.
#include "common.h"

extern int D_80801154_chvolcanobits[];
extern int D_8080119C_chvolcanobits[];
extern int D_808011E4_chvolcanobits[];
extern s32 D_8080122C_chvolcanobits[];
extern void *func_80100094(Actor *, u32);
typedef struct {
    s16 index;
    s16 kind;
} VolcanoMessage;
typedef struct {
    s32 unk_0;
    f32 timer;
    s32 unk_8;
} VolcanoTimer;
typedef struct {
    VolcanoTimer entries[8];
    s32 count;
    f32 cutscene_timer;
} VolcanoTimers;
extern u8 D_80801274_chvolcanobits[];
typedef struct {
    u8 pad[0x64];
    u32 pad64 : 11;
    u32 flag : 1;
    u32 rest : 20;
} BitsState;
extern void func_800CF494(BitsState *);
extern u8 D_80801288_chvolcanobits[];
extern u8 D_8080129C_chvolcanobits[];
extern u8 D_808012AC_chvolcanobits[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_800BBCB8(f32 *, s32, f32, s32, s32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct {
    u8 pad[0x76];
    u16 f76 : 9;
    u16 pad76 : 7;
} VolcS;
extern void _subaddiefind_entrypoint_10(VolcS *, s32, s32);
extern void _chswitch_entrypoint_7(VolcS *, s32);
extern void _chswitch_entrypoint_9(VolcS *);
extern Actor *func_80106790();
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern u8 _chvolcanobits_entrypoint_4[];
extern f32 D_8080110C_chvolcanobits[][3];
typedef struct {
    s32 point;
    f32 timer;
    f32 height;
} VolcanoSplashPoint;
typedef struct {
    VolcanoSplashPoint points[8];
    u32 count;
    f32 unk_64;
} VolcanoSplashState;
extern f32 func_800DC178(f32, f32);
typedef struct {
    s32 point;
    f32 timer;
    f32 height;
} VolcEntry;
extern void func_800CD08C(s32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80102FDC(Actor *, f32);
extern s32 func_800DC298(f32);
extern s32 func_800EA05C(void);
extern void func_800CF2D4(s32);
extern void *func_800C8A98(void);
extern void func_800C8E54(void *, f32, f32);
extern void func_800F2F60(s32 *, s32 *, f32);
extern s32 D_80801100_chvolcanobits[3];
typedef struct {
    f32 duration;
    s32 pad_0;
    s16 camera;
    s16 pad_1;
} VolcanoSequence;
extern void *func_800E1540(s32);
extern void func_800E13F0(void *, f32);
extern void func_800E1410(void *, f32, f32);
extern void func_800187B4(s32, f32, f32, f32);
extern u8 D_808012EC_chvolcanobits[];
int func_80801040_chvolcanobits();
f32 *func_8080108C_chvolcanobits();
void func_80800914_chvolcanobits();
void func_80800D6C_chvolcanobits();

int chvolcanobits_entrypoint_0()
{
    return &D_80801154_chvolcanobits;
}

int chvolcanobits_entrypoint_1()
{
    return (int) &D_8080119C_chvolcanobits;
}

int *chvolcanobits_entrypoint_2()
{
    return &D_808011E4_chvolcanobits;
}

int chvolcanobits_entrypoint_3()
{
    return (int) D_8080122C_chvolcanobits;
}

// Collects lava splash points from nearby cube props (0x154).
void func_80800030_chvolcanobits(Actor *actor)
{
    s32 cube_ids[8];
    s32 pad0;
    s32 cube_count;
    s32 point_idx;
    s32 i;
    f32 pos[3];
    VolcanoSplashState *state;

    state = func_80100094(actor, 0);
    cube_count = _gccubesearch_entrypoint_9(0x154, cube_ids, 8);
    state->count = 0;
    for (i = 0; i < cube_count; i++) {
        func_800EE88C(pos, cube_ids[i]);
        point_idx = func_800CBC3C(pos);
        if (point_idx != -1) {
            state->points[state->count].height = pos[1];
            state->points[state->count].timer = func_800DC178(3.0f, 5.0f);
            state->points[state->count].point = point_idx;
            state->count++;
        }
    }
    state->unk_64 = 6.4f;
}

// Fires per-point eruption messages when timers expire; in the fire-side train station also during cutscene 0x70.
void func_80800170_chvolcanobits(Actor *actor)
{
    VolcanoTimers *timers;
    s32 i;
    VolcanoMessage expire_msg;
    VolcanoMessage cutscene_msg;

    timers = (VolcanoTimers *) func_80100094(actor, 0);
    for (i = 0; i < timers->count; i++) {
        if (func_800D9078(&timers->entries[i].timer)) {
            expire_msg.index = i;
            expire_msg.kind = 0;
            func_80108B04(actor, *(s32 *) &expire_msg);
        }
    }
    _subaddieaudioloop_entrypoint_4(actor, 0, 1, D_80801274_chvolcanobits);
    switch (func_800EA05C()) {
        case 0x129:
            if (_glcutDll_entrypoint_19(0x70) && func_800D9078(&timers->cutscene_timer)) {
                cutscene_msg.index = -1;
                cutscene_msg.kind = 1;
                func_80108B04(actor, *(s32 *) &cutscene_msg);
            }
        case 0x133:
            break;
    }
}

// Message 0x3D spawns a lava rock (0x425) with random velocity and spin.
s32 func_8080027C_chvolcanobits(Actor *actor, s32 msg, s32 arg)
{
    VolcEntry *entries;
    s32 idx;
    f32 pos[3];
    Actor *rock;

    entries = func_80100094(actor, 0);
    switch (msg) {
        case 0x3D:
            switch (((s16 *) &arg)[1]) {
                case 0:
                    idx = ((s16 *) &arg)[0];
                    func_800CD08C(entries[idx].point, pos);
                    pos[1] = entries[idx].height;
                    entries[idx].timer = func_800DC178(3.0f, 5.0f);
                    rock = func_80108528(0x425, pos, 0, &actor);
                    func_800EFA4C((f32 *) &rock->actorData[4], func_800DC178(-200.0f, 200.0f),
                                  func_800DC178(600.0f, 1200.0f), func_800DC178(-200.0f, 200.0f));
                    func_80102FDC(rock, func_800DC178(0.8f, 1.2f));
                    rock->unk54 =
                        (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(100.0f, 200.0f);
                    rock->unk50 =
                        (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(60.0f, 120.0f);
                    rock->unk64_20 = func_800DC298(0.6f);
                    rock->unk58 = func_800DC178(0.8f, 1.2f);
                    break;
                case 1:
                    func_800EFA4C(pos, 250.0f, -815.0f, -400.0f);
                    rock = func_80108528(0x425, pos, 0, &actor);
                    func_800EFA4C((f32 *) &rock->actorData[4], 0.0f, 1200.0f, 0.0f);
                    func_80102FDC(rock, func_800DC178(0.8f, 1.2f));
                    rock->unk54 =
                        (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(100.0f, 200.0f);
                    rock->unk50 =
                        (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(60.0f, 120.0f);
                    rock->unk64_20 = 1;
                    rock->unk64_19 = 1;
                    rock->unk58 = 2.0f;
            }
            break;
        case 0x95:
            if (func_800EA05C() == 0x133) {
                func_800CF2D4(5);
                actor->unk64_20 = 1;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080061C_chvolcanobits(BitsState *state)
{
    if (state->flag) {
        func_800CF494(state);
        ((u8 *) state)[0x65] &= ~0x10;
    }
}

void func_8080065C_chvolcanobits(s32 arg0)
{
}

// Lava rock update: tumble, fall, light up and explode on impact.
void func_80800664_chvolcanobits(Actor *rock)
{
    f32 dt;
    f32 explode_pos[3];
    f32 *pos;

    dt = func_800D8FF8();
    rock->rotation[1] = func_800136E4(rock->rotation[1] + rock->unk54 * dt);
    rock->rotation[0] = func_800136E4(rock->rotation[0] + rock->unk50 * dt);
    if (rock->unk70_10 == 1) {
        pos = rock->position;
        if (!func_800BFA1C(pos) && *(f32 *) &rock->actorData[5] < 0.0f) {
            func_800FFAB0(rock);
            return;
        }
        *(f32 *) &rock->actorData[5] -= dt * 800.0f;
        func_80800914_chvolcanobits(rock);
        if ((func_8010B990(rock, 0x400007) & 0x20) ||
            (rock->unk64_20 && func_800D9078(&rock->unk58))) {
            func_800C8E54(rock->actorData[0], 400.0f, 1000.0f);
            func_800C8E84(rock->actorData[0], (u8 *) D_80801100_chvolcanobits);
            rock->actorData[0] = _chlightfader_entrypoint_1(rock->actorData[0], 1.8f, 2);
            func_800BBCB8(pos, 0, 1.0f, 1, _fxgenlist_entrypoint_2());
            _subaddieaudioquick_entrypoint_2(rock, pos,
                                             rock->unk64_19 ? D_8080129C_chvolcanobits
                                                               : D_80801288_chvolcanobits);
            func_800EE7F8(explode_pos, pos);
            explode_pos[1] -= rock->scale * 10.0f;
            _chexploder_entrypoint_3(rock, explode_pos, 0x1C);
            func_80101FDC(rock, 2);
        }
        if (!func_8001210C(1)) {
            func_800BABB8(func_800B5BE4(0x18), pos, NULL, 1.0f, D_808012AC_chvolcanobits);
        }
    }
}

void func_8080086C_chvolcanobits(Actor *actor)
{
    s32 *light = (s32 *) ((char *) actor + 0x18);
    if (*light != 0) {
        func_800C8B84(*(s32 *) ((char *) actor + 0x18));
        *(s32 *) ((char *) actor + 0x18) = 0;
    }
}

int func_808008A4_chvolcanobits(Actor *actor, s32 msg, s32 arg)
{
    s32 *target;
    if (msg == 0x90) {
        target = func_80101080();
        target = func_80106790(target);
        _chexploder_entrypoint_6(target, 0x44960000, 0x44AF0000);
        _subaddiefade_entrypoint_3(target);
        return 1;
    }
    if (msg == 0x95) {
        *(s32 *) ((char *) actor + 0x18) = 0;
        return 1;
    }
    return 0;
}

void func_80800914_chvolcanobits(actor) Actor *actor;
{
    s32 light_color[3];
    if (!*(void **) &actor->actorData[0]) {
        *(void **) &actor->actorData[0] = func_800C8A98();
        func_800C8E54(*(void **) &actor->actorData[0], 200.0f, 800.0f);
    }
    func_800C8CB8(*(void **) &actor->actorData[0], actor->position);
    func_800F2F60(light_color, D_80801100_chvolcanobits, func_800DC178(0.8f, 1.0f));
    func_800C8E84(*(void **) &actor->actorData[0], light_color);
}

void func_808009A8_chvolcanobits(VolcS *sw)
{
    u8 *params = func_8080108C_chvolcanobits(sw);
    _subaddiefind_entrypoint_10(sw, 0x42A, sw->f76);
    _chswitch_entrypoint_7(sw, *(s16 *) (params + 6));
    _chswitch_entrypoint_9(sw);
}

// Volcano switch messages; switch type 0x37 spawns the Inside the Volcano Jiggy.
s32 func_80800A04_chvolcanobits(Actor *actor, s32 msg)
{
    s32 switch_idx;
    s32 i;

    switch (msg) {
        case 7:
            if (actor->unk74_7 == 0x37) {
                func_800D1000(0x3E, 1, NULL, 1, 0);
            }
            func_8010114C(actor->unk3C, 0xA, 0);
            break;
        case 31:
            switch_idx = actor->unk74_7 - 0x32;
            func_801015D0(actor);
            for (i = 0; i < 6; i++) {
                func_800DF744(i + 1, switch_idx == i);
            }
            break;
        default:
            return _chswitch_entrypoint_10(actor);
    }
    return 1;
}

s32 func_80800AEC_chvolcanobits(s32 actor)
{
    func_800EE7F8(func_80100094(actor, 0), actor + 4);
}

// Rising platform update.
void func_80800B20_chvolcanobits(Actor *actor)
{
    u8 *params;
    s32 done;
    Actor *target;

    params = func_8080108C_chvolcanobits(actor);
    switch (actor->unk70_10) {
        case 1:
        case 3:
            if (--actor->unk79_4 == 0)
                func_80103110(actor, 0);
            break;
        case 2:
            done = func_800D9078(&actor->unk58);
            func_800EFE50(actor->position, (f32 *) ((u8 *) actor + 0x28),
                          (f32 *) actor->actorData,
                          func_800F12D4(actor->unk58, 0.0f, *(f32 *) params, 1.0f, 0.0f));
            if (actor->unk3C) {
                target = func_80106790(actor->unk3C);
                target->position[1] = actor->position[1] + actor->unk54;
            }
            if (done) {
                func_800DA544(*(s16 *) (params + 6));
                actor->unk79_4 = 2;
                func_80101FDC(actor, 3);
                func_800C2FDC(actor->unk5F);
                actor->unk5F = 0;
            } else {
                func_80800D6C_chvolcanobits(actor);
            }
    }
    func_80801040_chvolcanobits(actor);
}

void func_80800EF0_chvolcanobits();

s32 func_80800C5C_chvolcanobits(Actor *actor, s32 msg, s32 arg)
{
    VolcanoSequence *params;
    void *seq;
    if (msg == 0xA) {
        params = (VolcanoSequence *) func_8080108C_chvolcanobits(actor);
        seq = func_800E1540(0);
        func_800E1378(seq);
        func_800E13F0(seq, 5.0f);
        func_800E1410(seq, -5.0f, params->duration * 0.95f);
        func_800187B4(0, 3.0f, 1.0f, params->duration * 0.95f);
        func_80101FDC(actor, 2);
        func_80103110(actor, 1);
        actor->unk58 = params->duration;
        if (params->camera != -1)
            _capod_entrypoint_13(actor->unk0, 0, params->camera, 0x10);
        return 1;
    }
    if (msg == 0x95) {
        func_80800EF0_chvolcanobits(actor);
        return 1;
    }
    return 0;
}

void func_80800D6C_chvolcanobits(actor) Actor *actor;
{
    void *audio;
    audio = func_80100094(actor, 0);
    if (_subaddieaudioloop_entrypoint_4(actor, audio, 1, D_808012EC_chvolcanobits)) {
        _subaddieaudioloop_entrypoint_1(
            actor, (s32) func_800F12D4(actor->unk58, 0.0f,
                                         func_8080108C_chvolcanobits(actor)[0] * 0.6f, 32767.0f,
                                         22000.0f));
    }
}

// Moves map-mesh vertices with the platform actor.
void chvolcanobits_entrypoint_4(s32 param_0, Vtx *src, Vtx *dst, s32 count,
                                Unk80132ED0 *owner)
{
    Actor *platform;
    Vtx *end;
    s32 i;

    platform = func_80106790(owner);
    end = dst + count;
    for (; dst < end; dst++, src++) {
        for (i = 0; i < 3; i++) {
            dst->v.ob[i] = src->v.ob[i] + platform->position[i];
        }
    }
}

void func_80800EF0_chvolcanobits(u8 *platform)
{
    u8 *params;
    u8 *target;

    params = func_8080108C_chvolcanobits();
    target = NULL;
    _subaddiefind_entrypoint_10(platform, 0x429,
                                ((u32) (u16) *(u16 *) ((s8 *) platform + 0x76) >> 7) + 1);
    func_800EFD24(platform + 4);
    func_800EFD24(platform + 0x18);
    func_800EFD24(platform + 0x28);
    *(f32 *) ((s8 *) platform + 0x2C) =
        (f32) (*(f32 *) ((s8 *) platform + 0x2C) - (f32) *(s16 *) ((s8 *) params + 4));
    if (*(s32 *) ((s8 *) platform + 0x3C) != 0) {
        target = func_80106790(*(s32 *) ((s8 *) platform + 0x3C));
    }
    if (target != NULL) {
        *(f32 *) ((s8 *) platform + 0x54) =
            (f32) (*(f32 *) ((s8 *) target + 8) - *(f32 *) ((s8 *) platform + 8));
    }
    if (func_800DA298(*(s16 *) ((s8 *) params + 6)) != 0) {
        func_800EE7F8(platform + 4, platform + 0x18);
        func_80101FDC(platform, 3);
        func_800FFAB0(platform);
    } else {
        func_800EE7F8(platform + 4, platform + 0x28);
        func_80101FDC(platform, 1);
        func_80103110(platform, 1);
        *(u8 *) ((s8 *) platform + 0x79) = (u8) ((*(u8 *) ((s8 *) platform + 0x79) & 0xFF0F) | 0x20);
    }
    if (target != NULL) {
        *(f32 *) ((s8 *) target + 8) =
            (f32) (*(f32 *) ((s8 *) platform + 0x54) + *(f32 *) ((s8 *) platform + 8));
    }
    *(s8 *) ((s8 *) platform + 0x5F) = 0;
    func_80801040_chvolcanobits(platform);
}

int func_80801040_chvolcanobits(actor)
Actor *actor;
{
    s32 model;
    model = func_800BEA88(0);
    if (model != 0) {
        _glid_entrypoint_0(model | model,
                           ((u32) *(u16 *) ((char *) actor + 0x76) >> 7) - 0x31,
                           &_chvolcanobits_entrypoint_4, *(s32 *) ((char *) actor + 0x0));
    }
}

f32 *func_8080108C_chvolcanobits(actor)
Actor *actor;
{
    s32 index;

    index = actor->unk74_7 - 0x32;
    return D_8080110C_chvolcanobits[index];
}

// TU-NOTE: the .data below is defined in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80108ED0();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_801018A4();
extern void func_8010A730();
s32 D_80801100_chvolcanobits[3] = {0xFF, 0xFF, 0xFF};
f32 D_8080110C_chvolcanobits[6][3] = {
    4.0f, 1.5870066e-37f, 0.0f,         5.0f, 7.7589775e-37f, 2.75506e-40f,
    5.0f, 1.0697714e-36f, 5.51013e-40f, 3.0f, 8.963592e-38f,  8.2652e-40f,
    5.0f, 1.0697716e-36f, 1.01019e-39f, 5.0f, 7.758981e-37f,  1.377532e-39f};
int D_80801154_chvolcanobits[18] = {0x3360424,
                                    0x1,
                                    0x0,
                                    (u32) func_80800170_chvolcanobits,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080061C_chvolcanobits,
                                    0x0,
                                    0x680000,
                                    (u32) func_80800030_chvolcanobits,
                                    (u32) func_80107C2C,
                                    -0x7FFFF9FE,
                                    (u32) func_8080027C_chvolcanobits,
                                    0x0};
int D_8080119C_chvolcanobits[18] = {0x3370425,
                                    0x7BB0001,
                                    0x0,
                                    (u32) func_80800664_chvolcanobits,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080086C_chvolcanobits,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_8080065C_chvolcanobits,
                                    (u32) func_80107C2C,
                                    -0x7FFFBBFE,
                                    (u32) func_808008A4_chvolcanobits,
                                    0x0};
int D_808011E4_chvolcanobits[18] = {0x3430429,
                                    0x9450001,
                                    (u32) &D_8011A270,
                                    (u32) _chswitch_entrypoint_6,
                                    (u32) func_80105834,
                                    (u32) func_801018A4,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x4000080C,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_808009A8_chvolcanobits,
                                    (u32) func_80107C2C,
                                    -0x7FF7D3EE,
                                    (u32) func_80800A04_chvolcanobits,
                                    0x0};
s32 D_8080122C_chvolcanobits[18] = {0x158042A,
                                    0x1,
                                    0x0,
                                    (u32) func_80800B20_chvolcanobits,
                                    (u32) func_80105834,
                                    (u32) func_8010A730,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x4,
                                    0x0,
                                    0x0,
                                    0xC0000,
                                    (u32) func_80800AEC_chvolcanobits,
                                    (u32) func_80107C2C,
                                    -0x7FFFF1FE,
                                    (u32) func_80800C5C_chvolcanobits,
                                    0x0};
u8 D_80801274_chvolcanobits[20] = {0x0, 0x13, 0x4, 0x83, 0x0, 0xE,  0x0, 0x40, 0x0, 0x59,
                                   0x0, 0x19, 0x0, 0x18, 0x0, 0x14, 0x0, 0x0,  0x0, 0x0};
u8 D_80801288_chvolcanobits[20] = {0x0, 0x13, 0x4, 0x13, 0x0, 0xD,  0x0, 0x8C, 0x0, 0xA6,
                                   0x0, 0x1,  0x3, 0x20, 0xF, 0xA0, 0x0, 0x0,  0x0, 0x0};
u8 D_8080129C_chvolcanobits[16] = {0x0, 0x13, 0x4, 0x13, 0x0, 0xA, 0x1, 0x19,
                                   0x0, 0x18, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
u8 D_808012AC_chvolcanobits[64] = {
    0x0,  0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0,  0x32, 0x0, 0x2,  0x0, 0x15, 0x0,  0x0,
    0x0,  0xCC, 0x0, 0x22, 0x1, 0xCC, 0x2,  0x0,  0x0,  0x4C, 0x0, 0x66, 0x0, 0x2B, 0x0,  0x99,
    0x0,  0xCC, 0x0, 0x1B, 0x1, 0x2C, 0x1,  0x2C, 0x0,  0x18, 0x0, 0x0,  0x0, 0x0,  0x19, 0x0,
    0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0,  0x20, 0xFF, 0x80, 0x0, 0x80, 0x1, 0x1A, 0x0,  0x0};
u8 D_808012EC_chvolcanobits[20] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x16, 0x55, 0xF0, 0x0, 0x2,
                                   0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0};
