#include "common.h"

extern int D_80800988_chtntbox[];
extern int D_808009D0_chtntbox[];
typedef struct { u8 pad_0[0x94]; u32 pad_1:15; u32 local_0:1; u32 pad_2:16; } TntBoxFlags;
typedef union { s32 word; Unk80132ED0 *marker; } TntBoxEventPayload;
extern void *func_800D674C(s32);
extern void *func_801027F4(Actor *);
extern void func_800DE448(f32 *, void *, f32, s32, void *);
extern int D_80800A80_chtntbox[];
extern s32 func_800C8A98(void);
extern u8 D_80800AC8_chtntbox[];
extern void func_800C8E54(s32, f32, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 steering : 1; u32 pad_2 : 29; } TntBoxSteering29;
extern f32 func_800D8FF8(void);
extern s32 func_80101E14(Actor *, f32);
extern s32 D_808008D0_chtntbox[];
extern s32 D_808008F4_chtntbox[];
extern int D_80800A18_chtntbox[];
extern s32 D_80800938_chtntbox[];
extern void func_800BBCB8(f32 *, void *, f32, s32, void *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80800A3C_chtntbox[];
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_80103EAC(Actor *);
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern f32 sqrtf(f32);
extern u8 D_80800A78_chtntbox[];
void func_8080015C_chtntbox();
void func_808003F0_chtntbox();
void func_808004F8_chtntbox();

int chtntbox_entrypoint_0()
{
    return (int)&D_80800988_chtntbox;
}

int *chtntbox_entrypoint_1()
{
    return &D_808009D0_chtntbox;
}

void func_80800018_chtntbox(Actor *param_0)
{
    *(u16 *)((u8 *)param_0 + 0x7C) = param_0->unk74_7 * 10 + 0x320;
    ((TntBoxFlags *)param_0)->local_0 = 1;
}

void func_80800044_chtntbox(Actor *param_0)
{
    s32 local_0;
    switch (param_0->unk70_10) {
    case 1:
        if (param_0->unk58 > 0.0f) {
            param_0->unk58 -= func_800D8FF8();
        } else {
            if (((TntBoxSteering29 *)param_0)->steering) local_0 = _subaddiejoy_entrypoint_6(param_0, 1) == 1;
            else local_0 = func_8010C9B0(param_0->position, param_0->unk74_7 * 10);
            if (local_0) func_80102424(param_0, 2);
        }
        break;
    case 2:
        if (func_80101E14(param_0, 0.3f)) func_80108B04(param_0, 0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 1);
            param_0->unk58 = 0.8f;
        }
        break;
    }
}





































void func_80800824_chtntbox(Actor *param_0, f32 param_1);

void func_8080015C_chtntbox(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += 80.0f;
    func_800BBCB8(local_0, 0, param_0->scale * 1.2f, 4, &D_808008D0_chtntbox);
    func_800BBCB8(local_0, local_0, param_0->scale * 1.2f, 0x10, &D_808008F4_chtntbox);
    func_800BBCB8(local_0, local_0, param_0->scale, 0xA, &D_80800A18_chtntbox);
    func_808003F0_chtntbox(param_0, local_0);
    func_80800824_chtntbox((Actor *)local_0, 1.2f);
    _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_80800938_chtntbox);
    func_800E1610(0, 20.0f, 0.9f, local_0);
    func_80018820(0, 2.0f, 0.25f);
    if (func_8010CEF8(param_0, (s32)(param_0->scale * 300.0f))) {
        func_800F7A7C(func_800F54E4(), -1, 2, 5, param_0->position);
    }
    if (!func_80107070(param_0, 3)) { func_800FFAB0(param_0); }
}

