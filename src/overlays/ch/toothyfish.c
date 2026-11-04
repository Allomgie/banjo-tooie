#include "common.h"

typedef struct {
    u8 pad_0[0x18];
    f32 wobble[5];
    s32 unk_1;
    f32 unk_2;
    u8 tooth_gone[5];
    u8 unk_4[5];
} ToothyFishState;
extern void *func_80100094(Actor *, u32);
extern u8 D_80801778_chtoothyfish[];
extern u8 D_80801760_chtoothyfish[];
extern u8 D_8080178C_chtoothyfish[];
extern u8 D_80801858_chtoothyfish[];
extern u8 D_8080179C_chtoothyfish[];
extern u8 D_80801864_chtoothyfish[];
extern u8 D_808017AC_chtoothyfish[];
extern Unk80132ED0 *_sueggmove_entrypoint_1(void *);
typedef struct {
    u8 pad0[0x18];
    f32 f[5];
    u8 pad1[7];
    u8 b33[1];
    u8 b34[1];
    u8 b35[4];
    u8 b39[5];
} ToothyFish;
extern void *D_80801870_chtoothyfish;
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_808017C4_chtoothyfish[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern f32 func_800DC178(f32, f32);
extern Actor *func_801084B0(s32, Actor **);
extern int D_80801914_chtoothyfish[];
extern u8 D_80801814_chtoothyfish[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA994(s32, s32, s32, s32, s32, s32, s32);
typedef struct {
    u8 pad0[0xC];
    f32 unkC[3];
    f32 unk18[5];
    u8 pad2C[4];
    f32 unk30;
    u8 unk34[5];
} ToothyData_808004A4_chtoothyfish;
extern void func_8010A624(Actor *);
extern void func_8010A63C(Actor *);
extern f32 func_800D8FF8(void);
extern void func_80105A9C(Actor *, f32);
extern void func_80105834(Actor *);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0AFC(s32, u8, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_8010CAC0(f32 *, s32);
extern s32 func_800F8B88(void);
extern void func_800E39A8(ToothyData_808004A4_chtoothyfish *, f32 *);
extern void _gcgoto_entrypoint_5(s32, s32, f32);
extern void func_80090358(f32 *, f32, s32, s32);
extern s32 func_800DC298(f32);
extern void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
typedef struct {
    u8 pad0[0x30];
    f32 unk30;
    u8 unk34[5];
} ToothyData_80800B68_chtoothyfish;
extern s32 func_800F54E4(void);
extern void func_8010573C(Actor *, f32);
extern void func_80103014(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800F8294(s32, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800F608C(s32, s32);
extern void func_800F497C(s32);
extern void func_800F4A2C(s32, f32 *);
extern void func_800F49A8(s32, s32);
extern void func_800F4A00(s32, s32);
extern void func_800F49D4(s32, void *, Unk80132ED0 *);
extern void func_800F4A8C(s32, f32 *, f32);
extern void func_8010D5DC();
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_801015D0(Actor *);
extern void func_800DF744(s32, s32);
extern u8 D_808018B8_chtoothyfish[];
typedef struct {
    u8 pad0[0x7C];
    u32 pad7C_15 : 17;
    u32 unk7C_14 : 1;
    u32 pad7C_0 : 14;
} ToothyBits;
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
extern s32 func_80102D4C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
void func_808000E8_chtoothyfish();

void func_80800000_chtoothyfish(Actor *actor)
{
    ToothyFishState *data;
    s32 i;
    s32 teeth_left;

    data = func_80100094(actor, 0);
    teeth_left = 0;
    for (i = 0; i < 5; i++) {
        data->tooth_gone[i] = func_800DA298(0x4F6 + i);
        if (data->tooth_gone[i] == 0) {
            teeth_left++;
        }
        data->unk_4[i] = 0;
        data->wobble[i] = 0.0f;
    }
    if (teeth_left == 0) {
        func_808000E8_chtoothyfish(actor, 4);
    }
    data->unk_1 = 0;
    data->unk_2 = 1.0f;
    actor->unk6C_0 = _subaddiesect_entrypoint_1(actor);
}

void func_808000E8_chtoothyfish(actor, state) u8 *actor;
s32 state;
{
    u16 anim_bits;
    anim_bits = *(u16 *) ((char *) actor + 0x72);
    if (state != ((anim_bits & 0xFFFFu) >> 10)) {
        func_80102424();
        if (state != 1) {
            switch (state) {
                case 2:
                    _subaddieaudioquick_entrypoint_2(actor, actor + 4,
                                                     &D_80801760_chtoothyfish);
                    func_800FC660(0xE);
                    return;

                case 3:
                    _subaddieaudioquick_entrypoint_2(actor, actor + 4,
                                                     &D_80801778_chtoothyfish);
                    func_800FC660(0x10);

                case 4:
                    break;
            }
        }
    }
}

void func_80800188_chtoothyfish(f32 *pos, f32 y_offset, f32 scale, f32 yaw)
{
    s32 unk_0;
    s32 unk_1;
    unk_0 = func_800DC128(0, 5);
    unk_1 = func_800B53A4(unk_0);
    func_800BABB8(unk_1, pos, 0, 1.0f, D_80801814_chtoothyfish);
    func_800BA568(unk_1, (s16) (s32) (pos[1] + y_offset));
    func_800BA7C4(unk_1, 0.16f * scale, 0.3f * scale);
    func_800BA7FC(unk_1, 0.45f * scale, 0.6f * scale);
    func_800BA994(unk_1, -75, (s16) (s32) (yaw - 75.0f), 1200, -15, (s32) (yaw + 75.0f),
                  1500);
    func_800BA22C(unk_1, unk_0);
}

void func_808002DC_chtoothyfish(Actor *actor)
{
    f32 pos[3];
    if (actor->unk7C_12) {
        _subaddieskeleton_entrypoint_2(actor->unk0, 0xA, pos);
        _subaddieaudioquick_entrypoint_4(actor, pos, D_8080178C_chtoothyfish,
                                         D_80801858_chtoothyfish);
        _subaddieaudioquick_entrypoint_4(actor, pos, D_8080179C_chtoothyfish,
                                         D_80801864_chtoothyfish);
    }
}

// Tooth hit: knocks it out once it has 30 points, otherwise it just wobbles.
void func_80800350_chtoothyfish(Actor *actor, u8 *data, s32 tooth)
{
    if ((data + tooth)[0x39] >= 0x1E) {
        func_80108B04(actor, tooth);
        actor->unk74_29 = 1;
    } else {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808017AC_chtoothyfish);
        ((f32 *) data)[tooth + 6] = 1.0f;
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_808003D4_chtoothyfish(Actor *actor, u8 *data)
{
    s32 unk_0;
    s32 teeth_left;
    s32 i;
    u8 *tooth;
    teeth_left = 0;
    i = 0; tooth = data; do {
        i += 1;
        if (*(u8 *) ((char *) tooth + 0x34) == 0)
        {
            teeth_left += 1;
        }
        tooth += 1;
    }
    while (i != 5);
    if (teeth_left != *(u8 *) ((char *) data + 0x3E))
    {
        if (teeth_left != 0)
        {
            func_808000E8_chtoothyfish(actor, 2, teeth_left, data);
        }
        else
        {
            func_808000E8_chtoothyfish(actor, 3, teeth_left, data);
        }
        *(u8 *) ((char *) data + 0x3E) = (u8) teeth_left;
    }
}

void func_80800470_chtoothyfish(u8 *actor)
{
    if (((u32) *(u16 *) ((char *) actor + 0x72) >> 0xA) == 6) {
        func_808000E8_chtoothyfish(actor, 5);
    }
}

void func_808004A4_chtoothyfish(Actor *actor)
{
    ToothyData_808004A4_chtoothyfish *data;
    s32 i;
    s32 skeleton;
    f32 mouth_pos[3];
    f32 front_pos[3];
    f32 bone_pos[3];

    data = func_80100094(actor, 0);
    if (actor->unk64_19) {
        func_8010A624(actor);
    } else {
        func_8010A63C(actor);
        if (data->unk30 < 1.0f) {
            data->unk30 += 0.3f * func_800D8FF8();
        }
    }
    *(f32 *) &actor->actorData[3] = data->unk30 * 200.0f;
    func_80105A9C(actor, *(f32 *) &actor->actorData[3]);
    func_80105834(actor);
    actor->rotation[0] = 0.0f;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * 0.1f;
    skeleton = func_8010262C(actor->unk0, 5);
    if (skeleton) {
        for (i = 0; i < 5; i++) {
            if (0.005f < data->unk18[i] || data->unk18[i] < -0.005f) {
                data->unk18[i] *= -0.9f;
            }
            func_800E0AFC(skeleton, 90 - i, 1.0f, data->unk18[i] * 15.0f,
                          data->unk18[i] * 15.0f, data->unk18[i] * 0);
        }
    }
    if (actor->unk74_29) {
        func_808003D4_chtoothyfish(actor, data);
    }
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_80101E14(actor, 0.999f)) {
                func_808000E8_chtoothyfish(actor, 1);
            }
            break;
        case 3:
            if (func_80101E14(actor, 0.25f)) {
                func_808000E8_chtoothyfish(actor, 4);
            }
            break;
        case 4:
            func_800EEC30(mouth_pos, -actor->rotation[0] - 30.0f, actor->rotation[1],
                          actor->scale * 80.0f);
            func_800EF04C(mouth_pos, actor->position);
            _sudeflect_entrypoint_0(mouth_pos, actor->scale * 70.0f, actor->scale * 80.0f, 4);
            if (func_8010CAC0(mouth_pos, actor->scale * 70.0f) && func_800F8B88() != 3) {
                func_800E39A8(data, data->unkC);
                _gcgoto_entrypoint_5(0xF8, 1, actor->rotation[1] + 180.0f);
                actor->unk64_20 = 1;
                func_80090358(actor->position, 4.0f, 0, 0);
                func_808000E8_chtoothyfish(actor, 5);
            }
            break;
        case 6:
            data->unk30 = 0.0f;
            break;
        case 5:
            func_800EEC30(front_pos, -actor->rotation[0] - 20.0f, actor->rotation[1],
                          actor->scale * 80.0f);
            func_800EF04C(front_pos, actor->position);
            if (!func_8010CAC0(front_pos, actor->scale * 150.0f)) {
                func_808000E8_chtoothyfish(actor, 4);
            }
    }
    func_808002DC_chtoothyfish(actor);
    if (actor->unk7C_12) {
        if (func_800DC298(0.03f) || (actor->unk70_10 == 2 && func_800DC298(0.1f))) {
            _subaddieskeleton_entrypoint_2(actor->unk0, 6, bone_pos);
            func_80800188_chtoothyfish(bone_pos, 1000.0f, actor->scale, actor->rotation[1]);
        }
    }
}

s32 func_80800908_chtoothyfish(s32 flags)
{
    flags &= 0x78000000;
    switch (flags) {
        case 0x28000000:
            return 0;
        case 0x08000000:
            return 1;
        case 0x10000000:
            return 2;
        case 0x18000000:
            return 3;
        case 0x20000000:
            return 4;
        default:
            return -1;
    }
}

// Scores egg hits on the teeth (10/20/20/30 points); grenade eggs also hit neighbours.
void func_8080096C_chtoothyfish(Actor *actor, u8 *egg)
{
    ToothyFish *data;
    s32 valid;
    s32 points;
    s32 tooth;
    s32 prev;
    s32 next;

    data = func_80100094(actor, 0);
    valid = 1;
    points = 0;
    if (actor->unk7C_12 && egg != NULL) {
        switch (*(u32 *) (egg + 0x24) >> 22) {
            default:
                valid = 0;
                break;
            case 0x26C:
                points = 10;
                break;
            case 0x26D:
                points = 20;
                break;
            case 0x26F:
                points = 30;
                break;
            case 0x26E:
                points = 20;
                break;
        }
        if (points && valid && _sueggmove_entrypoint_1(egg) == actor->unk0) {
            tooth = func_80800908_chtoothyfish(_sueggmove_entrypoint_2(egg));
            if (tooth >= 0) {
                data->b39[tooth] += points;
                if (points == 30) {
                    prev = tooth - 1;
                    next = tooth + 1;
                    if (tooth > 0 && !data->b33[tooth]) {
                        data->b39[prev] += 10;
                        data->f[prev] = 0.5f;
                        if (data->b39[prev] >= 30) {
                            func_80108B04(actor, prev);
                        }
                    }
                    if (tooth < 4 && !data->b35[tooth]) {
                        data->b39[next] += 10;
                        data->f[next] = 0.5f;
                        if (data->b39[next] >= 30) {
                            func_80108B04(actor, next);
                        }
                    }
                }
                if (!data->b34[tooth]) {
                    func_80800350_chtoothyfish(actor, data, tooth);
                }
            }
        }
    }
}

void func_80801588_chtoothyfish();

s32 func_80800B68_chtoothyfish(Actor *actor, s32 msg, s32 msg_data)
{
    ToothyData_80800B68_chtoothyfish *data;
    f32 pos[3];
    f32 rot[3];
    s32 player;
    s32 i;

    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x49:
            if (actor->unk64_20) {
                player = func_800F54E4();
                func_8010573C(actor, 0.73f);
                func_80103014(actor);
                func_800EEC30(pos, -actor->rotation[0], actor->rotation[1],
                              actor->scale * 150.0f);
                func_800EF04C(pos, actor->position);
                func_800EFA4C(rot, 0.0f, actor->rotation[1], 0.0f);
                func_800F8294(player, pos);
                func_800F832C(player, rot);
                func_800F608C(player, 5);
                func_800F497C(player);
                func_800F4A2C(player, pos);
                func_800F49A8(player, 1);
                func_800F4A00(player, 1);
                func_800F49D4(player, func_8010D5DC, actor->unk0);
                func_800EEC30(pos, -actor->rotation[0], actor->rotation[1],
                              actor->scale * 350.0f);
                func_800EF04C(pos, actor->position);
                func_800F4A8C(player, pos, 2.0f);
                data->unk30 = 0.0f;
                actor->unk79_4 = 0xF;
                actor->unk64_20 = 0;
                actor->unk64_19 = 1;
                actor->unk58 = 5.0f;
                _capod_entrypoint_13(actor->unk0, 0, 0x2E, 0xA4C);
            }
            break;
        case 0x32:
            actor->unk64_19 = 0;
            break;
        case 0x3E:
            func_8080096C_chtoothyfish(actor, msg_data);
            return 1;
        case 0x3D:
            func_80801588_chtoothyfish(actor, msg_data);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            for (i = 0; i < 5; i++) {
                if (data->unk34[i]) {
                    func_800DF744(i + 3, 0);
                } else {
                    func_800DF744(i + 3, 1);
                }
            }
            return 1;
        default:
            return 0;
    }
    return 1;
}

void *chtoothyfish_entrypoint_0()
{
    return &D_80801870_chtoothyfish;
}

void func_80800E04_chtoothyfish(Actor *actor)
{
    Actor *fish;

    fish = func_80106790(actor->unk3C);
    _subaddieskeleton_entrypoint_2(actor->unk3C, actor->unk6C_0 + 4, actor->position);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808017C4_chtoothyfish);
    actor->scale = fish->scale;
    actor->rotation[2] = fish->rotation[2];
    actor->rotation[0] = fish->rotation[0];
    func_800EFCD8((f32 *) &actor->actorData[4],
                  func_800F1DF4(fish->position, actor->position), 3000.0f);
    *(f32 *) &actor->actorData[5] = 200.0f;
    *(f32 *) &actor->actorData[7] = -1000.0f;
    func_80103140(actor, (u16) (actor->unk6C_0 + 0x73A), actor->unk0->unk16);
}

void func_80800EDC_chtoothyfish(s32 unk_0)
{
}

void func_80800EE4_chtoothyfish(Actor *actor, s32 state)
{
    func_80101FDC(actor, state);
    switch (state) {
        case 2:
            actor->unk50 = func_800DC178(165.0f, 195.0f);
            break;
        case 4:
            actor->unk50 = func_800DC178(45.0f, 135.0f);
    }
}

void func_80800F6C_chtoothyfish(f32 *pos, f32 y_offset, f32 scale)
{
    s32 unk_0;
    s32 unk_1;

    unk_0 = func_800DC128(0, 5);
    unk_1 = func_800B53A4(unk_0);
    func_800BABB8(unk_1, pos, NULL, 1.0f, D_808018B8_chtoothyfish);
    func_800BA568(unk_1, (s16) (pos[1] + y_offset));
    func_800BA7C4(unk_1, 0.08f * scale, 0.15f * scale);
    func_800BA7FC(unk_1, 0.09f * scale, 0.18f * scale);
    func_800BA22C(unk_1, unk_0);
}

// Knocked-out tooth: tumbles down and settles on the floor.
void func_8080106C_chtoothyfish(Actor *actor)
{
    f32 delta[3];
    f32 dt;

    dt = func_800D8FF8();
    func_800EFA20(delta, (f32 *) &actor->actorData[4], dt);
    switch (actor->unk70_10) {
        case 1:
            func_800EF04C(actor->position, delta);
            ((f32 *) actor->actorData)[4] *= 0.7f;
            ((f32 *) actor->actorData)[6] *= 0.7f;
            ((f32 *) actor->actorData)[5] += ((f32 *) actor->actorData)[7] * dt;
            if (((f32 *) actor->actorData)[5] < -50.0f) {
                func_80800EE4_chtoothyfish(actor, 2);
            }
            actor->rotation[0] += 400.0f * dt;
            actor->rotation[1] += 200.0f * dt;
            if (func_800DC298(0.2f)) {
                func_80800F6C_chtoothyfish(actor->position, 200.0f, actor->scale);
            }
            break;
        case 2:
            func_800EF04C(actor->position, delta);
            ((f32 *) actor->actorData)[4] *= 0.7f;
            ((f32 *) actor->actorData)[6] *= 0.7f;
            ((f32 *) actor->actorData)[5] += ((f32 *) actor->actorData)[7] * dt;
            if (_subaddie3d_entrypoint_0(actor->position, 0.0f, actor->scale * -200.0f,
                                         (f32 *) &actor->actorData[1])) {
                if (((f32 *) actor->actorData)[1] + 20.0f * actor->scale <
                    delta[1] + actor->position[1]) {
                    actor->position[1] = delta[1] + actor->position[1];
                } else {
                    func_80800EE4_chtoothyfish(actor, 4);
                }
            } else if (func_80102D4C(actor, 4.0f)) {
                func_80800EE4_chtoothyfish(actor, 3);
            } else {
                func_80102B6C(actor, 4.0f);
            }
            if (func_800DC298(0.2f)) {
                func_80800F6C_chtoothyfish(actor->position, 200.0f, actor->scale);
            }
            break;
        case 3:
            ((f32 *) actor->actorData)[4] *= 0.7f;
            ((f32 *) actor->actorData)[6] *= 0.7f;
            ((f32 *) actor->actorData)[5] += ((f32 *) actor->actorData)[7] * dt;
            actor->position[0] += ((f32 *) actor->actorData)[4];
            actor->position[2] += ((f32 *) actor->actorData)[6];
            if (_subaddie3d_entrypoint_0(actor->position, 0.0f, actor->scale * -200.0f,
                                         (f32 *) &actor->actorData[1])) {
                if (((f32 *) actor->actorData)[1] + 50.0f * actor->scale <
                    delta[1] + actor->position[1]) {
                    actor->position[1] = delta[1] + actor->position[1];
                } else {
                    func_80800EE4_chtoothyfish(actor, 4);
                }
            } else {
                actor->position[1] += delta[1];
            }
            if (!func_80102D4C(actor, 3.0f)) {
                func_80102B6C(actor, 3.0f);
            }
            if (!func_80102CF4(actor, 3.0f)) {
                func_80102B2C(actor, 3.0f);
            }
            if (func_800DC298(0.1f)) {
                actor->unk50 = func_800DC178(140.0f, 220.0f);
            }
            if (func_800DC298(0.1f)) {
                actor->unk54 = actor->rotation[1] + func_800DC178(-90.0f, 90.0f);
            }
            if (func_800DC298(0.2f)) {
                func_80800F6C_chtoothyfish(actor->position, 200.0f, actor->scale);
            }
            break;
        case 4:
            if (((f32 *) actor->actorData)[1] + 10.0f * actor->scale < actor->position[1]) {
                actor->position[1] += ((f32 *) actor->actorData)[5] * dt;
            } else if (actor->position[1] < ((f32 *) actor->actorData)[1]) {
                actor->position[1] += 4.0f;
            }
            if (!func_80102D4C(actor, 8.0f)) {
                func_80102B6C(actor, 8.0f);
            } else {
                func_80800EE4_chtoothyfish(actor, 5);
            }
            break;
        case 5:
            if (((f32 *) actor->actorData)[1] + 10.0f * actor->scale < actor->position[1]) {
                actor->position[1] += ((f32 *) actor->actorData)[5] * dt;
            } else if (actor->position[1] <
                       ((f32 *) actor->actorData)[1] + 5.0f * actor->scale) {
                actor->position[1] += 4.0f;
            } else {
                ((ToothyBits *) actor)->unk7C_14 = 0;
            }
    }
}

// Spawns the loose tooth actor and sets the tooth's flag.
void func_80801588_chtoothyfish(Actor *actor, s32 tooth)
{
    Actor *tooth_actor;
    u8 *data;

    data = func_80100094(actor, 0);
    tooth_actor = func_801084B0(0x310, &actor);
    func_800DA544(tooth + 0x4F6);
    data[tooth + 0x34] = 1;
    tooth_actor->unk3C = actor->unk0;
    tooth_actor->unk6C_0 = tooth;
}

int chtoothyfish_entrypoint_1()
{
    return (int) &D_80801914_chtoothyfish;
}

extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_80101870();
// TU-NOTE: the overlay .data is defined here in C.
u8 D_80801760_chtoothyfish[24] = {0x0, 0x13, 0x5,  0x44, 0x0,  0xD,  0x0, 0xCC,
                                  0x1, 0x33, 0x0,  0x16, 0x7F, 0xFF, 0x0, 0x1,
                                  0xF, 0xA0, 0x1D, 0x4C, 0x0,  0x0,  0x0, 0x0};
u8 D_80801778_chtoothyfish[20] = {0x0,  0x13, 0x5, 0xCE, 0x0, 0xA,  0x0,  0x66, 0x0, 0x16,
                                  0x7F, 0xFF, 0x0, 0x1,  0xF, 0xA0, 0x1D, 0x4C, 0x0, 0x0};
u8 D_8080178C_chtoothyfish[16] = {0x0, 0x13, 0x3, 0xED, 0x0,  0xD,  0x0, 0x40,
                                  0x0, 0x4C, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_8080179C_chtoothyfish[16] = {0x0, 0x13, 0x3, 0xED, 0x0,  0xD,  0x0, 0x4C,
                                  0x0, 0x59, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_808017AC_chtoothyfish[24] = {0x0, 0x13, 0x5,  0x46, 0x0,  0xD, 0x0, 0xCC,
                                  0x0, 0xE6, 0x0,  0x16, 0x7D, 0x0, 0x0, 0x1,
                                  0xF, 0xA0, 0x1D, 0x4C, 0x0,  0x0, 0x0, 0x0};
u8 D_808017C4_chtoothyfish[24] = {0x0, 0x13, 0x5,  0x47, 0x0,  0xD, 0x0, 0xCC,
                                  0x0, 0xE6, 0x0,  0x16, 0x7D, 0x0, 0x0, 0x1,
                                  0xF, 0xA0, 0x1D, 0x4C, 0x0,  0x0, 0x0, 0x0};
u32 D_808017DC_chtoothyfish[14] = {0x0,        0x0,        0x40000000, 0x1190001,  0x3F99999A,
                                   0xFA0042,   0x3FC00000, 0xFA0042,   0x40000000, 0x11A0001,
                                   0x40000000, 0x11A0001,  0x40000000, 0x11A0001};
u8 D_80801814_chtoothyfish[68] = {
    0x0, 0x1D, 0x9, 0xD9, 0x0,  0x16, 0x10, 0x4,  0x0, 0x1,  0x0, 0x0,  0x0, 0x23,
    0x0, 0x0,  0x0, 0x0,  0x0,  0x32, 0x0,  0x0,  0x0, 0x1B, 0x0, 0x96, 0x0, 0xC8,
    0x0, 0x7,  0x0, 0x1,  0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0, 0x2B, 0x1, 0x80,
    0x4, 0x80, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40,
    0x0, 0x0,  0x0, 0x0,  0x0,  0x19, 0x0,  0x0,  0x0, 0x33, 0x0, 0x0};
u8 D_80801858_chtoothyfish[12] = {0x3E, 0x2E, 0x14, 0x7B, 0x3F, 0x2E,
                                  0x14, 0x7B, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801864_chtoothyfish[12] = {0x3E, 0xDC, 0x28, 0xF6, 0x3F, 0x68,
                                  0xF5, 0xC3, 0xBF, 0x80, 0x0,  0x0};
void *D_80801870_chtoothyfish = (void *) 0x02D4030F;
static u32 D_80801870_chtoothyfish_rest[17] = {0x6C50001,
                                               (u32) &D_808017DC_chtoothyfish,
                                               (u32) func_808004A4_chtoothyfish,
                                               (u32) func_808004A4_chtoothyfish,
                                               (u32) func_801018A4,
                                               0x2EE02AF8,
                                               0x0,
                                               0x0,
                                               0xC68,
                                               (u32) func_80800470_chtoothyfish,
                                               (u32) func_80108ED0,
                                               0x400000,
                                               (u32) func_80800000_chtoothyfish,
                                               (u32) func_80107C2C,
                                               0x0,
                                               (u32) func_80800B68_chtoothyfish,
                                               0x0};
u8 D_808018B8_chtoothyfish[92] = {
    0x0, 0x1D, 0x9, 0xD9, 0x0, 0x16, 0x10, 0x4,  0x0,  0x2C, 0x0, 0x0,  0x0, 0x64, 0x0, 0x0,
    0x0, 0x0,  0x0, 0xC8, 0x0, 0x0,  0x0,  0xB,  0x0,  0xF,  0x0, 0x1E, 0x0, 0xF,  0x0, 0x0,
    0x0, 0x1,  0x0, 0x0,  0x0, 0x23, 0x0,  0x0,  0x0,  0x0,  0x0, 0x32, 0x0, 0x0,  0x0, 0x1B,
    0x0, 0x96, 0x0, 0xC8, 0x0, 0x7,  0x0,  0x1,  0x0,  0x15, 0x0, 0x0,  0x0, 0xCC, 0x0, 0x2B,
    0x1, 0x80, 0x2, 0x80, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40,
    0x0, 0x0,  0x0, 0x0,  0x0, 0x19, 0x0,  0x0,  0x0,  0x33, 0x0, 0x0};
int D_80801914_chtoothyfish[19] = {0x2D50310,
                                   0x73A0001,
                                   0x0,
                                   (u32) func_8080106C_chtoothyfish,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x800,
                                   (u32) func_80800EDC_chtoothyfish,
                                   0x0,
                                   0x0,
                                   (u32) func_80800E04_chtoothyfish,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0,
                                   0x0};
