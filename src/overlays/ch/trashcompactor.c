// Most likely the Trash Compactor room: a press that slams down on a player standing under it
// (with a Tannoy warning on first entry), plus a switch and a door it opens.
#include "common.h"

extern int D_80800918_chtrashcompactor[];
extern int D_80800960_chtrashcompactor[];
extern int D_808009A8_chtrashcompactor[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800C87DC(f32 *);
extern void func_80101180(s32, s32, s32);
extern Actor *func_801084B0(s32, Actor **);
extern s32 _capod_entrypoint_14(void);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern u8 D_808009F0_chtrashcompactor[];
extern u8 D_808009FC_chtrashcompactor[];
extern u8 D_80800A0C_chtrashcompactor[];
extern f32 _subaddieaudioloop_entrypoint_8(Actor *, void *, s32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_800187B4(s32, f32, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80104004(Actor *, f32 *, f32 *);

int chtrashcompactor_entrypoint_0(void)
{
    extern int D_808008D0_chtrashcompactor[];
    return (int) &D_808008D0_chtrashcompactor;
}

int chtrashcompactor_entrypoint_1()
{
    return (int) &D_80800918_chtrashcompactor;
}

int *chtrashcompactor_entrypoint_2()
{
    return &D_80800960_chtrashcompactor;
}

int *chtrashcompactor_entrypoint_3()
{
    return &D_808009A8_chtrashcompactor;
}

void func_80800030_chtrashcompactor(u8 *actor)
{
    f32 unk_0[3];

    func_800EE7F8(actor + 0x18, actor + 4);
    func_800EE7F8(actor + 0x28, actor + 4);
    *(f32 *) ((s8 *) actor + 0x2C) = 0.0f;
    if (((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) == 0x32) {
        *(s32 *) ((s8 *) actor + 0x50) = 0x08000000;
    } else {
        *(s32 *) ((s8 *) actor + 0x50) = 0x10000000;
    }
    *(f32 *) ((s8 *) actor + 0x34) = 800.0f;
    func_800C87DC(unk_0);
    _subaddiefade_entrypoint_11(actor, unk_0);
}

void func_808000BC_chtrashcompactor(Actor *actor)
{
    s32 player;
    s32 unk_1;
    s32 has_deflect;
    f32 player_pos[3];

    player = func_800F54E4();
    unk_1 = func_800F64A4(player, 0x10000);
    has_deflect = 0;
    if (!unk_1 && !func_800DA298(0x1A0)) {
        if (func_800F6438(player) && func_800F6478(player) && actor->unk74_7 == 0x33) {
            func_800F5A00(player, player_pos);
            if (player_pos[0] > -2500.0f && player_pos[2] > -800.0f) {
                actor->unk64_19 = 1;
                _capod_entrypoint_13(actor->unk0, 0, 8, 0x10);
                func_80101180(0x3A7, 10, 1);
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1334, 0x44, actor->position, 0xA3);
                func_800DA544(0x1A0);
                func_80101FDC(actor, 2);
                actor->unk58 = 8.0f;
            }
        }
        unk_1 = 1;
    }

    actor->unk54 = _subaddieaudioloop_entrypoint_8(actor, D_808009F0_chtrashcompactor,
                                                     actor->unk70_10 != 1, actor->unk54);
    switch (actor->unk70_10) {
        case 1:
            has_deflect = 1;
            if (!unk_1 && func_80090248() && (func_8008FDC4() & *(s32 *) &actor->unk50) &&
                func_80090150()) {
                func_80090708(2);
                actor->unk64_19 = 1;
                _capod_entrypoint_13(actor->unk0, 0, actor->unk74_7 == 0x32 ? 2 : 4, 0x20);
                func_80101FDC(actor, 3);
                actor->unk58 = 0.45f;
            }
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                actor->unk64_20 = 1;
                func_80101FDC(actor, 3);
                actor->unk58 = 0.45f;
            }
            break;
        case 3: {
            s32 done;
            f32 blend;
            done = func_800D9078(&actor->unk58);
            blend = func_800F12D4(actor->unk58, 0.0f, 0.45f, 1.0f, 0.0f);
            func_800EFE50(actor->position, (f32 *) &actor->actorData[0],
                          (f32 *) &actor->actorData[4], blend);
            if (done) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808009FC_chtrashcompactor);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80800A0C_chtrashcompactor);
                func_800E15CC(2, 80.0f, 0.85f);
                func_800187B4(0, 2.0f, 1.0f, 1.0f);
                func_80101FDC(actor, 4);
                if (!actor->unk64_20) {
                    func_800904C8(0x9A);
                }
                actor->unk58 = 0.85f;
            }
            break;
        }
        case 4: {
            s32 done;
            f32 height;
            done = func_800D9078(&actor->unk58);
            height = func_800F10B4(actor->unk58, 0.0f, 0.85f, 400.0f, 800.0f);
            *(f32 *) &actor->actorData[7] = height;
            if (done) {
                func_80101FDC(actor, 5);
                actor->unk58 = 0.8f;
            }
            break;
        }
        case 5:
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 6);
                actor->unk58 = 0.15f;
            }
            break;
        case 6: {
            s32 done;
            done = func_800D9078(&actor->unk58);
            *(f32 *) &actor->actorData[7] =
                func_800F10B4(actor->unk58, 0.0f, 0.15f, 800.0f, 400.0f);
            if (done) {
                if (!actor->unk64_20) {
                    func_80090708(0);
                    func_800904C8(0x5A);
                    func_80090658(1);
                }
                func_80101FDC(actor, 7);
                actor->unk58 = 1.0f;
            }
            break;
        }
        case 7: {
            s32 done;
            f32 blend;
            done = func_800D9078(&actor->unk58);
            blend = func_800F12D4(actor->unk58, 0.0f, 0.45f, 0.0f, 1.0f);
            func_800EFE50(actor->position, (f32 *) &actor->actorData[0],
                          (f32 *) &actor->actorData[4], blend);
            if (done) {
                if (!actor->unk64_20) {
                    func_80090658(0);
                    if (actor->unk64_19) {
                        _capod_entrypoint_14();
                        actor->unk64_19 = 0;
                    }
                }
                actor->unk64_20 = 0;
                func_80101FDC(actor, 8);
                actor->unk58 = 3.5f;
            }
            break;
        }
        case 8:
            has_deflect = 1;
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 1);
            }
    }

    if (actor->unk3C) {
        Actor *linked;
        linked = func_80106790(actor->unk3C);
        func_800EE7F8(linked->position, actor->position);
        linked->position[1] += *(f32 *) &actor->actorData[7];
    }
    if (has_deflect) {
        f32 corner_a[3];
        f32 corner_b[3];
        func_80104004(actor, corner_a, corner_b);
        func_800EF04C(corner_a, actor->position);
        func_800EF04C(corner_b, actor->position);
        _sudeflect_entrypoint_2(corner_a, corner_b, 10);
    }
}

