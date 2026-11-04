#include "common.h"
extern void func_800F4F34(s32, f32 *, f32, f32);

#define R32(o) (*(s32 *) ((u8 *) rec + (o)))
#define RF(o) (*(f32 *) ((u8 *) rec + (o)))
#define R16(o) (*(s16 *) ((u8 *) rec + (o)))
#define RU8(o) (*(u8 *) ((u8 *) rec + (o)))
extern int D_80802B40_chdinoboss;
extern void *D_80802B88_chdinoboss;
extern void *func_80100094(Actor *, u32);
extern void func_80102FDC(Actor *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800DA564(s32, s32);
typedef struct {
    u8 pad_0[0x11E];
    s16 count;
} DinoBossHits;
typedef struct {
    u8 pad_0[0x110];
    f32 local_0[3];
    u8 pad_1[8];
    f32 local_1;
    u32 local_2 : 1;
    u32 pad_2 : 31;
    f32 local_3;
    f32 local_4;
    f32 local_5;
} CodexDinoPose;
extern f32 func_800136E4(f32);
extern s32 func_800DC298(f32);
extern f32 func_80013728(f32);
extern f32 func_800EEF94();
extern void func_800EEC30(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
extern u8 D_80802A2C_chdinoboss[];
extern u8 D_80802A48_chdinoboss[];
extern u8 D_80802BEC_chdinoboss[];
extern u8 D_80802BF4_chdinoboss[];
extern u8 D_80802C04_chdinoboss[];
extern u8 D_80802C14_chdinoboss[];
extern u8 D_80802C28_chdinoboss[];
extern u8 D_80802C34_chdinoboss[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern u32 D_80802C40_chdinoboss;
extern void *D_80802C4C_chdinoboss;
extern int D_80802C68_chdinoboss;
extern int D_80802C78_chdinoboss;
extern int D_80802C88_chdinoboss;
extern s32 D_80802C98_chdinoboss;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern f32 func_800DC178(f32, f32);
extern void func_8010D09C(s32, f32 *, f32);
extern void func_800EFD24(f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct {
    u8 pad_0[0x138];
    s16 local_0;
    u8 pad_1[0x26];
    f32 local_1;
    u8 pad_2[8];
    f32 local_2[3];
} DinoBossCameraState;
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x138];
    s16 local_0;
    s16 local_1;
    s16 local_2;
    s16 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8;
    s16 local_9;
    u8 pad_1[2];
    f32 local_10;
    f32 local_11[3];
} DinoCamera441;
extern f32 func_800F1DCC(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern s32 func_800D9078();
extern void func_80108B04();
extern s32 D_80802CA8_chdinoboss;
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1F38(f32, f32, f32);
extern f32 func_800F2094(f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_80102CF4(Actor *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void _subaddiemulti_entrypoint_6(f32 *, f32);
typedef struct {
    u8 pad[0x128];
    u32 f31 : 1;
    u32 f30 : 1;
    u32 f29 : 1;
    u32 f28 : 1;
    u32 f27 : 1;
    u32 rest : 27;
} DinoR128;
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    s16 local_0;
    s16 local_1;
    f32 local_2[20][3];
    s16 local_3[22];
    s32 local_4;
} DinoRouteData;
s32 func_80800E2C_chdinoboss();
void func_80801A44_chdinoboss();
void func_8080232C_chdinoboss();
void func_8080248C_chdinoboss();
void func_80800F70_chdinoboss();
void func_80801408_chdinoboss();
void func_80801AE4_chdinoboss();
f32 func_80801C84_chdinoboss();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_80800018_chdinoboss(), func_80800220_chdinoboss();
extern u8 D_80802A68_chdinoboss[];

// Terry (Terrydactyland boss) overlay.
// TU-NOTE: the data tables are emitted as a head symbol plus a static *_rest array.
int chdinoboss_entrypoint_0()
{
    return (int) &D_80802B40_chdinoboss;
}

int chdinoboss_entrypoint_1()
{
    return &D_80802B88_chdinoboss;
}

void func_80800018_chdinoboss(actor) Actor *actor;
{
    void **id_iter;
    u8 *dst;
    void *actor_ids[18];
    u8 *boss;
    s32 i;
    f32 *pos;

    boss = func_80100094(actor, 0);
    func_80102FDC(actor, actor->scale * 1.25f);
    pos = actor->position;
    func_800EE7F8((f32 *) (boss + 0x104), pos);
    *(s16 *) (boss + 0x138) = 0;
    *(s16 *) (boss + 0x164) = 1;
    func_800DA524(1);
    actor->pad5E = 30;
    *(s16 *) (boss + 0x11C) = actor->pad5E;
    *(s16 *) (boss + 0x138) = 0;
    func_80109EEC(actor, 0x40);
    func_80109FE8(actor, 0);
    if (_glcutDll_entrypoint_20()) {
        func_80102424(actor, 0x1A);
    } else if (func_800D395C()) {
        if (func_800DA298(0x172)) {
            func_8080248C_chdinoboss(actor, 0xD, 0x30);
            func_80800F70_chdinoboss(actor, 3);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1801, 6, pos, 0x57);
        } else {
            func_8080248C_chdinoboss(actor, 0x28, 0x30);
            func_80800F70_chdinoboss(actor, 2);
        }
    } else if (func_800DA298(0xE5)) {
        func_80101FDC(actor, 0x14);
        func_80109EEC(actor, 1);
        if (func_80800E2C_chdinoboss() == 4) {
            func_80101FDC(actor, 0x18);
        }
    }
    if (!func_800D395C() && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
    }
    *(s16 *) boss = _gccubesearch_entrypoint_9(0x154, actor_ids, 20);
    i = 0;
    dst = boss + 4;
    id_iter = actor_ids;
    if (*(s16 *) boss > 0) {
        do {
            func_800EE88C(dst, *id_iter);
            dst += 12;
            i++;
            id_iter++;
        } while (i < *(s16 *) boss);
    }
}

void func_80802540_chdinoboss();

void func_80802500_chdinoboss();

void func_80801DC8_chdinoboss();

void func_80801D08_chdinoboss();

void func_80801CDC_chdinoboss();

u8 func_80801C28_chdinoboss();

void func_80801830_chdinoboss();

void func_80801800_chdinoboss();

void func_808017D0_chdinoboss();

void func_808017A0_chdinoboss();

void func_808016C0_chdinoboss();

void func_80801660_chdinoboss(s32 param_0, f32 param_1, f32 param_2);

void func_80800220_chdinoboss(actor) Actor *actor;
{
    extern u8 D_80802A34_chdinoboss[];
    extern u8 D_80802A58_chdinoboss[];
    extern f32 D_80802A20_chdinoboss[];
    extern u8 D_80802BD0_chdinoboss[];

    char *boss;
    f32 probe_pos[3];
    f32 player_pos[3];
    f32 frame_time;
    f32 offset_a;
    f32 offset_b;
    s32 timer_done;
    f32 offset_c;
    f32 offset_d;
    s32 timer_done_2;
    f32 frame_time_2;
    f32 cam_pos[3];
    f32 ref_pos[3];

    boss = (char *) func_80100094(actor, 0);

    if (func_800DA298(1)) {
        func_80801CDC_chdinoboss(actor);
    }

    switch (actor->unk70_10) {
        case 1:
            _subaddieskeleton_entrypoint_2(*(s32 *) ((char *) actor + 0), 4, boss + 0x110);

            func_800EFD24(probe_pos);
            probe_pos[1] = *(f32 *) ((char *) actor + 8);

            if (func_8010C9B0(probe_pos, 0x6D6) && func_800F64A4(func_800F54E4(), 1)) {
                func_8010D254(player_pos);

                if (player_pos[2] < 1000.0f) {
                    if (func_800DA298(0x172)) {
                        func_8080248C_chdinoboss(actor, 0xD, 0x30);

                        _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1801, 6,
                                                      (char *) actor + 4, 0x57);

                        func_80800F70_chdinoboss(actor, 3);
                    } else {
                        func_8080248C_chdinoboss(actor, 0x28, 0x30);

                        func_80800F70_chdinoboss(actor, 2);
                    }

                    func_80101180(0x461, 8, 0);
                }
            }

            func_808016C0_chdinoboss(actor);
            break;

        case 2:
        case 3:
            _subaddieskeleton_entrypoint_2(*(s32 *) ((char *) actor + 0), 4, boss + 0x110);

            func_808016C0_chdinoboss(actor);
            break;

        case 4:
            func_808016C0_chdinoboss(actor);

            if (func_800D9078((char *) actor + 0x58)) {
                func_800FDC28(6);
                func_80800F70_chdinoboss(actor, 5);
            }
            break;

        case 5:
            func_808017A0_chdinoboss(actor);

            if (func_80101DDC(actor)) {
                func_80800F70_chdinoboss(actor, 6);
            }
            break;

        case 6:
            if (!func_800DA298(0x6AD)) {
                func_80802500_chdinoboss(actor);
                func_80800F70_chdinoboss(actor, 7);

                *(s32 *) (boss + 0x120) = func_80801C28_chdinoboss(actor);

                func_800DA544(0x172);
                _gcfrontend_entrypoint_9(0x27);
            }

            func_80801660_chdinoboss(actor, 0.0f, 0.0f);

            func_80801D08_chdinoboss(actor, 2);
            func_808017D0_chdinoboss(actor);
            break;

        case 7:
            func_80801D08_chdinoboss(actor, 2);
            func_808017D0_chdinoboss(actor);

            if (func_800D9078((char *) actor + 0x58)) {
                func_80800F70_chdinoboss(actor, 8);
            }
            break;

        case 8:
            func_80801D08_chdinoboss(actor, 2);

            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802A34_chdinoboss,
                                             0.65f);

            if (func_80101E14(actor, 0.7f)) {
                func_80108B04(actor, 1);
            }

            if (func_80101DDC(actor)) {
                if (*(s32 *) (boss + 0x120) > 0) {
                    func_80800F70_chdinoboss(actor, 7);

                    *(f32 *) ((char *) actor + 0x58) = func_80801C84_chdinoboss(actor);
                } else {
                    func_80800F70_chdinoboss(actor, 9);
                }
            }
            break;

        case 9:
            func_80801D08_chdinoboss(actor, 2);
            func_808017D0_chdinoboss(actor);

            if (!_subaddiefind_entrypoint_2(0x398, 0) && func_800D9078((char *) actor + 0x58)) {
                func_80800F70_chdinoboss(actor, 0xA);
                *(f32 *) ((char *) actor + 0x58) = 12.0f;
            }
            break;

        case 10:
            frame_time = func_800D8FF8();

            *(f32 *) (boss + 0x130) =
                func_800136E4(*(f32 *) (boss + 0x130) + frame_time * 16.0f);

            func_80801660_chdinoboss(actor, 0.0f, 0.0f);

            func_80801D08_chdinoboss(actor, 1);
            func_80801800_chdinoboss(actor);

            if (func_800D9078((char *) actor + 0x58)) {
                if (*(s16 *) (boss + 0x11E) == 0) {
                    func_80800F70_chdinoboss(actor, 7);

                    *(s32 *) (boss + 0x120) = func_80801C28_chdinoboss(actor);
                } else {
                    func_80800F70_chdinoboss(actor, 0xB);
                }
            }
            break;

        case 11:
            func_80801D08_chdinoboss(actor, 0);
            func_808017D0_chdinoboss(actor);

            if (func_800D9078((char *) actor + 0x58)) {
                func_80800F70_chdinoboss(actor, 0xC);
            }
            break;

        case 12:
            func_80801D08_chdinoboss(actor, 0);

            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802A34_chdinoboss,
                                             0.65f);

            if (func_80101E14(actor, 0.7f)) {
                func_80108B04(actor, 1);
            }

            if (func_80101DDC(actor)) {
                if (*(s32 *) (boss + 0x120) > 0) {
                    func_80800F70_chdinoboss(actor, 0xC);

                    *(f32 *) ((char *) actor + 0x58) = func_800DC178(0.5f, 1.0f);
                } else {
                    func_80800F70_chdinoboss(actor, 0xD);
                }
            }
            break;

        case 13:
            timer_done = func_800D9078((char *) actor + 0x58);

            offset_a = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 0.0f, 4.0f, -70.0f, 0.0f);

            offset_b = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 0.0f, 4.0f, 6500.0f, 0.0f);

            func_80801660_chdinoboss(actor, offset_a, offset_b);

            func_80801D08_chdinoboss(actor, 0);
            func_808017D0_chdinoboss(actor);

            if (timer_done) {
                func_80800F70_chdinoboss(actor, 0xE);
                func_800DA544(0);
            }
            break;

        case 14:
            func_80801D08_chdinoboss(actor, 0);

            if (!_subaddiefind_entrypoint_2(0x399, 0) && func_800D90A4((char *) actor + 0x58)) {
                func_80800F70_chdinoboss(actor, 0xF);
                func_800DA524(0);
            }
            break;

        case 15:
            timer_done_2 = func_800D9078((char *) actor + 0x58);

            offset_c = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 0.0f, 4.0f, 0.0f, -70.0f);

            offset_d = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 0.0f, 4.0f, 0.0f, 6500.0f);

            func_80801660_chdinoboss(actor, offset_c, offset_d);

            func_80801D08_chdinoboss(actor, 0);
            func_808017D0_chdinoboss(actor);

            if (timer_done_2) {
                func_80800F70_chdinoboss(actor, 7);

                *(s32 *) (boss + 0x120) = func_80801C28_chdinoboss(actor);
            }
            break;

        case 16:
            frame_time_2 = func_800D8FF8();

            *(f32 *) (boss + 0x130) = func_800F1F38(
                *(f32 *) (boss + 0x130), *(f32 *) (boss + 0x124), 25.0f * frame_time_2);

            func_80801660_chdinoboss(actor, 0.0f, 0.0f);

            func_80801D08_chdinoboss(actor, 0);
            func_80801830_chdinoboss(actor);

            if (func_800F2094(*(f32 *) (boss + 0x130), *(f32 *) (boss + 0x124)) < 1.5f &&
                func_80102CF4(actor, 4.0f)) {
                *(f32 *) ((char *) actor + 0x48) = *(f32 *) ((char *) actor + 0x54);

                func_80800F70_chdinoboss(actor, 0x11);
                func_8080248C_chdinoboss(actor, 0xA, 0x30);
            }
            break;

        case 17:
            if (_subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4,
                                                 D_80802A2C_chdinoboss, 0.35f)) {
                func_800E15CC(0, 30.0f, 0.9f);

                func_80018820(0, 2.0f, 0.45f);
            }

            if (func_80101DDC(actor)) {
                func_80800F70_chdinoboss(actor, 0x12);
            }
            break;

        case 18:
            if (func_800D9078((char *) actor + 0x58)) {
                if (func_800D395C()) {
                    func_80802500_chdinoboss(actor);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_80800F70_chdinoboss(actor, 0x13);
                }
            }

            func_80801860_chdinoboss(actor);
            break;

        case 19:
            func_80801860_chdinoboss(actor);

            if (!func_800C9510()) {
                *(u16 *) (D_80802A68_chdinoboss + 0xAE) |= 0x200;

                func_80800F70_chdinoboss(actor, 0x15);

                *(u16 *) (D_80802A68_chdinoboss + 0xAE) &= 0xFDFF;

                func_8080248C_chdinoboss(actor, 0x13, 0x20);

                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x17B6, 0xE,
                                              (char *) actor + 4, 0x57);

                func_800EFD24(cam_pos);

                cam_pos[1] = func_800F1DF4(D_80802A20_chdinoboss, (char *) actor + 4);

                func_800907C0(D_80802A20_chdinoboss);
                func_800906DC(cam_pos);
                func_800C964C(4);
            }
            break;

        case 20:
            if (_subaddiedialog_entrypoint_7(actor, (char *) actor + 4,
                                             D_80802BD0_chdinoboss)) {
                _capod_entrypoint_13(*(s32 *) ((char *) actor + 0), 0, 0x27, 0x20);
            }

            func_808018D0_chdinoboss(actor);
            func_80802540_chdinoboss(actor);
            break;

        case 21:
            func_808018D0_chdinoboss(actor);
            func_80802540_chdinoboss(actor);
            break;

        case 22:
            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802A58_chdinoboss,
                                             0.45f);

            if (func_80101DDC(actor)) {
                if (*(s16 *) (boss + 0x11E) == 3) {
                    func_80800F70_chdinoboss(actor, 0xB);
                } else {
                    func_80800F70_chdinoboss(actor, 0xA);
                }
            }
            break;

        case 23:
            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802A58_chdinoboss,
                                             0.45f);

            if (func_80101DDC(actor)) {
                func_80800F70_chdinoboss(actor, 0x10);
            }
            break;

        case 24:
            func_80802540_chdinoboss(actor);
            func_808016C0_chdinoboss(actor);
            break;

        case 25:
            func_80801D08_chdinoboss(actor, 0);
            func_808017D0_chdinoboss(actor);
            break;

        case 26:
            func_808016C0_chdinoboss(actor);
    }

    func_80801DC8_chdinoboss(actor);

    switch (func_801022E4(actor)) {
        case 0x163:
        case 0x1C1:
        case 0x1F7:
            if (!func_800D395C()) {
                break;
            }
        default:
            func_800EFD24(ref_pos);
            _subaddiemulti_entrypoint_6(ref_pos, 3062500.0f);
    }
}

