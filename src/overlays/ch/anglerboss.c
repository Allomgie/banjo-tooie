// Lord Woo Fak Fak, the anglerfish boss of Jolly Roger's Lagoon: a ~29-state machine (intro, swims
// between 5 waypoints, 6 boils, then the eye phase and defeat), plus the glowing lure-light actor.
#include "common.h"

extern int D_80802EB4_changlerboss[];
extern int D_80802EFC_changlerboss[];
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800F608C();
extern void func_80102424();
extern void *func_80100094(Actor *, u32);
extern s32 func_800F4AC0(s32, void *, f32);
extern s32 D_80802DA0_changlerboss[];
extern s32 func_8010D5DC;
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 31;
    u32 local_0 : 1;
} AnglerInitializationFlag1121;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 24;
    u32 local_0 : 2;
    u32 pad_2 : 6;
} AnglerMarkerPairFlags1121;
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_80109FE8();
extern s32 D_80802DAC_changlerboss[];
extern s32 D_80802F70_changlerboss[];
extern s16 D_80802F8C_changlerboss[][3][3];
extern void func_800F18FC();
typedef struct {
    f32 local_0[3];
    u8 pad_0[12];
} AnglerPoint721;
typedef struct {
    u8 pad_0[0x90];
    s16 local_0;
    u8 pad_1[0x12];
    AnglerPoint721 local_1[1];
} AnglerPath721;
extern f32 func_800D8FF8(void);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern s32 func_80102CF4(Actor *, f32);
typedef struct {
    u8 pad_0[0x128];
    s16 local_0;
} AnglerAimState;
typedef struct {
    u8 pad_0[0x1B];
    u8 local_0[6];
} AnglerPiecesState;
typedef struct {
    u8 pad_0[0x9C];
    void *local_0;
    void *local_1;
} AnglerCleanup1358;
extern int _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern s32 func_800D10D4(s32, s32, void *, s32, s32);
extern void func_800FFA88();
extern void func_8010114C();
typedef struct {
    u32 pad : 31;
    u32 flag : 1;
} BitTest31;
extern void _capod_entrypoint_14(void);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
typedef struct {
    u8 pad_0[0x3C];
    f32 local_0[6][3];
    f32 local_1[3];
} AnglerSkeletonState;
extern s16 D_80803054_changlerboss[6];
extern u8 D_80803060_changlerboss[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800EFD24(f32 *);
extern f32 func_80102D78(u8 *, f32 *);
typedef struct {
    u8 pad_0[0x7A];
    u8 pad_1 : 2;
    u8 local_0 : 2;
    u8 local_1 : 3;
    u8 pad_2 : 1;
} AnglerRenderFlags;
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern void func_800F5A00(s32, f32 *);
typedef struct {
    u8 pad_0[0x90];
    s16 local_0;
    s16 pad_1;
    s16 local_1;
    s16 pad_2;
    f32 local_2;
    Unk80132ED0 *local_3;
    u32 pad_3;
    f32 local_4[2][6];
} AnglerData88;
extern s32 D_80802F80_changlerboss[];
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad_0[0x90];
    s16 local_0;
    u8 pad_1[6];
    f32 local_1;
    u8 pad_2[0x93];
    u8 local_2;
} AnglerBossApproach;
typedef struct {
    f32 local_0[3];
    u8 pad_0[0xC];
} AnglerBossWaypoint;
extern f32 func_800F15F8(f32, f32, f32);
typedef struct {
    u8 pad0[0x6E];
    u16 unk6E_9 : 7;
    u16 unk6E_0 : 9;
} AnglerBits;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80802FF8_changlerboss[];
extern s32 func_80102320(Actor *, f32, f32);
extern s32 func_800DC298(f32);
extern void func_800BA22C();
extern void func_800BA568();
extern void func_800BA994();
extern u8 D_80803008_changlerboss[];
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern s32 D_80803098_changlerboss[];
extern void func_800F2F60(s32 *, s32 *, f32);
extern void func_800C8E54(s32, f32, f32);
void func_808015F4_changlerboss();
s32 func_80801C50_changlerboss();
void func_808021E4_changlerboss();
void func_80802210_changlerboss();
void func_808027F8_changlerboss();
void func_808012E0_changlerboss();
void func_8080170C_changlerboss();
s32 func_80801948_changlerboss();
void func_80801E3C_changlerboss();
void func_80801F54_changlerboss();
void func_80802340_changlerboss();
int func_80802430_changlerboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800018_changlerboss(),
    func_808002E0_changlerboss(), func_80800FEC_changlerboss();

// Boss actor: state machine, boil/eye hit counting, projectile spawning, dialogs, HUD, death.
// TU-NOTE: Lord Woo Fak Fak (Jolly Roger's Lagoon boss) and its lure light actor.
int *changlerboss_entrypoint_0()
{
    return &D_80802EB4_changlerboss;
}

// Lure light actor: dynamic light that grows and fades with state, fades out on message 0x2C.
int *changlerboss_entrypoint_1()
{
    return &D_80802EFC_changlerboss;
}

