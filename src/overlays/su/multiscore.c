#include "common.h"

#define MULTI_SCORE_ROW_VIEW_DEFINED
typedef struct { u8 pad_0; u8 type; s16 icon; u8 visible; u8 finished; u8 value; u8 pad_1; s16 score; u8 pad_2[6]; f32 amount; f32 progress; s32 pad_3; s32 selection; } MultiScoreCard;
typedef struct { u8 pad_0[0x18]; MultiScoreCard cards[9]; s32 owner; } MultiScoreCardRow;
extern s32 D_808014B0_sumultiscore[];
extern f32 func_800D8FF8(void);
extern s32 func_800F1418(s32 param_0, s32 param_1);
typedef struct { u8 pad[8]; s16 f8; u8 padA[0xA]; f32 f14; u8 pad18[8]; } ScoreSub;
typedef struct { u8 pad[0x40]; ScoreSub sub[7]; u8 pad2[0x13C - 0x40 - 0xE0]; } ScorePl;
typedef struct { u8 pad0[0xC]; s16 unkC; u8 padE[0xE]; f32 unk1C; } MultiScoreEntry;
typedef struct { u8 pad0[0x3C]; MultiScoreEntry unk3C[8]; } MultiScoreRow;
typedef struct { u8 pad0[6]; u8 unk6; u8 pad7[0x19]; } ScoreEntry;
typedef struct { u8 pad0[0x18]; ScoreEntry entries[9]; u8 pad138[4]; } ScorePlayer;
typedef struct { s32 unk0; u8 pad4[0x24]; ScorePlayer players[4]; s32 unk518; } MultiScore;
extern void func_800B8C50(void);
extern void func_800B8C98();
extern void func_800B8CBC(s32, s32, s32);
extern void func_800B7F14(s32);
extern void func_800B811C(s32);
typedef struct { u8 pad_0; u8 local_0; u16 local_1; u8 local_2; u8 local_3; u8 pad_1[6]; s8 local_4; s8 local_5; u8 pad_2[2]; f32 local_6; } MultiScoreDrawItem;
extern int _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
typedef struct { u16 local_0; u16 local_1; } MultiScorePosition;
extern f32 mlAbsF(f32);
extern f32 func_800138D0(f32);
typedef struct { u8 pad[0x13C]; } E13C;
extern int func_800F1574(f32 *, f32);
extern f32 func_80013970(f32);
typedef struct { s16 pad_0, sound; u8 pad_1[6]; s8 offset; u8 pad_2; s8 adjustment; u8 pad_3[3]; f32 duration; } MultiScoreState1436;
extern int _gcstatusDll_entrypoint_13(s32);
void sumultiscore_entrypoint_9();
void func_80801160_sumultiscore();
void sumultiscore_entrypoint_4();
void func_80800BFC_sumultiscore();
void func_808011E0_sumultiscore();
void func_80801340_sumultiscore();
void *D_exp_sumultiscore_entrypoint_4[] = { (void *)sumultiscore_entrypoint_4 };

void sumultiscore_entrypoint_0(s32 *param_0, s32 *param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    for (local_0 = 1; local_0 < param_2; local_0++) {
        for (local_1 = local_0; local_1 > 0 && param_0[local_1 - 1] < param_0[local_1]; local_1--) {
            local_2 = param_0[local_1];
            param_0[local_1] = param_0[local_1 - 1];
            param_0[local_1 - 1] = local_2;
            local_2 = param_1[local_1];
            param_1[local_1] = param_1[local_1 - 1];
            param_1[local_1 - 1] = local_2;
        }
    }
}

void sumultiscore_entrypoint_1(s32 *param_0, s32 *param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    for (local_0 = 1; local_0 < param_2; local_0++) {
        for (local_1 = local_0; local_1 > 0 && param_0[local_1] < param_0[local_1 - 1]; local_1--) {
            local_2 = param_0[local_1];
            param_0[local_1] = param_0[local_1 - 1];
            param_0[local_1 - 1] = local_2;
            local_2 = param_1[local_1];
            param_1[local_1] = param_1[local_1 - 1];
            param_1[local_1 - 1] = local_2;
        }
    }
}

void func_80800140_sumultiscore(s32 *param_0, s32 *param_1, s32 *param_2, s32 param_3)
{
    s32 local_0;
    s32 local_1;

    local_1 = 1;
    for (local_0 = 0; local_0 < param_3; local_0++) {
        if (local_1 >= 2 && param_0[local_0] == param_0[local_0 - 1]) {
            param_2[local_0] = param_2[local_0 - 1];
            param_1[local_0] = 1;
            param_1[local_0 - 1] = 1;
        } else {
            param_2[local_0] = local_1;
        }
        local_1++;
    }
}

