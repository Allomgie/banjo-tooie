#include "common.h"

extern int D_808013F0_chpoolkids;
extern int D_80801438_chpoolkids;
extern void *D_80801480_chpoolkids;
extern s32 field_30;
extern u32 D_808014E8_chpoolkids[];
extern u32 D_808014F8_chpoolkids[];
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
typedef struct { s16 a; s16 b; } PK2;
extern s32 _glcutDll_entrypoint_20();
extern void func_8010D600(f32 *);
extern f32 func_80102D78();
extern void func_80102BF8(u8 *, f32, f32, f32);
extern s32 D_80801520_chpoolkids;
extern s32 func_80101E14(Actor *, f32);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern int D_8080152C_chpoolkids;
extern int D_8080153C_chpoolkids;
extern int D_8080154C_chpoolkids;
extern int D_8080155C_chpoolkids;
extern int D_8080156C_chpoolkids;
extern int D_8080157C_chpoolkids;
extern void _subaddieaudioquick_entrypoint_4(int, int, int *, int *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 D_80801594_chpoolkids[];
extern void _chpoolkids_entrypoint_3();
extern Actor *func_80106790(Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern u8 D_808012F8_chpoolkids[];
extern u8 D_808014C8_chpoolkids[];
extern u8 D_808012B0_chpoolkids[];
extern u8 D_808012D8_chpoolkids[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 func_8008FB58(f32 *, f32, f32);
extern s32 func_800D9078();
extern u8 D_808014D8_chpoolkids[];
extern u8 D_80801318_chpoolkids[];
extern u8 D_80801340_chpoolkids[];
extern u8 D_80801360_chpoolkids[];
extern void func_80102424();
extern void func_80103014();
extern f32 D_80801508_chpoolkids[];
extern f32 D_80801514_chpoolkids[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_808015A0_chpoolkids[];
extern f32 D_808015EC_chpoolkids[];
extern void *func_800B5BE4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
void func_808006F8_chpoolkids();
void func_808007F0_chpoolkids();
void func_80800D74_chpoolkids();
void func_80800618_chpoolkids();
void func_808008DC_chpoolkids();
void func_808011A8_chpoolkids();

int chpoolkids_entrypoint_0()
{
    return (int)&D_808013F0_chpoolkids;
}

int chpoolkids_entrypoint_1()
{
  return (int)&D_80801438_chpoolkids;
}

int chpoolkids_entrypoint_2()
{
  return &D_80801480_chpoolkids;
}

int func_80800024_chpoolkids(Actor *param_0)
{
  int local_0;
  local_0 = _subaddiesect_entrypoint_1();
  *(s32*)((char*)param_0 + 0x30) = local_0;
  _subaddiesect_entrypoint_2(param_0, local_0, 1);
}





































void func_80800944_chpoolkids(Actor *param_0, f32 param_1);

void func_80800058_chpoolkids(Actor *param_0)
{
    s32 local_2;
    f32 local_0;
    if (func_80104248(param_0)) {
        if (func_801022E4(param_0) == 0x2B9) {
            local_0 = func_80101F24(param_0);
            *(f32 *)&param_0->actorData[5] = func_80013970(func_800F10B4(local_0, 0.75f, 0.99f, 0.0f, 180.0f));
            if (local_0 > 0.33f && local_0 < 0.52f) {
                *((u8 *)param_0 + 0x77) = (*((u8 *)param_0 + 0x77) & ~0xF) | 2;
            } else {
                *((u8 *)param_0 + 0x77) = (*((u8 *)param_0 + 0x77) & ~0xF) | 1;
            }
        } else {
            *((u8 *)param_0 + 0x77) = (*((u8 *)param_0 + 0x77) & ~0xF) | 1;
            *(f32 *)&param_0->actorData[5] = 0.0f;
        }
    }
    func_8008FB58(param_0->position, 60.0f, 60.0f);
    local_2 = param_0->unk70_10;
    switch (local_2) {
    case 1:
        param_0->actorData[4] = local_2;
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808014C8_chpoolkids, D_808012B0_chpoolkids, 5);
        func_80800AA0_chpoolkids(param_0);
        break;
    case 2:
        func_80800AA0_chpoolkids(param_0);
        break;
    case 3:
        func_80800AA0_chpoolkids(param_0);
        if (func_800D9078(&param_0->unk58)) _glcutDll_entrypoint_17();
        break;
    case 4:
        param_0->actorData[4] = local_2;
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808014C8_chpoolkids, D_808012D8_chpoolkids, 4);
        func_80800AA0_chpoolkids(param_0);
        break;
    case 5:
        param_0->actorData[4] = local_2;
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808014C8_chpoolkids, D_808012F8_chpoolkids, 4);
        func_80800AA0_chpoolkids(param_0);
        break;
    case 6:
        func_808008DC_chpoolkids(param_0);
        func_80800944_chpoolkids(param_0, 0.55f);
        break;
    }
}

void func_80800884_chpoolkids();

void func_80800290_chpoolkids(Actor *param_0)
{
    s32 local_0;
    func_8008FB58(param_0->position, 60.0f, 60.0f);
    switch (local_0 = param_0->unk70_10) {
    case 1:
        param_0->actorData[4] = local_0;
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808014D8_chpoolkids, D_80801318_chpoolkids, 5);
        func_80800B38_chpoolkids(param_0); break;
    case 2: func_80800B38_chpoolkids(param_0); break;
    case 4:
        param_0->actorData[4] = local_0;
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808014D8_chpoolkids, D_80801340_chpoolkids, 4);
        func_80800B38_chpoolkids(param_0); break;
    case 5:
        param_0->actorData[4] = local_0;
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808014D8_chpoolkids, D_80801360_chpoolkids, 4);
        func_80800B38_chpoolkids(param_0); break;
    case 6:
        func_80800884_chpoolkids(param_0); func_808008DC_chpoolkids(param_0); func_80800944_chpoolkids(param_0, 0.9f); break;
    }
}

