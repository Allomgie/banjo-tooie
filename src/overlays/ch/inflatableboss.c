#include "common.h"

extern void *D_80802E50_chinflatableboss;
struct anctrl_s;
extern s16 D_80802D8C_chinflatableboss[];
extern void *func_80100094(Actor *, u32);
extern void *func_80104248(Actor *);
extern void func_8008B1C8(struct anctrl_s *, f32);
typedef struct {
    u8 pad_0[0x18];
    u32 pad_1 : 11;
    u32 section : 4;
    u32 pad_2 : 17;
} InflatableBossMarker;
extern u8 D_80802F08_chinflatableboss[];
typedef struct {
    u8 local_0[0x10];
    f32 local_1[3];
    u8 pad_0[0x478];
    u8 local_2;
    u8 pad_1[2];
    u8 local_3;
} InflatableBossDestination;
extern f32 func_800DC178(f32, f32);
extern u8 D_80802F68_chinflatableboss[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_80102D78(Actor *, void *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 D_80802D98_chinflatableboss[];
typedef struct {
    u8 pad_0[0x254];
    f32 local_0[3];
    u8 pad_1[4];
    f32 local_1;
} InflatableSpawnAnchor;
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
typedef struct {
    f32 position[3];
    f32 unused;
    f32 yaw;
    s32 flags;
} InflatableBossSpawn;
typedef struct {
    u8 pad[0x6C];
    s32 count;
    InflatableBossSpawn spawns[1];
} InflatableBossSpawnList;
extern Actor *func_80108474(s32, f32 *, s32);
extern void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
extern s32 D_80802F90_chinflatableboss[];
extern s32 D_80802FC4_chinflatableboss[];
typedef struct {
    u8 pad_0[0x40];
    f32 local_0;
    u8 pad_1[0x453];
    u8 local_1;
} InflatableBossAttackDuration;
extern s16 D_80802D80_chinflatableboss[];
extern void func_80101CDC(Actor *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800B0D80(s32, s32, f32 *, f32 *, f32, s32, s32, f32 *, f32 *);
extern u8 func_8010D5DC[];
extern void func_800F4A58(s32, f32 *, f32);
typedef struct {
    f32 local_0[3];
    s32 local_1;
    u8 pad_0[8];
} InflatableMarker481;
typedef struct {
    u32 a : 1;
    u32 b : 1;
    u32 rest : 30;
} BF74;
extern s32 D_80802E98_chinflatableboss[];
extern s32 D_80802EA0_chinflatableboss[];
extern s32 D_80802EB4_chinflatableboss[];
extern s32 D_80802EC4_chinflatableboss[];
extern s32 D_80802ED0_chinflatableboss[];
extern s32 D_80802EDC_chinflatableboss[];
extern s32 D_80802EE8_chinflatableboss[];
extern s32 func_80102CF4(u8 *, f32);
extern f32 func_8010CD28();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, s32 *, f32);
typedef struct {
    u8 pad0[0x1C];
    f32 unk1C[3];
    u8 pad28[0x20];
    f32 unk48[3];
    f32 unk54[3];
    u8 pad60[0x427];
    u8 unk487[12];
    u8 pad493[3];
    u8 unk496;
    u8 pad497;
    u8 unk498;
    u8 unk499;
    u8 unk49A;
    u8 pad49B;
    u8 unk49C;
    u8 unk49D;
} BalloonData;
typedef union {
    s32 i;
    struct {
        s16 a;
        s16 b;
    } h;
} BalloonArg;
typedef struct {
    s32 v[3];
} BalloonEntry;
extern void func_80101180(s32, s32, s32);
extern void func_800FFAB0(Actor *);
extern void func_80108B04(Actor *, s32);
extern s32 func_800F54E4(void);
extern void func_800F497C(s32);
extern void func_800F49D4(s32, void *, Unk80132ED0 *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800F8300(s32, s32, f32 *);
extern void func_80101010(f32 *);
extern void func_800F49A8(s32, s32);
extern void func_800FDC28(s32);
extern s32 func_800D395C(void);
extern void func_80101074(BalloonEntry *);
extern s32 D_80802F2C_chinflatableboss[];
extern s16 D_80802F0E_chinflatableboss[];
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern int func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA714();
extern s32 func_800AE630(void *, u8 *, s32, f32 *);
extern s32 func_801017D0(s32 *);
extern void *func_80101808(Actor *, s32 (*)(s32 *));
extern void *func_80104130(void);
extern void func_800DBEFC(void *, s32, f32 *);
extern void *func_801040A8(Actor *);
extern void *func_800B27E0(void *);
extern void *func_800D674C(s32);
extern void func_800EFD24(f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern void func_800BC358();
extern s32 D_80802FF8_chinflatableboss[];
extern void func_800BBD18(s32, f32 *, f32 *, f32, s32);
extern u8 func_800C4350(u8, f32 *, void *);
extern u8 D_80803008_chinflatableboss[];
extern void func_800C3868(u8, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x487];
    u8 states[12];
} InflatablePartStates;
int func_80801904_chinflatableboss();
s32 func_80801C7C_chinflatableboss();
s32 func_80801CB4_chinflatableboss();
void func_80801EA0_chinflatableboss();
int func_80801FC0_chinflatableboss();
s32 func_80802590_chinflatableboss();
void func_8080267C_chinflatableboss();
void func_80802A00_chinflatableboss();
int func_80802A2C_chinflatableboss();
void func_80802A9C_chinflatableboss();
void func_80802AD8_chinflatableboss();
void func_808012EC_chinflatableboss();
void func_80801958_chinflatableboss();
void func_80801F4C_chinflatableboss();
void func_80802058_chinflatableboss();
void func_80802264_chinflatableboss(Actor *param_0, f32 param_1, f32 param_2, s32 *param_3,
                                    s16 param_4);
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800408_chinflatableboss(),
    func_808004A0_chinflatableboss(), func_80801554_chinflatableboss();

// Returns the actor class table.
int chinflatableboss_entrypoint_0()
{
    return &D_80802E50_chinflatableboss;
}

void func_8080183C_chinflatableboss();

void func_80800F84_chinflatableboss();

void func_8080000C_chinflatableboss(actor) Actor *actor;
{
    u8 *boss;
    s32 i;
    InflatableMarker481 markers[3];
    s32 j;
    s32 k;
    s32 marker_count;
    f32 *pos;
    s32 player;

    boss = func_80100094(actor, 0);
    func_800DA524(1);
    func_800DA524(2);
    func_800DA524(4);
    func_800DA524(3);
    func_800DA524(5);
    if (func_800DA298(0x9C) && !_glcutDll_entrypoint_20()) {
        func_800DA544(3);
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(actor);
        return;
    }
    func_80102FDC(actor, 1.4f);
    boss[0x494] = 1;
    boss[0x495] = D_80802D8C_chinflatableboss[0];
    *(f32 *) ((u8 *) actor + 0x28) = 0.35f;
    func_80109FE8(actor, 0);
    pos = actor->position;
    func_800EE7F8((f32 *) (boss + 0x1C), pos);
    func_800EE7F8((f32 *) (boss + 0x28), pos);
    func_800EE7F8((f32 *) (boss + 0x34), pos);
    for (i = 0; i != 12; i++) {
        func_80802AD8_chinflatableboss(actor, i, 1);
    }
    _subaddieDll_entrypoint_10(0x154, boss);
    _subaddieDll_entrypoint_10(0x320, boss + 8);
    func_8080183C_chinflatableboss(actor);
    func_8010A85C(actor, 2);
    _suexpression_entrypoint_7(actor, 1, 0x3A);
    *(s32 *) (boss + 0x6C) =
        _subaddiemarker_entrypoint_1(actor, 0x437, 0x32, boss + 0x70, 0x14);
    *(s32 *) (boss + 0x250) =
        _subaddiemarker_entrypoint_1(actor, 0x437, 0x35, boss + 0x254, 0x14);
    marker_count = _subaddiemarker_entrypoint_0(actor, 0x3DA, markers, 0x14);
    for (j = 0; j < marker_count; j++) {
        for (k = 0; k < marker_count; k++) {
            if (markers[k].local_1 - 0x32 == j) {
                break;
            }
        }
        func_800EE7F8(((Vec3f *) (boss + 0x48))[j].f, markers[k].local_0);
    }
    if (func_800DA298(0x17F)) {
        boss[0x498] = 5;
    } else {
        boss[0x498] = 1;
    }
    if (!func_800F64A4(func_800F54E4(), 1)) {
        boss[0x498] = 0;
    }
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C(actor, 1);
        func_80800F84_chinflatableboss(actor, _chcredits_entrypoint_1() == 0x36 ? 0x12 : 0x13);
        return;
    }
    if (boss[0x498] == 5) {
        player = func_800F54E4();
        boss[0x49C] = 1;
        boss[0x496] = 1;
        func_800F608C(player, 1);
        func_800F8294(player, boss + 0x54);
        func_800F8300(player, 2, pos);
        func_800F497C(player);
        _plcamera_entrypoint_8(player);
        func_800DA544(2);
        func_80802A00_chinflatableboss(actor, 0x22, 0x20);
        _subaddiedialog_entrypoint_11(actor->unk0, 0x1087, 0x107, pos, 0x3A);
        func_80800F84_chinflatableboss(actor, 3);
        func_8010A85C(actor, 1);
        return;
    }
    if (func_800D395C()) {
        actor->unk64_16 = 1;
        boss[0x498] = 2;
        func_800F497C(func_800F54E4());
        func_800F49D4(func_800F54E4(), func_8010D5DC, actor->unk0);
        func_800F4A58(func_800F54E4(), (f32 *) (boss + 0x48), 300.0f);
        func_80802A00_chinflatableboss(actor, 0x2F, 0x20);
        return;
    }
    ((u8 *) actor)[0x65] &= ~1;
    _chintrotext_entrypoint_2(1);
}

void func_80800408_chinflatableboss(actor) s32 actor;
{
    u8 *boss;
    s32 patch_fx;
    s32 jet_fx;
    s32 offset;
    u8 *cursor;

    boss = func_80100094(actor, 0);
    _suexpression_entrypoint_8(actor, 1);
    offset = 0;
    cursor = boss;
    do {
        patch_fx = (*(s32 *) ((s8 *) (cursor) + (0x43C)));
        if (patch_fx != 0) {
            (*(s32 *) ((s8 *) (cursor) + (0x43C))) = func_800BA2C4(patch_fx);
        }
        offset += 4;
        cursor += 4;
    } while (offset != 0x30);
    jet_fx = (*(s32 *) ((s8 *) (boss) + (0x434)));

    if (jet_fx != 0) {
        *(s32 *) ((s8 *) boss + 0x434) = func_800BA2C4(jet_fx);
    }
}

void func_80802910_chinflatableboss();

s32 func_8080272C_chinflatableboss();

void func_808024BC_chinflatableboss();

void func_80802450_chinflatableboss();

int func_8080200C_chinflatableboss();

void func_80801B04_chinflatableboss();

void func_808004A0_chinflatableboss(actor) u8 *actor;
{
    u8 *boss;
    u8 *dialog_pos;
    s32 pad2;
    f32 bone_pos[3];

    boss = func_80100094(actor, 0);
    func_80802058_chinflatableboss(actor);
    _suexpression_entrypoint_10(func_80100094(actor, 1), *(s32 *) actor, 0);
    func_8080272C_chinflatableboss(actor);
    func_808029AC_chinflatableboss(actor);

    switch ((u32) *(u16 *) (actor + 0x72) >> 10) {
        case 2:
            func_80802264_chinflatableboss(actor, 0.3f, 0.3f, &D_80802E98_chinflatableboss, 2);
            func_80802264_chinflatableboss(actor, 0.3f, 0.5f, &D_80802EA0_chinflatableboss, 5);
            if (func_80101DDC(actor) != 0) {
                _subaddiedialog_entrypoint_11(*(s32 *) actor, 0x1082, 0x106, actor + 4, 0x3A);
                func_80800F84_chinflatableboss(actor, 3);
                func_8008B1C8(func_80104248(actor), 0.8f);
            }
            break;
        case 4:
            func_80802264_chinflatableboss(actor, 0.5f, 0.8f, &D_80802EB4_chinflatableboss, 4);
            if (func_80101E14(actor, 0x3F000000) != 0) {
                func_800DA544(4);
            }
            if (func_80101DDC(actor) != 0) {
                dialog_pos = actor + 4;
                if (*(u8 *) (boss + 0x49C) != 0) {
                    func_80802910_chinflatableboss(actor);
                } else {
                    _subaddiedialog_entrypoint_11(*(s32 *) actor, 0x1083, 0x106, dialog_pos, 0x3A);
                    func_80800F84_chinflatableboss(actor, 5);
                    func_8008B1C8(func_80104248(actor), 0.8f);
                }
            }
            break;
        case 9:
            *(f32 *) (actor + 0x54) = func_8010CD28(actor);
            func_80102BF8(actor, 0.1f, 3.0f, 90.0f);
            if (func_800D9078(actor + 0x58) != 0) {
                func_8080183C_chinflatableboss(actor);
                func_808024BC_chinflatableboss(actor);
                *(f32 *) (actor + 0x54) = func_80102D78(actor, actor + 0x18);
            }
            break;
        case 10:
            *(f32 *) (actor + 0x54) = func_8010CD28(actor);
            func_80102BF8(actor, 0.1f, 3.0f, 90.0f);
            if (func_80102CF4(actor, 8.0f) != 0) {
                func_80800F84_chinflatableboss(actor, 0xB);
            }
            break;
        case 6:
            if (!((BF74 *) (actor + 0x74))->b) {
                func_80801B04_chinflatableboss(actor);
            }
            break;
        case 7:
            if (func_800D9078(actor + 0x58) != 0) {
                func_808024BC_chinflatableboss(actor);
            }
            break;
        case 8:
            if (!((BF74 *) (actor + 0x74))->b) {
                func_80801B04_chinflatableboss(actor);
            }
            break;
        case 11:
            *(f32 *) (actor + 0x54) = func_8010CD28(actor);
            func_80102BF8(actor, 0.1f, 3.0f, 90.0f);
            if (func_80101E14(actor, 0x3E99999A) != 0) {
                func_800C4B64(
                    func_800F10B4(*(f32 *) (actor + 0x38), 1.4f, 0.19913846f, 0.9f, 1.2f));
                _subaddieaudioquick_entrypoint_2(actor, boss + 0x1C,
                                                 &D_80802EC4_chinflatableboss);
            } else if (func_80101E14(actor, 0x3EE66666) != 0) {
                func_80108B04(actor, 1);
                *(f32 *) (actor + 0x58) = 1.0f;
                *(u8 *) (boss + 0x495) = *(u8 *) (boss + 0x495) - 1;
            } else if (func_80101E14(actor, 0x3F7FBE77) != 0 && *(u8 *) (boss + 0x495) == 0) {
                func_8080183C_chinflatableboss(actor);
                func_808024BC_chinflatableboss(actor);
                *(f32 *) (actor + 0x54) = func_80102D78(actor, actor + 0x18);
            }
            break;
        case 12:
            if (func_80101E14(actor, 0x3E800000) != 0) {
                func_800C4B64(
                    func_800F10B4(*(f32 *) (actor + 0x38), 1.4f, 0.19913846f, 1.0f, 1.4f) * 0.8f);
                _subaddieaudioquick_entrypoint_2(actor, boss + 0x1C,
                                                 &D_80802ED0_chinflatableboss);
            }
            if (func_80101DDC(actor) != 0) {
                func_80800F84_chinflatableboss(actor, 0xD);
            }
            break;
        case 13:
            func_80802450_chinflatableboss(actor);
            if (func_80101DDC(actor) != 0) {
                if (func_80801CB4_chinflatableboss(actor) == 0) {
                    func_80800F84_chinflatableboss(actor, 0xE);
                } else {
                    func_808024BC_chinflatableboss(actor);
                }
            }
            break;
        case 15:
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80802EDC_chinflatableboss,
                                             0.03f);
            if (func_80101E14(actor, 0x3D75C28F) != 0) {
                _subaddieskeleton_entrypoint_3(*(s32 *) actor, 7, bone_pos);
                *(s32 *) (boss + 0x434) =
                    func_8080200C_chinflatableboss(actor, bone_pos, boss + 0x28);
            }
            if (func_80101E14(actor, 0x3EDC28F6) != 0) {
                func_800C4AF0(boss + 0x34, &D_80802EE8_chinflatableboss);
            }
            if (func_80101DDC(actor) != 0) {
                func_800FDC28(0);
                func_800DA544(3);
                if (func_800D395C() != 0) {
                    func_80800F84_chinflatableboss(actor, 0x10);
                    func_80802A9C_chinflatableboss(actor);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_800DA544(0x9C);
                    func_80108B04(actor, 3);
                    func_80800F84_chinflatableboss(actor, 0x10);
                }
            }
            break;
        case 18:
            func_80802264_chinflatableboss(actor, 0.5f, 0.8f, &D_80802EB4_chinflatableboss, 4);
            if (func_80101DDC(actor) != 0) {
                func_80800F84_chinflatableboss(actor, 0x13);
            }
    }

    func_8080267C_chinflatableboss(actor);
}

void func_80801DE0_chinflatableboss();

void func_80801D38_chinflatableboss();

s32 func_80801AD8_chinflatableboss();

void func_80801418_chinflatableboss();

void func_80801164_chinflatableboss();

void func_808010BC_chinflatableboss();

BalloonEntry B_80803020_chinflatableboss[12];

s32 func_80800A98_chinflatableboss(Actor *actor, s32 msg, BalloonArg arg)
{
    BalloonData *boss;
    s32 player;
    s32 i;
    s32 count;

    boss = func_80100094(actor, 0);

    switch (msg) {
        case 0xB:
            switch (arg.i) {
                case 0x14:
                    func_80800F84_chinflatableboss(actor, 0x11);
                    func_80802A00_chinflatableboss(actor, 0x31, 0x10);
                    func_80101180(0x46E, 7, 0);
                    return 4;
                case 0x31:
                    boss->unk49D = 0;
                    func_800FFAB0(actor);
                default:
                ret3:
                    return 3;
                case 3:
                    if (boss->unk49C) {
                        goto ret3;
                    }
                    func_80802A00_chinflatableboss(actor, 0xC, 0x20);
                    return 4;
                case 0xA:
                    boss->unk49D = 0;
                    // Matching: empty block steers IDO.
                    if (actor) {
                    }
                    return 3;
                case 0xC:
                case 0x19:
                case 0x22:
                    boss->unk49A = 1;
                    // Matching: empty block steers IDO.
                    if (1) {
                    }
                    return 3;
                case 8:
                    func_80108B04(actor, 2);
                    func_80802A00_chinflatableboss(actor, 0xA, 0x10);
                    return 4;
            }
        case 0x2E:
            func_80801958_chinflatableboss(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x2F:
            func_80801AD8_chinflatableboss(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x3D:
            switch (arg.i) {
                case 0:
                    func_80801DE0_chinflatableboss(actor);
                    return 1;
                case 1:
                    func_80801D38_chinflatableboss(actor);
                    return 1;
                case 2:
                    func_80801EA0_chinflatableboss(actor);
                    return 1;
                case 3:
                    func_80801F4C_chinflatableboss(actor);
            }
            break;
        case 0x32:
            if (boss->unk498 == 2) {
                boss->unk498 = 3;
                boss->unk49A = 0;
                func_800F497C(func_800F54E4());
                func_800F49D4(func_800F54E4(), func_8010D5DC, actor->unk0);
                func_800F4A58(func_800F54E4(), boss->unk54, 300.0f);
                func_80802A00_chinflatableboss(actor, 0x19, 0x20);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x10CC, 0x44, actor->position, 0x3A);
                func_80101180(0x46E, 8, 0);
                return 1;
            }
            boss->unk499 = 1;
            func_800F8300(func_800F54E4(), 2, actor->position);
            break;
        case 0x3F:
            func_808010BC_chinflatableboss(actor, *(s32 *) &arg);
            break;
        case 0x40:
            func_80801164_chinflatableboss(actor, *(s32 *) &arg);
            break;
        case 6:
            func_80101010(boss->unk1C);
            break;
        case 0xA:
            player = func_800F54E4();
            actor->unk64_16 = 1;
            boss->unk498 = 2;
            func_800F497C(player);
            func_800F49A8(player, 1);
            func_800F49D4(player, func_8010D5DC, actor->unk0);
            func_800F4A58(player, boss->unk48, 300.0f);
            func_80802A00_chinflatableboss(actor, 0x2F, 0x20);
            break;
        case 0x95:
            if (boss->unk496) {
                boss->unk496 = 0;
                func_800FDC28(1);
            }
            break;
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x146, actor->position, 0x3A);
            break;
        case 0x9F:
            func_800FDC28(0);
            func_80800F84_chinflatableboss(actor, 5);
            break;
        case 0x1F:
            func_80801418_chinflatableboss(actor, *(s32 *) &arg);
            break;
        case 0xA2:
            count = 0;
            if (!actor->unk7C_12) {
                return 0;
            }
            for (i = 0; i != 12; i++) {
                if (boss->unk487[i] == 1) {
                    func_80802590_chinflatableboss(actor, &B_80803020_chinflatableboss[count],
                                                   i + 3);
                    count++;
                }
            }
            func_80101074(B_80803020_chinflatableboss);
            return count;
        default:
            return 0;
    }

    return 1;
}

void func_80800F84_chinflatableboss(Actor *actor, s32 state)
{
    u8 *boss;

    boss = func_80100094(actor, 0);
    func_80102424(actor, state);

    switch (state) {
        case 11:
            func_8008B1C8(func_80104248(actor), 0.8f);
            boss[0x495] = D_80802D8C_chinflatableboss[func_80801C7C_chinflatableboss(actor)];
            break;
        case 13:
            func_8008B1C8(func_80104248(actor), 0.8f);
            *(f32 *) (boss + 0x44) = actor->scale;
            break;
        case 14:
            func_80802A00_chinflatableboss(actor, 0x2B, 0x30);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1084, 0x10C, actor->position, 0x3A);
            func_8010A570(actor);
            func_8008B1C8(func_80104248(actor), 0.8f);
            break;
        case 16:
            ((u8 *) actor)[0x65] &= ~1;
    }
}