// Boss init: picks the starting state from the retry and defeated flags.
void func_80800018_changlerboss(actor) Actor *actor;
{
    s32 player;
    s32 i;
    u8 *data;

    data = func_80100094(actor, 0);
    ((AnglerInitializationFlag1121 *) actor)->local_0 = 1;
    ((AnglerMarkerPairFlags1121 *) actor)->local_0 = 3;
    func_800EE7F8(data + 0x11C, actor->position);
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x32, data + 0xA4, 1);
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x33, data + 0xBC, 1);
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x34, (data + 0xD4), 1);
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x35, (f32 *) (data + 0xEC), 1);
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x36, (f32 *) (data + 0x104), 1);
    (*(s16 *) ((s8 *) (data) + (0x90))) = 1;
    (*(s32 *) ((s8 *) (data) + (0x9C))) = 0;
    (*(s32 *) ((s8 *) (data) + (0xA0))) = 0;
    (*(s16 *) ((s8 *) (data) + (0x92))) = 0;
    (*(s16 *) ((s8 *) (data) + (0x96))) = 6;
    for (i = 0; i < 6; i++) {
        func_808015F4_changlerboss(actor, i, 1);
    }
    func_80109F08(actor, 0x40);
    player = func_800F54E4();
    if (_glcutDll_entrypoint_20() != 0) {
        func_800EE7F8(actor->position, (f32 *) (data + 0x104));
        func_80102424(actor, 0x1D);
        func_8010A85C(actor, 1);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802DA0_changlerboss);
        return;
    }
    if (func_800DA298(0x377) != 0) {
        func_8010A85C(actor, 1);
        func_8010A590(actor);
        func_808012E0_changlerboss(actor, 0x1A);
        func_800EE7F8(actor->position, (f32 *) (data + 0xEC));
        (*(f32 *) ((s8 *) (actor) + (0x48))) = (f32) (*(f32 *) ((s8 *) (data) + (0xFC)));
        _chintrotext_entrypoint_2(1);
        return;
    }
    func_8010A85C(actor, 2);
    (*(f32 *) ((s8 *) (actor) + (0x58))) = 2.0f;
    if (func_800DA298(0x1AF) != 0) {
        func_800EE7F8(actor->position, (f32 *) (data + 0x104));
        func_808012E0_changlerboss(actor, 4);
        func_800F608C(player, 1);
        func_800F8294(player, (data + 0xD4));
        _subaddiedialog_entrypoint_11((*(s32 *) ((s8 *) (actor) + (0))), 0x1028, 0x106,
                                      actor->position, 0xB4);
        func_808021E4_changlerboss(actor, 0x12, 0x30);
        (*(s8 *) ((s8 *) (data) + (0x12A))) = 1;
        return;
    }
    func_800F608C(player, 1);
    func_800F497C(player);
    func_800F49D4(player, &func_8010D5DC, (*(s32 *) ((s8 *) (actor) + (0))));
    func_800F4AC0(player, (data + 0xD4), 300.0f);
    func_808021E4_changlerboss(actor, 0x22, 0x20);
    _chintrotext_entrypoint_2(1);
}

void func_80802680_changlerboss();

void func_808025EC_changlerboss();

s32 func_808025AC_changlerboss();

void func_808022C4_changlerboss();

s32 func_80801CD8_changlerboss();

// Raises the boss toward its target height.
void func_80801BC8_changlerboss();

s32 func_80801AF0_changlerboss();

void func_80801A10_changlerboss();

// Picks a random boil that is still in state 1 and resets it to 0.
void func_808016A8_changlerboss();

// Boss update: per-state state machine.
void func_808002E0_changlerboss(actor) Actor *actor;
{
    extern u8 D_80802F44_changlerboss[];
    extern u8 D_80802F50_changlerboss[];
    extern u8 D_80802F60_changlerboss[];

    char *data;
    f32 player_pos[3];
    f32 blend;
    s32 anim_done;
    s32 boils_left;
    f32 anim_frac;
    s32 dialog_var;

    data = (char *) func_80100094(actor, 0);

    *(s16 *) (data + 0x128) = func_808025AC_changlerboss(actor);

    if (func_800F6438(*(s16 *) (data + 0x128))) {
        func_800F5A00(*(s16 *) (data + 0x128), player_pos);
    } else {
        func_8010D640(player_pos);

}

func_808025EC_changlerboss(actor);
func_80802680_changlerboss(actor);
func_808022C4_changlerboss(actor);
func_80802340_changlerboss(actor);

if (actor->unk7C_12) {
    if (*(Unk80132ED0 **) (data + 0xA0) != 0) {
        _subaddieskeleton_entrypoint_2(*(s32 *) ((char *) actor + 0), 0xB,
                                       func_80106790(*(Unk80132ED0 **) (data + 0xA0))->position);
    }

}

switch (actor->unk70_10) {
    case 1:
        func_8010A5B0(actor, actor->unk7C_12);

if (func_800D9078((char *) actor + 0x58)) {
    func_80101180(0x46C, 8, 0);
}

if (!func_800DA298(0x6AD)) {
    if (*(u8 *) (data + 0x12E) == 0) {
        *(u8 *) (data + 0x12E) = 1;

        _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x103E, 0x144,
                                      (char *) actor + 4, 0xB4);
    }
}

if (*(u8 *) (data + 0x12C) != 0 && *(u8 *) (data + 0x12D) != 0) {
    func_800F82D4(func_800F54E4(), 0);
    func_808012E0_changlerboss(actor, 2);
}

break;

case 2:
    if (func_80101DDC(actor)) {
        func_808012E0_changlerboss(actor, 3);
    }

break;

case 3:
    anim_done = func_800D9078((char *) actor + 0x58);

    blend = func_800F12D4(*(f32 *) ((char *) actor + 0x58), 0.0f, 4.0f, 1.0f, 0.0f);

    func_800EFE50((char *) actor + 4, data + 0x11C, data + 0x104, blend);

if (anim_done) {
    func_808012E0_changlerboss(actor, 4);

    _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1027, 0x106,
                                  (char *) actor + 4, 0xB4);

    func_808021E4_changlerboss(actor, 0xA, 0x30);
}

break;

case 4:
    func_8010A5B0(actor, actor->unk7C_12);
    break;

case 5:
    func_80801A10_changlerboss(actor);

if (func_800D9078((char *) actor + 0x58)) {
    func_808012E0_changlerboss(actor, 6);
}

break;

case 6:
    func_80801A10_changlerboss(actor);

if (func_80801948_changlerboss(actor)) {
    func_808012E0_changlerboss(actor, 7);
}

break;

case 7:
    func_80801948_changlerboss(actor);

if (func_80801AF0_changlerboss(actor)) {
    func_808012E0_changlerboss(actor, 8);
}

break;

case 8:
    func_80801AF0_changlerboss(actor);

if (func_80101E14(actor, 0.7f)) {
    func_80108B04(actor, 1);
}

if (func_80101E14(actor, 0.999f)) {
    if (--*(s16 *) (data + 0x94) == 0) {
        func_808012E0_changlerboss(actor, 5);
    }
}

break;

case 9:
    if (func_80101DDC(actor)) {
        boils_left = func_80801C50_changlerboss(actor);

        switch (boils_left) {
            case 0:
                func_808012E0_changlerboss(actor, 0xB);
                break;
            case 5:
                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x102A, 0x106,
                                              (char *) actor + 4, 0xB4);

                func_808012E0_changlerboss(actor, 0xA);
                break;
            default:
                func_808016A8_changlerboss(actor);
                func_808012E0_changlerboss(actor, 6);
        }
    }

break;

case 11:
    if (func_800D9078((char *) actor + 0x58)) {
        _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80802F44_changlerboss);

        func_8010A85C(actor, 1);

        ((AnglerRenderFlags *) actor)->local_0 = 1;
        ((AnglerRenderFlags *) actor)->local_1 = 3;

        func_808012E0_changlerboss(actor, 0xC);
    }

