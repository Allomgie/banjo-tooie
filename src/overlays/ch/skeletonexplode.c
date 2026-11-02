#include "common.h"
#include "core2/1EC8070.h"

typedef struct { u8 pad_0[0x74]; u32 pad_1:28, flags:4; u32 pad_2:18, phase:2, step:3, pad_3:9; } SkeletonFlags1436;
extern s32 func_80103140();
typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; f32 local_4[3]; u8 local_5; u8 pad_0[3]; } CodexSkeletonPiece65;
extern f32 func_800F1DF4(f32[3], f32[3]);
extern f32 func_800DC178(f32, f32);
extern f32 _dbskeleton_entrypoint_1(s32);
typedef struct Mass47SkeletonPiece { Vec3f local_0; Vec3f local_1; Vec3f local_2; Vec3f local_3; f32 local_4[3]; u8 local_5; u8 local_6[3]; } Mass47SkeletonPiece;
extern void *func_800B27E0(void *);
extern void *func_801039E4(Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801084B0(s32, Actor **);
extern void _chskeletonexplode_entrypoint_0();
extern void _chbaddiesetup_entrypoint_6(void (*)(), Unk80132ED0 *, s32, s32, s32, s32, s32);
extern void func_800EE904(s32[3], f32[3]);
extern void func_800ADD80();
extern void func_800ADEC4();
extern void func_800DF6BC();
extern void func_800DF758();
extern void mlMtxTranslate(f32, f32, f32);
extern void mlMtxRotatePYR(f32, f32, f32);
typedef struct { s16 a, b; } S16Pair;
extern int D_80801138_chskeletonexplode;
extern u8 D_80801090_chskeletonexplode[];
extern u8 D_808010C0_chskeletonexplode[];
extern u8 D_80801120_chskeletonexplode[];
extern u8 D_808010F0_chskeletonexplode[];
extern u8 D_808010D8_chskeletonexplode[];
extern u8 D_808010A8_chskeletonexplode[];
extern u8 D_80801108_chskeletonexplode[];
extern f32 func_800D8FF8(void);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, u32);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80800000_chskeletonexplode(), func_80800034_chskeletonexplode();

void func_80800000_chskeletonexplode(param_0) Actor *param_0;
{
    f32 *local_0;

    local_0 = func_80100094(param_0, 1);
    param_0->unk58 = 0.0f;
    *local_0 = 0.0f;
}

void func_80800034_chskeletonexplode(param_0) u8 **param_0;
{
  s16 new_var;
  s16 local_0;
  local_0 = *((s16 *) (((s8 *) (*param_0)) + 0x10));
  if ((*((s16 *) (((s8 *) (*param_0)) + 0x10))) != 0)
  {
    new_var = *((s16 *) (((s8 *) (*param_0)) + 0x10));
    func_800ADFE0(new_var, *((s16 *) (((s8 *) (*param_0)) + 0x10)), param_0);
    *((s16 *) (((s8 *) (*param_0)) + 0x10)) = 0;
  }
}

void func_8080007C_chskeletonexplode(Actor *param_0, f32 *param_1)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 1);
    if (*(f32 *)local_0 > 0.0f) {
        *(f32 *)local_0 -= func_800D8FF8();
    } else {
        switch (local_0[0xF4]) {
            case 0: break;
            case 1: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_80801090_chskeletonexplode); break;
            case 2: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_808010A8_chskeletonexplode); break;
            case 3: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_808010C0_chskeletonexplode); break;
            case 4: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_808010D8_chskeletonexplode); break;
            case 5: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_808010F0_chskeletonexplode); break;
            case 6: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_80801108_chskeletonexplode); break;
            case 7: _subaddieaudioquick_entrypoint_2(param_0, param_1, D_80801120_chskeletonexplode); break;
        }
        *(f32 *)local_0 = 0.25f;
    }
}

