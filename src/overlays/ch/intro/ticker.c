// Director of the story cutscenes: per cutscene map it starts music and sounds, sets story flags,
// chains to the next cutscene or warps back into the game, and lets Start skip. Runs intro sync.
#include "common.h"

extern void func_800FC6B0();
extern void func_800FCA90();
extern void func_800FCAE0();
typedef struct {
    s16 map;
    s16 music;
    s16 effect;
    s16 pad;
} IntroTickerAudio;
extern IntroTickerAudio D_80800830_chintroticker[15];
extern s32 D_808008A8_chintroticker[];
extern s32 D_808008C0_chintroticker[];
extern void _glintrosyncDll_entrypoint_2(f32);
extern void _glcutDll_entrypoint_14(s32);
extern void _glcutDll_entrypoint_24(s32, s32, s32);
extern f32 func_800D9004(void);
extern f32 func_800D8FF8(void);
extern void _glintrosyncDll_entrypoint_4(f32);
typedef struct {
    s16 map;
    s16 next_map;
} IntroTickerEntry;
extern IntroTickerEntry D_808008C4_chintroticker[28];
extern void *D_80800934_chintroticker;

// Starts the music and sound effect listed for the current map.
void func_80800000_chintroticker(Actor *actor)
{
    s32 i;
    s32 map;

    map = func_800EA05C();
    for (i = 0; i < 15; i++) {
        if (D_80800830_chintroticker[i].map == map) {
            if (D_80800830_chintroticker[i].music != -1) {
                if (func_800FCCD4(D_80800830_chintroticker[i].music)) {
                    func_800FCAE0(D_80800830_chintroticker[i].music, 0, 0x2EE0);
                    func_800FCA90(D_80800830_chintroticker[i].music);
                }
            }
            if (D_80800830_chintroticker[i].effect != -1) {
                func_800FC6B0(D_80800830_chintroticker[i].effect);
            }
        }
    }
}

// Classifies the map into a sequence group stored in the actor.
s32 func_808000B0_chintroticker(actor, map)
Actor *actor;
s32 map;
{
    s32 group;

    group = 0;
    switch (map) {
        case 0x167:
            0;
            break;
        case 0xA1:
        case 0xA2:
        case 0xA3:
        case 0xA4:
        case 0xA5:
        case 0xA6:
        case 0xA7:
        case 0xA8:
        case 0xA9:
        case 0xAA:
        case 0xAB:
        case 0xAC:
            group = 2;
            break;
        case 0x17E:
        case 0x18C:
        case 0x18D:
        case 0x18E:
        case 0x18F:
        case 0x190:
            group = 3;
            break;
        case 0x192:
        case 0x193:
        case 0x194:
        case 0x195:
        case 0x197:
        case 0x198:
        case 0x199:
            group = 4;
            break;
        case 0x191:
        case 0x196:
            group = 5;
            break;
        case 0x18B:
            group = 1;
            break;
    }
    if (D_808008A8_chintroticker[group])
        _gcfrontend_entrypoint_9(D_808008A8_chintroticker[group]);
    actor->unk79_4 = group;
    return 1;
}

void func_80800188_chintroticker(actor, map) Actor *actor;
s32 map;
{
    if (map == 0xA1 || map == 0x18B || map == 0x18E || map == 0x194 ||
        map == 0x196) {
        switch (actor->unk79_4) {
            case 0:
            case 5:
                break;
            case 1:
                if (func_800167F4())
                    _chattract_entrypoint_1(3);
                break;
            case 2:
                func_800DA544(0x578);
                break;
            case 3:
                func_800DA524(0x360);
                func_800DA524(0x3B);
                break;
            case 4:
                func_800DA544(0x360);
                func_800DA524(0x3B);
                func_800DA524(0x578);
        }
    }
}

void func_80800254_chintroticker(actor) u8 *actor;
{
    int offset;
    u8 byte;
    u32 group;
    offset = 0x79;
    byte = *(u8 *) ((s8 *) actor + offset);
    offset = byte;
    group = (u8) offset >> 4;
    switch (group) {
        case 2:
            func_800DA524(0x578);
            return;

        case 3:
            func_800DA544(0x360);
            func_800DA524(0x3B);
            return;

        case 4:
            func_800DA524(0x360);
            func_800DA544(0x3B);
            func_800DA524(0x1A5);
            func_800DA544(0x578);

        case 0:

        case 5:
            return;
    }
}

void func_808002DC_chintroticker(Actor *actor)
{
    s32 i;
    s32 map;

    map = func_800EA05C();
    for (i = 0; i < 1; i++) {
        if (map == D_808008C0_chintroticker[i]) {
            _glintrosyncDll_entrypoint_2(0.0f);
        }
    }
    if (!func_808000B0_chintroticker(actor, map)) {
        func_800FFAB0(actor);
    } else {
        func_80800188_chintroticker(actor, map);
        if (_glcutDll_entrypoint_18() == 0x68) {
            actor->unk64_20 = 1;
        }
        func_80800000_chintroticker(actor);
        ((f32 *) actor->actorData)[5] = ((f32 *) actor->actorData)[4] = 0;
    }
}

// Empty callback.
void func_808003BC_chintroticker(s32 arg0)
{
}

