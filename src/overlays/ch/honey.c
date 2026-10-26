#include "common.h"

#define AF(p, i) (*(f32 *)&(p)->actorData[i])
extern void _sudialog_entrypoint_0(void);
extern void func_800C9E20(f32, void *, s32, s32);
typedef struct Mass44HoneyFlags { u8 pad_0[0x78]; u32 pad_1:26; u32 local_0:1; u32 pad_2:1; u32 local_1:1; u32 pad_3:3; } Mass44HoneyFlags;
extern s32 D_80127194;
extern void func_80109EEC(Actor *, s32);
typedef struct { u8 pad[0x64]; u32 pad64:11; u32 b11:1; u32 b12:1; u32 rest:19; } HoneyS;
extern void func_8010DCB4(s32);
extern s32 *D_80801020_chhoney[];
extern f32 func_800D8FF8(void);
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 26; u32 disabled : 1; u32 pad_2 : 5; } HoneyFlags;
extern s32 func_800D9078(f32 *);
extern int D_80801048_chhoney;
extern void *D_80801090_chhoney;
extern int D_808010D8_chhoney;
extern u8 D_8012762C;
extern void func_800CE8D8(s32, f32, s32);
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern u8 D_80801028_chhoney[];
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } HoneyState;
typedef struct { u8 pad_0[0x78]; u32 a : 28; u32 f : 1; u32 b : 3; } Honey78;
extern u8 D_80801038_chhoney[];
extern s32 func_8008FC28(void);
extern s32 func_8008FC00(void);
extern void func_8008FBE0(s32);
extern void func_800FA9F4(s32, s32);
extern void func_800C3FC0(s32, f32, s32);
extern void func_8008FC70(s32);
extern void func_80090708(s32);
extern void func_800FFAB0(Actor *);
extern void _subaddieaudioloop_entrypoint_4();
void func_80800688_chhoney();
f32 func_80800000_chhoney();
void func_808000C4_chhoney();
void func_80800870_chhoney();

f32 func_80800000_chhoney(void) {
    switch (D_8012762C) {
    case 19:
        return 1.0f;
    case 16:
        return 0.7999878f;
    case 15:
        return 0.59999084f;
    case 18:
        return 0.3999939f;
    case 20:
        return 0.2999878f;
    case 21:
        return 0.19999695f;
    case 22:
        return 0.099990845f;
    case 23:
        return 0.07499695f;
    case 24:
        return 0.049987793f;
    case 25:
        return 0.049987793f;
    case 26:
        return 0.7999878f;
    default:
        return 0.0f;
    }
}

void func_808000C4_chhoney(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (param_0->unk70_10 == 2 || param_0->unk70_10 == 3) *(f32 *)((u8 *)param_0 + 0x24) = 0.0f;
    func_80101FDC(param_0, param_1);
    switch (param_0->unk70_10) {
    case 7: _subaddiedialog_entrypoint_11(param_0->unk0, 0xCE6, 12, param_0->position, 0); return;
    case 8: _subaddiedialog_entrypoint_11(param_0->unk0, 0xCE7, 12, param_0->position, 0); return;
    case 3:
        func_80090708(2);
        func_800CE8D8(6, 10.0f, 10);
        func_800CE88C(6, 1);
        func_800FA9F4(0, 1);
        *(f32 *)((u8 *)param_0 + 0x58) = *(f32 *)((u8 *)param_0 + 0x2C);
        break;
    case 2:
        func_80090708(2);
        func_800CE8D8(6, 10.0f, 10);
        func_800CE88C(6, 1);
        func_800FA9F4(0, 1);
        *(f32 *)((u8 *)param_0 + 0x58) = *(f32 *)((u8 *)param_0 + 0x2C);
        break;
    case 5:
    case 6: *(f32 *)((u8 *)param_0 + 0x58) = 0.0f; break;
    case 4:
        func_800FA9F4(0, 0);
        param_0->unk6C_0 = func_8008FC00();
        func_8008FC70(0);
        *(f32 *)((u8 *)param_0 + 0x58) = 0.2f;
        break;
    }
}

void func_80800244_chhoney(Actor *param_0)
{
    *(s32 *)((u8 *)param_0 + 0x54) = func_8001211C();
    *(f32 *)((u8 *)param_0 + 0x28) = 20.0f;
    _subaddieDll_entrypoint_4(param_0, !((*(u32 *)((u8 *)param_0 + 0x78) << 26) >> 31));
    param_0->scale = 0.5f;
    switch (param_0->unk0->unk24 >> 22) {
        case 0x55:
            param_0->unk79_4 = 0;
            break;
        case 0x22C:
            param_0->unk79_4 = 2;
            *(f32 *)((u8 *)param_0 + 0x2C) = func_80800000_chhoney();
            break;
        case 0x22B:
            param_0->unk79_4 = 1;
            *(f32 *)((u8 *)param_0 + 0x2C) = func_80800000_chhoney();
            break;
    }
    func_8010A5B0(param_0, func_800DA298(0x64C));
}

