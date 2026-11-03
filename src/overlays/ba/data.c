#include "overlays/ba/data.h"

s32 func_80800000_badata(PlayerState *self)
{
    s32 sp1C = bs_getCurrentState(self);
    switch (func_800A3274(self)) {
        case TRANSFORM_2_SNOWBALL:
            return 2;

        case TRANSFORM_6_BEE:
            if (func_8009CA70(self, sp1C, 0x4000)) {
                return 0x1E;
            }
            return 0xB;

        case TRANSFORM_7_WASHINGMACHINE:
            return 0;

        case TRANSFORM_8_STONY:
            return 0xE;

        case TRANSFORM_A_BANJO:
            if (func_8009E71C(self, 0x12)) {
                return 0xA;
            } else if (func_8009E71C(self, 0x13)) {
                return 0x1F;
            } else if (func_8009E71C(self, 0x14)) {
                return 0x20;
            } else if (func_8009CA70(self, sp1C, 0x400)) {
                return 0x1C;
            } else if (player_inWater(self)) {
                if (func_800F8B88() == 3) {
                    return 0x21;
                } else {
                    switch (func_800F40EC(self)) {
                        case 2:
                            return 0x5;
                        default:
                        case 1:
                            return 0x4;
                    }
                }
            } else {
                return 0xF;
            }
        case TRANSFORM_B_KAZOOIE:
            if (func_8009CA70(self, sp1C, 0x200)) {
                return 0x22;
            } else if (func_8009CBDC(self, sp1C) == 0x9) {
                return 0x3;
            } else if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x1;
            } else if (func_800F8B88() == 3) {
                return 0x1A;
            } else if (player_inWater(self)) {
                return 0x1B;
            } else {
                return 0x10;
            }

        case TRANSFORM_D_MUMBO:
            if (player_inWater(self)) {
                return 0x12;
            } else {
                return 0x11;
            }

        case TRANSFORM_E_GOLDENGOLIATH:
            return 0x13;

        case TRANSFORM_F_DETONATOR:
            return 0x14;

        case TRANSFORM_10_VAN:
            return 0x15;

        case TRANSFORM_C_SUB:
            return 0x16;

        case TRANSFORM_11_CLOCKWORK:
            return 0x17;

        case TRANSFORM_12_TREXSMALL:
            return 0x18;

        case TRANSFORM_13_TREXLARGE:
            return 0x19;

        case TRANSFORM_9_FIRSTPERSON:
            return 0x1D;

        case TRANSFORM_1_BK:
        default:
            if (func_8009CBDC(self, sp1C) == 2) {
                return 0x23;
            } else if (func_8009CBDC(self, sp1C) == 0xA) {
                return 0xC;
            } else if (func_8009CBDC(self, sp1C) == 0x9) {
                return 0x7;
            } else if (func_8009CA70(self, sp1C, 0x40)) {
                return 0x8;
            } else if (func_8009CA70(self, sp1C, 0x400)) {
                return 0x1C;
            } else if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x9;
            } else if (func_8009EA4C() == 5) {
                return 0x5;
            } else if (func_800F3ED0(self) == 3) {
                return 0xD;
            } else if (player_inWater(self)) {
                switch (func_800F40EC(self)) {
                    case 2:
                        return 0x5;
                    default:
                    case 1:
                        return 0x4;
                }
            } else {
                return 0x6;
            }
    }
}

s32 func_80800388_badata(PlayerState *self)
{
    s32 sp1C;
    f32 sp18;

    sp1C = func_8009EA4C();
    switch (func_800A3274(self)) {
        case TRANSFORM_2_SNOWBALL:
            return 2;

        case TRANSFORM_6_BEE:
            if (sp1C == 4) {
                return 0x1E;
            }
            return 0xB;

        case TRANSFORM_7_WASHINGMACHINE:
            return 0;

        case TRANSFORM_8_STONY:
            return 0xE;

        case TRANSFORM_A_BANJO:
            if (player_inWater(self)) {
                if (func_800F8B88() == 3) {
                    return 0x21;
                }

                sp18 = func_8009C150(self);
                if (func_800964DC(self) - 80.0f < sp18) {
                    return 0x4;
                }

                return 0x5;
            }

            switch (sp1C) {
                case 0x3:
                    return 0xA;
                case 0x6:
                    return 0x1F;
                case 0x7:
                    return 0x20;
            }
            return 0xF;

        case TRANSFORM_B_KAZOOIE:
            if (sp1C == 4) {
                return 0x3;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON) != 0.0f) {
                return 0x10;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x1;
            }

            if (func_800F8B88() == 3) {
                return 0x1A;
            }

            if (player_inWater(self)) {
                return 0x1B;
            }

            return 0x10;

        case TRANSFORM_D_MUMBO:
            if (player_inWater(self)) {
                return 0x12;
            }
            return 0x11;

        case TRANSFORM_E_GOLDENGOLIATH:
            return 0x13;

        case TRANSFORM_F_DETONATOR:
            return 0x14;

        case TRANSFORM_10_VAN:
            return 0x15;

        case TRANSFORM_C_SUB:
            return 0x16;

        case TRANSFORM_11_CLOCKWORK:
            return 0x17;

        case TRANSFORM_12_TREXSMALL:
            return 0x18;

        case TRANSFORM_13_TREXLARGE:
            return 0x19;

        case TRANSFORM_9_FIRSTPERSON:
            return 0x1D;

        case TRANSFORM_1_BK:
        default:
            if (player_inWater(self)) {
                sp18 = func_8009C150(self);
                if (func_800964DC(self) - 95.0f < sp18) {
                    return 4;
                }
                return 5;
            }
            if (sp1C == 4) {
                return 0x7;
            }
            if (sp1C == 5) {
                return 0x5;
            }
            if (sp1C == 2) {
                return 0x8;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON) != 0.0f) {
                return 0x8;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x9;
            }
            return 0x6;
    }
}

