#include "common.h"

typedef struct { void *items; u8 count; u8 id; u8 pad[2]; } MusicCat76;
extern int func_800DC298(f32);
extern void _gcnewoption_entrypoint_31(s32, s32, s32);
extern void _gcnewoption_entrypoint_32(s32, s32);
extern void _gcnewoption_entrypoint_33(s32);
typedef struct { u8 pad[0x70]; u32 pad2 : 6; u32 state : 6; u32 pad3 : 20; } MusicActor76;
typedef struct { s16 local_0; s16 local_2; s16 local_1; } MusicStyle62;
typedef struct { s16 local_0; s16 local_1; } MusicItem62;
typedef struct { MusicItem62 *local_0; u8 local_1; u8 pad_0[3]; } MusicCategory62;
extern MusicStyle62 D_80801554_chmusicmenu;
extern MusicStyle62 D_8080155C_chmusicmenu;
typedef struct { s16 id; u8 unk2; s8 unk3; } MusicEntry;
typedef struct { MusicEntry *entries; s32 pad4; } MusicSet;
extern void func_800FEF94();
extern s32 func_800FCDE0(s32, s32, s32);
extern s32 func_800FCED0(s32, s32, s32);
typedef struct { MusicItem62 *local_0; s32 local_1; } MusicMenuList;
extern MusicMenuList D_808014F4_chmusicmenu[];
typedef struct { s16 id; s16 pad2; } MusicTrack;
typedef struct { MusicTrack *unk0; s32 unk4; } MusicMenuEntry;
extern void func_800FEC60(s32);
extern void func_800DA544(s32);
extern void func_800FCAE0(s32, s32, s32);
extern void func_800FCA90(s32);
extern s16 D_808012A0_chmusicmenu[];
extern void *func_80100094(Actor *, s32);
typedef union { s32 local_0; struct {s16 local_1; s16 local_2;} local_3; } MusicMenuEvent;
extern int D_8080157C_chmusicmenu;
extern int D_808015C4_chmusicmenu;
typedef struct { u8 pad0[0x64]; u32 padH : 8; u32 f : 8; u32 padL : 16; } ByteBf65;
extern int D_8080160C_chmusicmenu;
extern s32 func_800FCF50();
extern void _gcnewoption_entrypoint_27(s32, s32, s32);
extern void func_800FC660(s32);
extern void _gcnewoption_entrypoint_37(void *, s32);
typedef struct { u8 local_0; u8 pad_0[7]; } MusicMenuCount521;
extern MusicMenuCount521 D_808014F8_chmusicmenu[];
extern void _gcnewoption_entrypoint_35(void);
extern u8 func_8010D5DC[];
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void func_8008F990(f32 *, f32);
extern s32 func_800FCCD4(s32);
void func_8080079C_chmusicmenu();
void func_80800930_chmusicmenu();

void func_80800000_chmusicmenu(u8 *param_0) {
    s32 local_0;
    s32 local_1;

    if (func_800DA298(0xC0) != 0) {
        if (*(s32 *)((char *)param_0 + 0x28) != 0) {
            *(f32 *)((char *)param_0 + 0x58) = 10.0f;
            _capod_entrypoint_22();
            local_0 = *(s32 *)((char *)param_0 + 0);
            _capod_entrypoint_21(local_0, local_0, 0x11, 4);
            *(s32 *)((char *)param_0 + 0x28) = 0;
            func_80101238(0x6E, 0);
            return;
        }
        *(f32 *)((char *)param_0 + 0x58) = 15.0f;
        _capod_entrypoint_22();
        local_1 = *(s32 *)((char *)param_0 + 0);
        _capod_entrypoint_21(local_1, local_1, 0x12, 4);
        *(s32 *)((char *)param_0 + 0x28) = 1;
        func_80101238(0x6E, 1);
    }
}

s32 func_808000B4_chmusicmenu(s32 param_0)
{
  if (param_0 < 9)
  {
    return param_0 + 0x1851;
  }
  return param_0 + 0x1860;
}