void func_808010BC_chinflatableboss(Actor *actor, s32 arg)
{
    u8 *boss;
    s32 patch;
    u32 sec;
    s32 idx;
    boss = func_80100094(actor, 0);

    if (!func_800DA298(5)) {
        sec = ((InflatableBossMarker *) actor->unk0)->section;
        patch = sec;
        if (patch >= 3 && patch < 15) {
            patch -= 3;
            idx = 0x487 + patch;
            if (boss[idx] != 2) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1086, 0x10E, actor->position,
                                              0x3A);
                func_800DA544(5);
                actor->unk74_30 = 1;
            }
        }
    }
}

void func_80801164_chinflatableboss(Actor *actor, s32 section)
{
    u8 *boss;
    s32 patch;
    f32 hit_pos[3];
    f32 anchor_pos[3];
    s32 radius;
    u32 unk_0;
    s32 unk_1;

    boss = func_80100094(actor, 0);
    section = (*(u32 *) ((u8 *) actor->unk0 + 0x18) << 11) >> 28;

    if (section >= 3) {
        patch = section - 3;
        if (section < 15 && (boss + 0x487)[patch] != 2) {
            radius = func_80802590_chinflatableboss(actor, hit_pos, section);
            _subaddieaudioquick_entrypoint_2(actor, hit_pos, D_80802F08_chinflatableboss);
            func_808012EC_chinflatableboss(actor, hit_pos, radius);
            func_80801904_chinflatableboss(actor, patch, anchor_pos);
            *(s32 *) (boss + patch * 4 + 0x43C) =
                func_80801FC0_chinflatableboss(actor, hit_pos, anchor_pos);
            func_80802AD8_chinflatableboss(actor, patch, 2);
            func_80800F84_chinflatableboss(actor, 12);
            unk_1 = func_80104248(actor);
            func_8008B1C8(unk_1, 0.8f);
            boss[0x493] = 1;
            unk_1 = func_80801CB4_chinflatableboss(actor);
            if (unk_1 != 0) {
                if (unk_1 == 11) {
                    func_800DA544(5);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1085, 0x10E, actor->position,
                                                  0x3A);
                    func_80802A00_chinflatableboss(actor, 0x2D, 0x20);
                    actor->unk74_30 = 1;
                }
            } else {
                func_800DA544(0);
                func_80802A00_chinflatableboss(actor, 0x29, 0x30);
            }
        }
    }
}

