#include "common.h"

extern int D_80800540_chbilldrillboulder[];
extern void *D_80800588_chbilldrillboulder;
extern int D_808005D0_chbilldrillboulder[];
extern u8 _chbaddiesetup_entrypoint_9[];
extern u8 D_80800684_chbilldrillboulder[];
extern u8 D_80800618_chbilldrillboulder[];
extern u8 D_808006F0_chbilldrillboulder[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_80103EF4(Actor *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chbaddiesetup_entrypoint_4(void *, s32, s32, s32, s32);
s32 func_808004D4_chbilldrillboulder();

int chbilldrillboulder_entrypoint_0()
{
    return (int) &D_80800540_chbilldrillboulder;
}

int chbilldrillboulder_entrypoint_1()
{
    return &D_80800588_chbilldrillboulder;
}

int chbilldrillboulder_entrypoint_2()
{
    return (int) &D_808005D0_chbilldrillboulder;
}

void func_80800024_chbilldrillboulder(param_0) Actor *param_0;
{
    s32 local_0;
    f32 *local_4;
    u8 *local_5;
    f32 local_1[3];
    s32 local_2;
    f32 local_3[3];
    local_0 = func_808004D4_chbilldrillboulder((u8 *) param_0);
    local_2 = param_0->unk6C_9;
    local_4 = param_0->position;
    if (!(local_2 ^ 0x322))
        local_5 = D_80800684_chbilldrillboulder;
    else
        local_5 = D_80800618_chbilldrillboulder;
    func_800BABB8(0, local_4, local_4, param_0->scale, local_5);
    _subaddieaudioquick_entrypoint_2(param_0, local_4, D_808006F0_chbilldrillboulder);
    if (local_0) {
        func_800DA544(local_0);
        if (local_0 == 0x514) {
            if (param_0->unk64_20) {
                func_800EE7F8(local_1, local_4);
                func_800EF1B8(local_1, param_0->rotation[1] - 70.0f, 450.0f);
                func_800F77E8(func_800F54E4(), local_1);
            }
            func_800F7F98(func_800F54E4(), 1);
            _capod_entrypoint_21(_subaddiefind_entrypoint_2(0x117, 0)->unk0, 0, 0x1D, 0);
            func_800DA544(0x5B);
        }
    }
    if (param_0->unk6C_9 == 0x3CF) {
        local_2 = -1;
        switch (param_0->unk74_7) {
            case 0x33:
                func_800D1000(param_0->unk6C_0, 4, local_4, 0, 0);
                break;
            case 0x34:
                local_2 = 2;
                break;
            case 0x35:
                local_2 = 0x15;
                break;
            case 0x36:
                local_2 = 0x16;
                break;
            case 0x37:
                local_2 = 0x17;
                break;
            case 0x38:
                func_800D1000(param_0->unk6C_0, 2, local_4, 0, 0);
                break;
        }
        if (local_2 != -1) {
            func_800EE7F8(local_3, local_4);
            local_3[1] += 0.5f * func_80103EF4(param_0);
            _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_9, local_2, ((s32 *) local_3)[0],
                                        ((s32 *) local_3)[1], ((s32 *) local_3)[2]);
        }
    }
}

int func_8080026C_chbilldrillboulder(Actor *param_0)
{
    if (((((((((((*(u16 *) ((char *) param_0 + 0x72) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
               0xFFFFFFFFu) &
              0xFFFFFFFFu) &
             0xFFFFFFFFu) &
            0xFFFFFFFFu) &
           0xFFFFFFFFu) &
          0xFFFFFFFFu) >>
         (10 & 0xFFFFFFFFFFFFFFFFu)) == 2) {
        if (_subaddieDll_entrypoint_6(param_0, 0xB)) {
            func_8010A570(param_0);
            _chexploder_entrypoint_3(param_0, (Actor *) ((char *) param_0 + 4), 2);
        }
    }
}

void func_808002C4_chbilldrillboulder(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_808004D4_chbilldrillboulder();
    if ((local_0 != 0) && (func_800DA298(local_0) != 0)) {
        func_800FFAB0(param_0);
        return;
    }
    if (param_0->unk6C_9 == 0x3CF) {
        local_1 = param_0->unk74_7 - 0x32;
        switch (local_1) {
            case 1:
                param_0->unk6C_0 =
                    _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x201, param_0));
                if (func_800D0A9C(param_0->unk6C_0, 4) != 0) {
                    func_800FFAB0(param_0);
                }
                break;
            case 6:
                param_0->unk6C_0 =
                    _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x1F7, param_0));
                if (func_800D0A9C(param_0->unk6C_0, 2) != 0) {
                    func_800FFAB0(param_0);
                }
        }
    }
}