s32 func_808003DC_chpoolkids(Actor *param_0, s32 param_1, PK2 param_2)
{
    s32 local_0;
    s32 local_1;
    f32 local_2[2];
    s32 local_3;
    switch (param_1) {
    case 0x2E:
        func_808007F0_chpoolkids(param_0, param_2.a, param_2.b);
        break;
    case 0xC:
        local_0 = func_800DA298(0x166);
        local_1 = func_800DA298(0x167);
        if (local_0 && local_1) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1022, 6, param_0->position, 0xA0);
            return 3;
        }
        if (local_0) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1021, 6, param_0->position, 0xA0);
            return 3;
        }
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1020, 6, param_0->position, 0xA0);
        return 3;
    case 0x1F:
        local_3 = *(s32 *)&param_2;
        local_2[0] = local_2[1] = *(f32 *)&param_0->actorData[5];
        _dbmorph_entrypoint_3((void *)func_800B2768(local_3), (void *)func_80103CB8(param_0, local_3), func_800B2840(local_3), 1, local_2);
        func_801015D0(param_0);
        break;
    case 0x49:
        if (param_0->unk6C_9 != 0x3A3) return 0;
        if (_glcutDll_entrypoint_19(0x2A)) {
            _capod_entrypoint_13(param_0->unk0, 0, 0x1F, 0x2830);
            break;
        }
        if (_glcutDll_entrypoint_19(0x29)) {
            _capod_entrypoint_13(param_0->unk0, 0, 0x2A, 0x2830);
            break;
        }
        return 0;
    case 0x95:
        func_808006F8_chpoolkids(param_0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(param_0->unk6C_9 == 0x3A3 ? D_808014E8_chpoolkids : D_808014F8_chpoolkids, param_0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800618_chpoolkids(param_0) Actor *param_0;
{

    func_80102424(param_0, 6);
    switch (param_0->unk6C_9) {
    case 0x3A3: func_800EE7F8(param_0->position, D_80801508_chpoolkids); break;
    case 0x3A4:
        func_800EE7F8(param_0->position, D_80801514_chpoolkids);
        func_801020DC(param_0, 0);
        func_80101DAC(param_0, 0);
        break;
    }
    if (!_glcutDll_entrypoint_20()) {
        func_800EF1B8(param_0->position, func_800DC178(0.0f, 359.0f), func_800DC178(0.0f, 200.0f));
    }
    func_80103014(param_0);
}

void func_808006F8_chpoolkids(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_2 = 0;
    local_0 = func_800DA298(0x166);
    local_1 = func_800DA298(0x167);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800618_chpoolkids(param_0);
    } else if ((_glcutDll_entrypoint_19(0x2A) != 0) || (_glcutDll_entrypoint_19(0x29) != 0)) {
        local_2 = 1;
    } else if ((local_0 != 0) && (local_1 == 0)) {
        func_80102424(param_0, 4);
        goto _L808007C8_chpoolkids;
    } else if ((local_0 == 0) && (local_1 != 0)) {
        func_80102424(param_0, 5);
    } else if ((local_0 != 0) && (local_1 != 0)) {
        func_80800618_chpoolkids(param_0);
    }
_L808007C8_chpoolkids:
    if (local_2 != 0) {
        func_800DA524(0x168);
        func_800DA524(0x1CE);
    }
}

void func_808007F0_chpoolkids(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x1020:
    case 0x1021:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_17();
        break;
    case 0x1022:
        func_800D0C78(0x22, 1, 0);
        param_0->unk58 = 4.5f;
        func_80102424(param_0, 3);
        break;
    default:
        func_80102424(param_0, param_0->actorData[4]);
        break;
    }
}