void func_808012EC_chinflatableboss(actor, pos, radius) Actor *actor;
f32 *pos;
s32 radius;
{
    f32 vec[2][3];
    s32 particle;

    func_80801904_chinflatableboss((s32) actor,
                                   ((*(u32 *) ((u8 *) actor->unk0 + 0x18) << 11) >> 28) - 3,
                                   (s32) vec[0]);
    func_800EFB24(vec[1], pos, vec[0]);
    func_800EF368(vec[1], radius * 0.5f);
    func_800EF04C(vec[1], pos);
    particle = func_800BABB8(0, pos, vec[1], actor->scale, D_80802F2C_chinflatableboss);
    func_800BA714(particle, (s16) (s32) (radius * 0.4f), (s16) (s32) (radius * 0.6f));
    func_800BA670(
        particle, D_80802F0E_chinflatableboss[(*(u32 *) ((u8 *) actor->unk0 + 0x18) << 11) >> 28]);
    func_800BA22C(particle, 8);
}

void func_80801418_chinflatableboss(Actor *actor, void *arg)
{
    u8 *boss;
    u8 *cursor;
    s32 i;

    boss = func_80100094(actor, 0);
    func_80103D48(actor);
    _suexpression_entrypoint_19(func_80100094(actor, 1), actor);
    if (!actor->unk64_20)
        func_8080267C_chinflatableboss(actor);
    func_800DF72C(func_801040A8(actor));
    func_800DF830(1);
    func_800DF738(func_80104130());
    func_800DF818(func_80103CDC(actor, arg));
    func_800DF660(2, (u32) ((u8 *) actor)[0x7B] >> 6, 0, _subaddiefade_entrypoint_0(actor));
    func_800DF720(func_80100AC4(*(s16 *) ((u8 *) actor + 0x60)));
    func_80101934(actor);
    func_80103D70(actor);
    for (i = 0, cursor = boss; i < 0xF; i++, cursor++) {
        func_800DF744(i + 3, cursor[0x478]);
    }
    actor->unk7C_12 = 1;
    actor->unk64_20 = 0;
}

