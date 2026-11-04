#include "common.h"

extern s32 D_808008F4_chtorpedo[];
extern s32 D_80800918_chtorpedo[];
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern u8 D_808008B4_chtorpedo[];
extern u8 D_80800840_chtorpedo[];
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_800EFA98(f32 *, f32 *, f32);
extern u8 D_80800950_chtorpedo[];
extern s32 func_800C8A98(void);
extern void func_800C8E54(s32, f32, f32);
extern void func_80109BEC(f32 *, f32, s32, s32, s32, Unk80132ED0 *);
extern s32 func_8010CC10(f32 *, f32);
extern void *func_80100094(Actor *, u32);
extern void func_800F7A7C(s32, s32, s32, s32, f32 *);
extern void _chlightfader_entrypoint_1(s32, f32, s32);
typedef struct {
    s8 unk_0;
    u8 pad_1[0x13];
    f32 last_pos[3];
    f32 age;
} ActorLocal_Torpedo;
extern f32 func_800D8FF8(void);
extern void _sumissilehome_entrypoint_6(Actor *, ActorLocal_Torpedo *);
extern s32 func_8010B990(Actor *, s32);
extern void func_8010AA78(f32 *);
extern void func_8010A590(Actor *);
extern void func_800CB840(s32, Actor *);
extern s32 func_800CD820(Unk80132ED0 *, f32 *, f32 *, f32);
extern void func_800CB870(void);
extern void func_8010A570(Actor *);
extern s32 func_8010D350(f32 *, f32 *, f32, s32);
extern void func_800FFAB0(Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void _sumissilehome_entrypoint_2(Actor *, void *, f32);
extern void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
typedef struct {
    u8 pad_0[0x28];
    s32 active;
    void (*callback)(Unk80132ED0 *, s32, s32);
    s32 argument;
} TorpedoEvents;
extern int D_8080095C_chtorpedo[];

// Spawns a bubble trail under water, smoke above.
void func_80800000_chtorpedo(Actor *actor, u8 *local)
{
    f32 *pos;

    pos = actor->position;
    if (actor->position[1] < *(f32 *) (local + 0x24)) {
        func_800BABB8(_fxairbub_entrypoint_1(pos, 5.0f, actor->position[1] + 200.0f, 1.0f),
                      pos, 0, 1.0f, D_808008F4_chtorpedo);
    } else {
        func_800BABB8(_fxdlsmoke_entrypoint_0(pos), pos, 0, 1.0f, D_80800918_chtorpedo);
    }
}

void func_808000B8_chtorpedo(Actor *actor)
{
    u8 *local;
    f32 trail_pos[3];

    local = func_80100094(actor, 0);
    if (!*(s32 *) (local + 0x28)) {
        func_800E1610(0, 20.0f, 0.6f, actor->position);
        func_800EFA98(trail_pos, (f32 *) ((u8 *) actor + 0x28), -70.0f);
        func_800EF04C(trail_pos, actor->position);
        func_800BABB8(0, trail_pos, 0, 1.0f, (s32 *) D_808008B4_chtorpedo);
        func_800EFA98(trail_pos, (f32 *) ((u8 *) actor + 0x28), -50.0f);
        func_800EF04C(trail_pos, actor->position);
        if (actor->position[1] < *(f32 *) (local + 0x24)) {
            func_800BABB8(_fxairbub_entrypoint_1(trail_pos, 100.0f, trail_pos[1] + 200.0f, 1.0f),
                          trail_pos, actor->position, 1.0f, (s32 *) D_80800840_chtorpedo);
        }
    }
}

// State change; entering 3 explodes: light flash, area damage, knockback.
void func_808001E0_chtorpedo(Actor *actor, s32 new_state)
{
    s32 light;
    s32 target;
    f32 knock_dir[3];

    if (new_state == actor->unk70_10)
        return;
    func_80101FDC();
    if (actor->unk70_10 == 3) {
        light = func_800C8A98();
        func_800C8E84(light, D_80800950_chtorpedo);
        func_800C8CB8(light, actor->position);
        func_800C8E54(light, 300.0f, 750.0f);
        func_800CB840(6, actor);
        func_80109BEC(actor->position, 150.0f, 2, 0, 0, actor->unk0);
        if (func_8010CC10(actor->position, 150.0f)) {
            func_800EFA98(knock_dir, (f32 *) ((u8 *) actor + 0x28), -200.0f);
            func_800EF04C(knock_dir, actor->position);
            func_8010CCE0();
            target = func_8010CCEC();
            while (target != -1) {
                func_800F7A7C(target, *(s8 *) func_80100094(actor, 0), 1, 7, knock_dir);
                target = func_8010CCEC();
            }
        }
        _chlightfader_entrypoint_1(light, 1.0f, 1);
        func_800CB870();
        func_808000B8_chtorpedo(actor);
    }
}

int func_80800350_chtorpedo(s32 actor)
{
    f32 dir[2];
    func_800F1A88(actor + 0x28, dir);
    *(f32 *) ((char *) actor + 0x44) = -dir[0];
    *(f32 *) ((char *) actor + 0x48) = dir[1];
}

void func_80800394_chtorpedo(s32 actor)
{
    Actor *local;
    char *local_bytes;
    local = func_80100094(actor, 0);
    local_bytes = (char *) local;
    if (*(s32 *) ((char *) local + 0x2C) != 0) {
        (*(void (*)(s32, s32, s32)) * (s32 *) (local_bytes + 0x2C))(*(s32 *) ((char *) actor + 0x0),
                                                                5, *(s32 *) (local_bytes + 0x30));
    }
}

void func_808003DC_chtorpedo(Actor *this)
{
    f32 timer;
    f32 dt;
    s32 hit;
    s32 msg;
    s32 done;
    ActorLocal_Torpedo *local;
    s32 pad;

    local = func_80100094(this, 0);
    timer = local->age;
    dt = func_800D8FF8();
    switch (this->unk70_10) {
        case 2:
            _sumissilehome_entrypoint_6(this, local);
            msg = func_8010B990(this, 0x100004);
            if (msg == 0x20) {
                func_8010AA78(this->position);
            }
            func_80800350_chtorpedo(this);
            this->rotation[2] += dt * 1200.0f;
            func_80800000_chtorpedo(this, local);
            func_8010A590(this);
            func_800CB840(6, this);
            hit = func_800CD820(this->unk0, local->last_pos, this->position, 40.0f);
            func_800CB870();
            func_8010A570(this);
            done = (hit != 0);
            if (func_8010D350(local->last_pos, this->position, 40.0f, local->unk_0) != -1) {
                done = 1;
            }
            if (msg == 0x20 || done || 3.0f < timer) {
                func_808001E0_chtorpedo(this, 3);
            }
            break;
        case 3:
            func_800FFAB0(this);
    }
    local->age = timer + dt;
    func_800EE7F8(local->last_pos, this->position);
}

// Spawns the torpedo (actor 0x168); callback is invoked with argument on message 0x78.
void *chtorpedo_entrypoint_0(f32 *spawn_pos, f32 *param_1, f32 *rotation, s32 callback, s32 argument,
                             f32 water_level)
{
    Actor *torpedo;
    f32 hit_pos[3];
    u8 *local;
    f32 dir[3];
    if (func_800C6A7C(param_1, spawn_pos, hit_pos, 0x20020)) {
        func_800EFB24(dir, param_1, spawn_pos);
        func_800EF368(dir, 1.0f);
        func_800EF04C(spawn_pos, dir);
    }
    torpedo = (Actor *) func_80108474(0x168, spawn_pos, 0);
    local = (u8 *) func_80100094(torpedo, 0);
    if (1) {
    }
    *(f32 *) ((u8 *) torpedo + 0x34) = 0.0f;
    func_800EE7F8((u8 *) torpedo + 0x28, rotation);
    func_80800350_chtorpedo(torpedo);
    func_800EE7F8(local + 0x14, spawn_pos);
    *(f32 *) (local + 0x20) = 0.0f;
    *(s32 *) (local + 0x2C) = callback;
    *(s32 *) (local + 0x30) = argument;
    *(f32 *) (local + 0x24) = water_level;
    *(s32 *) (local + 0x28) = 0;
    func_8010A570(torpedo);
    _sumissilehome_entrypoint_0(torpedo, local);
    _sumissilehome_entrypoint_3(torpedo, local, argument);
    if (func_800EA05C() == 0x181)
        _sumissilehome_entrypoint_1(torpedo, local, 0x1C7);
    else if (func_800EA068(0x20))
        _sumissilehome_entrypoint_4(torpedo, local, 1);
    _sumissilehome_entrypoint_2(torpedo, local, 4000.0f);
    _sumissilehome_entrypoint_5(torpedo, local, 4000.0f, 1200.0f);
    func_808001E0_chtorpedo(torpedo, 2);
    return torpedo->unk0;
}

s32 func_80800720_chtorpedo(Actor *actor, s32 msg, s32 param_2)
{
    TorpedoEvents *events;
    events = (TorpedoEvents *) func_80100094(actor, 0);
    switch (msg) {
        case 0x2C:
            events->callback = 0;
            func_800FFAB0(actor);
            return 1;
        case 5:
            func_808001E0_chtorpedo(actor, 3);
            return 1;
        case 0x95:
            func_80109EEC(actor, 0x10);
            return 1;
        case 0x78:
            if (events->callback) {
                events->callback(actor->unk0, 0x78, events->argument);
                events->callback = 0;
            }
            func_800FFAB0(actor);
            return 1;
        case 0x98:
            events->active = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

int *chtorpedo_entrypoint_1()
{
    return &D_8080095C_chtorpedo;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800840_chtorpedo[116] = {
    0x0,  0xC,  0x0,  0x23, 0x0,  0x2B, 0x2,  0x0,  0x2,  0x80, 0x0,  0x2D, 0x0,  0x14, 0x0,
    0x28, 0x0,  0x22, 0x0,  0x14, 0x0,  0x1E, 0x0,  0x23, 0x0,  0x30, 0x4,  0x1A, 0x0,  0xC,
    0x0,  0x2D, 0x0,  0x2B, 0x1,  0x80, 0x2,  0x0,  0x0,  0x2D, 0x0,  0x32, 0x0,  0x46, 0x0,
    0x22, 0x0,  0x21, 0x0,  0x26, 0x0,  0x2E, 0x0,  0x3A, 0x6,  0x1A, 0x0,  0xC,  0x0,  0x37,
    0x0,  0x2B, 0x1,  0x0,  0x1,  0x80, 0x0,  0x2D, 0x0,  0x46, 0x0,  0x50, 0x0,  0x22, 0x0,
    0x28, 0x0,  0x35, 0x0,  0x40, 0x0,  0x4C, 0x7,  0x1A, 0x0,  0xC,  0x0,  0x3C, 0x0,  0x2D,
    0x0,  0x50, 0x0,  0x5A, 0x0,  0x2B, 0x0,  0x80, 0x1,  0x0,  0x0,  0x22, 0x0,  0x3D, 0x0,
    0x40, 0x0,  0x4A, 0x0,  0x59, 0x8,  0x1A, 0x0,  0x0,  0x0,  0x0};
u8 D_808008B4_chtorpedo[64] = {
    0x6, 0x10, 0x0,  0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x32, 0x0, 0x2,
    0x0, 0x16, 0x10, 0x0,  0x0, 0x1E, 0x0, 0x1E, 0x0, 0x1E, 0x0, 0xE,  0x0, 0x32, 0x0, 0x3C,
    0x0, 0x19, 0x0,  0x0,  0x0, 0x0,  0x0, 0x22, 0x0, 0x99, 0x0, 0xCC, 0x1, 0x80, 0x2, 0x0,
    0x0, 0x2A, 0x0,  0x8,  0x0, 0x8,  0x0, 0xB3, 0x0, 0xB3, 0x0, 0xF,  0x0, 0x0,  0x0, 0x0};
s32 D_808008F4_chtorpedo[9] = {0x2B0066,  0x8C0022, 0xC000C,  0x1C001C, 0x2CFFD8,
                               -0x270028, 0x280028, 0x28011A, 0x0};
s32 D_80800918_chtorpedo[14] = {0x220033,  0x660100,   0x166002B, 0x730073, 0x180000,
                                0x132600,  0x26000022, 0x260033,  0x9900B3, 0x2CFFD8,
                                -0x270028, 0x280028,   0x28011A,  0x0};
u8 D_80800950_chtorpedo[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x40};
int D_8080095C_chtorpedo[21] = {0x27A0168,
                                0x6270001,
                                0x0,
                                (u32) func_808003DC_chtorpedo,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x0,
                                0x0,
                                0x4,
                                (u32) func_80800394_chtorpedo,
                                (u32) func_80108ED0,
                                0x340000,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800720_chtorpedo,
                                0x0,
                                0x0,
                                0x0,
                                0x0};