s32 sumultiscore_entrypoint_2(s32 *param_0, s32 *param_1, s32 *param_2, s32 param_3, s32 param_4)
{
    s32 local_0[4];
    s32 local_1[4];
    s32 local_2[4];
    s32 local_3[4];
    s32 local_4;
    s32 local_5;

    for (local_4 = 0; local_4 < param_4; local_4++) {
        local_0[local_4] = local_4;
        local_2[local_4] = param_0[local_4];
        local_3[local_4] = 0;
    }
    if (param_3 == 0) {
        sumultiscore_entrypoint_0(local_2, local_0, param_4);
        func_800AA200(0);
    } else {
        sumultiscore_entrypoint_1(local_2, local_0, param_4);
        func_800AA200(1);
    }
    func_80800140_sumultiscore(local_2, local_3, local_1, param_4);
    for (local_4 = 0; local_4 < param_4; local_4++) {
        param_1[local_0[local_4]] = local_1[local_4];
        param_2[local_0[local_4]] = local_3[local_4];
    }
    if (func_800D3948()) {
        local_5 = _gcstatusDll_entrypoint_11();
        for (local_4 = 0; local_4 < local_5; local_4++) {
            func_800AA20C(local_4, param_0[local_4]);
        }
    }
    if (local_1[0] == local_1[1]) {
        return 0;
    }
    return local_0[0] + 1;
}

void sumultiscore_entrypoint_3(u8 *param_0) {
    s32 local_5;
    u8 * local_6;
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    u8 * local_7;

    (*(s32 *)((s8 *)(param_0) + (0x518))) = _gcstatusDll_entrypoint_11();
    local_5 = 0;
    if ((*(s32 *)((s8 *)(param_0) + (0x518))) > 0) {
        local_7 = param_0 + 0x28;
        do {
            local_6 = local_7;
            func_800A8A04(func_800A940C(local_5), &local_0, &local_1, &local_2, &local_3);
            local_5 += 1;
            local_7 += 0x13C;
            (*(s16 *)((s8 *)(local_7) + (-0x13C))) = (s16) (local_0 + 0x1C);
            (*(s16 *)((s8 *)(local_7) + (-0x13A))) = (s16) (local_1 + 0xE);
            (*(s16 *)((s8 *)(local_7) + (-0x138))) = (s16) ((local_2 / 2) + local_0);
            (*(s16 *)((s8 *)(local_7) + (-0x136))) = (s16) (local_1 + 0xE);
            (*(s16 *)((s8 *)(local_7) + (-0x134))) = (s16) ((local_2 + local_0) - 0x1C);
            (*(s16 *)((s8 *)(local_7) + (-0x132))) = (s16) (local_1 + 0xE);
            (*(s16 *)((s8 *)(local_7) + (-0x130))) = (s16) (local_0 + 0x1C);
            (*(s16 *)((s8 *)(local_7) + (-0x12E))) = (s16) ((local_3 + local_1) - 0xE);
            (*(s16 *)((s8 *)(local_7) + (-0x12C))) = (s16) ((local_2 + local_0) - 0x1C);
            (*(s16 *)((s8 *)(local_6) + (0x12))) = (s16) ((local_3 + local_1) - 0xE);
            (*(s16 *)((s8 *)(local_6) + (0x14))) = (s16) ((local_2 / 2) + local_0);
            (*(s16 *)((s8 *)(local_6) + (0x16))) = (s16) ((local_3 / 2) + local_1);
        } while (local_5 < (*(s32 *)((s8 *)(param_0) + (0x518))));
    }
    (*(s32 *)((s8 *)(param_0) + (0))) = 0;
    sumultiscore_entrypoint_4(param_0, 0, 5, 0);
}

