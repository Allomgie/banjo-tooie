#include "common.h"

extern int D_80800380_chbigterrysbits[];
extern int D_808003C8_chbigterrysbits[];
extern int D_80800410_chbigterrysbits[];
extern void func_80101FDC(Actor *, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef union {
    s32 word;
    void *pointer;
} ActorCallbackData;
extern s32 _subaddieDll_entrypoint_5(Actor *, void *);
extern void func_80103110(Actor *, s32);
extern void _chexploder_entrypoint_3(void *param_0, f32 *local_0, int param_2);
extern void _subaddieaudioquick_entrypoint_2(void *param_0, void *param_1, void *param_2);
extern void func_800DA544(int param_0);
extern void func_800EE7F8(f32 *param_0, void *param_1);
extern u8 D_80800458_chbigterrysbits[];
void func_8080022C_chbigterrysbits();

int chbigterrysbits_entrypoint_0()
{
    return (int) &D_80800380_chbigterrysbits;
}

int chbigterrysbits_entrypoint_1()
{
    return (int) &D_808003C8_chbigterrysbits;
}

int chbigterrysbits_entrypoint_2()
{
    return (int) &D_80800410_chbigterrysbits;
}

void func_80800024_chbigterrysbits(Actor *actor)
{
    s32 is_replay;
    s32 retry_flag;

    is_replay = func_800D395C();
    retry_flag = func_800DA298(0x172);
    if (func_800F64A4(func_800F54E4(), 0x1000) || _glcutDll_entrypoint_20()) {
        func_80101FDC(actor, 1);
    }
    actor->rotation[0] = -50.0f;
    func_8010A800(actor, 0);
    if (_chdoormake_entrypoint_3(actor, 0.0f, actor->rotation[0] + 90.0f, -400.0f, 0x802, -1)) {
        _chdoormake_entrypoint_5(actor, 3.0f);
        _chdoormake_entrypoint_6(actor, 0.8f);
        _chdoormake_entrypoint_8(actor, 0xE);
    }
    if (!_glcutDll_entrypoint_20() && is_replay && !retry_flag) {
        func_8010108C(actor, 8, 0);
    }
}

s32 func_80800130_chbigterrysbits(Actor *this)
{
    if (_glcutDll_entrypoint_20())
        func_800FFAB0(this);
}

void func_80800160_chbigterrysbits(void *actor)
{
    if ((2 == ((*(u16 *) ((u8 *) actor + 0x72) & 0xFFFFFFFFu) >> 10)) &&
        _subaddieDll_entrypoint_6(actor, 11)) {
        func_8080022C_chbigterrysbits(actor);
    }
}

s32 func_808001A8_chbigterrysbits(Actor *actor, s32 msg, ActorCallbackData msg_data)
{
    switch (msg) {
        case 0x3F:
            if (_subaddieDll_entrypoint_5(actor, msg_data.pointer)) {
                func_80103110(actor, 1);
                func_80101FDC(actor, 2);
            }
            break;
        case 0x40:
            func_8080022C_chbigterrysbits(actor);
            return 1;
        default:
            return 0;
    }
    return 1;
}

// Breakable piece explodes; sets flag 0x173.
void func_8080022C_chbigterrysbits(actor) Actor *actor;
{
    f32 pos[3];
    func_800EE7F8(pos, (u8 *) actor + 4);
    pos[1] -= 80.0f;
    _chexploder_entrypoint_3(actor, pos, 0xc);
    _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4,
                                     (void *) &D_80800458_chbigterrysbits);
    func_800DA544(0x173);
}

void func_8080029C_chbigterrysbits(Actor *actor)
{
    s32 boss_defeated;
    s32 is_replay;

    boss_defeated = func_800DA298(0xE5);
    is_replay = func_800D395C();
    if (_glcutDll_entrypoint_20()) {
        func_800FFAB0(actor);
    } else {
        if (boss_defeated && !is_replay)
            func_80101FDC(actor, 4);
        actor->rotation[0] = -90.0f;
        func_8010A800(actor, 0);
        if (_chdoormake_entrypoint_3(actor, actor->rotation[1], actor->rotation[0] + 90.0f,
                                     -400.0f, 3, -1)) {
            _chdoormake_entrypoint_5(actor, 3.0f);
            _chdoormake_entrypoint_6(actor, 0.8f);
        }
    }
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern void func_80108ED0();
int D_80800380_chbigterrysbits[18] = {0xAC0461,
                                      0x7C40004,
                                      0x0,
                                      (u32) _chdoor_entrypoint_0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x752F,
                                      0x0,
                                      0x0,
                                      0x400,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800024_chbigterrysbits,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      (u32) _chdoor_entrypoint_1,
                                      0x0};
int D_808003C8_chbigterrysbits[18] = {0x2FF0365,
                                      0x7530001,
                                      0x0,
                                      (u32) func_80800160_chbigterrysbits,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x752F,
                                      0x0,
                                      0x1730000,
                                      0xC00,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_80800130_chbigterrysbits,
                                      (u32) func_80107C2C,
                                      -0x7FFFD400,
                                      (u32) func_808001A8_chbigterrysbits,
                                      0x0};
int D_80800410_chbigterrysbits[18] = {0xAC0469,
                                      0x7C40001,
                                      0x0,
                                      (u32) _chdoor_entrypoint_0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x752F,
                                      0x0,
                                      0x0,
                                      0xC00,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_8080029C_chbigterrysbits,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      (u32) _chdoor_entrypoint_1,
                                      0x0};
u8 D_80800458_chbigterrysbits[24] = {0x0,  0x13, 0x4,  0xF4, 0x0, 0xA, 0x0, 0xCC,
                                     0x0,  0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xE2,
                                     0x1F, 0x40, 0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
