#include "common.h"

extern int D_80801424_chminisubgame[];
extern int D_8080146C_chminisubgame[];
extern void *func_80100094(Actor *, u32);
extern void _susubgame_entrypoint_11(s32);
extern s32 B_80801590_chminisubgame;
extern s32 _susubgame_entrypoint_2(Actor *, void *);
extern void _susubgame_entrypoint_4(Actor *, void *);
typedef struct { u16 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; s16 local_5; } MinisubgameRecord;
typedef struct { f32 local_0[60][3]; u8 local_1[60]; u8 local_2[1]; } MinisubgameData;
extern MinisubgameRecord D_80801400_chminisubgame[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800E3980(f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
extern void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
extern s32 _susubgame_entrypoint_3(Actor *, void *, s32, s32);
extern void func_8008FE68(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct MiniSubGameData { f32 local_0[60][3]; u8 local_1[60]; } MiniSubGameData;
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
typedef struct { u8 pad[0x18]; u16 hi : 15; u16 b0 : 1; } MS18;
extern s32 _subaddiemulti_entrypoint_5(Actor *);
extern void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
extern void func_8010114C(Actor *, s32, s32);
extern void func_8010A570(Actor *);
extern s32 func_8010CC10(f32 *, s32);
extern void func_8010CCE0(void);
extern s32 func_8010CCEC(void);
extern void func_800F7A2C(s32, s32, f32 *);
extern s32 D_808014B4_chminisubgame[];
extern u8 D_80801578_chminisubgame[];
extern u8 D_80801534_chminisubgame[];
extern u8 D_808014F0_chminisubgame[];
typedef union { struct { s16 a; s16 b; } h; s32 w; } MSPair;
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern void func_800CE8D8(s32, f32, s32);
s32 func_80801058_chminisubgame();
void func_80801248_chminisubgame();
void func_80800BA8_chminisubgame();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(), func_80800EC8_chminisubgame();

int chminisubgame_entrypoint_0()
{
    return (int)&D_80801424_chminisubgame;
}

int chminisubgame_entrypoint_1()
{
    return (int)&D_8080146C_chminisubgame;
}

/* TU-NOTE: the .bss of this file (formerly asm/data/overlays/ch/minisubgame.bss.s) is defined here in C, ahead of
 * its first use: IDO places .bss objects used before their definition first, the rest in definition
 * order. The _pad/_tail objects fill bytes that no code names. */
s32 B_80801590_chminisubgame;
u8 B_80801590_chminisubgame_tail[4];
u8 B_80801590_chminisubgame_tail1[232];


void func_80800018_chminisubgame(u8 *param_0) {
    s32 local_0;
    s32 *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094((Actor *)param_0, 0);
    local_2 = _gccubesearch_entrypoint_9(0x1C0, &B_80801590_chminisubgame, 0x3C);
    (*(s32 *)((s8 *)(param_0) + (0x30))) = local_2;
    local_3 = 0;
    if (local_2 > 0) {
        local_1 = &B_80801590_chminisubgame;
        local_4 = local_0;
        do {
            _gspropctrl_entrypoint_11(*local_1, local_4);
            local_3 += 1;
            local_1 += 1;
            local_4 += 0xC;
        } while (local_3 < (*(s32 *)((s8 *)(param_0) + (0x30))));
    }
    _susubgame_entrypoint_0(param_0, local_0 + 0x30C, 0);
    _susubgame_entrypoint_11(0);
}

s32 func_80800AAC_chminisubgame();

void func_808000C8_chminisubgame(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_13;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_2;
    MSPair pr;
    s32 local_9;
    f32 local_10;
    s32 local_11;

    switch ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) {
    case 2:
        func_800D24E8(0xFC, *(s32 *)((u8 *)param_0 + 0x28), 0);
        if (func_800CEAD0(0) != 0) {
            local_1 = 4;
            local_3 = func_800D2054(0, 0x88, *(s32 *)((u8 *)param_0 + 0x28));
            local_4 = func_80100094(param_0, 0);
            func_800BF99C(0, 0x5AA, 1);
            func_80090708(2);
            _susubgame_entrypoint_5(param_0, local_4 + 0x30C, 5, 1, 0);
            func_80101180(0x4AE, 0x3E, 0);
            if (func_800D395C() != 0) {
                if (local_3 == 1) {
                    local_0 = 0x104A;
                    local_13 = 0x16;
                } else if (local_3 == 0) {
                    local_0 = 0x104B;
                    local_13 = 0x17;
                } else {
                    local_0 = 0x104C;
                    local_13 = 0x17;
                }
            } else if (func_800D0A9C(0x1F, 1) == 0 && *(s32 *)((u8 *)param_0 + 0x28) >= 0x3C) {
                local_0 = 0x1030;
                local_1 = 0x44;
                local_13 = 0x16;
            } else {
                local_1 = 6;
                if (func_800D0A9C(0x1F, 1) == 0) {
                    local_11 = *(s32 *)((u8 *)param_0 + 0x28);
                    switch (local_11) {
                    case 0:
                        local_0 = 0x1034;
                        local_13 = 0x17;
                        break;
                    case 1:
                        local_0 = 0x1046;
                        local_13 = 0x17;
                        break;
                    default:
                        local_0 = 0x1032;
                        local_13 = 0x17;
                        break;
                    }
                } else if (local_3 == 1) {
                    local_0 = 0x1031;
                    local_13 = 0x16;
                } else {
                    local_0 = *(s32 *)((u8 *)param_0 + 0x28) != 0 ? 0x1033 : 0x1034;
                    local_13 = 0x17;
                }
            }
            func_800FDC28(0, local_13);
            func_800FC6B0(local_13);
            _subaddiedialog_entrypoint_11(*(s32 *)param_0, local_0, local_1, 0, 0x22);
            func_80101FDC(param_0, 3);
            return;
        }
    case 1:
        if (*(s32 *)((u8 *)param_0 + 0x2C) < 0xF && func_800DC298(0.2f) != 0) {
            local_5 = func_80800AAC_chminisubgame(param_0);
            local_6 = 0;
            local_10 = func_800DC0C0();
            if (local_10 < 0.1666666f) {
                local_6 = 2;
            } else if (local_10 < 0.5f) {
                local_6 = 1;
            }
            if (local_5 != -1) {
                pr.h.a = local_6;
                pr.h.b = local_5;
                func_80108B04(param_0, pr.w);
            }
        }
        break;
    case 5:
        if (func_800D0B68(0x1F, 1) != 0 && func_800D90A4((u8 *)param_0 + 0x18) != 0) {
            local_9 = func_80100094(param_0, 0);
            func_80090708(2);
            _susubgame_entrypoint_5(param_0, local_9 + 0x30C, 5, 1, 0);
            _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0xCEB, 0x46, 0, 0x22);
            func_80101FDC(param_0, 3);
        }
        break;
    }
}

void func_80800430_chminisubgame(Actor *param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(param_0, local_0 + 0x30C)) {
        _susubgame_entrypoint_4(param_0, local_0 + 0x30C);
    }
}