break;

case 13:
    if (func_800D9078((char *) actor + 0x58)) {
        func_808012E0_changlerboss(actor, 0xE);
    }

break;

case 14:
    func_80801A10_changlerboss(actor);

if (func_80801948_changlerboss(actor)) {
    func_808012E0_changlerboss(actor, 0xF);
}

break;

case 15:
    func_80801948_changlerboss(actor);

if (func_80801AF0_changlerboss(actor)) {
    func_808012E0_changlerboss(actor, 0x10);
}

break;

case 16:
    anim_frac = func_80101F24(actor);

    _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802F60_changlerboss, 0.4f);

    _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802F50_changlerboss, 0.75f);

if (anim_frac > 0.0f && anim_frac >= 0.4f && anim_frac <= 0.75f) {
    func_80801CD8_changlerboss(actor);
}

func_80801AF0_changlerboss(actor);

if (func_80101DDC(actor)) {
    func_808012E0_changlerboss(actor, 0x12);
    *(s16 *) (data + 0x94) = 2;
}

break;

case 17:
    func_80801AF0_changlerboss(actor);

if (*(s16 *) (data + 0x94) == 0) {
    if (_subaddiefind_entrypoint_2(0x460, 0) == 0) {
        func_808012E0_changlerboss(actor, 0xD);
    }
}

if (func_800D9078((char *) actor + 0x58)) {
    if (*(s16 *) (data + 0x94) > 0) {
        func_808012E0_changlerboss(actor, 0x12);
    }
}

break;

case 18:
    func_80801AF0_changlerboss(actor);

if (func_80101E14(actor, 0.7f)) {
    func_80108B04(actor, 1);
}

if (func_80101DDC(actor)) {
    if (--*(s16 *) (data + 0x94) == 0 && _subaddiefind_entrypoint_2(0x460, 0) == 0) {
        func_808012E0_changlerboss(actor, 0xD);
    } else {
        func_808012E0_changlerboss(actor, 0x11);
    }
}

break;

case 19:
    func_80801AF0_changlerboss(actor);

if (func_80101E14(actor, 0.7f)) {
    func_80108B04(actor, 1);
}

if (func_80101E14(actor, 0.999f)) {
    --*(s16 *) (data + 0x94);
    if (*(s16 *) (data + 0x94) == 0) {
        func_808012E0_changlerboss(actor, 0xD);
    }
}

break;

case 20:
    func_80801AF0_changlerboss(actor);

if (func_800D9078((char *) actor + 0x58)) {
    func_808012E0_changlerboss(actor, 0x15);
}

break;

case 21:
    func_80801AF0_changlerboss(actor);

if (func_80101E14(actor, 0.7f)) {
    func_80108B04(actor, 1);
}

if (func_80101E14(actor, 0.999f)) {
    --*(s16 *) (data + 0x94);
    if (*(s16 *) (data + 0x94) == 0) {
        func_808012E0_changlerboss(actor, 0xD);
    }
}

break;

case 22:
    if (func_80101DDC(actor)) {
        *(u8 *) (data + 0x12F) = 1;

        if (*(s16 *) (data + 0x96) == 5) {
            _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1036, 0x106,
                                          (char *) actor + 4, 0xB4);

            func_808012E0_changlerboss(actor, 0x17);
        } else {
            func_80109FE8(actor, 0);
            func_808012E0_changlerboss(actor, 0x13);
        }
    }

break;

case 24:
    if (func_80101DDC(actor)) {
        func_808012E0_changlerboss(actor, 0x19);
    }

break;

case 25:
    func_80801BC8_changlerboss(actor);
    break;

case 26:
    func_80801BC8_changlerboss(actor);

if (*(u8 *) (data + 0x12B) == 0) {
    if (func_800D90A4((char *) actor + 0x58)) {
        if (func_800EEB40((char *) actor + 4, player_pos) < 1960000.0f) {
            dialog_var = func_800DC128(0, 4);

            _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), dialog_var + 0x1037, 0x144,
                                          (char *) actor + 4, 0xB4);

            func_808012E0_changlerboss(actor, 0x1B);
        }
    }
}

break;

case 29:
    if (func_80101DDC(actor)) {
        func_80102424(actor, 0x1E);
    }

break;

}
}

void func_80802108_changlerboss();

void func_80801D0C_changlerboss();

void func_80801070_changlerboss();

void func_80800F14_changlerboss();

s32 B_808030B0_changlerboss;

