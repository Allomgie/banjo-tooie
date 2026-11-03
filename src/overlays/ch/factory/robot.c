#include "common.h"

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

void func_80800024_chfactoryrobot(u8 *param_0)
{
    *(f32 *) ((s8 *) param_0 + 0x2C) = 0.0f;
    *(f32 *) ((s8 *) param_0 + 0x34) = 0.0f;
    *(f32 *) ((s8 *) param_0 + 0x30) = 20.0f;
    func_80105010();
}

int func_808006DC_chfactoryrobot(Actor *param_0, f32 param_1, f32 param_2);

void func_80800264_chfactoryrobot();

void func_80800058_chfactoryrobot(Actor *param_0)
{
    f32 local_0[3];
    f32 *local_3;
    f32 local_1[2];
    f32 local_2[2];

    local_3 = param_0->position;
    func_800EE7F8(local_0, local_3);
    func_800EF1B8(local_0, param_0->rotation[1], 40.0f);
    func_800F4F34(func_800F54E4(), local_0, 30.0f, 100.0f);
    switch (param_0->unk70_10) {
        case 1:
            func_80800264_chfactoryrobot(param_0);
            param_0->unk54 = 50.0f;
            param_0->unk50 = 20.0f;
            if (func_808006DC_chfactoryrobot(param_0, 1.0f, 15.0f)) {
                ((f32 *) param_0->actorData)[0] = func_800DC178(1.0f, 1.2f);
                func_80101FDC(param_0, 2);
            }
            break;
        case 2:
            func_80800264_chfactoryrobot(param_0);
            if (func_800D9078(param_0->actorData)) {
                func_80101FDC(param_0, 3);
            }
            break;
        case 3:
            func_80800264_chfactoryrobot(param_0);
            param_0->unk54 = -50.0f;
            param_0->unk50 = 20.0f;
            if (func_808006DC_chfactoryrobot(param_0, 1.0f, 15.0f)) {
                ((f32 *) param_0->actorData)[0] = func_800DC178(1.0f, 1.2f);
                func_80101FDC(param_0, 4);
            }
            break;
        case 4:
            func_80800264_chfactoryrobot(param_0);
            if (func_800D9078(param_0->actorData)) {
                func_80101FDC(param_0, 1);
            }
            break;
        case 5:
            func_80800264_chfactoryrobot(param_0);
            func_8010D254(local_1);
            func_800F18FC(local_3, local_1, local_2);
            param_0->unk54 = local_2[1] - param_0->rotation[1];
            param_0->unk50 = -local_2[0];
            func_808006DC_chfactoryrobot(param_0, 4.0f, 40.0f);
            if (param_0->unk58 == 0.0f) {
                func_80101FDC(param_0, 3);
            }
    }
}

void func_80800264_chfactoryrobot(Actor *param_0)
{
    func_800D9078(&param_0->unk58);
    if (_subaddierouteDll_entrypoint_4(param_0) && func_8010D248() && func_8010C500(param_0)) {
        param_0->unk58 = 4.0f;
    }
    _subaddieDll_entrypoint_4(param_0, param_0->unk58 > 0.0f ? 1 : 0);
    *(f32 *) &param_0->actorData[4] = _subaddieaudioloop_entrypoint_8(
        param_0, param_0->position, param_0->unk58 > 0.0f, *(f32 *) &param_0->actorData[4]);
    if (param_0->unk70_10 != 5 && param_0->unk58 > 0.0f) {
        func_80101FDC(param_0, 5);
    }
}