void func_808001BC_chskeletonexplode(Actor *param_0)
{
    CodexSkeletonPiece65 *local_11;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_7;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_8;
    s32 local_5;
    f32 local_6;
    f32 local_9;
    u32 local_10;

    local_11 = func_80100094(param_0, 0);
    local_5 = 1;
    local_6 = func_800D8FF8();
    if (param_0->unk58 < 5.0f) {
        param_0->unk58 += local_6;
    } else {
        _subaddiefade_entrypoint_3(param_0);
    }
    for (local_10 = 0; local_10 < param_0->unk6C_0; local_10++) {
        if (local_11->local_5 != 1) {
            local_11++;
            continue;
        }
            func_800EFA20(local_1, local_11->local_3, local_6);
            func_800EE780(local_0, local_11->local_1, local_11->local_0);
            func_800EF04C(local_0, param_0->position);
            local_5 = 0;
            func_800EE7F8(local_3, local_0);
            func_800EE7F8(local_4, local_3);
            func_800EF04C(local_4, local_1);
            func_800EF04C(local_4, local_1);
            if (param_0->position[1] - local_4[1] > 2000.0f) {
                local_11->local_5 = 2;
            } else if (func_800BEF00(local_3, local_4, local_2, 0x20020)) {
                local_7 = func_800EEF94(local_11->local_3);
                local_8 = func_800EEF94(local_1) * 2;
                local_9 = func_800EEAD4(local_3, local_4);
                if (local_9 < local_8) {
                    func_800EF334(local_1, local_9 / local_8 * 0.9f);
                }
                func_800EFDE8(local_11->local_3, local_11->local_3, local_2);
                func_800EF368(local_11->local_3, local_7 * 0.35f);
                func_800EF334(local_11->local_4, 0.35f);
                if (local_7 < 250.0f) {
                    local_11->local_5 = 2;
                }
                func_8080007C_chskeletonexplode(param_0, local_4);
            } else {
                local_11->local_3[0] *= 0.95f;
                local_11->local_3[2] *= 0.95f;
                local_11->local_3[1] += ((f32 *)param_0->actorData)[7] * func_800D8FF8();
                func_800EF04C(local_11->local_2, local_11->local_4);
                func_800EF334(local_11->local_4, 0.99f);
            }
            func_800EF04C(local_11->local_0, local_1);
        local_11++;
    }
    if (local_5) {
        _subaddiefade_entrypoint_3(param_0);
    }
}

void func_808004DC_chskeletonexplode(Actor *param_0, Actor *param_1, s32 param_2, s32 param_3)
{
    param_0->rotation[0] = param_1->rotation[0];
    param_0->rotation[2] = param_1->rotation[2];
    param_0->rotation[1] = param_1->rotation[1];
    param_0->scale = param_1->scale;
    func_80103140(param_0, (u16)param_2, (u16)param_3);
    ((SkeletonFlags1436 *)param_0)->flags = ((SkeletonFlags1436 *)param_1)->flags;
    ((SkeletonFlags1436 *)param_0)->step = ((SkeletonFlags1436 *)param_1)->step;
    ((SkeletonFlags1436 *)param_0)->phase = ((SkeletonFlags1436 *)param_1)->phase;
}

void func_80800594_chskeletonexplode(u8 *arg0) {
    *(f32 *)(arg0 + 0x30) = 15.0f;
    *(f32 *)(arg0 + 0x18) = 15.0f;
    *(f32 *)(arg0 + 0x28) = 800.0f;
    *(f32 *)(arg0 + 0x2C) = 1000.0f;
    *(f32 *)(arg0 + 0x34) = -2000.0f;
}

void func_808005CC_chskeletonexplode(Actor *param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_3;
    s32 local_2;
    CodexSkeletonPiece65 *local_4;
    u32 local_5;
    s32 local_6;
    f32 local_8;
    f32 local_9;
    f32 local_7[3];
    f32 local_10[4];

    local_0 = func_800B27E0(func_801039E4(param_0->unk0));
    local_1 = func_80104248(param_1);
    func_8008C200(((s16 *)param_0->unk0)[8], local_0, func_8008AEDC(local_1));
    local_2 = func_8008C27C(func_8008AEDC(local_1));
    param_0->unk6C_0 = func_800AE124(((s16 *)param_0->unk0)[8]);
    local_3 = func_800AE080(((s16 *)param_0->unk0)[8]);
    func_80100074(param_0, 0, param_0->unk6C_0 << 6);
    local_4 = func_80100094(param_0, 0);
    for (local_5 = 0; local_5 < param_0->unk6C_0; local_5++, local_4++) {
        local_6 = _dbskeleton_entrypoint_4(local_0, local_5);
        func_800F2C1C(func_800ADE50(local_3, local_0, local_6), local_4->local_2);
        func_800AE630(local_3, local_0, local_6, local_4->local_0);
        func_800EE780(local_7, param_0->position, local_4->local_0);
        local_8 = func_800F1DF4(local_7, param_2) - param_0->rotation[1];
        _dbskeleton_entrypoint_2(local_0, local_6, local_4->local_1);
        func_800EF3DC(local_4->local_0, local_4->local_1);
        local_9 = func_800DC178(-20.0f, 20.0f);
        func_800EEC30(local_4->local_3, local_9 + 130.0f, func_800DC178(-65.0f, 65.0f) + local_8, 1000.0f);
        local_4->local_5 = 1;
    }
    for (local_5 = 0; local_5 < param_0->unk6C_0; local_5++) {
        local_4 = (CodexSkeletonPiece65 *)func_80100094(param_0, 0) + local_5;
        if (local_4->local_5 == 4) {
            func_800DFC20(local_2, _dbskeleton_entrypoint_4(local_0, local_5), local_4->local_0);
            func_800EF334(local_4->local_0, _dbskeleton_entrypoint_1(local_0));
        }
    }
}

