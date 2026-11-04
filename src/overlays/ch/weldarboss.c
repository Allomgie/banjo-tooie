#include "common.h"

extern void *func_80100094(Actor *, u32);
extern s32 _subaddiefind_entrypoint_9(s32);
extern void func_800F82D4(s32, s32);
extern void func_800F7B9C(s32, s32);
extern Actor *_subaddielink_entrypoint_4(void *);
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EF030(f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_8010CD50(Actor *, s32);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _chbaddiesetup_entrypoint_5(s32, s32, s32, s32, s32, s32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void *D_808047C4_chweldarboss;
extern s32 D_8080480C_chweldarboss[];
extern void _plcamera_entrypoint_8();
extern void _subaddielink_entrypoint_0();
extern void func_800F608C();
extern void func_800FFAB0();
extern void func_80102424();
extern void func_80108B04();
extern void func_80109EEC();
extern s32 func_800D731C(s32);
extern void func_800DBE60(u8, s32, void *);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_8010D09C(s32, void *, f32);
extern u8 D_808049B4_chweldarboss[];
extern u8 D_808049DC_chweldarboss[];
extern f32 func_800DC178(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern u8 D_808049EC_chweldarboss[];
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_808049FC_chweldarboss[];
extern u8 D_80804A10_chweldarboss[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, s32 *, s32);
extern s32 D_80804A4C_chweldarboss[];
extern s32 D_80804A64_chweldarboss[];
extern s32 D_80804A7C_chweldarboss[];
extern s32 func_8010D490(f32 *, f32 *, f32, f32, s32);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern s32 func_800F6478();
extern s32 func_800F6590();
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F5D9C(s32, f32 *);
extern void func_800F8418(s32, f32 *);
extern u8 D_80804A94_chweldarboss[];
extern f32 func_800F5BF0(s32, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
typedef struct {
    u8 pad_0[0x44];
    f32 local_0[3];
    u8 pad_1[0x10];
    u8 local_1;
    u8 pad_2[0x15];
    s16 local_2;
} WeldarPlayerEvent;
extern u8 D_80804AA4_chweldarboss[];
typedef struct {
    u8 pad_0[0x64];
    u8 enabled;
    u8 pad_1[0x13];
    s16 player;
} WeldarCameraState1425;
extern s32 func_80110014(s32);
extern void _plcamera_entrypoint_9(s32, f32 *, f32);
extern u8 D_80804AB4_chweldarboss[];
extern void func_800D2498(int, int, int);
extern void _mlwave_entrypoint_0(void *param_0, f32 param_1, f32 param_2);
extern void _mlwave_entrypoint_7(void *param_0, f32 param_1);
extern void func_800BF744(s32 param_0, s32 param_1);
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern s32 _mlwave_entrypoint_8(void *, f32);
extern void _chweldarboss_entrypoint_2(void);
extern f32 func_800F5628(void *);
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct {
    u8 pad_0[0x30];
    u8 local_0[0x50];
    f32 local_1;
    s32 local_2;
} WeldarLinkedPhase;
extern f32 func_800F13C4(f32, f32);
extern void _capod_entrypoint_14(void);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
typedef struct {
    u8 pad0[0x1A];
    u16 unk1A_5 : 11;
    u16 pad1A_0 : 5;
    u8 pad1C[8];
    u32 unk24_22 : 10;
    u32 pad24_0 : 22;
} WeldarMsgObj;
typedef struct {
    u8 pad0[0x30];
    u8 unk30[0x31];
    u8 unk61;
    u8 pad62[4];
    u8 unk66;
    u8 pad67;
    u8 unk68[8];
} WeldarData;
typedef struct {
    f32 v[3];
} WeldarVec;
typedef union {
    s32 i;
    void *p;
    struct {
        s16 a;
        s16 b;
    } h;
} WeldarArg;
extern WeldarVec D_808048EC_chweldarboss;
extern void func_800F79DC(s32, s32, Unk80132ED0 *);
extern s32 _sueggmisc_entrypoint_0(void *);
extern void func_8010114C(void *, s32, s32);
extern s32 func_80101080(void);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern void _chexploder_entrypoint_13(Actor *, s32);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chexploder_entrypoint_8(Actor *, f32, f32);
extern void _chexploder_entrypoint_9(Actor *, s32, s32);
extern void func_80101010(f32 *);
extern void func_800F18FC(f32 *, WeldarVec *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void _subaddielink_entrypoint_3();
extern void func_800FDC28(s32);
extern s32 func_800D395C(void);
extern u8 D_808048F8_chweldarboss[];
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern u8 D_80804908_chweldarboss[];
extern s32 func_80102320(Actor *, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, void *, s32);
extern void func_800C31DC(s32, f32);
extern u8 D_80804918_chweldarboss[];
extern u8 D_80804928_chweldarboss[];
extern u8 D_80804970_chweldarboss[];
extern u8 D_80804980_chweldarboss[];
extern u8 D_80804990_chweldarboss[];
extern u8 D_808049A4_chweldarboss[];
extern void *func_800E1540(s32);
extern void func_800E13F0(void *, f32);
extern void func_800E1410(void *, f32, f32);
extern void func_800187B4(s32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x65];
    u8 active;
    u8 pad_1[0x12];
    s16 id;
} WeldarContactState;
typedef struct {
    u8 pad0[0xA4];
    f32 unkA4;
} WeldarLocal;
extern s32 func_800F6438(s32);
extern s32 func_800F6AA4(s32);
extern void func_800F796C(s32, s32);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
typedef struct {
    u8 pad_0[8];
    f32 local_0;
    s32 local_1;
} WeldarLightState;
extern u8 D_80804AC8_chweldarboss[];
extern u8 D_80804ABC_chweldarboss[];
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800C8E54(s32, f32, f32);
extern void func_800DF500(f32, f32, f32);
int func_80802214_chweldarboss();
void func_80802F14_chweldarboss();
void func_80803080_chweldarboss();
s32 func_80803184_chweldarboss();
void func_808034A0_chweldarboss();
void func_80803CF0_chweldarboss();
void func_808041C4_chweldarboss();
void func_80801AA0_chweldarboss();
void func_808023F8_chweldarboss();
void func_8080247C_chweldarboss();
void func_808026BC_chweldarboss();
void func_80803528_chweldarboss();
s32 func_808038F8_chweldarboss();
s32 func_80803DD8_chweldarboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800018_chweldarboss(),
    func_808002BC_chweldarboss(), func_8080030C_chweldarboss(), func_80801944_chweldarboss();

void func_80801F30_chweldarboss();
int func_80802100_chweldarboss(Actor *param_0, s32 param_1);
void func_8080227C_chweldarboss(Actor *param_0, s32 param_1);
void func_80802ABC_chweldarboss(Actor *param_0, f32 param_1);
void func_80802B1C_chweldarboss(Actor *param_0);
f32 func_80802C9C_chweldarboss(Actor *param_0, s32 param_1);
void func_80802D2C_chweldarboss(Actor *param_0, s32 param_1, s32 param_2);
void func_80802E80_chweldarboss();
void func_80802FE4_chweldarboss(Actor *param_0, s32 param_1);
void func_808032A8_chweldarboss(Actor *param_0);
f32 func_80803378_chweldarboss(Actor *param_0);
int func_808033D8_chweldarboss(s32 param_0);
s32 func_8080340C_chweldarboss(Actor *this);
void func_80803460_chweldarboss(s32 param_0);
void func_808035D0_chweldarboss(s32 param_0);
void func_80803624_chweldarboss(u8 *param_0);
void func_8080367C_chweldarboss(void *param_0);
void func_808036C8_chweldarboss(s32 param_0);
void func_8080373C_chweldarboss(s32 param_0);
void func_80803770_chweldarboss(Actor *param_0);
s32 func_80803B48_chweldarboss(void *param_0);
void func_80803C18_chweldarboss(Actor *param_0);
void func_80803D64_chweldarboss();
s32 func_80803D98_chweldarboss(s32 param_0);
void func_80804230_chweldarboss();

void *chweldarboss_entrypoint_0()
{
    return &D_808047C4_chweldarboss;
}

s32 chweldarboss_entrypoint_1(void)
{
    return (s32) &D_8080480C_chweldarboss;
}

// Init: skips spawning if Weldar is already dead or retry is not allowed.
void func_80800018_chweldarboss(actor) Actor *actor;
{
    u8 *data;
    s32 player;
    s32 i;

    data = func_80100094(actor, 0);
    if (_glcutDll_entrypoint_19(0x8A)) {
        func_800FFAB0(actor);
        return;
    }
    if (!_glcutDll_entrypoint_20()) {
        if (func_800DA298(0x18C)) {
            _chintrotext_entrypoint_2(1);
            func_800FFAB0(actor);
            return;
        }
        if (func_800DA298(0x174)) {
            s32 retry_player;
            retry_player = func_800F54E4();
            if (func_800F6438(retry_player) && !func_800F64A4(retry_player, 1)) {
                func_800FFAB0(actor);
                return;
            }
        }
    }
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x32, data, 1);
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x33, (f32 *) (data + 0x18), 1);
    actor->rotation[1] = func_80102D78(actor, (f32 *) data);
    func_800EE7F8((f32 *) (data + 0x38), actor->position);
    _subaddielink_entrypoint_0(data + 0x30);
    func_80108B04(actor, 0);
    func_80109EEC(actor, 0x40);
    *(s16 *) (data + 0xAC) = 1;
    func_800BF744(3, 0);
    for (i = 0; i < 6; i++) {
        data[0x68 + i] = 1;
    }
    data[0x6F] = 6;
    *(s16 *) (data + 0x76) = -1;
    *(s16 *) (data + 0x78) = -1;
    *(f32 *) (data + 0xB4) = 0.25f;
    player = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(actor->position, (f32 *) data);
        func_80102424(actor, 0x33);
        ((u8 *) actor)[0x7B] = (((u8 *) actor)[0x7B] & ~0xC0) | 0x40;
    } else if (func_800DA298(0x174)) {
        func_800EE7F8(actor->position, (f32 *) data);
        func_800F608C(player, 1);
        func_800F8294(player, (f32 *) (data + 0x18));
        func_800F497C(player);
        _plcamera_entrypoint_8(player);
        func_80801AA0_chweldarboss(actor, 6);
        func_80802214_chweldarboss(actor, 0x1356, 15);
        func_80803CF0_chweldarboss(actor, 0x11, 0x30);
        data[0x61] = 1;
        ((u8 *) actor)[0x7B] = (((u8 *) actor)[0x7B] & ~0xC0) | 0x40;
    } else if (func_800D395C()) {
        func_80801AA0_chweldarboss(actor, 2);
    } else {
        _chintrotext_entrypoint_2(1);
        actor->unk64_16 = 0;
    }
}

void func_808002BC_chweldarboss(actor) s32 actor;
{
    Actor *data;
    data = func_80100094(actor, 0);
    *(u8 *) ((char *) data + 0xB0) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) data + 0xB0));
    *(u8 *) ((char *) data + 0xB1) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) data + 0xB1));
    *(u8 *) ((char *) data + 0xB2) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) data + 0xB2));
}