void sumultiscore_entrypoint_4(param_0, param_1, param_2, param_3) u8 *param_0; u32 param_1; s32 param_2; s32 param_3;
{
    s32 local_1;
    u8 *local_2;
    u8 *local_3;

    local_1 = 0;
    local_3 = param_0;
    for (; local_1 < *(s32 *)(param_0 + 0x518); local_1++, local_3 += 0x13C) {
        local_2 = local_3;
        local_2 += (*(s32 *)param_0 << 5);
        local_2[0x40] = param_1;
        local_2 = local_2 + 0x40;
        local_2[1] = param_2;
        local_2[6] = param_3;
        local_2[4] = 0;
        local_2[5] = 255;
        *(s16 *)(local_2 + 8) = 0;
        local_2[0xA] = 5;
        local_2[0xB] = 0;
        *(s8 *)(local_2 + 0xC) = -5;
        local_2[0xD] = 0;
        switch (param_1) {
        case 0: local_2[5] = 0; break;
        case 1: *(s16 *)(local_2 + 2) = 0xB4D; *(f32 *)(local_2 + 0x10) = 0.4f; break;
        case 2: case 5: func_80801340_sumultiscore(local_2, local_1); break;
        case 3: *(s16 *)(local_2 + 2) = 0xB81; *(f32 *)(local_2 + 0x10) = 0.5f; break;
        case 4: *(s16 *)(local_2 + 2) = 0xC14; *(f32 *)(local_2 + 0x10) = 0.5f; break;
        case 6:
            *(s16 *)(local_2 + 2) = 0xB89;
            *(f32 *)(local_2 + 0x10) = 0.75f;
            local_2[0xA] = 10;
            *(s8 *)(local_2 + 0xC) -= 5;
            break;
        case 7:
            *(s16 *)(local_2 + 2) = 0xB8B;
            *(f32 *)(local_2 + 0x10) = 0.75f;
            *(s8 *)(local_2 + 0xC) -= 5;
            break;
        case 8: func_80801340_sumultiscore(local_2, local_1); break;
        }
    }
    *(s32 *)(param_0 + param_1 * 4 + 4) = *(s32 *)param_0;
    (*(s32 *)param_0)++;
}

void sumultiscore_entrypoint_5(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    MultiScoreCardRow *local_0;
    MultiScoreCard *local_1;
    MultiScoreCard *local_2;
    MultiScoreCard *local_3;

    local_0 = &((MultiScoreCardRow *)(param_0 + 0x28))[param_1];
    local_1 = ((s32 *)(param_0 + 4))[param_2] + local_0->cards;
    local_2 = *(s32 *)(param_0 + 4) + local_0->cards;
    if (local_0->owner) {
        local_3 = ((s32 *)(param_0 + 4))[local_0->owner] + local_0->cards;
        local_3->value = local_2->value;
    }
    local_0->owner = param_2;
    local_2->type = local_1->type;
    local_2->amount = local_1->amount;
    local_2->selection = param_3;
    local_2->value = local_1->value;
    local_1->value = 0;
    if (param_2 == 3) {
        local_2->icon = D_808014B0_sumultiscore[param_3];
        local_2->visible = 0;
        local_2->score = _badeathmatch_entrypoint_9(func_800F53D0(param_1), param_3);
        local_2->finished = 0;
        local_2->progress = 1.0f;
    }
}

void func_80800E84_sumultiscore();

void func_80800DD0_sumultiscore();

void func_80800D64_sumultiscore();

void func_80800D54_sumultiscore();

void sumultiscore_entrypoint_6(u8 *param_0)
{
    s32 local_1;
    s32 local_2;
    u8 *local_5;
    u8 *local_8;
    u8 *local_7;
    f32 local_0;

    local_1 = 0;
    if (*(s32 *)(param_0 + 0x518) > 0) {
        do {
            local_2 = 0;
            if (*(s32 *)param_0 > 0) {
                local_5 = param_0 + 0x28 + local_1 * 0x13C;
                do {
                    local_8 = (u8 *)((s32)local_5 + (local_2 << 5));
                    local_7 = local_8 + 0x18;
                    if (*(f32 *)(local_8 + 0x30) != 0.0f) {
                        func_800F1574((f32 *)(local_7 + 0x18), func_800D8FF8());
                        local_0 = *(f32 *)(local_7 + 0x18);
                        local_0 = local_0 - (f32)(s32)local_0;
                        *(u8 *)(local_7 + 5) = (s32)(mlAbsF(func_800138D0(local_0 * 720.0f)) * 255.99f);
                    }
                    switch (*local_7) {
                    case 0:
                        func_80800BFC_sumultiscore(param_0, local_1, local_7);
                        break;
                    case 1:
                        func_80800D24_sumultiscore(param_0, local_1, local_7);
                        break;
                    case 2:
                        func_80800D54_sumultiscore(param_0, local_1, local_7);
                        break;
                    case 3:
                        func_80800D64_sumultiscore(param_0, local_1, local_7);
                        break;
                    case 4:
                        func_80800DD0_sumultiscore(param_0, local_1, local_7);
                        break;
                    case 5:
                        func_80800E84_sumultiscore(param_0, local_1, local_7);
                        break;
                    }
                    local_2++;
                } while (local_2 < *(s32 *)param_0);
            }
            local_1++;
        } while (local_1 < *(s32 *)(param_0 + 0x518));
    }
}