void func_80801900_chdinoboss();

s32 func_80800F28_chdinoboss();

void func_80800E88_chdinoboss();

s32 func_80800C50_chdinoboss(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x3F:
            func_80800E88_chdinoboss(actor, arg);
            return 1;
        case 0x40:
            func_80800F28_chdinoboss(actor, arg);
            return 1;
        case 0xB:
            switch (arg) {
                case 11:
                    func_80802500_chdinoboss(actor);
                    _glcutDll_entrypoint_6(0x112, 0x33);
                    return 4;
                case 40:
                    func_8080248C_chdinoboss(actor, 1, 0x30);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x17B3, 6, actor->position,
                                                  0x57);
                    func_80800F70_chdinoboss(actor, 3);
                    return 4;
            }
            return 3;
        case 0x2E:
            func_80801408_chdinoboss(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            return 1;
        case 0x31:
            func_8080248C_chdinoboss(actor, 0x1B, 0x30);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x17DF, 6, actor->position, 0x57);
            return 1;
        case 0x3D:
            func_80801900_chdinoboss(actor);
            return 1;
        case 0x96:
            if (!func_800D395C())
                return 0;
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x4E, actor->position, 0x57);
            return 1;
        default:
            return 0;
        case 0x9F:
            func_800FDC28(0);
            func_80800F70_chdinoboss(actor, 0x19);
            return 1;
    }
}