void func_80801554_chinflatableboss(actor, arg) Actor *actor;
s32 arg;
{
    u8 *boss;
    s32 i = 0;
    void *unk_0;
    void *unk_1;
    f32 particle_vel[3];
    f32 bone_pos[3];
    void *unk_2;
    void *unk_3;

    boss = func_80100094(actor, 0);
    unk_0 = func_80101808(actor, func_801017D0);
    if (actor->unk7C_12) {
        unk_1 = func_80104130();
        func_800DBEFC(unk_1, 4, (f32 *) (boss + 0x1C));
        func_800DBEFC(unk_1, 5, (f32 *) (boss + 0x28));
        func_800DBEFC(unk_1, 6, (f32 *) (boss + 0x34));
    }
    if (unk_0 && (s32) actor->unk70_10 < 16) {
        unk_2 = func_800B27E0(unk_0);
        unk_3 = func_800D674C(0x637);
        func_800EFD24(particle_vel);

        if (func_800AE630(func_801040A8(actor), (u8 *) unk_2, 12, bone_pos)) {
            func_800EF334(bone_pos, *(f32 *) &actor->actorData[4]);
            func_800EF5A0(bone_pos, actor->rotation, bone_pos[0], bone_pos[1], bone_pos[2]);
            func_800EF04C(bone_pos, actor->position);
            bone_pos[1] = actor->position[1];
            func_800DF410(_subaddiefade_entrypoint_0(actor));
            func_800DF830(3);
            func_800DE448(bone_pos, particle_vel, *(f32 *) &actor->actorData[4] * 9.0f, 0,
                          (s32) unk_3);
        }

        if (func_800AE630(func_801040A8(actor), (u8 *) unk_2, 26, bone_pos)) {
            func_800EF334(bone_pos, *(f32 *) &actor->actorData[4]);
            func_800EF5A0(bone_pos, actor->rotation, bone_pos[0], bone_pos[1], bone_pos[2]);
            func_800EF04C(bone_pos, actor->position);
            bone_pos[1] = actor->position[1];
            func_800DF410(_subaddiefade_entrypoint_0(actor));
            func_800DF830(3);
            func_800DE448(bone_pos, particle_vel, *(f32 *) &actor->actorData[4] * 9.0f, 0,
                          (s32) unk_3);
        }

        func_800DF410(_subaddiefade_entrypoint_0(actor));
        func_800DF830(3);
        func_800DE448(actor->position, particle_vel, *(f32 *) &actor->actorData[4] * 1.4f * 9.0f, 0,
                      (s32) unk_3);
    }
    for (i = 0; i < 12; i++) {
        if (((s32 *) (boss + 0x43C))[i]) {
            func_800BC358(((s32 *) (boss + 0x43C))[i], arg, 0);
        }
    }
    if (*(s32 *) (boss + 0x434)) {
        func_800BC358(*(s32 *) (boss + 0x434), arg, 0);
    }
}

