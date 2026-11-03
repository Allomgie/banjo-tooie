#include "common.h"

extern u8 D_808005C0_chfactorytrashbelt[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern f32 func_800D91B8(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_80100094(Actor *, u32);
extern Vec3f D_808005D4_chfactorytrashbelt;
extern Vec3f D_808005E0_chfactorytrashbelt;
extern void func_801017D0(void);
extern void func_800DE498(s32, f32 *, f32 *, f32, s32, void *);
typedef struct {
    s32 local_0;
    s16 local_1[7];
} TrashBeltState;
extern s16 func_80100D24(s32, u16, s32, s32, u16, s32);
extern void func_80100E18(s16);
extern s16 func_80100A74(s16, s32);
extern void func_800DF818(void *);
extern void func_800DF660(s32, s32, s32, u8);
extern void *func_80100AC4(s16);
extern void func_800DF720(void *);
extern void *D_808005EC_chfactorytrashbelt;
extern void func_80105834(), func_80107C2C(), func_80800000_chfactorytrashbelt(),
    func_808001EC_chfactorytrashbelt();

void func_80800000_chfactorytrashbelt(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;

    func_800F5A00(func_800F54E4(), local_0);
    if (local_0[0] < 500.0f && local_0[0] > -500.0f && local_0[2] < 600.0f &&
        local_0[2] > -600.0f) {
        if (func_800F6C5C(func_800F54E4())) {
            local_1 = func_800138D0(func_800F10B4(local_0[0], -700.0f, 700.0f, 0.0f, 1.5f) *
                                    360.0f * 7.0f);
            func_800EFA4C(local_0, 200.0f / ((f32) param_0->unk74_7 / 70.0f), local_1 * 1.5f * 5.0f,
                          0.0f);
            func_800F48BC(func_800F54E4(), local_0);
        }
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808005C0_chfactorytrashbelt);
    local_1 = func_800D91B8(&param_0->unk58);
    local_2 = (f32) param_0->unk74_7 / 70.0f;
    if (local_1 >= local_2) {
        param_0->unk58 -= local_2;
    }
}

void func_808001EC_chfactorytrashbelt(param_0, param_1) Actor *param_0;
s32 param_1;
{
    f32 local_2;
    f32 local_3;
    s32 *local_4;
    s32 local_5;
    Vec3f local_0;
    Vec3f local_1;

    local_4 = func_80100094(param_0, 0);
    local_2 = func_800F10B4(param_0->unk58, 0.0f, (f32) param_0->unk74_7 / 70.0f, 0.0f, 200.0f);
    for (local_5 = 0; local_5 < 7; local_5++) {
        local_0 = D_808005D4_chfactorytrashbelt;
        local_1 = D_808005E0_chfactorytrashbelt;
        local_0.f[0] += (f32) local_5 * 200.0f + local_2;
        local_3 = func_800F10B4(local_0.f[0], -700.0f, 700.0f, 0.0f, 1.0f);
        local_0.f[1] = param_0->position[1] + func_800138D0(local_3 * 360.0f * 7.0f) * 1.5f;
        local_1.f[0] = func_800138D0(local_3 * 360.0f * 7.0f);
        *local_4 = local_5;
        func_800DF830(1);
        func_800DF47C(func_801017D0, param_0);
        func_800DE498(param_1, local_0.f, local_1.f, 1.0f, 0, func_8010347C(param_0->unk0));
    }
}

s32 func_8080041C_chfactorytrashbelt(Actor *param_0, s32 param_1, s32 param_2)
{
    TrashBeltState *local_0;
    s32 local_1;
    s16 local_2;
    s32 p2;
    s32 i;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x95:
            for (local_1 = 0; local_1 < 7; local_1++) {
                local_0->local_1[local_1] = 0;
            }
            break;
        case 0x29:
            p2 = param_2;
            if (&param_2) {
            }
            for (i = 0; i < 7; i++) {
                local_0->local_1[i] = func_80100D24(p2, *(u16 *) ((u8 *) param_0->unk0 + 0x14), 1,
                                                    1, *(u16 *) ((u8 *) param_0->unk0 + 0x16), 0);
            }
            break;
        case 0x2A:
            for (local_1 = 0; local_1 < 7; local_1++) {
                if (local_0->local_1[local_1]) {
                    func_80100E18(local_0->local_1[local_1]);
                    local_0->local_1[local_1] = 0;
                }
            }
            break;
        case 0x1F:
            local_2 = local_0->local_1[local_0->local_0];
            func_800DF818(func_80100A74(local_2, 0));
            func_800DF660(2, -2, 0, *(u8 *) ((u8 *) param_0 + 0x9B));
            func_800DF720(func_80100AC4(local_2));
            return 1;
        default:
            return 0;
    }
    return 1;
}

int chfactorytrashbelt_entrypoint_0()
{
    return &D_808005EC_chfactorytrashbelt;
}

u8 D_808005C0_chfactorytrashbelt[20] = {0x0,  0x13, 0x5, 0x27, 0x0, 0xA,  0x0,  0x80, 0x0, 0x16,
                                        0x46, 0x50, 0x0, 0x1,  0x0, 0xC8, 0x17, 0x70, 0x0, 0x0};
Vec3f D_808005D4_chfactorytrashbelt = {-7e+02f, 0.0f, 0.0f};
Vec3f D_808005E0_chfactorytrashbelt = {0.0f, 9e+01f, 0.0f};
void *D_808005EC_chfactorytrashbelt = (void *) 0x01580403;
static u32 D_808005EC_chfactorytrashbelt_rest[20] = {0x87D0001,
                                                     0x0,
                                                     (u32) func_80800000_chfactorytrashbelt,
                                                     (u32) func_80105834,
                                                     (u32) func_808001EC_chfactorytrashbelt,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x400,
                                                     0x0,
                                                     0x0,
                                                     0x140000,
                                                     0x0,
                                                     (u32) func_80107C2C,
                                                     0x80000402,
                                                     (u32) func_8080041C_chfactorytrashbelt,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x0};
