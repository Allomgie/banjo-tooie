#include "common.h"
extern s32 D_80803BD0_chjiggygamenew[][3];
extern s32 D_80803AE0_chjiggygamenew[][3];

#define CODEX_JIGGY_MENU_RECORD
#define JIGGY_DISTANCE49 (((local_0[0] - local_1[0]) * (local_0[0] - local_1[0])) + ((local_0[1] - local_1[1]) * (local_0[1] - local_1[1])))
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800E4140(f32 *, f32 *);
typedef struct { s8 unk0; u8 pad1[3]; u16 unk4; u8 pad6[2]; f32 unk8; u8 padC[0xC]; } JiggyMenuRecord;
typedef struct { s8 unk0; s8 unk1; u8 unk2; s8 unk3; u16 type; u8 pad6[2]; f32 unk8; f32 unkC[3]; } JiggyGameSlot_8080020C_chjiggygamenew;
typedef struct { JiggyGameSlot_8080020C_chjiggygamenew slots[20]; u8 pad1E0[0x28]; s8 unk208[20]; } JiggyGameData;
extern u8 *func_80100094(Actor *, s32);
extern void rom_read_word(u32, u32 *);
typedef struct { s8 local_0; s8 local_1; u8 local_2; u8 pad_0; s16 local_3; s16 pad_1; f32 local_4; u8 pad_2[0xC]; } JiggyTile88;
typedef struct { JiggyTile88 local_0[20]; u8 pad_0[0x14]; s8 local_1[20]; s8 local_2[20]; } JiggyGameData88;
extern f32 func_800DC1AC(void);
typedef struct { u8 pad_0[4]; u16 local_0; u8 pad_1[2]; f32 local_1; u8 pad_2[12]; } JiggyGameCell;
typedef struct { u8 unk0; s8 unk1; u8 unk2; u8 unk3; u16 type; u8 pad6[2]; f32 unk8; f32 unkC[3]; } JiggyGameSlot_80800B88_chjiggygamenew;
typedef struct { u8 pad_0[4]; u16 local_0; u8 pad_1[18]; } JiggyGameSolvedCell;
typedef struct { u8 pad0[4]; u16 unk4; u8 pad6[0x12]; } JiggyGameRecord;
extern f32 _sujiggy_entrypoint_3(s32);
extern void func_800CE8D8(s32, f32, s32);
extern s32 _sujiggy_entrypoint_12(void);
extern void *_gldbstring_entrypoint_0(s32, s32);
extern u8 *_gldbstring_entrypoint_1(void *, s32);
extern void _gldbstring_entrypoint_2(s32);
extern f32 D_80803D10_chjiggygamenew[];
extern f32 D_80803D1C_chjiggygamenew[];
extern f32 D_80803D28_chjiggygamenew;
extern void func_800E3C8C(f32, f32);
extern s32 D_80803DCC_chjiggygamenew[];
extern s32 D_80803DD8_chjiggygamenew[];
extern u8 D_80803DF8_chjiggygamenew[];
extern u8 D_80803DE4_chjiggygamenew[];
extern u16 *func_80014F00(void);
extern s32 D_80803E50_chjiggygamenew[];
extern int D_80803EBC_chjiggygamenew[];
extern u32 _sujiggy_entrypoint_24(void);
extern void func_800C9C34(f32, s32, s32, s32);
extern void func_800C9DE4(f32, void (*)(s32), s32);
extern void func_800FC6B0(s32);
extern s32 func_8010262C(Unk80132ED0 *, u32);
extern void func_800E0ACC(void *);
extern void func_800E0AF0(void *, f32);
extern void func_800E0C20(void *, u8, f32, f32, f32, f32);
extern void func_800E0AFC(void *, u8, f32, f32, f32, f32);
extern void func_800E0B8C(void *, u8, f32, f32, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 func_800D90A4(f32 *);
extern s32 func_800D91EC(f32 *, f32);
typedef struct { s32 unk0 : 8; s32 unk1 : 8; u32 unk2 : 8; u32 unk3 : 8; u16 unk4; u8 pad6[2]; f32 unk8; f32 unkC[3]; } JiggyPieceRecord;
extern f32 D_80803D8C_chjiggygamenew[][4];
extern u8 D_80803DBC_chjiggygamenew[];
extern u8 D_80803DAC_chjiggygamenew[];
typedef struct { u8 pad_0[0x90]; s16 local_0; } JiggyGameEvent441;
extern f32 func_800D8FF8(void);
extern void func_800CE980(s32, f32, s32);
typedef struct { struct { u8 b[0x1E]; } arr[1]; } ArrV1E;
typedef struct { u32 w0, w1; } GfxW;
extern void func_800DE498(GfxW **, f32 *, f32 *, f32, f32 *, s32);
extern s32 func_800D674C(s32);
extern void func_800DF830(s32);
extern void *func_800E81D0(void);
extern void _fxkern_entrypoint_3(f32);
extern void func_800B8C8C(s32);
extern void _fxkern_entrypoint_1(GfxW **, s32, s32);
extern void func_80102FDC(u8 *, f32);
extern s32 func_800E71B8();
typedef union { s32 local_0; s16 local_1[2]; } JiggyGameDialogEvent;
typedef struct { f32 origin[3]; u8 padC[0x1C]; s32 selected; s32 hovered; f32 accelerationX; f32 accelerationY; s32 previousButtons; f32 previousX; f32 previousY; } JiggyCursorData;
extern OSContPad *func_800169A8(void);
extern f32 func_800D9004(void);
extern f32 func_80015D60(s32, s32, s32);
extern f32 mlAbsF(f32);
extern void func_80102424(Actor *, s32);
extern s32 func_80101DDC(Actor *);
extern void func_800FC660(u32);
extern s32 _sujiggy_entrypoint_21(void);
extern void func_800FC63C(u32, u32);
extern void func_800C9E20(f32, u32 *, u32, u32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800C3F14(s32, f32);
extern void func_800C3E88(s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
extern u32 D_80803E98_chjiggygamenew[];
extern f32 D_80803EA4_chjiggygamenew[3];
extern f32 D_80803EB0_chjiggygamenew[3];
extern void func_800EF04C(f32 *, f32 *);
extern void func_800E7DE4(void *, s32, s32, s32, s32);
extern void func_80101870(Actor *, void *);
extern u8 D_80803F04_chjiggygamenew[];
extern u8 D_80803F14_chjiggygamenew[];
extern void func_800EDE54(void *, void *, void *, f32);
void func_80803668_chjiggygamenew();
extern void func_80102EC0(), func_80107C2C();
extern u8 D_80803D34_chjiggygamenew[];
extern void *D_80803D44_chjiggygamenew[];

int chjiggygamenew_entrypoint_0();
int func_8080000C_chjiggygamenew(Unk80132ED0 *param_0);
s32 func_80800030_chjiggygamenew(Unk80132ED0 *param_0, s32 param_1);
void func_80800158_chjiggygamenew(Unk80132ED0 *param_0);
s32 func_8080020C_chjiggygamenew(Unk80132ED0 *param_0, s32 param_1);
void func_80800368_chjiggygamenew(Unk80132ED0 *param_0);
void func_80800424_chjiggygamenew(Unk80132ED0 *param_0);
void func_808004E0_chjiggygamenew(Unk80132ED0 *param_0);
void func_808006E0_chjiggygamenew(Unk80132ED0 *param_0, s32 param_1, s32 param_2);
int func_808007BC_chjiggygamenew(Unk80132ED0 *param_0);
void func_808007E4_chjiggygamenew();
void func_80800834_chjiggygamenew(Actor *param_0);
void func_80800AF8_chjiggygamenew(Actor *param_0);
void func_80800B88_chjiggygamenew(Actor *param_0);
void func_80800CC0_chjiggygamenew(Actor *param_0);
int func_808019E0_chjiggygamenew(Actor *param_0);
int func_80801C20_chjiggygamenew(Actor *param_0);
int func_80801CB0_chjiggygamenew(s32 param_0, s32 param_1, JiggyGameRecord *param_2);
void func_80801CE8_chjiggygamenew(Actor *param_0);
void func_80801E4C_chjiggygamenew(Actor *param_0, s32 param_1);
void func_8080245C_chjiggygamenew(s32 arg0);
f32 func_80802464_chjiggygamenew(s32 param_0);
void func_808024C8_chjiggygamenew(s32 arg0);
void chjiggygamenew_entrypoint_1(void);
void chjiggygamenew_entrypoint_2(void);
int chjiggygamenew_entrypoint_3();
void func_80802E80_chjiggygamenew(u8 *param_0);
void func_80802F3C_chjiggygamenew(Actor *param_0);
void func_80803564_chjiggygamenew(s32 arg0);
void func_8080356C_chjiggygamenew(Unk80132ED0 *param_0);
void func_80803598_chjiggygamenew(Unk80132ED0 *param_0);
void func_808035C4_chjiggygamenew();
int func_808035FC_chjiggygamenew(s32 param_0, f32 *param_1);
int func_8080363C_chjiggygamenew(Unk80132ED0 *param_0);
int * chjiggygamenew_entrypoint_4();
void func_8080377C_chjiggygamenew(Actor *param_0);
s32 func_80803928_chjiggygamenew(s32 param_0, s32 *param_1);
int chjiggygamenew_entrypoint_0()
{
    return &D_80803D44_chjiggygamenew;
}

int func_8080000C_chjiggygamenew(Unk80132ED0 *param_0)
{
  int *local_0;
  local_0 = (int *)func_80106790(param_0);
  return local_0[8];
}

s32 func_80800030_chjiggygamenew(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;
    JiggyMenuRecord *local_1;

    local_0 = func_80106790(param_0);
    local_1 = func_80100094(local_0, 0);
    if (param_1 < 20) {
        if (local_1[*(s8 *)((u8 *)local_1 + 0x1F4 + param_1)].unk4 == 0x6B54 ||
            local_1[*(s8 *)((u8 *)local_1 + 0x1F4 + param_1)].unk4 == 0xC) {
            local_1[*(s8 *)((u8 *)local_1 + 0x1F4 + param_1)].unk8 = 0.0f;
            func_808007E4_chjiggygamenew(local_1, 0x78, *(s8 *)((u8 *)local_1 + 0x1F4 + param_1));
            local_0->actorData[3] = *(s8 *)((u8 *)local_1 + 0x1F4 + param_1);
            *(s8 *)((u8 *)local_1 + 0x1F4 + param_1) = -1;
            return 1;
        }
        return 0;
    }
    param_1 -= 20;
    if (*(s8 *)((u8 *)local_1 + 0x208 + param_1) != -1) {
        local_1[*(s8 *)((u8 *)local_1 + 0x208 + param_1)].unk8 = 0.0f;
        func_808007E4_chjiggygamenew(local_1, 0xF54, *(s8 *)((u8 *)local_1 + 0x208 + param_1));
        local_0->actorData[3] = *(s8 *)((u8 *)local_1 + 0x208 + param_1);
        *(s8 *)((u8 *)local_1 + 0x208 + param_1) = -1;
        return 2;
    }
    return 0;
}

void func_80800158_chjiggygamenew(Unk80132ED0 *param_0)
{
  s32 *s0;
  s32 local_0;
  s32 local_1;
  s0 = (s32 *)func_80106790(param_0);
  local_0 = func_80100094(s0, 0);
  *((f32 *) ((((char *) local_0) + ((*((s32 *) (((char *) s0) + 0x24))) * 0x18)) + 8)) = 0;
  func_808007E4_chjiggygamenew(local_0, 0xEB0, *((s32 *) (((char *) s0) + 0x24)));
  func_808035C4_chjiggygamenew(*((s32 *) (((char *) s0) + 0x3C)), (local_0 + ((*((s32 *) (((char *) s0) + 0x24))) * 0x18)) + (local_1 = 0xC));
  ;
  if (0)
  {
  }
  *((s8 *) ((((char *) local_0) + (*((s8 *) ((((char *) local_0) + ((*((s32 *) (((char *) s0) + 0x24))) * 0x18)) + 1)))) + 0x1F4)) = (s8) (*((s32 *) (((char *) s0) + 0x24)));
  *((s32 *) (((char *) s0) + 0x24)) = -1;
}

s32 func_8080020C_chjiggygamenew(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;
    JiggyGameData *local_1;

    local_0 = func_80106790(param_0);
    local_1 = func_80100094(local_0, 0);
    if (local_1->unk208[param_1] == -1) {
        if (param_1 == *(s32 *)((u8 *)local_0 + 0x24) && local_1->slots[*(s32 *)((u8 *)local_0 + 0x24)].unk0 == 0) {
            local_1->slots[*(s32 *)((u8 *)local_0 + 0x24)].unk8 = 0.0f;
            func_808007E4_chjiggygamenew(local_1, 0x2E4, *(s32 *)((u8 *)local_0 + 0x24));
            func_808035C4_chjiggygamenew(local_0->unk3C, local_1->slots[*(s32 *)((u8 *)local_0 + 0x24)].unkC);
            return 1;
        }
        if (local_1->slots[param_1].type != 0x18 && local_1->unk208[param_1] == -1) {
            local_1->slots[*(s32 *)((u8 *)local_0 + 0x24)].unk8 = 0.0f;
            func_808007E4_chjiggygamenew(local_1, 0x194, *(s32 *)((u8 *)local_0 + 0x24));
            func_808035C4_chjiggygamenew(local_0->unk3C, local_1->slots[*(s32 *)((u8 *)local_0 + 0x24)].unkC);
            local_1->slots[*(s32 *)((u8 *)local_0 + 0x24)].unk3 = param_1;
            local_1->unk208[param_1] = *(s32 *)((u8 *)local_0 + 0x24);
            return 0;
        }
    }
    return -1;
}

void func_80800368_chjiggygamenew(Unk80132ED0 *param_0)
{
    Actor *local_0;
    JiggyMenuRecord *local_1;
    s32 local_2;

    local_0 = func_80106790(param_0);
    local_1 = func_80100094(local_0, 0);
    local_2 = local_0->actorData[3];
    if (local_1[local_2].unk4 != 0x800) {
        if (local_1[local_2].unk4 == 0x1FFF) {
            local_1[local_2].unk0--;
        }
    } else {
        local_1[local_2].unk0++;
    }
    if (local_1[local_2].unk0 < 0) {
        local_1[local_2].unk0 += 4;
    }
    if (local_1[local_2].unk0 >= 4) {
        local_1[local_2].unk0 -= 4;
    }
    local_1[local_2].unk8 = 0.0f;
    func_808007E4_chjiggygamenew(local_1, 0x55C, local_2);
}

void func_80800424_chjiggygamenew(Unk80132ED0 *param_0)
{
    Actor *local_0;
    JiggyMenuRecord *local_1;
    s32 local_2;

    local_0 = func_80106790(param_0);
    local_1 = func_80100094(local_0, 0);
    local_2 = local_0->actorData[3];
    if (local_1[local_2].unk4 != 0x800) {
        if (local_1[local_2].unk4 == 0x1FFF) {
            local_1[local_2].unk0--;
        }
    } else {
        local_1[local_2].unk0++;
    }
    if (local_1[local_2].unk0 < 0) {
        local_1[local_2].unk0 += 4;
    }
    if (local_1[local_2].unk0 >= 4) {
        local_1[local_2].unk0 -= 4;
    }
    local_1[local_2].unk8 = 0.0f;
    func_808007E4_chjiggygamenew(local_1, 0x7F4, local_2);
}

void func_808004E0_chjiggygamenew(Unk80132ED0 *param_0)
{
    Actor *local_0;
    s32 local_1;
    u32 local_2;

    local_0 = func_80106790(param_0);
    if (!local_0->unk64_20 && func_800CEAA8(4)) {
        func_800CE88C(4, 0);
    }
    func_80803598_chjiggygamenew(local_0->unk3C);
    if (_sujiggy_entrypoint_21()) {
        local_2 = _sujiggy_entrypoint_24();
        local_0->unk6C_0 = (s32)(*(f32 *)&local_0->actorData[6] - *(f32 *)&local_0->actorData[0]);
        if (local_2 == 0) {
            func_800C9C34(0.25f, 0x83, 0, 2000);
            func_800C9DE4(0.3f, func_800FC6B0, 0x10);
            local_1 = 0x1564;
        } else if (local_2 < local_0->unk6C_0) {
            func_800C9C34(0.25f, 0x83, 0, 2000);
            func_800C9DE4(0.3f, func_800FC6B0, 0x17);
            local_1 = 0x1563;
        } else if (local_2 == local_0->unk6C_0) {
            func_800C9C34(0.25f, 0x83, 0, 2000);
            func_800C9DE4(0.3f, func_800FC6B0, 0x17);
            local_1 = 0x1562;
        } else {
            func_800C9C34(0.25f, 0x83, 0, 2000);
            func_800C9DE4(0.3f, func_800FC6B0, 0x10);
            local_1 = 0x1561;
        }
    } else {
        func_800C9C34(0.25f, 0x83, 0, 2000);
        func_800C9DE4(0.3f, func_800FC6B0, 0x10);
        local_1 = 0x14FA;
    }
    func_800C082C(0);
    _subaddiedialog_entrypoint_11(local_0->unk0, local_1, 0x4C6, 0, 0x97);
    func_800C082C(1);
    local_0->actorData[4] = 6;
}


void func_808006E0_chjiggygamenew(Unk80132ED0 *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    if (!local_0->unk64_20 && func_800CEAA8(4)) func_800CE88C(4, 0);
    func_8080356C_chjiggygamenew(local_0->unk3C);
    func_800C9C34(0.25f, 0x83, 0, 2000);
    func_800C9DE4(0.3f, func_800FC6B0, 0x17);
    local_0->actorData[4] = 6;
    if (_sujiggy_entrypoint_21()) param_2 = 0x155E;
    func_800C082C(0);
    _subaddiedialog_entrypoint_11(local_0->unk0, param_2, 0x4C6, 0, 0x97);
    func_800C082C(1);
    func_80800B88_chjiggygamenew(local_0);
}

int func_808007BC_chjiggygamenew(Unk80132ED0 *param_0)
{
  int *local_0 = (int)func_80106790(param_0) ^ 0;
  return local_0[10] == 5;
 dummy_label_933339: ; local_0++;
  local_0--;
}

void func_808007E4_chjiggygamenew(param_0, param_1, param_2) JiggyMenuRecord *param_0; s32 param_1; s32 param_2; {
    u32 local_0;
    rom_read_word(param_1 + 0xB0000000, &local_0);
    param_0[param_2].unk4 = local_0 & 0xFFFF;
}

void func_80800834_chjiggygamenew(Actor *param_0)
{
    s32 local_3;
    s32 i4; /* unused local: needed for the stack frame slot (removing it: metric 4) */
    s32 local_0[20];
    s32 local_1[20];
    JiggyTile88 *local_6;
    JiggyGameData88 *local_2;
    s8 local_5;
    s32 local_4;
    s32 local_4_b;

    local_2 = func_80100094(param_0, 0);
    for (local_3 = 0; local_3 < 20; local_3++) {
        local_2->local_0[local_3].local_1 = -1;
        local_2->local_0[local_3].local_0 = 0;
        local_2->local_0[local_3].local_2 = 0;
        func_808007E4_chjiggygamenew((JiggyMenuRecord *)local_2, 0x934, local_3);
        local_0[local_3] = 0;
        local_2->local_1[local_3] = -1;
        local_2->local_2[local_3] = -1;
    }
    for (local_3 = 0; local_3 < 20 - _sujiggy_entrypoint_6(param_0->actorData[5]); local_3++) {
        do {
            local_4_b = func_800DC214(0, 20);
        } while (local_0[local_4_b]);
        local_1[local_3] = local_4_b;
        local_0[local_4_b] = -1;
    }
    for (local_3 = 0; local_3 < 20 - _sujiggy_entrypoint_6(param_0->actorData[5]); local_3++) {
        do {
            local_4 = func_800DC214(0, 20);
        } while (local_2->local_0[local_4].local_1 != -1);
        local_6 = &local_2->local_0[local_4];
        local_6->local_1 = local_1[local_3];
        func_808007E4_chjiggygamenew((JiggyMenuRecord *)local_2, 0xA4, local_4);
        local_6->local_4 = 2.0f;
        local_2->local_1[local_1[local_3]] = local_4;
    }
    for (local_3 = 0; local_3 < _sujiggy_entrypoint_7(param_0->actorData[5]); local_3++) {
        local_5 = func_800DC214(1, 3);
        if (!(func_800DC1AC() < 0.5f)) {
            local_5 = -local_5;
        }
        do {
            local_4_b = func_800DC214(0, 20);
        } while (local_2->local_0[local_4_b].local_0);
        local_2->local_0[local_4_b].local_0 = local_5;
    }
    for (local_3 = 1; local_3 != 21; local_3++) {
        do {
            local_4 = func_800DC214(0, 20);
        } while (local_2->local_0[local_4].local_2);
        local_2->local_0[local_4].local_2 = local_3;
    }
    *(s32 *)&param_0->actorData[3] = -1;
}

void func_80800AF8_chjiggygamenew(Actor *param_0)
{
    JiggyGameCell *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 20; local_1++) {
        if (local_0[local_1].local_0 == 0x3000) {
            func_808007E4_chjiggygamenew(local_0, 0x844, local_1);
            local_0[local_1].local_1 = 0.0f;
        }
    }
}

void func_80800B88_chjiggygamenew(Actor *param_0)
{
    JiggyGameSlot_80800B88_chjiggygamenew *local_0;
    s32 i;

    local_0 = func_80100094(param_0, 0);
    for (i = 0; i < 20; i++) {
        if (local_0[i].type != 0x18 && local_0[i].type != 0x2A1) {
        switch (local_0[i].type) {
        case 0:
        case 0x800:
        case 0x1FFF:
            func_808035C4_chjiggygamenew(*(s32 *)((u8 *)param_0 + 0x3C), local_0[i].unkC);
            break;
        case 0xA000:
            func_800EE7F8(local_0[i].unkC, D_80803AE0_chjiggygamenew[local_0[i].unk3]);
            break;
        default:
            func_800EE7F8(local_0[i].unkC, D_80803BD0_chjiggygamenew[local_0[i].unk1]);
            break;
        }
        func_808007E4_chjiggygamenew(local_0, 0x9EC, i);
        local_0[i].unk8 = 1.5f;
        return;
        }
    }
}

void func_80800CC0_chjiggygamenew(Actor *param_0)
{
    extern s32 D_80803AE0_chjiggygamenew[][3];
    extern s32 D_80803BD0_chjiggygamenew[][3];
    extern u8 D_80803CC0_chjiggygamenew[][4];

    JiggyPieceRecord *local_0;
    s32 local_5;
    s32 local_4;
    f32 local_15;
    f32 local_14;
    f32 local_8[3];
    f32 local_13;

    local_0 = func_80100094(param_0, 0);
    local_4 = func_8010262C(param_0->unk0, 0x3C);

    if (local_4 == 0) {
        return;
    }

    func_800E0ACC(local_4);
    func_800E0AF0(local_4, 1.0f);

    for (local_5 = 0; local_5 < 20; local_5++) {
        JiggyPieceRecord *local_1 = &local_0[local_5];
        f32 local_16;
        switch (local_1->unk4) {
            case 0x18:
                local_15 = 1;
                local_14 = 0.0f;
                local_13 = 0.0f;

                func_800EFA4C(
                    local_8,
                    0.0f,
                    0.0f,
                    0.0f
                );
                break;

            case 0x3000:

                if (func_800D90A4(&local_1->unk8)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x844,
                        local_5
                    );
                }

                local_13 = func_800F12D4(
                    local_1->unk8,
                    2.0f,
                    0.0f,
                    0.0f,
                    1.0f
                );

                func_800EFB24(
                    local_8,
                    (char *)D_80803BD0_chjiggygamenew +
                        local_1->unk1 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_8[0] -=
                    func_80013970(local_13 * 180.0f) *
                    (100.0f +
                     10.0f * (f32)local_1->unk2);

                local_14 =
                    (f32)local_1->unk0 * 90.0f;
                local_15 = 0.75f;
                break;

            case 0x6B54:
                if (param_0->actorData[2] == (1 + ((s8 *)local_1)[1])) {
                    if (func_8080363C_chjiggygamenew(
                            param_0->unk3C)) {
                        local_1->unk8 = 0.0f;
                        func_808007E4_chjiggygamenew(
                            local_0,
                            0x12C,
                            local_5
                        );
                    }
                }

                local_15 = 0.75f;
                local_13 = 1;

                func_800EFB24(
                    local_8,
                    (char *)D_80803BD0_chjiggygamenew +
                        local_1->unk1 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;
                break;

            case 0x2A1: {
                local_16 = local_1->unk8;

                if (func_800D90A4(&local_1->unk8)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x934,
                        local_5
                    );
                    func_80800B88_chjiggygamenew(param_0);
                } else if (0.75f < local_16 &&
                           local_1->unk8 <= 0.75f) {
                    func_80800B88_chjiggygamenew(param_0);
                }

                local_13 = func_800F12D4(
                    local_1->unk8,
                    1.5f,
                    0.0f,
                    1.0f,
                    0.0f
                );

                func_800EFB24(
                    local_8,
                    local_1->unkC,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_16 = local_13 * 180.0f;
                local_8[0] -=
                    func_80013970(local_16) * 100.0f +
                    func_80013970(local_16) * 10.0f *
                        (f32)local_1->unk2;

                local_14 =
                    (f32)local_1->unk0 * 90.0f;
                local_15 = 0.75f;
                break;
            }

            case 0xC: {
                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    local_1->unk8 = 0.0f;

                    if (param_0->actorData[2] != (1 + ((s8 *)local_1)[1])) {
                        func_808007E4_chjiggygamenew(
                            local_0,
                            0x844,
                            local_5
                        );
                    }
                }

                local_13 = 1;

                func_800EFB24(
                    local_8,
                    (char *)D_80803BD0_chjiggygamenew +
                        local_1->unk1 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;

                local_15 =
                    func_80013970(func_800F10B4(
                    local_1->unk8,
                    0.0f,
                    0.2f,
                    0.0f,
                    1.0f
                ) * 360.0f) *
                        0.1f +
                    0.75f;
                break;
            }

            case 0xF018: {
                f32 local_9[3];
                f32 local_16;

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x470,
                        local_5
                    );
                }

                local_16 = func_800F10B4(
                    local_1->unk8,
                    0.0f,
                    0.2f,
                    0.0f,
                    1.0f
                );

                local_13 = 1;

                func_800EFB24(
                    local_8,
                    (char *)D_80803BD0_chjiggygamenew +
                        local_1->unk1 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                func_808035C4_chjiggygamenew(
                    param_0->unk3C,
                    local_9
                );

                func_800EFB24(
                    local_9,
                    local_9,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                func_800EFE50(
                    local_8,
                    local_8,
                    local_9,
                    local_16
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;

                local_15 = func_800F1214(
                    local_16,
                    0.75f,
                    1.1f
                );
                break;
            }

            case 0:
                local_13 = 1;

                func_808035C4_chjiggygamenew(
                    param_0->unk3C,
                    local_8
                );

                local_15 = 1.1f;

                func_800EFB24(
                    local_8,
                    local_8,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;
                break;

            case 0x1FFF: {
                f32 local_16;

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    local_1->unk8 = 0.0f;

                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x470,
                        local_5
                    );

                    local_16 = 0.0f;

                    local_1->unk0 -= 1;

                    if (local_1->unk0 >= 4) {
                        local_1->unk0 -= 4;
                    }
                } else {
                    local_16 = func_800F10B4(
                        local_1->unk8,
                        0.0f,
                        0.2f,
                        0.0f,
                        1.0f
                    );
                }

                local_13 = 1;
                local_15 = 1.1f;

                func_808035C4_chjiggygamenew(
                    param_0->unk3C,
                    local_8
                );

                func_800EFB24(
                    local_8,
                    local_8,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f -
                    90.0f * local_16;
                break;
            }

            case 0x800: {
                f32 local_16;

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x470,
                        local_5
                    );

                    local_16 = 0.0f;

                    local_1->unk0 += 1;

                    if (local_1->unk0 >= 4) {
                        local_1->unk0 -= 4;
                    }
                } else {
                    local_16 = func_800F10B4(
                        local_1->unk8,
                        0.0f,
                        0.2f,
                        0.0f,
                        1.0f
                    );
                }

                local_13 = 1;
                local_15 = 1.1f;

                func_808035C4_chjiggygamenew(
                    param_0->unk3C,
                    local_8
                );

                func_800EFB24(
                    local_8,
                    local_8,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f +
                    90.0f * local_16;
                break;
            }

            case 0x32D4: {
                f32 local_9[3];
                f32 local_16;

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x844,
                        local_5
                    );
                }

                local_16 = func_800F10B4(
                    local_1->unk8,
                    0.0f,
                    0.2f,
                    1.0f,
                    0.0f
                );

                local_13 = 1;

                func_800EFB24(
                    local_8,
                    (char *)D_80803BD0_chjiggygamenew +
                        local_1->unk1 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                func_800EFB24(
                    local_9,
                    local_1->unkC,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                func_800EFE50(
                    local_8,
                    local_8,
                    local_9,
                    local_16
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;

                local_15 = func_800F1214(
                    local_16,
                    0.75f,
                    1.1f
                );
                break;
            }

            case 0xB825: {
                f32 local_10[3];
                f32 local_16;

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x19C,
                        local_5
                    );
                }

                local_16 = func_800F10B4(
                    local_1->unk8,
                    0.0f,
                    0.2f,
                    0.0f,
                    1.0f
                );

                local_13 = 1;

                func_800EFB24(
                    local_10,
                    (char *)D_80803AE0_chjiggygamenew +
                        local_1->unk3 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_10[0] -= local_16 * 20.0f;

                func_800EFB24(
                    local_8,
                    local_1->unkC,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                func_800EFE50(
                    local_8,
                    local_8,
                    local_10,
                    local_16
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;

                local_15 = func_800F1214(
                    local_16,
                    1.1f,
                    1.0f
                );
                break;
            }

            case 0xA000:
                local_13 = 1;
                func_800EFB24(local_8,
                    D_80803AE0_chjiggygamenew[local_1->unk3],
                    D_80803AE0_chjiggygamenew[local_5]);
                local_15 = 1.0f;
                local_8[0] -= 20.0f;
                local_14 = (f32)local_1->unk0 * 90.0f;
                break;

            case 0xB41D: {
                f32 local_11[3];

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x470,
                        local_5
                    );
                }

                local_16 = func_800F10B4(
                    local_1->unk8,
                    0.0f,
                    0.2f,
                    1.0f,
                    0.0f
                );

                local_13 = 1;

                func_800EFB24(
                    local_11,
                    (char *)D_80803AE0_chjiggygamenew +
                        local_1->unk3 * 12,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                local_11[0] -= local_16 * 20.0f;

                func_808035C4_chjiggygamenew(
                    param_0->unk3C,
                    local_8
                );

                func_800EFB24(
                    local_8,
                    local_8,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );

                func_800EFE50(
                    local_8,
                    local_8,
                    local_11,
                    local_16
                );

                local_14 =
                    (f32)local_1->unk0 * 90.0f;

                local_15 = func_800F1214(
                    local_16,
                    1.1f,
                    1.0f
                );
                break;
            }

            case 0xE825:

                if (func_800D91EC(&local_1->unk8, 0.2f)) {
                    func_808007E4_chjiggygamenew(
                        local_0,
                        0x934,
                        local_5
                    );
                }

                local_13 = func_800F10B4(
                    local_1->unk8,
                    0.0f,
                    0.2f,
                    1.0f,
                    0.0f
                );

                local_15 = 1;
                local_14 = 0.0f;

                func_800EFB24(
                    local_8,
                    local_1->unkC,
                    (f32 *)D_80803AE0_chjiggygamenew[local_5]
                );
                break;
        }

        func_800EF334(local_8, 0.01f);

        func_800E0C20(
            local_4,
            D_80803CC0_chjiggygamenew[local_5][3],
            local_13,
            local_8[0],
            local_8[1],
            local_8[2]
        );

        func_800E0AFC(
            local_4,
            D_80803CC0_chjiggygamenew[local_5][3],
            local_13,
            local_14,
            0.0f,
            0.0f
        );

        func_800E0B8C(
            local_4,
            D_80803CC0_chjiggygamenew[local_5][3],
            local_13,
            local_15,
            local_15,
            local_15
        );

    }
}

int func_808019E0_chjiggygamenew(Actor *param_0)
{
    f32 local_1[2];
    f32 local_0[2];
    f32 local_2;
    f32 local_7;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_6;
    local_2 = -1.0f;
    local_3 = 0;
    func_808035FC_chjiggygamenew(param_0->unk3C, local_0);
    local_4 = _glglobalsettings_entrypoint_3() ? 1 : 0;
    if (local_0[0] >= D_80803D8C_chjiggygamenew[local_4][0] &&
        local_0[0] <= D_80803D8C_chjiggygamenew[local_4][1] &&
        local_0[1] >= D_80803D8C_chjiggygamenew[local_4][2] &&
        local_0[1] <= D_80803D8C_chjiggygamenew[local_4][3]) {
        for (local_5 = 0; local_5 != 20; local_5++) {
            func_800E4140(((s32 (*)[3]) D_80803AE0_chjiggygamenew)[local_5], local_1);
            if (local_2 == -1.0f || JIGGY_DISTANCE49 < local_2) {
                local_3 = local_5;
                local_2 = JIGGY_DISTANCE49;
            }
        }
        return local_3 + 21;
    }
    for (local_5 = 0; local_5 != 20; local_5++) {
        func_800E4140(((s32 (*)[3]) D_80803BD0_chjiggygamenew)[local_5], local_1);
        if (local_2 == -1.0f || JIGGY_DISTANCE49 < local_2) {
            local_3 = local_5;
            local_2 = JIGGY_DISTANCE49;
        }
    }
    if (local_2 < 625.0f) return local_3 + 1;
    return 0;
}

int func_80801C20_chjiggygamenew(Actor *param_0)
{
    JiggyGameSolvedCell *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 20; local_1++) {
        if (local_0[local_1].local_0 != 0x18) return 0;
    }
    return 1;
}

int func_80801CB0_chjiggygamenew(s32 param_0, s32 param_1, JiggyGameRecord *param_2)
{
    s32 local_0;

    local_0 = param_2[param_1].unk4;
    return (local_0 == 0x6B54) || (local_0 == 0xC);
}

void func_80801CE8_chjiggygamenew(Actor *param_0)
{
    u8 *local_1;
    s32 local_0;
    s32 local_2;
    s32 local_3;
    u8 local_4;
    s32 local_7;

    local_1 = func_80100094(param_0, 0);
    local_0 = *(s32 *)((u8 *)param_0 + 0x20) - 1;
    local_2 = func_8080363C_chjiggygamenew(param_0->unk3C);
    for (local_3 = 0; local_3 != 20; local_3++) {
        local_4 = local_1[0x1E0 + local_3];
        if (local_0 == *(s8 *)(local_1 + local_3 * 0x18 + 1) && local_2 &&
            func_80801CB0_chjiggygamenew(param_0, local_3, local_1)) {
            local_1[0x1E0 + local_3] = 1;
        } else local_1[0x1E0 + local_3] = 0;
        if (local_4 != local_1[0x1E0 + local_3]) {
            local_7 = func_8010649C(param_0, local_3 + 0x190);
            switch (local_1[0x1E0 + local_3]) {
                case 1:
                    func_800EDE54(local_7, D_80803DAC_chjiggygamenew, D_80803DBC_chjiggygamenew, 0.1f);
                    break;
                case 0:
                    func_800EDE54(local_7, D_80803DBC_chjiggygamenew, D_80803DAC_chjiggygamenew, 0.3f);
                    break;
            }
        }
    }
}

void func_80801E4C_chjiggygamenew(Actor *param_0, s32 param_1)
{
    f32 local_0;

    func_800DA544(0xD49);
    if (param_1 == 0) {
        local_0 = _sujiggy_entrypoint_3(param_0->actorData[5]);
        *(f32 *)((u8 *)param_0 + 0x18) = local_0;
        *(f32 *)((u8 *)param_0 + 0x30) = local_0;
        func_800CE8D8(4, local_0, (s32)local_0);
        func_800CE88C(4, 1);
        param_0->actorData[1] = osGetCount();
    }
    param_0->actorData[4] = 5;
    param_0->unk64_20 = param_1;
}

void func_80801EE8_chjiggygamenew(param_0) Actor *param_0;
{
    u8 *local_0;
    u8 *local_1;
    s32 i;
    s32 j;
    s32 k;

    *(s32 *)((u8 *)param_0 + 0x2C) = _sujiggy_entrypoint_12();
    *(s32 *)((u8 *)param_0 + 0x28) = 1;
    local_0 = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, 0x186D), *(s16 *)((u8 *)param_0 + 0x2E));
    for (i = 0, k = 0; local_0[k - 1] != 0 && i < 3; i++, k++) {
        local_1 = func_80100094(param_0, 0) + i * 30 + 0x21C;
        for (j = 0; local_0[k] != 0 && local_0[k] != 10; k++, j++) {
            local_1[j] = local_0[k];
        }
        local_1[j + 1] = 0;
    }
    for (; i < 3; i++) {
        (func_80100094(param_0, 0) + i * 30)[0x21C] = 0;
    }
    _gldbstring_entrypoint_2(0x186D);
}

void func_80802030_chjiggygamenew(param_0) Actor *param_0;
{
    f32 local_0 = func_800D8FF8();
    s32 local_1;
    s32 local_2;
    s32 local_3;

    if (((JiggyGameEvent441 *)param_0)->local_0 != 0) {
        func_80801CE8_chjiggygamenew(param_0);
    }
    param_0->unk58 += local_0;
    switch ((s32)param_0->actorData[4]) {
    case 1:
        if (param_0->unk58 > 0.1f) {
            func_800FC6B0(0x31);
            if (func_800FCCD4(0x2E)) {
                func_800FCAE0(0x2E, 0, 0x1D3);
                func_800FCA90(0x2E);
            }
            param_0->actorData[4] = 2;
            *(f32 *)&param_0->actorData[0] = 2.0f;
            func_80800834_chjiggygamenew(param_0);
        }
        break;
    case 2:
        if (func_800D90A4(&param_0->actorData[0])) {
            func_80800AF8_chjiggygamenew(param_0);
            func_800FC74C(0x31);
            func_800FC6B0(0x83);
            func_800FCA90(0x83);
            if (_sujiggy_entrypoint_21()) {
                if (!func_800DA298(0xD49)) {
                    func_800C082C(0);
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x155F, 0x4C7, 0, 0x97);
                    func_800C082C(1);
                    param_0->actorData[4] = 3;
                } else if (_sujiggy_entrypoint_24()) {
                    func_800C082C(0);
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x1560, 0x4C7, 0, 0x97);
                    func_800C082C(1);
                    param_0->actorData[4] = 3;
                } else {
                    func_80801E4C_chjiggygamenew(param_0, 0);
                }
            } else if (!func_800DA298(0xD49)) {
                func_800C082C(0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x14F9, 0x4C7, 0, 0x97);
                func_800C082C(1);
                param_0->actorData[4] = 3;
            } else if (_sujiggy_entrypoint_18()) {
                func_800C082C(0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1554, 0x4C7, 0, 0x97);
                func_800C082C(1);
                param_0->actorData[4] = 3;
            } else {
                func_80801E4C_chjiggygamenew(param_0, 0);
            }
        }
        break;
    case 4:
        func_800C082C(0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1555, 0x4C6, 0, 0x97);
        func_800C082C(1);
        param_0->actorData[4] = 3;
        break;
    case 5:
        if (func_80801C20_chjiggygamenew(param_0)) {
            func_808004E0_chjiggygamenew(param_0->unk0);
            func_80102424(func_80106790(param_0->unk3C), 7);
        } else if (!param_0->unk64_20) {
            local_1 = osGetCount();
            local_2 = (s32)param_0->actorData[1];
            if (local_1 >= local_2) {
                local_3 = local_1 - local_2;
            } else {
                local_3 = (0xFFFFFFFF - local_2) + local_1 + 1;
            }
            *(f32 *)&param_0->actorData[0] -= (local_3 * 0.021333333f) / 1000000.0f;
            param_0->actorData[1] = osGetCount();
            if (param_0->unk58 > 2.0f) {
                func_800FCD14(0x83, (s32)((131538.0f * *(f32 *)&param_0->actorData[0]) / *(f32 *)&param_0->actorData[6] + 330000.0f));
            }
            if (*(f32 *)&param_0->actorData[0] < -0.1f) {
                func_808006E0_chjiggygamenew(param_0->unk0, 0xD4B, 0x14FB);
            } else {
                func_800CE980(4, *(f32 *)&param_0->actorData[0], 0);
            }
        }
        break;
    case 7:
    case 8:
        if (func_80801C20_chjiggygamenew(param_0) && !func_800C0638()) {
            if (param_0->actorData[4] == 7) {
                _sujiggy_entrypoint_11(param_0->actorData[5]);
            } else {
                _sujiggy_entrypoint_10();
            }
            param_0->actorData[4] = 6;
        }
        break;
    }
    func_80800CC0_chjiggygamenew(param_0);
}

