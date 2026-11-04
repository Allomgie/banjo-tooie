#include "common.h"

extern void func_8010D5DC(Unk80132ED0 *);
extern u8 D_808016C0_chcaptainblubber[];
extern void func_8008F990(void *, f32);
typedef struct {
    u16 local_0;
    u8 pad_0[6];
} BlubberStateRecord;
extern BlubberStateRecord D_80801654_chcaptainblubber[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern int D_8080176C_chcaptainblubber[];
typedef struct {
    u8 pad_0[0x79];
    u8 mode : 4;
    u8 pad_1 : 4;
} BlubberFlags30;
extern u8 D_808016CC_chcaptainblubber[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void *_gccubesearch_entrypoint_1(s32, f32 *);
typedef struct {
    u8 pad0[0x70];
    u32 pad70 : 28;
    u32 bit3 : 1;
    u32 pad70b : 3;
} BlubberFlags70;
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80105998(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
extern void func_8010C93C(Actor *, f32 *, f32);
extern s32 D_808016D8_chcaptainblubber[];
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern s32 _capod_entrypoint_17(f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 func_800D1A04(s32);
typedef struct {
    f32 times[3];
} BlubberTimes3;
typedef struct {
    f32 times[4];
} BlubberTimes4;
typedef struct {
    f32 times[7];
} BlubberTimes7;
extern s32 func_80101E4C(Actor *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC128(s32, s32);
extern void func_800C4140(s32, f32 *, s32);
extern void func_800C3F48(s32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
void func_80800A1C_chcaptainblubber();

void func_80800000_chcaptainblubber(Actor *actor)
{
    if (!actor->unk64_20) {
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(func_8010D5DC, actor->unk0);
        func_8008F938(1);
        func_8008F990(D_808016C0_chcaptainblubber, 500.0f);
        actor->unk64_20 = 1;
    }
}

// Hands the item over to the player.
s32 func_80800078_chcaptainblubber(Actor *this)
{
    s32 item = func_801000D8(this, 0, 0x14);
    _subaddieitem_entrypoint_0(item, 0x4E4, 0x3E8, 3);
    _subaddieitem_entrypoint_2(item);
    func_80102424(this, 5);
}

void func_808000CC_chcaptainblubber(Actor *actor)
{
    void *prop;
    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(actor->position, (f32 *) D_808016CC_chcaptainblubber);
        func_80102424(actor, 11);
        return;
    }
    prop = _gccubesearch_entrypoint_1(0x299, actor->position);
    if (!prop) {
        func_800FFA88(actor->unk0);
        return;
    }
    _gspropctrl_entrypoint_11(prop, actor->actorData);
    *(f32 *) ((u8 *) actor + 0x54) = _gspropctrl_entrypoint_12(prop);
    ((BlubberFlags30 *) actor)->mode = 0;
    if (func_800EEAD4(actor->position, (f32 *) actor->actorData) > 1000000.0f) {
        func_800FFA88(actor->unk0);
        return;
    }
    *(f32 *) ((u8 *) actor + 0x34) = 0.0f;
    actor->position[0] += 175.0f;
    actor->position[2] += -33.0f;
    if (func_800DA298(0xE0))
        func_80108B04(actor, 1);
}

void func_8080143C_chcaptainblubber();

void func_808001F0_chcaptainblubber(Actor *actor)
{
    f32 bone_pos[3];
    char *expression;
    s32 unk_0;

    func_8010C93C(actor, actor->position, 0.75f);

    if (((BlubberFlags70 *) actor)->bit3) {
        expression = (char *) func_80100094(actor, 1);
        _suexpression_entrypoint_10(expression, *(s32 *) ((char *) actor + 0), 0);
    }

    func_800D1824(0x4E);

    switch (actor->unk70_10) {
        case 1:
        case 2:
            unk_0 = func_800F54E4();

            if (func_800F64A4(unk_0, 0x201)) {
                if (func_800DA298(0xDF)) {
                    if (_subaddiedialog_entrypoint_6(actor->position,
                                                     (s32) *(f32 *) ((char *) actor + 0x48),
                                                     0x12C, 0x3C, 0)) {
                        func_80800000_chcaptainblubber(actor);
                    }
                } else {
                    if (_subaddiedialog_entrypoint_3(actor->position,
                                                     (s32) *(f32 *) ((char *) actor + 0x48),
                                                     0x12C, 0x3C, 0)) {
                        func_80800000_chcaptainblubber(actor);
                    }
                }
            } else {
                if (_subaddiedialog_entrypoint_6(actor->position,
                                                 (s32) *(f32 *) ((char *) actor + 0x48), 0x12C,
                                                 0x3C, 0)) {
                    _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1208, 0xE,
                                                  actor->position, 0x64);
                }
            }
            break;

        case 5:
            expression = (char *) func_80100094(actor, 0);

            _subaddieskeleton_entrypoint_0(actor, 0x1E, bone_pos);

            if (_subaddieitem_entrypoint_3(actor, bone_pos, expression)) {
                func_80102424(actor, 6);
                func_80100074(actor, 0, 0);

                unk_0 = func_800F54E4();
                func_800F82D4(unk_0, 1);
            }
            break;

        case 6:
            if (func_80101DDC(actor)) {
                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x100B, 0xE,
                                              actor->position, 0x64);

                *(u8 *) ((char *) actor + 0x65) &= ~8;

                func_80102424(actor, 7);

                *(f32 *) ((char *) actor + 4) -= 175.0f;
                *(f32 *) ((char *) actor + 0xC) -= -33.0f;
            }
            break;

        case 7:
            if (func_80101E14(actor, 0.999f)) {
                if (actor->unk64_19) {
                    unk_0 = func_800F54E4();
                    func_800F82D4(unk_0, 0);

                    func_80102424(actor, 8);
                    func_80105A9C(actor, 500.0f);
                }
            }
            break;

        case 8:
            func_80105834(actor);
            func_800A54C0(actor->position);

            if (func_80105998(actor, 0.84f)) {
                func_80102424(actor, 9);
            }
            break;

        case 9:
            func_800A54C0(actor->position);

            if (func_80101DDC(actor)) {
                func_80102424(actor, 0xA);
            }
            break;

        case 10:
            func_80105834(actor);

            if (func_80105A5C(actor)) {
                _capod_entrypoint_22();
                func_800FFA88(*(s32 *) ((char *) actor + 0));
            }
            break;

        case 12:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 0xD);
            }
            break;

        case 13:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 0xC);
            }
    }

    func_80800A1C_chcaptainblubber(actor);
    func_8080143C_chcaptainblubber(actor);
}