s32 func_80800360_chfactoryrobot(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x40:
            *(s32 *) ((u8 *) func_80106790(*(s32 *) ((u8 *) param_0 + 0x3C)) + 0x3C) = 0;
            func_808005D4_chfactoryrobot(param_0);
            func_80107070(param_0, 3);
            break;
        case 0x1F:
            func_80800424_chfactoryrobot(param_0, *(s32 *) &param_2);
            break;
        case 0x8F:
            if (*(s32 *) &param_2 == 0) {
                func_80800508_chfactoryrobot(param_0);
            }
            break;
        case 0x95:
            func_80800508_chfactoryrobot(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800424_chfactoryrobot(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 local_2;
    f32 local_0[3];
    f32 local_1[4];

    local_2 = func_801040D0();
    func_801015D0(param_0);
    func_800DF41C(local_2);
    func_800EFA4C(local_0, 0.0f, *(f32 *) ((u8 *) param_0 + 0x2C), 0.0f);
    func_800D93A0(local_1, local_0);
    func_800DFF2C(local_2, 0x12, local_1);
    func_800EFA4C(local_0, *(f32 *) ((u8 *) param_0 + 0x30), 0.0f, 0.0f);
    func_800D93A0(local_1, local_0);
    func_800DFF2C(local_2, 0x6C, local_1);
    func_800AE1E8((s16) *(u16 *) &param_0->unk0->unk10, func_800B27E0(param_1), local_2);
    func_800DF72C(func_800AE080((s16) *(u16 *) &param_0->unk0->unk10));
}

void func_80800508_chfactoryrobot(param_0) Actor *param_0;
{
    Actor *local_0;

    _subaddiefind_entrypoint_10(param_0, 0x3BF, param_0->unk74_7);
    local_0 = func_80106790(param_0->unk3C);
    local_0->unk3C = param_0->unk0;
    func_80101FDC(local_0, 1);
    func_80103110(local_0, 1);
    ((FactoryRobotFlags *) param_0)->local_0 = ((FactoryRobotFlags *) local_0)->local_0;
    if (((FactoryRobotFlags *) local_0)->local_1) {
        ((FactoryRobotAnimation *) param_0)->local_0 = ((FactoryRobotFlags *) local_0)->local_1;
    } else {
        ((FactoryRobotAnimation *) param_0)->local_0 = 1;
    }
    func_80107200(param_0);
}

void func_808005D4_chfactoryrobot(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    func_800EE7F8(local_0, param_0->position);
    func_800EF214(local_0, -param_0->rotation[0], param_0->rotation[1], 20.0f);
    func_800BBCB8(local_0, param_0->position, 1.0f, 8, D_80802A38_chfactoryrobot);
    func_800BBCB8(local_0, param_0->position, 1.0f, 0xC, D_80802A00_chfactoryrobot);
    func_8010D930(6, *(u32 *) ((u8 *) param_0 + 0x70) & 1, local_0, D_80802A6C_chfactoryrobot);
    _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80802A7C_chfactoryrobot);
    func_800EE7F8(local_1, param_0->position);
    func_800EF1B8(local_1, param_0->rotation[1], -50.0f);
    _chexploder_entrypoint_3(param_0, local_1, 0);
}

int func_808006DC_chfactoryrobot(Actor *param_0, f32 param_1, f32 param_2)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    param_0->unk54 = func_800F0D50(func_80013728(param_0->unk54), -80.0f, 80.0f);
    param_0->unk50 = func_800F0D50(func_80013728(param_0->unk50), -60.0f, 60.0f);
    ((f32 *) param_0->actorData)[5] =
        func_800F1FF0(((f32 *) param_0->actorData)[5], param_0->unk54, 0.15f, (local_0 * param_1),
                      (local_0 * param_2));
    ((f32 *) param_0->actorData)[6] =
        func_800F1FF0(((f32 *) param_0->actorData)[6], param_0->unk50, 0.15f, (local_0 * param_1),
                      (local_0 * param_2));
    return func_800F20BC(((f32 *) param_0->actorData)[5], param_0->unk54, 4.0f);
}

void func_808007C4_chfactoryrobot(Actor *param_0)
{
    u8 *local_0 = func_80100094(param_0, 0);

    f32 local_2;

    func_8010A3E8(param_0, 0.4f);
    func_8010A590(param_0);
    func_800EE940(local_0, param_0->position);
    *(f32 *) (local_0 + 16) = *(f32 *) (local_0 + 12) = *(f32 *) ((u8 *) param_0 + 0x48);
    *(f32 *) (local_0 + 0x28) = 1.0f;
    *(f32 *) (local_0 + 0x24) = 0.0f;
    func_800EE7F8(param_0->actorData, param_0->position);
    if ((*(u32 *) ((u8 *) param_0 + 0x78) << 26) >> 31) {
        if (func_80105138(param_0, param_0->position, 0.0f, -500.0f, &local_2))
            *(s16 *) (local_0 + 2) = (s32) local_2;
        _subaddieDll_entrypoint_1(param_0);
        _subaddierouteDll_entrypoint_3(param_0, local_0 + 0x34, param_0->position);
        func_80107200(param_0);
        func_80801160_chfactoryrobot(param_0, 3);
        *(s16 *) (local_0 + 6) = (s32) func_800DC178(100.0f, 200.0f);
    } else {
        func_80801160_chfactoryrobot(param_0, 1);
        *(f32 *) &param_0->actorData[1] += 300.0f;
        param_0->unk64_24 = 0;
        param_0->unk58 = 1.0f;
    }
}

void func_80801C7C_chfactoryrobot();

s32 func_80801A80_chfactoryrobot();

