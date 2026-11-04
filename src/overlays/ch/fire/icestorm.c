// Hailfire Peaks dragon brothers' barrage: while a brother is undefeated, a controller rains
// fireballs or ice rocks (actor 0x4FD) on the player, with camera shake and burst particles.
#include "ch/fireicestorm.h"

extern int D_80800EA8_chfireicestorm[];
extern u32 D_80800EF0_chfireicestorm[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
typedef struct {
    u32 pad : 11;
    u32 flag : 1;
    u32 pad2 : 20;
} IceStormBits;
extern void func_800EF368(f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    s32 f0;
    u8 pad[0x60];
    u32 pad64 : 11;
    u32 flag : 1;
    u32 rest : 20;
} StormState;
extern void _subaddiedialog_entrypoint_11(s32, s32, s32, s32, s32);
extern s32 D_80800F38_chfireicestorm[];
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
typedef struct {
    u8 pad0[0x1A];
    u16 unk1A_5 : 11;
    u16 pad1A : 5;
    u8 pad1C[8];
    u32 unk24_22 : 10;
    u32 pad24 : 22;
} StormHit;
extern f32 D_80800F4C_chfireicestorm[];
extern u8 D_80800F54_chfireicestorm[];
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_9(Actor *, s32, s32);
extern void _subaddiefade_entrypoint_3(Actor *);
extern s32 func_800F6438(s32);
extern s32 func_800F6478(s32);
extern void func_800F7B9C(s32, s32);
extern s32 _capod_entrypoint_17(f32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern void func_800FFAB0(Actor *);
typedef struct {
    u8 pad0[4];
    f32 position[3];
    u8 pad10[0x64 - 0x10];
    u32 unk64_21 : 11;
    u32 unk64_20 : 1;
    u32 unk64_19 : 1;
    u32 unk64_0 : 19;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
} IceStorm;
extern s32 D_80800F68_chfireicestorm[];
extern s32 D_80800F7C_chfireicestorm[];
extern void _chexploder_entrypoint_3(IceStorm *, f32 *, s32);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern void func_80101FDC(IceStorm *, s32);
extern u8 D_80800F94_chfireicestorm[];
extern void func_800BBCB8(s32, s32, s32, s32, void *);
extern s32 D_80800FCC_chfireicestorm[];
extern s32 D_80800FFC_chfireicestorm[];
extern void func_80103140(Actor *, u16, u16);
typedef struct Mass45StormFlags {
    u32 local_0 : 11;
    u32 local_1 : 1;
    u32 local_2 : 20;
} Mass45StormFlags;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern u8 D_80800E94_chfireicestorm[];
extern u8 D_80800E80_chfireicestorm[];
void func_8080048C_chfireicestorm();
void func_80800558_chfireicestorm();
Actor *func_808007EC_chfireicestorm();
int func_80800940_chfireicestorm();
int func_80800980_chfireicestorm();
int func_808009C8_chfireicestorm();
void func_80800D0C_chfireicestorm();
void func_80800DC8_chfireicestorm();
void func_80800E08_chfireicestorm();
Actor *func_80800608_chfireicestorm();

int chfireicestorm_entrypoint_0(void)
{
    return (int) &D_80800EA8_chfireicestorm;
}

int chfireicestorm_entrypoint_1()
{
    return (int) &D_80800EF0_chfireicestorm;
}

void func_80800018_chfireicestorm(Actor *actor)
{
    s32 pad[2];
    u32 is_ice;
    f32 marker_pos[3];
    s32 defeated_flag;
    s32 intro_flag;

    func_800DA524(0x9FB);
    if (actor->unk74_7 != 0x32) {
        actor->unk64_20 = 1;
    } else {
        actor->unk64_20 = 0;
    }
    is_ice = actor->unk64_20;
    defeated_flag = is_ice ? 0x1D5 : 0x1D6;
    intro_flag = is_ice ? 0x43E : 0x43F;
    if (func_800A9C98()) {
        func_800DA524(defeated_flag);
        func_800DA544(intro_flag);
    }
    if (func_800DA298(defeated_flag)) {
        func_800FFAB0(actor);
        return;
    }
    if (func_800A9C98()) {
        actor->unk58 = 5.0f;
    } else {
        actor->unk58 = 30.0f;
    }
    if (func_800DA298(intro_flag)) {
        func_80800558_chfireicestorm(actor, 3);
    }
    actor->unk64_19 = func_800DA298(0x49) != 0 || actor->unk64_20 != 0;
    if (!actor->unk64_19) {
        _subaddiemarker_entrypoint_1(actor, 0x320, 0x32, marker_pos, 1);
        func_800EE7F8((f32 *) &actor->actorData[0], marker_pos);
        _subaddiemarker_entrypoint_1(actor, 0x320, 0x33, marker_pos, 1);
        func_800EE7F8((f32 *) &actor->actorData[4], marker_pos);
    }
}

void func_808001CC_chfireicestorm(Actor *actor)
{
    s32 player;
    s32 dialog_id;
    player = func_800F54E4();
    if (func_800F6478(player) && !((s32) ((u32) func_800F55FC(player) << 2) < 0)) {
        switch (actor->unk70_10) {
            case 1:
                if (func_800D90A4(&actor->unk58) && _subaddiedialog_entrypoint_16()) {
                    if (((IceStormBits *) ((u8 *) actor + 0x64))->flag) {
                        dialog_id = 0x12D0;
                    } else {
                        dialog_id = 0x12CF;
                    }
                    if (func_80800980_chfireicestorm(actor, dialog_id, 4)) {
                        func_80800940_chfireicestorm(actor);
                        func_80800558_chfireicestorm(actor, 2);
                    }
                }
                break;
            case 3:
                if (func_800D9078(&actor->unk58)) {
                    func_80800940_chfireicestorm(actor);
                    func_80800558_chfireicestorm(actor, 4);
                }
                break;
            case 4:
                if (!func_800DA298(0x6CD) && !func_800A9C98()) {
                    if (func_800D9078(&actor->unk58)) {
                        func_80800558_chfireicestorm(actor, 3);
                        return;
                    }
                    if (func_800D9078((f32 *) ((u8 *) actor + 0x24)) &&
                        !func_808009C8_chfireicestorm(actor)) {
                        func_80108B04(actor, 0);
                        *(f32 *) ((u8 *) actor + 0x24) = func_800DC178(3.0f, 4.0f);
                    }
                }
        }
    }
}

void func_80800360_chfireicestorm(s32 arg0)
{
    func_800DA524(FLAG3_9FB_UNK);
}

s32 func_80800384_chfireicestorm(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x2E:
            switch (*(s16 *) &arg) {
                case 0x12CF:
                    func_800DA544(0x43F);
                    break;
                case 0x12D0:
                    func_800DA544(0x43E);
                    break;
            }
            func_80800558_chfireicestorm(actor, 4);
            return 1;
        case 0x3D:
            switch (arg) {
                case 0:
                    if (!func_800DA298(0x6CD)) {
                        func_80800608_chfireicestorm(actor);
                    }
                    break;
                case 1:
                    func_808007EC_chfireicestorm(actor);
                    break;
            }
            break;
        case 0x95:
            func_8080048C_chfireicestorm(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080048C_chfireicestorm(actor) Actor *actor;
{
    s32 remove_self;
    s32 swap_mesh;
    s32 entrance;
    void *mesh_a;
    void *mesh_b;

    remove_self = 0;
    swap_mesh = 0;
    entrance = func_800EA090();
    if (actor->unk64_20) {
        if (entrance == 6)
            remove_self = 1;
        if (entrance == 10) {
            remove_self = 1;
            swap_mesh = 1;
        }
    }
    if (swap_mesh) {
        mesh_a = func_800BEA88(0);
        mesh_b = func_800BEA88(1);
        if (mesh_a)
            _idworldmake_entrypoint_1(mesh_a, 0x596, 1, 1);
        if (mesh_b)
            _idworldmake_entrypoint_1(mesh_b, 0x65E, 2, 1);
    }
    if (remove_self)
        func_800FFAB0(actor);
}

// Switches the controller state.
void func_80800558_chfireicestorm(actor, state) Actor *actor;
s32 state;
{
    s32 flag_value = 0;

    func_80101FDC(actor, state);
    switch (state) {
        case 3:
            if (func_800A9C98())
                actor->unk58 = 5.0f;
            else
                actor->unk58 = 30.0f;
            break;
        case 4:
            flag_value = 1;
            actor->unk58 = 15.0f;
            ((f32 *) actor->actorData)[3] = func_800DC178(3.0f, 4.0f);
    }
    func_800DA3B8(0x9FB, flag_value);
}

// Spawns a rock 2500 units above the player.
Actor *func_80800608_chfireicestorm(actor)
Actor *actor;
{
    Actor *rock;
    f32 player_pos[3];
    f32 spawn_pos[3];

    func_800F5BF0(func_800F54E4(), player_pos);
    func_800EE7F8(spawn_pos, player_pos);
    spawn_pos[0] += func_800DC178(-100.0f, 100.0f);
    spawn_pos[1] += 2500.0f;
    spawn_pos[2] += func_800DC178(-100.0f, 100.0f);
    rock = func_80108528(0x4FD, spawn_pos, 0, &actor);
    rock->unk64_20 = ((Mass45StormFlags *) ((u8 *) actor + 0x64))->local_1;
    func_80102FDC(rock, func_800DC178(0.95f, 1.25f));
    func_800EFB24((f32 *) &rock->actorData[4], player_pos, spawn_pos);
    func_800EF368((f32 *) &rock->actorData[4], func_800DC178(2750.0f, 3250.0f));
    func_800EFA4C((f32 *) rock->actorData, func_800DC178(50.0f, 100.0f), 0.0f,
                  func_800DC178(5.0f, 10.0f));
    func_80103140(rock, ((Mass45StormFlags *) ((u8 *) actor + 0x64))->local_1 ? 0x814 : 0x815,
                  *(u16 *) ((u8 *) rock->unk0 + 0x16));
    func_8010D930(4, *(u32 *) ((u8 *) rock + 0x70) & 1, spawn_pos,
                  ((Mass45StormFlags *) ((u8 *) rock + 0x64))->local_1
                      ? D_80800E94_chfireicestorm
                      : D_80800E80_chfireicestorm);
    return actor;
}

Actor *func_808007EC_chfireicestorm(actor)
Actor *actor;
{
    Actor *rock;
    f32 *velocity;
    f32 target_pos[2];
    f32 start_pos[3];

    func_800EE7F8(start_pos, actor->actorData);
    func_800EE7F8(target_pos, &actor->actorData[4]);
    rock = (Actor *) func_80108528(0x4FD, start_pos, 0, &actor);
    *(void **) ((u8 *) rock + 0x3C) = actor->unk0;
    rock->unk64_20 = 0;
    rock->unk64_19 = 1;
    func_80102FDC(rock, 2.0f);
    func_8010A570(rock);
    _subaddieDll_entrypoint_0(rock);
    velocity = (f32 *) &rock->actorData[4];
    func_800EFB24(velocity, target_pos, start_pos);
    func_800EF368(velocity, 2000.0f);
    func_800EFA4C((f32 *) rock->actorData, func_800DC178(50.0f, 100.0f), 0.0f,
                  func_800DC178(5.0f, 10.0f));
    func_80103140(rock, 0x815, *(u16 *) ((u8 *) rock->unk0 + 0x16));
    if (!rock->unk64_19)
        func_8010D930(4, *(u32 *) ((u8 *) rock + 0x70) & 1, start_pos,
                      (s32 *) D_80800E80_chfireicestorm);
    _capod_entrypoint_13(rock->unk0, 0, 0x27, 0x10);
    return actor;
}

int func_80800940_chfireicestorm(actor)
s32 actor;
{
    func_800C3FF0(0x605, 0x3F4CCCCD, 0x7FFF);
    func_800C3FF0(0x604, 0x3F800000, 0x7FFF);
}

int func_80800980_chfireicestorm(state, dialog_id, arg)
StormState *state;
s32 dialog_id;
s32 arg;
{
    s32 speaker;

if (state->flag) {
    speaker = 0x75;
} else {

speaker = 0x76;
}
_subaddiedialog_entrypoint_11(state->f0, dialog_id, arg, 0, speaker);
}

int func_808009C8_chfireicestorm(actor)
Actor *actor;
{
    if (actor->unk64_19)
        return 0;
    if (func_800DA298(0xA24)) {
        func_80101FDC(actor, 5);
        func_80108B04(actor, 1);
        actor->unk64_19 = 1;
        return 1;
    }
    return 0;
}

void func_80800A40_chfireicestorm(void *actor)
{
    struct {
        char pad[0x58];
        float unk58;
    } *tmp = actor;
    tmp->unk58 = 8.0f;
}

void func_80800A50_chfireicestorm(Actor *actor)
{
    s32 hit;
    f32 velocity[3];
    f32 new_pos[3];
    f32 rot_delta[3];
    f32 hit_normal[3];
    f32 dt;

if (actor->unk70_10 == 1) {
    dt = func_800D8FF8();
    func_800EFA20(velocity, (f32 *) &actor->actorData[4], dt);
    func_800EE780(new_pos, actor->position, velocity);
    hit = func_800C6A7C(actor->position, new_pos, hit_normal, 0x20020);
    func_800EE7F8(actor->position, new_pos);
    if (actor->unk64_19)
        _subaddieaudioloop_entrypoint_5(actor, actor->position, 1, 1500,
                                        &D_80800F38_chfireicestorm);
    if (hit) {
        if (actor->unk64_19)
            func_80101180(0x4A4, 0x40, 0);
        func_80800D0C_chfireicestorm(actor);
    } else if (func_800D9078(&actor->unk58)) {
        _subaddiefade_entrypoint_3(actor);
    }
    func_800EFA20(rot_delta, (f32 *) actor->actorData, dt);
    func_800EF04C(actor->rotation, rot_delta);
    if (actor->unk64_20)
        func_80800E08_chfireicestorm(actor);
    else
        func_80800DC8_chfireicestorm(actor);
}

}

s32 func_80800BA4_chfireicestorm(Actor *actor, s32 msg, StormHit *hit_info)
{
    Actor *rock;
    s32 player;
    s32 i;
    StormHit *hit;
    StormHit **hit_ref;

    hit_ref = &hit_info;

switch (msg) {
    case 0x90:
        rock = func_80106790(func_80101080());
        _chexploder_entrypoint_9(rock, 1, 2);
        _subaddiefade_entrypoint_3(rock);
        return 1;
    case 0x3E:
        hit = hit_info;
        func_80800D0C_chfireicestorm(actor);
        if (hit->unk24_22 == 0) {
            player = hit->unk1A_5;
            if (func_800F6438(player) && func_800F6478(player)) {
                func_800F7B9C(player, 0x51);
            }
        }
        break;
    case 0xE:
        for (i = 0; i < 2; i++) {
            if (_capod_entrypoint_17(D_80800F4C_chfireicestorm[i])) {
                func_8010D930(4, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                              D_80800F54_chfireicestorm);
                return 3;
            }
        }
        return 3;
    case 0xB:
        func_80800558_chfireicestorm(func_80106790(actor->unk3C), 4);
        func_800FFAB0(actor);
        return 3;
    default:
        return 0;
}

return 1;
}

// Rock explosion: debris, camera shake, rumble, sound.
void func_80800D0C_chfireicestorm(actor) IceStorm *actor;
{
    s32 particle_count;

    particle_count = 20;

if (!actor->unk64_19) {
    particle_count = 28;
}

_chexploder_entrypoint_3(actor, actor->position, particle_count);
func_800E1610(2, 150.0f, 0.85f, actor->position);
func_80018820(0, 2.0f, 0.3f);
func_8010D930(4, actor->unk70 & 1, actor->position,
              actor->unk64_20 ? &D_80800F68_chfireicestorm : &D_80800F7C_chfireicestorm);
func_80101FDC(actor, 2);
}

void func_80800DC8_chfireicestorm(actor) u8 *actor;
{
    func_800BBCB8(actor + 4, 0, (*(s32 *) ((char *) (actor) + 0x38)), 1,
                  &D_80800F94_chfireicestorm);
}

void func_80800E08_chfireicestorm(actor) Actor *actor;
{
    func_800BBCB8((s32) actor + 4, 0, *(s32 *) ((char *) actor + 0x38), 1,
                  &D_80800FCC_chfireicestorm);
    func_800BBCB8((s32) actor + 4, 0, *(s32 *) ((char *) actor + 0x38), 2,
                  &D_80800FFC_chfireicestorm);
}

extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
extern void func_80101870();
extern void func_80108EE8();
u8 D_80800E80_chfireicestorm[20] = {0x0, 0x13, 0x6, 0x1, 0x0, 0xD,  0x0,  0xF3, 0x1, 0xC,
                                    0x0, 0x18, 0x0, 0x1, 0x3, 0xE8, 0x13, 0x88, 0x0, 0x0};
u8 D_80800E94_chfireicestorm[20] = {0x0, 0x13, 0x6, 0x3, 0x0, 0xD,  0x0,  0xF3, 0x1, 0xC,
                                    0x0, 0x18, 0x0, 0x1, 0x3, 0xE8, 0x13, 0x88, 0x0, 0x0};
int D_80800EA8_chfireicestorm[18] = {0x15804FC,
                                     0x1,
                                     0x0,
                                     (u32) func_808001CC_chfireicestorm,
                                     (u32) func_80102EC0,
                                     (u32) func_8010A730,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800360_chfireicestorm,
                                     0x0,
                                     0x0,
                                     (u32) func_80800018_chfireicestorm,
                                     (u32) func_80107C2C,
                                     -0x7FFFD9FE,
                                     (u32) func_80800384_chfireicestorm,
                                     0x0};
u32 D_80800EF0_chfireicestorm[18] = {0x15804FD,
                                     0xFFFF0001,
                                     0x0,
                                     (u32) func_80800A50_chfireicestorm,
                                     (u32) func_80102EC0,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x4,
                                     0x0,
                                     (u32) func_80108EE8,
                                     0x0,
                                     (u32) func_80800A40_chfireicestorm,
                                     (u32) func_80107C2C,
                                     0x0,
                                     (u32) func_80800BA4_chfireicestorm,
                                     0x0};
s32 D_80800F38_chfireicestorm[5] = {0x130483, 0x163E80, 0xE0133, 0x1700180, 0x0};
f32 D_80800F4C_chfireicestorm[2] = {0.07f, 0.2f};
u8 D_80800F54_chfireicestorm[20] = {0x0, 0x13, 0x6, 0x1,  0x0,  0xA,  0x0, 0xD9, 0x0, 0x18,
                                    0x0, 0x1,  0x3, 0xE8, 0x13, 0x88, 0x0, 0x0,  0x0, 0x0};
s32 D_80800F68_chfireicestorm[5] = {0x1305B8, 0x180001, 0x4E209C4, 0xD0133, 0x14C0000};
s32 D_80800F7C_chfireicestorm[6] = {0x130607, 0xD00F3, 0x10C0016, 0x6D600001, 0x4E209C4, 0x0};
u8 D_80800F94_chfireicestorm[56] = {
    0x0, 0x1D, 0x9, 0xCE, 0x0,  0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15,
    0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99,
    0x0, 0x2B, 0x0, 0x8C, 0x0,  0x8C, 0x0,  0x1B, 0x1, 0x2C, 0x1, 0x2C, 0x0, 0x18,
    0x0, 0x0,  0x0, 0x0,  0x19, 0x0,  0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0, 0x0};
s32 D_80800FCC_chfireicestorm[12] = {0x1D09DD,  0x161200, 0x320002, 0x150000,  0x990022, 0x1990200,
                                     0x1330199, 0x2B008C, 0x8C001B, 0x12C012C, 0x170080, 0x0};
s32 D_80800FFC_chfireicestorm[13] = {0x1D09E0, 0x161200,  0xE0060,  0x600015,   0x190099,
                                     0x220100, 0x1000066, 0x660027, -0x18FFE70, -0x31FFCE0,
                                     0x2B004C, 0x800000,  0x0};