void func_80800328_chhoney(Actor *param_0, Unk80132ED0 *param_1)
{
    if (func_800F4B4C((u32)*(u16 *)((u8 *)param_1 + 0x1A) >> 5)) {
        switch (param_0->unk79_4) {
            case 0:
                func_800C9E20(0.75f, &_sudialog_entrypoint_0, 0x2F, 0);
                func_8008FC50();
                func_800FC660(8);
                func_800FFAB0(param_0);
                break;
            case 2:
                func_800FC660(0x81);
                if (!func_800DA9E4(0x40E, 1)) func_808000C4_chhoney(param_0, 8);
                else func_808000C4_chhoney(param_0, 3);
                break;
            case 1:
                func_800FC660(0x80);
                if (!func_800DA9E4(0x40D, 1)) func_808000C4_chhoney(param_0, 7);
                else func_808000C4_chhoney(param_0, 2);
                break;
        }
        _fxsparkle_entrypoint_1(param_0->position, 1);
        func_8010A570(param_0);
        param_0->unk64_16 = 0;
        ((u8 *)param_0)[0x75] &= ~0x10;
    }
}

int func_8080046C_chhoney(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3E:
        *((u8 *)param_0 + 0x79) &= 0xFFFC;
        func_80800328_chhoney(param_0, (Unk80132ED0 *)param_2);
        break;
    case 0x2E:
        switch (((s16 *)&param_2)[0]) {
        case 0xCE6: func_808000C4_chhoney(param_0, 2); break;
        case 0xCE7: func_808000C4_chhoney(param_0, 3); break;
        }
        break;
    case 0x1F:
        func_8010DD20(param_0, ((Mass44HoneyFlags *)param_0)->local_1 ? 2 : 3, param_2);
        if ((param_0->unk0->unk24 >> 22) != 0x55) func_800DF744(3, param_0->unk79_4);
        break;
    case 0x95:
        param_0->unk64_19 = 0;
        param_0->unk64_20 = 1 - ((Mass44HoneyFlags *)param_0)->local_1;
        func_80109EEC(param_0, 0x44);
        switch (param_0->unk0->unk24 >> 22) {
        case 0x55:
        case 0x22B:
        case 0x22C:
            if (!((Mass44HoneyFlags *)param_0)->local_0) {
                if (++D_80127194 >= 11) func_80800688_chhoney(param_0);
            }
            break;
        }
        break;
    default: return 0;
    }
    return 1;
}

void func_80800634_chhoney(HoneyS *param_0) {
    D_80127194--;
    if (param_0->b12) {
        func_8010DCB4(param_0->b11 ? 2 : 3);
    }
}

void func_80800688_chhoney(param_0) s32 *param_0;
{
    s32 *local_0[14];
    s32 *local_1[2];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 *local_7;
    s32 local_8;

    local_2 = 0;
    if (1) {}
    local_3 = func_8001211C();
    local_4 = _subaddiefind_entrypoint_6(D_80801020_chhoney, local_0, 14);
    for (local_5 = 0; local_5 < local_4; local_5++) {
        local_7 = local_0[local_5];
        if (param_0 != local_7) {
            local_8 = *(s32 *)((u8 *)local_7 + 0x54);
            if (local_8 <= local_3 && (*(u16 *)((u8 *)local_7 + 0x64) & 1)) {
                local_2 = *local_7;
                local_3 = local_8;
                local_1[0] = local_7;
            }
        }
    }
    if (local_2 == 0) {
        local_2 = *local_0[0];
        local_1[0] = local_0[0];
    }
    _fxsparkle_entrypoint_1(local_1[0] + 1, 0);
    func_800FFA88(local_2);
}

void func_80800754_chhoney(Actor *param_0)
{
    s32 local_1;
    f32 local_0[3];
    switch (param_0->unk0->unk24 >> 22) {
    case 0x55:
        break;
    case 0x22B:
    case 0x22C:
        if (param_0->unk7C_12) {
            for (local_1 = 0; local_1 < 4; local_1++) {
                if (func_800DC298(0.03f)) {
                    _subaddieskeleton_entrypoint_0(param_0, 1, local_0);
                    func_800EF214(local_0, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f), 50.0f);
                    _fxtwinkle_entrypoint_0(local_0);
                }
            }
        }
        break;
    }
}

void func_80800870_chhoney(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (*(f32 *)&param_0->actorData[6] <= 0.0f) {
        func_800C4B64(func_800F10B4(param_1, 1.0f, 10.0f, 0.8f, 1.5f));
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801028_chhoney);
        *(f32 *)&param_0->actorData[6] = 0.1f;
    }
}

void func_808008F8_chhoney(Actor *param_0, f32 param_1)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_800D8FF8();
    param_0->unk58 -= local_0;
    *(f32 *)&param_0->actorData[6] -= local_0;
    if (param_0->unk58 <= 0.0f) {
        local_1 = func_8008FC28() + 1;
        local_2 = func_8008FC00();
        local_3 = func_800DC128(1, local_1);
        while (local_3 == local_2) local_3 = func_800DC128(1, local_1);
        func_8008FC70(local_3);
        func_80800870_chhoney(param_0, local_3);
        param_0->unk58 = *(f32 *)&param_0->actorData[5];
    }
}