// Boss message handler.
s32 func_80800B7C_changlerboss(u8 *actor, s32 message, s32 arg)
{
    u8 *data;
    u8 *slot;
    s32 i;

    data = func_80100094(actor, 0);
    switch (message) {
        case 0x3D:
            switch (arg) {
                case 0:
                    func_80801D0C_changlerboss(actor);
                    break;
                case 1:
                    func_80801E3C_changlerboss(actor);
                    break;
                case 2:
                    func_80801F54_changlerboss(actor);
                    break;
                case 3:
                    func_80802108_changlerboss(actor);
            }

break;
case 0x2E:
    func_8080170C_changlerboss(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
    break;

case 0xB:
    if (arg != 0xE) {
        if (arg == 0x19) {
            func_80101180(0x46C, 7, 0);
            func_808021E4_changlerboss(actor, 0xE, 0x10);
            return 4;
        }
    } else {

data[0x12B] = 0;

if (message) {
}

}
return 3;
case 0x40:
    func_80801070_changlerboss(actor, *(s32 *) &arg);
    break;
case 0xA:
    if (((u32) *(u16 *) (actor + 0x72) >> 10) == 0x11) {
        func_808012E0_changlerboss(actor, 0x13);
    }
    break;
case 0x49:
    if (func_800DA298(0x377) == 0 || _glcutDll_entrypoint_20() != 0) {
        func_80801DA0_changlerboss(actor);
    }
    break;
case 0x32:
    data[0x12C] = 1;
    func_800F82D4(func_800F54E4(), 2);
    break;
case 0x95:
    if (!func_800DA298(0x377)) {
        func_80108B04(actor, 0);
    }
    if (data[0x12A] != 0) {
        func_800FDC28(1);
        data[0x12A] = 0;
    }
    break;
case 0x96:
    if (!func_800D395C()) {
        return 0;
    }
    _subaddiedialog_entrypoint_11(*(s32 *) actor, 0xCEB, 0x146, actor + 4, 0xB4);
    break;
case 0x9F:
    func_800FDC28(0);
    func_808012E0_changlerboss(actor, 0x1C);
    break;
case 0xA2:
    if (!((Actor *) actor)->unk7C_12 || func_800DA298(0x377)) {
        return 0;
    }
    if (*(s16 *) (data + 0x92) == 0) {
        for (i = 0, slot = data; i != 6; i++, slot++) {

if (slot[0x1B] == 0) {
    func_800EE7F8(&B_808030B0_changlerboss, &((Vec3f *) (data + 0x3C))[i]);
    func_80101074(&B_808030B0_changlerboss);
    return 1;
}

}
return 0;
}
func_800EE7F8(&B_808030B0_changlerboss, data + 0x84);
func_80101074(&B_808030B0_changlerboss);
break;
case 0x1F:
    func_80800F14_changlerboss(actor, *(s32 *) &arg);
    break;
default:
    return 0;
    }
    return 1;
    }

    void func_80800F14_changlerboss(Actor *actor, s32 param_1)
    {
        Unk80132ED0 *handle;
        u8 *data;
        s32 value;
        s32 i;
        u8 *marker;

        data = func_80100094(actor, 0);
        value = 0;
        for (i = 1; i < 27; i++) {
            func_800DF744(i, data[i]);
        }
        func_801015D0(actor);
        handle = *(Unk80132ED0 **) (data + 0x9C);
        if (handle != 0) {
            marker = (u8 *) func_80106790(handle);
            if (*(u16 *) (marker + 0x64) & 1)
                value = *(s32 *) (marker + 0x54);
        }
        func_800DF660(4, (value & 0xFFFF) | 0x30000, 0, *((u8 *) actor + 0x9B));
        func_800DF720(func_80100AC4(*(s16 *) ((u8 *) actor + 0x60)));
    }

    void func_80800FEC_changlerboss(actor, param_1) s32 *actor;
    s32 param_1;
    {
        s32 *local_0;
        s32 local_1;
        s32 *local_2;
        local_2 = func_80100094(actor, 0);
        local_0 = (char *) local_2;
        do {
            if ((*((s32 *) (((char *) local_2) + 0xA0))) != 0) {
                func_80101870(func_80106790(*((s32 *) (local_0 + 0x28))), param_1);
            }
            func_801018A4(actor, param_1);
            local_1 = *((s32 *) (((char *) local_0) + 0x9C));
        } while (0);
        if (local_1 != 0) {
            _subaddieskeleton_entrypoint_2(*actor, 0xB, (u8 *) func_80106790(local_1) + 4);
        }
    }

    void func_80801070_changlerboss(Actor *actor, s32 param_1)
    {
        u8 *data;
        u32 hit_id;
        s32 boil_index;

        data = func_80100094(actor, 0);
        hit_id = (actor->unk0->unk18 << 11) >> 28;
        if (func_800DA298(0x377)) {
            if (actor->unk70_10 == 0x1A) {
                _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0, 3) + 0x103B, 0x144,
                                              actor->position, 0xB4);
                func_808012E0_changlerboss(actor, 0x1B);
            }
        } else {
            boil_index = hit_id - 1;
            if (*(s16 *) (data + 0x92) == 0) {
                if (boil_index >= 0 && boil_index < 6 && !(data + 0x1B)[boil_index]) {
                    func_808015F4_changlerboss(actor, boil_index, 2);
                    func_808012E0_changlerboss(actor, 9);
                    ((f32 *) (data + 0x24))[boil_index] = 2.0f;
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     &D_80802DAC_changlerboss);
                    _subaddieaudioquick_entrypoint_2(actor, (data + 0x3C) + boil_index * 0xC,
                                                     &D_80802F70_changlerboss);

if (func_80801C50_changlerboss(actor) == 5) {
    func_80109FE8(actor, 0);
    func_808027F8_changlerboss(actor);
    func_808021E4_changlerboss(actor, 0x1E, 0x30);
}

}
}
else if (hit_id == 8)
{
    (*(s16 *) (data + 0x96))--;
    if (!(*(s16 *) (data + 0x96))) {
        func_80109FE8(actor, 0);
        func_808012E0_changlerboss(actor, 0x18);
        return;
    }
    if ((*(s16 *) (data + 0x96)) == 5) {
        func_80109FE8(actor, 0);
        func_808027F8_changlerboss(actor);
        func_808021E4_changlerboss(actor, 0x1E, 0x30);
        func_808012E0_changlerboss(actor, 0x16);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802DAC_changlerboss);
        return;
    }
    if ((*(s16 *) (data + 0x96)) == 3) {
        func_808012E0_changlerboss(actor, 0x14);
        *(s16 *) (data + 0x94) = 3;
        return;
    }
    func_808012E0_changlerboss(actor, 0x16);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802DAC_changlerboss);
}
}
}

void func_808018E8_changlerboss();

// Enters a new state and runs its entry actions.
void func_808012E0_changlerboss(actor, state) Actor *actor;
s32 state;
{
    AnglerData88 *data;

    data = func_80100094(actor, 0);
    func_80102424(actor, state);
    switch (state) {
        case 2:
            _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802DA0_changlerboss);
            func_800FDC28(1);
            func_808021E4_changlerboss(actor, 0, 48);
            func_80102424(func_80106790(data->local_3), 2);
            return;
        case 3:
            _chintrotext_entrypoint_1(0x18B9, 5, 1, 0);
            actor->unk58 = 4.0f;
            return;
        case 5:
            actor->unk58 = func_800DC178(4.0f, 6.0f);
            return;
        case 6:
        case 14:
            if (func_800EEB40(actor->position, data->local_4[data->local_0]) < 640000.0f) {
                data->local_0 ^= 1;
            }
            func_80109FE8(actor, 1);
            func_808018E8_changlerboss(actor);
            return;
        case 7:
        case 15:
            data->local_0 ^= 1;
            data->local_2 = 0.0f;
            return;
        case 13:
            actor->unk58 = func_800DC178(2.0f, 3.0f);
            return;
        case 8:
            if (func_80801C50_changlerboss(actor) < 4) {
                data->local_1 = 2;
                return;
            }
            data->local_1 = 1;
            return;
        case 11:
            actor->unk58 = 2.0f;
            func_808027F8_changlerboss(actor);
            func_808021E4_changlerboss(actor, 28, 48);
            func_800D2770(0xFE, 0);
            return;
        case 12:
            _subaddiedialog_entrypoint_11(actor->unk0, 0x102B, 0x106, actor->position, 0xB4);
            return;
        case 17:
            actor->unk58 = 2.0f;
            return;
        case 19:
            data->local_1 = 1;
            return;
        case 22:
            func_80109FE8(actor, 0);
            return;
        case 20:
            actor->unk58 = func_800DC178(1.5f, 2.5f);
            return;
        case 24:
            func_800FDC28(0);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802F80_changlerboss);
            func_808027F8_changlerboss(actor);
            func_808021E4_changlerboss(actor, 22, 56);
            return;
        case 25:
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1029, 0x106, actor->position, 0xB4);
            return;
        case 26:
            func_80109FE8(actor, 1);
            actor->unk58 = func_800DC178(5.0f, 8.0f);
            return;
        case 27:
        case 28:
            func_80109FE8(actor, 0);
    }
}

