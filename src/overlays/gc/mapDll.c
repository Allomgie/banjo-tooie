#include "common.h"

typedef struct { s16 id; s16 pad[6]; } MapEnt;
extern MapEnt D_80800F10_gcmapDll[];
typedef struct { s32 pad0; s32 idA; s32 rtA; s32 hA; s32 xA; s32 pA; s32 mA; s32 vA; s32 pad20[4]; s32 idB; s32 rtB; s32 hB; s32 xB; s32 pB; s32 mB; s32 vB; s32 pad4C[3]; u16 pad58; u16 uA; u16 uB; u8 pad5E[6]; u8 fA; u8 fB; } GCMapLights;
extern s32 func_800B27BC(s32);
extern s32 func_800B27A0(s32);
extern s32 func_800B2868(s32);
extern s32 func_800B274C(s32);
extern s32 func_800B2400(s32, s32);
typedef struct { u8 pad_0[0x10]; s32 local_0; u8 pad_1[0x18]; } MapBoundingRecord;
typedef struct { u8 pad_0[0x38]; s32 local_0; u8 pad_1[0x144]; s32 local_1[3]; s32 local_2[3]; s32 local_3[3]; s32 local_4[3]; } MapBoundingBoxes;
extern void func_800EE830(s32 *, s32 *);
typedef struct { s32 a; s32 b; s32 c; s32 d; } MapSlot88;
typedef struct { s32 unk0; u8 pad4[8]; s32 unkC; s32 unk10; s32 unk14; u8 pad18[8]; s32 unk20; u8 pad24[4]; u8 unk28; u8 unk29; u8 unk2A; u8 unk2B; s32 unk2C; u8 pad30[8]; s32 unk38; s32 unk3C; s32 unk40; u8 pad44[8]; s32 unk4C; u8 pad50[4]; u8 unk54; u8 unk55; u8 unk56; u8 unk57; u8 unk58[2]; u16 unk5A; u16 unk5C; u8 pad5E[0x27]; u8 unk85; u8 unk86; u8 unk87; MapSlot88 slot[15]; s32 unk178; s32 unk17C; u8 pad180[0x30]; s32 unk1B0; } MapDllState;
extern void func_800BF744(s32, s32);
extern s32 func_800EA05C(void);
extern void rare_memcpy(void *, void *, s32);
extern s32 func_800D674C(s32);
extern void func_800D70D0(s32);
extern void func_800D71F4(s32);
extern s32 func_800B2720(s32);
extern s32 func_800B2840(s32);
extern s32 func_800B284C(s32);
extern s32 func_800EA068(s32);
extern s32 _glzone_entrypoint_0(s32);
extern s32 func_800DBFF8(void);
extern u8 func_800D731C(s32);
extern void _gcmapsects_entrypoint_15(MapDllState *);
typedef struct { u8 pad_0[4]; void *id; void *light; u8 pad_1[8]; void *geometry; s32 viewport; void *view; u8 pad_2[4]; void *texture; u8 pad_3[4]; } MapResourceRecord;
typedef struct { s16 map; s16 region; } MapRegionRecord;
extern MapRegionRecord D_80801BE8_gcmapDll[];
extern u8 D_80801B98_gcmapDll[];
extern u8 D_80801BA0_gcmapDll[];
extern u8 D_80801BA8_gcmapDll[];
extern u8 D_80801BB0_gcmapDll[];
extern u8 D_80801BB8_gcmapDll[];
extern u8 D_80801BC8_gcmapDll[];
extern u8 D_80801BD8_gcmapDll[];
void gcmapDll_entrypoint_2();

int func_80800000_gcmapDll(s32 param_0)
{
  s16 *local_0 = &((s16 *) D_80800F10_gcmapDll)[0];
  while (*local_0 != 0)
  {
    if (*local_0 == param_0)
    {
      return local_0;
    }
    local_0 += 7;
  }

  return 0;
}

s32 gcmapDll_entrypoint_0(s32 param_0) {
    MapEnt *local_0;
    for (local_0 = D_80800F10_gcmapDll; local_0->id != 0; local_0++) {
        if (param_0 == local_0->id) {
            return 1;
        }
    }
    return 0;
}

