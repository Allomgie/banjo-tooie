#include "common.h"
extern s32 func_800DC298(f32);

extern int D_808012BC_chonearmbandit[];
extern int D_80801304_chonearmbandit[];
typedef union {
    s32 word;
    Actor **actors;
} BanditMessage30;
extern u8 D_80801280_chonearmbandit[];
typedef struct {
    s16 a, b;
} S16Pair;
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest72 : 10;
    u8 pad74[4];
    u32 pad78 : 29;
    u32 flag : 1;
    u32 rest78 : 2;
} BanditState;
typedef struct {
    u8 pad0[0x64];
    u32 pad64 : 2;
    u32 unk64_29 : 1;
    u32 pad64_0 : 29;
} BanditActor;
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800F54E4(void);
extern void func_8010D09C(s32, f32 *, f32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_800136E4(f32);
extern void *func_80100094(Actor *, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern f32 D_808011FC_chonearmbandit[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _subaddiejoy_entrypoint_10(Actor *, f32, f32);
extern s32 D_80801364_chonearmbandit[];
typedef struct {
    u8 local_0[0x64];
    u32 local_1 : 2;
    u32 local_2 : 1;
    u32 local_3 : 29;
} BanditFlags49;
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F20BC(f32, f32, f32);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern u8 func_801015D0[];
extern void func_800EFA4C(f32 *, void *, void *, f32);
extern void func_800BBCB8();
extern void func_800C4AF0(void *, void *);
extern void func_800FFAB0(void *);
extern void func_8010A570(void *);
extern void *D_808013A4_chonearmbandit;
extern void *D_808013DC_chonearmbandit;
extern int D_808013E8_chonearmbandit[];
typedef struct {
    u8 pad0[0x64];
    u32 pad64_30 : 2;
    u32 unk64_29 : 1;
    u32 pad64_0 : 29;
    u8 pad68[0x10];
    u32 pad78_3 : 29;
    u32 unk78_2 : 1;
    u32 pad78_0 : 2;
} BanditBits;
extern f32 D_808011F0_chonearmbandit[];
extern f32 D_8080134C_chonearmbandit[];
extern s32 func_8010C9B0(f32 *, s32);
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_8010D278(void);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80108B04(Actor *, s32);
extern s32 func_80101DDC(Actor *);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} OneArmBanditFlags;
extern u8 D_80801354_chonearmbandit[];
typedef union {
    f32 as_f32[3];
    s32 as_s32[3];
} DeferredPosition1864;
typedef union {
    f32 as_f32;
    s32 as_s32;
} DeferredAngle1864;
extern s32 D_8080139C_chonearmbandit[];
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chbaddiesetup_entrypoint_10();
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
int func_80800040_chonearmbandit();
void func_808006F8_chonearmbandit();
int func_80800AB8_chonearmbandit();
void func_808010AC_chonearmbandit();
void func_80801114_chonearmbandit();
s32 func_80801154_chonearmbandit();
void func_80800680_chonearmbandit();
int func_80800D00_chonearmbandit();

int chonearmbandit_entrypoint_0()
{
    return (int) &D_808012BC_chonearmbandit;
}

int chonearmbandit_entrypoint_1()
{
    return (int) &D_80801304_chonearmbandit;
}

void func_80800018_chonearmbandit(u8 *actor)
{
    *(f32 *) (actor + 0x24) = 400.0f;
    func_80800040_chonearmbandit();
}

int func_80800040_chonearmbandit(actor)
s32 actor;
{
    s32 data;
    data = func_80100094(actor, 1);
    _subaddierouteDll_entrypoint_3(actor, data | 0, actor + 4);
    _subaddierouteDll_entrypoint_1(actor);
}

void func_80800A14_chonearmbandit(Actor *actor, f32 volume);

s32 func_808008E0_chonearmbandit(Actor *actor, f32 angle_offset);

void func_80800740_chonearmbandit(Actor *actor, f32 angle_offset);

void func_8080007C_chonearmbandit(Actor *actor)
{
    f32 *pos;

    if (((BanditBits *) actor)->unk78_2) {
        return;
    }
    switch (actor->unk70_10) {
        case 1:
            if (((BanditBits *) actor)->unk64_29) {
                func_80800680_chonearmbandit(actor, 2);
                return;
            }
            if (func_8010C9B0(actor->position, 1500)) {
                func_80800680_chonearmbandit(actor, 4);
            }
            break;
        case 2:
            if (_subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_808011F0_chonearmbandit, 0.75f)) {
                _subaddiejoy_entrypoint_10(actor, 0.8f, 0.2f);
            }
            func_808008E0_chonearmbandit(actor, 0.0f);
            if (_subaddiejoy_entrypoint_6(actor, 1)) {
                func_80800680_chonearmbandit(actor, 3);
            } else if (_subaddiejoy_entrypoint_6(actor, 0)) {
                func_80800680_chonearmbandit(actor, 5);
            }
            if (!((BanditBits *) actor)->unk64_29) {
                func_80800680_chonearmbandit(actor, 3);
            }
            break;
        case 3:
            pos = actor->position;
            if (_subaddieaudioquick_entrypoint_3(actor, pos, D_808011F0_chonearmbandit,
                                                 0.75f)) {
                _subaddiejoy_entrypoint_10(actor, 0.8f, 0.2f);
            }
            func_80800A14_chonearmbandit(actor, 0.7f);
            func_808008E0_chonearmbandit(actor, 0.0f);
            if (func_80101E14(actor, 0.999f)) {
                if (((BanditBits *) actor)->unk64_29) {
                    if (!_subaddiejoy_entrypoint_6(actor, 1)) {
                        func_80800680_chonearmbandit(actor, 2);
                    }
                } else if (!func_8010C9B0(pos, 800)) {
                    func_80800680_chonearmbandit(actor, 4);
                }
            }
            break;
        case 4:
            pos = actor->position;
            _subaddieaudioquick_entrypoint_3(actor, pos, D_808011F0_chonearmbandit, 0.75f);
            if (func_80101E14(actor, 0.999f)) {
                if (((BanditBits *) actor)->unk64_29) {
                    func_80800680_chonearmbandit(actor, 2);
                    return;
                }
                if (!func_8010C9B0(pos, 1500)) {
                    func_80800680_chonearmbandit(actor, 1);
                    return;
                }
                if (func_8010C9B0(pos, 800)) {
                    func_80800680_chonearmbandit(actor, (func_8010D278() == 0x10) ? 6 : 2);
                }
                return;
            }
            func_80800740_chonearmbandit(actor, 0.0f);
            if (func_8010C9B0(pos, 1500)) {
                if (func_80102CF4(actor, 8.0f)) {
                    func_80800680_chonearmbandit(actor, 5);
                }
            } else {
                func_80800680_chonearmbandit(actor, 1);
            }
            break;
        case 5:
            pos = actor->position;
            _subaddieaudioquick_entrypoint_3(actor, pos, D_8080134C_chonearmbandit, 0.1f);
            if (func_80101E14(actor, 0.25f)) {
                func_80108B04(actor, 0);
            }
            if (func_80101DDC(actor)) {
                actor->unk58 -= func_800D8FF8();
                if (actor->unk58 < 0.0f) {
                    if (((BanditBits *) actor)->unk64_29) {
                        func_80800680_chonearmbandit(actor, 2);
                        return;
                    }
                    func_80800680_chonearmbandit(actor, func_8010C9B0(pos, 800)
                                                              ? ((func_8010D278() == 0x10) ? 6 : 2)
                                                              : 4);
                }
            }
            break;
        case 7:
            if (func_80101DDC(actor)) {
                func_80800680_chonearmbandit(actor, 1);
            }
            break;
        case 6:
            pos = actor->position;
            _subaddieaudioquick_entrypoint_3(actor, pos, D_808011F0_chonearmbandit, 0.75f);
            if (func_80101E14(actor, 0.999f)) {
                if (((BanditBits *) actor)->unk64_29) {
                    func_80800680_chonearmbandit(actor, 2);
                } else if (!func_8010C9B0(pos, 800)) {
                    func_80800680_chonearmbandit(actor, 4);
                }
            }
            func_808008E0_chonearmbandit(actor, 180.0f);
    }
}

s32 func_80800520_chonearmbandit(Actor *actor, s32 event, BanditMessage30 payload)
{
    switch (event) {
        case 0x3F:
            func_808006F8_chonearmbandit(actor, payload.word);
            break;
        case 0x40:
            _chexploder_entrypoint_4(actor, (*payload.actors)->position, 4);
            break;
        case 0x3D:
            if (!func_801072A8(actor))
                func_80800AB8_chonearmbandit(actor);
            break;
        case 0x90:
            func_80800D00_chonearmbandit(actor);
            break;
        case 2:
            if ((s32) actor->unk70_10 > 0 && !_subaddieDll_entrypoint_3(actor))
                func_80107070(actor, 1);
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0x38:
            func_80101074(D_80801280_chonearmbandit);
            return 5;
        default:
            return 0;
    }
    return 1;
}

s32 func_8080063C_chonearmbandit(s32 actor, s32 unk_1)
{
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(actor, unk_1);
}

void func_80800680_chonearmbandit(actor, state) Actor *actor;
s32 state;
{
    func_80102424(actor, state);
    if (state == 5) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801354_chonearmbandit);
        if (((OneArmBanditFlags *) actor)->local_0) {
            actor->unk58 = 0.36f;
        } else {
            actor->unk58 = 1.2f;
        }
    }
}

