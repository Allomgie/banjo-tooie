#include "common.h"

extern int D_808004C0_chelectricfence[];
extern void func_800BBCB8(s32, s32, float, s32, void *);
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern s32 func_800C8A98(void);
extern void func_800C8CB8(s32, s32);
extern void func_800C8E84(s32, void *);
extern void func_800C8E54(s32, s32, s32);
extern void _chlightfader_entrypoint_1(s32, s32, int);
extern void *D_80800558_chelectricfence;
extern void *D_8080051C_chelectricfence;
extern void *D_8080058C_chelectricfence;
extern void *D_80800598_chelectricfence;
extern u8 D_808005A4_chelectricfence[];
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800BABB8(s32, void *, s32, f32, void *);
extern void func_800BA8F8(s32, f32, f32);
extern u8 D_80800508_chelectricfence[];
extern f32 func_800EC75C(void *, f32 *);

int *chelectricfence_entrypoint_0()
{
    return &D_808004C0_chelectricfence;
}

int func_8080000C_chelectricfence(s32 param_0)
{
  if (func_800EA05C() == 0x124) {
    func_8010A624(param_0);
    func_8010A570(param_0);
  }
  func_80104004(param_0, param_0 + 0x18, param_0 + 0x28);
}

void chelectricfence_entrypoint_2();

void func_80800060_chelectricfence(Actor *param_0)
{
    if (func_800D9078(&param_0->unk58)) func_8010A590(param_0);
    _subaddieaudioloop_entrypoint_5(param_0, param_0->position, param_0->unk70_10 == 1, -1, D_80800508_chelectricfence);
    if (param_0->unk70_10 == 1 && param_0->unk7C_12 && func_800DC298(0.2f)) {
        chelectricfence_entrypoint_2(param_0, (f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[4]);
    }
}

void chelectricfence_entrypoint_1();

s32 func_8080010C_chelectricfence(Actor *param_0, s32 param_1, u32 *param_2)
{
    f32 local_0[3];
    u32 *local_1;

    switch (param_1) {
        case 0x3F:
            local_1 = *(u32 **)&param_2;
            func_800EC75C(local_1, local_0);
            chelectricfence_entrypoint_1((s32)param_0, (s32)local_0);
            param_0->unk58 = 0.2f;
            func_8010A570(param_0);
            if (local_1[0x24 / 4] >> 22 == 0) {
            }
            break;
        case 0x95:
            func_8010A5B0(param_0, func_800F6438(func_800F54E4()) &&
                            !func_800F64A4(func_800F54E4(), 0x8000));
            break;
        default: return 0;
    }
    return 1;
}

void chelectricfence_entrypoint_1(s32 param_0, s32 param_1) {
    s32 sp2C;
    s32 temp_v0;

    func_800BBCB8(param_1, param_1, 1.0f, 3, &D_80800558_chelectricfence);
    func_800BBCB8(param_1, param_1, 1.0f, 12, &D_8080051C_chelectricfence);
    _subaddieaudioquick_entrypoint_2(param_0, param_1, &D_8080058C_chelectricfence);
    temp_v0 = func_800C8A98();
    sp2C = temp_v0;
    func_800C8CB8(temp_v0, param_1);
    func_800C8E84(sp2C, &D_80800598_chelectricfence);
    func_800C8E54(sp2C, 0x43960000, 0x44160000);
    _chlightfader_entrypoint_1(sp2C, 0x3F4CCCCD, 5);
}

void chelectricfence_entrypoint_2(Actor *param_0, f32 *param_1, f32 *param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    f32 local_5;

    local_3 = func_800DC298(0.5f) ? param_1[2] : param_2[2];
    func_800EFA4C(local_0, func_800DC178(param_1[0], param_2[0]), func_800DC178(param_1[1], param_2[1]), local_3);
    func_800EFA4C(local_1, func_800DC178(param_1[0], param_2[0]), func_800DC178(param_1[1], param_2[1]), local_3);
    func_800EF934(local_0, local_0, param_0->rotation[1]);
    func_800EF04C(local_0, param_0->position);
    func_800EF934(local_1, local_1, param_0->rotation[1]);
    func_800EF04C(local_1, param_0->position);
    func_800EFB24(local_2, local_1, local_0);
    func_800EF368(local_2, 400.0f);
    local_5 = func_800EEAD4(local_1, local_0) / 500.0f;
    local_4 = func_800B5BE4(0x12);
    func_800BABB8(local_4, local_0, 0, 1.8f, D_808005A4_chelectricfence);
    func_800BA930(local_4, (s16)local_2[0], (s16)local_2[1], (s16)local_2[2],
        (s16)local_2[0], (s16)local_2[1], (s16)local_2[2]);
    func_800BA8F8(local_4, local_5, local_5);
    func_800BA22C(local_4, 1);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/electricfence.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808004C0_chelectricfence -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808004C0_chelectricfence[18] = { 0x33103D3, 0x79D0001, 0x0, (u32)func_80800060_chelectricfence, (u32)func_80105834, (u32)func_80101870, 0x17700000, 0x0, 0x0, 0xC00, 0x0, (u32)func_80108ED0, 0x0, (u32)func_8080000C_chelectricfence, (u32)func_80107C2C, -0x7FFFE000, (u32)func_8080010C_chelectricfence, 0x0 };
u8 D_80800508_chelectricfence[20] = { 0x0, 0x13, 0x5, 0xB7, 0x0, 0xE, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x19, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0 };
void *D_8080051C_chelectricfence = (void *)0x001D09CD;
static u32 D_8080051C_chelectricfence_rest[14] = { 0x1BFC18, 0xFCE0002D, 0x12C0190, 0xE0014, 0x140016, 0x11000018, 0x1, 0xA000F00, 0x220040, 0x590019, 0x330015, 0xCC, 0x2B0119, 0x14C0000 };
void *D_80800558_chelectricfence = (void *)0x001D09DD;
static u32 D_80800558_chelectricfence_rest[12] = { 0x2D000A, 0x1E000E, 0x140014, 0x20C0C0, 0xC0C00016, 0x80022, 0xCC0100, 0x1330166, 0x150000, 0x99002B, 0x119014C, 0x0 };
void *D_8080058C_chelectricfence = (void *)0x001304B0;
static u32 D_8080058C_chelectricfence_rest[2] = { 0xA014C, 0x180000 };
void *D_80800598_chelectricfence = (void *)0x000000E0;
static u32 D_80800598_chelectricfence_rest[2] = { 0xE0, 0xFF };
u8 D_808005A4_chelectricfence[60] = { 0x0, 0x34, 0x0, 0x1D, 0x9, 0xCD, 0x0, 0x16, 0x12, 0x0, 0x0, 0x18, 0x0, 0x0, 0x0, 0x4, 0x1E, 0x0, 0x23, 0x0, 0x0, 0x22, 0x0, 0x40, 0x0, 0x59, 0x0, 0x19, 0x0, 0x33, 0x0, 0x15, 0x0, 0x19, 0x0, 0xE6, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