// Counts the set bits of flag 0x175 (eggs returned).
s32 func_80800E2C_chdinoboss(void)
{
    s32 count = 0;
    s32 flags = func_800DA564(0x175, 4);
    if (flags & 1) {
        count++;
    }
    if (flags & 2) {
        count++;
    }
    if (flags & 4) {
        count++;
    }
    if (flags & 8) {
        count++;
    }
    return count;
}

void func_80800E88_chdinoboss(Actor *actor, s32 arg)
{
    DinoBossHits *boss;
    boss = func_80100094(actor, 0);
    if (!func_800DA298(0xE5) && actor->unk70_10 == 0xA) {
        boss->count++;
        if (boss->count == 3)
            func_80109FE8(actor, 0);
        if (actor->unk70_10 != 0x16)
            func_80800F70_chdinoboss(actor, 0x16);
    }
}

s32 func_80800F28_chdinoboss(s32 actor, s32 arg)
{
    if (func_800DA298(0xE5) == 0) {
        func_80800F70_chdinoboss(actor, 0x17);
        func_8080248C_chdinoboss(actor, 0x2A, 0x438);
    }
}

void func_80801FAC_chdinoboss();

void func_808015AC_chdinoboss();

void func_80800F70_chdinoboss(actor, state) Actor *actor;
s32 state;
{
    u8 *rec;
    s32 cam_mode;
    s32 cam_flag;
    f32 angles[2];
    f32 ref_pos[3];

    rec = func_80100094(actor, 0);
    cam_mode = 0;
    cam_flag = 0;
    func_80102424(actor, state);
    switch (state) {
        case 3:
            func_800FDC28(1);
            break;
        case 4:
            func_8080248C_chdinoboss(actor, 4, 0x30);
            break;
        case 5:
            func_800DA544(1);
            break;
        case 6:
            if (!func_800DA298(0x172)) {
                _chintrotext_entrypoint_1(0x18B9, 1, 1, 0);
            }
            func_808015AC_chdinoboss(actor);
            break;
        case 7:
            RF(0x12C) = 30.0f;
            RF(0x134) = 2500.0f;
            func_80801660_chdinoboss(actor, 0.0f, 0.0f);
            actor->unk58 = func_800DC178(2.0f, 4.0f);
            cam_mode = 1;
            break;
        case 8:
            R32(0x120) = R32(0x120) - 1;
            cam_mode = 1;
            break;
        case 9:
            actor->unk58 = 0.7f;
            R16(0x11E) = 0;
            cam_mode = 1;
            break;
        case 10:
            RF(0x12C) = 40.0f;
            RF(0x134) = 3500.0f;
            func_80801660_chdinoboss(actor, 0.0f, 0.0f);
            if (RU8(0x12A) == 0) {
                RU8(0x12A) = 1;
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17FC, 0x44, actor->position, 0x57);
            }
            func_80109FE8(actor, 1);
            R16(0x11C) = actor->pad5E;
            break;
        case 11:
            RF(0x12C) = 30.0f;
            RF(0x134) = 2500.0f;
            func_80801660_chdinoboss(actor, 0.0f, 0.0f);
            func_80109FE8(actor, 0);
            actor->unk58 = func_800DC178(1.0f, 2.0f);
            R16(2) = func_80801C28_chdinoboss(actor);
            R32(0x120) = R16(2);
            func_80801AE4_chdinoboss(actor);
            cam_mode = 1;
            cam_flag = 1;
            break;
        case 12:
            if (!((DinoR128 *) rec)->f30) {
                ((DinoR128 *) rec)->f30 = 1;
                if (func_800C064C() == 0x17FC) {
                    func_800C067C(0x17FC);
                }
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17B4, 0x44, actor->position, 0x57);
            }
            R32(0x120) = R32(0x120) - 1;
            cam_mode = 1;
            cam_flag = 1;
            break;
        case 13:
            RF(0x12C) = 40.0f;
            RF(0x134) = 3500.0f;
            func_80801660_chdinoboss(actor, 0.0f, 0.0f);
            actor->unk58 = 4.0f;
            cam_mode = 2;
            cam_flag = 1;
            break;
        case 14:
            actor->unk64_16 = 0;
            actor->unk58 = 2.0f;
            break;
        case 15:
            if (!((DinoR128 *) rec)->f27) {
                ((DinoR128 *) rec)->f27 = 1;
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1802, 0x44, actor->position, 0x57);
            }
            actor->unk64_16 = 1;
            actor->unk58 = 4.0f;
            cam_mode = 3;
            cam_flag = 1;
            break;
        case 23:
            func_800EFD24(ref_pos);
            func_800F18FC((f32 *) (rec + 0x110), ref_pos, angles);
            RF(0x12C) = func_800136E4(-angles[0]);
            RF(0x134) = func_800EEF94((f32 *) (rec + 0x110));
            RF(0x124) = func_80013728(RF(0x124));
            func_80801660_chdinoboss(actor, 0.0f, 0.0f);
            func_80109EEC(actor, 1);
            func_80109FE8(actor, 0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x17B5, 0x44, actor->position, 0x57);
            func_800DA544(0xE5);
            func_800DA524(1);
            func_800FDC28(0);
            actor->pad5E = 0;
            func_80801CDC_chdinoboss(actor);
            break;
        case 16:
            cam_flag = 1;
            break;
        case 17:
            func_800EE7F8(actor->position, (f32 *) (rec + 0x104));
            break;
        case 18:
            actor->unk58 = 10.0f;
            break;
        case 19:
            func_800C964C(3);
    }
    func_80801FAC_chdinoboss(actor, cam_mode, cam_flag);
}