void func_808003C4_chintroticker(actor) Actor *actor;
{
    func_80800254_chintroticker();
    if (func_800D395C()) {
        _gcfrontend_entrypoint_10();
        func_800EA334(1);
        return;
    }
    if (func_800DB9B0()) {
        _glcutDll_entrypoint_12(1);
        _glcutDll_entrypoint_17();
        return;
    }
    switch (actor->unk79_4) {
        case 2:
            func_800A7990(0xAF, 4, 1);
            break;
        case 1:
            _gsattract_entrypoint_5(0);
        case 3:
            break;
        case 4:
            func_800A7990(0x160, 4, 1);
            break;
        case 5:
            _gcfrontend_entrypoint_13();
    }
}

void func_808004A8_chintroticker(Actor *actor, s32 next_map)
{
    if (!func_800A8264()) {
        if (next_map >= 0) {
            if (actor->unk64_20) {
                _glcutDll_entrypoint_14(1);
                _glcutDll_entrypoint_24(next_map, -1, -1);
            } else
                func_800A7990(next_map, 0, 1);
        } else
            func_808003C4_chintroticker(actor);
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_80800530_chintroticker(s32 actor, s32 map)
{
    s16 *entry;
    int count;
    s16 next_map;
    u32 index;
    entry = (s16 *) D_808008C4_chintroticker;
    do { count = 0x1C; index = 0; loop_1: if (map != *entry) { next_map = count; index += 1; entry += 2; if (index != next_map) { goto loop_1; } } } while (0);
    if (index < 0x1CU)
    {
        loop_4:
        next_map = *(s16 *) ((s8 *) entry + 2);

        index += 1;
        if (next_map < 0)
        {
            func_808004A8_chintroticker(actor, next_map);
            return;
        }
        entry += 2;
        if (index >= 0x1CU)
        {}
        else
        {
            goto loop_4;
        }
    }
}

void func_808005AC_chintroticker(Actor *actor)
{
    s32 map;
    s32 i;

    map = func_800EA05C();
    if (func_800DA9E4(0, 0)) {
        for (i = 0; i < 28; i++) {
            if (map == D_808008C4_chintroticker[i].map) {
                func_808004A8_chintroticker(actor, D_808008C4_chintroticker[i].next_map);
            }
        }
    }
    switch (actor->unk79_4) {
        case 1:
            if (func_800DA298(0xD56) && !func_800A8264() && func_80015FA0(0) == 1) {
                _gcfrontend_entrypoint_10();
            }
            break;
        case 2:
        default:
            if (func_80016B30(0, 1) == 1)
                func_80800530_chintroticker(actor, map);
    }
    _glintrosyncDll_entrypoint_4(func_800D9004());
    *(f32 *) ((u8 *) actor + 0x28) += func_800D9004();
    *(f32 *) ((u8 *) actor + 0x2C) += func_800D8FF8();
}

void *chintroticker_entrypoint_0()
{
    return &D_80800934_chintroticker;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
IntroTickerAudio D_80800830_chintroticker[15] = {
    0x18E, -0x1, 0x87, 0x0, 0x18C, 0x87, 0x88, 0x0, 0x18F, 0x88, 0x89, 0x0, 0x190, 0x89, 0x8A, 0x0,
    0x17E, 0x8A, 0x8B, 0x0, 0x18D, 0x8B, 0x8C, 0x0, 0x194, -0x1, 0x8E, 0x0, 0x197, 0x8E, 0x8F, 0x0,
    0x198, 0x8F, 0x90, 0x0, 0x199, 0x90, 0x91, 0x0, 0x195, 0x91, 0x93, 0x0, 0x193, 0x93, 0x94, 0x0,
    0x192, 0x94, 0x95, 0x0, 0x191, -0x1, 0x98, 0x0, 0x196, 0x98, 0x99, 0x0};
s32 D_808008A8_chintroticker[6] = {0x0, 0x0, 0x80, 0x81, 0x82, 0x83};
s32 D_808008C0_chintroticker[1] = {0xA1};
IntroTickerEntry D_808008C4_chintroticker[28] = {
    0xA1,  0xA8,  0xA8,  0xA2,  0xA2,  0xA9,  0xA9,  0xA3, 0xA3,  0xAA,  0xAA,  0xA4,  0xA4,  0xAB,
    0xAB,  0xA5,  0xA5,  0xAC,  0xAC,  0xA6,  0xA6,  0xA7, 0xA7,  -0x2,  0x18E, 0x18C, 0x18C, 0x18F,
    0x18F, 0x190, 0x190, 0x17E, 0x17E, 0x18D, 0x18D, -0x3, 0x194, 0x197, 0x197, 0x198, 0x198, 0x199,
    0x199, 0x195, 0x195, 0x193, 0x193, 0x192, 0x192, -0x4, 0x191, 0x196, 0x196, -0x5,  0x18B, -0x1};
void *D_80800934_chintroticker = (void *) 0x02C50374;
static u32 D_80800934_chintroticker_rest[18] = {0x1,
                                                0x0,
                                                (u32) func_808005AC_chintroticker,
                                                (u32) func_80105834,
                                                (u32) func_8010A730,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x80004,
                                                (u32) func_808003BC_chintroticker,
                                                0x0,
                                                0x0,
                                                (u32) func_808002DC_chintroticker,
                                                (u32) func_80107C2C,
                                                0x80000202,
                                                0x0,
                                                0x0,
                                                0x0};