void func_80800920_chfactoryrobot(Actor *param_0)
{
    RobotData_80800920_chfactoryrobot *local_4;
    s32 local_5;
    f32 local_0[3];
    f32 local_1;
    f32 local_2[3];
    s32 local_3;

    local_4 = func_80100094(param_0, 0);
    if (((RobotBits *) param_0)->unk78_2) {
        return;
    }
    local_4->unk9 = _subaddieaudioloop_entrypoint_6(
        local_4->unk9, param_0->position, 0.0f < local_4->unk20, -1, D_80802AAC_chfactoryrobot,
        ((RobotBits *) param_0)->unk70_0);
    local_4->unk8 = _subaddieaudioloop_entrypoint_6(local_4->unk8, param_0->position, 1, -1,
                                                    D_80802A9C_chfactoryrobot,
                                                    ((RobotBits *) param_0)->unk70_0);
    if (local_4->unk8) {
        func_800C31DC(local_4->unk8, local_4->unk28);
    }
    func_800D9078(&local_4->unk1C);
    local_5 = func_800D9078(&local_4->unk20);
    if (0.0f < local_4->unk20) {
        if (local_4->unk1C == 0.0f &&
            func_8010CFBC(param_0->position, param_0->scale * 80.0f, param_0->scale * 175.0f) &&
            func_800F7B9C(func_800F54E4(), 0x51) == 2) {
            if (((RobotBits *) param_0)->unk64_29) {
                local_4->unk1C = 1.5f;
            } else {
                local_4->unk1C = 6.0f;
            }
            local_4->unk18 = ((RobotBits *) param_0)->unk64_29;
            local_4->unk20 = 0.4f;
            func_800F57F0(func_800F54E4(), local_0);
            _chelectricfence_entrypoint_1(param_0, local_0);
        }
        func_800C8CB8(local_4->unk14, param_0->position);
        func_800C8E84(local_4->unk14, D_80802890_chfactoryrobot[func_800DC298(0.35f)]);
    } else if (local_5) {
        func_800C8FE0(local_4->unk14, 0);
    }
    switch (param_0->unk70_10) {
        case 1:
            local_3 = func_800D9078(&param_0->unk58);
            local_1 = func_800F12D4(param_0->unk58, 0.0f, 1.0f, 1.0f, 0.0f);
            func_800EE88C(local_2, local_4->pos);
            func_800EFE50(param_0->position, local_2, (f32 *) param_0->actorData, local_1);
            if (local_3) {
                _subaddieDll_entrypoint_1(param_0);
                _subaddierouteDll_entrypoint_3(param_0, local_4->unk34, param_0->position);
                _subaddierouteDll_entrypoint_1(param_0);
                func_80107200(param_0);
                func_80801160_chfactoryrobot(param_0, 2);
                param_0->unk64_24 = 1;
            }
            break;
        case 2:
            if (func_80801278_chfactoryrobot(param_0)) {
                _subaddieaudioquick_entrypoint_3(param_0, param_0->position,
                                                 D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(param_0)) {
                    func_80801160_chfactoryrobot(param_0, 3);
                    param_0->unk58 = func_800DC178(2.0f, 4.0f);
                    func_80801C7C_chfactoryrobot(param_0);
                }
            }
            break;
        case 3:
            if (func_80801278_chfactoryrobot(param_0)) {
                func_80801BB0_chfactoryrobot(param_0);
                func_80801A80_chfactoryrobot(param_0);
            }
            break;
        case 4:
            if (func_80801278_chfactoryrobot(param_0)) {
                _subaddieaudioquick_entrypoint_3(param_0, param_0->position,
                                                 D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(param_0)) {
                    func_80801160_chfactoryrobot(param_0, 5);
                    if (((RobotBits *) param_0)->unk64_29) {
                        param_0->unk58 = func_800DC178(2.0f, 3.0f);
                    } else {
                        param_0->unk58 = func_800DC178(4.0f, 5.0f);
                    }
                }
            }
            break;
        case 5:
            if (func_80801278_chfactoryrobot(param_0)) {
                func_80801B3C_chfactoryrobot(param_0);
            }
        case 6:
            break;
    }
    if (!((RobotBits *) param_0)->unk64_29 && local_4->unk18 && local_4->unk20 == 0.0f &&
        func_800EEB40(param_0->position, (f32 *) param_0->actorData) < 62500.0f) {
        func_800C8FE0(local_4->unk14, 1);
        local_4->unk20 = func_800DC178(1.2f, 1.6f);
    }
}

void func_80800DC4_chfactoryrobot(Actor *param_0)
{
    FactoryRobotAudio *local_1;
    s32 local_0;
    u8 local_2;
    local_1 = func_80100094(param_0, 0);
    for (local_0 = 0; local_0 < 2; local_0++) {
        local_2 = _subaddieaudioloop_entrypoint_3(local_1->local_0[local_0]);
        local_1->local_0[local_0] = local_2;
    }
    if (local_1->local_1) {
        func_800C8B84(local_1->local_1);
        local_1->local_1 = 0;
    }
}