u8 B_80804AE0_chweldarboss[16];

// Per-frame boss state machine.
void func_8080030C_chweldarboss(actor) Actor *actor;
{
    extern u8 D_808047B8_chweldarboss[];
    extern u8 D_80804854_chweldarboss[];
    extern u8 D_80804864_chweldarboss[];
    extern u8 D_80804874_chweldarboss[];
    extern u8 D_80804880_chweldarboss[];
    extern u8 D_808048B4_chweldarboss[];
    extern void _chbaddiesetup_entrypoint_10(void);

    u8 *data;
    s32 deflect;
    f32 player_pos[3];

    data = func_80100094(actor, 0);
    deflect = 0;

    *(s16 *) (data + 0x78) = func_80803D98_chweldarboss(actor);

    func_8080367C_chweldarboss(actor);

    func_800F5A00(*(s16 *) (data + 0x78), player_pos);

    switch (actor->unk70_10) {
        case 1:
            if (func_8010CA74(actor->position, 0x1B58)) {
                if (func_80803B48_chweldarboss(func_800F54E4())) {
                    if (func_800F64A4(func_800F54E4(), 1)) {
                        func_80801AA0_chweldarboss(actor, 2);
                    }
                }
            }
            break;

        case 2:
            if (*(u8 *) (data + 0x70) == 0) {
                *(u8 *) (data + 0x70) = 1;
                func_80101180(0x431, 8, 0);
            }
            break;

        case 3: {
            f32 speed;
            speed = func_80802C9C_chweldarboss(actor, 0) * 500.0f;
            func_800EF1B8(actor->position, actor->rotation[1], func_800D8FF8() * speed);
            if (func_800D9078(data + 0xB4)) {
                func_80802214_chweldarboss(actor, 0x1366, 0x44);
            }
            if (func_800F0064(actor->position, 200.0f, (f32 *) data)) {
                func_80801AA0_chweldarboss(actor, 4);
            }
            break;
        }

        case 4:
            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 5);
            }
            break;

        case 5:
            if (!func_800DA298(0x6AD)) {
                func_80802214_chweldarboss(actor, 0x1355, 6);

                func_80801AA0_chweldarboss(actor, 6);
            }
            break;

        case 7: {
            s32 at_target;
            f32 dt;
            f32 forward_speed;
            f32 turn_speed;

            at_target = func_800F0064(actor->position, 200.0f, B_80804AE0_chweldarboss);

            func_80802F14_chweldarboss(actor, 0);

            if (at_target == 0) {
                dt = func_800D8FF8();

                forward_speed = func_80802C9C_chweldarboss(actor, 1) * 700.0f;

                turn_speed = func_80802C9C_chweldarboss(actor, 2) * 100.0f;

                actor->unk54 = func_80102D78(actor, B_80804AE0_chweldarboss);

                func_80102B2C(actor, turn_speed * dt);

                func_800EF1B8(actor->position, actor->rotation[1], forward_speed * dt);
            } else if (func_80101E14(actor, 0.999f)) {
                func_80801AA0_chweldarboss(actor, 8);

                *(u8 *) (data + 0x63) = func_808033D8_chweldarboss(actor);
            }
            break;
        }

        case 8: {
            f32 dt;
            f32 turn_speed;

            dt = func_800D8FF8();

            turn_speed = func_80802C9C_chweldarboss(actor, 2) * 100.0f;

            actor->unk54 = func_8010CD50(actor, *(s16 *) (data + 0x78));

            func_80102B2C(actor, turn_speed * dt);

            func_80802F14_chweldarboss(actor, 0);

            if (func_80102CF4(actor, 10.0f) && func_80101E14(actor, 0.999f)) {
                func_80801AA0_chweldarboss(actor, 9);
            }
            break;
        }

        case 9:
            func_80802F14_chweldarboss(actor, 0);

            if (func_80101E14(actor, 0.3f)) {
                func_80108B04(actor, 1);
            }

            if (func_80101DDC(actor)) {
                (*(u8 *) (data + 0x63))--;

                if (*(u8 *) (data + 0x63) == 0) {
                    func_80801AA0_chweldarboss(actor, 0xA);
                } else {
                    func_80801AA0_chweldarboss(actor, 8);
                }
            }
            break;

        case 10:
            func_80802E80_chweldarboss(actor);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0xB);
            }
            break;

        case 11:
            func_80802D2C_chweldarboss(actor, 0x10, 0xC);
            break;

        case 12:
            func_80802FE4_chweldarboss(actor, 0xD);
            break;

        case 13:
            func_80802F14_chweldarboss(actor, 0);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 8);

                *(u8 *) (data + 0x63) = func_808033D8_chweldarboss(actor);
            }
            break;

        case 14:
            if (func_80101DDC(actor)) {
                if (*(u8 *) (data + 0x7C) == 0) {
                    *(u8 *) (data + 0x7C) = 1;

                    func_80803CF0_chweldarboss(actor, 0x22, 0x30);

                    func_80802214_chweldarboss(actor, 0x1359, 6);

                    func_80801AA0_chweldarboss(actor, 0xF);
                } else {
                    func_80803D64_chweldarboss(actor);

                    func_80801AA0_chweldarboss(actor, 0x12);

                    *(u8 *) (data + 0x63) = 3;
                }
            }
            break;

        case 16:
            func_808032A8_chweldarboss(actor);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x11);
            }
            break;

        case 17:
            if (func_800D9078(&actor->unk58)) {
                func_800F82D4(*(s16 *) (data + 0x76), 0);

                func_80803D64_chweldarboss(actor);

                func_80801AA0_chweldarboss(actor, 8);

                *(u8 *) (data + 0x63) = func_808033D8_chweldarboss(actor);

                *(s16 *) (data + 0x76) = -1;
            }
            break;

        case 18: {
            f32 dt;
            f32 turn_speed;

            dt = func_800D8FF8();

            turn_speed = func_80802C9C_chweldarboss(actor, 2) * 100.0f;

            actor->unk54 = func_8010CD50(actor, *(s16 *) (data + 0x78));

            func_80102B2C(actor, turn_speed * dt);

            func_80802F14_chweldarboss(actor, 0);

            if (func_80102CF4(actor, 10.0f) && func_80101E14(actor, 0.999f)) {
                func_80801AA0_chweldarboss(actor, 0x13);
            }
            break;
        }

        case 19:
            if (func_80101E14(actor, 0.3f)) {
                _subaddieaudioquick_entrypoint_2(actor, data + 0x44, D_80804854_chweldarboss);

                func_80108B04(actor, 2);

                (*(u8 *) (data + 0x63))--;
            }

            func_80802F14_chweldarboss(actor, 0);

            if (func_80101DDC(actor)) {
                if (*(u8 *) (data + 0x63) == 0) {
                    func_80801AA0_chweldarboss(actor, 0x14);
                } else {
                    func_80801AA0_chweldarboss(actor, 0x12);
                }
            }
            break;

        case 20: {
            s32 minion_count;
            minion_count = _subaddiefind_entrypoint_9(0x43E) + _subaddiefind_entrypoint_9(0x43F) +
                       _subaddiefind_entrypoint_9(0x440);
            func_80802F14_chweldarboss(actor, 0);
            if (minion_count == 0) {
                func_80801AA0_chweldarboss(actor, 0x15);
            }
            break;
        }

        case 21:
            func_80802E80_chweldarboss(actor);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x16);
            }
            break;

        case 22:
            func_80802D2C_chweldarboss(actor, 0x1A, 0x17);
            break;

        case 23:
            func_80802FE4_chweldarboss(actor, 0x18);
            break;

        case 24:
            func_80802F14_chweldarboss(actor, 0);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x12);

                *(u8 *) (data + 0x63) = 3;
            }
            break;

        case 25:
            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x1C);
            }
            break;

        case 26:
            func_808032A8_chweldarboss(actor);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x1B);
            }
            break;

        case 27:
            if (func_800D9078(&actor->unk58)) {
                func_800F82D4(*(s16 *) (data + 0x76), 0);

                func_80803D64_chweldarboss(actor);

                func_80801AA0_chweldarboss(actor, 0x12);

                *(u8 *) (data + 0x63) = 3;
                *(s16 *) (data + 0x76) = -1;
            }
            break;

        case 28:
            func_80802F14_chweldarboss(actor, 0);

            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_808047B8_chweldarboss,
                                             0.15f);

            if (func_80101E14(actor, 0.85f)) {
                func_80801AA0_chweldarboss(actor, 0x1D);

                *(f32 *) (data + 0x5C) = 3000.0f;
            }
            break;

        case 29: {
            f32 angle;
            *(f32 *) (data + 0x5C) -= func_800D8FF8() * 1000.0f;
            actor->position[1] += func_800D8FF8() * *(f32 *) (data + 0x5C);
            if (*(s16 *) (data + 0x74) == 0 && actor->position[1] > 2750.0f) {
                if (func_800EF030(player_pos) > 360000.0f) {
                    angle = func_800F1DF4(player_pos, (f32 *) B_80804AE0_chweldarboss);
                    actor->position[0] = player_pos[0];
                    actor->position[2] = player_pos[2];
                    func_800EF1B8(actor->position, angle, 600.0f);
                }
                *(s16 *) (data + 0x74) = 1;
                func_80803D64_chweldarboss(actor);
            }
            if (*(s16 *) (data + 0x74) != 0) {
                if (func_800EFC7C(player_pos, actor->position) > 2500.0f) {
                    func_800EF1B8(actor->position, func_80102D78(actor, player_pos),
                                  func_800D8FF8() * 600.0f);
                }
            }
            if (*(f32 *) (data + 0x5C) < 0.0f) {
                func_80801AA0_chweldarboss(actor, 0x1E);
                func_8010A570(actor);
            }
            break;
        }

        case 30:
            *(f32 *) (data + 0x5C) -= func_800D8FF8() * 1000.0f;

            actor->position[1] += func_800D8FF8() * *(f32 *) (data + 0x5C);

            if (actor->position[1] > 1500.0f) {
                if (func_800EFC7C(player_pos, actor->position) > 2500.0f) {
                    func_800EF1B8(actor->position, func_80102D78(actor, player_pos),
                                  func_800D8FF8() * 600.0f);
                }
            }

            func_80803528_chweldarboss(actor, player_pos);

            if (actor->position[1] < 0.0f) {
                actor->position[1] = 0;

                func_80802B1C_chweldarboss(actor);

                func_808035D0_chweldarboss(actor);

                func_80801AA0_chweldarboss(actor, 0x1F);

                func_8010A590(actor);
            }
            break;

        case 31:
            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x20);

                actor->unk58 = 10.0f;
            }
            break;

        case 32: {
            f32 dt;
            f32 forward_speed;
            f32 turn_speed;

            dt = func_800D8FF8();

            forward_speed = func_80802C9C_chweldarboss(actor, 1) * 1400.0f;

            turn_speed = func_80802C9C_chweldarboss(actor, 2) * 160.0f;

            actor->unk54 = func_8010CD50(actor, *(s16 *) (data + 0x78));

            func_80102B2C(actor, turn_speed * dt);

            func_800EF1B8(actor->position, actor->rotation[1], forward_speed * dt);

            actor->position[0] = func_800F0D50(actor->position[0], -2000.0f, 2000.0f);

            actor->position[2] = func_800F0D50(actor->position[2], -2000.0f, 2000.0f);

            deflect = 1;

            func_80802F14_chweldarboss(actor, 0);

            if (func_800D90A4(&actor->unk58)) {
                func_80801AA0_chweldarboss(actor, 0x21);
            }
            break;
        }

        case 33:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_808047B8_chweldarboss,
                                             0.15f);

            func_80802F14_chweldarboss(actor, 0);

            if (func_80101E14(actor, 0.85f)) {
                func_80801AA0_chweldarboss(actor, 0x22);

                *(f32 *) (data + 0x5C) = 3000.0f;
            }
            break;

        case 34:
            *(f32 *) (data + 0x5C) -= func_800D8FF8() * 1000.0f;

            actor->position[1] += func_800D8FF8() * *(f32 *) (data + 0x5C);

            if (func_800EFC7C(B_80804AE0_chweldarboss, actor->position) > 2500.0f) {
                func_800EF1B8(actor->position, func_80102D78(actor, B_80804AE0_chweldarboss),
                              func_800D8FF8() * 600.0f);
            }

            if (*(f32 *) (data + 0x5C) < 0.0f) {
                func_80801AA0_chweldarboss(actor, 0x23);

                func_8010A570(actor);
            }
            break;

        case 35:
            *(f32 *) (data + 0x5C) -= func_800D8FF8() * 1000.0f;

            actor->position[1] += func_800D8FF8() * *(f32 *) (data + 0x5C);

            if (*(s16 *) (data + 0x74) == 0 && actor->position[1] < 3000.0f) {
                _subaddieaudioquick_entrypoint_2(actor, data + 0x44, D_80804864_chweldarboss);

                *(s16 *) (data + 0x74) = 1;

                func_80803CF0_chweldarboss(actor, 0x3C, 0x30);
            }

            if (actor->position[1] > 1500.0f) {
                if (func_800EFC7C(B_80804AE0_chweldarboss, actor->position) > 2500.0f) {
                    func_800EF1B8(actor->position,
                                  func_80102D78(actor, B_80804AE0_chweldarboss),
                                  func_800D8FF8() * 600.0f);
                }
            }

            func_80803528_chweldarboss(actor, player_pos);

            if (actor->position[1] < 0.0f) {
                actor->position[1] = 0;

                func_80802B1C_chweldarboss(actor);

                func_808035D0_chweldarboss(actor);

                func_80801AA0_chweldarboss(actor, 0x24);

                func_8010A590(actor);
            }
            break;

        case 36:
            if (func_80101DDC(actor)) {
                func_80803D64_chweldarboss(actor);

                func_80801AA0_chweldarboss(actor, 0x25);
            }
            break;

        case 37:
            func_80802E80_chweldarboss(actor);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x26);
            }
            break;

        case 38:
            func_80802D2C_chweldarboss(actor, 0x2A, 0x27);
            break;

        case 39:
            func_80802FE4_chweldarboss(actor, 0x28);
            break;

        case 40:
            func_80802F14_chweldarboss(actor, 0);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x1C);
            }
            break;

        case 41:
            if (func_80101DDC(actor)) {
                if (*(u8 *) (data + 0x62) == 0) {
                    func_80801AA0_chweldarboss(actor, 0x2C);
                } else {
                    *(u8 *) (data + 0x67) = 1;

                    func_80801AA0_chweldarboss(actor, 0x2D);
                }
            }
            break;

        case 42:
            func_808032A8_chweldarboss(actor);

            if (func_80101DDC(actor)) {
                func_80801AA0_chweldarboss(actor, 0x2B);
            }
            break;

        case 43:
            if (func_800D9078(&actor->unk58)) {
                func_800F82D4(*(s16 *) (data + 0x76), 0);

                func_80801AA0_chweldarboss(actor, 0x1C);

                *(s16 *) (data + 0x76) = -1;
            }
            break;

        case 45:
            func_80803624_chweldarboss(actor);
            break;

        case 46: {
            f32 burst_pos[3];

            if (func_800D9078(&actor->unk58)) {
                func_800EE7F8(burst_pos, actor->position);

                burst_pos[1] += 300.0f;

                *(u8 *) (data + 0x6E) = 0;

                _chbaddiesetup_entrypoint_5((s32) _chbaddiesetup_entrypoint_10, 5,
                                            ((s32 *) burst_pos)[0], ((s32 *) burst_pos)[1],
                                            ((s32 *) burst_pos)[2],
                                            *(s32 *) ((char *) actor + 0x48));

                func_800BBCB8(burst_pos, burst_pos, 3.0f, 1, D_80804880_chweldarboss);

                func_800BBCB8(burst_pos, burst_pos, 1.0f, 6, D_808048B4_chweldarboss);

                _chexploder_entrypoint_5(actor, 0x86F, actor->position, actor->rotation[1],
                                         actor->scale, 3);

                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80804874_chweldarboss);
            }

            func_80803624_chweldarboss(actor);
            break;
        }

        case 47:
            if (func_800D9078(&actor->unk58)) {
                func_800DA544(0x18C);
                func_80101180(0x345, 5, 0);
            }
            break;

        case 48:
            if (func_800D9078(&actor->unk58)) {
                func_80801AA0_chweldarboss(actor, 0x31);
            }
    }

    func_808023F8_chweldarboss(actor);
    func_8080247C_chweldarboss(actor);
    func_808026BC_chweldarboss(actor);
    func_80803770_chweldarboss(actor);
    func_80803C18_chweldarboss(actor);
    func_808034A0_chweldarboss(actor);

    if (deflect != 0) {
        f32 radius;

        radius = 600.0f;
        _sudeflect_entrypoint_1(actor->position, radius, 0, radius, 4);
    }
}