void gcmapDll_entrypoint_1(GCMapLights *param_0)
{
    s32 sp34[3];
    s32 var_a3;
    s32 var_v1;

    func_800C87DC(sp34);
    if (param_0->hA != 0 && func_800A946C() < 3) {
        var_a3 = func_800B27BC(param_0->hA);
    } else {
        var_a3 = 0;
    }
    if (var_a3 != 0) {
        _dblight_entrypoint_0(var_a3, param_0->xA, sp34);
        _dblight_entrypoint_1(var_a3, param_0->xA, func_800B27A0(param_0->hA));
    }
    if (var_a3 != 0) {
        param_0->rtA = _rtlight_entrypoint_1(var_a3, param_0->xA, func_800B27A0(param_0->hA));
    } else {
        param_0->rtA = 0;
    }
    if (param_0->hB != 0 && func_800A946C() < 3) {
        var_a3 = func_800B27BC(param_0->hB);
    } else {
        var_a3 = 0;
    }
    if (var_a3 != 0) {
        _dblight_entrypoint_0(var_a3, param_0->xB, sp34);
        _dblight_entrypoint_1(var_a3, param_0->xB, func_800B27A0(param_0->hB));
    }
    if (var_a3 != 0) {
        param_0->rtB = _rtlight_entrypoint_1(var_a3, param_0->xB, func_800B27A0(param_0->hB));
    } else {
        param_0->rtB = 0;
    }
    if (param_0->hA != 0 && func_800A946C() < 3 && (param_0->mA = func_800B2868(param_0->hA)) != 0) {
        param_0->vA = _vpmodule_entrypoint_0(param_0->mA, param_0->xA, sp34);
    } else {
        param_0->vA = 0;
    }
    if (param_0->hB != 0 && func_800A946C() < 3 && (param_0->mB = func_800B2868(param_0->hB)) != 0) {
        param_0->vB = _vpmodule_entrypoint_0(param_0->mB, param_0->xB, sp34);
    } else {
        param_0->vB = 0;
    }
    if (param_0->hA != 0 && param_0->mA == 0 && param_0->rtA == 0) {
        func_800B2464(param_0->xA, sp34, param_0->xA);
    }
    if (param_0->hB != 0 && param_0->mB == 0 && param_0->rtB == 0) {
        func_800B2464(param_0->xB, sp34, param_0->xB);
    }
    if (param_0->hA != 0 && func_800A946C() < 3) {
        var_v1 = func_800B274C(param_0->hA);
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        param_0->idA = _glidmake_entrypoint_5(param_0->uA, 0);
    } else {
        param_0->idA = 0;
    }
    if (param_0->idA != 0) {
        _idworldmake_entrypoint_0(param_0->idA, 1);
    }
    if (param_0->hB != 0 && func_800A946C() < 3) {
        var_v1 = func_800B274C(param_0->hB);
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        param_0->idB = _glidmake_entrypoint_5(param_0->uB, 0);
    } else {
        param_0->idB = 0;
    }
    if (param_0->idB != 0) {
        _idworldmake_entrypoint_0(param_0->idB, 1);
    }
    if (param_0->xA != 0 && param_0->fA != 0) {
        param_0->pA = func_800B2400(param_0->xA, 1);
    } else {
        param_0->pA = 0;
    }
    if (param_0->xB != 0 && param_0->fB != 0) {
        param_0->pB = func_800B2400(param_0->xB, 1);
    } else {
        param_0->pB = 0;
    }
    if (param_0->idA != 0 && param_0->pA != 0) {
        _glid_entrypoint_6(param_0->idA, param_0->pA);
    }
    if (param_0->idB != 0 && param_0->pB != 0) {
        _glid_entrypoint_6(param_0->idB, param_0->pB);
    }
}

void func_8080045C_gcmapDll(MapBoundingRecord *param_0, s32 param_1, s32 *param_2, s32 *param_3)
{
    if (param_0[param_1].local_0) {
        func_800B2198(param_0[param_1].local_0, param_2, param_3);
        return;
    }
    switch (func_800EA05C()) {
    case 0x1A7:
        param_2[0] = -18000;
        param_2[1] = -6000;
        param_2[2] = -16000;
        param_3[0] = 3000;
        param_3[1] = 12000;
        param_3[2] = 15000;
        return;
    case 0x1A8:
        param_2[0] = -20000;
        param_2[1] = -8000;
        param_2[2] = -3000;
        param_3[0] = 7000;
        param_3[1] = 2000;
        param_3[2] = 15000;
        return;
    case 0x1A9:
        param_2[0] = 1000;
        param_2[1] = -12000;
        param_2[2] = -13000;
        param_3[0] = 17000;
        param_3[1] = 0;
        param_3[2] = 12000;
        return;
    case 0x159:
        param_2[0] = param_2[1] = param_2[2] = -100;
        param_3[0] = 100;
        param_3[1] = 100;
        param_3[2] = 100;
        return;
    }
}