// Sets the state of one boil and updates its dependent flags.
void func_808015F4_changlerboss(actor, boil, state) s32 actor;
s32 boil;
s32 state;
{
    u8 *data;
    s32 j;
    s32 k;
    s32 flag;
    s32 val;

    data = func_80100094(actor, 0);
    data[boil + 0x1B] = state;
    for (j = 0; j != 3; j++) {
        k = 0;
        if (j == state) {
            flag = 1;
        } else {
            flag = 0;
        }
        for (; D_80802F8C_changlerboss[boil][j][k] != -1; k++) {
            val = D_80802F8C_changlerboss[boil][j][k];
            data[val] = flag;
        }
    }
}

void func_808016A8_changlerboss(s32 actor)
{
    s32 index;
    s32 data;
    index = func_80100094(actor, 0);
    data = index;
    while (1) {
        index = func_800DC128(0, 6);
        if (*(u8 *) ((char *) (data + index) + 0x1B) == 1) {
            break;
        }
    }

    func_808015F4_changlerboss(actor, index, 0);
}

void func_80802288_changlerboss();

void func_8080170C_changlerboss(actor, dialog_id, choice) Actor *actor;
s32 dialog_id;
s32 choice;
{
    u8 *data;

    data = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x1027:
        case 0x1028:
            func_800FDC28(5);
            func_80802288_changlerboss(actor);
            _plcamera_entrypoint_8(func_800F54E4());
            func_800DA544(0x1AF);
            _gcfrontend_entrypoint_9(0x26);
            func_808016A8_changlerboss(actor);
            func_808012E0_changlerboss(actor, 6);
            return;
        case 0x1029:
            func_808012E0_changlerboss(actor, 0x1A);
            if (func_800D395C()) {
                func_80802288_changlerboss(actor);
                _gcfrontend_entrypoint_10();
                return;
            }
            func_80108B04(actor, 3);
            func_800DA544(0x377);
            return;
        case 0x102B:
            func_80802288_changlerboss(actor);
            *(s16 *) (data + 0x92) = 1;
            func_808012E0_changlerboss(actor, 14);
            return;
        case 0x102A:
            func_80802288_changlerboss(actor);
            func_808016A8_changlerboss(actor);
            func_808012E0_changlerboss(actor, 6);
            func_80109FE8(actor, 1);
            return;
        case 0x1036:
            func_80802288_changlerboss(actor);
            func_808012E0_changlerboss(actor, 19);
            func_80109FE8(actor, 1);
            return;
        case 0x1037:
        case 0x1038:
        case 0x1039:
        case 0x103A:
        case 0x103B:
        case 0x103C:
        case 0x103D:
            func_808012E0_changlerboss(actor, 26);
            return;
        case 0x103E:
            data[0x12D] = 1;
            return;
        case 0xCEB:
            if (choice > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
    }
}

void func_808018E8_changlerboss(u8 *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    (*(f32 *) ((s8 *) (actor) + (0x24))) = 10.0f;
    if ((*(u8 *) ((s8 *) (data) + (0x12F))) != 0) {
        (*(f32 *) ((s8 *) (data) + (0x98))) = 900.0f;
        return;
    }
    (*(f32 *) ((s8 *) (data) + (0x98))) = 400.0f;
}

s32 func_80801948_changlerboss(actor)
Actor *actor;
{
    AnglerBossApproach *approach;

    approach = func_80100094(actor, 0);
    *(f32 *) &actor->actorData[3] =
        func_800F15F8(*(f32 *) &actor->actorData[3], approach->local_1, func_800D8FF8() * 600.0f);
    func_8010B990(actor, 6);
    if (func_800EEB40(actor->position,
                      ((AnglerBossWaypoint *) ((u8 *) approach + 0xA4))[approach->local_0].local_0) <
        160000.0f) {
        if (approach->local_2) {
            approach->local_2 = 0;
            approach->local_1 = 400.0f;
        }
        return 1;
    }
    return 0;
}

void func_80801A10_changlerboss(Actor *actor)
{
    AnglerPath721 *path;
    f32 angles[2];
    f32 dt;

    path = (AnglerPath721 *) func_80100094(actor, 0);
    dt = func_800D8FF8();
    func_800F18FC(actor->position, path->local_1[path->local_0].local_0, angles);
    actor->unk50 = angles[0];
    actor->unk54 = angles[1];
    actor->rotation[1] = func_800F1FF0(actor->rotation[1], actor->unk54, 0.1f,
                                         dt + dt, dt * 60.0f);
    actor->rotation[0] = func_800F1FF0(actor->rotation[0], actor->unk50, 0.1f,
                                         dt + dt, dt * 60.0f);
    func_80102CF4(actor, 8.0f);
}

s32 func_80801AF0_changlerboss(Actor *actor)
{
    AnglerAimState *aim;
    f32 angles[2];
    f32 dt;
    f32 target_pos[3];
    aim = func_80100094(actor, 0);
    dt = func_800D8FF8();
    func_800F5A00(aim->local_0, target_pos);
    func_800F18FC(actor->position, target_pos, angles);
    actor->unk50 = angles[0];
    actor->unk54 = angles[1];
    actor->rotation[1] = func_800F1FF0(actor->rotation[1], actor->unk54, 0.1f,
                                         dt + dt, dt * 60.0f);
    actor->rotation[0] = func_800F1FF0(actor->rotation[0], actor->unk50, 0.1f,
                                         dt + dt, dt * 60.0f);
    return func_80102CF4(actor, 8.0f);
}

void func_80801BC8_changlerboss(Actor *actor)
{
    f32 *data;
    data = func_80100094(actor, 0);
    if (actor->position[1] < data[0x3C]) {
        actor->position[1] += func_800D8FF8() * 120.0f;
        if (actor->position[1] > data[0x3C])
            actor->position[1] = data[0x3C];
    }
}