// Message handler.
s32 func_808014CC_chweldarboss(Actor *actor, s32 msg, WeldarArg arg)
{
    WeldarData *data;
    WeldarMsgObj *hit_msg;
    void *hit_obj;
    s32 unk_0; // Matching: unused local needed for the match.
    Actor *source;
    Actor *source_b;
    f32 knock_pos[3];
    f32 angle;
    WeldarVec dir;
    f32 offset[2];
    f32 push_pos[3];

    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x2E:
            func_80801F30_chweldarboss(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            return 1;
        case 0xB:
            return func_80802100_chweldarboss(actor, arg.i);
        case 0x3D:
            func_8080227C_chweldarboss(actor, arg.i);
            return 1;
        case 0x3F:
            hit_msg = *(WeldarMsgObj **) &arg;
            if (hit_msg->unk24_22 != 0) {
                break;
            }
            switch (actor->unk70_10) {
                case 0xB:
                case 0xC:
                case 0x10:
                case 0x16:
                case 0x17:
                case 0x1A:
                case 0x26:
                case 0x27:
                case 0x2A:
                    break;
                case 0x20:
                    func_80801AA0_chweldarboss(actor, 0x21);
                default:
                    func_800F79DC(hit_msg->unk1A_5, 7, actor->unk0);
            }
            break;
        case 0x40:
            hit_obj = *(void **) &arg;
            if (func_80803DD8_chweldarboss(actor) && _sueggmisc_entrypoint_0(hit_obj)) {
                func_8010114C(hit_obj, 0x2C, 0);
            }
            break;
        case 0x90:
            source = func_80106790(func_80101080());
            switch (arg.i) {
                case 0x86E:
                    _chexploder_entrypoint_15(source, 2, 1.0f);
                    _chexploder_entrypoint_13(source, 1);
                    return 1;
                case 0x86F:
                    actor->unk64_16 = 0;
                    _chexploder_entrypoint_6(source, 1000.0f, 1200.0f);
                    return 1;
                case 0x870:
                    _chexploder_entrypoint_6(source, 3000.0f, 3000.0f);
                    _chexploder_entrypoint_8(source, 450.0f, 450.0f);
                    _chexploder_entrypoint_9(source, 1, 1);
                    _chexploder_entrypoint_9(source, 2, 1);
                    _chexploder_entrypoint_13(source, 0xB);
                    _chexploder_entrypoint_8(source, 320.0f, 320.0f);
            }
            break;

        case 0x8D:
            source_b = func_80106790(func_80101080());
            switch (arg.i) {
                case 0x86E:
                    angle = func_800F1DF4(actor->position, source_b->position);
                    func_800EE7F8(knock_pos, source_b->position);
                    func_800EF1B8(knock_pos, angle, -200.0f);
                    func_80101010(knock_pos);
                    data->unk68[data->unk66] = 0;
                    data->unk66++;
                    break;

                case 0x870:
                    dir = D_808048EC_chweldarboss;
                    func_800F18FC(source_b->position, &dir, offset);
                    func_800EE7F8(push_pos, source_b->position);
                    func_800EF214(push_pos, -offset[0], offset[1], -500.0f);
                    push_pos[1] -= 200.0f;
                    func_80101010(push_pos);
                    return 1;
                default:
                    return 0;
            }
            break;
        case 7:
            func_80801AA0_chweldarboss(actor, 0x30);
            return 1;
        case 0x95:
            _subaddielink_entrypoint_3(data->unk30);
            if (data->unk61) {
                func_800FDC28(1);
                data->unk61 = 0;
            }
            break;
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            func_80802214_chweldarboss(actor, 0xCEB, 0x4E);
            return 1;
        case 0x9F:
            func_800FDC28(0);
            func_8080373C_chweldarboss(actor);
            func_80801AA0_chweldarboss(actor, 0x32);
            func_80803D64_chweldarboss(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

// Updates the linked torch light from two skeleton points.
void func_80801944_chweldarboss(actor, unk_0) Actor *actor;
s32 unk_0;
{
    u8 *data;
    u8 *cursor;
    s32 i;
    s32 unk_1;
    f32 saved_pos[1];
    Actor *light;
    f32 *bone_a;
    f32 rot[2];
    f32 *bone_b;

    data = func_80100094(actor, 0);
    unk_1 = func_800D731C(actor->unk0->unk14);
    if (unk_1)
        func_800DBE60(unk_1, 0, *(void **) (data + 0x84));
    for (i = 0, cursor = data; i < 6; i++, cursor++) {
        func_800DF744(i + 3, cursor[0x68]);
    }
    if (data[0x6E]) {
        func_800EE7F8(saved_pos, actor->position);
        _subaddieDll_entrypoint_7(actor, 0xF);
    }
    func_80101870(actor, unk_0);
    if (data[0x6E])
        func_800EE7F8(actor->position, saved_pos);
    if (actor->unk7C_12) {
        light = _subaddielink_entrypoint_4(data + 0x30);
        bone_a = (f32 *) (data + 0x44);
        _subaddieskeleton_entrypoint_2(actor->unk0, 5, bone_a);
        bone_b = (f32 *) (data + 0x50);
        _subaddieskeleton_entrypoint_2(actor->unk0, 6, bone_b);
        if (light != NULL) {
            func_800EE7F8(light->position, bone_a);
            func_800F18FC(bone_a, bone_b, rot);
            light->rotation[0] = 90.0f - rot[0];
            light->rotation[1] = rot[1];
        }
    }
}

// Switches Weldar to a new state and runs that state's setup.
void func_80801AA0_chweldarboss(actor, state) Actor *actor;
s32 state;
{
    u8 *data;
    s32 update_camera;
    f32 pos[3];

    data = func_80100094(actor, 0);
    update_camera = 0;
    func_80102424(actor, state);
    func_80803460_chweldarboss(actor);
    switch (state) {
        case 2:
            func_80803CF0_chweldarboss(actor, 0x1D, 0x30);
            data[0x70] = 0;
            break;
        case 3:
            actor->unk64_16 = 1;
            *(f32 *) (data + 0xB4) = 4.0f;
            func_800BF744(1, 1);
            func_800FDC28(1);
            func_80803CF0_chweldarboss(actor, 0, 0x30);
            func_80101180(0x341, 7, 0);
            break;
        case 4:
            ((u8 *) actor)[0x7B] = (((u8 *) actor)[0x7B] & ~0xC0) | 0x40;
            func_80101180(0x341, 8, 0);
            func_80803CF0_chweldarboss(actor, 0xB, 0x30);
            break;
        case 5:
            _chintrotext_entrypoint_1(0x18B9, 6, 1, 0);
            break;
        case 8:
            update_camera = 1;
            if (!data[0x7A]) {
                data[0x7A] = 1;
                func_80802214_chweldarboss(actor, 0x1357, 0x44);
            }
            break;
        case 7:
        case 9:
        case 13:
        case 19:
        case 21:
        case 24:
        case 37:
        case 40:
            update_camera = 1;
            break;
        case 12:
        case 23:
        case 39:
            update_camera = 1;
            actor->unk58 = func_80803378_chweldarboss(actor);
            data[0xB2] = _subaddieaudioloop_entrypoint_3(data[0xB2]);
            break;
        case 10:
            update_camera = 1;
            if (!data[0x7B]) {
                data[0x7B] = 1;
                func_80802214_chweldarboss(actor, 0x1358, 0x44);
            }
            break;
        case 14:
        case 25:
        case 41:
            func_80803CF0_chweldarboss(actor, 0x1B, 0x438);
            break;
        case 11:
        case 22:
        case 38:
            update_camera = 1;
            actor->unk58 = 8.0f;
            break;
        case 16:
        case 26:
        case 42:
            data[0xB2] = _subaddieaudioloop_entrypoint_3(data[0xB2]);
            func_800F82D4(*(s16 *) (data + 0x76), 2);
            func_800F8150(*(s16 *) (data + 0x76), 0);
            func_800F4FC4();
            data[0x60] = 1;
            func_80803CF0_chweldarboss(actor, 0x19, 0x428);
            break;
        case 17:
        case 27:
        case 43:
            actor->unk58 = 1.4f;
            break;
        case 28:
            if (!data[0x7E]) {
                data[0x7E] = 1;
                func_80802214_chweldarboss(actor, 0x135B, 0x44);
            }
            func_80803CF0_chweldarboss(actor, 0x39, 0x10);
            *(s16 *) (data + 0x74) = 0;
            break;
        case 35:
            *(s16 *) (data + 0x74) = 0;
            break;
        case 32:
            if (!data[0x7F]) {
                data[0x7F] = 1;
                func_80802214_chweldarboss(actor, 0x135C, 0x44);
            }
            break;
        case 18:
            update_camera = 1;
            if (!data[0x7D]) {
                data[0x7D] = 1;
                func_80802214_chweldarboss(actor, 0x135A, 0x44);
            }
            break;
        case 44:
            func_80802214_chweldarboss(actor, 0x135E, 6);
            func_80803CF0_chweldarboss(actor, 0x22, 0x30);
            break;
        case 45:
            data[0x6E] = 1;
            func_800FDC28(0);
            func_8080373C_chweldarboss(actor);
            func_80802214_chweldarboss(actor, 0x135D, 0xE);
            func_80803CF0_chweldarboss(actor, 0x22, 0x30);
            break;
        case 46:
            actor->unk58 = 1.0f;
            func_80803CF0_chweldarboss(actor, 0x12, 0x430);
            break;
        case 47:
            func_800EE7F8(pos, actor->position);
            pos[1] += 800.0f;
            _subaddieaudioquick_entrypoint_2(actor, pos, D_808048F8_chweldarboss);
            actor->unk58 = 0.9f;
            _chexploder_entrypoint_5(actor, 0x870, pos, actor->rotation[1], actor->scale,
                                     0x100);
            func_80803CF0_chweldarboss(actor, 0x29, 0x30);
            break;
        case 48:
            actor->unk58 = 4.0f;
            break;
        case 49:
            if (func_800D395C()) {
                func_80803D64_chweldarboss(actor);
                _gcfrontend_entrypoint_10();
            } else {
                func_80803CF0_chweldarboss(actor, 0x1D, 0x30);
                func_80101180(0x431, 7, 0);
            }
    }
    if (update_camera) {
        func_8080340C_chweldarboss(actor);
    }
}

void func_80801F30_chweldarboss(actor, dialog_id, answer) u8 *actor;
s32 dialog_id;
s32 answer;
{
    u8 *data;
    s32 iter;
    u8 *obj;

    data = func_80100094(actor, 0);

switch (dialog_id) {
    case 0x1355:;
    case 0x1356:
        func_800DA544(0x174);
        _gcfrontend_entrypoint_9(0x28);
        func_80803D64_chweldarboss(actor);
        func_80801AA0_chweldarboss(actor, 7);
        func_800FDC28(7);
        func_800BF744(1, 0);
        obj = _subaddiefind_entrypoint_2(0x3A7, &iter);
        if (obj != NULL) {
            do {
                if (*(f32 *) ((s8 *) obj + 0xC) < -2600.0f) {
                    func_800FFAB0(obj);
                }
                obj = _subaddiefind_entrypoint_3(0x3A7, &iter);
            } while (obj != NULL);
        }
        return;
    case 0x135D:
        func_80801AA0_chweldarboss(actor, 0x2E);
        return;
    case 0x135E:
        func_808036C8_chweldarboss(actor);
        func_80802214_chweldarboss(actor, 0x135F, 6);
        func_80803CF0_chweldarboss(actor, 0x1F, 0x30);
        return;
    case 0x135F:
        func_80803D64_chweldarboss(actor);
        func_80801AA0_chweldarboss(actor, 8);
        *(s8 *) ((s8 *) data + 0x63) = func_808033D8_chweldarboss(actor);
        return;
    case 0x1359:
        if (((u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) == 0xF) {
            func_80803D64_chweldarboss(actor);
            func_80801AA0_chweldarboss(actor, 0x12);
            *(s8 *) ((s8 *) data + 0x63) = 3;
        }
        break;
    case 0xCEB:
        if (answer > 0) {
            _gcfrontend_entrypoint_11();
            return;
        }
        _gcfrontend_entrypoint_10();
}

}

int func_80802100_chweldarboss(Actor *actor, s32 pod_id)
{
    u8 *data;
    s32 result;

    data = (u8 *) func_80100094(actor, 0);
    result = 3;

switch (pod_id) {
    case 0x1D:
        if (actor->unk70_10 == 2) {
            func_80801AA0_chweldarboss(actor, 3);
        } else {
            func_800FFAB0(_subaddielink_entrypoint_4(data + 0x30));
            func_800FFAB0(actor);
            func_80803D64_chweldarboss((s32) actor);
            func_800DA544(0x9C9);
            _glcutDll_entrypoint_6(0x10F, 0x45);
        }
        result = 4;
        break;
    case 0x12:
        func_80801AA0_chweldarboss(actor, 0x2F);
        result = 4;
        break;
    case 0x39:
        *(s16 *) (data + 0x72) = 0;
        break;
    case 0x29:
        func_80803CF0_chweldarboss(actor, 0x32, 0x30);
        func_80101180(0x46A, 10, 0);
        result = 4;
}

return result;

}

int func_80802214_chweldarboss(actor, text_id, unk_0)
s32 *actor;
s32 text_id;
s32 unk_0;
{
    if (text_id == 0x1359) {
        if (func_800C064C() == 0x1358) {
            func_800C067C(0x1358);
        }
    }

return _subaddiedialog_entrypoint_11(actor[0], text_id, unk_0, actor + 1, 0xB5);
}

void func_8080227C_chweldarboss(Actor *actor, s32 kind)
{
    u8 *data;
    Actor *light;
    Actor *fireball;
    f32 player_pos[3];
    Actor *drop;

    data = func_80100094(actor, 0);

switch (kind) {
    case 0:
        light = func_80108528(0x468, actor->position, 0, &actor);
        _subaddielink_entrypoint_1(data + 0x30, light->unk0);
        light->unk3C = actor->unk0;
        break;
    case 1:
        fireball = func_80108528(0x124, (f32 *) (data + 0x44), 0, &actor);
        func_8010D09C(*(s16 *) (data + 0x78), fireball->actorData, 0.8f);
        fireball->unk3C = actor->unk0;
        break;
    case 2:
        drop = func_80108528(func_800DC128(0, 3) + 0x43E, (f32 *) (data + 0x44),
                                (s32) actor->rotation[1], &actor);
        func_80100120(drop);
        func_800F5A00(*(s16 *) (data + 0x78), player_pos);
        player_pos[1] = 0.0f;
        func_80101010(player_pos);
        func_8010108C(drop, 0x8E, actor->unk0);
}

}

void func_808023BC_chweldarboss(Actor *unused, s32 mode)
{
    s32 light;

    light = _subaddielink_entrypoint_4((u8 *) func_80100094(unused, 0) + 0x30);

if (light != 0) {
    func_808041C4_chweldarboss(light, mode);
}

}

void func_808023F8_chweldarboss(actor) Actor *actor;
{
    f32 shadow_pos[3];
    f32 shadow_scale;

if (actor->unk64_16) {
    func_800EE7F8(shadow_pos, actor->position);
    shadow_pos[1] = 0.0f;
    shadow_scale = *(f32 *) ((u8 *) actor + 0x38) *
              func_800F10B4(actor->position[1], 0.0f, 3000.0f, 5.0f, 1.4f);
    _chbadshad_entrypoint_1(actor, shadow_pos, shadow_scale);
}

}

void func_8080247C_chweldarboss(actor) Actor *actor;
{
    u8 *data;
    Actor *light;
    f32 *light_data;
    s32 loop_active;
    data = func_80100094(actor, 0);
    light = _subaddielink_entrypoint_4(data + 0x30);
    light_data = func_80100094(light, 0);
    loop_active = 0;

if (light) {
    switch (func_801022E4(actor)) {
        case 0x36F:
            if (!data[0x67] &&
                (func_80102320(actor, 0.02f, 0.13f) || func_80102320(actor, 0.26f, 0.55f)))
                loop_active = 1;
            func_808023BC_chweldarboss(actor, loop_active ? 2 : 4);
            break;
        case 0x373:
            if (func_80101E14(actor, 0.53f))
                func_808023BC_chweldarboss(actor, 2);
            if (func_80101E14(actor, 0.75f))
                func_808023BC_chweldarboss(actor, 4);
            loop_active = func_80102320(actor, 0.53f, 0.75f);
            break;
        case 0x372:
            if (func_80101E14(actor, 0.7f))
                func_808023BC_chweldarboss(actor, 2);
            loop_active = func_80101F24(actor) > 0.7f;
            break;
        default:
            func_808023BC_chweldarboss(actor, 4);
    }
    if (light_data[2] > 0.0f)
        loop_active = 1;
    data[0xB0] = _subaddieaudioloop_entrypoint_7(data[0xB0], light->position, loop_active,
                                                    D_80804908_chweldarboss,
                                                    *(u32 *) ((u8 *) actor + 0x70) & 1);
    if (data[0xB0])
        func_800C31DC(data[0xB0], func_800F12D4(light_data[2], 0.0f, 1.0f, 1.2f, 0.8f));
}

}

void func_808026BC_chweldarboss(actor) Actor *actor;
{
    u8 *data;
    Vec3f back_pos;
    Vec3f mouth_pos;
    void *shake;
    Vec3f bone_pos;
    s32 idx;
    Vec3f spawn_pos;
    f32 angle;

    data = func_80100094(actor, 0);

switch (func_801022E4(actor)) {
    case 0x371:
        _subaddieaudioquick_entrypoint_3(actor, (f32 *) (data + 0x44), D_80804980_chweldarboss,
                                         0.22f);
        _subaddieaudioquick_entrypoint_3(actor, (f32 *) (data + 0x44), D_80804970_chweldarboss,
                                         0.24f);
        if (func_80102320(actor, 0.2f, 0.4f) && !func_8001210C(1)) {
            func_800EE7F8(mouth_pos.f, (f32 *) (data + 0x44));
            mouth_pos.pos.y = 0.0f;
            func_800EE7F8(back_pos.f, mouth_pos.f);
            func_800EF1B8(back_pos.f, actor->rotation[1], -100.0f);
            func_800BBCB8(mouth_pos.f, back_pos.f, actor->scale * 0.6f, 2, D_80804928_chweldarboss);
        }
        if (func_80102320(actor, 0.24f, 0.64f) && func_8001210C(1)) {
            func_800BBCB8(actor->position, (f32 *) (data + 0x44), actor->scale, 3,
                          D_80804928_chweldarboss);
        }
        if (_subaddieaudioquick_entrypoint_3(actor, actor->position, D_80804990_chweldarboss,
                                             0.34f)) {
            shake = func_800E1540(2);
            func_800E1378(shake);
            func_800E13F0(shake, 10.0f);
            func_800E1410(shake, -8.0f, 1.8f);
            func_800187B4(0, 1.0f, 0.4f, 0.8f);
        }
        break;
    case 0x372:
        func_80802ABC_chweldarboss(actor, 0.5f);
    case 0x374:
        break;
    case 0x375:
        func_80802ABC_chweldarboss(actor, 0.75f);
        break;
    case 0x3E7:
        _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80804918_chweldarboss,
                                         0.15f);
        break;
    case 0x373:
        _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80804918_chweldarboss,
                                         0.08f);
        _subaddieaudioquick_entrypoint_3(actor, actor->position, D_808049A4_chweldarboss, 0.5f);
        if (func_80101E14(actor, 0.6f)) {
            data[0x6F]--;
            idx = data[0x66];
            if (_subaddieskeleton_entrypoint_2(actor->unk0, idx + 7, bone_pos.f)) {
                angle = func_800F1DF4(actor->position, bone_pos.f);
                func_800EE7F8(spawn_pos.f, bone_pos.f);
                func_800EF1B8(spawn_pos.f, angle, -200.0f);
                _chexploder_entrypoint_5(actor, 0x86E, bone_pos.f, angle, actor->scale, 2);
            }
        }
}

}

void func_808029D8_chweldarboss(Actor *actor)
{
    u8 *data;
    f32 pos[3];
    f32 dist;
    f32 scale;

    data = func_80100094(actor, 0);
    dist = func_800DC178(300.0f, 1000.0f);
    scale = func_800F10B4(dist, 300.0f, 1000.0f, 1.0f, 1.5f);
    func_800EEB9C(pos, actor->rotation[1], dist);
    func_800EF04C(pos, (f32 *) (data + 0x44));
    func_800BBCB8(pos, (f32 *) (data + 0x44), scale, 1, D_808049B4_chweldarboss);
    data[0xB2] = _subaddieaudioloop_entrypoint_7(data[0xB2], (f32 *) (data + 0x44), 1,
                                                    D_808049DC_chweldarboss,
                                                    *(u32 *) ((u8 *) actor + 0x70) & 1);

}

void func_80802ABC_chweldarboss(Actor *actor, f32 phase)
{
    if (_subaddieaudioquick_entrypoint_3(actor, actor->position, D_808049EC_chweldarboss,
                                         phase)) {
        func_800E15CC(0, 10.0f, 0.8f);
        func_80018820(0, 0.8f, 0.3f);
    }

}

void func_80802B1C_chweldarboss(Actor *actor)
{
    s32 i;
    f32 pos[3];
    s32 batch;
    batch = func_800B53A4(8);
    for (i = 0; i != 8; i++) {
        func_800EEB9C(pos, (f32) i * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(pos, actor->position);
        pos[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(batch, pos, actor->position, 1.0f, D_80804A10_chweldarboss);
    }
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808049FC_chweldarboss);
    func_800E15CC(0, 30.0f, 0.9f);
    func_80018820(0, 1.8f, 0.75f);
}

f32 func_80802C9C_chweldarboss(Actor *actor, s32 table_id)
{
    f32 progress;
    progress = func_80101F24(actor);
    switch (table_id) {
        case 0:
            return func_800F3780(progress, D_80804A4C_chweldarboss, 3);
        case 1:
            return func_800F3780(progress, D_80804A64_chweldarboss, 3);
        case 2:
            return func_800F3780(progress, D_80804A7C_chweldarboss, 3);
    }
    return 0.0f;
}

void func_80802D2C_chweldarboss(Actor *actor, s32 next_state, s32 timeout_state)
{
    u8 *data = (u8 *) func_80100094(actor, 0);
    s32 timer_done = func_800D9078(&actor->unk58);
    f32 dt = func_800D8FF8();
    f32 dir[3];
    f32 mouth_pos[3];
    s32 player;

    actor->unk54 = func_8010CD50(actor, *(s16 *) (data + 0x78));
    func_80102B2C(actor, 120.0f * dt);
    func_808029D8_chweldarboss(actor);
    func_80802E80_chweldarboss(actor);
    if ((*(u32 *) ((u8 *) actor + 0x7C) << 19) >> 31) {
        func_800EEB9C(dir, actor->rotation[1], 100.0f);
        func_800EE7F8(mouth_pos, (f32 *) (data + 0x44));
        func_800EF1B8(mouth_pos, actor->rotation[1], -300.0f);
        player = func_8010D490(mouth_pos, dir, 2300.0f, 600.0f, -1);
        if (player != -1)
            func_80803080_chweldarboss(actor, player);

switch (func_80803184_chweldarboss(actor, player)) {
    case 1:
        func_80801AA0_chweldarboss(actor, next_state);
        break;
    case 2:
        return;
}

}
if (timer_done)
    func_80801AA0_chweldarboss(actor, timeout_state);
}

void func_80802E80_chweldarboss(actor) u8 *actor;
{
    s8 _sfpad[8];
    s32 pos;

    func_80802F14_chweldarboss(actor, 1);
    func_800EE7F8(&pos, actor + 4);
    func_800EF1B8(&pos, *(f32 *) ((s8 *) actor + 0x48), 250.0f);
    _sudeflect_entrypoint_1(&pos, 500.0f, -100.0f, 300.0f, 2);
    func_800EF1B8(&pos, *(f32 *) ((s8 *) actor + 0x48), 300.0f);
    _sudeflect_entrypoint_1(&pos, 500.0f, -100.0f, 200.0f, 2);
}

void func_80802F14_chweldarboss(actor, all_players) Actor *actor;
s32 all_players;
{
    s32 i;
    s32 player_count;

    i = 0;
    player_count = 8;
    do {
        if (func_800F6438(i) &&
            (all_players || !func_800F682C(i) || func_800F6AA4(i))) {
            func_800F4EC8(i, actor->position, 600.0f, -100.0f, 300.0f);
        }

i++;
}
while (i != player_count)
    ;
}

void func_80802FE4_chweldarboss(Actor *actor, s32 next_state)
{
    u8 *data;
    s32 timer_done;
    f32 dt;

    data = func_80100094(actor, 0);
    timer_done = func_800D90A4(&actor->unk58);
    dt = func_800D8FF8();
    actor->unk54 = func_8010CD50(actor, *(s16 *) (data + 0x78));
    func_80102B2C(actor, 120.0f * dt);
    func_80802E80_chweldarboss(actor);
    if (timer_done) {
        func_80801AA0_chweldarboss(actor, next_state);
    }
}

void func_80803080_chweldarboss(actor, player) Actor *actor;
s32 player;
{
    u8 *data;
    f32 behind_pos[3];
    f32 target[3];
    f32 player_pos[3];
    s32 pad;
    f32 strength;
    f32 angle;

    data = func_80100094(actor, 0);
    if (func_800F6478((*(s32 *) &player)) && !func_800F6590((*(s32 *) &player))) {
        func_800F5A00((*(s32 *) &player), player_pos);
        func_800EE7F8(behind_pos, (f32 *) (data + 0x44));
        func_800EF1B8(behind_pos, *(f32 *) ((u8 *) actor + 0x48), -600.0f);
        strength = func_800F10B4(func_800EEAD4(player_pos, (f32 *) (data + 0x44)), 100.0f, 3000.0f,
                                550.0f, 350.0f);
        func_800F5D9C((*(s32 *) &player), target);
        angle = func_800F1DF4((f32 *) (data + 0x44), player_pos);
        func_800EF1B8(target, angle, -(func_800D8FF8() * strength));
        func_800F8418((*(s32 *) &player), target);
    }
}

s32 func_80803184_chweldarboss(actor, player)
Actor *actor;
s32 player;
{
    u8 *data;
    f32 mouth_pos[3];
    f32 player_pos[3];
    f32 radius;

    data = func_80100094(actor, 0);
    if (player == -1) {
        return 0;
    }
    if (!func_800F6478(player)) {
        return 0;

}
radius = func_800F5BF0(player, player_pos);
func_800EE7F8(mouth_pos, (f32 *) (data + 0x44));
func_800EF1B8(mouth_pos, actor->rotation[1], 100.0f);
if (func_800F0008(player_pos, radius, mouth_pos, 175.0f)) {
    if (func_800F64A4(player, 0x10000)) {
        func_800F7B9C(player, 0x86);
        *(s16 *) (data + 0x78) = func_800F54E4();
        func_80803DD8_chweldarboss(actor);
        return 2;
    }

_subaddieaudioquick_entrypoint_2(actor, data + 0x44, D_80804A94_chweldarboss);
func_80018820(0, 1.2f, 0.4f);
*(s16 *) (data + 0x76) = player;
return 1;
}
return 0;
}

void func_808032A8_chweldarboss(Actor *actor)
{
    WeldarPlayerEvent *data;
    f32 catch_pos[3];
    f32 spit_pos[3];

    data = func_80100094(actor, 0);
    if (data->local_1) {
        func_800EE7F8(catch_pos, data->local_0);
        catch_pos[1] -= 200.0f;
        func_800F8294(data->local_2, catch_pos);

if (func_80101E14(actor, 0.7f)) {
    _subaddieaudioquick_entrypoint_2(actor, catch_pos, D_80804AA4_chweldarboss);
    func_800EE7F8(spit_pos, actor->position);
    func_800EF1B8(spit_pos, actor->rotation[1], 700.0f);
    func_800F7CF4(data->local_2, 0x92, spit_pos);
    func_800F8150(data->local_2, 1);
    data->local_1 = 0;
}

}
}

f32 func_80803378_chweldarboss(Actor *actor)
{
    u8 *data = func_80100094(actor, 0);

    return func_800F10B4((u32) data[0x6F], 1.0f, 6.0f, 0.0f, 3.0f);
}

int func_808033D8_chweldarboss(s32 actor)
{
    u8 *data;
    data = func_80100094(actor, 0);
    // Matching: pointer decrement with the offset below is needed for the match.
    data--;
    return (!data[0x63]) ? (5) : (8);
}

s32 func_8080340C_chweldarboss(Actor *this)
{
    u8 *data;
    u8 *data_copy;
    data = func_80100094(this, 0);
    if (data[0x64] == 0) {
        // Matching: the extra pointer copy is needed for the match.
        data_copy = data;
        func_800F4AF4(*(s16 *) &data[0x78], 0x14);
        data_copy[0x64] = 1;
    }
    func_808034A0_chweldarboss(this);
}

void func_80803460_chweldarboss(s32 actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    if ((*(u8 *) ((s8 *) (data) + (0x64))) != 0) {
        func_800F4B20((*(s16 *) ((s8 *) (data) + (0x78))));
        (*(s8 *) ((s8 *) (data) + (0x64))) = 0;
    }
}

void func_808034A0_chweldarboss(actor) Actor *actor;
{
    WeldarCameraState1425 *data;
    f32 pos[3];
    u32 pad;

    data = func_80100094(actor, 0);
    if (data->enabled) {
        func_800EE7F8(pos, actor->position);
        pos[1] += 700.0f;
        _plcamera_entrypoint_9(data->player, pos, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(data->player)), pos);

}
}

void func_80803528_chweldarboss(actor, player_pos) Actor *actor;
f32 *player_pos;
{
    WeldarContactState *data;
    data = func_80100094(actor, 0);
    if (!data->active && actor->position[1] < 300.0f) {
        if (func_800EFC7C(player_pos, actor->position) < 40000.0f &&
            func_80803B48_chweldarboss((void *) (s32) data->id)) {
            data->active = 1;
            func_800F82D4(data->id, 2);
        }

}
}

void func_808035D0_chweldarboss(s32 actor)
{
    u8 *data = func_80100094(actor, 0);
    s32 player;
    if (data[0x65]) {
        player = *(s16 *) (data + 0x78);
        func_800F82D4(player, 0);
        func_800F7B9C(player, 0x5A);
        data[0x65] = 0;
    }
}

void func_80803624_chweldarboss(u8 *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    *(u8 *) (data + 0xB1) = _subaddieaudioloop_entrypoint_7(
        *(u8 *) (data + 0xB1), actor + 4, *(u8 *) (data + 0x6E), &D_80804AB4_chweldarboss,
        (*(s32 *) (actor + 0x70)) & 1);
}

void func_8080367C_chweldarboss(void *actor)
{
    u32 state;

    state = ((u32) *(u16 *) ((u8 *) actor + 0x72)) >> 10;
    if ((s32) state >= 7 && (s32) state < 0x2D) {
        func_800D2498(0xFD, *(u8 *) ((u8 *) func_80100094(actor, 0) + 0x6F), 0);
    }
}

void func_808036C8_chweldarboss(s32 actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    *(s8 *) (data + 0x62) = 1;
    *(s16 *) (data + 0xAC) = 2;
    *(f32 *) (data + 0xA8) = 10.0f;
    _mlwave_entrypoint_0(data + 0x88, 300.0f, 300.0f);
    _mlwave_entrypoint_7(data + 0x88, 0.25f);
    func_800BF744(3, 1);
}

void func_8080373C_chweldarboss(s32 actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    (*(s16 *) ((s8 *) (data) + (0xAC))) = 4;
    (*(f32 *) ((s8 *) (data) + (0xA8))) = 2.0f;
}

void func_80803770_chweldarboss(Actor *actor)
{
    u8 *data;
    s32 update_mesh;
    s32 fade_in_done;
    s32 fade_out_done;
    void **wave_ref;
    void **wave_ref2;
    void *wave;
    void *mesh;
    data = (u8 *) func_80100094(actor, 0);
    update_mesh = 0;
    wave_ref2 = &wave;
    wave_ref = wave_ref2;
    switch (*((s16 *) (data + 0xAC))) {
        case 1:
            break;

        case 2:
            fade_in_done = func_800D90A4(data + 0xA8);
            wave = data + 0x88;
            _mlwave_entrypoint_1(*wave_ref);
            *((s16 *) (data + 0xAE)) = (s32) _mlwave_entrypoint_5(wave, 0, 255.0f);

if (fade_in_done && _mlwave_entrypoint_8(wave, 0.75f)) {
    *(s16 *) (data + 0xAE) = 0xFF;
    *(s16 *) (data + 0xAC) = 3;
}

update_mesh = 1;
break;

case 3:
    if (func_800D90A4(data + 0xA4)) {
        // Matching: "| 0" is needed for the match.
        func_808038F8_chweldarboss(actor, update_mesh | 0);
    }

break;

case 4:
    fade_out_done = func_800D90A4(data + 0xA8);
    *((s16 *) (data + 0xAE)) = (s32) func_800F10B4(*((f32 *) (data + 0xA8)), .0f, 2.0f, 0.0f,
                                                      255.0f);

if (fade_out_done) {
    *(s16 *) (data + 0xAC) = 1;
    func_800BF744(3, 0);
}

update_mesh = 1;
}

if (update_mesh) {
    mesh = (void *) func_800BEA88(0, update_mesh);

if (mesh) {
    _glid_entrypoint_0(mesh, 1, _chweldarboss_entrypoint_2, actor->unk0);
}

}
}

s32 func_808038F8_chweldarboss(this) Actor *this;
{
    WeldarLocal *local;
    f32 pos[3];
    s32 i;
    s32 count;
    s32 cell[2];
    f32 dx;
    f32 dz;
    f32 p2[3];

    local = func_80100094(this, 0);
    count = 0;
    for (i = 0; i < 8; i++) {
        if (!func_800F6438(i)) {
            continue;
        }

if (!func_80803B48_chweldarboss(i)) {
    continue;
}

if (func_800F6AA4(i)) {
    continue;
}

func_800F5A00(i, pos);
cell[0] = (0.0f < pos[0]) ? (s32) (pos[0] / 800.0f) : (s32) (pos[0] / 800.0f + -1.0f);
cell[1] = (0.0f < pos[2]) ? (s32) (pos[2] / 800.0f) : (s32) (pos[2] / 800.0f + -1.0f);
dx = pos[0] - (f32) (cell[0] * 800);
dz = pos[2] - (f32) (cell[1] * 800);

if (dx < 50.0f || 750.0f < dx || dz < 50.0f || 750.0f < dz) {
    func_800F796C(i, 0xD);
    func_800EE7F8(p2, pos);
    p2[1] += 20.0f;
    _chelectricfence_entrypoint_1(this, p2);
    local->unkA4 = 2.0f;
    count++;
}

}
return count;
}

s32 func_80803B48_chweldarboss(void *player)
{
    if (!func_800F6478(player) || !func_800F6C5C(player)) {
        return 0;
    }
    return func_800F5628(player) < 50.0f;
}

void chweldarboss_entrypoint_2(s32 unk_0, Vtx *unk_1, Vtx *vtx, s32 count,
                               Unk80132ED0 *actor)
{
    u8 alpha;
    Vtx *end;

    alpha = *((u8 *) func_80100094(func_80106790(actor), 0) + 0xAF);
    for (end = vtx + count; vtx < end; vtx++) {
        vtx->v.cn[3] = alpha;
    }
}

void func_80803C18_chweldarboss(Actor *actor)
{
    WeldarLinkedPhase *light;
    Actor *boss;
    u8 *boss_data;
    s32 base;
    light = func_80100094(actor, 0);
    boss = _subaddielink_entrypoint_4(light->local_0);
    light->local_1 += func_800D8FF8() * 22.0f;
    if (boss) {
        boss_data = func_80100094(boss, 0);
        if (boss->unk70_10 == 1)
            light->local_2 = 5;
        else {
            base = (s32) func_800F10B4(*(f32 *) (boss_data + 8), 0.0f, 1.0f, 4.0f, 0.0f);
            light->local_2 = (s32) func_800F13C4(light->local_1, 2.0f) + base;
        }
    }
}

void func_80803CF0_chweldarboss(actor, pod_id, flags) Actor *actor;
u32 pod_id;
u32 flags;
{
    u8 *data;

    data = func_80100094(actor, 0);
    if (*(s16 *) (data + 0x72)) {
        _capod_entrypoint_14();
        flags |= 0x2000;
    }
    _capod_entrypoint_13(actor->unk0, 0, pod_id, flags);
    *(s16 *) (data + 0x72) = 1;
}

void func_80803D64_chweldarboss(actor) s32 actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    if ((*(s16 *) ((s8 *) (data) + (0x72))) != 0) {
        (*(s16 *) ((s8 *) (data) + (0x72))) = 0;
        _capod_entrypoint_14();
    }
}

s32 func_80803D98_chweldarboss(s32 unk_0)
{
    s32 found;
    s32 player;
    found = func_8010D290(0x10000);
    player = found;
    if (player == (-1)) {
        player = func_800F54E4();
    }
    // Matching: empty block is needed for the match.
    {
    }
    return player;
}

s32 func_80803DD8_chweldarboss(boss)
Actor *boss;
{
    s32 handled;
    handled = 0;
    switch (boss->unk70_10) {
        case 0xB:
        case 0xC:
            func_80801AA0_chweldarboss(boss, 0xE);
            handled = 1;
            break;
        case 0x16:
        case 0x17:
            func_80801AA0_chweldarboss(boss, 0x19);
            handled = 1;
            break;
        case 0x26:
        case 0x27:
            func_80801AA0_chweldarboss(boss, 0x29);
            handled = 1;
    }
    return handled;
}

void func_80803E50_chweldarboss(Actor *light)
{
    void *state;
    state = func_80100094(light, 0);
    *(float *) ((char *) state + 8) = 0.0f;
    func_808041C4_chweldarboss(light, 1);
    _subaddielink_entrypoint_1(state, light->unk3C);
    light->unk3C = 0;
}

// Welding-torch light: fades in and out and changes radius with its state.
void func_80803EA4_chweldarboss(Actor *light)
{
    WeldarLightState *state;
    s32 light_id;
    f32 light_pos[3];
    f32 inner_radius;
    f32 outer_radius;
    f32 dt;
    f32 dist;

    state = func_80100094(light, 0);
    light_id = state->local_1;
    dt = func_800D8FF8();
    switch (light->unk70_10) {
        case 1:
            light->unk64_16 = 0;
            break;
        case 2:
            light->unk64_16 = 1;
            state->local_0 = func_800F15F8(state->local_0, 1.0f, dt * 1.4f);
            if (state->local_0 == 1.0f)
                func_808041C4_chweldarboss(light, 3);
            break;
        case 3:
            light->unk64_16 = 1;
            break;
        case 4:
            light->unk64_16 = 1;
            state->local_0 = func_800F15F8(state->local_0, 0.0f, dt * 1.6f);
            if (state->local_0 == 0.0f)
                func_808041C4_chweldarboss(light, 1);
    }
    dist = func_800F12D4(state->local_0, 0.0f, 1.0f, 400.0f, 700.0f);
    func_800EE7F8(light_pos, light->position);
    func_800EF214(light_pos, 90.0f - light->rotation[0], light->rotation[1], dist);
    inner_radius = func_800F12D4(state->local_0, 0.0f, 1.0f, 200.0f, 600.0f);
    outer_radius = func_800F12D4(state->local_0, 0.0f, 1.0f, 400.0f, 1000.0f);
    func_800C8FE0(light_id, light->unk64_16);
    func_800C8E54(light_id, inner_radius, outer_radius);
    func_800C8CB8(light_id, light_pos);
    func_800C8E84(light_id, func_8001210C(1) ? D_80804AC8_chweldarboss : D_80804ABC_chweldarboss);
}

s32 func_808040F4_chweldarboss(s32 light, s32 msg, s32 arg)
{
    s32 *arg_ptr;
    char result;
    if (msg == 0x95) {
        arg_ptr = &arg;
        func_80804230_chweldarboss(light, msg, *arg_ptr);
        return result = 1;
    }
    return 0;
}

void func_8080412C_chweldarboss(Actor *light, s32 arg)
{
    f32 *state;
    f32 scale_y;
    f32 scale_xz;
    state = func_80100094(light, 0);
    scale_y = func_800F12D4(state[2], 0.0f, 1.0f, 0.4f, 1.4f);
    scale_xz = func_800F12D4(state[2], 0.0f, 1.0f, 0.8f, 1.2f);
    func_800DF500(scale_xz, scale_y, scale_xz);
    func_80101870(light, arg);
}

void func_808041C4_chweldarboss(light, new_state) Actor *light;
s32 new_state;
{
    switch (new_state) {
        case 2:
            if (light->unk70_10 == 3)
                return;
            break;
        case 4:
            if (light->unk70_10 == 1)
                return;
    }
    func_80102424(light, new_state);
}

void func_80804230_chweldarboss(light) s32 light;
{
    u8 *data;
    s32 light_id;
    u8 *state;

    state = func_80100094(light, 0);
    data = state;
    _subaddielink_entrypoint_3(state);
    light_id = func_800C8A98();
    *(s32 *) ((char *) data + 0xC) = light_id;
    func_800C8FE0(light_id, 0);
}

u8 D_808045F0_chweldarboss[416] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x40, 0x53, 0x33, 0x33, 0x3, 0x71, 0x0, 0x44,
    0x40, 0x53, 0x33, 0x33, 0x3, 0x71, 0x0, 0x44, 0x40, 0x53, 0x33, 0x33, 0x3, 0x71, 0x0, 0x9,
    0x3F, 0xE0, 0x0,  0x0,  0x3, 0x72, 0x0, 0xA,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,
    0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,  0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x9,
    0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x49, 0x3E, 0xE6, 0x66, 0x66, 0x3, 0x76, 0x0, 0xA,
    0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0xA,  0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9,
    0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9,  0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0x92,
    0x40, 0x20, 0x0,  0x0,  0x3, 0x73, 0x0, 0xA,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,
    0x40, 0x4C, 0xCC, 0xCD, 0x3, 0xE7, 0x0, 0xA,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,
    0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x49, 0x3E, 0xE6, 0x66, 0x66, 0x3, 0x76, 0x0, 0xA,
    0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,  0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0xA,
    0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9,  0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9,
    0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0x92, 0x40, 0x20, 0x0,  0x0,  0x3, 0x73, 0x0, 0xA,
    0x40, 0x4C, 0xCC, 0xCD, 0x3, 0xE7, 0x0, 0xA,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,
    0x3F, 0x40, 0x0,  0x0,  0x3, 0xE5, 0x0, 0x4A, 0x3F, 0x40, 0x0,  0x0,  0x3, 0xE5, 0x0, 0x2,
    0x3F, 0x40, 0x0,  0x0,  0x3, 0xE5, 0x0, 0x2,  0x3F, 0x40, 0x0,  0x0,  0x3, 0xE6, 0x0, 0x4A,
    0x3F, 0x4C, 0xCC, 0xCD, 0x3, 0x75, 0x0, 0x9,  0x3F, 0x40, 0x0,  0x0,  0x3, 0xE5, 0x0, 0x4A,
    0x3F, 0x40, 0x0,  0x0,  0x3, 0xE5, 0x0, 0x2,  0x3F, 0x40, 0x0,  0x0,  0x3, 0xE5, 0x0, 0x2,
    0x3F, 0x40, 0x0,  0x0,  0x3, 0xE6, 0x0, 0x4A, 0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0xA,
    0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9,  0x3E, 0x61, 0x47, 0xAE, 0x3, 0x74, 0x0, 0x9,
    0x3F, 0x99, 0x99, 0x9A, 0x3, 0x70, 0x0, 0x92, 0x40, 0x20, 0x0,  0x0,  0x3, 0x73, 0x0, 0xA,
    0x40, 0x4C, 0xCC, 0xCD, 0x3, 0xE7, 0x0, 0xA,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,
    0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9,  0x40, 0x80, 0x0,  0x0,  0x3, 0x6F, 0x0, 0x9};