s32 func_80800684_chtrashcompactor(Actor *actor, s32 event, s32 value)
{
    Actor *linked;
    switch (event) {
        case 0x3D:
            linked = func_801084B0(0x3B5, &actor);
            if (linked) {
                func_80108944(linked, actor);
                linked->position[1] += *(f32 *) ((u8 *) actor + 0x34);
                actor->unk3C = linked->unk0;
            }
            break;
        case 0x95:
            actor->unk3C = 0;
            func_80108B04(actor, 0);
            if (!func_800DA298(0x1A0))
                func_80101180(0x3A7, 10, 0);
            break;
        case 0xB:
            if (value == 8)
                actor->unk64_19 = 0;
            return 3;
        case 0x9F:
            if (actor->unk64_19) {
                _capod_entrypoint_14();
                actor->unk64_19 = 0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808007A4_chtrashcompactor(s32 actor)
{
    _chswitch_entrypoint_7(actor, 0x9F5);
    _chswitch_entrypoint_8(actor, 0x200);
    _chswitch_entrypoint_9(actor);
}

s32 func_808007DC_chtrashcompactor(void *this, s32 next_state)
{
    if (next_state == 7) {
        func_80101180(0x3B7, 7, 0);
    } else {
        _chswitch_entrypoint_10(this, next_state);
    }
}

void func_8080081C_chtrashcompactor(Actor *actor)
{
    f32 unk_0[3];
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 200.0f, 1, 0x9F5)) {
        _chdoormake_entrypoint_9(actor, 0, 0, 0x10);
        _chdoormake_entrypoint_8(actor, 0xC);
    }
    func_800C87DC(unk_0);
    _subaddiefade_entrypoint_11(actor, unk_0);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80102EC0();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
int D_808008D0_chtrashcompactor[18] = {0x31903B4,
                                       0x7460001,
                                       0x0,
                                       (u32) func_808000BC_chtrashcompactor,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x400,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800030_chtrashcompactor,
                                       (u32) func_80107C2C,
                                       -0x7FF7FBEE,
                                       (u32) func_80800684_chtrashcompactor,
                                       0x0};
int D_80800918_chtrashcompactor[18] = {0x31A03B5,
                                       0x7470001,
                                       0x0,
                                       (u32) func_80102EC0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x404,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80107C2C,
                                       -0x7FF7F7EE,
                                       0x0,
                                       0x0};
int D_80800960_chtrashcompactor[18] = {0x34303B6,
                                       0x7B80001,
                                       (u32) &D_8011A270,
                                       (u32) _chswitch_entrypoint_6,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x40000808,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_808007A4_chtrashcompactor,
                                       (u32) func_80107C2C,
                                       -0x7FF7D3EE,
                                       (u32) func_808007DC_chtrashcompactor,
                                       0x0};
int D_808009A8_chtrashcompactor[18] = {0xAC03B7,
                                       0x7A30001,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x20800,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080081C_chtrashcompactor,
                                       (u32) func_80107C2C,
                                       -0x7FF7DBEE,
                                       (u32) _chdoor_entrypoint_1,
                                       0x0};
u8 D_808009F0_chtrashcompactor[12] = {0x0, 0x0, 0x0, 0x0, 0x44, 0x7A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_808009FC_chtrashcompactor[16] = {0x0, 0x13, 0x4, 0xCE, 0x0, 0xD, 0x0, 0xC0,
                                      0x0, 0xD9, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0};
u8 D_80800A0C_chtrashcompactor[36] = {
    0x0, 0x13, 0x4, 0xDC, 0x0, 0xC, 0x0, 0x0, 0x0, 0xD9, 0x1, 0x4C, 0x1, 0x19, 0x0, 0x15, 0x0, 0x0,
    0x0, 0xD9, 0x0, 0x33, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