// Counts boils that are not yet popped (state != 2).
s32 func_80801C50_changlerboss(actor)
Actor *actor;
{
    AnglerPiecesState *pieces;
    s32 count;
    s32 i;
    pieces = func_80100094(actor, 0);
    count = 0;
    for (i = 0; i < 6; i++) {
        if (pieces->local_0[i] != 2)
            count++;
    }
    return count;
}

s32 func_80801CD8_changlerboss(s32 actor)
{
    if (func_8001210C(3) == 0) {
        func_80108B04(actor, 2);
    }
}

void func_80801D0C_changlerboss(s32 *actor)
{
    u8 *data;
    u8 *light;

    data = func_80100094(actor, 0);
    light = func_801084B0(0x298, &actor);
    (*(s32 *) ((s8 *) (light) + (0x3C))) = (s32) *actor;
    (*(s32 *) ((s8 *) (data) + (0xA0))) = (s32) (*(s32 *) ((s8 *) (light) + (0)));
    _subaddieDll_entrypoint_0(light);
    func_8010A800(light, 2);
    func_8010A570(light);
    (*(u8 *) ((s8 *) (light) + (0x65))) = (u8) ((*(u8 *) ((s8 *) (light) + (0x65))) & 0xFFFE);
    _subaddieskeleton_entrypoint_2(*actor, 0xB, light + 4);
}

int func_80801DA0_changlerboss(Actor *actor)
{
    Actor *data;
    Actor *light;
    data = func_80100094(actor, 0);
    light = func_801084B0(0x45E, &actor);
    func_80102FDC(light, *(f32 *) ((char *) actor + 0x38));
    *(s32 *) ((char *) light + 0x3C) = (s32) *(s32 *) ((char *) actor + 0x0);
    *(s32 *) ((char *) data + 0x9C) = (s32) *(s32 *) ((char *) light + 0x0);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(light, 2);
    } else if (func_800DA298(0x1AF) != 0) {
        func_80102424(light, 3);
    }
    return actor;
}

void func_80801E3C_changlerboss(actor) Actor *actor;
{
    f32 target_pos[3];
    f32 mouth_pos[3];
    s32 pad;
    u8 *data;
    Actor *flare;
    f32 speed;

    func_800F5A00(*(s16 *) ((u8 *) func_80100094(actor, 0) + 0x128), target_pos);
    if (_subaddieskeleton_entrypoint_2(actor->unk0, 0xB, mouth_pos)) {
        data = func_80100094(actor, 0);
        flare = func_80108528(0x45F, mouth_pos, 0, &actor);
        func_800EFB24((f32 *) ((u8 *) flare + 0x28), target_pos, flare->position);
        ((AnglerBits *) flare)->unk6E_0 = *(s16 *) (data + 0x128);
        if (*(s16 *) (data + 0x92) == 0) {
            speed = 1000.0f;
        } else {
            speed = func_800F10B4(*(s16 *) (data + 0x96), 1.0f, 3.0f, 2000.0f, 1500.0f);
            flare->unk64_20 = 1;
        }
        func_800EF368((f32 *) ((u8 *) flare + 0x28), speed);
        *(void **) ((u8 *) flare + 0x3C) = actor->unk0;
    }
}

// Spawns three bubbles (0x460) around bone 10.
void func_80801F54_changlerboss(actor) Actor *actor;
{
    f32 spawn_pos[3];
    f32 bone_pos[3];
    s32 i;
    Actor *bubble;
    _subaddieskeleton_entrypoint_2(actor->unk0, 10, bone_pos);
    for (i = 0; i < 3; i++) {
        func_800EE7F8(spawn_pos, bone_pos);
        func_800EF214(spawn_pos, actor->rotation[0] + (func_800DC178(-10.0f, 10.0f)),
                      actor->rotation[1] + (func_800DC178(-10.0f, 10.0f)),
                      func_800DC178(200.0f, 300.0f));
        bubble = (Actor *) func_80108528(0x460, spawn_pos, 0, &actor);
        if (bubble) {
            func_800EFB24((f32 *) &bubble->actorData[4], bubble->position, bone_pos);
            func_800EF368((f32 *) &bubble->actorData[4], func_800DC178(1000.0f, 1400.0f));
            bubble->unk3C = actor->unk0;
            func_80102FDC(bubble, func_800DC178(0.8f, 1.2f));
        }
    }
}

void func_80802108_changlerboss(Actor *actor)
{
    AnglerCleanup1358 *state;
    s32 spawned_ref;
    Unk80132ED0 *boss_ref;
    f32 bone_pos[3];
    f32 *pos_ptr;
    Actor *spawned;

    state = func_80100094(actor, 0);
    boss_ref = actor->unk0;
    pos_ptr = NULL;
    func_800FFA88(state->local_1);
    state->local_1 = NULL;
    func_8010114C(state->local_0, 0x2C, 0);
    state->local_0 = NULL;
    if (_subaddieskeleton_entrypoint_2(actor->unk0, 11, bone_pos)) {
        pos_ptr = bone_pos;
    }
    spawned_ref = func_800D10D4(0x25, 1, pos_ptr, 0, 0);
    actor = func_80106790(boss_ref);
    if (spawned_ref) {
        spawned = func_80106790((Unk80132ED0 *) spawned_ref);
        ((BitTest31 *) ((u8 *) spawned + 0x70))->flag = 1;
        func_80802210_changlerboss(actor, (Unk80132ED0 *) spawned_ref, 25, 0x438);
    }
}

void func_808021E4_changlerboss(actor, unk_1, flags) s32 *actor;
s32 unk_1;
s32 flags;
{
    func_80802210_changlerboss(actor, *actor, unk_1, flags);
}

void func_80802210_changlerboss(actor, target, unk_2, flags) Actor *actor;
Unk80132ED0 *target;
u32 unk_2;
u32 flags;
{
    u8 *state;

    state = func_80100094(actor, 0);
    if (state[0x12B]) {
        _capod_entrypoint_14();
        flags |= 0x2000;
    }
    _capod_entrypoint_13(target, actor->unk0, unk_2, flags);
    state[0x12B] = 1;
}

void func_80802288_changlerboss(s32 actor)
{
    u8 *state;

    state = func_80100094(actor, 0);
    if (state[0x12B] != 0) {
        _capod_entrypoint_14();
        state[0x12B] = 0;
    }
}

