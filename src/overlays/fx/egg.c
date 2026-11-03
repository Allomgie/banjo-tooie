#include "common.h"
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);

typedef struct {
    s16 local_0, local_1, local_2;
} EggEffectRecord;
extern EggEffectRecord D_80800550_fxegg[];
extern void func_800BA75C(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 D_80800574_fxegg[];
extern u8 D_808005B0_fxegg[];
extern u8 D_808005D8_fxegg[];
extern u8 D_80800614_fxegg[];
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern s32 D_80800630_fxegg[];
extern s32 D_80800658_fxegg[];
extern s32 func_800B5BE4(s32);
int func_8080009C_fxegg(s32, s32, s32, f32);

EggEffectRecord *func_80800000_fxegg(s32 param_0)
{
    s32 local_1;

    while (1) {
        for (local_1 = 0; D_80800550_fxegg[local_1].local_0 != 0; local_1++) {
            if (D_80800550_fxegg[local_1].local_0 == param_0) {
                return &D_80800550_fxegg[local_1];
            }
        }
        param_0 = 1;
    }
}

void fxegg_entrypoint_0(s32 param_0, s32 param_1, f32 param_2)
{
    s16 *local_1 = func_80800000_fxegg(param_0);
    s32 local_0 = func_8080009C_fxegg(local_1[1], local_1[2], param_1, param_2);
    func_800BA75C(local_0, param_1);
    func_800BA22C(local_0, 5);
}

int func_8080009C_fxegg(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
    s32 local_0;
    local_0 = func_800B5BE4(param_1 | 0);
    func_800BA670(local_0, param_0);
    func_800BABB8(local_0, param_2, param_2, param_3, &D_80800574_fxegg);
}

void func_808000F8_fxegg(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
    func_800BA3FC(param_0, param_2 | 0);
    func_800BABB8(param_0, param_1, 0, param_3, &D_808005B0_fxegg);
}

s32 fxegg_entrypoint_1(s32 param_0, f32 param_1)
{
    s32 local_0;

    local_0 = func_800B5BE4(0xC);
    func_808000F8_fxegg(local_0 | 0, param_0, 0x9E5, param_1);
    return local_0;
}

s32 fxegg_entrypoint_2(s32 param_0, f32 param_1)
{
    s32 local_0;

    local_0 = func_800B5BE4(0xB);
    func_808000F8_fxegg(local_0 | 0, param_0, 0x9E0, param_1);
    return local_0;
}

void func_808001CC_fxegg(s32 param_0, s32 param_1, f32 param_2)
{
    func_800BABB8(param_0, param_1, 0, param_2, D_808005D8_fxegg);
}

s32 fxegg_entrypoint_3(s32 param_0, f32 param_1)
{
    s32 local_0;

    local_0 = func_800B5BE4(0x13);
    func_808001CC_fxegg(local_0 | 0, param_0, param_1);
    return local_0;
}

int fxegg_entrypoint_4(s32 param_0, f32 param_1)
{
    s32 local_0;
    local_0 = func_800B5BE4(0x21);
    func_808000F8_fxegg(local_0 | 0, param_0, 0x9E4, param_1);
    return local_0;
}

s32 fxegg_entrypoint_5(f32 *param_0, f32 *param_1, f32 param_2)
{
    s32 local_0;
    f32 local_1[3];
    local_0 = _fxdlsmoke_entrypoint_0();
    if (param_1) {
        func_800EFA20(local_1, param_1, 0.15f);
        func_800BA930(local_0, (s16) local_1[0], (s16) (local_1[1] + 60.0f), (s16) local_1[2],
                      (s16) local_1[0], (s32) (local_1[1] + 100.0f), (s16) local_1[2]);
    }
    func_800BABB8(local_0, param_0, param_0, param_2, D_80800614_fxegg);
    return local_0;
}

s32 fxegg_entrypoint_6(f32 *param_0, f32 param_1, f32 *param_2)
{
    s32 local_0;

    local_0 = func_800B5BE4(0x17);
    func_800BA930(local_0, (s16) param_2[0], (s16) param_2[1], (s16) param_2[2], (s16) param_2[0],
                  (s16) param_2[1], (s16) param_2[2]);
    func_800BA3FC(local_0, 0x9E2);
    func_800BABB8(local_0, param_0, 0, param_1, &D_80800630_fxegg);
    return local_0;
}

void func_80800410_fxegg(s32 param_0, f32 *param_1, f32 *param_2, s32 param_3, f32 param_4)
{
    func_800BA930(param_0, (s16) param_2[0], (s16) param_2[1], (s16) param_2[2], (s16) param_2[0],
                  (s16) param_2[1], (s16) param_2[2]);
    func_800BA3FC(param_0, param_3);
    func_800BABB8(param_0, param_1, NULL, param_4, D_80800658_fxegg);
}

void fxegg_entrypoint_7(s32 param_0, s32 param_1, f32 param_2)
{
    func_80800410_fxegg(func_800B5BE4(0xB), param_0, param_1, 0x9E0, param_2);
}

void fxegg_entrypoint_8(s32 param_0, s32 param_1, f32 param_2)
{
    func_80800410_fxegg(func_800B5BE4(0xC), param_0, param_1, 0x9E5, param_2);
}

EggEffectRecord D_80800550_fxegg[6] = {0x1, 0x611, 0x5,  0x2, 0x71B, 0x26, 0x3, 0x71E, 0x28,
                                       0x5, 0x71A, 0x25, 0x7, 0x71C, 0x27, 0x0, 0x0,   0x0};
s32 D_80800574_fxegg[15] = {0x160400,  0x220333,  0x4000033, 0x330027,  0x1900190,
                            0x3200320, 0x2A0000,  0x20180,   0x180002C, -0xC7FF38,
                            -0xC7FF38, 0x19000C8, 0xC0028,   0x1BFCE0,  -0x3200000};
u8 D_808005B0_fxegg[40] = {0x0, 0xC,  0x0, 0x20, 0x0, 0x15, 0x0, 0x19, 0x0, 0x33,
                           0x0, 0x22, 0x1, 0x0,  0x1, 0x0,  0x0, 0x66, 0x0, 0x66,
                           0x0, 0x27, 0x1, 0x90, 0x1, 0x90, 0x3, 0x20, 0x3, 0x20,
                           0x0, 0x2B, 0x0, 0x28, 0x0, 0x28, 0x1, 0x1A, 0x0, 0x0};
u8 D_808005D8_fxegg[60] = {0x0,  0x1D, 0x9, 0xCE, 0x0, 0x16, 0x12, 0x0,  0x0, 0x32, 0x0,  0x2,
                           0x0,  0x15, 0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1, 0x99, 0x2,  0x0,
                           0x1,  0x33, 0x1, 0x99, 0x0, 0x2B, 0x0,  0xA6, 0x0, 0xA6, 0x0,  0x1B,
                           0x1,  0x2C, 0x1, 0x2C, 0x0, 0x18, 0x0,  0x0,  0x0, 0x0,  0x19, 0x0,
                           0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x1,  0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_80800614_fxegg[28] = {0x0, 0x15, 0x0, 0x0,  0x0, 0x33, 0x0, 0x22, 0x1, 0x99,
                           0x2, 0x0,  0x2, 0xCC, 0x3, 0x99, 0x0, 0x2B, 0x0, 0x99,
                           0x0, 0xB3, 0x1, 0x1A, 0x0, 0x0,  0x0, 0x0};
s32 D_80800630_fxegg[10] = {0xC000C,  0x150019,  0x330022,  0x1000100, 0x660066,
                            0x270190, 0x1900320, 0x320002B, 0x4C004C,  0x11A0000};
s32 D_80800658_fxegg[10] = {0xC0001,  0x150019,  0x330022,  0x1000100, 0x660066,
                            0x270190, 0x1900320, 0x320002B, 0x280028,  0x11A0000};