int func_80800E40_chfactoryrobot(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    Actor *local_1;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x40:
            func_80801160_chfactoryrobot(param_0, 7);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(param_0))
                func_80107070(param_0, 1);
            break;
        case 0x3E:
            if (((Mass44RobotFlags *) param_0)->local_0)
                *(f32 *) (local_0 + 0x1C) = 1.5f;
            else
                *(f32 *) (local_0 + 0x1C) = 6.0f;
            *(s16 *) (local_0 + 0x18) = ((Mass44RobotFlags *) param_0)->local_0;
            break;
        case 0x90:
            local_1 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(local_1, 3, 0);
            _chexploder_entrypoint_13(local_1, 10);
            if (!func_80107070(param_0, 3))
                func_800FFAB0(param_0);
            break;
        case 0x93:
            func_80802470_chfactoryrobot(param_0, 0);
            break;
        case 0x95:
            func_8080183C_chfactoryrobot(param_0);
            break;
        case 0x38:
            return func_80801C50_chfactoryrobot(param_0);
        case 0x8F:
            if (!param_2) {
                func_8010A590(param_0);
                func_80109FE8(param_0, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800FFC_chfactoryrobot(Actor *param_0, s32 param_1)
{
    u8 *local_0 = func_80100094(param_0, 0);
    u8 *local_4;
    s32 local_1[3];
    s32 local_2[3];
    s32 local_3;

    if (*(f32 *)(local_0 + 0x20) > 0.0f && !((*(u32 *)((u8 *)param_0 + 0x78) << 29) >> 31)) {
        local_4 = func_80100094(param_0, 0);
        *(s16 *)(local_4 + 10) = func_800DC128(0, 4);
    }
    if (*(f32 *)(local_0 + 0x20) > 0.0f) local_3 = *(s16 *)((u8 *)func_80100094(param_0, 0) + 10); else local_3 = 0;
    func_800DF744(3, local_3);
    _subaddiefade_entrypoint_9(param_0, local_1);
    local_3 = *(s32 *)(local_0 + 0x14) != 0;
    if (local_3) local_3 = func_800C9044(*(s32 *)(local_0 + 0x14)) != 0;
    if (*((u8 *)param_0 + 0x74) & 1) {
        _subaddiefade_entrypoint_12(param_0, 255, 255, 255);
    } else if (local_3) {
        func_800C8900(*(s32 *)(local_0 + 0x14), local_2);
        _subaddiefade_entrypoint_11(param_0, local_2);
    }
    func_80101870(param_0, param_1);
    if (local_3 || (*((u8 *)param_0 + 0x74) & 1)) _subaddiefade_entrypoint_11(param_0, local_1);
}

void func_80801160_chfactoryrobot(param_0, param_1) u8 *param_0;
s32 param_1;
{
    f32 local_0[3];

    func_80102424();

switch (param_1) {
    case 2:;
    case 4:
        func_80109FE8(param_0, 1);
        return;
    case 5:
        func_80109FE8(param_0, 0);
        return;
    case 1:
        func_80109FE8(param_0, 0);
        return;
    case 7:
        func_80103DFC(param_0, &local_0);
        func_80802470_chfactoryrobot(param_0, 1);
        *(u8 *) ((char *) param_0 + 0x64) = (u8) (*(u8 *) ((char *) param_0 + 0x64) & 0xFFFE);
        func_800BBCB8(&local_0, &local_0, 0.8f, 1, _fxgenlist_entrypoint_2());
        func_8010D930(6, *(s32 *) ((char *) param_0 + 0x70) & 1, &local_0,
                      &D_80802AB8_chfactoryrobot);
        _chexploder_entrypoint_3(param_0, param_0 + 4, 0x124);
        return;
    default:
        func_80109FE8(param_0, 1);
}

}

void func_80801954_chfactoryrobot();

s32 func_80801278_chfactoryrobot(param_0)
Actor *param_0;
{
    FRobot *r;
    f32 dt;
    f32 tgt;
    f32 scale;
    s32 u2;
    f32 f;
    s32 sel;
    s32 u3;
    f32 f2;
    s32 mode;

    r = func_80100094(param_0, 0);
    dt = func_800D8FF8();
    scale = 1.0f;

if (_subaddierouteDll_entrypoint_4(param_0)) {
    if (r->st == 0) {
        if (r->f1C == 0.0f && !func_800C0638()) {
            if (W64(param_0) || (func_8010D248() && func_8010C500(param_0) &&
                                 _suchase_entrypoint_0() == (s32) param_0->unk0)) {
                r->st = 1;
                r->f24 = func_800DC178(2.0f, 4.0f);
                mode = param_0->unk70_10;
                if (mode == 4 || mode == 5) {
                    func_80801160_chfactoryrobot(param_0, 2);
                    r->f6 = func_800DC178(100.0f, 200.0f);
                }
            }
        }
    } else if (!W64(param_0)) {
        if (!func_8010C500(param_0) || _suchase_entrypoint_0() != (s32) param_0->unk0) {
            r->st = 0;
            func_80801C7C_chfactoryrobot(param_0);
        }
    }
}

tgt = r->st ? 420.0f : (f32) r->f6;
*(f32 *) &param_0->actorData[3] = func_800F15F8(*(f32 *) &param_0->actorData[3], tgt, dt * 150.0f);

if (*(f32 *) &param_0->actorData[3] != 0.0f) {
    if (r->st != 0) {
        func_8008FE94(5, (f32 *) &param_0->actorData[0]);
        if (W64(param_0)) {
            scale = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 1);
            if (r->f1C == 0.0f) {
                func_800EEB9C((f32 *) &param_0->actorData[4], param_0->unk54,
                              *(f32 *) &param_0->actorData[3] * scale);
                *(f32 *) &param_0->actorData[5] = func_800F0D50(
                    *(f32 *) &param_0->actorData[1] - param_0->position[1], -300.0f, 300.0f);
            } else {
                func_800EFD24((f32 *) &param_0->actorData[4]);
            }
        } else {
            f = func_80102D78(param_0, &param_0->actorData[0]);
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                _subaddierouteDll_entrypoint_7(param_0, r->f34, f, f, 400.0f, 0x5000);
                r->f30 = param_0->unk54;
            }
            r->f2C = func_800F1FF0(r->f2C, r->f30, 0.15f, func_800D8FF8() * 10.0f,
                                   func_800D8FF8() * 150.0f);
            param_0->unk54 = f;
            func_800EEB9C((f32 *) &param_0->actorData[4], r->f2C, *(f32 *) &param_0->actorData[3]);
            *(f32 *) &param_0->actorData[5] = func_800F0D50(
                *(f32 *) &param_0->actorData[1] - param_0->position[1], -300.0f, 300.0f);
        }
        func_80801954_chfactoryrobot(param_0);
        mode = W64(param_0) ? 0x204027 : 0x504427;
        func_8010B990(param_0, mode);
    } else {
        sel = ((u32) *(u16 *) ((u8 *) param_0->unk0 + 0x12) >> 1) & 0xF;
        if (func_8001210C(15) == sel) {
            if (func_800DC298(0.6f)) {
                param_0->unk54 = func_800DC178(0.0f, 359.0f);
            }
        }
        func_80801954_chfactoryrobot(param_0);
        func_800D9078(&r->f24);
        if (r->f24 == 0.0f) {
            if (func_800EEB40((f32 *) &param_0->actorData[0], param_0->position) > 6400.0f) {
                f2 = func_80102D78(param_0, &param_0->actorData[0]);
                if (_subaddierouteDll_entrypoint_4(param_0)) {
                    _subaddierouteDll_entrypoint_7(param_0, r->f34, f2, f2, 400.0f, 0x5000);
                    r->f30 = param_0->unk54;
                }
                r->f2C = func_800F1FF0(r->f2C, r->f30, 0.15f, func_800D8FF8() * 10.0f,
                                       func_800D8FF8() * 120.0f);
                param_0->unk54 = f2;
                func_800EEB9C((f32 *) &param_0->actorData[4], r->f2C,
                              *(f32 *) &param_0->actorData[3]);
                *(f32 *) &param_0->actorData[5] = func_800F0D50(
                    *(f32 *) &param_0->actorData[1] - param_0->position[1], -300.0f, 300.0f);
                if (func_8010B990(param_0, 0x504427) & 0x26) {
                    func_80801C7C_chfactoryrobot(param_0);
                }
            } else {
                func_80801C7C_chfactoryrobot(param_0);
                r->f24 = func_800DC178(2.0f, 4.0f);
            }
        } else {
            scale = 0.0f;
        }
    }
} else {

func_80104580(param_0);
}
r->f28 += 0.7f * (func_800F12D4(*(f32 *) &param_0->actorData[3] * scale, 0.0f, 420.0f, 1.0f, 1.1f) -
                  r->f28);
return 1;
}