s32 func_808003F0_chbilldrillboulder(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    switch (param_1) {
        case 0x3F:
            local_0 = *(s32 *) &param_2;
            if (param_0->unk70_10 != 2) {
                if (_subaddieDll_entrypoint_5(param_0, local_0)) {
                    param_0->unk64_20 = 1;
                    func_80103110(param_0, 1);
                    func_80101FDC(param_0, 2);
                }
            }
            break;
        case 0x40:
            func_8010A570(param_0);
            _chexploder_entrypoint_3(param_0, param_0->position, 2);
            break;
        case 0x90:
            func_80800024_chbilldrillboulder(param_0);
            func_800FFAB0(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808004D4_chbilldrillboulder(param_0)
u8 *param_0;
{
    s32 local_0;

if (((u32) (*(s32 *) ((s8 *) param_0 + 0x6C) << 0xB) >> 0x14) == 0x3CF) {
    return 0;
}

local_0 = ((u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7) - 0x33;

if ((local_0 < 0) || (local_0 >= 0x1E)) {
    return 0;
}

return local_0 + 0x514;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_10();
int D_80800540_chbilldrillboulder[18] = {0x157010F,
                                         0x6820001,
                                         0x0,
                                         (u32) func_8080026C_chbilldrillboulder,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000800,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_808002C4_chbilldrillboulder,
                                         (u32) func_80107C2C,
                                         (u32) _bsbtrot_entrypoint_10,
                                         (u32) func_808003F0_chbilldrillboulder,
                                         0x0};
void *D_80800588_chbilldrillboulder = (void *) 0x01570322;
static u32 D_80800588_chbilldrillboulder_rest[17] = {0x7930001,
                                                     0x0,
                                                     (u32) func_8080026C_chbilldrillboulder,
                                                     (u32) func_80105834,
                                                     (u32) func_80101870,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x40000800,
                                                     0x0,
                                                     (u32) func_80108ED0,
                                                     0x0,
                                                     (u32) func_808002C4_chbilldrillboulder,
                                                     (u32) func_80107C2C,
                                                     (u32) _bsbtrot_entrypoint_10,
                                                     (u32) func_808003F0_chbilldrillboulder,
                                                     0x0};
int D_808005D0_chbilldrillboulder[18] = {0x15703CF,
                                         0x6820001,
                                         0x0,
                                         (u32) func_8080026C_chbilldrillboulder,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000800,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_808002C4_chbilldrillboulder,
                                         (u32) func_80107C2C,
                                         (u32) _bsbtrot_entrypoint_10,
                                         (u32) func_808003F0_chbilldrillboulder,
                                         0x0};
u8 D_80800618_chbilldrillboulder[108] = {
    0x4,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x2, 0xCC, 0x3,  0x66, 0x0,  0x15, 0x0,  0x0,
    0x0,  0x99, 0x0, 0x22, 0x1,  0x80, 0x2, 0x0,  0x4, 0x80, 0x6,  0x0,  0x0,  0x19, 0x0,  0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0, 0x64, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x0,  0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0,  0x64, 0x4,  0x1A, 0xF,  0x10,
    0x0,  0x1D, 0x6, 0xA0, 0x0,  0x14, 0x0, 0x2D, 0x1, 0x90, 0x2,  0x58, 0x0,  0x1B, 0xFC, 0xE0,
    0xFD, 0xA8, 0x0, 0x22, 0x0,  0xB3, 0x0, 0xCC, 0x0, 0xB3, 0x0,  0xB3, 0x0,  0x1E, 0x0,  0x32,
    0x0,  0x32, 0x0, 0xD,  0x0,  0x4B, 0xF, 0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_80800684_chbilldrillboulder[108] = {
    0x4,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x2, 0xCC, 0x3,  0x66, 0x0,  0x15, 0x0,  0x0,
    0x0,  0x99, 0x0, 0x22, 0x1,  0x80, 0x2, 0x0,  0x4, 0x80, 0x6,  0x0,  0x0,  0x19, 0x0,  0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0, 0x64, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x0,  0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0,  0x64, 0x4,  0x1A, 0xF,  0x10,
    0x0,  0x1D, 0x6, 0x59, 0x0,  0x14, 0x0, 0x2D, 0x1, 0x90, 0x2,  0x58, 0x0,  0x1B, 0xFC, 0xE0,
    0xFD, 0xA8, 0x0, 0x22, 0x0,  0xB3, 0x0, 0xCC, 0x0, 0xB3, 0x0,  0xB3, 0x0,  0x1E, 0x0,  0x32,
    0x0,  0x32, 0x0, 0xD,  0x0,  0x4B, 0xF, 0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_808006F0_chbilldrillboulder[32] = {
    0x0, 0x13, 0x4, 0x13, 0x0, 0xA, 0x0, 0xE6, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xE2,
    0x9, 0xC4, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
