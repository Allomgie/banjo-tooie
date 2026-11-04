// Most likely a Cloud Cuckooland cannon: fires the player along an arc at a target prop, with a
// follow camera. A small companion actor plays a sound when the player steps off it.
#include "common.h"

extern s32 D_80800CF8_chfantasycannon[];
extern s32 func_800B5BE4(s32);
extern void func_800F5A00(u32, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void *func_80100094(Actor *, s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800DC0C0(void);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern int D_80800D30_chfantasycannon[];
extern void *D_80800D78_chfantasycannon;
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800F78EC(s32, f32 *, f32, f32);
int func_808009B8_chfantasycannon();
void func_80800544_chfantasycannon();

// Per-instance first-use flag 0x55D + id: read.
int func_80800000_chfantasycannon(Actor *actor)
{
    func_800DA298(((u32) *(u16 *) ((char *) actor + 0x76) >> 7) + 0x55D);
}

// Per-instance first-use flag 0x55D + id: set.
int func_80800028_chfantasycannon(Actor *actor)
{
    func_800DA544(((u32) *(u16 *) ((char *) actor + 0x76) >> 7) + 0x55D);
}

int func_80800050_chfantasycannon()
{
    s32 player;
    if (!func_8010C500()) {
        return 0;
    }
    player = func_800F54E4();
    if (func_800F64DC(player | 0) == 0) {
        return 0;
    }
    return 1;
}

// Spawns a particle effect at the player, 60 units up.
void func_808000A4_chfantasycannon(void)
{
    f32 pos[3];
    s32 emitter;

    emitter = func_800B5BE4(0x1A);
    func_800F5A00(func_800F54E4(), pos);
    pos[1] += 60.0f;
    func_800BABB8(emitter, pos, NULL, 1.0f, D_80800CF8_chfantasycannon);
}

// Spawn callback: finds the target prop (cube prop 0x47E with matching id) and aims at it.
void func_8080010C_chfantasycannon(Actor *actor)
{
    void *props[20];
    s32 found = 0;
    s32 prop_count;
    s32 i;
    prop_count = _gccubesearch_entrypoint_9(0x47E, props, 20);
    if (!_subaddieDll_entrypoint_1(actor)) {
        func_800FFA88(actor->unk0);
        return;
    }
    for (i = 0; i < prop_count; i++) {
        if (_gspropctrl_entrypoint_8(props[i]) == actor->unk74_7) {
            _gspropctrl_entrypoint_11(props[i], (f32 *) actor->actorData);
            func_800EF1B8((f32 *) actor->actorData,
                          func_800F1DF4((f32 *) actor->actorData, actor->position), -70.0f);
            *(f32 *) ((u8 *) actor + 0x1C) += 60.0f;
            found = 1;
            break;
        }
    }
    if (!found) {
        func_800FFA88(actor->unk0);
        return;
    }
    func_808009B8_chfantasycannon(actor);
    actor->unk64_19 = 0;
}

void func_808008B0_chfantasycannon();

// Cannon state machine: 1 idle, 2 wait, 3 fire anim, 4 flight, 5 landing, 6 reset.
void func_80800228_chfantasycannon(Actor *actor)
{
    s32 pad0;
    f32 pos[3];
    f32 t;

    switch (actor->unk70_10) {
        case 1:
            if (func_80800050_chfantasycannon(actor)) {
                func_80800544_chfantasycannon(actor, 3);
                return;
            }
            _sudeflect_entrypoint_0(actor->position, actor->scale * 226.0f * 0.75f,
                                    actor->scale * 226.0f * 0.75f, 14);
            return;
        case 2:
            if (func_800D90A4(&actor->unk54)) {
                func_80800544_chfantasycannon(actor, 3);
            }
            return;
        case 3:
            if (func_80101E14(actor, 0.47f)) {
                func_800C3F48(0x7FFB5E0D);
                func_80800544_chfantasycannon(actor, 4);
            }
            if (func_80101E14(actor, 0.16f)) {
                func_800F4CEC(func_800F54E4(), 0x2E);
                actor->unk64_20 = 0;
            }
            if (func_80101E14(actor, 0.01f)) {
                func_800C3F48(0x665B5E0C);
            }
            if (func_80101F24(actor) <= 0.3f) {
                t = func_800F10B4(func_80101F24(actor), 0.0f, 0.16f, 0.0f, 1.0f);
                func_800EFE50(pos, (f32 *) &actor->actorData[4], actor->position, t);
                pos[1] += func_80013970(t * 180.0f) * 300.0f;
                func_800F8294(func_800F54E4(), pos);
            }
            break;
        case 4:
            if (func_80101DDC(actor)) {
                func_80800544_chfantasycannon(actor, 5);
            } else if (func_80101F24(actor) >= 0.5f) {
                func_808000A4_chfantasycannon();
                if (!actor->unk64_20 && func_80101E14(actor, 0.5f)) {
                    actor->unk64_20 = 1;
                    func_800F4CC0(func_800F54E4());
                }
            }
            func_800F7B9C(func_800F54E4(), 140);
            func_808008B0_chfantasycannon(actor);
            return;
        case 5:
            func_808000A4_chfantasycannon();
            if (func_800F6C5C(func_800F54E4())) {
                func_80800544_chfantasycannon(actor, 6);
            }
            func_800F7B9C(func_800F54E4(), 140);
            func_808008B0_chfantasycannon(actor);
            return;
        case 6:
            if (func_800D90A4(&actor->unk54)) {
                func_80800544_chfantasycannon(actor, 1);
                return;
            }
            func_808008B0_chfantasycannon(actor);
    }
}

void func_80800544_chfantasycannon(actor, state) Actor *actor;
s32 state;
{
    f32 *cam;
    f32 target[3];
    f32 eye[3];
    s32 ccl_actor;
    f32 speed;
    f32 gravity;
    s32 ccl_actor2;
    f32 target_pos[3];
    f32 offset[3];
    f32 aim_pos[3];
    f32 max_speed;

    cam = func_80100094(actor, 0);
    switch (state) {
        case 1:
            _subaddieDll_entrypoint_4(actor, 0);
            func_800F7F98(func_800F54E4(), 0);
            if (actor->unk64_19) {
                actor->unk64_19 = 0;
                _capod_entrypoint_3(0);
            }
            break;
        case 2:
            actor->unk54 = 1.0f;
            break;
        case 3:
            if (func_800DA298(0x1E1)) {
                ccl_actor = (Actor *) _subaddiefind_entrypoint_2(0x40E, 0);
                if (ccl_actor)
                    func_8010A624(ccl_actor);
            }
            _subaddieDll_entrypoint_4(actor, 1);
            func_8010FFB0(func_800F5EF8(func_800F54E4()), eye, target);
            _capod_entrypoint_2(actor->unk0, 45, 0x10804);
            _capod_entrypoint_8(0);
            _capod_entrypoint_1(eye, target);
            if (func_80800000_chfantasycannon(actor)) {
                func_800EE7F8(cam, eye);
                func_800EE7F8(cam + 3, target);
            }
            func_800F7F98(func_800F54E4(), 1);
            actor->unk64_19 = 1;
            func_800F5A00(func_800F54E4(), (f32 *) &actor->actorData[4]);
            *(s32 *) &actor->unk50 = func_80015184();
            func_80015178(4);
            break;
        case 4:
            if (func_80800000_chfantasycannon(actor)) {
                cam = (f32 *) actor->actorData;
                func_800EEC30(offset, 45.0f, func_800F1DF4(cam, actor->position), 1250.0f);
                func_800EFA4C(target_pos, ((f32 *) actor->actorData)[0] + offset[0],
                              ((f32 *) actor->actorData)[1] + offset[1],
                              ((f32 *) actor->actorData)[2] + offset[2]);
                func_800F8294(func_800F54E4(), target_pos);
                gravity = -1250.0f;
                speed = 50.0f;
            } else {
                gravity = -800.0f;
                func_800EFA4C(aim_pos, actor->position[0], actor->position[1] + 350.0f,
                              actor->position[2]);
                func_800F8294(func_800F54E4(), aim_pos);
                max_speed = 1700.0f;
                speed = max_speed * max_speed -
                          (((f32 *) actor->actorData)[1] - aim_pos[1]) * (gravity + gravity);
                if (speed > 0.0f) {
                    cam = (f32 *) actor->actorData;
                    speed = sqrtf(speed);
                } else {
                    speed = max_speed;
                    cam = (f32 *) actor->actorData;
                }
            }
            func_800F78EC(func_800F54E4(), cam, speed, gravity);
            break;
        case 6:
            actor->unk54 = 0.25f;
            func_80015178(*(s32 *) &actor->unk50);
            func_80800028_chfantasycannon(actor);
            if (func_800DA298(0x1E1)) {
                ccl_actor2 = (Actor *) _subaddiefind_entrypoint_2(0x40E, 0);
                if (ccl_actor2)
                    func_8010A63C(ccl_actor2);
            }
    }
    func_80102424(actor, state);
}

// Updates the follow camera (_capod) while the player is in or flying from the cannon.
void func_808008B0_chfantasycannon(Actor *actor)
{
    f32 unk_0[3];
    f32 unk_1[3];
    f32 player_pos[3];
    f32 *cam;

    cam = func_80100094(actor, 0);
    if (func_80800000_chfantasycannon(actor)) {
        if ((s32) actor->unk70_10 < 4) {
            _capod_entrypoint_1(cam, cam + 3);
        } else {
            func_800A516C(unk_0, actor->actorData, cam + 6);
            _capod_entrypoint_1(cam + 6, unk_0);
        }
    } else {
        func_800F5A00(func_800F54E4(), player_pos);
        func_800EFE50(unk_1, cam + 6, cam,
                      func_800EEB40(player_pos, (f32 *) actor->actorData) /
                          func_800EEB40(actor->position, (f32 *) actor->actorData));
        func_800A516C(unk_0, player_pos, unk_1);
        _capod_entrypoint_1(unk_1, unk_0);
    }
}

int func_808009B8_chfantasycannon(actor)
Actor *actor;
{
    f32 *ray_end;
    f32 offset[3];
    f32 hit[3];
    f32 yaw;
    u8 *out;
    s32 step;
    s32 angle;
    out = (u8 *) func_80100094(actor, 0);
    yaw = func_800F1DF4(actor->position, (f32 *) actor->actorData) - 180.0f;
    step = 5;
    angle = 60;
    ray_end = (f32 *) (out + 0x18);
    do {
        func_800EEC30(offset, func_800DC0C0() * 10.0f + 25.0f, angle + yaw, 2000.0f);
        func_800EE780(ray_end, (f32 *) actor->actorData, offset);
        if (!func_800BEF00(actor->position, ray_end, hit, 0))
            break;
        func_800EEC30(offset, func_800DC0C0() * 10.0f + 25.0f, step * -12 + yaw, 2000.0f);
        func_800EE780(ray_end, (f32 *) actor->actorData, offset);
        if (!func_800BEF00(actor->position, ray_end, hit, 0))
            break;
        step++;
        angle += 12;
    } while (step >= 0);
    func_800EE780(out, ray_end, actor->position);
    func_800EF334((f32 *) out, 0.5f);
}

int chfantasycannon_entrypoint_0()
{
    return (int) D_80800D30_chfantasycannon;
}

void func_80800B84_chfantasycannon()
{
    func_80101870();
}

void func_80800BA4_chfantasycannon(u8 *actor)
{
    *(f32 *) (actor + 0x48) = 0.0f;
    if ((u32) ((u16 *) (actor + 0x76))[0] >> 7 == 0x38) {
        func_800FFAB0();
    }
}

void func_80800BDC_chfantasycannon(Actor *actor)
{
    s32 standing_on;
    standing_on = _plsu_entrypoint_3(actor->unk0);
    if (!standing_on && func_800D90A4(&actor->unk58) && !actor->unk64_20) {
        func_800C3F48(0x731C5699);
        actor->unk58 = 0.5f;
    }
    actor->unk64_20 = !standing_on;
}

int chfantasycannon_entrypoint_1()
{
    return &D_80800D78_chfantasycannon;
}

extern void func_80105834();
extern int func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
u32 D_80800CC0_chfantasycannon[14] = {0x0,        0x0,        0x3F6ED917, 0x3910049,  0x3F6ED917,
                                      0x3910009,  0x402EB852, 0x392004A,  0x402EB852, 0x392000A,
                                      0x3F6ED917, 0x3910049,  0x3F6ED917, 0x3910049};
s32 D_80800CF8_chfantasycannon[14] = {0x1D09DF, 0x161200, 0x1BFC18,  -0x257FFF2, 0x19003C,
                                      0x270000, 0x0,      0x12C0022, 0x400066,   0x190066,
                                      0x150019, 0x80002B, 0x660080,  0x31A0000};
int D_80800D30_chfantasycannon[18] = {0x158047D,
                                      0x8920001,
                                      (u32) &D_80800CC0_chfantasycannon,
                                      (u32) func_80800228_chfantasycannon,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x1F40000,
                                      0x0,
                                      0x0,
                                      0x9,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x240000,
                                      (u32) func_8080010C_chfantasycannon,
                                      (u32) func_80107C2C,
                                      (u32) ((u8 *) boot_thread_stack + 0x1F20),
                                      0x0,
                                      0x0};
void *D_80800D78_chfantasycannon = (void *) 0x0158047E;
static u32 D_80800D78_chfantasycannon_rest[17] = {0x92E0001,
                                                  0x0,
                                                  (u32) func_80800BDC_chfantasycannon,
                                                  (u32) func_80105834,
                                                  (u32) func_80800B84_chfantasycannon,
                                                  0x2580000,
                                                  0x0,
                                                  0x0,
                                                  0x21808,
                                                  0x0,
                                                  (u32) func_80108ED0,
                                                  0x0,
                                                  (u32) func_80800BA4_chfantasycannon,
                                                  (u32) func_80107C2C,
                                                  0x80000402,
                                                  0x0,
                                                  0x0};
