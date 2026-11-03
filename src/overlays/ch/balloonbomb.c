#include "common.h"

extern int D_808004B0_chballoonbomb[];
extern void *func_80100094(Actor *, s32);
extern void func_8010D09C(s32, f32 *, f32);
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_808004F8_chballoonbomb[];
extern s32 *_fxgenlist_entrypoint_2(void);
extern void func_800BBCB8(s32, s32, s32, s32, void *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern s32 D_8080050C_chballoonbomb[];
extern s32 D_80800540_chballoonbomb[];
extern s32 D_8080057C_chballoonbomb[];
extern f32 func_800136E4(f32);
extern f32 func_800F15F8(f32, f32, f32);
typedef union {
    f32 local_0;
    s32 local_1;
} BalloonUpdateTime;
void func_80800294_chballoonbomb();
s32 func_80800440_chballoonbomb();

int *chballoonbomb_entrypoint_0()
{
    return &D_808004B0_chballoonbomb;
}

void func_8080000C_chballoonbomb(Actor *param_0)
{
    s32 local_2;
    f32 local_1[3];
    f32 *local_0;
    f32 local_4;
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    func_8010D09C(func_800F54E4(), local_1, param_0->unk58);
    for (local_2 = 0; local_2 < 3; local_2++) {
        ((f32 *) param_0->actorData)[local_2 + 4] =
            (local_1[local_2] - param_0->position[local_2]) / param_0->unk58;
    }
    ((f32 *) param_0->actorData)[5] += 250.0f * param_0->unk58;
    if (func_800DC298(0.5f)) {
        local_3 = 1.0f;
    } else {
        local_3 = -1.0f;
    }
    local_4 = func_800DC178(300.0f, 400.0f);
    local_0[0] = local_4 * local_3;
}

void func_80800230_chballoonbomb();

void func_80800118_chballoonbomb(Actor *param_0)
{
    f32 *local_0;
    BalloonUpdateTime local_1;

    local_0 = (f32 *) func_80100094(param_0, 0);
    local_1.local_0 = func_800D8FF8();
    if (!param_0->unk64_17) {
        if (func_800DA298(0))
            func_80800294_chballoonbomb(param_0);
        else if (!func_800DA298(0x641) && !func_8008FF18()) {
            param_0->rotation[1] = func_800136E4(*local_0 * local_1.local_0 + param_0->rotation[1]);
            func_80800230_chballoonbomb(param_0, local_1.local_1, 1);
            param_0->scale = func_800F15F8(param_0->scale, 1.4f, local_1.local_0 * 1.5f);
        }
    }
}

s32 func_808001F8_chballoonbomb(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x40) {
        func_80800294_chballoonbomb(param_0, param_1, param_2);
        if (param_2) {
        }
        return 1;
    }
    return 0;
}

void func_80800230_chballoonbomb(Actor *param_0, s32 param_1, s32 param_2)
{
    *(f32 *) &param_0->actorData[5] -= 500.0f * func_800D8FF8();
    if (func_8010B990(param_0, 0x500007) & 0x20) {
        func_80800294_chballoonbomb(param_0);
    }
}

void func_80800294_chballoonbomb(param_0) Actor *param_0;
{
    if (!param_0->unk64_20) {
        func_80800440_chballoonbomb();
        func_800BBCB8(param_0->position, 0, 0x3F800000, 1, _fxgenlist_entrypoint_2());
        func_800C4AF0(param_0->position, D_808004F8_chballoonbomb);
        if (param_0->unk6C_0 >= 4U) {
            func_800E1610(0, 30.0f, 0.9f, param_0->position);
            func_80018820(0, 2.0f, 0.15f);
        }
        param_0->unk64_20 = 1;
        func_800FFAB0(param_0);
    }
}

void func_80800354_chballoonbomb(s32 param_0)
{
    int new_var;
    new_var = param_0 + 4;
    func_800BBCB8(new_var, new_var, *(s32 *) ((param_0 ^ 0) + 0x38), 8, &D_8080050C_chballoonbomb);
}

void func_80800394_chballoonbomb(s32 *arg0, s32 arg1, s32 arg2)
{
    s32 sp24;
    s32 temp_a1;
    s32 temp_v0;
    if (1) {
        temp_v0 = func_800B53A4(arg2);
        sp24 = temp_v0;
        func_800BA670(temp_v0, arg1);
        temp_a1 = arg0 + 1;
    }
    func_800BABB8(sp24, temp_a1, temp_a1, *(s32 *) ((u8 *) arg0 + 0x38), &D_80800540_chballoonbomb);
    func_800BA22C(sp24, arg2);
}

void func_80800400_chballoonbomb(s32 param_0)
{
    func_800BBCB8(param_0 + 4, 0, *(s32 *) ((param_0 + 0x38) ^ 0), 1, &D_8080057C_chballoonbomb);
}

s32 func_80800440_chballoonbomb(param_0)
s32 param_0;
{
    func_80800394_chballoonbomb(param_0, 0x93F, 2);
    func_80800394_chballoonbomb(param_0, 0x940, 3);
    func_80800394_chballoonbomb(param_0, 0x941, 4);
    func_80800400_chballoonbomb(param_0);
    func_80800354_chballoonbomb(param_0);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808004B0_chballoonbomb[18] = {0x18F013D,
                                    0x93E0001,
                                    0x0,
                                    (u32) func_80800118_chballoonbomb,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x752F,
                                    0x3F4CCCCD,
                                    0x0,
                                    0x406,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x40000,
                                    (u32) func_8080000C_chballoonbomb,
                                    (u32) func_80107C2C,
                                    0x0,
                                    (u32) func_808001F8_chballoonbomb,
                                    0x0};
u8 D_808004F8_chballoonbomb[20] = {0x0, 0x13, 0x4,  0x13, 0x0,  0xA,  0x0, 0xE6, 0x0, 0x18,
                                   0x0, 0x1,  0x1F, 0x40, 0x4E, 0x20, 0x0, 0x0,  0x0, 0x0};
s32 D_8080050C_chballoonbomb[13] = {0x113001D, 0x9E20016, 0x10000015, 0xB3,    0x2B0133,
                                    0x1990022, 0x4C0059,  0x260033,   0xE000A, 0x14002D,
                                    0x4B005DC, 0x1BFF9C,  -0xC80000};
s32 D_80800540_chballoonbomb[15] = {0x1130016, 0x10000015, 0xCC,     0x2B0133,  0x1990022,
                                    0x1000100, 0x660099,   0xE000A,  0x14002D,  0x4B005DC,
                                    0x1BFF9C,  -0xC7FFD9,  0xC800C8, 0x1900190, 0x0};
s32 D_8080057C_chballoonbomb[9] = {0x1D09DD, 0x2B0200, 0x2800022, 0x3000380, 0x8000A00,
                                   0x150000, 0x260019, 0x7,       0x0};