void func_808006F8_chonearmbandit(BanditState *actor, S16Pair unk_1)
{
    if (!actor->flag && actor->f72 != 7) {
        func_80800680_chonearmbandit(actor, 7);
    }
}

void func_80800740_chonearmbandit(Actor *actor, f32 angle_offset)
{
    f32 target_pos[3];
    f32 unk_3;
    f32 turn;
    f32 dt;

    if (((BanditActor *) actor)->unk64_29) {
        _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
        func_80102BF8(actor, 0.2f, 6.0f, 220.0f);
        return;
    }
    dt = func_800D8FF8();
    func_8010D09C(func_800F54E4(), target_pos, 0.8f);
    switch (actor->unk70_10) {
        case 2:
        case 3:
        case 6:
            if (_subaddierouteDll_entrypoint_4(actor)) {
                actor->unk54 = func_800136E4(func_80102D78(actor, target_pos) + angle_offset);
                _subaddierouteDll_entrypoint_7(actor, func_80100094(actor, 1),
                                               actor->rotation[1], actor->unk54, 200.0f,
                                               0x4000);
            }
            break;
        default:
            actor->unk54 = func_800136E4(func_80102D78(actor, target_pos) + angle_offset);
    }
    turn = func_800F1DCC(func_800F1FF0(actor->rotation[1], actor->unk54, 0.15f,
                                          dt * 4.0f, dt * 120.0f),
                            actor->rotation[1]);
    turn *= func_800F3780(func_80101F24(actor), (u8 *) D_808011FC_chonearmbandit, 3);
    actor->rotation[1] = func_800136E4(actor->rotation[1] + turn);
}