void func_808000D0_chmusicmenu(u8 *param_0, s32 param_1)
{
    s32 i;

    switch ((u32)*(u16 *)(param_0 + 0x72) >> 10) {
    case 1:
        _gcnewoption_entrypoint_32(param_1, 0x6F);
        for (i = 0; i < 12; i++) {
            if (((MusicCat76 *) D_808014F4_chmusicmenu)[i].id == 0x50 && func_800DC298(0.5f)) {
                _gcnewoption_entrypoint_31(param_1, i, 0x51);
            } else {
                _gcnewoption_entrypoint_31(param_1, i, ((MusicCat76 *) D_808014F4_chmusicmenu)[i].id);
            }
        }
        return;
    case 2:
        _gcnewoption_entrypoint_32(param_1, 0x6F);
        _gcnewoption_entrypoint_33(param_1);
        for (i = 0; i < ((MusicCat76 *) D_808014F4_chmusicmenu)[*(s32 *)(param_0 + 0x30)].count; i++) {
            _gcnewoption_entrypoint_31(param_1, i, ((MusicCat76 *) D_808014F4_chmusicmenu)[*(s32 *)(param_0 + 0x30)].id);
        }
        return;
    }
}

void func_8080021C_chmusicmenu(Actor *param_0, void *param_1)
{
    s32 local_0;
    MusicStyle62 local_1;
    MusicStyle62 local_2;

    switch (param_0->unk70_10) {
    case 1:
        for (local_0 = 0; local_0 < 12; local_0++) _gcnewoption_entrypoint_12(param_1, local_0, (s16)(local_0 + 10));
        if ((s32)param_0->actorData[1] != -1) {
            _gcnewoption_entrypoint_27(param_1, param_0->actorData[1], 1);
            _gcnewoption_entrypoint_41(param_1, param_0->actorData[1]);
        }
        break;
    case 2:
        local_1 = D_80801554_chmusicmenu;
        local_2 = D_8080155C_chmusicmenu;
        for (local_0 = 0; local_0 < ((MusicCategory62 *) D_808014F4_chmusicmenu)[param_0->actorData[6]].local_1; local_0++) {
            _gcnewoption_entrypoint_12(param_1, local_0, (s16)(local_0 + 10));
            if (func_800FCF50(((MusicCategory62 *) D_808014F4_chmusicmenu)[param_0->actorData[6]].local_0[local_0].local_0))
                _gcnewoption_entrypoint_13(param_1, local_0, &local_1);
            else _gcnewoption_entrypoint_13(param_1, local_0, &local_2);
        }
        if (param_0->actorData[1] == param_0->actorData[6] && (s32)param_0->actorData[0] != -1) {
            _gcnewoption_entrypoint_27(param_1, param_0->actorData[0], 1);
            _gcnewoption_entrypoint_41(param_1, param_0->actorData[0]);
        }
        break;
    }
}

void func_80800400_chmusicmenu(Actor *param_0)
{
    MusicEntry *local_3;
    s32 local_0;
    s16 local_1;
    s32 local_2;

    if ((s32)param_0->actorData[0] >= 0 && (!param_0->unk74_30 || !param_0->unk74_29)) {
        local_3 = ((MusicSet *) D_808014F4_chmusicmenu)[param_0->actorData[6]].entries;
        if (local_3[param_0->actorData[0]].unk3 != -1) {
            local_0 = -1;
            local_1 = -1;
            local_2 = local_3[param_0->actorData[0]].id;
            func_800FEF94(4, local_3[param_0->actorData[0]].unk3, local_3[param_0->actorData[0]].unk2, &local_0, &local_1);
            if (!param_0->unk74_30) {
                param_0->unk74_30 = func_800FCDE0(local_2, local_0, param_0->actorData[3]);
            }
            if (!param_0->unk74_29) {
                param_0->unk74_29 = func_800FCED0(local_2, 60000000 / local_1, param_0->actorData[3]);
            }
        }
    }
}