void func_80800884_chpoolkids(u8 *param_0) {
    f32 local_0[3];
    if (!_glcutDll_entrypoint_20(param_0)) {
        func_8010D600(local_0);
        *(f32 *)(param_0 + 0x54) = func_80102D78(param_0, local_0);
        func_80102BF8(param_0, 0.15f, 4.0f, 120.0f);
    }
}

void func_808008DC_chpoolkids(param_0) Actor *param_0;
{
    func_800D9078(&param_0->unk58);
    if (param_0->unk58 <= 0.0f) {
        _fxripple_entrypoint_0(3, param_0->position);
        param_0->unk58 = func_800DC178(0.6f, 1.2f);
    }
}

void func_80800944_chpoolkids(Actor *param_0, f32 param_1)
{
    f32 local_0[3];
    s32 local_1;

    if (func_80101E14(param_0, param_1)) {
        func_800EE7F8(local_0, param_0->position);
        _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_80801520_chpoolkids);
        _fxripple_entrypoint_0(3, local_0);
        _fxsplash25d_entrypoint_0(local_0);
        local_1 = _fxsplash_entrypoint_2(local_0, 35.0f);
        func_800BA930(local_1, -350, 300, -350, 350, 500, 350);
        func_800BA22C(local_1, 6);
        func_800BA930(local_1, -150, 500, -150, 150, 800, 150);
        func_800BA22C(local_1, 6);
        local_0[1] -= 30.0f;
        local_1 = _fxairbub_entrypoint_1(local_0, 20.0f, param_0->position[1], 1.0f);
        func_800BA930(local_1, -60, -250, -60, 60, -150, 60);
        func_800BA22C(local_1, 4);
    }
}

int func_80800AA0_chpoolkids(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_8080152C_chpoolkids, 0x3ECCCCCD);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_8080153C_chpoolkids, 0x3e3851ec);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_8080154C_chpoolkids, 0x3f3ae148);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_8080155C_chpoolkids, 0x3f451eb8);
}

int func_80800B38_chpoolkids(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_4(param_0, local_0, &D_8080156C_chpoolkids, &D_8080157C_chpoolkids);
}

void func_80800B68_chpoolkids(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    if (_gcmapsects_entrypoint_5(*(s16 *)local_0)) {
        local_1 = *(s16 *)(local_0 + 0x10) == 0;
        if (local_1 || (!local_1 && param_0->unk5F)) {
            _subaddieaudioloop_entrypoint_5(param_0, param_0->position,
                local_1, -1, D_80801594_chpoolkids);
        }
        switch (*(s16 *)(local_0 + 2)) {
        case 1:
            local_2 = func_800D9078((f32 *)(local_0 + 4));
            *(f32 *)(local_0 + 0xC) = func_800F12D4(*(f32 *)(local_0 + 4),
                0.0f, 4.0f, 1.0f, 0.0f);
            if (local_2) {
                *(s16 *)(local_0 + 0x10) = 1;
                *(s16 *)(local_0 + 2) = 0;
            }
            break;
        case 2:
            local_3 = func_800D9078((f32 *)(local_0 + 4));
            func_808011A8_chpoolkids(param_0);
            func_800BF744(3, 1);
            *(f32 *)(local_0 + 0x20) = func_800F12D4(*(f32 *)(local_0 + 4),
                0.0f, 2.1f, 1.0f, 0.0f);
            if (local_3) {
                *(s16 *)(local_0 + 0x24) = 1;
                *(s16 *)(local_0 + 2) = 0;
            }
            break;
        }
        if (!*(s16 *)(local_0 + 0x10) || !*(s16 *)(local_0 + 0x24)) {
            local_4 = func_800BEA88(1);
            if (local_4) {
                if (!*(s16 *)(local_0 + 0x24) && func_800E3DC0(local_0 + 0x28, local_0 + 0x2E)) {
                    _glid_entrypoint_0(local_4, 1, _chpoolkids_entrypoint_3, param_0->unk0);
                }
                if (!*(s16 *)(local_0 + 0x10) && func_800E3DC0(local_0 + 0x14, local_0 + 0x1A)) {
                    _glid_entrypoint_0(local_4, 2, _chpoolkids_entrypoint_3, param_0->unk0);
                }
            }
        }
    }
}