void func_8080183C_chinflatableboss(Actor *actor)
{
    InflatableBossDestination *boss;
    s16 xz[2];

    boss = func_80100094(actor, 0);
    boss->local_2 ^= 1;
    _subaddieDll_entrypoint_12(boss->local_2 ? boss->local_0 : boss->local_0 + 8, xz);
    boss->local_1[0] = xz[0];
    boss->local_1[1] = actor->position[1];
    boss->local_1[2] = xz[1];
    *(f32 *) &actor->actorData[0] = func_800DC178(0.0f, 1000.0f);
    *(f32 *) &actor->actorData[1] = actor->position[1];
    *(f32 *) &actor->actorData[2] = func_800DC178(0.0f, 1000.0f);
    boss->local_3 = 1;
}

int func_80801904_chinflatableboss(actor, patch, out_pos)
s32 actor;
s32 patch;
s32 out_pos;
{
    s32 base;
    base = func_80100094(actor, 0);
    if (patch >= 3 && patch < 6) {
        base += 0x34;
    } else {
        base += 0x28;
    }
    func_800EE7F8(out_pos, base);
}

void func_80801958_chinflatableboss(actor, dialog_id, choice) Actor *actor;
s32 dialog_id;
s32 choice;
{
    switch (dialog_id) {
        case 0x10CC:
            return;
        case 0x1082:
            _chintrotext_entrypoint_1(0x18B9, 3, 1, 0);
        case 0x1087:
            func_80800F84_chinflatableboss(actor, 4);
            func_8008B1C8(func_80104248(actor), 0.8f);
            func_80802A00_chinflatableboss(actor, 3, 0x20);
            break;
        case 0x1083:
            func_80802910_chinflatableboss(actor);
            break;
        case 0x1085:
        case 0x1086:
            *((u8 *) actor + 0x74) &= 0xFFBF;
            break;
        case 0x1084:
            func_801020DC(actor, 0);
            func_80102FDC(actor, actor->scale * 4.0f);
            func_80800F84_chinflatableboss(actor, 15);
            func_8080267C_chinflatableboss(actor);
            func_80802A00_chinflatableboss(actor, 11, 0x38);
            break;
        case 0xCEB:
            if (choice > 0)
                _gcfrontend_entrypoint_11();
            else
                _gcfrontend_entrypoint_10();
    }
    func_8008B1C8(func_80104248(actor), 0.8f);
}

s32 func_80801AD8_chinflatableboss(s32 actor, s32 dialog_id, s32 choice)
{
    if (dialog_id == 0x1085) {
        func_80108B04(actor, 0);
    }
}

