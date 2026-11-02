#include "common.h"
#include "core1/mlmtx.h"

extern void *D_80801AE0_chexploder;
typedef struct { u8 pad_0[0x14]; u16 local_0; u16 local_1; } ExploderAnimation1246;
typedef union { s32 local_0; s16 local_1[2]; } ExploderMessage1483;
extern void *func_80100094(Actor *, s32);
extern Unk80132ED0 *func_80101080(void);
extern void func_801018A4(Actor *, Unk80132ED0 *);
extern void func_80103140();
extern void mlMtxTranslate(f32, f32, f32);
extern void mlMtxRotatePYR(f32, f32, f32);
typedef struct { s16 local_0[8]; s16 local_1; u8 local_2; u8 local_3; u8 pad_0[4]; u8 local_4; u8 pad_1[0x3F]; f32 local_5; } ExploderInit;
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
typedef struct { s16 a, b; } S16Pair;
typedef struct { u8 pad[0x70]; u8 pad70:7; u8 f70:1; u8 pad71:2; u8 f71:1; u8 rest71:5; } ExplS;
extern s32 func_800B26F0(s32);
typedef struct { s16 id; s16 x; s16 y; s16 z; f32 yaw; f32 scale; s32 flags; } ExploderSpawn;
typedef struct { u8 pad0[0x14]; u16 unk14; u16 unk16; u8 pad18[0x3C]; u16 unk54; } ExploderLocal;
typedef struct { u32 pad74_26 : 6; u32 unk74_25 : 1; u32 pad74_0 : 25; } ActorFlags74b;
extern Actor *func_80108474(s32, f32 *, s32);
extern Actor *func_80106790();
extern void func_800EE7F8();
extern void func_80101074();
extern s32 func_8010108C(Actor *, s32, s32);
extern void func_80101038(f32 *);
extern void func_80108944(Actor *, Actor *);
extern s32 func_801039E4(Unk80132ED0 *);
extern s32 func_80104248(Actor *);
extern s32 _chexploder_entrypoint_1[];
extern void func_800EE88C(f32 *, s32);
extern s32 _chexploder_entrypoint_2;
extern void func_8010A570();
extern void _chbaddiesetup_entrypoint_6(void *, s32, s32, s32, s32, s32, s32);
typedef struct { u8 pad_0[0xE]; s16 local_0; } ExploderPartCount1332;
typedef struct { u8 pad_0[0x36]; u8 pad_1 : 1; u8 local_0 : 1; u8 pad_2 : 6; u8 pad_3[2]; u8 local_1; u8 pad_4[2]; } ExploderSelectablePart1332;
typedef struct { u8 pad[0xE]; s16 count; } ExploderCount;
typedef struct { u8 pad[0x36]; u8 pad_0 : 1; u8 active : 1; u8 pad_1 : 6; u8 pad_37[2]; u8 id; u8 pad_3A[2]; } ExploderPiece;
typedef struct { f32 pos[3]; f32 unkC[3]; f32 vel[3]; f32 unk24; f32 unk28; f32 unk2C; s16 unk30; s16 unk32; s16 unk34; u16 unk36_15:1; u16 unk36_14:1; u16 unk36_13:1; u16 pad36:13; u8 unk38; u8 pad39[3]; } ExplPart;
typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; s16 unk10; u8 pad12[0x5C - 0x12]; f32 unk5C; } ExplHead;
extern f32 func_800D8FF8(void);
extern s32 func_8001210C(s32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800BF340(f32 *, f32 *, f32 *, u32, f32);
extern f32 func_800EEF94(f32 *);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
typedef struct { s16 a; s16 b; s16 c; s16 d; s16 e; } ExpE;
extern ExpE D_80801B28_chexploder[];
extern s32 D_80801BA0_chexploder;
extern void func_800C4B7C(s32);
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern f32 func_800EEFD4();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_80801BB0_chexploder[];
extern u8 D_80801BD8_chexploder[];
extern u8 D_80801BE4_chexploder[];
extern u8 D_80801BF0_chexploder[];
extern u8 D_80801C00_chexploder[];
typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; u8 pad_0[6]; u8 b7 : 1; u8 b6 : 1; u8 bl : 6; u8 pad_1[2]; u8 local_5; u8 pad_2[2]; } CodexExploderPiece65;
extern int func_800EF5A0(f32[3], f32[3], f32, f32, f32);
extern int func_800EF334(f32[3], f32);
extern int func_800EEBF0(f32[3], f32[2], f32);
typedef struct { u8 pad_0[0x36]; u8 f1 : 1; u8 f2 : 1; u8 rest : 6; } Exp36;
extern void *func_80100074(Actor *, u32, s32);
void func_80800154_chexploder();
void chexploder_entrypoint_9();
s32 func_808002FC_chexploder();
void func_8080067C_chexploder();
void func_80800834_chexploder();
void func_80800AC8_chexploder();
void func_80800D7C_chexploder();