void func_808006AC_badata(PlayerState *self, BaData_1 *arg1, s32 *arg2, f32 *arg3)
{
    s32 tmp_v0 = func_80800000_badata(self);
    *arg2 = arg1[tmp_v0].unk2;
    *arg3 = arg1[tmp_v0].unk4;
}

void badata_entrypoint_0(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80801EF8_badata, assetId, arg2);
}

void badata_entrypoint_1(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80801A78_badata, assetId, arg2);
}

void badata_entrypoint_2(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80801B98_badata, assetId, arg2);
}

void badata_entrypoint_3(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80801DD8_badata, assetId, arg2);
}

void badata_entrypoint_4(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80802018_badata, assetId, arg2);
}

void badata_entrypoint_5(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80801CB8_badata, assetId, arg2);
}

void badata_entrypoint_6(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_3 *tmp_v1 = &D_80801718_badata[tmp_v0];
    *arg1 = tmp_v1->unk2;
    *arg2 = tmp_v1->unk4;
    *arg3 = tmp_v1->unk8;
    *arg4 = tmp_v1->unkC;
}

void badata_entrypoint_7(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80801958_badata, assetId, arg2);
}

void badata_entrypoint_8(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3)
{
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802648_badata[tmp_v0];
    *arg1 = tmp_v1->unk0;
    *arg2 = tmp_v1->unk4;
    *arg3 = tmp_v1->unk8;
}

void badata_entrypoint_9(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80802138_badata, assetId, arg2);
}

void badata_entrypoint_10(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80802378_badata, assetId, arg2);
}

void badata_entrypoint_11(PlayerState *self, AssetId *assetId, f32 *arg2)
{
    func_808006AC_badata(self, D_80802258_badata, assetId, arg2);
}

void badata_entrypoint_12(PlayerState *self, s32 *arg1, f32 *arg2)
{
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802498_badata[tmp_v0];
    *arg1 = tmp_v1->unk2;
    *arg2 = tmp_v1->unk8;
}

void badata_entrypoint_13(PlayerState *self, s32 *arg1, f32 *arg2)
{
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802498_badata[tmp_v0];
    *arg1 = tmp_v1->unk0;
    *arg2 = tmp_v1->unk4;
}

