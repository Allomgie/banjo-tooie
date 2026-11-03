#include "common.h"

extern int D_808006D8_chsquits[];
typedef struct {
    u8 pad[0x2C];
    f32 f2C;
    u8 pad30[0x3E];
    u16 hi : 7;
    u16 f6E : 9;
} SquitsState;
extern f32 func_800DC178(f32, f32);
extern s32 func_800D90A4(f32 *);
extern s16 D_808006C4_chsquits[];
extern int func_800DC128(int a, int b);
extern s32 func_800DC298(f32);
extern u8 D_80800720_chsquits[];
typedef struct {
    s16 local_0;
    s16 local_1;
    f32 local_2;
    f32 local_3;
} SquitsCue37;
typedef struct {
    SquitsCue37 *local_0;
    s32 local_1;
    f32 local_2;
} SquitsSequence37;
extern SquitsSequence37 D_80800694_chsquits[];
extern s32 func_800D91EC(f32 *, f32);
extern void func_800C4B64(f32);
s32 func_808001A4_chsquits();
void func_80800358_chsquits();
void func_80800564_chsquits();
void func_808003C4_chsquits();

int *chsquits_entrypoint_0()
{
    return &D_808006D8_chsquits;
}

void func_8080000C_chsquits(SquitsState *param_0)
{
    param_0->f6E = 1;
    param_0->f2C = func_800DC178(5.0f, 8.0f);
}

void func_80800054_chsquits(Actor *param_0)
{
    s32 local_0;

    if (param_0->unk70_10 == 1) {
        if (func_800D90A4(&param_0->unk58) && func_8010CAC0(param_0->position, 0x190)) {
            if (_subaddiedialog_entrypoint_11(param_0->unk0, func_808001A4_chsquits(param_0), 0,
                                              param_0->position, 0x8F)) {
                func_80101FDC(param_0, 2);
            }
            param_0->unk58 = func_800DC178(5.0f, 8.0f);
        }
    }
    func_80800358_chsquits(param_0);
}

