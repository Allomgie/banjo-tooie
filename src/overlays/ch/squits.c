#include "common.h"

extern int D_808006D8_chsquits;
typedef struct { u8 pad[0x2C]; f32 f2C; u8 pad30[0x3E]; u16 hi:7; u16 f6E:9; } SquitsState;
extern f32 func_800DC178(f32, f32);
extern s32 func_800D90A4(f32 *);
extern s16 D_808006C4_chsquits[];
extern int func_800DC128(int a, int b);
extern s32 func_800DC298(f32);
extern u8 D_80800720_chsquits[];
typedef struct { s16 local_0; s16 local_1; f32 local_2; f32 local_3; } SquitsCue37;
typedef struct { SquitsCue37 *local_0; s32 local_1; f32 local_2; } SquitsSequence37;
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

void func_8080000C_chsquits(SquitsState *param_0) {
    param_0->f6E = 1;
    param_0->f2C = func_800DC178(5.0f, 8.0f);
}

void func_80800054_chsquits(Actor *param_0)
{
    s32 local_0;

    if (param_0->unk70_10 == 1) {
        if (func_800D90A4(&param_0->unk58) && func_8010CAC0(param_0->position, 0x190)) {
            if (_subaddiedialog_entrypoint_11(param_0->unk0, func_808001A4_chsquits(param_0), 0, param_0->position, 0x8F)) {
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
    default: return 0;
    }
    return 1;
}

s32 func_808001A4_chsquits(param_0) Actor *param_0;
{
    u32 local_0;
    u32 local_1;
    s32 local_2;
    s32 local_3;
    local_0 = 0;
    for (local_1 = 0; local_1 < 10; local_1++) {
        if (!(param_0->actorData[6] & (1 << local_1))) { local_0++; }
    }
    if (local_0 == 0) { param_0->actorData[6] = 0; local_0 = 10; }
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
        if (func_800D90A4((f32 *)&param_0->actorData[5])) {
            param_0->unk6C_0 = 0;
            func_80800564_chsquits(param_0);
        }
        break;
    case 0:
        func_808003C4_chsquits(param_0);
        break;
    }
}





































s32 func_80800528_chsquits(f32 param_0, f32 param_1, f32 param_2);

void func_808003C4_chsquits(param_0) Actor *param_0;
{
    SquitsSequence37 *local_0 = &D_80800694_chsquits[param_0->actorData[4]];
    f32 local_1 = *(f32 *)&param_0->actorData[5];
    s32 local_2 = func_800D91EC((f32 *)&param_0->actorData[5], local_0->local_2);
    s32 local_3;
    s32 local_4;
    SquitsCue37 *local_5;

    for (local_3 = 0, local_4 = 0; local_3 < local_0->local_1; local_3++, local_4 += sizeof(SquitsCue37)) {
        local_5 = (SquitsCue37 *)((u8 *)local_0->local_0 + local_4);
        if (func_80800528_chsquits(*(f32 *)&param_0->actorData[5], local_1, local_5->local_3)) {
            func_800C4B7C(local_5->local_0);
            func_800C4B70(local_5->local_1);
            func_800C4B64(func_800DC178(-0.05f, 0.05f) + local_5->local_2);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800720_chsquits);
        }
    }
    if (local_2) {
        param_0->unk6C_0 = 1;
        *(f32 *)&param_0->actorData[5] = func_800DC178(5.0f, 8.0f);
    }
}

s32 func_80800528_chsquits(f32 param_0, f32 param_1, f32 param_2){
    if((param_2 < param_0) && (param_1 <= param_2)){
        return TRUE;
    }
    return FALSE;
}

void func_80800564_chsquits(param_0) Actor *param_0;
{
    *(s32 *)((char *)param_0 + 0x28) = func_800DC128(0, 4);
    *(f32 *)((char *)param_0 + 0x2C) = 0.0f;
}
