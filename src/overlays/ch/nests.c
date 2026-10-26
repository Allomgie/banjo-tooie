#include "common.h"

#define CODEX_NEST_RECORD_DEFINED
#define CODEX_NEST_EVENT_RECORD
typedef struct { s16 unk0; u8 pad2[0xC]; } NestRecord_80800000_chnests;
extern void func_800FFAB0(Actor *);
extern s32 _subaddiesect_entrypoint_1(Actor *);
extern void _subaddiesect_entrypoint_2(Actor *, s32, s32);
typedef struct { u8 pad[8]; s16 f8; u8 padA[4]; } NestEnt;
extern void _sudialog_entrypoint_0(s32, s32);
typedef struct { s16 unk0; s16 pad2; s16 sparkle; s16 sound; u16 pad8; u8 reward; u8 amount; u16 padC; } NestRecord_80800144_chnests;
extern s16 D_808011DC_chnests[][2];
extern f32 func_800DC178(f32, f32);
extern void _subaddiefade_entrypoint_2();
extern void _subaddieDll_entrypoint_4(void *param_0, int param_1);
extern void func_80101FDC(void *param_0, void *param_1);
extern void func_80103110(void *param_0, int param_1);
extern void func_8010A590(void *param_0);
typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest:10; } NestState;
extern s32 func_800D9078();
typedef struct { u8 pad0[0x1A]; u16 unk1A_5 : 11; u16 pad1A_0 : 5; } NestMsg;
extern s32 func_800F4B4C(s32);
extern void func_800F7C0C(s32, s32, s32);
extern void func_80109EEC(Actor *, s32);
extern void func_8010DC50(s32);
extern void func_8010DCB4(s32);
extern u8 field_0x20[];
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 4; u32 local_0 : 1; u32 pad_2 : 27; } NestFlags1367;
extern f32 func_800D8FF8(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
typedef struct { u8 unk0; u8 pad1[0xD]; } NestEventRecord;
extern NestEventRecord D_80801124_chnests[];
extern void func_800DF3E0(void);
extern void func_800DF744(s32, s32);
extern void func_801018A4(Actor *, s32);
typedef struct { s16 id; s16 flag; u8 pad4[0xA]; } NestEntry;
extern s32 func_800C6E38(s32);
typedef struct { s16 unk0; u8 pad2[0xC]; } NestRecord_80800BA0_chnests;
typedef struct { u8 pad0[0x24]; u16 unk24_6 : 10; u16 pad24_0 : 6; } NestMarkerView;
typedef struct { NestMarkerView *unk0; u8 pad4[0x18]; s32 unk1C; } NestActorView;
typedef struct { u8 unused[0x24]; u16 index : 10; u16 flags : 6; } NestMarkerIndex;
extern int D_808011E8_chnests;
extern int D_80801230_chnests;
extern void *D_80801278_chnests;
extern s32 D_808012C0_chnests[];
extern int D_80801308_chnests;
extern int D_80801350_chnests;
extern int D_80801398_chnests;
extern s32 D_808013E0_chnests[];
extern int D_80801428_chnests;
extern int D_80801470_chnests;
extern int D_808014B8_chnests;
extern int D_80801500_chnests;
extern int D_80801548_chnests;
typedef struct { s16 unk0; u8 pad2[0xC]; } NestRecord_chnests_entrypoint_13;
extern NestRecord_chnests_entrypoint_13 D_80801118_chnests[];
extern u8 unk6C[];
extern u8 D_8012762C;
extern s32 func_800DC298(f32);
void func_808002E0_chnests();
int func_80800670_chnests();
s32 func_80800898_chnests(Actor *param_0, s32 param_1, f32 param_2);
s32 func_8080093C_chnests();
void func_80800B80_chnests();
int func_80801014_chnests();
int func_808010A0_chnests();

void func_80800000_chnests(param_0) Actor *param_0;
{
    NestRecord_80800000_chnests *local_0;
    s32 local_1;
    u32 local_2;
    s32 local_3;

    local_3 = 14;
    local_0 = ((NestRecord_80800000_chnests *) D_80801118_chnests);
    local_1 = 0;
    local_2 = param_0->unk0->unk24 >> 22;
    do {
        if (local_2 == local_0->unk0) {
            break;
        }
        local_1++;
        local_0++;
    } while (local_1 < local_3);
    if (local_1 == 14) {
        func_800FFAB0(param_0);
        return;
    }
    *(s32 *)((u8 *)param_0 + 0x1C) = local_1;
    *(s32 *)((u8 *)param_0 + 0x24) = _subaddiesect_entrypoint_1(param_0);
    if (*(s32 *)((u8 *)param_0 + 0x24) != -1) {
        _subaddiesect_entrypoint_2(param_0, *(s32 *)((u8 *)param_0 + 0x24), 0);
    }
}

void func_80800098_chnests(s32 param_0)
{
    func_80800000_chnests();
    if ((func_800D3948() == 0) && (func_800F7150(func_800F54E4()) != 0)) {
        func_808002E0_chnests(param_0);
    }
}

void func_808000E8_chnests(u8 *param_0) {
    NestEnt *local_0 = &((NestEnt *) D_80801118_chnests)[*(s32 *)(param_0 + 0x1C)];
    if (local_0->f8 != 0 && func_800DA298(local_0->f8) == 0) {
        _sudialog_entrypoint_0(local_0->f8, 0);
    }
}

void func_80800144_chnests(param_0, param_1) Actor *param_0; Unk80132ED0 *param_1;
{
    NestRecord_80800144_chnests *local_0;
    local_0 = &((NestRecord_80800144_chnests *) D_80801118_chnests)[param_0->actorData[1]];
    if (local_0->sparkle) _fxsparkle_entrypoint_1(param_0->position, local_0->sparkle);
    if (local_0->sound) func_800FC660(local_0->sound);
    if (local_0->reward && (_gleeprom_entrypoint_0() >> 24) == 16) {
        func_800F7664(((u32)(*(u16 *)((u8 *)param_1 + 0x1A))) >> 5, local_0->reward, local_0->amount);
    }
}

void func_808001F0_chnests(param_0) Actor *param_0;
{
    Unk80132ED0 *local_0;
    s32 local_1;

    local_0 = param_0->unk0;
    local_1 = param_0->unk74_7 - 0x32;
    func_80800144_chnests(param_0);
    func_808000E8_chnests(param_0);
    switch (local_1) {
        case 1:
        case 2:
        case 3:
            param_0->unk58 = func_800DC178(D_808011DC_chnests[local_1 - 1][0], D_808011DC_chnests[local_1 - 1][1]);
            param_0->unk64_16 = 0;
            func_8010A570(param_0);
            func_80103110(param_0, 1);
            _subaddieDll_entrypoint_4(param_0, 1);
            *(s32 *)((u8 *)param_0 + 0x18) = param_0->unk70_10;
            func_80101FDC(param_0, 4);
            func_80800B80_chnests(param_0);
            break;
        default:
            func_800FFA88(local_0);
            break;
    }
}

void func_808002E0_chnests(param_0) u8 *param_0; {
    param_0[0x65] &= 0xFFFE;
    func_8010A570();
    *(u32 *)(param_0 + 0x18) = (u32)*(u16 *)(param_0 + 0x72) >> 0xA;
    func_80101FDC(param_0, 4);
}

void func_80800324_chnests(arg0) s32 arg0;
{
    func_80800144_chnests();
    func_808002E0_chnests(arg0);
}
void func_8080034C_chnests(void *param_0)
{
  _subaddiefade_entrypoint_2();
  func_80103110(param_0, 0);
  _subaddieDll_entrypoint_4(param_0, 0);
  func_8010A590(param_0);
  ((u8 *) param_0)[0x65] = (((u8 *) param_0)[0x65] & 0xFF) | 1;
  func_80101FDC(param_0, *((s32 *) (((char *) param_0) + 0x18)));
}

void func_808003AC_chnests(NestState *param_0) {
    if (param_0->f72 == 4 && func_800D9078((u8 *)param_0 + 0x58, param_0) != 0) {
        func_8080034C_chnests(param_0);
    }
}

void func_808009D4_chnests();

s32 func_808003F4_chnests(Actor *param_0, s32 param_1, s32 param_2)
{
    NestMsg *local_0;

    switch (param_1) {
    case 0x3E:
        local_0 = *(NestMsg **)&param_2;
        if (!func_800F4B4C(local_0->unk1A_5)) {
            return 0;
        }
        switch (param_0->unk0->unk24 >> 22) {
        case 0x1D9:
        case 0x1DA:
            func_80800670_chnests(param_0, local_0);
            return 1;
        case 0x1D4:
            func_800F7C0C(local_0->unk1A_5, 0x5F, param_0->actorData[12]);
            if (param_0->unk74_7 == 0x32) {
                func_808001F0_chnests(param_0, local_0);
                return 1;
            }
            func_80800324_chnests(param_0, local_0);
            return 1;
        default:
            func_808001F0_chnests(param_0, local_0);
            return 1;
        }
    case 0x1F:
        if (func_80801014_chnests(param_0)) {
            func_8080093C_chnests(param_0, param_2);
            return 1;
        }
        if (func_808010A0_chnests(param_0)) {
            func_808009D4_chnests(param_0, param_2);
            return 1;
        }
        break;
    case 0x95:
        if (param_0->unk6C_9 != 0x1E9 && param_0->unk6C_9 != 0x4A6) {
            func_80103110(param_0, 0);
        }
        func_80109EEC(param_0, 0x44);
        return 1;
    case 0x29:
        if (func_80801014_chnests(param_0)) {
            func_8010DC50(0);
            return 1;
        }
        if (func_808010A0_chnests(param_0)) {
            func_8010DC50(1);
        }
        break;
    case 0x2A:
        if (func_80801014_chnests(param_0)) {
            func_8010DCB4(0);
            return 1;
        }
        if (func_808010A0_chnests(param_0)) {
            func_8010DCB4(1);
        }
        break;
    case 0x76:
        func_8080034C_chnests(param_0);
        func_80101FDC(param_0, 1);
        return 1;
    default:
        return 0;
    }
    return 1;
}

int func_80800670_chnests(param_0) Actor *param_0;
{
  func_80800144_chnests();
  func_808000E8_chnests(param_0);
  if ((_gleeprom_entrypoint_0() >> 0x18) == 0x10) {
    func_800D0BD4(*(u8 **)((char *)param_0 + 0x20), 6);
  }
  func_800FFAB0(param_0);
}

void func_808006C4_chnests(Actor *param_0)
{
    s32 local_0;
    f32 local_1;

    local_0 = (s32)param_0->unk74_7 - 50;
    if (local_0 <= 0 || local_0 >= 18) {
        func_800FFAB0(param_0);
        return;
    }
    param_0->actorData[2] = func_800D13E8(6, D_8012762C) + param_0->unk74_7 - 50;
    if (func_800D0B68(param_0->actorData[2], 6)) {
        func_800FFAB0(param_0);
        return;
    }
    func_80800000_chnests(param_0);
    *(f32 *)&param_0->actorData[4] = param_0->rotation[1];
    local_1 = func_800DC298(0.5f) ? -1.0f : 1.0f;
    *(f32 *)&param_0->actorData[5] = func_800DC178(540.0f, 630.0f) * local_1;
    param_0->rotation[1] = func_800DC178(0.0f, 360.0f);
}

void func_808007C8_chnests(Actor *param_0)
{
    if (param_0->unk70_10 == 2 && ((NestFlags1367 *)param_0)->local_0) {
        param_0->rotation[1] += *(f32 *)((u8 *)param_0 + 0x2C) * func_800D8FF8();
        func_80103110(param_0, 0);
    }
}

void func_8080082C_chnests(Actor *param_0, s32 *param_1)
{
  if (func_80800898_chnests(param_0, param_1, *(f32 *)&param_0->actorData[4])) {
    func_80101870(param_0, param_1);
    if (param_0->unk7C_12 && (param_0->unk70_10 == 2)) {
      func_80103110(param_0, 1);
    }
  }
}

s32 func_80800898_chnests(Actor *param_0, s32 param_1, f32 param_2)
{
    f32 local_0[3];
    s32 local_1;
    local_1 = func_800D674C(0x85C);
    func_80101970(param_0);
    func_80106A98(param_0, local_1);
    func_800DF830(1);
    func_800DF410(_subaddiefade_entrypoint_0(param_0));
    func_800EFA4C(local_0, 0.0f, param_2, 0.0f);
    return (s32)func_800DE448(param_0->position, local_0, param_0->scale, (f32 *)func_801018D8(param_0), local_1);
}

s32 func_8080093C_chnests(param_0, param_1) s32 param_0; s32 param_1;{
    func_8010DD20(param_0, 0, param_1 | 0);
}

void func_80800960_chnests(s32 arg0) 
{
}
void func_80800968_chnests(Actor *param_0, s32 param_1)
{
    if (func_80800898_chnests(param_0, param_1, param_0->rotation[1])) {
        func_800DF3E0();
        func_800DF744(D_80801124_chnests[param_0->actorData[1]].unk0, 1);
        func_801018A4(param_0, param_1);
    }
}

void func_808009D4_chnests(s32 arg0,s32 arg1)
{
    func_8010DD20(arg0,0x1,arg1);
}

void func_808009F8_chnests(s32 arg0) 
{
}
void func_80800A00_chnests(Actor *param_0, s32 param_1)
{
    if (func_80800898_chnests(param_0, param_1, param_0->rotation[1])) {
        func_800DF3E0();
        func_800DF744(D_80801124_chnests[param_0->actorData[1]].unk0, 1);
        func_801018A4(param_0, param_1);
    }
}

void func_80800A6C_chnests(s32 arg0) 
{
}
s32 func_80800A74_chnests(s32 param_0)
{
    s16 local_0;

    local_0 = ((NestEntry *) D_80801118_chnests)[param_0].id;
    param_0++;
    while (local_0 != ((NestEntry *) D_80801118_chnests)[param_0].id) {
        if (((NestEntry *) D_80801118_chnests)[param_0].id == -1 && param_0 > 0 &&((NestEntry *) D_80801118_chnests)[param_0 - 1].id != -1) {
            do {
                param_0--;
            } while (param_0 > 0 &&((NestEntry *) D_80801118_chnests)[param_0 - 1].id != -1);
        }
        if (((NestEntry *) D_80801118_chnests)[param_0].flag == 0 || func_800C6E38(((NestEntry *) D_80801118_chnests)[param_0].flag) != 0) {
            break;
        }
        param_0++;
    }
    return param_0;
}

void func_80800B4C_chnests(u8 *param_0) {
    *(f32 *)(param_0 + 0x58) = func_800DC178(*(f32 *)(param_0 + 0x28), *(f32 *)(param_0 + 0x2C));
    *(s32 *)(param_0 + 0x30) = 0;
}

void func_80800B80_chnests(param_0) void *param_0;
{
  char *new_var2;
  char *new_var3;
  int new_var;
  unsigned short new_var4;
  new_var = (((*((s32 *) (((char *) param_0) + 0x64))) << 2) << 9) < 0;
  new_var4 = 9;
  new_var3 = (char *) param_0;
  if ((((*((s32 *) (((char *) param_0) + 0x64))) << 2) << new_var4) < (new_var * 0))
  {
    new_var2 = new_var3 + 0x30;
    *((s32 *) new_var2) = 2;
    if (param_0)
    {
      if (1)
      {
      }
    }
  }
}

void func_80800BA0_chnests(NestActorView *param_0, s32 param_1)
{
    NestMarkerView *local_0;

    local_0 = param_0->unk0;
    param_0->unk1C = param_1;
    local_0->unk24_6 = ((NestRecord_80800BA0_chnests *) D_80801118_chnests)[param_1].unk0;
}

void func_80800BD8_chnests(Actor *param_0, s32 param_1, f32 param_2, f32 param_3)
{
    ((NestMarkerIndex *)param_0->unk0)->index = param_1;
    func_80800000_chnests(param_0);
    param_0->unk64_20 = 1;
    *(f32 *)&param_0->actorData[4] = param_2;
    *(f32 *)&param_0->actorData[5] = param_3;
    func_80800B4C_chnests(param_0);
}

void func_80800C3C_chnests(Actor *param_0)
{
    switch (param_0->actorData[6]) {
    case 0:
        if (!(*(u16 *)((u8 *)param_0 + 0x78) & 3) && func_800D9078((f32 *)((u8 *)param_0 + 0x58))) {
            param_0->unk6C_0 = func_80800A74_chnests(param_0->actorData[1]);
            if (param_0->unk6C_0 == param_0->actorData[1]) { func_80800B4C_chnests(param_0); return; }
            param_0->unk58 = 0.25f;
            param_0->actorData[6] = 1;
        }
        break;
    case 1:
        if (func_800D9078((f32 *)((u8 *)param_0 + 0x58))) {
            func_80800BA0_chnests(param_0, param_0->unk6C_0); func_80800B4C_chnests(param_0); func_8010A828(param_0, 1);
        } break;
    case 2:
        if (func_800D9078((f32 *)((u8 *)param_0 + 0x58))) {
            _subaddiefade_entrypoint_2(param_0); func_8010A590(param_0); _subaddieDll_entrypoint_4(param_0, 0);
            param_0->unk64_16 = 1; func_80101FDC(param_0, param_0->actorData[0]); func_80800B4C_chnests(param_0);
        } break;
    }
}

void func_80800D8C_chnests(Actor *param_0, s32 param_1)
{
    s32 local_0;
    if (func_80800898_chnests(param_0, param_1, param_0->rotation[1])) {
        func_800DF3E0();
        func_800DF744(D_80801124_chnests[param_0->actorData[1]].unk0, 1);
        if (param_0->actorData[6] == 1) {
            local_0 = *(f32 *)((u8 *)param_0 + 0x58) / 0.25f * 255.0f;
            ((u8 *)param_0)[0x7A] = (((u8 *)param_0)[0x7A] & ~0xC0) | 0x80;
            _subaddiefade_entrypoint_1(param_0, local_0); func_801018A4(param_0, param_1);
            func_800DF3E0();
            func_800DF744(D_80801124_chnests[param_0->unk6C_0].unk0, 1);
            ((u8 *)param_0)[0x7A] = (((u8 *)param_0)[0x7A] & ~0xC0) | 0x40;
            _subaddiefade_entrypoint_1(param_0, 255 - local_0); func_801018A4(param_0, param_1);
            ((u8 *)param_0)[0x7A] = (((u8 *)param_0)[0x7A] & ~0xC0) | 0x40;
            _subaddiefade_entrypoint_1(param_0, 255);
        } else func_801018A4(param_0, param_1);
    }
}

void func_80800ED8_chnests(s32 param_0) {
    func_80800BD8_chnests(param_0, 0x1CE, 1.0f, 1.0f);
}

void func_80800F08_chnests(s32 param_0) {
    func_80800BD8_chnests(param_0, 0x1d5, 1.0f, 1.0f);
}

int chnests_entrypoint_0()
{
  return &D_808011E8_chnests;
}

int chnests_entrypoint_1()
{
  return &D_80801230_chnests;
}

int chnests_entrypoint_2(void)
{
    return (int)&D_80801278_chnests;
}

int chnests_entrypoint_3()
{
  return D_808012C0_chnests;
}

int chnests_entrypoint_4()
{
  return (int)&D_80801308_chnests;
}

int chnests_entrypoint_5()
{
    return (int)&D_80801350_chnests;
}

int *chnests_entrypoint_6()
{
    return &D_80801398_chnests;
}

int chnests_entrypoint_7()
{
  return D_808013E0_chnests;
}

void *chnests_entrypoint_8()
{
    return &D_80801428_chnests;
}

int *chnests_entrypoint_9()
{
    return &D_80801470_chnests;
}

int chnests_entrypoint_10()
{
    return (int)&D_808014B8_chnests;
}

int *chnests_entrypoint_11()
{
    return &D_80801500_chnests;
}

int chnests_entrypoint_12()
{
  return (int)&D_80801548_chnests;
}

u8 chnests_entrypoint_13(s32 param_0)
{
    s32 local_2;
    s32 local_1;
    NestRecord_chnests_entrypoint_13 *local_0;

    local_2 = 14;
    for (local_1 = 0, local_0 = D_80801118_chnests; local_1 < local_2; local_1++, local_0++) {
        if (local_0->unk0 == param_0) {
            return local_0->pad2[9];
        }
    }
    return 0;
}

int func_80801014_chnests(param_0) Actor *param_0;
{
    return param_0->unk6C_9 == 0x1C8 || param_0->unk6C_9 == 0x1C9 ||
           param_0->unk6C_9 == 0x1CA || param_0->unk6C_9 == 0x1CB ||
           param_0->unk6C_9 == 0x1CC || param_0->unk6C_9 == 0x1CD ||
           param_0->unk6C_9 == 0x2B8 || param_0->unk6C_9 == 0x1E9;
}

int func_808010A0_chnests(param_0) Actor *param_0;
{
  u32 local_0;
  local_0 = (*(u32 *)((char *)(param_0) + 0x6C)) << 11;
  local_0 = local_0 >> 20;
  return local_0 == 0x1CE || local_0 == 0x1CF || local_0 == 0x4A6;
}
