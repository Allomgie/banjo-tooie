#include "common.h"

extern int D_80800680_chgruntyfireballbig[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern s32 D_808006C8_chgruntyfireballbig[];
extern s32 D_808006E0_chgruntyfireballbig[];
extern f32 func_800D8FF8(void);
extern void func_80018820(s32, f32, f32);
extern void func_800E15CC(s32, f32, f32);
extern u8 D_8080070C_chgruntyfireballbig[];
extern u8 D_808006F8_chgruntyfireballbig[];
extern f32 func_80101068(void);
extern void func_800EF368(f32 *, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern s32 D_80800714_chgruntyfireballbig[];
extern s32 D_80800724_chgruntyfireballbig[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void func_800EF334(f32 *, f32);
extern u8 D_80800754_chgruntyfireballbig[];
extern u8 D_80800788_chgruntyfireballbig[];
void func_8080034C_chgruntyfireballbig();
void func_80800590_chgruntyfireballbig();
void func_808004C4_chgruntyfireballbig();

int chgruntyfireballbig_entrypoint_0()
{
    return (int)&D_80800680_chgruntyfireballbig;
}

void func_8080000C_chgruntyfireballbig(s32 param_0)
{
  s32 new_var;
  int new_var2;
  s32 result;
  *(s32 *)(param_0 + 0x24) = 0;
  result = func_80109EEC(param_0, 64);
  return;
}

void func_80800030_chgruntyfireballbig(Actor *param_0)
{
    f32 local_0;
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_808006C8_chgruntyfireballbig);
    switch (param_0->unk70_10) {
    case 1: func_808004C4_chgruntyfireballbig(param_0); break;
    case 2:
        func_80800590_chgruntyfireballbig(param_0);
        if (func_8010B990(param_0, 0x400007) & 0x20) {
            func_80018820(0, 1.2f, 0.22f);
            func_800E15CC(0, 24.0f, 0.84f);
            func_8080034C_chgruntyfireballbig(param_0);
        } else func_808004C4_chgruntyfireballbig(param_0);
        break;
    case 3:
        local_0 = func_800D8FF8();
        func_808004C4_chgruntyfireballbig(param_0);
        param_0->position[1] -= *(f32 *)((u8 *)param_0 + 0x20) * local_0;
        *(f32 *)((u8 *)param_0 + 0x20) = 800.0f * local_0 + *(f32 *)((u8 *)param_0 + 0x20);
        if (param_0->position[1] <= *(f32 *)((u8 *)param_0 + 0x1C)) func_800FFAB0(param_0);
        break;
    }
    if (*(s32 *)((u8 *)param_0 + 0x24)) {
        func_800C8CB8(*(s32 *)((u8 *)param_0 + 0x24), param_0->position);
        func_800C8E84(*(s32 *)((u8 *)param_0 + 0x24), (u8 *)&D_808006E0_chgruntyfireballbig + func_8001210C(1) * 12);
    }
}

int func_808001B4_chgruntyfireballbig(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    s32 local_1;
    switch (param_1) {
        case 0xA:
            param_0->unk6C_0 = (param_2 >> 16) & 0x1FF;
            *(f32 *)param_0->actorData = func_80101068();
            func_8010A590(param_0);
            func_80101FDC(param_0, 2);
            func_800F5A00(param_0->unk6C_0, local_0);
            local_0[1] += 50.0f;
            func_800EFB24((f32 *)((u8 *)param_0 + 0x28), local_0, param_0->position);
            func_800EF368((f32 *)((u8 *)param_0 + 0x28), (f32)(param_2 & 0xFFFF));
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808006F8_chgruntyfireballbig);
            return 1;
        case 0x40: func_8080034C_chgruntyfireballbig(param_0); return 1;
        case 0x95:
            param_0->actorData[3] = func_800C8A98();
            func_800C8CB8(param_0->actorData[3], param_0->position);
            func_800C8D4C(param_0->actorData[3], D_8080070C_chgruntyfireballbig);
            return 1;
        case 0x9B:
            func_80101FDC(param_0, 3);
            ((f32 *)param_0->actorData)[1] = param_2;
            ((f32 *)param_0->actorData)[2] = -150.0f;
            local_1 = param_0->actorData[3];
            if (local_1) {
                param_0->actorData[3] = _chlightfader_entrypoint_1(local_1, 1.5f, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080034C_chgruntyfireballbig(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_3;
    s32 local_4;
    func_8010A570(param_0);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800714_chgruntyfireballbig);
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += -10.0f;
    local_3 = func_800B53A4(10);
    for (local_4 = 0; local_4 < 10; local_4++) {
        func_800EEB9C(local_1, local_4 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(local_1, param_0->position);
        func_800BABB8(local_3, local_1, local_0, 1.0f, &D_80800724_chgruntyfireballbig);
    }
    if (*(s32 *)((u8 *)param_0 + 0x24)) *(s32 *)((u8 *)param_0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)((u8 *)param_0 + 0x24), 1.5f, 2);
    func_800FFAB0(param_0);
}

void func_808004C4_chgruntyfireballbig(param_0) Actor *param_0;
{
    f32 local_0[3];

    func_800BBCB8(param_0->position, (s32)param_0->position, param_0->scale * 1.2f, 1, D_80800788_chgruntyfireballbig);
    func_800EE7F8(local_0, (f32 *)&param_0->actorData[4]);
    func_800EF368(local_0, 100.0f);
    func_800EF334(local_0, -1.0f);
    func_800EF04C(local_0, param_0->position);
    func_800BBCB8(local_0, (s32)param_0->position, param_0->scale * 0.8f, 1, D_80800754_chgruntyfireballbig);
}

void func_80800590_chgruntyfireballbig(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[2];
    f32 local_2;

    if (!param_0->unk64_20 && func_800F6438(param_0->unk6C_0)) {
        func_800F5A00(param_0->unk6C_0, local_0);
        local_0[1] += 50.0f;
        if (func_800EEB40(param_0->position, local_0) <
            ((f32 *)param_0->actorData)[0] * ((f32 *)param_0->actorData)[0]) {
            param_0->unk64_20 = 1;
        } else {
            func_800F18FC(param_0->position, local_0, local_1);
            local_2 = func_800EEF94((f32 *)&param_0->actorData[4]);
            func_800EEBF0((f32 *)&param_0->actorData[4], local_1, local_2);
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/grunty/fireballbig.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800680_chgruntyfireballbig -> int[], D_808006C8_chgruntyfireballbig -> s32[], D_808006E0_chgruntyfireballbig -> s32[], D_80800714_chgruntyfireballbig -> s32[], D_80800724_chgruntyfireballbig -> s32[] */
extern void func_80102EC0();
extern void func_8010A73C();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800680_chgruntyfireballbig[18] = { 0x2B004F6, 0x6FB0001, 0x0, (u32)func_80800030_chgruntyfireballbig, (u32)func_80102EC0, (u32)func_8010A73C, 0x0, 0x0, 0x0, 0x4, 0x0, (u32)func_80108ED0, 0x0, (u32)func_8080000C_chgruntyfireballbig, (u32)func_80107C2C, -0x7FFFFFFE, (u32)func_808001B4_chgruntyfireballbig, 0x0 };
s32 D_808006C8_chgruntyfireballbig[6] = { 0x13052E, 0x180001, 0x3E81F40, 0xE00D9, 0xF30166, 0x0 };
s32 D_808006E0_chgruntyfireballbig[6] = { 0xFF, 0x60, 0xFF, 0xFF, 0xFF, 0xFF };
u8 D_808006F8_chgruntyfireballbig[20] = { 0x0, 0x13, 0x4, 0x90, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x18, 0x0, 0x1, 0x3, 0xE8, 0x1F, 0x40, 0x0, 0x0 };
u8 D_8080070C_chgruntyfireballbig[8] = { 0x43, 0xAF, 0x0, 0x0, 0x44, 0x9, 0x80, 0x0 };
s32 D_80800714_chgruntyfireballbig[4] = { 0x130491, 0x180001, 0x3E81770, 0x0 };
s32 D_80800724_chgruntyfireballbig[12] = { 0x1D09E9, 0x15000C, 0x990022, 0x1000100, 0x660066, 0x270064, 0x6400C8, 0xC8002B, 0x59008C, 0x2D00C8, 0x12C011A, 0x0 };
u8 D_80800754_chgruntyfireballbig[52] = { 0x0, 0x1D, 0x9, 0xE9, 0x0, 0xE, 0x0, 0x32, 0x0, 0x3C, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x22, 0x1, 0x0, 0x1, 0x0, 0x0, 0x66, 0x0, 0x66, 0x0, 0x27, 0x0, 0x64, 0x0, 0x64, 0x0, 0xC8, 0x0, 0xC8, 0x0, 0x2B, 0x0, 0x40, 0x0, 0x59, 0x0, 0x2D, 0x0, 0xC8, 0x1, 0x2C, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800788_chgruntyfireballbig[88] = { 0x0, 0x1D, 0x9, 0xBC, 0x0, 0x19, 0x0, 0x1, 0x0, 0x5, 0x0, 0x1B, 0x1, 0x31, 0x2, 0x42, 0x0, 0x2D, 0x0, 0x9, 0x0, 0xF, 0x0, 0xE, 0x0, 0xA, 0x0, 0x14, 0x0, 0x16, 0x6, 0x0, 0x0, 0x26, 0xFE, 0xF4, 0xFF, 0x26, 0xFF, 0x27, 0x0, 0xE3, 0x0, 0xCD, 0x0, 0xF7, 0x0, 0x22, 0x1, 0xCC, 0x2, 0x0, 0x0, 0x40, 0x0, 0x59, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x2B, 0x0, 0x66, 0x0, 0x80, 0x0, 0x2F, 0x0, 0x17, 0x0, 0x19, 0x0, 0x19, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xEE, 0x0, 0x0, 0x0, 0x0 };