void func_80800BFC_sumultiscore(param_0, param_1, param_2) u8 *param_0; s32 param_1; u8 *param_2;
{
    f32 local_2;
    s32 local_0;
    u8 *local_1;
    u8 *local_3;

    if (param_2[6]) {
        local_1 = (u8 *)&((E13C *)param_0)[param_1];
        if (*(s32 *)(local_1 + 0x160) == 3) {
            local_0 = *(s32 *)(param_2 + 0x1C);
            *(s16 *)(param_2 + 8) = _badeathmatch_entrypoint_9(func_800F53D0(param_1), local_0);
        }
        if (func_800F1574((f32 *)(param_2 + 0x14), func_800D8FF8())) {
            u8 *local_3 = local_1 + ((s32 *)param_0)[*(s32 *)(local_1 + 0x160) + 1] * 0x20 + 0x40;
            local_3[6] = param_2[6];
            *(s32 *)(local_1 + 0x160) = 0;
            param_2[6] = 0;
        } else {
            local_2 = *(f32 *)(param_2 + 0x14);
            local_2 -= (s32)local_2;
            param_2[5] = (s32)(mlAbsF(func_80013970(local_2 * 720.0f)) * 255.99f);
        }
    }
}

int func_80800D24_sumultiscore(s32 param_0, s32 param_1, s16 *param_2)
{
  s32 local_0;
  local_0 = func_800F5578(param_1 | 0);
  param_2[4] = local_0;
}

void func_80800D54_sumultiscore(s32 arg0, s32 arg1, s32 arg2) {
}
void func_80800D64_sumultiscore(s32 param_0, s32 param_1, u8 *param_2)
{
    s32 local_1;

    local_1 = _badeathmatch_entrypoint_6(func_800F53D0(param_1));
    ((s16 *)param_2)[1] = D_808014B0_sumultiscore[local_1];
    ((s16 *)param_2)[4] = _badeathmatch_entrypoint_9(func_800F53D0(param_1), local_1);
}

void func_80800DD0_sumultiscore(s32 param_0, s32 param_1, u8 *param_2)
{
    u8 temp_v0;

    if ((*(f32 *)((u8 *)(param_2) + 0x14)) != 0.0f)
    {
        func_800F1574(param_2 + 0x14, func_800D8FF8());
        if ((*(u8 *)((u8 *)(param_2) + 6)) == 0)
        {
            (*(u8 *)((u8 *)(param_2) + 6)) = 1U;
            (*(u8 *)((u8 *)(param_2) + 5)) = 0U;
            return;
        }
        (*(u8 *)((u8 *)(param_2) + 5)) = func_800F1418((*(u8 *)((u8 *)(param_2) + 5)) + 0x20, 0xFF);
        return;
    }
    if ((*(u8 *)((u8 *)(param_2) + 6)) != 0)
    {
        temp_v0 = (*(u8 *)((u8 *)(param_2) + 5));
        if ((s32) temp_v0 >= 0x21)
        {
            (*(u8 *)((u8 *)(param_2) + 5)) = (u8) (temp_v0 - 0x20);
            return;
        }
        (*(u8 *)((u8 *)(param_2) + 6)) = 0U;
    }
}

void func_80800E84_sumultiscore(s32 arg0, s32 arg1, s32 arg2) {
}
void sumultiscore_entrypoint_7(ScorePl *param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0 = ((s32 *)((u8 *)param_0 + 4))[param_2];
    param_3 += param_0[param_1].sub[local_0].f8;
    sumultiscore_entrypoint_9(param_0, param_1, param_2, param_3);
}

s16 sumultiscore_entrypoint_8(MultiScoreRow *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    local_0 = ((s32 *)((u8 *)param_0 + 4))[param_2];
    return param_0[param_1].unk3C[local_0].unkC;
}