void func_80801B04_chinflatableboss(Actor *actor)
{
    u8 *boss;
    boss = func_80100094(actor, 0);
    *(f32 *) ((u8 *) actor + 0x54) = func_80102D78(actor, (f32 *) actor->actorData);
    *(f32 *) ((u8 *) actor + 0x24) = func_800F15F8(
        *(f32 *) ((u8 *) actor + 0x24), *(f32 *) (boss + 0x40), func_800D8FF8() * 200.0f);
    func_80102BF8(actor, 0.1f, 3.0f, 60.0f);
    func_8010C3A8(actor, 5,
                  func_800F3780(func_80101F24(actor), &D_80802F68_chinflatableboss, 5));
    if (func_800F0064((f32 *) actor->actorData, 400.0f, actor->position)) {
        if (boss[0x497]) {
            func_80800F84_chinflatableboss(actor, 7);
            func_800EE7F8((f32 *) actor->actorData, boss + 0x10);
            boss[0x497] = 0;
            *(f32 *) ((u8 *) actor + 0x58) = func_800DC178(4.0f, 6.0f);
        } else if (boss[0x493] == 0) {
            func_80800F84_chinflatableboss(actor, 9);
            *(f32 *) ((u8 *) actor + 0x58) = func_800DC178(6.0f, 8.0f);
        } else
            func_80800F84_chinflatableboss(actor, 10);
        func_8008B1C8(func_80104248(actor), 0.8f);
    }
}

// Phase index (0-5) from the patches burst so far.
s32 func_80801C7C_chinflatableboss()
{
    return (s32) (0xC - func_80801CB4_chinflatableboss()) / 2;
}

// Number of patches not yet burst.
s32 func_80801CB4_chinflatableboss(actor)
Actor *actor;
{
    u8 *boss;
    s32 remaining;
    s32 i;

    boss = func_80100094(actor, 0);
    remaining = 12;
    for (i = 0; i < 12; i++) {
        if (boss[i + 0x487] == 2) {
            remaining--;
        }
    }
    return remaining;
}

void func_80801D38_chinflatableboss(Actor *actor)
{
    f32 *boss;
    Actor *ball;
    s32 stage;
    boss = func_80100094(actor, 0);
    stage = func_80801C7C_chinflatableboss(actor);
    ball = func_80108528(0x13D, &boss[7], 0, &actor);
    func_80102FDC(ball, actor->scale);
    ball->unk3C = actor->unk0;
    ball->unk6C_0 = func_80801CB4_chinflatableboss(actor);
    ball->unk58 = D_80802D98_chinflatableboss[stage];
}

void func_80801DE0_chinflatableboss(Actor *actor)
{
    InflatableSpawnAnchor *anchor;

    anchor = func_80100094(actor, 0);
    _chappearfx_entrypoint_1(
        func_80108528(0x13E, anchor->local_0, (s32) anchor->local_1, &actor), 0x22, 0, 1.0f);
    func_80108528(0x36E, anchor->local_0, (s32) anchor->local_1, &actor);
    if (!func_800DA298(0x6AC)) {
        func_800DA544(0x6AC);
        func_80802A00_chinflatableboss(actor, 8, 0x30);
    } else {
        func_80802A9C_chinflatableboss(actor);
        func_80801EA0_chinflatableboss(actor);
    }
}

void func_80801EA0_chinflatableboss(actor) Actor *actor;
{
    InflatableBossSpawnList *list;
    s32 i;

    list = func_80100094(actor, 0);
    for (i = 0; i < list->count; i++) {
        _chappearfx_entrypoint_2(func_80108474(0x234, list->spawns[i].position,
                                               (s32) list->spawns[i].yaw),
                                 0x20, 2, 1.0f);
    }
}

void func_80801F4C_chinflatableboss(actor) Actor *actor;
{
    f32 spawn_pos[3];
    s32 jiggy;
    Unk80132ED0 *marker;

    marker = actor->unk0;
    func_800EE7F8(spawn_pos, actor->position);
    spawn_pos[1] = 5000.0f;
    jiggy = func_800D10D4(0x17, 1, spawn_pos, 0, 0);
    func_80802A2C_chinflatableboss(func_80106790(marker), jiggy, 0x14, 0x438);
}

int func_80801FC0_chinflatableboss(actor, start, end)
u8 *actor;
s32 start;
s32 end;
{
    func_800BABB8(0, start, end, *(f32 *) (actor + 0x38) * 0.75f,
                  &D_80802F90_chinflatableboss);
}

int func_8080200C_chinflatableboss(u8 *actor, s32 start, s32 end)
{
    func_800BABB8(0, start, end, *(f32 *) (actor + 0x38) * 0.75f,
                  &D_80802FC4_chinflatableboss);
}

void func_80802058_chinflatableboss(actor) Actor *actor;
{
    u8 *boss;
    u8 *loop_ids;
    s32 i;
    s32 part;
    f32 emit_pos[3];
    f32 anchor_pos[3];
    f32 bone_pos[3];
    s32 *fx;
    s32 active;

    boss = func_80100094(actor, 0);
    fx = (s32 *) (boss + 0x43C);
    loop_ids = boss + 0x46C;
    i = 0;
    do {
        part = i + 3;
        if (*fx || *loop_ids) {
            func_80801904_chinflatableboss(actor, part, anchor_pos);
            func_80802590_chinflatableboss(actor, emit_pos, part);
            active = *fx != 0;

            if (active) {
                active = func_800BA198(*fx) >= 8;
            }

            *loop_ids = _subaddieaudioloop_entrypoint_7(*loop_ids, emit_pos, active,
                                                       &D_80802FF8_chinflatableboss,
                                                       *(u32 *) ((u8 *) actor + 0x70) & 1);

            if (*fx) {
                func_800BBD18(*fx, emit_pos, anchor_pos, actor->scale, 0);
                if (func_800BA28C(*fx)) {
                    ((s32 *) (boss + 0x43C))[i] = func_800BA2C4(*fx);
                }
            }
        }
        i++;
        fx++;
        loop_ids++;
    } while (i != 12);
    if (*(s32 *) (boss + 0x434) || boss[0x438]) {
        _subaddieskeleton_entrypoint_3(actor->unk0, 7, bone_pos);
        active = *(s32 *) (boss + 0x434) != 0;
        if (active) {
            active = func_80101F24(actor) < 0.43f;
        }
        boss[0x438] = _subaddieaudioloop_entrypoint_7(boss[0x438], bone_pos, active,
                                                         &D_80802FF8_chinflatableboss,
                                                         *(u32 *) ((u8 *) actor + 0x70) & 1);
        if (*(s32 *) (boss + 0x434)) {
            func_800BBD18(*(s32 *) (boss + 0x434), bone_pos, (f32 *) (boss + 0x28),
                          actor->scale, 0);

            if (func_800BA28C(*(s32 *) (boss + 0x434))) {
                *(s32 *) (boss + 0x434) = func_800BA2C4(*(s32 *) (boss + 0x434));
            }
        }
    }
}

