#include "gc/newpause.h"
#include "gl/dbstring.h"
#include "fx/kern.h"
#include "core2/1E2F380.h"
#include "core2/1E91790.h"
#include "core2/1EAD060.h"
#include "core2/1EC2350.h"
#include "core2/1EABAC0.h"
#include "core2/1ED3900.h"
#include "core1/1E2D890.h"
#include "core2/1E691A0.h"
#include "core2/1E82660.h"
#include "core2/1EA0690.h"
#include "core2/1EA9160.h"
#include "core2/1EAAD80.h"
#include "core2/1EB5E70.h"
#include "core2/1EB45C0.h"
#include "core2/1EBB4F0.h"

#include "gc/level.h"

u32 _gcaudiolist_entrypoint_1(u32 a0, u32 a1);

extern PauseOption D_80802070_gcnewpause[];
extern void *D_808021CC_gcnewpause;
extern void *D_808021E4_gcnewpause;

extern TotalsFlags D_808020A8_gcnewpause[];
extern InventoryDisplay D_808020D8_gcnewpause[];
extern s8 D_80802124_gcnewpause[];
extern s8 D_80802125_gcnewpause;
extern MemorySetupStruct D_80802126_gcnewpause[];
extern s8 D_8080212E_gcnewpause;
extern ItemCountDisplay D_80802130_gcnewpause[];
extern AbilityTracking D_8080215C_gcnewpause[];
extern unk80802190 D_80802190_gcnewpause[6];
extern u8 D_808021B4_gcnewpause[12];
extern void *D_808021C0_gcnewpause;
extern u8 D_8012762D;
extern s8 D_80802072_gcnewpause;

PauseState *gcnewpause_entrypoint_0(u32 arg0)
{
    u8 dummy[0x8];
    PauseState *pauseMemory;
    s8 *var_0;
    u32 index;
    pauseMemory = heap_alloc(_gcnewoption_entrypoint_2() + 0x30);
    bzero(pauseMemory, 0x30);
    pauseMemory->unkC = arg0;
    func_80800534_gcnewpause(pauseMemory, 1U);
    pauseMemory->HeaderAndButtonOffset += *D_80802124_gcnewpause;
    pauseMemory->HeaderAndButtonOffset += D_80802125_gcnewpause;
    index = 0;
    do {
        pauseMemory->HeaderAndButtonOffset += D_80802126_gcnewpause[index].a1;
        pauseMemory->HeaderAndButtonOffset += D_80802126_gcnewpause[index].a2;
        pauseMemory->HeaderAndButtonOffset += D_80802126_gcnewpause[index].a3;
        pauseMemory->HeaderAndButtonOffset += D_80802126_gcnewpause[index].a4;
        index++;
        var_0 = &D_80802126_gcnewpause[index].a1;
    } while (&D_8080212E_gcnewpause != var_0);

    return pauseMemory;
}

void gcnewpause_entrypoint_1(PauseState *a0)
{
    func_80800534_gcnewpause(a0, 0x4);
    heap_free(a0);
}

#ifndef NON_MATCHING

u32 gcnewpause_entrypoint_2(PauseState *param_0)
{
    s32 local_3;
    s32 local_4;
    char *local_5;
    f32 local_0;
    local_5 = (char *) param_0;
    func_800D2574();
    func_800C0438();
    func_800E8A68();
    switch (*(u8 *) local_5) {
        case 1:
            func_80800534_gcnewpause(param_0, 2);
            break;

        case 2:
            if (func_80015FA0(*(u8 *) (local_5 + 0xC)) == 1) {
                if (_gcnewoption_entrypoint_37((OptionState *) (local_5 + 0x30), 1)) {
                    *(u8 *) (local_5 + 3) = 0;
                }
            }
            if (*(u8 *) (local_5 + 0xE) != 0) {
                if (func_800D9078(local_5 + 8)) {
                    func_80801E08_gcnewpause(param_0, local_5 + 0x30);
                }
            }
            func_80800E10_gcnewpause(param_0, *(s8 *) (local_5 + 3));
            _gcnewoption_entrypoint_0((OptionState *) (local_5 + 0x30));
            break;

        case 3:
            func_80016068(*(u8 *) (local_5 + 0xC), &local_0);
            func_800D9078(local_5 + 8);
            if (*(u8 *) (local_5 + 0xF) != 0) {
                if (--*(u8 *) (local_5 + 0xF) == 0) {
                    _gcaudiolist_entrypoint_1(2, 0x4650);
                }
            }
            if ((*(s8 *) (local_5 + 7) == 0) && (*(s8 *) (local_5 + 3) == 1)) {
                if (func_80015FA0(*(u8 *) (local_5 + 0xC)) == 1) {
                    func_808015F8_gcnewpause(param_0, 1);
                } else if (func_80016B30(*(u8 *) (local_5 + 0xC), 1) == 1) {
                    func_808015F8_gcnewpause(param_0, 0);
                } else if (((*(u8 *) (local_5 + 0x1E) != 0) && (local_0 < -0.75f)) &&
                           (*(f32 *) (local_5 + 8) == 0.0f)) {
                    func_8080162C_gcnewpause(param_0, -1);
                } else if (((*(u8 *) (local_5 + 0x1F) != 0) && (0.75f < local_0)) &&
                           (*(f32 *) (local_5 + 8) == 0.0f)) {
                    func_8080162C_gcnewpause(param_0, 1);
                }
            }
            local_3 = func_80801330_gcnewpause(
                param_0, *(u8 *) (local_5 + 1),
                ((*(s8 *) (local_5 + 7) == 0) && (*(s8 *) (local_5 + 3) == -1))
                    ? 1
                    : *(s8 *) (local_5 + 3));
            func_80801580_gcnewpause(param_0);
            local_4 =
                func_80800F2C_gcnewpause(param_0, *(u8 *) (local_5 + 1), *(s8 *) (local_5 + 3));
            if (((*(s8 *) (local_5 + 7) == 0) && (*(s8 *) (local_5 + 3) == -1)) && (local_4 == 0)) {
                *(u8 *) (local_5 + 0x1F) = (*(u8 *) (local_5 + 3) = 0);
                *(u8 *) (local_5 + 0x1E) = 0;
                local_4 = 1;
                _gcaudiolist_entrypoint_1(5, 0x4650);
            }
            if ((local_4 != 0) || (local_3 != 0)) {
                break;
            }
            if (*(s8 *) (local_5 + 7) != 0) {
                local_4 = func_80801718_gcnewpause(*(u8 *) (local_5 + 1), *(s8 *) (local_5 + 7));
                func_808017C8_gcnewpause(param_0, local_4);
                *(u8 *) (local_5 + 7) = 0;
                *(u8 *) (local_5 + 3) = 1;
                *(f32 *) (local_5 + 8) = 0.2f;
                _gcaudiolist_entrypoint_1(2, 0x4650);
            } else {
                if (*(u8 *) (local_5 + 4) != 0) {
                    *(u8 *) (local_5 + 2) = 1;
                    break;
                }
                func_80800534_gcnewpause(param_0, 2);
            }

        case 4:
            break;

        case 5:
            func_80801CDC_gcnewpause(param_0);
            if (func_800D9078(local_5 + 8)) {
                *(s16 *) (local_5 + 0x2C) = 0;
                func_800FCAE0(0x12, 0, 0xC8);
                func_800FCA90(0x12);
                func_800A7AD4(1, 0);
                *(u8 *) (local_5 + 2) = 2;
                _gcfrontend_entrypoint_13();
            }
            break;

        default:
            if (func_80015FA0(*(u8 *) (local_5 + 0xC)) == 1) {
                *(u8 *) (local_5 + 2) = 1;
            }
    }

    return *(u8 *) (local_5 + 2) == 1;
}