s32 func_808008E0_chonearmbandit(Actor *actor, f32 angle_offset)
{
    f32 saved_speed;
    f32 unk_3;
    f32 stick;
    s32 moving;

    saved_speed = *(f32 *) &actor->actorData[3];
    if (((OneArmBanditFlags *) actor)->local_0) {
        stick = _subaddiejoy_entrypoint_9(actor, 0, 0);
        unk_3 = func_80101F24(actor);
        *(f32 *) &actor->actorData[3] = func_800F3780(unk_3, D_808011FC_chonearmbandit, 3) *
                                          (actor->scale * (stick * 400.0f));
    } else {
        unk_3 = func_80101F24(actor);
        *(f32 *) &actor->actorData[3] =
            func_800F3780(unk_3, D_808011FC_chonearmbandit, 3) * (actor->scale * 400.0f);
    }
    func_80800740_chonearmbandit(actor, angle_offset);
    if (((OneArmBanditFlags *) actor)->local_0) {
        func_8010B990(actor, 0x205025);
    } else {
        func_8010B990(actor, 0x5425);
    }
    moving = 0;
    if (*(f32 *) &actor->actorData[3] > 0.0f) {
        moving = 1;
    }
    *(f32 *) &actor->actorData[3] = saved_speed;
    return moving;
}