void func_808009BC_chhoney(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    local_0 = func_800D8FF8();
    param_0->unk58 -= local_0;
    *(f32 *)&param_0->actorData[6] -= local_0;
    if (param_0->unk58 <= 0.0f) {
        local_1 = func_8008FC00() + 1;
        if (func_8008FC28() < local_1) local_1 = 1;
        func_8008FC70(local_1);
        func_80800870_chhoney(param_0, local_1);
        param_0->unk58 = *(f32 *)&param_0->actorData[5];
    }
}

s32 func_80800EB0_chhoney();

void func_80800A5C_chhoney(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;

    func_80800EB0_chhoney(param_0);
    if (param_0->unk64_20 != ((Honey78 *)param_0)->f) {
        if (((Honey78 *)param_0)->f) {
            if (param_0->unk64_19) {
                func_8010DCB4(3);
            }
            func_8010DC50(2);
        } else {
            if (param_0->unk64_19) {
                func_8010DCB4(2);
            }
            func_8010DC50(3);
        }
        param_0->unk64_20 = ((Honey78 *)param_0)->f;
        param_0->unk64_19 = 1;
    }
    local_0 = func_800D8FF8();
    local_1 = func_8008FC28();
    switch (((HoneyState *)param_0)->st) {
    case 1:
        if (!local_1) {
            func_8010A570(param_0);
        } else {
            func_8010A590(param_0);
        }
        if (param_0->unk0->unk24 >> 22 == 0x22B || param_0->unk0->unk24 >> 22 == 0x22C) {
            if (func_8010CAC0(param_0->position, 0x1F4) && local_1) {
                func_8008FBE0(1);
            }
        }
        func_80800754_chhoney(param_0);
        return;
    case 7:
        func_8008FBE0(1);
        return;
    case 2:
        func_8008FBE0(1);
        func_808008F8_chhoney(param_0, 1e-45f);
        if (func_80090080()) {
            if (func_80016B30(0, 1)) {
                func_800CE88C(6, 0);
                func_808000C4_chhoney(param_0, 5);
                return;
            }
        }
        if (func_800CEAD0(6)) {
            func_808000C4_chhoney(param_0, 5);
            return;
        }
        break;
    case 8:
        func_8008FBE0(1);
        return;
    case 3:
        func_8008FBE0(1);
        func_808009BC_chhoney(param_0);
        if (func_80090080()) {
            if (func_80016B30(0, 1)) {
                func_800CE88C(6, 0);
                func_808000C4_chhoney(param_0, 5);
                return;
            }
        }
        if (func_800CEAD0(6)) {
            func_808000C4_chhoney(param_0, 5);
            return;
        }
        break;
    case 5:
        func_8008FBE0(1);
        func_800FA9F4(0, 1);
        param_0->unk58 += local_0 * 4.0f;
        if (0.2f < param_0->unk58) {
            AF(param_0, 3) += 1.0f;
            if (10.0f < AF(param_0, 3)) {
                func_808000C4_chhoney(param_0, 4);
            } else {
                func_808000C4_chhoney(param_0, 6);
            }
        }
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801038_chhoney);
        return;
    case 6:
        func_8008FBE0(1);
        func_800FA9F4(0, 2);
        param_0->unk58 += local_0 * 4.0f;
        if (0.2f < param_0->unk58) {
            func_808000C4_chhoney(param_0, 5);
        }
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801038_chhoney);
        return;
    case 4:
        func_8008FBE0(1);
        param_0->unk58 -= func_800D8FF8();
        if (param_0->unk58 <= 0.0f) {
            local_2 = func_8008FC00();
            param_0->unk58 = 0.2f;
            local_2 = local_2 + 1;
            func_800C3FC0(0x66C, func_800F10B4((f32)local_2, 1.0f, 10.0f, 0.8f, 1.5f), 0x3E80);
            func_8008FC70(local_2);
            if (local_2 == param_0->unk6C_0) {
                func_80090708(0);
                func_800FFAB0(param_0);
            }
        }
        return;
    }
}

s32 func_80800EB0_chhoney(Actor *param_0)
{
    if (((HoneyFlags *)param_0)->disabled || param_0->unk64_17) return 0;
    if (func_800EA068(2)) return 0;
    if (func_800D9078((f32 *)&param_0->actorData[4])) {
        if (param_0->unk64_16) {
            _subaddiefade_entrypoint_3(param_0);
            return 1;
        }
    }
    return 0;
}

int chhoney_entrypoint_0()
{
  return &D_80801048_chhoney;
}

int chhoney_entrypoint_1()
{
  return &D_80801090_chhoney;
}

int chhoney_entrypoint_2()
{
    return (int)&D_808010D8_chhoney;
}