void func_80801408_chdinoboss(actor, dialog_id, result) Actor *actor;
s32 dialog_id;
s32 result;
{
    switch (dialog_id) {
        case 0x17B3:
        case 0x1801:
            func_80800F70_chdinoboss(actor, 4);
            actor->unk58 = 0.75f;
        case 0x17B4:
        case 0x17B5:
        case 0x17FC:
            break;
        case 0x17B6:
            func_800D1000(0x2C, 1, 0, 1, 0);
            func_8080248C_chdinoboss(actor, 0xB, 0x10);
            func_80800F70_chdinoboss(actor, 0x14);
            func_80101180(0x461, 7, 0);
            func_80101180(0x469, 7, 0);
            break;
        case 0x17B7:
        case 0x120B:
            func_80800F70_chdinoboss(actor, 0x14);
            _capod_entrypoint_14();
            break;
        case 0x17DF:
            func_800D1000(0x2F, 1, 0, 1, 0);
            func_8080248C_chdinoboss(actor, 0x22, 0x10);
            func_80102424(actor, 0x18);
            break;
        case 0xCEB:
            if (result > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
        default:
            if (func_800DA298(0xE5)) {
                func_80800F70_chdinoboss(actor, 0x14);
            }
    }
}

void func_808015AC_chdinoboss(Actor *actor)
{
    f32 *pos;
    f32 angle;
    f32 ref_pos[3];
    CodexDinoPose *boss;

    boss = func_80100094(actor, 0);
    if (!boss->local_2) {
        boss->local_2 = 1;
        pos = actor->position;
        func_800EE7F8(pos, boss->local_0);
        func_800EFD24(ref_pos);
        func_800F18FC(pos, ref_pos, &angle);
        boss->local_1 = boss->local_4 = func_800136E4(actor->rotation[1] + 180.0f);
        boss->local_3 = func_80013728(-angle);
        boss->local_5 = func_800EEF94(pos);
    }
}

void func_80801660_chdinoboss(s32 actor, f32 offset_a, f32 offset_b)
{
    u8 *boss;

    boss = func_80100094(actor, 0);
    func_800EEC30((f32 *) (actor + 4), *(f32 *) ((u8 *) boss + 0x12C) + offset_a,
                  *(f32 *) ((u8 *) boss + 0x130), *(f32 *) ((u8 *) boss + 0x134) + offset_b);
}

void func_808016C0_chdinoboss(Actor *actor)
{
    f32 *pos;

    pos = actor->position;
    if (_subaddieaudioquick_entrypoint_3(actor, pos, D_80802A2C_chdinoboss, 0.94f)) {
        func_800E15CC(0, 30.0f, 0.9f);
        func_80018820(0, 1.0f, 0.3f);
    }
    _subaddieaudioquick_entrypoint_4(actor, pos, D_80802BEC_chdinoboss,
                                     D_80802C28_chdinoboss);
    _subaddieaudioquick_entrypoint_4(actor, pos, D_80802A48_chdinoboss,
                                     D_80802C14_chdinoboss);
    _subaddieaudioquick_entrypoint_4(actor, pos, D_80802BF4_chdinoboss,
                                     D_80802C34_chdinoboss);
    _subaddieaudioquick_entrypoint_3(actor, pos, D_80802C04_chdinoboss, 0.07f);
}

void func_808017A0_chdinoboss(s32 actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor + 4, &D_80802A48_chdinoboss,
                                     &D_80802C40_chdinoboss);
}

