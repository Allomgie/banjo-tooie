#include "common.h"

extern void func_800C301C(u8, s32);
extern void func_800C35E8(u8, void *);
extern void func_800C3BDC(u8);
extern int func_800C3058(u8, unsigned int);
extern void func_800C31DC(u8, f32);
extern f32 func_800DC178(f32, f32);
typedef struct { s32 local_0; f32 local_1[3]; u8 pad_0[0x14]; u8 local_2; u8 local_3; u8 local_4; } FxStepState;
typedef struct { s16 id; s16 first; s16 second; s16 pad_0; f32 low; f32 high; f32 scale; s16 count; s16 pad_1; } StepEffect;
extern StepEffect D_80800830_fxstep[];
typedef struct { s16 local_0; s16 local_1; f32 local_2; f32 local_3; s16 local_4; s16 pad_0; } StepSoundRecord;
extern StepSoundRecord D_80800AA0_fxstep[];
extern void *heap_alloc(s32);
extern u8 func_800C2E04(void);
extern void func_800C330C(u8, s32);
extern void func_800C3418();
extern void func_800C3584(u8, f32, f32);
void fxstep_entrypoint_4();
int fxstep_entrypoint_5(s32 param_0, s32 param_1, f32 param_2);
void fxstep_entrypoint_7();
extern s32 fxstep_entrypoint_15(s32, s32, s32 *, s32 *, f32 *);

