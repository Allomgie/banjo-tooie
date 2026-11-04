// Electromagnet hazard of the Electromagnetic Chamber: it pulls the player in, cycles charge and
// discharge with sparks and swings a hanging plate. Also holds Mumbo's EMP spell from pad 0xA,
// which switches it off for 90 s, and the final off state.
#include "common.h"

extern s32 func_800B53A4(s32);
extern void func_801015D0(Actor *);
extern s32 func_800DC128(s32, s32);
extern s32 func_800D90A4(f32 *);
extern s32 _gccubesearch_entrypoint_9(s32, s32 *, s32);
extern void _gspropctrl_entrypoint_11(void *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800F54E4(void);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
typedef union {
    s32 local_0;
    s16 local_1[2];
} FactoryMagnetEvent;
extern Vec3f D_80802910_chfactorymagnet;
extern void _chfactorymagnet_entrypoint_0(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800DC178(f32, f32);
extern f32 func_80103EAC(Actor *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800CE8D8(s32, f32, s32);
extern void _sumumbofx_entrypoint_3(void *, f32);
extern void *func_80100094(Actor *, s32);
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_28(void *, f32 *, f32, f32);
extern Vec3f D_8080291C_chfactorymagnet;
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern u8 D_80802940_chfactorymagnet[];
extern u8 D_80802954_chfactorymagnet[];
extern u8 D_80802934_chfactorymagnet[];
extern u8 D_8080294C_chfactorymagnet[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80103EF4(Actor *);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 _subaddieaudioloop_entrypoint_7(s32, f32 *, s32, void *, s32);
extern s32 func_800D90F8(f32 *, f32);
extern s32 func_800D91EC(f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern s32 D_8080298C_chfactorymagnet[];
extern s32 D_80802998_chfactorymagnet[];
extern Vec3f D_808029A4_chfactorymagnet;
extern Vec3f D_808029B0_chfactorymagnet;
typedef struct {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    u8 local_4;
    u8 local_5;
    u8 pad_0[2];
} FactoryMagnetBurstParticle;
extern s32 D_808029BC_chfactorymagnet[];
extern void func_800BAA9C(s32, f32);
extern void func_800BA5B0(s32, int, int);
extern int D_80802A04_chfactorymagnet[];
extern int D_80802A4C_chfactorymagnet[];
extern void func_800187B4(s32, f32, f32, f32);
extern s32 D_80802AB4_chfactorymagnet[];
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern u8 D_80802AFC_chfactorymagnet[];
extern u8 D_80802B50_chfactorymagnet[];
extern u8 D_80802B58_chfactorymagnet[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DF744(s32, s32);
extern s32 _gspropctrl_entrypoint_8(s32);
extern f32 func_800DC0C0(void);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800FFAB0(Actor *);
extern int D_80802B68_chfactorymagnet[];
typedef struct {
    f32 local_0;
    f32 local_1;
    u32 local_2;
    u32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
} FactoryMagnetData;
extern f32 func_800D8FF8(void);
extern void func_800F5A00(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800F8418(s32, f32 *);
extern void _sumumbofx_entrypoint_14(void *);
extern s32 _sumumbofx_entrypoint_27(void *);
extern void _sumumbofx_entrypoint_5(void *, f32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern s32 func_800CEA84(s32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, s32, s32);
typedef struct {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    u8 local_4;
    u8 local_5;
    u8 local_6[2];
} MagnetParticle;
extern void *func_800D674C(s32);
extern void func_800E2594(u32, void *);
extern void func_800E2588(u32);
extern s32 func_800E2720(void *, s32, s32, f32 *, f32 *, s32);
extern void func_800E2A14(s32);
extern void func_800F4D74(s32, f32 *, f32, f32, f32);
extern u8 D_80802A94_chfactorymagnet[];
extern u8 D_80802AA4_chfactorymagnet[];
extern void func_80018820(s32, f32, f32);
extern void func_800C31DC(s32, f32);
void *func_80800E40_chfactorymagnet();
void func_80801A9C_chfactorymagnet();
void func_80801AE8_chfactorymagnet();
void func_80800898_chfactorymagnet();
void func_80801460_chfactorymagnet();
void func_80801508_chfactorymagnet();
void func_808016A4_chfactorymagnet();

void func_80800000_chfactorymagnet(Actor *actor)
{
    void *coil_props[3];
    s32 j;
    void *target_prop;
    f32 target_pos[3];
    f32 pos_a[3];
    f32 pos_b[3];
    f32 pos_c[3];
    f32 dists[3];
    f32 tmp;
    s32 i;
    if (_gccubesearch_entrypoint_9(0x299, coil_props, 3) != 3) {
        func_800FFA88(actor->unk0);
        return;
    }
    if (!_gccubesearch_entrypoint_9(0x3FC, &target_prop, 1)) {
        func_800FFA88(actor->unk0);
        return;
    }
    _gspropctrl_entrypoint_11(coil_props[0], pos_a);
    _gspropctrl_entrypoint_11(coil_props[1], pos_b);
    _gspropctrl_entrypoint_11(coil_props[2], pos_c);
    _gspropctrl_entrypoint_11(target_prop, target_pos);
    dists[0] = func_800EFC7C(target_pos, pos_a);
    dists[1] = func_800EFC7C(target_pos, pos_b);
    dists[2] = func_800EFC7C(target_pos, pos_c);
    for (i = 0; i < 2; i++) {
        for (j = i; j < 3; j++) {
            if (dists[j] < dists[i]) {
                tmp = dists[j];
                dists[j] = dists[i];
                dists[i] = tmp;
            }
        }
    }
    *(f32 *) ((u8 *) actor + 0x28) = dists[0];
    *(f32 *) ((u8 *) actor + 0x2C) = dists[1];
    *(f32 *) ((u8 *) actor + 0x30) = dists[2];
    for (i = 0; i < 30; i++) {
        func_80801508_chfactorymagnet(actor, i);
    }
}

void func_80801B74_chfactorymagnet();

void func_80801368_chfactorymagnet();

s32 func_808012E4_chfactorymagnet(Actor *param_0, f32 param_1);

void func_80800FE8_chfactorymagnet();

void func_8080083C_chfactorymagnet();

// Electromagnet state machine.
void func_80800224_chfactorymagnet(Actor *actor)
{
    f32 player_pos[3];
    f32 pull[3];
    void *spell_fx_8;
    void *spell_fx_9;
    void *spell_fx_11;
    void *spell_fx_12;
    void *spell_fx_13;

    switch (actor->unk70_10) {
        case 1:
            if (func_808012E4_chfactorymagnet(
                    actor, ((FactoryMagnetData *) actor->actorData)->local_5)) {
                func_80800898_chfactorymagnet(actor, 2);
            }
            break;
        case 2:
            if (func_800D91EC(&actor->unk58, 1.0f)) {
                func_80800898_chfactorymagnet(actor, func_800DA298(0x19E) ? 3 : 4);
            }
            break;
        case 3:
            func_8080083C_chfactorymagnet(actor);
            if (func_808012E4_chfactorymagnet(
                    actor, ((FactoryMagnetData *) actor->actorData)->local_4)) {
                func_80800898_chfactorymagnet(actor, 4);
            } else if (!func_808012E4_chfactorymagnet(
                           actor, ((FactoryMagnetData *) actor->actorData)->local_5)) {
                func_80800898_chfactorymagnet(actor, 5);
            }
            break;
        case 4:
            if (func_808012E4_chfactorymagnet(
                    actor, ((FactoryMagnetData *) actor->actorData)->local_6)) {
                func_800F5A00(func_800F54E4(), player_pos);
                func_800EFB24(pull, player_pos, actor->position);
                func_800D90A4(&((FactoryMagnetData *) actor->actorData)->local_0);
                func_800EF334(pull,
                              func_800F10B4(((FactoryMagnetData *) actor->actorData)->local_0,
                                            20.0f, 0.0f, 1.0f, 0.5f));
                func_800EF04C(pull, actor->position);
                func_800F8418(func_800F54E4(), pull);
            } else {
                func_80800898_chfactorymagnet(actor, 5);
            }
            func_8080083C_chfactorymagnet(actor);
            break;
        case 5:
            if (func_808012E4_chfactorymagnet(
                    actor, ((FactoryMagnetData *) actor->actorData)->local_5)) {
                func_80800898_chfactorymagnet(actor, 2);
            } else if (--actor->unk6C_0 == 0) {
                func_80800898_chfactorymagnet(actor, 6);
            }
            break;
        case 6:
            if (func_808012E4_chfactorymagnet(
                    actor, ((FactoryMagnetData *) actor->actorData)->local_5)) {
                func_80800898_chfactorymagnet(actor, 2);
            } else if (func_800D90A4(&actor->unk58)) {
                func_80800898_chfactorymagnet(actor, 1);
            }
            break;
        case 7:
            if (func_800DA298(0x9DE)) {
                func_80800898_chfactorymagnet(actor, 8);
            }
            break;
        case 8:
            spell_fx_8 = func_80100094(actor, 0);
            func_80801460_chfactorymagnet(actor, spell_fx_8);
            _sumumbofx_entrypoint_14(spell_fx_8);
            if (_sumumbofx_entrypoint_27(spell_fx_8)) {
                func_80800898_chfactorymagnet(actor, 9);
            }
            break;
        case 9:
            spell_fx_9 = func_80100094(actor, 0);
            func_80801460_chfactorymagnet(actor, spell_fx_9);
            _sumumbofx_entrypoint_14(spell_fx_9);
            _sumumbofx_entrypoint_5(spell_fx_9, 3.0f);
            if (_sumumbofx_entrypoint_27(spell_fx_9)) {
                func_80800898_chfactorymagnet(actor, 11);
            }
            break;
        case 11:
            spell_fx_11 = func_80100094(actor, 0);
            func_80801460_chfactorymagnet(actor, spell_fx_11);
            _sumumbofx_entrypoint_14(spell_fx_11);
            func_800D91EC(&actor->unk58, 1.0f);
            if (_sumumbofx_entrypoint_27(spell_fx_11)) {
                func_800DA544(0x9DF);
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1337, 4, actor->position, 0xA3);
                func_80800898_chfactorymagnet(actor, 12);
            }
            break;
        case 12:
            spell_fx_12 = func_80100094(actor, 0);
            func_80801460_chfactorymagnet(actor, spell_fx_12);
            _sumumbofx_entrypoint_14(spell_fx_12);
            func_80801368_chfactorymagnet(actor);
            if (func_800DA298(0x1B8) || !func_800DA298(0xA06) ||
                (func_800CEAA8(0) && (f32) func_800CEA84(0) < 5.0f)) {
                func_80800898_chfactorymagnet(actor, 13);
            }
            break;
        case 13:
            spell_fx_13 = func_80100094(actor, 0);
            func_80801460_chfactorymagnet(actor, spell_fx_13);
            _sumumbofx_entrypoint_14(spell_fx_13);
            func_80801368_chfactorymagnet(actor);
            if (_sumumbofx_entrypoint_27(spell_fx_13)) {
                func_80800898_chfactorymagnet(actor, 14);
            }
            break;
        case 14:
            if (func_808012E4_chfactorymagnet(
                    actor, ((FactoryMagnetData *) actor->actorData)->local_5) &&
                !func_800DA298(0x1B8)) {
                func_800DA524(0xA06);
                func_800DA524(0x9DE);
                func_80800898_chfactorymagnet(actor, 2);
            } else {
                actor->unk58 -= func_800D8FF8() * 0.5f;
                if (actor->unk58 <= 0.0f) {
                    func_80800898_chfactorymagnet(actor, 15);
                }
            }
            break;
        case 15:
            if (func_800D90A4(&((FactoryMagnetData *) actor->actorData)->local_1)) {
                func_80800898_chfactorymagnet(actor, 16);
            }
            break;
        case 16:
            if (func_800CEAA8(0)) {
                func_800CE88C(0, 0);
            }
            if (func_800DA298(0x1B8)) {
                if (func_800D91EC(&actor->unk58, 1.0f)) {
                    func_80800898_chfactorymagnet(actor, 17);
                }
            } else if (func_800D91EC(&actor->unk58, 0.4f)) {
                func_80800898_chfactorymagnet(actor, 6);
            }
            func_800DA524(0xA06);
            func_800DA524(0x9DE);
            break;
        case 17:
            func_80103110(actor, 0);
            if (func_800D90A4(&((FactoryMagnetData *) actor->actorData)->local_0)) {
                ((FactoryMagnetData *) actor->actorData)->local_0 = func_800DC178(2.0f, 20.0f);
                func_80108B04(actor, 1);
            }
    }
    if (actor->unk58 != ((FactoryMagnetData *) actor->actorData)->local_7 &&
        actor->unk3C != NULL) {
        func_80800FE8_chfactorymagnet(actor);
    }
    func_80801B74_chfactorymagnet(actor);
    ((FactoryMagnetData *) actor->actorData)->local_7 = actor->unk58;
}

void func_8080083C_chfactorymagnet(Actor *actor)
{
    f32 target_pos[3];
    func_800EE7F8(target_pos, _subaddiefind_entrypoint_2(0x3FC, 0)->position);
    func_800F4EC8(func_800F54E4(), target_pos, 500.0f, 0.0f, 200.0f);
}

void func_80801CD8_chfactorymagnet();

void func_80800898_chfactorymagnet(actor, state) Actor *actor;
s32 state;
{
    void *spell_fx;
    switch (state) {
        case 1:
            actor->unk58 = 0.0f;
            func_8010A624(actor);
            break;
        case 2:
            func_8010A63C(actor);
            break;
        case 4:
            func_80101180(0x50F, 10, 0);
            actor->unk58 = 1.0f;
            *(f32 *) actor->actorData = 20.0f;
            if (!func_800DA298(0x19E)) {
                _capod_entrypoint_13(actor->unk0, 0, 0, 0x850);
            }
            break;
        case 5:
            func_80101180(0x50F, 0x4F, 0);
            actor->unk6C_0 = 0x3C;
            if (actor->unk70_10 == 4) {
                func_80801CD8_chfactorymagnet(actor);
            }
            break;
        case 6:
            if (!func_800DA298(0x19E)) {
                func_800DA544(0x19E);
            }
            break;
        case 8:
            spell_fx = func_80800E40_chfactorymagnet(actor);
            _capod_entrypoint_13(actor->unk0, 0, 2, 0x10);
            func_800DA544(0xA06);
            func_80101180(0x2B0, 0xBB, 10);
            _sumumbofx_entrypoint_15(spell_fx, 0x40400000);
            func_800DA544(0x57E);
            func_8010A63C(actor);
            break;
        case 9:
            _sumumbofx_entrypoint_18(func_80100094(actor, 0), 0x40400000);
            _chglowbo_entrypoint_6();
            break;
        case 11:
            _sumumbofx_entrypoint_17(func_80100094(actor, 0), 0x40000000);
            func_8010A63C(actor);
            break;
        case 12:
            _sumumbofx_entrypoint_17(func_80100094(actor, 0), 0x40000000);
            break;
        case 13:
            _sumumbofx_entrypoint_16(func_80100094(actor, 0), 0x40800000);
            break;
        case 14:
            func_80100094(actor, 0);
            _sumumbofx_entrypoint_1(actor, 0);
            func_8010A800(actor, 0);
            break;
        case 15:
            *(f32 *) ((u8 *) actor + 0x1C) = 1.5f;
            break;
        case 17:
            func_8010A63C(actor);
            actor->unk58 = 1.0f;
            *(f32 *) ((u8 *) actor + 0x34) = 1.0f;
            *(f32 *) actor->actorData = func_800DC178(2.0f, 20.0f);
    }
    func_80101FDC(actor, state);
}

s32 func_80800B20_chfactorymagnet(Actor *actor, s32 msg, FactoryMagnetEvent msg_data)
{
    Actor *spawned;
    Vec3f spark_pos;
    Vec3f field_pos;
    f32 yaw;
    Actor *plate;
    void *spell_fx;

    switch (msg) {
        case 0x4B:
            func_80800898_chfactorymagnet(actor, 7);
            return 1;
        case 0x30:
            if (msg_data.local_1[0] == 0x1337) {
                return 0x5A;
            }
            return 0;
        case 0xB:
            if (msg_data.local_0 == 2) {
                func_800CE8D8(0, 90.0f, 90);
                func_800CE928(0, _chfactorymagnet_entrypoint_0, actor->unk0);
                func_800CE88C(0, 1);
            }
            return 3;
        case 0x3D:
            switch (msg_data.local_0) {
                case 0:
                    spawned = func_80108528(0x3F6, D_80802910_chfactorymagnet.f, 0, &actor);
                    spawned->unk3C = actor->unk0;
                    actor->unk3C = spawned->unk0;
                    func_80801A9C_chfactorymagnet(actor, NULL, spark_pos.f);
                    func_80108528(0x50F, spark_pos.f, 0, &actor)->scale = actor->scale;
                    break;
                case 1:
                    yaw = func_800DC178(0.0f, 360.0f);
                    func_80801A9C_chfactorymagnet(actor, NULL, field_pos.f);
                    func_800EF214(field_pos.f, func_800DC178(0.0f, 360.0f), yaw,
                                  func_80103EAC(actor));
                    spawned = func_80108528(0x52F, field_pos.f, 0, &actor);
                    spawned->scale = actor->scale;
                    spawned->rotation[1] = func_800DC178(160.0f, 200.0f) + yaw;
                    spawned->rotation[0] = func_800DC178(-20.0f, 20.0f);
                    spawned->unk58 = *(f32 *) &spawned->actorData[7] = func_800DC178(0.5f, 1.25f);
            }
            return 1;
        case 0x95:
            plate = _subaddiefind_entrypoint_2(0x3F6, 0);
            *(u8 *) &actor->actorData[3] = 0;
            *(u8 *) &actor->unk54 = 0;
            func_80801AE8_chfactorymagnet(actor);
            if (plate == NULL) {
                func_80108B04(actor, 0);
                actor->unk3C = NULL;
            } else {
                actor->unk3C = plate->unk0;
            }
            if (func_800DA298(0xA06)) {
                spell_fx = func_80800E40_chfactorymagnet(actor);
                _sumumbofx_entrypoint_4(spell_fx);
                _sumumbofx_entrypoint_3(spell_fx, 10.0f);
                func_80800898_chfactorymagnet(actor, 12);
                if (func_800DA298(0x1B8)) {
                    func_800DA524(0xA06);
                }
            } else if (func_800DA298(0x1B8)) {
                func_80800898_chfactorymagnet(actor, 17);
            } else {
                func_80800898_chfactorymagnet(actor, 1);
            }
            return 1;
        default:
            return 0;
    }
}

void *func_80800E40_chfactorymagnet(actor)
Actor *actor;
{
    void *spell_fx;
    s32 offset[3];

    offset[0] = 0;
    offset[1] = 0;
    offset[2] = 0;
    _sumumbofx_entrypoint_0(actor, 0, 0x28, (s16) _chmumbopad_entrypoint_0(0xA));
    spell_fx = func_80100094(actor, 0);
    _sumumbofx_entrypoint_2(spell_fx);
    _sumumbofx_entrypoint_25(spell_fx, 0x8C, offset);
    _sumumbofx_entrypoint_24(spell_fx, 0.65f);
    func_8010A800(actor, 2);
    _sumumbofx_entrypoint_28(spell_fx, actor->position, 2000.0f, 4000.0f);
    return spell_fx;
}

void func_80800EF0_chfactorymagnet(Actor *actor, s32 gfx)
{
    f32 anchor_a[3];
    f32 anchor_b[3];
    f32 charge;
    Vec3f origin;
    void *spell_fx;

    charge = func_800F12D4(actor->unk58, 0.25f, 1.0f, 0.0f, 1.0f);
    origin = D_8080291C_chfactorymagnet;
    spell_fx = func_80100094(actor, 0);
    func_80801A9C_chfactorymagnet(actor, anchor_a, anchor_b);
    func_800EFE50(actor->position, anchor_a, anchor_b, charge);
    if (spell_fx != NULL) {
        _sumumbofx_entrypoint_9(spell_fx, gfx);
    }
    if (actor->unk70_10 == 4) {
        func_808016A4_chfactorymagnet(actor, gfx);
    }
    func_80101870(actor, gfx);
    if (spell_fx != NULL) {
        _sumumbofx_entrypoint_8(spell_fx, gfx);
    }
}

void func_80800FE8_chfactorymagnet(Actor *actor)
{
    s32 effect;
    Actor *plate;
    Vec3f left_top;
    Vec3f right_top;
    Vec3f left;
    Vec3f right;
    f32 half_width;

    *(u8 *) &actor->actorData[3] = _subaddieaudioloop_entrypoint_7(
        *(u8 *) &actor->actorData[3], actor->position,
        actor->unk58 > 0.25f && actor->unk58 < 1.0f, D_80802940_chfactorymagnet,
        *(u32 *) ((u8 *) actor + 0x70) & 1);
    *(u8 *) &actor->unk54 = _subaddieaudioloop_entrypoint_7(
        *(u8 *) &actor->unk54, actor->position, actor->unk58 > 0.0f && actor->unk58 < 0.75f,
        D_80802940_chfactorymagnet, *(u32 *) ((u8 *) actor + 0x70) & 1);
    if ((actor->unk58 <= 0.0f && ((f32 *) actor->actorData)[7] > 0.0f) ||
        (actor->unk58 >= 0.75f && ((f32 *) actor->actorData)[7] < 0.75f)) {
        effect = func_800B53A4(4);
        plate = func_80106790(actor->unk3C);
        half_width = func_80103EF4(plate);
        func_800EE7F8(left.f, plate->position);
        func_800EE7F8(right.f, left.f);
        left.pos.x -= half_width;
        right.pos.x += half_width;
        func_800EE7F8(left_top.f, left.f);
        func_800EE7F8(right_top.f, right.f);
        left_top.pos.y += half_width * func_800138D0(plate->rotation[0]);
        right_top.pos.y += half_width * func_800138D0(plate->rotation[0]);
        left_top.pos.z += half_width * func_80013970(plate->rotation[0]);
        right_top.pos.z += half_width * func_80013970(plate->rotation[0]);
        func_800BABB8(effect, plate->position, NULL, plate->scale, D_80802954_chfactorymagnet);
        func_800BA1D0(effect, left.f, left_top.f, 1);
        func_800BA1D0(effect, left_top.f, right_top.f, 2);
        func_800BA1D0(effect, right_top.f, right.f, 1);
        _subaddieaudioquick_entrypoint_2(actor, plate->position, D_80802934_chfactorymagnet);
    }
    if (actor->unk58 >= 1.0f && ((f32 *) actor->actorData)[7] < 1.0f) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080294C_chfactorymagnet);
    }
}

s32 func_808012E4_chfactorymagnet(Actor *actor, f32 max_dist)
{
    f32 player_pos[3];
    Actor *target;

    if (func_80090178(0x40)) {
        target = _subaddiefind_entrypoint_2(0x3FC, 0);
        func_800F5A00(func_800F54E4(), player_pos);
        return func_800EFC7C(player_pos, target->position) < max_dist;
    }
    return 0;
}

void func_80801368_chfactorymagnet(Actor *actor)
{
    s32 reached;
    if (*(f32 *) &actor->actorData[1] < actor->unk58) {
        reached = func_800D90F8(&actor->unk58, *(f32 *) &actor->actorData[1]);
    } else {
        reached = func_800D91EC(&actor->unk58, *(f32 *) &actor->actorData[1]);
    }
    if (reached) {
        *(f32 *) &actor->actorData[1] = func_800DC178(0.0f, 1.0f);
    }
}

// Timer-expiry callback of the Mumbo EMP spell.
int chfactorymagnet_entrypoint_0(s32 param_0, s32 param_1)
{
    func_800DA524(0xA06);
    if (func_800EA05C() != 0x107) {
        func_800DA524(0x9DE);
    }
    if (!func_800DA298(0x1B8)) {
        _chmrtannoy_entrypoint_0();
        func_800C05B8(0x1338, 4, 0, 0, 0, 0, 0xA3);
    }
}

void func_80801460_chfactorymagnet(actor, spell_fx) Actor *actor;
void *spell_fx;
{
    f32 emit_pos[3];
    f32 anchor_a[3];
    f32 anchor_b[3];
    f32 charge;
    charge = func_800F12D4(actor->unk58, 0.25f, 1.0f, 0.0f, 1.0f);
    func_80801A9C_chfactorymagnet(actor, anchor_a, anchor_b);
    func_800EFE50(emit_pos, anchor_a, anchor_b, charge);
    _sumumbofx_entrypoint_7(spell_fx, func_80103EAC(actor) * 0.6f, 0, 40, emit_pos, 0, 0);
}

void func_80801508_chfactorymagnet(actor, index) Actor *actor;
s32 index;
{
    MagnetParticle *particles;
    MagnetParticle *particle;
    particles = func_80100094(actor, 1);
    if (func_800DC0C0() < 0.2f) {
        particle = (MagnetParticle *) ((u8 *) particles + index * sizeof(MagnetParticle));
        particle->local_5 = func_800DC128(0, 3);
        particle->local_3 = func_800DC0C0() * 0.15f + 0.35f;
        particle->local_1 = particle->local_2 = func_800DC178(1.0f, 3.0f);
        particle->local_4 = func_800DC0C0() < 0.5f ? 1 : 2;
        if (func_800DC0C0() < 0.2f) {
            func_800F5A00(func_800F54E4(), particle->local_0);
            particle->local_0[0] += func_800DC178(-100.0f, 100.0f);
            particle->local_0[1] += func_800DC178(0.0f, 200.0f);
        } else {
            particle->local_0[0] = func_800DC178(-2000.0f, 1500.0f);
            particle->local_0[1] = func_800DC178(0.0f, 1600.0f);
            particle->local_0[2] = func_800DC178(1200.0f, 1800.0f);
        }
    }
}

void func_808019F4_chfactorymagnet();

void func_808016A4_chfactorymagnet(actor, gfx) Actor *actor;
s32 gfx;
{
    f32 anchor_a[3];
    f32 anchor_b[3];
    f32 *anchor;
    s32 alpha;
    f32 t;
    f32 spark_pos[3];
    f32 spark_size[3];
    s32 i;
    FactoryMagnetBurstParticle *particles;
    f32 glow_pos[3];
    f32 glow_size[3];
    FactoryMagnetBurstParticle *particle;

    particles = func_80100094(actor, 1);
    func_808019F4_chfactorymagnet(actor, anchor_a, anchor_b);
    func_800E2594(gfx, func_800D674C(0x9D8));
    for (i = 0, particle = particles; i != 20; i++, particle++) {
        if (particle->local_4) {
            if (func_800D90A4(&particle->local_1)) {
                particle->local_4 = 0;
            } else {
                t = func_800F12D4(particle->local_1, particle->local_2, 0.0f, 0.0f, 1.0f);
                if (t > 0.5f) {
                    alpha = 255;
                    t -= 0.5f;
                    t += t;
                    anchor = particle->local_4 == 1U ? anchor_a : anchor_b;
                    func_800EFE50(spark_pos, particle->local_0, anchor, t);
                    spark_size[2] =
                        func_800F10B4(particle->local_1, particle->local_2, 0.0f, 0.0f, 1.0f);
                    t = func_800138D0(spark_size[2] * 720.0f);
                    spark_size[0] = particle->local_3 * t;
                    t = func_80013970(spark_size[2] * 360.0f);
                    spark_size[1] = particle->local_3 * t;
                } else {
                    anchor = particle->local_4 == 1U ? anchor_a : anchor_b;
                    func_800EE7F8(spark_pos, anchor);
                    spark_size[0] = spark_size[1] = spark_size[2] = particle->local_3;
                    alpha = (s32) (511.0f * t);
                }
                func_800E2588(1);
                func_800E2720((void *) gfx, particle->local_5, 0, spark_pos, spark_size, alpha);
            }
        } else {
            func_80801508_chfactorymagnet(actor, i);
        }
    }
    func_800E2A14(gfx);
    func_800E2594(gfx, func_800D674C(0x9DF));
    for (; i < 30; i++, particle++) {
        if (particle->local_4) {
            if (func_800D90A4(&particle->local_1)) {
                particle->local_4 = 0;
            } else {
                t = func_800F12D4(particle->local_1, particle->local_2, 0.0f, 0.0f, 1.0f);
                anchor = particle->local_4 == 1U ? anchor_a : anchor_b;
                func_800EFE50(glow_pos, particle->local_0, anchor, t);
                glow_size[2] = particle->local_3;
                glow_size[0] = particle->local_3;
                glow_size[1] = particle->local_3;
                func_800E2588(1);
                func_800E2720((void *) gfx, 0, 0, glow_pos, glow_size, 255);
            }
        } else {
            func_80801508_chfactorymagnet(actor, i);
        }
    }
    func_800E2A14(gfx);
}

void func_808019F4_chfactorymagnet(Actor *actor, f32 *anchor_a, f32 *anchor_b)
{
    f32 offset[3];

    func_800EFA4C(offset, actor->scale * -195.0f, actor->scale * 60.0f,
                  actor->scale * 390.0f);
    func_800EE780(anchor_a, actor->position, offset);
    offset[0] = actor->scale * 205.0f;
    func_800EE780(anchor_b, actor->position, offset);
}

void func_80801A9C_chfactorymagnet(actor, anchor_a, anchor_b) Actor *actor;
f32 *anchor_a;
f32 *anchor_b;
{
    if (anchor_a != 0) {
        func_800EE7F8(anchor_a, (f32 *) &D_8080298C_chfactorymagnet);
    }
    if (anchor_b != 0) {
        func_800EE7F8(anchor_b, (f32 *) &D_80802998_chfactorymagnet);
    }
}

void func_80801AE8_chfactorymagnet(actor) s32 actor;
{
    u8 *fx_data;

    fx_data = func_80100094(actor, 1);
    (*(s32 *) ((s8 *) (fx_data) + (0x348))) = func_800C8A98();
    (*(s32 *) ((s8 *) (fx_data) + (0x34C))) = func_800C8A98();
    func_800C8E54((*(s32 *) ((s8 *) (fx_data) + (0x348))), 0x43960000, 0x43E10000);
    func_800C8E54((*(s32 *) ((s8 *) (fx_data) + (0x34C))), 0x43960000, 0x43E10000);
    func_800C8FE0((*(s32 *) ((s8 *) (fx_data) + (0x348))), 0);
    func_800C8FE0((*(s32 *) ((s8 *) (fx_data) + (0x34C))), 0);
    func_800C8F64((*(s32 *) ((s8 *) (fx_data) + (0x348))), 3);
    func_800C8F64((*(s32 *) ((s8 *) (fx_data) + (0x34C))), 3);
}

// Sparks are only active while in state 4.
void func_80801B74_chfactorymagnet(Actor *actor)
{
    Vec3f pos_a = D_808029A4_chfactorymagnet;
    Vec3f pos_b = D_808029B0_chfactorymagnet;
    u8 *fx_data = func_80100094(actor, 1);

if (actor->unk70_10 == 4) {
    func_800C8FE0(*(s32 *) (fx_data + 0x348), 1);
    func_800C8FE0(*(s32 *) (fx_data + 0x34C), 1);
    func_800C8CB8(*(s32 *) (fx_data + 0x348), &pos_a);
    func_800C8CB8(*(s32 *) (fx_data + 0x34C), &pos_b);
    func_800C8FB0(*(s32 *) (fx_data + 0x348), func_800DC128(230, 256), func_800DC128(0, 41),
                  func_800DC128(230, 256));
    func_800C8FB0(*(s32 *) (fx_data + 0x34C), func_800DC128(230, 256), func_800DC128(0, 41),
                  func_800DC128(230, 256));
} else {

func_800C8FE0(*(s32 *) (fx_data + 0x348), 0);
func_800C8FE0(*(s32 *) (fx_data + 0x34C), 0);

}
}

void func_80801CD8_chfactorymagnet(Actor *actor)
{
    f32 anchor_a[3];
    f32 anchor_b[3];
    f32 t;
    s32 effect;
    s32 i;
    f32 pos[3];
    FactoryMagnetBurstParticle *particles;
    particles = func_80100094(actor, 1);
    func_808019F4_chfactorymagnet(actor, anchor_a, anchor_b);
    for (i = 0; i < 20; i++) {
        if (particles[i].local_4) {
            t =
                func_800F12D4(particles[i].local_1, particles[i].local_2, 0.0f, 0.0f, 1.0f);
            effect = func_800B53A4(1);
            if (t > 0.5f) {
                t -= 0.5f;
                t += t;
                func_800EFE50(pos, particles[i].local_0,
                              particles[i].local_4 == 1 ? anchor_a : anchor_b, t);
            } else {
                func_800EE7F8(pos, particles[i].local_4 == 1 ? anchor_a : anchor_b);
            }
            func_800BAA9C(effect, particles[i].local_3);
            func_800BA5B0(effect, particles[i].local_5, particles[i].local_5);
            func_800BABB8(effect, pos, 0, 1.0f, &D_808029BC_chfactorymagnet);
        }

}
}

void func_80801E84_chfactorymagnet(s32 actor)
{
    if ((*((s16 *) (actor + 0x82))) != 0) {
        _sumumbofx_entrypoint_1(actor, 0);
    }
}

int chfactorymagnet_entrypoint_1()
{
    return &D_80802A04_chfactorymagnet;
}

void func_80801EBC_chfactorymagnet(Actor *actor)
{
    f32 pos[3];
    f32 size;

    if (func_800DA298(0xA06)) {
        size = func_80103EF4(actor) * 1.2f;
        func_800EFA4C(pos, actor->position[0], actor->position[1] + size * 0.5f,
                      actor->position[2] - size);
        func_800F4D74(func_800F54E4(), pos, size, size * 0.5f,
                      func_80013970(actor->rotation[0]) * size + size);
    }
    actor->rotation[0] =
        func_800F12D4(func_80106790(actor->unk3C)->unk58, 0.0f, 0.75f, 0.0f, 90.0f);
}

int chfactorymagnet_entrypoint_2()
{
    return (int) &D_80802A4C_chfactorymagnet;
}

void func_80801FB8_chfactorymagnet(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            break;

case 2:
    if (func_800D91EC(&actor->unk58, 0.5f)) {
        actor->alpha = 255;
        func_80101FDC(actor, 3);
    }

break;
case 3:
    func_80018820(0, 2.0f, 0.5f);
    break;
case 4:
    actor->alpha = func_800F10B4(actor->unk58, 0.5f, 0.0f, 0.0, 255.0f);

if (func_800D90A4(&actor->unk58)) {
    actor->unk64_16 = 0;
    func_80101FDC(actor, 1);
}

}
*(u8 *) &actor->actorData[4] = _subaddieaudioloop_entrypoint_7(
    *(u8 *) &actor->actorData[4], actor->position, actor->unk58 != 0.0f,
    D_80802A94_chfactorymagnet, *(u32 *) ((u8 *) actor + 0x70) & 1);
*(u8 *) &actor->actorData[5] = _subaddieaudioloop_entrypoint_7(
    *(u8 *) &actor->actorData[5], actor->position, actor->unk58 != 0.0f,
    D_80802AA4_chfactorymagnet, *(u32 *) ((u8 *) actor + 0x70) & 1);
if (actor->unk58 == 0.0f) {
    actor->unk64_16 = 0;
} else {
    actor->unk64_16 = 1;
    actor->alpha = func_800F10B4(actor->unk58, 0.5f, 0.0f, 255.0f, 0.0f);
    func_800C31DC(*(u8 *) &actor->actorData[4],
                  func_800F10B4(actor->unk58, 0.5f, 0.0f, 1.1f, 0.9f));
    func_800C31DC(*(u8 *) &actor->actorData[5],
                  func_800F10B4(actor->unk58, 0.5f, 0.0f, 1.1f, 0.9f));
}
}

s32 func_808022D8_chfactorymagnet(Actor *actor, s32 msg, s32 msg_data)
{
    switch (msg) {
        case 0x1F:
            func_801015D0(actor);
            func_800DF830(2);
            return 1;
        case 0xA:
            actor->unk64_16 = 1;
            func_80101FDC(actor, 2);
            func_800187B4(0, 1.0f, 2.0f, 0.5f);
            return 1;
        case 0x4F:
            func_80101FDC(actor, 4);
            func_800187B4(0, 2.0f, 1.0f, 0.5f);
            return 1;

}
return 0;
}

int chfactorymagnet_entrypoint_3()
{
    return D_80802AB4_chfactorymagnet;
}

void func_80802390_chfactorymagnet(Actor *actor)
{
    s32 bright;
    s32 pad0;

    switch (actor->unk70_10) {
        case 1:
            if (func_800D90A4(&actor->unk58)) {
                if (_subaddiefind_entrypoint_2(0x3F5, 0)->unk70_10 == 0x11) {
                    func_800BBCB8((f32 *) ((u8 *) actor + 0x28), (f32 *) actor->actorData, 1.0f,
                                  10, D_80802AFC_chfactorymagnet);
                    func_800BBCB8((f32 *) actor->actorData, (f32 *) ((u8 *) actor + 0x28), 1.0f,
                                  10, D_80802AFC_chfactorymagnet);
                    *(s32 *) ((u8 *) actor + 0x24) = func_800C8A98();
                    func_800C8D4C(*(s32 *) ((u8 *) actor + 0x24), D_80802B50_chfactorymagnet);
                    func_800C8FE0(*(s32 *) ((u8 *) actor + 0x24), 1);
                    func_800C8F64(*(s32 *) ((u8 *) actor + 0x24), 15);
                    func_800C8CB8(*(s32 *) ((u8 *) actor + 0x24), actor->position);
                    func_800C8FB0(*(s32 *) ((u8 *) actor + 0x24), 200, 200, 255);
                    actor->unk58 = *(f32 *) ((u8 *) actor + 0x34) = func_800DC178(0.5f, 1.25f);
                    func_80101FDC(actor, 2);
                    actor->unk64_16 = 1;
                } else {
                    actor->unk58 = *(f32 *) ((u8 *) actor + 0x34) = func_800DC178(2.0f, 20.0f);
                }
            }

return;

case 2:
    if (func_800D90A4(&actor->unk58)) {
        _subaddieaudioloop_entrypoint_2(actor);
        func_800C8B84(*(s32 *) ((u8 *) actor + 0x24));
        *(s32 *) ((u8 *) actor + 0x24) = 0;
        func_80101FDC(actor, 1);
        actor->unk58 = *(f32 *) ((u8 *) actor + 0x34) = func_800DC178(2.0f, 20.0f);
        actor->unk64_16 = 0;
        return;
    }

bright = func_8001210C(1);
func_800C8FB0(*(s32 *) ((u8 *) actor + 0x24), bright ? 200 : 160, bright ? 200 : 160,
              bright ? 255 : 200);
_subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80802B58_chfactorymagnet);
}
}

s32 func_808025B4_chfactorymagnet(Actor *this, s32 msg, s32 arg2)
{
    s32 buf[20];
    s32 n;
    s32 i;
    f32 v[4];
    f32 spd;

    switch (msg) {
        case 0x1F:
            this->alpha =
                func_800F10B4(this->unk58, *(f32 *) &this->actorData[7], 0.0f, 255.0f, 50.0f);
            func_801015D0(this);
            func_800DF744(1, 1);
            func_800DF744(2, func_800DC128(1, 5));
            return 1;
        case 0x95:
            n = _gccubesearch_entrypoint_9(0x511, buf, 0x14);
            for (i = 0; i < n; i++) {

if (_gspropctrl_entrypoint_8(buf[i]) == this->unk74_7) {
    spd = func_80103EAC(this);
    v[2] = func_800DC0C0() * 200.0f;
    v[3] = v[2] + func_800DC0C0() * 200.0f;
    _gspropctrl_entrypoint_11((void *) buf[i], (f32 *) &this->actorData[0]);
    func_800EE7F8((f32 *) &this->actorData[4], this->position);
    func_800F18FC(this->position, (f32 *) &this->actorData[0], v);
    this->rotation[0] = v[0];
    this->rotation[1] = v[1];
    spd = func_800EEAD4((f32 *) &this->actorData[4], (f32 *) &this->actorData[0]) / spd;
    this->scale = spd;
    func_800EF214(this->position, v[0], v[1], -spd);
    this->unk64_16 = 0;
    this->unk58 = *(f32 *) &this->actorData[7] = func_800DC178(2.0f, 20.0f);
    return 1;
}

}
func_800FFAB0(this);
return 0;
}
return 0;
}

int func_8080281C_chfactorymagnet(Actor *actor)
{
    if ((*(s32 *) ((char *) (actor) + 0x24)) != 0) {
        func_800C8B84((*(s32 *) ((char *) (actor) + 0x24)) |
                      (*(s32 *) ((char *) (actor) + 0x24)));
    }
}

int chfactorymagnet_entrypoint_4()
{
    return &D_80802B68_chfactorymagnet;
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to
// functions of this file; IDO's assembler schedules some functions differently unless the
// tables are in the same unit. Values are taken from the ROM. The extern declarations of
// D_8080298C, D_80802998, D_808029BC (s32[]) and D_80802A04, D_80802A4C, D_80802B68 (int[])
// are adjusted to the object (same addresses).
extern void func_80105834();
extern void func_80107C2C();
extern int func_80101870();
extern void func_801018A4();
Vec3f D_80802910_chfactorymagnet = {-2.5e+02f, 0.0f, -1.1e+03f};
Vec3f D_8080291C_chfactorymagnet = {0.0f, 0.0f, 0.0f};
static u32 D_8080291C_chfactorymagnet_rest[3] = {0x130528, 0xA00C0, 0x0};
u8 D_80802934_chfactorymagnet[12] = {0x0, 0x13, 0x4, 0xA0, 0x0, 0xA, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0};
u8 D_80802940_chfactorymagnet[12] = {0x0, 0x13, 0x4, 0xBF, 0x0, 0xA, 0x1, 0x33, 0x0, 0x0, 0x0, 0x0};
u8 D_8080294C_chfactorymagnet[8] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x0, 0x0, 0x0};
u8 D_80802954_chfactorymagnet[56] = {
    0x0, 0x1D, 0x9, 0xC9, 0x0, 0x2B, 0x2,  0x0,  0x3,  0x0,  0x0, 0x22, 0x2, 0x0,
    0x2, 0x80, 0x6, 0x0,  0x8, 0x0,  0x0,  0x15, 0x0,  0x0,  0x0, 0x33, 0x0, 0x19,
    0x0, 0x0,  0x0, 0x7,  0x0, 0x2C, 0xFF, 0xEC, 0x0,  0x14, 0x0, 0x14, 0x0, 0x14,
    0x0, 0x28, 0x0, 0x14, 0x0, 0x20, 0x60, 0x60, 0x60, 0x80, 0x0, 0x0,  0x0, 0x0};
s32 D_8080298C_chfactorymagnet[3] = {-0x3C860000, 0x43160000, -0x3B2B8000};
s32 D_80802998_chfactorymagnet[3] = {-0x3C860000, 0x43160000, -0x3B768000};
Vec3f D_808029A4_chfactorymagnet = {-4e+02f, 2e+02f, -7e+02f};
Vec3f D_808029B0_chfactorymagnet = {-75.0f, 2e+02f, -7e+02f};
s32 D_808029BC_chfactorymagnet[18] = {
    0x1D09D8, 0x1BF830,  -0x5DBFFEA, 0x20027, -0x1F301F4, 0x1F401F4, 0x240066,  0x660015, 0xC0,
    0x2B0200, 0x2800004, 0x800007,   0x40003, 0x6295DC0,  0x8014C,   0x1660005, 0x1E011A, 0x0};
int D_80802A04_chfactorymagnet[18] = {0x15803F5,
                                      0x70A0001,
                                      0x0,
                                      (u32) func_80800224_chfactorymagnet,
                                      (u32) func_80105834,
                                      (u32) func_80800EF0_chfactorymagnet,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x20800C40,
                                      (u32) func_80801E84_chfactorymagnet,
                                      0x0,
                                      0x350,
                                      (u32) func_80800000_chfactorymagnet,
                                      (u32) func_80107C2C,
                                      -0x7FF7FBFE,
                                      (u32) func_80800B20_chfactorymagnet,
                                      0x0};
int D_80802A4C_chfactorymagnet[18] = {0x15803F6,
                                      0x70B0001,
                                      0x0,
                                      (u32) func_80801EBC_chfactorymagnet,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x20802804,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FF7FFFE,
                                      0x0,
                                      0x0};
u8 D_80802A94_chfactorymagnet[16] = {0x0, 0x13, 0x6, 0x16, 0x0, 0x16, 0x7D, 0x0,
                                     0x0, 0xA,  0x1, 0x0,  0x0, 0x0,  0x0,  0x0};
u8 D_80802AA4_chfactorymagnet[16] = {0x0, 0x13, 0x5, 0x2E, 0x0, 0x16, 0x61, 0xA8,
                                     0x0, 0xA,  0x1, 0x0,  0x0, 0x0,  0x0,  0x0};
s32 D_80802AB4_chfactorymagnet[18] = {0x158050F,
                                      0x88E0001,
                                      0x0,
                                      (u32) func_80801FB8_chfactorymagnet,
                                      (u32) func_80105834,
                                      (u32) func_801018A4,
                                      0xFA00000,
                                      0x0,
                                      0x0,
                                      0x21004,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FFFFFFE,
                                      (u32) func_808022D8_chfactorymagnet,
                                      0x0};
u8 D_80802AFC_chfactorymagnet[84] = {
    0x0, 0x1D, 0x9,  0xCD, 0x0,  0x18, 0x0, 0x0,  0x0,  0x1,  0xF, 0x0,  0x1E, 0x0,
    0x0, 0x1B, 0xFD, 0x44, 0xFD, 0xA8, 0x0, 0x2D, 0x1,  0x61, 0x2, 0x91, 0x0,  0xE,
    0x0, 0x0,  0x0,  0x19, 0x0,  0x22, 0x0, 0x19, 0x0,  0x26, 0x0, 0xC,  0x0,  0x19,
    0x0, 0x15, 0x0,  0x0,  0x0,  0xE6, 0x0, 0x2B, 0x0,  0xB3, 0x1, 0x33, 0x0,  0x2F,
    0x0, 0x0,  0x0,  0x99, 0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x57,
    0x0, 0x31, 0xFF, 0xE2, 0xFF, 0xE2, 0x0, 0x16, 0x10, 0x0,  0x0, 0x0,  0x0,  0x0};
u8 D_80802B50_chfactorymagnet[8] = {0x43, 0x48, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0};
u8 D_80802B58_chfactorymagnet[16] = {0x0, 0x13, 0x5, 0x2E, 0x0,  0xD,  0x0, 0xD9,
                                     0x1, 0x26, 0x0, 0x16, 0x55, 0xF0, 0x0, 0x0};
int D_80802B68_chfactorymagnet[18] = {0x158052F,
                                      0x9390001,
                                      0x0,
                                      (u32) func_80802390_chfactorymagnet,
                                      (u32) func_80105834,
                                      (u32) func_801018A4,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x20000,
                                      (u32) func_8080281C_chfactorymagnet,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FBFFBFE,
                                      (u32) func_808025B4_chfactorymagnet,
                                      0x0};