s32 func_808002FC_chtntbox(Actor *param_0, s32 param_1, TntBoxEventPayload param_2)
{
    switch (param_1) {
    case 64:
        func_8080015C_chtntbox(param_0, param_2.word);
        break;
    case 61:
        func_808004F8_chtntbox(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800358_chtntbox(Actor *param_0)
{
    func_80101870(param_0);
    if (param_0->unk7C_12) {
        func_80101970(param_0);
        func_800DF830(3);
        func_800DF410(_subaddiefade_entrypoint_0(param_0));
        func_800DE448(param_0->position, func_801027F4(param_0), param_0->scale * 0.25f, 0, func_800D674C(0x6AC));
    }
}

void func_808003F0_chtntbox(param_0, param_1) Actor *param_0; f32 *param_1;
{
    s32 local_1;
    f32 local_0[3];
    s32 local_2;

    local_1 = func_800B53A4(8);
    for (local_2 = 0; local_2 < 8; local_2++) {
        func_800EEB9C(local_0, local_2 * 45.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(local_0, param_1);
        func_800BABB8(local_1, local_0, param_1, 0.6f, D_80800A3C_chtntbox);
    }
}

void func_808004F8_chtntbox(param_0) Actor *param_0;
{
    Actor *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6[4];

    local_0 = func_801084B0(0x200, &param_0);
    func_8010D254(local_0->actorData);
    local_0->position[1] += 180.0f;
    local_5 = func_80103EAC(param_0);
    local_1 = func_800F0E00(local_5, func_800EFB8C(local_0->position, (f32 *)local_0->actorData));
    local_2 = local_0->position[1] - *(f32 *)&local_0->actorData[1];
    if (local_2 <= -local_1) {
        local_2 = local_1 - 10.0f;
    }
    local_4 = func_80102D78(local_0, (f32 *)local_0->actorData);
    local_0->rotation[1] = local_4;
    local_3 = sqrtf((local_1 * local_1 * 3800.0f) / (local_1 + local_2));
    func_800EEC30((f32 *)&local_0->actorData[4], 45.0f, local_0->rotation[1], local_3);
    _subaddiefade_entrypoint_9(param_0, local_6);
    _subaddiefade_entrypoint_11(local_0, local_6);
    _subaddieaudioquick_entrypoint_2(param_0, local_0->position, D_80800A78_chtntbox);
}

void func_808007B0_chtntbox();

void func_80800624_chtntbox(Actor *param_0)
{
    f32 local_0;
    f32 local_1[3];
    local_0 = func_800D8FF8();
    param_0->rotation[0] += 750.0f * local_0;
    param_0->rotation[2] += 40.0f * local_0;
    func_808007B0_chtntbox(param_0);
    if (func_8010B990(param_0, 0x400007) & 0x20) {
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 80.0f;
        func_800BBCB8(local_1, 0, param_0->scale, 4, &D_808008D0_chtntbox);
        func_800BBCB8(local_1, local_1, param_0->scale, 0x10, &D_808008F4_chtntbox);
        func_80800824_chtntbox((Actor *)local_1, 1.0f);
        _subaddieaudioquick_entrypoint_2(param_0, local_1, &D_80800938_chtntbox);
        func_800E1610(0, 20.0f, 0.9f, param_0->position);
        func_80018820(0, 2.0f, 0.25f);
        if (func_8010CEF8(param_0, 0xA0)) {
            func_80090494(5, param_0->position);
        }
        func_800FFAB0(param_0);
        return;
    }
    if (!func_800BFA1C(param_0->position)) {
        func_800FFAB0(param_0);
        return;
    }
    *(f32 *)((u8 *)param_0 + 0x2C) += -3800.0f * local_0;
}

void func_808007B0_chtntbox(s32 param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800BABB8(0, param_0 + 4, 0, 1.4f, &D_80800A80_chtntbox);
    if (func_8001211C() & 1) {
        local_1 = 0x9E3;
    } else {
        local_1 = 0x9E2;
    }
    func_800BA3FC(local_0, local_1);
    func_800BA22C(local_0, 1);
}

void func_80800824_chtntbox(Actor *param_0, f32 param_1)
{
    s32 local_0;
    local_0 = func_800C8A98();
    func_800C8CB8(local_0, param_0);
    func_800C8E84(local_0, D_80800AC8_chtntbox);
    func_800C8E54(local_0, param_1 * 400.0f, param_1 * 800.0f);
    _chlightfader_entrypoint_1(local_0, 1.4f, 5);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/tnt/box.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808008D0_chtntbox -> s32[], D_808008F4_chtntbox -> s32[], D_80800938_chtntbox -> s32[], D_80800988_chtntbox -> int[], D_808009D0_chtntbox -> int[], D_80800A18_chtntbox -> int[], D_80800A80_chtntbox -> int[] */
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern int func_80101870();
s32 D_808008D0_chtntbox[9] = { 0xC0050, 0x230200, 0x2B0100, 0x1190015, 0xB300CC, 0x1D09BB, 0x180000, 0x90C00, 0xC000000 };
s32 D_808008F4_chtntbox[17] = { 0x1D09EA, 0xE000F, 0x14002D, 0x2580320, 0x1BFB50, -0x3E7FFDC, 0x230042, 0x2A0000, 0x200CC, 0x1330015, 0x59, 0x160004, 0x190001, 0x60027, -0x12B012C, 0x12C012C, 0x0 };
s32 D_80800938_chtntbox[5] = { 0x130413, 0xD00E6, 0x1000001, 0x3E81964, 0x0 };
u32 D_8080094C_chtntbox[10] = { 0x0, 0x0, 0x3F99999A, 0x1EC0044, 0x3F99999A, 0x1EC0002, 0x0, 0x0, 0x3F99999A, 0x1EC0044 };
u32 D_80800974_chtntbox[5] = { 0x10000, 0x0, 0x0, 0x30000, 0x40000 };
int D_80800988_chtntbox[18] = { 0x90119, 0x68F0001, (u32)&D_8080094C_chtntbox, (u32)func_80800044_chtntbox, (u32)func_80105834, (u32)func_80800358_chtntbox, 0x0, 0x0, 0x0, 0x40000838, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800018_chtntbox, (u32)func_80107C2C, -0x7FDFDBEF, (u32)func_808002FC_chtntbox, (u32)&D_80800974_chtntbox };
int D_808009D0_chtntbox[18] = { 0x3E0200, 0x64B0001, 0x0, (u32)func_80800624_chtntbox, (u32)func_80105834, (u32)func_80101870, 0x0, 0x3F4CCCCD, 0x0, 0x4, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFFFF0, 0x0, 0x0 };
int D_80800A18_chtntbox[9] = { 0x1D06A3, 0x14002D, 0x2580320, 0x220066, 0x800033, 0x4C001E, 0x140014, 0xD003C, 0x0 };
u8 D_80800A3C_chtntbox[60] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x1, 0x0, 0x1, 0x66, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x4, 0x80, 0x5, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x99, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0x5E, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0xC0, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800A78_chtntbox[8] = { 0x0, 0x13, 0x4, 0xAC, 0x0, 0x0, 0x0, 0x0 };
int D_80800A80_chtntbox[18] = { 0x1100015, 0x33, 0x2CFFE2, 0x3CFFE2, 0x1E0064, 0x1E001B, -0x13FFE2, 0xAFFF6, 0xFFF6, 0xA0000, 0xA0022, 0xF0019, 0x23002E, 0x2B004C, 0x800015, 0x6600B3, 0x160004, 0x0 };
u8 D_80800AC8_chtntbox[24] = { 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xE0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