void func_808017D0_chdinoboss(s32 actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor + 4, &D_80802A48_chdinoboss,
                                     &D_80802C4C_chdinoboss);
}

void func_80801800_chdinoboss(s32 actor)
{
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80802A48_chdinoboss, 0.23f);
}

void func_80801830_chdinoboss(s32 actor)
{
    s32 pos;
    pos = actor + 4;
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80802A48_chdinoboss, 0.28f);
}

// Matching: the line breaks in this function are needed for the match.
int func_80801860_chdinoboss(s32 actor)
{
    s32 pos;
    pos = actor + 0x4; _subaddieaudioquick_entrypoint_3(actor, pos, &D_80802A2C_chdinoboss, 0.8f);
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80802C68_chdinoboss, 0.65f);
    _subaddieaudioquick_entrypoint_4(actor, pos, &D_80802C78_chdinoboss, &D_80802C88_chdinoboss);
}

int func_808018D0_chdinoboss(s32 actor)
{
    s32 pos;
    pos = actor + 4;
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80802C98_chdinoboss, 0.1f);
}

// Spawns a goo ball (actor 0x398) from bone 5 toward the target.
void func_80801900_chdinoboss(Actor *actor)
{
    u8 *boss;
    Actor *goo;
    f32 bone_pos[3];
    f32 target_pos[3];
    f32 angles[2];

    boss = func_80100094(actor, 0);
    if (actor->unk70_10 == 8)
        func_80801A44_chdinoboss(actor, target_pos);
    else
        func_800EE7F8(
            target_pos,
            ((f32(*)[3])(boss + 4))[((s16 *) (boss + 0xF4))[*(s32 *) (boss + 0x120)]]);
    _subaddieskeleton_entrypoint_1(actor, 5, bone_pos);
    func_800F18FC(bone_pos, target_pos, angles);
    goo = func_80108528(0x398, bone_pos, (s32) angles[1], &actor);
    func_80102FDC(goo, func_800DC178(2.0f, 4.0f));
    func_800EFB24((f32 *) ((u8 *) goo + 0x28), target_pos, bone_pos);
    func_800EF368((f32 *) ((u8 *) goo + 0x28), 3500.0f);
    if (actor->unk70_10 == 8)
        goo->unk64_20 = 0;
    else
        goo->unk64_20 = 1;
}

void func_80801A44_chdinoboss(actor, out_pos) Actor *actor;
f32 *out_pos;
{
    f32 ray_start[3];
    f32 target[3];
    f32 hit_pos[3];
    func_8010D09C(func_800F54E4(), target, 1.0f);
    func_800EE7F8(ray_start, target);
    ray_start[1] += 400.0f;
    target[1] -= 350.0f;
    if (func_800C6A7C(ray_start, target, hit_pos, actor->unk14)) {
        func_800EE7F8(out_pos, target);
    } else {
        func_8010D254(out_pos);
    }
}

void func_80801AE4_chdinoboss(actor) Actor *actor;
{
    s32 i;
    s32 candidate;
    s32 j;
    s32 unique;
    DinoRouteData *route;
    Vec3f player_pos;

    route = func_80100094(actor, 0);
    func_8010D254(player_pos.f);
    for (i = 0; i < route->local_1; i++) {
        route->local_3[i] = -1;
        do {
            candidate = func_800DC128(0, route->local_0);
            unique = 1;
            for (j = i - 1; j >= 0; j--) {
                if (candidate == route->local_3[j]) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                if (func_800EEB40(player_pos.f, route->local_2[candidate]) > 160000.0f)
                    route->local_3[i] = candidate;
                else
                    unique = 0;
            }
        } while (!unique);
    }
}