void func_80800894_chskeletonexplode(Actor *param_0, u32 param_1, void *param_2)
{
    f32 local_1;
    f32 local_2;
    void *local_3;
    Mass47SkeletonPiece *local_4;
    u32 local_5;
    f32 *local_6;
    f32 local_0[3];

    local_3 = func_800B27E0(func_801039E4(param_0->unk0));
    param_0->unk6C_0 = _dbskeleton_entrypoint_0(local_3);
    func_80100074(param_0, 0, param_0->unk6C_0 << 6);
    local_4 = func_80100094(param_0, 0);
    local_5 = 0;
    local_6 = param_0->position;
    if (param_0->unk6C_0 != 0) {
        do {
            _dbskeleton_entrypoint_2(local_3, _dbskeleton_entrypoint_4(local_3, local_5), &local_4->local_1);
            func_800EFD24(&local_4->local_0);
            func_800EE780(local_0, &local_4->local_1, local_6);
            local_1 = func_800F1DF4(local_0, param_2);
            local_4->local_2.f[0] = 0.0f;
            local_4->local_2.f[1] = param_0->rotation[1];
            local_4->local_2.f[2] = 0.0f;
            local_2 = func_800DC178(-20.0f, 20.0f);
            func_800EEC30(local_4->local_3.f, local_2 + 130.0f,
                func_800DC178(-65.0f, 65.0f) + local_1, 1000.0f);
            local_4->local_5 = 1;
            local_5++;
            local_4++;
        } while (local_5 < param_0->unk6C_0);
    }
    param_0->rotation[1] = 0.0f;
    param_0->rotation[0] = 0.0f;
    param_0->rotation[2] = 0.0f;
}

void chskeletonexplode_entrypoint_0(Unk80132ED0 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    Actor *local_2;
    Actor *local_0;
    u8 *local_3;
    u8 *local_3_b;
    u32 local_4;
    f32 local_1[3];
    Unk80132ED0 *local_p;

    local_p = param_0;
    if (&param_0) {}
    local_1[0] = param_1;
    local_1[1] = param_2;
    local_1[2] = param_3;
    local_0 = func_80106790(local_p);
    local_2 = func_801084B0(0x304, &local_0);
    local_0 = func_80106790(local_p);
    local_3 = func_80100094(local_2, 1);
    func_808004DC_chskeletonexplode(local_2, local_0, param_4, param_5);
    if (!*((s16 *)((u8 *)local_2->unk0 + 0x10))) {
        *((s16 *)((u8 *)local_2->unk0 + 0x10)) = func_800AE020();
    }
    local_0->unk64_16 = 0;
    func_80800594_chskeletonexplode(local_2);
    if (func_80104248(local_0)) func_808005CC_chskeletonexplode(local_2, local_0, local_1);
    else func_80800894_chskeletonexplode(local_2, local_0, local_1);
    *((s32 *)(local_3 + 4)) = 0;
    local_3[0xF4] = 0;
    local_3[0xF5] = 0;
    if (*(u16 *)((u8 *)local_p + 0x18) & 1) {
        func_80101074(local_2->unk0);
        func_8010114C(local_p, 0xF, 0);
    }
    local_3_b = func_80100094(local_2, 0);
    for (local_4 = 0; local_4 < local_2->unk6C_0; local_4++, local_3_b += 0x40) {
        func_800EF334((f32 *)(local_3_b + 0x24),
            func_800DC178(*((f32 *)&local_2->actorData[4]), *((f32 *)&local_2->actorData[5])) / 1000.0f);
        *((f32 *)(local_3_b + 0x30)) = func_800DC178(*((f32 *)&local_2->actorData[6]), *((f32 *)&local_2->actorData[0]));
        *((f32 *)(local_3_b + 0x34)) = func_800DC178(*((f32 *)&local_2->actorData[6]), *((f32 *)&local_2->actorData[0]));
        *((f32 *)(local_3_b + 0x38)) = func_800DC178(*((f32 *)&local_2->actorData[6]), *((f32 *)&local_2->actorData[0]));
    }
}