void sumultiscore_entrypoint_9(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; s32 param_2; u32 param_3;
{
  u8 *new_var;
  s32 local_0;
  u8 *local_1;
  int new_var2;
  new_var2 = param_1 * 316;
  local_1 = param_0 + new_var2;
  local_0 = *(((s32 *) (param_0 + 4)) + param_2);
  *((s16 *) ((local_1 + (local_0 * 32)) + 0x48)) = param_3;
  if (param_2 == 4)
  {
    u32 local_2 = local_0 * 32;
    new_var = local_1 + local_2;
    *((f32 *) (new_var + 0x54)) = 1.0f;
  }
}

void sumultiscore_entrypoint_10(u8 *param_0, s32 param_1)
{
  s32 new_var;
  *((s8 *) (((s8 *) ((param_0 + (param_1 * 0x13C)) + ((new_var = *((s32 *) (param_0 - -0x18))) << 5))) + 0x47)) = 1;
}

void sumultiscore_entrypoint_11(MultiScoreRow *param_0, s32 param_1, s32 param_2, f32 param_3)
{
    s32 local_0;

    local_0 = ((s32 *)((u8 *)param_0 + 4))[param_2];
    param_0[param_1].unk3C[local_0].unk1C = param_3;
}

void sumultiscore_entrypoint_12(MultiScore *param_0, s32 param_1, s32 param_2)
{
    s32 i;
    s32 j;
    ScorePlayer *local_0;

    for (i = 0; i < param_0->unk518; i++) {
        local_0 = &param_0->players[i];
        for (j = 0; j < param_0->unk0; j++) {
            if (param_2 == local_0->entries[j].unk6) {
                func_80801160_sumultiscore(local_0, local_0->entries + j, param_1);
            }
        }
    }
    func_800B8C50();
    func_800B8C98(3);
    func_800B8CBC(0xFF, 0xFF, 0xFF);
    func_800B7F14(param_1);
    for (i = 0; i < param_0->unk518; i++) {
        local_0 = &param_0->players[i];
        for (j = 0; j < param_0->unk0; j++) {
            if (param_2 == local_0->entries[j].unk6) {
                func_808011E0_sumultiscore(local_0, local_0->entries + j, i, param_1);
            }
        }
    }
    func_800B811C(param_1);
}

void func_80801160_sumultiscore(param_0, param_1, param_2) MultiScorePosition *param_0; MultiScoreDrawItem *param_1; s32 param_2;
{
    MultiScorePosition *local_0;
    s32 local_1;
    s32 local_2;
    local_0 = param_0;
    local_0 += param_1->local_0;
    local_1 = param_1->local_4 + local_0->local_0;
    local_2 = param_1->local_5 + local_0->local_1;
    _fxdialog_entrypoint_1(local_1, local_2);
    _fxdialog_entrypoint_2(param_1->local_6);
    _fxdialog_entrypoint_4(param_2, param_1->local_1, param_1->local_2, 0.0f, 0.0f, param_1->local_3, 0);
}

void func_808011E0_sumultiscore(param_0, param_1, param_2, param_3) u16 param_0[][2]; u8 *param_1; s32 param_2; s32 param_3;
{
    char local_0[16];
    s32 local_1 = param_0[param_1[1]][0] + *(s8 *)(param_1 + 10);
    s32 local_2 = param_0[param_1[1]][1] + *(s8 *)(param_1 + 11);
    s32 local_3;

    if (param_1[0] == 5) {
        local_3 = param_1[7] && func_8001210C(8) ? param_1[5] : param_1[5] >> 1;
        func_800B8C98(0, local_3);
        func_800B8C8C(local_3);
        func_800B80D0(param_3);
        sprintf(local_0, "PLAYER %d", param_2 + 1);
        func_800B8E28(param_3, local_1 - 32, local_2 - 12, local_0);
    }
    local_3 = (s32)((f32)(u32)param_1[5] * 0.667f);
    func_800B8C98(3, local_3);
    func_800B8C8C(local_3);
    func_800B80D0(param_3);
    sprintf(local_0, "%d", *(s16 *)(param_1 + 8));
    func_800B8E28(param_3, local_1, local_2, local_0);
}

void func_80801340_sumultiscore(param_0, param_1) MultiScoreState1436 *param_0; s32 param_1;
{
    switch (_gcstatusDll_entrypoint_13(param_1)) {
    default:
        param_0->sound = 0xB50; param_0->offset += 10; param_0->duration = 0.5f;
        break;
    case 2:
        param_0->sound = 0xBD9;
        param_0->duration = 0.6f;
        param_0->adjustment -= 5;
        break;
    case 3:
        param_0->sound = 0xBD0;
        param_0->duration = 0.6f;
        param_0->adjustment -= 5;
        break;
    case 4:
        param_0->sound = 0xBAB;
        param_0->duration = 0.7f;
        param_0->adjustment -= 7;
        break;
    case 5:
        param_0->sound = 0xBA2;
        param_0->duration = 0.6f;
        param_0->adjustment -= 6;
        break;
    }
}