void func_80800560_chmusicmenu(Actor *param_0, s32 param_1, f32 param_2)
{
    MusicItem62 *local_0;

    local_0 = D_808014F4_chmusicmenu[param_0->actorData[6]].local_0;
    if (param_2 == 0.0f) {
        func_800FC660(local_0[param_0->actorData[0]].local_0);
    } else {
        func_800FCAE0(local_0[param_0->actorData[0]].local_0, -1, 0x14D);
    }
    param_0->unk74_30 = 0;
    param_0->unk74_29 = 0;
    ((f32 *)param_0->actorData)[3] = param_2;
    func_80800400_chmusicmenu(param_0);
}

void func_80800610_chmusicmenu(Actor *param_0)
{
    s16 local_0;
    s16 *local_1;
    MusicTrack *local_2;

    if (!param_0->unk64_20) {
        func_800FEC60(5);
        param_0->unk64_20 = 1;
        func_800DA544(0);
    }
    local_1 = &local_0;
    local_2 = ((MusicMenuEntry *) D_808014F4_chmusicmenu)[*(s32 *)((u8 *)param_0 + 0x30)].unk0;
    local_0 = local_2[*(s32 *)((u8 *)param_0 + 0x18)].id;
    if (param_0->unk74_7 != 0) {
        func_800FCAE0(param_0->unk74_7, 0, 0x14D);
        func_800FCA90(param_0->unk74_7);
    }
    if (param_0->unk74_7 == local_0) {
        func_80800560_chmusicmenu(param_0, local_0, 1.5f);
    } else {
        param_0->unk64_19 = 1;
        *(f32 *)((u8 *)param_0 + 0x2C) = 2.0f;
    }
    param_0->unk74_7 = local_0;
}

void func_80800714_chmusicmenu(Actor *param_0)
{
    if (param_0->unk64_20) {
        func_800FECB8(5);
        param_0->unk64_20 = 0;
        func_800FE8AC();
        func_800FCAE0(param_0->unk74_7, 0, 0x14D);
        func_800FCA90(param_0->unk74_7);
        param_0->unk74_7 = 0;
        func_800DA524(0);
    }
}

