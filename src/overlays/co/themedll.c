#include "common.h"

#define THEME_OPTION_1528
typedef struct { s16 unk0; s16 unk2; s16 unk4; } ThemeEntry;
extern ThemeEntry D_80800D34_cothemedll[];
extern ThemeEntry D_80800730_cothemedll[];
extern s32 func_800DA298(s32);
typedef struct { s16 a; s16 b; s16 c; } ThemeEnt;
extern s32 func_800FE890();
extern void func_80016DA0(s32, s32);
extern s16 D_80800734_cothemedll[];
typedef struct { s16 local_0; u8 pad_0[4]; } ThemeOption;
extern ThemeOption D_80800732_cothemedll[];
extern void func_800FEDC4(s32, s32, f32, f32);
extern s16 D_80800CB4_cothemedll[];
typedef struct { u8 pad_0[8]; s16 local_0; u8 pad_1[4]; u8 local_1; u8 pad_2[3]; u8 local_2; u8 pad_3[0x2E]; u8 local_3; } ThemeTransition;
void func_80800388_cothemedll();

s32 func_80800000_cothemedll(param_0) s32 param_0;
{
    s32 i;
    s32 local_0;

    local_0 = param_0;
    for (i = 0; D_80800D34_cothemedll[i].unk0 != 0; i++) {
        if (local_0 == D_80800D34_cothemedll[i].unk0 && func_800DA298(D_80800D34_cothemedll[i].unk4)) {
            local_0 = D_80800D34_cothemedll[i].unk2;
        }
    }
    for (i = 0; D_80800730_cothemedll[i].unk0 != 0; i++) {
        if (local_0 == D_80800730_cothemedll[i].unk0) {
            return i;
        }
    }
    return 0;
}

void cothemedll_entrypoint_0(s32 param_0) {
    s32 local_0;
    if (!func_800FE890()) {
        local_0 = ((ThemeEnt *) D_80800732_cothemedll)[func_80800000_cothemedll(param_0)].a >> 2;
        if (local_0 != -1) {
            func_80016DA0(local_0, 1);
        }
    }
}

int cothemedll_entrypoint_1()
{
  int new_var2;
  int new_var;
  new_var2 = ((((((0, func_80800000_cothemedll())) * 3) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & ((0, 0xFFFFFFFFFFFFFFFF));
  new_var = (new_var2 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
  return D_80800734_cothemedll[new_var & 0xFFFFFFFFFFFFFFFF];
}

void cothemedll_entrypoint_2(void *param_0, s32 param_1)
{
    s32 local_0;

    if (!func_800FE890(param_0)) {
        local_0 = func_80800000_cothemedll(param_1);
        local_0 = D_80800732_cothemedll[local_0].local_0 >> 2;
        if (local_0 != -1) {
            if (func_800FCCD4(local_0)) func_800FC74C(local_0);
            func_80016DF8(local_0);
        }
    }
    if (!func_800DA9E4(0x674, 0)) func_800FDC28(0);
    if (!func_800DA9E4(0x675, 0)) {
        for (local_0 = 0; local_0 < 2; local_0++) func_800FEDC4(local_0, 0, 1.0f, 0.0f);
    }
    *((u8 *)param_0 + 0x41) = 1;
}

void cothemedll_entrypoint_3(u8 *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_4;
    u8 *local_3;

    local_0 = func_800EA05C();
    local_1 = func_80800000_cothemedll(local_0);
    param_0[0x41] = 0;
    *(s32 *)(param_0 + 0x28) = -1;
    *(s32 *)(param_0 + 0x2C) = -1;
    param_0[0x10] = 0xFF;
    param_0[0x11] = 0xFF;
    if (func_800FE890() != 2) {
        *(s32 *)(param_0 + 0x1C) = 0;
        *(s16 *)(param_0 + 0x22) = 0;
        *(s16 *)(param_0 + 0x20) = 0;
        param_0[0x12] = 0;
        param_0[0x13] = 0;
        param_0[0x14] = 1;
        param_0[0x15] = 1;
        *(f32 *)(param_0 + 4) = 1.0f;
        if (param_0[0x16]) {
            local_3 = ((u8 *) D_80800730_cothemedll) + local_1 * 6;
            *(s16 *)(param_0 + 0xC) = *(u16 *)(local_3 + 2) & 3;
            *(s16 *)(param_0 + 8) = *(s16 *)(local_3 + 2) >> 2;
            if (*(s16 *)(param_0 + 8) != -1) {
                *(s16 *)(param_0 + 0xA) = func_80017764(*(s16 *)(param_0 + 8));
            } else {
                *(s16 *)(param_0 + 0xA) = 0x4E20;
            }
            *(s16 *)(param_0 + 0x24) = 0;
            for (local_4 = 0; ((s16 (*)[2])D_80800CB4_cothemedll)[local_4][0] != -1; local_4++) {
                if (local_0 == ((s16 (*)[2])D_80800CB4_cothemedll)[local_4][0]) {
                    *(s16 *)(param_0 + 0x20) = ((s16 (*)[2])D_80800CB4_cothemedll)[local_4][1];
                }
            }
        }
    }
}

void func_80800388_cothemedll(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_800EA05C();
    switch (local_0) {
    case 0xB8:
    case 0xBB:
    case 0xC6:
    case 0xC8:
    case 0xC9:
        switch (param_0) {
        case 0xB8:
        case 0xBB:
        case 0xC6:
        case 0xC8:
        case 0xC9:
            func_800FE870();
            return;
        default:
            return;
        }
        break;
    case 0x127:
    case 0x12D:
    case 0x12E:
    case 0x12F:
    case 0x130:
        switch (param_0) {
        case 0x127:
        case 0x12D:
        case 0x12E:
        case 0x12F:
        case 0x130:
            func_800FE870();
            break;
        }
        break;
    }
}

void cothemedll_entrypoint_4(ThemeTransition *param_0, s32 param_1)
{
    s32 local_0;

    param_0->local_2 = 1;
    if (!func_800DA298(0x674)) func_800FDC28(0);
    func_80800388_cothemedll(param_1);
    if (!func_800FE890()) {
        local_0 = D_80800732_cothemedll[func_80800000_cothemedll(param_1)].local_0 >> 2;
        if (local_0 != param_0->local_0 || param_0->local_3) {
            func_800FC2C4(0, 0x7D0);
            func_800FE3EC();
        } else param_0->local_1 = 1;
    }
    param_0->local_3 = 1;
}

void func_80800524_cothemedll(u8 *param_0, s32 param_1)
{
    s16 local_0;

    if (param_1 != 0) {
        func_800FC884();
    }
    local_0 = *(s16 *)(param_0 + 8);
    if ((local_0 != -1) && (func_800FCCD4(local_0) == 0)) {
        func_800FE89C();
    }
}

void cothemedll_entrypoint_5(u8 *param_0, s32 param_1, s32 param_2) {
    if (param_1 == 1) {
        func_800FC348(-1, 0xFA0, 4, param_2);
        func_800FECB8(2);
    }
    switch (param_2) {
    case 1:
        func_800FC348(0, 0xFA0, 4, param_2);
        func_800FEC60(2);
        return;
    case 0: ;
    case 2:
        if ((*(u8 *)((s8 *)(param_0) + (0xE))) == 0) {
            if ((*(s16 *)((s8 *)(param_0) + (0xC))) & 1) {
                func_80800524_cothemedll(param_0, 0);
                return;
            }
            func_80800524_cothemedll(param_0, 1);
            return;
        }
        (*(u8 *)((s8 *)(param_0) + (0xE))) = 0U;
        return;
    }
}