s32 func_80800108_chsquits(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80101FDC(param_0, 1);
            break;
        case 0x95:
            if (!func_800DC298(0.2f)) {
                func_800BF744(1, 0);
                func_800FFAB0(param_0);
                break;
            }
            func_800BF744(1, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808001A4_chsquits(param_0)
Actor *param_0;
{
    u32 local_0;
    u32 local_1;
    s32 local_2;
    s32 local_3;
    local_0 = 0;
    for (local_1 = 0; local_1 < 10; local_1++) {
        if (!(param_0->actorData[6] & (1 << local_1))) {
            local_0++;
        }
    }
    if (local_0 == 0) {
        param_0->actorData[6] = 0;
        local_0 = 10;
    }
    local_2 = func_800DC128(0, local_0);
    local_3 = 0;
    for (local_1 = 0; local_1 < 10; local_1++) {
        if (!(param_0->actorData[6] & (1 << local_1))) {
            if (local_3 == local_2) {
                param_0->actorData[6] |= 1 << local_1;
                return D_808006C4_chsquits[local_1];
            }
            local_3++;
        }
    }
    return D_808006C4_chsquits[0];
}

void func_80800358_chsquits(param_0) Actor *param_0;
{
    switch (param_0->unk6C_0) {
        case 1:
            if (func_800D90A4((f32 *) &param_0->actorData[5])) {
                param_0->unk6C_0 = 0;
                func_80800564_chsquits(param_0);
            }
            break;
        case 0:
            func_808003C4_chsquits(param_0);
    }
}

s32 func_80800528_chsquits(f32 param_0, f32 param_1, f32 param_2);

void func_808003C4_chsquits(param_0) Actor *param_0;
{
    SquitsSequence37 *local_0 = &D_80800694_chsquits[param_0->actorData[4]];
    f32 local_1 = *(f32 *) &param_0->actorData[5];
    s32 local_2 = func_800D91EC((f32 *) &param_0->actorData[5], local_0->local_2);
    s32 local_3;
    s32 local_4;
    SquitsCue37 *local_5;

    for (local_3 = 0, local_4 = 0; local_3 < local_0->local_1;
         local_3++, local_4 += sizeof(SquitsCue37)) {
        local_5 = (SquitsCue37 *) ((u8 *) local_0->local_0 + local_4);
        if (func_80800528_chsquits(*(f32 *) &param_0->actorData[5], local_1, local_5->local_3)) {
            func_800C4B7C(local_5->local_0);
            func_800C4B70(local_5->local_1);
            func_800C4B64(func_800DC178(-0.05f, 0.05f) + local_5->local_2);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800720_chsquits);
        }
    }
    if (local_2) {
        param_0->unk6C_0 = 1;
        *(f32 *) &param_0->actorData[5] = func_800DC178(5.0f, 8.0f);
    }
}

s32 func_80800528_chsquits(f32 param_0, f32 param_1, f32 param_2)
{
    if ((param_2 < param_0) && (param_1 <= param_2)) {
        return TRUE;
    }
    return FALSE;
}

void func_80800564_chsquits(param_0) Actor *param_0;
{
    *(s32 *) ((char *) param_0 + 0x28) = func_800DC128(0, 4);
    *(f32 *) ((char *) param_0 + 0x2C) = 0.0f;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_808005B0_chsquits[12] = {0x42B55F0,  0x3F4CCCCD, 0x3E99999A, 0x42B55F0,
                               0x3F19999A, 0x3F4CCCCD, 0x55755F0,  0x3F99999A,
                               0x40400000, 0x4E455F0,  0x3FA66666, 0x40866666};
u32 D_808005E0_chsquits[6] = {0x42B55F0, 0x3F266666, 0x3E99999A, 0x4E455F0, 0x3FA66666, 0x3F800000};
u32 D_808005F8_chsquits[9] = {0x55955F0,  0x3FB33333, 0x0,        0x42B55F0, 0x3F333333,
                              0x3F19999A, 0x42B55F0,  0x3ECCCCCD, 0x40733333};
u32 D_8080061C_chsquits[30] = {
    0x42B55F0,  0x3FCCCCCD, 0x3E4CCCCD, 0x42B55F0,  0x3FB33333, 0x3ECCCCCD, 0x42B55F0,  0x3F99999A,
    0x3F19999A, 0x42B55F0,  0x3FCCCCCD, 0x3F4CCCCD, 0x42B55F0,  0x3FD9999A, 0x3F800000, 0x42B55F0,
    0x3FE66666, 0x3F99999A, 0x42B55F0,  0x3F99999A, 0x3FB33333, 0x42B7D00,  0x3EB33333, 0x3FCCCCCD,
    0x40955F0,  0x3F59999A, 0x4019999A, 0x4E455F0,  0x3FA66666, 0x404CCCCD};
SquitsSequence37 D_80800694_chsquits[4] = {
    (void *) &D_808005B0_chsquits, 0x4, 8.0f, (void *) &D_808005E0_chsquits, 0x2, 6.0f,
    (void *) &D_808005F8_chsquits, 0x3, 6.0f, (void *) &D_8080061C_chsquits, 0xA, 8.0f};
s16 D_808006C4_chsquits[2] = {0x136A, 0x136B};
u32 D_808006C8_chsquits[4] = {0x136C136D, 0x136E136F, 0x13771378, 0x1379137A};
int D_808006D8_chsquits[18] = {0x15804E9,
                               0x1,
                               0x0,
                               (u32) func_80800054_chsquits,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_8080000C_chsquits,
                               (u32) func_80107C2C,
                               -0x7FFFF9FE,
                               (u32) func_80800108_chsquits,
                               0x0};
u8 D_80800720_chsquits[16] = {0x0, 0x21, 0x0, 0x1E, 0x0, 0x1D, 0x0, 0x1,
                              0x1, 0xF4, 0x5, 0xDC, 0x0, 0x0,  0x0, 0x0};