s32 func_80800484_chminisubgame(Actor *param_0, s32 param_1, s32 param_2)
{
    MinisubgameData *local_0;
    Actor *local_1;
    s32 local_2;
    s32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    union {
        struct {
            s16 local_0;
            s16 local_1;
        } local_0;
        u32 local_1;
    } local_6;
    MinisubgameRecord *local_7;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x95:
        if (func_800D0A9C(0x1F, 1) && !func_800D0B68(0x1F, 1)) {
            func_80101FDC(param_0, 5);
            *(f32 *)&param_0->actorData[0] = 0.5f;
        } else {
            func_80090708(2);
            func_800DA544(0);
            if (func_800D395C()) {
                _susubgame_entrypoint_5(param_0, local_0->local_2, 5, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1049, 6, 0, 0x22);
            } else if (func_800DA298(0x6E5)) {
                _susubgame_entrypoint_5(param_0, local_0->local_2, 5, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x102D, 6, 0, 0x22);
            } else {
                _susubgame_entrypoint_6(param_0, local_0->local_2, 5, 0x20, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0,
                    !func_800D0A9C(0x1F, 1) ? 0x102C : 0x102D, 6, 0, 0x22);
            }
        }
        break;
    case 0x3D:
        local_2 = ((s16 *)&param_2)[1];
        local_3 = ((s16 *)&param_2)[0];
        if (local_2 < 0) {
            func_800EE7F8(local_4, param_0->position);
        } else {
            func_800EE7F8(local_4, local_0->local_0[local_2]);
            local_0->local_1[local_2] = 1;
            param_0->actorData[5]++;
        }
        local_1 = func_80108528(0x4AE, local_4, 0, &param_0);
        local_1->unk3C = param_0->unk0;
        if (local_2 >= 0) {
            func_800E3980(local_5);
            local_1->rotation[1] = func_80102D78(param_0, local_5);
        }
        local_1->unk6C_0 = local_3;
        local_1->actorData[7] = local_2;
        local_7 = &D_80801400_chminisubgame[local_3];
        func_80103140(local_1, local_7->local_0, 0);
        *(f32 *)&local_1->actorData[3] = func_800DC178(local_7->local_1, local_7->local_2);
        local_1->unk58 = func_800DC178(local_7->local_3, local_7->local_4);
        *(f32 *)&local_1->actorData[5] = local_1->unk58;
        *(f32 *)&local_1->actorData[6] = local_1->position[1];
        *(f32 *)&local_1->actorData[4] = 0.0f;
        local_1->unk50 = local_7->local_5;
        if (local_2 < 0) {
            param_0->unk3C = local_1->unk0;
        }
        if (local_2 >= 0 || local_1->unk6C_0 == 2) {
            _subaddiefade_entrypoint_2(local_1);
        }
        return 1;
    case 0x2E:
        func_80800BA8_chminisubgame(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x30: {
        local_3 = ((s16 *)&param_2)[0];
        switch (local_3) {
        case 0x1032:
            return param_0->actorData[4];
        case 0x102C:
            return 60;
        case 0x1033:
        case 0x104C:
            if (((s16 *)&param_2)[1] == 0) {
                return param_0->actorData[4];
            }
        default:
            return func_800D211C(0x88, local_3);
        }
    }
    case 0x2F:
        local_6.local_0.local_0 = ((s16 *)&param_2)[1] - 1;
        local_6.local_0.local_1 = -1;
        if (((s16 *)&param_2)[1] == 3) {
            _susubgame_entrypoint_6(param_0, local_0->local_2, 9, 0xA0, 0);
        }
        func_80108B04(param_0, local_6.local_1);
        if (param_0->unk3C != NULL) {
            func_8010114C(param_0->unk3C, 0x3E, 0);
            param_0->unk3C = NULL;
        }
        break;
    case 0xE:
        if (param_2 == 9 && param_0->unk3C != NULL) {
            _capod_entrypoint_19(func_80106790(param_0->unk3C)->position);
        }
        return 3;
    case 0xB:
        if (param_2 == 1) {
            func_80090708(0);
            _susubgame_entrypoint_4(param_0, local_0->local_2);
            func_80101FDC(param_0, 5);
            *(f32 *)&param_0->actorData[0] = 0.5f;
            return 4;
        }
        return 3;
    case 0x57:
        return _susubgame_entrypoint_3(param_0, local_0->local_2,
            param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_800BF99C(0, 0x5AA, 1);
        func_80101180(0x4AE, 0x3E, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, 0, 0x22);
        func_80101FDC(param_0, 3);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800A64_chminisubgame(void *param_0, s32 param_1)
{
  char *new_var;
  s32 new_var2;
  s32 local_0;
  local_0 = func_80100094(param_0, 0);
  new_var2 = 2;
 ((s32 *) param_0)[0x2C / 4]--; ;
  *((local_0 + ((char *) param_1)) + 0x2D0) = 2;
}

s32 func_80800AAC_chminisubgame(Actor *param_0)
{
    MiniSubGameData *local_1;
    f32 local_0[3];
    s32 local_2;
    s32 local_3;

    local_1 = func_80100094(param_0, 0);
    func_8008FE68(local_0);
    for (local_2 = 0; local_2 < (s32)param_0->actorData[6]; local_2++) {
        local_3 = func_800DC128(0, param_0->actorData[6]);
        if (func_800EEAD4(local_1->local_0[local_3], local_0) > 1200.0f) {
            if (local_1->local_1[local_3] == 2) {
                local_1->local_1[local_3] = 0;
            } else if (local_1->local_1[local_3] == 0) {
                return local_3;
            }
        }
    }
    return -1;
}

void func_80800BA8_chminisubgame(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_2 = 4;
    local_1 = 0;
    switch (param_1) {
    case 0x102C:
    case 0x102D:
    case 0x1049:
        _susubgame_entrypoint_5(param_0, local_0 + 0x30C, 5, 1, 0);
        if (func_800DA298(0x6E5) || func_800D395C()) {
            local_1 = 0xCEC;
        } else {
            local_1 = 0x102E;
            local_2 = 0x46;
        }
        break;
    case 0x102E:
        if (param_2 == 1) {
            local_1 = 0x102F;
            local_2 = 0x46;
            _susubgame_entrypoint_6(param_0, local_0 + 0x30C, 0xD, 0x20, 0);
        } else {
            local_1 = 0xCEC;
        }
        break;
    case 0x102F:
        if (param_0->unk3C != NULL) {
            func_8010114C(param_0->unk3C, 0x3E, 0);
            param_0->unk3C = NULL;
        }
        local_1 = 0xCEC;
        _susubgame_entrypoint_5(param_0, local_0 + 0x30C, 5, 1, 0);
        break;
    case 0xCEC:
        _susubgame_entrypoint_4(param_0, local_0 + 0x30C);
        param_0->actorData[5] = 0;
        param_0->actorData[4] = 0;
        func_800D2770(0xFC, 0);
        func_800FDC28(0xC);
        func_8009055C(0x85, 1);
        func_80090708(0);
        func_80101FDC(param_0, 2);
        func_800CE8D8(0, 60.0f, 60);
        func_800CE88C(0, 1);
        _gcfrontend_entrypoint_9(0x6A);
        func_800DA544(0x6E5);
        func_800DA524(0);
        func_800BF99C(0, 0x5AA, 0);
        break;
    case 0x1030:
        func_800D1000(0x1F, 1, 0, 1, 0);
        _susubgame_entrypoint_6(param_0, local_0 + 0x30C, 1, 0, 0);
        break;
    case 0x1031:
    case 0x1032:
    case 0x1033:
    case 0x1034:
    case 0x104A:
    case 0x104B:
    case 0x104C:
        local_1 = 0xCEB;
        local_2 = 0x46;
        break;
    case 0xCEB:
        if (func_800D395C()) {
            if (param_2 == 1) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
        } else {
            if (param_2 == 1) {
                local_3 = 0x181;
                local_4 = 1;
            } else {
                local_3 = 0x1A9;
                local_4 = 0x1B;
            }
            func_8009055C(0x85, 0);
            func_80090708(0);
            func_80101FDC(param_0, 4);
            _gcgoto_entrypoint_1(local_3, local_4);
        }
        break;
    }
    if (local_1 != 0) {
        _subaddiedialog_entrypoint_11(param_0->unk0, local_1, local_2, NULL, 0x22);
    }
}

void func_80800EC8_chminisubgame(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    switch (param_0->unk70_10) {
        case 3:
            if (*(s32 *)((u8 *)param_0 + 0x34) >= 0) {
                func_800E3980(local_0);
                param_0->unk54 = func_80102D78(param_0, local_0);
                func_80102BF8(param_0, 0.1f, 4.0f, 180.0f);
            }
            if (!func_800DA298(0)) {
                func_80102424(param_0, 1);
            }
            break;
        case 1:
            if (param_0->unk58 < 5.0f) {
                func_80102424(param_0, 2);
            }
        case 2:
            func_8010D600(local_1);
            param_0->unk54 = func_80102D78(param_0, local_1);
            func_80102BF8(param_0, 0.1f, 4.0f, 180.0f);
            *(f32 *)((u8 *)param_0 + 0x28) +=
                (240.0f + (param_0->unk58 / *(f32 *)((u8 *)param_0 + 0x2C)) * -120.0f) * func_800D8FF8();
            param_0->position[1] = *(f32 *)((u8 *)param_0 + 0x30) +
                func_80013970(*(f32 *)((u8 *)param_0 + 0x28)) * param_0->unk50;
            if (func_800D9078(&param_0->unk58) ||
                func_8010C9B0(param_0->position, (s32)*(f32 *)((u8 *)param_0 + 0x24))) {
                func_80801058_chminisubgame(param_0, 0x3E, 0);
            }
            break;
    }
}

s32 func_80801058_chminisubgame(Actor *param_0, s32 param_1, Actor *param_2)
{
    Actor *local_0;
    Actor *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = NULL;
    switch (param_1) {
    case 0x40:
        local_1 = param_2;
        if (&param_2) {}
        local_2 = _subaddiemulti_entrypoint_5(local_1);
        local_3 = param_0->unk6C_0 + 1;
        if (1) {}
        local_0 = func_80106790(param_0->unk3C);
        local_0->actorData[4] += local_3;
        if ((s32)param_0 == local_3) {} // KUNSTGRIFF empty test: use of param_0 without reload (piece prio > 0, v1) and of local_3 (keeps its prio above local_1)
        _chscorepoints_entrypoint_2(local_3, local_2, param_0->position, 1);
        if ((((((((MS18 *)local_1)->b0 & 1) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) { // KUNSTGRIFF mask chain: burns ugen temps (lhu t9 / andi t1 like the target), as1 removes the redundant ops
            func_8010114C(local_1, 0x98, 0);
        }
    case 0x3E:
        if (local_0 == NULL) {
            local_0 = func_80106790(param_0->unk3C);
        }
        func_8010A570(param_0);
        if (!func_800DA298(0)) {
            if (func_8010CC10(param_0->position, *(s32 *)((u8 *)param_0 + 0x24))) {
                func_8010CCE0();
                for (local_4 = func_8010CCEC(); local_4 != -1; local_4 = func_8010CCEC()) {
                    func_800F7A2C(local_4, 7, param_0->position);
                }
            }
        }
        func_80801248_chminisubgame(param_0);
        if ((s32)param_0->actorData[7] >= 0) {
            func_80800A64_chminisubgame(local_0, param_0->actorData[7]);
        }
        func_800FFAB0(param_0);
        return 1;
    default:
        return 0;
    case 0x29:
    case 0x2A:
        return 1;
    }
}

void func_808011DC_chminisubgame(u8 *param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  if (1)
  {
    local_2 = func_800B53A4(param_2);
    local_0 = local_2;
    func_800BA670(local_2, param_1);
    local_1 = param_0 + 4;
 } func_800BABB8(local_0, local_1, local_1, *((s32 *) (((s8 *) param_0) + 0x38)), &D_808014B4_chminisubgame); func_800BA22C(local_0, param_2);
}

void func_80801248_chminisubgame(param_0) u8 *param_0;
{
  u8 *local_0;
  if ((func_80090270(param_0) == 0) && ((func_800DA298(0) != 0) || (func_800CEAD0(0) == 0)))
  {
    local_0 = param_0 + 4;
    func_800E1610(0, 0x41A00000, 0x3F19999A, param_0 + 4);
    func_800C4AF0(local_0, &D_80801578_chminisubgame);
  }
  local_0 = param_0 + 4;
  func_808011DC_chminisubgame(param_0, (((*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF) * 3) + 0x9A4, 2);
  func_808011DC_chminisubgame(param_0, (((*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF) * 3) + 0x9A5, 6);
  func_808011DC_chminisubgame(param_0, (((*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF) * 3) + 0x9A6, 4);
  func_800BABB8(0, local_0, 0, 0x3F800000, &D_808014F0_chminisubgame);
  func_800BABB8(0, local_0, 0, 0x3F800000 & 0xFFFFFFFF, &D_80801534_chminisubgame);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/minisubgame.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801424_chminisubgame -> int[], D_8080146C_chminisubgame -> int[], D_808014B4_chminisubgame -> s32[] */
extern void func_80102EC0();
extern void func_8010A730();
MinisubgameRecord D_80801400_chminisubgame[3] = { 0x76E, 0xC8, 0x12C, 0x46, 0x46, 0x32, 0x76F, 0xC8, 0x12C, 0x46, 0x46, 0x4B, 0x770, 0xC8, 0x12C, 0x46, 0x46, 0x64 };
int D_80801424_chminisubgame[18] = { 0x15804AD, 0x1, 0x0, (u32)func_808000C8_chminisubgame, (u32)func_80102EC0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x0, (u32)func_80800430_chminisubgame, 0x0, 0x3240000, (u32)func_80800018_chminisubgame, (u32)func_80107C2C, -0x7FFFDBFE, (u32)func_80800484_chminisubgame, 0x0 };
int D_8080146C_chminisubgame[18] = { 0x1C704AE, 0x76E0003, 0x0, (u32)func_80800EC8_chminisubgame, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x104, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, -0x7FE00000, (u32)func_80801058_chminisubgame, 0x0 };
s32 D_808014B4_chminisubgame[15] = { 0x1130016, 0x10000015, 0xCC, 0x2B0133, 0x1990022, 0x1000100, 0x660099, 0xE000A, 0x14002D, 0x4B005DC, 0x1BFF9C, -0xC7FFD9, 0xC800C8, 0x1900190, 0x0 };
u8 D_808014F0_chminisubgame[68] = { 0x7, 0x10, 0x0, 0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x2, 0x0, 0x99, 0x0, 0x16, 0x12, 0x0, 0x0, 0xE, 0x0, 0xDC, 0x0, 0xF0, 0x0, 0x26, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x9C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x0, 0x19, 0x0, 0x1, 0x0, 0x1, 0x0, 0x22, 0x1, 0x33, 0x1, 0x99, 0x3, 0x33, 0x4, 0x0, 0x0, 0x2A, 0x0, 0xA, 0x0, 0xA, 0x0, 0x80, 0x0, 0x8C, 0x0, 0xF, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801534_chminisubgame[68] = { 0x5, 0x10, 0x0, 0x1D, 0x9, 0xD6, 0x0, 0x15, 0x0, 0x2, 0x0, 0x99, 0x0, 0x16, 0x12, 0x0, 0x0, 0xE, 0x0, 0x3C, 0x0, 0x78, 0x0, 0x26, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x9C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x0, 0x19, 0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 0x1, 0x33, 0x1, 0x99, 0x4, 0x0, 0x5, 0x99, 0x0, 0x2A, 0x0, 0x8, 0x0, 0x8, 0x0, 0x66, 0x0, 0x66, 0x0, 0xF, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801578_chminisubgame[24] = { 0x0, 0x13, 0x4, 0x13, 0x0, 0x1B, 0x0, 0x18, 0x0, 0x1, 0x3, 0xE8, 0x17, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
