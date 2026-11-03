#include "common.h"

extern void *D_808005D0_changlerbossbubble;
extern void func_800EC75C(void *arg0, f32 *arg1);
extern void func_800EFD4C();
extern f32 func_800D8FF8(void);
extern void func_80015E80(s32, s32 *);
typedef struct { u8 pad0[0x18]; u32 pad18 : 16; u32 id : 11; u32 lo18 : 5; u32 pad1C; u32 pad20; u32 hi24 : 10; u32 lo24 : 22; } BubbleArg;
extern f32 func_800F5BF0(s32, f32 *);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80800668_changlerbossbubble[];
extern u8 D_80800618_changlerbossbubble[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA568();
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern s32 _chbubble_entrypoint_0(s32, f32 *, f32 *, f32, f32);
void func_80800450_changlerbossbubble();
void func_80800334_changlerbossbubble();

int changlerbossbubble_entrypoint_0()
{
  return (int)&D_808005D0_changlerbossbubble;
}

void func_8080000C_changlerbossbubble(Actor *param_0)
{
    f32 sp1C[3];
    func_800EC75C(*(s32 **)param_0, sp1C);
    func_800EFD4C((void *)((u8 *)*(void **)param_0 + 0x1E));
    *(f32 *)((u8 *)param_0 + 0x34) = 0.75f;
}

void func_80800054_changlerbossbubble(Actor *param_0)
{
    s32 local_0[6];
    s32 local_1;

    param_0->unk58 += func_800D8FF8();
    func_800EFD4C((u8 *)param_0->unk0 + 0x1E);
    switch (param_0->unk70_10) {
        case 1:
            if (func_8010B990(param_0, 0x400007) & 0x20) func_80800334_changlerbossbubble(param_0);
            break;
        case 2:
            local_1 = func_800F54F0(param_0->unk6C_0);
            func_80800450_changlerbossbubble(param_0);
            func_80015E80(local_1, local_0);
            if (local_0[0] == 1 || local_0[1] == 1) {
                if (++*(s32 *)((u8 *)param_0 + 0x1C) >= 10) {
                    func_800F7B9C(param_0->unk6C_0, 0x70);
                    return;
                }
                func_800F7B9C(param_0->unk6C_0, 0x7B);
            }
            if (func_800D9078(param_0->actorData)) {
                if (param_0->unk3C) func_8010114C(param_0->unk3C, 0xA, 0);
            }
            break;
    }
}

int func_80800194_changlerbossbubble(s32 param_0)
{
  s32 local_0;
  if (!func_800F64A4(param_0, 0xA01))
  {
    return 0;
  }
  if (!func_800F6D24(param_0))
  {
    return 1;
  }
  local_0 = func_800F8B88();
  if (local_0 == 3)
  {
    return 1;
  }
  return 0;
}

s32 func_80800200_changlerbossbubble(Actor *param_0, s32 param_1, Unk80132ED0 *param_2)
{
    BubbleArg *arg;

    switch (param_1) {
        case 0x2C:
            func_80800334_changlerbossbubble(param_0);
            break;
        case 0x3E:
            arg = *(BubbleArg **)&param_2; /* Adresse: param_2 im Heimatslot, arg (Def+4 Uses=5 > f24 19/4) in s1 */
            if (arg->hi24 == 0 && func_80800194_changlerbossbubble(arg->id) &&
                func_800F7BC8(arg->id, 0x6F, param_0->unk0) == 2) {
                func_8010A570(param_0);
                func_80101FDC(param_0, 2);
                *(f32 *)&param_0->actorData[0] = 3.0f;
                param_0->unk6C_0 = arg->id;
                func_80102FDC(param_0, func_800F5BF0(param_0->unk6C_0, param_0->position) * 0.015f);
                break;
            }
            func_80800334_changlerbossbubble(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800334_changlerbossbubble(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    f32 local_2;
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800668_changlerbossbubble);
    local_0 = func_800DC128(3, 4);
    local_1 = func_800B53A4(local_0);
    local_2 = param_0->scale;
    func_800BABB8(local_1, param_0->position, param_0->position, 1.0f, D_80800618_changlerbossbubble);
    func_800BA568(local_1, (s16)(param_0->position[1] + 1000.0f));
    func_800BA7C4(local_1, 0.25f * local_2, 0.6f * local_2);
    func_800BA7FC(local_1, 0.1f * local_2, 0.2f * local_2);
    func_800BA22C(local_1, local_0);
    func_800FFA88(param_0->unk0);
}

void func_80800450_changlerbossbubble(param_0) u8 *param_0; {
    func_800F5BF0((*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF, (f32 *)(param_0 + 4));
}

void func_80800480_changlerbossbubble(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[2];
    func_800EE7F8(local_1, param_0->position);
    func_800E3980(local_0);
    func_800F18FC(local_1, local_0, local_2);
    func_800EEBF0(local_0, local_2, 75.0f);
    func_800EF04C(local_1, local_0);
    local_2[0] = func_80013970(func_800F13C4(param_0->unk58, *(f32 *)((u8 *)param_0 + 0x34))
        / *(f32 *)((u8 *)param_0 + 0x34) * 360.0f) * 0.1f + 1.0f;
    local_2[1] = func_800138D0(func_800F13C4(param_0->unk58, *(f32 *)((u8 *)param_0 + 0x34))
        / *(f32 *)((u8 *)param_0 + 0x34) * 360.0f) * 0.15f + 1.0f;
    param_0->unk7C_12 = _chbubble_entrypoint_0(param_1, local_1, local_2, param_0->scale, 0.0f);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/anglerboss/bubble.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_808005D0_changlerbossbubble = (void *)0x02A90460;
static u32 D_808005D0_changlerbossbubble_rest[17] = { 0x9CB0001, 0x0, (u32)func_80800054_changlerbossbubble, (u32)func_80105834, (u32)func_80800480_changlerbossbubble, 0x0, 0x0, 0x0, 0x4, 0x0, (u32)func_80108ED0, 0x0, (u32)func_8080000C_changlerbossbubble, (u32)func_80107C2C, 0x0, (u32)func_80800200_changlerbossbubble, 0x0 };
u8 D_80800618_changlerbossbubble[80] = { 0x0, 0x1D, 0x9, 0xCB, 0x0, 0x16, 0x12, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x23, 0x0, 0x0, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0, 0x7, 0x0, 0x1, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0xE, 0x0, 0x32, 0x0, 0x3C, 0x0, 0x2D, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x80, 0x0, 0x1F, 0x50, 0xF0, 0xFF, 0x0, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0 };
u8 D_80800668_changlerbossbubble[24] = { 0x0, 0x13, 0x4, 0xB1, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
