#include "ch/biggafoot.h"

extern int D_80801094_chbiggafoot[];
extern int D_808010DC_chbiggafoot[];
extern s32 D_80801198_chbiggafoot[];
extern void *func_800F54E4(void);
extern f32 func_800F5BF0(void *, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
extern s32 func_800F6438(void *);
extern void func_800F5A00(void *, f32 *);
extern f32 func_80102D78(Actor *, u32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern u8 D_80801218_chbiggafoot[];
extern u8 D_808011E4_chbiggafoot[];
extern u8 D_808011D4_chbiggafoot[];
extern u8 D_80801208_chbiggafoot[];
extern u8 D_808011B4_chbiggafoot[];
extern u8 D_808011F4_chbiggafoot[];
extern u8 D_808011C4_chbiggafoot[];
extern u8 D_80801200_chbiggafoot[];
extern s16 D_80801030_chbiggafoot[];
typedef struct {
    u8 pad[0x6C];
    u32 pad6C : 23;
    u32 f : 9;
} BiggaS;
extern u8 D_80801224_chbiggafoot[];
extern u8 D_80801038_chbiggafoot[];
extern u8 func_800C4350(u8, s32, void *);
extern void func_800C32C4(u8, u8);
extern void func_800C3BDC(u8);
extern u8 D_80801238_chbiggafoot[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800BBCB8(void *param_0, s32 param_1, s32 param_2, s32 param_3, void *param_4);
extern s32 D_80801244_chbiggafoot[];
extern void func_80102FDC(Actor *, f32);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} BiggaState;
extern u8 D_80801124_chbiggafoot[];
extern u8 D_8080113C_chbiggafoot[];
extern u8 D_80801148_chbiggafoot[];
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern f32 func_800F3780(f32, u8 *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _sudeflect_entrypoint_4(s32, f32 *);
extern void _sudeflect_entrypoint_3(f32 *, f32 *, u8 *, u8 *, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EFA4C(f32 *, f32, s32, f32);
typedef struct {
    u8 pad0[0x70];
    u32 pad70_1 : 31;
    u32 unk70_0 : 1;
} BiggaBits;
extern f32 D_80801154_chbiggafoot[];
extern u8 D_8080115C_chbiggafoot[];
extern u8 D_80801170_chbiggafoot[];
extern u8 D_80801188_chbiggafoot[];
extern void func_800FFAB0(Actor *);
extern void _capod_entrypoint_3(s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 _capod_entrypoint_17(f32);
extern void func_8010D930();
extern void func_8010A570(Actor *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern f32 func_800F0D50(f32, f32, f32);
extern s32 func_800B2768(s32);
extern s32 func_80103CB8(Actor *, s32);
extern s32 func_800B2840(s32);
extern void _dbmorph_entrypoint_3(s32, s32, s32, s32, f32 *);
extern void func_801015D0(Actor *);
extern void _gcdialogcamera_entrypoint_3(u8 *, f32);
extern void func_800F7F98(s32, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern void func_80102424(Actor *, s32);
void func_80800CDC_chbiggafoot();
void func_80800E98_chbiggafoot();

int *chbiggafoot_entrypoint_0()
{
    return &D_80801094_chbiggafoot;
}

int *chbiggafoot_entrypoint_1()
{
    return &D_808010DC_chbiggafoot;
}

void func_80800018_chbiggafoot(Actor *actor)
{
    struct {
        f32 pos[3];
        s32 unk_C;
        f32 unk_10;
        f32 local_3;
    } marker;

    func_80102FDC(actor, actor->scale * 1.6f);
    *(f32 *) ((u8 *) actor + 0x2C) = 0.0f;
    *(f32 *) ((u8 *) actor + 0x28) = 0.0f;
    *(f32 *) ((u8 *) actor + 0x30) = 0.0f;
    actor->unk50 = actor->rotation[1];
    if (func_800A9C98()) {
        func_800DA544(0x1C7);
        func_800DA524(0x1CC);
    }
    if (_glcutDll_entrypoint_20()) {
        func_80102424(actor, 10);
    } else {
        if (func_800DA298(0x1CC)) {
            func_800FFAB0(actor);
            return;
        }
        _subaddiemarker_entrypoint_1(actor, 0x320, 0x32, marker.pos, 1);
        func_800EE7F8((f32 *) ((u8 *) actor + 0x18), marker.pos);
    }
    *(f32 *) ((u8 *) actor + 0x34) = 3.0f;
}

void func_80800C04_chbiggafoot();

void func_80800BA4_chbiggafoot();

void func_80800A9C_chbiggafoot();

s32 func_808009EC_chbiggafoot();

void func_80800980_chbiggafoot();

s32 func_808008FC_chbiggafoot();

void func_808008D4_chbiggafoot();

// Main update: runs the state machine (actor state in the bitfield at 0x72).
void func_80800100_chbiggafoot(Actor *actor)
{
    f32 pos_copy[3];
    f32 unk_1[3];
    f32 *pos;

    func_800D9078(&actor->unk58);
    switch (((BiggaState *) actor)->st) {
        case 1:
            func_80800980_chbiggafoot(actor);
            if (func_808009EC_chbiggafoot(actor)) {
                func_800F7F98(func_800F54E4(), 1);
                func_80102424(actor, 4);
                func_80108B04(actor, 0);
                _subaddieDll_entrypoint_4(actor, 1);
            } else if (func_808008FC_chbiggafoot(actor)) {
                actor->unk64_20 = 0;
                func_80102424(actor, 3);
            } else {
                func_808008D4_chbiggafoot(actor);
            }
            break;
        case 2:
            func_80800980_chbiggafoot(actor);
            break;
        case 3:
            if (!actor->unk64_20 && func_80101F24(actor) > 0.35f) {
                func_8010A590(actor);
            }
            func_80800980_chbiggafoot(actor);
            if (func_80101DDC(actor)) {
                func_8010A570(actor);
                func_80101FDC(actor, 1);
            }
            break;
        case 4:
            actor->unk54 = actor->unk50;
            func_80102BF8(actor, 0.15f, 5.0f, 120.0f);
            break;
        case 5:
            if (func_80101E14(actor, 0.9f)) {
                func_80800BA4_chbiggafoot(actor);
            }
            break;
        case 6:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 7);
            }
            func_80800C04_chbiggafoot(actor);
            break;
        case 7:
            func_80800C04_chbiggafoot(actor);
            break;
        case 9:
            actor->unk54 = func_80102D78(actor, actor->actorData);
            *(f32 *) &actor->actorData[3] =
                func_800F3780(func_80101F24(actor), D_80801124_chbiggafoot, 3) * 400.0f;
            func_80102B2C(actor, func_800D8FF8() * 100.0f);
            func_8010B990(actor, 0x1005);
    }
    if (((BiggaState *) actor)->st >= 5 && ((BiggaState *) actor)->st < 10) {
        *(f32 *) &actor->actorData[6] += func_800D8FF8() * 400.0f;
        *(f32 *) &actor->actorData[5] =
            func_800F10B4(func_80013970(*(f32 *) &actor->actorData[6]), -1.0f, 1.0f, -0.2f, 0.0f);
        *(f32 *) &actor->actorData[4] =
            func_800F15F8(*(f32 *) &actor->actorData[4], 1.0f, func_800D8FF8());
    }
    pos = actor->position;
    func_800EE7F8(pos_copy, pos);
    if (_sudeflect_entrypoint_0(pos, 140.0f, 160.0f, 10) & 2) {
        _sudeflect_entrypoint_4(9, pos);
    }
    func_800EF1B8(pos_copy, *(f32 *) &actor->unk50, -250.0f);
    func_800EFA4C(unk_1, 0.0f, *(s32 *) &actor->unk50, 0.0f);
    _sudeflect_entrypoint_3(pos_copy, unk_1, D_8080113C_chbiggafoot, D_80801148_chbiggafoot, 2);
    func_80800A9C_chbiggafoot(actor);
}

void func_808004B0_chbiggafoot(s32 arg0)
{
    func_800DA524(FLAG2_6CD_UNK);
}

void func_80800840_chbiggafoot();

// Message handler: dialog, throw (0x3D), flag and camera messages.
s32 func_808004D4_chbiggafoot(Actor *actor, s32 param_1, s32 param_2)
{
    f32 morph_scale;
    Actor *other;
    f32 morph_vec[2];
    f32 *limit;
    f32 throw_pos[3];
    Actor *projectile;
    s32 value;

    switch (param_1) {
        case 0x2E:
            func_80800840_chbiggafoot(actor, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
            break;
        case 0x0B:
            if (param_2 == 0x50) {
                func_800DA544(0x1CC);
                func_800FFAB0(actor);
                _capod_entrypoint_3(0);
                return 4;
            }
            return 3;
        case 0x0E:
            if (param_2 == 0x5A) {
                other = func_80106790(actor->unk3C);
                limit = D_80801154_chbiggafoot;
                do {
                    if (_capod_entrypoint_17(*limit)) {
                        func_8010D930(4, ((BiggaBits *) other)->unk70_0, other->position,
                                      D_8080115C_chbiggafoot);
                        return 3;
                    }
                    limit++;
                } while (limit != (f32 *) D_8080115C_chbiggafoot);
            }
            return 3;
        case 0x3F:
            func_8010A570(actor);
            actor->unk64_20 = 1;
            func_8010D930(1, ((BiggaBits *) actor)->unk70_0, actor->position,
                          D_80801170_chbiggafoot);
            if (!actor->unk64_19) {
                actor->unk64_19 = 1;
                _subaddiedialog_entrypoint_11(actor->unk0, 0x12B1, 0xE, actor->position, 0xA8);
            }
            break;
        case 0x1F:
            value = *(s32 *) &param_2;
            morph_scale = func_800F0D50(
                ((f32 *) actor->actorData)[4] + ((f32 *) actor->actorData)[5], 0, 1.0f);
            morph_vec[1] = morph_scale;
            morph_vec[0] = morph_scale;
            _dbmorph_entrypoint_3(func_800B2768(value), func_80103CB8(actor, value),
                                  func_800B2840(value), 1, morph_vec);
            func_801015D0(actor);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80801188_chbiggafoot, actor->scale);
            break;
        case 0x3D:
            func_800F7F98(func_800F54E4(), 0);
            func_800EE7F8(throw_pos, actor->position);
            func_800EF1B8(throw_pos, actor->unk50 - 40.0f, 100.0f);
            throw_pos[1] += 60.0f;
            projectile = func_80108528(0x44E, (f32 *) actor->actorData,
                                    func_800F1DF4((f32 *) actor->actorData, throw_pos), &actor);
            projectile->unk3C = (Unk80132ED0 *) actor->unk0;
            actor->unk3C = (Unk80132ED0 *) projectile->unk0;
            func_800EE7F8((f32 *) projectile->actorData, throw_pos);
            func_800EE7F8((f32 *) &projectile->actorData[4], (f32 *) actor->actorData);
            projectile->unk58 = ((f32 *) projectile->actorData)[3] =
                func_800EEAD4((f32 *) actor->actorData, throw_pos) / 1600.0f;
            _capod_entrypoint_2(actor->unk0, 0x23, 0);
            _capod_entrypoint_6(projectile->unk0, 0x5A, 0x30);
            break;
        case 0x0A:
            func_80102424(actor, 5);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800840_chbiggafoot(Actor *actor, s32 param_1, s32 param_2)
{
    u8 *sp20;

    *(f32 *) ((u8 *) actor + 0x58) = 1.5f;
    if (param_1 != 0x12B1) {
        if (param_1 == 0x12B2) {
            sp20 = (u8 *) actor + 0x18;
            func_800EE7F8(sp20, (u8 *) actor + 4);
            func_800EF1B8(sp20, *(f32 *) ((u8 *) actor + 0x50), 1e+03f);
            func_80102424(actor, 9);
            _capod_entrypoint_6(*(s32 *) actor, 0x50, 0x2010);
            return;
        }
        func_80102424(actor, 1);
    }
}

void func_808008D4_chbiggafoot(s32 param_0[3])
{
    _subaddiedialog_entrypoint_7(param_0, &param_0[1], &D_80801198_chbiggafoot);
}

s32 func_808008FC_chbiggafoot(Actor *actor)
{
    f32 player_pos[3];
    f32 unk_0;
    void *player;

    if (actor->unk58 > 0.0f) {
        return 0;
    }
    player = func_800F54E4();
    if (!func_800F6478(player)) {
        return 0;
    }
    unk_0 = func_800F5BF0(player, player_pos);
    return func_800F0008(player_pos, unk_0, actor->position, 180.0f);
}

void func_80800980_chbiggafoot(Actor *actor)
{
    f32 player_pos[3];
    if (func_800F6438(func_800F54E4())) {
        func_800F5A00(func_800F54E4(), player_pos);
        actor->unk54 = func_80102D78(actor, player_pos);
        func_80102BF8(actor, 0.15f, 5.0f, 120.0f);
    }
}

s32 func_808009EC_chbiggafoot(Actor *actor)
{
    s32 near_player;

    near_player = func_8010C9B0(actor->position, 0x320);
    func_800DA3B8(0x6CD, near_player);
    if (!near_player) {
        ((f32 *) actor->actorData)[7] = 3.0f;
        return 0;
    }
    if (!func_800F6478(func_800F54E4()))
        return 0;
    if (func_800DA298(0x9FB) && func_800DA298(0x1C7)) {
        return func_800D9078(&actor->actorData[7]);
    }
    return 0;
}

void func_80800A9C_chbiggafoot(s32 param_0)
{
    s32 *s1 = (s32 *) param_0;
    s32 *s0;
    int ret;

    ret = func_801022E4();
    switch (ret) {
        case 0x389:
            s0 = s1 + 1;
            _subaddieaudioquick_entrypoint_3(param_0, s0, &D_808011B4_chbiggafoot, 0x3F400000);
            _subaddieaudioquick_entrypoint_4(param_0, s0, &D_808011D4_chbiggafoot,
                                             &D_808011F4_chbiggafoot);
            _subaddieaudioquick_entrypoint_4(param_0, s0, &D_808011C4_chbiggafoot,
                                             &D_808011E4_chbiggafoot);
            return;
        case 0x38B:
            s0 = s1 + 1;
            _subaddieaudioquick_entrypoint_3(param_0, s0, &D_80801200_chbiggafoot, 0x3DF5C28F);
            _subaddieaudioquick_entrypoint_3(param_0, s0, &D_80801208_chbiggafoot, 0x3F1EB852);
            return;
        case 0x38A:
            _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80801218_chbiggafoot,
                                             0x3EB33333);
    }
}

void func_80800BA4_chbiggafoot(Actor *actor)
{
    func_80102424(actor, 6);
    actor->unk6C_0 = 0;
    actor->unk3C = NULL;
    *(f32 *) &actor->actorData[3] = 1.0f;
    _capod_entrypoint_20(actor->unk0, D_80801030_chbiggafoot[0], 0x10);
    func_80800CDC_chbiggafoot(actor);
}

void func_80800C04_chbiggafoot(Actor *actor)
{
    if (func_800D9078((f32 *) &actor->actorData[3])) {
        actor->unk6C_0++;
        if (actor->unk6C_0 == 4) {
            _capod_entrypoint_20(actor->unk0, 0x7F, 0x10);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x12B2, 6, actor->position, 0xA8);
            func_80102424(actor, 8);
        } else {
            _capod_entrypoint_20(actor->unk0, (s16 *) D_80801030_chbiggafoot[actor->unk6C_0],
                                 0x10);
            func_80800CDC_chbiggafoot(actor);
            *(f32 *) &actor->actorData[3] = 1.0f;
        }
    }
}

void func_80800CDC_chbiggafoot(BiggaS *param_0)
{
    u8 handle = func_800C4350(0, 0, &D_80801224_chbiggafoot);
    func_800C32C4(handle, D_80801038_chbiggafoot[param_0->f]);
    func_800C3BDC(handle);
}

int func_80800D38_chbiggafoot(int param_0)
{
    func_80102FDC(param_0, 1.4f);
}

void func_80800D5C_chbiggafoot(Actor *actor)
{
    s32 timer_done;
    f32 t;
    f32 pos_copy[3];

    timer_done = func_800D9078(&actor->unk58);
    t = func_800F10B4(actor->unk58, 0.0f, *(f32 *) ((u8 *) actor + 0x24), 1.0f, 0.0f);
    func_800EFE50(actor->position, (f32 *) ((u8 *) actor + 0x28), (f32 *) actor->actorData,
                  t);
    func_80800E98_chbiggafoot(actor);
    if (actor->unk70_10 == 1 && timer_done) {
        func_800EE7F8(pos_copy, actor->position);
        _chexploder_entrypoint_3(actor, pos_copy, 0xB);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801238_chbiggafoot);
        func_80101FDC(actor, 2);
        func_8010114C(actor->unk3C, 0xA, 0);
    }
}

s32 func_80800E2C_chbiggafoot(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    if (param_1 == 0x90) {
        local_1 = func_80106790(func_80101080());
        local_0 = local_1;
        _chexploder_entrypoint_9(local_1, 1, 2);
        _chexploder_entrypoint_6(local_0, 0x43C80000, 0x43FA0000);
    } else {
        return 0;
    }
    return 1;
}

// Matching: the old-style parameter list is needed for the match.
void func_80800E98_chbiggafoot(param_0) Actor *param_0;
{
    s32 *local_1;
    s32 *new_var;
    local_1 = (s32 *) ((u8 *) param_0 + 0x38);
    new_var = local_1;
    func_800BBCB8((s32) param_0 + 4, 0, *new_var, 1, &D_80801244_chbiggafoot);
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_80101870();
s16 D_80801030_chbiggafoot[4] = {0x80, 0x81, 0x82, 0x83};
u8 D_80801038_chbiggafoot[4] = {0x40, 0x80, 0xC0, 0xFF};
u32 D_8080103C_chbiggafoot[22] = {
    0x0,        0x0,       0x4148A3D7, 0x3890001, 0x4148A3D7, 0x3890001, 0x3F947AE1, 0x38A0002,
    0x4148A3D7, 0x3890001, 0x40654FDF, 0x38B0002, 0x40654FDF, 0x38B0002, 0x3F400000, 0x38C0001,
    0x3F400000, 0x38C0001, 0x3F400000, 0x38C0001, 0x4148A3D7, 0x3890401};
int D_80801094_chbiggafoot[18] = {0xAB03E6,
                                  0x81E0001,
                                  (u32) &D_8080103C_chbiggafoot,
                                  (u32) func_80800100_chbiggafoot,
                                  (u32) func_80105834,
                                  (u32) func_801018A4,
                                  0x7D00000,
                                  0x3FCCCCCD,
                                  0x0,
                                  0x1840120,
                                  (u32) func_808004B0_chbiggafoot,
                                  (u32) func_80108ED0,
                                  0x0,
                                  (u32) func_80800018_chbiggafoot,
                                  (u32) func_80107C2C,
                                  -0x7FFF8BFE,
                                  (u32) func_808004D4_chbiggafoot,
                                  0x0};
int D_808010DC_chbiggafoot[18] = {0x158044E,
                                  0x8140001,
                                  0x0,
                                  (u32) func_80800D5C_chbiggafoot,
                                  (u32) func_80105834,
                                  (u32) func_80101870,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x4,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80800D38_chbiggafoot,
                                  (u32) func_80107C2C,
                                  -0x7FFFFFFE,
                                  (u32) func_80800E2C_chbiggafoot,
                                  0x0};
u8 D_80801124_chbiggafoot[24] = {0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0, 0x3F, 0x0, 0x0, 0x0,
                                 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0};
u8 D_8080113C_chbiggafoot[12] = {0xC3, 0xC8, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0, 0xC3, 0x48, 0x0, 0x0};
u8 D_80801148_chbiggafoot[12] = {0x43, 0xC8, 0x0, 0x0, 0x43, 0xFA, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0};
f32 D_80801154_chbiggafoot[2] = {0.04f, 0.2f};
u8 D_8080115C_chbiggafoot[20] = {0x0, 0x13, 0x6, 0x1,  0x0,  0xA,  0x0, 0xD9, 0x0, 0x18,
                                 0x0, 0x1,  0x3, 0xE8, 0x13, 0x88, 0x0, 0x0,  0x0, 0x0};
u8 D_80801170_chbiggafoot[24] = {0x0,  0x13, 0x4, 0x17, 0x0, 0xD,  0x1,  0xC,  0x1, 0x26, 0x0, 0x16,
                                 0x65, 0x90, 0x0, 0x1,  0x3, 0x20, 0x13, 0x88, 0x0, 0x0,  0x0, 0x0};
u8 D_80801188_chbiggafoot[16] = {0x43, 0xF,  0x0, 0x0, 0x43, 0x23, 0x0, 0x0,
                                 0x43, 0x23, 0x0, 0x0, 0x42, 0xA3, 0x0, 0x0};
s32 D_80801198_chbiggafoot[7] = {0x1C70190, 0x126F1270, 0x201,    0x12080000,
                                 0xA80000,  0xC063C,    0x2000000};
u8 D_808011B4_chbiggafoot[16] = {0x0, 0x13, 0x5, 0xEC, 0x0, 0xD, 0x0, 0x66,
                                 0x0, 0x80, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_808011C4_chbiggafoot[16] = {0x0, 0x13, 0x4, 0x9C, 0x0,  0xD,  0x0, 0xF3,
                                 0x1, 0xC,  0x0, 0x16, 0x2E, 0xE0, 0x0, 0x0};
u8 D_808011D4_chbiggafoot[16] = {0x0, 0x13, 0x5, 0xBB, 0x0,  0xD,  0x0, 0xF3,
                                 0x1, 0xC,  0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
u8 D_808011E4_chbiggafoot[16] = {0x3E, 0xB3, 0x33, 0x33, 0x3E, 0xCC, 0xCC, 0xCD,
                                 0x3E, 0xEB, 0x85, 0x1F, 0xBF, 0x80, 0x0,  0x0};
u8 D_808011F4_chbiggafoot[12] = {0x3F, 0x0, 0x0, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0xBF, 0x80, 0x0, 0x0};
u8 D_80801200_chbiggafoot[8] = {0x0, 0x13, 0x4, 0xBE, 0x0, 0x0, 0x0, 0x0};
u8 D_80801208_chbiggafoot[16] = {0x0, 0x13, 0x6, 0x1A, 0x0, 0x16, 0x75, 0x30,
                                 0x0, 0xA,  0x0, 0xCC, 0x0, 0x0,  0x0,  0x0};
u8 D_80801218_chbiggafoot[12] = {0x0, 0x13, 0x5, 0xEC, 0x0, 0xD, 0x0, 0xC0, 0x0, 0xD9, 0x0, 0x0};
u8 D_80801224_chbiggafoot[20] = {0x0, 0x13, 0x6, 0x1A, 0x1, 0x6, 0x0, 0x18, 0x0, 0xA,
                                 0x0, 0xCC, 0x0, 0x3,  0x0, 0x2, 0x0, 0x0,  0x0, 0x0};
u8 D_80801238_chbiggafoot[12] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0xA, 0x0, 0xD9, 0x0, 0x2, 0x0, 0x0};
s32 D_80801244_chbiggafoot[11] = {0x1D09DD, 0x161200,  0x150000, 0x4C0022, 0x1990200, 0x1330199,
                                  0x1B012C, 0x2580017, 0x800000, 0x0,      0x0};
