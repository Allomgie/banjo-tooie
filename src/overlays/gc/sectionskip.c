/* TU-NOTE: gc/sectionskip.h is not included as a whole: through gc/goto.h -> core2/1E80A70.h -> core2/1E99980.h
 * it would declare func_800C05B8 with an s16 first parameter, but this file calls it without a prototype
 * (a0 is passed on unnarrowed). The other headers of gc/sectionskip.h are included directly. */
#include "common.h"
#include "core2/1EA9160.h"
#include "core2/1EAAD80.h"
#include "core2/1EB3750.h"
#include "core2/1EC3810.h"
#include "gc/sectionDll.h"
#include "ch/mrtannoy.h"
#include "gameflags.h"

extern f32 mlAbsF(f32);
extern f32 sqrtf(f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern s32 func_800DC298(f32);
int func_80800D3C_gcsectionskip();

int func_80800000_gcsectionskip(f32 *param_0, f32 *param_1, f32 param_2, s32 param_3)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_4;
    f32 local_3;
    f32 local_2;
    f32 local_7;
    f32 local_5;
    f32 local_6;
    func_800EE7F8(local_0, param_0);
    if (!param_3) {
        local_1 = (param_1[0] + param_2) - param_0[0];
        if (local_1 > param_2) { local_1 -= param_2 + param_2; }
        local_2 = (param_1[2] + param_2) - param_0[2];
        if (local_2 > param_2) { local_2 -= param_2 + param_2; }
        if (mlAbsF(local_1) < mlAbsF(local_2)) { param_0[0] += local_1; }
        else { param_0[2] += local_2; }
    } else {
        local_4 = (param_2 + param_2) / sqrtf(2.0f);
        local_5 = param_0[0] - param_1[0];
        local_6 = param_0[2] - param_1[2];
        local_7 = mlAbsF(local_5) + mlAbsF(local_6);
        local_5 = (local_5 * local_4) / local_7;
        local_6 = (local_6 * local_4) / local_7;
        param_0[0] = param_1[0] + local_5;
        param_0[2] = param_1[2] + local_6;
    }
    if (func_800EECE0(local_0, param_0)) {
        return 0;
    }
    return 1;
}

void func_8080019C_gcsectionskip(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    f32 local_4;

    func_800EE7F8(local_0, param_1);
    local_2 = param_4;
    local_3 = 0;
    local_4 = 4.0f;
    do {
        if (1) {}
        func_800EFE50(local_1, param_1, param_0, (f32)local_3 / local_4);
        if (!func_80800000_gcsectionskip(local_1, param_2, param_3, local_2)) {
            break;
        }
        func_800EE7F8(local_0, local_1);
        local_3++;
    } while (local_3 != 4);
    func_800EE7F8(param_1, local_0);
}

void func_808002A0_gcsectionskip(s32 param_0, u8 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4;
    f32 local_5;

    if (param_1 != NULL) {
        local_4 = (u32)param_1[0x13] >> 7;
        local_5 = (f32)((u32)*(u16 *)(param_1 + 6) >> 7);
        func_800F5D9C(param_0, local_3);
        func_800F5D70(param_0, local_2);
        func_800EF334(local_2, func_800D8FF8());
        func_800EFB24(local_1, local_3, local_2);
        func_800EE88C(local_0, param_1);
        func_8080019C_gcsectionskip(local_1, local_3, local_0, local_5, (f32)local_4);
        func_800F8418(param_0, local_3);
    }
}

s32 func_80800374_gcsectionskip(s32 param_0, s32 param_1) {
    func_800F7E3C(param_0, 0);
    func_808002A0_gcsectionskip(param_0, param_1);
}

s32 gcsectionskip_entrypoint_0(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0xDAA){
        func_800DA524(0x6C9);
    }
}

void func_80800EF8_gcsectionskip();