void func_8080245C_chjiggygamenew(s32 arg0) 
{
}
f32 func_80802464_chjiggygamenew(s32 param_0)
{
    func_800E41CC(param_0);
    func_800E3C8C(50.0f, 2000.0f);
    func_800E3BAC(D_80803D10_chjiggygamenew);
    func_800E3C30(D_80803D1C_chjiggygamenew);
    func_800E3CE8();
    func_800E44FC(param_0);
    return D_80803D28_chjiggygamenew;
}

void func_808024C8_chjiggygamenew(s32 arg0)
{
    func_800E4208();
    func_800E44FC(arg0);
}
void func_808024F0_chjiggygamenew(param_0, param_1) u8 *param_0; GfxW **param_1;
{
    f32 local_0;
    f32 sp70[3];
    f32 sp64[3];
    void *local_1;
    s32 m;

    local_1 = func_800E81D0();
    if ((local_1 != 0) && (func_800A9CD0() == 1)) {
        local_0 = func_80802464_chjiggygamenew(param_1);
        func_800EFA4C(sp70, 0, 0, 0); /* agV8: int 0 literals (zero in f2 like target) */
        func_800EFA4C(sp64, 0, 0, 0);
        func_800DF830(1);
        m = func_800D674C(0x866);
        func_800DE498(param_1, sp70, 0, 1.0f, sp64, m);
        m = func_800D674C(0x865);
        func_800DE498(param_1, sp70, 0, 1.0f, sp64, m);
        {
            GfxW *_g = (*param_1)++;
            _g->w1 = 0;
            _g->w0 = 0xE3001201;
            _g = (*param_1)++; /* agV8: consecutive pushes share one block-local _g (frame 0x80) */
            _g->w0 = 0xE3001801; _g->w1 = 0xC0;
        }
        if (*(s32 *)(param_0 + 0x34) != 0) {
            func_80803928_chjiggygamenew(*(s32 *)(param_0 + 0x34) ^ 0, param_1); /* PROBE (agV12): "^ 0" makes uopt treat the arg as a new value -> lw a2 + or a0,a2 in the beqz delay slot like target */
        }
        func_800E7C28(param_1);
        func_800E7CF4(param_1);
        {
            GfxW *_g = (*param_1)++;
            _g->w0 = 0xDB060010;
            _g->w1 = osVirtualToPhysical(local_1);
        }
        func_80102FDC(param_0, local_0);
        func_80101870(param_0, param_1);
        {
            GfxW *_g = (*param_1)++;
            _g->w1 = 0x2000;
            _g->w0 = 0xE3001201;
            _g = (*param_1)++;
            _g->w1 = 0;
            _g->w0 = 0xE3001801;
        }
        {
        s32 v;
        s32 j;
        s32 count;
        s32 sp34;
        func_80803668_chjiggygamenew(*(s32 *)(param_0 + 0x3C), param_1);
        *(s32 *)(param_0 + 0x20) = func_808019E0_chjiggygamenew(param_0);
        func_808024C8_chjiggygamenew(param_1);
        if (1) { do {} while (0); }
        switch (*(s32 *)(param_0 + 0x28)) {
            case 1:
            case 2:
                _fxkern_entrypoint_2();
                break;
            default:
                return;
        }
        if (*(s32 *)(param_0 + 0x28) == 1) {
            v = 0xFF;
        } else {
            v = (s32)func_800F10B4(*(f32 *)(param_0 + 0x18), 2.0f, 0.0f, 255.0f, 0.0f);
        }
        func_800B8C8C(v);
        func_800B8CE0(0xC26);
        _fxkern_entrypoint_3(1.1f);

        count = 0;
        for (j = 0; j < 3; j++) {
            if (func_80100094(param_0, 0)[j * 0x1E + 0x21C] != 0) {
                count++;
            }
        }

        j = 0;
        if (func_80100094(param_0, 0)[j * 0x1E + 0x21C] != 0) {
            sp34 = 0x78 - (count / 2) * 25;
            do {
                v = func_800E71B8((u8 *)&((ArrV1E *)func_80100094(param_0, 0))->arr[j] + 0x21C);
                _fxkern_entrypoint_1(param_1, (u32)sp34 + j * 0x19, v);
                j++;
                if (func_80100094(param_0, 0)[j * 0x1E + 0x21C] == 0) {
                    return;
                }
            } while (j != 3);
        }
        }
    }
}