u32 D_80804790_chweldarboss[10] = {0x0,       0x0,        0x3E23D70A, 0x37A0001,  0x3E23D70A,
                                   0x37A0001, 0x3E23D70A, 0x37A0001,  0x3E23D70A, 0x37A0001};
u8 D_808047B8_chweldarboss[12] = {0x0, 0x13, 0x4, 0x1D, 0x0, 0xD, 0x0, 0xC0, 0x0, 0xD9, 0x0, 0x0};
void *D_808047C4_chweldarboss = (void *) 0x02F80465;
static u32 D_808047C4_chweldarboss_rest[17] = {0x8170001,
                                               (u32) &D_808045F0_chweldarboss,
                                               (u32) func_8080030C_chweldarboss,
                                               (u32) func_80105834,
                                               (u32) func_80801944_chweldarboss,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x568,
                                               (u32) func_808002BC_chweldarboss,
                                               (u32) func_80108ED0,
                                               0xB80000,
                                               (u32) func_80800018_chweldarboss,
                                               (u32) func_80107C2C,
                                               0x82010480,
                                               (u32) func_808014CC_chweldarboss,
                                               0x0};
s32 D_8080480C_chweldarboss[18] = {0x1580468,
                                   0x86B0001,
                                   (u32) &D_80804790_chweldarboss,
                                   (u32) func_80803EA4_chweldarboss,
                                   (u32) func_80105834,
                                   (u32) func_8080412C_chweldarboss,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20400,
                                   0x0,
                                   0x0,
                                   0x100000,
                                   (u32) func_80803E50_chweldarboss,
                                   (u32) func_80107C2C,
                                   -0x7FFFFBFE,
                                   (u32) func_808040F4_chweldarboss,
                                   0x0};