void func_8080079C_chmusicmenu(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; s32 param_2; s32 param_3;
{
    s32 local_0;

    switch (param_3) {
    case 4:
        if (func_800FCF50(D_808014F4_chmusicmenu[param_0->actorData[6]].local_0[param_2].local_0)) {
            if (!param_0->unk64_19 && param_2 != param_0->actorData[0]) {
                _gcnewoption_entrypoint_27(param_1, param_2, 1);
                local_0 = param_0->actorData[0];
                if (local_0 != -1) {
                    _gcnewoption_entrypoint_27(param_1, local_0, 0);
                }
                param_0->actorData[2] = param_2;
                param_0->actorData[0] = param_2;
                param_0->actorData[1] = param_0->actorData[6];
                func_80800610_chmusicmenu(param_0);
            }
        } else {
            func_800FC660(0xF);
        }
        break;
    case 3:
        param_0->actorData[6] = param_2;
        func_80800930_chmusicmenu(param_0, 2);
        break;
    case 0:
        func_8080021C_chmusicmenu(param_0, param_1);
        break;
    case 5:
        if (!param_0->unk64_19) {
            _gcnewoption_entrypoint_37(func_80100094(param_0, 1), 1);
        }
        break;
    case 2:
        switch (param_0->unk70_10) {
        case 1:
            func_80800930_chmusicmenu(param_0, 3);
            break;
        case 2:
            func_80800930_chmusicmenu(param_0, 1);
            break;
        }
        break;
    }
}

void func_80800930_chmusicmenu(param_0, param_1) Actor *param_0; s32 param_1;
{
    void *local_0;
    void *local_1;
    f32 local_2[3];

    switch (param_0->unk70_10) {
    case 2:
        _gcnewoption_entrypoint_6(param_0, 1);
        break;
    case 1:
        _gcnewoption_entrypoint_6(param_0, 1);
        param_0->actorData[0] = -1;
        param_0->unk64_19 = 0;
        if (param_1 == 3) {
            _capod_entrypoint_22();
            func_80101238(0x6E, 0);
        }
        break;
    case 5:
        func_800F8300(func_800F54E4(), 2, param_0->position);
        _capod_entrypoint_21(param_0->unk0, param_0->unk0, 0x11, 4);
        param_0->actorData[4] = 0;
        param_0->unk58 = 10.0f;
        break;
    }
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
    case 1:
        _gcnewoption_entrypoint_4(param_0, 1, _gcnewoption_entrypoint_35, 0, 0x1850);
        local_0 = func_80100094(param_0, 1);
        _gcnewoption_entrypoint_40(local_0, 0x41, 0x22, 0x20, 0.8f, 1.0f);
        _gcnewoption_entrypoint_8(local_0, 5);
        _gcnewoption_entrypoint_9(local_0, 12);
        _gcnewoption_entrypoint_10(local_0, 0);
        func_808000D0_chmusicmenu(param_0, local_0);
        _gcnewoption_entrypoint_14(local_0, 0, 1, 3, 4.0f);
        _gcnewoption_entrypoint_11(local_0);
        return;
    case 2:
        _gcnewoption_entrypoint_4(param_0, 1, _gcnewoption_entrypoint_35, 0,
            func_808000B4_chmusicmenu(param_0->actorData[6]));
        local_1 = func_80100094(param_0, 1);
        _gcnewoption_entrypoint_40(local_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
        _gcnewoption_entrypoint_8(local_1,
            D_808014F8_chmusicmenu[param_0->actorData[6]].local_0 < 5 ?
            D_808014F8_chmusicmenu[param_0->actorData[6]].local_0 : 5);
        _gcnewoption_entrypoint_9(local_1, D_808014F8_chmusicmenu[param_0->actorData[6]].local_0);
        _gcnewoption_entrypoint_10(local_1, 2);
        func_808000D0_chmusicmenu(param_0, local_1);
        _gcnewoption_entrypoint_14(local_1, 0, 1, 3, 4.0f);
        if (param_0->actorData[1] == param_0->actorData[6]) {
            if ((s32)param_0->actorData[2] != -1) {
                param_0->actorData[0] = param_0->actorData[2];
            }
        }
        _gcnewoption_entrypoint_11(local_1);
        return;
    case 4:
        param_0->actorData[1] = param_0->actorData[2] = -1;
        break;
    case 3:
        func_800F82D4(func_800F54E4(), 0);
        func_80800714_chmusicmenu(param_0);
        param_0->actorData[2] = -1;
        param_0->actorData[1] = -1;
        param_0->actorData[6] = -1;
        break;
    case 5:
        _gccubesearch_entrypoint_12(local_2, 0x299, param_0->position);
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(func_8010D5DC, param_0->unk0);
        func_8008F938(1);
        func_8008F990(local_2, 400.0f);
        break;
    }
}

void func_80800CBC_chmusicmenu(Actor *param_0)
{
    s32 local_0;

    *(s32 *)((u8 *)param_0 + 0x30) = -1;
    param_0->unk74_7 = 0;
    *(s32 *)((u8 *)param_0 + 0x18) = -1;
    local_0 = 0;
    func_8010A828(param_0, 9);
    if (func_800D3E40(5)) {
        func_80800930_chmusicmenu(param_0, 4);
    } else if (func_800DA298(0x344)) {
        func_80800930_chmusicmenu(param_0, 6);
    } else {
        func_80800930_chmusicmenu(param_0, 7);
    }
    while (D_808012A0_chmusicmenu[local_0] != 0x9A) {
        local_0++;
    }
    func_800DA3B8(local_0 + 0x53E, func_800DA298(0x43));
}

void func_80800DA4_chmusicmenu(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 4:
            if (func_8010C500(param_0)) {
                if (!func_800DA298(0x3E1)) {
                    func_80800930_chmusicmenu(param_0, 5);
                    func_800DA544(0x3E1);
                    return;
                }
                if (func_80016B30(0, 1)) { func_80800930_chmusicmenu(param_0, 5); }
            }
            break;
        case 2:
            if (param_0->unk64_19 && func_800D90A4((f32 *)param_0->actorData + 5)) {
                func_80800560_chmusicmenu(param_0, param_0->unk74_7, 0.0f);
                param_0->unk64_19 = 0;
            }
        case 1:
            if (param_0->unk74_7) {
                if (func_800FCCD4(param_0->unk74_7) && !param_0->unk64_19) { func_80800400_chmusicmenu(param_0); }
                if (func_800D90A4(&param_0->unk58)) { func_80800000_chmusicmenu(param_0); }
            }
            _gcnewoption_entrypoint_0(func_80100094(param_0, 1));
            break;
        case 3: func_80800930_chmusicmenu(param_0, 4); break;
        case 7:
            if (func_8010C500(param_0)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1048, 0xF, param_0->position, 0x6F);
                func_800DA544(0x344);
                func_80800930_chmusicmenu(param_0, 6);
            }
            break;
    }
}

