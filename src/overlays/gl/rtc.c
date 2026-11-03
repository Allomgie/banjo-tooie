#include "common.h"

void func_80800170_glrtc();
void func_808002C8_glrtc();
void func_8080031C_glrtc();
void func_80800474_glrtc();
void func_808005B0_glrtc();

void glrtc_entrypoint_0(u8 *param_0, u8 *param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 i;
    s32 j;
    s32 unused0;
    s32 unused1;
    s32 unused2;
    s32 unused3;

    local_0 = param_0;
    local_1 = param_0 + 3;
    local_2 = param_0[1] * 4;
    for (i = 0; i < local_0[2]; i++) {
        for (j = 0; j < local_0[1]; j++) {
            switch (param_0[0]) {
                case 0:
                    func_80800170_glrtc(&local_1, (u16 *) param_1 + i * 4 * local_2 + j * 4,
                                        local_2);
                    break;
                case 1:
                    func_8080031C_glrtc(&local_1, (u32 *) param_1 + i * 4 * local_2 + j * 4,
                                        local_2);
                    break;
                case 2:
                    func_80800474_glrtc(&local_1, (u32 *) param_1 + i * 4 * local_2 + j * 4,
                                        local_2);
            }
        }
    }
}

void func_80800170_glrtc(param_0, param_1, param_2) u8 **param_0;
u16 *param_1;
s32 param_2;
{
    u16 local_0[2];
    u32 local_1;
    u16 local_2[4];
    u8 *local_3 = *param_0;
    s32 local_4;
    s32 local_5;

    bcopy(local_3, local_0, 4);
    local_3 += 4;
    local_2[0] = local_0[0];
    local_2[1] = 1;
    local_2[2] = 1;
    local_2[3] = local_0[1];
    func_808002C8_glrtc(local_2, 0xF800);
    func_808002C8_glrtc(local_2, 0x7C0);
    func_808002C8_glrtc(local_2, 0x3E);
    bcopy(local_3, &local_1, 4);
    local_3 += 4;
    for (local_4 = 0; local_4 < 4; local_4++) {
        for (local_5 = 0; local_5 < 4; local_5++) {
            param_1[local_5] = local_2[local_1 & 3];
            local_1 >>= 2;
        }
        param_1 += param_2;
    }
    *param_0 = local_3;
}

void func_808002C8_glrtc(param_0, param_1) u16 *param_0;
u16 param_1;
{
    u16 local_0;
    u16 local_1;
    u16 local_2;
    local_0 = param_0[0] & param_1;
    local_1 = param_0[3] & param_1;
    local_2 = ((local_1 - local_0) / 3) & (int) param_1;
    param_0[1] |= local_0 + local_2;
    param_0[2] |= local_1 - local_2;
}

void func_8080031C_glrtc(param_0, param_1, param_2) u8 **param_0;
s32 param_1;
s32 param_2;
{
    u16 local_0[2];
    u8 local_1[4][4];
    u8 *local_3 = *param_0;
    u32 local_2;
    s32 local_4;
    u8 *local_5;

    bcopy(local_3, local_0, 4);
    local_3 += 4;
    local_1[0][0] = (local_0[0] & 0xF800) >> 8;
    local_1[1][0] = (local_0[0] & 0x7C0) >> 3;
    local_1[2][0] = (local_0[0] & 0x3E) << 2;
    local_1[3][0] = 255;
    local_1[0][3] = (local_0[1] & 0xF800) >> 8;
    local_1[1][3] = (local_0[1] & 0x7C0) >> 3;
    local_1[2][3] = (local_0[1] & 0x3E) << 2;
    local_1[3][3] = 255;
    for (local_4 = 0, local_5 = &local_1[0][0]; local_4 != 3; local_4++, local_5 += 4) {
        if (local_5[0] == local_5[3])
            local_2 = 0;
        else {
            bcopy(local_3, &local_2, 4);
            local_3 += 4;
        }
        func_808005B0_glrtc(param_1, (u8) local_4, param_2, local_5, local_2);
    }
    local_2 = 0;
    func_808005B0_glrtc(param_1, (u8) local_4, param_2, &local_1[0][0], 0);
    *param_0 = local_3;
}

void func_80800474_glrtc(param_0, param_1, param_2) u8 **param_0;
u32 param_1;
u32 param_2;
{
    union {
        u64 local_2;
        u32 local_0[2];
        u8 local_1[8];
    } local_0;
    u32 local_1;
    u8 local_2[4];
    s32 local_3;
    u8 *local_4;
    u8 local_5 = 0;
    u8 local_6 = 0;

    local_4 = *param_0;
    local_0.local_1[3] = local_4[0];
    local_0.local_1[2] = local_4[1];
    local_0.local_1[1] = local_4[2] & 0xF;
    local_4 += 5;
    local_0.local_1[7] = local_4[-3];
    local_0.local_1[6] = local_4[-2];
    local_0.local_1[5] = local_4[-1];
    if (local_0.local_0[0]) {
    }
    local_0.local_0[1] >>= 4;
    for (local_3 = 0; local_3 < 4; local_3++) {
        local_5 = (local_0.local_0[0] << 3) & 0xFF;
        local_0.local_0[0] >>= 5;
        local_6 = (local_0.local_0[1] << 3) & 0xFF;
        local_0.local_0[1] >>= 5;
        local_2[3] = local_6;
        local_2[0] = local_5;
        if (local_6 == local_5) {
            local_1 = 0;
        } else {
            bcopy(local_4, &local_1, 4);
            local_4 += 4;
        }
        func_808005B0_glrtc(param_1, (u8) local_3, param_2, local_2, local_1);
    }
    if (local_3) {
    }
    *param_0 = local_4;
}

void func_808005B0_glrtc(param_0, param_1, param_2, param_3, param_4) u8 *param_0;
u8 param_1;
s32 param_2;
u8 *param_3;
u32 param_4;
{
    s32 i;
    s32 j;
    char d;

    if (param_4 != 0) {
        d = (param_3[3] - param_3[0]) / 3;
        param_3[1] = param_3[0] + d;
        param_3[2] = param_3[3] - d;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            *(param_0 + (j << 2) + param_1) = param_3[param_4 & 3];
            param_4 >>= 2;
        }
        param_0 += param_2 << 2;
    }
}
