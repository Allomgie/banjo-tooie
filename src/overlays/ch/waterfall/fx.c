#include "common.h"

extern void *D_80800410_chwaterfallfx;
extern u8 D_80800458_chwaterfallfx[];
extern void func_800EF334(f32 *, f32);
extern void func_800F22B4(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern u8 D_80800478_chwaterfallfx[];
extern f32 func_800D8FF8(void);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
void func_808001F8_chwaterfallfx();

int chwaterfallfx_entrypoint_0()
{
  return &D_80800410_chwaterfallfx;
}

void func_8080000C_chwaterfallfx(Actor *param_0)
{
    f32 local_0[2];
    f32 local_1[2];
    f32 local_2[3];
    f32 local_3;

    func_800F22B4(local_0, param_0->rotation[1]);
    func_800F23AC(local_1, local_0);
    func_800EE8E8(local_2, local_1);
    func_800EF334(local_2, (f32)param_0->unk74_7);
    func_800EE780((u8 *)param_0 + 0x28, param_0->position, local_2);
    func_800EFB24(param_0->actorData, param_0->position, local_2);
    local_3 = func_800EEAD4((f32 *)((u8 *)param_0 + 0x28), (f32 *)param_0->actorData);
    *(f32 *)((u8 *)param_0 + 0x34) = 0.6f * local_3;
    *(s32 *)((u8 *)param_0 + 0x54) = 0;
    param_0->unk64_20 = *(u32 *)((u8 *)param_0 + 0x70) & 1;
    ((u8 *)param_0)[0x73] &= ~1;
    *(s32 *)((u8 *)param_0 + 0x24) = (s32)(local_3 / 25.0f + 8.0f);
    param_0->unk58 = 0.0f;
    param_0->unk50 = *(s32 *)((u8 *)param_0 + 0x24) * 1.5f;
}

void func_80800148_chwaterfallfx(Actor *param_0)
{
  _subaddieaudioloop_entrypoint_5(param_0, (u8 *)param_0 + 4, 1, 0xC80, &D_80800458_chwaterfallfx);
  if (param_0->unk5F != 0) {
    if (!param_0->unk64_19) {
      func_800C3058(param_0->unk5F, 0x2AF8);
      param_0->unk64_19 = 1;
    }
  } else {
    param_0->unk64_19 = 0;
  }
  if (!param_0->unk64_20) {
    func_808001F8_chwaterfallfx(param_0);
  }
}

s32 func_808001E4_chwaterfallfx(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
void func_808001F8_chwaterfallfx(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_1[3];
    f32 local_2[3];

    func_800E3980(local_0);
    if (func_800EEB40(param_0->position, local_0) < 25000000.0f &&
        func_800E3E8C(param_0->position, param_0->actorData[7])) {
        local_5 = func_800B5BE4(0x23);
        local_4 = 0;
        param_0->unk58 += param_0->unk50 * func_800D8FF8();
        while (param_0->unk58 >= 1.0f) {
            local_4++;
            param_0->unk58 -= 1.0f;
        }
        for (local_3 = 0; local_3 < local_4; local_3++) {
            func_800EFE50(local_2, (f32 *)&param_0->actorData[4],
                         (f32 *)param_0->actorData, func_800DC178(0.0f, 1.0f));
            func_800EE7F8(local_1, local_2);
            func_800EF1B8(local_1, param_0->rotation[1], -100.0f);
            local_1[1] += 100.0f;
            func_800BABB8(local_5, local_2, local_1, param_0->scale * 1.15f,
                         D_80800478_chwaterfallfx);
            (*(s32 *)&param_0->unk54)++;
            if (*(s32 *)&param_0->unk54 >= (s32)param_0->actorData[3]) {
                *(s32 *)&param_0->unk54 = 0;
            }
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/waterfall/fx.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
void *D_80800410_chwaterfallfx = (void *)0x015801BB;
static u32 D_80800410_chwaterfallfx_rest[17] = { 0x1, 0x0, (u32)func_80800148_chwaterfallfx, (u32)func_80102EC0, (u32)func_8010A730, 0x17700000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)func_8080000C_chwaterfallfx, (u32)func_80107C2C, 0x80000602, (u32)func_808001E4_chwaterfallfx, 0x0 };
u8 D_80800458_chwaterfallfx[32] = { 0x0, 0x13, 0x3, 0xEC, 0x0, 0x1, 0x1, 0x90, 0xC, 0x80, 0x0, 0x1A, 0x1, 0x0, 0x0, 0x80, 0x0, 0xE, 0x0, 0xC0, 0x0, 0xD9, 0x0, 0x26, 0x0, 0x16, 0x2A, 0xF8, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800478_chwaterfallfx[72] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x1B, 0x1, 0xC2, 0x2, 0x26, 0x0, 0x2D, 0x0, 0xC8, 0x0, 0xFA, 0x0, 0xE, 0x0, 0xF, 0x0, 0x14, 0x0, 0x16, 0x6, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x33, 0x0, 0x2, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x22, 0x0, 0x91, 0x0, 0xAB, 0x0, 0xF8, 0x1, 0xF, 0x0, 0x15, 0x0, 0xC, 0x0, 0xA6, 0x0, 0x2B, 0x0, 0x99, 0x0, 0xB3, 0x80, 0x2, 0x1, 0x1A, 0x0, 0x0 };
