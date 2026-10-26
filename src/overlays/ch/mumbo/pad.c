#include "common.h"

extern u8 D_808010C8_chmumbopad[];
extern s16 D_808010EC_chmumbopad[];
typedef union { s32 word; s16 half; } MumboPadPayload31;
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 18; u32 local_0 : 1; u32 pad_2 : 13; } MumboMarkerFlags31;
extern int D_80801110_chmumbopad[];
extern s16 D_80801060_chmumbopad[];
extern u16 D_80801084_chmumbopad[][2];
extern f32 func_80103EAC(Actor *);
typedef struct { u8 pad0[0x2A]; u8 pad2A_6 : 2; u8 unk2A_5 : 1; u8 pad2A_0 : 5; } MumboPadInfo;
extern void func_80015E80(s32, s32 *);
int func_80800674_chmumbopad();
void func_808008CC_chmumbopad();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(), func_8080044C_chmumbopad();

int chmumbopad_entrypoint_0(s32 param_0)
{
  return (s16)D_80801084_chmumbopad[param_0][1];
}

s32 func_80800014_chmumbopad(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0;

    local_0 = _gccubesearch_entrypoint_1(param_2 | 0);
    _gspropctrl_entrypoint_11(local_0 | 0, param_1);
}

int func_80800048_chmumbopad(Actor *param_0)
{
  s16 local_0;
  unsigned int new_var;
  local_0 = *((s16 *) (D_808010C8_chmumbopad + (((*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF) * 2)));
  if (local_0 != (-1))
  {
    new_var = local_0;
    return func_800DA298(new_var, local_0);
  }
  return 0;
}

int func_80800098_chmumbopad(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk6C_0) {
    case 12:
        return func_800DA298(0x358) != 0 && func_800DA298(0x359) != 0;
    case 13:
        return func_800DA564(0x1CA, 2) != 0;
    default:
        local_0 = D_808010EC_chmumbopad[param_0->unk6C_0];
        if (local_0 != -1) return func_800DA298(local_0);
        return 0;
    }
}

void func_80800140_chmumbopad(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800EA05C();
    switch (local_0) {
        case 0xD7: param_0->unk6C_0 = 0; break;
        case 0xC7: param_0->unk6C_0 = 1; break;
        case 0xB8: param_0->unk6C_0 = 2; break;
        case 0xE6: param_0->unk6C_0 = 3; break;
        case 0xD6:
            if (param_0->pad6C_21 == 0xB4) {
                param_0->unk6C_0 = 5;
            } else {
                param_0->unk6C_0 = 4;
            }
            break;
        case 0x1A7: param_0->unk6C_0 = 6; break;
        case 0x118: param_0->unk6C_0 = 7; break;
        case 0x112:
            if (param_0->pad6C_21 == 0x5D) {
                param_0->unk6C_0 = 8;
            } else {
                param_0->unk6C_0 = 9;
            }
            break;
        case 0x107: param_0->unk6C_0 = 10; break;
        case 0x10B: param_0->unk6C_0 = 11; break;
        case 0x136: param_0->unk6C_0 = 12; break;
        case 0x128:
            if (param_0->pad6C_21 == 0x144) {
                param_0->unk6C_0 = 13;
            } else if (func_800DA298(0x376)) {
                param_0->unk6C_0 = 15;
            } else {
                param_0->unk6C_0 = 14;
            }
            break;
        case 0x155: param_0->unk6C_0 = 16; break;
    }
    func_80103140(param_0, D_80801084_chmumbopad[param_0->unk6C_0][0], param_0->unk0->unk16);
    func_8010A654(param_0, func_800DA298(0x64D));
    if (func_80800098_chmumbopad(param_0)) {
        if (func_8010CB84(param_0->position, (s32)func_80103EAC(param_0))) {
            func_80101FDC(param_0, 2);
        } else {
            func_800FFAB0(param_0);
            return;
        }
    }
    func_80800014_chmumbopad(param_0, param_0->actorData, D_80801060_chmumbopad[param_0->unk6C_0]);
    if (func_800F5410(func_800F54E4()) != 13) {
        _subaddiefade_entrypoint_1(param_0, 0x87);
    }
}

void func_8080044C_chmumbopad(param_0) Actor *param_0;
{
    switch (param_0->unk70_10) {
    case 1:
        if (!param_0->unk74_29) {
            func_80103110(param_0, 0);
            if (func_80800098_chmumbopad(param_0)) {
                _subaddiefade_entrypoint_3(param_0);
                func_80101FDC(param_0, 3);
            }
        }
        param_0->unk74_29 = 0;
        break;
    case 2:
        if (!param_0->unk74_29) {
            _subaddiefade_entrypoint_3(param_0);
            func_80101FDC(param_0, 3);
        }
        param_0->unk74_29 = 0;
        break;
    }
}