#else
u32 gcnewpause_entrypoint_2(0)
{
#endif
    void gcnewpause_entrypoint_3(u32 arg0, PauseState * pauseMenu)
    {
        u8 temp_v0;

        temp_v0 = pauseMenu->PageIndex;
        switch (temp_v0) {
            case 2:
                _gcnewoption_entrypoint_1(&pauseMenu->optionState, arg0);
                break;
            case 5:
                func_80801DA0_gcnewpause(pauseMenu, arg0);
        }
        func_80801410_gcnewpause(pauseMenu, (s32) arg0);
        func_808012CC_gcnewpause(pauseMenu, (u32 *) arg0);
    }

    void func_80800534_gcnewpause(PauseState * pauseMenu, u32 targetPage)
    {
        if (targetPage != pauseMenu->PageIndex) {
            switch (pauseMenu->PageIndex) {
                case 2:
                    func_80800E10_gcnewpause(pauseMenu, 0U);
                    _gcnewoption_entrypoint_7(&pauseMenu->optionState);
                    break;
                case 3:
                    _gldbstring_entrypoint_2(0x1864U);
                    pauseMenu->textPointer = NULL;
                    func_8080152C_gcnewpause(pauseMenu);
            }
            switch (targetPage) {
                case 1:
                    func_800FC348(0, 0x7D0, 2);
                    func_800FEC60(1);
                    func_800FC124(0x24);
                    func_80800DE0_gcnewpause(1.1f);
                    func_800C06C4();
                    func_80018634();
                    if (func_800D395C() != 0) {
                        pauseMenu->ActivePauseMenuVariant = 4;
                    } else if (func_800D3948() != 0) {
                        if (func_800A946C() == 1) {
                            pauseMenu->ActivePauseMenuVariant = 5;
                        } else {
                            pauseMenu->ActivePauseMenuVariant = 6;
                        }
                    } else {
                        pauseMenu->ActivePauseMenuVariant = 0;
                        if (func_80801EF0_gcnewpause((s32) pauseMenu) != 0) {
                            pauseMenu->ActivePauseMenuVariant += 1;
                        }
                        if (func_80801F18_gcnewpause((u32) pauseMenu) != 0) {
                            pauseMenu->ActivePauseMenuVariant += 2;
                        }
                    }
                    break;
                case 2:
                    func_80800A08_gcnewpause(pauseMenu);
                    pauseMenu->unk3 =
                        *(&D_80802072_gcnewpause + (pauseMenu->ActivePauseMenuVariant * 8));
                    break;
                case 3:
                    pauseMenu->unk3 = 1;
                    pauseMenu->CanExitPage = 0;
                    pauseMenu->Timer = 0.2f;
                    func_80801660_gcnewpause(pauseMenu);
                    func_8080136C_gcnewpause(pauseMenu);
                    _gcaudiolist_entrypoint_1(4U, 0x4650U);
                    pauseMenu->SoundEffectTimerPageOpen = 0xB;
                    break;
                case 4:
                    func_800FECB8(1);
                    switch (pauseMenu->ExitType) {
                        case 1:
                            func_800C0710();
                            func_80800DE0_gcnewpause(0.9f);
                            func_800FC348(-1, 0x7D0, 2);
                            func_800FC1A8();
                            break;
                        case 2:
                        case 3:
                        case 4:
                            func_800FC348(-1, 0x7D0, 2);
                            func_800FC1A8();
                            func_800FE4E4();
                    }
                    break;
                case 5:
                    pauseMenu->Timer = 5.0f;
                    func_800FCAE0(0x24, 0, 0x7D0);
                    func_800FCA90(0x24);
                    func_800FC660(0x12);
                    func_80801CCC_gcnewpause(pauseMenu);
            }
            pauseMenu->PageIndex = (u8) targetPage;
        }
    }
    void gcnewpause_entrypoint_4(u32 arg0, OptionState * arg1, u32 arg2, u32 arg3)
    {
        PauseState *pauseMenu;

        pauseMenu = (PauseState *) ((u8 *) arg1 - 0x30);
        switch (arg3) {
            case 0:
                func_80800C54_gcnewpause(pauseMenu, arg1);
                break;

            case 3:
                func_80800CE4_gcnewpause(pauseMenu, arg1, arg2);
                break;

            case 4:
                if ((D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant]
                         .options[arg2]
                         .AreYouSure == 0) ||
                    (pauseMenu->unkE != 0)) {
                    if (_gcnewoption_entrypoint_37(arg1, 0)) {
                        if (pauseMenu->unkE == pauseMenu->unk11) {
                            _gcaudiolist_entrypoint_0(6);
                        }

                        pauseMenu->unk3 = 0;
                        pauseMenu->unkE = 0;
                    }
                } else if (_gcnewoption_entrypoint_38(arg1, 0) != 0) {
                    if (D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant]
                            .options[arg2]
                            .Function == 2) {
                        func_800FC6B0(0xE);
                        func_800D389C();
                    }
                    pauseMenu->LastOptionSelected = arg2;
                    pauseMenu->unkE = 7;
                    func_80801E08_gcnewpause(pauseMenu, &pauseMenu->optionState);
                }
                break;

            case 5:
                if ((pauseMenu->unkE == 0)) {
                    if ((_gcnewoption_entrypoint_37(arg1, 1) != 0)) {
                        pauseMenu->unk3 = 0;
                    }
                } else {
                    if (_gcnewoption_entrypoint_39(arg1) != 0) {
                        if (pauseMenu->unkE == (u8) pauseMenu->unk11) {
                            _gcaudiolist_entrypoint_0(7);
                        }
                        pauseMenu->unkE = 0;
                        _gcnewoption_entrypoint_12(
                            arg1, arg2,
                            D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant]
                                .options[arg2]
                                .Text);
                    }
                }
                break;

            case 2:
                pauseMenu->ExitType = 1;
        }
    }

    void func_80800A08_gcnewpause(PauseState * pauseMenu)
    {
        s32 i;
        s32 optionSize;
        s32 menuVariant;
        Option *options;

        bzero(&pauseMenu->optionState, _gcnewoption_entrypoint_2());
        _gcnewoption_entrypoint_5(&pauseMenu->optionState, _gcnewpause_entrypoint_4, 0U,
                                  D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant].unk1, 0);
        _gcnewoption_entrypoint_10(&pauseMenu->optionState, 2U);
        optionSize = D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant].Size;
        options = D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant].options;
        _gcnewoption_entrypoint_8(&pauseMenu->optionState, optionSize);
        _gcnewoption_entrypoint_9(&pauseMenu->optionState, optionSize);
        _gcnewoption_entrypoint_46(&pauseMenu->optionState, pauseMenu->unkC);

        for (i = 0; i < optionSize; i++) {
            if (!pauseMenu->ActivePauseMenuVariant && !pauseMenu->ActivePauseMenuVariant) {
            }
            _gcnewoption_entrypoint_31(&pauseMenu->optionState, i, options[i].Icon);
        }
        _gcnewoption_entrypoint_36(&pauseMenu->optionState);
        menuVariant = pauseMenu->ActivePauseMenuVariant;

        if ((menuVariant != 5) && (menuVariant == 6)) {
            unk80802190 sp5C[6] = D_80802190_gcnewpause;
            u8 sp50[12] = D_808021B4_gcnewpause;
            s32 s1;
            s32 a0;

            a0 = _gcstatusDll_entrypoint_11();
            a0 = sp50[pauseMenu->unkC * 3 + a0 - 2];
            i = sp5C[a0].unk0;
            s1 = sp5C[a0].unk2;

            if (sp5C[a0].unk4 != 0) {
                _gcnewoption_entrypoint_49(&pauseMenu->optionState, 1U);
            }

            _gcnewoption_entrypoint_40(&pauseMenu->optionState, i, s1, 0x14U, 0.6f, 0.6f);
            pauseMenu->ConfirmTextStart = 5;
            pauseMenu->unk11 = 5;
            pauseMenu->ConfirmTextEnd = 8;
        } else {
            _gcnewoption_entrypoint_40(&pauseMenu->optionState, 0x3C, 0x25, 0x1AU, 0.65f, 0.99f);
            pauseMenu->ConfirmTextStart = 5;
            pauseMenu->unk11 = 6;
            pauseMenu->ConfirmTextEnd = 7;
        }
        _gcnewoption_entrypoint_42(&pauseMenu->optionState, 0.1f);
        _gcnewoption_entrypoint_11(&pauseMenu->optionState);
    }

    void func_80800C54_gcnewpause(PauseState * arg0, OptionState * arg1)
    {
        s32 index;
        Option *options;
        s32 size;
        size = D_80802070_gcnewpause[arg0->ActivePauseMenuVariant].Size;
        options = D_80802070_gcnewpause[arg0->ActivePauseMenuVariant].options;
        index = 0;
        for (index; index < size; index++) {
            _gcnewoption_entrypoint_12(arg1, index, options[index].Text);
        }
        _gcnewoption_entrypoint_41(arg1, arg0->LastOptionSelected);
    }

    void func_80800CE4_gcnewpause(PauseState * pauseMenu, OptionState * arg1, s32 selectedOption)
    {
        Option *new_var;
        new_var = D_80802070_gcnewpause[pauseMenu->ActivePauseMenuVariant].options;
        switch (new_var[selectedOption].Function) {
            case 0:
                pauseMenu->ExitType = 1;
                break;

            case 1:
                func_808017C8_gcnewpause(pauseMenu, (new_var[selectedOption].SubOption < 0xE)
                                                        ? new_var[selectedOption].SubOption
                                                        : func_808011BC_gcnewpause());
                func_80800534_gcnewpause(pauseMenu, 3U);
                break;

            case 2:
                func_80800534_gcnewpause(pauseMenu, 5U);
                break;

            case 3:
                pauseMenu->ExitType = 3;
                _gcfrontend_entrypoint_11();
                break;

            case 4:
                pauseMenu->ExitType = 4;
                _gcfrontend_entrypoint_12();
        }

        pauseMenu->LastOptionSelected = (u8) selectedOption;
    }

    void func_80800DE0_gcnewpause(f32 a0)
    {
        func_800C4B64(a0);
        func_800C4AF0(NULL, &D_808021C0_gcnewpause);
    }

    void func_80800E10_gcnewpause(PauseState * pauseMenu, u32 a1)
    {
        func_8080105C_gcnewpause(0xC, 0x7, a1, 0x0);
        func_8008FBE0(a1);
        func_800CF7F4(a1);
        if (a1 != 0) {
            func_800D2498(0xD6, func_800D035C(0x1), 0);
            func_800D2498(0xD0, func_800D035C(0x6), 0);
        } else {
            func_800D284C(0xD6);
            func_800D284C(0xD0);
        }
    }

    s32 func_80800EA8_gcnewpause(PauseState * arg0, u32 arg1)
    {
        s32 sp24;
        s32 sp20;
        s32 temp_v0;
        sp24 = func_8080105C_gcnewpause(0U, 0xCU, arg1, 1U);
        temp_v0 = func_800D1A04(0x54);
        sp20 = temp_v0;
        if ((temp_v0 != 0) &&
            (func_8080190C_gcnewpause((u32) sp20, 0x2F, func_800D27A4(func_800D1C5C(0x54)), 5U,
                                      arg1) != 0)) {
            sp24 = 1;
        }
        return sp24;
    }

    s32 func_80800F2C_gcnewpause(PauseState * arg1, u32 arg2, u32 arg3)
    {
        switch (arg2) {
            case 0:
                return func_80800EA8_gcnewpause(arg1, arg3);

            case 1:
                return func_80800FA8_gcnewpause(arg3);
            case 2:
                return func_80801AF8_gcnewpause(arg3);
            default:
                return func_808019A4_gcnewpause(func_808016A4_gcnewpause(arg2), arg3);
        }
    }

    s32 func_80800FA8_gcnewpause(u32 arg0)
    {
        s32 temp_s2;
        s32 var_s3 = 0;
        u32 temp_v0;
        u32 index;

        for (index = 0; index != 9; index++) {
            if (1)
                temp_v0 = func_800D1338(index);
            if (temp_v0 != 0) {
                temp_s2 = func_800D27A4(index + 0xE1);
                if (func_80801844_gcnewpause(temp_v0, func_800D129C(index), index + 0x11, temp_s2,
                                             1, arg0) != 0) {
                    var_s3 = 1;
                }
            }
        }
        return var_s3;
    }

    s32 func_8080105C_gcnewpause(s32 a0, s32 a1, u32 a2, u32 a3)
    {
        s32 temp_s0;
        s32 temp_v0_2;
        u32 temp_v0_3;
        u32 new_var;
        s32 index;
        u8 temp_s3;
        u32 ret;
        ret = 0;

        for (index = a0; index < (a0 + a1); index++) {
            if ((D_808020D8_gcnewpause[index].AbilityID != 0x3C) &&
                (func_800C6E38(D_808020D8_gcnewpause[index].AbilityID) == 0)) {
                continue;
            }
            new_var = func_800D1A04(D_808020D8_gcnewpause[index].ItemID);
            if (a3 != 0) {
                if (new_var == 0) {
                    continue;
                }
            }
            temp_s3 = D_808020D8_gcnewpause[index].uiPosition;
            temp_v0_2 = func_800D1C5C(D_808020D8_gcnewpause[index].ItemID);
            temp_s0 = func_800D27A4(temp_v0_2);
            temp_v0_3 = func_800D28E8(temp_v0_2);
            if (temp_v0_3 == 1) {
                if (func_80801844_gcnewpause(new_var,
                                             func_800D1A6C(D_808020D8_gcnewpause[index].ItemID),
                                             temp_s3, temp_s0, 1, a2) != 0) {
                    ret = 1;
                }
            } else if (func_8080190C_gcnewpause(new_var, temp_s3, temp_s0, temp_v0_3, a2) != 0) {
                ret = 1;
            }
        }

        return ret;
    }

    u32 func_808011BC_gcnewpause(void)
    {
        s32 temp_v0;
        s32 var_a0;
        u32 var_a1;

        temp_v0 = func_800EA05C();
        if ((temp_v0 == MAP_D0_CHUFFYS_CAB) || (temp_v0 == MAP_121_INSIDE_CHUFFY_WAGON)) {
            var_a1 = _chchuffycont_entrypoint_3();
        } else {
            var_a1 = D_8012762D;
        }
        var_a0 = 0;
        while (D_808020A8_gcnewpause[var_a0].unk1 != 0) {
            if (var_a1 == D_808020A8_gcnewpause[var_a0].unk1) {
                break;
            }
            var_a0++;
        }
        return D_808020A8_gcnewpause[var_a0].SubPage;
    }

    u8 func_80801248_gcnewpause(s16 * a0, u8 * a1, u32 a2)
    {
        u8 temp_t1;
        u8 var_v1;

        var_v1 = 1;
        if (a2 == 1) {
            if (*a1 < 0xAU) {
                *a0 += D_80802124_gcnewpause[*a1];
                *a1 += 1;
            }
        } else if (*a1 > 0) {
            temp_t1 = *a1 - 1;
            *a1 = temp_t1;
            *a0 -= D_80802124_gcnewpause[temp_t1 & 0xFF];
        } else {
            var_v1 = 0;
        }
        return var_v1;
    }
    void func_808012CC_gcnewpause(PauseState * pauseMenu, u32 * a1)
    {
        if (pauseMenu->DrawPageHeader != 0) {
            _fxkern_entrypoint_2();
            func_800B8CE0(0xC28);
            _fxkern_entrypoint_1(
                a1, pauseMenu->pageTitleOffset + 0x20,
                _gldbstring_entrypoint_1((u32 *) pauseMenu->textPointer, pauseMenu->SubPage));
        }
    }

    u8 func_80801330_gcnewpause(PauseState * pauseMenu, u32 a1, u32 a2)
    {
        pauseMenu->DrawPageHeader = func_80801248_gcnewpause(&pauseMenu->pageTitleOffset,
                                                             &pauseMenu->MovePageHeaderTrigger, a2);
        return pauseMenu->DrawPageHeader;
    }

    void func_8080136C_gcnewpause(PauseState * pauseMenu)
    {
        s16 temp_t7;
        u8 temp_v0;
        u8 temp_v0_2;

        temp_v0 = func_800E8B74(0xB59);
        pauseMenu->ShowBButton = temp_v0;
        func_800E8D28(temp_v0, 0.6f);
        func_800E8D5C(pauseMenu->ShowBButton, &D_808021CC_gcnewpause, 3);
        temp_v0_2 = func_800E8B74(0xB57);
        pauseMenu->JoystickIndicator = temp_v0_2;
        func_800E8D28(temp_v0_2, 0.8f);
        func_800E8D5C(pauseMenu->JoystickIndicator, &D_808021E4_gcnewpause, 3);
        pauseMenu->MoveRightJoystickTrigger = 0;
        pauseMenu->MoveLeftJoystickTrigger = 0;
        temp_t7 = -pauseMenu->HeaderAndButtonOffset;
        pauseMenu->RightJoystickPos = temp_t7;
        pauseMenu->LeftJoystickPos = temp_t7;
        pauseMenu->B_Button_Pos = temp_t7;
        pauseMenu->MoveBButtonTrigger = 0;
    }

    void func_80801410_gcnewpause(PauseState * pauseMenu, s32 arg1)
    {
        Coords2D sp30;
        ImageStruct *imageData;
        s32 sp28;
        s32 pad;

        if (pauseMenu->ShowBButton != 0) {
            sp30.x = 0x260;
            sp30.y = (-pauseMenu->B_Button_Pos * 4) + 0x340;
            imageData = func_800D674C(0xB59);

            sp28 = func_800E8C58(pauseMenu->ShowBButton);
            func_800E30E0(arg1, imageData, sp28, &sp30);
        }

        if (pauseMenu->JoystickIndicator != 0) {
            imageData = func_800D674C(0xB57);
            sp28 = func_800E8C58(pauseMenu->JoystickIndicator);

            sp30.x = 0x78;
            sp30.y = (-pauseMenu->LeftJoystickPos * 4) + 0x340;
            func_800E2568(imageData->unk8 * -4, imageData->unkA * 4);
            func_800E30E0(arg1, imageData, sp28, &sp30);

            sp30.x = 0x448;
            sp30.y = (-pauseMenu->RightJoystickPos * 4) + 0x340;
            func_800E30E0(arg1, imageData, sp28, &sp30);
        }
    }

    void func_8080152C_gcnewpause(PauseState * pauseMenu)
    {
        if (pauseMenu->ShowBButton != 0) {
            func_800E8C08(pauseMenu->ShowBButton);
            pauseMenu->ShowBButton = 0;
        }
        if (pauseMenu->JoystickIndicator != 0) {
            func_800E8C08(pauseMenu->JoystickIndicator);
            pauseMenu->JoystickIndicator = 0;
        }
    }

    void func_80801580_gcnewpause(PauseState * pauseMenu)
    {
        s32 a2;
        if (pauseMenu->unk3 != 0 || pauseMenu->CanExitPage != 0) {
            a2 = 1;
        } else {
            a2 = 0;
        }
        func_80801248_gcnewpause(&pauseMenu->B_Button_Pos, &pauseMenu->MoveBButtonTrigger, a2);
        func_80801248_gcnewpause(&pauseMenu->LeftJoystickPos, &pauseMenu->MoveLeftJoystickTrigger,
                                 pauseMenu->CanMoveLeft);
        func_80801248_gcnewpause(&pauseMenu->RightJoystickPos, &pauseMenu->MoveRightJoystickTrigger,
                                 pauseMenu->CanMoveRight);
    }

    void func_808015F8_gcnewpause(PauseState * pauseMenu, u32 a1)
    {
        pauseMenu->unk4 = a1;
        pauseMenu->unk3 = -1;
        pauseMenu->SoundEffectTimerPageOpen = 0x0;
        _gcaudiolist_entrypoint_1(0x3, 0x4650);
    }

    void func_8080162C_gcnewpause(PauseState * pauseMenu, u32 a1)
    {
        pauseMenu->CanExitPage = a1;
        pauseMenu->unk3 = -1;
        pauseMenu->SoundEffectTimerPageOpen = 0x0;
        _gcaudiolist_entrypoint_1(0x3, 0x4650);
    }

    void func_80801660_gcnewpause(PauseState * pauseMenu)
    {
        pauseMenu->textPointer = _gldbstring_entrypoint_0(pauseMenu->textPointer, 0x1864);
        pauseMenu->pageTitleOffset = -pauseMenu->HeaderAndButtonOffset;
        pauseMenu->MovePageHeaderTrigger = 0;
    }

    s32 func_808016A4_gcnewpause(s32 a0)
    {
        u32 index;
        for (index = 0; D_808020A8_gcnewpause[index].unk1 != 0; index++) {
            if (D_808020A8_gcnewpause[index].SubPage == a0) {
                break;
            }
        }
        return D_808020A8_gcnewpause[index].unk1;
    }
    s32 func_808016F0_gcnewpause(s32 a0)
    {
        return _gclevel_entrypoint_3(func_808016A4_gcnewpause(a0));
    }
    s32 func_80801718_gcnewpause(s32 subPage, s32 movementDirection)
    {
        s32 temp_v0;
        s32 var_s0;

        temp_v0 = subPage + movementDirection;
        var_s0 = temp_v0;

        if (movementDirection < 0) {
            for (var_s0; var_s0 >= 3; var_s0--) {
                if (func_808016F0_gcnewpause(var_s0) != 0) {
                    break;
                }
            }
            if (var_s0 < 2) {
                var_s0 = subPage;
            }
        } else if (movementDirection > 0) {
            for (var_s0; var_s0 < 0xE; var_s0++) {
                if (func_808016F0_gcnewpause(var_s0) != 0) {
                    break;
                }
            }
            if (var_s0 == 0xE) {
                var_s0 = subPage;
            }
        }
        return var_s0;
    }

    void func_808017C8_gcnewpause(PauseState * pauseMenu, u32 subPageTarget)
    {
        pauseMenu->SubPage = subPageTarget & 0xff;
        if ((pauseMenu->SubPage == 0) || (pauseMenu->SubPage == 1)) {
            pauseMenu->CanMoveRight = 0;
            pauseMenu->CanMoveLeft = 0;
        } else {
            pauseMenu->CanMoveLeft =
                (func_80801718_gcnewpause(pauseMenu->SubPage, -1) != pauseMenu->SubPage);
            pauseMenu->CanMoveRight =
                (func_80801718_gcnewpause(pauseMenu->SubPage, 1) != pauseMenu->SubPage);
        }
    }

    s32 func_80801844_gcnewpause(u32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5)
    {
        if (arg5 == 1) {
            if (arg1 != 0) {
                func_800FA9B4(arg2);
                func_800FA708(arg0, (s32) arg2, (s32) arg3, (u32) arg4);
                return 1;
            }
            func_800FAAB4((s32) arg2, (s32) arg3);
            return 1;
        }
        if (arg5 == -1U) {
            func_800FAAB4((s32) arg2, (s32) arg3);
            return func_800FA934((s32) arg2, (s32) arg3) == 0;
        }
        func_800FA818((s32) arg2, (s32) arg3);
        return func_800FA8E8((s32) arg2, (s32) arg3) == 1;
    }

    s32 func_8080190C_gcnewpause(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4)
    {
        if (arg4 == 1) {
            func_800FA708(arg0, arg1, arg2, arg3);
            return 1;
        }
        if (arg4 == -1) {
            func_800FAAB4((s32) arg1, (s32) arg2);
            return func_800FA934((s32) arg1, (s32) arg2) == 0;
        }
        func_800FA818((s32) arg1, (s32) arg2);
        return func_800FA8E8((s32) arg1, (s32) arg2) == 1;
    }

    s32 func_808019A4_gcnewpause(u32 arg0, u32 arg1)
    {
        u32 temp_s1;
        u32 temp_v0;
        u32 var_s5;
        u32 temp_a1;
        u32 index = 0;

        var_s5 = 0;
        while (D_80802130_gcnewpause[index].itemType != -1) {
            temp_s1 = func_800D0018(D_80802130_gcnewpause[index].itemType, arg0);
            temp_a1 = func_800CFC8C(D_80802130_gcnewpause[index].itemType, arg0);
            if (((arg1 != 1) || (temp_s1 != 0)) &&
                (func_80801844_gcnewpause(temp_s1, temp_a1, D_80802130_gcnewpause[index].uiPosition,
                                          D_80802130_gcnewpause[index].itemIcon, 6, arg1) != 0)) {
                var_s5 = 1;
            }
            index++;
        }
        if (func_8080190C_gcnewpause(func_800DADEC(arg0), 0x22, 0x1B, 4, arg1) != 0) {
            var_s5 = 1;
        }
        temp_v0 = func_80801C3C_gcnewpause(arg0);
        temp_s1 = temp_v0;
        if (((arg1 != 1) || (temp_s1 != 0)) &&
            (func_80801844_gcnewpause(temp_s1, func_80801BF0_gcnewpause((u32) arg0), 0x21, 0x1E, 6,
                                      arg1) != 0)) {
            var_s5 = 1;
        }
        return var_s5;
    }

    s32 func_80801AF8_gcnewpause(u32 arg0)
    {
        s32 temp_v0_2;
        s32 var_s3;
        u32 temp_v0;
        u32 index = 0;

        var_s3 = 0;
        while (D_80802130_gcnewpause[index].itemType != -1) {
            temp_v0 = func_800D035C(D_80802130_gcnewpause[index].itemType);

            if (temp_v0 != 0 && (func_8080190C_gcnewpause(
                                     temp_v0, D_80802130_gcnewpause[index].uiPosition,
                                     D_80802130_gcnewpause[index].itemIcon, 5U, (s32) arg0) != 0)) {
                var_s3 = 1;
            }
            index++;
        }
        if (func_8080190C_gcnewpause(func_800DAD10(), 0x22, 0x1B, 4U, (s32) arg0) != 0) {
            var_s3 = 1;
        }
        temp_v0_2 = func_80801C3C_gcnewpause(0);
        if ((temp_v0_2 != 0) &&
            (func_8080190C_gcnewpause((u32) temp_v0_2, 0x21, 0x1E, 5U, (s32) arg0) != 0)) {
            var_s3 = 1;
        }
        return var_s3;
    }

    u32 func_80801BF0_gcnewpause(u32 a0)
    {
        u32 MoveCount = 0;
        u32 index = 0;
        while (D_8080215C_gcnewpause[index].SubPageToShow != -1) {
            if (a0 == 0x0 || D_8080215C_gcnewpause[index].SubPageToShow == a0) {
                MoveCount++;
            }
            index++;
        }
        return MoveCount;
    }

    s32 func_80801C3C_gcnewpause(s32 a0)
    {
        s32 MoveCount = 0;
        u32 index = 0;
        while (D_8080215C_gcnewpause[index].SubPageToShow != -1) {
            if (a0 == 0x0 || D_8080215C_gcnewpause[index].SubPageToShow == a0) {
                if (func_800C6E38(D_8080215C_gcnewpause[index].AbilityId)) {
                    MoveCount++;
                }
            }
            index++;
        }
        return MoveCount;
    }

    void func_80801CCC_gcnewpause(PauseState * pauseMenu)
    {
        pauseMenu->GameOverTransparency = 0;
        pauseMenu->GameOverFadingIn = 0x1;
    }

    void func_80801CDC_gcnewpause(PauseState * pauseMenu)
    {
        f32 speed = func_800D8FF8();
        s16 temp_v0;
        if (pauseMenu->GameOverFadingIn != 0) {
            temp_v0 = pauseMenu->GameOverTransparency;
            if (temp_v0 < 0xFF) {
                pauseMenu->GameOverTransparency = temp_v0 + (speed * 200.0f);
            }
            temp_v0 = pauseMenu->GameOverTransparency;
            if (temp_v0 >= 0x100) {
                pauseMenu->GameOverTransparency = 0xFF;
            }
        } else {
            temp_v0 = pauseMenu->GameOverTransparency;
            if (temp_v0 > 0) {
                pauseMenu->GameOverTransparency = temp_v0 - (speed * 200.0f);
            }
            temp_v0 = pauseMenu->GameOverTransparency;
            if (temp_v0 < 0) {
                pauseMenu->GameOverTransparency = 0;
            }
        }
    }

    void func_80801DA0_gcnewpause(PauseState * pauseMenu, u32 a1)
    {
        f32 coord[2];
        coord[0] = 152.0f;
        coord[1] = 171.0f;

        func_800DF410(pauseMenu->GameOverTransparency);
        func_800DF944(a1, coord, 0.0f, 0.25f, 0, 1, func_800D674C(0x640));
    }

    void func_80801E08_gcnewpause(PauseState * pauseMenu, OptionState * a1)
    {
        pauseMenu->unkE = pauseMenu->unkE + 1;

        if (pauseMenu->unkE >= pauseMenu->ConfirmTextEnd) {
            pauseMenu->unkE = pauseMenu->ConfirmTextStart;
        }

        _gcnewoption_entrypoint_12(a1, pauseMenu->LastOptionSelected, pauseMenu->unkE);
        pauseMenu->Timer = 1.5f;
    }

    s32 func_80801E80_gcnewpause(s32 a0, s32 a1)
    {
        s32 s0 = 0;
        for (s0 = a0; s0 < a0 + a1; s0++) {
            if (func_800D1A04(D_808020D8_gcnewpause[s0].ItemID) != 0) {
                return 0x1;
            }
        }
        return 0x0;
    }

    s32 func_80801EF0_gcnewpause(s32 a0)
    {
        return func_80801E80_gcnewpause(0, 0xC);
    }

    u32 func_80801F18_gcnewpause(u32 a0)
    {
        u32 s0;
        for (s0 = 0; s0 < 9; s0++) {
            if (func_800D1338(s0) != 0) {
                return 0x1;
            }
        }
        return 0x0;
    }

    u32 D_80801FE0_gcnewpause[8] = {0xC0000,   0x0,       0x1010000, 0x130201,
                                    0x1000001, 0x3010E00, 0x9E0402,  0x10000};
    u32 D_80802000_gcnewpause[6] = {0xC0000, 0x0, 0x1010000, 0x10301, 0xE00009E, 0x4020001};
    u32 D_80802018_gcnewpause[6] = {0xC0000, 0x13, 0x2010100, 0x10301, 0xE00009E, 0x4020001};
    u32 D_80802030_gcnewpause[5] = {0xC0000, 0x1, 0x3010E00, 0x9E0402, 0x10000};
    u32 D_80802044_gcnewpause[5] = {0xC0000, 0x10, 0x1030001, 0xD0204, 0x10000};
    u32 D_80802058_gcnewpause[3] = {0xC0000, 0xD, 0x1040001};
    u32 D_80802064_gcnewpause[3] = {0xC0000, 0xD, 0x1040001};
    PauseOption D_80802070_gcnewpause[7] = {0x1863, 0x1, 0x3, (void *) &D_80802030_gcnewpause,
                                            0x1863, 0x1, 0x4, (void *) &D_80802000_gcnewpause,
                                            0x1863, 0x1, 0x4, (void *) &D_80802018_gcnewpause,
                                            0x1863, 0x1, 0x5, (void *) &D_80801FE0_gcnewpause,
                                            0x1867, 0x1, 0x3, (void *) &D_80802044_gcnewpause,
                                            0x1868, 0x0, 0x2, (void *) &D_80802058_gcnewpause,
                                            0x186E, 0x0, 0x2, (void *) &D_80802064_gcnewpause};
    TotalsFlags D_808020A8_gcnewpause[12] = {0x10, 0x5, 0xF,  0x6, 0x12, 0x7, 0x14, 0x8,
                                             0x15, 0x9, 0x16, 0xA, 0x17, 0xB, 0x18, 0xC,
                                             0x19, 0xD, 0x1A, 0x4, 0x13, 0x3, 0x0,  0x2};
    InventoryDisplay D_808020D8_gcnewpause[19] = {
        0x49, 0x11, 0x3C, 0x4A, 0x12, 0x3C, 0x48, 0x13, 0x3C, 0x4F, 0x14, 0x3C, 0x4D, 0x15, 0x3C,
        0x4B, 0x16, 0x3C, 0x4C, 0x17, 0x3C, 0x4E, 0x18, 0x3C, 0x51, 0x19, 0x3C, 0x50, 0x1A, 0x3C,
        0x52, 0x2B, 0x3C, 0x53, 0x2C, 0x3C, 0x40, 0x4,  0x31, 0x41, 0x5,  0x2C, 0x42, 0x7,  0x2F,
        0x43, 0x6,  0x2D, 0x44, 0x8,  0x2E, 0x46, 0x3,  0x9,  0x47, 0x9,  0x12};
    s8 D_80802124_gcnewpause[12] = {0x15, 0x11, 0xD, 0xA, 0x7, 0x5, 0x3, 0x2, -0x1, -0x1, 0x0, 0x0};
    ItemCountDisplay D_80802130_gcnewpause[7] = {0x1,  0x8,  0x1B, 0x2,  0xC,  0x1C, 0x4,
                                                 0x3B, 0x1D, 0x3,  0xD,  0x1E, 0x6,  0x2,
                                                 0x1F, 0x0,  0x16, 0x20, -0x1, 0x0,  0x0};
    AbilityTracking D_8080215C_gcnewpause[26] = {
        0x10, 0x14, 0x10, 0x15, 0x10, 0x16, 0xF,  0x19, 0xF,  0x1A, 0x12, 0x1B, 0x12,
        0x1C, 0x12, 0x29, 0x14, 0x1E, 0x14, 0x1F, 0x14, 0x1D, 0x15, 0x26, 0x15, 0x27,
        0x15, 0x28, 0x16, 0x25, 0x16, 0x23, 0x16, 0x24, 0x17, 0x21, 0x17, 0x22, 0x18,
        0x2A, 0x1A, 0x2C, 0x1A, 0x2D, 0x1A, 0x2E, 0x1A, 0x2F, -0x1, 0x0,  0x0,  0x0};
    unk80802190 D_80802190_gcnewpause[6] = {0x6E, 0x23, 0x0, 0x6E, 0x91, 0x0, 0x23, 0x23, 0x0,
                                            0x23, 0x23, 0x1, 0x23, 0x91, 0x0, 0x23, 0x91, 0x1};
    u8 D_808021B4_gcnewpause[12] = {0x0, 0x0, 0x2, 0x1, 0x4, 0x3, 0x0, 0x5, 0x4, 0x0, 0x0, 0x5};
    void *D_808021C0_gcnewpause = (void *) 0x00130466;
    static u32 D_808021C0_gcnewpause_rest[2] = {0x1D0018, 0x0};
    void *D_808021CC_gcnewpause = 0;
    static u32 D_808021CC_gcnewpause_rest[5] = {0x0, 0x3F000000, 0x3F800000, 0x3F800000, 0x0};
    void *D_808021E4_gcnewpause = 0;
    static u32 D_808021E4_gcnewpause_rest[6] = {0x0, 0x3ECCCCCD, 0x3F800000, 0x3F800000, 0x0, 0x0};