void func_80800A14_chonearmbandit(Actor *actor, f32 volume)
{
    f32 bone_pos[3];
    if (_subaddieaudioquick_entrypoint_3(actor, actor->position,
                                         (u8 *) D_808011F0_chonearmbandit, volume)) {
        if (_subaddieskeleton_entrypoint_2(actor->unk0, 5, bone_pos)) {
            if (actor->position[1] < bone_pos[1])
                bone_pos[1] = actor->position[1];
            func_800BBCB8(bone_pos, bone_pos, 0x3F333333, 6, D_80801364_chonearmbandit);
        }
        _subaddiejoy_entrypoint_10(actor, 1.4f, 0.3f);
    }
}

int func_80800AB8_chonearmbandit(actor)
Actor *actor;
{
    f32 target[3];
    f32 spawn_pos[3];
    Actor *shot;
    f32 yaw;
    if (!_subaddieskeleton_entrypoint_2(actor->unk0, 4, spawn_pos)) {
        func_800EE7F8(spawn_pos, actor->position);
        spawn_pos[1] += actor->scale * 60.0f;
    }
    shot = func_80108528(0x35B, spawn_pos, (s32) actor->rotation[1], &actor);
    func_80102FDC(shot, actor->scale);
    func_8010D09C(func_800F54E4(), target, 0.8f);
    target[1] += 60.0f;
    if (((BanditFlags49 *) actor)->local_2) {
        yaw = func_800136E4(func_800F1DF4(shot->position, target));
        if (func_800F20BC(yaw, actor->rotation[1], 8.0f)) {
            shot->rotation[1] = yaw;
        } else {
            shot->rotation[1] = actor->rotation[1];
        }
    } else {
        s32 pad0;
        shot->rotation[1] = func_800136E4(func_800F1DF4(shot->position, target));
        yaw = func_800F1DCC(shot->rotation[1], actor->rotation[1]);
        if (yaw < -60.0f) {
            shot->rotation[1] = actor->rotation[1] - 60.0f;
        } else if (yaw > 60.0f) {
            shot->rotation[1] = actor->rotation[1] + 60.0f;
        }
    }
    shot->rotation[0] = func_800136E4(func_800F1828(shot->position, target));
    if (shot->rotation[0] > 180.0f) {
        if (shot->rotation[0] < 350.0f) {
            shot->rotation[0] = 350.0f;
        }
    } else if (shot->rotation[0] > 10.0f) {
        shot->rotation[0] = 10.0f;
    }
    func_80108944(shot, actor);
}

s32 func_80800E78_chonearmbandit();

int func_80800D00_chonearmbandit(Actor *actor)
{
    f32 pos[3];
    Actor *exploder;
    s32 slot;
    DeferredPosition1864 drop_pos;
    DeferredAngle1864 drop_angle;
    s32 drop_id;
    exploder = func_80106790(func_80101080(actor));
    _chexploder_entrypoint_9(exploder, 3, 0);
    _chexploder_entrypoint_9(exploder, 4, 1);
    _chexploder_entrypoint_6(exploder, 1000.0f, 1200.0f);
    _subaddiefade_entrypoint_9(actor, pos);
    _subaddiefade_entrypoint_11(exploder, pos);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_8080139C_chonearmbandit);
    _subaddiejoy_entrypoint_10(actor, 1.4f, 0.3f);
    *((u8 *) actor + 0x64) &= ~1;
    slot = func_80800E78_chonearmbandit(actor);
    if (slot)
        func_800D1000(slot, 8, actor->position, 1, 0);
    else if (func_8010A430(actor)) {
        drop_angle.as_f32 = func_800DC178(0.0f, 359.0f);
        if (func_800DC298(0.5f))
            drop_id = 0x18;
        else
            drop_id = 0x19;
        func_80103DFC(actor, drop_pos.as_f32);
        _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, drop_id, drop_pos.as_s32[0],
                                    drop_pos.as_s32[1], drop_pos.as_s32[2], drop_angle.as_s32);
    }
    if (!func_80107070(actor, 3))
        func_800FFAB0(actor);
}