u8 func_80801C28_chdinoboss(u8 *actor)
{
    if (actor[0x5E] < 7) {
        return 6;
    }
    if (actor[0x5E] < 13) {
        return 5;
    }
    if (actor[0x5E] < 19) {
        return 4;
    }
    if (actor[0x5E] < 0x19) {
        return 3;
    }
    return 2;
}

f32 func_80801C84_chdinoboss(actor)
u8 *actor;
{
    return func_800F10B4(actor[0x5E], 0.0f, 30.0f, 0.3f, 1.8f);
}

void func_80801CDC_chdinoboss(u8 *actor)
{
    func_800D2498(0xC8, actor[0x5E], 0, actor);
}

void func_80801D08_chdinoboss(Actor *actor, s32 mode)
{
    f32 target[3];

    switch (mode) {
        case 0:
            func_800EFD24(target);
            actor->unk54 = func_80102D78(actor, target);
            break;
        case 1:
            func_800EFD24(target);
            actor->unk54 = func_80102D78(actor, target) - 90.0f;
            break;
        case 2:
            func_8010D254(target);
            actor->unk54 = func_80102D78(actor, target);
    }

    func_80102BF8(actor, 0.1f, 0.05f, 120.0f);
}

void func_80801DC8_chdinoboss(Actor *actor)
{
    DinoBossCameraState *state;
    f32 ref_pos[3];
    f32 cam_pos[3];

    state = func_80100094(actor, 0);

    switch (state->local_0) {
        case 0:
            break;
        case 1:
            func_8008FE68(ref_pos);
            func_800EEC30(cam_pos, 60.0f, state->local_1, 2800.0f);
            func_800EF934(cam_pos, cam_pos, actor->rotation[1]);
            func_800EF04C(cam_pos, actor->position);
            func_8080232C_chdinoboss(actor, cam_pos, ref_pos);
            break;
        case 2:
        case 3:
            func_8080232C_chdinoboss(actor, state->local_2, actor->position);
    }
}

// Matching: the `| 0` only exists to produce the original code.
int func_80801E90_chdinoboss(f32 *pos, f32 *target)
{
    func_8010FFB0(func_800F5EF8(func_800F54E4()) | 0, pos, target);
}

s32 func_80801ECC_chdinoboss(f32 *pos, f32 *target)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        if (func_800F6438(i) != 0) {
            func_8010FE14(func_800F5EF8(i), pos, target);
        }
    }
}

// Matching: the `| 0` operations are needed for the match.
int func_80801F44_chdinoboss(s32 mode)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_800F6438(i | 0)) {
            func_8010F9C0(func_800F5EF8(i | 0) | 0, mode | 0);
        }
    }
}

void func_80801FAC_chdinoboss(Actor *actor, s32 mode, s32 unk_2)
{
    f32 player_pos[3];
    DinoCamera441 *cam;
    s32 in_cutscene;
    s32 reset_blend;
    f32 cam_pos[3];
    f32 offset[3];
    f32 cam_target[3];
    f32 angle;
    Actor *actor_alias;
    f32 target_angle;

    cam = func_80100094(actor, 0);
    in_cutscene = 0;
    reset_blend = 1;
    if (cam->local_1 && !unk_2) {
        func_80090708(0);
        cam->local_1 = 0;
    }
    if (!cam->local_1 && unk_2) {
        func_80090708(2);
        cam->local_1 = 1;
    }
    if (mode != cam->local_0) {
        func_80801E90_chdinoboss(cam->local_6, cam->local_7);
        // Matching: empty blocks and the alias steer IDO's register allocation.
        if (1) {
        }
        actor_alias = actor;

        switch (cam->local_0) {
            case 1:
            case 2:
                if (1) {
                }
            case 3:
                break;
            case 0:
                func_800F7B9C(func_800F54E4(), 0x93);
        }

        switch (mode) {
            case 0:
                func_8008FE68(player_pos);
                func_80801E90_chdinoboss(cam_pos, cam_target);
                func_800EFB24(offset, cam_pos, player_pos);
                func_800EF368(offset, 600.0f);
                func_800EF04C(player_pos, offset);
                func_80801ECC_chdinoboss(player_pos, cam_target);
                func_80801F44_chdinoboss(2);
                reset_blend = 0;
                break;
            case 1:
                func_80801F44_chdinoboss(6);
                target_angle = func_80102D78(actor_alias, cam->local_6);
                if (!func_800F1EA4(actor_alias->position, &angle)) {
                    angle = actor_alias->rotation[1];
                }
                if (func_800F1DCC(target_angle, angle) > 0.0f) {
                    cam->local_8 = -100.0f;
                } else {
                    cam->local_8 = 100.0f;
                }
                if (cam->local_9) {
                    reset_blend = 0;
                    cam->local_9 = 0;
                }
                if (actor_alias->unk70_10 == 0xB || actor->unk70_10 == 0xC) {
                    in_cutscene = 1;
                }
                break;
            case 2:
                func_80801F44_chdinoboss(6);
                cam->local_10 = 0.0f;
                func_800EEB9C(
                    cam->local_11,
                    func_800136E4((func_800DC298(0.5f) ? -35.0f : 35.0f) + actor->rotation[1]),
                    6000.0f);
                func_800EF04C(cam->local_11, actor->position);
                in_cutscene = 1;
                reset_blend = 0;
                break;
            case 3:
                func_80801F44_chdinoboss(6);
                in_cutscene = 1;
                reset_blend = 0;
        }

        if (in_cutscene && !cam->local_2) {
            _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
            func_800C52F4(0, 2);
            cam->local_2 = 1;
        }

        if (!in_cutscene && cam->local_2) {
            _glcutDll_entrypoint_17();
            func_800C53EC(0, 2);
            cam->local_2 = 0;
        }

        cam->local_0 = mode;

        if (reset_blend) {
            cam->local_3 = 1;
            cam->local_5 = 1.0f;
            cam->local_4 = 1.0f;
            return;
        }

        cam->local_3 = 0;
    }
}