int chexploder_entrypoint_0()
{
  return &D_80801AE0_chexploder;
}

void func_8080000C_chexploder(s32 arg0) 
{
}
void func_80800014_chexploder(Actor *param_0)
{
    if (param_0->unk70_10 == 1 && !func_808002FC_chexploder(param_0)) {
        func_80101FDC(param_0, 2);
        _subaddiefade_entrypoint_3(param_0);
        func_8010A800(param_0, 2);
    }
}

void func_80800078_chexploder(u8 **param_0)
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

s32 func_808000C0_chexploder(Actor *param_0, s32 param_1, ExploderMessage1483 param_2)
{
    ExploderAnimation1246 *local_0;

    switch (param_1) {
    case 0xAB:
        func_801018A4(param_0, func_80101080());
        break;
    case 0x1F:
        func_80800154_chexploder(param_0, param_2.local_0);
        break;
    case 0x95:
        local_0 = func_80100094(param_0, 0);
        func_80103140(param_0, local_0->local_0, local_0->local_1);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800154_chexploder(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_1;
    MtxF local_0;
    s32 local_2;
    s32 local_7;
    s32 local_3;
    s32 local_4;
    u8 *local_5;
    u8 *local_6;
    local_2 = func_800B27E0(param_1);
    local_5 = func_80100094(param_0, 1);
    local_6 = func_80100094(param_0, 0);
    func_801015D0(param_0);
    func_800ADD80(*(s16 *)((u8 *)param_0->unk0 + 0x10), local_2);
    local_3 = func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10));
    local_1 = 1.0f / param_0->scale;
    for (local_4 = 0; local_4 < *(s16 *)(local_6 + 0xE); local_4++, local_5 += 0x3C) {
        func_80019CD4();
        mlMtxTranslate(*(f32 *)(local_5 + 0xC), *(f32 *)(local_5 + 0x10), *(f32 *)(local_5 + 0x14));
        mlMtxTranslate(*(f32 *)local_5 * local_1, *(f32 *)(local_5 + 4) * local_1, *(f32 *)(local_5 + 8) * local_1);
        mlMtxRotatePYR(*(f32 *)(local_5 + 0x24), *(f32 *)(local_5 + 0x28), *(f32 *)(local_5 + 0x2C));
        mlMtxTranslate(-*(f32 *)(local_5 + 0xC), -*(f32 *)(local_5 + 0x10), -*(f32 *)(local_5 + 0x14));
        mlMtxGet(&local_0);
        func_800ADEC4(local_3, local_2, local_5[0x39], &local_0);
    }
    func_800DF72C(local_3);
    local_4 = 1;
    local_5 = local_6 + 1;
    for (; local_4 <= local_6[0x18]; local_4++, local_5++) {
        func_800DF744(local_4, local_5[0x18]);
    }
}