s32 badata_entrypoint_14(PlayerState *self)
{
    return D_80801640_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_15(PlayerState *self)
{
    return D_80801664_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_16()
{
    return 11;
}

s32 func_80800AA4_badata(PlayerState *self, BaData_5 *arg1, s32 index, s32 *arg3, f32 *arg4,
                         s32 *arg5)
{
    s32 max;
    s32 valid;
    s32 tmp_v0;

    valid = 1;
    tmp_v0 = func_80800000_badata(self);
    max = arg1[tmp_v0].count;
    if (index >= max) {
        index = 0;
        valid = 0;
    }
    *arg3 = arg1[tmp_v0].unk0[index].unk0;
    *arg4 = arg1[tmp_v0].unk0[index].unk4 + arg1[tmp_v0].unk8;
    *arg5 = arg1[tmp_v0].unk0[index].unk2;
    return valid;
}

void badata_entrypoint_17(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4)
{
    func_80800AA4_badata(self, D_808010C8_badata, index, arg2, arg3, arg4);
}

f32 badata_entrypoint_18(PlayerState *self)
{
    return D_808010C8_badata[func_80800000_badata(self)].unk8;
}

void badata_entrypoint_19(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4)
{
    func_80800AA4_badata(self, D_80801298_badata, index, arg2, arg3, arg4);
}

s32 badata_entrypoint_20(PlayerState *self)
{
    if (0.5f < func_800DC0C0()) {
        return D_80801568_badata[func_80800000_badata(self)].unk2;
    } else {
        return D_80801568_badata[func_80800000_badata(self)].unk4;
    }
}

s32 badata_entrypoint_21(PlayerState *self)
{
    return D_80801A78_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_22(PlayerState *self)
{
    return D_80801718_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_23(PlayerState *self)
{
    return D_80802018_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_24(PlayerState *self)
{
    return D_808014D8_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_25(PlayerState *self)
{
    return D_80801520_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_26(PlayerState *self)
{
    return D_80801568_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_27(PlayerState *self)
{
    func_80800000_badata(self);
    return D_80801448_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_28(PlayerState *self)
{
    return D_80801688_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_29(PlayerState *self)
{
    return D_80802138_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_30(PlayerState *self, s32 arg1)
{
    switch (arg1) {
        case 1:
            return 0x73;

        case 2:
            return 0x74;

        case 3:
            return 0x75;

        case 4:
            return 0x74;
    }
    return 0;
}

s32 badata_entrypoint_31(PlayerState *self)
{
    return D_80802378_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_32(PlayerState *self)
{
    return D_80802258_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_33(PlayerState *self)
{
    switch (func_8009EA64()) {
        case 0x305:
            return 0x12A;

        case 0x171:
            return 0x7C;

        case 0x2A2:
            return 0x12B;

        case 0x38A:
            return 0xB7;
    }
    return 0xB7;
}

s32 badata_entrypoint_34(PlayerState *self)
{
    return D_80801490_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_35(PlayerState *self)
{
    return D_80801490_badata[func_80800388_badata(self)];
}

extern void _bswalk_entrypoint_22();
extern void _bsfirstp_entrypoint_25();
u32 D_80801060_badata[8] = {0x57855F0, 0x3F800000, 0x57955F0, 0x3F800000,
                            0x57A55F0, 0x3F800000, 0x57B55F0, 0x3F800000};
u32 D_80801080_badata[8] = {0x459355F0, 0x3F800000, 0x459455F0, 0x3F800000,
                            0x459555F0, 0x3F800000, 0x459655F0, 0x3F800000};
u32 D_808010A0_badata[4] = {0x50F55F0, 0x3F800000, 0x51055F0, 0x3F800000};
u32 D_808010B0_badata[6] = {0x56755F0, 0x3F99999A, 0x56755F0, 0x3FA00000, 0x56755F0, 0x3FA66666};
BaData_5 D_808010C8_badata[36] = {
    (void *) &D_80801060_badata, 0x4, 0.81f, (void *) &D_80801080_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.81f, (void *) &D_80801080_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.81f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.81f, (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801080_badata, 0x4, 0.0f,  (void *) &D_808010A0_badata, 0x2, 0.0f,
    (void *) &D_808010A0_badata, 0x2, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.81f, (void *) &D_80801060_badata, 0x4, 0.81f,
    (void *) &D_80801060_badata, 0x4, 0.81f, (void *) &D_80801080_badata, 0x4, 0.4f,
    (void *) &D_808010B0_badata, 0x3, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801080_badata, 0x4, 0.0f,  (void *) &D_80801080_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.8f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801060_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f,
    (void *) &D_80801080_badata, 0x4, 0.0f,  (void *) &D_80801060_badata, 0x4, 0.0f};
u32 D_80801278_badata[2] = {0x43D55F0, 0x3F800000};
u32 D_80801280_badata[2] = {0x443E6D60, 0x3F800000};
u32 D_80801288_badata[4] = {0x51155F0, 0x3F800000, 0x4D855F0, 0x3FACCCCD};
BaData_5 D_80801298_badata[36] = {
    (void *) &D_80801278_badata, 0x1, 0.81f, (void *) &D_80801280_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.81f, (void *) &D_80801280_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.81f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.81f, (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801280_badata, 0x1, 0.0f,  (void *) &D_80801288_badata, 0x1, 0.0f,
    (void *) &D_80801288_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.81f,
    (void *) &D_80801278_badata, 0x1, 0.81f, (void *) &D_80801278_badata, 0x1, 0.81f,
    (void *) &D_80801278_badata, 0x1, 0.81f, (void *) &D_80801280_badata, 0x1, 0.4f,
    (void *) &D_808010B0_badata, 0x3, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801280_badata, 0x1, 0.0f,  (void *) &D_80801280_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.81f, (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801278_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f,
    (void *) &D_80801280_badata, 0x1, 0.0f,  (void *) &D_80801278_badata, 0x1, 0.0f};
s16 D_80801448_badata[36] = {0x8E,  0x56, 0x184, 0x173, 0x56, 0xBF, 0x56,  0x18,  0x56,
                             0x56,  0x7E, 0xA3,  0x56,  0x56, 0xB0, 0x56,  0x13A, 0xEC,
                             0xEC,  -0x1, 0x10A, 0x118, 0x83, -0x1, 0x141, 0x14D, 0x168,
                             0x13A, 0x56, -0x1,  0xC0,  0x56, 0x56, 0xBF,  0x13A, 0x56};
s16 D_80801490_badata[36] = {0x32,  0x48,  0x17D, 0x162, 0x2D,  0x2B,  0x1,   0x24,  0x15,
                             0x26,  0x165, 0x85,  0x4F,  0x1B,  0xB3,  0x1,   0xBB,  0xE5,
                             0xF0,  0xF9,  0x10C, 0x11A, 0x131, 0x136, 0x145, 0x151, 0x154,
                             0x15D, 0x3A,  0xCC,  0x8C,  0x16C, 0x16F, 0x2B,  0xBE,  0x1};
s16 D_808014D8_badata[36] = {0x36, 0x48,  0x180, 0xDF,  0x2F,  0x2F,  0x2F,  0x2F,  0x71,
                             0x2F, 0x166, 0x88,  0x2F,  0x2F,  0xAD,  0x2F,  0xDF,  0xE9,
                             0xE9, 0xF9,  0x106, 0x114, 0x131, 0x133, 0x13E, 0x14A, 0x154,
                             0xDF, 0x3A,  0xCC,  0x88,  0x2F,  0x2F,  0x2F,  0xDF,  0x2F};
s16 D_80801520_badata[36] = {0x35, 0x4A,  0x17F, 0xBD,  0x5,   0x5,   0x5,   0x5,   0x8,
                             0x5,  0x169, 0x87,  0x5,   0x5,   0xAE,  0x5,   0xBD,  0xE8,
                             0xE8, 0xF9,  0x107, 0x115, 0x131, 0x134, 0x13F, 0x14B, 0x154,
                             0xBD, 0x3A,  0xCC,  0x87,  0x5,   0x5,   0x5,   0xBD,  0x5};
BaData_2 D_80801568_badata[36] = {
    0x3E,  0x43,  0x43,  0x100, 0x101, 0x101, 0x181, 0x182, 0x182, 0x179, 0x101, 0x101,
    0xE,   0x102, 0x41,  0x7F,  0x102, 0x41,  0xE,   0x102, 0x41,  0x91,  0x102, 0x41,
    0x7B,  0x102, 0x41,  0xE,   0x102, 0x41,  0x7D,  0x102, 0x102, 0x89,  0x8A,  0x8A,
    0xE,   0x102, 0x41,  0xE,   0x102, 0x41,  0xAF,  0xAB,  0xAB,  0xE,   0x103, 0x103,
    0x100, 0x101, 0x101, 0xEA,  0xEB,  0xEB,  0xEA,  0xEB,  0xEB,  0xE,   0x102, 0x41,
    0x109, 0x104, 0x104, 0x117, 0x112, 0x112, 0x12D, 0x12E, 0x12E, 0x12D, 0x12E, 0x12E,
    0x140, 0x13C, 0x13C, 0x14C, 0x148, 0x148, 0x15A, 0x12E, 0x12E, 0x100, 0x101, 0x101,
    0xE,   0x102, 0x41,  0xCC,  0xCC,  0xCC,  0x18C, 0x8A,  0x8A,  0xE,   0x102, 0x41,
    0xE,   0x102, 0x41,  0x7F,  0x102, 0x41,  0x15B, 0x101, 0x101, 0xE,   0x102, 0x41};
u8 D_80801640_badata[36] = {0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1,
                            0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x0, 0x1,
                            0x1, 0x1, 0x0, 0x0, 0x1, 0x0, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0};
u8 D_80801664_badata[36] = {0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0,
                            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0};
s32 D_80801688_badata[36] = {0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             (u32) _bswalk_entrypoint_22,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             (u32) _bswalk_entrypoint_22,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             (u32) _bsfirstp_entrypoint_25,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             0x0,
                             (u32) _bswalk_entrypoint_22};
BaData_3 D_80801718_badata[36] = {
    0x5D,  0x355, 1.0f,  0.5f,  0.5f,  0x93,  0x13C, 0.43f, 0.0f,  1.0f,  0x183, 0x5F,  0.3f,
    0.0f,  1.0f,  0x93,  0x13C, 0.43f, 0.0f,  1.0f,  0x98,  0x68,  0.35f, 0.0f,  1.0f,  0x98,
    0x68,  0.35f, 0.0f,  1.0f,  0x98,  0x68,  0.35f, 0.0f,  1.0f,  0x98,  0x68,  0.35f, 0.0f,
    1.0f,  0x98,  0x68,  0.35f, 0.0f,  1.0f,  0x9B,  0x68,  0.35f, 0.0f,  1.0f,  0x98,  0x68,
    0.35f, 0.0f,  1.0f,  0x9D,  0x1E2, 1.0f,  0.34f, 0.34f, 0x98,  0x68,  0.35f, 0.0f,  1.0f,
    0x98,  0x68,  0.35f, 0.0f,  1.0f,  0xAC,  0x122, 1.0f,  0.63f, 0.63f, 0x98,  0x68,  0.35f,
    0.0f,  1.0f,  0x93,  0x13C, 0.43f, 0.0f,  1.0f,  0xF5,  0xBB,  1.0f,  0.57f, 0.57f, 0xF3,
    0xBB,  1.0f,  0.57f, 0.57f, 0xFE,  0x1EF, 1.0f,  0.5f,  0.5f,  0x105, 0xE5,  1.0f,  0.5f,
    0.5f,  0x113, 0xED,  1.0f,  0.35f, 0.35f, 0x130, 0x12F, 0.5f,  0.5f,  0.5f,  0x93,  0x13C,
    0.43f, 0.0f,  1.0f,  0x13D, 0x1D1, 1.0f,  0.71f, 0.71f, 0x149, 0x1D1, 1.0f,  0.71f, 0.71f,
    0x93,  0x13C, 0.43f, 0.0f,  1.0f,  0x93,  0x13C, 0.43f, 0.0f,  1.0f,  0x98,  0x68,  0.35f,
    0.0f,  1.0f,  0xCE,  0x68,  0.35f, 0.0f,  1.0f,  0x9D,  0x1E2, 1.0f,  0.34f, 0.34f, 0x98,
    0x68,  0.35f, 0.0f,  1.0f,  0x98,  0x68,  0.35f, 0.0f,  1.0f,  0x98,  0x68,  0.35f, 0.0f,
    1.0f,  0x93,  0x13C, 0.43f, 0.0f,  1.0f,  0x98,  0x68,  0.35f, 0.0f,  1.0f};
BaData_1 D_80801958_badata[36] = {
    0x5D,  0x356, 0.38f, 0x5C,  0x280, 0.38f, 0x183, 0x5E,  0.38f, 0x17A, 0xAA,  0.38f,
    0x96,  0x57,  1.2f,  0x97,  0x70,  2.0f,  0x98,  0x29,  0.38f, 0x99,  0x38,  0.38f,
    0x9A,  0x26,  0.38f, 0x9B,  0x41,  0.38f, 0x6E,  0x289, 1.0f,  0x9D,  0x1DE, 3.0f,
    0x98,  0xB2,  0.38f, 0xA4,  0x23,  0.38f, 0xAC,  0x63,  0.38f, 0x98,  0x29,  0.38f,
    0x93,  0xA4,  0.38f, 0xF5,  0xBC,  0.38f, 0xF3,  0xB5,  0.38f, 0xFE,  0x1EE, 6.5f,
    0x105, 0xE5,  0.38f, 0x113, 0xEC,  0.38f, 0x130, 0x12E, 0.38f, 0x138, 0xEC,  0.38f,
    0x13D, 0x1D2, 8.5f,  0x149, 0x1D2, 8.5f,  0x156, 0x132, 0.38f, 0x66,  0x139, 0.38f,
    0x40,  0x73,  0.38f, 0xCE,  0x30E, 0.38f, 0x9D,  0x1DC, 0.38f, 0x98,  0x29,  0.38f,
    0x98,  0x29,  0.38f, 0x97,  0x70,  2.0f,  0x18E, 0x13D, 0.8f,  0x98,  0x29,  0.38f};
BaData_1 D_80801A78_badata[36] = {
    0x5D,  0x359, 0.4f,  0x5C,  0x280, 0.8f,  0x183, 0x5F,  0.6f,  0x17A, 0xAA,  0.62f,
    0x96,  0x39,  0.8f,  0x97,  0x71,  0.75f, 0x98,  0x3,   0.43f, 0x99,  0x38,  0.62f,
    0x9A,  0x15,  0.53f, 0x9B,  0x42,  0.8f,  0x6E,  0x144, 0.9f,  0x9D,  0x1DD, 0.38f,
    0x98,  0x3,   0.43f, 0xA4,  0x11,  0.53f, 0xAC,  0x62,  0.4f,  0x98,  0x3,   0.43f,
    0x93,  0xA7,  0.43f, 0xF5,  0xB3,  0.43f, 0xF3,  0x9C,  0.75f, 0xFE,  0x1E5, 0.8f,
    0x105, 0xE2,  0.5f,  0x113, 0xEC,  0.5f,  0x130, 0x12F, 0.5f,  0x138, 0xA6,  0.5f,
    0x13D, 0x1CE, 0.6f,  0x149, 0x1CE, 0.6f,  0x156, 0x132, 0.5f,  0x66,  0x139, 0.7f,
    0x40,  0x73,  0.5f,  0xCE,  0x30E, 0.5f,  0x9D,  0x1DC, 0.38f, 0x5E,  0x146, 0.7f,
    0x60,  0x278, 0.5f,  0x97,  0x71,  0.75f, 0x18E, 0x13D, 0.8f,  0x98,  0x3,   0.43f};
BaData_1 D_80801B98_badata[36] = {
    0x5D, 0x356, 3.9f,  0x5C,  0x280, 0.8f,  0x183, 0x5E,  1.2f,  0x17A, 0xAA,  0.62f, 0x96,  0x57,
    1.2f, 0x97,  0x70,  2.0f,  0x98,  0x4,   4.5f,  0x99,  0x38,  0.62f, 0x9A,  0x26,  1.2f,  0x9B,
    0x41, 1.0f,  0x6E,  0x289, 1.0f,  0x9D,  0x1DE, 3.0f,  0x98,  0xB2,  2.64f, 0xA4,  0x23,  1.0f,
    0xAC, 0x63,  1.0f,  0x98,  0x4,   4.5f,  0x93,  0xA4,  6.5f,  0xF5,  0xB5,  5.5f,  0xF3,  0xB5,
    5.5f, 0xFE,  0x1EE, 6.5f,  0x105, 0xE5,  6.5f,  0x113, 0xEC,  1.0f,  0x130, 0x12E, 6.0f,  0x138,
    0xA6, 0.5f,  0x13D, 0x1D2, 8.5f,  0x149, 0x1D2, 8.5f,  0x156, 0x132, 0.5f,  0x66,  0x139, 0.7f,
    0x40, 0x73,  0.5f,  0xCE,  0x30E, 0.5f,  0x9D,  0x1DC, 0.38f, 0x5E,  0x293, 2.7f,  0x60,  0x277,
    2.0f, 0x97,  0x70,  2.0f,  0x18E, 0x13D, 0.8f,  0x98,  0x4,   4.5f};
BaData_1 D_80801CB8_badata[36] = {
    0x5D, 0x356, 3.9f,  0x5C,  0x280, 0.8f,  0x183, 0x5E,  1.2f,  0x17A, 0xAA,  0.62f, 0x96,  0x57,
    1.2f, 0x97,  0x70,  2.0f,  0x98,  0x4,   4.5f,  0x99,  0x38,  0.62f, 0x9A,  0x26,  1.2f,  0x9B,
    0x41, 1.0f,  0x6E,  0x289, 1.0f,  0x9D,  0x1DE, 3.0f,  0x98,  0xB2,  2.64f, 0xA4,  0x23,  1.0f,
    0xAC, 0x63,  1.0f,  0x98,  0x4,   4.5f,  0x93,  0xA4,  6.5f,  0xF5,  0xB5,  5.5f,  0xF3,  0xB5,
    5.5f, 0xFE,  0x1EE, 4.5f,  0x105, 0xE5,  6.5f,  0x113, 0xEC,  1.0f,  0x130, 0x12E, 6.0f,  0x138,
    0xA6, 0.5f,  0x13D, 0x1D2, 8.5f,  0x149, 0x1D2, 8.5f,  0x156, 0x132, 0.5f,  0x66,  0x139, 0.7f,
    0x40, 0x73,  0.5f,  0xCD,  0x30D, 0.5f,  0x9D,  0x1DC, 0.38f, 0x5E,  0x293, 2.7f,  0x60,  0x277,
    2.0f, 0x97,  0x70,  2.0f,  0x18E, 0x13D, 0.8f,  0x98,  0x4,   4.5f};
BaData_1 D_80801DD8_badata[36] = {
    0x5D, 0x356, 3.9f,  0x5C,  0x280, 0.8f,  0x183, 0x5E,  1.2f,  0x17A, 0xAA,  0.62f, 0x96,  0x57,
    1.2f, 0x97,  0x70,  2.0f,  0x98,  0x6F,  5.5f,  0x99,  0x38,  0.62f, 0x9A,  0x26,  1.2f,  0x9B,
    0x41, 1.0f,  0x6E,  0x289, 1.0f,  0x9D,  0x1DE, 3.0f,  0x98,  0xB2,  2.64f, 0xA4,  0x23,  1.0f,
    0xAC, 0x63,  6.1f,  0x98,  0x6F,  5.5f,  0x93,  0xA4,  6.5f,  0xF5,  0xB5,  6.03f, 0xF3,  0x9D,
    2.8f, 0xFE,  0x1EE, 6.5f,  0x105, 0xE5,  6.5f,  0x113, 0xEC,  1.0f,  0x130, 0x12E, 6.0f,  0x138,
    0xA4, 6.5f,  0x13D, 0x1D2, 8.5f,  0x149, 0x1D2, 8.5f,  0x156, 0x132, 0.5f,  0x66,  0x139, 0.7f,
    0x40, 0x73,  0.5f,  0xCD,  0x30D, 0.5f,  0x9D,  0x1DC, 0.38f, 0x5E,  0x293, 2.7f,  0x60,  0x277,
    2.0f, 0x97,  0x70,  2.0f,  0x18E, 0x13D, 0.8f,  0x98,  0x6F,  5.5f};
BaData_1 D_80801EF8_badata[36] = {
    0x5D,  0x356, 3.9f,  0x5C,  0x280, 0.8f,  0x183, 0x5F,  0.6f,  0x17A, 0xAA,  0.62f,
    0x96,  0xB9,  0.7f,  0x97,  0xB9,  0.7f,  0x98,  0xB9,  0.7f,  0x99,  0xB9,  0.7f,
    0x9A,  0x15,  0.53f, 0x9B,  0x42,  0.8f,  0x6E,  0xB9,  0.7f,  0x9D,  0x1DE, 3.0f,
    0x98,  0x3,   0.43f, 0xA4,  0x11,  0.53f, 0xAC,  0x63,  0.6f,  0x98,  0xB9,  0.7f,
    0x93,  0xA7,  0.43f, 0xF5,  0xB3,  0.43f, 0xF3,  0x9C,  0.75f, 0xFE,  0x1E5, 0.43f,
    0x105, 0xE2,  0.5f,  0x113, 0xEC,  0.5f,  0x130, 0x12F, 0.5f,  0x138, 0xA4,  6.5f,
    0x13D, 0x1D2, 8.5f,  0x149, 0x1D2, 8.5f,  0x156, 0x132, 0.5f,  0x66,  0x139, 0.7f,
    0x40,  0x73,  0.5f,  0xCE,  0x30E, 0.5f,  0x9D,  0x1DC, 0.38f, 0x5E,  0xB9,  0.7f,
    0x60,  0xB9,  0.7f,  0x97,  0xB9,  0.7f,  0x18E, 0x13D, 0.8f,  0x98,  0xB9,  0.7f};
BaData_1 D_80802018_badata[36] = {
    0x5D,  0x356, 3.9f,  0x93,  0x13C, 0.43f, 0x183, 0x5F,  0.6f,  0x93,  0x13C, 0.43f,
    0x98,  0x68,  0.35f, 0x97,  0x71,  0.75f, 0x98,  0x68,  0.35f, 0x98,  0x68,  0.35f,
    0x98,  0x68,  0.35f, 0x98,  0x68,  0.35f, 0x98,  0x68,  0.35f, 0x9D,  0x1DE, 3.0f,
    0x98,  0x68,  0.35f, 0x98,  0x68,  0.35f, 0xAC,  0x63,  0.6f,  0x98,  0x68,  0.35f,
    0x93,  0x13C, 0.43f, 0xF5,  0xBC,  0.25f, 0xF5,  0xBC,  0.25f, 0xFE,  0x1E5, 0.43f,
    0x105, 0xE2,  0.5f,  0x113, 0xEC,  0.5f,  0x130, 0x12F, 0.5f,  0x138, 0xA4,  6.5f,
    0x13D, 0x1D2, 8.5f,  0x149, 0x1D2, 8.5f,  0x156, 0x132, 0.5f,  0x93,  0x13C, 0.43f,
    0x40,  0x73,  0.5f,  0xCE,  0x30E, 0.5f,  0x9D,  0x1DC, 0.38f, 0x98,  0x68,  0.35f,
    0x98,  0x68,  0.35f, 0x97,  0x71,  0.75f, 0x93,  0x13C, 0.43f, 0x98,  0x68,  0.35f};
BaData_1 D_80802138_badata[36] = {
    0x92, 0x356, 3.9f,  0x4E,  0x149, 1.0f,  0x185, 0x5E,  1.2f,  0x178, 0x0,   0.0f,  0x77,  0x57,
    1.2f, 0x78,  0x70,  2.0f,  0x73,  0x50,  11.4f, 0x76,  0x0,   0.0f,  0x79,  0x0,   0.0f,  0x62,
    0x41, 1.0f,  0x80,  0x289, 1.0f,  0x6B,  0x1DE, 3.0f,  0x9E,  0x0,   0.0f,  0x73,  0x50,  11.4f,
    0xB1, 0x63,  6.1f,  0x73,  0x6F,  5.5f,  0x8F,  0x10,  9.6f,  0xF6,  0xB5,  6.03f, 0xF2,  0x9D,
    2.8f, 0x70,  0x1EE, 6.5f,  0x10B, 0xE5,  6.5f,  0x119, 0xEC,  1.0f,  0x12F, 0x12E, 6.0f,  0x137,
    0xA4, 6.5f,  0x142, 0x1D2, 8.5f,  0x14E, 0x1D2, 8.5f,  0x155, 0x132, 0.5f,  0x65,  0x139, 0.7f,
    0xA0, 0x72,  1.2f,  0xD0,  0x0,   1.0f,  0x8D,  0x1DC, 0.38f, 0x5F,  0x293, 2.7f,  0x61,  0x277,
    2.0f, 0x78,  0x70,  2.0f,  0x18D, 0x0,   0.0f,  0x18F, 0x55,  4.5f};
BaData_1 D_80802258_badata[36] = {
    0x92, 0x356, 3.9f,  0x4E,  0x149, 1.0f,  0x185, 0x5E,  1.2f,  0x178, 0x0,   0.0f,  0x77,  0x57,
    1.2f, 0x78,  0x70,  2.0f,  0x74,  0x6F,  5.5f,  0x76,  0x0,   0.0f,  0x79,  0x0,   0.0f,  0x62,
    0x41, 1.0f,  0x80,  0x289, 1.0f,  0x6B,  0x1DE, 3.0f,  0x9E,  0x0,   0.0f,  0x74,  0x6F,  5.5f,
    0xB1, 0x63,  6.1f,  0x74,  0x6F,  5.5f,  0x8F,  0xA4,  6.5f,  0xF6,  0xB5,  6.03f, 0xF2,  0x9D,
    2.8f, 0x70,  0x1EE, 6.5f,  0x10B, 0xE5,  6.5f,  0x119, 0xEC,  1.0f,  0x12F, 0x12E, 6.0f,  0x137,
    0xA4, 6.5f,  0x142, 0x1D2, 8.5f,  0x14E, 0x1D2, 8.5f,  0x155, 0x132, 0.5f,  0x65,  0x139, 0.7f,
    0xA0, 0x72,  1.2f,  0xCF,  0x0,   1.0f,  0x8D,  0x1DC, 0.38f, 0x5F,  0x293, 2.7f,  0x61,  0x277,
    2.0f, 0x78,  0x70,  2.0f,  0x18D, 0x0,   0.0f,  0x18F, 0x55,  4.5f};
BaData_1 D_80802378_badata[36] = {
    0x92, 0x356, 3.9f,  0x4E,  0x149, 1.0f,  0x185, 0x5E,  1.2f,  0x178, 0x0,   0.0f,  0x77,  0x57,
    1.2f, 0x78,  0x70,  2.0f,  0x75,  0x50,  11.4f, 0x76,  0x0,   0.0f,  0x79,  0x0,   0.0f,  0x62,
    0x41, 1.0f,  0x80,  0x289, 1.0f,  0x6B,  0x1DE, 3.0f,  0x9E,  0x0,   0.0f,  0x74,  0x6F,  5.5f,
    0xB1, 0x63,  6.1f,  0x75,  0x6F,  5.5f,  0x8F,  0x10,  9.6f,  0xF6,  0xB5,  6.03f, 0xF2,  0x9D,
    2.8f, 0x70,  0x1EE, 6.5f,  0x10B, 0xE5,  6.5f,  0x119, 0xEC,  1.0f,  0x12F, 0x12E, 6.0f,  0x137,
    0xA4, 6.5f,  0x142, 0x1D2, 8.5f,  0x14E, 0x1D2, 8.5f,  0x155, 0x132, 0.5f,  0x65,  0x139, 0.7f,
    0xA0, 0x72,  1.2f,  0xD0,  0x0,   1.0f,  0x8D,  0x1DC, 0.38f, 0x5F,  0x293, 2.7f,  0x61,  0x277,
    2.0f, 0x78,  0x70,  2.0f,  0x18D, 0x0,   0.0f,  0x18F, 0x55,  4.5f};
BaData_4 D_80802498_badata[36] = {
    0x359, 0x359, 1.0f,  1.0f,  0x290, 0x291, 0.2f, 0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x5A, 0x59, 0.2f,
    0.2f,  0x5A,  0x59,  0.2f,  0.2f,  0x5A,  0x59, 0.2f, 0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x5A, 0x59,
    0.2f,  0.2f,  0x5A,  0x59,  0.2f,  0.2f,  0x5A, 0x59, 0.2f, 0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x5A,
    0x59,  0.2f,  0.2f,  0x5A,  0x59,  0.2f,  0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x63, 0x63, 6.1f, 6.1f,
    0x5A,  0x59,  0.2f,  0.2f,  0x290, 0x291, 0.2f, 0.2f, 0xBA, 0xBA, 0.5f, 0.5f, 0xBA, 0xBA, 0.5f,
    0.5f,  0x5A,  0x59,  0.2f,  0.2f,  0x5A,  0x59, 0.2f, 0.2f, 0xEE, 0xEE, 1.0f, 1.0f, 0x5A, 0x59,
    0.2f,  0.2f,  0x290, 0x291, 0.2f,  0.2f,  0x5A, 0x59, 0.2f, 0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x290,
    0x291, 0.2f,  0.2f,  0x290, 0x291, 0.2f,  0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x5A, 0x59, 0.2f, 0.2f,
    0x5A,  0x59,  0.2f,  0.2f,  0x5A,  0x59,  0.2f, 0.2f, 0x5A, 0x59, 0.2f, 0.2f, 0x5A, 0x59, 0.2f,
    0.2f,  0x5A,  0x59,  0.2f,  0.2f,  0x5A,  0x59, 0.2f, 0.2f};
BaData_4 D_80802648_badata[36] = {
    0x359, 0x0,  0.0f,  1.0f, 0x280, 0x0,  0.0f,  1.0f,  0x5E,  0x0,  0.0f,  0.99f, 0xAA,  0x0,
    0.0f,  1.0f, 0x39,  0x0,  0.0f,  1.0f, 0x71,  0x0,   0.0f,  1.0f, 0x8,   0x0,   0.3f,  0.66f,
    0x38,  0x0,  0.0f,  1.0f, 0x15,  0x0,  0.2f,  0.82f, 0x42,  0x0,  0.0f,  1.0f,  0x289, 0x0,
    0.0f,  1.0f, 0x1DC, 0x0,  0.0f,  1.0f, 0x3,   0x0,   0.0f,  1.0f, 0x11,  0x0,   0.0f,  1.0f,
    0x63,  0x0,  0.0f,  1.0f, 0x8,   0x0,  0.3f,  0.66f, 0xA9,  0x0,  0.3f,  0.7f,  0xB3,  0x0,
    0.0f,  1.0f, 0x9C,  0x0,  0.0f,  1.0f, 0x1E5, 0x0,   0.0f,  1.0f, 0xE2,  0x0,   0.0f,  1.0f,
    0xEC,  0x0,  0.0f,  1.0f, 0x12F, 0x0,  0.0f,  1.0f,  0xA6,  0x0,  0.0f,  1.0f,  0x1CE, 0x0,
    0.0f,  1.0f, 0x1CE, 0x0,  0.0f,  1.0f, 0x132, 0x0,   0.0f,  1.0f, 0x139, 0x0,   0.0f,  1.0f,
    0x73,  0x0,  0.0f,  1.0f, 0x30E, 0x0,  0.0f,  1.0f,  0x1DC, 0x0,  0.0f,  1.0f,  0x68,  0x0,
    0.0f,  1.0f, 0x68,  0x0,  0.0f,  1.0f, 0x71,  0x0,   0.0f,  1.0f, 0xAA,  0x0,   0.0f,  1.0f,
    0x8,   0x0,  0.3f,  0.66f};
