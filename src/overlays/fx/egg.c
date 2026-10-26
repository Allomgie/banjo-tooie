#include "common.h"
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);

typedef struct { s16 local_0, local_1, local_2; } EggEffectRecord;
extern EggEffectRecord D_80800550_fxegg[];
extern void func_800BA75C(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 D_80800574_fxegg;
extern u8 D_808005B0_fxegg[];
extern u8 D_808005D8_fxegg[];
extern u8 D_80800614_fxegg[];
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern s32 D_80800630_fxegg;
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

void fxegg_entrypoint_0(s32 param_0, s32 param_1, f32 param_2) {
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

s32 fxegg_entrypoint_1(s32 param_0, f32 param_1) {
    s32 local_0;

    local_0 = func_800B5BE4(0xC);
    func_808000F8_fxegg(local_0 | 0, param_0, 0x9E5, param_1);
    return local_0;
}

s32 fxegg_entrypoint_2(s32 param_0, f32 param_1) {
    s32 local_0;

    local_0 = func_800B5BE4(0xB);
    func_808000F8_fxegg(local_0 | 0, param_0, 0x9E0, param_1);
    return local_0;
}

void func_808001CC_fxegg(s32 param_0, s32 param_1, f32 param_2) {
    func_800BABB8(param_0, param_1, 0, param_2, D_808005D8_fxegg);
}

s32 fxegg_entrypoint_3(s32 param_0, f32 param_1) {
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
        func_800BA930(local_0, (s16)local_1[0], (s16)(local_1[1] + 60.0f), (s16)local_1[2],
            (s16)local_1[0], (s32)(local_1[1] + 100.0f), (s16)local_1[2]);
    }
    func_800BABB8(local_0, param_0, param_0, param_2, D_80800614_fxegg);
    return local_0;
}

s32 fxegg_entrypoint_6(f32 *param_0, f32 param_1, f32 *param_2)
{
    s32 local_0;

    local_0 = func_800B5BE4(0x17);
    func_800BA930(local_0, (s16)param_2[0], (s16)param_2[1], (s16)param_2[2], (s16)param_2[0], (s16)param_2[1], (s16)param_2[2]);
    func_800BA3FC(local_0, 0x9E2);
    func_800BABB8(local_0, param_0, 0, param_1, &D_80800630_fxegg);
    return local_0;
}

void func_80800410_fxegg(s32 param_0, f32 *param_1, f32 *param_2, s32 param_3, f32 param_4)
{
    func_800BA930(param_0, (s16)param_2[0], (s16)param_2[1], (s16)param_2[2],
        (s16)param_2[0], (s16)param_2[1], (s16)param_2[2]);
    func_800BA3FC(param_0, param_3);
    func_800BABB8(param_0, param_1, NULL, param_4, D_80800658_fxegg);
}

void fxegg_entrypoint_7(s32 param_0, s32 param_1, f32 param_2) {
    func_80800410_fxegg(func_800B5BE4(0xB), param_0, param_1, 0x9E0, param_2);
}

void fxegg_entrypoint_8(s32 param_0, s32 param_1, f32 param_2) {
    func_80800410_fxegg(func_800B5BE4(0xC), param_0, param_1, 0x9E5, param_2);
}