s32 func_80802858_chjiggygamenew(param_0, param_1, param_2) void *param_0; s32 param_1; u32 param_2;
{
    JiggyGameDialogEvent *local_0 = (JiggyGameDialogEvent *)&param_2;
    Actor *local_1 = param_0;

    switch (param_1) {
    case 0x2E:
        switch (local_0->local_1[0]) {
        case 0x14F9:
        case 0x155F:
        case 0x1560:
            func_80801E4C_chjiggygamenew(local_1, 0);
            break;
        case 0x1554:
            if (local_0->local_1[1] == 1) {
                if (!func_800DA298(0xD74)) {
                    _subaddiedialog_entrypoint_11(local_1->unk0, 0x1555, 0x4C7, 0, 0x97);
                    func_800DA544(0xD74);
                } else {
                    func_80801E4C_chjiggygamenew(local_1, 1);
                }
            } else {
                func_80801E4C_chjiggygamenew(local_1, 0);
            }
            break;
        case 0x1555:
            func_80801E4C_chjiggygamenew(local_1, 1);
            break;
        case 0x14FA:
            _sujiggy_entrypoint_9();
            func_80800B88_chjiggygamenew(local_1);
        case 0x150B:
        case 0x14FB:
            if (local_0->local_1[1] == 1) {
                local_1->actorData[4] = 7;
            } else {
                local_1->actorData[4] = 8;
            }
            break;
        case 0x155E:
        case 0x1561:
        case 0x1562:
        case 0x1563:
        case 0x1564:
            func_80800B88_chjiggygamenew(local_1);
            _sujiggy_entrypoint_25(local_1->unk6C_0);
            if (local_0->local_1[1] == 1) {
                local_1->actorData[4] = 7;
            } else {
                local_1->actorData[4] = 8;
            }
            break;
        }
        break;
    case 0x30:
        switch (local_0->local_1[0]) {
        case 0x14FA:
        case 0x14FB:
        case 0x14FC:
            return local_1->actorData[5] + 1;
        case 0x1554:
            return _sujiggy_entrypoint_19();
        case 0x14F9:
            return _sujiggy_entrypoint_24();
        case 0x1561:
        case 0x1564:
            if (local_0->local_1[1] != 0) {
                return _sujiggy_entrypoint_24();
            }
            return local_1->unk6C_0;
        case 0x1563:
            return _sujiggy_entrypoint_24();
        case 0x1560:
        case 0x1562:
            return _sujiggy_entrypoint_24();
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void chjiggygamenew_entrypoint_1(void) {
    u8 *local_0;
    u8 **local_3;
    u8 **local_1;

    (*(f32 *)((s8 *)(&D_80803DCC_chjiggygamenew) + (8))) = 0.0f;
    (*(f32 *)((s8 *)(&D_80803DCC_chjiggygamenew) + (4))) = (f32) (*(f32 *)((s8 *)(&D_80803DCC_chjiggygamenew) + (8)));
    (*(f32 *)((s8 *)(&D_80803DCC_chjiggygamenew) + (0))) = (f32) (*(f32 *)((s8 *)(&D_80803DCC_chjiggygamenew) + (8)));
    local_0 = func_80108474(0x1DF, &D_80803DCC_chjiggygamenew, 0);
    local_1 = func_80108528(0x1E2, &D_80803DD8_chjiggygamenew, 0, &local_0);
    (*(u8 **)((s8 *)(local_0) + (0x3C))) = (u8 *) (*(u8 **)((s8 *)(local_1) + (0)));
    (*(u8 **)((s8 *)(local_1) + (0x3C))) = (u8 *) (*(u8 **)((s8 *)(local_0) + (0)));
    local_3 = func_80108528(0x1DE, local_0 + 4, 0, &local_0);
    (*(u8 **)((s8 *)(local_0) + (0x34))) = (u8 *) (*(u8 **)((s8 *)(local_3) + (0)));
    (*(u8 **)((s8 *)(local_3) + (0x3C))) = (u8 *) (*(u8 **)((s8 *)(local_0) + (0)));
    (*(u16 *)((s8 *)(*(u8 **)local_0) + (0x12))) = (u16) (((*(u16 *)((s8 *)(*(u8 **)local_0) + (0x12))) & 1) | 2);
    (*(u16 *)((s8 *)(*local_1) + (0x12))) = (u16) (((*(u16 *)((s8 *)(*local_1) + (0x12))) & 1) | 2);
    (*(u16 *)((s8 *)(*local_3) + (0x12))) = (u16) (((*(u16 *)((s8 *)(*local_3) + (0x12))) & 1) | 2);
    func_800EC828();
    func_800EC828();
    func_800EC828();
}

void chjiggygamenew_entrypoint_2(void)
{
    u16 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80014F00();
    if (_glglobalsettings_entrypoint_3()) {
        for (local_1 = 0; local_1 < 7; local_1++) {
            local_3 = D_80803DF8_chjiggygamenew[local_1 * 2] +
                      D_80803DF8_chjiggygamenew[local_1 * 2 + 1] * 0x130;
            local_0[local_3] = local_0[local_3 - 1];
        }
    } else {
        for (local_1 = 0; local_1 < 10; local_1++) {
            local_2 = D_80803DE4_chjiggygamenew[local_1 * 2] +
                      D_80803DE4_chjiggygamenew[local_1 * 2 + 1] * 0x130;
            local_0[local_2] = local_0[local_2 - 1];
        }
    }
}

int chjiggygamenew_entrypoint_3()
{
    return D_80803E50_chjiggygamenew;
}

void func_80802E80_chjiggygamenew(u8 *param_0)
{
  u16 *local_0;
  u8 *local_1;
  u8 *local_2;
  local_0 = func_800169A8();
  local_2 = func_80100094(param_0, 0);
  local_1 = local_2;
  if (local_2)
  {
  }
  func_800EE7F8(local_2, param_0 + 4);
 goto dummy_label_56401; dummy_label_56401: ;
  *((f32 *) (((s8 *) param_0) + 0x38)) = 0.18f;
  *((f32 *) (((s8 *) param_0) + 0x44)) = 59.0f;
  *((f32 *) (((s8 *) param_0) + 0x4C)) = 63.0f;
  *((f32 *) (((s8 *) param_0) + 0x48)) = -6.0f;
  *((f32 *) (((s8 *) local_1) + 0x30)) = 1.0f;
  *((f32 *) (((s8 *) local_1) + 0x34)) = 1.0f;
  *((s32 *) (((s8 *) local_1) + 0x28)) = -1;
  *((s32 *) (((s8 *) local_1) + 0x2C)) = -1;
  *((s32 *) (((s8 *) local_1) + 0x38)) = (s32) (*local_0);
  *((f32 *) (((s8 *) local_1) + 0x3C)) = 0.0f;
  *((f32 *) (((s8 *) local_1) + 0x40)) = 0.0f;
  _subaddiefade_entrypoint_1(param_0, 0xB9);
}

void func_80802F3C_chjiggygamenew(Actor *param_0)
{
    OSContPad *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    JiggyCursorData *local_4;
    s32 local_5;
    s32 local_6;
    s32 z;
    s32 lim;
    s32 k = 0;
    s8 sx;

    local_0 = func_800169A8();
    local_1 = func_800D9004();
    local_4 = func_80100094(param_0, 0);

    if (param_0->unk70_10 == 7 || param_0->unk70_10 == 8) {
        return;
    }
    if (func_808007BC_chjiggygamenew(param_0->unk3C)) {
        if (param_0->unk70_10) {}
        z = local_0->button + k; lim = 7 + k; k = 2;
        if (param_0->unk70_10 != 6) {
            sx = local_0->stick_x;
            if (z) {}
            local_2 = func_80015D60(sx, lim, 0x3B);
            local_3 = func_80015D60(local_0->stick_y, 7, 0x3D);
            if (local_2 == 0 || local_4->previousX * local_2 < 0.0f) {
                local_4->accelerationX = 1;
            } else {
                local_4->accelerationX *= 1 + mlAbsF(local_2 * 0.1f);
            }
            if (local_3 == 0 || local_4->previousY * local_3 < 0.0f) {
                local_4->accelerationY = 1;
            } else {
                local_4->accelerationY *= 1 + mlAbsF(local_3 * 0.1f);
            }
            local_4->previousX = local_2;
            local_4->previousY = local_3;
            ((f32 *)param_0->actorData)[1] += local_3 * local_1 * 150.0f * local_4->accelerationY;
            ((f32 *)param_0->actorData)[2] += local_2 * local_1 * 150.0f * local_4->accelerationX;
            ((f32 *)param_0->actorData)[1] = MIN(((f32 *)param_0->actorData)[1], 110.0f) < -100.0f ?
                -100.0f : MIN(((f32 *)param_0->actorData)[1], 110.0f);
            ((f32 *)param_0->actorData)[2] = MIN(((f32 *)param_0->actorData)[2], 154.0f) < -135.0f ?
                -135.0f : MIN(((f32 *)param_0->actorData)[2], 154.0f);
            func_800EE780(param_0->position, local_4->origin, (f32 *)param_0->actorData);
        }
        if ((s32)param_0->unk70_10 >= 2 && (s32)param_0->unk70_10 < 5 && _sujiggy_entrypoint_21()) {
            if ((local_0->button & 2) && !(local_4->previousButtons & 2)) {
                func_800C3F14(0x487, 0.9f);
                func_80102424(param_0, 3);
                func_80800368_chjiggygamenew(param_0->unk3C);
            }
            if ((local_0->button & 1) && !(local_4->previousButtons & 1)) {
                func_800C3F14(0x487, 1.0f);
                func_80102424(param_0, 4);
                func_80800424_chjiggygamenew(param_0->unk3C);
            }
        }
        local_4->hovered = func_8080000C_chjiggygamenew(param_0->unk3C);
        switch (param_0->unk70_10) {
            case 1:
                if (local_4->hovered > 0 && local_4->hovered < 41 &&
                    (local_0->button & 0x8000) && !(local_4->previousButtons & 0x8000)) {
                    local_5 = func_80800030_chjiggygamenew(param_0->unk3C, local_4->hovered - 1);
                    if (local_5 != 0) {
                        local_4->selected = local_4->hovered - 1;
                        if (local_5 == 1) {
                            func_800FC660(0x2F);
                        } else {
                            func_800C3E88(0x47F);
                        }
                        func_80102424(param_0, 2);
                        func_80800030_chjiggygamenew(param_0->unk3C, local_4->hovered - 1);
                    }
                }
                break;
            case 2:
                if ((local_0->button & 0x4000) && !(local_4->previousButtons & 0x4000)) {
                    func_80102424(param_0, 5);
                    func_80800158_chjiggygamenew(param_0->unk3C);
                    func_800FC660(0x30);
                    local_4->selected = -1;
                } else if (local_4->hovered >= 21 && local_4->hovered < 41 &&
                           (local_0->button & 0x8000) && !(local_4->previousButtons & 0x8000)) {
                    local_5 = func_8080020C_chjiggygamenew(param_0->unk3C, local_4->hovered - 21);
                    if (local_5 == 1) {
                        local_6 = 0xE;
                        local_4->selected = -1;
                        func_80102424(param_0, 6);
                    } else if (local_5 == 0) {
                        local_6 = 0xF;
                        local_4->selected = -1;
                        func_80102424(param_0, 1);
                    } else {
                        local_6 = 0xF;
                    }
                    func_800C9E20(0.25f, (u32 *)func_800FC63C, local_6, 0x6590);
                }
                break;
            case 3:
            case 4:
                if (func_80101DDC(param_0)) {
                    func_80102424(param_0, 2);
                }
                break;
            case 5:
                func_80102424(param_0, 1);
                break;
            case 6:
                _subaddieaudioquick_entrypoint_3(param_0, NULL, D_80803E98_chjiggygamenew, 0.5f);
                if (func_80101DDC(param_0)) {
                    func_80102424(param_0, 1);
                }
                break;
            case 7:
            case 8:
            default:
                break;
        }
        local_4->previousButtons = local_0->button;
    }
}

void func_80803564_chjiggygamenew(s32 arg0) 
{
}
void func_8080356C_chjiggygamenew(Unk80132ED0 *param_0) {
    s32 local_0 = (s32)func_80106790(param_0);

    func_80102424(local_0 | 0, 8);
}

void func_80803598_chjiggygamenew(Unk80132ED0 *param_0){
    s32 temp = (s32)func_80106790(param_0);
    func_80102424(temp, 7);
}

void func_808035C4_chjiggygamenew(param_0, param_1) Unk80132ED0 *param_0; f32 *param_1; {
    func_800EE7F8(param_1, (f32 *)((u8 *)func_80100094(func_80106790(param_0), 0) + 0xC));
}

int func_808035FC_chjiggygamenew(s32 param_0, f32 *param_1)
{
  s32 local_0;
  f32 *local_1;
  local_0 = func_80106790(param_0);
  local_1 = func_80100094(local_0 | 0, 0);
  param_1[0] = local_1[6];
  param_1[1] = local_1[7];
}

int func_8080363C_chjiggygamenew(Unk80132ED0 *param_0)
{
  s32 *ptr = (s32 *)func_80106790(param_0);
  u16 val = *((u16 *) (((char *) ptr) + 0x72));
  unsigned long new_var;
  new_var = *((u16 *) (((char *) ptr) + 0x72));
  return (new_var >> 10) == 1;
}

void func_80803668_chjiggygamenew(param_0, param_1) Unk80132ED0 *param_0; void *param_1;
{
    Actor *local_0;
    f32 local_1;
    u8 *local_4;

    local_0 = func_80106790(param_0);
    local_4 = func_80100094(local_0, 0);
    func_800E4140(local_0->position, (f32 *)(local_4 + 0x20));
    local_1 = local_0->scale * 650.0f;
    func_800E7DE4(param_1, (s32)(*(f32 *)(local_4 + 0x20) - local_1 / 2),
                 (s32)(*(f32 *)(local_4 + 0x24) - local_1 / 2), (s32)local_1, (s32)local_1);
    func_80101870(local_0, param_1);
    if (local_0->unk70_10 == 1) {
        func_800EE7F8((f32 *)(local_4 + 0xC), D_80803EA4_chjiggygamenew);
    } else {
        func_800EE7F8((f32 *)(local_4 + 0xC), D_80803EB0_chjiggygamenew);
    }
    func_800EF04C((f32 *)(local_4 + 0xC), local_0->position);
    func_800E4140((f32 *)(local_4 + 0xC), (f32 *)(local_4 + 0x18));
}

int *chjiggygamenew_entrypoint_4()
{
    return &D_80803EBC_chjiggygamenew;
}

void func_8080377C_chjiggygamenew(Actor *param_0)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    u8 local_4;
    void *local_5;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk7C_12 && *(s16 *)((u8 *)param_0 + 0x90)) {
        if (!param_0->unk64_20) {
            for (local_2 = 0; local_2 < 20; local_2++) {
                func_800EDE54(func_8010649C(param_0, local_2 + 0x190), D_80803F14_chjiggygamenew, D_80803F04_chjiggygamenew, 0.0f);
            }
            param_0->unk64_20 = 1;
        }
        local_3 = func_8080000C_chjiggygamenew(param_0->unk3C) - 0x15;
        for (local_2 = 0, local_1 = local_0; local_2 < 20; local_2++, local_1++) {
            local_4 = *local_1;
            if (local_2 == local_3) *local_1 = 1;
            else *local_1 = 0;
            if (*local_1 != local_4) {
                local_5 = func_8010649C(param_0, local_2 + 0x190);
                switch (*local_1) {
                case 1:
                    func_800EDE54(local_5, D_80803F04_chjiggygamenew, D_80803F14_chjiggygamenew, 0.05f);
                    break;
                case 0:
                    func_800EDE54(local_5, D_80803F14_chjiggygamenew, D_80803F04_chjiggygamenew, 0.2f);
                    break;
                }
            }
        }
    }
}

s32 func_80803928_chjiggygamenew(s32 param_0, s32 *param_1)
{
  u32 local_0;
  s32 *local_1;
  u32 local_2;
  if ((local_0 = func_800E81D0()) != 0)
  {
    local_1 = *((s32 **) (((char *) param_1) + 0x0));
    *((s32 **) (((char *) param_1) + 0x0)) = (s32 *) (((s32) (*((s32 **) (((char *) param_1) + 0x0)))) + 8);
    *((u32 *) local_1) = 0xDB060010;
    local_2 = osVirtualToPhysical(local_0);
    *((u32 *) (((char *) local_1) + 4)) = local_2;
    func_80101870(func_80106790(param_0), param_1);
  }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/jiggy/gamenew.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80803DE5_chjiggygamenew = D_80803DE4_chjiggygamenew + 0x1, D_80803DE6_chjiggygamenew = D_80803DE4_chjiggygamenew + 0x2, D_80803DE7_chjiggygamenew = D_80803DE4_chjiggygamenew + 0x3, D_80803DF9_chjiggygamenew = D_80803DF8_chjiggygamenew + 0x1, D_80803DFA_chjiggygamenew = D_80803DF8_chjiggygamenew + 0x2, D_80803DFB_chjiggygamenew = D_80803DF8_chjiggygamenew + 0x3, D_80803DFD_chjiggygamenew = D_80803DFC_chjiggygamenew + 0x1
 * extern declarations adjusted to the object (same addresses): D_80803DCC_chjiggygamenew -> s32[], D_80803DD8_chjiggygamenew -> s32[], D_80803EBC_chjiggygamenew -> int[] */
extern void func_8010A730();
s32 D_80803AE0_chjiggygamenew[20][3] = { 0x440F2666, 0x43BEA3D7, -0x3CE991EC, 0x440F2666, 0x43BEA3D7, -0x3CC707AE, 0x440F2666, 0x43AD8666, -0x3D0B47AE, 0x440F2666, 0x438AB70A, -0x3CE991EC, 0x440F2666, 0x438AB70A, -0x3CA47D71, 0x440F2666, 0x438AB70A, -0x3C81F333, 0x440F2666, 0x438AB70A, -0x3D0B47AE, 0x440F2666, 0x43BEA3D7, -0x3CA47D71, 0x440F2666, 0x439C4148, -0x3D0B47AE, 0x440F2666, 0x43AD8666, -0x3CA47D71, 0x440F2666, 0x439C4148, -0x3CE991EC, 0x440F2666, 0x43AD8666, -0x3C81F333, 0x440F2666, 0x438AB70A, -0x3CC707AE, 0x440F2666, 0x43AD8666, -0x3CE991EC, 0x440F2666, 0x439C4148, -0x3C81F333, 0x440F2666, 0x439C4148, -0x3CC707AE, 0x440F2666, 0x439C4148, -0x3CA47D71, 0x440F2666, 0x43AD8666, -0x3CC707AE, 0x440F2666, 0x43BEA3D7, -0x3C81F333, 0x440F2666, 0x43BEA3D7, -0x3D0B47AE };
s32 D_80803BD0_chjiggygamenew[20][3] = { 0x441090A4, 0x43D5F1EC, -0x3CE23D71, 0x441090A4, 0x43D5F1EC, -0x3CBB2148, 0x440C8666, 0x43AFEB85, -0x3D6C999A, 0x44067CCD, 0x436E3AE1, -0x3D02C7AE, 0x44066852, 0x436CB5C3, -0x3CB32B85, 0x44066852, 0x436CB5C3, -0x3C728F5C, 0x44067CCD, 0x436E3AE1, -0x3D4D70A4, 0x44107C29, 0x43D52E14, -0x3C94051F, 0x440A928F, 0x439D8E14, -0x3D697AE1, 0x440C8666, 0x43AFEB85, -0x3C662E14, 0x440877AE, 0x4389BEB8, -0x3D760F5C, 0x440EA148, 0x43C3BAE1, -0x3C661852, 0x44066852, 0x436CB5C3, -0x3CDA47AE, 0x440E8C29, 0x43C2F70A, -0x3D760F5C, 0x440A7E14, 0x439CCA3D, -0x3C6551EC, 0x44067148, 0x436D6666, -0x3C8C63D7, 0x440877AE, 0x4389BEB8, -0x3C656666, 0x4410928F, 0x43D603D7, -0x3D120A3D, 0x44107C29, 0x43D52E14, -0x3C75ACCD, 0x441090A4, 0x43D5F1EC, -0x3D5D051F };
u8 D_80803CC0_chjiggygamenew[20][4] = { 0x0, 0x0, 0x0, 0x3C, 0x0, 0x0, 0x0, 0x3D, 0x0, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x42, 0x0, 0x0, 0x0, 0x41, 0x0, 0x0, 0x0, 0x43, 0x0, 0x0, 0x0, 0x3A, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x2E, 0x0, 0x0, 0x0, 0x3E, 0x0, 0x0, 0x0, 0x2A, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0, 0x0, 0x2F, 0x0, 0x0, 0x0, 0x31, 0x0, 0x0, 0x0, 0x2D, 0x0, 0x0, 0x0, 0x34, 0x0, 0x0, 0x0, 0x3B, 0x0, 0x0, 0x0, 0x39 };
f32 D_80803D10_chjiggygamenew[3] = { 222.38f, 328.9f, -186.4f };
f32 D_80803D1C_chjiggygamenew[3] = { 0.0f, 2.7e+02f, 0.0f };
f32 D_80803D28_chjiggygamenew = 0.996982f;
static u32 D_80803D28_chjiggygamenew_rest[2] = { 0x64, 0x64 };
u8 D_80803D34_chjiggygamenew[16] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x3, 0xD7, 0x0, 0x44 };
void *D_80803D44_chjiggygamenew[18] = { (void *)0x015801DF, (void *)0x08630001, (void *)&D_80803D34_chjiggygamenew, (void *)func_80802030_chjiggygamenew, (void *)func_80102EC0, (void *)func_808024F0_chjiggygamenew, 0, 0, 0, (void *)0x00401424, (void *)func_8080245C_chjiggygamenew, 0, (void *)0x02780000, (void *)func_80801EE8_chjiggygamenew, (void *)func_80107C2C, (void *)0x80002002, (void *)func_80802858_chjiggygamenew, 0 };
f32 D_80803D8C_chjiggygamenew[2][4] = { 62.0f, 2.4e+02f, 48.0f, 183.0f, 85.0f, 2.2e+02f, 48.0f, 183.0f };
u8 D_80803DAC_chjiggygamenew[16] = { 0x0, 0x0, 0x0, 0xD8, 0x0, 0x0, 0x0, 0xD8, 0x0, 0x0, 0x0, 0xD8, 0x0, 0x0, 0x0, 0xFF };
u8 D_80803DBC_chjiggygamenew[16] = { 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0x50, 0x0, 0x0, 0x0, 0xFF };
s32 D_80803DCC_chjiggygamenew[3] = { 0x3F333333, 0x0, -0x40E66666 };
s32 D_80803DD8_chjiggygamenew[3] = { 0x44048000, 0x43A47333, -0x3CC5999A };
u8 D_80803DE4_chjiggygamenew[4] = { 0xC6, 0x5F, 0xD6, 0x68 };
u32 D_80803DE8_chjiggygamenew[4] = { 0xD967968D, 0x88A588A6, 0x88A86DA8, 0x6B7D768D };
u8 D_80803DF8_chjiggygamenew[4] = { 0x76, 0x5F, 0x94, 0x67 };
u32 D_80803DFC_chjiggygamenew[3] = { 0x9F708CA5, 0x8CA68CA8, 0x95640000 };
u32 D_80803E08_chjiggygamenew[18] = { 0x0, 0x0, 0x3F800000, 0x3D00049, 0x3F800000, 0x3D30049, 0x3ECCCCCD, 0x3D2004A, 0x3ECCCCCD, 0x3D1004A, 0x3E99999A, 0x3CF0049, 0x3ECCCCCD, 0x3D5004A, 0x40266666, 0x3D4004A, 0x40266666, 0x3D6004A };
s32 D_80803E50_chjiggygamenew[18] = { 0x15801E2, 0x8620001, (u32)&D_80803E08_chjiggygamenew, (u32)func_80802F3C_chjiggygamenew, (u32)func_80102EC0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x400444, (u32)func_80803564_chjiggygamenew, 0x0, 0x440000, (u32)func_80802E80_chjiggygamenew, (u32)func_80107C2C, -0x7FFFFFFE, 0x0, 0x0 };
u32 D_80803E98_chjiggygamenew[3] = { 0x130448, 0x165DC0, 0x1B0000 };
f32 D_80803EA4_chjiggygamenew[3] = { -1e+01f, 15.0f, -35.0f };
f32 D_80803EB0_chjiggygamenew[3] = { -1e+01f, 5.0f, -5e+01f };
int D_80803EBC_chjiggygamenew[18] = { 0x15801DE, 0x8640001, 0x0, (u32)func_8080377C_chjiggygamenew, (u32)func_80102EC0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x401404, 0x0, 0x0, 0x140000, 0x0, (u32)func_80107C2C, -0x7FFFDFFE, 0x0, 0x0 };
u8 D_80803F04_chjiggygamenew[16] = { 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0xFF };
u8 D_80803F14_chjiggygamenew[28] = { 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