s32 func_808002FC_chexploder(param_0) Actor *param_0;
{
    ExplHead *local_0;
    ExplPart *local_1;
    f32 local_2;
    s32 local_3;
    f32 local_4[3];
    f32 local_5;
    s32 local_6;
    s32 local_7;
    f32 local_8[3];
    f32 local_9[3];
    f32 local_10[3];
    f32 local_11[3];
    f32 local_12[3];
    s32 local_13;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80100094(param_0, 1);
    local_3 = 0;
    local_2 = func_800D8FF8();
    local_7 = func_8001210C(1);
    local_0->unk5C += local_2;
    for (local_13 = 0; local_13 < local_0->unkE; local_13++, local_1++) {
        if (!local_1->unk36_14) {
            continue;
        }
        local_1->unk24 += local_1->unk30 * local_2;
        local_1->unk2C += local_1->unk32 * local_2;
        local_1->vel[1] += local_2 * local_1->unk34;
        func_800EFA20(local_9, local_1->vel, 2.0f * local_2);
        func_800EFA20(local_10, local_1->vel, local_2);
        func_800EFA20(local_8, local_1->unkC, param_0->scale);
        func_800EF04C(local_8, local_1->pos);
        func_800EF04C(local_8, param_0->position);
        func_800EE7F8(local_11, local_8);
        func_800EE7F8(local_12, local_8);
        func_800EF04C(local_12, local_9);
        if (func_800EEB40(local_12, param_0->position) > 12250000.0f) {
            local_1->unk36_14 = 0;
            continue;
        }
        if (!local_1->unk36_15) {
            if (local_7 == (local_13 & 1)) {
                local_6 = func_800BF340(local_11, local_12, local_4, param_0->unk14, local_0->unkC);
            } else {
                local_6 = 0;
            }
            if (local_6) {
                if (local_1->unk36_13) {
                    local_5 = func_800EEF94(local_1->vel);
                    func_800EFDE8(local_1->vel, local_1->vel, local_4);
                    func_800EF368(local_1->vel, local_5 * 0.35f);
                    local_1->unk30 = local_1->unk30 * 0.35f;
                    local_1->unk32 = local_1->unk32 * 0.35f;
                    local_1->unk38++;
                    if (local_0->unk10 < local_1->unk38 || 2.0f * (local_2 * local_5) < 10.0f) {
                        local_1->unk36_14 = 0;
                        continue;
                    }
                    func_8080067C_chexploder(param_0, local_1, local_12);
                }
            } else if (!local_1->unk36_13) {
                local_1->unk36_13 = 1;
            }
        }
        func_800EF04C(local_1->pos, local_10);
        func_80800834_chexploder(param_0, local_1, local_12);
        local_3++;
    }
    return local_3;
}

void func_8080067C_chexploder(param_0, param_1, param_2) u8 *param_0; u8 *param_1; s32 param_2;
{
    u8 *local_7;
    s32 local_6;
    s32 local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;

    local_7 = func_80100094(param_0, 0);
    if (!(*(f32 *)(local_7 + 0x5C) < 0.1f)) {
        if (local_7[0x12] != 0 && local_7[0x56] == 0) {
            local_6 = local_7[0x12] - 1;
            local_0 = D_80801B28_chexploder[local_6].a;
            local_1 = D_80801B28_chexploder[local_6].b;
            local_2 = func_800DC178(D_80801B28_chexploder[local_6].c * 0.00390625f, D_80801B28_chexploder[local_6].d * 0.00390625f);
            local_3 = D_80801B28_chexploder[local_6].e * 0.00390625f;
            func_800C4B7C(local_0);
            func_800C4B64(local_2 - ((f32)(u32)param_1[0x38] - 1.0f) * local_3);
            func_800C4B70(local_1 - param_1[0x38] * 4000 + 4000);
            func_8010D930(7, *(s32 *)(param_0 + 0x70) & 1, param_2, &D_80801BA0_chexploder);
            if (*(s16 *)(local_7 + 0x54) & 0x100) {
                local_7[0x56] = 1;
            }
        }
        *(f32 *)(local_7 + 0x5C) = 0.0f;
    }
}

void func_80800834_chexploder(param_0, param_1, param_2) Actor *param_0; u8 *param_1; f32 *param_2;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    if (param_1[0x38] < 3 && !(func_800EEFD4((f32 *)(param_1 + 0x18)) < 90000.0f)) {
        switch (local_0[0x13]) {
            case 1:
                local_1 = func_800B5BE4(0x18);
                func_800BABB8(local_1, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BB0_chexploder);
                func_800BABB8(local_1, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BD8_chexploder);
                break;
            case 2:
                local_2 = func_800B5BE4(0x18);
                func_800BABB8(local_2, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BB0_chexploder);
                func_800BABB8(local_2, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BE4_chexploder);
                break;
            case 3:
                local_3 = func_800B5BE4(0x18);
                func_800BABB8(local_3, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BB0_chexploder);
                func_800BABB8(local_3, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BF0_chexploder);
                break;
            case 4:
                local_4 = func_800B5BE4(0x18);
                func_800BABB8(local_4, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801BB0_chexploder);
                func_800BABB8(local_4, param_2, NULL, *(f32 *)(local_0 + 0x58), D_80801C00_chexploder);
                break;
        }
    }
}