void func_808005A8_gcmapDll(MapBoundingBoxes *param_0)
{
    func_8080045C_gcmapDll(param_0, 0, param_0->local_1, param_0->local_2);
    func_800EE830(param_0->local_3, param_0->local_1);
    func_800EE830(param_0->local_4, param_0->local_2);
    if (param_0->local_0) {
        s32 local_2;
        s32 local_0[3];
        s32 local_1[3];

        func_8080045C_gcmapDll(param_0, 1, local_0, local_1);
        for (local_2 = 0; local_2 < 3; local_2++) {
            if (local_0[local_2] < param_0->local_3[local_2]) {
                param_0->local_3[local_2] = local_0[local_2];
            }
            if (param_0->local_4[local_2] < local_1[local_2]) {
                param_0->local_4[local_2] = local_1[local_2];
            }
        }
    }
}

int func_80800668_gcmapDll(s32 param_0, s16 *param_1, s32 param_2)
{
  s32 local_0;
  s32 local_1;
  local_1 = 0;
  for (local_0 = 0; local_0 < param_2; local_0++)
  {
    func_800BF744(param_1[local_0 * 2], param_1[local_0 * 2 + 1]);
  }

}

void gcmapDll_entrypoint_2(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_800EA05C();
    switch (local_0) {
    case 0xA1:
    case 0xA2:
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xA6:
    case 0x18B:
        func_80800668_gcmapDll(param_0, &D_80801B98_gcmapDll, 2);
        return;
    case 0xA7:
    case 0xAF:
    case 0x193:
        func_80800668_gcmapDll(param_0, &D_80801BA0_gcmapDll, 2);
        return;
    case 0xB7:
    case 0xD9:
    case 0xEF:
    case 0x13E:
    case 0x13F:
    case 0x156:
    case 0x171:
    case 0x172:
    case 0x176:
        func_80800668_gcmapDll(param_0, &D_80801BB0_gcmapDll, 2);
        return;
    case 0x134:
        func_80800668_gcmapDll(param_0, &D_80801BA8_gcmapDll, 2);
        return;
    case 0x160:
        if (func_800DA298(0x360) != 0) {
            func_80800668_gcmapDll(param_0, &D_80801BC8_gcmapDll, 4);
            return;
        }
        func_80800668_gcmapDll(param_0, &D_80801BB8_gcmapDll, 4);
        return;
    case 0x18C:
        func_80800668_gcmapDll(param_0, &D_80801BB8_gcmapDll, 4);
        return;
    case 0x18D:
        func_80800668_gcmapDll(param_0, &D_80801BD8_gcmapDll, 4);
        return;
    case 0x194:
    case 0x195:
        func_80800668_gcmapDll(param_0, &D_80801BC8_gcmapDll, 4);
        return;
    }
}

void gcmapDll_entrypoint_3(MapDllState *this)
{
    s32 i;

    for (i = 0; i < 60; i++) {
        ((s32 *)this->slot)[i] = 0;
    }
    func_800BF744(1, 0);
    gcmapDll_entrypoint_2(this);
    this->unk85 = this->unk86 = this->unk87 = 0xFF;
    this->unk17C = 0;
    rare_memcpy(this->unk58, func_80800000_gcmapDll(func_800EA05C()), 0xE);
    this->unk55 = 0;
    this->unk29 = 0;
    this->unk40 = 0;
    this->unk14 = 0;
    if (this->unk5A) {
        this->unkC = func_800D674C(this->unk5A);
        func_800D70D0(1);
        func_800D71F4(1);
        this->unk0 = func_800B2720(this->unkC);
        this->unk10 = func_800B2840(this->unkC);
        this->unk20 = func_800B284C(this->unkC);
        if (1) {}
        if (this->unk20 && func_800EA068(0x80)) {
            this->unk17C = _glzone_entrypoint_0(this->unk20);
        }
    } else {
        this->unkC = 0;
        this->unk0 = 0;
        this->unk10 = 0;
        this->unk20 = 0;
    }
    this->unk1B0 = 0;
    if (this->unk5C) {
        this->unk38 = func_800D674C(this->unk5C);
        func_800D70D0(1);
        func_800D71F4(1);
        this->unk2C = func_800B2720(this->unk38);
        this->unk3C = func_800B2840(this->unk38);
        this->unk4C = func_800B284C(this->unk38);
    } else {
        this->unk38 = 0;
        this->unk2C = 0;
        this->unk3C = 0;
        this->unk4C = 0;
    }
    this->unk178 = func_800DBFF8();
    if (this->unkC) {
        this->unk28 = func_800D731C(this->unk5A);
    } else {
        this->unk28 = 0;
    }
    if (this->unk38) {
        this->unk54 = func_800D731C(this->unk5C);
    } else {
        this->unk54 = 0;
    }
    if (this->unk0) {
        this->unk2A = 1;
    } else {
        this->unk2A = 0;
    }
    if (this->unk2C) {
        this->unk56 = 1;
    } else {
        this->unk56 = 0;
    }
    _gcmapsects_entrypoint_15(this);
    func_808005A8_gcmapDll(this);
    this->unk2B = this->unk57 = 1;
}

