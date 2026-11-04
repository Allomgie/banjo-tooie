#include "common.h"

// Grunty Industries robots: scanning head turret (entrypoint_0), route-walking robot that
// zaps the player and explodes when hit (entrypoint_1), and the group controller (entrypoint_2).

#define W64(p) (((FRFlags *) (p))->b29)
extern int D_80802928_chfactoryrobot[];
extern int D_80802970_chfactoryrobot[];
extern void *D_808029B8_chfactoryrobot;
extern f32 _subaddieaudioloop_entrypoint_8(Actor *, f32 *, s32, f32);
extern int func_80107070(Actor *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800D93A0(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x70];
    u32 local_0 : 7;
    u32 pad_1 : 15;
    u32 local_1 : 6;
    u32 pad_2 : 4;
} FactoryRobotFlags;
typedef struct {
    u8 pad_0[0x72];
    u16 pad_1 : 6;
    u16 local_0 : 6;
    u16 pad_2 : 4;
} FactoryRobotAnimation;
extern Actor *func_80106790();
extern void func_80103110(Actor *, s32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, u8 *);
extern u8 D_80802A38_chfactoryrobot[], D_80802A00_chfactoryrobot[], D_80802A6C_chfactoryrobot[],
    D_80802A7C_chfactoryrobot[];
