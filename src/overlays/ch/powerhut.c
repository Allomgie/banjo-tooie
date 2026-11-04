#include "common.h"

// Per-actor state of a power hut.
typedef struct {
    s16 delay;
    u16 pad_2;
    f32 unk_4;
    u32 pad_8;
    s16 phase;
    u8 hum_loop;
    u8 pad_F;
    u32 pad_10;
    f32 light_level;
} PowerHutState;
// Per-hut config record; flag is the game flag set when the hut is powered.
typedef struct {
    u16 flag;
    u8 pad_2[6];
    f32 unk_8;
} PowerHutSetup;
extern void *func_80100094(Actor *, u32);
extern void func_800EE88C();
extern s32 func_800D9058(f32);
extern u8 D_80800970_chpowerhut[];
extern f32 D_80800988_chpowerhut[3];
extern void *func_800D674C(s32);
extern void func_800DE448(f32 *, f32 *, f32, s32, void *);
extern u8 D_80800950_chpowerhut[];
extern u8 D_80800964_chpowerhut[];
extern u8 D_80800958_chpowerhut[];
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s32);
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern u8 D_80800994_chpowerhut[];
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, f32 *, f32 *, void *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern int D_808009C0_chpowerhut[];
extern f32 _sumumbofx_entrypoint_22(void *);
extern u8 D_808009A0_chpowerhut[];
extern u8 D_808009B4_chpowerhut[];
extern int func_800D9078();
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern void func_80018820(s32, f32, f32);
extern void func_800E15CC(s32, f32, f32);
void func_80800400_chpowerhut();
int func_8080047C_chpowerhut();
s32 func_808005F4_chpowerhut();
int func_80800698_chpowerhut();

s32 chpowerhut_entrypoint_0(Actor *actor, PowerHutSetup *config)
{
    PowerHutState *state;

    state = func_80100094(actor, 0);
    func_800EE88C((f32 *) &actor->actorData[0], _gccubesearch_entrypoint_0(0x154, actor));
    state->unk_4 = config->unk_8;
    state->delay = func_800D9058(1.5f);
    state->phase = 1;
    state->hum_loop = 0;
    state->light_level = 0.0f;
    if (func_800DA298(config->flag) || _glcutDll_entrypoint_20()) {
        func_80101FDC(actor, 5);
        state->phase = 4;
        state->light_level = 1.0f;
        return 1;
    }
    return 0;
}

s32 chpowerhut_entrypoint_1(Actor *actor, u16 *config)
{
    _subaddieaudioloop_entrypoint_5(actor, actor->position,
                                    func_800DA298(config[0]) != 0 ||
                                        _glcutDll_entrypoint_20() != 0,
                                    0x708, D_80800970_chpowerhut);
    switch (actor->unk70_10) {
        case 2:
            func_8080047C_chpowerhut(actor, config);
            break;
        case 3:
            func_8080047C_chpowerhut(actor, config);
            func_80800698_chpowerhut(actor, config);
            break;
        case 4:
            func_8080047C_chpowerhut(actor, config);
            if (func_808005F4_chpowerhut(actor)) {
                _subaddieDll_entrypoint_4(actor, 0);
                return 1;
            }
    }
    return 0;
}

void chpowerhut_entrypoint_2(Actor *actor, s32 param_1)
{
    u8 *state;
    s32 lit_index;
    s32 i;

    state = func_80100094(actor, 0);
    if (func_80100094(actor, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(actor, 1), param_1);
    }
    if (*(s16 *) (state + 0xC) == 3) {
        lit_index = func_800DC128(0, 4);
        for (i = 0; i < 4; i++) {
            func_800DF744(i + 1, lit_index == i ? 1 : 0);
        }
        func_800DF830(2);
        func_800DE448((f32 *) ((u8 *) actor + 0x18), D_80800988_chpowerhut, 2.5f, 0,
                      func_800D674C(0x742));
    }
}