void func_8080232C_chdinoboss(actor, pos, unk_2) Actor *actor;
f32 *pos;
void *unk_2;
{
    u8 *cam;
    f32 target[3];
    f32 blend_pos[3];
    f32 from_angles[2];
    f32 to_angles[2];
    f32 from_dist;
    f32 blend_dist;
    f32 t;
    s32 i;
    s32 pad;
    s32 finished;

    cam = func_80100094(actor, 0);
    if (*(s16 *) (cam + 0x13E)) {
        finished = func_800D9078(cam + 0x140);
        t =
            func_800F12D4(*(f32 *) (cam + 0x140), 0.0f, *(f32 *) (cam + 0x144), 1.0f, 0.0f);
        func_800F1A88(cam + 0x148, from_angles);
        func_800F1A88(pos, to_angles);
        from_dist = func_800EEF94((f32 *) (cam + 0x148));
        blend_dist = (func_800EEF94(pos) - from_dist) * t + from_dist;
        for (i = 0; i < 2; i++) {
            to_angles[i] = from_angles[i] + func_800F1DCC(to_angles[i], from_angles[i]) * t;
        }
        func_800EEBF0(blend_pos, to_angles, blend_dist);
        func_800A516C(target, unk_2, blend_pos);
        func_80801ECC_chdinoboss(blend_pos, target);
        if (finished)
            *(s16 *) (cam + 0x13E) = 0;
    } else {
        func_800A516C(target, unk_2, pos);
        func_80801ECC_chdinoboss(pos, target);
    }
}

void func_8080248C_chdinoboss(actor, cam_mode, cam_flags) s32 actor[3];
s32 cam_mode;
u32 cam_flags;
{
    Actor *data;
    data = func_80100094(actor, 0);
    if (*(u8 *) ((char *) (data) + 0x12B)) {
        _capod_entrypoint_14();
        cam_flags = cam_flags | 0x2000;
    }
    _capod_entrypoint_13(*actor, 0, cam_mode, cam_flags);
    *(u8 *) ((char *) (data) + 0x12B) = 1;
}

// Ends the camera override started by func_8080248C.
void func_80802500_chdinoboss(s32 actor)
{
    u8 *data;
    u8 *data_alias;

    data = func_80100094(actor, 0);
    data_alias = data;
    if (*(u8 *) ((char *) data + 0x12B) != 0) {
        _capod_entrypoint_14();
        data_alias = data;
    }
    *(s8 *) ((char *) data_alias + 0x12B) = 0;
}

void func_80802540_chdinoboss(Actor *actor)
{
    f32 bone_pos[3];
    func_800F4F34(func_800F54E4(), actor->position, 5e+02f, 5e+02f);
    if (_subaddieskeleton_entrypoint_0(actor, 6, bone_pos))
        func_800F4F34(func_800F54E4(), bone_pos, 0.0f, 3e+02f);
    if (_subaddieskeleton_entrypoint_0(actor, 20, bone_pos))
        func_800F4F34(func_800F54E4(), bone_pos, 0.0f, 3e+02f);
}

void func_808025E8_chdinoboss(Actor *actor)
{
    s32 map_id;
    s32 despawn;

    map_id = func_800EA05C();
    despawn = 1;
    actor->actorData[4] = -1;
    if (!_glcutDll_entrypoint_19(0x33)) {
        if (func_800DA298(0xE5) && map_id == 0x112 && !_subaddiefind_entrypoint_2(0x234, 0)) {
            func_80108B04(actor, 0);
            despawn = 0;
        }
    } else {
        despawn = 0;
    }
    if (despawn) {
        func_800FFAB0(actor);
    }
}

void func_80802684_chdinoboss(u8 *actor, s32 unk_1)
{
    if (func_800D9078(actor + 0x58, unk_1, actor) != 0 && *(s32 *) (actor + 0x28) == 0x1D) {
        func_80108B04(actor, 0);
    }
}

void func_80802864_chdinoboss();