void func_808022C4_changlerboss(Actor *actor)
{
    s32 state_id;
    s32 count;
    u8 *data;
    state_id = actor->unk70_10;
    if (state_id != 0xB && state_id != 0xC && state_id >= 5 && state_id < 0x19) {
        data = func_80100094(actor, 0);
        if (*(s16 *) (data + 0x92) == 0) {
            count = func_80801C50_changlerboss(actor);
        } else {
            count = *(s16 *) (data + 0x96);
        }
        func_800D2498(0xFE, count, 0);
    }
}

void func_80802340_changlerboss(actor) Actor *actor;
{
    switch (func_801022E4(actor)) {
        case 0x3EC:
            if (func_80102320(actor, 0.25f, 0.8f) && func_800DC298(0.15f)) {
                func_80802430_changlerboss(actor);
            }
            break;
        case 0x330:
            if (func_80102320(actor, 0.25f, 0.75f) && func_800DC298(0.1f)) {
                func_80802430_changlerboss(actor);
            }
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80802FF8_changlerboss,
                                             0.4f);
            break;
        case 0x33F:
            if (func_80101E14(actor, 0.85f)) {
                func_80802430_changlerboss(actor);
            }
    }
}

int func_80802430_changlerboss(actor)
Actor *actor;
{
    f32 bone_pos[3];
    s32 particle_id;
    s32 emitter;
    f32 scale;
    if (actor->unk7C_12) {
        _subaddieskeleton_entrypoint_2(actor->unk0, 10, bone_pos);
        particle_id = func_800DC128(1, 3);
        emitter = func_800B53A4(particle_id);
        scale = actor->scale * 1.3f;
        func_800BABB8(emitter, bone_pos, NULL, 1.0f, &D_80803008_changlerboss);
        func_800BA568(emitter, (s16) (s32) (bone_pos[1] + 1000.0f));
        func_800BA7C4(emitter, 0.16f * scale, 0.3f * scale);
        func_800BA7FC(emitter, 0.45f * scale, 0.6f * scale);
        func_800BA994(emitter, -75, (s16) (s32) (actor->rotation[1] - 75.0f), 800, -35,
                      (s32) (actor->rotation[1] + 75.0f), 1000);
        func_800BA22C(emitter, particle_id);
    }
}

s32 func_808025AC_changlerboss(s32 unk_0)
{
    s32 found;
    s32 result;
    found = func_8010D290(0x400);
    result = found;
    if (result == (-1)) {
        result = func_800F54E4();
    }
    return result;
}

void func_808025EC_changlerboss(Actor *actor)
{
    s32 i;
    AnglerSkeletonState *state;
    state = func_80100094(actor, 0);
    for (i = 0; i < 6; i++) {
        _subaddieskeleton_entrypoint_2(actor->unk0, D_80803054_changlerboss[i],
                                       state->local_0[i]);
    }
    _subaddieskeleton_entrypoint_2(actor->unk0, 0xC, state->local_1);
}

void func_80802680_changlerboss(Actor *actor)
{
    f32 spawn_pos[3];
    f32 dt;
    f32 scale;
    u8 *state;
    u8 *slot;
    f32 *boil_pos;
    s32 emitter;
    s32 i;
    dt = func_800D8FF8();
    state = func_80100094(actor, 0);
    func_80103DFC(actor, spawn_pos);
    spawn_pos[1] -= 600.0f;
    for (i = 0, slot = state; i < 6; i++, slot += 4) {
        boil_pos = (f32 *) state;
        boil_pos = (f32 *) ((u8 *) boil_pos + i * 12 + 0x3C);
        if (*(f32 *) (slot + 0x24) > 0.0f) {
            // Matching: empty blocks steer IDO.
            if (1) {
            }
            // Matching: empty blocks steer IDO.
            if (1) {
            }
            scale = func_800F10B4(*(f32 *) (slot + 0x24), 0.0f, 2.0f, 0.75f, 1.0f);
            *(f32 *) (slot + 0x24) -= dt;
            emitter = func_800B53A4(1);
            func_800BABB8(emitter, boil_pos, spawn_pos, scale, &D_80803060_changlerboss);
            func_800BA22C(emitter, 1);
        }
    }
}

void func_808027F8_changlerboss(actor) u8 *actor;
{
    f32 vec[3];
    f32 value;
    func_800EFD24(vec);
    value = func_80102D78(actor, vec);
    *(f32 *) (actor + 0x54) = value;
    *(f32 *) (actor + 0x48) = value;
    *(f32 *) (actor + 0x50) = 0.0f;
    *(f32 *) (actor + 0x44) = 0.0f;
}

void func_80802844_changlerboss(Actor *actor)
{
    *((f32 *) (((char *) actor) + 0x58)) = 0.4f;
    *((u8 *) (((char *) actor) + 0x7A)) =
        ((*((u8 *) (((char *) actor) + 0x7A))) & 0xFF3F) | 0x80;
    *((s32 *) (((char *) actor) + 0x54)) = func_800C8A98();
}

void func_80802888_changlerboss(Actor *actor)
{
    s32 color[3];
    f32 scale;
    s32 faded_color[3];
    s32 done;
    f32 fade;
    f32 faded_scale;
    f32 unk_0;

    switch (actor->unk70_10) {
        case 1:
            scale = actor->scale * 0.3f;
            actor->unk64_16 = 0;
            func_800F2F60(color, D_80803098_changlerboss, 0.3f);
            func_800C8E54(*(s32 *) &actor->unk54, scale * 400.0f, scale * 1000.0f);
            func_800C8E84(*(s32 *) &actor->unk54, color);
            break;
        case 2:
            done = func_800D9078(&actor->unk58);
            fade = func_800F12D4(actor->unk58, 0.0f, 0.4f, 1.0f, 0.3f);
            faded_scale = actor->scale * fade;
            actor->unk64_16 = 1;
            func_800F2F60(faded_color, D_80803098_changlerboss, fade);
            func_800C8E54(*(s32 *) &actor->unk54, faded_scale * 400.0f, faded_scale * 1000.0f);
            func_800C8E84(*(s32 *) &actor->unk54, faded_color);
            _subaddiefade_entrypoint_1(actor, (s32) (fade * 255.0f));
            if (done) {
                func_80101FDC(actor, 3);
            }
            break;
        case 3:
            scale = actor->scale;
            actor->unk64_16 = 1;
            func_800C8E54(*(s32 *) &actor->unk54, scale * 400.0f, scale * 1000.0f);
            func_800C8E84(*(s32 *) &actor->unk54, D_80803098_changlerboss);
    }
    if (*(s32 *) &actor->unk54) {
        func_800C8CB8(*(s32 *) &actor->unk54, actor->position);
    }
}

