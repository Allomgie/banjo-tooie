// Bovina, the cow farmer of Mayahem Temple, and the pest flies bothering her cow: Bovina talks,
// starts the task and gives the Jiggy once all flies are shot.
#include "common.h"

extern s32 D_8080124C_chmayafarmer[];
typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[0x6C];
    u8 pad74 : 1;
    u8 flag : 1;
    u8 rest : 6;
} FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern void *D_80801278_chmayafarmer;
extern u8 D_80801230_chmayafarmer[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct {
    u8 pad_0[0x70];
    u32 zone : 7;
    u32 pad_1 : 15;
    u32 point : 6;
    u32 pad_2 : 4;
} FarmerRouteKeys;
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern s32 D_808012E8_chmayafarmer[];
extern void _subaddieaudioloop_entrypoint_4();
extern int D_808012FC_chmayafarmer[];
typedef union {
    s32 word;
    s16 half[2];
} MayaFarmerEvent;
extern u8 D_8080125C_chmayafarmer[];
extern Vec3f D_8080126C_chmayafarmer;
extern f32 func_800DC178(f32, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern u8 D_80801210_chmayafarmer[];
extern u8 D_80801220_chmayafarmer[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_8080123C_chmayafarmer[];
extern void *func_80106790(void *);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
typedef struct {
    f32 pos[3];
    s16 radius;
} FarmerScatterOrigin;
extern FarmerScatterOrigin *func_800CC63C(s32, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_80102424();
extern f32 func_800DC0C0(void);
extern f32 func_800F1828(f32 *, f32 *);
extern s32 func_80102D4C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
void func_80800D60_chmayafarmer();

// Bovina NPC: dialogs, dialog camera, fly spawning, Jiggy.
// Bovina cutscene/dialog state machine; the case fall-through is intended.
void func_80800000_chmayafarmer(u8 *actor, s32 arg1, s32 arg2)
{
    s32 unk_0;

    unk_0 = *(s32 *) ((s8 *) actor + 0x6C) & 0x1FF;
    switch (unk_0) {
        case 0:
            _capod_entrypoint_2(*(s32 *) ((s8 *) actor + 0), 8, 0);

        case 1:
            _capod_entrypoint_8(1);
            *(u16 *) ((s8 *) actor + 0x6E) =
                (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 2);
            _gcdialogcamera_entrypoint_3(&D_8080124C_chmayafarmer,
                                         *(f32 *) ((s8 *) actor + 0x38));
            _gcdialogcamera_entrypoint_4(actor + 4);
            _gcdialogcamera_entrypoint_5(actor + 0x44);
            _gcdialogcamera_entrypoint_8();

        case 2:
            _capod_entrypoint_7(arg1, arg2);
    }
}

void func_808000B0_chmayafarmer(u8 *actor, s32 arg1, s32 arg2, s32 arg3)
{
    s32 unk_0;

    unk_0 = *(s32 *) (actor + 0x6C) & 0x1FF;
    switch (unk_0) {
        case 0:
            _capod_entrypoint_2(*(s32 *) actor, 8, arg2);

        case 2:
            *(u16 *) (actor + 0x6E) = (*(u16 *) (actor + 0x6E) & 0xFE00) | 1;

        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
    }
}

int func_80800138_chmayafarmer(Actor *actor)
{
    if (*(s32 *) ((char *) actor + 0x6C) & 0x1FF) {
        _capod_entrypoint_3(0, actor);
        *(u16 *) ((char *) actor + 0x6E) &= 0xFE00;
    }
}

void func_80800180_chmayafarmer(FarmerState *farmer, s32 dialog_id, s32 flags)
{
    flags |= 4;
    _subaddiedialog_entrypoint_11(farmer->f0, dialog_id, flags, &farmer->f4, 0x2A);
    farmer->flag = 1;
}

int func_808001CC_chmayafarmer(actor)
Actor *actor;
{
    func_80102424();
    if (((u32) *(u16 *) ((char *) actor + 0x72) >> 10) == 4) {
        func_800FC660(0x10);
        func_80800180_chmayafarmer(actor, 0xF07, 0xB);
        *(f32 *) ((char *) actor + 0x58) = 0.0f;
    }
}

s32 func_80800228_chmayafarmer(Actor *actor, s32 event, MayaFarmerEvent data)
{
    s32 zone_id;
    s32 i;

    switch (event) {
        case 0x95:
            _suexpression_entrypoint_7(actor, 1, 0x2A);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 80.0f, 30.0f);
            func_80108B04(actor, 0);
            break;
        case 0x11:
            if (actor->unk70_10 == 1) {
                func_808001CC_chmayafarmer(actor, 3);
            }
            break;
        case 0x2E:
            actor->unk74_30 = 0;
            switch (data.half[0]) {
                case 0xF07:
                    func_800C01A8(0x64, 0);
                    func_808000B0_chmayafarmer(actor, 4, 0x2010, actor->unk0);
                    func_800D1000(4, 1, 0, 1, 0);
                    break;
                case 0xF06:
                    func_80800138_chmayafarmer(actor);
            }
            break;
        case 0x2F:
            if (data.half[0] == 0xF06 && !func_800C07F4()) {
                func_800DA544(5);
            }
            break;
        case 0xB:
            switch (data.word) {
                case 0xF:
                    func_80800000_chmayafarmer(actor, 2, 1);
                    return 4;
                case 4:
                    func_80800138_chmayafarmer(actor);
                    return 4;
                default:
                    return 3;
            }
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_8080125C_chmayafarmer, actor->scale);
            break;
        case 0x40:
            // A fly was shot.
            actor->unk74_7--;
            if ((s32) actor->unk74_7 <= 0) {
                func_808001CC_chmayafarmer(actor, 4);
            }
            break;
        case 0x3D:
            // Spawn up to 8 flies.
            zone_id = func_800CBC3C(D_8080126C_chmayafarmer.f);
            if ((s32) actor->unk74_7 >= 9) {
                actor->unk74_7 = 8;
            }
            for (i = 0; i < (s32) actor->unk74_7; i++) {
                func_800CD08C(zone_id, D_8080126C_chmayafarmer.f);
                func_80108528(0x2F8, D_8080126C_chmayafarmer.f, (s32) func_800DC178(0.0f, 360.0f),
                              &actor)
                    ->unk3C = actor->unk0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800520_chmayafarmer(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

// Bovina main loop: dialogs, task start and fly-shot handling.
void func_80800540_chmayafarmer(Actor *actor)
{
    f32 player_pos[3];
    f32 *pos;

    func_8010D254(player_pos);
    if (!actor->unk64_19 && player_pos[1] < 2000.0f) {
        actor->unk64_16 = 0;
        return;
    }
    actor->unk64_16 = 1;
    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    pos = actor->position;
    _sudeflect_entrypoint_1(pos, 140.0f, 0.0f, 110.0f, 14);
    if (!actor->unk74_30 && func_80090178(1) && !func_800D0A9C(4, 1)) {
        if (_subaddiedialog_entrypoint_3(pos, (s32) actor->rotation[1], 0x15E, 0x46, 6) &&
            !func_800DA9E4(0x4D, 1)) {
            func_80800000_chmayafarmer(actor, 2, 0);
            func_80800180_chmayafarmer(actor, 0xF06, 11);
        } else if (_subaddiedialog_entrypoint_6(pos, (s32) actor->rotation[1], 0x15E, 0x46,
                                                6)) {
            func_80800180_chmayafarmer(actor, 0xF08, 11);
        }
    }
    switch (actor->unk70_10) {
        case 1:
            if ((s32) actor->unk74_7 <= 0) {
                func_808001CC_chmayafarmer(actor, 4);
            }
            return;
        case 3:
            actor->unk54 *= 0.9f;
            if (func_80101E14(actor, 0.06f) || func_80101E14(actor, 0.8f)) {
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80801210_chmayafarmer);
            }
            if (func_80101E14(actor, 0.999f)) {
                _suexpression_entrypoint_12((s32) func_80100094(actor, 1), 80.0f, 30.0f);
                if ((s32) actor->unk74_7 <= 0) {
                    func_808001CC_chmayafarmer(actor, 4);
                    return;
                }
                func_808001CC_chmayafarmer(actor, 1);
            }
            break;
        case 4:
            actor->unk58 += 1.0f;
            if (actor->unk58 > 120.0f) {
                func_808001CC_chmayafarmer(actor, 5);
            }
            if (func_80101E14(actor, 0.75f)) {
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80801220_chmayafarmer);
            }
            break;
        case 5:
            if (func_80101E14(actor, 0.75f)) {
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80801220_chmayafarmer);
            }
    }
}

void func_8080085C_chmayafarmer(Actor *actor)
{
    actor->scale = 0.375f;
    if (func_800D0A9C(4, 1)) {
        actor->unk74_7 = 0;
        func_808001CC_chmayafarmer(actor, 5);
    }
    if (_glcutDll_entrypoint_20()) {
        actor->unk74_7 = 0;
        func_808001CC_chmayafarmer(actor, 5);
        actor->unk64_19 = 1;
    }
}

int chmayafarmer_entrypoint_0()
{
    return &D_80801278_chmayafarmer;
}

// Pest flies: wander in zone volumes, get shot down by eggs, report back to Bovina.
s32 func_808008F8_chmayafarmer(Actor *actor, s32 event, s32 data)
{
    f32 hit_pos[3];
    switch (event) {
        case 0x40:
            func_800EC398(data, hit_pos);
            func_800EFCD8((f32 *) &actor->actorData[4], func_800F1DF4(hit_pos, actor->position),
                          25.0f);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801230_chmayafarmer);
            func_80102424(actor, 3);
            func_8010A570(actor);
            func_8010114C(actor->unk3C, event, data);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808010DC_chmayafarmer();

void func_80801040_chmayafarmer();

// Fly actor main loop.
void func_808009A0_chmayafarmer(Actor *actor)
{
    void *bovina;
    f32 player_pos[3];
    f32 shadow_pos[3];

    func_8010D254(player_pos);
    if (player_pos[1] < 2000.0f) {
        if (actor->unk70_10 == 1 || actor->unk70_10 == 2) {
            func_808010DC_chmayafarmer(actor);
        }
        actor->unk64_16 = 0;
    } else {
        actor->unk64_16 = 1;
        bovina = func_80106790(actor->unk3C);
        if (func_800EFFB4(actor->position, 500.0f, (f32 *) ((u8 *) bovina + 4))) {
            func_8010114C(actor->unk3C, 0x11, 0);
        }
        switch (actor->unk70_10) {
            case 1:
            case 2:
                if (func_800DA9E4(5, 0)) {
                    func_808000B0_chmayafarmer(bovina, 0xF, 0x418, actor->unk0);
                }
                func_80800D60_chmayafarmer(actor, bovina);
                func_800EF04C(actor->position, (f32 *) ((u8 *) actor + 0x28));
                func_808010DC_chmayafarmer(actor);
                break;
            case 3:
                if (actor->unk58 < actor->position[1]) {
                    func_80801040_chmayafarmer(actor);
                    func_808010DC_chmayafarmer(actor);
                } else {
                    ((f32 *) actor->actorData)[5] = 0.0f;
                    func_800EF04C(actor->position, (f32 *) ((u8 *) actor + 0x28));
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_8080123C_chmayafarmer);
                    func_80102424(actor, 4);
                }
                break;
            case 4:
                if (func_80101E14(actor, 0.75f)) {
                    _subaddiefade_entrypoint_3(actor);
                }
        }
        func_800EE7F8(shadow_pos, actor->position);
        shadow_pos[1] = 2608.0f;
        _chbadshad_entrypoint_1(actor, shadow_pos, actor->scale * 1.4f);
    }
}

void func_80800B9C_chmayafarmer(Actor *actor)
{
    FarmerScatterOrigin *origin;
    f32 distance;
    f32 angle;
    origin = func_800CC63C(((FarmerRouteKeys *) actor)->zone - 1,
                            ((FarmerRouteKeys *) actor)->point - 1);
    func_800EE7F8(actor->position, origin->pos);
    angle = func_800DC178(0.0f, 360.0f);
    distance = func_800DC178(origin->radius * 0.3f, origin->radius);
    func_800EF1B8(actor->position, angle, distance);
    actor->unk58 = 2605.0f;
    actor->scale = 0.5f;
}

s32 func_80800C58_chmayafarmer(Actor *actor)
{
    f32 target[3];
    s32 point_idx;

    func_800EEC30(target, actor->rotation[0], actor->rotation[1], 200.0f);
    func_800EF04C(target, actor->position);
    if (target[1] < actor->unk58 + 250.0f)
        return 0;
    point_idx = func_800CC338(target, ((FarmerRouteKeys *) actor)->zone - 1,
                            ((FarmerRouteKeys *) actor)->point - 1);
    if (point_idx != -1) {
        ((FarmerRouteKeys *) actor)->point = point_idx + 1;
        return 1;
    }
    return 0;
}

void func_80800D18_chmayafarmer(u8 *actor)
{
    u32 keys;
    u32 point_idx;
    u32 zone_idx;
    u32 pos;

    keys = *(u32 *) (actor + 0x70);
    point_idx = ((keys << 22) >> 26) - 1;
    zone_idx = (keys >> 25) - 1;
    pos = func_800CC63C(zone_idx, point_idx);
    func_800EE7F8(actor + 0x18, pos);
}

// Fly wandering movement around the cow.
void func_80800D60_chmayafarmer(actor, bovina) Actor *actor;
Actor *bovina;
{
    switch (actor->unk70_10) {
        case 1:
            if (*(f32 *) &actor->actorData[3] < 8.0f) {
                *(f32 *) &actor->actorData[3] += 1.0f;
            }
            if (!func_80800C58_chmayafarmer(actor)) {
                func_80800D18_chmayafarmer(actor);
                func_80102424(actor, 2);
            }
            if (func_800DC0C0() < 0.05f) {
                actor->unk50 = func_800DC178(-25.0f, 25.0f);
            }
            if (func_800DC0C0() < 0.05f) {
                actor->unk54 += func_800DC178(-90.0f, 90.0f);
            }
            break;
        case 2:
            if (func_80800C58_chmayafarmer(actor)) {
                func_80102424(actor, 1);
            }
            if (6.0f < *(f32 *) &actor->actorData[3]) {
                *(f32 *) &actor->actorData[3] -= 2.0f;
            }
            actor->unk54 = func_800F1DF4(actor->position, (f32 *) &actor->actorData[0]);
            actor->unk50 = -func_800F1828(actor->position, (f32 *) &actor->actorData[0]);
    }
    if (!func_80102CF4(actor, 16.0f)) {
        if (actor->rotation[1] < actor->unk54) {
            if (actor->rotation[2] < 15.0f) {
                actor->rotation[2] += 1.0f;
            }
        } else if (-15.0f < actor->rotation[2]) {
            actor->rotation[2] -= 1.0f;
        }
    } else {
        actor->rotation[2] *= 0.75f;
    }
    if (bovina->unk6C_0 == 1) {
        *(f32 *) &actor->actorData[3] = 2.0f;
        actor->rotation[1] += actor->rotation[2] * 0.02f;
        actor->rotation[0] = 0.0f;
    } else {
        if (!func_80102D4C(actor, 2.0f)) {
            func_80102B6C(actor, 2.0f);
        }
        actor->rotation[1] += actor->rotation[2] * 0.2f;
    }
    func_800EF4E4((f32 *) &actor->actorData[4], actor->rotation[0], actor->rotation[1], 0.0f,
                  0.0f, *(f32 *) &actor->actorData[3]);
}

void func_80801040_chmayafarmer(Actor *actor)
{
    if (!func_80102EC8(actor, actor->position)) {
        *(f32 *) &actor->actorData[4] = 0.0f;
        *(f32 *) &actor->actorData[6] = 0.0f;
    }
    func_800EF04C(actor->position, (f32 *) &actor->actorData[4]);
    *(f32 *) &actor->actorData[5] -= 5.0f;
    if (actor->position[1] < actor->unk58)
        actor->position[1] = actor->unk58;
    if (!func_80102CF4(actor, 6.0f))
        func_80102B2C(actor, 4.0f);
}

void func_808010DC_chmayafarmer(u8 *actor)
{
    _subaddieaudioloop_entrypoint_4(actor, actor + 4, 1, &D_808012E8_chmayafarmer);
}

int *chmayafarmer_entrypoint_1()
{
    return &D_808012FC_chmayafarmer;
}

extern void func_80101870();
extern void func_80107C2C();
extern void func_80105834();
extern void func_80108ED0();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to
// functions of this file; IDO's assembler schedules some of them differently unless the
// tables are in the same unit. Values are taken from the ROM. The extern declarations at the
// top use the object's types: D_8080124C -> s32[], D_808012E8 -> s32[], D_808012FC -> int[].
u32 D_808011E0_chmayafarmer[12] = {0x0,        0x0,       0x3F400000, 0x1970001,
                                   0x3F400000, 0x1970001, 0x40DCCCCD, 0x19D0002,
                                   0x3F666666, 0x1980001, 0x3F666666, 0x1980001};
u8 D_80801210_chmayafarmer[16] = {0x0, 0x13, 0x3, 0xFF, 0x0,  0xD,  0x0, 0xCC,
                                  0x1, 0x66, 0x0, 0x16, 0x55, 0xF0, 0x0, 0x0};
u8 D_80801220_chmayafarmer[16] = {0x0, 0x13, 0x4,  0x2,  0x0, 0xA, 0x1, 0x99,
                                  0x0, 0x16, 0x3E, 0x80, 0x0, 0x0, 0x0, 0x0};
u8 D_80801230_chmayafarmer[12] = {0x0, 0x13, 0x4, 0xB3, 0x0, 0x16, 0x55, 0xF0, 0x0, 0x0, 0x0, 0x0};
u8 D_8080123C_chmayafarmer[16] = {0x0, 0x13, 0x4,  0x1F, 0x0, 0xA, 0x1, 0x66,
                                  0x0, 0x16, 0x55, 0xF0, 0x0, 0x0, 0x0, 0x0};
s32 D_8080124C_chmayafarmer[4] = {0x441C4000, 0x43BB8000, 0x437A0000, 0x43AF0000};
u8 D_8080125C_chmayafarmer[16] = {0x44, 0x3B, 0x80, 0x0, 0x43, 0xBB, 0x80, 0x0,
                                  0x43, 0x7A, 0x0,  0x0, 0x43, 0x7A, 0x0,  0x0};
Vec3f D_8080126C_chmayafarmer = {3369.0f, 3e+03f, -5688.0f};
void *D_80801278_chmayafarmer = (void *) 0x0230019B;
static u32 D_80801278_chmayafarmer_rest[17] = {0x6600001,
                                               (u32) &D_808011E0_chmayafarmer,
                                               (u32) func_80800540_chmayafarmer,
                                               0x0,
                                               (u32) func_80101870,
                                               0xDAC0000,
                                               0x40AAAAAB,
                                               0x0,
                                               0x800160,
                                               (u32) func_80800520_chmayafarmer,
                                               0x0,
                                               0x0,
                                               (u32) func_8080085C_chmayafarmer,
                                               (u32) func_80107C2C,
                                               0x86006482,
                                               (u32) func_80800228_chmayafarmer,
                                               0x0};
u32 D_808012C0_chmayafarmer[10] = {0x0,       0x0,        0x3F400000, 0x19E0001,  0x3F400000,
                                   0x19E0001, 0x3ECCCCCD, 0x19F0041,  0x3F666666, 0x1A00042};
s32 D_808012E8_chmayafarmer[5] = {0x13049B, 0x161388, 0xE00E6, 0x1190180, 0x0};
int D_808012FC_chmayafarmer[21] = {0x2BD02F8,
                                   0x6620001,
                                   (u32) &D_808012C0_chmayafarmer,
                                   (u32) func_808009A0_chmayafarmer,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0xBB80000,
                                   0x0,
                                   0x0,
                                   0x20000D,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_80800B9C_chmayafarmer,
                                   (u32) func_80107C2C,
                                   -0x7DDFBF80,
                                   (u32) func_808008F8_chmayafarmer,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0};