s32 func_80800000_fxstep(u8 *param_0)
{
  f32 temp_f0;
  s32 temp_a1;
  temp_f0 = (*((f32 *) (((s8 *) param_0) + 0x10))) - (*((f32 *) (((s8 *) param_0) + 8)));
  if ((temp_f0 > 0.0f) && (temp_f0 < 60.0f))
  {
    return 4;
  }
  temp_a1 = *((s32 *) (((s8 *) param_0) + 0));
  if (temp_a1 == 0)
  {
    return 0;
  }
  return func_800C84B0((((((temp_a1 & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF, temp_a1);
}

void func_80800078_fxstep(u8 *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
    f32 local_1;
    f32 local_0;
    u8 local_2;

    local_1 = param_3 * 0.5f;
    local_0 = func_800DC178(param_2 - local_1, param_2 + local_1);
    if (param_0[0x26]) local_2 = param_0[0x24];
    else local_2 = param_0[0x25];
    func_800C35E8(local_2, param_0 + 4);
    func_800C301C(local_2, param_1);
    func_800C31DC(local_2, local_0);
    func_800C3058(local_2, param_4);
    func_800C3BDC(local_2);
    param_0[0x26] ^= 1;
}

void func_8080012C_fxstep(FxStepState *param_0, s32 param_1, s32 param_2, f32 param_3, f32 param_4, f32 param_5, s32 param_6)
{
    f32 local_0;
    f32 local_1;
    s32 local_2;
    u8 local_3;

    local_0 = param_0->local_4 ? param_3 : param_4;
    local_1 = param_5 * 0.5f;
    local_0 = func_800DC178(local_0 - local_1, local_0 + local_1);
    local_2 = param_0->local_4 ? param_1 : param_2;
    local_3 = param_0->local_4 ? param_0->local_2 : param_0->local_3;
    func_800C35E8(local_3, param_0->local_1);
    func_800C301C(local_3, local_2);
    func_800C31DC(local_3, local_0);
    func_800C3058(local_3, param_6);
    func_800C3BDC(local_3);
    param_0->local_4 ^= 1;
}

int func_80800210_fxstep(void *param_0, f32 param_1, f32 param_2, s32 param_3)
{
    s32 local_0;

    for (local_0 = 0; D_80800830_fxstep[local_0].id != 0; local_0++) {
        if (param_3 == D_80800830_fxstep[local_0].id) {
            func_8080012C_fxstep(param_0, D_80800830_fxstep[local_0].first, D_80800830_fxstep[local_0].second,
                D_80800830_fxstep[local_0].low + param_1, D_80800830_fxstep[local_0].high + param_1,
                D_80800830_fxstep[local_0].scale, (s32)((f32)D_80800830_fxstep[local_0].count * param_2));
            return 1;
        }
    }
    return 0;
}

int func_808002B4_fxstep(void *param_0, f32 param_1, f32 param_2, s32 param_3)
{
    s32 i;

    for (i = 0; D_80800AA0_fxstep[i].local_0 != 0; i++) {
        if (D_80800AA0_fxstep[i].local_0 == param_3) {
            func_80800078_fxstep(param_0, D_80800AA0_fxstep[i].local_1, D_80800AA0_fxstep[i].local_2 + param_1,
                D_80800AA0_fxstep[i].local_3, (s32)(D_80800AA0_fxstep[i].local_4 * param_2));
            return 1;
        }
    }
    return 0;
}

void func_80800344_fxstep(void *param_0, f32 param_1, f32 param_2, s32 param_3)
{
    s32 local_0;
    void (*local_1)(void *, s32, s32);

    local_0 = func_80800000_fxstep(param_0);
    if (param_3) {
        func_80800210_fxstep(param_0, *(f32 *)&param_1, *(f32 *)&param_2, local_0);
    }
    local_1 = *(void (**)(void *, s32, s32))((u8 *)param_0 + 0x14);
    if (local_1 != NULL) {
        local_1(param_0, local_0, *(s32 *)((u8 *)param_0 + 0x14 + 4));
    }
}

void func_808003B4_fxstep(void *param_0, f32 param_1, f32 param_2, s32 param_3)
{
    s32 local_0;
    void (*local_1)(void *, s32, s32);

    local_0 = func_80800000_fxstep(param_0);
    if (param_3) {
        func_808002B4_fxstep(param_0, param_1, param_2, local_0);
    }
    local_1 = *(void (**)(void *, s32, s32))((u8 *)param_0 + 0x1C);
    if (local_1 != NULL) {
        local_1(param_0, local_0, *(s32 *)((u8 *)param_0 + 0x1C + 4));
    }
}

void fxstep_entrypoint_0(void *param_0)
{
    func_800C2FDC(*(char *)((char *)param_0 + 0x24));
    func_800C2FDC(*(char *)((char *)param_0 + 0x25));
    heap_free(param_0);
}

void *fxstep_entrypoint_1(void)
{
    u8 *local_0;

    local_0 = heap_alloc(0x28);
    local_0[0x26] = 0;
    local_0[0x27] = 1;
    local_0[0x24] = func_800C2E04();
    func_800C330C(local_0[0x24], 3);
    func_800C3418(local_0[0x24], 0);
    local_0[0x25] = func_800C2E04();
    func_800C330C(local_0[0x25], 3);
    func_800C3418(local_0[0x25], 0);
    func_800EFD24((f32 *)(local_0 + 4));
    fxstep_entrypoint_4(local_0, 0, 0);
    fxstep_entrypoint_5(local_0, 0, 0.0f);
    fxstep_entrypoint_7(local_0, 0, 0);
    return local_0;
}

int fxstep_entrypoint_2(u8 *param_0, unsigned int param_1)
{
  param_0[0x26] = param_1;
}

fxstep_entrypoint_3(s32 param_0, s32 param_1) {
    *(s8 *)(param_0 + 0x27) = param_1;
}

void fxstep_entrypoint_4(param_0, param_1, param_2) void *param_0; s32 param_1; s32 param_2; {
    ((u32 *)param_0)[7] = param_1;
    ((u32 *)param_0)[8] = param_2;
}

fxstep_entrypoint_5(s32 param_0, s32 param_1, f32 param_2)
{
    *(s32 *)(param_0 + 0x0) = param_1;
    *(f32 *)(param_0 + 0x10) = param_2;
}

s32 fxstep_entrypoint_6(s32 *param_0)
{
  s32 *new_var;
  s32 *new_var2;
  int new_var3;
  new_var3 = 4;
  new_var3 = 1;
  if (new_var3)
  {
    new_var = param_0 + new_var3;
    ;
    func_800EE7F8(new_var);
  }
}

void fxstep_entrypoint_7(void *param_0, s32 param_1, s32 param_2)
{
  ((s32 *) param_0)[5] = param_1;
  ((s32 *) param_0)[6] = param_2;
}

void fxstep_entrypoint_8(u8 *param_0, f32 param_1, f32 param_2) {
    func_808003B4_fxstep(param_0, param_1, param_2, param_0[0x27]);
}

void fxstep_entrypoint_9(s32 param_0)
{
  func_808003B4_fxstep(param_0, 0.0f, 1.0f, 0);
}

int fxstep_entrypoint_10(s32 param_0, s32 param_1)
{
  func_808002B4_fxstep(param_0, 0, 1.0f, param_1);
}

void fxstep_entrypoint_11(u8 *param_0, f32 param_1, f32 param_2) {
    func_80800344_fxstep(param_0, param_1, param_2, param_0[0x27]);
}

void fxstep_entrypoint_12(s32 param_0) {
    func_80800344_fxstep(param_0, 0, 1.0f, 0);
}

void fxstep_entrypoint_13(u8 *param_0, s32 param_1)
{
    if (param_0[0x27] != 0) {
        func_80800210_fxstep(param_0, 0, 1.0f, param_1);
    }
}

void fxstep_entrypoint_14(s32 param_0, s32 param_1, void *param_2, s32 param_3, s32 param_4)
{
    s32 local_0;
    s32 local_1;
    f32 local_2;
    u8 local_3;

    if (fxstep_entrypoint_15(param_0, param_1, &local_0, &local_1, &local_2)) {
        local_3 = func_800C2E04();
        func_800C330C(local_3, 1);
        func_800C35E8(local_3, param_2);
        func_800C301C(local_3, local_0);
        func_800C31DC(local_3, func_800DC178(-0.05f, 0.05f) + local_2);
        func_800C3058(local_3, local_1);
        func_800C3584(local_3, (f32)param_3, (f32)param_4);
        func_800C3BDC(local_3);
    }
}

s32 fxstep_entrypoint_15(param_0, param_1, param_2, param_3, param_4) s32 param_0; s32 param_1; s32 *param_2; s32 *param_3; f32 *param_4;
{
    s32 local_0;

    for (local_0 = 0; D_80800830_fxstep[local_0].id != 0; local_0++) {
        if (param_0 == D_80800830_fxstep[local_0].id) {
            if (param_1) {
                *param_4 = D_80800830_fxstep[local_0].low;
                *param_2 = D_80800830_fxstep[local_0].first;
            } else {
                *param_4 = D_80800830_fxstep[local_0].high;
                *param_2 = D_80800830_fxstep[local_0].second;
            }
            *param_4 += func_800DC178(-0.05f, 0.05f);
            *param_3 = D_80800830_fxstep[local_0].count;
            return 1;
        }
    }
    return 0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/fx/step.data.s) is defined here in C.
 * Values are taken from the ROM. */
StepEffect D_80800830_fxstep[26] = { 0x1, 0x404, 0x404, 0x0, 1.0f, 1.2f, 0.05f, 0x2328, 0x0, 0x2, 0x403, 0x403, 0x0, 1.0f, 1.2f, 0.05f, 0xBB8, 0x0, 0x3, 0x405, 0x405, 0x0, 1.0f, 1.2f, 0.05f, 0x2AF8, 0x0, 0x4, 0x40A, 0x40A, 0x0, 1.0f, 1.2f, 0.05f, 0x32C8, 0x0, 0x5, 0x419, 0x419, 0x0, 1.0f, 1.2f, 0.05f, 0x2328, 0x0, 0x6, 0x402, 0x402, 0x0, 1.0f, 1.2f, 0.05f, 0x1B58, 0x0, 0x7, 0x41B, 0x41B, 0x0, 1.0f, 1.0f, 0.05f, 0x2710, 0x0, 0x8, 0x401, 0x401, 0x0, 0.7f, 0.8f, 0.05f, 0x4268, 0x0, 0xB, 0x40A, 0x40A, 0x0, 0.5f, 0.55f, 0.01f, 0x3E80, 0x0, 0x9, 0x459, 0x459, 0x0, 1.0f, 1.1f, 0.05f, 0x5208, 0x0, 0xA, 0x45A, 0x45A, 0x0, 1.0f, 1.1f, 0.05f, 0x5208, 0x0, 0xC, 0x482, 0x482, 0x0, 0.85f, 0.89f, 0.05f, 0x5208, 0x0, 0xD, 0x3F0, 0x3F0, 0x0, 0.96f, 1.04f, 0.02f, 0x2710, 0x0, 0xE, 0x40A, 0x40A, 0x0, 1.2f, 1.35f, 0.05f, 0x32C8, 0x0, 0xF, 0x46F, 0x46F, 0x0, 0.95f, 1.1f, 0.05f, 0x3E80, 0x0, 0x10, 0x41B, 0x41B, 0x0, 1.0f, 1.0f, 0.05f, 0x2328, 0x0, 0x11, 0x4AE, 0x4AE, 0x0, 1.0f, 1.0f, 0.05f, 0x2328, 0x0, 0x12, 0x4BC, 0x4BC, 0x0, 1.0f, 1.0f, 0.05f, 0x2328, 0x0, 0x13, 0x56E, 0x56E, 0x0, 1.0f, 1.1f, 0.05f, 0x2AF8, 0x0, 0x15, 0x40A, 0x40A, 0x0, 1.0f, 1.2f, 0.05f, 0x32C8, 0x0, 0x16, 0x56E, 0x56E, 0x0, 1.0f, 1.1f, 0.05f, 0x32C8, 0x0, 0x17, 0x5C2, 0x5C2, 0x0, 1.4f, 1.5f, 0.05f, 0x61A8, 0x0, 0x1A, 0x4D5, 0x4D5, 0x0, 1.0f, 1.5f, 0.05f, 0x61A8, 0x0, 0x14, 0x60F, 0x60F, 0x0, 1.0f, 1.2f, 0.05f, 0x2AF8, 0x0, 0x18, 0x402, 0x402, 0x0, 1.0f, 1.2f, 0.05f, 0x1B58, 0x0, 0x0, 0x0, 0x0, 0x0, 0.0f, 0.0f, 0.0f, 0x0, 0x0 };
StepSoundRecord D_80800AA0_fxstep[23] = { 0x1, 0x44A, 1.0f, 0.05f, 0x2EE0, 0x0, 0x2, 0x44E, 1.0f, 0.05f, 0xBB8, 0x0, 0x3, 0x405, 1.0f, 0.05f, 0x36B0, 0x0, 0x4, 0x40A, 1.0f, 0.05f, 0x32C8, 0x0, 0x5, 0x450, 1.0f, 0.05f, 0x2AF8, 0x0, 0x6, 0x44C, 1.0f, 0.05f, 0x2710, 0x0, 0x7, 0x41B, 1.0f, 0.05f, 0x4268, 0x0, 0x8, 0x401, 0.7f, 0.05f, 0x4268, 0x0, 0xB, 0x40A, 0.5f, 0.03f, 0x4268, 0x0, 0x9, 0x459, 1.0f, 0.05f, 0x55F0, 0x0, 0xA, 0x45A, 1.0f, 0.05f, 0x55F0, 0x0, 0xC, 0x482, 0.9f, 0.05f, 0x55F0, 0x0, 0x10, 0x41B, 1.0f, 0.05f, 0x55F0, 0x0, 0x11, 0x4AE, 1.0f, 0.05f, 0x55F0, 0x0, 0x12, 0x4BC, 1.0f, 0.05f, 0x55F0, 0x0, 0x13, 0x56E, 1.0f, 0.05f, 0x7FFF, 0x0, 0x15, 0x40A, 1.0f, 0.05f, 0x32C8, 0x0, 0x16, 0x56E, 0.85f, 0.05f, 0x6D60, 0x0, 0x17, 0x5C2, 1.4f, 0.05f, 0x7D00, 0x0, 0x1A, 0x4D5, 1.0f, 0.05f, 0x7D00, 0x0, 0x14, 0x60F, 1.0f, 0.05f, 0x36B0, 0x0, 0x18, 0x44C, 1.0f, 0.05f, 0x2710, 0x0, 0x0, 0x0, 0.0f, 0.0f, 0x0, 0x0 };