void chskeletonexplode_entrypoint_1(Actor *param_0, f32 param_1, f32 param_2)
{
  f32 *new_var;
  new_var = (char *) param_0;
  *((f32 *) (new_var + 10)) = param_1;
  new_var = (f32 *) (((char *) param_0) + 44);
  if (!param_1)
  {
  }
  *new_var = param_2;
}

void chskeletonexplode_entrypoint_2(Actor *param_0, f32 param_1, f32 param_2)
{
  *(f32 *)((char *)param_0 + 0x30) = param_1;
  *(f32 *)((char *)param_0 + 0x18) = param_2;
}

void chskeletonexplode_entrypoint_3(s32 param_0, s32 param_1, s32 param_2) {
    s32 *local_0 = func_80100094(param_0, 1);
    local_0[param_1 + 1] = param_2;
    if (local_0[1] < param_1) {
        local_0[1] = param_1;
    }
}

void chskeletonexplode_entrypoint_4(s32 param_0, s32 param_1)
{
    void *local_0;
    local_0 = func_80100094(param_0, 1);
    *(u8 *)((char *)local_0 + 0xF4) = param_1;
}

void chskeletonexplode_entrypoint_5(s32 param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80100094(param_0, 1);
  *(((char *) local_0) + 0xF5) = param_1;
}

void chskeletonexplode_entrypoint_6(Actor *param_0, f32 param_1[3], s32 param_2, s32 param_3)
{
    s32 local_0[3];

    func_800EE904(local_0, param_1);
    _chbaddiesetup_entrypoint_6(_chskeletonexplode_entrypoint_0, param_0->unk0, local_0[0], local_0[1], local_0[2], param_2, param_3);
}

void chskeletonexplode_entrypoint_7(Actor *param_0, s32 param_1)
{
    s32 local_2[3];
    s32 local_0[2];

    local_0[1] = *(u16 *)((u8 *)param_0->unk0 + 0x14);
    local_0[0] = *(u16 *)((u8 *)param_0->unk0 + 0x16);
    func_800EE904(local_2, param_1);
    _chbaddiesetup_entrypoint_6(_chskeletonexplode_entrypoint_0, param_0->unk0, local_2[0], local_2[1], local_2[2], local_0[1], local_0[0]);
}

void chskeletonexplode_entrypoint_8(u8 **param_0, s16 *param_1)
{
    s32 position[3];
    s32 sp2C[2];

    sp2C[1] = *(u16 *)(*param_0 + 0x14);
    sp2C[0] = *(u16 *)(*param_0 + 0x16);
    position[0] = param_1[0];
    position[1] = param_1[1];
    position[2] = param_1[2];
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, *param_0, position[0], position[1], position[2], sp2C[1], sp2C[0]);
}

void func_80800E88_chskeletonexplode(Actor *param_0)
{
    u8 *local_0;
    s32 local_2;
    s32 local_3;
    f32 local_1[4][4];
    s32 local_4;
    u32 local_5;
    u8 *local_6;
    local_0 = func_80100094(param_0, 1);
    local_2 = func_800B27E0(func_801039E4(param_0->unk0));
    local_6 = func_80100094(param_0, 0);
    func_801015D0(param_0);
    func_800ADD80(*(s16 *)((u8 *)param_0->unk0 + 0x10), local_2);
    local_3 = func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10));
    for (local_5 = 0; local_5 < param_0->unk6C_0; local_5++, local_6 += 0x40) {
        local_4 = _dbskeleton_entrypoint_4(local_2, local_5);
        func_80019CD4();
        mlMtxTranslate(*(f32 *)(local_6 + 12), *(f32 *)(local_6 + 16), *(f32 *)(local_6 + 20));
        mlMtxTranslate(*(f32 *)local_6, *(f32 *)(local_6 + 4), *(f32 *)(local_6 + 8));
        mlMtxRotatePYR(*(f32 *)(local_6 + 24), *(f32 *)(local_6 + 28), *(f32 *)(local_6 + 32));
        mlMtxTranslate(-*(f32 *)(local_6 + 12), -*(f32 *)(local_6 + 16), -*(f32 *)(local_6 + 20));
        mlMtxGet(local_1);
        func_800ADEC4(local_3, local_2, local_4, local_1);
    }
    func_800DF72C(local_3);
    func_800DF758(local_0 + 4);
    if (!local_0[0xF5]) return;
    func_800DF6BC(local_0[0xF5], *((u8 *)param_0 + 0x9B));
}

s32 func_8080100C_chskeletonexplode(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    if (param_1 == 0x1F) {
        func_80800E88_chskeletonexplode(param_0);
    } else {
        return 0;
    }
    return 1;
}

int *chskeletonexplode_entrypoint_9()
{
    return &D_80801138_chskeletonexplode;
}