void func_80802264_chinflatableboss(Actor *actor, f32 low, f32 high, s32 *times,
                                    s16 count)
{
    s32 i;
    f32 pitch;
    u8 sound;
    for (i = 0; i < count; i++) {
        if (func_80101E14(actor, times[i])) {
            pitch = func_800F10B4((f32) i, 0.0f, (f32) count, low, high);
            sound = _subaddieaudioquick_entrypoint_1(actor, actor->position);
            func_800C3868(sound, 0.15f, 0.25f, pitch, pitch + 0.12f);
            func_800C4350(sound, actor->position, D_80803008_chinflatableboss);
        }
    }
}

f32 func_808023B0_chinflatableboss(actor)
Actor *actor;
{
    InflatablePartStates *parts;
    f32 scale;
    s32 i;
    parts = func_80100094(actor, 0);
    scale = 1.4f;
    for (i = 0; i < 12; i++) {
        if (parts->states[i] == 2)
            scale *= 0.85f;
    }
    return scale;
}

void func_80802450_chinflatableboss(Actor *actor)
{
    f32 *boss;
    f32 shrink;
    boss = func_80100094(actor, 0);
    shrink = boss[0x11] - func_808023B0_chinflatableboss(actor);
    func_80102FDC(actor, boss[0x11] - shrink * func_80101F24(actor));
}

void func_808024BC_chinflatableboss(Actor *actor)
{
    InflatableBossAttackDuration *boss;
    f32 speed;

    boss = func_80100094(actor, 0);
    boss->local_0 = D_80802D80_chinflatableboss[func_80801C7C_chinflatableboss(actor)];
    ((f32 *) actor->actorData)[3] = 0.0f;
    func_80800F84_chinflatableboss(actor, boss->local_1 ? 6 : 8);
    speed = ((f32) D_80802D80_chinflatableboss[0] / boss->local_0) * 5.0f;
    func_80101CDC(actor, speed);
    func_8008B1C8(func_80104248(actor), 0.8f);
}

s32 func_80802590_chinflatableboss(actor, out_pos, patch_id)
Actor *actor;
f32 *out_pos;
s32 patch_id;
{
    f32 rot[3];
    f32 dist;
    s32 model;

    if (!func_800AE0B8(func_801040A8(actor))) {
        func_800EE7F8(out_pos, actor->position);
        return 0;
    }
    model = func_801039E4(actor->unk0);
    func_800EFA4C(rot, 0.0f, actor->rotation[1], 0.0f);
    if (!func_800B0D80(func_800B2824(model), patch_id, actor->position, rot, actor->scale,
                       0, func_801040A8(actor), out_pos, &dist)) {
        func_800EE7F8(out_pos, actor->position);
        return 0;
    }
    return (s32) dist;
}

void func_8080267C_chinflatableboss(actor) Actor *actor;
{
    s32 pose;
    s32 model_id;
    s32 anctrl;
    f32 bone_pos[3];
    s32 data;

    anctrl = func_80104248(actor);
    if (actor->unk64_16) {
        model_id = func_801039E4(actor->unk0);
        data = func_800B27E0(model_id);
        func_8008B304(anctrl);
        func_8008C200(*(s16 *) &actor->unk0->unk10, data, func_8008AEDC(anctrl));
        pose = func_8008C27C(func_8008AEDC(anctrl));
        func_800DFBE0(pose, 3, bone_pos);
        ((f32 *) actor->actorData)[4] = bone_pos[0] * actor->scale;
        actor->unk64_20 = 1;
    }
}

s32 func_8080272C_chinflatableboss(Actor *boss)
{
    u8 *data;

    data = func_80100094(boss, 0);
    switch (data[0x498]) {
        case 1:
        case 6:
            break;
        case 3:
            if (data[0x49A] && data[0x499]) {
                if (!data[0x49B]) {
                    func_800DA544(2);
                    func_80800F84_chinflatableboss(boss, 2);
                    func_8008B1C8(func_80104248(boss), 0.8f);
                    func_8010A85C(boss, 1);
                    func_80802A00_chinflatableboss(boss, 1, 0x20);
                    data[0x49B] = 1;
                    func_800FDC28(1);
                }

                if (boss->unk70_10 == 4) {
                    data[0x49A] = data[0x499] = 0;
                    func_800F82D4(func_800F54E4(), 0);
                    func_800F497C(func_800F54E4());
                    func_800F49D4(func_800F54E4(), func_8010D5DC, boss->unk0);
                    func_800F4A58(func_800F54E4(), (f32 *) (data + 0x60), 400.0f);
                    data[0x498] = 4;
                }
            }
            break;
        case 5:
            if (boss->unk70_10 == 4) {
                data[0x49A] = 0;
                data[0x499] = 1;
                func_800F82D4(func_800F54E4(), 0);
                func_800F497C(func_800F54E4());
                func_800F49D4(func_800F54E4(), func_8010D5DC, boss->unk0);
                func_800F4A58(func_800F54E4(), (f32 *) (data + 0x60), 400.0f);
                data[0x498] = 4;
            }
    }
    return 0;
}

// Defeat sequence: sets flags 1 and 0x17F (retry).
void func_80802910_chinflatableboss(Actor *boss)
{
    u8 *data;

    data = func_80100094(boss, 0);
    func_800FDC28(4);
    func_80802A9C_chinflatableboss(boss);
    func_800A51C0();
    func_808024BC_chinflatableboss(boss);
    func_800DA544(1);
    func_800DA544(0x17F);
    _gcfrontend_entrypoint_9(0x25);
    func_800F82D4(func_800F54E4(), 0);
    data[0x498] = 6;
    func_8010A590(boss);
    func_80109FE8(boss, 1);
}

// Updates the boss HUD counter with the patches left.
int func_808029AC_chinflatableboss(s32 boss)
{
    if (func_800DA298(1) != 0 && func_800DA298(3) == 0) {
        func_800D2498(0xEC, func_80801CB4_chinflatableboss(boss), 0);
    }
}

void func_80802A00_chinflatableboss(actor, unk_0, unk_1) s32 *actor;
s32 unk_0;
s32 unk_1;
{
    func_80802A2C_chinflatableboss(actor, *actor, unk_0, unk_1);
}

