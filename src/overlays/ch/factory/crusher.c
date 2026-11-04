// Grunty Industries wall crusher: two wall halves slam together while the player is in the
// corridor, with shake, rumble and sound, until FLAG_329 is set. A second actor is the chswitch.
#include "common.h"

extern int D_80800A50_chfactorycrusher[];
extern int D_80800A98_chfactorycrusher[];
extern void *func_80100094(Actor *, u32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F0E00(f32, f32);
extern s32 func_800F54E4(void);
extern Actor *_subaddiefind_entrypoint_1(Actor *, s32, s32, s32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800F4D18(u32, f32 *, f32 *);
extern void func_800EFE50(u8 *, u8 *, u8 *, f32);
extern u8 D_80800AE0_chfactorycrusher[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern s32 func_800E148C(s32, f32, f32);
extern f32 mlAbsF(f32);
extern s32 func_80018820(s32, f32, f32);
s32 func_80800898_chfactorycrusher();
s32 func_80800738_chfactorycrusher();

// TU-NOTE: the .data tables below are defined in C so IDO schedules the functions as in the original.
// Crusher wall pair: cycle, player squash/eject, collision boxes.
int chfactorycrusher_entrypoint_0()
{
    return &D_80800A50_chfactorycrusher;
}

// Switch that sets FLAG_329 (crusher off) and announces it.
int chfactorycrusher_entrypoint_1()
{
    return (int) &D_80800A98_chfactorycrusher;
}

void func_80800018_chfactorycrusher(Actor *actor)
{
    s32 i;
    f32 box_min[3];
    f32 box_max[3];
    f32 *bounds;

    func_800EE7F8(actor->actorData, actor->position);
    func_800EE7F8((u8 *) actor + 0x28, actor->position);
    func_800EF1B8((f32 *) ((u8 *) actor + 0x28), actor->rotation[1], 500.0f);
    actor->unk58 = 0.0f;
    func_8010A63C(actor);
    bounds = func_80100094(actor, 0);
    if (func_80104004(actor, box_min, box_max)) {
        func_800EF934(box_min, box_min, actor->rotation[1]);
        func_800EF934(box_max, box_max, actor->rotation[1]);
        for (i = 0; i < 3; i++) {
            bounds[i] = func_800F13F0(box_min[i], box_max[i]);
            bounds[i + 3] = func_800F0E00(box_min[i], box_max[i]);
        }
    }
    if (actor->unk74_7 != 0x32) {
        func_80101FDC(actor, 6);
        func_80103110(actor, 0);
    }
}

void func_808008F0_chfactorycrusher();

void func_808008B8_chfactorycrusher(u8 *param_0, f32 param_1);

void func_808006CC_chfactorycrusher();

void func_80800150_chfactorycrusher(Actor *actor)
{
    u8 *data;
    Actor *partner;
    f32 player_pos[3];
    s32 in_corridor;
    s32 slam_done;
    f32 cam_pos[3];
    s32 cutscene_id;
    s32 player;
    f32 shake_scale;
    s32 retract_done;

    data = func_80100094(actor, 0);
    partner = func_80800898_chfactorycrusher(actor);
    switch (actor->unk70_10) {
        case 1:
            if (!func_800DA298(0x329) && !actor->unk64_19 && !*(s32 *) (data + 0x18) &&
                func_800D90A4(&actor->unk58)) {
                actor->unk64_20 = 0;
                in_corridor = func_80800738_chfactorycrusher(actor, player_pos);
                if (in_corridor) {
                    if (func_800F64A4(func_800F54E4(), 0x10000) ||
                        func_800F5578(func_800F54E4()) >= 2) {
                        cutscene_id = ((f32 *) actor->actorData)[0] < player_pos[0] ? 0x22 : 0x1E;
                        _capod_entrypoint_13(actor->unk0, 0, cutscene_id, 0);
                        actor->unk64_19 = 1;
                    }
                    player = func_800F54E4();
                    func_800F7F98(player, 1);
                    actor->unk64_20 = 1;
                    func_80101180(0x3EE, 0xB9, 0);
                    func_8010A624(actor);
                    func_8010A624(partner);
                }
                func_80101FDC(actor, 2);
                actor->unk58 = 0.25f;
            }
            ((f32 *) actor->actorData)[7] = 0.0f;
            break;
        case 2:
            slam_done = func_800D9078(&actor->unk58);
            ((f32 *) actor->actorData)[7] =
                func_800F12D4(actor->unk58, 0.0f, 0.25f, 1.0f, 0.0f);
            func_808008B8_chfactorycrusher(actor, ((f32 *) actor->actorData)[7]);
            func_808008B8_chfactorycrusher(partner, ((f32 *) actor->actorData)[7]);
            if (actor->unk64_20) {
                func_808008F0_chfactorycrusher(actor);
            }
            if (slam_done) {
                if (actor->unk74_7 == 50) {
                    func_800E148C(func_800E1610(2, 80.0f, 0.85f, (f32 *) actor->actorData + 4),
                                  2000.0f, 8000.0f);
                    func_8010D640(cam_pos);
                    shake_scale =
                        (800.0f / func_800F0E00(800.0f, mlAbsF(cam_pos[2] - 4000.0f))) * 2.75f;
                    if (shake_scale > 0.25f) {
                        func_80018820(0, shake_scale, 0.35f);
                    }
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800AE0_chfactorycrusher);
                }
                func_80800800_chfactorycrusher(actor);
                func_80101FDC(actor, 3);
                actor->unk58 = 0.35f;
            }
            break;
        case 3:
            if (func_800D90A4(&actor->unk58)) {
                func_80101FDC(actor, 4);
                actor->unk58 = 1.5f;
            }
            ((f32 *) actor->actorData)[7] = 1.0f;
            break;
        case 4:
            retract_done = func_800D9078(&actor->unk58);
            ((f32 *) actor->actorData)[7] = func_800F12D4(actor->unk58, 0.0f, 1.5f, 0.0f, 1.0f);
            func_808008B8_chfactorycrusher(actor, ((f32 *) actor->actorData)[7]);
            func_808008B8_chfactorycrusher(partner, ((f32 *) actor->actorData)[7]);
            if (retract_done) {
                func_80101FDC(actor, 1);
                actor->unk58 = actor->unk64_20 ? 2.0f : 0.0f;
                actor->unk64_20 = 0;
            }
            break;
        case 5:
            func_808008B8_chfactorycrusher(actor, ((f32 *) actor->actorData)[7]);
            func_808008B8_chfactorycrusher(partner, ((f32 *) actor->actorData)[7]);
    }
    if (!actor->unk64_19) {
        func_808006CC_chfactorycrusher(actor);
        func_808006CC_chfactorycrusher(partner);
        if (!actor->unk64_20) {
            func_8010A654(actor, actor->unk7C_12);
            func_8010A654(partner, partner->unk7C_12);
        }
    }
}

s32 func_80800580_chfactorycrusher(Actor *actor, s32 msg, s32 arg)
{
    u8 *data;
    Actor *partner;

    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x95:
            partner = _subaddiefind_entrypoint_1(actor, 0x3BA, -1, 0);
            if (partner) {
                actor->unk3C = partner->unk0;
            }
            *(s32 *) (data + 0x18) = 0;
            break;
        case 11:
            if (arg == 0x1E || arg == 0x22) {
                partner = func_80800898_chfactorycrusher(actor);
                actor->unk64_19 = 0;
                partner->unk64_19 = actor->unk64_19;
                func_800F7F98(func_800F54E4(), 0);
                func_80101180(0x3EE, 0xBA, 0);
            }
            return 3;
        default:
            return 0;
    }
    return 1;
}

void func_8080067C_chfactorycrusher(s32 param_0, s32 param_1)
{
    f32 cam_pos[3];

    func_800E3980(cam_pos);
    if (cam_pos[2] > 2500.0f) {
        func_80101870(param_0, param_1);
    }
}

void func_808006CC_chfactorycrusher(Actor *actor)
{
    f32 *bounds;
    f32 box_min[3];
    f32 box_max[3];

    bounds = func_80100094(actor, 0);
    func_800EE780(box_min, bounds, actor->position);
    func_800EE780(box_max, bounds + 3, actor->position);
    func_800F4D18(func_800F54E4(), box_min, box_max);
}

// Is the player in the crusher corridor?
s32 func_80800738_chfactorycrusher(actor, player_pos)
Actor *actor;
f32 *player_pos;
{
    if (!func_800F6478(func_800F54E4()))
        return 0;
    func_800F5A00(func_800F54E4(), player_pos);
    if (player_pos[0] > -2350.0f && player_pos[0] < 3550.0f && player_pos[2] > 3400.0f &&
        player_pos[2] < 4600.0f)
        return 1;
    return 0;
}

// Squash or eject the player while the walls slam together.
int func_80800800_chfactorycrusher(Actor *actor)
{
    s32 *data;
    s32 player;
    data = func_80100094(actor, 0);
    if (actor->unk64_20) {
        player = func_800F54E4();
        if (func_800F5578(player) == 1 && !func_800F64A4(player, 0x10000)) {
            func_800F7F98(player, 0);
            data[6] = 1;
        }
        func_800F7B9C(player, 0x5C);
        return 1;
    }
    return 0;
}

s32 func_80800898_chfactorycrusher(this) Actor *this;
{
    func_80106790(this->unk3C);
}

void func_808008B8_chfactorycrusher(u8 *base, f32 t)
{
    func_800EFE50(base + 4, base + 0x18, base + 0x28, t);
}

void func_808008F0_chfactorycrusher(Actor *actor)
{
    f32 partner_z;
    f32 own_z;
    f32 player_pos[3];
    s32 player;
    Actor *partner;

    player = func_800F54E4();
    partner = (Actor *) func_80800898_chfactorycrusher(actor);
    own_z = actor->position[2];
    partner_z = partner->position[2];
    func_800F5A00(player, player_pos);

if (player_pos[2] < partner_z) {
    player_pos[2] = partner_z;
    func_800F8418(player, player_pos);
} else if (own_z < player_pos[2]) {

player_pos[2] = own_z;
func_800F8418(player, player_pos);
}
}

s32 func_80800984_chfactorycrusher(Actor *this)
{
    _chswitch_entrypoint_7(this, 0x329);
    _chswitch_entrypoint_8(this, 1);
    _chswitch_entrypoint_9(this);
}

int func_808009BC_chfactorycrusher(s32 param_0[4], unsigned int msg)
{
    if (msg == 7) {
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(param_0[0], 0x1340, 4, param_0 + 1, 0xA3);
        return 1;
    }
    _chswitch_entrypoint_10(param_0);
}

extern void func_80105834();
extern void func_80107C2C();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern int func_80101870();
int D_80800A50_chfactorycrusher[18] = {0x31F03BA,
                                       0x74A0001,
                                       0x0,
                                       (u32) func_80800150_chfactorycrusher,
                                       (u32) func_80105834,
                                       (u32) func_8080067C_chfactorycrusher,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x20000400,
                                       0x0,
                                       0x0,
                                       0x1C0000,
                                       (u32) func_80800018_chfactorycrusher,
                                       (u32) func_80107C2C,
                                       -0x7FF7FBFE,
                                       (u32) func_80800580_chfactorycrusher,
                                       0x0};
int D_80800A98_chfactorycrusher[18] = {0x34303BB,
                                       0x9420001,
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
                                       (u32) func_80800984_chfactorycrusher,
                                       (u32) func_80107C2C,
                                       -0x7FF7D3EE,
                                       (u32) func_808009BC_chfactorycrusher,
                                       0x0};
u8 D_80800AE0_chfactorycrusher[32] = {0x0,  0x13, 0x4, 0xCE, 0x0,  0xD,  0x0,  0xC0, 0x0, 0xD9, 0x0,
                                      0x18, 0x0,  0x1, 0x7,  0xD0, 0x1F, 0x40, 0x0,  0x0, 0x0,  0x0,
                                      0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0};