s32 func_808026D0_chdinoboss(Actor *actor, s32 msg, s32 msg_data)
{
    s32 map_id;
    switch (msg) {
        case 0xB:
            switch (msg_data) {
                case 0x1D:
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(actor->unk0, 0, 0x25, 0x2820);
                    *(s32 *) ((u8 *) actor + 0x28) = 0x25;
                    return 4;
                case 0x25:
                    _glcutDll_entrypoint_24(0x115, 0x113, 0x33);
                    *(s32 *) ((u8 *) actor + 0x28) = -1;
                    return 2;
                case 4:
                    _glcutDll_entrypoint_17();
                    *(s32 *) ((u8 *) actor + 0x28) = -1;
            }
            return 2;
        case 0x3D:
            func_80802864_chdinoboss(actor, msg_data);
            return 1;
        case 0x49:
            map_id = func_800EA05C();
            if (msg_data != 0x33) {
                return 0;
            }
            switch (map_id) {
                case 0x112:
                    actor->unk58 = 0.8f;
                    *(s32 *) ((u8 *) actor + 0x28) = 0x1D;
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x17FB, 0x44, 0, 0x57);
                    _capod_entrypoint_13(actor->unk0, 0, 0x1D, 0x2820);
                    break;
                case 0x115:
                    *(s32 *) ((u8 *) actor + 0x28) = 4;
                    _capod_entrypoint_13(actor->unk0, 0, 4, 0x2820);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80802864_chdinoboss(s32 actor, s32 msg_data)
{
    s32 fx_alias;
    s32 fx;

    if (msg_data == 0) {
        fx = func_80108528(0x234, &D_80802CA8_chdinoboss, 0x5A, &actor);
        fx_alias = fx;
        func_80102FDC(fx, 0.8f);
        if (_glcutDll_entrypoint_19(0x33) != 0) {
            _chappearfx_entrypoint_1(fx_alias, 0x22, 2, 0x3F800000);
            return;
        }
        func_800FFAB0(actor);
    }
}

extern void func_8010A730();
f32 D_80802A20_chdinoboss[3] = {3e+02f, 1e+01f, -1.5e+02f};
u8 D_80802A2C_chdinoboss[8] = {0x0, 0x13, 0x4, 0x17, 0x0, 0x2, 0x0, 0x0};
u8 D_80802A34_chdinoboss[20] = {0x0, 0x13, 0x5, 0x38, 0x0, 0x2, 0x0, 0x16, 0x75, 0x30,
                                0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x0,  0x0,  0x0};
u8 D_80802A48_chdinoboss[16] = {0x0, 0x13, 0x3, 0xFF, 0x0, 0xD, 0x0, 0x73,
                                0x0, 0x8C, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
u8 D_80802A58_chdinoboss[16] = {0x0, 0x13, 0x5, 0x39, 0x0, 0x2, 0x0, 0x18,
                                0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80802A68_chdinoboss[216] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1,
    0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1,  0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1,
    0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x1, 0x62, 0x0, 0x2,
    0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x3, 0x1,  0x40, 0x99, 0x99, 0x9A, 0x1, 0x61, 0x0, 0x1,
    0x3F, 0x80, 0x0,  0x0,  0x1, 0x5F, 0x0, 0x42, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1,
    0x3E, 0xE6, 0x66, 0x66, 0x1, 0x60, 0x0, 0x1,  0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1,
    0x3F, 0x80, 0x0,  0x0,  0x1, 0x5F, 0x0, 0x42, 0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1,
    0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1,  0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1,
    0x3F, 0x66, 0x66, 0x66, 0x1, 0x5E, 0x0, 0x1,  0x3F, 0x80, 0x0,  0x0,  0x1, 0x5D, 0x3, 0x2,
    0x41, 0x3B, 0xAE, 0x14, 0x1, 0xC1, 0x0, 0x1,  0x41, 0x3B, 0xAE, 0x14, 0x1, 0xC1, 0x0, 0x1,
    0x40, 0xE7, 0x5C, 0x29, 0x1, 0xF7, 0x0, 0x1,  0x40, 0xE7, 0x5C, 0x29, 0x1, 0xF7, 0x0, 0x1,
    0x3F, 0x0,  0x0,  0x0,  0x1, 0x5C, 0x0, 0x2,  0x3F, 0x0,  0x0,  0x0,  0x1, 0x5C, 0x0, 0x2,
    0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1,  0x40, 0x8C, 0xCC, 0xCD, 0x1, 0x61, 0x0, 0x1,
    0x41, 0x1C, 0xCC, 0xCD, 0x1, 0x63, 0x0, 0x1};
int D_80802B40_chdinoboss = 0x2FA036F;
static int D_80802B40_chdinoboss_rest[17] = {0x6DA0001,
                                             (int) &D_80802A68_chdinoboss,
                                             (int) func_80800220_chdinoboss,
                                             (int) func_80105834,
                                             (int) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x10568,
                                             0x0,
                                             (int) func_80108ED0,
                                             0x1780000,
                                             (int) func_80800018_chdinoboss,
                                             (int) func_80107C2C,
                                             -0x7FDEFBE0,
                                             (int) func_80800C50_chdinoboss,
                                             0x0};
void *D_80802B88_chdinoboss = (void *) 0x009F03D8;
static void *D_80802B88_chdinoboss_rest[17] = {(void *) 0x00000001,
                                               0,
                                               func_80802684_chdinoboss,
                                               func_80105834,
                                               func_8010A730,
                                               0,
                                               0,
                                               0,
                                               0,
                                               0,
                                               0,
                                               0,
                                               func_808025E8_chdinoboss,
                                               func_80107C2C,
                                               (void *) 0x80000602,
                                               func_808026D0_chdinoboss,
                                               0};
u8 D_80802BD0_chdinoboss[28] = {0x0, 0x0, 0x9,  0xC4, 0x0,  0x0, 0x17, 0xB7, 0x0, 0x0,
                                0x6, 0x1, 0x12, 0xB,  0x0,  0x0, 0x0,  0x57, 0x0, 0x0,
                                0x0, 0xE, 0x22, 0x28, 0x15, 0x0, 0x0,  0x0};
u8 D_80802BEC_chdinoboss[8] = {0x0, 0x13, 0x4, 0xAA, 0x0, 0x2, 0x0, 0x0};
u8 D_80802BF4_chdinoboss[16] = {0x0, 0x13, 0x5, 0x35, 0x0, 0x2, 0x0, 0xD,
                                0x0, 0xF3, 0x1, 0xC,  0x0, 0x0, 0x0, 0x0};
u8 D_80802C04_chdinoboss[16] = {0x0, 0x13, 0x5, 0x34, 0x0, 0x2, 0x0, 0x18,
                                0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80802C14_chdinoboss[20] = {0x3D, 0x38, 0x51, 0xEC, 0x3D, 0xB4, 0x39, 0x58, 0x3E, 0xD,
                                0x4F, 0xDF, 0x3E, 0x3D, 0x70, 0xA4, 0xBF, 0x80, 0x0,  0x0};
u8 D_80802C28_chdinoboss[12] = {0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xBD,
                                0x70, 0xA4, 0xBF, 0x80, 0x0,  0x0};
u8 D_80802C34_chdinoboss[12] = {0x3F, 0x40, 0x0, 0x0, 0x3F, 0x6B, 0x85, 0x1F, 0xBF, 0x80, 0x0, 0x0};
u32 D_80802C40_chdinoboss = 0x3E99999A;
static u32 D_80802C40_chdinoboss_rest[2] = {0x3F266666, 0xBF800000};
void *D_80802C4C_chdinoboss = (void *) 0x3C23D70A;
static void *D_80802C4C_chdinoboss_rest[6] = {(void *) 0x3E3851EC, (void *) 0x3EB33333,
                                              (void *) 0x3F051EB8, (void *) 0x3F2E147B,
                                              (void *) 0x3F570A3D, (void *) 0xBF800000};
int D_80802C68_chdinoboss = 0x130512;
static int D_80802C68_chdinoboss_rest[3] = {0x2000D, 0xC000D9, 0x0};
int D_80802C78_chdinoboss = 0x130551;
static int D_80802C78_chdinoboss_rest[3] = {0x2000D, 0xF3010C, 0x0};
int D_80802C88_chdinoboss = 0x3EE147AE;
static int D_80802C88_chdinoboss_rest[3] = {0x3F000000, 0x3F0F5C29, -0x40800000};
s32 D_80802C98_chdinoboss = 0x130535;
static s32 D_80802C98_chdinoboss_rest[3] = {0x2000D, 0x9900B3, 0x0};
s32 D_80802CA8_chdinoboss = -0x3A2EA000;
static s32 D_80802CA8_chdinoboss_rest[5] = {0x44A28000, -0x3A768000, 0x0, 0x0, 0x0};