s32 func_80800580_chcaptainblubber(Actor *actor, s32 event, s32 arg)
{
    Actor *spawned;
    s32 dialog_id;
    s32 dialog_arg;

    switch (event) {
        case 0x95:
            _suexpression_entrypoint_7(actor, 1, 0x64);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 30.0f, 15.0f);
            return 1;
        case 0x2E:
            switch (((s16 *) &arg)[0]) {
                case 0x1006:
                case 0x1007:
                case 0x106B:
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1008, 0x4E, actor->position,
                                                  0x64);
                    func_80102424(actor, 2);
                    return 1;
                case 0x1008:
                    if (((s16 *) &arg)[1] > 0) {
                        if (func_800D1A04(0x4E) <= 0) {
                            _subaddiedialog_entrypoint_11(actor->unk0, 0x100A, 0xE,
                                                          actor->position, 0x64);
                            return 1;
                        }
                        func_80800078_chcaptainblubber(actor);
                        return 1;
                    }
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1009, 0xE, actor->position,
                                                  0x64);
                    return 1;
                case 0x1009:
                case 0x100A:
                    func_80102424(actor, 2);
                    return 1;
                case 0x100B:
                    // Unlocks the reward flag 0xE0.
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x103F, 0x4E, actor->position,
                                                  0x64);
                    func_800DA544(0xE0);
                    func_800D175C(0x4E, -1);
                    return 1;
                case 0x103F:
                    return 1;
            }
            return 0;
        case 0x30:
            if (((s16 *) &arg)[0] == 0x1006 || ((s16 *) &arg)[0] == 0x1007 ||
                ((s16 *) &arg)[0] == 0x1008 || ((s16 *) &arg)[0] == 0x106B) {
                return 1;
            }
            return 0;
        case 0xE:
            if (_capod_entrypoint_17(0.3f)) {
                func_80108B04(actor, 0);
            }
            return 3;
        case 0xB:
            _capod_entrypoint_14();
            if (func_800C064C()) {
                func_800C01A8(0x6B, 0);
                _capod_entrypoint_21(actor->unk0, actor->unk0, 4, 0x2011);
            }
            return 4;
        case 0x2F:
            switch (((s16 *) &arg)[0]) {
                case 0x100B:
                    func_800C01A8(0x6B, 0);
                    _capod_entrypoint_13(actor->unk0, actor->unk0, 0, 0x6010);
                    func_800FC6B0(0xE);
                    break;
                case 0x103F:
                    actor->unk64_19 = 1;
            }
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_808016D8_chcaptainblubber, actor->scale);
            return 1;
        case 0x3D:
            spawned =
                func_80108528(0x1F0, (f32 *) actor->actorData, (s32) actor->unk54, &actor);
            spawned->unk74_7 = 0x33;
            if (func_800DB9B0()) {
                _chappearfx_entrypoint_1(spawned, 0x20, 0, 1.0f);
            }
            if (arg) {
                func_800FFA88(actor->unk0);
            }
            return 1;
        case 0x32:
            dialog_arg = 0xE;
            dialog_id = 0;
            switch (actor->unk70_10) {
                case 1:
                    if (func_800DA298(0xDF)) {
                        dialog_id = 0x1007;
                    } else {
                        func_800DA544(0xDF);
                        switch (func_800F5410(func_800F54E4())) {
                            case 1:
                                dialog_id = 0x1006;
                                break;
                            case 10:
                                dialog_id = 0x106B;
                        }
                    }
                    break;
                case 2:
                    dialog_id = 0x1008;
                    dialog_arg = 0x4E;
            }
            if (dialog_id) {
                _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, dialog_arg, actor->position,
                                              0x64);
            }
            actor->unk64_20 = 0;
            return 1;
    }
    return 0;
}