int func_80800D3C_chpoolkids(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x95)
  {
    func_80800D74_chpoolkids(param_0);
    return 1;
  }
  return 0;
}

void func_80800D74_chpoolkids(param_0) Actor *param_0;
{
    u8 *local_4;
    s32 local_0;
    s32 local_1;
    void *local_2;
    s32 local_3;

    local_4 = func_80100094(param_0, 0);
    local_0 = func_800DA298(0x166);
    local_1 = func_800DA298(0x167);
    *(s16 *)local_4 = _gcmapsects_entrypoint_4(param_0->position);
    *(s16 *)(local_4 + 2) = 0;
    *(f32 *)(local_4 + 4) = 0.0f;
    *(f32 *)(local_4 + 8) = 0.0f;
    *(f32 *)(local_4 + 0x20) = 0.0f;
    *(f32 *)(local_4 + 0xC) = 0.0f;
    if (_glcutDll_entrypoint_20()) {
        local_0 = 1;
        local_1 = 1;
    }
    if (local_0) {
        *(f32 *)(local_4 + 0xC) = 1.0f;
    }
    if (local_1) {
        *(f32 *)(local_4 + 0x20) = 1.0f;
    }
    if (_glcutDll_entrypoint_19(0x2A)) {
        *(s16 *)(local_4 + 2) = 1;
        *(f32 *)(local_4 + 0xC) = 0.0f;
        *(f32 *)(local_4 + 4) = 4.0f;
        *(f32 *)(local_4 + 8) = 4.0f;
        _subaddieDll_entrypoint_4(param_0, 1);
    } else if (_glcutDll_entrypoint_19(0x29)) {
        *(s16 *)(local_4 + 2) = 2;
        *(f32 *)(local_4 + 0x20) = 0.0f;
        *(f32 *)(local_4 + 4) = 6.0f;
        *(f32 *)(local_4 + 8) = 6.0f;
        _subaddieDll_entrypoint_4(param_0, 1);
    }
    if (*(f32 *)(local_4 + 0xC) == 1.0f) {
        *(s16 *)(local_4 + 0x10) = 1;
    } else {
        *(s16 *)(local_4 + 0x10) = 0;
    }
    if (*(f32 *)(local_4 + 0x20) == 1.0f) {
        *(s16 *)(local_4 + 0x24) = 1;
    } else {
        *(s16 *)(local_4 + 0x24) = 0;
    }
    func_800BF744(3, 0);
    func_800BF744(2, *(s16 *)(local_4 + 0x10) ? 0 : 1);
    local_2 = func_800BEA88(1);
    _glidmake_entrypoint_2(local_2, 1, local_4 + 0x28, local_4 + 0x2E);
    _glidmake_entrypoint_2(local_2, 2, local_4 + 0x14, local_4 + 0x1A);
    _idworldmake_entrypoint_1(local_2, 0x8D, 1, 1);
    _idworldmake_entrypoint_1(local_2, 0x8D, 2, 1);
}

void chpoolkids_entrypoint_3(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    u8 *local_0;
    Vtx *local_1;
    f32 local_2;

    local_0 = func_80100094(func_80106790(param_4), 0);
    switch (param_0) {
    case 1:
        local_2 = 1.0f - *(f32 *)(local_0 + 0x20);
        local_1 = param_1 + param_3;
        for (; param_1 < local_1; param_1++, param_2++) {
            param_2->v.cn[3] = (u32)((u32)param_1->v.cn[3] * local_2);
        }
        break;
    case 2:
        local_2 = 1.0f - *(f32 *)(local_0 + 0xC);
        local_1 = param_1 + param_3;
        for (; param_1 < local_1; param_1++, param_2++) {
            param_2->v.cn[3] = (u32)((u32)param_1->v.cn[3] * local_2);
        }
        break;
    }
}

void func_808011A8_chpoolkids(param_0) Actor *param_0;
{
    void *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_800B5BE4(0x23);
    local_2 = 1;
    for (local_1 = 0; local_1 < local_2; local_1++) {
        func_800BABB8(local_0, D_808015EC_chpoolkids, D_808015EC_chpoolkids,
            param_0->scale * 1.15f, D_808015A0_chpoolkids);
    }
}