u8 D_80804854_chweldarboss[16] = {0x0, 0x13, 0x6, 0x1C, 0x0, 0x18, 0x0, 0xD,
                                  0x0, 0xF3, 0x1, 0xC,  0x0, 0x2,  0x0, 0x0};
u8 D_80804864_chweldarboss[16] = {0x0, 0x13, 0x6, 0x12, 0x0, 0x18, 0x0, 0xA,
                                  0x0, 0xC0, 0x0, 0x2,  0x0, 0x0,  0x0, 0x0};
u8 D_80804874_chweldarboss[12] = {0x0, 0x13, 0x4, 0x13, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80804880_chweldarboss[52] = {0x0,  0x1D, 0x7,  0x8F, 0x0,  0x15, 0x0, 0x19, 0x0,  0x66, 0x0,
                                  0x16, 0x12, 0x0,  0x0,  0x32, 0x0,  0x2, 0x0,  0x1E, 0x0,  0x1E,
                                  0x0,  0x1E, 0x0,  0x18, 0x0,  0x0,  0x0, 0x0,  0xF,  0x0,  0xF,
                                  0x0,  0x0,  0x22, 0x1,  0x0,  0x1,  0x0, 0x4,  0x0,  0x4,  0x0,
                                  0x0,  0x2B, 0x1,  0x0,  0x1,  0x0,  0x0, 0x0};
u8 D_808048B4_chweldarboss[56] = {
    0x0,  0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x8, 0x0,  0xA, 0x0,  0x0,  0x22, 0x4,  0x0,
    0x5,  0x0,  0x8, 0x80, 0xA, 0x0,  0x0, 0x15, 0x0, 0x0,  0x0,  0x66, 0x0,  0x19,
    0x0,  0x0,  0x0, 0x7,  0x0, 0x2D, 0x0, 0x64, 0x0, 0xC8, 0x0,  0x20, 0xC0, 0xC0,
    0xC0, 0x80, 0x0, 0xB,  0x0, 0x3C, 0x0, 0x78, 0x0, 0xB4, 0xFF, 0x4C, 0x0,  0x0};
WeldarVec D_808048EC_chweldarboss = {-1.8e+03f, 1.2e+03f, -2.2e+03f};
u8 D_808048F8_chweldarboss[16] = {0x0, 0x13, 0x4, 0xFE, 0x0, 0x18, 0x0, 0x2,
                                  0x0, 0xA,  0x0, 0x8C, 0x0, 0x0,  0x0, 0x0};
u8 D_80804908_chweldarboss[16] = {0x0, 0x13, 0x6,  0x6,  0x0, 0xA, 0x1, 0x33,
                                  0x0, 0x16, 0x3E, 0x80, 0x0, 0x2, 0x0, 0x0};
u8 D_80804918_chweldarboss[16] = {0x0, 0x13, 0x4, 0xA4, 0x0, 0xD, 0x0, 0xAE,
                                  0x0, 0xB8, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
u8 D_80804928_chweldarboss[72] = {
    0x0,  0x1D, 0x9,  0xE2, 0x0,  0x16, 0x2,  0x0,  0x0, 0x5,  0x0,  0x0,  0x0,  0x4,  0x0,
    0x99, 0x0,  0x7,  0x0,  0x4,  0x0,  0x15, 0x0,  0x0, 0x0,  0xCC, 0x0,  0x2B, 0x1,  0x80,
    0x2,  0x0,  0x0,  0x22, 0x0,  0x4C, 0x0,  0x59, 0x0, 0x26, 0x0,  0x33, 0x0,  0x2D, 0x0,
    0xFA, 0x1,  0x90, 0x0,  0xA,  0xFF, 0x9C, 0x0,  0xA, 0xFF, 0x9C, 0x0,  0x64, 0x0,  0xA,
    0x0,  0x64, 0x0,  0x1B, 0xF9, 0xC0, 0xFB, 0x50, 0x0, 0x0,  0x0,  0x0};
u8 D_80804970_chweldarboss[16] = {0x0, 0x13, 0x6, 0x9, 0x0, 0xD, 0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80804980_chweldarboss[16] = {0x0, 0x13, 0x6, 0xA, 0x0, 0xD, 0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80804990_chweldarboss[20] = {0x0, 0x13, 0x6, 0x8,  0x0,  0xD,  0x0, 0xF3, 0x1, 0xC,
                                  0x0, 0x2,  0x0, 0x16, 0x6D, 0x60, 0x0, 0x0,  0x0, 0x0};
u8 D_808049A4_chweldarboss[16] = {0x0, 0x13, 0x6, 0x7, 0x0, 0xD,  0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x2, 0x0, 0x18, 0x0, 0x0};
u8 D_808049B4_chweldarboss[40] = {0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x80, 0x0,  0x0, 0x2D,
                                  0x2, 0x58, 0x3, 0x20, 0x1, 0x13, 0x0,  0x22, 0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x40, 0x0, 0x59, 0x0,  0x15, 0x0, 0x26,
                                  0x0, 0x99, 0x0, 0x2B, 0x0, 0x4C, 0x0,  0x66, 0x0, 0x0};
u8 D_808049DC_chweldarboss[16] = {0x0, 0x13, 0x6, 0xB, 0x0, 0xD,  0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x2, 0x0, 0x18, 0x0, 0x0};
u8 D_808049EC_chweldarboss[16] = {0x0, 0x13, 0x4, 0xA0, 0x0, 0xD, 0x0, 0x99,
                                  0x0, 0xA6, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
u8 D_808049FC_chweldarboss[20] = {0x0, 0x13, 0x4,  0xA0, 0x0, 0xD, 0x0, 0x99, 0x0, 0xA6,
                                  0x0, 0x16, 0x6D, 0x60, 0x0, 0x2, 0x0, 0x0,  0x0, 0x0};
u8 D_80804A10_chweldarboss[60] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x1,  0x80, 0x2,  0x0, 0x0,  0x22, 0x1,  0x80, 0x2,
    0x0,  0x3,  0x80, 0x4,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0, 0x99, 0x0,  0x27, 0xFF, 0x9C,
    0xFF, 0x9C, 0x0,  0x64, 0x0,  0x64, 0x0,  0x19, 0x0,  0x0, 0x0,  0x7,  0x0,  0x2D, 0x0,
    0xFA, 0x1,  0x5E, 0x0,  0x20, 0xC0, 0xC0, 0xC0, 0xC0, 0x1, 0x1A, 0x0,  0x0,  0x0,  0x0};
s32 D_80804A4C_chweldarboss[6] = {0x3E4CCCCD, 0x0, 0x3ECCCCCD, 0x3F800000, 0x3F266666, 0x0};
s32 D_80804A64_chweldarboss[6] = {0x0, 0x0, 0x3ECCCCCD, 0x3F800000, 0x3F400000, 0x0};
s32 D_80804A7C_chweldarboss[6] = {0x0, 0x3F800000, 0x3ECCCCCD, 0x0, 0x3F400000, 0x3F800000};
u8 D_80804A94_chweldarboss[16] = {0x0, 0x13, 0x4, 0x9C, 0x0, 0x18, 0x0, 0xD,
                                  0x0, 0x66, 0x0, 0x80, 0x0, 0x2,  0x0, 0x0};
u8 D_80804AA4_chweldarboss[16] = {0x0, 0x13, 0x6, 0x1C, 0x0, 0x18, 0x0, 0xD,
                                  0x0, 0xF3, 0x1, 0xC,  0x0, 0x2,  0x0, 0x0};
u8 D_80804AB4_chweldarboss[8] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x2, 0x0, 0x0};
u8 D_80804ABC_chweldarboss[12] = {0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0xFF};
u8 D_80804AC8_chweldarboss[24] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF,
                                  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