void func_80800A18_chexploder(Actor *param_0)
{
    ExploderInit *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0->local_0[0] = 0x320;
    local_0->local_0[1] = 0x3E8;
    local_0->local_0[2] = 0xC8;
    local_0->local_0[3] = 0x12C;
    local_0->local_0[4] = -0x41A;
    local_0->local_0[5] = -0x3B6;
    local_0->local_0[6] = param_0->scale * 30.0f;
    local_0->local_1 = 4;
    local_0->local_4 = 0;
    local_0->local_2 = 0;
    local_0->local_3 = 0;
    local_0->local_5 = 1.0f;
    chexploder_entrypoint_9(param_0, 1, 0);
    chexploder_entrypoint_9(param_0, 2, 1);
}

void func_80800AC8_chexploder(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; f32 *param_2; s32 param_3;
{
    f32 *local_8;
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    CodexExploderPiece65 *local_4;
    s32 local_5;
    f32 local_6[2];
    f32 local_7[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800B27E0(func_801039E4(param_0->unk0));
    local_2 = func_80104248(param_1);
    func_8008C238(((s16 *)param_0->unk0)[8], local_1, func_8008AEDC(local_2));
    *(s16 *)(local_0 + 0xE) = func_800AE124(((s16 *)param_0->unk0)[8]);
    local_4 = func_80100074(param_0, 1, *(s16 *)(local_0 + 0xE) * 0x3C);
    local_3 = func_800AE080(((s16 *)param_0->unk0)[8]);
    for (local_5 = 0; local_5 < *(s16 *)(local_0 + 0xE); local_5++, local_4++) {
        local_4->local_5 = _dbskeleton_entrypoint_4(local_1, local_5);
        func_800F2C1C(func_800ADE50(local_3, local_1, local_4->local_5), local_4->local_3);
    }
    local_4 = func_80100094(param_0, 1);
    func_8008C200(((s16 *)param_0->unk0)[8], local_1, func_8008AEDC(local_2));
    local_3 = func_800AE080(((s16 *)param_0->unk0)[8]);
    local_8 = param_0->rotation;
    for (local_5 = 0; local_5 < *(s16 *)(local_0 + 0xE); local_5++, local_4++) {
        func_800AE630(local_3, local_1, local_4->local_5, local_4->local_1);
        func_800EF5A0(local_7, local_8, local_4->local_1[0], local_4->local_1[1], local_4->local_1[2]);
        func_800EF334(local_7, param_0->scale);
        func_800EF04C(local_7, param_0->position);
        func_800F18FC(param_2, local_7, local_6);
        func_800EFD24(local_4->local_0);
        func_800EEBF0(local_4->local_2, local_6, 1000.0f);
        if (param_3 & 0x10) {
            local_4->b7 = 1;
        }
        switch (local_4->local_5) {
        case 3:
            if (param_3 & 0x20) {
                local_4->b6 = 1;
            } else {
                local_4->b6 = 0;
            }
            break;
        default:
            local_4->b6 = 1;
            break;
        }
    }
    *(f32 *)(local_0 + 0x5C) = 1e10f;
    func_800EFD24(param_0->rotation);
    func_80100094(param_0, 1);
}

void func_80800D7C_chexploder(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; f32 *param_2; s32 param_3;
{
    u8 *local_0;
    s32 local_3;
    s32 local_4;
    u8 *local_5;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    local_3 = func_800B27E0(func_801039E4(param_0->unk0));
    *(s16 *)(local_0 + 0xE) = _dbskeleton_entrypoint_0(local_3);
    local_5 = func_80100074(param_0, 1, *(s16 *)(local_0 + 0xE) * 60);
    for (local_4 = 0; local_4 < *(s16 *)(local_0 + 0xE); local_4++, local_5 += 60) {
        local_5[0x39] = _dbskeleton_entrypoint_4(local_3, local_4);
        _dbskeleton_entrypoint_2(local_3, local_5[0x39], local_5 + 0xC);
        func_800EFD24(local_5);
        func_800EE780(local_2, local_5 + 0xC, param_0->position);
        func_800F18FC(param_2, local_2, local_1);
        func_800EEBF0((f32 *)(local_5 + 0x18), local_1, 1000.0f);
        *(f32 *)(local_5 + 0x24) = 0.0f;
        *(f32 *)(local_5 + 0x28) = param_0->rotation[1];
        *(f32 *)(local_5 + 0x2C) = 0.0f;
        if (param_3 & 0x10) {
            ((Exp36 *)local_5)->f1 = 1;
        }
        switch (local_5[0x39]) {
        case 3:
            if (param_3 & 0x20) {
                ((Exp36 *)local_5)->f2 = 1;
            } else {
                ((Exp36 *)local_5)->f2 = 0;
            }
            break;
        default:
            ((Exp36 *)local_5)->f2 = 1;
            break;
        }
    }
    *(f32 *)(local_0 + 0x5C) = 1e10f;
    func_800EFD24(param_0->rotation);
}

void func_80800F74_chexploder(Actor *param_0, s32 param_1)
{
    s16 *local_0;
    u8 *local_1;
    s32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;

    local_0 = func_80100094(param_0, 0);
    local_1 = (u8 *)func_80100094(param_0, 1);
    for (local_2 = 0; local_2 < local_0[7]; local_2++, local_1 += 0x3C) {
        if ((*(u32 *)(local_1 + 0x34) << 17) >> 31) {
            local_3 = func_800DC178(local_0[0], local_0[1]);
            local_4 = func_800DC178(local_0[4], local_0[5]);
            local_5 = func_800DC178(local_0[2], local_0[3]);
            local_6 = func_800DC178(local_0[2], local_0[3]);
            func_800EF368((f32 *)(local_1 + 0x18), local_3);
            func_800EF368((f32 *)(local_1 + 0x18), local_3);
            *(s16 *)(local_1 + 0x34) = (s16)local_4;
            *(s16 *)(local_1 + 0x30) = (s16)local_5;
            *(s16 *)(local_1 + 0x32) = (s16)local_6;
        }
    }
}

void func_808010E0_chexploder(void *param_0, s32 param_1, u32 param_2)
{
  if (param_2 & 2)
  {
    func_800E1610(0, 0x41F00000, 0x3F666666, ((int) param_0) + 4);
  }
  if (param_2 & 1)
  {
    func_80018820(0, 0x40400000, 0x3E800000);
  }
  if ((param_1 != 0) && (param_2 & 8))
  {
    func_800FFAB0(param_1);
  }
  if (param_2 & 0x40)
  {
    *((u8 *) (((char *) param_0) + 0x65)) = (u8) ((*(((char *) param_0) + 0x65)) & 0xFFFE);
  }
}

void func_80801188_chexploder(param_0, param_1, param_2) ExplS *param_0; s32 param_1; S16Pair param_2; {
    if (func_800B26F0(param_1)) {
        param_0->f70 = 1;
        param_0->f71 = 0;
    }
}

void chexploder_entrypoint_1(s32 param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4) {
    s32 local_3;
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;

    local_0 = func_80106790();
    local_2 = func_801084B0(0x1FF, &local_0);
    local_1 = func_80100094(local_2, 0);
    (*(f32 *)((s8 *)(local_2) + (0x18))) = param_1;
    (*(f32 *)((s8 *)(local_2) + (0x1C))) = param_2;
    (*(f32 *)((s8 *)(local_2) + (0x20))) = param_3;
    func_800EE7F8(local_2 + 0x44, local_0 + 0x44);
    (*(f32 *)((s8 *)(local_2) + (0x38))) = (f32) (*(f32 *)((s8 *)(local_0) + (0x38)));
    if ((*(s16 *)((s8 *)((*(u8 **)((s8 *)(local_2) + (0)))) + (0x10))) == 0) {
        (*(s16 *)((s8 *)((*(u8 **)((s8 *)(local_2) + (0)))) + (0x10))) = func_800AE020();
    }
    (*(u16 *)((s8 *)(local_1) + (0x14))) = (u16) (*(u16 *)((s8 *)((*(u8 **)((s8 *)(local_0) + (0)))) + (0x14)));
    (*(u16 *)((s8 *)(local_1) + (0x16))) = (u16) (*(u16 *)((s8 *)((*(u8 **)((s8 *)(local_0) + (0)))) + (0x16)));
    (*(s16 *)((s8 *)(local_1) + (0x54))) = (s16) param_4;
    (*(u8 *)((s8 *)(local_0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(local_0) + (0x65))) & 0xFFFE);
    func_80108944(local_2, local_0);
    func_80801188_chexploder(local_2, func_801039E4((*(u8 **)((s8 *)(local_0) + (0)))), local_0);
    (*(u8 *)((s8 *)(local_2) + (0x74))) = (u8) ((*(u8 *)((s8 *)(local_2) + (0x74))) & 0xFFFD);
    func_80103140(local_2, (*(u16 *)((s8 *)(local_1) + (0x14))), (*(u16 *)((s8 *)(local_1) + (0x16))));
    func_80800A18_chexploder(local_2);
    if (func_80104248(local_0) != 0) {
        func_80800AC8_chexploder(local_2, local_0, local_2 + 0x18, param_4);
    } else {
        func_80800D7C_chexploder(local_2, local_0, local_2 + 0x18, param_4);
    }
    func_80101074((*(u8 **)((s8 *)(local_2) + (0))));
    func_8010108C(local_0, 0x90, (*(u16 *)((s8 *)(local_1) + (0x14))));
    func_80800F74_chexploder(local_2, local_0);
    func_808010E0_chexploder(local_2, local_0, param_4);
}

void chexploder_entrypoint_2(Unk80132ED0 *marker, ExploderSpawn sp)
{
    f32 pos[3];
    Actor *a;
    Actor *p;
    ExploderSpawn *s;
    f32 yaw;
    s32 id;
    f32 sc;
    ExploderLocal *local;

    p = (Actor *)marker;
    s = &sp;
    id = s->id;
    yaw = s->yaw;
    pos[0] = s->x;
    pos[1] = s->y;
    pos[2] = s->z;
    sc = s->scale;
    a = func_80108474(0x1FF, pos, yaw);
    if (&marker) {} /* PROBE: marker home store sw a0,0x50 */
    local = func_80100094(a, 0);
    if (p) {
        p = func_80106790((Unk80132ED0 *)p);
    } else {
        p = NULL;
    }
    a->scale = sc;
    func_800EE7F8((f32 *)a->actorData, a->position);
    if (p) {
        func_80101074(a->unk0);
        if (func_8010108C(p, 0x8D, id) > 0) {
            func_80101038((f32 *)a->actorData);
        }
    }
    local->unk14 = id;
    local->unk16 = 0;
    local->unk54 = sp.flags;
    if (p) {
        func_80108944(a, p);
        ((ActorFlags74b *)((u8 *)a + 0x74))->unk74_25 = 0;
    }
    func_80103140(a, local->unk14, local->unk16);
    func_80801188_chexploder(a, func_801039E4(a->unk0), p);
    func_80800A18_chexploder(a);
    if (p && (sp.flags & 0x80) && func_80104248(p)) {
        func_80800AC8_chexploder(a, p, (f32 *)a->actorData, sp.flags);
    } else {
        func_80800D7C_chexploder(a, NULL, (f32 *)a->actorData, sp.flags);
    }
    if (p) {
        func_80101074(a->unk0);
        func_8010108C(p, 0x90, local->unk14);
    }
    func_80800F74_chexploder(a, p);
    func_808010E0_chexploder(a, p, sp.flags);
}

void chexploder_entrypoint_3(s32 *param_0, s32 param_1, s32 param_2) {
    s32 sp24[3];

    if (param_1 != 0) {
        func_800EE7F8(sp24);
    } else {
        func_80103DFC(param_0, sp24);
    }
    if (param_2 & 4) {
        func_8010A570(param_0);
    }
    _chbaddiesetup_entrypoint_5(&_chexploder_entrypoint_1, *param_0, sp24[0], sp24[1], sp24[2], param_2);
}

void chexploder_entrypoint_4(s32 param_0, s32 param_1, s32 param_2) {
    f32 local_0[3];

    func_800EE88C(local_0, param_1);
    chexploder_entrypoint_3(param_0, local_0, param_2);
}

void chexploder_entrypoint_5(s32 *param_0, s32 param_1, f32 *param_2, s32 param_3, s32 param_4, s32 param_5)
{
    s16 sp34[2];
    s16 sp30[2];
    s32 sp2C[1];

    sp2C[0] = (param_0 != NULL) ? *param_0 : 0;
    sp34[0] = param_1;
    sp34[1] = param_2[0];
    sp30[0] = param_2[1];
    sp30[1] = param_2[2];
    if (param_5 & 4) {
        func_8010A570();
    }
    _chbaddiesetup_entrypoint_6(&_chexploder_entrypoint_2, sp2C[0], *(s32 *)sp34, *(s32 *)sp30, param_3, param_4, param_5);
}

int chexploder_entrypoint_6(f32 param_0[3], f32 param_1, f32 param_2)
{
  s16 *local_0;
  local_0 = func_80100094(param_0, 0);
  local_0[0] = param_1;
  local_0[1] = param_2;
}

void chexploder_entrypoint_7(s32 param_0, f32 param_1, f32 param_2)
{
    void *local_0;
    local_0 = func_80100094(param_0, 0);
    *(s16 *)((char *)local_0 + 8) = (s16)param_1;
    *(s16 *)((char *)local_0 + 10) = (s16)param_2;
}

int chexploder_entrypoint_8(f32 param_0[3], f32 param_1, f32 param_2)
{
  int new_var;
  s16 *local_0;
  new_var = 0xFFu;
  local_0 = func_80100094(param_0, 0);
  *(s16*)((s8*)local_0 + 4) = (s16) (s32) param_1;
  local_0[3] = param_2;
}

void chexploder_entrypoint_9(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    u8 *local_0 = func_80100094(param_0, 0);
    local_0[param_1 + 0x18] = param_2;
    if (local_0[0x18] < param_1) {
        local_0[0x18] = param_1;
    }
}

void chexploder_entrypoint_10(Actor *param_0, s16 *param_1)
{
    ExploderPartCount1332 *local_0;
    ExploderSelectablePart1332 *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80100094(param_0, 1);
    for (local_2 = 0; local_2 < local_0->local_0; local_2++) {
        local_4 = 0;
        for (local_3 = 0; param_1[local_3] != -1; local_3++) {
            if (local_1->local_1 == param_1[local_3]) {
                local_4 = 1;
                break;
            }
        }
        local_1->local_0 = local_4;
        local_1++;
    }
}

void chexploder_entrypoint_11(Actor *param_0, s16 *param_1)
{
    ExploderCount *local_0;
    ExploderPiece *local_1;
    s32 local_2;
    s16 *local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80100094(param_0, 1);
    for (local_2 = 0; local_2 < local_0->count; local_2++, local_1++) {
        if (*param_1 != -1) {
        local_3 = param_1;
        do {
            if (local_1->id == *local_3) {
                local_1->active = 0;
                break;
            }
            local_3++;
        } while (*local_3 != -1);
        }
    }
}

int chexploder_entrypoint_12(s32 param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80100094(param_0, 0);
  *(s16 *)((char *)(local_0) + 0xC) = param_1 * (*(f32 *)((char *)(param_0) + 0x38));
}

void chexploder_entrypoint_13(s32 unused, s32 param_1) {
    s8 *local_0;
    local_0 = func_80100094(unused, 0);
    local_0[0x12] = (s8) param_1;
}

s32 chexploder_entrypoint_14(s32 param_0, s32 param_1)
{
  *(s16 *)((char *)func_80100094(param_0, 0) + 0x10) = param_1;
}

void chexploder_entrypoint_15(Actor *param_0, s32 param_1, f32 param_2)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    *(s8 *)(local_0 + 0x13) = param_1;
    *(f32 *)(local_0 + 0x58) = param_2;
}

void chexploder_entrypoint_16(Actor *param_0, s32 param_1)
{
    ExploderAnimation1246 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0->local_0 = param_1;
    func_80103140(param_0, local_0->local_0, local_0->local_1);
}