s32 func_80800514_chmumbopad(Actor *param_0, s32 param_1, MumboPadPayload31 param_2)
{
    switch (param_1) {
        default:
            return 0;
        case 0x91:
            if (!param_0->unk64_19 && !param_0->unk74_29 &&
                !((MumboMarkerFlags31 *)param_0->unk0)->local_0) {
                func_808008CC_chmumbopad(param_0, param_2.word);
            }
            func_80103110(param_0, 1);
            return 1;
        case 0x32:
            func_80800674_chmumbopad(param_0, param_2.word);
            return 1;
        case 0xBB:
            if (param_2.word == param_0->unk6C_0) {
                ((MumboMarkerFlags31 *)param_0->unk0)->local_0 = 0;
            }
            break;
        case 0x2E:
            if (param_2.half == 0x11DE) {
                _chintrotext_entrypoint_1(0x18BD, param_0->unk6C_0, 0, 1);
                param_0->unk64_19 = 0;
            }
            return 0;
    }
    return 1;
}

int func_8080063C_chmumbopad(s32 param_0, s32 param_1)
{
    func_800F7874(param_1, *(s32 *)param_0, param_0 + 4, param_0);
    func_800F5FA8(param_1);
}

int func_80800674_chmumbopad(param_0, param_1) Actor *param_0; s32 param_1;
{

    func_800F7CF4(param_1, 0x43, param_0->actorData);
    func_800C067C(0x11DD);
    if (!func_80800048_chmumbopad(param_0)) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x11DE, 6, param_0->position, 0);
        param_0->unk64_19 = 1;
    }
    param_0->unk64_20 = 1;
    param_0->unk74_30 = 0;
    func_800C067C(0x11DD);
    switch (*(u32 *)((u8 *)param_0 + 0x6C) & 0x1FF) {
    case 0:
    case 1: break;
    case 2: param_0->unk64_20 = 0; break;
    case 3: func_80101180(0x337, 10, 0); break;
    case 4: func_80101180(0x39D, 10, 0); break;
    case 5: func_80101180(0x39C, 10, 0); break;
    case 6: func_80101180(0x297, 75, 0); break;
    case 7: func_80101180(0x292, 75, 0); break;
    case 8: func_80101180(0x28E, 75, 8); break;
    case 9: func_80101180(0x28D, 75, 9); param_0->unk64_20 = 0; break;
    case 11: func_80101180(0x3EE, 75, 0); param_0->unk64_20 = 0; break;
    case 10: func_80101180(0x3F5, 75, 0); param_0->unk64_20 = 0; break;
    case 12: func_80101180(0x40E, 75, 12); param_0->unk64_20 = 0; break;
    case 13: func_80101180(0x346, 75, 0); break;
    case 14: func_80101180(0x45A, 75, 0); break;
    case 15: func_80101180(0x457, 75, 0); break;
    case 16: func_80101180(0x4D8, 75, 0); break;
    }
    ((MumboPadInfo *)param_0->unk0)->unk2A_5 = !param_0->unk64_20;
}