s32 func_80800E78_chonearmbandit(s32 actor)
{
    s32 marker_idx;

    marker_idx = ((u32) *(u16 *) ((char *) actor + 0x76) >> 7) - 0x31;
    if (func_800D0A9C(marker_idx, 8) != 0) {
        return 0;
    }
    return marker_idx;
}

void func_80800EBC_chonearmbandit(Actor *actor)
{
    f32 dt;

    dt = func_800D8FF8();
    if (func_800D90A4(&actor->unk58) && !actor->unk7C_12 && !actor->unk64_20) {
        func_8010A570(actor);
        _subaddiefade_entrypoint_3(actor);
        actor->unk64_20 = 1;
    }
    actor->unk54 += dt * *(f32 *) &actor->actorData[4];
    if (func_8001210C(1))
        func_80801114_chonearmbandit(actor);
    if (actor->unk70_10 == 1)
        func_80801154_chonearmbandit(actor);
}

void func_80800F80_chonearmbandit(Actor *actor)
{
    f32 sign;

    sign = func_800DC298(0.5f) ? -1.0f : 1.0f;
    ((f32 *) actor->actorData)[4] = func_800DC178(600.0f, 800.0f) * sign;
    actor->unk58 = 4.0f;
    ((f32 *) actor->actorData)[3] = 1000.0f;
}

int func_80801008_chonearmbandit(unsigned long actor, s32 msg, s32 payload)
{
    s32 *payload_ref;
    s32 *payload_ptr;
    if (msg == 0x40) {
        payload_ptr = &payload;
        payload_ref = payload_ptr;
        func_808010AC_chonearmbandit(actor, *payload_ref | 0);
        return 1;
    }
    return 0;
}

void func_80801040_chonearmbandit(ALSeqPlayer *actor, s32 unk_1)
{
    f32 vec[3];
    void *anim;
    func_800EFA4C(vec, *(ALSeqMarker ***) ((char *) actor + 0x50),
                  *(ALSeqMarker ***) ((char *) actor + 0x54), 0);
    func_800DF47C(&func_801015D0, actor);
    anim = func_8010347C(*(ALSeqMarker ***) actor);
    func_800DE448(&((ALSeqMarker ***) actor)[1], vec,
                  *(ALVoiceState ***) ((char *) actor + 0x38), 0, anim);
}

void func_808010AC_chonearmbandit(actor, unused) void *actor;
void *unused;
{
    func_800BBCB8((char *) actor + 4, (char *) actor + 4, *(void **) ((char *) actor + 0x38),
                  6, &D_808013A4_chonearmbandit);
    func_800C4AF0((char *) actor + 4, &D_808013DC_chonearmbandit);
    func_8010A570(actor);
    func_800FFAB0(actor);
}

void func_80801114_chonearmbandit(actor) u8 *actor;
{
    func_800BBCB8(actor + 4, 0, *(s32 **) (actor + 0x38), 1, &D_808013E8_chonearmbandit);
}