void func_8080183C_chfactoryrobot(param_0) Actor *param_0;
{
    RobotSoundState *local_1;
    RobotSoundLimits local_0;
    s32 local_2;
    s32 local_3;

    local_1 = func_80100094(param_0, 0);
    local_0 = D_80802ACC_chfactoryrobot;
    for (local_2 = 0; local_2 != 2; local_2++) {
        local_1->local_0[local_2] = 0;
    }
    func_80802398_chfactoryrobot(param_0);
    local_0.local_0 *= param_0->scale;
    local_0.local_1 *= param_0->scale;
    local_3 = func_800C8A98();
    local_1->local_1 = local_3;
    func_800C8E84(local_3, ((s32 *) D_80802890_chfactoryrobot));
    func_800C8CB8(local_1->local_1, param_0->position);
    func_800C8F64(local_1->local_1, 3);
    func_800C8D4C(local_1->local_1, &local_0);
    func_800C8FE0(local_1->local_1, local_1->local_2 > 0.0f);
    if (param_0->unk70_10 != 1) {
        _subaddierouteDll_entrypoint_1(param_0);
    }
}

void func_80801954_chfactoryrobot(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    if (param_0->unk70_10 != 5) {
        *(f32 *) (local_0 + 0x10) = func_800F1FF0(*(f32 *) (local_0 + 0x10), param_0->unk54, 0.1f,
                                                  local_1 * 0.5f, local_1 * 150.0f);
        *(f32 *) (local_0 + 0xC) = func_800F1FF0(*(f32 *) (local_0 + 0xC), param_0->unk54, 0.2f,
                                                 local_1 * 4.0f, local_1 * 400.0f);
    }
    local_2 = func_8010262C(param_0->unk0, 2);
    if (local_2) {
        func_800E0AFC(local_2, 3, 1.0f, 0.0f, *(f32 *) (local_0 + 0x10), 0.0f);
        func_800E0AFC(local_2, 0x12, 1.0f, 0.0f,
                      func_800136E4(*(f32 *) (local_0 + 0xC) - *(f32 *) (local_0 + 0x10)), 0.0f);
    }
}