void func_808008CC_chmumbopad(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0[6];

    if (func_800F54E4() == param_1) {
        if (func_800F5410(param_1) == 0xD) {
            func_80015E80(0, local_0);
            param_0->unk74_29 = 1;
            if (!func_800DA298(0x9B)) {
                func_800DA544(0x9B);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x11DD, 6, param_0->position, 0);
            }
            if (local_0[1] == 1 && !param_0->unk64_20 && !func_800DA298(0x9DE)) {
                switch (param_0->unk6C_0) {
                case 0:
                    if (!func_800DA298(0x95)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 1:
                    if (!func_800DA564(0x4FC, 4)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 2:
                    func_8080063C_chmumbopad(param_0, param_1);
                    return;
                case 3:
                    func_8080063C_chmumbopad(param_0, param_1);
                    return;
                case 4:
                    func_8080063C_chmumbopad(param_0, param_1);
                    return;
                case 5:
                    func_8080063C_chmumbopad(param_0, param_1);
                    return;
                case 6:
                    if (!func_800DA298(0xE9)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 7:
                    if (!func_800DA298(0x15F)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 8:
                    if (!func_800DA298(0x160)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 9:
                    func_8080063C_chmumbopad(param_0, param_1);
                    return;
                case 11:
                    if (!func_800DA298(0xA05) && !func_800DA298(0x329)) {
                        if (!func_800DA298(0xA06)) {
                            func_8080063C_chmumbopad(param_0, param_1);
                            return;
                        }
                        if (!param_0->unk74_30) {
                            param_0->unk74_30 = 1;
                            _subaddiedialog_entrypoint_11(param_0->unk0, 0x11E9, 0xE, param_0->position, 0x10);
                            return;
                        }
                    }
                    break;
                case 10:
                    if (!func_800DA298(0xA06)) {
                        if (!func_800DA298(0xA05)) {
                            func_8080063C_chmumbopad(param_0, param_1);
                            return;
                        }
                        if (!param_0->unk74_30) {
                            param_0->unk74_30 = 1;
                            _subaddiedialog_entrypoint_11(param_0->unk0, 0x11E9, 0xE, param_0->position, 0x10);
                            return;
                        }
                    }
                    break;
                case 12:
                    if (!func_800DA298(0x1E1) || !func_800DA298(0x358) || !func_800DA298(0x359) || !func_800DA298(0x35A)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 13:
                    if (!func_800DA564(0x1CA, 2)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    break;
                case 14:
                    if (func_800DA298(0x375) && !func_800DA298(0x376)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    if (!param_0->unk74_30) {
                        param_0->unk74_30 = 1;
                        _subaddiedialog_entrypoint_11(param_0->unk0, 0x11EC, 0xE, param_0->position, 0x10);
                        return;
                    }
                    break;
                case 15:
                    if (!func_800DA298(0x373) && func_800DA298(0x6B4)) {
                        func_8080063C_chmumbopad(param_0, param_1);
                        return;
                    }
                    if (!param_0->unk74_30) {
                        param_0->unk74_30 = 1;
                        _subaddiedialog_entrypoint_11(param_0->unk0, 0x11EC, 0xE, param_0->position, 0x10);
                        return;
                    }
                    break;
                case 16:
                    if (func_800DA298(0x4F3) && !func_800DA298(0x15E)) {
                        if (!func_800C0638()) {
                            if (func_800DA298(0x189)) {
                                func_8080063C_chmumbopad(param_0, param_1);
                                return;
                            }
                            if (func_800DA298(0x6DB)) {
                                _subaddiedialog_entrypoint_11(param_0->unk0, 0x150E, 0xE, param_0->position, 0x10);
                                return;
                            }
                            _subaddiedialog_entrypoint_11(param_0->unk0, 0x150F, 0xE, param_0->position, 0x10);
                            func_800DA544(0x6DB);
                            return;
                        }
                    } else if (!func_800C0638()) {
                        if (func_800DA298(0x6DC)) {
                            _subaddiedialog_entrypoint_11(param_0->unk0, 0x150D, 0xE, param_0->position, 0x10);
                            return;
                        }
                        _subaddiedialog_entrypoint_11(param_0->unk0, 0x150C, 0xE, param_0->position, 0x10);
                        func_800DA544(0x6DC);
                        return;
                    }
                    break;
                }
            }
        } else if (!func_800DA298(0x9A)) {
            func_800DA544(0x9A);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x11DC, 6, param_0->position, 0);
        }
    }
}

int chmumbopad_entrypoint_1()
{
  return (int)&D_80801110_chmumbopad;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mumbo/pad.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80801110_chmumbopad -> int[] */
s16 D_80801060_chmumbopad[18] = { 0x2A5, 0x17E, 0x163, 0x154, 0x154, 0x154, 0x297, 0x292, 0x28E, 0x28D, 0x3F5, 0x3EE, 0x40E, 0x346, 0x45A, 0x457, 0x4D8, 0x0 };
u16 D_80801084_chmumbopad[17][2] = { 0x7D8, 0x9D5, 0x7D8, 0x9D5, 0x7E0, 0x9DF, 0x7D9, 0x9E0, 0x7D9, 0x9E0, 0x7D9, 0x9E0, 0x7DB, 0x9E2, 0x7DC, 0x9E5, 0x7DC, 0x9E5, 0x7DC, 0x9E5, 0x7DE, 0x9E3, 0x7DE, 0x9E3, 0x7DD, 0x9E4, 0x7DA, 0x9E9, 0x7DA, 0x9E9, 0x7DA, 0x9E9, 0x7DF, 0x9DE };
u8 D_808010C8_chmumbopad[36] = { 0xFF, 0xFF, 0xFF, 0xFF, 0x5, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5, 0x7D, 0x5, 0x7E, 0x5, 0x7F, 0x5, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0 };
s16 D_808010EC_chmumbopad[18] = { 0x95, 0x4FC, -0x1, 0xEA, 0xEC, 0xEB, 0xE9, 0x15F, 0x160, -0x1, 0x1B8, 0x329, -0x1, -0x1, -0x1, 0x373, 0x15E, 0x0 };
int D_80801110_chmumbopad[20] = { 0x21002B0, -0xFFFF, 0x0, (u32)func_8080044C_chmumbopad, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x181C, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800140_chmumbopad, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_80800514_chmumbopad, 0x0, 0x0, 0x0 };
