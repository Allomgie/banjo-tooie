#include "common.h"

extern void func_80103110();
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80800288_chfantasysafeswitch[];

void func_80800000_chfantasysafeswitch(u8 *param_0)
{
    param_0[0x65] &= ~0x10;
    func_80103110(param_0, 0);
}

s32 func_8080002C_chfantasysafeswitch(s32 param_0)
{
    if (((((u16) *(u16 *) (param_0 + 0x72) & 0xFFFFFFFF) >> 0xA) == 2) && (func_80101DDC() != 0)) {
        func_80102424(param_0, 3);
    }
}

s32 func_80800070_chfantasysafeswitch(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_2;
    f32 local_0[3];
    f32 local_1[3];

    switch (param_1) {
        case 0x40:
            if (param_0->unk70_10 == 1) {
                local_2 = _subaddiefind_entrypoint_2(0x2B2, 0);
                if (local_2 != NULL) {
                    func_800EE7F8(local_0, local_2->position);
                    func_800EFA4C(local_1, param_0->position[0], param_0->position[1] + 40.0f,
                                  param_0->position[2]);
                    if (func_800C6A7C(local_0, local_1, &param_0->actorData[4], 0)) {
                        return 0;
                    }
                }
                func_80102424(param_0, 2);
                func_80103110(param_0, 1);
                param_0->unk64_20 = 1;
            }
            return 1;
        case 0x39:
            if (param_0->unk64_20) {
                if (func_800EA05C() == 0x13A) {
                    func_80101180(0x417, 0x49, param_0->unk74_7 + 0x1F);
                } else {
                    _glcutDll_entrypoint_6(0x13A, param_0->unk74_7 + 0x1F);
                }
                param_0->unk64_20 = 0;
                func_80102424(param_0, 3);
                return 1;
            }
            return 0;
        case 0x95:
            if (func_800DA298(param_0->unk74_7 + 0x357)) {
                func_80102424(param_0, 3);
                return 1;
            }
            func_80102424(param_0, 1);
            return 1;
        case 0x1F:
            func_801015D0(param_0);
            func_800DF744(1, param_0->unk74_7 - 0x31);
            return 1;
        default:
            return 0;
    }
}

int *chfantasysafeswitch_entrypoint_0()
{
    return &D_80800288_chfantasysafeswitch;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800260_chfantasysafeswitch[10] = {0x0,      0x0,        0x3F800000, 0xD40044,   0x3F800000,
                                          0xD40002, 0x3F800000, 0xD40084,   0x3F800000, 0xD40084};
int D_80800288_chfantasysafeswitch[18] = {0x1210418,
                                          0x8DB0001,
                                          (u32) &D_80800260_chfantasysafeswitch,
                                          (u32) func_8080002C_chfantasysafeswitch,
                                          (u32) func_80105834,
                                          (u32) func_801018A4,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x808,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x0,
                                          (u32) func_80800000_chfantasysafeswitch,
                                          (u32) func_80107C2C,
                                          -0x7FFFDC00,
                                          (u32) func_80800070_chfantasysafeswitch,
                                          0x0};