extern f32 func_800D8FF8(void);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern void *func_80100094();
extern void func_8010A3E8(Actor *, f32);
extern s32 func_80105138(Actor *, f32 *, f32, f32, f32 *);
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad_0[8];
    u8 local_0[2];
    u8 pad_1[0xA];
    s32 local_1;
} FactoryRobotAudio;
typedef struct Mass44RobotFlags {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} Mass44RobotFlags;
typedef struct RobotSoundLimits {
    f32 local_0;
    f32 local_1;
} RobotSoundLimits;
typedef struct RobotSoundState {
    u8 pad_0[8];
    u8 local_0[2];
    u8 pad_1[10];
    s32 local_1;
    u8 pad_2[8];
    f32 local_2;
} RobotSoundState;
extern RobotSoundLimits D_80802ACC_chfactoryrobot;
extern f32 func_800136E4(f32);
extern void func_800E0AFC(s32, u8, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x18];
    s16 local_0;
    u8 pad_1[6];
    f32 local_1;
} FactoryRobotDelayState;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} FactoryRobotControl;
extern s32 D_80802AD4_chfactoryrobot[];
extern void func_800CD1E0(s32, f32 *, f32);
extern u8 func_800D731C(s32);
extern void *func_800E8C58(u8);
extern void func_800DBE60(u8, s32, void *);
typedef union {
    s16 value;
    struct {
        u16 initialized : 1;
        u16 pad_0 : 15;
    } bits;
} RobotState1438;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 26, disabled : 1, pad_2 : 5;
    u8 pad_3[2];
    RobotState1438 state;
} FactoryRobotFlags1436;
typedef struct {
    Unk80132ED0 *markers[4];
    u8 count;
} FactoryRobotLinks1436;
typedef struct {
    u8 pad0[0x78];
    u32 pad78 : 26;
    u32 unk78_5 : 1;
    u32 pad78_0 : 5;
} RobotActor;
typedef struct {
    s32 unk0[4];
    u8 unk10;
    u8 pad11;
    u8 unk12;
    u8 unk13;
} RobotData_80802470_chfactoryrobot;
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_80101FDC(Actor *, s32);
extern void func_800FC660(s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800F4F34(s32, f32 *, f32, f32);
typedef struct {
    f32 pos[2];
    u8 unk8;
    u8 unk9;
    u8 padA[0xA];
    s32 unk14;
    s16 unk18;
    u8 pad1A[2];
    f32 unk1C;
    f32 unk20;
    u8 pad24[4];
    f32 unk28;
    u8 pad2C[8];
    u8 unk34[4];
} RobotData_80800920_chfactoryrobot;
typedef struct {
    u8 pad0[0x64];
    u32 pad64_30 : 2;
    u32 unk64_29 : 1;
    u32 pad64_0 : 29;
    u8 pad68[8];
    u32 pad70_1 : 31;
    u32 unk70_0 : 1;
    u8 pad74[4];
    u32 pad78_3 : 29;
    u32 unk78_2 : 1;
    u32 pad78_0 : 2;
} RobotBits;
extern f32 D_80802AAC_chfactoryrobot[];
extern f32 D_80802A9C_chfactoryrobot[];
extern f32 D_80802A8C_chfactoryrobot[];
extern u8 D_80802890_chfactoryrobot[][12];
extern u8 _subaddieaudioloop_entrypoint_6(u8, f32 *, s32, s32, f32 *, s32);
extern void func_800C31DC(u8, f32);
extern s32 func_800D9078(f32 *);
extern s32 func_8010CFBC(f32 *, s32, s32);
extern s32 func_800F54E4(void);
extern s32 func_800F7B9C(s32, s32);
extern void func_800F57F0(s32, f32 *);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
extern void func_800C8CB8(s32, f32 *);
extern s32 func_800DC298(f32);
extern void func_800C8E84();
extern void func_800C8FE0(s32, s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EE88C(f32 *, f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void _subaddieDll_entrypoint_1(Actor *);
extern void _subaddierouteDll_entrypoint_3(Actor *, u8 *, f32 *);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern void func_80107200(Actor *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, f32 *, f32);
extern s32 func_80101DDC(Actor *);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 D_80802AB8_chfactoryrobot[];
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_80102D78(Actor *, u32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
typedef struct {
    u8 pad0[6];
    s16 f6;
    u8 pad8[0x10];
    s16 st;
    u8 pad1A[2];
    f32 f1C;
    u8 pad20[4];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34[3];
} FRobot;
typedef struct {
    u8 pad[0x64];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 b29 : 1;
    u32 rest : 29;
} FRFlags;
typedef struct {
    u8 pad_0[0x14];
    s32 handle;
    u8 pad_1[8];
    f32 timer;
} RobotWaitState;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 enabled : 1;
    u32 pad_2 : 29;
} RobotEnabledState;
extern u8 D_80802AEC_chfactoryrobot[];
extern void _sudialog_entrypoint_0(s32, s32);
extern s32 func_800F00A4(s32, f32, f32, f32, s32);
extern void func_80108B04();
extern s32 func_8010D23C(void);
extern s32 func_8010C500();
extern s32 func_8008FDC4(void);
extern void _chmrtannoy_entrypoint_0(void);
extern void func_800D1254(s32, s32, s32 *);
extern void _subaddieaudioquick_entrypoint_2();
extern void func_800DA544(s32);
extern void func_800D2498(s32, s32, s32);
extern s32 func_800F1418(s32, s32);
extern s32 D_80802AF4_chfactoryrobot[];
extern void func_800E8D28(s32, f32);
typedef union {
    s32 local_0;
    s16 local_1[2];
} FactoryRobotMessage36;
void func_80800424_chfactoryrobot();
void func_80800508_chfactoryrobot();
void func_808005D4_chfactoryrobot();
void func_8080183C_chfactoryrobot();
int func_80801C50_chfactoryrobot();
int func_80802398_chfactoryrobot();
s32 func_80802470_chfactoryrobot();
int func_808025D4_chfactoryrobot();
void func_80801160_chfactoryrobot();
s32 func_80801278_chfactoryrobot();
s32 func_80801BB0_chfactoryrobot();

int *chfactoryrobot_entrypoint_0()
{
    return &D_80802928_chfactoryrobot;
}

int chfactoryrobot_entrypoint_1()
{
    return (int) &D_80802970_chfactoryrobot;
}

void *chfactoryrobot_entrypoint_2(void)
{
    return &D_808029B8_chfactoryrobot;
}

void func_80800024_chfactoryrobot(u8 *actor)
{
    *(f32 *) ((s8 *) actor + 0x2C) = 0.0f;
    *(f32 *) ((s8 *) actor + 0x34) = 0.0f;
    *(f32 *) ((s8 *) actor + 0x30) = 20.0f;
    func_80105010();
}

int func_808006DC_chfactoryrobot(Actor *param_0, f32 param_1, f32 param_2);

void func_80800264_chfactoryrobot();

// Scanning head: sweeps left/right and turns towards the player when it sees them.
void func_80800058_chfactoryrobot(Actor *actor)
{
    f32 front_pos[3];
    f32 *pos;
    f32 player_pos[2];
    f32 aim_angles[2];

    pos = actor->position;
    func_800EE7F8(front_pos, pos);
    func_800EF1B8(front_pos, actor->rotation[1], 40.0f);
    func_800F4F34(func_800F54E4(), front_pos, 30.0f, 100.0f);
    switch (actor->unk70_10) {
        case 1:
            func_80800264_chfactoryrobot(actor);
            actor->unk54 = 50.0f;
            actor->unk50 = 20.0f;
            if (func_808006DC_chfactoryrobot(actor, 1.0f, 15.0f)) {
                ((f32 *) actor->actorData)[0] = func_800DC178(1.0f, 1.2f);
                func_80101FDC(actor, 2);
            }
            break;
        case 2:
            func_80800264_chfactoryrobot(actor);
            if (func_800D9078(actor->actorData)) {
                func_80101FDC(actor, 3);
            }
            break;
        case 3:
            func_80800264_chfactoryrobot(actor);
            actor->unk54 = -50.0f;
            actor->unk50 = 20.0f;
            if (func_808006DC_chfactoryrobot(actor, 1.0f, 15.0f)) {
                ((f32 *) actor->actorData)[0] = func_800DC178(1.0f, 1.2f);
                func_80101FDC(actor, 4);
            }
            break;
        case 4:
            func_80800264_chfactoryrobot(actor);
            if (func_800D9078(actor->actorData)) {
                func_80101FDC(actor, 1);
            }
            break;
        case 5:
            func_80800264_chfactoryrobot(actor);
            func_8010D254(player_pos);
            func_800F18FC(pos, player_pos, aim_angles);
            actor->unk54 = aim_angles[1] - actor->rotation[1];
            actor->unk50 = -aim_angles[0];
            func_808006DC_chfactoryrobot(actor, 4.0f, 40.0f);
            if (actor->unk58 == 0.0f) {
                func_80101FDC(actor, 3);
            }
    }
}

void func_80800264_chfactoryrobot(Actor *actor)
{
    func_800D9078(&actor->unk58);
    if (_subaddierouteDll_entrypoint_4(actor) && func_8010D248() && func_8010C500(actor)) {
        actor->unk58 = 4.0f;
    }
    _subaddieDll_entrypoint_4(actor, actor->unk58 > 0.0f ? 1 : 0);
    *(f32 *) &actor->actorData[4] = _subaddieaudioloop_entrypoint_8(
        actor, actor->position, actor->unk58 > 0.0f, *(f32 *) &actor->actorData[4]);
    if (actor->unk70_10 != 5 && actor->unk58 > 0.0f) {
        func_80101FDC(actor, 5);
    }
}

s32 func_80800360_chfactoryrobot(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x40:
            *(s32 *) ((u8 *) func_80106790(*(s32 *) ((u8 *) actor + 0x3C)) + 0x3C) = 0;
            func_808005D4_chfactoryrobot(actor);
            func_80107070(actor, 3);
            break;
        case 0x1F:
            func_80800424_chfactoryrobot(actor, *(s32 *) &arg);
            break;
        case 0x8F:
            if (*(s32 *) &arg == 0) {
                func_80800508_chfactoryrobot(actor);
            }
            break;
        case 0x95:
            func_80800508_chfactoryrobot(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800424_chfactoryrobot(actor, arg) Actor *actor;
s32 arg;
{
    s32 unk_0;
    f32 euler[3];
    f32 quat[4];

    unk_0 = func_801040D0();
    func_801015D0(actor);
    func_800DF41C(unk_0);
    func_800EFA4C(euler, 0.0f, *(f32 *) ((u8 *) actor + 0x2C), 0.0f);
    func_800D93A0(quat, euler);
    func_800DFF2C(unk_0, 0x12, quat);
    func_800EFA4C(euler, *(f32 *) ((u8 *) actor + 0x30), 0.0f, 0.0f);
    func_800D93A0(quat, euler);
    func_800DFF2C(unk_0, 0x6C, quat);
    func_800AE1E8((s16) *(u16 *) &actor->unk0->unk10, func_800B27E0(arg), unk_0);
    func_800DF72C(func_800AE080((s16) *(u16 *) &actor->unk0->unk10));
}

void func_80800508_chfactoryrobot(actor) Actor *actor;
{
    Actor *robot;

    _subaddiefind_entrypoint_10(actor, 0x3BF, actor->unk74_7);
    robot = func_80106790(actor->unk3C);
    robot->unk3C = actor->unk0;
    func_80101FDC(robot, 1);
    func_80103110(robot, 1);
    ((FactoryRobotFlags *) actor)->local_0 = ((FactoryRobotFlags *) robot)->local_0;
    if (((FactoryRobotFlags *) robot)->local_1) {
        ((FactoryRobotAnimation *) actor)->local_0 = ((FactoryRobotFlags *) robot)->local_1;
    } else {
        ((FactoryRobotAnimation *) actor)->local_0 = 1;
    }
    func_80107200(actor);
}

void func_808005D4_chfactoryrobot(Actor *actor)
{
    f32 pos[3];
    f32 explode_pos[3];

    func_800EE7F8(pos, actor->position);
    func_800EF214(pos, -actor->rotation[0], actor->rotation[1], 20.0f);
    func_800BBCB8(pos, actor->position, 1.0f, 8, D_80802A38_chfactoryrobot);
    func_800BBCB8(pos, actor->position, 1.0f, 0xC, D_80802A00_chfactoryrobot);
    func_8010D930(6, *(u32 *) ((u8 *) actor + 0x70) & 1, pos, D_80802A6C_chfactoryrobot);
    _subaddieaudioquick_entrypoint_2(actor, pos, D_80802A7C_chfactoryrobot);
    func_800EE7F8(explode_pos, actor->position);
    func_800EF1B8(explode_pos, actor->rotation[1], -50.0f);
    _chexploder_entrypoint_3(actor, explode_pos, 0);
}

int func_808006DC_chfactoryrobot(Actor *actor, f32 min_speed, f32 max_speed)
{
    f32 dt;

    dt = func_800D8FF8();
    actor->unk54 = func_800F0D50(func_80013728(actor->unk54), -80.0f, 80.0f);
    actor->unk50 = func_800F0D50(func_80013728(actor->unk50), -60.0f, 60.0f);
    ((f32 *) actor->actorData)[5] =
        func_800F1FF0(((f32 *) actor->actorData)[5], actor->unk54, 0.15f, (dt * min_speed),
                      (dt * max_speed));
    ((f32 *) actor->actorData)[6] =
        func_800F1FF0(((f32 *) actor->actorData)[6], actor->unk50, 0.15f, (dt * min_speed),
                      (dt * max_speed));
    return func_800F20BC(((f32 *) actor->actorData)[5], actor->unk54, 4.0f);
}

void func_808007C4_chfactoryrobot(Actor *actor)
{
    u8 *data = func_80100094(actor, 0);

    f32 ground_y;

    func_8010A3E8(actor, 0.4f);
    func_8010A590(actor);
    func_800EE940(data, actor->position);
    *(f32 *) (data + 16) = *(f32 *) (data + 12) = *(f32 *) ((u8 *) actor + 0x48);
    *(f32 *) (data + 0x28) = 1.0f;
    *(f32 *) (data + 0x24) = 0.0f;
    func_800EE7F8(actor->actorData, actor->position);
    if ((*(u32 *) ((u8 *) actor + 0x78) << 26) >> 31) {
        if (func_80105138(actor, actor->position, 0.0f, -500.0f, &ground_y))
            *(s16 *) (data + 2) = (s32) ground_y;
        _subaddieDll_entrypoint_1(actor);
        _subaddierouteDll_entrypoint_3(actor, data + 0x34, actor->position);
        func_80107200(actor);
        func_80801160_chfactoryrobot(actor, 3);
        *(s16 *) (data + 6) = (s32) func_800DC178(100.0f, 200.0f);
    } else {
        func_80801160_chfactoryrobot(actor, 1);
        *(f32 *) &actor->actorData[1] += 300.0f;
        actor->unk64_24 = 0;
        actor->unk58 = 1.0f;
    }
}

void func_80801C7C_chfactoryrobot();

s32 func_80801A80_chfactoryrobot();

// Walking robot update: audio, electric arc at close range, route state machine.
void func_80800920_chfactoryrobot(Actor *actor)
{
    RobotData_80800920_chfactoryrobot *data;
    s32 arc_done;
    f32 player_pos[3];
    f32 blend;
    f32 route_pos[3];
    s32 timer_done;

    data = func_80100094(actor, 0);
    if (((RobotBits *) actor)->unk78_2) {
        return;
    }
    data->unk9 = _subaddieaudioloop_entrypoint_6(
        data->unk9, actor->position, 0.0f < data->unk20, -1, D_80802AAC_chfactoryrobot,
        ((RobotBits *) actor)->unk70_0);
    data->unk8 = _subaddieaudioloop_entrypoint_6(data->unk8, actor->position, 1, -1,
                                                    D_80802A9C_chfactoryrobot,
                                                    ((RobotBits *) actor)->unk70_0);
    if (data->unk8) {
        func_800C31DC(data->unk8, data->unk28);
    }
    func_800D9078(&data->unk1C);
    arc_done = func_800D9078(&data->unk20);
    if (0.0f < data->unk20) {
        if (data->unk1C == 0.0f &&
            func_8010CFBC(actor->position, actor->scale * 80.0f, actor->scale * 175.0f) &&
            func_800F7B9C(func_800F54E4(), 0x51) == 2) {
            if (((RobotBits *) actor)->unk64_29) {
                data->unk1C = 1.5f;
            } else {
                data->unk1C = 6.0f;
            }
            data->unk18 = ((RobotBits *) actor)->unk64_29;
            data->unk20 = 0.4f;
            func_800F57F0(func_800F54E4(), player_pos);
            _chelectricfence_entrypoint_1(actor, player_pos);
        }
        func_800C8CB8(data->unk14, actor->position);
        func_800C8E84(data->unk14, D_80802890_chfactoryrobot[func_800DC298(0.35f)]);
    } else if (arc_done) {
        func_800C8FE0(data->unk14, 0);
    }
    switch (actor->unk70_10) {
        case 1:
            timer_done = func_800D9078(&actor->unk58);
            blend = func_800F12D4(actor->unk58, 0.0f, 1.0f, 1.0f, 0.0f);
            func_800EE88C(route_pos, data->pos);
            func_800EFE50(actor->position, route_pos, (f32 *) actor->actorData, blend);
            if (timer_done) {
                _subaddieDll_entrypoint_1(actor);
                _subaddierouteDll_entrypoint_3(actor, data->unk34, actor->position);
                _subaddierouteDll_entrypoint_1(actor);
                func_80107200(actor);
                func_80801160_chfactoryrobot(actor, 2);
                actor->unk64_24 = 1;
            }
            break;
        case 2:
            if (func_80801278_chfactoryrobot(actor)) {
                _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(actor)) {
                    func_80801160_chfactoryrobot(actor, 3);
                    actor->unk58 = func_800DC178(2.0f, 4.0f);
                    func_80801C7C_chfactoryrobot(actor);
                }
            }
            break;
        case 3:
            if (func_80801278_chfactoryrobot(actor)) {
                func_80801BB0_chfactoryrobot(actor);
                func_80801A80_chfactoryrobot(actor);
            }
            break;
        case 4:
            if (func_80801278_chfactoryrobot(actor)) {
                _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(actor)) {
                    func_80801160_chfactoryrobot(actor, 5);
                    if (((RobotBits *) actor)->unk64_29) {
                        actor->unk58 = func_800DC178(2.0f, 3.0f);
                    } else {
                        actor->unk58 = func_800DC178(4.0f, 5.0f);
                    }
                }
            }
            break;
        case 5:
            if (func_80801278_chfactoryrobot(actor)) {
                func_80801B3C_chfactoryrobot(actor);
            }
        case 6:
            break;
    }
    if (!((RobotBits *) actor)->unk64_29 && data->unk18 && data->unk20 == 0.0f &&
        func_800EEB40(actor->position, (f32 *) actor->actorData) < 62500.0f) {
        func_800C8FE0(data->unk14, 1);
        data->unk20 = func_800DC178(1.2f, 1.6f);
    }
}

void func_80800DC4_chfactoryrobot(Actor *actor)
{
    FactoryRobotAudio *audio;
    s32 i;
    u8 sound_id;
    audio = func_80100094(actor, 0);
    for (i = 0; i < 2; i++) {
        sound_id = _subaddieaudioloop_entrypoint_3(audio->local_0[i]);
        audio->local_0[i] = sound_id;
    }
    if (audio->local_1) {
        func_800C8B84(audio->local_1);
        audio->local_1 = 0;
    }
}

int func_80800E40_chfactoryrobot(Actor *actor, s32 msg, s32 arg)
{
    u8 *data;
    Actor *exploder;
    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x40:
            func_80801160_chfactoryrobot(actor, 7);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(actor))
                func_80107070(actor, 1);
            break;
        case 0x3E:
            if (((Mass44RobotFlags *) actor)->local_0)
                *(f32 *) (data + 0x1C) = 1.5f;
            else
                *(f32 *) (data + 0x1C) = 6.0f;
            *(s16 *) (data + 0x18) = ((Mass44RobotFlags *) actor)->local_0;
            break;
        case 0x90:
            exploder = func_80106790(func_80101080());
            _chexploder_entrypoint_9(exploder, 3, 0);
            _chexploder_entrypoint_13(exploder, 10);
            if (!func_80107070(actor, 3))
                func_800FFAB0(actor);
            break;
        case 0x93:
            func_80802470_chfactoryrobot(actor, 0);
            break;
        case 0x95:
            func_8080183C_chfactoryrobot(actor);
            break;
        case 0x38:
            return func_80801C50_chfactoryrobot(actor);
        case 0x8F:
            if (!arg) {
                func_8010A590(actor);
                func_80109FE8(actor, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Matching: the line breaks in this function are needed for the match.
void func_80800FFC_chfactoryrobot(Actor *actor, s32 arg)
{
    u8 *data = func_80100094(actor, 0);
    u8 *data_again;
    s32 saved_color[3];
    s32 effect_color[3];
    s32 value;

    if (*(f32 *)(data + 0x20) > 0.0f && !((*(u32 *)((u8 *)actor + 0x78) << 29) >> 31)) {
        data_again = func_80100094(actor, 0);
        *(s16 *)(data_again + 10) = func_800DC128(0, 4);
    }
    if (*(f32 *)(data + 0x20) > 0.0f) value = *(s16 *)((u8 *)func_80100094(actor, 0) + 10); else value = 0;
    func_800DF744(3, value);
    _subaddiefade_entrypoint_9(actor, saved_color);
    value = *(s32 *)(data + 0x14) != 0;
    if (value) value = func_800C9044(*(s32 *)(data + 0x14)) != 0;
    if (*((u8 *)actor + 0x74) & 1) {
        _subaddiefade_entrypoint_12(actor, 255, 255, 255);
    } else if (value) {
        func_800C8900(*(s32 *)(data + 0x14), effect_color);
        _subaddiefade_entrypoint_11(actor, effect_color);
    }
    func_80101870(actor, arg);
    if (value || (*((u8 *)actor + 0x74) & 1)) _subaddiefade_entrypoint_11(actor, saved_color);
}

void func_80801160_chfactoryrobot(actor, state) u8 *actor;
s32 state;
{
    f32 pos[3];

    func_80102424();

switch (state) {
    case 2:;
    case 4:
        func_80109FE8(actor, 1);
        return;
    case 5:
        func_80109FE8(actor, 0);
        return;
    case 1:
        func_80109FE8(actor, 0);
        return;
    case 7:
        func_80103DFC(actor, &pos);
        func_80802470_chfactoryrobot(actor, 1);
        *(u8 *) ((char *) actor + 0x64) = (u8) (*(u8 *) ((char *) actor + 0x64) & 0xFFFE);
        func_800BBCB8(&pos, &pos, 0.8f, 1, _fxgenlist_entrypoint_2());
        func_8010D930(6, *(s32 *) ((char *) actor + 0x70) & 1, &pos,
                      &D_80802AB8_chfactoryrobot);
        _chexploder_entrypoint_3(actor, actor + 4, 0x124);
        return;
    default:
        func_80109FE8(actor, 1);
}

}

void func_80801954_chfactoryrobot();

s32 func_80801278_chfactoryrobot(actor)
Actor *actor;
{
    FRobot *data;
    f32 dt;
    f32 target_speed;
    f32 speed_scale;
    s32 u2;
    f32 heading;
    s32 slot;
    s32 u3;
    f32 home_heading;
    s32 new_state;

    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    speed_scale = 1.0f;

if (_subaddierouteDll_entrypoint_4(actor)) {
    if (data->st == 0) {
        if (data->f1C == 0.0f && !func_800C0638()) {
            if (W64(actor) || (func_8010D248() && func_8010C500(actor) &&
                                 _suchase_entrypoint_0() == (s32) actor->unk0)) {
                data->st = 1;
                data->f24 = func_800DC178(2.0f, 4.0f);
                new_state = actor->unk70_10;
                if (new_state == 4 || new_state == 5) {
                    func_80801160_chfactoryrobot(actor, 2);
                    data->f6 = func_800DC178(100.0f, 200.0f);
                }
            }
        }
    } else if (!W64(actor)) {
        if (!func_8010C500(actor) || _suchase_entrypoint_0() != (s32) actor->unk0) {
            data->st = 0;
            func_80801C7C_chfactoryrobot(actor);
        }
    }
}

target_speed = data->st ? 420.0f : (f32) data->f6;
*(f32 *) &actor->actorData[3] = func_800F15F8(*(f32 *) &actor->actorData[3], target_speed, dt * 150.0f);

if (*(f32 *) &actor->actorData[3] != 0.0f) {
    if (data->st != 0) {
        func_8008FE94(5, (f32 *) &actor->actorData[0]);
        if (W64(actor)) {
            speed_scale = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 1);
            if (data->f1C == 0.0f) {
                func_800EEB9C((f32 *) &actor->actorData[4], actor->unk54,
                              *(f32 *) &actor->actorData[3] * speed_scale);
                *(f32 *) &actor->actorData[5] = func_800F0D50(
                    *(f32 *) &actor->actorData[1] - actor->position[1], -300.0f, 300.0f);
            } else {
                func_800EFD24((f32 *) &actor->actorData[4]);
            }
        } else {
            heading = func_80102D78(actor, &actor->actorData[0]);
            if (_subaddierouteDll_entrypoint_4(actor)) {
                _subaddierouteDll_entrypoint_7(actor, data->f34, heading, heading, 400.0f, 0x5000);
                data->f30 = actor->unk54;
            }
            data->f2C = func_800F1FF0(data->f2C, data->f30, 0.15f, func_800D8FF8() * 10.0f,
                                   func_800D8FF8() * 150.0f);
            actor->unk54 = heading;
            func_800EEB9C((f32 *) &actor->actorData[4], data->f2C, *(f32 *) &actor->actorData[3]);
            *(f32 *) &actor->actorData[5] = func_800F0D50(
                *(f32 *) &actor->actorData[1] - actor->position[1], -300.0f, 300.0f);
        }
        func_80801954_chfactoryrobot(actor);
        new_state = W64(actor) ? 0x204027 : 0x504427;
        func_8010B990(actor, new_state);
    } else {
        slot = ((u32) *(u16 *) ((u8 *) actor->unk0 + 0x12) >> 1) & 0xF;
        if (func_8001210C(15) == slot) {
            if (func_800DC298(0.6f)) {
                actor->unk54 = func_800DC178(0.0f, 359.0f);
            }
        }
        func_80801954_chfactoryrobot(actor);
        func_800D9078(&data->f24);
        if (data->f24 == 0.0f) {
            if (func_800EEB40((f32 *) &actor->actorData[0], actor->position) > 6400.0f) {
                home_heading = func_80102D78(actor, &actor->actorData[0]);
                if (_subaddierouteDll_entrypoint_4(actor)) {
                    _subaddierouteDll_entrypoint_7(actor, data->f34, home_heading, home_heading, 400.0f, 0x5000);
                    data->f30 = actor->unk54;
                }
                data->f2C = func_800F1FF0(data->f2C, data->f30, 0.15f, func_800D8FF8() * 10.0f,
                                       func_800D8FF8() * 120.0f);
                actor->unk54 = home_heading;
                func_800EEB9C((f32 *) &actor->actorData[4], data->f2C,
                              *(f32 *) &actor->actorData[3]);
                *(f32 *) &actor->actorData[5] = func_800F0D50(
                    *(f32 *) &actor->actorData[1] - actor->position[1], -300.0f, 300.0f);
                if (func_8010B990(actor, 0x504427) & 0x26) {
                    func_80801C7C_chfactoryrobot(actor);
                }
            } else {
                func_80801C7C_chfactoryrobot(actor);
                data->f24 = func_800DC178(2.0f, 4.0f);
            }
        } else {
            speed_scale = 0.0f;
        }
    }
} else {

func_80104580(actor);
}
data->f28 += 0.7f * (func_800F12D4(*(f32 *) &actor->actorData[3] * speed_scale, 0.0f, 420.0f, 1.0f, 1.1f) -
                  data->f28);
return 1;
}

void func_8080183C_chfactoryrobot(actor) Actor *actor;
{
    RobotSoundState *sound;
    RobotSoundLimits limits;
    s32 i;
    s32 handle;

    sound = func_80100094(actor, 0);
    limits = D_80802ACC_chfactoryrobot;
    for (i = 0; i != 2; i++) {
        sound->local_0[i] = 0;
    }
    func_80802398_chfactoryrobot(actor);
    limits.local_0 *= actor->scale;
    limits.local_1 *= actor->scale;
    handle = func_800C8A98();
    sound->local_1 = handle;
    func_800C8E84(handle, ((s32 *) D_80802890_chfactoryrobot));
    func_800C8CB8(sound->local_1, actor->position);
    func_800C8F64(sound->local_1, 3);
    func_800C8D4C(sound->local_1, &limits);
    func_800C8FE0(sound->local_1, sound->local_2 > 0.0f);
    if (actor->unk70_10 != 1) {
        _subaddierouteDll_entrypoint_1(actor);
    }
}

void func_80801954_chfactoryrobot(Actor *actor)
{
    u8 *data;
    f32 dt;
    s32 handle;

    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    if (actor->unk70_10 != 5) {
        *(f32 *) (data + 0x10) = func_800F1FF0(*(f32 *) (data + 0x10), actor->unk54, 0.1f,
                                                  dt * 0.5f, dt * 150.0f);
        *(f32 *) (data + 0xC) = func_800F1FF0(*(f32 *) (data + 0xC), actor->unk54, 0.2f,
                                                 dt * 4.0f, dt * 400.0f);
    }
    handle = func_8010262C(actor->unk0, 2);
    if (handle) {
        func_800E0AFC(handle, 3, 1.0f, 0.0f, *(f32 *) (data + 0x10), 0.0f);
        func_800E0AFC(handle, 0x12, 1.0f, 0.0f,
                      func_800136E4(*(f32 *) (data + 0xC) - *(f32 *) (data + 0x10)), 0.0f);
    }
}

s32 func_80801A80_chfactoryrobot(Actor *actor)
{
    FactoryRobotDelayState *data;
    s32 done;

    data = func_80100094(actor, 0);
    if (data->local_1 > 0.0f)
        return 0;
    if (((FactoryRobotControl *) actor)->local_0) {
        done = _subaddiejoy_entrypoint_6(actor, 0);
    } else {
        if (data->local_0)
            return 0;
        done = func_800D9078(&actor->unk58);
    }
    if (done) {
        func_80801160_chfactoryrobot(actor, 4);
        data->local_1 = 0.0f;
        return 1;
    }
    return 0;
}

int func_80801B3C_chfactoryrobot(Actor *actor)
{
    int done;

    if (((FactoryRobotControl *) actor)->local_0) {
        done = _subaddiejoy_entrypoint_6(actor, 0);
    } else {
        done = 0;
    }
    if (done || func_800D9078(&actor->unk58)) {
        func_80801160_chfactoryrobot(actor, 2);
    }
    return done;
}

s32 func_80801BB0_chfactoryrobot(actor)
Actor *actor;
{
    RobotWaitState *data;
    data = func_80100094(actor, 0);
    if (data->timer > 0.0f)
        return 1;
    if (((RobotEnabledState *) actor)->enabled && _subaddiejoy_entrypoint_6(actor, 1)) {
        func_800C8FE0(data->handle, 1);
        data->timer = func_800DC178(1.2f, 1.6f);
        return 1;
    }
    return 0;
}

int func_80801C50_chfactoryrobot(param_0)
s32 param_0;
{
    func_80101074(&D_80802AD4_chfactoryrobot);
    return 2;
}

void func_80801C7C_chfactoryrobot(Actor *actor)
{
    s16 *data;
    data = func_80100094(actor, 0);
    func_800CD1E0((((u32 *) actor)[0x1C] >> 25) - 1, (f32 *) actor->actorData,
                  data[1] + 60.0f);
    data[3] = (s32) func_800DC178(100.0f, 200.0f);
}

void func_80801D08_chfactoryrobot(Actor *actor)
{
    Actor *data;
    data = func_80100094(actor, 0);
    if (((((u32) (*((s32 *) (((char *) actor) + 0x70)))) << 22) >> 26) == 0) {
        *((u16 *) (((char *) actor) + 0x72)) =
            ((*((u16 *) (((char *) actor) + 0x72))) & 0xFC0F) | 0x10;
    }
    if (func_800EA05C(actor) == 0x101) {
        *((s8 *) (((char *) data) + 0x12)) = 1;
        return;

}
*(s8 *) ((char *) data + 0x12) = 0;
}

// Group controller: tracks linked robots, respawns them, plays Tannoy dialog and spawns the reward.
void func_80801D7C_chfactoryrobot(u8 *actor)
{
    u8 *group;
    s32 result;

    group = func_80100094(actor, 0);
    result = func_800F54E4();
    func_800F4F34(result, (s32 *) (s32) (actor + 4), 100.0f, 80.0f);

    switch ((u32) *(u16 *) (actor + 0x72) >> 10) {
        case 1: {
            s32 i;
            s32 near_player;
            s32 handle;
            handle = *(s32 *) (actor + 0x3C);
            if (handle == 0) {
                func_80101FDC(actor, 3);
            } else if ((*(f32 *) ((u8 *) func_80106790(handle) + 0x58) > 0.0f) && (group[0x14] == 0)) {
                _sudialog_entrypoint_0(0x364, 4);
                handle = group[0x10];
                if (handle < group[0x11]) {
                    near_player = 0;
                    i = 0;
                    if (handle > 0) {
                        do {
                            if (func_800F00A4((s32) (actor + 4), 150.0f, 800.0f, 0.0f,
                                              (s32) ((u8 *) func_80106790(((s32 *) group)[i]) + 4)) !=
                                0) {
                                near_player = 1;
                                break;
                            }
                            i += 1;
                        } while (i < group[0x10]);
                    }
                    if (near_player == 0) {
                        func_80108B04(actor, 0);
                        func_80101FDC(actor, 2);
                        *(f32 *) (actor + 0x58) = func_800DC178(1.5f, 2.5f);
                    }
                }
            }
            break;
        }

case 2:
    if (func_800D9078(actor + 0x58) != 0) {
        func_80101FDC(actor, 1);
    }

break;

case 4:
    if ((func_8010D23C() != 0) && (func_8010C500(actor) != 0) && (func_8008FDC4() & 0x08000000)) {
        _capod_entrypoint_13(*(s32 *) (actor + 0), 0, 0xC, 0x30);
        func_80101FDC(actor, 6);
        actor[0x65] = (u8) (actor[0x65] & 0xFFEF);
        *(f32 *) (actor + 0x58) = 1.0f;
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(*(s32 *) (actor + 0), 0x133B, 7, (s32) (actor + 4), 0xA3);
    }

break;

case 6: {
    f32 reward_pos[3];
    s32 pad_y;
    f32 y_offset;
    result = func_800D9078(actor + 0x58);
    y_offset = func_800F12D4(*(f32 *) (actor + 0x58), 0.0f, 1.0f, -200.0f, 300.0f);
    func_800EE7F8(reward_pos, (s32) (actor + 4));
    reward_pos[1] += y_offset;
    func_800D1254(0x39, 1, reward_pos);
    if (!((Actor *) actor)->unk64_20 && (*(f32 *) (actor + 0x58) < 0.7f)) {
        _subaddieaudioquick_entrypoint_2(actor, (s32) (actor + 4), D_80802AEC_chfactoryrobot);
        ((Actor *) actor)->unk64_20 = 1;
    }
    if (result != 0) {
        func_80101FDC(actor, 9);
    }
    break;
}

case 7: {
    f32 reward_pos2[3];
    s32 pad_x;
    f32 y_offset2;
    result = func_800D9078(actor + 0x58);
    y_offset2 = func_800F12D4(*(f32 *) (actor + 0x58), 0.0f, 1.0f, 300.0f, -200.0f);
    func_800EE7F8(reward_pos2, (s32) (actor + 4));
    reward_pos2[1] += y_offset2;
    func_800D1254(0x39, 1, reward_pos2);
    if (result != 0) {
        func_80101FDC(actor, 0xA);
        func_800DA544(0x1BB);
    }
    break;
}

case 8:
    func_800D2498(0x101, group[0x13], 0);

if (func_800D9078(actor + 0x58) != 0) {
    func_80101FDC(actor, 9);
}

break;

case 9:
    func_800D2498(0x101, group[0x13], 0);

if ((group[0x10] < func_800F1418(group[0x11], group[0x13])) && (group[0x14] == 0)) {
    func_80108B04(actor, 0);
    func_80101FDC(actor, 8);
    *(f32 *) (actor + 0x58) = func_800DC178(1.5f, 2.5f);
}

case 10:
    break;
    }
    group[0x14] = 0;
    }

    void func_8080219C_chfactoryrobot(u8 *actor)
    {
        short sound_id;
        u8 *sound_slot;
        sound_id = *((u8 *) (((s8 *) actor) + 0x28));
        sound_slot = (u8 *) (((s8 *) actor) + 0x28);
        if (sound_id != 0) {
            func_800E8C08(sound_id & 0xFF, sound_id, actor);
            *sound_slot = 0U;
        }
    }

    void func_808021D4_chfactoryrobot(Actor *actor, s32 param_1)
    {
        u8 handle;
        void *data;
        func_801015D0(actor);
        handle = func_800D731C(actor->unk0->unk14);
        if (handle) {
            data = func_800E8C58(*(u8 *) ((u8 *) actor + 0x28));
            func_800DBE60(handle, 0, data);
            func_800DBE60(handle, 1, data);
        }
    }

    s32 func_80802240_chfactoryrobot(Actor *actor, s32 param_1, FactoryRobotMessage36 arg)
    {
        Actor *spawned;
        s32 sound_id;

        switch (param_1) {
            case 0x3D:
                spawned = (Actor *) func_80108528(0x3BE, actor->position, 0, &actor);
                if (spawned)
                    spawned->unk74_7 = actor->unk74_7;
                break;
            case 0x2E:
                _capod_entrypoint_14();
                break;
            case 0x1F:
                func_808021D4_chfactoryrobot(actor, arg.local_0);
                break;
            case 0x95:
                func_808025D4_chfactoryrobot(actor);
                break;
            case 0x29:
                ((u8 *) actor)[0x28] = func_800E8B74(0);
                func_800E8DB0(((u8 *) actor)[0x28], 6);
                func_800E8D28(((u8 *) actor)[0x28], 1.2f);
                func_800E8D5C(((u8 *) actor)[0x28], &D_80802AF4_chfactoryrobot, 3);
                break;
            case 0x2A:
                sound_id = ((u8 *) actor)[0x28];

if (sound_id) {
    func_800E8C08(sound_id);
    ((u8 *) actor)[0x28] = 0;
}

break;
default:
    return 0;
    }
    return 1;
    }

    int func_80802398_chfactoryrobot(actor)
    Actor *actor;
    {
        Actor *leader;
        FactoryRobotLinks1436 *links;

        if (((FactoryRobotFlags1436 *) actor)->disabled) {
            return 0;
        }
        if (!_subaddiefind_entrypoint_10(actor, 0x3BF, actor->unk74_7)) {
            return 0;
        }
        leader = func_80106790(actor->unk3C);
        links = func_80100094(leader, 0);
        if (!((FactoryRobotFlags1436 *) leader)->state.bits.initialized) {
            func_808025D4_chfactoryrobot(leader);
            ((FactoryRobotFlags1436 *) leader)->state.bits.initialized = 1;
        }
        links->markers[links->count] = actor->unk0;
        links->count++;
        return 1;
    }

    s32 func_80802470_chfactoryrobot(actor, killed)
    Actor *actor;
    s32 killed;
    {
        Actor *leader;
        RobotData_80802470_chfactoryrobot *links;
        s32 i;

        if (((RobotActor *) actor)->unk78_5) {
            return 0;
        }
        if (actor->unk3C == NULL) {
            return 0;

}
leader = func_80106790(actor->unk3C);
links = func_80100094(leader, 0);
if (killed && links->unk12) {
    if (--links->unk13 == 0) {
        _capod_entrypoint_13(leader->unk0, 0, 0xF, 0x30);
        func_80101FDC(leader, 7);
        *((u8 *) leader + 0x65) &= ~0x10;
        leader->unk58 = 1.0f;
        func_800FC660(0x10);
        _subaddiedialog_entrypoint_11(leader->unk0, 0x137B, 0x44, leader->position, 0xA3);
    }

}
actor->unk3C = NULL;
for (i = 0; i < links->unk10; i++) {
    if ((s32) actor->unk0 == links->unk0[i]) {
        links->unk0[i] = links->unk0[--links->unk10];
        return 1;
    }

}
return 0;
}

int func_808025D4_chfactoryrobot(actor)
Actor *actor;
{
    u8 *data;
    s32 i;
    f32 reward_pos[3];
    data = (u8 *) func_80100094(actor, 0);
    if (data[0x12]) {
        _subaddieDll_entrypoint_4(actor, 1);
        data[0x13] = 6;
        func_80101FDC(actor, func_800DA298(0x1BB) ? 10 : 4);
        func_800EE7F8(reward_pos, actor->position);
        reward_pos[1] += 300.0f;
        func_800D1254(0x39, 1, reward_pos);
    } else if (!_subaddiefind_entrypoint_10(actor, 0x3BD, actor->unk74_7)) {
        func_80101FDC(actor, 3);
        func_80103110(actor, 0);
    }
    data[0x11] = func_800F0D90((s32) actor->rotation[1], 1, 4);
    data[0x10] = 0;
    data[0x14] = 1;
    for (i = 0; i < data[0x11]; i++)
        ((s32 *) data)[i] = 0;
    if (data[0x12] && !func_800DA298(0x6A3) && func_800EA090() == 3) {
        _capod_entrypoint_13(actor->unk0, 0, 8, 0x10);
        func_800DA544(0x6A3);
    }
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80802890_chfactoryrobot[2][12] = {0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0xC0,
                                       0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x80,
                                       0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0xA0};
u32 D_808028A8_chfactoryrobot[5] = {0x10000, 0x0, 0x0, 0x70000, 0x80000};
u32 D_808028BC_chfactoryrobot[5] = {0x20000, 0x90000, 0x90000, 0x80000, 0xA0000};
u32 D_808028D0_chfactoryrobot[22] = {
    0x0,        0x0,       0x3FC00000, 0x2B50101, 0x3F1126E9, 0x2B60002, 0x3F000000, 0x2B70001,
    0x3F028F5C, 0x2B80002, 0x3FC00000, 0x2B50101, 0x3F000000, 0x2B70001, 0x0,        0x0,
    0x0,        0x0,       0x3FC00000, 0x2B50001, 0x3FC00000, 0x2B50001};
int D_80802928_chfactoryrobot[18] = {0x32103BD,
                                     0x7E30001,
                                     0x0,
                                     (u32) func_80800058_chfactoryrobot,
                                     (u32) func_80105834,
                                     (u32) func_801018A4,
                                     0xDAC0000,
                                     0x0,
                                     0x0,
                                     0x120,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800024_chfactoryrobot,
                                     (u32) func_80107C2C,
                                     -0x7FFFBBF0,
                                     (u32) func_80800360_chfactoryrobot,
                                     (u32) &D_808028A8_chfactoryrobot};
int D_80802970_chfactoryrobot[18] = {0x32203BE,
                                     0x7D10001,
                                     (u32) &D_808028D0_chfactoryrobot,
                                     (u32) func_80800920_chfactoryrobot,
                                     (u32) func_80105834,
                                     (u32) func_80800FFC_chfactoryrobot,
                                     0xDAC0000,
                                     0x3FC00000,
                                     0x0,
                                     0x43A50320,
                                     (u32) func_80800DC4_chfactoryrobot,
                                     (u32) func_80108ED0,
                                     0x400000,
                                     (u32) func_808007C4_chfactoryrobot,
                                     (u32) func_80107C2C,
                                     -0x7FDDABE1,
                                     (u32) func_80800E40_chfactoryrobot,
                                     (u32) &D_808028BC_chfactoryrobot};
void *D_808029B8_chfactoryrobot = (void *) 0x032303BF;
static u32 D_808029B8_chfactoryrobot_rest[17] = {0x8740001,
                                                 0x0,
                                                 (u32) func_80801D7C_chfactoryrobot,
                                                 (u32) func_80105834,
                                                 (u32) func_801018A4,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x40000801,
                                                 (u32) func_8080219C_chfactoryrobot,
                                                 0x0,
                                                 0x180000,
                                                 (u32) func_80801D08_chfactoryrobot,
                                                 (u32) func_80107C2C,
                                                 0x80085416,
                                                 (u32) func_80802240_chfactoryrobot,
                                                 0x0};
u8 D_80802A00_chfactoryrobot[56] = {
    0x0, 0x1D, 0x9,  0xE2, 0x0, 0x1B, 0xFD, 0xA9, 0xFE, 0x5F, 0x0,  0x2D, 0x1,  0x2C,
    0x1, 0x90, 0x0,  0xE,  0x0, 0x14, 0x0,  0x14, 0x0,  0x1F, 0xFF, 0xFF, 0x60, 0x0,
    0x0, 0x16, 0x11, 0x8,  0x0, 0x22, 0x0,  0x19, 0x0,  0x19, 0x0,  0xC,  0x0,  0xC,
    0x0, 0x15, 0x0,  0x0,  0x0, 0xCC, 0x0,  0x2B, 0x1,  0x19, 0x1,  0x4C, 0x0,  0x0};
u8 D_80802A38_chfactoryrobot[52] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2D, 0x0,  0x96, 0x0,  0xFA, 0x0,  0xE,  0x0,
    0x14, 0x0,  0x14, 0x0,  0x20, 0xC0, 0xC0, 0xC0, 0xC0, 0x0,  0x16, 0x0,  0x8,
    0x0,  0x22, 0x0,  0x99, 0x0,  0xB3, 0x0,  0xD9, 0x0,  0xE6, 0x0,  0x15, 0x0,
    0x0,  0x0,  0x99, 0x0,  0x2B, 0x1,  0x33, 0x1,  0x99, 0x0,  0x0,  0x0,  0x0};
u8 D_80802A6C_chfactoryrobot[16] = {0x0, 0x13, 0x4, 0x13, 0x0, 0xA,  0x1, 0x4C,
                                    0x0, 0x1,  0x2, 0x26, 0x9, 0xC4, 0x0, 0x0};
u8 D_80802A7C_chfactoryrobot[16] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0xA,  0x0, 0xCC,
                                    0x0, 0x1,  0x2, 0x26, 0x9, 0xC4, 0x0, 0x0};
f32 D_80802A8C_chfactoryrobot[4] = {1.746943e-39f, 1.194202e-39f, 2.5714e-38f, 5.2452087e-06f};
f32 D_80802A9C_chfactoryrobot[4] = {1.746625e-39f, 9.18714e-40f, 2.031591e-39f, 0.0f};
f32 D_80802AAC_chfactoryrobot[3] = {1.746733e-39f, 1.194292e-39f, 4.2244328e-38f};
u8 D_80802AB8_chfactoryrobot[20] = {0x0, 0x13, 0x4, 0x13, 0x0, 0xD,  0x1, 0x19, 0x1, 0x33,
                                    0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0,  0x0, 0x0};
RobotSoundLimits D_80802ACC_chfactoryrobot = {2.5e+02f, 4e+02f};
s32 D_80802AD4_chfactoryrobot[6] = {0x12, 0x40200000, 0xFF0000, 0x1, 0x400CCCCD, 0xFF0000};
u8 D_80802AEC_chfactoryrobot[8] = {0x0, 0x13, 0x4, 0x6A, 0x0, 0x2, 0x0, 0x0};
s32 D_80802AF4_chfactoryrobot[7] = {0x0, 0x0, 0x3F000000, 0x3F800000, 0x3F800000, 0x0, 0x0};
