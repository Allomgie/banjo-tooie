#include "common.h"

extern int D_80800928_chmricecube[];
typedef struct {
    u8 pad_0[0x1A];
    u16 val : 11;
    u16 pad_1A : 5;
} RiceCubeMsg;
extern u8 D_808009A8_chmricecube[];
extern u8 D_808008B0_chmricecube[];
extern void func_800EE7F8();
extern void func_800EF1B8(f32 *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 D_808009B8_chmricecube[];
extern void _subaddiedialog_entrypoint_8(s32, s32, s32 *, s32 *, s32);
extern s32 D_80800A00_chmricecube[];
extern f32 D_80800970_chmricecube[];
extern f32 D_80800980_chmricecube[];
extern f32 D_80800990_chmricecube[];
extern s32 func_80101DDC(Actor *);
extern void func_80102424(Actor *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern void _capod_entrypoint_14(void);
extern void _glcutDll_entrypoint_6(s32, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
extern void func_800C4AF0(f32 *, f32 *);
extern void func_80101180(s32, s32, s32);
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_80102FDC(Actor *, f32);
extern void _subaddiefade_entrypoint_1(Actor *, s32);
extern void func_800DA544(s32);
extern void _glcutDll_entrypoint_17(void);
extern s32 func_800D90A4(f32 *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern f32 func_800DC178(f32, f32);
extern u8 D_808009C8_chmricecube[];
void func_808007B0_chmricecube();

int *chmricecube_entrypoint_0()
{
    return &D_80800928_chmricecube;
}

void func_8080000C_chmricecube(void *actor)
{
    f32 *actor_copy;
    actor_copy = (char *) actor;
    func_800EE7F8((void *) (actor_copy + 6), (void *) ((char *) actor + 4));
    *(f32 *) ((char *) actor + 0x2C) = 0.f;
    *(f32 *) ((char *) actor + 0x54) = *(f32 *) ((char *) actor + 0x48);
    func_8010A5B0(actor, func_800DA298(0x1C9));
    if (_glcutDll_entrypoint_20() != 0) {
        *(f32 *) ((char *) actor + 0x48) = (f32) (*(f32 *) ((char *) actor + 0x48) - 180.0f);
        func_80102424(actor, 6);
        return;
    }
    if (func_800DA298(0x31B) != 0) {
        func_800FFAB0(actor_copy);
    }
}

void func_808000AC_chmricecube(Actor *actor)
{
    f32 dt_slide;
    f32 dt_fall;
    s32 timer_done;
    f32 dt_melt;

    switch (actor->unk70_10) {
        case 1:
            func_80800778_chmricecube(actor);
            break;
        case 2:
            actor->unk64_19 = 1;
            func_80800850_chmricecube(actor);
            if (func_80101DDC(actor)) {
                func_80102424(actor, 3);
            }
            break;
        case 4:
            if (func_80101DDC(actor)) {
                actor->unk64_19 = 0;
                func_80102424(actor, 1);
            }
            break;
        case 5:
            dt_slide = func_800D8FF8();
            ((f32 *) actor->actorData)[3] =
                func_800F15F8(((f32 *) actor->actorData)[3], 200.0f, dt_slide * 150.0f);
            func_800EF1B8(actor->position, actor->unk54,
                          -(((f32 *) actor->actorData)[3] * dt_slide));
            actor->unk64_19 = 1;
            ((f32 *) actor->actorData)[6] =
                func_800F15F8(((f32 *) actor->actorData)[6], 100.0f, dt_slide * 120.0f);
            actor->rotation[1] += ((f32 *) actor->actorData)[6] * dt_slide;
            if (160000.0f < func_800EFC7C(actor->position, (f32 *) actor->actorData)) {
                if (!actor->unk64_20) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800970_chmricecube);
                    actor->unk64_20 = 1;
                }
                ((f32 *) actor->actorData)[5] += dt_slide * 800.0f;
                actor->position[1] -= dt_slide * ((f32 *) actor->actorData)[5];
                // Fell 8000 units: start the Lava Side cutscene.
                if (actor->position[1] < ((f32 *) actor->actorData)[1] - 8000.0f) {
                    _capod_entrypoint_14();
                    _glcutDll_entrypoint_6(0x127, 0x49);
                }
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_80800980_chmricecube);
            }
            break;
        case 8:
            dt_fall = func_800D8FF8();
            ((f32 *) actor->actorData)[6] =
                func_800F15F8(((f32 *) actor->actorData)[6], 100.0f, dt_fall * 120.0f);
            ((f32 *) actor->actorData)[5] += dt_fall * 800.0f;
            actor->position[1] -= dt_fall * ((f32 *) actor->actorData)[5];
            actor->rotation[1] += ((f32 *) actor->actorData)[6] * dt_fall;
            if (actor->position[1] < 600.0f) {
                actor->position[1] = 600.0f;
                func_800C4AF0(actor->position, D_80800990_chmricecube);
                func_80102424(actor, 9);
                actor->unk58 = 4.0f;
                func_80101180(0x439, 10, 999);
            }
            break;
        case 9:
            timer_done = func_800D9078(&actor->unk58);
            dt_melt = func_800D8FF8();
            actor->position[1] = func_800F12D4(actor->unk58, 0.0f, 4.0f, 400.0f, 600.0f);
            func_80102FDC(actor, func_800F12D4(actor->unk58, 0.0f, 4.0f, 0.5f, 1.0f));
            _subaddiefade_entrypoint_1(actor,
                                       func_800F12D4(actor->unk58, 0.0f, 4.0f, 0, 255.0f));
            if (1.0f < actor->unk58) {
                ((f32 *) actor->actorData)[6] =
                    func_800F15F8(((f32 *) actor->actorData)[6], 0.0f, dt_melt * 40.0f);
                func_808007B0_chmricecube(actor);
            }
            actor->rotation[1] += ((f32 *) actor->actorData)[6] * dt_melt;
            if (timer_done) {
                // Melted: lava pool cooled flag.
                func_800DA544(0x31B);
                _glcutDll_entrypoint_17();
            }
            break;
        case 6:
            func_80800850_chmricecube(actor);
            actor->unk64_19 = 1;
            if (func_80101DDC(actor)) {
                func_80102424(actor, 7);
            }
    }
}

int func_8080050C_chmricecube(Actor *actor, s32 msg, s32 msg_arg)
{
    u32 state;
    Vec3f pos;
    u8 *msg_data;
    s16 dialog_id;

    switch (msg) {
        case 0x2E:
            dialog_id = ((s16 *) &msg_arg)[0];
            if (_subaddiedialog_entrypoint_9(actor, dialog_id, D_808008B0_chmricecube, 5) == 1) {
                func_8010A590(actor);
            }
            state = actor->unk70_10;
            if (state == 3 || state == 2) {
                func_80102424(actor, 4);
            }
            break;
        case 0x40:
            msg_data = (u8 *) msg_arg;
            func_8010A624(actor);
            func_800EE7F8(pos.f, actor->position);
            func_800EF1B8(pos.f, actor->rotation[1], 300.0f);
            func_800F77E8(((RiceCubeMsg *) msg_data)->val, pos.f);
            _capod_entrypoint_13(actor->unk0, 0, 0, 0x831);
            func_80102424(actor, 5);
            _subaddieDll_entrypoint_4(actor, 1);
            func_8010A570(actor);
            func_800FC660(14);
            break;
        case 0x49:
            if (func_800EA05C() == 0x127 && _glcutDll_entrypoint_19(0x49)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x13CC, 4, 0, 0xA9);
                func_80102424(actor, 8);
                _subaddieDll_entrypoint_4(actor, 1);
                *(f32 *) &actor->actorData[6] = 100.0f;
                *(f32 *) &actor->actorData[5] = 1200.0f;
                _capod_entrypoint_13(actor->unk0, 0, 0x13, 0x2831);
                break;
            }
            return 0;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808009A8_chmricecube, actor->scale);
            break;
        case 0x95:
            if (func_800EA05C() == 0x127 && !_glcutDll_entrypoint_19(0x49)) {
                func_800FFAB0(actor);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800734_chmricecube(u8 *actor, s32 unk_1)
{
    func_800DF744(3, (u32) (*(s32 *) ((char *) actor + 0x64) << 0xC) >> 0x1F);
    func_80101870(actor, unk_1);
}

int func_80800778_chmricecube(s32 actor)
{
    s32 unk_0;
    unk_0 = 5;
    _subaddiedialog_entrypoint_8(actor, actor + 4, &D_808009B8_chmricecube,
                                 (s32 *) D_808008B0_chmricecube, unk_0);
}

void func_808007B0_chmricecube(actor) Actor *actor;
{
    f32 pos_low[3];
    f32 pos_high[3];
    if (func_800D90A4((f32 *) &actor->actorData[4])) {
        func_800EE7F8(pos_low, actor->position);
        pos_low[1] = 200.0f;
        func_800EE7F8(pos_high, actor->position);
        pos_high[1] = 600.0f;
        func_800BBCB8(pos_high, pos_low, actor->scale, 5, D_808009C8_chmricecube);
        *(f32 *) &actor->actorData[4] = func_800DC178(0.1f, 0.15f);
    }
}

int func_80800850_chmricecube(s32 actor)
{
    s32 pos;
    pos = actor + 4;
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80800A00_chmricecube, 0x3DCCCCCD);
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of
// this file; IDO schedules some of them differently unless the tables are in the same unit.
// The extern declarations of D_80800928/9B8/A00 are adjusted to the object (same addresses).
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_808008B0_chmricecube[40] = {0x0,  0x0,  0x0,  0x1,  0x13, 0xCA, 0x1,  0x0, 0x0,  0x0,
                                 0x6,  0x1,  0x13, 0xCB, 0x2,  0x0,  0x0,  0x0, 0x2,  0x0,
                                 0x14, 0x52, 0x1,  0x0,  0x0,  0x0,  0x4,  0x0, 0x14, 0x53,
                                 0x1,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u32 D_808008D8_chmricecube[20] = {0x0,        0x0,        0x3FA66666, 0x4A80044,  0x3FA66666,
                                  0x4A80002,  0x3FA66666, 0x4A90001,  0x3FA66666, 0x4A80092,
                                  0x3FA66666, 0x4A80002,  0x3FA66666, 0x4A80002,  0x3FA66666,
                                  0x4A90001,  0x3FA66666, 0x4A90001,  0x3FA66666, 0x4A90001};
int D_80800928_chmricecube[18] = {0xAE03E7,
                                  0x9150001,
                                  (u32) &D_808008D8_chmricecube,
                                  (u32) func_808000AC_chmricecube,
                                  (u32) func_80105834,
                                  (u32) func_80800734_chmricecube,
                                  0x7D00000,
                                  0x0,
                                  0x0,
                                  0x20904,
                                  0x0,
                                  (u32) func_80108ED0,
                                  0x0,
                                  (u32) func_8080000C_chmricecube,
                                  (u32) func_80107C2C,
                                  -0x7FFFFBFE,
                                  (u32) func_8080050C_chmricecube,
                                  0x0};
f32 D_80800970_chmricecube[4] = {1.746407e-39f, 9.18928e-40f, 1.83705e-40f, 0.0f};
f32 D_80800980_chmricecube[4] = {1.746332e-39f, 9.18785e-40f, 1.83705e-40f, 0.0f};
f32 D_80800990_chmricecube[6] = {1.746618e-39f, 9.1882e-40f,   2.204081e-39f,
                                 1.435e-42f,    9.367223e-39f, 0.0f};
u8 D_808009A8_chmricecube[16] = {0x43, 0xF0, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0,
                                 0x43, 0x8E, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0};
s32 D_808009B8_chmricecube[4] = {0x1C90000, 0x19000A9, 0xC, 0x200};
u8 D_808009C8_chmricecube[56] = {0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0,  0x0, 0x2D, 0x1, 0x90,
                                 0x2, 0x58, 0x0, 0xB,  0x0, 0xF0, 0x0, 0xFA, 0x0, 0x0,  0x0, 0x0,
                                 0x0, 0x22, 0x0, 0x99, 0x1, 0x0,  0x3, 0x0,  0x3, 0x80, 0x0, 0x15,
                                 0x0, 0x0,  0x0, 0xB3, 0x0, 0x2B, 0x0, 0x80, 0x0, 0x99, 0x0, 0x1E,
                                 0x0, 0x64, 0x0, 0x64, 0x0, 0x0,  0x0, 0x0};
s32 D_80800A00_chmricecube[4] = {0x13047F, 0xD00F3, 0x10C0000, 0x0};