// Plays animation-driven sounds and footstep particles.
void func_80800A1C_chcaptainblubber(actor) Actor *actor;
{
    extern BlubberTimes4 D_808016E8_chcaptainblubber;
    extern BlubberTimes3 D_808016F8_chcaptainblubber;
    extern BlubberTimes3 D_80801704_chcaptainblubber;
    extern BlubberTimes3 D_80801710_chcaptainblubber;
    extern BlubberTimes7 D_8080171C_chcaptainblubber;
    extern BlubberTimes3 D_80801738_chcaptainblubber;
    extern u8 D_80801744_chcaptainblubber[];

    s32 emit_particles;
    BlubberTimes4 times_a;
    BlubberTimes3 times_b;
    BlubberTimes3 times_c;
    BlubberTimes3 times_d;
    BlubberTimes7 times_e;
    BlubberTimes3 times_f;
    f32 pos_b[3];
    f32 pos_a[3];

    emit_particles = 0;

    switch (D_80801654_chcaptainblubber[actor->unk70_10].local_0) {
        case 0x159:
            times_a = D_808016E8_chcaptainblubber;

            if (func_80101E4C(actor, times_a.times)) {
                func_800C4140(((u16) (u32) (func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0x119564,
                              (char *) actor + 4, 0x04B000FA);

                func_800C4140(((u16) (u32) (func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0x119614,
                              (char *) actor + 4, 0x04B000FA);
            }

            if (func_80101E14(actor, 0.22f)) {
                func_800C4140(0x4CB194E3, (char *) actor + 4, 0x04B000FA);
            } else if (func_80101E14(actor, 0.4f)) {
                func_800C4140(0x4CB194E4, (char *) actor + 4, 0x04B000FA);
            }
            break;

        case 0x1C0:
            if (func_80101E14(actor, 0.14f)) {
                func_800C4140(0x7FF19612, (char *) actor + 4, 0x04B000FA);
            } else if (func_80101E14(actor, 0.55f)) {
                emit_particles = 1;

                func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x1B5C50,
                              (char *) actor + 4, 0x04B000FA);
            }
            break;
        case 0x15A:
            times_b = D_808016F8_chcaptainblubber;

            times_c = D_80801704_chcaptainblubber;

            if (actor->unk70_10 == 0xB) {
                if (func_80101E14(actor, 0.24f)) {
                    func_800C3F48(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x09C612);
                }
            } else if (func_80101E4C(actor, times_b.times)) {
                if (actor->unk70_10 == 9) {
                    func_800C3F48(0x7FE7D612);
                } else {
                    func_800C4140(0x7FE7D612, (char *) actor + 4, 0x04B000FA);
                }
            }

            if (func_80101E4C(actor, times_c.times)) {
                emit_particles = 1;

                func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x177450,
                              (char *) actor + 4, 0x04B000FA);
            }
            break;

        case 0x1BF:
            times_d = D_80801710_chcaptainblubber;

            if (func_80101E4C(actor, times_d.times)) {
                emit_particles = 1;

                func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x119451,
                              (char *) actor + 4, 0x04B000FA);
            }
            break;

        case 0x17B:
            times_e = D_8080171C_chcaptainblubber;

            times_f = D_80801738_chcaptainblubber;

            if (func_80101E4C(actor, times_e.times)) {
                emit_particles = 1;

                func_800C4140((((func_800DC128(0x36B0, 0x3E81) >> 5) & 0x3FF) << 11) +
                                  ((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x451,
                              (char *) actor + 4, 0x04B000FA);
            }
            break;

        case 0x16D:
            if (func_80101E14(actor, 0.07f)) {
                func_800C4140(0x7FF19612, (char *) actor + 4, 0x04B000FA);
            } else if (func_80101E14(actor, 0.9f)) {
                emit_particles = 1;

                func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) +
                                  0x09C451,
                              (char *) actor + 4, 0x04B000FA);
            }
    }

    if (emit_particles != 0) {
        _subaddieskeleton_entrypoint_0(actor, 0x14, pos_a);

        _subaddieskeleton_entrypoint_0(actor, 6, pos_b);

        func_800BBCB8(pos_a, 0, 1.0f, 1, D_80801744_chcaptainblubber);

        func_800BBCB8(pos_b, 0, 1.0f, 1, D_80801744_chcaptainblubber);
    }
}

// Draws Blubber's shadow.
void func_8080143C_chcaptainblubber(Actor *actor)
{
    f32 shadow_pos[3];
    if (D_80801654_chcaptainblubber[actor->unk70_10].local_0 == 0x1C0) {
        _subaddieskeleton_entrypoint_0(actor, 3, shadow_pos);
        shadow_pos[1] = 0.0f;
    } else
        func_800EFA4C(shadow_pos, actor->position[0], 0.0f, actor->position[2]);
    _chbadshad_entrypoint_1(actor, shadow_pos, actor->scale + actor->scale);
}

void func_808014C8_chcaptainblubber(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

int chcaptainblubber_entrypoint_0()
{
    return (int) &D_8080176C_chcaptainblubber;
}

extern void func_80101870();
extern void func_80107C2C();
u32 D_80801650_chcaptainblubber[1] = {0x0};
BlubberStateRecord D_80801654_chcaptainblubber[13] = {
    0x0,  0x0,   0x0,   0x41,  0x18,  0x0,   0x0,   0x159, 0x0,   0x1,   0x41,  0x18,  0x0,
    0x0,  0x159, 0x0,   0x1,   0x41,  0x18,  0x0,   0x0,   0x159, 0x0,   0x1,   0x41,  0x18,
    0x0,  0x0,   0x159, 0x0,   0x1,   0x41,  0x18,  0x0,   0x0,   0x159, 0x0,   0x1,   0x3F,
    0x99, 0x99,  0x9A,  0x1C0, 0x0,   0x42,  0x3F,  0x99,  0x99,  0x9A,  0x15A, 0x2,   0x41,
    0x3F, 0x33,  0x33,  0x33,  0x1BF, 0x0,   0x41,  0x3F,  0x99,  0x99,  0x9A,  0x15A, 0x0,
    0x42, 0x3F,  0x33,  0x33,  0x33,  0x1BF, 0x0,   0x41,  0x3F,  0x99,  0x99,  0x9A,  0x15A,
    0x0,  0x41,  0x40,  0x60,  0x0,   0x0,   0x17B, 0x1,   0x42,  0x40,  0x0,   0x0,   0x0};
static u32 D_80801654_chcaptainblubber_rest[1] = {0x16D0142};
u8 D_808016C0_chcaptainblubber[12] = {0x43, 0xB0, 0x0,  0x0,  0x0,  0x0,
                                      0x0,  0x0,  0xC3, 0xD4, 0x80, 0x0};
u8 D_808016CC_chcaptainblubber[12] = {0x44, 0x1F, 0x0,  0x0,  0x0, 0x0,
                                      0x0,  0x0,  0xC3, 0xAA, 0x0, 0x0};
s32 D_808016D8_chcaptainblubber[4] = {0x438C0000, 0x42F00000, 0x43200000, 0x43160000};
BlubberTimes4 D_808016E8_chcaptainblubber = {0.72f, 0.775f, 0.83f, -1.0f};
BlubberTimes3 D_808016F8_chcaptainblubber = {0.24f, 0.7f, -1.0f};
BlubberTimes3 D_80801704_chcaptainblubber = {0.43f, 0.98f, -1.0f};
BlubberTimes3 D_80801710_chcaptainblubber = {0.42f, 0.92f, -1.0f};
BlubberTimes7 D_8080171C_chcaptainblubber = {0.06f, 0.15f, 0.24f, 0.33f, 0.42f, 0.51f, -1.0f};
BlubberTimes3 D_80801738_chcaptainblubber = {0.66f, 0.77f, -1.0f};
u8 D_80801744_chcaptainblubber[40] = {0x0, 0x1D, 0x9, 0xC9, 0x0,  0x2B, 0x1,  0x0,  0x1, 0x80,
                                      0x0, 0x22, 0x0, 0x80, 0x1,  0x0,  0x2,  0x0,  0x2, 0x0,
                                      0x0, 0x15, 0x0, 0x33, 0x0,  0x33, 0x0,  0x19, 0x0, 0x0,
                                      0x0, 0x7,  0x0, 0x20, 0x64, 0x64, 0x50, 0x78, 0x0, 0x0};
int D_8080176C_chcaptainblubber[21] = {0x12C0294,
                                       0x6DB0001,
                                       (u32) &D_80801650_chcaptainblubber,
                                       0x0,
                                       (u32) func_808001F0_chcaptainblubber,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x100120,
                                       (u32) func_808014C8_chcaptainblubber,
                                       0x0,
                                       0x0,
                                       (u32) func_808000CC_chcaptainblubber,
                                       (u32) func_80107C2C,
                                       -0x7DFFFB7E,
                                       (u32) func_80800580_chcaptainblubber,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0};