int chpowerhut_entrypoint_3(Image *param_0, s32 param_1, u8 param_2, OSIoMesgHdr *param_3)
{
    Image *actor;
    s32 light;
    u8 *color;

    actor = param_0;
    switch (param_1) {
        case 0xA:
            if ((func_800DA298(*(u16 *) ((char *) param_3 + 0x0)) != 0) ||
                (_glcutDll_entrypoint_20() != 0)) {
                return 0;
            }
            func_80101FDC(actor, 2);
            _subaddieDll_entrypoint_4(actor, 1);
            func_80103110(actor, 1);
            func_80800400_chpowerhut(actor);
            _capod_entrypoint_13(*(u8 **) ((char *) actor + 0x0), 0,
                                 *(u16 *) ((char *) param_3 + 0x2),
                                 *(u16 *) ((char *) param_3 + 0x4));
            goto block_13;
        case 0x95:
            *(u8 *) ((char *) func_80100094(actor, 0) + 0xE) = 0;
            light = func_800C8A98();
            *(s32 *) ((char *) actor + 0x28) = light;
            func_800C8D4C(light, D_80800950_chpowerhut);
            func_800C8CB8(*(s32 *) ((char *) actor + 0x28), (u8 *) actor + 0x18);
            if ((func_800DA298(*(u16 *) ((char *) param_3 + 0x0)) != 0) ||
                (_glcutDll_entrypoint_20() != 0)) {
                color = D_80800964_chpowerhut;
            } else {
                color = D_80800958_chpowerhut;
            }
            func_800C8E84(*(s32 *) ((char *) actor + 0x28), color);
            func_80103110(actor, func_800DA298(*(u16 *) ((char *) param_3 + 0x0)));
            goto block_13;
        default:
            return 0;
    }
block_13:
    return 1;
}

// Starts the Mumbo beam effect on the hut.
void func_80800400_chpowerhut(param_0) Actor *param_0;
{
    void *beam;
    _sumumbofx_entrypoint_0(param_0, 1, 20, (s16) _chmumbopad_entrypoint_0(3));
    beam = func_80100094(param_0, 1);
    _sumumbofx_entrypoint_2(beam);
    _sumumbofx_entrypoint_24(beam, 2.25f);
    _sumumbofx_entrypoint_15(beam, 3.0f);
    _sumumbofx_entrypoint_20(beam, 3.0f);
}

int func_8080047C_chpowerhut(param_0, param_1)
Actor *param_0;
u8 *param_1;
{
    f32 origin[3];
    void *beam;
    u8 *state;
    beam = func_80100094(param_0, 1);
    state = func_80100094(param_0, 0);
    func_800EFD24(origin);
    if (func_800DA298(0x9DE)) {
        _sumumbofx_entrypoint_6(beam, 500.0f, (f32) (u32) *(u16 *) (param_1 + 6), 0, 20,
                                origin, param_0->position, &D_80800994_chpowerhut);
        switch (param_0->unk70_10) {
            case 2:
                if (_sumumbofx_entrypoint_21(beam) == 0.0f &&
                    _sumumbofx_entrypoint_5(beam, 1.85f)) {
                    _sumumbofx_entrypoint_17(beam, *(f32 *) (param_1 + 8));
                    func_80101FDC(param_0, 3);
                }
                break;
            case 3:
                *(f32 *) (state + 8) = *(f32 *) (param_1 + 8) - *(f32 *) (state + 4);
                if (func_800D9078(state + 4)) {
                    _chglowbo_entrypoint_6();
                    _sumumbofx_entrypoint_16(beam, 1.5f);
                    func_80101FDC(param_0, 4);
                }
        }
        _sumumbofx_entrypoint_14(beam);
    }
}

s32 func_808005F4_chpowerhut(param_0)
Actor *param_0;
{
    u16 *delay;
    if (_sumumbofx_entrypoint_22(func_80100094(param_0, 1)) < 0.05f) {
        delay = func_80100094(param_0, 0);
        if (*delay) {
            *delay = *delay - 1;
            return 0;
        } else {
            _sumumbofx_entrypoint_1(param_0, 1);
            func_80101FDC(param_0, 5);
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            return 1;
        }
    }
    return 0;
}