// Message 0x2C: fade the lure light out.
s32 func_80802A90_changlerboss(u8 *actor, s32 msg, s32 param_2)
{
    s32 light;

    if (msg == 0x2C) {
        light = (*(s32 *) ((s8 *) (actor) + (0x54)));
        if (light != 0) {
            (*(s32 *) ((s8 *) (actor) + (0x54))) =
                _chlightfader_entrypoint_1(light, 0x3F800000, 3, actor);
        }
        _subaddiefade_entrypoint_3(actor);
        func_80101FDC(actor, 4);
    } else {
        return 0;
    }
    return 1;
}

extern int func_80101870();
s32 D_80802DA0_changlerboss[3] = {0x1305E2, 0x180002, 0x0};
s32 D_80802DAC_changlerboss[4] = {0x1305E2, 0x18000D, 0xCC00E6, 0x20000};
u8 D_80802DBC_changlerboss[248] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x40, 0x2C, 0xCC, 0xCD, 0x3, 0xEB, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0xEC, 0x0, 0x2,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x3E, 0x0, 0x1,  0x3F, 0xC0, 0x0,  0x0,  0x3, 0x3F, 0x0, 0x2,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x3E, 0x0, 0x2,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x3E, 0x0, 0x42, 0x40, 0x0,  0x0,  0x0,  0x3, 0x3E, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x3E, 0x0, 0x1,
    0x3F, 0xC0, 0x0,  0x0,  0x3, 0x3F, 0x0, 0x2,  0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,
    0x41, 0x13, 0x33, 0x33, 0x3, 0x40, 0x0, 0x2,  0x40, 0x0,  0x0,  0x0,  0x3, 0x41, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x41, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x41, 0x0, 0x1,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0xEC, 0x0, 0x2,
    0x40, 0x0,  0x0,  0x0,  0x3, 0x30, 0x0, 0x1};
int D_80802EB4_changlerboss[18] = {0x2045D,
                                   0x7F90001,
                                   (u32) &D_80802DBC_changlerboss,
                                   (u32) func_808002E0_changlerboss,
                                   (u32) func_80105834,
                                   (u32) func_80800FEC_changlerboss,
                                   0x752F,
                                   0x0,
                                   0x0,
                                   0x468,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x1300000,
                                   (u32) func_80800018_changlerboss,
                                   (u32) func_80107C2C,
                                   -0x7F1EFBFE,
                                   (u32) func_80800B7C_changlerboss,
                                   0x0};
int D_80802EFC_changlerboss[18] = {0x158045E,
                                   0x7FB0001,
                                   0x0,
                                   (u32) func_80802888_changlerboss,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x21404,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80802844_changlerboss,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   (u32) func_80802A90_changlerboss,
                                   0x0};
u8 D_80802F44_changlerboss[12] = {0x0, 0x13, 0x6, 0x92, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80802F50_changlerboss[16] = {0x0, 0x13, 0x5, 0xE3, 0x0, 0x18, 0x0, 0x2,
                                  0x0, 0xD,  0x1, 0x40, 0x1, 0x59, 0x0, 0x0};
u8 D_80802F60_changlerboss[16] = {0x0, 0x13, 0x5, 0xE4, 0x0, 0x18, 0x0, 0x2,
                                  0x0, 0xD,  0x1, 0x40, 0x1, 0x59, 0x0, 0x0};
s32 D_80802F70_changlerboss[4] = {0x13060F, 0xD00C0, 0xD90018, 0x20000};
s32 D_80802F80_changlerboss[3] = {0x1305E1, 0x180002, 0x0};
s16 D_80802F8C_changlerboss[6][3][3] = {
    0x3,  0x6,  -0x1, 0x4,  0x7,  -0x1, 0x5,  0x8,  -0x1, 0x9,  -0x1, 0x0,  0xA,  -0x1,
    0x0,  0xB,  -0x1, 0x0,  0xC,  0xF,  -0x1, 0xD,  0x10, -0x1, 0xE,  0x11, -0x1, 0x12,
    -0x1, 0x0,  0x13, -0x1, 0x0,  0x14, -0x1, 0x0,  0x15, -0x1, 0x0,  0x16, -0x1, 0x0,
    0x17, -0x1, 0x0,  0x18, -0x1, 0x0,  0x19, -0x1, 0x0,  0x1A, -0x1, 0x0};
u8 D_80802FF8_changlerboss[16] = {0x0, 0x13, 0x3, 0xFD, 0x0, 0xD, 0x0, 0xA6,
                                  0x0, 0xC0, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
u8 D_80803008_changlerboss[76] = {
    0x0, 0x1D, 0x9, 0xD9, 0x0,  0x16, 0x12, 0x0,  0x0, 0x1,  0x0, 0x0,  0x0, 0x23, 0x0, 0x0,
    0x0, 0x0,  0x0, 0x32, 0x0,  0x0,  0x0,  0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0, 0x7,  0x0, 0x1,
    0x0, 0x15, 0x0, 0x0,  0x0,  0xCC, 0x0,  0xE,  0x0, 0x32, 0x0, 0x3C, 0x0, 0x2B, 0x1, 0x80,
    0x4, 0x80, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40, 0x0, 0x0,
    0x0, 0x0,  0x0, 0x19, 0x0,  0x0,  0x0,  0x33, 0x0, 0x0,  0x0, 0x0};
s16 D_80803054_changlerboss[6] = {0x4, 0x5, 0x6, 0x7, 0x8, 0x9};
u8 D_80803060_changlerboss[56] = {0x0, 0x1D, 0x9, 0xD3, 0x0,  0x22, 0x0, 0xCC, 0x1, 0x0,  0x0, 0x19,
                                  0x0, 0x26, 0x0, 0x16, 0x22, 0x0,  0x0, 0x2D, 0x3, 0x20, 0x3, 0xE8,
                                  0x0, 0x15, 0x0, 0x0,  0x0,  0xC0, 0x0, 0xE,  0x0, 0x14, 0x0, 0x50,
                                  0x0, 0x2B, 0x1, 0x40, 0x1,  0xC0, 0x0, 0x30, 0x0, 0xF0, 0x0, 0x1B,
                                  0x0, 0x96, 0x0, 0xC8, 0x0,  0x0,  0x0, 0x0};
s32 D_80803098_changlerboss[6] = {0xFF, 0xFF, 0x60, 0x0, 0x0, 0x0};