void func_80800A94_gcmapDll(MapResourceRecord *param_0, s32 param_1)
{
    MapResourceRecord *local_0;
    local_0 = (MapResourceRecord *)((u8 *)param_0 + param_1 * sizeof(MapResourceRecord));
    if (local_0->texture != NULL) {
        _dbtex_entrypoint_1(local_0->texture);
        local_0->texture = NULL;
    }
    if (local_0->geometry != NULL) func_800B23E0(local_0->geometry);
    if (local_0->id != NULL) _glidmake_entrypoint_4(local_0->id);
    if (local_0->light != NULL) {
        _rtlight_entrypoint_0(local_0->light);
        local_0->light = NULL;
    }
    if (local_0->view != NULL) {
        _vpmodule_entrypoint_1(local_0->view, local_0->viewport);
        local_0->view = NULL;
    }
}

int gcmapDll_entrypoint_4(s32 param_0)
{
  s32 local_0;
  s32 local_1 = param_0;
  for (local_0 = 0; local_0 < 2; local_0++)
  {
    func_80800A94_gcmapDll(local_1, local_0);
  }

  if ((*(s32 *)((char *)(local_1) + 0xC)) != 0)
  {
    func_800D70F8(*(u16 *)((char *)(local_1) + 0x5A), 0);
    func_800D721C(*(u16 *)((char *)(local_1) + 0x5A), 0);
    func_800D6CEC(*(u16 *)((char *)(local_1) + 0x5A));
    (*(s32 *)((char *)(local_1) + 0xC)) = 0;
  }
  if ((*(s32 *)((char *)(local_1) + 0x38)) != 0)
  {
    func_800D70F8(*(u16 *)((char *)(local_1) + 0x5C), 0);
    func_800D721C(*(u16 *)((char *)(local_1) + 0x5C), 0);
    func_800D6CEC(*(u16 *)((char *)(local_1) + 0x5C));
    (*(s32 *)((char *)(local_1) + 0x38)) = 0;
  }
  if ((*(s32 *)((char *)(local_1) + 0x17C)) != 0)
  {
    _glzone_entrypoint_1(*(s32 *)((char *)(local_1) + 0x17C));
  }
  func_800DBFD8(*(s32 *)((char *)(local_1) + 0x178));
  if ((*(u8 *)((char *)(local_1) + 0x77)) != 0)
  {
    _gcmapsects_entrypoint_16(local_1);
  }
}

s32 gcmapDll_entrypoint_5(void)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800EA05C();
    for (local_1 = 0; D_80801BE8_gcmapDll[local_1].map != -1; local_1++) {
        if (local_0 == D_80801BE8_gcmapDll[local_1].map) {
            break;
        }
    }
    return D_80801BE8_gcmapDll[local_1].region;
}

void gcmapDll_entrypoint_6(void *param_0, s32 param_1)
{
  void *local_0;
  local_0 = func_80800000_gcmapDll(param_1);
  if (*((u16 *) (((char *) local_0) + 2)) != 0)
  {
    func_800D5B24();
    *((s32 *) (((char *) param_0) + 0x24)) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C(*((u16 *) (((char *) local_0) + 2)))));
  }
  if (*((u16 *) (((char *) local_0) + 4)) != 0)
  {
    func_800D5B24();
    *((s32 *) (((char *) param_0) + 0x50)) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C(*((u16 *) (((char *) local_0) + 4)))));
  }
}