s32 func_80801A80_chfactoryrobot(Actor *param_0)
{
    FactoryRobotDelayState *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_1 > 0.0f)
        return 0;
    if (((FactoryRobotControl *) param_0)->local_0) {
        local_1 = _subaddiejoy_entrypoint_6(param_0, 0);
    } else {
        if (local_0->local_0)
            return 0;
        local_1 = func_800D9078(&param_0->unk58);
    }
    if (local_1) {
        func_80801160_chfactoryrobot(param_0, 4);
        local_0->local_1 = 0.0f;
        return 1;
    }
    return 0;
}

int func_80801B3C_chfactoryrobot(Actor *param_0)
{
    int local_0;

    if (((FactoryRobotControl *) param_0)->local_0) {
        local_0 = _subaddiejoy_entrypoint_6(param_0, 0);
    } else {
        local_0 = 0;
    }
    if (local_0 || func_800D9078(&param_0->unk58)) {
        func_80801160_chfactoryrobot(param_0, 2);
    }
    return local_0;
}

s32 func_80801BB0_chfactoryrobot(param_0)
Actor *param_0;
{
    RobotWaitState *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0->timer > 0.0f)
        return 1;
    if (((RobotEnabledState *) param_0)->enabled && _subaddiejoy_entrypoint_6(param_0, 1)) {
        func_800C8FE0(local_0->handle, 1);
        local_0->timer = func_800DC178(1.2f, 1.6f);
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

void func_80801C7C_chfactoryrobot(Actor *param_0)
{
    s16 *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800CD1E0((((u32 *) param_0)[0x1C] >> 25) - 1, (f32 *) param_0->actorData,
                  local_0[1] + 60.0f);
    local_0[3] = (s32) func_800DC178(100.0f, 200.0f);
}

void func_80801D08_chfactoryrobot(Actor *param_0)
{
    Actor *temp_v1;
    temp_v1 = func_80100094(param_0, 0);
    if (((((u32) (*((s32 *) (((char *) param_0) + 0x70)))) << 22) >> 26) == 0) {
        *((u16 *) (((char *) param_0) + 0x72)) =
            ((*((u16 *) (((char *) param_0) + 0x72))) & 0xFC0F) | 0x10;
    }
    if (func_800EA05C(param_0) == 0x101) {
        *((s8 *) (((char *) temp_v1) + 0x12)) = 1;
        return;

}
*(s8 *) ((char *) temp_v1 + 0x12) = 0;
}

void func_80801D7C_chfactoryrobot(u8 *param_0)
{
    u8 *s2;
    s32 v0;

    s2 = func_80100094(param_0, 0);
    v0 = func_800F54E4();
    func_800F4F34(v0, (s32 *) (s32) (param_0 + 4), 100.0f, 80.0f);

    switch ((u32) *(u16 *) (param_0 + 0x72) >> 10) {
        case 1: {
            s32 v1;
            s32 sp68;
            s32 a0;
            a0 = *(s32 *) (param_0 + 0x3C);
            if (a0 == 0) {
                func_80101FDC(param_0, 3);
            } else if ((*(f32 *) ((u8 *) func_80106790(a0) + 0x58) > 0.0f) && (s2[0x14] == 0)) {
                _sudialog_entrypoint_0(0x364, 4);
                a0 = s2[0x10];
                if (a0 < s2[0x11]) {
                    sp68 = 0;
                    v1 = 0;
                    if (a0 > 0) {
                        do {
                            if (func_800F00A4((s32) (param_0 + 4), 150.0f, 800.0f, 0.0f,
                                              (s32) ((u8 *) func_80106790(((s32 *) s2)[v1]) + 4)) !=
                                0) {
                                sp68 = 1;
                                break;
                            }
                            v1 += 1;
                        } while (v1 < s2[0x10]);
                    }
                    if (sp68 == 0) {
                        func_80108B04(param_0, 0);
                        func_80101FDC(param_0, 2);
                        *(f32 *) (param_0 + 0x58) = func_800DC178(1.5f, 2.5f);
                    }
                }
            }
            break;
        }

case 2:
    if (func_800D9078(param_0 + 0x58) != 0) {
        func_80101FDC(param_0, 1);
    }

break;

case 4:
    if ((func_8010D23C() != 0) && (func_8010C500(param_0) != 0) && (func_8008FDC4() & 0x08000000)) {
        _capod_entrypoint_13(*(s32 *) (param_0 + 0), 0, 0xC, 0x30);
        func_80101FDC(param_0, 6);
        param_0[0x65] = (u8) (param_0[0x65] & 0xFFEF);
        *(f32 *) (param_0 + 0x58) = 1.0f;
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(*(s32 *) (param_0 + 0), 0x133B, 7, (s32) (param_0 + 4), 0xA3);
    }

break;

case 6: {
    f32 sp58[3];
    s32 padY;
    f32 sp50;
    v0 = func_800D9078(param_0 + 0x58);
    sp50 = func_800F12D4(*(f32 *) (param_0 + 0x58), 0.0f, 1.0f, -200.0f, 300.0f);
    func_800EE7F8(sp58, (s32) (param_0 + 4));
    sp58[1] += sp50;
    func_800D1254(0x39, 1, sp58);
    if (!((Actor *) param_0)->unk64_20 && (*(f32 *) (param_0 + 0x58) < 0.7f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (s32) (param_0 + 4), D_80802AEC_chfactoryrobot);
        ((Actor *) param_0)->unk64_20 = 1;
    }
    if (v0 != 0) {
        func_80101FDC(param_0, 9);
    }
    break;
}

case 7: {
    f32 sp44[3];
    s32 padX;
    f32 sp3C;
    v0 = func_800D9078(param_0 + 0x58);
    sp3C = func_800F12D4(*(f32 *) (param_0 + 0x58), 0.0f, 1.0f, 300.0f, -200.0f);
    func_800EE7F8(sp44, (s32) (param_0 + 4));
    sp44[1] += sp3C;
    func_800D1254(0x39, 1, sp44);
    if (v0 != 0) {
        func_80101FDC(param_0, 0xA);
        func_800DA544(0x1BB);
    }
    break;
}

case 8:
    func_800D2498(0x101, s2[0x13], 0);

if (func_800D9078(param_0 + 0x58) != 0) {
    func_80101FDC(param_0, 9);
}

break;

case 9:
    func_800D2498(0x101, s2[0x13], 0);

if ((s2[0x10] < func_800F1418(s2[0x11], s2[0x13])) && (s2[0x14] == 0)) {
    func_80108B04(param_0, 0);
    func_80101FDC(param_0, 8);
    *(f32 *) (param_0 + 0x58) = func_800DC178(1.5f, 2.5f);
}

case 10:
    break;
    }
    s2[0x14] = 0;
    }

    void func_8080219C_chfactoryrobot(u8 *param_0)
    {
        short temp_a1;
        u8 *new_var;
        temp_a1 = *((u8 *) (((s8 *) param_0) + 0x28));
        new_var = (u8 *) (((s8 *) param_0) + 0x28);
        if (temp_a1 != 0) {
            func_800E8C08(temp_a1 & 0xFF, temp_a1, param_0);
            *new_var = 0U;
        }
    }

    void func_808021D4_chfactoryrobot(Actor *param_0, s32 param_1)
    {
        u8 local_1;
        void *local_0;
        func_801015D0(param_0);
        local_1 = func_800D731C(param_0->unk0->unk14);
        if (local_1) {
            local_0 = func_800E8C58(*(u8 *) ((u8 *) param_0 + 0x28));
            func_800DBE60(local_1, 0, local_0);
            func_800DBE60(local_1, 1, local_0);
        }
    }

    s32 func_80802240_chfactoryrobot(Actor *param_0, s32 param_1, FactoryRobotMessage36 param_2)
    {
        Actor *local_0;
        s32 local_1;

        switch (param_1) {
            case 0x3D:
                local_0 = (Actor *) func_80108528(0x3BE, param_0->position, 0, &param_0);
                if (local_0)
                    local_0->unk74_7 = param_0->unk74_7;
                break;
            case 0x2E:
                _capod_entrypoint_14();
                break;
            case 0x1F:
                func_808021D4_chfactoryrobot(param_0, param_2.local_0);
                break;
            case 0x95:
                func_808025D4_chfactoryrobot(param_0);
                break;
            case 0x29:
                ((u8 *) param_0)[0x28] = func_800E8B74(0);
                func_800E8DB0(((u8 *) param_0)[0x28], 6);
                func_800E8D28(((u8 *) param_0)[0x28], 1.2f);
                func_800E8D5C(((u8 *) param_0)[0x28], &D_80802AF4_chfactoryrobot, 3);
                break;
            case 0x2A:
                local_1 = ((u8 *) param_0)[0x28];

if (local_1) {
    func_800E8C08(local_1);
    ((u8 *) param_0)[0x28] = 0;
}

break;
default:
    return 0;
    }
    return 1;
    }

    int func_80802398_chfactoryrobot(param_0)
    Actor *param_0;
    {
        Actor *local_0;
        FactoryRobotLinks1436 *local_1;

        if (((FactoryRobotFlags1436 *) param_0)->disabled) {
            return 0;
        }
        if (!_subaddiefind_entrypoint_10(param_0, 0x3BF, param_0->unk74_7)) {
            return 0;
        }
        local_0 = func_80106790(param_0->unk3C);
        local_1 = func_80100094(local_0, 0);
        if (!((FactoryRobotFlags1436 *) local_0)->state.bits.initialized) {
            func_808025D4_chfactoryrobot(local_0);
            ((FactoryRobotFlags1436 *) local_0)->state.bits.initialized = 1;
        }
        local_1->markers[local_1->count] = param_0->unk0;
        local_1->count++;
        return 1;
    }

    s32 func_80802470_chfactoryrobot(param_0, param_1)
    Actor *param_0;
    s32 param_1;
    {
        Actor *local_0;
        RobotData_80802470_chfactoryrobot *local_1;
        s32 i;

        if (((RobotActor *) param_0)->unk78_5) {
            return 0;
        }
        if (param_0->unk3C == NULL) {
            return 0;

}
local_0 = func_80106790(param_0->unk3C);
local_1 = func_80100094(local_0, 0);
if (param_1 && local_1->unk12) {
    if (--local_1->unk13 == 0) {
        _capod_entrypoint_13(local_0->unk0, 0, 0xF, 0x30);
        func_80101FDC(local_0, 7);
        *((u8 *) local_0 + 0x65) &= ~0x10;
        local_0->unk58 = 1.0f;
        func_800FC660(0x10);
        _subaddiedialog_entrypoint_11(local_0->unk0, 0x137B, 0x44, local_0->position, 0xA3);
    }

}
param_0->unk3C = NULL;
for (i = 0; i < local_1->unk10; i++) {
    if ((s32) param_0->unk0 == local_1->unk0[i]) {
        local_1->unk0[i] = local_1->unk0[--local_1->unk10];
        return 1;
    }

}
return 0;
}

int func_808025D4_chfactoryrobot(param_0)
Actor *param_0;
{
    u8 *local_0;
    s32 local_2;
    f32 local_1[3];
    local_0 = (u8 *) func_80100094(param_0, 0);
    if (local_0[0x12]) {
        _subaddieDll_entrypoint_4(param_0, 1);
        local_0[0x13] = 6;
        func_80101FDC(param_0, func_800DA298(0x1BB) ? 10 : 4);
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 300.0f;
        func_800D1254(0x39, 1, local_1);
    } else if (!_subaddiefind_entrypoint_10(param_0, 0x3BD, param_0->unk74_7)) {
        func_80101FDC(param_0, 3);
        func_80103110(param_0, 0);
    }
    local_0[0x11] = func_800F0D90((s32) param_0->rotation[1], 1, 4);
    local_0[0x10] = 0;
    local_0[0x14] = 1;
    for (local_2 = 0; local_2 < local_0[0x11]; local_2++)
        ((s32 *) local_0)[local_2] = 0;
    if (local_0[0x12] && !func_800DA298(0x6A3) && func_800EA090() == 3) {
        _capod_entrypoint_13(param_0->unk0, 0, 8, 0x10);
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