int func_80800698_chpowerhut(param_0, param_1)
Actor *param_0;
u8 *param_1;
{
    u8 *state;
    s32 done;

    state = func_80100094(param_0, 0);
    state[0xE] = _subaddieaudioloop_entrypoint_7(
        state[0xE], (f32 *) param_0->actorData, *(s16 *) (state + 0xC) == 3,
        D_808009A0_chpowerhut, *(u32 *) ((u8 *) param_0 + 0x70) & 1);
    switch (*(s16 *) (state + 0xC)) {
        case 1:
            if (*(f32 *) (param_1 + 0xC) < *(f32 *) (param_1 + 8) - *(f32 *) (state + 4)) {
                *(s16 *) (state + 0xC) = 2;
            }
            break;
        case 2:
            _subaddieaudioquick_entrypoint_2(param_0, (f32 *) param_0->actorData,
                                             D_808009B4_chpowerhut);
            *(s16 *) (state + 0xC) = 3;
            *(f32 *) (state + 0x10) = *(f32 *) (param_1 + 0x10);
            func_800C8E84(param_0->actorData[4], D_80800964_chpowerhut);
            func_80018820(0, 2.0f, 1.0f);
            func_800E15CC(0, 20.0f, 0.9f);
            func_800DA544(*(u16 *) param_1);
            func_80101180(0x33D, 0xA, 0);
            break;
        case 3:
            done = func_800D9078((f32 *) (state + 0x10));
            *(f32 *) (state + 0x14) = 1.0f;
            // Random flicker of the light level.
            if (func_800DC298(0.8f) && *(f32 *) (state + 0x10) > 0.15f) {
                *(f32 *) (state + 0x14) *= func_800DC178(0.25f, 0.5f);
            }
            if (done) {
                *(s16 *) (state + 0xC) = 4;
                *(f32 *) (state + 0x14) = 1.0f;
            }
            func_80800870_chpowerhut(param_0);
    }
}

int func_80800870_chpowerhut(s32 param_0)
{
    int pos;
    int pos_copy;
    // Matching: ^ with a zeroed temporary and the duplicate pos copy are needed for the match.
    pos = 0;
    if (!func_8001210C(3 ^ pos)) {
        pos = param_0 + 0x18;
        pos_copy = pos;
        func_800BBCB8(pos, pos_copy, 0x3F800000, 2, &D_808009C0_chpowerhut);
    }
}

int chpowerhut_entrypoint_4(Actor *actor, f32 param_1, f32 *param_2)
{
    f32 *state;
    f32 limit;
    state = func_80100094(actor, 0);
    limit = param_2[2] - state[1];
    return param_1 < limit && state[2] <= param_1;
}

u8 D_80800950_chpowerhut[8] = {0x44, 0x16, 0x0, 0x0, 0x44, 0x96, 0x0, 0x0};
u8 D_80800958_chpowerhut[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0x20};
u8 D_80800964_chpowerhut[12] = {0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x20};
u8 D_80800970_chpowerhut[24] = {0x0, 0x13, 0x5,  0x27, 0x0, 0xE, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x19,
                                0x0, 0x16, 0x4E, 0x20, 0x0, 0x1, 0x2, 0x58, 0x9, 0xC4, 0x0, 0x0};
f32 D_80800988_chpowerhut[3] = {0.0f, 0.0f, 0.0f};
u8 D_80800994_chpowerhut[12] = {0x0, 0x0, 0x0, 0x0, 0x42, 0xB4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_808009A0_chpowerhut[20] = {0x0, 0x13, 0x5, 0x2E, 0x0, 0xD,  0x1,  0x26, 0x1, 0x40,
                                0x0, 0x18, 0x0, 0x1,  0x5, 0xDC, 0x1F, 0x40, 0x0, 0x0};
u8 D_808009B4_chpowerhut[12] = {0x0, 0x13, 0x6, 0x11, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
int D_808009C0_chpowerhut[16] = {0x1D09DD,  0xE001E,   0x28002D, 0x9600FA,  0x20C0FF,  -0x3F3FFFCF,
                                 -0x270028, 0x161208,  0x2200CC, 0x1000199, 0x1CC0015, 0x190099,
                                 0x2B0133,  0x1990000, 0x0,      0x0};