void func_80800F50_chmusicmenu(u8 *param_0)
{
  unsigned int new_var;
  func_80800714_chmusicmenu(param_0);
  new_var = ((unsigned int) (*((u16 *) (((char *) param_0) + 0x72)))) >> 10;
  if ((new_var == 1) || (new_var == 2))
  {
 if (0) { }
    _gcnewoption_entrypoint_6(param_0, 1);
  }
}

void func_80800F98_chmusicmenu(Actor *param_0, void *param_1)
{
    void *local_0;
    if (!func_800EB854(param_0)) {
        if ((s32)param_0->unk70_10 < 6) {
            func_800DF744(1, 0);
            func_800DF744(2, 1);
        } else {
            func_800DF744(1, 1);
            func_800DF744(2, 0);
        }
        func_80101870(param_0, param_1);
    } else {
        local_0 = func_80100094(param_0, 1);
        if (local_0 != NULL) _gcnewoption_entrypoint_1(local_0, param_1);
    }
}

s32 func_80801040_chmusicmenu(Actor *param_0, s32 param_1, MusicMenuEvent param_2)
{
    switch (param_1) {
        case 0x20:
            func_8080079C_chmusicmenu(param_0, func_80101080(param_0),
                param_2.local_3.local_1, param_2.local_3.local_2);
            return 1;
        case 0x32:
            func_80800930_chmusicmenu(param_0, 1);
            return 1;
    }
    return 0;
}

int chmusicmenu_entrypoint_0()
{
    return (int)&D_8080157C_chmusicmenu;
}

int chmusicmenu_entrypoint_1()
{
  return &D_808015C4_chmusicmenu;
}

int func_808010C4_chmusicmenu(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0[14];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    switch (param_1) {
    case 0x95:
        if (!func_800D3E40(5) || !func_800DA298(0xC0) || _glcutDll_entrypoint_20()) func_800FFAB0(param_0);
        else ((ByteBf65 *)(param_0))->f &= ~1;
        return 1;
    case 0x6E:
        local_4 = param_2 & 1;
        ((ByteBf65 *)(param_0))->f = (local_4 & 1) | (((ByteBf65 *)(param_0))->f & ~1);
        if (local_4) {
            local_3 = 0;
            local_2 = 0;
            if (((u32)*(u16 *)((u8 *)param_0 + 0x76)) >> 7 != 0x33) {
                for (local_2 = 0; local_2 < 14; local_2++) {
                    if (!func_800DA298(local_2 + 1)) local_0[local_3++] = local_2;
                }
                if (local_3 == 0) {
                    for (local_2 = 0; local_2 < 14; local_2++) {
                        func_800DA524(local_2 + 1);
                    }
                    local_2 = func_800DC128(0, 14);
                } else local_2 = local_0[func_800DC128(0, local_3)];
                local_1 = local_2 + 1;
                func_800DA544(local_1);
                func_80102424(param_0, local_1);
            }
        }
        return 1;
    default: return 0;
    }
}

int chmusicmenu_entrypoint_2()
{
  return &D_8080160C_chmusicmenu;
}