int func_80802A2C_chinflatableboss(actor, unk_0, unk_1, unk_2)
s32 actor[3];
s32 unk_0;
s32 unk_1;
s32 unk_2;
{
    u8 *data;
    data = func_80100094(actor, 0);
    if (data[0x49D]) {
        unk_2 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(unk_0, *actor, unk_1, unk_2);
    data[0x49D] = 1;
}

void func_80802A9C_chinflatableboss(boss) s32 boss;
{
    u8 *data;

    data = func_80100094(boss, 0);
    if (data[0x49d] != 0) {
        _capod_entrypoint_14();
        data[0x49d] = 0;
    }
}

void func_80802AD8_chinflatableboss(boss, index, value) Actor *boss;
s32 index;
s32 value;
{
    u8 *data;

    data = func_80100094(boss, 0);
    data[0x487 + index] = value;
    if (index >= 9) {
        index = index + index - 9;
        data[0x478 + index] = value;
        data[0x479 + index] = value;
    } else {
        data[0x478 + index] = value;
    }
}

s16 D_80802D80_chinflatableboss[6] = {0x190, 0x1F4, 0x258, 0x2BC, 0x320, 0x384};
s16 D_80802D8C_chinflatableboss[6] = {0x1, 0x1, 0x2, 0x2, 0x3, 0x3};
f32 D_80802D98_chinflatableboss[6] = {3.0f, 2.8f, 2.6f, 2.4f, 2.2f, 2.0f};
u8 D_80802DB0_chinflatableboss[160] = {
    0x0,  0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x10, 0x0,  0x0,  0x2, 0x4, 0x0, 0x44,
    0x41, 0x10, 0x0, 0x0, 0x2, 0x4, 0x0, 0x2, 0x40, 0x90, 0x0,  0x0,  0x2, 0x8, 0x0, 0x1,
    0x40, 0xF0, 0x0, 0x0, 0x2, 0x5, 0x0, 0x2, 0x40, 0x90, 0x0,  0x0,  0x2, 0x2, 0x0, 0x1,
    0x40, 0xA0, 0x0, 0x0, 0x2, 0x3, 0x0, 0x1, 0x40, 0x90, 0x0,  0x0,  0x2, 0x2, 0x0, 0x1,
    0x40, 0xA0, 0x0, 0x0, 0x2, 0x3, 0x0, 0x1, 0x40, 0x90, 0x0,  0x0,  0x2, 0x2, 0x0, 0x1,
    0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x3F, 0xE6, 0x66, 0x66, 0x2, 0x9, 0x0, 0x1,
    0x40, 0x0,  0x0, 0x0, 0x2, 0x6, 0x0, 0x2, 0x40, 0x40, 0x0,  0x0,  0x2, 0x2, 0x0, 0x2,
    0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x40, 0xCC, 0xCC, 0xCD, 0x2, 0xA, 0x0, 0x2,
    0x0,  0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0,
    0x40, 0xF0, 0x0, 0x0, 0x2, 0x5, 0x0, 0x2, 0x40, 0x90, 0x0,  0x0,  0x2, 0x2, 0x0, 0x1};
void *D_80802E50_chinflatableboss = (void *) 0x018E013C;
static u32 D_80802E50_chinflatableboss_rest[17] = {0x7940001,
                                                   (u32) &D_80802DB0_chinflatableboss,
                                                   (u32) func_808004A0_chinflatableboss,
                                                   (u32) func_80105834,
                                                   (u32) func_80801554_chinflatableboss,
                                                   0x0,
                                                   0x0,
                                                   0x0,
                                                   0x3000042A,
                                                   (u32) func_80800408_chinflatableboss,
                                                   (u32) func_80108ED0,
                                                   0x4A00000,
                                                   (u32) func_8080000C_chinflatableboss,
                                                   (u32) func_80107C2C,
                                                   0x80200402,
                                                   (u32) func_80800A98_chinflatableboss,
                                                   0x0};
s32 D_80802E98_chinflatableboss[2] = {0x3D4CCCCD, 0x3E6147AE};
s32 D_80802EA0_chinflatableboss[5] = {0x3EB33333, 0x3EDC28F6, 0x3F0CCCCD, 0x3F23D70A, 0x3F3D70A4};
s32 D_80802EB4_chinflatableboss[4] = {0x3C23D70A, 0x3E19999A, 0x3ECCCCCD, 0x3F333333};
s32 D_80802EC4_chinflatableboss[3] = {0x1304FF, 0x18001D, 0x20000};
s32 D_80802ED0_chinflatableboss[3] = {0x1304FE, 0x18001D, 0x20000};
s32 D_80802EDC_chinflatableboss[3] = {0x1304B1, 0x180002, 0x0};
s32 D_80802EE8_chinflatableboss[8] = {0x1304FD,  0x176D60, 0x7D0001F4, 0x150000,
                                      0x33300A3, 0xE0100,  0x14C0180,  0x20000};
u8 D_80802F08_chinflatableboss[36] = {0x0,  0x13, 0x4,  0xFB, 0x0,  0x18, 0x0,  0x2,  0x0,
                                      0x0,  0x0,  0x0,  0x7,  0x9A, 0x7,  0x98, 0x7,  0x99,
                                      0x7,  0x98, 0x7,  0x97, 0x7,  0x97, 0x7,  0x99, 0x7,
                                      0x97, 0x7,  0x97, 0x7,  0x98, 0x7,  0x99, 0x7,  0x9A};
s32 D_80802F2C_chinflatableboss[15] = {0x1130810,  0x2200C0,   0xD90073,  0x8C0015,  0x99,
                                       0x27FE0C,   -0x1F3FE0C, 0x1F4002D, 0x6A40898, 0x1BFC18,
                                       -0x4AFFFFB, 0x16,       0x204002B, 0x4000500, 0x0};
u8 D_80802F68_chinflatableboss[40] = {0x0,  0x0,  0x0,  0x0,  0x3F, 0x19, 0x99, 0x9A, 0x3E, 0x80,
                                      0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,  0x3F, 0x0,  0x0,  0x0,
                                      0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x40, 0x0,  0x0,  0x3F, 0x80,
                                      0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,  0x3F, 0x19, 0x99, 0x9A};
s32 D_80802F90_chinflatableboss[13] = {0x1130A1C, 0x1D09DD,  0x160200, 0x2D05DC, 0x7080022,
                                       0x2800300, 0x7000880, 0x150000, 0x99002A, 0x0,
                                       0xCC00E6,  0x280500,  0x0};
s32 D_80802FC4_chinflatableboss[13] = {0x113141C, 0x1D09DD,  0x160200, 0x2D04B0, 0x5DC0022,
                                       0x1800200, 0x4000500, 0x150000, 0x99002A, 0x0,
                                       0x660080,  0x28051E,  0x0};
s32 D_80802FF8_chinflatableboss[4] = {0x1304DC, 0x18000D, 0x1190133, 0x20000};
u8 D_80803008_chinflatableboss[24] = {0x0, 0xF, 0x0, 0x13, 0x4, 0xFA, 0x0, 0x18,
                                      0x0, 0x2, 0x0, 0x11, 0x0, 0x0,  0x0, 0x0,
                                      0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
