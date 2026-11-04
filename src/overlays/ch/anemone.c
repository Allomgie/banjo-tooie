#include "common.h"

extern int D_808008D8_chanemone[];
extern void func_80102FDC(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern void _subaddiecustomhits_entrypoint_0(void *param_0, void *param_1);
extern void func_800E0AFC(void *param_0, s32 param_1, f32 param_2, void *param_3, f32 param_4,
                          f32 param_5);
extern s32 func_8010262C(void *param_0, s32 param_1);
extern void *_chanemone_entrypoint_1;
extern u8 D_80800954_chanemone[];
extern u32 D_80800964_chanemone[];
extern void _subaddieDll_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_5();
extern u8 D_80800920_chanemone[];
extern u8 D_80800934_chanemone[];
extern u8 D_80800944_chanemone[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern int func_800D9078(f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s32 func_800B1F8C(void *, f32 *, f32 *, f32, s32, s32, f32 *, f32, s32, s32);
void func_808005A0_chanemone();
void func_808003A8_chanemone();

int chanemone_entrypoint_0()
{
    return (int) &D_808008D8_chanemone;
}

// Per-frame update: deflect field and open/close states.
void func_8080000C_chanemone(Actor *anemone)
{
    s32 deflect_flags;
    s32 full_field;
    deflect_flags = 4;
    full_field = anemone->unk70_10 != 3;
    func_808003A8_chanemone();
    if (func_8010D23C()) {
        if (anemone->unk70_10 != 1)
            deflect_flags = 30;
        if (func_800F64A4(func_800F54E4(), 0x400))
            deflect_flags |= 2;
    }
    if (full_field) {
        _sudeflect_entrypoint_1(anemone->position, anemone->scale * 850.0f, 0.0f,
                                anemone->scale * 600.0f, deflect_flags);
        _sudeflect_entrypoint_0(anemone->position, anemone->scale * 800.0f, anemone->scale * 600.0f,
                                deflect_flags);
    } else {
        _sudeflect_entrypoint_0(anemone->position, anemone->scale * 250.0f, anemone->scale * 700.0f,
                                deflect_flags);
    }
    _subaddieaudioloop_entrypoint_5(anemone, anemone->position, anemone->unk70_10 == 1, 2000,
                                    D_80800920_chanemone);
    switch (anemone->unk70_10) {
        case 2:
            _subaddieaudioquick_entrypoint_3(anemone, anemone->position, D_80800934_chanemone,
                                             0.2f);
            if (func_80101DDC(anemone)) {
                func_80102424(anemone, 3);
                anemone->unk58 = 6.0f;
            }
            break;
        case 3:
            if (func_800D9078(&anemone->unk58))
                func_80102424(anemone, 4);
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3(anemone, anemone->position, D_80800944_chanemone,
                                             0.6f);
            if (func_80101DDC(anemone)) {
                func_80102424(anemone, 1);
                _subaddieDll_entrypoint_4(anemone, 0);
                func_8010A590(anemone);
            }
    }
}

void func_80800260_chanemone(Actor *anemone)
{
    func_80102FDC(anemone, anemone->scale * 0.5f);
    anemone->unk54 = 0.0f;
    *(f32 *) &anemone->actorData[4] = 0.0f;
    anemone->unk50 = 0.0f;
    *(f32 *) &anemone->actorData[5] = 0.0f;
    *(f32 *) &anemone->actorData[7] = func_800DC178(0.5f, 2.0f);
    anemone->actorData[6] = _subaddiesect_entrypoint_1(anemone);
    _subaddiesect_entrypoint_2(anemone, anemone->actorData[6], 0);
}

s32 func_808002E8_chanemone(void *param_0, s32 msg, volatile int payload)
{
    s32 bone;
    switch (msg) {
        case 0x3F:
            func_808005A0_chanemone(param_0, payload);
            goto block_9;

        case 0x95:
            _subaddiecustomhits_entrypoint_0(param_0, &_chanemone_entrypoint_1);
            goto block_9;

        case 0x9C:
            bone = func_8010262C(*(s32 *) param_0, 1);
            if (bone != 0) {
                func_800E0AFC(bone, 0x64, 1.0f, *(s32 *) ((u8 *) param_0 + 0x2C),
                              *(f32 *) ((u8 *) param_0 + 0x28), 0.0f);
            }
            goto block_9;

        default:
            return 0;
    }

block_9:
    return 1;
}

void func_808003A8_chanemone(anemone) Actor *anemone;
{
    f32 dt;
    Vec3f player_pos;
    Vec3f aim_pos;
    f32 angles[2];

    dt = func_800D8FF8();
    if (func_8010D23C()) {
        func_8010D254(&player_pos);
        func_800EE7F8(&aim_pos, anemone->position);
        aim_pos.f[1] += anemone->scale + 200.0f;
        func_800EF1B8(&aim_pos, anemone->rotation[1], anemone->scale * 300.0f);
        if (func_800EEB40(&player_pos, &aim_pos) < 2250000.0f) {
            func_800F18FC(&aim_pos, &player_pos, angles);
            anemone->unk54 = angles[1] - anemone->rotation[1];
            anemone->unk50 = -angles[0];
        } else if (func_800D9078(&((f32 *) anemone->actorData)[7])) {
            anemone->unk54 = func_800DC178(-60.0f, 60.0f);
            anemone->unk50 = func_800DC178(-50.0f, 50.0f);
            ((f32 *) anemone->actorData)[7] = func_800DC178(0.5f, 2.0f);
        }
    } else {
        anemone->unk54 = 0.0f;
        anemone->unk50 = 0.0f;
    }
    anemone->unk54 = func_800F0D50(func_80013728(anemone->unk54), -60.0f, 60.0f);
    anemone->unk50 = func_800F0D50(func_80013728(anemone->unk50), -50.0f, 50.0f);
    ((f32 *) anemone->actorData)[4] = func_800F1FF0(((f32 *) anemone->actorData)[4], anemone->unk54,
                                                    0.1f, (4.0f * dt), (60.0f * dt));
    ((f32 *) anemone->actorData)[5] = func_800F1FF0(((f32 *) anemone->actorData)[5], anemone->unk50,
                                                    0.1f, (4.0f * dt), (60.0f * dt));
}

void func_808005A0_chanemone(anemone, unk_1) Actor *anemone;
s32 unk_1;
{
    if (anemone->unk6C_0 == 1) {
        switch ((s32) anemone->unk70_10) {
            case 1:
            case 4:
                _subaddieaudioquick_entrypoint_2(anemone, anemone->position, D_80800954_chanemone);
                func_80102424(anemone, 2);
                _subaddieDll_entrypoint_4(anemone, 1);
                func_8010A570(anemone);
                break;
            case 3:
                anemone->unk58 = 6.0f;
                break;
        }
    }
}

s32 func_80800648_chanemone(Unk80132ED0 *param_0, f32 *param_1, f32 param_2, s32 param_3,
                            s32 param_4)
{
    f32 angle;
    s32 result;
    s32 unk_0;
    f32 dir[3];
    void *hit_data;
    Actor *actor;
    void *hit_data_alt;

    actor = func_80106790(param_0);
    switch (func_800CB854(&unk_0)) {
        case 2:
            func_800EE88C(dir, (s16 *) ((u8 *) param_0 + 0x1E));
            func_800EF04C(dir, actor->position);
            return func_800EFFB4(
                dir, (u32) *(u16 *) ((u8 *) actor + 0x68) * 0.8f * actor->scale + param_2,
                param_1);
        case 5:
            hit_data = (void *) func_80103D98(param_0);
            if (!hit_data)
                return 0;
            result = func_800B1F8C(hit_data, actor->position, actor->rotation, actor->scale,
                                    0, func_801040A8(actor), param_1, param_2, param_3, 30);
            break;
        default:
            hit_data_alt = (void *) func_80103D98(param_0);
            if (!hit_data_alt)
                return 0;
            angle = func_800136E4(
                func_800F1DCC(func_800F1DF4(actor->position, param_1), actor->rotation[1]));
            if (angle < 90.0f)
                param_4 = 12;
            else if (angle < 180.0f)
                param_4 = 24;
            else if (angle < 270.0f)
                param_4 = 18;
            else
                param_4 = 6;
            result = func_800B1F8C(hit_data_alt, actor->position, actor->rotation, actor->scale,
                                    0, func_801040A8(actor), param_1, param_2, param_3, param_4);
    }
    if (result)
        actor->unk6C_0 = result;
    return result;
}

u8 *chanemone_entrypoint_1(void)
{
    return D_80800964_chanemone;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808008B0_chanemone[10] = {0x0,       0x0,        0x3F4CCCCD, 0x14E0001,  0x3FC00000,
                                0x14F0002, 0x3FC00000, 0x14F0084,  0x40266666, 0x1500002};
int D_808008D8_chanemone[18] = {0x2F2035F,
                                0x6D20001,
                                (u32) &D_808008B0_chanemone,
                                (u32) func_8080000C_chanemone,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x11940000,
                                0x0,
                                0x0,
                                0x28,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800260_chanemone,
                                (u32) func_80107C2C,
                                -0x7FCF9BB0,
                                (u32) func_808002E8_chanemone,
                                0x0};
u8 D_80800920_chanemone[20] = {0x0, 0x13, 0x6, 0x36, 0x0, 0xA,  0x0,  0xE6, 0x0, 0x1,
                               0x3, 0x20, 0x7, 0xD0, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_80800934_chanemone[16] = {0x0, 0x13, 0x5, 0xC0, 0x0, 0xD, 0x0, 0x80,
                               0x0, 0x99, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80800944_chanemone[16] = {0x0, 0x13, 0x6, 0x37, 0x0, 0xD, 0x0, 0x80,
                               0x0, 0x99, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80800954_chanemone[16] = {0x0, 0x13, 0x4, 0xB7, 0x0,  0xD,  0x0, 0xB3,
                               0x0, 0xCC, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
u32 D_80800964_chanemone[7] = {0x0, 0x0, 0x0, (u32) func_80800648_chanemone, 0x0, 0x0, 0x0};