s32 gcsectionskip_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3, void *param_4)
{
    extern u8 D_80801040_gcsectionskip[];
    extern u8 D_8012762C;

    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;

    local_0 = 1;

    if (_gcgoto_entrypoint_15()) {
        return 0;
    }

    local_1 = func_800F54E4();

    if (param_4 != 0 &&
        local_1 != ((u32)*(u16 *)((char *)param_4 + 0x1A) >> 5)) {
        return 0;
    }

    local_2 = func_800F5410(local_1);

    _gcgoto_entrypoint_0(&param_1, &param_2);

    if (func_800F6D24(local_1) ||
        func_800F8004(local_1) ||
        func_800F6CC8(local_1) ||
        func_800F66F0(local_1) ||
        func_800F70BC(func_800F54E4())) {
        func_808002A0_gcsectionskip(local_1, param_0);
        return 0;
    }

    if (func_800F8B88() == 3 && local_2 == 0xB) {
        func_800F7B9C(local_1, 0x88);
        return 0;
    }

    switch (param_3) {
        case 0:
            if (!func_800F4BE4(local_1)) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 1:
            if (!_chchuffycont_entrypoint_0(&param_1, &param_2)) {
                return 0;
            }
            break;

        case 2:
            if (!_chchuffycont_entrypoint_1(&param_1, &param_2)) {
                return 0;
            }
            local_0 = 0;
            break;

        case 3:
            if (!func_800DA298(0xB2)) {
                return 0;
            }
            break;

        case 4:
            if (local_2 != 1) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 29:
            if (local_2 != 1) {
                func_808002A0_gcsectionskip(local_1, param_0);
                func_800F7E3C(local_1, 0x1228);
                return 0;
            }
            break;

        case 5:
            if (local_2 != 0xB) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 6:
            if (local_2 != 0xA) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            local_0 = 0;
            break;

        case 7:
            if (func_800DA298(0xB6)) {
                return 0;
            }
            break;

        case 8:
            if (func_800DA564(0xA34, 3)) {
                return 0;
            }
            break;

        case 14:
            param_2 = D_80801040_gcsectionskip[func_800DA564(0x3A4, 4)];
            break;

        case 10:
        case 15:
            break;

        case 11:
            if (func_800DA298(0x327)) {
                param_2++;
            }
            break;

        case 12:
            if (!func_800DA9E4(0x409, 1)) {
                func_800DA3B8(0x40A, func_800DC298(0.5f) ? 0 : 1);
            }

            switch (func_800EA05C()) {
            case 0x136:
                switch (param_1) {
                case 0x13E:
                    if (!func_800DA298(0x40A)) {
                        param_1 = 0x13F;
                    }
                    break;
                case 0x13F:
                    if (!func_800DA298(0x40A)) {
                        param_1 = 0x13E;
                    }
                    break;
                default:
                    return 0;
                }
                break;
            case 0x13E:
                if (!func_800DA298(0x40A)) {
                    param_2 = 9;
                }
                break;
            case 0x13F:
                if (!func_800DA298(0x40A)) {
                    param_2 = 0x16;
                }
                break;
            }
            break;

        case 13:
            if (!func_80800D3C_gcsectionskip(&param_1, &param_2)) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 9:
            if (local_2 != 1) {
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            if (!func_800C6E38(0x1B)) {
                func_808002A0_gcsectionskip(local_1, param_0);
                func_80800EF8_gcsectionskip(0x10FB, 0x22);
                return 0;
            }
            break;

        case 16:
            if (local_2 != 1 && local_2 != 8) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            local_0 = 0;
            break;

        case 17:
            if (local_2 != 0xC) {
                func_80800EF8_gcsectionskip(0x1219, 0x22);
                return 0;
            }
            break;

        case 18:
            if (local_2 == 0xA) {
                func_80800EF8_gcsectionskip(0x1545, 0xCB);
                return 0;
            }

            if (local_2 == 0xB) {
                func_80800EF8_gcsectionskip(0x1544, 0xCB);
                return 0;
            }
            break;

        case 19:
            if (local_2 != 8) {
                func_80800EF8_gcsectionskip(0xF56, 0xCB);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 20:
            if (local_2 != 1) {
                func_808002A0_gcsectionskip(local_1, param_0);
                func_80800EF8_gcsectionskip(0x1221, 0x22);
                return 0;
            }

            if (!func_800C6E38(0x15)) {
                func_808002A0_gcsectionskip(local_1, param_0);
                func_80800EF8_gcsectionskip(0x1227, 0x22);
                return 0;
            }

            if (!func_800C6E38(0x2E)) {
                func_808002A0_gcsectionskip(local_1, param_0);
                func_80800EF8_gcsectionskip(0x122A, 0x22);
                return 0;
            }

            if (func_800DA298(0x44) &&
                !func_800DA298(0x43)) {
                param_1 = 0x19A;
                param_2 = 1;
            }
            break;

        case 21:
            if (func_800DA298(0x360)) {
                param_1 = 0x19B;
            }
            break;

        case 22:
            if (!func_800F64A4(local_1, 0x601)) {
                func_80800EF8_gcsectionskip(0x1211, 0x6F);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 23:
            if (!func_800F64A4(local_1, 0x801)) {
                func_80800EF8_gcsectionskip(0x1223, 0x6F);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }

            if (!func_800C6E38(0x1F) ||
                !func_800C6E38(0x2D)) {
                func_80800EF8_gcsectionskip(0x1226, 0x6F);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 24:
            if (local_2 == 0x11) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 25:
            local_3 = func_800F54E4();

            if (local_2 == 0x11) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }

            func_800F7C9C(local_3, 0x95, func_800EA05C(), 2);
            break;

        case 26:
            local_4 = func_800F54E4();

            if (local_2 == 0x11) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }

            func_800F7C9C(local_4, 0x95, func_800EA05C(), 2);
            func_800F7B9C(local_4, 0x96);
            break;

        case 27:
            if (local_2 == 0x11) {
                func_80800374_gcsectionskip(local_1, param_0);
                return 0;
            }

            if (local_2 != 1) {
                if (func_800F7E3C(local_1, 0x1224)) {
                    _chmrtannoy_entrypoint_0();
                }

                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }

            if (!func_800C6E38(0x2D)) {
                if (func_800F7E3C(local_1, 0x122B)) {
                    _chmrtannoy_entrypoint_0();
                }

                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 28:
            if (local_2 == 8) {
                func_80800374_gcsectionskip(local_1, param_0);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 30:
            if (local_2 == 0xD) {
                func_800F7E3C(local_1, 0x1215);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 31:
            if (!func_800DA298(0x360) &&
                !func_800DA298(0x3B)) {
                func_800F7E3C(local_1, 0x1566);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;

        case 32:
            if (!func_800C6E38(0x2F)) {
                func_800F7E3C(local_1, 0x122C);
                func_808002A0_gcsectionskip(local_1, param_0);
                return 0;
            }
            break;
    }

    if (func_800D395C() || func_800D3948()) {
        func_808002A0_gcsectionskip(local_1, param_0);
        return 0;
    }

    if (local_0 && local_2 != 1) {
        local_5 = D_8012762C;
        local_6 = _gcsectionDll_entrypoint_4(param_1);
        local_7 = local_6 == local_5 && local_2 == 0xD;

        if (local_5 != local_6 ||
            (local_5 == 0x1A && !local_7)) {
            func_80800374_gcsectionskip(local_1, param_0);
            return 0;
        }
    }

    if (func_800A8264()) {
        return 0;
    }

    _gcgoto_entrypoint_3(param_0, param_1, param_2);
    return 1;
}

int func_80800D3C_gcsectionskip(param_0, param_1) s32 *param_0; s32 *param_1;
{
    if (func_800F5410(func_800F54E4()) != 1) return 0;
    switch (func_800EA05C()) {
    case 0xAF:
        if (func_800DA298(0x318)) { *param_0 = 0x142; *param_1 = 3; }
        break;
    case 0x142:
        if (func_800DA298(0x318)) { *param_0 = 0xAF; *param_1 = 3; }
        else *param_1 = 1;
        break;
    case 0x15A:
        if (func_800DA298(0x319)) { *param_0 = 0x154; *param_1 = 3; }
        else *param_1 = 1;
        break;
    case 0x154:
        if (func_800DA298(0x319)) { *param_0 = 0x15A; *param_1 = 1; }
        break;
    case 0x15D:
        if (func_800DA298(0x31A)) {
            *param_0 = 0x15F;
            if (func_800DA298(0x441)) *param_1 = 3;
            else *param_1 = 1;
        }
        break;
    case 0x15F:
        if (func_800DA298(0x31A)) { *param_0 = 0x15D; *param_1 = 2; }
        else *param_1 = 1;
        break;
    }
    return 1;
}

void func_80800EF8_gcsectionskip(s32 param_0, s32 param_1)
{
    func_800C05B8(param_0, 0, 0, 0, 0, 0, param_1);
}