s32 func_80801154_chonearmbandit(actor)
Actor *actor;
{
    s32 flags = 6;

    if (!actor->unk64_20) {
        flags = 0x100006;
    }
    if (func_8010B990(actor, flags) & 0x30) {
        func_801096C8(actor, 0);
        func_808010AC_chonearmbandit(actor, 0);
        return 1;
    }
    return 0;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
f32 D_808011F0_chonearmbandit[3] = {1.746342e-39f, 2.0414e-39f, 0.0f};
f32 D_808011FC_chonearmbandit[6] = {0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f};
u32 D_80801214_chonearmbandit[5] = {0x10000, 0x80000, 0x80000, 0x90000, 0xA0000};
u32 D_80801228_chonearmbandit[22] = {
    0x0,        0x0,       0x3F4CCCCD, 0x1800044, 0x3F4CCCCD, 0x1800001, 0x3F19999A, 0x1820001,
    0x3F4CCCCD, 0x1800001, 0x3F666666, 0x1810002, 0x3F4CCCCD, 0x1800001, 0x3FA00000, 0x17F0002,
    0x3F4CCCCD, 0x1800044, 0x3FA00000, 0x2,       0x3F4CCCCD, 0x1800044};
u8 D_80801280_chonearmbandit[60] = {0x0, 0x0, 0x0, 0x3,  0x40, 0x80, 0x0, 0x0, 0x0, 0xFD, 0x0, 0x0,
                                    0x0, 0x0, 0x0, 0x2A, 0x40, 0x40, 0x0, 0x0, 0x0, 0xFD, 0x0, 0x0,
                                    0x0, 0x0, 0x0, 0x12, 0x40, 0x0,  0x0, 0x0, 0x0, 0xFF, 0x0, 0x0,
                                    0x0, 0x0, 0x0, 0x43, 0x3F, 0xC0, 0x0, 0x0, 0x2, 0x42, 0x0, 0x0,
                                    0x0, 0x0, 0x0, 0x42, 0x3F, 0xE0, 0x0, 0x0, 0x2, 0x43, 0x0, 0x0};
int D_808012BC_chonearmbandit[18] = {0x1960144,
                                     0x6C90001,
                                     (u32) &D_80801228_chonearmbandit,
                                     (u32) func_8080007C_chonearmbandit,
                                     (u32) func_80105834,
                                     (u32) func_8080063C_chonearmbandit,
                                     0x9C40000,
                                     0x40000000,
                                     0x0,
                                     0x43050261,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0xC,
                                     (u32) func_80800018_chonearmbandit,
                                     (u32) func_80107C2C,
                                     -0x7FCDAFE3,
                                     (u32) func_80800520_chonearmbandit,
                                     (u32) &D_80801214_chonearmbandit};
int D_80801304_chonearmbandit[18] = {0x2EE035B,
                                     0x6CA0001,
                                     0x0,
                                     (u32) func_80800EBC_chonearmbandit,
                                     (u32) func_80105834,
                                     (u32) func_80801040_chonearmbandit,
                                     0x0,
                                     0x3F800000,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800F80_chonearmbandit,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBF0,
                                     (u32) func_80801008_chonearmbandit,
                                     0x0};
f32 D_8080134C_chonearmbandit[2] = {1.746731e-39f, 2.204052e-39f};
u8 D_80801354_chonearmbandit[16] = {0x0, 0x13, 0x5, 0x2F, 0x0, 0xD, 0x1, 0xC,
                                    0x1, 0x26, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
s32 D_80801364_chonearmbandit[14] = {0x1D09DD,  0x20C0C0, -0x3F7FFFEA, 0x80022,  0x9900CC,
                                     0x1000133, 0x150033, 0x99002B,    0xB300E6, 0xB000A,
                                     0x140005,  0x2002D,  0x12C0190,   0x0};
s32 D_8080139C_chonearmbandit[2] = {0x130413, 0x0};
void *D_808013A4_chonearmbandit = (void *) 0x001D075C;
static u32 D_808013A4_chonearmbandit_rest[13] = {
    0x150033,   0x990027, 0x6400C8,  0x6400C8, 0x2B00CC, 0x1000016, 0x1400001B,
    0xFE70FED4, 0x2D012C, 0x190001E, 0x50005,  0xD000A,  0x0};
void *D_808013DC_chonearmbandit = (void *) 0x0013052C;
static u32 D_808013DC_chonearmbandit_rest[2] = {0xD00F3, 0x10C0000};
int D_808013E8_chonearmbandit[14] = {0x1D09E6, 0x150033, 0x990027,   0x6400C8, 0x6400C8,
                                     0x2B004C, 0x660016, 0x10000024, 0x4C0066, 0xC000A,
                                     0x0,      0x0,      0x0,        0x0};
